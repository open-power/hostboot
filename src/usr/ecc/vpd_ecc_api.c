/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ecc/vpd_ecc_api.c $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

#include <stdint.h>
#include <vpdecc.h>

// ------------------------------------------------------------------
// Global variable to determine if the ECC APIs are present and available.
// This is the real version, therefore set to true (1).
// ------------------------------------------------------------------
const int g_vpd_ecc_api_present = 1;

// Stringify a token given as a preprocessor macro
#define EXPAND(X) #X
#define STR(X) EXPAND(X)

// This variable will hold the git commit hash that identifies the version of
// the ECC implementation that was compiled into libecc_static.a. Use the
// "strings" command on libecc_static.a and grep for this string to identify the
// version of the ECC implementation it contains. This string will not appear in
// the no-op implementation.
const char ibm_fw_proprietary_commit_hash[] = "ibm_fw_proprietary git hash: " STR(IBM_FW_PROPRIETARY_COMMIT_HASH);

int vpdeccCreateEcc_wrapper(
                const unsigned char* i_recordData, size_t  i_recordLength,
                unsigned char*       o_eccData,    size_t* io_eccLength)
{
    return vpdecc_create_ecc(i_recordData, i_recordLength, o_eccData, io_eccLength);
}

int vpdeccCheckData_wrapper(
                unsigned char*       io_recordData, size_t i_recordLength,
                const unsigned char* i_eccData,     size_t i_eccLength)
{
    return vpdecc_check_data(io_recordData, i_recordLength, i_eccData, i_eccLength);
}
