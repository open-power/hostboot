/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/hostboot/test/attncomp.H $                  */
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
#ifndef __TEST_ATTNCOMP_H
#define __TEST_ATTNCOMP_H

/**
 * @file attncomp.H
 *
 * @brief HBATTN test lib comparison functors.
 */

#include "attntest.H"

namespace ATTN
{

/**
 * @brief AttnDataSwo Less than comparison functor for PRDF::AttnData structs.
 */
class AttnDataSwo
{
    public:

        /**
         * @brief operator() Less than comparison for PRDF::AttnData structs.
         *
         * @param[in] i_l One of two PRDF::AttnData structs to be compared.
         * @param[in] i_r One of two PRDF::AttnData structs to be compared.
         *
         * @return bool Comparison result.
         *
         * @retval[true] i_l < i_r;
         * @retval[false] i_r < i_l;
         */
        bool operator()(
                const PRDF::AttnData & i_l,
                const PRDF::AttnData & i_r) const
        {
            return compare(i_l,  i_r) < 0;
        }
};

/**
 * @brief AttnDataEq Equality comparison predicate for PRDF::AttnData structs.
 */
class AttnDataEq
{
    public:

        /**
         * @brief operator() Equality comparison for PRDF::AttnData structs.
         *
         * @param[in] i_r One of two PRDF::AttnData structs to be compared.
         *
         * @return bool Comparison result.
         *
         * @retval[true] i_l == i_r;
         * @retval[false] i_l != i_r;
         */
        bool operator()(
                const PRDF::AttnData & i_r) const
        {
            return compare(iv_d,  i_r) == 0;
        }

        /**
         * @brief ctor
         *
         * @param[in] i_l One of two PRDF::AttnData structs to be compared.
         */
        explicit AttnDataEq(const PRDF::AttnData & i_l) :
            iv_d(i_l) {}

    private:

        /**
         * @brief iv_d
         *
         * One of two PRDF::AttnData structs to be compared.
         */
        const PRDF::AttnData & iv_d;
};
}
#endif
