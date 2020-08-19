/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfErrlSmartPtr.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#ifndef __PRDFERRLSMARTPTR_H
#define __PRDFERRLSMARTPTR_H

#include <errlentry.H>
#include <prdf_service_codes.H>

namespace PRDF
{
/**
 * @class ErrlSmartPtr
 *        This is a smart pointer class for errlHndl_t objects, especially for
 *        the g_prd_errl variable.  Currently, programmers can accidentially
 *        overwrite g_prd_errl and we leak a error log.  This class will keep
 *        track of the error logs and commit/delete it if it goes out of context.
 */
class ErrlSmartPtr
{
    public:

        class INVALID_TYPE_CONVERSION___SEE_COMMENTS_FOR_RELEASE_FUNCTION {};

        /* ctor - Initialize ptr to nullptr */
        ErrlSmartPtr() : iv_errl(nullptr) {};
        /* dtor - Commit remaining error log */
        ~ErrlSmartPtr() { commit_errl(); };

        /* operator =
         *        Someone attempted to overwrite the error log, commit if needed.
         */
        ErrlSmartPtr & operator=(errlHndl_t i_errl)
            {
                this->commit_errl();
                iv_errl = i_errl;

                return *this;
            };

        /* operator ->
         *        Used to do standard errlHndl_t->func() operations:
         *                errl->commit().
         */
        errlHndl_t operator->() const
            {
                return iv_errl;
            };

        /* operator*
         *        Used when dereferencing the errlHndl_t, for instance to get
         *        at the rc value:
         *                (uint32_t) *errl;
         */
        #ifdef __HOSTBOOT_MODULE
        ERRORLOG::ErrlEntry& operator*() const
        #else
        ErrlEntry& operator*() const
        #endif
            {
                return *iv_errl;
            };

        /* operator ==
         *        Compare with nullptr or other ptr values:
         *                if (errl == nullptr)...
         */
        bool operator==(const errlHndl_t i_errl) const
            {
                return iv_errl == i_errl;
            };

        /* operator !=
         *        Compare with nullptr or other ptr values:
         *                if (errl != nullptr)...
         */
        bool operator!=(const errlHndl_t i_errl) const
            {
                return iv_errl != i_errl;
            };

        /* friend operator ==
         *        Compare with nullptr or other ptr values:
         *                if (nullptr == errl)
         */
        friend bool operator==(const errlHndl_t i_errl,
                        const ErrlSmartPtr & i_smrtptr)
            {
                return i_smrtptr == i_errl;
            };

        /* friend operator =!
         *        Compare with nullptr or other ptr values:
         *                if (nullptr =! errl)
         */
        friend bool operator!=(const errlHndl_t i_errl,
                        const ErrlSmartPtr & i_smrtptr)
            {
                return i_smrtptr != i_errl;
            };

        /* operator errlHndl_t
         *        Cast to errlHndl_t object.  (needed?)
         */
        operator errlHndl_t()
            {
                return iv_errl;
            };

        operator INVALID_TYPE_CONVERSION___SEE_COMMENTS_FOR_RELEASE_FUNCTION *()
            {
                return nullptr;
            };

        /* errlHndl_t release
         *        Used when error log is leaving PRD's context (returned to
         *        cecserver):
         *                return errl.release();
         *        instead of:
         *                return errl;
         *
         *        Or, to delete the error log:
         *                delete errl.release();
         *
         *        This prevent the error log from being deleted twice or committed
         *        by the wrong component.
         */
        errlHndl_t release()
            {
                errlHndl_t l_tmp = iv_errl;
                iv_errl = nullptr;
                return l_tmp;
            };

    protected:
        errlHndl_t iv_errl;

        /* void add_src()
         *         Add special SRC to error log specifying committed from smart
         *         pointer.
         */
        void add_src();

        /* void commit_errl()
         *        Commit error log and delete.
         */
        void commit_errl();

};

} // end namespace PRDF

#endif
