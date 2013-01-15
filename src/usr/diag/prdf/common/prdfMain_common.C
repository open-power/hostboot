/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfMain_common.C $                  */
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

/**
 * @file  prdfMain_common.C
 * @brief PRD code used by external components.
 *
 * This file contains code that is strictly common between FSP and Hostboot. All
 * platform specific code should be in the respective FSP only or Hostboot only
 * files.
 */

#include <prdfMain.H>

#include <CcAutoDeletePointer.h>
#include <iipglobl.h>
#include <iipResolutionFactory.h>
#include <iipSystem.h>
#include <prdrLoadChipCache.H>  // To flush chip-file cache.
#include <prdfPlatServices.H>
#include <prdf_ras_services.H>
#include <prdfRegisterCache.H>
#include <prdfScanFacility.H>
#include <prdfSystemSpecific.H>

// For some odd reason when compile in FSP, these includes have to be down here
// or there will be some weird compiling error in iipResolutionFactory.h
#ifndef __HOSTBOOT_MODULE
  #include <prdfChipPersist.H>          // for ChipPersist
  #include <prdfMfgThresholdMgr.H>
  #include <prdfSdcFileControl.H>       // for RestoreAnalysis()
#endif

namespace PRDF
{

//------------------------------------------------------------------------------
// Global Variables
//------------------------------------------------------------------------------

System * systemPtr = NULL;
ErrlSmartPtr g_prd_errlHndl; // inited to NULL in ctor.
bool g_initialized = false;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

void unInitialize(void)
{
    PRDF_ENTER( "PRDF::unInitialize()" );

    delete systemPtr;
    systemPtr = NULL;
    g_initialized = false;
    // Some Resolutions carry state and must be re-created - this call resets
    // what it needs to.
    ResolutionFactory::Access().Reset();

#ifndef __HOSTBOOT_MODULE
    // clear the MfgThresholdMgr
    MfgThresholdMgr::getInstance()->reset();
#endif

    PRDF_EXIT( "PRDF::unInitialize()" );
}

//------------------------------------------------------------------------------

errlHndl_t initialize()
{
    PRDF_ENTER( "PRDF::initialize()" );

    g_prd_errlHndl = NULL;  // This forces any previous errls to be committed dg09a

    // Synchronize SCOM access to hardware
    // Start un-synchronized so hardware is accessed
    RegDataCache::getCachedRegisters().flush();
    if(g_initialized == true && systemPtr != NULL)
    {
        // This means we are being re-initialized (and we were in a good state)
        // so Clean up in preparation for re-build
        unInitialize();
    }

    if(g_initialized == false)
    {
        // Initialize the Service Generator
        ServiceGeneratorClass & serviceGenerator =
            ServiceGeneratorClass::ThisServiceGenerator();
        serviceGenerator.Initialize();

#ifndef __HOSTBOOT_MODULE

        //FIXME RTC64373 Is this the correct place to add the check for the
        //saved SDC and sdc errl commit, if found???
        bool isSavedSdc = false;
        ServiceDataCollector thisSavedSdc;

        RestoreAnalysis(thisSavedSdc, isSavedSdc);
        if (isSavedSdc)
        {
            PRDF_INF("PRDF::initialize() Used Saved ReSync'd SDC for an errl");
            thisSavedSdc.SetFlag(ServiceDataCollector::USING_SAVED_SDC);
            errlHndl_t errl = serviceGenerator.GenerateSrcPfa(RECOVERABLE, thisSavedSdc);
            if (NULL != errl)
            {
                PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
            }
        }

        // Clear out old chip persistency (for CCM).
        TARGETING::TargetHandleList l_oldChips;
        for(ChipPersist::iterator i = ChipPersist::getInstance()->begin();
            i != ChipPersist::getInstance()->end();
            ++i)
        {
            if (!PlatServices::isFunctional(*i))
                l_oldChips.push_back(*i);
        }
        // This must be done afterwards otherwise the delete operation destroys
        // the ChipPersist::iterator.
        for(TARGETING::TargetHandleList::iterator i = l_oldChips.begin();
            i != l_oldChips.end();
            ++i)
        {
            ChipPersist::getInstance()->deleteEntry(*i);
        };
        // -- finished clearing out old chip persistency (for CCM).

#endif

        CcAutoDeletePointer<Configurator> configuratorPtr
            (SystemSpecific::getConfiguratorPtr());

        systemPtr = configuratorPtr->build();   // build PRD system model
        if(systemPtr != NULL)
        {
            systemPtr->Initialize(); // Hardware initialization & start scrub
            g_initialized = true;
        }
        else // something bad happend.
        {
            g_initialized = false;
        }

        // Flush rule table cache since objects are all built.
        Prdr::LoadChipCache::flushCache();
    }

    PRDF_EXIT( "PRDF::initialize()" );

    return (g_prd_errlHndl.release());
}

//------------------------------------------------------------------------------

errlHndl_t main(ATTENTION_VALUE_TYPE i_attentionType, const AttnList & i_attnList)
{
    PRDF_ENTER( "PRDF::main() Global attnType=%04X", i_attentionType );
    using namespace TARGETING;

    g_prd_errlHndl = NULL;

    uint32_t rc =  SUCCESS;
    // clears all the chips saved to stack during last analysis
    ServiceDataCollector::clearChipStack( );

    if(( g_initialized == false)&&(NULL ==systemPtr))
    {
        g_prd_errlHndl = initialize();
        if(g_prd_errlHndl != NULL) rc = PRD_NOT_INITIALIZED;
    }
    //FIXME enterCCMMode ,isInCCM  function not available in wrapper
    //    if (SystemData::getInstance()->isInCCM())
    //        PlatServices::enterCCMMode();

    bool latent_check_stop = false;
    ServiceDataCollector serviceData;
    STEP_CODE_DATA_STRUCT sdc;
    sdc.service_data = &serviceData;
    SYSTEM_DEBUG_CLASS sysdebug;

    sysdebug.Reinitialize(i_attnList); //Refresh sysdebug with latest Attn data

    ///////////////////////////////////////////////////////////////////////////////////
    // Normalize global attn type (ie 11,12,13,....) to (CHECKSTOP,RECOVERED,SPECIAL..)
    ////////////////////////////////////////////////////////////////////////////////////

    if(i_attentionType == INVALID_ATTENTION_TYPE || i_attentionType >= END_ATTENTION_TYPE)
    {
        rc = PRD_INVALID_ATTENTION_TYPE;
        PRDF_ERR("PrdMain: Invalid attention type! Global:%x" ,i_attentionType );
        i_attentionType = RECOVERABLE; // This will prevent RAS service problems
    }


    // link to the right service Generator
    ServiceGeneratorClass & serviceGenerator =
        ServiceGeneratorClass::ThisServiceGenerator();

    // check for something wrong
    if(g_initialized == false || rc != SUCCESS || systemPtr == NULL)
    {
        if(rc == SUCCESS)
        {
            rc = PRD_NOT_INITIALIZED;
        }
        PRDF_ERR("PrdMain: PRD failed. RC=%x",rc );
        // we are not going to do an analysis - so fill out the Service Data
        (serviceData.GetErrorSignature())->setSigId(rc);
        serviceData.SetCallout(SP_CODE);
        serviceData.SetThresholdMaskId(0); // Sets AT_THRESHOLD, DEGRADED, SERVICE_CALL
    }
    else  // do the analysis
    {
        // flush Cache so that SCR reads access hardware
        RegDataCache::getCachedRegisters().flush();

        serviceData.SetAttentionType(i_attentionType);

        // Check to see if this is a latent machine check.- capture time of day
        serviceGenerator.SetErrorTod(i_attentionType, &latent_check_stop,serviceData);

        if(serviceGenerator.QueryLoggingBufferFull())
        {
            serviceData.SetFlooding();
        }

        // If the checkstop is latent than Service Generator Will use the scd from the last call
        // to PRD - no further analysis needed.
        if (!latent_check_stop)
        {
            int32_t analyzeRc = systemPtr->Analyze(sdc, i_attentionType);
            // flush Cache to free up the memory
            RegDataCache::getCachedRegisters().flush();
            ScanFacility      & l_scanFac = ScanFacility::Access();
            //delete all the wrapper register objects since these were created
            //just for plugin code
            l_scanFac.ResetPluginRegister();
            SystemSpecific::postAnalysisWorkarounds(sdc);
            if(analyzeRc != SUCCESS && g_prd_errlHndl == NULL)
            {
                // We have a bad RC, but no error log - Fill out SDC and have service generator make one
                (serviceData.GetErrorSignature())->setErrCode((uint16_t)analyzeRc);
                serviceData.SetCallout(SP_CODE);
                serviceData.SetServiceCall();
                //mk438901 a We don't want to gard unless we have a good return code
                serviceData.Gard(GardResolution::NoGard);
            }
        }
    }

    if(g_prd_errlHndl != NULL)
    {
        PRDF_INF("PRDTRACE: PrdMain: g_prd_errlHndl != NULL");
        PRDF_ADD_PROCEDURE_CALLOUT(g_prd_errlHndl, SRCI_PRIORITY_MED, EPUB_PRC_SP_CODE);

        // This forces any previous errls to be committed
        g_prd_errlHndl = NULL;

        // pw 597903 -- Don't GARD if we got a global error.
        serviceData.Gard(GardResolution::NoGard);
    }

    g_prd_errlHndl = serviceGenerator.GenerateSrcPfa(i_attentionType, serviceData);

    //FIXME need delay to  let attention lines  settle

    // mk461813 a Sleep for 20msec to let attention lines settle if we are at threshold
    //if ((g_prd_errlHndl == NULL) && serviceData.IsAtThreshold())
    //{
        //may need to call some function to manage some delay
    //}

    RasServices::SetTerminateOnCheckstop(true);

    PRDF_EXIT( "PRDF::main()" );

    return(g_prd_errlHndl.release());
}

//------------------------------------------------------------------------------

void iplCleanup()
{
    PRDF_ENTER( "PRDF::iplCleanup()" );

#ifndef __HOSTBOOT_MODULE

    ChipPersist::getInstance()->clearData();

    if(PlatServices::isMasterFSP()) //only write registry key on primary
    {
        uint8_t  l_allZeros = 0;
        errlHndl_t errl = UtilReg::write("prdf/RasServices",
                                         &l_allZeros,
                                         sizeof(uint8_t));
        if (NULL != errl)
        {
            PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
        }
    }

#endif

    PRDF_EXIT( "PRDF::iplCleanup()" );

    return;
}

} // end namespace PRDF

