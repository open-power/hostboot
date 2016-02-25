/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9EqDomain.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#ifndef __prdfP9EqDomain_H
#define __prdfP9EqDomain_H

#include <prdfRuleChipDomain.H>

namespace PRDF
{

class EqDomain : public RuleChipDomain
{
  public:

    /**
     * @brief Constructor
     * @param i_did  The domain ID
     * @param i_size The projected size of the domain
     */
    EqDomain( DOMAIN_ID i_did, uint32_t i_size = EQ_DOMAIN_SIZE ) :
        RuleChipDomain( i_did, i_size )
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

#endif /* __prdfP9EqDomain_H */
