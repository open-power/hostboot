/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPllDomain.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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

#ifndef prdfPllDomain_H
#define prdfPllDomain_H

#include <prdfExtensibleDomain.H>
#include <prdfRuleChipDomain.H>
#include <prdfThresholdUtils.H>

namespace PRDF
{

//------------------------------------------------------------------------------

class PllDomain : public RuleChipDomain, public ExtensibleDomain
{
  protected:
    /**
     * @brief Constructor
     * @param i_domainId The domain ID.
     */
    explicit PllDomain(DOMAIN_ID i_domainId) :
        RuleChipDomain(i_domainId, 8), ExtensibleDomain("PllDomain")
    {}

  public:
    /** @brief Destructor. */
    virtual ~PllDomain() = default;

    /**
     * @brief  Queries this domain for active attentions of the given type.
     * @param  i_attnType The target attention type.
     * @return True, if attention of this type exists in this domain. False,
     *         otherwise.
     */
    virtual bool Query(ATTENTION_TYPE i_attnType) = 0;

    /**
     * @brief  Analyzes active attentions in this domain of the given type.
     * @param  io_sc      The service data collector.
     * @param  i_attnType The target attention type.
     * @return Non-SUCCESS, if an internal error occurred. SUCCESS, otherwise.
     */
    virtual int32_t Analyze(STEP_CODE_DATA_STRUCT& io_sc,
                            ATTENTION_TYPE i_attnType) = 0;

  protected:
#ifdef __HOSTBOOT_MODULE

    /** A simple child class of TimeBasedThreshold designed specifically for
     *  clock errors. */
    class ClockErrorTH : public TimeBasedThreshold
    {
      public:
        /** @brief Default constructor. */
        ClockErrorTH() :
            TimeBasedThreshold(PlatServices::mfgMode()
                                   ? ThresholdResolution::cv_mnfgDefault
                                   : ThresholdResolution::cv_pllDefault)
        {}
    };

#endif // __HOSTBOOT_MODULE
};

//------------------------------------------------------------------------------

} // end namespace PRDF

#endif /* prdfPllDomain_H */
