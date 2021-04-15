/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfRasServices_common.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

/** @file  prdfRasServices_common.C
 *  @brief Utility code to parse an SDC and produce the appropriate error log.
 */

#include <prdfRasServices.H>
#include <prdfPfa5Data.h>
#include <time.h>
#include <iipServiceDataCollector.h>
#include <prdf_service_codes.H>
#include <prdfGlobal.H>
#include <prdfErrlUtil.H>
#include <prdfCallouts.H>
#include <prdfMemoryMru.H>
#include <prdfPlatServices.H>

#include <prdfMemCaptureData.H>

#if !defined(__HOSTBOOT_MODULE) && !defined(ESW_SIM_COMPILE)
#include <server/services/hostService/hwsvHostSvcUtil.H> // setRegNodeBootStatus
#endif

// For compression routines
#define PRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS
#include <prdfCompressBuffer.H>

#include <utilmem.H> //For UtilMem stream class (outputting PfaData).
#include <vector>
#include <algorithm>
#include <iipSystem.h>         //For RemoveStoppedChips

#ifdef __HOSTBOOT_MODULE

  #include <stdio.h>
  #include <errludstring.H>

  #ifdef __HOSTBOOT_RUNTIME
    #include <prdfMemDynDealloc.H>
  #endif

#else
  #include <srcisrc.H>
  #include <utilreg.H> //For registry functions
  #include <evenmgt.H>
  #include <rmgrBaseClientLib.H>  //for rmgrSyncFile
  #include <prdfSdcFileControl.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
// Local Globals
//------------------------------------------------------------------------------

RasServices thisServiceGenerator;

//------------------------------------------------------------------------------

ServiceGeneratorClass & ServiceGeneratorClass::ThisServiceGenerator(void)
{
  return thisServiceGenerator;
}

//------------------------------------------------------------------------------

void ErrDataService::Initialize()
{
    iv_serviceActionCounter = 0;
}

//------------------------------------------------------------------------------

errlHndl_t ErrDataService::GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                           ServiceDataCollector & io_sdc )
{
    #define PRDF_FUNC "[ErrDataService::GenerateSrcPfa] "

    // First, check if an error log should be committed. Note that there should
    // always be an error log if there was a system or unit checkstop.
    if ( io_sdc.queryDontCommitErrl() &&
         MACHINE_CHECK != i_attnType &&
         UNIT_CS != io_sdc.getSecondaryAttnType() )
    {
        // User did not want this error log committed. No need to continue. So
        // delete it and exit.
        delete iv_errl; iv_errl = nullptr;
        return nullptr;
    }

#ifdef __HOSTBOOT_MODULE
    using namespace ERRORLOG;
    using namespace HWAS;
#else
    uint8_t sdcSaveFlags = SDC_NO_SAVE_FLAGS;
    size_t  sz_uint8    = sizeof(uint8_t);
#endif

    epubProcedureID thisProcedureID;

    bool ForceTerminate = false;
    bool iplDiagMode = false;

    ++iv_serviceActionCounter;

    uint16_t PRD_Reason_Code = 0;

    //**************************************************************
    // Callout loop to set up Reason code and SRC word 9
    //**************************************************************

    // Must go thru callout list to look for RIOPORT procedure callouts,
    // since they require the port info to be in SRC Word 9
    bool HW = false;
    bool SW = false;
    bool SW_High = false;
    bool SecondLevel = false;
    uint32_t SrcWord7 = 0;
    uint32_t SrcWord9 = 0;

    // Should not gard hardware if there is a hardware callout at LOW priority
    // and a symbolic FRU indicating a possibility of a software error at MED or
    // HIGH priority.
    bool sappSwNoGardReq = false, sappHwNoGardReq = false;

    const SDC_MRU_LIST & mruList = io_sdc.getMruList();
    int32_t calloutsPlusDimms = mruList.size();

    for ( SDC_MRU_LIST::const_iterator it = mruList.begin();
          it < mruList.end(); ++it )
    {
        PRDcallout thiscallout = it->callout;

        if ( PRDcalloutData::TYPE_SYMFRU == thiscallout.getType() )
        {
            if ( (SP_CODE     == thiscallout.flatten()) ||
                 (SYS_SW_CODE == thiscallout.flatten()) )
            {
                SW = true;

                if ( MRU_LOW != it->priority )
                {
                    sappSwNoGardReq = true;
                }

                if ( MRU_MED == it->priority )
                {
                    SW_High = true;
                }
            }
            else if ( LEVEL2_SUPPORT == thiscallout.flatten())
            {
                SecondLevel = true;

                if ( MRU_LOW != it->priority )
                {
                    sappSwNoGardReq = true;
                }
            }
        }
        else if ( PRDcalloutData::TYPE_MEMMRU == thiscallout.getType() )
        {
            MemoryMru memMru (thiscallout.flatten());
            SrcWord9 = memMru.toUint32(); // Get MemMru value

            TargetHandleList partList = memMru.getCalloutList();
            uint32_t partCount = partList.size();

            calloutsPlusDimms = calloutsPlusDimms + partCount -1;
            HW = true; //hardware callout

            if ( MRU_LOW == it->priority )
            {
                sappHwNoGardReq = true;
            }
        }
        else // PRDcalloutData::TYPE_TARGET
        {
            HW = true; // Hardware callout

            // Determines if all the hardware callouts have low priority.

            if ( MRU_LOW == it->priority )
            {
                sappHwNoGardReq = true;
            }

            if ( MACHINE_CHECK == i_attnType && it->isDefault )
            {
                #if !defined(__HOSTBOOT_MODULE) && !defined(ESW_SIM_COMPILE)
                TargetHandle_t trgt = thiscallout.getTarget();
                TargetHandle_t node = getConnectedParent( trgt, TYPE_NODE );

                errlHndl_t errl = HWSV::HostSvc::setRegNodeBootStatus( node );
                if ( nullptr != errl )
                {
                    PRDF_ERR( PRDF_FUNC "Error from HWSV::HostSvc::"
                              "setRegNodeBootStatus(0x%08x)", getHuid(node) );
                    PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                    continue;
                }
                #endif
            }
        }
    }

    ////////////////////////////////////////////////////////////////
    //Set the PRD Reason Code based on the flags set in the above callout loop.
    ////////////////////////////////////////////////////////////////

    if (HW == true && SW == true)
    {
        if (SW_High == true)
            PRD_Reason_Code = PRDF_DETECTED_FAIL_SOFTWARE_PROBABLE;
        else
            PRD_Reason_Code = PRDF_DETECTED_FAIL_HARDWARE_PROBABLE;
    }
    else if (HW == true && SW == false && SecondLevel == true)
        PRD_Reason_Code = PRDF_DETECTED_FAIL_HARDWARE_PROBABLE;
    else if (HW == true && SW == false && SecondLevel == false)
        PRD_Reason_Code = PRDF_DETECTED_FAIL_HARDWARE;
    else if (HW == false && SW == true)
        PRD_Reason_Code = PRDF_DETECTED_FAIL_SOFTWARE;
    else
    {
        // If we get here both HW and SW flags were false. Callout may be
        // Second Level Support only, or a procedure not checked in the SW
        // flag code.
        PRD_Reason_Code = PRDF_DETECTED_FAIL_HARDWARE_PROBABLE;
    }

    SrcWord7  = io_sdc.getPrimaryAttnType() << 8;
    SrcWord7 |= io_sdc.getSecondaryAttnType();

    //--------------------------------------------------------------------------
    // Check for IPL Diag Mode
    //--------------------------------------------------------------------------

    #if defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)

    iplDiagMode = PlatServices::isInMdiaMode();

    #endif

    //**************************************************************
    // Update Error Log with SRC
    //**************************************************************
    ErrorSignature * esig = io_sdc.GetErrorSignature();

    updateSrc( esig->getChipId(), SrcWord7, esig->getSigId(),
               SrcWord9, PRD_Reason_Code);

    //**************************************************************
    //  Add SDC Capture data to Error Log User Data here only if
    //    there are 4 or more callouts,
    //    (including Dimm callouts in the MemoryMru).
    //**************************************************************
    bool capDataAdded = false;
    if (calloutsPlusDimms > 3)
    {
        AddCapData( io_sdc.GetCaptureData(),    iv_errl );
        AddCapData( io_sdc.getTraceArrayData(), iv_errl );
        capDataAdded = true;
    }

    //--------------------------------------------------------------------------
    // Set the error log severity and get the error log action flags.
    //--------------------------------------------------------------------------

    // Let's assume the default is the action for a system checkstop.

    #ifdef __HOSTBOOT_MODULE
    errlSeverity_t errlSev = ERRL_SEV_UNRECOVERABLE;
    #else
    errlSeverity   errlSev = ERRL_SEV_UNRECOVERABLE;
    #endif

    uint32_t errlAct = ERRL_ACTION_SA        | // Service action required.
                       ERRL_ACTION_REPORT    | // Report to HMC and hypervisor.
                       ERRL_ACTION_CALL_HOME;  // Call home.

    if ( MACHINE_CHECK != i_attnType ) // Anything other that a system checkstop
    {
        if ( io_sdc.queryServiceCall() ) // still a serviceable event
        {
            errlSev = ERRL_SEV_PREDICTIVE;
        }
        else // not a serviceable event
        {
            errlSev = io_sdc.queryLogging()
                            ? ERRL_SEV_RECOVERED      // should still be logged
                            : ERRL_SEV_INFORMATIONAL; // can be ignored
            errlAct = ERRL_ACTION_HIDDEN;
        }
    }

    // This needs to be done after setting the SRCs otherwise it will be
    // overridden.
    iv_errl->setSev( errlSev );

    // Add procedure callout for SUE attentions. The intent is to make sure the
    // customer looks for other service actions before replacing parts for this
    // attention.
    if ( io_sdc.IsSUE() )
    {
        PRDF_HW_ADD_PROC_CALLOUT( SUE_PREV_ERR, MRU_HIGH, iv_errl, errlSev );
    }

    //--------------------------------------------------------------------------
    // Get the global gard policy.
    //--------------------------------------------------------------------------

    HWAS::GARD_ErrorType gardPolicy = HWAS::GARD_NULL;

    // Gard only if the error is a serviceable event.
    if ( io_sdc.queryServiceCall() )
    {
        // We will not Resource Recover on a checkstop attention.
        gardPolicy = ( MACHINE_CHECK == i_attnType ) ? HWAS::GARD_Fatal
                                                     : HWAS::GARD_Predictive;
    }

    if ( io_sdc.IsSUE() && ( MACHINE_CHECK == i_attnType ) )
    {
        // If we are logging an error for an SUE consumed, we should not
        // perform any GARD here. Appropriate resources should have already
        // been GARDed for the original UE.
        gardPolicy = HWAS::GARD_NULL;
    }

    // Apply special policies for OPAL.
    if ( isHyprConfigOpal() &&                          // OPAL is used
         !isMfgAvpEnabled() && !isMfgHdatAvpEnabled() ) // No AVPs running
    {
        // OPAL has requested that we disable garding for predictive errors
        // found at runtime.
        if ( HWAS::GARD_Predictive == gardPolicy )
        {
            #if !defined(__HOSTBOOT_MODULE) // FSP only

            if ( isHyprRunning() ) gardPolicy = HWAS::GARD_NULL;

            #elif defined(__HOSTBOOT_RUNTIME) // HBRT only

            gardPolicy = HWAS::GARD_NULL;

            #endif
        }
        // OPAL has requested that we diable garding for fatal errors (system
        // checkstops) that could have been caused by a software generated
        // attention at runtime. This will be determined if there is a software
        // callout with higher priority than a hardware callout.
        else if ( HWAS::GARD_Fatal == gardPolicy &&
                  sappSwNoGardReq && sappHwNoGardReq ) // Gard requirements met
        {
            #if !defined(__HOSTBOOT_MODULE) // FSP only

            if ( isHyprRunning() ) gardPolicy = HWAS::GARD_NULL;

            #endif
        }
    }

    //--------------------------------------------------------------------------
    // Get the global deconfig policy (must be done after setting gard policy).
    //--------------------------------------------------------------------------

    HWAS::DeconfigEnum deconfigPolicy = HWAS::NO_DECONFIG;

    // NOTE: If gardPolicy is HWAS::GARD_Fatal don't deconfig. The system will
    //       reboot and the garded part will be deconfigured early in the next
    //       IPL. This avoids problems where a deconfig will make the part
    //       unavailable for a dump.
    // NOTE: No deconfigs (via hardware callouts) are allowed at runtime.

    if ( HWAS::GARD_Predictive == gardPolicy )
    {
        #if !defined(__HOSTBOOT_MODULE) // FSP only

        // If we are within the reconfig loop, we can do a deconfig. Otherwise,
        // treat it as if the error happened a runtime. Note that this must be
        // a delayed deconfig to ensure we don't take an parts out from
        // underneath us during analysis.
        if ( HWSV::SvrError::isInHwReconfLoop() )
            deconfigPolicy = HWAS::DELAYED_DECONFIG;

        #elif !defined(__HOSTBOOT_RUNTIME) // Hostboot only

        // Must do a delayed deconfig to trigger a reconfig loop at the end of
        // the istep.
        deconfigPolicy = HWAS::DELAYED_DECONFIG;

        #endif
    }

    bool deferDeconfig = ( HWAS::DELAYED_DECONFIG == deconfigPolicy );

    //--------------------------------------------------------------------------
    // Get the HCDB diagnostics policy.
    //--------------------------------------------------------------------------

    // Diagnostics is only needed on the next IPL for visible logs.
    bool l_diagUpdate = ( ERRL_ACTION_HIDDEN != errlAct );

    //--------------------------------------------------------------------------
    // Initialize the PFA data
    //--------------------------------------------------------------------------

    PfaData pfaData;
    TargetHandle_t dumpTrgt;
    initPfaData( io_sdc, i_attnType, deferDeconfig, errlAct, errlSev,
                 gardPolicy, pfaData, dumpTrgt );

    //--------------------------------------------------------------------------
    // Add each mru/callout to the error log.
    //--------------------------------------------------------------------------

    for ( SDC_MRU_LIST::const_iterator it = mruList.begin();
          it < mruList.end(); ++it )
    {
        PRDcallout  thiscallout  = it->callout;
        PRDpriority thispriority = it->priority;

        // Use the global gard/deconfig policies as default.
        HWAS::GARD_ErrorType thisGard     = gardPolicy;
        HWAS::DeconfigEnum   thisDeconfig = deconfigPolicy;

        // Change the gard/deconfig actions if this MRU should not be garded.
        if ( NO_GARD == it->gardState )
        {
            thisGard     = HWAS::GARD_NULL;
            thisDeconfig = HWAS::NO_DECONFIG;
        }

        // Add the callout to the PFA data
        addCalloutToPfaData( pfaData, thiscallout, thispriority, thisGard );

        // Add callout based on callout type.
        if( PRDcalloutData::TYPE_TARGET == thiscallout.getType() )
        {
            PRDF_HW_ADD_CALLOUT(thiscallout.getTarget(),
                                thispriority,
                                thisDeconfig,
                                iv_errl,
                                thisGard,
                                errlSev,
                                l_diagUpdate);
        }
        else if (PRDcalloutData::TYPE_PROCCLK0 == thiscallout.getType())
        {
            PRDF_ADD_CLOCK_CALLOUT(iv_errl, thiscallout.getTarget(),
                                   HWAS::OSCREFCLK0_TYPE, thispriority,
                                   thisDeconfig, thisGard);
        }
        else if (PRDcalloutData::TYPE_PROCCLK1 == thiscallout.getType())
        {
            PRDF_ADD_CLOCK_CALLOUT(iv_errl, thiscallout.getTarget(),
                                   HWAS::OSCREFCLK1_TYPE, thispriority,
                                   thisDeconfig, thisGard);
        }
        else if(PRDcalloutData::TYPE_TODCLK == thiscallout.getType())
        {
            PRDF_ADD_CLOCK_CALLOUT(iv_errl,
                                   thiscallout.getTarget(),
                                   HWAS::TODCLK_TYPE,
                                   thispriority,
                                   thisDeconfig,
                                   thisGard);
        }
        else if ( PRDcalloutData::TYPE_MEMMRU == thiscallout.getType() )
        {
            MemoryMru memMru (thiscallout.flatten());

            TargetHandleList partList = memMru.getCalloutList();
            for ( TargetHandleList::iterator it = partList.begin();
                  it != partList.end(); it++ )
            {
                PRDF_HW_ADD_CALLOUT( *it,
                                     thispriority,
                                     thisDeconfig,
                                     iv_errl,
                                     thisGard,
                                     errlSev,
                                     l_diagUpdate );
            }
        }
        else if ( PRDcalloutData::TYPE_SYMFRU == thiscallout.getType() )
        {
            thisProcedureID = epubProcedureID(thiscallout.flatten());

            PRDF_DTRAC( PRDF_FUNC "thisProcedureID: %x, thispriority: %x, "
                        "errlSev: %x", thisProcedureID, thispriority,errlSev );

            PRDF_HW_ADD_PROC_CALLOUT(thisProcedureID,
                                     thispriority,
                                     iv_errl,
                                     errlSev);

            // Use the flags set earlier to determine if the callout is just
            // Software (SP code or Phyp Code). Add a Second Level Support
            // procedure callout Low, for this case.
            if (HW == false && SW == true && SecondLevel == false)
            {
                PRDF_DTRAC( PRDF_FUNC "thisProcedureID= %x, thispriority=%x, "
                            "errlSev=%x", LEVEL2_SUPPORT, MRU_LOW, errlSev );

                PRDF_HW_ADD_PROC_CALLOUT( LEVEL2_SUPPORT, MRU_LOW, iv_errl,
                                          errlSev );

                SecondLevel = true;
            }
        }
    }

    // Send the dynamic memory Dealloc message for DIMMS for Predictive
    // callouts.
    // We can not check for ERRL severity here as there are some cases
    // e.g. DD02 where we create a Predictive error log but callouts
    // are not predictive.
    if ( HWAS::GARD_Predictive == gardPolicy )
    {
        deallocateDimms( mruList );
    }

    //**************************************************************
    // Check for Terminating the system for non mnfg conditions.
    //**************************************************************

    ForceTerminate = checkForceTerm( io_sdc, dumpTrgt, pfaData );

    //*************************************************************
    // Check for Manufacturing Mode terminate here and then do
    // the needed overrides on ForceTerminate flag.
    //*************************************************************
    if ( PlatServices::mnfgTerminate() && !ForceTerminate )
    {
        ForceTerminate = true;
        if ( !((errlSev == ERRL_SEV_RECOVERED) ||
               (errlSev == ERRL_SEV_INFORMATIONAL)) &&
             iplDiagMode  &&
             !HW )
        {
            //Terminate in Manufacturing Mode, in IPL mode, for visible log, with no HW callouts.
            PRDF_SRC_WRITE_TERM_STATE_ON(iv_errl, SRCI_TERM_STATE_MNFG);
        }
        // Do not terminate if recoverable or informational.
        // Do not terminate if deferred deconfig.
        else if ( deferDeconfig                            ||
                  (errlSev == ERRL_SEV_RECOVERED    ) ||
                  (errlSev == ERRL_SEV_INFORMATIONAL)  )
        {
            ForceTerminate = false;
            errlAct |= ERRL_ACTION_DONT_TERMINATE;
        }
        else
        {
            PRDF_SRC_WRITE_TERM_STATE_ON(iv_errl, SRCI_TERM_STATE_MNFG);
        }

        pfaData.errlActions = errlAct;
    }

    // Needed to move the errl add user data sections here because of some updates
    // of the data required in the Aysnc section for the SMA dual reporting fix.

    //**************************************************************
    // Add the PFA data to Error Log User Data
    //**************************************************************
    UtilMem l_membuf;
    l_membuf << pfaData;
    PRDF_ADD_FFDC( iv_errl, (const char*)l_membuf.base(), l_membuf.size(),
                   ErrlVer1, ErrlSectPFA5_1 );

    //**************************************************************
    // Add SDC Capture data to Error Log User Data
    //**************************************************************
    // Pulled some code out to incorporate into AddCapData
    // Check to make sure Capture Data wasn't added earlier.
    if (!capDataAdded)
    {
        AddCapData( io_sdc.GetCaptureData(),    iv_errl );
        AddCapData( io_sdc.getTraceArrayData(), iv_errl );
    }

    //**************************************************************************
    // Add extended MemoryMru error log sections (if needed).
    //**************************************************************************

    for ( SDC_MRU_LIST::const_iterator it = mruList.begin();
          it < mruList.end(); ++it )
    {
        // Operate only on MemoryMru callouts.
        if ( PRDcalloutData::TYPE_MEMMRU != it->callout.getType() ) continue;

        // Only add single DIMM callouts. Otherwise, the parsed data is
        // redundant.
        MemoryMru memMru ( it->callout.flatten() );
        if ( !memMru.getSymbol().isValid() ) continue;

        // Add the MemoryMru to the capture data.
        MemCaptureData::addExtMemMruData( memMru, iv_errl );
    }

    //**************************************************************************
    // Additional FFDC
    //**************************************************************************

    // Collect PRD traces.
    // NOTE: Each line of a trace is on average 36 bytes so 768 bytes should get
    //       us around 21 lines of trace output.
    PRDF_COLLECT_TRACE(iv_errl, 768);

    //**************************************************************
    // Commit the error log.
    // This will also perform Gard and Deconfig actions.
    // Do the Unit Dumps if needed.
    //**************************************************************

    // Add the MNFG trace information.
    MnfgTrace( io_sdc.GetErrorSignature(), pfaData );

    // If this is not a terminating condition, commit the error log. If the
    // error log is not committed, the error log will be passed back to
    // PRDF::main() and eventually ATTN.
    if ( MACHINE_CHECK != pfaData.priAttnType && !ForceTerminate &&
         !pfaData.TERMINATE )
    {
        // Commit the error log.
        commitErrLog( iv_errl, pfaData );
    }

#ifndef __HOSTBOOT_MODULE
    errlHndl_t reg_errl = UtilReg::read ("prdf/RasServices", &sdcSaveFlags, sz_uint8);
    if (reg_errl)
    {
        PRDF_ERR( PRDF_FUNC "Failure in SDC Sync flag Registry read" );
        PRDF_COMMIT_ERRL(reg_errl, ERRL_ACTION_REPORT);
    }
    else
    {
        //Turn off indicator that there is saved Sdc Analysis info
        sdcSaveFlags &= ( ~SDC_ANALYSIS_SAVE_FLAG );
        reg_errl = UtilReg::write ("prdf/RasServices", &sdcSaveFlags, sz_uint8);
        if (reg_errl)
        {
            PRDF_ERR( PRDF_FUNC "Failure in SDC Sync flag Registry write" );
            PRDF_COMMIT_ERRL(reg_errl, ERRL_ACTION_REPORT);
        }
    }
#endif

    PRDF_INF( PRDF_FUNC "PRD called to analyze an error: 0x%08x 0x%08x",
              esig->getChipId(), esig->getSigId() );

    // Reset iv_errl to nullptr. This is done to catch logical bug in our code.
    // It enables us to assert in createInitialErrl function if iv_errl is
    // not nullptr which should catch any logical bug in initial stages of testing.
    errlHndl_t o_errl = iv_errl;
    iv_errl = nullptr;

    return o_errl;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void ErrDataService::initPfaData( const ServiceDataCollector & i_sdc,
                                  uint32_t i_attnType, bool i_deferDeconfig,
                                  uint32_t i_errlAct, uint32_t i_errlSev,
                                  uint32_t i_gardPolicy,
                                  PfaData & o_pfa, TargetHandle_t & o_dumpTrgt )
{
    // Dump info
    o_pfa.msDumpLabel[0] = 0x4D532020; // Start of MS Dump flags
    o_pfa.msDumpLabel[1] = 0x44554D50; // 'MS  DUMP'

    hwTableContent dumpContent;
    i_sdc.GetDumpRequest( dumpContent, o_dumpTrgt );

    o_pfa.msDumpInfo.content = dumpContent;
    o_pfa.msDumpInfo.id      = getHuid(o_dumpTrgt);

    // Error log actions and severity
    o_pfa.errlActions  = i_errlAct;
    o_pfa.errlSeverity = i_errlSev;

    // PRD Service Data Collector Flags (1:true, 0:false)
    o_pfa.DUMP                = i_sdc.IsDump()              ? 1 : 0;
    o_pfa.UERE                = i_sdc.IsUERE()              ? 1 : 0;
    o_pfa.SUE                 = i_sdc.IsSUE()               ? 1 : 0;
    o_pfa.AT_THRESHOLD        = i_sdc.IsAtThreshold()       ? 1 : 0;
    o_pfa.DEGRADED            = i_sdc.IsDegraded()          ? 1 : 0;
    o_pfa.SERVICE_CALL        = i_sdc.queryServiceCall()    ? 1 : 0;
    o_pfa.TRACKIT             = i_sdc.IsMfgTracking()       ? 1 : 0;
    o_pfa.TERMINATE           = i_sdc.Terminate()           ? 1 : 0;
    o_pfa.LOGIT               = i_sdc.queryLogging()        ? 1 : 0;
    o_pfa.MEM_CHNL_FAIL       = i_sdc.isMemChnlFail()       ? 1 : 0;
    o_pfa.PROC_CORE_CS        = i_sdc.isProcCoreCS()        ? 1 : 0;
    o_pfa.LAST_CORE_TERMINATE = 0; // Will be set later, if needed.
    o_pfa.USING_SAVED_SDC     = i_sdc.IsUsingSavedSdc()     ? 1 : 0;
    o_pfa.DEFER_DECONFIG      = i_deferDeconfig             ? 1 : 0;
    o_pfa.SECONDARY_ERROR     = i_sdc.isSecondaryErrFound() ? 1 : 0;

    // Thresholding
    o_pfa.errorCount = i_sdc.GetHits();
    o_pfa.threshold  = i_sdc.GetThreshold();

    // Misc
    o_pfa.serviceActionCounter = iv_serviceActionCounter;
    o_pfa.globalGardPolicy     = i_gardPolicy;

    // Attention types
    o_pfa.priAttnType = i_attnType;
    o_pfa.secAttnType = i_sdc.getSecondaryAttnType();

    // Initialize the MRU count to 0. Callouts will be added to the PFA data
    // when callouts are added to the error log.
    o_pfa.mruListCount = 0;

    // Build the signature list into PFA data
    const PRDF_SIGNATURES & sigList = i_sdc.getSignatureList();
    uint32_t i = 0;
    for ( i = 0; i < sigList.size() && i < SigListLIMIT; i++ )
    {
        o_pfa.sigList[i].chipId    = getHuid(sigList[i].target);
        o_pfa.sigList[i].signature = sigList[i].signature;
    }
    o_pfa.sigListCount = i;

}

//------------------------------------------------------------------------------

void ErrDataService::addCalloutToPfaData( PfaData &            io_pfa,
                                          PRDcallout           i_callout,
                                          PRDpriority          i_priority,
                                          HWAS::GARD_ErrorType i_gardType )
{
    uint32_t cnt = io_pfa.mruListCount;

    if ( MruListLIMIT > cnt )
    {
        io_pfa.mruList[cnt].callout   = i_callout.flatten();
        io_pfa.mruList[cnt].type      = i_callout.getType();
        io_pfa.mruList[cnt].priority  = i_priority;
        io_pfa.mruList[cnt].gardState = i_gardType;

        io_pfa.mruListCount++;
    }
}

//------------------------------------------------------------------------------

void ErrDataService::AddCapData( CaptureData & i_cd, errlHndl_t i_errHdl)
{
    // As CaptureDataClass has large array inside, allocate it on heap
    CaptureDataClass  *l_CapDataBuf = new CaptureDataClass() ;

    for(uint32_t ii = 0; ii < CaptureDataSize; ++ii)
    {
        l_CapDataBuf->CaptureData[ii] = 0xFF;
    }

    uint32_t thisCapDataSize =  i_cd.Copy( l_CapDataBuf->CaptureData,
                                           CaptureDataSize );

    do
    {
        if( 0 == thisCapDataSize )
        {
            // Nothing to add
            break;
        }

        l_CapDataBuf->PfaCaptureDataSize = htonl( thisCapDataSize );

        thisCapDataSize = thisCapDataSize +
                          sizeof(l_CapDataBuf->PfaCaptureDataSize);

        //Compress the Capture data
        size_t l_compressBufSize =
                PrdfCompressBuffer::compressedBufferMax( thisCapDataSize );

        uint8_t * l_compressCapBuf = new uint8_t[l_compressBufSize];

        PrdfCompressBuffer::compressBuffer( ( ( uint8_t * ) l_CapDataBuf ),
                                            (size_t) thisCapDataSize ,
                                            l_compressCapBuf,
                                            l_compressBufSize);

        //Actual size of compressed data is returned in l_compressBufSize
        //Add the Compressed Capture data to Error Log User Data
        PRDF_ADD_FFDC( i_errHdl, (const char*)l_compressCapBuf,
                       (size_t) l_compressBufSize, ErrlVer2, ErrlCapData_1 );

        delete [] l_compressCapBuf;

    }while (0);

    delete l_CapDataBuf;
}

//------------------------------------------------------------------------------

void ErrDataService::deallocateDimms( const SDC_MRU_LIST & i_mruList )
{
    #define PRDF_FUNC "[ErrDataService::deallocateDimms] "

    #if defined(__HOSTBOOT_RUNTIME) // RT only

    do
    {
        // First check if Dynamic Memory Deallocation is supported. Then check
        // if it is enabled for predictive callouts.
        // For now, this is defaulted to enabled for Phyp systems.
        // RTC 184585 will address whether we need to support disabling
        if ( !MemDealloc::isEnabled() || !isHyprConfigPhyp() ) break;

        TargetHandleList dimmList;
        for ( SDC_MRU_LIST::const_iterator it = i_mruList.begin();
              it != i_mruList.end(); ++it )
        {

            PRDcallout thiscallout = it->callout;
            if ( PRDcalloutData::TYPE_TARGET == thiscallout.getType() )
            {
                TargetHandle_t calloutTgt = thiscallout.getTarget();
                TYPE tgtType = getTargetType( calloutTgt );

                #ifdef CONFIG_NVDIMM
                // If the MRU's gard policy is set to NO_GARD, skip it.
                if ( NO_GARD == it->gardState && isNVDIMM(calloutTgt) )
                {
                    continue;
                }
                #endif

                switch ( tgtType )
                {
                    case TYPE_MC:   case TYPE_MI:  case TYPE_MCC:
                    case TYPE_OMIC: case TYPE_OMI: case TYPE_OCMB_CHIP:
                    case TYPE_MEM_PORT:
                    {
                        TargetHandleList dimms = getConnectedChildren(
                                calloutTgt, TYPE_DIMM );
                        dimmList.insert( dimmList.end(), dimms.begin(),
                                         dimms.end() );
                        break;
                    }

                    case TYPE_DIMM:
                        dimmList.push_back( calloutTgt );
                        break;

                    default: ; // nothing to do
                }
            }
            else if ( PRDcalloutData::TYPE_MEMMRU == thiscallout.getType() )
            {
                MemoryMru memMru (thiscallout.flatten());

                TargetHandleList dimms = memMru.getCalloutList();
                for ( TargetHandleList::iterator dimm = dimms.begin();
                      dimm != dimms.end(); ++dimm )
                {
                    if ( TYPE_DIMM == getTargetType(*dimm) )
                    {
                        #ifdef CONFIG_NVDIMM
                        // If the MRU's gard policy is set to NO_GARD, skip it.
                        if ( NO_GARD == it->gardState && isNVDIMM(*dimm) )
                        {
                            continue;
                        }
                        #endif

                        dimmList.push_back(*dimm);
                    }
                }
            }
        }

        if( 0 == dimmList.size() ) break;

        int32_t rc = MemDealloc::dimmList( dimmList );
        if ( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "dimmList failed" );
            break;
        }

    } while(0);

    #endif

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------
// RasServices class
//------------------------------------------------------------------------------

RasServices::RasServices() :
    iv_eds(nullptr)
{
    iv_eds = new ErrDataService();
}

//------------------------------------------------------------------------------

RasServices::~RasServices()
{
    if ( nullptr != iv_eds )
    {
        delete iv_eds;
        iv_eds = nullptr;
    }
}

//------------------------------------------------------------------------------

void RasServices::Initialize()
{
    iv_eds->Initialize();
}

//------------------------------------------------------------------------------

void RasServices::setErrDataService( ErrDataService & i_eds )
{
    if ( nullptr != iv_eds )
    {
        delete iv_eds;
        iv_eds = nullptr;
    }

    iv_eds = &i_eds;
}

//------------------------------------------------------------------------------

errlHndl_t RasServices::GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                        ServiceDataCollector & io_sdc )

{
    return iv_eds->GenerateSrcPfa( i_attnType, io_sdc );
}

//------------------------------------------------------------------------------

void RasServices::createInitialErrl( ATTENTION_TYPE i_attnType )
{
    iv_eds->createInitialErrl( i_attnType );
}

//------------------------------------------------------------------------------

errlHndl_t RasServices::getErrl() const
{
    return iv_eds->getErrl();
}

} // end namespace PRDF

/******************************************************************************/
// Servicability tags for PRDF Ras Services.
// They are located here because their position in the code is not relevant.
/******************************************************************************/

    /*@
      * @errortype
      * @reasoncode PRDF_DETECTED_FAIL_HARDWARE
      * @subsys EPUB_PROCESSOR_SUBSYS
      * @subsys EPUB_PROCESSOR_FRU
      * @subsys EPUB_PROCESSOR_CHIP_CACHE
      * @subsys EPUB_PROCESSOR_UNIT
      * @subsys EPUB_PROCESSOR_BUS_CTL
      * @subsys EPUB_MEMORY_SUBSYS
      * @subsys EPUB_MEMORY_CONTROLLER
      * @subsys EPUB_MEMORY_DIMM
      * @subsys EPUB_MEMORY_FRU
      * @subsys EPUB_EXTERNAL_CACHE
      * @subsys EPUB_CEC_HDW_SUBSYS
      * @subsys EPUB_CEC_HDW_CLK_CTL
      * @subsys EPUB_CEC_HDW_TOD_HDW
      * @subsys EPUB_CEC_HDW_SP_PHYP_INTF
      * @subsys EPUB_MISC_SUBSYS
      * @subsys EPUB_MISC_UNKNOWN
      * @subsys EPUB_MISC_INFORMATIONAL
      * @subsys EPUB_FIRMWARE_SUBSYS
      * @subsys EPUB_FIRMWARE_SP
      * @subsys EPUB_FIRMWARE_PHYP
      * @subsys EPUB_FIRMWARE_HMC
      * @subsys EPUB_EXT_ENVIRO_USER
      * @moduleid PRDF_MAIN
      * @userdata1  PRD Chip Signature
      * @userdata2  PRD Attention Type and Cause Attention Type
      * @userdata3  PRD Signature
      * @devdesc CEC hardware failure detected.
      * @procedure  EPUB_PRC_ALL_PROCS
      * @procedure  EPUB_PRC_REBOOT
      * @procedure  EPUB_PRC_TOD_CLOCK_ERR
      */

    /*@
      * @errortype
      * @reasoncode PRDF_DETECTED_FAIL_HARDWARE_PROBABLE
      * @subsys EPUB_PROCESSOR_SUBSYS
      * @subsys EPUB_PROCESSOR_FRU
      * @subsys EPUB_PROCESSOR_CHIP_CACHE
      * @subsys EPUB_PROCESSOR_UNIT
      * @subsys EPUB_PROCESSOR_BUS_CTL
      * @subsys EPUB_MEMORY_SUBSYS
      * @subsys EPUB_MEMORY_CONTROLLER
      * @subsys EPUB_MEMORY_DIMM
      * @subsys EPUB_MEMORY_FRU
      * @subsys EPUB_EXTERNAL_CACHE
      * @subsys EPUB_CEC_HDW_SUBSYS
      * @subsys EPUB_CEC_HDW_CLK_CTL
      * @subsys EPUB_CEC_HDW_TOD_HDW
      * @subsys EPUB_CEC_HDW_SP_PHYP_INTF
      * @subsys EPUB_MISC_SUBSYS
      * @subsys EPUB_MISC_UNKNOWN
      * @subsys EPUB_MISC_INFORMATIONAL
      * @subsys EPUB_FIRMWARE_SUBSYS
      * @subsys EPUB_FIRMWARE_SP
      * @subsys EPUB_FIRMWARE_PHYP
      * @subsys EPUB_FIRMWARE_HMC
      * @subsys EPUB_EXT_ENVIRO_USER
      * @moduleid PRDF_MAIN
      * @userdata1  PRD Chip Signature
      * @userdata2  PRD Attention Type and Cause Attention Type
      * @userdata3  PRD Signature
      * @devdesc CEC hardware failure detected. Cause is most likely hardware,
      *          but there are other callouts including Software or Next Level
      *          Support.
      * @procedure EPUB_PRC_SP_CODE
      * @procedure  EPUB_PRC_PHYP_CODE
      * @procedure  EPUB_PRC_LVL_SUPP
      * @procedure  EPUB_PRC_ALL_PROCS
      * @procedure  EPUB_PRC_REBOOT
      * @procedure  EPUB_PRC_TOD_CLOCK_ERR
      */

    /*@
      * @errortype
      * @reasoncode PRDF_DETECTED_FAIL_SOFTWARE_PROBABLE
      * @subsys EPUB_PROCESSOR_SUBSYS
      * @subsys EPUB_PROCESSOR_FRU
      * @subsys EPUB_PROCESSOR_CHIP_CACHE
      * @subsys EPUB_PROCESSOR_UNIT
      * @subsys EPUB_PROCESSOR_BUS_CTL
      * @subsys EPUB_MEMORY_SUBSYS
      * @subsys EPUB_MEMORY_CONTROLLER
      * @subsys EPUB_MEMORY_DIMM
      * @subsys EPUB_MEMORY_FRU
      * @subsys EPUB_EXTERNAL_CACHE
      * @subsys EPUB_CEC_HDW_SUBSYS
      * @subsys EPUB_CEC_HDW_CLK_CTL
      * @subsys EPUB_CEC_HDW_TOD_HDW
      * @subsys EPUB_CEC_HDW_SP_PHYP_INTF
      * @subsys EPUB_MISC_SUBSYS
      * @subsys EPUB_MISC_UNKNOWN
      * @subsys EPUB_MISC_INFORMATIONAL
      * @subsys EPUB_FIRMWARE_SUBSYS
      * @subsys EPUB_FIRMWARE_SP
      * @subsys EPUB_FIRMWARE_PHYP
      * @subsys EPUB_FIRMWARE_HMC
      * @subsys EPUB_EXT_ENVIRO_USER
      * @moduleid PRDF_MAIN
      * @userdata1  PRD Chip Signature
      * @userdata2  PRD Attention Type and Cause Attention Type
      * @userdata3  PRD Signature
      * @devdesc CEC hardware failure detected. Cause is most likley Software,
      *          but there are also Hardware callouts.
      * @procedure EPUB_PRC_SP_CODE
      * @procedure  EPUB_PRC_PHYP_CODE
      * @procedure  EPUB_PRC_LVL_SUPP
      * @procedure  EPUB_PRC_ALL_PROCS
      * @procedure  EPUB_PRC_REBOOT
      * @procedure  EPUB_PRC_TOD_CLOCK_ERR
      */

    /*@
      * @errortype
      * @reasoncode PRDF_DETECTED_FAIL_SOFTWARE
      * @subsys EPUB_MISC_SUBSYS
      * @subsys EPUB_MISC_UNKNOWN
      * @subsys EPUB_FIRMWARE_SUBSYS
      * @subsys EPUB_FIRMWARE_SP
      * @subsys EPUB_FIRMWARE_PHYP
      * @subsys EPUB_FIRMWARE_HMC
      * @moduleid PRDF_MAIN
      * @userdata1  PRD Chip Signature
      * @userdata2  PRD Attention Type and Cause Attention Type
      * @userdata3  PRD Signature
      * @devdesc CEC hardware failure detected. Cause is most likely Software.
      * @procedure EPUB_PRC_SP_CODE
      * @procedure  EPUB_PRC_PHYP_CODE
      * @procedure  EPUB_PRC_LVL_SUPP
      * @procedure  EPUB_PRC_ALL_PROCS
      * @procedure  EPUB_PRC_REBOOT
      * @procedure  EPUB_PRC_TOD_CLOCK_ERR
      */

