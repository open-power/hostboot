/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_host_set_mem_volt.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2026                        */
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
 *  @file call_host_set_mem_volt.C
 *
 *  Support file for IStep: host_set_mem_volt
 *    Enable voltages on the DDIMMS
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

//  Error handling support
#include <errl/errlentry.H>             // errlHndl_t
#include <errl/errlmanager.H>
#include <istepHelperFuncs.H>           // captureError

//  Tracing support
#include <initservice/isteps_trace.H>   // g_trac_isteps_trace

//  FAPI support
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <isteps/hwpisteperror.H>       // IStepError

//  HWP call support
#include <chipids.H>                    // for EXPLORER ID
#include <pmic_enable.H>

#include <platform_vddr.H>              // platform_enable_vddr

#include <targeting/targplatutil.H>     // assertGetToplevelTarget
#include <hwpThread.H>


using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_11
{

class WorkItem_pmic_enable: public ISTEP::HwpWorkItem
{
  public:
    WorkItem_pmic_enable( IStepError& i_stepError,
                              Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "pmic_enable" ) {}

    virtual errlHndl_t run_hwp( void )
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        
        // ============================================================
        // FORCE TEST CASE 1: Simulate error with NO callout
        // ============================================================
        #if 0  // Enable this block to test "no callout" scenario
        TRACFCOMP(g_trac_isteps_trace, "HEYV TEST: Forcing error with NO callout");

        l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        ISTEP::MOD_VOLTAGE_CONFIG,
                        ISTEP::RC_FAILURE,
                        TARGETING::get_huid(iv_pTarget),
                        0);
        #endif
        
        // ============================================================
        // FORCE TEST CASE 2: Simulate error with callout but NO deconfig
        // ============================================================
        #if 0  // Enable this block to test "callout exists without deconfig" scenario
        TRACFCOMP(g_trac_isteps_trace, "HEYV TEST: Forcing error with callout but NO deconfig");

        l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        ISTEP::MOD_VOLTAGE_CONFIG,
                        ISTEP::RC_FAILURE,
                        TARGETING::get_huid(iv_pTarget),
                        1);
        // Add a callout WITHOUT deconfig/gard
        l_err->addHwCallout(iv_pTarget,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::NO_DECONFIG,
                           HWAS::GARD_NULL);
        #endif
        
        // ============================================================
        // FORCE TEST CASE 3: Simulate error with callout AND deconfig
        // ============================================================
        #if 1  // Enable this block to test "callout with deconfig already set" scenario
        TRACFCOMP(g_trac_isteps_trace, "HEYV TEST: Forcing error with callout AND deconfig");
  
        l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        ISTEP::MOD_VOLTAGE_CONFIG,
                        ISTEP::RC_FAILURE,
                        TARGETING::get_huid(iv_pTarget),
                        2);
        // Add a callout WITH deconfig
        l_err->addHwCallout(iv_pTarget,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::DECONFIG,
                           HWAS::GARD_NULL);
        #endif
        
        // ============================================================
        // Normal HWP call (comment out when testing)
        // ============================================================
        #if 0  // Set to 0 when testing above scenarios
        FAPI_INVOKE_HWP(l_err, pmic_enable, l_fapi_target);
        #endif
        
        // ============================================================
        // Check for callouts and add default if needed
        // ============================================================
        if (l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "HEYV pmic_enable returned error for OCMB 0x%08X",
                      TARGETING::get_huid(iv_pTarget));
            
            const auto search_results = l_err->queryCallouts(iv_pTarget);
            using compare_enum = ERRORLOG::ErrlEntry::callout_search_criteria;
            
            TRACFCOMP(g_trac_isteps_trace,
                      "HEYV queryCallouts returned: 0x%02X (TARGET_MATCH=%d, DECONFIG=%d, GARD=%d)",
                      search_results,
                      (search_results & compare_enum::TARGET_MATCH) ? 1 : 0,
                      (search_results & compare_enum::DECONFIG_FOUND) ? 1 : 0,
                      (search_results & compare_enum::GARD_FOUND) ? 1 : 0);
            
            // Check if we found any callouts for this OCMB
            if((search_results & compare_enum::TARGET_MATCH) == compare_enum::TARGET_MATCH)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "HEYV Found existing callout for OCMB 0x%08X",
                          TARGETING::get_huid(iv_pTarget));
                
                // If we found a callout for this OCMB w/o a DECONFIG,
                // edit the callout to include a deconfig
                if((search_results & compare_enum::DECONFIG_FOUND) != compare_enum::DECONFIG_FOUND)
                {
                    TRACFCOMP(g_trac_isteps_trace,
                              "HEYV Adding DECONFIG to existing callout for OCMB 0x%08X",
                              TARGETING::get_huid(iv_pTarget));
                    l_err->setDeconfigState(iv_pTarget, HWAS::DECONFIG);
                }
                else
                {
                    TRACFCOMP(g_trac_isteps_trace,
                              "HEYV Callout already has DECONFIG for OCMB 0x%08X",
                              TARGETING::get_huid(iv_pTarget));
                }
            }
            else
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "HEYV No callout found, adding default HW callout with DECONFIG/NO_GARD for OCMB 0x%08X",
                          TARGETING::get_huid(iv_pTarget));
                
                // No callout found for this OCMB, add one with DECONFIG/NO_GARD
                l_err->addHwCallout(iv_pTarget,
                                HWAS::SRCI_PRIORITY_LOW,
                                HWAS::DECONFIG,
                                HWAS::GARD_NULL);
            }
        }
    
        return l_err;
    }
};


void* call_host_set_mem_volt (void *io_pArgs)
{
    TRACFCOMP(
    g_trac_isteps_trace, ENTER_MRK"call_host_set_mem_volt");

    errlHndl_t  l_errl = nullptr;
    IStepError l_StepError;

    do {

    // Do not run voltage inits in MPIPL
    if(!UTIL::assertGetToplevelTarget()->getAttr<ATTR_IS_MPIPL_HB>())
    {
        // Disable voltage first (no-op on non-FSP systems)
        l_errl = platform_disable_vddr();
        if(l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace, ERR_MRK"call_host_set_mem_volt: could not disable voltages"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_StepError, ISTEP_COMP_ID);
            break;
        }

        // Send voltage config down to FSP. This is a no-op on non-FSP systems.
        l_errl = platform_enable_vddr();
        if(l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace, ERR_MRK"call_host_set_mem_volt: could not send voltage config to FSP"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_StepError, ISTEP_COMP_ID);
            break;
        }
    }


    Util::ThreadPool<ISTEP::HwpWorkItem> threadpool;

    // Create a vector of Target pointers
    TargetHandleList l_ocmbTargetList;

    // Get a list of all present OCMB chips. host_set_mem_volt will attempt to disable
    // PMICs on non-functional/deconfigured OCMBs prior to enabling PMICs on functional OCMBs
    getClassResources(l_ocmbTargetList, CLASS_CHIP, TYPE_OCMB_CHIP, UTIL_FILTER_PRESENT);

    for (auto l_ocmb_target: l_ocmbTargetList)
    {
        // PMICs are not present on Gemini, so skip this enable call
        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb_target->getAttr<ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16 ||
            chipId == POWER_CHIPID::ODYSSEY_16)
        {
            //  Create a new workitem from this membuf and feed it to the
            //  thread pool for processing.  Thread pool handles workitem
            //  cleanup.
            threadpool.insert(new WorkItem_pmic_enable(l_StepError,
                                                       *l_ocmb_target));
        }
    }

    // Start the threads and wait for completion
    if( ISTEP::HwpWorkItem::start_threads( threadpool,
                                           l_StepError,
                                           l_ocmbTargetList.size() ) )
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_host_set_mem_volt: start_threads returned an error for pmic_enable" );
        break;
    }

    } while(0);

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_set_mem_volt");
    return l_StepError.getErrorHandle();
}

};
