/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_exit_cache_contained.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/target.H>
#include <targeting/targplatutil.H>

//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>
#include    <p10_exit_cache_contained.H>

#include <sys/mm.h>
#include <arch/pirformat.H>
#include <isteps/hwpf_reasoncodes.H>
#include <devicefw/userif.H>
#include <util/misc.H>
#include <hwas/common/hwas.H>
#include <sys/misc.h>
#include <vmmconst.h>

#include <intr/interrupt.H>
#include <isteps/mem_utils.H>
#include <arch/magic.H>
#include <runtime/runtime.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


//Simics only register to trigger exit of cache containment
#define EXIT_CACHE_CONTAINED_SCOM_ADDR 0x0000000005000003

/* @brief Zero the entire Hostboot Reserved Memory section. Called after exiting
 * cache-contained mode.
 */
static void zero_hb_reserved_memory()
{
    // Map in the entire physical range for the reserved memory region
    const uint64_t hb_base_pa = RUNTIME::getHbBaseAddrWithNodeOffset();
    const uint64_t hb_rsv_mem_pa = hb_base_pa + VMM_MEMORY_SIZE;
    const size_t rsv_mem_size = VMM_HB_RSV_MEM_SIZE - VMM_MEMORY_SIZE;

    void* const rsv_mem = mm_block_map(reinterpret_cast<void*>(hb_rsv_mem_pa),
                                       rsv_mem_size);

    assert(rsv_mem, "mm_block_map failed to map HB reserved memory region");

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Zeroing HB Reserved Memory from p:0x%lx to p:0x%lx",
              hb_rsv_mem_pa,
              hb_rsv_mem_pa + rsv_mem_size);

    // Zero it out and unmap
    memset(rsv_mem, 0, rsv_mem_size);

    assert(mm_block_unmap(rsv_mem) == 0,
           "mm_block_unmap failed to unmap hb reserved memory region");
}

namespace ISTEP_14
{

void* call_proc_exit_cache_contained (void *io_pArgs)
{
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained entry" );
    errlHndl_t  l_errl = nullptr;

    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    //  extend the memory space from cache out to VMM_MEMORY_SIZE of mainstore
    do{

    //if mirrored then check that there is going to be memory at that location.
    //For sapphire with mirrored location flipped and at zero,
    //this also insures there is memory available to 'exit_cache' to.
    //Also set ATTR_PAYLOAD_BASE here.
    TARGETING::Target* l_sys = nullptr;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != nullptr,
           "ERROR call_proc_exit_cache_contained:: No Top Level Target" );

    //Check that minimum hardware requirement is met.
    //If not, log error and do not proceed
    bool l_bootable;
    l_errl = HWAS::checkMinimumHardware(l_sys, &l_bootable);
    if(l_errl)
    {
        break;
    }
    else if(!l_bootable)
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
        break;
    }


    // Verify the memory config didn't change so much that EFF Topology Id for the boot proc changed.
    // NOTE: Despite the name of the function, this will verify the alt boot proc's EFF Topology Id because
    // by using the alt boot proc EFF Topo Id 0 was already set to a proc with memory that isn't proc0 and if that
    // answer changes here it's still a problem.
    l_errl = UTIL::check_proc0_memory_config();
    if (l_errl || (l_sys->getAttr<ATTR_FORCE_SBE_UPDATE>() & SBE_UPDATE_TYPE_TOPOLOGY_CHECKS))
    {
        // We deconfigured a bunch of dimms and the answer
        // changed for which proc's memory to use. Give up TI
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR check_current_proc_mem_to_use_is_still_valid::"
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
        break;
    }

    TARGETING::TargetHandleList l_procList;
    getAllChips(l_procList, TYPE_PROC);
    ATTR_PAYLOAD_BASE_type payloadBase = 0;


    ATTR_PAYLOAD_IN_MIRROR_MEM_type l_mirrored = false;

    // In Sapphire mode disable mirroring and force
    // payload to zero
    if(!is_sapphire_load())
    {
        payloadBase = l_sys->getAttr<ATTR_PAYLOAD_BASE>();
        l_mirrored = l_sys->getAttr<ATTR_PAYLOAD_IN_MIRROR_MEM>();
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
              *  @custdesc       An internal firmware error occurred
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


    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_exit_cache_contained:: Payload base address is 0x%016lx",
              payloadBase * MEGABYTE);

    l_sys->setAttr<ATTR_PAYLOAD_BASE>(payloadBase);


    // Make sure we actually have memory before we try to use it
    uint64_t l_bottom = get_bottom_mem_addr();
    uint64_t l_top = get_top_mem_addr();
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_exit_cache_contained:: Memory range : %.lX-%.lx", l_bottom, l_top );
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
          *  @custdesc       An internal firmware error occurred
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
        break;
    }
    else
    {
        do {
            // 1) Reclaim all DMA buffers from the FSP
            // 2) Suspend the mailbox with interrupt disable
            // 3) Ensure that interrupt presenter is drained
            // 4) call p10_exit_cache_contained which routes
            //       a chipop to the SBE
            // 5) Resume the mailbox

            l_errl = MBOX::reclaimDmaBfrsFromFsp();
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "ERROR call_proc_exit_cache_contained:: "
                            "MBOX::reclaimDmaBfrsFromFsp");

                // If it not complete then thats okay, but we want to store
                // the log away somewhere. Since we didn't get all the DMA
                // buffers back its not a big deal to commit a log, even if
                // we lose a DMA buffer because of it it doesn't matter that
                // much. This will generate more traffic to the FSP
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit( l_errl, HWPF_COMP_ID );

                // (do not break.   keep going to suspend)
            }

            l_errl = MBOX::suspend(true, true);
            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR call_proc_exit_cache_contained:: MBOX::suspend");
                break;
            }

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_exit_cache_contained:: draining interrupt Q");
            INTR::drainQueue();

            //The HWP takes a list of processors, first build the list
            std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>> l_fapiProcList;
            for (const auto & l_procChip: l_procList)
            {
                fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                              l_fapi_cpu_target(l_procChip);
                l_fapiProcList.push_back(l_fapi_cpu_target);
            }

            if(Util::isSimicsRunning())
            {
                // notify simics exiting cache contained mode
                MAGIC_INSTRUCTION(MAGIC_SIMICS_EXIT_CACHE_CONTAINED);
            }

            // call p10_proc_exit_cache_contained.C HWP to
            //         RUN_ALL functionality
            FAPI_INVOKE_HWP(
                    l_errl,
                    p10_exit_cache_contained,
                    l_fapiProcList,
                    p10_sbe_exit_cache_contained_step_t::RUN_ALL);

            // Don't check the error just yet, first resume the MBOX.
            errlHndl_t l_mboxErrl = MBOX::resume();
            if (l_mboxErrl)
            {
                // Make sure l_errl isn't overwritten.
                if (l_errl != nullptr)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR p10_exit_cache_contained:: error found but also found mbox error when trying to resume, committing HWP log now");
                    // add log to istep error log
                    l_stepError.addErrorDetails( l_errl );
                    // MBOX error can still be gathered from a dump or live
                    // debug.
                    ERRORLOG::errlCommit(l_errl, ISTEP_COMP_ID);
                }
                else
                {
                    l_errl = l_mboxErrl;
                    l_mboxErrl = nullptr;
                }
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR call_proc_exit_cache_contained:: MBOX::resume");
            }
        } while (0);

        // Check if l_errl was set in previous do-while wrapping around p10_exit_cache_contained
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_proc_exit_cache_contained:: failed in p10_exit_cache_contained do-while loop");
            break;
        }

    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS call_proc_exit_cache_contained:: p10_exit_cache_contained passed and we were able to resume the MBOX service" );

    // Call the function to extend VMM to mainstore, must be master
    task_affinity_pin();
    task_affinity_migrate_to_master();

    int rc = mm_extend();

    task_affinity_unpin();

    if (rc!=0)
    {
        /*@
          * @errortype
          * @moduleid     ISTEP::MOD_EXIT_CACHE_CONTAINED
          * @reasoncode   ISTEP::RC_MM_EXTEND_FAILED
          * @userdata1    rc from mm_extend
          * @userdata2    <UNUSED>
          *
          * @devdesc      Failure extending memory to after
          *               exiting cache contained mode.
          * @custdesc     An internal firmware error occurred
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
        break;
    }
    else
    {
        // trace out the extend VMM was successful
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "SUCCESS call_proc_exit_cache_contained::"
                  " - extendVMM passed");
    }

    zero_hb_reserved_memory();

    }while(0);

    if ( l_errl )
    {
        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained exit" );
    // @@@@@    END CUSTOM BLOCK:   @@@@@

    // end task, returning any errorlogs to IStepDisp
   return l_stepError.getErrorHandle();
}

};
