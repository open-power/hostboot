/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_setup_sbe.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
 *  @file call_host_setup_sbe.C
 *
 *  Support file for IStep: slave_sbe
 *   Slave SBE
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <i2c/i2cif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

#include <errl/errlmanager.H>

#include <isteps/hwpisteperror.H>

#include <errl/errludtarget.H>

#include <p9_set_fsi_gp_shadow.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_08
{

//******************************************************************************
// call_host_setup_sbe()
//******************************************************************************
void* call_host_setup_sbe(void *io_pArgs)
{
    errlHndl_t l_errl = NULL;
    IStepError  l_stepError;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_setup_sbe entry" );

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    //
    //  identify master processor target
    //
    TARGETING::Target* l_pMasterProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    for (const auto & l_procChip: l_cpuTargetList)
    {
        // call only on non-master processor chips
        if (l_procChip != l_pMasterProcTarget)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (l_procChip);

            //call p9_set_fsi_gp_shadow on non-master processors
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running p9_set_fsi_gp_shadow HWP on processor target %.8X",
                    TARGETING::get_huid(l_procChip) );

            FAPI_INVOKE_HWP(l_errl,p9_set_fsi_gp_shadow, l_fapi2_proc_target);
            if(l_errl)
            {
                l_stepError.addErrorDetails(l_errl);
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         "ERROR : call p9_set_fsi_gp_shadow, PLID=0x%x",
                         l_errl->plid() );
                errlCommit(l_errl, HWPF_COMP_ID);
            }

            // TODO-RTC:152203 BEGIN
            // Configure slave sbe to be in slave SBE, continuous IPL mode
            // All this code gets deleted once host_slave_sbe_config.C is in
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "WORKAROUND:RTC:152203 - Setup slave sbe scratch "
                      "registers for proc 0x%.8X",
                      TARGETING::get_huid(l_procChip));

            // Bits 7-15 are address portion
            const uint32_t CFAM_ADDRESS_MASK = 0x1FF;

            // Bits 0-6 are engine offset
            const uint32_t CFAM_ENGINE_OFFSET = 0xFE00;


            uint64_t l_addr = 0x283A;
            l_addr = ((l_addr & CFAM_ADDRESS_MASK) << 2) |
              (l_addr & CFAM_ENGINE_OFFSET);
            uint32_t l_data = 0x10000000;
            size_t l_size = sizeof(uint32_t);
            l_errl = deviceWrite(l_procChip,
                                &l_data,
                                l_size,
                                DEVICE_FSI_ADDRESS(l_addr));
            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"WORKAROUND:RTC:152203 - FAIL to setup "
                          "slave sbe scratch  registers for proc 0x%.8X "
                          "scratch 0x3A",
                          TARGETING::get_huid(l_procChip));
                delete l_errl;
                l_errl = NULL;
            }

            l_addr = 0x283D;
            l_addr = ((l_addr & CFAM_ADDRESS_MASK) << 2) |
              (l_addr & CFAM_ENGINE_OFFSET);
            l_data = 0x00000080;
            l_errl = deviceWrite(l_procChip,
                                 &l_data,
                                 l_size,
                                 DEVICE_FSI_ADDRESS(l_addr));
            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"WORKAROUND:RTC:152203 - FAIL to setup "
                          "slave sbe scratch registers for proc 0x%.8X "
                          "scratch 0x3D",
                          TARGETING::get_huid(l_procChip));
                delete l_errl;
                l_errl = NULL;
            }
            l_addr = 0x283F;
            l_addr = ((l_addr & CFAM_ADDRESS_MASK) << 2) |
              (l_addr & CFAM_ENGINE_OFFSET);
            l_data = 0x24000000;
            l_errl = deviceWrite(l_procChip,
                                 &l_data,
                                 l_size,
                                 DEVICE_FSI_ADDRESS(l_addr));
            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          ERR_MRK"WORKAROUND:RTC:152203 - FAIL to setup "
                          "slave sbe scratch "
                          "registers for proc 0x%.8X scratch 0x3F",
                          TARGETING::get_huid(l_procChip));
                delete l_errl;
                l_errl = NULL;
            }
            // TODO-RTC:152203 END
        }

    } // end of cycling through all processor chips

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_setup_sbe exit" );
    return l_stepError.getErrorHandle();
}
};
