/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfErrlSmartPtr.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

#include <prdfErrlSmartPtr.H>
#include <iipglobl.h>

namespace PRDF
{

/* void add_src()
 *         Add special SRC to error log specifying commited from smart
 *         pointer.
 */
void ErrlSmartPtr::add_src()
{

    if (iv_errl)
    {
        PRDF_ADD_SW_ERR( iv_errl, 0, PRDF_ERRLSMARTPTR, __LINE__ );
        PRDF_ADD_PROCEDURE_CALLOUT( iv_errl, SRCI_PRIORITY_MED,
                                    EPUB_PRC_SP_CODE );
    }
}

/* void commit_errl()
 *        Commit error log and delete.
 */
void ErrlSmartPtr::commit_errl()
{
    if (iv_errl)
    {
        this->add_src();

        PRDF_COMMIT_ERRL(iv_errl, ERRL_ACTION_REPORT);
    }
}

} // end namespace PRDF

