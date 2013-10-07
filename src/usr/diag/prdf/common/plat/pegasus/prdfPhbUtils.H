/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPhbUtils.H $        */
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

#ifndef PHB_CONFIG_H
#define PHB_CONFIG_H

/** @file  prdfPhbUtils.H
 *  @brief Utility functions to determine PHB Configuration.
 */

#include <prdfPlatServices.H>

namespace PRDF
{

namespace Proc
{

/**
 * @brief  Returns PHB target associated with given IOPCIFR and clock.
 * @param  i_procTrgt The target processor.
 * @param  i_iopciIdx IOPCIFIR instance number (0,1)
 * @param  i_clkIdx   The target clock within the IOPCIFIR (0-1)
 * @param  o_phbTrgt  NULL if the PHB does not exist. Otherwise the PHB target.
 * @return NULL if no configured PHB found, otherwise the target PHB.
 */
int32_t getConfiguredPHB( TARGETING::TargetHandle_t i_procTrgt,
                          uint32_t i_iopciIdx, uint32_t i_clkIdx,
                          TARGETING::TargetHandle_t & o_phbTrgt );

} // end namespace Proc

} // end namespace PRDF

#endif // PHB_CONFIG_H
