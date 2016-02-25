/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfRuleChipDomain.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#ifndef __prdfP9RuleChipDomain_H
#define __prdfP9RuleChipDomain_H

#include <iipDomainContainer.h>
#include <prdfRuleChip.H>

namespace PRDF
{

class RuleChipDomain : public DomainContainer<RuleChip>
{
  public:

    enum DefaultDomainSize
    {
        // At minimum, should allocate for a fully configured single P9 Nimbus
        // system.

        PROC_DOMAIN_SIZE   = 1,
        EQ_DOMAIN_SIZE     = PROC_DOMAIN_SIZE * 6,
        EX_DOMAIN_SIZE     = EQ_DOMAIN_SIZE * 2,
        EC_DOMAIN_SIZE     = EX_DOMAIN_SIZE * 2,
        OBUS_DOMAIN_SIZE   = PROC_DOMAIN_SIZE * 2,
        XBUS_DOMAIN_SIZE   = PROC_DOMAIN_SIZE * 2,
        PEC_DOMAIN_SIZE    = PROC_DOMAIN_SIZE * 3,
        PHB_DOMAIN_SIZE    = PROC_DOMAIN_SIZE * 6,
        CAPP_DOMAIN_SIZE   = PROC_DOMAIN_SIZE * 2,
        MCBIST_DOMAIN_SIZE = PROC_DOMAIN_SIZE * 2,
        MCS_DOMAIN_SIZE    = MCBIST_DOMAIN_SIZE * 2,
        MCA_DOMAIN_SIZE    = MCS_DOMAIN_SIZE * 2,

        MEMBUF_DOMAIN_SIZE = MCS_DOMAIN_SIZE,
        MBA_DOMAIN_SIZE    = MEMBUF_DOMAIN_SIZE * 2,

        TOTAL_CHIPS = PROC_DOMAIN_SIZE +
                      EQ_DOMAIN_SIZE + EX_DOMAIN_SIZE + EC_DOMAIN_SIZE +
                      OBUS_DOMAIN_SIZE + XBUS_DOMAIN_SIZE +
                      PEC_DOMAIN_SIZE + PHB_DOMAIN_SIZE +
                      CAPP_DOMAIN_SIZE +
                      MCBIST_DOMAIN_SIZE + MCS_DOMAIN_SIZE + MCA_DOMAIN_SIZE +
                      MEMBUF_DOMAIN_SIZE + MBA_DOMAIN_SIZE,

        TOTAL_DOMAINS = 14,
    };

    /** @fn RuleChipDomain
     *  @brief Constructor
     *  @param DOMAIN_ID - the domain ID
     *  @param uint32_t - the projected size of the domain
     */
    RuleChipDomain( DOMAIN_ID i_did, uint32_t i_size ) :
        DomainContainer<RuleChip>( i_did, i_size )
    {}

    /** @fn Query
     *  @brief Query for an attention of a specific type in this domain
     *  @param ATTENTION_TYPE [MACHINE_CHECK | RECOVERABLE | SPECIAL]
     *  @return TRUE if a chip in the domain is at attention.
     */
    virtual bool Query( ATTENTION_TYPE i_attnType);

  protected:

    /** @fn Order
     *  @brief Prioritizes the components of this domain for Analysis
     *  @param ATTENTION_TYPE [MACHINE_CHECK | RECOVERABLE | SPECIAL]
     */
    virtual void Order( ATTENTION_TYPE i_attnType);
};

} // end namespace PRDF

#endif /* __prdfP9RuleChipDomain_H */
