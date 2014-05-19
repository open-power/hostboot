/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/test/attnfakeprd.H $                        */
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
#ifndef __TEST_ATTNFAKEPRD_H
#define __TEST_ATTNFAKEPRD_H

/**
 * @file attnfakeprd.H
 *
 * @brief HBATTN fake PRD class definitions.
 */

#include "attntest.H"
#include "../attnprd.H"

namespace ATTN
{

/**
 * @brief FakePrd
 *
 * Basic PRD implementation that eventually clears every attention it
 * receives.
 */
class FakePrd : public PrdImpl
{
    public:

        /**
         * @brief ctor
         *
         * @param[in] i_injectSink The system where attentions
         *                     should be cleared.
         */
        explicit FakePrd(InjectSink & i_injectSink);

        /**
         * @brief dtor
         */
        ~FakePrd() {}

        /**
         * @brief callPrd Simulate a call to PRD.
         *
         * Sleeps random intervals, to simulate PRD processing times.  Periodically
         * does not clear some attentions, to simulate real PRD behavior.
         *
         * @param[in] i_attentions List of attentions for PRD to analyze.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t callPrd(const AttentionList & i_attentions);

    private:

        /**
         * @brief iv_injectSink The system where attentions should
         *                  be cleared.
         */
        InjectSink * iv_injectSink;
};
}
#endif
