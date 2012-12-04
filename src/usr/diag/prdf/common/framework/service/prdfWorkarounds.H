/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfWorkarounds.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2007,2013              */
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

/**
 * @file prdfWorkarounds.H
 * @brief Prototypes for Workaround functions.
 *
 * These functions allow workarounds to be applied at different points in the
 * analysis.  It is expected that the code for these workarounds are
 * implemented in each system subdirectory.
 */

#ifndef __PRDFWORKAROUNDS_H
#define __PRDFWORKAROUNDS_H

#include <iipstep.h>

namespace PRDF
{

/**
 * @fn PostAnalysisWorkarounds
 * @brief Apply workarounds after "system" analysis, but prior to RAS Services.
 */
void PostAnalysisWorkarounds(STEP_CODE_DATA_STRUCT & i_sdc);

} // end namespace PRDF

#endif
