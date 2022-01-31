/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ecc/vpd_ecc_api_wrapper.h $                   */
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

#ifndef VPD_ECC_API_WRAPPER_H
#define VPD_ECC_API_WRAPPER_H

#include <stdint.h>

extern const int g_vpd_ecc_api_present;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief A wrapper around the vpdecc_check_data API.
 *
 * See IpVpdFacade::vpdeccCreateEcc for documentation.
 */
int vpdeccCreateEcc_wrapper(
                const unsigned char* i_recordData, size_t  i_recordLength,
                unsigned char*       o_eccData,    size_t* io_eccLength);

/**
 * @brief A wrapper around the vpdecc_check_data API.
 *
 * See IpVpdFacade::vpdeccCheckData for documentation.
 */
int vpdeccCheckData_wrapper(
                unsigned char*       io_recordData, size_t i_recordLength,
                const unsigned char* i_eccData,     size_t i_eccLength);

#ifdef __cplusplus
}
#endif

#endif
