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
#include <prdfErrlUtil.H>
#include <iipResolutionFactory.h>
#include <iipSystem.h>
#include <prdrLoadChipCache.H>  // To flush chip-file cache.
#include <prdfPlatServices.H>
#include <prdfRasServices.H>
#include <prdfRegisterCache.H>
#include <prdfScanFacility.H>
#include <prdfSystemSpecific.H>
#include <prdfMfgThresholdMgr.H>

namespace PRDF
{

//------------------------------------------------------------------------------
// Forward references
//------------------------------------------------------------------------------

extern void initPlatSpecific();

//------------------------------------------------------------------------------
// Global Variables
//------------------------------------------------------------------------------

System * systemPtr = NULL;
ErrlSmartPtr g_prd_errlHndl; // inited to NULL in ctor.
bool g_initialized = false;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

void unInitialize()
{
    PRDF_ENTER( "PRDF::unInitialize()" );

    delete systemPtr;
    systemPtr = NULL;
    g_initialized = false;
    // Some Resolutions carry state and must be re-created - this call resets
    // what it needs to.
    ResolutionFactory::Access().Reset();

    // clear the MfgThresholdMgr
    MfgThresholdMgr::getInstance()->reset();

    PRDF_EXIT( "PRDF::unInitialize()" );
}

//------------------------------------------------------------------------------

errlHndl_t initialize()
{
    PRDF_ENTER( "PRDF::initialize()" );

    // will unlock when going out of scope
    // this lock is recursive so it's ok to lock again
    // as long as calling from the same thread
    PRDF_SYSTEM_SCOPELOCK;

    g_prd_errlHndl = NULL; // This forces any previous errls to be committed

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

        // Perform platform specific initialization.
        initPlatSpecific();

        CcAutoDeletePointer<Configurator> configuratorPtr
            (SystemSpecific::getConfiguratorPtr());

        errlHndl_t l_errBuild = configuratorPtr->build();//build object model
        if( NULL != l_errBuild )
        {
            //there is some problem in building RuleMetaData object
            g_prd_errlHndl = l_errBuild;

            //object model is either not build or at best incomplete.We must
            // clean this up .The easiest way is to delete the system which in
            //in turn shall clean up the constituents.
            delete systemPtr;
            systemPtr = NULL;
            g_initialized = false;
            PRDF_ERR("PRDF::initialize() failed to buid object model");
        }
        //systemPtr is populated in configurator
        else if( systemPtr != NULL )
        {
            systemPtr->Initialize(); // Hardware initialization
            g_initialized = true;
        }

        // Flush rule table cache since objects are all built.
        Prdr::LoadChipCache::flushCache();
    }

    PRDF_EXIT( "PRDF::initialize()" );

    return (g_prd_errlHndl.release());
}

//------------------------------------------------------------------------------

errlHndl_t main( ATTENTION_VALUE_TYPE i_attentionType,
                 const AttnList & i_attnList )
{
    PRDF_ENTER( "PRDF::main() Global attnType=%04X", i_attentionType );

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    g_prd_errlHndl = NULL;

    uint32_t rc =  SUCCESS;
    // clears all the chips saved to stack during last analysis
    ServiceDataCollector::clearChipStack();

    if(( g_initialized == false)&&(NULL ==systemPtr))
    {
        g_prd_errlHndl = initialize();
        if(g_prd_errlHndl != NULL) rc = PRD_NOT_INITIALIZED;
    }

    ServiceDataCollector serviceData;
    STEP_CODE_DATA_STRUCT sdc;
    sdc.service_data = &serviceData;
    SYSTEM_DEBUG_CLASS sysdebug;

    sysdebug.Reinitialize(i_attnList); //Refresh sysdebug with latest Attn data

    ////////////////////////////////////////////////////////////////////////////
    // Normalize global attn type (ie 11,12,13,....) to (CHECKSTOP, RECOVERED,
    // SPECIAL..)
    ////////////////////////////////////////////////////////////////////////////

    if ( i_attentionType == INVALID_ATTENTION_TYPE ||
         i_attentionType >= END_ATTENTION_TYPE )
    {
        rc = PRD_INVALID_ATTENTION_TYPE;
        PRDF_ERR( "PrdMain: Invalid attention type! Global:%x",
                  i_attentionType );
        i_attentionType = RECOVERABLE; // This will prevent RAS service problems
    }

    // link to the right service Generator
    ServiceGeneratorClass & serviceGenerator =
        ServiceGeneratorClass::ThisServiceGenerator();

    // check for something wrong
    if ( g_initialized == false || rc != SUCCESS || systemPtr == NULL )
    {
        if(rc == SUCCESS)
        {
            rc = PRD_NOT_INITIALIZED;
        }
        PRDF_ERR("PrdMain: PRD failed. RC=%x",rc );
        // we are not going to do an analysis - so fill out the Service Data
        (serviceData.GetErrorSignature())->setSigId(rc);
        serviceData.SetCallout(SP_CODE);
        serviceData.SetThresholdMaskId(0); // Sets AT_THRESHOLD, DEGRADED,
                                           // SERVICE_CALL
    }
    else  // do the analysis
    {
        // flush Cache so that SCR reads access hardware
        RegDataCache::getCachedRegisters().flush();

        serviceData.SetAttentionType(i_attentionType);

        // capture time of day
        serviceGenerator.SetErrorTod( i_attentionType, serviceData );

        if(serviceGenerator.QueryLoggingBufferFull())
        {
            serviceData.SetFlooding();
        }

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
            // We have a bad RC, but no error log - Fill out SDC and have
            // service generator make one
            (serviceData.GetErrorSignature())->setErrCode(
                                                    (uint16_t)analyzeRc );
            serviceData.SetCallout(SP_CODE);
            serviceData.SetServiceCall();
            // We don't want to gard unless we have a good
            // return code
            serviceData.Gard(GardAction::NoGard);
        }
    }

    if(g_prd_errlHndl != NULL)
    {
        PRDF_INF("PRDTRACE: PrdMain: g_prd_errlHndl != NULL");
        PRDF_ADD_PROCEDURE_CALLOUT( g_prd_errlHndl, SRCI_PRIORITY_MED,
                                    EPUB_PRC_SP_CODE );

        // This forces any previous errls to be committed
        g_prd_errlHndl = NULL;

        // pw 597903 -- Don't GARD if we got a global error.
        serviceData.Gard(GardAction::NoGard);
    }

    g_prd_errlHndl = serviceGenerator.GenerateSrcPfa( i_attentionType,
                                                      serviceData );

    // Sleep for 20msec to let attention lines settle if we are at threshold.
    if ( (g_prd_errlHndl == NULL) && serviceData.IsAtThreshold() )
    {
        PlatServices::milliSleep( 0, 20 );
    }

    RasServices::SetTerminateOnCheckstop(true);

    PRDF_EXIT( "PRDF::main()" );

    return(g_prd_errlHndl.release());
}

//------------------------------------------------------------------------------

errlHndl_t refresh()
{
    PRDF_ENTER("PRDF::refresh()");

    errlHndl_t l_errl = NULL;

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    if((false == g_initialized) || (NULL == systemPtr))
    {
        l_errl = initialize();
    }
    else
    {
        // System was built so just check and
        // remove any non-functional chips
        systemPtr->RemoveNonFunctionalChips();
    }

    PRDF_EXIT("PRDF::refresh()");

    return l_errl;
}

//------------------------------------------------------------------------------

} // end namespace PRDF

