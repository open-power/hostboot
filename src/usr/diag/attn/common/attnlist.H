/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnlist.H $                         */
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
#ifndef __ATTN_ATTNLIST_H
#define __ATTN_ATTNLIST_H

/**
 * @file attnlist.H
 *
 * @brief HBATTN AttentionList definition.
 */

#include "common/attnops.H"
#include "common/attnfwd.H"

namespace ATTN
{

/**
 * @brief AttentionList Class definition.
 *
 * Container for Attentions.  Attentions
 * kept sorted by attention type priority.
 */
class AttentionList : public std::vector<Attention>
{
    public:

        /**
         * @brief add Insert a new Attention element.
         *
         * @param[in] i_attn The attention element to add.
         */
        void add(const Attention & i_attn);

        /**
         * @brief getAttnList Convert to PRDF::AttnList.
         *
         * Elements are placed such that attentions with
         * higher priority appear before those with
         * lower priority.
         *
         * @param[out] o_dest Where PRDF::AttnData elements are placed.
         */
        void getAttnList(PRDF::AttnList & o_dest) const;

        /**
         * @brief forEach Invoke a functor on each element.
         *
         * @param[in] i_functor The functor to invoke.
         *
         * @return Functor The functor.
         */
        template<typename Functor>
            Functor forEach(Functor i_functor) const
            {
                return std::for_each(begin(), end(), i_functor);
            }

        /**
         * @brief AttnListTest Provide access to unit test.
         */
        friend class ::AttnListTest;
};
}
#endif
