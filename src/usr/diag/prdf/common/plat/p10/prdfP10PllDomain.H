/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10PllDomain.H $        */
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
    bool query(Types i_types) const
    {
        return (0 != (iv_types & i_types));
    }

    /** @return True, if any type is currently set in iv_types. */
    bool any() const
    {
        return (0 != iv_types);
    }

    /** @brief Sets the given type in iv_types. */
    void set(Types i_types)
    {
        iv_types |= i_types;
    }

    /** @brief Clears the given type in iv_types. */
    void clear(Types i_types)
    {
        iv_types &= ~i_types;
    }

    /** @brief Clears all types in iv_types. */
    void clear()
    {
        iv_types = 0;
    }

    /** @brief Bitwise OR operator. */
    PllErrTypes operator|(const PllErrTypes& i_types) const
    {
        PllErrTypes o_types;
        o_types.iv_types = this->iv_types | i_types.iv_types;
        return o_types;
    }
};

//------------------------------------------------------------------------------

class P10PllDomain : public PllDomain
{
  public:
    /** @brief Default constructor. */
    P10PllDomain() : PllDomain(CLOCK_DOMAIN_FAB) {}

    /** @brief Destructor. */
    ~P10PllDomain() = default;

    /** @brief Copy constructor. */
    P10PllDomain(const P10PllDomain&) = default;

    /** @brief Assignment operator. */
    P10PllDomain& operator=(const P10PllDomain&) = default;

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
#ifdef __HOSTBOOT_MODULE

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
