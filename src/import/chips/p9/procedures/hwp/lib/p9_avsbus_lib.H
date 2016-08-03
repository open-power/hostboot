/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_avsbus_lib.H $      */
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
/// @file  p9_avsbus_lib.H
/// @brief Library functions for AVSBus
///
/// *HW Owner    : Sudheendra K Srivathsa <sudheendraks@in.ibm.com>
/// *FW Owner    : Sangeetha T S <sangeet2@in.ibm.com>
/// *Team        : PM
/// *Consumed by : HB
/// *Level       : 2
///
/// @todo (to be considered in L2/L3 development) AVSBus timing parameters
///  as attributes or not.  They were hardcoded in P8.

#ifndef __P9_AVSBUS_LIB_H__
#define __P9_AVSBUS_LIB_H__

#include <fapi2.H>

namespace p9avslib
{
enum avsRails
{
    VDD,
    VDN,
    VCS
};

enum avsBusNum
{
    AVSBUSVDD = 0,
    AVSBUSVDN = 1,
    AVSBUSVCS = 0
};

union avsMasterFrame
{
    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t StartCode : 2;
        uint32_t Cmd : 2;
        uint32_t CmdGroup : 1;
        uint32_t CmdDataType: 4;
        uint32_t Select : 4;
        uint32_t CmdData : 16;
        uint32_t CRC : 3;
#else
        uint32_t CRC : 3;
        uint32_t CmdData : 16;
        uint32_t Select : 4;
        uint32_t CmdDataType: 4;
        uint32_t CmdGroup : 1;
        uint32_t Cmd : 2;
        uint32_t StartCode : 2;
#endif // _BIG_ENDIAN
    } fields;
};

union avsSlaveFrame
{
    uint32_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t SlaveAck : 2;
        uint32_t reserved1 : 1;
        uint32_t StatusResp : 5;
        uint32_t CmdData : 16;
        uint32_t reserved5 : 5;
        uint32_t CRC : 3;
#else
        uint32_t CRC : 3;
        uint32_t reserved5 : 5;
        uint32_t CmdData : 16;
        uint32_t StatusResp : 5;
        uint32_t reserved1 : 1;
        uint32_t SlaveAck : 2;
#endif // _BIG_ENDIAN

    } fields;
};

union avsStatus
{
    uint16_t value;
    struct
    {
#ifdef _BIG_ENDIAN
        uint16_t VDone : 1; // Voltage done
        uint16_t OCW : 1;   // IOUT_OC_WARNING (Output over-current)
        uint16_t UCW : 1;   // VOUT_UV_WARNING (Output under-voltage)
        uint16_t OTW : 1;   // IOUT_OT_WARNING (Over-temperature)
        uint16_t OPW : 1;   // POUT_OP_WARNING (Output over-power)
        uint16_t Reserved_3 : 3;
        uint16_t MfrSpcfc_8 : 8; // Mfg Specific defined by the AVSBus Slave
#else
        uint16_t MfrSpcfc_8 : 8; // Mfg Specific defined by the AVSBus Slave
        uint16_t Reserved_3 : 3;
        uint16_t OPW : 1;   // POUT_OP_WARNING (Output over-power)
        uint16_t OTW : 1;   // IOUT_OT_WARNING (Over-temperature)
        uint16_t UCW : 1;   // VOUT_UV_WARNING (Output under-voltage)
        uint16_t OCW : 1;   // IOUT_OC_WARNING (Output over-current)
        uint16_t VDone : 1; // Voltage done
#endif // _BIG_ENDIAN
    } fields;
};

enum avslibconstants
{

// @todo:  This should be calculated based on time (eg 100ms) and the projected
// time that a SCOM poll will take.
// const uint32_t MAX_POLL_COUNT_AVS = 0x1000;
    MAX_POLL_COUNT_AVS = 0x1000,
    AVS_CRC_DATA_MASK = 0xfffffff8,
    O2S_FRAME_SIZE = 0x20,
    O2S_IN_DELAY1 = 0x3F

};

// Constant definitions
//const uint64_t O2S_FRAME_SIZE = 0x20;

// OIMR Mask Values
const uint32_t OCB_OIMR1_MASK_VALUES[2][2] =
{
    0xFFFFFBFF, //bit 21
    0xFFFFFCFF, //bit 22
    0xFFFFFBFF, //bit 23
    0xFFFFFEFF  //bit 24
};

//const uint64_t OCB_O2SST_MASK = 0x8000000000000000;

} //end of p9avslib namespace

///@brief Generates a 3 bit CRC value for 29 bit data
///@param[i] i_data
///@return   3 bit CRC result (right aligned)

uint32_t avsCRCcalc(uint32_t i_data);



///@brief Initialize an O2S bridge for AVSBus usage
///@param[i] i_target       Chip target
///@param[i] i_avsBusNum    AVSBus Number (0 or 1)
///@param[i] i_o2sBridgeNum O2S Bridge Number (0 or 1)
///@return   FAPI2::ReturnCode defined in XML

fapi2::ReturnCode
avsInitExtVoltageControl(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                         const uint8_t i_avsBusNum,
                         const uint8_t i_o2sBridgeNum);


///@brief Polls OCB status register O2SST for o2s_ongoing=0
///@param[i] i_target       Chip target
///@param[i] i_avsBusNum    AVSBus Number (0 or 1)
///@param[i] i_o2sBridgeNum O2S Bridge Number (0 or 1)
///@return   FAPI2::SUCCESS
///@return   FAPI2::RC_PROCPM_AVSBUS_TIMEOUT

fapi2::ReturnCode
avsPollVoltageTransDone(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        const uint8_t i_avsBusNum,
                        const uint8_t i_o2sBridgeNum);



///@brief Drives a downstream command to a select bus via a selected bridge
///@param[i] i_target       Chip target
///@param[i] i_avsBusNum    AVSBus Number (0 or 1)
///@param[i] i_o2sBridgeNum O2S Bridge Number (0 or 1)
///@param[i] i_RailSelect   Rail Select (value depends on the system implementation)
///@param[i] i_CmdType      Defined by AVSBus spec (4b, right justified)
///@param[i] i_CmdGroup     Defined by AVSBus spec (0 = AVSBus defined; 1 = Mfg defined)
///@param[i] i_CmdData      Defined by AVSBus spec and command dependent (16b, right justified)
///@return   FAPI2::SUCCESS
///@return   FAPI2::RC_PROCPM_AVSBUS_TIMEOUT

fapi2::ReturnCode
avsDriveCommand(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                const uint8_t  i_avsBusNum,
                const uint8_t  i_o2sBridgeNum,
                const uint32_t i_RailSelect,
                const uint32_t i_CmdType,
                const uint32_t i_CmdGroup,
                const uint32_t i_CmdDataType,
                const uint32_t i_CmdData);



///@brief Perform an AVS read transaction
///@param[i] i_target       Chip target
///@param[i] i_avsBusNum    AVSBus Number (0 or 1)
///@param[i] i_o2sBridgeNum O2S Bridge Number (0 or 1)
///@param[i] i_RailSelect   Rail Select (value depends on the system implementation)
///@param[o] o_CmdData      Defined by AVSBus spec and command dependent (16b, right justified)
///@return   FAPI2::SUCCESS
///@return   FAPI2::RC_PROCPM_AVSBUS_TIMEOUT

fapi2::ReturnCode
avsVoltageRead(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               const uint8_t i_avsBusNum,
               const uint8_t i_o2sBridgeNum,
               const uint32_t i_RailSelect,
               uint32_t* o_Voltage);


///@brief Perform an AVS write transaction
///@param[i] i_target       Chip target
///@param[i] i_avsBusNum    AVSBus Number (0 or 1)
///@param[i] i_o2sBridgeNum O2S Bridge Number (0 or 1)
///@param[i] i_RailSelect   Rail Select (value depends on the system implementation)
///@param[i] i_CmdData      Defined by AVSBus spec and command dependent (16b, right justified)
///@return   FAPI2::SUCCESS
///@return   FAPI2::RC_PROCPM_AVSBUS_TIMEOUT

fapi2::ReturnCode
avsVoltageWrite(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                const uint8_t i_avsBusNum,
                const uint8_t i_o2sBridgeNum,
                const uint32_t i_RailSelect,
                const uint32_t o_Voltage);


///@brief Drive an Idle Frame on an AVSBus
///@param[i] i_target       Chip target
///@param[i] i_avsBusNum    AVSBus Number (0 or 1)
///@param[i] i_o2sBridgeNum O2S Bridge Number (0 or 1)
///@return   FAPI2::SUCCESS

fapi2::ReturnCode
avsIdleFrame(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
             const uint8_t i_avsBusNum,
             const uint8_t i_o2sBridgeNum);


#endif  // __P9_AVSBUS_LIB_H__
