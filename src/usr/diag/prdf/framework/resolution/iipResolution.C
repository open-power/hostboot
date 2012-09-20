/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/resolution/iipResolution.C $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1996,2012              */
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
#include <iipglobl.h>
//#include <iipCalloutMap.h>
#include <iipCalloutResolution.h>
#include <iipstep.h>
#include <iipScanCommRegisterChip.h>
#include <iipCaptureData.h>
#include <iipServiceDataCollector.h>
#include <iipErrorRegister.h>
#include <iipEregResolution.h>
#include <iipsdbug.h>
#include <iipResolutionList.h>
//#include <iipThresholdResolution.h>
#include <iipCallAttnResolution.h>
#include <iipTerminateResolution.h>
#include <iipAnalyzeChipResolution.h>
#include <xspprdTryResolution.h>
//#include <prdfResetThresholdResolution.H>
//#include <prdfIntervalThresholdResolution.H>
#include <iipchip.h>
#include <prdfCalloutConnected.H>
#include <prdfAnalyzeConnected.H>
#include <prdfPlatServices.H>

#undef iipResolution_C

using namespace PRDF;

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

int32_t EregResolution::Resolve(STEP_CODE_DATA_STRUCT & data)
{
    int32_t rc = PRD_INTERNAL_CODE_ERROR;
    if(errorRegister != NULL)
    {
        rc = errorRegister->Analyze(data);
    }
    return rc;
}


//---------------------------------------------------------------------
// CalloutResolution Member Function Specifications
// using MruValues (xspiiCallout.h)
//---------------------------------------------------------------------

int32_t CalloutResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    error.service_data->SetCallout(xMruCallout,xPriority);
    return(SUCCESS);
}

//--------------------------------------------------------------------
// ResolutionList Member Functions
//--------------------------------------------------------------------

int32_t ResolutionList::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    int32_t rc = SUCCESS;
    for(std::vector<void *>::iterator iter = resolutionList.begin();
        iter != resolutionList.end();
        ++iter)
    {
        Resolution * r = (Resolution *) *iter;
        rc = r->Resolve(error);
        if(rc != SUCCESS) break;
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
int32_t CallAttnResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    int32_t rc = NO_DOMAINS_AT_ATTENTION;
    SYSTEM_DEBUG_CLASS systemDebug;

    ErrorSignature * signature = error.service_data->GetErrorSignature();
    signature->clear();
    signature->setChipId(0xffffffff);

    systemDebug.CalloutThoseAtAttention(error);

    signature->setErrCode((uint16_t)NO_PRD_ANALYSIS);

    return(rc);
}

// ********************************************************************

int32_t TerminateResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    error.service_data->SetTerminate();
    return(SUCCESS);
}

// ********************************************************************

int32_t AnalyzeChipResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    // mk442956 a
    return xChip.Analyze(error,error.service_data->GetCauseAttentionType());
}

// ********************************************************************

int32_t TryResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    // Save the current error signature
    ErrorSignature * es = error.service_data->GetErrorSignature();
    ErrorSignature temp = *es;
    // Try the tryResolution
    int32_t rc = xTryResolution->Resolve(error);
    if ( (SUCCESS != rc) && (PRD_NO_CLEAR_FIR_BITS != rc) ) // if it didn't work
    {
        // Restore signature
        *es = temp;
        // Call the default signature
        rc = xDefaultResolution->Resolve(error);
    }
    return rc;
}

int32_t prdfCalloutConnected::Resolve(STEP_CODE_DATA_STRUCT & serviceData)
{
    using namespace TARGETING;

    TargetHandle_t l_pconnectedTarget = NULL;
    TargetHandleList l_connectedTargetList;
    l_connectedTargetList = PlatServices::getConnected( iv_psourceHandle,
                                                        iv_targetType );
    if(0xffffffff == iv_idx)
    {
        if(l_connectedTargetList.size()>0)
        {
            l_pconnectedTarget = l_connectedTargetList[0];
        }
    }
    else
    {
        for(TargetHandleList::iterator itrTarget = l_connectedTargetList.begin();
            itrTarget!= l_connectedTargetList.end();itrTarget++)
        {
            if(iv_idx == PlatServices::getTargetPosition(*itrTarget))
            {
                l_pconnectedTarget = *itrTarget ;
                break;
            }
        }
    }

    if ( l_pconnectedTarget != NULL )
    {
        serviceData.service_data->SetCallout(l_pconnectedTarget,iv_priority);
    }
    else
    {
        if(iv_altResolution != NULL)
        {
            iv_altResolution->Resolve(serviceData);
        }
        else
        {
            serviceData.service_data->SetCallout(iv_psourceHandle);
        }
    }

    return SUCCESS;
}

//--------------------------------------------------------------------
// AnalyzeConnected Member Functions
//--------------------------------------------------------------------
int32_t PrdfAnalyzeConnected::Resolve(STEP_CODE_DATA_STRUCT & serviceData)
{
    using namespace TARGETING;
    using namespace PRDF;

    CHIP_CLASS * l_connChipObj = NULL;
    TARGETING::TargetHandle_t l_pconnChipTarget = NULL;

    // Get connected list.
    TargetHandleList l_connectedTargetList = PlatServices::getConnected(
                                                            iv_psourceHandle,
                                                            iv_targetType );

    // If ID = 0xffffffff, find first valid.
    if (0xffffffff == iv_idx)
    {
        if(l_connectedTargetList.size()>0)
        {
            //First valid handle. we don't allow invalid things in list
            l_pconnChipTarget = l_connectedTargetList[0] ;
        }
    }
    // Otherwise, grab from correct index.
    else
    {
        for(TargetHandleList::iterator itrTarget = l_connectedTargetList.begin();
            itrTarget!= l_connectedTargetList.end();itrTarget++)
        {
            if(iv_idx == PlatServices::getTargetPosition(*itrTarget))
            {
                l_pconnChipTarget = *itrTarget ;
                break;

            }
        }
    }

    // If valid chip found, look up in global system container.
    if (NULL != l_pconnChipTarget)
    {
        l_connChipObj = systemPtr->GetChip(l_pconnChipTarget);
    }

    // Analyze chip.
    if (NULL != l_connChipObj)
        return l_connChipObj->Analyze( serviceData,
                            serviceData.service_data->GetCauseAttentionType() );
    else
        return PRD_UNRESOLVED_CHIP_CONNECTION;
}

//--------------------------------------------------------------------
// ResetThresholdResolution Member Functions
//--------------------------------------------------------------------

#if defined(_OBSOLITE_)
int32_t ResetThresholdResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    ++count;
    error.service_data->SetHits((uint16_t)count);
    error.service_data->SetThreshold((uint16_t)threshold);
    if((count == threshold) || (error.service_data->IsFlooding()))
    {
        error.service_data->SetThresholdMaskId(maskId);  // threshold, degraded YES
        count = 0;                                       // Reset the counter when threshold is hit
    }
    int32_t rc = SUCCESS;
    //  if(xRes != NULL) rc = xRes->Resolve(error);
    return rc;
}
//--------------------------------------------------------------------
// IntervalThresholdResolution Member Functions
//--------------------------------------------------------------------

int32_t IntervalThresholdResolution::Resolve(STEP_CODE_DATA_STRUCT & error)
{
    PrdTimer curTime = error.service_data->GetTOE();       // get timestamp (Time Of Error) from SDC;
    ++count;
    if (count == 1)                                        // The interval begins now at the first occurrence
        intervalEndTime = curTime + intervalLength;        // Project the end of interval (intervalLength is in seconds)
    else
    {
        if (curTime > intervalEndTime)                      // See if we're already past the time window
        {
            count = 1;                                      // Reset count as if it were the first
            intervalEndTime = curTime + intervalLength;     // Project the new end of interval (intervalLength is in seconds)
        }
        else if((count == threshold) || (error.service_data->IsFlooding())) // We've hit threshold within the interval
        {
            error.service_data->SetThresholdMaskId(maskId);  // threshold, degraded YES
            count = 0;                                       // Reset the counter when threshold is hit
        }
        else ;                                              // Nothing else--the count is already incremented
    }
    error.service_data->SetHits((uint16_t)count);
    error.service_data->SetThreshold((uint16_t)threshold);

    int32_t rc = SUCCESS;
    //  if(xRes != NULL) rc = xRes->Resolve(error);
    return rc;
}
#endif
