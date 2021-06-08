/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10GenericDomain.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
#ifndef __prdfP10GenericDomain_H
#define __prdfP10GenericDomain_H

#include <prdfRuleChipDomain.H>

namespace PRDF
{

template <DOMAIN_ID ID>
class GenericDomain : public RuleChipDomain
{
  public:

    /**
     * @brief Constructor
     */
    GenericDomain() : RuleChipDomain( ID, domainSizeFromId(ID) )
    {}

    /**
     * @brief  Query for an attention of a specific type in this domain
     * @param  i_attnType [MACHINE_CHECK | RECOVERABLE | SPECIAL]
     * @return false
     * @note   This function will always return false. That way PRD will look
     *         for the attention via the processor chip.
     */
    virtual bool Query( ATTENTION_TYPE i_attnType )
    {  return false;  }

};

} // end namespace PRDF

#endif /* __prdfP10GenericDomain_H */
