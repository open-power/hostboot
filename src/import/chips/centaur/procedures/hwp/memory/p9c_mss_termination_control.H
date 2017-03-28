/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_termination_control.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file mss_draminit_training_advanced.H
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: SARAVANAN SETHURAMAN <saravanans@in.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
//
//


#ifndef MSS_TERMINATION_CONTROL_H
#define MSS_TERMINATION_CONTROL_H
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>
#include <cen_gen_scom_addresses_fld.H>
#include <cen_gen_scom_addresses.H>

///
/// @brief termination constants
///
enum term_consts : size_t
{
    SLEW = 0,
    IMP = 1,
    MAX_NUM_IMP = 4,      // number of impedances valid per slew type
    // bypass slew (MAX slew rate) not included since it is not calibrated.
    MAX_NUM_CAL_SLEW_RATES = 4,  // 3V/ns, 4V/ns, 5V/ns, 6V/n
    MAX_NUM_SLEW_RATES = 4,   // 3V/ns, 4V/ns, 5V/ns, 6V/n, MAX?
    MAX_SLEW_VALUE = 15,      // 4 bit value
    MAX_WR_VREF = 32,
    MAX_DRV_IMP = 4,
    MAX_RCV_IMP = 9,
};

///
/// @brief Address shmoo is not done as a part of Training advanced, so the order matches attribute enum
///
const uint8_t adr_imp_array[] =
{
    15,
    20,
    30,
    40,
};

///
/// @brief slew rate values
///
const uint8_t slew_rate_array[] =
{
    6,
    5,
    4,
    3,
};

///
/// @brief Wr vref values
///
const uint32_t wr_vref_array[] =
{
    420,
    425,
    430,
    435,
    440,
    445,
    450,
    455,
    460,
    465,
    470,
    475,
    480,
    485,
    490,
    495,
    500,
    505,
    510,
    515,
    520,
    525,
    530,
    535,
    540,
    545,
    550,
    555,
    560,
    565,
    570,
    575
};


//The Array is re-arranged inorder to find the best Eye margin based on the
//Fitness level - 500 is the best value
const uint32_t wr_vref_array_fitness[] =
{
    420,
    425,
    575,
    430,
    570,
    435,
    565,
    440,
    560,
    445,
    555,
    450,
    550,
    455,
    545,
    460,
    540,
    465,
    535,
    470,
    530,
    475,
    525,
    480,
    520,
    485,
    515,
    490,
    510,
    495,
    505,
    500
};

const uint8_t MAX_RD_VREF = 16;

///
/// @brief rd vref values
///
const uint32_t rd_cen_vref_array[] =
{
    40375,
    41750,
    43125,
    44500,
    45875,
    47250,
    48625,
    50000,
    51375,
    52750,
    54125,
    55500,
    56875,
    58250,
    59625,
    61000
};

///
/// @brief The Array is re-arranged inorder to find the best Eye margin based on the
/// Fitness level - 50000 is the best value
///
const uint32_t rd_cen_vref_array_fitness[] =
{
    61000,
    59625,
    40375,
    58250,
    41750,
    56875,
    43125,
    55500,
    44500,
    54125,
    45875,
    52750,
    47250,
    51375,
    48625,
    50000
};

///
/// @brief The Array is re-arranged inorder to find the best Eye margin based on the
/// Fitness level - 24 is the best value
///
const uint8_t drv_imp_array[] =
{
    40,
    34,
    30,
    24
};

///
/// @brief The Array is re-arranged inorder to find the best Eye margin based on the
/// Fitness level - 15 is the best value
///
const uint8_t rcv_imp_array[] =
{
    120,
    80,
    60,
    48,
    40,
    34,
    30,
    20,
    15
};

///
/// @brief slew calibration control register
///
constexpr uint64_t SLEW_CAL_CNTL[] =
{
    CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0, // port 0
    CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P1_ADR32S0  // port 1
};

///
/// @brief slew calibration status registers
///
constexpr uint64_t SLEW_CAL_STAT[] =
{
    CEN_MBA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_RO,
    CEN_MBA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P1_ADR32S0_RO
};

///
/// @brief adr enums
///
enum adr
{
    ADR_SLEW_CAL_CNTL_ADR32S0_ENABLE = CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_ADR0_ENABLE,
    ADR_SLEW_CAL_CNTL_ADR32S0_START = CEN_MBA_DDRPHY_ADR_SLEW_CAL_CNTL_P0_ADR32S0_ADR0_START,
    ADR_SYSCLK_PR_VALUE_RO_BB_LOCK = CEN_MBA_DDRPHY_ADR_SYSCLK_PR_VALUE_RO_P0_ADR32S0_ADR0_BB_LOCK,
};

constexpr uint8_t NUM_DRAM_GENS = 2;
constexpr uint8_t NUM_PIN_TYPES = 2;
constexpr uint8_t NUM_SPEEDS = 4;
constexpr uint8_t NUM_IMPS = 4;
constexpr uint8_t NUM_SLEWS = 4;
// DD level 1.0-1.1, Version 1.0
// [ddr3/4][dq/adr][speed][impedance][slew_rate]
// note: Assumes standard voltage for DDR3(1.35V), DDR4(1.2V),
// little endian, if >=128, lab only debug.
//
// ddr_type(2)  ddr3=0, ddr4=1
// data/adr(2)  data(dq/dqs)=0, adr(cmd/cntl)=1
// speed(4)     1066=0, 1333=1, 1600=2, 1866=3
// imped(4)     24ohms=0, 30ohms=1, 34ohms=2, 40ohms=3 for DQ/DQS
// imped(4)     15ohms=0, 20ohms=1, 30ohms=2, 40ohms=3 for ADR driver
// slew(3)      3V/ns=0, 4V/ns=1, 5V/ns=2, 6V/ns=3
constexpr uint8_t SLEW_TABLE[NUM_DRAM_GENS][NUM_PIN_TYPES][NUM_SPEEDS][NUM_IMPS][NUM_SLEWS] =
{
    //  NOTE: bit 7 = unsupported slew, and actual value is in bits 4:0

    /*  DDR3(0) */
    { {
            // dq/dqs(0)
            /* Imp. ________24ohms______..________30ohms______..________34ohms______..________40ohms______
               Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
            /*1066*/{{ 12,   9,   7, 134}, { 13,   9,   7, 133}, { 13,  10,   7, 134}, { 14,  10,   7, 132}},
            /*1333*/{{ 15,  11,   8, 135}, { 16,  12,   9, 135}, { 17,  12,   9, 135}, { 17,  12,   8, 133}},
            /*1600*/{{ 18,  13,  10, 136}, { 19,  14,  10, 136}, { 20,  15,  11, 136}, { 21,  14,  10, 134}},
            /*1866*/{{149, 143, 140, 138}, {151, 144, 140, 137}, {151, 145, 141, 138}, {152, 145, 139, 135}}
        }, {
            // adr(1),
            /* Imp. ________15ohms______..________20ohms______..________30ohms______..________40ohms______
               Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
            /*1066*/{{ 17,  13,  10,   8}, { 13,  10,   7,   6}, { 12,   8,   5, 131}, {  7,   4, 131, 131}},
            /*1333*/{{ 21,  16,  12,  10}, { 17,  12,   9,   7}, { 15,  10,   6, 132}, {  6,   5, 132, 132}},
            /*1600*/{{ 25,  19,  15,  12}, { 20,  14,  13,   8}, { 19,  12,   7, 133}, {  7,   6, 133, 133}},
            /*1866*/{{157, 150, 145, 142}, {151, 145, 141, 138}, {150, 142, 136, 134}, {141, 134, 134, 134}}
        }
    },
    /* DDR4(1) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    { {
            // dq/dqs(0)
            /* Imp. ________24ohms______..________30ohms______..________34ohms______..________40ohms______
               Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
            /*1066*/{{138, 135, 134, 133}, {139, 136, 134, 132}, {140, 136, 134, 132}, {140, 136, 132, 132}},
            /*1333*/{{139, 137, 135, 134}, {142, 138, 135, 133}, {143, 138, 135, 133}, {143, 138, 133, 132}},
            /*1600*/{{ 15,  11,   9, 135}, { 17,  11,   9, 135}, { 18,  13,   9, 134}, { 18,  11,   6, 133}},
            /*1866*/{{ 18,  13,  10, 137}, { 19,  13,  10, 136}, { 21,  15,  10, 135}, { 21,  13,   8, 134}}
        }, {
            // adr(1)
            /* Imp. ________15ohms______..________20ohms______..________30ohms______..________40ohms______
               Slew    3    4    5    6      3    4    5    6      3    4    5    6      3    4    5    6  (V/ns) */
            /*1066*/{{142, 139, 136, 134}, {140, 136, 134, 133}, {138, 134, 131, 131}, {133, 131, 131, 131}},
            /*1333*/{{145, 142, 139, 136}, {143, 138, 135, 134}, {140, 135, 132, 132}, {134, 132, 132, 132}},
            /*1600*/{{ 21,  16,  13,  10}, { 18,  12,   9, 135}, { 15,   8, 133, 133}, {  7, 133, 133, 133}},
            /*1866*/{{ 24,  19,  15,  11}, { 21,  14,  10, 136}, { 17,  10, 134, 134}, {  9, 134, 134, 134}}
        }
    }
};


extern "C"
{
    ///
    /// @brief configures PC_VREF_DRV_CONTROL registers to vary the DRAM VREF
    /// @param[in] i_target_mba   Reference to centaur.mba target
    /// @param[in] i_port         MBA Port
    /// @param[in] i_wr_dram_vref DRAM VREF to set
    /// @return ReturnCode
    ///
    fapi2::ReturnCode config_wr_dram_vref(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                          const uint8_t i_port,
                                          const uint32_t i_wr_dram_vref);

    ///
    /// @brief configures read vref registers to vary the CEN VREF
    /// @param[in] i_target_mba   Reference to centaur.mba target
    /// @param[in] i_port         MBA Port
    /// @param[in] i_rd_cen_vref  CEN VREF to set
    /// @return ReturnCode
    ///
    fapi2::ReturnCode config_rd_cen_vref(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const uint8_t i_port,
                                         const uint32_t i_rd_cen_vref);

    ///
    /// @brief configures the Driver impedance values to the registers
    /// @param[in] i_target_mba     Reference to centaur.mba target
    /// @param[in] i_port           MBA Port
    /// @param[in] i_drv_imp_dq_dqs Driver impedance values
    /// @return ReturnCode
    ///
    fapi2::ReturnCode config_drv_imp(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                     const uint8_t i_port,
                                     const uint8_t i_drv_imp_dq_dqs);

    ///
    /// @brief configures the Receiver impedance values to the registers
    /// @param[in] i_target_mba     Reference to centaur.mba target
    /// @param[in] i_port           MBA Port
    /// @param[in] i_rcv_imp_dq_dqs Receiver impedance values
    /// @return ReturnCode
    ///
    fapi2::ReturnCode config_rcv_imp(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                     const uint8_t i_port,
                                     const uint8_t i_rcv_imp_dq_dqs);

    ///
    /// @brief configures the Slew rate values to the registers
    /// @param[in] i_target_mba Reference to centaur.mba target
    /// @param[in] i_port       MBA Port
    /// @param[in] i_slew_type  Slew Type
    /// @param[in] i_slew_imp   Slew Impedance
    /// @param[in] i_slew_rate  Slew Rate
    /// @return ReturnCode
    ///
    fapi2::ReturnCode config_slew_rate(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                       const uint8_t i_port,
                                       const uint8_t i_slew_type,
                                       const uint8_t i_slew_imp,
                                       const uint8_t i_slew_rate);

    ///
    /// @brief runs the slew calibration engine
    /// Configures MSS_SLEW_DATA/ADR attributes and calls config_slew_rate to set
    /// the slew rate in the registers.
    /// @param[in] i_target_mba     Reference to centaur.mba target
    /// @return ReturnCode
    ///
    fapi2::ReturnCode mss_slew_cal(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

} // extern C
#endif
