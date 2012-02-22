//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/hwp/dimmConsts.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file dimmConsts.H
 *
 *  @brief DIMM Constants
 */

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

#endif
