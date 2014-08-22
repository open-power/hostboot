/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/test/attnmeminject.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __TEST_ATTNMEMINJECT_H
#define __TEST_ATTNMEMINJECT_H

/**
 * @file attnmeminject.H
 *
 * @brief
 */

#include "attntest.H"
#include "attncomp.H"
#include "attninject.H"

namespace ATTN
{

/**
 * @brief InjectSink Attention inject interface.
 *
 * Turns the MCI FIR on or off.
 */
class MemInjectSink : public InjectSink
{
    public:

        /**
         * @brief dtor
         */
        ~MemInjectSink() {}

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
        errlHndl_t putAttentions(
                const PRDF::AttnList & i_list);

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
        errlHndl_t clearAttention(
                const PRDF::AttnData & i_attn);

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
        errlHndl_t clearAllAttentions(
                const PRDF::AttnData & i_attn);

    private:

        /**
         * @brief putAttention
         *
         * Instruct the system to inject the specified attention.
         *
         * @param[in] i_attn The attention to inject.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t putAttention(const PRDF::AttnData & i_attn);

        AttnDataMap<uint64_t> iv_map;

        mutex_t iv_mutex;
};
}
#endif
