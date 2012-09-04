/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/test/attninject.H $
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
#ifndef __TEST_ATTNINJECT_H
#define __TEST_ATTNINJECT_H

/**
 * @file attninject.H
 *
 * @brief
 */

#include "attntest.H"

namespace ATTN
{

/**
 * @brief InjectSink Attention inject interface.
 *
 * Interface definition for classes wishing to allow injection.
 */
class InjectSink
{
    public:

        /**
         * @brief dtor
         */
        virtual ~InjectSink() {}

        /**
         * @brief putAttentions
         *
         * Instruct the system to inject the specified attention.
         *
         * @param[in] i_list The attentions to inject.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t putAttentions(
                const PRDF::AttnList & i_list) = 0;

        /**
         * @brief clearAttention
         *
         * Instruct the system clear the specified attention.
         *
         * @param[in] i_attn The attention to clear.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t clearAttention(
                const PRDF::AttnData & i_attn) = 0;

        /**
         * @brief clearAllAttentions
         *
         * Instruct the system clear all instances of the specified attention.
         *
         * @param[in] i_attn The attention to clear.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t clearAllAttentions(
                const PRDF::AttnData & i_attn) = 0;
};
}
#endif
