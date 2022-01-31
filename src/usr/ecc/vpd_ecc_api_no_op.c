/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ecc/vpd_ecc_api_no_op.c $                             */
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

// ------------------------------------------------------------------
// Global variable to determine if the ECC APIs are present and available.
// This is the no-op version, therefore set to false (0).
// ------------------------------------------------------------------
const int g_vpd_ecc_api_present = 0;

// This variable is used only for linking purposes; if
// CONFIG_COMPILE_VPD_ECC_ALGORITHMS is not active, the libecc.so will create a
// reference to this variable and linking will fail unless this no-op
// implementation is used.
size_t seepromGetEccShim;

int vpdeccCreateEcc_wrapper(
                const unsigned char* i_recordData, size_t  i_recordLength,
                unsigned char*       o_eccData,    size_t* io_eccLength)
{
    return 0;
}

int vpdeccCheckData_wrapper(
                unsigned char*       io_recordData, size_t i_recordLength,
                const unsigned char* i_eccData,     size_t i_eccLength)
{
    return 0;
}
