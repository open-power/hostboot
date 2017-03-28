/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_shmoo_common.H $ */
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
/// @file mss_shmoo_common.H
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: steve glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
//
//



#ifndef MSS_SHMOO_COMMON_H
#define MSS_SHMOO_COMMON_H

///
/// @brief shmoo type enums
///
enum shmoo_type_t
{
    TEST_NONE = 0,
    MCBIST    = 1,
    WR_EYE    = 2,
    WRT_DQS   = 8,
    RD_EYE    = 4,
    RD_GATE   = 16,
    BOX       = 32
};

///
/// @brief shmoo algorithm enums
///
enum shmoo_algorithm_t
{
    SEQ_LIN  // Parallel bytes/ranks here .. no parallel targets in HB
};

const uint8_t NINE = 9;
const uint8_t MAX_SHMOO = 2;
const uint8_t MAX_RANK_DIMM = 4;
const uint8_t MAX_NIBBLES = 2;
const uint8_t MAX_BITS = 4;
const uint8_t MAX_DQ = 80;
const uint8_t MAX_DQS = 20;
const uint8_t SCHMOO_NIBBLES = 20;
const uint8_t MAX_PORT = 2;
const uint8_t MAX_BYTE = 10;
const uint8_t MAX_RANK = 8;

///
/// @brief Defines the structure of a knob ..Holds static info regarding a knob
///
struct shmoo_knob_config_t
{
    //! These are const values that define a knob , will not change during
    //! shmoo runtime
    uint16_t min_val; //Minimum value that can be taken by the knob
    uint16_t max_val; //Maximum value that can be taken by the knob
};

///
/// @brief Defines the structure of a knob ..Holds dynamic runtime info of a knob
///
struct shmoo_knob_data_t
{
    // placeholder for the datastructure that will hold all the shmoo
    // config data and results
    bool done;
    uint16_t lb_regval[MAX_DQ]; // Left Bound register/Hex value
    uint16_t rb_regval[MAX_DQ];// Right Bound register/Hex value
    uint16_t nom_val[MAX_DQ]; // nominal value of this instance of the knob
    uint16_t last_pass[MAX_DQ];
    uint16_t total_margin[MAX_DQ];
    uint16_t curr_diff[MAX_DQ];
    uint16_t last_fail[MAX_DQ];
    uint16_t curr_val[MAX_DQ];
    uint16_t right_margin_val[MAX_DQ];
    uint16_t left_margin_val[MAX_DQ];
};
#endif
