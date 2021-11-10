/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCallouts.H $ */
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

#ifndef prdfCallouts_H
#define prdfCallouts_H

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <prdfCalloutMap.H> // for enums
#include <prdfCalloutsData.H>
#include <prdfEnums.H>
#include <prdfMemoryMru.H>
#include <prdfPlatServices.H>

namespace PRDF
{

//------------------------------------------------------------------------------

/**
 * @brief Wrapper class for PRD callouts (TargetHandle_t, MemoryMru, and
 *        SymbolicFru).
 * @note  It is a requirement that all supported callout types have a 32-bit
 *        representation for storage in the service data collector.
 * @note  This is a simple container of callout types. It does not translate
 *        between the different types.
 */
class PRDcallout
{
  public:

    /** @brief Constructor */
    PRDcallout() : iv_type(PRDcalloutData::TYPE_NONE)
    { iv_meldValue.u32 = 0; }

    /** @brief Constructor from TargetHandle_t */
    PRDcallout( TARGETING::TargetHandle_t i_target ) :
        iv_type(PRDcalloutData::TYPE_TARGET)
    { iv_meldValue.target = i_target; }

    /** @brief Constructor from TargetHandle_t
     *         with clock type info
     */
    PRDcallout( TARGETING::TargetHandle_t i_target,
                PRDcalloutData::MruType i_type ) :
        iv_type(i_type)
    { iv_meldValue.target = i_target; }

    /** @brief Constructor from MemoryMru */
    PRDcallout( const MemoryMru & i_memmru ) :
        iv_type(PRDcalloutData::TYPE_MEMMRU)
    { iv_meldValue.u32 = i_memmru.toUint32(); }

    /** @brief Constructor from SymbolicFru */
    PRDcallout( SymbolicFru i_symfru ) : iv_type(PRDcalloutData::TYPE_SYMFRU)
    { iv_meldValue.symfru = i_symfru; }

    /** @brief Constructor from raw data */
    PRDcallout( uint32_t i_val, PRDcalloutData::MruType i_type ) :
        iv_type(i_type)
    {
        switch ( iv_type )
        {
            case PRDcalloutData::TYPE_TARGET:
            case PRDcalloutData::TYPE_PROCCLK0:
            case PRDcalloutData::TYPE_PROCCLK1:
            case PRDcalloutData::TYPE_TODCLK:
#ifndef __HOSTBOOT_MODULE
            case PRDcalloutData::TYPE_PNOR:
            case PRDcalloutData::TYPE_DPSS:
#endif
                iv_meldValue.target = PlatServices::getTarget(i_val); break;
            case PRDcalloutData::TYPE_MEMMRU:
            case PRDcalloutData::TYPE_SYMFRU:
                iv_meldValue.u32 = i_val; break;
            default:
                iv_type          = PRDcalloutData::TYPE_NONE;
                iv_meldValue.u32 = 0;
        }
    }

    /** @brief Assignment from TargetHandle_t */
    PRDcallout & operator=( TARGETING::TargetHandle_t i_target )
    {
        iv_type = PRDcalloutData::TYPE_TARGET;
        iv_meldValue.target = i_target;
        return *this;
    }

    /** @brief Assignment from MemoryMru */
    PRDcallout & operator=( const MemoryMru & i_memmru )
    {
        iv_type = PRDcalloutData::TYPE_MEMMRU;
        iv_meldValue.u32 = i_memmru.toUint32();
        return *this;
    }

    /** @brief Assignment from SymbolicFru */
    PRDcallout & operator=( SymbolicFru i_symfru )
    {
        iv_type = PRDcalloutData::TYPE_SYMFRU;
        iv_meldValue.symfru = i_symfru;
        return *this;
    }

    // NOTE: The == operator must be declared within the class definition.
    // Meaning, you can't declare this outside the class:
    //
    //      bool operator==( const PRDcallout & l, const PRDcallout & r ) const;
    //
    // Otherwise, the single-argument constructors listed above will do
    // automatic type conversion, which will allow code like this:
    //
    //      TargetHandle_t t; MemoryMru m;
    //      if ( t == m ) ...
    //
    // The safest way to prevent this is to make all of the single-argument
    // constructors explicit. However, this will force us to create additional
    // code to handle the different callout types. For example,
    // ServiceDataCollector::SetCallout() will need to be implemented for each
    // callout type.

    /** @brief Overloaded == operator */
    bool operator==( const PRDcallout & r ) const
    {
        if ( iv_type == r.iv_type )
        {
            return ( PRDcalloutData::TYPE_TARGET == iv_type )
                    ? iv_meldValue.target == r.iv_meldValue.target
                    : iv_meldValue.u32    == r.iv_meldValue.u32;
        }

        return false;
    }

    /** @brief Returns the callout type. */
    PRDcalloutData::MruType getType() const { return iv_type; }

    /** @returns Returns the TargetHandle_t. */
    TARGETING::TargetHandle_t getTarget() const { return iv_meldValue.target; }

    /** @returns Returns the MemoryMru. */
    MemoryMru getMemMru() const { return MemoryMru(iv_meldValue.u32); }

    /** @brief Returns a uint32_t representation of the callout */
    uint32_t flatten() const
    {
        switch ( iv_type )
        {
            case PRDcalloutData::TYPE_TARGET:
            case PRDcalloutData::TYPE_PROCCLK0:
            case PRDcalloutData::TYPE_PROCCLK1:
            case PRDcalloutData::TYPE_TODCLK:
#ifndef __HOSTBOOT_MODULE
            case PRDcalloutData::TYPE_PNOR:
            case PRDcalloutData::TYPE_DPSS:
#endif
                return PlatServices::getHuid(iv_meldValue.target); break;
            case PRDcalloutData::TYPE_MEMMRU:
            case PRDcalloutData::TYPE_SYMFRU:
                return iv_meldValue.u32; break;
            default:
                return 0;
        }
    }

  private:

    PRDcalloutData::MruType iv_type;

    union
    {
        TARGETING::TargetHandle_t target;
        SymbolicFru               symfru;
        uint32_t                  u32;
    } iv_meldValue;

};

} // end namespace PRDF

#endif /* prdfCallouts_H */

