/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_ddrphy_phyinit_structs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
/* [+] International Business Machines Corp.                              */
/* [+] Synopsys, Inc.                                                     */
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

// Note: Synopsys, Inc. owns the original copyright of the code
// This file is ported into IBM's code stream with the permission of Synopsys, Inc.

// EKB-Mirror-To: hostboot
///
/// @file ody_ddrphy_phyinit_structs.H
/// @brief Odyssey PHY init procedure structures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _ODY_DDRPHY_PHYINIT_STRUCTS_H_
#define _ODY_DDRPHY_PHYINIT_STRUCTS_H_


//
// Structure for basic (mandatory) user inputs
//
typedef enum DramTypes
{
    DDR4,
    DDR5
} DramType_t;

typedef enum DimmTypes
{
    UDIMM,
    SODIMM,
    RDIMM,
    LRDIMM,
    NODIMM,
    NVDIMMP
} DimmType_t;


typedef struct user_input_basic
{


// === Global variables  === //
    int ARdPtrInitVal[4];       // making this a userInput variable so that it can be overriden if the ARdPtrInitValOvr is 1;
    //ARdPtrInitVal[pstate];
    int ARdPtrInitValOvr;   // set this to 1 if the ARdPtrInitVal should be overriden via userInput.  else,
    // dwc_ddrphy_phyinit_C_initPhyConfig.c will program based on frequency values on a range of 0-3

    //
    // @brief DDR protocol specification
    // - Choose the DDR protocol
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | DDR4
    //       4 | DDR5
    // - Default: 4
    //
    DramType_t DramType;


    //
    // @brief Disables PtrInit from clearing the TxTrkState csr during skip retrain.
    // - Default: 0
    //   Value | Description
    //       0 | It will not effect the TxTrkState
    //       1 | clears the TxTrkState csr
    //
    //   DisPtrInitClrTxTracking[pstate];
    //
    int DisPtrInitClrTxTracking[4];

    //
    // @brief DIMM type specification
    // - Choose the DIMM type
    // - Values:
    //   Value | Description
    //   ----- | -----
    //     0x0 | UDIMM
    //     0x1 | SODIMM
    //     0x2 | RDIMM
    //     0x3 | LRDIMM (DDR4 only)
    //     0x4 | No DIMM (Soldered-on)
    // - Default: 0x0
    //
    DimmType_t DimmType;

    //
    // @brief Number of DBYTE Instances
    // - Number of DBYTE instances
    // - Values: 2, 4, 5, 8, 9, 10
    // - Default: 4
    //
    int NumDbyte;

    //
    // @brief Number of active DBYTEs to be controlled by DFI0
    // - Number of active DBYTEs to be controlled by DFI0.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       2 | 2 (16 DQ bits)
    //       4 | 4 (32 DQ bits)
    //       5 | 5 (40 DQ bits)
    //       8 | 8 (64 DQ bits)
    //       9 | 9 (72 DQ bits)
    //      10 | 10 (80 DQ bits)
    // - Default: 4
    //
    int NumActiveDbyteDfi0;

    //
    // @brief Number of active DBYTEs to be controlled by DFI1 (DDR5 only)
    // - Number of active DBYTEs to be controlled by DFI1
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | 0
    //       2 | 2 (16 DQ bits)
    //       4 | 4 (32 DQ bits)
    //       5 | 5 (40 DQ bits)
    // - Default: 0
    //
    int NumActiveDbyteDfi1;

    //
    // @brief Number of ANIB(ACX4) Instances
    // - Number of ANIB(ACX4) instances
    // - Values: 6, 10, 12, 14
    // - Default: 6
    //
    int NumAnib;

    //
    // @brief Number of physical ranks to be controlled by DFI0
    // - Corresponds to the number of independently-addressable logical memory arrays to be controlled by DFI0 in your system.
    // - Values: 1, 2, 3, 4
    // - Default: 1
    //
    int NumRank_dfi0;

    //
    // @brief Number of physical ranks to be controlled by DFI1 (DDR5 only)
    // - Corresponds to the number of independently-addressable logical memory arrays to be controlled by DFI1 in your system.
    // - Values: 0, 1, 2, 3, 4
    // - Default: 0
    //
    int NumRank_dfi1;

    //
    // @brief DRAM chip data bus width
    // - The DRAM chip data bus width per TG depending on the protocol and DRAM type. The x8,x16 options are not available for LRDIMM systems.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       4 | x4
    //       8 | x8 (not available for LRDIMM)
    //      16 | x16 (not available for LRDIMM)
    // - Default: 8
    //  DramDataWidth[tg]
    //
    int DramDataWidth[4];

    //
    // @brief Number of p-states used
    // - Number of p-states used
    // - Values: 1, 2, 3, 4
    // - Default: 1
    //
    int NumPStates;

    //
    // @brief Memclk frequency
    // - Memclk frequency in MHz -- round up to next highest integer.  Enter 334 for 333.333, etc.
    // - Values:
    //   - Min: 25
    //   - Max: 2600
    // - Default: 800
    //
    //  Frequency[pstate]
    //
    int Frequency[4];

    //
    // @brief Enable PLL Bypass
    // - Enable PLL Bypass
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | Disable
    //       1 | Enable
    // - Default: 0
    //
    //  PllBypass[pstate]
    //
    int PllBypass[4];

    //
    // @brief Memory controller to PHY frequency ratio at the DFI interface
    // - Indicate memory controller to PHY clock frequency ratio to facilitate serialization/deserialization of DFI interface signals.
    // - Refer to the discussion on the internal "DfiCtlClk" clock in the PHY Utility Block (PUB) Databook for information regarding frequency relationships corresponding to this ratio setting.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       1 | 1:2
    //       2 | 1:4
    // - Default: 1
    //
    //  DfiFreqRatio[pstate]
    //
    int DfiFreqRatio[4];

    //
    // @brief Indicates whether they PHY config has Dfi1 channel
    // - Indicates whether they PHY config has Dfi1 channel
    // - Values: 0, 1
    // - Default: 0
    //
    int Dfi1Exists;


} user_input_basic_t;


//#############################################################################
//
// Structure for advanced (optional) user inputs
// - if user does not enter a value for these parameters, a PHY recommended or
//   default value will be used
//
//#############################################################################
typedef struct user_input_advanced
{

    //
    // @brief Control the length of DDR4 read DQS preamble (DDR4 only)
    // - Widen (from 1tCK to 2tCK) the RxDqsEn preamble to allow for larger DRAM timing drift.
    // - WARNING: the user should ensure that the controller is correspondingly configured (as cycle-to-cycle time can be affected).
    // - This is equivalent to DDR4 MR4-OP[11]
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | 1 tCK
    //       1 | 2 tCK (MEMCLK >= 1200MHz)
    // - Default: 0
    //
    //  D4RxPreambleLength[pstate]
    //
    int D4RxPreambleLength[4];

    //
    // @brief Control the length of DDR4 write DQS preamble (DDR4 only)
    // - Widen (from 1tCK to 2tCK) the TxDqs preamble to allow for larger DRAM timing drift.
    // - WARNING: the user should ensure that the controller is correspondingly configured (as cycle-to-cycle time can be affected).
    // - This is equivalent to DDR4 MR4-OP[12]
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | 1 tCK
    //       1 | 2 tCK (MEMCLK >= 1200MHz)
    // - Default: 0
    //
    //  D4TxPreambleLength[pstate]
    //
    int D4TxPreambleLength[4];

    //
    // @brief External PHY impedance calibration pull-down resistor value (in ohms)
    // - Indicates value of impedance calibration pull-down resistor connected to BP_ZN pin of the PHY.
    // - Refer to the section titled "Impedance Calibrator" in the PHY Utility Block (PUB) Databook for more information.
    // - Values: 40, 120, 240
    // - Default: 240
    //
    int ExtCalResVal;


    //
    // @brief On-die termination (ODT) impedance (in ohms)
    // - Specify the appropriate on-die termination resistance (in ohms) to minimize distortion and improve signal integrity.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | High-impedance
    //      40 | 40
    //      60 | 60
    //      80 | 80
    //     120 | 120
    //     240 | 240
    // - Default: 240
    //
    //  ODTImpedance[pstate]
    //
    int ODTImpedance[4];

    //
    // @brief Address TX impedance controls
    // - Specify Tx impedance of Address driver cells, for pstate P0
    // - Refer to the description on the ATxImpedance CSR, the section titled "ATxImpedance" in the PHY Utility Block (PUB) Databook for more information.
    // - Default: 0xcfff
    //
    int ATxImpedance;

    //
    // @brief DQ/DQS Tx drive impedance (in ohms)
    // - Specify the Tx DQ driver impedance when equalization is enabled per nibble, per pstate.
    // - Refer to the description on the TxImpedanceCtrl0 CSR, the section titled "TxImpedanceCtrl0" in the PHY Utility Block (PUB) Databook for more information.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | High-impedance
    //      40 | 40
    //      60 | 60
    //      80 | 80
    //     120 | 120
    //     240 | 240
    // - Default:
    //    PUB 1.x, 3.x = 25 ohms
    //    PUB 2.x, 4.x = 34 ohms
    //
    //  TxImpedance[pstate]
    //
    int TxImpedance[4];

    //
    // @brief DQ/DQS Tx drive impedance (in ohms)
    // - Specify the Tx impedance of DQ driver cells when equalization is disabled, per pstate
    // - Refer to the description on the TxImpedanceCtrl1 CSR, the section titled "TxImpedanceCtrl1" in the PHY Utility Block (PUB) Databook for more information.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | High-impedance
    //      40 | 40
    //      60 | 60
    //      80 | 80
    //     120 | 120
    //     240 | 240
    // - Default:
    //    PUB 1.x, 3.x = 25 ohms
    //    PUB 2.x, 4.x = 34 ohms
    //
    //  TxImpedanceCtrl1[pstate]
    //
    int TxImpedanceCtrl1[4];

    //
    // @brief TX equalization impedance controls
    // - Specify the Tx DQ driver opposition impedance when equalization is enabled, per pstate.
    // - Refer to the description on the TxImpedanceCtrl2 CSR, the section titled "TxImpedanceCtrl2" in the PHY Utility Block (PUB) Databook for more information.
    // - Default:
    //    PUB 1.x, 3.x = 0x000
    //    PUB 2.x, 4.x = 0x820
    //
    //  TxImpedanceCtrl2[pstate]
    //
    int TxImpedanceCtrl2[4];

    //
    // @brief The ERR/ALERT signal provided by the DRAM will be
    // - Indicate how the ERR/ALERT signal (which communicates feedback such as an address/command parity error) should be accommodated.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | unused
    //       1 | used
    // - Default: 0
    //
    int MemAlertEn;

    //
    // @brief Pull-up Termination Impedance for MALERT_N pin
    // - Specify the Pull-up Termination Impedance for MemAlert pin
    // - Values: 40, 60, 80, 120, 240
    // - Default: 240
    //
    int MtestPUImp;

    //
    // @brief Disable dynamic tri-stating of the address/command bus signals between transactions (DDR4 only)
    // - In DDR4 mode, the PHY can dynamically and transparently tristate the address/command bus on a per-MEMCLK basis to save power anytime the outgoing command is a DESELECT. This saves significant termination power at the system level, as the Address/Command bus is terminated to VDDQ/2 in DDR4 systems.
    // - In DDR4 (1T address/command timing), this feature works transparently, the PHY tristates A*,BA*,BG*,RAS_n,CAS_n,WE_n anytime all ranks are deselected.
    // - In DDR4 (2T address/command timing), this feature requires extra support from the controller, see the register TristateModeCA and "2T Timing, Geardown, 2N Mode, and RDIMM SDR Support" on for more information.
    // - In DDR5 Mode, Dynamic Address Tristating must be disabled. This feature is not useful in DDR5, as the Command Address bus is terminated to VDDQ.
    // - Values: 0, 1
    // - Default: 0
    //
    //  DisDynAdrTri[pstate]
    //
    int DisDynAdrTri[4];

    //
    // @brief Time between the end of one training and the start of the next
    // - it is the max expected time from dfi_init_complete asserted to tdfi_phymstr_ack asserted
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | Disable Phy Master Interface
    //       1 | 524288 MEMCLKs
    //       2 | 1048576 MEMCLKs
    //       3 | 2097152 MEMCLKs
    //       4 | 4194304 MEMCLKs
    //       5 | 8388608 MEMCLKs
    //       6 | 16777216 MEMCLKs
    //       7 | 33554432 MEMCLKs
    //       8 | 67108864 MEMCLKs
    //       9 | 134217728 MEMCLKs
    //      10 | 268435456 MEMCLKs
    //      14 | 8192 MEMCLKs
    // - Default: 0
    //
    //  PhyMstrTrainInterval[pstate]
    //
    int PhyMstrTrainInterval[4];

    //
    // @brief Max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted
    // - Specifies the max time from tdfi_phymstr_req asserted to tdfi_phymstr_ack asserted
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | Disable Phy Master Interface
    //       1 | 512 MEMCLKs
    //       2 | 1024 MEMCLKs
    //       3 | 2048 MEMCLKs
    //       4 | 4096 MEMCLKs
    //       5 | 8192 MEMCLKs
    // - Default: 0
    //
    //  PhyMstrMaxReqToAck[pstate]
    //
    int PhyMstrMaxReqToAck[4];

    //
    // @brief Phy Master Control Mode
    // - 1 : a PHY Master transaction is initiated only by a dfi_ctrlmsg transaction
    // - 0 : a PHY Master transaction is initiated only by timer function
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | PHY Master transaction initiated by timer function
    //       1 | PHY Master transaction initiated by dfi_ctrlmsg transaction
    // - Default: 0
    //
    //  PhyMstrCtrlMode[pstate]
    //
    int PhyMstrCtrlMode[4];

    //
    // @brief Enable Write DQS Extension
    // Not applicable for DDR5 and DDR4
    // - Values: 0, 1
    // - Default: 0
    //
    int WDQSExt;

    //
    // @brief The interval between successive PHY impedance calibrations
    // - Continuous PHY impedance calibration will be performed - select the applicable interval between consecutive PHY impedance calibrations.
    // - Refer to the section titled "Impedance Calibration Engine Setup" in the PHY Utility Block (PUB) Databook for more information.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | continuous
    //       1 | 0.01 ms (13 us)
    //       2 | 0.10 ms
    //       3 | 1 ms
    //       4 | 2 ms
    //       5 | 3 ms
    //       6 | 4 ms
    //       7 | 8 ms
    //       8 | 10 ms
    //       9 | 20 ms
    // - Default: 9
    //
    int CalInterval;

    //
    // @brief The behaviour of CSR CalRun
    // - This field should only be changed while the calibrator is idle.
    // - ie. before csr CalRun is set.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | Calibration will proceed at the rate determined by CSRCalInterval
    //       1 | The 0->1 transition of CSR CalRun causes a single iteration of the calibration sequence to occur
    // - Default: 0
    //
    int CalOnce;

    //
    // @brief Swap PHY Byte to DRAM Byte connections
    // - required only for x16, DramByteSwap[I] must be set if Dbyte 2*I and Dbyte 2*I + 1 are swapped at the DRAM device
    // - PHY DBYTE 0 and 1 are partners, 2 and 3 are partners,4 and 5 are partners, 6 and 7 are partners.
    // - Other DBYTE pairings are not supported.
    // - This is per timing group.
    // - Values:
    //   - Min: 0
    //   - Max: 0xff
    // - Default: 0
    //
    //  DramByteSwap[tg]
    //
    int DramByteSwap[4];

    //
    // @brief The number of UI to be subtracted from the delay position of the RxEnDly-trained
    // - dqs edge to position the RxEnDly in the middle of the preamble.
    // - Not applicable for DDR5 and DDR4.
    // - Values: 1, 2
    // - Default: 1
    //
    int RxEnBackOff;

    //
    // @brief Firmware Training Sequence Control
    // - This input can be set to control which stages of training firmware will execute.
    // - Unless specifically requested, please leave at default value. Refer to Training App Note
    //   and the message block definition for SequenceCtrl for programing when required.
    // - Values: (TODO)
    // - Default: (TODO)
    //
    int TrainSequenceCtrl;

    //
    // @brief Enable Optimizations specific to Synopsys UMCTL2
    // - Enable Optimizations specific to Synopsys UMCTL2
    // - Values: 0, 1
    // - Default: 0
    //
    int SnpsUmctlOpt;

    //
    // @brief F0RC5x When using Snopsys UMCTL2 and DDR4 RDIMM
    // - F0RC5x When using Snopsys UMCTL2 and DDR4 RDIMM
    // - Values:
    //   - Min: 0
    //   - Max: 0xff
    // - Default: 0
    //
    //  SnpsUmctlF0RC5x[pstate]
    //
    int SnpsUmctlF0RC5x[4];

    //
    // @brief Pull-up slew rate control for DBYTE transmitter
    // - Value specified here will be applied directly to TxSlewRate::CsrTxSrc
    // - Please consult the "Calibration Codes" section of HSpice Model App Note in specific technology for recommended settings.
    //   Protocol specific values are provided under the DWC_TXRXDQ/rise_index column.
    // - Values:
    //   - Min: 0
    //   - Max: 255
    // - Default: 0
    //
    //  TxSlewRiseDQ[pstate]
    //
    int TxSlewRiseDQ[4];

    //
    // @brief Pull-down slew rate control for DBYTE transmitter
    // - Value specified here will be applied directly to TxSlewRate::TxPreN
    // - Please consult the "Calibration Codes" section of HSpice Model App Note in specific technology for recommended settings.
    //   Protocol specific values are provided under the DWC_TXRXDQ/fall_index column.
    // - WARNING: Vaule of this parameter is don't care if Pull-up slew rate control for DBYTE transmitter is set to 0. Refer to TxSlewRate descriptions in "Register Descriptions" of PHY Utility Block (PUB) Databook for more information.
    // - Values:
    //   - Min: 0
    //   - Max: 255
    // - Default: 0
    //
    //  TxSlewFallDQ[pstate]
    //
    int TxSlewFallDQ[4];

    //
    // @brief Pull-up slew rate control for ANIB(ACX4) transmitter
    // - Value specified here will be applied directly to ATxSlewRate::CsrATxSrc
    // - Please consult the "Calibration Codes" section of HSpice Model App Note in specific technology for recommended settings.
    //   Protocol specific values are provided under the DWC_TXRXCA/rise_index column.
    // - Values:
    //   - Min: 0
    //   - Max: 255
    // - Default: 0x66
    //
    int TxSlewRiseAC;

    //
    // @brief Pull-down slew rate control for ANIB(ACX4) transmitter
    // - Value specified here will be applied directly to ATxSlewRate::ATxPreN
    // - Please consult the "Calibration Codes" section of HSpice Model App Note in specific technology for recommended settings.
    //   Protocol specific values are provided under the DWC_TXRXCA/fall_index column.
    // - WARNING: Vaule of this parameter is don't care if Pull-up slew rate control for ANIB(ACX4) transmitter is set to 0. Refer to ATxSlewRate descriptions in "Register Descriptions" of PHY Utility Block (PUB) Databook for more information.
    // - Values:
    //   - Min: 0
    //   - Max: 255
    // - Default: 0x26
    //
    int TxSlewFallAC;


    //
    // @brief High VDD
    // - When VDD=0.9V nominal, set this to 1'b1, otherwise set to 1'b0.
    // - This input is used to program TxSlewRate[8] and ATxSlewRate[9].
    // - Values: 0, 1
    // - Default: 1
    //
    int IsHighVDD;

    //
    // @brief Pull-up slew rate control for CK
    // - Controls CalPreDriverOverride::CsrTxOvSrc High voltage
    // - Values:
    //   - Min: 0
    //   - Max: 255
    // - Default: 0x0
    //
    int TxSlewRiseCK;

    //
    // @brief Pull-down slew rate control for CK
    // - Controls CalPreDriverOverride::CsrTxOvSrc Low voltage
    // - Values:
    //   - Min: 0
    //   - Max: 255
    // - Default: 0x0
    //
    int TxSlewFallCK;

    //
    // @brief Selects the Lane within an ANIB to be used for NVDIMM receive for Channel-X
    // - Selects the Lane within an ANIB to be used for NVDIMM receive for Channel-X
    //  [X] - selection for Channel-X
    // - Values: (TODO)
    // - Default: 0x0
    //
    //  NvAnibRcvSel[num_nvdimmp_chan]
    //
    int NvAnibRcvSel[8];

    //
    // @brief Selects the Lane within an ANIB to be used for NVDIMM receive for Channel-X
    // - Selects the Lane within an ANIB to be used for NVDIMM receive for Channel-X
    //   [X] - selection for Channel-X
    // - Values: (TODO)
    // - Default: 0x0
    //
    //  AnibRcvLaneSel[num_nvdimmp_chan]
    //
    int AnibRcvLaneSel[8];

    //
    // @brief Enables NVDIMM receiver for Channel-X
    // - Enables NVDIMM receiver for Channel-X
    //   [X] - selection for Channel-X
    // - Values: 0, 1
    // - Default: 0x0
    //
    //  AnibRcvEn[num_nvdimmp_chan]
    //
    int AnibRcvEn[8];


    //
    // @brief Enable tracking of tDQS2DQ for timing group 0
    // - under control of PIE initiated tracking or DFI initiated reads tagged with assertion of dwc_ddrphy_snoop_en.
    // - Refer to section titled "Tracking of DDR5 DRAM Write-DQS Drift" in the PHY Utility Block (PUB) Databook for more information.
    // - Values: 0, 1
    // - Default: 1
    //
    //  EnTdqs2dqTrackingTg0[pstate]
    //
    int EnTdqs2dqTrackingTg0[4];

    //
    // @brief Enable tracking of tDQS2DQ for timing group 1
    // - under control of PIE initiated tracking or DFI initiated reads tagged with assertion of dwc_ddrphy_snoop_en.
    // - Refer to section titled "Tracking of DDR5 DRAM Write-DQS Drift" in the PHY Utility Block (PUB) Databook for more information.
    // - Values: 0, 1
    // - Default: 1
    //
    //  EnTdqs2dqTrackingTg1[pstate]
    //
    int EnTdqs2dqTrackingTg1[4];

    //
    // @brief Enable tracking of tDQS2DQ for timing group 2
    // - under control of PIE initiated tracking or DFI initiated reads tagged with assertion of dwc_ddrphy_snoop_en.
    // - Refer to section titled "Tracking of DDR5 DRAM Write-DQS Drift" in the PHY Utility Block (PUB) Databook for more information.
    // - Values: 0, 1
    // - Default: 1
    //
    //  EnTdqs2dqTrackingTg2[pstate]
    //
    int EnTdqs2dqTrackingTg2[4];

    //
    // @brief Enable tracking of tDQS2DQ for timing group 3
    // - under control of PIE initiated tracking or DFI initiated reads tagged with assertion of dwc_ddrphy_snoop_en.
    // - Refer to section titled "Tracking of DDR5 DRAM Write-DQS Drift" in the PHY Utility Block (PUB) Databook for more information.
    // - Values: 0, 1
    // - Default: 1
    //
    //  EnTdqs2dqTrackingTg3[pstate]
    //
    int EnTdqs2dqTrackingTg3[4];

    //
    // @brief DQS oscillator interval timer (in MEMCLK)
    // - Must match the value programmed to the MR for DQS oscillator interval timer
    // - Unit is in number of MEMECLK
    // - Values: 256, 512, 1024, 2048, 4096, 8192
    // - Default: 256
    //
    //  DqsOscRunTimeSel[pstate]
    //
    int DqsOscRunTimeSel[4];


    //
    // @brief Enable tracking of the incoming read DQS to modify the read gate timing
    // - Enable tracking of the incoming read DQS to modify the read gate timing
    // - Values: 0, 1
    // - Default: 1
    //
    //  EnRxDqsTracking[pstate]
    //
    int EnRxDqsTracking[4];


    //
    // @brief Control the length and pattern of DDR5 write DQ and DM preamble
    // - Control the length and pattern of DDR5 write DQ and DM preamble
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | 1 MemClk toggling preamble
    //       1 | X MemClk preamble with pattern XXXX (TBD)
    //       2 | XX MemClk preamble with pattern XXXX (TBD)
    //       3 | XXX MemClk preamble with pattern XXXX (TBD)
    //       4 | XXXX MemClk preamble with pattern XXXX (TBD)
    // - Default: 1
    //
    //  D5TxDqPreambleCtrl[pstate]
    //
    int D5TxDqPreambleCtrl[4];

    //
    // @brief Disable PHY-initiated tDQS2DQ Drift compensation re-training
    // - Disable PHY re-training during DFI frequency change requests and PMI.
    //   See PUB Databook section "Tracking of DDR5 DRAM Write-DQS Drift" for details
    // - DDR5 LRDIMM does not support retraining
    // - Controller-initiated re-training is not affected by this field
    // - Values:
    //   Value | Description
    //   ----- | -----
    //     0x1 | Disable PHY-initiated retraining
    //     0x0 | Enable PHY-initiated retraining
    // - Default: 0
    //
    int D5DisableRetraining;


    //
    // @brief Disables ARC Microcontroller ECC
    // - Disables ARC Microcontroller ECC
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | Enable ECC
    //       1 | Disable ECC
    // - Default: 0
    //
    int DisablePmuEcc;

    //
    // @brief Enables Async Path from MALERT_N to dfi_alert_n
    // - Enables Async Path from MALERT_N to dfi_alert_n
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       1 | Enable
    //       0 | Disable
    // - Default: 0
    //
    int EnableMAlertAsync;

    //
    // @brief Enables logic that disables/resets RxTracking during an Alert
    // - Enables logic that disables/resets RxTracking during an Alert
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       1 | Enable
    //       0 | Disable
    // - Default: 0
    //
    int AlertRecoveryEnable;

    //
    // @brief Controls RxTracking during an Alert
    // - Controls Async Path from MALERT_N to dfi_alert_n
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | an alert will suspend RxTracking until the next ctrlupd
    //       1 | an alert will reset   RxTracking state
    // - Default: 0
    //
    int RstRxTrkState;

    //
    // @brief Enable 32 bit write to ICCM and DCCM memories using APB interface.
    // - should only be enabled when `DWC_DDRPHY_APB32BITMODE is define.
    // - CSR APBMode16BitOverride should not be set.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | APB 16 bit writes for ICCM and DCCM memory
    //       1 | APB 32 bit writes for ICCM and DCCM memory
    // - Default: 0
    //
    int Apb32BitMode;

    //
    // @brief Enable 3DS.
    // - should be set to one for DDR5 3DS devices.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | 3DS disabled
    //       1 | 3DS enabled
    // - Default: 0
    //
    int en_3DS;

    //
    // @brief UserInput is maintained for backward compatibility. It is not valid from F-2022.06 and beyond.
    // phyinit is not using this setting anymore.
    // The number of logical ranks should be configured through UserInputAdvanced->Num_Logical_Ranks
    //
    // - Default: 0
    int en_16LogicalRanks_3DS;

    //
    // @brief Enable additional power savings during LP2 using csrPhyInLP2En
    // - only applicable for PUB Versions having PhyInLP2En register.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | Additional power savings during LP2 using csrPhyInLP2En disabled
    //       1 | Additional power savings during LP2 using csrPhyInLP2En enabled
    // - Default: 0
    //
    int PhyInLP2En_Pwr_Saving;

    //
    // @brief Enable special feature 1.
    // - should be set to one for enabling the special feature 1.
    // - The CsPresentCh<A/B> MessageBlock should be either 4'h3 or 4'hC if the special feature is enabled.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | special feature 1 disabled
    //       1 | special feature 1 enabled
    // - Default: 0
    // - This is an internal feature.
    // - Contact Synopsys before enabling this feature.
    int special_feature_1_en;

    //
    // @brief Enable Non-Target ODT Termination for MRR during PIE initiated PPT for DDR5
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | NT-ODT Disabled
    //       1 | NT-ODT Enabled
    // - Default: 0
    //
    int rtt_term_en;

    //
    // @brief Enable additional Power savings during LP2
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | LP2 power savings disabled
    //       1 | LP2 power savings enabled
    // - Default: 0
    // Contact Synopsys before enabling the UserInput.
    //
    int VREGCtrl_LP2_PwrSavings_En;

    //
    // @brief Enable nibble feature of ECC DBYTEs for DDR5. Each bit corresponds to different TGs.
    // Bit zero corresponsds to TG0 and so on.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //     0x0 | Byte ECC for all TGs
    //     0xF | Nibble ECC for all TGs
    // - Default: 0xF for UDIMM and 0x0 for RDIMM/LRDIMM
    //
    int Nibble_ECC;

    //
    // @brief Enable the overriding of DfiMode resgister. If set to 1, DfiMode register will be programmed to the value of UserInputAdvanced DfiMode_Override_Val.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //     0x0 | Phyinit calculates the CSR DfiMode.
    //     0x1 | The CSR DfiMode programmed to the value of UserInputAdvanced DfiMode_Override_Val.
    // - Default: 0x0
    // Contact Synopsys before enabling the UserInput. Recommended to use the default values.
    //
    int DfiMode_Override_En;

    //
    // @brief Program DfiMode to a customized value. The UserInputAdvanced DfiMode_Override_En should be set to 1 for enabling this feature.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //     0x<value> | CSR DfiMode will be programmed to value of 0x<value>.
    // - Default: 0x0
    // Contact Synopsys for the correct values. Recommended to use the default values.
    //
    int DfiMode_Override_Val;

    // @brief Enable the overriding of the UserInput NoX4onUpperNibbleTg
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       0 | LP2 power savings disabled
    //       1 | LP2 power savings enabled
    // - Default: 0
    //
    int NoX4onUpperNibble_Override;

    //
    // @brief Customize CSR NoX4onUpperNibbleTg<0/1/2/3> for each DBYTE.
    // Each bit corresponds to each DBYTE. The bit zero corresponsds to DBYTE 0 and so on.
    // This is per TG. This is valid only when NoX4onUpperNibble_Override is set to one.
    // - Values:
    //   Value  | Description
    //   -----  | -----
    //   0x0000 | CSR NoX4onUpperNibbleTg<0/1/2/3> for all 10 DBYES will be set to zero
    //   0x03ff | CSR NoX4onUpperNibbleTg<0/1/2/3> for all 10 DBYES will be set to one
    // - Default: 0
    //
    //  NoX4onUpperNibbleTg[tg]
    //
    int NoX4onUpperNibbleTg[4];

    //
    // @brief Indicates DFI1 channel is active or not. The UserInput is only valid when userInputBasic->Dfi1Exists is 1.
    // If DFI1 channel is physically present, then this UserInput will decide whether it is active or not.
    // - Values:
    //   Value  | Description
    //   -----  | -----
    //        0 | DFI1 channel is not active when userInputBasic->Dfi1Exists is 1
    //        1 | DFI1 channel is active when userInputBasic->Dfi1Exists is 1
    // - Default: 1
    //
    int Dfi1Active;

    //
    // @brief configure the number of logical ranks in the DDR5 3DS device.
    // - only valid when the user_input_advanced->en_3DS is enabled.
    // - Should be configured correctly for the proper refreshes during the DDR5 PPT.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       x | x logical ranks present in 3DS devices
    // - Default: 8
    //
    int Num_Logical_Ranks;

    //
    // @brief It defines the interval between the end of a phyupdate transaction and a subsequent phyupdate request.
    // - DFIPHYUPDCNT must be chosen such that (pUserInputAdvanced->DFIPHYUPDCNT) > (pUserInputAdvanced->DFIPHYUPDRESP).
    // - Values:
    //   Value   | Description
    //   ------  | ------
    //   4'b0000 | Disable timer-based PHY Update
    //   4'b1001 | 2K MEMCLKs minus nMEMCLKs_phyupd_resp
    //   4'b1010 | 4K MEMCLKs minus nMEMCLKs_phyupd_resp
    //   4'b1011 | 8K MEMCLKs minus nMEMCLKs_phyupd_resp
    //   4'b0001 | 16K MEMCLKs minus nMEMCLKs_phyupd_resp
    //   4'b0011 | 32K MEMCLKs minus nMEMCLKs_phyupd_resp
    //   4'b0111 | 64K MEMCLKs minus nMEMCLKs_phyupd_resp, default value
    //   4'b1111 | 128K MEMCLKs minus nMEMCLKs_phyupd_resp
    // - Default: 4'b0111
    //
    int DFIPHYUPDCNT;

    //
    // @brief It defines the maximum time that is allowed to the controller to respond to the request for a PHY update.
    // - A dfi_error will be signaled if there is no acknowledgement of the update request within nMEMCLKs_phyupd_resp.
    // - DFIPHYUPDRESP must be chosen such that (pUserInputAdvanced->DFIPHYUPDCNT) > (pUserInputAdvanced->DFIPHYUPDRESP).
    // - Values:
    //   Value  | Description
    //   ------ | ------
    //   3'b000 | nMEMCLKs_phyupd_resp = 1K MEMCLKs, default value
    //   3'b001 | nMEMCLKs_phyupd_resp = 2K MEMCLKs
    //   3'b010 | nMEMCLKs_phyupd_resp = 4K MEMCLKs
    //   3'b011 | nMEMCLKs_phyupd_resp = 8K MEMCLKs
    //   3'b100 | nMEMCLKs_phyupd_resp = 16K MEMCLKs
    // - Default: 3'b000
    //
    int DFIPHYUPDRESP;

} user_input_advanced_t;


//#############################################################################
//
// Structure for user input simulation options
//
//#############################################################################
typedef struct user_input_sim
{

    //
    // @brief DQ to DQS offset (tDQS2DQ, in integer number of ps) (DDR5 only)
    // - Manually enter the DRAM DQS delay (tDQS2DQ, in integer number of ps) to apply in simulation.
    // - Values are vendor-specific - ensure that the entered value aligns with that described for the connected DRAM model.
    // - Refer to discussions regarding the tDQS2DQ variable in the DDR5 JEDEC spec for more information.
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 0
    //
    int tDQS2DQ;

    //
    // @brief DRAM DQS device delay value (tDQSCK, in integer number of ps, DDR5 only)
    // - Manually enter the DRAM DQS delay (tDQSCK, in integer number of ps) to apply in simulation.
    // - Values are vendor-specific - ensure that the entered value aligns with that described for the connected DRAM model.
    // - Refer to discussions regarding the tDQSCK variable in the JEDEC specs for more information.
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 0
    //
    int tDQSCK;

    //
    // @brief RCD clock delay (integer number of ps)
    // - Manually enter the propagation delay (input to output, in integer number of ps) of the clock through the registering clock device
    // - Refer to discussions regarding the tSTAOFF variable in the RCD JEDEC spec for more information.
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 0
    //
    //  tSTAOFF[pstate]
    //
    int tSTAOFF[4];

    //
    // @brief LRDIMM data buffer delay (in integer number of ps)
    // - Manually enter the tPDM data buffer delay (in integer number of ps) between first rising edge of MDQS and first rising edge of DQS
    // - Refer to discussions regarding the tPDM variable in the DB JEDEC spec for more information.
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 0
    //
    //  tPDM[pstate]
    //
    int tPDM[4];

    // @brief Disables automatically calculating userInputSim->tCASL_add.
    // - Values:
    //   Value | Description
    //   ----- | -----
    //       1 | Enable tCASL_add override to manually set a custom tCASL_add value.
    //       0 | Disable tCASL_add override. tCASL_add will automatically get calculated. (Default)
    // - Default: 0
    //
    int tCASL_override;

    // @brief This user input is automatically calculated. This can only be set if userInputSim->tCASL_override = 0x1.
    // - Extra 2UI latency added if tDIMM_DQ > tDIMM_CK
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 0
    //
    //  tCASL_add[pstate][tg]
    //
    int tCASL_add[4][4];

    //Note : Following members are for Rdimm and the respective code for their usage needs porting.
#if 0
    //
    // @brief This is the additional compensation in terms of UIs added on top of userinput_sim tSTAOFF in SDR1 mode
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 2
    // Contact synopsys before changing the default value
    //
    int SDR1_tSTAOFF_Compensation;

    //
    // @brief This is the additional compensation in terms of UIs added on top of userinput_sim tSTAOFF in SDR2 mode
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 0
    // Contact synopsys before changing the default value
    //
    int SDR2_tSTAOFF_Compensation;

    //
    // @brief This is the additional compensation in terms of UIs added on top of userinput_sim tSTAOFF in DDR mode
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 1
    // Contact synopsys before changing the default value
    //
    int DDR_tSTAOFF_Compensation;

    //
    // @brief This should be set to one for leagcy default values for SDR1_tSTAOFF_Compensation, SDR2_tSTAOFF_Compensation
    // - and DDR_tSTAOFF_Compensation values.That is SDR1_tSTAOFF_Compensation = 1, SDR2_tSTAOFF_Compensation = 1
    // - and DDR_tSTAOFF_Compensation values = 0;
    // - Values:
    //   - Min: 0
    //   - Max: (TODO)
    // - Default: 0
    //
    int Legacy_tSTAOFF_Compensation;
#endif

} user_input_sim_t;

// Note: blantantly stealing all of this information from the message block that is passed in for FW training
// However, we need some of this information (not all of it)
// As such, creating a custom struct to store the information, while copying the exact comments
typedef struct user_input_dram_config
{
    uint8_t  MR0_A0;           // Byte offset 0x5e, CSR Addr 0x5802f, Direction=In
    // Value to be programmed in DRAM Mode Register 0 {Channel A, Rank 0}
    uint8_t  MR2_A0;           // Byte offset 0x5f, CSR Addr 0x5802f, Direction=In
    // Value to be programmed in DRAM Mode Register 2 {Channel A, Rank 0}
    uint8_t  MR8_A0;           // Byte offset 0x65, CSR Addr 0x58032, Direction=In
    // Value to be programmed in DRAM Mode Register 8 {Channel A, Rank 0}
    uint8_t  MR50_A0;          // Byte offset 0x80, CSR Addr 0x58040, Direction=In
    // Value to be programmed in DRAM Mode Register 50 {Channel A, Rank 0}
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
    uint8_t  X16Present;       // Byte offset 0x17, CSR Addr 0x5800b, Direction=In
    // X16 device map. Corresponds to CS[3:0] (same mapping for both channel).
    //  X16Present[0] = CS0 is populated with X16 devices
    //  X16Present[1] = CS1 is populated with X16 devices
    //  X16Present[2] = CS2 is populated with X16 devices
    //  X16Present[3] = CS3 is populated with X16 devices
    //  X16Present[7:4] = Reserved (must be programmed to 0)
    //
    // Ranks may not contain mixed device types.
    uint8_t  RCW00_ChA_D0;     // Byte offset 0x200, CSR Addr 0x58100, Direction=In
    // RCD CW 0x00 setting, Channel A, DIMM0. Unused for UDIMM.
    uint8_t  DisabledDbyte;    // Byte offset 0x1a, CSR Addr 0x5800d, Direction=In
    // Bitmap to indicate which Dbytes are not connected (for DByte 0 to 7):
    // Set DisabledDbyte[i] to 1 to specify that DByte i does not need to be trained (DByte 8 and 9 can be disabled via EnabledDQs setting, however both must either enabled or disabled)
} user_input_dram_config_t;
#endif
