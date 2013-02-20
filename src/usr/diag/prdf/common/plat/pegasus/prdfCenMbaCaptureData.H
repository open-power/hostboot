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
 * @brief Add DRAM repair data to error log.
 * @param i_mbaTarget An MBA target.
 * @param o_errHdl       Error log handle.
 */
void addDramRepairsData( TARGETING::TargetHandle_t i_mbaTarget,
                         errlHndl_t o_errHdl );


/**
 * @brief Add DRAM repair data to SDC.
 * @param i_mbaTarget An MBA target.
 * @param io_sc       The step code data struct.
 */
void addDramRepairsData( TARGETING::TargetHandle_t i_mbaTarget,
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
} // end namespace MbaCaptureData

} // end namespace PRDF

#endif // PRDF_CEN_MBA_CAPTURE_DATA_H

