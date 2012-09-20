/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/attnlistutil.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef __ATTN_ATTNLISTUTIL_H
#define __ATTN_ATTNLISTUTIL_H

/**
 * @file attnlistutil.H
 *
 * @brief HBATTN AttentionList utility type definitions.
 */

#include "attnfwd.H"
#include "attnops.H"

namespace ATTN
{

/**
 * @brief MaskFunct Mask attentions functor.
 */
struct MaskFunct
{
    errlHndl_t err;

    MaskFunct() : err(0) {}

    void operator()(const Attention & i_attn)
    {
        if(!err)
        {
            err = i_attn.mask();
        }
    }
};

/**
 * @brief UnmaskFunct Unmask attentions functor.
 */
struct UnmaskFunct
{
    errlHndl_t err;

    UnmaskFunct() : err(0) {}

    void operator()(const Attention & i_attn)
    {
        if(!err)
        {
            err = i_attn.unmask();
        }
    }
};

/**
 * @brief ClearedPredicate Attention query predicate.
 */
struct ClearedPredicate
{
    errlHndl_t err;

    ClearedPredicate() : err(0) {}

    bool operator()(const Attention & i_attn)
    {
        bool attnIsOn = false, condition = false;

        if(!err)
        {
            err = i_attn.query(attnIsOn);

            if(!err && !attnIsOn)
            {
                condition = true;
            }
        }

        return condition;
    }
};
}
#endif
