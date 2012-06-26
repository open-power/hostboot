/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwas/common/hwas.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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

TRAC_INIT(&g_trac_dbg_hwas, "HWAS",     1024 );
TRAC_INIT(&g_trac_imp_hwas, "HWAS_I",   1024 );

/**
 * @brief       simple helper fn to get and set hwas state to poweredOn,
 *                  present, functional
 *
 * @param[in]   i_target    pointer to target that we're looking at
 *
 * @return      none
 *
 */
void enableHwasState(Target *i_target, bool i_functional)
{
    HwasState hwasState     = i_target->getAttr<ATTR_HWAS_STATE>();
    hwasState.poweredOn     = true;
    hwasState.present       = true;
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

        HWAS_ASSERT(pSys, "HWAS discoverTargets: no CLASS_SYS TopLevelTarget found");

        // mark this as present
        enableHwasState(pSys, true);
        HWAS_DBG("pSys %.8X (%p) - marked present",
            pSys->getAttr<ATTR_HUID>(), pSys);

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
            enableHwasState(pEnc, true);
            HWAS_DBG("pEnc %.8X (%p) - marked present",
                pEnc->getAttr<ATTR_HUID>(), pEnc);
        } // for pEnc_it

        // find TYPE_PROC, TYPE_MEMBUF and TYPE_DIMM
        PredicateCTM predProc(CLASS_CHIP, TYPE_PROC);
        PredicateCTM predMembuf(CLASS_CHIP, TYPE_MEMBUF);
        PredicateCTM predDimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predProc).push(&predMembuf).Or().push(&predDimm).Or();

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
        //  mark them and their descendants as present and functional
        for (TargetHandleList::iterator pTarget_it = pCheckPres.begin();
                pTarget_it != pCheckPres.end();
                pTarget_it++
            )
        {
            TargetHandle_t pTarget = *pTarget_it;

            // read Chip ID/EC data from these physical chips
            if (pTarget->getAttr<ATTR_CLASS>() == CLASS_CHIP)
            {
                errl = platReadIDEC(pTarget);
            }

            bool isFunctional;
            if (!errl)
            {   // no error
                isFunctional = true;
            }
            else
            {   // read of ID/EC failed even tho we were present..
                isFunctional = false;

                // commit the error but keep going
                errlCommit(errl, HWAS_COMP_ID);
                // errl is now NULL
            }

            HWAS_DBG("pTarget %.8X (%p) - detected present %s functional",
                pTarget->getAttr<ATTR_HUID>(), pTarget,
                isFunctional ? "and" : "NOT");

            // set HWAS state to show it's present
            enableHwasState(pTarget, isFunctional);

            // now need to mark all of this target's
            //  physical descendants as present and NOT functional
            TargetHandleList pDescList;
            targetService().getAssociated( pDescList, pTarget,
                TargetService::CHILD, TargetService::ALL);
            for (TargetHandleList::iterator pDesc_it = pDescList.begin();
                    pDesc_it != pDescList.end();
                    pDesc_it++)
            {
                TargetHandle_t pDesc = *pDesc_it;
                enableHwasState(pDesc, isFunctional);
                HWAS_DBG("pDesc %.8X (%p) - marked present %s functional",
                    pDesc->getAttr<ATTR_HUID>(), pDesc,
                    isFunctional ? "and" : "NOT");
            }
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

