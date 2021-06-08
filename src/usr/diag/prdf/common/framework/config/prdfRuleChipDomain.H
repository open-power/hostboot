/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfRuleChipDomain.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

#ifndef __prdfRuleChipDomain_H
#define __prdfRuleChipDomain_H

#include <iipDomainContainer.h>
#include <prdfRuleChip.H>

namespace PRDF
{

class RuleChipDomain : public DomainContainer<RuleChip>
{
  public:

    enum DefaultDomainSize
    {
        // At minimum, should allocate for a fully configured single P10 system.

        PROC_DOMAIN_SIZE   = 1,
        EQ_DOMAIN_SIZE     = PROC_DOMAIN_SIZE * 6,
        NMMU_DOMAIN_SIZE   = PROC_DOMAIN_SIZE * 2,
        PAUC_DOMAIN_SIZE   = PROC_DOMAIN_SIZE * 4,
        IOHS_DOMAIN_SIZE   = PAUC_DOMAIN_SIZE * 4,
        PAU_DOMAIN_SIZE    = IOHS_DOMAIN_SIZE,
        CORE_DOMAIN_SIZE   = PROC_DOMAIN_SIZE * 4,
        PEC_DOMAIN_SIZE    = PROC_DOMAIN_SIZE * 3,
        PHB_DOMAIN_SIZE    = PROC_DOMAIN_SIZE * 6,
        MC_DOMAIN_SIZE     = PROC_DOMAIN_SIZE * 2,
        MCC_DOMAIN_SIZE    = MC_DOMAIN_SIZE * 2,
        OMIC_DOMAIN_SIZE   = MC_DOMAIN_SIZE * 3,
        OMI_DOMAIN_SIZE    = MCC_DOMAIN_SIZE * 2,
        OCMB_DOMAIN_SIZE   = OMI_DOMAIN_SIZE,

        TOTAL_CHIPS = PROC_DOMAIN_SIZE + IOHS_DOMAIN_SIZE + NMMU_DOMAIN_SIZE +
                      PAUC_DOMAIN_SIZE + PAU_DOMAIN_SIZE +
                      EQ_DOMAIN_SIZE + CORE_DOMAIN_SIZE +
                      PEC_DOMAIN_SIZE + PHB_DOMAIN_SIZE + MC_DOMAIN_SIZE +
                      MCC_DOMAIN_SIZE + OMIC_DOMAIN_SIZE +
                      OCMB_DOMAIN_SIZE,

        TOTAL_DOMAINS = 13,
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

    /**
     *  @brief Returns the appropriate domain size based on input domain ID
     *  @param i_id Domain ID to get the size from
     *  @return The domain size for the input domain ID
     */
    DefaultDomainSize domainSizeFromId( DOMAIN_ID i_id )
    {
        DefaultDomainSize o_size = PROC_DOMAIN_SIZE;

        switch ( i_id )
        {
            case PROC_DOMAIN: o_size = PROC_DOMAIN_SIZE; break;
            case EQ_DOMAIN:   o_size = EQ_DOMAIN_SIZE;   break;
            case NMMU_DOMAIN: o_size = NMMU_DOMAIN_SIZE; break;
            case PAUC_DOMAIN: o_size = PAUC_DOMAIN_SIZE; break;
            case IOHS_DOMAIN: o_size = IOHS_DOMAIN_SIZE; break;
            case PAU_DOMAIN:  o_size = PAU_DOMAIN_SIZE;  break;
            case CORE_DOMAIN: o_size = CORE_DOMAIN_SIZE; break;
            case PEC_DOMAIN:  o_size = PEC_DOMAIN_SIZE;  break;
            case PHB_DOMAIN:  o_size = PHB_DOMAIN_SIZE;  break;
            case MC_DOMAIN:   o_size = MC_DOMAIN_SIZE;   break;
            case MCC_DOMAIN:  o_size = MCC_DOMAIN_SIZE;  break;
            case OMIC_DOMAIN: o_size = OMIC_DOMAIN_SIZE; break;
            case OCMB_DOMAIN: o_size = OCMB_DOMAIN_SIZE; break;
            default:
                PRDF_ERR( "RuleChipDomain::domainSizeFromId: Invalid Domain "
                          "ID: 0x%x", i_id );
                PRDF_ASSERT(false);
                break;
        }

        return o_size;
    }
};

} // end namespace PRDF

#endif /* __prdfRuleChipDomain_H */
