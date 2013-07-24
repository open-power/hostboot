/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfRasServices_common.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
  #include <GardExtInt.H> //for GARD_ErrorType
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
#ifndef __HOSTBOOT_MODULE

const char * ThermalFileKeys[]  = {"fstp/P1_Root","prdf/ThermalSdcPath"};
char  * ThermalFilename = NULL;

#endif

PfaData pfaData;
bool ErrDataService::terminateOnCheckstop = true;
bool previousWasRecovered = false;
Timer previousEventTime;
const double LATENT_MCK_WINDOW = 2;   // two seconds to determin latency
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
    savedLatentSdc = false;
    serviceActionCounter = 0;
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
                                 bool *is_latent,
                                 ServiceDataCollector & sdc)
{
  *is_latent = false;
  latentMachineCheck = false;

  Timer l_curEventTime;
  PlatServices::getCurrentTime(l_curEventTime);

  if(previousWasRecovered && (MACHINE_CHECK == the_attention))
  {
    // check for latent machine check
    if ( LATENT_MCK_WINDOW > (l_curEventTime - previousEventTime))
    {
      *is_latent = true;
      latentMachineCheck = true;
    }
    previousWasRecovered = false; // in case of multiple calls for same cstop
  }
  else if (RECOVERABLE == the_attention)
  {
    previousWasRecovered = true;
  }
  else
  {
    previousWasRecovered = false;
  }

  previousEventTime = l_curEventTime;
  sdc.SetTOE(l_curEventTime);
}

void RasServices::SetErrorTod(ATTENTION_TYPE the_attention,
                              bool *is_latent,
                              ServiceDataCollector & sdc)
{
    iv_ErrDataService->SetErrorTod(the_attention,
                                   is_latent,
                                   sdc);
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

    errlHndl_t o_errl = NULL;

#ifdef __HOSTBOOT_MODULE
    using namespace ERRORLOG;
    using namespace HWAS;
    errlSeverity_t severityParm = ERRL_SEV_RECOVERED;
#else
    bool writeVPD = false;    // Make the default to not Write VPD Capture data
    bool causeAttnPreviouslyReported = false;
    bool pldCheck = false;  // Default to not do the PLD check. Set it to true for  Machine Check
    uint8_t sdcSaveFlags = SDC_NO_SAVE_FLAGS;
    size_t  sz_uint8    = sizeof(uint8_t);
    HWSV::hwsvTermEnum termFlag = HWSV::HWSV_SYS_NO_TERMINATE;
    HWSV::hwsvDeconfigSchedule deconfigSched = HWSV::HWSV_DECONFIG_IMMEDIATE;
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



    HWSV::hwsvHCDBUpdate hcdbUpdate = HWSV::HWSV_HCDB_DO_UPDATE;

    //Use this SDC unless determined in Check Stop processing to use a Latent, UE, or SUE saved SDC
    sdc = i_sdc;

    GardResolution::ErrorType prdGardErrType;
    HWSV::hwsvGardEnum gardState;  // defined in src/hwsv/server/hwsvTypes.H
    GARD_ErrorType gardErrType = GARD_NULL;
    HWSV::hwsvDeconfigEnum deconfigState = HWSV::HWSV_NO_DECONFIG;

    bool ReturnELog = false;
    bool ForceTerminate = false;
    bool iplDiagMode = false;
    bool deferDeconfig = false;

    ++serviceActionCounter;

    uint16_t PRD_Reason_Code = 0;
    uint32_t dumpPlid = 0;

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
        writeVPD = true;              // Change the default so as to Write Capture Data
        pldCheck = true;              // Do the PLD check

        if (terminateOnCheckstop)
        {
            //Also need to return error log for machine check condition
            termFlag = HWSV::HWSV_SYS_TERMINATE_HW_CHECKSTOP;
        }

        ReturnELog = true;

        severityParm = ERRL_SEV_UNRECOVERABLE;

        if // No special UE-SUE flags.
            ((!sdc.IsUERE() ) &&
             (!sdc.IsSUE()  )   )
        {
            if //if LtntMck and last recoverable Stored use it.
                ((latentMachineCheck || sdc.IsForceLatentCS() ) &&
                 (savedLatentSdc      )   )
            {
                gardErrType = GARD_Func;
                sdc = latentSdc;
                causeAttnPreviouslyReported = true;
            }
            //else set no flags, use this sdc
        }
        else //This is a SUE-CS condition check flags.
            if ((!sdc.IsUERE() ) &&
                ( sdc.IsSUE()  )   )
            {
                //Read current sdc state flags from registry
                errlHndl_t errorLog = UtilReg::read ("prdf/RasServices", &sdcSaveFlags, sz_uint8);
                if (errorLog)
                {
                    PRDF_ERR( PRDF_FUNC"Failure in SDC flag Registry read" );
                    PRDF_COMMIT_ERRL(errorLog, ERRL_ACTION_REPORT);
                }
                else if (sdcSaveFlags & SDC_SAVE_UE_FLAG) //check if UE log stored then use it.
                {
                    bool l_rc = SdcRetrieve(SDC_SAVE_UE_FLAG, sdcBuffer);
                    if (l_rc)
                    {
                        PRDF_ERR( PRDF_FUNC"Failure in UE SDC Retrieve Function" );
                    }
                    else
                    {
                        //set the sdc to the Saved SDC for UE
                        sdc = sdcBuffer;
                        gardErrType = GARD_Func;
                        causeAttnPreviouslyReported = true;
                    }
                }
                else if (sdcSaveFlags & SDC_SAVE_SUE_FLAG ) //else check if SUE log stored then use it.
                {
                    bool l_rc = SdcRetrieve(SDC_SAVE_SUE_FLAG, sdcBuffer);
                    if (l_rc)
                    {
                        PRDF_ERR( PRDF_FUNC"Failure in SUE SDC Retrieve Function" );
                    }
                    else
                    {
                        //set the sdc to the Saved SDC for SUE
                        sdc = sdcBuffer;
                        gardErrType = GARD_Func;
                        causeAttnPreviouslyReported = true;
                    }
                }
                //else, set no flags, use this sdc
            }
        //else Normal Mck, set no flags, use this sdc
#endif  // if not __HOSTBOOT_MODULE
    }
    ////////////////////////////////////////////////////////////////
    // Recoverable ATTN or Unit CheckStop
    ////////////////////////////////////////////////////////////////
    else if (i_attnType == RECOVERABLE  || i_attnType == UNIT_CS )
    {
#ifndef  __HOSTBOOT_MODULE
        // FIXME: I don't think Hostboot needs latent SDC and UE/SUE support
        if (!sdc.IsUsingSavedSdc() )  // Don't save File if we are Re-Syncing an sdc
        {
            savedLatentSdc = true;  //Save this SDC as Latent SDC
            latentSdc = i_sdc;
        }

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

        // For a Recoverable Attn with MPFatal and Cause_i_attnType not
        // equal Special, make this a Predictive, Parable error.
        if (!sdc.IsLogging() )
        {
            // This is a Hidden Log
            severityParm = ERRL_SEV_INFORMATIONAL;
            actionFlag = (actionFlag | ERRL_ACTION_HIDDEN);
        }
        else if (sdc.IsServiceCall() || //At Thresold
            (sdc.IsMpFatal() && sdc.GetCauseAttentionType() != SPECIAL) )
        {
            severityParm = ERRL_SEV_PREDICTIVE;
        }
        else  //Recovered
        {
            severityParm = ERRL_SEV_RECOVERED;
            //  Recovered error should be Hidden, and No Service Action
            actionFlag = ERRL_ACTION_HIDDEN;
        }

        if (sdc.IsThermalEvent())
        {  //Make the Thermal Event Hidden
            severityParm = ERRL_SEV_RECOVERED;
            actionFlag = ERRL_ACTION_HIDDEN;
        }
    }
    ////////////////////////////////////////////////////////////////
    // Special ATTN
    ////////////////////////////////////////////////////////////////
    else if (i_attnType == SPECIAL)
    {
        //SMA path on Special attn
        if (sdc.IsMpFatal() && (sdc.IsLogging() || sdc.IsServiceCall() ) )
        {
            severityParm = ERRL_SEV_UNRECOVERABLE;
            savedLatentSdc = true;  //Save this SDC as Latent SDC
            latentSdc = i_sdc;
        }
        else if (sdc.IsServiceCall())
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

    gardState = HWSV::HWSV_DECONFIG_GARD;

    // If gardErrType was determined during latent/UE/SUE processing for Check Stop,
    // use that and not determine gardErrType from the sdc values.
    if (gardErrType != GARD_Func)
    {
        prdGardErrType = sdc.QueryGard();
        switch (prdGardErrType)
        {
            case GardResolution::NoGard:
                gardState =  HWSV::HWSV_NO_GARD;
                gardErrType = GARD_NULL;
                break;
            case GardResolution::Predictive:
                gardErrType = GARD_Predictive;
                break;
            case GardResolution::Fatal:
                gardErrType = GARD_Func;
                break;
            case GardResolution::CheckStopOnlyGard:
                if  (MACHINE_CHECK == i_attnType)
                {
                    gardErrType = GARD_Func;
                }
                else
                {
                    gardState =  HWSV::HWSV_NO_GARD;
                    gardErrType = GARD_NULL;
                }
                break;
            case GardResolution::DeconfigNoGard:
                gardState =  HWSV::HWSV_NO_GARD;
                gardErrType = GARD_NULL;
                break;
            default:
                gardState =  HWSV::HWSV_NO_GARD;
                gardErrType = GARD_NULL;
                PRDF_DTRAC( PRDF_FUNC"Unknown prdGardErrType" );
                break;
        }
    }
    else
    {
        // gardErrType is GARD_Func, set in latent/UE/SUE processing for Check Stop.
        // If NoGard was specified in this switched sdc, then keep the NoGard
        if ( sdc.QueryGard() == GardResolution::NoGard )
        {
            gardState = HWSV::HWSV_NO_GARD;
            gardErrType = GARD_NULL;
            prdGardErrType = GardResolution::NoGard;
        }
        else
        {
            prdGardErrType = GardResolution::Fatal;
        }
    }

    if (sdc.IsThermalEvent() && (MACHINE_CHECK != i_attnType) )
    {  //Force No Gard
        gardState = HWSV::HWSV_NO_GARD;
        gardErrType = GARD_NULL;
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
    uint16_t SDC_Reason_Code = sdc.GetReasonCode();
    if (SDC_Reason_Code == 0) // If the analysis code has not set its own
                              // Reason Code.
    {
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
    }
    else
    {   //Set to Reason Code in SDC, set by the chip analysis code.
        PRD_Reason_Code = SDC_Reason_Code;
    }

    SrcWord7 = i_sdc.GetAttentionType() << 8;
    SrcWord7 |= i_sdc.GetCauseAttentionType();

    //--------------------------------------------------------------------------
    // Check for IPL Diag Mode and set up for Deferred Deconfig
    //--------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

    iplDiagMode = PlatServices::isInMdiaMode();

    // Deferred Deconfig should be used throughout all of Hostboot (both
    // checkForIplAttns() and MDIA).
    if ( (HWSV::HWSV_NO_GARD != gardState ||
          GardResolution::DeconfigNoGard == prdGardErrType ) )
    {
        deferDeconfig = true;
        deconfigState = HWSV::HWSV_DECONFIG;
        // NOTE: deconfigSched is not actually used in Hostboot. Will remove in
        // the refactoring effort.
    }

#endif


    //**************************************************************
    // Create Error Log with SRC
    //**************************************************************
    ErrorSignature * esig = sdc.GetErrorSignature();

    PRDF_HW_CREATE_ERRL(o_errl,
                        ERRL_SEV_PREDICTIVE,
                        ERRL_ETYPE_NOT_APPLICABLE,
                        SRCI_MACH_CHECK,
                        SRCI_NO_ATTR,
                        PRDF_RAS_SERVICES,
                        FSP_DEFAULT_REFCODE,
                        PRD_Reason_Code,
                        esig->getChipId(), //SRC Word 6
                        SrcWord7,          //code location - SRC Word 7
                        esig->getSigId(),  //signature - SRC Word 8
                        SrcWord9,          //user data - SRC Word 9
                        termFlag,
                        pldCheck);         //pldCheck

    //**************************************************************
    //  Add SDC Capture data to Error Log User Data here only if
    //    there are 4 or more callouts,
    //    (including Dimm callouts in the MemoryMru).
    //**************************************************************
    bool capDataAdded = false;
    if (calloutsPlusDimms > 3)
    {
        AddCapData(sdc.GetCaptureData(),o_errl);
        capDataAdded = true;
    }

    // make sure serviceAction doesn't override errl severity
    o_errl->setSev(severityParm);

    if (ERRL_ACTION_HIDDEN == actionFlag)
    {  //Change HCDB Update to not do the update for non-visible logs
        hcdbUpdate = HWSV::HWSV_HCDB_OVERRIDE;
    }

    //**************************************************************
    // Add each mru/callout to the error log.
    //**************************************************************
    fspmrulist = sdc.GetMruList();
    uint32_t calloutcount = fspmrulist.size();
    for ( SDC_MRU_LIST::iterator i = fspmrulist.begin();
          i < fspmrulist.end(); ++i )
    {
        thispriority = (*i).priority;
        thiscallout = (*i).callout;
        if ( PRDcalloutData::TYPE_TARGET == thiscallout.getType() )
        {
            HWSV::hwsvDeconfigEnum thisDeconfigState = deconfigState;

            #ifdef __HOSTBOOT_MODULE
            // Special case for Hostboot.
            if ( deferDeconfig )
            {
                thisDeconfigState = HWAS::DELAYED_DECONFIG;
            }
            #endif

            PRDF_HW_ADD_CALLOUT(thiscallout.getTarget(),
                                thispriority,
                                thisDeconfigState,
                                gardState,
                                o_errl,
                                writeVPD,
                                gardErrType,
                                severityParm,
                                hcdbUpdate);

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
                                     gardState,
                                     o_errl,
                                     writeVPD,
                                     gardErrType,
                                     severityParm,
                                     hcdbUpdate );
            }
        }
        else if ( PRDcalloutData::TYPE_SYMFRU == thiscallout.getType() )
        {
            thisProcedureID = epubProcedureID(thiscallout.flatten());

            PRDF_DTRAC( PRDF_FUNC"thisProcedureID: %x, thispriority: %x, severityParm: %x",
                   thisProcedureID, thispriority,severityParm );

            PRDF_HW_ADD_PROC_CALLOUT(thisProcedureID,
                                     thispriority,
                                     o_errl,
                                     severityParm);

            // Use the flags set earlier to determine if the callout is just Software (SP code or Phyp Code).
            // Add a Second Level Support procedure callout Low, for this case.
            if (HW == false && SW == true && SecondLevel == false)
            {
                PRDF_DTRAC( PRDF_FUNC"thisProcedureID= %x, thispriority=%x, severityParm=%x",
                   EPUB_PRC_LVL_SUPP, MRU_LOW, severityParm );

                PRDF_HW_ADD_PROC_CALLOUT(EPUB_PRC_LVL_SUPP,
                                         MRU_LOW,
                                         o_errl,
                                         severityParm);

                SecondLevel = true;
            }

        }
    }

#ifndef  __HOSTBOOT_MODULE
    // FIXME: need to investigate whether or not to add HCDB to Hostboot

    //**************************************************************
    //  setChangeState for HomIds in the HCDB change list
    //**************************************************************
    HCDB_CHANGE_LIST hcdbList = sdc.GetHcdbList();
    for (HCDB_CHANGE_LIST::iterator i = hcdbList.begin(); i < hcdbList.end(); ++i)
    {
        //FIXME  comp_id_t, l_pchipHandle commented to avoid warning
        //TargetHandle_t l_pchipHandle = (*i).iv_phcdbtargetHandle;
       // comp_id_t thisCompId = (*i).iv_compType;
        hcdb::comp_subtype_t thisCompSubType = (*i).iv_compSubType;
        if (hcdb::SUBTYPE_ANY == thisCompSubType)
        {
            //PlatServices::setHcdbChangeState(l_pchipHandle);//FIXME functions commneted for now in wrapper
            // false means don't set the HOM objects derived from this ohject.
        }
        else
        {
            //PlatServices::setHcdbChangeState(l_pchipHandle , thisCompId, thisCompSubType);
            //TODO TargetHandle Conversion may shall change for P8
            // false means don't set the HOM objects derived from this ohject.
        }
    }

    //**************************************************************
    //  setChangeState for System if needed
    //**************************************************************
    // If Second Level callout with no hardware called out, setChangeState for System
    if ( (HW == false) && (SecondLevel == true))
    {
        //PlatServices::setHcdbChangeStateSystem();FIXME functions commneted for now in wrapper
        PRDF_INF( PRDF_FUNC"initiating a HCDB setChangeState for System." );
    }
#endif // if not __HOSTBOOT_MODULE

    //**************************************************************
    // Build Dump Flags and PFA5 data
    //**************************************************************
    //MP01 a Start
    pfaData.MsDumpLabel[0] = 0x4D532020;                //start of MS Dump flags
    pfaData.MsDumpLabel[1] = 0x44554D50;                // 'MS  DUMP'

    TargetHandle_t l_dumpHandle = NULL;
#ifdef  __HOSTBOOT_MODULE
    sdc.GetDumpRequest( l_dumpHandle );
#else
    hwTableContent l_dumpRequestContent; //not used but needed to call GetDumpRequest
    sdc.GetDumpRequest( l_dumpRequestContent, l_dumpHandle );
    pfaData.MsDumpInfo.DumpContent = l_dumpRequestContent;
#endif

    pfaData.MsDumpInfo.DumpId = PlatServices::getHuid(l_dumpHandle);
    TYPE l_targetType = PlatServices::getTargetType(l_dumpHandle);

    if (i_sdc.IsMpDumpReq())
    {
        pfaData.MP_DUMP_REQ = 1;
    }
    else
    {
        pfaData.MP_DUMP_REQ = 0;
    }
    if (i_sdc.IsMpResetReq())
    {
        pfaData.MP_RESET_REQ = 1;
    }
    else
    {
        pfaData.MP_RESET_REQ = 0;
    }
    //Pass Error Log Action Flag to attn handling, so it know what actions to commit

    pfaData.MP_FATAL = (i_sdc.IsMpFatal()==true)? 1:0;

    pfaData.PFA_errlActions = actionFlag;
    pfaData.PFA_errlSeverity = severityParm;

    pfaData.REBOOT_MSG = 0; //  Not supported??
    pfaData.DUMP = (sdc.IsDump()==true)? 1:0;
    pfaData.UERE = (sdc.IsUERE()==true)? 1:0;
    pfaData.SUE = (sdc.IsSUE()==true)? 1:0;
    pfaData.CRUMB = (sdc.MaybeCrumb()==true)? 1:0;
    pfaData.AT_THRESHOLD = (sdc.IsAtThreshold()==true)? 1:0;
    pfaData.DEGRADED = (sdc.IsDegraded()==true)? 1:0;
    pfaData.SERVICE_CALL = (sdc.IsServiceCall()==true)? 1:0;
    pfaData.TRACKIT = (sdc.IsMfgTracking()==true)? 1:0;
    pfaData.TERMINATE = (sdc.Terminate()==true)? 1:0;
    pfaData.LOGIT = (sdc.IsLogging()==true)? 1:0;
    pfaData.MEMORY_STEERED = (sdc.IsMemorySteered()==true)? 1:0;
    pfaData.FLOODING = (sdc.IsFlooding()==true)? 1:0;

    pfaData.ErrorCount              = sdc.GetHits();
    pfaData.PRDServiceActionCounter = serviceActionCounter;
    pfaData.Threshold               = sdc.GetThreshold();
    pfaData.ErrorType               = prdGardErrType;
    pfaData.homGardState            = gardState;
    pfaData.PRD_AttnTypes           = i_attnType;
    pfaData.PRD_SecondAttnTypes     = i_sdc.GetCauseAttentionType();
    pfaData.THERMAL_EVENT           = (sdc.IsThermalEvent()==true)? 1:0;
    pfaData.UNIT_CHECKSTOP          = (sdc.IsUnitCS()==true)? 1:0;
    pfaData.USING_SAVED_SDC         = (sdc.IsUsingSavedSdc()==true)? 1:0;
    pfaData.FORCE_LATENT_CS         = (i_sdc.IsForceLatentCS()==true)? 1:0;
    pfaData.DEFER_DECONFIG          = (deferDeconfig==true)? 1:0;
    pfaData.CM_MODE                 = 0; //FIXME RTC 50063
    pfaData.TERMINATE_ON_CS         = (terminateOnCheckstop==true)? 1:0;
    pfaData.reasonCode              = sdc.GetReasonCode();
    pfaData.PfaCalloutCount         = calloutcount;

    // First clear out the PFA Callout list from previous SRC
    for (uint32_t j = 0; j < MruListLIMIT; ++j)
    {
        pfaData.PfaCalloutList[j].Callout = 0;
        pfaData.PfaCalloutList[j].MRUtype = 0;
        pfaData.PfaCalloutList[j].MRUpriority = 0;
    }

    // Build the mru list into PFA data Callout list
    uint32_t n = 0;
    fspmrulist = sdc.GetMruList();
    for ( SDC_MRU_LIST::iterator i = fspmrulist.begin();
          i < fspmrulist.end(); ++i )
    {
        if ( n < MruListLIMIT )
        {
            pfaData.PfaCalloutList[n].MRUpriority = (uint8_t)(*i).priority;
            pfaData.PfaCalloutList[n].Callout = i->callout.flatten();
            pfaData.PfaCalloutList[n].MRUtype = i->callout.getType();

            ++n;
        }
    }

#ifndef __HOSTBOOT_MODULE
    // FIXME: need to investigate whether or not we need to add HCDB support in Hostboot
    // First clear out the HCDB from previous SRC
    for (uint32_t j = 0; j < HcdbListLIMIT; ++j)
    {
        pfaData.PfaHcdbList[j].hcdbId = 0;//Resetting entity path
        pfaData.PfaHcdbList[j].compSubType = 0;
        pfaData.PfaHcdbList[j].compType = 0;
        pfaData.PfaHcdbList[j].hcdbReserved1 = 0;
        pfaData.PfaHcdbList[j].hcdbReserved2 = 0;
    }

    // Build the HCDB list into PFA data
    n = 0;
    hcdbList = sdc.GetHcdbList();
    pfaData.hcdbListCount = hcdbList.size();
    for (HCDB_CHANGE_LIST::iterator i = hcdbList.begin(); i < hcdbList.end(); ++i)
    {
        if (n < HcdbListLIMIT)
        {
            pfaData.PfaHcdbList[n].hcdbId = PlatServices::getHuid((*i).iv_phcdbtargetHandle);
            pfaData.PfaHcdbList[n].compSubType = (*i).iv_compSubType;
            pfaData.PfaHcdbList[n].compType = (*i).iv_compType;
            ++n;
        }
        else
            break;
    }
    // Set flag so we know to parse the hcdb data
    pfaData.HCDB_SUPPORT = 1;
#endif // if not __HOSTBOOT_MODULE

    PRDF_SIGNATURES signatureList = sdc.GetSignatureList();
    // First clear out the HCDB from previous SRC
    for (uint32_t j = 0; j < SignatureListLIMIT; ++j)
    {
        pfaData.PfaSignatureList[j].chipId = 0;//Resetting the chipPath
        pfaData.PfaSignatureList[j].signature = 0;
    }

    // Build the signature list into PFA data
    n = 0;
    signatureList = sdc.GetSignatureList();
    pfaData.signatureCount = signatureList.size();
    for (PRDF_SIGNATURES::iterator i = signatureList.begin(); i < signatureList.end(); ++i)
    {
        if (n < SignatureListLIMIT)
        {
            pfaData.PfaSignatureList[n].chipId = PlatServices::getHuid((*i).iv_pSignatureHandle);
            pfaData.PfaSignatureList[n].signature = (*i).iv_signature;
            ++n;
        }
        else
            break;
    }
    // Set flag so we know to parse the hcdb data
    pfaData.SIGNATURE_SUPPORT = 1;

    //**************************************************************
    // Check for Unit CheckStop.
    // Check for Last Functional Core.
    // PFA data updates for these item.
    //**************************************************************
    pfaData.LAST_CORE_TERMINATE = false;
    // Now the check is for Unit Check Stop and Dump ID for Processor
    // Skip the termination on Last Core if this is a Saved SDC
    if (sdc.IsUnitCS()  && (!sdc.IsUsingSavedSdc() ) )
    {
        PRDF_TRAC( PRDF_FUNC"Unit CS, Func HUID: %x, TargetType: %x",
                   pfaData.MsDumpInfo.DumpId, l_targetType );
        if (TYPE_CORE == l_targetType)
        {
            //Check if this is last functional core
            if ( PlatServices::checkLastFuncCore(l_dumpHandle) )
            {
                PRDF_TRAC( PRDF_FUNC"Last Func Core: %x was true.",
                           PlatServices::getHuid(l_dumpHandle)  );
                ForceTerminate = true;
                pfaData.LAST_CORE_TERMINATE = true;
                o_errl->setSev(ERRL_SEV_UNRECOVERABLE);  //Update Errl Severity
                //Update PFA data
                pfaData.PFA_errlSeverity = ERRL_SEV_UNRECOVERABLE;
            }
        }
    }

    // Check the errl for the terminate state
    // Note: will also be true for CheckStop attn.
    bool l_termSRC = false;
    PRDF_GET_TERM_SRC(o_errl, l_termSRC);
    if(l_termSRC)
    {
        ForceTerminate = true;
        uint32_t l_plid = 0;
        PRDF_GET_PLID(o_errl, l_plid);
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
            PRDF_SRC_WRITE_TERM_STATE_ON(o_errl, SRCI_TERM_STATE_MNFG);
        }
        //Do not Terminate in Manufacturing Mode if not at threshold.
        //Allow Manufacturing Mode Terminate for Thermal Event. It's severityParm will be
        //ERRL_SEV_RECOVERED in the current error log.
        //MPB1 c Do not Terminate in Manufacturing Mode in Ipl Diag Mode  with Deferred Deconfig
        else if ( ( ((severityParm == ERRL_SEV_RECOVERED) || (severityParm == ERRL_SEV_INFORMATIONAL)) &&
                       !sdc.IsThermalEvent() ) ||
                     deferDeconfig )
        {
            ForceTerminate = false;
            actionFlag = (actionFlag | ERRL_ACTION_DONT_TERMINATE);
        }
        else
        {
            PRDF_SRC_WRITE_TERM_STATE_ON(o_errl, SRCI_TERM_STATE_MNFG);
        }

        if (sdc.IsThermalEvent() )
        {  //For Manufacturing Mode terminate, change the action flags for Thermal Event.
            actionFlag = (ERRL_ACTION_SA | ERRL_ACTION_REPORT | ERRL_ACTION_CALL_HOME);
        }
        pfaData.PFA_errlActions = actionFlag;
    }


    // Needed to move the errl add user data sections here because of some updates
    // of the data required in the Aysnc section for the SMA dual reporting fix.

    //**************************************************************
    // Add the PFA data to Error Log User Data
    //**************************************************************
    UtilMem l_membuf;
    l_membuf << pfaData;
    PRDF_ADD_FFDC( o_errl, (const char*)l_membuf.base(), l_membuf.size(),
                   ErrlVer1, ErrlSectPFA5_1 );

    //**************************************************************
    // Check for Manufacturing AVP mode
    // If needed: Add the AVP mode data to Error Log User Data
    //**************************************************************

   /* FIXME - The MDIA component is being removed from FSP code. This means this MDIA registry variable
will also be removed. Need to confirm if this code is required anymore.
    if ( PlatServices::avpMode() )
    {
        //Get the AVP Test Case Number from the AVP Test Case Data Registry. The Test Case Number is the first four bytes.
        uint32_t avpTCNumber = 0;
        size_t  sz_uint32    = sizeof(uint32_t);
        errlHndl_t errorLog = UtilReg::read ("mdia/AvpTestCaseData", &avpTCNumber, sz_uint32);
        // printf("AVP Test Case Number from registry: %.8x \n", avpTCNumber);
        if (errorLog)
        {
            errorLog->commit(PRDF_COMP_ID,ERRL_ACTION_REPORT);
            PRDF_ERR( "PRDTRACE: RasServices Failure in AVP Test Case Registry read" );
            delete errorLog;
            errorLog = NULL;
        }
        else
        {
            //Add Test Case Number to Error Log User Data
            UtilMem l_membuf;
            l_membuf << avpTCNumber;
            o_errl->addUsrDtls(l_membuf.base(),l_membuf.size(),PRDF_COMP_ID,ErrlVer1,ErrlAVPData_1);
        }
    }
*/

#ifndef __HOSTBOOT_MODULE
    // FIXME: do we need support for AVP in Hostboot?  probably not
    if ( PlatServices::hdatAvpMode() )
    {
        //Get the AVP Test Case Data from the AVP Test Case Data Registry.
        uint8_t avpTCData[64];
        size_t  sz_avpTCData    = sizeof(avpTCData);
        errlHndl_t errorLog = UtilReg::read ("hdat/AvpTestCaseData", avpTCData, sz_avpTCData);

        if (errorLog)
        {
            PRDF_ERR( PRDF_FUNC"Failure in hdat AVP Test Case Registry read" );
            PRDF_COMMIT_ERRL(errorLog, ERRL_ACTION_REPORT);
        }
        else
        {
            //Add Test Case Data to Error Log User Data
            const size_t sz_usrDtlsTCData = 29;
            uint8_t usrDtlsTCData[sz_usrDtlsTCData];
            memcpy(usrDtlsTCData, avpTCData, 4);
            memcpy(&usrDtlsTCData[4], &avpTCData[40], 4);
            memcpy(&usrDtlsTCData[8], &avpTCData[37], 1);
            memcpy(&usrDtlsTCData[9], &avpTCData[44], 20);
            PRDF_ADD_FFDC( o_errl, (const char*)usrDtlsTCData, sz_usrDtlsTCData,
                           ErrlVer1, ErrlAVPData_2 );
        }
    }
#endif // if not __HOSTBOOT_MODULE

    //**************************************************************
    // Add SDC Capture data to Error Log User Data
    //**************************************************************
    // Pulled some code out to incorporate into AddCapData
    // Check to make sure Capture Data wasn't added earlier.
    if (!capDataAdded)
    {
        AddCapData(sdc.GetCaptureData() ,o_errl);
    }

    // Note moved the code from here, that was associated with checking for the last
    // functional core to be before the PFA data is placed in error log.

    // Collect PRD trace
    // NOTE: Each line of trace is on average 36 bytes so 768 bytes should get
    //       us around 21 lines of trace output.
    PRDF_COLLECT_TRACE(o_errl, 768);

    //**************************************************************
    // Commit the eror log.
    // This will also perform Gard and Deconfig actions.
    // Do the Unit Dumps if needed.
    //**************************************************************
    if (sdc.IsDontCommitErrl() && !sdc.IsUnitCS() && (MACHINE_CHECK != i_attnType) )
    {
        delete o_errl;
        o_errl = NULL;
    }
    else if ( !ReturnELog        && !ForceTerminate &&
              !i_sdc.IsMpFatal() && !i_sdc.Terminate() )
    {
        // Check to see if we need to do a Proc Core dump
        if ( sdc.IsUnitCS() && !sdc.IsUsingSavedSdc() )
        {
            if ( l_targetType == TYPE_PROC )
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
                    l_rc = PRDF_HWUDUMP( o_errl, CONTENT_HWNXLCL,
                                         pfaData.MsDumpInfo.DumpId );
                }
            }
            else if (l_targetType == TYPE_MEMBUF ||
                     l_targetType == TYPE_MBA    ||
                     l_targetType == TYPE_MCS)
            {
                // Centaur Checkstop
                TargetHandle_t centaurHandle = l_dumpHandle;
                if ( TYPE_MCS == l_targetType )
                {
                    centaurHandle = getConnectedChild( l_dumpHandle,
                                                       TYPE_MEMBUF, 0 );
                }
                else if ( TYPE_MBA == l_targetType )
                {
                    centaurHandle = getConnectedParent( l_dumpHandle,
                                                        TYPE_MEMBUF );
                }

                if (centaurHandle)
                {
                    int32_t l_rc = PRDF_RUNTIME_DECONFIG(centaurHandle);
                    if ( SUCCESS != l_rc )
                    {
                        PRDF_ERR( PRDF_FUNC"runtime deconfig failed 0x%08x",
                                  pfaData.MsDumpInfo.DumpId );
                    }
                    // No unit dump for Centaur checkstop
                }
            }
            else
            {
                int32_t l_rc = PRDF_RUNTIME_DECONFIG( l_dumpHandle );
                if ( SUCCESS == l_rc )
                {
                    // Call Dump for Proc Core CS
                    if ( TYPE_CORE == l_targetType )
                    {
                        l_rc = PRDF_HWUDUMP( o_errl,
                                             CONTENT_SINGLE_CORE_CHECKSTOP,
                                             pfaData.MsDumpInfo.DumpId );
                    }
                    // FIXME: Will need to add Centaur DMI channel checkstop
                    //        support later.
                    else
                    {
                        PRDF_ERR( PRDF_FUNC"Unsupported dump for target 0x%08x",
                                  pfaData.MsDumpInfo.DumpId );
                    }
                }
            }
        }

        // Commit the Error log
        // Need to move below here since we'll need
        // to pass o_errl to PRDF_HWUDUMP
        // for FSP specific SRC handling in the future
#ifndef __HOSTBOOT_MODULE
        MnfgTrace(esig);
#endif

        PRDF_GET_PLID(o_errl, dumpPlid);

        bool l_sysTerm = false;
        PRDF_HW_COMMIT_ERRL(l_sysTerm,
                            o_errl,
                            deconfigSched,
                            actionFlag,
                            HWSV::HWSV_CONTINUE);
        if(true == l_sysTerm) // if sysTerm then we have to commit and delete the log
        {
            //Just commit the log
            uint32_t l_rc = 0;
            PRDF_GET_RC(o_errl, l_rc);

            uint16_t l_reasonCode = 0;
            PRDF_GET_REASONCODE(o_errl, l_reasonCode);

            PRDF_INF( PRDF_FUNC"committing error log: PLID=%.8X, ReasonCode=%.8X, RC=%.8X, actions=%.4X",
                      dumpPlid,
                      l_reasonCode,
                      l_rc, actionFlag );
            PRDF_COMMIT_ERRL(o_errl, actionFlag);
        }
        else
        {
            // Error log has been committed, return NULL Error Log to PrdMain
            o_errl = NULL;
        }

    }
    // If the Error Log is not committed (as due to a Terminate condtion),
    // the Error Log will be returned to PRDMain
    else
    {

#ifndef __HOSTBOOT_MODULE
        MnfgTrace(esig);
#endif

        PRDF_DTRAC( PRDF_FUNC"generating a terminating, or MP Fatal SRC" );
        if (ForceTerminate && sdc.IsThermalEvent() ) //MP42 a  Start
        {  //For Manufacturing Mode terminate, change the severity in
           //the error log to be Predictive for Thermal Event.
            o_errl->setSev(ERRL_SEV_PREDICTIVE);
        }
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

    //##########################################################################
    // Start debug trace output
    //##########################################################################

    switch ( sdc.GetAttentionType() )
    {
        case MACHINE_CHECK:
            PRDF_DTRAC( "PRDTRACE: Attention Type = CHECKSTOP" );   break;
        case RECOVERABLE:
            PRDF_DTRAC( "PRDTRACE: Attention Type = RECOVERABLE" ); break;
        case SPECIAL:
            PRDF_DTRAC( "PRDTRACE: Attention Type = SPECIAL" );     break;
        default:
            PRDF_DTRAC( "PRDTRACE: Attention Type = Unknown" );
    }

    if ( RECOVERABLE == sdc.GetAttentionType() )
    {
        PRDF_DTRAC( "PRDTRACE: Hit Count: 0x%x", sdc.GetHits() );
        PRDF_DTRAC( "PRDTRACE: Threshold at: 0x%x", sdc.GetThreshold() );
        PRDF_DTRAC( "PRDTRACE: Mask id: 0x%x", sdc.GetThresholdMaskId() );
    }

    fspmrulist = sdc.GetMruList();
    for ( SDC_MRU_LIST::iterator i = fspmrulist.begin();
          i < fspmrulist.end(); ++i )
    {
        PRDF_DTRAC( "PRDTRACE: Callout: %x", i->callout.flatten() );

        switch ( i->priority )
        {
            case MRU_LOW:  PRDF_DTRAC( "PRDTRACE:   LOW" );   break;
            case MRU_MEDC: PRDF_DTRAC( "PRDTRACE:   MED_C" ); break;
            case MRU_MEDB: PRDF_DTRAC( "PRDTRACE:   MED_B" ); break;
            case MRU_MEDA: PRDF_DTRAC( "PRDTRACE:   MED_A" ); break;
            case MRU_MED:  PRDF_DTRAC( "PRDTRACE:   MED" );  break;
            case MRU_HIGH: PRDF_DTRAC( "PRDTRACE:   HIGH" );  break;
            default:
                PRDF_DTRAC( "PRDTRACE:   Unknown Priority Value" );
        }

        GardResolution::ErrorType et = sdc.QueryGard();
        switch ( et )
        {
            case GardResolution::NoGard:
                PRDF_DTRAC( "PRDTRACE:   NoGard" );            break;
            case GardResolution::Predictive:
                PRDF_DTRAC( "PRDTRACE:   Predictive" );        break;
            case GardResolution::Fatal:
                PRDF_DTRAC( "PRDTRACE:   Fatal" );             break;
            case GardResolution::CheckStopOnlyGard:
                PRDF_DTRAC( "PRDTRACE:   CheckStopOnlyGard" ); break;
            case GardResolution::DeconfigNoGard:
                PRDF_DTRAC( "PRDTRACE:   DeconfigNoGard" );
        }
    }

    PRDF_DTRAC( "PRDTRACE: Flag Values" );
    if ( sdc.IsSUE() )         PRDF_DTRAC( "PRDTRACE: SUE Flag Set" );
    if ( sdc.IsUERE() )        PRDF_DTRAC( "PRDTRACE: UERE Flag Set" );
    if ( sdc.MaybeCrumb() )    PRDF_DTRAC( "PRDTRACE: Check for PCI Crumb" );
    if ( sdc.IsAtThreshold() ) PRDF_DTRAC( "PRDTRACE: AT_THRESHOLD" );
    if ( sdc.IsDegraded() )    PRDF_DTRAC( "PRDTRACE: Performance is degraded" );

    if ( sdc.IsServiceCall() )
        PRDF_DTRAC( "PRDTRACE: SERVICE REQUIRED" );
    else
        PRDF_DTRAC( "PRDTRACE: SERVICE NOT REQUIRED" );

    if ( sdc.IsMfgTracking() )   PRDF_DTRAC( "PRDTRACE: Track this error" );
    if ( sdc.Terminate() )       PRDF_DTRAC( "PRDTRACE: BRING DOWN MACHINE" );
    if ( sdc.IsLogging() )       PRDF_DTRAC( "PRDTRACE: Create history log entry" );
    if ( sdc.IsFlooding() )      PRDF_DTRAC( "PRDTRACE: Flooding detected" );
    if ( sdc.IsMemorySteered() ) PRDF_DTRAC( "PRDTRACE: Memory steered" );

    return o_errl;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

#ifndef __HOSTBOOT_MODULE
void ErrDataService::MnfgTrace(ErrorSignature * l_esig )
{
    char  * MnfgFilename = NULL;
    uint32_t l_size = 0;
    const char * MnfgKey[] = {"fstp/P0_Root"};

    if ( PlatServices::mfgMode() )
    {
        errlHndl_t errorLog = UtilReg::path(MnfgKey, 1, "prdfMfgErrors",
                                            MnfgFilename, l_size);
        if (errorLog == NULL)
        {
            UtilFile l_mfgFile;
            l_mfgFile.Open(MnfgFilename,"a+");

            char l_string[100];
            uint32_t signature = l_esig->getSigId();
            HUID sigChip = l_esig->getChipId();

            // Get Entity Path String
            TargetHandle_t l_ptempHandle = PlatServices::getTarget(sigChip);
            TARGETING::EntityPath path;
            PlatServices::getEntityPath(l_ptempHandle, path,
                                        EntityPath::PATH_PHYSICAL);
            char *epStr = path.toString();
            if (epStr)
            {
                snprintf(l_string, 100, "%s, ", path.toString());
                free(epStr);
            }

            l_mfgFile.write(l_string, strlen(l_string));

            // Write Signature
            snprintf(l_string, 100, "0x%08x, 0x%08x, ", sigChip, signature);
            l_mfgFile.write(l_string, strlen(l_string));

            // Write chip ECID data
            PlatServices::getECIDString(l_ptempHandle, l_string);
            l_mfgFile.write(l_string, strlen(l_string));

            // Write MRU list
            uint32_t n = 0;
            while ( (n < MruListLIMIT )  && (n < pfaData.PfaCalloutCount) )
            {
                snprintf(l_string, 100, " , %08x", pfaData.PfaCalloutList[n].Callout);
                l_mfgFile.write(l_string, strlen(l_string));
                ++n;
            }
            snprintf(l_string, 100, "\n");
            l_mfgFile.write(l_string, 1);

            l_mfgFile.Close();
        }
        else
        {
            PRDF_ERR( "PRDTRACE: MnfgTrace Failure in getting file path" );
            PRDF_COMMIT_ERRL(errorLog, ERRL_ACTION_REPORT);
        }
    }

    if (MnfgFilename != NULL)
    {  //need to free the pathname
        free(MnfgFilename);
        MnfgFilename = NULL;
    }

    return;

}
#endif // if not __HOSTBOOT_MODULE

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
#ifndef __HOSTBOOT_MODULE

bool ErrDataService::SdcSave(sdcSaveFlagsEnum i_saveFlag, ServiceDataCollector & i_saveSdc)
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

