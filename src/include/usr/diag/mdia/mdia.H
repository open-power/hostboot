//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/diag/mdia/mdia.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __MDIA_MDIA_H
#define __MDIA_MDIA_H

#include <errl/errlentry.H>
#include <targeting/target.H>

/**
 * @file mdia.H
 * @brief mdia component interface
 */

class PrdfMdiaMessage;

namespace MDIA
{
/**
 * @brief runStep istep dispatcher entry point.
 *
 * execute the memory diagnostics ipl step on a single mba
 * or a list of mbas
 *
 * @param[in] i_targetList the targets on which to run diagnostics
 *
 * @return errlHndl_t. Error log handle.
 * @retval 0 no errors
 * @retval !0 error occurred
 *
 * @pre memory ready to hold data, node free of attentions
 * @post memory tested and initialized, ready to hold data
 */
errlHndl_t runStep(const TARGETING::TargetHandleList & i_targetList);

/**
 * @brief processEvent prd callback
 *
 * called by prd to inform memory diagnostics of attention
 * related events like maint command complete or hw error.
 *
 * @param[in] i_event prd attention event to be processed
 *
 * @return errlHndl_t. Error log handle.
 * @retval 0 no errors
 * @retval !0 error occurred
 *
 * @pre memory diagnostics ipl step in progress
 * @post message processed
 */
errlHndl_t processEvent(PrdfMdiaMessage & i_event);
}
#endif
