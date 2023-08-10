/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/odyssey/prdfOdyPllDomain.H $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

#pragma once

#include <prdfPllDomain.H>

namespace PRDF
{

class OdyPllDomain : public PllDomain
{
  public:
    /** @brief Default constructor. */
    OdyPllDomain() : PllDomain(CLOCK_DOMAIN_MEMBUF) {}

    /** @brief Destructor. */
    ~OdyPllDomain() = default;

    /** @brief Copy constructor. */
    OdyPllDomain(const OdyPllDomain&) = default;

    /** @brief Assignment operator. */
    OdyPllDomain& operator=(const OdyPllDomain&) = default;

    /**
     * @brief  Queries this domain for active attentions of the given type.
     * @param  i_attnType The target attention type.
     * @return True, if attention of this type exists in this domain. False,
     *         otherwise.
     */
    bool Query(ATTENTION_TYPE i_attnType) override;

    /**
     * @brief  Analyzes active attentions in this domain of the given type.
     * @param  io_sc      The service data collector.
     * @param  i_attnType The target attention type.
     * @return Non-SUCCESS, if an internal error occurred. SUCCESS, otherwise.
     */
    int32_t Analyze(STEP_CODE_DATA_STRUCT& io_sc,
                    ATTENTION_TYPE i_attnType) override;

  private:

    /** When Query() is called, this list is cleared and then populated with all
     *  chips in this domain with an active PLL attention. The list can then be
     *  used in Analyze() instead of querying all chips a second time. */
    std::vector<ExtensibleChip*> iv_pllChips;

#ifdef __HOSTBOOT_MODULE

    /** Threshold counter for PLL unlock attentions on any chip in the
     *  domain. */
    ClockErrorTH iv_thPll;

#endif // __HOSTBOOT_MODULE
};

} // end namespace PRDF
