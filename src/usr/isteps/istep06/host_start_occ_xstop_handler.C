/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_start_occ_xstop_handler.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <kernel/vmmmgr.H>
#include <sys/mm.h>
#include <pm/pm_common.H>
#include <targeting/common/commontargeting.H>
#include <isteps/pm/occCheckstop.H>
#include <util/misc.H>
#include <util/utilsemipersist.H>
#ifdef CONFIG_BMC_IPMI
#include <ipmi/ipmisensor.H>
#endif


namespace ISTEP_06
{
void* host_start_occ_xstop_handler( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_start_occ_xstop_handler entry" );

    do
    {
//         if ( Util::isSimicsRunning() ) break; //Skip if running in Simics

        TARGETING::Target * l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( l_sys );
        assert(l_sys != nullptr);

#ifndef CONFIG_HANG_ON_MFG_SRC_TERM
        //When in MNFG_FLAG_SRC_TERM mode enable reboots to allow HB
        //to analyze now that the OCC is up and alive
        auto l_mnfgFlags =
          l_sys->getAttr<TARGETING::ATTR_MNFG_FLAGS>();

        // Check to see if SRC_TERM bit is set in MNFG flags
        if ((l_mnfgFlags & TARGETING::MNFG_FLAG_SRC_TERM) &&
            !(l_mnfgFlags & TARGETING::MNFG_FLAG_IMMEDIATE_HALT))
        {
            errlHndl_t l_err = nullptr;

            //If HB_VOLATILE MFG_TERM_REBOOT_ENABLE flag is set at this point
            //Create errorlog to terminate the boot.
            Util::semiPersistData_t l_semiData;
            Util::readSemiPersistData(l_semiData);
            if (l_semiData.mfg_term_reboot == Util::MFG_TERM_REBOOT_ENABLE)
            {
                /*@
                 * @errortype
                 * @moduleid    ISTEP::MOD_OCC_XSTOP_HANDLER
                 * @reasoncode  ISTEP::RC_PREVENT_REBOOT_IN_MFG_TERM_MODE
                 * @devdesc     System rebooted without xstop in MFG TERM mode.
                 * @custdesc    A problem occurred during the IPL of the system.
                 */
                l_err = new ERRORLOG::ErrlEntry
                  (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                   ISTEP::MOD_OCC_XSTOP_HANDLER,
                   ISTEP::RC_PREVENT_REBOOT_IN_MFG_TERM_MODE,
                   0,
                   0,
                   true /*HB SW error*/ );
                l_stepError.addErrorDetails(l_err);
                ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
                break;
            }

            //Put a mark in HB VOLATILE
            Util::semiPersistData_t l_newSemiData;  //inits to 0s
            Util::readSemiPersistData(l_newSemiData);
            l_newSemiData.mfg_term_reboot = Util::MFG_TERM_REBOOT_ENABLE;
            Util::writeSemiPersistData(l_newSemiData);

            //Enable reboots so FIRDATA will be analyzed on XSTOP
            SENSOR::RebootControlSensor l_rbotCtl;
            l_err = l_rbotCtl.setRebootControl(
                SENSOR::RebootControlSensor::autoRebootSetting::ENABLE_REBOOTS);

            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "Failed to enable BMC auto reboots....");
                l_stepError.addErrorDetails(l_err);
                ERRORLOG::errlCommit(l_err, HWPF_COMP_ID);
                break;
            }
        }
#endif


#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
        errlHndl_t l_errl = NULL;

        TARGETING::Target* masterproc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(masterproc);

        void* l_homerVirtAddrBase = reinterpret_cast<void*>
          (VmmManager::INITIAL_MEM_SIZE);
        uint64_t l_homerPhysAddrBase = mm_virt_to_phys(l_homerVirtAddrBase);
        uint64_t l_commonPhysAddr = l_homerPhysAddrBase + VMM_HOMER_REGION_SIZE;

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "host_start_occ_xstop_handler:"
                  " l_homerPhysAddrBase=0x%x, l_commonPhysAddr=0x%x",
                  l_homerPhysAddrBase, l_commonPhysAddr);

        l_errl = HBPM::loadPMComplex(masterproc,
                                     l_homerPhysAddrBase,
                                     l_commonPhysAddr,
                                     HBPM::PM_LOAD,
                                     true);
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                                        "loadPMComplex failed");
            l_stepError.addErrorDetails(l_errl);
            ERRORLOG::errlCommit(l_errl, HWPF_COMP_ID);
            break;
        }

        l_errl = HBOCC::startOCCFromSRAM(masterproc);
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                                     "startOCCFromSRAM failed");
            l_stepError.addErrorDetails(l_errl);
            ERRORLOG::errlCommit(l_errl, HWPF_COMP_ID);
            break;
        }
#endif

    }while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_start_occ_xstop_handler exit" );

    return l_stepError.getErrorHandle();
}

};
