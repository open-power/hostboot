/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/rowRepairsFuncs.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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

#ifndef ROWREPAIRS_H_
#define ROWREPAIRS_H_

#include <fapi2.H>
#include <../memory/lib/shared/mss_const.H>

extern "C"
{

/**
 * @brief FW Team Utility function that gets the Row Repair Data.
 *
 * This function finds the corresponding DIMM Target, calls
 * Row Repair Data getter procedure to get the DQ bitmap and returns the data
 * for the specified rank.
 *
 * @param[in]  i_fapiTrgt Reference to MCA/MBA/MEM_PORT/OCMB_CHIP Target
 * @param[in]  i_dimm MCA/MBA port DIMM number
 * @param[in]  i_rank DIMM rank number
 * @param[out] o_data Reference to data where Row Repair Data is copied to
 * @param[in]  i_port Optional port for MBA targets. Default is port 0.
 *
 * @return ReturnCode
 */
fapi2::ReturnCode getRowRepair( const fapi2::Target
    <fapi2::TARGET_TYPE_MCA|fapi2::TARGET_TYPE_MBA|
     fapi2::TARGET_TYPE_MEM_PORT|fapi2::TARGET_TYPE_OCMB_CHIP> & i_fapiTrgt,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    uint8_t (&o_data)[mss::ROW_REPAIR_BYTE_COUNT],
    const uint8_t i_port = 0 );

/**
 * @brief FW Team Utility function that sets the Row Repair Data.
 *
 * This function finds the corresponding DIMM Target, calls
 * Row Repair Data setter procedure to set the data
 * for the specified rank.
 *
 * @param[in]  i_fapiTrgt Reference to MCA/MBA/MEM_PORT/OCMB_CHIP Target
 * @param[in]  i_dimm MCA/MBA port DIMM number
 * @param[in]  i_rank DIMM rank number
 * @param[out] i_data Reference to data where Row Repair Data is
 * @param[in]  i_port Optional port for MBA targets. Default is port 0.
 *
 * @return ReturnCode
 */
fapi2::ReturnCode setRowRepair( const fapi2::Target
    <fapi2::TARGET_TYPE_MCA|fapi2::TARGET_TYPE_MBA|
     fapi2::TARGET_TYPE_MEM_PORT|fapi2::TARGET_TYPE_OCMB_CHIP> & i_fapiTrgt,
    const uint8_t i_dimm,
    const uint8_t i_rank,
    uint8_t (&i_data)[mss::ROW_REPAIR_BYTE_COUNT],
    const uint8_t i_port = 0 );

}

#endif
