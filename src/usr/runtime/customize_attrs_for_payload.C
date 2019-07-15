/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/customize_attrs_for_payload.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
 *  @file customize_attrs_for_payload.C
 *
 *  @brief Customize attributes in the targeting model that vary based on
 *      payload which are only needed for runtime operation
 */

//#include <sys/misc.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/runtime/rt_targeting.H>
#include <runtime/runtime_reasoncodes.H>
#include <runtime/runtime.H>
#include <errl/errlmanager.H>
#include <arch/pirformat.H>
#include <targeting/common/util.H>
#include <errl/errludtarget.H>
#include <runtime/customize_attrs_for_payload.H>
#include <runtime/interface.h>

extern trace_desc_t *g_trac_runtime;

namespace RUNTIME
{

/**
 *  @brief Create procesor targeting target not found error
 *  @param[in] i_pTarget Targeting target which did not have a processor
 *      targeting target.  Must not be NULL (asserts otherwise)
 *  @return Error log handle
 *  @retval !NULL New error log indicating the error
 */
errlHndl_t createProcNotFoundError(
    const TARGETING::Target* const i_pTarget)
{
    assert(i_pTarget != NULL);

    errlHndl_t pError = NULL;
    auto huid = TARGETING::get_huid(i_pTarget);
    TRACFCOMP(g_trac_runtime, ERR_MRK
        " No processor targeting target found for targeting target with "
        "HUID of 0x%08X",
        huid);

    // Note: the module ID below references the function that exclusively
    // creates this error
    /*@
     * @errortype
     * @moduleid    RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET
     * @reasoncode  RUNTIME::RT_NO_PROC_TARGET
     * @userdata1   Input targeting target's HUID
     * @devdesc     No processor targeting target was found for the given
     *              targeting target
     * @custdesc    Unexpected internal firmware error
     */
    pError = new ERRORLOG::ErrlEntry(
        ERRORLOG::ERRL_SEV_INFORMATIONAL,
        RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET,
        RUNTIME::RT_NO_PROC_TARGET,
        huid,
        0,
        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

    ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting target").
        addToLog(pError);

    return pError;
}

/**
 *  @brief Returns the runtime target ID for a given targeting target for all
 *      hypervisors other than PHyp
 *  @param[in] i_pTarget Targeting target, must not be NULL (asserts
 *      otherwise)
 *  @param[out] o_rtTargetId Runtime target ID which maps to the given targeting
 *      target
 *  @return Error log handle
 *  @retval NULL Computed a valid runtime target ID for the given input
 *      targeting target and returned it in the output parameter.
 *  @retval !NULL Failed to compute a runtime target ID for the given input
 *      targeting target. Ignore output parameter.
 */
errlHndl_t computeNonPhypRtTarget(
    const TARGETING::Target*   i_pTarget,
          TARGETING::rtChipId_t& o_rtTargetId)
{
    assert(i_pTarget != NULL);

    errlHndl_t pError = NULL;

    do
    {
        if(i_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* masterProcChip = NULL;
            TARGETING::targetService().
                masterProcChipTargetHandle(masterProcChip);
            i_pTarget = masterProcChip;
        }

        auto targetingTargetType = i_pTarget->getAttr<TARGETING::ATTR_TYPE>();

        if(targetingTargetType == TARGETING::TYPE_PROC)
        {
            uint32_t fabId =
                i_pTarget->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();

            uint32_t procPos =
                i_pTarget->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

            o_rtTargetId = PIR_t::createChipId( fabId, procPos );
        }
        else if( targetingTargetType == TARGETING::TYPE_MEMBUF)
        {
            //MEMBUF
            // 0b1000.0000.0000.0000.0000.0GGG.GCCC.MMMM
            // where GGGG is group, CCC is chip, MMMM is memory channel
            //
            TARGETING::TargetHandleList targetList;

            getParentAffinityTargets(targetList,
                                    i_pTarget,
                                    TARGETING::CLASS_UNIT,
                                    TARGETING::TYPE_DMI,
                                    TARGETING::UTIL_FILTER_ALL);

            if( targetList.empty() )
            {
                auto huid = get_huid(i_pTarget);
                TRACFCOMP(g_trac_runtime, ERR_MRK
                    "No associated DMI targeting target(s) found for MEMBUF "
                    "targeting target with HUID of 0x%08X",
                    huid);
                /*@
                 * @error
                 * @moduleid    RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET
                 * @reasoncode  RUNTIME::RT_UNIT_TARGET_NOT_FOUND
                 * @userdata1   MEMBUF targeting target's HUID
                 * @devdesc     No associated DMI targeting target(s) found for
                 *              given MEMBUF targeting target
                 * @custdesc    Unexpected internal firmware error
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET,
                    RUNTIME::RT_UNIT_TARGET_NOT_FOUND,
                    huid,
                    0,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting Target").
                    addToLog(pError);

                break;
            }

            auto target = targetList[0];
            auto pos = target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            targetList.clear();
            getParentAffinityTargets(targetList,
                                     target,
                                     TARGETING::CLASS_CHIP,
                                     TARGETING::TYPE_PROC,
                                     TARGETING::UTIL_FILTER_ALL);

            if(targetList.empty())
            {
                pError = createProcNotFoundError(target);
                break;
            }

            auto procTarget = targetList[0];
            pError = computeNonPhypRtTarget(procTarget, o_rtTargetId);
            if(pError)
            {
                break;
            }

            o_rtTargetId = (o_rtTargetId << RT_TARG::MEMBUF_ID_SHIFT);
            o_rtTargetId += pos;
            o_rtTargetId |= HBRT_MEMBUF_TYPE;
        }
        else if(targetingTargetType == TARGETING::TYPE_CORE)
        {
            // CORE
            // 0b0100.0000.0000.0000.0000.GGGG.CCCP.PPPP
            // GGGG is group, CCC is chip, PPPPP is core
            auto pos = i_pTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();
            const TARGETING::Target* procTarget = getParentChip(i_pTarget);
            if(procTarget == NULL)
            {
                pError = createProcNotFoundError(i_pTarget);
                break;
            }

            pError = computeNonPhypRtTarget(procTarget, o_rtTargetId);
            if(pError)
            {
                break;
            }

            o_rtTargetId = PIR_t::createCoreId(o_rtTargetId,pos);
            o_rtTargetId |= HBRT_CORE_TYPE;
        }
        else if( targetingTargetType == TARGETING::TYPE_OCMB_CHIP)
        {
            // OCMB (This layout mimics MEMBUF)
            // 0b1000.0000.0000.0000.0000.0GGG.GCCC.UUUU
            // where GGGG is group, CCC is chip, UUUU is OMI chip unit
            //
            TARGETING::TargetHandleList targetList;

            getParentAffinityTargets(targetList,
                                    i_pTarget,
                                    TARGETING::CLASS_UNIT,
                                    TARGETING::TYPE_OMI,
                                    TARGETING::UTIL_FILTER_ALL);

            if( targetList.empty() )
            {
                auto huid = get_huid(i_pTarget);
                TRACFCOMP(g_trac_runtime, ERR_MRK
                    "No associated OMI targeting target(s) found for OCMB_CHIP "
                    "targeting target with HUID of 0x%08X",
                    huid);
                /*@
                 * @error
                 * @moduleid    RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET
                 * @reasoncode  RUNTIME::RT_NO_OMI_TARGET_FOUND
                 * @userdata1   OCMB targeting target's HUID
                 * @devdesc     No associated OMI targeting target(s) found for
                 *              given OCMB targeting target
                 * @custdesc    Unexpected internal firmware error
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET,
                    RUNTIME::RT_NO_OMI_TARGET_FOUND,
                    huid,
                    0,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting Target").
                    addToLog(pError);

                break;
            }

            auto target = targetList[0];
            auto pos = target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            targetList.clear();
            getParentAffinityTargets(targetList,
                                     target,
                                     TARGETING::CLASS_CHIP,
                                     TARGETING::TYPE_PROC,
                                     TARGETING::UTIL_FILTER_ALL);

            if(targetList.empty())
            {
                pError = createProcNotFoundError(target);
                break;
            }

            auto procTarget = targetList[0];
            pError = computeNonPhypRtTarget(procTarget, o_rtTargetId);
            if(pError)
            {
                break;
            }

            // GGGG = 0 by default, CCC = o_rtTargetId, UUUU = pos
            // HBRT_MEMBUF_TYPE distinguishes this target as a MEMBUF/OCMB
            // Reusing MEMBUF for OCMB type as the two can't coexist
            o_rtTargetId = (o_rtTargetId << RT_TARG::MEMBUF_ID_SHIFT);
            o_rtTargetId += pos;  // OMI chip unit acts as unique target position
            o_rtTargetId |= HBRT_MEMBUF_TYPE;
        }
        else
        {
            auto huid = get_huid(i_pTarget);
            TRACFCOMP(g_trac_runtime,ERR_MRK
                      "Targeting target type 0x%08X not supported.  Cannot "
                      "convert targeting target with HUID of 0x%08X into a "
                      "runtime target ID",
                      targetingTargetType,
                      huid);
            /*@
             * @errortype
             * @moduleid    RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET
             * @reasoncode  RUNTIME::RT_TARGET_TYPE_NOT_SUPPORTED
             * @userdata1   Targeting target's HUID
             * @userdata2   Targeting target's type
             * @devdesc     The targeting type of the input targeting target is
             *              not supported by runtime code
             * @custdesc    Unexpected internal firmware error
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET,
                RUNTIME::RT_TARGET_TYPE_NOT_SUPPORTED,
                huid,
                targetingTargetType,
                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting Target").
                addToLog(pError);
        }

    } while(0);

    return pError;
}

/**
 *  @brief Returns the runtime target type for a given targeting target
 *  @param[in] i_pTarget Targeting target, must not be NULL
 *      (asserts otherwise)
 *  @param[out] o_rtType Runtime target type for given targeting target
 *  @return Error log handle
 *  @retval NULL Returned supported runtime target type for the given input
 *      targeting target in the output parameter.
 *  @retval !NULL Failed to determine runtime target type for the
 *      given input targeting target, ignore output parameter.
 */
errlHndl_t getRtTypeForTarget(
    const TARGETING::Target*   i_pTarget,
          TARGETING::rtChipId_t& o_rtType)
{
    assert(i_pTarget != NULL);

    errlHndl_t pError = NULL;

    if(i_pTarget == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        TARGETING::Target* masterProcChip = NULL;
        TARGETING::targetService().
            masterProcChipTargetHandle(masterProcChip);
        i_pTarget = masterProcChip;
    }

    auto found = true;
    auto rtType = RT_TYPE_UNKNOWN;
    auto targetingTargetType = i_pTarget->getAttr<TARGETING::ATTR_TYPE>();
    switch(targetingTargetType)
    {
        case TARGETING::TYPE_PROC:
            rtType = HBRT_PROC_TYPE;
            break;
        case TARGETING::TYPE_MEMBUF:
            rtType = HBRT_MEMBUF_TYPE;
            break;
        case TARGETING::TYPE_CORE:
            rtType = HBRT_CORE_TYPE;
            break;
        case TARGETING::TYPE_OCMB_CHIP:
            // reusing MEMBUF type as it is not present
            rtType = HBRT_MEMBUF_TYPE;
            break;
        default:
            found = false;
            break;
    }

    if(!found)
    {
        auto huid = get_huid(i_pTarget);
        TRACFCOMP(g_trac_runtime, ERR_MRK
            "Input targeting target's type of 0x%08X is not supported. "
            "HUID: 0x%08X",
            targetingTargetType,
            huid);
        /*@
         * @errortype
         * @moduleid    RUNTIME::MOD_CUST_CONF_HBRT_HYP_IDS
         * @reasoncode  RUNTIME::RT_TARGET_TYPE_NOT_SUPPORTED
         * @userdata1   Target's HUID
         * @userdata2   Target's targeting type
         * @devdesc     Targeting target's type not supported by runtime code
         * @custdesc    Unexpected internal firmware error
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            RUNTIME::MOD_CUST_CONF_HBRT_HYP_IDS,
            RUNTIME::RT_TARGET_TYPE_NOT_SUPPORTED,
            huid,
            targetingTargetType,
            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

        ERRORLOG::ErrlUserDetailsTarget(i_pTarget,"Targeting Target").
            addToLog(pError);
    }

    o_rtType = rtType;

    return pError;
}

errlHndl_t configureHbrtHypIds(const bool i_configForPhyp)
{
    TRACDCOMP( g_trac_runtime, ENTER_MRK "configureHbrtHypIds" );

    errlHndl_t pError = NULL;

    TARGETING::PredicateCTM isaProc(
        TARGETING::CLASS_CHIP, TARGETING::TYPE_PROC);
    TARGETING::PredicateCTM isaMembuf(
        TARGETING::CLASS_CHIP, TARGETING::TYPE_MEMBUF);
    TARGETING::PredicateCTM isaCore(
        TARGETING::CLASS_UNIT, TARGETING::TYPE_CORE);
    TARGETING::PredicateCTM isanOcmbChip(
        TARGETING::CLASS_CHIP, TARGETING::TYPE_OCMB_CHIP);
    TARGETING::PredicatePostfixExpr isaProcMembufCoreorOcmb;
    isaProcMembufCoreorOcmb.push(&isaProc).push(&isaMembuf).Or()
        .push(&isaCore).Or().push(&isanOcmbChip).Or();
    TARGETING::TargetRangeFilter pIt(
        TARGETING::targetService().begin(),
        TARGETING::targetService().end(),
        &isaProcMembufCoreorOcmb);
    for (; pIt; ++pIt)
    {
        auto hbrtHypId = HBRT_HYP_ID_UNKNOWN;

        // Phyp is the only special case
        if(i_configForPhyp)
        {
            auto rtType = RT_TYPE_UNKNOWN;
            pError = getRtTypeForTarget(*pIt,rtType);
            if(pError)
            {
                break;
            }

            switch ((*pIt)->getAttr<TARGETING::ATTR_TYPE>())
            {
              case TARGETING::TYPE_CORE:
                {
                    if(TARGETING::is_fused_mode())
                    {
                        // If we're in fused core mode, all core ID's must
                        // match that of the parent EX
                        auto type = TARGETING::TYPE_EX;
                        const TARGETING::Target* pEx =
                                TARGETING::getParent(*pIt,type);

                        // If this fails, everything is already hosed
                        assert(pEx != NULL);

                        hbrtHypId = (pEx)->getAttr<TARGETING::ATTR_ORDINAL_ID>();
                    }
                    else
                    {
                        hbrtHypId = (*pIt)->getAttr<TARGETING::ATTR_ORDINAL_ID>();
                    }
                    break;
                }
              case TARGETING::TYPE_MEMBUF:
                {
                    //MEMBUF
                    // 0b1000.0000.0000.0000.0000.0PPP.PPPP.MMMM
                    // where PP is the parent proc's id, MMMM is memory channel
                    //
                    TARGETING::TargetHandleList targetList;

                    getParentAffinityTargets(targetList,
                                             (*pIt),
                                             TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_DMI, false);
                    assert( !targetList.empty() );

                    auto dmi_target = targetList[0];
                    auto pos = dmi_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                    targetList.clear();
                    getParentAffinityTargets(targetList,
                                             dmi_target,
                                             TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_PROC, false);
                    assert( !targetList.empty() );

                    auto procTarget = targetList[0];
                    hbrtHypId = procTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();
                    hbrtHypId = (hbrtHypId << RT_TARG::MEMBUF_ID_SHIFT);
                    hbrtHypId += pos;
                    break;
                }
              case TARGETING::TYPE_OCMB_CHIP:
                {
                    TRACDCOMP( g_trac_runtime, "configureHbrtHypIds> "
                      "Set ATTR_HBRT_HYP_ID attribute for OCMB target "
                      "with HUID of 0x%08X", TARGETING::get_huid(*pIt));

                    // TYPE_OCMB_CHIP (mimics MEMBUF layout)
                    // 0b1000.0000.0000.0000.0000.0PPP.PPPP.UUUU
                    // where PP is the parent proc's id, UUUU is OMI chip unit
                    //
                    TARGETING::TargetHandleList targetList;

                    getParentAffinityTargets(targetList,
                                             (*pIt),
                                             TARGETING::CLASS_UNIT,
                                             TARGETING::TYPE_OMI, false);
                    assert( !targetList.empty() );

                    auto omi_target = targetList[0];
                    auto pos = omi_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                    targetList.clear();
                    getParentAffinityTargets(targetList,
                                             omi_target,
                                             TARGETING::CLASS_CHIP,
                                             TARGETING::TYPE_PROC, false);
                    assert( !targetList.empty() );

                    auto procTarget = targetList[0];
                    // Reusing MEMBUF for OCMB Chip communication
                    hbrtHypId = procTarget->getAttr<TARGETING::ATTR_ORDINAL_ID>();
                    hbrtHypId = (hbrtHypId << RT_TARG::MEMBUF_ID_SHIFT);
                    hbrtHypId += pos; // Add OMI chip unit to end
                    break;
                }
              case TARGETING::TYPE_PROC:
                {
                    hbrtHypId = (*pIt)->getAttr<TARGETING::ATTR_ORDINAL_ID>();
                    break;
                }
              default:
                {
                    auto huid = get_huid(*pIt);
                    auto targetType = (*pIt)->getAttr<TARGETING::ATTR_TYPE>();
                    TRACFCOMP(g_trac_runtime, ERR_MRK
                        "configureHbrtHypIds> 0x%08X is not a supported type. "
                        "HUID: 0x%08X", targetType, huid);
                    /*@
                     * @errortype
                     * @moduleid    RUNTIME::MOD_CONFIGURE_HBRT_HYP_IDS
                     * @reasoncode  RUNTIME::RT_TARGET_TYPE_NOT_SUPPORTED
                     * @userdata1   Target's HUID
                     * @userdata2   Target's targeting type
                     * @devdesc     Targeting target's type not supported by runtime code
                     * @custdesc    Unexpected internal firmware error
                     */
                    pError = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        RUNTIME::MOD_CONFIGURE_HBRT_HYP_IDS,
                        RUNTIME::RT_TARGET_TYPE_NOT_SUPPORTED,
                        huid,
                        targetType,
                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                    ERRORLOG::ErrlUserDetailsTarget(*pIt,"Targeting Target").
                        addToLog(pError);
                    break;
                }
            } // end of ATTR_TYPE switch
            hbrtHypId |= rtType;
        }
        else
        {
            pError = computeNonPhypRtTarget(*pIt,hbrtHypId);
            if(pError)
            {
                break;
            }
        }

        // Only set HBRT_HYP_ID attribute if no error found
        if (pError)
        {
            break;
        }

        (*pIt)->setAttr<TARGETING::ATTR_HBRT_HYP_ID>(hbrtHypId);
        TRACDCOMP( g_trac_runtime, "configureHbrtHypIds> "
            "Set ATTR_HBRT_HYP_ID attribute to 0x%016llX on targeting target "
            "with HUID of 0x%08X",
            hbrtHypId,TARGETING::get_huid(*pIt));
    }

    TRACDCOMP( g_trac_runtime, EXIT_MRK "configureHbrtHypIds" );

    return pError;
}

}; // End namespace RUNTIME
