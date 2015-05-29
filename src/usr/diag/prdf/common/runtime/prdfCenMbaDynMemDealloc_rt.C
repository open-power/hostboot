/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/runtime/prdfCenMbaDynMemDealloc_rt.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#include <prdfExtensibleChip.H>
#include <prdfCenMbaDynMemDealloc_rt.H>
#include <prdfTrace.H>
#include <prdfPlatServices.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfCenAddress.H>


//------------------------------------------------------------------------------
// Function Definitions
//------------------------------------------------------------------------------

using namespace TARGETING;

namespace PRDF
{
using namespace PlatServices;

namespace DEALLOC
{

enum
{
    DDR3 = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3,
    DDR4 = fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4,

    HASH_MODE_128B = 0,
    HASH_MODE_256B,
};

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
 *  @param  i_col       Column (C13,C11,C9-C3,C2-C0)
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

    // Get the column components. Note c2-c1 will be added later. Also c0 is
    // tied to 0 and not used at all.
    uint64_t upperCol = (i_col & 0x00ff0) >> 4;
    uint64_t c3       = (i_col & 0x00008) >> 3;

    uint64_t numUpperCol = i_numCol - 4;
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
 *  @param  i_col       Column (C13,C11,C9-C3,C2-C0)
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

    // Add c2-c1 to the end (bits 33:34).
    addr <<= 2; addr |= (i_col & 0x00006) >> 1;

    // Bits 35:39 are zero.
    addr <<= 5;

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

// The code in this function is based on section 5.4.1 and 5.6 of Centaur
// chip spec.
int32_t getCenPhyAddr( ExtensibleChip * i_mbaChip, ExtensibleChip * i_mbChip,
                       CenAddr i_addr, uint64_t & o_addr  )
{
    #define PRDF_FUNC "[DEALLOC::getCenPhyAddr] "

    int32_t o_rc = SUCCESS;

    o_addr = 0;

    TargetHandle_t mba    = i_mbaChip->GetChipHandle();
    uint64_t       mbaPos = getTargetPosition( mba );

    uint64_t ds   = i_addr.getRank().getDimmSlct(); // D
    uint64_t mrnk = i_addr.getRank().getRankSlct(); // M0-M2
    uint64_t srnk = i_addr.getRank().getSlave();    // S0-S2

    uint64_t row  = i_addr.getRow();    // R18-R0
    uint64_t col  = i_addr.getCol();    // C13,C11,C9-C3,C2-C0
    uint64_t bnk  = i_addr.getBank();   // DDR3: B2-B0, DDR4: BG1-BG0,B1-B0

    do
    {
        // Get the number of configured address bits for the master and slave
        // ranks.
        uint64_t num_mrnk = getMasterRanksPerDimm( mba, ds );
        if ( 0 == num_mrnk )
        {
            PRDF_ERR( PRDF_FUNC "getMasterRanksPerDimm() failed. HUID:0X%08X",
                      i_mbChip->GetId() );
            break;
        }

        uint64_t num_srnk = getRanksPerDimm( mba, ds ) / num_mrnk;
        if ( 0 == num_srnk )
        {
            PRDF_ERR( PRDF_FUNC "getRanksPerDimm() failed. HUID:0X%08X",
                      i_mbChip->GetId() );
            break;
        }

        uint64_t mrnkBits = ranks2bits( num_mrnk );
        uint64_t srnkBits = ranks2bits( num_srnk );

        // Get the number of configured address bits for the row and column.
        uint8_t rowBits, colBits;
        o_rc = getDimmRowCol( mba, rowBits, colBits );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getDimmConfig() failed. HUID:0x%08X",
                      i_mbaChip->GetId());
            break;
        }

        // Get the DDR verion of the DIMM (DDR3, DDR4, etc...)
        uint8_t ddrVer;
        o_rc = getDramGen( mba, ddrVer );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getDramGen() failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }

        // Get the Centaur interleave mode (MBSXCR[0:4]).
        SCAN_COMM_REGISTER_CLASS * mbsxcr = i_mbChip->getRegister("MBSXCR");
        o_rc = mbsxcr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MBSXCR. HUID:0x%08X",
                      i_mbChip->GetId() ) ;
            break;
        }

        uint64_t cenIlMode = mbsxcr->GetBitFieldJustified( 0, 5 );

        // Get the rank config (MBAXCR[8]), rank hash (MBAXCR[10:11]), and
        // MBA interleave mode (MBAXCR[12]).
        const char * reg_str = ( 0 == mbaPos ) ? "MBA0_MBAXCR" : "MBA1_MBAXCR";
        SCAN_COMM_REGISTER_CLASS * mbaxcr = i_mbChip->getRegister( reg_str );
        o_rc = mbaxcr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on %s. HUID:0X%08X",
                      reg_str, i_mbChip->GetId() );
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

// The code in this function is based on section 2.1.3 of MC workbook.

int32_t getSystemAddr( ExtensibleChip * i_mbaChip, CenAddr i_addr,
                       uint64_t & o_addr )
{
    #define PRDF_FUNC "[DEALLOC::getSystemAddr] "

    uint64_t cenAddr = 0;
    o_addr = 0;
    int32_t o_rc = SUCCESS;
    do
    {
        uint8_t dramGen = 0;
        TargetHandle_t mba = i_mbaChip->GetChipHandle();

        o_rc = getDramGen( mba, dramGen );
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getDramGen() failed. HUID:0x%08X",
                      i_mbaChip->GetId());
            break;
        }
        if( fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3 != dramGen )
        {
            PRDF_ERR( PRDF_FUNC "page Gard is only supported for DDR3."
                      "HUID:0x%08X  DRAM Generation : %u",
                      i_mbaChip->GetId(), dramGen );
            o_rc = FAIL; break;
        }

        CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );
        ExtensibleChip *mbChip = mbadb->getMembChip();
        if( NULL == mbChip )
        {
            PRDF_ERR( PRDF_FUNC " Null Membuf chip for mba. HUID:0x%08X",
                                 i_mbaChip->GetId() );
            o_rc = FAIL; break;
        }
        CenMembufDataBundle * mbdb = getMembufDataBundle( mbChip );
        ExtensibleChip * mcsChip = mbdb->getMcsChip();

        if( NULL == mbChip )
        {
            PRDF_ERR( PRDF_FUNC " Null Mcs chip for Membuf. HUID:0x%08X",
                      mbChip->GetId() );
            o_rc = FAIL; break;
        }

        o_rc = getCenPhyAddr( i_mbaChip, mbChip, i_addr, cenAddr);
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getCenPhyAddr() failed. MBA:0x%08X "
                      "Membuf:0x%08X", i_mbaChip->GetId(), mbChip->GetId());
            break;
        }

        SCAN_COMM_REGISTER_CLASS * mcgfp = mcsChip->getRegister( "MCFGP" );

        o_rc = mcgfp->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on MCFGP. HUID:0x%08X",
                      mcsChip->GetId() ) ;
            break;
        }

        // Get the MCS per group
        // 000 - 1, 001 - 2, 010 - 4, 100 - 8
        uint8_t mcsPerGrp =  mcgfp->GetBitFieldJustified( 1,3 );
        uint8_t grpShift = 0;

        // Get the number of  bits required to accomondate mcsPos
        while( 0 != ( mcsPerGrp >> grpShift ) ) {  grpShift++;    }

        // Get the MCS position within group. Though it is 5 bit field,
        // two bits are not used.
        uint64_t grpSlct    = mcgfp->GetBitFieldJustified( 4, 5 ) << 7;
        // Get the base address for MCS
        uint64_t baseAddr = mcgfp->GetBitFieldJustified( 26, 18 ) << 32;

        // Split the Centaur address to make room for the group select.
        uint64_t cenUpper33 = (cenAddr & 0xFFFFFFFF80ull) << grpShift;
        uint64_t cenLower7  =  cenAddr & 0x000000007full;


        // Put the whole address together
        o_addr = baseAddr | cenUpper33 | grpSlct | cenLower7;

    } while( 0 );

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t rankGard( ExtensibleChip * i_mbaChip, CenRank i_rank )
{
    #define PRDF_FUNC "[DEALLOC::rankGard] "

    int32_t o_rc = SUCCESS;
    do
    {
        CenAddr startAddr, endAddr;
        TargetHandle_t mba = i_mbaChip->GetChipHandle();
        o_rc = getMemAddrRange( mba, i_rank, startAddr, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange() Failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }

        // Get the system addresses
        uint64_t ssAddr = 0;
        uint64_t seAddr = 0;
        o_rc = getSystemAddr( i_mbaChip, startAddr, ssAddr);
        o_rc |= getSystemAddr( i_mbaChip, endAddr, seAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }
        // Send the address range to HV
        sendDynMemDeallocRequest( ssAddr, seAddr );
        PRDF_TRAC( PRDF_FUNC "Rank gard for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llX", ssAddr, seAddr );

    } while( 0 );

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool isEnabled()
{
    return ( isHyprRunning() && (isHyprConfigPhyp() || isHyprConfigOpal()) &&
             !isMfgAvpEnabled() && !isMfgHdatAvpEnabled() );
}

//------------------------------------------------------------------------------

int32_t pageGard( ExtensibleChip * i_mbaChip, CenAddr i_addr )
{
    #define PRDF_FUNC "[DEALLOC::pageGard] "

    uint64_t sysAddr = 0;
    int32_t o_rc = SUCCESS;
    do
    {
        if ( !isEnabled() ) break; // nothing to do

        o_rc = getSystemAddr( i_mbaChip, i_addr, sysAddr);
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }

        sendPageGardRequest( sysAddr );
        PRDF_TRAC( PRDF_FUNC "Page gard for address: 0x%016llX", sysAddr );

    } while( 0 );

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t lmbGard( ExtensibleChip * i_mbaChip, CenAddr i_addr, bool i_isFetch )
{
    #define PRDF_FUNC "[DEALLOC::lmbGard] "

    uint64_t sysAddr = 0;
    int32_t o_rc = SUCCESS;
    do
    {
        if ( !isEnabled() ) break; // nothing to do

        if( isHyprConfigOpal() )
        {
            o_rc = rankGard( i_mbaChip, i_addr.getRank() );
            if( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "rankGard() failed. HUID:0x%08X",
                          i_mbaChip->GetId() );
                break;
            }
        }
        else
        {
            o_rc = getSystemAddr( i_mbaChip, i_addr, sysAddr);
            if( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                          i_mbaChip->GetId() );
                break;
            }

            sendLmbGardRequest( sysAddr, i_isFetch );
            PRDF_TRAC( PRDF_FUNC "LMB gard for address: 0x%016llX", sysAddr );
        }

    } while( 0 );

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t mbaGard( ExtensibleChip * i_mbaChip )
{
    #define PRDF_FUNC "[DEALLOC::mbaGard] "
    int32_t o_rc = SUCCESS;

    do
    {
        if ( !isEnabled() ) break; // nothing to do

        CenAddr startAddr, endAddr;
        TargetHandle_t mba = i_mbaChip->GetChipHandle();
        o_rc = getMemAddrRange( mba, startAddr, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange() Failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }

        // Get the system addresses
        uint64_t ssAddr = 0;
        uint64_t seAddr = 0;
        o_rc = getSystemAddr( i_mbaChip, startAddr, ssAddr);
        o_rc |= getSystemAddr( i_mbaChip, endAddr, seAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }

        // Send the address range to PHYP
        sendDynMemDeallocRequest( ssAddr, seAddr );
        PRDF_TRAC( PRDF_FUNC "MBA gard for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llX", ssAddr, seAddr );

    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t dimmSlctGard( TargetHandle_t  i_dimm )
{
    #define PRDF_FUNC "[DEALLOC::dimmSlctGard] "
    int32_t o_rc = SUCCESS;

    do
    {
        if ( !isEnabled() ) break; // nothing to do

        TargetHandle_t mba =  getConnectedParent( i_dimm, TYPE_MBA );

        ExtensibleChip * mbaChip = (ExtensibleChip *)systemPtr->GetChip( mba );
        if ( NULL == mbaChip )
        {
            PRDF_ERR( PRDF_FUNC "No MBA chip behind DIMM" );
            o_rc = FAIL; break;
        }
        // Find the largest address range
        uint64_t smallestAddr = 0xffffffffffffffffll;
        uint64_t largestAddr  = 0;
        CenAddr startAddr, endAddr;
        std::vector<CenRank> masterRanks;
        uint8_t dimmSlct = 0;

        o_rc = getMbaDimm( i_dimm, dimmSlct );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMbaDimm() failed" );
            break;
        }

        o_rc = getMasterRanks( mba, masterRanks, dimmSlct );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMasterRanks() failed" );
            break;
        }

        // Iterate all ranks to get start and end address.
        for ( std::vector<CenRank>::iterator it = masterRanks.begin();
              it != masterRanks.end(); it++ )
        {
            o_rc = getMemAddrRange( mba, *it, startAddr, endAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemAddrRange() Failed. HUID:0x%08X",
                          mbaChip->GetId() );
                break;
            }

            // Get the system addresses
            uint64_t ssAddr = 0;
            uint64_t seAddr = 0;
            o_rc = getSystemAddr( mbaChip, startAddr, ssAddr);
            o_rc |= getSystemAddr( mbaChip, endAddr, seAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                          mbaChip->GetId() );
                break;
            }
            if ( ssAddr < smallestAddr ) smallestAddr = ssAddr;
            if ( seAddr > largestAddr  ) largestAddr  = seAddr;
        }
        if( SUCCESS != o_rc ) break;

        // Send the address range to PHYP
        sendDynMemDeallocRequest( smallestAddr, largestAddr );
        PRDF_TRAC( PRDF_FUNC "DIMM Slct gard for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llX", smallestAddr, largestAddr );

    } while (0);

    if( FAIL == o_rc )
    {
        PRDF_ERR( PRDF_FUNC "failed. DIMM:0x%08X", getHuid( i_dimm ) );
    }

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

bool isDimmPair( TargetHandle_t i_dimm1, TargetHandle_t i_dimm2 )
{
    #define PRDF_FUNC "[DEALLOC::isDimmPair] "
    bool isDimmPair = false;
    do
    {
        uint8_t dimm1Slct = 0;
        uint8_t dimm2Slct = 0;

        int32_t rc = getMbaDimm( i_dimm1, dimm1Slct );
        rc        |= getMbaDimm( i_dimm2, dimm2Slct );

        if( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC " getMbaDimm() failed" );
            break;
        }
        isDimmPair = ( ( dimm1Slct == dimm2Slct ) &&
                       ( getConnectedParent( i_dimm1, TYPE_MBA ) ==
                                 getConnectedParent( i_dimm2, TYPE_MBA )));
    } while(0);
    return isDimmPair;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

// This function is used for sorting dimms in a list.
bool compareDimms( TargetHandle_t i_dimm1, TargetHandle_t i_dimm2 )
{
    #define PRDF_FUNC "[DEALLOC::compareDimms] "
    bool isSmall = false;
    do
    {
        uint8_t dimm1Slct = 0;
        uint8_t dimm2Slct = 0;

        int32_t rc = getMbaDimm( i_dimm1, dimm1Slct );
        rc        |= getMbaDimm( i_dimm2, dimm2Slct );

        if( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC " getMbaDimm() failed" );
            break;
        }
        TargetHandle_t mba1 = getConnectedParent( i_dimm1, TYPE_MBA );
        TargetHandle_t mba2 = getConnectedParent( i_dimm2, TYPE_MBA );

        isSmall = ( ( mba1 < mba2 ) ||
                    ( ( mba1 == mba2) && ( dimm1Slct < dimm2Slct )));

    } while(0);

    return isSmall;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t dimmListGard( TargetHandleList  & i_dimmList )
{
    #define PRDF_FUNC "[DEALLOC::dimmListGard] "
    int32_t o_rc = SUCCESS;

    // Find unique dimm slct.
    std::sort( i_dimmList.begin(), i_dimmList.end(), compareDimms );
    TargetHandleList::iterator uniqueDimmEndIt =
                std::unique( i_dimmList.begin(), i_dimmList.end(), isDimmPair );

    for( TargetHandleList::iterator it = i_dimmList.begin();
         it != uniqueDimmEndIt; it++ )
    {
        int32_t l_rc = dimmSlctGard( *it );
        if( SUCCESS != l_rc )
        {
            PRDF_ERR(PRDF_FUNC "Failed for DIMM 0x:%08X", getHuid( *it ) );
            o_rc |= l_rc;
        }
    }
    return o_rc;
    #undef PRDF_FUNC
}
} //namespace DEALLOC
} // namespace PRDF
