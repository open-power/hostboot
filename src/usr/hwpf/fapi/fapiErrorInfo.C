/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/fapi/fapiErrorInfo.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
// $Id: fapiErrorInfo.C,v 1.13 2015/01/16 11:27:43 sangeet2 Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiErrorInfo.C,v $

/**
 *  @file fapiErrorInfo.C
 *
 *  @brief Implements the ErrorInfo structs and classes
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     08/05/2011  Created
 *                          mjjones     08/24/2011  Added ErrorInfoGard.
 *                          mjjones     09/22/2011  Major updates
 *                          mjjones     03/16/2012  Add FfdcType. Remove copy
 *                                                  ctor and assignment operator
 *                          mjjones     08/14/2012  Merge Callout/Deconfig/Gard
 *                                                  structures into one
 *                          mjjones     09/19/2012  Replace FFDC type with ID
 *                          mjjones     03/22/2013  Support Procedure Callouts
 *                          mjjones     05/20/2013  Support Bus Callouts
 *                          mjjones     06/24/2013  Support Children CDGs
 *                          mjjones     08/26/2013  Support HW Callouts
 *                          rjknight    09/24/2013  Support dimm callouts
 *                                                  based on mba parent target
 *                          whs         03/11/2014  Add FW traces to error logs
 *                          sangeet2    01/16/2015  Modify ErrorInfoHwCallout
 */

#include <fapiErrorInfo.H>
#include <string.h>
#include <fapiUtil.H>

namespace fapi
{

//******************************************************************************
// ErrorInfoFfdc Constructor
//******************************************************************************
ErrorInfoFfdc::ErrorInfoFfdc(const uint32_t i_ffdcId,
                             const void * i_pFfdc,
                             const uint32_t i_size)
: iv_ffdcId(i_ffdcId), iv_size(i_size)
{
    iv_pFfdc = reinterpret_cast<uint8_t *>(fapiMalloc(i_size));
    if(iv_pFfdc != NULL)
    {
        memcpy(iv_pFfdc, i_pFfdc, i_size);
    }
    else
    {
        FAPI_ERR("ErrorInfoFfdc - could not allocate storage");
        iv_size = 0;
    }
}

//******************************************************************************
// ErrorInfoFfdc Destructor
//******************************************************************************
ErrorInfoFfdc::~ErrorInfoFfdc()
{
    fapiFree(iv_pFfdc);
    iv_pFfdc = NULL;
}

//******************************************************************************
// ErrorInfoFfdc getData function
//******************************************************************************
const void * ErrorInfoFfdc::getData(uint32_t & o_size) const
{
    o_size = iv_size;
    return iv_pFfdc;
}

//******************************************************************************
// ErrorInfoFfdc new Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void * ErrorInfoFfdc::operator new(size_t i_sz)
{
    return fapiMalloc(i_sz);
}
#endif

//******************************************************************************
// ErrorInfoFfdc delete Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void ErrorInfoFfdc::operator delete(void * i_ptr)
{
    fapiFree(i_ptr);
}
#endif

//******************************************************************************
// ErrorInfoHwCallout Constructor
//******************************************************************************
ErrorInfoHwCallout::ErrorInfoHwCallout(
    const HwCallouts::HwCallout i_hw,
    const CalloutPriorities::CalloutPriority i_calloutPriority,
    const Target & i_refTarget,
    const targetPos_t i_position)
: iv_hw(i_hw), iv_calloutPriority(i_calloutPriority), iv_refTarget(i_refTarget),
  iv_position(i_position)
{

}

//******************************************************************************
// ErrorInfoHwCallout new Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void * ErrorInfoHwCallout::operator new(size_t i_sz)
{
    return fapiMalloc(i_sz);
}
#endif

//******************************************************************************
// ErrorInfoProcedureCallout delete Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void ErrorInfoHwCallout::operator delete(void * i_ptr)
{
    fapiFree(i_ptr);
}
#endif

//******************************************************************************
// ErrorInfoProcedureCallout Constructor
//******************************************************************************
ErrorInfoProcedureCallout::ErrorInfoProcedureCallout(
    const ProcedureCallouts::ProcedureCallout i_procedure,
    const CalloutPriorities::CalloutPriority i_calloutPriority)
: iv_procedure(i_procedure), iv_calloutPriority(i_calloutPriority)
{

}

//******************************************************************************
// ErrorInfoProcedureCallout new Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void * ErrorInfoProcedureCallout::operator new(size_t i_sz)
{
    return fapiMalloc(i_sz);
}
#endif

//******************************************************************************
// ErrorInfoProcedureCallout delete Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void ErrorInfoProcedureCallout::operator delete(void * i_ptr)
{
    fapiFree(i_ptr);
}
#endif

//******************************************************************************
// ErrorInfoBusCallout Constructor
//******************************************************************************
ErrorInfoBusCallout::ErrorInfoBusCallout(
    const Target & i_target1,
    const Target & i_target2,
    const CalloutPriorities::CalloutPriority i_calloutPriority)
: iv_target1(i_target1), iv_target2(i_target2),
  iv_calloutPriority(i_calloutPriority)
{
}

//******************************************************************************
// ErrorInfoBusCallout new Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void * ErrorInfoBusCallout::operator new(size_t i_sz)
{
    return fapiMalloc(i_sz);
}
#endif

//******************************************************************************
// ErrorInfoBusCallout delete Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void ErrorInfoBusCallout::operator delete(void * i_ptr)
{
    fapiFree(i_ptr);
}
#endif

//******************************************************************************
// ErrorInfoCDG Constructor
//******************************************************************************
ErrorInfoCDG::ErrorInfoCDG(const Target & i_target,
                           const bool i_callout,
                           const bool i_deconfigure,
                           const bool i_gard,
                           const CalloutPriorities::CalloutPriority i_priority)
: iv_target(i_target), iv_callout(i_callout), iv_calloutPriority(i_priority),
  iv_deconfigure(i_deconfigure), iv_gard(i_gard)
{

}

//******************************************************************************
// ErrorInfoCDG new Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void * ErrorInfoCDG::operator new(size_t i_sz)
{
    return fapiMalloc(i_sz);
}
#endif

//******************************************************************************
// ErrorInfoCDG delete Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void ErrorInfoCDG::operator delete(void * i_ptr)
{
    fapiFree(i_ptr);
}
#endif

//******************************************************************************
// ErrorInfoChildrenCDG Constructor
//******************************************************************************
ErrorInfoChildrenCDG::ErrorInfoChildrenCDG(
    const Target & i_parent,
    const TargetType i_childType,
    const bool i_callout,
    const bool i_deconfigure,
    const bool i_gard,
    const CalloutPriorities::CalloutPriority i_priority,
    const uint8_t i_childPort, const uint8_t i_childNum )
: iv_parent(i_parent), iv_childType(i_childType), iv_callout(i_callout),
  iv_calloutPriority(i_priority), iv_deconfigure(i_deconfigure),
  iv_gard(i_gard), iv_childPort(i_childPort), iv_childNumber(i_childNum)
{

}

//******************************************************************************
// ErrorInfoCollectTrace Constructor
//******************************************************************************
ErrorInfoCollectTrace::ErrorInfoCollectTrace(
    const CollectTraces::CollectTrace i_traceId)
: iv_eiTraceId(i_traceId)
{
}

//******************************************************************************
// ErrorInfoChildrenCDG new Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void * ErrorInfoChildrenCDG::operator new(size_t i_sz)
{
    return fapiMalloc(i_sz);
}
#endif

//******************************************************************************
// ErrorInfoCDG delete Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void ErrorInfoChildrenCDG::operator delete(void * i_ptr)
{
    fapiFree(i_ptr);
}
#endif

//******************************************************************************
// ErrorInfo Destructor
//******************************************************************************
ErrorInfo::~ErrorInfo()
{
    for (ErrorInfo::ErrorInfoFfdcItr_t l_itr = iv_ffdcs.begin();
         l_itr != iv_ffdcs.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }

    for (ErrorInfoHwCalloutItr_t l_itr = iv_hwCallouts.begin();
         l_itr != iv_hwCallouts.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }

    for (ErrorInfo::ErrorInfoProcedureCalloutItr_t l_itr =
             iv_procedureCallouts.begin();
         l_itr != iv_procedureCallouts.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }

    for (ErrorInfo::ErrorInfoBusCalloutItr_t l_itr =
             iv_busCallouts.begin();
         l_itr != iv_busCallouts.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }

    for (ErrorInfo::ErrorInfoCDGItr_t l_itr = iv_CDGs.begin();
         l_itr != iv_CDGs.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }

    for (ErrorInfo::ErrorInfoChildrenCDGItr_t l_itr = iv_childrenCDGs.begin();
         l_itr != iv_childrenCDGs.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }
}

//******************************************************************************
// ErrorInfo new Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void * ErrorInfo::operator new(size_t i_sz)
{
    return fapiMalloc(i_sz);
}
#endif

//******************************************************************************
// ErrorInfo delete Operator Overload
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void ErrorInfo::operator delete(void * i_ptr)
{
    fapiFree(i_ptr);
}
#endif

}
