/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfMain_common.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2024                        */
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

/**
 * @file  prdfMain_common.C
 * @brief PRD code used by external components.
 *
 * This file contains code that is strictly common between FSP and Hostboot. All
 * platform specific code should be in the respective FSP only or Hostboot only
 * files.
 */

#include <prdfMain.H>

#include <prdfErrlUtil.H>
#include <iipResolutionFactory.h>
#include <iipSystem.h>
#include <prdrLoadChipCache.H>  // To flush chip-file cache.
#include <prdfPlatServices.H>
#include <prdfRasServices.H>
#include <prdfRegisterCache.H>
#include <prdfScanFacility.H>
#include <prdfMfgThresholdMgr.H>

#ifdef __HOSTBOOT_MODULE
#include <hbotcompid.H>
#endif

#ifdef __HOSTBOOT_RUNTIME
#include <prdfOcmbChipDomain.H>
#endif

#if !defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
#include <prdfSdcFileControl.H>
#endif

#include <prdfPlatConfigurator.H>

#include <memory>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
// Forward references
//------------------------------------------------------------------------------

extern void initPlatSpecific();

//------------------------------------------------------------------------------
// Global Variables
//------------------------------------------------------------------------------

System * systemPtr = nullptr;
ErrlSmartPtr g_prd_errlHndl; // inited to nullptr in ctor.
bool g_initialized = false;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

void uninitialize()
{
    PRDF_ENTER( "PRDF::uninitialize()" );

    delete systemPtr;
    systemPtr = nullptr;
    g_initialized = false;

    ScanFacility::Access().reset();

    // Some Resolutions carry state and must be re-created - this call resets
    // what it needs to.
    ResolutionFactory::Access().Reset();

    // clear the MfgThresholdMgr
    MfgThresholdMgr::getInstance()->reset();

    PRDF_EXIT( "PRDF::uninitialize()" );
}

//------------------------------------------------------------------------------

errlHndl_t noLock_initialize()
{
    #define PRDF_FUNC "PRDF::noLock_initialize() "

    PRDF_ENTER( PRDF_FUNC );

    g_prd_errlHndl = nullptr; // This forces any previous errls to be committed

    // Synchronize SCOM access to hardware
    // Start un-synchronized so hardware is accessed
    RegDataCache::getCachedRegisters().flush();

    if(g_initialized == true && systemPtr != nullptr)
    {
        // This means we are being re-initialized (and we were in a good state)
        // so Clean up in preparation for re-build
        PRDF::uninitialize();
    }

    if(g_initialized == false)
    {
        // Initialize the Service Generator
        ServiceGeneratorClass & serviceGenerator =
                    ServiceGeneratorClass::ThisServiceGenerator();
        serviceGenerator.Initialize();

        // Perform platform specific initialization.
        initPlatSpecific();

        // Note that the use of a pointer for the configurator is simply so that
        // it is allocated on the heap and not in the stack. The configurator,
        // not the system objects it creates, will be deleted as soon as it goes
        // out of scope.
        auto configuratorPtr = std::make_shared<PlatConfigurator>();

        errlHndl_t l_errBuild = configuratorPtr->build();//build object model
        if( nullptr != l_errBuild )
        {
            //there is some problem in building RuleMetaData object
            g_prd_errlHndl = l_errBuild;

            //object model is either not build or at best incomplete.We must
            // clean this up .The easiest way is to delete the system which in
            //in turn shall clean up the constituents.
            delete systemPtr;
            systemPtr = nullptr;
            g_initialized = false;
            PRDF_ERR(PRDF_FUNC "failed to buid object model");
        }
        //systemPtr is populated in configurator
        else if( systemPtr != nullptr )
        {
            systemPtr->Initialize(); // Hardware initialization
            g_initialized = true;
        }

        // Flush rule table cache since objects are all built.
        Prdr::LoadChipCache::flushCache();
    }

    #ifdef __HOSTBOOT_RUNTIME

    // Handle R/R scenario.
    TARGETING::MODEL procModel = getChipModel( getMasterProc() );
    if ( MODEL_POWER10 == procModel )
    {
        ((OcmbChipDomain *)systemPtr->GetDomain(OCMB_DOMAIN))->handleRrFo();
    }
    else
    {
        PRDF_ERR( PRDF_FUNC "Master PROC model %d not supported", procModel );
        PRDF_ASSERT(false);
    }

    #endif

    PRDF_EXIT( PRDF_FUNC );

    return (g_prd_errlHndl.release());

    #undef PRDF_FUNC
}

errlHndl_t initialize()
{
    PRDF_ENTER( "PRDF::initialize()" );

    errlHndl_t err = nullptr;

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    err = noLock_initialize();

    PRDF_EXIT( "PRDF::initialize()" );

    return err;

}

//------------------------------------------------------------------------------

errlHndl_t main( ATTENTION_VALUE_TYPE i_priAttnType,
                 const AttnList & i_attnList )
{
    PRDF_ENTER( "PRDF::main() Global attnType=%04X", i_priAttnType );

    // These have to be outside of system scope lock
    errlHndl_t retErrl = nullptr;

    { // system scope lock starts ------------------------------------------

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    g_prd_errlHndl = nullptr;

    uint32_t rc =  SUCCESS;
    // clears all the chips saved to stack during last analysis
    ServiceDataCollector::clearChipStack();

    if(( g_initialized == false)&&(nullptr ==systemPtr))
    {
        g_prd_errlHndl = noLock_initialize();
        if(g_prd_errlHndl != nullptr)
        {
            rc = PRD_NOT_INITIALIZED;

            #ifdef __HOSTBOOT_MODULE
            // Add extra traces to help determine why initialization failed.
            g_prd_errlHndl->collectTrace(VFS_COMP_NAME,  512);
            g_prd_errlHndl->collectTrace(PNOR_COMP_NAME, 512);
            g_prd_errlHndl->collectTrace(UTIL_COMP_NAME, 512);
            #endif
        }
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

    if ( i_priAttnType == INVALID_ATTENTION_TYPE ||
         i_priAttnType >= END_ATTENTION_TYPE )
    {
        rc = PRD_INVALID_ATTENTION_TYPE;
        PRDF_ERR( "PrdMain: Invalid attention type! Global:%x",
                  i_priAttnType );
        i_priAttnType = RECOVERABLE; // This will prevent RAS service problems
    }

    // link to the right service Generator
    ServiceGeneratorClass & serviceGenerator =
        ServiceGeneratorClass::ThisServiceGenerator();

    // Initialize the SDC error log. Required for GenerateSrcPfa() call below.
    serviceGenerator.createInitialErrl( i_priAttnType );

    // check for something wrong
    if ( g_initialized == false || rc != SUCCESS || systemPtr == nullptr )
    {
        if(rc == SUCCESS)
        {
            rc = PRD_NOT_INITIALIZED;
        }
        PRDF_ERR("PrdMain: PRD failed. RC=%x",rc );
        // we are not going to do an analysis - so fill out the Service Data
        (serviceData.GetErrorSignature())->setSigId(rc);
        serviceData.SetCallout(SP_CODE);
        serviceData.SetCallout( LEVEL2_SUPPORT, MRU_LOW );
        serviceData.SetThresholdMaskId(0); // Sets AT_THRESHOLD, DEGRADED,
                                           // SERVICE_CALL
    }
    else  // do the analysis
    {
        // flush Cache so that SCR reads access hardware
        RegDataCache::getCachedRegisters().flush();

        // The primary attention type must be set before calling Analyze().
        serviceData.setPrimaryAttnType(i_priAttnType);

        // Set the time in which PRD handled the error.
        Timer timeOfError;
        PlatServices::getCurrentTime( timeOfError );
        serviceData.SetTOE( timeOfError );

        ServiceDataCollector l_tempSdc = serviceData;
        l_tempSdc.setPrimaryPass();
        sdc.service_data = &l_tempSdc;

        int32_t analyzeRc = systemPtr->Analyze( sdc );

        if( PRD_SCAN_COMM_REGISTER_ZERO == analyzeRc )
        {
            // So, the first pass has failed. Hence, there are no primary
            // bits set. We must start second pass to see if there are any
            //secondary bits set.
            sdc.service_data = &serviceData;

            #if !defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
            ForceSyncAnalysis( l_tempSdc ); // save SDC till end of primary pass
            #endif

            // starting the second pass
            PRDF_INF( "PRDF::main() No bits found set in first pass,"
                      " starting second pass" );
            sysdebug.initAttnPendingtatus( ); //for the second  pass

            if( l_tempSdc.isSecondaryErrFound() )
            {
                sdc.service_data->setSecondaryErrFlag();
            }

            analyzeRc = systemPtr->Analyze( sdc );

            // merging capture data of primary pass with capture data of
            // secondary pass for better FFDC.
            serviceData.GetCaptureData().mergeData(
                                    l_tempSdc.GetCaptureData());

            #if !defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
            // save SDC till end of secondary pass
            ForceSyncAnalysis( serviceData );
            #endif
        }
        else
        {
            serviceData = l_tempSdc;
            sdc.service_data = &serviceData;
        }

        // flush Cache to free up the memory
        RegDataCache::getCachedRegisters().flush();
        ScanFacility      & l_scanFac = ScanFacility::Access();
        //delete all the wrapper register objects since these were created
        //just for plugin code
        l_scanFac.ResetPluginRegister();
        if(analyzeRc != SUCCESS && g_prd_errlHndl == nullptr)
        {
            (serviceData.GetErrorSignature())->setErrCode(
                                                    (uint16_t)analyzeRc );
            serviceData.SetCallout( SP_CODE, MRU_MED, NO_GARD );
            serviceData.SetCallout( LEVEL2_SUPPORT, MRU_LOW, NO_GARD );
            serviceData.setServiceCall();
            // We don't want to gard for non-checkstops unless we have a good
            // return code
            if ( CHECK_STOP != serviceData.getPrimaryAttnType() )
            {
                serviceData.clearMruListGard();
            }
        }
    }

    if(g_prd_errlHndl != nullptr)
    {
        PRDF_INF("PRDTRACE: PrdMain: g_prd_errlHndl != nullptr");
        PRDF_ADD_PROCEDURE_CALLOUT( g_prd_errlHndl, MRU_MED, SP_CODE );
        // This is a precautionary step. There is a possibilty that if
        // severity for g_prd_errlHndl is Predictve and there is only
        // SP_CODE callout than it will be changed to tracing event.
        // So adding LEVEL2_SUPPORT to avoid this.
        PRDF_ADD_PROCEDURE_CALLOUT( g_prd_errlHndl, MRU_LOW, LEVEL2_SUPPORT );

        // This forces any previous errls to be committed
        g_prd_errlHndl = nullptr;

        // pw 597903 -- Don't GARD if we got a global error.
        serviceData.clearMruListGard();
    }

    g_prd_errlHndl = serviceGenerator.GenerateSrcPfa( i_priAttnType,
                                                      serviceData );

    // Sleep for 20msec to let attention lines settle if we are at threshold.
    if ( (g_prd_errlHndl == nullptr) && serviceData.IsAtThreshold() )
    {
        PlatServices::milliSleep( 0, 20 );
    }

    retErrl = g_prd_errlHndl.release();

    } // system scope lock ends ------------------------------------------

    PRDF_EXIT( "PRDF::main()" );

    return retErrl;
}

//------------------------------------------------------------------------------

errlHndl_t noLock_refresh()
{
    PRDF_ENTER("PRDF::noLock_refresh()");

    errlHndl_t l_errl = nullptr;

    if((false == g_initialized) || (nullptr == systemPtr))
    {
        l_errl = noLock_initialize();
    }
    else
    {
        // System was built so just check and
        // remove any non-functional chips
        systemPtr->RemoveNonFunctionalChips();
    }

    PRDF_EXIT("PRDF::noLock_refresh()");

    return l_errl;
}

errlHndl_t refresh()
{
    PRDF_ENTER("PRDF::refresh()");

    errlHndl_t l_errl = nullptr;

    // will unlock when going out of scope
    PRDF_SYSTEM_SCOPELOCK;

    l_errl = noLock_refresh();

    PRDF_EXIT("PRDF::refresh()");

    return l_errl;
}

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

errlHndl_t analyzeOcmbChnlFail(TARGETING::TargetHandle_t i_ocmb)
{
    // Note: This function should NOT be called anywhere within PRD itself, as
    // calling PRD's 'main' function recursively will cause problems.

    // Confirm that the input target was an OCMB_CHIP
    if ( TYPE_OCMB_CHIP != getTargetType(i_ocmb) )
    {
        PRDF_ERR("PRDF::analyzeOcmbChnlFail: Target passed in is not an OCMB. "
                 "i_ocmb huid=0x%08x", getHuid(i_ocmb));

        uint64_t userdata12 = PRDF_GET_UINT64_FROM_UINT32(getHuid(i_ocmb), 0);
        uint64_t userdata34 = PRDF_GET_UINT64_FROM_UINT32(0, 0);

        errlHndl_t o_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_PREDICTIVE, ModuleId::PRDF_MAIN,
            ReasonCode::PRDF_DETECTED_FAIL_SOFTWARE, userdata12, userdata34);

        o_errl->addProcedureCallout(HWAS::EPUB_PRC_LVL_SUPP,
                                    HWAS::SRCI_PRIORITY_HIGH);

        o_errl->collectTrace(PRDF_COMP_NAME, 512);

        return o_errl;
    }

    AttnData data = AttnData(i_ocmb, ATTENTION_VALUE_TYPE::UNIT_CS);
    AttnList list;
    list.push_back(data);

    return PRDF::main(ATTENTION_VALUE_TYPE::UNIT_CS, list);
}

#endif

//------------------------------------------------------------------------------

} // end namespace PRDF

