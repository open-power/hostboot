//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/fapi/fapiReturnCodeDataRef.C $
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
 */

#include <string.h>
#include <fapiReturnCodeDataRef.H>
#include <fapiUtil.H>
#include <fapiPlatTrace.H>

namespace fapi
{

//******************************************************************************
// ReturnCodeDataRef Constructor
//******************************************************************************
ReturnCodeDataRef::ReturnCodeDataRef() :
    iv_refCount(1)
{

}

//******************************************************************************
// ReturnCodeDataRef Destructor
//******************************************************************************
ReturnCodeDataRef::~ReturnCodeDataRef()
{
    if (iv_refCount != 0)
    {
        FAPI_ERR("ReturnCodeDataRef. Bug. Destruct with refcount");
        fapiAssert(false);
    }
}

//******************************************************************************
// ReturnCodeDataRef incRefCount function
//******************************************************************************
void ReturnCodeDataRef::incRefCount()
{
	FAPI_DBG("ReturnCodeDataRef::incRefCount: iv_refCount = %d on entry",
             iv_refCount);
    iv_refCount++;
}

//******************************************************************************
// ReturnCodeDataRef decRefCountCheckZero function
//******************************************************************************
bool ReturnCodeDataRef::decRefCountCheckZero()
{
	FAPI_DBG("ReturnCodeDataRef::decRefCountCheckZero: iv_refCount = %d on "
             "entry", iv_refCount);

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
// ReturnCodePlatDataRef Constructor
//******************************************************************************
ReturnCodePlatDataRef::ReturnCodePlatDataRef(void * i_pData) :
    iv_pData(i_pData)
{

}

//******************************************************************************
// ReturnCodePlatDataRef Destructor
//******************************************************************************
ReturnCodePlatDataRef::~ReturnCodePlatDataRef()
{
    // Call platform implemented deleteData
    (void) deleteData();
}

//******************************************************************************
// ReturnCodePlatDataRef getData function
//******************************************************************************
void * ReturnCodePlatDataRef::getData() const
{
    return iv_pData;
}

//******************************************************************************
// ReturnCodePlatDataRef releaseData function
//******************************************************************************
void * ReturnCodePlatDataRef::releaseData()
{
    void * l_pData = iv_pData;
    iv_pData = NULL;
    return l_pData;
}

//******************************************************************************
// ReturnCodeHwpFfdcRef Constructor
//******************************************************************************
ReturnCodeHwpFfdcRef::ReturnCodeHwpFfdcRef(const void * i_pFfdc,
                                           const uint32_t i_size)
: iv_size(i_size)
{
    iv_pFfdc = new uint8_t[i_size];
    memcpy(iv_pFfdc, i_pFfdc, i_size);
}

//******************************************************************************
// ReturnCodeHwpFfdcRef Destructor
//******************************************************************************
ReturnCodeHwpFfdcRef::~ReturnCodeHwpFfdcRef()
{
    delete [] iv_pFfdc;
    iv_pFfdc = NULL;
}

//******************************************************************************
// ReturnCodeHwpFfdcRef getData function
//******************************************************************************
const void * ReturnCodeHwpFfdcRef::getData(uint32_t & o_size) const
{
    o_size = iv_size;
    return iv_pFfdc;
}

}
