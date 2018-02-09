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

int32_t getRowsAndIntrlv( ExtensibleChip * i_chip, uint8_t i_dslct,
                           uint8_t &o_rows, bool &o_interleaved)
{
    int32_t o_rc = SUCCESS;
    o_rows = 0;
    o_interleaved = false;

    uint32_t mcaPos = i_chip->getPos() % MAX_MCA_PER_MCS;

    ExtensibleChip * mcs_chip = getConnectedParent( i_chip, TYPE_MCS );

    SCAN_COMM_REGISTER_CLASS * addrTransReg = mcs_chip->getRegister(
        (mcaPos == 0) ? "MC_ADDR_TRANS_0" : "MC_ADDR_TRANS_1");

    o_rc = addrTransReg->Read();
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR("getRows Read failed on addrTransReg: chip=0x%08x",
                 i_chip->getHuid() );
        return o_rc;
    }

    if (addrTransReg->IsBitSet(i_dslct ? 31:15))
        o_rows = 18;
    else if (addrTransReg->IsBitSet(i_dslct ? 30:14))
        o_rows = 17;
    else if (addrTransReg->IsBitSet(i_dslct ? 29:13))
        o_rows = 16;
    else
        o_rows = 15;

    if ( addrTransReg->IsBitSet(0) && addrTransReg->IsBitSet(16))
        o_interleaved = true;

    return o_rc;
}

void setRemainingRowBitsAndDimmSelect(uint8_t  i_bit, //bit position in o_addr
                                      uint64_t i_row, //row value from MemAddr
                                      uint8_t  i_numRows, //# of row bits
                                      uint64_t i_dsclt, // dimm select
                                      uint64_t &o_addr) // system address
{
    // Write bits R15..R17 followed by dimm select bit
    uint8_t rowBit = 15;
    while ( i_bit >= 0 && rowBit <= i_numRows )
    {
        if (i_numRows == rowBit)
        {
            // We've finished writing row bits, now write the dimm select
            // and we're done
            o_addr |= (i_dsclt << (63-i_bit));
            break;;
        }
        else
        {
            // Set i_bit to rowBit
            o_addr |= (((i_row >> (17-rowBit)) & 0x1) << (63-i_bit));
            ++rowBit;
            --i_bit;
        }
    }
    return;
}

int32_t getMcaPortAddr( ExtensibleChip * i_chip, MemAddr i_addr,
                        uint64_t & o_addr )
{
    #define PRDF_FUNC "[MemDealloc::getMcaPortAddr] "

    int32_t o_rc = SUCCESS;
    o_addr = 0;
    TargetHandle_t tgt = i_chip->GetChipHandle();
    MemRank rnk = i_addr.getRank();

    // Local vars for address fields
    uint64_t col   = i_addr.getCol();   // C3 C4 C5 C6 C7 C8 C9
    uint64_t row   = i_addr.getRow();   //  R0 R1 R2 .. R16 R17
    uint64_t bnk   = i_addr.getBank();  //     BG0 BG1 B0 B1 B2
    uint64_t srnk  = rnk.getSlave();    //             S0 S1 S2
    uint64_t mrnk  = rnk.getRankSlct(); //                M0 M1
    uint64_t dslct = rnk.getDimmSlct(); //                1 bit

    // number of masters and slaves per dimm
    uint8_t mstrs = getNumMasterRanksPerDimm<TYPE_MCA>(tgt, dslct);
    uint8_t slvs  = getNumRanksPerDimm<TYPE_MCA>(tgt, dslct) / mstrs;

    uint8_t rowBits = 0;   // Number of row bits used for an addr on this dimm
    bool interleaved = false; // Whether dimm slot interleaving is used
    o_rc = getRowsAndIntrlv( i_chip, dslct, rowBits, interleaved);
    if (o_rc != SUCCESS)
        return o_rc;

    // If we're not using 2 dimm slots, the DS bit should always be set to 0
    if (!interleaved)
        dslct = 0;

    // Set Bits 33-0
    do {
        // Bits 33-30 are common to all configs
        // Set bit 33 to C3
        o_addr |= ((col & 0x40) << 24);
        // Set bits 31 32 to BG0 BG1
        o_addr |= ((bnk & 0x18) << 28);
        // Set bit 30 to B1
        o_addr |= ((bnk & 0x02) << 32);

        // Bit 29
        if ( slvs != 0 )
        {
            // Set bit 29 to S2
            o_addr |= ((srnk & 0x01) << 34);
        }
        else if (mstrs > 1)
        {
            // Set bit 29 to M1
            o_addr |= ((mrnk & 0x01) << 34);
        }
        else if (interleaved)
        {
            // Set bit 29 to D
            o_addr |= (dslct << 34);
        }
        else
        {
            // Set bit 29 to B0
            o_addr |= ((bnk & 0x04) << 32);
        }

        //Bits 28-23
        if ( mstrs == 1 && slvs == 0 && !interleaved )
        {
            // Set Bit 28 to C4
            o_addr |= ((col & 0x20) << 30);
            // Set bits 23-27 to C9-C5
            o_addr |= ((col & 0x10) << 32);
            o_addr |= ((col & 0x08) << 34);
            o_addr |= ((col & 0x04) << 36);
            o_addr |= ((col & 0x02) << 38);
            o_addr |= ((col & 0x01) << 40);
        }
        else
        {
            // Set Bit 28 to B0
            o_addr |= ((bnk & 0x04) << 33);
            // Set bits 23-27 to C8-C4
            o_addr |= ((col & 0x20) << 31);
            o_addr |= ((col & 0x10) << 33);
            o_addr |= ((col & 0x08) << 35);
            o_addr |= ((col & 0x04) << 37);
            o_addr |= ((col & 0x02) << 39);
        }

        // Bits 22-8
        o_addr |= ((row & 0x00010) << 37); // R13 -> bit 22
        o_addr |= ((row & 0x20000) << 25); // R0  -> bit 21
        o_addr |= ((row & 0x10000) << 27); // R1  -> bit 20
        o_addr |= ((row & 0x08000) << 29); // R2  -> bit 19
        o_addr |= ((row & 0x04000) << 31); // R3  -> bit 18
        o_addr |= ((row & 0x02000) << 33); // R4  -> bit 17
        o_addr |= ((row & 0x01000) << 35); // R5  -> bit 16
        o_addr |= ((row & 0x00800) << 37); // R6  -> bit 15
        o_addr |= ((row & 0x00400) << 39); // R7  -> bit 14
        o_addr |= ((row & 0x00200) << 41); // R8  -> bit 13
        o_addr |= ((row & 0x00100) << 43); // R9  -> bit 12
        o_addr |= ((row & 0x00080) << 45); // R10 -> bit 11
        o_addr |= ((row & 0x00040) << 47); // R11 -> bit 10
        o_addr |= ((row & 0x00020) << 49); // R12 -> bit  9
        o_addr |= ((row & 0x00008) << 52); // R14 -> bit  8

        // Bit 7
        if ( mstrs == 1 && slvs == 0 && !interleaved )
        {
            // Set remaining row bits starting at bit 7
            setRemainingRowBitsAndDimmSelect(7, row, rowBits, dslct, o_addr);
            break;
        }
        else
        {
            // Set bit 7 to C9
            o_addr |= ((col & 0x01) << 56);
        }

        // Bit 6...
        if (slvs >= 4)
        {
            // set bit 6 to S1
            o_addr |= ((srnk & 0x02) << 56);
        }
        else if (mstrs == 4 && slvs==0)
        {
            // set Bit 6 to M0
            o_addr |= ((mrnk & 0x02) << 56);
        }
        else if (mstrs == 2 && slvs == 2)
        {
            // Set Bit 6 to M1
            o_addr |= ((mrnk & 0x01) << 57);
        }
        else
        {
            // Set remaining bits starting at 6
            setRemainingRowBitsAndDimmSelect(6, row, rowBits, dslct, o_addr);
            break;
        }

        // Bit 5
        if (slvs >= 8)
        {
            // Set bit 5 to S0
            o_addr |= ((srnk & 0x04) << 56);
        }
        else if (mstrs == 2 && slvs == 4)
        {
            // Set bit 5 to M1
            o_addr |= ((mrnk & 0x01) << 58);
        }
        else
        {
            setRemainingRowBitsAndDimmSelect(5, row, rowBits, dslct, o_addr);
            break;
        }

        // Bit 4
        if (mstrs == 2 && slvs == 8)
        {
            // Set bit 4 to M1
            o_addr |= ((mrnk & 0x01) << 59);

            // Set remaining row bits
            setRemainingRowBitsAndDimmSelect(3, row, rowBits, dslct, o_addr);
            break;
        }
        else
        {
            setRemainingRowBitsAndDimmSelect(4, row, rowBits, dslct, o_addr);
            break;
        }

    } while (0);

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
        // Get 40-bit MCA Port address
        l_rc = getMcaPortAddr( i_chip, i_addr, o_addr);
        if (l_rc) break;

        // Construct the 56-bit Powerbus address

        // Shift the 40 bit port address in bits 0:39 over to bits 24:63
        o_addr = o_addr >> 24;

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
        PRDF_TRAC( PRDF_FUNC "Page dealloc address: 0x%016llX", sysAddr );

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
                   "End Addr: 0x%016llX", ssAddr, seAddr );

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
        PRDF_TRAC( PRDF_FUNC "MBA dealloc for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llX", ssAddr, seAddr );

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
                   "End Addr: 0x%016llX", smallestAddr, largestAddr );

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

