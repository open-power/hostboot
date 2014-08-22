/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/test/attninject.H $                */
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
