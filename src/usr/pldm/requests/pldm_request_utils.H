/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_request_utils.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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
#ifndef __PLDM_REQUEST_UTILS
#define __PLDM_REQUEST_UTILS

/**
 * @file pldm_req_utils.H
 *
 * @brief Provide functions that are used by pldm_*_requests.C files
 *        in the src/usr/pldm/requests/ directory.
 */

/*  System Includes */
#include <assert.h>

/* Userspace Includes */
#include <errl/errlentry.H>
#include <errl/errludstring.H>

/* PLDM Includes */
#include <pldm/pldm_errl.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_trace.H>

/* libpldm Includes */
#include <base.h>
#include <utils.h>

using namespace ERRORLOG;

namespace PLDM
{
/**
 * @brief Used to validate the various fields of a PLDM response. Check if
 *        the value "i_actual" is equivalent to the value "i_expected".
 *        If not equivalent then create an error and return it.
 *
 * @param[in] i_actual The actual value of the field.
 * @param[in] i_expected The expected value of the field.
 * @param[in] i_moduleid Module ID to use if an error log is generated
 * @param[in] i_reasoncode Reason Code to use if an error log is generated
 * @param[in] i_rsp_bytes container holding the pldm response data as raw binary data
 *
 * @return errlHndl_t errorlog if i_actual != i_expected
*/
template<typename T, typename U, typename container>
errlHndl_t validate_resp(const T i_actual,
                         const U i_expected,
                         const PLDMModuleId i_moduleid,
                         const PLDMReasonCode i_reasoncode,
                         const container& i_rsp_bytes)
{
    errlHndl_t errl = nullptr;
    static_assert(sizeof(T) <= sizeof(uint64_t),
                  "validate_resp only supports types less than 8 bytes in size");
    static_assert(sizeof(U) <= sizeof(uint64_t),
                  "validate_resp only supports types less than 8 bytes in size");
    if(i_actual != i_expected)
    {
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            i_moduleid,
                            i_reasoncode,
                            i_actual,
                            i_expected,
                            ErrlEntry::NO_SW_CALLOUT);
        PLDM_ERR("validate_resp: Incorrect value, expected 0x%lx and got 0x%lx instead. Error rc=0x%x plid=0x%x",
                 i_expected, i_actual, ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
        addBmcErrorCallouts(errl);
        addCmdInfo(errl, i_rsp_bytes);
    }
    return errl;
}
}

#endif /* __PLDM_REQUEST_UTILS */
