/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbe/sbe_update.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#include <targeting/common/target.H>
#include <util/align.H>
#include <util/crc32.H>
#include <util/misc.H>
#include <util/utilxipimage.H>
#include <errno.h>
#include <pnor/pnorif.H>
#include <pnor/ecc.H>
#include <devicefw/driverif.H>
#include <sys/mm.h>
#include <sys/misc.h>
#include <sys/msg.h>
#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwas.H>
#include <initservice/initserviceif.H>
#include <console/consoleif.H>
#include <config.h>
#include <sbe/sbeif.H>
#include <sbeio/sbeioif.H>
#include <sbe/sbereasoncodes.H>
#include <sbe/sbe_update.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>

#ifdef CONFIG_BMC_IPMI
#include <ipmi/ipmisensor.H>
#include <ipmi/ipmiwatchdog.H>
#endif
#include <initservice/istepdispatcherif.H>
#ifdef CONFIG_SECUREBOOT
#include <secureboot/containerheader.H>
#endif

//  fapi support
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <fapi2/hwp_executor.H>
#include    <fapi2/hw_access.H>

//Procedures
#include <p9_xip_customize.H>
#include <p9_xip_section_append.H>
#include <p9_xip_image.h>

#include <p9_perv_scom_addresses.H>
#include <initservice/mboxRegs.H>
#include <bootloader/bootloaderif.H>
#include <secureboot/service.H>
#include <assert.h>
#include <securerom/sha512.H>

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
trace_desc_t* g_trac_sbe = NULL;
TRAC_INIT( & g_trac_sbe, SBE_COMP_NAME, 4*KILOBYTE );

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// ----------------------------------------
// Global Variables for MBOX Ipl Query
static bool g_mbox_query_done   = false;
static bool g_mbox_query_result = false;
static bool g_istep_mode        = false;
static bool g_update_both_sides = false;

// ----------------------------------------
// Global Variables HW Keys Hash Transition
static bool    g_do_hw_keys_hash_transition = false;
static SHA512_t g_hw_keys_hash_transition_data = {0};

using namespace ERRORLOG;
using namespace TARGETING;

namespace SBE
{
    errlHndl_t updateProcessorSbeSeeproms(
        const KEY_TRANSITION_PERM i_keyTransPerm)
    {
        errlHndl_t err = NULL;
        errlHndl_t err_cleanup = NULL;
        sbeTargetState_t sbeState;
        std::vector<sbeTargetState_t> sbeStates_vector;

        bool l_cleanupVmmSpace = false;
        bool l_restartNeeded   = false;

        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"updateProcessorSbeSeeproms()");

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
            /* Skip Update if ATTR_SBE_UPDATE_DISABLE is set                 */
            /*****************************************************************/
            if ( sys->getAttr<ATTR_SBE_UPDATE_DISABLE>() ) // true => disable
            {
                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update skipped due to "
                           "system attribute SBE_UPDATE_DISABLE being set");
                break;
            }

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

            if (mnfg_flags & MNFG_FLAG_UPDATE_BOTH_SIDES_OF_SBE)
            {
                TRACFCOMP(g_trac_sbe,
                            INFO_MRK"Update Both Sides of SBE Flag Indicated.");
                g_update_both_sides = true;
            }

            //Make sure procedure constants keep within expected range.
            assert((FIXED_SEEPROM_WORK_SPACE <= VMM_SBE_UPDATE_SIZE/2),
                   "updateProcessorSbeSeeproms() FIXED_SEEPROM_WORK_SPACE "
                   "too large");
            assert((MAX_RING_BUF_SIZE <= VMM_SBE_UPDATE_SIZE/4),
                   "updateProcessorSbeSeeproms() MAX_RING_BUF_SIZE too "
                   "large");

            // reset global variables for MBOX Ipl Query
            g_mbox_query_done   = false;
            g_mbox_query_result = false;

            // Create VMM space for p9_xip_customize() procedure
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
                           "masterProcChipTargetHandle=NULL is ok, "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                 errlCommit( err, SBE_COMP_ID );
                 err = NULL;
            }

            // Check if a key transition is allowed/needed
            if(i_keyTransPerm == ALLOW_KEY_TRANSITION)
            {
                err = secureKeyTransition();
            }

            if (err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateProcessorSbeSeeproms() - failed secureKeyTransition");
                break;
            }
            // Print new hw keys' hash if a key transition is required.
            if(g_do_hw_keys_hash_transition)
            {
                TRACFBIN(g_trac_sbe, "updateProcessorSbeSeeproms(): Key transition new hw key hash",
                         g_hw_keys_hash_transition_data,
                         sizeof(g_hw_keys_hash_transition_data));
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
                           TARGETING::get_huid(sbeState.target), i);

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

                //Can only update the SBE once the powerbus is up (secureboot)
                //Use the scom switch Xscom capability flag as a proxy for
                //powerbus access.  If we can't access via powerbus, then skip
                TARGETING::ScomSwitches scomSetting =
                      sbeState.target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();

                if(!(scomSetting.useXscom))
                {
                    //Xscom is not viable on this chip, thus powerbus isn't
                    //up to chip -- skip it
                    TRACFCOMP( g_trac_sbe,
                               INFO_MRK"updateProcessorSbeSeeproms(): "
                               "Power bus not established to chip 0x%X,"
                               " not performing update",
                               TARGETING::get_huid(sbeState.target));
                    continue;
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
                // Force an update of SEEPROM 0 or SEEPROM 1 if SB keyword
                // flags is requesting an update for that particular seeprom
                if (((sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY) &&
                (sbeState.mvpdSbKeyword.flags & SEEPROM_0_FORCE_UPDATE_MASK)) ||
                    ((sbeState.seeprom_side_to_update == EEPROM::SBE_BACKUP) &&
                (sbeState.mvpdSbKeyword.flags & SEEPROM_1_FORCE_UPDATE_MASK)))
                {
                   // The DO_UPDATE flag alone might not be enough to
                   // force an update, setting UPDATE_SBE flag as well
                   // because I know that performUpdateActions checks that flag
                   sbeState.update_actions = static_cast<sbeUpdateActions_t>
                             (sbeState.update_actions | DO_UPDATE | UPDATE_SBE);
                }

                if ((err == NULL) && (sbeState.update_actions & DO_UPDATE))
                {
                    // If update is needed, check to see if it's in MPIPL
                    if(sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>() == true)
                    {
                        TRACFCOMP( g_trac_sbe,
                                       INFO_MRK"updateProcessorSbeSeeproms(): "
                                       "Skip SBE update during MPIPL "
                                       ", Target UID=0x%X",
                                       TARGETING::get_huid(sbeState.target));
                        /*@
                         * @errortype
                         * @moduleid          SBE_UPDATE_SEEPROMS
                         * @reasoncode        SBE_UPDATE_DURING_MPIPL
                         * @userdata1         Target huid id
                         * @userdata2[0:31]   Update actions
                         * @userdata2[32:63]  SEEPROM side to update
                         * @devdesc           SBE update is being skipped
                         *                    during MPIPL
                         * @custdesc          SBE is not being updated
                         */
                        err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                  SBE_UPDATE_SEEPROMS,
                                  SBE_UPDATE_DURING_MPIPL,
                                  TARGETING::get_huid(sbeState.target),
                                  TWO_UINT32_TO_UINT64(
                                      TO_UINT32(sbeState.update_actions),
                                      TO_UINT32(sbeState.seeprom_side_to_update)
                                  )
                        );
                        err->collectTrace(SBE_COMP_NAME);
                    }
                    else
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

                            //Don't break - handle error at the end of the loop,
                        }
                        else
                        {
                            //Target updated without failure, so set IPL_RESTART
                            //flag, if necessary
                            if (sbeState.update_actions & IPL_RESTART)
                            {
                                l_restartNeeded = true;
                            }
                        }
                    }  // end else of if(sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>() == true)
                }  // end if ((err == NULL) && (sbeState.update_actions & DO_UPDATE))

                if ( err )
                {
                    // Something failed for this target.
                    // Save error information
                    sbeState.err_plid = err->plid();
                    sbeState.err_eid  = err->eid();
                    sbeState.err_rc   = err->reasonCode();
                    sbeState.err_sev  = err->sev();

                    // Commit the error here and move on to the next target,
                    // or if no targets left, will just continue the IPL
                    TRACFCOMP( g_trac_sbe,
                               INFO_MRK"updateProcessorSbeSeeproms(): "
                               "Committing Error Log rc=0x%.4X eid=0x%.8X "
                               "plid=0x%.8X sev=0x%.2X for Target UID=0x%X, "
                               "but continuing procedure",
                               sbeState.err_rc, sbeState.err_eid,
                               sbeState.err_plid, sbeState.err_sev,
                               TARGETING::get_huid(sbeState.target));
                    errlCommit( err, SBE_COMP_ID );
                }

                /**********************************************/
                /*   Reset the watchdog after each Action     */
                /**********************************************/
                INITSERVICE::sendProgressCode();

                // Push this sbeState onto the vector
                sbeStates_vector.push_back(sbeState);

            } //end of Target for loop collecting each target's SBE State

            /**************************************************************/
            /*  Perform System Operation                                  */
            /**************************************************************/

            // Restart IPL if SBE Update requires it or key transition occurred
            if (   (l_restartNeeded == true)
                || (g_do_hw_keys_hash_transition))
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

                err = sbeDoReboot();
                if (err)
                {
                    TRACFCOMP( g_trac_sbe,ERR_MRK"sbeDoReboot failed");
                    break;
                }
            }
            else
            {
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
            else
            {
                // Unsupported target type was passed in
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
                TRACFCOMP(g_trac_sbe,INFO_MRK"findSBEInPnor: sha512perEC "
                          "Found in %s", pnorInfo.name);
                // Advance PNOR pointer 4k to move it past header page to the
                // start of the non-customized SBE image
                o_imgPtr = reinterpret_cast<void*>
                                (reinterpret_cast<char*>(hdr_Ptr)+PAGE_SIZE);
                // Do not include header in size
                o_imgSize -= PAGE_SIZE;
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
    errlHndl_t appendHbblToSbe(void*     i_section,
                               uint32_t  i_section_size,
                               void*     i_image,
                               uint32_t& io_image_size)
    {
        errlHndl_t err = NULL;
        P9XipItem l_xipItem;

        TRACFCOMP( g_trac_sbe,
                   ENTER_MRK"appendHbblToSbe(): i_section=%p, "
                            "i_section_size=0x%X, i_image=%p, "
                            "io_image_size=0x%X",
                            i_section, i_section_size,
                            i_image, io_image_size);

        do{
            // Call p9_xip_find to find HBBL image in SBE image
            const char* l_sectionId = ".hbbl";
            // Note - this is not a fapi2 function
            int xip_rc = p9_xip_find( i_image, l_sectionId, &l_xipItem );

            // Check the return code
            if( xip_rc == P9_XIP_ITEM_NOT_FOUND )
            {
                TRACUCOMP( g_trac_sbe, "appendHbblToSbe(): "
                           "p9_xip_find received expected return code, item "
                           "not found, rc=0x%X",
                           xip_rc );
            }
            else if( xip_rc == P9_XIP_DATA_NOT_PRESENT )
            {
                TRACFCOMP( g_trac_sbe, "appendHbblToSbe(): "
                           "p9_xip_find located %s, rc=0x%X",
                           xip_rc ? "TOC only" : "TOC and section data",
                           xip_rc );

                // Call p9_xip_delete_section to delete existing HBBL image
                // from SBE image
                void *l_imageBuf =malloc(io_image_size);
                xip_rc = p9_xip_delete_section(
                                 i_image,
                                 l_imageBuf,
                                 io_image_size,
                                 P9_XIP_SECTION_SBE_HBBL );
                free(l_imageBuf);

                // Check for error
                if( xip_rc )
                {
                    TRACFCOMP( g_trac_sbe, "appendHbblToSbe(): "
                               "p9_xip_delete_section failed, rc=0x%X",
                               xip_rc );
                    /*@
                     * @errortype
                     * @moduleid     SBE_APPEND_HBBL
                     * @reasoncode   ERROR_FROM_XIP_DELETE
                     * @userdata1    rc from p9_xip_delete
                     * @userdata2    <unused>
                     * @devdesc      Bad RC from p9_xip_delete
                     * @custdesc     A problem occurred while updating processor
                     *               boot code.
                     */
                    err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                        SBE_APPEND_HBBL,
                                        ERROR_FROM_XIP_DELETE,
                                        xip_rc,
                                        0,
                                        true /* SW error */);
                    err->collectTrace(SBE_COMP_NAME);

                    // exit loop
                    break;
                }
            }
            else
            {
                TRACFCOMP( g_trac_sbe, "appendHbblToSbe(): p9_xip_find "
                           "received unexpected return code, rc=0x%X",
                           xip_rc );
                /*@
                 * @errortype
                 * @moduleid     SBE_APPEND_HBBL
                 * @reasoncode   ERROR_FROM_XIP_FIND
                 * @userdata1    rc from p9_xip_find
                 * @userdata2    <unused>
                 * @devdesc      Bad RC from p9_xip_find
                 * @custdesc     A problem occurred while updating processor
                 *               boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_APPEND_HBBL,
                                    ERROR_FROM_XIP_FIND,
                                    xip_rc,
                                    0,
                                    true /* SW error */);
                err->collectTrace(SBE_COMP_NAME);
                err->collectTrace(FAPI_IMP_TRACE_NAME,256);
                err->collectTrace(FAPI_TRACE_NAME,384);

                // exit loop
                break;
            }

            // Invoke p9_xip_section_append to append HBBL image to SBE image
            FAPI_INVOKE_HWP( err,
                             p9_xip_section_append,
                             i_section,
                             i_section_size,
                             P9_XIP_SECTION_SBE_HBBL,
                             i_image,
                             io_image_size );

            // Check for error
            if(err)
            {
                TRACFCOMP( g_trac_sbe, "appendHbblToSbe(): "
                           "p9_xip_section_append failed, rc=0x%X",
                           err->reasonCode() );

                // exit loop
                break;
            }

        }while(0);

        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"appendHbblToSbe(): i_image=%p, "
                   "io_image_size=0x%X, RC=0x%X",
                   i_image, io_image_size, ERRL_GETRC_SAFE(err) );

        return err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t ringOvd(void *io_imgPtr,
                       uint32_t & io_ovdImgSize)
    {
        errlHndl_t l_err = nullptr;
        PNOR::SectionInfo_t l_pnorRingOvd;

        do {

            l_err = PNOR::getSectionInfo(PNOR::RINGOVD, l_pnorRingOvd);
            if(l_err)
            {
                delete l_err;
                l_err = NULL;
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"ringOvd():Error trying to read RINGOVD "
                           "from PNOR. Could be blocked in secure mode. "
                           "It is optional, continuing");
                io_ovdImgSize = 0;
                break;
            }
            if(l_pnorRingOvd.size == 0)
            {
                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"ringOvd(): No RINGOVD section in PNOR");
                io_ovdImgSize = 0;
                break;
            }

            TRACDBIN( g_trac_sbe,
                      "ringOvd():100 bytes of RINGOVD section",
                      (void *)l_pnorRingOvd.vaddr,100);

            // If first 8 bytes are just FF's then we know there's no override
            if((*(static_cast<uint64_t *>((void *)l_pnorRingOvd.vaddr))) ==
                    0xFFFFFFFFFFFFFFFF)
            {
                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"ringOvd():No overrides in RINGOVD section "
                           "found");
                io_ovdImgSize = 0;
                break;
            }

            TRACFCOMP( g_trac_sbe,
                       INFO_MRK"ringOvd():Valid overrides, applying them");

            FAPI_INVOKE_HWP(l_err,p9_xip_section_append,
                            (void *)l_pnorRingOvd.vaddr,
                            RING_OVD_SIZE,
                            P9_XIP_SECTION_SBE_OVERRIDES,
                            io_imgPtr,
                            io_ovdImgSize);

            if ( l_err )
            {
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"ringOvd(): FAPI_INVOKE_HWP("
                           "p9_xip_section_append) failed, PLID=0x%x",
                           l_err->plid());

                l_err->collectTrace(SBE_COMP_NAME, 256);

                io_ovdImgSize = 0;
                break;
            }

        }while(0);

        return l_err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t procCustomizeSbeImg(TARGETING::Target* i_target,
                                   void* i_hwImgPtr,
                                   void* i_sbeImgPtr,
                                   size_t i_maxImgSize,
                                   void* io_imgPtr,
                                   size_t& o_actImgSize)
    {
        errlHndl_t err = NULL;
        uint32_t tmpImgSize = static_cast<uint32_t>(i_maxImgSize);
        uint32_t coreMask = 0x00FFFFFF; // Bits(8:31) = EC00:EC23
        size_t maxCores = P9_MAX_EC_PER_PROC;
        uint32_t coreCount = 0;
        uint32_t procIOMask = 0;
        bool procedure_success = false;

        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"procCustomizeSbeImg(): uid=0x%X, i_sbeImgPtr= "
                            "%p, maxS=0x%X, io_imgPtr=%p",
                            TARGETING::get_huid(i_target), i_sbeImgPtr,
                            i_maxImgSize, io_imgPtr);

        do{

            // Before doing any customization, we need to ensure that the
            // ATTR_EC/EQ_GARD attributes are setup to reflect the
            // current state of our targets
            HWAS::setChipletGardsOnProc(i_target);

            // cast OUR type of target to a FAPI type of target.
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapiTarg(i_target);

            // The p9_xip_customize() procedure tries to include as much core
            // information as possible, but is limited by SBE Image size
            // constraints.
            // First, maximize core mask for the target
            // Then loop on the procedure call, where the loop is designed to
            // remove the number of cores passed into p9_xip_customize() until
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

            // Get Target Service
            // System target check done earlier, so no assert check necessary
            TargetService& tS = targetService();
            TARGETING::Target* sys = NULL;
            (void) tS.getTopLevelTarget( sys );

            // setup loop parameters
            coreCount = __builtin_popcount(coreMask);
            uint32_t desired_min_cores = ((is_fused_mode()) ? 2 : 1) *
                sys->getAttr<ATTR_SBE_IMAGE_MINIMUM_VALID_ECS>();

            // Find out what chip it is
            // If NIMBUS DD1, be less restrictive
            uint32_t min_cores =
                ( (i_target->getAttr<ATTR_MODEL>() == MODEL_NIMBUS) &&
                (i_target->getAttr<TARGETING::ATTR_EC>() >= 0x20) ) ?
                    desired_min_cores :
                    std::min(desired_min_cores, coreCount);

            while( coreCount >= min_cores )
            {
                // copy customized SBE image to destination
                memcpy ( io_imgPtr,
                         i_sbeImgPtr,
                         tmpImgSize);

                procIOMask = coreMask;

                uint32_t l_ringSectionBufSize = MAX_SEEPROM_IMAGE_SIZE;
                FAPI_INVOKE_HWP( err,
                                 p9_xip_customize,
                                 l_fapiTarg,
                                 i_hwImgPtr,
                                 io_imgPtr, //image in/out
                                 tmpImgSize,
                                 (void*)RING_SEC_VADDR,
                                 l_ringSectionBufSize,
                                 SYSPHASE_HB_SBE,
                                 MODEBUILD_IPL,
                                 (void*)RING_BUF1_VADDR,
                                 (uint32_t)MAX_RING_BUF_SIZE,
                                 (void*)RING_BUF2_VADDR,
                                 (uint32_t)MAX_RING_BUF_SIZE,
                                 (void*)RING_BUF3_VADDR,
                                 (uint32_t)MAX_RING_BUF_SIZE,
                                 procIOMask ); // Bits(8:31) = EC00:EC23

                // Check for no error and use of input cores
                if ( (NULL == err) && (procIOMask == coreMask))
                {
                    // Procedure was successful
                    procedure_success = true;

                    o_actImgSize = static_cast<size_t>(tmpImgSize);

                    TRACUCOMP( g_trac_sbe, "procCustomizeSbeImg(): "
                               "p9_xip_customize success=%d, procIOMask=0x%X "
                               "o_actImgSize=0x%X",
                               procedure_success, procIOMask, o_actImgSize);

                    // exit inner loop
                    break;
                }
                // Check if p9_xip_customize returned a different core mask
                else if ( procIOMask != coreMask )
                {
                    // A different core mask is returned from p9_xip_customize
                    // when the cores sent in couldn't fit, but possibly
                    // a different procIOMask would work

                    TRACFCOMP( g_trac_sbe,
                               ERR_MRK"procCustomizeSbeImg(): FAPI_INVOKE_HWP("
                               "p9_xip_customize) returned rc=0x%X, "
                               "XIPC_IMAGE_WOULD_OVERFLOW-Retry "
                               "MaxCores=0x%.8X. HUID=0x%X. coreMask=0x%.8X, "
                               "procIOMask=0x%.8X. coreCount=%d",
                               ERRL_GETRC_SAFE(err), maxCores,
                               TARGETING::get_huid(i_target),
                               coreMask, procIOMask, coreCount);

                    // Setup for next loop - update coreMask
                    err = selectBestCores(i_target,
                                          --coreCount,
                                          coreMask);

                    if ( err )
                    {
                        TRACFCOMP(g_trac_sbe,
                                  ERR_MRK"procCustomizeSbeImg() - "
                                  "selectBestCores() failed rc=0x%X. "
                                  "coreCount=0x%.8X. HUID=0x%X. Aborting "
                                  "Customization of SBE Image",
                                  err->reasonCode(), coreCount,
                                  TARGETING::get_huid(i_target));

                        // break from inner while loop
                        break;
                    }

                    TRACFCOMP( g_trac_sbe, "procCustomizeSbeImg(): for "
                               "next loop: coreMask=0x%.8X, coreCount=%d",
                               coreMask, coreCount);

                    // Check if loop will execute again
                    // Clean up some data if it will
                    if( coreCount >= min_cores )
                    {
                        // Reset size and clear image buffer
                        tmpImgSize = static_cast<uint32_t>(i_maxImgSize);
                        memset ( io_imgPtr,
                                 0,
                                 tmpImgSize);
                    }

                    // No break - keep looping
                }
                else
                {
                    // Unexpected return code - create err and fail
                    TRACFCOMP( g_trac_sbe,
                               ERR_MRK"procCustomizeSbeImg(): FAPI_INVOKE_HWP("
                               "p9_xip_customize) failed with rc=0x%X, "
                               "MaxCores=0x%X. HUID=0x%X. coreMask=0x%.8X, "
                               "procIOMask=0x%.8X. coreCount=%d. Create "
                               "err and break loop",
                               ERRL_GETRC_SAFE(err), maxCores,
                               TARGETING::get_huid(i_target),
                               coreMask, procIOMask, coreCount);

                    ERRORLOG::ErrlUserDetailsTarget(i_target,
                                                    "Proc Target")
                                                    .addToLog(err);
                    err->collectTrace(SBE_COMP_NAME, 256);

                    // break from inner while loop
                    break;
                }
            }  // end of inner while loop

            if(err)
            {
                // There was a previous error, so break here
                break;
            }

            if ( procedure_success == false )
            {
                // No err, but exit from while loop before successful
                TRACFCOMP( g_trac_sbe, ERR_MRK"procCustomizeSbeImg() - "
                           "Failure to successfully complete p9_xip_customize()"
                           ". HUID=0x%X, rc=0x%X, coreCount=%d, coreMask=0x%.8X"
                           " procIOMask=0x%.8X, maxCores=0x%X, min_cores=0x%X, "
                           "desired_min_cores=0x%X",
                           TARGETING::get_huid(i_target), ERRL_GETRC_SAFE(err),
                           coreCount, coreMask, procIOMask, maxCores,
                           min_cores, desired_min_cores);
                /*@
                 * @errortype
                 * @moduleid          SBE_CUSTOMIZE_IMG
                 * @reasoncode        SBE_P9_XIP_CUSTOMIZE_UNSUCCESSFUL
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
                                    SBE_P9_XIP_CUSTOMIZE_UNSUCCESSFUL,
                                    TWO_UINT32_TO_UINT64(procIOMask,
                                                         ERRL_GETRC_SAFE(err)),
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
                   "o_actImgSize=0x%X, RC=0x%X, procedure_success=%d",
                   io_imgPtr, o_actImgSize, ERRL_GETRC_SAFE(err),
                   procedure_success );

        return err;
    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t selectBestCores(TARGETING::Target* i_target,
                               size_t i_maxCores,
                               uint32_t& o_coreMask)
    {
        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"selectBestCores(i_maxCores=0x%.8X)",
                   i_maxCores);

        errlHndl_t err = NULL;
        const uint32_t chipUnitMask = 0x00800000; // Bits(8:31) = EC00:EC23
        uint32_t manGuardEcs = 0x00000000;
        uint32_t remainingEcs = 0x00000000;
        uint32_t coreCount = 0;
        uint32_t deconfigByEid = 0;

        o_coreMask = 0x00000000;

        do{

            // Special case: if i_maxCores == 0 don't loop through cores
            if (unlikely(i_maxCores == 0 ))
            {
                break;
            }

            // find all CORE chiplets of the proc
            TARGETING::TargetHandleList l_coreTargetList;
            TARGETING::getChildAffinityTargetsByState( l_coreTargetList,
                                                       i_target,
                                                       CLASS_UNIT,
                                                       TYPE_CORE,
                                                       UTIL_FILTER_PRESENT);

            //Sort through cores
            for( const auto & l_core_target: l_coreTargetList )
            {
                uint8_t chipUnit = l_core_target->
                    getAttr<TARGETING::ATTR_CHIP_UNIT>();

                if(l_core_target->
                    getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
                {
                    o_coreMask |= (chipUnitMask >> chipUnit);
                    coreCount++;
                }
                else
                {
                    //If non-functional due to FCO or Manual gard,
                    //add it to list of cores to include if
                    //more are needed

                    deconfigByEid = l_core_target->
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
                        manGuardEcs |= (chipUnitMask >> chipUnit);
                    }
                    // Add it to the 'remaining' list in case
                    // more are needed
                    else
                    {
                        remainingEcs |= (chipUnitMask >> chipUnit);
                    }

                }
            }   // end core target loop

            if(coreCount == i_maxCores)
            {
                //We've found the exact amount, break out of function
                break;
            }

            else if(coreCount > i_maxCores)
            {
                //We have too many, so need to trim
                o_coreMask = trimBitMask(o_coreMask,
                                         i_maxCores);
                break;
            }

            else
            {
                // We need to add 'other' cores
                TRACUCOMP( g_trac_sbe,INFO_MRK"selectBestCores: non-functional "
                           "cores needed for bit mask: coreCount=%d, "
                           "i_maxCores=%d, o_coreMask=0x%.8X, "
                           "manGuardEcs=0x%.8X, remainingEcs=0x%.8X",
                           coreCount, i_maxCores, o_coreMask, manGuardEcs,
                           remainingEcs );
            }

            // Add more 'good' cores.
            manGuardEcs = trimBitMask(manGuardEcs,
                                      i_maxCores-coreCount);
            o_coreMask |= manGuardEcs;
            coreCount = __builtin_popcount(o_coreMask);
            TRACUCOMP( g_trac_sbe,INFO_MRK"selectBestCores: trimBitMask "
                       "manGuardEcs=0x%.8X", manGuardEcs);

            if(coreCount >= i_maxCores)
            {
                //We've found enough, break out of function
                break;
            }

            // If we still need more, add 'remaining' cores
            // Get Target Service
            // System target check done earlier, so no assert check necessary
            TargetService& tS = targetService();
            TARGETING::Target* sys = NULL;
            (void) tS.getTopLevelTarget( sys );

            uint32_t min_cores =
                sys->getAttr<ATTR_SBE_IMAGE_MINIMUM_VALID_ECS>();
            min_cores *= (is_fused_mode()) ? 2 : 1; // double minimum for fused
            if ( coreCount < min_cores )
            {
                remainingEcs = trimBitMask(remainingEcs,
                                           min_cores-coreCount);
                o_coreMask |= remainingEcs;
                TRACUCOMP( g_trac_sbe,INFO_MRK"selectBestCores: trimBitMask "
                           "remainingEcs=0x%.8X, min_cores=%d",
                           remainingEcs, min_cores);
            }

        }while(0);

        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"selectBestCores(o_coreMask=0x%.8X)",
                   o_coreMask);

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
                           "keyword wrong length HUID=0x%.8X, length=0x%.2X, "
                           "expected=0x%.2x",
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
        TARGETING::Target* masterProcChipTargetHandle = NULL;

        o_bootSide = SBE_SEEPROM_INVALID;

        do{

             TARGETING::Target * l_target=i_target;

            // Get the Master Proc Chip Target for comparisons later
            TargetService& tS = targetService();
            err = tS.queryMasterProcChipTargetHandle(
                                                masterProcChipTargetHandle);

            if( (i_target != masterProcChipTargetHandle) &&
                !(i_target->getAttr<ATTR_SBE_IS_STARTED>()) )
            {
                l_target=masterProcChipTargetHandle;
                TRACFCOMP( g_trac_sbe, INFO_MRK"getSbeBootSeeprom() "
                           "using master proc to read SBE_VITAL_REG: "
                           "i_target=0x%.8x, target=0x%.8x ",
                           TARGETING::get_huid(i_target),
                           TARGETING::get_huid(l_target));

            }

            // Read PERV_SB_CS_SCOM 0x00050008
            size_t op_size = sizeof(scomData);
            err = deviceRead( l_target,
                              &scomData,
                              op_size,
                              DEVICE_SCOM_ADDRESS(PERV_SB_CS_SCOM) );
            if( err )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeBootSeeprom() -Error "
                           "reading SB CS SCOM (0x%.8X) from Target :"
                           "HUID=0x%.8X, RC=0x%X, PLID=0x%lX",
                           PERV_SB_CS_SCOM, // 0x00050008
                           TARGETING::get_huid(l_target),
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            if(scomData & SBE_BOOT_SELECT_MASK)
            {
                o_bootSide = SBE_SEEPROM1;
            }
            else
            {
                o_bootSide = SBE_SEEPROM0;
            }

        }while(0);

        TRACFCOMP( g_trac_sbe,
                   EXIT_MRK"getSbeBootSeeprom(): o_bootSide=0x%X (reg=0x%X, "
                   "tgt=0x%X, %s)",
                   o_bootSide, scomData, TARGETING::get_huid(i_target),
                   (i_target != masterProcChipTargetHandle) ? "slave" :
                   "master");

        return err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t updateSbeBootSeeprom(TARGETING::Target* i_target)
    {
        TRACFCOMP( g_trac_sbe, ENTER_MRK"updateSbeBootSeeprom()" );

        errlHndl_t err = NULL;
        const uint32_t l_sbeBootSelectMask = SBE_BOOT_SELECT_MASK >> 32;

        size_t l_opSize = sizeof(uint32_t);

        do{
            // Read PERV_SB_CS_FSI 0x2808 for target proc
            uint32_t l_targetReg = 0;
            err = DeviceFW::deviceOp(
                         DeviceFW::READ,
                         i_target,
                         &l_targetReg,
                         l_opSize,
                         DEVICE_FSI_ADDRESS(PERV_SB_CS_FSI_BYTE) );
            if( err )
            {
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"updateSbeBootSeeprom(): getCfamRegister, "
                           "PERV_SB_CS_FSI (0x%.4X), proc target = %.8X, "
                           "RC=0x%X, PLID=0x%lX",
                           PERV_SB_CS_FSI, // 0x2808
                           TARGETING::get_huid(i_target),
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

#ifdef CONFIG_SBE_UPDATE_SEQUENTIAL
            // Read version from MVPD for target proc
            mvpdSbKeyword_t l_mvpdSbKeyword;
            err =  getSetMVPDVersion(i_target,
                                     MVPDOP_READ,
                                     l_mvpdSbKeyword);

            if( err )
            {
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"updateSbeBootSeeprom(): getSetMVPDVersion, "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            // Determine Boot Side from flags in MVPD
            bool l_bootSide0 = (isIplFromReIplRequest())
                ? (REIPL_SEEPROM_0_VALUE ==
                    (l_mvpdSbKeyword.flags & REIPL_SEEPROM_MASK))
                : (SEEPROM_0_PERMANENT_VALUE ==
                    (l_mvpdSbKeyword.flags & PERMANENT_FLAG_MASK));

#else

            // The slave will use the same side setting as the master
            sbeSeepromSide_t l_bootside = SBE_SEEPROM_INVALID;
            TARGETING::Target * l_masterTarget = nullptr;
            targetService().masterProcChipTargetHandle(l_masterTarget);
            err = getSbeBootSeeprom( l_masterTarget, l_bootside );
            if( err )
            {
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"updateSbeBootSeeprom(): call to getSbeBootSeeprom(master) failed : PLID=%.8X",
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            bool l_bootSide0 = (l_bootside == SBE_SEEPROM0);

            TRACFCOMP( g_trac_sbe,INFO_MRK"updateSbeBootSeeprom(): set SBE boot side %d for proc=%.8X",
                       !l_bootSide0,
                       TARGETING::get_huid(i_target) );

#endif

            if(l_bootSide0)
            {
                // Set Boot Side 0 by clearing bit for side 1
                l_targetReg &= ~l_sbeBootSelectMask;

                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"updateSbeBootSeeprom(): l_read_reg=0x%.8X "
                           "set SBE boot side 0 for proc=%.8llX",
                           l_targetReg,
                           TARGETING::get_huid(i_target) );
            }
            else
            {
                // Set Boot Side 1 by setting bit for side 1
                l_targetReg |= l_sbeBootSelectMask;

                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"updateSbeBootSeeprom(): l_read_reg=0x%.8X "
                           "set SBE boot side 1 for proc=%.8llX",
                           l_targetReg,
                           TARGETING::get_huid(i_target) );
            }

            // Write PERV_SB_CS_FSI 0x2808 back into target proc
            err = DeviceFW::deviceOp(
                         DeviceFW::WRITE,
                         i_target,
                         &l_targetReg,
                         l_opSize,
                         DEVICE_FSI_ADDRESS(PERV_SB_CS_FSI_BYTE) );
            if( err )
            {
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"updateSbeBootSeeprom(): putCfamRegister, "
                           "PERV_SB_CS_FSI (0x%.4X), proc target = %.8X, "
                           "RC=0x%X, PLID=0x%lX",
                           PERV_SB_CS_FSI, // 0x2808
                           TARGETING::get_huid(i_target),
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

        }while(0);

        TRACFCOMP( g_trac_sbe, EXIT_MRK"updateSbeBootSeeprom()" );

        return err;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t sbeLoadHcode(char*& o_hcodeAddr)
    {
        errlHndl_t l_errl = NULL;
        PNOR::SectionInfo_t l_info;

        do
        {

            // Get HCODE PNOR section info from PNOR RP
            l_errl = PNOR::getSectionInfo( PNOR::HCODE, l_info );
            if( l_errl )
            {
                //No need to commit error here, it gets handled later
                //just break out to escape this function
                break;
            }

            o_hcodeAddr = reinterpret_cast<char*>(l_info.vaddr);

            TRACUCOMP( g_trac_sbe,
                    ERR_MRK"sbeLoadHcode() - Error from "
                    "HCODE addr = 0x%p ",
                    o_hcodeAddr);

        } while ( 0 );

        return  l_errl;
    }

    errlHndl_t getSeepromVersions(sbeTargetState_t& io_sbeState)
    {
        errlHndl_t l_err = nullptr;
        bool l_sbeSupportedSeepromReadOp = true;
        bool l_errFoundDuringChipOp = false;

        //Make sure that io_sbeState had valid information
        assert(io_sbeState.target != NULL, "target member variable not set on io_sbeState");
        do
        {
            //Get Current (boot) Side
            sbeSeepromSide_t tmp_cur_side = SBE_SEEPROM_INVALID;
            l_err = getSbeBootSeeprom(io_sbeState.target, tmp_cur_side);
            if(l_err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromVersions() - Error "
                          "determining which seeprom we booted on. Exiting function");
                break;
            }
            bool l_sideZeroActive = (tmp_cur_side == SBE_SEEPROM0);
            /*******************************************/
            /*  Get SEEPROM 0 SBE Version Information  */
            /*******************************************/

            // If the current seeprom is side 0 then attempt read via chipOp
            // TODO RTC:186269 Remove forced I2C path when simics issue is resolved
            if (l_sideZeroActive &&
                !Util::isSimicsRunning())
            {
                l_err = getSeepromSideVersionViaChipOp(io_sbeState.target,
                                            io_sbeState.seeprom_0_ver,
                                            l_sbeSupportedSeepromReadOp);

                if(l_err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromVersions() - Error "
                            "getting SBE Information from SEEPROM 0 (Primary) via ChipOp "
                            "RC=0x%X, PLID=0x%lX, will attempt I2C read instead",
                            ERRL_GETRC_SAFE(l_err),
                            ERRL_GETPLID_SAFE(l_err));
                    //Commit error as informational and attempt reading via i2c
                    l_errFoundDuringChipOp = true;
                    l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    l_err->collectTrace(SBE_COMP_NAME, 256);
                    l_err->collectTrace(SBEIO_COMP_NAME, 256);
                    errlCommit( l_err, SBEIO_COMP_ID );
                }
                else if(!l_sbeSupportedSeepromReadOp)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromVersions() - Error "
                    "getting SBE Information from SEEPROM 0 (Primary) via ChipOp. The "
                    "SBE firmware level does not support readSeeprom Op, will attempt I2C read instead");
                }
                else
                {
                    TRACDBIN(g_trac_sbe, "getSeepromVersions found via ChipOp -spA",
                            &(io_sbeState.seeprom_0_ver),
                            sizeof(sbeSeepromVersionInfo_t));
                }
            }

            //If side 0 is not active or there was an error trying to read
            //the primary via chipOp, then try reading via I2C
            // TODO RTC:186269 Remove forced I2C path when simics issue is resolved
            if(!l_sideZeroActive || !l_sbeSupportedSeepromReadOp ||
                l_errFoundDuringChipOp || Util::isSimicsRunning())
            {

                l_err = getSeepromSideVersionViaI2c(io_sbeState.target,
                                            EEPROM::SBE_PRIMARY,
                                            io_sbeState.seeprom_0_ver,
                                            io_sbeState.seeprom_0_ver_ECC_fail);

                if(l_err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromVersions() - Error "
                            "getting SBE Information from SEEPROM 0 (Primary) via I2C, "
                            "RC=0x%X, PLID=0x%lX",
                            ERRL_GETRC_SAFE(l_err),
                            ERRL_GETPLID_SAFE(l_err));
                    break;
                }

                TRACDBIN(g_trac_sbe, "getSeepromVersions found via I2C -spA",
                        &(io_sbeState.seeprom_0_ver),
                        sizeof(sbeSeepromVersionInfo_t));
            }


            /*******************************************/
            /*  Get SEEPROM 1 SBE Version Information  */
            /*******************************************/

            //If side 1 is active, then attempt read via chipOp
            //Note that there is no reason to attempt chipOp on backup if it failed
            //on the primary.
            // TODO RTC:186269 Remove forced I2C path when simics issue is resolved
            if (!l_sideZeroActive && l_sbeSupportedSeepromReadOp &&
                !l_errFoundDuringChipOp && !Util::isSimicsRunning() )
            {
                l_err = getSeepromSideVersionViaChipOp(io_sbeState.target,
                                                    io_sbeState.seeprom_1_ver,
                                                    l_sbeSupportedSeepromReadOp);

                if(l_err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromVersions() - Error "
                            "getting SBE Information from SEEPROM 1 (Backup) via Chipop, "
                            "RC=0x%X, PLID=0x%lX, will attempt I2C read instead",
                            ERRL_GETRC_SAFE(l_err),
                            ERRL_GETPLID_SAFE(l_err));
                    //Commit error as informational and attempt reading via i2c
                    l_errFoundDuringChipOp = true;
                    l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    l_err->collectTrace(SBE_COMP_NAME, 256);
                    l_err->collectTrace(SBEIO_COMP_NAME, 256);
                    errlCommit( l_err, SBEIO_COMP_ID );
                }
                else if(!l_sbeSupportedSeepromReadOp)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromVersions() - Error "
                                "getting SBE Information from SEEPROM 1 (Backup) via ChipOp. The "
                                "SBE firmware level does not support readSeeprom Op, will attempt I2C read instead");
                }
                else
                {
                    TRACDBIN(g_trac_sbe, "getSeepromVersions found via Chipop -spB",
                            &(io_sbeState.seeprom_1_ver),
                            sizeof(sbeSeepromVersionInfo_t));
                }
            }

            //If side 1 is not active, or there was an error trying to read
            //the primary via chipOp, then try reading via I2C
            // TODO RTC:186269 Remove forced I2C path when simics issue is resolved
            if(l_sideZeroActive || !l_sbeSupportedSeepromReadOp ||
                l_errFoundDuringChipOp || Util::isSimicsRunning() )
            {
                l_err = getSeepromSideVersionViaI2c(io_sbeState.target,
                                            EEPROM::SBE_BACKUP,
                                            io_sbeState.seeprom_1_ver,
                                            io_sbeState.seeprom_1_ver_ECC_fail);

                if(l_err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromVersions() - Error "
                            "getting SBE Information from SEEPROM 1 (Backup) via I2C, "
                            "RC=0x%X, PLID=0x%lX",
                            ERRL_GETRC_SAFE(l_err),
                            ERRL_GETPLID_SAFE(l_err));
                    break;
                }

                TRACDBIN(g_trac_sbe, "getSeepromVersions-spB found via I2C",
                        &(io_sbeState.seeprom_1_ver),
                        sizeof(sbeSeepromVersionInfo_t));
            }
        }while(0);

        return l_err;
    }

    /////////////////////////////////////////////////////////////////////
    errlHndl_t getSbeInfoState(sbeTargetState_t& io_sbeState)
    {

        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"getSbeInfoState(): HUID=0x%.8X",
                   TARGETING::get_huid(io_sbeState.target));


        errlHndl_t err = nullptr;
        void *sbeHbblImgPtr = nullptr;

        // Clear build information
        io_sbeState.new_imageBuild.buildDate = 0;
        io_sbeState.new_imageBuild.buildTime = 0;
        memset(io_sbeState.new_imageBuild.buildTag,
               '\0',
               sizeof(io_sbeState.new_imageBuild.buildTag) );

        do{

            /***********************************************/
            /*  Determine which SEEPROM System Booted On   */
            /***********************************************/
            //Get Current (boot) Side
            sbeSeepromSide_t tmp_cur_side = SBE_SEEPROM_INVALID;
            err = getSbeBootSeeprom(io_sbeState.target, tmp_cur_side);
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                           "Error returned from getSbeBootSeeprom(), "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
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

            /************************************************************/
            /*  Set Target Properties (target_is_master previously set) */
            /************************************************************/
            io_sbeState.ec = io_sbeState.target->getAttr<TARGETING::ATTR_EC>();

            /*******************************************/
            /*  Get SBE SEEPROM Version Information    */
            /*******************************************/
            err = getSeepromVersions(io_sbeState);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                "Error getting SBE Version from SEEPROMs, "
                "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                           break;
            }

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
                           "Error getting SBE Version from PNOR, "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }
            else
            {
                TRACFCOMP( g_trac_sbe, "getSbeInfoState() - "
                           "sbePnorPtr=%p, sbePnorImageSize=0x%08X (%d)",
                           sbePnorPtr, sbePnorImageSize, sbePnorImageSize);

                // Pull build information from XIP header and trace it
                Util::pullTraceBuildInfo(sbePnorPtr,
                                         io_sbeState.new_imageBuild,
                                         g_trac_sbe);
            }

            // copy tmp_pnorVersion to the main structure
            memcpy ( &io_sbeState.pnorVersion,
                     &tmp_pnorVersion,
                     sizeof(tmp_pnorVersion));


            /*******************************************/
            /*  Get PNOR HBBL Information              */
            /*******************************************/

            // Get HBBL PNOR section info from PNOR RP
            PNOR::SectionInfo_t pnorInfo;
            err = getSectionInfo( PNOR::HB_BOOTLOADER, pnorInfo );
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState: Error calling "
                           "getSectionInfo() rc=0x%.4X",
                           err->reasonCode() );
                break;
            }

            // Create a working copy of HBBL since it may need to be modified
            // and it's not legal to update code partitions
            uint8_t pHbbl[MAX_HBBL_SIZE]={0};
            memcpy(pHbbl,
                   reinterpret_cast<const void*>(pnorInfo.vaddr),
                   sizeof(pHbbl));
            const void* hbblPnorPtr = reinterpret_cast<const void*>(pHbbl);

            // Use max hbbl size and not the PNOR size. The PNOR size can grow
            // to add a secure header, but the code size limit is still 20K.
            TRACFCOMP( g_trac_sbe, "getSbeInfoState() - "
                       "hbblPnorPtr=%p, hbblMaxSize=0x%08X (%d)",
                       hbblPnorPtr, MAX_HBBL_SIZE, MAX_HBBL_SIZE);

            /*******************************************/
            /*  Update the HW Key Hash in the HBBL     */
            /*******************************************/
            // Create an 'all-zero' hash for comparison now and then use it
            // to save hash being put into image for comparison later
            SHA512_t tmp_hash = {0};

            if ( !g_do_hw_keys_hash_transition )
            {
                // Use the HW Key Hash that the system used to boot
                SHA512_t sys_hash = {0};
                SECUREBOOT::getHwKeyHash(sys_hash);

                // Look for 'all-zero' system hash
                if ( memcmp(sys_hash, tmp_hash, sizeof(SHA512_t)) == 0 )
                {
                    // System hash is all zeros, so use HW Key Hash in HBBL
                    // section from PNOR
                    TRACFCOMP( g_trac_sbe, "getSbeInfoState() - Using HW Key "
                               "Hash from HBBL section of PNOR: 0x%8X",
                               sha512_to_u32(
                                   reinterpret_cast<uint8_t*>(
                                       reinterpret_cast<uint64_t>(hbblPnorPtr) +
                                       HBBL_HW_KEY_HASH_LOCATION)));

                    // Save hash for comparison later
                    memcpy (tmp_hash,
                            reinterpret_cast<uint8_t*>(
                                       reinterpret_cast<uint64_t>(hbblPnorPtr) +
                                       HBBL_HW_KEY_HASH_LOCATION),
                            sizeof(SHA512_t));
                }
                else
                {
                    // Use non-zero system hash
                    TRACFCOMP( g_trac_sbe, "getSbeInfoState() - Using System "
                               "HW Key Hash: 0x%.8X",
                               sha512_to_u32(sys_hash));

                    memcpy (reinterpret_cast<void*>(
                                reinterpret_cast<uint64_t>(hbblPnorPtr) +
                                HBBL_HW_KEY_HASH_LOCATION),
                            sys_hash,
                            sizeof(SHA512_t));

                    // Save hash for comparison later
                    memcpy (tmp_hash,
                            sys_hash,
                            sizeof(SHA512_t));
                }
            }
            else
            {
                // Use the Secureboot Transition HW Key Hash found earlier
                TRACFCOMP( g_trac_sbe, "getSbeInfoState() - Using Secureboot "
                           "Transition HW Key Hash: 0x%.8X",
                           sha512_to_u32(g_hw_keys_hash_transition_data));

                memcpy (reinterpret_cast<void*>(
                            reinterpret_cast<uint64_t>(hbblPnorPtr) +
                            HBBL_HW_KEY_HASH_LOCATION),
                        g_hw_keys_hash_transition_data,
                        sizeof(SHA512_t));

                // Save hash for comparison later
                memcpy (tmp_hash,
                        g_hw_keys_hash_transition_data,
                        sizeof(SHA512_t));
            }

            /*******************************************/
            /*  Append HBBL Image from PNOR to SBE     */
            /*  Image from PNOR                        */
            /*******************************************/
            uint32_t sbeHbblImgSize =
                static_cast<uint32_t>(sbePnorImageSize + MAX_HBBL_SIZE);

            // copy SBE image from PNOR to memory
            sbeHbblImgPtr = (void*)SBE_HBBL_IMG_VADDR;
            memcpy ( sbeHbblImgPtr,
                     sbePnorPtr,
                     sbePnorImageSize);

            err = appendHbblToSbe(const_cast<void*>(hbblPnorPtr), // HBBL Image to append
                                  MAX_HBBL_SIZE, // Size of HBBL Image
                                  sbeHbblImgPtr,     // SBE, HBBL Image
                                  sbeHbblImgSize);   // Available/used

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                           "Error from procAppendHbblToSbe(), "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            /*******************************************/
            /*  Append RINGOVD Image from PNOR to SBE  */
            /*******************************************/
            // Check if we have a valid ring override section and
            // append it in if so
            uint32_t l_ovdImgSize =
              static_cast<uint32_t>(sbeHbblImgSize+RING_OVD_SIZE);
            err = ringOvd(sbeHbblImgPtr,l_ovdImgSize);
            if(err)
            {
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"procCustomizeSbeImg(): "
                           "Error in call to ringOvd!");
                break;
            }

            //If it's larger than the original size then we added some overrides
            if(l_ovdImgSize > sbeHbblImgSize)
            {
                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"procCustomizeSbeImg(): We added some "
                           "ring overrides, initial image size:%u "
                           "new image size:%u",
                           sbeHbblImgSize, l_ovdImgSize);

                // Set new size for use below
                sbeHbblImgSize = l_ovdImgSize;
            }

            // Pass in the larger of our custom size or MAX_SEEPROM_IMAGE_SIZE
            // -- p9_xip_customize is expecting at least MAX_SEEPROM_IMAGE_SIZE
            sbeHbblImgSize = std::max(sbeHbblImgSize, MAX_SEEPROM_IMAGE_SIZE);

            /*******************************************/
            /*  Customize SBE/HBBL Image and           */
            /*  Calculate CRC of the image             */
            /*******************************************/
            size_t sbeImgSize = 0;


            // get a pointer to the hcode for the .overlays
            char* l_hCodeAddr = NULL;

            err = sbeLoadHcode(l_hCodeAddr);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"ge() - "
                        "Error from sbeLoadHcode(), "
                        "RC=0x%X, PLID=0x%lX",
                        ERRL_GETRC_SAFE(err),
                        ERRL_GETPLID_SAFE(err));
                break;
            }


            void * pCustomizedBfr = reinterpret_cast<void*>(SBE_IMG_VADDR);

            err = procCustomizeSbeImg(io_sbeState.target,
                                      l_hCodeAddr,    // HCODE in memory
                                      sbeHbblImgPtr,  //SBE, HBBL in memory
                                      sbeHbblImgSize,
                                      pCustomizedBfr,  //destination
                                      sbeImgSize);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                           "Error from procCustomizeSbeImg(), "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            // Verify that HW Key Hash is included in customized image
            SHA512_t hash = {0};
            err = getHwKeyHashFromSbeImage(io_sbeState.target,  // ignored
                                           EEPROM::SBE_PRIMARY, // ignored
                                           hash,
                                           pCustomizedBfr);

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                           "Error from getHwKeyHashFromSbeImage(), "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            // Verify that the HW Key Hash is the same hash used earlier
            if ( memcmp(hash, tmp_hash, sizeof(SHA512_t)) != 0 )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - Error: "
                           "HW Key Hash in customized image 0x%.8X doesn't "
                           "match expected hash 0x%.8X for proc=0x%X",
                           sha512_to_u32(hash),
                           sha512_to_u32(tmp_hash),
                           TARGETING::get_huid(io_sbeState.target));

                /*@
                 * @errortype
                 * @moduleid         SBE_GET_TARGET_INFO_STATE
                 * @reasoncode       SBE_MISMATCHED_HW_KEY_HASH
                 * @userdata1        Target HUID
                 * @userdata2[0:31]  HW Key Hash found in Customized SBE Image
                 * @userdata2[32:63] Expected HW Key Hash
                 * @devdesc          Unexpected HW Key Hash found in SBE Image
                 * @custdesc         A problem occurred while updating processor
                 *                   boot code.
                 */
                err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    SBE_GET_TARGET_INFO_STATE,
                                    SBE_MISMATCHED_HW_KEY_HASH,
                                    TARGETING::get_huid(io_sbeState.target),
                                    TWO_UINT32_TO_UINT64(
                                      sha512_to_u32(hash),
                                      sha512_to_u32(tmp_hash)));

                err->collectTrace(SBE_COMP_NAME);
                err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                          HWAS::SRCI_PRIORITY_HIGH );

                break;
            }


            // save off the hbbl id and remove it from the image
            void * pSearchBfr = pCustomizedBfr;
            uint32_t searchSize = sbePnorImageSize;
            void * pHbblIdStringBfr;

            err = locateHbblIdStringBfr( pSearchBfr,
                                         searchSize,
                                         pHbblIdStringBfr );
            if(err)
            {
                //If string search failure, commit the error and move
                //   to the next proc
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSbeInfoState() - "
                           "Error searhing for HBBL ID string, "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            // save off the hbbl ID string and clear the source
            uint8_t tempHbblStringIdBfr[128];
            memcpy( &tempHbblStringIdBfr[0],
                    pHbblIdStringBfr,
                    sizeof(tempHbblStringIdBfr) );

            memset( pHbblIdStringBfr,
                    0,
                    sizeof(tempHbblStringIdBfr) );

            // Calculate Data CRC
            io_sbeState.customizedImage_size = sbeImgSize;
            io_sbeState.customizedImage_crc =
                            Util::crc32_calc(pCustomizedBfr,
                                             sbeImgSize) ;

            TRACFCOMP( g_trac_sbe, "getSbeInfoState() - procCustomizeSbeImg(): "
                       "maxSize=0x%X, actSize=0x%X, crc=0x%X",
                       MAX_SEEPROM_IMAGE_SIZE, sbeImgSize,
                       io_sbeState.customizedImage_crc);

            // restore the hbbl ID string
            memcpy( pHbblIdStringBfr,
                    &tempHbblStringIdBfr[0],
                    sizeof(tempHbblStringIdBfr) );

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
                           "Error reading version from MVPD, "
                           "RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
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

        }while(0);

        if(err && (io_sbeState.new_imageBuild.buildDate != 0) &&
           (io_sbeState.new_imageBuild.buildTime != 0))
        {
            err->addFFDC(ERRL_COMP_ID,
                         &(io_sbeState.new_imageBuild),
                         sizeof(io_sbeState.new_imageBuild),
                         0,                   // Version
                         ERRL_UDT_BUILD,      // parser for XIP image build info
                         false );             // merge
        }

        return err;

    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t getSeepromSideVersionViaI2c(TARGETING::Target* i_target,
                                     EEPROM::eeprom_chip_types_t i_seepromSide,
                                     sbeSeepromVersionInfo_t& o_info,
                                     bool& o_seeprom_ver_ECC_fail)
    {
        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"getSeepromSideVersionViaI2c(): HUID=0x%.8X, side:%d",
                   TARGETING::get_huid(i_target), i_seepromSide);

        errlHndl_t err = NULL;
        PNOR::ECC::eccStatus eccStatus = PNOR::ECC::CLEAN;
        o_seeprom_ver_ECC_fail = false;

        // Set these variables to the read out the max struct size
        // Supported version 1 is a subset of supported version 2
        size_t sbeInfoSize = sizeof(sbeSeepromVersionInfo_t);
        size_t sbeInfoSize_ECC = (sbeInfoSize*9)/8;
        uint8_t * tmp_data_ECC = static_cast<uint8_t*>(
                                        malloc(sbeInfoSize_ECC));

        do{

            /***********************************************/
            /*  Read SBE Version SBE Version Information   */
            /***********************************************/
            // Clear Buffer
            memset( tmp_data_ECC, 0, sbeInfoSize_ECC );

            //Read SBE Versions
            err = deviceRead( i_target,
                              tmp_data_ECC,
                              sbeInfoSize_ECC,
                              DEVICE_EEPROM_ADDRESS(
                                            i_seepromSide,
                                            SBE_VERSION_SEEPROM_ADDRESS));

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromSideVersionViaI2c() - "
                           "Error reading SBE Version from Seeprom 0x%X, "
                           "HUID=0x%.8X, RC=0x%X, PLID=0x%lX",
                           i_seepromSide, TARGETING::get_huid(i_target),
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            TRACDBIN(g_trac_sbe,
                     "getSeepromSideVersionViaI2c() - tmp_data_ECC",
                     tmp_data_ECC,
                     sbeInfoSize_ECC);


            // Clear destination
            memset( &o_info, 0, sizeof(o_info) );


            // Initially only look at the first 8-Bytes which should include
            // the struct version value
            // Remove ECC
            eccStatus = removeECC(tmp_data_ECC,
                                  reinterpret_cast<uint8_t*>(&o_info),
                                  8,
                                  SBE_VERSION_SEEPROM_ADDRESS,
                                  SBE_SEEPROM_SIZE);

            TRACUCOMP( g_trac_sbe, "getSeepromSideVersionViaI2c(): First 8-Bytes: "
                       "eccStatus=%d, version=0x%X, data_crc=0x%X",
                       eccStatus, o_info.struct_version, o_info.data_crc);


            if ( STRUCT_VERSION_CHECK(o_info.struct_version) )
            {
                // Supported Versions - set size variable to remove ECC
                sbeInfoSize = SBE_SEEPROM_STRUCT_SIZES[o_info.struct_version];
                sbeInfoSize_ECC = (sbeInfoSize*9)/8;

            }
            else
            {
                // Unsupported versions - ignoring any ECC errors
                TRACFCOMP( g_trac_sbe, "getSeepromSideVersionViaI2c(): Unsupported "
                           "Struct Version=0x%X, ignoring any eccStatus=%d",
                           o_info.struct_version, eccStatus);

                break;
            }

            // Remove ECC for full SBE Version struct
            eccStatus = PNOR::ECC::CLEAN;
            eccStatus = removeECC(tmp_data_ECC,
                                  reinterpret_cast<uint8_t*>(&o_info),
                                  sbeInfoSize,
                                  SBE_VERSION_SEEPROM_ADDRESS,
                                  SBE_SEEPROM_SIZE);

            TRACFCOMP( g_trac_sbe, "getSeepromSideVersionViaI2c(): eccStatus=%d, "
                       "sizeof o_info/sI=%d, sI_ECC=%d, origin golden=%i",
                       eccStatus, sbeInfoSize, sbeInfoSize_ECC, o_info.origin);

            // Handle Uncorrectable ECC - no error log:
            // clear data and set o_seeprom_ver_ECC_fail=true
            if ( eccStatus == PNOR::ECC::UNCORRECTABLE )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getSeepromSideVersionViaI2c() - ECC "
                           "ERROR: Handled. eccStatus=%d, side=%d, sizeof "
                           "o_info/sI=%d, sI_ECC=%d",
                           eccStatus, i_seepromSide, sbeInfoSize,
                           sbeInfoSize_ECC);

                memset( &o_info, 0, sizeof(o_info));
                o_seeprom_ver_ECC_fail = true;

                TRACUCOMP( g_trac_sbe, "getSeepromSideVersionViaI2c(): clearing out "
                "version data (o_info) for side %d and returning "
                "o_seeprom_ver_ECC_fail as true (%d)",
                i_seepromSide, o_seeprom_ver_ECC_fail);
            }

            TRACDBIN(g_trac_sbe,
                     "getSeepromSideVersionViaI2c: data (no ECC)",
                     &o_info,
                     sizeof(o_info));

        }while(0);

        // Free allocated memory
        free(tmp_data_ECC);


        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"getSeepromSideVersionViaI2c: o_seeprom_ver_ECC_fail=%d",
                   o_seeprom_ver_ECC_fail );

        return err;
    }

errlHndl_t getSeepromSideVersionViaChipOp(TARGETING::Target* i_target,
                                          sbeSeepromVersionInfo_t& o_info,
                                          bool& o_opSupported)
    {
        errlHndl_t l_err = nullptr;

        // Set these variables to the read out the max struct size
        // Supported version 1 is a subset of supported version 2
        size_t sbeInfoSize = sizeof(sbeSeepromVersionInfo_t);

        //Set up the buffer which the SBE will copy the version info to
        //Add 127 bytes to the buffer length so we can guarantee a 128 byte aligned addr
        //Note that the SBE_SEEPROM_VERSION_READ_SIZE is 3 * 128 Bytes to be cacheline aligned
        uint8_t * l_seepromReadBuffer = static_cast<uint8_t*>(
                                               malloc(SBE_SEEPROM_VERSION_READ_SIZE + 127 ));

        uint64_t l_seepromReadBufferAligned = ALIGN_X(reinterpret_cast<uint64_t>(l_seepromReadBuffer),
                                                      128);

        do{

            /***********************************************/
            /*  Read SBE Version SBE Version Information   */
            /***********************************************/
            // Clear Buffer
            memset( reinterpret_cast<uint8_t*>(l_seepromReadBufferAligned),
                    0,
                    SBE_SEEPROM_VERSION_READ_SIZE );

            // Clear destination
            memset( &o_info, 0, sizeof(o_info) );

            l_err = SBEIO::sendPsuReadSeeprom(i_target,
                               END_OF_SEEPROM_MINUS_READ_SIZE,
                               SBE_SEEPROM_VERSION_READ_SIZE,
                               mm_virt_to_phys(reinterpret_cast<void*>(l_seepromReadBufferAligned)),
                               o_opSupported);

            if(!l_err && o_opSupported)
            {

                TRACDBIN(g_trac_sbe,
                        "getSeepromSideVersionViaChipOp() - l_seepromReadBufferAligned",
                        reinterpret_cast<uint8_t*>(l_seepromReadBufferAligned),
                        SBE_SEEPROM_VERSION_READ_SIZE);

                // Initially only look at the first 8-Bytes which should include
                // the struct version value
                memcpy ( &o_info, reinterpret_cast<void*>(l_seepromReadBufferAligned), 8);

                if ( STRUCT_VERSION_CHECK(o_info.struct_version) )
                {
                    // Supported Versions - set size variable
                    sbeInfoSize = SBE_SEEPROM_STRUCT_SIZES[o_info.struct_version];
                }
                else
                {
                    // Unsupported versions
                    TRACFCOMP( g_trac_sbe, "getSeepromSideVersion(): Unsupported "
                            "Struct Version=0x%X",
                            o_info.struct_version);

                    break;
                }

                //Copy the sbeInfo data into the struct that was passed into the function
                memcpy ( &o_info, reinterpret_cast<void*>(l_seepromReadBufferAligned), sbeInfoSize);

                TRACDBIN(g_trac_sbe,
                        "getSeepromSideVersionViaChipOp: data (no ECC)",
                        &o_info,
                        sizeof(o_info));
            }
            else
            {
                TRACFCOMP( g_trac_sbe,
                        "Error reading seeprom via chipOp, either the Op isnt supported by SBE or"
                        " something else went wrong, not going to attempt to parse results");
            }

        }while(0);

        //Free up the buffer before returning no matter what
        free(l_seepromReadBuffer);
        l_seepromReadBuffer = nullptr;

        TRACUCOMP( g_trac_sbe,
                   EXIT_MRK"getSeepromSideVersionViaChipOp" );
        return l_err;
    }


/////////////////////////////////////////////////////////////////////
    errlHndl_t updateSeepromSide(sbeTargetState_t& io_sbeState)
    {
        TRACUCOMP( g_trac_sbe,
                   ENTER_MRK"updateSeepromSide(): HUID=0x%.8X, side=%d",
                   TARGETING::get_huid(io_sbeState.target),
                   io_sbeState.seeprom_side_to_update);

#ifdef CONFIG_CONSOLE
        CONSOLE::displayf(SBE_COMP_NAME,
                          "System Performing SBE Update for PROC %d, side %d",
                        io_sbeState.target->getAttr<TARGETING::ATTR_POSITION>(),
                        io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY ? SBE_SEEPROM0 : SBE_SEEPROM1);
#endif

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
            uint8_t* sbeInfoEnd = sbeInfo_data + sbeInfoSize;
            for (uint64_t* p = reinterpret_cast<uint64_t*>(sbeInfo_data);
                 p < reinterpret_cast<uint64_t*>(sbeInfoEnd);
                 p++)
            {
                *p = SBE_SEEPROM_STRUCT_INVALID;
            }

            // Inject ECC to Data
            memset( sbeInfo_data_ECC, 0, sbeInfoSize_ECC);
            injectECC(sbeInfo_data,
                      sbeInfoSize,
                      SBE_VERSION_SEEPROM_ADDRESS,
                      SBE_SEEPROM_SIZE,
                      sbeInfo_data_ECC);

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
                           "Writing SBE Version Info: HUID=0x%.8X, side=%d, "
                           "RC=0x%X, PLID=0x%lX",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.seeprom_side_to_update,
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
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
                               "side=%d, RC=0x%X, PLID=0x%lX",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.seeprom_side_to_update,
                               ERRL_GETRC_SAFE(err),
                               ERRL_GETPLID_SAFE(err));
                    break;
                }

                // Compare ECC data
                rc_readBack_ECC_memcmp = memcmp( sbeInfo_data_ECC,
                                                 sbeInfo_data_ECC_readBack,
                                                 sbeInfoSize_ECC);

                // Remove ECC
                eccStatus = removeECC( sbeInfo_data_ECC_readBack,
                                       sbeInfo_data_readBack,
                                       sbeInfoSize,
                                       SBE_VERSION_SEEPROM_ADDRESS,
                                       SBE_SEEPROM_SIZE);

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
                               "ERROR or Data Miscompare On SBE Version Read "
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
                     *               SBE Version Information
                     * @custdesc     ECC or Data Miscompare Fail Reading Back
                     *               Self Boot Engine (SBE) Version Information
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

            // Inject ECC
            // clear out back half of page block to use as temp space
            // for ECC injected SBE Image.
            rc = mm_remove_pages(RELEASE,
                                 reinterpret_cast<void*>(SBE_ECC_IMG_VADDR),
                                 SBE_ECC_IMG_MAX_SIZE);
            if( rc )
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - Error "
                           "from mm_remove_pages : rc=%d,  HUID=0x%.8X, "
                           "ECC_VADDR=0x%.16X, eccSize=0x%.8X.",
                           rc, TARGETING::get_huid(io_sbeState.target),
                           SBE_ECC_IMG_VADDR,
                           SBE_ECC_IMG_MAX_SIZE );
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
            size_t sbeEccImgSize = setECCSize(sbeImgSize);

            // Check if assert below will fail and values should be traced
            if(sbeEccImgSize > SBE_ECC_IMG_MAX_SIZE)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide(): assert "
                           "values eccSize=0x%.8X <= ECC_MAX_SIZE=0x%.8X",
                           sbeEccImgSize,
                           SBE_ECC_IMG_MAX_SIZE );
            }

            assert(sbeEccImgSize <= SBE_ECC_IMG_MAX_SIZE,
                   "updateSeepromSide() SBE Image with ECC too large");

            TRACUCOMP( g_trac_sbe, INFO_MRK"updateSeepromSide(): "
                       "SBE_VADDR=0x%.16X, ECC_VADDR=0x%.16X, size=0x%.8X, "
                       "eccSize=0x%.8X, UPDATE_END=0x%.16X, UPDATE_SIZE=0x%.8X",
                       SBE_IMG_VADDR,
                       SBE_ECC_IMG_VADDR,
                       sbeImgSize,
                       sbeEccImgSize,
                       VMM_VADDR_SBE_UPDATE_END,
                       VMM_SBE_UPDATE_SIZE );

            injectECC(reinterpret_cast<uint8_t*>(SBE_IMG_VADDR),
                      sbeImgSize,
                      SBE_IMAGE_SEEPROM_ADDRESS,
                      SBE_SEEPROM_SIZE,
                      reinterpret_cast<uint8_t*>(SBE_ECC_IMG_VADDR));

            TRACDBIN(g_trac_sbe,"updateSeepromSide()-start of IMG - no ECC",
                     reinterpret_cast<void*>(SBE_IMG_VADDR), 0x80);
            TRACDBIN(g_trac_sbe,"updateSeepromSide()-start of IMG - ECC",
                     reinterpret_cast<void*>(SBE_ECC_IMG_VADDR), 0x80);


            //Quiesce the SBE before writing current SBE
            if ( ( ( io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY )
                   &&
                   ( io_sbeState.cur_seeprom_side == SBE_SEEPROM0 ) )
                 ||
                 ( ( io_sbeState.seeprom_side_to_update == EEPROM::SBE_BACKUP )
                   &&
                   ( io_sbeState.cur_seeprom_side == SBE_SEEPROM1 ) ) )
            {
                err = SBEIO::sendPsuQuiesceSbe(io_sbeState.target);

                if(err)
                {
                    TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - Error "
                               "quiescing SBE.  RC=0x%X, PLID=0x%lX",
                               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));
                    break;
                }
            }

            //Write new data to seeprom
            TRACFCOMP( g_trac_sbe, INFO_MRK"updateSeepromSide(): Write New "
                       "SBE Image for Target 0x%X to Seeprom %d",
                       TARGETING::get_huid(io_sbeState.target),
                       io_sbeState.seeprom_side_to_update );

            //Write image to indicated side
            err = deviceWrite(io_sbeState.target,
                              reinterpret_cast<void*>(SBE_ECC_IMG_VADDR),
                              sbeEccImgSize,
                              DEVICE_EEPROM_ADDRESS(
                                            io_sbeState.seeprom_side_to_update,
                                            SBE_IMAGE_SEEPROM_ADDRESS));

            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"updateSeepromSide() - Error "
                           "writing new SBE image to size=%d. HUID=0x%.8X."
                           "SBE_VADDR=0x%.16X, ECC_VADDR=0x%.16X, size=0x%.8X, "
                           "eccSize=0x%.8X, EEPROM offset=0x%X, "
                           "RC=0x%X, PLID=0x%lX",
                           io_sbeState.seeprom_side_to_update,
                           TARGETING::get_huid(io_sbeState.target),
                           SBE_IMG_VADDR, SBE_ECC_IMG_VADDR, sbeImgSize,
                           sbeEccImgSize, SBE_IMAGE_SEEPROM_ADDRESS,
                           ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err));
                break;
            }

            /*******************************************/
            /*  Update SBE Version Information         */
            /*******************************************/

            // The new version has already been created
            memcpy(sbeInfo_data, &io_sbeState.new_seeprom_ver, sbeInfoSize);

            // Inject ECC to Data
            memset( sbeInfo_data_ECC, 0, sbeInfoSize_ECC);
            injectECC(sbeInfo_data,
                      sbeInfoSize,
                      SBE_VERSION_SEEPROM_ADDRESS,
                      SBE_SEEPROM_SIZE,
                      sbeInfo_data_ECC);

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
                           "Writing SBE Version Info: HUID=0x%.8X, side=%d, "
                           "RC=0x%X, PLID=0x%lX",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.seeprom_side_to_update,
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                break;
            }

            // Successful update if we get here, so update internal code
            // structure with the new version information
            memcpy( io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY
                    ? &io_sbeState.seeprom_0_ver : &io_sbeState.seeprom_1_ver,
                    &io_sbeState.new_seeprom_ver,
                    sbeInfoSize );

            // Also update with new Build date, time, and tag for MVPD
            memcpy( io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY
                    ? &io_sbeState.mvpdSbKeyword.seeprom_0_build
                    : &io_sbeState.mvpdSbKeyword.seeprom_1_build,
                    &io_sbeState.new_imageBuild,
                    sizeof(Util::imageBuild_t) );
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

#ifdef CONFIG_SBE_UPDATE_SEQUENTIAL

        // If no error and a key transition in progress, recursively call this
        // function for the other SEEPROM
        if ( ( err == nullptr ) &&
             ( io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY ) &&
             ( g_do_hw_keys_hash_transition) )
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

#ifdef CONFIG_SBE_UPDATE_INDEPENDENT
        //If MFG flag is set to indicate update both side of SBE
        //Update both sides of SBE - even in indepent mode
        if (g_update_both_sides)
        {
            // If no error, recursively call this function for the other SEEPROM
            if ( ( err == NULL ) &&
                 ( io_sbeState.seeprom_side_to_update == EEPROM::SBE_PRIMARY ) )
            {
                io_sbeState.seeprom_side_to_update = EEPROM::SBE_BACKUP;
                TRACFCOMP( g_trac_sbe, "UPDATE_BOTH_SIDES_OF_SBE MNFG Flag indicated, will update both sides" );
                TRACFCOMP( g_trac_sbe,
                           "updateSeepromSide(): Recursively calling itself: "
                           "HUID=0x%.8X, side=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.seeprom_side_to_update);
                 err = updateSeepromSide(io_sbeState);
            }
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
#ifndef CONFIG_SBE_UPDATE_CONSECUTIVE
        bool current_side_isDirty = false;
        bool alt_side_isDirty     = false;
#endif

        bool pnor_check_dirty     = false;
        bool crc_check_dirty      = false;
        bool isSimics_check       = false;

        TARGETING::Target * l_sys = nullptr;

        // Set system_situation - bits defined in sbe_update.H
        uint8_t system_situation = 0x00;

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
                   STRUCT_VERSION_SIMICS )
                 && ( Util::isSimicsRunning() )
               )
            {
                isSimics_check = true;
            }

            if ( ( pnor_check_dirty ||
                   crc_check_dirty )
                 && !isSimics_check )
            {
                seeprom_0_isDirty = true;
#ifdef CONFIG_SBE_UPDATE_CONSECUTIVE
                system_situation |= SITUATION_SIDE_0_DIRTY;
#endif
                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: Seeprom0 "
                           "dirty: pnor=%d, crc=%d (custom=0x%X/s0=0x%X), "
                           "isSimics=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           pnor_check_dirty, crc_check_dirty,
                           io_sbeState.customizedImage_crc,
                           io_sbeState.seeprom_0_ver.data_crc,
                           isSimics_check);
            }
            else
            {
                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: Seeprom0 "
                           "flagged as clean: pnor=%d, crc=%d "
                           "(custom=0x%X/s0=0x%X), isSimics=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           pnor_check_dirty, crc_check_dirty,
                           io_sbeState.customizedImage_crc,
                           io_sbeState.seeprom_0_ver.data_crc,
                           isSimics_check);
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
                   STRUCT_VERSION_SIMICS )
                 && ( Util::isSimicsRunning() )
               )
            {
                isSimics_check = true;
            }

            if ( (pnor_check_dirty ||
                  crc_check_dirty )
                 && !isSimics_check )
            {
                seeprom_1_isDirty = true;
#ifdef CONFIG_SBE_UPDATE_CONSECUTIVE
                system_situation |= SITUATION_SIDE_1_DIRTY;
#endif
                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: Seeprom1 "
                           "dirty: pnor=%d, crc=%d (custom=0x%X/s1=0x%X), "
                           "isSimics=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           pnor_check_dirty, crc_check_dirty,
                           io_sbeState.customizedImage_crc,
                           io_sbeState.seeprom_1_ver.data_crc,
                           isSimics_check);
            }
            else
            {
                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: Seeprom1 "
                           "flagged as clean: pnor=%d, crc=%d "
                           "(custom=0x%X/s1=0x%X), isSimics=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           pnor_check_dirty, crc_check_dirty,
                           io_sbeState.customizedImage_crc,
                           io_sbeState.seeprom_1_ver.data_crc,
                           isSimics_check);
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
#ifndef CONFIG_SBE_UPDATE_CONSECUTIVE
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
#else
            if (io_sbeState.cur_seeprom_side == SBE_SEEPROM1)
            {
                system_situation |= SITUATION_BOOT_SIDE_1;
            }
#endif

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
            if ( ( io_sbeState.update_actions & UPDATE_SBE ) ||
                 ( io_sbeState.update_actions & UPDATE_NEST_FREQ ) )
            {
                memset(&(io_sbeState.new_seeprom_ver),
                       0x0,
                       sizeof(sbeSeepromVersionInfo_t));
                // the above memset also has the side effect of setting the
                // origin field to WORKING_SIDE which is the default

                io_sbeState.new_seeprom_ver.struct_version =
                                            STRUCT_VERSION_LATEST;

                memcpy( &(io_sbeState.new_seeprom_ver.image_version),
                        &(io_sbeState.pnorVersion),
                        SBE_IMAGE_VERSION_SIZE);

                memcpy( &(io_sbeState.new_seeprom_ver.data_crc),
                        &(io_sbeState.customizedImage_crc),
                        sizeof(io_sbeState.new_seeprom_ver.data_crc));

                TARGETING::targetService().getTopLevelTarget( l_sys );
                io_sbeState.new_seeprom_ver.nest_freq_mhz =
                         l_sys->getAttr<TARGETING::ATTR_FREQ_PB_MHZ>();

                // If there was an ECC fail on either SEEPROM, do a read-back
                // Check when writing this information to the SEEPROM
                io_sbeState.new_readBack_check = (
                                io_sbeState.seeprom_0_ver_ECC_fail ||
                                io_sbeState.seeprom_1_ver_ECC_fail);

                TRACFBIN( g_trac_sbe,
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
            //Check if MFG flag set to indicate both sides should be updated
            if (g_update_both_sides)
            {
                decisionTreeForUpdatesSimultaneous(l_actions,
                                                   io_sbeState,
                                                   i_system_situation);
            }
            else
            {
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

                TRACUCOMP( g_trac_sbe,INFO_MRK"SBE Update tgt=0x%X: PNOR Info: "
                           "side-%c, sideId=0x%X, isGolden=%d, hasOtherSide=%d",
                           TARGETING::get_huid(io_sbeState.target),
                           pnor_side_info.side, pnor_side_info.id,
                           pnor_side_info.isGolden,
                           pnor_side_info.hasOtherSide);

                if ( pnor_side_info.isGolden == true )
                {
                    // Nothing to do (covered in istep 6 function)
                    l_actions = CLEAR_ACTIONS;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                            "Booting READ_ONLY SEEPROM pointing at PNOR's "
                            "GOLDEN side. No updates for cur side=%d. Continue "
                            "IPL. (sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                            TARGETING::get_huid(io_sbeState.target),
                            io_sbeState.cur_seeprom_side,
                            i_system_situation, l_actions,
                            io_sbeState.mvpdSbKeyword.flags);
                }
                else if (  ( pnor_side_info.hasOtherSide == false ) &&
                         ( io_sbeState.cur_seeprom_side == READ_ONLY_SEEPROM ) )
                {
                    // Even though current seeprom is not pointing at PNOR's
                    // GOLDEN side, treat like READ_ONLY if booting from
                    // READ_ONLY seeprom and PNOR does not have another side
                    // - No Update (ie, Palmetto configuration)
                    l_actions = CLEAR_ACTIONS;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "Treating cur like READ_ONLY SBE SEEPROM. "
                               "No updates for cur side=%d. Continue IPL. "
                               "(sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions,
                               io_sbeState.mvpdSbKeyword.flags);
                }
                else // proceed to update this side
                {
                    // proceed to update this side
                    TRACUCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "NOT Booting READ_ONLY SEEPROM. Check for update"
                               " on cur side=%d ",
                               TARGETING::get_huid(io_sbeState.target),
                               io_sbeState.cur_seeprom_side);

                    // Check for clean vs. dirty only on cur side
                    if ( i_system_situation & SITUATION_CUR_IS_DIRTY )
                    {
                        //  Update cur side and re-ipl
                        l_actions |= IPL_RESTART;
                        l_actions |= DO_UPDATE;
                        l_actions |= UPDATE_SBE;
                        //even though flags byte not updated
                        l_actions |= UPDATE_MVPD;

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
                }
            }
#elif CONFIG_SBE_UPDATE_SIMULTANEOUS
            decisionTreeForUpdatesSimultaneous(l_actions,
                                               io_sbeState,
                                               i_system_situation);

#elif CONFIG_SBE_UPDATE_SEQUENTIAL

            // On a secure boot key transition, force both sides to update
            if (g_do_hw_keys_hash_transition)
            {
                decisionTreeForUpdatesSimultaneous(l_actions,
                                                   io_sbeState,
                                                   i_system_situation);
            }
            else
            {
                // Updating the SEEPROMs 1-at-a-time
                switch ( i_system_situation )
                {

                ////////////////////////////////////////////////////////////////
                    case ( SITUATION_CUR_IS_TEMP  |
                           SITUATION_CUR_IS_DIRTY |
                           SITUATION_ALT_IS_DIRTY  ) :

                        // 0xE0: cur=temp, cur=dirty, alt=dirty
                        // Treat like 0xC0
                        // not sure why we booted off of temp

                ////////////////////////////////////////////////////////////////
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
                             io_sbeState.mvpdSbKeyword.flags &=
                                 ~PERMANENT_FLAG_MASK
                             : //set bit 0
                             io_sbeState.mvpdSbKeyword.flags |=
                                 PERMANENT_FLAG_MASK;

                        // Update MVPD RE-IPL SEEPROM flag: re-IPL on ALT:
                        ( io_sbeState.alt_seeprom_side == SBE_SEEPROM0 ) ?
                             // clear bit 1
                             io_sbeState.mvpdSbKeyword.flags &=
                                 ~REIPL_SEEPROM_MASK
                             : //set bit 1
                             io_sbeState.mvpdSbKeyword.flags |=
                                 REIPL_SEEPROM_MASK;


                        TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                                   "cur=temp/dirty(%d). Update alt. Re-IPL. "
                                   "Update MVPD flag "
                                   "(sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                                   TARGETING::get_huid(io_sbeState.target),
                                   io_sbeState.cur_seeprom_side,
                                   i_system_situation, l_actions,
                                   io_sbeState.mvpdSbKeyword.flags);


                        break;

                ////////////////////////////////////////////////////////////////
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
                             io_sbeState.mvpdSbKeyword.flags &=
                                 ~PERMANENT_FLAG_MASK
                             : // set bit 0
                             io_sbeState.mvpdSbKeyword.flags |=
                                 PERMANENT_FLAG_MASK;

                        TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                                   "cur=temp/clean(%d), alt=dirty. "
                                   "Update alt. Continue IPL. Update MVPD flag."
                                   "(sit=0x%.2X, act=0x%.8X flags=0x%.2X)",
                                   TARGETING::get_huid(io_sbeState.target),
                                   io_sbeState.cur_seeprom_side,
                                   i_system_situation, l_actions,
                                   io_sbeState.mvpdSbKeyword.flags);

                        break;


                ////////////////////////////////////////////////////////////////
                    case ( SITUATION_CUR_IS_TEMP  |
                           SITUATION_CUR_IS_CLEAN |
                           SITUATION_ALT_IS_CLEAN  ) :

                        // 0x80: cur=temp, cur=clean, alt=clean
                        // Both sides are clean,
                        // Not sure why cur=temp, but do nothing

                        l_actions = CLEAR_ACTIONS;

                        TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                                   "Both sides clean-no updates. cur was temp "
                                   "(%d). Continue IPL. (sit=0x%.2X, "
                                   "act=0x%.8X)",
                                   TARGETING::get_huid(io_sbeState.target),
                                   io_sbeState.cur_seeprom_side,
                                   i_system_situation, l_actions);

                        break;


                ////////////////////////////////////////////////////////////////
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
                             io_sbeState.mvpdSbKeyword.flags &=
                                 ~REIPL_SEEPROM_MASK
                             : // set bit 1
                             io_sbeState.mvpdSbKeyword.flags |=
                                 REIPL_SEEPROM_MASK;

                        // If istep mode, re-IPL bit won't be checked, so also
                        // change perm flag to boot off of alt on next IPL
                        if ( g_istep_mode )
                        {
                            // Update MVPD PERMANENT flag: make alt=perm
                            (io_sbeState.alt_seeprom_side == SBE_SEEPROM0 ) ?
                             // clear bit 0
                             io_sbeState.mvpdSbKeyword.flags &=
                                 ~PERMANENT_FLAG_MASK
                             : //set bit 0
                             io_sbeState.mvpdSbKeyword.flags |=
                                 PERMANENT_FLAG_MASK;

                            TRACFCOMP(g_trac_sbe,INFO_MRK"SBE Update tgt=0x%X: "
                                      "istep mode: update alt to perm, (sit="
                                      "0x%.2X)",
                                      TARGETING::get_huid(io_sbeState.target),
                                      i_system_situation);
                        }

                        TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                                   "cur=perm/dirty(%d), alt=dirty. Update alt. "
                                   "re-IPL. (sit=0x%.2X, act=0x%.8X, "
                                   "flags=0x%.2X)",
                                   TARGETING::get_huid(io_sbeState.target),
                                   io_sbeState.cur_seeprom_side,
                                   i_system_situation, l_actions,
                                   io_sbeState.mvpdSbKeyword.flags);

                        break;


                ////////////////////////////////////////////////////////////////
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
                            TRACFCOMP(g_trac_sbe, INFO_MRK"SBE Update "
                                      "tgt=0x%X: cur=perm/dirty(%d), "
                                      "alt=clean. On our Re-"
                                      "IPL. Call-out SBE code but Continue "
                                      "IPL. (sit=0x%.2X, act=0x%.8X)",
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
                            // Target isn't directly related to fail, but could
                            // be useful to see how far we got before failing.
                            ErrlUserDetailsTarget(io_sbeState.target
                                                  ).addToLog(err);
                            err->collectTrace(SBE_COMP_NAME);
                            err->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                                      HWAS::SRCI_PRIORITY_HIGH);
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
                              io_sbeState.mvpdSbKeyword.flags &=
                                  ~REIPL_SEEPROM_MASK
                              : // set bit 1
                              io_sbeState.mvpdSbKeyword.flags |=
                                  REIPL_SEEPROM_MASK;

                            TRACFCOMP(g_trac_sbe,INFO_MRK"SBE Update tgt=0x%X: "
                                      "cur=perm/dirty(%d), alt=clean. Not our "
                                      "Re-IPL. Update alt and MVPD. re-IPL. "
                                      "(sit=0x%.2X, act=0x%.8X, flags=0x%.2X)",
                                      TARGETING::get_huid(io_sbeState.target),
                                      io_sbeState.cur_seeprom_side,
                                      i_system_situation, l_actions,
                                      io_sbeState.mvpdSbKeyword.flags);

                            break;
                        }

                ////////////////////////////////////////////////////////////////
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


                ////////////////////////////////////////////////////////////////
                    case ( SITUATION_CUR_IS_PERM  |
                           SITUATION_CUR_IS_CLEAN |
                           SITUATION_ALT_IS_CLEAN  ) :

                        // 0x0: cur=perm, cur=clean, alt=clean
                        // Both sides are clean - no updates
                        // Continue IPL
                        l_actions = CLEAR_ACTIONS;

                        TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                                   "Both sides clean-no updates. cur was "
                                   "perm(%d). Continue IPL. (sit=0x%.2X, "
                                   "act=0x%.8X)",
                                   TARGETING::get_huid(io_sbeState.target),
                                   io_sbeState.cur_seeprom_side,
                                   i_system_situation, l_actions);

                        break;

                ////////////////////////////////////////////////////////////////
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
                ////////////////////////////////////////////////////////////////
                //  End of i_system_situation switch statement
                ////////////////////////////////////////////////////////////////

            }

#elif CONFIG_SBE_UPDATE_CONSECUTIVE
            // Updating the SEEPROMs 1-at-a-time (OP systems)

            // Check system situation ignoring perm/temp bit
            switch ( i_system_situation )
            {

            //// 0x0E: side0=dirty, side1=dirty, boot=1 ///////////////////////
            // Uncommon situation:
                case ( SITUATION_SIDE_0_DIRTY  |
                       SITUATION_SIDE_1_DIRTY |
                       SITUATION_BOOT_SIDE_1  ) :
                    // fall through

            //// 0x0C: side0=dirty, side1=dirty, boot=0 ///////////////////////
            // Common situation: likely first step of code update
                case ( SITUATION_SIDE_0_DIRTY  |
                       SITUATION_SIDE_1_DIRTY |
                       SITUATION_BOOT_SIDE_0  ) :
                    // fall through

            //// 0x0A: side0=dirty, side1=clean, boot=1 ///////////////////////
            // Uncommon situation:
                case ( SITUATION_SIDE_0_DIRTY  |
                       SITUATION_SIDE_1_CLEAN |
                       SITUATION_BOOT_SIDE_1  ) :
                    // fall through

            //// 0x08: side0=dirty, side1=clean, boot=0 ///////////////////////
            // Uncommon situation:
                case ( SITUATION_SIDE_0_DIRTY  |
                       SITUATION_SIDE_1_CLEAN |
                       SITUATION_BOOT_SIDE_0  ) :

                    // Update side 0 and re-ipl

                    l_actions |= IPL_RESTART;
                    l_actions |= DO_UPDATE;
                    l_actions |= UPDATE_MVPD;
                    l_actions |= UPDATE_SBE;

                    // Set Update side to primary
                    io_sbeState.seeprom_side_to_update =  EEPROM::SBE_PRIMARY;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "side 0=dirty, side 1=%s. Boot side %d. "
                               "Update side 0 (primary). re-IPL. "
                               "(sit=0x%.2X, act=0x%.8X)",
                               TARGETING::get_huid(io_sbeState.target),
                               ( i_system_situation & SITUATION_SIDE_1_DIRTY)
                                   ? "dirty" : "clean",
                               io_sbeState.cur_seeprom_side,
                               i_system_situation, l_actions);

                    break;


            //// 0x06: side0=clean, side1=dirty, boot=1 ///////////////////////
            // Uncommon situation: booting from dirty side after other side
            //                     was updated
                case ( SITUATION_SIDE_0_CLEAN  |
                       SITUATION_SIDE_1_DIRTY |
                       SITUATION_BOOT_SIDE_1  ) :

                    // No update, log error and continue IPL

                    l_actions = CLEAR_ACTIONS;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "side 0=clean, side 1=dirty. Boot side 1. "
                               "Call-out SBE code. Continue IPL. "
                               "(sit=0x%.2X, act=0x%.8X)",
                               TARGETING::get_huid(io_sbeState.target),
                               i_system_situation, l_actions);

                    /*
                     * errortype
                     * moduleid     SBE_DECISION_TREE
                     * reasoncode   SBE_BOOT_SIDE_DIRTY_BAD_PATH
                     * userdata1    System Situation
                     * userdata2    Update Actions
                     * devdesc      Bad Path in decisionUpdateTree:
                     *               cur=DIRTY, alt=CLEAN
                     * custdesc     A problem occurred while updating
                     *               processor boot code.
                     */
                    err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                        SBE_DECISION_TREE,
                                        SBE_BOOT_SIDE_DIRTY_BAD_PATH,
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


            //// 0x04: side0=clean, side1=dirty, boot=0 ///////////////////////
            // Common situation: likely second step of code update
                case ( SITUATION_SIDE_0_CLEAN  |
                       SITUATION_SIDE_1_DIRTY |
                       SITUATION_BOOT_SIDE_0  ) :

                    // Update side 1 and continue IPL

                    l_actions |= DO_UPDATE;
                    l_actions |= UPDATE_MVPD;
                    l_actions |= UPDATE_SBE;

                    // Set Update side to backup
                    io_sbeState.seeprom_side_to_update = EEPROM::SBE_BACKUP;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "side 0=clean, side 1=dirty. Boot side 0. "
                               "Update side 1 (backup). Continue IPL. "
                               "(sit=0x%.2X, act=0x%.8X)",
                               TARGETING::get_huid(io_sbeState.target),
                               i_system_situation, l_actions);

                    break;


            //// 0x02: side0=clean, side1=clean, boot=1 ///////////////////////
            // Uncommon situation: booting from side 1 when both sides clean
                case ( SITUATION_SIDE_0_CLEAN  |
                       SITUATION_SIDE_1_CLEAN |
                       SITUATION_BOOT_SIDE_1  ) :
                    // fall through

            //// 0x00: side0=clean, side1=clean, boot=0 ///////////////////////
            // Common situation: normal boot
                case ( SITUATION_SIDE_0_CLEAN  |
                       SITUATION_SIDE_1_CLEAN |
                       SITUATION_BOOT_SIDE_0  ) :

                    // No update (both sides are clean) and continue IPL

                    l_actions = CLEAR_ACTIONS;

                    TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                               "Both sides clean-no updates. Boot side %d. "
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
                               "(sit=0x%.2X, act=0x%.8X, Boot side %d)",
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
    void decisionTreeForUpdatesSimultaneous(uint32_t& io_actions,
                                            sbeTargetState_t& io_sbeState,
                                            uint8_t& i_system_situation )
    {
        // Updates both SEEPROMs if either side is dirty
        if ( ( i_system_situation & SITUATION_CUR_IS_DIRTY ) ||
             ( i_system_situation & SITUATION_ALT_IS_DIRTY )  )
        {
                // At least one of the sides is dirty
                // Update both sides and re-IPL
                // Update MVPD flag: make cur=perm (because we know it
                //  works a bit)

                io_actions |= IPL_RESTART;
                io_actions |= DO_UPDATE;
                io_actions |= UPDATE_MVPD;
                io_actions |= UPDATE_SBE;

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
                           i_system_situation, io_actions,
                           io_sbeState.mvpdSbKeyword.flags);
        }
        else
        {
                // Both sides are clean - no updates
                // Continue IPL
                io_actions = CLEAR_ACTIONS;

                TRACFCOMP( g_trac_sbe, INFO_MRK"SBE Update tgt=0x%X: "
                           "Both sides clean-no updates. cur side=%d. "
                           "Continue IPL. (sit=0x%.2X, act=0x%.8X)",
                           TARGETING::get_huid(io_sbeState.target),
                           io_sbeState.cur_seeprom_side,
                           i_system_situation, io_actions);
        }
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

#ifdef CONFIG_SBE_UPDATE_INDEPENDENT
                if (g_update_both_sides)
                {
                    TRACFCOMP( g_trac_sbe, "UPDATE_BOTH_SIDES_OF_SBE MNFG Flag indicated, will update both sides" );
                    io_sbeState.seeprom_side_to_update = EEPROM::SBE_PRIMARY;
                }
#endif

#ifdef CONFIG_SBE_UPDATE_SEQUENTIAL
                if (g_do_hw_keys_hash_transition)
                {
                    TRACFCOMP( g_trac_sbe, "UPDATE_BOTH_SIDES_OF_SBE Key transition, will update both sides" );
                    io_sbeState.seeprom_side_to_update = EEPROM::SBE_PRIMARY;
                }
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
             *               SBE Version Information
             * @custdesc     Successful Update of Self Boot Engine
             *               (SBE) SEEPROM SBE Version Information
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
            assert((MAX_RING_BUF_SIZE <= VMM_SBE_UPDATE_SIZE/4),
                "createSbeImageVmmSpace() MAX_RING_BUF_SIZE too large");


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

            // Load PNOR sections into secure memory
#ifdef CONFIG_SECUREBOOT
            err = loadSecureSection(PNOR::SBE_IPL);
            if (err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"createSbeImageVmmSpace() - Error from loadSecureSection(PNOR::SBE_IPL)");
                break;
            }

            err = loadSecureSection(PNOR::HB_BOOTLOADER);
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK,"createSbeImageVmmSpace() - Error from loadSecureSection(PNOR::HB_BOOTLOADER)");
                break;
            }

            err = loadSecureSection(PNOR::HCODE);

            if (err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK,"createSbeImageVmmSpace() - Error from loadSecureSection(PNOR::HCODE)");
                break;
            }
#endif

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

            // Unload PNOR sections from secure memory
#ifdef CONFIG_SECUREBOOT
            err = unloadSecureSection(PNOR::SBE_IPL);
            if (err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"cleanupSbeImageVmmSpace() - Error from unloadSecureSection(PNOR::SBE_IPL)");
                break;
            }

            err = unloadSecureSection(PNOR::HB_BOOTLOADER);
            if (err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK,"cleanupSbeImageVmmSpace() - Error from unloadSecureSection(PNOR::HB_BOOTLOADER)");
                break;
            }

            err = unloadSecureSection(PNOR::HCODE);
            if (err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK,"cleanupSbeImageVmmSpace() - Error from unloadSecureSection(PNOR::HCODE)");
                break;
            }
#endif
            PNOR::flush( PNOR::SBE_IPL );
            PNOR::flush( PNOR::HB_BOOTLOADER );
            PNOR::flush( PNOR::HCODE );

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
                          "IPL wasn't requested from us: o_reIplRequest=%d, "
                          "RC=0x%X, PLID=0x%lX",
                          o_reIplRequest,
                          ERRL_GETRC_SAFE(err),
                          ERRL_GETPLID_SAFE(err));

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
                              "MBOX returned that it was our IPL request: "
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

        // MVPD PERMANENT and Re-IPL Seeprom flags
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
                                  "Required for tgt=0x%X (u_a=0x%X, flag=0x%X)",
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
                         * @devdesc      SBE Image Version Miscompare with
                         *               Master Target
                         * @custdesc     Self Boot Engine (SBE) Image Version
                         *               Miscompare with Master Target
                         */
                        err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                            SBE_MASTER_VERSION_COMPARE,
                                            SBE_MASTER_VERSION_DOWNLEVEL,
                                            TARGETING::get_huid(
                                                  io_sbeStates_v[mP].target),
                                            mP);

                        err->collectTrace(SBE_COMP_NAME);

                        err->addProcedureCallout(HWAS::EPUB_PRC_LVL_SUPP,
                                                 HWAS::SRCI_PRIORITY_HIGH);

                        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                                HWAS::SRCI_PRIORITY_MED);

                        err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                                 HWAS::SRCI_PRIORITY_LOW);

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
                               "rc=0x%.4X, sev=0x%.2X. "
                               "Can't trust its SBE Version",
                               TARGETING::get_huid(io_sbeStates_v[i].target),
                               io_sbeStates_v[i].err_plid,
                               io_sbeStates_v[i].err_eid,
                               io_sbeStates_v[i].err_rc,
                               io_sbeStates_v[i].err_sev);

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
                    err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
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
                     * @devdesc      SBE Version Miscompare with Master Target
                     * @custdesc     Self Boot Engine (SBE) Version Miscompare
                     *               with Master Target
                     */
                    err = new ErrlEntry(ERRL_SEV_PREDICTIVE,
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

                    err->addProcedureCallout(HWAS::EPUB_PRC_LVL_SUPP,
                                             HWAS::SRCI_PRIORITY_HIGH);

                    err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_MED);

                    err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                             HWAS::SRCI_PRIORITY_LOW);

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


/////////////////////////////////////////////////////////////////////
    size_t setECCSize(size_t i_srcSz,
                      const uint64_t i_offset,
                      const uint64_t i_boundary)
    {
        // Assert that source size is a multiple of 8
        assert((i_srcSz % 8) == 0);

        // Calculate size with ECC. but without padding
        size_t l_eccSz = (i_srcSz * 9) / 8;

        // Determine padding at each boundary
        size_t l_padSz = i_boundary % 9;

        // Calculate number of boundary crossings
        // Only use portion of offset beyond last boundary it crosses
        // Exactly reaching a boundary is not counted as a crossing
        uint64_t l_boundaryCrossings =
            (l_eccSz + (i_offset % i_boundary) - 1) / (i_boundary - l_padSz);

        // Calculate total padding
        size_t l_totalPadding = l_boundaryCrossings * l_padSz;

        return (l_eccSz + l_totalPadding);
    }


/////////////////////////////////////////////////////////////////////
    void injectECC(const uint8_t* i_src,
                   size_t i_srcSz,
                   const uint64_t i_offset,
                   const uint64_t i_boundary,
                   uint8_t* o_dst)
    {
        // Initialize local size variables for inject loop
        size_t l_completeSz = 0;
        size_t l_completeEccSz = 0;
        size_t l_padSz = i_boundary % 9;
        size_t l_injectSz =
            ((i_boundary - l_padSz - (i_offset % i_boundary)) * 8) / 9;
        if(l_injectSz > i_srcSz)
        {
            l_injectSz = i_srcSz;
        }

        // Loop through injection of ECC
        while(l_completeSz < i_srcSz)
        {
            // Assert that injection size is a multiple of 8
            assert((l_injectSz % 8) == 0);

            // Inject ECC
            PNOR::ECC::injectECC(i_src + l_completeSz,
                                 l_injectSz,
                                 o_dst + l_completeEccSz);

            // Adjust local size variables
            l_completeSz += l_injectSz;
            l_completeEccSz += ((l_injectSz * 9) / 8);

            // Determine next size for ECC injection
            if((i_srcSz - l_completeSz) >= (((i_boundary - l_padSz) * 8) / 9))
            {
                // Set up size to go to next device boundary
                l_injectSz = ((i_boundary - l_padSz) * 8) / 9;
            }
            else
            {
                // Set up size to finish ECC injection
                l_injectSz = i_srcSz - l_completeSz;
            }

            // Determine if ECC injection is not finished
            if(l_injectSz > 0)
            {
                // Pad to device boundary if some ECC injection is left
                memset(o_dst + l_completeEccSz,
                       '\0',
                       l_padSz);
                l_completeEccSz += l_padSz;
            }
        } // while (l_completeSz < i_srcSz)
    }


/////////////////////////////////////////////////////////////////////
    PNOR::ECC::eccStatus removeECC(uint8_t* io_src,
                                   uint8_t* o_dst,
                                   size_t i_dstSz,
                                   const uint64_t i_offset,
                                   const uint64_t i_boundary)
    {
        PNOR::ECC::eccStatus l_status = PNOR::ECC::CLEAN;

        // Initialize local size variables for remove loop
        size_t l_completeSz = 0;
        size_t l_completeEccSz = 0;
        size_t l_padSz = i_boundary % 9;
        size_t l_removeSz =
            ((i_boundary - l_padSz - (i_offset % i_boundary)) * 8) / 9;
        if(l_removeSz > i_dstSz)
        {
            l_removeSz = i_dstSz;
        }

        // Loop through removal of ECC
        while(l_completeSz < i_dstSz)
        {
            // Assert that removal size is a multiple of 8
            assert((l_removeSz % 8) == 0);

            // remove ECC
            l_status = PNOR::ECC::removeECC(io_src + l_completeEccSz,
                                            o_dst + l_completeSz,
                                            l_removeSz);
            if (l_status == PNOR::ECC::UNCORRECTABLE)
            {
                break;
            }

            // Adjust local size variables
            l_completeSz += l_removeSz;
            l_completeEccSz += ((l_removeSz * 9) / 8);

            // Determine next size for ECC removal
            if((i_dstSz - l_completeSz) >= (((i_boundary - l_padSz) * 8) / 9))
            {
                // Set up size to go to next device boundary
                l_removeSz = ((i_boundary - l_padSz) * 8) / 9;
            }
            else
            {
                // Set up size to finish ECC removal
                l_removeSz = i_dstSz - l_completeSz;
            }

            // Determine if ECC removal is not finished
            if(l_removeSz > 0)
            {
                // Skip pad at device boundary if some ECC removal is left
                l_completeEccSz += l_padSz;
            }
        } // while (l_completeSz < i_dstSz)

        return l_status;
    }

/////////////////////////////////////////////////////////////////////
    errlHndl_t getBootMcSyncMode( uint8_t& o_mcSyncMode )
    {
        errlHndl_t l_err = nullptr;

        INITSERVICE::SPLESS::MboxScratch5_t l_scratch5;

        TRACFCOMP( g_trac_sbe, ENTER_MRK"Enter getBootMcSyncMode()");
        do
        {
            TARGETING::Target * l_sys = nullptr;
            (void) TARGETING::targetService().getTopLevelTarget( l_sys );
            assert( l_sys, "getBootMcSyncMode() system target is NULL");

            TARGETING::ATTR_MASTER_MBOX_SCRATCH_type l_scratchRegs;
            assert(l_sys->tryGetAttr
                      <TARGETING::ATTR_MASTER_MBOX_SCRATCH>(l_scratchRegs),
                   "getBootMcSyncMode() failed to get MASTER_MBOX_SCRATCH");
            l_scratch5.data32 = l_scratchRegs[INITSERVICE::SPLESS::SCRATCH_5];

            TRACFCOMP(g_trac_sbe,
                      "The MC Sync Bit is %d",
                      l_scratch5.mcSyncMode );

            o_mcSyncMode = l_scratch5.mcSyncMode;

        } while( 0 );
        TRACUCOMP(g_trac_sbe,EXIT_MRK "Exit getBootMcSyncMode()");

        return l_err;
    }

/////////////////////////////////////////////////////////////////////
errlHndl_t sbeDoReboot( void )
{
    errlHndl_t err = NULL;
    TRACFCOMP( g_trac_sbe, ENTER_MRK"sbeDoReboot");

    do{
#ifdef CONFIG_BMC_IPMI
        uint16_t count = SENSOR::DEFAULT_REBOOT_COUNT;
        SENSOR::RebootCountSensor l_sensor;

        // Set reboot count to default value
        TRACFCOMP( g_trac_sbe,
                   INFO_MRK"sbeDoReboot: "
                   "Writing Reboot Sensor Count=%d", count);

        err = l_sensor.setRebootCount( count );
        if ( err )
        {
            TRACFCOMP( g_trac_sbe,
                       ERR_MRK"sbeDoReboot: "
                       "FAIL Writing Reboot Sensor Count to %d. "
                       "Committing Error Log rc=0x%.4X eid=0x%.8X "
                       "plid=0x%.8X, but continuing shutdown",
                       count,
                       err->reasonCode(),
                       err->eid(),
                       err->plid());
            err->collectTrace(SBE_COMP_NAME);
            errlCommit( err, SBE_COMP_ID );

            // No Break - Still send chassis power cycle
        }

#else //non-IPMI

        if( INITSERVICE::spBaseServicesEnabled() )
        {
            // Sync all attributes to the FSP before doing the Shutdown
            err = syncAllAttributesToFsp();
            if( err )
            {
                // Something failed on the sync.  Commit the error here
                // and continue with the Re-IPL Request
                TRACFCOMP( g_trac_sbe,
                           ERR_MRK"sbeDoReboot() - Error "
                           "syncing attributes to FSP, RC=0x%X, PLID=0x%lX",
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));
                errlCommit( err, SBE_COMP_ID );
            }
            else
            {
                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"sbeDoReboot() - Sync "
                           "Attributes to FSP" );
            }
        }

#endif

#ifdef CONFIG_CONSOLE
        if(g_do_hw_keys_hash_transition)
        {
            CONSOLE::displayf(SBE_COMP_NAME, "Performing Secure Boot key transition\n");
            CONSOLE::displayf(SBE_COMP_NAME, "System will power off after completion\n");
            CONSOLE::flush();
        }
        else
        {
            CONSOLE::displayf(SBE_COMP_NAME, "System Rebooting To "
                              "Complete SBE Update Process");
            CONSOLE::flush();
        }
#endif


#ifdef CONFIG_BMC_IPMI
        if(g_do_hw_keys_hash_transition)
        {
            // Initiate a graceful power off
            TRACFCOMP(g_trac_sbe,
                INFO_MRK"sbeDoReboot(): Performing Secure Boot key transition. "
                "Requesting power off");
            INITSERVICE::requestPowerOff();
        }
        else
        {
            // Initiate a graceful power cycle
            TRACFCOMP( g_trac_sbe,"sbeDoReboot: "
                       "requesting power cycle");
            INITSERVICE::requestReboot();
        }
#else //non-IPMI
        if(g_do_hw_keys_hash_transition)
        {
            TRACFCOMP(g_trac_sbe,
                INFO_MRK"sbeDoReboot(): Performing Secure Boot key transition. "
                "Calling INITSERVICE::doShutdown() with "
                "SHUTDOWN_KEY_TRANSITION = 0x%08X",
                INITSERVICE::SHUTDOWN_KEY_TRANSITION );
            INITSERVICE::doShutdown(INITSERVICE::
                                    SHUTDOWN_KEY_TRANSITION);
        }
        else
        {
            TRACFCOMP( g_trac_sbe,
                       INFO_MRK"sbeDoReboot(): Calling "
                       "INITSERVICE::doShutdown() with "
                       "SBE_UPDATE_REQUEST_REIPL = 0x%08X",
                       SBE_UPDATE_REQUEST_REIPL );
            // shutdown/TI hostboot
            INITSERVICE::doShutdown(SBE_UPDATE_REQUEST_REIPL);
        }
#endif

    }while(0);

    TRACFCOMP( g_trac_sbe, EXIT_MRK"sbeDoReboot");

    return err;
}

/////////////////////////////////////////////////////////////////////
errlHndl_t getHwKeyHashFromSbeImage(
                           TARGETING::Target* const i_target,
                           const EEPROM::eeprom_chip_types_t i_seeprom,
                           SHA512_t o_hash,
                           const void * i_image_ptr) // defaults to nullptr
{
    errlHndl_t err = nullptr;

    // if i_image_ptr == nullptr, then read from SBE Seeprom;
    // if i_image_ptr != nullptr, then read from memory at i_image_ptr
    TRACFCOMP( g_trac_sbe, ENTER_MRK"getHwKeyHashFromSbeImage: "
               "i_target=0x%X, i_seeprom=%d, i_image_ptr=%p: "
               "reading from %s",
               get_huid(i_target), i_seeprom, i_image_ptr,
               (i_image_ptr) ? "memory" : "seeprom");

    // Check Input Parameters
    if ( i_image_ptr == nullptr )
    {
        // Only check i_target and i_seeprom if i_image_ptr == nullptr;
        // otherwise they're ignored as i_image_ptr is used
        assert(i_target != nullptr,"getHwKeyHashFromSbeImage i_target can't be NULL");
        assert(i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC, "getHwKeyHashFromSbeImage i_target must be TYPE_PROC");
        assert(((i_seeprom == EEPROM::SBE_PRIMARY) || (i_seeprom == EEPROM::SBE_BACKUP)), "getHwKeyHashFromSbeImage i_seeprom=%d is invalid", i_seeprom);
    }


    // Code Assumptions
    static_assert((sizeof(P9XipHeader) % 8) == 0, "getHwKeyHashFromSbeImage(): sizeof(P9XipHeader) is not 8-byte-aligned");
    static_assert((sizeof(P9XipHeader().iv_magic) % 8) == 0, "getHwKeyHashFromSbeImage(): sizeof(P9XipHeader().iv_magic) is not 8-byte-aligned");
    static_assert((sizeof(SHA512_t) % 8) == 0, "getHwKeyHashFromSbeImage(): sizeof(SHA512_t) is not 8-byte-aligned");

    // Local variables used to capture ECC FFDC
    PNOR::ECC::eccStatus eccStatus = PNOR::ECC::CLEAN;
    size_t seeprom_offset = 0;
    size_t remove_ECC_size = 0;
    size_t size = 0;
    size_t expected_size = 0;

    // Create buffers for read operations and removing ECC
    const size_t max_buffer_size = PNOR::ECC::sizeWithEcc(
         (std::max(sizeof(P9XipHeader), sizeof(SHA512_t))));

    uint8_t tmp_data[max_buffer_size] = {0};
    uint8_t tmp_data_ECC[max_buffer_size] = {0};


    do{
        // Get P9XipHeader, which is at the start of the SBE Image
        seeprom_offset = 0;

        if ( i_image_ptr == nullptr )
        {
            // Calculate amount of data to read from SEEPROM
            size = PNOR::ECC::sizeWithEcc(sizeof(P9XipHeader));
            expected_size = size;

            //Read SBE Versions
            err = deviceRead( i_target,
                              tmp_data_ECC,
                              size,
                              DEVICE_EEPROM_ADDRESS(i_seeprom,
                                                    seeprom_offset));
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getHwKeyHashFromSbeImage() "
                           "Error getting SBE Data from Tgt=0x%X SEEPROM "
                           "(0x%X), RC=0x%X, PLID=0x%X",
                           get_huid(i_target),
                           EEPROM::SBE_BACKUP,
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));

                err->collectTrace(SBE_COMP_NAME);

                break;
            }
            assert(size==expected_size, "getHwKeyHashFromSbeImage: size 0x%X returned form reading P9XipHeader does not equal expected_size=0x%X", size, expected_size);

            remove_ECC_size = sizeof(P9XipHeader);
            eccStatus = removeECC( tmp_data_ECC,
                                   tmp_data,
                                   remove_ECC_size,
                                   seeprom_offset,
                                   SBE_SEEPROM_SIZE);

            if ( eccStatus == PNOR::ECC::UNCORRECTABLE )
            {
                TRACFCOMP( g_trac_sbe, "getHwKeyHashFromSbeImage(): "
                           "Uncorrectable eccStatus from reading P9XipHeader: "
                           "%d",
                           eccStatus);

                // Break here - error log will be created after do-while loop
                break;
            }

            TRACDBIN( g_trac_sbe,
                      "getHwKeyHashFromSbeImage: P9XipHeader with ECC",
                      tmp_data_ECC,
                      PNOR::ECC::sizeWithEcc(sizeof(P9XipHeader().iv_magic) ) );

        }
        else
        {
            // Copy P9XipHeader to local membuf
            memcpy (tmp_data, i_image_ptr, sizeof(P9XipHeader));
        }

        TRACDBIN( g_trac_sbe,
                  "getHwKeyHashFromSbeImage: P9XipHeader no ECC",
                  tmp_data,
                  sizeof(P9XipHeader().iv_magic) ) ;


        // After getting P9XipHeader, call p9_xip_find to find HBBL image
        // in SBE Image
        P9XipSection l_xipSection = {0};

        // Call p9_xip_find to find HBBL image in SBE image
        auto l_sectionId = P9_XIP_SECTION_SBE_HBBL;

        int xip_rc = p9_xip_get_section( tmp_data, l_sectionId, &l_xipSection );

        TRACUCOMP( g_trac_sbe, "getHwKeyHashFromSbeImage: xip_rc=%d: "
                   "Section iv_offset=0x%X, iv_size=0x%X, iv_alignment=0x%X",
                   xip_rc, l_xipSection.iv_offset, l_xipSection.iv_size,
                   l_xipSection.iv_alignment);

        // Check the return code
        if( ( xip_rc != 0 ) ||
            ( l_xipSection.iv_offset == 0 ) ||
            ( l_xipSection.iv_size == 0 ) )
        {
            TRACFCOMP( g_trac_sbe, "getHwKeyHashFromSbeImage: Error from "
                       "p9_xip_get_section: xip_rc=%d: Section iv_offset=0x%X, "
                       "iv_size=0x%X, iv_alignment=0x%X",
                       xip_rc, l_xipSection.iv_offset, l_xipSection.iv_size,
                       l_xipSection.iv_alignment);

            /*@
             * @errortype
             * @moduleid         SBE_GET_HW_KEY_HASH
             * @reasoncode       ERROR_FROM_XIP_FIND
             * @userdata1[0:31]  Target HUID
             * @userdata1[32:63] Seeprom Side
             * @userdata2[0:15]  Offset of HBBL Section in Seeprom Image
             * @userdata2[16:31] Size of HBBL Section in Seeprom Image
             * @userdata2[32:63] Return Code from p9_xip_get_section
             * @devdesc          Error Associated with Target's SBE Seeprom
             * @custdesc         A problem occurred with processor seeprom
             */
            err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                SBE_GET_HW_KEY_HASH,
                                ERROR_FROM_XIP_FIND,
                                TWO_UINT32_TO_UINT64(
                                  TARGETING::get_huid(i_target),
                                  i_seeprom),
                                TWO_UINT16_ONE_UINT32_TO_UINT64(
                                  l_xipSection.iv_offset,
                                  l_xipSection.iv_size,
                                  xip_rc));

            err->addPartCallout(i_target,
                                HWAS::SBE_SEEPROM_PART_TYPE,
                                HWAS::SRCI_PRIORITY_HIGH,
                                HWAS::NO_DECONFIG,
                                HWAS::GARD_NULL );

            ErrlUserDetailsTarget(i_target,"Target").addToLog(err);

            err->collectTrace(SBE_COMP_NAME);

            break;
        }


        // Calculate Seeprom offset
        // -- Raw Image Offset -- HW Key Hash is at end of HBBL section
        seeprom_offset = l_xipSection.iv_offset + HBBL_HW_KEY_HASH_LOCATION;
        if ( i_image_ptr == nullptr )
        {
            // Math to convert Image offset to Seeprom(with ECC) Offset
            seeprom_offset = setECCSize(seeprom_offset);
        }

        TRACUCOMP( g_trac_sbe, "getHwKeyHashFromSbeImage: seeprom_offset "
                   "= 0x%X, size = 0x%X",
                   seeprom_offset, size);

        // Read HW Key Hash from SBE Image
        if ( i_image_ptr == nullptr)
        {
            // Clear buffers and set size to SHA512_t+ECC
            memset( tmp_data_ECC, 0, max_buffer_size );
            memset( tmp_data, 0, max_buffer_size );
            size = PNOR::ECC::sizeWithEcc(sizeof(SHA512_t));
            expected_size = size;

            //Read SBE Seeprom
            err = deviceRead( i_target,
                              tmp_data_ECC,
                              size,
                              DEVICE_EEPROM_ADDRESS(
                                                i_seeprom,
                                                seeprom_offset));
            if(err)
            {
                TRACFCOMP( g_trac_sbe, ERR_MRK"getHwKeyHashFromSbeImage() "
                           "Error getting HKH from SEEPROM (0x%X), "
                           "RC=0x%X, PLID=0x%X",
                           EEPROM::SBE_BACKUP,
                           ERRL_GETRC_SAFE(err),
                           ERRL_GETPLID_SAFE(err));

                err->collectTrace(SBE_COMP_NAME);

                break;
            }
            assert(size==expected_size, "getHwKeyHashFromSbeImage: size 0x%X returned form reading HW Key Hash does not equal expected_size=0x%X", size, expected_size);

            remove_ECC_size = sizeof(SHA512_t);
            eccStatus = removeECC( tmp_data_ECC,
                                   tmp_data,
                                   remove_ECC_size,
                                   seeprom_offset,
                                   SBE_SEEPROM_SIZE);

            if ( eccStatus == PNOR::ECC::UNCORRECTABLE )
            {
                TRACFCOMP( g_trac_sbe, "getHwKeyHashFromSbeImage(): "
                           "Uncorrectable eccStatus from reading HW Key Hash: %d",
                           eccStatus);

                // Break here - error log will be created after do-while loop
                break;
            }

            TRACDBIN( g_trac_sbe,
                      "getHwKeyHashFromSbeImage: ECC",
                      tmp_data_ECC,
                      expected_size ) ;

            TRACDBIN( g_trac_sbe,
                      "getHwKeyHashFromSbeImage: no ECC",
                      tmp_data,
                      sizeof(SHA512_t) ) ;

            // If we made it here, HW Key Hash was found successfully
            TRACUCOMP( g_trac_sbe, INFO_MRK"getHwKeyHashFromSbeImage(): hash "
                       "found successfully from SBE Seeprom- setting o_hash");
            memcpy(o_hash, tmp_data, sizeof(SHA512_t));
        }
        else
        {
            // Copy HW Key Hash from system memory
            memcpy(o_hash,
                   reinterpret_cast<uint8_t*>(const_cast<void*>(i_image_ptr))
                     + seeprom_offset,
                   sizeof(SHA512_t));
        }

    }while(0);

    // Create error log here for ECC fails
    if ( (eccStatus == PNOR::ECC::UNCORRECTABLE)
         && ( err == nullptr ) )
    {
        // Trace above; create error log here

        /*@
         * @errortype
         * @moduleid         SBE_GET_HW_KEY_HASH
         * @reasoncode       SBE_ECC_FAIL
         * @userdata1[0:31]  Target HUID
         * @userdata1[32:63] Seeprom Side
         * @userdata2[0:15]  ECC Status
         * @userdata2[16:31] No-ECC Data Size
         * @userdata2[32:63] Offset into Seeprom Data Came From
         * @devdesc          Error Associated with Updating this Target
         * @custdesc         A problem occurred with processor seeprom
         */
        err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            SBE_GET_HW_KEY_HASH,
                            SBE_ECC_FAIL,
                            TWO_UINT32_TO_UINT64(
                              TARGETING::get_huid(i_target),
                              i_seeprom),
                            TWO_UINT16_ONE_UINT32_TO_UINT64(
                              eccStatus,
                              remove_ECC_size,
                              seeprom_offset));

        err->addPartCallout(i_target,
                            HWAS::SBE_SEEPROM_PART_TYPE,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL );

        ErrlUserDetailsTarget(i_target,"Target").addToLog(err);

        err->collectTrace(SBE_COMP_NAME);
    }


    TRACFCOMP( g_trac_sbe, EXIT_MRK"getHwKeyHashFromSbeImage: "
               "err rc=0x%X, plid=0x%X, o_hash=0x%.8X",
               ERRL_GETRC_SAFE(err), ERRL_GETPLID_SAFE(err),
               sha512_to_u32(o_hash));

    return err;
}

errlHndl_t secureKeyTransition()
{
    errlHndl_t l_errl = nullptr;

#ifdef CONFIG_SECUREBOOT
    do {
    bool l_loaded = false;
    PNOR::SectionInfo_t l_secInfo;

    // Get SBKT PNOR section info from PNOR RP
    l_errl = getSectionInfo(PNOR::SBKT, l_secInfo);
    // SBKT section is optional so just delete error and no-op
    if (l_errl)
    {
        TRACFCOMP( g_trac_sbe, ERR_MRK"secureKeyTransition() - getSectionInfo() optional PNOR::SBKT DNE");
        delete l_errl;
        l_errl = nullptr;
        break;
    }

    // if it has a secure header, we do need to load and verify the container
    if(l_secInfo.secure)
    {
        // Verify and Load SBKT section and nested container.
        l_errl = loadSecureSection(PNOR::SBKT);
        if (l_errl)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"secureKeyTransition() - Error from loadSecureSection(PNOR::SBKT)");
            break;
        }
        l_loaded = true;

        // Get new verified HW key hash
        const void* l_pVaddr = reinterpret_cast<void*>(l_secInfo.vaddr);
        SECUREBOOT::ContainerHeader l_nestedConHdr;
        l_errl = l_nestedConHdr.setHeader(l_pVaddr);
        if(l_errl)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"secureKeyTransition() - setheader failed");
            break;
        }
        // Get pointer to first element of hwKeyHash from header.
        const uint8_t* l_hwKeyHash = l_nestedConHdr.hwKeyHash()[0];
        // Update global variable with hw keys hash to transition to.
        memcpy(g_hw_keys_hash_transition_data, l_hwKeyHash,
               sizeof(g_hw_keys_hash_transition_data));
        // Indicate a key transition is required
        g_do_hw_keys_hash_transition = true;

        bool l_hw_lab_override_flag = l_nestedConHdr.sb_flags()->hw_lab_override;
        TRACFCOMP(g_trac_sbe, "Overriding the Lab Security Backdoor Bit due to"
                  " key transition; new Security Backdoor Enabled bit is %d",
                  l_nestedConHdr.sb_flags()->hw_lab_override);
        l_errl = SECUREBOOT::setSbeSecurityMode(!l_hw_lab_override_flag);
        if(l_errl)
        {
            TRACFCOMP(g_trac_sbe, ERR_MRK"secureKeyTransition() - could not"
                      " set SBE security mode.");
            break;
        }
    }
    if(l_loaded)
    {
        l_errl = unloadSecureSection(PNOR::SBKT);
        if (l_errl)
        {
            TRACFCOMP( g_trac_sbe, ERR_MRK"secureKeyTransition() - Error from unloadSecureSection(PNOR::SBKT)");
            break;
        }
    }
    } while(0);
#endif

    return l_errl;
}

/////////////////////////////////////////////////////////////////////

errlHndl_t locateHbblIdStringBfr( void * i_pSourceBfr,
                                  uint32_t i_SourceBfrLen,
                                  void * & o_pHbblIdStringBfr )
{
    errlHndl_t l_errl = NULL;
    o_pHbblIdStringBfr = NULL;


    // packing of ID string is defined in bl_start.S
    //   - 16 byte aligned : note, after customize, this may only be
    //                              8 byte aligned
    //   - 128 bytes long
    //   - resides in .data at end of binary

    //  start near end of bfr, minimum of 128 bytes from overflow,
    //    aligned on 16 byte boundary
    uint64_t sourceBfrAddr = reinterpret_cast<uint64_t>(i_pSourceBfr);
    uint64_t bfrOverflowAddr = sourceBfrAddr + i_SourceBfrLen;
    uint64_t startSearchAddr = ALIGN_DOWN_8(bfrOverflowAddr - 128);

    uint64_t * pBfrUnderflow = reinterpret_cast<uint64_t *>(sourceBfrAddr);
    uint64_t * pStartSearch = reinterpret_cast<uint64_t *>(startSearchAddr);

    // 'HBBL ID '
#define SBE_HBBL_ID_MARKER0  0x4842424c20494420ull
    // 'STRING ='
#define SBE_HBBL_ID_MARKER1  0x535452494e47203dull

    TRACFCOMP( g_trac_sbe,
               INFO_MRK"locateHbblIdStringBfr() : start search "
               "pBfr=0x%X, BfrLen=0x%X, pSearchStart=0x%X",
               sourceBfrAddr, i_SourceBfrLen, pStartSearch );

    do
    {
        for // search for the string, starting from the end of the bfr
          ( uint64_t * pCurTestPosn = pStartSearch;
            pCurTestPosn >= pBfrUnderflow;
            pCurTestPosn-=(8/8) )  // backup 8 bytes, 8-byte ptr math
        {
            if // current position is hbbl id marker
              ( ((*(pCurTestPosn)) == SBE_HBBL_ID_MARKER0) &&
                ((*(pCurTestPosn+1)) == SBE_HBBL_ID_MARKER1) )
            {
                // found the string eye catcher, all done
                //  note : step over 16 byte hdr using 8-byte ptr math
                o_pHbblIdStringBfr = pCurTestPosn + (16/8);

                TRACFCOMP( g_trac_sbe,
                           INFO_MRK"locateHbblIdStringBfr() : string found "
                           "pString=0x%X",
                           o_pHbblIdStringBfr );

                TRACFBIN( g_trac_sbe,
                          INFO_MRK"locateHbblIdStringBfr() : "
                                  "Eye Catcher + string Bfr = ",
                          pCurTestPosn,
                          (16+128) );

                break;
            }
        } // end reverse bfr search

    } while(0);

    return l_errl;
}

errlHndl_t querySbeSeepromVersions()
{
    errlHndl_t l_errl = nullptr;
    sbeTargetState_t l_sbeState;
    TARGETING::TargetHandleList l_procList;
    do {
        // Query all of the functional processor targets
        TARGETING::getAllChips(l_procList,
                            TARGETING::TYPE_PROC,
                            true); // true: return functional targets
        assert( l_procList.size(), "querySbeSeepromVersions: no functional procs found!")

        if(!Util::isSimicsRunning())
        {
            for(const auto & l_procTarget : l_procList)
            {
                memset(&l_sbeState, 0, sizeof(l_sbeState));
                l_sbeState.target = l_procTarget;
                // populate the SBE SEEPROM version info
                l_errl = getSeepromVersions(l_sbeState);

                if(l_errl)
                {
                    break;
                }

                // If the image_versions do not match then we must set the attribute to reflect that
                if(memcmp(&l_sbeState.seeprom_0_ver.image_version,
                        &l_sbeState.seeprom_1_ver.image_version,
                        SBE_IMAGE_VERSION_SIZE) != 0)
                {
                    // ATTR_HB_SBE_SEEPROM_VERSION_MISMATCH is defaulted to be 0, so
                    // we need to set the attribute to 1 if we find that the SEEPROM
                    // sides do not have matching versions.
                    l_procTarget->setAttr<ATTR_HB_SBE_SEEPROM_VERSION_MISMATCH>(1);
                }
            }

            if(l_errl)
            {
                TRACFCOMP(g_trac_sbe,
                          ERR_MRK "querySbeSeepromVersions: "
                          "Error occured looking up seeprom versions. Returning early from function.");
                break;
            }
        }
        else
        {
            // If we are running simics it is safe to assume both sides of the seeprom are the same.
            // We don't actually perform SEEPROM updates in simics do to time restrictions so the
            // concept of updating the SBE SEEPROMs in simics is a little spoofed out so we need
            // to do some fudging here. ATTR_HB_SBE_SEEPROM_VERSION_MATCH is defaulted to 1 so there
            // is no need to set it.
        }

    } while(0);
    return l_errl;
}

} //end SBE Namespace

