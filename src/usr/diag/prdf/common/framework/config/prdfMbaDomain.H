/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/config/prdfMbaDomain.H $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

#ifndef __PRDFMBADOMAIN_H
#define __PRDFMBADOMAIN_H

#include <prdfRuleChipDomain.H>

namespace PRDF
{

class MbaDomain : public RuleChipDomain
{
  public:

    /**
     * @brief Constructor
     * @param i_did  The domain ID
     * @param i_size The projected size of the domain
     */
    MbaDomain( DOMAIN_ID i_did, uint32_t i_size = MBA_DOMAIN_SIZE ) :
        RuleChipDomain( i_did, i_size )
    {}

    /**
     * @brief  Query for an attention of a specific type in this domain
     * @param  i_attnType [MACHINE_CHECK | RECOVERABLE | SPECIAL]
     * @return false
     * @note   This function will always return false. That way PRD will look
     *         for the attention via the memory buffer chip.
     */
    virtual bool Query( ATTENTION_TYPE i_attnType )
    {  return false;  }

};

} // end namespace PRDF

#endif /* __PRDFMBADOMAIN_H */

