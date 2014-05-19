/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnfakeelement.H $                    */
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
#ifndef __TEST_ATTNFAKEELEMENT_H
#define __TEST_ATTNFAKEELEMENT_H

/**
 * @file attnfakeelement.H
 *
 * @brief HBATTN fake system element class definitions.
 */

#include "attntest.H"

namespace ATTN
{

/**
 * @brief FakeSource Attention source interface.
 *
 * Interface definition for classes wishing to attach logic
 * to FakeSystem error injections.
 */
class FakeSource
{
    public:

        /**
         * @brief dtor
         */
        virtual ~FakeSource() {}

        /**
         * @brief processPutAttention Process injected attention.
         *
         * @param[in] i_sys System on which attention was injected.
         * @param[in] i_attn Attention that was injected.
         * @param[in] i_count number of attentions currently present.
         */
        virtual errlHndl_t processPutAttention(
                FakeSystem & i_sys,
                const PRDF::AttnData & i_attn,
                uint64_t i_count) = 0;

        /**
         * @brief processClearAttention Process cleared attention.
         *
         * @param[in] i_sys System on which attention was cleared.
         * @param[in] i_attn Attention that was cleared.
         * @param[in] i_count number of attentions currently present.
         */
        virtual errlHndl_t processClearAttention(
                FakeSystem & i_sys,
                const PRDF::AttnData & i_attn,
                uint64_t i_count) = 0;
};

/**
 * @brief FakeReg Register interface.
 *
 * Interface definition for classes wishing to attach logic
 * to FakeSystem register modifications.
 */
class FakeReg
{
    public:

        /**
         * @brief dtor
         */
        virtual ~FakeReg() {}

        /**
         * @brief processPutReg Process modified register content.
         *
         * @param[in] i_sys System that modified register content.
         * @param[in] i_target Target whose registers were modified.
         * @param[in] i_address Address of register that was modified.
         * @param[in] i_new Register content after modification.
         * @param[in] i_old Register content before modification.
         */
        virtual errlHndl_t processPutReg(
                FakeSystem & i_sys,
                TARGETING::TargetHandle_t i_target,
                uint64_t i_address,
                uint64_t i_new,
                uint64_t i_old) = 0;
};
}
#endif
