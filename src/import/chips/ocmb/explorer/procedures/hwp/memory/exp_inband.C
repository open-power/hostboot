/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_inband.C $ */
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

/// @file exp_inband.C
/// @brief implement OpenCAPI config, scom, and MSCC MMIO operations.
//
// *HWP HWP Owner: bgass@us.ibm.com
// *HWP FW Owner: dcrowell@us.ibm.com
// *HWP Team:
// *HWP Level: 2
// *HWP Consumed by: HB

#include <exp_inband.H>
#include <lib/omi/crc32.H>
#include <lib/shared/exp_consts.H>

#include <mmio_access.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{

namespace exp
{

namespace ib
{

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
    const fapi2::buffer<uint64_t>& i_data )
{
    uint64_t l_v = static_cast<uint64_t>(i_data);
    std::vector<uint8_t> l_wd;
    forceLE(l_v, l_wd);
    return fapi2::putMMIO(i_target, EXPLR_IB_MMIO_OFFSET | i_addr, 8, l_wd);
}




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
    const fapi2::buffer<uint32_t>& i_data )
{
    uint32_t l_v = static_cast<uint32_t>(i_data);
    std::vector<uint8_t> l_wd;
    forceLE(l_v, l_wd);
    return fapi2::putMMIO(i_target, EXPLR_IB_MMIO_OFFSET | i_addr, 4, l_wd);
}




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
    const fapi2::buffer<uint64_t>& i_data)
{
    // Converts from the scom address to the MMIO address by shifting left by 3 bits
    uint64_t l_scomAddr = i_scomAddr << 3;
    return putMMIO64(i_target, l_scomAddr, i_data);
}




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
    const fapi2::buffer<uint32_t>& i_data)
{
    uint32_t l_v = static_cast<uint32_t>(i_data);
    std::vector<uint8_t> l_wd;
    forceLE(l_v, l_wd);
    return fapi2::putMMIO(i_target, i_cfgAddr, 4, l_wd);
}




///
/// @brief Converts user_input_msdg to little endian
/// @param[in] i_input user_input_msdg structure to convert
/// @return vector of little endian data
///
std::vector<uint8_t> user_input_msdg_to_little_endian(const user_input_msdg& i_input)
{
    std::vector<uint8_t> l_data;
    forceLE(i_input.DimmType, l_data);
    forceLE(i_input.CsPresent, l_data);
    forceLE(i_input.DramDataWidth, l_data);
    forceLE(i_input.Height3DS, l_data);
    forceLE(i_input.ActiveDBYTE, l_data);
    forceLE(i_input.ActiveNibble, l_data);
    forceLE(i_input.AddrMirror, l_data);
    forceLE(i_input.ColumnAddrWidth, l_data);
    forceLE(i_input.RowAddrWidth, l_data);
    forceLE(i_input.SpdCLSupported, l_data);
    forceLE(i_input.SpdtAAmin, l_data);
    forceLE(i_input.Rank4Mode, l_data);
    forceLE(i_input.DDPCompatible, l_data);
    forceLE(i_input.TSV8HSupport, l_data);
    forceLE(i_input.MRAMSupport, l_data);
    forceLE(i_input.NumPStates, l_data);
    forceLEArray(i_input.Frequency, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.PhyOdtImpedance, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.PhyDrvImpedancePU, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.PhyDrvImpedancePD, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.PhySlewRate, MSDG_MAX_PSTATE, l_data);
    forceLE(i_input.ATxImpedance, l_data);
    forceLE(i_input.ATxSlewRate, l_data);
    forceLE(i_input.CKTxImpedance, l_data);
    forceLE(i_input.CKTxSlewRate, l_data);
    forceLE(i_input.AlertOdtImpedance, l_data);
    forceLEArray(i_input.DramRttNomR0, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttNomR1, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttNomR2, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttNomR3, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttWrR0, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttWrR1, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttWrR2, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttWrR3, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttParkR0, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttParkR1, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttParkR2, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramRttParkR3, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramDic, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramWritePreamble, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.DramReadPreamble, MSDG_MAX_PSTATE, l_data);
    forceLE(i_input.PhyEqualization, l_data);
    forceLEArray(i_input.InitVrefDQ, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.InitPhyVref, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.OdtWrMapCs, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.OdtRdMapCs, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.Geardown, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.CALatencyAdder, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.BistCALMode, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.BistCAParityLatency, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.RcdDic, MSDG_MAX_PSTATE, l_data);
    forceLEArray(i_input.RcdVoltageCtrl, MSDG_MAX_PSTATE, l_data);
    forceLE(i_input.RcdIBTCtrl, l_data);
    forceLE(i_input.RcdDBDic, l_data);
    forceLE(i_input.RcdSlewRate, l_data);
    forceLE(i_input.EmulationSupport, l_data);
    return l_data;
}

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
    uint32_t& o_crc)
{
    const auto l_data = user_input_msdg_to_little_endian(i_data);
    o_crc = crc32_gen(l_data);

    return fapi2::putMMIO(i_target, EXPLR_IB_DATA_ADDR, 8, l_data);
}



///
/// @brief Converts host_fw_command_struct to little endian
/// @param[in] i_input user_input_msdg structure to convert
/// @return vector of little endian data
///
std::vector<uint8_t> host_fw_command_struct_to_little_endian(const host_fw_command_struct& i_input)
{
    std::vector<uint8_t> l_data;

    forceLE(i_input.cmd_id, l_data);
    forceLE(i_input.cmd_flags, l_data);
    forceLE(i_input.request_identifier, l_data);
    forceLE(i_input.cmd_length, l_data);
    forceLE(i_input.cmd_crc, l_data);
    forceLE(i_input.host_work_area, l_data);
    forceLE(i_input.cmd_work_area, l_data);
    forceLEArray(i_input.padding, PADDING_SIZE, l_data);
    forceLEArray(i_input.command_argument, ARGUMENT_SIZE, l_data);

    // Generates and adds on the CRC
    const uint32_t l_cmd_header_crc = crc32_gen(l_data);
    FAPI_DBG("Command header crc: %xl", l_cmd_header_crc);
    forceLE(l_cmd_header_crc, l_data);

    return l_data;
}

/// @brief Writes a command to the command buffer and issues interrupt
///
/// @param[in] i_target     The Explorer chip to issue the command to
/// @param[in] i_cmd        The command structure to write
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode putCMD(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const host_fw_command_struct& i_cmd)
{
    const auto l_data = host_fw_command_struct_to_little_endian(i_cmd);
    fapi2::buffer<uint64_t> l_scom;

    // Clear the doorbell
    l_scom.setBit<EXPLR_MMIO_MDBELLC_MDBELL_MDBELL>();
    FAPI_TRY(mss::exp::ib::putScom(i_target, EXPLR_MMIO_MDBELLC, l_scom));

    // Set the command
    FAPI_TRY(fapi2::putMMIO(i_target, EXPLR_IB_CMD_ADDR, 8, l_data))

    // Ring the doorbell - aka the bit that interrupts the microchip FW and tells it to do the thing
    l_scom.flush<0>();
    l_scom.setBit<EXPLR_MMIO_MDBELL_MDBELL>();
    FAPI_TRY(mss::exp::ib::putScom(i_target, EXPLR_MMIO_MDBELL, l_scom));

fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}



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
    fapi2::buffer<uint64_t>& o_data)
{
    uint64_t l_rd = 0;
    std::vector<uint8_t> l_data(8);
    uint32_t l_idx = 0;
    FAPI_TRY(fapi2::getMMIO(i_target, EXPLR_IB_MMIO_OFFSET | i_addr, 8, l_data));
    readLE(l_data, l_idx, l_rd);
    o_data = l_rd;
fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}




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
    fapi2::buffer<uint32_t>& o_data)
{
    uint32_t l_rd = 0;
    std::vector<uint8_t> l_data(4);
    uint32_t l_idx = 0;
    FAPI_TRY(fapi2::getMMIO(i_target, EXPLR_IB_MMIO_OFFSET | i_addr, 4, l_data));
    readLE(l_data, l_idx, l_rd);
    o_data = l_rd;
fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}




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
    fapi2::buffer<uint64_t>& o_data)
{
    // Converts from the scom address to the MMIO address by shifting left by 3 bits
    uint64_t l_scomAddr = i_scomAddr << 3;
    return getMMIO64(i_target, l_scomAddr, o_data);
}




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
    fapi2::buffer<uint32_t>& o_data)
{
    uint32_t l_rd = 0;
    std::vector<uint8_t> l_data(4);
    uint32_t l_idx = 0;
    FAPI_TRY(fapi2::getMMIO(i_target, i_cfgAddr, 4, l_data));
    readLE(l_data, l_idx, l_rd);
    o_data = l_rd;
fapi_try_exit:
    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}



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
        host_fw_response_struct& o_response)
{
    uint32_t l_idx = 0;
    bool l_rc = readLE(i_data, l_idx, o_response.response_id);
    l_rc &= readLE(i_data, l_idx, o_response.response_flags);
    l_rc &= readLE(i_data, l_idx, o_response.request_identifier);
    l_rc &= readLE(i_data, l_idx, o_response.response_length);
    l_rc &= readLE(i_data, l_idx, o_response.response_crc);
    l_rc &= readLE(i_data, l_idx, o_response.host_work_area);

    l_rc &= readLEArray(i_data, PADDING_SIZE, l_idx, o_response.padding);
    l_rc &= readLEArray(i_data, ARGUMENT_SIZE, l_idx, o_response.response_argument);

    o_crc = crc32_gen(i_data, l_idx);
    l_rc &= readLE(i_data, l_idx, o_response.response_header_crc);

    return l_rc;
}

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
        host_fw_response_struct& o_response)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint32_t l_crc = 0;
    FAPI_ASSERT( host_fw_response_struct_from_little_endian(i_data,
                 l_crc,
                 o_response),
                 fapi2::EXP_INBAND_LE_DATA_RANGE()
                 .set_TARGET(i_target)
                 .set_FUNCTION(mss::exp::READ_HOST_FW_RESPONSE_STRUCT)
                 .set_DATA_SIZE(i_data.size())
                 .set_MAX_INDEX(sizeof(host_fw_response_struct)),
                 "%s Failed to convert from data to host_fw_response_struct data size %u expected size %u",
                 mss::c_str(i_target), i_data.size(), sizeof(host_fw_response_struct));

    FAPI_ASSERT(l_crc == o_response.response_header_crc,
                fapi2::EXP_INBAND_RSP_CRC_ERR()
                .set_COMPUTED(l_crc)
                .set_RECEIVED(o_response.response_header_crc)
                .set_OCMB_TARGET(i_target),
                "%s Response CRC failed to validate computed: 0x%08x got: 0x%08x",
                mss::c_str(i_target), l_crc, o_response.response_header_crc);

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Reads a response from the response buffer
///
/// @param[in] i_target     The Explorer chip to read data from
/// @param[out] o_rsp       The response data read from the buffer
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode getRSP(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    host_fw_response_struct& o_rsp)
{
    std::vector<uint8_t> l_data(static_cast<int>(sizeof(o_rsp)));
    FAPI_TRY(fapi2::getMMIO(i_target, EXPLR_IB_RSP_ADDR, 8, l_data));

    FAPI_TRY(host_fw_response_struct_from_little_endian(i_target, l_data, o_rsp));

fapi_try_exit:
    FAPI_DBG("%s Exiting with return code : 0x%08X...", mss::c_str(i_target), (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

} // ns ib

} // ns exp

} // ns mss
