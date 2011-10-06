//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/fapi/fapiErrorInfo.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
 */

#include <fapiErrorInfo.H>
#include <string.h>

namespace fapi
{

//******************************************************************************
// ErrorInfoFfdc Constructor
//******************************************************************************
ErrorInfoFfdc::ErrorInfoFfdc(const void * i_pFfdc,
                             const uint32_t i_size)
: iv_size(i_size)
{
    iv_pFfdc = new uint8_t[i_size];
    memcpy(iv_pFfdc, i_pFfdc, i_size);
}

//******************************************************************************
// ErrorInfoFfdc Copy Constructor
//******************************************************************************
ErrorInfoFfdc::ErrorInfoFfdc(const ErrorInfoFfdc & i_right)
: iv_size(i_right.iv_size)
{
    iv_pFfdc = new uint8_t[i_right.iv_size];
    memcpy(iv_pFfdc, i_right.iv_pFfdc, i_right.iv_size);
}

//******************************************************************************
// ErrorInfoFfdc Destructor
//******************************************************************************
ErrorInfoFfdc::~ErrorInfoFfdc()
{
    delete [] iv_pFfdc;
    iv_pFfdc = NULL;
}

//******************************************************************************
// ErrorInfoFfdc Assignment Operator
//******************************************************************************
ErrorInfoFfdc & ErrorInfoFfdc::operator=(const ErrorInfoFfdc & i_right)
{
    delete [] iv_pFfdc;
    iv_pFfdc = new uint8_t[i_right.iv_size];
    memcpy(iv_pFfdc, i_right.iv_pFfdc, i_right.iv_size);
    iv_size = i_right.iv_size;
    return *this;
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
// ErrorInfoCallout Constructor
//******************************************************************************
ErrorInfoCallout::ErrorInfoCallout(const Target & i_target,
                                   const CalloutPriority i_priority)
: iv_target(i_target),
  iv_priority(i_priority)
{

}

//******************************************************************************
// ErrorInfoDeconfig Constructor
//******************************************************************************
ErrorInfoDeconfig::ErrorInfoDeconfig(const Target & i_target)
: iv_target(i_target)
{

}

//******************************************************************************
// ErrorInfoGard Constructor
//******************************************************************************
ErrorInfoGard::ErrorInfoGard(const Target & i_target)
: iv_target(i_target)
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

    for (ErrorInfo::ErrorInfoCalloutItr_t l_itr = iv_callouts.begin();
         l_itr != iv_callouts.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }

    for (ErrorInfo::ErrorInfoDeconfigItr_t l_itr = iv_deconfigs.begin();
         l_itr != iv_deconfigs.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }

    for (ErrorInfo::ErrorInfoGardItr_t l_itr = iv_gards.begin();
         l_itr != iv_gards.end(); ++l_itr)
    {
        delete (*l_itr);
        (*l_itr) = NULL;
    }
}

}
