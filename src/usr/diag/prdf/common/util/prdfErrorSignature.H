/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfErrorSignature.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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

#ifndef ErrorSignature_h
#define ErrorSignature_h

/** @file prdfErrorSignature.H
 *  @brief PRD error signature
 */

#include <iipconst.h>
#include <prdfTrace.H>

namespace PRDF
{
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
     * @brief Sets the entire signature all at once.
     * @param i_chipId The chip's ID.
     * @param i_sigId  The signature ID.
     */
    void setSignature( uint32_t i_chipId, uint32_t i_sigId )
    {
        iv_chipId   = i_chipId;
        iv_regId    = (uint16_t)(i_sigId >> 16);
        iv_errCode  = (uint16_t)(i_sigId & 0xffff);
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
     * @brief   Returns the error code.
     */
    uint16_t getErrorCode() { return iv_errCode; }
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

        #ifdef __HOSTBOOT_MODULE
        // Any time the signature is updated, write the HB scratch regs
        writeScratch();
        #endif
    }

    #ifdef __HOSTBOOT_MODULE
    /**
     * @brief Write the current signature to the specified Hostboot scratch
     *        registers: 0x00050180 (scratch 9) and 0x00050181 (scratch 10).
     * @note This is intended to workaround an issue in analysis if a system
     *       would checkstop during FIR analysis at the time when PRD had
     *       cleared and masked the attention, but had not yet committed the
     *       log. This way, the signature of the otherwise lost analysis is
     *       saved.
     */
    void writeScratch() const;
    #endif

    uint32_t iv_chipId;  ///< 32-bit representation of a chip
    uint16_t iv_regId;   ///< 16-bit register ID
    uint16_t iv_errCode; ///< 16-bit error code
};
} //End namespace PRDF
#endif

