/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_snps_dram_train_msg_blk.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
// EKB-Mirror-To: hostboot
///
/// @file ody_snps_dram_train_msg_blk.H
/// @brief Odyssey DRAM Training Message block strucure
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_SNPS_DRAM_TRAIN_MSG_BLK_H_
#define _ODY_SNPS_DRAM_TRAIN_MSG_BLK_H_

#include <fapi2.H>

typedef struct _PMU_SMB_DDR5_1D_t
{
    uint8_t  AdvTrainOpt;      // Byte offset 0x00, CSR Addr 0x58000, Direction=In
    // Some Advanced Training Options:
    //
    // AdvTrainOpt[0]: Use same data sequence on all DQ during read training (MRR31 based)
    //     0 = Use different data sequence per DQ of a nibble (2 or 4 different sequences, depending on D5Misc[4])
    //     1 = Use same data sequenece for all DQ of a nibble
    //     Note: same sequence setting is applied to all nibbles
    //
    // AdvTrainOpt[2:1]: DQ odd seed setting during read training (MRR31 based, don't care if either AdvTrainOpt[0] or D5Misc[4] is 1)
    //     00: one bit shift  w.r.t. DQ even seed
    //     01: two bit shift  w.r.t. DQ even seed
    //     10: RFU, must be 0
    //     11: RFU, must be 0
    //
    // AdvTrainOpt[4:3]: Extended sequence for read training (w.r.t. AdvTrainOpt[7] setting)
    //     00: 1x burst length
    //     01: 2x burst length
    //     10: 4x burst length
    //     11: 8x burst lenght
    //
    // AdvTrainOpt[6:5]: Extended sequence for write training (w.r.t. AdvTrainOpt[7] setting)
    //     00: 1x burst length
    //     01: 2x burst length
    //     10: 4x burst length
    //     11: 8x burst lenght
    //
    // AdvTrainOpt[7] = Use RD/WR burst length twice shorter (Applicable only if MsgMisc[2] is 0, otherwise burst length is 128bits)
    //       0 = Use default RD/WR burst length of 2048bits
    //       1 = Use RD/WR burst length of 1024bits
    uint8_t  MsgMisc;          // Byte offset 0x01, CSR Addr 0x58000, Direction=In
    // Contains various global options for training.
    //
    // Bit fields:
    //
    // MsgMisc[0] MTESTEnable
    //      0x1 = Pulse primary digital test output bump at the start of firmware execution and at the end of each major training stage. This enables observation of training stage completion by observing the digital test output.
    //      0x0 = Do not pulse primary digital test output bump
    //
    // MsgMisc[1] SimulationOnlyReset
    //      0x1 = Verilog only simulation option to shorten duration of DRAM reset pulse length to 1ns.
    //                Must never be set to 1 in silicon.
    //      0x0 = Use reset pulse length specifed by JEDEC standard
    //
    // MsgMisc[2] SimulationOnlyTraining
    //      0x1 = Verilog only simulation option to shorten the duration of the training steps by performing fewer iterations.
    //                Must never be set to 1 in silicon.
    //      0x0 = Use standard training duration.
    //
    // MsgMisc[3] UsePerDeviceVrefDq
    //      0x1 = Program user characterized Vref DQ values per DDR5 DRAM device after Write Leveling. The message block VrefDqR*Nib* fields must be populated with the desired per device Vref DQs when using this option.
    //      0x0 = Do not use VrefDqR*Nib* as input values
    //
    // MsgMisc[4] Suppress streaming messages, including assertions, regardless of HdtCtrl setting.
    //            Stage Completion messages, as well as training completion and error messages are still sent depending on HdtCtrl setting.
    //
    // MsgMisc[5] PerByteMaxRdLat
    //      0x1 = Each DBYTE will return dfi_rddata_valid at the lowest possible latency. This may result in unaligned data between bytes to be returned to the DFI.
    //      0x0 = Every DBYTE will return  dfi_rddata_valid simultaneously. This will ensure that data bytes will return aligned accesses to the DFI.
    //
    // MsgMisc[6] DRAMResetMode
    //      0x1 = Do not reset DRAM during devinit (only for pstate > 0)
    //      0x0 = Reset DRAM during devinit
    //
    // MsgMisc[7] RFU, must be zero
    //
    // Notes:
    //
    // - SimulationOnlyReset and SimulationOnlyTraining can be used to speed up simulation run times, and must never be used in real silicon. Some VIPs may have checks on DRAM reset parameters that may need to be disabled when using SimulationOnlyReset.
    uint16_t PmuRevision;      // Byte offset 0x02, CSR Addr 0x58001, Direction=Out
    // PMU firmware revision ID
    // After training is run, this address will contain the revision ID of the firmware.
    // Please reference this revision ID when filing support cases with Synopsys.
    uint8_t  Pstate;           // Byte offset 0x04, CSR Addr 0x58002, Direction=In
    // Must be set to the target Pstate to be trained
    //    0x0 = Pstate 0
    //    0x1 = Pstate 1
    //    0x2 = Pstate 2
    //    0x3 = Pstate 3
    //    All other encodings are reserved
    uint8_t  PllBypassEn;      // Byte offset 0x05, CSR Addr 0x58002, Direction=In
    // Set according to whether target Pstate uses PHY PLL bypass
    //    0x0 = PHY PLL is enabled for target Pstate
    //    0x1 = PHY PLL is bypassed for target Pstate
    uint16_t DRAMFreq;         // Byte offset 0x06, CSR Addr 0x58003, Direction=In
    // DDR data rate for the target Pstate in units of MT/s.
    // For example enter 0x12C0 for DDR4800.
    uint8_t  RCW05_next;       // Byte offset 0x08, CSR Addr 0x58004, Direction=In
    // Fields to exploit RCD multi-context feature, enabled only if RCW05_next[7] is set to 1.
    // RCW05_next[6:0] is the value to be set into RCD RCW05 before entering self-refresh at the end of training.
    // The same value is applied to each populated RCD device.
    uint8_t  RCW06_next;       // Byte offset 0x09, CSR Addr 0x58004, Direction=In
    // Fields to exploit RCD multi-context feature, enabled only if RCW05_next[7] is set to 1.
    // RCW06_next[7:0] is the value to be set into RCD RCW06 before entering self-refresh at the end of training.
    // The same value is applied to each populated RCD device.
    uint8_t  RXEN_ADJ;         // Byte offset 0x0a, CSR Addr 0x58005, Direction=In
    // Offset to apply at the end of RxEn training (in fine steps); RXEN_ADJ is a sign-magnitude value: if RXEN_ADJ[7] is 0, RXEN_ADJ[6:0] is added to the RxEnDly value found when RxEn training is converging, otherwise RXEN_ADJ[6:0] is subtracted (the maximal offset range covered is almost  +/- 2UI); see detail in training FW application note.
    uint8_t  RX2D_DFE_Misc;    // Byte offset 0x0b, CSR Addr 0x58005, Direction=In
    // Applicable only for PUB which support 4 TAP DFE, otherwise Reserved, must be programmed to 0x00
    // Extra option for RX2D when DFE is set (some to speed up training, in particular for simulation):
    // [1:0] NbTAPm1: Number of TAP (NbTAP) to train is NbTAPm1 + 1 (TAP are trained from 1 to NbTAP)
    // [3:2] BiasStepMode: delta to use when iterating TAP BiasStep from min to max
    //     0 = delta 1 (31 for TAP2, 15 for TAP 3, 7 for TAP4)
    //     1 = delta 3 for TAP2, 1 for TAP3 and TAP4 (10 iterations for TAP2, 15 for TAP3, 7 for TAP4)
    //     2 = delta 5 for TAP2, 2 for TAP3 and TAP4 (7 iterations for TAP2, 8 for TAP3, 4 for TAP4)
    //     3 = delta 15 for TAP2, 7 for TAP3, 3 for TAP 4 (3 iterations per TAP, useful for simulation)
    // [5:4] VStepSizeX: StepSize used for Voltage is the one from RX2D_TrainOpt multiplied by VStepSizeX+1
    // [7:6] DStepSizeX: StepSize used for Delay is the one from RX2D_TrainOpt multiplied by DStepSizeX+1
    uint8_t  PhyVref;          // Byte offset 0x0c, CSR Addr 0x58006, Direction=In
    // Must be programmed with the Vref level to be used by the PHY during reads
    //
    // The units of this field are a percentage of VDDQ according to the following equation:
    //
    // Receiver Vref = VDDQ*PhyVref[6:0]/128
    //
    // For example to set Vref at 0.25*VDDQ, set this field to 0x20.
    //
    // For digital simulation, any legal value can be used. For silicon, the users must calculate the analytical Vref by using the impedances, terminations, and series resistance present in the system.
    uint8_t  D5Misc;           // Byte offset 0x0d, CSR Addr 0x58006, Direction=In
    // D5 specific options for training.
    //
    // Bit fields:
    //
    // D5Misc[0]: Disable dfi_reset_n
    //     0x0 = Enables dfi_reset_n to control memreset after training
    //           PHY Internal registers control memreset during training only.
    //           To ensure that no glitches occur on BP_MEMRESET at the end of training,
    //           the memory controller must drive dfi_reset_n=1'b1 prior to starting training
    //     0x1 = (Recommended) PHY internal registers control memreset during training, and also after training.
    //           dfi_reset_n cannot control the PHY BP_MEMRESET_L pin.
    // D5Misc[1]: RFU, must be zero
    // D5Misc[2]: Use_back2back_MRR
    //     0x0 = MRR read commands are spaced by 8 MCLK during read dqs training
    //     0x1 = Back-to-back MRR read commands are issued during read dqs training
    // D5Misc[3]: RFU, must be zero
    // D5Misc[4]: Use DRAM LFSR0 only
    //     0x0 = Both LFSR are used to create, together with inversion, different patterns on each DQ of a nibble during MRR MR31
    //     0x1 = Only LFSR0 is used: this is required for x16 devices in case swizzle configuration is not the same between lower and upper byte
    // D5Misc[5]: SinglePassRd2D
    //     0x0 = Use multi-pass  Rx2D training (default, recommended)
    //     0x1 = Use single-pass Rx2D training (assumes max DQ->DQS skew of half UI, and RxClkDly may be less optimal)
    // D5Misc[6]: Train also CK ANIB delay during CS/CA training
    //     0x0 = Do not change CK ANIB delay, only CS and CA ANIB delays will be set, with potential sub optimal results
    //     0x1 = CK ANIB delays will first be set to one UI, then will be adjusted to permit better optimization of CS and CA ANIB delays
    // D5Misc[7]: Use_back2back_MRR_for_MRD
    //     0x0 = MRR read commands are spaced by 248 MCLK during LRDIMM MRD training to meet tMRROD1 and tMRR2NOD1 constraints
    //     0x1 = Back-to-back MRR read commands are issued during LRDIMM MRD training (using short MRR for 2N mode)
    uint8_t  WL_ADJ;           // Byte offset 0x0e, CSR Addr 0x58007, Direction=In
    // Offset to apply at the end of Write-Leveling (in fine steps); applicable only if internal WL is disabled (i.e., when MR2[7] is 0); WL_ADJ is a sign-magnitude value: if WL_ADJ[7] is 0, WL_ADJ[6:0] is added to the TxDqsDly value found when external WL is converging, otherwise WL_ADJ[6:0] is subtracted (the maximal offset range covered is almost  +/- 2UI); see detail in training FW application note.
    uint8_t  CsTestFail;       // Byte offset 0x0f, CSR Addr 0x58007, Direction=Out
    // This field will be set if training fails on any rank.
    //    0x0 = No failure
    //    non-zero = One or more ranks failed training
    uint16_t SequenceCtrl;     // Byte offset 0x10, CSR Addr 0x58008, Direction=In
    // Controls the training steps to be run. Each bit corresponds to a training step.
    //
    // If the bit is set to 1, the training step will run.
    // If the bit is set to 0, the training step will be skipped.
    //
    // Training step to bit mapping:
    //    SequenceCtrl[0] = Run DevInit - Device/PHY initialization. Should always be set.
    //    SequenceCtrl[1] = Run WrLvl - Write leveling (external + internal)
    //    SequenceCtrl[2] = Run RxEn - Read gate training
    //    SequenceCtrl[3] = Run RdDQS1D - 1d read dqs training (including Read Deskew)
    //    SequenceCtrl[4] = Run WrDQ1D - 1d write dq training
    //    SequenceCtrl[5] = Run rd2D - 2d read dqs training
    //    SequenceCtrl[6] = Run wr2D - 2d write dq training
    //    SequenceCtrl[7] = RFU, must be zero
    //    SequenceCtrl[8] = RFU, must be zero
    //    SequenceCtrl[9] = Run MxRdLat - Max read latency training
    //    SequenceCtrl[10] = Run LRDIMM DWL (UDIMM/RDIMM: RFU, must be zero)
    //    SequenceCtrl[11] = Run LRDIMM MRE (UDIMM/RDIMM: RFU, must be zero)
    //    SequenceCtrl[12] = Run LRDIMM MRD (UDIMM/RDIMM: RFU, must be zero)
    //    SequenceCtrl[13] = Run LRDIMM MWD (UDIMM/RDIMM: RFU, must be zero)
    //    SequenceCtrl[14] = Run RCD_CSCA - QCS/QCA training between RCD and DRAM (RDIMM/LRDIMM only, RFU for UDIMM)
    //    SequenceCtrl[15] = Run CSCA - CS/CA Training between PHY and DRAM (UDIMM) or RCD (RDIMM/LRDIMM)
    //
    uint8_t  HdtCtrl;          // Byte offset 0x12, CSR Addr 0x58009, Direction=In
    // Controls the total number of debug messages. Every message has a verbosity level associated with it, and as the HdtCtrl value is increased, less important messages stop being sent through the mailboxes. The meanings of several major HdtCtrl thresholds are explained below:
    //
    //    0x04 = Maximal debug messages (e.g., Eye contours)
    //    0x05 = Detailed debug messages (e.g. Eye delays)
    //    0x0A = Coarse debug messages (e.g. rank information)
    //    0xC8 = Stage completion
    //    0xC9 = Assertion messages
    //    0xFF = Firmware completion messages only
    //
    // See Training App Note for more detailed information on what messages are included for each threshold.
    //
    uint8_t  PhyCfg;           // Byte offset 0x13, CSR Addr 0x58009, Direction=In
    // Additional mode bits.
    //
    // Bit fields:
    // PhyCfg[1:0] 2N mode CA setup/hold time setting w.r.t. CK capturing CS assertion (DDR5 UDIMM only). This setting is only applicable if D5Misc[6] is set to 1.
    //     00 = 2UI setup time, 2UI hold time (CA stable 1UI before CS falling edge until 1UI after CS rising edge)
    //     01 = 3UI setup time, 1UI hold time (similar to RCD SDR1 mode)
    //     10 = 1UI setup time, 3UI hold time (similar to RCD SDR2 mode)
    //     11 = Reserved
    // PhyCfg[2] Support channel Id during SMBus mailbox command (NOTE: Must be set to 1 for LRDIMM, or if RCD VrefCS/VrefCA training step enable)
    //     0 = No channel ID is provided in SMBus mailbox message, SMBus command must be sent for both channels of the DIMM, when applicable
    //     1 = Channel ID is provided in SMBus mailbox message, SMBus command must be sent only for the given channel ID of the DIMM
    // PhyCfg[3] Enable detection of DQ swizzle
    // PhyCfg[4] When PhyCfg[3] is set to 1, check that detected DQ swizzle matches with the user settings (DqLnSelTg CSRs)
    // PhyCfg[5] UsePerDeviceVrefCSCA
    //     1 = Program user characterized VrefCS and VrefCA values per DDR5 DRAM device before DRAM CS/CA training. The message block VrefCSR*Nib* and VrefCAR*Nib* fields must be populated with the desired per device VrefCS and VrefCA when using this option.
    //     0 = Do not use VrefCSR*Nib* and VrefCAR*Nib* as input values
    // PhyCfg[6] UseContinuousIDforPDA (see detail in training FW application note)
    //     1 = DRAM PDA ID correspons to DRAM position in the rank
    //     0 = DRAM PDA ID corresponds with its lower nibble ID
    // PhyCfg[7] RFU, must be zero
    uint16_t ResultAddrOffset; // Byte offset 0x14, CSR Addr 0x5800a, Direction=Out
    // Byte Offset in DCCM in which more output results are provided after training. Please refer to training FW application note on when this output is significant and the format of the information to read from DCCM.
    uint8_t  DFIMRLMargin;     // Byte offset 0x16, CSR Addr 0x5800b, Direction=In
    // Margin added to the smallest passing trained DFI Max Read Latency value, in units of DFI clocks. Recommended to be >= 1. See the Training App Note for more details on the training process and the use of this value.
    //
    // This margin must include the maximum positive drift expected in tDQSCK over the target temperature and voltage range of the system.
    uint8_t  X16Present;       // Byte offset 0x17, CSR Addr 0x5800b, Direction=In
    // X16 device map. Corresponds to CS[3:0] (same mapping for both channel).
    //  X16Present[0] = CS0 is populated with X16 devices
    //  X16Present[1] = CS1 is populated with X16 devices
    //  X16Present[2] = CS2 is populated with X16 devices
    //  X16Present[3] = CS3 is populated with X16 devices
    //  X16Present[7:4] = Reserved (must be programmed to 0)
    //
    // Ranks may not contain mixed device types.
    uint8_t  UseBroadcastMR;   // Byte offset 0x18, CSR Addr 0x5800c, Direction=In
    // Training firmware can optionally set per rank mode register values for DRAM partial array self-refresh features if desired.
    //
    //    0x0 = Use MR<0:49>_A0 for rank 0 channel A
    //          Use MR<0:49>_B0 for rank 0 channel B
    //          Use MR<0:49>_A1 for rank 1 channel A
    //          Use MR<0:49>_B1 for rank 1 channel B
    //          Use MR<0:49>_A2 for rank 2 channel A
    //          Use MR<0:49>_B2 for rank 2 channel B
    //          Use MR<0:49>_A3 for rank 3 channel A
    //          Use MR<0:49>_B3 for rank 3 channel B
    //          Use RCW<0:7F>_ChA_D0 for dimm 0 channel A (RDIMM and LRDIMM)
    //          Use RCW<0:7F>_ChB_D0 for dimm 0 channel B (RDIMM and LRDIMM)
    //          Use RCW<0:7F>_ChA_D1 for dimm 1 channel A (RDIMM and LRDIMM)
    //          Use RCW<0:7F>_ChB_D1 for dimm 1 channel B (RDIMM and LRDIMM)
    //          Use BCW<0:7F>_ChA_D0 for dimm 0 channel A (LRDIMM)
    //          Use BCW<0:7F>_ChB_D0 for dimm 0 channel B (LRDIMM)
    //          Use BCW<0:7F>_ChA_D1 for dimm 1 channel A (LRDIMM)
    //          Use BCW<0:7F>_ChB_D1 for dimm 1 channel B (LRDIMM)
    //
    //    0x1 = Use MR<0:49>_A0 setting for all channels/ranks
    //          Use RCW<0:7F> setting for all channels/dimms (RDIMM and LRDIMM)
    //          Use BCW<0:7F> setting for all channels/dimms (LRDIMM)
    //
    // It is recommended in most DDR5 system configurations to set this to 1.
    //
    // Note: When set to 0, only a subset of MR and RCW can be set differently between ranks and channels, mainly those related with termination and Vref setting; see details in training FW application note.
    //
    uint8_t  D5Quickboot;      // Byte offset 0x19, CSR Addr 0x5800c, Direction=In
    // Reserved, must be zero
    uint8_t  DisabledDbyte;    // Byte offset 0x1a, CSR Addr 0x5800d, Direction=In
    // Bitmap to indicate which Dbytes are not connected (for DByte 0 to 7):
    // Set DisabledDbyte[i] to 1 to specify that DByte i does not need to be trained (DByte 8 and 9 can be disabled via EnabledDQs setting, however both must either enabled or disabled)
    uint8_t  CATrainOpt;       // Byte offset 0x1b, CSR Addr 0x5800d, Direction=In
    // CA training option bit field:
    // [0] Enable RDIMM/LRDIMM 2D CA training (UDIMM: RFU, must be zero)
    // [1] Enable RDIMM/LRDIMM CA DFE training (UDIMM: RFU, must be zero)
    // [3:2] step size for CS and CA training: 0 -> 1, 1 -> 2, 2 -> 4, 3 -> 8
    // [4] Skip_CA13_during_CAtraining
    //     0x0 = Train CA13 during CA training
    //     0x1 = Skip CA13 during CA training
    // [5] Enable RCD VrefCS training
    // [6] Enable RCD VrefCA training
    // [7] Use multiple patterns during CA training
    uint8_t  TX2D_DFE_Misc;    // Byte offset 0x1c, CSR Addr 0x5800e, Direction=In
    // Extra option for TX2D when DFE is set (some to speed up training, in particular for simulation):
    // [1:0] NbTAPm1: Number of TAP (NbTAP) to train is NbTAPm1 + 1 (TAP are trained from 1 to NbTAP)
    // [3:2] BiasStepMode: delta to use when iterating TAP BiasStep from min to max
    //     0 = delta 1 (81 iterations for TAP1, 31 for TAP2, 25 for TAP 3, 17 for TAP4)
    //     1 = delta 2 for TAP1 and TAP4, 3 for TAP2 and TAP3 (41 iterations for TAP1, 11 for TAP2, 9 for TAP3 and TAP4)
    //     2 = delta 5 for TAP1 and TAP2, 6 for TAP3, 4 for TAP4 (17 iterations for TAP1, 7 for TAP2, 5 for TAP3 and TAP4)
    //     3 = delta 40 for TAP1, 15 for TAP2, 12 for TAP3, 8 for TAP 4 (3 iterations per TAP, useful for simulation)
    // [5:4] VStepSizeX: StepSize used for Voltage is the one from TX2D_TrainOpt multiplied by VStepSizeX+1
    // [7:6] DStepSizeX: StepSize used for Delay is the one from TX2D_TrainOpt multiplied by DStepSizeX+1
    uint8_t  RX2D_TrainOpt;    // Byte offset 0x1d, CSR Addr 0x5800e, Direction=In
    // Options for 2D read training (Note: delay step size also applicable for 1D read training):
    // [0] DFE
    //      1 = Run rx2D with DFE
    //      0 = Run rx2D with DFE off
    // [1-2] Voltage Step Size (2^n)
    //      3 = 8 DAC settings between checked values
    //      2 = 4 DAC settings between checked values
    //      1 = 2 DAC settings between checked values
    //      0 = 1 DAC settings between checked values
    // [3-4] Delay Step Size (2^n)
    //      3 = 8 LCDL delays between checked values
    //      2 = 4 LCDL delays between checked values
    //      1 = 2 LCDL delays between checked values
    //      0 = 1 LCDL delays between checked values
    // [5] Voltage Step Size Multiplier
    //      1 = Voltage Step Size defined by TX2D_TrainOpt[2:1] is multiplied by 16
    //      0 = Voltage Step Size defined by TX2D_TrainOpt[2:1] is not modified
    // [6] Delay Step Size Multiplier
    //      1 = Delay Step Size defined by TX2D_TrainOpt[4:3] is multiplied by 16
    //      0 = Delay Step Size defined by TX2D_TrainOpt[4:3] is not modified
    // [7] RFU, must be zero
    //
    uint8_t  TX2D_TrainOpt;    // Byte offset 0x1e, CSR Addr 0x5800f, Direction=In
    // Options for 2D write training (Note: delay step size also applicable for 1D write training):
    // [0] DFE
    //      1 = Run tx2D with DFE
    //      0 = Run tx2D with DFE off
    // [1-2] Voltage Step Size (2^n)
    //      3 = 8 DAC settings between checked values
    //      2 = 4 DAC settings between checked values
    //      1 = 2 DAC settings between checked values
    //      0 = 1 DAC settings between checked values
    // [3-4] Delay Step Size (2^n)
    //      3 = 8 LCDL delays between checked values
    //      2 = 4 LCDL delays between checked values
    //      1 = 2 LCDL delays between checked values
    //      0 = 1 LCDL delays between checked values
    // [5] Voltage Step Size Multiplier
    //      1 = Voltage Step Size defined by TX2D_TrainOpt[2:1] is multiplied by 16
    //      0 = Voltage Step Size defined by TX2D_TrainOpt[2:1] is not modified
    // [6] Delay Step Size Multiplier
    //      1 = Delay Step Size defined by TX2D_TrainOpt[4:3] is multiplied by 16
    //      0 = Delay Step Size defined by TX2D_TrainOpt[4:3] is not modified
    // [7] RFU, must be zero
    uint8_t  Share2DVrefResult; // Byte offset 0x1f, CSR Addr 0x5800f, Direction=In
    // Reserved, must be zero
    //
    uint8_t  MRE_MIN_PULSE;    // Byte offset 0x20, CSR Addr 0x58010, Direction=In
    // LRDIMM only (UDIMM/RDIMM: RFU, must be). MRE assumes rising edge is found when MRE_MIN_PULSE[6:0]+3 consecutive 1s are received during MRE delay sweep; MRE_MIN_PULSE[6:0] thus allows to increase tolerance for noisy systems. And if MRE_MIN_PULSE[7] is set, MRE training will fail if no rising edge is found (otherwise the rising edge is assumed to be in front of last sequence of 1s detected, even if it is a short one)
    uint8_t  DWL_MIN_PULSE;    // Byte offset 0x21, CSR Addr 0x58010, Direction=In
    // LRDIMM only (UDIMM/RDIMM: RFU, must be zero). DWL assumes rising edge is found when DWL_MIN_PULSE[6:0]+3 consecutive 1s are received during DWL delay sweep; DWL_MIN_PULSE[6:0] thus allows to increase tolerance for noisy systems. And if DWL_MIN_PULSE[7] is set, DWL training will fail if no rising edge is found (otherwise the rising edge is assumed to be in front of last sequence of 1s detected, even if it is a short one)
    uint16_t PhyConfigOverride; // Byte offset 0x22, CSR Addr 0x58011, Direction=In
    // Override PhyConfig CSR.
    // 0x0: Use hardware CSR value for PhyConfig (recommended)
    // Other values: Use value for PhyConfig instead of Hardware value.
    //
    uint8_t  EnabledDQsChA;    // Byte offset 0x24, CSR Addr 0x58012, Direction=In
    // Total number of DQ bits enabled in PHY Channel A
    uint8_t  CsPresentChA;     // Byte offset 0x25, CSR Addr 0x58012, Direction=In
    // Indicates presence of DRAM at each chip select for PHY channel A.
    //
    // If the bit is set to 1, the CS is connected to DRAM.
    // If the bit is set to 0, the CS is not connected to DRAM.
    //
    //  CsPresentChA[0] = CSA0 is populated with DRAM
    //  CsPresentChA[1] = CSA1 is populated with DRAM
    //  CsPresentChA[2] = CSA2 is populated with DRAM
    //  CsPresentChA[3] = CSA3 is populated with DRAM
    //  CsPresentChA[7:4] = Reserved (must be programmed to 0)
    int8_t   CDD_ChA_RR_3_2;   // Byte offset 0x26, CSR Addr 0x58013, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 3 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_3_1;   // Byte offset 0x27, CSR Addr 0x58013, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 3 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_3_0;   // Byte offset 0x28, CSR Addr 0x58014, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 3 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_2_3;   // Byte offset 0x29, CSR Addr 0x58014, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 2 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_2_1;   // Byte offset 0x2a, CSR Addr 0x58015, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 2 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_2_0;   // Byte offset 0x2b, CSR Addr 0x58015, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 2 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_1_3;   // Byte offset 0x2c, CSR Addr 0x58016, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 1 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_1_2;   // Byte offset 0x2d, CSR Addr 0x58016, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 1 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_1_0;   // Byte offset 0x2e, CSR Addr 0x58017, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 1 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_0_3;   // Byte offset 0x2f, CSR Addr 0x58017, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 0 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_0_2;   // Byte offset 0x30, CSR Addr 0x58018, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 0 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RR_0_1;   // Byte offset 0x31, CSR Addr 0x58018, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 0 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_3_3;   // Byte offset 0x32, CSR Addr 0x58019, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 3 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_3_2;   // Byte offset 0x33, CSR Addr 0x58019, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 3 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_3_1;   // Byte offset 0x34, CSR Addr 0x5801a, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 3 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_3_0;   // Byte offset 0x35, CSR Addr 0x5801a, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 3 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_2_3;   // Byte offset 0x36, CSR Addr 0x5801b, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 2 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_2_2;   // Byte offset 0x37, CSR Addr 0x5801b, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 2 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_2_1;   // Byte offset 0x38, CSR Addr 0x5801c, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 2 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_2_0;   // Byte offset 0x39, CSR Addr 0x5801c, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 2 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_1_3;   // Byte offset 0x3a, CSR Addr 0x5801d, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 1 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_1_2;   // Byte offset 0x3b, CSR Addr 0x5801d, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 1 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_1_1;   // Byte offset 0x3c, CSR Addr 0x5801e, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 1 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_1_0;   // Byte offset 0x3d, CSR Addr 0x5801e, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 1 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_0_3;   // Byte offset 0x3e, CSR Addr 0x5801f, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 0 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_0_2;   // Byte offset 0x3f, CSR Addr 0x5801f, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 0 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_0_1;   // Byte offset 0x40, CSR Addr 0x58020, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 0 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_RW_0_0;   // Byte offset 0x41, CSR Addr 0x58020, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs0 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_3_3;   // Byte offset 0x42, CSR Addr 0x58021, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 3 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_3_2;   // Byte offset 0x43, CSR Addr 0x58021, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 3 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_3_1;   // Byte offset 0x44, CSR Addr 0x58022, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 3 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_3_0;   // Byte offset 0x45, CSR Addr 0x58022, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 3 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_2_3;   // Byte offset 0x46, CSR Addr 0x58023, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 2 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_2_2;   // Byte offset 0x47, CSR Addr 0x58023, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 2 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_2_1;   // Byte offset 0x48, CSR Addr 0x58024, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 2 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_2_0;   // Byte offset 0x49, CSR Addr 0x58024, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 2 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_1_3;   // Byte offset 0x4a, CSR Addr 0x58025, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 1 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_1_2;   // Byte offset 0x4b, CSR Addr 0x58025, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 1 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_1_1;   // Byte offset 0x4c, CSR Addr 0x58026, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 1 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_1_0;   // Byte offset 0x4d, CSR Addr 0x58026, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 1 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_0_3;   // Byte offset 0x4e, CSR Addr 0x58027, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 0 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_0_2;   // Byte offset 0x4f, CSR Addr 0x58027, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 0 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_0_1;   // Byte offset 0x50, CSR Addr 0x58028, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 0 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WR_0_0;   // Byte offset 0x51, CSR Addr 0x58028, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 0 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_3_2;   // Byte offset 0x52, CSR Addr 0x58029, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 3 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_3_1;   // Byte offset 0x53, CSR Addr 0x58029, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 3 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_3_0;   // Byte offset 0x54, CSR Addr 0x5802a, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 3 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_2_3;   // Byte offset 0x55, CSR Addr 0x5802a, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 2 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_2_1;   // Byte offset 0x56, CSR Addr 0x5802b, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 2 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_2_0;   // Byte offset 0x57, CSR Addr 0x5802b, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 2 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_1_3;   // Byte offset 0x58, CSR Addr 0x5802c, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 1 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_1_2;   // Byte offset 0x59, CSR Addr 0x5802c, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 1 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_1_0;   // Byte offset 0x5a, CSR Addr 0x5802d, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 1 to cs 0 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_0_3;   // Byte offset 0x5b, CSR Addr 0x5802d, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 0 to cs 3 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_0_2;   // Byte offset 0x5c, CSR Addr 0x5802e, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 0 to cs 2 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChA_WW_0_1;   // Byte offset 0x5d, CSR Addr 0x5802e, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 0 to cs 1 on Channel A
    // See PUB Databook section 8.2 for details on use of CDD values.
    uint8_t  MR0_A0;           // Byte offset 0x5e, CSR Addr 0x5802f, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel A, Rank 0}
    uint8_t  MR2_A0;           // Byte offset 0x5f, CSR Addr 0x5802f, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel A, Rank 0}
    uint8_t  MR3_A0;           // Byte offset 0x60, CSR Addr 0x58030, Direction=In
    // Value to be programmed in DRAM Mode Register 3 {Channel A, Rank 0}
    uint8_t  MR4_A0;           // Byte offset 0x61, CSR Addr 0x58030, Direction=In
    // Value to be programmed in DRAM Mode Register 4 {Channel A, Rank 0}
    uint8_t  MR5_A0;           // Byte offset 0x62, CSR Addr 0x58031, Direction=In
    // Value to be programmed in DRAM Mode Register 5 {Channel A, Rank 0}
    uint8_t  MR6_A0;           // Byte offset 0x63, CSR Addr 0x58031, Direction=In
    // Value to be programmed in DRAM Mode Register 6 {Channel A, Rank 0}
    uint8_t  MR32_A0_next;     // Byte offset 0x64, CSR Addr 0x58032, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 0} for RTT group specified in MR32_A0_next[6]
    uint8_t  MR8_A0;           // Byte offset 0x65, CSR Addr 0x58032, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel A, Rank 0}
    uint8_t  MR32_ORG_A0_next; // Byte offset 0x66, CSR Addr 0x58033, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 0} for other RTT group than the one specfied in MR32_A0_next[6]
    uint8_t  MR10_A0;          // Byte offset 0x67, CSR Addr 0x58033, Direction=In
    // Value to be programmed in DRAM Mode Register 10 {Channel A, Rank 0}
    uint8_t  MR11_A0;          // Byte offset 0x68, CSR Addr 0x58034, Direction=In
    // Value to be programmed in DRAM Mode Register 11 {Channel A, Rank 0}
    uint8_t  MR12_A0;          // Byte offset 0x69, CSR Addr 0x58034, Direction=In
    // Value to be programmed in DRAM Mode Register 12 {Channel A, Rank 0}
    uint8_t  MR13_A0;          // Byte offset 0x6a, CSR Addr 0x58035, Direction=In
    // Value to be programmed in DRAM Mode Register 13 {Channel A, Rank 0}
    uint8_t  MR14_A0;          // Byte offset 0x6b, CSR Addr 0x58035, Direction=In
    // Value to be programmed in DRAM Mode Register 14 {Channel A, Rank 0}
    uint8_t  MR15_A0;          // Byte offset 0x6c, CSR Addr 0x58036, Direction=In
    // Value to be programmed in DRAM Mode Register 15 {Channel A, Rank 0}
    uint8_t  MR111_A0;         // Byte offset 0x6d, CSR Addr 0x58036, Direction=In
    // Value to be programmed in DRAM Mode Register 111 {Channel A, Rank 0}
    uint8_t  MR32_A0;          // Byte offset 0x6e, CSR Addr 0x58037, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel A, Rank 0} for RTT group specified in MR32_A0[6]
    uint8_t  MR33_A0;          // Byte offset 0x6f, CSR Addr 0x58037, Direction=In
    // Value to be programmed in DRAM Mode Register 33 {Channel A, Rank 0} for RTT group specified in MR32_A0[6], when applicable
    uint8_t  MR34_A0;          // Byte offset 0x70, CSR Addr 0x58038, Direction=In
    // Value to be programmed in DRAM Mode Register 34 {Channel A, Rank 0}
    uint8_t  MR35_A0;          // Byte offset 0x71, CSR Addr 0x58038, Direction=In
    // Value to be programmed in DRAM Mode Register 35 {Channel A, Rank 0}
    uint8_t  MR32_ORG_A0;      // Byte offset 0x72, CSR Addr 0x58039, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel A, Rank 0} for other RTT group than the one specfied in MR32_A0[6]
    uint8_t  MR37_A0;          // Byte offset 0x73, CSR Addr 0x58039, Direction=In
    // Value to be programmed in DRAM Mode Register 37 {Channel A, Rank 0}
    uint8_t  MR38_A0;          // Byte offset 0x74, CSR Addr 0x5803a, Direction=In
    // Value to be programmed in DRAM Mode Register 38 {Channel A, Rank 0}
    uint8_t  MR39_A0;          // Byte offset 0x75, CSR Addr 0x5803a, Direction=In
    // Value to be programmed in DRAM Mode Register 39 {Channel A, Rank 0}
    uint8_t  MR33_ORG_A0;      // Byte offset 0x76, CSR Addr 0x5803b, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT {Channel A, Rank 0} for other RTT group than the one specfied in MR32_A0[6]
    uint8_t  MR11_A0_next;     // Byte offset 0x77, CSR Addr 0x5803b, Direction=In
    // Value to be programmed in DRAM Mode Register 11 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 0}
    uint8_t  MR12_A0_next;     // Byte offset 0x78, CSR Addr 0x5803c, Direction=In
    // Value to be programmed in DRAM Mode Register 12 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 0}
    uint8_t  MR13_A0_next;     // Byte offset 0x79, CSR Addr 0x5803c, Direction=In
    // Value to be programmed in DRAM Mode Register 13 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 0}
    uint8_t  CS_Dly_Margin_A0; // Byte offset 0x7a, CSR Addr 0x5803d, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is for channel A rank 0.
    uint8_t  CS_Vref_Margin_A0; // Byte offset 0x7b, CSR Addr 0x5803d, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is for channel A rank 0.
    uint8_t  CA_Dly_Margin_A0; // Byte offset 0x7c, CSR Addr 0x5803e, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all CA for channel A rank 0.
    uint8_t  CA_Vref_Margin_A0; // Byte offset 0x7d, CSR Addr 0x5803e, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is the minimum of all CA for channel A rank 0.
    uint8_t  MR33_ORG_A0_next; // Byte offset 0x7e, CSR Addr 0x5803f, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 0} for other RTT group than the one specfied in MR32_A0_next[6]
    uint8_t  MR33_A0_next;     // Byte offset 0x7f, CSR Addr 0x5803f, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 0} for RTT group specified in MR32_A0_next[6]
    uint8_t  MR50_A0;          // Byte offset 0x80, CSR Addr 0x58040, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel A, Rank 0}
    uint8_t  MR51_A0;          // Byte offset 0x81, CSR Addr 0x58040, Direction=In
    // Value to be programmed in DRAM Mode Register 51 {Channel A, Rank 0}
    uint8_t  MR52_A0;          // Byte offset 0x82, CSR Addr 0x58041, Direction=In
    // Value to be programmed in DRAM Mode Register 52 {Channel A, Rank 0}
    uint8_t  DFE_GainBias_A0;  // Byte offset 0x83, CSR Addr 0x58041, Direction=In
    // Value to be programmed in DRAM Mode Register 112, 120, 128, . . .,  248 {Channel A, Rank 0}
    uint8_t  MR0_A1;           // Byte offset 0x84, CSR Addr 0x58042, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel A, Rank 1}
    uint8_t  MR2_A1;           // Byte offset 0x85, CSR Addr 0x58042, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel A, Rank 1}
    uint8_t  MR3_A1;           // Byte offset 0x86, CSR Addr 0x58043, Direction=In
    // Value to be programmed in DRAM Mode Register 3 {Channel A, Rank 1}
    uint8_t  MR4_A1;           // Byte offset 0x87, CSR Addr 0x58043, Direction=In
    // Value to be programmed in DRAM Mode Register 4 {Channel A, Rank 1}
    uint8_t  MR5_A1;           // Byte offset 0x88, CSR Addr 0x58044, Direction=In
    // Value to be programmed in DRAM Mode Register 5 {Channel A, Rank 1}
    uint8_t  MR6_A1;           // Byte offset 0x89, CSR Addr 0x58044, Direction=In
    // Value to be programmed in DRAM Mode Register 6 {Channel A, Rank 1}
    uint8_t  MR32_A1_next;     // Byte offset 0x8a, CSR Addr 0x58045, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 1} for RTT group specified in MR32_A1_next[6]
    uint8_t  MR8_A1;           // Byte offset 0x8b, CSR Addr 0x58045, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel A, Rank 1}
    uint8_t  MR32_ORG_A1_next; // Byte offset 0x8c, CSR Addr 0x58046, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 1} for other RTT group than the one specfied in MR32_A1_next[6]
    uint8_t  MR10_A1;          // Byte offset 0x8d, CSR Addr 0x58046, Direction=In
    // Value to be programmed in DRAM Mode Register 10 {Channel A, Rank 1}
    uint8_t  MR11_A1;          // Byte offset 0x8e, CSR Addr 0x58047, Direction=In
    // Value to be programmed in DRAM Mode Register 11 {Channel A, Rank 1}
    uint8_t  MR12_A1;          // Byte offset 0x8f, CSR Addr 0x58047, Direction=In
    // Value to be programmed in DRAM Mode Register 12 {Channel A, Rank 1}
    uint8_t  MR13_A1;          // Byte offset 0x90, CSR Addr 0x58048, Direction=In
    // Value to be programmed in DRAM Mode Register 13 {Channel A, Rank 1}
    uint8_t  MR14_A1;          // Byte offset 0x91, CSR Addr 0x58048, Direction=In
    // Value to be programmed in DRAM Mode Register 14 {Channel A, Rank 1}
    uint8_t  MR15_A1;          // Byte offset 0x92, CSR Addr 0x58049, Direction=In
    // Value to be programmed in DRAM Mode Register 15 {Channel A, Rank 1}
    uint8_t  MR111_A1;         // Byte offset 0x93, CSR Addr 0x58049, Direction=In
    // Value to be programmed in DRAM Mode Register 111 {Channel A, Rank 1}
    uint8_t  MR32_A1;          // Byte offset 0x94, CSR Addr 0x5804a, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel A, Rank 1} for RTT group specified in MR32_A1[6]
    uint8_t  MR33_A1;          // Byte offset 0x95, CSR Addr 0x5804a, Direction=In
    // Value to be programmed in DRAM Mode Register 33 {Channel A, Rank 1} for RTT group specified in MR32_A1[6], when applicable
    uint8_t  MR34_A1;          // Byte offset 0x96, CSR Addr 0x5804b, Direction=In
    // Value to be programmed in DRAM Mode Register 34 {Channel A, Rank 1}
    uint8_t  MR35_A1;          // Byte offset 0x97, CSR Addr 0x5804b, Direction=In
    // Value to be programmed in DRAM Mode Register 35 {Channel A, Rank 1}
    uint8_t  MR32_ORG_A1;      // Byte offset 0x98, CSR Addr 0x5804c, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel A, Rank 1} for other RTT group than the one specfied in MR32_A1[6]
    uint8_t  MR37_A1;          // Byte offset 0x99, CSR Addr 0x5804c, Direction=In
    // Value to be programmed in DRAM Mode Register 37 {Channel A, Rank 1}
    uint8_t  MR38_A1;          // Byte offset 0x9a, CSR Addr 0x5804d, Direction=In
    // Value to be programmed in DRAM Mode Register 38 {Channel A, Rank 1}
    uint8_t  MR39_A1;          // Byte offset 0x9b, CSR Addr 0x5804d, Direction=In
    // Value to be programmed in DRAM Mode Register 39 {Channel A, Rank 1}
    uint8_t  MR33_ORG_A1;      // Byte offset 0x9c, CSR Addr 0x5804e, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT {Channel A, Rank 1} for other RTT group than the one specfied in MR32_A1[6]
    uint8_t  MR11_A1_next;     // Byte offset 0x9d, CSR Addr 0x5804e, Direction=In
    // Value to be programmed in DRAM Mode Register 11 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 1}
    uint8_t  MR12_A1_next;     // Byte offset 0x9e, CSR Addr 0x5804f, Direction=In
    // Value to be programmed in DRAM Mode Register 12 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 1}
    uint8_t  MR13_A1_next;     // Byte offset 0x9f, CSR Addr 0x5804f, Direction=In
    // Value to be programmed in DRAM Mode Register 13 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 1}
    uint8_t  CS_Dly_Margin_A1; // Byte offset 0xa0, CSR Addr 0x58050, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is for channel A rank 1.
    uint8_t  CS_Vref_Margin_A1; // Byte offset 0xa1, CSR Addr 0x58050, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is for channel A rank 1.
    uint8_t  CA_Dly_Margin_A1; // Byte offset 0xa2, CSR Addr 0x58051, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all CA for channel A rank 1.
    uint8_t  CA_Vref_Margin_A1; // Byte offset 0xa3, CSR Addr 0x58051, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is the minimum of all CA for channel A rank 1.
    uint8_t  MR33_ORG_A1_next; // Byte offset 0xa4, CSR Addr 0x58052, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 1} for other RTT group than the one specfied in MR32_A1_next[6]
    uint8_t  MR33_A1_next;     // Byte offset 0xa5, CSR Addr 0x58052, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 1} for RTT group specified in MR32_A1_next[6]
    uint8_t  MR50_A1;          // Byte offset 0xa6, CSR Addr 0x58053, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel A, Rank 1}
    uint8_t  MR51_A1;          // Byte offset 0xa7, CSR Addr 0x58053, Direction=In
    // Value to be programmed in DRAM Mode Register 51 {Channel A, Rank 1}
    uint8_t  MR52_A1;          // Byte offset 0xa8, CSR Addr 0x58054, Direction=In
    // Value to be programmed in DRAM Mode Register 52 {Channel A, Rank 1}
    uint8_t  DFE_GainBias_A1;  // Byte offset 0xa9, CSR Addr 0x58054, Direction=In
    // Value to be programmed in DRAM Mode Register 112, 120, 128, . . .,  248 {Channel A, Rank 1}
    uint8_t  MR0_A2;           // Byte offset 0xaa, CSR Addr 0x58055, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel A, Rank 2}
    uint8_t  MR2_A2;           // Byte offset 0xab, CSR Addr 0x58055, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel A, Rank 2}
    uint8_t  MR3_A2;           // Byte offset 0xac, CSR Addr 0x58056, Direction=In
    // Value to be programmed in DRAM Mode Register 3 {Channel A, Rank 2}
    uint8_t  MR4_A2;           // Byte offset 0xad, CSR Addr 0x58056, Direction=In
    // Value to be programmed in DRAM Mode Register 4 {Channel A, Rank 2}
    uint8_t  MR5_A2;           // Byte offset 0xae, CSR Addr 0x58057, Direction=In
    // Value to be programmed in DRAM Mode Register 5 {Channel A, Rank 2}
    uint8_t  MR6_A2;           // Byte offset 0xaf, CSR Addr 0x58057, Direction=In
    // Value to be programmed in DRAM Mode Register 6 {Channel A, Rank 2}
    uint8_t  MR32_A2_next;     // Byte offset 0xb0, CSR Addr 0x58058, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 2} for RTT group specified in MR32_A2_next[6]
    uint8_t  MR8_A2;           // Byte offset 0xb1, CSR Addr 0x58058, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel A, Rank 2}
    uint8_t  MR32_ORG_A2_next; // Byte offset 0xb2, CSR Addr 0x58059, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 2} for other RTT group than the one specfied in MR32_A2_next[6]
    uint8_t  MR10_A2;          // Byte offset 0xb3, CSR Addr 0x58059, Direction=In
    // Value to be programmed in DRAM Mode Register 10 {Channel A, Rank 2}
    uint8_t  MR11_A2;          // Byte offset 0xb4, CSR Addr 0x5805a, Direction=In
    // Value to be programmed in DRAM Mode Register 11 {Channel A, Rank 2}
    uint8_t  MR12_A2;          // Byte offset 0xb5, CSR Addr 0x5805a, Direction=In
    // Value to be programmed in DRAM Mode Register 12 {Channel A, Rank 2}
    uint8_t  MR13_A2;          // Byte offset 0xb6, CSR Addr 0x5805b, Direction=In
    // Value to be programmed in DRAM Mode Register 13 {Channel A, Rank 2}
    uint8_t  MR14_A2;          // Byte offset 0xb7, CSR Addr 0x5805b, Direction=In
    // Value to be programmed in DRAM Mode Register 14 {Channel A, Rank 2}
    uint8_t  MR15_A2;          // Byte offset 0xb8, CSR Addr 0x5805c, Direction=In
    // Value to be programmed in DRAM Mode Register 15 {Channel A, Rank 2}
    uint8_t  MR111_A2;         // Byte offset 0xb9, CSR Addr 0x5805c, Direction=In
    // Value to be programmed in DRAM Mode Register 111 {Channel A, Rank 2}
    uint8_t  MR32_A2;          // Byte offset 0xba, CSR Addr 0x5805d, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel A, Rank 2} for RTT group specified in MR32_A2[6]
    uint8_t  MR33_A2;          // Byte offset 0xbb, CSR Addr 0x5805d, Direction=In
    // Value to be programmed in DRAM Mode Register 33 {Channel A, Rank 2} for RTT group specified in MR32_A2[6], when applicable
    uint8_t  MR34_A2;          // Byte offset 0xbc, CSR Addr 0x5805e, Direction=In
    // Value to be programmed in DRAM Mode Register 34 {Channel A, Rank 2}
    uint8_t  MR35_A2;          // Byte offset 0xbd, CSR Addr 0x5805e, Direction=In
    // Value to be programmed in DRAM Mode Register 35 {Channel A, Rank 2}
    uint8_t  MR32_ORG_A2;      // Byte offset 0xbe, CSR Addr 0x5805f, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel A, Rank 2} for other RTT group than the one specfied in MR32_A2[6]
    uint8_t  MR37_A2;          // Byte offset 0xbf, CSR Addr 0x5805f, Direction=In
    // Value to be programmed in DRAM Mode Register 37 {Channel A, Rank 2}
    uint8_t  MR38_A2;          // Byte offset 0xc0, CSR Addr 0x58060, Direction=In
    // Value to be programmed in DRAM Mode Register 38 {Channel A, Rank 2}
    uint8_t  MR39_A2;          // Byte offset 0xc1, CSR Addr 0x58060, Direction=In
    // Value to be programmed in DRAM Mode Register 39 {Channel A, Rank 2}
    uint8_t  MR33_ORG_A2;      // Byte offset 0xc2, CSR Addr 0x58061, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT {Channel A, Rank 2} for other RTT group than the one specfied in MR32_A2[6]
    uint8_t  MR11_A2_next;     // Byte offset 0xc3, CSR Addr 0x58061, Direction=In
    // Value to be programmed in DRAM Mode Register 11 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 2}
    uint8_t  MR12_A2_next;     // Byte offset 0xc4, CSR Addr 0x58062, Direction=In
    // Value to be programmed in DRAM Mode Register 12 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 2}
    uint8_t  MR13_A2_next;     // Byte offset 0xc5, CSR Addr 0x58062, Direction=In
    // Value to be programmed in DRAM Mode Register 13 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 2}
    uint8_t  CS_Dly_Margin_A2; // Byte offset 0xc6, CSR Addr 0x58063, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is for channel A rank 2.
    uint8_t  CS_Vref_Margin_A2; // Byte offset 0xc7, CSR Addr 0x58063, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is for channel A rank 2.
    uint8_t  CA_Dly_Margin_A2; // Byte offset 0xc8, CSR Addr 0x58064, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all CA for channel A rank 2.
    uint8_t  CA_Vref_Margin_A2; // Byte offset 0xc9, CSR Addr 0x58064, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is the minimum of all CA for channel A rank 2.
    uint8_t  MR33_ORG_A2_next; // Byte offset 0xca, CSR Addr 0x58065, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 2} for other RTT group than the one specfied in MR32_A2_next[6]
    uint8_t  MR33_A2_next;     // Byte offset 0xcb, CSR Addr 0x58065, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 2} for RTT group specified in MR32_A2_next[6]
    uint8_t  MR50_A2;          // Byte offset 0xcc, CSR Addr 0x58066, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel A, Rank 2}
    uint8_t  MR51_A2;          // Byte offset 0xcd, CSR Addr 0x58066, Direction=In
    // Value to be programmed in DRAM Mode Register 51 {Channel A, Rank 2}
    uint8_t  MR52_A2;          // Byte offset 0xce, CSR Addr 0x58067, Direction=In
    // Value to be programmed in DRAM Mode Register 52 {Channel A, Rank 2}
    uint8_t  DFE_GainBias_A2;  // Byte offset 0xcf, CSR Addr 0x58067, Direction=In
    // Value to be programmed in DRAM Mode Register 112, 120, 128, . . .,  248 {Channel A, Rank 2}
    uint8_t  MR0_A3;           // Byte offset 0xd0, CSR Addr 0x58068, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel A, Rank 3}
    uint8_t  MR2_A3;           // Byte offset 0xd1, CSR Addr 0x58068, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel A, Rank 3}
    uint8_t  MR3_A3;           // Byte offset 0xd2, CSR Addr 0x58069, Direction=In
    // Value to be programmed in DRAM Mode Register 3 {Channel A, Rank 3}
    uint8_t  MR4_A3;           // Byte offset 0xd3, CSR Addr 0x58069, Direction=In
    // Value to be programmed in DRAM Mode Register 4 {Channel A, Rank 3}
    uint8_t  MR5_A3;           // Byte offset 0xd4, CSR Addr 0x5806a, Direction=In
    // Value to be programmed in DRAM Mode Register 5 {Channel A, Rank 3}
    uint8_t  MR6_A3;           // Byte offset 0xd5, CSR Addr 0x5806a, Direction=In
    // Value to be programmed in DRAM Mode Register 6 {Channel A, Rank 3}
    uint8_t  MR32_A3_next;     // Byte offset 0xd6, CSR Addr 0x5806b, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 3} for RTT group specified in MR32_A3_next[6]
    uint8_t  MR8_A3;           // Byte offset 0xd7, CSR Addr 0x5806b, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel A, Rank 3}
    uint8_t  MR32_ORG_A3_next; // Byte offset 0xd8, CSR Addr 0x5806c, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 3} for other RTT group than the one specfied in MR32_A3_next[6]
    uint8_t  MR10_A3;          // Byte offset 0xd9, CSR Addr 0x5806c, Direction=In
    // Value to be programmed in DRAM Mode Register 10 {Channel A, Rank 3}
    uint8_t  MR11_A3;          // Byte offset 0xda, CSR Addr 0x5806d, Direction=In
    // Value to be programmed in DRAM Mode Register 11 {Channel A, Rank 3}
    uint8_t  MR12_A3;          // Byte offset 0xdb, CSR Addr 0x5806d, Direction=In
    // Value to be programmed in DRAM Mode Register 12 {Channel A, Rank 3}
    uint8_t  MR13_A3;          // Byte offset 0xdc, CSR Addr 0x5806e, Direction=In
    // Value to be programmed in DRAM Mode Register 13 {Channel A, Rank 3}
    uint8_t  MR14_A3;          // Byte offset 0xdd, CSR Addr 0x5806e, Direction=In
    // Value to be programmed in DRAM Mode Register 14 {Channel A, Rank 3}
    uint8_t  MR15_A3;          // Byte offset 0xde, CSR Addr 0x5806f, Direction=In
    // Value to be programmed in DRAM Mode Register 15 {Channel A, Rank 3}
    uint8_t  MR111_A3;         // Byte offset 0xdf, CSR Addr 0x5806f, Direction=In
    // Value to be programmed in DRAM Mode Register 111 {Channel A, Rank 3}
    uint8_t  MR32_A3;          // Byte offset 0xe0, CSR Addr 0x58070, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel A, Rank 3} for RTT group specified in MR32_A3[6]
    uint8_t  MR33_A3;          // Byte offset 0xe1, CSR Addr 0x58070, Direction=In
    // Value to be programmed in DRAM Mode Register 33 {Channel A, Rank 3} for RTT group specified in MR32_A3[6], when applicable
    uint8_t  MR34_A3;          // Byte offset 0xe2, CSR Addr 0x58071, Direction=In
    // Value to be programmed in DRAM Mode Register 34 {Channel A, Rank 3}
    uint8_t  MR35_A3;          // Byte offset 0xe3, CSR Addr 0x58071, Direction=In
    // Value to be programmed in DRAM Mode Register 35 {Channel A, Rank 3}
    uint8_t  MR32_ORG_A3;      // Byte offset 0xe4, CSR Addr 0x58072, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel A, Rank 3} for other RTT group than the one specfied in MR32_A3[6]
    uint8_t  MR37_A3;          // Byte offset 0xe5, CSR Addr 0x58072, Direction=In
    // Value to be programmed in DRAM Mode Register 37 {Channel A, Rank 3}
    uint8_t  MR38_A3;          // Byte offset 0xe6, CSR Addr 0x58073, Direction=In
    // Value to be programmed in DRAM Mode Register 38 {Channel A, Rank 3}
    uint8_t  MR39_A3;          // Byte offset 0xe7, CSR Addr 0x58073, Direction=In
    // Value to be programmed in DRAM Mode Register 39 {Channel A, Rank 3}
    uint8_t  MR33_ORG_A3;      // Byte offset 0xe8, CSR Addr 0x58074, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT {Channel A, Rank 3} for other RTT group than the one specfied in MR32_A3[6]
    uint8_t  MR11_A3_next;     // Byte offset 0xe9, CSR Addr 0x58074, Direction=In
    // Value to be programmed in DRAM Mode Register 11 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 3}
    uint8_t  MR12_A3_next;     // Byte offset 0xea, CSR Addr 0x58075, Direction=In
    // Value to be programmed in DRAM Mode Register 12 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 3}
    uint8_t  MR13_A3_next;     // Byte offset 0xeb, CSR Addr 0x58075, Direction=In
    // Value to be programmed in DRAM Mode Register 13 before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 3}
    uint8_t  CS_Dly_Margin_A3; // Byte offset 0xec, CSR Addr 0x58076, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is for channel A rank 3.
    uint8_t  CS_Vref_Margin_A3; // Byte offset 0xed, CSR Addr 0x58076, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is for channel A rank 3.
    uint8_t  CA_Dly_Margin_A3; // Byte offset 0xee, CSR Addr 0x58077, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all CA for channel A rank 3.
    uint8_t  CA_Vref_Margin_A3; // Byte offset 0xef, CSR Addr 0x58077, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is the minimum of all CA for channel A rank 3.
    uint8_t  MR33_ORG_A3_next; // Byte offset 0xf0, CSR Addr 0x58078, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 3} for other RTT group than the one specfied in MR32_A3_next[6]
    uint8_t  MR33_A3_next;     // Byte offset 0xf1, CSR Addr 0x58078, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel A, Rank 3} for RTT group specified in MR32_A3_next[6]
    uint8_t  MR50_A3;          // Byte offset 0xf2, CSR Addr 0x58079, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel A, Rank 3}
    uint8_t  MR51_A3;          // Byte offset 0xf3, CSR Addr 0x58079, Direction=In
    // Value to be programmed in DRAM Mode Register 51 {Channel A, Rank 3}
    uint8_t  MR52_A3;          // Byte offset 0xf4, CSR Addr 0x5807a, Direction=In
    // Value to be programmed in DRAM Mode Register 52 {Channel A, Rank 3}
    uint8_t  DFE_GainBias_A3;  // Byte offset 0xf5, CSR Addr 0x5807a, Direction=In
    // Value to be programmed in DRAM Mode Register 112, 120, 128, . . .,  248 {Channel A, Rank 3}
    uint8_t  ReservedF6;       // Byte offset 0xf6, CSR Addr 0x5807b, Direction=N/A
    // This field is reserved and must be programmed to 0x00.
    uint8_t  ReservedF7;       // Byte offset 0xf7, CSR Addr 0x5807b, Direction=N/A
    // This field is reserved and must be programmed to 0x00.
    uint8_t  ReservedF8;       // Byte offset 0xf8, CSR Addr 0x5807c, Direction=N/A
    // This field is reserved and must be programmed to 0x00.
    uint8_t  ReservedF9;       // Byte offset 0xf9, CSR Addr 0x5807c, Direction=N/A
    // This field is reserved and must be programmed to 0x00.
    uint8_t  BCW04_next;       // Byte offset 0xfa, CSR Addr 0x5807d, Direction=In
    // Fields to exploit DB multi-context feature, enabled only if RCW05_next[7] is set to 1.
    // BCW04_next[6:0] is the value to be set into DB BCW04 (RCD RCW84) before entering self-refresh at the end of training.
    // The same value is applied to each populated RCD device.
    uint8_t  BCW05_next;       // Byte offset 0xfb, CSR Addr 0x5807d, Direction=In
    // Fields to exploit DB multi-context feature, enabled only if RCW05_next[7] is set to 1.
    // BCW05_next[7:0] is the value to be set into DB BCW05 (RCD RCW85) before entering self-refresh at the end of training.
    // The same value is applied to each populated RCD device.
    uint8_t  WR_RD_RTT_PARK_A0; // Byte offset 0xfc, CSR Addr 0x5807e, Direction=In
    // RTT_PARK setting for Write/Read acesses targeting Ch A Rank 0.
    //   WR_RD_RTT_PARK_A0[3:0]: Write RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 0 is not used); if bit set, corresponding rank is using RTT_PARK during Write to Ch A rank 0; otherwise RTT_NOM_WR is used
    //   WR_RD_RTT_PARK_A0[7:4]: Read RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 4 is not used): if set, corresponding ranks is using RTT_PARK during Read to Ch A rank 0; otherwise, RTT_NOM_RD is used
    uint8_t  WR_RD_RTT_PARK_A1; // Byte offset 0xfd, CSR Addr 0x5807e, Direction=In
    // RTT_PARK setting for Write/Read acesses targeting Ch A Rank 1.
    //   WR_RD_RTT_PARK_A1[3:0]: Write RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 1 is not used); if bit set, corresponding rank is using RTT_PARK during Write to Ch A rank 1; otherwise RTT_NOM_WR is used
    //   WR_RD_RTT_PARK_A1[7:4]: Read RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 5 is not used): if set, corresponding ranks is using RTT_PARK during Read to Ch A rank 1; otherwise, RTT_NOM_RD is used
    uint8_t  WR_RD_RTT_PARK_A2; // Byte offset 0xfe, CSR Addr 0x5807f, Direction=In
    // RTT_PARK setting for Write/Read acesses targeting Ch A Rank 2.
    //   WR_RD_RTT_PARK_A2[3:0]: Write RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 2 is not used); if bit set, corresponding rank is using RTT_PARK during Write to Ch A rank 2; otherwise RTT_NOM_WR is used
    //   WR_RD_RTT_PARK_A2[7:4]: Read RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 6 is not used): if set, corresponding ranks is using RTT_PARK during Read to Ch A rank 2; otherwise, RTT_NOM_RD is used
    uint8_t  WR_RD_RTT_PARK_A3; // Byte offset 0xff, CSR Addr 0x5807f, Direction=In
    // RTT_PARK setting for Write/Read acesses targeting Ch A Rank 3.
    //   WR_RD_RTT_PARK_A3[3:0]: Write RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 3 is not used); if bit set, corresponding rank is using RTT_PARK during Write to Ch A rank 3; otherwise RTT_NOM_WR is used
    //   WR_RD_RTT_PARK_A3[7:4]: Read RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 7 is not used): if set, corresponding ranks is using RTT_PARK during Read to Ch A rank 3; otherwise, RTT_NOM_RD is used
    uint8_t  RxClkDly_Margin_A0; // Byte offset 0x100, CSR Addr 0x58080, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  VrefDac_Margin_A0; // Byte offset 0x101, CSR Addr 0x58080, Direction=Out
    // Distance from the trained center to the closest failing region in PHY DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  TxDqDly_Margin_A0; // Byte offset 0x102, CSR Addr 0x58081, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  DeviceVref_Margin_A0; // Byte offset 0x103, CSR Addr 0x58081, Direction=Out
    // Distance from the trained center to the closest failing region in device DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  RxClkDly_Margin_A1; // Byte offset 0x104, CSR Addr 0x58082, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  VrefDac_Margin_A1; // Byte offset 0x105, CSR Addr 0x58082, Direction=Out
    // Distance from the trained center to the closest failing region in PHY DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  TxDqDly_Margin_A1; // Byte offset 0x106, CSR Addr 0x58083, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  DeviceVref_Margin_A1; // Byte offset 0x107, CSR Addr 0x58083, Direction=Out
    // Distance from the trained center to the closest failing region in device DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  RxClkDly_Margin_A2; // Byte offset 0x108, CSR Addr 0x58084, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  VrefDac_Margin_A2; // Byte offset 0x109, CSR Addr 0x58084, Direction=Out
    // Distance from the trained center to the closest failing region in PHY DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  TxDqDly_Margin_A2; // Byte offset 0x10a, CSR Addr 0x58085, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  DeviceVref_Margin_A2; // Byte offset 0x10b, CSR Addr 0x58085, Direction=Out
    // Distance from the trained center to the closest failing region in device DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  RxClkDly_Margin_A3; // Byte offset 0x10c, CSR Addr 0x58086, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  VrefDac_Margin_A3; // Byte offset 0x10d, CSR Addr 0x58086, Direction=Out
    // Distance from the trained center to the closest failing region in PHY DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  TxDqDly_Margin_A3; // Byte offset 0x10e, CSR Addr 0x58087, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  DeviceVref_Margin_A3; // Byte offset 0x10f, CSR Addr 0x58087, Direction=Out
    // Distance from the trained center to the closest failing region in device DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  EnabledDQsChB;    // Byte offset 0x110, CSR Addr 0x58088, Direction=In
    // Total number of DQ bits enabled in PHY Channel B
    uint8_t  CsPresentChB;     // Byte offset 0x111, CSR Addr 0x58088, Direction=In
    // Indicates presence of DRAM at each chip select for PHY channel B.
    //
    // If the bit is set to 1, the CS is connected to DRAM.
    // If the bit is set to 0, the CS is not connected to DRAM.
    //
    //  CsPresentChB[0] = CSB0 is populated with DRAM
    //  CsPresentChB[1] = CSB1 is populated with DRAM
    //  CsPresentChB[2] = CSB2 is populated with DRAM
    //  CsPresentChB[3] = CSB3 is populated with DRAM
    //  CsPresentChB[7:4] = Reserved (must be programmed to 0)
    //
    int8_t   CDD_ChB_RR_3_2;   // Byte offset 0x112, CSR Addr 0x58089, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 3 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_3_1;   // Byte offset 0x113, CSR Addr 0x58089, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 3 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_3_0;   // Byte offset 0x114, CSR Addr 0x5808a, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 3 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_2_3;   // Byte offset 0x115, CSR Addr 0x5808a, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 2 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_2_1;   // Byte offset 0x116, CSR Addr 0x5808b, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 2 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_2_0;   // Byte offset 0x117, CSR Addr 0x5808b, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 2 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_1_3;   // Byte offset 0x118, CSR Addr 0x5808c, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 1 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_1_2;   // Byte offset 0x119, CSR Addr 0x5808c, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 1 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_1_0;   // Byte offset 0x11a, CSR Addr 0x5808d, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 1 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_0_3;   // Byte offset 0x11b, CSR Addr 0x5808d, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 0 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_0_2;   // Byte offset 0x11c, CSR Addr 0x5808e, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 0 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RR_0_1;   // Byte offset 0x11d, CSR Addr 0x5808e, Direction=Out
    // This is a signed integer value.
    // Read to read critical delay difference from cs 0 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_3_3;   // Byte offset 0x11e, CSR Addr 0x5808f, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 3 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_3_2;   // Byte offset 0x11f, CSR Addr 0x5808f, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 3 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_3_1;   // Byte offset 0x120, CSR Addr 0x58090, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 3 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_3_0;   // Byte offset 0x121, CSR Addr 0x58090, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 3 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_2_3;   // Byte offset 0x122, CSR Addr 0x58091, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 2 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_2_2;   // Byte offset 0x123, CSR Addr 0x58091, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 2 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_2_1;   // Byte offset 0x124, CSR Addr 0x58092, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 2 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_2_0;   // Byte offset 0x125, CSR Addr 0x58092, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 2 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_1_3;   // Byte offset 0x126, CSR Addr 0x58093, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 1 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_1_2;   // Byte offset 0x127, CSR Addr 0x58093, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 1 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_1_1;   // Byte offset 0x128, CSR Addr 0x58094, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 1 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_1_0;   // Byte offset 0x129, CSR Addr 0x58094, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 1 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_0_3;   // Byte offset 0x12a, CSR Addr 0x58095, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 0 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_0_2;   // Byte offset 0x12b, CSR Addr 0x58095, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 0 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_0_1;   // Byte offset 0x12c, CSR Addr 0x58096, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs 0 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_RW_0_0;   // Byte offset 0x12d, CSR Addr 0x58096, Direction=Out
    // This is a signed integer value.
    // Read to write critical delay difference from cs01 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_3_3;   // Byte offset 0x12e, CSR Addr 0x58097, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 3 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_3_2;   // Byte offset 0x12f, CSR Addr 0x58097, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 3 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_3_1;   // Byte offset 0x130, CSR Addr 0x58098, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 3 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_3_0;   // Byte offset 0x131, CSR Addr 0x58098, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 3 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_2_3;   // Byte offset 0x132, CSR Addr 0x58099, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 2 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_2_2;   // Byte offset 0x133, CSR Addr 0x58099, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 2 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_2_1;   // Byte offset 0x134, CSR Addr 0x5809a, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 2 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_2_0;   // Byte offset 0x135, CSR Addr 0x5809a, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 2 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_1_3;   // Byte offset 0x136, CSR Addr 0x5809b, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 1 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_1_2;   // Byte offset 0x137, CSR Addr 0x5809b, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 1 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_1_1;   // Byte offset 0x138, CSR Addr 0x5809c, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 1 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_1_0;   // Byte offset 0x139, CSR Addr 0x5809c, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 1 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_0_3;   // Byte offset 0x13a, CSR Addr 0x5809d, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 0 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_0_2;   // Byte offset 0x13b, CSR Addr 0x5809d, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 0 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_0_1;   // Byte offset 0x13c, CSR Addr 0x5809e, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 0 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WR_0_0;   // Byte offset 0x13d, CSR Addr 0x5809e, Direction=Out
    // This is a signed integer value.
    // Write to read critical delay difference from cs 0 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_3_2;   // Byte offset 0x13e, CSR Addr 0x5809f, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 3 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_3_1;   // Byte offset 0x13f, CSR Addr 0x5809f, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 3 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_3_0;   // Byte offset 0x140, CSR Addr 0x580a0, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 3 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_2_3;   // Byte offset 0x141, CSR Addr 0x580a0, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 2 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_2_1;   // Byte offset 0x142, CSR Addr 0x580a1, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 2 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_2_0;   // Byte offset 0x143, CSR Addr 0x580a1, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 2 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_1_3;   // Byte offset 0x144, CSR Addr 0x580a2, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 1 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_1_2;   // Byte offset 0x145, CSR Addr 0x580a2, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 1 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_1_0;   // Byte offset 0x146, CSR Addr 0x580a3, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 1 to cs 0 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_0_3;   // Byte offset 0x147, CSR Addr 0x580a3, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 0 to cs 3 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_0_2;   // Byte offset 0x148, CSR Addr 0x580a4, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 0 to cs 2 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    int8_t   CDD_ChB_WW_0_1;   // Byte offset 0x149, CSR Addr 0x580a4, Direction=Out
    // This is a signed integer value.
    // Write to write critical delay difference from cs 0 to cs 1 on Channel B
    // See PUB Databook section 8.2 for details on use of CDD values.
    uint8_t  MR0_B0;           // Byte offset 0x14a, CSR Addr 0x580a5, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel B, Rank 0}
    uint8_t  MR2_B0;           // Byte offset 0x14b, CSR Addr 0x580a5, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel B, Rank 0}
    uint8_t  MR3_B0;           // Byte offset 0x14c, CSR Addr 0x580a6, Direction=In
    // Value to be programmed in DRAM Mode Register 3 {Channel B, Rank 0}
    uint8_t  MR4_B0;           // Byte offset 0x14d, CSR Addr 0x580a6, Direction=In
    // Value to be programmed in DRAM Mode Register 4 {Channel B, Rank 0}
    uint8_t  MR5_B0;           // Byte offset 0x14e, CSR Addr 0x580a7, Direction=In
    // Value to be programmed in DRAM Mode Register 5 {Channel B, Rank 0}
    uint8_t  MR6_B0;           // Byte offset 0x14f, CSR Addr 0x580a7, Direction=In
    // Value to be programmed in DRAM Mode Register 6 {Channel B, Rank 0}
    uint8_t  MR32_B0_next;     // Byte offset 0x150, CSR Addr 0x580a8, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 0} for RTT group specified in MR32_B0_next[6]
    uint8_t  MR8_B0;           // Byte offset 0x151, CSR Addr 0x580a8, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel B, Rank 0}
    uint8_t  MR32_ORG_B0_next; // Byte offset 0x152, CSR Addr 0x580a9, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 0} for other RTT group than the one specfied in MR32_B0_next[6]
    uint8_t  MR10_B0;          // Byte offset 0x153, CSR Addr 0x580a9, Direction=In
    // Value to be programmed in DRAM Mode Register 10 {Channel B, Rank 0}
    uint8_t  MR11_B0;          // Byte offset 0x154, CSR Addr 0x580aa, Direction=In
    // Value to be programmed in DRAM Mode Register 11 {Channel B, Rank 0}
    uint8_t  MR12_B0;          // Byte offset 0x155, CSR Addr 0x580aa, Direction=In
    // Value to be programmed in DRAM Mode Register 12 {Channel B, Rank 0}
    uint8_t  MR13_B0;          // Byte offset 0x156, CSR Addr 0x580ab, Direction=In
    // Value to be programmed in DRAM Mode Register 13 {Channel B, Rank 0}
    uint8_t  MR14_B0;          // Byte offset 0x157, CSR Addr 0x580ab, Direction=In
    // Value to be programmed in DRAM Mode Register 14 {Channel B, Rank 0}
    uint8_t  MR15_B0;          // Byte offset 0x158, CSR Addr 0x580ac, Direction=In
    // Value to be programmed in DRAM Mode Register 15 {Channel B, Rank 0}
    uint8_t  MR111_B0;         // Byte offset 0x159, CSR Addr 0x580ac, Direction=In
    // Value to be programmed in DRAM Mode Register 111 {Channel B, Rank 0}
    uint8_t  MR32_B0;          // Byte offset 0x15a, CSR Addr 0x580ad, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel B, Rank 0} for RTT group specified in MR32_B0[6]
    uint8_t  MR33_B0;          // Byte offset 0x15b, CSR Addr 0x580ad, Direction=In
    // Value to be programmed in DRAM Mode Register 33 {Channel B, Rank 0} for RTT group specified in MR32_B0[6], when applicable
    uint8_t  MR34_B0;          // Byte offset 0x15c, CSR Addr 0x580ae, Direction=In
    // Value to be programmed in DRAM Mode Register 34 {Channel B, Rank 0}
    uint8_t  MR35_B0;          // Byte offset 0x15d, CSR Addr 0x580ae, Direction=In
    // Value to be programmed in DRAM Mode Register 35 {Channel B, Rank 0}
    uint8_t  MR32_ORG_B0;      // Byte offset 0x15e, CSR Addr 0x580af, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel B, Rank 0} for other RTT group than the one specfied in MR32_B0[6]
    uint8_t  MR37_B0;          // Byte offset 0x15f, CSR Addr 0x580af, Direction=In
    // Value to be programmed in DRAM Mode Register 37 {Channel B, Rank 0}
    uint8_t  MR38_B0;          // Byte offset 0x160, CSR Addr 0x580b0, Direction=In
    // Value to be programmed in DRAM Mode Register 38 {Channel B, Rank 0}
    uint8_t  MR39_B0;          // Byte offset 0x161, CSR Addr 0x580b0, Direction=In
    // Value to be programmed in DRAM Mode Register 39 {Channel B, Rank 0}
    uint8_t  MR33_ORG_B0;      // Byte offset 0x162, CSR Addr 0x580b1, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT {Channel B, Rank 0} for other RTT group than the one specfied in MR32_B0[6]
    uint8_t  MR11_B0_next;     // Byte offset 0x163, CSR Addr 0x580b1, Direction=In
    // Value to be programmed in DRAM Mode Register 11 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 0}
    uint8_t  MR12_B0_next;     // Byte offset 0x164, CSR Addr 0x580b2, Direction=In
    // Value to be programmed in DRAM Mode Register 12 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 0}
    uint8_t  MR13_B0_next;     // Byte offset 0x165, CSR Addr 0x580b2, Direction=In
    // Value to be programmed in DRAM Mode Register 13 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 0}
    uint8_t  CS_Dly_Margin_B0; // Byte offset 0x166, CSR Addr 0x580b3, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is for channel B rank 0.
    uint8_t  CS_Vref_Margin_B0; // Byte offset 0x167, CSR Addr 0x580b3, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is for channel B rank 0.
    uint8_t  CA_Dly_Margin_B0; // Byte offset 0x168, CSR Addr 0x580b4, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all CA for channel B rank 0.
    uint8_t  CA_Vref_Margin_B0; // Byte offset 0x169, CSR Addr 0x580b4, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is the minimum of all CA for channel B rank 0.
    uint8_t  MR33_ORG_B0_next; // Byte offset 0x16a, CSR Addr 0x580b5, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 0} for other RTT group than the one specfied in MR32_B0_next[6]
    uint8_t  MR33_B0_next;     // Byte offset 0x16b, CSR Addr 0x580b5, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 0} for RTT group specified in MR32_B0_next[6]
    uint8_t  MR50_B0;          // Byte offset 0x16c, CSR Addr 0x580b6, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel B, Rank 0}
    uint8_t  MR51_B0;          // Byte offset 0x16d, CSR Addr 0x580b6, Direction=In
    // Value to be programmed in DRAM Mode Register 51 {Channel B, Rank 0}
    uint8_t  MR52_B0;          // Byte offset 0x16e, CSR Addr 0x580b7, Direction=In
    // Value to be programmed in DRAM Mode Register 52 {Channel B, Rank 0}
    uint8_t  DFE_GainBias_B0;  // Byte offset 0x16f, CSR Addr 0x580b7, Direction=In
    // Value to be programmed in DRAM Mode Register 112, 120, 128, . . .,  248 {Channel B, Rank 0}
    uint8_t  MR0_B1;           // Byte offset 0x170, CSR Addr 0x580b8, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel B, Rank 1}
    uint8_t  MR2_B1;           // Byte offset 0x171, CSR Addr 0x580b8, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel B, Rank 1}
    uint8_t  MR3_B1;           // Byte offset 0x172, CSR Addr 0x580b9, Direction=In
    // Value to be programmed in DRAM Mode Register 3 {Channel B, Rank 1}
    uint8_t  MR4_B1;           // Byte offset 0x173, CSR Addr 0x580b9, Direction=In
    // Value to be programmed in DRAM Mode Register 4 {Channel B, Rank 1}
    uint8_t  MR5_B1;           // Byte offset 0x174, CSR Addr 0x580ba, Direction=In
    // Value to be programmed in DRAM Mode Register 5 {Channel B, Rank 1}
    uint8_t  MR6_B1;           // Byte offset 0x175, CSR Addr 0x580ba, Direction=In
    // Value to be programmed in DRAM Mode Register 6 {Channel B, Rank 1}
    uint8_t  MR32_B1_next;     // Byte offset 0x176, CSR Addr 0x580bb, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 1} for RTT group specified in MR32_B1_next[6]
    uint8_t  MR8_B1;           // Byte offset 0x177, CSR Addr 0x580bb, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel B, Rank 1}
    uint8_t  MR32_ORG_B1_next; // Byte offset 0x178, CSR Addr 0x580bc, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 1} for other RTT group than the one specfied in MR32_B1_next[6]
    uint8_t  MR10_B1;          // Byte offset 0x179, CSR Addr 0x580bc, Direction=In
    // Value to be programmed in DRAM Mode Register 10 {Channel B, Rank 1}
    uint8_t  MR11_B1;          // Byte offset 0x17a, CSR Addr 0x580bd, Direction=In
    // Value to be programmed in DRAM Mode Register 11 {Channel B, Rank 1}
    uint8_t  MR12_B1;          // Byte offset 0x17b, CSR Addr 0x580bd, Direction=In
    // Value to be programmed in DRAM Mode Register 12 {Channel B, Rank 1}
    uint8_t  MR13_B1;          // Byte offset 0x17c, CSR Addr 0x580be, Direction=In
    // Value to be programmed in DRAM Mode Register 13 {Channel B, Rank 1}
    uint8_t  MR14_B1;          // Byte offset 0x17d, CSR Addr 0x580be, Direction=In
    // Value to be programmed in DRAM Mode Register 14 {Channel B, Rank 1}
    uint8_t  MR15_B1;          // Byte offset 0x17e, CSR Addr 0x580bf, Direction=In
    // Value to be programmed in DRAM Mode Register 15 {Channel B, Rank 1}
    uint8_t  MR111_B1;         // Byte offset 0x17f, CSR Addr 0x580bf, Direction=In
    // Value to be programmed in DRAM Mode Register 111 {Channel B, Rank 1}
    uint8_t  MR32_B1;          // Byte offset 0x180, CSR Addr 0x580c0, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel B, Rank 1} for RTT group specified in MR32_B1[6]
    uint8_t  MR33_B1;          // Byte offset 0x181, CSR Addr 0x580c0, Direction=In
    // Value to be programmed in DRAM Mode Register 33 {Channel B, Rank 1} for RTT group specified in MR32_B1[6], when applicable
    uint8_t  MR34_B1;          // Byte offset 0x182, CSR Addr 0x580c1, Direction=In
    // Value to be programmed in DRAM Mode Register 34 {Channel B, Rank 1}
    uint8_t  MR35_B1;          // Byte offset 0x183, CSR Addr 0x580c1, Direction=In
    // Value to be programmed in DRAM Mode Register 35 {Channel B, Rank 1}
    uint8_t  MR32_ORG_B1;      // Byte offset 0x184, CSR Addr 0x580c2, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel B, Rank 1} for other RTT group than the one specfied in MR32_B1[6]
    uint8_t  MR37_B1;          // Byte offset 0x185, CSR Addr 0x580c2, Direction=In
    // Value to be programmed in DRAM Mode Register 37 {Channel B, Rank 1}
    uint8_t  MR38_B1;          // Byte offset 0x186, CSR Addr 0x580c3, Direction=In
    // Value to be programmed in DRAM Mode Register 38 {Channel B, Rank 1}
    uint8_t  MR39_B1;          // Byte offset 0x187, CSR Addr 0x580c3, Direction=In
    // Value to be programmed in DRAM Mode Register 39 {Channel B, Rank 1}
    uint8_t  MR33_ORG_B1;      // Byte offset 0x188, CSR Addr 0x580c4, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT {Channel B, Rank 1} for other RTT group than the one specfied in MR32_B1[6]
    uint8_t  MR11_B1_next;     // Byte offset 0x189, CSR Addr 0x580c4, Direction=In
    // Value to be programmed in DRAM Mode Register 11 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 1}
    uint8_t  MR12_B1_next;     // Byte offset 0x18a, CSR Addr 0x580c5, Direction=In
    // Value to be programmed in DRAM Mode Register 12 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 1}
    uint8_t  MR13_B1_next;     // Byte offset 0x18b, CSR Addr 0x580c5, Direction=In
    // Value to be programmed in DRAM Mode Register 13 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 1}
    uint8_t  CS_Dly_Margin_B1; // Byte offset 0x18c, CSR Addr 0x580c6, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is for channel B rank 1.
    uint8_t  CS_Vref_Margin_B1; // Byte offset 0x18d, CSR Addr 0x580c6, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is for channel B rank 1.
    uint8_t  CA_Dly_Margin_B1; // Byte offset 0x18e, CSR Addr 0x580c7, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all CA for channel B rank 1.
    uint8_t  CA_Vref_Margin_B1; // Byte offset 0x18f, CSR Addr 0x580c7, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is the minimum of all CA for channel B rank 1.
    uint8_t  MR33_ORG_B1_next; // Byte offset 0x190, CSR Addr 0x580c8, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 1} for other RTT group than the one specfied in MR32_B1_next[6]
    uint8_t  MR33_B1_next;     // Byte offset 0x191, CSR Addr 0x580c8, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 1} for RTT group specified in MR32_B1_next[6]
    uint8_t  MR50_B1;          // Byte offset 0x192, CSR Addr 0x580c9, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel B, Rank 1}
    uint8_t  MR51_B1;          // Byte offset 0x193, CSR Addr 0x580c9, Direction=In
    // Value to be programmed in DRAM Mode Register 51 {Channel B, Rank 1}
    uint8_t  MR52_B1;          // Byte offset 0x194, CSR Addr 0x580ca, Direction=In
    // Value to be programmed in DRAM Mode Register 52 {Channel B, Rank 1}
    uint8_t  DFE_GainBias_B1;  // Byte offset 0x195, CSR Addr 0x580ca, Direction=In
    // Value to be programmed in DRAM Mode Register 112, 120, 128, . . .,  248 {Channel B, Rank 1}
    uint8_t  MR0_B2;           // Byte offset 0x196, CSR Addr 0x580cb, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel B, Rank 2}
    uint8_t  MR2_B2;           // Byte offset 0x197, CSR Addr 0x580cb, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel B, Rank 2}
    uint8_t  MR3_B2;           // Byte offset 0x198, CSR Addr 0x580cc, Direction=In
    // Value to be programmed in DRAM Mode Register 3 {Channel B, Rank 2}
    uint8_t  MR4_B2;           // Byte offset 0x199, CSR Addr 0x580cc, Direction=In
    // Value to be programmed in DRAM Mode Register 4 {Channel B, Rank 2}
    uint8_t  MR5_B2;           // Byte offset 0x19a, CSR Addr 0x580cd, Direction=In
    // Value to be programmed in DRAM Mode Register 5 {Channel B, Rank 2}
    uint8_t  MR6_B2;           // Byte offset 0x19b, CSR Addr 0x580cd, Direction=In
    // Value to be programmed in DRAM Mode Register 6 {Channel B, Rank 2}
    uint8_t  MR32_B2_next;     // Byte offset 0x19c, CSR Addr 0x580ce, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 2} for RTT group specified in MR32_B2_next[6]
    uint8_t  MR8_B2;           // Byte offset 0x19d, CSR Addr 0x580ce, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel B, Rank 2}
    uint8_t  MR32_ORG_B2_next; // Byte offset 0x19e, CSR Addr 0x580cf, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 2} for other RTT group than the one specfied in MR32_B2_next[6]
    uint8_t  MR10_B2;          // Byte offset 0x19f, CSR Addr 0x580cf, Direction=In
    // Value to be programmed in DRAM Mode Register 10 {Channel B, Rank 2}
    uint8_t  MR11_B2;          // Byte offset 0x1a0, CSR Addr 0x580d0, Direction=In
    // Value to be programmed in DRAM Mode Register 11 {Channel B, Rank 2}
    uint8_t  MR12_B2;          // Byte offset 0x1a1, CSR Addr 0x580d0, Direction=In
    // Value to be programmed in DRAM Mode Register 12 {Channel B, Rank 2}
    uint8_t  MR13_B2;          // Byte offset 0x1a2, CSR Addr 0x580d1, Direction=In
    // Value to be programmed in DRAM Mode Register 13 {Channel B, Rank 2}
    uint8_t  MR14_B2;          // Byte offset 0x1a3, CSR Addr 0x580d1, Direction=In
    // Value to be programmed in DRAM Mode Register 14 {Channel B, Rank 2}
    uint8_t  MR15_B2;          // Byte offset 0x1a4, CSR Addr 0x580d2, Direction=In
    // Value to be programmed in DRAM Mode Register 15 {Channel B, Rank 2}
    uint8_t  MR111_B2;         // Byte offset 0x1a5, CSR Addr 0x580d2, Direction=In
    // Value to be programmed in DRAM Mode Register 111 {Channel B, Rank 2}
    uint8_t  MR32_B2;          // Byte offset 0x1a6, CSR Addr 0x580d3, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel B, Rank 2} for RTT group specified in MR32_B2[6]
    uint8_t  MR33_B2;          // Byte offset 0x1a7, CSR Addr 0x580d3, Direction=In
    // Value to be programmed in DRAM Mode Register 33 {Channel B, Rank 2} for RTT group specified in MR32_B2[6], when applicable
    uint8_t  MR34_B2;          // Byte offset 0x1a8, CSR Addr 0x580d4, Direction=In
    // Value to be programmed in DRAM Mode Register 34 {Channel B, Rank 2}
    uint8_t  MR35_B2;          // Byte offset 0x1a9, CSR Addr 0x580d4, Direction=In
    // Value to be programmed in DRAM Mode Register 35 {Channel B, Rank 2}
    uint8_t  MR32_ORG_B2;      // Byte offset 0x1aa, CSR Addr 0x580d5, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel B, Rank 2} for other RTT group than the one specfied in MR32_B2[6]
    uint8_t  MR37_B2;          // Byte offset 0x1ab, CSR Addr 0x580d5, Direction=In
    // Value to be programmed in DRAM Mode Register 37 {Channel B, Rank 2}
    uint8_t  MR38_B2;          // Byte offset 0x1ac, CSR Addr 0x580d6, Direction=In
    // Value to be programmed in DRAM Mode Register 38 {Channel B, Rank 2}
    uint8_t  MR39_B2;          // Byte offset 0x1ad, CSR Addr 0x580d6, Direction=In
    // Value to be programmed in DRAM Mode Register 39 {Channel B, Rank 2}
    uint8_t  MR33_ORG_B2;      // Byte offset 0x1ae, CSR Addr 0x580d7, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT {Channel B, Rank 2} for other RTT group than the one specfied in MR32_B2[6]
    uint8_t  MR11_B2_next;     // Byte offset 0x1af, CSR Addr 0x580d7, Direction=In
    // Value to be programmed in DRAM Mode Register 11 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 2}
    uint8_t  MR12_B2_next;     // Byte offset 0x1b0, CSR Addr 0x580d8, Direction=In
    // Value to be programmed in DRAM Mode Register 12 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 2}
    uint8_t  MR13_B2_next;     // Byte offset 0x1b1, CSR Addr 0x580d8, Direction=In
    // Value to be programmed in DRAM Mode Register 13 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 2}
    uint8_t  CS_Dly_Margin_B2; // Byte offset 0x1b2, CSR Addr 0x580d9, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is for channel B rank 2.
    uint8_t  CS_Vref_Margin_B2; // Byte offset 0x1b3, CSR Addr 0x580d9, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is for channel B rank 2.
    uint8_t  CA_Dly_Margin_B2; // Byte offset 0x1b4, CSR Addr 0x580da, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all CA for channel B rank 2.
    uint8_t  CA_Vref_Margin_B2; // Byte offset 0x1b5, CSR Addr 0x580da, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is the minimum of all CA for channel B rank 2.
    uint8_t  MR33_ORG_B2_next; // Byte offset 0x1b6, CSR Addr 0x580db, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 2} for other RTT group than the one specfied in MR32_B2_next[6]
    uint8_t  MR33_B2_next;     // Byte offset 0x1b7, CSR Addr 0x580db, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 2} for RTT group specified in MR32_B2_next[6]
    uint8_t  MR50_B2;          // Byte offset 0x1b8, CSR Addr 0x580dc, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel B, Rank 2}
    uint8_t  MR51_B2;          // Byte offset 0x1b9, CSR Addr 0x580dc, Direction=In
    // Value to be programmed in DRAM Mode Register 51 {Channel B, Rank 2}
    uint8_t  MR52_B2;          // Byte offset 0x1ba, CSR Addr 0x580dd, Direction=In
    // Value to be programmed in DRAM Mode Register 52 {Channel B, Rank 2}
    uint8_t  DFE_GainBias_B2;  // Byte offset 0x1bb, CSR Addr 0x580dd, Direction=In
    // Value to be programmed in DRAM Mode Register 112, 120, 128, . . .,  248 {Channel B, Rank 2}
    uint8_t  MR0_B3;           // Byte offset 0x1bc, CSR Addr 0x580de, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel B, Rank 3}
    uint8_t  MR2_B3;           // Byte offset 0x1bd, CSR Addr 0x580de, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel B, Rank 3}
    uint8_t  MR3_B3;           // Byte offset 0x1be, CSR Addr 0x580df, Direction=In
    // Value to be programmed in DRAM Mode Register 3 {Channel B, Rank 3}
    uint8_t  MR4_B3;           // Byte offset 0x1bf, CSR Addr 0x580df, Direction=In
    // Value to be programmed in DRAM Mode Register 4 {Channel B, Rank 3}
    uint8_t  MR5_B3;           // Byte offset 0x1c0, CSR Addr 0x580e0, Direction=In
    // Value to be programmed in DRAM Mode Register 5 {Channel B, Rank 3}
    uint8_t  MR6_B3;           // Byte offset 0x1c1, CSR Addr 0x580e0, Direction=In
    // Value to be programmed in DRAM Mode Register 6 {Channel B, Rank 3}
    uint8_t  MR32_B3_next;     // Byte offset 0x1c2, CSR Addr 0x580e1, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 3} for RTT group specified in MR32_B3_next[6]
    uint8_t  MR8_B3;           // Byte offset 0x1c3, CSR Addr 0x580e1, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel B, Rank 3}
    uint8_t  MR32_ORG_B3_next; // Byte offset 0x1c4, CSR Addr 0x580e2, Direction=In
    // Value to be programmed in DRAM Mode Register 32 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 3} for other RTT group than the one specfied in MR32_B3_next[6]
    uint8_t  MR10_B3;          // Byte offset 0x1c5, CSR Addr 0x580e2, Direction=In
    // Value to be programmed in DRAM Mode Register 10 {Channel B, Rank 3}
    uint8_t  MR11_B3;          // Byte offset 0x1c6, CSR Addr 0x580e3, Direction=In
    // Value to be programmed in DRAM Mode Register 11 {Channel B, Rank 3}
    uint8_t  MR12_B3;          // Byte offset 0x1c7, CSR Addr 0x580e3, Direction=In
    // Value to be programmed in DRAM Mode Register 12 {Channel B, Rank 3}
    uint8_t  MR13_B3;          // Byte offset 0x1c8, CSR Addr 0x580e4, Direction=In
    // Value to be programmed in DRAM Mode Register 13 {Channel B, Rank 3}
    uint8_t  MR14_B3;          // Byte offset 0x1c9, CSR Addr 0x580e4, Direction=In
    // Value to be programmed in DRAM Mode Register 14 {Channel B, Rank 3}
    uint8_t  MR15_B3;          // Byte offset 0x1ca, CSR Addr 0x580e5, Direction=In
    // Value to be programmed in DRAM Mode Register 15 {Channel B, Rank 3}
    uint8_t  MR111_B3;         // Byte offset 0x1cb, CSR Addr 0x580e5, Direction=In
    // Value to be programmed in DRAM Mode Register 111 {Channel B, Rank 3}
    uint8_t  MR32_B3;          // Byte offset 0x1cc, CSR Addr 0x580e6, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel B, Rank 3} for RTT group specified in MR32_B3[6]
    uint8_t  MR33_B3;          // Byte offset 0x1cd, CSR Addr 0x580e6, Direction=In
    // Value to be programmed in DRAM Mode Register 33 {Channel B, Rank 3} for RTT group specified in MR32_B3[6], when applicable
    uint8_t  MR34_B3;          // Byte offset 0x1ce, CSR Addr 0x580e7, Direction=In
    // Value to be programmed in DRAM Mode Register 34 {Channel B, Rank 3}
    uint8_t  MR35_B3;          // Byte offset 0x1cf, CSR Addr 0x580e7, Direction=In
    // Value to be programmed in DRAM Mode Register 35 {Channel B, Rank 3}
    uint8_t  MR32_ORG_B3;      // Byte offset 0x1d0, CSR Addr 0x580e8, Direction=In
    // Value to be programmed in DRAM Mode Register 32 {Channel B, Rank 3} for other RTT group than the one specfied in MR32_B3[6]
    uint8_t  MR37_B3;          // Byte offset 0x1d1, CSR Addr 0x580e8, Direction=In
    // Value to be programmed in DRAM Mode Register 37 {Channel B, Rank 3}
    uint8_t  MR38_B3;          // Byte offset 0x1d2, CSR Addr 0x580e9, Direction=In
    // Value to be programmed in DRAM Mode Register 38 {Channel B, Rank 3}
    uint8_t  MR39_B3;          // Byte offset 0x1d3, CSR Addr 0x580e9, Direction=In
    // Value to be programmed in DRAM Mode Register 39 {Channel B, Rank 3}
    uint8_t  MR33_ORG_B3;      // Byte offset 0x1d4, CSR Addr 0x580ea, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT {Channel B, Rank 3} for other RTT group than the one specfied in MR32_B3[6]
    uint8_t  MR11_B3_next;     // Byte offset 0x1d5, CSR Addr 0x580ea, Direction=In
    // Value to be programmed in DRAM Mode Register 11 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 3}
    uint8_t  MR12_B3_next;     // Byte offset 0x1d6, CSR Addr 0x580eb, Direction=In
    // Value to be programmed in DRAM Mode Register 12 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 3}
    uint8_t  MR13_B3_next;     // Byte offset 0x1d7, CSR Addr 0x580eb, Direction=In
    // Value to be programmed in DRAM Mode Register 13 before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 3}
    uint8_t  CS_Dly_Margin_B3; // Byte offset 0x1d8, CSR Addr 0x580ec, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is for channel B rank 3.
    uint8_t  CS_Vref_Margin_B3; // Byte offset 0x1d9, CSR Addr 0x580ec, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is for channel B rank 3.
    uint8_t  CA_Dly_Margin_B3; // Byte offset 0x1da, CSR Addr 0x580ed, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all CA for channel B rank 3.
    uint8_t  CA_Vref_Margin_B3; // Byte offset 0x1db, CSR Addr 0x580ed, Direction=Out
    // Distance from the trained center to the closest failing region in Vref steps. This value is the minimum of all CA for channel B rank 3.
    uint8_t  MR33_ORG_B3_next; // Byte offset 0x1dc, CSR Addr 0x580ee, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 3} for other RTT group than the one specfied in MR32_B3_next[6]
    uint8_t  MR33_B3_next;     // Byte offset 0x1dd, CSR Addr 0x580ee, Direction=In
    // Value to be programmed in DRAM Mode Register 33 CA_ODT before issuing self-refresh enter (SREF) command at the end of training  {Channel B, Rank 3} for RTT group specified in MR32_B3_next[6]
    uint8_t  MR50_B3;          // Byte offset 0x1de, CSR Addr 0x580ef, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel B, Rank 3}
    uint8_t  MR51_B3;          // Byte offset 0x1df, CSR Addr 0x580ef, Direction=In
    // Value to be programmed in DRAM Mode Register 51 {Channel B, Rank 3}
    uint8_t  MR52_B3;          // Byte offset 0x1e0, CSR Addr 0x580f0, Direction=In
    // Value to be programmed in DRAM Mode Register 52 {Channel B, Rank 3}
    uint8_t  DFE_GainBias_B3;  // Byte offset 0x1e1, CSR Addr 0x580f0, Direction=In
    // Value to be programmed in DRAM Mode Register 112, 120, 128, . . .,  248 {Channel B, Rank 3}
    uint8_t  Reserved1E2;      // Byte offset 0x1e2, CSR Addr 0x580f1, Direction=N/A
    // CA DFE training option bit fields:
    // [1:0] NbTAPm1: Number of TAP (NbTAP) to train is NbTAPm1 + 1 (TAP are trained from 1 to NbTAP)
    // [3:2] BiasStepMode: delta to use when iterating TAP BiasStep from min to max
    //     0 = delta 1 for all trained TAP
    //     1 = delta 2 for all trained TAP
    //     2 = delta 5 for all trained TAP
    //     3 = delta 16 for TAP1, 10 for TAP2, 7 for TAP3 and 7 for TAP4 (useful for simulation)
    // [5:4] VStepSize: VrefCA step size (2^n)
    //     0 = step size of 1
    //     1 = step size of 2
    //     2 = step size of 4
    //     3 = step size of 8
    // [6] TrainDFEGain: when set, train the DFE Gain Offset
    // [7] DFEVrefEnable: when set, DFE Vref circuitry will be enabled by firmware in RW31[1] during and after CA DFE training
    uint8_t  Reserved1E3;      // Byte offset 0x1e3, CSR Addr 0x580f1, Direction=N/A
    // This field is reserved and must be programmed to 0x00.
    uint8_t  Reserved1E4;      // Byte offset 0x1e4, CSR Addr 0x580f2, Direction=N/A
    // Bit fields:
    // [0]: SingleBurstPDA: when set, use the single burst PDA ID enumeration method
    // [1]: DumpMR: when set, read and dump MR values after read and write training stages (only when HdtCtrl is <= 4)
    // [2]: KeepODT: when set, ODT_on / off values in MR37, MR38 and MR39 are programmed as specified in the message block during training
    // [3]: ResetIntWL: when set, MR2[7] is set to 0 during devinit
    // [4]: ForceDPAR: when set, DPAR signal is forced to high during RCD initialization
    // [7:5] RFU, must be 0
    uint8_t  Reserved1E5;      // Byte offset 0x1e5, CSR Addr 0x580f2, Direction=N/A
    // This field is reserved and must be programmed to 0x00.
    uint8_t  Reserved1E6;      // Byte offset 0x1e6, CSR Addr 0x580f3, Direction=N/A
    // This field is reserved and must be programmed to 0x00.
    uint8_t  Reserved1E7;      // Byte offset 0x1e7, CSR Addr 0x580f3, Direction=N/A
    // This field is reserved and must be programmed to 0x00.
    uint8_t  WR_RD_RTT_PARK_B0; // Byte offset 0x1e8, CSR Addr 0x580f4, Direction=In
    // RTT_PARK setting for Write/Read acesses targeting Ch B Rank 0.
    //   WR_RD_RTT_PARK_B0[3:0]: Write RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 0 is not used); if bit set, corresponding rank is using RTT_PARK during Write to Ch B rank 0; otherwise RTT_NOM_WR is used
    //   WR_RD_RTT_PARK_B0[7:4]: Read RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 4 is not used): if set, corresponding ranks is using RTT_PARK during Read to Ch B rank 0; otherwise, RTT_NOM_RD is used
    uint8_t  WR_RD_RTT_PARK_B1; // Byte offset 0x1e9, CSR Addr 0x580f4, Direction=In
    // RTT_PARK setting for Write/Read acesses targeting Ch B Rank 1.
    //   WR_RD_RTT_PARK_B0[3:0]: Write RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 1 is not used); if bit set, corresponding rank is using RTT_PARK during Write to Ch B rank 1; otherwise RTT_NOM_WR is used
    //   WR_RD_RTT_PARK_B0[7:4]: Read RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 5 is not used): if set, corresponding ranks is using RTT_PARK during Read to Ch B rank 1; otherwise, RTT_NOM_RD is used
    uint8_t  WR_RD_RTT_PARK_B2; // Byte offset 0x1ea, CSR Addr 0x580f5, Direction=In
    // RTT_PARK setting for Write/Read acesses targeting Ch B Rank 2.
    //   WR_RD_RTT_PARK_B0[3:0]: Write RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 2 is not used); if bit set, corresponding rank is using RTT_PARK during Write to Ch B rank 2; otherwise RTT_NOM_WR is used
    //   WR_RD_RTT_PARK_B0[7:4]: Read RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 6 is not used): if set, corresponding ranks is using RTT_PARK during Read to Ch B rank 2; otherwise, RTT_NOM_RD is used
    uint8_t  WR_RD_RTT_PARK_B3; // Byte offset 0x1eb, CSR Addr 0x580f5, Direction=In
    // RTT_PARK setting for Write/Read acesses targeting Ch B Rank 3.
    //   WR_RD_RTT_PARK_B0[3:0]: Write RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 3 is not used); if bit set, corresponding rank is using RTT_PARK during Write to Ch B rank 3; otherwise RTT_NOM_WR is used
    //   WR_RD_RTT_PARK_B0[7:4]: Read RTT_PARK bit-map setting for non-target ranks 3 to 0, respectively (bit 7 is not used): if set, corresponding ranks is using RTT_PARK during Read to Ch B rank 3; otherwise, RTT_NOM_RD is used
    uint8_t  RxClkDly_Margin_B0; // Byte offset 0x1ec, CSR Addr 0x580f6, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  VrefDac_Margin_B0; // Byte offset 0x1ed, CSR Addr 0x580f6, Direction=Out
    // Distance from the trained center to the closest failing region in PHY DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  TxDqDly_Margin_B0; // Byte offset 0x1ee, CSR Addr 0x580f7, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  DeviceVref_Margin_B0; // Byte offset 0x1ef, CSR Addr 0x580f7, Direction=Out
    // Distance from the trained center to the closest failing region in device DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  RxClkDly_Margin_B1; // Byte offset 0x1f0, CSR Addr 0x580f8, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  VrefDac_Margin_B1; // Byte offset 0x1f1, CSR Addr 0x580f8, Direction=Out
    // Distance from the trained center to the closest failing region in PHY DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  TxDqDly_Margin_B1; // Byte offset 0x1f2, CSR Addr 0x580f9, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  DeviceVref_Margin_B1; // Byte offset 0x1f3, CSR Addr 0x580f9, Direction=Out
    // Distance from the trained center to the closest failing region in device DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  RxClkDly_Margin_B2; // Byte offset 0x1f4, CSR Addr 0x580fa, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  VrefDac_Margin_B2; // Byte offset 0x1f5, CSR Addr 0x580fa, Direction=Out
    // Distance from the trained center to the closest failing region in PHY DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  TxDqDly_Margin_B2; // Byte offset 0x1f6, CSR Addr 0x580fb, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  DeviceVref_Margin_B2; // Byte offset 0x1f7, CSR Addr 0x580fb, Direction=Out
    // Distance from the trained center to the closest failing region in device DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  RxClkDly_Margin_B3; // Byte offset 0x1f8, CSR Addr 0x580fc, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  VrefDac_Margin_B3; // Byte offset 0x1f9, CSR Addr 0x580fc, Direction=Out
    // Distance from the trained center to the closest failing region in PHY DAC steps. This value is the minimum of all eyes in this timing group.
    uint8_t  TxDqDly_Margin_B3; // Byte offset 0x1fa, CSR Addr 0x580fd, Direction=Out
    // Distance from the trained center to the closest failing region in DLL steps. This value is the minimum of all eyes in this timing group.
    uint8_t  DeviceVref_Margin_B3; // Byte offset 0x1fb, CSR Addr 0x580fd, Direction=Out
    // Distance from the trained center to the closest failing region in device DAC steps. This value is the minimum of all eyes in this timing group.
    uint16_t WL_ADJ_START;     // Byte offset 0x1fc, CSR Addr 0x580fe, Direction=In
    // Offset to apply before internal WL (in fine steps); applicable only if internal WL is enabled (i.e., when MR2[7] is 1); WL_ADJ_START is subtracted from the TxDqsDly value found after external WL, to be used as the starting point for internal WL.
    uint16_t WL_ADJ_END;       // Byte offset 0x1fe, CSR Addr 0x580ff, Direction=In
    // Offset to apply after internal WL (in fine steps); applicable only if internal WL is enabled (i.e., when MR2[7] is 1); WL_ADJ_END is added to the TxDqsDly value found after internal WL, to be used as the final value.
    uint8_t  RCW00_ChA_D0;     // Byte offset 0x200, CSR Addr 0x58100, Direction=In
    // RCD CW 0x00 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW01_ChA_D0;     // Byte offset 0x201, CSR Addr 0x58100, Direction=In
    // RCD CW 0x01 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW02_ChA_D0;     // Byte offset 0x202, CSR Addr 0x58101, Direction=In
    // RCD CW 0x02 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW03_ChA_D0;     // Byte offset 0x203, CSR Addr 0x58101, Direction=In
    // RCD CW 0x03 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW04_ChA_D0;     // Byte offset 0x204, CSR Addr 0x58102, Direction=In
    // RCD CW 0x04 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW05_ChA_D0;     // Byte offset 0x205, CSR Addr 0x58102, Direction=In
    // RCD CW 0x05 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW06_ChA_D0;     // Byte offset 0x206, CSR Addr 0x58103, Direction=In
    // RCD CW 0x06 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW07_ChA_D0;     // Byte offset 0x207, CSR Addr 0x58103, Direction=In
    // RCD CW 0x07 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW08_ChA_D0;     // Byte offset 0x208, CSR Addr 0x58104, Direction=In
    // RCD CW 0x08 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW09_ChA_D0;     // Byte offset 0x209, CSR Addr 0x58104, Direction=In
    // RCD CW 0x09 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW0A_ChA_D0;     // Byte offset 0x20a, CSR Addr 0x58105, Direction=In
    // RCD CW 0x0A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW0B_ChA_D0;     // Byte offset 0x20b, CSR Addr 0x58105, Direction=In
    // RCD CW 0x0B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW0C_ChA_D0;     // Byte offset 0x20c, CSR Addr 0x58106, Direction=In
    // RCD CW 0x0C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW0D_ChA_D0;     // Byte offset 0x20d, CSR Addr 0x58106, Direction=In
    // RCD CW 0x0D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW0E_ChA_D0;     // Byte offset 0x20e, CSR Addr 0x58107, Direction=In
    // RCD CW 0x0E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW0F_ChA_D0;     // Byte offset 0x20f, CSR Addr 0x58107, Direction=In
    // RCD CW 0x0F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW10_ChA_D0;     // Byte offset 0x210, CSR Addr 0x58108, Direction=In
    // RCD CW 0x10 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW11_ChA_D0;     // Byte offset 0x211, CSR Addr 0x58108, Direction=In
    // RCD CW 0x11 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW12_ChA_D0;     // Byte offset 0x212, CSR Addr 0x58109, Direction=In
    // RCD CW 0x12 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW13_ChA_D0;     // Byte offset 0x213, CSR Addr 0x58109, Direction=In
    // RCD CW 0x13 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW14_ChA_D0;     // Byte offset 0x214, CSR Addr 0x5810a, Direction=In
    // RCD CW 0x14 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW15_ChA_D0;     // Byte offset 0x215, CSR Addr 0x5810a, Direction=In
    // RCD CW 0x15 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW16_ChA_D0;     // Byte offset 0x216, CSR Addr 0x5810b, Direction=In
    // RCD CW 0x16 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW17_ChA_D0;     // Byte offset 0x217, CSR Addr 0x5810b, Direction=In
    // RCD CW 0x17 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW18_ChA_D0;     // Byte offset 0x218, CSR Addr 0x5810c, Direction=In
    // RCD CW 0x18 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW19_ChA_D0;     // Byte offset 0x219, CSR Addr 0x5810c, Direction=In
    // RCD CW 0x19 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW1A_ChA_D0;     // Byte offset 0x21a, CSR Addr 0x5810d, Direction=In
    // RCD CW 0x1A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW1B_ChA_D0;     // Byte offset 0x21b, CSR Addr 0x5810d, Direction=In
    // RCD CW 0x1B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW1C_ChA_D0;     // Byte offset 0x21c, CSR Addr 0x5810e, Direction=In
    // RCD CW 0x1C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW1D_ChA_D0;     // Byte offset 0x21d, CSR Addr 0x5810e, Direction=In
    // RCD CW 0x1D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW1E_ChA_D0;     // Byte offset 0x21e, CSR Addr 0x5810f, Direction=In
    // RCD CW 0x1E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW1F_ChA_D0;     // Byte offset 0x21f, CSR Addr 0x5810f, Direction=In
    // RCD CW 0x1F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW20_ChA_D0;     // Byte offset 0x220, CSR Addr 0x58110, Direction=In
    // RCD CW 0x20 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW21_ChA_D0;     // Byte offset 0x221, CSR Addr 0x58110, Direction=In
    // RCD CW 0x21 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW22_ChA_D0;     // Byte offset 0x222, CSR Addr 0x58111, Direction=In
    // RCD CW 0x22 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW23_ChA_D0;     // Byte offset 0x223, CSR Addr 0x58111, Direction=In
    // RCD CW 0x23 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW24_ChA_D0;     // Byte offset 0x224, CSR Addr 0x58112, Direction=In
    // RCD CW 0x24 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW25_ChA_D0;     // Byte offset 0x225, CSR Addr 0x58112, Direction=In
    // RCD CW 0x25 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW26_ChA_D0;     // Byte offset 0x226, CSR Addr 0x58113, Direction=In
    // RCD CW 0x26 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW27_ChA_D0;     // Byte offset 0x227, CSR Addr 0x58113, Direction=In
    // RCD CW 0x27 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW28_ChA_D0;     // Byte offset 0x228, CSR Addr 0x58114, Direction=In
    // RCD CW 0x28 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW29_ChA_D0;     // Byte offset 0x229, CSR Addr 0x58114, Direction=In
    // RCD CW 0x29 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW2A_ChA_D0;     // Byte offset 0x22a, CSR Addr 0x58115, Direction=In
    // RCD CW 0x2A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW2B_ChA_D0;     // Byte offset 0x22b, CSR Addr 0x58115, Direction=In
    // RCD CW 0x2B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW2C_ChA_D0;     // Byte offset 0x22c, CSR Addr 0x58116, Direction=In
    // RCD CW 0x2C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW2D_ChA_D0;     // Byte offset 0x22d, CSR Addr 0x58116, Direction=In
    // RCD CW 0x2D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW2E_ChA_D0;     // Byte offset 0x22e, CSR Addr 0x58117, Direction=In
    // RCD CW 0x2E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW2F_ChA_D0;     // Byte offset 0x22f, CSR Addr 0x58117, Direction=In
    // RCD CW 0x2F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW30_ChA_D0;     // Byte offset 0x230, CSR Addr 0x58118, Direction=In
    // RCD CW 0x30 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW31_ChA_D0;     // Byte offset 0x231, CSR Addr 0x58118, Direction=In
    // RCD CW 0x31 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW32_ChA_D0;     // Byte offset 0x232, CSR Addr 0x58119, Direction=In
    // RCD CW 0x32 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW33_ChA_D0;     // Byte offset 0x233, CSR Addr 0x58119, Direction=In
    // RCD CW 0x33 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW34_ChA_D0;     // Byte offset 0x234, CSR Addr 0x5811a, Direction=In
    // RCD CW 0x34 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW35_ChA_D0;     // Byte offset 0x235, CSR Addr 0x5811a, Direction=In
    // RCD CW 0x35 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW36_ChA_D0;     // Byte offset 0x236, CSR Addr 0x5811b, Direction=In
    // RCD CW 0x36 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW37_ChA_D0;     // Byte offset 0x237, CSR Addr 0x5811b, Direction=In
    // RCD CW 0x37 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW38_ChA_D0;     // Byte offset 0x238, CSR Addr 0x5811c, Direction=In
    // RCD CW 0x38 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW39_ChA_D0;     // Byte offset 0x239, CSR Addr 0x5811c, Direction=In
    // RCD CW 0x39 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW3A_ChA_D0;     // Byte offset 0x23a, CSR Addr 0x5811d, Direction=In
    // RCD CW 0x3A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW3B_ChA_D0;     // Byte offset 0x23b, CSR Addr 0x5811d, Direction=In
    // RCD CW 0x3B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW3C_ChA_D0;     // Byte offset 0x23c, CSR Addr 0x5811e, Direction=In
    // RCD CW 0x3C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW3D_ChA_D0;     // Byte offset 0x23d, CSR Addr 0x5811e, Direction=In
    // RCD CW 0x3D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW3E_ChA_D0;     // Byte offset 0x23e, CSR Addr 0x5811f, Direction=In
    // RCD CW 0x3E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW3F_ChA_D0;     // Byte offset 0x23f, CSR Addr 0x5811f, Direction=In
    // RCD CW 0x3F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW40_ChA_D0;     // Byte offset 0x240, CSR Addr 0x58120, Direction=In
    // RCD CW 0x40 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW41_ChA_D0;     // Byte offset 0x241, CSR Addr 0x58120, Direction=In
    // RCD CW 0x41 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW42_ChA_D0;     // Byte offset 0x242, CSR Addr 0x58121, Direction=In
    // RCD CW 0x42 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW43_ChA_D0;     // Byte offset 0x243, CSR Addr 0x58121, Direction=In
    // RCD CW 0x43 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW44_ChA_D0;     // Byte offset 0x244, CSR Addr 0x58122, Direction=In
    // RCD CW 0x44 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW45_ChA_D0;     // Byte offset 0x245, CSR Addr 0x58122, Direction=In
    // RCD CW 0x45 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW46_ChA_D0;     // Byte offset 0x246, CSR Addr 0x58123, Direction=In
    // RCD CW 0x46 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW47_ChA_D0;     // Byte offset 0x247, CSR Addr 0x58123, Direction=In
    // RCD CW 0x47 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW48_ChA_D0;     // Byte offset 0x248, CSR Addr 0x58124, Direction=In
    // RCD CW 0x48 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW49_ChA_D0;     // Byte offset 0x249, CSR Addr 0x58124, Direction=In
    // RCD CW 0x49 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW4A_ChA_D0;     // Byte offset 0x24a, CSR Addr 0x58125, Direction=In
    // RCD CW 0x4A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW4B_ChA_D0;     // Byte offset 0x24b, CSR Addr 0x58125, Direction=In
    // RCD CW 0x4B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW4C_ChA_D0;     // Byte offset 0x24c, CSR Addr 0x58126, Direction=In
    // RCD CW 0x4C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW4D_ChA_D0;     // Byte offset 0x24d, CSR Addr 0x58126, Direction=In
    // RCD CW 0x4D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW4E_ChA_D0;     // Byte offset 0x24e, CSR Addr 0x58127, Direction=In
    // RCD CW 0x4E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW4F_ChA_D0;     // Byte offset 0x24f, CSR Addr 0x58127, Direction=In
    // RCD CW 0x4F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW50_ChA_D0;     // Byte offset 0x250, CSR Addr 0x58128, Direction=In
    // RCD CW 0x50 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW51_ChA_D0;     // Byte offset 0x251, CSR Addr 0x58128, Direction=In
    // RCD CW 0x51 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW52_ChA_D0;     // Byte offset 0x252, CSR Addr 0x58129, Direction=In
    // RCD CW 0x52 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW53_ChA_D0;     // Byte offset 0x253, CSR Addr 0x58129, Direction=In
    // RCD CW 0x53 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW54_ChA_D0;     // Byte offset 0x254, CSR Addr 0x5812a, Direction=In
    // RCD CW 0x54 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW55_ChA_D0;     // Byte offset 0x255, CSR Addr 0x5812a, Direction=In
    // RCD CW 0x55 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW56_ChA_D0;     // Byte offset 0x256, CSR Addr 0x5812b, Direction=In
    // RCD CW 0x56 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW57_ChA_D0;     // Byte offset 0x257, CSR Addr 0x5812b, Direction=In
    // RCD CW 0x57 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW58_ChA_D0;     // Byte offset 0x258, CSR Addr 0x5812c, Direction=In
    // RCD CW 0x58 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW59_ChA_D0;     // Byte offset 0x259, CSR Addr 0x5812c, Direction=In
    // RCD CW 0x59 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW5A_ChA_D0;     // Byte offset 0x25a, CSR Addr 0x5812d, Direction=In
    // RCD CW 0x5A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW5B_ChA_D0;     // Byte offset 0x25b, CSR Addr 0x5812d, Direction=In
    // RCD CW 0x5B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW5C_ChA_D0;     // Byte offset 0x25c, CSR Addr 0x5812e, Direction=In
    // RCD CW 0x5C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW5D_ChA_D0;     // Byte offset 0x25d, CSR Addr 0x5812e, Direction=In
    // RCD CW 0x5D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW5E_ChA_D0;     // Byte offset 0x25e, CSR Addr 0x5812f, Direction=In
    // RCD CW 0x5E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW5F_ChA_D0;     // Byte offset 0x25f, CSR Addr 0x5812f, Direction=In
    // RCD CW 0x5F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW60_ChA_D0;     // Byte offset 0x260, CSR Addr 0x58130, Direction=In
    // RCD CW 0x60 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW61_ChA_D0;     // Byte offset 0x261, CSR Addr 0x58130, Direction=In
    // RCD CW 0x61 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW62_ChA_D0;     // Byte offset 0x262, CSR Addr 0x58131, Direction=In
    // RCD CW 0x62 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW63_ChA_D0;     // Byte offset 0x263, CSR Addr 0x58131, Direction=In
    // RCD CW 0x63 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW64_ChA_D0;     // Byte offset 0x264, CSR Addr 0x58132, Direction=In
    // RCD CW 0x64 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW65_ChA_D0;     // Byte offset 0x265, CSR Addr 0x58132, Direction=In
    // RCD CW 0x65 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW66_ChA_D0;     // Byte offset 0x266, CSR Addr 0x58133, Direction=In
    // RCD CW 0x66 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW67_ChA_D0;     // Byte offset 0x267, CSR Addr 0x58133, Direction=In
    // RCD CW 0x67 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW68_ChA_D0;     // Byte offset 0x268, CSR Addr 0x58134, Direction=In
    // RCD CW 0x68 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW69_ChA_D0;     // Byte offset 0x269, CSR Addr 0x58134, Direction=In
    // RCD CW 0x69 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW6A_ChA_D0;     // Byte offset 0x26a, CSR Addr 0x58135, Direction=In
    // RCD CW 0x6A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW6B_ChA_D0;     // Byte offset 0x26b, CSR Addr 0x58135, Direction=In
    // RCD CW 0x6B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW6C_ChA_D0;     // Byte offset 0x26c, CSR Addr 0x58136, Direction=In
    // RCD CW 0x6C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW6D_ChA_D0;     // Byte offset 0x26d, CSR Addr 0x58136, Direction=In
    // RCD CW 0x6D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW6E_ChA_D0;     // Byte offset 0x26e, CSR Addr 0x58137, Direction=In
    // RCD CW 0x6E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW6F_ChA_D0;     // Byte offset 0x26f, CSR Addr 0x58137, Direction=In
    // RCD CW 0x6F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW70_ChA_D0;     // Byte offset 0x270, CSR Addr 0x58138, Direction=In
    // RCD CW 0x70 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW71_ChA_D0;     // Byte offset 0x271, CSR Addr 0x58138, Direction=In
    // RCD CW 0x71 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW72_ChA_D0;     // Byte offset 0x272, CSR Addr 0x58139, Direction=In
    // RCD CW 0x72 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW73_ChA_D0;     // Byte offset 0x273, CSR Addr 0x58139, Direction=In
    // RCD CW 0x73 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW74_ChA_D0;     // Byte offset 0x274, CSR Addr 0x5813a, Direction=In
    // RCD CW 0x74 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW75_ChA_D0;     // Byte offset 0x275, CSR Addr 0x5813a, Direction=In
    // RCD CW 0x75 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW76_ChA_D0;     // Byte offset 0x276, CSR Addr 0x5813b, Direction=In
    // RCD CW 0x76 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW77_ChA_D0;     // Byte offset 0x277, CSR Addr 0x5813b, Direction=In
    // RCD CW 0x77 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW78_ChA_D0;     // Byte offset 0x278, CSR Addr 0x5813c, Direction=In
    // RCD CW 0x78 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW79_ChA_D0;     // Byte offset 0x279, CSR Addr 0x5813c, Direction=In
    // RCD CW 0x79 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW7A_ChA_D0;     // Byte offset 0x27a, CSR Addr 0x5813d, Direction=In
    // RCD CW 0x7A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW7B_ChA_D0;     // Byte offset 0x27b, CSR Addr 0x5813d, Direction=In
    // RCD CW 0x7B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW7C_ChA_D0;     // Byte offset 0x27c, CSR Addr 0x5813e, Direction=In
    // RCD CW 0x7C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW7D_ChA_D0;     // Byte offset 0x27d, CSR Addr 0x5813e, Direction=In
    // RCD CW 0x7D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW7E_ChA_D0;     // Byte offset 0x27e, CSR Addr 0x5813f, Direction=In
    // RCD CW 0x7E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW7F_ChA_D0;     // Byte offset 0x27f, CSR Addr 0x5813f, Direction=In
    // RCD CW 0x7F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW00_ChA_D0;     // Byte offset 0x280, CSR Addr 0x58140, Direction=In
    // DB CW 0x00 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW01_ChA_D0;     // Byte offset 0x281, CSR Addr 0x58140, Direction=In
    // DB CW 0x01 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW02_ChA_D0;     // Byte offset 0x282, CSR Addr 0x58141, Direction=In
    // DB CW 0x02 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW03_ChA_D0;     // Byte offset 0x283, CSR Addr 0x58141, Direction=In
    // DB CW 0x03 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW04_ChA_D0;     // Byte offset 0x284, CSR Addr 0x58142, Direction=In
    // DB CW 0x04 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW05_ChA_D0;     // Byte offset 0x285, CSR Addr 0x58142, Direction=In
    // DB CW 0x05 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW06_ChA_D0;     // Byte offset 0x286, CSR Addr 0x58143, Direction=In
    // DB CW 0x06 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW07_ChA_D0;     // Byte offset 0x287, CSR Addr 0x58143, Direction=In
    // DB CW 0x07 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW08_ChA_D0;     // Byte offset 0x288, CSR Addr 0x58144, Direction=In
    // DB CW 0x08 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW09_ChA_D0;     // Byte offset 0x289, CSR Addr 0x58144, Direction=In
    // DB CW 0x09 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW0A_ChA_D0;     // Byte offset 0x28a, CSR Addr 0x58145, Direction=In
    // DB CW 0x0A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW0B_ChA_D0;     // Byte offset 0x28b, CSR Addr 0x58145, Direction=In
    // DB CW 0x0B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW0C_ChA_D0;     // Byte offset 0x28c, CSR Addr 0x58146, Direction=In
    // DB CW 0x0C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW0D_ChA_D0;     // Byte offset 0x28d, CSR Addr 0x58146, Direction=In
    // DB CW 0x0D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW0E_ChA_D0;     // Byte offset 0x28e, CSR Addr 0x58147, Direction=In
    // DB CW 0x0E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW0F_ChA_D0;     // Byte offset 0x28f, CSR Addr 0x58147, Direction=In
    // DB CW 0x0F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW10_ChA_D0;     // Byte offset 0x290, CSR Addr 0x58148, Direction=In
    // DB CW 0x10 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW11_ChA_D0;     // Byte offset 0x291, CSR Addr 0x58148, Direction=In
    // DB CW 0x11 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW12_ChA_D0;     // Byte offset 0x292, CSR Addr 0x58149, Direction=In
    // DB CW 0x12 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW13_ChA_D0;     // Byte offset 0x293, CSR Addr 0x58149, Direction=In
    // DB CW 0x13 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW14_ChA_D0;     // Byte offset 0x294, CSR Addr 0x5814a, Direction=In
    // DB CW 0x14 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW15_ChA_D0;     // Byte offset 0x295, CSR Addr 0x5814a, Direction=In
    // DB CW 0x15 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW16_ChA_D0;     // Byte offset 0x296, CSR Addr 0x5814b, Direction=In
    // DB CW 0x16 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW17_ChA_D0;     // Byte offset 0x297, CSR Addr 0x5814b, Direction=In
    // DB CW 0x17 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW18_ChA_D0;     // Byte offset 0x298, CSR Addr 0x5814c, Direction=In
    // DB CW 0x18 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW19_ChA_D0;     // Byte offset 0x299, CSR Addr 0x5814c, Direction=In
    // DB CW 0x19 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW1A_ChA_D0;     // Byte offset 0x29a, CSR Addr 0x5814d, Direction=In
    // DB CW 0x1A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW1B_ChA_D0;     // Byte offset 0x29b, CSR Addr 0x5814d, Direction=In
    // DB CW 0x1B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW1C_ChA_D0;     // Byte offset 0x29c, CSR Addr 0x5814e, Direction=In
    // DB CW 0x1C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW1D_ChA_D0;     // Byte offset 0x29d, CSR Addr 0x5814e, Direction=In
    // DB CW 0x1D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW1E_ChA_D0;     // Byte offset 0x29e, CSR Addr 0x5814f, Direction=In
    // DB CW 0x1E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW1F_ChA_D0;     // Byte offset 0x29f, CSR Addr 0x5814f, Direction=In
    // DB CW 0x1F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW20_ChA_D0;     // Byte offset 0x2a0, CSR Addr 0x58150, Direction=In
    // DB CW 0x20 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW21_ChA_D0;     // Byte offset 0x2a1, CSR Addr 0x58150, Direction=In
    // DB CW 0x21 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW22_ChA_D0;     // Byte offset 0x2a2, CSR Addr 0x58151, Direction=In
    // DB CW 0x22 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW23_ChA_D0;     // Byte offset 0x2a3, CSR Addr 0x58151, Direction=In
    // DB CW 0x23 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW24_ChA_D0;     // Byte offset 0x2a4, CSR Addr 0x58152, Direction=In
    // DB CW 0x24 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW25_ChA_D0;     // Byte offset 0x2a5, CSR Addr 0x58152, Direction=In
    // DB CW 0x25 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW26_ChA_D0;     // Byte offset 0x2a6, CSR Addr 0x58153, Direction=In
    // DB CW 0x26 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW27_ChA_D0;     // Byte offset 0x2a7, CSR Addr 0x58153, Direction=In
    // DB CW 0x27 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW28_ChA_D0;     // Byte offset 0x2a8, CSR Addr 0x58154, Direction=In
    // DB CW 0x28 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW29_ChA_D0;     // Byte offset 0x2a9, CSR Addr 0x58154, Direction=In
    // DB CW 0x29 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW2A_ChA_D0;     // Byte offset 0x2aa, CSR Addr 0x58155, Direction=In
    // DB CW 0x2A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW2B_ChA_D0;     // Byte offset 0x2ab, CSR Addr 0x58155, Direction=In
    // DB CW 0x2B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW2C_ChA_D0;     // Byte offset 0x2ac, CSR Addr 0x58156, Direction=In
    // DB CW 0x2C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW2D_ChA_D0;     // Byte offset 0x2ad, CSR Addr 0x58156, Direction=In
    // DB CW 0x2D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW2E_ChA_D0;     // Byte offset 0x2ae, CSR Addr 0x58157, Direction=In
    // DB CW 0x2E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW2F_ChA_D0;     // Byte offset 0x2af, CSR Addr 0x58157, Direction=In
    // DB CW 0x2F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW30_ChA_D0;     // Byte offset 0x2b0, CSR Addr 0x58158, Direction=In
    // DB CW 0x30 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW31_ChA_D0;     // Byte offset 0x2b1, CSR Addr 0x58158, Direction=In
    // DB CW 0x31 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW32_ChA_D0;     // Byte offset 0x2b2, CSR Addr 0x58159, Direction=In
    // DB CW 0x32 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW33_ChA_D0;     // Byte offset 0x2b3, CSR Addr 0x58159, Direction=In
    // DB CW 0x33 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW34_ChA_D0;     // Byte offset 0x2b4, CSR Addr 0x5815a, Direction=In
    // DB CW 0x34 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW35_ChA_D0;     // Byte offset 0x2b5, CSR Addr 0x5815a, Direction=In
    // DB CW 0x35 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW36_ChA_D0;     // Byte offset 0x2b6, CSR Addr 0x5815b, Direction=In
    // DB CW 0x36 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW37_ChA_D0;     // Byte offset 0x2b7, CSR Addr 0x5815b, Direction=In
    // DB CW 0x37 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW38_ChA_D0;     // Byte offset 0x2b8, CSR Addr 0x5815c, Direction=In
    // DB CW 0x38 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW39_ChA_D0;     // Byte offset 0x2b9, CSR Addr 0x5815c, Direction=In
    // DB CW 0x39 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW3A_ChA_D0;     // Byte offset 0x2ba, CSR Addr 0x5815d, Direction=In
    // DB CW 0x3A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW3B_ChA_D0;     // Byte offset 0x2bb, CSR Addr 0x5815d, Direction=In
    // DB CW 0x3B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW3C_ChA_D0;     // Byte offset 0x2bc, CSR Addr 0x5815e, Direction=In
    // DB CW 0x3C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW3D_ChA_D0;     // Byte offset 0x2bd, CSR Addr 0x5815e, Direction=In
    // DB CW 0x3D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW3E_ChA_D0;     // Byte offset 0x2be, CSR Addr 0x5815f, Direction=In
    // DB CW 0x3E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW3F_ChA_D0;     // Byte offset 0x2bf, CSR Addr 0x5815f, Direction=In
    // DB CW 0x3F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW40_ChA_D0;     // Byte offset 0x2c0, CSR Addr 0x58160, Direction=In
    // DB CW 0x40 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW41_ChA_D0;     // Byte offset 0x2c1, CSR Addr 0x58160, Direction=In
    // DB CW 0x41 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW42_ChA_D0;     // Byte offset 0x2c2, CSR Addr 0x58161, Direction=In
    // DB CW 0x42 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW43_ChA_D0;     // Byte offset 0x2c3, CSR Addr 0x58161, Direction=In
    // DB CW 0x43 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW44_ChA_D0;     // Byte offset 0x2c4, CSR Addr 0x58162, Direction=In
    // DB CW 0x44 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW45_ChA_D0;     // Byte offset 0x2c5, CSR Addr 0x58162, Direction=In
    // DB CW 0x45 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW46_ChA_D0;     // Byte offset 0x2c6, CSR Addr 0x58163, Direction=In
    // DB CW 0x46 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW47_ChA_D0;     // Byte offset 0x2c7, CSR Addr 0x58163, Direction=In
    // DB CW 0x47 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW48_ChA_D0;     // Byte offset 0x2c8, CSR Addr 0x58164, Direction=In
    // DB CW 0x48 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW49_ChA_D0;     // Byte offset 0x2c9, CSR Addr 0x58164, Direction=In
    // DB CW 0x49 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW4A_ChA_D0;     // Byte offset 0x2ca, CSR Addr 0x58165, Direction=In
    // DB CW 0x4A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW4B_ChA_D0;     // Byte offset 0x2cb, CSR Addr 0x58165, Direction=In
    // DB CW 0x4B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW4C_ChA_D0;     // Byte offset 0x2cc, CSR Addr 0x58166, Direction=In
    // DB CW 0x4C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW4D_ChA_D0;     // Byte offset 0x2cd, CSR Addr 0x58166, Direction=In
    // DB CW 0x4D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW4E_ChA_D0;     // Byte offset 0x2ce, CSR Addr 0x58167, Direction=In
    // DB CW 0x4E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW4F_ChA_D0;     // Byte offset 0x2cf, CSR Addr 0x58167, Direction=In
    // DB CW 0x4F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW50_ChA_D0;     // Byte offset 0x2d0, CSR Addr 0x58168, Direction=In
    // DB CW 0x50 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW51_ChA_D0;     // Byte offset 0x2d1, CSR Addr 0x58168, Direction=In
    // DB CW 0x51 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW52_ChA_D0;     // Byte offset 0x2d2, CSR Addr 0x58169, Direction=In
    // DB CW 0x52 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW53_ChA_D0;     // Byte offset 0x2d3, CSR Addr 0x58169, Direction=In
    // DB CW 0x53 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW54_ChA_D0;     // Byte offset 0x2d4, CSR Addr 0x5816a, Direction=In
    // DB CW 0x54 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW55_ChA_D0;     // Byte offset 0x2d5, CSR Addr 0x5816a, Direction=In
    // DB CW 0x55 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW56_ChA_D0;     // Byte offset 0x2d6, CSR Addr 0x5816b, Direction=In
    // DB CW 0x56 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW57_ChA_D0;     // Byte offset 0x2d7, CSR Addr 0x5816b, Direction=In
    // DB CW 0x57 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW58_ChA_D0;     // Byte offset 0x2d8, CSR Addr 0x5816c, Direction=In
    // DB CW 0x58 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW59_ChA_D0;     // Byte offset 0x2d9, CSR Addr 0x5816c, Direction=In
    // DB CW 0x59 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW5A_ChA_D0;     // Byte offset 0x2da, CSR Addr 0x5816d, Direction=In
    // DB CW 0x5A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW5B_ChA_D0;     // Byte offset 0x2db, CSR Addr 0x5816d, Direction=In
    // DB CW 0x5B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW5C_ChA_D0;     // Byte offset 0x2dc, CSR Addr 0x5816e, Direction=In
    // DB CW 0x5C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW5D_ChA_D0;     // Byte offset 0x2dd, CSR Addr 0x5816e, Direction=In
    // DB CW 0x5D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW5E_ChA_D0;     // Byte offset 0x2de, CSR Addr 0x5816f, Direction=In
    // DB CW 0x5E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW5F_ChA_D0;     // Byte offset 0x2df, CSR Addr 0x5816f, Direction=In
    // DB CW 0x5F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW60_ChA_D0;     // Byte offset 0x2e0, CSR Addr 0x58170, Direction=In
    // DB CW 0x60 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW61_ChA_D0;     // Byte offset 0x2e1, CSR Addr 0x58170, Direction=In
    // DB CW 0x61 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW62_ChA_D0;     // Byte offset 0x2e2, CSR Addr 0x58171, Direction=In
    // DB CW 0x62 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW63_ChA_D0;     // Byte offset 0x2e3, CSR Addr 0x58171, Direction=In
    // DB CW 0x63 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW64_ChA_D0;     // Byte offset 0x2e4, CSR Addr 0x58172, Direction=In
    // DB CW 0x64 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW65_ChA_D0;     // Byte offset 0x2e5, CSR Addr 0x58172, Direction=In
    // DB CW 0x65 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW66_ChA_D0;     // Byte offset 0x2e6, CSR Addr 0x58173, Direction=In
    // DB CW 0x66 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW67_ChA_D0;     // Byte offset 0x2e7, CSR Addr 0x58173, Direction=In
    // DB CW 0x67 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW68_ChA_D0;     // Byte offset 0x2e8, CSR Addr 0x58174, Direction=In
    // DB CW 0x68 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW69_ChA_D0;     // Byte offset 0x2e9, CSR Addr 0x58174, Direction=In
    // DB CW 0x69 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW6A_ChA_D0;     // Byte offset 0x2ea, CSR Addr 0x58175, Direction=In
    // DB CW 0x6A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW6B_ChA_D0;     // Byte offset 0x2eb, CSR Addr 0x58175, Direction=In
    // DB CW 0x6B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW6C_ChA_D0;     // Byte offset 0x2ec, CSR Addr 0x58176, Direction=In
    // DB CW 0x6C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW6D_ChA_D0;     // Byte offset 0x2ed, CSR Addr 0x58176, Direction=In
    // DB CW 0x6D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW6E_ChA_D0;     // Byte offset 0x2ee, CSR Addr 0x58177, Direction=In
    // DB CW 0x6E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW6F_ChA_D0;     // Byte offset 0x2ef, CSR Addr 0x58177, Direction=In
    // DB CW 0x6F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW70_ChA_D0;     // Byte offset 0x2f0, CSR Addr 0x58178, Direction=In
    // DB CW 0x70 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW71_ChA_D0;     // Byte offset 0x2f1, CSR Addr 0x58178, Direction=In
    // DB CW 0x71 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW72_ChA_D0;     // Byte offset 0x2f2, CSR Addr 0x58179, Direction=In
    // DB CW 0x72 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW73_ChA_D0;     // Byte offset 0x2f3, CSR Addr 0x58179, Direction=In
    // DB CW 0x73 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW74_ChA_D0;     // Byte offset 0x2f4, CSR Addr 0x5817a, Direction=In
    // DB CW 0x74 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW75_ChA_D0;     // Byte offset 0x2f5, CSR Addr 0x5817a, Direction=In
    // DB CW 0x75 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW76_ChA_D0;     // Byte offset 0x2f6, CSR Addr 0x5817b, Direction=In
    // DB CW 0x76 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW77_ChA_D0;     // Byte offset 0x2f7, CSR Addr 0x5817b, Direction=In
    // DB CW 0x77 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW78_ChA_D0;     // Byte offset 0x2f8, CSR Addr 0x5817c, Direction=In
    // DB CW 0x78 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW79_ChA_D0;     // Byte offset 0x2f9, CSR Addr 0x5817c, Direction=In
    // DB CW 0x79 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW7A_ChA_D0;     // Byte offset 0x2fa, CSR Addr 0x5817d, Direction=In
    // DB CW 0x7A setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW7B_ChA_D0;     // Byte offset 0x2fb, CSR Addr 0x5817d, Direction=In
    // DB CW 0x7B setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW7C_ChA_D0;     // Byte offset 0x2fc, CSR Addr 0x5817e, Direction=In
    // DB CW 0x7C setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW7D_ChA_D0;     // Byte offset 0x2fd, CSR Addr 0x5817e, Direction=In
    // DB CW 0x7D setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW7E_ChA_D0;     // Byte offset 0x2fe, CSR Addr 0x5817f, Direction=In
    // DB CW 0x7E setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  BCW7F_ChA_D0;     // Byte offset 0x2ff, CSR Addr 0x5817f, Direction=In
    // DB CW 0x7F setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  RCW00_ChA_D1;     // Byte offset 0x300, CSR Addr 0x58180, Direction=In
    // RCD CW 0x00 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW01_ChA_D1;     // Byte offset 0x301, CSR Addr 0x58180, Direction=In
    // RCD CW 0x01 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW02_ChA_D1;     // Byte offset 0x302, CSR Addr 0x58181, Direction=In
    // RCD CW 0x02 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW03_ChA_D1;     // Byte offset 0x303, CSR Addr 0x58181, Direction=In
    // RCD CW 0x03 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW04_ChA_D1;     // Byte offset 0x304, CSR Addr 0x58182, Direction=In
    // RCD CW 0x04 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW05_ChA_D1;     // Byte offset 0x305, CSR Addr 0x58182, Direction=In
    // RCD CW 0x05 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW06_ChA_D1;     // Byte offset 0x306, CSR Addr 0x58183, Direction=In
    // RCD CW 0x06 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW07_ChA_D1;     // Byte offset 0x307, CSR Addr 0x58183, Direction=In
    // RCD CW 0x07 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW08_ChA_D1;     // Byte offset 0x308, CSR Addr 0x58184, Direction=In
    // RCD CW 0x08 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW09_ChA_D1;     // Byte offset 0x309, CSR Addr 0x58184, Direction=In
    // RCD CW 0x09 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW0A_ChA_D1;     // Byte offset 0x30a, CSR Addr 0x58185, Direction=In
    // RCD CW 0x0A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW0B_ChA_D1;     // Byte offset 0x30b, CSR Addr 0x58185, Direction=In
    // RCD CW 0x0B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW0C_ChA_D1;     // Byte offset 0x30c, CSR Addr 0x58186, Direction=In
    // RCD CW 0x0C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW0D_ChA_D1;     // Byte offset 0x30d, CSR Addr 0x58186, Direction=In
    // RCD CW 0x0D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW0E_ChA_D1;     // Byte offset 0x30e, CSR Addr 0x58187, Direction=In
    // RCD CW 0x0E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW0F_ChA_D1;     // Byte offset 0x30f, CSR Addr 0x58187, Direction=In
    // RCD CW 0x0F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW10_ChA_D1;     // Byte offset 0x310, CSR Addr 0x58188, Direction=In
    // RCD CW 0x10 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW11_ChA_D1;     // Byte offset 0x311, CSR Addr 0x58188, Direction=In
    // RCD CW 0x11 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW12_ChA_D1;     // Byte offset 0x312, CSR Addr 0x58189, Direction=In
    // RCD CW 0x12 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW13_ChA_D1;     // Byte offset 0x313, CSR Addr 0x58189, Direction=In
    // RCD CW 0x13 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW14_ChA_D1;     // Byte offset 0x314, CSR Addr 0x5818a, Direction=In
    // RCD CW 0x14 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW15_ChA_D1;     // Byte offset 0x315, CSR Addr 0x5818a, Direction=In
    // RCD CW 0x15 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW16_ChA_D1;     // Byte offset 0x316, CSR Addr 0x5818b, Direction=In
    // RCD CW 0x16 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW17_ChA_D1;     // Byte offset 0x317, CSR Addr 0x5818b, Direction=In
    // RCD CW 0x17 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW18_ChA_D1;     // Byte offset 0x318, CSR Addr 0x5818c, Direction=In
    // RCD CW 0x18 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW19_ChA_D1;     // Byte offset 0x319, CSR Addr 0x5818c, Direction=In
    // RCD CW 0x19 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW1A_ChA_D1;     // Byte offset 0x31a, CSR Addr 0x5818d, Direction=In
    // RCD CW 0x1A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW1B_ChA_D1;     // Byte offset 0x31b, CSR Addr 0x5818d, Direction=In
    // RCD CW 0x1B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW1C_ChA_D1;     // Byte offset 0x31c, CSR Addr 0x5818e, Direction=In
    // RCD CW 0x1C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW1D_ChA_D1;     // Byte offset 0x31d, CSR Addr 0x5818e, Direction=In
    // RCD CW 0x1D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW1E_ChA_D1;     // Byte offset 0x31e, CSR Addr 0x5818f, Direction=In
    // RCD CW 0x1E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW1F_ChA_D1;     // Byte offset 0x31f, CSR Addr 0x5818f, Direction=In
    // RCD CW 0x1F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW20_ChA_D1;     // Byte offset 0x320, CSR Addr 0x58190, Direction=In
    // RCD CW 0x20 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW21_ChA_D1;     // Byte offset 0x321, CSR Addr 0x58190, Direction=In
    // RCD CW 0x21 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW22_ChA_D1;     // Byte offset 0x322, CSR Addr 0x58191, Direction=In
    // RCD CW 0x22 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW23_ChA_D1;     // Byte offset 0x323, CSR Addr 0x58191, Direction=In
    // RCD CW 0x23 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW24_ChA_D1;     // Byte offset 0x324, CSR Addr 0x58192, Direction=In
    // RCD CW 0x24 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW25_ChA_D1;     // Byte offset 0x325, CSR Addr 0x58192, Direction=In
    // RCD CW 0x25 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW26_ChA_D1;     // Byte offset 0x326, CSR Addr 0x58193, Direction=In
    // RCD CW 0x26 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW27_ChA_D1;     // Byte offset 0x327, CSR Addr 0x58193, Direction=In
    // RCD CW 0x27 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW28_ChA_D1;     // Byte offset 0x328, CSR Addr 0x58194, Direction=In
    // RCD CW 0x28 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW29_ChA_D1;     // Byte offset 0x329, CSR Addr 0x58194, Direction=In
    // RCD CW 0x29 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW2A_ChA_D1;     // Byte offset 0x32a, CSR Addr 0x58195, Direction=In
    // RCD CW 0x2A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW2B_ChA_D1;     // Byte offset 0x32b, CSR Addr 0x58195, Direction=In
    // RCD CW 0x2B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW2C_ChA_D1;     // Byte offset 0x32c, CSR Addr 0x58196, Direction=In
    // RCD CW 0x2C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW2D_ChA_D1;     // Byte offset 0x32d, CSR Addr 0x58196, Direction=In
    // RCD CW 0x2D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW2E_ChA_D1;     // Byte offset 0x32e, CSR Addr 0x58197, Direction=In
    // RCD CW 0x2E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW2F_ChA_D1;     // Byte offset 0x32f, CSR Addr 0x58197, Direction=In
    // RCD CW 0x2F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW30_ChA_D1;     // Byte offset 0x330, CSR Addr 0x58198, Direction=In
    // RCD CW 0x30 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW31_ChA_D1;     // Byte offset 0x331, CSR Addr 0x58198, Direction=In
    // RCD CW 0x31 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW32_ChA_D1;     // Byte offset 0x332, CSR Addr 0x58199, Direction=In
    // RCD CW 0x32 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW33_ChA_D1;     // Byte offset 0x333, CSR Addr 0x58199, Direction=In
    // RCD CW 0x33 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW34_ChA_D1;     // Byte offset 0x334, CSR Addr 0x5819a, Direction=In
    // RCD CW 0x34 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW35_ChA_D1;     // Byte offset 0x335, CSR Addr 0x5819a, Direction=In
    // RCD CW 0x35 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW36_ChA_D1;     // Byte offset 0x336, CSR Addr 0x5819b, Direction=In
    // RCD CW 0x36 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW37_ChA_D1;     // Byte offset 0x337, CSR Addr 0x5819b, Direction=In
    // RCD CW 0x37 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW38_ChA_D1;     // Byte offset 0x338, CSR Addr 0x5819c, Direction=In
    // RCD CW 0x38 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW39_ChA_D1;     // Byte offset 0x339, CSR Addr 0x5819c, Direction=In
    // RCD CW 0x39 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW3A_ChA_D1;     // Byte offset 0x33a, CSR Addr 0x5819d, Direction=In
    // RCD CW 0x3A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW3B_ChA_D1;     // Byte offset 0x33b, CSR Addr 0x5819d, Direction=In
    // RCD CW 0x3B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW3C_ChA_D1;     // Byte offset 0x33c, CSR Addr 0x5819e, Direction=In
    // RCD CW 0x3C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW3D_ChA_D1;     // Byte offset 0x33d, CSR Addr 0x5819e, Direction=In
    // RCD CW 0x3D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW3E_ChA_D1;     // Byte offset 0x33e, CSR Addr 0x5819f, Direction=In
    // RCD CW 0x3E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW3F_ChA_D1;     // Byte offset 0x33f, CSR Addr 0x5819f, Direction=In
    // RCD CW 0x3F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW40_ChA_D1;     // Byte offset 0x340, CSR Addr 0x581a0, Direction=In
    // RCD CW 0x40 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW41_ChA_D1;     // Byte offset 0x341, CSR Addr 0x581a0, Direction=In
    // RCD CW 0x41 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW42_ChA_D1;     // Byte offset 0x342, CSR Addr 0x581a1, Direction=In
    // RCD CW 0x42 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW43_ChA_D1;     // Byte offset 0x343, CSR Addr 0x581a1, Direction=In
    // RCD CW 0x43 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW44_ChA_D1;     // Byte offset 0x344, CSR Addr 0x581a2, Direction=In
    // RCD CW 0x44 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW45_ChA_D1;     // Byte offset 0x345, CSR Addr 0x581a2, Direction=In
    // RCD CW 0x45 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW46_ChA_D1;     // Byte offset 0x346, CSR Addr 0x581a3, Direction=In
    // RCD CW 0x46 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW47_ChA_D1;     // Byte offset 0x347, CSR Addr 0x581a3, Direction=In
    // RCD CW 0x47 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW48_ChA_D1;     // Byte offset 0x348, CSR Addr 0x581a4, Direction=In
    // RCD CW 0x48 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW49_ChA_D1;     // Byte offset 0x349, CSR Addr 0x581a4, Direction=In
    // RCD CW 0x49 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW4A_ChA_D1;     // Byte offset 0x34a, CSR Addr 0x581a5, Direction=In
    // RCD CW 0x4A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW4B_ChA_D1;     // Byte offset 0x34b, CSR Addr 0x581a5, Direction=In
    // RCD CW 0x4B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW4C_ChA_D1;     // Byte offset 0x34c, CSR Addr 0x581a6, Direction=In
    // RCD CW 0x4C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW4D_ChA_D1;     // Byte offset 0x34d, CSR Addr 0x581a6, Direction=In
    // RCD CW 0x4D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW4E_ChA_D1;     // Byte offset 0x34e, CSR Addr 0x581a7, Direction=In
    // RCD CW 0x4E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW4F_ChA_D1;     // Byte offset 0x34f, CSR Addr 0x581a7, Direction=In
    // RCD CW 0x4F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW50_ChA_D1;     // Byte offset 0x350, CSR Addr 0x581a8, Direction=In
    // RCD CW 0x50 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW51_ChA_D1;     // Byte offset 0x351, CSR Addr 0x581a8, Direction=In
    // RCD CW 0x51 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW52_ChA_D1;     // Byte offset 0x352, CSR Addr 0x581a9, Direction=In
    // RCD CW 0x52 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW53_ChA_D1;     // Byte offset 0x353, CSR Addr 0x581a9, Direction=In
    // RCD CW 0x53 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW54_ChA_D1;     // Byte offset 0x354, CSR Addr 0x581aa, Direction=In
    // RCD CW 0x54 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW55_ChA_D1;     // Byte offset 0x355, CSR Addr 0x581aa, Direction=In
    // RCD CW 0x55 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW56_ChA_D1;     // Byte offset 0x356, CSR Addr 0x581ab, Direction=In
    // RCD CW 0x56 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW57_ChA_D1;     // Byte offset 0x357, CSR Addr 0x581ab, Direction=In
    // RCD CW 0x57 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW58_ChA_D1;     // Byte offset 0x358, CSR Addr 0x581ac, Direction=In
    // RCD CW 0x58 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW59_ChA_D1;     // Byte offset 0x359, CSR Addr 0x581ac, Direction=In
    // RCD CW 0x59 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW5A_ChA_D1;     // Byte offset 0x35a, CSR Addr 0x581ad, Direction=In
    // RCD CW 0x5A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW5B_ChA_D1;     // Byte offset 0x35b, CSR Addr 0x581ad, Direction=In
    // RCD CW 0x5B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW5C_ChA_D1;     // Byte offset 0x35c, CSR Addr 0x581ae, Direction=In
    // RCD CW 0x5C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW5D_ChA_D1;     // Byte offset 0x35d, CSR Addr 0x581ae, Direction=In
    // RCD CW 0x5D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW5E_ChA_D1;     // Byte offset 0x35e, CSR Addr 0x581af, Direction=In
    // RCD CW 0x5E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW5F_ChA_D1;     // Byte offset 0x35f, CSR Addr 0x581af, Direction=In
    // RCD CW 0x5F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW60_ChA_D1;     // Byte offset 0x360, CSR Addr 0x581b0, Direction=In
    // RCD CW 0x60 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW61_ChA_D1;     // Byte offset 0x361, CSR Addr 0x581b0, Direction=In
    // RCD CW 0x61 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW62_ChA_D1;     // Byte offset 0x362, CSR Addr 0x581b1, Direction=In
    // RCD CW 0x62 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW63_ChA_D1;     // Byte offset 0x363, CSR Addr 0x581b1, Direction=In
    // RCD CW 0x63 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW64_ChA_D1;     // Byte offset 0x364, CSR Addr 0x581b2, Direction=In
    // RCD CW 0x64 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW65_ChA_D1;     // Byte offset 0x365, CSR Addr 0x581b2, Direction=In
    // RCD CW 0x65 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW66_ChA_D1;     // Byte offset 0x366, CSR Addr 0x581b3, Direction=In
    // RCD CW 0x66 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW67_ChA_D1;     // Byte offset 0x367, CSR Addr 0x581b3, Direction=In
    // RCD CW 0x67 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW68_ChA_D1;     // Byte offset 0x368, CSR Addr 0x581b4, Direction=In
    // RCD CW 0x68 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW69_ChA_D1;     // Byte offset 0x369, CSR Addr 0x581b4, Direction=In
    // RCD CW 0x69 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW6A_ChA_D1;     // Byte offset 0x36a, CSR Addr 0x581b5, Direction=In
    // RCD CW 0x6A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW6B_ChA_D1;     // Byte offset 0x36b, CSR Addr 0x581b5, Direction=In
    // RCD CW 0x6B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW6C_ChA_D1;     // Byte offset 0x36c, CSR Addr 0x581b6, Direction=In
    // RCD CW 0x6C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW6D_ChA_D1;     // Byte offset 0x36d, CSR Addr 0x581b6, Direction=In
    // RCD CW 0x6D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW6E_ChA_D1;     // Byte offset 0x36e, CSR Addr 0x581b7, Direction=In
    // RCD CW 0x6E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW6F_ChA_D1;     // Byte offset 0x36f, CSR Addr 0x581b7, Direction=In
    // RCD CW 0x6F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW70_ChA_D1;     // Byte offset 0x370, CSR Addr 0x581b8, Direction=In
    // RCD CW 0x70 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW71_ChA_D1;     // Byte offset 0x371, CSR Addr 0x581b8, Direction=In
    // RCD CW 0x71 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW72_ChA_D1;     // Byte offset 0x372, CSR Addr 0x581b9, Direction=In
    // RCD CW 0x72 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW73_ChA_D1;     // Byte offset 0x373, CSR Addr 0x581b9, Direction=In
    // RCD CW 0x73 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW74_ChA_D1;     // Byte offset 0x374, CSR Addr 0x581ba, Direction=In
    // RCD CW 0x74 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW75_ChA_D1;     // Byte offset 0x375, CSR Addr 0x581ba, Direction=In
    // RCD CW 0x75 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW76_ChA_D1;     // Byte offset 0x376, CSR Addr 0x581bb, Direction=In
    // RCD CW 0x76 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW77_ChA_D1;     // Byte offset 0x377, CSR Addr 0x581bb, Direction=In
    // RCD CW 0x77 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW78_ChA_D1;     // Byte offset 0x378, CSR Addr 0x581bc, Direction=In
    // RCD CW 0x78 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW79_ChA_D1;     // Byte offset 0x379, CSR Addr 0x581bc, Direction=In
    // RCD CW 0x79 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW7A_ChA_D1;     // Byte offset 0x37a, CSR Addr 0x581bd, Direction=In
    // RCD CW 0x7A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW7B_ChA_D1;     // Byte offset 0x37b, CSR Addr 0x581bd, Direction=In
    // RCD CW 0x7B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW7C_ChA_D1;     // Byte offset 0x37c, CSR Addr 0x581be, Direction=In
    // RCD CW 0x7C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW7D_ChA_D1;     // Byte offset 0x37d, CSR Addr 0x581be, Direction=In
    // RCD CW 0x7D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW7E_ChA_D1;     // Byte offset 0x37e, CSR Addr 0x581bf, Direction=In
    // RCD CW 0x7E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW7F_ChA_D1;     // Byte offset 0x37f, CSR Addr 0x581bf, Direction=In
    // RCD CW 0x7F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW00_ChA_D1;     // Byte offset 0x380, CSR Addr 0x581c0, Direction=In
    // DB CW 0x00 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW01_ChA_D1;     // Byte offset 0x381, CSR Addr 0x581c0, Direction=In
    // DB CW 0x01 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW02_ChA_D1;     // Byte offset 0x382, CSR Addr 0x581c1, Direction=In
    // DB CW 0x02 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW03_ChA_D1;     // Byte offset 0x383, CSR Addr 0x581c1, Direction=In
    // DB CW 0x03 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW04_ChA_D1;     // Byte offset 0x384, CSR Addr 0x581c2, Direction=In
    // DB CW 0x04 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW05_ChA_D1;     // Byte offset 0x385, CSR Addr 0x581c2, Direction=In
    // DB CW 0x05 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW06_ChA_D1;     // Byte offset 0x386, CSR Addr 0x581c3, Direction=In
    // DB CW 0x06 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW07_ChA_D1;     // Byte offset 0x387, CSR Addr 0x581c3, Direction=In
    // DB CW 0x07 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW08_ChA_D1;     // Byte offset 0x388, CSR Addr 0x581c4, Direction=In
    // DB CW 0x08 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW09_ChA_D1;     // Byte offset 0x389, CSR Addr 0x581c4, Direction=In
    // DB CW 0x09 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW0A_ChA_D1;     // Byte offset 0x38a, CSR Addr 0x581c5, Direction=In
    // DB CW 0x0A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW0B_ChA_D1;     // Byte offset 0x38b, CSR Addr 0x581c5, Direction=In
    // DB CW 0x0B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW0C_ChA_D1;     // Byte offset 0x38c, CSR Addr 0x581c6, Direction=In
    // DB CW 0x0C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW0D_ChA_D1;     // Byte offset 0x38d, CSR Addr 0x581c6, Direction=In
    // DB CW 0x0D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW0E_ChA_D1;     // Byte offset 0x38e, CSR Addr 0x581c7, Direction=In
    // DB CW 0x0E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW0F_ChA_D1;     // Byte offset 0x38f, CSR Addr 0x581c7, Direction=In
    // DB CW 0x0F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW10_ChA_D1;     // Byte offset 0x390, CSR Addr 0x581c8, Direction=In
    // DB CW 0x10 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW11_ChA_D1;     // Byte offset 0x391, CSR Addr 0x581c8, Direction=In
    // DB CW 0x11 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW12_ChA_D1;     // Byte offset 0x392, CSR Addr 0x581c9, Direction=In
    // DB CW 0x12 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW13_ChA_D1;     // Byte offset 0x393, CSR Addr 0x581c9, Direction=In
    // DB CW 0x13 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW14_ChA_D1;     // Byte offset 0x394, CSR Addr 0x581ca, Direction=In
    // DB CW 0x14 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW15_ChA_D1;     // Byte offset 0x395, CSR Addr 0x581ca, Direction=In
    // DB CW 0x15 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW16_ChA_D1;     // Byte offset 0x396, CSR Addr 0x581cb, Direction=In
    // DB CW 0x16 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW17_ChA_D1;     // Byte offset 0x397, CSR Addr 0x581cb, Direction=In
    // DB CW 0x17 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW18_ChA_D1;     // Byte offset 0x398, CSR Addr 0x581cc, Direction=In
    // DB CW 0x18 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW19_ChA_D1;     // Byte offset 0x399, CSR Addr 0x581cc, Direction=In
    // DB CW 0x19 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW1A_ChA_D1;     // Byte offset 0x39a, CSR Addr 0x581cd, Direction=In
    // DB CW 0x1A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW1B_ChA_D1;     // Byte offset 0x39b, CSR Addr 0x581cd, Direction=In
    // DB CW 0x1B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW1C_ChA_D1;     // Byte offset 0x39c, CSR Addr 0x581ce, Direction=In
    // DB CW 0x1C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW1D_ChA_D1;     // Byte offset 0x39d, CSR Addr 0x581ce, Direction=In
    // DB CW 0x1D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW1E_ChA_D1;     // Byte offset 0x39e, CSR Addr 0x581cf, Direction=In
    // DB CW 0x1E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW1F_ChA_D1;     // Byte offset 0x39f, CSR Addr 0x581cf, Direction=In
    // DB CW 0x1F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW20_ChA_D1;     // Byte offset 0x3a0, CSR Addr 0x581d0, Direction=In
    // DB CW 0x20 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW21_ChA_D1;     // Byte offset 0x3a1, CSR Addr 0x581d0, Direction=In
    // DB CW 0x21 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW22_ChA_D1;     // Byte offset 0x3a2, CSR Addr 0x581d1, Direction=In
    // DB CW 0x22 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW23_ChA_D1;     // Byte offset 0x3a3, CSR Addr 0x581d1, Direction=In
    // DB CW 0x23 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW24_ChA_D1;     // Byte offset 0x3a4, CSR Addr 0x581d2, Direction=In
    // DB CW 0x24 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW25_ChA_D1;     // Byte offset 0x3a5, CSR Addr 0x581d2, Direction=In
    // DB CW 0x25 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW26_ChA_D1;     // Byte offset 0x3a6, CSR Addr 0x581d3, Direction=In
    // DB CW 0x26 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW27_ChA_D1;     // Byte offset 0x3a7, CSR Addr 0x581d3, Direction=In
    // DB CW 0x27 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW28_ChA_D1;     // Byte offset 0x3a8, CSR Addr 0x581d4, Direction=In
    // DB CW 0x28 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW29_ChA_D1;     // Byte offset 0x3a9, CSR Addr 0x581d4, Direction=In
    // DB CW 0x29 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW2A_ChA_D1;     // Byte offset 0x3aa, CSR Addr 0x581d5, Direction=In
    // DB CW 0x2A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW2B_ChA_D1;     // Byte offset 0x3ab, CSR Addr 0x581d5, Direction=In
    // DB CW 0x2B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW2C_ChA_D1;     // Byte offset 0x3ac, CSR Addr 0x581d6, Direction=In
    // DB CW 0x2C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW2D_ChA_D1;     // Byte offset 0x3ad, CSR Addr 0x581d6, Direction=In
    // DB CW 0x2D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW2E_ChA_D1;     // Byte offset 0x3ae, CSR Addr 0x581d7, Direction=In
    // DB CW 0x2E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW2F_ChA_D1;     // Byte offset 0x3af, CSR Addr 0x581d7, Direction=In
    // DB CW 0x2F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW30_ChA_D1;     // Byte offset 0x3b0, CSR Addr 0x581d8, Direction=In
    // DB CW 0x30 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW31_ChA_D1;     // Byte offset 0x3b1, CSR Addr 0x581d8, Direction=In
    // DB CW 0x31 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW32_ChA_D1;     // Byte offset 0x3b2, CSR Addr 0x581d9, Direction=In
    // DB CW 0x32 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW33_ChA_D1;     // Byte offset 0x3b3, CSR Addr 0x581d9, Direction=In
    // DB CW 0x33 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW34_ChA_D1;     // Byte offset 0x3b4, CSR Addr 0x581da, Direction=In
    // DB CW 0x34 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW35_ChA_D1;     // Byte offset 0x3b5, CSR Addr 0x581da, Direction=In
    // DB CW 0x35 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW36_ChA_D1;     // Byte offset 0x3b6, CSR Addr 0x581db, Direction=In
    // DB CW 0x36 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW37_ChA_D1;     // Byte offset 0x3b7, CSR Addr 0x581db, Direction=In
    // DB CW 0x37 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW38_ChA_D1;     // Byte offset 0x3b8, CSR Addr 0x581dc, Direction=In
    // DB CW 0x38 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW39_ChA_D1;     // Byte offset 0x3b9, CSR Addr 0x581dc, Direction=In
    // DB CW 0x39 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW3A_ChA_D1;     // Byte offset 0x3ba, CSR Addr 0x581dd, Direction=In
    // DB CW 0x3A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW3B_ChA_D1;     // Byte offset 0x3bb, CSR Addr 0x581dd, Direction=In
    // DB CW 0x3B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW3C_ChA_D1;     // Byte offset 0x3bc, CSR Addr 0x581de, Direction=In
    // DB CW 0x3C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW3D_ChA_D1;     // Byte offset 0x3bd, CSR Addr 0x581de, Direction=In
    // DB CW 0x3D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW3E_ChA_D1;     // Byte offset 0x3be, CSR Addr 0x581df, Direction=In
    // DB CW 0x3E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW3F_ChA_D1;     // Byte offset 0x3bf, CSR Addr 0x581df, Direction=In
    // DB CW 0x3F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW40_ChA_D1;     // Byte offset 0x3c0, CSR Addr 0x581e0, Direction=In
    // DB CW 0x40 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW41_ChA_D1;     // Byte offset 0x3c1, CSR Addr 0x581e0, Direction=In
    // DB CW 0x41 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW42_ChA_D1;     // Byte offset 0x3c2, CSR Addr 0x581e1, Direction=In
    // DB CW 0x42 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW43_ChA_D1;     // Byte offset 0x3c3, CSR Addr 0x581e1, Direction=In
    // DB CW 0x43 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW44_ChA_D1;     // Byte offset 0x3c4, CSR Addr 0x581e2, Direction=In
    // DB CW 0x44 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW45_ChA_D1;     // Byte offset 0x3c5, CSR Addr 0x581e2, Direction=In
    // DB CW 0x45 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW46_ChA_D1;     // Byte offset 0x3c6, CSR Addr 0x581e3, Direction=In
    // DB CW 0x46 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW47_ChA_D1;     // Byte offset 0x3c7, CSR Addr 0x581e3, Direction=In
    // DB CW 0x47 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW48_ChA_D1;     // Byte offset 0x3c8, CSR Addr 0x581e4, Direction=In
    // DB CW 0x48 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW49_ChA_D1;     // Byte offset 0x3c9, CSR Addr 0x581e4, Direction=In
    // DB CW 0x49 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW4A_ChA_D1;     // Byte offset 0x3ca, CSR Addr 0x581e5, Direction=In
    // DB CW 0x4A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW4B_ChA_D1;     // Byte offset 0x3cb, CSR Addr 0x581e5, Direction=In
    // DB CW 0x4B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW4C_ChA_D1;     // Byte offset 0x3cc, CSR Addr 0x581e6, Direction=In
    // DB CW 0x4C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW4D_ChA_D1;     // Byte offset 0x3cd, CSR Addr 0x581e6, Direction=In
    // DB CW 0x4D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW4E_ChA_D1;     // Byte offset 0x3ce, CSR Addr 0x581e7, Direction=In
    // DB CW 0x4E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW4F_ChA_D1;     // Byte offset 0x3cf, CSR Addr 0x581e7, Direction=In
    // DB CW 0x4F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW50_ChA_D1;     // Byte offset 0x3d0, CSR Addr 0x581e8, Direction=In
    // DB CW 0x50 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW51_ChA_D1;     // Byte offset 0x3d1, CSR Addr 0x581e8, Direction=In
    // DB CW 0x51 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW52_ChA_D1;     // Byte offset 0x3d2, CSR Addr 0x581e9, Direction=In
    // DB CW 0x52 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW53_ChA_D1;     // Byte offset 0x3d3, CSR Addr 0x581e9, Direction=In
    // DB CW 0x53 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW54_ChA_D1;     // Byte offset 0x3d4, CSR Addr 0x581ea, Direction=In
    // DB CW 0x54 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW55_ChA_D1;     // Byte offset 0x3d5, CSR Addr 0x581ea, Direction=In
    // DB CW 0x55 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW56_ChA_D1;     // Byte offset 0x3d6, CSR Addr 0x581eb, Direction=In
    // DB CW 0x56 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW57_ChA_D1;     // Byte offset 0x3d7, CSR Addr 0x581eb, Direction=In
    // DB CW 0x57 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW58_ChA_D1;     // Byte offset 0x3d8, CSR Addr 0x581ec, Direction=In
    // DB CW 0x58 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW59_ChA_D1;     // Byte offset 0x3d9, CSR Addr 0x581ec, Direction=In
    // DB CW 0x59 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW5A_ChA_D1;     // Byte offset 0x3da, CSR Addr 0x581ed, Direction=In
    // DB CW 0x5A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW5B_ChA_D1;     // Byte offset 0x3db, CSR Addr 0x581ed, Direction=In
    // DB CW 0x5B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW5C_ChA_D1;     // Byte offset 0x3dc, CSR Addr 0x581ee, Direction=In
    // DB CW 0x5C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW5D_ChA_D1;     // Byte offset 0x3dd, CSR Addr 0x581ee, Direction=In
    // DB CW 0x5D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW5E_ChA_D1;     // Byte offset 0x3de, CSR Addr 0x581ef, Direction=In
    // DB CW 0x5E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW5F_ChA_D1;     // Byte offset 0x3df, CSR Addr 0x581ef, Direction=In
    // DB CW 0x5F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW60_ChA_D1;     // Byte offset 0x3e0, CSR Addr 0x581f0, Direction=In
    // DB CW 0x60 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW61_ChA_D1;     // Byte offset 0x3e1, CSR Addr 0x581f0, Direction=In
    // DB CW 0x61 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW62_ChA_D1;     // Byte offset 0x3e2, CSR Addr 0x581f1, Direction=In
    // DB CW 0x62 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW63_ChA_D1;     // Byte offset 0x3e3, CSR Addr 0x581f1, Direction=In
    // DB CW 0x63 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW64_ChA_D1;     // Byte offset 0x3e4, CSR Addr 0x581f2, Direction=In
    // DB CW 0x64 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW65_ChA_D1;     // Byte offset 0x3e5, CSR Addr 0x581f2, Direction=In
    // DB CW 0x65 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW66_ChA_D1;     // Byte offset 0x3e6, CSR Addr 0x581f3, Direction=In
    // DB CW 0x66 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW67_ChA_D1;     // Byte offset 0x3e7, CSR Addr 0x581f3, Direction=In
    // DB CW 0x67 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW68_ChA_D1;     // Byte offset 0x3e8, CSR Addr 0x581f4, Direction=In
    // DB CW 0x68 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW69_ChA_D1;     // Byte offset 0x3e9, CSR Addr 0x581f4, Direction=In
    // DB CW 0x69 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW6A_ChA_D1;     // Byte offset 0x3ea, CSR Addr 0x581f5, Direction=In
    // DB CW 0x6A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW6B_ChA_D1;     // Byte offset 0x3eb, CSR Addr 0x581f5, Direction=In
    // DB CW 0x6B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW6C_ChA_D1;     // Byte offset 0x3ec, CSR Addr 0x581f6, Direction=In
    // DB CW 0x6C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW6D_ChA_D1;     // Byte offset 0x3ed, CSR Addr 0x581f6, Direction=In
    // DB CW 0x6D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW6E_ChA_D1;     // Byte offset 0x3ee, CSR Addr 0x581f7, Direction=In
    // DB CW 0x6E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW6F_ChA_D1;     // Byte offset 0x3ef, CSR Addr 0x581f7, Direction=In
    // DB CW 0x6F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW70_ChA_D1;     // Byte offset 0x3f0, CSR Addr 0x581f8, Direction=In
    // DB CW 0x70 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW71_ChA_D1;     // Byte offset 0x3f1, CSR Addr 0x581f8, Direction=In
    // DB CW 0x71 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW72_ChA_D1;     // Byte offset 0x3f2, CSR Addr 0x581f9, Direction=In
    // DB CW 0x72 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW73_ChA_D1;     // Byte offset 0x3f3, CSR Addr 0x581f9, Direction=In
    // DB CW 0x73 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW74_ChA_D1;     // Byte offset 0x3f4, CSR Addr 0x581fa, Direction=In
    // DB CW 0x74 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW75_ChA_D1;     // Byte offset 0x3f5, CSR Addr 0x581fa, Direction=In
    // DB CW 0x75 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW76_ChA_D1;     // Byte offset 0x3f6, CSR Addr 0x581fb, Direction=In
    // DB CW 0x76 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW77_ChA_D1;     // Byte offset 0x3f7, CSR Addr 0x581fb, Direction=In
    // DB CW 0x77 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW78_ChA_D1;     // Byte offset 0x3f8, CSR Addr 0x581fc, Direction=In
    // DB CW 0x78 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW79_ChA_D1;     // Byte offset 0x3f9, CSR Addr 0x581fc, Direction=In
    // DB CW 0x79 setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW7A_ChA_D1;     // Byte offset 0x3fa, CSR Addr 0x581fd, Direction=In
    // DB CW 0x7A setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW7B_ChA_D1;     // Byte offset 0x3fb, CSR Addr 0x581fd, Direction=In
    // DB CW 0x7B setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW7C_ChA_D1;     // Byte offset 0x3fc, CSR Addr 0x581fe, Direction=In
    // DB CW 0x7C setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW7D_ChA_D1;     // Byte offset 0x3fd, CSR Addr 0x581fe, Direction=In
    // DB CW 0x7D setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW7E_ChA_D1;     // Byte offset 0x3fe, CSR Addr 0x581ff, Direction=In
    // DB CW 0x7E setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  BCW7F_ChA_D1;     // Byte offset 0x3ff, CSR Addr 0x581ff, Direction=In
    // DB CW 0x7F setting, Channel A, DIMM1. Unused for UDIMM.
    uint8_t  RCW00_ChB_D0;     // Byte offset 0x400, CSR Addr 0x58200, Direction=In
    // RCD CW 0x00 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW01_ChB_D0;     // Byte offset 0x401, CSR Addr 0x58200, Direction=In
    // RCD CW 0x01 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW02_ChB_D0;     // Byte offset 0x402, CSR Addr 0x58201, Direction=In
    // RCD CW 0x02 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW03_ChB_D0;     // Byte offset 0x403, CSR Addr 0x58201, Direction=In
    // RCD CW 0x03 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW04_ChB_D0;     // Byte offset 0x404, CSR Addr 0x58202, Direction=In
    // RCD CW 0x04 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW05_ChB_D0;     // Byte offset 0x405, CSR Addr 0x58202, Direction=In
    // RCD CW 0x05 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW06_ChB_D0;     // Byte offset 0x406, CSR Addr 0x58203, Direction=In
    // RCD CW 0x06 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW07_ChB_D0;     // Byte offset 0x407, CSR Addr 0x58203, Direction=In
    // RCD CW 0x07 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW08_ChB_D0;     // Byte offset 0x408, CSR Addr 0x58204, Direction=In
    // RCD CW 0x08 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW09_ChB_D0;     // Byte offset 0x409, CSR Addr 0x58204, Direction=In
    // RCD CW 0x09 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW0A_ChB_D0;     // Byte offset 0x40a, CSR Addr 0x58205, Direction=In
    // RCD CW 0x0A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW0B_ChB_D0;     // Byte offset 0x40b, CSR Addr 0x58205, Direction=In
    // RCD CW 0x0B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW0C_ChB_D0;     // Byte offset 0x40c, CSR Addr 0x58206, Direction=In
    // RCD CW 0x0C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW0D_ChB_D0;     // Byte offset 0x40d, CSR Addr 0x58206, Direction=In
    // RCD CW 0x0D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW0E_ChB_D0;     // Byte offset 0x40e, CSR Addr 0x58207, Direction=In
    // RCD CW 0x0E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW0F_ChB_D0;     // Byte offset 0x40f, CSR Addr 0x58207, Direction=In
    // RCD CW 0x0F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW10_ChB_D0;     // Byte offset 0x410, CSR Addr 0x58208, Direction=In
    // RCD CW 0x10 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW11_ChB_D0;     // Byte offset 0x411, CSR Addr 0x58208, Direction=In
    // RCD CW 0x11 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW12_ChB_D0;     // Byte offset 0x412, CSR Addr 0x58209, Direction=In
    // RCD CW 0x12 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW13_ChB_D0;     // Byte offset 0x413, CSR Addr 0x58209, Direction=In
    // RCD CW 0x13 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW14_ChB_D0;     // Byte offset 0x414, CSR Addr 0x5820a, Direction=In
    // RCD CW 0x14 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW15_ChB_D0;     // Byte offset 0x415, CSR Addr 0x5820a, Direction=In
    // RCD CW 0x15 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW16_ChB_D0;     // Byte offset 0x416, CSR Addr 0x5820b, Direction=In
    // RCD CW 0x16 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW17_ChB_D0;     // Byte offset 0x417, CSR Addr 0x5820b, Direction=In
    // RCD CW 0x17 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW18_ChB_D0;     // Byte offset 0x418, CSR Addr 0x5820c, Direction=In
    // RCD CW 0x18 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW19_ChB_D0;     // Byte offset 0x419, CSR Addr 0x5820c, Direction=In
    // RCD CW 0x19 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW1A_ChB_D0;     // Byte offset 0x41a, CSR Addr 0x5820d, Direction=In
    // RCD CW 0x1A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW1B_ChB_D0;     // Byte offset 0x41b, CSR Addr 0x5820d, Direction=In
    // RCD CW 0x1B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW1C_ChB_D0;     // Byte offset 0x41c, CSR Addr 0x5820e, Direction=In
    // RCD CW 0x1C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW1D_ChB_D0;     // Byte offset 0x41d, CSR Addr 0x5820e, Direction=In
    // RCD CW 0x1D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW1E_ChB_D0;     // Byte offset 0x41e, CSR Addr 0x5820f, Direction=In
    // RCD CW 0x1E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW1F_ChB_D0;     // Byte offset 0x41f, CSR Addr 0x5820f, Direction=In
    // RCD CW 0x1F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW20_ChB_D0;     // Byte offset 0x420, CSR Addr 0x58210, Direction=In
    // RCD CW 0x20 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW21_ChB_D0;     // Byte offset 0x421, CSR Addr 0x58210, Direction=In
    // RCD CW 0x21 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW22_ChB_D0;     // Byte offset 0x422, CSR Addr 0x58211, Direction=In
    // RCD CW 0x22 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW23_ChB_D0;     // Byte offset 0x423, CSR Addr 0x58211, Direction=In
    // RCD CW 0x23 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW24_ChB_D0;     // Byte offset 0x424, CSR Addr 0x58212, Direction=In
    // RCD CW 0x24 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW25_ChB_D0;     // Byte offset 0x425, CSR Addr 0x58212, Direction=In
    // RCD CW 0x25 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW26_ChB_D0;     // Byte offset 0x426, CSR Addr 0x58213, Direction=In
    // RCD CW 0x26 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW27_ChB_D0;     // Byte offset 0x427, CSR Addr 0x58213, Direction=In
    // RCD CW 0x27 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW28_ChB_D0;     // Byte offset 0x428, CSR Addr 0x58214, Direction=In
    // RCD CW 0x28 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW29_ChB_D0;     // Byte offset 0x429, CSR Addr 0x58214, Direction=In
    // RCD CW 0x29 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW2A_ChB_D0;     // Byte offset 0x42a, CSR Addr 0x58215, Direction=In
    // RCD CW 0x2A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW2B_ChB_D0;     // Byte offset 0x42b, CSR Addr 0x58215, Direction=In
    // RCD CW 0x2B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW2C_ChB_D0;     // Byte offset 0x42c, CSR Addr 0x58216, Direction=In
    // RCD CW 0x2C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW2D_ChB_D0;     // Byte offset 0x42d, CSR Addr 0x58216, Direction=In
    // RCD CW 0x2D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW2E_ChB_D0;     // Byte offset 0x42e, CSR Addr 0x58217, Direction=In
    // RCD CW 0x2E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW2F_ChB_D0;     // Byte offset 0x42f, CSR Addr 0x58217, Direction=In
    // RCD CW 0x2F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW30_ChB_D0;     // Byte offset 0x430, CSR Addr 0x58218, Direction=In
    // RCD CW 0x30 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW31_ChB_D0;     // Byte offset 0x431, CSR Addr 0x58218, Direction=In
    // RCD CW 0x31 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW32_ChB_D0;     // Byte offset 0x432, CSR Addr 0x58219, Direction=In
    // RCD CW 0x32 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW33_ChB_D0;     // Byte offset 0x433, CSR Addr 0x58219, Direction=In
    // RCD CW 0x33 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW34_ChB_D0;     // Byte offset 0x434, CSR Addr 0x5821a, Direction=In
    // RCD CW 0x34 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW35_ChB_D0;     // Byte offset 0x435, CSR Addr 0x5821a, Direction=In
    // RCD CW 0x35 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW36_ChB_D0;     // Byte offset 0x436, CSR Addr 0x5821b, Direction=In
    // RCD CW 0x36 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW37_ChB_D0;     // Byte offset 0x437, CSR Addr 0x5821b, Direction=In
    // RCD CW 0x37 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW38_ChB_D0;     // Byte offset 0x438, CSR Addr 0x5821c, Direction=In
    // RCD CW 0x38 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW39_ChB_D0;     // Byte offset 0x439, CSR Addr 0x5821c, Direction=In
    // RCD CW 0x39 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW3A_ChB_D0;     // Byte offset 0x43a, CSR Addr 0x5821d, Direction=In
    // RCD CW 0x3A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW3B_ChB_D0;     // Byte offset 0x43b, CSR Addr 0x5821d, Direction=In
    // RCD CW 0x3B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW3C_ChB_D0;     // Byte offset 0x43c, CSR Addr 0x5821e, Direction=In
    // RCD CW 0x3C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW3D_ChB_D0;     // Byte offset 0x43d, CSR Addr 0x5821e, Direction=In
    // RCD CW 0x3D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW3E_ChB_D0;     // Byte offset 0x43e, CSR Addr 0x5821f, Direction=In
    // RCD CW 0x3E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW3F_ChB_D0;     // Byte offset 0x43f, CSR Addr 0x5821f, Direction=In
    // RCD CW 0x3F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW40_ChB_D0;     // Byte offset 0x440, CSR Addr 0x58220, Direction=In
    // RCD CW 0x40 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW41_ChB_D0;     // Byte offset 0x441, CSR Addr 0x58220, Direction=In
    // RCD CW 0x41 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW42_ChB_D0;     // Byte offset 0x442, CSR Addr 0x58221, Direction=In
    // RCD CW 0x42 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW43_ChB_D0;     // Byte offset 0x443, CSR Addr 0x58221, Direction=In
    // RCD CW 0x43 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW44_ChB_D0;     // Byte offset 0x444, CSR Addr 0x58222, Direction=In
    // RCD CW 0x44 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW45_ChB_D0;     // Byte offset 0x445, CSR Addr 0x58222, Direction=In
    // RCD CW 0x45 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW46_ChB_D0;     // Byte offset 0x446, CSR Addr 0x58223, Direction=In
    // RCD CW 0x46 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW47_ChB_D0;     // Byte offset 0x447, CSR Addr 0x58223, Direction=In
    // RCD CW 0x47 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW48_ChB_D0;     // Byte offset 0x448, CSR Addr 0x58224, Direction=In
    // RCD CW 0x48 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW49_ChB_D0;     // Byte offset 0x449, CSR Addr 0x58224, Direction=In
    // RCD CW 0x49 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW4A_ChB_D0;     // Byte offset 0x44a, CSR Addr 0x58225, Direction=In
    // RCD CW 0x4A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW4B_ChB_D0;     // Byte offset 0x44b, CSR Addr 0x58225, Direction=In
    // RCD CW 0x4B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW4C_ChB_D0;     // Byte offset 0x44c, CSR Addr 0x58226, Direction=In
    // RCD CW 0x4C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW4D_ChB_D0;     // Byte offset 0x44d, CSR Addr 0x58226, Direction=In
    // RCD CW 0x4D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW4E_ChB_D0;     // Byte offset 0x44e, CSR Addr 0x58227, Direction=In
    // RCD CW 0x4E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW4F_ChB_D0;     // Byte offset 0x44f, CSR Addr 0x58227, Direction=In
    // RCD CW 0x4F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW50_ChB_D0;     // Byte offset 0x450, CSR Addr 0x58228, Direction=In
    // RCD CW 0x50 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW51_ChB_D0;     // Byte offset 0x451, CSR Addr 0x58228, Direction=In
    // RCD CW 0x51 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW52_ChB_D0;     // Byte offset 0x452, CSR Addr 0x58229, Direction=In
    // RCD CW 0x52 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW53_ChB_D0;     // Byte offset 0x453, CSR Addr 0x58229, Direction=In
    // RCD CW 0x53 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW54_ChB_D0;     // Byte offset 0x454, CSR Addr 0x5822a, Direction=In
    // RCD CW 0x54 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW55_ChB_D0;     // Byte offset 0x455, CSR Addr 0x5822a, Direction=In
    // RCD CW 0x55 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW56_ChB_D0;     // Byte offset 0x456, CSR Addr 0x5822b, Direction=In
    // RCD CW 0x56 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW57_ChB_D0;     // Byte offset 0x457, CSR Addr 0x5822b, Direction=In
    // RCD CW 0x57 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW58_ChB_D0;     // Byte offset 0x458, CSR Addr 0x5822c, Direction=In
    // RCD CW 0x58 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW59_ChB_D0;     // Byte offset 0x459, CSR Addr 0x5822c, Direction=In
    // RCD CW 0x59 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW5A_ChB_D0;     // Byte offset 0x45a, CSR Addr 0x5822d, Direction=In
    // RCD CW 0x5A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW5B_ChB_D0;     // Byte offset 0x45b, CSR Addr 0x5822d, Direction=In
    // RCD CW 0x5B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW5C_ChB_D0;     // Byte offset 0x45c, CSR Addr 0x5822e, Direction=In
    // RCD CW 0x5C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW5D_ChB_D0;     // Byte offset 0x45d, CSR Addr 0x5822e, Direction=In
    // RCD CW 0x5D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW5E_ChB_D0;     // Byte offset 0x45e, CSR Addr 0x5822f, Direction=In
    // RCD CW 0x5E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW5F_ChB_D0;     // Byte offset 0x45f, CSR Addr 0x5822f, Direction=In
    // RCD CW 0x5F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW60_ChB_D0;     // Byte offset 0x460, CSR Addr 0x58230, Direction=In
    // RCD CW 0x60 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW61_ChB_D0;     // Byte offset 0x461, CSR Addr 0x58230, Direction=In
    // RCD CW 0x61 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW62_ChB_D0;     // Byte offset 0x462, CSR Addr 0x58231, Direction=In
    // RCD CW 0x62 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW63_ChB_D0;     // Byte offset 0x463, CSR Addr 0x58231, Direction=In
    // RCD CW 0x63 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW64_ChB_D0;     // Byte offset 0x464, CSR Addr 0x58232, Direction=In
    // RCD CW 0x64 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW65_ChB_D0;     // Byte offset 0x465, CSR Addr 0x58232, Direction=In
    // RCD CW 0x65 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW66_ChB_D0;     // Byte offset 0x466, CSR Addr 0x58233, Direction=In
    // RCD CW 0x66 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW67_ChB_D0;     // Byte offset 0x467, CSR Addr 0x58233, Direction=In
    // RCD CW 0x67 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW68_ChB_D0;     // Byte offset 0x468, CSR Addr 0x58234, Direction=In
    // RCD CW 0x68 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW69_ChB_D0;     // Byte offset 0x469, CSR Addr 0x58234, Direction=In
    // RCD CW 0x69 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW6A_ChB_D0;     // Byte offset 0x46a, CSR Addr 0x58235, Direction=In
    // RCD CW 0x6A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW6B_ChB_D0;     // Byte offset 0x46b, CSR Addr 0x58235, Direction=In
    // RCD CW 0x6B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW6C_ChB_D0;     // Byte offset 0x46c, CSR Addr 0x58236, Direction=In
    // RCD CW 0x6C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW6D_ChB_D0;     // Byte offset 0x46d, CSR Addr 0x58236, Direction=In
    // RCD CW 0x6D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW6E_ChB_D0;     // Byte offset 0x46e, CSR Addr 0x58237, Direction=In
    // RCD CW 0x6E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW6F_ChB_D0;     // Byte offset 0x46f, CSR Addr 0x58237, Direction=In
    // RCD CW 0x6F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW70_ChB_D0;     // Byte offset 0x470, CSR Addr 0x58238, Direction=In
    // RCD CW 0x70 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW71_ChB_D0;     // Byte offset 0x471, CSR Addr 0x58238, Direction=In
    // RCD CW 0x71 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW72_ChB_D0;     // Byte offset 0x472, CSR Addr 0x58239, Direction=In
    // RCD CW 0x72 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW73_ChB_D0;     // Byte offset 0x473, CSR Addr 0x58239, Direction=In
    // RCD CW 0x73 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW74_ChB_D0;     // Byte offset 0x474, CSR Addr 0x5823a, Direction=In
    // RCD CW 0x74 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW75_ChB_D0;     // Byte offset 0x475, CSR Addr 0x5823a, Direction=In
    // RCD CW 0x75 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW76_ChB_D0;     // Byte offset 0x476, CSR Addr 0x5823b, Direction=In
    // RCD CW 0x76 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW77_ChB_D0;     // Byte offset 0x477, CSR Addr 0x5823b, Direction=In
    // RCD CW 0x77 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW78_ChB_D0;     // Byte offset 0x478, CSR Addr 0x5823c, Direction=In
    // RCD CW 0x78 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW79_ChB_D0;     // Byte offset 0x479, CSR Addr 0x5823c, Direction=In
    // RCD CW 0x79 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW7A_ChB_D0;     // Byte offset 0x47a, CSR Addr 0x5823d, Direction=In
    // RCD CW 0x7A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW7B_ChB_D0;     // Byte offset 0x47b, CSR Addr 0x5823d, Direction=In
    // RCD CW 0x7B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW7C_ChB_D0;     // Byte offset 0x47c, CSR Addr 0x5823e, Direction=In
    // RCD CW 0x7C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW7D_ChB_D0;     // Byte offset 0x47d, CSR Addr 0x5823e, Direction=In
    // RCD CW 0x7D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW7E_ChB_D0;     // Byte offset 0x47e, CSR Addr 0x5823f, Direction=In
    // RCD CW 0x7E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW7F_ChB_D0;     // Byte offset 0x47f, CSR Addr 0x5823f, Direction=In
    // RCD CW 0x7F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW00_ChB_D0;     // Byte offset 0x480, CSR Addr 0x58240, Direction=In
    // DB CW 0x00 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW01_ChB_D0;     // Byte offset 0x481, CSR Addr 0x58240, Direction=In
    // DB CW 0x01 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW02_ChB_D0;     // Byte offset 0x482, CSR Addr 0x58241, Direction=In
    // DB CW 0x02 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW03_ChB_D0;     // Byte offset 0x483, CSR Addr 0x58241, Direction=In
    // DB CW 0x03 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW04_ChB_D0;     // Byte offset 0x484, CSR Addr 0x58242, Direction=In
    // DB CW 0x04 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW05_ChB_D0;     // Byte offset 0x485, CSR Addr 0x58242, Direction=In
    // DB CW 0x05 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW06_ChB_D0;     // Byte offset 0x486, CSR Addr 0x58243, Direction=In
    // DB CW 0x06 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW07_ChB_D0;     // Byte offset 0x487, CSR Addr 0x58243, Direction=In
    // DB CW 0x07 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW08_ChB_D0;     // Byte offset 0x488, CSR Addr 0x58244, Direction=In
    // DB CW 0x08 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW09_ChB_D0;     // Byte offset 0x489, CSR Addr 0x58244, Direction=In
    // DB CW 0x09 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW0A_ChB_D0;     // Byte offset 0x48a, CSR Addr 0x58245, Direction=In
    // DB CW 0x0A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW0B_ChB_D0;     // Byte offset 0x48b, CSR Addr 0x58245, Direction=In
    // DB CW 0x0B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW0C_ChB_D0;     // Byte offset 0x48c, CSR Addr 0x58246, Direction=In
    // DB CW 0x0C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW0D_ChB_D0;     // Byte offset 0x48d, CSR Addr 0x58246, Direction=In
    // DB CW 0x0D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW0E_ChB_D0;     // Byte offset 0x48e, CSR Addr 0x58247, Direction=In
    // DB CW 0x0E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW0F_ChB_D0;     // Byte offset 0x48f, CSR Addr 0x58247, Direction=In
    // DB CW 0x0F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW10_ChB_D0;     // Byte offset 0x490, CSR Addr 0x58248, Direction=In
    // DB CW 0x10 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW11_ChB_D0;     // Byte offset 0x491, CSR Addr 0x58248, Direction=In
    // DB CW 0x11 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW12_ChB_D0;     // Byte offset 0x492, CSR Addr 0x58249, Direction=In
    // DB CW 0x12 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW13_ChB_D0;     // Byte offset 0x493, CSR Addr 0x58249, Direction=In
    // DB CW 0x13 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW14_ChB_D0;     // Byte offset 0x494, CSR Addr 0x5824a, Direction=In
    // DB CW 0x14 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW15_ChB_D0;     // Byte offset 0x495, CSR Addr 0x5824a, Direction=In
    // DB CW 0x15 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW16_ChB_D0;     // Byte offset 0x496, CSR Addr 0x5824b, Direction=In
    // DB CW 0x16 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW17_ChB_D0;     // Byte offset 0x497, CSR Addr 0x5824b, Direction=In
    // DB CW 0x17 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW18_ChB_D0;     // Byte offset 0x498, CSR Addr 0x5824c, Direction=In
    // DB CW 0x18 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW19_ChB_D0;     // Byte offset 0x499, CSR Addr 0x5824c, Direction=In
    // DB CW 0x19 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW1A_ChB_D0;     // Byte offset 0x49a, CSR Addr 0x5824d, Direction=In
    // DB CW 0x1A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW1B_ChB_D0;     // Byte offset 0x49b, CSR Addr 0x5824d, Direction=In
    // DB CW 0x1B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW1C_ChB_D0;     // Byte offset 0x49c, CSR Addr 0x5824e, Direction=In
    // DB CW 0x1C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW1D_ChB_D0;     // Byte offset 0x49d, CSR Addr 0x5824e, Direction=In
    // DB CW 0x1D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW1E_ChB_D0;     // Byte offset 0x49e, CSR Addr 0x5824f, Direction=In
    // DB CW 0x1E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW1F_ChB_D0;     // Byte offset 0x49f, CSR Addr 0x5824f, Direction=In
    // DB CW 0x1F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW20_ChB_D0;     // Byte offset 0x4a0, CSR Addr 0x58250, Direction=In
    // DB CW 0x20 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW21_ChB_D0;     // Byte offset 0x4a1, CSR Addr 0x58250, Direction=In
    // DB CW 0x21 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW22_ChB_D0;     // Byte offset 0x4a2, CSR Addr 0x58251, Direction=In
    // DB CW 0x22 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW23_ChB_D0;     // Byte offset 0x4a3, CSR Addr 0x58251, Direction=In
    // DB CW 0x23 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW24_ChB_D0;     // Byte offset 0x4a4, CSR Addr 0x58252, Direction=In
    // DB CW 0x24 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW25_ChB_D0;     // Byte offset 0x4a5, CSR Addr 0x58252, Direction=In
    // DB CW 0x25 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW26_ChB_D0;     // Byte offset 0x4a6, CSR Addr 0x58253, Direction=In
    // DB CW 0x26 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW27_ChB_D0;     // Byte offset 0x4a7, CSR Addr 0x58253, Direction=In
    // DB CW 0x27 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW28_ChB_D0;     // Byte offset 0x4a8, CSR Addr 0x58254, Direction=In
    // DB CW 0x28 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW29_ChB_D0;     // Byte offset 0x4a9, CSR Addr 0x58254, Direction=In
    // DB CW 0x29 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW2A_ChB_D0;     // Byte offset 0x4aa, CSR Addr 0x58255, Direction=In
    // DB CW 0x2A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW2B_ChB_D0;     // Byte offset 0x4ab, CSR Addr 0x58255, Direction=In
    // DB CW 0x2B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW2C_ChB_D0;     // Byte offset 0x4ac, CSR Addr 0x58256, Direction=In
    // DB CW 0x2C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW2D_ChB_D0;     // Byte offset 0x4ad, CSR Addr 0x58256, Direction=In
    // DB CW 0x2D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW2E_ChB_D0;     // Byte offset 0x4ae, CSR Addr 0x58257, Direction=In
    // DB CW 0x2E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW2F_ChB_D0;     // Byte offset 0x4af, CSR Addr 0x58257, Direction=In
    // DB CW 0x2F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW30_ChB_D0;     // Byte offset 0x4b0, CSR Addr 0x58258, Direction=In
    // DB CW 0x30 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW31_ChB_D0;     // Byte offset 0x4b1, CSR Addr 0x58258, Direction=In
    // DB CW 0x31 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW32_ChB_D0;     // Byte offset 0x4b2, CSR Addr 0x58259, Direction=In
    // DB CW 0x32 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW33_ChB_D0;     // Byte offset 0x4b3, CSR Addr 0x58259, Direction=In
    // DB CW 0x33 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW34_ChB_D0;     // Byte offset 0x4b4, CSR Addr 0x5825a, Direction=In
    // DB CW 0x34 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW35_ChB_D0;     // Byte offset 0x4b5, CSR Addr 0x5825a, Direction=In
    // DB CW 0x35 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW36_ChB_D0;     // Byte offset 0x4b6, CSR Addr 0x5825b, Direction=In
    // DB CW 0x36 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW37_ChB_D0;     // Byte offset 0x4b7, CSR Addr 0x5825b, Direction=In
    // DB CW 0x37 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW38_ChB_D0;     // Byte offset 0x4b8, CSR Addr 0x5825c, Direction=In
    // DB CW 0x38 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW39_ChB_D0;     // Byte offset 0x4b9, CSR Addr 0x5825c, Direction=In
    // DB CW 0x39 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW3A_ChB_D0;     // Byte offset 0x4ba, CSR Addr 0x5825d, Direction=In
    // DB CW 0x3A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW3B_ChB_D0;     // Byte offset 0x4bb, CSR Addr 0x5825d, Direction=In
    // DB CW 0x3B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW3C_ChB_D0;     // Byte offset 0x4bc, CSR Addr 0x5825e, Direction=In
    // DB CW 0x3C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW3D_ChB_D0;     // Byte offset 0x4bd, CSR Addr 0x5825e, Direction=In
    // DB CW 0x3D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW3E_ChB_D0;     // Byte offset 0x4be, CSR Addr 0x5825f, Direction=In
    // DB CW 0x3E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW3F_ChB_D0;     // Byte offset 0x4bf, CSR Addr 0x5825f, Direction=In
    // DB CW 0x3F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW40_ChB_D0;     // Byte offset 0x4c0, CSR Addr 0x58260, Direction=In
    // DB CW 0x40 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW41_ChB_D0;     // Byte offset 0x4c1, CSR Addr 0x58260, Direction=In
    // DB CW 0x41 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW42_ChB_D0;     // Byte offset 0x4c2, CSR Addr 0x58261, Direction=In
    // DB CW 0x42 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW43_ChB_D0;     // Byte offset 0x4c3, CSR Addr 0x58261, Direction=In
    // DB CW 0x43 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW44_ChB_D0;     // Byte offset 0x4c4, CSR Addr 0x58262, Direction=In
    // DB CW 0x44 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW45_ChB_D0;     // Byte offset 0x4c5, CSR Addr 0x58262, Direction=In
    // DB CW 0x45 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW46_ChB_D0;     // Byte offset 0x4c6, CSR Addr 0x58263, Direction=In
    // DB CW 0x46 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW47_ChB_D0;     // Byte offset 0x4c7, CSR Addr 0x58263, Direction=In
    // DB CW 0x47 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW48_ChB_D0;     // Byte offset 0x4c8, CSR Addr 0x58264, Direction=In
    // DB CW 0x48 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW49_ChB_D0;     // Byte offset 0x4c9, CSR Addr 0x58264, Direction=In
    // DB CW 0x49 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW4A_ChB_D0;     // Byte offset 0x4ca, CSR Addr 0x58265, Direction=In
    // DB CW 0x4A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW4B_ChB_D0;     // Byte offset 0x4cb, CSR Addr 0x58265, Direction=In
    // DB CW 0x4B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW4C_ChB_D0;     // Byte offset 0x4cc, CSR Addr 0x58266, Direction=In
    // DB CW 0x4C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW4D_ChB_D0;     // Byte offset 0x4cd, CSR Addr 0x58266, Direction=In
    // DB CW 0x4D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW4E_ChB_D0;     // Byte offset 0x4ce, CSR Addr 0x58267, Direction=In
    // DB CW 0x4E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW4F_ChB_D0;     // Byte offset 0x4cf, CSR Addr 0x58267, Direction=In
    // DB CW 0x4F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW50_ChB_D0;     // Byte offset 0x4d0, CSR Addr 0x58268, Direction=In
    // DB CW 0x50 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW51_ChB_D0;     // Byte offset 0x4d1, CSR Addr 0x58268, Direction=In
    // DB CW 0x51 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW52_ChB_D0;     // Byte offset 0x4d2, CSR Addr 0x58269, Direction=In
    // DB CW 0x52 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW53_ChB_D0;     // Byte offset 0x4d3, CSR Addr 0x58269, Direction=In
    // DB CW 0x53 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW54_ChB_D0;     // Byte offset 0x4d4, CSR Addr 0x5826a, Direction=In
    // DB CW 0x54 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW55_ChB_D0;     // Byte offset 0x4d5, CSR Addr 0x5826a, Direction=In
    // DB CW 0x55 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW56_ChB_D0;     // Byte offset 0x4d6, CSR Addr 0x5826b, Direction=In
    // DB CW 0x56 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW57_ChB_D0;     // Byte offset 0x4d7, CSR Addr 0x5826b, Direction=In
    // DB CW 0x57 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW58_ChB_D0;     // Byte offset 0x4d8, CSR Addr 0x5826c, Direction=In
    // DB CW 0x58 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW59_ChB_D0;     // Byte offset 0x4d9, CSR Addr 0x5826c, Direction=In
    // DB CW 0x59 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW5A_ChB_D0;     // Byte offset 0x4da, CSR Addr 0x5826d, Direction=In
    // DB CW 0x5A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW5B_ChB_D0;     // Byte offset 0x4db, CSR Addr 0x5826d, Direction=In
    // DB CW 0x5B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW5C_ChB_D0;     // Byte offset 0x4dc, CSR Addr 0x5826e, Direction=In
    // DB CW 0x5C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW5D_ChB_D0;     // Byte offset 0x4dd, CSR Addr 0x5826e, Direction=In
    // DB CW 0x5D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW5E_ChB_D0;     // Byte offset 0x4de, CSR Addr 0x5826f, Direction=In
    // DB CW 0x5E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW5F_ChB_D0;     // Byte offset 0x4df, CSR Addr 0x5826f, Direction=In
    // DB CW 0x5F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW60_ChB_D0;     // Byte offset 0x4e0, CSR Addr 0x58270, Direction=In
    // DB CW 0x60 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW61_ChB_D0;     // Byte offset 0x4e1, CSR Addr 0x58270, Direction=In
    // DB CW 0x61 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW62_ChB_D0;     // Byte offset 0x4e2, CSR Addr 0x58271, Direction=In
    // DB CW 0x62 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW63_ChB_D0;     // Byte offset 0x4e3, CSR Addr 0x58271, Direction=In
    // DB CW 0x63 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW64_ChB_D0;     // Byte offset 0x4e4, CSR Addr 0x58272, Direction=In
    // DB CW 0x64 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW65_ChB_D0;     // Byte offset 0x4e5, CSR Addr 0x58272, Direction=In
    // DB CW 0x65 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW66_ChB_D0;     // Byte offset 0x4e6, CSR Addr 0x58273, Direction=In
    // DB CW 0x66 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW67_ChB_D0;     // Byte offset 0x4e7, CSR Addr 0x58273, Direction=In
    // DB CW 0x67 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW68_ChB_D0;     // Byte offset 0x4e8, CSR Addr 0x58274, Direction=In
    // DB CW 0x68 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW69_ChB_D0;     // Byte offset 0x4e9, CSR Addr 0x58274, Direction=In
    // DB CW 0x69 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW6A_ChB_D0;     // Byte offset 0x4ea, CSR Addr 0x58275, Direction=In
    // DB CW 0x6A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW6B_ChB_D0;     // Byte offset 0x4eb, CSR Addr 0x58275, Direction=In
    // DB CW 0x6B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW6C_ChB_D0;     // Byte offset 0x4ec, CSR Addr 0x58276, Direction=In
    // DB CW 0x6C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW6D_ChB_D0;     // Byte offset 0x4ed, CSR Addr 0x58276, Direction=In
    // DB CW 0x6D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW6E_ChB_D0;     // Byte offset 0x4ee, CSR Addr 0x58277, Direction=In
    // DB CW 0x6E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW6F_ChB_D0;     // Byte offset 0x4ef, CSR Addr 0x58277, Direction=In
    // DB CW 0x6F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW70_ChB_D0;     // Byte offset 0x4f0, CSR Addr 0x58278, Direction=In
    // DB CW 0x70 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW71_ChB_D0;     // Byte offset 0x4f1, CSR Addr 0x58278, Direction=In
    // DB CW 0x71 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW72_ChB_D0;     // Byte offset 0x4f2, CSR Addr 0x58279, Direction=In
    // DB CW 0x72 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW73_ChB_D0;     // Byte offset 0x4f3, CSR Addr 0x58279, Direction=In
    // DB CW 0x73 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW74_ChB_D0;     // Byte offset 0x4f4, CSR Addr 0x5827a, Direction=In
    // DB CW 0x74 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW75_ChB_D0;     // Byte offset 0x4f5, CSR Addr 0x5827a, Direction=In
    // DB CW 0x75 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW76_ChB_D0;     // Byte offset 0x4f6, CSR Addr 0x5827b, Direction=In
    // DB CW 0x76 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW77_ChB_D0;     // Byte offset 0x4f7, CSR Addr 0x5827b, Direction=In
    // DB CW 0x77 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW78_ChB_D0;     // Byte offset 0x4f8, CSR Addr 0x5827c, Direction=In
    // DB CW 0x78 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW79_ChB_D0;     // Byte offset 0x4f9, CSR Addr 0x5827c, Direction=In
    // DB CW 0x79 setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW7A_ChB_D0;     // Byte offset 0x4fa, CSR Addr 0x5827d, Direction=In
    // DB CW 0x7A setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW7B_ChB_D0;     // Byte offset 0x4fb, CSR Addr 0x5827d, Direction=In
    // DB CW 0x7B setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW7C_ChB_D0;     // Byte offset 0x4fc, CSR Addr 0x5827e, Direction=In
    // DB CW 0x7C setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW7D_ChB_D0;     // Byte offset 0x4fd, CSR Addr 0x5827e, Direction=In
    // DB CW 0x7D setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW7E_ChB_D0;     // Byte offset 0x4fe, CSR Addr 0x5827f, Direction=In
    // DB CW 0x7E setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  BCW7F_ChB_D0;     // Byte offset 0x4ff, CSR Addr 0x5827f, Direction=In
    // DB CW 0x7F setting, Channel B, DIMM0. Unused for UDIMM.
    uint8_t  RCW00_ChB_D1;     // Byte offset 0x500, CSR Addr 0x58280, Direction=In
    // RCD CW 0x00 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW01_ChB_D1;     // Byte offset 0x501, CSR Addr 0x58280, Direction=In
    // RCD CW 0x01 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW02_ChB_D1;     // Byte offset 0x502, CSR Addr 0x58281, Direction=In
    // RCD CW 0x02 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW03_ChB_D1;     // Byte offset 0x503, CSR Addr 0x58281, Direction=In
    // RCD CW 0x03 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW04_ChB_D1;     // Byte offset 0x504, CSR Addr 0x58282, Direction=In
    // RCD CW 0x04 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW05_ChB_D1;     // Byte offset 0x505, CSR Addr 0x58282, Direction=In
    // RCD CW 0x05 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW06_ChB_D1;     // Byte offset 0x506, CSR Addr 0x58283, Direction=In
    // RCD CW 0x06 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW07_ChB_D1;     // Byte offset 0x507, CSR Addr 0x58283, Direction=In
    // RCD CW 0x07 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW08_ChB_D1;     // Byte offset 0x508, CSR Addr 0x58284, Direction=In
    // RCD CW 0x08 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW09_ChB_D1;     // Byte offset 0x509, CSR Addr 0x58284, Direction=In
    // RCD CW 0x09 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW0A_ChB_D1;     // Byte offset 0x50a, CSR Addr 0x58285, Direction=In
    // RCD CW 0x0A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW0B_ChB_D1;     // Byte offset 0x50b, CSR Addr 0x58285, Direction=In
    // RCD CW 0x0B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW0C_ChB_D1;     // Byte offset 0x50c, CSR Addr 0x58286, Direction=In
    // RCD CW 0x0C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW0D_ChB_D1;     // Byte offset 0x50d, CSR Addr 0x58286, Direction=In
    // RCD CW 0x0D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW0E_ChB_D1;     // Byte offset 0x50e, CSR Addr 0x58287, Direction=In
    // RCD CW 0x0E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW0F_ChB_D1;     // Byte offset 0x50f, CSR Addr 0x58287, Direction=In
    // RCD CW 0x0F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW10_ChB_D1;     // Byte offset 0x510, CSR Addr 0x58288, Direction=In
    // RCD CW 0x10 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW11_ChB_D1;     // Byte offset 0x511, CSR Addr 0x58288, Direction=In
    // RCD CW 0x11 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW12_ChB_D1;     // Byte offset 0x512, CSR Addr 0x58289, Direction=In
    // RCD CW 0x12 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW13_ChB_D1;     // Byte offset 0x513, CSR Addr 0x58289, Direction=In
    // RCD CW 0x13 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW14_ChB_D1;     // Byte offset 0x514, CSR Addr 0x5828a, Direction=In
    // RCD CW 0x14 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW15_ChB_D1;     // Byte offset 0x515, CSR Addr 0x5828a, Direction=In
    // RCD CW 0x15 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW16_ChB_D1;     // Byte offset 0x516, CSR Addr 0x5828b, Direction=In
    // RCD CW 0x16 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW17_ChB_D1;     // Byte offset 0x517, CSR Addr 0x5828b, Direction=In
    // RCD CW 0x17 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW18_ChB_D1;     // Byte offset 0x518, CSR Addr 0x5828c, Direction=In
    // RCD CW 0x18 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW19_ChB_D1;     // Byte offset 0x519, CSR Addr 0x5828c, Direction=In
    // RCD CW 0x19 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW1A_ChB_D1;     // Byte offset 0x51a, CSR Addr 0x5828d, Direction=In
    // RCD CW 0x1A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW1B_ChB_D1;     // Byte offset 0x51b, CSR Addr 0x5828d, Direction=In
    // RCD CW 0x1B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW1C_ChB_D1;     // Byte offset 0x51c, CSR Addr 0x5828e, Direction=In
    // RCD CW 0x1C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW1D_ChB_D1;     // Byte offset 0x51d, CSR Addr 0x5828e, Direction=In
    // RCD CW 0x1D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW1E_ChB_D1;     // Byte offset 0x51e, CSR Addr 0x5828f, Direction=In
    // RCD CW 0x1E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW1F_ChB_D1;     // Byte offset 0x51f, CSR Addr 0x5828f, Direction=In
    // RCD CW 0x1F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW20_ChB_D1;     // Byte offset 0x520, CSR Addr 0x58290, Direction=In
    // RCD CW 0x20 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW21_ChB_D1;     // Byte offset 0x521, CSR Addr 0x58290, Direction=In
    // RCD CW 0x21 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW22_ChB_D1;     // Byte offset 0x522, CSR Addr 0x58291, Direction=In
    // RCD CW 0x22 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW23_ChB_D1;     // Byte offset 0x523, CSR Addr 0x58291, Direction=In
    // RCD CW 0x23 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW24_ChB_D1;     // Byte offset 0x524, CSR Addr 0x58292, Direction=In
    // RCD CW 0x24 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW25_ChB_D1;     // Byte offset 0x525, CSR Addr 0x58292, Direction=In
    // RCD CW 0x25 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW26_ChB_D1;     // Byte offset 0x526, CSR Addr 0x58293, Direction=In
    // RCD CW 0x26 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW27_ChB_D1;     // Byte offset 0x527, CSR Addr 0x58293, Direction=In
    // RCD CW 0x27 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW28_ChB_D1;     // Byte offset 0x528, CSR Addr 0x58294, Direction=In
    // RCD CW 0x28 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW29_ChB_D1;     // Byte offset 0x529, CSR Addr 0x58294, Direction=In
    // RCD CW 0x29 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW2A_ChB_D1;     // Byte offset 0x52a, CSR Addr 0x58295, Direction=In
    // RCD CW 0x2A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW2B_ChB_D1;     // Byte offset 0x52b, CSR Addr 0x58295, Direction=In
    // RCD CW 0x2B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW2C_ChB_D1;     // Byte offset 0x52c, CSR Addr 0x58296, Direction=In
    // RCD CW 0x2C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW2D_ChB_D1;     // Byte offset 0x52d, CSR Addr 0x58296, Direction=In
    // RCD CW 0x2D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW2E_ChB_D1;     // Byte offset 0x52e, CSR Addr 0x58297, Direction=In
    // RCD CW 0x2E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW2F_ChB_D1;     // Byte offset 0x52f, CSR Addr 0x58297, Direction=In
    // RCD CW 0x2F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW30_ChB_D1;     // Byte offset 0x530, CSR Addr 0x58298, Direction=In
    // RCD CW 0x30 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW31_ChB_D1;     // Byte offset 0x531, CSR Addr 0x58298, Direction=In
    // RCD CW 0x31 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW32_ChB_D1;     // Byte offset 0x532, CSR Addr 0x58299, Direction=In
    // RCD CW 0x32 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW33_ChB_D1;     // Byte offset 0x533, CSR Addr 0x58299, Direction=In
    // RCD CW 0x33 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW34_ChB_D1;     // Byte offset 0x534, CSR Addr 0x5829a, Direction=In
    // RCD CW 0x34 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW35_ChB_D1;     // Byte offset 0x535, CSR Addr 0x5829a, Direction=In
    // RCD CW 0x35 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW36_ChB_D1;     // Byte offset 0x536, CSR Addr 0x5829b, Direction=In
    // RCD CW 0x36 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW37_ChB_D1;     // Byte offset 0x537, CSR Addr 0x5829b, Direction=In
    // RCD CW 0x37 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW38_ChB_D1;     // Byte offset 0x538, CSR Addr 0x5829c, Direction=In
    // RCD CW 0x38 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW39_ChB_D1;     // Byte offset 0x539, CSR Addr 0x5829c, Direction=In
    // RCD CW 0x39 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW3A_ChB_D1;     // Byte offset 0x53a, CSR Addr 0x5829d, Direction=In
    // RCD CW 0x3A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW3B_ChB_D1;     // Byte offset 0x53b, CSR Addr 0x5829d, Direction=In
    // RCD CW 0x3B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW3C_ChB_D1;     // Byte offset 0x53c, CSR Addr 0x5829e, Direction=In
    // RCD CW 0x3C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW3D_ChB_D1;     // Byte offset 0x53d, CSR Addr 0x5829e, Direction=In
    // RCD CW 0x3D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW3E_ChB_D1;     // Byte offset 0x53e, CSR Addr 0x5829f, Direction=In
    // RCD CW 0x3E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW3F_ChB_D1;     // Byte offset 0x53f, CSR Addr 0x5829f, Direction=In
    // RCD CW 0x3F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW40_ChB_D1;     // Byte offset 0x540, CSR Addr 0x582a0, Direction=In
    // RCD CW 0x40 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW41_ChB_D1;     // Byte offset 0x541, CSR Addr 0x582a0, Direction=In
    // RCD CW 0x41 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW42_ChB_D1;     // Byte offset 0x542, CSR Addr 0x582a1, Direction=In
    // RCD CW 0x42 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW43_ChB_D1;     // Byte offset 0x543, CSR Addr 0x582a1, Direction=In
    // RCD CW 0x43 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW44_ChB_D1;     // Byte offset 0x544, CSR Addr 0x582a2, Direction=In
    // RCD CW 0x44 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW45_ChB_D1;     // Byte offset 0x545, CSR Addr 0x582a2, Direction=In
    // RCD CW 0x45 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW46_ChB_D1;     // Byte offset 0x546, CSR Addr 0x582a3, Direction=In
    // RCD CW 0x46 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW47_ChB_D1;     // Byte offset 0x547, CSR Addr 0x582a3, Direction=In
    // RCD CW 0x47 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW48_ChB_D1;     // Byte offset 0x548, CSR Addr 0x582a4, Direction=In
    // RCD CW 0x48 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW49_ChB_D1;     // Byte offset 0x549, CSR Addr 0x582a4, Direction=In
    // RCD CW 0x49 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW4A_ChB_D1;     // Byte offset 0x54a, CSR Addr 0x582a5, Direction=In
    // RCD CW 0x4A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW4B_ChB_D1;     // Byte offset 0x54b, CSR Addr 0x582a5, Direction=In
    // RCD CW 0x4B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW4C_ChB_D1;     // Byte offset 0x54c, CSR Addr 0x582a6, Direction=In
    // RCD CW 0x4C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW4D_ChB_D1;     // Byte offset 0x54d, CSR Addr 0x582a6, Direction=In
    // RCD CW 0x4D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW4E_ChB_D1;     // Byte offset 0x54e, CSR Addr 0x582a7, Direction=In
    // RCD CW 0x4E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW4F_ChB_D1;     // Byte offset 0x54f, CSR Addr 0x582a7, Direction=In
    // RCD CW 0x4F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW50_ChB_D1;     // Byte offset 0x550, CSR Addr 0x582a8, Direction=In
    // RCD CW 0x50 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW51_ChB_D1;     // Byte offset 0x551, CSR Addr 0x582a8, Direction=In
    // RCD CW 0x51 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW52_ChB_D1;     // Byte offset 0x552, CSR Addr 0x582a9, Direction=In
    // RCD CW 0x52 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW53_ChB_D1;     // Byte offset 0x553, CSR Addr 0x582a9, Direction=In
    // RCD CW 0x53 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW54_ChB_D1;     // Byte offset 0x554, CSR Addr 0x582aa, Direction=In
    // RCD CW 0x54 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW55_ChB_D1;     // Byte offset 0x555, CSR Addr 0x582aa, Direction=In
    // RCD CW 0x55 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW56_ChB_D1;     // Byte offset 0x556, CSR Addr 0x582ab, Direction=In
    // RCD CW 0x56 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW57_ChB_D1;     // Byte offset 0x557, CSR Addr 0x582ab, Direction=In
    // RCD CW 0x57 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW58_ChB_D1;     // Byte offset 0x558, CSR Addr 0x582ac, Direction=In
    // RCD CW 0x58 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW59_ChB_D1;     // Byte offset 0x559, CSR Addr 0x582ac, Direction=In
    // RCD CW 0x59 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW5A_ChB_D1;     // Byte offset 0x55a, CSR Addr 0x582ad, Direction=In
    // RCD CW 0x5A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW5B_ChB_D1;     // Byte offset 0x55b, CSR Addr 0x582ad, Direction=In
    // RCD CW 0x5B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW5C_ChB_D1;     // Byte offset 0x55c, CSR Addr 0x582ae, Direction=In
    // RCD CW 0x5C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW5D_ChB_D1;     // Byte offset 0x55d, CSR Addr 0x582ae, Direction=In
    // RCD CW 0x5D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW5E_ChB_D1;     // Byte offset 0x55e, CSR Addr 0x582af, Direction=In
    // RCD CW 0x5E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW5F_ChB_D1;     // Byte offset 0x55f, CSR Addr 0x582af, Direction=In
    // RCD CW 0x5F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW60_ChB_D1;     // Byte offset 0x560, CSR Addr 0x582b0, Direction=In
    // RCD CW 0x60 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW61_ChB_D1;     // Byte offset 0x561, CSR Addr 0x582b0, Direction=In
    // RCD CW 0x61 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW62_ChB_D1;     // Byte offset 0x562, CSR Addr 0x582b1, Direction=In
    // RCD CW 0x62 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW63_ChB_D1;     // Byte offset 0x563, CSR Addr 0x582b1, Direction=In
    // RCD CW 0x63 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW64_ChB_D1;     // Byte offset 0x564, CSR Addr 0x582b2, Direction=In
    // RCD CW 0x64 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW65_ChB_D1;     // Byte offset 0x565, CSR Addr 0x582b2, Direction=In
    // RCD CW 0x65 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW66_ChB_D1;     // Byte offset 0x566, CSR Addr 0x582b3, Direction=In
    // RCD CW 0x66 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW67_ChB_D1;     // Byte offset 0x567, CSR Addr 0x582b3, Direction=In
    // RCD CW 0x67 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW68_ChB_D1;     // Byte offset 0x568, CSR Addr 0x582b4, Direction=In
    // RCD CW 0x68 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW69_ChB_D1;     // Byte offset 0x569, CSR Addr 0x582b4, Direction=In
    // RCD CW 0x69 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW6A_ChB_D1;     // Byte offset 0x56a, CSR Addr 0x582b5, Direction=In
    // RCD CW 0x6A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW6B_ChB_D1;     // Byte offset 0x56b, CSR Addr 0x582b5, Direction=In
    // RCD CW 0x6B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW6C_ChB_D1;     // Byte offset 0x56c, CSR Addr 0x582b6, Direction=In
    // RCD CW 0x6C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW6D_ChB_D1;     // Byte offset 0x56d, CSR Addr 0x582b6, Direction=In
    // RCD CW 0x6D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW6E_ChB_D1;     // Byte offset 0x56e, CSR Addr 0x582b7, Direction=In
    // RCD CW 0x6E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW6F_ChB_D1;     // Byte offset 0x56f, CSR Addr 0x582b7, Direction=In
    // RCD CW 0x6F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW70_ChB_D1;     // Byte offset 0x570, CSR Addr 0x582b8, Direction=In
    // RCD CW 0x70 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW71_ChB_D1;     // Byte offset 0x571, CSR Addr 0x582b8, Direction=In
    // RCD CW 0x71 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW72_ChB_D1;     // Byte offset 0x572, CSR Addr 0x582b9, Direction=In
    // RCD CW 0x72 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW73_ChB_D1;     // Byte offset 0x573, CSR Addr 0x582b9, Direction=In
    // RCD CW 0x73 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW74_ChB_D1;     // Byte offset 0x574, CSR Addr 0x582ba, Direction=In
    // RCD CW 0x74 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW75_ChB_D1;     // Byte offset 0x575, CSR Addr 0x582ba, Direction=In
    // RCD CW 0x75 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW76_ChB_D1;     // Byte offset 0x576, CSR Addr 0x582bb, Direction=In
    // RCD CW 0x76 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW77_ChB_D1;     // Byte offset 0x577, CSR Addr 0x582bb, Direction=In
    // RCD CW 0x77 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW78_ChB_D1;     // Byte offset 0x578, CSR Addr 0x582bc, Direction=In
    // RCD CW 0x78 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW79_ChB_D1;     // Byte offset 0x579, CSR Addr 0x582bc, Direction=In
    // RCD CW 0x79 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW7A_ChB_D1;     // Byte offset 0x57a, CSR Addr 0x582bd, Direction=In
    // RCD CW 0x7A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW7B_ChB_D1;     // Byte offset 0x57b, CSR Addr 0x582bd, Direction=In
    // RCD CW 0x7B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW7C_ChB_D1;     // Byte offset 0x57c, CSR Addr 0x582be, Direction=In
    // RCD CW 0x7C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW7D_ChB_D1;     // Byte offset 0x57d, CSR Addr 0x582be, Direction=In
    // RCD CW 0x7D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW7E_ChB_D1;     // Byte offset 0x57e, CSR Addr 0x582bf, Direction=In
    // RCD CW 0x7E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  RCW7F_ChB_D1;     // Byte offset 0x57f, CSR Addr 0x582bf, Direction=In
    // RCD CW 0x7F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW00_ChB_D1;     // Byte offset 0x580, CSR Addr 0x582c0, Direction=In
    // DB CW 0x00 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW01_ChB_D1;     // Byte offset 0x581, CSR Addr 0x582c0, Direction=In
    // DB CW 0x01 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW02_ChB_D1;     // Byte offset 0x582, CSR Addr 0x582c1, Direction=In
    // DB CW 0x02 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW03_ChB_D1;     // Byte offset 0x583, CSR Addr 0x582c1, Direction=In
    // DB CW 0x03 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW04_ChB_D1;     // Byte offset 0x584, CSR Addr 0x582c2, Direction=In
    // DB CW 0x04 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW05_ChB_D1;     // Byte offset 0x585, CSR Addr 0x582c2, Direction=In
    // DB CW 0x05 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW06_ChB_D1;     // Byte offset 0x586, CSR Addr 0x582c3, Direction=In
    // DB CW 0x06 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW07_ChB_D1;     // Byte offset 0x587, CSR Addr 0x582c3, Direction=In
    // DB CW 0x07 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW08_ChB_D1;     // Byte offset 0x588, CSR Addr 0x582c4, Direction=In
    // DB CW 0x08 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW09_ChB_D1;     // Byte offset 0x589, CSR Addr 0x582c4, Direction=In
    // DB CW 0x09 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW0A_ChB_D1;     // Byte offset 0x58a, CSR Addr 0x582c5, Direction=In
    // DB CW 0x0A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW0B_ChB_D1;     // Byte offset 0x58b, CSR Addr 0x582c5, Direction=In
    // DB CW 0x0B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW0C_ChB_D1;     // Byte offset 0x58c, CSR Addr 0x582c6, Direction=In
    // DB CW 0x0C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW0D_ChB_D1;     // Byte offset 0x58d, CSR Addr 0x582c6, Direction=In
    // DB CW 0x0D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW0E_ChB_D1;     // Byte offset 0x58e, CSR Addr 0x582c7, Direction=In
    // DB CW 0x0E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW0F_ChB_D1;     // Byte offset 0x58f, CSR Addr 0x582c7, Direction=In
    // DB CW 0x0F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW10_ChB_D1;     // Byte offset 0x590, CSR Addr 0x582c8, Direction=In
    // DB CW 0x10 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW11_ChB_D1;     // Byte offset 0x591, CSR Addr 0x582c8, Direction=In
    // DB CW 0x11 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW12_ChB_D1;     // Byte offset 0x592, CSR Addr 0x582c9, Direction=In
    // DB CW 0x12 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW13_ChB_D1;     // Byte offset 0x593, CSR Addr 0x582c9, Direction=In
    // DB CW 0x13 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW14_ChB_D1;     // Byte offset 0x594, CSR Addr 0x582ca, Direction=In
    // DB CW 0x14 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW15_ChB_D1;     // Byte offset 0x595, CSR Addr 0x582ca, Direction=In
    // DB CW 0x15 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW16_ChB_D1;     // Byte offset 0x596, CSR Addr 0x582cb, Direction=In
    // DB CW 0x16 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW17_ChB_D1;     // Byte offset 0x597, CSR Addr 0x582cb, Direction=In
    // DB CW 0x17 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW18_ChB_D1;     // Byte offset 0x598, CSR Addr 0x582cc, Direction=In
    // DB CW 0x18 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW19_ChB_D1;     // Byte offset 0x599, CSR Addr 0x582cc, Direction=In
    // DB CW 0x19 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW1A_ChB_D1;     // Byte offset 0x59a, CSR Addr 0x582cd, Direction=In
    // DB CW 0x1A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW1B_ChB_D1;     // Byte offset 0x59b, CSR Addr 0x582cd, Direction=In
    // DB CW 0x1B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW1C_ChB_D1;     // Byte offset 0x59c, CSR Addr 0x582ce, Direction=In
    // DB CW 0x1C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW1D_ChB_D1;     // Byte offset 0x59d, CSR Addr 0x582ce, Direction=In
    // DB CW 0x1D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW1E_ChB_D1;     // Byte offset 0x59e, CSR Addr 0x582cf, Direction=In
    // DB CW 0x1E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW1F_ChB_D1;     // Byte offset 0x59f, CSR Addr 0x582cf, Direction=In
    // DB CW 0x1F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW20_ChB_D1;     // Byte offset 0x5a0, CSR Addr 0x582d0, Direction=In
    // DB CW 0x20 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW21_ChB_D1;     // Byte offset 0x5a1, CSR Addr 0x582d0, Direction=In
    // DB CW 0x21 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW22_ChB_D1;     // Byte offset 0x5a2, CSR Addr 0x582d1, Direction=In
    // DB CW 0x22 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW23_ChB_D1;     // Byte offset 0x5a3, CSR Addr 0x582d1, Direction=In
    // DB CW 0x23 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW24_ChB_D1;     // Byte offset 0x5a4, CSR Addr 0x582d2, Direction=In
    // DB CW 0x24 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW25_ChB_D1;     // Byte offset 0x5a5, CSR Addr 0x582d2, Direction=In
    // DB CW 0x25 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW26_ChB_D1;     // Byte offset 0x5a6, CSR Addr 0x582d3, Direction=In
    // DB CW 0x26 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW27_ChB_D1;     // Byte offset 0x5a7, CSR Addr 0x582d3, Direction=In
    // DB CW 0x27 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW28_ChB_D1;     // Byte offset 0x5a8, CSR Addr 0x582d4, Direction=In
    // DB CW 0x28 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW29_ChB_D1;     // Byte offset 0x5a9, CSR Addr 0x582d4, Direction=In
    // DB CW 0x29 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW2A_ChB_D1;     // Byte offset 0x5aa, CSR Addr 0x582d5, Direction=In
    // DB CW 0x2A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW2B_ChB_D1;     // Byte offset 0x5ab, CSR Addr 0x582d5, Direction=In
    // DB CW 0x2B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW2C_ChB_D1;     // Byte offset 0x5ac, CSR Addr 0x582d6, Direction=In
    // DB CW 0x2C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW2D_ChB_D1;     // Byte offset 0x5ad, CSR Addr 0x582d6, Direction=In
    // DB CW 0x2D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW2E_ChB_D1;     // Byte offset 0x5ae, CSR Addr 0x582d7, Direction=In
    // DB CW 0x2E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW2F_ChB_D1;     // Byte offset 0x5af, CSR Addr 0x582d7, Direction=In
    // DB CW 0x2F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW30_ChB_D1;     // Byte offset 0x5b0, CSR Addr 0x582d8, Direction=In
    // DB CW 0x30 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW31_ChB_D1;     // Byte offset 0x5b1, CSR Addr 0x582d8, Direction=In
    // DB CW 0x31 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW32_ChB_D1;     // Byte offset 0x5b2, CSR Addr 0x582d9, Direction=In
    // DB CW 0x32 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW33_ChB_D1;     // Byte offset 0x5b3, CSR Addr 0x582d9, Direction=In
    // DB CW 0x33 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW34_ChB_D1;     // Byte offset 0x5b4, CSR Addr 0x582da, Direction=In
    // DB CW 0x34 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW35_ChB_D1;     // Byte offset 0x5b5, CSR Addr 0x582da, Direction=In
    // DB CW 0x35 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW36_ChB_D1;     // Byte offset 0x5b6, CSR Addr 0x582db, Direction=In
    // DB CW 0x36 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW37_ChB_D1;     // Byte offset 0x5b7, CSR Addr 0x582db, Direction=In
    // DB CW 0x37 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW38_ChB_D1;     // Byte offset 0x5b8, CSR Addr 0x582dc, Direction=In
    // DB CW 0x38 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW39_ChB_D1;     // Byte offset 0x5b9, CSR Addr 0x582dc, Direction=In
    // DB CW 0x39 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW3A_ChB_D1;     // Byte offset 0x5ba, CSR Addr 0x582dd, Direction=In
    // DB CW 0x3A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW3B_ChB_D1;     // Byte offset 0x5bb, CSR Addr 0x582dd, Direction=In
    // DB CW 0x3B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW3C_ChB_D1;     // Byte offset 0x5bc, CSR Addr 0x582de, Direction=In
    // DB CW 0x3C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW3D_ChB_D1;     // Byte offset 0x5bd, CSR Addr 0x582de, Direction=In
    // DB CW 0x3D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW3E_ChB_D1;     // Byte offset 0x5be, CSR Addr 0x582df, Direction=In
    // DB CW 0x3E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW3F_ChB_D1;     // Byte offset 0x5bf, CSR Addr 0x582df, Direction=In
    // DB CW 0x3F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW40_ChB_D1;     // Byte offset 0x5c0, CSR Addr 0x582e0, Direction=In
    // DB CW 0x40 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW41_ChB_D1;     // Byte offset 0x5c1, CSR Addr 0x582e0, Direction=In
    // DB CW 0x41 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW42_ChB_D1;     // Byte offset 0x5c2, CSR Addr 0x582e1, Direction=In
    // DB CW 0x42 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW43_ChB_D1;     // Byte offset 0x5c3, CSR Addr 0x582e1, Direction=In
    // DB CW 0x43 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW44_ChB_D1;     // Byte offset 0x5c4, CSR Addr 0x582e2, Direction=In
    // DB CW 0x44 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW45_ChB_D1;     // Byte offset 0x5c5, CSR Addr 0x582e2, Direction=In
    // DB CW 0x45 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW46_ChB_D1;     // Byte offset 0x5c6, CSR Addr 0x582e3, Direction=In
    // DB CW 0x46 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW47_ChB_D1;     // Byte offset 0x5c7, CSR Addr 0x582e3, Direction=In
    // DB CW 0x47 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW48_ChB_D1;     // Byte offset 0x5c8, CSR Addr 0x582e4, Direction=In
    // DB CW 0x48 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW49_ChB_D1;     // Byte offset 0x5c9, CSR Addr 0x582e4, Direction=In
    // DB CW 0x49 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW4A_ChB_D1;     // Byte offset 0x5ca, CSR Addr 0x582e5, Direction=In
    // DB CW 0x4A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW4B_ChB_D1;     // Byte offset 0x5cb, CSR Addr 0x582e5, Direction=In
    // DB CW 0x4B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW4C_ChB_D1;     // Byte offset 0x5cc, CSR Addr 0x582e6, Direction=In
    // DB CW 0x4C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW4D_ChB_D1;     // Byte offset 0x5cd, CSR Addr 0x582e6, Direction=In
    // DB CW 0x4D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW4E_ChB_D1;     // Byte offset 0x5ce, CSR Addr 0x582e7, Direction=In
    // DB CW 0x4E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW4F_ChB_D1;     // Byte offset 0x5cf, CSR Addr 0x582e7, Direction=In
    // DB CW 0x4F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW50_ChB_D1;     // Byte offset 0x5d0, CSR Addr 0x582e8, Direction=In
    // DB CW 0x50 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW51_ChB_D1;     // Byte offset 0x5d1, CSR Addr 0x582e8, Direction=In
    // DB CW 0x51 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW52_ChB_D1;     // Byte offset 0x5d2, CSR Addr 0x582e9, Direction=In
    // DB CW 0x52 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW53_ChB_D1;     // Byte offset 0x5d3, CSR Addr 0x582e9, Direction=In
    // DB CW 0x53 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW54_ChB_D1;     // Byte offset 0x5d4, CSR Addr 0x582ea, Direction=In
    // DB CW 0x54 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW55_ChB_D1;     // Byte offset 0x5d5, CSR Addr 0x582ea, Direction=In
    // DB CW 0x55 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW56_ChB_D1;     // Byte offset 0x5d6, CSR Addr 0x582eb, Direction=In
    // DB CW 0x56 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW57_ChB_D1;     // Byte offset 0x5d7, CSR Addr 0x582eb, Direction=In
    // DB CW 0x57 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW58_ChB_D1;     // Byte offset 0x5d8, CSR Addr 0x582ec, Direction=In
    // DB CW 0x58 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW59_ChB_D1;     // Byte offset 0x5d9, CSR Addr 0x582ec, Direction=In
    // DB CW 0x59 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW5A_ChB_D1;     // Byte offset 0x5da, CSR Addr 0x582ed, Direction=In
    // DB CW 0x5A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW5B_ChB_D1;     // Byte offset 0x5db, CSR Addr 0x582ed, Direction=In
    // DB CW 0x5B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW5C_ChB_D1;     // Byte offset 0x5dc, CSR Addr 0x582ee, Direction=In
    // DB CW 0x5C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW5D_ChB_D1;     // Byte offset 0x5dd, CSR Addr 0x582ee, Direction=In
    // DB CW 0x5D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW5E_ChB_D1;     // Byte offset 0x5de, CSR Addr 0x582ef, Direction=In
    // DB CW 0x5E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW5F_ChB_D1;     // Byte offset 0x5df, CSR Addr 0x582ef, Direction=In
    // DB CW 0x5F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW60_ChB_D1;     // Byte offset 0x5e0, CSR Addr 0x582f0, Direction=In
    // DB CW 0x60 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW61_ChB_D1;     // Byte offset 0x5e1, CSR Addr 0x582f0, Direction=In
    // DB CW 0x61 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW62_ChB_D1;     // Byte offset 0x5e2, CSR Addr 0x582f1, Direction=In
    // DB CW 0x62 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW63_ChB_D1;     // Byte offset 0x5e3, CSR Addr 0x582f1, Direction=In
    // DB CW 0x63 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW64_ChB_D1;     // Byte offset 0x5e4, CSR Addr 0x582f2, Direction=In
    // DB CW 0x64 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW65_ChB_D1;     // Byte offset 0x5e5, CSR Addr 0x582f2, Direction=In
    // DB CW 0x65 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW66_ChB_D1;     // Byte offset 0x5e6, CSR Addr 0x582f3, Direction=In
    // DB CW 0x66 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW67_ChB_D1;     // Byte offset 0x5e7, CSR Addr 0x582f3, Direction=In
    // DB CW 0x67 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW68_ChB_D1;     // Byte offset 0x5e8, CSR Addr 0x582f4, Direction=In
    // DB CW 0x68 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW69_ChB_D1;     // Byte offset 0x5e9, CSR Addr 0x582f4, Direction=In
    // DB CW 0x69 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW6A_ChB_D1;     // Byte offset 0x5ea, CSR Addr 0x582f5, Direction=In
    // DB CW 0x6A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW6B_ChB_D1;     // Byte offset 0x5eb, CSR Addr 0x582f5, Direction=In
    // DB CW 0x6B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW6C_ChB_D1;     // Byte offset 0x5ec, CSR Addr 0x582f6, Direction=In
    // DB CW 0x6C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW6D_ChB_D1;     // Byte offset 0x5ed, CSR Addr 0x582f6, Direction=In
    // DB CW 0x6D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW6E_ChB_D1;     // Byte offset 0x5ee, CSR Addr 0x582f7, Direction=In
    // DB CW 0x6E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW6F_ChB_D1;     // Byte offset 0x5ef, CSR Addr 0x582f7, Direction=In
    // DB CW 0x6F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW70_ChB_D1;     // Byte offset 0x5f0, CSR Addr 0x582f8, Direction=In
    // DB CW 0x70 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW71_ChB_D1;     // Byte offset 0x5f1, CSR Addr 0x582f8, Direction=In
    // DB CW 0x71 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW72_ChB_D1;     // Byte offset 0x5f2, CSR Addr 0x582f9, Direction=In
    // DB CW 0x72 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW73_ChB_D1;     // Byte offset 0x5f3, CSR Addr 0x582f9, Direction=In
    // DB CW 0x73 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW74_ChB_D1;     // Byte offset 0x5f4, CSR Addr 0x582fa, Direction=In
    // DB CW 0x74 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW75_ChB_D1;     // Byte offset 0x5f5, CSR Addr 0x582fa, Direction=In
    // DB CW 0x75 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW76_ChB_D1;     // Byte offset 0x5f6, CSR Addr 0x582fb, Direction=In
    // DB CW 0x76 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW77_ChB_D1;     // Byte offset 0x5f7, CSR Addr 0x582fb, Direction=In
    // DB CW 0x77 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW78_ChB_D1;     // Byte offset 0x5f8, CSR Addr 0x582fc, Direction=In
    // DB CW 0x78 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW79_ChB_D1;     // Byte offset 0x5f9, CSR Addr 0x582fc, Direction=In
    // DB CW 0x79 setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW7A_ChB_D1;     // Byte offset 0x5fa, CSR Addr 0x582fd, Direction=In
    // DB CW 0x7A setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW7B_ChB_D1;     // Byte offset 0x5fb, CSR Addr 0x582fd, Direction=In
    // DB CW 0x7B setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW7C_ChB_D1;     // Byte offset 0x5fc, CSR Addr 0x582fe, Direction=In
    // DB CW 0x7C setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW7D_ChB_D1;     // Byte offset 0x5fd, CSR Addr 0x582fe, Direction=In
    // DB CW 0x7D setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW7E_ChB_D1;     // Byte offset 0x5fe, CSR Addr 0x582ff, Direction=In
    // DB CW 0x7E setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  BCW7F_ChB_D1;     // Byte offset 0x5ff, CSR Addr 0x582ff, Direction=In
    // DB CW 0x7F setting, Channel B, DIMM1. Unused for UDIMM.
    uint8_t  VrefDqR0Nib0;     // Byte offset 0x600, CSR Addr 0x58300, Direction=InOut
    // VrefDq for rank 0 nibble  0. Specifies MR10[6:0].
    uint8_t  VrefDqR0Nib1;     // Byte offset 0x601, CSR Addr 0x58300, Direction=InOut
    // VrefDq for rank 0 nibble  1. Specifies MR10[6:0]. Identical to VrefDqR0Nib0 for x8 or x16 devices.
    uint8_t  VrefDqR0Nib2;     // Byte offset 0x602, CSR Addr 0x58301, Direction=InOut
    // VrefDq for rank 0 nibble  2. Specifies MR10[6:0]. Identical to VrefDqR0Nib0 for x16 devices.
    uint8_t  VrefDqR0Nib3;     // Byte offset 0x603, CSR Addr 0x58301, Direction=InOut
    // VrefDq for rank 0 nibble  3. Specifies MR10[6:0]. Identical to VrefDqR0Nib0 for x16 devices, or VrefDqR0Nib2 for x8 devices.
    uint8_t  VrefDqR0Nib4;     // Byte offset 0x604, CSR Addr 0x58302, Direction=InOut
    // VrefDq for rank 0 nibble  4. Specifies MR10[6:0].
    uint8_t  VrefDqR0Nib5;     // Byte offset 0x605, CSR Addr 0x58302, Direction=InOut
    // VrefDq for rank 0 nibble  5. Specifies MR10[6:0]. Identical to VrefDqR0Nib4 for x8 or x16 devices.
    uint8_t  VrefDqR0Nib6;     // Byte offset 0x606, CSR Addr 0x58303, Direction=InOut
    // VrefDq for rank 0 nibble  6. Specifies MR10[6:0]. Identical to VrefDqR0Nib4 for x16 devices.
    uint8_t  VrefDqR0Nib7;     // Byte offset 0x607, CSR Addr 0x58303, Direction=InOut
    // VrefDq for rank 0 nibble  7. Specifies MR10[6:0]. Identical to VrefDqR0Nib4 for x16 devices, or VrefDqR0Nib6 for x8 devices.
    uint8_t  VrefDqR0Nib8;     // Byte offset 0x608, CSR Addr 0x58304, Direction=InOut
    // VrefDq for rank 0 nibble  8. Specifies MR10[6:0].
    uint8_t  VrefDqR0Nib9;     // Byte offset 0x609, CSR Addr 0x58304, Direction=InOut
    // VrefDq for rank 0 nibble  9. Specifies MR10[6:0]. Identical to VrefDqR0Nib8 for x8 or x16 devices.
    uint8_t  VrefDqR0Nib10;    // Byte offset 0x60a, CSR Addr 0x58305, Direction=InOut
    // VrefDq for rank 0 nibble 10. Specifies MR10[6:0]. Identical to VrefDqR0Nib8 for x16 devices.
    uint8_t  VrefDqR0Nib11;    // Byte offset 0x60b, CSR Addr 0x58305, Direction=InOut
    // VrefDq for rank 0 nibble 11. Specifies MR10[6:0]. Identical to VrefDqR0Nib8 for x16 devices, or VrefDqR0Nib10 for x8 devices.
    uint8_t  VrefDqR0Nib12;    // Byte offset 0x60c, CSR Addr 0x58306, Direction=InOut
    // VrefDq for rank 0 nibble 12. Specifies MR10[6:0].
    uint8_t  VrefDqR0Nib13;    // Byte offset 0x60d, CSR Addr 0x58306, Direction=InOut
    // VrefDq for rank 0 nibble 13. Specifies MR10[6:0]. Identical to VrefDqR0Nib12 for x8 or x16 devices.
    uint8_t  VrefDqR0Nib14;    // Byte offset 0x60e, CSR Addr 0x58307, Direction=InOut
    // VrefDq for rank 0 nibble 14. Specifies MR10[6:0]. Identical to VrefDqR0Nib12 for x16 devices.
    uint8_t  VrefDqR0Nib15;    // Byte offset 0x60f, CSR Addr 0x58307, Direction=InOut
    // VrefDq for rank 0 nibble 15. Specifies MR10[6:0]. Identical to VrefDqR0Nib12 for x16 devices, or VrefDqR0Nib14 for x8 devices.
    uint8_t  VrefDqR0Nib16;    // Byte offset 0x610, CSR Addr 0x58308, Direction=InOut
    // VrefDq for rank 0 nibble 16. Specifies MR10[6:0].
    uint8_t  VrefDqR0Nib17;    // Byte offset 0x611, CSR Addr 0x58308, Direction=InOut
    // VrefDq for rank 0 nibble 17. Specifies MR10[6:0]. Identical to VrefDqR0Nib16 for x8 or x16 devices.
    uint8_t  VrefDqR0Nib18;    // Byte offset 0x612, CSR Addr 0x58309, Direction=InOut
    // VrefDq for rank 0 nibble 18. Specifies MR10[6:0]. Identical to VrefDqR0Nib16 for x16 devices.
    uint8_t  VrefDqR0Nib19;    // Byte offset 0x613, CSR Addr 0x58309, Direction=InOut
    // VrefDq for rank 0 nibble 19. Specifies MR10[6:0]. Identical to VrefDqR0Nib16 for x16 devices, or VrefDqR0Nib18 for x8 devices.
    uint8_t  VrefDqR1Nib0;     // Byte offset 0x614, CSR Addr 0x5830a, Direction=InOut
    // VrefDq for rank 1 nibble  0. Specifies MR10[6:0]
    uint8_t  VrefDqR1Nib1;     // Byte offset 0x615, CSR Addr 0x5830a, Direction=InOut
    // VrefDq for rank 1 nibble  1. Specifies MR10[6:0]. Identical to VrefDqR1Nib0 for x8 or x16 devices.
    uint8_t  VrefDqR1Nib2;     // Byte offset 0x616, CSR Addr 0x5830b, Direction=InOut
    // VrefDq for rank 1 nibble  2. Specifies MR10[6:0]. Identical to VrefDqR1Nib0 for x16 devices.
    uint8_t  VrefDqR1Nib3;     // Byte offset 0x617, CSR Addr 0x5830b, Direction=InOut
    // VrefDq for rank 1 nibble  3. Specifies MR10[6:0]. Identical to VrefDqR1Nib0 for x16 devices, or VrefDqR1Nib2 for x8 devices.
    uint8_t  VrefDqR1Nib4;     // Byte offset 0x618, CSR Addr 0x5830c, Direction=InOut
    // VrefDq for rank 1 nibble  4. Specifies MR10[6:0]
    uint8_t  VrefDqR1Nib5;     // Byte offset 0x619, CSR Addr 0x5830c, Direction=InOut
    // VrefDq for rank 1 nibble  5. Specifies MR10[6:0]. Identical to VrefDqR1Nib4 for x8 or x16 devices.
    uint8_t  VrefDqR1Nib6;     // Byte offset 0x61a, CSR Addr 0x5830d, Direction=InOut
    // VrefDq for rank 1 nibble  6. Specifies MR10[6:0]. Identical to VrefDqR1Nib4 for x16 devices.
    uint8_t  VrefDqR1Nib7;     // Byte offset 0x61b, CSR Addr 0x5830d, Direction=InOut
    // VrefDq for rank 1 nibble  7. Specifies MR10[6:0]. Identical to VrefDqR1Nib4 for x16 devices, or VrefDqR1Nib6 for x8 devices.
    uint8_t  VrefDqR1Nib8;     // Byte offset 0x61c, CSR Addr 0x5830e, Direction=InOut
    // VrefDq for rank 1 nibble  8. Specifies MR10[6:0]
    uint8_t  VrefDqR1Nib9;     // Byte offset 0x61d, CSR Addr 0x5830e, Direction=InOut
    // VrefDq for rank 1 nibble  9. Specifies MR10[6:0]. Identical to VrefDqR1Nib8 for x8 or x16 devices.
    uint8_t  VrefDqR1Nib10;    // Byte offset 0x61e, CSR Addr 0x5830f, Direction=InOut
    // VrefDq for rank 1 nibble 10. Specifies MR10[6:0]. Identical to VrefDqR1Nib8 for x16 devices.
    uint8_t  VrefDqR1Nib11;    // Byte offset 0x61f, CSR Addr 0x5830f, Direction=InOut
    // VrefDq for rank 1 nibble 11. Specifies MR10[6:0]. Identical to VrefDqR1Nib8 for x16 devices, or VrefDqR1Nib10 for x8 devices.
    uint8_t  VrefDqR1Nib12;    // Byte offset 0x620, CSR Addr 0x58310, Direction=InOut
    // VrefDq for rank 1 nibble 12. Specifies MR10[6:0]
    uint8_t  VrefDqR1Nib13;    // Byte offset 0x621, CSR Addr 0x58310, Direction=InOut
    // VrefDq for rank 1 nibble 13. Specifies MR10[6:0]. Identical to VrefDqR1Nib12 for x8 or x16 devices.
    uint8_t  VrefDqR1Nib14;    // Byte offset 0x622, CSR Addr 0x58311, Direction=InOut
    // VrefDq for rank 1 nibble 14. Specifies MR10[6:0]. Identical to VrefDqR1Nib12 for x16 devices.
    uint8_t  VrefDqR1Nib15;    // Byte offset 0x623, CSR Addr 0x58311, Direction=InOut
    // VrefDq for rank 1 nibble 15. Specifies MR10[6:0]. Identical to VrefDqR1Nib12 for x16 devices, or VrefDqR1Nib14 for x8 devices.
    uint8_t  VrefDqR1Nib16;    // Byte offset 0x624, CSR Addr 0x58312, Direction=InOut
    // VrefDq for rank 1 nibble 16. Specifies MR10[6:0]
    uint8_t  VrefDqR1Nib17;    // Byte offset 0x625, CSR Addr 0x58312, Direction=InOut
    // VrefDq for rank 1 nibble 17. Specifies MR10[6:0]. Identical to VrefDqR1Nib16 for x8 or x16 devices.
    uint8_t  VrefDqR1Nib18;    // Byte offset 0x626, CSR Addr 0x58313, Direction=InOut
    // VrefDq for rank 1 nibble 18. Specifies MR10[6:0]. Identical to VrefDqR1Nib16 for x16 devices.
    uint8_t  VrefDqR1Nib19;    // Byte offset 0x627, CSR Addr 0x58313, Direction=InOut
    // VrefDq for rank 1 nibble 19. Specifies MR10[6:0]. Identical to VrefDqR1Nib16 for x16 devices, or VrefDqR1Nib18 for x8 devices.
    uint8_t  VrefDqR2Nib0;     // Byte offset 0x628, CSR Addr 0x58314, Direction=InOut
    // VrefDq for rank 2 nibble  0. Specifies MR10[6:0]
    uint8_t  VrefDqR2Nib1;     // Byte offset 0x629, CSR Addr 0x58314, Direction=InOut
    // VrefDq for rank 2 nibble  1. Specifies MR10[6:0]. Identical to VrefDqR2Nib0 for x8 or x16 devices.
    uint8_t  VrefDqR2Nib2;     // Byte offset 0x62a, CSR Addr 0x58315, Direction=InOut
    // VrefDq for rank 2 nibble  2. Specifies MR10[6:0]. Identical to VrefDqR2Nib0 for x16 devices.
    uint8_t  VrefDqR2Nib3;     // Byte offset 0x62b, CSR Addr 0x58315, Direction=InOut
    // VrefDq for rank 2 nibble  3. Specifies MR10[6:0]. Identical to VrefDqR2Nib0 for x16 devices, or VrefDqR2Nib2 for x8 devices.
    uint8_t  VrefDqR2Nib4;     // Byte offset 0x62c, CSR Addr 0x58316, Direction=InOut
    // VrefDq for rank 2 nibble  4. Specifies MR10[6:0]
    uint8_t  VrefDqR2Nib5;     // Byte offset 0x62d, CSR Addr 0x58316, Direction=InOut
    // VrefDq for rank 2 nibble  5. Specifies MR10[6:0]. Identical to VrefDqR2Nib4 for x8 or x16 devices.
    uint8_t  VrefDqR2Nib6;     // Byte offset 0x62e, CSR Addr 0x58317, Direction=InOut
    // VrefDq for rank 2 nibble  6. Specifies MR10[6:0]. Identical to VrefDqR2Nib4 for x16 devices.
    uint8_t  VrefDqR2Nib7;     // Byte offset 0x62f, CSR Addr 0x58317, Direction=InOut
    // VrefDq for rank 2 nibble  7. Specifies MR10[6:0]. Identical to VrefDqR2Nib4 for x16 devices, or VrefDqR2Nib6 for x8 devices.
    uint8_t  VrefDqR2Nib8;     // Byte offset 0x630, CSR Addr 0x58318, Direction=InOut
    // VrefDq for rank 2 nibble  8. Specifies MR10[6:0]
    uint8_t  VrefDqR2Nib9;     // Byte offset 0x631, CSR Addr 0x58318, Direction=InOut
    // VrefDq for rank 2 nibble  9. Specifies MR10[6:0]. Identical to VrefDqR2Nib8 for x8 or x16 devices.
    uint8_t  VrefDqR2Nib10;    // Byte offset 0x632, CSR Addr 0x58319, Direction=InOut
    // VrefDq for rank 2 nibble 10. Specifies MR10[6:0]. Identical to VrefDqR2Nib8 for x16 devices.
    uint8_t  VrefDqR2Nib11;    // Byte offset 0x633, CSR Addr 0x58319, Direction=InOut
    // VrefDq for rank 2 nibble 11. Specifies MR10[6:0]. Identical to VrefDqR2Nib8 for x16 devices, or VrefDqR2Nib10 for x8 devices.
    uint8_t  VrefDqR2Nib12;    // Byte offset 0x634, CSR Addr 0x5831a, Direction=InOut
    // VrefDq for rank 2 nibble 12. Specifies MR10[6:0]
    uint8_t  VrefDqR2Nib13;    // Byte offset 0x635, CSR Addr 0x5831a, Direction=InOut
    // VrefDq for rank 2 nibble 13. Specifies MR10[6:0]. Identical to VrefDqR2Nib12 for x8 or x16 devices.
    uint8_t  VrefDqR2Nib14;    // Byte offset 0x636, CSR Addr 0x5831b, Direction=InOut
    // VrefDq for rank 2 nibble 14. Specifies MR10[6:0]. Identical to VrefDqR2Nib12 for x16 devices.
    uint8_t  VrefDqR2Nib15;    // Byte offset 0x637, CSR Addr 0x5831b, Direction=InOut
    // VrefDq for rank 2 nibble 15. Specifies MR10[6:0]. Identical to VrefDqR2Nib12 for x16 devices, or VrefDqR2Nib14 for x8 devices.
    uint8_t  VrefDqR2Nib16;    // Byte offset 0x638, CSR Addr 0x5831c, Direction=InOut
    // VrefDq for rank 2 nibble 16. Specifies MR10[6:0]
    uint8_t  VrefDqR2Nib17;    // Byte offset 0x639, CSR Addr 0x5831c, Direction=InOut
    // VrefDq for rank 2 nibble 17. Specifies MR10[6:0]. Identical to VrefDqR2Nib16 for x8 or x16 devices.
    uint8_t  VrefDqR2Nib18;    // Byte offset 0x63a, CSR Addr 0x5831d, Direction=InOut
    // VrefDq for rank 2 nibble 18. Specifies MR10[6:0]. Identical to VrefDqR2Nib16 for x16 devices.
    uint8_t  VrefDqR2Nib19;    // Byte offset 0x63b, CSR Addr 0x5831d, Direction=InOut
    // VrefDq for rank 2 nibble 19. Specifies MR10[6:0]. Identical to VrefDqR2Nib16 for x16 devices, or VrefDqR2Nib18 for x8 devices.
    uint8_t  VrefDqR3Nib0;     // Byte offset 0x63c, CSR Addr 0x5831e, Direction=InOut
    // VrefDq for rank 3 nibble  0. Specifies MR10[6:0]
    uint8_t  VrefDqR3Nib1;     // Byte offset 0x63d, CSR Addr 0x5831e, Direction=InOut
    // VrefDq for rank 3 nibble  1. Specifies MR10[6:0]. Identical to VrefDqR3Nib0 for x8 or x16 devices.
    uint8_t  VrefDqR3Nib2;     // Byte offset 0x63e, CSR Addr 0x5831f, Direction=InOut
    // VrefDq for rank 3 nibble  2. Specifies MR10[6:0]. Identical to VrefDqR3Nib0 for x16 devices.
    uint8_t  VrefDqR3Nib3;     // Byte offset 0x63f, CSR Addr 0x5831f, Direction=InOut
    // VrefDq for rank 3 nibble  3. Specifies MR10[6:0]. Identical to VrefDqR3Nib0 for x16 devices, or VrefDqR3Nib2 for x8 devices.
    uint8_t  VrefDqR3Nib4;     // Byte offset 0x640, CSR Addr 0x58320, Direction=InOut
    // VrefDq for rank 3 nibble  4. Specifies MR10[6:0]
    uint8_t  VrefDqR3Nib5;     // Byte offset 0x641, CSR Addr 0x58320, Direction=InOut
    // VrefDq for rank 3 nibble  5. Specifies MR10[6:0]. Identical to VrefDqR3Nib4 for x8 or x16 devices.
    uint8_t  VrefDqR3Nib6;     // Byte offset 0x642, CSR Addr 0x58321, Direction=InOut
    // VrefDq for rank 3 nibble  6. Specifies MR10[6:0]. Identical to VrefDqR3Nib4 for x16 devices.
    uint8_t  VrefDqR3Nib7;     // Byte offset 0x643, CSR Addr 0x58321, Direction=InOut
    // VrefDq for rank 3 nibble  7. Specifies MR10[6:0]. Identical to VrefDqR3Nib4 for x16 devices, or VrefDqR3Nib6 for x8 devices.
    uint8_t  VrefDqR3Nib8;     // Byte offset 0x644, CSR Addr 0x58322, Direction=InOut
    // VrefDq for rank 3 nibble  8. Specifies MR10[6:0]
    uint8_t  VrefDqR3Nib9;     // Byte offset 0x645, CSR Addr 0x58322, Direction=InOut
    // VrefDq for rank 3 nibble  9. Specifies MR10[6:0]. Identical to VrefDqR3Nib8 for x8 or x16 devices.
    uint8_t  VrefDqR3Nib10;    // Byte offset 0x646, CSR Addr 0x58323, Direction=InOut
    // VrefDq for rank 3 nibble 10. Specifies MR10[6:0]. Identical to VrefDqR3Nib8 for x16 devices.
    uint8_t  VrefDqR3Nib11;    // Byte offset 0x647, CSR Addr 0x58323, Direction=InOut
    // VrefDq for rank 3 nibble 11. Specifies MR10[6:0]. Identical to VrefDqR3Nib8 for x16 devices, or VrefDqR3Nib10 for x8 devices.
    uint8_t  VrefDqR3Nib12;    // Byte offset 0x648, CSR Addr 0x58324, Direction=InOut
    // VrefDq for rank 3 nibble 12. Specifies MR10[6:0]
    uint8_t  VrefDqR3Nib13;    // Byte offset 0x649, CSR Addr 0x58324, Direction=InOut
    // VrefDq for rank 3 nibble 13. Specifies MR10[6:0]. Identical to VrefDqR3Nib12 for x8 or x16 devices.
    uint8_t  VrefDqR3Nib14;    // Byte offset 0x64a, CSR Addr 0x58325, Direction=InOut
    // VrefDq for rank 3 nibble 14. Specifies MR10[6:0]. Identical to VrefDqR3Nib12 for x16 devices.
    uint8_t  VrefDqR3Nib15;    // Byte offset 0x64b, CSR Addr 0x58325, Direction=InOut
    // VrefDq for rank 3 nibble 15. Specifies MR10[6:0]. Identical to VrefDqR3Nib12 for x16 devices, or VrefDqR3Nib14 for x8 devices.
    uint8_t  VrefDqR3Nib16;    // Byte offset 0x64c, CSR Addr 0x58326, Direction=InOut
    // VrefDq for rank 3 nibble 16. Specifies MR10[6:0].
    uint8_t  VrefDqR3Nib17;    // Byte offset 0x64d, CSR Addr 0x58326, Direction=InOut
    // VrefDq for rank 3 nibble 17. Specifies MR10[6:0]. Identical to VrefDqR3Nib16 for x8 or x16 devices.
    uint8_t  VrefDqR3Nib18;    // Byte offset 0x64e, CSR Addr 0x58327, Direction=InOut
    // VrefDq for rank 3 nibble 18. Specifies MR10[6:0]. Identical to VrefDqR3Nib16 for x16 devices.
    uint8_t  VrefDqR3Nib19;    // Byte offset 0x64f, CSR Addr 0x58327, Direction=InOut
    // VrefDq for rank 3 nibble 19. Specifies MR10[6:0]. Identical to VrefDqR3Nib16 for x16 devices, or VrefDqR3Nib18 for x8 devices.
    uint8_t  MR3R0Nib0;        // Byte offset 0x650, CSR Addr 0x58328, Direction=InOut
    // MR3 for rank 0 nibble 0 results from internal WL.
    uint8_t  MR3R0Nib1;        // Byte offset 0x651, CSR Addr 0x58328, Direction=InOut
    // MR3 for rank 0 nibble 1 results from internal WL.  Identical to MR3R0Nib0 for x8 or x16 devices.
    uint8_t  MR3R0Nib2;        // Byte offset 0x652, CSR Addr 0x58329, Direction=InOut
    // MR3 for rank 0 nibble 2 results from internal WL.  Identical to MR3R0Nib0 for x16 device.
    uint8_t  MR3R0Nib3;        // Byte offset 0x653, CSR Addr 0x58329, Direction=InOut
    // MR3 for rank 0 nibble 3 results from internal WL.  Identical to MR3R0Nib0 for x16 device, or MR3R0Nib2 for x8 or x16 devices.
    uint8_t  MR3R0Nib4;        // Byte offset 0x654, CSR Addr 0x5832a, Direction=InOut
    // MR3 for rank 0 nibble 4 results from internal WL.
    uint8_t  MR3R0Nib5;        // Byte offset 0x655, CSR Addr 0x5832a, Direction=InOut
    // MR3 for rank 0 nibble 5 results from internal WL.  Identical to MR3R0Nib4 for x8 or x16 devices.
    uint8_t  MR3R0Nib6;        // Byte offset 0x656, CSR Addr 0x5832b, Direction=InOut
    // MR3 for rank 0 nibble 6 results from internal WL.  Identical to MR3R0Nib4 for x16 device.
    uint8_t  MR3R0Nib7;        // Byte offset 0x657, CSR Addr 0x5832b, Direction=InOut
    // MR3 for rank 0 nibble 7 results from internal WL.  Identical to MR3R0Nib4 for x16 device, or MR3R0Nib6 for x8 or x16 devices.
    uint8_t  MR3R0Nib8;        // Byte offset 0x658, CSR Addr 0x5832c, Direction=InOut
    // MR3 for rank 0 nibble 8 results from internal WL.
    uint8_t  MR3R0Nib9;        // Byte offset 0x659, CSR Addr 0x5832c, Direction=InOut
    // MR3 for rank 0 nibble 9 results from internal WL.  Identical to MR3R0Nib8 for x8 or x16 devices.
    uint8_t  MR3R0Nib10;       // Byte offset 0x65a, CSR Addr 0x5832d, Direction=InOut
    // MR3 for rank 0 nibble 10 results from internal WL.  Identical to MR3R0Nib8 for x16 device.
    uint8_t  MR3R0Nib11;       // Byte offset 0x65b, CSR Addr 0x5832d, Direction=InOut
    // MR3 for rank 0 nibble 11 results from internal WL.  Identical to MR3R0Nib8 for x16 device, or MR3R0Nib10 for x8 or x16 devices.
    uint8_t  MR3R0Nib12;       // Byte offset 0x65c, CSR Addr 0x5832e, Direction=InOut
    // MR3 for rank 0 nibble 12 results from internal WL.
    uint8_t  MR3R0Nib13;       // Byte offset 0x65d, CSR Addr 0x5832e, Direction=InOut
    // MR3 for rank 0 nibble 13 results from internal WL.  Identical to MR3R0Nib12 for x8 or x16 devices.
    uint8_t  MR3R0Nib14;       // Byte offset 0x65e, CSR Addr 0x5832f, Direction=InOut
    // MR3 for rank 0 nibble 14 results from internal WL.  Identical to MR3R0Nib12 for x16 device.
    uint8_t  MR3R0Nib15;       // Byte offset 0x65f, CSR Addr 0x5832f, Direction=InOut
    // MR3 for rank 0 nibble 15 results from internal WL.  Identical to MR3R0Nib12 for x16 device, or MR3R0Nib14 for x8 or x16 devices.
    uint8_t  MR3R0Nib16;       // Byte offset 0x660, CSR Addr 0x58330, Direction=InOut
    // MR3 for rank 0 nibble 16 results from internal WL.
    uint8_t  MR3R0Nib17;       // Byte offset 0x661, CSR Addr 0x58330, Direction=InOut
    // MR3 for rank 0 nibble 17 results from internal WL.  Identical to MR3R0Nib16 for x8 or x16 devices.
    uint8_t  MR3R0Nib18;       // Byte offset 0x662, CSR Addr 0x58331, Direction=InOut
    // MR3 for rank 0 nibble 18 results from internal WL.  Identical to MR3R0Nib16 for x16 device.
    uint8_t  MR3R0Nib19;       // Byte offset 0x663, CSR Addr 0x58331, Direction=InOut
    // MR3 for rank 0 nibble 19 results from internal WL.  Identical to MR3R0Nib16 for x16 device, or MR3R0Nib2 for x8 or x16 devices.
    uint8_t  MR3R1Nib0;        // Byte offset 0x664, CSR Addr 0x58332, Direction=InOut
    // MR3 for rank 1 nibble 0 results from internal WL.
    uint8_t  MR3R1Nib1;        // Byte offset 0x665, CSR Addr 0x58332, Direction=InOut
    // MR3 for rank 1 nibble 1 results from internal WL.  Identical to MR3R1Nib0 for x8 or x16 devices.
    uint8_t  MR3R1Nib2;        // Byte offset 0x666, CSR Addr 0x58333, Direction=InOut
    // MR3 for rank 1 nibble 2 results from internal WL.  Identical to MR3R1Nib0 for x16 device.
    uint8_t  MR3R1Nib3;        // Byte offset 0x667, CSR Addr 0x58333, Direction=InOut
    // MR3 for rank 1 nibble 3 results from internal WL.  Identical to MR3R1Nib0 for x16 device, or MR3R1Nib2 for x8 or x16 devices.
    uint8_t  MR3R1Nib4;        // Byte offset 0x668, CSR Addr 0x58334, Direction=InOut
    // MR3 for rank 1 nibble 4 results from internal WL.
    uint8_t  MR3R1Nib5;        // Byte offset 0x669, CSR Addr 0x58334, Direction=InOut
    // MR3 for rank 1 nibble 5 results from internal WL.  Identical to MR3R1Nib4 for x8 or x16 devices.
    uint8_t  MR3R1Nib6;        // Byte offset 0x66a, CSR Addr 0x58335, Direction=InOut
    // MR3 for rank 1 nibble 6 results from internal WL.  Identical to MR3R1Nib4 for x16 device.
    uint8_t  MR3R1Nib7;        // Byte offset 0x66b, CSR Addr 0x58335, Direction=InOut
    // MR3 for rank 1 nibble 7 results from internal WL.  Identical to MR3R1Nib4 for x16 device, or MR3R1Nib6 for x8 or x16 devices.
    uint8_t  MR3R1Nib8;        // Byte offset 0x66c, CSR Addr 0x58336, Direction=InOut
    // MR3 for rank 1 nibble 8 results from internal WL.
    uint8_t  MR3R1Nib9;        // Byte offset 0x66d, CSR Addr 0x58336, Direction=InOut
    // MR3 for rank 1 nibble 9 results from internal WL.  Identical to MR3R1Nib8 for x8 or x16 devices.
    uint8_t  MR3R1Nib10;       // Byte offset 0x66e, CSR Addr 0x58337, Direction=InOut
    // MR3 for rank 1 nibble 10 results from internal WL.  Identical to MR3R1Nib8 for x16 device.
    uint8_t  MR3R1Nib11;       // Byte offset 0x66f, CSR Addr 0x58337, Direction=InOut
    // MR3 for rank 1 nibble 11 results from internal WL.  Identical to MR3R1Nib8 for x16 device, or MR3R1Nib10 for x8 or x16 devices.
    uint8_t  MR3R1Nib12;       // Byte offset 0x670, CSR Addr 0x58338, Direction=InOut
    // MR3 for rank 1 nibble 12 results from internal WL.
    uint8_t  MR3R1Nib13;       // Byte offset 0x671, CSR Addr 0x58338, Direction=InOut
    // MR3 for rank 1 nibble 13 results from internal WL.  Identical to MR3R1Nib12 for x8 or x16 devices.
    uint8_t  MR3R1Nib14;       // Byte offset 0x672, CSR Addr 0x58339, Direction=InOut
    // MR3 for rank 1 nibble 14 results from internal WL.  Identical to MR3R1Nib12 for x16 device.
    uint8_t  MR3R1Nib15;       // Byte offset 0x673, CSR Addr 0x58339, Direction=InOut
    // MR3 for rank 1 nibble 15 results from internal WL.  Identical to MR3R1Nib12 for x16 device, or MR3R1Nib14 for x8 or x16 devices.
    uint8_t  MR3R1Nib16;       // Byte offset 0x674, CSR Addr 0x5833a, Direction=InOut
    // MR3 for rank 1 nibble 16 results from internal WL.
    uint8_t  MR3R1Nib17;       // Byte offset 0x675, CSR Addr 0x5833a, Direction=InOut
    // MR3 for rank 1 nibble 17 results from internal WL.  Identical to MR3R1Nib16 for x8 or x16 devices.
    uint8_t  MR3R1Nib18;       // Byte offset 0x676, CSR Addr 0x5833b, Direction=InOut
    // MR3 for rank 1 nibble 18 results from internal WL.  Identical to MR3R1Nib16 for x16 device.
    uint8_t  MR3R1Nib19;       // Byte offset 0x677, CSR Addr 0x5833b, Direction=InOut
    // MR3 for rank 1 nibble 19 results from internal WL.  Identical to MR3R1Nib16 for x16 device, or MR3R1Nib2 for x8 or x16 devices.
    uint8_t  MR3R2Nib0;        // Byte offset 0x678, CSR Addr 0x5833c, Direction=InOut
    // MR3 for rank 2 nibble 0 results from internal WL.
    uint8_t  MR3R2Nib1;        // Byte offset 0x679, CSR Addr 0x5833c, Direction=InOut
    // MR3 for rank 2 nibble 1 results from internal WL.  Identical to MR3R2Nib0 for x8 or x16 devices.
    uint8_t  MR3R2Nib2;        // Byte offset 0x67a, CSR Addr 0x5833d, Direction=InOut
    // MR3 for rank 2 nibble 2 results from internal WL.  Identical to MR3R2Nib0 for x16 device.
    uint8_t  MR3R2Nib3;        // Byte offset 0x67b, CSR Addr 0x5833d, Direction=InOut
    // MR3 for rank 2 nibble 3 results from internal WL.  Identical to MR3R2Nib0 for x16 device, or MR3R2Nib2 for x8 or x16 devices.
    uint8_t  MR3R2Nib4;        // Byte offset 0x67c, CSR Addr 0x5833e, Direction=InOut
    // MR3 for rank 2 nibble 4 results from internal WL.
    uint8_t  MR3R2Nib5;        // Byte offset 0x67d, CSR Addr 0x5833e, Direction=InOut
    // MR3 for rank 2 nibble 5 results from internal WL.  Identical to MR3R2Nib4 for x8 or x16 devices.
    uint8_t  MR3R2Nib6;        // Byte offset 0x67e, CSR Addr 0x5833f, Direction=InOut
    // MR3 for rank 2 nibble 6 results from internal WL.  Identical to MR3R2Nib4 for x16 device.
    uint8_t  MR3R2Nib7;        // Byte offset 0x67f, CSR Addr 0x5833f, Direction=InOut
    // MR3 for rank 2 nibble 7 results from internal WL.  Identical to MR3R2Nib4 for x16 device, or MR3R2Nib6 for x8 or x16 devices.
    uint8_t  MR3R2Nib8;        // Byte offset 0x680, CSR Addr 0x58340, Direction=InOut
    // MR3 for rank 2 nibble 8 results from internal WL.
    uint8_t  MR3R2Nib9;        // Byte offset 0x681, CSR Addr 0x58340, Direction=InOut
    // MR3 for rank 2 nibble 9 results from internal WL.  Identical to MR3R2Nib8 for x8 or x16 devices.
    uint8_t  MR3R2Nib10;       // Byte offset 0x682, CSR Addr 0x58341, Direction=InOut
    // MR3 for rank 2 nibble 10 results from internal WL.  Identical to MR3R2Nib8 for x16 device.
    uint8_t  MR3R2Nib11;       // Byte offset 0x683, CSR Addr 0x58341, Direction=InOut
    // MR3 for rank 2 nibble 11 results from internal WL.  Identical to MR3R2Nib8 for x16 device, or MR3R2Nib10 for x8 or x16 devices.
    uint8_t  MR3R2Nib12;       // Byte offset 0x684, CSR Addr 0x58342, Direction=InOut
    // MR3 for rank 2 nibble 12 results from internal WL.
    uint8_t  MR3R2Nib13;       // Byte offset 0x685, CSR Addr 0x58342, Direction=InOut
    // MR3 for rank 2 nibble 13 results from internal WL.  Identical to MR3R2Nib12 for x8 or x16 devices.
    uint8_t  MR3R2Nib14;       // Byte offset 0x686, CSR Addr 0x58343, Direction=InOut
    // MR3 for rank 2 nibble 14 results from internal WL.  Identical to MR3R2Nib12 for x16 device.
    uint8_t  MR3R2Nib15;       // Byte offset 0x687, CSR Addr 0x58343, Direction=InOut
    // MR3 for rank 2 nibble 15 results from internal WL.  Identical to MR3R2Nib12 for x16 device, or MR3R2Nib14 for x8 or x16 devices.
    uint8_t  MR3R2Nib16;       // Byte offset 0x688, CSR Addr 0x58344, Direction=InOut
    // MR3 for rank 2 nibble 16 results from internal WL.
    uint8_t  MR3R2Nib17;       // Byte offset 0x689, CSR Addr 0x58344, Direction=InOut
    // MR3 for rank 2 nibble 17 results from internal WL.  Identical to MR3R2Nib16 for x8 or x16 devices.
    uint8_t  MR3R2Nib18;       // Byte offset 0x68a, CSR Addr 0x58345, Direction=InOut
    // MR3 for rank 2 nibble 18 results from internal WL.  Identical to MR3R2Nib16 for x16 device.
    uint8_t  MR3R2Nib19;       // Byte offset 0x68b, CSR Addr 0x58345, Direction=InOut
    // MR3 for rank 2 nibble 19 results from internal WL.  Identical to MR3R2Nib16 for x16 device, or MR3R2Nib2 for x8 or x16 devices.
    uint8_t  MR3R3Nib0;        // Byte offset 0x68c, CSR Addr 0x58346, Direction=InOut
    // MR3 for rank 3 nibble 0 results from internal WL.
    uint8_t  MR3R3Nib1;        // Byte offset 0x68d, CSR Addr 0x58346, Direction=InOut
    // MR3 for rank 3 nibble 1 results from internal WL.  Identical to MR3R3Nib0 for x8 or x16 devices.
    uint8_t  MR3R3Nib2;        // Byte offset 0x68e, CSR Addr 0x58347, Direction=InOut
    // MR3 for rank 3 nibble 2 results from internal WL.  Identical to MR3R3Nib0 for x16 device.
    uint8_t  MR3R3Nib3;        // Byte offset 0x68f, CSR Addr 0x58347, Direction=InOut
    // MR3 for rank 3 nibble 3 results from internal WL.  Identical to MR3R3Nib0 for x16 device, or MR3R3Nib2 for x8 or x16 devices.
    uint8_t  MR3R3Nib4;        // Byte offset 0x690, CSR Addr 0x58348, Direction=InOut
    // MR3 for rank 3 nibble 4 results from internal WL.
    uint8_t  MR3R3Nib5;        // Byte offset 0x691, CSR Addr 0x58348, Direction=InOut
    // MR3 for rank 3 nibble 5 results from internal WL.  Identical to MR3R3Nib4 for x8 or x16 devices.
    uint8_t  MR3R3Nib6;        // Byte offset 0x692, CSR Addr 0x58349, Direction=InOut
    // MR3 for rank 3 nibble 6 results from internal WL.  Identical to MR3R3Nib4 for x16 device.
    uint8_t  MR3R3Nib7;        // Byte offset 0x693, CSR Addr 0x58349, Direction=InOut
    // MR3 for rank 3 nibble 7 results from internal WL.  Identical to MR3R3Nib4 for x16 device, or MR3R3Nib6 for x8 or x16 devices.
    uint8_t  MR3R3Nib8;        // Byte offset 0x694, CSR Addr 0x5834a, Direction=InOut
    // MR3 for rank 3 nibble 8 results from internal WL.
    uint8_t  MR3R3Nib9;        // Byte offset 0x695, CSR Addr 0x5834a, Direction=InOut
    // MR3 for rank 3 nibble 9 results from internal WL.  Identical to MR3R3Nib8 for x8 or x16 devices.
    uint8_t  MR3R3Nib10;       // Byte offset 0x696, CSR Addr 0x5834b, Direction=InOut
    // MR3 for rank 3 nibble 10 results from internal WL.  Identical to MR3R3Nib8 for x16 device.
    uint8_t  MR3R3Nib11;       // Byte offset 0x697, CSR Addr 0x5834b, Direction=InOut
    // MR3 for rank 3 nibble 11 results from internal WL.  Identical to MR3R3Nib8 for x16 device, or MR3R3Nib10 for x8 or x16 devices.
    uint8_t  MR3R3Nib12;       // Byte offset 0x698, CSR Addr 0x5834c, Direction=InOut
    // MR3 for rank 3 nibble 12 results from internal WL.
    uint8_t  MR3R3Nib13;       // Byte offset 0x699, CSR Addr 0x5834c, Direction=InOut
    // MR3 for rank 3 nibble 13 results from internal WL.  Identical to MR3R3Nib12 for x8 or x16 devices.
    uint8_t  MR3R3Nib14;       // Byte offset 0x69a, CSR Addr 0x5834d, Direction=InOut
    // MR3 for rank 3 nibble 14 results from internal WL.  Identical to MR3R3Nib12 for x16 device.
    uint8_t  MR3R3Nib15;       // Byte offset 0x69b, CSR Addr 0x5834d, Direction=InOut
    // MR3 for rank 3 nibble 15 results from internal WL.  Identical to MR3R3Nib12 for x16 device, or MR3R3Nib14 for x8 or x16 devices.
    uint8_t  MR3R3Nib16;       // Byte offset 0x69c, CSR Addr 0x5834e, Direction=InOut
    // MR3 for rank 3 nibble 16 results from internal WL.
    uint8_t  MR3R3Nib17;       // Byte offset 0x69d, CSR Addr 0x5834e, Direction=InOut
    // MR3 for rank 3 nibble 17 results from internal WL.  Identical to MR3R3Nib16 for x8 or x16 devices.
    uint8_t  MR3R3Nib18;       // Byte offset 0x69e, CSR Addr 0x5834f, Direction=InOut
    // MR3 for rank 3 nibble 18 results from internal WL.  Identical to MR3R3Nib16 for x16 device.
    uint8_t  MR3R3Nib19;       // Byte offset 0x69f, CSR Addr 0x5834f, Direction=InOut
    // MR3 for rank 3 nibble 19 results from internal WL.  Identical to MR3R3Nib16 for x16 device, or MR3R3Nib2 for x8 or x16 devices.
    uint8_t  VrefCSR0Nib0;     // Byte offset 0x6a0, CSR Addr 0x58350, Direction=InOut
    // VrefCS for rank 0 nibble 0 (only for setting, not trained).
    uint8_t  VrefCSR0Nib1;     // Byte offset 0x6a1, CSR Addr 0x58350, Direction=InOut
    // VrefCS for rank 0 nibble 1 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib2;     // Byte offset 0x6a2, CSR Addr 0x58351, Direction=InOut
    // VrefCS for rank 0 nibble 2 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR0Nib3;     // Byte offset 0x6a3, CSR Addr 0x58351, Direction=InOut
    // VrefCS for rank 0 nibble 3 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib4;     // Byte offset 0x6a4, CSR Addr 0x58352, Direction=InOut
    // VrefCS for rank 0 nibble 4 (only for setting, not trained).
    uint8_t  VrefCSR0Nib5;     // Byte offset 0x6a5, CSR Addr 0x58352, Direction=InOut
    // VrefCS for rank 0 nibble 5 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib6;     // Byte offset 0x6a6, CSR Addr 0x58353, Direction=InOut
    // VrefCS for rank 0 nibble 6 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR0Nib7;     // Byte offset 0x6a7, CSR Addr 0x58353, Direction=InOut
    // VrefCS for rank 0 nibble 7 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib8;     // Byte offset 0x6a8, CSR Addr 0x58354, Direction=InOut
    // VrefCS for rank 0 nibble 8 (only for setting, not trained).
    uint8_t  VrefCSR0Nib9;     // Byte offset 0x6a9, CSR Addr 0x58354, Direction=InOut
    // VrefCS for rank 0 nibble 9 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib10;    // Byte offset 0x6aa, CSR Addr 0x58355, Direction=InOut
    // VrefCS for rank 0 nibble 10 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR0Nib11;    // Byte offset 0x6ab, CSR Addr 0x58355, Direction=InOut
    // VrefCS for rank 0 nibble 11 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib12;    // Byte offset 0x6ac, CSR Addr 0x58356, Direction=InOut
    // VrefCS for rank 0 nibble 12 (only for setting, not trained).
    uint8_t  VrefCSR0Nib13;    // Byte offset 0x6ad, CSR Addr 0x58356, Direction=InOut
    // VrefCS for rank 0 nibble 13 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib14;    // Byte offset 0x6ae, CSR Addr 0x58357, Direction=InOut
    // VrefCS for rank 0 nibble 14 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR0Nib15;    // Byte offset 0x6af, CSR Addr 0x58357, Direction=InOut
    // VrefCS for rank 0 nibble 15 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib16;    // Byte offset 0x6b0, CSR Addr 0x58358, Direction=InOut
    // VrefCS for rank 0 nibble 16 (only for setting, not trained).
    uint8_t  VrefCSR0Nib17;    // Byte offset 0x6b1, CSR Addr 0x58358, Direction=InOut
    // VrefCS for rank 0 nibble 17 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR0Nib18;    // Byte offset 0x6b2, CSR Addr 0x58359, Direction=InOut
    // VrefCS for rank 0 nibble 18 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR0Nib19;    // Byte offset 0x6b3, CSR Addr 0x58359, Direction=InOut
    // VrefCS for rank 0 nibble 19 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib0;     // Byte offset 0x6b4, CSR Addr 0x5835a, Direction=InOut
    // VrefCS for rank 1 nibble 0 (only for setting, not trained).
    uint8_t  VrefCSR1Nib1;     // Byte offset 0x6b5, CSR Addr 0x5835a, Direction=InOut
    // VrefCS for rank 1 nibble 1 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib2;     // Byte offset 0x6b6, CSR Addr 0x5835b, Direction=InOut
    // VrefCS for rank 1 nibble 2 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR1Nib3;     // Byte offset 0x6b7, CSR Addr 0x5835b, Direction=InOut
    // VrefCS for rank 1 nibble 3 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib4;     // Byte offset 0x6b8, CSR Addr 0x5835c, Direction=InOut
    // VrefCS for rank 1 nibble 4 (only for setting, not trained).
    uint8_t  VrefCSR1Nib5;     // Byte offset 0x6b9, CSR Addr 0x5835c, Direction=InOut
    // VrefCS for rank 1 nibble 5 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib6;     // Byte offset 0x6ba, CSR Addr 0x5835d, Direction=InOut
    // VrefCS for rank 1 nibble 6 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR1Nib7;     // Byte offset 0x6bb, CSR Addr 0x5835d, Direction=InOut
    // VrefCS for rank 1 nibble 7 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib8;     // Byte offset 0x6bc, CSR Addr 0x5835e, Direction=InOut
    // VrefCS for rank 1 nibble 8 (only for setting, not trained).
    uint8_t  VrefCSR1Nib9;     // Byte offset 0x6bd, CSR Addr 0x5835e, Direction=InOut
    // VrefCS for rank 1 nibble 9 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib10;    // Byte offset 0x6be, CSR Addr 0x5835f, Direction=InOut
    // VrefCS for rank 1 nibble 10 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR1Nib11;    // Byte offset 0x6bf, CSR Addr 0x5835f, Direction=InOut
    // VrefCS for rank 1 nibble 11 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib12;    // Byte offset 0x6c0, CSR Addr 0x58360, Direction=InOut
    // VrefCS for rank 1 nibble 12 (only for setting, not trained).
    uint8_t  VrefCSR1Nib13;    // Byte offset 0x6c1, CSR Addr 0x58360, Direction=InOut
    // VrefCS for rank 1 nibble 13 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib14;    // Byte offset 0x6c2, CSR Addr 0x58361, Direction=InOut
    // VrefCS for rank 1 nibble 14 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR1Nib15;    // Byte offset 0x6c3, CSR Addr 0x58361, Direction=InOut
    // VrefCS for rank 1 nibble 15 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib16;    // Byte offset 0x6c4, CSR Addr 0x58362, Direction=InOut
    // VrefCS for rank 1 nibble 16 (only for setting, not trained).
    uint8_t  VrefCSR1Nib17;    // Byte offset 0x6c5, CSR Addr 0x58362, Direction=InOut
    // VrefCS for rank 1 nibble 17 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR1Nib18;    // Byte offset 0x6c6, CSR Addr 0x58363, Direction=InOut
    // VrefCS for rank 1 nibble 18 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR1Nib19;    // Byte offset 0x6c7, CSR Addr 0x58363, Direction=InOut
    // VrefCS for rank 1 nibble 19 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib0;     // Byte offset 0x6c8, CSR Addr 0x58364, Direction=InOut
    // VrefCS for rank 2 nibble 0 (only for setting, not trained).
    uint8_t  VrefCSR2Nib1;     // Byte offset 0x6c9, CSR Addr 0x58364, Direction=InOut
    // VrefCS for rank 2 nibble 1 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib2;     // Byte offset 0x6ca, CSR Addr 0x58365, Direction=InOut
    // VrefCS for rank 2 nibble 2 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR2Nib3;     // Byte offset 0x6cb, CSR Addr 0x58365, Direction=InOut
    // VrefCS for rank 2 nibble 3 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib4;     // Byte offset 0x6cc, CSR Addr 0x58366, Direction=InOut
    // VrefCS for rank 2 nibble 4 (only for setting, not trained).
    uint8_t  VrefCSR2Nib5;     // Byte offset 0x6cd, CSR Addr 0x58366, Direction=InOut
    // VrefCS for rank 2 nibble 5 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib6;     // Byte offset 0x6ce, CSR Addr 0x58367, Direction=InOut
    // VrefCS for rank 2 nibble 6 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR2Nib7;     // Byte offset 0x6cf, CSR Addr 0x58367, Direction=InOut
    // VrefCS for rank 2 nibble 7 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib8;     // Byte offset 0x6d0, CSR Addr 0x58368, Direction=InOut
    // VrefCS for rank 2 nibble 8 (only for setting, not trained).
    uint8_t  VrefCSR2Nib9;     // Byte offset 0x6d1, CSR Addr 0x58368, Direction=InOut
    // VrefCS for rank 2 nibble 9 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib10;    // Byte offset 0x6d2, CSR Addr 0x58369, Direction=InOut
    // VrefCS for rank 2 nibble 10 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR2Nib11;    // Byte offset 0x6d3, CSR Addr 0x58369, Direction=InOut
    // VrefCS for rank 2 nibble 11 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib12;    // Byte offset 0x6d4, CSR Addr 0x5836a, Direction=InOut
    // VrefCS for rank 2 nibble 12 (only for setting, not trained).
    uint8_t  VrefCSR2Nib13;    // Byte offset 0x6d5, CSR Addr 0x5836a, Direction=InOut
    // VrefCS for rank 2 nibble 13 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib14;    // Byte offset 0x6d6, CSR Addr 0x5836b, Direction=InOut
    // VrefCS for rank 2 nibble 14 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR2Nib15;    // Byte offset 0x6d7, CSR Addr 0x5836b, Direction=InOut
    // VrefCS for rank 2 nibble 15 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib16;    // Byte offset 0x6d8, CSR Addr 0x5836c, Direction=InOut
    // VrefCS for rank 2 nibble 16 (only for setting, not trained).
    uint8_t  VrefCSR2Nib17;    // Byte offset 0x6d9, CSR Addr 0x5836c, Direction=InOut
    // VrefCS for rank 2 nibble 17 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR2Nib18;    // Byte offset 0x6da, CSR Addr 0x5836d, Direction=InOut
    // VrefCS for rank 2 nibble 18 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR2Nib19;    // Byte offset 0x6db, CSR Addr 0x5836d, Direction=InOut
    // VrefCS for rank 2 nibble 19 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib0;     // Byte offset 0x6dc, CSR Addr 0x5836e, Direction=InOut
    // VrefCS for rank 3 nibble 0 (only for setting, not trained).
    uint8_t  VrefCSR3Nib1;     // Byte offset 0x6dd, CSR Addr 0x5836e, Direction=InOut
    // VrefCS for rank 3 nibble 1 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib2;     // Byte offset 0x6de, CSR Addr 0x5836f, Direction=InOut
    // VrefCS for rank 3 nibble 2 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR3Nib3;     // Byte offset 0x6df, CSR Addr 0x5836f, Direction=InOut
    // VrefCS for rank 3 nibble 3 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib4;     // Byte offset 0x6e0, CSR Addr 0x58370, Direction=InOut
    // VrefCS for rank 3 nibble 4 (only for setting, not trained).
    uint8_t  VrefCSR3Nib5;     // Byte offset 0x6e1, CSR Addr 0x58370, Direction=InOut
    // VrefCS for rank 3 nibble 5 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib6;     // Byte offset 0x6e2, CSR Addr 0x58371, Direction=InOut
    // VrefCS for rank 3 nibble 6 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR3Nib7;     // Byte offset 0x6e3, CSR Addr 0x58371, Direction=InOut
    // VrefCS for rank 3 nibble 7 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib8;     // Byte offset 0x6e4, CSR Addr 0x58372, Direction=InOut
    // VrefCS for rank 3 nibble 8 (only for setting, not trained).
    uint8_t  VrefCSR3Nib9;     // Byte offset 0x6e5, CSR Addr 0x58372, Direction=InOut
    // VrefCS for rank 3 nibble 9 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib10;    // Byte offset 0x6e6, CSR Addr 0x58373, Direction=InOut
    // VrefCS for rank 3 nibble 10 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR3Nib11;    // Byte offset 0x6e7, CSR Addr 0x58373, Direction=InOut
    // VrefCS for rank 3 nibble 11 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib12;    // Byte offset 0x6e8, CSR Addr 0x58374, Direction=InOut
    // VrefCS for rank 3 nibble 12 (only for setting, not trained).
    uint8_t  VrefCSR3Nib13;    // Byte offset 0x6e9, CSR Addr 0x58374, Direction=InOut
    // VrefCS for rank 3 nibble 13 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib14;    // Byte offset 0x6ea, CSR Addr 0x58375, Direction=InOut
    // VrefCS for rank 3 nibble 14 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR3Nib15;    // Byte offset 0x6eb, CSR Addr 0x58375, Direction=InOut
    // VrefCS for rank 3 nibble 15 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib16;    // Byte offset 0x6ec, CSR Addr 0x58376, Direction=InOut
    // VrefCS for rank 3 nibble 16 (only for setting, not trained).
    uint8_t  VrefCSR3Nib17;    // Byte offset 0x6ed, CSR Addr 0x58376, Direction=InOut
    // VrefCS for rank 3 nibble 17 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCSR3Nib18;    // Byte offset 0x6ee, CSR Addr 0x58377, Direction=InOut
    // VrefCS for rank 3 nibble 18 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCSR3Nib19;    // Byte offset 0x6ef, CSR Addr 0x58377, Direction=InOut
    // VrefCS for rank 3 nibble 19 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib0;     // Byte offset 0x6f0, CSR Addr 0x58378, Direction=InOut
    // VrefCA for rank 0 nibble 0 (only for setting, not trained).
    uint8_t  VrefCAR0Nib1;     // Byte offset 0x6f1, CSR Addr 0x58378, Direction=InOut
    // VrefCA for rank 0 nibble 1 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib2;     // Byte offset 0x6f2, CSR Addr 0x58379, Direction=InOut
    // VrefCA for rank 0 nibble 2 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR0Nib3;     // Byte offset 0x6f3, CSR Addr 0x58379, Direction=InOut
    // VrefCA for rank 0 nibble 3 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib4;     // Byte offset 0x6f4, CSR Addr 0x5837a, Direction=InOut
    // VrefCA for rank 0 nibble 4 (only for setting, not trained).
    uint8_t  VrefCAR0Nib5;     // Byte offset 0x6f5, CSR Addr 0x5837a, Direction=InOut
    // VrefCA for rank 0 nibble 5 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib6;     // Byte offset 0x6f6, CSR Addr 0x5837b, Direction=InOut
    // VrefCA for rank 0 nibble 6 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR0Nib7;     // Byte offset 0x6f7, CSR Addr 0x5837b, Direction=InOut
    // VrefCA for rank 0 nibble 7 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib8;     // Byte offset 0x6f8, CSR Addr 0x5837c, Direction=InOut
    // VrefCA for rank 0 nibble 8 (only for setting, not trained).
    uint8_t  VrefCAR0Nib9;     // Byte offset 0x6f9, CSR Addr 0x5837c, Direction=InOut
    // VrefCA for rank 0 nibble 9 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib10;    // Byte offset 0x6fa, CSR Addr 0x5837d, Direction=InOut
    // VrefCA for rank 0 nibble 10 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR0Nib11;    // Byte offset 0x6fb, CSR Addr 0x5837d, Direction=InOut
    // VrefCA for rank 0 nibble 11 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib12;    // Byte offset 0x6fc, CSR Addr 0x5837e, Direction=InOut
    // VrefCA for rank 0 nibble 12 (only for setting, not trained).
    uint8_t  VrefCAR0Nib13;    // Byte offset 0x6fd, CSR Addr 0x5837e, Direction=InOut
    // VrefCA for rank 0 nibble 13 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib14;    // Byte offset 0x6fe, CSR Addr 0x5837f, Direction=InOut
    // VrefCA for rank 0 nibble 14 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR0Nib15;    // Byte offset 0x6ff, CSR Addr 0x5837f, Direction=InOut
    // VrefCA for rank 0 nibble 15 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib16;    // Byte offset 0x700, CSR Addr 0x58380, Direction=InOut
    // VrefCA for rank 0 nibble 16 (only for setting, not trained).
    uint8_t  VrefCAR0Nib17;    // Byte offset 0x701, CSR Addr 0x58380, Direction=InOut
    // VrefCA for rank 0 nibble 17 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR0Nib18;    // Byte offset 0x702, CSR Addr 0x58381, Direction=InOut
    // VrefCA for rank 0 nibble 18 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR0Nib19;    // Byte offset 0x703, CSR Addr 0x58381, Direction=InOut
    // VrefCA for rank 0 nibble 19 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib0;     // Byte offset 0x704, CSR Addr 0x58382, Direction=InOut
    // VrefCA for rank 1 nibble 0 (only for setting, not trained).
    uint8_t  VrefCAR1Nib1;     // Byte offset 0x705, CSR Addr 0x58382, Direction=InOut
    // VrefCA for rank 1 nibble 1 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib2;     // Byte offset 0x706, CSR Addr 0x58383, Direction=InOut
    // VrefCA for rank 1 nibble 2 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR1Nib3;     // Byte offset 0x707, CSR Addr 0x58383, Direction=InOut
    // VrefCA for rank 1 nibble 3 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib4;     // Byte offset 0x708, CSR Addr 0x58384, Direction=InOut
    // VrefCA for rank 1 nibble 4 (only for setting, not trained).
    uint8_t  VrefCAR1Nib5;     // Byte offset 0x709, CSR Addr 0x58384, Direction=InOut
    // VrefCA for rank 1 nibble 5 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib6;     // Byte offset 0x70a, CSR Addr 0x58385, Direction=InOut
    // VrefCA for rank 1 nibble 6 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR1Nib7;     // Byte offset 0x70b, CSR Addr 0x58385, Direction=InOut
    // VrefCA for rank 1 nibble 7 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib8;     // Byte offset 0x70c, CSR Addr 0x58386, Direction=InOut
    // VrefCA for rank 1 nibble 8 (only for setting, not trained).
    uint8_t  VrefCAR1Nib9;     // Byte offset 0x70d, CSR Addr 0x58386, Direction=InOut
    // VrefCA for rank 1 nibble 9 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib10;    // Byte offset 0x70e, CSR Addr 0x58387, Direction=InOut
    // VrefCA for rank 1 nibble 10 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR1Nib11;    // Byte offset 0x70f, CSR Addr 0x58387, Direction=InOut
    // VrefCA for rank 1 nibble 11 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib12;    // Byte offset 0x710, CSR Addr 0x58388, Direction=InOut
    // VrefCA for rank 1 nibble 12 (only for setting, not trained).
    uint8_t  VrefCAR1Nib13;    // Byte offset 0x711, CSR Addr 0x58388, Direction=InOut
    // VrefCA for rank 1 nibble 13 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib14;    // Byte offset 0x712, CSR Addr 0x58389, Direction=InOut
    // VrefCA for rank 1 nibble 14 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR1Nib15;    // Byte offset 0x713, CSR Addr 0x58389, Direction=InOut
    // VrefCA for rank 1 nibble 15 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib16;    // Byte offset 0x714, CSR Addr 0x5838a, Direction=InOut
    // VrefCA for rank 1 nibble 16 (only for setting, not trained).
    uint8_t  VrefCAR1Nib17;    // Byte offset 0x715, CSR Addr 0x5838a, Direction=InOut
    // VrefCA for rank 1 nibble 17 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR1Nib18;    // Byte offset 0x716, CSR Addr 0x5838b, Direction=InOut
    // VrefCA for rank 1 nibble 18 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR1Nib19;    // Byte offset 0x717, CSR Addr 0x5838b, Direction=InOut
    // VrefCA for rank 1 nibble 19 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib0;     // Byte offset 0x718, CSR Addr 0x5838c, Direction=InOut
    // VrefCA for rank 2 nibble 0 (only for setting, not trained).
    uint8_t  VrefCAR2Nib1;     // Byte offset 0x719, CSR Addr 0x5838c, Direction=InOut
    // VrefCA for rank 2 nibble 1 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib2;     // Byte offset 0x71a, CSR Addr 0x5838d, Direction=InOut
    // VrefCA for rank 2 nibble 2 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR2Nib3;     // Byte offset 0x71b, CSR Addr 0x5838d, Direction=InOut
    // VrefCA for rank 2 nibble 3 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib4;     // Byte offset 0x71c, CSR Addr 0x5838e, Direction=InOut
    // VrefCA for rank 2 nibble 4 (only for setting, not trained).
    uint8_t  VrefCAR2Nib5;     // Byte offset 0x71d, CSR Addr 0x5838e, Direction=InOut
    // VrefCA for rank 2 nibble 5 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib6;     // Byte offset 0x71e, CSR Addr 0x5838f, Direction=InOut
    // VrefCA for rank 2 nibble 6 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR2Nib7;     // Byte offset 0x71f, CSR Addr 0x5838f, Direction=InOut
    // VrefCA for rank 2 nibble 7 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib8;     // Byte offset 0x720, CSR Addr 0x58390, Direction=InOut
    // VrefCA for rank 2 nibble 8 (only for setting, not trained).
    uint8_t  VrefCAR2Nib9;     // Byte offset 0x721, CSR Addr 0x58390, Direction=InOut
    // VrefCA for rank 2 nibble 9 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib10;    // Byte offset 0x722, CSR Addr 0x58391, Direction=InOut
    // VrefCA for rank 2 nibble 10 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR2Nib11;    // Byte offset 0x723, CSR Addr 0x58391, Direction=InOut
    // VrefCA for rank 2 nibble 11 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib12;    // Byte offset 0x724, CSR Addr 0x58392, Direction=InOut
    // VrefCA for rank 2 nibble 12 (only for setting, not trained).
    uint8_t  VrefCAR2Nib13;    // Byte offset 0x725, CSR Addr 0x58392, Direction=InOut
    // VrefCA for rank 2 nibble 13 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib14;    // Byte offset 0x726, CSR Addr 0x58393, Direction=InOut
    // VrefCA for rank 2 nibble 14 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR2Nib15;    // Byte offset 0x727, CSR Addr 0x58393, Direction=InOut
    // VrefCA for rank 2 nibble 15 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib16;    // Byte offset 0x728, CSR Addr 0x58394, Direction=InOut
    // VrefCA for rank 2 nibble 16 (only for setting, not trained).
    uint8_t  VrefCAR2Nib17;    // Byte offset 0x729, CSR Addr 0x58394, Direction=InOut
    // VrefCA for rank 2 nibble 17 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR2Nib18;    // Byte offset 0x72a, CSR Addr 0x58395, Direction=InOut
    // VrefCA for rank 2 nibble 18 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR2Nib19;    // Byte offset 0x72b, CSR Addr 0x58395, Direction=InOut
    // VrefCA for rank 2 nibble 19 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib0;     // Byte offset 0x72c, CSR Addr 0x58396, Direction=InOut
    // VrefCA for rank 3 nibble 0 (only for setting, not trained).
    uint8_t  VrefCAR3Nib1;     // Byte offset 0x72d, CSR Addr 0x58396, Direction=InOut
    // VrefCA for rank 3 nibble 1 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib2;     // Byte offset 0x72e, CSR Addr 0x58397, Direction=InOut
    // VrefCA for rank 3 nibble 2 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR3Nib3;     // Byte offset 0x72f, CSR Addr 0x58397, Direction=InOut
    // VrefCA for rank 3 nibble 3 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib4;     // Byte offset 0x730, CSR Addr 0x58398, Direction=InOut
    // VrefCA for rank 3 nibble 4 (only for setting, not trained).
    uint8_t  VrefCAR3Nib5;     // Byte offset 0x731, CSR Addr 0x58398, Direction=InOut
    // VrefCA for rank 3 nibble 5 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib6;     // Byte offset 0x732, CSR Addr 0x58399, Direction=InOut
    // VrefCA for rank 3 nibble 6 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR3Nib7;     // Byte offset 0x733, CSR Addr 0x58399, Direction=InOut
    // VrefCA for rank 3 nibble 7 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib8;     // Byte offset 0x734, CSR Addr 0x5839a, Direction=InOut
    // VrefCA for rank 3 nibble 8 (only for setting, not trained).
    uint8_t  VrefCAR3Nib9;     // Byte offset 0x735, CSR Addr 0x5839a, Direction=InOut
    // VrefCA for rank 3 nibble 9 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib10;    // Byte offset 0x736, CSR Addr 0x5839b, Direction=InOut
    // VrefCA for rank 3 nibble 10 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR3Nib11;    // Byte offset 0x737, CSR Addr 0x5839b, Direction=InOut
    // VrefCA for rank 3 nibble 11 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib12;    // Byte offset 0x738, CSR Addr 0x5839c, Direction=InOut
    // VrefCA for rank 3 nibble 12 (only for setting, not trained).
    uint8_t  VrefCAR3Nib13;    // Byte offset 0x739, CSR Addr 0x5839c, Direction=InOut
    // VrefCA for rank 3 nibble 13 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib14;    // Byte offset 0x73a, CSR Addr 0x5839d, Direction=InOut
    // VrefCA for rank 3 nibble 14 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR3Nib15;    // Byte offset 0x73b, CSR Addr 0x5839d, Direction=InOut
    // VrefCA for rank 3 nibble 15 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib16;    // Byte offset 0x73c, CSR Addr 0x5839e, Direction=InOut
    // VrefCA for rank 3 nibble 16 (only for setting, not trained).
    uint8_t  VrefCAR3Nib17;    // Byte offset 0x73d, CSR Addr 0x5839e, Direction=InOut
    // VrefCA for rank 3 nibble 17 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  VrefCAR3Nib18;    // Byte offset 0x73e, CSR Addr 0x5839f, Direction=InOut
    // VrefCA for rank 3 nibble 18 (only for setting, not trained). Do not care for x16 device.
    uint8_t  VrefCAR3Nib19;    // Byte offset 0x73f, CSR Addr 0x5839f, Direction=InOut
    // VrefCA for rank 3 nibble 19 (only for setting, not trained). Do not care for x8 or x16 devices.
    uint8_t  DisabledDB0LaneR0; // Byte offset 0x740, CSR Addr 0x583a0, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 0 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB1LaneR0; // Byte offset 0x741, CSR Addr 0x583a0, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 1 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB2LaneR0; // Byte offset 0x742, CSR Addr 0x583a1, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 2 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB3LaneR0; // Byte offset 0x743, CSR Addr 0x583a1, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 3 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB4LaneR0; // Byte offset 0x744, CSR Addr 0x583a2, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 4 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB5LaneR0; // Byte offset 0x745, CSR Addr 0x583a2, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 5 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB6LaneR0; // Byte offset 0x746, CSR Addr 0x583a3, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 6 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB7LaneR0; // Byte offset 0x747, CSR Addr 0x583a3, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 7 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB8LaneR0; // Byte offset 0x748, CSR Addr 0x583a4, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 8 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB9LaneR0; // Byte offset 0x749, CSR Addr 0x583a4, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 9 are not connected on rank 0 (for DQ 0 to 7)
    uint8_t  DisabledDB0LaneR1; // Byte offset 0x74a, CSR Addr 0x583a5, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 0 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB1LaneR1; // Byte offset 0x74b, CSR Addr 0x583a5, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 1 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB2LaneR1; // Byte offset 0x74c, CSR Addr 0x583a6, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 2 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB3LaneR1; // Byte offset 0x74d, CSR Addr 0x583a6, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 3 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB4LaneR1; // Byte offset 0x74e, CSR Addr 0x583a7, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 4 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB5LaneR1; // Byte offset 0x74f, CSR Addr 0x583a7, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 5 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB6LaneR1; // Byte offset 0x750, CSR Addr 0x583a8, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 6 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB7LaneR1; // Byte offset 0x751, CSR Addr 0x583a8, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 7 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB8LaneR1; // Byte offset 0x752, CSR Addr 0x583a9, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 8 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB9LaneR1; // Byte offset 0x753, CSR Addr 0x583a9, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 9 are not connected on rank 1 (for DQ 0 to 7)
    uint8_t  DisabledDB0LaneR2; // Byte offset 0x754, CSR Addr 0x583aa, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 0 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB1LaneR2; // Byte offset 0x755, CSR Addr 0x583aa, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 1 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB2LaneR2; // Byte offset 0x756, CSR Addr 0x583ab, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 2 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB3LaneR2; // Byte offset 0x757, CSR Addr 0x583ab, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 3 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB4LaneR2; // Byte offset 0x758, CSR Addr 0x583ac, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 4 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB5LaneR2; // Byte offset 0x759, CSR Addr 0x583ac, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 5 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB6LaneR2; // Byte offset 0x75a, CSR Addr 0x583ad, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 6 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB7LaneR2; // Byte offset 0x75b, CSR Addr 0x583ad, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 7 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB8LaneR2; // Byte offset 0x75c, CSR Addr 0x583ae, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 8 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB9LaneR2; // Byte offset 0x75d, CSR Addr 0x583ae, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 9 are not connected on rank 2 (for DQ 0 to 7)
    uint8_t  DisabledDB0LaneR3; // Byte offset 0x75e, CSR Addr 0x583af, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 0 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB1LaneR3; // Byte offset 0x75f, CSR Addr 0x583af, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 1 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB2LaneR3; // Byte offset 0x760, CSR Addr 0x583b0, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 2 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB3LaneR3; // Byte offset 0x761, CSR Addr 0x583b0, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 3 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB4LaneR3; // Byte offset 0x762, CSR Addr 0x583b1, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 4 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB5LaneR3; // Byte offset 0x763, CSR Addr 0x583b1, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 5 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB6LaneR3; // Byte offset 0x764, CSR Addr 0x583b2, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 6 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB7LaneR3; // Byte offset 0x765, CSR Addr 0x583b2, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 7 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB8LaneR3; // Byte offset 0x766, CSR Addr 0x583b3, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 8 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  DisabledDB9LaneR3; // Byte offset 0x767, CSR Addr 0x583b3, Direction=InOut
    // Bitmap to indicate which DQ lane of Dbytes 9 are not connected on rank 3 (for DQ 0 to 7)
    uint8_t  QCS_Dly_Margin_A0; // Byte offset 0x768, CSR Addr 0x583b4, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CS channel A, rank 0 (both sides)
    uint8_t  QCA_Dly_Margin_A0; // Byte offset 0x769, CSR Addr 0x583b4, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CA channel A, rank 0 (both sides)
    uint8_t  QCS_Dly_Margin_A1; // Byte offset 0x76a, CSR Addr 0x583b5, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CS channel A, rank 1 (both sides)
    uint8_t  QCA_Dly_Margin_A1; // Byte offset 0x76b, CSR Addr 0x583b5, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CA channel A, rank 1 (both sides)
    uint8_t  QCS_Dly_Margin_A2; // Byte offset 0x76c, CSR Addr 0x583b6, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CS channel A, rank 2 (both sides)
    uint8_t  QCA_Dly_Margin_A2; // Byte offset 0x76d, CSR Addr 0x583b6, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CA channel A, rank 2 (both sides)
    uint8_t  QCS_Dly_Margin_A3; // Byte offset 0x76e, CSR Addr 0x583b7, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CS channel A, rank 3 (both sides)
    uint8_t  QCA_Dly_Margin_A3; // Byte offset 0x76f, CSR Addr 0x583b7, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CA channel A, rank 3 (both sides)
    uint8_t  QCS_Dly_Margin_B0; // Byte offset 0x770, CSR Addr 0x583b8, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CS channel B, rank 0 (both sides)
    uint8_t  QCA_Dly_Margin_B0; // Byte offset 0x771, CSR Addr 0x583b8, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CA channel B, rank 0 (both sides)
    uint8_t  QCS_Dly_Margin_B1; // Byte offset 0x772, CSR Addr 0x583b9, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CS channel B, rank 1 (both sides)
    uint8_t  QCA_Dly_Margin_B1; // Byte offset 0x773, CSR Addr 0x583b9, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CA channel B, rank 1 (both sides)
    uint8_t  QCS_Dly_Margin_B2; // Byte offset 0x774, CSR Addr 0x583ba, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CS channel B, rank 2 (both sides)
    uint8_t  QCA_Dly_Margin_B2; // Byte offset 0x775, CSR Addr 0x583ba, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CA channel B, rank 2 (both sides)
    uint8_t  QCS_Dly_Margin_B3; // Byte offset 0x776, CSR Addr 0x583bb, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CS channel B, rank 3 (both sides)
    uint8_t  QCA_Dly_Margin_B3; // Byte offset 0x777, CSR Addr 0x583bb, Direction=Out
    // Distance from the trained center to the closest failing region in 1/64 tCK steps, for CA channel B, rank 3 (both sides)
    uint16_t PmuInternalRev0;  // Byte offset 0x778, CSR Addr 0x583bc, Direction=Out
    // PMU firmware internal revision ID 0
    // After training is run, this address will contain the internal revision ID 0 of the firmware.
    uint16_t PmuInternalRev1;  // Byte offset 0x77a, CSR Addr 0x583bd, Direction=Out
    // PMU firmware internal revision ID 1
    // After training is run, this address will contain the internal revision ID 1 of the firmware.
} __attribute__ ((packed)) PMU_SMB_DDR5U_1D_t;
#endif
