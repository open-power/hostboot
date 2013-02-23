/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfTargetFwdRef.H $                 */
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

/** @file  prdfTargetFwdRef.H
 *  @brief Forward references for the targeting code.
 *
 *  Allows the ability to use things like TargetHandle_t in header files without
 *  being required to include targeting/common/target.H.
 */

#ifndef __prdfTargetFwdRef_H
#define __prdfTargetFwdRef_H

namespace TARGETING
{
    class Target;

    typedef const Target* ConstTargetHandle_t;
    typedef       Target* TargetHandle_t;
}

#endif // __prdfTargetFwdRef_H

