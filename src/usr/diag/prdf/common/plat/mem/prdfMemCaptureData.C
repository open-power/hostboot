/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCaptureData.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#include <prdfMemCaptureData.H>

// Framework includes
#include <iipCaptureData.h>
#include <iipSystem.h>
#include <prdfDramRepairUsrData.H>
#include <prdfErrlUtil.H>
#include <prdfGlobal.H>
#include <prdfMemMark.H>
#include <UtilHash.H>
#include <utilmem.H>

// Platform includes
#include <prdfPlatServices.H>
#include <prdfP9McaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MemCaptureData
{

//------------------------------------------------------------------------------

void addExtMemMruData( const MemoryMru & i_memMru, errlHndl_t io_errl )
{
    #define PRDF_FUNC "[addExtMemMruData] "

    MemoryMruData::ExtendedData extMemMru ( i_memMru.toUint32() );

    do
    {
        int32_t l_rc = SUCCESS;

        TargetHandle_t trgt = i_memMru.getTrgt();

        // Get the DRAM width.
        extMemMru.isX4Dram = isDramWidthX4( trgt ) ? 1 : 0;

        // Get the DIMM type.
        bool isBufDimm = false;
        l_rc = isMembufOnDimm( trgt, isBufDimm );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "isMembufOnDimm() failed. Trgt:0x%08x",
                      getHuid(trgt) );
            break;
        }
        extMemMru.isBufDimm = isBufDimm ? 1 : 0;

        if ( isBufDimm )
        {
            // TODO RTC 169956
            //// Get the raw card type (Centaur DIMMs only).
            //CEN_SYMBOL::WiringType cardType = CEN_SYMBOL::WIRING_INVALID;
            //l_rc = getMemBufRawCardType( trgt, cardType );
            //if ( SUCCESS != l_rc )
            //{
            //    PRDF_ERR( PRDF_FUNC "getMemBufRawCardType() failed. MBA:0x%08x",
            //              getHuid(trgt) );
            //    break;
            //}
            //extMemMru.cardType = cardType;
        }
        else
        {
            // Get the 80-byte DQ map (ISDIMMs only). This is only needed if the
            // MemoryMru contains a single DIMM callout with a valid symbol.
            if ( i_memMru.getSymbol().isValid() )
            {
                TargetHandleList partList = i_memMru.getCalloutList();
                if ( 1 != partList.size() ||
                     TYPE_DIMM != getTargetType(partList[0]) )
                {
                    PRDF_ERR( PRDF_FUNC "Symbol is valid but callout is not a "
                              "single DIMM." );
                    break;
                }
                getDimmDqAttr( trgt, extMemMru.dqMapping );
            }
        }

        // If we reach this point, nothing failed and the data is valid.
        extMemMru.isValid = 1;

    }while(0);

    size_t sz_buf = sizeof(extMemMru);
    BitStringBuffer bsb( sz_buf*8 );
    uint32_t curPos = 0;

    bsb.setFieldJustify( curPos, 32, extMemMru.mmMeld.u  ); curPos+=32;
    bsb.setFieldJustify( curPos,  8, extMemMru.cardType  ); curPos+= 8;
    bsb.setFieldJustify( curPos,  1, extMemMru.isBufDimm ); curPos+= 1;
    bsb.setFieldJustify( curPos,  1, extMemMru.isX4Dram  ); curPos+= 1;
    bsb.setFieldJustify( curPos,  1, extMemMru.isValid   ); curPos+= 1;

    BitString bs( sizeof(extMemMru.dqMapping)*8,
                  (CPU_WORD *)extMemMru.dqMapping );
    bsb.setString( bs, 0, bs.getBitLen(), curPos );

    // Add the extended MemoryMru to the error log.
    PRDF_ADD_FFDC( io_errl, bsb.getBufAddr(), sz_buf, ErrlVer1, ErrlMruData );

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
void captureDramRepairsData<TYPE_MCA>( TARGETING::TargetHandle_t i_trgt,
                                       CaptureData & io_cd )
{
    #define PRDF_FUNC "[captureDramRepairsData<TYPE_MCA>] "

    int32_t rc = SUCCESS;
    DramRepairUsrData mcaData;
    mcaData.header.isSpareDram = false;

    ExtensibleChip * mcaChip = (ExtensibleChip *)systemPtr->GetChip( i_trgt );
    std::vector<MemRank> masterRanks;

    do
    {
        getMasterRanks<TYPE_MCA>( i_trgt, masterRanks );
        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC "Master Rank list size is 0");
            break;
        }

        // Iterate all ranks to get DRAM repair data
        for ( auto & rank : masterRanks )
        {
            // Get chip/symbol marks
            MemMark cm, sm;
            rc = MarkStore::readChipMark<TYPE_MCA>( mcaChip, rank, cm );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_MCA>(0x%08x,0x%02x) "
                          "failed", mcaChip->getHuid(), rank.getKey() );
                continue;
            }

            rc = MarkStore::readSymbolMark<TYPE_MCA>( mcaChip, rank, sm );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "readSymbolMark<TYPE_MCA>(0x%08x,0x%02x) "
                          "failed", mcaChip->getHuid(), rank.getKey() );
                continue;
            }

            if ( cm.isValid() && sm.isValid() )
            {
                // Add data
                DramRepairRankData rankData = { rank.getMaster(),
                                                cm.getSymbol().getSymbol(),
                                                sm.getSymbol().getSymbol() };
                mcaData.rankDataList.push_back(rankData);
            }
        }
        // If MCA had some DRAM repair data, add header information
        if( mcaData.rankDataList.size() > 0 )
        {
            mcaData.header.rankCount = mcaData.rankDataList.size();
            mcaData.header.isX4Dram =  isDramWidthX4( i_trgt );
            UtilMem dramStream;
            dramStream << mcaData;

            // TODO RTC 179854
            #ifndef PPC
            // Fix endianness issues with non PPC machines.
            // This is a workaround. Though UtilMem takes care of endianness,
            // It seems with capture data its not working
            const size_t sz_word = sizeof(uint32_t);

            // Align data with 32 bit boundary
            for (uint32_t i = 0; i < ( dramStream.size()%sz_word ); i++)
            {
                uint8_t dummy = 0;
                dramStream << dummy;
            }
            for ( uint32_t i = 0; i < ( dramStream.size()/sz_word); i++ )
            {
                ((uint32_t*)dramStream.base())[i] =
                            htonl(((uint32_t*)dramStream.base())[i]);
            }
            #endif

            // Allocate space for the capture data.
            BitString dramRepairData ( ( dramStream.size() )*8,
                                               (CPU_WORD *) dramStream.base() );
            io_cd.Add( i_trgt, Util::hashString("DRAM_REPAIRS_DATA"),
                       dramRepairData );
        }
    }while(0);

    if( FAIL == rc )
        PRDF_ERR( PRDF_FUNC "Failed for MCA 0x%08X", getHuid( i_trgt ) );

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
void captureDramRepairsData<TYPE_MBA>( TARGETING::TargetHandle_t i_trgt,
                                       CaptureData & io_cd )
{
    #define PRDF_FUNC "[CenMbaCaptureData::captureDramRepairsData] "
    /* TODO RTC 178911
    using namespace fapi; // for spare config

    int32_t rc = SUCCESS;
    DramRepairMbaData mbaData;

    mbaData.header.isSpareDram = false;
    std::vector<CenRank> masterRanks;

    do
    {
        rc = getMasterRanks( i_mbaTrgt, masterRanks );
        if ( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "getMasterRanks() failed" );
            break;
        }
        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC "Master Rank list size is 0");
            break;;
        }
        uint8_t spareConfig = ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE;
        // check for spare DRAM. Port does not matter.
        // Also this configuration is same for all ranks on MBA.
        rc = getDimmSpareConfig( i_mbaTrgt, masterRanks[0], 0, spareConfig );
        if( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "getDimmSpareConfig() failed" );
            break;
        }

        if( ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE != spareConfig )
            mbaData.header.isSpareDram = true;

        // Iterate all ranks to get DRAM repair data
        for ( std::vector<CenRank>::iterator it = masterRanks.begin();
              it != masterRanks.end(); it++ )
        {
            // Get chip/symbol marks
            CenMark mark;
            rc = mssGetMarkStore( i_mbaTrgt, *it, mark );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "mssGetMarkStore() Failed");
                continue;
            }

            // Get DRAM spares
            CenSymbol sp0, sp1, ecc;
            rc = mssGetSteerMux( i_mbaTrgt, *it, sp0, sp1, ecc );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed");
                continue;
            }

            // Add data
            DramRepairRankData rankData = { (*it).getMaster(),
                                            mark.getCM().getSymbol(),
                                            mark.getSM().getSymbol(),
                                            sp0.getSymbol(),
                                            sp1.getSymbol(),
                                            ecc.getSymbol() };
            if ( rankData.valid() )
            {
                mbaData.rankDataList.push_back(rankData);
            }
        }
        // If MBA had some DRAM repair data, add header information
        if( mbaData.rankDataList.size() > 0 )
        {
            mbaData.header.rankCount = mbaData.rankDataList.size();
            mbaData.header.isX4Dram =  isDramWidthX4( i_mbaTrgt );
            UtilMem dramStream;
            dramStream << mbaData;

            #ifndef PPC
            // Fix endianness issues with non PPC machines.
            // This is a workaround. Though UtilMem takes care of endianness,
            // It seems with capture data its not working
            const size_t sz_word = sizeof(uint32_t);

            // Align data with 32 bit boundary
            for (uint32_t i = 0; i < ( dramStream.size()%sz_word ); i++)
            {
                uint8_t dummy = 0;
                dramStream << dummy;
            }
            for ( uint32_t i = 0; i < ( dramStream.size()/sz_word); i++ )
            {
                ((uint32_t*)dramStream.base())[i] =
                            htonl(((uint32_t*)dramStream.base())[i]);
            }
            #endif

            // Allocate space for the capture data.
            BitString dramRepairData ( ( dramStream.size() )*8,
                                               (CPU_WORD *) dramStream.base() );
            io_cd.Add( i_mbaTrgt, Util::hashString("DRAM_REPAIRS_DATA"),
                       dramRepairData );
        }
    }while(0);

    if( FAIL == rc )
        PRDF_ERR( PRDF_FUNC "Failed for MBA 0x%08X", getHuid( i_mbaTrgt ) );*/

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
void captureDramRepairsVpd<TYPE_MCA>(TargetHandle_t i_trgt, CaptureData & io_cd)
{
    #define PRDF_FUNC "[captureDramRepairsVpd] "

    // Get the maximum capture data size.
    static const size_t sz_rank  = sizeof(uint8_t);
    static const size_t sz_entry = MCA_DIMMS_PER_RANK * DQ_BITMAP::BITMAP_SIZE;
    static const size_t sz_word  = sizeof(CPU_WORD);

    do
    {
        std::vector<MemRank> masterRanks;
        getMasterRanks<TYPE_MCA>( i_trgt, masterRanks );
        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC "Master Rank list size is 0");
            break;
        }

        // Get the maximum capture data size.
        size_t sz_maxData = masterRanks.size() * (sz_rank + sz_entry);

        // Adjust the size for endianness.
        sz_maxData = ((sz_maxData + sz_word-1) / sz_word) * sz_word;

        // Initialize to 0.
        uint8_t capData[sz_maxData];
        memset( capData, 0x00, sz_maxData );

        // Iterate all ranks to get VPD data
        uint32_t idx = 0;
        for ( auto & rank : masterRanks )
        {
            MemDqBitmap<DIMMS_PER_RANK::MCA> bitmap;

            if ( SUCCESS != getBadDqBitmap<DIMMS_PER_RANK::MCA>(i_trgt, rank,
                                                                bitmap) )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed: MCA=0x%08x"
                          " rank=0x%02x", getHuid(i_trgt), rank.getKey() );
                continue; // skip this rank
            }

            if ( bitmap.badDqs() ) // make sure the data is non-zero
            {
                // Add the rank, then the entry data.
                capData[idx] = rank.getMaster();
                idx += sz_rank;
                memcpy(&capData[idx], bitmap.getData(), sz_entry);
                idx += sz_entry;
            }
        }

        if( 0 == idx ) break; // Nothing to capture

        // Fix endianness issues with non PPC machines.
        size_t sz_capData = idx;
        sz_capData = ((sz_capData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_capData/sz_word); i++ )
            ((CPU_WORD*)capData)[i] = htonl(((CPU_WORD*)capData)[i]);

        // Add data to capture data.
        BitString bs ( sz_capData*8, (CPU_WORD *) &capData );
        io_cd.Add( i_trgt, Util::hashString("DRAM_REPAIRS_VPD"), bs );

    }while(0);


    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
void captureDramRepairsVpd<TYPE_MBA>(TargetHandle_t i_trgt, CaptureData & io_cd)
{
    #define PRDF_FUNC "[captureDramRepairsVpd] "

    // Get the maximum capture data size.
    /* TODO RTC 178911
    static const size_t sz_rank  = sizeof(uint8_t);
    static const size_t sz_entry = MBA_DIMMS_PER_RANK * DIMM_DQ_RANK_BITMAP_SIZE;
    static const size_t sz_word  = sizeof(CPU_WORD);
    int32_t rc = SUCCESS;

    do
    {
        std::vector<CenRank> masterRanks;
        rc = getMasterRanks( i_mbaTrgt, masterRanks );
        if ( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "getMasterRanks() failed" );
            break;
        }

        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC "Master Rank list size is 0");
            break;
        }

        // Get the maximum capture data size.
        size_t sz_maxData = masterRanks.size() * (sz_rank + sz_entry);

        // Adjust the size for endianness.
        sz_maxData = ((sz_maxData + sz_word-1) / sz_word) * sz_word;

        // Initialize to 0.
        uint8_t capData[sz_maxData];
        memset( capData, 0x00, sz_maxData );

        // Iterate all ranks to get VPD data
        uint32_t idx = 0;
        for ( std::vector<CenRank>::iterator it = masterRanks.begin();
              it != masterRanks.end(); it++ )
        {
            CenDqBitmap bitmap;
            uint8_t rank = it->getMaster();

            if ( SUCCESS != getBadDqBitmap(i_mbaTrgt, *it, bitmap, true) )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed: MBA=0x%08x"
                          " rank=%d", getHuid(i_mbaTrgt), rank );
                continue; // skip this rank
            }

            if ( bitmap.badDqs() ) // make sure the data is non-zero
            {
                // Add the rank, then the entry data.
                capData[idx] = rank;              idx += sz_rank;
                memcpy(&capData[idx], bitmap.getData(), sz_entry);
                idx += sz_entry;
            }
        }

        if( 0 == idx ) break; // Nothing to capture

        // Fix endianness issues with non PPC machines.
        size_t sz_capData = idx;
        sz_capData = ((sz_capData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_capData/sz_word); i++ )
            ((CPU_WORD*)capData)[i] = htonl(((CPU_WORD*)capData)[i]);

        // Add data to capture data.
        BitString bs ( sz_capData*8, (CPU_WORD *) &capData );
        io_cd.Add( i_mbaTrgt, Util::hashString("DRAM_REPAIRS_VPD"), bs );

    }while(0);

    if( FAIL == rc )
        PRDF_ERR( PRDF_FUNC "Failed for MBA 0x%08X", getHuid( i_mbaTrgt ) );*/

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
void addEccData<TYPE_MCA>( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    CaptureData & cd = io_sc.service_data->GetCaptureData();
    McaDataBundle * db = getMcaDataBundle( i_chip );

    TargetHandle_t trgt = i_chip->GetChipHandle();

    // Add DRAM repairs data from hardware.
    captureDramRepairsData<TYPE_MCA>( trgt, cd );

    // Add DRAM repairs data from VPD.
    captureDramRepairsVpd<TYPE_MCA>( trgt, cd );

    // Add CE table to capture data.
    db->iv_ceTable.addCapData( cd );

    // Add UE table to capture data.
    db->iv_ueTable.addCapData( cd );
}

template<>
void addEccData<TYPE_MCBIST>( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    // Add data for each connected MCA.
    ExtensibleChipList list = getConnected( i_chip, TYPE_MCA );
    for ( auto & mcaChip : list ) { addEccData<TYPE_MCA>(mcaChip, io_sc); }
}

template<>
void addEccData<TYPE_MBA>( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

/* TODO: RTC 157888
    CaptureData & cd = io_sc.service_data->GetCaptureData();
    CenMbaDataBundle * db = getMbaDataBundle( i_chip );

    // Add UE table to capture data.
    db->iv_ueTable.addCapData( i_chip, cd );

    // Add CE table to capture data.
    db->iv_ceTable.addCapData( cd );

    // Add RCE table to capture data.
    db->iv_rceTable.addCapData( cd );

    // Add DRAM repairs data from hardware.
    captureDramRepairsData( i_chip->getTrgt(), cd );

    // Add DRAM repairs data from VPD.
    captureDramRepairsVpd( i_chip->getTrgt(), cd );
*/
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void addEccData( TargetHandle_t i_trgt, errlHndl_t io_errl )
{
    CaptureData cd;

    // Add DRAM repairs data from hardware.
    captureDramRepairsData<T>( i_trgt, cd );

    // Add DRAM repairs data from VPD.
    captureDramRepairsVpd<T>( i_trgt, cd );

    ErrDataService::AddCapData( cd, io_errl );
}

// To resolve template linker errors.
template
void addEccData<TYPE_MCA>( TargetHandle_t i_trgt, errlHndl_t io_errl );
template
void addEccData<TYPE_MBA>( TargetHandle_t i_trgt, errlHndl_t io_errl );

//------------------------------------------------------------------------------

}  //end namespace MemCaptureData

} // end namespace PRDF

