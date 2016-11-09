/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemAddress.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 *         registers for Centaur MBA and P9 MCBIST/MCA.
 */

#ifndef __prdfMemAddress_H
#define __prdfMemAddress_H

// Platform includes
#include <prdfMemRank.H>
#include <prdfPlatServices.H>

// External includes
#include <vector>

namespace PRDF
{

class ExtensibleChip;

//------------------------------------------------------------------------------
//  Class MemAddr
//------------------------------------------------------------------------------

/** @brief Simple container for a memory address.
 *  @note  These addresses are relative to the MBA and MCA targets. Therefore,
 *         they do not contain information like the port, which is needed for
 *         MCBIST targets. So that information will need to be derived
 *         elsewhere.
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
     * @brief Creates a MemAddr from a maintenance address.
     * @param i_addr 64-bit address.
     */
    template<TARGETING::TYPE T>
    static MemAddr fromMaintAddr( uint64_t i_addr );

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

  private: // functions

    /**
     * @brief Constructor from components.
     * @param i_rnk Rank   See MemRank class
     * @param i_bnk Bank   MBA (DDR4): bg1-bg0,b1-b0  (4-bit)
     *                     MBA (DDR3): b2-b0          (3-bit)
     *                     MCBIST:     bg0-bg1,b0-b2  (5-bit)
     * @param i_row Row    MBA:        c13,c11,c9-c3  (9-bit)
     *                     MCBIST:     c3-c9          (7-bit)
     * @param i_col Column MBA:        r17-r0         (18-bit)
     *                     MCBIST:     r0-r17         (18-bit)
     */
    MemAddr( MemRank i_rnk, uint8_t i_bnk, uint32_t i_row, uint16_t i_col ) :
        iv_rnk(i_rnk), iv_bnk(i_bnk), iv_row(i_row), iv_col(i_col)
    {}

  private: // instance variables

    MemRank  iv_rnk;     ///< Rank
    uint8_t  iv_bnk = 0; ///< Bank
    uint32_t iv_row = 0; ///< Row
    uint16_t iv_col = 0; ///< Column
};

//------------------------------------------------------------------------------
//                       Address Accessor Functions
//------------------------------------------------------------------------------

/**
 * @brief  Reads the specified mainline memory read address from hardware.
 *
 * While the address returned will be relative to an MBA or MCA, this function
 * requires the MEMBUF or MCBIST targets and the position of the MBA or MCA
 * relative to the parent. The reason for this is because of where the addresses
 * and FIRs are located on the Nimbus or Centaur. We didn't want to add a lot of
 * hopping around between targets just to make the interface look pretty.
 *
 * @param  i_chip An MEMBUF or MCBIST chip.
 * @param  i_pos  Position of MBA/MCA relative to MEMBUF/MCBIST.
 * @param  i_reg  The target address register.
 * @param  o_addr The returned address from hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t getMemReadAddr( ExtensibleChip * i_chip, uint32_t i_pos,
                         MemAddr::ReadReg i_reg, MemAddr & o_addr );

#ifdef __HOSTBOOT_MODULE

/**
 * @brief  Reads the maintenance address from hardware.
 *
 * While the address returned will be relative to an MBA or MCA, this function
 * requires the MBA or MCBIST targets, which is where the maintenance logic
 * is on the Nimbus or Centaur. We didn't want to add a lot of hopping around
 * between targets just to make the interface look pretty.
 *
 * The address register in the MCBIST may contain the MCA port information, but
 * that is dependent on the on whether or not the command was run in broadcast
 * mode or not. Therefore, users must call getMcbistMaintPort() to get the port
 * information.
 *
 * @param  i_chip An MBA or MCBIST chip.
 * @param  o_addr The returned address from hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t getMemMaintAddr( ExtensibleChip * i_chip, MemAddr & o_addr );

/**
 * @brief  Queries broadcast mode information and determines which of the MCBIST
 *         ports were targeted for the command.
 *
 * Notes about broadcast mode. It will only be run...
 *  - on all configured ports, no partials configurations supported.
 *  - if there are more than one configured ports behind the MCBIST.
 *  - if all configured ports have the same geometry.
 *
 * @note   Only supported for MCBIST.
 * @param  i_mcbChip An MCBIST chip.
 * @param  o_mcaList A list of all MCAs targeted by the command.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
uint32_t getMcbistMaintPort( ExtensibleChip * i_mcbChip,
                             std::vector<ExtensibleChip *> & o_mcaList );

#endif

} // end namespace PRDF

#endif // __prdfMemAddress_H

