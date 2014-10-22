/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/attnsvc.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#ifndef __ATTN_ATTNSVC_H
#define __ATTN_ATTNSVC_H

/**
 * @file attnsvc.H
 *
 * @brief HBRT ATTN background service class definition.
 */

#include "common/attnsvc_common.H"

namespace ATTN
{

/**
 * @brief Service Host attention handler background service class definition.
 */
class Service : public ServiceCommon
{
    public:

        /**
         * @brief disable attentions.
         *
         * @post attentions are disabled.  All resources reclaimed.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] No error.
         * @retval[!0] Unexpected error.
         */
        errlHndl_t disableAttns();

        /**
         * @brief enable attentions.
         *
         * @post ServiceCommon started.
         *
         * @return errlHndl_t Error log.
         *
         * @retval[0] no error
         * @retval[!0] unexpected error
         */
        errlHndl_t enableAttns();

        /**
         * @brief ctor
         */
        Service() {};

        /**
         * @brief dtor
         */
        ~Service();

    private:

        /**
         * @brief copy disabled
         */
        Service(const Service &);

        /**
         * @brief assignment disabled
         */
        Service &operator=(const Service &);

};

}
#endif
