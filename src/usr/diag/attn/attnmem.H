/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnmem.H $                                 */
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
#ifndef __ATTN_ATTNMEM_H
#define __ATTN_ATTNMEM_H

/**
 * @file attnmem.H
 *
 * @brief HBATTN memory attention operations definition.
 */

#include "attnops.H"
#include <map>

namespace ATTN
{

/**
 * @brief MemOps ATTN memory attention operations definition.
 */
class MemOps : public AttentionOps
{
    public:

        /**
         * @brief resolve Find membuf attentions behind the supplied proc.
         *
         * @param[in] i_proc The proc on which to look for attentions.
         * @param[out] o_attentions Where to put attentions when found.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t resolve(
                TARGETING::TargetHandle_t i_proc,
                AttentionList & o_attentions);

        /**
         * @brief dtor
         */
        ~MemOps();

        /**
         * @brief ctor
         */
        MemOps();
};
}
#endif
