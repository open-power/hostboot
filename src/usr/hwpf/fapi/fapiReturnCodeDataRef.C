/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/fapi/fapiReturnCodeDataRef.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
// $Id: fapiReturnCodeDataRef.C,v 1.8 2013/10/15 13:13:37 dcrowell Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/hwpf/working/fapi/fapiReturnCodeDataRef.C,v $

/**
 *  @file fapiReturnCodeDataRef.C
 *
 *  @brief Implements the FAPI part of the ReturnCodeDataRef class.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     04/13/2011  Created.
 *                          camvanng	05/31/2011  Added debug traces
 *                          mjjones     06/30/2011  Added #include
 *                          mjjones     07/05/2011  Removed const from data
 *                          mjjones     07/25/2011  Added support for FFDC
 *                          mjjones     09/22/2011  Added support for Error Info
 *                          mjjones     07/11/2012  Removed some tracing
 */

#include <string.h>
#include <fapiReturnCodeDataRef.H>
#include <fapiUtil.H>
#include <fapiPlatTrace.H>

namespace fapi
{

//******************************************************************************
// Constructor
//******************************************************************************
ReturnCodeDataRef::ReturnCodeDataRef()
: iv_refCount(1),
  iv_pPlatData(NULL),
  iv_pErrorInfo(NULL)
{

}

//******************************************************************************
// Destructor
//******************************************************************************
ReturnCodeDataRef::~ReturnCodeDataRef()
{
    if (iv_refCount != 0)
    {
        FAPI_ERR("ReturnCodeDataRef. Bug. Destruct with refcount: %d",
                 iv_refCount);
        fapiAssert(false);
    }

    deletePlatData();
    delete iv_pErrorInfo;
    iv_pErrorInfo = NULL;
}

//******************************************************************************
// incRefCount function
//******************************************************************************
void ReturnCodeDataRef::incRefCount()
{
    iv_refCount++;
}

//******************************************************************************
// decRefCountCheckZero function
//******************************************************************************
bool ReturnCodeDataRef::decRefCountCheckZero()
{
    if (iv_refCount == 0)
    {
        FAPI_ERR("ReturnCodeDataRef. Bug. Dec with zero refcount");
        fapiAssert(false);
    }
    else
    {
        iv_refCount--;
    }
    return (iv_refCount == 0);
}

//******************************************************************************
// setPlatData function
//******************************************************************************
void ReturnCodeDataRef::setPlatData(void * i_pPlatData)
{
    // Delete any current PlatData
    if (iv_pPlatData)
    {
        FAPI_ERR("ReturnCodeDataRef. setPlatData when existing data");
        deletePlatData();
    }

    iv_pPlatData = i_pPlatData;
}

//******************************************************************************
// getPlatData function
//******************************************************************************
void * ReturnCodeDataRef::getPlatData() const
{
    return iv_pPlatData;
}

//******************************************************************************
// releasePlatData function
//******************************************************************************
void * ReturnCodeDataRef::releasePlatData()
{
    void * l_pPlatData = iv_pPlatData;
    iv_pPlatData = NULL;
    return l_pPlatData;
}

//******************************************************************************
// getErrorInfo function
//******************************************************************************
ErrorInfo * ReturnCodeDataRef::getErrorInfo()
{
    return iv_pErrorInfo;
}

//******************************************************************************
// getCreateErrorInfo function
//******************************************************************************
ErrorInfo & ReturnCodeDataRef::getCreateErrorInfo()
{
    if (iv_pErrorInfo == NULL)
    {
        iv_pErrorInfo = new ErrorInfo();
    }

    return *iv_pErrorInfo;
}

//******************************************************************************
// Overload Operator new function
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void * ReturnCodeDataRef::operator new(size_t i_sz)
{
    return fapiMalloc(i_sz);
}
#endif

//******************************************************************************
// Overload Operator delete function
//******************************************************************************
#ifdef FAPI_CUSTOM_MALLOC
void ReturnCodeDataRef::operator delete(void * i_ptr)
{
    fapiFree(i_ptr);
}
#endif

}
