/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfExtensibleDomain.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2012              */
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

#include <string.h>

#include <prdfExtensibleDomain.H>
#include <prdfPluginMap.H>
#include <prdf_service_codes.H>
#include <errlentry.H>
#include <prdfPfa5Data.h>
#include <iipglobl.h>

PrdfExtensibleDomainFunction *
    PrdfExtensibleDomain::getExtensibleFunction(const char * i_func,
                                                bool i_expectNull)
{
    PrdfExtensibleFunctionType * plugin =
            prdfGetPluginGlobalMap().getPlugins(iv_domainName)[i_func];
    if (NULL == plugin)
    {
        static PrdfPlugin<PrdfExtensibleDomain> l_nullPlugin(NULL);
        plugin = &l_nullPlugin;

        if (!i_expectNull)
        {
            errlHndl_t l_errl = NULL;
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
                          prdfErrlVer1,
                          prdfErrlString);

            PRDF_ADD_FFDC(l_errl,
                          i_func,
                          strlen(i_func),
                          prdfErrlVer1,
                          prdfErrlString);

            PRDF_COMMIT_ERRL(l_errl, ERRL_ACTION_REPORT);
            delete l_errl;
        }
    }

    return (PrdfExtensibleDomainFunction *) plugin;
}
