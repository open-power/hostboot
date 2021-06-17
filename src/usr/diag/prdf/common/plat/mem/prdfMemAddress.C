/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemAddress.C $          */
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

/** @file  prdfMemAddress.C
 *  @brief General utilities to read, modify, and write the memory address
 *         registers for OCMB targets.
 */

#include <prdfPlatServices.H>
#include <prdfMemAddress.H>
#include <prdfMemUtils.H>

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfTrace.H>

#include <stdio.h>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------
//  Class MemAddr
//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
MemAddr MemAddr::fromReadAddr( uint64_t i_addr )
{
    uint64_t mrnk = (i_addr >> 59) &     0x7; //  2: 4
    uint64_t srnk = (i_addr >> 56) &     0x7; //  5: 7
    uint64_t row  = (i_addr >> 38) & 0x3ffff; //  8:25
    uint64_t col  = (i_addr >> 31) &    0x7f; // 26:32
    uint64_t bnk  = (i_addr >> 26) &    0x1f; // 33:37

    return MemAddr( MemRank(mrnk, srnk), bnk, row, col );
}

template
MemAddr MemAddr::fromReadAddr<TYPE_OCMB_CHIP>( uint64_t i_addr );

template<TARGETING::TYPE T>
MemAddr MemAddr::fromMaintAddr( uint64_t i_addr )
{
    uint64_t rslct = (i_addr >> 59) &     0x3; //  3: 4
    uint64_t srnk  = (i_addr >> 56) &     0x7; //  5: 7
    uint64_t row   = (i_addr >> 38) & 0x3ffff; //  8:25
    uint64_t col   = (i_addr >> 31) &    0x7f; // 26:32
    uint64_t bnk   = (i_addr >> 26) &    0x1f; // 33:37
    uint64_t dslct = (i_addr >> 23) &     0x1; // 40

    uint64_t mrnk  = (dslct << 2) | rslct;

    return MemAddr( MemRank(mrnk, srnk), bnk, row, col );
}

template
MemAddr MemAddr::fromMaintAddr<TYPE_OCMB_CHIP>( uint64_t i_addr );


template<TARGETING::TYPE T>
uint64_t MemAddr::toMaintAddr() const
{
    return
    (
        ((uint64_t)(iv_rnk.getRankSlct() & 0x3    ) << 59) | // 3:4
        ((uint64_t)(iv_rnk.getSlave()    & 0x7    ) << 56) | // 5:7
        ((uint64_t)(iv_row               & 0x3ffff) << 38) | // 8:25
        ((uint64_t)(iv_col               & 0x7f   ) << 31) | // 26:32
        ((uint64_t)(iv_bnk               & 0x1f   ) << 26) | // 33:37
        ((uint64_t)(iv_rnk.getDimmSlct() & 0x1    ) << 23)   // 40
    );
}

template
uint64_t MemAddr::toMaintAddr<TYPE_OCMB_CHIP>() const;


template<TARGETING::TYPE T>
uint64_t MemAddr::incRowAddr( ExtensibleChip * i_chip ) const
{
    // Format of mss::mcbist::address, bits in ascending order
    // 0:1   port select
    // 2     dimm select
    // 3:4   mrank(0 to 1)
    // 5:7   srank(0 to 2)
    // 8:25  row(0 to 17)
    // 26:32 col(3 to 9)
    // 33:35 bank(0 to 2)
    // 36:37 bank_group(0 to 1)

    // Note: we should not be calling this function for the last address of the
    // master rank.

    // Get the address config to determine whether we are using row17 or not.
    // extraRowBits will denote whether row15:row17 are used (0:3);
    bool twoDimmConfig, col3Config;
    uint8_t mrnkBits, srnkBits, extraRowBits;
    int32_t rc = MemUtils::getAddrConfig<TYPE_OCMB_CHIP>( i_chip,
            iv_rnk.getDimmSlct(), twoDimmConfig, mrnkBits, srnkBits,
            extraRowBits, col3Config );
    if ( SUCCESS != rc )
    {
        PRDF_ERR( "[MemAddr::incRowAddr] getAddrConfig(0x%08x, %d)",
                  i_chip->getHuid(), iv_rnk.getDimmSlct() );
    }

    // Zero out bank and column.
    uint32_t incRow  = 0;
    uint16_t zeroCol = 0;
    uint8_t  zeroBnk = 0;
    uint8_t  srank = iv_rnk.getSlave();

    // If we are on the last row of the secondary rank, we need to increment
    // the srank and zero out the row. If row17 isn't used, don't check it for
    // determining the last row.
    uint8_t shift = 3 - extraRowBits;
    uint32_t lastRow = (0x3ffff >> shift) << shift;
    if ( iv_row == lastRow )
    {
        srank += 1;
    }
    else
    {
        // Increment row
        // Note: we need to increment row0, so we need to reverse the row bits,
        // increment, and then reverse back.
        incRow = MemUtils::reverseBits( iv_row, 18 );
        incRow += 1;
        incRow = MemUtils::reverseBits( incRow, 18 );
    }

    // Note: the uint64_t passed back will be right justified as that is the
    // format we will want for passing into the constructor of
    // mss::mcbist::address.
    return
    (
        ((uint64_t)(iv_rnk.getDimmSlct() & 0x1    ) << 35) | // 2
        ((uint64_t)(iv_rnk.getRankSlct() & 0x3    ) << 33) | // 3:4
        ((uint64_t)(srank                & 0x7    ) << 30) | // 5:7
        ((uint64_t)(incRow               & 0x3ffff) << 12) | // 8:25
        ((uint64_t)(zeroCol              & 0x7f   ) <<  5) | // 26:32
        ((uint64_t)(zeroBnk              & 0x1f   ))         // 33:37
    );
}

template
uint64_t MemAddr::incRowAddr<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip ) const;


//------------------------------------------------------------------------------
//                       Address Accessor Functions
//------------------------------------------------------------------------------

template<>
uint32_t getMemReadAddr<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                         MemAddr::ReadReg i_reg,
                                         MemAddr & o_addr )
{
    #define PRDF_FUNC "[getMemReadAddr<TYPE_OCMB_CHIP>] "

    uint32_t o_rc = SUCCESS;

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    // Get the register string.
    const char * reg_str = "";
    switch ( i_reg )
    {
        case MemAddr::READ_NCE_ADDR: reg_str = "MBNCER"; break;
        case MemAddr::READ_RCE_ADDR: reg_str = "MBRCER"; break;
        case MemAddr::READ_MPE_ADDR: reg_str = "MBMPER"; break;
        case MemAddr::READ_UE_ADDR : reg_str = "MBUER" ; break;
        case MemAddr::READ_AUE_ADDR: reg_str = "MBAUER"; break;
        default: PRDF_ASSERT( false );
    }

    // Read the address register
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( reg_str );
    o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on %s: i_chip=0x%08x",
                  reg_str, i_chip->getHuid() );
    }
    else
    {
        // Get the address object.
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );
        o_addr = MemAddr::fromReadAddr<TYPE_OCMB_CHIP>( addr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t getMemMaintAddr( ExtensibleChip * i_chip, MemAddr & o_addr )
{
    #define PRDF_FUNC "[getMemMaintAddr<T>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( T == i_chip->getType() );

    // Read the address register
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( "MCBMCAT" );
    uint32_t o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on MCBMCAT: i_chip=0x%08x",
                  i_chip->getHuid() );
    }
    else
    {
        // Get the address object.
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );
        o_addr = MemAddr::fromMaintAddr<T>( addr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

template
uint32_t getMemMaintAddr<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          MemAddr & o_addr );

//------------------------------------------------------------------------------

} // end namespace PRDF

