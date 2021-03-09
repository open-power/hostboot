/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/associationmanager.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
#ifdef __HOSTBOOT_MODULE
#include <targeting/common/associationmanager.H>
#endif
#include <targeting/targplatutil.H>
#include <targeting/common/targetservice.H>
#include <targeting/targplatreasoncodes.H>
#include <targeting/attrrp.H>

#ifdef __HOSTBOOT_MODULE
    #define TARG_PTR_TO_UINT32(ptr) (static_cast<uint32_t>((uint64_t)(ptr)))
    const size_t MAX_PARENT_LINKS_PER_ASSOC_TYPE = 1;
#endif

namespace TARGETING
{

//******************************************************************************
// AssociationManager::reconnectSyAndNodeTargets
//******************************************************************************
#ifdef __HOSTBOOT_MODULE
errlHndl_t AssociationManager::reconnectSyAndNodeTargets()
{
    #define TARG_FN "reconnectSysAndNodeTargets(...)"

    errlHndl_t pError = NULL;

    do {

    using namespace TARGETING::UTIL;

    static SysToNodeContainer sysContainer =
                                 targetService().getSysToNodeAssociations(true);

    for(SysToNodeContainerIt pSys = sysContainer.begin();
        pSys != sysContainer.end();
        ++pSys)
    {
        TARGETING::TargetService::ASSOCIATION_TYPE associationList[] =
            { TARGETING::TargetService::CHILD,
              TARGETING::TargetService::CHILD_BY_AFFINITY };

        for(size_t association = 0;
            association < sizeof(associationList)/sizeof(associationList[0]);
            ++association)
        {
            pError = _clearAssocsOfTypeFromSysOrNodeTarget(
                associationList[association],
                pSys->pSysTarget);
            if(pError)
            {
                TARG_ERR("Failed in call to "
                    "_clearAssocsOfTypeFromSysOrNodeTarget with association "
                    "type = 0x%08X, sys target HUID = 0x%08X, and "
                    "sys target address = %p",
                    associationList[association],
                    pSys->pSysTarget->getAttr<TARGETING::ATTR_HUID>(),
                    pSys->pSysTarget);
                break;
            }

            for(SysToNodeContainerIt pNode = sysContainer.begin();
                pNode != sysContainer.end();
                ++pNode)
            {
                pError = _addAssocToSysOrNodeTarget(
                    associationList[association],
                    pSys->pSysTarget,
                    pNode->pNodeTarget);
                if(pError)
                {
                    TARG_ERR("Failed in call to "
                        "_addAssocToSysOrNodeTarget with association "
                        "type = 0x%08X, source sys target HUID = 0x%08X, "
                        "source sys target address = %p, dest node target "
                        "HUID = 0x%08X, dest node target address = %p",
                        associationList[association],
                        pSys->pSysTarget->getAttr<TARGETING::ATTR_HUID>(),
                        pSys->pSysTarget,
                        pNode->pNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
                        pNode->pNodeTarget);
                    break;
                }
            }

            if(pError)
            {
                break;
            }
        }

        if(pError)
        {
            break;
        }
    }

    if(pError)
    {
        break;
    }

    Target* pMasterSysTarget = NULL;
    for(SysToNodeContainerIt pNode = sysContainer.begin();
        pNode != sysContainer.end();
        ++pNode)
    {
        if(isThisMasterNodeTarget( pNode->pNodeTarget ) )
        {
            pMasterSysTarget = pNode->pSysTarget;
            break;
        }
    }

    if(pMasterSysTarget)
    {
        for(SysToNodeContainerIt pNode = sysContainer.begin();
            pNode != sysContainer.end();
            ++pNode)
        {
            TARGETING::TargetService::ASSOCIATION_TYPE associationList[] =
                { TARGETING::TargetService::PARENT,
                  TARGETING::TargetService::PARENT_BY_AFFINITY };

            for(size_t association = 0;
                association<sizeof(associationList)/sizeof(associationList[0]);
                ++association)
            {
                pError = _clearAssocsOfTypeFromSysOrNodeTarget(
                    associationList[association],
                    pNode->pNodeTarget);
                if(pError)
                {
                    TARG_ERR("Failed in call to "
                        "_clearAssocsOfTypeFromSysOrNodeTarget with "
                        "association type = 0x%08X, node target HUID = 0x%08X, "
                        "and node target address = %p",
                        associationList[association],
                        pNode->pNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
                        pNode->pNodeTarget);
                    break;
                }

                pError = _addAssocToSysOrNodeTarget(
                    associationList[association],
                    pNode->pNodeTarget,
                    pMasterSysTarget);
                if(pError)
                {
                    TARG_ERR("Failed in call to "
                        "_addAssocToSysOrNodeTarget with association "
                        "type = 0x%08X, source node target HUID = 0x%08X, "
                        "source node target address = %p, dest sys target "
                        "HUID = 0x%08X, dest sys target address = %p",
                        associationList[association],
                        pNode->pNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
                        pNode->pNodeTarget,
                        pMasterSysTarget->getAttr<TARGETING::ATTR_HUID>(),
                        pMasterSysTarget);
                    break;
                }
            }

            if(pError)
            {
                break;
            }
        }

        if(pError)
        {
            break;
        }
    }
    else
    {
        TARG_ERR("Failed to find master system target");

        /*@
         * @errortype
         * @refcode      LIC_REFCODE
         * @subsys       EPUB_FIRMWARE_SP
         * @moduleid     TARG_MOD_RECONNECT_SYS_AND_NODE_TARGETS
         * @reasoncode   TARG_RC_TARGET_NOT_FOUND
         * @devdesc      Error: Failed to find master system target
         * @custdesc     An issue occurred during IPL of the system:
         *               Internal Firmware Error
         */
        UTIL::createTracingError(
            TARG_MOD_RECONNECT_SYS_AND_NODE_TARGETS,
            TARG_RC_TARGET_NOT_FOUND,
            0,0,0,0,
            pError);
    }

    } while(0);

    return pError;

    #undef TARG_FN
}

//******************************************************************************
// AssociationManager::_clearAssocsOfTypeFromSysOrNodeTarget
//******************************************************************************

errlHndl_t AssociationManager::_clearAssocsOfTypeFromSysOrNodeTarget(
    const TargetService::ASSOCIATION_TYPE i_assocType,
          Target* const                   i_pSysOrNodeTarget)
{
    #define TARG_FN "_clearAssocsOfTypeFromSysOrNodeTarget(...)"

    errlHndl_t pError = NULL;

    do {

    if(!i_pSysOrNodeTarget)
    {
        TARG_ASSERT(0,
            "Caller tried to clear associations from NULL target");
    }

    // Intentionally match -ANY- node type
    TARGETING::PredicateCTM isaNodeTarget(CLASS_ENC);
    TARGETING::PredicateCTM isaSysTarget(CLASS_SYS,TYPE_SYS);

    if(isaNodeTarget(i_pSysOrNodeTarget))
    {
        if (   (i_assocType != TARGETING::TargetService::PARENT)
            && (i_assocType != TARGETING::TargetService::PARENT_BY_AFFINITY))
        {
            TARG_ASSERT(0,
                "Caller specified unsupported association type / target "
                "pair when attempting to clear association links. "
                "i_assocType = 0x%08X, HUID = 0x%08X",
                i_assocType,
                i_pSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>());
        }
    }
    else if(isaSysTarget(i_pSysOrNodeTarget))
    {
        if (   (i_assocType != TARGETING::TargetService::CHILD)
            && (i_assocType != TARGETING::TargetService::CHILD_BY_AFFINITY))
        {
            TARG_ASSERT(0,
                "Caller specified unsupported association type / target "
                "pair when attempting to clear association links. "
                "i_assocType = 0x%08X, HUID = 0x%08X",
                i_assocType,
                i_pSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>());
        }
    }
    else
    {
        TARG_ASSERT(0,
            "Caller tried to clear associations from a non-system, non-node "
            "target whose HUID = 0x%08X",
            i_pSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>());
    }

    AbstractPointer<Target>* pAssocsItrPreTrans  =
        TARG_TO_PLAT_PTR(i_pSysOrNodeTarget->iv_ppAssociations[i_assocType]);

    AbstractPointer<Target>* pAssocsItr = NULL;

    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        pAssocsItr = static_cast< AbstractPointer<Target>* >(
            TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
               pAssocsItrPreTrans, i_pSysOrNodeTarget));
    }
    else
    {
        pAssocsItr = pAssocsItrPreTrans;
    }

    if(!pAssocsItr)
    {
        TARG_ERR(
            "Failed to translate common association address to platform "
            "address.  Address prior to translation = %p, "
            "target HUID = 0x%08X, target address = %p",
            pAssocsItrPreTrans,
            i_pSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
            i_pSysOrNodeTarget);
        /*@
         * @errortype
         * @refcode      LIC_REFCODE
         * @subsys       EPUB_FIRMWARE_SP
         * @moduleid     TARG_MOD_CLR_ASSOCS_FROM_SYS_OR_NODE_TARGET
         * @reasoncode   TARG_RC_FAILED_TO_XLATE_ADDR
         * @userdata1    Address prior to translation
         * @userdata2    Target's HUID
         * @userdata3    Target's address
         * @devdesc      Error: Failed to translate common association address
         *     to platform address
         * @custdesc     An issue occurred during IPL of the system:
         *               Internal Firmware Error
         */
        UTIL::createTracingError(
            TARG_MOD_CLR_ASSOCS_FROM_SYS_OR_NODE_TARGET,
            TARG_RC_FAILED_TO_XLATE_ADDR,
            TARG_PTR_TO_UINT32(pAssocsItrPreTrans),
            i_pSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
            TARG_PTR_TO_UINT32(i_pSysOrNodeTarget),
            0,
            pError);
        break;
    }

    while(static_cast<uint64_t>(*pAssocsItr))
    {
        (*pAssocsItr).raw = 0;
        ++pAssocsItr;
    }
    } while(0);

    return pError;

    #undef TARG_FN
}

//******************************************************************************
// AssociationManager::_addAssocToSysOrNodeTarget
//******************************************************************************

errlHndl_t AssociationManager::_addAssocToSysOrNodeTarget(
    const TargetService::ASSOCIATION_TYPE i_assocType,
          Target* const                   i_pSourceSysOrNodeTarget,
    const Target* const                   i_pDestSysOrNodeTarget)
{
    #define TARG_FN "_addAssocToSysOrNodeTarget(...)"

    errlHndl_t pError = NULL;

    do {

    if(!i_pSourceSysOrNodeTarget)
    {
        TARG_ASSERT(0,
            "Caller tried to add association using NULL source target");
    }

    if(!i_pDestSysOrNodeTarget)
    {
        TARG_ASSERT(0,
            "Caller tried to add association using NULL destination target");
    }

    // Intentinoally match -ANY- node type
    TARGETING::PredicateCTM isaNodeTarget(CLASS_ENC);
    TARGETING::PredicateCTM isaSysTarget(CLASS_SYS,TYPE_SYS);

    size_t maxLinks = 0;
    if(isaNodeTarget(i_pSourceSysOrNodeTarget)
       && isaSysTarget(i_pDestSysOrNodeTarget))
    {
        maxLinks = MAX_PARENT_LINKS_PER_ASSOC_TYPE;

        if (   (i_assocType != TARGETING::TargetService::PARENT)
            && (i_assocType != TARGETING::TargetService::PARENT_BY_AFFINITY))
        {
            TARG_ASSERT(0,
                "Caller specified unsupported association type / source target "
                "pair when attempting to add association link. "
                "i_assocType = 0x%08X, HUID = 0x%08X",
                i_assocType,
                i_pSourceSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>());
        }
    }
    else if(isaSysTarget(i_pSourceSysOrNodeTarget)
            && isaNodeTarget(i_pDestSysOrNodeTarget))
    {
        size_t numNodes = 0;
        TARGETING::TargetRangeFilter nodesItr(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &isaNodeTarget);
        for(;nodesItr;++nodesItr,++numNodes);

        maxLinks = numNodes;

        if (   (i_assocType != TARGETING::TargetService::CHILD)
            && (i_assocType != TARGETING::TargetService::CHILD_BY_AFFINITY))
        {
            TARG_ASSERT(0,
                "Caller specified unsupported association type / source target "
                "pair when attempting to add association links. "
                "i_assocType = 0x%08X, HUID = 0x%08X",
                i_assocType,
                i_pSourceSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>());
        }
    }
    else
    {
        TARG_ASSERT(0,
            "Caller tried to add association to invalid source/dest target "
            "combo (expected either node source/system dest -OR- system "
            "source/node dest.  Instead given source HUID = 0x%08X, dest "
            "HUID = 0x%08X",
            i_pSourceSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
            i_pDestSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>() );
    }

    AbstractPointer<Target>* pAssocsItrPreTrans  =
        TARG_TO_PLAT_PTR(
            i_pSourceSysOrNodeTarget->iv_ppAssociations[i_assocType]);

    AbstractPointer<Target>* pAssocsItr = NULL;

    if(TARG_ADDR_TRANSLATION_REQUIRED)
    {
        pAssocsItr = static_cast< AbstractPointer<Target>* >(
            TARG_GET_SINGLETON(TARGETING::theAttrRP).translateAddr(
                pAssocsItrPreTrans, i_pSourceSysOrNodeTarget));
    }
    else
    {
        pAssocsItr = pAssocsItrPreTrans;
    }

    if(!pAssocsItr)
    {
        TARG_ERR(
            "Failed to translate common association address to platform "
            "address.  Address prior to translation = %p, "
            "target HUID = 0x%08X, target address = %p",
            pAssocsItrPreTrans,
            i_pSourceSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
            i_pSourceSysOrNodeTarget);
        /*@
         * @errortype
         * @refcode      LIC_REFCODE
         * @subsys       EPUB_FIRMWARE_SP
         * @moduleid     TARG_MOD_ADD_ASSOC_TO_SYS_OR_NODE_TARGET
         * @reasoncode   TARG_RC_FAILED_TO_XLATE_ADDR
         * @userdata1    Address prior to translation
         * @userdata2    Target's HUID
         * @userdata3    Target's address
         * @devdesc      Error: Failed to translate common association address
         *     to platform address
         * @custdesc     An issue occurred during IPL of the system:
         *               Internal Firmware Error
         */
        UTIL::createTracingError(
            TARG_MOD_ADD_ASSOC_TO_SYS_OR_NODE_TARGET,
            TARG_RC_FAILED_TO_XLATE_ADDR,
            TARG_PTR_TO_UINT32(pAssocsItrPreTrans),
            i_pSourceSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
            TARG_PTR_TO_UINT32(i_pSourceSysOrNodeTarget),
            0,
            pError);
        break;
    }

    size_t association = 0;

    // Find unused (0) entry
    for(; static_cast<uint64_t>(*pAssocsItr) != 0; ++pAssocsItr, ++association);

    if(association >= maxLinks)
    {
        TARG_ERR(
            "No free association entry to set; association = %d, "
            "maxLinks = %d, i_assocType = 0x%08X, HUID = 0x%08X",
            association, maxLinks, i_assocType,
            i_pSourceSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>());
        /*@
         * @errortype
         * @refcode      LIC_REFCODE
         * @subsys       EPUB_FIRMWARE_SP
         * @moduleid     TARG_MOD_ADD_ASSOC_TO_SYS_OR_NODE_TARGET
         * @reasoncode   TARG_RC_EXCEEDED_ENTRY_LIMIT
         * @userdata1    Index into association array
         * @userdata2    Maximum association entries
         * @userdata3    Association type
         * @userdata4    HUID of target to modify
         * @devdesc      Error: No free association entry to set
         * @custdesc     An issue occurred during IPL of the system:
         *               Internal Firmware Error
         */
        UTIL::createTracingError(
            TARG_MOD_ADD_ASSOC_TO_SYS_OR_NODE_TARGET,
            TARG_RC_EXCEEDED_ENTRY_LIMIT,
            association, maxLinks, i_assocType,
            i_pSourceSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
            pError);
        break;
    }
    else
    {
        uint64_t rawAddr = 0;
        #if defined(__HOSTBOOT_RUNTIME) || !defined(__HOSTBOOT_MODULE)
        pError = TARG_GET_SINGLETON(
            TARGETING::theAttrRP).convertPlatTargAddrToCommonAddr(
                i_pDestSysOrNodeTarget,rawAddr);
        if(pError)
        {
            TARG_ERR("Failed to convert platform target address into common "
                     "target address with dest HUID = 0x%08X, "
                     "i_pDestSysOrNodeTarget = %p",
                     i_pDestSysOrNodeTarget->getAttr<TARGETING::ATTR_HUID>(),
                     i_pDestSysOrNodeTarget);
            break;
        }
        #else
        // No translation required in non-runtime, non-FSP case
        rawAddr = reinterpret_cast<uint64_t>(i_pDestSysOrNodeTarget);
        #endif

        (*pAssocsItr).raw = rawAddr;
    }

    } while(0);

    return pError;

    #undef TARG_FN
}

#endif // if defined
} // namespace TARGETING
