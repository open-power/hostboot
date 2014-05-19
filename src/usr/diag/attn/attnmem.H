/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnmem.H $                                 */
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
