/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfExtensibleDomain.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2013              */
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

#ifndef __PRDFEXTENSIBLEDOMAIN_H
#define __PRDFEXTENSIBLEDOMAIN_H

#include <prdfPluginDef.H>
#include <prdfExtensibleChip.H>

namespace PRDF
{

class ExtensibleDomain
{
    public:
        ExtensibleDomain(const char * i_domainName) :
                iv_domainName(i_domainName), iv_dataBundle(NULL) {};

        virtual ~ExtensibleDomain()
            {
                if (NULL != iv_dataBundle)
                {
                    delete iv_dataBundle;
                    iv_dataBundle = NULL;
                }
            };

        virtual ExtensibleDomainFunction *
            getExtensibleFunction(const char * i_func,
                                  bool i_expectNull = false);

        virtual DataBundle *& getDataBundle() { return iv_dataBundle; };

    private:
        const char * iv_domainName;
        DataBundle * iv_dataBundle;

};

} // end namespace PRDF

#endif //__PRDFEXTENSIBLEDOMAIN_H
