/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnvalidate.H $                       */
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
#ifndef __TEST_ATTNVALIDATE_H
#define __TEST_ATTNVALIDATE_H

/**
 * @file attnvalidate.H
 *
 * @brief HBATTN fake system validation class definitions.
 */

#include "attnfakeelement.H"

namespace ATTN
{

/**
 * @brief Validator
 *
 * Fake system validation class definition.
 *
 * Monitors attention state changes.
 *
 * Accumulates attentions injected on the system.
 */
class Validator : public FakeSource
{
    public:

        /**
         * @brief ctor
         */
        Validator() {};

        /**
         * @brief dtor
         */
        ~Validator() {}

        /**
         * @brief install
         *
         * Register this object with the provided system for
         * the appropriate callbacks.
         *
         * @param[in] i_system The system in which to register callbacks.
         */
        void install(FakeSystem & i_sys);

        /**
         * @brief processPutAttention Process injected attention.
         *
         * @param[in] i_sys System that modified register content.
         * @param[in] i_attn Attention that was injected.
         * @param[in] i_count number of attentions currently present.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t processPutAttention(
                FakeSystem & i_sys,
                const PRDF::AttnData & i_attn,
                uint64_t i_count);

        /**
         * @brief processClearAttention Process cleared attention.
         *
         * @param[in] i_sys System that modified register content.
         * @param[in] i_attn Attention that was cleared.
         * @param[in] i_count number of attentions currently present.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t processClearAttention(
                FakeSystem & i_sys,
                const PRDF::AttnData & i_attn,
                uint64_t i_count);

        /**
         * @brief empty
         *
         * Indicates whether or not all attentions successfully
         * completed their lifecycle.
         *
         * @return[true] All lifecycles completed.
         * @return[false] One or more lifecycles incomplete.
         */
        bool empty() const;

        /**
         * @brief dump
         *
         * Dump the list of attentions with incomplete lifecycles.
         */
        void dump() const;

    private:

        /**
         * @brief Attnetion type status association list.
         */
        PRDF::AttnList iv_properties;
};
}
#endif
