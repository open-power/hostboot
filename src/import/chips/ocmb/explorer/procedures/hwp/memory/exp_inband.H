/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_inband.H $ */
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
///
/// @file exp_inband.H
/// @brief Explorer specifics for get/putMMIO inband ops
///
/// One Axone bar register is set per MC channel for MMIO, and another
/// is set per MC channel for config space.  Each bar is shared between
/// both sub-channels each with an OCMB.  The upper bit of the address
/// determined by the bar sizes is used to determine which sub-channel
/// is selected.  This means that for a pair of OCMB's on a channel
/// their config space is contiguous and their MMIO space is contiguous.
/// Therefore a single OCMB's MMIO and config space cannot be contiguous.
/// However, we can still use one BAR attribute and the set_bars procedure
/// can interleave the config space and MMIO space as shown in the table
/// bellow.  For example, both MMIO and config bar sizes are 2GB.  The
/// 2GB bit becomes the selector for the subchannel.  The 4GB bit
/// becomes the offset applied for MMIO operations.
///
///
/// Each OCMB is assigned one base address attribute.  For example:
/// ocmb  |  BAR ATTRIBUTE     | Type | Base reg           - end addr           | size | sub-ch
/// +-----+--------------------+------+-----------------------------------------+------+-------
/// ocmb0 | 0x0006030200000000 | cnfg | 0x0006030200000000 - 0x000603027FFFFFFF | 2GB  | 0
/// ocmb1 | 0x0006030280000000 | cnfg | 0x0006030280000000 - 0x00060302FFFFFFFF | 2GB  | 1
/// ocmb0 | N/A                | mmio | 0x0006030300000000 - 0x000603037FFFFFFF | 2GB  | 0
/// ocmb1 | N/A                | mmio | 0x0006030380000000 - 0x00060303FFFFFFFF | 2GB  | 1
/// +-----+--------------------+------+-----------------------------------------+------+-------
/// ocmb2 | 0x0006030400000000 | cnfg | 0x0006030400000000 - 0x000603047FFFFFFF | 2GB  | 0
/// ocmb3 | 0x0006030480000000 | cnfg | 0x0006030480000000 - 0x00060304FFFFFFFF | 2GB  | 1
/// ocmb2 | N/A                | mmio | 0x0006030500000000 - 0x000603057FFFFFFF | 2GB  | 0
/// ocmb3 | N/A                | mmio | 0x0006030580000000 - 0x00060305FFFFFFFF | 2GB  | 1
///
/// Bit 33 of the 64 bit address in big endian order determines if
/// the MMIO operation is a SCOM to the core or a register access
/// to MSCC space.  If an MSCC access falls within the range specified
/// by the MSCCRNGE core register it is an access to the MIPS SRAM.
/// Specific locations within the SRAM have been set asside for command
/// and response buffers. Once written an interrupt must be issued
/// to MIPS indicating a new command is ready.  Responses will send
/// an interrupt back to the host.
///
/// Table 4-8:- Address of various buffers
/// Buffer Type        MIPS view (un-cached)    Host View (OpenCapi)     I2C View
/// Command Buffer     0xA103 FF40              BAR + 0x0103 FF40        0xA103 FF40
/// Response Buffer    0xA103 FF00              BAR + 0x0103 FF00        0xA103 FF00
/// Data Buffer        0xA102 FF00              BAR + 0x0102 FF00        0xA102 FF00
///

/// @file exp_inband.H
/// @brief implement OpenCAPI config, scom, and MSCC MMIO operations.
//
// *HWP HWP Owner: bgass@us.ibm.com
// *HWP FW Owner: dcrowell@us.ibm.com
// *HWP Team:
// *HWP Level: 2
// *HWP Consumed by: HB
//
//--------------------------------------------------------------------------------

#ifndef __EXP_INBAND_H_
#define __EXP_INBAND_H_

#include <fapi2.H>
#include <exp_data_structs.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

namespace exp
{

namespace ib
{

static const uint64_t EXPLR_IB_CONFIG_OFFSET = 0x0000000000000000ull;
static const uint64_t EXPLR_IB_MMIO_OFFSET   = 0x0000000100000000ull; // 4GB

//--------------------------------------------------------------------------------
// The MSCC RAM Range Register SCOM 0x080108e5  MSCCRNGE
// determines the address range for the MIPS SRAM
// An offset within the the 1MB range is used for the command
//
/// Table 4-8:- Address of various buffers      64K      0x1 0000
/// Buffer Type        MIPS view (un-cached)    Host View (OpenCapi)     I2C View
/// Command Buffer     0xA103 FF40              BAR + 0x0103 FF40        0xA103 FF40
/// Response Buffer    0xA103 FF00              BAR + 0x0103 FF00        0xA103 FF00
/// Data Buffer        0xA102 FF00              BAR + 0x0102 FF00        0xA102 FF00
///
static const uint64_t EXPLR_IB_SRAM_BASE     = 0x01000000; // MSCCRNGE 01000000 020FFFFF
static const uint64_t EXPLR_IB_CMD_SRAM_ADDR  = EXPLR_IB_SRAM_BASE | 0x03FF40;
static const uint64_t EXPLR_IB_RSP_SRAM_ADDR  = EXPLR_IB_SRAM_BASE | 0x03FF00;
static const uint64_t EXPLR_IB_DATA_SRAM_ADDR = EXPLR_IB_SRAM_BASE | 0x02FF00;

static const uint64_t EXPLR_IB_CMD_ADDR =  EXPLR_IB_MMIO_OFFSET | EXPLR_IB_CMD_SRAM_ADDR;
static const uint64_t EXPLR_IB_RSP_ADDR =  EXPLR_IB_MMIO_OFFSET | EXPLR_IB_RSP_SRAM_ADDR;
static const uint64_t EXPLR_IB_DATA_ADDR = EXPLR_IB_MMIO_OFFSET | EXPLR_IB_DATA_SRAM_ADDR;

static const uint64_t EXPLR_IB_SENSOR_CACHE_ADDR = EXPLR_IB_MMIO_OFFSET | 0x40084200;

//--------------------------------------------------------------------------------
// Utilities
//--------------------------------------------------------------------------------

///
/// @brief Converts user_input_msdg to little endian
/// @param[in] i_input user_input_msdg structure to convert
/// @return vector of little endian data
///
std::vector<uint8_t> user_input_msdg_to_little_endian(const user_input_msdg& i_input);

///
/// @brief Converts host_fw_command_struct to little endian
/// @param[in] i_input user_input_msdg structure to convert
/// @return vector of little endian data
///
std::vector<uint8_t> host_fw_command_struct_to_little_endian(const host_fw_command_struct& i_input);

///
/// @brief Converts a little endian data array to a host_fw_response_struct
/// @param[in] i_data little endian data to process
/// @param[out] o_crc computed CRC
/// @param[out] o_response response structure
/// @return true if success false if failure
/// @note helper function - returning a bool and will have true FFDC in a separate function
///
bool host_fw_response_struct_from_little_endian(const std::vector<uint8_t>& i_data,
        uint32_t& o_crc,
        host_fw_response_struct& o_response);

///
/// @brief Converts a little endian data array to a host_fw_response_struct
/// @param[in] i_target OCMB target on which to operate
/// @param[in] i_data little endian data to process
/// @param[out] o_response response structure
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note helper function to allow for checking FFDC
///
fapi2::ReturnCode host_fw_response_struct_from_little_endian(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const std::vector<uint8_t>& i_data,
        host_fw_response_struct& o_response);

///
/// @brief Converts a little endian data array to a sensor_cache_struct
/// @param[in] i_data little endian data to process
/// @param[out] o_data sensor cache structure
/// @return true if success false if failure
/// @note helper function - returning a bool and will have true FFDC in a separate function
///
bool sensor_cache_struct_from_little_endian(const std::vector<uint8_t>& i_data,
        sensor_cache_struct& o_data);

///
/// @brief Converts a little endian data array to a sensor_cache_struct
/// @param[in] i_target OCMB target on which to operate
/// @param[in] i_data little endian data to process
/// @param[out] o_data sensor cache structure
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
/// @note helper function to allow for checking FFDC
///
fapi2::ReturnCode sensor_cache_struct_from_little_endian(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const std::vector<uint8_t>& i_data,
        sensor_cache_struct& o_data);

//--------------------------------------------------------------------------------
// Write operations
//--------------------------------------------------------------------------------

/// @brief Writes 64 bits of data to MMIO space to the selected Explorer
///
/// @param[in] i_target     The Explorer chip to write
/// @param[in] i_addr       The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putMMIO64(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    const fapi2::buffer<uint64_t>& i_data ) ;




/// @brief Writes 32 bits of data to MMIO space to the selected Explorer
///
/// @param[in] i_target     The Explorer chip to write
/// @param[in] i_addr       The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putMMIO32(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    const fapi2::buffer<uint32_t>& i_data ) ;




/// @brief Writes 64 bits of data to SCOM MMIO space
///
/// @param[in] i_target     The Explorer chip to write
/// @param[in] i_scomAddr   The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putScom(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_scomAddr,
    const fapi2::buffer<uint64_t>& i_data) ;




/// @brief Writes 32 bits of data to OpenCAPI config space
///
/// @param[in] i_target     The Explorer chip to write
/// @param[in] i_cfgAddr    The address to write
/// @param[in] i_data       The data to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putOCCfg(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_cfgAddr,
    const fapi2::buffer<uint32_t>& i_data) ;




/// @brief Writes user_input_msdg to the data buffer
///
/// @param[in] i_target     The Explorer chip to issue the command to
/// @param[in] i_data       The user_input_msdg data to write
/// @param[out] o_crc       The calculated crc of the data.
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putUserInputMsdg(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const user_input_msdg& i_data,
    uint32_t& o_crc);




/// @brief Writes a command to the command buffer and issues interrupt
///
/// @param[in] i_target     The Explorer chip to issue the command to
/// @param[in] i_cmd        The command structure to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putCMD(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const host_fw_command_struct& i_cmd) ;



//--------------------------------------------------------------------------------
// Read operations
//--------------------------------------------------------------------------------

/// @brief Reads 64 bits of data from MMIO space on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_addr       The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getMMIO64(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    fapi2::buffer<uint64_t>& o_data) ;




/// @brief Reads 32 bits of data from MMIO space on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_addr       The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getMMIO32(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_addr,
    fapi2::buffer<uint32_t>& o_data) ;




/// @brief Reads 64 bits of data from SCOM MMIO space on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_scomAddr   The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getScom(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_scomAddr,
    fapi2::buffer<uint64_t>& o_data) ;




/// @brief Reads 32 bits of data from OpenCAPI config space on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[in] i_cfgAddr    The address to read
/// @param[out] o_data      The data read from the address
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getOCCfg(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint64_t i_cfgAddr,
    fapi2::buffer<uint32_t>& o_data) ;




/// @brief Reads a response from the response buffer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[out] o_rsp       The response data read from the buffer
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getRSP(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    host_fw_response_struct& o_rsp) ;




/// @brief Reads the complete 64 byte sensor cache on the selected Explorer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[out] o_data      The data read from the buffer
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getSensorCache(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    sensor_cache_struct& o_data) ;


//--------------------------------------------------------------------------------

} // ns ib

} // ns exp

} // ns mss

#endif
