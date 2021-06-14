/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPllDomain.H $               */
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

#ifndef prdfPllDomain_H
#define prdfPllDomain_H

#include <iipDomain.h>
#include <iipResolutionFactory.h>
#include <prdfExtensibleDomain.H>
#include <prdfRuleChipDomain.H>
#include <prdfThresholdUtils.H>

namespace PRDF
{

//------------------------------------------------------------------------------

class PllErrTypes
{
  public: // Consts, enums, etc.

    // Each value in this enum represents a bit in iv_flags.
    enum Types
    {
        PLL_UNLOCK_0    = 0x01,
        PLL_UNLOCK_1    = 0x02,
        RCS_OSC_ERROR_0 = 0x04,
        RCS_OSC_ERROR_1 = 0x08,
        RCS_UNLOCKDET_0 = 0x10,
        RCS_UNLOCKDET_1 = 0x20,
    };

  public: // Constructors, destructor, assignment, etc.

    /** @brief Default constructor. */
    PllErrTypes() = default;

    /** @brief Destructor. */
    ~PllErrTypes() = default;

    /** @brief Copy constructor. */
    PllErrTypes(const PllErrTypes&) = default;

    /** @brief Assignment operator. */
    PllErrTypes& operator=(const PllErrTypes&) = default;

  private: // Instance variables

    /** A bitwise mask for all error types that are currently reporting
     *  attentions. See enum Types for the list of supported error types. */
    unsigned int iv_types = 0;

  public: // Member functions

    /** @return True, if the given type is currently set in iv_types. */
    bool query( Types i_types ) const { return ( 0 != (iv_types & i_types) ); }

    /** @return True, if any type is currently set in iv_types. */
    bool any() const { return ( 0 != iv_types ); }

    /** @brief Sets the given type in iv_types. */
    void set( Types i_types ) { iv_types |= i_types; }

    /** @brief Clears the given type in iv_types. */
    void clear( Types i_types ) { iv_types &= ~i_types; }

    /** @brief Clears all types in iv_types. */
    void clear() { iv_types = 0; }

    /** @brief Bitwise OR operator. */
    PllErrTypes operator|(const PllErrTypes& i_types) const
    {
        PllErrTypes o_types;
        o_types.iv_types = this->iv_types | i_types.iv_types;
        return o_types;
    }
};

//------------------------------------------------------------------------------

class PllDomain : public RuleChipDomain, public ExtensibleDomain
{
  public:

    /**
     * @brief Constructor
     * @param i_domainId The domain ID.
     */
    explicit PllDomain(DOMAIN_ID i_domainId);

  /**
   *  @brief Perform any initialization required by the hardware
   *  @returns error code
   *  @post  PLL errors cleared in hardware.
   */
  virtual int32_t Initialize(void);

  /**
   * @brief Query if anything in this domain is at the attention type specified
   * @param Attention type to query for. (@see iipsdbug.h)
   * @returns [true|false]
   * @pre Initialize()
   */
  virtual bool Query(ATTENTION_TYPE attentionType);

  /**
   * @brief Analyze errors within the domain
   * @param service data collector
   * @param attentiont type (@see iipsdbug.h)
   * @returns service data collector - completed
   * @return return code
   * @pre Initialize(); Query() == true
   * @post domain element order may be modified.
   */
  virtual int32_t Analyze( STEP_CODE_DATA_STRUCT & serviceData,
                           ATTENTION_TYPE attentionType );

protected:

  /**
   * @brief Order the domain - with detecting element at the top
   * @param Attention type (@see iipsdbug.h)
   * @post domain elemenet order may be altered
   * @note this is called by Analyze()
   */
  virtual void Order(ATTENTION_TYPE attentionType);

private:  // Data

  enum { CONTAINER_SIZE = 8 };

    #ifdef __HOSTBOOT_MODULE

    /** A simple child class of TimeBasedThreshold designed specifically clock
     *  errors. */
    class ClockErrorTH : public TimeBasedThreshold
    {
      public:
        /** @brief Default constructor. */
        ClockErrorTH() : TimeBasedThreshold(PlatServices::mfgMode()
                                        ? ThresholdResolution::cv_mnfgDefault
                                        : ThresholdResolution::cv_pllDefault)
        {}
    };

    /** Threshold counters for RCS OSC error and RCS unlock detect attentions
     *  (from clock 0) on each chip in the domain. */
    std::map<ExtensibleChip*, ClockErrorTH> iv_thRcsClk0;

    /** Threshold counters for RCS OSC error and RCS unlock detect attentions
     *  (from clock 1) on each chip in the domain. */
    std::map<ExtensibleChip*, ClockErrorTH> iv_thRcsClk1;

    /** Threshold counter for PLL unlock attentions (from clock 0) on any chip
     *  in the domain. */
    ClockErrorTH iv_thPllClk0;

    /** Threshold counter for PLL unlock attentions (from clock 1) on any chip
     *  in the domain. */
    ClockErrorTH iv_thPllClk1;

    #endif // __HOSTBOOT_MODULE
};

//------------------------------------------------------------------------------

} // end namespace PRDF

#endif /* prdfPllDomain_H */

