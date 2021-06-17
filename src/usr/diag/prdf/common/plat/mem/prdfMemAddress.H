/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemAddress.H $          */
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

/** @file  prdfMemAddress.H
 *  @brief General utilities to read, modify, and write the memory address
 *         registers for OCMB targets.
 */

#ifndef __prdfMemAddress_H
#define __prdfMemAddress_H

// Platform includes
#include <prdfMemRank.H>
#include <prdfTargetServices.H>

// External includes
#include <vector>

namespace PRDF
{

class ExtensibleChip;

/** Used to specify target address ranges for functions input. */
enum AddrRangeType
{
    SLAVE_RANK,  ///< Target slave rank only.
    MASTER_RANK, ///< Target entire master rank.
};

//------------------------------------------------------------------------------
//  Class MemAddr
//------------------------------------------------------------------------------

/** @brief Simple container for a memory address.
 *  @note  These addresses are relative to OCMB target. Therefore,
 *         they do not contain information like the port.
 *         So that information will need to be derived elsewhere.
 */
class MemAddr
{
  public: // constants, enums

    /** Supported read address registers */
    enum ReadReg
    {
        READ_NCE_ADDR,
        READ_RCE_ADDR,
        READ_MPE_ADDR,
        READ_UE_ADDR,
        READ_AUE_ADDR, // not supported on Centaur
    };

  public: // functions

    /** @brief Default constructor. */
    MemAddr() = default;

    /**
     * @brief Creates a MemAddr from a mainline memory read address.
     * @param i_addr 64-bit address.
     */
    template<TARGETING::TYPE T>
    static MemAddr fromReadAddr( uint64_t i_addr );

    /**
     * @brief Creates a MemAddr from the current maintenance address.
     * @param i_addr 64-bit address.
     */
    template<TARGETING::TYPE T>
    static MemAddr fromMaintAddr( uint64_t i_addr );

    /**
     * @brief  Converts internal data structure to a maintenance address.
     * @return A uint64_t version of the address.
     * @note   Does not include error type. This is because in most cases we
     *         will use this function to write out to hardware and in doing so
     *         we will want to clear the status bits anyway.
     */
    template<TARGETING::TYPE T>
    uint64_t toMaintAddr() const;

    /**
     * @brief  Returns a right justified uint64_t version of the address that
     *         has been incremented to the next row to be input to a scrub cmd.
     * @param  i_chip OCMB chip.
     * @return A right justified uint64_t version of the address.
     */
    template<TARGETING::TYPE T>
    uint64_t incRowAddr( ExtensibleChip * i_chip ) const;

    /** @return This address's rank. */
    const MemRank& getRank() const { return iv_rnk; }

    /** @return This address's bank. */
    uint32_t getBank() const { return iv_bnk; }

    /** @return This address's row. */
    uint32_t getRow() const { return iv_row; }

    /** @return This address's column. */
    uint32_t getCol() const { return iv_col; }

    /** @brief '==' operator */
    bool operator==( const MemAddr & i_addr ) const
    {
        return ( this->getRank() == i_addr.getRank() &&
                 this->getBank() == i_addr.getBank() &&
                 this->getRow()  == i_addr.getRow()  &&
                 this->getCol()  == i_addr.getCol() );
    }

  public: // functions

    /**
     * @brief Constructor from components.
     * @param i_rnk Rank   See MemRank class
     * @param i_bnk Bank   OCMB: b0-b2,bg0-bg1 (5-bit)
     * @param i_row Row    OCMB: r0-r17        (18-bit)
     * @param i_col Column OCMB: c3-c9         (7-bit)
     */
    MemAddr( MemRank i_rnk, uint8_t i_bnk, uint32_t i_row, uint16_t i_col ) :
        iv_rnk(i_rnk), iv_bnk(i_bnk), iv_row(i_row), iv_col(i_col)
    {}

  private: // instance variables

    MemRank  iv_rnk = MemRank(0); ///< Rank
    uint8_t  iv_bnk = 0;          ///< Bank
    uint32_t iv_row = 0;          ///< Row
    uint16_t iv_col = 0;          ///< Column
};

//------------------------------------------------------------------------------
//                       Address Accessor Functions
//------------------------------------------------------------------------------

/**
 * @brief  Reads the specified mainline memory read address from hardware.
 * @param  i_chip OCMB chip.
 * @param  i_reg  The target address register.
 * @param  o_addr The returned address from hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t getMemReadAddr( ExtensibleChip * i_chip, MemAddr::ReadReg i_reg,
                         MemAddr & o_addr );

/**
 * @brief  Reads the maintenance address from hardware.
 *
 * @param  i_chip An OCMB chip.
 * @param  o_addr The returned address from hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t getMemMaintAddr( ExtensibleChip * i_chip, MemAddr & o_addr );

} // end namespace PRDF

#endif // __prdfMemAddress_H

