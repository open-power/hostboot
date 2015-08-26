/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_shmoo_common.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: mss_shmoo_common.H,v 1.21 2015/08/07 11:29:09 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM 
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             : mss_shmoo_common.H
// *! TITLE                : MSS Shmoo common defines
// *! DESCRIPTION          : Memory Subsystem Shmoo common defines
// *! CONTEXT              : To make all shmoos share a common defines
// *!
// *! OWNER  NAME          : Preetham Hosmane 				 Email - preeragh@in.ibm.com
// *! BACKUP NAME          : Saravanan Sethuraman            Email:     
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// 1.21    |preeragh| 30/07/15| Optimized for FW Linear/Composite/Bin
// 1.20    |preeragh| 22/06/15| DDR4 - Mods
// 1.18    |mjjones | 24/01/14| RAS Review Updates
// 1.15    |abhijit |8/8/12   | Updated Review Comments
// 1.9     |aditya  |12/6/12  | Updated Review Comments
// 1.8     | abhijit| 15/11/12| made changes fw review comments 
// 1.7     | abhijit| 22/10/12| made changes to variables
// 1.6     | abhijit| 22/10/12| made changes according to the new design 
// --------|--------|-------- |--------------------------------------------------
#ifndef MSS_SHMOO_COMMON_H
#define MSS_SHMOO_COMMON_H

enum shmoo_type_t
{
    TEST_NONE = 0,
    MCBIST    = 1,
    WR_EYE    = 2,
    WRT_DQS   = 8,
    RD_EYE    = 4,
    RD_GATE   = 16
};

enum shmoo_algorithm_t
{
    SEQ_LIN  // Parallel bytes/ranks here .. no parallel targets in HB
};

const uint8_t NINE = 9;
const uint8_t MAX_SHMOO=2;
const uint8_t MAX_RANK_DIMM=4;
const uint8_t MAX_NIBBLES=2;
const uint8_t MAX_BITS=4;
const uint8_t MAX_DQ=80;
const uint8_t MAX_DQS=20;
const uint8_t SCHMOO_NIBBLES=20;
const uint8_t MAX_PORT = 2;
const uint8_t MAX_BYTE = 10;
const uint8_t MAX_RANK = 8;

//! Defines the structure of a knob ..Holds static info regarding a knob
struct shmoo_knob_config_t
{
    //! These are const values that define a knob , will not change during
    //! shmoo runtime
    uint16_t min_val; //Minimum value that can be taken by the knob
    uint16_t max_val; //Maximum value that can be taken by the knob
};

//! Defines the structure of a knob ..Holds dynamic runtime info of a knob
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
