/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/common/deconfigGard.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
 *  @file deconfigGard.C
 *
 *  @brief Implements the DeconfigGard class
 */

#include <stdint.h>
#include <algorithm>
#include <vector>
#include <iterator>

#include <hwas/hwasPlatAssert.H>
#include <hwas/common/hwas.H>
#include <hwas/common/hwasCommon.H>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/common/vpdConstants.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>

#ifdef __HOSTBOOT_MODULE
#include <errl/errlmanager.H>
#include <targeting/common/DCMUtils.H>
#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
#include <console/consoleif.H>
#endif
#endif

#ifdef CONFIG_TPMDD
#include <../../usr/secureboot/trusted/trustedbootUtils.H>
#endif

// Trace definition
#define __COMP_TD__ g_trac_deconf

namespace HWAS
{

using namespace HWAS::COMMON;
using namespace TARGETING;

//******************************************************************************
// RUNTIME/NON-RUNTIME/HOSTBOOT/NON-HOSTBOOT methods
//******************************************************************************

//******************************************************************************
DeconfigGard & theDeconfigGard()
{
    return HWAS_GET_SINGLETON(theDeconfigGardSingleton);
}

//******************************************************************************
DeconfigGard::DeconfigGard()
: iv_platDeconfigGard(NULL),
  iv_XAOBusEndpointDeconfigured(false)
{
    HWAS_DBG("DeconfigGard Constructor");
    HWAS_MUTEX_INIT(iv_mutex);
}

//******************************************************************************
DeconfigGard::~DeconfigGard()
{
    HWAS_DBG("DeconfigGard Destructor");
    HWAS_MUTEX_DESTROY(iv_mutex);
    free(iv_platDeconfigGard);
}

uint8_t isBlockSpecDeconfigSetOnAnyNode()
{
    ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig = 0;
    TargetHandleList l_nodelist;
    getEncResources(l_nodelist, TARGETING::TYPE_NODE,
                    TARGETING::UTIL_FILTER_FUNCTIONAL);
    for( auto l_node : l_nodelist )
    {
        l_block_spec_deconfig = l_node->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
        if (l_block_spec_deconfig)
        {
            break;
        }
    }
    return l_block_spec_deconfig;
}

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTarget(
        Target & i_target,
        const uint32_t i_errlEid,
        bool *o_targetDeconfigured,
        const DeconfigureFlags i_deconfigRule)
{
    HWAS_DBG("Deconfigure Target");
    errlHndl_t l_pErr = nullptr;

    do
    {
        // Do not deconfig Target if we're NOT being asked to force AND
        // the System is at runtime
        if ((i_deconfigRule == NOT_AT_RUNTIME) &&
                platSystemIsAtRuntime())
        {
            HWAS_INF("Skipping deconfigureTarget: at Runtime; target %.8X",
                get_huid(&i_target));
            break;
        }

        // just to make sure that we haven't missed anything in development
        //  AT RUNTIME: we should only be called to deconfigure these types.
        if (i_deconfigRule != NOT_AT_RUNTIME)
        {
            TYPE target_type = i_target.getAttr<ATTR_TYPE>();
            // TODO RTC 88471: use attribute vs hardcoded list.
            if (!((target_type == TYPE_MEMBUF) ||
                  (target_type == TYPE_NX) ||
                  (target_type == TYPE_EQ) ||
                  (target_type == TYPE_FC) ||
                  (target_type == TYPE_CORE) ||
                  (target_type == TYPE_PORE)))
            {
                HWAS_INF("Skipping deconfigureTarget: atRuntime with unexpected target %.8X type %d -- SKIPPING",
                    get_huid(&i_target), target_type);
                break;
            }
        }

        const ATTR_DECONFIG_GARDABLE_type lDeconfigGardable =
                i_target.getAttr<ATTR_DECONFIG_GARDABLE>();
        const uint8_t lPresent =
                i_target.getAttr<ATTR_HWAS_STATE>().present;

        if (!lDeconfigGardable || !lPresent)
        {
            // Target is not Deconfigurable. Create an error
            HWAS_ERR("Target %.8X not Deconfigurable (ATTR_DECONFIG_GARDABLE=%d, present=%d)",
                get_huid(&i_target), lDeconfigGardable, lPresent);

            /*@
             * @errortype
             * @moduleid          HWAS::MOD_DECONFIG_GARD
             * @reasoncode        HWAS::RC_TARGET_NOT_DECONFIGURABLE
             * @devdesc           Attempt to deconfigure a target that is not
             *                    deconfigurable or not present.
             * @custdesc          An issue occurred during IPL of the system:
             *                    Internal Firmware Error
             * @userdata1[00:31]  HUID of input target
             * @userdata1[32:63]  GARD errlog EID
             * @userdata2[00:31]  ATTR_DECONFIG_GARDABLE
             * @userdata2[32:63]  ATTR_HWAS_STATE.present

             */
            const uint64_t userdata1 =
                (static_cast<uint64_t>(get_huid(&i_target)) << 32) | i_errlEid;
            const uint64_t userdata2 =
                (static_cast<uint64_t>(lDeconfigGardable) << 32) | lPresent;
            l_pErr = hwasError(
                ERRL_SEV_INFORMATIONAL,
                HWAS::MOD_DECONFIG_GARD,
                HWAS::RC_TARGET_NOT_DECONFIGURABLE,
                userdata1, userdata2);
            break;
        }

        // all ok - do the work
        HWAS_MUTEX_LOCK(iv_mutex);

        // Deconfigure the Target
        _deconfigureTarget(i_target, i_errlEid, o_targetDeconfigured,
                i_deconfigRule);

        // Deconfigure other Targets by association
        _deconfigureByAssoc(i_target, i_errlEid, i_deconfigRule);

        HWAS_MUTEX_UNLOCK(iv_mutex);
    }
    while (0);

    return l_pErr;
} // deconfigureTarget

//******************************************************************************
void DeconfigGard::_deconfigureTarget(
        Target & i_target,
        const uint32_t i_errlEid,
        bool *o_targetDeconfigured /* default is nullptr */,
        const DeconfigureFlags i_deconfigRule /* default is NOT_AT_RUNTIME */)
{
    HWAS_INF("Deconfiguring Target %.8X, errlEid 0x%X",
            get_huid(&i_target), i_errlEid);

    HwasState l_state = i_target.getAttr<ATTR_HWAS_STATE>();

    // if the rule is DUMP_AT_RUNTIME and we got here, then we are at runtime.
    // FSP Only, used by DUMP applet; 0b0: target is dump capable; 0b1:
    // target is not dump capable; see obj/genfiles/attributestructs.H
    if (i_deconfigRule == DUMP_AT_RUNTIME)
    {
        l_state.dumpfunctional = 1;
    }
    else
    {
        l_state.dumpfunctional = 0;
    }

    // Set the Target state to non-functional. The assumption is that it is
    // not possible for another thread (other than deconfigGard) to be
    // updating HWAS_STATE concurrently.
    updateAttrPG(i_target, false);

    if (!l_state.functional)
    {
        HWAS_DBG("Target HWAS_STATE already has functional=0; deconfiguredByEid=0x%X",
                l_state.deconfiguredByEid);

        if (i_deconfigRule != NOT_AT_RUNTIME)
        {
            // if FULLY_AT_RUNTIME or DUMP_AT_RUNTIME, then the dumpfunctional
            // state changed, so do the setAttr
            i_target.setAttr<ATTR_HWAS_STATE>(l_state);
        }

        if (l_state.deconfiguredByEid == DECONFIGURED_BY_FIELD_CORE_OVERRIDE)
        {
            // A child target was deconfig by FCO, and parent is being deconfig
            // with a non-FCO reason .. override with parent's EID
            HWAS_INF("HUID %.8X, Overriding deconfigByEid from FCO->%.8X",
                     get_huid(&i_target), i_errlEid);
            l_state.deconfiguredByEid = i_errlEid;
            i_target.setAttr<ATTR_HWAS_STATE>(l_state);
        }
    }
    else //HWAS state functional
    {
        if(i_deconfigRule == SPEC_DECONFIG)
        {
            HWAS_INF("Setting speculative deconfig");
            l_state.specdeconfig = 1;
            l_state.deconfiguredByEid = i_errlEid;
            i_target.setAttr<ATTR_HWAS_STATE>(l_state);
        }
        else
        {
            HWAS_INF("Setting Target HWAS_STATE: functional=0; deconfiguredByEid=0x%X",
                    i_errlEid);

            l_state.functional = 0;
            l_state.specdeconfig = 0;
            l_state.deconfiguredByEid = i_errlEid;

            i_target.setAttr<ATTR_HWAS_STATE>(l_state);

            if (o_targetDeconfigured)
            {
                *o_targetDeconfigured = true;
            }

            // if this is a real error, trigger a reconfigure loop
            if (i_errlEid & DECONFIGURED_BY_PLID_MASK)
            {
                // Set RECONFIGURE_LOOP attribute to indicate it was caused by
                // a hw deconfigure
                TARGETING::Target* l_pTopLevel = nullptr;
                TARGETING::targetService().getTopLevelTarget(l_pTopLevel);
                TARGETING::ATTR_RECONFIGURE_LOOP_type l_reconfigAttr =
                        l_pTopLevel->getAttr<ATTR_RECONFIGURE_LOOP>();
                // 'OR' values in case of multiple reasons for reconfigure
                l_reconfigAttr |= TARGETING::RECONFIGURE_LOOP_DECONFIGURE;
                l_pTopLevel->setAttr<ATTR_RECONFIGURE_LOOP>(l_reconfigAttr);
            }

            // Do any necessary Deconfigure Actions
            _doDeconfigureActions(i_target);

            const ATTR_TYPE_type target_type = i_target.getAttr<ATTR_TYPE>();

            // If target being deconfigured is an x/a/o bus endpoint
            if (TYPE_IOHS == target_type || TYPE_SMPGROUP == target_type)
            {
                // Set flag indicating x/a/o bus endpoint deconfiguration
                iv_XAOBusEndpointDeconfigured = true;
            }

            // The target has been successfully de-configured,
            // perform any other post-deconfig operations,
            // e.g. syncing state with other subsystems
            // TODO RTC:184521: Allow function platPostDeconfigureTarget
            // to run once FSP supports it
            // Remove the #ifdef ... #endif, once FSP is ready for code
            #ifdef __HOSTBOOT_MODULE
                platPostDeconfigureTarget(&i_target);
            #endif
        }
    }
} // _deconfigureTarget

//******************************************************************************
void DeconfigGard::_doDeconfigureActions(Target & i_target)
{
 // Placeholder for any necessary deconfigure actions
} // _doDeconfigureActions

//******************************************************************************
void DeconfigGard::_deconfigureByAssoc(
        Target & i_target,
        const uint32_t i_errlEid,
        const DeconfigureFlags i_deconfigRule)
{
    HWAS_INF("_deconfigureByAssoc for %.8X (i_deconfigRule %d)",
            get_huid(&i_target), i_deconfigRule);

    // some common variables used below
    TargetHandleList pChildList;
    PredicateHwas isFunctional;
    isFunctional.functional(true);
    if(i_deconfigRule == SPEC_DECONFIG)
    {
        isFunctional.specdeconfig(false);
    }

    // Retrieve the target type from the given target
    const TYPE l_targetType = i_target.getAttr<ATTR_TYPE>();
    const uint32_t l_targetHuid = get_huid(&i_target);

    // If there are child targets deconfig by FCO, override the reason
    // with that of the parent's deconfg EID
    PredicateHwas isFCO;
    isFCO.present(true).functional(false)
         .deconfiguredByEid(DECONFIGURED_BY_FIELD_CORE_OVERRIDE);

    PredicatePostfixExpr funcOrFco;
    funcOrFco.push(&isFunctional).push(&isFCO).Or();

    // note - ATTR_DECONFIG_GARDABLE is NOT checked for all 'by association'
    // deconfigures, as that attribute is only for direct deconfigure requests.

    // find all CHILD targets and deconfigure them
    targetService().getAssociated(pChildList, &i_target,
        TargetService::CHILD, TargetService::ALL, &funcOrFco);

    // Temporary list for special relationships since the
    // getChildxxxTargetsByState functions replace instead of append to the
    // list passed in
    TargetHandleList pTempList;

    // Since OMICs and OMIs share special relations OMI_CHILD and OMIC_PARENT,
    // they will only show up if those relations are used and not the regular
    // CHILD and PARENT relations.
    if (l_targetType == TYPE_OMIC)
    {
        // Append OMI targets to the temp list.
        getChildOmiTargetsByState(pTempList, &i_target, CLASS_NA,
                                  TYPE_OMI, UTIL_FILTER_FUNCTIONAL);
    }

    // Since PAUCs and OMICs share special relations PAUC_CHILD and PAUC_PARENT,
    // they will only show up if those relations are used and not the regular
    // CHILD and PARENT relations.
    else if (l_targetType == TYPE_PAUC)
    {
        // Add OMIC targets to the temp list.
        getChildPaucTargetsByState(pTempList, &i_target, CLASS_NA,
                                  TYPE_OMIC, UTIL_FILTER_FUNCTIONAL);
    }
    else if (l_targetType == TYPE_IOHS)
    {
        // We do NOT need to deconfigure the mapped PAU here, it can still be
        // used for other links.
    }
    else if (l_targetType == TYPE_NMMU)
    {
        auto l_unit = i_target.getAttr<ATTR_CHIP_UNIT>();

        // NMMU1 will take out the associated PAUs (0,4,5)
        if( l_unit == 1 ) //NMMU1
        {
            const Target* l_parentChip = getParentChip(&i_target);
            TargetHandleList l_pauList;
            getChildChiplets(l_pauList,l_parentChip,TYPE_PAU);
            for( auto pau : l_pauList )
            {
                auto pos = pau->getAttr<ATTR_CHIP_UNIT>();
                if( (pos==0) || (pos==4) || (pos==5) )
                {
                    pTempList.push_back(pau);
                }
            }
        }
        // NMMU0 will take out the entire proc chip in _deconfigParentAssoc
    }
    // If the target is a Parent Pervasive, then deconfigure the targets associated
    // with the Parent Pervasive target and it's children.
    else if (l_targetType == TYPE_PERV)
    {
        TargetHandleList l_associatesOfPervTargetsList;
        getPervasiveChildTargetsByState(l_associatesOfPervTargetsList, &i_target,
                                        CLASS_NA, TYPE_NA, UTIL_FILTER_FUNCTIONAL);
        for( auto l_parentPervChild : l_associatesOfPervTargetsList )
        {
            pTempList.push_back(l_parentPervChild);
        }
    }
    else if (l_targetType == TYPE_PROC)
    {
        #ifdef __HOSTBOOT_MODULE
            // Get the IO SCM chip associated with target if system is a Dual Chip Module
            DCMUtils l_dcmUtils;
            auto l_ioScmChip = l_dcmUtils.getAssociatedIoScmChip(&i_target);
            // If an IO SCM chip was found then put on list of targets to be deconfigured
            if (l_ioScmChip) { pTempList.push_back(l_ioScmChip); };
        #endif
    }

    // Append the temporary list to the child list
    if (!pTempList.empty())
    {
        pChildList.insert(pChildList.end(), pTempList.begin(), pTempList.end());
    }

    for (TargetHandleList::iterator pChild_it = pChildList.begin();
            pChild_it != pChildList.end();
            ++pChild_it)
    {
        TargetHandle_t pChild = *pChild_it;

        HWAS_INF("_deconfigureByAssoc %.8X _deconfigureTarget on CHILD: %.8X",
                 l_targetHuid, get_huid(pChild));
        _deconfigureTarget(*pChild, i_errlEid, nullptr,
                i_deconfigRule);

        // Deconfigure other Targets by association
        _deconfigureByAssoc(*pChild, i_errlEid, i_deconfigRule);
    } // for CHILD

    if ((i_deconfigRule == NOT_AT_RUNTIME) ||
        (i_deconfigRule == SPEC_DECONFIG)  ||
        (l_targetType == TYPE_FC)          ||
        (l_targetType == TYPE_CORE))
    {
        // Allow any affinity deconfigure if NOT at runtime
        //  --> if the rule is NOT_AT_RUNTIME and we got here, then we are
        //      not at runtime.
        //
        // Allow all speculative deconfigures, irregardless of runtime status
        //
        // Allow affinity deconfig of FC and CORE targets,
        // regardless of the runtime status

        // Work deconfigure down to its children
        // find all CHILD_BY_AFFINITY targets and deconfigure them
        targetService().getAssociated(pChildList, &i_target,
            TargetService::CHILD_BY_AFFINITY, TargetService::ALL,
            &funcOrFco);
        for (TargetHandleList::iterator pChild_it = pChildList.begin();
                pChild_it != pChildList.end();
                ++pChild_it)
        {
            TargetHandle_t pChild = *pChild_it;

            HWAS_INF("_deconfigureByAssoc %.8X _deconfigureTarget "
                     "CHILD_BY_AFFINITY: %.8X",
                    l_targetHuid, get_huid(pChild));
            _deconfigureTarget(*pChild, i_errlEid, nullptr,
                    i_deconfigRule);

            // Deconfigure other Targets by association
            _deconfigureByAssoc(*pChild, i_errlEid, i_deconfigRule);
        } // for CHILD_BY_AFFINITY

        // Work the deconfig up the parent side (if necessary)
        HWAS_DBG("_deconfigureByAssoc %.8X _deconfigParentAssoc", l_targetHuid);
       _deconfigParentAssoc(i_target, i_errlEid, i_deconfigRule);

        // Deconfigure the Parent Pervasive if the Target has a Parent Pervasive.
        // This method will check if the Target has a Parent Pervasive, no need
        // to check for that here.  This method will not propagate the deconfig,
        // it only deconfigs the Parent Pervasive associated with target.
        _deconfigParentPervasiveAssoc(i_target, i_errlEid, i_deconfigRule);
    } // !i_Runtime-ish
    else
    {
        HWAS_INF("_deconfigureByAssoc() - system is at runtime"
                " skipping all association checks beyond"
                " the CHILD");
    }

    HWAS_DBG("_deconfigureByAssoc exiting: %.8X", l_targetHuid);

} // _deconfigureByAssoc

//******************************************************************************
void DeconfigGard::_deconfigParentAssoc(TARGETING::Target & i_target,
                                        const uint32_t i_errlEid,
                                        const DeconfigureFlags i_deconfigRule)
{
    HWAS_INF("_deconfigParentAssoc entry for %.8X (i_deconfigRule %d)",
            get_huid(&i_target), i_deconfigRule);

    // Retrieve the target type from the given target
    TYPE l_targetType = i_target.getAttr<ATTR_TYPE>();

    if ((i_deconfigRule == NOT_AT_RUNTIME) ||
        (i_deconfigRule == SPEC_DECONFIG)  ||
        (l_targetType == TYPE_FC)          ||
        (l_targetType == TYPE_CORE))
    {
        // Allow any affinity deconfigure if NOT at runtime
        //  --> if the rule is NOT_AT_RUNTIME and we got here, then we are
        //      not at runtime.
        //
        // Allow all speculative deconfigures, irregardless of runtime status
        //
        // Allow affinity deconfig of FC and CORE targets,
        // regardless of the runtime status

        // Handles bus endpoint (TYPE_IOHS, TYPE_SMPGROUP, TYPE_PSI) and
        // memory (TYPE_MEMBUF, TYPE_MBA, TYPE_DIMM)
        // chip  (TYPE_FC, TYPE_CORE)
        // obus specific (TYPE_OBUS, TYPE_NPU, TYPE_OBUS_BRICK)
        // deconfigureByAssociation rules
        switch (l_targetType)
        {
            case TYPE_CORE:
            {
                HWAS_DBG("_deconfigParentAssoc CORE deconfig parent proc");
                //
                // In Fused Core Mode, Cores must be de-configureed
                // in pairs
                //
                // In Normal Core Mode if both cores are non-functional
                // FC should be deconfigured
                //
                // First get parent i.e FC
                // Other errors may have affected parent state so use
                // UTIL_FILTER_ALL
                TargetHandleList pParentFcList;
                getParentAffinityTargetsByState(pParentFcList, &i_target,
                        CLASS_UNIT, TYPE_FC, UTIL_FILTER_ALL);
                HWAS_ASSERT((pParentFcList.size() == 1),
                    "HWAS _deconfigParentAssoc: pParentFcList != 1");
                Target *l_parentFC = pParentFcList[0];

                // General predicate to determine if target is functional
                PredicateIsFunctional isFunctional;

                if (isFunctional(l_parentFC))
                {
                    HWAS_DBG("_deconfigParentAssoc isFunctional");
                    // Fused Core Mode
                    if (is_fused_mode())
                    {
                        HWAS_DBG("_deconfigParentAssoc is_fused_mode");
                        // If parent is functional, deconfigure it
                        _deconfigureTarget(*l_parentFC,
                           i_errlEid, nullptr, i_deconfigRule);
                        _deconfigureByAssoc(*l_parentFC,
                          i_errlEid,i_deconfigRule);
                        // After deconfiguring FC the other FC of EQ
                        // is non-functional, case TYPE_FC takes care
                    }
                    // Normal Core Mode
                    // if both cores of FC non-functional, de-config FC
                    else if (!anyChildFunctional(*l_parentFC))
                    {
                       HWAS_DBG("_deconfigParentAssoc normal core");
                       uint32_t l_errlEidOverride = i_errlEid;


                       // If any sibling is not functional due to FCO, override
                       // the deconfig by Eid reason of its parent to FCO
                       if (anyChildFCO(*l_parentFC))
                       {
                           HWAS_INF("_deconfigParentAssoc Override FC %.8X deconfigByEid %.8X->FCO",
                                    get_huid(l_parentFC), i_errlEid);
                           l_errlEidOverride =
                                    DECONFIGURED_BY_FIELD_CORE_OVERRIDE;
                       }

                       // If parent is functional, deconfigure it
                       HWAS_DBG("_deconfigParentAssoc parent functional deconfigure");
                       _deconfigureTarget(*l_parentFC,
                          l_errlEidOverride, nullptr, i_deconfigRule);
                       _deconfigureByAssoc(*l_parentFC,
                          l_errlEidOverride, i_deconfigRule);
                    } // is_fused
                } // isFunctional
                break;
            } // TYPE_CORE

            case TYPE_DIMM:
            {
                HWAS_DBG("_deconfigParentAssoc DIMM deconfig parent proc");
                // Whenever a DIMM is deconfigured, we will also deconfigure
                // the immediate parent target (e.g. MCA, MBA, etc) to ensure
                // there is not an unbalanced load on the ports.

                // General predicate to determine if target is functional
                PredicateIsFunctional isFunctional;

                //  get immediate parent (MCA/MBA/etc)
                TargetHandleList pParentList;
                PredicatePostfixExpr funcParent;
                funcParent.push(&isFunctional);
                targetService().getAssociated(pParentList,
                        &i_target,
                        TargetService::PARENT_BY_AFFINITY,
                        TargetService::IMMEDIATE,
                        &funcParent);

                HWAS_ASSERT((pParentList.size() <= 1),
                    "HWAS _deconfigParentAssoc: pParentList > 1");

                // if parent hasn't already been deconfigured
                //  then deconfigure it
                if (!pParentList.empty())
                {
                    const Target *l_parentMba = pParentList[0];
                    HWAS_INF("_deconfigParentAssoc DIMM parent: %.8X",
                             get_huid(l_parentMba));
                    _deconfigureTarget(const_cast<Target &> (*l_parentMba),
                                       i_errlEid, nullptr, i_deconfigRule);
                    _deconfigureByAssoc(const_cast<Target &> (*l_parentMba),
                                        i_errlEid, i_deconfigRule);
                }

                break;
            } // TYPE_DIMM

            // If the target is an SMPGROUP bus, deconfigure its peer
            case TYPE_SMPGROUP:
            {
                Target* const iohs_target = getImmediateParentByAffinity(&i_target);

                const auto iohs_config_mode = iohs_target->getAttr<ATTR_IOHS_CONFIG_MODE>();

                const bool is_smp_link = ((iohs_config_mode == IOHS_CONFIG_MODE_SMPA)
                                          || (iohs_config_mode == IOHS_CONFIG_MODE_SMPX));

                // Deconfigure the target's IOHS parent if we're in SMP mode and
                // the IOHS has no other functional child SMPGROUPs
                if (is_smp_link)
                {
                    _deconfigAffinityParent(i_target, i_errlEid, i_deconfigRule);
                }

                const Target* const l_pDstTarget = i_target.getAttr<ATTR_PEER_TARGET>();

                // If the peer target is valid...
                if (l_pDstTarget)
                {
                    auto l_pDstTarget_state = l_pDstTarget->getAttr<ATTR_HWAS_STATE>();

                    // ...and if the target is functional...
                    if (!l_pDstTarget_state.functional
                        || (i_deconfigRule == SPEC_DECONFIG && l_pDstTarget_state.specdeconfig))
                    { // Keep from entering an infinite loop, don't re-deconfigure a target that's already deconfigured
                        break;
                    }

                    HWAS_INF("_deconfigParentAssoc BUS peer: 0x%.8X", get_huid(l_pDstTarget));

                    // ...then deconfigure the peer itself
                    _deconfigureTarget(const_cast<Target &>(*l_pDstTarget),
                                       i_errlEid, nullptr, i_deconfigRule);

                    // Deconfiguring the peer might cause other targets to get
                    // deconfigured, like the peer's parent IOHS
                    _deconfigureByAssoc(const_cast<Target &>(*l_pDstTarget),
                                        i_errlEid, i_deconfigRule);
                }

                break;
            } // SMPGROUP

            case TYPE_OMI:
            {
                HWAS_DBG("_deconfigParentAssoc OMI deconfig parent proc");

                // Deconfigure related OMIC if necessary
                TargetHandleList pOmicParentList;
                getParentOmicTargetsByState(pOmicParentList,
                        &i_target, CLASS_NA, TYPE_OMIC,
                        UTIL_FILTER_ALL);

                HWAS_ASSERT((pOmicParentList.size() == 1),
                    "HWAS _deconfigParentAssoc: pOmicParentList != 1");

                TargetHandle_t parentOmic = pOmicParentList[0];

                if (!anyChildFunctional(*parentOmic, TargetService::OMI_CHILD))
                {
                    _deconfigureTarget(*parentOmic, i_errlEid, nullptr,
                                       i_deconfigRule);
                }

                // Deconfigure parent MCC if necessary
                _deconfigAffinityParent(i_target, i_errlEid, i_deconfigRule);

                break;
            } // TYPE_OMI

            case TYPE_PAU:
            {
                // If PAU 0, 4, and 5 are all deconfigured then nest 1's NMMU is
                // power-gated and we deconfigure it here.

                HWAS_DBG("_deconfigParentAssoc PAU deconfig parent proc");
                const Target* const l_chip = getParentChip(&i_target);

                Target* const l_nmmu1 = shouldPowerGateNMMU1(*l_chip);
                if (l_nmmu1)
                {
                    _deconfigureTarget(*l_nmmu1,
                                       i_errlEid,
                                       nullptr,
                                       i_deconfigRule);
                }

                // Deconfigure the mapped partner OCAPI IOHS, if any. This won't
                // do anything before Istep 10, where the mapping happens,
                // because the mapping attribute isn't set yet.

                TargetHandleList pIohsParentList;
                getParentIohsTargetsByState(pIohsParentList,
                        &i_target, CLASS_NA, TYPE_IOHS,
                        UTIL_FILTER_FUNCTIONAL);

                HWAS_ASSERT((pIohsParentList.size() <= 1),
                            "HWAS _deconfigParentAssoc: got multiple IOHS parents of PAU target");

                if (!pIohsParentList.empty())
                {
                    TargetHandle_t parentIohs = pIohsParentList[0];

                    _deconfigureTarget(*parentIohs, i_errlEid, nullptr,
                                       i_deconfigRule);
                }

                // Ensure that there are at least enough PAU units to satisfy
                // the functional OCAPI IOHSes' requirements. This won't do
                // anything after Istep 10, because there will be a one-to-one
                // mapping between OCAPI IOHS targets, and we will already have
                // deconfigured the partner above, if there was one.
                Target* const parentPauc = getImmediateParentByAffinity(&i_target);

                HWAS_ASSERT(parentPauc->getAttr<ATTR_TYPE>() == TYPE_PAUC,
                            "Parent of PAU 0x%08x is not a PAUC, got %s",
                            get_huid(&i_target),
                            attrToString<ATTR_TYPE>(parentPauc->getAttr<ATTR_TYPE>()));

                const auto iohsList
                    = disableExtraOcapiIohsTargets(parentPauc);

                for (const auto iohs : iohsList)
                {
                    _deconfigureTarget(*iohs, i_errlEid, nullptr, i_deconfigRule);
                }
                break;
            } // TYPE_PAU

            case TYPE_NMMU:
            {
                HWAS_DBG("_deconfigParentAssoc NMMU deconfig parent proc");
                // If this is NMMU0 then we must knock out the parent
                // processor chip, otherwise we do the standard
                // _deconfigAffinityParent call and break.
                if(i_target.getAttr<ATTR_CHIP_UNIT>() != 0)
                {
                    HWAS_DBG("NMMU1 case - default");
                    _deconfigAffinityParent(i_target, i_errlEid, i_deconfigRule);
                    break;
                }
                HWAS_DBG("NMMU0 case - take out the chip");

                // Otherwise if we are deconfiguring NMMU0 we must also deconfig
                // it's parent processor chip so fall through to the next case
            } // TYPE_NMMU

            case TYPE_PAUC:
            case TYPE_EQ:
            {
                // If any PAUC or EQ is deconfigured than deconfigure its
                // parent processor chip
                HWAS_DBG("_deconfigParentAssoc PAUC or EQ deconfig parent proc");
                Target* const l_chip = const_cast<Target*>(getParentChip(&i_target));

                HWAS_ASSERT(l_chip != nullptr,
                            "Unable to find parent chip for target 0x%08x",
                            get_huid(&i_target));

                _deconfigureTarget(*l_chip, i_errlEid, nullptr, i_deconfigRule);
                _deconfigureByAssoc(*l_chip, i_errlEid, i_deconfigRule);

                break;
            } // TYPE_PAUC or TYPE_EQ

            case TYPE_PSI:
            {
                // Get peer endpoint target
                const Target * l_pDstTarget = i_target.
                              getAttr<ATTR_PEER_TARGET>();
                // If target is valid
                if (l_pDstTarget)
                {
                    // Deconfigure peer endpoint
                    HWAS_INF("_deconfigParentAssoc PSI Peer: 0x%08x",
                        get_huid(l_pDstTarget));
                    _deconfigureTarget(const_cast<Target &> (*l_pDstTarget),
                                       i_errlEid, nullptr,
                                       i_deconfigRule);
                }
                break;
            } // TYPE_PSI

            default:
            {
              HWAS_INF("_deconfigParentAssoc default case _deconfigAffinityParent");
              // TYPE_IOHS, TYPE_MEMBUF, TYPE_MCA, TYPE_MCS, TYPE_MC, TYPE_MI, TYPE_DMI,
              // TYPE_MCC, TYPE_MBA, TYPE_PHB, TYPE_OBUS_BRICK, TYPE_EQ
              _deconfigAffinityParent(i_target, i_errlEid, i_deconfigRule);
            }
            break;
        } // switch
    }
    HWAS_DBG("_deconfigureParentAssoc exiting: %.8X", get_huid(&i_target));
} // _deconfigParentAssoc


//******************************************************************************
void DeconfigGard::_deconfigParentPervasiveAssoc(      TARGETING::Target & i_target,
                                                 const uint32_t            i_errlEid,
                                                 const DeconfigureFlags    i_deconfigRule)
{
    // Get a list of Parent Pervasive targets associated with this target.
    TargetHandleList l_parentPervasiveList;
    getParentPervasiveTargetsByState(l_parentPervasiveList, &i_target, CLASS_UNIT,
                                    TYPE_PERV, UTIL_FILTER_FUNCTIONAL);

    // Iterate thru the list of Parent Pervasive targets and only deconfigure it
    // if all associated targets have been deconfigured or if i_deconfigRule is
    // a speculative deconfig (SPEC_DECONFIG) and all functional, associated
    // targets have been set to speculative deconfig or regular deconfig.
    for (auto l_parentPervasive: l_parentPervasiveList)
    {
        // Will assume that the Parent Pervasive target will get deconfiged, unless
        // determined otherwise.
        bool l_deconfigParentPerv(true);

        // Retrieve all the functional targets associated with this Parent Pervasive target
        TargetHandleList l_associatesOfPervTargetsList;
        getPervasiveChildTargetsByState(l_associatesOfPervTargetsList, l_parentPervasive,
                                        CLASS_NA, TYPE_NA, UTIL_FILTER_FUNCTIONAL);
        // If there are functional targets associated with this Parent Pervasive,
        // then can't deconfig unless those functional targets match i_deconfigRule
        if (l_associatesOfPervTargetsList.size())
        {
            if (SPEC_DECONFIG == i_deconfigRule)
            {
                // Determine if these functional targets are speculative deconfigs,
                // and if all are so, then OK to deconfig Parent Pervasive target.
                // If one target is functional and is not a speculative deconfig, then
                // cannot deconfig this Parent Pervasive target.
                for ( auto l_parentPervChild : l_associatesOfPervTargetsList )
                {
                    auto l_state = l_parentPervChild->getAttr<TARGETING::ATTR_HWAS_STATE>();
                    if (!l_state.specdeconfig)
                    {
                        // Found a target that is not a speculative deconfig, therfore
                        // can't deconfig the Parent Pervasive target. No need to inspect
                        // the other targets.
                        l_deconfigParentPerv = false;
                        break;
                    }
                } // for ( auto l_parentPervChild : l_associatesOfPervTargetsList )
            } // if (SPEC_DECONFIG == i_deconfigRule)
            // There are functional targets, associated with this Parent Pervasive
            // target, and this is not a speculative deconfig/regular deconfig
            // ergo cannot deconfig the Parent Pervasive target.
            else
            {
                l_deconfigParentPerv = false;
            }
        } // if (l_associatesOfPervTargetsList.size())

        if (l_deconfigParentPerv)
        {
            _deconfigureTarget(*l_parentPervasive, i_errlEid, nullptr, i_deconfigRule);
        }
    } // for (auto l_parentPervasive: l_parentPervasiveList)
} // DeconfigGard::_deconfigParentPervasiveAssoc

//******************************************************************************
bool DeconfigGard::anyChildFunctional(Target & i_parent,
                            TargetService::ASSOCIATION_TYPE i_type)
{
    bool retVal = false;
    TargetHandleList pChildList;
    PredicateHwas isFunctional;
    isFunctional.functional(true);

    if (isFunctional(&i_parent))
    {
        // find all CHILD targets, that match the predicate
        // if any of them are functional return true
        // if all of them are non-functional return false
        targetService().getAssociated(pChildList, &i_parent, i_type,
                                      TargetService::ALL, &isFunctional);
        if (pChildList.size() >= 1)
        {
            retVal = true;
            if (i_type == TargetService::CHILD_BY_AFFINITY)
            {
                HWAS_INF("anyChildFunctional: found %d functional children of 0x%.8X (child 0: 0x%.8X)",
                    pChildList.size(), get_huid(&i_parent), get_huid(pChildList[0]));
            }
        }
    }
    return retVal;
} // anyChildFunctional

//******************************************************************************
bool DeconfigGard::anyChildFCO (Target & i_parent)
{
    bool retVal = false;

    TargetHandleList pChildList;
    PredicateHwas predFCO;
    predFCO.present(true)
           .functional(false)
           .deconfiguredByEid(DECONFIGURED_BY_FIELD_CORE_OVERRIDE);

    // find all CHILD targets, that match the predicate
    // if any of them are FCO return true
    // if none of them are FCO return false
    targetService().getAssociated(pChildList, &i_parent,
        TargetService::CHILD, TargetService::ALL, &predFCO);

    if (pChildList.size() >= 1)
    {
        retVal = true;
    }

    return retVal;
} // anyChildFCO

//******************************************************************************
void DeconfigGard::_deconfigAffinityParent( TARGETING::Target & i_child,
                                        const uint32_t i_errlEid,
                                        const DeconfigureFlags i_deconfigRule )
{
    Target * l_parent = nullptr;
    TARGETING::ATTR_PARENT_DECONFIG_RULES_type l_child_rules =
        i_child.getAttr<ATTR_PARENT_DECONFIG_RULES>();

    // Does this deconfigured child allow the deconfig to rollup to its parent
    if (l_child_rules.deconfigureParent)
    {
        // General predicate to determine if target is functional
        PredicateIsFunctional isFunctional;

        l_parent = getImmediateParentByAffinity(&i_child);

        if ((l_parent != nullptr) && isFunctional(l_parent))
        {
            TARGETING::ATTR_PARENT_DECONFIG_RULES_type l_parent_rules =
                  l_parent->getAttr<ATTR_PARENT_DECONFIG_RULES>();
            // Does the parent allow its deconfigured children to rollup their
            // deconfigure to itself?  This is a safety check to prevent
            // essential resources from being deconfigured via rollup.
            if (l_parent_rules.childRollupAllowed)
            {
                // Now check if parent has any functional affinity children
                // that match the same type/class as the child
                if ( !anyFunctionalChildLikeMe(l_parent, &i_child) )
                {
                    bool isDeconfigured = false;
                    HWAS_INF("_deconfigAffinityParent: deconfig functional parent 0x%.8X, EID 0x%.8X",
                        get_huid(l_parent), i_errlEid);
                    _deconfigureTarget(*l_parent, i_errlEid,
                                       &isDeconfigured, i_deconfigRule);
                    if (isDeconfigured)
                    {
                        HWAS_INF("_deconfigAffinityParent: roll-up/down parent 0x%.8X deconfig, EID 0x%.8X",
                            get_huid(l_parent), i_errlEid);
                        // need to account for possible non-like functional children
                        _deconfigureByAssoc(*l_parent, i_errlEid, i_deconfigRule);
                    }
                }
                else
                {
                    HWAS_INF("_deconfigAffinityParent: functional child found for parent 0x%.8X, EID 0x%.8X",
                        get_huid(l_parent), i_errlEid);
                }
            }
            else
            {
                HWAS_INF("_deconfigAffinityParent: parent 0x%.8X does NOT allow deconfig via child rollup",
                  get_huid(l_parent));
            }
        }
        else
        {
            if (l_parent != nullptr)
            {
                HWAS_INF("_deconfigAffinityParent: non-functional parent 0x%.8X of 0x%.8X, EID 0x%.8X",
                    get_huid(l_parent), get_huid(&i_child), i_errlEid);
            }
        }
    }
    else
    {
       HWAS_INF("_deconfigAffinityParent: do not rollup deconfigured child 0x%.8X, EID 0x%.8X",
            get_huid(&i_child), i_errlEid);
    }
} // _deconfigAffinityParent

//******************************************************************************
bool DeconfigGard::anyFunctionalChildLikeMe(const Target * i_my_parent,
                                            const Target * i_child)
{
    bool retVal = false;
    TargetHandleList pChildList;
    PredicateHwas isFunctional;
    isFunctional.functional(true);

    if (isFunctional(i_my_parent))
    {
        // target type and class as predicate
        auto l_childType = i_child->getAttr<ATTR_TYPE>();
        auto l_childClass = i_child->getAttr<ATTR_CLASS>();

        PredicateCTM predChildMatch(l_childClass, l_childType);
        PredicatePostfixExpr checkExpr;
        checkExpr.push(&predChildMatch).push(&isFunctional).And();

        // find all CHILD_BY_AFFINITY targets, that match the predicate
        // if any of them are functional return true
        // if all of them are non-functional return false
        targetService().getAssociated(pChildList, i_my_parent,
                                      TargetService::CHILD_BY_AFFINITY,
                                      TargetService::ALL,
                                      &checkExpr);
        if (pChildList.size() >= 1)
        {
            retVal = true;
            HWAS_INF("anyFunctionalChildLikeMe: found %d functional children of 0x%.8X (child 0: 0x%.8X)",
                    pChildList.size(), get_huid(i_my_parent), get_huid(pChildList[0]));
        }
    }
    return retVal;
} // anyFunctionalChildLikeMe

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureAssocProc()
{
    HWAS_INF("Deconfiguring chip resources "
             "based on fabric bus deconfigurations");

    HWAS_MUTEX_LOCK(iv_mutex);
    // call _invokeDeconfigureAssocProc() to obtain state of system,
    // call algorithm function, and then deconfigure targets
    // based on output
    errlHndl_t l_pErr = _invokeDeconfigureAssocProc();
    HWAS_MUTEX_UNLOCK(iv_mutex);
    return l_pErr;
} // deconfigureAssocProc

//******************************************************************************
errlHndl_t DeconfigGard::_invokeDeconfigureAssocProc(TARGETING::ConstTargetHandle_t i_node)
{
    HWAS_INF("Preparing data for _deconfigureAssocProc");
    // Return error
    errlHndl_t l_pErr = nullptr;

    // Define vector of ProcInfo structs to be used by
    // _deconfigAssocProc algorithm.
    ProcInfoVector l_procInfo;

    do
    {
        // If flag indicating deconfigured bus endpoints is not set,
        // then there's no work for _invokeDeconfigureAssocProc to do
        // as this implies there are no deconfigured endpoints or
        // processors.
        if (!(iv_XAOBusEndpointDeconfigured))
        {
            HWAS_INF("_invokeDeconfigureAssocProc: No deconfigured x/a/o"
                     " bus endpoints. Deconfiguration of "
                     "associated procs unnecessary.");
            break;
        }

        // Clear flag as this function is called multiple times
        iv_XAOBusEndpointDeconfigured = false;

        // Get top 'starting' level target - use top level target if no
        // i_node given (hostboot)
        Target *pTop;
        if (i_node == nullptr)
        {
            HWAS_INF("_invokeDeconfigureAssocProc: i_node not specified");
            targetService().getTopLevelTarget(pTop);
            HWAS_ASSERT(pTop, "_invokeDeconfigureAssocProc: no TopLevelTarget");
        }
        else
        {
            HWAS_INF("_invokeDeconfigureAssocProc: i_node 0x%X specified",
                     i_node->getAttr<ATTR_HUID>());
            pTop = const_cast<Target *>(i_node);
        }

        // Define and populate vector of procs
        // Define predicate
        PredicateCTM predProc(CLASS_CHIP, TYPE_PROC);
        PredicateHwas predPres;
        predPres.present(true);

        // Populate vector
        TargetHandleList l_procs;
        targetService().getAssociated(l_procs,
                                      pTop,
                                      TargetService::CHILD,
                                      TargetService::ALL,
                                      &predProc);

        // Sort by HUID
        std::sort(l_procs.begin(),
                  l_procs.end(), compareTargetHuid);

        // General predicate to determine if target is functional
        PredicateIsFunctional isFunctional;

        PredicateCTM predIohs(CLASS_UNIT, TYPE_IOHS);
        PredicatePostfixExpr busses;
        busses.push(&predIohs);

        // Iterate through procs and populate l_procInfo vector with system
        // information regarding procs to be used by _deconfigAssocProc
        // algorithm.
        ProcInfoVector l_procInfo;
        for (TargetHandleList::const_iterator
             l_procsIter = l_procs.begin();
             l_procsIter != l_procs.end();
             ++l_procsIter)
        {
            ProcInfo l_ProcInfo = ProcInfo();
            // Iterate through present procs and populate structs in l_procInfo
            // Target pointer
            l_ProcInfo.iv_pThisProc =
                *l_procsIter;
            // HUID
            l_ProcInfo.procHUID =
                (*l_procsIter)->getAttr<ATTR_HUID>();

            const uint8_t procFabricTopology =
                (*l_procsIter)->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_ID>();
            uint8_t procFabricGroup = 0;
            uint8_t procFabricChip = 0;
            extractGroupAndChip(procFabricTopology, procFabricGroup, procFabricChip);

            // FABRIC_GROUP_ID
            l_ProcInfo.procFabricGroup = procFabricGroup;
            // FABRIC_CHIP_ID
            l_ProcInfo.procFabricChip = procFabricChip;
            // HWAS state
            l_ProcInfo.iv_deconfigured =
                !(isFunctional(*l_procsIter));
            // iv_masterCapable - this includes both master and alternate master
            // This is done to ensure that both the master and alt master don't
            // get deconfigured in _deconfigAssocProc()
            if ( (*l_procsIter)->getAttr<ATTR_PROC_MASTER_TYPE>() ==
                 PROC_MASTER_TYPE_NOT_MASTER)
            {
                l_ProcInfo.iv_masterCapable = false;
            }
            else
            {
                l_ProcInfo.iv_masterCapable = true;
            }
            HWAS_INF( "_invokeDeconfigureAssocProc> %.8X : G=%d, C=%d, D=%d, M=%d", l_ProcInfo.procHUID, l_ProcInfo.procFabricGroup, l_ProcInfo.procFabricChip, l_ProcInfo.iv_deconfigured, l_ProcInfo.iv_masterCapable );
            l_procInfo.push_back(l_ProcInfo);
        }
        HWAS_INF("----------------------------------------------------------");
        // Iterate through l_procInfo and populate child bus endpoint
        // chiplet information
        for (ProcInfoVector::iterator
             l_currentProcInfoIt = l_procInfo.begin();
             l_currentProcInfoIt != l_procInfo.end();
             ++l_currentProcInfoIt)
        {
            // Populate vector of bus endpoints associated with this proc
            TargetHandleList l_busTargets;
            targetService().getAssociated(l_busTargets,
                                         (*l_currentProcInfoIt).iv_pThisProc,
                                         TargetService::CHILD,
                                         TargetService::ALL,
                                         &busses);

            // Remove irrelevant IOHS types from the vector.
            l_busTargets.erase(std::remove_if(l_busTargets.begin(), l_busTargets.end(),
                                              [](const TargetHandle_t& i)
                                              {
                                                 auto l_iohsConfigMode = i->getAttr<ATTR_IOHS_CONFIG_MODE>();
                                                 // Only want all SMPX and SMPA IOHS targets.
                                                 return !((l_iohsConfigMode == IOHS_CONFIG_MODE_SMPX)
                                                        || (l_iohsConfigMode == IOHS_CONFIG_MODE_SMPA));
                                              }), l_busTargets.end());

            { // Get the SMPGROUP children of all the SMPA/X IOHSes that we just
              // collected.
                TargetHandleList l_realLinkTargets;

                TargetHandleList l_smpgroups;

                PredicateCTM predSmpgroup(CLASS_NA, TYPE_SMPGROUP);
                PredicateAttrVal<ATTR_PEER_TARGET> predPeerTarget(nullptr, true /* invert search */);
                PredicatePostfixExpr smpgroupWithPeerTarget;
                smpgroupWithPeerTarget.push(&predSmpgroup).push(&predPeerTarget).And();

                for (const auto l_iohs : l_busTargets)
                {
                    targetService().getAssociated(l_smpgroups,
                                                  l_iohs,
                                                  TargetService::CHILD,
                                                  TargetService::ALL,
                                                  &smpgroupWithPeerTarget);

                    l_realLinkTargets.insert(end(l_realLinkTargets), begin(l_smpgroups), end(l_smpgroups));
                }

                // Overwrite the IOHS list with the list of real links
                l_busTargets = move(l_realLinkTargets);
            }

            // Sort by HUID
            std::sort(l_busTargets.begin(),
                      l_busTargets.end(), compareTargetHuid);

            uint8_t inGroupBusIndex = 0;
            uint8_t outGroupBusIndex = 0;

            // Iterate through bus endpoint chiplets
            for (TargetHandleList::const_iterator
                 l_busIter = l_busTargets.begin();
                 l_busIter != l_busTargets.end();
                 ++l_busIter)
            {
                // Declare current endpoint target
                const Target * l_currentEndpointTarget = *l_busIter;
                // Get peer endpoint target
                const Target * l_DestEndpointTarget = l_currentEndpointTarget->getAttr<ATTR_PEER_TARGET>();

                // Only interested in endpoint chiplets which lead to a present proc:
                // If no destination endpoint for the current endpoint or the peer endpoint is not present, continue
                if ((!l_DestEndpointTarget) ||
                    (!(l_DestEndpointTarget->getAttr<ATTR_HWAS_STATE>().present)))
                {
                    if (l_DestEndpointTarget == nullptr)
                    {
                      HWAS_INF("Proc %.8X Skipping non-peer endpt of BUS %.8X",
                        get_huid((*l_currentProcInfoIt).iv_pThisProc),
                        l_currentEndpointTarget->getAttr<ATTR_HUID>());
                    }
                    else
                    {
                      HWAS_INF("Proc %.8X Skipping non-present endpt target %.8X of %.8X BUS",
                          get_huid((*l_currentProcInfoIt).iv_pThisProc),
                          l_DestEndpointTarget->getAttr<ATTR_HUID>(),
                          l_currentEndpointTarget->getAttr<ATTR_HUID>());
                    }

                    continue;
                }

                // Chiplet has a valid (present) peer
                // Handle filling out ProcInfo arrays
                // Define target for peer proc
                const Target* l_pPeerProcTarget;
                // Get parent chip from bus chiplet
                l_pPeerProcTarget = getParentChip(l_DestEndpointTarget);

                // Find matching ProcInfo struct
                for (ProcInfoVector::iterator
                     l_peerProcInfoIt = l_procInfo.begin();
                     l_peerProcInfoIt != l_procInfo.end();
                     ++l_peerProcInfoIt)
                {
                    /*************
                     NOTE:

                       1. On P10 systems, XBUS busses connect processors within the same drawer, and ABUS busses
                          connect processors between drawers.

                       2. On platforms where deconfigureAssocProc is only called on Node targets (e.g. HWSV as of
                          P10), l_procInfo will only contain references processors on a single node. Therefore
                          l_busTargets will only contain references to busses on that same node.

                       3. The peer target (l_pPeerProcTarget) of an ABUS will always be on a different node than the
                          node the ABUS target itself is on.

                       4. This means that the following if-statement, checking whether the peer is equal to some
                          processor in l_procInfo, will NEVER be true for ABUS targets.

                       5. Consequently, the deconfigureAssocProc algorithm will NEVER consider ABUS targets. Broken
                          ABUS connections are handled elsewhere in HWSV.
                     *************/

                    // If Peer proc target matches this ProcInfo struct's
                    // Identifier target
                    if (l_pPeerProcTarget == l_peerProcInfoIt->iv_pThisProc)
                    {
                        // Update struct of current proc to point to this struct, and also handle iv_A/XDeconfigured[]
                        // and increment appropriate index:
                        if (l_peerProcInfoIt->procFabricGroup == l_currentProcInfoIt->procFabricGroup)
                        {
                            HWAS_ASSERT(inGroupBusIndex < NUM_IN_GROUP_BUSES,
                                        "Number of in-group bus connections %d exceeds maximum allowed: %d",
                                        inGroupBusIndex, NUM_IN_GROUP_BUSES);
                            l_currentProcInfoIt->iv_pInGroupProcInfos[inGroupBusIndex] = &(*l_peerProcInfoIt);
                            // HWAS state
                            l_currentProcInfoIt->iv_InGroupLinkDeconfigured[inGroupBusIndex] =
                                !(isFunctional(l_currentEndpointTarget));
                            HWAS_INF("PROC 0x%.8X add %.8X Bus Deconfig=%d; in-group bus[%d]> PROC %.8X: "
                                     "Group=%d, Chip=%d, Deconfigured=%d, Master=%d",
                                     l_currentProcInfoIt->procHUID,
                                     l_currentEndpointTarget->getAttr<ATTR_HUID>(),
                                     l_currentProcInfoIt->iv_InGroupLinkDeconfigured[inGroupBusIndex],
                                     inGroupBusIndex,
                                     l_peerProcInfoIt->procHUID,
                                     l_peerProcInfoIt->procFabricGroup,
                                     l_peerProcInfoIt->procFabricChip,
                                     l_peerProcInfoIt->iv_deconfigured,
                                     l_peerProcInfoIt->iv_masterCapable );
                            inGroupBusIndex++;
                        }
                        // If subsystem owns SMPA deconfigs consider them
                        else if (l_peerProcInfoIt->procFabricGroup != l_currentProcInfoIt->procFabricGroup)
                        {
                            HWAS_ASSERT(outGroupBusIndex < NUM_OUT_GROUP_BUSES,
                                        "Number of out-group bus connections %d exceeds maximum allowed: %d",
                                        outGroupBusIndex, NUM_OUT_GROUP_BUSES);
                            (*l_currentProcInfoIt).iv_pOutGroupProcInfos[outGroupBusIndex] = &(*l_peerProcInfoIt);
                            // HWAS state
                            l_currentProcInfoIt->iv_OutGroupLinkDeconfigured[outGroupBusIndex] =
                                !(isFunctional(l_currentEndpointTarget));
                            HWAS_INF("PROC 0x%.8X add %.8X Bus Deconfig=%d; out-group bus[%d]> %.8X : Group=%d, Chip=%d, Deconfigured=%d, Master=%d",
                                     l_currentProcInfoIt->procHUID,
                                     l_currentEndpointTarget->getAttr<ATTR_HUID>(),
                                     l_currentProcInfoIt->iv_OutGroupLinkDeconfigured[outGroupBusIndex],
                                     outGroupBusIndex,
                                     l_peerProcInfoIt->procHUID,
                                     l_peerProcInfoIt->procFabricGroup,
                                     l_peerProcInfoIt->procFabricChip,
                                     l_peerProcInfoIt->iv_deconfigured,
                                     l_peerProcInfoIt->iv_masterCapable);
                            outGroupBusIndex++;
                        }
                        break;
                    }
                }
            }
        }

        // call _deconfigureAssocProc() to run deconfig algorithm
        // based on current state of system obtained above
        l_pErr = _deconfigureAssocProc(l_procInfo);
        if (l_pErr)
        {
            HWAS_ERR("Error from _deconfigureAssocProc ");
            break;
        }

        // Iterate through l_procInfo and deconfigure any procs
        // which _deconfigureAssocProc marked for deconfiguration
        for (ProcInfoVector::const_iterator
             l_procInfoIter = l_procInfo.begin();
             l_procInfoIter != l_procInfo.end();
             ++l_procInfoIter)
        {
            if ((*l_procInfoIter).iv_deconfigured &&
                (isFunctional((*l_procInfoIter).iv_pThisProc)))
            {
                // Deconfigure marked procs
                HWAS_INF("_invokeDeconfigureAssocProc is "
                                "deconfiguring proc: %.8X",
                    get_huid((*l_procInfoIter).iv_pThisProc));
                _deconfigureTarget(*(*l_procInfoIter).
                                iv_pThisProc, DECONFIGURED_BY_BUS_DECONFIG);
                _deconfigureByAssoc(*(*l_procInfoIter).
                                iv_pThisProc, DECONFIGURED_BY_BUS_DECONFIG);
            }
        }
    }while(0);

    return l_pErr;
} // _invokeDeconfigureAssocProc

/**
 * @brief Collects a list of processors that are not connected by any bus to
 *        the given processor.
 */
void DeconfigGard::_collectDisconnectedProcs(const ProcInfo* const i_proc,
                                             ProcInfo* const i_buses[],
                                             const bool* const i_deconfiguredInfo,
                                             const uint8_t i_num_buses,
                                             std::vector<ProcInfo*>& io_disconnectedProcs)
{
    // Maps a ProcInfo* to the number of functional buses that exist from i_proc
    // to the processor represented by that ProcInfo*.
    std::map<ProcInfo*, int> num_connections;

    // Iterate through bus endpoints and count the ones that are functional. If
    // the count of functional buses is zero then the processor is not connected
    // and we add it to the list of disconnected procs.
    for (uint8_t i = 0; i < i_num_buses; i++)
    {
        if (i_buses[i])
        {
            int is_connected = 0;

            if (!i_deconfiguredInfo[i])
            {
                is_connected = 1;
            }

            num_connections[i_buses[i]] += is_connected;
        }
    }

    for (const auto pair : num_connections)
    {
        if (pair.second == 0)
        {
            io_disconnectedProcs.push_back(pair.first);
        }
    }
}

//******************************************************************************
errlHndl_t DeconfigGard::_deconfigureAssocProc(ProcInfoVector &io_procInfo)
{
    // Defined for possible use in future applications
    errlHndl_t l_errlHdl = nullptr;

    do
    {
        // STEP 1:
        // Find master proc and iterate through its connected processors.
        // Mark as deconfigured any processor that is not connected to the
        // master processor.

        // Find master proc
        ProcInfo * l_pMasterProcInfo = nullptr;
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            if ( ((*l_procInfoIter).iv_masterCapable) &&
                 (!(*l_procInfoIter).iv_deconfigured) )
            {
                if (l_procInfoIter->iv_pThisProc->getAttr<ATTR_PROC_MASTER_TYPE>() != PROC_MASTER_TYPE_ACTING_MASTER)
                { // The first master-capable processor is not necessarily the acting master.
                    continue;
                }

                // Save for subsequent use
                l_pMasterProcInfo = &(*l_procInfoIter);

                std::vector<ProcInfo*> disconnected_procs;

                _collectDisconnectedProcs(l_pMasterProcInfo,
                                          l_pMasterProcInfo->iv_pOutGroupProcInfos,
                                          l_pMasterProcInfo->iv_OutGroupLinkDeconfigured,
                                          NUM_OUT_GROUP_BUSES,
                                          disconnected_procs);

                _collectDisconnectedProcs(l_pMasterProcInfo,
                                          l_pMasterProcInfo->iv_pInGroupProcInfos,
                                          l_pMasterProcInfo->iv_InGroupLinkDeconfigured,
                                          NUM_IN_GROUP_BUSES,
                                          disconnected_procs);

                for (auto proc = disconnected_procs.begin();
                     proc != disconnected_procs.end();
                     ++proc)
                {
                    HWAS_INF("deconfigureAssocProc marked proc: 0x%08x for deconfiguration in step 1 "
                             "due to deconfigured bus to master proc",
                             (*proc)->procHUID);
                    (*proc)->iv_deconfigured = true;
                }

                break;
            }
        } // STEP 1

        // If no master proc found, mark all proc as deconfigured
        if (l_pMasterProcInfo == nullptr)
        {
            HWAS_INF("deconfigureAssocProc: Master proc not found");
            // Iterate through procs, and mark deconfigured all proc
            for (ProcInfoVector::iterator
                     l_procInfoIter = io_procInfo.begin();
                     l_procInfoIter != io_procInfo.end();
                     ++l_procInfoIter)
            {
                (*l_procInfoIter).iv_deconfigured = true;
            }
            // break now since all of the rest of the processing is moot.
            break;
        }

        // STEP 2:
        // Iterate through procs, and mark deconfigured any non-master proc
        // which is disconnected from more than one other non-master proc
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Don't deconfigure master proc
            if ((*l_procInfoIter).iv_masterCapable)
            {
                continue;
            }
            // Don't examine previously marked proc
            if ((*l_procInfoIter).iv_deconfigured)
            {
                continue;
            }

            std::vector<ProcInfo*> disconnected_procs;

            _collectDisconnectedProcs(&*l_procInfoIter,
                                      l_procInfoIter->iv_pOutGroupProcInfos,
                                      l_procInfoIter->iv_OutGroupLinkDeconfigured,
                                      NUM_OUT_GROUP_BUSES,
                                      disconnected_procs);

            _collectDisconnectedProcs(&*l_procInfoIter,
                                      l_procInfoIter->iv_pInGroupProcInfos,
                                      l_procInfoIter->iv_InGroupLinkDeconfigured,
                                      NUM_IN_GROUP_BUSES,
                                      disconnected_procs);

            // Deconfigured proc chip counter
            int num_functional_disconnected_procs = 0;

            // Check and increment counter if A/X bus endpoints found
            // which are deconfigured
            for (auto proc = disconnected_procs.begin();
                 proc != disconnected_procs.end();
                 ++proc)
            {
                // Only increment deconfigBusCounter if peer proc exists
                // and is functional
                if (!(*proc)->iv_deconfigured)
                {
                    HWAS_INF("deconfigureAssocProc: The configured processor 0x%08x is not attached "
                             "to 0x%08x in step 2",
                             (*proc)->procHUID,
                             l_procInfoIter->procHUID);
                    ++num_functional_disconnected_procs;
                }
            }

            if (num_functional_disconnected_procs > 1)
            {
                HWAS_INF("deconfigureAssocProc: The processor 0x%08x has %d configured non-master "
                         "peers in step 2, marking deconfigured",
                         l_procInfoIter->procHUID,
                         num_functional_disconnected_procs);
                l_procInfoIter->iv_deconfigured = true;
            }
        }// STEP 2


        // STEP 3:
        // If a deconfigured bus connects two non-master procs,
        // both of which are in the master-containing logical group,
        // mark proc with higher HUID to be deconfigured.

        // Iterate through procs and check Bus[in-group] chiplets
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Master proc handled in STEP 1
            if ((*l_procInfoIter).iv_masterCapable)
            {
                continue;
            }
            // Don't examine previously marked proc
            if ((*l_procInfoIter).iv_deconfigured)
            {
                continue;
            }
            // If current proc is on master logical group
            if (l_pMasterProcInfo->procFabricGroup == (*l_procInfoIter).procFabricGroup)
            {
                std::vector<ProcInfo*> disconnected_procs;

                // Check Bus[in-group] endpoints
                _collectDisconnectedProcs(&*l_procInfoIter,
                                          l_procInfoIter->iv_pInGroupProcInfos,
                                          l_procInfoIter->iv_InGroupLinkDeconfigured,
                                          NUM_IN_GROUP_BUSES,
                                          disconnected_procs);

                for (auto proc = disconnected_procs.begin();
                     proc != disconnected_procs.end();
                     ++proc)
                {
                    if (!(*proc)->iv_deconfigured)
                    {
                        // Mark proc with higher HUID to be deconfigured
                        if ((*proc)->procHUID > l_procInfoIter->procHUID)
                        {
                            HWAS_INF("deconfigureAssocProc marked remote proc: %.8X for deconfiguration due to "
                                     "higher HUID than peer proc on same master-containing logical group.",
                                     (*proc)->procHUID);
                            (*proc)->iv_deconfigured = true;
                        }
                        else
                        {
                            HWAS_INF("deconfigureAssocProc marked proc: %.8X for deconfiguration due to "
                                     " higher HUID than peer proc on same master-containing logical group.",
                                     l_procInfoIter->procHUID);
                            l_procInfoIter->iv_deconfigured = true;
                        }
                    }
                }
            }
        }// STEP 3


        // STEP 4:
        // If a deconfigured bus connects two procs, both in the same
        // non-master-containing logical group, mark current proc
        // deconfigured if there is a same position proc marked deconfigured
        // in the master logical group, else mark remote proc if there is
        // a same position proc marked deconfigured in the master logical
        // group otherwise, mark the proc with the higher HUID.

        // Iterate through procs and, if in non-master
        // logical group, check Bus[in-group] chiplets
        for (ProcInfoVector::iterator l_procInfoIter = io_procInfo.begin();
             l_procInfoIter != io_procInfo.end();
             ++l_procInfoIter)
        {
            // Don't examine previously marked proc
            if ((*l_procInfoIter).iv_deconfigured)
            {
                continue;
            }
            // Don't examine procs on master logical group
            if (l_pMasterProcInfo->procFabricGroup == (*l_procInfoIter).procFabricGroup)
            {
                continue;
            }

            std::vector<ProcInfo*> disconnected_procs;

            // Check Bus "In Group" because they connect procs which
            // are in the same logical group
            _collectDisconnectedProcs(&*l_procInfoIter,
                                      l_procInfoIter->iv_pInGroupProcInfos,
                                      l_procInfoIter->iv_InGroupLinkDeconfigured,
                                      NUM_IN_GROUP_BUSES,
                                      disconnected_procs);

            for (auto proc = disconnected_procs.begin();
                 proc != disconnected_procs.end();
                 ++proc)
            {
                if (!(*proc)->iv_deconfigured)
                {
                    // Variable to indicate If this step results in
                    // finding a proc to mark deconfigured
                    bool l_chipIDmatch = false;
                    // Iterate through procs and examine ones found to
                    // be on the master-containing logical group
                    for (ProcInfoVector::const_iterator l_mGroupProcInfoIter = io_procInfo.begin();
                         l_mGroupProcInfoIter != io_procInfo.end();
                         ++l_mGroupProcInfoIter)
                    {
                        if (l_pMasterProcInfo->procFabricGroup == (*l_mGroupProcInfoIter).procFabricGroup)
                        {
                            // If master logical group proc deconfigured with
                            // same FABRIC_CHIP_ID as current proc
                            if (l_mGroupProcInfoIter->iv_deconfigured &&
                                l_mGroupProcInfoIter->procFabricChip == l_procInfoIter->procFabricChip)
                            {
                                // Mark current proc to be deconfigured
                                // and set chipIDmatch
                                HWAS_INF("deconfigureAssocProc marked proc: %.8X for deconfiguration due to same position "
                                         "deconfigured proc on master-containing logical group.",
                                         l_procInfoIter->procHUID);
                                l_procInfoIter->iv_deconfigured = true;
                                l_chipIDmatch = true;
                                break;
                            }
                            // If master logical group proc deconfigured with
                            // same FABRIC_CHIP_ID as current proc's Bus[in-group] peer
                            // proc
                            else if (l_mGroupProcInfoIter->iv_deconfigured
                                     && l_mGroupProcInfoIter->procFabricChip == (*proc)->procFabricChip)
                            {
                                // Mark peer proc to be deconfigured
                                // and set chipIDmatch
                                HWAS_INF("deconfigureAssocProc marked remote proc: %.8X for deconfiguration due to "
                                         "same position deconfigured proc on master-containing logical group.",
                                         (*proc)->procHUID);
                                (*proc)->iv_deconfigured = true;
                                l_chipIDmatch = true;
                                break;
                            }
                        }
                    }
                    // If previous step did not find a proc to mark
                    if (!l_chipIDmatch)
                    {
                        // Deconfigure proc with higher HUID
                        if (l_procInfoIter->procHUID > (*proc)->procHUID)
                        {
                            HWAS_INF("deconfigureAssocProc marked proc:"
                                     " %.8X for deconfiguration "
                                     "due to higher HUID than peer "
                                     "proc on same non master-containing logical "
                                     "group.",
                                     l_procInfoIter->procHUID);
                            l_procInfoIter->iv_deconfigured = true;
                        }
                        else
                        {
                            HWAS_INF("deconfigureAssocProc marked remote proc:"
                                     " %.8X for deconfiguration "
                                     "due to higher HUID than peer "
                                     "proc on same non master-containing logical "
                                     "group.",
                                     (*proc)->procHUID);
                            (*proc)->iv_deconfigured = true;
                        }
                    }
                }
            }
        }// STEP 4

        // STEP 5:
        // If a deconfigured bus connects two procs on different logical groups,
        // and neither proc is the master proc: If current proc's Bus[in-group] peer
        // proc is marked as deconfigured, mark current proc. Else, mark
        // Bus[out-group] peer proc.

        // Iterate through procs and check for deconfigured Bus[out-group] endpoints
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Master proc handled in STEP 1
            if ((*l_procInfoIter).iv_masterCapable)
            {
                continue;
            }
            // Don't examine procs which are already marked
            if ((*l_procInfoIter).iv_deconfigured)
            {
                continue;
            }

            std::vector<ProcInfo*> disconnected_procs_outgroup;

            // Check Bus "Out Group" buses because they connect procs which are in
            // different logical groups
            _collectDisconnectedProcs(&*l_procInfoIter,
                                      l_procInfoIter->iv_pOutGroupProcInfos,
                                      l_procInfoIter->iv_OutGroupLinkDeconfigured,
                                      NUM_OUT_GROUP_BUSES,
                                      disconnected_procs_outgroup);

            std::vector<ProcInfo*> disconnected_procs_ingroup;

            _collectDisconnectedProcs(&*l_procInfoIter,
                                      l_procInfoIter->iv_pInGroupProcInfos,
                                      l_procInfoIter->iv_InGroupLinkDeconfigured,
                                      NUM_IN_GROUP_BUSES,
                                      disconnected_procs_ingroup);

            for (auto outgroup_proc = disconnected_procs_outgroup.begin();
                 outgroup_proc != disconnected_procs_outgroup.end();
                 ++outgroup_proc)
            {
                if (!(*outgroup_proc)->iv_deconfigured)
                {
                    bool l_inGroupBusPeerProcDeconfigured = false;

                    // Check XBUS peer
                    for (auto ingroup_proc = disconnected_procs_ingroup.begin();
                         ingroup_proc != disconnected_procs_ingroup.end();
                         ++ingroup_proc)
                    {
                        // If Bus[in-group] peer proc deconfigured
                        if ((*ingroup_proc)->iv_deconfigured)
                        {
                            HWAS_INF("deconfigureAssocProc marked proc: "
                                     "0x%08x for deconfiguration due to deconfigured Bus[in-group] peer proc.",
                                     l_procInfoIter->procHUID);
                            l_inGroupBusPeerProcDeconfigured = true;
                            l_procInfoIter->iv_deconfigured = true;
                            break;
                        }
                    }

                    // If previous step did not result in marking a proc
                    // mark Bus[out-group] peer proc
                    if (!l_inGroupBusPeerProcDeconfigured)
                    {
                        // Don't deconfigure master proc
                        if (!(*outgroup_proc)->iv_masterCapable)
                        {
                            HWAS_INF("deconfigureAssocProc marked "
                                     "remote proc: 0x%08x for deconfiguration "
                                     "due to functional Bus[in-group] peer proc.",
                                     (*outgroup_proc)->procHUID);
                            (*outgroup_proc)->iv_deconfigured = true;
                        }
                    }
                }
            }
        }// STEP 5
    }while(0);
    if (!l_errlHdl)
    {
        // Perform SMP group balancing
        l_errlHdl = _symmetryValidation(io_procInfo);
    }
    return l_errlHdl;
} // _deconfigureAssocProc

//******************************************************************************
errlHndl_t DeconfigGard::_symmetryValidation(ProcInfoVector &io_procInfo)
{
    // Defined for possible use in future applications
    errlHndl_t l_errlHdl = nullptr;

    HWAS_INF("_symmetryValidation - entry");

    // Perform SMP group balancing
    do
    {
        Target* pSys;
        targetService().getTopLevelTarget(pSys);
        HWAS_ASSERT(pSys, "HWAS _symmetryValidation: no TopLevelTarget");
        if ( pSys->getAttr<TARGETING::ATTR_PROC_FABRIC_BROADCAST_MODE>() ==
             TARGETING::PROC_FABRIC_BROADCAST_MODE_1HOP_CHIP_IS_GROUP )
        {
          // When CHIP_IS_GROUP is set, that means a single fabric CHIP
          // per GROUP (or NODE). If we apply symmetry deconfig, it will
          // deconfig all the other chips because they all have the same
          // relative position to group.

          break;
        }

        // STEP 1:
        // If a proc is deconfigured in a logical group
        // containing the master proc, iterate through all procs
        // and mark as deconfigured those in other logical groups
        // with the same FABRIC_CHIP_ID (procFabricChip)

        // Find master proc
        ProcInfo * l_pMasterProcInfo = nullptr;
        for (ProcInfoVector::iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // If master proc
            if ((*l_procInfoIter).iv_masterCapable)
            {
                if (l_procInfoIter->iv_pThisProc->getAttr<ATTR_PROC_MASTER_TYPE>() != PROC_MASTER_TYPE_ACTING_MASTER)
                { // The first master-capable processor is not necessarily the acting master.
                    continue;
                }

                // Save for subsequent use
                l_pMasterProcInfo = &(*l_procInfoIter);
                break;
            }
        }
        // If no master proc found, abort
        HWAS_ASSERT(l_pMasterProcInfo, "HWAS _symmetryValidation:"
                                       "Master proc not found");
        // Iterate through procs and check if in master logical group
        for (ProcInfoVector::const_iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // Skip master proc
            if ((*l_procInfoIter).iv_masterCapable)
            {
                continue;
            }
            // If current proc is on master logical group
            // and marked as deconfigured
            if ((l_pMasterProcInfo->procFabricGroup ==
                (*l_procInfoIter).procFabricGroup) &&
                ((*l_procInfoIter).iv_deconfigured))
            {
                // Iterate through procs and mark any same-
                // position procs as deconfigured
                for (ProcInfoVector::iterator
                     l_posProcInfoIter = io_procInfo.begin();
                     l_posProcInfoIter != io_procInfo.end();
                     ++l_posProcInfoIter)
                {
                    if ((*l_procInfoIter).procFabricChip ==
                        (*l_posProcInfoIter).procFabricChip)
                    {
                        HWAS_INF("symmetryValidation step 1 marked proc: "
                             "%.8X for deconfiguration. Previously marked %d",
                           (*l_posProcInfoIter).procHUID,
                           (*l_posProcInfoIter).iv_deconfigured?1:0);
                        (*l_posProcInfoIter).iv_deconfigured = true;
                    }
                }
            }
        }// STEP 1

        // STEP 2:
        // If a deconfigured proc is found on a non-master-containing group
        // and has the same position (FABRIC_CHIP_ID) as a functional
        // non-master chip on the master logical group,
        // mark its Bus[in-group] peer proc(s) for deconfiguration

        // Iterate through procs, if marked deconfigured, compare chip
        // position to functional chip on master group.
        for (ProcInfoVector::const_iterator
                 l_procInfoIter = io_procInfo.begin();
                 l_procInfoIter != io_procInfo.end();
                 ++l_procInfoIter)
        {
            // If proc is marked deconfigured
            if ((*l_procInfoIter).iv_deconfigured)
            {
                // Iterate through procs, examining those on
                // the master logical group
                for (ProcInfoVector::const_iterator
                     l_mGroupProcInfoIter = io_procInfo.begin();
                     l_mGroupProcInfoIter != io_procInfo.end();
                     ++l_mGroupProcInfoIter)
                {
                    // If proc found is on the master-containing logical group
                    // functional, and matches the position of the deconfigured
                    // proc from the outer loop
                    if ((l_pMasterProcInfo->procFabricGroup ==
                        (*l_mGroupProcInfoIter).procFabricGroup) &&
                        (!((*l_mGroupProcInfoIter).iv_deconfigured)) &&
                        ((*l_mGroupProcInfoIter).procFabricChip ==
                                (*l_procInfoIter).procFabricChip))
                    {
                        // Find Bus[in-group] peer proc to mark deconfigured
                        for (uint8_t i = 0; i < NUM_IN_GROUP_BUSES; i++)
                        {
                            // If Bus[in-group] peer proc exists, mark it
                            if ((*l_procInfoIter).iv_pInGroupProcInfos[i])
                            {
                                HWAS_INF( "procs> %.8X : G=%d, C=%d, D=%d, M=%d", (*l_procInfoIter).procHUID, (*l_procInfoIter).procFabricGroup, (*l_procInfoIter).procFabricChip, (*l_procInfoIter).iv_deconfigured, (*l_procInfoIter).iv_masterCapable );
                                HWAS_INF( "mGroup> %.8X : G=%d, C=%d, D=%d, M=%d", (*l_mGroupProcInfoIter).procHUID, (*l_mGroupProcInfoIter).procFabricGroup, (*l_mGroupProcInfoIter).procFabricChip, (*l_mGroupProcInfoIter).iv_deconfigured, (*l_mGroupProcInfoIter).iv_masterCapable );
                                HWAS_INF( "Bus[in-group]%d> %.8X : G=%d, C=%d, D=%d, M=%d", i,  (*l_procInfoIter).iv_pInGroupProcInfos[i]->procHUID, (*l_procInfoIter).iv_pInGroupProcInfos[i]->procFabricGroup, (*l_procInfoIter).iv_pInGroupProcInfos[i]->procFabricChip, (*l_procInfoIter).iv_pInGroupProcInfos[i]->iv_deconfigured, (*l_procInfoIter).iv_pInGroupProcInfos[i]->iv_masterCapable );

                                // If the chip we found is the master then do NOT
                                //  deconfigure it
                                if( (*l_procInfoIter).iv_pInGroupProcInfos[i]->iv_masterCapable )
                                {
                                    HWAS_INF( "Skipping deconfig of master proc %.8X", l_pMasterProcInfo->procHUID );
                                }
                                else
                                {
                                    HWAS_INF("symmetryValidation step 2 "
                                             "marked proc: %.8X for "
                                             "deconfiguration.",
                                             (*l_procInfoIter).
                                             iv_pInGroupProcInfos[i]->procHUID);
                                    (*l_procInfoIter).iv_pInGroupProcInfos[i]->
                                        iv_deconfigured = true;
                                }
                            }
                        }
                    }
                }
            }
        }// STEP 2
    }while(0);
    return l_errlHdl;
} // _symmetryValidation

//******************************************************************************
void updateAttrPG(Target& i_target, const bool i_shouldSetFunctional)
{
    Target* const l_perv = getTargetWithPGAttr(i_target);

    if (l_perv)
    {
        const pg_entry_t l_old_ATTR_PG_mask = l_perv->getAttr<ATTR_PG>();

        // Get masked PG value
        const pg_entry_t l_new_ATTR_PG_mask =
            getDeconfigMaskedPGValue(i_target);

        // Apply the mask, either straight-way or else inverted depending on
        // whether this target is being enabled or disabled.

        if (!i_shouldSetFunctional)
        {
            l_perv->setAttr<ATTR_PG>(l_old_ATTR_PG_mask | l_new_ATTR_PG_mask);
        }
        else
        {
            l_perv->setAttr<ATTR_PG>(l_old_ATTR_PG_mask & ~l_new_ATTR_PG_mask);
        }
    }

} // updateAttrPG

//******************************************************************************
pg_entry_t getDeconfigMaskedPGValue(const Target& i_target)
{
    using namespace PARTIAL_GOOD;

    // This structure holds a deconfiguration rule that applies a mask to the
    // ATTR_PG bits of the given target type when the target is not functional
    // or present.
    struct target_deconfig_rule
    {
        TYPE targetType;
        pg_entry_t deconfigureMask;
    };

    // Bits used by ATTR_PG to indicate deconfigured targets (reference: P10
    // Partial Good Keyword document)
    const pg_mask_t N1_S_NMMU_BIT = 0x00004000; // NMMU bit in N1_S chiplet

    // The list of rules that are not already contained in the partial-good
    // logic. When there are multiple rules that apply to the same target type,
    // they should be adjacent in this array.
    static const target_deconfig_rule l_deconfigRules[] =
    {
        { TYPE_PAUC, VPD_CP00_PG_PAUC_ALWAYS_GOOD_MASK },
        { TYPE_NMMU, N1_S_NMMU_BIT },
        { TYPE_EQ,   VPD_CP00_PG_EQ_ALWAYS_GOOD_MASK },
    };

    const auto l_targetType = i_target.getAttr<ATTR_TYPE>();

    auto l_deconfigRule
        = std::find_if(std::begin(l_deconfigRules),
                       std::end(l_deconfigRules),
                       [l_targetType](const target_deconfig_rule& rule)
                       {
                           return l_targetType == rule.targetType;
                       });

    const auto l_chipUnit = i_target.getAttr<ATTR_CHIP_UNIT>();

    // We will build this mask up from the rules in the array
    // above (target_deconfig_rule), along with the rules specified in the
    // partial-good logic (pgLogic.C)
    pg_entry_t l_attrPGMask = 0;

    // Loop through l_deconfigRules and apply all the relevant ones
    while ((l_deconfigRule != std::end(l_deconfigRules))
           && (l_deconfigRule->targetType == l_targetType))
    {
        l_attrPGMask |= l_deconfigRule->deconfigureMask;
        ++l_deconfigRule;
    }

    // Now iterate the relevant partial-good rules and accumulate our mask
    size_t l_numPgRules = 0;
    const PartialGoodRule* l_pgRule_it = nullptr;

    auto l_errl = findRulesForTarget(&i_target, l_pgRule_it, l_numPgRules);

    if (l_errl)
    {
        errlCommit(l_errl, HWAS_COMP_ID);
    }
    else
    {
        while (l_numPgRules-- != 0)
        {
            if (l_pgRule_it->isApplicableToCurrentModel()
                && l_pgRule_it->isApplicableToChipUnit(l_chipUnit))
            {
                l_attrPGMask |= l_pgRule_it->partialGoodMask();
            }

            ++l_pgRule_it;
        }
    }

    return l_attrPGMask;
} // getDeconfigMaskedPGValue

//******************************************************************************
// NON-RUNTIME methods
//******************************************************************************

#ifndef __HOSTBOOT_RUNTIME
//******************************************************************************
errlHndl_t collectGard(const PredicateBase *i_pPredicate)
{
    HWAS_DBG("collectGard entry" );
    errlHndl_t errl = nullptr;

    do
    {
        errl = theDeconfigGard().clearGardRecordsForReplacedTargets();
        if (errl)
        {
            HWAS_ERR("ERROR: collectGard failed to clear GARD Records for replaced Targets");
            break;
        }

        (void)theDeconfigGard().clearFcoDeconfigures();

        errl = theDeconfigGard().
                    deconfigureTargetsFromGardRecordsForIpl(i_pPredicate);
        if (errl)
        {
            HWAS_ERR("ERROR: collectGard failed to deconfigure Targets from GARD Records for IPL");
            break;
        }

#ifdef __HOSTBOOT_MODULE
        errl = theDeconfigGard().platProcessFieldCoreOverride();
        if (errl)
        {
            HWAS_ERR("ERROR: collectGard failed to process Field Core Override");
            break;
        }
#endif
    }
    while(0);

    if (errl)
    {
        HWAS_ERR("collectGard failed (plid 0x%X)", errl->plid());
    }
    else
    {
        HWAS_INF("collectGard completed successfully");
    }
    return errl;
} // collectGard

//******************************************************************************
errlHndl_t clearGardByType(const GARD_ErrorType i_type)
{
    return theDeconfigGard().clearGardRecordsByType(i_type);
}

//******************************************************************************
errlHndl_t DeconfigGard::applyGardRecord(Target *i_pTarget,
        GardRecord &i_gardRecord,
        const DeconfigureFlags i_deconfigRule)
{
    HWAS_INF("Apply gard record for target %.8X, gard type 0x%.X",
              get_huid(i_pTarget), i_gardRecord.iv_errorType);
    errlHndl_t l_pErr = nullptr;
    do
    {
        // skip if not present
        if (!i_pTarget->getAttr<ATTR_HWAS_STATE>().present)
        {
            HWAS_INF("skipping %.8X - target not present",
                        get_huid(i_pTarget));
            l_pErr = platLogEvent(i_pTarget, GARD_NOT_APPLIED);
            if (l_pErr)
            {
                    HWAS_ERR("platLogEvent returned an error");
            }
            break;
        }

        // special case - use errlogEid UNLESS it's a Manual Gard
        uint32_t l_errlogEid =
                (i_gardRecord.iv_errorType == GARD_User_Manual) ?
                    DECONFIGURED_BY_MANUAL_GARD : i_gardRecord.iv_errlogEid;

        // all ok - do the work
        HWAS_MUTEX_LOCK(iv_mutex);

#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
        // Don't emit a console message if the GARD type is considered a
        //  Deconfig GARD record. Emitting a message as if a GARD is being
        //  applied in that case leads to confusion since its actually just
        //  used as a means to remember to deconfig.
        // Similarly, there should be no message as we're speculatively acting
        //  on the gard records since the message will either be redundant
        //  with the real apply we do later or it will be misleading when we
        //  do not actually deconfigure the part.
        if(!isDeconfigGard(i_gardRecord.iv_errorType) && (i_deconfigRule != SPEC_DECONFIG) )
        {
            const char* l_tmpstring =
              i_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();
            CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "Applying GARD record for HUID=0x%08X (%s) due to 0x%.8X",
                        get_huid(i_pTarget),
                        l_tmpstring,
                        l_errlogEid);
            free((void*)(l_tmpstring));
            l_tmpstring = nullptr;
        }
#endif

        // Deconfigure the Target
        // don't need to check ATTR_DECONFIG_GARDABLE -- if we get
        // here, it's because of a gard record on this target
        _deconfigureTarget(*i_pTarget, l_errlogEid, nullptr, i_deconfigRule);

        // Deconfigure other Targets by association
        _deconfigureByAssoc(*i_pTarget, l_errlogEid, i_deconfigRule);

        HWAS_MUTEX_UNLOCK(iv_mutex);

        // Need to set GARD_APPLIED bit for all garded targets
        // Also need to set DIAG_MASK to force diagnostics to run if the part
        //  is unguarded later.
        update_hwas_changed_mask(i_pTarget,
                                 HWAS_CHANGED_BIT_GARD_APPLIED
                                 | HWAS_CHANGED_BIT_DIAG_MASK);

        if(i_deconfigRule == SPEC_DECONFIG)
        {
            HWAS_INF(
                "Skip platLogEvent(GARD_APPLIED) and platCreateGardRecord(GARD_Reconfig) for spec_deconfig target %.8X",
                get_huid(i_pTarget));
            break;
        }

#ifdef __HOSTBOOT_MODULE
        // only create deconfig gard records for BMC systems
        if(!INITSERVICE::spBaseServicesEnabled())
        {
            // if ATTR_BLOCK_SPEC_DECONFIG is set for any node, make the gard type GARD_Sticky_deconfig,
            // otherwise set to GARD_Reconfig
            GARD_ErrorType gardDeconfig = isBlockSpecDeconfigSetOnAnyNode() ? GARD_Sticky_deconfig : GARD_Reconfig;
            HWAS_INF("call platCreateGardRecord to create a deconfig record for the garded target %.8X",
                     get_huid(i_pTarget));
            l_pErr = HWAS::theDeconfigGard().platCreateGardRecord(i_pTarget,
                                                                  l_errlogEid,
                                                                  gardDeconfig);
            if (l_pErr)
            {
                HWAS_ERR("platCreateGardRecord returned an error creating a Deconfig Gard record for %.8X",
                         get_huid(i_pTarget));
                // if the error was caused by the gard record repository being full,
                // reset RECONFIGURE_LOOP_DECONFIGURE bit, so that we do not trigger
                // a reconfig loop at the end of the istep for any gard records applied
                // for error logs that came from prior ipls. If we do not reset this
                // attr, this will lead to infinite reconfig loops at the end of the
                // istep
                if (l_pErr->reasonCode() == HWAS::RC_GARD_REPOSITORY_FULL)
                {
                    Target* l_pTopLevel = UTIL::assertGetToplevelTarget();
                    ATTR_RECONFIGURE_LOOP_type l_reconfigAttr =
                        l_pTopLevel->getAttr<ATTR_RECONFIGURE_LOOP>();
                    // Turn off deconfigure bit
                    l_reconfigAttr &= ~RECONFIGURE_LOOP_DECONFIGURE;
                    // Write back to attribute
                    l_pTopLevel->setAttr<ATTR_RECONFIGURE_LOOP>(l_reconfigAttr);
                }

                break;
            }
        }
#endif

        l_pErr = platLogEvent(i_pTarget, GARD_APPLIED);
        if (l_pErr)
        {
            HWAS_ERR("platLogEvent returned an error");
            break;
        }
    }
    while(0);
    return l_pErr;
}//applyGardRecord

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecordsForReplacedTargets()
{
    HWAS_INF("Clear GARD Records for replaced Targets");
    errlHndl_t l_pErr = nullptr;

    // Create the predicate with HWAS changed state and our GARD bit
    PredicateHwasChanged l_predicateHwasChanged;
    l_predicateHwasChanged.changedBit(HWAS_CHANGED_BIT_GARD, true);
    std::vector<uint32_t> l_gardedRecordEids;

    do
    {
        GardRecords_t l_gardRecords;
        l_pErr = platGetGardRecords(nullptr, l_gardRecords);
        if (l_pErr)
        {
            HWAS_ERR("Error from platGetGardRecords");
            break;
        }

        // For each GARD Record
        for (GardRecordsCItr_t l_itr = l_gardRecords.begin();
             l_itr != l_gardRecords.end();
             ++l_itr)
        {
            GardRecord l_gardRecord = *l_itr;

            // Find the associated Target
            Target* l_pTarget = targetService().
                            toTarget(l_gardRecord.iv_targetId);

            if (l_pTarget == nullptr)
            {
                // could be a platform specific target for the other
                // ie, we are hostboot and this is an FSP target, or vice-versa
                HWAS_INF_BIN("Could not find Target for:",
                             &(l_gardRecord.iv_targetId),
                             sizeof(l_gardRecord.iv_targetId));

                // we just skip this GARD record
                continue;
            }

            // if target is unchanged, continue to next in loop
            if (l_predicateHwasChanged(l_pTarget) == false)
            {
                HWAS_INF("skipping %.8X - GARD changed bit false",
                        get_huid(l_pTarget));
                continue;
            }

            // if record is USER garded then don't clear it here and
            // continue to next in loop
            if (l_gardRecord.iv_errorType == GARD_User_Manual)
            {
                HWAS_INF("skipping %.8X - GARD user manual",
                        get_huid(l_pTarget));
                continue;
            }

            // we have made it this far so we know the target has changed
            // requiring its gard record to be cleared and eid stored
            // Clear the gard record

            ATTR_HWAS_STATE_CHANGED_FLAG_type l_actual =
              l_pTarget->getAttr<ATTR_HWAS_STATE_CHANGED_FLAG>();

            ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK_type l_subscriptionMask =
              l_pTarget->getAttr<ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK>();

            uint64_t * l_pPred =
               reinterpret_cast<uint64_t *>(&l_predicateHwasChanged);
            uint64_t * l_pPred_iv_desired = l_pPred + 1;
            uint64_t * l_pPred_iv_valid = l_pPred + 2;

            HWAS_INF( "clearGardRecordsForReplacedTargets() "
                      "HUID :0x%08X, "
                      "predicate ATTR_HWAS_STATE_CHANGED_FLAG "
                      "iv_valid : 0x%08X%08X, "
                      "predicate ATTR_HWAS_STATE_CHANGED_FLAG "
                      "iv_desired : 0x%08X%08X, "
                      "Target ATTR_HWAS_STATE_CHANGED_FLAG : 0x%08X%08X, "
                      "Target ATTR_HWAS_STATE_CHANGED_SUBSCRIPTION_MASK "
                      ": 0x%08X%08X ",
                      get_huid(l_pTarget),
                      (*l_pPred_iv_valid) >> 32, (*l_pPred_iv_valid),
                      (*l_pPred_iv_desired) >> 32, (*l_pPred_iv_desired),
                      l_actual >> 32, l_actual,
                      l_subscriptionMask >> 32, l_subscriptionMask );

            HWAS_INF("clearing GARD for %.8X, recordId %d",
                        get_huid(l_pTarget),
                        l_gardRecord.iv_recordId);

            l_pErr = platClearGardRecords(l_pTarget);
            if (l_pErr)
            {
                HWAS_ERR("Error from platClearGardRecords");
                break;
            }
            // add gardRecord eid to vector so we can clear other records with
            // the same eid
            l_gardedRecordEids.push_back(l_gardRecord.iv_errlogEid);
        } // for

        if(!l_pErr)
        {
            // Second pass over present gard records to look for Errlog Ids
            GardRecords_t l_gardRecordsSecond;
            l_pErr = platGetGardRecords(nullptr, l_gardRecordsSecond);
            if (l_pErr)
            {
                HWAS_ERR("Error from platGetGardRecords");
                break;
            }
            //PASS TWO: Check for other like error log Ids
            for(GardRecordsCItr_t l_itr = l_gardRecordsSecond.begin();
                    l_itr != l_gardRecordsSecond.end();
                    ++l_itr)
            {
                GardRecord l_gardRecord = *l_itr;

                // Find the associated Target
                Target* l_pTarget = targetService().
                                toTarget(l_gardRecord.iv_targetId);

                if (l_pTarget == nullptr)
                {
                    // could be a platform specific target for the other
                    // ie, we are hostboot and this is an FSP target,
                    // or vice-versa
                    HWAS_INF_BIN("Could not find Target for:",
                                 &(l_gardRecord.iv_targetId),
                                 sizeof(l_gardRecord.iv_targetId));

                    // we just skip this GARD record
                    continue;
                }

                if (l_gardRecord.iv_errorType == GARD_User_Manual)
                {
                    // do not clear user garded records
                    HWAS_INF("Still skipping USER garded record %08X",
                        get_huid(l_pTarget));

                    // skip this GARD record
                    continue;
                }

                // Compare the current GARD record against all the stored
                // EIDs from the first pass. If there is a match,
                // clear the GARD record.

                if(l_gardedRecordEids.end() != std::find(
                                                     l_gardedRecordEids.begin(),
                                                     l_gardedRecordEids.end(),
                                                     l_gardRecord.iv_errlogEid))
                {
                    // we have found a gard record that has a matching EID
                    // as something else that has been cleared, so clear
                    // GARD record.
                    HWAS_INF("clearing GARD for %08x, recordId %d due to"
                             " matching EID of %08x",
                                get_huid(l_pTarget),
                                l_gardRecord.iv_recordId,
                                l_gardRecord.iv_errlogEid);
                    l_pErr = platClearGardRecords(l_pTarget);

                    if (l_pErr)
                    {
                        HWAS_ERR("Error from platClearGardRecords");
                        break;
                    }
                }
            }
        }
        // now we need to go thru and clear all of the GARD bits in the
        // changed flags for all targets
        for (TargetIterator t_iter = targetService().begin();
                t_iter != targetService().end();
                ++t_iter)
        {
            Target* l_pTarget = *t_iter;

            if (l_predicateHwasChanged(l_pTarget))
            {
                clear_hwas_changed_bit(l_pTarget,HWAS_CHANGED_BIT_GARD);
            }
        }
    }
    while (0);

    return l_pErr;
} // clearGardRecordsForReplacedTargets

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecordsByType(const GARD_ErrorType i_type)
{
    HWAS_INF("Clear GARD Records by type %x", i_type);
    errlHndl_t l_pErr = nullptr;

    do
    {
        GardRecords_t l_gardRecords;
        l_pErr = platGetGardRecords(nullptr, l_gardRecords);
        if (l_pErr)
        {
            HWAS_ERR("Error from platGetGardRecords");
            break;
        }

        // For each GARD Record
        for (const auto & l_gardRecord : l_gardRecords)
        {
            //If this is the type to clear
            if(l_gardRecord.iv_errorType == i_type)
            {
                // Find the associated Target
                Target* l_pTarget = targetService().
                  toTarget(l_gardRecord.iv_targetId);

                if (l_pTarget == nullptr)
                {
                    // could be a platform specific target for the other
                    // ie, we are hostboot and this is an FSP target, or
                    // vice-versa
                    // we just skip this GARD record
                    continue;
                }

                l_pErr = clearGardRecords(l_pTarget, isDeconfigGard(i_type));
                if (l_pErr)
                {
                    HWAS_ERR("Error from platClearGardRecords");
                    break;
                }

            }
        }
    }
    while (0);

    return l_pErr;
} // clearGardRecordsByType

//******************************************************************************
errlHndl_t DeconfigGard::updateSpecDeconfigTargetStates(
        const PredicateBase *i_pPredicate)
{
    errlHndl_t l_pErr = nullptr;

    do
    {
        // It is a caller error if this function is called and spec deconfig
        // is not enabled.
        // Get all node targets
        TargetHandleList l_nodelist;
        getEncResources(l_nodelist, TARGETING::TYPE_NODE,
                        TARGETING::UTIL_FILTER_FUNCTIONAL);
        ATTR_BLOCK_SPEC_DECONFIG_type l_blockSet = 0;
        for( auto l_node : l_nodelist )
        {
            l_blockSet |= l_node->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
        }
        HWAS_ASSERT((l_blockSet),
                    "HWAS updateSpecDeconfigTargetStates: "
                    "ATTR_BLOCK_SPEC_DECONFIG != 1 on any node");

        // Get all GARD Records
        GardRecords_t l_gardRecords;
        l_pErr = platGetGardRecords(nullptr, l_gardRecords);
        if (l_pErr)
        {
            HWAS_ERR("Error from platGetGardRecords");
            break;
        }

        for (GardRecordsCItr_t l_itr = l_gardRecords.begin();
             (l_itr != l_gardRecords.end());
             ++l_itr)
        {
            GardRecord l_gardRecord = *l_itr;

            // Find the associated Target
            Target * l_pTarget =
                targetService().toTarget(l_gardRecord.iv_targetId);

            if (l_pTarget == nullptr)
            {
                // could be a platform specific target for the other
                // ie, we are hostboot and this is an FSP target, or vice-versa
                // Binary trace the iv_targetId (EntityPath)
                HWAS_INF_BIN("Could not find Target for:",
                             &(l_gardRecord.iv_targetId),
                             sizeof(l_gardRecord.iv_targetId));
                continue;
            }

            // if this does NOT match, continue to next in loop
            if (i_pPredicate && ((*i_pPredicate)(l_pTarget) == false))
            {
                HWAS_INF("skipping %.8X - predicate didn't match",
                        get_huid(l_pTarget));
                continue;
            }

            // Since all GARD records have already been processed, if we find
            // any target that is functional, it means it has been resource
            // recovered. Update it's HWAS state to reflect this
            TARGETING::HwasState l_hwasState =
                    l_pTarget->getAttr<TARGETING::ATTR_HWAS_STATE>();
            if(l_hwasState.functional)
            {
                HWAS_INF("Found GARDED target 0x%08X is functional, set state",
                        TARGETING::get_huid(l_pTarget));
                l_hwasState.deconfiguredByEid =
                        DeconfigGard::CONFIGURED_BY_RESOURCE_RECOVERY;
                l_pTarget->setAttr<TARGETING::ATTR_HWAS_STATE>(l_hwasState);
            }
        }
    }while (0);

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::deconfigureTargetsFromGardRecordsForIpl(
        const PredicateBase *i_pPredicate)
{
    HWAS_INF("Deconfigure Targets from GARD Records for IPL");
    errlHndl_t l_pErr = nullptr;

    do
    {
        Target* pSys;
        targetService().getTopLevelTarget(pSys);
        HWAS_ASSERT(pSys, "HWAS deconfigTargetsFromGardRecordsForIpl: no TopLevelTarget");

        // check for system CDM Policy
        const ATTR_CDM_POLICIES_type l_sys_policy =
                pSys->getAttr<ATTR_CDM_POLICIES>();
        if (l_sys_policy & CDM_POLICIES_MANUFACTURING_DISABLED)
        {
            // manufacturing records are disabled
            //  - don't process
            HWAS_INF("Manufacturing policy: disabled - skipping GARD Records");
            l_pErr = platLogEvent(nullptr, MFG);
            if (l_pErr)
            {
                HWAS_ERR("platLogEvent returned an error");
            }
            break;
        }

#ifdef __HOSTBOOT_MODULE
        HWAS_INF("deconfigureTargetsFromGardRecordsForIpl: flushing the error log queue");
        ErrlManager::callFlushErrorLogs();
#endif

        // Get all GARD Records
        GardRecords_t l_gardRecords;
        l_pErr = platGetGardRecords(nullptr, l_gardRecords);
        if (l_pErr)
        {
            HWAS_ERR("Error from platGetGardRecords");
            break;
        }

        HWAS_DBG("%d GARD Records found", l_gardRecords.size());

        std::vector<uint32_t> errlLogEidList;
        //First apply all Unrecoverable or Fatal gard records and
        //check whether system is bootable, if not bootable
        //exit from this funtion or try to apply remaining records
        for (GardRecordsCItr_t l_itr = l_gardRecords.begin();
             l_itr != l_gardRecords.end();
             ++l_itr)
        {
            GardRecord l_gardRecord = *l_itr;

            // Find the associated Target
            Target * l_pTarget =
                targetService().toTarget(l_gardRecord.iv_targetId);

            if (l_pTarget == nullptr)
            {
                // could be a platform specific target for the other
                // ie, we are hostboot and this is an FSP target, or vice-versa
                // Binary trace the iv_targetId (EntityPath)
                HWAS_INF_BIN("Could not find Target for:",
                             &(l_gardRecord.iv_targetId),
                             sizeof(l_gardRecord.iv_targetId));
                continue;
            }

            bool l_isUnrecoverableGard = (l_gardRecord.iv_errorType == GARD_Fatal) ||
                                         (l_gardRecord.iv_errorType == GARD_Unrecoverable) ||
                                         (l_gardRecord.iv_errorType == GARD_Sticky_deconfig) ||
                                         (l_pTarget->getAttr<ATTR_TYPE>() == TYPE_NODE);
            // Only apply the record if it is Fatal, Unrecoverable,
            // Sticky_deconfig, or for a Node
            if (!l_isUnrecoverableGard)
            {
                //Skip applying the 'recoverable' record
                //and continue to the next record in l_gardRecords
                continue;
            }

            // if this does NOT match, continue to next in loop
            if (i_pPredicate && ((*i_pPredicate)(l_pTarget) == false))
            {
                HWAS_INF("skipping %.8X - predicate didn't match",
                        get_huid(l_pTarget));
                l_pErr = platLogEvent(l_pTarget, PREDICATE);
                if (l_pErr)
                {
                    HWAS_ERR("platLogEvent returned an error");
                    break;
                }
                continue;
            }

            l_pErr = applyGardRecord(l_pTarget, l_gardRecord);
            if (l_pErr)
            {
                HWAS_ERR("applyGardRecord returned an error");
                break;
            }
            uint32_t l_errlogEid = l_gardRecord.iv_errlogEid;
            //If the errlogEid is already in the errLogEidList, then
            //don't need to log it again as a single error log can
            //create multiple guard records and we only need to repost
            //it once.
            std::vector<uint32_t>::iterator low =
                    std::lower_bound(errlLogEidList.begin(),
                    errlLogEidList.end(), l_errlogEid);
            if((low == errlLogEidList.end()) || ((*low) != l_errlogEid))
            {
                errlLogEidList.insert(low, l_errlogEid);
                l_pErr = platReLogGardError(l_gardRecord);
                if (l_pErr)
                {
                    HWAS_ERR("platReLogGardError returned an error");
                    break;
                }
            }

#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
            const char* l_tmpstring =
              l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();
            CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "Deconfig HUID 0x%08X, %s due to 0x%.8X",
                    get_huid(l_pTarget),
                    l_tmpstring,
                    l_errlogEid);
            free((void*)(l_tmpstring));
            l_tmpstring = nullptr;
#endif
        } // for

        if (l_pErr)
        {
            HWAS_ERR("Error occured when applying Unrecoverable Guard records");
            break;
        }

        bool l_isSystemBootable = false;
        l_pErr = checkMinimumHardware(pSys,&l_isSystemBootable);
        if (l_pErr)
        {
            HWAS_ERR("checkMinimumHardware returned an error");
            break;
        }

        if(!l_isSystemBootable)
        {
            HWAS_ERR("System is not bootable after applying non recoverable gard records");
            break;
        }

        // Check if any targets have been replaced, and if so clear(set to 0)
        //Block Spec Deconfig
        TARGETING::ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig =
            clearBlockSpecDeconfigForReplacedTargets();

        l_pErr =
            clearBlockSpecDeconfigForUngardedTargets(l_block_spec_deconfig);
        if (l_pErr)
        {
            HWAS_ERR("clearBlockSpecDeconfigForUngardedTargets returned an error");
            break;
        }

        if(l_block_spec_deconfig != 0)
        {
#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
            CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "Blocking Speculative Deconfig");
#endif
            HWAS_INF("Blocking Speculative Deconfig: skipping Predictive GARD "
                     "and updating recovered resources");

            l_pErr = updateSpecDeconfigTargetStates(i_pPredicate);
            if(l_pErr)
            {
                HWAS_ERR("updateSpecDeconfigTargetStates returned an error");
                break;
            }
        }

        GardRecords_t l_specDeconfigVector;

        //If allowed, that is if Block Spec Deconfig is cleared,
        //loop through all gard records and apply recoverable
        //gard records(non Fatal and non Unrecoverable). Check
        //whether system can be booted after applying all gard
        //records. If system can't be booted after attempting to
        //applying gard records, then need to roll them back.
        for (GardRecordsCItr_t l_itr = l_gardRecords.begin();
             l_itr != l_gardRecords.end(); ++l_itr)
        {
            GardRecord l_gardRecord = *l_itr;
            // Find the associated Target
            Target * l_pTarget =
                targetService().toTarget(l_gardRecord.iv_targetId);

            if (l_pTarget == nullptr)
            {
                // could be a platform specific target for the other
                // ie, we are hostboot and this is an FSP target, or vice-versa
                // Binary trace the iv_targetId (EntityPath)
                HWAS_INF_BIN("Could not find Target for:",
                             &(l_gardRecord.iv_targetId),
                             sizeof(l_gardRecord.iv_targetId));
                continue;
            }

            bool l_isUnrecoverableGard = (l_gardRecord.iv_errorType == GARD_Fatal) ||
                                         (l_gardRecord.iv_errorType == GARD_Unrecoverable) ||
                                         (l_gardRecord.iv_errorType == GARD_Sticky_deconfig) ||
                                         (l_pTarget->getAttr<ATTR_TYPE>() == TYPE_NODE);
            // Skip apply the record if it is Fatal, Unrecoverable,
            // Sticky_deconfig, or for a Node
            if(l_isUnrecoverableGard)
            {
                //Skip applying the 'unrecoverable' record (since we already applied
                //them in the prior loop), and continue to the next record in l_gardRecords
                continue;
            }

            // if Block spec deconfig is set, write out to the console
            // which gard records are not being applied
            if (l_block_spec_deconfig == 1)
            {
                // use errlogEid UNLESS it's a Manual Gard
                uint32_t l_errlogEid = (l_gardRecord.iv_errorType == GARD_User_Manual) ?
                                        DECONFIGURED_BY_MANUAL_GARD : l_gardRecord.iv_errlogEid;
                const char* l_tmpstring =
                    l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();
#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
                CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "Skip applying %sGARD record for HUID=0x%08X (%s) due to 0x%.8X",
                                  isDeconfigGard(l_gardRecord.iv_errorType) ? "Deconfig " : "",
                                  get_huid(l_pTarget),
                                  l_tmpstring,
                                  l_errlogEid);
#endif
                HWAS_INF("Skip applying %sGARD record for HUID=0x%08X (%s) due to 0x%.8X",
                          isDeconfigGard(l_gardRecord.iv_errorType) ? "Deconfig " : "",
                          get_huid(l_pTarget),
                          l_tmpstring,
                          l_errlogEid);
                free((void*)(l_tmpstring));
                l_tmpstring = nullptr;

                continue;
            }

            if ((l_sys_policy & CDM_POLICIES_PREDICTIVE_DISABLED) &&
                (l_gardRecord.iv_errorType == GARD_Predictive))
            {
                // predictive records are disabled AND gard record is predictive
                //  - don't process
                HWAS_INF("Predictive policy: disabled - skipping GARD Record");
                l_pErr = platLogEvent(l_pTarget, PREDICTIVE);
                if (l_pErr)
                {
                    HWAS_ERR("platLogEvent returned an error");
                    break;
                }
                continue;
            }
            // if this does NOT match, continue to next in loop
            if (i_pPredicate && ((*i_pPredicate)(l_pTarget) == false))
            {
                HWAS_INF("skipping %.8X - predicate didn't match",
                        get_huid(l_pTarget));
                l_pErr = platLogEvent(l_pTarget, PREDICATE);
                if (l_pErr)
                {
                    HWAS_ERR("platLogEvent returned an error");
                    break;
                }
                continue;
            }

            // clock design requires the predictively garded clocks to be
            // functional to use it as secondary so skipping the deconfigure
            if ((l_gardRecord.iv_errorType == GARD_Predictive) &&
                 (l_pTarget->getAttr<ATTR_TYPE>() == TYPE_OSCREFCLK))
            {
                HWAS_INF("skipping applying gard record for clock %.8X",
                    get_huid(l_pTarget));
                continue;
            }

            //Apply the speculative gard record.
            l_pErr = applyGardRecord(l_pTarget, l_gardRecord, SPEC_DECONFIG);
            if (l_pErr)
            {
                HWAS_ERR("applyGardRecord returned an error");
                break;
            }
            else
            {
                // Keep track of spec deconfig gard record
                l_specDeconfigVector.push_back(l_gardRecord);
            }
        } // for

        if(l_pErr)
        {
            HWAS_ERR("Error occured when applying Recoverable Guard records");
            break;
        }

        l_pErr = checkMinimumHardware(pSys,&l_isSystemBootable);
        if (l_pErr)
        {
            HWAS_ERR("checkMinimumHardware returned an error");
            break;
        }

        if(!l_isSystemBootable)
        {
            HWAS_INF("System cannot ipl, rolling back the gard for "
                     "speculatively deconfigured targets");

            const uint64_t userdata1 = l_specDeconfigVector.size();
            const uint64_t userdata2 = 0;
            /*@
             * @errortype
             * @severity          ERRL_SEV_INFORMATIONAL
             * @moduleid          MOD_DECONFIG_TARGETS_FROM_GARD
             * @reasoncode        RC_RESOURCE_RECOVERED
             * @devdesc           Gard record(s) not applied due to a
             *                    lack of resources.
             * @custdesc          A previously discovered hardware issue is
             *                    being ignored to allow the system to boot.
             * @userdata1         Number of gard records not applied
             * @userdata2         0
             */

            l_pErr = hwasError(ERRL_SEV_INFORMATIONAL,
                               MOD_DECONFIG_TARGETS_FROM_GARD,
                               RC_RESOURCE_RECOVERED,
                               userdata1,
                               userdata2);

            //Now go through all targets which are speculatively
            //deconfigured and roll back gard on them.
            PredicateHwas predSpecDeconfig;
            predSpecDeconfig.specdeconfig(true);
            TargetHandleList l_specDeconfgList;
            targetService().getAssociated(l_specDeconfgList, pSys,
                            TargetService::CHILD, TargetService::ALL,
                            &predSpecDeconfig);

            //Loop through gard records where spec deconfig was applied
            for (TargetHandleList::const_iterator
                 l_sdIter = l_specDeconfgList.begin();
                 l_sdIter != l_specDeconfgList.end();
                 ++l_sdIter)
            {
                HwasState l_state = (*l_sdIter)->getAttr<ATTR_HWAS_STATE>();

                //Need to call enableHwasState() to make sure any secondary
                // actions run, specifically the logic that sets ATTR_PG.
                enableHwasState( *l_sdIter,
                                 l_state.present,
                                 l_state.functional,
                                 CONFIGURED_BY_RESOURCE_RECOVERY );

                //Mark parent node as resource recovered
                PredicateCTM predNode(CLASS_ENC, TYPE_NODE);
                PredicateHwas predFunctional;
                predFunctional.functional(true);
                PredicatePostfixExpr nodeCheckExpr;
                nodeCheckExpr.push(&predNode).push(&predFunctional).And();

                TargetHandleList pNodeList;
                targetService().getAssociated(pNodeList, *l_sdIter,
                                TargetService::PARENT, TargetService::ALL,
                                &nodeCheckExpr);
                if(!pNodeList.empty())
                {
                    HwasState l_state =
                            pNodeList[0]->getAttr<ATTR_HWAS_STATE>();
                    l_state.deconfiguredByEid =
                            CONFIGURED_BY_RESOURCE_RECOVERY;
                    pNodeList[0]->setAttr<ATTR_HWAS_STATE>(l_state);
                }

                // TODO: Should add some of this data to the info log, but
                //  we can't use normal interfaces in this common code
            } // for

            // commit the informational log
            errlCommit(l_pErr, HWAS_COMP_ID);

            //After recovery go through all recovered gard records and
            //log an event.
            for (GardRecordsCItr_t l_itr = l_specDeconfigVector.begin();
                 l_itr != l_specDeconfigVector.end();
                 ++l_itr)
            {
                Target * l_pTarget =
                   targetService().toTarget((*l_itr).iv_targetId);

                l_pErr = platLogEvent(l_pTarget, RESOURCE_RECOVERED);
                if (l_pErr)
                {
                    HWAS_ERR("platLogEvent returned an error");
                    break;
                }
            } // for

#ifdef __HOSTBOOT_MODULE
            if(!INITSERVICE::spBaseServicesEnabled())
            {
                // for eBMC systems, we want to remove all GARD_Reconfigs
                // from the Gard list so that eBMC will know that HB is NOT
                // applying those Gards for the next reconfig loop
                l_pErr = clearGardRecordsByType(GARD_Reconfig);
                if (l_pErr)
                {
                    HWAS_ERR("Error clearing all GARD_Reconfigs");
                    break;
                }
            }
#endif

        }
        else
        {
            HWAS_INF("System can ipl with gard + spec deconfig, converting all spec deconfig to gard");
            //Loop through gard records where spec deconfig was applied
            while(!l_specDeconfigVector.empty())
            {
                // Get gard record and associated target
                GardRecord l_gardRecord = l_specDeconfigVector.front();
                Target * l_pTarget =
                    targetService().toTarget(l_gardRecord.iv_targetId);

                //Apply the spec gard record as a normal gard record.
                l_pErr = applyGardRecord(l_pTarget, l_gardRecord);
                if (l_pErr)
                {
                    HWAS_ERR("applyGardRecord returned an error");
                    break;
                }

                uint32_t l_errlogEid = l_gardRecord.iv_errlogEid;
                //If the errlogEid is already in the errLogEidList, then
                //don't need to log it again as a single error log can
                //create multiple guard records and we only need to repost
                //it once.
                std::vector<uint32_t>::iterator low =
                        std::lower_bound(errlLogEidList.begin(),
                        errlLogEidList.end(), l_errlogEid);
                if((low == errlLogEidList.end()) || ((*low) != l_errlogEid))
                {
                    errlLogEidList.insert(low, l_errlogEid);
                    l_pErr = platReLogGardError(l_gardRecord);
                    if (l_pErr)
                    {
                        HWAS_ERR("platReLogGardError returned an error");
                        break;
                    }
                }

#if (!defined(CONFIG_CONSOLE_OUTPUT_TRACE) && defined(CONFIG_CONSOLE))
                const char* l_tmpstring =
                  l_pTarget->getAttr<TARGETING::ATTR_PHYS_PATH>().toString();
                CONSOLE::displayf(CONSOLE::DEFAULT, "HWAS", "Deconfig HUID 0x%08X, %s due to 0x%.08X",
                    get_huid(l_pTarget),
                    l_tmpstring,
                    l_errlogEid);
                free((void*)(l_tmpstring));
                l_tmpstring = nullptr;
#endif

                l_specDeconfigVector.erase(l_specDeconfigVector.begin());
            } // while
        }

        if (iv_XAOBusEndpointDeconfigured)
        {
            // Get all functional nodes
            TargetHandleList l_funcNodes;
            getEncResources(l_funcNodes, TYPE_NODE, UTIL_FILTER_FUNCTIONAL);

            for (TargetHandleList::const_iterator
                 l_nodesIter = l_funcNodes.begin();
                 l_nodesIter != l_funcNodes.end();
                 ++l_nodesIter)
            {
                l_pErr = _invokeDeconfigureAssocProc(*l_nodesIter);
                if (l_pErr)
                {
                    HWAS_ERR("Error from _invokeDeconfigureAssocProc");
                    break;
                }
                // Set for deconfigure algorithm to run on every node even if
                // no buses deconfigured (needed for multi-node systems)
                setXAOBusEndpointDeconfigured(true);
            }
            setXAOBusEndpointDeconfigured(false);
        }
    }
    while (0);

    return l_pErr;
} // deconfigureTargetsFromGardRecordsForIpl

//******************************************************************************
void DeconfigGard::clearFcoDeconfigures()
{
    // Get top level target
    Target* pSys = nullptr;
    targetService().getTopLevelTarget(pSys);
    HWAS_ASSERT(pSys!=nullptr,"Top level target was nullptr");

    // Find all the nodes below it
    PredicateCTM isNode(CLASS_ENC, TYPE_NODE);
    PredicateHwas isFunctional;
    isFunctional.functional(true);
    PredicatePostfixExpr isFunctionalNode;
    isFunctionalNode.push(&isNode).push(&isFunctional).And();

    TargetHandleList nodeHandleList;
    targetService().getAssociated(nodeHandleList, pSys,
                    TargetService::CHILD, TargetService::IMMEDIATE,
                    &isFunctionalNode);

    // Clear the FCO deconfigures for each one
    for(auto const& pNode : nodeHandleList)
    {
        _clearFCODeconfigure(pNode);
    }
} // clearFcoDeconfigures

//******************************************************************************
errlHndl_t DeconfigGard::clearGardRecords(
    const Target * const i_pTarget,
    const bool i_clearOnlyDeconfig)
{
#ifndef __HOSTBOOT_MODULE
    errlHndl_t l_pErr = platClearGardRecords(i_pTarget);
#else
    // eBMC systems have a Deconfig gard record in addition to
    // normal Gard record. Need to pass in i_type to know which
    // of the two to remove
    errlHndl_t l_pErr = platClearGardRecords(i_pTarget, i_clearOnlyDeconfig);
#endif
    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::dumpGardRecords(
    const Target * const i_pTarget,
    GardRecords_t & o_records)
{
    errlHndl_t l_pErr = nullptr;
    char * tmp_str = nullptr;

    do
    {
        l_pErr = platGetGardRecords(i_pTarget, o_records);
        if (l_pErr)
        {
            HWAS_ERR("dumpGardRecords: dumpGardRecords had a problem calling platGetGardRecords");
            break;
        }

        HWAS_INF("dumpGardRecords: o_records.size=0x%X GardRecord size=0x%X",
            o_records.size(), sizeof(DeconfigGard::GardRecord));
        if (o_records.size() == 0)
        {
            HWAS_INF("dumpGardRecords: found NO gard records to dump");
            break;
        }
        for (const auto& record : o_records)
        {
            HWAS_INF("dumpGardRecords: o_records record.iv_recordId=0x%X", record.iv_recordId);
            tmp_str = record.iv_targetId.toString();
            HWAS_INF("dumpGardRecords: o_records record.iv_targetId.toString()=%s", tmp_str);
            free(tmp_str);
            tmp_str = nullptr;
            HWAS_INF("dumpGardRecords: o_records record.iv_errlogEid=0x%X", record.iv_errlogEid);
            HWAS_INF("dumpGardRecords: o_records record.iv_errorType=0x%X", record.iv_errorType);
            HWAS_INF_BIN("dumpGardRecords: o_records uniqueId", &record.uniqueId, sizeof(record.uniqueId));
        }
    }
    while (0);

    return l_pErr;
}

//******************************************************************************
errlHndl_t DeconfigGard::getGardRecords(
    const Target * const i_pTarget,
    GardRecords_t & o_records)
{
    errlHndl_t l_pErr = platGetGardRecords(i_pTarget, o_records);
    return l_pErr;
}

//******************************************************************************
void DeconfigGard::registerDeferredDeconfigure(
        const Target & i_target,
        const uint32_t i_errlEid)
{
    HWAS_INF("registerDeferredDeconfigure Target %.8X, errlEid 0x%X",
            get_huid(&i_target), i_errlEid);

    // Create a Deconfigure Record
    HWAS_MUTEX_LOCK(iv_mutex);

    _createDeconfigureRecord(i_target, i_errlEid);

    HWAS_MUTEX_UNLOCK(iv_mutex);
}

//******************************************************************************
errlHndl_t DeconfigGard::_getDeconfigureRecords(
    const Target * const i_pTarget,
    DeconfigureRecords_t & o_records)
{
    HWAS_DBG("Get Deconfigure Record(s)");
    o_records.clear();

    HWAS_MUTEX_LOCK(iv_mutex);
    DeconfigureRecordsCItr_t l_itr = iv_deconfigureRecords.begin();

    if (i_pTarget == nullptr)
    {
        HWAS_INF("Getting all %d Deconfigure Records",
                 iv_deconfigureRecords.size());

        for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            o_records.push_back(*l_itr);
        }
    }
    else
    {
        // Look for a Deconfigure Record for the specified Target (there can
        // only be one record)
        for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            if ((*l_itr).iv_target == i_pTarget)
            {
                HWAS_INF("Getting Deconfigure Record for %.8X",
                               get_huid(i_pTarget));
                o_records.push_back(*l_itr);
                break;
            }
        }

        if (l_itr == iv_deconfigureRecords.end())
        {
            HWAS_INF("Did not find a Deconfigure Record for %.8X",
                           get_huid(i_pTarget));
        }
    }

    HWAS_MUTEX_UNLOCK(iv_mutex);
    return nullptr;
} // _getDeconfigureRecords

//******************************************************************************
void DeconfigGard::_createDeconfigureRecord(
    const Target & i_target,
    const uint32_t i_errlEid)
{
    // Look for an existing Deconfigure Record for the Target
    DeconfigureRecordsCItr_t l_itr = iv_deconfigureRecords.begin();

    for (; l_itr != iv_deconfigureRecords.end(); ++l_itr)
    {
        if ((*l_itr).iv_target == &i_target)
        {
            HWAS_DBG("Not creating Deconfigure Record, one exists errlEid 0x%X",
                (*l_itr).iv_errlogEid);
            break;
        }
    }

    // didn't find a match and the target is present
    if (l_itr == iv_deconfigureRecords.end() &&
        i_target.getAttr<TARGETING::ATTR_HWAS_STATE>().present)
    {
        // Create a DeconfigureRecord
        HWAS_INF("Creating a Deconfigure Record");

        DeconfigureRecord l_record;
        l_record.iv_target = &i_target;
        l_record.iv_errlogEid = i_errlEid;

        iv_deconfigureRecords.push_back(l_record);
    }
} // _createDeconfigureRecord

//******************************************************************************
void DeconfigGard::clearDeconfigureRecords(
        const Target * const i_pTarget)
{
    if (i_pTarget == nullptr)
    {
        HWAS_INF("Clearing all %d Deconfigure Records",
                 iv_deconfigureRecords.size());
        iv_deconfigureRecords.clear();
    }
    else
    {
        // Look for a Deconfigure Record for the specified Target (there can
        // only be one record)
        bool l_foundRecord = false;

        for (DeconfigureRecordsItr_t l_itr = iv_deconfigureRecords.begin();
             l_itr != iv_deconfigureRecords.end(); ++l_itr)
        {
            if ((*l_itr).iv_target == i_pTarget)
            {
                HWAS_INF("Clearing Deconfigure Record for %.8X",
                                get_huid(i_pTarget));
                iv_deconfigureRecords.erase(l_itr);
                l_foundRecord = true;
                break;
            }
        }

        if (!l_foundRecord)
        {
            HWAS_INF("Did not find a Deconfigure Record to clear for %.8X",
                           get_huid(i_pTarget));
        }
    }
} // clearDeconfigureRecords

//******************************************************************************
void DeconfigGard::processDeferredDeconfig()
{
    HWAS_DBG(">processDeferredDeconfig");

    // get all deconfigure records, process them, and delete them.
    HWAS_MUTEX_LOCK(iv_mutex);

#if (defined(__HOSTBOOT_MODULE) && defined(CONFIG_FSP_BUILD))
    // grab the bootproc target to use below
    TARGETING::Target* l_masterProc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle(l_masterProc);
#endif

    for (DeconfigureRecordsItr_t l_itr = iv_deconfigureRecords.begin();
            l_itr != iv_deconfigureRecords.end();
            ++l_itr)
    {
        DeconfigureRecord l_record = *l_itr;

#if (defined(__HOSTBOOT_MODULE) && defined(CONFIG_FSP_BUILD))
        // On FSP boxes we need to avoid deconfiguring the boot
        // processor because it will break the FSP's ability to
        // analyze our TI.
        if( (l_record.iv_target) == l_masterProc )
        {
            continue;
            //Note - shutdown was already triggered in platHandleHWCallout
        }
#endif

        // do the deconfigure
        _deconfigureTarget(const_cast<Target &> (*(l_record.iv_target)),
                l_record.iv_errlogEid);
        _deconfigureByAssoc(const_cast<Target &> (*(l_record.iv_target)),
                l_record.iv_errlogEid);
    } // for

    // clear the list - handled them all
    iv_deconfigureRecords.clear();

    HWAS_MUTEX_UNLOCK(iv_mutex);

    HWAS_DBG("<processDeferredDeconfig");
} // processDeferredDeconfig

//******************************************************************************
void DeconfigGard::setXAOBusEndpointDeconfigured(bool deconfig)
{
    HWAS_INF("Set iv_XAOBusEndpointDeconfigured = %d", deconfig?1:0);
    iv_XAOBusEndpointDeconfigured = deconfig;
}

//*****************************************************************************
void DeconfigGard::_clearFCODeconfigure(ConstTargetHandle_t i_nodeTarget)
{
    HWAS_DBG("Clear all FCO deconfigure");

    //Get all targets in the node present and non-functional.
    PredicateHwas predNonFunctional;
    predNonFunctional.present(true).functional(false);
    TargetHandleList l_targetList;
    targetService().getAssociated(l_targetList,i_nodeTarget,
                              TargetService::CHILD, TargetService::ALL,
                              &predNonFunctional);
    for (TargetHandleList::const_iterator
             l_target_it = l_targetList.begin();
             l_target_it != l_targetList.end();
             l_target_it++)
    {
        TargetHandle_t l_pTarget = *l_target_it;
        HwasState l_state = l_pTarget->getAttr<ATTR_HWAS_STATE>();
        if(l_state.deconfiguredByEid == DECONFIGURED_BY_FIELD_CORE_OVERRIDE)
        {
            l_state.functional = 1;
            l_state.deconfiguredByEid = 0;
            l_pTarget->setAttr<ATTR_HWAS_STATE>(l_state);
        }
    }
} // _clearFCODeconfigure

//******************************************************************************
uint8_t DeconfigGard::clearBlockSpecDeconfigForReplacedTargets()
{
    HWAS_INF("Clear Block Spec Deconfig for replaced Targets");

    // Get Block Spec Deconfig value
    ATTR_BLOCK_SPEC_DECONFIG_type l_block_spec_deconfig = 0;

    do
    {
        TargetHandleList l_nodelist;
        getEncResources(l_nodelist, TARGETING::TYPE_NODE,
                        TARGETING::UTIL_FILTER_FUNCTIONAL);
        for( auto l_node : l_nodelist )
        {
            l_block_spec_deconfig |= l_node->getAttr<ATTR_BLOCK_SPEC_DECONFIG>();
        }

        // Check Block Spec Deconfig value
        if(l_block_spec_deconfig == 0)
        {
            // Block Spec Deconfig is already cleared
            HWAS_INF("Block Spec Deconfig already cleared");
        }

        // Create the predicate with HWAS changed state and our RESRC_RECOV bit
        PredicateHwasChanged l_predicateHwasChanged;
        l_predicateHwasChanged.changedBit(HWAS_CHANGED_BIT_RESRC_RECOV, true);

        // Go through all targets
        for (TargetIterator t_iter = targetService().begin();
             t_iter != targetService().end();
             ++t_iter)
        {
            Target* l_pTarget = *t_iter;

            // Check if target has changed
            if (l_predicateHwasChanged(l_pTarget))
            {
                // Check if Block Spec Deconfig is set
                if(l_block_spec_deconfig == 1)
                {
                    l_block_spec_deconfig = 0;
                    HWAS_INF("Block Spec Deconfig cleared due to HWAS state "
                             "change for 0x%.8x",
                             get_huid(l_pTarget));
                }

                // Clear RESRC_RECOV bit in changed flags for the target
                HWAS_DBG("RESRC_RECOV bit cleared for 0x%.8x",
                         get_huid(l_pTarget));
                clear_hwas_changed_bit(l_pTarget, HWAS_CHANGED_BIT_RESRC_RECOV);
            }
        } // for

        // Clear on all nodes if we found a reason
        if( l_block_spec_deconfig == 0 )
        {
            for( auto l_node : l_nodelist )
            {
                l_node->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(l_block_spec_deconfig);
            }
        }
    } while (0);

    return l_block_spec_deconfig;
} // clearBlockSpecDeconfigForReplacedTargets

//******************************************************************************
errlHndl_t
   DeconfigGard::clearBlockSpecDeconfigForUngardedTargets(uint8_t &io_blockAttr)
{
    HWAS_INF("Clear Block Spec Deconfig for ungarded Targets");

    errlHndl_t l_pErr = nullptr;
    GardRecords_t l_records;

    do
    {
        // Check Block Spec Deconfig value
        if(io_blockAttr == 0)
        {
            // Block Spec Deconfig is already cleared
            HWAS_INF("Block Spec Deconfig already cleared");
        }

        // Create the predicate with HWAS changed state and our GARD_APPLIED bit
        PredicateHwasChanged l_predicateHwasChanged;
        l_predicateHwasChanged.changedBit(HWAS_CHANGED_BIT_GARD_APPLIED, true);

        // Go through all targets
        for (TargetIterator t_iter = targetService().begin();
             t_iter != targetService().end();
             ++t_iter)
        {
            Target* l_pTarget = *t_iter;

            // Check if target has gard applied
            if (l_predicateHwasChanged(l_pTarget))
            {
                // Get gard records for the target
                l_pErr = platGetGardRecords(l_pTarget, l_records);
                if (l_pErr)
                {
                    break;
                }

                // If there are gard records, continue to next target
                if (l_records.size() > 0)
                {
                    continue;
                }

                // Check if Block Spec Deconfig is set
                if(io_blockAttr == 1)
                {
                    io_blockAttr = 0;
                    HWAS_INF("Block Spec Deconfig cleared due to no gard "
                             "records for 0x%.8x",
                             get_huid(l_pTarget));
                }

                // Clear GARD_APPLIED bit in HWAS changed flags for the target
                HWAS_INF("HWAS_CHANGED_BIT_GARD_APPLIED cleared for 0x%.8x",
                         get_huid(l_pTarget));
                clear_hwas_changed_bit(l_pTarget,
                                       HWAS_CHANGED_BIT_GARD_APPLIED);
            }
        } // for

        // Clear on all nodes if we found a reason
        if( io_blockAttr == 0 )
        {
            TargetHandleList l_nodelist;
            getEncResources(l_nodelist, TARGETING::TYPE_NODE,
                            TARGETING::UTIL_FILTER_FUNCTIONAL);
            for( auto l_node : l_nodelist )
            {
                l_node->setAttr<ATTR_BLOCK_SPEC_DECONFIG>(io_blockAttr);
            }
        }
    } while (0);

    return l_pErr;
} // clearBlockSpecDeconfigForUngardedTargets

//******************************************************************************
#endif // end #ifndef __HOSTBOOT_RUNTIME

//******************************************************************************
// HOSTBOOT only methods - RUNTIME and NON-RUNTIME
//******************************************************************************

#ifdef __HOSTBOOT_MODULE
/******************************************************************************/
// deconfigureTargetAtRuntime
/******************************************************************************/
errlHndl_t DeconfigGard::deconfigureTargetAtRuntime(
        TARGETING::TargetHandle_t i_pTarget,
        const DeconfigGard::DeconfigureFlags i_deconfigureAction,
        const errlHndl_t i_deconfigErrl)

{
    errlHndl_t l_errl = nullptr;

    uint32_t deconfigReason =
        (i_deconfigErrl) ?
        i_deconfigErrl->eid() : DeconfigGard::DECONFIGURED_BY_PRD;

    HWAS_INF(">>>deconfigureTargetAtRuntime() - "
            "Input Target HUID:0x%08X Deconfig Action"
            " 0x%08X Deconfig Reason :0x%08X",
            get_huid(i_pTarget),i_deconfigureAction,
            deconfigReason);

#ifdef __HOSTBOOT_RUNTIME

    l_errl = platDeconfigureTargetAtRuntime(
                                            i_pTarget,
                                            i_deconfigureAction,
                                            i_deconfigErrl
                                           );
#else
    HWAS_ERR("deconfigureTargetAtRuntime() - "
            "called outside of hbrt context");
    /*@
     * @errortype
     * @moduleid     MOD_RUNTIME_DECONFIG
     * @reasoncode   RC_NOT_AT_RUNTIME
     * @userdata1    HUID of the target
     * @userdata2    deconfig reason - either error log id, or
     *                                 DeconfigGard::DECONFIGURED_BY_PRD
     *
     * @devdesc      deconfigureTargetAtRuntime is currently only
     *               supported in hostboot runtime, this error
     *               indicates the function was called outside of
     *               the hostboot runtime context.
     * @custdesc     Host firmware encountered an
     *               internal error
     */

    l_errl = hwasError(
                       ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                       MOD_RUNTIME_DECONFIG,RC_NOT_AT_RUNTIME,
                       get_huid(i_pTarget),deconfigReason
                       );
#endif
    HWAS_INF(">>>deconfigureTargetAtRuntime()" );
    return l_errl ;
} // deconfigureTargetAtRuntime

//******************************************************************************
#endif  // end #ifdef __HOSTBOOT_MODULE

} // namespace HWAS
