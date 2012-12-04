/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfErrlSmartPtr.H $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
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

        /* ctor - Initialize ptr to NULL */
        ErrlSmartPtr() : iv_errl(NULL) {};
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
        /* FIXME : Hostboot ErrorLog disallow this operation but it also doesn't seem to get used
        ErrlEntry operator*() const
            {
                return *iv_errl;
            };
        */

        /* operator ==
         *        Compare with NULL or other ptr values:
         *                if (errl == NULL)...
         */
        bool operator==(const errlHndl_t i_errl) const
            {
                return iv_errl == i_errl;
            };

        /* operator !=
         *        Compare with NULL or other ptr values:
         *                if (errl != NULL)...
         */
        bool operator!=(const errlHndl_t i_errl) const
            {
                return iv_errl != i_errl;
            };

        /* friend operator ==
         *        Compare with NULL or other ptr values:
         *                if (NULL == errl)
         */
        friend bool operator==(const errlHndl_t i_errl,
                        const ErrlSmartPtr & i_smrtptr)
            {
                return i_smrtptr == i_errl;
            };

        /* friend operator =!
         *        Compare with NULL or other ptr values:
         *                if (NULL =! errl)
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
                return NULL;
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
         *        This prevent the error log from being deleted twice or commited
         *        by the wrong component.
         */
        errlHndl_t release()
            {
                errlHndl_t l_tmp = iv_errl;
                iv_errl = NULL;
                return l_tmp;
            };

    protected:
        errlHndl_t iv_errl;

        /* void add_src()
         *         Add special SRC to error log specifying commited from smart
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
