/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCalloutUtil.H $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef prdfCalloutUtil_H
#define prdfCalloutUtil_H

/** @file  prdfCalloutUtil.H
 *  @brief Utility functions for common, non-trivial callouts.
 */

namespace PRDF
{

struct STEP_CODE_DATA_STRUCT;

namespace CalloutUtil
{

/**
 * @brief In many cases, an internal logic error may occur in which 2nd level
 *        support and FSP code need to be called out. This function is intented
 *        to help eliminate the need to constantly repeat the list of callouts.
 * @param i_sc The step code data struct.
 */
void defaultError( STEP_CODE_DATA_STRUCT & i_sc );

} // end namespace CalloutUtil
} // end namespace PRDF

#endif // prdfCalloutUtil_H
