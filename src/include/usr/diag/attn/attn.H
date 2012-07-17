/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/diag/attn/attn.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __ATTN_ATTN_H
#define __ATTN_ATTN_H

/**
 * @file attn.H
 *
 * @brief HBATTN declarations.
 */

#include <errl/errlentry.H>

namespace ATTN
{

/**
 * @brief startService Start the HB attention handler service.
 *
 * Registers with Interrupt Service for callback for attention
 *          or host type interrupts.
 *
 * @retval[0] No error occurred.
 * @retval[1] Unexpected error occurred.
 */
errlHndl_t startService();

/**
 * @brief stopService Stop the HB attention handler service.
 *
 * Stop background threads and unregister from Interrupt Service
 * Attention or host type interrupt messages.  Waits for completion of
 * any in-progress attention analysis.
 *
 * @post All resources reclaimed, no outstanding attentions.
 *
 * @retval[0] No error occurred.
 * @retval[1] Unexpected error occurred.
 */
errlHndl_t stopService();

/**
 * @brief checkForIplAttentions
 *
 * Check each proc target for any attentions
 * and invoke PRD for analysis.  Will loop indefinitely
 * until all chips stop reporting attentions.
 *
 * @retval[0] No errors.
 * @retval[!0] Unexpected error occurred.
 */
errlHndl_t checkForIplAttentions();
}
#endif
