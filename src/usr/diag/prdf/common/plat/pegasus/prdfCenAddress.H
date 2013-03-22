/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenAddress.H $      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
    CenRank() { iv_rank.u = 0; }

    /**
     * @brief Constructor from flattened rank.
     * @param i_rank The 3-bit rank.
     * @note  The rank format should be 0bDRR (D=DIMM select, R=rank select).
     */
    explicit CenRank( uint8_t i_rank ) { iv_rank.u = i_rank; }

    /**
     * @brief Constructor from components.
     * @param i_dimmSlct The 1-bit DIMM select.
     * @param i_rankSlct The 2-bit rank select.
     */
    CenRank( uint8_t i_dimmSlct, uint8_t i_rankSlct )
    {
        iv_rank.s.ds = i_dimmSlct;
        iv_rank.s.rs = i_rankSlct;
    }

    /** @return The 1-bit DIMM select. */
    uint8_t getDimmSlct() const { return iv_rank.s.ds; }

    /** @return The 2-bit rank select. */
    uint8_t getRankSlct() const { return iv_rank.s.rs; }

    /**
     * @brief  Converts internal data structure to a uint8_t.
     * @note   The format will be 0bDRR (D=DIMM select, R=rank select).
     * @return A uint8_t version of the rank.
     */
    uint8_t flatten() const { return iv_rank.u; }

    /** @brief '==' operator */
    bool operator==( const CenRank & i_rank ) const
    { return ( this->flatten() == i_rank.flatten() ); }

    /** @brief '<' operator */
    bool operator<( const CenRank & i_rank ) const
    { return ( this->flatten() < i_rank.flatten() ); }

  private: // data

    union
    {
        struct { uint8_t unused : 5; uint8_t ds : 1; uint8_t rs : 2; } s;
        uint8_t u;
    } iv_rank;
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
     * @param i_rank  The 3-bit master rank.
     * @param i_bank  The 4-bit bank.
     * @param i_row   The 17-bit row.
     * @param i_col   The 12-bit column.
     * @param i_types An OR of all error types associated with this address (see
     *                enum ErrorType).
     */
    CenAddr( uint32_t i_rank, uint32_t i_bank, uint32_t i_row,
                uint32_t i_col, uint32_t i_types = NONE ) :
        iv_rank(i_rank), iv_types(i_types)
    {
        iv_bankRowCol.bank = i_bank;
        iv_bankRowCol.row  = i_row;
        iv_bankRowCol.col  = i_col;
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
        uint32_t row  : 17; ///< r16-r0
    } iv_bankRowCol;

    /** An OR of all error types assoiated with this address (see enum
     *  ErrorType). */
    uint32_t iv_types;

};

//------------------------------------------------------------------------------
//                       MBS Address Registers
//------------------------------------------------------------------------------

typedef const char * const ReadAddrReg;

extern ReadAddrReg READ_NCE_ADDR_0; ///< For the MBNCER_0 register
extern ReadAddrReg READ_RCE_ADDR_0; ///< For the MBRCER_0 register
extern ReadAddrReg READ_MPE_ADDR_0; ///< For the MBMPER_0 register
extern ReadAddrReg READ_UE_ADDR_0;  ///< For the MBUER_0 register

extern ReadAddrReg READ_NCE_ADDR_1; ///< For the MBNCER_1 register
extern ReadAddrReg READ_RCE_ADDR_1; ///< For the MBRCER_1 register
extern ReadAddrReg READ_MPE_ADDR_1; ///< For the MBMPER_1 register
extern ReadAddrReg READ_UE_ADDR_1;  ///< For the MBUER_1 register

/**
 * @brief  Returns the address from the specified register.
 * @param  i_mbChip  A Centaur chip.
 * @param  i_addrReg The target address register.
 * @param  o_addr    The returned address from hardware.
 * @return Non-SUCCESS if a register read fails, SUCCESS otherwise.
 */
int32_t cenGetReadAddr( ExtensibleChip * i_mbChip, ReadAddrReg i_addrReg,
                        CenAddr & o_addr );

/**
 * @brief  Writes an address to the specified register.
 * @param  i_mbChip  A Centaur chip.
 * @param  i_addrReg The target address register.
 * @param  i_addr    The address to write to hardware.
 * @return Non-SUCCESS if a register read fails, SUCCESS otherwise.
 */
int32_t cenSetReadAddr( ExtensibleChip * i_mbChip, ReadAddrReg i_addrReg,
                        CenAddr i_addr );

//------------------------------------------------------------------------------
//                       MBA Address Registers
//------------------------------------------------------------------------------

typedef const char * const MaintAddrReg;

extern MaintAddrReg MAINT_START_ADDR; ///< For the MBMACA register
extern MaintAddrReg MAINT_END_ADDR;   ///< For the MBMEA register

/**
 * @brief  Returns the address from the specified register.
 * @param  i_mbaChip An MBA chip.
 * @param  i_addrReg The target address register.
 * @param  o_addr    The returned address from hardware.
 * @return Non-SUCCESS if a register read fails, SUCCESS otherwise.
 */
int32_t cenGetMaintAddr( ExtensibleChip * i_mbaChip, MaintAddrReg i_addrReg,
                         CenAddr & o_addr );

/**
 * @brief  Writes an address to the specified register.
 * @param  i_mbaChip An MBA chip.
 * @param  i_addrReg The target address register.
 * @param  i_addr    The address to write to hardware.
 * @return Non-SUCCESS if a register read fails, SUCCESS otherwise.
 */
int32_t cenSetMaintAddr( ExtensibleChip * i_mbChip, MaintAddrReg i_addrReg,
                         CenAddr i_addr );

} // end namespace PRDF

#endif // __prdfCenAddress_H

