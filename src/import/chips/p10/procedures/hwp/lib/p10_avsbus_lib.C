/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_avsbus_lib.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file  p10_avsbus_lib.C
/// @brief Library functions for AVSBus
///
/// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP HWP Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner         : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *Team                 : PM
/// *Consumed by          : SBE:CRO
/// *Level                : 3
///

#include <p10_avsbus_lib.H>
#include <p10_avsbus_scom.H>
#include <ocb_firmware_registers.h>

const static char* g_rail_str[]
{
    "VDD",
    "VCS",
    "VDN",
    "VIO"
};

//##############################################################################
// Function which generates a 3 bit CRC value for 29 bit data
//##############################################################################
#define AVS_CRC_DATA_MASK 0xFFFFFFF8
uint32_t avsCRCcalc(const uint32_t i_avs_cmd)
{
    //Polynomial = x^3 + x^1 + x^0 = 1*x^3 + 0*x^2 + 1*x^1 + 1*x^0
    //           = divisor(1011)
    uint32_t o_crc_value = 0;
    uint32_t l_polynomial = 0xB0000000;
    uint32_t l_msb =        0x80000000;

    o_crc_value = i_avs_cmd & AVS_CRC_DATA_MASK;

    while (o_crc_value & AVS_CRC_DATA_MASK)
    {
        if (o_crc_value & l_msb)
        {
            // if l_msb is 1'b1, divide by l_polynomial and shift l_polynomial
            // to the right
            o_crc_value = o_crc_value ^ l_polynomial;
            l_polynomial = l_polynomial >> 1;
        }
        else
        {
            // if l_msb is zero, shift l_polynomial
            l_polynomial = l_polynomial >> 1;
        }

        l_msb = l_msb >> 1;
    }

    FAPI_DBG("Computed CRC Value = %d", o_crc_value)
    return o_crc_value;
}

//##############################################################################
// Function which initializes the OCB O2S registers
//##############################################################################
fapi2::ReturnCode
avsInitExtVoltageControl(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_avsBusNum,
    const uint8_t i_o2sBridgeNum)
{

    fapi2::buffer<uint64_t> l_data64;
    uint32_t l_avsbus_frequency, l_value, l_nest_frequency;
    uint16_t l_divider;

    // O2SCTRLF
    // [ 0: 5] o2s_frame_size = 32; -> 0x20
    // [ 6:11] o2s_out_count1 = 32; -> 0x20
    // [12:17] o2s_in_delay1  = 255 -> 0xFF; (long delay – no read data)
    // [18:23] o2s_in_l_count1  =  X;     No input on first frame

    //uint32_t O2SCTRLF_value = 0b10000010000011111100000000000000;
    ocb_o2sctrlfn_t O2SCTRLF_value;
    O2SCTRLF_value.fields.o2s_frame_size_n = p10avslib::O2S_FRAME_SIZE;
    O2SCTRLF_value.fields.o2s_out_count1_n = p10avslib::O2S_FRAME_SIZE;
    O2SCTRLF_value.fields.o2s_in_delay1_n = p10avslib::O2S_IN_DELAY1;

    l_data64.flush<0>();
    l_data64.insertFromRight<0, 6>(O2SCTRLF_value.fields.o2s_frame_size_n);
    l_data64.insertFromRight<6, 6>(O2SCTRLF_value.fields.o2s_out_count1_n);
    l_data64.insertFromRight<12, 6>(O2SCTRLF_value.fields.o2s_in_delay1_n);
    FAPI_TRY(putScom(i_target,
                     p10avslib::OCB_O2SCTRLF[i_avsBusNum],
                     l_data64));

    // Note:  the buffer is a 32bit buffer.  make sure it is left
    // aligned for the SCOM

    // O2SCTRLS
    // [ 0: 5] o2s_out_count2  = 0;
    // [ 6:11] o2s_in_delay2   = 0;
    // [12:17] o2s_in_l_count2   = 32; -> 0x20;

    // uint32_t O2SCTRLS_value = 0b00000000000010000000000000000000;
    ocb_o2sctrlsn_t O2SCTRLS_value;
    O2SCTRLS_value.fields.o2s_in_count2_n = p10avslib::O2S_FRAME_SIZE;

    l_data64.flush<0>();
    l_data64.insertFromRight<12, 6>(O2SCTRLS_value.fields.o2s_in_count2_n);
    FAPI_TRY(putScom(i_target,
                     p10avslib::OCB_O2SCTRLS[i_avsBusNum],
                     l_data64));

    // O2SCTRL1
    // [    0] o2s_bridge_enable
    // [    1] pmcocr1_reserved_1
    // [    2] o2s_cpol = 0;            Low idle clock
    // [    3] o2s_cpha = 0;            First edge
    // [ 4:13] o2s_clock_divider = 0xFA    Yield 1MHz with 2GHz nest
    // [14:16] pmcocr1_reserved_2
    // [   17] o2s_nr_of_frames = 1; Two frames
    // [18:20] o2s_port_enable (only port 0 (18) by default

    // Divider calculation (which can be overwritten)
    //  Nest Frequency:  2000MHz (0x7D0)
    //  AVSBus Frequency:    1MHz (0x1) (eg  1us per bit)
    //
    // Divider = Nest Frequency / (AVSBus Frequency * 8) - 1
    //
    // @note:  PPE can multiply by a recipricol.  A precomputed
    // 1 / (AVSBus frequency *8) held in an attribute allows a
    // fully l_data64 driven computation without a divide operation.

    ocb_o2sctrl1n_t O2SCTRL1_value;
    O2SCTRL1_value.fields.o2s_bridge_enable_n_a = 1;
    O2SCTRL1_value.fields.o2s_bridge_enable_n_b = 1;

    //Nest frequency attribute in MHz
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ,
                           fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_nest_frequency));

    // AVSBus frequency attribute in KHz
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_AVSBUS_FREQUENCY,
                           i_target,
                           l_value));

    if (l_value == 0)
    {
        l_avsbus_frequency = p10avslib::AVSBUS_FREQUENCY / 1000;
        FAPI_INF("Using default AVSBus frequency value of %d", l_avsbus_frequency);
    }
    else
    {
        l_avsbus_frequency = l_value / 1000;
        FAPI_INF("AVSBus frequency value is %d", l_avsbus_frequency);
    }

    // Divider = Nest Frequency / (AVSBus Frequency * 8) - 1
    l_divider = (l_nest_frequency / (l_avsbus_frequency * 8)) - 1;

    FAPI_INF("AVSBus number is %d using bridge %d", i_avsBusNum, i_o2sBridgeNum );
    FAPI_INF("Const frequency value is %d", l_nest_frequency);
    FAPI_INF("Divider value is %d (0x%X)", l_divider, l_divider);

    O2SCTRL1_value.fields.o2s_clock_divider_n = l_divider;
    O2SCTRL1_value.fields.o2s_nr_of_frames_n = 1;

    l_data64.flush<0>();
    l_data64.insertFromRight<0, 1>(O2SCTRL1_value.fields.o2s_bridge_enable_n_a);
    l_data64.insertFromRight<1, 1>(O2SCTRL1_value.fields.o2s_bridge_enable_n_b);
    l_data64.insertFromRight<4, 10>(O2SCTRL1_value.fields.o2s_clock_divider_n);
    l_data64.insertFromRight<17, 1>(O2SCTRL1_value.fields.o2s_nr_of_frames_n);
    FAPI_TRY(putScom(i_target,
                     p10avslib::OCB_O2SCTRL1[i_avsBusNum],
                     l_data64));

    // O2SCTRL2
    // OCC O2S Control2
    // [ 0:15] o2s_inter_frame_delay
    // Delay between two frames of a two command set as measured from the end of
    // the last bit of the first frame until the chip select of the second frame
    // is  asserted.
    // Delay is computed as: (value * SPI clock)
    // 0x00000: Wait 1 SPI Clock
    // 0x00001 - 0x1FFFF: value = number of ~SPI Clocks
    // Max. delay at the fastest SPI clock is 1.3ms.
    ocb_o2sctrl2n_t O2SCTRL2_value;
    O2SCTRL2_value.fields.o2s_inter_frame_delay_n = 0x0;

    l_data64.flush<0>();
    l_data64.insertFromRight<0, 16>
    (O2SCTRL2_value.fields.o2s_inter_frame_delay_n);
    FAPI_TRY(putScom(i_target,
                     p10avslib::OCB_O2SCTRL2[i_avsBusNum],
                     l_data64));

fapi_try_exit:
    return fapi2::current_err;
}

//##############################################################################
// Function polls OCB status register O2SST for o2s_ongoing=0
//##############################################################################
fapi2::ReturnCode
avsPollVoltageTransDone(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_avsBusNum,
    const uint8_t i_avsBusRail,
    const uint8_t i_o2sBridgeNum)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_data64;

    uint8_t l_count = 0;

    while (l_count < p10avslib::MAX_POLL_COUNT_AVS)
    {
        FAPI_TRY(getScom(i_target, p10avslib::OCB_O2SST[i_avsBusNum]
                         [i_o2sBridgeNum], l_data64),
                 "Error from getscom 0x%.16llX",
                 p10avslib::OCB_O2SST[i_avsBusNum]);

        if (!l_data64.getBit<0>())
        {
            break;  // Leave the polling loop as "ongoing" has deasserted
        }

        l_count++;
    }

    // Check for timeout condition
    // This will set current_err to a non success value that can be
    // checked by the caller.
    FAPI_ASSERT((l_count < p10avslib::MAX_POLL_COUNT_AVS),
                fapi2::PROCPM_AVSBUS_POLL_TIMEOUT()
                .set_PROC_TARGET(i_target)
                .set_AVSBUS_NUM(i_avsBusNum)
                .set_AVSRAIL_NUM(i_avsBusRail)
                .set_AVSBUS_BRIDGE_NUM(i_o2sBridgeNum)
                .set_AVSBUS_MAX_POLL_CNT(p10avslib::MAX_POLL_COUNT_AVS)
                .set_SCOMREG_ADDR(p10avslib::OCB_O2SST[i_avsBusNum][i_o2sBridgeNum])
                .set_SCOMREG_DATA(l_data64),
                "avsPollVoltageTransDone poll timeout");

fapi_try_exit:
    return fapi2::current_err;
}

//##############################################################################
// Function which outputs a downstream command
//##############################################################################
fapi2::ReturnCode
avsDriveCommand(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                const uint8_t  i_avsBusNum,
                const uint8_t  i_o2sBridgeNum,
                const uint32_t i_RailSelect,
                const uint32_t i_CmdType,
                const uint32_t i_CmdGroup,
                const uint32_t i_CmdDataType,
                const uint32_t i_CmdData,
                enum avsBusOpType i_opType)
{

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data64WithoutCRC;
    fapi2::ReturnCode l_rc;

    uint32_t l_StartCode = 0b01;
    uint32_t l_Reserved = 0b000;
    uint32_t l_crc;

    // clear sticky bits in o2s_status_reg
    l_data64.setBit<1, 1>();
    FAPI_TRY(putScom(i_target,
                     p10avslib::OCB_O2SCMD[i_avsBusNum][i_o2sBridgeNum],
                     l_data64));

    // MSB sent out first always, which should be start code 0b01
    // compose and send frame
    //      CRC(31:29),
    //      l_Reserved(28:13) (read), CmdData(28:13) (write)
    //      RailSelect(12:9),
    //      l_CmdDataType(8:5),
    //      l_CmdGroup(4),
    //      l_CmdType(3:2),
    //      l_StartCode(1:0)
    l_data64.flush<0>();
    l_data64.insertFromRight<0, 2>(l_StartCode);
    l_data64.insertFromRight<2, 2>(i_CmdType);
    l_data64.insertFromRight<4, 1>(i_CmdGroup);
    l_data64.insertFromRight<5, 4>(i_CmdDataType);
    l_data64.insertFromRight<9, 4>(i_RailSelect);
    l_data64.insertFromRight<13, 16>(i_CmdData);
    l_data64.insertFromRight<29, 3>(l_Reserved);

    // Generate CRC
    l_data64.extract(l_data64WithoutCRC, 0, 32);
    l_crc = avsCRCcalc(l_data64WithoutCRC);
    l_data64.insertFromRight<29, 3>(l_crc);
    FAPI_TRY(putScom(i_target,
                     p10avslib::OCB_O2SWD[i_avsBusNum][i_o2sBridgeNum], l_data64));

    // Wait on o2s_ongoing = 0
    FAPI_TRY(avsPollVoltageTransDone(i_target, i_avsBusNum, i_RailSelect, i_o2sBridgeNum));
    // Note:  caller will check for the specific timeout return code.

fapi_try_exit:

    if (fapi2::current_err)
    {
        FAPI_ERR("AVS bus driver command function fail");
    }

    return fapi2::current_err;
}

//##############################################################################
// Function which writes to OCB registers to initiate a AVS read transaction
//##############################################################################
fapi2::ReturnCode
avsVoltageRead(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               const uint8_t i_avsBusNum,
               const uint8_t i_o2sBridgeNum,
               const uint32_t i_RailSelect,
               uint32_t& o_Voltage)
{

    fapi2::buffer<uint64_t> l_data64;

    // Values as per VRM spec
    // Cmd 0b11, cmd group 0, cmd data type - 0b0000 for voltage read,
    // outbound data = 0xFFFf
    uint32_t l_CmdType     = 3; // read
    uint32_t l_CmdGroup    = 0;
    uint32_t l_CmdDataType = 0;
    uint32_t l_outboundCmdData = 0xFFFF;

    // Drive a Read Command
    FAPI_TRY(avsDriveCommand(i_target,
                             i_avsBusNum,
                             i_o2sBridgeNum,
                             i_RailSelect,
                             l_CmdType,
                             l_CmdGroup,
                             l_CmdDataType,
                             l_outboundCmdData));

    // Read returned voltage value from Read frame
    FAPI_TRY(getScom(i_target,
                     p10avslib::OCB_O2SRD[i_avsBusNum][i_o2sBridgeNum], l_data64));
    // Extracting bits 8:23 , which contains voltage read data
    o_Voltage = (l_data64 & 0x00FFFF0000000000) >> 40;

    FAPI_INF("Voltage value read is %d mV", o_Voltage);

fapi_try_exit:
    return fapi2::current_err;
}

//##############################################################################
// Function which writes to OCB registers to initiate a AVS write transaction
//##############################################################################
fapi2::ReturnCode
avsVoltageWrite(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                const uint8_t i_avsBusNum,
                const uint8_t i_o2sBridgeNum,
                const uint32_t i_RailSelect,
                const uint32_t i_Voltage)
{
    uint32_t l_CmdType     = 0; // write and commit
    uint32_t l_CmdGroup    = 0;
    uint32_t l_CmdDataType = 0;

    FAPI_INF("Voltage %4d (0x%X)  Limit %4d (0x%X)",
             i_Voltage, i_Voltage,
             p10avslib::AVSBUS_MAX_VOLTAGE_MV, p10avslib::AVSBUS_MAX_VOLTAGE_MV);

    if (i_Voltage > p10avslib::AVSBUS_MAX_VOLTAGE_MV)
    {
        FAPI_ERR("ERROR: Voltage %4d is greater than the AVSBUS VRM allow maximum of %4d  mV was to be attempted to bus %d, rail %d",
                 i_Voltage,
                 p10avslib::AVSBUS_MAX_VOLTAGE_MV,
                 i_avsBusNum,
                 i_RailSelect);

        FAPI_ASSERT(false,
                    fapi2::PM_AVSBUS_EXCESSIVE_VOLTAGE_ERROR()
                    .set_PROC_TARGET(i_target)
                    .set_BUS(i_avsBusNum)
                    .set_RAIL(i_RailSelect)
                    .set_BRIDGE(i_o2sBridgeNum)
                    .set_VOLTAGE(i_Voltage),
                    "A voltage greater than the AVSBUS VRM allowable maximum was to be attempted");
    }

    // Drive a Write Command
    FAPI_TRY(avsDriveCommand(i_target,
                             i_avsBusNum,
                             i_o2sBridgeNum,
                             i_RailSelect,
                             l_CmdType,
                             l_CmdGroup,
                             l_CmdDataType,
                             i_Voltage));

fapi_try_exit:
    return fapi2::current_err;
}

//##############################################################################
// Function to read the AVSBus VRM Status
//##############################################################################
fapi2::ReturnCode
avsStatusRead(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
              const uint8_t  i_avsBusNum,
              const uint8_t  i_o2sBridgeNum,
              const uint32_t i_RailSelect,
              uint32_t&      o_StatusData)
{

    fapi2::buffer<uint64_t> l_data64;

    // Values as per VRM spec
    // Cmd 0b11, cmd group 0, cmd data type - 0b1110 for AVSBus Status,
    // outbound data = 0xFFFf
    uint32_t l_CmdType     = 3;  // read
    uint32_t l_CmdGroup    = 0;
    uint32_t l_CmdDataType = 0xE;
    uint32_t l_outboundCmdData = 0xFFFF;

    // Drive a Read Command
    FAPI_TRY(avsDriveCommand(i_target,
                             i_avsBusNum,
                             i_o2sBridgeNum,
                             i_RailSelect,
                             l_CmdType,
                             l_CmdGroup,
                             l_CmdDataType,
                             l_outboundCmdData));

    // Read returned voltage value from Read frame
    FAPI_TRY(getScom(i_target,
                     p10avslib::OCB_O2SRD[i_avsBusNum][i_o2sBridgeNum], l_data64));
    // Extracting bits 8:23 , which contains the status data
    o_StatusData = (l_data64 & 0x00FFFF0000000000) >> 40;

    FAPI_INF("AVSBus status value read is %d mV", o_StatusData);

fapi_try_exit:
    return fapi2::current_err;
}


//##############################################################################
// Function which writes to OCB registers to initialize the AVS Slave with an
// idle frame
//##############################################################################
fapi2::ReturnCode
avsIdleFrame(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
             const uint8_t i_avsBusNum,
             const uint8_t i_avsRailNum,
             const uint8_t i_o2sBridgeNum)
{
    fapi2::buffer<uint64_t> l_idleframe = 0xFFFFFFFFFFFFFFFFull;
    fapi2::buffer<uint64_t> l_scomdata;

    // clear sticky bits in o2s_status_reg
    l_scomdata.setBit<1, 1>();
    FAPI_TRY(putScom(i_target,
                     p10avslib::OCB_O2SCMD[i_avsBusNum][i_o2sBridgeNum],
                     l_scomdata),
             "Error clearing sticky bits in o2s_status_reg");

    FAPI_INF("Sending idle frame of all 1s");
    // Send the idle frame
    l_scomdata = l_idleframe;
    FAPI_TRY(putScom(i_target,
                     p10avslib::OCB_O2SWD[i_avsBusNum][i_o2sBridgeNum],
                     l_scomdata));

    // Wait on o2s_ongoing = 0
    FAPI_TRY(avsPollVoltageTransDone(i_target, i_avsBusNum, i_avsRailNum, i_o2sBridgeNum));

fapi_try_exit:

    if (fapi2::current_err)
    {
        FAPI_ERR("AVS Idle frame function fails");
    }

    return fapi2::current_err;
}

//##############################################################################
// Function which reads the data response from the AVSBus and validates it.
//##############################################################################
fapi2::ReturnCode
avsValidateResponse(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                    const uint8_t       i_avsBusNum,
                    const uint8_t       i_o2sBridgeNum,
                    const uint8_t       i_RailSelect,
                    const uint8_t       i_throw_assert,
                    uint8_t&            o_goodResponse,
                    enum avsBusOpType   i_opType = p10avslib::VLTG_READ_VLTG
                   )

{
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_rsp_rcvd_crc;

    fapi2::buffer<uint32_t> l_rsp_data;                 // Response frame read from the hardware
    fapi2::buffer<uint8_t>  l_rsp_ack_code;
    fapi2::buffer<uint8_t>  l_rsp_status;               // 3 bit code Acknowledgement Response Frame
    fapi2::buffer<uint32_t> l_status_data = 0;          // Buffer for Read Status command that might be used
    fapi2::buffer<uint8_t>  l_status_frame_resp = 0;    // 5 bit code from Status Response Frame
    fapi2::buffer<uint32_t> l_command        ;          // Command sent
    uint8_t                 l_goodResponse;             // Internal use
    uint32_t                l_buffer = 0;
    fapi2::ATTR_AVSBUS_VRM_FAIL_OVERRIDE_Type l_vrm_fail_override =
    fapi2::ENUM_ATTR_AVSBUS_VRM_FAIL_OVERRIDE_NO_ERROR;

    bool                    b_avs_in_control = true;
    bool                    b_status_alert   = false;
    bool                    b_over_current   = false;
    bool                    b_under_volt     = false;
    bool                    b_over_temp      = false;
    bool                    b_over_power     = false;

    uint32_t l_rsp_computed_crc;
    o_goodResponse = false;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_AVSBUS_VRM_FAIL_OVERRIDE,
    i_target, l_vrm_fail_override));

    // Read the command register
    FAPI_DBG("Reading the OS2SRD register to check status");
    FAPI_TRY(getScom(i_target, p10avslib::OCB_O2SWD[i_avsBusNum][i_o2sBridgeNum],
    l_data64));
    l_data64.extractToRight(l_command, 0, 32);

    // Read the data response register
    FAPI_DBG("Reading the OS2SRD register to check status");
    FAPI_TRY(getScom(i_target, p10avslib::OCB_O2SRD[i_avsBusNum][i_o2sBridgeNum],
    l_data64));

    // Status Return Code and Received CRC
    l_data64.extractToRight(l_rsp_ack_code, 0, 2);
    l_data64.extractToRight(l_rsp_status, 3, 5);
    l_data64.extractToRight(l_rsp_rcvd_crc, 29, 3);
    l_data64.extractToRight(l_rsp_data, 0, 32);

    // Compute CRC on Response frame
    l_rsp_computed_crc = avsCRCcalc(l_rsp_data);

    // Error inject code to log VRM fail
    if (l_vrm_fail_override !=
    fapi2::ENUM_ATTR_AVSBUS_VRM_FAIL_OVERRIDE_NO_ERROR)
    {
        switch (l_vrm_fail_override)
        {
            case fapi2::ENUM_ATTR_AVSBUS_VRM_FAIL_OVERRIDE_ZERO_RESP_ERR:
                l_rsp_data = 0x00000000;
                break;

            case fapi2::ENUM_ATTR_AVSBUS_VRM_FAIL_OVERRIDE_NO_RESP_ERROR:
                l_rsp_data = 0xFFFFFFFF;
                break;

            case fapi2::ENUM_ATTR_AVSBUS_VRM_FAIL_OVERRIDE_MASTER_BAD_CRC_ERROR:
                l_rsp_rcvd_crc = ~l_rsp_computed_crc;
                break;

            case fapi2::ENUM_ATTR_AVSBUS_VRM_FAIL_OVERRIDE_SLAVE_BAD_CRC_ERROR:
                l_rsp_ack_code = 2;
                break;

            default:
                break;
        }
    }

    if ((l_rsp_ack_code == 0) &&                               // no error code
        (l_rsp_rcvd_crc == l_rsp_computed_crc) &&              // good crc
        (l_rsp_data != 0) && (l_rsp_data != 0xFFFFFFFF))       // valid response
    {
        o_goodResponse = true;
    }
    else
    {

        FAPI_INF("Non-clean response received for %s: Computed CRC vs %X Received CRC %X;  Full Response %08X",
        g_rail_str[i_RailSelect], l_rsp_computed_crc, l_rsp_rcvd_crc, l_rsp_data);


        FAPI_TRY(getScom(i_target, scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_RW, l_data64));

        if (!l_data64.getBit<scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_RI_DC_B>())
        {
            FAPI_ERR("ERROR: AVS command failed for %s. Receiver Inhibit in Root Control 1 is not set!!!",
            g_rail_str[i_RailSelect]);
        }

        if (!l_data64.getBit<scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI1_DC_B>())
        {
            FAPI_ERR("ERROR: AVS command failed for %s. Driver Inhibit 1 in Root Control 1 is not set!!!",
            g_rail_str[i_RailSelect]);
        }

        if (!l_data64.getBit<scomt::proc::TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL1_TP_DI2_DC_B>())
        {
            FAPI_ERR("ERROR: AVS command failed. Driver Inhibit 2 in Root Control 1 is not set!!!",
            g_rail_str[i_RailSelect]);
        }

        if(l_rsp_data == 0x00000000)
        {
            FAPI_DBG("ERROR: AVS command failed for %s. All 0 response data received possibly due to AVSBus IO RI/DIs disabled.",
            g_rail_str[i_RailSelect]);
            FAPI_ASSERT((i_throw_assert != true),
            fapi2::PM_AVSBUS_ZERO_RESP_ERROR()
            .set_PROC_TARGET(i_target)
            .set_BUS(i_avsBusNum)
            .set_BRIDGE(i_o2sBridgeNum)
            .set_RAIL(i_RailSelect)
            .set_ROOT_CTRL1(l_data64),
            "ERROR: AVS command failed. All 0 response data received possibly due to AVSBus IO RI/DIs disabled.");
        }
        else if(l_rsp_data == 0xFFFFFFFF)
        {
            FAPI_DBG("ERROR: AVS command failed failed for %s. No response from VRM device, Check AVSBus interface connectivity to VRM in system.",
            g_rail_str[i_RailSelect]);
            FAPI_ASSERT((i_throw_assert != true),
            fapi2::PM_AVSBUS_NO_RESP_ERROR()
            .set_PROC_TARGET(i_target)
            .set_BUS(i_avsBusNum)
            .set_BRIDGE(i_o2sBridgeNum)
            .set_RAIL(i_RailSelect)
            .set_ROOT_CTRL1(l_data64),
            "ERROR: AVS command failed. No response from VRM device, Check AVSBus interface connectivity to VRM in system.");
        }
        else if(l_rsp_rcvd_crc != l_rsp_computed_crc)
        {
            FAPI_DBG("ERROR: AVS command failed for %s. Bad CRC detected by P10 on AVSBus Slave Segement.",
            g_rail_str[i_RailSelect]);
            FAPI_ASSERT((i_throw_assert != true),
            fapi2::PM_AVSBUS_MASTER_BAD_CRC_ERROR()
            .set_PROC_TARGET(i_target)
            .set_BUS(i_avsBusNum)
            .set_BRIDGE(i_o2sBridgeNum)
            .set_RAIL(i_RailSelect),
            "ERROR: AVS command failed. Bad CRC detected by P10 on AVSBus Slave Segement.");
        }
        else if(l_rsp_ack_code == 0x02)
        {
            FAPI_DBG("ERROR: AVS command failed for %s. Bad CRC indicated by Slave VRM on AVSBus Master Segement.",
            g_rail_str[i_RailSelect]);
            FAPI_ASSERT((i_throw_assert != true),
            fapi2::PM_AVSBUS_SLAVE_BAD_CRC_ERROR()
            .set_PROC_TARGET(i_target)
            .set_BUS(i_avsBusNum)
            .set_BRIDGE(i_o2sBridgeNum)
            .set_RAIL(i_RailSelect),
            "ERROR: AVS command failed. Bad CRC indicated by Slave VRM on AVSBus Master Segement.");
        }
        else if(l_rsp_ack_code == 0x01)
        {
            if (i_opType == p10avslib::VLTG_WRITE_VLTG)
            {

                FAPI_ERR("ERROR: AVS Write Voltage command problem for rail %s.  Valid data sent but no action is taken due to unavailable resource.",
                g_rail_str[i_RailSelect]);

                // Parse the Status Response for the reason.

                if (l_rsp_status.getBit<p10avslib::AVSBUS_STATRSP_STATALRT>())
                {
                    FAPI_INF("  Status indicator detected");

                    // Read the status register to find out what happened.
                    FAPI_TRY(avsStatusRead(i_target, i_avsBusNum, i_o2sBridgeNum, i_RailSelect, l_buffer));
                    l_status_data.insertFromRight<0, 32>(l_buffer);

                    // Yes, this is recursive but with a different OpType
                    FAPI_TRY(avsValidateResponse(i_target,
                    i_avsBusNum,
                    i_o2sBridgeNum,
                    i_RailSelect,
                    i_throw_assert,
                    l_goodResponse,
                    p10avslib::VLTG_READ_STAT));

                    if (!l_goodResponse)
                    {
                        FAPI_ASSERT((i_throw_assert != true),
                        fapi2::PM_AVSBUS_STATUS_READ_ERROR()
                        .set_PROC_TARGET(i_target)
                        .set_BUS(i_avsBusNum)
                        .set_BRIDGE(i_o2sBridgeNum)
                        .set_RAIL(i_RailSelect)
                        .set_COMMAND(l_command)
                        .set_RESP_DATA(l_status_data),
                        "ERROR: AVS Read Status command validation failed.");
                        FAPI_TRY(avsIdleFrame(i_target, i_avsBusNum, i_RailSelect, i_o2sBridgeNum));
                    }

                    // Parse the status for the reason.  The actual status is bits 8:12
                    if (l_status_data.getBit<p10avslib::AVSBUS_STATUS_OCW>())
                    {
                        FAPI_ERR("  Over Current Warning status detected");
                        b_over_current = true;
                    }

                    if (l_status_data.getBit<p10avslib::AVSBUS_STATUS_UVW>())
                    {
                        FAPI_ERR("  Under Voltage Warning status detected");
                        b_under_volt = true;
                    }

                    if (l_status_data.getBit<p10avslib::AVSBUS_STATUS_OTW>())
                    {

                        FAPI_ERR("  Over Temperature Warning status detected");
                        b_over_temp = true;
                    }

                    if (l_status_data.getBit<p10avslib::AVSBUS_STATUS_OPW>() )
                    {
                        FAPI_ERR("  Over Power Warning status detected");
                        b_over_power = true;
                    }
                }

                if (!(l_rsp_status.getBit<p10avslib::AVSBUS_STATRSP_AVSCTRL>()))
                {

                    FAPI_ERR("  VRM NOT controlled by AVSBus");
                    b_avs_in_control = false;
                }

                FAPI_ASSERT((i_throw_assert != true),
                            fapi2::PM_AVSBUS_WRITE_VOLTAGE_ERROR()
                            .set_PROC_TARGET(i_target)
                            .set_BUS(i_avsBusNum)
                            .set_RAIL(i_RailSelect)
                            .set_COMMAND(l_command)
                            .set_RESP_DATA(l_rsp_data)
                            .set_STATUS(l_status_data)
                            .set_AVSCTRL(b_avs_in_control)
                            .set_STATUS_ALERT(b_status_alert)
                            .set_OVERCURRENT(b_over_current)
                            .set_UNDERVOLT(b_under_volt)
                            .set_OVERTEMP(b_over_temp)
                            .set_OVERPOWER(b_over_power),
                            "ERROR: AVS Write voltage command failed due to unavailable resource. No VRM action was taken.");
            }
            else
            {
                FAPI_ASSERT((i_throw_assert != true),
                            fapi2::PM_AVSBUS_UNAVAILABLE_RESOURCE_ERROR()
                            .set_PROC_TARGET(i_target)
                            .set_BUS(i_avsBusNum)
                            .set_BRIDGE(i_o2sBridgeNum)
                            .set_RAIL(i_RailSelect)
                            .set_COMMAND(l_command)
                            .set_RESP_DATA(l_rsp_data),
                            "ERROR: AVS command failed. Valid data sent but no action is taken due to unavailable resource.");
            }

        }
        else if(l_rsp_ack_code == 0x03)
        {
            FAPI_DBG("ERROR: AVS command failed for rail %s. Unknown resource, invalid data, incorrect data or incorrect action.",
                     g_rail_str[i_RailSelect]);
            FAPI_ASSERT((i_throw_assert != true),
                        fapi2::PM_AVSBUS_INVALID_DATA_ERROR()
                        .set_PROC_TARGET(i_target)
                        .set_BUS(i_avsBusNum)
                        .set_BRIDGE(i_o2sBridgeNum)
                        .set_RAIL(i_RailSelect)
                        .set_COMMAND(l_command)
                        .set_RESP_DATA(l_rsp_data),
                        "ERROR: AVS command failed. Unknown resource, invalid data, incorrect data or incorrect action.");
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}
