/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/common/spd_access/memport_state.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
///
/// @file memport_state.H
/// @brief Function to determine state of MEM_PORTs given SPD binary
///
// *HWP HWP Owner:
// *HWP HWP Owner: Dan Crowell <dcrowell@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#ifndef __MEMPORT_STATE_
#define __MEMPORT_STATE_

#include <vector>
#include <ddimm_spd_common.H>
#include <target_states.H>

// DDR5 DDIMM
// Byte 235: Memory PHYs Data Bus Width
//  00 = reserved
//  01 = 1 enabled - PHY0 (A0/B0)
//  10 = 1 enabled - PHY1 (A1/B1)
//  11 = 2 enabled  (A0/B0 and A1/B1)
constexpr uint16_t DDR5_PHY_WIDTH_BYTE = 235;
constexpr uint8_t DDR5_MEMPORT_MASK = 0xC0;
constexpr uint8_t DDR5_MEMPORT0     = 0x40;
constexpr uint8_t DDR5_MEMPORT1     = 0x80;

///
/// @brief Get the functional state of the MEM_PORTs behind the OCMB
///        from the provided OCMB spd binary.
///
/// @param[in] i_spd SPD binary
/// @param[in] i_memport_id  MEM_PORT id relative to the parent OCMB
/// @return TargetState State of MEM_PORT and downstream DIMMs
/// @note May need to be changed to support 4U SPD
///
inline fapi2::TargetState get_memport_state(const uint8_t* i_spd,
        const uint8_t i_memport_id)
{
    // Use the byte offsets appropriate to the dimm type
    if ( i_spd[DDIMM_SPD::DDR_BYTE] == DDIMM_SPD::MEM_DDR4 )
    {
        // DDR4 (Explorer) only supports a single memory port
        if( i_memport_id == 0 )
        {
            return fapi2::TARGET_STATE_FUNCTIONAL;
        }
        else
        {
            return fapi2::TARGET_STATE_NOT_PRESENT;
        }
    }
    else if ( i_spd[DDIMM_SPD::DDR_BYTE] == DDIMM_SPD::MEM_DDR5 )
    {
        uint8_t l_ports = i_spd[DDR5_PHY_WIDTH_BYTE] & DDR5_MEMPORT_MASK;

        if( ((i_memport_id == 0) && (l_ports & DDR5_MEMPORT0))
            || ((i_memport_id == 1) && (l_ports & DDR5_MEMPORT1)) )
        {
            return fapi2::TARGET_STATE_FUNCTIONAL;
        }
        else if( i_memport_id > 1 )
        {
            return fapi2::TARGET_STATE_NOT_PRESENT;
        }
        else
        {
            return fapi2::TARGET_STATE_PRESENT;
        }
    }
    else
    {
        return fapi2::TARGET_STATE_NOT_PRESENT;
    }
}

#endif
