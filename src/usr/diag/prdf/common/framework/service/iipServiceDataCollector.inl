/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/iipServiceDataCollector.inl $ */
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

namespace PRDF
{

inline
ServiceDataCollector::ServiceDataCollector() :
#ifndef __HOSTBOOT_MODULE
    ivDumpRequestContent(CONTENT_HW),
#endif
    error_signature(),
    captureData(),
    iv_traceArrayData(),
    xMruList(),
    maskId(0),
    attentionType(INVALID_ATTENTION_TYPE),
    flags(TRACKIT | LOGIT),
    hitCount(0),
    threshold(0),
    analysisFlags(0),
    startingPoint(nullptr),
    ivpDumpRequestChipHandle(nullptr),
    causeAttentionType(INVALID_ATTENTION_TYPE)
{
    PlatServices::getCurrentTime(ivCurrentEventTime);
}

// ---------------------------------------------------------------

inline
void ServiceDataCollector::setPrimaryAttnType( ATTENTION_TYPE attention )
{
    attentionType = attention;
    if( MACHINE_CHECK == attention )
    {
        setFlag( SERVICE_CALL );
    }
}

// ---------------------------------------------------------------

inline
void ServiceDataCollector::setSecondaryAttnType(ATTENTION_TYPE attention)
{
  causeAttentionType = attention;
}

// ---------------------------------------------------------------

inline
void ServiceDataCollector::SetThresholdMaskId(uint32_t mask_id)
{
    setFlag( AT_THRESHOLD );
    setFlag( DEGRADED     );
    setFlag( SERVICE_CALL );

    maskId = mask_id;        // Set MaskId
}

// ---------------------------------------------------------------

inline
uint32_t ServiceDataCollector::GetThresholdMaskId(void) const
{ return maskId; }

// ---------------------------------------------------------------

inline void ServiceDataCollector::SetTerminate(void)
{
    setFlag( TERMINATE    );
    setFlag( SERVICE_CALL );
}

// ---------------------------------------------------------------

// dg12d  removed previously commented-out memory steer stuff

// ---------------------------------------------------------------

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

} // end namespace PRDF
