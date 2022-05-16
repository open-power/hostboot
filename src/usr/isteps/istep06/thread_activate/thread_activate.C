/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/thread_activate/thread_activate.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
 *  @file thread_activate.C
 *
 *  Support file to start non-primary threads
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <devicefw/userif.H>
#include    <sys/misc.h>
#include    <sys/mm.h>
#include    <sys/mmio.h>
#include    <p10_thread_control.H>
#include    <arch/pirformat.H>
#include    <arch/pvrformat.H>
#include    <arch/magic.H>
#include    <console/consoleif.H>

//  targeting support
#include    <targeting/common/target.H>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/util.H>

#include    <fapi2.H>
#include    <fapi2/target.H>
#include    <fapi2_hw_access.H>
#include    <plat_hwp_invoker.H>
#include    <istep_reasoncodes.H>

#include    <pnor/pnorif.H>
#include    <vpd/mvpdenums.H>
#include    <vfs/vfs.H>
#include    <xscom/xscomif.H>
#include    <kernel/machchk.H>

namespace   THREAD_ACTIVATE
{

void activate_threads( errlHndl_t& io_rtaskRetErrl )
{
    errlHndl_t  l_errl  =   NULL;
    bool l_wakeup_lib_loaded = false;

    TRACFCOMP( g_fapiTd,
               "activate_threads entry" );

    do
    {
        // get the sys target
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        assert( sys != NULL );

        // get the master processor target
        TARGETING::Target* l_masterProc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );
        if( l_masterProc == NULL )
        {
            TRACFCOMP( g_fapiImpTd,
                     "Could not find master proc!!!" );

            assert(false);
        }

        // get the list of core targets for this proc chip
        TARGETING::TargetHandleList l_coreTargetList;
        TARGETING::getChildChiplets( l_coreTargetList,
                                     l_masterProc,
                                     TARGETING::TYPE_CORE,
                                     false);

        // set the fused core mode attribute
        PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );

        //We need to read the EXPORT_REGL_STATUS register to tell if the fuse
        //has been blown to force PHYP -> SMT 8 and force OPAL -> SMT 4
        const uint64_t EXPORT_REGL_STATUS_SCOM_REG   = 0x10009;
        const uint64_t IS_FUSED_BLOWN_BIT_MASK = 0x0100000000000000ull;
        uint64_t l_chipIdReadout = 0;
        size_t l_size = sizeof(l_chipIdReadout);
        l_errl = deviceRead(l_masterProc,
                            &l_chipIdReadout,
                            l_size,
                            DEVICE_SCOM_ADDRESS(EXPORT_REGL_STATUS_SCOM_REG) );

        if(l_errl)
        {
            TRACFCOMP( g_fapiTd,ERR_MRK"activate_threads: Failed reading fused bits!" );
            // break from do loop if error occured
            break;
        }

        uint8_t l_isFuseBlown = (l_chipIdReadout & IS_FUSED_BLOWN_BIT_MASK);

        TARGETING::ATTR_FUSED_CORE_MODE_HB_type l_coreMode;
        TARGETING::ATTR_FUSED_CORE_OPTION_type l_option;

        if( l_pvr.smt == PVR_t::SMT4_MODE )
        {
            l_coreMode = TARGETING::FUSED_CORE_MODE_HB_SMT4_ONLY;
            l_option = TARGETING::FUSED_CORE_OPTION_USING_NORMAL_CORES;
        }
        else // SMT8_MODE
        {
            l_coreMode = TARGETING::FUSED_CORE_MODE_HB_SMT8_ONLY;
            l_option = TARGETING::FUSED_CORE_OPTION_USING_FUSED_CORES;
            sys->setAttr<TARGETING::ATTR_FUSED_CORE_MODE_HB>
                (TARGETING::FUSED_CORE_MODE_HB_SMT8_ONLY);
        }
        sys->setAttr<TARGETING::ATTR_FUSED_CORE_MODE_HB>(l_coreMode);
        if( l_isFuseBlown )
        {
            sys->setAttr<TARGETING::ATTR_FUSED_CORE_OPTION>(l_option);
        }

        TRACFCOMP( g_fapiImpTd, "Core Mode = %d, Fuseblow = %d, Option = %d",
                   l_coreMode, l_isFuseBlown, l_option );
        CONSOLE::displayf(CONSOLE::DEFAULT,  nullptr, "SMT=%d, Fuse=%d", l_coreMode, l_isFuseBlown);

        // -----------------------------------
        // Activate threads on the master core
        // -----------------------------------

        // find the core/thread we're running on
        task_affinity_pin();
        task_affinity_migrate_to_master(); //just in case...
        uint64_t cpuid = task_getcpuid();
        CONSOLE::displayf(CONSOLE::DEFAULT,  nullptr, "BootThread=%d", cpuid);

        // Now that the checkstop handler is running (or we don't have one),
        //  setup the machine check code to trigger a checkstop for UE
        TRACFCOMP( g_fapiImpTd,"Enabling machine check handler to generate checkstops on master thread" );

        uint64_t l_xstopXscom = XSCOM::generate_mmio_addr( l_masterProc,
                           Kernel::MachineCheck::MCHK_XSTOP_FIR_SCOM_ADDR );
        set_mchk_data( l_xstopXscom,
                   Kernel::MachineCheck::MCHK_XSTOP_FIR_VALUE );

        task_affinity_unpin();

        uint64_t l_masterCoreID = PIR_t::coreFromPir(cpuid);
        uint64_t l_masterThreadID = PIR_t::threadFromPir(cpuid);

        // find the master core
        const TARGETING::Target* l_masterCore = NULL;
        for( const auto & l_core:l_coreTargetList)
        {
            TARGETING::ATTR_CHIP_UNIT_type l_coreId =
                    (l_core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
            if( l_coreId == l_masterCoreID )
            {
                l_masterCore = (l_core);
                break;
            }
        }

        if( l_masterCore == NULL )
        {
            TRACFCOMP( g_fapiImpTd,
                       "Could not find a target for core %d",
                       l_masterCoreID );

            /*@
             * @errortype
             * @moduleid     ISTEP::MOD_THREAD_ACTIVATE
             * @reasoncode   ISTEP::RC_NO_MASTER_CORE_TARGET
             * @userdata1    Master cpu id
             * @userdata2    Master processor chip huid
             * @devdesc      activate_threads> Could not find a target
             *               for the master core
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             ISTEP::MOD_THREAD_ACTIVATE,
                                             ISTEP::RC_NO_MASTER_CORE_TARGET,
                                             cpuid,
                                             TARGETING::get_huid(l_masterProc));
            l_errl->collectTrace("TARG",256);
            l_errl->collectTrace(FAPI_TRACE_NAME,256);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

            break;
        }

        TRACFCOMP( g_fapiTd,
                   "Master CPU : c%d t%d (HUID=%.8X)",
                   l_masterCoreID, l_masterThreadID,
                   TARGETING::get_huid(l_masterCore) );

        // cast OUR type of target to a FAPI type of target.
        const fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapiCore0(l_masterCore);

        // AVPs might enable a subset of the available threads
        uint64_t max_threads = cpu_thread_count();
        uint64_t en_threads, en_threads_master;
        en_threads = en_threads_master =
                    sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();

        // Core0_thread:  0 1 2 3  Core1_thread: 0 1 2 3
        //   NORMAL(SMT4) - E E E                - - - -
        //   FUSED (SMT8) - E - -                E E - -
        // * E=enable, Core0_t0=master already enabled
        const uint64_t SMT8_ENABLE_THREADS_MASK = 0xC000000000000000;
        const uint64_t SMT8_FUSE0_THREADS_MASK  = 0xA000000000000000;
        const uint64_t SMT8_FUSE1_THREADS_MASK  = 0x5000000000000000;
        if( l_coreMode == TARGETING::FUSED_CORE_MODE_HB_SMT8_ONLY )
        {
            // First capture if threads 0,2 are enabled.  Then eliminate
            // odd threads and compress to bits 0,1
            uint64_t threads = en_threads & SMT8_FUSE0_THREADS_MASK;
            en_threads_master = threads & SMT8_ENABLE_THREADS_MASK;  //T0
            en_threads_master |= (threads << 1) & SMT8_ENABLE_THREADS_MASK;//T2
        }

        TRACFCOMP( g_fapiTd,
                   "activate_threads max_threads=%d, en_threads_master=0x%016X",
                   max_threads, en_threads_master );

        // Set the start-threads bitset (4 bits)
        // Mask off the master thread that is already running
        const uint32_t ENABLE_THREADS_SHIFT = 60;
        uint8_t thread_bitset = fapi2::thread_id2bitset(l_masterThreadID);
        thread_bitset = ~(thread_bitset) &
                            (en_threads_master >> ENABLE_THREADS_SHIFT);

        // send a magic instruction for PHYP Simics to work...
        MAGIC_INSTRUCTION(MAGIC_SIMICS_CORESTATESAVE);

        // parameters: i_target   => core target
        //             i_threads  => thread bitset (0b0000..0b1111)
        //             i_command  =>
        //               PTC_CMD_SRESET => initiate sreset thread command
        //               PTC_CMD_START  => initiate start thread command
        //               PTC_CMD_STOP   => initiate stop thread command
        //               PTC_CMD_STEP   => initiate step thread command
        //               PTC_CMD_QUERY  => query and return thread state
        //                                 return data in o_ras_status
        //             i_warncheck => convert pre/post checks errors to
        //                            warnings
        //             o_rasStatusReg => Complete RAS status reg 64-bit buffer
        //             o_state        => N/A - Output state not used for
        //                               PTC_CMD_SRESET command
        //
        fapi2::buffer<uint64_t> l_rasStatus = 0;
        uint64_t l_threadState = 0;
        FAPI_INVOKE_HWP( l_errl, p10_thread_control,
                         l_fapiCore0,     //i_target
                         static_cast<ThreadSpecifier>(thread_bitset),   //i_threads
                         PTC_CMD_SRESET,  //i_command
                         false,           //i_warncheck
                         l_rasStatus,     //o_rasStatusReg
                         l_threadState);  //o_state

        if ( l_errl != NULL )
        {
            TRACFCOMP( g_fapiImpTd,
                       "ERROR: 0x%.8X :  proc_thread_control HWP"
                       "( cpu %d, thread_bitset 0x%02X, "
                       "l_rasStatus 0x%lx )",
                       l_errl->reasonCode(),
                       l_masterCoreID,
                       thread_bitset,
                       l_rasStatus );
        }
        else
        {
            TRACFCOMP(g_fapiTd,
                      "SUCCESS: p10_thread_control HWP"
                      "( cpu %d, thread_bitset 0x%02X )",
                      l_masterCoreID,
                      thread_bitset );
        }

        if(l_errl)
        {
            break;
        }

        // -----------------------------------------
        // Activate threads on the master-fused core
        // -----------------------------------------

        if( l_coreMode == TARGETING::FUSED_CORE_MODE_HB_SMT8_ONLY )
        {
            uint64_t l_fusedCoreID = l_masterCoreID + 1;

            // find the master-fused core
            const TARGETING::Target* l_fusedCore = NULL;
            for( const auto & l_core:l_coreTargetList)
            {
                TARGETING::ATTR_CHIP_UNIT_type l_coreId =
                        (l_core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                if( l_coreId == l_fusedCoreID )
                {
                    l_fusedCore = (l_core);
                    break;
                }
            }

            if( l_fusedCore == NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                        "Could not find a target for core %d",
                        l_fusedCoreID );

                /*@
                * @errortype
                * @moduleid     ISTEP::MOD_THREAD_ACTIVATE
                * @reasoncode   ISTEP::RC_NO_FUSED_CORE_TARGET
                * @userdata1    Master-fused core id
                * @userdata2    Master-fused processor chip huid
                * @devdesc      activate_threads> Could not find a target
                *               for the master-fused core
                * @custdesc     A problem occurred during the IPL
                *               of the system.
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ISTEP::MOD_THREAD_ACTIVATE,
                                    ISTEP::RC_NO_FUSED_CORE_TARGET,
                                    l_fusedCoreID,
                                    TARGETING::get_huid(l_masterProc));
                l_errl->collectTrace("TARG",256);
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            TRACFCOMP( g_fapiTd,
                       "Master-Fused CPU : c%d (HUID=%.8X)",
                       l_fusedCoreID, TARGETING::get_huid(l_fusedCore) );

            // cast OUR type of target to a FAPI type of target.
            const fapi2::Target<fapi2::TARGET_TYPE_CORE> l_fapiCore1(l_fusedCore);

            // First capture if threads 1,3 are enabled.  Then eliminate
            // even threads and compress to bits 0,1
            uint64_t en_threads_c1;
            uint64_t threads = en_threads & SMT8_FUSE1_THREADS_MASK;
            en_threads_c1 = (threads << 1) & SMT8_ENABLE_THREADS_MASK; //T1
            en_threads_c1 |= (threads << 2) & SMT8_ENABLE_THREADS_MASK;//T3


            TRACFCOMP( g_fapiTd,
                    "activate_threads max_threads=%d, en_threads_c1=0x%016X",
                    max_threads, en_threads_c1 );

            // Set the start-threads bitset (4 bits)
            thread_bitset = en_threads_c1 >> ENABLE_THREADS_SHIFT;

            // see HWP call above for parameter definitions
            l_rasStatus = 0;
            l_threadState = 0;
            FAPI_INVOKE_HWP( l_errl, p10_thread_control,
                            l_fapiCore1,     //i_target1
                            //i_threads
                            static_cast<ThreadSpecifier>(thread_bitset),
                            PTC_CMD_SRESET,  //i_command
                            false,           //i_warncheck
                            l_rasStatus,     //o_rasStatusReg
                            l_threadState);  //o_state

            if ( l_errl != NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                        "ERROR: 0x%.8X :  proc_thread_control HWP"
                        "( cpu %d, thread_bitset 0x%02X, "
                        "l_rasStatus 0x%lx )",
                        l_errl->reasonCode(),
                        l_masterCoreID,
                        thread_bitset,
                        l_rasStatus );
            }
            else
            {
                TRACFCOMP(g_fapiTd,
                        "SUCCESS: p10_thread_control HWP"
                        "( cpu %d, thread_bitset 0x%02X )",
                        l_masterCoreID,
                        thread_bitset );
            }

            if(l_errl)
            {
                break;
            }
        }  // end if( l_coreMode == TARGETING::FUSED_CORE_MODE_HB_SMT8_ONLY )
    } while(0);

    //make sure we always unload the module if we loaded it
    if( l_wakeup_lib_loaded )
    {
        errlHndl_t l_tmpErrl =
          VFS::module_unload( "libp10_cpuWkup.so" );
        if ( l_tmpErrl )
        {
            TRACFCOMP( g_fapiTd,ERR_MRK"thread_activate: Error unloading libp10_cpuWkup module" );
            if(l_errl)
            {
                errlCommit( l_tmpErrl, ISTEP_COMP_ID );
            }
            else
            {
                l_errl = l_tmpErrl;
            }
        }
    }

    TRACFCOMP( g_fapiTd,
               "activate_threads exit" );

    io_rtaskRetErrl = l_errl;

    return;
}

};   // end namespace

/**
 * @brief   set up _start() task entry procedure for PNOR daemon
 */
TASK_ENTRY_MACRO( THREAD_ACTIVATE::activate_threads );
