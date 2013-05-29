/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/fapi/fapiErrorInfo.C $                           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
// ErrorInfoProcedureCallout Constructor
//******************************************************************************
ErrorInfoProcedureCallout::ErrorInfoProcedureCallout(
    const ProcedureCallouts::ProcedureCallout i_procedure,
    const CalloutPriorities::CalloutPriority i_calloutPriority)
: iv_procedure(i_procedure), iv_calloutPriority(i_calloutPriority)
{

}

//******************************************************************************
// ErrorInfoProcedureCallout Constructor
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
    const Target & i_parentChip,
    const TargetType i_childType,
    const bool i_callout,
    const bool i_deconfigure,
    const bool i_gard,
    const CalloutPriorities::CalloutPriority i_priority)
: iv_parentChip(i_parentChip), iv_childType(i_childType), iv_callout(i_callout),
  iv_calloutPriority(i_priority), iv_deconfigure(i_deconfigure), iv_gard(i_gard)
{

}

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

    for (ErrorInfo::ErrorInfoProcedureCalloutItr_t l_itr =
             iv_procedureCallouts.begin();
         l_itr != iv_procedureCallouts.end(); ++l_itr)
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
