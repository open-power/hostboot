/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep15/proc_set_pba_homer_bar.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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


//From Hostboot Directory
////System
  #include    <limits.h>
  #include    <sys/misc.h>

////Error handling and traces
  #include    <errl/errluserdetails.H>
  #include    <errl/errlmanager.H>
  #include    <errl/errlentry.H>
  #include    <errl/errludtarget.H>
  #include    <isteps/hwpisteperror.H>
  #include    <initservice/isteps_trace.H>

////Targeting support
  #include    <targeting/common/utilFilter.H>
  #include    <fapi2/plat_hwp_invoker.H>
  #include    <fapi2/target.H>

//From Import Directory (EKB Repository)
#include    <return_code.H>
#include    <p9_pm_set_homer_bar.H>

#include    <secureboot/smf_utils.H>
#include    <secureboot/smf.H>
#include    <isteps/mem_utils.H>
#include    <util/align.H>


//Namespaces
using namespace ERRORLOG;
using namespace TARGETING;
using namespace fapi2;
using namespace ISTEP;

namespace ISTEP_15
{
enum
{
    HOMER_SIZE_IN_MB    =4,
};

void* proc_set_pba_homer_bar (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_set_pba_homer_bar entry" );
    ISTEP_ERROR::IStepError l_StepError;
    errlHndl_t l_errl = nullptr;
    TARGETING::TargetHandleList l_procChips;
    uint64_t l_smfBase = 0x0;
    uint64_t l_unsecureHomerAddr = get_top_mem_addr();


    //Determine top-level system target
    TARGETING::Target* l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    assert(l_sys != nullptr, "Top level target was nullptr!");

    //Because the way P9N/P9C are init'ed for backwards HB / SBE
    //compatibility (SMF never enabled -- thus unsecure homer to
    //secure homer sc2 (system call to Ultravisor) doesn't work) during istep 15
    //need to "trick" hostboot into placing HOMER into normal memory @
    //HRMOR.  When HB goes through istep 16 it will enter UV
    //mode if SMF is enabled, and then when PM complex is restarted
    //in istep 21, HOMER is moved to right spot
    if(SECUREBOOT::SMF::isSmfEnabled())
    {
        l_smfBase = get_top_homer_mem_addr();
        assert(l_smfBase != 0,
               "proc_set_pba_homer_bar: Top of SMF memory was 0!");
        if(is_sapphire_load())
        {
            l_smfBase -= VMM_ALL_HOMER_OCC_MEMORY_SIZE;
            // Unsecure HOMER address is used in istep21 to place the
            // unsecure part of the HOMER image outside of SMF memory.
            // Unsecure HOMER goes to the top of unsecure
            // memory (2MB aligned); we need to subtract the size of the
            // unsecure HOMER and align the resulting address to arrive
            // at the correct location.
            l_unsecureHomerAddr = ALIGN_DOWN_X(l_unsecureHomerAddr -
                                               MAX_UNSECURE_HOMER_SIZE,
                                               2 * MEGABYTE);
        }
        assert(l_unsecureHomerAddr != 0,
               "proc_set_pba_homer_bar: Unsecure HOMER addr was 0!");

        //Since we have the HOMER location defined, set the
        // OCC common attribute to be used later by pm code
        l_sys->setAttr<TARGETING::ATTR_OCC_COMMON_AREA_PHYS_ADDR>
            (l_smfBase + VMM_HOMER_REGION_SIZE);
    }

    //Use targeting code to get a list of all processors
    getAllChips( l_procChips, TARGETING::TYPE_PROC   );



    //Loop through all of the procs and call the HWP on each one
    for (const auto & l_procChip: l_procChips)
    {

        //Convert the TARGETING::Target into a fapi2::Target by passing
        //the const_casted l_procChip into the fapi::Target constructor
        const fapi2::Target<TARGET_TYPE_PROC_CHIP>
            l_fapiCpuTarget((l_procChip));

        const uint64_t homerAddr =
            l_procChip->getAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>();

        //call p9_pm_set_homer_bar.C HWP
        FAPI_INVOKE_HWP( l_errl,
                        p9_pm_set_homer_bar,
                        l_fapiCpuTarget,
                        homerAddr,
                        HOMER_SIZE_IN_MB);

        if(l_errl)
        {
            l_StepError.addErrorDetails( l_errl );
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        if(SECUREBOOT::SMF::isSmfEnabled())
        {
            //Set correct SMF value used later in istep 21
            //  calculate size and location of the HCODE output buffer
            uint32_t l_procNum =
                l_procChip->getAttr<TARGETING::ATTR_POSITION>();
            uint64_t l_procOffsetAddr = l_procNum * VMM_HOMER_INSTANCE_SIZE;

            l_procChip->setAttr<TARGETING::ATTR_HOMER_PHYS_ADDR>
              (l_smfBase + l_procOffsetAddr);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Update %.8X HOMER from 0x%.16llX to 0x%.16llX for SMF",
                      TARGETING::get_huid(l_procChip), homerAddr,
                      (l_smfBase + l_procOffsetAddr));

            l_procChip->setAttr<TARGETING::ATTR_UNSECURE_HOMER_ADDRESS>
              (l_unsecureHomerAddr);
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "proc_set_pba_homer_bar: unsecure HOMER addr = 0x%.16llX",
                      l_unsecureHomerAddr);
        }

    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_set_pba_homer_bar exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
