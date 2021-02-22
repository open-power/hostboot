/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd_ecc_api_algorithms.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

// ------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------
#include "ipvpd.H"   // vpdeccCreateEcc, vpdeccCheckData
#include "vpdecc.h"  // vpd_create_ecc, vpdecc_check_data

// ------------------------------------------------------------------
// Global variable to determine if the ECC APIs are present and available.
// This is the algorithms version, therefore set to true
// ------------------------------------------------------------------
const bool g_vpd_ecc_api_present(true);

// ------------------------------------------------------------------
// IpVpdFacade::vpdeccCreateEcc
// ------------------------------------------------------------------
int IpVpdFacade::vpdeccCreateEcc(
                const unsigned char* i_recordData, size_t  i_recordLength,
                unsigned char*       o_eccData,    size_t* io_eccLength)
{
    return ::vpdecc_create_ecc(i_recordData, i_recordLength, o_eccData, io_eccLength);
} // vpdeccCreateEcc

// ------------------------------------------------------------------
// IpVpdFacade::vpdeccCheckData
// ------------------------------------------------------------------
int IpVpdFacade::vpdeccCheckData(
                unsigned char*       io_recordData, size_t i_recordLength,
                const unsigned char* i_eccData,     size_t i_eccLength)
{
    return ::vpdecc_check_data(io_recordData, i_recordLength, i_eccData, i_eccLength);
} // vpdeccCheckData

