/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_exit_cache_contained.C $     */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/target.H>


//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>
#include    <p9_misc_scom_addresses.H>
#include    <p9_exit_cache_contained.H>

#include <sys/mm.h>
#include <arch/pirformat.H>
#include <isteps/hwpf_reasoncodes.H>
#include <devicefw/userif.H>
#include <config.h>
#include <util/misc.H>
#include <hwas/common/hwas.H>
#include <sys/misc.h>
#include <vmmconst.h>

#ifdef CONFIG_SECUREBOOT
#include <secureboot/service.H>
#include <scom/centaurScomCache.H>
#endif

#include <isteps/mem_utils.H>
#include <arch/ppc.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


//Simics only register to trigger exit of cache containment
#define EXIT_CACHE_CONTAINED_SCOM_ADDR 0x0000000005000003

namespace ISTEP_14
{
void* call_proc_exit_cache_contained (void *io_pArgs)
{

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained entry" );
    errlHndl_t  l_errl = nullptr;

#ifdef CONFIG_SECUREBOOT
    if(SECUREBOOT::enabled())
    {
        SECUREBOOT::CENTAUR_SECURITY::ScomCache& centaurCache =
            SECUREBOOT::CENTAUR_SECURITY::ScomCache::getInstance();

        l_errl = centaurCache.verify();
        if(l_errl)
        {
            l_stepError.addErrorDetails(l_errl);
            errlCommit(l_errl, HWPF_COMP_ID );
        }

        centaurCache.destroy();
    }
#endif

    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    //  extend the memory space from cache out to VMM_MEMORY_SIZE of mainstore

    //if mirrored then check that there is going to be memory at that location.
    //For sapphire with mirrored location flipped and at zero,
    //this also insures there is memory available to 'exit_cache' to.
    //Also set ATTR_PAYLOAD_BASE here.
    TARGETING::Target* l_sys = NULL;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL );

    //Check that minimum hardware requirement is meet.
    //If not, log error and do not proceed
    bool l_bootable;
    l_errl = HWAS::checkMinimumHardware(l_sys, &l_bootable);
    if (!l_bootable && !l_errl)
    {
        /*@
        *  @errortype      ERRL_SEV_UNRECOVERABLE
        *  @moduleid       ISTEP::MOD_PROC_EXIT_CACHE_CONTAINED
        *  @reasoncode     ISTEP::RC_MIN_HW_CHECK_FAILED
        *  @devdesc        call_proc_exit_cache_contained: did not
        *                  find minimum hardware to continue
        *  @custdesc       Host firmware did not find enough
        *                  hardware to continue the boot
        */
        l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            ISTEP::MOD_PROC_EXIT_CACHE_CONTAINED,
            ISTEP::RC_MIN_HW_CHECK_FAILED);
    }

    if (!l_errl)
    {
        bool l_valid {true};
        l_errl = HWAS::check_current_proc_mem_to_use_is_still_valid (l_valid);
        if (l_errl || !l_valid)
        {
            //We deconfigured a bunch of dimms and the answer
            //changed for which proc's memory to use. Give up TI
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR: check_current_proc_mem_to_use_is_still_valid"
                    " going to TI");

            if (!l_errl)
            {
                /*@
                *  @errortype      ERRL_SEV_UNRECOVERABLE
                *  @moduleid       ISTEP::MOD_PROC_EXIT_CACHE_CONTAINED
                *  @reasoncode     ISTEP::RC_NO_VALID_MEM_CONFIG
                *  @devdesc        call_proc_exit_cache_contained: did not
                *                  find valid memory configuration
                *  @custdesc       Host firmware did not find valid
                *                  hardware to continue the boot
                */
                l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        ISTEP::MOD_PROC_EXIT_CACHE_CONTAINED,
                        ISTEP::RC_NO_VALID_MEM_CONFIG);

                l_errl->addProcedureCallout(
                        HWAS::EPUB_PRC_SP_CODE,
                        HWAS::SRCI_PRIORITY_HIGH );

                l_errl->addProcedureCallout(
                        HWAS::EPUB_PRC_FIND_DECONFIGURED_PART,
                        HWAS::SRCI_PRIORITY_HIGH );
            }
        }
    }

    uint8_t l_mpipl = 0;
    TARGETING::TargetHandleList l_procList;
    if (!l_errl)
    {
        l_mpipl = l_sys->getAttr<ATTR_IS_MPIPL_HB>();
        getAllChips(l_procList, TYPE_PROC);
    }

    ATTR_PAYLOAD_BASE_type payloadBase = 0;

    if(!l_mpipl && !l_errl)
    {
        ATTR_PAYLOAD_IN_MIRROR_MEM_type l_mirrored = false;

        // In Sapphire mode disable mirroring for now - @todo-RTC:108314
        // and force payload to zero
        if(!is_sapphire_load())
        {
            payloadBase = l_sys->getAttr<ATTR_PAYLOAD_BASE>();
            l_mirrored = l_sys->getAttr<ATTR_PAYLOAD_IN_MIRROR_MEM>();
        }

        // In Simics mode disable mirroring for now - @todo-CQ:SW427497
        // need action file changes for P9 to enable MM
        // SW427497 addresses these changes
        // also force payload to zero
        // @todo-RTC:192854 to enable it back once the defect SW427497
        // is integrated.
        if(Util::isSimicsRunning())
        {
            l_mirrored = false;

            l_sys->setAttr<ATTR_PAYLOAD_IN_MIRROR_MEM>(0);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Disabling memory mirroring temporarily");
        }

        if(l_mirrored)
        {
            ATTR_MIRROR_BASE_ADDRESS_type l_mirrorBaseAddr = 0;
            if(!is_sapphire_load())
            {
                //Get all the proc chips
                TARGETING::TargetHandleList l_cpuTargetList;
                getAllChips(l_cpuTargetList, TYPE_PROC);

                //Iterate through the proc chips, finding the smallest valid
                // mirrored memory address
                uint64_t l_mirrorSmallestAddr = 0;
                for (const auto & l_cpu_target: l_cpuTargetList)
                {
                    //Get the acknowledged memory mirror sizes attribute
                    //  If this is 0, we should not consider this mirror region
                    uint64_t mirrorSizesAck[sizeof(fapi2::ATTR_PROC_MIRROR_SIZES_ACK_Type)/sizeof(uint64_t)];
                    bool rc = (l_cpu_target)->
                        tryGetAttr<TARGETING::ATTR_PROC_MIRROR_SIZES_ACK>(mirrorSizesAck);
                    if(false == rc)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  "Failed to get ATTR_PROC_MIRROR_SIZES_ACK");
                        assert(0);
                    }

                    //Get the acknowledged memory mirror bases attribute
                    uint64_t mirrorBasesAck[sizeof(fapi2::ATTR_PROC_MIRROR_BASES_ACK_Type)/sizeof(uint64_t)];
                    rc = (l_cpu_target)->
                       tryGetAttr<TARGETING::ATTR_PROC_MIRROR_BASES_ACK>(mirrorBasesAck);
                    if(false == rc)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                 "Failed to get ATTR_PROC_MIRROR_BASES_ACK");
                        assert(0);
                    }

                    assert ((sizeof(fapi2::ATTR_PROC_MIRROR_SIZES_ACK_Type) ==
                               sizeof(fapi2::ATTR_PROC_MIRROR_BASES_ACK_Type)),
                             "sizeof(ATTRPROC_MIRROR_SIZES_ACK) != sizeof(ATTR_PROC_MIRROR_BASES_ACK)");

                    //Loop through each mirror region looking for the lowest
                    // valid memory value
                    for (uint8_t i=0;
                         i < sizeof(fapi2::ATTR_PROC_MIRROR_BASES_ACK_Type)/sizeof(uint64_t);
                         i++)
                    {
                        if (mirrorSizesAck[i] == 0)
                        {
                            //Mirrored memory region has a size of 0, do not consider
                            continue;
                        }

                        //Save the smallest address for later use
                        if (l_mirrorSmallestAddr == 0)
                        {
                            l_mirrorSmallestAddr = mirrorBasesAck[i];
                        }
                        else if (mirrorBasesAck[i] < l_mirrorBaseAddr &&
                              mirrorBasesAck[i] != 0)
                        {
                            l_mirrorSmallestAddr = mirrorBasesAck[i];
                        }
                    }
                }
                //Set the mirrored addr to the lowest valid memory value found
                l_mirrorBaseAddr = l_mirrorSmallestAddr;
            }

            // Verify there is memory at the mirrored location
            bool mirroredMemExists = false;

            for (TargetHandleList::const_iterator proc = l_procList.begin();
                 proc != l_procList.end() && !mirroredMemExists;
                 ++proc)
            {
                uint64_t mirrorBase[sizeof(fapi2::ATTR_PROC_MIRROR_BASES_Type)/sizeof(uint64_t)];
                uint64_t mirrorSize[sizeof(fapi2::ATTR_PROC_MIRROR_SIZES_Type)/sizeof(uint64_t)];
                bool rc = (*proc)->
                    tryGetAttr<TARGETING::ATTR_PROC_MIRROR_BASES>(mirrorBase);
                if(false == rc)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Failed to get ATTR_PROC_MIRROR_BASES");
                    assert(0);
                }

                rc = (*proc)->
                    tryGetAttr<TARGETING::ATTR_PROC_MIRROR_SIZES>(mirrorSize);
                if(false == rc)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Failed to get ATTR_PROC_MIRROR_SIZES");
                    assert(0);
                }

                for(uint64_t i = 0;
                i < sizeof(fapi2::ATTR_PROC_MIRROR_BASES_Type) && !mirroredMemExists;
                ++i)
                {
                    if(mirrorSize[i] != 0 &&
                       l_mirrorBaseAddr >= mirrorBase[i] &&
                       l_mirrorBaseAddr < (mirrorBase[i] + mirrorSize[i]))
                    {
                        mirroredMemExists = true;
                    }
                }
            }

            if (mirroredMemExists)
            {
                // ATTR_PAYLOAD_BASE is in MB
                payloadBase += l_mirrorBaseAddr/MEGABYTE;
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                          "Request to load payload into mirrored memory,"
                          " but no memory exists at address 0x%016lx",
                          l_mirrorBaseAddr);

                /*@
                 *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                 *  @moduleid       ISTEP::MOD_EXIT_CACHE_CONTAINED
                 *  @reasoncode     ISTEP::RC_NO_MIRRORED_MEMORY
                 *  @userdata1      Mirrored Memory Address
                 *  @userdata2      0
                 *
                 *  @devdesc        Request given to load payload into mirrored
                 *                  memory, but no mirrored memory exists at
                 *                  that location.
                 */
                l_errl = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                     ISTEP::MOD_EXIT_CACHE_CONTAINED,
                     ISTEP::RC_NO_MIRRORED_MEMORY,
                     l_mirrorBaseAddr,
                     0,
                     true); // callout firmware
            }
        }
        // If we're not mirrored, payloadBase is the lowest mem_base.
        // Note that if we are mirrored, finding the correct mirror
        // base yields the proper payloadBase. This should also work
        // for sapphire as a single (working) node will return 0 for
        // bottom_mem_addr.
        else {
            payloadBase += get_bottom_mem_addr()/MEGABYTE;
        }
    }

    if(!l_errl)
    {
        if(!l_mpipl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Payload base address is 0x%016lx",
                      payloadBase * MEGABYTE);

            l_sys->setAttr<ATTR_PAYLOAD_BASE>(payloadBase);
        }

        // Make sure we actually have memory before we try to use it
        uint64_t l_bottom = get_bottom_mem_addr();
        uint64_t l_top = get_top_mem_addr();
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Memory range : %.llX-%.llX", l_bottom, l_top );
        if( (l_top == 0) || (l_top == l_bottom) )
        {
            /*@
             *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
             *  @moduleid       ISTEP::MOD_EXIT_CACHE_CONTAINED
             *  @reasoncode     ISTEP::RC_NO_FUNCTIONAL_MEMORY
             *  @userdata1      Bottom of memory
             *  @userdata2      Top of memory
             *
             *  @devdesc        There is no functional memory
             */
            l_errl = new ERRORLOG::ErrlEntry
              (
               ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
               ISTEP::MOD_EXIT_CACHE_CONTAINED,
               ISTEP::RC_NO_FUNCTIONAL_MEMORY,
               l_bottom,
               l_top);
            // We should never get here so there is some kind of bug
            l_errl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH );
            // Also should look at the deconfigured memory
            l_errl->addProcedureCallout( HWAS::EPUB_PRC_FIND_DECONFIGURED_PART,
                                         HWAS::SRCI_PRIORITY_MED );
        }
        else
        {
            for (const auto & l_procChip: l_procList)
            {
                const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                  l_fapi_cpu_target(l_procChip);
                // call p9_proc_exit_cache_contained.C HWP
                FAPI_INVOKE_HWP( l_errl,
                                 p9_exit_cache_contained,
                                 l_procChip);

                if(l_errl)
                {
                    ErrlUserDetailsTarget(l_procChip).addToLog(l_errl);
                    l_stepError.addErrorDetails( l_errl );
                    errlCommit( l_errl, HWPF_COMP_ID );
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_exit_cache_contained:: failed on proc with HUID : %d", TARGETING::get_huid(l_procChip)  );
                }
            }
        }

        // no errors so extend Virtual Memory Map
        if(!l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : call_proc_exit_cache_contained on all procs" );

            if(Util::isSimicsRunning())
            {
                TARGETING::ATTR_MODEL_type l_procModel = TARGETING::targetService().getProcessorModel();
                if (l_procModel == TARGETING::MODEL_AXONE)
                {
                    // notify simics exiting cache contained mode
                    MAGIC_INSTRUCTION(MAGIC_SIMICS_EXIT_CACHE_CONTAINED);
                }
                else
                {
                    // used for each processor with memory
                    size_t scom_size = sizeof(uint64_t);

                    //Value to indicate memory is valid
                    uint64_t l_memory_valid = 1;

                    //Predicate(s) to get functional dimm for each proc
                    PredicateHwas l_functional;
                    l_functional.functional(true);
                    TargetHandleList l_dimms;
                    PredicateCTM l_dimm(CLASS_LOGICAL_CARD, TYPE_DIMM);
                    PredicatePostfixExpr l_checkExprFunctional;
                    l_checkExprFunctional.push(&l_dimm).push(&l_functional).And();

                    // Loop through all procs to find ones with valid memory
                    for (const auto & l_procChip: l_procList)
                    {
                        // Get the functional DIMMs for this proc
                        targetService().getAssociated(l_dimms,
                                              l_procChip,
                                              TargetService::CHILD_BY_AFFINITY,
                                              TargetService::ALL,
                                              &l_checkExprFunctional);

                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                           "%d functional dimms behind proc: %.8X",
                           l_dimms.size(), get_huid(l_procChip) );

                        // Check if this proc has memory
                        if(l_dimms.size())
                        {
                            // exit cache contained mode
                            l_errl = deviceWrite( l_procChip,
                                            &l_memory_valid,  //Memory is valid
                                            scom_size,        //Size of Scom
                                            DEVICE_SCOM_ADDRESS(
                                              EXIT_CACHE_CONTAINED_SCOM_ADDR) );
                        }

                        if ( l_errl )
                        {
                            // Create IStep error log and cross reference to error
                            // that occurred
                            l_stepError.addErrorDetails( l_errl );

                            // Commit Error
                            errlCommit( l_errl, HWPF_COMP_ID );
                       }
                    } // end processor for loop
                } // end non-Axone model
            } // end simics running

            // Call the function to extend VMM to mainstore
            int rc = mm_extend();

            if (rc!=0)
            {
                /*@
                 * @errortype
                 * @moduleid     ISTEP::MOD_EXIT_CACHE_CONTAINED
                 * @reasoncode   ISTEP::RC_MM_EXTEND_FAILED
                 * @userdata1    rc from mm_extend
                 * @userdata2    <UNUSED>
                 *
                 *   @devdesc  Failure extending memory to after
                 *        exiting cache contained mode.
                 */
                l_errl = new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                     ISTEP::MOD_EXIT_CACHE_CONTAINED,
                     ISTEP::RC_MM_EXTEND_FAILED,
                     rc,
                     0);

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : call_proc_exit_cache_contained"
                          " - extendVMM, rc=0x%x",
                          rc );
            }
            else
            {
                // trace out the extend VMM was successful
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS : call_proc_exit_cache_contained"
                          " - extendVMM");
            }
        }
    }

    if ( l_errl )
    {
        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

#ifdef CONFIG_SECUREBOOT
    // Unload the MEMD section that was loaded at the beginning of step11
    l_errl = unloadSecureSection(PNOR::MEMD);
    if (l_errl)
    {
        l_stepError.addErrorDetails(l_errl);
        errlCommit(l_errl, HWPF_COMP_ID);
    }
#endif


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained exit" );
    // @@@@@    END CUSTOM BLOCK:   @@@@@

    // end task, returning any errorlogs to IStepDisp
   return l_stepError.getErrorHandle();
}

};
