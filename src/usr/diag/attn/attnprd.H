/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/attn/attnprd.H $
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
#ifndef __ATTN_ATTNPRD_H
#define __ATTN_ATTNPRD_H

/**
 * @file attnprd.H
 *
 * @brief HBATTN PRD wrapper class definitions.
 */

#include "attnfwd.H"

namespace ATTN
{

/**
 * @brief PrdImpl PRD implementation interface requirement.
 *
 * Default implementation forwards call to real PRD.
 */
class PrdImpl
{
    public:

        /**
         * @brief callPrd Forward PRD call to real PRD.
         *
         * @param[in] i_attentions List of attentions for PRD to analyze.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        virtual errlHndl_t callPrd(const AttentionList & i_attentions);

        /**
         * @brief dtor
         */
        virtual ~PrdImpl() {}

        /**
         * @brief ctor
         */
        PrdImpl() {}
};

/**
 * @brief PrdWrapper Hold the installed prd implementation.
 */
class PrdWrapper
{
    public:

        /**
         * @brief callPrd Route PRD call to the active PRD implementation.
         *
         * @param[in] i_attentions List of attentions for PRD to analyze.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error occurred.
         * @retval[!0] Unexpected error occurred.
         */
        errlHndl_t callPrd(const AttentionList & i_attentions);

        /**
         * @brief setImpl Set the active PRD implementation.
         *
         * @param[in] i_prd The PRD implementation to make active.
         */
        void setImpl(PrdImpl & i_prd)
        {
            iv_impl = &i_prd;
        }

        /**
         * @brief ctor
         */
        PrdWrapper();

    private:

        /**
         * @brief iv_impl The active PRD implementation.
         */
        PrdImpl * iv_impl;

        /**
         * @brief copy Disabled.
         */
        PrdWrapper(const PrdWrapper &);

        /**
         * @brief assignment Disabled.
         */
        PrdWrapper & operator=(const PrdWrapper &);
};
}
#endif
