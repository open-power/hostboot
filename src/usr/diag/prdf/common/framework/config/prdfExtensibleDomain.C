/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfExtensibleDomain.C $ */
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

#include <string.h>

#include <prdfExtensibleDomain.H>
#include <prdfPluginMap.H>
#include <prdf_service_codes.H>
#include <errlentry.H>
#include <prdfPfa5Data.h>
#include <prdfErrlUtil.H>
#include <prdfGlobal.H>

namespace PRDF
{

ExtensibleDomainFunction *
        ExtensibleDomain::getExtensibleFunction(const char * i_func,
                                                bool i_expectNull)
{
    ExtensibleFunctionType * plugin =
            getPluginGlobalMap().getPlugins(iv_domainName)[i_func];
    if (nullptr == plugin)
    {
        static Plugin<ExtensibleDomain> l_nullPlugin(nullptr);
        plugin = &l_nullPlugin;

        if (!i_expectNull)
        {
            errlHndl_t l_errl = nullptr;
            PRDF_CREATE_ERRL(l_errl,
                             ERRL_SEV_UNRECOVERABLE,
                             ERRL_ETYPE_NOT_APPLICABLE,
                             SRCI_ERR_INFO,
                             SRCI_NO_ATTR,
                             PRDF_EXTENSIBLEDOMAIN,
                             LIC_REFCODE,
                             PRDF_CODE_FAIL,
                             __LINE__,
                             0, 0, 0);
            PRDF_ADD_FFDC(l_errl,
                          iv_domainName,
                          strlen(iv_domainName),
                          ErrlVer1,
                          ErrlString);

            PRDF_ADD_FFDC(l_errl,
                          i_func,
                          strlen(i_func),
                          ErrlVer1,
                          ErrlString);

            PRDF_COMMIT_ERRL(l_errl, ERRL_ACTION_REPORT);
        }
    }

    return (ExtensibleDomainFunction *) plugin;
}

} // end namespace PRDF

