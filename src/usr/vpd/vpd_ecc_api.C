/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/vpd_ecc_api.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include "ipvpd.H"              // translateRecord, findRecordMetaDataSeeprom, fetchData

// ----------------------------------------------
// Macros for unit testing
// ----------------------------------------------
//#define TRACSSCOMP(args...)  TRACFCOMP(args)
#define TRACSSCOMP(args...)

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_vpd;

// ----------------------------------------------
// Forward declarations
// ----------------------------------------------
errlHndl_t validateCreateEccResults(
               const size_t                     i_results,
               const TARGETING::TargetHandle_t  i_target,
               const IpVpdFacade::input_args_t &i_args,
               const char *                     i_recordName,
               const uint16_t                   i_recordOffset,
               const uint16_t                   i_recordLength,
               const uint16_t                   i_eccOffset,
               const uint16_t                   i_eccLength );

errlHndl_t validateCheckDataResults(
               const size_t                     i_results,
               const TARGETING::TargetHandle_t  i_target,
               const IpVpdFacade::input_args_t &i_args,
               const char *                     i_recordName,
               const uint16_t                   i_recordOffset,
               const uint16_t                   i_recordLength,
               const uint16_t                   i_eccOffset,
               const uint16_t                   i_eccLength );

// ------------------------------------------------------------------
// IpVpdFacade::updateRecordEccData
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::updateRecordEccData (
               const TARGETING::TargetHandle_t  i_target,
               const IpVpdFacade::input_args_t &i_args )
{
    return nullptr;
} // updateRecordEccData

// ------------------------------------------------------------------
// IpVpdFacade::validateRecordEccData
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::validateRecordEccData (
               const TARGETING::TargetHandle_t  i_target,
               const IpVpdFacade::input_args_t &i_args )
{
    return nullptr;
} // validateRecordEccData

// ------------------------------------------------------------------
// IpVpdFacade::validateAllRecordEccData
// ------------------------------------------------------------------
errlHndl_t IpVpdFacade::validateAllRecordEccData (
               const TARGETING::TargetHandle_t  i_target )
{
    return nullptr;
} // validateAllRecordEccData

