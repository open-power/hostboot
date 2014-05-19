/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnops.H $                                 */
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
#ifndef __ATTN_ATTNOPS_H
#define __ATTN_ATTNOPS_H

/**
 * @file attnops.H
 *
 * @brief HBATTN Attention and AttentionOps definitions.
 */

#include "attnfwd.H"

namespace ATTN
{

/**
 * @brief AttentionOps Interface specification.
 *
 * For types that implement mask, unmask and query operations.
 */
class AttentionOps
{
    public:

        /**
         * @brief dtor
         */
        virtual ~AttentionOps() {}

        /**
         * @brief AttnOpsTest Provide access to unit test.
         */
        friend class AttnOpsTest;
};

/**
 * @brief Attention Operation router.
 *
 * Routes Attention mask, unmask and query operations
 * to the correct handler.
 */
class Attention
{
    public:

        /**
         * @brief getData Convert this attention to PRDF::AttnData.
         *
         * @param[out] o_data Converted attention.
         */
        void getData(PRDF::AttnData & o_data) const
        {
            o_data = iv_data;
        }

        /**
         * @brief compare Compare two attentions.
         *
         * @param[in] i_rhs The other attention.
         *
         * @retval[-1] This attention is less than the other attention.
         * @retval[1] This attention is greather than the other attention.
         * @retval[0] This attention is equivalent to the other attention.
         */
        int64_t compare(const Attention & i_rhs) const;

        /**
         * @brief ctor
         *
         * @param[in] i_data The PRDF::AttnData representation of the attention.
         * @param[in] i_ops The AttentionOps instance to which operations
         *                  should be routed.
         */
        Attention(const PRDF::AttnData & i_data,
                AttentionOps * i_ops)
            : iv_data(i_data), iv_ops(i_ops) {}

    private:

        /**
         * @brief iv_data The PRDF::AttnData representation of the attention.
         */
        PRDF::AttnData iv_data;

        /**
         * @brief iv_ops The AttentionOps instance to which operations
         *               should be routed.
         */
        AttentionOps * iv_ops;

        /**
         * @brief AttnOpsTest Provide access to unit test.
         */
        friend class ::AttnOpsTest;
};

/**
 * @brief operator< Test two attentions for less than.
 *
 * @param[in] i_lhs The left hand side of the comparison.
 * @param[in] i_rhs The right hand side of the comparison.
 *
 * @retval[true] i_lhs is less than i_rhs.
 * @retval[false] i_lhs is not less than i_rhs.
 */
inline bool operator<(const Attention & i_lhs, const Attention & i_rhs)
{
    return i_lhs.compare(i_rhs) < 0;
}
}
#endif
