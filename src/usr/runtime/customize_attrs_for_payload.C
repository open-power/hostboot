/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/customize_attrs_for_payload.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#include <runtime/runtime_reasoncodes.H>
#include <runtime/runtime.H>
#include <errl/errlmanager.H>
#include <runtime/rt_targeting.H>
#include <arch/pirformat.H>
#include <targeting/common/util.H>
#include <errl/errludtarget.H>
#include <runtime/customize_attrs_for_payload.H>

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
     *     targeting target
     */
    pError = new ERRORLOG::ErrlEntry(
        ERRORLOG::ERRL_SEV_INFORMATIONAL,
        RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET,
        RUNTIME::RT_NO_PROC_TARGET,
        huid,
        0,
        true);

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
          RT_TARG::rtChipId_t& o_rtTargetId)
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
                                    TARGETING::TYPE_MCS);

            if( targetList.empty() )
            {
                auto huid = get_huid(i_pTarget);
                TRACFCOMP(g_trac_runtime, ERR_MRK
                    "No associated MCS targeting target(s) found for MEMBUF "
                    "targeting target with HUID of 0x%08X",
                    huid);
                /*@
                 * @error
                 * @moduleid    RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET
                 * @reasoncode  RUNTIME::RT_UNIT_TARGET_NOT_FOUND
                 * @userdata1   MEMBUF targeting target's HUID
                 * @devdesc     No associated MCS targeting target(s) found for
                 *              given MEMBUF targeting target
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET,
                    RUNTIME::RT_UNIT_TARGET_NOT_FOUND,
                    huid,
                    0,
                    true);

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
                                     TARGETING::TYPE_PROC);

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
            o_rtTargetId |= RT_TARG::MEMBUF_TYPE;
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
            o_rtTargetId |= RT_TARG::CORE_TYPE;
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
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                RUNTIME::MOD_CUST_COMP_NON_PHYP_RT_TARGET,
                RUNTIME::RT_TARGET_TYPE_NOT_SUPPORTED,
                huid,
                targetingTargetType,
                true);

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
          RT_TARG::rtChipId_t& o_rtType)
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
            rtType = RT_TARG::PROC_TYPE;
            break;
        case TARGETING::TYPE_MEMBUF:
            rtType = RT_TARG::MEMBUF_TYPE;
            break;
        case TARGETING::TYPE_CORE:
            rtType = RT_TARG::CORE_TYPE;
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
         */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            RUNTIME::MOD_CUST_CONF_HBRT_HYP_IDS,
            RUNTIME::RT_TARGET_TYPE_NOT_SUPPORTED,
            huid,
            targetingTargetType,
            true);

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
    TARGETING::PredicatePostfixExpr isaProcMembufOrCore;
    isaProcMembufOrCore.push(&isaProc).push(&isaMembuf).Or()
        .push(&isaCore).Or();
    TARGETING::TargetRangeFilter pIt(
        TARGETING::targetService().begin(),
        TARGETING::targetService().end(),
        &isaProcMembufOrCore);
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

            // PHyp only operates on fused cores, so all core IDs
            // must match that of the parent EX
            if(   (*pIt)->getAttr<TARGETING::ATTR_TYPE>()
               == TARGETING::TYPE_CORE)
            {
                auto type = TARGETING::TYPE_EX;
                const TARGETING::Target* pEx =
                      TARGETING::getParent(*pIt,type);

                // If this fails, everything is already hosed
                assert(pEx != NULL);

                hbrtHypId =
                    pEx->getAttr<TARGETING::ATTR_ORDINAL_ID>();
            }
            else
            {
                hbrtHypId = (*pIt)->getAttr<TARGETING::ATTR_ORDINAL_ID>();
            }

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
