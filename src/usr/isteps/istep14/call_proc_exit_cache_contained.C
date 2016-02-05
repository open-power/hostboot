/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_exit_cache_contained.C $     */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <initservice/taskargs.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/target.H>


//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>

#include    <p9_exit_cache_contained.H>


#include <sys/mm.h>
#include <arch/pirformat.H>
#include <isteps/hwpf_reasoncodes.H>

// @TODO RTC:134082 remove below block
// Add P9 - Fake trigger for memory expansion
#include <kernel/console.H>                  // printk status
#include <devicefw/userif.H>
#include <config.h>
// @TODO RTC:134082 remove above block

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{
void* call_proc_exit_cache_contained (void *io_pArgs)
{

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    //  extend the memory space from 8MEG to 32Meg

    //if mirrored then check that there is going to be memory at that location.
    //For sapphire with mirrored location flipped and at zero,
    //this also insures there is memory available to 'exit_cache' to.
    //Also set ATTR_PAYLOAD_BASE here.
    TARGETING::Target* l_sys = NULL;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL );

    errlHndl_t  l_errl  =   NULL;
    uint8_t l_mpipl = l_sys->getAttr<ATTR_IS_MPIPL_HB>();
    ATTR_PAYLOAD_BASE_type payloadBase = 0;

    TARGETING::TargetHandleList l_procList;
    getAllChips(l_procList, TYPE_PROC);

    if(!l_mpipl)
    {
        ATTR_PAYLOAD_IN_MIRROR_MEM_type l_mirrored = false;

        // In Sapphire mode disable mirroring for now - @todo-RTC:108314
        // and force payload to zero
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
                uint64_t hrmor_base =
                    l_sys->getAttr<TARGETING::ATTR_HB_HRMOR_NODAL_BASE>();

                l_mirrorBaseAddr =
                    l_sys->getAttr<TARGETING::ATTR_MIRROR_BASE_ADDRESS>();

                // For single-node systems, the non-master processors can be
                // in a different logical (powerbus) group.
                // Need to migrate task to master.
                task_affinity_pin();
                task_affinity_migrate_to_master();
                uint64_t this_node = PIR_t(task_getcpuid()).groupId;
                task_affinity_unpin();

                l_mirrorBaseAddr += (this_node * hrmor_base)/2;

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
                 *  @moduleid       fapi::MOD_EXIT_CACHE_CONTAINED,
                 *  @reasoncode     fapi::RC_NO_MIRRORED_MEMORY,
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
                     fapi::MOD_EXIT_CACHE_CONTAINED,
                     fapi::RC_NO_MIRRORED_MEMORY,
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
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_exit_cache_contained:: failed on proc with HUID : %d",TARGETING::get_huid(l_procChip)  );
            }
        }



        // no errors so extend VMM.
        if(!l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : call_proc_exit_cache_contained on all procs" );

            // @TODO RTC:134082 remove below block
#ifndef CONFIG_P9_VPO_COMPILE
            // Add P9 - Fake trigger for memory expansion
            TARGETING::Target* l_masterProc = NULL;
            TARGETING::targetService()
              .masterProcChipTargetHandle( l_masterProc );

            uint64_t l_top_addr = get_top_mem_addr();
            uint64_t l_bottom_addr = get_bottom_mem_addr();
            uint64_t l_mem_size = l_top_addr - l_bottom_addr;

            // aggregate scom data to write
            uint64_t l_data[] = {l_bottom_addr,  // Memory Base Address
                                 l_mem_size,     // Memory Size in bytes
                                 1};             // Memory Valid
            uint64_t l_addr = 0x05000000;
            size_t scom_size = sizeof(uint64_t);

            for(uint8_t i = 0;
                i < sizeof(l_data) / sizeof(uint64_t);
                i++)
            {
                l_errl = deviceWrite( l_masterProc,
                                      &(l_data[i]),
                                      scom_size,
                                      DEVICE_SCOM_ADDRESS(l_addr+i) );
                if( l_errl ) { break; }
            }

            if ( l_errl )
            {
                // Create IStep error log and cross reference to error that
                // occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
            }

            printk("Fake Memory now set up.\n");

            // exit cache contained mode
            l_errl = deviceWrite( l_masterProc,
                                  &(l_data[2]),
                                  scom_size,
                                  DEVICE_SCOM_ADDRESS(l_addr+3) );

            if ( l_errl )
            {
                // Create IStep error log and cross reference to error that
                // occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
            }

            printk("Cache contained mode has been exited.\n");
            // End of Add P9 - Fake trigger for memory expansion

            //Set PSI and FSP BARs, activate the PSI link BAR
            //TODO RTC 150260 Re-evaluate if this should be deleted or enabled
//            uint64_t psi = l_masterProc->getAttr<ATTR_PSI_BRIDGE_BASE_ADDR>();
            uint64_t fsp = l_masterProc->getAttr<ATTR_FSP_BASE_ADDR>();
//            psi |= 0x1; //turn on enable bit for PSI, FSP is in PSI Init HWP

//            l_errl = deviceWrite( l_masterProc,
//                                  &psi,
//                                  scom_size,
//                                  DEVICE_SCOM_ADDRESS(0x0501290a) );
            if ( l_errl )
            {
                // Create IStep error log and cross reference to error that
                // occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
            }

            l_errl = deviceWrite( l_masterProc,
                                  &fsp,
                                  scom_size,
                                  DEVICE_SCOM_ADDRESS(0x0501290b) );
            if ( l_errl )
            {
                // Create IStep error log and cross reference to error that
                // occurred
                l_stepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
            }

            //Need to default TOD registers to reasonable value
            // aggregate scom data to write
            uint64_t l_tod_data[] = {
                0x40000, 0x4083000000000000,0x4083000000000000,
                0x40001, 0x0008008011000000,0x8000000000000000,
                0x40002, 0x8000000000000000,0x0008008000000000,
                0x40003, 0x0008008000000000,0x8000000011000000,
                0x40004, 0x8000000000000000,0x00C3000000000000,
                0x40005, 0x0800c30000000000,0x00C3000000000000,
                0x40007, 0x6900000000000000,0x0B60000000000000,
                0x40008, 0x06661D0C00000000,0x06C06CCC00000000,
                0x40010, 0x003F000000000000,0x003F000000000000,
                0x40013, 0x8000000000000000,0x0000000000000000,
            };

            // Per Dean, this workaround should be run against all
            // processor chips.
            TARGETING::TargetHandleList l_cpuTargetList;
            getAllChips(l_cpuTargetList, TYPE_PROC);

            uint32_t l_proc_num = 0;
            for (const auto & l_cpu_target: l_cpuTargetList)
            {
                assert((l_proc_num < 2),
                       "TOD hack does not support more then 2 procs");

                for(uint8_t i = 0;
                    i < (sizeof(l_tod_data) / sizeof(uint64_t));
                    i+=3)
                {
                    l_errl = deviceWrite( l_cpu_target,
                                          &(l_tod_data[i+1+l_proc_num]),
                                          scom_size,
                                          DEVICE_SCOM_ADDRESS(l_tod_data[i]) );
                    if( l_errl ) { break; }
                }

                if ( l_errl )
                {
                    // Create IStep error log and cross reference to error that
                    // occurred
                    l_stepError.addErrorDetails( l_errl );

                    // Commit Error
                    errlCommit( l_errl, HWPF_COMP_ID );
                }
                l_proc_num++;
            }

            printk("Fake TOD Initialized\n");
#endif
            // @TODO RTC:134082 remove above block

            // Call the function to extend VMM to 32MEG
            int rc = mm_extend();

            if (rc!=0)
            {
                /*@
                 * @errortype
                 * @moduleid     fapi::MOD_EXIT_CACHE_CONTAINED
                 * @reasoncode   fapi::RC_MM_EXTEND_FAILED
                 * @userdata1    rc from mm_extend
                 * @userdata2    <UNUSED>
                 *
                 *   @devdesc  Failure extending memory to 32MEG after
                 *        exiting cache contained mode.
                 */
                l_errl = new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                     fapi::MOD_EXIT_CACHE_CONTAINED,
                     fapi::RC_MM_EXTEND_FAILED,
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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained exit" );
    // @@@@@    END CUSTOM BLOCK:   @@@@@

    // end task, returning any errorlogs to IStepDisp
   return l_stepError.getErrorHandle();
}

};
