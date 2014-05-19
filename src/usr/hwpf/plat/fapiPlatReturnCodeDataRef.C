/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/plat/fapiPlatReturnCodeDataRef.C $               */
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
// deletePlatData function
//******************************************************************************
void ReturnCodeDataRef::deletePlatData()
{
	FAPI_DBG("ReturnCodePlatDataRef::deleteData");

    // HostBoot platform uses iv_pData to point at an error log.
    delete (static_cast<errlHndl_t>(iv_pPlatData));
    iv_pPlatData = NULL;
}

}
