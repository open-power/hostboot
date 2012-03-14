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

#include    <targeting/targetservice.H>
#include    <targeting/iterators/rangefilter.H>
#include    <targeting/predicates/predicates.H>
#include    <targeting/util.H>

#include    <hwas/hwas.H>
#include    <hwas/hwasCommon.H>

namespace   HWAS
{

using   namespace   TARGETING;


//@todo - This should come from the target/attribute code somewhere
uint64_t target_to_uint64(const Target* i_target)
{
    uint64_t id = 0;
    if (i_target == NULL)
    {
        id = 0x0;
    }
    else if (i_target == MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        id = 0xFFFFFFFFFFFFFFFF;
    }
    else
    {
        // physical path, 3 nibbles per type/instance pair
        //   TIITIITII... etc.
        EntityPath epath;
        i_target->tryGetAttr<ATTR_PHYS_PATH>(epath);
        for (uint32_t x = 0; x < epath.size(); x++)
        {
            id = id << 12;
            id |= (uint64_t)((epath[x].type << 8) & 0xF00);
            id |= (uint64_t)(epath[x].instance & 0x0FF);
        }
    }
    return id;
}


/**
 * @brief       simple helper function to get and set hwas to clear state
 *
 * @param[in]   i_target    pointer to target that we're looking at
 *
 * @return      none
 */
void clearHwasState(Target * i_target)
{
    HwasState hwasState             = i_target->getAttr<ATTR_HWAS_STATE>();
    hwasState.poweredOn             = false;
    hwasState.present               = false;
    hwasState.functional            = false;
    hwasState.changedSinceLastIPL   = false;
    hwasState.gardLevel             = 0;
    i_target->setAttr<ATTR_HWAS_STATE>(hwasState);
}

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
    HWAS_DBG("discoverTargets entry");
    errlHndl_t errl = NULL;

    //  loop through all the targets and set HWAS_STATE to a known default
    for (TargetIterator target = targetService().begin();
            target != targetService().end();
            ++target)
    {
        clearHwasState(*target);
    }

    // ASSUMPTIONS: Physical hierarchy is:
    // CLASS_SYS (exactly 1)
    //  \->children: CLASS_ENC
    //     \->children: CLASS_* where ALL require hardware query
    //        \->children: CLASS_* where NONE require hardware query

    // find CLASS_SYS (the top level target)
    Target* pSys;
    targetService().getTopLevelTarget(pSys);

    do
    {
        if (pSys == NULL)
        {
            // shouldn't happen, but if it does, then we're done - nothing present.
            HWAS_ERR("pSys NULL - nothing present");
            break; // break out of the do/while so that we can return
        }

        // mark this as present
        enableHwasState(pSys);
        HWAS_DBG("pSys   %x (%p) %x/%x - marked present",
            target_to_uint64(pSys), pSys,
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
                target_to_uint64(pEnc), pEnc,
                pEnc->getAttr<ATTR_CLASS>(), pEnc->getAttr<ATTR_TYPE>());

            // now find the physical children
            TargetHandleList pChildList;
            targetService().getAssociated(pChildList, pEnc,
                TargetService::CHILD, TargetService::IMMEDIATE);

            // pass this list of children to the hwas common api
            // pChildList will be modified to only have present targets
            HWAS_DBG("pChildList size before %d", pChildList.size());
            errl = platPresenceDetect(pChildList);
            HWAS_DBG("pChildList size after %d", pChildList.size());

            if (errl != NULL)
            {
                break; // get out of the pEnc loop
            }

            // read Chip ID/EC data from these physical chips, since they
            //  are present
            errl = platReadIDEC(pChildList);

            if (errl != NULL)
            {
                break; // get out of the pEnc loop
            }

            // no errors - keep going

            // at this point, pChildList only has present targets
            // for each, mark them and their descendants as present
            for (TargetHandleList::iterator pChild_it = pChildList.begin();
                    pChild_it != pChildList.end();
                    pChild_it++)
            {
                TargetHandle_t pChild = *pChild_it;

                // set HWAS state to show it's present
                enableHwasState(pChild);
                HWAS_DBG("pChild %x (%p) %x/%x - detected present",
                    target_to_uint64(pChild), pChild,
                    pChild->getAttr<ATTR_CLASS>(),
                    pChild->getAttr<ATTR_TYPE>());

                // now need to mark all of this target's
                //  physical descendants as present
                TargetHandleList pDescList;
                targetService().getAssociated( pDescList, pChild,
                    TargetService::CHILD, TargetService::ALL);
                for (TargetHandleList::iterator pDesc_it = pDescList.begin();
                        pDesc_it != pDescList.end();
                        pDesc_it++)
                {
                    TargetHandle_t pDesc = *pDesc_it;
                    enableHwasState(pDesc);
                    HWAS_DBG("pDsnds %x (%p) %x/%x - marked present",
                        target_to_uint64(pDesc), pDesc,
                        pDesc->getAttr<ATTR_CLASS>(),
                        pDesc->getAttr<ATTR_TYPE>());
                }
            } // for pChild_it
        } // for pEnc_it
    } while (0);

    if (errl != NULL)
    {
        HWAS_ERR("returning errl %p", errl);
    }
    return errl;
} // discoverTargets

};   // end namespace

