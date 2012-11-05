/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/hwas.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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

/**
 * @brief       simple helper fn to get and set hwas state to poweredOn,
 *                  present, functional
 *
 * @param[in]   i_target    pointer to target that we're looking at
 * @param[in]   i_present   boolean indicating present or not
 * @param[in]   i_functional boolean indicating functional or not
 *
 * @return      none
 *
 */
void enableHwasState(Target *i_target, bool i_present, bool i_functional)
{
    HwasState hwasState     = i_target->getAttr<ATTR_HWAS_STATE>();
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
        hwasState.poweredOn             = false;
        hwasState.present               = false;
        hwasState.functional            = false;
        hwasState.changedSinceLastIPL   = false;
        target->setAttr<ATTR_HWAS_STATE>(hwasState);
    }

    // ASSUMPTIONS:
    // CLASS_SYS (exactly 1) - mark as present
    // CLASS_ENC (>=1) - mark as present
    // TYPE_PROC TYPE_MEMBUF TYPE_DIMM (ALL require hardware query)
    //                                  - call platPresenceDetect
    //  \->children: CLASS_* (NONE require hardware query) - mark as present

    do
    {
        // find CLASS_SYS (the top level target)
        Target* pSys;
        targetService().getTopLevelTarget(pSys);

        HWAS_ASSERT(pSys,
                "HWAS discoverTargets: no CLASS_SYS TopLevelTarget found");

        // mark this as present
        enableHwasState(pSys, true, true);
        HWAS_DBG("pSys %.8X - marked present",
            pSys->getAttr<ATTR_HUID>());

        // find CLASS_ENC
        PredicateCTM predEnc(CLASS_ENC);
        TargetHandleList pEncList;
        targetService().getAssociated( pEncList, pSys,
            TargetService::CHILD, TargetService::ALL, &predEnc );

        for (TargetHandleList::iterator pEnc_it = pEncList.begin();
                pEnc_it != pEncList.end();
                pEnc_it++)
        {
            TargetHandle_t pEnc = *pEnc_it;

            // mark it as present
            enableHwasState(pEnc, true, true);
            HWAS_DBG("pEnc %.8X - marked present",
                pEnc->getAttr<ATTR_HUID>());
        } // for pEnc_it

        PredicateCTM predChip(CLASS_CHIP);
        PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predChip).push(&predDimm).Or();

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

        // no errors - keep going
        // for each, read their ID/EC level. if that works,
        //  mark them and their descendants as present
        //  read the partialGood vector to determine if any are not functional

        for (TargetHandleList::iterator pTarget_it = pCheckPres.begin();
                pTarget_it != pCheckPres.end();
                pTarget_it++
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            bool chipFunctional = true;
            bool chipPresent = true;
            uint16_t pgData[VPD_CP00_PG_DATA_LENGTH / sizeof(uint16_t)];
            bzero(pgData, sizeof(pgData));
            if (pTarget->getAttr<ATTR_CLASS>() == CLASS_CHIP)
            {
                // read Chip ID/EC data from these physical chips
                errl = platReadIDEC(pTarget);

                if (errl)
                {   // read of ID/EC failed even tho we were present..
                    HWAS_INF("pTarget %.8X - read IDEC failed - bad",
                        pTarget->getAttr<ATTR_HUID>());
                    chipFunctional = false;

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
                        HWAS_INF("pTarget %.8X - read PG failed - bad",
                            pTarget->getAttr<ATTR_HUID>());
                        chipFunctional = false;

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
                        HWAS_INF("pTarget %.8X - PIB "
                                    "pgPdata[%d]: expected 0x%04X - bad",
                            pTarget->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_PIB_INDEX,
                            VPD_CP00_PG_PIB_GOOD);
                        chipFunctional = false;
                    }
                    else
                    if (pgData[VPD_CP00_PG_PERVASIVE_INDEX] !=
                                    VPD_CP00_PG_PERVASIVE_GOOD)
                    {
                        HWAS_INF("pTarget %.8X - Pervasive "
                                    "pgPdata[%d]: expected 0x%04X - bad",
                            pTarget->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_PERVASIVE_INDEX,
                            VPD_CP00_PG_PERVASIVE_GOOD);
                        chipFunctional = false;
                    }
                    else
                    if (pgData[VPD_CP00_PG_POWERBUS_INDEX] !=
                                    VPD_CP00_PG_POWERBUS_GOOD)
                    {
                        HWAS_INF("pTarget %.8X - PowerBus "
                                    "pgPdata[%d]: expected 0x%04X - bad",
                            pTarget->getAttr<ATTR_HUID>(),
                            VPD_CP00_PG_POWERBUS_INDEX,
                            VPD_CP00_PG_POWERBUS_GOOD);
                        chipFunctional = false;
                    }
                } // TYPE_PROC
            } // CLASS_CHIP

            // TODO: Story 35077 - add PR processing. roughly:
            //  totalcores = readPR();
            //  for each child ex in chip c
            //      if goodcores < totalcores
            //          if ex->functional==true
            //              goodcores++
            //      else
            //          ex->functional = false

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
                    pDesc_it++)
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
                        HWAS_INF("pDesc %.8X - XBUS  "
                                    "pgPdata[%d]: expected 0x%04X - bad",
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
                        HWAS_INF("pDesc %.8X - ABUS "
                                    "pgPdata[%d]: expected 0x%04X - bad",
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
                        HWAS_INF("pDesc %.8X - PCIe "
                                    "pgPdata[%d]: expected 0x%04X - bad",
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
                        HWAS_INF("pDesc %.8X - CORE/EX%d "
                                    "pgPdata[%d]: expected 0x%04X - bad",
                            pDesc->getAttr<ATTR_HUID>(), indexEX,
                            VPD_CP00_PG_EX0_INDEX + indexEX,
                            VPD_CP00_PG_EX0_GOOD);
                        descFunctional = false;
                      }
                    }
                } // chipFunctional

                // for sub-parts, if it's not functional, it's not present.
                enableHwasState(pDesc, descFunctional, descFunctional);
                HWAS_DBG("pDesc %.8X - marked %spresent, %sfunctional",
                    pDesc->getAttr<ATTR_HUID>(),
                    descFunctional ? "" : "NOT ",
                    descFunctional ? "" : "NOT ");
            }

            // set HWAS state to show CHIP is present, functional per above
            enableHwasState(pTarget, chipPresent, chipFunctional);

        } // for pTarget_it

    } while (0);

    if (errl == NULL)
    {
        HWAS_INF("discoverTargets exit with no error");
    }
    else
    {
        HWAS_ERR("discoverTargets returning errl %p", errl);
    }
    return errl;
} // discoverTargets

};   // end namespace

