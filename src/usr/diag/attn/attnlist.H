/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnlist.H $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __ATTN_ATTNLIST_H
#define __ATTN_ATTNLIST_H

/**
 * @file attnlist.H
 *
 * @brief HBATTN AttentionList definition.
 */

#include "attnops.H"
#include "attnfwd.H"

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
