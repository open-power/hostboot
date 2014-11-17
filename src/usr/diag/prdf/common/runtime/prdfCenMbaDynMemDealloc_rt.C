/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/runtime/prdfCenMbaDynMemDealloc_rt.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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

// The code in this function is based on section 5.4.1 and 5.6 of Centaur
// chip spec.
int32_t getCenPhyAddr( ExtensibleChip * i_mbaChip, ExtensibleChip * i_mbChip,
                       CenAddr i_addr, uint64_t & o_addr  )
{
    #define PRDF_FUNC "[DEALLOC::getCenPhyAddr] "

    int32_t o_rc = SUCCESS;
    o_addr = 0;
    do
    {
        TargetHandle_t mba = i_mbaChip->GetChipHandle();
        uint8_t rowNum = 0;
        uint8_t colNum = 0;
        uint8_t numRanks = 0;
        uint32_t row = i_addr.getRow();
        uint32_t col = i_addr.getCol();
        uint32_t bank = i_addr.getBank();
        uint8_t bankNum = 3;
        o_rc = getDimmRowCol( mba, rowNum, colNum );
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getDimmConfig() failed. HUID:0x%08X",
                      i_mbaChip->GetId());
            break;
        }

        CenRank rank = i_addr.getRank();

        // Get  master ranks for this MBA.
        std::vector<CenRank> configuredRanks;
        o_rc = getMasterRanks( mba, configuredRanks, rank.getDimmSlct() );
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getMasterRanks() failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }
        numRanks = configuredRanks.size();

        uint8_t mbaPos = getTargetPosition( mba );
        const char * reg_str = ( 0 == mbaPos ) ? "MBA0_MBAXCR" : "MBA1_MBAXCR";
        SCAN_COMM_REGISTER_CLASS * mbaxcr = i_mbChip->getRegister( reg_str );

        o_rc = mbaxcr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on %s. HUID:0X%08X",
                      reg_str, i_mbChip->GetId() );
            break;
        }

        // Get the hash mode
        uint8_t hash = mbaxcr->GetBitFieldJustified( 10, 2 );
        if ( 3 <= hash )
        {
            PRDF_ERR( PRDF_FUNC"Invalid value for hash. Hash:%u HUID:0X%08X",
                      hash, i_mbaChip->GetId() );
            o_rc = FAIL;   break;
        }
        // Get the slot configuration. 0 - Only one slot is populated
        // 1 - Both slots are populated

        uint8_t cfg = mbaxcr->GetBitFieldJustified( 8, 1 );

        // HW currently using 256 byte hash mode. In 256 byte
        // hash mode, C3 becomes 32nd bit.
        // There is no plan to have support for 128 bye hash mode.
        // But in 128 byte hash mode, bank bits map to 32nd bit.
        // For compliance perspective supporting both 128 and 256
        // byte hash modes.
        // Interleaving (IL) is general concept for placing consecutive
        // addresses at different locations for performance
        // improvement and is done at different levels.
        // The position of 32 bit defines Interleaving at MBA level.
        // We will use interleaving bit in MBAXSCR to get this
        // information.
        uint8_t mbaIlMode = mbaxcr->GetBitFieldJustified( 12, 1 );

        // The address components are defined as such:
        //   row:  18 bits ordered r17-r0
        //   col:  12 bits ordered c13,c11,c9-c3,c2-c0
        //   bank: DDR3: 3 bits ordered b2-b0
        //         DDR4: 4 bits ordered bg1-bg0,b1-b0

        uint64_t r17_r15 = (row & 0x38000) >> 15;
        uint64_t r14_r0  =  row & 0x07fff;
        uint64_t c13_c4  = (col & 0x00ff0) >> 4;
        uint64_t c3   = (col & 0x00008 ) >> 3;
        uint64_t c2_c1   = (col & 0x00006 ) >> 1;
        // c0 currently is not used.

        o_addr   = r17_r15;             // Start with upper row bits
        o_addr <<= (colNum - 4);        // Make room for upper column bits
        o_addr  |= c13_c4;              // Add upper column bits
        // If IL is not supported, put c3 along with c4.
        if( 0 == mbaIlMode )
        {
            o_addr <<= 1;                   // Make room for C3 bit
            o_addr |= c3;                   // Add C3 bit
        }
        o_addr <<= (bankNum + hash);   // Make room for the bank bits and hash


        // Add the bank bits and adjust for the hash type.
        if ( 0 == hash )
            o_addr |= bank;
        else
        {
            o_addr |= (bank & 0x4) << 1;
            o_addr |=  bank & 0x3;
        }

        // In IL mode, c3 will come after bank bits.
        if( mbaIlMode )
        {
            o_addr <<= 1;                   // Make room for C3 bit
            o_addr |= c3;                   // Add C3 bit
        }
        // Add the lower row bits in the middle.
        uint64_t upper = (o_addr & 0x3fc00) << 15;
        uint64_t lower =  o_addr & 0x003ff;
        o_addr = upper | (r14_r0 << 10) | lower;


        // Get Dmmm Slct and Rank bits
        // LSB is created by ranks bits and MSB is created by dimmSlct bit.
        // If this is only one rank DIMM, we will only have dimm Slct bit.
        // For 2 rank DIMM, we will have one bit for rank slct. For 4 ranks DIMM
        // we will have 2 bits. Once ranks slct bits are placed, we will place
        // DIMM slct bit.
        uint8_t dimmRankBits = rank.getRankSlct() & ( numRanks - 1 );

        if( 1 == cfg )
            dimmRankBits =  dimmRankBits |
                            ( rank.getDimmSlct()  <<  ( numRanks / 2 ));

        // In hash mode. low order bits comes towards LSB of MBA address
        if( hash > 0 )
            o_addr = o_addr | ( dimmRankBits & 0x1 ) << 2;

        if( hash == 2 )
            o_addr = o_addr | ( dimmRankBits & 0x2 ) << 4;

        // Fill up MSB
        o_addr = o_addr |
                 ( dimmRankBits >> hash ) << ( rowNum + ( colNum - 3 )
                                               + hash + bankNum );

        // Change it to 40 bit address. Keep last 5 bits as zero
        o_addr = ( o_addr << 7 ) | ( ( c2_c1 ) << 5 );

        // Find MBA Interleaving bit information on Centaur.

        SCAN_COMM_REGISTER_CLASS * mbsxcr = i_mbChip->getRegister ("MBSXCR");

        o_rc = mbsxcr->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on MBSXCR. HUID:0x%08X",
                      i_mbChip->GetId() ) ;
            break;
        }

        // Get MBA Interleaving mode information and adjust address
        // accordingly.
        uint8_t ilMode = mbsxcr->GetBitFieldJustified( 0, 5 );
        if( 0 != ilMode )
        {
            if ( ( ilMode > 25 ) || ( ilMode < 16 ))
            {
                PRDF_ERR( PRDF_FUNC"Invalid value for IL bit Mode :%u",
                          ilMode );
                o_rc = FAIL; break;
            }
            // Interleaving mode at Centaur level  is used to divide address
            // across MBA for performance reason. As there are only two mba per
            // Centaur, only one bit is required to support IL. Position of IL
            // bit decide which consecutive address will go on a particular MBA.
            // ilMode is 5 bit field
            // 1xxxx tells MBA interleaving is supported.
            // Value 16 suggest bit 23 is the IL bit.
            // Value 25 suggets bit 32 is IL bit.
            // The Centaur address is 40 bits. To get the appropriate shift
            // value for IL bit, we will have to adjust by a factor of 7.

            uint8_t ilBitPos = ilMode + 7;
            uint8_t shiftVal = (40 - 1) - ilBitPos;

            // Split the address to make room for the interleave bit.
            uint64_t upper = (o_addr >> shiftVal) << (shiftVal + 1);
            uint64_t lower = o_addr & (0xffffffffffffffffull >> (64-shiftVal));
            uint64_t ilBit = mbaPos << shiftVal;

            // Put the address back together.
            o_addr = upper | ilBit | lower;
        }

    }while(0);
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
            PRDF_ERR( PRDF_FUNC"getDramGen() failed. HUID:0x%08X",
                      i_mbaChip->GetId());
            break;
        }
        if( fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR3 != dramGen )
        {
            PRDF_ERR( PRDF_FUNC"page Gard is only supported for DDR3."
                      "HUID:0x%08X  DRAM Generation : %u",
                      i_mbaChip->GetId(), dramGen );
            o_rc = FAIL; break;
        }

        CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );
        ExtensibleChip *mbChip = mbadb->getMembChip();
        if( NULL == mbChip )
        {
            PRDF_ERR( PRDF_FUNC" Null Membuf chip for mba. HUID:0x%08X",
                                 i_mbaChip->GetId() );
            o_rc = FAIL; break;
        }
        CenMembufDataBundle * mbdb = getMembufDataBundle( mbChip );
        ExtensibleChip * mcsChip = mbdb->getMcsChip();

        if( NULL == mbChip )
        {
            PRDF_ERR( PRDF_FUNC" Null Mcs chip for Membuf. HUID:0x%08X",
                      mbChip->GetId() );
            o_rc = FAIL; break;
        }

        o_rc = getCenPhyAddr( i_mbaChip, mbChip, i_addr, cenAddr);
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getCenPhyAddr() failed. MBA:0x%08X "
                      "Membuf:0x%08X", i_mbaChip->GetId(), mbChip->GetId());
            break;
        }

        SCAN_COMM_REGISTER_CLASS * mcgfp = mcsChip->getRegister( "MCFGP" );

        o_rc = mcgfp->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"Read() failed on MCFGP. HUID:0x%08X",
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

int32_t pageGard( ExtensibleChip * i_mbaChip, CenAddr i_addr )
{
    #define PRDF_FUNC "[DEALLOC::pageGard] "

    uint64_t sysAddr = 0;
    int32_t o_rc = SUCCESS;
    do
    {
        o_rc = getSystemAddr( i_mbaChip, i_addr, sysAddr);
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getSystemAddr() failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }

        sendPageGardRequest( sysAddr );
        PRDF_TRAC( PRDF_FUNC"Page gard for address: 0x%016llX", sysAddr );

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
        o_rc = getSystemAddr( i_mbaChip, i_addr, sysAddr);
        if( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getSystemAddr() failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }

        sendLmbGardRequest( sysAddr, i_isFetch );
        PRDF_TRAC( PRDF_FUNC"LMB gard for address: 0x%016llX", sysAddr );

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
        CenAddr startAddr, endAddr;
        TargetHandle_t mba = i_mbaChip->GetChipHandle();
        o_rc = getMemAddrRange( mba, startAddr, endAddr );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getMemAddrRange() Failed. HUID:0x%08X",
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
            PRDF_ERR( PRDF_FUNC"getSystemAddr() failed. HUID:0x%08X",
                      i_mbaChip->GetId() );
            break;
        }

        // Send the address range to PHYP
        sendDynMemDeallocRequest( ssAddr, seAddr );
        PRDF_TRAC( PRDF_FUNC"MBA gard for Start Addr: 0x%016llx "
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
        TargetHandle_t mba =  getConnectedParent( i_dimm, TYPE_MBA );

        ExtensibleChip * mbaChip = (ExtensibleChip *)systemPtr->GetChip( mba );
        if ( NULL == mbaChip )
        {
            PRDF_ERR( PRDF_FUNC"No MBA chip behind DIMM" );
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
            PRDF_ERR( PRDF_FUNC"getMbaDimm() failed" );
            break;
        }

        o_rc = getMasterRanks( mba, masterRanks, dimmSlct );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"getMasterRanks() failed" );
            break;
        }

        // Iterate all ranks to get start and end address.
        for ( std::vector<CenRank>::iterator it = masterRanks.begin();
              it != masterRanks.end(); it++ )
        {
            o_rc = getMemAddrRange( mba, *it, startAddr, endAddr );
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC"getMemAddrRange() Failed. HUID:0x%08X",
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
                PRDF_ERR( PRDF_FUNC"getSystemAddr() failed. HUID:0x%08X",
                          mbaChip->GetId() );
                break;
            }
            if ( ssAddr < smallestAddr ) smallestAddr = ssAddr;
            if ( seAddr > largestAddr  ) largestAddr  = seAddr;
        }
        if( SUCCESS != o_rc ) break;

        // Send the address range to PHYP
        sendDynMemDeallocRequest( smallestAddr, largestAddr );
        PRDF_TRAC( PRDF_FUNC"DIMM Slct gard for Start Addr: 0x%016llx "
                   "End Addr: 0x%016llX", smallestAddr, largestAddr );

    } while (0);

    if( FAIL == o_rc )
    {
        PRDF_ERR( PRDF_FUNC"failed. DIMM:0x%08X", getHuid( i_dimm ) );
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
            PRDF_ERR( PRDF_FUNC" getMbaDimm() failed" );
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
            PRDF_ERR( PRDF_FUNC" getMbaDimm() failed" );
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
            PRDF_ERR(PRDF_FUNC"Failed for DIMM 0x:%08X", getHuid( *it ) );
            o_rc |= l_rc;
        }
    }
    return o_rc;
    #undef PRDF_FUNC
}
} //namespace DEALLOC
} // namespace PRDF
