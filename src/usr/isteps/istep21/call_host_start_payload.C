/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_host_start_payload.C $            */
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
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <sys/task.h>
#include <initservice/extinitserviceif.H>
#include <hbotcompid.H>
#include <sys/misc.h>
#include <targeting/common/util.H>
#include <pnor/pnorif.H>
#include <kernel/console.H>
#include <util/misc.H>
#include <sys/mm.h>
#include <devtree/devtreeif.H>
#include <kernel/ipc.H> // for internode data areas
#include <mbox/ipc_msg_types.H>
#include <devicefw/userif.H>
#include <arch/pirformat.H>
#include <xz/xz.h>
#include    <isteps/hwpf_reasoncodes.H>

#include <errl/errludtarget.H>


using namespace ERRORLOG;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace TARGETING;

namespace ISTEP_21
{
/**
 * @brief This function will call the Initservice interface to shutdown
 *      Hostboot.  This function will call shutdown, passing in system
 *      attribute variables for the Payload base and Payload offset.
 *
 * @param[in] Host boot master instance number (logical node number)
 * @param[in] Is this the master HB instance [true|false]
 *
 * @return errlHndl_t - NULL if succesful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t callShutdown ( uint64_t i_hbInstance, bool i_masterIntance );

/**
 * @brief This function will send an IPC message to all other HB instances
 *        to perfrom the shutdown sequence.
 * @param[in] Hostboot master instance number (logical node number)
 * @Return errlHndlt_t - Null if succesful, otherwise an error Handle
 */
errlHndl_t broadcastShutdown ( uint64_t i_hbInstance );

/**
 * @brief Re-enables the local core checkstop function
 *
 * @return errlHndl_t error handle
 */
errlHndl_t enableCoreCheckstops();

/**
 * @brief This function will clear the PORE BARs.  Needs to be done
 *      depending on payload type
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t clearPoreBars ( void );

/**
 * @brief This function will check the Istep mode and send the appropriate
 *      mailbox message to the Fsp to indicate what we're doing.
 *
 * @param[in] i_istepModeFlag - Whether or not Isteps is enabled.
 *
 * @param[in] i_spFuncs - The SpFuncs system attribute.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t notifyFsp ( bool i_istepModeFlag,
                       TARGETING::SpFunctions i_spFuncs );


static void simics_load_payload(uint64_t addr) __attribute__((noinline));
static void simics_load_payload(uint64_t addr)
{
    MAGIC_INSTRUCTION(MAGIC_LOAD_PAYLOAD);
}


static errlHndl_t load_pnor_section(PNOR::SectionId i_section,
        uint64_t i_physAddr)
{
    // Get the section info from PNOR.
    PNOR::SectionInfo_t pnorSectionInfo;
    errlHndl_t err = PNOR::getSectionInfo( i_section,
                                           pnorSectionInfo );
    if( err != NULL )
    {
        return err;
    }
    uint32_t uncompressedPayloadSize = pnorSectionInfo.xzCompressed ?
            pnorSectionInfo.xzSize : pnorSectionInfo.size;

    const uint32_t originalPayloadSize = pnorSectionInfo.size;

    printk( "Loading PNOR section %d (%s) %d bytes @0x%lx\n",
            i_section,
            pnorSectionInfo.name,
            originalPayloadSize,
            i_physAddr );

    uint64_t loadAddr = NULL;
    // Use simics optimization if we are running under simics which has very
    // slow PNOR access.
    if ( Util::isSimicsRunning()  )
    {
        //TODO RTC:143500
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "If you are running simics, and have a xz compressed ",
                  "payload image, you are going to fail. RTC 143500");
        simics_load_payload( i_physAddr );
    }
    else
    {
        // Map in the physical memory we are loading into.
        // If we are not xz compressed, the uncompressedSize is
        // equal to the original size.
        uint64_t loadAddr = reinterpret_cast<uint64_t>(
            mm_block_map( reinterpret_cast<void*>( i_physAddr ),
                          uncompressedPayloadSize ) );

        // Print out inital progress bar.
#ifdef CONFIG_CONSOLE
        const int progressSteps = 80;
        int progress = 0;
        for ( int i = 0; i < progressSteps; ++i )
        {
            printk( "." );
        }
        printk( "\r" );
#endif

        if(!pnorSectionInfo.xzCompressed)
        {
            // Load the data block by block and update the progress bar.
            const uint32_t BLOCK_SIZE = 4096;
            for ( uint32_t i = 0; i < originalPayloadSize; i += BLOCK_SIZE )
            {
                memcpy( reinterpret_cast<void*>( loadAddr + i ),
                        reinterpret_cast<void*>( pnorSectionInfo.vaddr + i ),
                        std::min( originalPayloadSize - i, BLOCK_SIZE ) );
#ifdef CONFIG_CONSOLE
                for ( int new_progress = (i * progressSteps) /
                                         originalPayloadSize;
                    progress <= new_progress; progress++ )
                {
                    printk( "=" );
                }
#endif
            }
#ifdef CONFIG_CONSOLE
            printk( "\n" );
#endif
        }
    }

    if(pnorSectionInfo.xzCompressed)
    {
        struct xz_buf b;
        struct xz_dec *s;
        enum xz_ret ret;

        xz_crc32_init();

        s = xz_dec_init(XZ_SINGLE, 0);
        if(s == NULL)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                     "load_pnor_section: XZ Embedded Initialization failed");
            return err;
        }

        static const uint64_t compressed_SIZE = originalPayloadSize;
        static const uint64_t decompressed_SIZE = uncompressedPayloadSize;

        b.in = reinterpret_cast<uint8_t *>( pnorSectionInfo.vaddr);
        b.in_pos = 0;
        b.in_size = compressed_SIZE;
        b.out = reinterpret_cast<uint8_t *>(loadAddr);
        b.out_pos = 0;
        b.out_size = decompressed_SIZE;

        ret = xz_dec_run(s, &b);

        if(ret == XZ_STREAM_END)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "load_pnor_section: The %s section was decompressed.",
                     pnorSectionInfo.name);
        }else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                     "load_pnor_section: xz-embedded returned an error, ",
                     "the ret is %d",ret);

            //Clean up memory
            xz_dec_end(s);

            /*@
             * @errortype
             * @reasoncode       fapi::RC_INVALID_RETURN_XZ_CODE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         fapi::MOD_START_XZ_PAYLOAD
             * @devdesc          xz-embedded has returned an error.
             *                   the return code can be found in xz.h
             * @custdesc         Error uncompressing payload image from
             *                   boot flash
             * @userdata1        Return code from xz-embedded
             * @userdata2[0:31]  Original Payload Size
             * @userdata2[32:63] Uncompressed Payload Size
             */
             err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           fapi::MOD_START_XZ_PAYLOAD,
                                           fapi::RC_INVALID_RETURN_XZ_CODE,
                                           ret,TWO_UINT32_TO_UINT64(
                                                   originalPayloadSize,
                                                   uncompressedPayloadSize));
             err->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);
             return err;
         }
         xz_dec_end(s);
    }

    return NULL;
}


void* call_host_start_payload (void *io_pArgs)
{
    errlHndl_t  l_errl  =   NULL;

    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_start_payload entry" );

    // For single-node systems, the non-master processors can be in a
    // different logical (powerbus) group.  Need to migrate task to master.
    task_affinity_pin();
    task_affinity_migrate_to_master();

    uint64_t this_node = PIR_t(task_getcpuid()).groupId;

    task_affinity_unpin();

#ifdef CONFIG_BMC_IPMI

    // TODO ISSUE 118082
    // ENABLE CODE BELOW ONCE OPAL COMPLETES ipmi WATCHDOG
#if 0
            //run the ipmi watchdog for a longer period to transition
            // to opel
            errlHndl_t err_ipmi = IPMIWATCHDOG::setWatchDogTimer(
                    IPMIWATCHDOG::DEFAULT_HB_OPAL_TRANSITION_COUNTDOWN);

            if(err_ipmi)
            {
               TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "init: ERROR: Set IPMI watchdog Failed");
                err_ipmi->collectTrace("ISTEPS_TRACE",256);
                errlCommit(err_ipmi, ISTEP_COMP_ID );

            }
#endif

    // TODO ISSUE 118082
    // REMOVE CODE BELOW ONCE OPAL COMPLETES IPMI WATCHDOG
    // THE CODE BELOW STOPS THE IPMI TIMER FROM RUNNING
    // TO PREVENT IT GETTING TRIGGERED DURING HB_OPAL TRANSITION

    // Call setWatchdogTimer without the default DON'T STOP
    // flag to stop the watchdog timer
    errlHndl_t err_ipmi = IPMIWATCHDOG::setWatchDogTimer(
            IPMIWATCHDOG::DEFAULT_HB_OPAL_TRANSITION_COUNTDOWN,
            IPMIWATCHDOG::BIOS_FRB2);

    if(err_ipmi)
    {
       TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "init: ERROR: Set IPMI watchdog Failed");
        err_ipmi->collectTrace("ISTEPS_TRACE",256);
        errlCommit(err_ipmi, ISTEP_COMP_ID );

    }

#endif

    // broadcast shutdown to other HB instances.
    l_errl = broadcastShutdown(this_node);

    if( l_errl == NULL)
    {
        //  - Run CXX testcases
        l_errl = INITSERVICE::executeUnitTests();
    }

    if( l_errl == NULL )
    {
// todo RTC:132413 Special Wakeup updates for P9
#if (0)
        l_errl = disableSpecialWakeup();
#endif
    }

    if( l_errl == NULL )
    {
        //  - Call shutdown using payload base, and payload entry.
        //      - base/entry will be from system attributes
        //      - this will start the payload (Phyp)
        // NOTE: this call will not return if successful.
        l_errl = callShutdown(this_node, true);

    };

    if( l_errl )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "istep start_payload_failed see plid 0x%x", l_errl->plid());

        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit(l_errl, ISTEP_COMP_ID);

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_start_payload exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

//
// Call shutdown
//
errlHndl_t callShutdown ( uint64_t i_masterInstance,
                          bool i_isMaster)
{
    errlHndl_t err = NULL;
    uint64_t payloadBase = 0x0;
    uint64_t payloadEntry = 0x0;
    uint64_t payloadData = 0x0;
    bool istepModeFlag = false;
    uint64_t status = SHUTDOWN_STATUS_GOOD;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"callShutdown()" );

    do
    {
        if( i_isMaster == false )
        {

            // Revert back to standard runtime mode where core checkstops
            // do not escalate to system checkstops
            // Workaround for HW286670
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "calling enableCoreCheckstops() in node");

            err = enableCoreCheckstops();

            if ( err )
            {
                break;
            }

            if(is_phyp_load())
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "calling clearPoreBars() in node");

                //If PHYP then clear out the PORE BARs
                err = clearPoreBars();
                if( err )
                {
                    break;
                }
            }

        }

// @todo RTC:123019 I2CM changes for P9bringup
#if (0)
        // Phyp needs us to program all of the I2C masters with the bus
        // divisor
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Setup I2C Masters" );
        err = I2C::i2cSetupActiveMasters(I2C::I2C_PROC_ALL);
        if( err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Error setting up I2C Bus Divisors" );
            // just commit the error and keep going
            errlCommit(err, ISTEP_COMP_ID);
        }
#endif
        // Get Target Service, and the system target.
        TargetService& tS = targetService();
        TARGETING::Target* sys = NULL;
        (void) tS.getTopLevelTarget( sys );

        if( NULL == sys )
        {
            // Error getting system target to get payload related values.  We
            // will create an error to be passed back.  This will cause the
            // istep to fail.
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"System Target was NULL!" );

            /*@
             * @errortype
             * @reasoncode       RC_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         MOD_START_PAYLOAD_CALL_SHUTDOWN
             * @userdata1        <UNUSED>
             * @userdata2        <UNUSED>
             * @devdesc          System target was NULL!
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                           MOD_START_PAYLOAD_CALL_SHUTDOWN,
                                           RC_TARGET_NULL,
                                           0x0,
                                           0x0 );

            break;
        }

        // Get Payload base/entry from attributes
        payloadBase = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        payloadEntry = sys->getAttr<TARGETING::ATTR_PAYLOAD_ENTRY>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Payload Base: 0x%08x, Entry: 0x%08x",
                   payloadBase, payloadEntry );
        payloadBase = (payloadBase * MEGABYTE);
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"   base: 0x%08x",
                   payloadBase );

        // Get Istep Mode flag
        istepModeFlag = sys->getAttr<ATTR_ISTEP_MODE>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Istep mode flag: %s",
                   ((istepModeFlag) ? "Enabled" : "Disabled") );

        // Get the Service Processor Functions
        TARGETING::SpFunctions spFuncs =
                sys->getAttr<TARGETING::ATTR_SP_FUNCTIONS>();

        if(i_isMaster)
        {
            // Notify Fsp with appropriate mailbox message.
            err = notifyFsp( istepModeFlag,
                             spFuncs );

            if( err )
            {
                break;
            }

            // Load payload data in Sapphire mode when
            // SP Base Services not enabled
            if( is_sapphire_load() && (!INITSERVICE::spBaseServicesEnabled()))
            {
                err = load_pnor_section( PNOR::PAYLOAD, payloadBase );
                if ( err ) { break; }
                payloadData = DEVTREE::get_flatdevtree_phys_addr();
            }
        }

        // do the shutdown.
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "callShutdown finished, shutdown = 0x%x.",
                   status );
        INITSERVICE::doShutdown( status,
                                 false,
                                 payloadBase,
                                 payloadEntry,
                                 payloadData,
                                 i_masterInstance);

    } while( 0 );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"callShutdown()" );

    return err;
}

errlHndl_t broadcastShutdown ( uint64_t i_hbInstance )
{
    errlHndl_t err = NULL;
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    assert(sys != NULL);

    TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
        sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

    do
    {
        // Set up the start_payload_data_area before
        // broadcasting the shutdown to the slave HB instances
        memset(&KernelIpc::start_payload_data_area,
               '\0',
               sizeof(KernelIpc::start_payload_data_area));

        KernelIpc::start_payload_data_area.node_count = 0;
        KernelIpc::start_payload_data_area.lowest_PIR = 0xfffffffffffffffful;

        // ATTR_HB_EXISTING_IMAGE only gets set on a multi-drawer system.
        // Currently set up in host_sys_fab_iovalid_processing() which only
        // gets called if there are multiple physical nodes.
        if(hb_images == 0)
        {
            // Single node system
            KernelIpc::start_payload_data_area.node_count = 1;
            break;
        }

        // continue - multi-node

        uint8_t node_map
            [sizeof(TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP_type)];

        sys->tryGetAttr<TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>(node_map);

        uint64_t node_count = 0;

        // Count the number of hb instances before sending
        // any start_payload messages
        for(uint64_t drawer = 0; drawer < sizeof(node_map); ++drawer)
        {
            uint64_t node = node_map[drawer];

            if(node < (sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8))
            {

                // set mask to msb
                TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
                    ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

                if( 0 != ((mask >> node) & hb_images ) )
                {
                    ++node_count;
                }
            }
        }

        KernelIpc::start_payload_data_area.node_count = node_count;

        // send message to all other existing hb instances except this one.
        for(uint64_t drawer = 0; drawer < sizeof(node_map); ++drawer)
        {
            uint64_t node = node_map[drawer];

            if(node < (sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) &&
               node != i_hbInstance)
            {

                // set mask to msb
                TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
                    ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

                if( 0 != ((mask >> node) & hb_images ) )
                {
                    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "start_payload-sending msg for drawer %d",
                               drawer );
                    msg_t * msg = msg_allocate();
                    msg->type = IPC::IPC_START_PAYLOAD;
                    msg->data[0] = i_hbInstance;
                    err = MBOX::send(MBOX::HB_IPC_MSGQ, msg, node);
                    if (err)
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "MBOX::send failed");
                        break;
                    }
                }
            }
        }

    } while(0);

    return err;
}
/**
 * @brief Re-enables the local core checkstop function
 */
errlHndl_t enableCoreCheckstops()
{
    errlHndl_t l_errl = NULL;
    //@TODO RTC:133848
#if 0
    void* l_slwPtr = NULL;
    int mm_rc = 0;

    // for OpenPower systems, leave core checkstops as system checkstops
    if( is_sapphire_load() && (!INITSERVICE::spBaseServicesEnabled()) )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Leaving local core checkstops as escalating to system checkstop" );
        return NULL;
    }
    //@todo-RTC:130092 Remove this when Opal support is in place

    // loop thru all proc and find all functional ex units
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);
    for (TargetHandleList::const_iterator l_procIter =
         l_procTargetList.begin();
         l_procIter != l_procTargetList.end();
         ++l_procIter)
    {
        const TARGETING::Target* l_pChipTarget = *l_procIter;

        //  calculate location of the SLW output buffer
        uint64_t l_physAddr =
          l_pChipTarget->getAttr<TARGETING::ATTR_SLW_IMAGE_ADDR>();
        l_slwPtr = mm_block_map(reinterpret_cast<void*>(l_physAddr),
                                HOMER_MAX_STOP_IMG_SIZE_IN_MB*MEGABYTE);
        if( l_slwPtr == NULL )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Error from mm_block_map : phys=%.16X", l_physAddr );
            /*@
             * @errortype
             * @reasoncode   RC_MM_MAP_ERR
             * @moduleid     MOD_ENABLE_CORE_CHECKSTOPS
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @userdata1    Size of STOP IMG
             * @userdata2    Physical address
             * @devdesc      mm_block_map() returns error
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            l_errl =
              new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP::MOD_ENABLE_CORE_CHECKSTOPS,
                                      ISTEP::RC_MM_MAP_ERR,
                                      HOMER_MAX_STOP_IMG_SIZE_IN_MB*MEGABYTE,
                                      l_physAddr);
        }

        // Get EX list under this proc
        TARGETING::TargetHandleList l_exList;
        getChildChiplets( l_exList, l_pChipTarget, TYPE_EX );

        for (TargetHandleList::const_iterator
             l_exIter = l_exList.begin();
             l_exIter != l_exList.end();
             ++l_exIter)
        {
            TARGETING::Target* l_exTarget = *l_exIter;

            // Write the runtime version of the Action1 reg
            // Core FIR Action1 Register value from Nick
            uint64_t action1_reg = 0xFEFC17F7FF9C8A09;
            size_t opsize = sizeof(uint64_t);
            l_errl = deviceWrite( l_exTarget,
                        &action1_reg,
                        opsize,
                        DEVICE_SCOM_ADDRESS(EX_CORE_FIR_ACTION1_0x10013107) );
            if( l_errl )
            {
                break;
            }

            // Need to force core checkstops to escalate to a system checkstop
            //  by telling the SLW to update the ACTION1 register when it
            //  comes out of winkle  (see HW286670)
            TARGETING::ATTR_CHIP_UNIT_type l_coreId =
              l_exTarget->getAttr<ATTR_CHIP_UNIT>();
            uint32_t l_rc = p8_pore_gen_scom_fixed( l_slwPtr,
                                           P8_SLW_MODEBUILD_IPL,
                                           EX_CORE_FIR_ACTION1_0x10013107,
                                           l_coreId,
                                           action1_reg,//ignored
                                           P8_PORE_SCOM_NOOP,
                                           P8_SCOM_SECTION_NC );
            if( l_rc )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR: ACTION1: chip=%.8X, core=0x%x,l_rc=0x%x",
                           get_huid(l_pChipTarget), l_coreId, l_rc );
                /*@
                 * @errortype
                 * @reasoncode  RC_BAD_RC
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    MOD_ENABLE_CORE_CHECKSTOPS
                 * @userdata1[00:31]  rc from p8_pore_gen_scom_fixed function
                 * @userdata1[32:63]  address being added to image
                 * @userdata2[00:31]  Failing Proc HUID
                 * @userdata2[32:63]  Failing Core Id
                 *
                 * @devdesc p8_pore_gen_scom_fixed returned an error when
                 *          attempting to erase a reg value in the PORE image.
                 * @custdesc         A problem occurred during the IPL
                 *                   of the system.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                     ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     MOD_ENABLE_CORE_CHECKSTOPS,
                                     RC_BAD_RC,
                                     TWO_UINT32_TO_UINT64(l_rc,
                                             EX_CORE_FIR_ACTION1_0x10013107),
                                     TWO_UINT32_TO_UINT64(
                                             get_huid(l_pChipTarget),
                                             l_coreId) );
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
                l_errl->collectTrace("ISTEPS_TRACE",256);
                break;
            }
        }

        mm_rc = mm_block_unmap(l_slwPtr);
        if( mm_rc )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Error from mm_block_unmap : rc=%d, ptr=%p", mm_rc, l_slwPtr );
            /*@
             * @errortype
             * @reasoncode   ISTEP::RC_MM_UNMAP_ERR
             * @moduleid     ISTEP::MOD_ENABLE_CORE_CHECKSTOPS
             * @severity     ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @userdata1    Return Code
             * @userdata2    Unmap address
             * @devdesc      mm_block_unmap() returns error
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            l_errl =
                new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      ISTEP::MOD_ENABLE_CORE_CHECKSTOPS,
                                      ISTEP::RC_MM_UNMAP_ERR,
                                      mm_rc,
                                      reinterpret_cast<uint64_t>
                                      (l_slwPtr));
            // Just commit error and keep going
            errlCommit( l_errl, ISTEP_COMP_ID );
        }
        l_slwPtr = NULL;

        if(l_errl)
        {
            break;
        }
    }
#endif
    return l_errl;
}

/**
 * @brief This function will clear the PORE BARs.  Needs to be done
 *      depending on payload type
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t clearPoreBars ( void )
{
    errlHndl_t l_errl = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "set PORE bars back to 0" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    // loop thru all the cpus and reset the pore bars.
    for (TargetHandleList::const_iterator
         l_proc_iter = l_procTargetList.begin();
         l_proc_iter != l_procTargetList.end();
         ++l_proc_iter)
    {
        //  make a local copy of the CPU target
        const TARGETING::Target* l_proc_target = *l_proc_iter;

        //  trace HUID
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "target HUID %.8X", TARGETING::get_huid(l_proc_target));

        //@TODO RTC:133848 cast OUR type of target to a FAPI type of target.
#if 0
        fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                                         (const_cast<TARGETING::Target*>(
                                                         l_proc_target)) );

        //  reset pore bar notes:
        //  A mem_size of 0 means to ignore the image address
        //  This image should have been moved to memory after winkle

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         p8_set_pore_bar,
                         l_fapi_proc_target,
                         0,
                         0,
                         0,
                         SLW_MEMORY
                         );
#endif
        if ( l_errl )
        {
            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : p8_set_pore_bar, PLID=0x%x",
                      l_errl->plid()  );
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : p8_set_pore_bar" );
        }

    }   // end for

    return l_errl;
}

//
// Notify the Fsp via Mailbox Message
//
errlHndl_t notifyFsp ( bool i_istepModeFlag,
                       TARGETING::SpFunctions i_spFuncs )
{
    errlHndl_t err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"notifyFsp()" );

    do
    {
        if( i_istepModeFlag )
        {
            // Istep Mode send istep complete
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"Isteps enabled, send istep complete msg" );

            err = INITSERVICE::sendIstepCompleteMsg();

            if( err )
            {
                break;
            }
        }
        else
        {
            // Non-Istep mode send SYNC_POINT_REACHED
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       INFO_MRK"Isteps disabled, send SYNC_POINT_REACHED msg" );

            err = INITSERVICE::sendSyncPoint();

            if( err )
            {
                break;
            }
        }
    } while( 0 );

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"notifyFsp()" );

    return err;
}


};
