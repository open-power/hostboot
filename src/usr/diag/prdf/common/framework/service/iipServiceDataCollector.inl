/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/iipServiceDataCollector.inl $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 1998,2013              */
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

namespace PRDF
{

inline
ServiceDataCollector::ServiceDataCollector() :
#ifndef __HOSTBOOT_MODULE
    ivDumpRequestContent(CONTENT_HW),
#endif
    error_signature(),
    captureData(),
    xMruList(),
    maskId(0),
    attentionType(INVALID_ATTENTION_TYPE),
    flags(TRACKIT | LOGIT),
    hitCount(0),
    threshold(0),
    analysisFlags(0),
    startingPoint(NULL),
    errorType(GardAction::NoGard),
    ivpDumpRequestChipHandle(NULL),
    causeAttentionType(INVALID_ATTENTION_TYPE),
    ivpThermalChipHandle(NULL)
{
    PlatServices::getCurrentTime(ivCurrentEventTime);
}

// ---------------------------------------------------------------

inline
void ServiceDataCollector::SetAttentionType( ATTENTION_TYPE attention )
{
  attentionType = attention;
  if(attention == MACHINE_CHECK)
  {
      flags |= SERVICE_CALL;
      errorType = GardAction::Fatal;
  } else
  {
      errorType = GardAction::Predictive;
  }
}

// ---------------------------------------------------------------

inline
void ServiceDataCollector::SetCauseAttentionType(ATTENTION_TYPE attention)
{
  causeAttentionType = attention;
}

// ---------------------------------------------------------------

inline
void ServiceDataCollector::SetThresholdMaskId(uint32_t mask_id)
{
  flags |= AT_THRESHOLD | DEGRADED | SERVICE_CALL;
  maskId = mask_id;        // Set MaskId
}

// ---------------------------------------------------------------

inline
uint32_t ServiceDataCollector::GetThresholdMaskId(void) const
{ return maskId; }

// ---------------------------------------------------------------

inline void ServiceDataCollector::SetTerminate(void)
{ flags |= TERMINATE | SERVICE_CALL; }

// ---------------------------------------------------------------

// dg12d  removed previously commented-out memory steer stuff

// ---------------------------------------------------------------

inline
GardAction::ErrorType ServiceDataCollector::QueryGard(void)
{
  if (IsServiceCall())
  {
    return errorType;
  }
  return GardAction::NoGard;
}

// dg12a -moved here from *.C --------------------------------------

inline
void ServiceDataCollector::ClearCallouts(void)
{
  xMruList.erase(xMruList.begin(),xMruList.end());  // dg04
}
// dg12a -moved here from *.C --------------------------------------


inline
void ServiceDataCollector::ClearSignatureList(void)
{
  iv_SignatureList.erase(iv_SignatureList.begin(),iv_SignatureList.end());  // jl00
}


inline
SDC_MRU_LIST & ServiceDataCollector::GetMruList(void)
{
  return xMruList;
}

inline
PRDF_SIGNATURES & ServiceDataCollector::GetSignatureList(void)
{
  return iv_SignatureList;
}


} // end namespace PRDF
