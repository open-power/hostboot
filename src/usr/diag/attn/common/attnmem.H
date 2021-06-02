/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnmem.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
#ifndef __ATTN_ATTNMEM_H
#define __ATTN_ATTNMEM_H

/**
 * @file attnmem.H
 *
 * @brief HBATTN memory attention operations definition.
 */

#include "common/attnops.H"
#include <map>

namespace ATTN
{

/**
 * @brief MemOps ATTN memory attention operations definition.
 */
class MemOps : public AttentionOps
{
    private:

        /** Used to indicate that an OCMB has hit a channel fail. Because we
         *  cannot mask the OCMB chiplet level FIR, we will only handle the
         *  one channel fail before forgoing further OCMB analysis */
        std::map<TARGETING::TargetHandle_t, bool> iv_ocmbChnlFail;

    public:

        /**
         * @brief resolveOcmbs Find ocmb attentions associated with input proc.
         *
         * @param[in/out] io_attentions List of attentions
         */
        void resolveOcmbs( const TARGETING::TargetHandle_t i_proc,
                           AttentionList & io_attentions );
        /**
         * @brief Clears the iv_ocmbChnlFail map
         */
        void clearChnlFailMap() { iv_ocmbChnlFail.clear(); }

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
