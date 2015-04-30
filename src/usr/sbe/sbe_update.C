/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/sbe_update.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2015                        */
/* [+] Google Inc.                                                        */
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

#include <vector>
#include <trace/interface.H>
#include <vpd/mvpdenums.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/predicates/predicatectm.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <util/align.H>
#include <util/crc32.H>
#include <util/misc.H>
#include <errno.h>
#include <pnor/pnorif.H>
#include <pnor/ecc.H>
#include <devicefw/driverif.H>
#include <sys/mm.h>
#include <sys/misc.h>
#include <sys/msg.h>
#include <hwas/common/deconfigGard.H>
#include <initservice/initserviceif.H>
#include <console/consoleif.H>
#include <config.h>
#include <sbe/sbeif.H>
#include <sbe/sbereasoncodes.H>
#include "sbe_update.H"
#include "sbe_resolve_sides.H"

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
trace_desc_t* g_trac_sbe = NULL;
TRAC_INIT( & g_trac_sbe, SBE_COMP_NAME, KILOBYTE );

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


// ----------------------------------------
// Global Variables for MBOX Ipl Query
static bool g_mbox_query_done   = false;
static bool g_mbox_query_result = false;
static bool g_istep_mode        = false;

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
    errlHndl_t updateProcessorSbeSeeproms()
    {
        errlHndl_t err = NULL;
        errlHndl_t err_cleanup = NULL;
        sbeTargetState_t sbeState;
        std::vector<sbeTargetState_t> sbeStates_vector;

        bool l_cleanupVmmSpace = false;
        bool l_restartNeeded   = false;

        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"updateProcessorSbeSeeproms()" );

        do{

#ifdef CONFIG_NO_SBE_UPDATES
            TRACFCOMP( g_trac_sbe, INFO_MRK"updateProcessorSbeSeeproms() - "
                       "SBE updates not configured");
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
            // else - continue on
#endif


            // Get Target Service, and the system target.
            TargetService& tS = targetService();
            TARGETING::Target* sys = NULL;
            (void) tS.getTopLevelTarget( sys );
            assert(sys, "updateProcessorSbeSeeproms() system target is NULL");

            /*****************************************************************/
            /* Skip Update if MNFG_FLAG_FSP_UPDATE_SBE_IMAGE is set          */
            /* AND there is a FSP present                                    */
            /*****************************************************************/
            ATTR_MNFG_FLAGS_type mnfg_flags = sys->getAttr<ATTR_MNFG_FLAGS>();
            if ( (mnfg_flags & MNFG_FLAG_FSP_UPDATE_SBE_IMAGE)
                 && INITSERVICE::spBaseServicesEnabled() // true => FSP present
               )
            {
                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update skipped due to "
                           "FSP present and MNFG_FLAG_FSP_UPDATE_SBE_IMAGE "
                           "(0x%.16X) is set in MNFG Flags 0x%.16X",
                           MNFG_FLAG_FSP_UPDATE_SBE_IMAGE, mnfg_flags);
                break;
            }

            // For a future check, determine if in istep mode and FSP is present
            if ( sys->getAttr<ATTR_ISTEP_MODE>() && // true => istep mode
                 INITSERVICE::spBaseServicesEnabled() ) // true => FSP present
            {
                g_istep_mode = true;
            }

            //Make sure procedure constants keep within expected range.
            assert((FIXED_SEEPROM_WORK_SPACE <= VMM_SBE_UPDATE_SIZE/2),
                   "updateProcessorSbeSeeproms() FIXED_SEEPROM_WORK_SPACE "
                   "too large");
            assert((FIXED_RING_BUF_SIZE <= VMM_SBE_UPDATE_SIZE/4),
                   "updateProcessorSbeSeeproms() FIXED_RING_BUF_SIZE too "
                   "large");

            // reset global variables for MBOX Ipl Query
            g_mbox_query_done   = false;
            g_mbox_query_result = false;

            // Create VMM space for p8_xip_customize() procedure
            err = createSbeImageVmmSpace();
            if (err)
            {
                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"updateProcessorSbeSeeproms(): "
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
            /*  1) Check their SBE State  (PNOR, MVPD, SEEPROMs, etc),       */
            /*  2) Determine the Necessary Update                            */
            /*  3) Perform Update Action                                     */
            /*****************************************************************/
            TARGETING::TargetHandleList procList;
            TARGETING::getAllChips(procList,
                                   TARGETING::TYPE_PROC,
                                   true); // true: return functional targets

            if( ( 0 == procList.size() ) ||
                ( NULL == procList[0] ) )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateProcessorSbeSeeproms() - "
                           "No functional processors Found!" );
                break;
            }


            // Get the Master Proc Chip Target for comparisons later
            TARGETING::Target* masterProcChipTargetHandle = NULL;
            err = tS.queryMasterProcChipTargetHandle(
                                                masterProcChipTargetHandle);
            if (err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateProcessorSbeSeeproms() - "
                           "queryMasterProcChipTargetHandle returned error. "
                           "Commit here and continue.  Check below against "
                           "masterProcChipTargetHandle=NULL is ok");
                 errlCommit( err, SBE_COMP_ID );
                 err = NULL;
            }


            for(uint32_t i=0; i<procList.size(); i++)
            {

                /*********************************************/
                /*  Collect SBE Information for this Target  */
                /*********************************************/
                memset(&sbeState, 0, sizeof(sbeState));
                sbeState.target = procList[i];

                TRACUCOMP( g_trac_sbe, "updateProcessorSbeSeeproms(): "
                           "Main Loop: tgt=0x%X, i=%d",
                           TARGETING::get_huid(sbeState.target), i)

                // Check to see if current target is master processor
                if ( sbeState.target == masterProcChipTargetHandle)
                {
                    TRACUCOMP(g_trac_sbe,"sbeState.target=0x%X is MASTER. "
                              " (i=%d)",
                              TARGETING::get_huid(sbeState.target), i);
                    sbeState.target_is_master = true;
                }
                else
                {
                    sbeState.target_is_master = false;
                }

                err = getSbeInfoState(sbeState);

                if (err)
                {
                    TRACFCOMP( g_trac_sbe,
                               INFO_MRK"updateProcessorSbeSeeproms(): "
                               "getSbeInfoState() Failed "
                               "rc=0x%.4X, Target UID=0x%X",
                               err->reasonCode(),
                               TARGETING::get_huid(sbeState.target));

                    // Don't break - handle error at the end of the loop

                }


                /**********************************************/
                /*  Determine update actions for this target  */
                /**********************************************/
                // Skip if we got an error collecting SBE Info State
                if ( err == NULL )
                {
                    err = getTargetUpdateActions(sbeState);
                    if (err)
                    {
                        TRACFCOMP( g_trac_sbe,
                                   INFO_MRK"updateProcessorSbeSeeproms(): "
                                   "getTargetUpdateActions() Failed "
                                   "rc=0x%.4X, Target UID=0x%X",
                                   err->reasonCode(),
                                   TARGETING::get_huid(sbeState.target));

                        // Don't break - handle error at the end of the loop,
                    }
                }

                /**********************************************/
                /*  Perform Update Actions For This Target    */
                /**********************************************/
                if ((err == NULL) && (sbeState.update_actions & DO_UPDATE))
                {
                    err = performUpdateActions(sbeState);
                    if (err)
                    {
                        TRACFCOMP( g_trac_sbe,
                                   INFO_MRK"updateProcessorSbeSeeproms(): "
                                   "performUpdateActions() Failed "
                                   "rc=0x%.4X, Target UID=0x%X",
                                   err->reasonCode(),
                                   TARGETING::get_huid(sbeState.target));

                        // Don't break - handle error at the end of the loop,
                    }
                    else
                    {
                        // Target updated without failure, so set IPL_RESTART
                        // flag, if necessary
                        if (sbeState.update_actions & IPL_RESTART)
                        {
                            l_restartNeeded   = true;
                        }
                    }

                }

                if ( err )
                {
                    // Something failed for this target.
                    // Save error information
                    sbeState.err_plid = err->plid();
                    sbeState.err_eid  = err->eid();
                    sbeState.err_rc   = err->reasonCode();

                    // Commit the error here and move on to the next target,
                    // or if no targets left, will just continue the IPL
                    TRACFCOMP( g_trac_sbe,
                               INFO_MRK"updateProcessorSbeSeeproms(): "
                               "Committing Error Log rc=0x%.4X eid=0x%.8X "
                               "plid=0x%.8X for Target UID=0x%X, but "
                               "continuing procedure",
                               sbeState.err_rc, sbeState.err_eid,
                               sbeState.err_plid,
                               TARGETING::get_huid(sbeState.target));
                    errlCommit( err, SBE_COMP_ID );
                }

                // Push this sbeState onto the vector
                sbeStates_vector.push_back(sbeState);

            } //end of Target for loop collecting each target's SBE State

            /**************************************************************/
            /*  Perform System Operation                                  */
            /**************************************************************/
            // Restart IPL if SBE Update requires it
            if ( l_restartNeeded == true )
            {
                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"updateProcessorSbeSeeproms(): Restart "
                           "Needed (%d). Calling preReIplCheck()",
                           l_restartNeeded);

                err = preReIplCheck(sbeStates_vector);

                if ( err )
                {
                    // Something failed on the check.  Commit the error here
                    // and continue with the Re-IPL Request
                    TRACFCOMP( g_trac_sbe,
                               INFO_MRK"updateProcessorSbeSeeproms(): "
                               "Committing Error Log rc=0x%.4X from "
                               "preReIplCheck(), but doing Re-IPL",
                               err->reasonCode());
                    errlCommit( err, SBE_COMP_ID );
                }

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
                           INFO_MRK"updateProcessorSbeSeeproms(): Calling "
                           "INITSERVICE::doShutdown() with "
                           "SBE_UPDATE_REQUEST_REIPL = 0x%X",
                           SBE_UPDATE_REQUEST_REIPL );
                INITSERVICE::doShutdown(SBE_UPDATE_REQUEST_REIPL);
            }

            /************************************************************/
            /* Deconfigure any Processors that have a Version different */
            /*   from the Master Processor's Version                    */
            /************************************************************/
            err = masterVersionCompare(sbeStates_vector);

            if ( err )
            {
                // Something failed on the check
                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"updateProcessorSbeSeeproms(): Call to "
                           "masterVersionCompare() failed rc=0x%.4X",
                           err->reasonCode());
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
                               ERR_MRK"updateProcessorSbeSeeproms(): Previous "
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
                               ERR_MRK"updateProcessorSbeSeeproms(): "
                               "cleanupSbeImageVmmSpace() failed.",
                               "rc=0x%.4X", err_cleanup->reasonCode() );
                    err = err_cleanup;
                }
            }
        }


        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"updateProcessorSbeSeeproms()" );

        return err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t findSBEInPnor(TARGETING::Target* i_target,
                             void*& o_imgPtr,
                             size_t& o_imgSize,
                             sbe_image_version_t* o_version)
    {
        errlHndl_t err = NULL;
        PNOR::SectionInfo_t pnorInfo;
        sbeToc_t* sbeToc = NULL;
        uint8_t ec = 0;
        PNOR::SectionId pnorSectionId = PNOR::INVALID_SECTION;

        void* hdr_Ptr  = NULL;
        o_imgPtr = NULL;
        o_imgSize = 0;

        TRACDCOMP( g_trac_sbe,
                   ENTER_MRK"findSBEInPnor()" );

        do{

            // Get the correct PNOR Section Id
            if ( i_target->getAttr<ATTR_TYPE>() == TYPE_PROC )
            {
                pnorSectionId = PNOR::SBE_IPL;
            }
            else if ( i_target->getAttr<ATTR_TYPE>() == TYPE_MEMBUF )
            {
                pnorSectionId = PNOR::CENTAUR_SBE;
            }
            else
            {
                // Unsopported target type was passed in
                TRACFCOMP( g_trac_sbe, ERR_MRK"findSBEInPnor: Unsupported "
                           "target type was passed in: uid=0x%X, type=0x%X",
                           TARGETING::get_huid(i_target),
                           i_target->getAttr<ATTR_TYPE>());

                /*@
                 * @errortype
                 * @moduleid     SBE_FIND_IN_PNOR
                 * @reasoncode   SBE_INVALID_INPUT
                 * @userdata1    Target Unit Id
                 * @userdata2    Target Type
                 * @devdesc      Unsupported Target Type passed in
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_FIND_IN_PNOR,
                                    SBE_INVALID_INPUT,
                                    TARGETING::get_huid(i_target),
                                    i_target->getAttr<ATTR_TYPE>());
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
                break;
            }

            // Get SBE PNOR section info from PNOR RP
            err = getSectionInfo( pnorSectionId,
                                        pnorInfo );

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"findSBEInPnor: Error calling "
                           "getSectionInfo() rc=0x%.4X",
                           err->reasonCode() );
                break;
            }

            TRACUCOMP( g_trac_sbe,
                       INFO_MRK"findSBEInPnor: UID=0x%X, sectionId=0x%X. "
                       "pnor vaddr = 0x%.16X",
                       TARGETING::get_huid(i_target),
                       pnorSectionId, pnorInfo.vaddr);

            sbeToc = reinterpret_cast<sbeToc_t*>( pnorInfo.vaddr );

            if (sbeToc->eyeCatch != SBETOC_EYECATCH)
            {
                //The SBE partition does not have the proper eyecatcher
                TRACFCOMP( g_trac_sbe, ERR_MRK"findSBEInPnor: SBE partition "
                           "does not have the proper eyecatcher: was: 0x%X, "
                           "should be: 0x%X",
                           sbeToc->eyeCatch, SBETOC_EYECATCH );

                TRACFBIN( g_trac_sbe, "sbeToc", sbeToc, sizeof(sbeToc_t));

                /*@
                 * @errortype
                 * @moduleid     SBE_FIND_IN_PNOR
                 * @reasoncode   SBE_INVALID_EYECATCHER
                 * @userdata1    SBE TOC EYE-CATCHER
                 * @userdata2    Expected EYE-CATCHER
                 * @devdesc      Unsupported EYE-CATCHER found in TOC
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_FIND_IN_PNOR,
                                    SBE_INVALID_EYECATCHER,
                                    sbeToc->eyeCatch,
                                    SBETOC_EYECATCH);
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
                break;
            }
            else
            {

                //Check the TOC Version
                if( SUPPORTED_TOC_VER != sbeToc->tocVersion)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"findSBEInPnor: Unsupported "
                               "SBE TOC Version in SBE Partition" );

                    TRACFBIN( g_trac_sbe, "sbeToc", sbeToc, sizeof(sbeToc_t));

                    /*@
                     * @errortype
                     * @moduleid          SBE_FIND_IN_PNOR
                     * @reasoncode        SBE_UNSUPPORTED_TOC
                     * @userdata1[0:31]   CHIP EC
                     * @userdata1[32:63]  Expected TOC Version
                     * @userdata2[0:31]   SBE TOC Version
                     * @userdata2[32:63]  SBE TOC EyeCatch
                     * @devdesc      SBE partition contains unsupported version
                     *               of Table of Contents
                     * @custdesc     A problem occurred while updating processor
                     *               boot code.
                     */
                    err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                        SBE_FIND_IN_PNOR,
                                        SBE_UNSUPPORTED_TOC,
                                        TWO_UINT32_TO_UINT64(ec,
                                                             SUPPORTED_TOC_VER),
                                        TWO_UINT32_TO_UINT64(sbeToc->tocVersion,
                                                             sbeToc->eyeCatch));
                    err->collectTrace(SBE_COMP_NAME);
                    err->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                              HWAS::SRCI_PRIORITY_HIGH );

                    break;
                }

                //Walk the TOC and find our current EC
                ec = i_target->getAttr<TARGETING::ATTR_EC>();
                for(uint32_t i=0; i<MAX_SBE_ENTRIES; i++)
                {
                    if(static_cast<uint32_t>(ec) == sbeToc->entries[i].ec)
                    {

                        // EC found in TOC
                        uint64_t offset = pnorInfo.vaddr
                          + static_cast<uint64_t>(sbeToc->entries[i].offset);
                        hdr_Ptr = reinterpret_cast<void*>( offset );

                        o_imgSize = sbeToc->entries[i].size;

                        TRACUCOMP( g_trac_sbe, INFO_MRK"findSBEInPnor: Found "
                                   "EC Image: ec=0x%.2X offset=0x%.16X, i=%d "
                                   "size=0x%X",
                                   ec, offset, i, o_imgSize );
                        break;
                    }
                }
            }

            if(NULL == hdr_Ptr)
            {
                //if we get here, it's an error
                TRACFCOMP( g_trac_sbe,ERR_MRK"findSBEInPnor:SBE Image not "
                           "located, ec=0x%.2X",ec );

                TRACFBIN( g_trac_sbe, "sbeToc", sbeToc, sizeof(sbeToc_t));

                /*@
                 * @errortype
                 * @moduleid     SBE_FIND_IN_PNOR
                 * @reasoncode   SBE_EC_NOT_FOUND
                 * @userdata1[0:31]   CHIP EC
                 * @userdata1[32:63]  PNOR Section ID
                 * @userdata2[0:31]   SBE TOC Version
                 * @userdata2[32:63]  SBE TOC EyeCatch
                 * @devdesc      SBE image for current chip EC was not found
                 *               in PNOR
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_FIND_IN_PNOR,
                                    SBE_EC_NOT_FOUND,
                                    TWO_UINT32_TO_UINT64(ec,
                                                         pnorSectionId),
                                    TWO_UINT32_TO_UINT64(sbeToc->tocVersion,
                                                         sbeToc->eyeCatch));
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
                break;
            }

            //  The SBE Image for the corresponding EC was found, check if
            //  it includes a SBE Header
            if (pnorInfo.sha512perEC)
            {
                TRACFCOMP(g_trac_sbe,INFO_MRK"findSBEInPnor: sha512perEC Found in %s", pnorInfo.name);
                // Advance PNOR pointer 4k to move it past header page to the
                // start of the non-customized SBE image
                o_imgPtr = reinterpret_cast<void*>
                                (reinterpret_cast<char*>(hdr_Ptr)+0x1000);
            }


            if(NULL != o_version)
            {
                err = readPNORVersion(hdr_Ptr,
                                      *o_version);
                if(err)
                {
                    break;
                }
            }

        }while(0);


        TRACDCOMP( g_trac_sbe,
                   EXIT_MRK"findSBEInPnor(): o_imgPtr=%p, o_imgSize=0x%X",
                   o_imgPtr, o_imgSize );


        return err;
    }



/////////////////////////////////////////////////////////////////////
    errlHndl_t procCustomizeSbeImg(TARGETING::Target* i_target,
                                   void* i_sbePnorPtr,
                                   size_t i_maxImgSize,
                                   void* io_imgPtr,
                                   size_t& o_actImgSize)
    {
        errlHndl_t err = NULL;
        fapi::ReturnCode rc_fapi = fapi::FAPI_RC_SUCCESS;
        uint32_t coreMask = 0x0000FFFF;
        size_t maxCores = P8_MAX_EX_PER_PROC;
        int coreCount = 0;
        uint32_t procIOMask = 0;
        uint32_t tmpImgSize = static_cast<uint32_t>(i_maxImgSize);
        bool procedure_success = false;

        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"procCustomizeSbeImg(): uid=0x%X, i_sbePnorPtr= "
                            "%p, maxS=0x%X, io_imgPtr=%p",
                            TARGETING::get_huid(i_target), i_sbePnorPtr,
                            i_maxImgSize, io_imgPtr);

        do{

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target
              l_fapiTarg(fapi::TARGET_TYPE_PROC_CHIP,
                         (const_cast<TARGETING::Target*>(i_target)));

            // NOTE: The p8_xip_customize_procedure uses SBE_IMAGE_OFFSET
            // attribute for HBB address value.  Purpsely leaving this
            // attribute as-is for now and will do the check for HBB address
            // later.

            // The p8_xip_customize() procedure tries to include as much core
            // information as possible, but is limited by SBE Image size
            // constraints.
            // First, maximize core mask for the target
            // Then loop on the procedure call, where the loop is designed to
            // remove the number of cores passed into p8_xip_customize() until
            // an image can be created successfully.

            // Maximize Core mask for this target
            err = selectBestCores(i_target,
                                  maxCores,
                                  coreMask);
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"procCustomizeSbeImg() - "
                           "selectBestCores() failed rc=0x%X. "
                           "MaxCores=0x%.8X. HUID=0x%X. Aborting "
                           "Customization of SBE Image",
                           err->reasonCode(), maxCores,
                           TARGETING::get_huid(i_target));
                break;
            }

            // setup loop parameters
            coreCount = __builtin_popcount(coreMask);
            procIOMask = coreMask;

            while( coreCount >= 0 )
            {

                FAPI_EXEC_HWP( rc_fapi,
                               p8_xip_customize,
                               l_fapiTarg,
                               i_sbePnorPtr, //image in
                               io_imgPtr,    //image out
                               tmpImgSize,
                               0,  //IPL
                               0, //HB/IPL
                               (void*)RING_BUF1_VADDR,
                               (uint32_t)FIXED_RING_BUF_SIZE,
                               (void*)RING_BUF2_VADDR,
                               (uint32_t)FIXED_RING_BUF_SIZE,
                               procIOMask);

                // Check the return code
                if ( !rc_fapi )
                {
                    // Procedure was successful
                    procedure_success = true;

                    o_actImgSize = static_cast<size_t>(tmpImgSize);

                    TRACUCOMP( g_trac_sbe, "procCustomizeSbeImg(): "
                               "p8_xip_customize success=%d, procIOMask=0x%X "
                               "o_actImgSize=0x%X, rc_fapi=0x%X",
                               procedure_success, procIOMask, o_actImgSize,
                               uint32_t(rc_fapi));

                    // exit loop
                    break;
                }
                else
                {
                    // Look for a specific return code
                    if ( static_cast<uint32_t>(rc_fapi) ==
                         fapi::RC_PROC_XIPC_OVERFLOW_BEFORE_REACHING_MINIMUM_EXS
                       )
                    {
                        // This is a specific return code from p8_xip_customize
                        // where the cores sent in couldn't fit, but possibly
                        // a different procIOMask would work

                        TRACFCOMP( g_trac_sbe,
                              ERR_MRK"procCustomizeSbeImg(): FAPI_EXEC_HWP("
                              "p8_xip_customize) returned rc=0x%X, "
                              "XIPC_OVERFLOW_BEFORE_REACHING_MINIMUM_EXS-Retry "
                              "MaxCores=0x%.8X. HUID=0x%X. coreMask=0x%.8X, "
                              "procIOMask=0x%.8X. coreCount=%d",
                              uint32_t(rc_fapi), maxCores,
                              TARGETING::get_huid(i_target),
                              coreMask, procIOMask, coreCount);

                        // Setup for next loop - update coreMask
                        err = selectBestCores(i_target,
                                              --coreCount,
                                              procIOMask);

                        if ( err )
                        {
                            TRACFCOMP(g_trac_sbe,
                                      ERR_MRK"procCustomizeSbeImg() - "
                                      "selectBestCores() failed rc=0x%X. "
                                      "coreCount=0x%.8X. HUID=0x%X. Aborting "
                                      "Customization of SBE Image",
                                      err->reasonCode(), coreCount,
                                      TARGETING::get_huid(i_target));

                            // break from while loop
                            break;
                        }

                        TRACFCOMP( g_trac_sbe, "procCustomizeSbeImg(): for "
                                   "next loop: procIOMask=0x%.8X, coreMask="
                                   "0x%.8X, coreCount=%d",
                                   procIOMask, coreMask, coreCount);

                        // No break - keep looping
                    }
                    else
                    {
                        // Unexpected return code - create err and fail
                        TRACFCOMP( g_trac_sbe,
                              ERR_MRK"procCustomizeSbeImg(): FAPI_EXEC_HWP("
                              "p8_xip_customize) failed with rc=0x%X, "
                              "MaxCores=0x%X. HUID=0x%X. coreMask=0x%.8X, "
                              "procIOMask=0x%.8X. coreCount=%d. Create "
                              "err and break loop",
                              uint32_t(rc_fapi), maxCores,
                              TARGETING::get_huid(i_target),
                              coreMask, procIOMask, coreCount);

                        err = fapiRcToErrl(rc_fapi);

                        ERRORLOG::ErrlUserDetailsTarget(i_target,
                                                        "Proc Target")
                                                       .addToLog(err);
                        err->collectTrace(SBE_COMP_NAME, 256);

                        // break from while loop
                        break;
                    }
                }
            }  // end of while loop

            if(err)
            {
                // There was a previous error, so break here
                break;
            }

            if ( procedure_success == false )
            {
                // No err, but exit from while loop before successful
                TRACFCOMP( g_trac_sbe, ERR_MRK"procCustomizeSbeImg() - "
                           "Failure to successfully complete p8_xip_customize()"
                           ". HUID=0x%X, rc=0x%X, coreCount=%d, coreMask=0x%.8X"
                           " procIOMask=0x%.8X, maxCores=0x%X",
                           TARGETING::get_huid(i_target), uint32_t(rc_fapi),
                           coreCount, coreMask, procIOMask, maxCores);
                /*@
                 * @errortype
                 * @moduleid          SBE_CUSTOMIZE_IMG
                 * @reasoncode        SBE_P8_XIP_CUSTOMIZE_UNSUCCESSFUL
                 * @userdata1[0:31]   procIOMask in/out parameter
                 * @userdata1[32:63]  rc of procedure
                 * @userdata2[0:31]   coreMask of target
                 * @userdata2[32:63]  coreCount - updated on the loops
                 * @devdesc      Unsuccessful in creating Customized SBE Image
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_CUSTOMIZE_IMG,
                                    SBE_P8_XIP_CUSTOMIZE_UNSUCCESSFUL,
                                    TWO_UINT32_TO_UINT64(procIOMask,
                                                         uint32_t(rc_fapi)),
                                    TWO_UINT32_TO_UINT64(coreMask,
                                                          coreCount));

                ErrlUserDetailsTarget(i_target
                                      ).addToLog(err);
                err->collectTrace("FAPI", 256);
                err->collectTrace(SBE_COMP_NAME, 256);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
            }

        }while(0);

        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"procCustomizeSbeImg(): io_imgPtr=%p, "
                   "o_actImgSize=0x%X, rc_fapi=0x%X, procedure_success=%d",
                   io_imgPtr, o_actImgSize, uint32_t(rc_fapi),
                   procedure_success );

        return err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t selectBestCores(TARGETING::Target* i_target,
                               size_t i_maxExs,
                               uint32_t& o_exMask)
    {
        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"selectBestCores(i_maxCores=0x%.8X)",
                   i_maxExs);

        errlHndl_t err = NULL;
        uint32_t manGuardExs = 0x00000000;
        uint32_t remainingExs = 0x00000000;
        uint32_t exCount = 0;
        uint32_t deconfigByEid = 0;

        o_exMask = 0x00000000;

        do{

            // Special case: if i_maxExs == 0 don't loop through EXs
            if (unlikely(i_maxExs == 0 ))
            {
                break;
            }

            // find all EX chiplets of the proc
            TARGETING::TargetHandleList l_exTargetList;
            TARGETING::getChildChiplets( l_exTargetList,
                                         i_target,
                                         TARGETING::TYPE_EX,
                                         false); // return all

            //Sort through cores
            for ( TargetHandleList::const_iterator
                  l_iterEX = l_exTargetList.begin();
                  l_iterEX != l_exTargetList.end();
                  ++l_iterEX )
            {
                //  make a local copy of the EX target
                const TARGETING::Target*  l_ex_target = *l_iterEX;

                if( !(l_ex_target->
                      getAttr<TARGETING::ATTR_HWAS_STATE>().present) )
                {
                    // not present, so skip and continue
                    continue;
                }


                uint8_t chipUnit = l_ex_target->
                  getAttr<TARGETING::ATTR_CHIP_UNIT>();

                if(l_ex_target->
                     getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    o_exMask |= (0x00008000 >> chipUnit);
                    exCount++;
                }
                else
                {
                    //If non-functional due to FCO or Manual gard,
                    //add it to list of exs to include if
                    //more are needed

                    deconfigByEid = l_ex_target->
                                      getAttr<TARGETING::ATTR_HWAS_STATE>().
                                      deconfiguredByEid;
                    if(
                       // FCO
                       (deconfigByEid ==
                        HWAS::DeconfigGard::DECONFIGURED_BY_FIELD_CORE_OVERRIDE)
                       || // Manual GARD
                       (deconfigByEid ==
                        HWAS::DeconfigGard::DECONFIGURED_BY_MANUAL_GARD)
                       )
                    {
                        manGuardExs |= (0x00008000 >> chipUnit);
                    }
                    // Add it to the 'remaining' list in case
                    // more are needed
                    else
                    {
                        remainingExs |= (0x00008000 >> chipUnit);
                    }

                }
            }   // end ex target loop

            if(exCount == i_maxExs)
            {
                //We've found the exact amount, break out of function
                break;
            }

            else if(exCount > i_maxExs)
            {
                //We have too many, so need to trim
                o_exMask = trimBitMask(o_exMask,
                                       i_maxExs);
                break;
            }

            else
            {
                // We need to add 'other' cores
                TRACUCOMP( g_trac_sbe,INFO_MRK"selectBestCores: non-functional "
                           "cores needed for bit mask: exCount=%d, i_maxExs=%d,"
                           " o_exMask=0x%.8X, manGuardExs=0x%.8X, "
                           "remainingExs=0x%.8X",
                           exCount, i_maxExs, o_exMask, manGuardExs,
                           remainingExs );
            }

            // Add more 'good' exs.
            manGuardExs = trimBitMask(manGuardExs,
                        i_maxExs-exCount);
            o_exMask |= manGuardExs;
            exCount = __builtin_popcount(o_exMask);
            TRACUCOMP( g_trac_sbe,INFO_MRK"selectBestCores: trimBitMask "
                       "manGuardExs=0x%.8X", manGuardExs);

            if(exCount >= i_maxExs)
            {
                //We've found enough, break out of function
                break;
            }

            // If we still need more, add 'remaining' exs
            // Get Target Service
            // System target check done earlier, so no assert check necessary
            TargetService& tS = targetService();
            TARGETING::Target* sys = NULL;
            (void) tS.getTopLevelTarget( sys );

            uint32_t min_exs = sys->getAttr<ATTR_SBE_IMAGE_MINIMUM_VALID_EXS>();
            if ( exCount < min_exs )
            {
                remainingExs = trimBitMask(remainingExs,
                                           min_exs-exCount);
                o_exMask |= remainingExs;
                TRACUCOMP( g_trac_sbe,INFO_MRK"selectBestCores: trimBitMask "
                           "remainingExs=0x%.8X, min_exs=%d",
                           remainingExs, min_exs);
            }

        }while(0);

        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"selectBestCores(o_exMask=0x%.8X)",
                   o_exMask);

        return err;
    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t getSetMVPDVersion(TARGETING::Target* i_target,
                                 opType_t i_op,
                                 mvpdSbKeyword_t& io_sb_keyword)
    {
        errlHndl_t err = NULL;
        size_t vpdSize = 0;

        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"getSetMVPDVersion(i_op=%d)", i_op );

        do{
            // Read SB Keyword which contains SBE version and dirty bit
            // information
            // Note: First read with NULL for o_buffer sets vpdSize to the
            // correct length
            err = deviceRead( i_target,
                              NULL,
                              vpdSize,
                              DEVICE_MVPD_ADDRESS( MVPD::CP00,
                                                   MVPD::SB ) );

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSetMVPDVersion() - MVPD "
                           "failure getting SB keywordw size HUID=0x%.8X",
                           TARGETING::get_huid(i_target));
                break;
            }

            if(vpdSize != MVPD_SB_RECORD_SIZE)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSetMVPDVersion() - MVPD SB "
                           "keyword wrong length HUID=0x%.8X, length=0x.2X, "
                           "expected=0x.2x",
                           TARGETING::get_huid(i_target), vpdSize,
                           MVPD_SB_RECORD_SIZE);
                /*@
                 * @errortype
                 * @moduleid     SBE_GETSET_MVPD_VERSION
                 * @reasoncode   SBE_MVPD_LEN_INVALID
                 * @userdata1    Discovered VPD Size
                 * @userdata2    Expected VPD Size
                 * @devdesc      SB Keyword in MVPD has invalid size
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_GETSET_MVPD_VERSION,
                                    SBE_MVPD_LEN_INVALID,
                                    TO_UINT64(vpdSize),
                                    TO_UINT64(MVPD_SB_RECORD_SIZE));
                ErrlUserDetailsTarget(i_target
                                      ).addToLog(err);
                err->collectTrace(SBE_COMP_NAME, 256);
                err->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_MED );

                break;
            }

            if(i_op == MVPDOP_READ)
            {
                err = deviceRead( i_target,
                                  reinterpret_cast<void*>( &io_sb_keyword ),
                                  vpdSize,
                                  DEVICE_MVPD_ADDRESS( MVPD::CP00,
                                                       MVPD::SB ) );
                if(err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"getSetMVPDVersion() - MVPD "
                               "failure reading SB keyword data HUID=0x%.8X",
                               TARGETING::get_huid(i_target));
                    break;
                }
                TRACDBIN(g_trac_sbe, "MVPD:SB:r", &io_sb_keyword, vpdSize);

            }
            else //write
            {
                TRACDBIN(g_trac_sbe, "MVPD:SB:w", &io_sb_keyword, vpdSize);

                err = deviceWrite( i_target,
                                  reinterpret_cast<void*>( &io_sb_keyword ),
                                  vpdSize,
                                  DEVICE_MVPD_ADDRESS( MVPD::CP00,
                                                       MVPD::SB ) );
                if(err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"getSetMVPDVersion() - MVPD "
                               "failure writing SB keyword data HUID=0x%.8X",
                               TARGETING::get_huid(i_target));
                    break;
                }
            }

        }while(0);

        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"getSetMVPDVersion()" );

        return err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t readPNORVersion(void*& i_pnorImgHdrPtr,
                               sbe_image_version_t& o_version)
    {
        errlHndl_t err = NULL;
        TRACDCOMP( g_trac_sbe,
                   ENTER_MRK"readPNORVersion()" );

        do{
            // @todo RTC 34080 - support Secure Boot Header

            //For Non-secure systems, version is prefixed with
            //'VERSION\0' in ASCII in the 4k header.  The official
            //protocol is to scan for VERSION, then grab the value
            //that follows.

            char* tmpPtr = static_cast<char*>(i_pnorImgHdrPtr);


            //Last reasonable offset is (Version size +
            //size of eyecatcher) bytes from end of Page.
            char* endPtr = tmpPtr +(4*KILOBYTE) -
              sizeof(sbe_image_version_t&) -
              sizeof(NONSECURE_VER_EYECATCH);

            // Increment pointer sizeof(uint64_t) because eyecatcher
            // must be 8-byte aligned
            for(; tmpPtr<endPtr; tmpPtr+=sizeof(uint64_t))
            {
                if(*(reinterpret_cast<uint64_t*>(tmpPtr)) ==
                   NONSECURE_VER_EYECATCH)
                {
                    //increment 8 more bytes and break out
                    tmpPtr+=sizeof(uint64_t);
                    break;
                }
            }

            if(tmpPtr < endPtr)
            {
                memcpy(reinterpret_cast<void*>( &o_version ),
                       tmpPtr,
                       sizeof(o_version));
            }
            else
            {

                TRACFCOMP( g_trac_sbe, ERR_MRK"readPNORVersion() - VERSION not found in SBE image in PNOR");
                /*@
                 * @errortype
                 * @moduleid     SBE_READ_PNOR_VERSION
                 * @reasoncode   SBE_VERSION_NOT_FOUND
                 * @userdata1    Not Used
                 * @userdata2    Not Used
                 * @devdesc      Image Version not found in PNOR
                 *               SBE image.
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_READ_PNOR_VERSION,
                                    SBE_VERSION_NOT_FOUND,
                                    0, 0);
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_SP_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
            }

        }while(0);

        TRACDCOMP( g_trac_sbe,
                   EXIT_MRK"readPNORVersion()" );

        return err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t getSbeBootSeeprom(TARGETING::Target* i_target,
                                 sbeSeepromSide_t& o_bootSide)
    {
        TRACFCOMP( g_trac_sbe, ENTER_MRK"getSbeBootSeeprom()" );

        errlHndl_t err = NULL;
        uint64_t scomData = 0x0;

        o_bootSide = SBE_SEEPROM0;

        do{

             TARGETING::Target * l_target=i_target;

#if defined(CONFIG_SBE_UPDATE_INDEPENDENT) || \
    defined(CONFIG_SBE_UPDATE_SIMULTANEOUS)

            // Get the Master Proc Chip Target for comparisons later
            TARGETING::Target* masterProcChipTargetHandle = NULL;
            TargetService& tS = targetService();
            err = tS.queryMasterProcChipTargetHandle(
                                                masterProcChipTargetHandle);
            if ( i_target != masterProcChipTargetHandle )
            {
                l_target=masterProcChipTargetHandle;
                TRACFCOMP( g_trac_sbe, INFO_MRK"getSbeBootSeeprom() "
                           "using master proc to read SBE_VITAL_REG: "
                           "i_target=0x%.8x, target=0x%.8x ",
                           TARGETING::get_huid(i_target),
                           TARGETING::get_huid(l_target));

            }
#endif
            size_t op_size = sizeof(scomData);
            err = deviceRead( l_target,
                              &scomData,
                              op_size,
                              DEVICE_SCOM_ADDRESS(SBE_VITAL_REG_0x0005001C) );
            if( err )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeBootSeeprom() -Error "
                           "reading SBE VITAL REG (0x%.8X) from Target :"
                           "HUID=0x%.8X",
                           SBE_VITAL_REG_0x0005001C,
                           TARGETING::get_huid(l_target));
                break;
            }
            if(scomData & SBE_BOOT_SELECT_MASK)
            {
                o_bootSide = SBE_SEEPROM1;
            }

        }while(0);

        TRACFCOMP( g_trac_sbe,
                   EXIT_MRK"getSbeBootSeeprom(): o_bootSide=0x%X (reg=0x%X)",
                   o_bootSide, scomData );

        return err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t getSbeInfoState(sbeTargetState_t& io_sbeState)
    {

        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"getSbeInfoState(): HUID=0x%.8X",
                   TARGETING::get_huid(io_sbeState.target));


        errlHndl_t err = NULL;

        do{

            /************************************************************/
            /*  Set Target Properties (target_is_master previously set) */
            /************************************************************/
            io_sbeState.ec = io_sbeState.target->getAttr<TARGETING::ATTR_EC>();


            /*******************************************/
            /*  Get PNOR SBE Version Information       */
            /*******************************************/
            void* sbePnorPtr = NULL;
            size_t sbePnorImageSize = 0;
            sbe_image_version_t tmp_pnorVersion;

            err = findSBEInPnor(io_sbeState.target,
                                sbePnorPtr,
                                sbePnorImageSize,
                                &tmp_pnorVersion);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                           "Error getting SBE Version from PNOR");
                break;
            }

            // copy tmp_pnorVersion to the main structure
            memcpy ( &io_sbeState.pnorVersion,
                     &tmp_pnorVersion,
                     sizeof(tmp_pnorVersion));


            /*******************************************/
            /*  Customize SBE Image from PNOR and      */
            /*  Calculate CRC of the image             */
            /*******************************************/
            size_t sbeImgSize = 0;
            err = procCustomizeSbeImg(io_sbeState.target,
                                sbePnorPtr,     //SBE vaddr in PNOR
                                FIXED_SEEPROM_WORK_SPACE,  //max size
                                reinterpret_cast<void*>
                                (SBE_IMG_VADDR),  //destination
                                sbeImgSize);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                           "Error from procCustomizeSbeImg()");
                break;
            }

            io_sbeState.customizedImage_size = sbeImgSize;
            io_sbeState.customizedImage_crc =
                            Util::crc32_calc(reinterpret_cast<void*>
                                             (SBE_IMG_VADDR),
                                             sbeImgSize) ;

            TRACUCOMP( g_trac_sbe, "getSbeInfoState() - procCustomizeSbeImg(): "
                       "maxSize=0x%X, actSize=0x%X, crc=0x%X",
                       FIXED_SEEPROM_WORK_SPACE, sbeImgSize,
                       io_sbeState.customizedImage_crc);



            /*******************************************/
            /*  Get MVPD SBE Version Information       */
            /*******************************************/
            err =  getSetMVPDVersion(io_sbeState.target,
                                     MVPDOP_READ,
                                     io_sbeState.mvpdSbKeyword);
            if(err)
            {
                //If MVPD is bad, commit the error and move to the next proc
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                           "Error reading version from MVPD");
                break;
            }


            // Determine Permanent Side from flag in MVPD
            if(SEEPROM_0_PERMANENT_VALUE ==
               (io_sbeState.mvpdSbKeyword.flags & PERMANENT_FLAG_MASK))
            {
                io_sbeState.permanent_seeprom_side = SBE_SEEPROM0;
            }
            else // Side 1 must be permanent
            {
                io_sbeState.permanent_seeprom_side = SBE_SEEPROM1;
            }


            /*******************************************/
            /*  Get SEEPROM A SBE Version Information  */
            /*******************************************/
            err = getSeepromSideVersion(io_sbeState.target,
                                       EEPROM::SBE_PRIMARY,
                                       io_sbeState.seeprom_0_ver,
                                       io_sbeState.seeprom_0_ver_ECC_fail);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - Error "
                           "getting SBE Information from SEEPROM A (0x%X)",
                EEPROM::SBE_PRIMARY);
                break;
            }

            TRACDBIN(g_trac_sbe, "getSbeInfoState-spA",
                     &(io_sbeState.seeprom_0_ver),
                     sizeof(sbeSeepromVersionInfo_t));

            /*******************************************/
            /*  Get SEEPROM B SBE Version Information  */
            /*******************************************/
            err = getSeepromSideVersion(io_sbeState.target,
                                        EEPROM::SBE_BACKUP,
                                        io_sbeState.seeprom_1_ver,
                                        io_sbeState.seeprom_1_ver_ECC_fail);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - Error "
                           "getting SBE Information from SEEPROM B (0x%X)",
                           EEPROM::SBE_BACKUP);
                break;
            }


            TRACDBIN(g_trac_sbe, "getSbeInfoState-spB",
                     &(io_sbeState.seeprom_1_ver),
                    sizeof(sbeSeepromVersionInfo_t));

            /***********************************************/
            /*  Determine which SEEPROM System Booted On   */
            /***********************************************/
            //Get Current (boot) Side
            sbeSeepromSide_t tmp_cur_side = SBE_SEEPROM_INVALID;
            err = getSbeBootSeeprom(io_sbeState.target, tmp_cur_side);
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - Error returned from getSbeBootSeeprom()");
                break;
            }
            io_sbeState.cur_seeprom_side = tmp_cur_side;
            if (io_sbeState.cur_seeprom_side == SBE_SEEPROM0)
            {
                io_sbeState.alt_seeprom_side = SBE_SEEPROM1;
            }
            else if ( io_sbeState.cur_seeprom_side == SBE_SEEPROM1)
            {
                io_sbeState.alt_seeprom_side = SBE_SEEPROM0;
            }
            else
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - Error: "
                           "Unexpected cur_seeprom_side value = 0x%X, ",
                           io_sbeState.cur_seeprom_side);

                 /*@
                  * @errortype
                  * @moduleid     SBE_GET_TARGET_INFO_STATE
                  * @reasoncode   SBE_INVALID_SEEPROM_SIDE
                  * @userdata1    Temporary Current Side
                  * @userdata2    SBE State Current Side
                  * @devdesc      Invalid Boot SEEPROM Side Found
                  */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_GET_TARGET_INFO_STATE,
                                    SBE_INVALID_SEEPROM_SIDE,
                                    tmp_cur_side,
                                    io_sbeState.cur_seeprom_side);
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );

                break;
            }

            TRACUCOMP( g_trac_sbe,"getSbeInfoState() - cur=0x%X, alt=0x%X",
                       io_sbeState.cur_seeprom_side,
                       io_sbeState.alt_seeprom_side);

        }while(0);

        return err;

    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t getSeepromSideVersion(TARGETING::Target* i_target,
                                     EEPROM::eeprom_chip_types_t i_seepromSide,
                                     sbeSeepromVersionInfo_t& o_info,
                                     bool& o_seeprom_ver_ECC_fail)
    {

        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"getSeepromSideVersion(): HUID=0x%.8X, side:%d",
                   TARGETING::get_huid(i_target), i_seepromSide);

        errlHndl_t err = NULL;
        PNOR::ECC::eccStatus eccStatus = PNOR::ECC::CLEAN;
        o_seeprom_ver_ECC_fail = false;

        size_t sbeInfoSize_ECC = (sizeof(sbeSeepromVersionInfo_t)*9)/8;
        size_t sbeInfoSize_ECC_aligned = ALIGN_8(sbeInfoSize_ECC);

        // Create data buffer of larger size
        // NOTE:  EEPROM read will fill in smaller, unaligned size
        uint8_t * tmp_data_ECC = static_cast<uint8_t*>(
        malloc(sbeInfoSize_ECC_aligned));

        do{

            /*******************************************/
            /*  Read SBE Version SBE Version Information       */
            /*******************************************/

            // Clear Buffer
            memset( tmp_data_ECC, 0, sbeInfoSize_ECC_aligned );

            //Read SBE Versions
            err = deviceRead( i_target,
                              tmp_data_ECC,
                              sbeInfoSize_ECC,
                              DEVICE_EEPROM_ADDRESS(
                                            i_seepromSide,
                                            SBE_VERSION_SEEPROM_ADDRESS));

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromSideVersion() - Error "
                "reading SBE Version from Seeprom 0x%X, HUID=0x%.8X",
                i_seepromSide, TARGETING::get_huid(i_target));
                break;
            }

            TRACDBIN(g_trac_sbe,
                     "getSeepromSideVersion()- tmp_data_ECC (not-aligned)",
                     tmp_data_ECC,
                     sbeInfoSize_ECC);

            TRACDBIN(g_trac_sbe,
                     "getSeepromSideVersion()- tmp_data_ECC (aligned)",
                     tmp_data_ECC,
                     sbeInfoSize_ECC_aligned);


            // Clear destination
            memset( &o_info, 0, sizeof(o_info) );


            // Remove ECC
            eccStatus = PNOR::ECC::removeECC(
                                         tmp_data_ECC,
                                         reinterpret_cast<uint8_t*>(&o_info),
                                         sizeof(o_info));

            TRACUCOMP( g_trac_sbe, "getSeepromSideVersion(): eccStatus=%d, "
                       "sizeof o_info=%d, sI_ECC=%d, sI_ECC_aligned=%d",
                       eccStatus, sizeof(o_info), sbeInfoSize_ECC,
                       sbeInfoSize_ECC_aligned);

            // Handle Uncorrectable ECC - no error log:
            // clear data and set o_seeprom_ver_ECC_fail=true
            // -- unless SIM version found:  than just ignore
            if ( (eccStatus == PNOR::ECC::UNCORRECTABLE) &&
                 (o_info.struct_version != SBE_SEEPROM_STRUCT_SIMICS_VERSION) )
            {

                TRACFCOMP( g_trac_sbe,ERR_MRK"getSeepromSideVersion() - ECC "
                           "ERROR: Handled. eccStatus=%d, side=%d, sizeof "
                           "o_info=%d, sI_ECC=%d, sI_ECC_aligned=%d",
                           eccStatus, i_seepromSide, sizeof(o_info),
                           sbeInfoSize_ECC, sbeInfoSize_ECC_aligned);

                memset( &o_info, 0, sizeof(o_info));
                o_seeprom_ver_ECC_fail = true;

                TRACUCOMP( g_trac_sbe, "getSeepromSideVersion(): clearing out "
                "version data (o_info) for side %d and returning "
                "o_seeprom_ver_ECC_fail as true (%d)",
                i_seepromSide, o_seeprom_ver_ECC_fail);
            }

            TRACDBIN(g_trac_sbe,
                     "getSeepromSideVersion: data (no ECC)",
                     &o_info,
                     sizeof(o_info));

        }while(0);

        // Free allocated memory
        free(tmp_data_ECC);


        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"getSeepromSideVersion: o_seeprom_ver_ECC_fail=%d",
                   o_seeprom_ver_ECC_fail );

        return err;
    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t updateSeepromSide(sbeTargetState_t& io_sbeState)
    {
        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"updateSeepromSide(): HUID=0x%.8X, side=%d",
                   TARGETING::get_huid(io_sbeState.target),
                   io_sbeState.seeprom_side_to_update);

        errlHndl_t err = NULL;
        int64_t rc = 0;

        int64_t rc_readBack_ECC_memcmp = 0;
        PNOR::ECC::eccStatus eccStatus = PNOR::ECC::CLEAN;

        // This struct is always 8-byte aligned
        size_t sbeInfoSize = sizeof(sbeSeepromVersionInfo_t);
        size_t sbeInfoSize_ECC = (sbeInfoSize*9)/8;


        // Buffers for reading/writing SBE Version Information
        uint8_t * sbeInfo_data = static_cast<uint8_t*>(
                                                malloc(sbeInfoSize));

        uint8_t * sbeInfo_data_ECC = static_cast<uint8_t*>(
                                                malloc(sbeInfoSize_ECC));

        uint8_t * sbeInfo_data_readBack = static_cast<uint8_t*>(
                                                malloc(sbeInfoSize));

        uint8_t * sbeInfo_data_ECC_readBack = static_cast<uint8_t*>(
                                                malloc(sbeInfoSize_ECC));

        do{


            /*************************************************************/
            /*  Write Invalid SBE Version Information                    */
            /*  -- This is done to prevent confusion if there is a fail  */
            /*     when updating the Version or Image after this         */
            /*************************************************************/

            // Create Invalid Version struct (which is always 8-byte aligned)
            for ( uint8_t i = 0; i < (sbeInfoSize)/8; i++ )
            {
                memcpy(&sbeInfo_data[i*8],
                       &SBE_SEEPROM_STRUCT_INVALID,
                       sizeof(uint64_t));
            }

            // Inject ECC to Data
            memset( sbeInfo_data_ECC, 0, sbeInfoSize_ECC);
            PNOR::ECC::injectECC(sbeInfo_data, sbeInfoSize, sbeInfo_data_ECC);

            TRACDBIN( g_trac_sbe, "updateSeepromSide: Invalid Info",
                      sbeInfo_data, sbeInfoSize);
            TRACDBIN( g_trac_sbe, "updateSeepromSide: Invalid Info ECC",
                      sbeInfo_data_ECC, sbeInfoSize_ECC);

            err = deviceWrite( io_sbeState.target,
                               sbeInfo_data_ECC,
                               sbeInfoSize_ECC,
                               DEVICE_EEPROM_ADDRESS(
                                             io_sbeState.seeprom_side_to_update,
                                             SBE_VERSION_SEEPROM_ADDRESS));
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - Error "
                           "Writing SBE Version Info: HUID=0x%.8X, side=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.seeprom_side_to_update);
                break;
            }

            // In an effort to avoid an infinite loop of updates, if there
            // was an ECC error when reading this SBE Version Information
            // while collecting data, read back this data to ensure there
            // isn't a permanent ECC error on the SEEPROM
            if ( io_sbeState.new_readBack_check == true )
            {
                // Read Back Version Information
                err = deviceRead( io_sbeState.target,
                                  sbeInfo_data_ECC_readBack,
                                  sbeInfoSize_ECC,
                                  DEVICE_EEPROM_ADDRESS(
                                             io_sbeState.seeprom_side_to_update,
                                             SBE_VERSION_SEEPROM_ADDRESS));

                if(err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - Error "
                               "Reading Back SBE Version Info: HUID=0x%.8X, "
                               "side=%d",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.seeprom_side_to_update);
                    break;
                }

                // Compare ECC data
                rc_readBack_ECC_memcmp = memcmp( sbeInfo_data_ECC,
                                                 sbeInfo_data_ECC_readBack,
                                                 sbeInfoSize_ECC);

                // Remove ECC
                eccStatus = PNOR::ECC::removeECC( sbeInfo_data_ECC_readBack,
                                                  sbeInfo_data_readBack,
                                                  sbeInfoSize);

                TRACUCOMP( g_trac_sbe, "updateSeepromSide(): eccStatus=%d, "
                           "sizeof sI=%d, sI_ECC=%d, rc_ECC=%d",
                           eccStatus, sbeInfoSize, sbeInfoSize_ECC,
                           rc_readBack_ECC_memcmp);

                // Fail if uncorrectable ECC or any data miscompare
                if (  ( eccStatus == PNOR::ECC::UNCORRECTABLE ) ||
                      ( rc_readBack_ECC_memcmp != 0 )
                   )
                {

                    // There is an ECC issue with this SEEPROM

                    TRACFCOMP( g_trac_sbe,ERR_MRK"updateSeepromSide() - ECC "
                               "ERROR or Data Miscimpare On SBE Version Read "
                               "Back: eccStatus=%d, rc_ECC=%d,  "
                               "sI=%d, sI_ECC=%d, HUID=0x%.8X, side=%d",
                               eccStatus, rc_readBack_ECC_memcmp,
                               sbeInfoSize, sbeInfoSize_ECC,
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.seeprom_side_to_update);

                    TRACFBIN( g_trac_sbe, "updateSeepromSide: readback_wECC",
                              sbeInfo_data_ECC_readBack, sbeInfoSize_ECC);

                    /*@
                     * @errortype
                     * @moduleid     SBE_GET_SEEPROM_INFO
                     * @reasoncode   SBE_ECC_FAIL
                     * @userdata1[0:15]     ECC Status
                     * @userdata1[16:31]    SEEPROM Side
                     * @userdata1[32:47]    RC on Data Compare with ECC
                     * @userdata1[48:63]    <unused>
                     * @userdata2[0:31]     Size - No Ecc
                     * @userdata2[32:63]    Size - ECC
                     * @devdesc      ECC or Data Miscompare Fail Reading Back
                     *               SBE Verion Information
                     */
                    err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                        SBE_UPDATE_SEEPROMS,
                                        SBE_ECC_FAIL,
                                        FOUR_UINT16_TO_UINT64(
                                             eccStatus,
                                             io_sbeState.seeprom_side_to_update,
                                             rc_readBack_ECC_memcmp,
                                             0x0),
                                        TWO_UINT32_TO_UINT64(sbeInfoSize,
                                                             sbeInfoSize_ECC));

                    err->collectTrace(SBE_COMP_NAME);

                    err->addPartCallout(
                                         io_sbeState.target,
                                         HWAS::SBE_SEEPROM_PART_TYPE,
                                         HWAS::SRCI_PRIORITY_HIGH,
                                         HWAS::NO_DECONFIG,
                                         HWAS::GARD_NULL );


                    ErrlUserDetailsTarget(io_sbeState.target).addToLog(err);

                    break;
                }

            }

            /*******************************************/
            /*  Update SBE with Customized Image       */
            /*******************************************/
            // The Customized Image For This Target Still Resides In
            // The SBE Update VMM Space: SBE_IMG_VADDR = VMM_VADDR_SBE_UPDATE

#ifdef CONFIG_SBE_UPDATE_INDEPENDENT
            // Ensure HBB address value in the customized image is correct
            // for this side
            bool imageWasUpdated=false;
            err = resolveImageHBBaddr ( io_sbeState.target,
                                        reinterpret_cast<void*>(SBE_IMG_VADDR),
                                        ((io_sbeState.seeprom_side_to_update ==
                                         EEPROM::SBE_PRIMARY ) ?
                                                 SBE_SEEPROM0 :
                                                 SBE_SEEPROM1  ),
                                        PNOR::WORKING,
                                        imageWasUpdated );

            if (imageWasUpdated == true )
            {
                TRACUCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - "
                           "HBB Address's MMIO Offset Updated in Image");
            }

#endif

            // Inject ECC
            // clear out back half of page block to use as temp space
            // for ECC injected SBE Image.
            rc = mm_remove_pages(RELEASE,
                                 reinterpret_cast<void*>
                                 (SBE_ECC_IMG_VADDR),
                                 SBE_ECC_IMG_MAX_SIZE);
            if( rc )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - Error "
                           "from mm_remove_pages : rc=%d,  HUID=0x%.8X.",
                           rc, TARGETING::get_huid(io_sbeState.target) );
                /*@
                 * @errortype
                 * @moduleid     SBE_UPDATE_SEEPROMS
                 * @reasoncode   SBE_REMOVE_PAGES_FOR_EC
                 * @userdata1    Requested Address
                 * @userdata2    rc from mm_remove_pages
                 * @devdesc      updateProcessorSbeSeeproms> mm_remove_pages
                 *               RELEASE failed
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_UPDATE_SEEPROMS,
                                    SBE_REMOVE_PAGES_FOR_EC,
                                    TO_UINT64(SBE_ECC_IMG_VADDR),
                                    TO_UINT64(rc));
                //Target isn't directly related to fail, but could be useful
                // to see how far we got before failing.
                ErrlUserDetailsTarget(io_sbeState.target
                                      ).addToLog(err);
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
                break;
            }


            //align size, calculate ECC size
            size_t sbeImgSize = ALIGN_8(io_sbeState.customizedImage_size);
            size_t sbeEccImgSize = static_cast<size_t>(sbeImgSize*9/8);


            assert(sbeEccImgSize <= SBE_ECC_IMG_MAX_SIZE,
                   "updateSeepromSide() SBE Image with ECC too large");

            TRACUCOMP( g_trac_sbe, INFO_MRK"updateSeepromSide(): "
                       "SBE_VADDR=0x%.16X, ECC_VADDR=0x%.16X, size=0x%.8X, "
                       "eccSize=0x%.8X",
                       SBE_IMG_VADDR,
                       SBE_ECC_IMG_VADDR,
                       sbeImgSize,
                       sbeEccImgSize );

            PNOR::ECC::injectECC(reinterpret_cast<uint8_t*>(SBE_IMG_VADDR),
                                 sbeImgSize,
                                 reinterpret_cast<uint8_t*>
                                 (SBE_ECC_IMG_VADDR));

            TRACDBIN(g_trac_sbe,"updateSeepromSide()-start of IMG - no ECC",
                     reinterpret_cast<void*>(SBE_IMG_VADDR), 0x80);
            TRACDBIN(g_trac_sbe,"updateSeepromSide()-start of IMG - ECC",
                     reinterpret_cast<void*>(SBE_ECC_IMG_VADDR), 0x80);


            //Write new data to seeprom
            TRACFCOMP( g_trac_sbe, INFO_MRK"updateSeepromSide(): Write New "
                       "SBE Image for Target 0x%X to Seeprom %d",
                       TARGETING::get_huid(io_sbeState.target),
                       io_sbeState.seeprom_side_to_update );

            //Write image to indicated side
            err = deviceWrite(io_sbeState.target,
                              reinterpret_cast<void*>
                              (SBE_ECC_IMG_VADDR),
                              sbeEccImgSize,
                              DEVICE_EEPROM_ADDRESS(
                                            io_sbeState.seeprom_side_to_update,
                                            SBE_IMAGE_SEEPROM_ADDRESS));

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - Error "
                           "writing new SBE image to size=%d. HUID=0x%.8X."
                           "SBE_VADDR=0x%.16X, ECC_VADDR=0x%.16X, size=0x%.8X, "
                           "eccSize=0x%.8X, EEPROM offset=0x%X",
                           io_sbeState.seeprom_side_to_update,
                           TARGETING::get_huid(io_sbeState.target),
                           SBE_IMG_VADDR, SBE_ECC_IMG_VADDR, sbeImgSize,
                           sbeEccImgSize, SBE_IMAGE_SEEPROM_ADDRESS);
                break;
            }


            /*******************************************/
            /*  Update SBE Version Information         */
            /*******************************************/

            // The new version has already been created
            memcpy(sbeInfo_data, &io_sbeState.new_seeprom_ver, sbeInfoSize);

            // Inject ECC to Data
            memset( sbeInfo_data_ECC, 0, sbeInfoSize_ECC);
            PNOR::ECC::injectECC(sbeInfo_data, sbeInfoSize, sbeInfo_data_ECC);

            TRACDBIN( g_trac_sbe, "updateSeepromSide: Info",
                      sbeInfo_data, sbeInfoSize);
            TRACDBIN( g_trac_sbe, "updateSeepromSide: Info ECC",
                      sbeInfo_data_ECC, sbeInfoSize_ECC);

            err = deviceWrite( io_sbeState.target,
                               sbeInfo_data_ECC,
                               sbeInfoSize_ECC,
                               DEVICE_EEPROM_ADDRESS(
                                             io_sbeState.seeprom_side_to_update,
                                             SBE_VERSION_SEEPROM_ADDRESS));
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - Error "
                           "Writing SBE Version Info: HUID=0x%.8X, side=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.seeprom_side_to_update);
                break;
            }

            // Successful update if we get here, so update internal code
            // structure with the new version information
            memcpy( io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY
                    ? &io_sbeState.seeprom_0_ver : &io_sbeState.seeprom_1_ver,
                    &io_sbeState.new_seeprom_ver,
                    sbeInfoSize );

        }while(0);

        // Free allocated memory
        free( sbeInfo_data );
        free( sbeInfo_data_ECC);
        free( sbeInfo_data_readBack );
        free( sbeInfo_data_ECC_readBack );

#ifdef CONFIG_SBE_UPDATE_SIMULTANEOUS
        // If no error, recursively call this function for the other SEEPROM
        if ( ( err == NULL ) &&
             ( io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY ) )
        {
            io_sbeState.seeprom_side_to_update = EEPROM::SBE_BACKUP;
            TRACFCOMP( g_trac_sbe,
                       "updateSeepromSide(): Recursively calling itself: "
                       "HUID=0x%.8X, side=%d",
                       TARGETING::get_huid(io_sbeState.target),
                       io_sbeState.seeprom_side_to_update);

            err = updateSeepromSide(io_sbeState);
        }
#endif

        return err;


    }



/////////////////////////////////////////////////////////////////////
    errlHndl_t getTargetUpdateActions(sbeTargetState_t& io_sbeState)
    {
        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"getTargetUpdateActions(): HUID=0x%.8X",
                   TARGETING::get_huid(io_sbeState.target));

        errlHndl_t err = NULL;

        bool seeprom_0_isDirty =    false;
        bool seeprom_1_isDirty =    false;
        bool current_side_isDirty = false;
        bool alt_side_isDirty     = false;

        bool pnor_check_dirty     = false;
        bool crc_check_dirty      = false;
        bool isSimics_check       = false;

        do{

            /**************************************************************/
            /*  Compare SEEPROM 0 with PNOR and Customized Image CRC --   */
            /*  -- dirty or clean?                                        */
            /**************************************************************/
            // Check PNOR and SEEPROM 0 Version
            if ( 0 != memcmp(&(io_sbeState.pnorVersion),
                             &(io_sbeState.seeprom_0_ver.image_version),
                             SBE_IMAGE_VERSION_SIZE) )
            {
                pnor_check_dirty = true;
            }

            // Check CRC and SEEPROM 0 CRC
            if ( io_sbeState.customizedImage_crc !=
                 io_sbeState.seeprom_0_ver.data_crc )
            {
                crc_check_dirty = true;
            }

            // Check if in simics
            if ( ( io_sbeState.seeprom_0_ver.struct_version ==
                   SBE_SEEPROM_STRUCT_SIMICS_VERSION )
                 && ( Util::isSimicsRunning() )
               )
            {
                isSimics_check = true;
            }

            if ( (pnor_check_dirty || crc_check_dirty )
                 && !isSimics_check )
            {
                seeprom_0_isDirty = true;
                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: Seeprom0 "
                           "dirty: pnor=%d, crc=%d (custom=0x%X/s0=0x%X), "
                           "isSimics=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           pnor_check_dirty, crc_check_dirty,
                           io_sbeState.customizedImage_crc,
                           io_sbeState.seeprom_0_ver.data_crc, isSimics_check);
            }

            /**************************************************************/
            /*  Compare SEEPROM 1 with PNOR and Customized Image CRC --   */
            /*  -- dirty or clean?                                        */
            /**************************************************************/
            // reset dirty variables
            pnor_check_dirty     = false;
            crc_check_dirty      = false;
            isSimics_check       = false;

            // Check PNOR and SEEPROM 1 Version
            if ( 0 != memcmp(&(io_sbeState.pnorVersion),
                             &(io_sbeState.seeprom_1_ver.image_version),
                             SBE_IMAGE_VERSION_SIZE) )
            {
                pnor_check_dirty = true;
            }

            // Check CRC and SEEPROM 1 CRC
            if ( io_sbeState.customizedImage_crc !=
                 io_sbeState.seeprom_1_ver.data_crc )
            {
                crc_check_dirty = true;
            }

            // Check if in simics
            if ( ( io_sbeState.seeprom_1_ver.struct_version ==
                   SBE_SEEPROM_STRUCT_SIMICS_VERSION )
                 && ( Util::isSimicsRunning() )
               )
            {
                isSimics_check = true;
            }

            if ( (pnor_check_dirty || crc_check_dirty )
                 && !isSimics_check )
            {
                seeprom_1_isDirty = true;
                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: Seeprom1 "
                           "dirty: pnor=%d, crc=%d (custom=0x%X/s1=0x%X), "
                           "isSimics=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           pnor_check_dirty, crc_check_dirty,
                           io_sbeState.customizedImage_crc,
                           io_sbeState.seeprom_1_ver.data_crc, isSimics_check);
            }


            // Extra information for unit testing
            if ( seeprom_0_isDirty || seeprom_1_isDirty )
            {
                TRACFBIN( g_trac_sbe,
                          "PNOR Version",
                          &(io_sbeState.pnorVersion),
                          16 ) ;

                TRACFBIN( g_trac_sbe,
                          "Seeprom0: Image Version",
                          &(io_sbeState.seeprom_0_ver.image_version),
                          16 ) ;

                TRACFBIN( g_trac_sbe,
                          "Seeprom1: Image Version",
                          &(io_sbeState.seeprom_1_ver.image_version),
                          16 ) ;

                TRACFBIN( g_trac_sbe,
                          "MVPD SB",
                          &(io_sbeState.mvpdSbKeyword),
                          sizeof(mvpdSbKeyword_t));
            }


            /**************************************************************/
            /*  Determine what side to update                             */
            /**************************************************************/
            // Set cur and alt isDirty values
            if( io_sbeState.cur_seeprom_side == SBE_SEEPROM0 )
            {
                current_side_isDirty = seeprom_0_isDirty;
                alt_side_isDirty     = seeprom_1_isDirty;
            }
            else
            {
                current_side_isDirty = seeprom_1_isDirty;
                alt_side_isDirty     = seeprom_0_isDirty;
            }

            // Set system_situation - bits defined in sbe_update.H
            uint8_t system_situation = 0x00;

            // Bit 0: current_side is permanent (0) or temp (1)
            // -- defaulted to 0 (cur=perm) above
            if ( io_sbeState.cur_seeprom_side !=
                 io_sbeState.permanent_seeprom_side )
            {
               system_situation |= SITUATION_CUR_IS_TEMP;
            }

            // Bit 1:  current_side clean (0) or dirty (1)
            // -- defaulted to 0 (clean) above
            if ( current_side_isDirty )
            {
                system_situation |= SITUATION_CUR_IS_DIRTY;
            }

            // Bit 2:  alt_side is clean (0) or dirty (1)
            if ( alt_side_isDirty )
            {
                system_situation |= SITUATION_ALT_IS_DIRTY;
            }


            // Call function to update actions
            err = decisionTreeForUpdates(io_sbeState, system_situation);

            if ( err ) { break; }

            TRACUCOMP( g_trac_sbe, "getTargetUpdateActions() - system_situation"
                       "= 0x%.2X, actions=0x%.8X, Update EEPROM=0x%X",
                       system_situation,
                       io_sbeState.update_actions,
                       io_sbeState.seeprom_side_to_update);

            /**************************************************************/
            /*  Setup new SBE Image Version Info, if necessary            */
            /**************************************************************/
            if ( io_sbeState.update_actions & UPDATE_SBE )
            {
                memset(&(io_sbeState.new_seeprom_ver),
                       0x0,
                       sizeof(sbeSeepromVersionInfo_t));


                io_sbeState.new_seeprom_ver.struct_version =
                                            SBE_SEEPROM_STRUCT_VERSION;

                memcpy( &(io_sbeState.new_seeprom_ver.image_version),
                        &(io_sbeState.pnorVersion),
                        SBE_IMAGE_VERSION_SIZE);

                memcpy( &(io_sbeState.new_seeprom_ver.data_crc),
                        &(io_sbeState.customizedImage_crc),
                        sizeof(io_sbeState.new_seeprom_ver.data_crc));

                // If there was an ECC fail on either SEEPROM, do a read-back
                // Check when writing this information to the SEEPROM
                io_sbeState.new_readBack_check = (
                                io_sbeState.seeprom_0_ver_ECC_fail ||
                                io_sbeState.seeprom_1_ver_ECC_fail);

                TRACDBIN( g_trac_sbe,
                          "getTargetUpdateActions() - New SBE Version Info",
                          &(io_sbeState.new_seeprom_ver),
                          sizeof(sbeSeepromVersionInfo_t));
            }

            /**************************************************************/
            /*  Update MVPD Struct to write back, if necessary            */
            /**************************************************************/
            if ( io_sbeState.update_actions & UPDATE_MVPD )
            {
                // Note: mvpdSbKeyword.flags updated in decisionTreeForUpdates()

                if ( io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY )
                {
                    memcpy(&(io_sbeState.mvpdSbKeyword.seeprom_0_data_crc),
                           &(io_sbeState.customizedImage_crc),
                          sizeof(io_sbeState.mvpdSbKeyword.seeprom_0_data_crc));

                    memcpy(&(io_sbeState.mvpdSbKeyword.seeprom_0_short_version),
                           &(io_sbeState.pnorVersion),
                           SBE_MVPD_SHORT_IMAGE_VERSION_SIZE);
                }
                else // EEPROM::SBE_Backup
                {
                    memcpy(&(io_sbeState.mvpdSbKeyword.seeprom_1_data_crc),
                           &(io_sbeState.customizedImage_crc),
                          sizeof(io_sbeState.mvpdSbKeyword.seeprom_1_data_crc));

                    memcpy(&(io_sbeState.mvpdSbKeyword.seeprom_1_short_version),
                           &(io_sbeState.pnorVersion),
                           SBE_MVPD_SHORT_IMAGE_VERSION_SIZE);
                }
            }


        }while(0);

        return err;


    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t decisionTreeForUpdates(sbeTargetState_t& io_sbeState,
                                uint8_t i_system_situation)
    {
        errlHndl_t err = NULL;

        uint32_t l_actions           = CLEAR_ACTIONS;
        io_sbeState.update_actions   = CLEAR_ACTIONS;
        io_sbeState.seeprom_side_to_update = EEPROM::LAST_CHIP_TYPE;

        do{

            // To be safe, we're only look at the bits defined in sbe_update.H
            i_system_situation &= SITUATION_ALL_BITS_MASK;

#ifdef CONFIG_SBE_UPDATE_INDEPENDENT

            // The 2 SBE SEEPROMs are independent of each other
            // Determine if PNOR is 1- or 2-sided and if the current
            // Seeprom is pointing at PNOR's GOLDEN side

            PNOR::SideId tmp_side = PNOR::WORKING;
            PNOR::SideInfo_t pnor_side_info;
            err = PNOR::getSideInfo (tmp_side, pnor_side_info);
            if ( err )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK
                           "SBE Update() - Error returned from "
                           "PNOR::getSideInfo() rc=0x%.4X, Target UID=0x%X",
                           err->reasonCode(),
                           TARGETING::get_huid(io_sbeState.target));
                break;
            }

            TRACUCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: PNOR Info: "
                       "side-%c, sideId=0x%X, isGolden=%d, hasOtherSide=%d",
                       TARGETING::get_huid(io_sbeState.target),
                       pnor_side_info.side, pnor_side_info.id,
                       pnor_side_info.isGolden, pnor_side_info.hasOtherSide);

            if ( pnor_side_info.isGolden == true )
            {
                // If true, nothing to do (covered in istep 6 function)
                l_actions = CLEAR_ACTIONS;

                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                           "Booting READ_ONLY SEEPROM pointing at PNOR's "
                           "GOLDEN side. No updates for cur side=%d. Continue "
                            "IPL. (sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.cur_seeprom_side,
                           i_system_situation, l_actions,
                           io_sbeState.mvpdSbKeyword.flags);
                break;
            }

            else if (  ( pnor_side_info.hasOtherSide == false ) &&
                       ( io_sbeState.cur_seeprom_side == READ_ONLY_SEEPROM ) )
            {
                // Even though current seeprom is not pointing at PNOR's
                // GOLDEN side, treat like READ_ONLY if booting from READ_ONLY
                // seeprom and and PNOR does not have another side - No Update
                // (ie, Palmetto configuration)
                l_actions = CLEAR_ACTIONS;

                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                           "Treating cur like READ_ONLY SBE SEEPROM. "
                           "No updates for cur side=%d. Continue IPL. "
                           "(sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.cur_seeprom_side,
                           i_system_situation, l_actions,
                           io_sbeState.mvpdSbKeyword.flags);
                break;
            }
            else // proceed to update this side
            {
                // proceed to update this side
                TRACUCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                           "NOT Booting READ_ONLY SEEPROM. Check for update "
                           "on cur side=%d ",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.cur_seeprom_side)
            }


            // Check for clean vs. dirty only on cur side
            if ( i_system_situation & SITUATION_CUR_IS_DIRTY )
            {
                //  Update cur side and re-ipl
                l_actions |= IPL_RESTART;
                l_actions |= DO_UPDATE;
                l_actions |= UPDATE_SBE;
                l_actions |= UPDATE_MVPD; // even though flags byte not updated

                // Set Update side to cur
                io_sbeState.seeprom_side_to_update =
                                ( io_sbeState.cur_seeprom_side ==
                                              SBE_SEEPROM0 )
                                  ? EEPROM::SBE_PRIMARY : EEPROM::SBE_BACKUP;

                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                           "cur side (%d) dirty. Update cur. Re-IPL. "
                           "(sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.cur_seeprom_side,
                           i_system_situation, l_actions,
                           io_sbeState.mvpdSbKeyword.flags);
            }
            else
            {
                // Cur side clean - No Updates - Continue IPL
                l_actions = CLEAR_ACTIONS;

                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                           "cur side (%d) clean-no updates. "
                           "Continue IPL. (sit=0x%.2X, act=0x%.8X)",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.cur_seeprom_side,
                           i_system_situation, l_actions);
            }

#elif CONFIG_SBE_UPDATE_SIMULTANEOUS
            // Updates both SEEPROMs if either side is dirty
            if ( ( i_system_situation & SITUATION_CUR_IS_DIRTY ) ||
                 ( i_system_situation & SITUATION_ALT_IS_DIRTY )  )
            {
                    // At least one of the sides is dirty
                    // Update both sides and re-IPL
                    // Update MVPD flag: make cur=perm (because we know it
                    //  works a bit)

                    l_actions |= IPL_RESTART;
                    l_actions |= DO_UPDATE;
                    l_actions |= UPDATE_MVPD;
                    l_actions |= UPDATE_SBE;

                    // Set update side to Primary here, but both sides
                    // will be updated
                    io_sbeState.seeprom_side_to_update = EEPROM::SBE_PRIMARY;

                    // Update MVPD PERMANENT flag: make cur=perm
                    ( io_sbeState.cur_seeprom_side == SBE_SEEPROM0 ) ?
                         // clear bit 0
                         io_sbeState.mvpdSbKeyword.flags &= ~PERMANENT_FLAG_MASK
                         : //set bit 0
                         io_sbeState.mvpdSbKeyword.flags |= PERMANENT_FLAG_MASK;

                    // Update MVPD RE-IPL SEEPROM flag: re-IPL on ALT:
                    ( io_sbeState.alt_seeprom_side == SBE_SEEPROM0 ) ?
                         // clear bit 1
                         io_sbeState.mvpdSbKeyword.flags &= ~REIPL_SEEPROM_MASK
                         : //set bit 1
                         io_sbeState.mvpdSbKeyword.flags |= REIPL_SEEPROM_MASK;


                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "At least one side dirty. cur side=%d. Update "
                               "alt. Re-IPL. Update MVPD flag "
                               "(sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions,
                               io_sbeState.mvpdSbKeyword.flags);

            }
            else
            {
                    // Both sides are clean - no updates
                    // Continue IPL
                    l_actions = CLEAR_ACTIONS;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "Both sides clean-no updates. cur side=%d. "
                               "Continue IPL. (sit=0x%.2X, act=0x%.8X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions);


            }

#elif CONFIG_SBE_UPDATE_SEQUENTIAL
            // Updating the SEEPROMs 1-at-a-time
            switch ( i_system_situation )
            {

            ///////////////////////////////////////////////////////////////////
                case ( SITUATION_CUR_IS_TEMP  |
                       SITUATION_CUR_IS_DIRTY |
                       SITUATION_ALT_IS_DIRTY  ) :

                    // 0xE0: cur=temp, cur=dirty, alt=dirty
                    // Treat like 0xC0
                    // not sure why we booted off of temp

            ///////////////////////////////////////////////////////////////////
                case ( SITUATION_CUR_IS_TEMP  |
                       SITUATION_CUR_IS_DIRTY |
                       SITUATION_ALT_IS_CLEAN  ) :


                    // 0xC0: cur=temp, cur=dirty, alt=clean
                    // Bad path: we shouldn't be booting to dirty side
                    // Update Alt and re-IPL to it
                    // Update MVPD flag: make cur=perm (because we know it
                    //  works a bit)

                    l_actions |= IPL_RESTART;
                    l_actions |= DO_UPDATE;
                    l_actions |= UPDATE_MVPD;
                    l_actions |= UPDATE_SBE;

                    // Set Update side to alt
                    io_sbeState.seeprom_side_to_update =
                                ( io_sbeState.alt_seeprom_side ==
                                              SBE_SEEPROM0 )
                                  ? EEPROM::SBE_PRIMARY : EEPROM::SBE_BACKUP ;

                    // Update MVPD PERMANENT flag: make cur=perm
                    ( io_sbeState.cur_seeprom_side == SBE_SEEPROM0 ) ?
                         // clear bit 0
                         io_sbeState.mvpdSbKeyword.flags &= ~PERMANENT_FLAG_MASK
                         : //set bit 0
                         io_sbeState.mvpdSbKeyword.flags |= PERMANENT_FLAG_MASK;

                    // Update MVPD RE-IPL SEEPROM flag: re-IPL on ALT:
                    ( io_sbeState.alt_seeprom_side == SBE_SEEPROM0 ) ?
                         // clear bit 1
                         io_sbeState.mvpdSbKeyword.flags &= ~REIPL_SEEPROM_MASK
                         : //set bit 1
                         io_sbeState.mvpdSbKeyword.flags |= REIPL_SEEPROM_MASK;


                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "cur=temp/dirty(%d). Update alt. Re-IPL. "
                               "Update MVPD flag "
                               "(sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions,
                               io_sbeState.mvpdSbKeyword.flags);


                    break;

            ///////////////////////////////////////////////////////////////////
                case ( SITUATION_CUR_IS_TEMP  |
                       SITUATION_CUR_IS_CLEAN |
                       SITUATION_ALT_IS_DIRTY  ) :

                    // 0xA0: cur=temp, cur=clean, alt=dirty
                    // Common 2nd step of Code Update path
                    // Update Alt and Continue IPL
                    // Update MVPD flag: make cur=perm

                    l_actions |= DO_UPDATE;
                    l_actions |= UPDATE_MVPD;
                    l_actions |= UPDATE_SBE;

                    // Set Update side to alt
                    io_sbeState.seeprom_side_to_update =
                                ( io_sbeState.alt_seeprom_side ==
                                              SBE_SEEPROM0 )
                                  ? EEPROM::SBE_PRIMARY : EEPROM::SBE_BACKUP ;


                    // MVPD flag Update
                    // Update MVPD flag make cur=perm
                    ( io_sbeState.cur_seeprom_side == SBE_SEEPROM0 ) ?
                         // clear bit 0
                         io_sbeState.mvpdSbKeyword.flags &= ~PERMANENT_FLAG_MASK
                         : // set bit 0
                         io_sbeState.mvpdSbKeyword.flags |= PERMANENT_FLAG_MASK;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "cur=temp/clean(%d), alt=dirty. "
                               "Update alt. Continue IPL. Update MVPD flag."
                               "(sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions,
                               io_sbeState.mvpdSbKeyword.flags);

                    break;


            ///////////////////////////////////////////////////////////////////
                case ( SITUATION_CUR_IS_TEMP  |
                       SITUATION_CUR_IS_CLEAN |
                       SITUATION_ALT_IS_CLEAN  ) :

                    // 0x80: cur=temp, cur=clean, alt=clean
                    // Both sides are clean,
                    // Not sure why cur=temp, but do nothing

                    l_actions = CLEAR_ACTIONS;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "Both sides clean-no updates. cur was temp(%d). "
                               "Continue IPL. (sit=0x%.2X, act=0x%.8X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions);

                    break;


            ///////////////////////////////////////////////////////////////////
                case ( SITUATION_CUR_IS_PERM  |
                       SITUATION_CUR_IS_DIRTY |
                       SITUATION_ALT_IS_DIRTY  ) :

                    // 0x60: cur=perm, cur=dirty, alt=dirty
                    // Common situation: likely first step of code update
                    // Update alt and re-ipl
                    l_actions |= IPL_RESTART;
                    l_actions |= DO_UPDATE;
                    l_actions |= UPDATE_MVPD;
                    l_actions |= UPDATE_SBE;

                    // Set Update side to alt
                    io_sbeState.seeprom_side_to_update =
                                ( io_sbeState.alt_seeprom_side ==
                                              SBE_SEEPROM0 )
                                  ? EEPROM::SBE_PRIMARY : EEPROM::SBE_BACKUP ;

                    // Update MVPD RE-IPL SEEPROM flag: re-IPL on ALT:
                    ( io_sbeState.alt_seeprom_side == SBE_SEEPROM0 ) ?
                         // clear bit 1
                         io_sbeState.mvpdSbKeyword.flags &= ~REIPL_SEEPROM_MASK
                         : // set bit 1
                         io_sbeState.mvpdSbKeyword.flags |= REIPL_SEEPROM_MASK;

                    // If istep mode, re-IPL bit won't be checked, so also
                    // change perm flag to boot off of alt on next IPL
                    if ( g_istep_mode )
                    {
                        // Update MVPD PERMANENT flag: make alt=perm
                        (io_sbeState.alt_seeprom_side == SBE_SEEPROM0 ) ?
                         // clear bit 0
                         io_sbeState.mvpdSbKeyword.flags &= ~PERMANENT_FLAG_MASK
                         : //set bit 0
                         io_sbeState.mvpdSbKeyword.flags |= PERMANENT_FLAG_MASK;

                        TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                                   "istep mode: update alt to perm, (sit="
                                   "0x%.2X)",
                                   TARGETING::get_huid(io_sbeState.target),
                                   i_system_situation);
                    }

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "cur=perm/dirty(%d), alt=dirty. Update alt. re-"
                               "IPL. (sit=0x%.2X, act=0x%.8X, flags=0x%.2X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions,
                               io_sbeState.mvpdSbKeyword.flags);

                    break;


            ///////////////////////////////////////////////////////////////////
                case ( SITUATION_CUR_IS_PERM  |
                       SITUATION_CUR_IS_DIRTY |
                       SITUATION_ALT_IS_CLEAN  ) :

                    // 0x40: cur=perm, cur=dirty, alt=clean
                    // Ask FSP if we just re-IPLed due to our request.
                    // If Yes: Working PERM side is out-of-sync, so callout
                    //         SBE code, but continue IPL on dirty image
                    // If Not: Update alt and re-IPL

                    if ( isIplFromReIplRequest() )
                    {
                        l_actions = CLEAR_ACTIONS;
                        TRACFCOMP(g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                                  "cur=perm/dirty(%d), alt=clean. On our Re-"
                                  "IPL. Call-out SBE code but Continue IPL. "
                                  "(sit=0x%.2X, act=0x%.8X)",
                                  TARGETING::get_huid(io_sbeState.target),
                                  io_sbeState.cur_seeprom_side,
                                  i_system_situation, l_actions);

                        /*@
                         * @errortype
                         * @moduleid     SBE_DECISION_TREE
                         * @reasoncode   SBE_PERM_SIDE_DIRTY_BAD_PATH
                         * @userdata1    System Situation
                         * @userdata2    Update Actions
                         * @devdesc      Bad Path in decisionUpdateTree:
                         *               cur=PERM/DIRTY
                         * @custdesc     A problem occurred while updating
                         *               processor boot code.
                         */
                        err = new ErrlEntry(ERRL_SEV_RECOVERED,
                                            SBE_DECISION_TREE,
                                            SBE_PERM_SIDE_DIRTY_BAD_PATH,
                                            TO_UINT64(i_system_situation),
                                            TO_UINT64(l_actions));
                        // Target isn't directly related to fail, but could be
                        // useful to see how far we got before failing.
                        ErrlUserDetailsTarget(io_sbeState.target
                                              ).addToLog(err);
                        err->collectTrace(SBE_COMP_NAME);
                        err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                                  HWAS::SRCI_PRIORITY_HIGH );
                        break;

                    }
                    else
                    {
                        // Update alt and re-ipl
                        l_actions |= IPL_RESTART;
                        l_actions |= DO_UPDATE;
                        l_actions |= UPDATE_MVPD;
                        l_actions |= UPDATE_SBE;

                        // Set Update side to alt
                        io_sbeState.seeprom_side_to_update =
                                ( io_sbeState.alt_seeprom_side ==
                                              SBE_SEEPROM0 )
                                  ? EEPROM::SBE_PRIMARY : EEPROM::SBE_BACKUP ;

                        // Update MVPD RE-IPL SEEPROM flag: re-IPL on ALT:
                        ( io_sbeState.alt_seeprom_side == SBE_SEEPROM0 ) ?
                          // clear bit 1
                          io_sbeState.mvpdSbKeyword.flags &= ~REIPL_SEEPROM_MASK
                          : // set bit 1
                          io_sbeState.mvpdSbKeyword.flags |= REIPL_SEEPROM_MASK;

                        TRACFCOMP(g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                                  "cur=perm/dirty(%d), alt=clean. Not our Re-"
                                  "IPL. Update alt and MVPD. re-IPL. "
                                  "(sit=0x%.2X, act=0x%.8X, flags=0x%.2X)",
                                  TARGETING::get_huid(io_sbeState.target),
                                  io_sbeState.cur_seeprom_side,
                                  i_system_situation, l_actions,
                                  io_sbeState.mvpdSbKeyword.flags);

                        break;
                    }

            ///////////////////////////////////////////////////////////////////
                case ( SITUATION_CUR_IS_PERM  |
                       SITUATION_CUR_IS_CLEAN |
                       SITUATION_ALT_IS_DIRTY  ) :

                    // 0x20: cur=perm, cur=clean, alt=dirty
                    // Not sure why alt is dirty, but update alt and
                    // continue IPL

                    l_actions |= DO_UPDATE;
                    l_actions |= UPDATE_SBE;

                    // Set Update side to alt
                    io_sbeState.seeprom_side_to_update =
                                ( io_sbeState.alt_seeprom_side ==
                                              SBE_SEEPROM0 )
                                  ? EEPROM::SBE_PRIMARY : EEPROM::SBE_BACKUP ;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "cur=perm/clean(%d), alt=dirty. "
                               "Update alt. Continue IPL. "
                               "(sit=0x%.2X, act=0x%.8X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions);

                    break;


            ///////////////////////////////////////////////////////////////////
                case ( SITUATION_CUR_IS_PERM  |
                       SITUATION_CUR_IS_CLEAN |
                       SITUATION_ALT_IS_CLEAN  ) :

                    // 0x0: cur=perm, cur=clean, alt=clean
                    // Both sides are clean - no updates
                    // Continue IPL
                    l_actions = CLEAR_ACTIONS;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "Both sides clean-no updates. cur was perm(%d). "
                               "Continue IPL. (sit=0x%.2X, act=0x%.8X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions);

                    break;

            ///////////////////////////////////////////////////////////////////
                default:

                    l_actions = UNSUPPORTED_SITUATION;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "Unsupported Scenario.  Just Continue IPL. "
                               "(sit=0x%.2X, act=0x%.8X, cur=%d)",
                               TARGETING::get_huid(io_sbeState.target),
                               i_system_situation, l_actions,
                               io_sbeState.cur_seeprom_side);

                    break;
            }
            ///////////////////////////////////////////////////////////////////
            //  End of i_system_situation switch statement
            ///////////////////////////////////////////////////////////////////

#endif

            // Set actions
            io_sbeState.update_actions = static_cast<sbeUpdateActions_t>
                                                    (l_actions);

            TRACUCOMP( g_trac_sbe, "decisionTreeForUpdates() Tgt=0x%X: "
                       "i_system_situation=0x%.2X, actions=0x%.8X, "
                       "Update EEPROM=0x%X, flags=0x%X, cur=%d",
                       TARGETING::get_huid(io_sbeState.target),
                       i_system_situation,
                       io_sbeState.update_actions,
                       io_sbeState.seeprom_side_to_update,
                       io_sbeState.mvpdSbKeyword.flags,
                       io_sbeState.cur_seeprom_side);

        }while(0);

        return err;

    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t performUpdateActions(sbeTargetState_t& io_sbeState)
    {
        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"performUpdateActions(): HUID=0x%.8X, "
                   "updateActions=0x%.8X",
                   TARGETING::get_huid(io_sbeState.target),
                   io_sbeState.update_actions);

        errlHndl_t err      = NULL;
        errlHndl_t err_info = NULL;
        uint32_t   l_actions = io_sbeState.update_actions;

        do{

            /**************************************************************/
            /*  Update SEEPROM, if necessary                              */
            /**************************************************************/
            if (l_actions & UPDATE_SBE)
            {
#ifdef CONFIG_SBE_UPDATE_SIMULTANEOUS
                io_sbeState.seeprom_side_to_update = EEPROM::SBE_PRIMARY;
#endif
                err = updateSeepromSide(io_sbeState);
                if(err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"performUpdateActions() - "
                               "updateProcessorSbeSeeproms() failed. "
                               "HUID=0x%.8X.",
                               TARGETING::get_huid(io_sbeState.target));
                    break;
                }
                l_actions |= SBE_UPDATE_COMPLETE;
            }

            /**************************************************************/
            /*  Update MVPD, if necessary                                 */
            /**************************************************************/
            if (l_actions & UPDATE_MVPD)
            {
                err =  getSetMVPDVersion(io_sbeState.target,
                                         MVPDOP_WRITE,
                                         io_sbeState.mvpdSbKeyword);
                if(err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"performUpdateActions() - "
                               "Error Updating MVPD with new SBE Image Info "
                               "HUID=0x%.8X, rc=0x%.4x. Skipping SBE Update. "
                               "(actions=0x%.8X)",
                               TARGETING::get_huid(io_sbeState.target),
                               err->reasonCode(), l_actions );
                    break;
                }
                l_actions |= MVPD_UPDATE_COMPLETE;
            }

            /**************************************************************/
            /*  Create Info Error Log of successful operation             */
            /**************************************************************/
#ifndef CONFIG_SBE_UPDATE_SIMULTANEOUS
            TRACFCOMP( g_trac_sbe,INFO_MRK"performUpdateActions(): Successful "
                       "SBE Update of HUID=0x%.8X SEEPROM %d",
                       TARGETING::get_huid(io_sbeState.target),
                       io_sbeState.seeprom_side_to_update);
#else
            TRACFCOMP( g_trac_sbe,INFO_MRK"performUpdateActions(): Successful "
                       "SBE Update of HUID=0x%.8X - Both SEEPROMs",
                       TARGETING::get_huid(io_sbeState.target));
#endif

            /*@
             * @errortype
             * @moduleid          SBE_PERFORM_UPDATE_ACTIONS
             * @reasoncode        SBE_INFO_LOG
             * @userdata1[0:31]   Update Actions Enum
             * @userdata1[32:63]  Customized Data CRC
             * @userdata2[0:31]   Original SEEPROM 0 CRC
             * @userdata2[32:63]  Original SEEPROM 1 CRC
             * @devdesc      Successful Update of SBE SEEPROM
             *               SBE Verion Information
             */
            err_info = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                     SBE_PERFORM_UPDATE_ACTIONS,
                                     SBE_INFO_LOG,
                                     TWO_UINT32_TO_UINT64(
                                         l_actions,
                                         io_sbeState.customizedImage_crc),
                                     TWO_UINT32_TO_UINT64(
                                         io_sbeState.seeprom_0_ver.data_crc,
                                         io_sbeState.seeprom_1_ver.data_crc));


            // Add general data sections to capture MVPD SB Keyword and
            // the new SBE SEEPROM Version structure
            err_info->addFFDC( SBE_COMP_ID,
                               &(io_sbeState.mvpdSbKeyword),
                               sizeof(io_sbeState.mvpdSbKeyword),
                               0,                   // Version
                               ERRL_UDT_NOFORMAT,   // parser ignores data
                               false );             // merge

            err_info->addFFDC( SBE_COMP_ID,
                               &(io_sbeState.new_seeprom_ver),
                               sizeof(io_sbeState.new_seeprom_ver),
                               0,                   // Version
                               ERRL_UDT_NOFORMAT,   // parser ignores data
                               false );             // merge


            err_info->collectTrace(SBE_COMP_NAME, KILOBYTE);

            ErrlUserDetailsTarget(io_sbeState.target, "SBE Target Updated")
                                 .addToLog(err_info);

            errlCommit( err_info, SBE_COMP_ID );

            /**************************************************************/


        }while(0);

        io_sbeState.update_actions = static_cast<sbeUpdateActions_t>
                                                    (l_actions);
        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"performUpdateActions(): HUID=0x%.8X, "
                   "updateActions=0x%.8X",
                   TARGETING::get_huid(io_sbeState.target),
                   io_sbeState.update_actions);

        return err;

    }



/////////////////////////////////////////////////////////////////////
    uint32_t trimBitMask(uint32_t i_mask,
                         size_t i_maxBits)
    {
        TRACDCOMP( g_trac_sbe,
                   ENTER_MRK"trimBitMask(i_mask=0x%.8X, i_maxBits=0x%.8X)",
                   i_mask, i_maxBits);
        uint32_t retMask = i_mask;

        while(__builtin_popcount(retMask) >  static_cast<int32_t>(i_maxBits))
        {
            retMask ^= (0x80000000 >>
                        static_cast<uint32_t>(__builtin_clz(retMask)));
        }

        TRACDCOMP( g_trac_sbe,
                   EXIT_MRK"trimBitMask(): retMask=0x%.8X",
                   retMask);

        return retMask;
    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t createSbeImageVmmSpace(void)
    {

        TRACDCOMP( g_trac_sbe,
                   ENTER_MRK"createSbeImageVmmSpace");

        int64_t rc = 0;
        errlHndl_t err = NULL;

        do{

            //Make sure procedure constants keep within expected range.
            assert((FIXED_SEEPROM_WORK_SPACE <= VMM_SBE_UPDATE_SIZE/2),
                "createSbeImageVmmSpace() FIXED_SEEPROM_WORK_SPACE too large");
            assert((FIXED_RING_BUF_SIZE <= VMM_SBE_UPDATE_SIZE/4),
                "createSbeImageVmmSpace() FIXED_RING_BUF_SIZE too large");


            // Create a memory block to serve as XIP Customize scratch space
            // NOTE: using mm_alloc_block since this code is running before we
            // have mainstore and we must have contiguous blocks of memory for
            // the customize procedure to use.
            rc = mm_alloc_block( NULL,
                                 reinterpret_cast<void*>
                                 (VMM_VADDR_SBE_UPDATE),
                                 VMM_SBE_UPDATE_SIZE);

            if(rc == -EALREADY)
            {
                //-EALREADY inidciates the block is already mapped
                // so just ignore
                rc = 0;
            }

            if( rc )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"createSbeImageVmmSpace() - "
                           "Error from mm_alloc_block : rc=%d", rc );
                /*@
                 * @errortype
                 * @moduleid     SBE_CREATE_TEST_SPACE
                 * @reasoncode   SBE_ALLOC_BLOCK_FAIL
                 * @userdata1    Requested Address
                 * @userdata2    rc from mm_alloc_block
                 * @devdesc      updateProcessorSbeSeeproms> Error
                 *               from mm_alloc_block
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_CREATE_TEST_SPACE,
                                    SBE_ALLOC_BLOCK_FAIL,
                                    TO_UINT64(VMM_VADDR_SBE_UPDATE),
                                    TO_UINT64(rc));

                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );

                break;
            }

            rc = mm_set_permission(reinterpret_cast<void*>
                                   (VMM_VADDR_SBE_UPDATE),
                                   VMM_SBE_UPDATE_SIZE,
                                   WRITABLE | ALLOCATE_FROM_ZERO );
            if( rc )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"createSbeImageVmmSpace() - Error from mm_set_permission : rc=%d", rc );
                /*@
                 * @errortype
                 * @moduleid     SBE_CREATE_TEST_SPACE
                 * @reasoncode   SBE_SET_PERMISSION_FAIL
                 * @userdata1    Requested Address
                 * @userdata2    rc from mm_set_permission
                 * @devdesc      updateProcessorSbeSeeproms> Error from
                 *               mm_set_permission on creation
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_CREATE_TEST_SPACE,
                                    SBE_SET_PERMISSION_FAIL,
                                    TO_UINT64(VMM_VADDR_SBE_UPDATE),
                                    TO_UINT64(rc));
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
                break;
            }

        }while(0);

        TRACDCOMP( g_trac_sbe,
                   EXIT_MRK"createSbeImageVmmSpace() - rc =0x%X", rc);

        return err;

    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t cleanupSbeImageVmmSpace(void)
    {
        TRACDCOMP( g_trac_sbe,
                   ENTER_MRK"cleanupSbeImageVmmSpace");

        errlHndl_t err = NULL;
        int64_t rc = 0;

        do{

            //release all pages in page block
            rc = mm_remove_pages(RELEASE,
                                 reinterpret_cast<void*>
                                 (VMM_VADDR_SBE_UPDATE),
                                 VMM_SBE_UPDATE_SIZE);
            if( rc )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"cleanupSbeImageVmmSpace() - "
                           "Error from mm_remove_pages : rc=%d", rc );
                /*@
                 * @errortype
                 * @moduleid     SBE_CLEANUP_TEST_SPACE
                 * @reasoncode   SBE_REMOVE_PAGES_FAIL
                 * @userdata1    Requested Address
                 * @userdata2    rc from mm_remove_pages
                 * @devdesc      updateProcessorSbeSeeproms> mm_remove_pages
                 *               RELEASE failed
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_CLEANUP_TEST_SPACE,
                                    SBE_REMOVE_PAGES_FAIL,
                                    TO_UINT64(VMM_VADDR_SBE_UPDATE),
                                    TO_UINT64(rc));
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );

                break;
            }

            // Set permissions back to "no_access"
            rc = mm_set_permission(reinterpret_cast<void*>
                                   (VMM_VADDR_SBE_UPDATE),
                                   VMM_SBE_UPDATE_SIZE,
                                   NO_ACCESS | ALLOCATE_FROM_ZERO );
            if( rc )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"cleanupSbeImageVmmSpace() - "
                           "Error from mm_set_permission : rc=%d", rc );
                /*@
                 * @errortype
                 * @moduleid     SBE_CLEANUP_TEST_SPACE
                 * @reasoncode   SBE_SET_PERMISSION_FAIL
                 * @userdata1    Requested Address
                 * @userdata2    rc from mm_set_permission
                 * @devdesc      updateProcessorSbeSeeproms> Error from
                 *               mm_set_permission on cleanup
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_CLEANUP_TEST_SPACE,
                                    SBE_SET_PERMISSION_FAIL,
                                    TO_UINT64(VMM_VADDR_SBE_UPDATE),
                                    TO_UINT64(rc));
                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );
                break;
            }

        }while(0);


        TRACDCOMP( g_trac_sbe,
                   EXIT_MRK"cleanupSbeImageVmmSpace() - rc =0x%X", rc);

        return err;

    }


/////////////////////////////////////////////////////////////////////
    bool isIplFromReIplRequest(void)
    {
        TRACDCOMP( g_trac_sbe,
                   ENTER_MRK"isIplFromReIplRequest");

        bool o_reIplRequest = false;
        errlHndl_t err = NULL;
        msg_t * msg = msg_allocate();

        do{

            /***********************************************/
            /*  Check if MBOX Query has already been made  */
            /***********************************************/
            if ( g_mbox_query_done == true )
            {
                o_reIplRequest = g_mbox_query_result;

                TRACUCOMP( g_trac_sbe, "isIplFromReIplRequest: query "
                           "previously done (%d). o_reIplRequest = %d",
                           g_mbox_query_done, o_reIplRequest);
                break;
            }

            /*********************************************/
            /*  Check if MBOX is enabled                 */
            /*********************************************/
            bool mbox_enabled = false;

            TARGETING::Target * sys = NULL;
            TARGETING::targetService().getTopLevelTarget( sys );
            TARGETING::SpFunctions spfuncs;
            if( sys &&
                sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfuncs) &&
                spfuncs.mailboxEnabled)
            {
                mbox_enabled = true;
            }

            /****************************************************/
            /*  MBOX IS NOT enabled: assume IPL not our request */
            /****************************************************/
            if ( mbox_enabled == false )
            {
                o_reIplRequest = false;
                TRACFCOMP(g_trac_sbe, INFO_MRK"isIplFromReIplRequest(): "
                          "MBOX not enabled, so assume not our IPL request. "
                          "o_reIplRequest=%d", o_reIplRequest);
                break;
            }


            /*********************************************/
            /*  MBOX enabled, send message               */
            /*********************************************/
            msg->type = MSG_IPL_DUE_TO_SBE_UPDATE;
            msg->data[0] = 0x0;
            msg->data[1] = 0x0;
            msg->extra_data = NULL;

            err = MBOX::sendrecv(MBOX::IPL_SERVICE_QUEUE, msg);

            if(err)
            {
                o_reIplRequest = false;
                TRACFCOMP(g_trac_sbe, ERR_MRK"isIplFromReIplRequest(): "
                          "Error sending MBOX msg. Commit error, and assume "
                          "IPL wasn't requested from us: o_reIplRequest=%d",
                          o_reIplRequest);

                errlCommit(err, SBE_COMP_ID);
                break;
            }

            // data word 0: if non-zero:  IPL is due to SBE Update Request
            // data word 1: if non-zero:  IPL is due to an error found by the
            //                            FSP
            if ( msg->data[1] == 0 ) // No error from FSP side
            {
                if( msg->data[0] != 0 )
                {
                    // IPL is due to SBE Update Request
                    o_reIplRequest = true;
                    TRACFCOMP(g_trac_sbe, INFO_MRK"isIplFromReIplRequest(): "
                              "MBOX retuned that it was our IPL request: "
                              "o_reIplRequest=%d (d0=0x%X, d1=0x%X)",
                              o_reIplRequest, msg->data[0], msg->data[1]);
                }
                else
                {
                    // normal IPL
                    o_reIplRequest = false;
                    TRACFCOMP(g_trac_sbe, INFO_MRK"isIplFromReIplRequest(): "
                             "MBOX returned that it was a normal IPL: "
                             "o_reIplRequest=%d (d0=0x%X, d1=0x%X)",
                              o_reIplRequest, msg->data[0], msg->data[1]);

                }
            }
            else  /*  Non-Zero: error from FSP side. */
            {
                // handle error reported by FSP
                o_reIplRequest = false;
                TRACFCOMP(g_trac_sbe, INFO_MRK"isIplFromReIplRequest(): "
                          "MBOX returned error from FSP-side, so assume not our"
                          "IPL request: o_reIplRequest=%d (d0=0x%X, d1=0x%X)",
                          o_reIplRequest, msg->data[0], msg->data[1]);
            }


        }while(0);


        /********************************************************************/
        /*  If check hadn't been done before, set globals for next request  */
        /********************************************************************/
        if ( g_mbox_query_done == false )
        {
            g_mbox_query_done = true;
            g_mbox_query_result = o_reIplRequest;

            TRACUCOMP( g_trac_sbe, "isIplFromReIplRequest: save results: "
                       "q_done = %d, q_result = %d",
                       g_mbox_query_done, g_mbox_query_result);
        }


        // msg cleanup
        msg_free(msg);
        msg = NULL;

        TRACDCOMP( g_trac_sbe,
                   EXIT_MRK"isIplFromReIplRequest(): o_reIplRequest=%d",
                   o_reIplRequest);

        return o_reIplRequest;

    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t preReIplCheck(std::vector<sbeTargetState_t>& io_sbeStates_v)
    {

        TRACDCOMP( g_trac_sbe,
                   ENTER_MRK"preReIplCheck");

        errlHndl_t err = NULL;

        // MVPD PERMANT and Re-IPL Seeprom flags
        uint8_t perm_and_reipl = 0x0;
        uint8_t flags_mask = (PERMANENT_FLAG_MASK | REIPL_SEEPROM_MASK);
        uint8_t flags_match_0 =    SEEPROM_0_PERMANENT_VALUE |
                                   REIPL_SEEPROM_0_VALUE;
        uint8_t flags_match_1 =    SEEPROM_1_PERMANENT_VALUE |
                                   REIPL_SEEPROM_1_VALUE;
        uint8_t flags_misMatch_A = SEEPROM_1_PERMANENT_VALUE |
                                   REIPL_SEEPROM_0_VALUE;
        uint8_t flags_misMatch_B = SEEPROM_0_PERMANENT_VALUE |
                                   REIPL_SEEPROM_1_VALUE;

        do{


            /*****************************************************************/
            /*  Iterate over all the processors and check/update each for:   */
            /*  1) MVPD SB Keyword has correct flag set for the              */
            /*     re-IPL SEEPROM                                            */
            /*****************************************************************/
            for ( uint8_t i=0; i < io_sbeStates_v.size(); i++ )
            {
                /*************************************************************/
                /* If not already updated, make sure MVPD SB Keyword has     */
                /*     correct flag set for re-IPL SEEPROM                   */
                /*************************************************************/
                if (!(io_sbeStates_v[i].update_actions & MVPD_UPDATE_COMPLETE))
                {
                    // This target has not already had its MVPD updated
                    // Check that perm and re-IPL boot flag match

                    perm_and_reipl = io_sbeStates_v[i].mvpdSbKeyword.flags &
                                     flags_mask;


                    if ( ( perm_and_reipl == flags_match_0 ) ||
                         ( perm_and_reipl == flags_match_1 )   )
                    {
                        TRACUCOMP(g_trac_sbe,"preReIplCheck(): no MVPD update "
                                  "required for tgt=0x%X (u_a=0x%X, flag=0x%X)",
                                  TARGETING::get_huid(io_sbeStates_v[i].target),
                                  io_sbeStates_v[i].update_actions,
                                  io_sbeStates_v[i].mvpdSbKeyword.flags);
                        continue;

                    }
                    else if ( ( perm_and_reipl == flags_misMatch_A ) ||
                              ( perm_and_reipl == flags_misMatch_B )   )

                    {
                        if ( perm_and_reipl == flags_misMatch_A )
                        {
                            // Perm is SEEPROM 1, so set both to 1
                            io_sbeStates_v[i].mvpdSbKeyword.flags |=
                                                            flags_match_1;
                        }
                        else
                        {
                            // Perm is SEEPROM 0, so set both to 0
                            io_sbeStates_v[i].mvpdSbKeyword.flags &=
                                                           ~flags_mask;
                        }


                        TRACFCOMP(g_trac_sbe,"preReIplCheck(): MVPD update "
                                  "Requried for tgt=0x%X (u_a=0x%X, flag=0x%X)",
                                  TARGETING::get_huid(io_sbeStates_v[i].target),
                                  io_sbeStates_v[i].update_actions,
                                  io_sbeStates_v[i].mvpdSbKeyword.flags);

                        err = getSetMVPDVersion(
                                    io_sbeStates_v[i].target,
                                    MVPDOP_WRITE,
                                    io_sbeStates_v[i].mvpdSbKeyword);
                        if(err)
                        {
                            TRACFCOMP(g_trac_sbe,ERR_MRK"preReIplCheck() "
                                "Error Updating MVPD with new flag Info: "
                                "HUID=0x%.8X, rc=0x%.4X. Committing log "
                                "here and continuing.",
                                TARGETING::get_huid(io_sbeStates_v[i].target),
                                err->reasonCode());
                             errlCommit( err, SBE_COMP_ID );
                        }

                        // update actions field
                        uint32_t tmp_actions = io_sbeStates_v[i].update_actions
                                                | MVPD_UPDATE_COMPLETE;

                        io_sbeStates_v[i].update_actions =
                                          static_cast<sbeUpdateActions_t>
                                                          (tmp_actions);

                        continue;

                    }
                }
            } // end of for loop

        }while(0);


        TRACDCOMP( g_trac_sbe,
                   EXIT_MRK"preReIplCheck()");

        return err;

    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t masterVersionCompare(
                     std::vector<sbeTargetState_t>& io_sbeStates_v)
    {
        TRACDCOMP( g_trac_sbe,
                   ENTER_MRK"masterVersionCompare");

        errlHndl_t err = NULL;

        uint8_t mP = UINT8_MAX;
        sbe_image_version_t mP_version;
        sbe_image_version_t * ver_ptr;

        do{

            // If running in simics, don't do these checks
            if ( Util::isSimicsRunning() )
            {
                break;
            }

            /*****************************************************************/
            /*  Iterate over all the processors to find Master Processor     */
            /*****************************************************************/
            for ( uint8_t i=0; i < io_sbeStates_v.size(); i++ )
            {
                if ( io_sbeStates_v[i].target_is_master == true )
                {
                    mP = i;

                    // Compare against 'current' Master side in case there is
                    // an issue with the other side
                    if (io_sbeStates_v[i].cur_seeprom_side ==
                                          SBE_SEEPROM0)
                    {
                        ver_ptr =
                            &(io_sbeStates_v[i].seeprom_0_ver.image_version);
                    }
                    else // SBE_SEEPROM1
                    {
                        ver_ptr =
                            &(io_sbeStates_v[i].seeprom_1_ver.image_version);
                    }

                    memcpy(&(mP_version),
                           ver_ptr,
                           SBE_IMAGE_VERSION_SIZE);
                    break;
                }
            }

            // Handle very unlikely case of not finding Master Processor
            assert( (mP != UINT8_MAX),
                    "masterVersionCompare(): master processor not found");

            /*****************************************************************/
            /*  Make sure that there aren't any errors associated with       */
            /*  updating the non-master targets; otherwise you can't trust   */
            /*  their  version                                               */
            /*  -- AND --                                                    */
            /*  Compare 'current' Version on all processors to see if they   */
            /*  match the 'current' version on the Master Processor          */
            /*                                                               */
            /*  NOTE: Comparison based on PNOR SBE Image and --NOT--         */
            /*        based on CRC (which is partly target specific)         */
            /*                                                               */
            /*  Also, there are special checks for the Master Processor      */
            /*****************************************************************/

            // @todo RTC 107721 - Need to handle Habanero 'Golden' SEEPROM side

            for ( uint8_t i=0; i < io_sbeStates_v.size(); i++ )
            {

                // Special Master Processor checks
                if ( i == mP )
                {
// Skip Master Processor check of Both SEEPROMs being identical
#ifndef CONFIG_SBE_UPDATE_INDEPENDENT

                    // Compare Versions of Both SEEPROMs to PNOR Version
                    // Create a Predictive Error if there's an issue
                    if ((0 != memcmp(
                              &(io_sbeStates_v[i].pnorVersion),
                              &(io_sbeStates_v[i].seeprom_0_ver.image_version),
                              SBE_IMAGE_VERSION_SIZE) )
                        ||
                        (0 != memcmp(
                              &(io_sbeStates_v[i].pnorVersion),
                              &(io_sbeStates_v[i].seeprom_1_ver.image_version),
                              SBE_IMAGE_VERSION_SIZE) )
                            )
                    {
                        TRACFCOMP( g_trac_sbe,ERR_MRK"masterVersionCompare() - "
                                   "SBE Version Miscompare Between Master "
                                   "Target SEEPROMs (HUID=0x%.8X, current "
                                   "side=%d)",
                                   TARGETING::get_huid(
                                                  io_sbeStates_v[mP].target),
                                   io_sbeStates_v[mP].cur_seeprom_side);

                        // Trace first 8 bytes of each section
                        // Full Version added to error log below
                        TRACFBIN( g_trac_sbe,
                                  "PNOR Version",
                                  &(io_sbeStates_v[i].pnorVersion),
                                  8 ) ;

                        TRACFBIN(
                             g_trac_sbe,
                             "Seeprom0: Master Image Version",
                             &(io_sbeStates_v[mP].seeprom_0_ver.image_version),
                             8 ) ;

                        TRACFBIN(
                             g_trac_sbe,
                             "Seeprom1: Master Image Version",
                             &(io_sbeStates_v[mP].seeprom_1_ver.image_version),
                             8 ) ;

                        /*@
                         * @errortype
                         * @moduleid     SBE_MASTER_VERSION_COMPARE
                         * @reasoncode   SBE_MASTER_VERSION_DOWNLEVEL
                         * @userdata1    Master Target HUID
                         * @userdata2    Master Target Loop Index
                         * @devdesc      SBE Image Verion Miscompare with
                         *               Master Target
                         */
                        err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                            SBE_MASTER_VERSION_COMPARE,
                                            SBE_MASTER_VERSION_DOWNLEVEL,
                                            TARGETING::get_huid(
                                                  io_sbeStates_v[mP].target),
                                            mP);

                        err->collectTrace(SBE_COMP_NAME);

                        err->addPartCallout(
                                           io_sbeStates_v[i].target,
                                           HWAS::SBE_SEEPROM_PART_TYPE,
                                           HWAS::SRCI_PRIORITY_HIGH,
                                           HWAS::NO_DECONFIG,
                                           HWAS::GARD_NULL );

                        ErrlUserDetailsTarget(io_sbeStates_v[mP].target,
                                              "Master Target").addToLog(err);

                        // Add general data sections to capture the
                        // different versions
                        err->addFFDC( SBE_COMP_ID,
                                      &(io_sbeStates_v[i].pnorVersion),
                                      SBE_IMAGE_VERSION_SIZE,
                                      0,                 // Version
                                      ERRL_UDT_NOFORMAT, // parser ignores data
                                      false );           // merge

                        err->addFFDC( SBE_COMP_ID,
                             &(io_sbeStates_v[mP].seeprom_0_ver.image_version),
                                      SBE_IMAGE_VERSION_SIZE,
                                      0,                 // Version
                                      ERRL_UDT_NOFORMAT, // parser ignores data
                                      false );           // merge

                        err->addFFDC( SBE_COMP_ID,
                             &(io_sbeStates_v[mP].seeprom_1_ver.image_version),
                                      SBE_IMAGE_VERSION_SIZE,
                                      0,                 // Version
                                      ERRL_UDT_NOFORMAT, // parser ignores data
                                      false );           // merge

                        errlCommit( err, SBE_COMP_ID );

                    } // end of check
#endif
                    // Continue to avoid remaining non-Master Processor checks
                    continue;
                }
                else
                {
                    // Not Master, so get 'current' version
                    if (io_sbeStates_v[i].cur_seeprom_side ==
                                          SBE_SEEPROM0)
                    {
                        ver_ptr =
                            &(io_sbeStates_v[i].seeprom_0_ver.image_version);
                    }
                    else // SBE_SEEPROM1
                    {
                        ver_ptr =
                            &(io_sbeStates_v[i].seeprom_1_ver.image_version);
                    }

                }


                // See if there was an issue updating this target
                if ( io_sbeStates_v[i].err_plid != 0 )
                {
                    TRACFCOMP( g_trac_sbe,ERR_MRK"masterVersionCompare() - "
                               "Error Associated with Updating Target "
                               "HUID=0x%.8X: plid=0x%.8X, eid=0x%.8X, "
                               "rc=0x%.4X. Can't trust its SBE Version",
                               TARGETING::get_huid(io_sbeStates_v[i].target),
                               io_sbeStates_v[i].err_plid,
                               io_sbeStates_v[i].err_eid,
                               io_sbeStates_v[i].err_rc);

                    /*@
                     * @errortype
                     * @moduleid     SBE_MASTER_VERSION_COMPARE
                     * @reasoncode   SBE_ERROR_ON_UPDATE
                     * @userdata1[0:31]     Target HUID
                     * @userdata1[32:63]    Original Error PLID
                     * @userdata2[0:31]     Original Error EID
                     * @userdata2[32:63]    Original Error Reason Code
                     * @devdesc      Error Associated with Updating this Target
                     */
                    err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                        SBE_MASTER_VERSION_COMPARE,
                                        SBE_ERROR_ON_UPDATE,
                                        TWO_UINT32_TO_UINT64(
                                          TARGETING::get_huid(
                                                     io_sbeStates_v[i].target),
                                          io_sbeStates_v[i].err_plid),
                                        TWO_UINT32_TO_UINT64(
                                          io_sbeStates_v[i].err_eid,
                                          io_sbeStates_v[i].err_rc));

                    // Link the 2 logs
                    err->plid(io_sbeStates_v[i].err_plid);

                }

                // Compare 'current' version of target to 'current' version
                // of Master target in case Master version is down-level
                else if ( 0 != memcmp( &(mP_version),
                                       ver_ptr,
                                       SBE_IMAGE_VERSION_SIZE) )
                {
                    TRACFCOMP( g_trac_sbe,ERR_MRK"masterVersionCompare() - "
                               "SBE Version Miscompare Between Master Target "
                               "HUID=0x%.8X (side=%d) and Target HUID=0x%.8X "
                               "(side=%d)",
                               TARGETING::get_huid(
                                          io_sbeStates_v[mP].target),
                               io_sbeStates_v[mP].cur_seeprom_side,
                               TARGETING::get_huid(io_sbeStates_v[i].target),
                               io_sbeStates_v[i].cur_seeprom_side);

                    // Trace first 8 bytes of each section
                    // Full Version added to error log below
                    TRACFBIN( g_trac_sbe,
                              "PNOR Version",
                              &(io_sbeStates_v[i].pnorVersion),
                              8 ) ;

                    TRACFBIN( g_trac_sbe,
                              "Seeprom0: Master Image Version",
                              &(io_sbeStates_v[mP].seeprom_0_ver.image_version),
                              8 ) ;

                    TRACFBIN( g_trac_sbe,
                              "Seeprom1: Master Image Version",
                              &(io_sbeStates_v[mP].seeprom_1_ver.image_version),
                              8 ) ;

                    TRACFBIN( g_trac_sbe,
                              "Seeprom0: Failing Image Version",
                              &(io_sbeStates_v[i].seeprom_0_ver.image_version),
                              8  ) ;

                    TRACFBIN( g_trac_sbe,
                              "Seeprom1: Failing Image Version",
                              &(io_sbeStates_v[i].seeprom_1_ver.image_version),
                              8 ) ;


                    /*@
                     * @errortype
                     * @moduleid     SBE_MASTER_VERSION_COMPARE
                     * @reasoncode   SBE_MISCOMPARE_WITH_MASTER_VERSION
                     * @userdata1    Master Target HUID
                     * @userdata2    Comparison Target HUID
                     * @devdesc      SBE Verion Miscompare with Master Target
                     */
                    err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                        SBE_MASTER_VERSION_COMPARE,
                                        SBE_MISCOMPARE_WITH_MASTER_VERSION,
                                        TARGETING::get_huid(
                                                   io_sbeStates_v[mP].target),
                                        TARGETING::get_huid(
                                                   io_sbeStates_v[i].target));

                    // Add general data sections to capture the
                    // different versions
                    err->addFFDC( SBE_COMP_ID,
                                  &(io_sbeStates_v[i].pnorVersion),
                                  SBE_IMAGE_VERSION_SIZE,
                                  0,                 // Version
                                  ERRL_UDT_NOFORMAT, // parser ignores data
                                  false );           // merge

                    err->addFFDC( SBE_COMP_ID,
                             &(io_sbeStates_v[mP].seeprom_0_ver.image_version),
                                  SBE_IMAGE_VERSION_SIZE,
                                  0,                 // Version
                                  ERRL_UDT_NOFORMAT, // parser ignores data
                                  false );           // merge

                    err->addFFDC( SBE_COMP_ID,
                             &(io_sbeStates_v[mP].seeprom_1_ver.image_version),
                              SBE_IMAGE_VERSION_SIZE,
                                  0,                 // Version
                                  ERRL_UDT_NOFORMAT, // parser ignores data
                                  false );           // merge

                   err->addFFDC( SBE_COMP_ID,
                             &(io_sbeStates_v[i].seeprom_0_ver.image_version),
                                  SBE_IMAGE_VERSION_SIZE,
                                  0,                 // Version
                                  ERRL_UDT_NOFORMAT, // parser ignores data
                                  false );           // merge

                    err->addFFDC( SBE_COMP_ID,
                             &(io_sbeStates_v[i].seeprom_1_ver.image_version),
                              SBE_IMAGE_VERSION_SIZE,
                                  0,                 // Version
                                  ERRL_UDT_NOFORMAT, // parser ignores data
                                  false );           // merge

                }

                // No issues
                else
                {
                    TRACUCOMP( g_trac_sbe, "masterVersionCompare: Successful "
                               "Version check", i, mP);
                }


                if ( err )
                {
                    // Add FFDC and Commit the error log created here
                    err->collectTrace(SBE_COMP_NAME);
                    err->addPartCallout(
                                       io_sbeStates_v[i].target,
                                       HWAS::SBE_SEEPROM_PART_TYPE,
                                       HWAS::SRCI_PRIORITY_HIGH,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL );

                    ErrlUserDetailsTarget(io_sbeStates_v[mP].target,
                                          "Master Target").addToLog(err);

                    ErrlUserDetailsTarget(io_sbeStates_v[i].target,
                                          "Failing Target").addToLog(err);

                    errlCommit( err, SBE_COMP_ID );

                }
            }

        }while(0);


        TRACDCOMP( g_trac_sbe,
                   EXIT_MRK"masterVersionCompare");

        return err;

    }


} //end SBE Namespace
