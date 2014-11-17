/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/test/attnfakeprd.H $                */
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
#ifndef __TEST_ATTNFAKEPRD_H
#define __TEST_ATTNFAKEPRD_H

/**
 * @file attnfakeprd.H
 *
 * @brief HBATTN fake PRD class definitions.
 */

#include "../../common/attnprd.H"
#include "../../common/attnlist.H"

namespace ATTN
{

/**
 * @brief FakePrd
 *
 * Basic PRD implementation that verifies attention list it
 * receives with expected attention list.
 */
class FakePrd : public PrdImpl
{
    public:

        /**
         * @brief ctor
         */
        FakePrd(){};

        /**
         * @brief set expected attention list for test case.
         *
         * @param[in] i_attnList List of attentions for PRD to analyze.
         */
        void setExpectedAttn( AttentionList &i_attnList );

        /**
         * @brief dtor
         */
        ~FakePrd() {}

        /**
         * @brief callPrd Simulate a call to PRD.
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
        AttentionList iv_expectedAttns;

};
}
#endif
