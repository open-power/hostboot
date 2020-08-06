/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemDynDealloc.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <iipSystem.h>
#include <prdfGlobal_common.H>
#include <prdfExtensibleChip.H>
#include <prdfMemDynDealloc.H>
#include <prdfTrace.H>
#include <prdfPlatServices.H>
#include <prdfMemAddress.H>
#include <prdfMemUtils.H>

//------------------------------------------------------------------------------
// Function Definitions
//------------------------------------------------------------------------------

using namespace TARGETING;

namespace PRDF
{
using namespace PlatServices;
using namespace MemUtils;

namespace MemDealloc
{

enum
{
    DDR3 = fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR3,
    DDR4 = fapi2::ENUM_ATTR_EFF_DRAM_GEN_DDR4,

    HASH_MODE_128B = 0,
    HASH_MODE_256B,
};

bool isEnabled()
{
    return ( isHyprRunning() && (isHyprConfigPhyp() || isHyprConfigOpal()) &&
             !isMfgAvpEnabled() && !isMfgHdatAvpEnabled() );
}

int32_t __getAddrConfig( ExtensibleChip * i_chip, uint8_t i_dslct,
                         bool & o_twoDimmConfig, uint8_t & o_mrnkBits,
                         uint8_t & o_srnkBits, uint8_t & o_extraRowBits )
{
    #define PRDF_FUNC "[MemDealloc::__getAddrConfig] "

    int32_t o_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( "MC_ADDR_TRANS" );
    o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS: i_chip=0x%08x",
                  i_chip->getHuid() );
        return o_rc;
    }

    o_twoDimmConfig = false;
    if ( reg->IsBitSet(0) && reg->IsBitSet(16) )
        o_twoDimmConfig = true;

    o_mrnkBits = 0;
    if ( reg->IsBitSet(i_dslct ? 21: 5) ) o_mrnkBits++;
    if ( reg->IsBitSet(i_dslct ? 22: 6) ) o_mrnkBits++;

    o_srnkBits = 0;
    if ( reg->IsBitSet(i_dslct ? 25: 9) ) o_srnkBits++;
    if ( reg->IsBitSet(i_dslct ? 26:10) ) o_srnkBits++;
    if ( reg->IsBitSet(i_dslct ? 27:11) ) o_srnkBits++;

    // According to the hardware team, B2 is used for DDR4e which went away. If
    // for some reason B2 is valid, there is definitely a bug.
    if ( reg->IsBitSet(i_dslct ? 28:12) )
    {
        PRDF_ERR( PRDF_FUNC "B2 enabled in MC_ADDR_TRANS: i_chip=0x%08x "
                  "i_dslct=%d", i_chip->getHuid(), i_dslct );
        return FAIL;
    }

    o_extraRowBits = 0;
    if ( reg->IsBitSet(i_dslct ? 29:13) ) o_extraRowBits++;
    if ( reg->IsBitSet(i_dslct ? 30:14) ) o_extraRowBits++;
    if ( reg->IsBitSet(i_dslct ? 31:15) ) o_extraRowBits++;

    return o_rc;

    #undef PRDF_FUNC
}

uint64_t __maskBits( uint64_t i_val, uint64_t i_numBits )
{
    uint64_t mask = (0xffffffffffffffffull >> i_numBits) << i_numBits;
    return i_val & ~mask;
}

uint64_t __countBits( uint64_t i_val )
{
    uint64_t o_count = 0;

    while ( 0 != i_val )
    {
        if ( 1 == (i_val & 0x1) )
            o_count++;
        i_val >>= 1;
    }

    return o_count;
}

/** @brief  Combines the rank and bank together. Note that the rank/bank will be
 *          split in two to make room for the row and column. This function will
 *          return the rank/bank in both parts (right justified).
 *  @param  i_ds             DIMM select (D).
 *  @param  i_mrnk           Master rank (M0-M2).
 *  @param  i_srnk           Slave rank  (S0-S2).
 *  @param  i_numDs          Number of configured DIMM select bits.
 *  @param  i_numMrnk        Number of configured master rank bits.
 *  @param  i_numSrnk        Number of configured slave rank bits.
 *  @param  i_bnk            Bank (DDR3: B2-B0, DDR4: BG1-BG0,B1-B0).
 *  @param  i_ddrVer         DDR version (DDR3 or DDR4).
 *  @param  i_hash           Hash value (0, 1, or 2).
 *  @param  o_upperRnkBnk    Upper rank/bank bits (right justified).
 *  @param  o_numUpperRnkBnk Number of configured upper rank/bank bits.
 *  @param  o_lowerRnkBnk    Lower rank/bank bits (right justified).
 *  @param  o_numLowerRnkBnk Number of configured lower rank/bank bits.
 */
void getRankBank( uint64_t i_ds,    uint64_t i_mrnk,    uint64_t i_srnk,
                  uint64_t i_numDs, uint64_t i_numMrnk, uint64_t i_numSrnk,
                  uint64_t i_bnk,   uint64_t i_ddrVer,  uint64_t i_hash,
                  uint64_t & o_upperRnkBnk, uint64_t & o_numUpperRnkBnk,
                  uint64_t & o_lowerRnkBnk, uint64_t & o_numLowerRnkBnk )
{
    // The number of bank bits can be determined from the DDR version.
    uint64_t numBnk = (DDR3 == i_ddrVer) ? 3 : 4;

    // Calculate the number of combined rank/bank bits.
    uint64_t numRnkBnk = i_numDs + i_numMrnk + i_numSrnk + numBnk;

    // Build the rank (D,M0-M2,S0-S2)
    uint64_t rnk = i_ds;
    rnk <<= i_numMrnk; rnk |= i_mrnk;
    rnk <<= i_numSrnk; rnk |= i_srnk;

    // Get the rank components
    uint64_t upperRnk = (rnk & ~0x1) << numBnk;
    uint64_t lowerRnk = (rnk &  0x1) << numBnk;

    // Get the bank components
    uint64_t upperBnk = 0, lowerBnk = 0;
    if ( DDR3 == i_ddrVer )
    {
        upperBnk = i_bnk & 0x4; // B2
        lowerBnk = i_bnk & 0x3; // B1-B0
    }
    else // DDR4
    {
        upperBnk = (i_bnk & 0x3) << 2; // B1-B0
        lowerBnk = (i_bnk & 0xC) >> 2; // BG1-BG0
    }

    // The last bit of the rank and the upper part of the bank will be swapped
    // in certain conditions.
    bool swap = ( (0 != i_hash)    || // Normal case:  hash is non-zero
                  (0 != i_numSrnk) || // Special case: any slave ranks
                  (3 == i_numMrnk) ); // Special case: 8 master ranks (3 bits)

    // Combine rank and bank.
    uint64_t rnkBnk = upperRnk                              |
                      lowerRnk >> (swap ? (numBnk - 2) : 0) |
                      upperBnk << (swap ? 1            : 0) |
                      lowerBnk;

    // The combined rank/bank will need to be split to insert the column and
    // row bits.
    uint64_t shift = numBnk + i_hash;
    if ( 0 != i_numSrnk ) shift += i_numSrnk; // Special case: any slave ranks
    if ( 3 == i_numMrnk ) shift += i_numMrnk; // Special case: 8 master ranks

    uint64_t mask = (0xffffffffffffffffull >> shift) << shift;

    o_upperRnkBnk = (rnkBnk &  mask) >> shift;
    o_lowerRnkBnk =  rnkBnk & ~mask;

    o_numUpperRnkBnk = numRnkBnk - shift;
    o_numLowerRnkBnk = shift;
}

/** @brief  Takes the combined rank/bank and adds the row and column. This will
 *          give us bits 0:32 of the Centaur address as described in sections
 *          5.6 and 5.7 of Centaur chip spec.
 *  @param  i_upperRnkBnk    Upper rank/bank bits (right justified).
 *  @param  i_numUpperRnkBnk Number of configured upper rank/bank bits.
 *  @param  i_lowerRnkBnk    Lower rank/bank bits (right justified).
 *  @param  i_numLowerRnkBnk Number of configured lower rank/bank bits.
 *  @param  i_row       Row (R18-R0)
 *  @param  i_numRow    Number of configured row bits.
 *  @param  i_col       Column (C13,C11,C9-C3)
 *  @param  i_numCol    Number of configured column bits.
 *  @param  i_ddrVer    DDR version (DDR3 or DDR4).
 *  @param  i_mbaIlMode MBA interleave mode.     (from MBAXCR[12])
 *  @return Bits 0-34 of the Centaur address (right justified).
 */
uint64_t combineComponents( uint64_t i_upperRnkBnk, uint64_t i_numUpperRnkBnk,
                            uint64_t i_lowerRnkBnk, uint64_t i_numLowerRnkBnk,
                            uint64_t i_row, uint64_t i_numRow,
                            uint64_t i_col, uint64_t i_numCol,
                            uint64_t i_ddrVer, uint64_t i_mbaIlMode )
{
    // Get the row components.
    uint64_t r17 = 0; // DDR4 only
    uint64_t upperRow = 0, numUpperRow = 0;
    uint64_t lowerRow = 0, numLowerRow = 0;
    if ( DDR3 == i_ddrVer )
    {
        // upper:r16-r15 lower:r14-r0
        upperRow = (i_row & 0x18000) >> 15; numUpperRow = i_numRow - 15;
        lowerRow =  i_row & 0x07fff;        numLowerRow = 15;
    }
    else // DDR4
    {
        // upper:r16-r14 lower:r13-r0
        r17      = (i_row & 0x20000) >> 17;
        upperRow = (i_row & 0x1c000) >> 14; numUpperRow = i_numRow - 14;
        lowerRow =  i_row & 0x03fff;        numLowerRow = 14;

        if ( 18 == i_numRow ) numUpperRow -= 1; // r17 is not in numUpperRow
    }

    // Get the column components.
    uint64_t upperCol = i_col & 0x1fe;
    uint64_t c3       = i_col & 0x001;

    uint64_t numUpperCol = i_numCol - 1;
    uint64_t numC3       = 1;

    // Start building the address.
    uint64_t addr = r17;
    addr <<= i_numUpperRnkBnk; addr |= i_upperRnkBnk;
    addr <<=   numUpperRow;    addr |=   upperRow;
    addr <<=   numUpperCol;    addr |=   upperCol;

    if ( HASH_MODE_128B == i_mbaIlMode )
    {
        addr <<=   numC3;          addr |=   c3;
        addr <<= i_numLowerRnkBnk; addr |= i_lowerRnkBnk;

    }
    else // HASH_MODE_256B
    {
        addr <<= i_numLowerRnkBnk; addr |= i_lowerRnkBnk;
        addr <<=   numC3;          addr |=   c3;
    }

    // Insert the fixed row bits.
    addr = (addr & 0xfffffffffffffc00ull) << numLowerRow |
           lowerRow                       << 10          |
           (addr & 0x00000000000003ffull);

    return addr;
}

/** @brief  Translates a physical address (rank, bank, row, col) to a 40 bit
 *          Centaur address. The algorithm is derived from Sections 5.4, 5.6,
 *          and 5.7 of Centaur chip spec.
 *  @param  i_ds        DIMM select (D).
 *  @param  i_mrnk      Master rank (M0-M2).
 *  @param  i_srnk      Slave rank  (S0-S2).
 *  @param  i_numMrnk   Number of configured master rank bits.
 *  @param  i_numSrnk   Number of configured slave rank bits.
 *  @param  i_row       Row (R18-R0)
 *  @param  i_numRow    Number of configured row bits.
 *  @param  i_col       Column (C13,C11,C9-C3)
 *  @param  i_numCol    Number of configured column bits.
 *  @param  i_bnk       Bank (DDR3: B2-B0, DDR4: BG1-BG0,B1-B0).
 *  @param  i_mba       MBA position (0 or 1)
 *  @param  i_ddrVer    DDR version (DDR3 or DDR4).
 *  @param  i_cenIlMode Centaur interleave mode. (from MBSXCR[0:4])
 *  @param  i_mbaIlMode MBA interleave mode.     (from MBAXCR[12])
 *  @param  i_hash      Rank hash.               (from MBAXCR[10:11])
 *  @param  i_cfg       Rank config.             (from MBAXCR[8])
 *  @return The returned 40-bit Cenaur address.
 */
uint64_t transPhysToCenAddr( uint64_t i_ds,  uint64_t i_mrnk, uint64_t i_srnk,
                             uint64_t i_numMrnk, uint64_t i_numSrnk,
                             uint64_t i_row, uint64_t i_numRow,
                             uint64_t i_col, uint64_t i_numCol,
                             uint64_t i_bnk, uint64_t i_mba,
                             uint64_t i_ddrVer,
                             uint64_t i_cenIlMode, uint64_t i_mbaIlMode,
                             uint64_t i_hash, uint64_t i_cfg )
{
    // Get the combine rank/bank.
    uint64_t upperRnkBnk, numUpperRnkBnk;
    uint64_t lowerRnkBnk, numLowerRnkBnk;
    getRankBank( i_ds,  i_mrnk,    i_srnk,
                 i_cfg, i_numMrnk, i_numSrnk,
                 i_bnk, i_ddrVer,  i_hash,
                 upperRnkBnk, numUpperRnkBnk,
                 lowerRnkBnk, numLowerRnkBnk );

    // Get bits 0:32 as described in sections 5.6 and 5.7 of the Centaur spec.
    uint64_t addr = combineComponents( upperRnkBnk, numUpperRnkBnk,
                                       lowerRnkBnk, numLowerRnkBnk,
                                       i_row, i_numRow, i_col, i_numCol,
                                       i_ddrVer, i_mbaIlMode );

    // Adjust for Centaur interleave mode as described in sections 5.4.1 of the
    // Centaur spec.
    if ( 0 != i_cenIlMode )
    {
        // MBSXCR[0] just indicates there is interleaving so that can be
        // ignored and we'll just use MBSXCR[1:4].
        i_cenIlMode &= 0xf;

        // Now, a value of 0 indicates bit 23 is interleaved and a value of 9
        // indicates bit 32 is interleaved. So we should be able to invert it to
        // give us the shift value.
        uint64_t shift = 9 - i_cenIlMode;
        uint64_t mask  = (0xffffffffffffffffull >> shift) << shift;

        // Insert the MBA bit.
        addr = (addr & mask) << 1 | i_mba << shift | (addr & ~mask);
    }

    // Bits 33:39 are zero.
    addr <<= 7;

    return addr;
}

// Given the number of configured ranks, return the number of configured rank
// bits (i.e. 1 rank=0 bits, 2 ranks=1 bit, 4 ranks=2 bits, 8 ranks=3 bits).
// This could be achieved with log2() from math.h, but we don't want to mess
// with floating point numbers (FSP uses C++ standard).
uint64_t ranks2bits( uint64_t i_numRnks )
{
    switch ( i_numRnks )
    {
        case 1: return 0;
        case 2: return 1;
        case 4: return 2;
        case 8: return 3;
    }

    return 0;
}

template <TYPE T>
int32_t __getPortAddr( ExtensibleChip * i_chip, MemAddr i_addr,
                               uint64_t & o_addr );

template <>
int32_t __getPortAddr<TYPE_MCA>( ExtensibleChip * i_chip, MemAddr i_addr,
                                 uint64_t & o_addr )
{
    int32_t o_rc = SUCCESS;

    o_addr = 0;

    // Local vars for address fields
    uint64_t col   = reverseBits(i_addr.getCol(),  7);   // C9 C8 C7 C6 C5 C4 C3
    uint64_t row   = reverseBits(i_addr.getRow(), 18);   // R17 R16 R15 .. R1 R0
    uint64_t bnk   = i_addr.getBank();                   //     B0 B1 B2 BG0 BG1
    uint64_t srnk  = i_addr.getRank().getSlave();        //             S0 S1 S2
    uint64_t mrnk  = i_addr.getRank().getRankSlct();     //                M0 M1
    uint64_t dslct = i_addr.getRank().getDimmSlct();     //                    D

    // Determine if a two DIMM config is used. Also, determine how many
    // mrank (M0-M1), srnk (S0-S2), or extra row (R17-R15) bits are used.
    bool twoDimmConfig;
    uint8_t mrnkBits, srnkBits, extraRowBits;
    o_rc = __getAddrConfig( i_chip, dslct, twoDimmConfig, mrnkBits, srnkBits,
                            extraRowBits );
    if ( SUCCESS != o_rc ) return o_rc;

    // Mask off the non-configured bits. If this address came from hardware,
    // this would not be a problem. However, the get_mrank_range() and
    // get_srank_range() HWPS got lazy just set the entire fields and did not
    // take into account the actual bit ranges.
    mrnk = __maskBits( mrnk, mrnkBits );
    srnk = __maskBits( srnk, srnkBits );
    row  = __maskBits( row,  15 + extraRowBits );

    // Combine master and slave ranks.
    uint64_t rnk     = (mrnk << srnkBits) | srnk;
    uint8_t  rnkBits = mrnkBits + srnkBits;

    // Now split the DIMM select and combined rank into components.
    uint64_t rnk_pt1     = 0, rnk_pt2     = 0, rnk_pt3     = 0;
    uint8_t  rnkBits_pt1 = 0, rnkBits_pt2 = 0, rnkBits_pt3 = 0;

    if ( 0 == rnkBits )
    {
        if ( twoDimmConfig ) // The DIMM select goes into part 3.
        {
            rnk_pt3 = dslct; rnkBits_pt3 = 1;
        }
    }
    else // At least one master or slave.
    {
        // Put the LSB of the combined rank in part 3 and the rest in part 2.
        rnk_pt3 = rnk & 0x1; rnkBits_pt3 = 1;
        rnk_pt2 = rnk >> 1;  rnkBits_pt2 = rnkBits - 1;

        if ( twoDimmConfig ) // The DIMM select goes into part 1.
        {
            rnk_pt1 = dslct; rnkBits_pt1 = 1;
        }
    }

    // Split the row into its components.
    uint64_t r17_r15 = (row & 0x38000) >> 15;
    uint64_t r14     = (row & 0x04000) >> 14;
    uint64_t r13     = (row & 0x02000) >> 13;
    uint64_t r12_r0  = (row & 0x01fff);

    // Split the column into its components.
    uint64_t c9_c4 = (col & 0x7e) >> 1;
    uint64_t c3    = (col & 0x01);

    // Split the bank into its components.
    uint64_t b0      = (bnk & 0x10) >> 4;
    uint64_t b1      = (bnk & 0x08) >> 3;
    // NOTE: B2 is not supported on Nimbus.
    uint64_t bg0_bg1 = (bnk & 0x03);

    // Now start building the flexible part of the address (bits 0-7,23-33).
    o_addr = (o_addr << rnkBits_pt1 ) | rnk_pt1;
    o_addr = (o_addr << extraRowBits) | r17_r15;
    o_addr = (o_addr << rnkBits_pt2 ) | rnk_pt2;
    o_addr = (o_addr << 6           ) | c9_c4;
    o_addr = (o_addr << 1           ) | b0;
    o_addr = (o_addr << rnkBits_pt3 ) | rnk_pt3;
    o_addr = (o_addr << 1           ) | b1;
    o_addr = (o_addr << 2           ) | bg0_bg1;
    o_addr = (o_addr << 1           ) | c3;

    // C2 is in bit 34, but the Nimbus physical address does not contain a C2.
    // It will be set to 0 for now. Also, bits 35-39 are the rest of the cache
    // line address, which we do not need. So, that will be set to 0 as well.
    o_addr <<= 6;

    // Finally, insert R14,R12-R0,R13 into bits 8-22.
    o_addr  = ((o_addr & 0xfffffe0000ull) << 15) | (o_addr & 0x000001ffffull);
    o_addr |= ((r14 << 14) | (r12_r0 << 1) | r13) << 17;

    return o_rc;
}

void __adjustCapiAddrBitPos( uint8_t & io_bitPos )
{
    // Note: the translation bitmaps are all 5 bits that are defined
    // consistently as:
    // 00000 = CAPI_Address(5)
    // 00001 = CAPI_Address(6)
    // 00010 = CAPI_Address(7)
    // ...
    // 01010 = CAPI_Address(15)
    // 01011 = CAPI_Address(31)
    // 01100 = CAPI_Address(32)
    // ...
    // 10011 = CAPI_Address(39)
    // So the value from the regs can be converted to the CAPI address bit pos
    // by adding 5 if the value is less than or equal to 10, or by adding 20
    // if it is above 10.

    if ( io_bitPos <= 10 )
    {
        io_bitPos += 5;
    }
    else
    {
        io_bitPos += 20;
    }
}

template <>
int32_t __getPortAddr<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip, MemAddr i_addr,
                                       uint64_t & o_addr )
{
    #define PRDF_FUNC "[MemDealloc::__getPortAddr<TYPE_OCMB_CHIP>] "

    int32_t o_rc = SUCCESS;

    o_addr = 0;

    // Local vars for address fields
    uint64_t col   = reverseBits(i_addr.getCol(),  7);   // C9 C8 C7 C6 C5 C4 C3
    uint64_t row   = reverseBits(i_addr.getRow(), 18);   // R17 R16 R15 .. R1 R0
    uint64_t bnk   = i_addr.getBank();                   //     B0 B1 B2 BG0 BG1
    uint64_t srnk  = i_addr.getRank().getSlave();        //             S0 S1 S2
    uint64_t mrnk  = i_addr.getRank().getRankSlct();     //                M0 M1
    uint64_t dslct = i_addr.getRank().getDimmSlct();     //                    D

    // Determine if a two DIMM config is used. Also, determine how many
    // mrank (M0-M1), srnk (S0-S2), or extra row (R17-R15) bits are used.
    bool twoDimmConfig;
    uint8_t mrnkBits, srnkBits, extraRowBits;
    o_rc = __getAddrConfig( i_chip, dslct, twoDimmConfig, mrnkBits, srnkBits,
                            extraRowBits );
    if ( SUCCESS != o_rc ) return o_rc;

    // Mask off the non-configured bits. If this address came from hardware,
    // this would not be a problem. However, the get_mrank_range() and
    // get_srank_range() HWPS got lazy just set the entire fields and did not
    // take into account the actual bit ranges.
    mrnk = __maskBits( mrnk, mrnkBits );
    srnk = __maskBits( srnk, srnkBits );
    row  = __maskBits( row,  15 + extraRowBits );

    // Insert the needed bits based on the config defined in the MC Address
    // Translation Registers.

    uint8_t bitPos = 0;

    // Split the row into its components.
    uint8_t  r17    = (row & 0x20000) >> 17;
    uint8_t  r16    = (row & 0x10000) >> 16;
    uint8_t  r15    = (row & 0x08000) >> 15;
    uint16_t r14_r0 = (row & 0x07fff);

    // Split the master rank and slave rank into their components
    uint8_t m0 = (mrnk & 0x2) >> 1;
    uint8_t m1 = (mrnk & 0x1);

    uint8_t s0 = (srnk & 0x4) >> 2;
    uint8_t s1 = (srnk & 0x2) >> 1;
    uint8_t s2 = (srnk & 0x1);

    // Split the column into its components
    uint8_t c9 = (col & 0x40) >> 6;
    uint8_t c8 = (col & 0x20) >> 5;
    uint8_t c7 = (col & 0x10) >> 4;
    uint8_t c6 = (col & 0x08) >> 3;
    uint8_t c5 = (col & 0x04) >> 2;
    uint8_t c4 = (col & 0x02) >> 1;
    uint8_t c3 = (col & 0x01);

    // Split the bank and bank group into their components
    // Note: B2 is not used for OCMB
    uint8_t b0 = (bnk & 0x10) >> 4;
    uint8_t b1 = (bnk & 0x08) >> 3;

    uint8_t bg0 = (bnk & 0x2) >> 1;
    uint8_t bg1 = (bnk & 0x1);

    // Row bits 14:0 are always at CAPI addr position 30:16
    o_addr |= (r14_r0 << 16);

    // Check MC_ADDR_TRANS0 register for bit positions
    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister( "MC_ADDR_TRANS" );
    o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS: i_chip=0x%08x",
                  i_chip->getHuid() );
        return o_rc;
    }

    // If the DIMM select is valid, insert that bit
    if ( twoDimmConfig )
    {
        // DIMM bitmap: MC_ADDR_TRANS0[33:37]
        bitPos = reg->GetBitFieldJustified( 33, 5 );
        __adjustCapiAddrBitPos( bitPos );
        o_addr |= (dslct << bitPos);
    }

    // Insert any of the master rank bits that are valid
    switch( mrnkBits )
    {
        case 2:
            // Master rank 0 bitmap: MC_ADDR_TRANS0[38:42]
            bitPos = reg->GetBitFieldJustified( 38, 5 );
            __adjustCapiAddrBitPos( bitPos );
            o_addr |= (m0 << bitPos);
        case 1:
            // Master rank 1 bitmap: MC_ADDR_TRANS0[43:47]
            bitPos = reg->GetBitFieldJustified( 43, 5 );
            __adjustCapiAddrBitPos( bitPos );
            o_addr |= (m1 << bitPos);
            break;
    }

    // Insert any extra row bits (17:15) that are valid
    switch ( extraRowBits )
    {
        case 3:
            // Row 17 bitmap: MC_ADDR_TRANS0[49:53]
            bitPos = reg->GetBitFieldJustified( 49, 5 );
            __adjustCapiAddrBitPos( bitPos );
            o_addr |= (r17 << bitPos);
        case 2:
            // Row 16 bitmap: MC_ADDR_TRANS0[54:58]
            bitPos = reg->GetBitFieldJustified( 54, 5 );
            __adjustCapiAddrBitPos( bitPos );
            o_addr |= (r16 << bitPos);
        case 1:
            // Row 15 bitmap: MC_ADDR_TRANS0[59:63]
            bitPos = reg->GetBitFieldJustified( 59, 5 );
            __adjustCapiAddrBitPos( bitPos );
            o_addr |= (r15 << bitPos);
            break;
    }

    // Check MC_ADDR_TRANS1 register for bit positions
    reg = i_chip->getRegister( "MC_ADDR_TRANS1" );
    o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS1: i_chip=0x%08x",
                  i_chip->getHuid() );
        return o_rc;
    }

    // Insert any of the slave rank bits that are valid
    switch ( srnkBits )
    {
        case 3:
            // Slave rank 0 bitmap: MC_ADDR_TRANS1[3:7]
            bitPos = reg->GetBitFieldJustified( 3, 5 );
            __adjustCapiAddrBitPos( bitPos );
            o_addr |= (s0 << bitPos);
        case 2:
            // Slave rank 1 bitmap: MC_ADDR_TRANS1[11:15]
            bitPos = reg->GetBitFieldJustified( 11, 5 );
            __adjustCapiAddrBitPos( bitPos );
            o_addr |= (s1 << bitPos);
        case 1:
            // Slave rank 2 bitmap: MC_ADDR_TRANS1[19:23]
            bitPos = reg->GetBitFieldJustified( 19, 5 );
            __adjustCapiAddrBitPos( bitPos );
            o_addr |= (s2 << bitPos);
            break;
    }

    // Column 3 bitmap: MC_ADDR_TRANS1[30:34]
    bitPos = reg->GetBitFieldJustified( 30, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (c3 << bitPos);

    // Column 4 bitmap: MC_ADDR_TRANS1[35:39]
    bitPos = reg->GetBitFieldJustified( 35, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (c4 << bitPos);

    // Column 5 bitmap: MC_ADDR_TRANS1[43:47]
    bitPos = reg->GetBitFieldJustified( 43, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (c5 << bitPos);

    // Column 6 bitmap: MC_ADDR_TRANS1[51:55]
    bitPos = reg->GetBitFieldJustified( 51, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (c6 << bitPos);

    // Column 7 bitmap: MC_ADDR_TRANS1[59:63]
    bitPos = reg->GetBitFieldJustified( 59, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (c7 << bitPos);

    // Check MC_ADDR_TRANS2 register for bit positions
    reg = i_chip->getRegister( "MC_ADDR_TRANS2" );
    o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS2: i_chip=0x%08x",
                  i_chip->getHuid() );
        return o_rc;
    }

    // Column 8 bitmap: MC_ADDR_TRANS2[3:7]
    bitPos = reg->GetBitFieldJustified( 3, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (c8 << bitPos);

    // Column 9 bitmap: MC_ADDR_TRANS2[11:15]
    bitPos = reg->GetBitFieldJustified( 11, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (c9 << bitPos);

    // Bank 0 bitmap: MC_ADDR_TRANS2[19:23]
    bitPos = reg->GetBitFieldJustified( 19, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (b0 << bitPos );

    // Bank 1 bitmap: MC_ADDR_TRANS2[27:31]
    bitPos = reg->GetBitFieldJustified( 27, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (b1 << bitPos);

    // Bank 2 bitmap: MC_ADDR_TRANS2[35:39]
    // Note: Bank2 not used for OCMB

    // Bank group 0 bitmap: MC_ADDR_TRANS2[43:47]
    bitPos = reg->GetBitFieldJustified( 43, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (bg0 << bitPos);

    // Bank group 1 bitmap: MC_ADDR_TRANS2[51:55]
    bitPos = reg->GetBitFieldJustified( 51, 5 );
    __adjustCapiAddrBitPos( bitPos );
    o_addr |= (bg1 << bitPos);

    return o_rc;

    #undef PRDF_FUNC
}

template <>
int32_t __getPortAddr<TYPE_MBA>( ExtensibleChip * i_chip, MemAddr i_addr,
                                 uint64_t & o_addr )
{
    #define PRDF_FUNC "[DEALLOC::__getPortAddr<TYPE_MBA>] "

    int32_t o_rc = SUCCESS;

    o_addr = 0;

    TargetHandle_t mba  = i_chip->GetChipHandle();

    ExtensibleChip * mbChip = getConnectedParent(i_chip, TYPE_MEMBUF);
    uint64_t mbaPos = i_chip->getPos();

    uint64_t ds   = i_addr.getRank().getDimmSlct(); // D
    uint64_t mrnk = i_addr.getRank().getRankSlct(); // M0-M2
    uint64_t srnk = i_addr.getRank().getSlave();    // S0-S2

    uint64_t row  = i_addr.getRow();    // R18-R0
    uint64_t col  = i_addr.getCol();    // C13,C11,C9-C3
    uint64_t bnk  = i_addr.getBank();   // DDR3: B2-B0, DDR4: BG1-BG0,B1-B0

    // Get the number of configured address bits for the master and slave ranks.
    uint64_t num_mrnk = getNumMasterRanksPerDimm<TYPE_MBA>( mba, ds );
    uint64_t num_srnk = getNumRanksPerDimm<TYPE_MBA>( mba, ds ) / num_mrnk;

    uint64_t mrnkBits = ranks2bits( num_mrnk );
    uint64_t srnkBits = ranks2bits( num_srnk );

    // Get the number of configured address bits for the row and column.
    uint8_t rowBits = getRowNumConfig<TYPE_MBA>( mba );
    uint8_t colBits = getColNumConfig<TYPE_MBA>( mba );

    do
    {
        // The attribute used in getDimmRowCol() returns a value for colBits
        // which includes c2-c0. Those bits are tied to zero and are not
        // included in col. Therefore, we need to subtract 3 to get the real
        // value.
        colBits = colBits - 3;

        // Get the DDR verion of the DIMM (DDR3, DDR4, etc...)
        uint8_t ddrVer = getDramGen<TYPE_MBA>( mba );

        // Get the Centaur interleave mode (MBSXCR[0:4]).
        SCAN_COMM_REGISTER_CLASS * mbsxcr = mbChip->getRegister("MBSXCR");
        o_rc = mbsxcr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSXCR. HUID:0x%08X",
                      mbChip->GetId() ) ;
            break;
        }

        uint64_t cenIlMode = mbsxcr->GetBitFieldJustified( 0, 5 );

        // Get the rank config (MBAXCR[8]), rank hash (MBAXCR[10:11]), and
        // MBA interleave mode (MBAXCR[12]).
        const char * reg_str = ( 0 == mbaPos ) ? "MBA0_MBAXCR" : "MBA1_MBAXCR";
        SCAN_COMM_REGISTER_CLASS * mbaxcr = mbChip->getRegister( reg_str );
        o_rc = mbaxcr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s. HUID:0X%08X",
                      reg_str, mbChip->GetId() );
            break;
        }

        uint8_t cfg       = mbaxcr->GetBitFieldJustified(  8, 1 );
        uint8_t hash      = mbaxcr->GetBitFieldJustified( 10, 2 );
        uint8_t mbaIlMode = mbaxcr->GetBitFieldJustified( 12, 1 );

        // Form the address from info gathered above
        o_addr = transPhysToCenAddr( ds, mrnk, srnk,
                                     mrnkBits, srnkBits,
                                     row, rowBits, col, colBits,
                                     bnk, mbaPos,
                                     ddrVer,
                                     cenIlMode, mbaIlMode,
                                     hash, cfg );


    } while(0);

    return o_rc;

    #undef PRDF_FUNC

}
//------------------------------------------------------------------------------

template<TYPE T>
void __getGrpPrms( ExtensibleChip * i_chip, uint8_t & o_portPos,
                   SCAN_COMM_REGISTER_CLASS * &o_mcfgp,
                   SCAN_COMM_REGISTER_CLASS * &o_mcfgpm );

template<>
void __getGrpPrms<TYPE_MCA>( ExtensibleChip * i_chip, uint8_t & o_portPos,
                             SCAN_COMM_REGISTER_CLASS * &o_mcfgp,
                             SCAN_COMM_REGISTER_CLASS * &o_mcfgpm )
{
    // Get the connected MCS chip and MCA target position.
    ExtensibleChip * mcs_chip = getConnectedParent( i_chip, TYPE_MCS );
    o_portPos = i_chip->getPos() % MAX_MCA_PER_MCS;

    o_mcfgp  = mcs_chip->getRegister("MCFGP");
    o_mcfgpm = mcs_chip->getRegister("MCFGPM");

}

template<>
void __getGrpPrms<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip, uint8_t & o_portPos,
                                   SCAN_COMM_REGISTER_CLASS * &o_mcfgp,
                                   SCAN_COMM_REGISTER_CLASS * &o_mcfgpm )
{
    // Get the connected parent MI;
    ExtensibleChip * mcc = getConnectedParent( i_chip, TYPE_MCC );
    ExtensibleChip * mi  = getConnectedParent( mcc, TYPE_MI );

    // TODO RTC 210072 - support for multiple ports
    o_portPos = 0;

    // Get the position of the MCC relative to the MI (0:1)
    uint8_t chnlPos = mcc->getPos() % MAX_MCC_PER_MI;

    char mcfgpName[64];
    sprintf( mcfgpName, "MCFGP%d", chnlPos );

    char mcfgpmName[64];
    sprintf( mcfgpmName, "MCFGPM%d", chnlPos );

    o_mcfgp  = mi->getRegister( mcfgpName );
    o_mcfgpm = mi->getRegister( mcfgpmName );

}

template<>
void __getGrpPrms<TYPE_MBA>( ExtensibleChip * i_chip, uint8_t & o_portPos,
                             SCAN_COMM_REGISTER_CLASS * &o_mcfgp,
                             SCAN_COMM_REGISTER_CLASS * &o_mcfgpm )
{
    // Get the connected MI chip and MBA target position.
    ExtensibleChip * mi_chip = getConnectedParent( i_chip, TYPE_MI );
    o_portPos = i_chip->getPos();

    o_mcfgp  = mi_chip->getRegister("MCFGP");
    o_mcfgpm = mi_chip->getRegister("MCFGPM");
}



template<TYPE T>
uint32_t __getGrpInfo( ExtensibleChip * i_chip, uint64_t & o_grpChnls,
                       uint64_t & o_grpId, uint64_t & o_grpSize,
                       uint64_t & o_grpBar )
{
    #define PRDF_FUNC "[MemDealloc::__getGrpInfo] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get mcaPos and MCFGP/M registers
        uint8_t portPos = 0xFF;
        SCAN_COMM_REGISTER_CLASS * mcfgp  = nullptr;
        SCAN_COMM_REGISTER_CLASS * mcfgpm = nullptr;
        __getGrpPrms<T>( i_chip, portPos, mcfgp, mcfgpm );

        o_rc = mcfgp->Read();  if ( SUCCESS != o_rc ) break;
        o_rc = mcfgpm->Read(); if ( SUCCESS != o_rc ) break;

        // Get the number of channels in this group.
        uint8_t mcGrpCnfg = mcfgp->GetBitFieldJustified( 1, 4 );
        switch ( mcGrpCnfg )
        {
            case 0: o_grpChnls = 1;                      break; // 11
            case 1: o_grpChnls = (0 == portPos) ? 1 : 3; break; // 13
            case 2: o_grpChnls = (0 == portPos) ? 3 : 1; break; // 31
            case 3: o_grpChnls = 3;                      break; // 33
            case 4: o_grpChnls = 2;                      break; // 2D
            case 5: o_grpChnls = 2;                      break; // 2S
            case 6: o_grpChnls = 4;                      break; // 4
            case 7: o_grpChnls = 6;                      break; // 6
            case 8: o_grpChnls = 8;                      break; // 8
            default:
                PRDF_ERR( PRDF_FUNC "Invalid MC channels per group value: 0x%x "
                          "on 0x%08x", mcGrpCnfg, i_chip->getHuid() );
                o_rc = FAIL;
        }
        if ( SUCCESS != o_rc ) break;

        // Get the group ID and group size.
        o_grpId   = mcfgp->GetBitFieldJustified( (0 == portPos) ? 5 : 8, 3 );
        o_grpSize = mcfgp->GetBitFieldJustified( 13, 11 );

        // Get the base address (BAR).
        if ( 0 == portPos ) // MCS channel 0
        {
            // Channel 0 is always from the MCFGP.
            o_grpBar = mcfgp->GetBitFieldJustified(24, 24);
        }
        else // MCS channel 1
        {
            switch ( mcGrpCnfg )
            {
                // Each channel is in an different group. Use the MCFGPM.
                case 0: // 11
                case 1: // 13
                case 2: // 31
                case 3: // 33
                case 4: // 2D
                    o_grpBar = mcfgpm->GetBitFieldJustified(24, 24);
                    break;

                // Both channels are in the same group. Use the MCFGP.
                case 5: // 2S
                case 6: // 4
                case 7: // 6
                case 8: // 8
                    o_grpBar = mcfgp->GetBitFieldJustified(24, 24);
                    break;

                default:
                    PRDF_ERR( PRDF_FUNC "Invalid MC channels per group value: "
                              "0x%x on 0x%08x", mcGrpCnfg,
                              i_chip->getHuid() );
                    o_rc = FAIL;
            }
        }
        if ( SUCCESS != o_rc ) break;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t __getGrpInfo<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                       uint64_t & o_grpChnls,
                                       uint64_t & o_grpId, uint64_t & o_grpSize,
                                       uint64_t & o_grpBar )
{
    #define PRDF_FUNC "[MemDealloc::__getGrpInfo] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get portPos and MCFGP/M registers
        uint8_t portPos = 0xFF;
        SCAN_COMM_REGISTER_CLASS * mcfgp  = nullptr;
        SCAN_COMM_REGISTER_CLASS * mcfgpm = nullptr;
        __getGrpPrms<TYPE_OCMB_CHIP>( i_chip, portPos, mcfgp, mcfgpm );

        o_rc = mcfgp->Read();  if ( SUCCESS != o_rc ) break;

        // Get the number of channels in this group: MCFGP[40:42]
        uint8_t mcGrpCnfg = mcfgp->GetBitFieldJustified( 40, 3 );
        switch ( mcGrpCnfg )
        {
            case 0: o_grpChnls = 8; break; // 8MCS
            case 1: o_grpChnls = 1; break; // 1MCS
            case 2: o_grpChnls = 2; break; // 2MCS
            case 3: o_grpChnls = 3; break; // 3MCS
            case 4: o_grpChnls = 4; break; // 4MCS
            case 5: o_grpChnls = 6; break; // 6MCS
            default:
                PRDF_ERR( PRDF_FUNC "Invalid MC channels per group value: 0x%x "
                          "on 0x%08x", mcGrpCnfg, i_chip->getHuid() );
                o_rc = FAIL;
        }
        if ( SUCCESS != o_rc ) break;

        // Get the group ID and group size.
        o_grpId   = mcfgp->GetBitFieldJustified( 43, 3 );  // MCFGP[43:45]
        o_grpSize = mcfgp->GetBitFieldJustified( 25, 15 ); // MCFGP[25:39]

        // TODO RTC 210072 - support for multiple ports, see generic handling

        // Get the base address (BAR).
        // Channel 0 is always from the MCFGP.
        o_grpBar = mcfgp->GetBitFieldJustified(1, 24); // MCFGP[1:24]

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TYPE T>
uint32_t __insertGrpId( ExtensibleChip * i_chip, uint64_t & io_addr,
                        uint64_t i_grpChnls, uint64_t i_grpId )
{
    #define PRDF_FUNC "[MemDealloc::__insertGrpId<T>] "

    uint32_t o_rc = SUCCESS;

    // Notes on 3 and 6 channel per group configs:
    //      Let's use an example of 3 channels in a group with 4 GB per channel.
    //      The group size will be configured like there are 4 channels (16 GB
    //      total). However, only the first 12 GB of the 16 GB are used because
    //      there are only three channels. Since we need a contiguous address
    //      space and can't have holes every fourth address, the hardware uses
    //      some crafty mod3 logic to evenly distribute the addresses among the
    //      3 channels. The mod3 hashing is based on the address itself so there
    //      isn't a traditional group select like we are used to in the 2, 4,
    //      and 8 channel group configs. For 3 MC/group configs, there is no
    //      shifting (same as 1 MC/group). For 6 MC/group configs, we need to
    //      insert the least significant bit of the group ID into RA[56] (same
    //      as 2 MC/group).

    uint64_t upper33 = io_addr & 0xFFFFFFFF80ull;
    uint64_t lower7  = io_addr & 0x000000007full;

    switch ( i_grpChnls )
    {
        case 1:
        case 3: // no shifting
            break;

        case 2:
        case 6: // insert 1 bit
            io_addr = (upper33 << 1) | ((i_grpId & 0x1) << 7) | lower7;
            break;

        case 4: // insert 2 bits
            io_addr = (upper33 << 2) | ((i_grpId & 0x3) << 7) | lower7;
            break;

        case 8: // insert 3 bits
            io_addr = (upper33 << 3) | ((i_grpId & 0x7) << 7) | lower7;
            break;

        default:
            PRDF_ERR( PRDF_FUNC "Invalid MC channels per group value %d",
                      i_grpChnls );
            o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t __insertGrpId<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                        uint64_t & io_addr, uint64_t i_grpChnls,
                                        uint64_t i_grpId )
{
    #define PRDF_FUNC "[MemDealloc::__insertGrpId<TYPE_OCMB_CHIP>] "

    uint32_t o_rc = SUCCESS;

    uint64_t upper33 = io_addr & 0xFFFFFFFF80ull;
    uint64_t lower7  = io_addr & 0x000000007full;

    bool subChanAEnable = false;
    bool subChanBEnable = false;
    bool bothSubChansEnabled = false;

    ExtensibleChip * mcc = getConnectedParent( i_chip, TYPE_MCC );

    // Check both subchannels whether we can get the connected OCMB to
    // determine whether they are enabled.
    // Check for subchannel A
    ExtensibleChip * subchanA = getConnectedChild( mcc, TYPE_OCMB_CHIP, 0 );
    if ( nullptr != subchanA ) subChanAEnable = true;

    // Check for subchannel B
    ExtensibleChip * subchanB = getConnectedChild( mcc, TYPE_OCMB_CHIP, 1 );
    if ( nullptr != subchanB ) subChanBEnable = true;

    // Check if both subchannels were enabled
    if ( subChanAEnable && subChanBEnable ) bothSubChansEnabled = true;

    // If both subchannels are enabled, bit 56 of the address will contain the
    // subchannel select bit.
    if ( bothSubChansEnabled )
    {
        TargetHandle_t omi = getConnectedParent( i_chip->getTrgt(), TYPE_OMI );
        uint8_t ocmbChnl = getTargetPosition(omi) % MAX_OMI_PER_MCC; // 0:1
        uint8_t bitInsert = 0;

        switch ( i_grpChnls )
        {
            case 1: // insert 1 bit for subchannel select
            case 3:
            case 6:
                bitInsert = ( ocmbChnl & 0x1 );
                io_addr = (upper33 << 1) | (bitInsert << 7) | lower7;
                break;

            case 2: // insert 1 bit for subchannel select and 1 bit for grpId
                bitInsert = ( ((i_grpId & 0x1) << 1) | (ocmbChnl & 0x1) );
                io_addr = (upper33 << 2) | (bitInsert << 7) | lower7;
                break;

            case 4: // insert 1 bit for subchannel select and 2 bits for grpId
                bitInsert = ( ((i_grpId & 0x3) << 1) | (ocmbChnl & 0x1) );
                io_addr = (upper33 << 3) | (bitInsert << 7) | lower7;
                break;

            case 8: // insert 1 bit for subchannel select and 3 bits for grpId
                bitInsert = ( ((i_grpId & 0x7) << 1) | (ocmbChnl & 0x1) );
                io_addr = (upper33 << 4) | (bitInsert << 7) | lower7;
                break;

            default:
                PRDF_ERR( PRDF_FUNC "Invalid MC channels per group value %d",
                          i_grpChnls );
                o_rc = FAIL;
        }
    }
    else
    {
        switch ( i_grpChnls )
        {
            case 1: // no shifting
            case 3:
            case 6:
                break;

            case 2: // insert 1 bit
                io_addr = (upper33 << 1) | ((i_grpId & 0x1) << 7) | lower7;
                break;

            case 4: // insert 2 bits
                io_addr = (upper33 << 2) | ((i_grpId & 0x3) << 7) | lower7;
                break;

            case 8: // insert 3 bits
                io_addr = (upper33 << 3) | ((i_grpId & 0x7) << 7) | lower7;
                break;

            default:
                PRDF_ERR( PRDF_FUNC "Invalid MC channels per group value %d",
                          i_grpChnls );
                o_rc = FAIL;
        }
    }

    return o_rc;

    #undef PRDF_FUNC

}

//------------------------------------------------------------------------------

// The hardware uses a mod3 hashing algorithm to calculate which memory channel
// an address belongs to. This is calulated with the following:
//      r0 = B3MF(RA[47:48])
//      r1 = rrotate(r0, RA[45:46])
//      r2 = rrotate(r1, RA[43:44])
//      r3 = rrotate(r2, m[0:1])
// RA is the real address, m[0:1] is the two most significant bits of the port
// address, and r3 is the mod3 hash. Since we are translating from the phyiscal
// address to the real address, we don't have m[0:1]. So the goal here is to
// calculate that. Fortunately, we have the 40-bit port address, which is where
// we can get RA[43:48] to calculate r2. We can also do a reverse lookup with
// the group ID and RA[55:56] to find r3. From there, we just need to solve for
// m[0:1] and add it to the beginning of the port address.

// Converts a 2-bit number into the binned (one-hot) 3-modulus format (B3MF).
//    mod(0) = 0b00 = 0b100
//    mod(1) = 0b01 = 0b010
//    mod(2) = 0b10 = 0b001
//    mod(3) = 0b00 = 0b100
uint8_t __b3mf( uint8_t i_val )
{
    return 4 >> (i_val % 3);
}

// Rotates i_b3mf right by i_num bits.
uint8_t __rrotate( uint8_t i_b3mf, uint8_t i_num )
{
    uint8_t o_b3mf = i_b3mf;
    for ( uint8_t n = 0; n < i_num; n++ )
    {
        o_b3mf = ((o_b3mf & 0x6) >> 1) | ((o_b3mf & 0x1) << 2);
    }
    return o_b3mf;
}

// Rotates i_b3mf left by i_num bits.
uint8_t __lrotate( uint8_t i_b3mf, uint8_t i_num )
{
    uint8_t o_b3mf = i_b3mf;
    for ( uint8_t n = 0; n < i_num; n++ )
    {
        o_b3mf = ((o_b3mf & 0x3) << 1) | ((o_b3mf & 0x4) >> 2);
    }
    return o_b3mf;
}

uint64_t __getMsb( uint64_t i_addr, uint64_t i_grpChnls, uint64_t i_grpId )
{
    uint64_t o_msb = 0;

    // Start by calculating r2 (see description above) and extracting RA[55:56].
    uint8_t r0       = __b3mf(        (i_addr >> 15) & 0x3 ); // RA[47:48]
    uint8_t r1       = __rrotate( r0, (i_addr >> 17) & 0x3 ); // RA[45:46]
    uint8_t r2       = __rrotate( r1, (i_addr >> 19) & 0x3 ); // RA[43:44]
    uint8_t ra_55_56 =                (i_addr >>  7) & 0x3;   // RA[55:56]

    // Special case for 6 MC/grp configs.
    if ( 6 == i_grpChnls )
    {
        // Note that the LSB of the group ID has already been inserted into
        // RA[56] (via __insertGrpId()). That bit should not be used to
        // calculate the mod 3 hash.
        i_grpId  = i_grpId  & 0x6; // Top two bits of the group ID.
        ra_55_56 = ra_55_56 & 0x2; // Only bit 55.
    }

    // Get the mod3 hash. There are some tables in sections 2.12.1 and 2.12.2 of
    // the Cumulus MC workbook. Fortunately, those tables can be boiled down to
    // some bit shifting.
    uint8_t r3 = __lrotate( __b3mf(i_grpId), ra_55_56 );

    // Given r2 and r3, calculate the MSBs for the port address by counting the
    // number of lrotates on r3 it takes to match r2.
    while ( r2 != r3 )
    {
        r3 = __lrotate( r3, 1 );
        o_msb++;
    }

    return o_msb;
}

//------------------------------------------------------------------------------

void __insertMsb( uint64_t & io_addr, uint64_t i_grpSize, uint64_t i_msb )
{
    // i_grpSize is a mask for the BAR. All we have to do is count the number
    // of bits in that value to determine how many extra bits we need to shift
    // in order to get the MSB in the correct position. Refer to the MC workbook
    // for details of the bit positions based on the group size.
    io_addr |= i_msb << ( 30 + __countBits(i_grpSize) );
}

//------------------------------------------------------------------------------

void __addBar( uint64_t & io_addr, uint64_t i_grpBar )
{
    // The BAR field is 24 bits and always starts at bit 8 of the real address.
    io_addr |= (i_grpBar << 32);
}

//------------------------------------------------------------------------------

template<TYPE T>
uint32_t getSystemAddr( ExtensibleChip * i_chip, MemAddr i_addr,
                        uint64_t & o_addr )
{
    #define PRDF_FUNC "[MemDealloc::getSystemAddr] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the group information.
        uint64_t grpChnls, grpId, grpSize, grpBar;
        o_rc = __getGrpInfo<T>(i_chip, grpChnls, grpId, grpSize, grpBar);
        if ( SUCCESS != o_rc ) break;

        // Get the 40-bit port address (right justified).
        o_rc = __getPortAddr<T>( i_chip, i_addr, o_addr );
        if ( SUCCESS != o_rc ) break;

        // Insert the group ID.
        o_rc = __insertGrpId<T>( i_chip, o_addr, grpChnls, grpId );
        if ( SUCCESS != o_rc ) break;

        // Notes on 3 and 6 channel per group configs:
        //      Now that the group ID has been inserted, if applicable, we need
        //      to add the two most significant (MSB) bits to the beginning of
        //      the port address. These bits are calculated with a special mod3
        //      hashing algorithm.
        if ( 3 == grpChnls || 6 == grpChnls )
        {
            uint64_t msb = __getMsb( o_addr, grpChnls, grpId );
            __insertMsb( o_addr, grpSize, msb );
        }

        // Add the BAR to the rest of the address.
        __addBar( o_addr, grpBar );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TYPE T>
uint32_t getSystemAddrRange( ExtensibleChip * i_chip,
                                MemAddr    i_saddr, MemAddr    i_eaddr,
                                uint64_t & o_saddr, uint64_t & o_eaddr )
{
    #define PRDF_FUNC "[MemDealloc::getSystemAddrRange] "

    uint32_t o_rc = SUCCESS;

    do
    {
        // Get the group information.
        uint64_t grpChnls, grpId, grpSize, grpBar;
        o_rc = __getGrpInfo<T>(i_chip, grpChnls, grpId, grpSize, grpBar);
        if ( SUCCESS != o_rc ) break;

        // Get the 40-bit port addresses (right justified).
        o_rc  = __getPortAddr<T>( i_chip, i_saddr, o_saddr );
        o_rc |= __getPortAddr<T>( i_chip, i_eaddr, o_eaddr );
        if ( SUCCESS != o_rc ) break;

        // Insert the group ID.
        o_rc  = __insertGrpId<T>( i_chip, o_saddr, grpChnls, grpId );
        o_rc |= __insertGrpId<T>( i_chip, o_eaddr, grpChnls, grpId );
        if ( SUCCESS != o_rc ) break;

        // Notes on 3 and 6 channel per group configs:
        //   It turns out that with 3 and 6 MC/group configs every address is
        //   interleaved, meaning that three consecutive physical addresses have
        //   three different MSBs. In addition, that hashing is not so simple.
        //   The given i_saddr and i_eaddr may be on MSB b10 and MSB b00,
        //   respectively. This really mucks things up when the start address is
        //   larger than the end address. To circumvent this issue, we have to
        //   bypass the actual MSBs and force o_saddr and o_eaddr to have
        //   MSB b00 and MSB b10, respectively.
        if ( 3 == grpChnls || 6 == grpChnls )
        {
            __insertMsb( o_saddr, grpSize, 0 );
            __insertMsb( o_eaddr, grpSize, 2 );
        }

        // Add the BAR to the rest of the address.
        __addBar( o_saddr, grpBar );
        __addBar( o_eaddr, grpBar );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
//------------------------------------------------------------------------------

template<TYPE T>
int32_t page( ExtensibleChip * i_chip, MemAddr i_addr )
{
    #define PRDF_FUNC "[MemDealloc::page] "

    uint64_t sysAddr = 0;
    int32_t o_rc = SUCCESS;
    do
    {
        if ( !isEnabled() ) break; // nothing to do

        o_rc = getSystemAddr<T>( i_chip, i_addr, sysAddr);
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                      i_chip->GetId() );
            break;
        }

        sendPageGardRequest( sysAddr );
        PRDF_TRAC( PRDF_FUNC "Page dealloc address: 0x%016llx", sysAddr );

    } while( 0 );

    return o_rc;
    #undef PRDF_FUNC
}
template int32_t page<TYPE_MCA>( ExtensibleChip * i_chip, MemAddr i_addr );
template int32_t page<TYPE_MBA>( ExtensibleChip * i_chip, MemAddr i_addr );
template int32_t page<TYPE_OCMB_CHIP>(ExtensibleChip * i_chip, MemAddr i_addr);

//------------------------------------------------------------------------------

template<TYPE T>
int32_t rank( ExtensibleChip * i_chip, MemRank i_rank )
{
    #define PRDF_FUNC "[MemDealloc::rank] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( !isEnabled() ) break; // nothing to do

        // Get the address range of i_rank.
        MemAddr startAddr, endAddr;
        o_rc = getMemAddrRange<T>( i_chip, i_rank, startAddr, endAddr,
                                   SLAVE_RANK );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,0x%02x) failed",
                      i_chip->getHuid(), i_rank.getKey() );
            break;
        }

        // Get the system addresses.
        uint64_t ssAddr = 0;
        uint64_t seAddr = 0;
        o_rc = getSystemAddrRange<T>( i_chip, startAddr, endAddr,
                                              ssAddr,    seAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSystemAddrRange(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }
        PRDF_TRAC( PRDF_FUNC "NOTE: Dynamic mem dealloc currently disabled" );
        /* TODO RTC 258446
        // Send the address range to the hypervisor.
        sendDynMemDeallocRequest( ssAddr, seAddr );
        */
        PRDF_TRAC( PRDF_FUNC "Rank dealloc for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llx", ssAddr, seAddr );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
template int32_t rank<TYPE_MCA>( ExtensibleChip * i_chip, MemRank i_rank );
template int32_t rank<TYPE_MBA>( ExtensibleChip * i_chip, MemRank i_rank );
template int32_t rank<TYPE_OCMB_CHIP>(ExtensibleChip * i_chip, MemRank i_rank);

//------------------------------------------------------------------------------

template<TYPE T>
int32_t port( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[MemDealloc::port] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( !isEnabled() ) break; // nothing to do

        // Get the address range of i_chip.
        MemAddr startAddr, endAddr;
        o_rc = getMemAddrRange<T>( i_chip, startAddr, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        // Get the system addresses.
        uint64_t ssAddr = 0;
        uint64_t seAddr = 0;
        o_rc = getSystemAddrRange<T>( i_chip, startAddr, endAddr,
                                              ssAddr,    seAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSystemAddrRange(0x%08x) failed",
                      i_chip->getHuid() );
            break;
        }

        PRDF_TRAC( PRDF_FUNC "NOTE: Dynamic mem dealloc currently disabled" );
        /* TODO RTC 258446
        // Send the address range to the hypervisor.
        sendDynMemDeallocRequest( ssAddr, seAddr );
        */
        PRDF_TRAC( PRDF_FUNC "Port dealloc for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llx", ssAddr, seAddr );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
template int32_t port<TYPE_MCA>( ExtensibleChip * i_chip );
template int32_t port<TYPE_MBA>( ExtensibleChip * i_chip );
template int32_t port<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip );

//------------------------------------------------------------------------------

template <TYPE T>
int32_t __getDimmRange( TargetHandle_t i_dimm,
                        uint64_t & o_ssAddr, uint64_t & o_seAddr )
{
    #define PRDF_FUNC "[MemDealloc::__getDimmRange] "

    int32_t o_rc = SUCCESS;

    o_ssAddr = o_seAddr = 0;

    do
    {
        // Get the MCA, MBA, etc. connected to this DIMM.
        TargetHandle_t trgt = getConnectedParent( i_dimm, T );
        ExtensibleChip * chip = (ExtensibleChip *)systemPtr->GetChip( trgt );
        if ( nullptr == chip )
        {
            PRDF_ERR( PRDF_FUNC "No chip connected to DIMM" );
            o_rc = FAIL; break;
        }

        // Get the DIMM select.
        uint8_t dimmSlct = getDimmSlct( i_dimm );

        // Get the address range of i_dimm.
        MemAddr startAddr, endAddr;
        o_rc = getMemAddrRange<T>( chip, startAddr, endAddr, dimmSlct );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange(0x%08x,%d) failed",
                      chip->getHuid(), dimmSlct );
            break;
        }

        // Get the system addresses.
        o_rc = getSystemAddrRange<T>( chip, startAddr, endAddr,
                                            o_ssAddr,  o_seAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSystemAddrRange(0x%08x) failed",
                      chip->getHuid() );
            break;
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TYPE T>
int32_t dimmSlct( TargetHandle_t i_dimm )
{
    #define PRDF_FUNC "[MemDealloc::dimmSlct] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( !isEnabled() ) break; // nothing to do

        // Get the system addresses.
        uint64_t ssAddr = 0, seAddr = 0;
        o_rc = __getDimmRange<T>( i_dimm, ssAddr, seAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "__getDimmRange(0x%08x) failed",
                      getHuid(i_dimm) );
            break;
        }

        PRDF_TRAC( PRDF_FUNC "NOTE: Dynamic mem dealloc currently disabled" );
        /* TODO RTC 258446
        // Send the address range to the hypervisor.
        sendDynMemDeallocRequest( ssAddr, seAddr );
        */
        PRDF_TRAC( PRDF_FUNC "DIMM Slct dealloc for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llx", ssAddr, seAddr );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TYPE T>
bool isDimmPair( TargetHandle_t i_dimm1, TargetHandle_t i_dimm2 )
{
    #define PRDF_FUNC "[MemDealloc::isDimmPair] "
    bool isDimmPair = false;
    do
    {
        uint8_t dimm1Slct = getDimmSlct( i_dimm1 );
        uint8_t dimm2Slct = getDimmSlct( i_dimm2 );

        isDimmPair = ( ( dimm1Slct == dimm2Slct ) &&
                       ( getConnectedParent( i_dimm1, T ) ==
                                 getConnectedParent( i_dimm2, T )));
    } while(0);
    return isDimmPair;
    #undef PRDF_FUNC
}

// This function is used for sorting dimms in a list.
template <TYPE T>
bool compareDimms( TargetHandle_t i_dimm1, TargetHandle_t i_dimm2 )
{
    #define PRDF_FUNC "[MemDealloc::compareDimms] "
    bool isSmall = false;
    do
    {
        uint8_t dimm1Slct = getDimmSlct( i_dimm1 );
        uint8_t dimm2Slct = getDimmSlct( i_dimm2 );

        TargetHandle_t tgt1 = getConnectedParent( i_dimm1, T );
        TargetHandle_t tgt2 = getConnectedParent( i_dimm2, T );

        isSmall = ( ( tgt1 < tgt2 ) ||
                    ( ( tgt1 == tgt2) && ( dimm1Slct < dimm2Slct )));

    } while(0);

    return isSmall;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template <TYPE T>
int32_t dimmList( TargetHandleList  & i_dimmList )
{
    #define PRDF_FUNC "[MemDealloc::dimmList] "

    int32_t o_rc = SUCCESS;

    // Find unique dimm slct.
    std::sort( i_dimmList.begin(), i_dimmList.end(), compareDimms<T> );
    TargetHandleList::iterator uniqueDimmEndIt =
                std::unique( i_dimmList.begin(), i_dimmList.end(),
                             isDimmPair<T> );

    for( TargetHandleList::iterator it = i_dimmList.begin();
         it != uniqueDimmEndIt; it++ )
    {
        // Get the system addresses.
        uint64_t ssAddr = 0, seAddr = 0;
        if ( SUCCESS != __getDimmRange<T>(*it, ssAddr, seAddr) )
        {
            PRDF_ERR( PRDF_FUNC "__getDimmRange(0x%08x) failed", getHuid(*it) );
            o_rc = FAIL; continue; // Continue to the next DIMM.
        }

        // Send the address range to the hypervisor.
        sendPredDeallocRequest( ssAddr, seAddr );
        PRDF_TRAC( PRDF_FUNC "Predictive dealloc for start addr: 0x%016llx "
                   "end addr: 0x%016llx", ssAddr, seAddr );

        #ifdef CONFIG_NVDIMM
        // If the DIMM is an NVDIMM, send a message to PHYP that a save/restore
        // may work.
        if ( isNVDIMM(*it) )
        {
            uint32_t l_rc = PlatServices::nvdimmNotifyProtChange( *it,
                    NVDIMM::NVDIMM_RISKY_HW_ERROR );
            if ( SUCCESS != l_rc )
            {
                PRDF_TRAC( PRDF_FUNC "nvdimmNotifyProtChange(0x%08x) "
                           "failed.", getHuid(*it) );
                continue;
            }
        }
        #endif
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t dimmList( TargetHandleList  & i_dimmList )
{
    #define PRDF_FUNC "[MemDealloc::dimmList] "

    int32_t o_rc = SUCCESS;

    do
    {
        if ( i_dimmList.empty() ) break;

        // Determine what target these DIMMs are connected to.
        // Note that we cannot use getConnectedParent() because it will assert
        // if there is no parent of that type.

        TargetHandle_t dimmTrgt = i_dimmList.front();
        TargetHandleList list;

        // First, check for MCAs.
        list = getConnected( dimmTrgt, TYPE_MCA );
        if ( !list.empty() )
        {
            o_rc = dimmList<TYPE_MCA>( i_dimmList );
            break;
        }

        // Second, check for MBAs.
        list = getConnected( dimmTrgt, TYPE_MBA );
        if ( !list.empty() )
        {
            o_rc = dimmList<TYPE_MBA>( i_dimmList );
            break;
        }

        // Third, check for OCMBs.
        list = getConnected( dimmTrgt, TYPE_OCMB_CHIP );
        if ( !list.empty() )
        {
            o_rc = dimmList<TYPE_OCMB_CHIP>( i_dimmList );
            break;
        }

        // If we get here we did not find a supported target.
        PRDF_ERR( PRDF_FUNC "Unsupported connected parent to dimm 0x%08x",
                  getHuid(dimmTrgt) );
        PRDF_ASSERT(false); // code bug

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

} //namespace MemDealloc
} // namespace PRDF

