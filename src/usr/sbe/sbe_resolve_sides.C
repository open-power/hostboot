/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/sbe_resolve_sides.C $                             */
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

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errlreasoncodes.H>
#include <errl/hberrltypes.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <util/misc.H>
#include <pnor/pnorif.H>
#include <pnor/ecc.H>
#include <devicefw/driverif.H>
#include <sys/mm.h>
#include <sys/misc.h>
#include <hwas/common/deconfigGard.H>
#include <initservice/initserviceif.H>
#include <console/consoleif.H>
#include <config.h>
#include <ipmi/ipmiwatchdog.H>
#include <ipmi/ipmisensor.H>
#include <sbe/sbeif.H>
#include <sbe/sbereasoncodes.H>
#include "sbe_resolve_sides.H"
#include "sbe_update.H"

//  fapi support
#include    <fapi.H>
#include    <fapiHwpExecutor.H>
#include    <hwpf/plat/fapiPlatHwpInvoker.H>
#include    <hwpf/plat/fapiPlatTrace.H>

//Procedures
#include <p8_xip_customize.H>
#include <sbe_xip_image.h>
#include <p8_image_help_base.H>

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_sbe;

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


using namespace ERRORLOG;
using namespace TARGETING;

namespace SBE
{
    enum {
        SBE_IMG_VADDR = VMM_VADDR_SBE_UPDATE,
        RING_BUF1_VADDR = FIXED_SEEPROM_WORK_SPACE + SBE_IMG_VADDR,
        RING_BUF2_VADDR = RING_BUF1_VADDR + FIXED_RING_BUF_SIZE,
        //NOTE: recycling the same memory space for different
        //steps in the process.
        SBE_ECC_IMG_VADDR = RING_BUF1_VADDR,
        SBE_ECC_IMG_MAX_SIZE = VMM_VADDR_SBE_UPDATE_END - SBE_ECC_IMG_VADDR,
    };

/////////////////////////////////////////////////////////////////////
errlHndl_t resolveProcessorSbeSeeproms()
{
    errlHndl_t err = NULL;
    errlHndl_t err_cleanup = NULL;
    sbeResolveState_t sideState;
    bool l_cleanupVmmSpace = false;
    bool l_restartNeeded   = false;

    TRACUCOMP( g_trac_sbe,
               ENTER_MRK"resolveProcessorSbeSeeproms()" );

    do{

#ifdef CONFIG_NO_SBE_UPDATES
        TRACFCOMP( g_trac_sbe, INFO_MRK"resolveProcessorSbeSeeproms() -  "
                   "SBE updates not configured");
        break;
#endif

#ifdef CONFIG_SBE_UPDATE_SIMULTANEOUS
        TRACFCOMP( g_trac_sbe, INFO_MRK"resolveProcessorSbeSeeproms() - "
                   "Do Nothing in SBE_UPDATE_SIMULTANEOUS mode");
        break;
#endif

#ifdef CONFIG_SBE_UPDATE_SEQUENTIAL
        // Check if FSP-services are enabled and if we're running in simics
        if ( !INITSERVICE::spBaseServicesEnabled() &&
             !Util::isSimicsRunning() )
        {
            assert (false, "resolveProcessorSbeSeeproms() - "
                    "SBE_UPDATE_SEQUENTIAL mode, but FSP-services are not "
                    "enabled - Invalid Configuration");
        }
        else
        {
            TRACFCOMP( g_trac_sbe, INFO_MRK"resolveProcessorSbeSeeproms() - "
                       "Do Nothing in SBE_UPDATE_SEQUENTIAL mode with FSP-"
                       "services enabled or running in simics");
             break;
        }
#endif


        // Don't run this function in simics
        if ( Util::isSimicsRunning() )
        {
            TRACFCOMP( g_trac_sbe, INFO_MRK"resolveProcessorSbeSeeproms() - "
                       "Do Nothing in SBE_UPDATE_INDEPENDENT mode in simics");
             break;
        }

        // Get Target Service, and the system target.
        TargetService& tS = targetService();
        TARGETING::Target* sys = NULL;
        (void) tS.getTopLevelTarget( sys );
        assert(sys, "resolveProcessorSbeSeeproms() system target is NULL");


        //Make sure procedure constants keep within expected range.
        assert((FIXED_SEEPROM_WORK_SPACE <= VMM_SBE_UPDATE_SIZE/2),
               "resolveProcessorSbeSeeproms() FIXED_SEEPROM_WORK_SPACE "
               "too large");
        assert((FIXED_RING_BUF_SIZE <= VMM_SBE_UPDATE_SIZE/4),
               "resolveProcessorSbeSeeproms() FIXED_RING_BUF_SIZE too "
               "large");

        // Create VMM space for p8_xip_customize() procedure
        err = createSbeImageVmmSpace();
        if (err)
        {
            TRACFCOMP( g_trac_sbe,
                       INFO_MRK"resolveProcessorSbeSeeproms: "
                       "createSbeImageVmmSpace() Failed. ",
                       "rc=0x%.4X", err->reasonCode() );

            break;
        }
        else
        {
            // Make sure cleanup gets called
            l_cleanupVmmSpace = true;
        }

        /*****************************************************************/
        /*  Iterate over all the functional processors and do for each:  */
        /*****************************************************************/
        TARGETING::TargetHandleList procList;
        TARGETING::getAllChips(procList,
                               TARGETING::TYPE_PROC,
                               true); // true: return functional targets

        if( ( 0 == procList.size() ) ||
            ( NULL == procList[0] ) )
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"resolveProcessorSbeSeeproms() - "
                       "No functional processors Found!" );
            break;
        }

        for(uint32_t i=0; i<procList.size(); i++)
        {
            /***********************************************/
            /*  Get Side This Processor did/will boot from */
            /***********************************************/
            memset(&sideState, 0, sizeof(sideState));
            sideState.tgt = procList[i];

            err = getSideState(sideState);
            if ( err )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK
                           "resolveProcessorSbeSeeproms: Error returned "
                           "from getSideState() "
                           "rc=0x%.4X, Target UID=0x%X",
                           err->reasonCode(),
                           TARGETING::get_huid(sideState.tgt));
                // Don't break - handle error at the end of the loop
            }


            /**********************************************/
            /*  Determine the necessary actions           */
            /**********************************************/
            // Skip if we got an error previously
            if ( err == NULL )
            {
                err = getSideActions(sideState);
                if (err)
                {
                    TRACFCOMP( g_trac_sbe,
                               INFO_MRK"resolveProcessorSbeSeeproms: "
                               "getSideActions() Failed "
                               "rc=0x%.4X, Target UID=0x%X",
                               err->reasonCode(),
                               TARGETING::get_huid(sideState.tgt));

                    // Don't break - handle error at the end of the loop,
                }
            }

            /**********************************************/
            /*  Perform the necessary actions             */
            /**********************************************/
            // Skip if we got an error previously
            if ( err == NULL )
            {
                err = performSideActions(sideState);
                if (err)
                {
                    TRACFCOMP( g_trac_sbe,
                               INFO_MRK"resolveProcessorSbeSeeproms: "
                               "performSideActions() Failed "
                               "rc=0x%.4X, Target UID=0x%X",
                               err->reasonCode(),
                               TARGETING::get_huid(sideState.tgt));

                    // Don't break - handle error at the end of the loop,
                }
                else
                {
                    // Target updated without failure, so set IPL_RESTART
                    // flag, if necessary
                    if (sideState.actions & REIPL)
                    {
                       l_restartNeeded   = true;
                    }
                }
            }

            /**********************************************/
            /*  Handle Errors                             */
            /**********************************************/

            if ( err )
            {
                // Something failed for this target.

                // Commit the error here and move on to the next target,
                // or if no targets left, will just continue the IPL
                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"resolveProcessorSbeSeeproms: "
                           "Committing Error Log rc=0x%.4X eid=0x%.8X "
                           "plid=0x%.8X for Target UID=0x%X, but "
                           "continuing procedure",
                           err->reasonCode(),
                           err->eid(),
                           err->plid(),
                           TARGETING::get_huid(sideState.tgt));
                errlCommit( err, SBE_COMP_ID );
            }


        } //end of Target for loop collecting each target's SBE State


        /**************************************************************/
        /*  Perform System Operation                                  */
        /**************************************************************/
        // Restart IPL if SBE Update requires it
        if ( l_restartNeeded == true )
        {
            TRACFCOMP( g_trac_sbe,
                       INFO_MRK"resolveProcessorSbeSeeprom: Restart "
                       "Needed (%d).",
                       l_restartNeeded);

#ifdef CONFIG_BMC_IPMI
            sbePreShutdownIpmiCalls();
#endif

#ifdef CONFIG_CONSOLE
  #ifdef CONFIG_BMC_IPMI
            CONSOLE::displayf(SBE_COMP_NAME, "System Shutting Down In %d "
                              "Seconds To Perform SBE Update\n",
                              SET_WD_TIMER_IN_SECS);
  #else
            CONSOLE::displayf(SBE_COMP_NAME, "System Shutting Down To "
                              "Perform SBE Update\n");
  #endif

            CONSOLE::flush();
#endif

            TRACFCOMP( g_trac_sbe,
                       INFO_MRK"resolveProcessorSbeSeeproms: Calling "
                       "INITSERVICE::doShutdown() with "
                       "SBE_UPDATE_REQUEST_REIPL = 0x%X",
                       SBE_UPDATE_REQUEST_REIPL );
            INITSERVICE::doShutdown(SBE_UPDATE_REQUEST_REIPL);
        }

    }while(0);


    // Cleanup VMM Workspace
    if ( l_cleanupVmmSpace == true )
    {
        err_cleanup = cleanupSbeImageVmmSpace();
        if ( err_cleanup != NULL )
        {

            if ( err != NULL )
            {
                // 2 error logs, so commit the cleanup log here
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"resolveProcessorSbeSeeproms: Previous "
                           "error (rc=0x%X) before cleanupSbeImageVmmSpace"
                           "() failed.  Committing cleanup error (rc=0x%X) "
                           "and returning original error",
                           err->reasonCode(), err_cleanup->reasonCode()  );

                 errlCommit( err_cleanup, SBE_COMP_ID );
            }
            else
            {
                // no previous error, so returning cleanup error
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"resolveProcessorSbeSeeproms: "
                           "cleanupSbeImageVmmSpace() failed.",
                           "rc=0x%.4X", err_cleanup->reasonCode() );
                err = err_cleanup;
            }
        }
    }


    TRACUCOMP( g_trac_sbe,
               EXIT_MRK"resolveProcessorSbeSeeproms()" );

    return err;
}

/////////////////////////////////////////////////////////////////////
errlHndl_t getSideState(sbeResolveState_t& io_sideState)
{
    errlHndl_t err = NULL;
    TRACUCOMP( g_trac_sbe,
               ENTER_MRK"getSideState()" );

    do{

        /***********************************************/
        /*  Get Side This Processor did/will boot from */
        /***********************************************/
        sbeSeepromSide_t tmp_cur_side = SBE_SEEPROM_INVALID;
        err = getSbeBootSeeprom(io_sideState.tgt, tmp_cur_side);
        if ( err )
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK
                       "resolveProcessorSbeSeeproms() - Error returned "
                       "from getSbeBootSeeprom() "
                       "rc=0x%.4X, Target UID=0x%X",
                       err->reasonCode(),
                       TARGETING::get_huid(io_sideState.tgt));
            break;
        }

        io_sideState.cur_side = tmp_cur_side;

        io_sideState.alt_side = (tmp_cur_side == SBE_SEEPROM0)
                                 ? SBE_SEEPROM1 : SBE_SEEPROM0;

        /**********************************************/
        /*  Get PNOR Side Information                 */
        /**********************************************/
        PNOR::SideId tmp_side = PNOR::WORKING;
        PNOR::SideInfo_t tmp_side_info;
        err = PNOR::getSideInfo (tmp_side, tmp_side_info);
        if ( err )
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK
                       "resolveProcessorSbeSeeproms() - Error returned "
                       "from PNOR::getSideInfo() "
                       "rc=0x%.4X, Target UID=0x%X",
                       err->reasonCode(),
                       TARGETING::get_huid(io_sideState.tgt));
            break;
        }

        io_sideState.pnor_sideId       = tmp_side_info.id;
        io_sideState.pnor_side         = tmp_side_info.side;
        io_sideState.pnor_isGolden     = tmp_side_info.isGolden;
        io_sideState.pnor_hasOtherSide = tmp_side_info.hasOtherSide;

    }while(0);


    TRACUCOMP( g_trac_sbe,
               EXIT_MRK"getSideState(): cur/alt=%d/%d. Side-%c(%d): "
               "isGolden=%d, hasOtherSide=%d",
               io_sideState.cur_side, io_sideState.alt_side,
               io_sideState.pnor_side, io_sideState.pnor_sideId,
               io_sideState.pnor_isGolden, io_sideState.pnor_hasOtherSide );

    return err;
}


/////////////////////////////////////////////////////////////////////
errlHndl_t getSideActions(sbeResolveState_t& io_sideState)
{
    errlHndl_t err = NULL;
    uint32_t l_actions = NO_ACTIONS;
    TRACUCOMP( g_trac_sbe,
               ENTER_MRK"getSideActions()" );

    do{

        // Check if PNOR is running from its GOLDEN side
        if ( io_sideState.pnor_isGolden == true )
        {

            // If Booting From Seeprom that is pointing to PNOR's GOLDEN Side
            // and is possibly the READ_ONLY_SEEPROM - No Re-IPL
            if ( io_sideState.cur_side == READ_ONLY_SEEPROM )
            {
                l_actions |= COPY_READ_ONLY_TO_WORKING;
                io_sideState.update_side = io_sideState.alt_side;
#ifdef CONFIG_PNOR_TWO_SIDE_SUPPORT
                // Need info from PNOR's non-working side for update side
                l_actions |= USE_PNOR_ALT_SIDE;
                TRACUCOMP( g_trac_sbe, "getSideActions(): Asking for "
                           "USE_PNOR_ALT_SIDE: actions=0x%X", l_actions);
#endif
            }
            else
            {
                // non-READ_ONLY_SEEPROM is pointing to PNOR's GOLDEN side
                // This requires an update and re-IPL (Possibly Genesis Mode)
                l_actions |= COPY_READ_ONLY_TO_WORKING;
                l_actions |= REIPL;
                io_sideState.update_side = io_sideState.cur_side;

#ifdef CONFIG_PNOR_TWO_SIDE_SUPPORT
                // Need info from PNOR's non-working side for update side
                l_actions |= USE_PNOR_ALT_SIDE;
                TRACUCOMP( g_trac_sbe, "getSideActions(): Asking for "
                           "USE_PNOR_ALT_SIDE: actions=0x%X", l_actions);
#endif

            }
        }

        // Even though READ_ONLY_SEEPROM is not pointing to PNOR's GOLDEN side,
        // treat like it is if there is only 1 side (ie, Palmetto configuration)
        else if (  ( io_sideState.pnor_hasOtherSide == false ) &&
                   ( io_sideState.cur_side == READ_ONLY_SEEPROM ) )
        {
            l_actions |= COPY_READ_ONLY_TO_WORKING;
            io_sideState.update_side = io_sideState.alt_side;
        }

        else // current Seeprom not pointing to PNOR's GOLDEN side
        {
            l_actions |= CHECK_WORKING_HBB;
            io_sideState.update_side = io_sideState.cur_side;
            // REIPL action will be determined later
        }

        io_sideState.actions = l_actions;

        TRACUCOMP( g_trac_sbe, "getSideActions() Tgt=0x%X: "
                   "pnor_isGolden/hasOtherSide=%d/%d, actions=0x%.8X, "
                   "Update Side=0x%X, cur=%d",
                   TARGETING::get_huid(io_sideState.tgt),
                   io_sideState.pnor_isGolden, io_sideState.pnor_hasOtherSide,
                   io_sideState.actions,
                   io_sideState.update_side,
                   io_sideState.cur_side);

    }while(0);

    TRACUCOMP( g_trac_sbe,
               EXIT_MRK"getSideActions()" );

    return err;
}



/////////////////////////////////////////////////////////////////////
errlHndl_t performSideActions(sbeResolveState_t& io_sideState)
{
    errlHndl_t err = NULL;
    TRACUCOMP( g_trac_sbe,
               ENTER_MRK"performSideActions()" );

    bool updateForHBB = false;
    size_t image_size = 0;
    sbeSeepromVersionInfo_t image_version;

    do{
        if ( io_sideState.actions & COPY_READ_ONLY_TO_WORKING )
        {
            // Copy READ_ONLY SBE Seeprom Image to Memory
            err = readSbeImage(io_sideState.tgt,
                               reinterpret_cast<void*>(SBE_IMG_VADDR),
                               READ_ONLY_SEEPROM,
                               image_size,
                               image_version);
            if ( err )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK
                           "performSideActions: Error returned from "
                           "getSetSbeImage() rc=0x%.4X, Target UID=0x%X, "
                           "actions = 0x%X, image_size=0x%X",
                           err->reasonCode(),
                           TARGETING::get_huid(io_sideState.tgt),
                           io_sideState.actions, image_size);
                break;
            }

            // The host has booted from the golden side because the action
            // COPY_READ_ONLY_TO_WORKING implies io_sideState.pnor_isGolden.
            // We need to write to the version info that the SBE Seeprom Image
            // originates from the golden side Seeprom.

            // If the golden side version struct doesn't already have the newer
            // nest_freq_mhz field add it.
            if (image_version.struct_version < STRUCT_VERSION_NEST_FREQ)
            {
                TargetService& ts = targetService();
                TARGETING::Target* sys = NULL;
                ts.getTopLevelTarget(sys);

                image_version.nest_freq_mhz =
                                        sys->getAttr<ATTR_NEST_FREQ_MHZ>();
            }

            // indicate that the version struct is the latest version
            image_version.struct_version = STRUCT_VERSION_LATEST;

            // indicate that the SBE image we are copying originates from
            // the golden side seeprom.  This value will be read and printed
            // in the traces each time getSeepromSideVersion is called.
            image_version.origin = GOLDEN_SIDE;
        }

        if ( io_sideState.actions & CHECK_WORKING_HBB )
        {
            // Copy current SBE Seeprom Image to Memory
            // NOTE: Seprate section from above because of possible future
            // improvement to use MBPD SB Keyword bit to keep track of HBB

            err = readSbeImage(io_sideState.tgt,
                                 reinterpret_cast<void*>(SBE_IMG_VADDR),
                                 io_sideState.update_side,
                                 image_size,
                                 image_version);
            if ( err )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK
                           "performSideActions: Error returned from "
                           "getSetSbeImage() rc=0x%.4X, Target UID=0x%X, "
                           "actions = 0x%X, image_size=0x%X",
                           err->reasonCode(),
                           TARGETING::get_huid(io_sideState.tgt),
                           io_sideState.actions, image_size);
                break;
            }

        }


        if ( ( io_sideState.actions & COPY_READ_ONLY_TO_WORKING ) ||
             ( io_sideState.actions & CHECK_WORKING_HBB ) )
        {
            // verify HBB
            PNOR::SideId pnor_side = PNOR::WORKING;

#ifdef CONFIG_PNOR_TWO_SIDE_SUPPORT
            // In certain situations need info from Alternate PNOR
            if ( io_sideState.actions & USE_PNOR_ALT_SIDE)
            {
                pnor_side = PNOR::ALTERNATE;
            }
#endif



            err = resolveImageHBBaddr(io_sideState.tgt,
                                      reinterpret_cast<void*>(SBE_IMG_VADDR),
                                      io_sideState.update_side,
                                      pnor_side,
                                      updateForHBB);
            if ( err )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK
                           "performSideActions: Error returned from "
                           "resolveImageHBBaddr() rc=0x%.4X, Target UID=0x%X, "
                           "actions = 0x%X",
                           err->reasonCode(),
                           TARGETING::get_huid(io_sideState.tgt),
                           io_sideState.actions);
                break;
            }

            // Since HBB was updated, we need to re-IPL if not booting on
            // READ_ONLY seeprom
            if ( ( updateForHBB == true ) &&
                 ( io_sideState.cur_side != READ_ONLY_SEEPROM ) )
            {
                io_sideState.actions |= REIPL;

                TRACUCOMP( g_trac_sbe, ERR_MRK
                           "performSideActions: resolveImageHBBaddr returned "
                           "updateForHBB=%d, and not on READ_ONLY_SEEPROM so "
                           "REIPL (actions=0x%X)",
                           updateForHBB, io_sideState.actions);
            }
        }

        if ( ( io_sideState.actions & COPY_READ_ONLY_TO_WORKING ) ||
             ( updateForHBB == true ) )
        {
            //  Write Seeprom Image from memory to Seeprom
            err = writeSbeImage(io_sideState.tgt,
                                reinterpret_cast<void*>(SBE_IMG_VADDR),
                                io_sideState.update_side,
                                image_size,
                                image_version);
            if ( err )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK
                           "performSideActions: Error returned from "
                           "getSetSbeImage() rc=0x%.4X, Target UID=0x%X, "
                           "actions = 0x%X",
                           err->reasonCode(),
                           TARGETING::get_huid(io_sideState.tgt),
                           io_sideState.actions);
                break;
            }
        }

    }while(0);

    TRACUCOMP( g_trac_sbe,
               EXIT_MRK"performSideActions()" );

    return err;
}


/////////////////////////////////////////////////////////////////////
errlHndl_t readSbeImage(TARGETING::Target* i_target,
                        void* o_imgPtr,
                        sbeSeepromSide_t i_side,
                        size_t& o_image_size,
                        sbeSeepromVersionInfo_t& o_image_version)
{
    TRACUCOMP( g_trac_sbe,
               ENTER_MRK"readSbeImage(): tgt=0x%X, i_side=%d "
               "o_imgPtr=%p, o_image_size=0x%X",
               TARGETING::get_huid(i_target), i_side, o_imgPtr, o_image_size);

    errlHndl_t err = NULL;
    int64_t rc = 0;
    PNOR::ECC::eccStatus eccStatus = PNOR::ECC::CLEAN;
    EEPROM::eeprom_chip_types_t l_seeprom = sbe_side_sync[i_side];
    size_t image_size_ECC = 0;

    // Need to ensure that io_imgPtr is at SBE_IMG_VADDR = VMM_VADDR_SBE_UPDATE
    // since we need to use the VMM_VADDR_SBE_UPDATE space
    assert ( o_imgPtr == reinterpret_cast<void*>(SBE_IMG_VADDR),
             "getSetSbeImage() - o_imgPtr is not at SBE_IMG_VADDR");

    do{

        // Clear out back half of page block to use as temp space
        // for ECC injected SBE Image.
        rc = mm_remove_pages(RELEASE,
                             reinterpret_cast<void*>
                             (SBE_ECC_IMG_VADDR),
                             SBE_ECC_IMG_MAX_SIZE);
        if( rc )
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"getSetSbeImage() - Error "
                           "from mm_remove_pages : rc=%d,  HUID=0x%.8X.",
                           rc, TARGETING::get_huid(i_target) );
            /*@
             * @errortype
             * @moduleid     SBE_READ_SBE_IMAGE
             * @reasoncode   SBE_REMOVE_PAGES_FOR_EC
             * @userdata1    Requested Address
             * @userdata2    rc from mm_remove_pages
             * @devdesc      updateProcessorSbeSeeproms> mm_remove_pages
             *               RELEASE failed
             * @custdesc     A problem occurred while updating processor
             *               boot code.
             */
            err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                SBE_READ_SBE_IMAGE,
                                SBE_REMOVE_PAGES_FOR_EC,
                                TO_UINT64(SBE_ECC_IMG_VADDR),
                                TO_UINT64(rc),
                                true /*Add HB SW Callout*/ );

            //Target isn't directly related to fail, but could be useful
            // to see how far we got before failing.
            ErrlUserDetailsTarget(i_target).addToLog(err);
            err->collectTrace(SBE_COMP_NAME);
            break;
        }

        /*****************************************/
        /*  Get Image Size                       */
        /*****************************************/
        err = getSbeImageSize(i_target,
                              o_imgPtr,
                              i_side,
                              o_image_size);
        if(err)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"readSbeImage: - Error from "
                       "getSbeImageSize(): rc=0x%.4X, side=%d, HUID=0x%.8X.",
                       err->reasonCode(),
                       i_side, TARGETING::get_huid(i_target));
            break;
        }

        // make sure returned size is 8 byte aligned
        o_image_size = ALIGN_8(o_image_size);

        /*****************************************/
        /*  Do Actual Read                       */
        /*****************************************/
        image_size_ECC = (o_image_size*9)/8;

        assert(image_size_ECC <= SBE_ECC_IMG_MAX_SIZE,
               "getSetSbeImage() SBE Image with ECC too large");

        // Read image to memory space
        err = DeviceFW::deviceOp(
                          DeviceFW::READ,
                          i_target,
                          reinterpret_cast<void*>
                            (SBE_ECC_IMG_VADDR),
                          image_size_ECC,
                          DEVICE_EEPROM_ADDRESS(
                                        l_seeprom,
                                        SBE_IMAGE_SEEPROM_ADDRESS));

        if(err)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"readSbeImage: - Error "
                       "from EEPROM op: rc=0x%.4X, seeprom=%d (side=%d). "
                       "HUID=0x%.8X. SBE_VADDR=0x%.16X, ECC_VADDR=0x%.16X, "
                       "size=0x%.8X, eccSize=0x%.8X, EEPROM offset=0x%X",
                       err->reasonCode(), l_seeprom, i_side,
                       TARGETING::get_huid(i_target),
                       SBE_IMG_VADDR, SBE_ECC_IMG_VADDR, o_image_size,
                       image_size_ECC, SBE_IMAGE_SEEPROM_ADDRESS);
            break;
        }

        /*****************************************/
        /*  Remove ECC From Image                */
        /*****************************************/

        // Clear destination
        memset( o_imgPtr, 0, MAX_SEEPROM_IMAGE_SIZE );

        // Remove ECC
        eccStatus = PNOR::ECC::removeECC(reinterpret_cast<uint8_t*>
                                             (SBE_ECC_IMG_VADDR),
                                         reinterpret_cast<uint8_t*>
                                             (o_imgPtr),
                                         o_image_size);

        // Fail if uncorrectable ECC
        if ( eccStatus == PNOR::ECC::UNCORRECTABLE )
        {
            // There is an ECC issue with this SEEPROM

            TRACFCOMP( g_trac_sbe,ERR_MRK"readSbeImage: ECC Error "
                       "On SBE Image Read eccStatus=%d sI=%d, sI_ECC="
                       "%d, HUID=0x%.8X, Seeprom %d (side=%d)",
                       eccStatus, o_image_size, image_size_ECC,
                       TARGETING::get_huid(i_target),
                       l_seeprom, i_side );

            /*@
             * @errortype
             * @moduleid     SBE_READ_SBE_IMAGE
             * @reasoncode   SBE_ECC_FAIL
             * @userdata1[0:15]     ECC Status
             * @userdata1[16:31]    SEEPROM Side
             * @userdata1[32:63]    Target HUID
             * @userdata2[0:31]     Size - No Ecc
             * @userdata2[32:63]    Size - ECC
             * @devdesc      ECC Fail Reading SBE Image
             */
            err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                SBE_READ_SBE_IMAGE,
                                SBE_ECC_FAIL,
                                TWO_UINT32_TO_UINT64(
                                     ( (eccStatus << 16 ) |
                                       l_seeprom ),
                                     TARGETING::get_huid(i_target)),
                                TWO_UINT32_TO_UINT64(o_image_size,
                                                     image_size_ECC));

            err->collectTrace(SBE_COMP_NAME);

            err->addPartCallout(
                                 i_target,
                                 HWAS::SBE_SEEPROM_PART_TYPE,
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );

            ErrlUserDetailsTarget(i_target).addToLog(err);

            break;

        } // ECC check


        // Read out SBE Version Info
        bool seeprom_ver_ECC_fail = false;
        err = getSeepromSideVersion(i_target,
                                    l_seeprom,
                                    o_image_version,
                                    seeprom_ver_ECC_fail);


        if(err)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"readSbeImage: - Error "
                       "from getSeepromSideVersion: rc=0x%.4X, seeprom=%d "
                       "(side=%d). HUID=0x%.8X",
                       err->reasonCode(), l_seeprom, i_side,
                       TARGETING::get_huid(i_target));
            break;
        }

        else if (seeprom_ver_ECC_fail == true)
        {
            // For now, any issues will be addressed in SBE Update
            // later in the IPL
            TRACFCOMP( g_trac_sbe, ERR_MRK"readSbeImage: ECC fail=%d "
                       "Reading Seeprom Version seeprom=%d "
                       "(side=%d). HUID=0x%.8X",
                       seeprom_ver_ECC_fail, l_seeprom, i_side,
                       TARGETING::get_huid(i_target));
        }

        TRACDBIN(g_trac_sbe, "readSbeImage: SBE Info Version",
                 reinterpret_cast<uint8_t*>(&o_image_version),
                 sizeof(o_image_version));

    }while(0);


    TRACUCOMP( g_trac_sbe,
               EXIT_MRK"readSbeImage() - eccStatus=%d, "
               "size=0x%X, size_ECC=0x%X",
               eccStatus, o_image_size, image_size_ECC);


    return err;
}


/////////////////////////////////////////////////////////////////////
errlHndl_t writeSbeImage(TARGETING::Target* i_target,
                          void* i_imgPtr,
                          sbeSeepromSide_t i_side,
                          size_t i_image_size,
                          sbeSeepromVersionInfo_t& io_version)
{
    TRACFCOMP( g_trac_sbe,
               ENTER_MRK"writeSbeImage(): tgt=0x%X, i_side=%d "
               "i_imgPtr=%p, i_image_size=0x%X",
               TARGETING::get_huid(i_target), i_side, i_imgPtr, i_image_size);

    errlHndl_t err = NULL;
    int64_t rc = 0;
    EEPROM::eeprom_chip_types_t l_seeprom = sbe_side_sync[i_side];
    size_t image_size_ECC = 0;

    // For Version Information
    size_t sbeInfoSize = sizeof(sbeSeepromVersionInfo_t);
    size_t sbeInfoSize_ECC = (sbeInfoSize*9)/8;

    uint8_t * sbeInfo_data_ECC = static_cast<uint8_t*>
                                            (malloc(sbeInfoSize_ECC));


    // Need to ensure that io_imgPtr is at SBE_IMG_VADDR = VMM_VADDR_SBE_UPDATE
    // since we need to use the VMM_VADDR_SBE_UPDATE space
    assert ( i_imgPtr == reinterpret_cast<void*>(SBE_IMG_VADDR),
             "writeSbeImage() - io_imgPtr is not at SBE_IMG_VADDR");

    do{

        // Clear out back half of page block to use as temp space
        // for ECC injected SBE Image.
        rc = mm_remove_pages(RELEASE,
                             reinterpret_cast<void*>
                             (SBE_ECC_IMG_VADDR),
                             SBE_ECC_IMG_MAX_SIZE);
        if( rc )
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"writeSbeImage() - Error "
                       "from mm_remove_pages : rc=%d,  HUID=0x%.8X.",
                       rc, TARGETING::get_huid(i_target) );
            /*@
             * @errortype
             * @moduleid     SBE_WRITE_SBE_IMAGE
             * @reasoncode   SBE_REMOVE_PAGES_FOR_EC
             * @userdata1    Requested Address
             * @userdata2    rc from mm_remove_pages
             * @devdesc      updateProcessorSbeSeeproms> mm_remove_pages
             *               RELEASE failed
             * @custdesc     A problem occurred while updating processor
             *               boot code.
             */

            err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                SBE_WRITE_SBE_IMAGE,
                                SBE_REMOVE_PAGES_FOR_EC,
                                TO_UINT64(SBE_ECC_IMG_VADDR),
                                TO_UINT64(rc),
                                true /*Add HB SW Callout*/ );

            //Target isn't directly related to fail, but could be useful
            //to see how far we got before failing.
            ErrlUserDetailsTarget(i_target).addToLog(err);
            err->collectTrace(SBE_COMP_NAME);
            break;
        }

        // Inject ECC
        PNOR::ECC::injectECC(reinterpret_cast<uint8_t*>(i_imgPtr),
                             i_image_size,
                             reinterpret_cast<uint8_t*>
                                 (SBE_ECC_IMG_VADDR));

        /*****************************************/
        /*  Do Actual Write of Image             */
        /*****************************************/
        image_size_ECC = (i_image_size*9)/8;

        assert(image_size_ECC <= SBE_ECC_IMG_MAX_SIZE,
               "writeSbeImage() SBE Image with ECC too large");

        err = deviceWrite(i_target,
                          reinterpret_cast<void*>
                            (SBE_ECC_IMG_VADDR),
                          image_size_ECC,
                          DEVICE_EEPROM_ADDRESS(
                                        l_seeprom,
                                        SBE_IMAGE_SEEPROM_ADDRESS));

        if(err)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"writeSbeImage: - Error "
                       "from EEPROM op: rc=0x%.4X, seeprom=%d (side=%d). "
                       "HUID=0x%.8X. SBE_VADDR=0x%.16X, ECC_VADDR=0x%.16X, "
                       "size=0x%.8X, eccSize=0x%.8X, EEPROM offset=0x%X",
                       err->reasonCode(), l_seeprom, i_side,
                       TARGETING::get_huid(i_target),
                       SBE_IMG_VADDR, SBE_ECC_IMG_VADDR, i_image_size,
                       image_size_ECC, SBE_IMAGE_SEEPROM_ADDRESS);
            break;
        }

        /********************************************/
        /*  Do Actual Write of Version Information  */
        /********************************************/

        // Update the image crc in the version information
        uint32_t image_crc = Util::crc32_calc(i_imgPtr, i_image_size);

        memcpy( &(io_version.data_crc),
                &image_crc,
                sizeof(image_crc));

       TRACDBIN( g_trac_sbe, "writeSbeImage: Version no ECC",
                 reinterpret_cast<uint8_t*>(&io_version), sizeof(io_version));

        // Inject ECC
        memset( sbeInfo_data_ECC, 0, sbeInfoSize_ECC);
        PNOR::ECC::injectECC(reinterpret_cast<uint8_t*>(&io_version),
                             sbeInfoSize, sbeInfo_data_ECC);

        TRACDBIN( g_trac_sbe, "writeSbeImage: Version with ECC",
                  sbeInfo_data_ECC, sbeInfoSize_ECC);

        err = deviceWrite( i_target,
                           sbeInfo_data_ECC,
                           sbeInfoSize_ECC,
                           DEVICE_EEPROM_ADDRESS(
                                             l_seeprom,
                                             SBE_VERSION_SEEPROM_ADDRESS));

        if(err)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"writeSbeImage: - Error "
                       "Writing SBE Version Info: rc=0x%.4X, "
                       "HUID=0x%.8X, seeprom=%d, side=%d",
                       err->reasonCode(),
                       TARGETING::get_huid(i_target), l_seeprom, i_side);
            break;
        }

    }while(0);

    // Free allocated memory
    free(sbeInfo_data_ECC);

    TRACUCOMP( g_trac_sbe,
               EXIT_MRK"writeSetSbeImage()" );

    return err;
}




/////////////////////////////////////////////////////////////////////
errlHndl_t getSbeImageSize(TARGETING::Target* i_target,
                               void* i_imgPtr,
                               sbeSeepromSide_t i_side,
                               size_t& o_image_size)
{
    TRACUCOMP( g_trac_sbe,
               ENTER_MRK"geSbeImageSize(): tgt=0x%X, i_side=%d "
               "i_imgPtr=%p, o_image_size=0x%X",
               TARGETING::get_huid(i_target), i_side, i_imgPtr, o_image_size);

    errlHndl_t err = NULL;
    PNOR::ECC::eccStatus eccStatus = PNOR::ECC::CLEAN;
    EEPROM::eeprom_chip_types_t l_seeprom = sbe_side_sync[i_side];
    size_t image_size_ECC = 0;

    // Need to ensure that i_imgPtr is at SBE_IMG_VADDR = VMM_VADDR_SBE_UPDATE
    // since we need to use the VMM_VADDR_SBE_UPDATE space

    assert ( i_imgPtr == reinterpret_cast<void*>(SBE_IMG_VADDR),
             "getSbeImageSize() - i_imgPtr is not at SBE_IMG_VADDR");

    do{
        // Need to read the SbeXipHeader of the image to determine size
        // of the image to read out.
        // Using io_imgPtr space. First read our header+ECC from SBE
        // Seeprom and then use space after that to put header without ECC


        size_t hdr_size = ALIGN_8(sizeof(SbeXipHeader));
        size_t hdr_size_ECC = (hdr_size * 9)/8;

        uint8_t* hdr_ptr = reinterpret_cast<uint8_t*>(i_imgPtr) + hdr_size_ECC;

        memset( i_imgPtr, 0, hdr_size_ECC + hdr_size );

        TRACUCOMP( g_trac_sbe, INFO_MRK"getSetSbeImage() Reading "
                   "SbeXipHeader for Target 0x%X, Seeprom %d "
                   "(side=%d), size_ECC=0x%X (size=0x%X)",
                   TARGETING::get_huid(i_target),
                   l_seeprom, i_side, hdr_size_ECC, hdr_size );

        err = DeviceFW::deviceOp( DeviceFW::READ,
                                  i_target,
                                  i_imgPtr,
                                  hdr_size_ECC,
                                  DEVICE_EEPROM_ADDRESS(
                                                l_seeprom,
                                                SBE_IMAGE_SEEPROM_ADDRESS));

        if(err)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeImageSize: - Error "
                       "Reading SbeXipHeader: rc=0x%.4X, seeprom=%d (side=%d). "
                       "HUID=0x%.8X. size=0x%.8X, EEPROM offset=0x%X",
                       err->reasonCode(), l_seeprom, i_side,
                       TARGETING::get_huid(i_target), sizeof(SbeXipHeader),
                       SBE_IMAGE_SEEPROM_ADDRESS);
            break;
        }


        TRACDBIN( g_trac_sbe,
                 "Data with ECC read from Seeprom",
                 i_imgPtr,
                 hdr_size_ECC );

        // Remove ECC
        eccStatus = PNOR::ECC::removeECC(
                                     reinterpret_cast<uint8_t*>(i_imgPtr),
                                     hdr_ptr,
                                     hdr_size);

        // Fail if uncorrectable ECC
        if ( eccStatus == PNOR::ECC::UNCORRECTABLE )
        {
            TRACFCOMP( g_trac_sbe,ERR_MRK"getSbeImageSize: ECC Error "
                       "On SBE Image Read eccStatus=%d sI=%d, sI_ECC="
                       "%d, HUID=0x%.8X, Seeprom %d (side=%d)",
                       eccStatus, o_image_size, image_size_ECC,
                       TARGETING::get_huid(i_target),
                       l_seeprom, i_side );
            /*@
             * @errortype
             * @moduleid     SBE_GET_SBE_IMAGE_SIZE
             * @reasoncode   SBE_ECC_FAIL
             * @userdata1[0:15]     ECC Status
             * @userdata1[16:31]    SEEPROM Side
             * @userdata1[32:63]    Target HUID
             * @userdata2[0:31]     Size - No Ecc
             * @userdata2[32:63]    Size - ECC
             * @devdesc      ECC Fail Reading SBE Image
             */
            err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                SBE_GET_SBE_IMAGE_SIZE,
                                SBE_ECC_FAIL,
                                TWO_UINT32_TO_UINT64(
                                              ( (eccStatus << 16 ) |
                                                 l_seeprom ),
                                              TARGETING::get_huid(i_target)),
                                TWO_UINT32_TO_UINT64(o_image_size,
                                                     image_size_ECC));
            err->collectTrace(SBE_COMP_NAME);
            err->addPartCallout(
                                i_target,
                                HWAS::SBE_SEEPROM_PART_TYPE,
                                HWAS::SRCI_PRIORITY_HIGH,
                                HWAS::NO_DECONFIG,
                                HWAS::GARD_NULL );

            ErrlUserDetailsTarget(i_target).addToLog(err);

            break;
        }

        TRACDBIN( g_trac_sbe,
                  "Data without ECC read from Seeprom",
                  hdr_ptr,
                  hdr_size );

        o_image_size = (((SbeXipHeader*)hdr_ptr)->iv_imageSize);

    }while(0);

    TRACFCOMP( g_trac_sbe,
               EXIT_MRK"getSbeImageSize(): o_image_size=0x%X", o_image_size );

    return err;
}



/////////////////////////////////////////////////////////////////////
errlHndl_t resolveImageHBBaddr(TARGETING::Target* i_target,
                               void* io_imgPtr,
                               sbeSeepromSide_t i_side,
                               PNOR::SideId  i_pnorSideId,
                               bool& o_imageWasUpdated )
{
    errlHndl_t err = NULL;
    uint64_t data = 0;
    int rc = 0;
    bool rc_fail_on_get = false; // 1=get failed, 0=set failed

    o_imageWasUpdated = false;

    TRACUCOMP( g_trac_sbe,
               ENTER_MRK"resolveImageHBBaddr() - tgt=0x%X, i_side=%d, "
               "i_pnorSideId=%d",
               TARGETING::get_huid(i_target), i_side, i_pnorSideId);

    do{

        // Get info from PNOR
        PNOR::SideInfo_t pnor_side_info;
        err = PNOR::getSideInfo (i_pnorSideId, pnor_side_info);
        if ( err )
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK
                       "resolveImageHBBaddr() - Error returned "
                       "from PNOR::getSideInfo() rc=0x%.4X, Target UID=0x%X "
                       "i_pnorSideId",
                       err->reasonCode(),
                       TARGETING::get_huid(i_target), i_pnorSideId);
            break;
        }

        // Only Need to Check/Update if PNOR has Other Side
        if ( pnor_side_info.hasOtherSide == true )
        {
            // Read the MMIO offset associated with the HBB address
            // from the image
            rc = sbe_xip_get_scalar( io_imgPtr,
                                     "standalone_mbox2_value",
                                     &data);
            if ( rc != 0 )
            {
                rc_fail_on_get = true; // get failed

                TRACFCOMP( g_trac_sbe, ERR_MRK"resolveImageHBBaddr() - "
                           "sbe_xip_get_scalar() failed rc = 0x%X (%d)",
                           rc, rc_fail_on_get);
                break;
            }

            if ( pnor_side_info.hbbMmioOffset == data )
            {
                TRACUCOMP( g_trac_sbe, "resolveImageHBBaddr: Image has MMIO "
                           "offset = 0x%X that matches PNOR MMIO="
                           "0x%X for HBB Address=0x%X",
                           data, pnor_side_info.hbbMmioOffset,
                           pnor_side_info.hbbAddress);
            }
            else
            {
                TRACFCOMP( g_trac_sbe, "resolveImageHBBaddr: Image has MMIO "
                           "offset = 0x%X does NOT match PNOR MMIO="
                           "0x%X for HBB Address=0x%X. Updating Image",
                           data, pnor_side_info.hbbMmioOffset,
                           pnor_side_info.hbbAddress);

                TRACDBIN (g_trac_sbe, "resolveImageHBBaddr: data", &data, 8 );

                TRACDBIN (g_trac_sbe, "resolveImageHBBaddr: hbbMmioOffset",
                          &pnor_side_info.hbbMmioOffset, 8 );
                TRACDBIN (g_trac_sbe, "resolveImageHBBaddr: hbbAddress",
                          &pnor_side_info.hbbAddress, 8);

                rc = sbe_xip_set_scalar( io_imgPtr, "standalone_mbox2_value",
                                         pnor_side_info.hbbMmioOffset);

                if ( rc != 0 )
                {
                    rc_fail_on_get = false; // set failed

                    TRACFCOMP( g_trac_sbe, ERR_MRK"resolveImageHBBaddr() - "
                               "sbe_xip_set_scalar() failed rc = 0x%X (%d)",
                               rc, rc_fail_on_get);
                    break;
                }
                o_imageWasUpdated = true;
            }

        }
        else
        {
              // pnor_side_info.hasOtherSide is false
              TRACUCOMP( g_trac_sbe, "resolveImageHBBaddr: PNOR only has "
                         "1 side - No Update Required");
        }

    }while(0);


    if ( ( err == NULL ) && ( rc != 0) )
    {
        // We failed on get/set cmd above (already traced)

        /*@
         * @errortype
         * @moduleid     SBE_RESOLVE_HBB_ADDR
         * @reasoncode   SBE_IMAGE_GET_SET_SCALAR_FAIL
         * @userdata1    Return Code of failed operation
         * @userdata2    True/False if Get (true) or Set (false) Op failed
         * @devdesc      sbe_xip_get/set_scalar() failed when accessing the
                         HBB Address MMIO offset in 'standalone_mbox2_value'
         * @custdesc     A problem occurred while updating processor
         *               boot code.
         */
        err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            SBE_RESOLVE_HBB_ADDR,
                            SBE_IMAGE_GET_SET_SCALAR_FAIL,
                            TO_UINT64(rc),
                            TO_UINT64(rc_fail_on_get),
                            true /*Add HB SW Callout*/ );

        err->collectTrace(SBE_COMP_NAME);
    }


    TRACUCOMP( g_trac_sbe,
               EXIT_MRK"resolveImageHBBaddr() - o_imageWasUpdated = %d",
               o_imageWasUpdated);

    return err;
}

#ifdef CONFIG_BMC_IPMI
/////////////////////////////////////////////////////////////////////
void sbePreShutdownIpmiCalls( void )
{
    errlHndl_t err = NULL;
    TRACFCOMP( g_trac_sbe, ENTER_MRK"sbePreShutdownIpmiCalls");

    do{
        uint16_t count = 0;
        SENSOR::RebootCountSensor l_sensor;

        // Read reboot count sensor
        err = l_sensor.getRebootCount(count);
        if ( err )
        {
            TRACFCOMP( g_trac_sbe,
                       ERR_MRK"sbePreShutdownIpmiCalls: "
                       "FAIL Reading Reboot Sensor Count. "
                       "Committing Error Log rc=0x%.4X eid=0x%.8X "
                       "plid=0x%.8X, but continuing shutdown",
                       err->reasonCode(),
                       err->eid(),
                       err->plid());
            err->collectTrace(SBE_COMP_NAME);
            errlCommit( err, SBE_COMP_ID );

            // No Break - Still Do Watchdog Timer Call
        }
        else
        {
            // Increment Reboot Count Sensor
            count++;
            TRACFCOMP( g_trac_sbe,
                       INFO_MRK"sbePreShutdownIpmiCalls: "
                       "Writing Reboot Sensor Count=%d", count);

            err = l_sensor.setRebootCount( count );
            if ( err )
            {
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"sbePreShutdownIpmiCalls: "
                           "FAIL Writing Reboot Sensor Count to %d. "
                           "Committing Error Log rc=0x%.4X eid=0x%.8X "
                           "plid=0x%.8X, but continuing shutdown",
                           count,
                           err->reasonCode(),
                           err->eid(),
                           err->plid());
                err->collectTrace(SBE_COMP_NAME);
                errlCommit( err, SBE_COMP_ID );

                // No Break - Still Do Watchdog Timer Call
            }
        }

        // @todo RTC 124679 - Remove Once BMC Monitors Shutdown Attention
        // Set Watchdog Timer before calling doShutdown()
        TRACFCOMP( g_trac_sbe,"sbePreShutdownIpmiCalls: "
                   "Set Watch Dog Timer To %d Seconds",
                   SET_WD_TIMER_IN_SECS);

        err = IPMIWATCHDOG::setWatchDogTimer(
                               SET_WD_TIMER_IN_SECS,  // new time
                               static_cast<uint8_t>
                                          (IPMIWATCHDOG::DO_NOT_STOP |
                                           IPMIWATCHDOG::BIOS_FRB2), // default
                               IPMIWATCHDOG::TIMEOUT_HARD_RESET);
        if(err)
        {
               TRACFCOMP( g_trac_sbe,
                          ERR_MRK"sbePreShutdownIpmiCalls: "
                          "FAIL Setting Watch Dog Timer to %d seconds. "
                          "Committing Error Log rc=0x%.4X eid=0x%.8X "
                          "plid=0x%.8X, but continuing shutdown",
                          SET_WD_TIMER_IN_SECS,
                          err->reasonCode(),
                          err->eid(),
                          err->plid());

                err->collectTrace(SBE_COMP_NAME);
                errlCommit(err, SBE_COMP_ID );
         }

    }while(0);

    TRACFCOMP( g_trac_sbe, EXIT_MRK"sbePreShutdownIpmiCalls");

    return;
}
#endif // CONFIG_BMC_IPMI


} //end SBE Namespace
