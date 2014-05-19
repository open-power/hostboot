/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfExtensibleDomain.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2009,2014              */
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
