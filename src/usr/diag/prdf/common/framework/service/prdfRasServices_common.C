/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfRasServices_common.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

/** @file  prdfRasServices_common.H
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

// For compression routines
#define PRDF_COMPRESSBUFFER_COMPRESS_FUNCTIONS
#include <prdfCompressBuffer.H>

#include <utilmem.H> //For UtilMem stream class (outputting PfaData).
#include <utilfile.H>
#include <vector>
#include <algorithm>
#include <iipSystem.h>         //For RemoveStoppedChips

#ifdef __HOSTBOOT_MODULE
  #include <stdio.h>
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

bool ErrDataService::terminateOnCheckstop = true;
RasServices thisServiceGenerator;

//------------------------------------------------------------------------------
// Member Functions
//------------------------------------------------------------------------------

ServiceGeneratorClass & ServiceGeneratorClass::ThisServiceGenerator(void)
{
  return thisServiceGenerator;
}

//------------------------------------------------------------------------------

RasServices::RasServices() :
    iv_ErrDataService(NULL)
{
    //PRDF_DTRAC("RasServices() initializing default iv_ErrDataService");
    iv_ErrDataService = new ErrDataService();
}

//------------------------------------------------------------------------------
RasServices::~RasServices()
{
    if(NULL != iv_ErrDataService)
    {
        PRDF_DTRAC("~RasServices() deleting iv_ErrDataService");
        delete iv_ErrDataService;
        iv_ErrDataService = NULL;
    }
}

//------------------------------------------------------------------------------

void ErrDataService::Initialize()
{
    iv_serviceActionCounter = 0;
}

void RasServices::Initialize()
{
    iv_ErrDataService->Initialize();
}

//------------------------------------------------------------------------------

void RasServices::setErrDataService(ErrDataService & i_ErrDataService)
{
    PRDF_TRAC("RasServices::setErrDataService() setting new ErrDataService");

    if(NULL != iv_ErrDataService)
    {
        PRDF_DTRAC("RasServices::setErrDataService() deleting old iv_ErrDataService");
        delete iv_ErrDataService;
        iv_ErrDataService = NULL;
    }

    iv_ErrDataService = &i_ErrDataService;
}

//------------------------------------------------------------------------------

void ErrDataService::SetErrorTod(ATTENTION_TYPE the_attention,
                                 ServiceDataCollector & sdc)
{
  Timer l_curEventTime;
  PlatServices::getCurrentTime(l_curEventTime);
  sdc.SetTOE(l_curEventTime);
}

void RasServices::SetErrorTod(ATTENTION_TYPE the_attention,
                              ServiceDataCollector & sdc)
{
    iv_ErrDataService->SetErrorTod(the_attention, sdc);
}

//------------------------------------------------------------------------------

bool ErrDataService::QueryLoggingBufferFull(void) const
{
    return (loggingBufferFull);
}

bool RasServices::QueryLoggingBufferFull(void) const
{
    return iv_ErrDataService->QueryLoggingBufferFull();
}

//------------------------------------------------------------------------------

void ErrDataService ::SaveRcForSrc(int32_t the_rc)
{
    savedPrdReturnCode = the_rc;
}

void RasServices::SaveRcForSrc(int32_t the_rc)
{
    iv_ErrDataService->SaveRcForSrc(the_rc);
}

//------------------------------------------------------------------------------

errlHndl_t RasServices::GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                        ServiceDataCollector & i_sdc )

{
    return iv_ErrDataService->GenerateSrcPfa( i_attnType, i_sdc );
}

//------------------------------------------------------------------------------

errlHndl_t ErrDataService::GenerateSrcPfa( ATTENTION_TYPE i_attnType,
                                           ServiceDataCollector & i_sdc )
{
    #define PRDF_FUNC "[ErrDataService::GenerateSrcPfa] "

#ifdef __HOSTBOOT_MODULE
    using namespace ERRORLOG;
    using namespace HWAS;
    errlSeverity_t severityParm = ERRL_SEV_RECOVERED;
#else
    bool causeAttnPreviouslyReported = false;
    uint8_t sdcSaveFlags = SDC_NO_SAVE_FLAGS;
    size_t  sz_uint8    = sizeof(uint8_t);
    uint8_t sdcBuffer[sdcBufferSize];  //buffer to use for sdc flatten
    errlSeverity severityParm = ERRL_SEV_RECOVERED;
#endif

    SDC_MRU_LIST fspmrulist;
    PRDcallout thiscallout;
    PRDpriority thispriority;
    epubProcedureID thisProcedureID;

    // Init Action Parm to most common usage, Service Action Required and
    // Report Externally. Note this is like the old Signal
    // Event: OS Viewable (Parable) or OS Hidden.
    // Also set the Call Home Flag. This should be set when IBM Service is required.
    // For PRD this is for UnRecoverable and Predictive errors. Setting it here will
    // take care of this. The Hidden and Informational cases will reassign the actionFlag.
    uint32_t actionFlag = (ERRL_ACTION_SA | ERRL_ACTION_REPORT | ERRL_ACTION_CALL_HOME);

    HWSV::hwsvDiagUpdate l_diagUpdate = HWSV::HWSV_DIAG_NEEDED;

    // Use this SDC unless determined in Check Stop processing to use a UE,
    // or SUE saved SDC
    sdc = i_sdc;

    GardAction::ErrorType prdGardErrType;
    HWAS::GARD_ErrorType gardErrType = HWAS::GARD_NULL;
    HWAS::DeconfigEnum deconfigState = HWAS::NO_DECONFIG;

    bool ReturnELog = false;
    bool ForceTerminate = false;
    bool iplDiagMode = false;
    bool deferDeconfig = false;

    ++iv_serviceActionCounter;

    uint16_t PRD_Reason_Code = 0;

    //**************************************************************
    // Initial set up by Attention Type
    //**************************************************************

    ////////////////////////////////////////////////////////////////
    // Machine Check ATTN (CHECKSTOP)
    ////////////////////////////////////////////////////////////////
    if (i_attnType == MACHINE_CHECK)
    {
#ifdef  __HOSTBOOT_MODULE

        PRDF_ERR( PRDF_FUNC"Hostboot should NOT have any system checkstop!" );
#else
        ReturnELog = true;

        severityParm = ERRL_SEV_UNRECOVERABLE;

        // Check for SUE-CS condition flags.
        if ((!sdc.IsUERE() ) &&
            ( sdc.IsSUE()  )   )
        {
            //Read current sdc state flags from registry
            errlHndl_t errorLog = UtilReg::read ( "prdf/RasServices",
                                                  &sdcSaveFlags, sz_uint8 );
            if (errorLog)
            {
                PRDF_ERR( PRDF_FUNC"Failure in SDC flag Registry read" );
                PRDF_COMMIT_ERRL(errorLog, ERRL_ACTION_REPORT);
            }
            else if (sdcSaveFlags & SDC_SAVE_UE_FLAG) //check if UE log stored
            {                                         // then use it.
                bool l_rc = SdcRetrieve(SDC_SAVE_UE_FLAG, sdcBuffer);
                if (l_rc)
                {
                    PRDF_ERR( PRDF_FUNC"Failure in UE SDC Retrieve Function" );
                }
                else
                {
                    ErrorSignature secSig = *(sdc.GetErrorSignature());
                    //set the sdc to the Saved SDC for UE
                    sdc = sdcBuffer;
                    // Add secondary signature
                    sdc.AddSignatureList( secSig );
                    gardErrType = HWAS::GARD_Fatal;
                    causeAttnPreviouslyReported = true;
                }
            }
            else if (sdcSaveFlags & SDC_SAVE_SUE_FLAG ) //else check if SUE log
            {                                           // stored then use it.
                bool l_rc = SdcRetrieve(SDC_SAVE_SUE_FLAG, sdcBuffer);
                if (l_rc)
                {
                    PRDF_ERR( PRDF_FUNC"Failure in SUE SDC Retrieve Function" );
                }
                else
                {
                    ErrorSignature secSig = *(sdc.GetErrorSignature());
                    //set the sdc to the Saved SDC for SUE
                    sdc = sdcBuffer;
                    // Add secondary signature
                    sdc.AddSignatureList( secSig );
                    gardErrType = HWAS::GARD_Fatal;
                    causeAttnPreviouslyReported = true;
                }
            }
        }
#endif  // if not __HOSTBOOT_MODULE
    }
    ////////////////////////////////////////////////////////////////
    // Recoverable ATTN or Unit CheckStop
    ////////////////////////////////////////////////////////////////
    else if (i_attnType == RECOVERABLE  || i_attnType == UNIT_CS )
    {
#ifndef  __HOSTBOOT_MODULE
        if //Ue-Re RECOVERABLE condition.
            ((sdc.IsUERE()   ) &&
             (!sdc.IsSUE()   ) &&
             (!sdc.IsUsingSavedSdc() ) )  // Don't save File if we are Re-Syncing an sdc
        {
            bool l_rc = SdcSave(SDC_SAVE_UE_FLAG, i_sdc);
            if (l_rc)
            {
                PRDF_ERR( PRDF_FUNC"Failure in UE SDC Save Function" );
            }
        }
        else if //Sue-Re RECOVERABLE condition.
            ((!sdc.IsUERE()   ) &&
             (sdc.IsSUE()     ) &&
             (!sdc.IsUsingSavedSdc() ) )  // Don't save File if we are Re-Syncing an sdc

        {
            bool l_rc = SdcSave(SDC_SAVE_SUE_FLAG, i_sdc);
            if (l_rc)
            {
                PRDF_ERR( PRDF_FUNC"Failure in SUE SDC Save Function" );
            }
        }
#endif  // if not __HOSTBOOT_MODULE

        if (!sdc.IsLogging() )
        {
            // This is a Hidden Log
            severityParm = ERRL_SEV_INFORMATIONAL;
            actionFlag = (actionFlag | ERRL_ACTION_HIDDEN);
        }
        else if ( sdc.IsServiceCall() ) //At Thresold
        {
            severityParm = ERRL_SEV_PREDICTIVE;
        }
        else  //Recovered
        {
            severityParm = ERRL_SEV_RECOVERED;
            //  Recovered error should be Hidden, and No Service Action
            actionFlag = ERRL_ACTION_HIDDEN;
        }
    }
    ////////////////////////////////////////////////////////////////
    // Special ATTN
    ////////////////////////////////////////////////////////////////
    else if (i_attnType == SPECIAL)
    {
        if (sdc.IsServiceCall())
        //Bit Steered already, or Bit Steer Not supported
        {
            severityParm = ERRL_SEV_PREDICTIVE;
        }
        else if ( (!sdc.IsServiceCall()) && (!sdc.IsLogging()) ) // Special Attn Clean Up
        {
            severityParm = ERRL_SEV_INFORMATIONAL;
            //Hidden, No Service Action for Infomational
            actionFlag = ERRL_ACTION_HIDDEN;
        }
        else if ( (!sdc.IsServiceCall()) && (sdc.IsLogging()) ) // Special Attn Bit Steer Normal Condition
        {
            severityParm = ERRL_SEV_RECOVERED;
            //Hidden, No Service Action for Recovered
            actionFlag = ERRL_ACTION_HIDDEN;
        }
    }

    //**************************************************************
    // Set Gard Error Type and state
    //**************************************************************

    // If gardErrType was determined during UE/SUE processing for Check Stop,
    // use that and not determine gardErrType from the sdc values.
    if (gardErrType != HWAS::GARD_Fatal)
    {
        prdGardErrType = sdc.QueryGard();
        switch (prdGardErrType)
        {
            case GardAction::NoGard:
                gardErrType = HWAS::GARD_NULL;
                break;
            case GardAction::Predictive:
                gardErrType = HWAS::GARD_Predictive;
                break;
            case GardAction::Fatal:
                gardErrType = HWAS::GARD_Fatal;
                break;
            case GardAction::CheckStopOnlyGard:
                if  (MACHINE_CHECK == i_attnType)
                {
                    gardErrType = HWAS::GARD_Fatal;
                }
                else
                {
                    gardErrType = HWAS::GARD_NULL;
                }
                break;
            case GardAction::DeconfigNoGard:
                gardErrType = HWAS::GARD_NULL;
                break;
            default:
                gardErrType = HWAS::GARD_NULL;
                PRDF_DTRAC( PRDF_FUNC"Unknown prdGardErrType" );
                break;
        }
    }
    else
    {
        // gardErrType is GARD_Fatal, set in UE/SUE processing for Check Stop.
        // If NoGard was specified in this switched sdc, then keep the NoGard
        if ( sdc.QueryGard() == GardAction::NoGard )
        {
            gardErrType = HWAS::GARD_NULL;
            prdGardErrType = GardAction::NoGard;
        }
        else
        {
            prdGardErrType = GardAction::Fatal;
        }
    }

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
    fspmrulist = sdc.GetMruList();
    int32_t calloutsPlusDimms = fspmrulist.size();
    for (SDC_MRU_LIST::iterator i = fspmrulist.begin(); i < fspmrulist.end(); ++i)
    {
        thiscallout = i->callout;
        if ( PRDcalloutData::TYPE_SYMFRU == thiscallout.getType() )
        {
            if ( (EPUB_PRC_SP_CODE   == thiscallout.flatten()) ||
                 (EPUB_PRC_PHYP_CODE == thiscallout.flatten()) )
            {
                SW = true;
                if ( MRU_MED == i->priority )
                {
                    SW_High = true;
                }
            }
            else if ( EPUB_PRC_LVL_SUPP == thiscallout.flatten())
            {
                SecondLevel = true;
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

        }
        else // PRDcalloutData::TYPE_TARGET
        {
            HW = true; // Hardware callout
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

    SrcWord7  = i_sdc.GetAttentionType() << 8;
    SrcWord7 |= i_sdc.GetCauseAttentionType();

    //--------------------------------------------------------------------------
    // Check for IPL Diag Mode and set up for Deferred Deconfig
    //--------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

    iplDiagMode = PlatServices::isInMdiaMode();

    // Deferred Deconfig should be used throughout all of Hostboot (both
    // checkForIplAttns() and MDIA).
    if ( (HWAS::GARD_NULL != gardErrType) ||
         (GardAction::DeconfigNoGard == prdGardErrType) )
    {
        deferDeconfig = true;
        deconfigState = HWAS::DECONFIG;
    }

#endif


    //**************************************************************
    // Update Error Log with SRC
    //**************************************************************
    ErrorSignature * esig = sdc.GetErrorSignature();

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
        AddCapData(sdc.GetCaptureData(),iv_errl);
        capDataAdded = true;
    }

    // make sure serviceAction doesn't override errl severity
    iv_errl->setSev(severityParm);

    if (ERRL_ACTION_HIDDEN == actionFlag)
    {  // Diagnostics is not needed in the next IPL cycle for non-visible logs
        l_diagUpdate = HWSV::HWSV_DIAG_NOT_NEEDED;
    }

    //**************************************************************
    // Add each mru/callout to the error log.
    //**************************************************************

    // Change deconfigState only based on Gard Types.
    // This only affects FSP code since Hostboot macro is no-op.
    // This is needed for FSP Reconfig Loop to work.
    if ( (HWAS::GARD_NULL != gardErrType) ||
         (GardAction::DeconfigNoGard == prdGardErrType) )
    {
        PRDF_RECONFIG_LOOP(deconfigState);
    }

    fspmrulist = sdc.GetMruList();
    for ( SDC_MRU_LIST::iterator i = fspmrulist.begin();
          i < fspmrulist.end(); ++i )
    {
        thispriority = (*i).priority;
        thiscallout = (*i).callout;
        if ( PRDcalloutData::TYPE_TARGET == thiscallout.getType() )
        {
            PRDF_HW_ADD_CALLOUT(thiscallout.getTarget(),
                                thispriority,
                                deconfigState,
                                iv_errl,
                                gardErrType,
                                severityParm,
                                l_diagUpdate);

        }
        else if(PRDcalloutData::TYPE_PROCCLK == thiscallout.getType() ||
                PRDcalloutData::TYPE_PCICLK  == thiscallout.getType())
        {
            PRDF_ADD_CLOCK_CALLOUT(iv_errl,
                                   thiscallout.getTarget(),
                                   thiscallout.getType(),
                                   thispriority,
                                   deconfigState,
                                   gardErrType);
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
                                     deconfigState,
                                     iv_errl,
                                     gardErrType,
                                     severityParm,
                                     l_diagUpdate );
            }
        }
        else if ( PRDcalloutData::TYPE_SYMFRU == thiscallout.getType() )
        {
            thisProcedureID = epubProcedureID(thiscallout.flatten());

            PRDF_DTRAC( PRDF_FUNC"thisProcedureID: %x, thispriority: %x, severityParm: %x",
                   thisProcedureID, thispriority,severityParm );

            PRDF_HW_ADD_PROC_CALLOUT(thisProcedureID,
                                     thispriority,
                                     iv_errl,
                                     severityParm);

            // Use the flags set earlier to determine if the callout is just Software (SP code or Phyp Code).
            // Add a Second Level Support procedure callout Low, for this case.
            if (HW == false && SW == true && SecondLevel == false)
            {
                PRDF_DTRAC( PRDF_FUNC"thisProcedureID= %x, thispriority=%x, severityParm=%x",
                   EPUB_PRC_LVL_SUPP, MRU_LOW, severityParm );

                PRDF_HW_ADD_PROC_CALLOUT(EPUB_PRC_LVL_SUPP,
                                         MRU_LOW,
                                         iv_errl,
                                         severityParm);

                SecondLevel = true;
            }

        }
    }

    // Send the dynamic memory Dealloc message for DIMMS for Predictive
    // callouts.
    // We can not check for ERRL severity here as there are some cases
    // e.g. DD02 where we create a Predictive error log but callouts
    // are not predictive.
    if ( HWAS::GARD_Predictive == gardErrType )
    {
        deallocateDimms( fspmrulist );
    }

    //**************************************************************
    // Build Dump Flags and PFA5 data
    //**************************************************************

    PfaData pfaData;
    TargetHandle_t dumpTrgt = NULL;

    initPfaData( sdc, i_attnType, deferDeconfig, actionFlag, severityParm,
                 prdGardErrType, pfaData, dumpTrgt );

    HUID dumpId       = pfaData.msDumpInfo.id;
    TYPE dumpTrgtType = getTargetType( dumpTrgt );

    //**************************************************************
    // Check for Unit CheckStop.
    // Check for Last Functional Core.
    // PFA data updates for these item.
    //**************************************************************

    // Now the check is for Unit Check Stop and Dump ID for Processor
    // Skip the termination on Last Core if this is a Saved SDC
    if ( sdc.IsUnitCS() && !sdc.IsUsingSavedSdc() )
    {
        PRDF_TRAC( PRDF_FUNC"Unit CS on HUID: 0x%08x", dumpId );

        if ( TYPE_CORE == dumpTrgtType )
        {
            // Check if this is last functional core
            if ( PlatServices::checkLastFuncCore(dumpTrgt) )
            {
                PRDF_TRAC(PRDF_FUNC"Last Functional Core HUID: 0x%08x", dumpId);

                ForceTerminate = true;
                pfaData.LAST_CORE_TERMINATE = 1;
                iv_errl->setSev(ERRL_SEV_UNRECOVERABLE);
                pfaData.errlSeverity = ERRL_SEV_UNRECOVERABLE;
            }
        }
    }

    // Check the errl for the terminate state
    // Note: will also be true for CheckStop attn.
    bool l_termSRC = false;
    PRDF_GET_TERM_SRC(iv_errl, l_termSRC);
    if(l_termSRC)
    {
        ForceTerminate = true;
        uint32_t l_plid = 0;
        PRDF_GET_PLID(iv_errl, l_plid);
        PRDF_INF(PRDF_FUNC"check for isTerminateSRC is true. PLID=%.8X", l_plid);
    }

    //*************************************************************
    // Must check for Manufacturing Mode terminate here and then do
    // the needed overrides on ForceTerminate flag.
    //*************************************************************
    if ( PlatServices::mnfgTerminate() && !ForceTerminate )
    {
        ForceTerminate = true;
        if ( !((severityParm == ERRL_SEV_RECOVERED) ||
               (severityParm == ERRL_SEV_INFORMATIONAL)) &&
             iplDiagMode  &&
             !HW )
        {
            //Terminate in Manufacturing Mode, in IPL mode, for visible log, with no HW callouts.
            PRDF_SRC_WRITE_TERM_STATE_ON(iv_errl, SRCI_TERM_STATE_MNFG);
        }
        // Do not terminate if recoverable or informational.
        // Do not terminate if deferred deconfig.
        else if ( deferDeconfig                            ||
                  (severityParm == ERRL_SEV_RECOVERED    ) ||
                  (severityParm == ERRL_SEV_INFORMATIONAL)  )
        {
            ForceTerminate = false;
            actionFlag = (actionFlag | ERRL_ACTION_DONT_TERMINATE);
        }
        else
        {
            PRDF_SRC_WRITE_TERM_STATE_ON(iv_errl, SRCI_TERM_STATE_MNFG);
        }

        pfaData.errlActions = actionFlag;
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
        AddCapData(sdc.GetCaptureData() ,iv_errl);
    }

    // Note moved the code from here, that was associated with checking for the last
    // functional core to be before the PFA data is placed in error log.

    // Collect PRD trace
    // NOTE: Each line of trace is on average 36 bytes so 768 bytes should get
    //       us around 21 lines of trace output.
    PRDF_COLLECT_TRACE(iv_errl, 768);

    //**************************************************************
    // Commit the eror log.
    // This will also perform Gard and Deconfig actions.
    // Do the Unit Dumps if needed.
    //**************************************************************
    if (sdc.IsDontCommitErrl() && !sdc.IsUnitCS() && (MACHINE_CHECK != i_attnType) )
    {
        delete iv_errl;
        iv_errl = NULL;
    }
    else if ( !ReturnELog && !ForceTerminate && !i_sdc.Terminate() )
    {
        // Check to see if we need to do a Proc Core dump
        if ( sdc.IsUnitCS() && !sdc.IsUsingSavedSdc() )
        {
            if ( dumpTrgtType == TYPE_PROC )
            {
                // NX Unit Checktop - runtime deconfig each accelerator
                int32_t l_rc = SUCCESS;
                SDC_MRU_LIST mrulist = sdc.GetMruList();
                for ( SDC_MRU_LIST::iterator i = mrulist.begin();
                      i < mrulist.end(); ++i )
                {
                    /* FIXME: need to add accelerators runtime deconfig
                    TargetHandle_t accelTarget = i->callout.getMruValues();
                    if ( TYPE_CORE == PlatServices::getTargetType(accelTarget) )
                    {
                        l_rc = PRDF_RUNTIME_DECONFIG( accelTarget );
                        if ( SUCCESS != l_rc )
                            break;
                    }
                    */
                }

                if ( SUCCESS == l_rc )
                {
                    l_rc = PRDF_HWUDUMP( iv_errl, CONTENT_HWNXLCL,
                                         dumpId );
                }
            }
            else if (dumpTrgtType == TYPE_MEMBUF ||
                     dumpTrgtType == TYPE_MBA    ||
                     dumpTrgtType == TYPE_MCS)
            {
                // Centaur Checkstop
                TargetHandle_t centaurHandle = dumpTrgt;
                if ( TYPE_MCS == dumpTrgtType )
                {
                    centaurHandle = getConnectedChild( dumpTrgt,
                                                       TYPE_MEMBUF, 0 );
                }
                else if ( TYPE_MBA == dumpTrgtType )
                {
                    centaurHandle = getConnectedParent( dumpTrgt,
                                                        TYPE_MEMBUF );
                }

                if (centaurHandle)
                {
                    int32_t l_rc = PRDF_RUNTIME_DECONFIG(centaurHandle,
                                                         iv_errl,
                                                         false);
                    if ( SUCCESS != l_rc )
                    {
                        PRDF_ERR( PRDF_FUNC"runtime deconfig failed 0x%08x",
                                  dumpId );
                    }
                    // No unit dump for Centaur checkstop
                }
            }
            else
            {
                int32_t l_rc = PRDF_RUNTIME_DECONFIG( dumpTrgt, iv_errl,
                                                      true);
                if ( SUCCESS == l_rc )
                {
                    // Call Dump for Proc Core CS
                    if ( TYPE_EX == dumpTrgtType )
                    {
                        l_rc = PRDF_HWUDUMP( iv_errl,
                                             CONTENT_SINGLE_CORE_CHECKSTOP,
                                             dumpId );
                    }
                    // FIXME: Will need to add Centaur DMI channel checkstop
                    //        support later.
                    else
                    {
                        PRDF_ERR( PRDF_FUNC"Unsupported dump for target 0x%08x",
                                  dumpId );
                    }
                }
            }
        }

        // Commit the Error log
        // Need to move below here since we'll need
        // to pass iv_errl to PRDF_HWUDUMP
        // for FSP specific SRC handling in the future
        MnfgTrace( esig, pfaData );

        PRDF_HW_COMMIT_ERRL( iv_errl, actionFlag );
        if ( NULL != iv_errl )
        {
            // Just commit the log.
            uint32_t dumpPlid = 0;
            PRDF_GET_PLID(iv_errl, dumpPlid);

            uint32_t l_rc = 0;
            PRDF_GET_RC(iv_errl, l_rc);

            uint16_t l_reasonCode = 0;
            PRDF_GET_REASONCODE(iv_errl, l_reasonCode);

            PRDF_INF( PRDF_FUNC"Committing error log: PLID=%.8X, "
                               "ReasonCode=%.8X, RC=%.8X, actions=%.4X",
                               dumpPlid, l_reasonCode, l_rc, actionFlag );

            PRDF_COMMIT_ERRL(iv_errl, actionFlag);
        }
    }
    // If the Error Log is not committed (as due to a Terminate condtion),
    // the Error Log will be returned to PRDMain
    else
    {

        MnfgTrace( esig, pfaData );

        PRDF_DTRAC( PRDF_FUNC"generating a terminating, or MP Fatal SRC" );
    }

#ifndef __HOSTBOOT_MODULE
    errlHndl_t reg_errl = UtilReg::read ("prdf/RasServices", &sdcSaveFlags, sz_uint8);
    if (reg_errl)
    {
        PRDF_ERR( PRDF_FUNC"Failure in SDC Sync flag Registry read" );
        PRDF_COMMIT_ERRL(reg_errl, ERRL_ACTION_REPORT);
    }
    else
    {
        //Turn off indicator that there is saved Sdc Analysis info
        sdcSaveFlags &= ( ~SDC_ANALYSIS_SAVE_FLAG );
        reg_errl = UtilReg::write ("prdf/RasServices", &sdcSaveFlags, sz_uint8);
        if (reg_errl)
        {
            PRDF_ERR( PRDF_FUNC"Failure in SDC Sync flag Registry write" );
            PRDF_COMMIT_ERRL(reg_errl, ERRL_ACTION_REPORT);
        }
    }
#endif

    PRDF_INF( PRDF_FUNC"PRD called to analyze an error: 0x%08x 0x%08x",
              esig->getChipId(), esig->getSigId() );

    //prints debug traces

    printDebugTraces();

    // Reset iv_errl to NULL. This is done to catch logical bug in our code.
    // It enables us to assert in createInitialErrl function if iv_errl is
    // not NULL which should catch any logical bug in initial stages of testing.
    errlHndl_t o_errl = iv_errl;
    iv_errl = NULL;

    return o_errl;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void ErrDataService::initPfaData( ServiceDataCollector & i_sdc,
                                  uint32_t i_attnType, bool i_deferDeconfig,
                                  uint32_t i_errlAct, uint32_t i_errlSev,
                                  uint32_t i_prdGardType,
                                  PfaData & o_pfa, TargetHandle_t & o_dumpTrgt )
{
    // Dump info
    o_pfa.msDumpLabel[0] = 0x4D532020; // Start of MS Dump flags
    o_pfa.msDumpLabel[1] = 0x44554D50; // 'MS  DUMP'

    hwTableContent dumpContent;
    i_sdc.GetDumpRequest( dumpContent, o_dumpTrgt );
    o_pfa.msDumpInfo.content = dumpContent;

    o_pfa.msDumpInfo.id = getHuid(o_dumpTrgt);

    // Error log actions and severity
    o_pfa.errlActions  = i_errlAct;
    o_pfa.errlSeverity = i_errlSev;

    // PRD Service Data Collector Flags (1:true, 0:false)
    o_pfa.DUMP                = i_sdc.IsDump()          ? 1 : 0;
    o_pfa.UERE                = i_sdc.IsUERE()          ? 1 : 0;
    o_pfa.SUE                 = i_sdc.IsSUE()           ? 1 : 0;
    o_pfa.AT_THRESHOLD        = i_sdc.IsAtThreshold()   ? 1 : 0;
    o_pfa.DEGRADED            = i_sdc.IsDegraded()      ? 1 : 0;
    o_pfa.SERVICE_CALL        = i_sdc.IsServiceCall()   ? 1 : 0;
    o_pfa.TRACKIT             = i_sdc.IsMfgTracking()   ? 1 : 0;
    o_pfa.TERMINATE           = i_sdc.Terminate()       ? 1 : 0;
    o_pfa.LOGIT               = i_sdc.IsLogging()       ? 1 : 0;
    o_pfa.FLOODING            = i_sdc.IsFlooding()      ? 1 : 0;
    o_pfa.UNIT_CHECKSTOP      = i_sdc.IsUnitCS()        ? 1 : 0;
    o_pfa.LAST_CORE_TERMINATE = 0; // Will be set later, if needed.
    o_pfa.USING_SAVED_SDC     = i_sdc.IsUsingSavedSdc() ? 1 : 0;
    o_pfa.DEFER_DECONFIG      = i_deferDeconfig         ? 1 : 0;

    // Thresholding
    o_pfa.errorCount = i_sdc.GetHits();
    o_pfa.threshold  = i_sdc.GetThreshold();

    // Misc
    o_pfa.serviceActionCounter = iv_serviceActionCounter;
    o_pfa.prdGardErrType       = i_prdGardType;

    // Attention types
    o_pfa.priAttnType = i_attnType;
    o_pfa.secAttnType = i_sdc.GetCauseAttentionType();

    // Build the MRU list into PFA data.
    SDC_MRU_LIST fspmrulist = i_sdc.GetMruList();
    uint32_t i; // Iterator used to set limited list count.
    for ( i = 0; i < fspmrulist.size() && i < MruListLIMIT; i++ )
    {
        o_pfa.mruList[i].callout  = fspmrulist[i].callout.flatten();
        o_pfa.mruList[i].type     = fspmrulist[i].callout.getType();
        o_pfa.mruList[i].priority = (uint8_t)fspmrulist[i].priority;
    }
    o_pfa.mruListCount = i;

    // Build the signature list into PFA data
    PRDF_SIGNATURES sigList = i_sdc.GetSignatureList();
    for ( i = 0; i < sigList.size() && i < SigListLIMIT; i++ )
    {
        o_pfa.sigList[i].chipId    = getHuid(sigList[i].target);
        o_pfa.sigList[i].signature = sigList[i].signature;
    }
    o_pfa.sigListCount = i;

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
        delete l_CapDataBuf;
    }while (0);
}

//------------------------------------------------------------------------------

void ErrDataService::printDebugTraces( )
{
    #define PRDF_FUNC "[ErrDataService::printDebugTraces()]"

    const char * tmp = "Unknown";
    switch ( sdc.GetAttentionType() )
    {
        case MACHINE_CHECK: tmp = "CHECKSTOP";      break;
        case UNIT_CS:       tmp = "UNIT CHECKSTOP"; break;
        case RECOVERABLE:   tmp = "RECOVERABLE";    break;
        case SPECIAL:       tmp = "SPECIAL";        break;
    }
    PRDF_DTRAC( "PRDTRACE: Attention Type = %s", tmp );

    if ( RECOVERABLE == sdc.GetAttentionType() )
    {
        PRDF_DTRAC( "PRDTRACE: Hit Count: 0x%x", sdc.GetHits() );
        PRDF_DTRAC( "PRDTRACE: Threshold at: 0x%x", sdc.GetThreshold() );
        PRDF_DTRAC( "PRDTRACE: Mask id: 0x%x", sdc.GetThresholdMaskId() );
    }

    SDC_MRU_LIST fspmrulist = sdc.GetMruList();

    for ( SDC_MRU_LIST::iterator i = fspmrulist.begin();
          i < fspmrulist.end(); ++i )
    {
        tmp = "Unknown";
        switch ( i->priority )
        {
            case MRU_LOW:  tmp = "LOW";   break;
            case MRU_MEDC: tmp = "MED_C"; break;
            case MRU_MEDB: tmp = "MED_B"; break;
            case MRU_MEDA: tmp = "MED_A"; break;
            case MRU_MED:  tmp = "MED";   break;
            case MRU_HIGH: tmp = "HIGH";  break;
        }
        PRDF_DTRAC( "PRDTRACE: Callout=0x%08x Priority=%s",
                    i->callout.flatten(), tmp );
    }

    PRDF_DTRAC ("GardType: %s", GardAction::ToString( sdc.QueryGard() ) );

    PRDF_DTRAC( "PRDTRACE: Flag Values" );
    if( sdc.IsSUE() )          PRDF_DTRAC( "PRDTRACE: SUE Flag Set" );
    if( sdc.IsUERE() )         PRDF_DTRAC( "PRDTRACE: UERE Flag Set" );
    if( sdc.IsAtThreshold() )  PRDF_DTRAC( "PRDTRACE: AT_THRESHOLD" );
    if( sdc.IsDegraded() )     PRDF_DTRAC( "PRDTRACE: Performance is degraded");

    if( sdc.IsServiceCall() )
        PRDF_DTRAC( "PRDTRACE: SERVICE REQUIRED" );
    else
        PRDF_DTRAC( "PRDTRACE: SERVICE NOT REQUIRED" );

    if( sdc.IsMfgTracking() ) PRDF_DTRAC( "PRDTRACE: Track this error" );
    if( sdc.Terminate() )     PRDF_DTRAC( "PRDTRACE: BRING DOWN MACHINE" );
    if( sdc.IsLogging() )     PRDF_DTRAC( "PRDTRACE: Create history log entry");
    if( sdc.IsFlooding() )    PRDF_DTRAC( "PRDTRACE: Flooding detected" );

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

#ifndef __HOSTBOOT_MODULE

bool ErrDataService::SdcSave( sdcSaveFlagsEnum i_saveFlag,
                              ServiceDataCollector & i_saveSdc )
{
    #define PRDF_FUNC "SdcRetrieve() "
    errlHndl_t errorLog = NULL;
    bool rc = false;
    uint8_t sdcSaveFlags = SDC_NO_SAVE_FLAGS;
    size_t  sz_uint8    = sizeof(uint8_t);
    const char * UeSdcKeys[]  = {"fstp/P1_Root","prdf/UeSdcDataPath"};
    const char * SueSdcKeys[] = {"fstp/P1_Root","prdf/SueSdcDataPath"};
    char  * SdcFilename = NULL;
    uint32_t l_size = 0;

    do
    {
        //Need path to the File
        if (i_saveFlag == SDC_SAVE_UE_FLAG)
            errorLog = UtilReg::path(UeSdcKeys,2,NULL,SdcFilename,l_size);
        else if (i_saveFlag == SDC_SAVE_SUE_FLAG)
            errorLog = UtilReg::path(SueSdcKeys,2,NULL,SdcFilename,l_size);
        else
        {
            //Should not get here - code error
            PRDF_ERR( PRDF_FUNC"Failure - incorrect SDC save flag" );
            rc = true;
            break;
        }
        if (errorLog)
        {
            PRDF_ERR( PRDF_FUNC"Failure in getting SDC file path" );
            PRDF_COMMIT_ERRL(errorLog, ERRL_ACTION_REPORT);
            rc = true;
            break;
        }

        rc = SdcWrite(SdcFilename, i_saveSdc);
        if (rc)
        {
            break;
        }

          //Read current sdc state flags from registry
        errorLog = UtilReg::read ("prdf/RasServices", &sdcSaveFlags, sz_uint8);
        if (errorLog)
        {
            PRDF_ERR( PRDF_FUNC"Failure in SDC flag Registry read" );
            PRDF_COMMIT_ERRL(errorLog, ERRL_ACTION_REPORT);
            rc = true;
            break;
        }

        //Update Sdc registry flag
        sdcSaveFlags = (sdcSaveFlags | i_saveFlag);
        errorLog = UtilReg::write ("prdf/RasServices", &sdcSaveFlags, sz_uint8);
        if (errorLog)
        {
            PRDF_ERR( PRDF_FUNC"Failure in SDC flag Registry write" );
            PRDF_COMMIT_ERRL(errorLog, ERRL_ACTION_REPORT);
            rc = true;
            break;
        }


    }
    while(0);

    if (SdcFilename != NULL)
    {  //need to free the pathname
        free(SdcFilename);
        SdcFilename = NULL;
    }

    return rc;

    #undef PRDF_FUNC
}

bool ErrDataService::SdcRetrieve(sdcSaveFlagsEnum i_saveFlag, void * o_buffer)
{
    #define PRDF_FUNC "SdcRetrieve() "
    errlHndl_t errorLog = NULL;
    bool rc = false;
    const char * UeSdcKeys[]  = {"fstp/P1_Root","prdf/UeSdcDataPath"};
    const char * SueSdcKeys[] = {"fstp/P1_Root","prdf/SueSdcDataPath"};
    char  * SdcFilename = NULL;
    uint32_t l_size = 0;

    do
    {
        //Need path to the File
        if (i_saveFlag == SDC_SAVE_UE_FLAG)
            errorLog = UtilReg::path(UeSdcKeys,2,NULL,SdcFilename,l_size);
        else if (i_saveFlag == SDC_SAVE_SUE_FLAG)
            errorLog = UtilReg::path(SueSdcKeys,2,NULL,SdcFilename,l_size);
        else
        {
            //Should not get here - code error
            PRDF_ERR(PRDF_FUNC"Failure - incorrect SDC save flag" );
            rc = true;
            break;
        }
        if (errorLog)
        {
            PRDF_ERR( PRDF_FUNC"Failure in getting SDC file path" );
            PRDF_COMMIT_ERRL(errorLog, ERRL_ACTION_REPORT);
            rc = true;
            break;
        }

        rc = SdcRead (SdcFilename, o_buffer);


    }
    while(0);

    if (SdcFilename != NULL)
    {  //need to free the pathname
        free(SdcFilename);
        SdcFilename = NULL;
    }

    return rc;

    #undef PRDF_FUNC
}

#endif // if not __HOSTBOOT_MODULE

} // End namespace PRDF

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
      */

