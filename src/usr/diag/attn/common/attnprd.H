/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/common/attnprd.H $                          */
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
#ifndef __ATTN_ATTNPRD_H
#define __ATTN_ATTNPRD_H

/**
 * @file attnprd.H
 *
 * @brief HBATTN PRD wrapper class definitions.
 */

#include "common/attnfwd.H"

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
         * @brief installPrd
         *
         * Make this the active PRD implementation.
         */
        void installPrd();

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
