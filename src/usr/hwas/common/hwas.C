/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/hwas.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
/* [+] Google Inc.                                                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file hwas.C
 *
 *  HardWare Availability Service functions.
 *  See hwas.H for doxygen documentation tags.
 *
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <algorithm>
#ifdef __HOSTBOOT_MODULE
#include <config.h>
#endif

#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasError.H>

#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <targeting/common/utilFilter.H>

namespace HWAS
{

using namespace TARGETING;
using namespace HWAS::COMMON;

// trace setup; used by HWAS_DBG and HWAS_ERR macros
HWAS_TD_t g_trac_dbg_hwas   = NULL; // debug - fast
HWAS_TD_t g_trac_imp_hwas   = NULL; // important - slow

#ifdef __HOSTBOOT_MODULE
TRAC_INIT(&g_trac_dbg_hwas, "HWAS",     KILOBYTE );
TRAC_INIT(&g_trac_imp_hwas, "HWAS_I",   KILOBYTE );
#else
TRAC_INIT(&g_trac_dbg_hwas, "HWAS",     1024 );
TRAC_INIT(&g_trac_imp_hwas, "HWAS_I",   1024 );
#endif

// SORT functions that we'll use for PR keyword processing
bool compareProcGroup(procRestrict_t t1, procRestrict_t t2)
{
    if (t1.group == t2.group)
    {
        return (t1.target->getAttr<ATTR_HUID>() <
                    t2.target->getAttr<ATTR_HUID>());
    }
    return (t1.group < t2.group);
}

bool compareAffinity(const TargetInfo t1, const TargetInfo t2)
{
        return t1.affinityPath < t2.affinityPath;
}

/**
 * @brief       simple helper fn to get and set hwas state to poweredOn,
 *                  present, functional
 *
 * @param[in]   i_target        pointer to target that we're looking at
 * @param[in]   i_present       boolean indicating present or not
 * @param[in]   i_functional    boolean indicating functional or not
 * @param[in]   i_errlEid       erreid that caused change to non-funcational;
 *                              0 if not associated with an error or if
 *                              functional is true
 *
 * @return      none
 *
 */
void enableHwasState(Target *i_target,
        bool i_present, bool i_functional,
        uint32_t i_errlEid)
{
    HwasState hwasState = i_target->getAttr<ATTR_HWAS_STATE>();

    if (i_functional == false)
    {   // record the EID as a reason that we're marking non-functional
        hwasState.deconfiguredByEid = i_errlEid;
    }
    hwasState.poweredOn     = true;
    hwasState.present       = i_present;
    hwasState.functional    = i_functional;
    i_target->setAttr<ATTR_HWAS_STATE>( hwasState );
}


/**
 * @brief       simple helper fn to check IOX/PBIOX pairs in PG XBUS data
 *
 * @param[in]   i_pgData        XBUS data from PG keyword VPD
 *
 * @return bool                 pairs are valid
 *
 */
bool areIoxPairsValid(uint16_t i_pgData)
{
    bool l_valid = true;

    // Check that pairs are valid, that is, both good or both bad
    for (uint8_t l_pair = 0;
         l_pair <= 2;
         l_pair++)
    {
        // Check if both are good in the pair
        if ((i_pgData & VPD_CP00_PG_XBUS_IOX_PAIR[l_pair]) == 0)
        {
            continue;
        }

        // Check if both are bad in the pair
        if ((i_pgData & VPD_CP00_PG_XBUS_IOX_PAIR[l_pair]) ==
            VPD_CP00_PG_XBUS_IOX_PAIR[l_pair])
        {
            continue;
        }

        l_valid = false;
        break;
    }

    return l_valid;
}


/**
 * @brief simple helper fn to check L3/L2/REFR triplets in PG EPx data
 *
 * @param[in] i_pgData EPx data from PG keyword VPD
 *
 * @return bool triplets are valid
 *
 */
bool areL3L2REFRtripletsValid(uint16_t i_pgData)
{
    bool l_valid = true;

    // Check that triplets are valid, that is, all good or all bad
    for (uint8_t l_triplet = 0;
         l_triplet <= 1;
         l_triplet++)
    {
        // Check if all are good in the triplet
        if ((i_pgData & VPD_CP00_PG_EPx_L3L2REFR[l_triplet]) == 0)
        {
            continue;
        }

        // Check if all are bad in the triplet
        if ((i_pgData & VPD_CP00_PG_EPx_L3L2REFR[l_triplet]) ==
            VPD_CP00_PG_EPx_L3L2REFR[l_triplet])
        {
            continue;
        }

        l_valid = false;
        break;
    }

    return l_valid;
}


errlHndl_t discoverTargets()
{
    HWAS_DBG("discoverTargets entry");
    errlHndl_t errl = NULL;

    //  loop through all the targets and set HWAS_STATE to a known default
    for (TargetIterator target = targetService().begin();
            target != targetService().end();
            ++target)
    {
        HwasState hwasState             = target->getAttr<ATTR_HWAS_STATE>();
        hwasState.deconfiguredByEid     = 0;
        hwasState.poweredOn             = false;
        hwasState.present               = false;
        hwasState.functional            = false;
        hwasState.dumpfunctional        = false;
        target->setAttr<ATTR_HWAS_STATE>(hwasState);
    }

    // Assumptions and actions:
    // CLASS_SYS (exactly 1) - mark as present
    // CLASS_ENC, TYPE_PROC, TYPE_MCS, TYPE_MEMBUF, TYPE_DIMM
    //     (ALL require hardware query) - call platPresenceDetect
    //  \->children: CLASS_* (NONE require hardware query) - mark as present
    do
    {
        // find CLASS_SYS (the top level target)
        Target* pSys;
        targetService().getTopLevelTarget(pSys);

        HWAS_ASSERT(pSys,
                "HWAS discoverTargets: no CLASS_SYS TopLevelTarget found");

        // mark this as present
        enableHwasState(pSys, true, true, 0);
        HWAS_DBG("pSys %.8X - marked present",
            pSys->getAttr<ATTR_HUID>());

        // find list of all we need to call platPresenceDetect against
        PredicateCTM predEnc(CLASS_ENC);
        PredicateCTM predChip(CLASS_CHIP);
        PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
        PredicateCTM predMcs(CLASS_UNIT, TYPE_MCS);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predChip).push(&predDimm).Or().push(&predEnc).Or().
                  push(&predMcs).Or();

        TargetHandleList pCheckPres;
        targetService().getAssociated( pCheckPres, pSys,
            TargetService::CHILD, TargetService::ALL, &checkExpr );

        // pass this list to the hwas platform-specific api where
        // pCheckPres will be modified to only have present targets
        HWAS_DBG("pCheckPres size: %d", pCheckPres.size());
        errl = platPresenceDetect(pCheckPres);
        HWAS_DBG("pCheckPres size: %d", pCheckPres.size());

        if (errl != NULL)
        {
            break; // break out of the do/while so that we can return
        }

        // for each, read their ID/EC level. if that works,
        //  mark them and their descendants as present
        //  read the partialGood vector to determine if any are not functional
        //  and read and store values from the PR keyword

        // list of procs and data that we'll need to look at the PR keyword
        procRestrict_t l_procEntry;
        std::vector <procRestrict_t> l_procPRList;

        // sort the list by ATTR_HUID to ensure that we
        //  start at the same place each time
        std::sort(pCheckPres.begin(), pCheckPres.end(),
                compareTargetHuid);

        for (TargetHandleList::const_iterator pTarget_it = pCheckPres.begin();
                pTarget_it != pCheckPres.end();
                ++pTarget_it
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            // if CLASS_ENC is still in this list, mark as present
            if (pTarget->getAttr<ATTR_CLASS>() == CLASS_ENC)
            {
                enableHwasState(pTarget, true, true, 0);
                HWAS_DBG("pTarget %.8X - CLASS_ENC marked present",
                    pTarget->getAttr<ATTR_HUID>());

                // on to the next target
                continue;
            }

            bool chipPresent = true;
            bool chipFunctional = true;
            uint32_t errlEid = 0;
            uint16_t pgData[VPD_CP00_PG_DATA_LENGTH / sizeof(uint16_t)];
            bzero(pgData, sizeof(pgData));

            if (pTarget->getAttr<ATTR_CLASS>() == CLASS_CHIP)
            {
                // read Chip ID/EC data from these physical chips
                errl = platReadIDEC(pTarget);

                if (errl)
                {   // read of ID/EC failed even tho we THOUGHT we were present.
                    HWAS_INF("pTarget %.8X - read IDEC failed (eid 0x%X) - bad",
                        errl->eid(), pTarget->getAttr<ATTR_HUID>());
                    // chip NOT present and NOT functional, so that FSP doesn't
                    // include this for HB to process
                    chipPresent = false;
                    chipFunctional = false;
                    errlEid = errl->eid();

                    // commit the error but keep going
                    errlCommit(errl, HWAS_COMP_ID);
                    // errl is now NULL
                }
                else if (pTarget->getAttr<ATTR_TYPE>() == TYPE_PROC)
                {
                    // read partialGood vector from these as well.
                    errl = platReadPartialGood(pTarget, pgData);

                    if (errl)
                    {   // read of PG failed even tho we were present..
                        HWAS_INF("pTarget %.8X - read PG failed (eid 0x%X)- bad",
                            errl->eid(), pTarget->getAttr<ATTR_HUID>());
                        chipFunctional = false;
                        errlEid = errl->eid();

                        // commit the error but keep going
                        errlCommit(errl, HWAS_COMP_ID);
                        // errl is now NULL
                    }
                    else
                    {
                      // look at the 'nest' logic to override the functionality
                      //  of this proc
                      chipFunctional = isChipFunctional(pTarget, pgData);

                      if (chipFunctional)
                      {
                        // read the PR keywords that we need, so that if
                        //  we have errors, we can handle them as approprite.
                        uint8_t prData[VPD_VINI_PR_DATA_LENGTH/sizeof(uint8_t)];
                        bzero(prData, sizeof(prData));
                        errl = platReadPR(pTarget, prData);
                        if (errl != NULL)
                        {   // read of PR keyword failed
                            HWAS_INF("pTarget %.8X - read PR failed - bad",
                                pTarget->getAttr<ATTR_HUID>());
                            chipFunctional = false;
                            errlEid = errl->eid();

                            // commit the error but keep going
                            errlCommit(errl, HWAS_COMP_ID);
                            // errl is now NULL
                        }
                        else
                        {
                            // save info so that we can
                            //  process the PR keyword after this loop
                            HWAS_INF("pTarget %.8X - pushing to procPRlist; FRU_ID %d",
                                pTarget->getAttr<ATTR_HUID>(),
                                pTarget->getAttr<ATTR_FRU_ID>());
                            l_procEntry.target = pTarget;
                            l_procEntry.group = pTarget->getAttr<ATTR_FRU_ID>();
                            l_procEntry.procs =
                                        (prData[7] & VPD_VINI_PR_B7_MASK) + 1;
                            l_procEntry.maxECs = l_procEntry.procs *
                                        (prData[2] & VPD_VINI_PR_B2_MASK)
                                            >> VPD_VINI_PR_B2_SHIFT;
                            l_procPRList.push_back(l_procEntry);

                            if (l_procEntry.maxECs == 0)
                            {
                                // this is PROBABLY bad PR, so YELL...
                                HWAS_ERR("pTarget %.8X - PR VPD says 0 CORES",
                                    pTarget->getAttr<ATTR_HUID>());
                            }
                        }
                      }
                    }
                } // TYPE_PROC
            } // CLASS_CHIP

            HWAS_DBG("pTarget %.8X - detected present, %sfunctional",
                pTarget->getAttr<ATTR_HUID>(),
                chipFunctional ? "" : "NOT ");

            // now need to mark all of this target's
            //  physical descendants as present and functional as appropriate
            TargetHandleList pDescList;
            targetService().getAssociated( pDescList, pTarget,
                TargetService::CHILD, TargetService::ALL);
            for (TargetHandleList::const_iterator pDesc_it = pDescList.begin();
                    pDesc_it != pDescList.end();
                    ++pDesc_it)
            {
                TargetHandle_t pDesc = *pDesc_it;
                // by default, the descendant's functionality is 'inherited'
                bool descFunctional = chipFunctional;

                if (chipFunctional)
                {   // if the chip is functional, then look through the
                    //  partialGood vector to see if its chiplets
                    //  are functional
                    descFunctional = isDescFunctional(pDesc, pgData);
                }

                // for sub-parts, if it's not functional, it's not present.
                enableHwasState(pDesc, descFunctional, descFunctional,
                                errlEid);
                HWAS_DBG("pDesc %.8X - marked %spresent, %sfunctional",
                    pDesc->getAttr<ATTR_HUID>(),
                    descFunctional ? "" : "NOT ",
                    descFunctional ? "" : "NOT ");
            }

            // set HWAS state to show CHIP is present, functional per above
            enableHwasState(pTarget, chipPresent, chipFunctional, errlEid);

        } // for pTarget_it

        // Check for non-present Procs and if found, trigger
        // DeconfigGard::_invokeDeconfigureAssocProc() to run by setting
        // setXABusEndpointDeconfigured to true
        PredicateCTM predProc(CLASS_CHIP, TYPE_PROC);
        TargetHandleList l_procs;
        targetService().getAssociated(l_procs,
                                      pSys,
                                      TargetService::CHILD,
                                      TargetService::ALL,
                                      &predProc);

        for (TargetHandleList::const_iterator
             l_procsIter = l_procs.begin();
             l_procsIter != l_procs.end();
             ++l_procsIter)
        {
            if ( !(*l_procsIter)->getAttr<ATTR_HWAS_STATE>().present )
            {
                HWAS_INF("discoverTargets: Proc %.8X not present",
                    (*l_procsIter)->getAttr<ATTR_HUID>());
                HWAS::theDeconfigGard().setXABusEndpointDeconfigured(true);
            }
        }

        // PR keyword processing - potentially reduce the number of ec/core
        //  units that are functional based on what's in the PR keyword.
        //  call to restrict EC units, marking bad units as present=false;
        //  deconfigReason = 0 because present is false so this is not a
        //  deconfigured event.
#ifndef CONFIG_SKIP_RESTRICT_EC_UNITS
        errl = restrictECunits(l_procPRList, false, 0);

        if (errl)
        {
            HWAS_ERR("discoverTargets: restrictECunits failed");
            break;
        }
#endif

        // call invokePresentByAssoc() to obtain functional MCSs, MEMBUFs, and
        // DIMMs for non-direct memory or MCSs, MCAs, and DIMMs for direct
        // memory. Call algorithm function presentByAssoc() to determine
        // targets that need to be deconfigured
        invokePresentByAssoc();

    } while (0);

    if (errl)
    {
        HWAS_INF("discoverTargets failed (plid 0x%X)", errl->plid());
    }
    else
    {
        HWAS_INF("discoverTargets completed successfully");
    }
    return errl;
} // discoverTargets


bool isChipFunctional(const TARGETING::TargetHandle_t &i_target,
                      const uint16_t i_pgData[])
{
    bool l_chipFunctional = true;

    // Check all bits in FSI entry
    if (i_pgData[VPD_CP00_PG_FSI_INDEX] !=
        VPD_CP00_PG_FSI_GOOD)
    {
        HWAS_INF("pTarget %.8X - FSI pgData[%d]: "
                 "actual 0x%04X, expected 0x%04X - bad",
                 i_target->getAttr<ATTR_HUID>(),
                 VPD_CP00_PG_FSI_INDEX,
                 i_pgData[VPD_CP00_PG_FSI_INDEX],
                 VPD_CP00_PG_FSI_GOOD);
        l_chipFunctional = false;
    }
    else
    // Check all bits in PRV entry
    if (i_pgData[VPD_CP00_PG_PERVASIVE_INDEX] !=
        VPD_CP00_PG_PERVASIVE_GOOD)
    {
        HWAS_INF("pTarget %.8X - Pervasive pgData[%d]: "
                 "actual 0x%04X, expected 0x%04X - bad",
                 i_target->getAttr<ATTR_HUID>(),
                 VPD_CP00_PG_PERVASIVE_INDEX,
                 i_pgData[VPD_CP00_PG_PERVASIVE_INDEX],
                 VPD_CP00_PG_PERVASIVE_GOOD);
        l_chipFunctional = false;
    }
    else
    // Check all bits in N0 entry
    if (i_pgData[VPD_CP00_PG_N0_INDEX] != VPD_CP00_PG_N0_GOOD)
    {
        HWAS_INF("pTarget %.8X - N0 pgData[%d]: "
                 "actual 0x%04X, expected 0x%04X - bad",
                 i_target->getAttr<ATTR_HUID>(),
                 VPD_CP00_PG_N0_INDEX,
                 i_pgData[VPD_CP00_PG_N0_INDEX],
                 VPD_CP00_PG_N0_GOOD);
        l_chipFunctional = false;
    }
    else
    // Check bits in N1 entry except those in partial good region
    if ((i_pgData[VPD_CP00_PG_N1_INDEX] &
         ~VPD_CP00_PG_N1_PG_MASK) != VPD_CP00_PG_N1_GOOD)
    {
        HWAS_INF("pTarget %.8X - N1 pgData[%d]: "
                 "actual 0x%04X, expected 0x%04X - bad",
                 i_target->getAttr<ATTR_HUID>(),
                 VPD_CP00_PG_N1_INDEX,
                 i_pgData[VPD_CP00_PG_N1_INDEX],
                 VPD_CP00_PG_N1_GOOD);
        l_chipFunctional = false;
    }
    else
    // Check all bits in N2 entry
    if (i_pgData[VPD_CP00_PG_N2_INDEX] != VPD_CP00_PG_N2_GOOD)
    {
        HWAS_INF("pTarget %.8X - N2 pgData[%d]: "
                 "actual 0x%04X, expected 0x%04X - bad",
                 i_target->getAttr<ATTR_HUID>(),
                 VPD_CP00_PG_N2_INDEX,
                 i_pgData[VPD_CP00_PG_N2_INDEX],
                 VPD_CP00_PG_N2_GOOD);
        l_chipFunctional = false;
    }
    else
    // Check bits in N3 entry except those in partial good region
    if ((i_pgData[VPD_CP00_PG_N3_INDEX] &
         ~VPD_CP00_PG_N3_PG_MASK) != VPD_CP00_PG_N3_GOOD)
    {
        HWAS_INF("pTarget %.8X - N3 pgData[%d]: "
                 "actual 0x%04X, expected 0x%04X - bad",
                 i_target->getAttr<ATTR_HUID>(),
                 VPD_CP00_PG_N3_INDEX,
                 i_pgData[VPD_CP00_PG_N3_INDEX],
                 VPD_CP00_PG_N3_GOOD);
        l_chipFunctional = false;
    }
    else
    // Check bits in XBUS entry, validating pairs in partial good region
    if (((i_pgData[VPD_CP00_PG_XBUS_INDEX] &
          ~VPD_CP00_PG_XBUS_PG_MASK) != VPD_CP00_PG_XBUS_GOOD)
        ||
        (!areIoxPairsValid(i_pgData[VPD_CP00_PG_XBUS_INDEX])))
    {
        HWAS_INF("pTarget %.8X - XBUS pgData[%d]: "
                 "actual 0x%04X, expected 0x%04X - bad",
                 i_target->getAttr<ATTR_HUID>(),
                 VPD_CP00_PG_XBUS_INDEX,
                 i_pgData[VPD_CP00_PG_XBUS_INDEX],
                 VPD_CP00_PG_XBUS_GOOD);
        l_chipFunctional = false;
    }

    return l_chipFunctional;
} // isChipFunctional


bool isDescFunctional(const TARGETING::TargetHandle_t &i_desc,
                      const uint16_t i_pgData[])
{
    bool l_descFunctional = true;

    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_XBUS)
    {
        ATTR_CHIP_UNIT_type indexXB =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // Check pair of bits in XBUS entry
        if ((i_pgData[VPD_CP00_PG_XBUS_INDEX] &
             VPD_CP00_PG_XBUS_IOX_PAIR[indexXB]) != 0)
        {
            HWAS_INF("pDesc %.8X - XBUS%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexXB,
                     VPD_CP00_PG_XBUS_INDEX,
                     i_pgData[VPD_CP00_PG_XBUS_INDEX],
                     (i_pgData[VPD_CP00_PG_XBUS_INDEX] &
                      ~VPD_CP00_PG_XBUS_IOX_PAIR[indexXB]));
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_OBUS)
    {
        ATTR_CHIP_UNIT_type indexOB =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // Check all bits in OBUSx entry
        if (i_pgData[VPD_CP00_PG_OB0_INDEX + indexOB] !=
            VPD_CP00_PG_OBUS_GOOD)
        {
            HWAS_INF("pDesc %.8X - OB%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexOB,
                     VPD_CP00_PG_OB0_INDEX + indexOB,
                     i_pgData[VPD_CP00_PG_OB0_INDEX + indexOB],
                     VPD_CP00_PG_OBUS_GOOD);
            l_descFunctional = false;
        }
        else
        // Check PBIOO0 bit in N1 entry
        // @TODO RTC:134608 PBIOO0 seems to be good with Nimbus and Cumulus
        //                  except Nimbus Sforza (without optics and NVLINK)
        //                  so is it associated with all OBUS entries or just
        //                  with OBUS0 and OBUS3 -- verify this
        if ((i_pgData[VPD_CP00_PG_N1_INDEX] &
              VPD_CP00_PG_N1_PBIOO0) != 0)
        {
            HWAS_INF("pDesc %.8X - OB%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexOB,
                     VPD_CP00_PG_N1_INDEX,
                     i_pgData[VPD_CP00_PG_N1_INDEX],
                     (i_pgData[VPD_CP00_PG_N1_INDEX] &
                      ~VPD_CP00_PG_N1_PBIOO0));
            l_descFunctional = false;
        }
        else
        // Check PBIOO1 bit in N1 entry if second or third OBUS
        // @TODO RTC:134608 PBIOO1 seems to be associated with OBUS1 and OBUS2
        //                  which only are valid on a Cumulus -- verify this
        if (((1 == indexOB) || (2 == indexOB)) &&
            ((i_pgData[VPD_CP00_PG_N1_INDEX] &
              VPD_CP00_PG_N1_PBIOO1) != 0))
        {
            HWAS_INF("pDesc %.8X - OB%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexOB,
                     VPD_CP00_PG_N1_INDEX,
                     i_pgData[VPD_CP00_PG_N1_INDEX],
                     (i_pgData[VPD_CP00_PG_N1_INDEX] &
                      ~VPD_CP00_PG_N1_PBIOO1));
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_PEC)
    {
        ATTR_CHIP_UNIT_type indexPCI =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // Check all bits in PCIx entry
        if (i_pgData[VPD_CP00_PG_PCI0_INDEX + indexPCI] !=
            VPD_CP00_PG_PCIx_GOOD[indexPCI])
        {
            HWAS_INF("pDesc %.8X - PCI%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexPCI,
                     VPD_CP00_PG_PCI0_INDEX + indexPCI,
                     i_pgData[VPD_CP00_PG_PCI0_INDEX + indexPCI],
                     VPD_CP00_PG_PCIx_GOOD[indexPCI]);
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_EQ)
    {
        ATTR_CHIP_UNIT_type indexEP =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // Check bits in EPx entry, validating triplets in partial good region
        if (((i_pgData[VPD_CP00_PG_EP0_INDEX + indexEP]
              & ~VPD_CP00_PG_EPx_PG_MASK) !=
              VPD_CP00_PG_EPx_GOOD) ||
            (!areL3L2REFRtripletsValid(i_pgData[VPD_CP00_PG_EP0_INDEX +
                                       indexEP])))
        {
            HWAS_INF("pDesc %.8X - EQ%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexEP,
                     VPD_CP00_PG_EP0_INDEX + indexEP,
                     i_pgData[VPD_CP00_PG_EP0_INDEX + indexEP],
                     VPD_CP00_PG_EPx_GOOD);
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_EX)
    {
        ATTR_CHIP_UNIT_type indexEX =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // 2 EX chiplets per EP/EQ chiplet
        size_t indexEP = indexEX / 2;
        // 2 L3/L2/REFR triplets per EX chiplet
        size_t indexL3L2REFR = indexEX % 2;
        // Check triplet of bits in EPx entry
        if ((i_pgData[VPD_CP00_PG_EP0_INDEX + indexEP] &
             VPD_CP00_PG_EPx_L3L2REFR[indexL3L2REFR]) != 0)
        {
            HWAS_INF("pDesc %.8X - EX%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexEX,
                     VPD_CP00_PG_EP0_INDEX + indexEP,
                     i_pgData[VPD_CP00_PG_EP0_INDEX + indexEP],
                     (i_pgData[VPD_CP00_PG_EP0_INDEX + indexEP] &
                      ~VPD_CP00_PG_EPx_L3L2REFR[indexL3L2REFR]));
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_CORE)
    {
        ATTR_CHIP_UNIT_type indexEC =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // Check all bits in ECxx entry
        if (i_pgData[VPD_CP00_PG_EC00_INDEX + indexEC] !=
            VPD_CP00_PG_ECxx_GOOD)
        {
            HWAS_INF("pDesc %.8X - CORE/EC%2.2d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexEC,
                     VPD_CP00_PG_EC00_INDEX + indexEC,
                     i_pgData[VPD_CP00_PG_EC00_INDEX + indexEC],
                     VPD_CP00_PG_ECxx_GOOD);
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_MCBIST)
    {
        ATTR_CHIP_UNIT_type indexMCBIST =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // 2 MCS chiplets per MCBIST / MCU
        size_t indexMCS = indexMCBIST * 2;
        // Check MCS01 bit in N3 entry if first MCBIST / MCU
        if ((0 == indexMCBIST) &&
            ((i_pgData[VPD_CP00_PG_N3_INDEX] &
              VPD_CP00_PG_N3_MCS01) != 0))
        {
            HWAS_INF("pDesc %.8X - MCBIST%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexMCBIST,
                     VPD_CP00_PG_N3_INDEX,
                     i_pgData[VPD_CP00_PG_N3_INDEX],
                     (i_pgData[VPD_CP00_PG_N3_INDEX] &
                      ~VPD_CP00_PG_N3_MCS01));
            l_descFunctional = false;
        }
        else
        // Check MCS23 bit in N1 entry if second MCBIST / MCU
        if ((1 == indexMCBIST) &&
            ((i_pgData[VPD_CP00_PG_N1_INDEX] &
              VPD_CP00_PG_N1_MCS23) != 0))
        {
            HWAS_INF("pDesc %.8X - MCBIST%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexMCBIST,
                     VPD_CP00_PG_N1_INDEX,
                     i_pgData[VPD_CP00_PG_N1_INDEX],
                     (i_pgData[VPD_CP00_PG_N1_INDEX] &
                      ~VPD_CP00_PG_N1_MCS23));
            l_descFunctional = false;
        }
        else
        // Check bits in MCxx entry except those in partial good region
        if ((i_pgData[VPD_CP00_PG_MCxx_INDEX[indexMCS]]
             & ~VPD_CP00_PG_MCxx_PG_MASK) !=
             VPD_CP00_PG_MCxx_GOOD)
        {
            HWAS_INF("pDesc %.8X - MCBIST%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexMCBIST,
                     VPD_CP00_PG_MCxx_INDEX[indexMCS],
                     i_pgData[VPD_CP00_PG_MCxx_INDEX[indexMCS]],
                     VPD_CP00_PG_MCxx_GOOD);
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_MCS)
    {
        ATTR_CHIP_UNIT_type indexMCS =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // Check MCS01 bit in N3 entry if first or second MCS
        if (((0 == indexMCS) || (1 == indexMCS)) &&
            ((i_pgData[VPD_CP00_PG_N3_INDEX] &
              VPD_CP00_PG_N3_MCS01) != 0))
        {
            HWAS_INF("pDesc %.8X - MCS%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexMCS,
                     VPD_CP00_PG_N3_INDEX,
                     i_pgData[VPD_CP00_PG_N3_INDEX],
                     (i_pgData[VPD_CP00_PG_N3_INDEX] &
                      ~VPD_CP00_PG_N3_MCS01));
            l_descFunctional = false;
        }
        else
        // Check MCS23 bit in N1 entry if third or fourth MCS
        if (((2 == indexMCS) || (3 == indexMCS)) &&
            ((i_pgData[VPD_CP00_PG_N1_INDEX] &
              VPD_CP00_PG_N1_MCS23) != 0))
        {
            HWAS_INF("pDesc %.8X - MCS%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexMCS,
                     VPD_CP00_PG_N1_INDEX,
                     i_pgData[VPD_CP00_PG_N1_INDEX],
                     (i_pgData[VPD_CP00_PG_N1_INDEX] &
                      ~VPD_CP00_PG_N1_MCS23));
            l_descFunctional = false;
        }
        else
        // Check bits in MCxx entry including specific IOM bit,
        // but not other bits in partial good region
        if ((i_pgData[VPD_CP00_PG_MCxx_INDEX[indexMCS]]
             & ~(VPD_CP00_PG_MCxx_PG_MASK
                 & ~VPD_CP00_PG_MCxx_IOMyy[indexMCS])) !=
             VPD_CP00_PG_MCxx_GOOD)
        {
            HWAS_INF("pDesc %.8X - MCS%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexMCS,
                     VPD_CP00_PG_MCxx_INDEX[indexMCS],
                     i_pgData[VPD_CP00_PG_MCxx_INDEX[indexMCS]],
                     (i_pgData[VPD_CP00_PG_MCxx_INDEX[indexMCS]] &
                      ~VPD_CP00_PG_MCxx_IOMyy[indexMCS]));
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_MCA)
    {
        ATTR_CHIP_UNIT_type indexMCA =
            i_desc->getAttr<ATTR_CHIP_UNIT>();
        // 2 MCA chiplets per MCS
        size_t indexMCS = indexMCA / 2;
        // Check IOM bit in MCxx entry
        if ((i_pgData[VPD_CP00_PG_MCxx_INDEX[indexMCS]]
             & VPD_CP00_PG_MCxx_IOMyy[indexMCS]) != 0)
        {
            HWAS_INF("pDesc %.8X - MCA%d pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(), indexMCA,
                     VPD_CP00_PG_MCxx_INDEX[indexMCS],
                     i_pgData[VPD_CP00_PG_MCxx_INDEX[indexMCS]],
                     (i_pgData[VPD_CP00_PG_MCxx_INDEX[indexMCS]] &
                      ~VPD_CP00_PG_MCxx_IOMyy[indexMCS]));
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_NV)
    {
        // Check NPU bit in N3 entry
        if ((i_pgData[VPD_CP00_PG_N3_INDEX] &
             VPD_CP00_PG_N3_NPU) != 0)
        {
            HWAS_INF("pDesc %.8X - NV pgData[%d]: "
                     "actual 0x%04X, expected 0x%04X - bad",
                     i_desc->getAttr<ATTR_HUID>(),
                     VPD_CP00_PG_N3_INDEX,
                     i_pgData[VPD_CP00_PG_N3_INDEX],
                     (i_pgData[VPD_CP00_PG_N3_INDEX] &
                      ~VPD_CP00_PG_N3_NPU));
            l_descFunctional = false;
        }
    }
    else
    if (i_desc->getAttr<ATTR_TYPE>() == TYPE_PERV)
    {
        // Loop through PG entries from PRV entry to last used entry
        for (uint8_t l_pgDataIndex =
               VPD_CP00_PG_PERVASIVE_INDEX;
             l_pgDataIndex <= VPD_CP00_PG_MAX_USED_INDEX;
             ++l_pgDataIndex)
        {
            // Skip reserved entries between EP5 entry and EC00 entry
            if ((l_pgDataIndex > VPD_CP00_PG_EP5_INDEX) &&
                (l_pgDataIndex < VPD_CP00_PG_EC00_INDEX))
            {
                continue;
            }

            // Skip OB1 and OB2 entries on NIMBUS (region doesn't exist)
            if ((i_desc->getAttr<ATTR_MODEL>() ==
                 MODEL_NIMBUS) &&
                (l_pgDataIndex > VPD_CP00_PG_OB0_INDEX) &&
                (l_pgDataIndex < VPD_CP00_PG_OB3_INDEX))
            {
                continue;
            }

            // Check PERV bit in the entry
            if ((i_pgData[l_pgDataIndex]
                 & VPD_CP00_PG_xxx_PERV) != 0)
            {
                HWAS_INF("pDesc %.8X - PERV pgData[%d]: "
                         "actual 0x%04X, expected 0x%04X - bad",
                         i_desc->getAttr<ATTR_HUID>(),
                         l_pgDataIndex,
                         i_pgData[l_pgDataIndex],
                         (i_pgData[l_pgDataIndex] &
                          ~VPD_CP00_PG_xxx_PERV));
                l_descFunctional = false;
                break;
            }
        }
    }

    return l_descFunctional;
} // isDescFunctional



errlHndl_t restrictECunits(
    std::vector <procRestrict_t> &i_procList,
    const bool i_present,
    const uint32_t i_deconfigReason)
{
    HWAS_INF("restrictECunits entry, %d elements", i_procList.size());
    errlHndl_t errl = NULL;

    // sort by group so PROC# are in the right groupings.
    std::sort(i_procList.begin(), i_procList.end(),
                compareProcGroup);

    // loop thru procs to handle restrict
    const uint32_t l_ProcCount = i_procList.size();
    for (uint32_t procIdx = 0;
            procIdx < l_ProcCount;
            // the increment will happen in the loop to handle
            //  groups covering more than 1 proc target
        )
    {
        // determine the number of procs we should enable
        uint8_t procs = i_procList[procIdx].procs;
        uint32_t maxECs = i_procList[procIdx].maxECs;

        // this procs number, used to determine groupings
        uint32_t thisGroup = i_procList[procIdx].group;

        HWAS_INF("procRestrictList[%d] - maxECs %d, procs %d, group %d",
                procIdx, maxECs, procs, thisGroup);

        // exs, ecs, and iters for each proc in this vpd set
        TargetHandleList pEXList[procs];
        TargetHandleList::const_iterator pEX_it[procs];
        TargetHandleList pECList[procs][NUM_EX_PER_CHIP];
        TargetHandleList::const_iterator pEC_it[procs][NUM_EX_PER_CHIP];

        // find the proc's that we think are in this group
        uint32_t currentPairedECs = 0;
        uint32_t currentSingleECs = 0;
        for (uint32_t i = 0; i < procs; ) // increment in loop
        {
            TargetHandle_t pProc = i_procList[procIdx].target;

            // if this proc is past the last of the proc count
            //  OR is NOT in the same group
            if ((procIdx >= l_ProcCount) ||
                (thisGroup != i_procList[procIdx].group))
            {
                HWAS_DBG("procRestrictList[%d] - group %d not in group %d",
                        i, i_procList[procIdx].group, thisGroup);

                // change this to be how many we actually have here
                procs = i;

                // we're done - break so that we use procIdx as the
                //  start index next time
                break;
            }

            // get this proc's (CHILD) functional EX units
            getChildChiplets(pEXList[i], pProc, TYPE_EX, true);

            if (!pEXList[i].empty())
            {
                // sort the list by ATTR_HUID to ensure that we
                //  start at the same place each time
                std::sort(pEXList[i].begin(), pEXList[i].end(),
                          compareTargetHuid);

                // keep a pointer into that list
                pEX_it[i] = pEXList[i].begin();

                for (uint32_t j = 0;
                     (j < NUM_EX_PER_CHIP) && (pEX_it[i] != pEXList[i].end());
                     j++)
                {
                    TargetHandle_t pEX = *(pEX_it[i]);

                    // get this EX's (CHILD) functional EC/core units
                    getChildChiplets(pECList[i][j], pEX,
                                     TYPE_CORE, true);

                    if (!pECList[i][j].empty())
                    {
                        // sort the list by ATTR_HUID to ensure that we
                        //  start at the same place each time
                        std::sort(pECList[i][j].begin(), pECList[i][j].end(),
                                  compareTargetHuid);

                        // keep a pointer into that list
                        pEC_it[i][j] = pECList[i][j].begin();

                        // keep local count of current functional EC units
                        if (pECList[i][j].size() == 2)
                        {
                            // track ECs that can make a fused-core pair
                            currentPairedECs += pECList[i][j].size();
                        }
                        else
                        {
                            // track ECs without a pair for a fused-core
                            currentSingleECs += pECList[i][j].size();
                        }
                    }

                    // go to next EX
                    (pEX_it[i])++;
                } // for j < NUM_EX_PER_CHIP

                // go to next proc
                i++;
            }
            else
            {
                // this one is bad, stay on this i but lower the end count
                procs--;
            }

            // advance the outer loop as well since we're doing these
            //  procs together
            ++procIdx;
        } // for i < procs

        if ((currentPairedECs + currentSingleECs) <= maxECs)
        {
            // we don't need to restrict - we're done with this group.
            HWAS_DBG("currentECs %d <= maxECs %d -- done",
                    (currentPairedECs + currentSingleECs), maxECs);
            continue;
        }

        HWAS_DBG("currentECs %d > maxECs %d -- restricting!",
                (currentPairedECs + currentSingleECs), maxECs);

        // now need to find EC units that stay functional, going
        //  across the list of units for each proc and EX we have,
        //  until we get to the max or run out of ECs, giving
        //  preference to paired ECs and if we are in fused mode
        //  excluding single, non-paired ECs.

        // Use as many paired ECs as we can up to maxECs
        uint32_t pairedECs_remaining =
            (maxECs < currentPairedECs) ? maxECs : currentPairedECs;
        // If not in fused mode, use single ECs as needed to get to maxECs
        uint32_t singleECs_remaining =
            ((maxECs > currentPairedECs) && !is_fused_mode())
            ? (maxECs - currentPairedECs) : 0;
        uint32_t goodECs = 0;
        HWAS_DBG("procs %d maxECs %d", procs, maxECs);

        // Each pECList has ECs for a given EX and proc.  Check each EC list to
        //  determine if it has an EC pair or a single EC and if the remaining
        //  count indicates the given EC from that list is to stay functional.

        // Cycle through the procs
        for (uint32_t i = 0; i < procs; i++)
        {
            // Cycle through the EXs for this proc
            for (uint32_t j = 0; j < NUM_EX_PER_CHIP; j++)
            {
                // Walk through the EC list from this EX
                while (pEC_it[i][j] != pECList[i][j].end())
                {
                    // Check if EC pair for this EX
                    if ((pECList[i][j].size() == 2) &&
                        (pairedECs_remaining != 0))
                    {
                        // got a functional EC that is part of a pair
                        goodECs++;
                        pairedECs_remaining--;
                        HWAS_DBG("pEC   %.8X - is good %d!",
                                 (*(pEC_it[i][j]))->getAttr<ATTR_HUID>(),
                                 goodECs);
                    }
                    // Check if single EC for this EX
                    else if ((pECList[i][j].size() == 1) &&
                             (singleECs_remaining != 0))
                    {
                        // got a functional EC without a pair
                        goodECs++;
                        singleECs_remaining--;
                        HWAS_DBG("pEC   %.8X - is good %d!",
                                 (*(pEC_it[i][j]))->getAttr<ATTR_HUID>(),
                                 ++goodECs);
                    }
                    // Otherwise paired or single EC, but not needed for maxECs
                    else
                    {
                        // got an EC to be restricted and marked not functional
                        TargetHandle_t l_pEC = *(pEC_it[i][j]);
                        enableHwasState(l_pEC, i_present,
                                        false, i_deconfigReason);
                        HWAS_INF("pEC   %.8X - marked %spresent,"
                                 " NOT functional",
                                 l_pEC->getAttr<ATTR_HUID>(),
                                 i_present ? "" : "NOT ");
                    }

                    (pEC_it[i][j])++; // next ec in this ex's list
                } // while pEC_it[i][j] != pECList[i][j].end()
            } // for j < NUM_EX_PER_CHIP
        } // for i < procs
    } // for procIdx < l_ProcCount

    if (errl)
    {
        HWAS_INF("restrictECunits failed (plid 0x%X)", errl->plid());
    }
    else
    {
        HWAS_INF("restrictECunits completed successfully");
    }
    return errl;
} // restrictECunits


void checkCriticalResources(uint32_t & io_commonPlid,
                                  const Target * i_pTop)
{
    errlHndl_t l_errl = NULL;
    PredicatePostfixExpr l_customPredicate;
    PredicateIsFunctional l_isFunctional;

    TargetHandleList l_plist;

    // filter for targets that are deemed critical by ATTR_RESOURCE_IS_CRITICAL
    uint8_t l_critical = 1;
    PredicateAttrVal<ATTR_RESOURCE_IS_CRITICAL> l_isCritical(l_critical);

    l_customPredicate.push(&l_isFunctional).Not().push(&l_isCritical).And();

    targetService().getAssociated( l_plist, i_pTop,
          TargetService::CHILD, TargetService::ALL, &l_customPredicate);

    //if this list has ANYTHING then something critical has been deconfigured
    if(l_plist.size())
    {
        HWAS_ERR("Insufficient HW to continue IPL: (critical resource not functional)");
        /*@
         * @errortype
         * @severity          ERRL_SEV_UNRECOVERABLE
         * @moduleid          MOD_CHECK_MIN_HW
         * @reasoncode        RC_SYSAVAIL_MISSING_CRITICAL_RESOURCE
         * @devdesc           checkCriticalResources found a critical
         *                    resource to be deconfigured
         * @custdesc          A problem occurred during the IPL of the
         *                    system: A critical resource was found
         *                    to be deconfigured
         *
         * @userdata1[00:31]  Number of critical resources
         * @userdata1[32:63]  HUID of first critical resource found
         * @userdata2[00:31]  HUID of second critical resource found, if present
         * @userdata2[32:63]  HUID of third critical resource found, if present
         */

        uint64_t userdata1 = 0;
        uint64_t userdata2 = 0;
        switch(std::min(3,(int)l_plist.size()))
        {
            case 3:
                userdata2 = static_cast<uint64_t>(get_huid(l_plist[2]));

                /*fall through*/  // keep BEAM quiet
            case 2:
                userdata2 |=
                    static_cast<uint64_t>(get_huid(l_plist[1])) << 32;

                /*fall through*/  // keep BEAM quiet
            case 1:
                userdata1 =
                    (static_cast<uint64_t>(l_plist.size()) << 32) |
                     static_cast<uint64_t>(get_huid(l_plist[0]));
        }

        l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                           MOD_CHECK_MIN_HW,
                           RC_SYSAVAIL_MISSING_CRITICAL_RESOURCE,
                           userdata1,
                           userdata2 );

        // call out the procedure to find the deconfigured part.
        hwasErrorAddProcedureCallout(l_errl,
                                     EPUB_PRC_FIND_DECONFIGURED_PART,
                                     SRCI_PRIORITY_HIGH);

        //  if we already have an error, link this one to the earlier;
        //  if not, set the common plid
        hwasErrorUpdatePlid(l_errl, io_commonPlid);
        errlCommit(l_errl, HWAS_COMP_ID);
        // errl is now NULL
    }
}




errlHndl_t checkMinimumHardware(const TARGETING::ConstTargetHandle_t i_nodeOrSys,
        bool *o_bootable)
{
    errlHndl_t l_errl = NULL;
    HWAS_INF("checkMinimumHardware entry");
    uint32_t l_commonPlid = 0;

    do
    {
        //*********************************************************************/
        //  Common present and functional hardware checks.
        //*********************************************************************/

        if(o_bootable)
        {
            *o_bootable = true;
        }
        PredicateHwas l_present;
        l_present.present(true);
        PredicateHwas l_functional;
        if(o_bootable)
        {
            l_functional.specdeconfig(false);
        }
        l_functional.functional(true);

        // top 'starting' point - use first node if no i_node given (hostboot)
        Target *pTop;
        if (i_nodeOrSys == NULL)
        {
            Target *pSys;
            targetService().getTopLevelTarget(pSys);
            PredicateCTM l_predEnc(CLASS_ENC);
            PredicatePostfixExpr l_nodeFilter;
            l_nodeFilter.push(&l_predEnc).push(&l_functional).And();
            TargetHandleList l_nodes;
            targetService().getAssociated( l_nodes, pSys,
                TargetService::CHILD, TargetService::IMMEDIATE, &l_nodeFilter );

            if (l_nodes.empty())
            { // no functional nodes, get out now
                if(o_bootable)
                {
                    *o_bootable = false;
                    break;
                }

                HWAS_ERR("Insufficient HW to continue IPL: (no func nodes)");
                /*@
                 * @errortype
                 * @severity          ERRL_SEV_UNRECOVERABLE
                 * @moduleid          MOD_CHECK_MIN_HW
                 * @reasoncode        RC_SYSAVAIL_NO_NODES_FUNC
                 * @devdesc           checkMinimumHardware found no functional
                 *                    nodes on the system
                 * @custdesc          A problem occurred during the IPL of the
                 *                    system: No functional nodes were found on
                 *                    the system.
                 */
                l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                    MOD_CHECK_MIN_HW,
                                    RC_SYSAVAIL_NO_NODES_FUNC);

                // call out the procedure to find the deconfigured part.
                hwasErrorAddProcedureCallout(l_errl,
                                            EPUB_PRC_FIND_DECONFIGURED_PART,
                                            SRCI_PRIORITY_HIGH);

                //  if we already have an error, link this one to the earlier;
                //  if not, set the common plid
                hwasErrorUpdatePlid(l_errl, l_commonPlid);
                errlCommit(l_errl, HWAS_COMP_ID);
                // errl is now NULL
                break;
            }

            // top level has at least 1 node - and it's our node.
            pTop = l_nodes[0];

            HWAS_INF("checkMinimumHardware: i_nodeOrSys = NULL, using %.8X",
                    get_huid(pTop));
        }
        else
        {
            pTop = const_cast<Target *>(i_nodeOrSys);
            HWAS_INF("checkMinimumHardware: i_nodeOrSys %.8X",
                    get_huid(pTop));
        }

        // check for functional Master Proc on this node
        Target* l_pMasterProc = NULL;

        //Get master proc at system level or node level based on target type
        if(pTop->getAttr<ATTR_TYPE>() == TYPE_SYS)
        {
            targetService().queryMasterProcChipTargetHandle(l_pMasterProc);
        }
        else
        {
            targetService().queryMasterProcChipTargetHandle(l_pMasterProc,
                                                          pTop);
        }

        if ((l_pMasterProc == NULL) || (!l_functional(l_pMasterProc)))
        {
            HWAS_ERR("Insufficient HW to continue IPL: (no master proc)");

            if(o_bootable)
            {
                *o_bootable = false;
                break;
            }
            // determine some numbers to help figure out what's up..
            PredicateCTM l_proc(CLASS_CHIP, TYPE_PROC);
            TargetHandleList l_plist;

            PredicatePostfixExpr l_checkExprPresent;
            l_checkExprPresent.push(&l_proc).push(&l_present).And();
            targetService().getAssociated(l_plist, pTop,
                    TargetService::CHILD, TargetService::ALL,
                    &l_checkExprPresent);
            uint32_t procs_present = l_plist.size();

            PredicatePostfixExpr l_checkExprFunctional;
            l_checkExprFunctional.push(&l_proc).push(&l_functional).And();
            targetService().getAssociated(l_plist, pTop,
                    TargetService::CHILD, TargetService::ALL,
                    &l_checkExprFunctional);
            uint32_t procs_functional = l_plist.size();

            /*@
             * @errortype
             * @severity          ERRL_SEV_UNRECOVERABLE
             * @moduleid          MOD_CHECK_MIN_HW
             * @reasoncode        RC_SYSAVAIL_NO_PROCS_FUNC
             * @devdesc           checkMinimumHardware found no functional
             *                    master processor on this node
             * @custdesc          A problem occurred during the IPL of the
             *                    system: No functional master processor
             *                    was found on this node.
             * @userdata1[00:31]  HUID of node
             * @userdata2[00:31]  number of present procs
             * @userdata2[32:63]  number of present functional non-master procs
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(pTop)) << 32);
            const uint64_t userdata2 =
                (static_cast<uint64_t>(procs_present) << 32) | procs_functional;
            l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                MOD_CHECK_MIN_HW,
                                RC_SYSAVAIL_NO_PROCS_FUNC,
                                userdata1, userdata2);

            // call out the procedure to find the deconfigured part.
            hwasErrorAddProcedureCallout(l_errl,
                                        EPUB_PRC_FIND_DECONFIGURED_PART,
                                        SRCI_PRIORITY_HIGH);

            //  if we already have an error, link this one to the earlier;
            //  if not, set the common plid
            hwasErrorUpdatePlid(l_errl, l_commonPlid);
            errlCommit(l_errl, HWAS_COMP_ID);
            // errl is now NULL
        }
        else
        {
            // we have a Master Proc and it's functional
            // check for at least 1 functional ec/core on Master Proc
            TargetHandleList l_cores;
            PredicateCTM l_core(CLASS_UNIT, TYPE_CORE);
            PredicatePostfixExpr l_coresFunctional;
            l_coresFunctional.push(&l_core).push(&l_functional).And();
            targetService().getAssociated(l_cores, l_pMasterProc,
                    TargetService::CHILD, TargetService::ALL,
                    &l_coresFunctional);

            HWAS_DBG( "checkMinimumHardware: %d functional cores",
                      l_cores.size() );

            if (l_cores.empty())
            {
                HWAS_ERR("Insufficient HW to continue IPL: (no func cores)");

                if(o_bootable)
                {
                    *o_bootable = false;
                    break;
                }
                // determine some numbers to help figure out what's up..
                PredicateCTM l_ex(CLASS_UNIT, TYPE_EX);
                TargetHandleList l_plist;

                PredicatePostfixExpr l_checkExprPresent;
                l_checkExprPresent.push(&l_ex).push(&l_present).And();
                targetService().getAssociated(l_plist, l_pMasterProc,
                        TargetService::CHILD, TargetService::IMMEDIATE,
                        &l_checkExprPresent);
                uint32_t exs_present = l_plist.size();

                /*@
                 * @errortype
                 * @severity          ERRL_SEV_UNRECOVERABLE
                 * @moduleid          MOD_CHECK_MIN_HW
                 * @reasoncode        RC_SYSAVAIL_NO_CORES_FUNC
                 * @devdesc           checkMinimumHardware found no functional
                 *                    processor cores on the master proc
                 * @custdesc          A problem occurred during the IPL of the
                 *                    system: No functional processor cores
                 *                    were found on the master processor.
                 * @userdata1[00:31]  HUID of node
                 * @userdata1[32:63]  HUID of master proc
                 * @userdata2[00:31]  number of present, non-functional cores
                 */
                const uint64_t userdata1 =
                    (static_cast<uint64_t>(get_huid(pTop)) << 32) |
                    get_huid(l_pMasterProc);
                const uint64_t userdata2 =
                    (static_cast<uint64_t>(exs_present) << 32);
                l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                    MOD_CHECK_MIN_HW,
                                    RC_SYSAVAIL_NO_CORES_FUNC,
                                    userdata1, userdata2);

                //  call out the procedure to find the deconfigured part.
                hwasErrorAddProcedureCallout( l_errl,
                                              EPUB_PRC_FIND_DECONFIGURED_PART,
                                              SRCI_PRIORITY_HIGH );

                //  if we already have an error, link this one to the earlier;
                //  if not, set the common plid
                hwasErrorUpdatePlid( l_errl, l_commonPlid );
                errlCommit(l_errl, HWAS_COMP_ID);
                // errl is now NULL
            } // if no cores
        }

        //  check here for functional dimms
        TargetHandleList l_dimms;
        PredicateCTM l_dimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
        PredicatePostfixExpr l_checkExprFunctional;
        l_checkExprFunctional.push(&l_dimm).push(&l_functional).And();
        targetService().getAssociated(l_dimms, pTop,
                TargetService::CHILD, TargetService::ALL,
                &l_checkExprFunctional);
        HWAS_DBG( "checkMinimumHardware: %d functional dimms",
                  l_dimms.size());

// @todo RTC:149770 Once ZZ supports DIMMs, add DIMMs back in min hdw check.
// It works for stand alone.
#if (0)
        if (l_dimms.empty())
        {
            HWAS_ERR( "Insufficient hardware to continue IPL (func DIMM)");

            if(o_bootable)
            {
                *o_bootable = false;
                break;
            }
            // determine some numbers to help figure out what's up..
            TargetHandleList l_plist;
            PredicatePostfixExpr l_checkExprPresent;
            l_checkExprPresent.push(&l_dimm).push(&l_present).And();
            targetService().getAssociated(l_plist, pTop,
                    TargetService::CHILD, TargetService::ALL,
                    &l_checkExprPresent);
            uint32_t dimms_present = l_plist.size();

            /*@
             * @errortype
             * @severity          ERRL_SEV_UNRECOVERABLE
             * @moduleid          MOD_CHECK_MIN_HW
             * @reasoncode        RC_SYSAVAIL_NO_MEMORY_FUNC
             * @devdesc           checkMinimumHardware found no
             *                    functional dimm cards.
             * @custdesc          A problem occurred during the IPL of the
             *                    system: Found no functional dimm cards.
             * @userdata1[00:31]  HUID of node
             * @userdata2[00:31]  number of present, non-functional dimms
             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(pTop)) << 32);
            const uint64_t userdata2 =
                (static_cast<uint64_t>(dimms_present) << 32);
            l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                                MOD_CHECK_MIN_HW,
                                RC_SYSAVAIL_NO_MEMORY_FUNC,
                                userdata1, userdata2);

            //  call out the procedure to find the deconfigured part.
            hwasErrorAddProcedureCallout( l_errl,
                                          EPUB_PRC_FIND_DECONFIGURED_PART,
                                          SRCI_PRIORITY_HIGH );

            //  if we already have an error, link this one to the earlier;
            //  if not, set the common plid
            hwasErrorUpdatePlid( l_errl, l_commonPlid );
            errlCommit(l_errl, HWAS_COMP_ID);
            // errl is now NULL
        } // if no dimms
#endif
        // There needs to be either functional MCS/MCAs (NIMBUS) or MCS/MBAs
        // (CUMULUS). Check for MCAs first.
        PredicateCTM l_mca(CLASS_UNIT, TYPE_MCA);

        TargetHandleList l_presMcaTargetList;
        PredicatePostfixExpr l_checkExprPresMca;
        l_checkExprPresMca.push(&l_mca).push(&l_present).And();
        targetService().getAssociated( l_presMcaTargetList, pTop,
                TargetService::CHILD, TargetService::ALL,
                &l_checkExprPresMca);
        // If any MCAs are present, then some must be functional
        if (!l_presMcaTargetList.empty())
        {
            TargetHandleList l_funcMcaTargetList;
            PredicatePostfixExpr l_checkExprPresMca;
            l_checkExprPresMca.push(&l_mca).push(&l_functional).And();
            targetService().getAssociated( l_funcMcaTargetList, pTop,
                TargetService::CHILD, TargetService::ALL,
                &l_checkExprPresMca);

            HWAS_DBG( "checkMinimumHardware: %d functional MCAs",
                l_funcMcaTargetList.size());

            if (l_funcMcaTargetList.empty())
            {
                 HWAS_ERR( "Insufficient hardware to continue IPL"
                           " (func membufs)");
                if(o_bootable)
                {
                    *o_bootable = false;
                    break;
                }
                uint32_t mca_present = l_presMcaTargetList.size();

                /*@
                 * @errortype
                 * @severity           ERRL_SEV_UNRECOVERABLE
                 * @moduleid           MOD_CHECK_MIN_HW
                 * @reasoncode         RC_SYSAVAIL_NO_MCAS_FUNC
                 * @devdesc            checkMinimumHardware found no
                 *                     functional membufs
                 * @custdesc           A problem occurred during the IPL of the
                 *                     system: Found no functional dimm cards.
                 * @userdata1[00:31]   HUID of node
                 * @userdata2[00:31]   number of present nonfunctional membufs
                 */
                const uint64_t userdata1 =
                    (static_cast<uint64_t>(get_huid(pTop)) << 32);
                const uint64_t userdata2 =
                    (static_cast<uint64_t>(mca_present) << 32);
                l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                             MOD_CHECK_MIN_HW,
                             RC_SYSAVAIL_NO_MCAS_FUNC,
                             userdata1, userdata2);

                //  call out the procedure to find the deconfigured part.
                hwasErrorAddProcedureCallout( l_errl,
                             EPUB_PRC_FIND_DECONFIGURED_PART,
                             SRCI_PRIORITY_HIGH );

                //  if we already have an error, link this one to the earlier;
                //  if not, set the common plid
                hwasErrorUpdatePlid( l_errl, l_commonPlid );
                errlCommit(l_errl, HWAS_COMP_ID);
                // errl is now NULL
            }
        }
        else  // there were no MCAa. There must be functional membufs
        {
            PredicateCTM l_membuf(CLASS_CHIP, TYPE_MEMBUF);

            TargetHandleList l_funcMembufTargetList;
            PredicatePostfixExpr l_checkExprFunctionalMembufs;
            l_checkExprFunctionalMembufs.push(&l_membuf).
                                                      push(&l_functional).And();
            targetService().getAssociated( l_funcMembufTargetList, pTop,
                TargetService::CHILD, TargetService::ALL,
                &l_checkExprFunctionalMembufs);

            HWAS_DBG( "checkMinimumHardware: %d functional membufs",
                l_funcMembufTargetList.size());

            if (l_funcMembufTargetList.empty())
            {
                 HWAS_ERR( "Insufficient hardware to continue IPL"
                           " (func membufs)");
                if(o_bootable)
                {
                    *o_bootable = false;
                    break;
                }
                TargetHandleList l_presentMembufTargetList;
                PredicatePostfixExpr l_checkExprPresentMembufs;
                l_checkExprPresentMembufs.push(&l_membuf).
                                                      push(&l_present).And();
                targetService().getAssociated( l_presentMembufTargetList, pTop,
                TargetService::CHILD, TargetService::ALL,
                &l_checkExprPresentMembufs);
                uint32_t membufs_present = l_presentMembufTargetList.size();

                /*@
                 * @errortype
                 * @severity           ERRL_SEV_UNRECOVERABLE
                 * @moduleid           MOD_CHECK_MIN_HW
                 * @reasoncode         RC_SYSAVAIL_NO_MEMBUFS_FUNC
                 * @devdesc            checkMinimumHardware found no
                 *                     functional membufs
                 * @custdesc           A problem occurred during the IPL of the
                 *                     system: Found no functional dimm cards.
                 * @userdata1[00:31]   HUID of node
                 * @userdata2[00:31]   number of present nonfunctional membufs
                 */
                const uint64_t userdata1 =
                    (static_cast<uint64_t>(get_huid(pTop)) << 32);
                const uint64_t userdata2 =
                    (static_cast<uint64_t>(membufs_present) << 32);
                l_errl = hwasError(ERRL_SEV_UNRECOVERABLE,
                             MOD_CHECK_MIN_HW,
                             RC_SYSAVAIL_NO_MEMBUFS_FUNC,
                             userdata1, userdata2);

                //  call out the procedure to find the deconfigured part.
                hwasErrorAddProcedureCallout( l_errl,
                             EPUB_PRC_FIND_DECONFIGURED_PART,
                             SRCI_PRIORITY_HIGH );

                //  if we already have an error, link this one to the earlier;
                //  if not, set the common plid
                hwasErrorUpdatePlid( l_errl, l_commonPlid );
                errlCommit(l_errl, HWAS_COMP_ID);
                // errl is now NULL
            }
        }
        //  ------------------------------------------------------------
        //  Check for Mirrored memory -
        //  If the user requests mirrored memory and we do not have it,
        //  post an errorlog but do not return a terminating error.
        //  ------------------------------------------------------------
        //  Need to read an attribute set by PHYP?


        //  check for minimum hardware that is specific to platform that we're
        //  running on (ie, hostboot or fsp in hwsv).
        //  if there is an issue, create and commit an error, and tie it to the
        //  the rest of them with the common plid.
        HWAS::checkCriticalResources(l_commonPlid, pTop);
        platCheckMinimumHardware(l_commonPlid, i_nodeOrSys, o_bootable);
    }
    while (0);

    //  ---------------------------------------------------------------
    // if the common plid got set anywhere above, we have an error.
    //  ---------------------------------------------------------------
    if ((l_commonPlid)&&(o_bootable == NULL))
    {
        /*@
         * @errortype
         * @severity          ERRL_SEV_UNRECOVERABLE
         * @moduleid          MOD_CHECK_MIN_HW
         * @reasoncode        RC_SYSAVAIL_INSUFFICIENT_HW
         * @devdesc           Insufficient hardware to continue.
         */
        l_errl  =   hwasError(  ERRL_SEV_UNRECOVERABLE,
                                MOD_CHECK_MIN_HW,
                                RC_SYSAVAIL_INSUFFICIENT_HW);
        //  call out the procedure to find the deconfigured part.
        hwasErrorAddProcedureCallout( l_errl,
                                      EPUB_PRC_FIND_DECONFIGURED_PART,
                                      SRCI_PRIORITY_HIGH );
        //  if we already have an error, link this one to the earlier;
        //  if not, set the common plid
        hwasErrorUpdatePlid( l_errl, l_commonPlid );
    }

    HWAS_INF("checkMinimumHardware exit - minimum hardware %s",
            ((l_errl != NULL)||((o_bootable!=NULL)&&(!*o_bootable))) ?
                    "NOT available" : "available");
    return  l_errl ;
} // checkMinimumHardware



/**
 * @brief Checks if both targets have the same paths up to a certain number
 *        of path elements, determined by the smaller affinity path.
 *
 * @param[in] i_t1 TargetInfo containing the first target's affinity path
 * @param[in] i_t2 TargetInfo containing the second target's affinity path
 */
bool isSameSubPath(TargetInfo i_t1, TargetInfo i_t2)
{
    size_t l_size = std::min(i_t1.affinityPath.size(),
                             i_t2.affinityPath.size());
    return i_t1.affinityPath.equals(i_t2.affinityPath, l_size);
}

/**
 * @brief Deconfigures a target based on type
 *
 * Called by invokePresentByAssoc() after presentByAssoc() is called
 *
 * @param[in] i_targInfo TargetInfo for the target to be deconfigured
 */
void deconfigPresentByAssoc(TargetInfo i_targInfo)
{
    TargetHandleList pChildList;

    // find all CHILD matches for this target and deconfigure them
    getChildChiplets(pChildList, i_targInfo.pThisTarget, TYPE_NA);

    for (TargetHandleList::const_iterator
            pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t l_childTarget = *pChild_it;
        enableHwasState(l_childTarget, true, false, i_targInfo.reason);
        HWAS_INF("deconfigPresentByAssoc: Target %.8X"
                " marked present, not functional: reason %.x",
                l_childTarget->getAttr<ATTR_HUID>(), i_targInfo.reason);
    }

    // find all CHILD_BY_AFFINITY matches for this target and deconfigure them
    getChildAffinityTargets(pChildList, i_targInfo.pThisTarget,
                            CLASS_NA ,TYPE_NA);

    for (TargetHandleList::const_iterator
            pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t l_affinityTarget = *pChild_it;
        enableHwasState(l_affinityTarget,true,false, i_targInfo.reason);
        HWAS_INF("deconfigPresentByAssoc: Target %.8X"
                " marked present, not functional: reason %.x",
                l_affinityTarget->getAttr<ATTR_HUID>(), i_targInfo.reason);
    }

    // deconfigure the target itself
    enableHwasState(i_targInfo.pThisTarget,true,false,i_targInfo.reason);
    HWAS_INF("deconfigPresentByAssoc: Target %.8X"
            " marked present, not functional, reason %.x",
            i_targInfo.pThisTarget->getAttr<ATTR_HUID>(), i_targInfo.reason);

} // deconfigPresentByAssoc

void invokePresentByAssoc()
{
    HWAS_DBG("invokePresentByAssoc enter");

    // make one list
    TargetHandleList l_funcTargetList;

    // get the functional MCSs
    TargetHandleList l_funcMCSTargetList;
    getAllChiplets(l_funcMCSTargetList, TYPE_MCS, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcMCSTargetList.begin(),
                               l_funcMCSTargetList.end());

// If VPO, dump targets (MCS) for verification & debug purposes
#ifdef CONFIG_VPO_COMPILE
    HWAS_INF("invokePresentByAssoc(): MCS targets:");
    for (TargetHandleList::const_iterator
            l_MCS_Itr = l_funcMCSTargetList.begin();
            l_MCS_Itr != l_funcMCSTargetList.end();
            l_MCS_Itr++)
    {
        HWAS_INF("   MCS: HUID %.8x", TARGETING::get_huid(*l_MCS_Itr));
    }
#endif

    // get the functional membufs
    // note: do not expect membufs for NIMBUS direct memory attach
    TargetHandleList l_funcMembufTargetList;
    getAllChips(l_funcMembufTargetList, TYPE_MEMBUF, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcMembufTargetList.begin(),
                               l_funcMembufTargetList.end());

// If VPO, dump targets (MEMBUF) for verification & debug purposes
#ifdef CONFIG_VPO_COMPILE
    HWAS_INF("invokePresentByAssoc(): MEMBUF targets:");
    for (TargetHandleList::const_iterator
            l_MEMBUF_Itr = l_funcMembufTargetList.begin();
            l_MEMBUF_Itr != l_funcMembufTargetList.end();
            l_MEMBUF_Itr++)
    {
        HWAS_INF("   MEMBUF: HUID %.8x", TARGETING::get_huid(*l_MEMBUF_Itr));
    }
#endif

    // get the functional mbas
    // note: do not expect mbas for NIMBUS direct memory attach
    TargetHandleList l_funcMBATargetList;
    getAllChiplets(l_funcMBATargetList, TYPE_MBA, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcMBATargetList.begin(),
                               l_funcMBATargetList.end());

// If VPO, dump targets (MBA) for verification & debug purposes
#ifdef CONFIG_VPO_COMPILE
    HWAS_INF("invokePresentByAssoc(): MBA targets:");
    for (TargetHandleList::const_iterator
            l_MBA_Itr = l_funcMBATargetList.begin();
            l_MBA_Itr != l_funcMBATargetList.end();
            l_MBA_Itr++)
    {
        HWAS_INF("   MBA: HUID %.8x", TARGETING::get_huid(*l_MBA_Itr));
    }
#endif

    // get the functional MCAs
    // note: MCAs are expected for NIMBUS direct memory attach
    TargetHandleList l_funcMcaTargetList;
    getAllChiplets(l_funcMcaTargetList, TYPE_MCA, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcMcaTargetList.begin(),
                               l_funcMcaTargetList.end());

// If VPO, dump targets (MCA) for verification & debug purposes
#ifdef CONFIG_VPO_COMPILE
    HWAS_INF("invokePresentByAssocDA(): MCA targets:");
    for (TargetHandleList::const_iterator
            l_MCA_Itr = l_funcMcaTargetList.begin();
            l_MCA_Itr != l_funcMcaTargetList.end();
            l_MCA_Itr++)
    {
        HWAS_INF("   MCA: HUID %.8x", TARGETING::get_huid(*l_MCA_Itr));
    }
#endif
    // get the functional dimms
    TargetHandleList l_funcDIMMTargetList;
    getAllLogicalCards(l_funcDIMMTargetList, TYPE_DIMM, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcDIMMTargetList.begin(),
                               l_funcDIMMTargetList.end());


// If VPO, dump targets (DIMM) for verification & debug purposes
#ifdef CONFIG_VPO_COMPILE
    HWAS_INF("invokePresentByAssoc(): DIMM targets:");
    for (TargetHandleList::const_iterator
            l_DIMM_Itr = l_funcDIMMTargetList.begin();
            l_DIMM_Itr != l_funcDIMMTargetList.end();
            l_DIMM_Itr++)
    {
        HWAS_INF("   DIMM: HUID %.8x", TARGETING::get_huid(*l_DIMM_Itr));
    }
#endif

    // Define vectors of TargetInfo structs to be used in presentByAssoc
    TargetInfoVector l_targInfo;
    TargetInfoVector l_targToDeconfig;

    // Iterate through targets and populate l_targInfo vector
    for (TargetHandleList::const_iterator
            l_targIter = l_funcTargetList.begin();
            l_targIter != l_funcTargetList.end();
            ++l_targIter)
    {
        TargetHandle_t pTarg = *l_targIter;
        TargetInfo l_TargetInfo;
        l_TargetInfo.pThisTarget    = pTarg;
        l_TargetInfo.affinityPath   = pTarg->getAttr<ATTR_AFFINITY_PATH>();
        l_TargetInfo.type           = pTarg->getAttr<ATTR_TYPE>();
        l_targInfo.push_back(l_TargetInfo);
    }

    // Call presentByAssoc to take the functional targets in l_targInfo
    // and determine which ones need to be deconfigured
    presentByAssoc(l_targInfo, l_targToDeconfig);

    // Deconfigure targets in l_targToDeconfig
    for (TargetInfoVector::const_iterator
         l_targIter = l_targToDeconfig.begin();
         l_targIter != l_targToDeconfig.end();
         ++l_targIter)
    {
        deconfigPresentByAssoc(*l_targIter);
    }
} // invokePresentByAssoc

void presentByAssoc(TargetInfoVector& io_funcTargets,
                    TargetInfoVector& o_targToDeconfig)
{
    HWAS_DBG("presentByAssoc entry");

    // Sort entire vector by affinity path. This provides the algorithm with
    // an ordered vector of targets, making it easy to check if:
    // for direct attach memory -
    //   MCS has child MCA
    //   MCA has child DIMM and parent MCS
    //   DIMM has parent MCA.
    // for non direct attach memory -
    //   MCS has child MEMBUF
    //   MEMBUF has parent MCS and child MBA
    //   MBA has child DIMM and parnent MEMBUF
    //   DIMM has parent MBA.
    std::sort(io_funcTargets.begin(), io_funcTargets.end(),
              compareAffinity);

    // Keep track of the most recently seen MCS MEMBUF and MBA. This allows the
    // algorithm to quickly check if targets share a MCS or MEMBUF and used
    // for backtracking after deleting a target from the vector
    size_t l_MCSIndex = __INT_MAX__;
    size_t l_MEMBUFIndex = __INT_MAX__;
    size_t l_MBAIndex = __INT_MAX__;
    size_t l_MCAIndex = __INT_MAX__;
    size_t i = 0;

    // Perform presentByAssoc algorithm
    while ( i < io_funcTargets.size() )
    {
        // INIT STEPS:
        // Reset iterator, check if the next taget in
        // the vector is valid or even needed

        // Get iterator to erase elements from vector when needed
        std::vector<TargetInfo>::iterator it = io_funcTargets.begin();
        std::advance(it,i);
        TargetInfo& l_curTargetInfo = *it;

        // Check if there is a next target and set it
        // Don't need to check next target with a DIMM
        TargetInfo* l_nextTargetInfo = NULL;
        if ( ((i + 1) < io_funcTargets.size()) &&
             (l_curTargetInfo.type != TYPE_DIMM) )
        {
            l_nextTargetInfo = &(*(it + 1));
        }

        switch (l_curTargetInfo.type)
        {
        case TYPE_MCS:
        {
            // No Child MEMBUFs or MCAs
            // If next is not a MEMBUF or MCA sharing the same MCS, deconfig MCS
            if ( (l_nextTargetInfo == NULL) ||
                 ( (l_nextTargetInfo->type != TYPE_MEMBUF) &&
                   (l_nextTargetInfo->type != TYPE_MCA) ) ||
                 !isSameSubPath(l_curTargetInfo, *l_nextTargetInfo) )
            {
                // Disable MCS - NO_CHILD_MEMBUF_OR_MCA
                l_curTargetInfo.reason =
                        DeconfigGard::DECONFIGURED_BY_NO_CHILD_MEMBUF_OR_MCA;
                // Add target to Deconfig vector to be deconfigured later
                o_targToDeconfig.push_back(l_curTargetInfo);
                // Remove target from funcTargets
                io_funcTargets.erase(it);
            }
            // Update MCS Index
            else
            {
                l_MCSIndex = i;
                i++;
            }
            break;
        } // MCS

        case TYPE_MEMBUF:
        {
            // No Child MBAs
            // If next is not a MBA sharing the same MEMBUF, deconfig MEMBUF
            if ( (l_nextTargetInfo == NULL) ||
                 (l_nextTargetInfo->type != TYPE_MBA) ||
                 !isSameSubPath(l_curTargetInfo, *l_nextTargetInfo) )
            {
                // Disable MEMBUF - NO_CHILD_MBA
                l_curTargetInfo.reason =
                        DeconfigGard::DECONFIGURED_BY_NO_CHILD_MBA;
            }
            // No Parent MCS
            // If MEMBUF doesn't share the same MCS as MCSIndex, deconfig MEMBUF
            else if ( (l_MCSIndex == __INT_MAX__) ||
                    !isSameSubPath(l_curTargetInfo, io_funcTargets[l_MCSIndex]))
            {
                // Disable MEMBUF - NO_PARENT_MCS
                l_curTargetInfo.reason =
                        DeconfigGard::DECONFIGURED_BY_NO_PARENT_MCS;
            }
            // Update MEMBUF Index
            else
            {
                l_MEMBUFIndex = i;
                i++;
                continue;
            }

            // Add target to deconfig vector to be deconfigured later
            o_targToDeconfig.push_back(l_curTargetInfo);
            // Remove target from funcTargets
            io_funcTargets.erase(it);

            // Backtrack to last MCS
            if ( l_MCSIndex != __INT_MAX__ )
            {
                i = l_MCSIndex;
            }
            // Backtrack to beginning if no MCS has been seen yet
            else
            {
                i = 0;
            }
            break;
        } // MEMBUF

        case TYPE_MBA:
        {
            // No Child DIMMs
            // If next is not a DIMM sharing the same MBA, deconfig MBA
            if ( (l_nextTargetInfo == NULL) ||
                 (l_nextTargetInfo->type != TYPE_DIMM) ||
                 !isSameSubPath(l_curTargetInfo, *l_nextTargetInfo) )
            {
                // Disable MBA - NO_CHILD_DIMM
                l_curTargetInfo.reason =
                        DeconfigGard::DECONFIGURED_BY_NO_CHILD_DIMM;
            }
            // No Parent MEMBUF
            // If MBA doesn't share the same MEMBUF as MEMBUFIndex, deconfig MBA
            else if ( (l_MEMBUFIndex == __INT_MAX__) ||
                    !isSameSubPath(l_curTargetInfo, io_funcTargets[l_MEMBUFIndex]))
            {
                // Disable MBA - NO_PARENT_MEMBUF
                l_curTargetInfo.reason =
                        DeconfigGard::DECONFIGURED_BY_NO_PARENT_MEMBUF;
            }
            // Update MBA Index
            else
            {
                l_MBAIndex = i;
                i++;
                continue;
            }

            // Add target to deconfig vector to be deconfigured later
            o_targToDeconfig.push_back(l_curTargetInfo);
            // Remove target from funcTargets
            io_funcTargets.erase(it);

            // Backtrack to last MEMBUF
            if ( l_MEMBUFIndex != __INT_MAX__ )
            {
                i = l_MEMBUFIndex;
            }
            // Backtrack to last MCS if no MEMBUF has been seen yet
            else if ( l_MCSIndex != __INT_MAX__)
            {
                i = l_MCSIndex;
            }
            // Backtrack to beginning if no MCS has been seen yet
            else
            {
                i = 0;
            }
            break;
        } // MBA

        case TYPE_MCA:
        {
// @todo RTC:149770 Once ZZ supports DIMMs, add DIMMs back in min hdw check.
// It works for stand alone.
#if (0)
            // No Child DIMMs
            // If next is not a DIMM sharing the same MCA, deconfig MCS
            if ( (l_nextTargetInfo == NULL) ||
                 (l_nextTargetInfo->type != TYPE_DIMM) ||
                 !isSameSubPath(l_curTargetInfo, *l_nextTargetInfo) )
            {
                // Disable MCS - NO_CHILD_DIMM
                l_curTargetInfo.reason =
                        DeconfigGard::DECONFIGURED_BY_NO_CHILD_DIMM;
            }
            // No Parent MCS
            // If MCA doesn't share the same MCS as MCSIndex, deconfig MCA
            else
#endif // the new line can be removed
            if ( (l_MCSIndex == __INT_MAX__) ||
                    !isSameSubPath(l_curTargetInfo, io_funcTargets[l_MCSIndex]))
            {
                // Disable MCA - NO_PARENT_MCS
                l_curTargetInfo.reason =
                        DeconfigGard::DECONFIGURED_BY_NO_PARENT_MCS;
            }
            // Update MCA Index
            else
            {
                l_MCAIndex = i;
                i++;
                continue;
            }

            // Add target to deconfig vector to be deconfigured later
            o_targToDeconfig.push_back(l_curTargetInfo);
            // Remove target from funcTargets
            io_funcTargets.erase(it);

            // Backtrack to last MCS
            if ( l_MCSIndex != __INT_MAX__ )
            {
                i = l_MCSIndex;
            }
            // Backtrack to beginning if no MCS has been seen yet
            else
            {
                i = 0;
            }
            break;
        } // MCS

        case TYPE_DIMM:
        {
            // No Parent MBA or MCA
            // If DIMM does not share the same MBA as MBAIndex,
            // or if DIMM does not share the same MCA as MCAIndex,
            // deconfig DIMM
            if ( ((l_MBAIndex == __INT_MAX__) ||
                 !isSameSubPath(l_curTargetInfo, io_funcTargets[l_MBAIndex])) &&
                 ((l_MCAIndex == __INT_MAX__) ||
                 !isSameSubPath(l_curTargetInfo, io_funcTargets[l_MCAIndex])) )
            {
                // Disable DIMM
                l_curTargetInfo.reason =
                        DeconfigGard::DECONFIGURED_BY_NO_PARENT_MBA_OR_MCA;

                // Add target to deconfig vector to be deconfigured later
                o_targToDeconfig.push_back(l_curTargetInfo);
                // Remove target from funcTargets
                io_funcTargets.erase(it);

                // Backtrack to last MBA
                if ( l_MBAIndex != __INT_MAX__ )
                {
                    i = l_MBAIndex;
                }
                // Backtrack to last MCA
                else if ( l_MCAIndex != __INT_MAX__)
                {
                    i = l_MCSIndex;
                }
                // Backtrack to last MEMBUF if no MBA has been seen yet
                else if ( l_MEMBUFIndex != __INT_MAX__)
                {
                    i = l_MEMBUFIndex;
                }
                // Backtrack to last MCS if no MEMBUF has been seen yet
                else if ( l_MCSIndex != __INT_MAX__)
                {
                    i = l_MCSIndex;
                }
                // Backtrack to beginning if no MCS has been seen yet
                else
                {
                    i = 0;
                }
            }
            else
            {
                i++;
            }
            break;
        } // DIMM
        default:
            // no action
            break;
        } // switch
    } // while
} // presentByAssoc

};   // end namespace
