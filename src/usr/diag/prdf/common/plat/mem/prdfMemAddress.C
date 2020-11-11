/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemAddress.C $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

