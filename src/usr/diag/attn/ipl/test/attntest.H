/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/ipl/test/attntest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#ifndef __TEST_ATTNTEST_H
#define __TEST_ATTNTEST_H

/**
 * @file attntest.H
 *
 * @brief HBATTN test utility function declarations.
 */

#include "../../common/attnfwd.H"
#include <map>
#include "util/random.H"

namespace ATTN
{

class FakePresenter;
struct AttnDataSwo;
struct AttnDataEq;
class FakeSystem;
class FakeReg;
class FakeSource;
class InjectSink;

/**
 * @brief AttnDataMap
 *
 * AttnData as key map template.
 */
template <typename T>
    class AttnDataMap :
        public std::map<PRDF::AttnData, T, AttnDataSwo>
    {

    };

/**
 * @brief getRandomAttentionType
 *
 * Obtain a random attention type.
 *
 * @return The generated attention type.
 */
PRDF::ATTENTION_VALUE_TYPE getRandomAttentionType();
}
#endif
