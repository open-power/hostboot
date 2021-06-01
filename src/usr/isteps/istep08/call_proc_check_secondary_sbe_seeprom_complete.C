/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_check_secondary_sbe_seeprom_complete.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
 *  @file call_proc_check_secondary_sbe_seeprom_complete.C
 *
 *  Support file for IStep: proc_check_secondary_sbe_seeprom_complete
 *   Secondary SBE
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <hbotcompid.H>           // HWPF_COMP_ID
#include <attributeenums.H>       // TYPE_PROC
#include <isteps/hwpisteperror.H> //ISTEP_ERROR:IStepError
#include <istepHelperFuncs.H>     // captureError
#include <fapi2/plat_hwp_invoker.H>
#include <nest/nestHwpHelperFuncs.H>
#include <sbeio/sbe_retry_handler.H>
#include <sbeio/sbeioif.H>
#include <errl/errludtarget.H>
#include <spi/spi.H> // for SPI lock support
#include <p10_getecid.H>
#include <util/utilmbox_scratch.H>
#include <hwas/hwasPlat.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;
using namespace ERRORLOG;
using namespace SBEIO;

namespace ISTEP_08
{

//******************************************************************************
// call_proc_check_secondary_sbe_seeprom_complete function
//******************************************************************************
void* call_proc_check_secondary_sbe_seeprom_complete( void *io_pArgs )
{
    IStepError  l_stepError;
    errlHndl_t  l_errl = nullptr;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_check_secondary_sbe_seeprom_complete");

    //
    //  get the master Proc target, we want to IGNORE this one.
    //
    Target* l_pMasterProcTarget = nullptr;
    targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    //
    //  get a list of all the procs in the system
    //
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    TRACFCOMP(g_trac_isteps_trace,
        "proc_check_secondary_sbe_seeprom_complete: %d procs in the system.",
        l_cpuTargetList.size());

    // loop thru all the cpus
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        if ( l_cpu_target  ==  l_pMasterProcTarget )
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "Master SBE found, HUID %.8X, "
                      "skipping to look for Slave SBEs.",
                      get_huid(l_cpu_target));
            // we are just checking the Slave SBEs, skip the master
            continue;
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                            const_cast<Target*> (l_cpu_target));

        TRACFCOMP(g_trac_isteps_trace,
                  "Running p10_get_sbe_msg_register HWP"
                  " on processor target %.8X",
                  get_huid(l_cpu_target));

        //Note no PLID passed in
        SbeRetryHandler l_SBEobj = SbeRetryHandler(
                SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT);

        l_SBEobj.setSbeRestartMethod(SbeRetryHandler::
                                     SBE_RESTART_METHOD::START_CBS);

        // We want to tell the retry handler that we have just powered
        // on the sbe, to distinguish this case from other cases where
        // we have determined there is something wrong w/ the sbe and
        // want to diagnose the problem
        l_SBEobj.setInitialPowerOn(true);

        // Enable HB SPI operations to this slave processor before
        // checking for success because we may end up doing SPI
        // operations (writing MVPD) as part of the recovery.
        l_errl = SPI::spiLockProcessor(l_cpu_target, false);
        if (l_errl)
        {
            // This would be a firmware bug that would be hard to
            // find later so terminate with this failure
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR : SPI unlock failed to target %.8X"
                      TRACE_ERR_FMT,
                      get_huid(l_cpu_target),
                      TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            break;
        }

        // Poll for SBE boot complete
        l_SBEobj.main_sbe_handler(l_cpu_target);

        // We will judge whether or not the SBE had a successful
        // boot if it made it to runtime
        if(l_SBEobj.isSbeAtRuntime())
        {
            // Set attribute indicating that SBE is started
            l_cpu_target->setAttr<ATTR_SBE_IS_STARTED>(1);

            // Make the FIFO call to get and apply the SBE Capabilities
            // for secondary SBEs
            l_errl = getFifoSbeCapabilities(l_cpu_target);
            if (l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace, ERR_MRK
                      "proc_check_secondary_sbe_seeprom_complete: "
                      " getFifoSbeCapabilities(proc 0x%.8X) failed",
                      get_huid(l_cpu_target));

                // allow istep to continue to SBE update
                // prevent reconfig loop by removing deconfig
                l_errl->removeGardAndDeconfigure();
                // Ensure the error log is visible.
                if ( l_errl->sev() < ERRORLOG::ERRL_SEV_PREDICTIVE )
                {
                    l_errl->setSev( ERRORLOG::ERRL_SEV_PREDICTIVE );
                }
                l_errl->collectTrace("ISTEPS_TRACE", 256);
                errlCommit(l_errl, ISTEP_COMP_ID); // commit error and move on
            }

            // Switch to using SBE SCOM
            ScomSwitches l_switches =
                l_cpu_target->getAttr<ATTR_SCOM_SWITCHES>();
            ScomSwitches l_switches_before = l_switches;

            // Turn on SBE SCOM and turn off FSI SCOM.
            l_switches.useFsiScom = 0;
            l_switches.useSbeScom = 1;

            TRACFCOMP(g_trac_isteps_trace,
                      "proc_check_secondary_sbe_seeprom_complete: changing SCOM"
                      " switches from 0x%.2X to 0x%.2X for proc 0x%.8X",
                      l_switches_before,
                      l_switches,
                      get_huid(l_cpu_target));
            l_cpu_target->setAttr<ATTR_SCOM_SWITCHES>(l_switches);

            TRACFCOMP(g_trac_isteps_trace,
                      "SUCCESS : proc_check_secondary_sbe_seeprom_complete"
                      " completed ok for proc 0x%.8X",
                      get_huid(l_cpu_target));

            // Ensure that the mailbox scratch registers 1 and 2 match what we
            // calculated for functional state

            const auto l_scratch = Util::readScratchRegs(l_cpu_target);

            TRACFCOMP(g_trac_isteps_trace,
                      "proc_check_secondary_sbe_seeprom_complete: "
                      "Checking SBE functional state scratch registers on processor 0x%08x",
                      get_huid(l_cpu_target));

            l_errl = HWAS::HWASPlatVerification().verifyDeconfiguration(l_cpu_target, l_scratch);

            // This shouldn't ever fail because Hostboot pushes the values to
            // the secondary SBEs, so if it does then make the error
            // UNRECOVERABLE.
            if (l_errl)
            {
                l_errl->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                l_errl->collectTrace("ISTEPS_TRACE", 256);
                captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            }
        }
        else
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "FAILURE : proc_check_secondary_sbe_seeprom_complete"
                      "SBE for proc 0x%.8X did not reach runtime",
                      get_huid(l_cpu_target));
           /*@
            * @reasoncode RC_FAILED_TO_BOOT_SBE
            * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid   MOD_CHECK_SECONDARY_SBE_SEEPROM_COMPLETE
            * @userdata1  HUID of proc that failed to boot its SBE
            * @userdata2  Unused
            * @devdesc    Failed to boot a slave SBE
            * @custdesc   Processor Error
            */
            l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                            MOD_CHECK_SECONDARY_SBE_SEEPROM_COMPLETE,
                                            RC_FAILED_TO_BOOT_SBE,
                                            get_huid(l_cpu_target),
                                            0);
            l_errl->collectTrace("ISTEPS_TRACE", 256);
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);


        }

/* @TODO-RTC:100963 This should only be called when the SBE has completely
              crashed. There is a path in OpenPower where HB may get an
              attention and need to call it. For now, though, just associate
              with this story for tracking.

        // Not a way to pass in -soft_err, assuming that is default behavior
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9_extract_sbe_rc HWP"
                " on processor target %.8X",
                  TARGETING::get_huid(l_cpu_target) );

**/
        // Need to switch SPI control register back to FSI_ACCESS mode
        // since SBE will flip the access mode into PIB_ACCESS
        l_errl = SPI::spiSetAccessMode(l_cpu_target, SPI::FSI_ACCESS);
        if (l_errl)
        {
            // This would be another hard to find firmware bug so terminate
            // with this failure
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR: SPI access mode switch to FSI_ACCESS failed for target %.8X"
                      TRACE_ERR_FMT,
                      get_huid(l_cpu_target),
                      TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            break;
        }

    }   // end of going through all slave processors

    //  Once the sbes are up correctly, fetch all the proc ECIDs and
    //  store them in an attribute.
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
      const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                          const_cast<Target*> (l_cpu_target));

      TRACFCOMP(g_trac_isteps_trace,
                "Running p10_getecid HWP"
                " on processor target %.8X",
                get_huid(l_cpu_target));

      //  p10_getecid should set the fuse string to proper length
      fapi2::variable_buffer  l_fuseString(p10_getecid_fuseString_len);

      // Invoke the HWP
      FAPI_INVOKE_HWP(l_errl,
                      p10_getecid,
                      l_fapi2ProcTarget,
                      l_fuseString);

      if (l_errl)
      {
        if (l_cpu_target->getAttr<ATTR_HWAS_STATE>().functional)
        {
            TRACFCOMP(g_trac_isteps_trace,
                    "ERROR : p10_getecid failed, returning errorlog target %.8X"
                    TRACE_ERR_FMT,
                    get_huid(l_cpu_target),
                    TRACE_ERR_ARGS(l_errl));

            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
        }
        else // Not functional, proc deconfigured, don't report error
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR : p10_getecid failed, proc target %.8X deconfigured",
                      get_huid(l_cpu_target));
            delete l_errl;
            l_errl = nullptr;
        }
      }
      else
      {
          TRACFCOMP(g_trac_isteps_trace,
                    "SUCCESS : proc_getecid completed ok target %.8X",
                    get_huid(l_cpu_target));

          // Update HDAT_EC to account for anything lower than the minor EC
          auto l_miniEC = l_cpu_target->getAttr<ATTR_MINI_EC>();
          if( l_miniEC != 0 )
          {
              auto l_hdatEC = l_cpu_target->getAttr<ATTR_HDAT_EC>();
              auto l_EC = l_cpu_target->getAttr<ATTR_EC>();
              auto l_newHdatEC = l_EC + l_miniEC;
              TRACFCOMP(g_trac_isteps_trace,
                        "MINI_EC=%d, HDAT_EC changing from %d->%d",
                        l_miniEC, l_hdatEC, l_newHdatEC);
              l_cpu_target->setAttr<ATTR_HDAT_EC>(l_newHdatEC);
          }
      }

    }  // end of going through all processors

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_check_secondary_sbe_seeprom_complete");
    return l_stepError.getErrorHandle();
}

};
