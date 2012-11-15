/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfRuleChipDomain.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2008,2012              */
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

#ifndef PRDFRULECHIPDOMAIN_H
#define PRDFRULECHIPDOMAIN_H

#include <iipDomainContainer.h>
#include <prdfRuleChip.H>

class PrdfRuleChipDomain : public DomainContainer<PrdfRuleChip>
{
  public:

    enum DefaultDomainSize
    {
        // At minimum, should allocate for a fully configured single P8 murano
        // system.

        PROC_DOMAIN_SIZE   = 1,
        EX_DOMAIN_SIZE     = PROC_DOMAIN_SIZE * 6,
        MCS_DOMAIN_SIZE    = PROC_DOMAIN_SIZE * 4,

        MEMBUF_DOMAIN_SIZE = MCS_DOMAIN_SIZE,
        MBA_DOMAIN_SIZE    = MEMBUF_DOMAIN_SIZE * 2,

        TOTAL_CHIPS = PROC_DOMAIN_SIZE   + EX_DOMAIN_SIZE  + MCS_DOMAIN_SIZE +
                      MEMBUF_DOMAIN_SIZE + MBA_DOMAIN_SIZE,

        TOTAL_DOMAINS = 5,
    };

    /** @fn PrdfRuleChipDomain
     *  @brief Constructor
     *  @param DOMAIN_ID - the domain ID
     *  @param uint32_t - the projected size of the domain
     */
    PrdfRuleChipDomain( DOMAIN_ID i_did, uint32_t i_size ) :
        DomainContainer<PrdfRuleChip>( i_did, i_size )
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

#endif /* PRDFRULECHIPDOMAIN_H */
