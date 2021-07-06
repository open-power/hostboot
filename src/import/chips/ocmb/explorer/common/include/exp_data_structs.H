/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/common/include/exp_data_structs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file exp_data_structs.H
/// @brief explorer data structures
///
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _EXP_DATA_STRUCTS_H_
#define _EXP_DATA_STRUCTS_H_

#include <stdint.h>

///
/// @brief Common exp data structure constants
///
enum exp_struct_sizes
{
    // SNPS PHY supports more than 1 pstate which allows it to train
    // at different DDR rates.  By saving the training results,
    // the controller can start a frequency switch protocol.
    // This would allow the PHY to quickly switch between
    // training settings of a different frequency.
    // It was deemed the PSTATE feature was not useful to Explorer so we only have 1
    MSDG_MAX_PSTATE = 1,
    CMD_PADDING_SIZE = 3,
    RSP_PADDING_SIZE = 4,
    ARGUMENT_SIZE = 28,
    SENSOR_CACHE_PADDING_SIZE_0 = 3,
    SENSOR_CACHE_PADDING_SIZE_1 = 15,

    // Constants for draminit
    DRAMINIT_NUM_ADDR_DELAYS = 8,
    OLD_DRAMINIT_STRUCTURE_VERSION = 2,
    NEW_DRAMINIT_STRUCTURE_VERSION = 3,

    // Training response constants
    TIMING_RESPONSE_2D_ARRAY_SIZE = 16,
    TRAINING_RESPONSE_NUM_RANKS = 4,
    TRAINING_RESPONSE_NUM_DRAM = 20,
    TRAINING_RESPONSE_NUM_LANES = 80,
    TRAINING_RESPONSE_NUM_RC = 27,
    TRAINING_RESPONSE_MR6_SIZE = TRAINING_RESPONSE_NUM_RANKS * TRAINING_RESPONSE_NUM_DRAM,
    RCW_8BIT_CUTOFF = 16,
    EYE_MIN_MAX_SIZE = 31,
    DBYTE_N_SIZE = 10,
    NIBBLE_N_SIZE = 20,
    BIT_N_SIZE = 8,

    // EXP_FW_ADAPTER_PROPERTIES_GET number of images
    FW_ADAPTER_MAX_FW_IMAGE = 2,

    // EXP_FW_READ_SAVED_DDR_PARAMS enums
    MAX_NUM_RANKS       = TRAINING_RESPONSE_NUM_RANKS,
    NUM_BYTES           = DBYTE_N_SIZE,
    NUM_DQ              = TRAINING_RESPONSE_NUM_LANES,
    NUM_DRAM            = TRAINING_RESPONSE_NUM_DRAM,
    NIBBLES_PER_BYTE    = 2,
};

///
/// @class host_fw_command_struct
/// @brief The host command structure
/// @note The HOST uses 64 Byte Command Information Unit (IU) for sending commands to Firmware
///
typedef struct __attribute__((packed))
{
    // Command Header
    uint8_t cmd_id;                             // Command type
    uint8_t cmd_flags;                          // Various flags associated with the command
    uint16_t request_identifier;                // The request identifier of this transport request
    uint32_t cmd_length;                        // Number of bytes following the UI header
    uint32_t cmd_crc;                           // CRC of command data buffer, if used
    uint32_t host_work_area;                    // Scratchpad area for Host, FW returns this value as a reponse
    uint32_t cmd_work_area;                     // Scratchpad area for Firmware, can be used for tracking command progress etc.
    uint32_t padding[CMD_PADDING_SIZE];         // Fill up to the size of one cache line
    uint8_t command_argument[ARGUMENT_SIZE];    // Additional parameters associated with the command
    uint32_t cmd_header_crc;                    // CRC of 64 bytes of command header
}
host_fw_command_struct;


///
/// @class host_fw_response_struct
/// @brief The firmware response structure
/// @note The Firmware uses 64 Byte Response Information Unit (IU) for sending responses to HOST
///
typedef struct __attribute__((packed))
{
    // Response Header
    uint8_t  response_id;                      // Response ID - same as Command ID
    uint8_t  response_flags;                   // Various flags associated with the response
    uint16_t request_identifier;               // The request identifier of this transport request
    uint32_t response_length;                  // Number of bytes following the response header
    uint32_t response_crc;                     // CRC of response data buffer, if used
    uint32_t host_work_area;                   // Scratchpad area for Host, FW returns this value as a reponse
    uint32_t padding[RSP_PADDING_SIZE];         // Fill up to the size of one cache line
    uint8_t  response_argument[ARGUMENT_SIZE]; // Additional parameters associated with the response
    uint32_t response_header_crc;              // CRC of 64 bytes of reponse header
}
host_fw_response_struct;


///
/// @class user_input_msdg_upto_ver397559
/// @brief PHY initialization parameters
/// @note PHY FW module requires certain parameters from HOST software
/// @note This response is valid for FW version up to 397559
///
typedef struct __attribute__((packed)) user_input_msdg_upto_ver397559
{
    uint32_t version_number;

    // Choose the Dimm type from one of below:
    // 0 = UDIMM
    // 1 = RDIMM
    // 2 = LRDIMM (invalid for explorer)
    // 3 = MDS-LRDIMM
    // 4 = MDS
    uint16_t DimmType;

    // Indicates presence of DRAM at each chip select for PHY. Each
    // bit corresponds to a logical CS.
    // If the bit is set to 1, the CS is connected to DRAM.
    // If the bit is set to 0, the CS is not connected to DRAM.
    //
    // CsPresent[0] = CS0 is populated
    // CsPresent[1] = CS1 is populated
    // CsPresent[2] = CS2 is populated // Rank4Mode is 1)
    // CsPresent[3] = CS3 is populated // Rank4Mode is 1)
    uint16_t CsPresent;

    // Enter 4,8,16 depending on protocol and dram type.
    // See below for legal types for each protocol.
    // DDR4   4:X4, 8:X8, 16:X16 -- default = X8
    uint16_t DramDataWidth;

    // Enter 0,2,4 depending on 3Ds Stack
    // See below for legal types
    // 0 = Planar
    // 2 = H2
    // 4 = H4
    // 8 = H8
    uint16_t Height3DS;

    // [9:0] each bit to enables one DBYTPE macro
    // 1 = Enable DBYTE macro
    // 0 = Disable DBYTE macro (clock gating and IO tri-state)
    uint16_t ActiveDBYTE;

    // [19:0] each bit to enables one X4 nibble. This field is only
    // valid for X4 DRAMs
    // 1 = Account training/dfi_bist result on the selected nibble.
    // 0 = Ignore training/dfi_bist result on the selected nibble.
    uint32_t ActiveNibble;

    // Byte offset 0x13, CSR Addr 0x54009, Direction=In
    // Corresponds to CS[3:0]
    // 1 = Address Mirror.
    // 0 = No Address Mirror.
    uint16_t AddrMirror;

    // DRAM Column Addr Width (Valid value: 10)
    uint16_t ColumnAddrWidth;

    // DRAM Row Addr Width (Valid value: 14,15,16,17,18)
    uint16_t RowAddrWidth;

    // Cas Latency Supported by DRAM (from DDR4 SPD Byte 20~21)
    // SpdCLSupported0[7:0] = CL14~CL7
    // SpdCLSupported0[15:8] = CL22~CL16
    // SpdCLSupported1[23:16] = CL24~CL23
    // SpdCLSupported1[31:24] = Reserved
    uint32_t SpdCLSupported;


    // Minimum Cas Latency Time (tAAmin) in Picosecond (Byte 24)
    // examples: DDR4-2400P = 12500 ps
    // DDR4-2400R = 13320 ps
    // DDR4-2400U = 15000 ps
    uint16_t SpdtAAmin;

    // Operate PHY in 4-rank mode.
    // when enabled, A-side CA bus
    // drives rank 2/3, DQ/DQS bus
    // 1 = 4-rank mode
    // 0 = Normal mode (2-rank);
    uint16_t Rank4Mode;

    // Operate PHY in Encoded QuadCs Mode (only valid for
    // RDIMM/RLDIMM) (NOT Supported in Explorer) when enabled,
    // each CA bus drives one RCD in Encoded QuadCs mode.
    // {cid_a/b[0],csn_a/b[1:0]} are connected to {DC0,DCS1_n,DCS0_n}
    // to select master ranks. cid_a/b[1] is connected to DC2 to
    // select up to 2 logic ranks (2H 3DStack)
    // 1 = Encoded QuadCs Mode
    // 0 = Direct DualCs Mod
    uint16_t EncodedQuadCs;

    // Support 1rank 3DS Device in
    // 1 = 1 rank 3DS in DDP board
    // PHY are connected to c[0],c[1],c[2] of DRAM);
    // 0 = Normal Mode (cid[0],cid[1] of PHY are connected
    // c[0],c[1] of DRAM, c[2] of DRAM ties to ground);
    uint16_t DDPCompatible;

    // Support 8H 3DS routing in board routing when pairty
    // disabled.
    // 1 = Support DDR4 3DS 8H DRAM (caparity is connected
    // to c[2] of DRAM);
    // 0 = Normal Mode (caparity is connected to PAR of DRAM or
    // DPAR of RCD);
    uint16_t TSV8HSupport;

    // Support timing parameters of Everspin MRAM.
    // 1 = Support Everspin DDR4 MRAM;
    // 0 = Normal DDR4 DRAM;
    uint16_t MRAMSupport;


    // 1 = Support MDS 8H DRAM (odt[1] is connected to c[2] of
    // MDS DRAM);
    // 0 = Normal Mode;
    uint16_t MDSSupport;

    // Number of p-states used
    // Always set NumPStates to 1 for Explorer.
    // For the fields with Pstate array, only need to fill [0] entry.
    uint16_t NumPStates;

    // Memclk frequency in MHz -- round up to next highest
    // integer. Enter 334 for 333.333, etc.
    // examples: DDR4-3200 = 1600
    //           DDR4-2933 = 1467
    //           DDR4-2666 = 1333
    // [0] - P0 pstate Memclk frequency in MHz
    // [1] - P1 pstate Memclk frequency in MHz
    // [2] - P2 pstate Memclk frequency in MHz
    // [3] - P3 pstate Memclk frequency in MHz -- round up to next
    // highest integer. Enter 334 for 333.333, etc.
    uint16_t Frequency[MSDG_MAX_PSTATE];

    // Enter desired ODT impedance for DQ/DQS in Ohm for each pstates
    // Enter 0 for high-impedance
    // Valid values for DDR4 = 240, 120, 80, 60, 40, 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t PhyOdtImpedance[MSDG_MAX_PSTATE];

    // Tx Pull-up Drive Impedance for DQ/DQS in ohm for each pstates
    // Valid values = 480,240,160,120, 96,80,68, 60,53,48,43,40,
    // 36,34,32,30,28
    // [0] - Impedance in Ohm for P0
    // [1] - Impedance in Ohm for P1
    // [2] - Impedance in Ohm for P2
    // [3] - Impedance in Ohm for P3
    uint16_t PhyDrvImpedancePU[MSDG_MAX_PSTATE];

    // Tx Pull-up Drive Impedance for DQ/DQS in ohm for each pstates
    // Valid values = 480,240,160,120, 96,80,68, 60,53,48,43,40,
    // 36,34,32,30,28
    // [0] - Impedance in Ohm for P0
    // [1] - Impedance in Ohm for P1
    // [2] - Impedance in Ohm for P2
    // [3] - Impedance in Ohm for P3
    uint16_t PhyDrvImpedancePD[MSDG_MAX_PSTATE];

    // Enter desired slew rate setting for DQ/DQS for each pstates
    // Valid values = 0~15 (TBD)
    // [0] - Slew rate in Ohm for P0
    // [1] - Slew rate in Ohm for P1
    // [2] - Slew rate in Ohm for P2
    // [3] - Slew rate in Ohm for P3
    uint16_t PhySlewRate[MSDG_MAX_PSTATE];

    // Tx Drive Impedance for address/control bus in ohm
    // Valid values = 120, 60, 40, 30, 24, 20
    uint16_t ATxImpedance;

    // Enter desired slew rate setting for address/control bus
    // Valid values = 0~15 (TBD)
    uint16_t ATxSlewRate;

    // Tx Drive Impedance for CK bus in ohm
    // Valid values = 120, 60, 40, 30, 24, 20
    uint16_t CKTxImpedance;

    // Enter desired slew rate setting for CK bus
    // Valid values = 0~15 (TBD)
    uint16_t CKTxSlewRate;

    // Enter desired ODT Impedance for alert_n
    // Enter 0 for high-impedance
    // Valid values for DDR4 = 240, 120, 80,
    // 0(Disabled)
    uint16_t AlertOdtImpedance;

    // Enter desired RttNom of Rank0 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4
    // 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttNomR0[MSDG_MAX_PSTATE];

    // Enter desired RttNom of Rank1 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4
    // 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttNomR1[MSDG_MAX_PSTATE];

    // Enter desired RttNom of Rank2 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4
    // 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttNomR2[MSDG_MAX_PSTATE];

    // Enter desired RttNom of Rank3 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4
    // 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttNomR3[MSDG_MAX_PSTATE];

    // Enter desired RttWr of Rank0 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4 = 240, 120,
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttWrR0[MSDG_MAX_PSTATE];

    // Enter desired RttWr of Rank1 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4   = 240, 120,
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttWrR1[MSDG_MAX_PSTATE];

    // Enter desired RttWr of Rank2 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4 = 240, 120,
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttWrR2[MSDG_MAX_PSTATE];

    // Enter desired RttWr of Rank3 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4 = 240, 120,
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttWrR3[MSDG_MAX_PSTATE];

    // Enter desired RttPark of Rank0 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4 = 240, 120, 80,
    // 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttParkR0[MSDG_MAX_PSTATE];

    // Enter desired RttPark of Rank1 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4
    // 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttParkR1[MSDG_MAX_PSTATE];

    // Enter desired RttPark of Rank2 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4
    // 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttParkR2[MSDG_MAX_PSTATE];

    // Enter desired RttPark of Rank3 in Ohm
    // Enter 0 for high-impedance
    // Valid values for DDR4 = 240, 120, 80, 60, 48, 40, 34,
    // 0(Disabled)
    // [0] - ODT in Ohm for P0
    // [1] - ODT in Ohm for P1
    // [2] - ODT in Ohm for P2
    // [3] - ODT in Ohm for P3
    uint16_t DramRttParkR3[MSDG_MAX_PSTATE];

    // Tx Drive Impedance for DQ/DQS of all ranks in ohm
    // Valid values for all DramType = 48, 34
    // [0] - Impedance in Ohm for P0
    // [1] - Impedance in Ohm for P1
    // [2] - Impedance in Ohm for P2
    // [3] - Impedance in Ohm for P3
    uint16_t DramDic[MSDG_MAX_PSTATE];

    // Write Preamble setting for DRAM (MR4)
    // 0 = 1 nCK; 1 = 2 nCK;(only available at DDR4 2400~3200)
    // [0] - Write Preamble setting for P0
    // [1] - Write Preamble setting for P1
    // [2] - Write Preamble setting for P2
    // [3] - Write Preamble setting for P3
    uint16_t DramWritePreamble[MSDG_MAX_PSTATE];

    // Read Preamble setting for DRAM (MR4)
    // 0 = 1 nCK; 1 = 2 nCK;
    // [0] - Read Preamble setting for P0
    // [1] - Read Preamble setting for P1
    // [2] - Read Preamble setting for P2
    // [3] - Read Preamble setting for P3
    uint16_t DramReadPreamble[MSDG_MAX_PSTATE];

    // Control DFE of DQ/DQS receiver and FFE of DQ/DQS driver
    // PhyEqualization[0] =1: Enable Receiver DFE; = 0:
    // Disable Receiver DFE
    // PhyEqualization[1] = 0: Enable Driver FFE; = 0:
    // Disable Driver FFE
    uint16_t PhyEqualization[MSDG_MAX_PSTATE];

    // Initial VrefDQ (MR6)
    // InitVrefDQ[6] = VrefDQ training range (same as MR6[6])
    // InitVrefDQ[5:0] = VrefDQ training value (same as MR6[5:0])
    // For example, 0x17 -> 74.9%, 0x0f -> 69.75%, 0x9-> 65.85%
    uint16_t InitVrefDQ[MSDG_MAX_PSTATE];


    // Initial DQ Vref setting of PHY before training
    // Receiver Vref = VDDQ*PhyVref[6:0]/128
    // For example, 0x60 = 75% * VDDQ
    uint16_t InitPhyVref[MSDG_MAX_PSTATE];

    // Enter desired ODT[3:0] value when writing to ranks
    // in normal mode (2 rank)
    // OdtWrMapCs BIT [1:0] ODT_A/B[1:0] value when writing to rank 0
    // OdtWrMapCs BIT [5:4] ODT_A/B[1:0] value when writing to rank 1
    // If EncodedQuadCs = 1
    // OdtWrMapCs BIT [1:0] ODT_A/B[1:0] value when writing to rank 0
    // OdtWrMapCs BIT [5:4] ODT_A/B[1:0] value when writing to rank 1
    // OdtWrMapCs BIT [9:8] ODT_A/B[1:0] value when writing to rank 2
    // OdtWrMapCs BIT [13:12] ODT_A/B[1:0] value when writing to rank 3
    // If Rank4Mode = 1
    // OdtWrMapCs BIT [1:0] ODT_A[1:0] value when writing to rank 0
    // OdtWrMapCs BIT [3:2] ODT_B[1:0] value when writing to rank 0
    // OdtWrMapCs BIT [5:4] ODT_A[1:0] value when writing to rank 1
    // OdtWrMapCs BIT [7:6] ODT_B[1:0] value when writing to rank 1
    // OdtWrMapCs BIT [9:8] ODT_A[1:0] value when writing to rank 2
    // OdtWrMapCs BIT [11:10] ODT_B[1:0] value when writing to rank 2
    // OdtWrMapCs BIT [13:12] ODT_A[1:0] value when writing to rank 3
    // OdtWrMapCs BIT [15:14] ODT_B[1:0] value when writing to rank 3
    uint16_t OdtWrMapCs[MSDG_MAX_PSTATE];

    // Enter desired ODT[3:0] value when reading from ranks
    // in normal mode (2 rank)
    // OdtRdMapCs BIT [1:0] ODT_A/B[1:0] value when reading from rank 0
    // OdtRdMapCs BIT [5:4] ODT_A/B[1:0] value when reading from rank 1
    // If EncodedQuadCs = 1
    // OdtRdMapCs BIT [1:0] ODT_A/B[1:0] value when reading from rank 0
    // OdtRdMapCs BIT [5:4] ODT_A/B[1:0] value when reading from rank 1
    // OdtRdMapCs BIT [9:8] ODT_A/B[1:0] value when reading from rank 2
    // OdtRdMapCs BIT [13:12] ODT_A/B[1:0] value when reading from rank 3
    // If Rank4Mode = 1
    // OdtRdMapCs BIT [1:0] ODT_A[1:0] value when reading from rank 0
    // OdtRdMapCs BIT [3:2] ODT_B[1:0] value when reading from rank 0
    // OdtRdMapCs BIT [5:4] ODT_A[1:0] value when reading from rank 1
    // OdtRdMapCs BIT [7:6] ODT_B[1:0] value when reading from rank 1
    // OdtRdMapCs BIT [9:8] ODT_A[1:0] value when reading from rank 2
    // OdtRdMapCs BIT [11:10] ODT_B[1:0] value when reading from rank 2
    // OdtRdMapCs BIT [13:12] ODT_A[1:0] value when reading from rank 3
    // OdtRdMapCs BIT [15:14] ODT_B[1:0] value when reading from rank 3
    uint16_t OdtRdMapCs[MSDG_MAX_PSTATE];

    // Enable geardown mode during training/dfi_bist.
    // 0 = 1/2 Rate; 1 = 1/4 Rate;
    // [0] - Geardown value for P0
    // [1] - Geardown value for P1
    // [2] - Geardown value for P2
    // [3] - Geardown value for P3
    uint16_t Geardown[MSDG_MAX_PSTATE];


    // Value of RCD parity checking & Command Latency Adder
    // (F0RC0E, FORC0F)
    // 0 = 0nCK latency adder, parity disabled;
    // 1 = 1nCK latency adder;
    // 2 = 2nCK latency adder;
    // 3 = 3nCK latency adder;
    // 4 = 4nCK latency adder;
    // [0] - CALatencyAdder value for P0
    // [1] - CALatencyAdder value for P1
    // [2] - CALatencyAdder value for P2
    // [3] - CALatencyAdder value for P3
    uint16_t CALatencyAdder[MSDG_MAX_PSTATE];


    // Value of CS to CMD/ADDR Latency mode (MR4.CAL) for dfi_bist
    // (training runs with CALMode = 0)
    // Valid value: 0,3,4,5,6,8
    // [0] - BistCALMode value for P0
    // [1] - BistCALMode value for P1
    // [2] - BistCALMode value for P2
    // [3] - BistCALMode value for P3
    uint16_t BistCALMode[MSDG_MAX_PSTATE];

    // Value of CA Parity Latency mode (MR5.PL) for dfi_bist
    // (training runs with CAParityLatency = 0)
    // Valid value: 0,4,5,6,8
    // [0] - BistCAParityLatency for P0
    // [1] - BistCAParityLatency for P1
    // [2] - BistCAParityLatency for P2
    // [3] - BistCAParityLatency for P3
    uint16_t BistCAParityLatency[MSDG_MAX_PSTATE];

    // F0RC03[3:0], F0RC04[3:0], F0RC05[3:0] CA and CS signal Driver
    // Characteristics
    // [1:0] QxA,QxBA,QxBG...: =00 light; =01 moderate; =10 strong;
    // =11 very strong
    // [3:2] QxCSx_n: =00 light; =01 moderate; =10 strong; =11 very
    // strong
    // [5:4] QxODT: =00 light; =01 moderate; =10 strong; =11 very
    // strong
    // [7:6] QxCKE: =00 light; =01 moderate; =10 strong; =11 very
    // strong
    // [9:8] Y1/Y3(A side): =00 light; =01 moderate; =10 strong; =11
    // very strong
    // [11:10] Y0/Y2(B side): =00 light; =01 moderate; =10 strong;
    // =11 very strong
    uint16_t RcdDic[MSDG_MAX_PSTATE];

    // RCD operating voltage VDD and VrefCA control
    // RcdVoltageCtrl[3:0] F0RC0B;
    // RcdVoltageCtrl[11:4] F0RC1x;
    uint16_t RcdVoltageCtrl[MSDG_MAX_PSTATE];

    // RCD IBT Control Word (F0RC7x)
    // RcdIBTCtrl[1:0] CA Input Bus Termination
    // RcdIBTCtrl[3:2] DCS[3:0]_n Input Bus Termination // RcdIBTCtrl[5:4] DCKE Input Bus Termination
    // RcdIBTCtrl[7:6] DODT Input Bus Termination
    uint16_t RcdIBTCtrl[MSDG_MAX_PSTATE];

    // RCD Data Buffer Interface Driver Characteristics (F1RC00)
    // RcdDBDic[0] BCOM[3:0],BODT,BCKE, driver strength
    // RcdDBDic[1] Reserved
    // RcdDBDic[2] BCK_t/BCK_c driver strength
    // RcdDBDic[3] Reserved
    uint16_t RcdDBDic[MSDG_MAX_PSTATE];

    // RCD slew rate control (F1RC02,F1RC03,F1RC04,F1RC05)
    // RcdSlewRate[1:0] slew rate control of address/command
    // RcdSlewRate[3:2] slew rate control of QxCs*_n
    // RcdSlewRate[5:4] slew rate control of QxODT*
    // RcdSlewRate[7:6] slew rate control of QxCKE*
    // RcdSlewRate[9:8] slew rate control of Y1_t/c, Y3_t/c
    // RcdSlewRate[11:10] slew rate control of Y0_t/c, Y2_t/c
    // RcdSlewRate[13:12] slew rate control of BCOM[3:0], BODT, BCKE // RcdSlewRate[15:14] slew rate control of BCK_t/c
    uint16_t RcdSlewRate[MSDG_MAX_PSTATE];

    // DFIMRL_DDRCLK: Max Read Latency counted by DDR Clock.
    // dfi_rddata is returned (14 + DFIMRL_DDRCLK) cycles after
    // dfi_rddata_en is asserted.
    uint16_t DFIMRL_DDRCLK;

    //ATxDly_A/B[0]: ODT[1],ODT[0],CS_N[0],CS_N[1]
    //ATxDly_A/B[1]: ADDR[13],ADDR[5],BG[0],CKE[1]
    //ATxDly_A/B[2]: ADDR[17],ADDR[7],BA[0],ADDR[16]
    //ATxDly_A/B[3]: ADDR[8],BG[1],CID[1],CID[0]
    //ATxDly_A/B[4]: ADDR[1],ADDR[9],ADDR[2],CAPARITY
    //ATxDly_A/B[5]: ADDR[12],ADDR[3],ADDR[4],ADDR[0]
    //ATxDly_A/B[6]: CKE[0],ADDR[15],ACT_N,ADDR[10]
    //ATxDly_A/B[7]: ADDR[11],ADDR[6],BA[1],ADDR[14]
    //7bit A-side AC Delay
    //ATxDly_A[pstate][NumAnib]
    uint8_t  ATxDly_A[MSDG_MAX_PSTATE][DRAMINIT_NUM_ADDR_DELAYS];
    //7bit B-side AC Delay
    //ATxDly_B[pstate][NumAnib]
    uint8_t  ATxDly_B[MSDG_MAX_PSTATE][DRAMINIT_NUM_ADDR_DELAYS];
} user_input_msdg_upto_ver397559_t;

///
/// @class user_input_msdg
/// @brief PHY initialization parameters
/// @note PHY FW module requires certain parameters from HOST software
/// @note This response is valid for FW version after 397559
///
typedef struct __attribute__((packed)) user_input_msdg
{
    user_input_msdg_upto_ver397559_t iv_user_msdg_upto_ver397559;

    uint8_t F1RC1x;     // RCD control word F1RC1x. only available for RDIMM.
    uint8_t F1RC2x;     // RCD control word F1RC2x. only available for RDIMM.
    uint8_t F1RC3x;     // RCD control word F1RC3x. only available for RDIMM.
    uint8_t F1RC4x;     // RCD control word F1RC4x. only available for RDIMM.
    uint8_t F1RC5x;     // RCD control word F1RC5x. only available for RDIMM.
    uint8_t F1RC6x;     // RCD control word F1RC6x. only available for RDIMM.
    uint8_t F1RC7x;     // RCD control word F1RC7x. only available for RDIMM.

} user_input_msdg_t;

///
/// @class sensor_cache_struct
/// @brief The sensor cache structure
/// @note The data in the sensor cache is returned in 2 32-byte packets
///
typedef struct __attribute__((packed))
{
    /*
     * Packet 0
     */
    // Responses
    // status[0] OCMB Onchip DTS Error Bit
    // status[1] OCMB Onchip DTS Valid Bit
    // status[2] OCMB Onchip DTS Present Bit
    // status[3] MEM DTS0 Error Bit
    // status[4] MEM DTS0 Valid Bit
    // status[5] MEM DTS0 Present Bit
    // status[6] MEM DTS1 Error Bit
    // status[7] MEM DTS1 Valid Bit
    // status[8] MEM DTS1 Present Bit
    // status[9] Event Bit
    // status[10] Initial Packet0 ('1' on first packet0 return, otherwise '0')
    // status[11:15] Reserved
    uint16_t status;

    uint16_t ocmb_dts;          // On chip thermal sensor
    uint16_t mem_dts0;          // External DIMM thermal sensor 0
    uint16_t mem_dts1;          // External DIMM thermal sensor 1
    uint32_t mba_reads;         // The number of reads that the sequencer has seen; wraps
    uint32_t mba_writes;        // The number of writes that the sequencer has seen; wraps
    uint32_t mba_activations;   // The number of bank activates seen; wraps
    uint32_t mba_powerups;      // Counts the number of rising edges for a CKE; wraps
    uint8_t self_timed_refresh; // The number of times that the sequencer exited self-timed refresh
    uint8_t reserved0[SENSOR_CACHE_PADDING_SIZE_0];
    uint32_t frame_count;       // Free running counter that is used as denominator for performance counts

    /*
     * Packet 1
     */
    uint32_t mba_arrival_histo_base; // Increments every MBA Idle Cycle
    uint32_t mba_arrival_histo_low;  // Counts the number of times the low idle threshold was met
    uint32_t mba_arrival_histo_med;  // Counts the number of times the med idle threshold was met
    uint32_t mba_arrival_histo_high; // Counts the number of times the high idle threshold was met
    uint8_t initial_packet1;         // initial_packet1[0] '1' on first packet1 return, otherwise '0'
    //                               // initial_packet1[1:7] Reserved
    uint8_t reserved1[SENSOR_CACHE_PADDING_SIZE_1];
}
sensor_cache_struct;


///
/// @class user_response_timing_msdg_t
/// @brief Contains the command to command timing training results
///
typedef struct __attribute__((packed)) user_response_timing_msdg
{
    uint16_t DFIMRL_DDRCLK_trained; // Training result of DFIMRL_DDRCLK parameter (by mrlTraining step).
    // DFIMRL_DDRCLK: Max Read Latency counted by DDR Clock. dfi_rddata is returned (14 + DFIMRL_DDRCLK) cycles after dfi_rddata_en is asserted.
    //DFI rank-to rank space timing must be determined by the actual board delay (DQ/DQS bus turnarounds).
    //PHY firmware training result provide CDD (critical delay difference) information to help to calculate the minimum required timing spacing for memory controllers.
    //Minimal possible gap between rank-to-rank read-read transaction is defined by tCCDmin(R_rank[i], R_rank[j]) = 4 + max(abs(CDD_RR_[i]_[j]));
    int8_t   CDD_RR[TRAINING_RESPONSE_NUM_RANKS][TRAINING_RESPONSE_NUM_RANKS];      // CDD_RR[n][m]: This is a signed integer value. Read to read critical delay difference from cs n to cs m
    // CDD_RR[0][0], CDD_RR[1][1], CDD_RR[2][2], CDD_RR[3][3] are always 0;
    //Minimal possible gap between rank-to-rank write-write transaction is defined by tCCDmin(W_rank[i], W_rank[j]) = 4 + max(abs(CDD_WW_[i]_[j]));
    int8_t   CDD_WW[TRAINING_RESPONSE_NUM_RANKS][TRAINING_RESPONSE_NUM_RANKS];      // CDD_WW[n][m]: This is a signed integer value. Write to write critical delay difference from cs n to cs m
    // CDD_WW[0][0], CDD_WW[1][1], CDD_WW[2][2], CDD_WW[3][3] are always 0;
    //Minimal possible gap between rank-to-rank read-write transaction is defined by tCCDmin(R_rank[i], W_rank[j]) = (RL + BL/2 + 1 + WR_PREAMBLE - WL) + max(abs(CDD_RW_[i]_[j]));
    //RL: Read Latency; WL: Write Latency; BL: Burst Length; WR_PREAMBLE: Write Preamble cycles
    int8_t   CDD_RW[TRAINING_RESPONSE_NUM_RANKS][TRAINING_RESPONSE_NUM_RANKS];      // CDD_RW[n][m]This is a signed integer value. Read to write critical delay difference from cs 3 to cs 3
    //Minimal possible gap between rank-to-rank write-read transaction is defined by tCCDmin(W_rank[i], R_rank[j]) = (WL + PL + BL/2 + tWTR_L) + max(abs(CDD_RW_[i]_[j]));
    //WL: Write Latency; BL: Burst Length; PL: CA Parity Latency; tWTR_L: delay from internal write to internal read for same bank group
    int8_t   CDD_WR[TRAINING_RESPONSE_NUM_RANKS][TRAINING_RESPONSE_NUM_RANKS];      // CDD_WR[n][m]This is a signed integer value. Write to read critical delay difference from cs 3 to cs 3
} user_response_timing_msdg_t;

///
/// @class user_response_error_msdg
/// @brief Contains the lane failure results
///
typedef struct __attribute__((packed)) user_response_error_msdg
{
    uint16_t Failure_Lane[TRAINING_RESPONSE_NUM_LANES]; // error code of DQ[n] on Rank 3,2,1 & 0. Rank 0 is in LS Nibble.
    //Failure status of training. Each uint16_t field contains the training error code of all 4 ranks on 1 DQ lane.
    //4-bit error code reports the training errors:
    //0x0: No Error
    //0x1: DevInit Error
    //0x2: RxEnable Error
    //0x3: Find Write Leveling Error
    //0x4: Read Deskew Error
    //0x5: Read 1D SI Friendly Training Error
    //0x6: Coarse Write Leveling Error
    //0x7: Write 1D Training Error
    //0x8: Read 1D Traiing Error
    //0x9: Read Latency Training Error
    //0xA~0xF: Reserved
} user_response_error_msdg_t;

///
/// @class user_response_mrs_msdg_t
/// @brief MRS response structure
///
typedef struct __attribute__((packed)) user_response_mrs_msdg_t
{
    uint16_t MR0;               // Value of DDR mode register MR0 for all ranks, all devices
    uint16_t MR1[TRAINING_RESPONSE_NUM_RANKS];            // Value of DDR mode register MR1 for each rank (up to 4 ranks)
    uint16_t MR2[TRAINING_RESPONSE_NUM_RANKS];            // Value of DDR mode register MR2 for each rank (up to 4 ranks)
    uint16_t MR3;               // Value of DDR mode register MR3 for all ranks, all devices
    uint16_t MR4;               // Value of DDR mode register MR4 for all ranks, all devices
    uint16_t MR5[TRAINING_RESPONSE_NUM_RANKS];            // Value of DDR mode register MR5 for each rank (up to 4 ranks)
    uint16_t MR6[TRAINING_RESPONSE_NUM_RANKS][TRAINING_RESPONSE_NUM_DRAM];        // Value of DDR mode register MR6 for each nibble on each rank
    // for X8,X16 DRAMs MR6[i][2n+1] = MR6[i][2n] (n = 0~9)
} user_response_mrs_msdg_t;

///
/// @class user_response_rc_msdg_t
/// @brief RCD response structure
///
typedef struct __attribute__((packed)) user_response_rc_msdg_t
{
    uint8_t   F0RC_D0[TRAINING_RESPONSE_NUM_RC];      // RCD control words for DIMM0; Invalid for UDIMM
    // F0RC_D0[15:0] BIT [3:0]: 4-bit value of F0RC00~F0RC0F
    // F0RC_D0[26:16] BIT [7:0]: 8-bit value of F0RC1x~F0RCBx
    uint8_t   F1RC_D0[TRAINING_RESPONSE_NUM_RC];      // RCD control words for DIMM0; Invalid for UDIMM
    // F1RC_D0[15:0] BIT [3:0]: 4-bit value of F1RC00~F1RC0F
    // F1RC_D0[26:16] BIT [7:0]: 8-bit value of F1RC1x~F1RCBx
    uint8_t   F0RC_D1[TRAINING_RESPONSE_NUM_RC];      // RCD control words for DIMM1; Invalid for UDIMM
    // F0RC_D0[15:0] BIT [3:0]: 4-bit value of F0RC00~F0RC0F
    // F0RC_D0[26:16] BIT [7:0]: 8-bit value of F0RC1x~F0RCBx
    uint8_t   F1RC_D1[TRAINING_RESPONSE_NUM_RC];      // RCD control words for DIMM1; Invalid for UDIMM
    // F1RC_D0[15:0] BIT [3:0]: 4-bit value of F1RC00~F1RC0F
    // F1RC_D0[26:16] BIT [7:0]: 8-bit value of F1RC1x~F1RCBx
} user_response_rc_msdg_t;

///
/// @class user_response_mds_rc_msdg_t
/// @brief MDS explorer response structure
///
typedef struct __attribute__((packed)) user_response_mds_rc_msdg
{
    uint8_t  F0RC00;
    uint8_t  F0RC01;
    uint8_t  F0RC02;
    uint8_t  F0RC03;
    uint8_t  F0RC04;
    uint8_t  F0RC05;
    uint8_t  F0RC06;
    uint8_t  F0RC07;
    uint8_t  F0RC08;
    uint8_t  F0RC09;
    uint8_t  F0RC0A;
    uint8_t  F0RC0B;
    uint8_t  F0RC0C;
    uint8_t  F0RC0D;
    uint8_t  F0RC0E;
    uint8_t  F0RC0F;
    uint8_t  F0RC1x;
    uint8_t  F0RC2x;
    uint8_t  F0RC3x;
    uint8_t  F0RC4x;
    uint8_t  F0RC5x;
    uint8_t  F0RC6x;
    uint8_t  F0RC7x;
    uint8_t  F0RC8x;
    uint8_t  F0RC9x;
    uint8_t  F0RCAx;
    uint8_t  F0RCBx;
    uint8_t  F1RC00;
    uint8_t  F1RC01;
    uint8_t  F1RC02;
    uint8_t  F1RC03;
    uint8_t  F1RC04;
    uint8_t  F1RC05;
    uint8_t  F1RC06;
    uint8_t  F1RC07;
    uint8_t  F1RC08;
    uint8_t  F1RC09;
    uint8_t  F1RC0A;
    uint8_t  F1RC0B;
    uint8_t  F1RC0C;
    uint8_t  F1RC0D;
    uint8_t  F1RC0E;
    uint8_t  F1RC0F;
    uint8_t  F1RC1x;
    uint8_t  F1RC2x;
    uint8_t  F1RC3x;
    uint8_t  F1RC4x;
    uint8_t  F1RC5x;
    uint8_t  F1RC6x;
    uint8_t  F1RC7x;
    uint8_t  F1RC8x;
    uint8_t  F1RC9x;
    uint8_t  F1RCAx;
    uint8_t  F1RCBx;
    uint8_t  F2RC00;
    uint8_t  F2RC01;
    uint8_t  F2RC02;
    uint8_t  F2RC03;
    uint8_t  F3RC00;
    uint8_t  F3RC01;
    uint8_t  F3RC09;
    uint8_t  F3RC0A;
    uint8_t  F3RC0B;
    uint8_t  F3RC0C;
    uint8_t  F3RC0D;
    uint8_t  F3RC0F;
    uint8_t  F3RC1x;
    uint8_t  F3RC2x;
    uint8_t  F3RC3x;
    uint8_t  F3RC4x;
    uint8_t  F3RC5x;
    uint8_t  F3RC6x;
    uint8_t  F3RC7x;
    uint8_t  F3RC8x;
    uint8_t  F3RC9x;
    uint8_t  F3RCAx;
    uint8_t  F3RCBx;
    uint8_t  F3RCCx;
    uint8_t  F3RCDx;
    uint8_t  F3RCEx;
    uint8_t  F3RCFx;
    uint8_t  FCRCDx;
    uint8_t  RESERVED0;
    uint8_t  RESERVED1;
    uint8_t  RESERVED2;
    uint8_t  RESERVED3;
} user_response_mds_rc_msdg;

///
/// @class train_2d_eye_min_max_msdg_t
/// @brief Microchip response structure
///
typedef struct __attribute__((packed)) train_2d_eye_min_max_msdg
{
    //2D training has to run with 1D training results in the delay registers. Horizontally it takes 1D
    //centered value as starting position and only sweep half of a UI to left and right (1 UI in total).
    //Vertically it takes preset vref value as starting position and sweep until bit error is detected.
    //The assumption is that data eye will be enclosed in that range.
    //eye_max/min contain the max/min VrefDAC0/VrefDQ value which passes test with the Nth step shift
    //within the 1UI range. The 1D centered RxClkDly/TxDqDly is always normalized to index 15 of the
    //array.
    //In train_2d_read_eye_msdg, eye_max/min value represents VrefDAC0 (PHY DQ receiver Vref setting)
    //Vref = (0.510 + VrefDAC0[6:0] * 0.00385) * VDDQ
    //In train_2d_write_eye_msdg, eye_max/min value represents VrefDQ (Dram DQ receiver Vref setting)
    //Vref = (0.450 + VrefDQ[6:0] * 0.0065) * VDDQ
    uint16_t eye_min[EYE_MIN_MAX_SIZE];
    uint16_t eye_max[EYE_MIN_MAX_SIZE];
} train_2d_eye_min_max_msdg_t;

///
/// @class train_2d_read_eye_msdg_t
/// @brief Microchip response structure
///
typedef struct __attribute__((packed)) train_2d_read_eye_msdg
{
    //train_2d_read_eye_msdg_t returns the read eye diagram from point of view of 2D training firmware.
    //1D training center RxClkDly (per nibble) horizontally (left and right search), 2D training does
    //sweep on horizontal (RxClkDly) and vertical (VrefDAC0) directions, then decide the center.
    //2D training has to run with 1D training results in the delay registers. Horizontally it takes 1D
    //centered value as starting position and only sweep half of a UI to left and right (1 UI in total).
    //Vertically it takes preset vref value as starting position and sweep until bit error is detected.
    //The assumption is that data eye will be enclosed in that range.
    //VrefDAC0[*][*][*] contains the max/min VrefDAC0 value which passes test with the Nth step shift
    //within the 1UI range. The 1D centered RxClkDly is always normalized to index 15 of the
    //array.
    //With both arrays, 2D read eye diagram can be plotted on debug host.

    // VrefDAC0[RANKi][DBYTEn][BITn] Maximum
    // and minimum passing VrefDAC0 in 2D read training
    train_2d_eye_min_max_msdg_t VrefDAC0[TRAINING_RESPONSE_NUM_RANKS][DBYTE_N_SIZE][BIT_N_SIZE];

    // VrefDAC0_Center[DBYTEn][BITn] Centered
    // VrefDAC0 value after 2D read training
    uint16_t VrefDAC0_Center[DBYTE_N_SIZE][BIT_N_SIZE];

    // RxClkDly_Center[RANKi][NIBBLEn] Centered
    // RxClkDly location (w.r.t. eye diagram) after 2D
    // read training
    uint16_t RxClkDly_Center[TRAINING_RESPONSE_NUM_RANKS][NIBBLE_N_SIZE];
} train_2d_read_eye_msdg_t;

typedef struct __attribute__((packed)) train_2d_write_eye_msdg
{
    //train_2d_write_eye_msdg_t returns the write eye diagram from point of view of 2D training
    //firmware.
    //1D training center TxDqDly (per DQ) horizontally (left and right search), 2D training does sweep
    //on horizontal (TxDqDly) and vertical (VrefDQ) directions, then decide the center.
    //2D training has to run with 1D training results in the delay registers. Horizontally it takes 1D
    //centered value as starting position and only sweep half of a UI to left and right (1 UI in total).
    //Vertically it takes preset vref value as starting position and sweep until bit error is detected.
    //The assumption is that data eye will be enclosed in that range.
    //VrefDQ[*][*][*] contains the max/min VrefDQ value which passes test with the Nth step shift within
    //the 1UI range. The 1D centered TxDqDly is always normalized to index 15 of the array.
    //With both arrays, 2D read eye diagram can be plotted on debug host.

    // VrefDQ[RANKi][DBYTEn][BITn] Maximum and
    // minimum passing VrefDQ in 2D write training
    train_2d_eye_min_max_msdg_t VrefDQ[TRAINING_RESPONSE_NUM_RANKS][DBYTE_N_SIZE][BIT_N_SIZE];

    // VrefDQ_Center[RANKi][NIBBLEn] Centered VrefDQ
    // value after 2D write training
    uint16_t VrefDQ_Center[TRAINING_RESPONSE_NUM_RANKS][NIBBLE_N_SIZE];

    // TxDqDly_Center[RANKi][DBYTEn][BITn] Centered
    // TxDqDly location (w.r.t. eye diagram) after 2D
    // write training
    uint16_t TxDqDly_Center[TRAINING_RESPONSE_NUM_RANKS][DBYTE_N_SIZE][BIT_N_SIZE];

} train_2d_write_eye_msdg_t;

///
/// @class user_response_msdg_t
/// @brief Microchip response structure
///
typedef struct __attribute__((packed)) user_response_msdg
{
    uint32_t                        version_number;
    user_response_timing_msdg_t     tm_resp;
    user_response_error_msdg        err_resp;
    user_response_mrs_msdg_t        mrs_resp;
    user_response_rc_msdg_t         rc_resp;

} user_response_msdg_t;

///
/// @class user_2d_eye_response_1_msdg_t
/// @brief Microchip response structure
///
typedef struct __attribute__((packed)) user_2d_eye_response_1_msdg
{
    uint32_t                        version_number;
    train_2d_read_eye_msdg_t        read_2d_eye_resp;
    user_response_timing_msdg_t     tm_resp;
    user_response_error_msdg_t      err_resp;
    user_response_mrs_msdg_t        mrs_resp;
    user_response_rc_msdg_t         rc_resp;

} user_2d_eye_response_1_msdg_t;

///
/// @class user_2d_eye_response_2_msdg_t
/// @brief Microchip response structure
///
typedef struct __attribute__((packed)) user_2d_eye_response_2_msdg
{
    uint32_t version_number;
    train_2d_write_eye_msdg_t write_2d_eye_resp;
    user_response_timing_msdg_t tm_resp;
    user_response_error_msdg_t err_resp;
    user_response_mrs_msdg_t mrs_resp;
    user_response_rc_msdg_t rc_resp;

} user_2d_eye_response_2_msdg_t;

///
/// @class user_response_mds_msdg_t
/// @brief MDS Explorer command response structure
///
typedef struct __attribute__((packed)) user_response_mds_msdg
{
    uint32_t                        version_number;
    user_response_error_msdg        err_resp;
    user_response_mrs_msdg_t        mrs_resp;
    user_response_mds_rc_msdg       mds_resp;

} user_response_mds_msdg;

///
/// @class fw_adapter_properties_struct
/// @brief EXP_FW_ADAPTER_PROPERTIES_GET data response format (Explorer FW Document v1.21)
///
typedef struct __attribute__((packed))
{
    uint32_t fw_number_of_images;     // number of FW images
    uint32_t boot_partion_id;         // ID of current boot partion
    struct fw_version_string
    {
        uint32_t major;               // FW version - Major release
        uint32_t minor;               // FW version - Minor release
        uint32_t build_patch;         // FW build patch number
        uint32_t build_num;           // FW build number
        uint32_t build_date;          // FW build data mmddyyyy
    } fw_ver_str[FW_ADAPTER_MAX_FW_IMAGE];

    uint32_t ram_size_in_bytes;       // RAM size in bytes
    uint32_t chip_version;            // Explorer chip revision
    uint32_t spi_flash_id;            // SPI flash ID
    uint32_t spi_flash_sector_size;   // SPI flash size in bytes
    uint32_t spi_flash_size;          // SPI flash size in bytes
    uint32_t error_buffer_size;       // FW error buffer size in bytes
}
fw_adapter_properties_struct;

///
/// @class spi_flash_plat_auth_info_struct
/// @brief SPI flash platform authentication info struct
/// @note this will be appended onto fw_adapter_properties_struct after FW version 432894
///
typedef struct __attribute__((packed))
{
    uint8_t active_image_index;        // The active image
    uint8_t red_image_index;           // The redundant image
    uint8_t failed_authentication[FW_ADAPTER_MAX_FW_IMAGE]; // 1 if the image failed authentication
    uint8_t uecc_detected[FW_ADAPTER_MAX_FW_IMAGE]; // 1 if UECC detected when authenticating or copying image
    uint8_t uecc_compare; // 1 if UECC detected when comparing active and redundant images
    uint8_t image_updated; // 1 if FW successfully overwrote an image that failed authentication or was out of date
}
spi_flash_plat_auth_info_struct;

///
/// @class train_delay_msdg
/// @brief MCHP delay data structure
///
typedef struct __attribute__((packed)) train_delay_msdg
{
    //9bit Write Data Delay
    //TxDqDly[pstate][rank][DQ index]
    uint16_t TxDqDly[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_DQ];

    //9bit Write DM Delay (invalid in X4 device)
    //TxDmDly[pstate][rank][byte index]u
    uint16_t TxDmDly[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_BYTES];

    //10bit Write Dqs Delay (lower nibble)
    //TxDqsDly_u0[pstate][rank][byte index]
    uint16_t TxDqsDly_u0[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_BYTES];

    //10bit Write Dqs Delay (upper nibble)
    //TxDqsDly_u1[pstate][rank][byte index]
    uint16_t TxDqsDly_u1[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_BYTES];

    //6bit Read DQS Delay (lower nibble)
    //RxClkDly_u0[pstate][rank][byte index]
    uint8_t  RxClkDly_u0[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_BYTES];

    //6bit read DQS Delay (upper nibble)
    //RxClkDly_u1[pstate][rank][byte index]
    uint8_t  RxClkDly_u1[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_BYTES];

    //11bit Read Gate Delay (lower nibble)
    //RxEnDly_u0[pstate][rank][byte index]
    uint16_t RxEnDly_u0[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_BYTES];

    //11bit Read Gate Delay (upper nibble)
    //RxEnDly_u1[pstate][rank][byte index]
    uint16_t RxEnDly_u1[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_BYTES];

    //7bit A-side AC Delay (ACX4[8]:CK0/1;ACX4[9]:N/A)
    //ATxDly_A[pstate][NumAnib]
    uint8_t  ATxDly_A[MSDG_MAX_PSTATE][NUM_BYTES];

    //7bit B-side AC Delay (ACX4[8]:CK0/1;ACX4[9]:N/A)
    //ATxDly_B[pstate][NumAnib]
    uint8_t  ATxDly_B[MSDG_MAX_PSTATE][NUM_BYTES];

    //5 bit Max Read Latency (per DFICLK)
    //DFIMRL[pstate][byte index]
    uint8_t  DFIMRL[MSDG_MAX_PSTATE][NUM_BYTES];

    //7bit Read Data Delay
    //RxPBDly[rank][DQ index]
    uint8_t  RxPBDly[MAX_NUM_RANKS][NUM_DQ];

    //LCDL Step size from lcdl_txln0
    //It is used to convert RxPBDly
    //StepSize[byte index]
    uint16_t StepSize[NUM_BYTES];

    //5 bit Max Read Latency (per DFICTLCLK)
    //DFIMRL_ddrclk[pstate]
    uint8_t  DFIMRL_ddrclk[MSDG_MAX_PSTATE];

    // Explorer FW doesn't "pack" this struct so it ends up with a byte of padding here
    uint8_t Padding;

}
train_delay_msdg_t;

///
/// @class phy_cdd
/// @brief MCHP phy cdd data structure
///
typedef struct __attribute__((packed)) phy_cdd
{
    int8_t rr;
    int8_t ww;
    int8_t rw;
    int8_t wr;
}
phy_cdd_t;

///
/// @class ddr_timing_data
/// @brief MCHP DDR timing data structure
///
typedef struct __attribute__((packed)) ddr_timing_data
{
    train_delay_msdg_t  delay_data;
    phy_cdd_t           cdd_data;
}
ddr_timing_data_t;

///
/// @class train_host_vref_msdg
/// @brief MCHP train vref data structure
///
typedef struct __attribute__((packed)) train_host_vref_msdg
{
    // VrefDAC0 value for each bit VrefDAC0[6:0]
    // PHY RX VREF DAC control for rxdq cell internal VREF, (used only when 2D training is enabled in DDR4)
    // DAC control for rxdq cell internal VREF, trained by Firmware
    // The VREF generators have different ranges, depending on the Mission Mode settings for
    // {DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange}
    // {011,0} :: VREF = VDDQ*(0.510 + VrefDAC0[6:0]*0.00345)
    uint8_t  VrefDAC0[NUM_DQ];

    // VrefDAC1 value for each bit VrefDAC1[6:0]
    // VrefDAC1 controls the alternate VREF setting for DFE (used only when DFE is enabled in DDR4)
    // DAC control for rxdq cell internal VREF, trained by Firmware
    // The VREF generators have different ranges, depending on the Mission Mode settings for
    // {DqDqsRcvCntrl::MajorMode,DqDqsRcvCntrl::ExtVrefRange}
    // {011,0} :: VREF = VDDQ*(0.510 + VrefDAC1[6:0]*0.00345)
    // {non-enumerated encodings are reserved}
    uint8_t  VrefDAC1[NUM_DQ];

    // VrefInGlobal[pstate].
    // Vref setting has two registers assocoated, it is better to put those critical registers in this same struct.
    // VrefInGlobal = {GlobalVrefInDac[6:0], GlobalVreInSel[2:0]}
    // GlobalVrefInDac[6:0]: DAC code for internal Vref generation,
    // For DDR4, GlobalVrefInSel[2] = 0, the coding :
    // DAC Output Voltage = GlobalVrefInDAC == 6'h00 ? Hi-Z : 0.345*VDDQ +
    // (0.005*GlobalVrefInDAC)*VDDQ// GlobalVrefInSel[1:0] :
    // 2'b00 -PHY Vref DAC Range0 --BP_VREF = Hi-Z   (internal Vref mode)
    // 2'b01 -Reserved Encoding
    // 2'b10 -PHY Vref DAC Range0 --BP_VREF connected to PLL Analog Bus (used and anlog test pin)
    // 2'b11 -PHY Vref DAC Range0 --BP_VREF connected to PHY Vref DAC   (External VREF mode)
    uint32_t  VrefInGlobal[MSDG_MAX_PSTATE];

    // DqDqsRcvCntrl[pstate][byte][nibble]
    // = {GainCurrAdj[4:0], MajorModebyte[2:0], DfeCtrl[1:0], ExtVrefRange, SelAnalogVref}
    // GainCurrAdj[4:0] :   Adjust gain current of RX amplifier stage, It is recommended to use default values for this CSR.
    // MajorModebyte[2:0] :
    // Selects the major mode of operation for the receiver.
    // These settings are determined by PHY Configuration based on DRAM protocol
    // 000 -Input signal is terminated/referenced to VDDQ/2 (or unterminated)
    // 001 -reserved
    // 010 -Input signal is terminated/referenced to VSSQ
    // 011 -Input signal is terminated/referenced to VDDQ, this is the recommended mode to use for DDR4.
    // others -reserved.
    // DFECTRL// 00 -DFE off// 01 -DFE on
    // 10 -Train DFE0 Amplifier
    // 11 -Train DFE1 Amplifier
    // These settings are determined by PHY Training FW and should not
    // be overridden.
    // ExtVrefRange: Extends the range available in the local per-bit VREF gener
    // SelAnalogVref  :  Setting this signal high will force the local per-bit VREF generator to pass the global VREFA to the samplers.
    uint32_t  DqDqsRcvCntrl[MSDG_MAX_PSTATE][NUM_BYTES][NIBBLES_PER_BYTE];

    // PLL Test Mode
    uint32_t  PllTestMode;

    // PLL Control Register 2
    uint32_t  PllCtrl2;

    // PLL Control Register 3
    uint32_t  PllCtrl3;

    // DLL locking parameter for each power state
    uint32_t  DllLockParam[MSDG_MAX_PSTATE];

    // DLL gain control
    uint32_t  DllGainCtl[MSDG_MAX_PSTATE];
}
train_host_vref_msdg_t;

///
/// @class train_dram_vref_msdg
/// @brief The train DDR vref data structure
///
typedef struct __attribute__((packed)) train_dram_vref_msdg
{
    // VrefDQ value for each nibble MR6[6:0].
    // VrefDQ[pstate][rank][nibble]
    // X4 DRAM:  VrefDQ[pstate][rank][19:0] represents VrefDQ for each nibble
    // X8 DRAM:  VrefDQ[pstate][rank][2*i+1] == VrefDQ[pstate][rank][2*i]
    // X16 DRAM: VrefDQ[pstate][rank][4*i+3] == VrefDQ[pstate][rank][4*i+2] == VrefDQ[pstate][rank][4*i+1] == VrefDQ[pstate][rank][4*i]
    uint8_t  VrefDQ[MSDG_MAX_PSTATE][MAX_NUM_RANKS][NUM_DRAM];
}
train_dram_vref_msdg_t;

///
/// @class ddr_vref_data
/// @brief The DDR vref data structure
///
typedef struct __attribute__((packed)) ddr_vref_data
{
    train_host_vref_msdg_t  vrefdqDeviceVoltageSetting;
    train_dram_vref_msdg_t  vrefdqDramVoltageSetting;
}
ddr_vref_data_t;

///
/// @class app_fw_ddr_calibration_data_struct
/// @brief The calibration parameters data structure
///
typedef struct __attribute__((packed))
{
    // 32-bit header to identify the section -0x20dd20dd
    uint32_t            header;

    // Structure containing the saved timing data
    ddr_timing_data_t   timing_data;

    // Structure containing the saved vref data
    ddr_vref_data_t     vref_data;

    // The saved CRC value calculated for the structure
    uint32_t            crc;
}
app_fw_ddr_calibration_data_struct;

#endif
