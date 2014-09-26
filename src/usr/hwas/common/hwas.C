/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/hwas.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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


errlHndl_t discoverTargets()
{
    HWAS_INF("discoverTargets entry");
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
    // CLASS_ENC, TYPE_PROC, TYPE_MEMBUF, TYPE_DIMM
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
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predChip).push(&predDimm).Or().push(&predEnc).Or();

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
                    // look at the 'nest' logic to override the functionality
                    //  of this proc
                    if (pgData[VPD_CP00_PG_PIB_INDEX] !=
                                    VPD_CP00_PG_PIB_GOOD)
                    {
                        HWAS_INF("pTarget %.8X - PIB pgPdata[%d]: expected 0x%04X - bad",
                            pTarget->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_PIB_INDEX,
                            VPD_CP00_PG_PIB_GOOD);
                        chipFunctional = false;
                    }
                    else
                    if (pgData[VPD_CP00_PG_PERVASIVE_INDEX] !=
                                    VPD_CP00_PG_PERVASIVE_GOOD)
                    {
                        HWAS_INF("pTarget %.8X - Pervasive pgPdata[%d]: expected 0x%04X - bad",
                            pTarget->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_PERVASIVE_INDEX,
                            VPD_CP00_PG_PERVASIVE_GOOD);
                        chipFunctional = false;
                    }
                    else
                    if ((pgData[VPD_CP00_PG_POWERBUS_INDEX] &
                             VPD_CP00_PG_POWERBUS_BASE) !=
                                    VPD_CP00_PG_POWERBUS_BASE)
                    {
                        HWAS_INF("pTarget %.8X - PowerBus pgPdata[%d]: expected 0x%04X - bad",
                            pTarget->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_POWERBUS_INDEX,
                            VPD_CP00_PG_POWERBUS_BASE);
                        chipFunctional = false;
                    }
                    else
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
                            l_procEntry.maxEXs = l_procEntry.procs *
                                        (prData[2] & VPD_VINI_PR_B2_MASK)
                                            >> VPD_VINI_PR_B2_SHIFT;
                            l_procPRList.push_back(l_procEntry);

                            if (l_procEntry.maxEXs == 0)
                            {
                                // this is PROBABLY bad PR, so YELL...
                                HWAS_ERR("pTarget %.8X - PR VPD says 0 CORES",
                                    pTarget->getAttr<ATTR_HUID>());
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
                {   // if the chip is functional, the look through the
                    //  partialGood vector to see if its chiplets
                    //  are functional
                    if ((pDesc->getAttr<ATTR_TYPE>() == TYPE_XBUS) &&
                        (pgData[VPD_CP00_PG_XBUS_INDEX] !=
                            VPD_CP00_PG_XBUS_GOOD))
                    {
                        HWAS_INF("pDesc %.8X - XBUS  pgPdata[%d]: expected 0x%04X - bad",
                            pDesc->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_XBUS_INDEX,
                            VPD_CP00_PG_XBUS_GOOD);
                        descFunctional = false;
                    }
                    else
                    if ((pDesc->getAttr<ATTR_TYPE>() == TYPE_ABUS) &&
                        (pgData[VPD_CP00_PG_ABUS_INDEX] !=
                            VPD_CP00_PG_ABUS_GOOD))
                    {
                        HWAS_INF("pDesc %.8X - ABUS pgPdata[%d]: expected 0x%04X - bad",
                            pDesc->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_ABUS_INDEX,
                            VPD_CP00_PG_ABUS_GOOD);
                        descFunctional = false;
                    }
                    else
                    if ((pDesc->getAttr<ATTR_TYPE>() == TYPE_PCI) &&
                        (pgData[VPD_CP00_PG_PCIE_INDEX] !=
                            VPD_CP00_PG_PCIE_GOOD))
                    {
                        HWAS_INF("pDesc %.8X - PCIe pgPdata[%d]: expected 0x%04X - bad",
                            pDesc->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_PCIE_INDEX,
                            VPD_CP00_PG_PCIE_GOOD);
                        descFunctional = false;
                    }
                    else
                    if ((pDesc->getAttr<ATTR_TYPE>() == TYPE_EX) ||
                        (pDesc->getAttr<ATTR_TYPE>() == TYPE_CORE)
                       )
                    {
                      ATTR_CHIP_UNIT_type indexEX =
                                pDesc->getAttr<ATTR_CHIP_UNIT>();
                      if (pgData[VPD_CP00_PG_EX0_INDEX + indexEX] !=
                            VPD_CP00_PG_EX0_GOOD)
                      {
                        HWAS_INF("pDesc %.8X - CORE/EX%d pgPdata[%d]: expected 0x%04X - bad",
                            pDesc->getAttr<ATTR_HUID>(), indexEX,
                            VPD_CP00_PG_EX0_INDEX + indexEX,
                            VPD_CP00_PG_EX0_GOOD);
                        descFunctional = false;
                      }
                    }
                    else
                    if (pDesc->getAttr<ATTR_TYPE>() == TYPE_MCS)
                    {
                      ATTR_CHIP_UNIT_type indexMCS =
                                pDesc->getAttr<ATTR_CHIP_UNIT>();
                      // check: MCS 0..3 in MCL, MCS 4..7 in MCR
                      if (((indexMCS >=0) && (indexMCS <=3)) &&
                          ((pgData[VPD_CP00_PG_POWERBUS_INDEX] &
                            VPD_CP00_PG_POWERBUS_MCL) == 0))
                      {
                        HWAS_INF("pDesc %.8X - MCS%d pgPdata[%d]: MCL expected 0x%04X - bad",
                            pDesc->getAttr<ATTR_HUID>(), indexMCS,
                            VPD_CP00_PG_POWERBUS_INDEX,
                            VPD_CP00_PG_POWERBUS_MCL);
                        descFunctional = false;
                      }
                      else
                      if (((indexMCS >=4) && (indexMCS <=7)) &&
                          ((pgData[VPD_CP00_PG_POWERBUS_INDEX] &
                            VPD_CP00_PG_POWERBUS_MCR) == 0))
                      {
                        HWAS_INF("pDesc %.8X - MCS%d pgPdata[%d]: MCR expected 0x%04X - bad",
                            pDesc->getAttr<ATTR_HUID>(), indexMCS,
                            VPD_CP00_PG_POWERBUS_INDEX,
                            VPD_CP00_PG_POWERBUS_MCR);
                        descFunctional = false;
                      }
                    }
                } // chipFunctional

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
                HWAS_INF("discoverTargets: Proc not present HUID=0x%X",
                (*l_procsIter)->getAttr<ATTR_HUID>());
                HWAS::theDeconfigGard().setXABusEndpointDeconfigured(true);
            }
        }

        // PR keyword processing - potentially reduce the number of ex/core
        //  units that are functional based on what's in the PR keyword.
        //  call to restrict EX units, marking bad units as present=false;
        //  deconfigReason = 0 because present is false so this is not a
        //  deconfigured event.
#ifndef CONFIG_SKIP_RESTRICT_EX_UNITS
        errl = restrictEXunits(l_procPRList, false, 0);

        if (errl)
        {
            HWAS_ERR("discoverTargets: restrictEXunits failed");
            break;
        }
#endif

        // call invokePresentByAssoc() to obtain functional MCS's, MEMBUFs, and
        // DIMM's, call algorithm function presentByAssoc() to determine
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


errlHndl_t restrictEXunits(
    std::vector <procRestrict_t> &i_procList,
    const bool i_present,
    const uint32_t i_deconfigReason)
{
    HWAS_INF("restrictEXunits entry, %d elements", i_procList.size());
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
        uint32_t maxEXs = i_procList[procIdx].maxEXs;

        // this procs number, used to determine groupings
        uint32_t thisGroup = i_procList[procIdx].group;

        HWAS_INF("procRestrictList[%d] - maxEXs %d, procs %d, group %d",
                procIdx, maxEXs, procs, thisGroup);

        // exs and iters for each proc in this vpd set
        TargetHandleList pEXList[procs];
        TargetHandleList::const_iterator pEX_it[procs];

        // find the proc's that we think are in this group
        uint32_t currentEXs = 0;
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

                // keep local count of current functional EX units
                currentEXs += pEXList[i].size();

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
        } // for

        if (currentEXs <= maxEXs)
        {
            // we don't need to restrict - we're done with this group.
            HWAS_DBG("currentEXs %d <= maxEXs %d -- done",
                    currentEXs, maxEXs);
            continue;
        }

        HWAS_DBG("currentEXs %d > maxEXs %d -- restricting!",
                currentEXs, maxEXs);

        // now need to find EX units that stay function, going
        //  across the list of units for each proc we have, until
        //  we get to the max or run out of EXs.
        uint8_t procs_remaining = procs;
        uint32_t goodEXs = 0;
        HWAS_DBG("procs %d maxEXs %d", procs, maxEXs);
        do
        {
            // now cycle thru the procs, stopping when we either hit
            //  the end, or when we hit our maxEXs limit
            for (uint32_t i = 0;(i < procs) && (goodEXs < maxEXs);i++)
            {
                // if we have EX units still to process
                //  from this processor
                if (pEX_it[i] != pEXList[i].end())
                {
                    // got a functional EX
                    goodEXs++;
                    HWAS_DBG("pEX   %.8X - is good %d!",
                        (*(pEX_it[i]))->getAttr<ATTR_HUID>(), goodEXs);

                    (pEX_it[i])++; // next ex/core in this proc's list

                    // check to see if we just hit the end of the list
                    if (pEX_it[i] == pEXList[i].end())
                    {
                        procs_remaining--;
                        continue;
                    }
                }
            } // for
        }
        while ((goodEXs < maxEXs) && (procs_remaining != 0));

        // now mark the rest of the EXs as non-functional
        for (uint32_t i = 0;i < procs;i++)
        {
            // walk thru the rest of the EX list
            while (pEX_it[i] != pEXList[i].end())
            {
                TargetHandle_t l_pEX = *(pEX_it[i]);
                enableHwasState(l_pEX, i_present, false, i_deconfigReason);
                HWAS_INF("pEX   %.8X - marked %spresent, NOT functional",
                        l_pEX->getAttr<ATTR_HUID>(),
                        i_present ? "" : "NOT ");

                // now need to mark the child CORE
                TargetHandleList pCoreList;
                getChildChiplets(pCoreList, l_pEX, TYPE_CORE, true);
                enableHwasState(pCoreList[0], i_present, false,
                        i_deconfigReason);
                HWAS_INF("pCore %.8X - marked %spresent, NOT functional",
                        l_pEX->getAttr<ATTR_HUID>(),
                        i_present ? "" : "NOT ");
                (pEX_it[i])++; // next ex/core in this proc's list
            }
        } // for making remaining non-functional
    } // for procIdx < l_ProcCount

    if (errl)
    {
        HWAS_INF("restrictEXunits failed (plid 0x%X)", errl->plid());
    }
    else
    {
        HWAS_INF("restrictEXunits completed successfully");
    }
    return errl;
} // restrictEXunits

errlHndl_t checkMinimumHardware(const TARGETING::ConstTargetHandle_t i_node)
{
    errlHndl_t l_errl = NULL;
    HWAS_INF("checkMinimumHardware entry");
    uint32_t l_commonPlid = 0;

    do
    {
        //*********************************************************************/
        //  Common present and functional hardware checks.
        //*********************************************************************/

        PredicateHwas l_present;
        l_present.present(true);
        PredicateIsFunctional l_functional;

        // top 'starting' point - use first node if no i_node given (hostboot)
        Target *pTop;
        if (i_node == NULL)
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

            HWAS_INF("checkMinimumHardware: i_node = NULL, using %.8X",
                    get_huid(pTop));
        }
        else
        {
            pTop = const_cast<Target *>(i_node);
            HWAS_INF("checkMinimumHardware: i_node %.8X",
                    get_huid(pTop));
        }

        // check for functional Master Proc on this node
        Target* l_pMasterProc = NULL;
        targetService().queryMasterProcChipTargetHandle(l_pMasterProc, pTop);

        if ((l_pMasterProc == NULL) || (!l_functional(l_pMasterProc)))
        {
            HWAS_ERR("Insufficient HW to continue IPL: (no master proc)");

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
            // check for at least 1 functional ex/core on Master Proc
            TargetHandleList l_cores;
            getChildChiplets(l_cores, l_pMasterProc, TYPE_EX, true);
            HWAS_DBG( "checkMinimumHardware: %d functional cores",
                      l_cores.size() );

            if (l_cores.empty())
            {
                HWAS_ERR("Insufficient HW to continue IPL: (no func cores)");

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

#ifndef CONFIG_DJVPD_READ_FROM_HW
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

        if (l_dimms.empty())
        {
            HWAS_ERR( "Insufficient hardware to continue IPL (func DIMM)");

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

        // check for functional membufs
        PredicateCTM l_membuf(CLASS_CHIP, TYPE_MEMBUF);

        TargetHandleList l_funcMembufTargetList;
        PredicatePostfixExpr l_checkExprFunctionalMembufs;
        l_checkExprFunctionalMembufs.push(&l_membuf).push(&l_functional).And();
        targetService().getAssociated( l_funcMembufTargetList, pTop,
                TargetService::CHILD, TargetService::ALL,
                &l_checkExprFunctionalMembufs);

        HWAS_DBG( "checkMinimumHardware: %d functional membufs",
            l_funcMembufTargetList.size());

        if (l_funcMembufTargetList.empty())
        {
             HWAS_ERR( "Insufficient hardware to continue IPL (func membufs)");

             TargetHandleList l_presentMembufTargetList;
             PredicatePostfixExpr l_checkExprPresentMembufs;
             l_checkExprPresentMembufs.push(&l_membuf).push(&l_present).And();
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

#endif // CONFIG_DJVPD_READ_FROM_HW

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
        platCheckMinimumHardware(l_commonPlid, i_node);
    }
    while (0);

    //  ---------------------------------------------------------------
    // if the common plid got set anywhere above, we have an error.
    //  ---------------------------------------------------------------
    if (l_commonPlid)
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
            (l_errl == NULL) ? "available" : "NOT available");
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

    for (TargetHandleList::iterator pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t l_childTarget = *pChild_it;
        enableHwasState(l_childTarget, true, false, i_targInfo.reason);
        HWAS_INF("deconfigPresentByAssoc: Target %.8X mark as present"
                 ", not functional due to non-functional parent"
                 " Centaur",
                 l_childTarget->getAttr<ATTR_HUID>() );
    }

    // find all CHILD_BY_AFFINITY matches for this target and deconfigure them
    getChildAffinityTargets(pChildList, i_targInfo.pThisTarget,
                            CLASS_NA ,TYPE_NA);

    for (TargetHandleList::iterator pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t l_affinityTarget = *pChild_it;
        enableHwasState(l_affinityTarget,true,false, i_targInfo.reason);
        HWAS_INF("deconfigPresentByAssoc: Target %.8X mark as present"
                 ", not functional due to non-functional parent"
                 " Centaur",
                 l_affinityTarget->getAttr<ATTR_HUID>() );
    }

    // deconfigure the target itself
    enableHwasState(i_targInfo.pThisTarget,true,false,i_targInfo.reason);
    HWAS_INF("deconfigPresentByAssoc: Target %.8X mark as present, not functional",
              i_targInfo.huid );

}

void invokePresentByAssoc()
{
    HWAS_INF("invokePresentByAssoc enter");

    // make one list
    TargetHandleList l_funcTargetList;

    // get the mcss
    TargetHandleList l_funcMCSTargetList;
    getAllChiplets(l_funcMCSTargetList, TYPE_MCS, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcMCSTargetList.begin(),
                               l_funcMCSTargetList.end());

    // get the membufs
    TargetHandleList l_funcMembufTargetList;
    getAllChips(l_funcMembufTargetList, TYPE_MEMBUF, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcMembufTargetList.begin(),
                               l_funcMembufTargetList.end());

    // get the dimms
    TargetHandleList l_funcDIMMTargetList;
    getAllLogicalCards(l_funcDIMMTargetList, TYPE_DIMM, true );
    l_funcTargetList.insert(l_funcTargetList.begin(),
                               l_funcDIMMTargetList.begin(),
                               l_funcDIMMTargetList.end());

    // Define vectors of TargetInfo structs to be used in presentByAssoc
    TargetInfoVector l_targInfo;
    TargetInfoVector l_targToDeconfig;
    do
    {
        // Iterate through targets and populate l_targInfo vector
        for (TargetHandleList::const_iterator
             l_targIter = l_funcTargetList.begin();
             l_targIter != l_funcTargetList.end();
             ++l_targIter)
        {
            TargetInfo l_TargetInfo;
            l_TargetInfo.pThisTarget =
                    *l_targIter;
            l_TargetInfo.affinityPath =
                    (*l_targIter)->getAttr<ATTR_AFFINITY_PATH>();
            l_TargetInfo.huid =
                    (*l_targIter)->getAttr<ATTR_HUID>();
            l_TargetInfo.type =
                    (*l_targIter)->getAttr<ATTR_TYPE>();
            l_TargetInfo.functional = true;
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

    } while(0);
}

void presentByAssoc(TargetInfoVector& o_funcTargets,
                    TargetInfoVector& o_targToDeconfig)
{
    HWAS_INF("presentByAssoc entry");

    // Sort entire vector by affinity path. This provides the algorithm with
    // an ordered vector of targets, making it easy to check if a MCS has a
    // MEMBUF, a MEMBUF has a MCS and DIMM, and a DIMM has a MEMBUF.
    std::sort(o_funcTargets.begin(), o_funcTargets.end(),
              compareAffinity);

    // Keep track of the most recently seen MCS and MEMBUF. This allows the
    // algorithm to quickly check if targets share a MCS or MEMBUF and used
    // for backtracking after deleting a target from the vector
    size_t l_MCSIndex = __INT_MAX__;
    size_t l_MEMBUFIndex = __INT_MAX__;
    size_t i = 0;

    // Perform presentByAssoc algorithm
    while ( i < o_funcTargets.size() )
    {
        // INIT STEPS:
        // Reset iterator, check functional state, check if the next taget in
        // the vector is valid or even needed

        // Get iterator to erase elements from vector when needed
        std::vector<TargetInfo>::iterator it = o_funcTargets.begin();
        std::advance(it,i);

        // If target is already marked non-functional, delete from vector and
        // move on.
        TargetInfo& l_curTargetInfo = *it;
        if (!l_curTargetInfo.functional)
        {
            o_funcTargets.erase(it);
            continue;
        }

        // Check if there is a next target and set it
        // Don't need to check next target with a DIMM
        TargetInfo* l_nextTargetInfo = NULL;
        if ( (i + 1) < o_funcTargets.size() &&
             l_curTargetInfo.type != TYPE_DIMM )
        {
            l_nextTargetInfo = &(*(it + 1));
        }

        // CASE MCS
        if ( l_curTargetInfo.type == TYPE_MCS )
        {
            // No Child MEMBUFs
            // If next is not a MEMBUF sharing the same MCS, deconfig MCS
            if ( l_nextTargetInfo == NULL ||
                 l_nextTargetInfo->type != TYPE_MEMBUF ||
                 !isSameSubPath(l_curTargetInfo, *l_nextTargetInfo) )
            {
                // Disable MCS - NO_CHILD_MEMBUF
                l_curTargetInfo.reason =
                        HWAS::DeconfigGard::DECONFIGURED_BY_NO_CHILD_MEMBUF;

                // Add target to Deconfig vector to be deconfigured later
                o_targToDeconfig.push_back(l_curTargetInfo);
                // Remove target from funcTargets
                o_funcTargets.erase(it);
            }
            // Update MCS Index
            else
            {
                l_MCSIndex = i;
                i++;
            }
        }

        // CASE MEMBUF
        else if ( l_curTargetInfo.type == TYPE_MEMBUF )
        {
            // No Child DIMMs
            // If next is not a DIMM sharing the same MEMBUF, deconfig MEMBUF
            if ( l_nextTargetInfo == NULL ||
                 l_nextTargetInfo->type != TYPE_DIMM ||
                 !isSameSubPath(l_curTargetInfo, *l_nextTargetInfo) )
            {
                // Disable MEMBUF - NO_CHILD_DIMM
                l_curTargetInfo.reason =
                        HWAS::DeconfigGard::DECONFIGURED_BY_NO_CHILD_DIMM;
            }
            // No Parent MCS
            // If MEMBUF doesn't share the same MCS as MCSIndex, deconfig MEMBUF
            else if ( l_MCSIndex == __INT_MAX__ ||
                    !isSameSubPath(l_curTargetInfo, o_funcTargets[l_MCSIndex]))
            {
                // Disable MEMBUF - NO_PARENT_MCS
                l_curTargetInfo.reason =
                        HWAS::DeconfigGard::DECONFIGURED_BY_NO_PARENT_MCS;
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
            o_funcTargets.erase(it);

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
        }

        // CASE DIMM
        else if ( l_curTargetInfo.type == TYPE_DIMM )
        {
            // No Parent MEMBUF
            // If DIMM does not share the same MEMBUF as MEMBUFIndex,
            // deconfig DIMM
            if ( l_MEMBUFIndex == __INT_MAX__ ||
                 !isSameSubPath(l_curTargetInfo, o_funcTargets[l_MEMBUFIndex]))
            {
                // Disable DIMM
                l_curTargetInfo.reason =
                        HWAS::DeconfigGard::DECONFIGURED_BY_NO_PARENT_MEMBUF;

                // Add target to deconfig vector to be deconfigured later
                o_targToDeconfig.push_back(l_curTargetInfo);
                // Remove target from funcTargets
                o_funcTargets.erase(it);

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
            }
            else
            {
                i++;
            }
        }
    } // presentByAssoc algorithm
}

};   // end namespace

