/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/common/include/exp_data_structs.H $ */
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
    PADDING_SIZE = 4,
    ARGUMENT_SIZE = 28,
};

///
/// @class host_fw_command_struct
/// @brief The host command structure
/// @note The HOST uses 64 Byte Command Information Unit (IU) for sending commands to Firmware
///
typedef struct
{
    // Command Header
    uint8_t  cmd_id;                          // Command type
    uint8_t  cmd_flags;                       // Various flags associated with the command
    uint16_t request_identifier;              // The request identifier of this transport request
    uint32_t cmd_length;                      // Number of bytes following the UI header
    uint32_t cmd_crc;                         // CRC of command data buffer, if used
    uint32_t host_work_area;                  // Scratchpad area for Host, FW returns this value as a reponse
    uint32_t cmd_work_area;                   // Scratchpad area for Firmware, can be used for tracking command progress etc.
    uint32_t padding[PADDING_SIZE];        // Fill up to the size of one cache line
    uint8_t  command_argument[ARGUMENT_SIZE]; // Additional parameters associated with the command
    uint32_t cmd_header_crc;                  // CRC of 64 bytes of command header
} host_fw_command_struct;

///
/// @class host_fw_response_struct
/// @brief The firmware response structure
/// @note The Firmware uses 64 Byte Response Information Unit (IU) for sending responses to HOST
///
typedef struct
{
    // Response Header
    uint8_t  response_id;                      // Response ID - same as Command ID
    uint8_t  response_flags;                   // Various flags associated with the response
    uint16_t request_identifier;               // The request identifier of this transport request
    uint32_t response_length;                  // Number of bytes following the response header
    uint32_t response_crc;                     // CRC of response data buffer, if used
    uint32_t host_work_area;                   // Scratchpad area for Host, FW returns this value as a reponse
    uint32_t padding[PADDING_SIZE];         // Fill up to the size of one cache line
    uint8_t  response_argument[ARGUMENT_SIZE]; // Additional parameters associated with the response
    uint32_t response_header_crc;              // CRC of 64 bytes of reponse header
} host_fw_response_struct;


///
/// @class user_input_msdg
/// @brief PHY initialization parameters
/// @note PHY FW module requires certain parameters from HOST software
///
typedef struct user_input_msdg
{
    // Choose the Dimm type from one of below: // 0 = UDIMM
    // 1 = RDIMM
    // 2 = LRDIMM
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

    // DRAM Column Addr Width (Valid value: 5,6,7,10)
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
    // Valid values = 480,240,160,120, 96,80,68, 60,53,48,43,40, // 36,34,32,30,28
    // [0] - Impedance in Ohm for P0
    // [1] - Impedance in Ohm for P1
    // [2] - Impedance in Ohm for P2
    // [3] - Impedance in Ohm for P3
    uint16_t PhyDrvImpedancePU[MSDG_MAX_PSTATE];

    // Tx Pull-up Drive Impedance for DQ/DQS in ohm for each pstates
    // Valid values = 480,240,160,120, 96,80,68, 60,53,48,43,40, // 36,34,32,30,28
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
    uint16_t PhyEqualization;

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
    // OdtWrMapCs[i][3:0] ODT value when writing to rank 0
    // OdtWrMapCs[i][7:4] ODT value when writing to rank 1
    // OdtWrMapCs[i][11:8] ODT value when writing to rank 2
    // OdtWrMapCs[i][15:12] ODT value when writing to rank 3
    // [0] - ODT value for P0
    // [1] - ODT value for P1
    // [2] - ODT value for P2
    // [3] - ODT value for P3
    uint16_t OdtWrMapCs[MSDG_MAX_PSTATE];

    // Enter desired ODT[3:0] value when writing to ranks
    // OdtRdMapCs[i][3:0] ODT value when writing to rank 0
    // OdtRdMapCs[i][7:4] ODT value when writing to rank 1
    // OdtRdMapCs[i][11:8] ODT value when writing to rank 2
    // OdtRdMapCs[i][15:12] ODT value when writing to rank 3
    // [0] - ODT value for P0
    // [1] - ODT value for P1
    // [2] - ODT value for P2
    // [3] - ODT value for P3
    uint16_t OdtRdMapCs[MSDG_MAX_PSTATE];

    // Enable geardown mode during training/dfi_bist.
    // 0 = 1/2 Rate; 1 = 1/4 Rate;
    // [0] - Geardown value for P0
    // [1] - Geardown value for P1
    // [2] - Geardown value for P2
    // [3] - Geardown value for P3
    uint16_t Geardown[MSDG_MAX_PSTATE];


    // Value of RCD parity checking & Command Latency Adder // (F0RC0E, FORC0F)
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


    // Value of CS to CMD/ADDR Latency mode (MR4.CAL) for dfi_bist // (training runs with CALMode = 0)
    // Valid value: 0,3,4,5,6,8
    // [0] - BistCALMode value for P0// [1] - BistCALMode value for P1
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
    uint16_t RcdIBTCtrl;

    // RCD Data Buffer Interface Driver Characteristics (F1RC00)
    // RcdDBDic[0] BCOM[3:0],BODT,BCKE, driver strength
    // RcdDBDic[1] Reserved
    // RcdDBDic[2] BCK_t/BCK_c driver strength
    // RcdDBDic[3] Reserved
    uint16_t RcdDBDic;

    // RCD slew rate control (F1RC02,F1RC03,F1RC04,F1RC05)
    // RcdSlewRate[1:0] slew rate control of address/command
    // RcdSlewRate[3:2] slew rate control of QxCs*_n
    // RcdSlewRate[5:4] slew rate control of QxODT*
    // RcdSlewRate[7:6] slew rate control of QxCKE*
    // RcdSlewRate[9:8] slew rate control of Y1_t/c, Y3_t/c
    // RcdSlewRate[11:10] slew rate control of Y0_t/c, Y2_t/c
    // RcdSlewRate[13:12] slew rate control of BCOM[3:0], BODT, BCKE // RcdSlewRate[15:14] slew rate control of BCK_t/c
    uint16_t RcdSlewRate;

    // Enable Special mode for Emulation Support
    // [0] = 0 Normal firmware mode
    // [0] = 1 Emulation firmware mode
    uint16_t EmulationSupport;
} user_input_msdg_t;

#endif
