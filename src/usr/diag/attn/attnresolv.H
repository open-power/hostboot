/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnresolv.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __ATTN_ATTNRESOLV_H
#define __ATTN_ATTNRESOLV_H

/**
 * @file attnresolv.H
 *
 * @brief HBATTN Resolver wrapper class definitions.
 */

#include "attnfwd.H"

namespace ATTN
{

/**
 * @brief Resolver Resolver implementation interface requirement.
 *
 * Default implementation forwards call to Proc & Mem resolvers.
 */
class Resolver
{
    public:

        /**
         * @brief resolve Find attentions of the supplied type on the
         *        supplied target.
         *
         * @param[in] i_proc The proc on which to look for attentions.
         * @param[out] o_attentions Where to put attentions when found.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t resolve(
                TARGETING::TargetHandle_t i_proc,
                AttentionList & o_attentions);

        /**
         * @brief dtor
         */
        virtual ~Resolver() {}

        /**
         * @brief ctor
         */
        Resolver() {}
};

/**
 * @brief ResolverWrapper Hold the installed resolver implementation.
 */
class ResolverWrapper
{
    public:

        /**
         * @brief resolve Find attentions of the supplied type on the
         *        supplied target.
         *
         * @param[in] i_proc The proc on which to look for attentions.
         * @param[out] o_attentions Where to put attentions when found.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t resolve(
                TARGETING::TargetHandle_t i_proc,
                AttentionList & o_attentions);

        /**
         * @brief setImpl Set the active PRD implementation.
         *
         * @param[in] i_prd The PRD implementation to make active.
         */
        void setImpl(Resolver & i_resolver)
        {
            iv_impl = &i_resolver;
        }

        /**
         * @brief ctor
         */
        ResolverWrapper();

    private:

        /**
         * @brief iv_impl The active resolver implementation.
         */
        Resolver * iv_impl;

        /**
         * @brief copy Disabled.
         */
        ResolverWrapper(const ResolverWrapper &);

        /**
         * @brief assignment Disabled.
         */
        ResolverWrapper & operator=(const ResolverWrapper &);
};
}
#endif
