/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/handleSpecialWakeup.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <stdint.h>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <trace/interface.H>

#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/mfgFlagAccessors.H>

#include <scom/scomreasoncodes.H>
#include <initservice/initserviceif.H>

#ifdef __HOSTBOOT_RUNTIME
#include <targeting/runtime/rt_targeting.H>
#include <runtime/interface.h>
#endif // __HOSTBOOT_RUNTIME

#include <fapi2/plat_hwp_invoker.H>
#include <p10_core_special_wakeup.H>
#include <scom/wakeup.H>

// Trace definition
extern trace_desc_t* g_trac_scom;
const char* HBRT_TRACE_NAME = "HBRT";
const char* ISTEP_TRACE_NAME = "ISTEPS_TRACE";

using namespace TARGETING;
using namespace SCOM;

namespace WAKEUP
{

/**
 * @brief Check to see which type of wakeup we need to use
 * @return  true: Use Host wakeup interface;
 *          false: Use internal wakeup HWP
 */
bool useHypWakeup( void )
{
#ifdef __HOSTBOOT_RUNTIME
    // FSP and BMC runtime use hostservice for wakeup, provided that
    //  we are using a level of opal-prd that supports it

    // Always use the hyp call on FSP systems
    if( INITSERVICE::spBaseServicesEnabled() )
    {
        return true;
    }
    // PHYP always supports it
    else if( TARGETING::is_phyp_load() )
    {
        return true;
    }
    // On non-FSP + non-PHYP systems, explicitly check that the OPAL support
    //  is there
    else if( (g_hostInterfaces != NULL) &&
             (g_hostInterfaces->get_interface_capabilities != NULL) &&
             (g_hostInterfaces->get_interface_capabilities(HBRT_CAPS_SET1_OPAL)
              & HBRT_CAPS_OPAL_HAS_WAKEUP) &&
             (g_hostInterfaces->wakeup != NULL) )
    {
        return true;
    }

    return false;

#else

    // IPL time always uses our internal version
    return false;

#endif
}

/**
 * @brief Use the Host/Hyp interface to control special wakeup
 * @param     i_target   - Input target core
 * @param[in] i_enable   - set or clear or clear all of the wakeups
 */
errlHndl_t callWakeupHyp(TARGETING::Target* i_target,
                         HandleOptions_t i_enable)
{
    errlHndl_t l_errl = NULL;

#ifdef __HOSTBOOT_RUNTIME

    do {
        // Check for valid interface function
        if( (g_hostInterfaces == NULL) ||
            (g_hostInterfaces->wakeup == NULL) )
        {
            TRACFCOMP( g_trac_scom,ERR_MRK
                       "callWakeupHyp> Hypervisor wakeup interface not linked");

            /*@
             * @errortype
             * @moduleid     SCOM_CALL_WAKEUP_HYP
             * @reasoncode   SCOM_RUNTIME_INTERFACE_ERR
             * @userdata1    Target HUID
             * @userdata2    Wakeup Enable
             * @devdesc      Wakeup runtime interface not linked.
             * @custdesc         Internal firmware error.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             SCOM_CALL_WAKEUP_HYP,
                                             SCOM_RUNTIME_INTERFACE_ERR,
                                             get_huid(i_target),
                                             i_enable,
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            l_errl->collectTrace(HBRT_TRACE_NAME,1024);
            l_errl->collectTrace(ISTEP_TRACE_NAME,512);
            break;
        }

        // Runtime target id
        TARGETING::rtChipId_t rtTargetId = 0;
        l_errl = TARGETING::getRtTarget(i_target, rtTargetId);
        if(l_errl)
        {
            break;
        }

        uint32_t mode;
        if(i_enable == WAKEUP::ENABLE)
        {
            mode = HBRT_WKUP_FORCE_AWAKE;
        }
        else if(i_enable == WAKEUP::DISABLE)
        {
            mode = HBRT_WKUP_CLEAR_FORCE;
        }
        else if(i_enable == WAKEUP::FORCE_DISABLE)
        {
            mode = HBRT_WKUP_CLEAR_FORCE_COMPLETELY;
        }
        else
        {
            /*@
             * @errortype
             * @moduleid         SCOM_HANDLE_SPECIAL_WAKEUP
             * @reasoncode       SCOM_INVALID_WAKEUP_PARM
             * @userdata1        Wakeup Argument
             * @userdata2        Input Target
             * @devdesc          Invalid mode parm for wakeup operation.
             * @custdesc         Internal firmware error.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        SCOM_HANDLE_SPECIAL_WAKEUP,
                                        SCOM_INVALID_WAKEUP_PARM,
                                        i_enable,
                                        TARGETING::get_huid(i_target),
                                        ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
            l_errl->collectTrace(HBRT_TRACE_NAME,1024);
            l_errl->collectTrace(ISTEP_TRACE_NAME,512);
            break;
        }

        // PHYP supports the complete clear but OPAL might not yet
        if( (mode == HBRT_WKUP_CLEAR_FORCE_COMPLETELY)
            && !TARGETING::is_phyp_load()
            && !(g_hostInterfaces->
                 get_interface_capabilities(HBRT_CAPS_SET1_OPAL)
                 & HBRT_CAPS_OPAL_HAS_WAKEUP_CLEAR) )
        {
            TRACFCOMP( g_trac_scom, "No support for forced clear, skipping" );
            break;
        }

        // Do the special wakeup
        int l_rc = g_hostInterfaces->wakeup(rtTargetId,mode);

        // Check for the specific case where PHYP has detected a core
        //  checkstop and will fail no matter what
        if( HBRT_RC_WAKEUP_INVALID_ON_CORE_XSTOP == l_rc )
        {
            TRACFCOMP( g_trac_scom,ERR_MRK
                       "callWakeupHyp> Wakeup on %.8X failed due to core checkstop",
                       TARGETING::get_huid(i_target) );
        }
        // Any other failure is valid
        else if(l_rc)
        {
            TRACFCOMP( g_trac_scom,ERR_MRK
                "callWakeupHyp> Hypervisor wakeup failed. "
                "rc 0x%X target_huid 0x%llX rt_target_id 0x%llX mode %d",
                l_rc, get_huid(i_target), rtTargetId, mode );

            // convert rc to error log
            /*@
             * @errortype
             * @moduleid         SCOM_CALL_WAKEUP_HYP
             * @reasoncode       SCOM_RUNTIME_WAKEUP_ERR
             * @userdata1        Hypervisor return code
             * @userdata2[0:31]  Runtime Target ID
             * @userdata2[32:63] Wakeup Mode
             * @devdesc          Hypervisor wakeup failed.
             * @custdesc         Internal firmware error.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        SCOM_CALL_WAKEUP_HYP,
                                        SCOM_RUNTIME_WAKEUP_ERR,
                                        l_rc,
                                        TWO_UINT32_TO_UINT64(
                                                    rtTargetId, mode));

            l_errl->addHwCallout(i_target,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL);

            l_errl->collectTrace(HBRT_TRACE_NAME,1024);
            l_errl->collectTrace(ISTEP_TRACE_NAME,512);
            break;
        }
    } while(0);

#else

    assert( false, "Cannot use host wakeup in IPL code!!" );

#endif

    return l_errl;
}


/**
 * @brief Call the wakeup HWP to control special wakeup
 * @param i_target  Input target core/ex/eq/etc
 * @param[in] i_enable   - set or clear or clear all of the wakeups
 */
errlHndl_t callWakeupHwp(TARGETING::Target* i_target,
                         HandleOptions_t i_enable)
{
    errlHndl_t l_errl = NULL;

    auto l_targType = i_target->getAttr<TARGETING::ATTR_TYPE>();

    // Need to handle multiple calls to enable special wakeup
    // Count attribute will keep track and disable when zero
    // Assume HBRT is single-threaded, so no issues with concurrency
    uint32_t l_count = 0xFFFF;

    // Skip count updates in some error scenarios
    bool l_skipCountModify = false;

    // need to consolidate all cores
    if( TARGETING::TYPE_PROC == l_targType )
    {
        TargetHandleList pCoreList;
        getChildChiplets( pCoreList, i_target, TARGETING::TYPE_CORE );
        for( auto core : pCoreList )
        {
            uint32_t tmp_count = core->getAttr<ATTR_SPCWKUP_COUNT>();
            if( l_count == 0xFFFF )
            {
                l_count = tmp_count;
            }
            else if( tmp_count != l_count )
            {
                TRACFCOMP( g_trac_scom,ERR_MRK
                           "callWakeupHwp> Inconsistent core wakeup counts on %.8X : exp=%d, act=%d",
                           TARGETING::get_huid(core),
                           l_count, tmp_count );
                /*@
                 * @errortype
                 * @moduleid         SCOM_CALL_WAKEUP_HWP
                 * @reasoncode       SCOM_SPCWKUP_COUNT_INCONSISTENT
                 * @userdata1[00:31] Processor Target HUID
                 * @userdata1[32:63] Core Target HUID
                 * @userdata2[00:31] Wakeup Enable
                 * @userdata2[32:47] Previous Wakeup Count (ATTR_SPCWKUP_COUNT)
                 * @userdata2[48:63] Current Wakeup Count (ATTR_SPCWKUP_COUNT)
                 * @devdesc          Unexpectedly forcing wakeup off when the counter
                 *                   is non-zero, implies a bug in the code flow.
                 * @custdesc         Internal firmware error.
                 */
                l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                                 SCOM_CALL_WAKEUP_HWP,
                                                 SCOM_SPCWKUP_COUNT_INCONSISTENT,
                                                 TWO_UINT32_TO_UINT64(
                                                            get_huid(i_target),
                                                            get_huid(core)),
                                                 TWO_UINT32_TO_UINT64(
                                                            i_enable,
                                                            TWO_UINT16_TO_UINT32(
                                                                 l_count,
                                                                 tmp_count)),
                                                 ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                l_errl->collectTrace(HBRT_TRACE_NAME,1024);
                l_errl->collectTrace(FAPI2_COMP_NAME,512);
                l_errl->collectTrace(ISTEP_TRACE_NAME,512);
                errlCommit( l_errl, RUNTIME_COMP_ID );
            }
        }
    }
    else //single CORE
    {
        l_count = (i_target)->getAttr<ATTR_SPCWKUP_COUNT>();
    }

    if((l_count==0) && (i_enable==WAKEUP::DISABLE))
    {
        TRACFCOMP( g_trac_scom,ERR_MRK
            "callWakeupHwp> Disabling special wakeup on target with SPCWKUP_COUNT=0");

        /*@
         * @errortype
         * @moduleid         SCOM_CALL_WAKEUP_HWP
         * @reasoncode       SCOM_SPCWKUP_COUNT_ERR
         * @userdata1        Target HUID
         * @userdata2[0:31]  Wakeup Enable
         * @userdata2[32:63] Wakeup Count (ATTR_SPCWKUP_COUNT)
         * @devdesc          Disabling special wakeup when not enabled.
         * @custdesc         Internal firmware error.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         SCOM_CALL_WAKEUP_HWP,
                                         SCOM_SPCWKUP_COUNT_ERR,
                                         get_huid(i_target),
                                         TWO_UINT32_TO_UINT64(
                                                    i_enable, l_count),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(HBRT_TRACE_NAME,1024);
        l_errl->collectTrace(FAPI2_COMP_NAME,512);
        l_errl->collectTrace(ISTEP_TRACE_NAME,512);

        errlCommit( l_errl, RUNTIME_COMP_ID );
        l_skipCountModify = true; // do not subtract from zero
    }

    if( (l_count>0) && (i_enable==WAKEUP::FORCE_DISABLE) )
    {
        TRACFCOMP( g_trac_scom,ERR_MRK
                   "Attempting to force disable special wakeup on %.8X with SPCWKUP_COUNT=%d",
                   TARGETING::get_huid(i_target), l_count);
        /*@
         * @errortype
         * @moduleid         SCOM_CALL_WAKEUP_HWP
         * @reasoncode       SCOM_UNEXPECTED_FORCE_WAKEUP
         * @userdata1        Target HUID
         * @userdata2[0:31]  Wakeup Enable
         * @userdata2[32:63] Wakeup Count (ATTR_SPCWKUP_COUNT)
         * @devdesc          Unexpectedly forcing wakeup off when the counter
         *                   is non-zero, implies a bug in the code flow.
         * @custdesc         Internal firmware error.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         SCOM_CALL_WAKEUP_HWP,
                                         SCOM_UNEXPECTED_FORCE_WAKEUP,
                                         get_huid(i_target),
                                         TWO_UINT32_TO_UINT64(
                                                    i_enable, l_count),
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
        l_errl->collectTrace(HBRT_TRACE_NAME,1024);
        l_errl->collectTrace(FAPI2_COMP_NAME,512);
        l_errl->collectTrace(ISTEP_TRACE_NAME,512);

        errlCommit( l_errl, RUNTIME_COMP_ID );
    }

    // Only call the HWP if 0-->1 or 1-->0 or if it is a force
    if( ((l_count==0) && (i_enable==WAKEUP::ENABLE)) ||
        ((l_count==1) && (i_enable==WAKEUP::DISABLE)) ||
        (i_enable==WAKEUP::FORCE_DISABLE) )
    {
        // NOTE Regarding the entity type passed to the HWP:
        // There are 3 independent registers used to trigger a
        // special wakeup (FSP,HOST,OCC), we are using the FSP
        // bit because HOST/OCC are already in use.
        p10specialWakeup::PROC_SPCWKUP_OPS l_spcwkupType;

        if(i_enable==WAKEUP::ENABLE)
        {
            l_spcwkupType = p10specialWakeup::SPCWKUP_ENABLE;
        }
        else  // DISABLE or FORCE_DISABLE
        {
            l_spcwkupType = p10specialWakeup::SPCWKUP_DISABLE;
        }

        // Different inputs require different fapi target handling
        if( TARGETING::TYPE_PROC == l_targType )
        {
            // first get the fapi proc target to use below
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapiProc(i_target);

            // generate a multicast target that covers the cores
            fapi2::Target < fapi2::TARGET_TYPE_CORE | fapi2::TARGET_TYPE_MULTICAST >
              l_fapi_mc_core = l_fapiProc.getMulticast< fapi2::MULTICAST_OR >
              (fapi2::MCGROUP_GOOD_EQ, fapi2::MCCORE_ALL);

            FAPI_INVOKE_HWP(l_errl,
                            p10_core_special_wakeup,
                            l_fapi_mc_core,
                            l_spcwkupType,
                            p10specialWakeup::HOST);
            if(l_errl)
            {
                TRACFCOMP( g_trac_scom,ERR_MRK
                           "callWakeupHwp> p10_core_special_wakeup(multicast %.8X, op=%d)",
                           TARGETING::get_huid(i_target),
                           l_spcwkupType );

                // Capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );

                l_errl->collectTrace(SCOM_COMP_NAME,512);
                l_errl->collectTrace(HBRT_TRACE_NAME,512);
                l_errl->collectTrace(ISTEP_TRACE_NAME,512);
            }
        }
        else if( TARGETING::TYPE_CORE == l_targType )
        {
            TRACFCOMP( g_trac_scom,
                    "callWakeupHwp> p10_uc_core_special_wakeup(core %.8X)",
                    TARGETING::get_huid(i_target) );

            // use a regular core target
            fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapi_core(i_target);
            fapi2::ReturnCode l_rc = 0;

            if (i_target->getAttr<ATTR_DEAD_CORE_MODE>() == 
                fapi2::ENUM_ATTR_DEAD_CORE_MODE_ENABLED)
            {
                TRACFCOMP(g_trac_scom,INFO_MRK
                        "callWakeupHwp> p10_uc_core_special_wakeup (DEAD core %.8x op=%dis skipped from hwp)",
                        TARGETING::get_huid(i_target),
                        l_spcwkupType );
            }
            else
            {
                FAPI_INVOKE_HWP_RC(l_errl,
                        l_rc,
                        p10_uc_core_special_wakeup,
                        l_fapi_core,
                        l_spcwkupType,
                        p10specialWakeup::HOST);
            }
            if (l_rc == (fapi2::ReturnCode)fapi2::RC_ECO_CORE_SPWU_SKIPPED)
            {
                TRACFCOMP(g_trac_scom,INFO_MRK
                        "callWakeupHwp> p10_uc_core_special_wakeup (ECO core %.8x op=%dis skipped from hwp)",
                        TARGETING::get_huid(i_target),
                        l_spcwkupType );
                delete l_errl;
                l_errl = NULL;
            }
            else if(l_errl) // any other RC
            {
                TRACFCOMP( g_trac_scom,ERR_MRK
                        "callWakeupHwp> p10_uc_core_special_wakeup(core %.8X, op=%d)",
                        TARGETING::get_huid(i_target),
                        l_spcwkupType );

                // Capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );

                l_errl->collectTrace(SCOM_COMP_NAME,512);
                l_errl->collectTrace(HBRT_TRACE_NAME,512);
                l_errl->collectTrace(ISTEP_TRACE_NAME,512);
            }
        }
        else
        {
            TRACFCOMP( g_trac_scom,ERR_MRK
                       "callWakeupHwp> Invalid target type (0x%X) for wakeup call : huid=%.8X",
                       l_targType,
                       TARGETING::get_huid(i_target));
            /*@
             * @errortype
             * @moduleid         SCOM_CALL_WAKEUP_HWP
             * @reasoncode       SCOM_BAD_TARGET
             * @userdata1        Target HUID
             * @userdata2        Target Type
             * @devdesc          Invalid target type for wakeup call.
             * @custdesc         Internal firmware error.
             */
             l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                              SCOM_CALL_WAKEUP_HWP,
                                              SCOM_BAD_TARGET,
                                              get_huid(i_target),
                                              l_targType,
                                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );
             l_errl->collectTrace(SCOM_COMP_NAME,512);
             l_errl->collectTrace(HBRT_TRACE_NAME,512);
             l_errl->collectTrace(ISTEP_TRACE_NAME,512);
             l_errl->collectTrace(FAPI2_COMP_NAME,512);

             errlCommit( l_errl, RUNTIME_COMP_ID );
        }

    }

    // Update the counter
    if(!l_errl && !l_skipCountModify)
    {
        if(i_enable == WAKEUP::ENABLE)
        {
            l_count++;
        }
        else if(i_enable == WAKEUP::DISABLE)
        {
            l_count--;
        }
        else if(i_enable == WAKEUP::FORCE_DISABLE)
        {
            l_count = 0;
        }

        if( TARGETING::TYPE_PROC == l_targType )
        {
            TargetHandleList pCoreList;
            getChildChiplets( pCoreList, i_target, TARGETING::TYPE_CORE );
            for( auto core : pCoreList )
            {
                core->setAttr<ATTR_SPCWKUP_COUNT>(l_count);
            }
        }
        else //CORE
        {
            i_target->setAttr<ATTR_SPCWKUP_COUNT>(l_count);
        }
    }

    return l_errl;
}

/**
 * @brief Check if a given core is alive or not
 * @param[in]  Core Target
 * @param[out]  True: Core is dead, False: Core is active
 * @return  Error log handle
 */
errlHndl_t checkForDeadCore( TARGETING::Target* i_core,
                             bool& o_coreIsDead )
{
    errlHndl_t l_errhdl = nullptr;
    o_coreIsDead = false; //assume things are okay

    // Read QME Scratch Register A (200E0124)
    // if bit[0:3] is 1, that core is marked dead by HYP due to a PM Malfunction

    // Register is EQ-scoped, so need to find the core's parent EQ
    // Get the connected parent, should be one and only one parent
    TargetHandleList l_eqlist;
    TARGETING::getParentAffinityTargetsByState( l_eqlist,
                                                i_core,
                                                TARGETING::CLASS_UNIT,
                                                TARGETING::TYPE_EQ,
                                                TARGETING::UTIL_FILTER_ALL );
    assert( (1 == l_eqlist.size()) && (nullptr != l_eqlist[0]),
            "No EQ parent for Core %.8X", TARGETING::get_huid(i_core) );

    uint64_t l_qmeScratchA = 0;
    auto l_reqSize = sizeof(l_qmeScratchA);
    l_errhdl = DeviceFW::deviceRead( l_eqlist[0],
                                     &l_qmeScratchA,
                                     l_reqSize,
                                     DEVICE_SCOM_ADDRESS(0x200E0124));
    if( !l_errhdl )
    {
        // Figure out which core this is relative to the EQ
        //  Cannot use ATTR_REL_POS because that is relative
        //  to the FC parent, not the EQ.  Instead use the
        //  knowleve that a quad has 4 cores.
        auto l_corenum = i_core->getAttr<ATTR_CHIP_UNIT>();
        uint64_t l_mask = 0x8000000000000000 >> (l_corenum%4);
        if( l_qmeScratchA & l_mask )
        {
            o_coreIsDead = true;
        }
    }

    return l_errhdl;
}


/**
 * @brief Enable and disable special wakeup for SCOM and FAPI operations
 */
errlHndl_t handleSpecialWakeup(TARGETING::Target* i_target,
                               HandleOptions_t i_enable)
{
    errlHndl_t l_errl = NULL;

    do {
#ifndef __HOSTBOOT_RUNTIME //IPL context
        // Always use the HWP inside the IPL context
        l_errl = callWakeupHwp(i_target, i_enable);
        if (l_errl)
        {
            break;
        }

#else //Runtime context
        // Extended Cache-Only (ECO) cores and non-ECO cores must be handled individually.
        TargetHandleList l_ecoCores, l_nonEcoCores;

        // Determines in a general case which wakeup interface to call.
        static bool l_useHypWakeup = useHypWakeup();

        // Figure out all the right targets at runtime
        if (i_target->getAttr<ATTR_TYPE>() == TYPE_CORE)
        {
            if (i_target->getAttr<ATTR_ECO_MODE>() == ECO_MODE_ENABLED)
            {
                l_ecoCores.push_back(i_target);
            }
            else if (i_target->getAttr<ATTR_ECO_MODE>() == ECO_MODE_DISABLED)
            {
                l_nonEcoCores.push_back(i_target);
            }
            else
            {
                /*@
                 * @errortype
                 * @moduleid         SCOM_HANDLE_SPECIAL_WAKEUP
                 * @reasoncode       SCOM_INVALID_ECO_TYPE
                 * @userdata1        ECO mode
                 * @userdata2[0:31]  Core huid
                 * @devdesc          Supplied core chiplet had an invalid ECO mode setting.
                 * @custdesc         Internal firmware error.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                                            SCOM_CALL_WAKEUP_HYP,
                                            SCOM_RUNTIME_WAKEUP_ERR,
                                            i_target->getAttr<ATTR_ECO_MODE>(),
                                            get_huid(i_target),
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }
        }
        else
        {
            // Given target is not an CORE target. Need to gather up all its ECO and non-ECO CORE children for
            // processing.
            getNonEcoCores(l_nonEcoCores, i_target);
            getEcoCores(l_ecoCores, i_target);
            TRACDCOMP(g_trac_scom, "i_target HUID[0x%x]: ECO cores %d, NON-ECO cores %d",
                      get_huid(i_target),
                      l_ecoCores.size(),
                      l_nonEcoCores.size());
        }
        TRACDCOMP( g_trac_scom, "l_useHypWakeup = %s", l_useHypWakeup ? "TRUE" : "FALSE");

        // Always call the HWP for ECO cores since the hypervisor doesn't know about ECO COREs and asking it to wake
        // them would result in an error.
        for (auto l_core : l_ecoCores)
        {
            // We need to skip the wakeup call if the core has already died.
            bool l_coreIsDead = false;
            l_errl = checkForDeadCore(l_core,l_coreIsDead);
            if( l_errl )
            {
                break;
            }
            else if( l_coreIsDead )
            {
                TRACFCOMP( g_trac_scom, "Skipping wakeup for dead core %.8X",
                           TARGETING::get_huid(l_core) );
                continue;
            }

            l_errl = callWakeupHwp(l_core, i_enable);
            if (l_errl)
            {
                break;
            }
        }
        if (l_errl)
        {
            break;
        }

        // Non-ECO cores can use the general case determination for which wakeup interface to call.
        for (auto l_core : l_nonEcoCores)
        {
            // We need to skip the wakeup call if the core has already died.
            bool l_coreIsDead = false;
            l_errl = checkForDeadCore(l_core,l_coreIsDead);
            if( l_errl )
            {
                break;
            }
            else if( l_coreIsDead )
            {
                TRACFCOMP( g_trac_scom, "Skipping wakeup for dead core %.8X",
                           TARGETING::get_huid(l_core) );
                continue;
            }

            if( l_useHypWakeup )
            {
                l_errl = callWakeupHyp(l_core, i_enable);
            }
            else
            {
                l_errl = callWakeupHwp(l_core, i_enable);
            }
            if (l_errl)
            {
                break;
            }
        }
        if (l_errl)
        {
            break;
        }
#endif //__HOSTBOOT_RUNTIME

    } while(0);

    return l_errl;
}

/**
 * @brief Enable or disable special wakeup logic
 */
void controlWakeupLogic( WakeupControl_t i_op )
{
    // We will control the calls to the HWP by playing with the
    //  wakeup counter that we already use to handle recursion.

    // Grab all the cores in the system (even not present/functional)
    TARGETING::TargetHandleList l_cores;
    TARGETING::getAllChiplets( l_cores, TARGETING::TYPE_CORE, false );

    // Loop through all the cores and set the counter value as needed
    for( auto c : l_cores )
    {
        TARGETING::ATTR_SPCWKUP_COUNT_type l_count = 0;
        switch(i_op)
        {
            case( DISABLE_SPECIAL_WAKEUP ):
                l_count = 0xFF;//arbitrary non-zero value
                break;
            case( ENABLE_SPECIAL_WAKEUP ):
                l_count = 0x00;//start fresh with no wakeups pending
                break;
        }
        c->setAttr<ATTR_SPCWKUP_COUNT>(l_count);
    }
}

}
