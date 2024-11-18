/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_attr_update.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
   @file call_proc_attr_update.C
 *
 *  Support file for IStep: proc_attr_update
 *   Proc ATTR Update
 *
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
#include <p10_attr_update.H>

namespace   ISTEP_08
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//*****************************************************************************
// wrapper function to call proc_attr_update
//*****************************************************************************
void * call_proc_attr_update( void * io_pArgs )
{
    IStepError l_stepError;
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_attr_update");

    //
    //  get a list of all the procs in the system
    //
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    //get the boot interposer rev
    TARGETING::Target * boot_processor =   NULL;
    TARGETING::targetService().masterProcChipTargetHandle( boot_processor );
    TARGETING::ATTR_INTERPOSER_REV_type boot_interposer_rev = boot_processor->getAttr<ATTR_INTERPOSER_REV>();

    // Loop through all processors including master
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapi2_proc_target(
                  l_cpu_target);



        TRACFCOMP(g_trac_isteps_trace,
                  "Running p10_attr_update HWP on processor target %.8X",
                  get_huid(l_cpu_target));

        FAPI_INVOKE_HWP(l_err, p10_attr_update, l_fapi2_proc_target);
        if(l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR p10_attr_update target %.8X"
                      TRACE_ERR_FMT,
                      get_huid(l_cpu_target),
                      TRACE_ERR_ARGS(l_err));
            captureError(l_err, l_stepError, HWPF_COMP_ID, l_cpu_target);
        }

        TARGETING::ATTR_INTERPOSER_REV_type proc_interposer_rev = l_cpu_target->getAttr<ATTR_INTERPOSER_REV>();
        if (boot_interposer_rev != proc_interposer_rev)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR interposer mismatch in this target %.8X. The boot interposer was %.8X and this target's interposer was %.8X",
                      get_huid(l_cpu_target), boot_interposer_rev, proc_interposer_rev);
            /*@ errorlog tag
            * @moduleid        MOD_VOLTAGE_CONFIG
            * @reasoncode      RC_SCRATCH_REG_ATTR_MISMATCH
            * @userdata1       boot processor interposer value
            * @userdata2       current processor interposer value
            * @devdesc         Message from FSP. An invalid message queue ID
            *                  or mesage type was sent to the FSP.
            * @custdesc        An internal firmware error occurred
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                   MOD_VOLTAGE_CONFIG,
                                   RC_SCRATCH_REG_ATTR_MISMATCH,
                                   boot_interposer_rev,
                                   proc_interposer_rev,
                                   ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            l_stepError.addErrorDetails(l_err);

            l_err->addHwCallout( l_cpu_target,
            HWAS::SRCI_PRIORITY_HIGH,
            HWAS::DELAYED_DECONFIG,
            HWAS::GARD_NULL );

            l_err->addHwCallout( boot_processor,
            HWAS::SRCI_PRIORITY_LOW,
            HWAS::NO_DECONFIG,
            HWAS::GARD_NULL );

            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
    } // end of going through all processors

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_attr_update");
    return l_stepError.getErrorHandle();
}

};
