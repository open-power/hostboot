/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10ProcDomain.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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

#ifndef __prdfP10ProcDomain_H
#define __prdfP10ProcDomain_H

#include <prdfRuleChipDomain.H>

namespace PRDF
{

class ProcDomain : public RuleChipDomain
{
  public:

    /**
     * @brief Constructor
     * @param i_did  The domain ID
     * @param i_size The projected size of the domain
     */
    ProcDomain( DOMAIN_ID i_did, uint32_t i_size = PROC_DOMAIN_SIZE ) :
                RuleChipDomain( i_did, i_size )
    {}

    /**
     * @brief Determin which chip to Analyze and call it's Analyze() function
     * @param serviceData   Service data collector
     * @param attentionType attention type
     * @return return code (0 == SUCCESS)
     */
     virtual int32_t Analyze( STEP_CODE_DATA_STRUCT & serviceData,
                              ATTENTION_TYPE attentionType ) override;

protected:

    /**
     * @brief Determine which chip to Analyze and call it's Analyze() function
     * @param  attentionType Attention of the chip
     * @return SUCCESS
     */
     virtual void Order(ATTENTION_TYPE attentionType) override;

    /**
     @brief Determine which chip to Analyze and put at front of list.
     */
     virtual void SortForXstop();
     virtual void SortForRecov();
};

} // end namespace PRDF

#endif /* __prdfP10ProcDomain_H */
