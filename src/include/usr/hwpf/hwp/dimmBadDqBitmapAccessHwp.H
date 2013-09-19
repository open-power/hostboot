/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/dimmBadDqBitmapAccessHwp.H $         */
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
// $Id: dimmBadDqBitmapAccessHwp.H,v 1.2 2013/08/13 20:29:40 mjjones Exp $
/**
 *  @file dimmBadDqBitmapAccessHwp.H
 *
 *  @brief FW Team HWP that accesses the Bad DQ Bitmap.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     02/17/2012  Created.
 */

#ifndef DIMMBADDQBITMAPACCESSHWP_H_
#define DIMMBADDQBITMAPACCESSHWP_H_

#include <fapi.H>
#include <dimmConsts.H>

typedef fapi::ReturnCode (*dimmBadDqBitmapAccessHwp_FP_t)(
    const fapi::Target &,
    const fapi::Target &,
    const uint8_t (&)[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE],
    const bool);

extern "C"
{

/**
 * @brief FW Team HWP that accesses the Bad DQ Bitmap. It accesses the raw data
 *        from DIMM SPD and does any necessary processing to turn it into a
 *        bitmap from a Centaur DQ point of view. If the data in SPD is not
 *        valid then it has never been written and all zeroes are returned (no
 *        bad DQs).
 *
 * This HWP should be called by HWP/PLAT code to access the BAD DQ Bitmap
 *
 * Note that the MSB of each byte corresponds to the lowest DQ.
 * if (data[1][0] == 0x80) then rank 1, Centaur DQ0 is bad
 * if (data[1][0] == 0x40) then rank 1, Centaur DQ1 is bad
 * if (data[1][1] == 0x20) then rank 1, Centaur DQ10 is bad
 *
 * @param[in] i_mba   Reference to MBA Target
 * @param[in] i_dimm  Reference to DIMM Target
 * @param[io] io_data Reference to bad DQ bitmap data for the DIMM.
 * @param[in] i_get   True if getting DQ Bitmap data. False if setting data.
 *
 * @return ReturnCode
 */
fapi::ReturnCode dimmBadDqBitmapAccessHwp(
    const fapi::Target & i_mba,
    const fapi::Target & i_dimm,
    uint8_t (&io_data)[DIMM_DQ_MAX_DIMM_RANKS][DIMM_DQ_RANK_BITMAP_SIZE],
    const bool i_get);

}

#endif
