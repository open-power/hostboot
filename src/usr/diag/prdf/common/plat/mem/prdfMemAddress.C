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
 *         registers for Centaur MBA and P9 MCBIST/MCA.
 */

#include <prdfPlatServices.H>
#include <prdfMemAddress.H>

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfTrace.H>

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
MemAddr MemAddr::fromReadAddr<TYPE_MCBIST>( uint64_t i_addr );
template
MemAddr MemAddr::fromReadAddr<TYPE_OCMB_CHIP>( uint64_t i_addr );


template<>
MemAddr MemAddr::fromReadAddr<TYPE_MEMBUF>( uint64_t i_addr )
{
    uint64_t mrnk   = (i_addr >> 60) &     0x7; //  1: 3
    uint64_t srnk   = (i_addr >> 57) &     0x7; //  4: 6
    uint64_t bnk    = (i_addr >> 53) &     0xf; //  7:10
    uint64_t r16_r0 = (i_addr >> 36) & 0x1ffff; // 11:27
    uint64_t col    = (i_addr >> 27) &   0x1ff; // 28:36
    uint64_t r17    = (i_addr >> 22) &     0x1; // 41

    uint64_t row    = (r17 << 17) | r16_r0;

    return MemAddr( MemRank(mrnk, srnk), bnk, row, col );
}

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
MemAddr MemAddr::fromMaintAddr<TYPE_MCBIST>( uint64_t i_addr );
template
MemAddr MemAddr::fromMaintAddr<TYPE_OCMB_CHIP>( uint64_t i_addr );


template<>
MemAddr MemAddr::fromMaintAddr<TYPE_MBA>( uint64_t i_addr )
{
    uint64_t mrnk   = (i_addr >> 60) &     0x7; //  1: 3
    uint64_t srnk   = (i_addr >> 57) &     0x7; //  4: 6
    uint64_t bnk    = (i_addr >> 53) &     0xf; //  7:10
    uint64_t r16_r0 = (i_addr >> 36) & 0x1ffff; // 11:27
    uint64_t col    = (i_addr >> 27) &   0x1ff; // 28:36 (37:39 tied to 0)
    uint64_t r17    = (i_addr >>  4) &     0x1; // 59

    uint64_t row    = (r17 << 17) | r16_r0;

    return MemAddr( MemRank(mrnk, srnk), bnk, row, col );
}

template<>
MemAddr MemAddr::fromMaintEndAddr<TYPE_MBA>( uint64_t i_addr )
{
    uint64_t mrnk   = (i_addr >> 60) &     0x7; //  1: 3
    uint64_t srnk   = (i_addr >> 57) &     0x7; //  4: 6
    uint64_t bnk    = (i_addr >> 53) &     0xf; //  7:10
    uint64_t r16_r0 = (i_addr >> 36) & 0x1ffff; // 11:27
    uint64_t col    = (i_addr >> 27) &   0x1ff; // 28:36 (37:39 tied to 0)
    uint64_t r17    = (i_addr >> 23) &     0x1; // 40

    uint64_t row    = (r17 << 17) | r16_r0;

    return MemAddr( MemRank(mrnk, srnk), bnk, row, col );
}
template<>
uint64_t MemAddr::toMaintAddr<TYPE_MBA>() const
{
    return (
        ((uint64_t)(iv_rnk.getMaster() &     0x7)<< 60) |  //  1: 3
        ((uint64_t)(iv_rnk.getSlave()  &     0x7)<< 57) |  //  4: 6
        ((uint64_t)(iv_bnk             &     0xf)<< 53) |  //  7:10
        ((uint64_t)(iv_row             & 0x1ffff)<< 36) |  // 11:27
        ((uint64_t)(iv_col             &   0x1ff)<< 27) |  // 28:36
                                                           // 37:39 tied to 0
        ((uint64_t)(iv_row             & 0x20000)>> 13) ); // 59
}

//------------------------------------------------------------------------------
//                       Address Accessor Functions
//------------------------------------------------------------------------------

template<>
uint32_t getMemReadAddr<TYPE_MCBIST>( ExtensibleChip * i_chip, uint32_t i_pos,
                                      MemAddr::ReadReg i_reg, MemAddr & o_addr )
{
    #define PRDF_FUNC "[getMemReadAddr<TYPE_MCBIST>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );
    PRDF_ASSERT( i_pos < MAX_MCA_PER_MCBIST );

    // Get the register string.
    const char * tmp = "";
    switch ( i_reg )
    {
        case MemAddr::READ_NCE_ADDR: tmp = "MBNCER"; break;
        case MemAddr::READ_RCE_ADDR: tmp = "MBRCER"; break;
        case MemAddr::READ_MPE_ADDR: tmp = "MBMPER"; break;
        case MemAddr::READ_UE_ADDR : tmp = "MBUER" ; break;
        case MemAddr::READ_AUE_ADDR: tmp = "MBAUER"; break;
        default: PRDF_ASSERT( false );
    }

    char reg_str[64];
    sprintf( reg_str, "MCB%d_%s", i_pos, tmp );

    // Read the address register
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( reg_str );
    uint32_t o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on %s: i_chip=0x%08x",
                  reg_str, i_chip->getHuid() );
    }
    else
    {
        // Get the address object.
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );
        o_addr = MemAddr::fromReadAddr<TYPE_MCBIST>( addr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

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

template<>
uint32_t getMemReadAddr<TYPE_MEMBUF>( ExtensibleChip * i_chip, uint32_t i_pos,
                                      MemAddr::ReadReg i_reg, MemAddr & o_addr )
{
    #define PRDF_FUNC "[getMemReadAddr<TYPE_MEMBUF>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MEMBUF == i_chip->getType() );
    PRDF_ASSERT( i_pos < MAX_MBA_PER_MEMBUF );

    // Get the register string.
    const char * tmp = "";
    switch ( i_reg )
    {
        case MemAddr::READ_NCE_ADDR: tmp = "MBNCER"; break;
        case MemAddr::READ_RCE_ADDR: tmp = "MBRCER"; break;
        case MemAddr::READ_MPE_ADDR: tmp = "MBMPER"; break;
        case MemAddr::READ_UE_ADDR : tmp = "MBUER" ; break;
        default: PRDF_ASSERT( false );
    }

    char reg_str[64];
    sprintf( reg_str, "MBA%d_%s", i_pos, tmp );

    // Read the address register
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( reg_str );
    uint32_t o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on %s: i_chip=0x%08x",
                  reg_str, i_chip->getHuid() );
    }
    else
    {
        // Get the address object.
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );
        o_addr = MemAddr::fromReadAddr<TYPE_MEMBUF>( addr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemReadAddr<TYPE_MCA>( ExtensibleChip * i_chip,
                                   MemAddr::ReadReg i_reg, MemAddr & o_addr )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

    uint8_t port = i_chip->getPos() % MAX_MCA_PER_MCBIST;

    return getMemReadAddr<TYPE_MCBIST>( mcbChip, port, i_reg, o_addr );
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemReadAddr<TYPE_MBA>( ExtensibleChip * i_chip,
                                   MemAddr::ReadReg i_reg, MemAddr & o_addr )
{
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    ExtensibleChip * membChip = getConnectedParent( i_chip, TYPE_MEMBUF );

    uint8_t mbaPos = i_chip->getPos();

    return getMemReadAddr<TYPE_MEMBUF>( membChip, mbaPos, i_reg, o_addr );
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
uint32_t getMemMaintAddr<TYPE_MCBIST>( ExtensibleChip * i_chip,
                                       MemAddr & o_addr );
template
uint32_t getMemMaintAddr<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                          MemAddr & o_addr );

//------------------------------------------------------------------------------

template<>
uint32_t getMemMaintAddr<TYPE_MCA>( ExtensibleChip * i_chip, MemAddr & o_addr )
{
    #define PRDF_FUNC "[getMemMaintAddr<TYPE_MCA>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    ExtensibleChip * mcbChip = getConnectedParent( i_chip, TYPE_MCBIST );

    return getMemMaintAddr<TYPE_MCBIST>( mcbChip, o_addr );

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemMaintAddr<TYPE_MBA>( ExtensibleChip * i_chip, MemAddr & o_addr )
{
    #define PRDF_FUNC "[getMemMaintAddr<TYPE_MBA>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    // Read the address register
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( "MBMACA" );
    uint32_t o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on MBMACA: i_chip=0x%08x",
                  i_chip->getHuid() );
    }
    else
    {
        // Get the address object.
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );
        o_addr = MemAddr::fromMaintAddr<TYPE_MBA>( addr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t setMemMaintAddr<TYPE_MBA>( ExtensibleChip * i_chip,
                                    const MemAddr & i_addr )
{
    #define PRDF_FUNC "[setMemMaintAddr<TYPE_MBA>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    // Write the address register
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( "MBMACA" );
    reg->SetBitFieldJustified( 0, 64, i_addr.toMaintAddr<TYPE_MBA>() );
    uint32_t o_rc = reg->Write();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on MBMACA: i_chip=0x%08x",
                  i_chip->getHuid() );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t getMemMaintEndAddr<TYPE_MBA>( ExtensibleChip * i_chip,
                                       MemAddr & o_addr )
{
    #define PRDF_FUNC "[getMemMaintEndAddr<TYPE_MBA>] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

    // Read the address register
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( "MBMEA" );
    uint32_t o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read() failed on MBMEA: i_chip=0x%08x",
                  i_chip->getHuid() );
    }
    else
    {
        // Get the address object.
        uint64_t addr = reg->GetBitFieldJustified( 0, 64 );
        o_addr = MemAddr::fromMaintAddr<TYPE_MBA>( addr );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

template<>
uint32_t getMcbistMaintPort<TYPE_MCBIST>( ExtensibleChip * i_mcbChip,
                                          ExtensibleChipList & o_mcaList )
{
    #define PRDF_FUNC "[getMcbistMaintPort] "

    // Check parameters
    PRDF_ASSERT( nullptr != i_mcbChip );
    PRDF_ASSERT( TYPE_MCBIST == i_mcbChip->getType() );

    uint32_t o_rc = SUCCESS;

    o_mcaList.clear();

    SCAN_COMM_REGISTER_CLASS * mcbagra  = i_mcbChip->getRegister( "MCBAGRA" );
    SCAN_COMM_REGISTER_CLASS * mcbmcat  = i_mcbChip->getRegister( "MCBMCAT" );
    SCAN_COMM_REGISTER_CLASS * mcb_cntl = i_mcbChip->getRegister( "MCB_CNTL" );

    do
    {
        o_rc = mcbagra->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCBAGRA: i_mcbChip=0x%08x",
                      i_mcbChip->getHuid() );
            break;
        }

        // Get a mask of all ports in which the command was executed. Use
        // MCB_CNTL[2:5] only if MCBAGRA[10] is b0 OR MCBAGRA[10:11] is b11.
        // Otherwise, use MCBMCAT[38:39].
        uint8_t portMask = 0;
        if ( !mcbagra->IsBitSet(10) || mcbagra->IsBitSet(11) ) // broadcast mode
        {
            o_rc = mcb_cntl->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on MCB_CNTL: "
                          "i_mcbChip=0x%08x", i_mcbChip->getHuid() );
                break;
            }

            portMask = mcb_cntl->GetBitFieldJustified( 2, 4 );
        }
        else // non-broadcast mode
        {
            o_rc = mcbmcat->Read();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Read() failed on MCBMCAT: "
                          "i_mcbChip=0x%08x", i_mcbChip->getHuid() );
                break;
            }

            portMask = 0x8 >> mcbmcat->GetBitFieldJustified( 38, 2 );
        }

        // Get MCAs from all targeted ports.
        for ( uint8_t p = 0; p < MAX_MCA_PER_MCBIST; p++ )
        {
            if ( 0 == (portMask & (0x8 >> p)) ) continue;

            ExtensibleChip * mcaChip = getConnectedChild(i_mcbChip,TYPE_MCA,p);
            if ( nullptr == mcaChip )
            {
                PRDF_ERR( PRDF_FUNC "getConnectedChild(0x%08x,TYPE_MCA,%d) "
                          "returned nullptr", i_mcbChip->getHuid(), p );
                PRDF_ASSERT( false ); // port configured but not functional
            }

            o_mcaList.push_back( mcaChip );
        }

        // The list should never be empty.
        size_t sz_list = o_mcaList.size();
        if ( 0 == sz_list )
        {
            PRDF_ERR( PRDF_FUNC "o_mcaList is empty: i_mcbChip=0x%08x "
                      "portMask=0x%0x", i_mcbChip->getHuid(), portMask );
            PRDF_ASSERT( false ); // mcbist functional but no configured ports
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

#endif

//------------------------------------------------------------------------------

} // end namespace PRDF

