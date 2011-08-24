//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/plat/fapiPlatReturnCodeDataRef.C $
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
 *  @file platReturnCodeDataRef.C
 *
 *  @brief Implements the platform part of the ReturnCodeDataRef class.
 *
 *  Note that platform code must provide the implementation. FAPI has provided
 *  an example for platforms that do not attach ReturnCodeData to a ReturnCode.
 */

#include <fapiReturnCodeDataRef.H>
#include <fapiPlatTrace.H>
#include <errl/errlentry.H>

namespace fapi
{

//******************************************************************************
// deleteData function
//******************************************************************************
void ReturnCodePlatDataRef::deleteData()
{
	FAPI_DBG("ReturnCodePlatDataRef::deleteData");

    // HostBoot platform uses iv_pData to point at an error log.
    delete (static_cast<errlHndl_t>(iv_pData));
    iv_pData = NULL;
}

}
