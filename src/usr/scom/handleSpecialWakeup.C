/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/handleSpecialWakeup.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#include <targeting/common/util.H>

#include <scom/scomreasoncodes.H>
#include <initservice/initserviceif.H>

#ifdef __HOSTBOOT_RUNTIME
#include <runtime/rt_targeting.H>
#include <runtime/interface.h>
#endif // __HOSTBOOT_RUNTIME

#include <fapi2/plat_hwp_invoker.H>
#include <p9_cpu_special_wakeup.H>

extern "C"
{

// Trace definition
extern trace_desc_t* g_trac_scom;

using namespace TARGETING;
using namespace SCOM;

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
 * @param i_target  Input target core/ex/eq/etc
 * @param i_enable  Turn wakeup on or off
 */
errlHndl_t callWakeupHyp(TARGETING::Target* i_target, bool i_enable)
{
    errlHndl_t l_errl = NULL;

#ifdef __HOSTBOOT_RUNTIME
    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    // Check for valid interface function
    if( (g_hostInterfaces == NULL) ||
        (g_hostInterfaces->wakeup == NULL) )
    {
        TRACFCOMP( g_trac_scom,
                   ERR_MRK"Hypervisor wakeup interface not linked");

        /*@
         * @errortype
         * @moduleid     SCOM_CALL_WAKEUP_HYP
         * @reasoncode   SCOM_RUNTIME_INTERFACE_ERR
         * @userdata1    Target HUID
         * @userdata2    Wakeup Enable
         * @devdesc      Wakeup runtime interface not linked.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         SCOM_CALL_WAKEUP_HYP,
                                         SCOM_RUNTIME_INTERFACE_ERR,
                                         get_huid(i_target),
                                         i_enable);

        l_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);

        return l_errl;
    }

    TargetHandleList pCoreList;

    // If the target is already a core just push it on the list
    if(l_type == TARGETING::TYPE_CORE)
    {
        pCoreList.clear();
        pCoreList.push_back(i_target);
    }
    else
    {
        getChildChiplets( pCoreList, i_target, TARGETING::TYPE_CORE );
    }

    // Call wakeup on all core targets
    // Wakeup may be called twice for fused cores
    for ( auto pCore_it = pCoreList.begin();
          pCore_it != pCoreList.end();
          ++pCore_it )
    {
        // Runtime target id
        RT_TARG::rtChipId_t rtTargetId = 0;
        l_errl = RT_TARG::getRtTarget(*pCore_it, rtTargetId);
        if(l_errl)
        {
            break;
        }

        uint32_t mode;
        if(i_enable)
        {
            mode = HBRT_WKUP_FORCE_AWAKE;
        }
        else
        {
            mode = HBRT_WKUP_CLEAR_FORCE;
        }

        // Do the special wakeup
        int l_rc = g_hostInterfaces->wakeup(rtTargetId,mode);

        if(l_rc)
        {
            TRACFCOMP( g_trac_scom,ERR_MRK
                "Hypervisor wakeup failed. "
                "rc 0x%X target_huid 0x%llX rt_target_id 0x%llX mode %d",
                l_rc, get_huid(*pCore_it), rtTargetId, mode );

            // convert rc to error log
            /*@
             * @errortype
             * @moduleid         SCOM_CALL_WAKEUP_HYP
             * @reasoncode       SCOM_RUNTIME_WAKEUP_ERR
             * @userdata1        Hypervisor return code
             * @userdata2[0:31]  Runtime Target ID
             * @userdata2[32:63] Wakeup Mode
             * @devdesc          Hypervisor wakeup failed.
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

            break;
        }
    }

#else

    assert( false, "Cannot use host wakeup in IPL code!!" );

#endif

    return l_errl;
}


/**
 * @brief Call the wakeup HWP to control special wakeup
 * @param i_target  Input target core/ex/eq/etc
 * @param i_enable  Turn wakeup on or off
 */
errlHndl_t callWakeupHwp(TARGETING::Target* i_target, bool i_enable)
{
    errlHndl_t l_errl = NULL;
    fapi2::ReturnCode l_rc;

    TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

    if(l_type == TARGETING::TYPE_PROC)
    {
        // Call wakeup on all core targets
        TargetHandleList pCoreList;
        getChildChiplets( pCoreList, i_target, TARGETING::TYPE_CORE );

        for ( auto pCore_it = pCoreList.begin();
              pCore_it != pCoreList.end();
              ++pCore_it )
        {
            // To simplify, just call recursively with the core target
            l_errl = callWakeupHwp(*pCore_it, i_enable);
            if(l_errl)
            {
                break;
            }
        }
        return l_errl;
    }

    // Need to handle multiple calls to enable special wakeup
    // Count attribute will keep track and disable when zero
    // Assume HBRT is single-threaded, so no issues with concurrency
    uint32_t l_count = (i_target)->getAttr<ATTR_SPCWKUP_COUNT>();

    if((l_count==0) && !i_enable)
    {
        TRACFCOMP( g_trac_scom,ERR_MRK
            "Disabling special wakeup on target with SPCWKUP_COUNT=0");

        /*@
         * @errortype
         * @moduleid         SCOM_CALL_WAKEUP_HWP
         * @reasoncode       SCOM_SPCWKUP_COUNT_ERR
         * @userdata1        Target HUID
         * @userdata2[0:31]  Wakeup Enable
         * @userdata2[32:63] Wakeup Count
         * @devdesc          Disabling special wakeup when not enabled.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         SCOM_CALL_WAKEUP_HWP,
                                         SCOM_SPCWKUP_COUNT_ERR,
                                         get_huid(i_target),
                                         TWO_UINT32_TO_UINT64(
                                                    i_enable, l_count));

        l_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_LOW);

        errlCommit( l_errl, RUNTIME_COMP_ID );
    }

    // Only call the HWP if 0-->1 or 1-->0
    if( ((l_count==0) &&  i_enable) ||
        ((l_count==1) && !i_enable) )
    {
        // NOTE Regarding the entity type passed to the HWP:
        // There are 3 independent registers used to trigger a
        // special wakeup (FSP,HOST,OCC), we are using the FSP
        // bit because HOST/OCC are already in use.

        p9specialWakeup::PROC_SPCWKUP_OPS l_spcwkupType;
        p9specialWakeup::PROC_SPCWKUP_ENTITY l_spcwkupSrc;
        if(! INITSERVICE::spBaseServicesEnabled())
        {
            l_spcwkupSrc = p9specialWakeup::FSP;
        }
        else
        {
            l_spcwkupSrc = p9specialWakeup::HOST;
        }

        if(i_enable)
        {
            l_spcwkupType = p9specialWakeup::SPCWKUP_ENABLE;
        }
        else
        {
            l_spcwkupType = p9specialWakeup::SPCWKUP_DISABLE;
        }

        if(l_type == TARGETING::TYPE_EQ)
        {
            fapi2::Target<fapi2::TARGET_TYPE_EQ>
                l_fapi_target(const_cast<TARGETING::Target*>(i_target));

            FAPI_EXEC_HWP(l_rc,
                          p9_cpu_special_wakeup_eq,
                          l_fapi_target,
                          l_spcwkupType,
                          l_spcwkupSrc );
            l_errl = rcToErrl(l_rc, ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }
        else if(l_type == TARGETING::TYPE_EX)
        {
            fapi2::Target<fapi2::TARGET_TYPE_EX_CHIPLET>
                l_fapi_target(const_cast<TARGETING::Target*>(i_target));

            FAPI_EXEC_HWP(l_rc,
                          p9_cpu_special_wakeup_ex,
                          l_fapi_target,
                          l_spcwkupType,
                          l_spcwkupSrc );
            l_errl = rcToErrl(l_rc, ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }
        else if(l_type == TARGETING::TYPE_CORE)
        {
            fapi2::Target<fapi2::TARGET_TYPE_CORE>
                l_fapi_target(const_cast<TARGETING::Target*>(i_target));

            FAPI_EXEC_HWP(l_rc,
                          p9_cpu_special_wakeup_core,
                          l_fapi_target,
                          l_spcwkupType,
                          l_spcwkupSrc );
            l_errl = rcToErrl(l_rc, ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        }

        if(l_errl)
        {
            TRACFCOMP( g_trac_scom,
                    "p9_cpu_special_wakeup ERROR :"
                    " Returning errorlog, reason=0x%x",
                    l_errl->reasonCode() );

            // Capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );
        }
    }

    // Update the counter
    if(!l_errl)
    {
        if(i_enable)
        {
            l_count++;
        }
        else
        {
            l_count--;
        }
        i_target->setAttr<ATTR_SPCWKUP_COUNT>(l_count);
    }

    return l_errl;
}


/**
 * @brief Enable and disable special wakeup for SCOM operations
 */
errlHndl_t handleSpecialWakeup(TARGETING::Target* i_target, bool i_enable)
{
    errlHndl_t l_errl = NULL;

    static bool l_useHypWakeup = useHypWakeup();

    if( l_useHypWakeup )
    {
        l_errl = callWakeupHyp( i_target, i_enable );
    }
    else
    {
        l_errl = callWakeupHwp( i_target, i_enable );
    }

    return l_errl;
}

}
