/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/resolution/prdfCallouts.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2000,2013              */
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

#ifndef prdfCallouts_H
#define prdfCallouts_H

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#ifndef __HOSTBOOT_MODULE

#include <srci.H>

#endif

#include <prdfCalloutMap.H>
#include <prdfEnums.H>
#include <prdfMemoryMru.H>

#ifdef PRDF_ERRL_PARSER
  #include <prdfTargetFwdRef.H>
#else
  #include <prdfPlatServices.H>
#endif

namespace PRDF
{

//------------------------------------------------------------------------------

typedef CalloutPriorityEnum PRDpriority;

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

    enum MruType
    {
        TYPE_NONE,
        TYPE_TARGET,
        TYPE_MEMMRU,
        TYPE_SYMFRU,
    };

    /** @brief Constructor */
    PRDcallout() : iv_type(TYPE_NONE)
    { iv_meldValue.u32 = 0; }

    /** @brief Constructor from TargetHandle_t */
    PRDcallout( TARGETING::TargetHandle_t i_target ) : iv_type(TYPE_TARGET)
    { iv_meldValue.target = i_target; }

    /** @brief Constructor from PrdfMemoryMru */
    PRDcallout( const PrdfMemoryMru & i_memmru ) : iv_type(TYPE_MEMMRU)
    { iv_meldValue.u32 = i_memmru.toUint32(); }

    /** @brief Constructor from SymbolicFru */
    PRDcallout( SymbolicFru i_symfru ) : iv_type(TYPE_SYMFRU)
    { iv_meldValue.symfru = i_symfru; }

#ifndef PRDF_ERRL_PARSER

    /** @brief Constructor from raw data */
    PRDcallout( uint32_t i_val, MruType i_type ) : iv_type(i_type)
    {
        switch ( iv_type )
        {
            case TYPE_TARGET:
                iv_meldValue.target = PlatServices::getTarget(i_val); break;
            case TYPE_MEMMRU:
            case TYPE_SYMFRU:
                iv_meldValue.u32 = i_val; break;
            default:
                iv_type          = TYPE_NONE;
                iv_meldValue.u32 = 0;
        }
    }

#endif

    /** @brief Assignment from TargetHandle_t */
    PRDcallout & operator=( TARGETING::TargetHandle_t i_target )
    {
        iv_type = TYPE_TARGET;
        iv_meldValue.target = i_target;
        return *this;
    }

    /** @brief Assignment from PrdfMemoryMru */
    PRDcallout & operator=( const PrdfMemoryMru & i_memmru )
    {
        iv_type = TYPE_MEMMRU;
        iv_meldValue.u32 = i_memmru.toUint32();
        return *this;
    }

    /** @brief Assignment from SymbolicFru */
    PRDcallout & operator=( SymbolicFru i_symfru )
    {
        iv_type = TYPE_SYMFRU;
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
    //      TargetHandle_t t; PrdfMemoryMru m;
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
            return ( TYPE_TARGET == iv_type )
                    ? iv_meldValue.target == r.iv_meldValue.target
                    : iv_meldValue.u32    == r.iv_meldValue.u32;
        }

        return false;
    }

    /** @brief Returns the callout type. */
    MruType getType() const { return iv_type; }

    /** @returns Returns the TargetHandle_t. */
    TARGETING::TargetHandle_t getTarget() const { return iv_meldValue.target; }

    /** @returns Returns the PrdfMemoryMru. */
    PrdfMemoryMru getMemMru() const { return PrdfMemoryMru(iv_meldValue.u32); }

#ifndef PRDF_ERRL_PARSER

    /** @brief Returns a uint32_t representation of the callout */
    uint32_t flatten() const
    {
        switch ( iv_type )
        {
            case TYPE_TARGET:
                return PlatServices::getHuid(iv_meldValue.target); break;
            case TYPE_MEMMRU:
            case TYPE_SYMFRU:
                return iv_meldValue.u32; break;
            default:
                return 0;
        }
    }

#endif

  private:

    MruType iv_type;

    union
    {
        TARGETING::TargetHandle_t target;
        SymbolicFru               symfru;
        uint32_t                  u32;
    } iv_meldValue;

};

} // end namespace PRDF

#endif /* prdfCallouts_H */

