/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_avsbus_lib.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file  p9_avsbus_lib.C
/// @brief Library functions for AVSBus
///
// *HW Owner    : Sudheendra K Srivathsa <sudheendraks@in.ibm.com>
// *FW Owner    : Sangeetha T S <sangeet2@in.ibm.com>
// *Team        : PM
// *Consumed by : HB
// *Level       : 2
///
/// @todo (to be considered in L2/L3 development) AVSBus timing parameters
///  as attributes or not.  They were hardcoded in P8.

#include <p9_avsbus_lib.H>
#include <p9_avsbus_registers.H>
#include <p9_ocb_firmware_registers.h>

//##############################################################################
// Function which generates a 3 bit CRC value for 29 bit data
//##############################################################################
uint32_t
avsCRCcalc(const uint32_t i_data)
{
    //Polynomial= x^3 + x^2 + 1 = 1*x^3 + 0*x^2 + 1*x^1 + 1*x^0 = divisor(1011)

    uint32_t l_crc_value = 0;
    uint32_t l_polynomial = 0xb0000000;
    uint32_t l_msb = 0x80000000;

    l_crc_value = i_data & p9avslib::AVS_CRC_DATA_MASK;

    while (l_crc_value & p9avslib::AVS_CRC_DATA_MASK)
    {
        if (l_crc_value & l_msb)
        {
            //if l_msb is 1'b1, divide by l_polynomial and shift l_polynomial
            // to the right
            l_crc_value = l_crc_value ^ l_polynomial;
            l_polynomial = l_polynomial >> 1;
        }
        else
        {
            // if l_msb is zero, shift l_polynomial
            l_polynomial = l_polynomial >> 1;
        }

        l_msb = l_msb >> 1;
    }

    return l_crc_value;
}
//##############################################################################


//##############################################################################
// Function which initializes the OCB O2S registers
//##############################################################################
fapi2::ReturnCode
avsInitExtVoltageControl(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&
                         i_target,
                         const uint8_t i_avsBusNum,
                         const uint8_t i_o2sBridgeNum)
{

    fapi2::buffer<uint64_t> l_data64;
    // if using interrupt clear ongoing in OITR1 and OIEPR0

    FAPI_TRY(putScom(i_target, OCB_OITR1,  0));  //edge
    FAPI_TRY(putScom(i_target, OCB_OIEPR0, 0));

    // O2SCTRLF
    // [ 0: 5] o2s_frame_size = 32; -> 0x20
    // [ 6:11] o2s_out_count1 = 32; -> 0x20
    // [12:17] o2s_in_delay1  =  0;     No concurrent input
    // [18:23] o2s_in_l_count1  =  X;     No input on first frame

    //uint32_t O2SCTRLF_value = 0b10000010000011111100000000000000;
    ocb_o2sctrlf0a_t O2SCTRLF_value;

    O2SCTRLF_value.fields.o2s_frame_size_an = p9avslib::O2S_FRAME_SIZE;
    O2SCTRLF_value.fields.o2s_out_count1_an = p9avslib::O2S_FRAME_SIZE;
    O2SCTRLF_value.fields.o2s_in_delay1_an = p9avslib::O2S_IN_DELAY1;

    l_data64.insertFromRight<0, 6>(O2SCTRLF_value.fields.o2s_frame_size_an);
    l_data64.insertFromRight<6, 6>(O2SCTRLF_value.fields.o2s_out_count1_an);
    l_data64.insertFromRight<12, 6>(O2SCTRLF_value.fields.o2s_in_delay1_an);

    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SCTRLF[i_avsBusNum][i_o2sBridgeNum], l_data64));
    // Note to self:  the buffer is a 32bit buffer.  make sure it is left
    // aligned for the SCOM

    // O2SCTRLS
    // [ 0: 5] o2s_out_count2  = 0;
    // [ 6:11] o2s_in_delay2   = 0;
    // [12:17] o2s_in_l_count2   = 32; -> 0x20;

    // uint32_t O2SCTRLS_value = 0b00000000000010000000000000000000;
    ocb_o2sctrls0a_t O2SCTRLS_value;
    O2SCTRLS_value.fields.o2s_in_count2_an = p9avslib::O2S_FRAME_SIZE;

    //O2SCTRLS_value.value = 0b00000000000010000000000000000000;

    l_data64.flush<0>();
    l_data64.insertFromRight<12, 6>(O2SCTRLS_value.fields.o2s_in_count2_an);

    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SCTRLS[i_avsBusNum][i_o2sBridgeNum], l_data64));

    // O2SCTRL2
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


    // uint32_t O2SCTRL1_value = 0b10000000000100000100000000000000;

    // uint32_t nest_freq;
    // FAPI_ATTR_GET(ATTR_PB_FREQ, &nest_freq);

    ocb_o2sctrl10a_t O2SCTRL1_value;
    O2SCTRL1_value.fields.o2s_bridge_enable_an = 1;
    O2SCTRL1_value.fields.o2s_clock_divider_an = 0x04;//@todo attr candidate
    O2SCTRL1_value.fields.o2s_nr_of_frames_an = 1;

//    O2SCTRL2_value.value  = 0b00000000000000000000000000000000;

    l_data64.flush<0>();
    l_data64.insertFromRight<0, 1>(O2SCTRL1_value.fields.o2s_bridge_enable_an);
    l_data64.insertFromRight<4, 10>(O2SCTRL1_value.fields.o2s_clock_divider_an);
    l_data64.insertFromRight<17, 1>(O2SCTRL1_value.fields.o2s_nr_of_frames_an);

    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SCTRL1[i_avsBusNum][i_o2sBridgeNum], l_data64));

    // O2SCTRL1
    // OCC O2S Control2
    // [ 0:16] o2s_inter_frame_delay = filled in with ATTR l_data64
    // Needs to be 10us or greater for SPIVID part operation
    // Set to ~16us for conservatism using a 100ns hang pulse
    // 16us = 16000ns -> 16000/100 = 160 = 0xA0;  aligned to 0:16 -> 0x005
    ocb_o2sctrl20a_t O2SCTRL2_value;
    O2SCTRL2_value.fields.o2s_inter_frame_delay_an = 0x0;

    l_data64.flush<0>();
    l_data64.insertFromRight<0, 17>
    (O2SCTRL2_value.fields.o2s_inter_frame_delay_an);

    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SCTRL2[i_avsBusNum][i_o2sBridgeNum], l_data64));

fapi_try_exit:
    return fapi2::current_err;
}
//##############################################################################


//##############################################################################
// Function polls OCB status register O2SST for o2s_ongoing=0
//##############################################################################
fapi2::ReturnCode
avsPollVoltageTransDone(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&
                        i_target,
                        const uint8_t i_avsBusNum,
                        const uint8_t i_o2sBridgeNum)
{
    fapi2::buffer<uint64_t> l_data64;

    uint8_t l_count = 0;

    while (l_count < p9avslib::MAX_POLL_COUNT_AVS)
    {
        FAPI_TRY(getScom(i_target, p9avslib::OCB_O2SST[i_avsBusNum]
                         [i_o2sBridgeNum], l_data64), "Error in polling ongoing bit");

        l_data64 &= 0x8000000000000000ull;

        if (l_data64 == 0)
        {
            break;  // Leave the polling loop as "ongoing" has deasserted
        }

        l_count++;
        // May put a delay (or sleep) in here to keep off of the OCI bus
    }

    // Check for timeout condition
    if (l_count >= p9avslib::MAX_POLL_COUNT_AVS)
    {

        // @todo L3:  Added Timeout FAPI2_SET_RC error point
        // This will set current_err to a non success value that can be
        // checked by the caller.

    }

fapi_try_exit:
    return fapi2::current_err;
}
//##############################################################################

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
                const uint32_t i_CmdData)
{

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint32_t> l_data64WithoutCRC;

    fapi2::ReturnCode l_rc;

    uint32_t l_StartCode = 0b01;
    uint32_t l_Reserved = 0b000;
    uint32_t l_crc;

    // clear sticky bits in o2s_status_reg
    // @todo check this register in the EPM code
    l_data64.setBit<1, 1>();
    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SCMD[i_avsBusNum][i_o2sBridgeNum], l_data64));

    //unmask pmc_o2s_ongoing in OISR1
    FAPI_TRY(getScom(i_target, OCB_OIMR1, l_data64));
    l_data64 &= p9avslib::OCB_OIMR1_MASK_VALUES[i_avsBusNum][i_o2sBridgeNum];
    FAPI_TRY(putScom(i_target, OCB_OIMR1, l_data64));

    // @todo:  double check on Endianess definition
    // compose and send frame
    //      CRC(31:29),
    //      l_Reserved(28:13) (read), CmdData(28:13) (write)
    //      RailSelect(12:9),
    //      l_CmdDataType(8:5),
    //      l_CmdGroup(4),
    //      l_CmdType(3:2),
    //      l_StartCode(1:0)
    l_data64.flush<0>();

    //l_data64 = l_data64 |
    //       (l_StartCode << 60) |
    //       (i_CmdType << 28) |
    //       (i_CmdGroup << 27) |
    //       (i_CmdDataType << 23) |
    //       (i_RailSelect << 19) |
    //       (l_Reserved << 3);
    l_data64.insertFromRight<0, 2>(l_StartCode);
    l_data64.insertFromRight<2, 2>(i_CmdType);
    l_data64.insertFromRight<4, 1>(i_CmdGroup);
    l_data64.insertFromRight<5, 4>(i_CmdDataType);
    l_data64.insertFromRight<9, 4>(i_RailSelect);
    l_data64.insertFromRight<13, 16>(i_CmdData);
    l_data64.insertFromRight<29, 3>(l_Reserved);

    l_data64.extract(l_data64WithoutCRC, 0, 32);

    // generate CRC
    l_crc = avsCRCcalc(l_data64WithoutCRC);

    l_data64.insertFromRight<29, 3>(l_crc);
    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SWD[i_avsBusNum][i_o2sBridgeNum], l_data64));

    // Wait on o2s_ongoing = 0
    FAPI_TRY(avsPollVoltageTransDone(i_target, i_avsBusNum, i_o2sBridgeNum));
    // Note:  caller will check for the specific timeout return code.

fapi_try_exit:
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
               uint32_t* o_Voltage)
{

    fapi2::buffer<uint64_t> l_data64;

    uint32_t l_CmdType     = 3; // read
    uint32_t l_CmdGroup    = 0;
    uint32_t l_CmdDataType = 0;
    uint32_t l_outboundCmdData = 0;  // @todo check the spec on this for a read

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
    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SRD[i_avsBusNum][i_o2sBridgeNum], l_data64));
    *o_Voltage = ((l_data64 >> 8) & 0x0000FFFF) >> 32;

    // @todo L3 insert SET_HWP_RC macro with FFDC
    // FFDC:
    //  i_avsBusNum
    //  i_o2sBridgeNum,
    //  i_RailSelect,
    //  l_CmdType,
    //  l_CmdGroup
    //  l_CmdDataType
    // O2S Registers (need to create in XML

fapi_try_exit:
    return fapi2::current_err;
}
//##############################################################################

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

    // Drive a Write Command
    FAPI_TRY(avsDriveCommand(i_target,
                             i_avsBusNum,
                             i_o2sBridgeNum,
                             i_RailSelect,
                             l_CmdType,
                             l_CmdGroup,
                             l_CmdDataType,
                             i_Voltage));   // @todo command data flow

    // @todo L3 insert SET_HWP_RC macro with FFDC
    // FFDC:
    //  i_avsBusNum
    //  i_o2sBridgeNum,
    //  i_RailSelect,
    //  l_CmdType,
    //  l_CmdGroup
    //  l_CmdDataType
    // O2S Registers (need to create in XML)

fapi_try_exit:
    return fapi2::current_err;
}
//##############################################################################


//##############################################################################
// Function which writes to OCB registers to initialize the AVS Slave with an
// idle frame
//##############################################################################
fapi2::ReturnCode
avsIdleFrame(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
             const uint8_t i_avsBusNum,
             const uint8_t i_o2sBridgeNum)
{
    fapi2::buffer<uint64_t> l_idleframe = 0xFFFFFFFF00000000ull;
    fapi2::buffer<uint64_t> l_scomdata;

    // clear sticky bits in o2s_status_reg
    l_scomdata.setBit<1, 1>();
    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SCMD[i_avsBusNum][i_o2sBridgeNum],
                     l_scomdata),
             "Error clearing sticky bits in o2s_status_reg");

    //unmask pmc_o2s_ongoing in OISR1
    FAPI_TRY(getScom(i_target, OCB_OIMR1, l_scomdata));
    l_scomdata &= p9avslib::OCB_OIMR1_MASK_VALUES[i_avsBusNum][i_o2sBridgeNum];
    FAPI_TRY(putScom(i_target, OCB_OIMR1, l_scomdata));

    // Send the idle frame
    l_scomdata = l_idleframe << 32;
    FAPI_TRY(putScom(i_target,
                     p9avslib::OCB_O2SWD[i_avsBusNum][i_o2sBridgeNum], l_scomdata));

    // Wait on o2s_ongoing = 0
    FAPI_TRY(avsPollVoltageTransDone(i_target, i_avsBusNum, i_o2sBridgeNum));

    // @todo L3 insert SET_HWP_RC macro with FFDC
    // FFDC:
    //  i_avsBusNum
    //  i_o2sBridgeNum,
    //  i_RailSelect,
    //  l_CmdType,
    //  l_CmdGroup
    //  l_CmdDataType
    // O2S Registers (need to create in XML

fapi_try_exit:
    return fapi2::current_err;
}
//##############################################################################
