/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnproc.H $
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
#ifndef __ATTN_ATTNPROC_H
#define __ATTN_ATTNPROC_H

/**
 * @file attnproc.H
 *
 * @brief HBATTN Processor attention operations definition.
 */

#include "attnops.H"

namespace ATTN
{

/**
 * @brief ProcOps ATTN Processor attention operations definition.
 */
class ProcOps : public AttentionOps
{
    public:

        /**
         * @brief mask Mask this attention.
         *
         * @param[in] i_data The attention to mask.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t mask(const PRDF::AttnData & i_data);

        /**
         * @brief unmask Unmask this attention.
         *
         * @param[in] i_data The attention to unmask.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t unmask(const PRDF::AttnData & i_data);

        /**
         * @brief query Test to see if this attention is active.
         *
         * @param[in] i_data The attention to query.
         * @param[out] o_active true if attention is active.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t query(const PRDF::AttnData & i_data, bool & o_active);

        /**
         * @brief resolve Find attentions of the supplied type on the
         *        supplied target.
         *
         * @param[in] i_proc The proc on which to look for attentions.
         * @param[in] i_typeMask The types of attentions to look for.
         * @param[out] o_attentions Where to put attentions when found.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t resolve(
                TARGETING::TargetHandle_t i_proc,
                uint64_t i_typeMask,
                AttentionList & o_attentions);

        /**
         * @brief dtor
         */
        ~ProcOps() {}
};
}
#endif
