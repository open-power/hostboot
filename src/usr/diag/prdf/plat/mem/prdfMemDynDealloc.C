/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemDynDealloc.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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

//------------------------------------------------------------------------------
// Function Definitions
//------------------------------------------------------------------------------

using namespace TARGETING;

namespace PRDF
{
using namespace PlatServices;

namespace MemDealloc
{

bool isEnabled()
{
    return ( isHyprRunning() && (isHyprConfigPhyp() || isHyprConfigOpal()) &&
             !isMfgAvpEnabled() && !isMfgHdatAvpEnabled() );
}

int32_t __getAddrConfig( ExtensibleChip * i_mcaChip, uint8_t i_dslct,
                         bool & o_twoDimmConfig, uint8_t & o_mrnkBits,
                         uint8_t & o_srnkBits, uint8_t & o_extraRowBits )
{
    #define PRDF_FUNC "[MemDealloc::__getAddrConfig] "

    int32_t o_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * reg = i_mcaChip->getRegister( "MC_ADDR_TRANS" );
    o_rc = reg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC "Read failed on MC_ADDR_TRANS: i_mcaChip=0x%08x",
                  i_mcaChip->getHuid() );
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
        PRDF_ERR( PRDF_FUNC "B2 enabled in MC_ADDR_TRANS: i_mcaChip=0x%08x "
                  "i_dslct=%d", i_mcaChip->getHuid(), i_dslct );
        return FAIL;
    }

    o_extraRowBits = 0;
    if ( reg->IsBitSet(i_dslct ? 29:13) ) o_extraRowBits++;
    if ( reg->IsBitSet(i_dslct ? 30:14) ) o_extraRowBits++;
    if ( reg->IsBitSet(i_dslct ? 31:15) ) o_extraRowBits++;

    return o_rc;

    #undef PRDF_FUNC
}

uint64_t __reverseBits( uint64_t i_val, uint64_t i_numBits )
{
    uint64_t o_val = 0;

    for ( uint64_t i = 0; i < i_numBits; i++ )
    {
        o_val <<= 1;
        o_val |= i_val & 0x1;
        i_val >>= 1;
    }

    return o_val;
}

uint64_t __maskBits( uint64_t i_val, uint64_t i_numBits )
{
    uint64_t mask = (0xffffffffffffffffull >> i_numBits) << i_numBits;
    return i_val & ~mask;
}

int32_t __getMcaPortAddr( ExtensibleChip * i_chip, MemAddr i_addr,
                          uint64_t & o_addr )
{
    int32_t o_rc = SUCCESS;

    o_addr = 0;

    // Local vars for address fields
    uint64_t col   = __reverseBits(i_addr.getCol(),  7); // C9 C8 C7 C6 C5 C4 C3
    uint64_t row   = __reverseBits(i_addr.getRow(), 18); // R17 R16 R15 .. R1 R0
    uint64_t bnk   = i_addr.getBank();                   //     BG0 BG1 B0 B1 B2
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
            rnk_pt3 = dslct; rnkBits_pt3 = 1;
    }
    else // At least one master or slave.
    {
        // Put the LSB of the combined rank in part 3 and the rest in part 2.
        rnk_pt3 = rnk & 0x1; rnkBits_pt3 = 1;
        rnk_pt2 = rnk >> 1;  rnkBits_pt2 = rnkBits - 1;

        if ( twoDimmConfig ) // The DIMM select goes into part 1.
            rnk_pt1 = dslct; rnkBits_pt1 = 1;
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
    uint64_t bg0_bg1 = (bnk & 0x18) >> 3;
    uint64_t b0      = (bnk & 0x04) >> 2;
    uint64_t b1      = (bnk & 0x02) >> 1;
    // NOTE: B2 is not supported on Nimbus.

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

    #undef PRDF_FUNC
}

template<TYPE T>
int32_t getSystemAddr( ExtensibleChip * i_chip, MemAddr i_addr,
                       uint64_t & o_addr );
template<>
int32_t getSystemAddr<TYPE_MBA>( ExtensibleChip * i_chip, MemAddr i_addr,
                                 uint64_t & o_addr )
{
    // TODO - RTC: 157588
    return SUCCESS;
}

template<>
int32_t getSystemAddr<TYPE_MCA>( ExtensibleChip * i_chip, MemAddr i_addr,
                                 uint64_t & o_addr )
{
    #define PRDF_FUNC "[MemDealloc::getSystemAddr] "

    int32_t l_rc = SUCCESS;

    do {
        // Get the 40-bit port address (right justified).
        l_rc = __getMcaPortAddr( i_chip, i_addr, o_addr );
        if (l_rc) break;

        // Construct the 56-bit Powerbus address

        // Get MCA target position
        ExtensibleChip * mcs_chip = getConnectedParent( i_chip, TYPE_MCS );
        uint8_t mcaPos = i_chip->getPos() % MAX_MCA_PER_MCS;

        SCAN_COMM_REGISTER_CLASS * mcfgp =  mcs_chip->getRegister("MCFGP");
        SCAN_COMM_REGISTER_CLASS * mcfgpm = mcs_chip->getRegister("MCFGPM");
        l_rc = mcfgp->Read(); if (l_rc) break;
        l_rc = mcfgpm->Read(); if (l_rc) break;

        // Get the MCS per group
        uint8_t mcsPerGrp = mcfgp->GetBitFieldJustified( 1,4 );
        // mcs position / group member id from mcfgp[5:7 or 8:10]
        uint8_t mcGrpSel = mcfgp->GetBitFieldJustified( (mcaPos==0) ? 5 : 8, 3);
        uint64_t upper33 = o_addr & 0xFFFFFFFF80ull;
        uint64_t lower7  = o_addr & 0x000000007full;
        uint64_t bar = 0;

        if (mcaPos == 0) // Channel 0
        {
            switch (mcsPerGrp)
            {
                case 0:
                case 1:
                    // 1 MCS per group -- no shift needed
                    break;
                case 4:
                case 5:
                    // 2 MCS per group
                    // shift physical addr by 1 and set bit 56 to group sel
                    o_addr = (upper33 << 1) | ((mcGrpSel & 0x1) << 7) | lower7;
                    break;
                case 6:
                    // 4 MCS per group
                    // shift physical addr by 2 and set bit 55:56 to group sel
                    o_addr = (upper33 << 2) | ((mcGrpSel & 0x3) << 7) | lower7;
                    break;
                case 8:
                    // 8 MCS per group
                    // shift physical addr by 3 and set bit 54:56 to group sel
                    o_addr = (upper33 << 3) | ((mcGrpSel & 0x7) << 7) | lower7;
                    break;
                case 2:
                case 3:
                    // 3 MCS per group
                    // May not be a supported config
                case 7:
                    // 6 MCS per group
                    // May not be a supported config
                default:
                    // Unsupported MCS per group config
                    PRDF_ERR( PRDF_FUNC
                              "Invalid MCS per group value: %x on HUID:0x%08X",
                              mcsPerGrp, i_chip->GetId() );
                    return FAIL;
                    break;
            }

            // Get BAR from MCFGP
            bar = mcfgp->GetBitFieldJustified(24, 24);
            o_addr |= (bar << 32);
        }
        else // Channel 1
        {
            switch (mcsPerGrp)
            {
                case 0:
                case 2:
                    // 1 MCS per group -- no shift needed

                    // Get BAR from MCFGPM
                    bar = mcfgpm->GetBitFieldJustified(24, 24);
                    break;
                case 4:
                    // 2 MCS per group
                    // shift physical addr by 1 and set bit 56 to group sel
                    o_addr = (upper33 << 1) | ((mcGrpSel & 0x1) << 7) | lower7;

                    // Get BAR from MCFGPM
                    bar = mcfgpm->GetBitFieldJustified(24, 24);
                    break;
                case 5:
                    // 2 MCS per group
                    // shift physical addr by 1 and set bit 56 to group sel
                    o_addr = (upper33 << 1) | ((mcGrpSel & 0x1) << 7) | lower7;

                    // Get BAR from MCFGPM
                    bar = mcfgp->GetBitFieldJustified(24, 24);
                    break;
                case 6:
                    // 4 MCS per group
                    // shift physical addr by 2 and set bit 55:56 to group sel
                    o_addr = (upper33 << 2) | ((mcGrpSel & 0x3) << 7) | lower7;

                    // Get BAR from MCFGP
                    bar = mcfgp->GetBitFieldJustified(24, 24);
                    break;
                case 8:
                    // 8 MCS per group
                    // shift physical addr by 3 and set bit 54:56 to group sel
                    o_addr = (upper33 << 3) | ((mcGrpSel & 0x7) << 7) | lower7;

                    // Get BAR from MCFGP
                    bar = mcfgp->GetBitFieldJustified(24, 24);
                    break;
                case 1:
                case 3:
                    // 3 MCS per group
                    // May not be a supported config

                    // Get BAR from MCFGPM
                case 7:
                    // 6 MCS per group
                    // May not be a supported config

                    // Get BAR from MCFGP
                default:
                    // Unsupported MCS per group config
                    PRDF_ERR( PRDF_FUNC
                              "Invalid MCS per group value: %x on HUID:0x%08X",
                              mcsPerGrp, i_chip->GetId() );
                    return FAIL;
                    break;
            }

            // Insert BAR
            o_addr |= (bar << 32);

        } // Channel 1

    } while (0);

    return l_rc;
    #undef PRDF_FUNC
}


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

template<TYPE T>
int32_t rank( ExtensibleChip * i_chip, MemRank i_rank )
{
    #define PRDF_FUNC "[MemDealloc::rank] "

    int32_t o_rc = SUCCESS;
    do
    {
        MemAddr startAddr, endAddr;
        TargetHandle_t tgt = i_chip->GetChipHandle();
        o_rc = getMemAddrRange( tgt, i_rank.getRankSlct(), i_rank.getDimmSlct(),
                                 startAddr, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getMemAddrRange() Failed. HUID:0x%08X",
                      i_chip->GetId() );
            break;
        }

        // Get the system addresses
        uint64_t ssAddr = 0;
        uint64_t seAddr = 0;
        o_rc  = getSystemAddr<T>( i_chip, startAddr, ssAddr);
        o_rc |= getSystemAddr<T>( i_chip, endAddr, seAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                      i_chip->GetId() );
            break;
        }
        // Send the address range to HV
        sendDynMemDeallocRequest( ssAddr, seAddr );
        PRDF_TRAC( PRDF_FUNC "Rank dealloc for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llx", ssAddr, seAddr );

    } while( 0 );

    return o_rc;
    #undef PRDF_FUNC
}
template int32_t rank<TYPE_MCA>( ExtensibleChip * i_chip, MemRank i_rank );

template<TYPE T>
int32_t port( ExtensibleChip * i_chip )
{
    #define PRDF_FUNC "[MemDealloc::port] "
    int32_t o_rc = SUCCESS;

    do
    {
        if ( !isEnabled() ) break; // nothing to do

        TargetHandle_t tgt = i_chip->GetChipHandle();

        // Find the largest address range
        uint64_t smallestAddr = 0xffffffffffffffffll;
        uint64_t largestAddr  = 0;
        uint64_t ssAddr = 0;
        uint64_t seAddr = 0;
        MemAddr startAddr, endAddr;
        std::vector<MemRank> masterRanks;

        // Get Master ranks
        getMasterRanks<T>( tgt, masterRanks);

        // Iterate all ranks to get start and end address.
        for ( std::vector<MemRank>::iterator it = masterRanks.begin();
              it != masterRanks.end(); it++ )
        {
            o_rc = getMemAddrRange( tgt, it->getRankSlct(),
                                    it->getDimmSlct(),
                                    startAddr, endAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemAddrRange() Failed. HUID:0x%08X",
                          i_chip->GetId() );
                break;
            }

            // Get the system addresses
            o_rc = getSystemAddr<T>( i_chip, startAddr, ssAddr);
            o_rc |= getSystemAddr<T>( i_chip, endAddr, seAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                          i_chip->GetId() );
                break;
            }
            if ( ssAddr < smallestAddr ) smallestAddr = ssAddr;
            if ( seAddr > largestAddr  ) largestAddr  = seAddr;
        }
        if( SUCCESS != o_rc ) break;

        // Send the address range to PHYP
        sendDynMemDeallocRequest( ssAddr, seAddr );
        PRDF_TRAC( PRDF_FUNC "Port dealloc for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llx", ssAddr, seAddr );

    } while (0);

    return o_rc;
    #undef PRDF_FUNC
}
template int32_t port<TYPE_MCA>( ExtensibleChip * i_chip );

template <TYPE T>
int32_t dimmSlct( TargetHandle_t  i_dimm )
{
    #define PRDF_FUNC "[MemDealloc::dimmSlct] "
    int32_t o_rc = SUCCESS;

    do
    {
        if ( !isEnabled() ) break; // nothing to do

        TargetHandle_t tgt = getConnectedParent( i_dimm, T );

        if ( tgt == NULL )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get parent for dimm 0x%08X",
                      getHuid( i_dimm ) );
            o_rc = FAIL; break;
        }

        ExtensibleChip * chip = (ExtensibleChip *)systemPtr->GetChip( tgt );
        if ( NULL == chip )
        {
            PRDF_ERR( PRDF_FUNC "No MBA/MCA chip behind DIMM" );
            o_rc = FAIL; break;
        }
        // Find the largest address range
        uint64_t smallestAddr = 0xffffffffffffffffll;
        uint64_t largestAddr  = 0;
        MemAddr startAddr, endAddr;
        std::vector<MemRank> masterRanks;
        uint8_t dimmSlct = getDimmSlct<T>( i_dimm );

        getMasterRanks<T>( tgt, masterRanks, dimmSlct );

        // Iterate all ranks to get start and end address.
        for ( std::vector<MemRank>::iterator it = masterRanks.begin();
              it != masterRanks.end(); it++ )
        {
            o_rc = getMemAddrRange( tgt, it->getRankSlct(), dimmSlct,
                                    startAddr, endAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getMemAddrRange() Failed. HUID:0x%08X",
                          chip->GetId() );
                break;
            }

            // Get the system addresses
            uint64_t ssAddr = 0;
            uint64_t seAddr = 0;
            o_rc = getSystemAddr<T>( chip, startAddr, ssAddr);
            o_rc |= getSystemAddr<T>( chip, endAddr, seAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "getSystemAddr() failed. HUID:0x%08X",
                          chip->GetId() );
                break;
            }
            if ( ssAddr < smallestAddr ) smallestAddr = ssAddr;
            if ( seAddr > largestAddr  ) largestAddr  = seAddr;
        }
        if( SUCCESS != o_rc ) break;

        // Send the address range to PHYP
        sendDynMemDeallocRequest( smallestAddr, largestAddr );
        PRDF_TRAC( PRDF_FUNC "DIMM Slct dealloc for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llx", smallestAddr, largestAddr );

    } while (0);

    if( FAIL == o_rc )
    {
        PRDF_ERR( PRDF_FUNC "failed. DIMM:0x%08X", getHuid( i_dimm ) );
    }

    return o_rc;
    #undef PRDF_FUNC
}

template <TYPE T>
bool isDimmPair( TargetHandle_t i_dimm1, TargetHandle_t i_dimm2 )
{
    #define PRDF_FUNC "[MemDealloc::isDimmPair] "
    bool isDimmPair = false;
    do
    {
        uint8_t dimm1Slct = getDimmSlct<T>( i_dimm1 );
        uint8_t dimm2Slct = getDimmSlct<T>( i_dimm2 );

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
        uint8_t dimm1Slct = getDimmSlct<T>( i_dimm1 );
        uint8_t dimm2Slct = getDimmSlct<T>( i_dimm2 );

        TargetHandle_t tgt1 = getConnectedParent( i_dimm1, T );
        TargetHandle_t tgt2 = getConnectedParent( i_dimm2, T );

        isSmall = ( ( tgt1 < tgt2 ) ||
                    ( ( tgt1 == tgt2) && ( dimm1Slct < dimm2Slct )));

    } while(0);

    return isSmall;
    #undef PRDF_FUNC
}


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
        int32_t l_rc = dimmSlct<T>( *it );
        if( SUCCESS != l_rc )
        {
            PRDF_ERR(PRDF_FUNC "Failed for DIMM 0x:%08X", getHuid( *it ) );
            o_rc |= l_rc;
        }
    }
    return o_rc;
    #undef PRDF_FUNC
}

int32_t dimmList( TargetHandleList  & i_dimmList )
{
    if (i_dimmList.size() == 0)
        return SUCCESS;

    // Determine MBA/MCA
    TYPE T = TYPE_MCA;
    TargetHandle_t dimmTgt = i_dimmList[0];
    TargetHandle_t tgt = getConnectedParent( dimmTgt, T );
    if ( NULL == tgt)
    {
        T = TYPE_MBA;
        tgt = getConnectedParent( dimmTgt, T );
    }

    if (tgt == NULL)
    {
        PRDF_ERR( "[MemDealloc::dimmList] get parent tgt failed for 0x%08X",
                  getHuid(dimmTgt));
        return FAIL;
    }

    if ( T == TYPE_MCA )
       return dimmList<TYPE_MCA>( i_dimmList );
    else if ( T == TYPE_MBA )
       return dimmList<TYPE_MBA>( i_dimmList );
    else
       return FAIL;
}

} //namespace MemDealloc
} // namespace PRDF

