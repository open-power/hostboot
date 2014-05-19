/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnproc.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
         * @brief disable Clear the enablement state.
         */
        void disable()
        {
            iv_enabled = false;
        }

        /**
         * @brief enable Set the enablement state.
         */
        void enable()
        {
            iv_enabled = true;
        }

        /**
         * @brief enabled Obtain the enablement state.
         *
         * @retval[true] Enabled.
         * @retval[true] Disabled.
         */
        bool enabled() const
        {
            return iv_enabled;
        }

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
         * @brief resolveIpoll Find attentions of the supplied type on the
         *        supplied target, using ipoll.
         *
         * @param[in] i_proc The proc on which to look for attentions.
         * @param[out] o_attentions Where to put attentions when found.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t resolveIpoll(
                TARGETING::TargetHandle_t i_proc,
                AttentionList & o_attentions);

        /**
         * @brief resolve Find attentions of the supplied type on the
         *        supplied target, using broadcast FIRs.
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

        /**
         * @brief ctor
         */
        ProcOps() : iv_enabled(true) {}

    private:

        /**
         * @brief iv_enabled Enablement state.
         */
        bool iv_enabled;
};
}
#endif
