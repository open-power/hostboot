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

    /**
     * @brief Creates a CenAddr from a mainline memory read address.
     * @param i_addr 64-bit address.
     * @param i_type The error type associated with this address.
     */
    static CenAddr fromReadAddr( uint64_t i_addr, uint32_t i_type )
    {
        return CenAddr(
                  (i_addr >> 60) &     0x7,     // rank
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
        return ( ((uint64_t) iv_rank.flatten()             << 60) |
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
                  (i_addr >> 60) &     0x7,     // rank
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
        return ( ((uint64_t) iv_rank.flatten()             << 60) |
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
                  (i_addr >> 60) &     0x7,     // rank
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
        return ( ((uint64_t) iv_rank.flatten()             << 60) |
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

extern CenReadAddrReg READ_NCE_ADDR_0; ///< For the MBA0_MBNCER register
extern CenReadAddrReg READ_RCE_ADDR_0; ///< For the MBA0_MBRCER register
extern CenReadAddrReg READ_MPE_ADDR_0; ///< For the MBA0_MBMPER register
extern CenReadAddrReg READ_UE_ADDR_0;  ///< For the MBA0_MBUER register

extern CenReadAddrReg READ_NCE_ADDR_1; ///< For the MBA1_MBNCER register
extern CenReadAddrReg READ_RCE_ADDR_1; ///< For the MBA1_MBRCER register
extern CenReadAddrReg READ_MPE_ADDR_1; ///< For the MBA1_MBMPER register
extern CenReadAddrReg READ_UE_ADDR_1;  ///< For the MBA1_MBUER register

/**
 * @brief  Reads the specified mainline memory read address from hardware.
 * @param  i_membChip A Centaur chip.
 * @param  i_addrReg  The target address register.
 * @param  o_addr     The returned address from hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getCenReadAddr( ExtensibleChip * i_membChip, CenReadAddrReg i_addrReg,
                        CenAddr & o_addr );

/**
 * @brief  Writes the specified mainline memory read address to hardware.
 * @param  i_membChip A Centaur chip.
 * @param  i_addrReg  The target address register.
 * @param  i_addr     The address to write to hardware.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t setCenReadAddr( ExtensibleChip * i_membChip, CenReadAddrReg i_addrReg,
                        const CenAddr & i_addr );

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

