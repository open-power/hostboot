/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/dimmConsts.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
/**
 *  @file dimmConsts.H
 *
 *  @brief DIMM Constants
 */
// $Id: dimmConsts.H,v 1.5 2014/11/03 17:16:17 eliner Exp $
/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     02/17/2012  Created.
 */

#ifndef DIMMCONSTS_H_
#define DIMMCONSTS_H_

// Maximum number of ports on an MBA
const uint8_t DIMM_DQ_MAX_MBA_PORTS = 2;

// Maximum number of DIMMs attached to an MBA PORT
const uint8_t DIMM_DQ_MAX_MBAPORT_DIMMS = 2;

// Maximum number of ranks on a DIMM
const uint8_t DIMM_DQ_MAX_DIMM_RANKS = 4;

// Size in bytes of the Bad DQ bitmap for a rank.
const uint8_t DIMM_DQ_RANK_BITMAP_SIZE = 10;

// Number of DQs (data query pins).
// This is the number of bits in DIMM_DQ_RANK_BITMAP_SIZE.
const uint8_t DIMM_DQ_NUM_DQS = DIMM_DQ_RANK_BITMAP_SIZE * 8;

// Size in bytes of Bad DQ Data in DIMM SPD
// This must be big enough to contain the bitmap for each rank
// (DIMM_DQ_MAX_DIMM_RANKS * DIMM_DQ_RANK_BITMAP_SIZE), plus the header
const uint8_t DIMM_DQ_SPD_DATA_SIZE = 80;

//ISDIMM to C4 DQ and DQS constant
//Number of Ports needed in the array
const uint8_t DIMM_TO_C4_PORTS = 4;
//Number of entries in the DQ attribute
const uint8_t DIMM_TO_C4_DQ_ENTRIES = 80;
//Number of entries in the DQS attribute
const uint8_t DIMM_TO_C4_DQS_ENTRIES = 20;

#endif
