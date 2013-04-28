/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/prdf/prdfMain.H $                        */
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

#ifndef __prdfMain_H
#define __prdfMain_H

/**
 * @file  prdfMain.H
 * @brief PRD code used by external components.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <errl/errlmanager.H> // for errlHndl_t

// This must be included after all other includes. This will take care of cases
// where a file must be included in the common code, but the include paths are
// different between FSP and Hostboot.
#include <diag/prdf/common/prdfMain_common.H>

namespace PRDF
{

/**
 * @brief  Restores hardware DRAM repairs to reflect what is stored in VPD.
 * @param  i_mba An MBA target.
 * @return Non-SUCCESS if conditions are such that a callout had to be made,
 *         SUCCESS otherwise.
 */
extern int32_t restoreDramRepairs( const TARGETING::TargetHandle_t i_mba );

/**
 * @brief  Analyzes IPL CE statistics during MNFG IPL
 * @param  i_mba An MBA target.
 * @param  o_calloutMade True if callout has been made, false otherwise .
 * @return Non-SUCCESS if internal function fails, SUCCESS otherwise.
 */
extern int32_t analyzeIplCEStats( const TARGETING::TargetHandle_t i_mba,
                                  bool &o_calloutMade );

/**
 * @brief  Starts memory background scrubbing on all MBAs in the node.
 *
 * This will only start the initial fast scrub of all memory. PRD on the FSP or
 * HostServices (SP-less machines) will need to resume normal background
 * scrubbing once this initial fast scrub is complete.
 *
 * @return If an error log is returned, then some internal function failed. See
 *         the FFDC in the error log for failure details.
 */
extern errlHndl_t startScrub();

} // end namespace PRDF

#endif // __prdfMain_H

