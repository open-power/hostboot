/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfExtensibleDomain.H $ */
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

#ifndef __PRDFEXTENSIBLEDOMAIN_H
#define __PRDFEXTENSIBLEDOMAIN_H

#include <prdfPluginDef.H>
#include <prdfExtensibleChip.H>

class PrdfExtensibleDomain
{
    public:
        PrdfExtensibleDomain(const char * i_domainName) :
                iv_domainName(i_domainName), iv_dataBundle(NULL) {};

        virtual ~PrdfExtensibleDomain()
            {
                if (NULL != iv_dataBundle)
                {
                    delete iv_dataBundle;
                    iv_dataBundle = NULL;
                }
            };

        virtual PrdfExtensibleDomainFunction *
            getExtensibleFunction(const char * i_func,
                                  bool i_expectNull = false);

        virtual PrdfDataBundle *& getDataBundle() { return iv_dataBundle; };

    private:
        const char * iv_domainName;
        PrdfDataBundle * iv_dataBundle;

};

#endif //__PRDFEXTENSIBLEDOMAIN_H
