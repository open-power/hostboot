/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/iipResolution.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2013              */
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
#include <iipCalloutResolution.h>
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
#include <prdfCalloutConnected.H>
#include <prdfAnalyzeConnected.H>
#include <prdfPlatServices.H>
#undef iipResolution_C

namespace PRDF
{

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

int32_t EregResolution::Resolve( STEP_CODE_DATA_STRUCT & io_data )
{
    int32_t rc = PRD_INTERNAL_CODE_ERROR;
    if( errorRegister != NULL )
    {
        rc = errorRegister->Analyze( io_data );
    }
    return rc;
}


//---------------------------------------------------------------------
// CalloutResolution Member Function Specifications
// using MruValues (xspiiCallout.h)
//---------------------------------------------------------------------

int32_t CalloutResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
{
    /*
    This resolution is only needed when we callout self.So during RuleChip
    creation,we create CalloutResolution passing NULL as target value.In Resolve
    function when we need to update SDC with target to be called out we get it
    from Service Data Collector.It is because target currently under analysis is
    the target that needs to be called out here.By instantiating Callout
    resolution with just priority info and NULL target , we are able to reduce
    CalloutResolution objects to one per priority instead of one per target per
    priority.So,this reduction in number of resolution objects shall eventually
    reduce memory utilization.
    */

    if ( PRDcalloutData::TYPE_TARGET == xMruCallout.getType() )
    {
        PRDcallout l_targetCallout( ServiceDataCollector::getTargetAnalyzed() );
        io_serviceData.service_data->SetCallout( l_targetCallout, xPriority );
    }
    else
    {
        io_serviceData.service_data->SetCallout( xMruCallout,xPriority );
    }

    return(SUCCESS);
}

//--------------------------------------------------------------------
// ResolutionList Member Functions
//--------------------------------------------------------------------

int32_t ResolutionList::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
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
// ThresholdResolution Member Functions
//--------------------------------------------------------------------

//int32_t ThresholdResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
//{
//  ++count;
//  error.service_data->SetHits((uint16_t)count);
//  error.service_data->SetThreshold((uint16_t)threshold);
//  if((count >= threshold) || (error.service_data->IsFlooding()))
//  {
//    error.service_data->SetThresholdMaskId(maskId);  // threshold, degraded YES
//  }
//  int32_t rc = SUCCESS;
//  if(xRes != NULL) rc = xRes->Resolve(error);
//  return rc;
//}

//--------------------------------------------------------------------
// Call all chips raising attention as reported by sp sysdebug area
//--------------------------------------------------------------------
int32_t CallAttnResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
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

int32_t TerminateResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
{
    io_serviceData.service_data->SetTerminate();
    return(SUCCESS);
}

// ********************************************************************

int32_t AnalyzeChipResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
{
    // mk442956 a
    return xChip.Analyze( io_serviceData,
                          io_serviceData.service_data->GetCauseAttentionType() );
}

// ********************************************************************

int32_t TryResolution::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
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

int32_t CalloutConnected::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
{
    using namespace TARGETING;

    TargetHandle_t l_pconnectedTarget = NULL;
    TARGETING::TargetHandle_t l_psourceTarget =
                            ServiceDataCollector::getTargetAnalyzed( ) ;
    TargetHandleList l_connectedTargetList;
    l_connectedTargetList = PlatServices::getConnected( l_psourceTarget,
                                                        iv_targetType );
    if( 0xffffffff == iv_idx )
    {
        if( l_connectedTargetList.size()>0 )
        {
            l_pconnectedTarget = l_connectedTargetList[0];
        }
    }
    else
    {
        for( TargetHandleList::iterator itrTarget =
            l_connectedTargetList.begin();
            itrTarget!= l_connectedTargetList.end();itrTarget++ )
        {
            if( iv_idx == PlatServices::getTargetPosition( *itrTarget ) )
            {
                l_pconnectedTarget = *itrTarget ;
                break;
            }
        }
    }

    if ( l_pconnectedTarget != NULL )
    {
        io_serviceData.service_data->SetCallout( l_pconnectedTarget,
                                                 iv_priority );
    }
    else
    {
        if(iv_altResolution != NULL)
        {
            iv_altResolution->Resolve( io_serviceData );
        }
        else
        {
            io_serviceData.service_data->SetCallout( l_psourceTarget );
        }
    }

    return SUCCESS;
}

//--------------------------------------------------------------------
// AnalyzeConnected Member Functions
//--------------------------------------------------------------------
int32_t AnalyzeConnected::Resolve( STEP_CODE_DATA_STRUCT & io_serviceData )
{
    using namespace TARGETING;

    CHIP_CLASS * l_connChipObj = NULL;
    TARGETING::TargetHandle_t l_pconnChipTarget = NULL;
    TARGETING::TargetHandle_t l_psourceHandle =
                            ServiceDataCollector::getTargetAnalyzed( ) ;
    // Get connected list.
    TargetHandleList l_connectedTargetList = PlatServices::getConnected(
                                                            l_psourceHandle,
                                                            iv_targetType );

    // If ID = 0xffffffff, find first valid.
    if ( 0xffffffff == iv_idx )
    {
        if( l_connectedTargetList.size()>0 )
        {
            //First valid handle. we don't allow invalid things in list
            l_pconnChipTarget = l_connectedTargetList[0] ;
        }
    }
    // Otherwise, grab from correct index.
    else
    {
        for( TargetHandleList::iterator itrTarget =
            l_connectedTargetList.begin();
            itrTarget!= l_connectedTargetList.end();itrTarget++ )
        {
            if( iv_idx == PlatServices::getTargetPosition( *itrTarget ) )
            {
                l_pconnChipTarget = *itrTarget ;
                break;

            }
        }
    }

    // If valid chip found, look up in global system container.
    if ( NULL != l_pconnChipTarget )
    {
        l_connChipObj = systemPtr->GetChip( l_pconnChipTarget );
    }

    // Analyze chip.
    if (NULL != l_connChipObj)
        return l_connChipObj->Analyze( io_serviceData,
                        io_serviceData.service_data->GetCauseAttentionType() );
    else
        return PRD_UNRESOLVED_CHIP_CONNECTION;
}

} // end namespace PRDF

