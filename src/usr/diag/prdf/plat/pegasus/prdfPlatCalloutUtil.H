/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfPlatCalloutUtil.H $        */
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

#ifndef __prdfPlatCalloutUtil_H
#define __prdfPlatCalloutUtil_H

/** @file prdfPlatCalloutUtil.H */

// Framework includes
#include <prdfEnums.H>

namespace PRDF
{

class MemoryMru;

namespace CalloutUtil
{

/**
 * @brief Add all parts of a MemoryMru to the callout list of an error log.
 *        Also, adds the MemoryMru info to the capture data.
 *
 * This is only intended to be used by non-attention analysis code like Restore
 * DRAM Repairs or MNFG IPL CE analysis. In these cases, there is no SDC to
 * collect the callout info or capture data.
 *
 * @param io_errl         The target error log.
 * @param i_memmru        The target MemoryMru.
 * @param i_priority      The callout priority
 * @param i_deconfigState The deconfiguration state.
 * @param i_gardType      The GARD error type.
 */
void calloutMemoryMru( errlHndl_t io_errl, const MemoryMru & i_memmru,
                       const HWAS::callOutPriority i_priority,
                       const HWAS::DeconfigEnum    i_deconfigState,
                       const HWAS::GARD_ErrorType  i_gardType );

} // end namespace CalloutUtil

} // end namespace PRDF

#endif // __prdfPlatCalloutUtil_H

