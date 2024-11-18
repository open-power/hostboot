/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/call_host_voltage_config.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2024                        */
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
 *  @file call_host_voltage_config.C
 *  Contains the wrapper for istep 6.12
*/

#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <devicefw/userif.H>
#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>
#include <errl/hberrltypes.H>
#include <isteps/bios_attr_accessors/bios_attr_setters.H>

//Targeting
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

//Hwp
#include    <p10_setup_evid.H>
#include    <p10_sbe_scratch_regs.H>
#include    <p10_get_interposer_ecid.H>


using namespace TARGETING;


namespace ISTEP_06
{

void* call_host_voltage_config( void *io_pArgs )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_voltage_config entry" );

    ISTEP_ERROR::IStepError l_stepError;

    errlHndl_t l_err = nullptr;

    do
    {
        TARGETING::TargetHandleList l_procList;
        TARGETING::getAllChips(l_procList, TARGETING::TYPE_PROC);

        //get the boot interposer rev
        TARGETING::Target * boot_processor =   NULL;
        TARGETING::targetService().masterProcChipTargetHandle( boot_processor );
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>fapi_boot_processor(boot_processor);
        fapi2::variable_buffer l_ignored;

        FAPI_INVOKE_HWP(l_err, p10_get_interposer_ecid, fapi_boot_processor, l_ignored);
        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR p10_get_interposer_ecid target %.8X"
                      TRACE_ERR_FMT,
                      get_huid(boot_processor),
                      TRACE_ERR_ARGS(l_err));
            l_stepError.addErrorDetails(l_err);
            errlCommit( l_err, HWPF_COMP_ID );
        }

        auto boot_interposer_rev = boot_processor->getAttr<ATTR_INTERPOSER_REV>();

        // for each proc target
        for( const auto & l_proc : l_procList )
        {
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);

            //This applies the ATTR_INTERPOSER_REV from the boot processor on every proc target.
            //This is required because the registers containing the data cannot be accessed until the processors are started in step8 but the data is needed in step7.
            l_proc->setAttr<ATTR_INTERPOSER_REV>(boot_interposer_rev);

            // Sets up ATTR_FREQ_PAU_MHZ which is required by p10_setup_evid
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Running p10_sbe_scratch_regs_set_pll_buckets HWP on processor target %.8X",
                      get_huid(l_proc));

            FAPI_INVOKE_HWP(l_err,
                            p10_sbe_scratch_regs_set_pll_buckets,
                            l_fapiProc);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR in p10_sbe_scratch_regs_set_pll_buckets HWP "
                          "for HUID %.8x. "
                          TRACE_ERR_FMT,
                          get_huid(l_proc),
                          TRACE_ERR_ARGS(l_err));
                l_stepError.addErrorDetails(l_err);
                errlCommit( l_err, HWPF_COMP_ID );
                continue;
            }


            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "call_host_voltage_config: calling p10_setup_evid:"
                "COMPUTE_VOLTAGE_SETTINGS, Tgt=%.08X: ",
                get_huid(l_proc) );

            // call p10_setup_evid for each processor to first COMPUTE
            // the voltage settings for each proc
            FAPI_INVOKE_HWP(l_err,
                            p10_setup_evid,
                            l_fapiProc,
                            COMPUTE_VOLTAGE_SETTINGS);

            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                   "call_host_voltage_config: Error Back from p10_setup_evid:"
                   " COMPUTE_VOLTAGE_SETTINGS, Tgt=%.08X: "
                   TRACE_ERR_FMT,
                   get_huid(l_proc),
                   TRACE_ERR_ARGS(l_err));

                // Create IStep error log and cross reference occurred error
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );
                continue;
            }

        } // PROC for-loop

        // ####################################################################
        //TODO RTC:244307 Revisit if other HWP's need to be called to Validate
        //                Voltage Settings
        // ###################################################################
    } while( 0 );

    if( l_err )
    {
        // Create IStep error log and cross reference occurred error
        l_stepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, ISTEP_COMP_ID );

    }

#ifdef CONFIG_PLDM
    // Notify the BMC via PLDM BIOS attributes hb_cap_freq_mhz_min/max
    std::vector<uint8_t> string_table, attr_table;
    ISTEP::set_hb_cap_freq_mhz_min_max(string_table, attr_table, l_stepError);
#endif

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_voltage_config exit" );

    return l_stepError.getErrorHandle();
}

};
