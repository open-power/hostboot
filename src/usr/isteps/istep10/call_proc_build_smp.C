/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_build_smp.C $                */
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
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <fsi/fsiif.H>
#include <arch/magic.H>


//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/target.H>
#include <pbusLinkSvc.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <intr/interrupt.H>

#include <spi/spi.H>

//@TODO RTC:150562 - Remove when BAR setting handled by INTRRP
#include <devicefw/userif.H>
#include <sys/misc.h>
#include <sbeio/sbeioif.H>
#include <usr/vmmconst.h>
#include <p10_build_smp.H>

#include <secureboot/trustedbootif.H>
#include <secureboot/service.H>
#include <p10_scom_proc.H>
#include <sys/time.h>
#include <istepHelperFuncs.H>
#include <sbeio/sbe_retry_handler.H>
#include <sbeio/sbe_utils.H>

#include "call_proc_build_smp.H"

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;
using   namespace   SBEIO;

namespace ISTEP_10
{

const uint64_t MAX_SBE_WAIT_NS = 30000*NS_PER_MSEC; //=30s

/**
 * @brief Force a processor delayed_deconfig callout in the error log
 * @param[in]     i_proc  processor target to callout
 * @param[in/out] io_err  error log to check/update with callout
 */
void forceProcDelayDeconfigCallout(TargetHandle_t const i_proc,
                                   errlHndl_t& io_err)
{
    const auto search_results = io_err->queryCallouts(i_proc);
    using compare_enum = ERRORLOG::ErrlEntry::callout_search_criteria;
    // Check if we found any callouts for this Processor
    if((search_results & compare_enum::TARGET_MATCH) == compare_enum::TARGET_MATCH)
    {
        // If we found a callout for this Processor w/o a DECONFIG,
        // edit the callout to include a deconfig
        if((search_results & compare_enum::DECONFIG_FOUND) != compare_enum::DECONFIG_FOUND)
        {
            io_err->setDeconfigState(i_proc, HWAS::DELAYED_DECONFIG);
        }
    }
    else
    {
        // Add HW callout for Processor with low priority
        io_err->addHwCallout(i_proc,
                            HWAS::SRCI_PRIORITY_LOW,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL);
    }
}

/**
 * @brief Prevent PRD from handling SBE halted
 *        - Mask TP_LOCAL_FIR[33] - SBE - PPE in halted state
 *
 * @param[in] i_secondaryProcs - secondary/alternate processor targets
 * @param[in/out] io_StepError - istep failure errors will be added to this
 */
void preventPRDHaltHandling(const TargetHandleList& i_secondaryProcs,
                            IStepError & io_StepError)
{
    errlHndl_t errl = nullptr;

    for (auto proc : i_secondaryProcs)
    {
        // Write 0x0000000040000000 (bit 33) to 0x01040105 (mask atomic OR) to mask the attention
        uint64_t local_fir_mask = TP_LOCAL_FIR_SBE_PPE_HALTED_STATE;
        size_t local_fir_mask_size = sizeof(local_fir_mask);
        errl = deviceWrite(proc,
                          &local_fir_mask,
                          local_fir_mask_size,
                          DEVICE_SCOM_ADDRESS(scomt::proc::TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR));

        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"Failed to mask TP_LOCAL_FIR[33] on 0x%8X processor",
                      " tried to write 0x%016llX to SCOM address 0x%.8X",
                      get_huid(proc), local_fir_mask,
                      scomt::proc::TP_TPCHIP_TPC_EPS_FIR_LOCAL_MASK_WO_OR);
            forceProcDelayDeconfigCallout(proc, errl);
            // Capture error and continue to the next chip
            captureError(errl, io_StepError, ISTEP_COMP_ID, proc);
        }
    }
}

/**
 * @brief Poison the primary TPM
 *        Common function so only actually poisons once
 */
void poisonPrimaryTpm()
{
#ifdef CONFIG_TPMDD
    errlHndl_t l_errl = nullptr;

    // TPM to poison
    Target* l_primaryTpm = nullptr;
    TRUSTEDBOOT::getPrimaryTpm(l_primaryTpm);

    // only poison the primary TPM once
    if ((l_primaryTpm != nullptr) &&
        (!l_primaryTpm->getAttr<TARGETING::ATTR_TPM_POISONED>()))
    {
        // make sure TPM is functional
        auto l_tpmHwasState = l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();
        if (l_tpmHwasState.functional)
        {
            // this will poison and flushTpmQueue
            l_errl = TRUSTEDBOOT::poisonTpm(l_primaryTpm);
            if (l_errl)
            {
                // mark the TPM as non-functional as poisoning should always work
                // note: this will also commit the error log and then set it to nullptr
                TRUSTEDBOOT::tpmMarkFailed(l_primaryTpm, l_errl);
            }
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "poisonPrimaryTpm(): skipping poisoning of NON-FUNCTIONAL TPM 0x%.8X",
                TARGETING::get_huid(l_primaryTpm));
        }
    }
#endif
}

/**
 * @brief Wait until SBE Attention is reported in status register
 * @param[in] i_secProc - secondary/alternate processor target
 * @param[in] i_max_wait_time_nsec - maximum time to wait for attn in nsecs
 * @return nullptr if SBE attn found, else error
 */
errlHndl_t waitForSBEAttn( Target * i_secProc,
                           const uint64_t i_max_wait_time_nsecs )
{
    errlHndl_t l_errl = nullptr;
    uint32_t l_status_data = 0;
    size_t l_32bitSize = sizeof(l_status_data);
    uint64_t l_elapsed_time_ns = 0;

    do
    {
        l_status_data = 0;
        l_32bitSize = sizeof(l_status_data);

        // Read TP.TPVSB.FSI.W.FSI2PIB.STATUS register (0x00001007ull)
        l_errl = deviceOp(DeviceFW::READ,
                          i_secProc,
                          &l_status_data,
                          l_32bitSize,
                          DEVICE_FSI_ADDRESS(scomt::proc::TP_TPVSB_FSI_W_FSI2PIB_STATUS_FSI_BYTE));

        // only check SBE bit on successful read
        if (!l_errl)
        {
            // check SELFBOOT_ENGINE_ATTENTION bit (30)
            uint32_t checkBit = 0x80000000 >> scomt::proc::TP_TPVSB_FSI_W_FSI2PIB_STATUS_SELFBOOT_ENGINE_ATTENTION;
            if (l_status_data & checkBit)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "waitForSBEAttn: 0x%.8X proc SBE is at SBE attn",
                   get_huid(i_secProc) );
                break;
            }
            else
            {
                if (l_elapsed_time_ns > i_max_wait_time_nsecs)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "waitForSBEAttn: Elapsed 0x%16llX nsecs - 0x%.8X proc SBE"
                       " is NOT at SBE attn (0x%08X & SBE ATTN BIT 0x%08X)",
                       l_elapsed_time_ns, get_huid(i_secProc), l_status_data,
                       checkBit );

                    /*@
                     * @errortype
                     * @moduleid   MOD_WAIT_FOR_SBE_ATTN
                     * @reasoncode RC_WAIT_ATTN_TIMEOUT
                     * @userdata1[0:31]  HUID of proc without SBE attn
                     * @userdata1[32:63] Last response status (bit 30 = SBE Attn bit)
                     * @userdata2  Max wait time in ns
                     * @devdesc    Failed to halt a secondary SBE
                     * @custdesc   Processor Error
                     */
                    l_errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                           MOD_WAIT_FOR_SBE_ATTN,
                                           RC_WAIT_ATTN_TIMEOUT,
                                           TWO_UINT32_TO_UINT64(
                                           get_huid(i_secProc),
                                           l_status_data),
                                           i_max_wait_time_nsecs);
                    // SBE says it supports halt, so this timeout should not happen
                    l_errl->addHwCallout( i_secProc,
                                          HWAS::SRCI_PRIORITY_HIGH,
                                          HWAS::DELAYED_DECONFIG,
                                          HWAS::GARD_NULL );
                    break;
                }

                // try later
                nanosleep( 0, 1000000 ); //sleep for 1ms
                l_elapsed_time_ns += 1000000;
            }
        } // errl check

    } while (!l_errl);
    return l_errl;
} // end waitForSBEAttn()


/**
 * @brief Check if SAB (Secure Access Bit) is set in PERV_CBS_CS register via FSI
 * @param[in]  i_procTarget - secondary processor target
 * @param[out] o_set - setting of SAB
 * @return nullptr | FSI read error
 */
errlHndl_t isSecureAccessSet(const TargetHandle_t i_procTarget, bool & o_set)
{
    o_set = false; // default to not set
    errlHndl_t l_err = nullptr;
    // FSI_BYTE Register PERV_CBS_CS
    uint64_t l_fsiAddr = static_cast<uint64_t>(SECUREBOOT::ProcCbsControl::StatusRegisterFsi);
    const uint32_t CBS_CS_SECURE_ACCESS_BIT = 0x08000000; // Bit 4
    uint32_t l_data = 0;
    size_t l_size = sizeof(l_data);

    l_err = deviceRead( i_procTarget, &l_data, l_size,
                        DEVICE_FSI_ADDRESS(l_fsiAddr) );
    if (l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
           ERR_MRK"isSecureAccessSet(0x%.8X) read failed, default is not secure",
           get_huid(i_procTarget) );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
           "isSecureAccessSet(0x%.8X) address 0x%.8X read 0x%08X",
           get_huid(i_procTarget),
           l_fsiAddr,
           l_data );
        if (l_data & CBS_CS_SECURE_ACCESS_BIT)
        {
            o_set = true;
        }
    }
    return l_err;
}


/**
 * @brief Read SAB value via FSI from A|S SBE and validate it matches
 *        the primary SBE value.
 *        If mismatch is detected:
 *        - poison primary TPM
 *        - set ATTR_SBE_COMPROMISED_EID to mismatch error ID
 * @param[in] i_secondaryProcs - secondary/alternate processor targets
 * @param[in/out] io_StepError - istep failure errors will be added to this
 */
void checkForSecurityAccessMismatch(const TargetHandleList& i_secondaryProcs,
                                    IStepError & io_StepError)
{
    errlHndl_t l_errl = nullptr;

    bool poisonTpm = false;

    // SAB setting
    bool l_primarySecureAccessSet = false;
    bool l_secondarySecureAccessSet = false;

    // check primary setting first
    l_primarySecureAccessSet = SECUREBOOT::enabled();

    for ( auto curproc : i_secondaryProcs)
    {
        // compare Secure Access settings
        l_errl = isSecureAccessSet(curproc, l_secondarySecureAccessSet);
        if (l_errl)
        {
            // unable to read SAB from hw
            forceProcDelayDeconfigCallout(curproc, l_errl);
            captureError(l_errl, io_StepError, ISTEP_COMP_ID, curproc);
            continue;  // go to next secondary processor
        }

        if (l_secondarySecureAccessSet != l_primarySecureAccessSet)
        {
            // need to notify security can't be trusted
            poisonTpm = true;

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                "SAB for 0x%.8X processor (%d) mismatches master setting (%d)",
                get_huid(curproc), l_secondarySecureAccessSet, l_primarySecureAccessSet);

            /*@
             * @errortype
             * @moduleid   MOD_CHECK_FOR_SECURITY_ACCESS_MISMATCH
             * @reasoncode RC_SAB_MISMATCH_DETECTED
             * @userdata1  Huid of secondary processor
             * @userdata2[0:31]   Primary processor SAB
             * @userdata2[32:63]  Secondary processor SAB
             * @devdesc    Security Access mismatch
             * @custdesc   Platform security problem detected
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             MOD_CHECK_FOR_SECURITY_ACCESS_MISMATCH,
                                             RC_SAB_MISMATCH_DETECTED,
                                             get_huid(curproc),
                                             TWO_UINT32_TO_UINT64(
                                             l_primarySecureAccessSet,
                                             l_secondarySecureAccessSet
                                             ));
            l_errl->addHwCallout( curproc,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_NULL );
            if (!SECUREBOOT::enabled())
            {
              TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "checkForSecurityAccessMismatch: security is off, "
                  "so just log the SAB Mismatch (EID: 0x%08X) as informational",
                  l_errl->eid() );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }

            // only mark compromised if not already marked
            if (!curproc->getAttr<ATTR_SBE_COMPROMISED_EID>())
            {
                // update attribute with EID of poisoning reason
                curproc->setAttr<ATTR_SBE_COMPROMISED_EID>(l_errl->eid());
            }

            SECUREBOOT::addSecurityRegistersToErrlog(l_errl);
            l_errl->collectTrace(ISTEP_COMP_NAME);

            // IPL should be able to continue, so just log the mismatch error
            errlCommit(l_errl, ISTEP_COMP_ID);
        }
    }

    if (poisonTpm)
    {
        poisonPrimaryTpm();
    }
}



// Main function
void* call_proc_build_smp (void *io_pArgs)
{
    IStepError l_StepError;

    // General flow of this istep
    // a) phase 1 build SMP
    // b) halt all non-boot chip SBEs
    // c) check for Secure Access mismatch via FSI to non-boot chips
    // d) call HWP to specifically enable SMP fabric (pb hotplug)

    // SBE's will have measurements taken / extended to TPM / restarted in 10.3

    do
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "call_proc_build_smp entry" );

        errlHndl_t l_errl = nullptr;
        TargetHandleList l_cpuTargetList,
                         l_secondaryProcsList;  // all secondary/non-boot procs

        getAllChips(l_cpuTargetList, TYPE_PROC);

        //  Identify the boot processor
        Target * l_bootProc =   nullptr;
        Target * l_bootNode =   nullptr;
        bool l_onlyFunctional = true; // Make sure bootproc is functional
        l_errl = targetService().queryMasterProcChipTargetHandle(
                                                 l_bootProc,
                                                 l_bootNode,
                                                 l_onlyFunctional);
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call_proc_build_smp: "
                       "queryMasterProcChipTargetHandle() "
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_errl) );
            captureError(l_errl, l_StepError, ISTEP_COMP_ID);
            break;
        }

        // FAPI2 list for HWP
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_procList;

        // Loop through all proc chips and convert them to FAPI targets
        for (const auto & curproc: l_cpuTargetList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                    l_fapi2_proc_target (curproc);
            l_procList.push_back(l_fapi2_proc_target);

            // build list of non-boot processors too
            if (curproc != l_bootProc)
            {
                // include all secondary processors
                l_secondaryProcsList.push_back(curproc);

            }
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                            l_fapi2_boot_proc (l_bootProc);


        // a) phase 1 build SMP
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call p10_build_smp(SMP_ACTIVATE_PHASE1)" );
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_boot_proc,
                         SMP_ACTIVATE_PHASE1 );

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p10_build_smp(SMP_ACTIVATE_PHASE1) "
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_errl) );
            //@FIXME-RTC:254475-Remove once this works everywhere
            if( MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__IGNORESMPFAIL) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "WORKAROUND> Ignoring error for now - p10_build_smp" );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit( l_errl, HWPF_COMP_ID );
            }
            else
            {
                captureError(l_errl, l_StepError, HWPF_COMP_ID);
                break;
            }
        }

        // Mask appropriate bits to prevent PRDF handling of SBE halt
        preventPRDHaltHandling(l_secondaryProcsList, l_StepError);
        if (!l_StepError.isNull())
        {
            // NOTE: no need to try to re-enable PRD halt handling on
            // the non-failed processors.  It will happen automatically
            // during the reconfig loop after bad processors are deconfigured
            break;
        }

        // b) halt all non-boot chip SBEs
        for (auto l_proc : l_secondaryProcsList)
        {
            // send halt request
            l_errl = SBEIO::sendSecondarySbeHaltRequest(l_proc);
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR : call_proc_build_smp: sendSecondarySbeHaltRequest returned error" );
                forceProcDelayDeconfigCallout(l_proc, l_errl);
                captureError(l_errl, l_StepError, ISTEP_COMP_ID, l_proc);
                continue;  // no sense waiting for SBE attn
            }

            // monitor for halt completion
            l_errl = waitForSBEAttn(l_proc, MAX_SBE_WAIT_NS);
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR : call_proc_build_smp: waitForSBEAttn returned error" );
                forceProcDelayDeconfigCallout(l_proc, l_errl);
                captureError(l_errl, l_StepError, ISTEP_COMP_ID, l_proc);
            }

            // reset the started attribute
            l_proc->setAttr<ATTR_SBE_IS_STARTED>(0);
        }
        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        // c) check for Secure Access mismatch via FSI to non-boot chips
        checkForSecurityAccessMismatch(l_secondaryProcsList, l_StepError);
        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        // d) Call HWP to specifically enable SMP fabric (pb hotplug)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call p10_build_smp(SMP_ACTIVATE_SWITCH)" );
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_boot_proc,
                         SMP_ACTIVATE_SWITCH );
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR : call p10_build_smp(SMP_ACTIVATE_SWITCH) "
                TRACE_ERR_FMT,
                TRACE_ERR_ARGS(l_errl) );
            captureError(l_errl, l_StepError, HWPF_COMP_ID);
            break;
        }


        // At the point where we can now change the proc chips to use
        // XSCOM rather than SBESCOM which is the default.
        for (auto l_proc_target : l_cpuTargetList)
        {
            // If the proc chip supports xscom..
            if (l_proc_target->getAttr<ATTR_PRIMARY_CAPABILITIES>()
                .supportsXscom)
            {
                ScomSwitches l_switches =
                  l_proc_target->getAttr<ATTR_SCOM_SWITCHES>();

                // If Xscom is not already enabled.
                if ((l_switches.useXscom != 1) || (l_switches.useSbeScom != 0))
                {
                    l_switches.useSbeScom = 0;
                    l_switches.useXscom = 1;

                    // Turn off SBE scom and turn on Xscom.
                    l_proc_target->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
                }
            }
        }

        // Call SMP_ACTIVATE_POST
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Call p10_build_smp(SMP_ACTIVATE_POST)" );
        FAPI_INVOKE_HWP( l_errl, p10_build_smp,
                         l_procList,
                         l_fapi2_boot_proc,
                         SMP_ACTIVATE_POST );
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p10_build_smp(SMP_ACTIVATE_POST) "
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_errl) );
            captureError(l_errl, l_StepError, HWPF_COMP_ID);
            break;
        }

        for (auto l_proc_target : l_secondaryProcsList)
        {
            // Switch from FSI to PIB SPI access for secondary processors
            l_errl = SPI::spiSetAccessMode(l_proc_target, SPI::PIB_ACCESS);
            if(l_errl)
            {
                // Since this is a hard failure to detect later
                // (via SPI failures), error out here
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                  "call_proc_build_smp> Unable to switch SPI access to "
                  "PIB_ACCESS for 0x%.8X",
                  get_huid(l_proc_target) );
                captureError(l_errl, l_StepError, ISTEP_COMP_ID, l_proc_target);
                break;
            }

            //Enable PSIHB Interrupts for secondary proc -- moved from above
            l_errl = INTR::enablePsiIntr(l_proc_target);
            if(l_errl)
            {
                captureError(l_errl, l_StepError, HWPF_COMP_ID, l_proc_target);
                break;
            }
        }

        if (!l_StepError.isNull())
        {
            // break out on istep failure
            break;
        }

        // Set a flag so that the ATTN code will check ALL processors
        // the next time it gets called versus just the master proc.
        uint8_t    l_useAllProcs = 1;
        // Get a handle to the System target
        TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();
        l_systemTarget->setAttr<ATTR_ATTN_CHK_ALL_PROCS>(l_useAllProcs);

    } while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_proc_build_smp exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
