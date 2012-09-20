/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/service/prdf_ras_services.C $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2012              */
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

/** @file  prdf_ras_services.C
 *  @brief Definition of external RAS services needed by PRD
 */

#define prdf_ras_services_C

#include <prdf_ras_services.H>
#include <prdfPfa5Data.h>
#include <time.h>
#include <iipServiceDataCollector.h>
#include <prdf_service_codes.H>
#include <iipglobl.h>
#include <prdfCallouts.H>
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
  #define htonl(foo) (foo) // no-op for HB
  #include <stdio.h>
  //FIXME: CPTR_Identifier used to be defined in hutlCecSvrErrl.H
  // it seems to me that we can delete this but leave it here for now
  #define CPTR_Identifier 0x43505452
  //FIXME: move these typedefs to somewhere
  typedef uint32_t homHCDBUpdate;
  typedef uint32_t homTermEnum;
  typedef uint32_t homHCDBUpdate;
  typedef uint32_t homGardEnum;
  typedef uint32_t homDeconfigEnum;
  typedef uint32_t homDeconfigSchedule;
#else
  #include <srcisrc.H>
  #include <GardExtInt.H> //for GARD_ErrorType
  #include <utilreg.H> //For registry functions
  #include <evenmgt.H>
  #include <rmgrBaseClientLib.H>  //for rmgrSyncFile
  #include <prdfSdcFileControl.H>
  // FIXME: move dump include to iipglobl.h when Adriana's fix is in
  #include <dumpHWURequest_applet.H>
#endif

#undef prdf_ras_services_C

using namespace TARGETING;

namespace PRDF
{

// ----------------------------------------------------------------------------
// Local macros and types
// ----------------------------------------------------------------------------
#ifndef BIN_TO_BCD
#define BIN_TO_BCD(val) ((val) = (((val)/1000)<<12) + (((val%1000)/100)<<8) + (((val%100)/10)<<4) + (val)%10)
#endif

// ----------------------------------------------------------------------------
// Local Globals
// ----------------------------------------------------------------------------
#ifndef __HOSTBOOT_MODULE

const char * ThermalFileKeys[]  = {"fstp/P1_Root","prdf/ThermalSdcPath"};
char  * ThermalFilename = NULL;

#endif

prdfPfaData PfaData;
bool ErrDataService::terminateOnCheckstop = true;
bool previousWasRecovered = false;
PrdTimer previousEventTime;
const double LATENT_MCK_WINDOW = 2;   // two seconds to determin latency
RasServices thisServiceGenerator;

// ----------------------------------------------------------------------------
// Member Functions
// ----------------------------------------------------------------------------

ServiceGeneratorClass & ServiceGeneratorClass::ThisServiceGenerator(void)
{
  return thisServiceGenerator;
}

// ----------------------------------------------------------------------------

RasServices::RasServices() :
    iv_ErrDataService(NULL)
{
    //PRDF_DTRAC("RasServices() initializing default iv_ErrDataService");
    iv_ErrDataService = new ErrDataService();
}

// ----------------------------------------------------------------------------
RasServices::~RasServices()
{
    if(NULL != iv_ErrDataService)
    {
        PRDF_DTRAC("~RasServices() deleting iv_ErrDataService");
        delete iv_ErrDataService;
        iv_ErrDataService = NULL;
    }
}

// ----------------------------------------------------------------------------

void ErrDataService::Initialize()
{
    savedLatentSdc = false;
    serviceActionCounter = 0;
}

void RasServices::Initialize()
{
    iv_ErrDataService->Initialize();
}

// ----------------------------------------------------------------------------

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

// ----------------------------------------------------------------------------

void ErrDataService::SetErrorTod(ATTENTION_TYPE the_attention,
                                 bool *is_latent,
                                 ServiceDataCollector & sdc)
{
  *is_latent = false;
  latentMachineCheck = false;

  PrdTimer l_curEventTime;
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

// ----------------------------------------------------------------------------

bool ErrDataService::QueryLoggingBufferFull(void) const
{
    return (loggingBufferFull);
}

bool RasServices::QueryLoggingBufferFull(void) const
{
    return iv_ErrDataService->QueryLoggingBufferFull();
}

// ----------------------------------------------------------------------------

void ErrDataService ::SaveRcForSrc(int32_t the_rc)
{
    savedPrdReturnCode = the_rc;
}

void RasServices::SaveRcForSrc(int32_t the_rc)
{
    iv_ErrDataService->SaveRcForSrc(the_rc);
}

// ----------------------------------------------------------------------------

errlHndl_t RasServices::GenerateSrcPfa(ATTENTION_TYPE attn_type,
                                             ServiceDataCollector & i_sdc)

{
    PRDF_DENTER("RasServices::GenerateSrcPfa()");

    errlHndl_t errLog = NULL;
    errLog = iv_ErrDataService->GenerateSrcPfa(attn_type, i_sdc);

    PRDF_DEXIT("RasServices::GenerateSrcPfa()");
    return errLog;

}

// ----------------------------------------------------------------------------

errlHndl_t ErrDataService::GenerateSrcPfa(ATTENTION_TYPE attn_type,
                                             ServiceDataCollector & i_sdc)
{
    #define PRDF_FUNC "GenerateSrcPfa() "
    PRDF_DENTER( PRDF_FUNC );
    errlHndl_t errLog = NULL;

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
    homTermEnum termFlag = HOM_SYS_NO_TERMINATE;
    homDeconfigSchedule deconfigSched = HOM_DECONFIG_IMMEDIATE; //See src/hwsv/server/hwsvTypes.H
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



    homHCDBUpdate hcdbUpdate = HOM_HCDB_DO_UPDATE;

    //Use this SDC unless determined in Check Stop processing to use a Latent, UE, or SUE saved SDC
    sdc = i_sdc;

    GardResolution::ErrorType prdGardErrType;
    homGardEnum gardState;  // homGardEnum in src/hwsv/server/hwsvTypes.H
    GARD_ErrorType gardErrType = GARD_NULL;
    homDeconfigEnum deconfigState = HOM_NO_DECONFIG;

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
    if (attn_type == MACHINE_CHECK)
    {
#ifdef  __HOSTBOOT_MODULE

        // FIXME: do we want to commit any log here?
        PRDF_ERR( PRDF_FUNC"Hostboot should NOT have any system checkstop!" );

#else
        writeVPD = true;              // Change the default so as to Write Capture Data
        pldCheck = true;              // Do the PLD check

        if (terminateOnCheckstop)
        {
            termFlag = HOM_SYS_TERMINATE_HW_CHECKSTOP; //Also need to return error log for machine check condition
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
    else if (attn_type == RECOVERABLE  || attn_type == UNIT_CS )
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

        // For a Recoverable Attn with MPFatal and Cause_attn_type not
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
    else if (attn_type == SPECIAL)
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

    gardState = HOM_DECONFIG_GARD;

    // If gardErrType was determined during latent/UE/SUE processing for Check Stop,
    // use that and not determine gardErrType from the sdc values.
    if (gardErrType != GARD_Func)
    {
        prdGardErrType = sdc.QueryGard();
        switch (prdGardErrType)
        {
            case GardResolution::NoGard:
                gardState = HOM_NO_GARD;
                gardErrType = GARD_NULL;
                break;
            case GardResolution::Predictive:
                gardErrType = GARD_Predictive;
                break;
            case GardResolution::Uncorrectable:
                gardErrType = GARD_Unrecoverable;
                break;
            case GardResolution::Fatal:
                gardErrType = GARD_Func;
                break;
            case GardResolution::Pending:
                gardErrType = GARD_Pending;
                // Do not set Call Home for Array Gard (Pending)
                actionFlag &= ~ERRL_ACTION_CALL_HOME;
                break;
            case GardResolution::CheckStopOnlyGard:
                if  (MACHINE_CHECK == attn_type)
                {
                    gardErrType = GARD_Func;
                }
                else
                {
                    gardState = HOM_NO_GARD;
                    gardErrType = GARD_NULL;
                }
                break;
            case GardResolution::DeconfigNoGard:
                gardState = HOM_NO_GARD;
                gardErrType = GARD_NULL;
                break;
            default:
                gardState = HOM_NO_GARD;
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
            gardState = HOM_NO_GARD;
            gardErrType = GARD_NULL;
            prdGardErrType = GardResolution::NoGard;
        }
        else
        {
            prdGardErrType = GardResolution::Fatal;
        }
    }

    if (sdc.IsThermalEvent() && (MACHINE_CHECK != attn_type) )
    {  //Force No Gard
        gardState = HOM_NO_GARD;
        gardErrType = GARD_NULL;
    }

    //**************************************************************
    // Callout loop to set up Reason code and SRC word 9
    //**************************************************************

    //FIXME  relevant PlatServices function defintions are not available yet
    //bool myCM_FUNCTIONAL = true;

    // Must go thru callout list to look for RIOPORT procedure callouts,
    // since they require the port info to be in SRC Word 9
    bool HW = false;
    bool SW = false;
    bool SW_High = false;
    bool SecondLevel = false;
    bool l_memBuffInCallouts = false;
    uint32_t SrcWord7 = 0;
    uint32_t SrcWord9 = 0;
    fspmrulist = sdc.GetMruList();
    int32_t calloutsPlusDimms = fspmrulist.size();
    for (SDC_MRU_LIST::iterator i = fspmrulist.begin(); i < fspmrulist.end(); ++i)
    {
        thiscallout = i->callout;
        if ( PRDcallout::TYPE_SYMFRU == thiscallout.getType() )
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
        else if ( PRDcallout::TYPE_MEMMRU == thiscallout.getType() )
        {
            PrdfMemoryMru memMru = thiscallout.getMemMru();
            SrcWord9 = memMru.toUint32(); // Get MemMru value

/* FIXME: Add support after refactoring PrdfMemoryMru

            TargetHandleList partList = memMru.getCalloutList();
            uint32_t partCount = partList.size();

            calloutsPlusDimms = calloutsPlusDimms + partCount -1;
            HW = true; //hardware callout

            // If we are in Concurrent Maintenance Mode, we will need to disable
            // the Deferred Deconfig, if the callouts are not HOM_CM_FUNCTIONAL.

            // FIXME PlatServices::inCMMode() not available yet
            if (PlatServices::inCMMode())
            {
                if (partCount < 1)
                {
                    // Something wrong with memmru
                    myCM_FUNCTIONAL = false;
                    PRDF_TRAC( "PRDTRACE: RasServices MemMru has no callouts" );
                }
                else
                {
                    for ( TargetHandleList::iterator it = partList.begin();
                          it != partList.end(); it++ )
                    {
                        if ( !PlatServices::isCM_FUNCTIONAL(*it) )
                        {
                            myCM_FUNCTIONAL = false;
                            PRDF_TRAC( PRDF_FUNC"isCM_FUNCTIONAL is false for ID: 0x%08x",
                                       PlatServices::getHuid(*it) );
                            break;
                        }
                    }
                }
            }
*/
        }
        else // PRDcallout::TYPE_TARGET
        {
            HW = true; // Hardware callout

            TargetHandle_t target = thiscallout.getTarget();
            if ( TYPE_MEMBUF == PlatServices::getTargetType(target) )
                l_memBuffInCallouts = true;

            // If we are in Concurrent Maintenance Mode, we will need to disable the
            // Deferred Deconfig, if the callouts are not HOM_CM_FUNCTIONAL.
            // FIXME PlatServices::inCMMode() not avaialble yet
            #if 0
            if (PlatServices::inCMMode())
            {
            // FIXME PlatServices::isCM_FUNCTIONAL  not avaialble yet
                if ( !PlatServices::isCM_FUNCTIONAL(l_thisChipHandle) )
                {
                    myCM_FUNCTIONAL = false;
                    PRDF_TRAC( "PRDTRACE: RasServices CM not functional for ID: %x",
                               PlatServices::getHuid(l_thisChipHandle) );
                }
            }
            #endif
        }

    }

    ////////////////////////////////////////////////////////////////
    //Set the PRD Reason Code based on the flags set in the above callout loop.
    ////////////////////////////////////////////////////////////////
    uint16_t SDC_Reason_Code = sdc.GetReasonCode();
    if (SDC_Reason_Code == 0) //If the analysis code has not set its own Reason Code.
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
            //If we get here both HW and SW flags were false. Callout may be Second Level
            //Support only, or a procedure not checked in the SW flag code.
            PRD_Reason_Code = PRDF_DETECTED_FAIL_HARDWARE_PROBABLE;
        }
    }
    else
    {   //Set to Reason Code in SDC, set by the chip analysis code.
        PRD_Reason_Code = SDC_Reason_Code;
    }

    SrcWord7 = i_sdc.GetAttentionType() << 8;
    SrcWord7 |= i_sdc.GetCauseAttentionType();

    //**************************************************************
    // Check for IPL Diag Mode and set up for Deferred Deconfig
    //**************************************************************

 //TODO TargetHandle conversion -defferredDeconfigMasterNot avaialable yet
#if 0
    hutlIplStepManager* stepManager = PlatServices::getDeferredDeconfigMaster();
    if ( NULL != stepManager )
    {
        iplDiagMode = true;
        if ( (MACHINE_CHECK != attn_type || !terminateOnCheckstop) &&
              myCM_FUNCTIONAL             &&
              (HOM_NO_GARD != gardState ||
               GardResolution::DeconfigNoGard == prdGardErrType )  ) //Allow Deferred Deconfig for IPL Diag when No Gard action is needed
        {
            deferDeconfig = true;
            deconfigState = HOM_DECONFIG;
            deconfigSched = HOM_DECONFIG_DEFER;
        }

    }

#endif


    //**************************************************************
    // Create Error Log with SRC
    //**************************************************************
    ErrorSignature * esig = sdc.GetErrorSignature();

    PRDF_HW_CREATE_ERRL(errLog,
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
        AddCapData(sdc,errLog);
        capDataAdded = true;
    }

    // make sure serviceAction doesn't override errl severity
    errLog->setSev(severityParm);

    if (ERRL_ACTION_HIDDEN == actionFlag)
    {  //Change HCDB Update to not do the update for non-visible logs
        hcdbUpdate = HOM_HCDB_OVERRIDE;
    }

    //**************************************************************
    // Add each mru/callout to the error log.
    //**************************************************************
    fspmrulist = sdc.GetMruList();
    uint32_t calloutcount = fspmrulist.size();
    for (SDC_MRU_LIST::iterator i = fspmrulist.begin(); i < fspmrulist.end(); ++i)
    {
        thispriority = (*i).priority;
        thiscallout = (*i).callout;
        if ( PRDcallout::TYPE_TARGET == thiscallout.getType() )
        {
            TargetHandle_t target = thiscallout.getTarget();
            // Don't deconfig a Memory Controller for Bus Errors (Mc and SuperNova
            // both in Callouts) for Mem Diag. Note still deconfg the SuperNova.
            homDeconfigEnum thisDeconfigState = deconfigState;
            TYPE l_targetType = PlatServices::getTargetType(target);
            if ( HOM_DECONFIG == deconfigState  &&
                 l_memBuffInCallouts            &&
                 (l_targetType  ==  TYPE_MCS)) //InP8 only 1:1 connection between Mem Buf and Mem ctrl
            {
                thisDeconfigState = HOM_NO_DECONFIG;
            }

            #ifdef __HOSTBOOT_MODULE
            // FIXME: this will change once mdia mode support is in
            if(true == iplDiagMode)
            {
              thisDeconfigState = HOM_DEFER_DECONFIG; // DELAYED_DECONFIG;
            }
            #endif

            PRDF_HW_ADD_CALLOUT(ForceTerminate,
                                target,
                                thispriority,
                                thisDeconfigState,
                                gardState,
                                errLog,
                                writeVPD,
                                gardErrType,
                                severityParm,
                                hcdbUpdate);

        }
        else if ( PRDcallout::TYPE_MEMMRU == thiscallout.getType() )
        {
            // FIXME: PrdfMemoryMru will need refactor later
            PrdfMemoryMru memMru = thiscallout.getMemMru();

            PRDF_HW_ADD_MEMMRU_CALLOUT(ForceTerminate,
                                       memMru,
                                       thispriority,
                                       deconfigState,
                                       gardState,
                                       errLog,
                                       writeVPD,
                                       gardErrType,
                                       severityParm,
                                       hcdbUpdate);
        }
        else if ( PRDcallout::TYPE_SYMFRU == thiscallout.getType() )
        {
            thisProcedureID = epubProcedureID(thiscallout.flatten());

            PRDF_DTRAC( PRDF_FUNC"thisProcedureID: %x, thispriority: %x, severityParm: %x",
                   thisProcedureID, thispriority,severityParm );

            PRDF_HW_ADD_PROC_CALLOUT(thisProcedureID,
                                     thispriority,
                                     errLog,
                                     severityParm);

            // Use the flags set earlier to determine if the callout is just Software (SP code or Phyp Code).
            // Add a Second Level Support procedure callout Low, for this case.
            if (HW == false && SW == true && SecondLevel == false)
            {
                PRDF_DTRAC( PRDF_FUNC"thisProcedureID= %x, thispriority=%x, severityParm=%x",
                   EPUB_PRC_LVL_SUPP, MRU_LOW, severityParm );

                PRDF_HW_ADD_PROC_CALLOUT(EPUB_PRC_LVL_SUPP,
                                         MRU_LOW,
                                         errLog,
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
    PfaData.MsDumpLabel[0] = 0x4D532020;                //start of MS Dump flags
    PfaData.MsDumpLabel[1] = 0x44554D50;                // 'MS  DUMP'

    TargetHandle_t l_dumpHandle = NULL;
#ifdef  __HOSTBOOT_MODULE
    sdc.GetDumpRequest( l_dumpHandle );
#else
    hwTableContent l_dumpRequestContent; //not used but needed to call GetDumpRequest
    sdc.GetDumpRequest( l_dumpRequestContent, l_dumpHandle );
#endif

    PfaData.MsDumpInfo.DumpId = PlatServices::getHuid(l_dumpHandle);
    TYPE l_targetType = PlatServices::getTargetType(l_dumpHandle);

    if (i_sdc.IsMpDumpReq())
    {
        PfaData.MP_DUMP_REQ = 1;
    }
    else
    {
        PfaData.MP_DUMP_REQ = 0;
    }
    if (i_sdc.IsMpResetReq())
    {
        PfaData.MP_RESET_REQ = 1;
    }
    else
    {
        PfaData.MP_RESET_REQ = 0;
    }
    //Pass Error Log Action Flag to attn handling, so it know what actions to commit

    PfaData.MP_FATAL = (i_sdc.IsMpFatal()==true)? 1:0;

    PfaData.PFA_errlActions = actionFlag;
    PfaData.PFA_errlSeverity = severityParm;

    PfaData.REBOOT_MSG = 0; //  Not supported??
    PfaData.DUMP = (sdc.IsDump()==true)? 1:0;
    PfaData.UERE = (sdc.IsUERE()==true)? 1:0;
    PfaData.SUE = (sdc.IsSUE()==true)? 1:0;
    PfaData.CRUMB = (sdc.MaybeCrumb()==true)? 1:0;
    PfaData.AT_THRESHOLD = (sdc.IsAtThreshold()==true)? 1:0;
    PfaData.DEGRADED = (sdc.IsDegraded()==true)? 1:0;
    PfaData.SERVICE_CALL = (sdc.IsServiceCall()==true)? 1:0;
    PfaData.TRACKIT = (sdc.IsMfgTracking()==true)? 1:0;
    PfaData.TERMINATE = (sdc.Terminate()==true)? 1:0;
    PfaData.LOGIT = (sdc.IsLogging()==true)? 1:0;
    PfaData.MEMORY_STEERED = (sdc.IsMemorySteered()==true)? 1:0;
    PfaData.FLOODING = (sdc.IsFlooding()==true)? 1:0;

    PfaData.ErrorCount = sdc.GetHits();
    PfaData.PRDServiceActionCounter = serviceActionCounter;
    PfaData.Threshold = sdc.GetThreshold();
    PfaData.ErrorType = prdGardErrType;
    PfaData.homGardState = gardState;
    PfaData.PRD_AttnTypes = attn_type;
    PfaData.PRD_SecondAttnTypes = i_sdc.GetCauseAttentionType();
    PfaData.THERMAL_EVENT = (sdc.IsThermalEvent()==true)? 1:0;
    PfaData.UNIT_CHECKSTOP = (sdc.IsUnitCS()==true)? 1:0;
    PfaData.USING_SAVED_SDC = (sdc.IsUsingSavedSdc()==true)? 1:0;
    PfaData.FORCE_LATENT_CS = (i_sdc.IsForceLatentCS()==true)? 1:0;
    PfaData.DEFER_DECONFIG_MASTER = (iplDiagMode==true)? 1:0;
    PfaData.DEFER_DECONFIG = (deferDeconfig==true)? 1:0;
    PfaData.CM_MODE = 0; //FIXME  Need to change this initialization
    PfaData.TERMINATE_ON_CS = (terminateOnCheckstop==true)? 1:0;
    PfaData.reasonCode = sdc.GetReasonCode();
    PfaData.PfaCalloutCount = calloutcount;

    // First clear out the PFA Callout list from previous SRC
    for (uint32_t j = 0; j < prdfMruListLIMIT; ++j)
    {
        PfaData.PfaCalloutList[j].Callout = 0;
        PfaData.PfaCalloutList[j].MRUtype = 0;
        PfaData.PfaCalloutList[j].MRUpriority = 0;
    }

    // Build the mru list into PFA data Callout list
    uint32_t n = 0;
    fspmrulist = sdc.GetMruList();
    for ( SDC_MRU_LIST::iterator i = fspmrulist.begin();
          i < fspmrulist.end(); ++i )
    {
        if ( n < prdfMruListLIMIT )
        {
            PfaData.PfaCalloutList[n].MRUpriority = (uint8_t)(*i).priority;
            PfaData.PfaCalloutList[n].Callout = i->callout.flatten();
            PfaData.PfaCalloutList[n].MRUtype = i->callout.getType();

            ++n;
        }
    }

#ifndef __HOSTBOOT_MODULE
    // FIXME: need to investigate whether or not we need to add HCDB support in Hostboot
    // First clear out the HCDB from previous SRC
    for (uint32_t j = 0; j < prdfHcdbListLIMIT; ++j)
    {
        PfaData.PfaHcdbList[j].hcdbId = 0;//Resetting entity path
        PfaData.PfaHcdbList[j].compSubType = 0;
        PfaData.PfaHcdbList[j].compType = 0;
        PfaData.PfaHcdbList[j].hcdbReserved1 = 0;
        PfaData.PfaHcdbList[j].hcdbReserved2 = 0;
    }

    // Build the HCDB list into PFA data
    n = 0;
    hcdbList = sdc.GetHcdbList();
    PfaData.hcdbListCount = hcdbList.size();
    for (HCDB_CHANGE_LIST::iterator i = hcdbList.begin(); i < hcdbList.end(); ++i)
    {
        if (n < prdfHcdbListLIMIT)
        {
            PfaData.PfaHcdbList[n].hcdbId = PlatServices::getHuid((*i).iv_phcdbtargetHandle);
            PfaData.PfaHcdbList[n].compSubType = (*i).iv_compSubType;
            PfaData.PfaHcdbList[n].compType = (*i).iv_compType;
            ++n;
        }
        else
            break;
    }
    // Set flag so we know to parse the hcdb data
    PfaData.HCDB_SUPPORT = 1;
#endif // if not __HOSTBOOT_MODULE

    PRDF_SIGNATURES signatureList = sdc.GetSignatureList();
    // First clear out the HCDB from previous SRC
    for (uint32_t j = 0; j < prdfSignatureListLIMIT; ++j)
    {
        PfaData.PfaSignatureList[j].chipId = 0;//Resetting the chipPath
        PfaData.PfaSignatureList[j].signature = 0;
    }

    // Build the signature list into PFA data
    n = 0;
    signatureList = sdc.GetSignatureList();
    PfaData.signatureCount = signatureList.size();
    for (PRDF_SIGNATURES::iterator i = signatureList.begin(); i < signatureList.end(); ++i)
    {
        if (n < prdfSignatureListLIMIT)
        {
            PfaData.PfaSignatureList[n].chipId = PlatServices::getHuid((*i).iv_pSignatureHandle);
            PfaData.PfaSignatureList[n].signature = (*i).iv_signature;
            ++n;
        }
        else
            break;
    }
    // Set flag so we know to parse the hcdb data
    PfaData.SIGNATURE_SUPPORT = 1;

    //**************************************************************
    // Check for Unit CheckStop.
    // Check for Last Functional Core.
    // PFA data updates for these item.
    //**************************************************************
    PfaData.LAST_CORE_TERMINATE = false;
    // Now the check is for Unit Check Stop and Dump ID for Processor
    // Skip the termination on Last Core if this is a Saved SDC
    if (sdc.IsUnitCS()  && (!sdc.IsUsingSavedSdc() ) )
    {
        PRDF_TRAC( PRDF_FUNC"Unit CS, Func HUID: %x, TargetType: %x",
                   PfaData.MsDumpInfo.DumpId, l_targetType );
        if (TYPE_CORE ==l_targetType)
        {
            //Check if this is last functional core
            if ( PlatServices::checkLastFuncCore(l_dumpHandle) )
            {
                PRDF_TRAC( PRDF_FUNC"Last Func Core from Gard was true." );
                ForceTerminate = true;
                PfaData.LAST_CORE_TERMINATE = true;
                errLog->setSev(ERRL_SEV_UNRECOVERABLE);  //Update Errl Severity
                PfaData.PFA_errlSeverity = ERRL_SEV_UNRECOVERABLE; //Update PFA data
            }
        }
    }

    // Check the errl for the terminate state
    // Note: will also be true for CheckStop attn.
    bool l_termSRC = false;
    PRDF_GET_TERM_SRC(errLog, l_termSRC);
    if(l_termSRC)
    {
        ForceTerminate = true;
        uint32_t l_plid = 0;
        PRDF_GET_PLID(errLog, l_plid);
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
            PRDF_SRC_WRITE_TERM_STATE_ON(errLog, SRCI_TERM_STATE_MNFG);
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
            PRDF_SRC_WRITE_TERM_STATE_ON(errLog, SRCI_TERM_STATE_MNFG);
        }

        if (sdc.IsThermalEvent() )
        {  //For Manufacturing Mode terminate, change the action flags for Thermal Event.
            actionFlag = (ERRL_ACTION_SA | ERRL_ACTION_REPORT | ERRL_ACTION_CALL_HOME);
        }
        PfaData.PFA_errlActions = actionFlag;
    }


    // Needed to move the errl add user data sections here because of some updates
    // of the data required in the Aysnc section for the SMA dual reporting fix.

    //**************************************************************
    // Add the PFA data to Error Log User Data
    //**************************************************************
    UtilMem l_membuf;
    l_membuf << PfaData;
    PRDF_ADD_FFDC( errLog, (const char*)l_membuf.base(), l_membuf.size(),
                   prdfErrlVer1, prdfErrlSectPFA5_1 );

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
            errLog->addUsrDtls(l_membuf.base(),l_membuf.size(),PRDF_COMP_ID,prdfErrlVer1,prdfErrlAVPData_1);
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
            PRDF_ADD_FFDC( errLog, (const char*)usrDtlsTCData, sz_usrDtlsTCData,
                           prdfErrlVer1, prdfErrlAVPData_2 );
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
        AddCapData(sdc,errLog);
    }

    // Note moved the code from here, that was associated with checking for the last
    // functional core to be before the PFA data is placed in error log.

    // Collect PRD trace
    // NOTE: Each line of trace is on average 36 bytes so 768 bytes should get
    //       us around 21 lines of trace output.
    PRDF_COLLECT_TRACE(errLog, 768);

    //**************************************************************
    // Commit the eror log.
    // This will also perform Gard and Deconfig actions.
    // Do the Unit Dumps if needed.
    //**************************************************************
    if (sdc.IsDontCommitErrl() && !sdc.IsUnitCS() && (MACHINE_CHECK != attn_type) )
    {
        delete errLog;
        errLog = NULL;
    }
    else if (!ReturnELog && !ForceTerminate && !i_sdc.IsMpFatal() && !i_sdc.Terminate())
    {
        //Check to see if we need to do a Proc Core dump
        if (sdc.IsUnitCS() && (!sdc.IsUsingSavedSdc() ) )
        {
            if (l_targetType == TYPE_PROC)
            {
                // NX Unit Checktop - runtime deconfig each accelerator
                errlHndl_t dumpErrl = NULL;
                SDC_MRU_LIST mrulist = sdc.GetMruList();
                for (SDC_MRU_LIST::iterator i = mrulist.begin();
                     i < mrulist.end(); ++i)
                {
                    //FIXME: need to add accelerators runtime deconfig
/*
                    TargetHandle_t  l_acceleratorHandle = (*i).callout.getMruValues();
                    if (TYPE_CORE == PlatServices::getTargetType(l_acceleratorHandle))
                    {
                        dumpErrl = PlatServices::runtimeDeconfig(PlatServices::getHuid(l_acceleratorHandle));
                        if  (dumpErrl != NULL)
                            break;
                    }
*/
                }

                if  (dumpErrl != NULL)
                {
                    PRDF_COMMIT_ERRL(dumpErrl, ERRL_ACTION_REPORT);
                }
                else
                {
                    PRDF_HWUDUMP(dumpErrl, errLog, CONTENT_HWNXLCL,
                                 PfaData.MsDumpInfo.DumpId);
                    if  (dumpErrl != NULL)
                    {
                        PRDF_COMMIT_ERRL(dumpErrl, ERRL_ACTION_REPORT);
                    }
                }
            }
            else
            {
                errlHndl_t dumpErrl =NULL;
                PRDF_RUNTIME_DECONFIG(dumpErrl, l_dumpHandle);
                if  (dumpErrl != NULL)
                {
                    PRDF_COMMIT_ERRL(dumpErrl, ERRL_ACTION_REPORT);
                }
                else
                {   //Call Dump for Proc Core CS
                    if (TYPE_CORE == l_targetType)
                    {
                         PRDF_HWUDUMP(dumpErrl, errLog, CONTENT_SINGLE_CORE_CHECKSTOP,
                                      PfaData.MsDumpInfo.DumpId);
                    }
                    // remove dump CONTENT_HWGAL2LCL since no IOHUB dump
                    // is supported in P8
                    // FIXME : will need to add Centaur DMI channel checkstop support later
                    else
                    {  //This is not Proc ..ie. it is Galaxy 2
                        PRDF_ERR( PRDF_FUNC"Unsupported dump for DumpId: %x, TargetType: %x",
                                       PfaData.MsDumpInfo.DumpId, l_targetType );
                    }
                }
                if  (dumpErrl != NULL)
                {
                    PRDF_COMMIT_ERRL(dumpErrl, ERRL_ACTION_REPORT);
                }
            }
        }

        // Commit the Error log
        // Need to move below here since we'll need
        // to pass errLog to PRDF_HWUDUMP
        // for FSP specific SRC handling in the future
#ifndef __HOSTBOOT_MODULE
        /* FIXME: not sure if we still need this in fips810?
        MnfgTrace(esig); */
#endif

        PRDF_GET_PLID(errLog, dumpPlid);

        bool l_sysTerm = false;
        PRDF_HW_COMMIT_ERRL(l_sysTerm,
                            errLog,
                            deconfigSched,
                            actionFlag,
                            HOM_CONTINUE);
        if(true == l_sysTerm) // if sysTerm then we have to commit and delete the log
        {
            //Just commit the log
            uint32_t l_rc = 0;
            PRDF_GET_RC(errLog, l_rc);

            uint16_t l_reasonCode = 0;
            PRDF_GET_REASONCODE(errLog, l_reasonCode);

            PRDF_INF( PRDF_FUNC"committing error log: PLID=%.8X, ReasonCode=%.8X, RC=%.8X, actions=%.4X",
                      dumpPlid,
                      l_reasonCode,
                      l_rc, actionFlag );
            PRDF_COMMIT_ERRL(errLog, actionFlag);
        }
        else
        {
            // Error log has been committed, return NULL Error Log to PrdMain
            errLog = NULL;
        }

    }
    // If the Error Log is not committed (as due to a Terminate condtion),
    // the Error Log will be returned to PRDMain
    else
    {

#ifndef __HOSTBOOT_MODULE
        /* FIXME: not sure if we still need this in fips810?
        MnfgTrace(esig); */
#endif

        PRDF_DTRAC( PRDF_FUNC"generating a terminating, or MP Fatal SRC" );
        if (ForceTerminate && sdc.IsThermalEvent() ) //MP42 a  Start
        {  //For Manufacturing Mode terminate, change the severity in
           //the error log to be Predictive for Thermal Event.
            errLog->setSev(ERRL_SEV_PREDICTIVE);
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
        PRDF_DTRAC( "PRDTRACE: Callout: %x", (uint32_t)((*i).callout) );

        switch ( (*i).priority )
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
            case GardResolution::Uncorrectable:
                PRDF_DTRAC( "PRDTRACE:   Uncorrectable" );     break;
            case GardResolution::Fatal:
                PRDF_DTRAC( "PRDTRACE:   Fatal" );             break;
            case GardResolution::Pending:
                PRDF_DTRAC( "PRDTRACE:   Pending" );           break;
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

    PRDF_DEXIT( PRDF_FUNC );

    return errLog;

    #undef PRDF_FUNC
}

void prdfGetTargetString(TargetHandle_t  i_pTargetHandle,
                         char * o_chipName, uint32_t i_sizeOfChipName )
{
    //FIXME  waiting on alternate implementation of toString function in targeting
    //FIXME Commenting out current usage of getEntityPathString
    //char * l_entityPathString =NULL;
    //uint32_t l_tempSize  =0;
    do
    {
        if(NULL==i_pTargetHandle )
        {
#ifdef  __HOSTBOOT_MODULE
            sprintf( o_chipName, "????, " );
#else
            snprintf( o_chipName, i_sizeOfChipName, "????, " );
#endif

        }
        else
        {
/*
            l_entityPathString =PlatServices::getEntityPathString(i_pTargetHandle);
            l_tempSize  = strlen(l_entityPathString );
            if(l_tempSize < i_sizeOfChipName)
                i_sizeOfChipName = l_tempSize;
            memcpy(o_chipName ,l_entityPathString ,i_sizeOfChipName);
            free(l_entityPathString);
*/
        }

    } while (0);
}


// ----------------------------------------------------------------------------

#ifndef __HOSTBOOT_MODULE
void RasServices::MnfgTrace(ErrorSignature * l_esig )
{
    char  * MnfgFilename = NULL;
    uint32_t l_size = 0;
    const char * MnfgKey[] = {"fstp/P0_Root"};

    if ( PlatServices::mfgMode() )
    {
        errlHndl_t errorLog = UtilReg::path(MnfgKey,1,"prdfMfgErrors",MnfgFilename,l_size);
        if (errorLog == NULL)
        {
            UtilFile l_mfgFile;
            l_mfgFile.Open(MnfgFilename,"a+");

            char l_array[62];
            char l_array2[42];
            uint32_t signature = l_esig->getSigId();
            HUID sigChip = l_esig->getChipId();

            // Get Entity Path String
            TargetHandle_t l_ptempHandle = PlatServices::getTarget(sigChip);
            prdfGetTargetString(l_ptempHandle , l_array, 62);
            l_mfgFile.write(l_array, strlen(l_array));

            // Write Signature
            snprintf(l_array, 62, "0x%08x,", signature);
            l_mfgFile.write(l_array, 24);

            // Write chip ECID data
            char ecidString[1024];
            l_ptempHandle = PlatServices::getTarget(PfaData.PfaCalloutList[0].Callout);
            //TODO TargetHandle conversion - not sure we need it now
            PlatServices::getECIDString(l_ptempHandle , ecidString);
            l_mfgFile.write(ecidString, strlen(ecidString));

            // Write MRU list
            uint32_t n = 0;
            while ( (n < prdfMruListLIMIT )  && (n < PfaData.PfaCalloutCount) )
            {
                snprintf(l_array2, 16, ", %08x", PfaData.PfaCalloutList[n].Callout);
                l_mfgFile.write(l_array2, 9);
                ++n;
            }
            snprintf(l_array2, 42, "\n");
            l_mfgFile.write(l_array2, 1);

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

// ----------------------------------------------------------------------------

void ErrDataService::AddCapData(ServiceDataCollector & i_sdc, errlHndl_t i_errHdl)
{
    // NOTE: Labels on this structure are not being verified in the
    //       plugins.  If that behavior changes, we must use htonl()
    //       to fix the endianness on them.

    prdfCaptureData * l_CapDataBuf = new prdfCaptureData;

    for(uint32_t ii = 0; ii < CaptureDataSize; ++ii)
    {
        l_CapDataBuf->CaptureData[ii] = 0xFF;
    }

    l_CapDataBuf->CaptureData_Label = CPTR_Identifier;        //Start of Capture Data 'CPTR'
    l_CapDataBuf->EndLabel[0]           = 0x454E4420;        // End of Capture data
    l_CapDataBuf->EndLabel[1]           = 0x44415441;        // 'END DATA'

    uint32_t thisCapDataSize =  i_sdc.GetCaptureData().Copy(l_CapDataBuf->CaptureData,CaptureDataSize);

    thisCapDataSize = thisCapDataSize + 32; // include the eye catcher labels

    l_CapDataBuf->PfaCaptureDataSize = thisCapDataSize;
    l_CapDataBuf->PfaCaptureDataSize = htonl(l_CapDataBuf->PfaCaptureDataSize);

    //Compress the Capture data
    size_t l_compressBufSize =
      PrdfCompressBuffer::compressedBufferMax(thisCapDataSize);
    const size_t sz_compressCapBuf = l_compressBufSize + 4;
    uint8_t * l_compressCapBuf = new uint8_t[sz_compressCapBuf];

    memcpy(l_compressCapBuf, l_CapDataBuf, 4); // grab CPTR string
    PrdfCompressBuffer::compressBuffer( &((uint8_t *) l_CapDataBuf)[4],
                                        (size_t) thisCapDataSize - 4,
                                        &l_compressCapBuf[4],
                                        l_compressBufSize);

    //Add the Compressed Capture data to Error Log User Data
    PRDF_ADD_FFDC( i_errHdl, (const char*)l_compressCapBuf,
                   sz_compressCapBuf, prdfErrlVer2, prdfErrlCapData_1 );
    delete [] l_compressCapBuf;
    delete l_CapDataBuf;
}

// ----------------------------------------------------------------------------
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
      * @reasoncode PRDF_HARDWARE_FAIL
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
      * @devdesc CEC hardware failure detected
      * @procedure EPUB_PRC_SP_CODE
      * @procedure  EPUB_PRC_PHYP_CODE
      * @procedure  EPUB_PRC_LVL_SUPP
      * @procedure  EPUB_PRC_ALL_PROCS
      * @procedure  EPUB_PRC_REBOOT
      */

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

