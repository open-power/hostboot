/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/util/prdfErrorSignature.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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

#ifndef ErrorSignature_h
#define ErrorSignature_h

/** @file prdfErrorSignature.H
 *  @brief PRD error signature
 */

#include <iipconst.h>
#include <prdfTrace.H>

// FIXME - Should this class be scoped in PRDF namspace?

/** @class ErrorSignature
 *
 *  A complete error signature is a 64-bit number where:
 *      The 1st 32-bits is representation of a chip.
 *      The 2nd 32-bits is the signature ID.
 *  The signature ID is defined the following:
 *      The 1st 16-bits is the register ID.
 *      The 2nd 16-bits is the error code.
 */
class ErrorSignature
{
  public:

    /**
     * @brief Constructor
     */
    ErrorSignature() : iv_chipId(0), iv_regId(0), iv_errCode(0) {}

    /**
     * @brief operator==
     */
    int operator==( const ErrorSignature & r ) const
    {
        return ( iv_chipId  == r.iv_chipId  &&
                 iv_regId   == r.iv_regId   &&
                 iv_errCode == r.iv_errCode );
    }

    /**
     * @brief operator!=
     */
    int operator!=( const ErrorSignature & r ) const
    {
        return ( iv_chipId  != r.iv_chipId  ||
                 iv_regId   != r.iv_regId   ||
                 iv_errCode != r.iv_errCode );
    }

    /**
     * @brief operator<
     */
    bool operator<( const ErrorSignature & r ) const
    {
        if ( iv_chipId == r.iv_chipId )
        {
            if ( iv_regId == r.iv_regId )
                return ( iv_errCode < r.iv_errCode );
            else
                return ( iv_regId < r.iv_regId );
        }
        else
            return ( iv_chipId < r.iv_chipId );
    };

    /**
     * @brief Clears the signature.
     */
    void clear()
    {
        iv_chipId   = 0;
        iv_regId    = 0;
        iv_errCode  = 0;
        TraceSignature();
    }

    /**
     * @brief Sets the chip ID.
     * @note  Clears signature ID.
     * @param i_chipId The chip's ID.
     */
    void setChipId( uint32_t i_chipId )
    {
        iv_chipId   = i_chipId;
        iv_regId    = 0;
        iv_errCode  = 0;
        TraceSignature();
    }

    /**
     * @brief Sets the signature ID.
     * @param i_sigId The signature ID.
     */
    void setSigId( uint32_t i_sigId )
    {
        iv_regId    = (uint16_t)(i_sigId >> 16);
        iv_errCode  = (uint16_t)(i_sigId & 0xffff);
        TraceSignature();
    }

    /**
     * @brief Sets the signature's register ID.
     * @param i_regId The signature's register ID.
     */
    void setRegId( uint16_t i_regId )
    {
        iv_regId    = i_regId;
        iv_errCode  = 0;
        TraceSignature();
    }

    /**
     * @brief Sets the signature's error code.
     * @param i_errCode The signature's error code.
     */
    void setErrCode( uint16_t i_errCode )
    {
        iv_errCode  = i_errCode;
        TraceSignature();
    }

    /**
     * @return The chip ID.
     */
    uint32_t getChipId() const { return iv_chipId; }

    /**
     * @return The signature ID.
     */
    uint32_t getSigId() const
    {
        return ((uint32_t)iv_regId << 16) | (uint32_t)iv_errCode;
    }

  private:

    /**
     * @brief Create a trace statement for the current signature.
     */
    void TraceSignature() const
    {
        PRDF_INF( "PRD Signature %08X %08X", getChipId(), getSigId() );
    }

    uint32_t iv_chipId;  ///< 32-bit representation of a chip
    uint16_t iv_regId;   ///< 16-bit register ID
    uint16_t iv_errCode; ///< 16-bit error code
};

#endif

