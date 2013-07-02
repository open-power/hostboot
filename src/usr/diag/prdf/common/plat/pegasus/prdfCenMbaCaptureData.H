/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaCaptureData.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2013              */
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

#ifndef PRDF_CEN_MBA_CAPTURE_DATA_H
#define PRDF_CEN_MBA_CAPTURE_DATA_H

/**
 *  @file  prdfCenfMbaCaptureData.H
 *  @brief Header File for utility functions to capture MBA related data.
 */

#include <targeting/common/targetservice.H>
#include <iipCaptureData.h>
#include <errlentry.H>

namespace PRDF
{

struct STEP_CODE_DATA_STRUCT;

namespace CenMbaCaptureData
{

/**
 * @brief Adds Memory ECC FFDC to an error log.
 * @note  This is intended to be used in non-normal analysis paths that do not
 *        have an SDC (i.e. Restore DRAM Repairs, IPL MNFG CE Isolation).
 * @note  The data will be limited and include things like the DRAM Repairs data
 *        but will not include stuff like the CE/UE tables, because that
 *        information is not relevent during its intented uses.
 * @param i_mba  Target MBA.
 * @param o_errl Target error log.
 */
void addMemEccData( TARGETING::TargetHandle_t i_mba, errlHndl_t io_errl );

/**
 * @brief Adds Memory ECC FFDC to an SDC.
 * @param i_mba Target MBA.
 * @param io_sc Target step code data struct.
 */
void addMemEccData( TARGETING::TargetHandle_t i_mba,
                    STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief Queries hardware for all DRAM repairs data (chip/symbol marks, DRAM
 *        spare, etc.) for the given MBA and added it to the capture data.
 * @param i_mbaTarget An MBA target.
 * @param o_cd        Capture data struct.
 * @note  This function will be used to capture DRAM repair data into
 *        capture data struct. Other functions can call this function and
 *        update error log
 */
void captureDramRepairsData( TARGETING::TargetHandle_t i_mbaTarget,
                             CaptureData & o_cd );

/**
 * @brief Queries the Bad DQ attributes for the content of the DRAM repairs VPD
 *        and add it to the capture data.
 * @param i_mbaTarget An MBA target.
 * @param o_cd        Capture data struct.
 * @note  This function will be used to capture DRAM repair data into
 *        capture data struct. Other functions can call this function and
 *        update error log
 */
void captureDramRepairsVpd( TARGETING::TargetHandle_t i_mba,
                            CaptureData & o_cd );

} // end namespace MbaCaptureData

} // end namespace PRDF

#endif // PRDF_CEN_MBA_CAPTURE_DATA_H

