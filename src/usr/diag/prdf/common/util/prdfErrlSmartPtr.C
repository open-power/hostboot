/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfErrlSmartPtr.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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

#include <prdfErrlSmartPtr.H>
#include <prdfGlobal.H>
#include <prdfErrlUtil.H>

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

