/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/hwas.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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

#include <targeting/common/commontargeting.H>

#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/hwasError.H>

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

// structure used to store proc information for PR keyword processing
typedef struct {
    TargetHandle_t target;
    ATTR_FRU_ID_type fruid;
    uint8_t avgNum;
    uint8_t vpdCopies;
} procPR_t;

// SORT functions that we'll use for PR keyword processing
bool compareTargetHUID(TargetHandle_t t1, TargetHandle_t t2)
{
    return (t1->getAttr<ATTR_HUID>() < t2->getAttr<ATTR_HUID>());
}
bool compareProcFRUID(procPR_t t1, procPR_t t2)
{
    return (t1.fruid < t2.fruid);
}

/**
 * @brief       simple helper fn to get and set hwas state to poweredOn,
 *                  present, functional
 *
 * @param[in]   i_target        pointer to target that we're looking at
 * @param[in]   i_present       boolean indicating present or not
 * @param[in]   i_functional    boolean indicating functional or not
 * @param[in]   i_errlPlid      errplid that caused change to non-funcational;
 *                              0 if not associated with an error or if
 *                              functional is true
 *
 * @return      none
 *
 */
void enableHwasState(Target *i_target,
        bool i_present, bool i_functional,
        uint32_t i_errlPlid)
{
    HwasState hwasState = i_target->getAttr<ATTR_HWAS_STATE>();

    if (i_functional == false)
    {   // record the PLID as a reason that we're marking non-functional
        hwasState.deconfiguredByPlid = i_errlPlid;
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
        hwasState.deconfiguredByPlid    = 0;
        hwasState.poweredOn             = false;
        hwasState.present               = false;
        hwasState.functional            = false;
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
        procPR_t l_procEntry;
        std::vector <procPR_t> l_procPRList;

        for (TargetHandleList::iterator pTarget_it = pCheckPres.begin();
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
            uint32_t errlPlid = 0;
            uint16_t pgData[VPD_CP00_PG_DATA_LENGTH / sizeof(uint16_t)];
            bzero(pgData, sizeof(pgData));

            if (pTarget->getAttr<ATTR_CLASS>() == CLASS_CHIP)
            {
                // read Chip ID/EC data from these physical chips
                errl = platReadIDEC(pTarget);

                if (errl)
                {   // read of ID/EC failed even tho we were present..
                    HWAS_INF("pTarget %.8X - read IDEC failed (plid 0x%X) - bad",
                        errl->plid(), pTarget->getAttr<ATTR_HUID>());
                    chipFunctional = false;
                    errlPlid = errl->plid();

                    // commit the error but keep going
                    errlCommit(errl, HWAS_COMP_ID);
                    // errl is now NULL
                }
                if (pTarget->getAttr<ATTR_TYPE>() == TYPE_PROC)
                {
                    // read partialGood vector from these as well.
                    errl = platReadPartialGood(pTarget, pgData);

                    if (errl)
                    {   // read of PG failed even tho we were present..
                        HWAS_INF("pTarget %.8X - read PG failed (plid 0x%X)- bad",
                            errl->plid(), pTarget->getAttr<ATTR_HUID>());
                        chipFunctional = false;
                        errlPlid = errl->plid();

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
                            errlPlid = errl->plid();

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
                            l_procEntry.fruid = pTarget->getAttr<ATTR_FRU_ID>();
                            l_procEntry.avgNum =
                                        (prData[2] & VPD_VINI_PR_B2_MASK)
                                            >> VPD_VINI_PR_B2_SHIFT;
                            l_procEntry.vpdCopies =
                                        (prData[7] & VPD_VINI_PR_B7_MASK) + 1;
                            l_procPRList.push_back(l_procEntry);
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
            for (TargetHandleList::iterator pDesc_it = pDescList.begin();
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
                                errlPlid);
                HWAS_DBG("pDesc %.8X - marked %spresent, %sfunctional",
                    pDesc->getAttr<ATTR_HUID>(),
                    descFunctional ? "" : "NOT ",
                    descFunctional ? "" : "NOT ");
            }

            // set HWAS state to show CHIP is present, functional per above
            enableHwasState(pTarget, chipPresent, chipFunctional, errlPlid);

        } // for pTarget_it

        // PR keyword processing - potentially reduce the number of ex/core
        //  units that are functional based on what's in the PR keyword.

        // predicate to find present EX units
        PredicateCTM predEX(CLASS_UNIT, TYPE_EX);
        PredicateHwas predPresent;
        predPresent.present(true);
        PredicatePostfixExpr exCheckExpr;
        exCheckExpr.push(&predEX).push(&predPresent).And();

        // predicate to find CORE units
        PredicateCTM predCore(CLASS_UNIT, TYPE_CORE);
        PredicatePostfixExpr coreCheckExpr;
        coreCheckExpr.push(&predCore);

        // sort by ATTR_FRU_ID so PROC# are in the right groupings.
        std::sort(l_procPRList.begin(), l_procPRList.end(),
                    compareProcFRUID);

        // AFTER all targets have been tested, loop thru procs to handle PR
        const uint32_t l_PRProcCount = l_procPRList.size();
        for (uint32_t procIdx = 0;
                procIdx < l_PRProcCount;
                // the increment will happen in the loop to handle
                //  PR records covering more than 1 proc target
            )
        {
            // determine the number of procs we should enable
            uint8_t avgNum = l_procPRList[procIdx].avgNum;
            uint8_t vpdCopies = l_procPRList[procIdx].vpdCopies;

            // this procs FRU_ID, used to determine groupings
            ATTR_FRU_ID_type thisFruId = l_procPRList[procIdx].fruid;

            HWAS_INF("procPRList[%d] - PR avg units %d, VPDs %d, FRU_ID %d",
                    procIdx, avgNum, vpdCopies, thisFruId);

            // exs and iters for each proc in this vpd set
            TargetHandleList pEXList[vpdCopies];
            TargetHandleList::iterator pEX_it[vpdCopies];

            // find the proc's that we think are in this group
            for (uint32_t i = 0; i < vpdCopies; i++)
            {
                TargetHandle_t pProc = l_procPRList[procIdx].target;

                // if this proc is past the last of the proc count
                //  OR is NOT in the same FRU_ID
                if ((procIdx >= l_PRProcCount) ||
                    (thisFruId != pProc->getAttr<ATTR_FRU_ID>()))
                {
                    HWAS_DBG("procPRList[%d] - not in FRU_ID %d group",
                            i, thisFruId);

                    // change this to be how many we actually have here
                    vpdCopies = i;

                    // we're done - break so that we use procIdx as the
                    //  start index next time
                    break;
                }

                // get this proc's (CHILD) present EX units
                targetService().getAssociated( pEXList[i], pProc,
                        TargetService::CHILD, TargetService::ALL, &exCheckExpr);

                // sort the list by ATTR_HUID to ensure that we
                //  start at the same place each time
                std::sort(pEXList[i].begin(), pEXList[i].end(),
                            compareTargetHUID);

                // keep a pointer into that list
                pEX_it[i] = pEXList[i].begin();

                // advance the outer loop as well since we're doing these
                //  procs together
                ++procIdx;
            } // for
            HWAS_DBG("procIdx %d, vpdCopies %d", procIdx, vpdCopies);

            // now need to find EX units that stay function, going
            //  across the list of units for each proc we have, until
            //  we get to the max or run out of EXs.
            uint8_t procs_remaining = vpdCopies;
            uint32_t maxEXs = avgNum * vpdCopies;
            uint32_t goodEXs = 0;
            do
            {
                // now cycle thru the procs
                for (uint32_t i = 0;i < vpdCopies;i++)
                {
                    // if we are done with this list of ex/core units
                    //  from this processor
                    if (pEX_it[i] == pEXList[i].end())
                    {
                        procs_remaining--;
                        continue;
                    }

                    // got a present EX
                    HWAS_DBG("pEX   %.8X - is good!",
                            (*(pEX_it[i]))->getAttr<ATTR_HUID>());
                    (pEX_it[i])++; // next ex/core in this proc's list
                    goodEXs++;
                } // for
            }
            while ((goodEXs < maxEXs) && (procs_remaining != 0));

            // now mark the rest of the EXs as non-present/non-functional
            for (uint32_t i = 0;i < vpdCopies;i++)
            {
                // walk thru the rest of the EX list
                while (pEX_it[i] != pEXList[i].end())
                {
                    TargetHandle_t l_pEX = *(pEX_it[i]);
                    enableHwasState(l_pEX, false, false, 0);
                    HWAS_INF("pEX   %.8X - marked NOT present, NOT functional (PR)",
                            l_pEX->getAttr<ATTR_HUID>());

                    // now need to mark the child CORE
                    TargetHandleList pCoreList;
                    targetService().getAssociated(
                        pCoreList, l_pEX,
                        TargetService::CHILD, TargetService::ALL,
                        &coreCheckExpr );
                    enableHwasState(pCoreList[0], false, false, 0);
                    HWAS_INF("pCore %.8X - marked NOT present, NOT functional (PR)",
                            pCoreList[0]->getAttr<ATTR_HUID>());
                    (pEX_it[i])++; // next ex/core in this proc's list
                }
            } // for making remaining non-present/non-functional
        } // for procIdx < l_PRProcCount

    } while (0);

    HWAS_INF("discoverTargets returning errl %p", errl);
    return errl;
} // discoverTargets

};   // end namespace

