/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaThresholds.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

#ifndef __PRDF_CEN_MBA_THRESHOLDS_H
#define __PRDF_CEN_MBA_THRESHOLDS_H

/** @file  prdfCenMbaThresholds.H
 *  @brief Utility functions used to get specific Centaur thresholds
 *         during IPL time.
 */

#include <prdfCenMbaThresholds_common.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfMfgThresholds.H>

namespace PRDF
{

class ExtensibleChip;

/**
 * @brief  Returns the manufacturing memory CE thresholds Per 2GB ( base ).
 */
inline uint8_t getMnfgCeTh()
{
    return MfgThresholdMgr::getInstance()->
                    getThreshold( PRDF_CEN_MBA_IPL_SOFT_CE_TH_ALGO );

}

} // end namespace PRDF

#endif /* __PRDF_CEN_MBA_THRESHOLDS_H */

