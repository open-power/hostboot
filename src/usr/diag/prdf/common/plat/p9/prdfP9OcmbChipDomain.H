/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9OcmbChipDomain.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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

#ifndef __prdfP9OcmbChipDomain_H
#define __prdfP9OcmbChipDomain_H

#include <prdfRuleChipDomain.H>

namespace PRDF
{

class OcmbChipDomain : public RuleChipDomain
{
  public:

    /**
     * @brief Constructor
     * @param i_did  The domain ID
     * @param i_size The projected size of the domain
     */
    OcmbChipDomain( DOMAIN_ID i_did, uint32_t i_size = OCMB_DOMAIN_SIZE ) :
                    RuleChipDomain( i_did, i_size )
    {}

    #ifdef __HOSTBOOT_RUNTIME

    /**
     * @brief Starts memory background scrubbing or VCM procedure for OCMB
     *        during R/R and F/O if required.
     */
    void handleRrFo();

    #endif

};

} // end namespace PRDF

#endif /* __prdfP9OcmbChipDomain_H */
