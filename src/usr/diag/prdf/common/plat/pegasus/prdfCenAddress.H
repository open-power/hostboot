/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenAddress.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

/** @file  prdfCenAddress.H
 *  @brief General utilities to read, modify, and write the memory address
 *         registers (MBMACA, MBMEA, etc.). Also includes the CenRank class.
 */

#ifndef __prdfCenAddress_H
#define __prdfCenAddress_H

#include <prdf_types.h>

namespace PRDF
{

class ExtensibleChip;

//------------------------------------------------------------------------------
//  Class CenRank
//------------------------------------------------------------------------------

/**
 * @brief Container for a memory rank.
 */
class CenRank
{
  public: // constructor

    /** @brief Default constructor */
    CenRank() :
        iv_slaveValid(false)
    {
        iv_rank.master.u = 0;
        iv_rank.slave    = 0;
    }

    /**
     * @brief Constructor from flattened rank.
     * @param i_mrank The 3-bit master rank.
     * @note  The master rank format should be 0bDRR (D=DIMM select,
     *        R=rank select).
     */
    explicit CenRank( uint8_t i_mrank ) :
        iv_slaveValid(false)
    {
        iv_rank.master.u = i_mrank;
        iv_rank.slave    = 0;
    }

    /**
     * @brief Constructor from flattened rank.
     * @param i_mrank The 3-bit master rank.
     * @param i_srank The 3-bit slave rank.
     * @note  The master rank format should be 0bDRR (D=DIMM select,
     *        R=rank select).
     */
    explicit CenRank( uint8_t i_mrank, uint8_t i_srank ) :
        iv_slaveValid(true)
    {
        iv_rank.master.u = i_mrank;
        iv_rank.slave    = i_srank;
    }

    /** @return The 1-bit DIMM select. */
    uint8_t getDimmSlct() const { return iv_rank.master.s.ds; }

    /** @return The 2-bit rank select. */
    uint8_t getRankSlct() const { return iv_rank.master.s.rs; }

    /**
     * @return The 3-bit master rank.
     * @note   The format will be 0bDRR (D=DIMM select, R=rank select).
     */
    uint8_t getMaster() const { return iv_rank.master.u; }

    /** @return The 3-bit slave rank. */
    uint8_t getSlave() const { return iv_rank.slave; }

    /**
     * There are a lot of cases where we only need to know the master rank,
     * however, this object stores both the master and slave rank. This function
     * will indicate whether it is intended to only be used for a master rank or
     * both a master and slave rank.
     *
     * @return TRUE if slave rank is trusted to be valid, FALSE otherwise.
     */
    bool isSlaveValid() const { return iv_slaveValid; }

    /** @brief '==' operator */
    bool operator==( const CenRank & i_rank ) const
    {
        return ( (this->getMaster() == i_rank.getMaster()) &&
                 (this->getSlave()  == i_rank.getSlave() ) );
    }

    /** @brief '<' operator */
    bool operator<( const CenRank & i_rank ) const
    {
        return ( (this->getMaster() < i_rank.getMaster()) ||
                 ( (this->getMaster() == i_rank.getMaster()) &&
                   (this->getSlave()  <  i_rank.getSlave() ) ) );
    }

  private: // data

    struct
    {
        #if !( __BYTE_ORDER == __LITTLE_ENDIAN )
        union
        {
            struct { uint8_t unused : 5; uint8_t ds : 1; uint8_t rs : 2; } s;
            uint8_t u;
        } master;
        #else
        union
        {
            struct { uint8_t rs : 2; uint8_t ds : 1; uint8_t unused : 5; } s;
            uint8_t u;
        } master;
        #endif

        uint8_t slave : 3;

    } iv_rank;

    bool iv_slaveValid;
};

//------------------------------------------------------------------------------
//  Class CenAddr
//------------------------------------------------------------------------------

/**
 * @brief Simple container for a memory address.
 */
class CenAddr
{
  public: // constants, enums

    /** Some addresses are associated with a specific error type. For example,
     *  the address in the MBMACA will indicate what type of CE/UE caused the
     *  maintenance command to stop.
     *
     *  From the MBMACA SCOM def:
     *      Multiple error status bits may be set due to unique errors on each
     *      64 byte pieces of read data.
     *
     *  Since it is possible to have multiple error types, iv_types will need to
     *  be an OR of all error types. The enum values will be mapped directly
     *  with MBMACA[40:46] so that the user can simply pass that 7-bit field
     *  into the i_types parameter of the contructor.
     */
    enum ErrorType
    {
        NONE = 0,    ///< Unknown attention
        NCE  = 0x40, ///< New CE
        SCE  = 0x20, ///< CE on a symbol mark
        MCE  = 0x10, ///< CE on a chip mark
        RCE  = 0x08, ///< Retry CE
        MPE  = 0x04, ///< Mark placed error
        SUE  = 0x02, ///< SUE
        UE   = 0x01, ///< UE
    };

  public: // functions

    /** @brief Default constructor. */
    CenAddr() :
        iv_rank(0), iv_types(NONE)
    {
        iv_bankRowCol.bank = 0;
        iv_bankRowCol.row  = 0;
        iv_bankRowCol.col  = 0;
    }

    /**
     * @brief Constructor from components.
     * @param i_mrank The 3-bit master rank.
     * @param i_srank The 3-bit slave rank.
     * @param i_bank  The 4-bit bank.
     * @param i_row   The 17-bit row.
     * @param i_col   The 12-bit column.
     * @param i_types An OR of all error types associated with this address (see
     *                enum ErrorType).
     */
    CenAddr( uint32_t i_mrank, uint32_t i_srank, uint32_t i_bank,
             uint32_t i_row, uint32_t i_col, uint32_t i_types = NONE ) :
        iv_rank(i_mrank, i_srank), iv_types(i_types)
    {
        iv_bankRowCol.bank = i_bank;
        iv_bankRowCol.row  = i_row;
        iv_bankRowCol.col  = i_col;
    }

    /**
     * @brief Creates a CenAddr from a mainline memory read address.
     * @param i_addr 64-bit address.
     * @param i_type The error type associated with this address.
     */
    static CenAddr fromReadAddr( uint64_t i_addr, uint32_t i_type )
    {
        return CenAddr(
                  (i_addr >> 60) &     0x7,     // master rank
                  (i_addr >> 57) &     0x7,     // slave rank
                  (i_addr >> 53) &     0xf,     // bank
                 ((i_addr >>  5) & 0x20000) | ((i_addr >> 36) & 0x1ffff), // row
                  (i_addr >> 24) &   0xfff,     // column
                 i_type );                      // error type
    }

    /**
     * @brief  Converts internal data structure to a mainline memory read
     *         address.
     * @return A uint64_t version of the address.
     * @note   Does not include error type. This is because in most cases we
     *         will use this function to write out to hardware and in doing so
     *         we will want to clear the status bits anyway.
     */
    uint64_t toReadAddr() const
    {
        return ( ((uint64_t) iv_rank.getMaster()           << 60) |
                 ((uint64_t) iv_rank.getSlave()            << 57) |
                 ((uint64_t) iv_bankRowCol.bank            << 53) |
                 ((uint64_t)(iv_bankRowCol.row & 0x1ffff)  << 36) |  // r16-r0
                 ((uint64_t) iv_bankRowCol.col             << 24) |
                 ((uint64_t)(iv_bankRowCol.row & 0x20000)  <<  5) ); // r17
    }

    /**
     * @brief Creates a CenAddr from a maintenace start address.
     * @param i_addr 64-bit address.
     */
    static CenAddr fromMaintStartAddr( uint64_t i_addr )
    {
        return CenAddr(
                  (i_addr >> 60) &     0x7,     // master rank
                  (i_addr >> 57) &     0x7,     // slave rank
                  (i_addr >> 53) &     0xf,     // bank
                 ((i_addr << 13) & 0x20000) | ((i_addr >> 36) & 0x1ffff), // row
                  (i_addr >> 24) &   0xfff,     // column
                  (i_addr >> 17) &    0x7f );   // error type
    }

    /**
     * @brief  Converts internal data structure to a maintenace start address.
     * @return A uint64_t version of the address.
     * @note   Does not include error type. This is because in most cases we
     *         will use this function to write out to hardware and in doing so
     *         we will want to clear the status bits anyway.
     */
    uint64_t toMaintStartAddr() const
    {
        return ( ((uint64_t) iv_rank.getMaster()           << 60) |
                 ((uint64_t) iv_rank.getSlave()            << 57) |
                 ((uint64_t) iv_bankRowCol.bank            << 53) |
                 ((uint64_t)(iv_bankRowCol.row & 0x1ffff)  << 36) |  // r16-r0
                 ((uint64_t) iv_bankRowCol.col             << 24) |
                 ((uint64_t)(iv_bankRowCol.row & 0x20000)  >> 13) ); // r17
    }

    /**
     * @brief Creates a CenAddr from a maintenace end address.
     * @param i_addr 64-bit address.
     */
    static CenAddr fromMaintEndAddr( uint64_t i_addr )
    {
        return CenAddr(
                  (i_addr >> 60) &     0x7,     // master rank
                  (i_addr >> 57) &     0x7,     // slave rank
                  (i_addr >> 53) &     0xf,     // bank
                 ((i_addr >>  6) & 0x20000) | ((i_addr >> 36) & 0x1ffff), // row
                  (i_addr >> 24) &   0xfff );    // column
    }

    /**
     * @brief  Converts internal data structure to a maintenace end address.
     * @return A uint64_t version of the address.
     * @note   Does not include error type. This is because in most cases we
     *         will use this function to write out to hardware and in doing so
     *         we will want to clear the status bits anyway.
     */
    uint64_t toMaintEndAddr() const
    {
        return ( ((uint64_t) iv_rank.getMaster()           << 60) |
                 ((uint64_t) iv_rank.getSlave()            << 57) |
                 ((uint64_t) iv_bankRowCol.bank            << 53) |
                 ((uint64_t)(iv_bankRowCol.row & 0x1ffff)  << 36) |  // r16-r0
                 ((uint64_t) iv_bankRowCol.col             << 24) |
                 ((uint64_t)(iv_bankRowCol.row & 0x20000)  <<  6) ); // r17
    }

    /** @return This address's rank. */
    const CenRank& getRank() const { return iv_rank; };

    /** @return This address's bank. */
    uint32_t getBank() const { return iv_bankRowCol.bank; };

    /** @return This address's row. */
    uint32_t getRow() const { return iv_bankRowCol.row; };

    /** @return This address's column. */
    uint32_t getCol() const { return iv_bankRowCol.col; };

    /** @brief '==' operator */
    bool operator==( const CenAddr & i_addr ) const
    {
        return ( this->getRank() == i_addr.getRank() &&
                 this->getBank() == i_addr.getBank() &&
                 this->getRow()  == i_addr.getRow()  &&
                 this->getCol()  == i_addr.getCol() );
    }

  private: // instance variable

    CenRank iv_rank;  ///< Master rank (see CenRank class)

    /** The bank, row, and column. Note that these are all packed in a struct
     *  to save space. */
    struct __attribute__((__packed__))
    {
        uint32_t bank :  4; ///< b2-b0
        uint32_t col  : 12; ///< c13,c11,c9-c3 (c2-c0 are tied to 0)
        uint32_t row  : 18; ///< r17-r0
    } iv_bankRowCol;

    /** An OR of all error types assoiated with this address (see enum
     *  ErrorType). */
    uint32_t iv_types;

};

//------------------------------------------------------------------------------
//                       MBS Address Registers
//------------------------------------------------------------------------------

typedef const char * const CenReadAddrReg;

extern CenReadAddrReg READ_NCE_ADDR; ///< For the MBNCER register
extern CenReadAddrReg READ_RCE_ADDR; ///< For the MBRCER register
extern CenReadAddrReg READ_MPE_ADDR; ///< For the MBMPER register
extern CenReadAddrReg READ_UE_ADDR;  ///< For the MBUER register

/**
 * @brief  Reads the specified mainline memory read address from hardware.
 * @param  i_membChip A Centaur chip.
 * @param  i_mbaPos   The target MBA position.
 * @param  i_addrReg  The target address register.
 * @param  o_addr     The returned address from hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getCenReadAddr( ExtensibleChip * i_membChip, uint32_t i_mbaPos,
                        CenReadAddrReg i_addrReg, CenAddr & o_addr );

/**
 * @brief  Writes the specified mainline memory read address to hardware.
 * @param  i_membChip A Centaur chip.
 * @param  i_mbaPos   The target MBA position.
 * @param  i_addrReg  The target address register.
 * @param  i_addr     The address to write to hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t setCenReadAddr( ExtensibleChip * i_membChip, uint32_t i_mbaPos,
                        CenReadAddrReg i_addrReg, const CenAddr & i_addr );

//------------------------------------------------------------------------------
//                       MBA Address Registers
//------------------------------------------------------------------------------

/**
 * @brief  Reads the maintenance start address from hardware.
 * @param  i_mbaChip An MBA chip.
 * @param  o_addr    The returned address from hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getCenMaintStartAddr( ExtensibleChip * i_mbaChip, CenAddr & o_addr );

/**
 * @brief  Writes the maintenance start address to hardware.
 * @param  i_mbaChip An MBA chip.
 * @param  i_addr    The address to write to hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t setCenMaintStartAddr( ExtensibleChip * i_mbaChip,
                              const CenAddr & i_addr );

/**
 * @brief  Reads the maintenance end address from hardware.
 * @param  i_mbaChip An MBA chip.
 * @param  o_addr    The returned address from hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getCenMaintEndAddr( ExtensibleChip * i_mbaChip, CenAddr & o_addr );

/**
 * @brief  Writes the maintenance end address to hardware.
 * @param  i_mbaChip An MBA chip.
 * @param  i_addr    The address to write to hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t setCenMaintEndAddr( ExtensibleChip * i_mbaChip,
                            const CenAddr & i_addr );

} // end namespace PRDF

#endif // __prdfCenAddress_H

