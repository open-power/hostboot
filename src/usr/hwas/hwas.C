//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwas/hwas.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

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
#include    <stdint.h>
#include    <assert.h>

#include    <targeting/common/commontargeting.H>

#include    <hwas/hwas.H>
#include    <hwas/hwasCommon.H>

namespace   HWAS
{

using   namespace   TARGETING;


/**
 * @brief       simple helper fn to get and set hwas state to poweredOn,
 *                  present, functional
 *
 * @param[in]   i_target    pointer to target that we're looking at
 *
 * @return      none
 *
 */
void enableHwasState(Target *i_target)
{
    HwasState hwasState     = i_target->getAttr<ATTR_HWAS_STATE>();
    hwasState.poweredOn     = true;
    hwasState.present       = true;
    hwasState.functional    = true;
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
        hwasState.gardLevel             = 0;
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

        assert(pSys, "HWAS discoverTargets: no CLASS_SYS TopLevelTarget found");

        // mark this as present
        enableHwasState(pSys);
        HWAS_DBG("pSys   %x (%p) %x/%x - marked present",
            pSys->getAttr<ATTR_HUID>(), pSys,
            pSys->getAttr<ATTR_CLASS>(), pSys->getAttr<ATTR_TYPE>());

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
            enableHwasState(pEnc);
            HWAS_DBG("pEnc   %x (%p) %x/%x - marked present",
                pEnc->getAttr<ATTR_HUID>(), pEnc,
                pEnc->getAttr<ATTR_CLASS>(), pEnc->getAttr<ATTR_TYPE>());
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
        // for each, mark them and their descendants as present
        for (TargetHandleList::iterator pTarget_it = pCheckPres.begin();
                pTarget_it != pCheckPres.end();
            ) // increment will be done in the loop below
        {
            TargetHandle_t pTarget = *pTarget_it;

            // set HWAS state to show it's present
            enableHwasState(pTarget);
            HWAS_DBG("pTarget %x (%p) %x/%x - detected present",
                pTarget->getAttr<ATTR_HUID>(), pTarget,
                pTarget->getAttr<ATTR_CLASS>(),
                pTarget->getAttr<ATTR_TYPE>());

            // now need to mark all of this target's
            //  physical descendants as present
            TargetHandleList pDescList;
            targetService().getAssociated( pDescList, pTarget,
                TargetService::CHILD, TargetService::ALL);
            for (TargetHandleList::iterator pDesc_it = pDescList.begin();
                    pDesc_it != pDescList.end();
                    pDesc_it++)
            {
                TargetHandle_t pDesc = *pDesc_it;
                enableHwasState(pDesc);
                HWAS_DBG("pDesc %x (%p) %x/%x - marked present",
                    pDesc->getAttr<ATTR_HUID>(), pDesc,
                    pDesc->getAttr<ATTR_CLASS>(),
                    pDesc->getAttr<ATTR_TYPE>());
            }

            // if we're not a CHIP, remove us from the list, so that
            //  when we do the Chip ID/EC call after the loop, we have
            //  a list that is CHIPs only
            if (pTarget->getAttr<ATTR_CLASS>() != CLASS_CHIP)
            {
                // erase this target, and 'increment' to next
                pTarget_it = pCheckPres.erase(pTarget_it);
            }
            else
            {
                // advance to next entry in the list
                pTarget_it++;
            }
        } // for pTarget_it

        // at this point, pCheckPres only has present CLASS_CHIP targets
        // read Chip ID/EC data from these physical chips
        HWAS_DBG("pCheckPres size: %d", pCheckPres.size());
        errl = platReadIDEC(pCheckPres);

        if (errl != NULL)
        {
            break; // break out of the do/while so that we can return
        }

    } while (0);

    if (errl != NULL)
    {
        HWAS_ERR("discoverTargets returning errl %p", errl);
    }
    else
    {
        HWAS_INF("discoverTargets exit with no error");
    }
    return errl;
} // discoverTargets

};   // end namespace

