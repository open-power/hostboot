/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_shmoo_common.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: mss_shmoo_common.H,v 1.12 2013/03/20 17:18:38 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM 
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : mss_shmoo_common.H
// *! TITLE                : MSS Shmoo common defines
// *! DESCRIPTION          : Memory Subsystem Shmoo common defines
// *! CONTEXT              : To make all shmoos share a common defines
// *!
// *! OWNER  NAME          : Varkey Varghese          Email: varkey.kv@in.ibm.com
// *! BACKUP NAME          : Gaurav Sharda            Email:     
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// 1.9     |aditya  |12/6/12  | Updated Review Comments
// 1.8     | abhijit| 15/11/12| made changes fw review comments 
// 1.7     | abhijit| 22/10/12| made changes to variables
// 1.6     | abhijit| 22/10/12| made changes according to the new design 
// --------|--------|-------- |--------------------------------------------------
#ifndef MSS_SHMOO_COMMON_H
#define MSS_SHMOO_COMMON_H

enum shmoo_type_t { TEST_NONE=0,MCBIST=1,WR_EYE=2, WRT_DQS=4,RD_EYE=8,RD_GATE=16 };


enum shmoo_algorithm_t { SEQ_LIN}; // Parallel bytes/ranks here .. no parallel targets in HB
const uint8_t NINE = 9;
const uint8_t MAX_RPS=4;// 4 Rank pairs in this design
const uint8_t MAX_SHMOO=4;
const uint8_t MAX_RANK_DIMM=4;
const uint8_t MAX_NIBBLES=2;
const uint8_t MAX_BITS=4;
const uint8_t MAX_DQ=80;
const uint8_t MAX_DQS=20;
const uint8_t SCHMOO_NIBBLES=20;
const uint16_t read_counter_threshold=1000;
const uint16_t error_threshold_count=400;
const uint8_t MAX_PORT = 2;
const uint8_t MAX_BYTE = 10;
const uint8_t MAX_RANK = 8;
//const uint8_t MAX_NIBBLE = 1;

//! Defines the structure of a knob ..Holds static info regarding a knob
struct shmoo_knob_config_t{
        //! These are const values that define a knob , will not change during
        //! shmoo runtime 
        uint16_t min_val; //Minimum value that can be taken by the knob
        uint16_t max_val; //Maximum value that can be taken by the knob
        
};

//! Defines the structure of a knob ..Holds dynamic runtime info of a knob
struct shmoo_knob_data_t{
    // placeholder for the datastructure that will hold all the shmoo
    // config data and results
    //uint32_t curr_val[MAX_BLOCK][MAX_INSTANCE][MAX_RPS];
    bool done;
    uint32_t lb_regval[MAX_DQ][MAX_RPS]; // Left Bound register/Hex value
    uint32_t rb_regval[MAX_DQ][MAX_RPS];// Right Bound register/Hex value
    uint32_t total_margin[MAX_DQ][MAX_RPS]; //Left bound+ right bound value
    uint32_t nom_val[MAX_DQ][MAX_RPS]; // nominal value of this instance of the knob
    uint32_t right_margin_val[MAX_DQ][MAX_RPS];
    uint32_t left_margin_val[MAX_DQ][MAX_RPS];
};
#endif
