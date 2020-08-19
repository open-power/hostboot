/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolution.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

// Module Description **************************************************
//
// Description: PRD resolution definition
//
// End Module Description **********************************************

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define iipResolution_C

#include <iipconst.h>
#include <CcAutoDeletePointer.h>
#include <iipSystem.h>
#include <prdfGlobal.H>
//#include <iipCalloutMap.h>
#include <iipstep.h>
#include <iipCaptureData.h>
#include <iipServiceDataCollector.h>
#include <iipErrorRegister.h>
#include <iipEregResolution.h>
#include <iipsdbug.h>
#include <iipResolutionList.h>
#include <iipCallAttnResolution.h>
#include <iipTerminateResolution.h>
#include <iipAnalyzeChipResolution.h>
#include <xspprdTryResolution.h>
#include <iipchip.h>
#include <prdfCalloutGard.H>
#include <prdfCalloutConnectedGard.H>
#include <prdfAnalyzeConnected.H>
#include <prdfPlatServices.H>
#undef iipResolution_C

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Macros
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Internal Function Prototypes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//---------------------------------------------------------------------
// Resolution Member Function Specifications
//---------------------------------------------------------------------
Resolution::~Resolution() {}

//---------------------------------------------------------------------
// EregResolution Member Function Specifications
//---------------------------------------------------------------------

int32_t EregResolution::Resolve( STEP_CODE_DATA_STRUCT & io_data,
                                 bool i_default )
{
    int32_t rc = PRD_INTERNAL_CODE_ERROR;
    if( errorRegister != nullptr )
    {
        rc = errorRegister->Analyze( io_data );
    }
    return rc;
}

//--------------------------------------------------------------------
// CalloutGardResolution Member Functions
//--------------------------------------------------------------------
int32_t CalloutGardResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData,
                                        bool i_default )
{
    /*
    This resolution is only needed when we callout self. So, during RuleChip
    creation, we create CalloutGardResolution passing nullptr as target value. In
    Resolve function when we need to update SDC with target to be called out, we
    get it from Service Data Collector. It is because target currently under
    analysis is the target that needs to be called out here. By instantiating
    Callout resolution with just priority info and nullptr target, we are able to
    reduce CalloutGardResolution objects to one per priority instead of one per
    target per priority. So, this reduction in number of resolution objects
    shall eventually reduce memory utilization.
    */

    if ( PRDcalloutData::TYPE_TARGET == iv_callout.getType() )
    {
        PRDcallout l_targetCallout( ServiceDataCollector::getTargetAnalyzed() );
        io_serviceData.service_data->SetCallout( l_targetCallout,
                                                 iv_calloutPriority,
                                                 iv_gardState,
                                                 i_default );
    }
    else
    {
        io_serviceData.service_data->SetCallout( iv_callout, iv_calloutPriority,
                                                 iv_gardState );
    }

    return SUCCESS;
}

//--------------------------------------------------------------------
// ResolutionList Member Functions
//--------------------------------------------------------------------

int32_t ResolutionList::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData,
                                 bool i_default )
{
    int32_t rc = SUCCESS;
    for(std::vector<void *>::iterator iter = resolutionList.begin();
        iter != resolutionList.end();
        ++iter)
    {
        Resolution * r = (Resolution *) *iter;
        rc = r->Resolve( io_serviceData );
        if( rc != SUCCESS ) break;
    }
    return(rc);
}

//--------------------------------------------------------------------
// Call all chips raising attention as reported by sp sysdebug area
//--------------------------------------------------------------------
int32_t CallAttnResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData,
                                     bool i_default )
{
    int32_t rc = NO_DOMAINS_AT_ATTENTION;
    SYSTEM_DEBUG_CLASS systemDebug;

    ErrorSignature * signature =
                        io_serviceData.service_data->GetErrorSignature();
    signature->clear();
    signature->setChipId(0xffffffff);

    systemDebug.CalloutThoseAtAttention( io_serviceData );

    signature->setErrCode((uint16_t)NO_PRD_ANALYSIS);

    return(rc);
}

// ********************************************************************

int32_t TerminateResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData,
                                      bool i_default )
{
    io_serviceData.service_data->SetTerminate();
    return(SUCCESS);
}

// ********************************************************************

int32_t AnalyzeChipResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData,
                                        bool i_default )
{
    // mk442956 a
    return xChip.Analyze( io_serviceData,
                          io_serviceData.service_data->getSecondaryAttnType() );
}

// ********************************************************************

int32_t TryResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData,
                                bool i_default )
{
    // Save the current error signature
    ErrorSignature * es = io_serviceData.service_data->GetErrorSignature();
    ErrorSignature temp = *es;
    // Try the tryResolution
    int32_t rc = xTryResolution->Resolve( io_serviceData  );
    if ( (SUCCESS != rc) && (PRD_NO_CLEAR_FIR_BITS != rc) ) // if it didn't work
    {
        // Restore signature
        *es = temp;
        // Call the default signature
        rc = xDefaultResolution->Resolve( io_serviceData );
    }
    return rc;
}

//--------------------------------------------------------------------
// CalloutConnectedGard Member Functions
//--------------------------------------------------------------------
int32_t CalloutConnectedGard::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData,
                                       bool i_default )
{
    TargetHandle_t sourceTrgt = ServiceDataCollector::getTargetAnalyzed();
    TargetHandle_t connTrgt   = nullptr;

    if ( TYPE_NA == iv_peerConnType )
    {
        if ( INVALID_INDEX == iv_idx )
        {
            connTrgt = getConnectedParent( sourceTrgt, iv_targetType );
        }
        else
        {
            connTrgt = getConnectedChild( sourceTrgt, iv_targetType, iv_idx );
        }
    }
    else
    {
        TargetHandle_t srcEndPoint
                    = getConnectedChild( sourceTrgt, iv_peerConnType, iv_idx );

        if ( nullptr != srcEndPoint )
            connTrgt = getConnectedPeerTarget( srcEndPoint );
    }

    if ( nullptr != connTrgt )
    {
        io_serviceData.service_data->SetCallout( connTrgt,
                                                 iv_priority,
                                                 iv_gardState );
    }
    else
    {
        if ( nullptr != iv_altResolution )
        {
            iv_altResolution->Resolve( io_serviceData );
        }
        else
        {
            PRDF_ERR( "[CalloutConnectedGard::Resolve] No connected chip found:"
                      " sourceTrgt=0x%08x, iv_peerConnType=0x%x",
                        getHuid(sourceTrgt), iv_peerConnType );

            io_serviceData.service_data->SetCallout( sourceTrgt,
                                                     MRU_MED,
                                                     iv_gardState );
        }
    }

    return SUCCESS;
}

//--------------------------------------------------------------------
// AnalyzeConnected Member Functions
//--------------------------------------------------------------------
int32_t AnalyzeConnected::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData,
                                   bool i_default )
{
    TargetHandle_t sourceTrgt = ServiceDataCollector::getTargetAnalyzed();
    TargetHandle_t connTrgt   = nullptr;

    if ( INVALID_INDEX == iv_idx )
    {
        connTrgt = getConnectedParent( sourceTrgt, iv_targetType );
    }
    else
    {
        connTrgt = getConnectedChild( sourceTrgt, iv_targetType, iv_idx );
    }

    // If valid chip found, look up in global system container.
    CHIP_CLASS * connChip = nullptr;
    if ( nullptr != connTrgt )
    {
        connChip = systemPtr->GetChip( connTrgt );
    }

    // Analyze chip.
    if ( nullptr != connChip )
    {
        return connChip->Analyze( io_serviceData,
                        io_serviceData.service_data->getSecondaryAttnType() );
    }
    else
    {
        // Add a default callout for checkstops
        if ( CHECK_STOP == io_serviceData.service_data->getPrimaryAttnType() )
        {
            PRDcallout l_targetCallout(
                ServiceDataCollector::getTargetAnalyzed() );
            io_serviceData.service_data->SetCallout( l_targetCallout,
                                                     MRU_MED, GARD, true );
        }
        return PRD_UNRESOLVED_CHIP_CONNECTION;
    }
}

} // end namespace PRDF

