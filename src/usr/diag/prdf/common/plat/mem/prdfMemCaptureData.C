/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCaptureData.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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
#include <prdfOcmbDataBundle.H>
#include <prdfMemRowRepair.H>



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
        TargetHandle_t trgt = i_memMru.getTrgt();
        uint8_t port = extMemMru.mmMeld.s.port;

        if ( TYPE_OCMB_CHIP == getTargetType(trgt) )
        {
            TargetHandle_t dimm = getConnectedDimm( trgt, i_memMru.getRank(),
                                                    port );
            extMemMru.isX4Dram = isDramWidthX4( dimm ) ? 1 : 0;
        }
        else
        {
            // Get the DRAM width.
            extMemMru.isX4Dram = isDramWidthX4( trgt ) ? 1 : 0;
        }

        if ( 0 == extMemMru.isBufDimm )
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

                if ( TYPE_OCMB_CHIP == getTargetType(trgt) )
                {
                    TargetHandle_t memport = getConnectedChild(trgt,
                        TYPE_MEM_PORT, port);
                    getDimmDqAttr<TYPE_MEM_PORT>(memport, extMemMru.dqMapping);
                }
                else
                {
                    PRDF_ERR( PRDF_FUNC "Invalid target type." );
                    PRDF_ASSERT(false);
                }
            }
        }

        // If we reach this point, nothing failed and the data is valid.
        extMemMru.isValid = 1;

    }while(0);

    static const size_t sz_word  = sizeof(CPU_WORD);
    size_t sz_buf = ( (sizeof(extMemMru) + sz_word-1) / sz_word ) * sz_word;
    BitStringBuffer bsb( sz_buf*8 );
    uint32_t curPos = 0;

    // TODO RTC 179854
    bsb.setFieldJustify( curPos, 32, extMemMru.mmMeld.u  ); curPos+=32;
    bsb.setFieldJustify( curPos,  1, extMemMru.isBufDimm ); curPos+= 1;
    bsb.setFieldJustify( curPos,  1, extMemMru.isX4Dram  ); curPos+= 1;
    bsb.setFieldJustify( curPos,  1, extMemMru.isValid   ); curPos+= 1;

    // Have 5 reserved bits to put the DQ mapping on the byte line for ease of
    // parsing
    bsb.setFieldJustify( curPos, 5, 0 ); curPos+=5;

    for ( uint8_t i = 0; i < sizeof(extMemMru.dqMapping); i++ )
    {
        bsb.setFieldJustify( curPos, 8, extMemMru.dqMapping[i] );
        curPos += 8;
    }

    // NOTE: The BitString and BitStringBuffer classes are not endian safe. As
    // such, this is needed to ensure this works with non-PPC machines.
    CPU_WORD* bufAddr = bsb.getBufAddr();
    for ( uint32_t i = 0; i < (sz_buf/sz_word); i++ )
    {
        bufAddr[i] = htobe32(bufAddr[i]);
    }

    // Add the extended MemoryMru to the error log.
    PRDF_ADD_FFDC( io_errl, bsb.getBufAddr(), sz_buf, ErrlVer2, ErrlMruData );

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
void captureDramRepairsData<TYPE_OCMB_CHIP>(TARGETING::TargetHandle_t i_trgt,
                                            CaptureData & io_cd, uint8_t i_port)
{
    #define PRDF_FUNC "[captureDramRepairsData] "

    int32_t rc = SUCCESS;
    DramRepairUsrData data;
    data.header.isSpareDram = false;

    ExtensibleChip * chip = (ExtensibleChip *)systemPtr->GetChip( i_trgt );
    std::vector<MemRank> masterRanks;

    do
    {
        getMasterRanks<TYPE_OCMB_CHIP>( i_trgt, i_port, masterRanks );
        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC "Master Rank list size is 0");
            break;
        }

        uint8_t spareConfig = MEM_EFF_DIMM_SPARE_NO_SPARE;
        // check for spare DRAM.
        rc = getDimmSpareConfig<TYPE_OCMB_CHIP>( i_trgt, masterRanks[0], i_port,
                                                 spareConfig );
        if( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC "getDimmSpareConfig() failed" );
            break;
        }

        if( MEM_EFF_DIMM_SPARE_NO_SPARE != spareConfig )
            data.header.isSpareDram = true;

        TargetHandle_t memport = getConnectedChild(i_trgt, TYPE_MEM_PORT,
                                                   i_port);
        if (nullptr == memport)
        {
            PRDF_ERR(PRDF_FUNC "Failed to get child MEM_PORT %x from parent "
                     "0x%08x", i_port, getHuid(i_trgt));
            return;
        }

        // Iterate all ranks to get DRAM repair data
        for ( auto & rank : masterRanks )
        {
            // Get chip/symbol marks
            MemMark cm, sm;
            rc = MarkStore::readChipMark<TYPE_OCMB_CHIP>( chip, rank, i_port,
                                                          cm );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "readChipMark<TYPE_OCMB_CHIP>(0x%08x,"
                          "0x%02x,%x) failed", chip->getHuid(), rank.getKey(),
                          i_port );
                continue;
            }

            rc = MarkStore::readSymbolMark<TYPE_OCMB_CHIP>( chip, rank, i_port,
                                                            sm );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "readSymbolMark<TYPE_OCMB_CHIP>(0x%08x,"
                          "0x%02x,%x) failed", chip->getHuid(), rank.getKey(),
                          i_port );
                continue;
            }

            // Get DRAM spares
            MemSymbol sp0, sp1;
            rc = mssGetSteerMux<TYPE_MEM_PORT>( memport, rank, sp0, sp1 );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC "mssGetSteerMux() failed");
                continue;
            }

            // Add data
            DramRepairRankData rankData = { rank.getMaster(),
                                              cm.getSymbol().getSymbol(),
                                              sm.getSymbol().getSymbol(),
                                             sp0.getSymbol(),
                                             sp1.getSymbol() };
            if ( rankData.valid() )
            {
                data.rankDataList.push_back(rankData);
            }
        }

        // If data exists, add header information.
        if ( data.rankDataList.size() > 0 )
        {
            data.header.rankCount = data.rankDataList.size();
            data.header.port = i_port;

            UtilMem dramStream;
            dramStream << data;

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
                                    htobe32(((uint32_t*)dramStream.base())[i]);
            }
            #endif

            // Allocate space for the capture data.
            BitString dramRepairData ( ( dramStream.size() )*8,
                                       (CPU_WORD *) dramStream.base() );

            io_cd.Add( i_trgt, Util::hashString("DRAM_REPAIRS_DATA"),
                       dramRepairData );

      }
    } while (0);

    if ( FAIL == rc )
    {
      PRDF_ERR( PRDF_FUNC "Failed on 0x%08X", getHuid( i_trgt ) );
    }

    #undef PRDF_FUNC
}


//------------------------------------------------------------------------------

template<>
void captureDramRepairsVpd<TYPE_OCMB_CHIP>(TargetHandle_t i_trgt,
    CaptureData & io_cd, uint8_t i_port)
{
    #define PRDF_FUNC "[captureDramRepairsVpd] "

    // Get the maximum capture data size.
    static const size_t sz_rank  = sizeof(uint8_t);
    static const size_t sz_port  = sizeof(uint8_t);
    static const size_t sz_entry = DQ_BITMAP::BITMAP_SIZE;
    static const size_t sz_word  = sizeof(CPU_WORD);

    do
    {
        std::vector<MemRank> masterRanks;
        getMasterRanks<TYPE_OCMB_CHIP>( i_trgt, i_port, masterRanks );
        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC "Master Rank list size is 0");
            break;
        }

        // Get the maximum capture data size.
        size_t sz_maxData = masterRanks.size() * MAX_DIMM_PER_RANK *
                            (sz_rank + sz_port + sz_entry);

        // Adjust the size for endianness.
        sz_maxData = ((sz_maxData + sz_word-1) / sz_word) * sz_word;

        // Initialize to 0.
        uint8_t capData[sz_maxData];
        memset( capData, 0x00, sz_maxData );

        // Get the MEM_PORT target
        TargetHandle_t memport = getConnectedChild(i_trgt, TYPE_MEM_PORT,
                                                   i_port);
        if (nullptr == memport)
        {
            PRDF_ERR(PRDF_FUNC "Failed to get child MEM_PORT %x from parent "
                     "0x%08x", i_port, getHuid(i_trgt));
            return;
        }

        // Iterate all ranks to get VPD data
        uint32_t idx = 0;
        for ( auto & rank : masterRanks )
        {
            MemDqBitmap bitmap;

            if ( SUCCESS != getBadDqBitmap<TYPE_MEM_PORT>(memport, rank,
                                                          bitmap) )
            {
                PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed: Trgt=0x%08x"
                          " rank=0x%02x", getHuid(memport), rank.getKey() );
                continue; // skip this rank
            }

            if ( bitmap.badDqs() ) // make sure the data is non-zero
            {
                uint8_t ps = memport->getAttr<ATTR_REL_POS>();
                // Add the rank, port, then the entry data.
                capData[idx] = rank.getMaster();
                idx += sz_rank;
                capData[idx] = ps;
                idx += sz_port;
                memcpy(&capData[idx], bitmap.getData(), sz_entry);
                idx += sz_entry;
            }
        }

        if( 0 == idx ) break; // Nothing to capture

        // Fix endianness issues with non PPC machines.
        size_t sz_capData = idx;
        sz_capData = ((sz_capData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_capData/sz_word); i++ )
            ((CPU_WORD*)capData)[i] = htobe32(((CPU_WORD*)capData)[i]);

        // Add data to capture data.
        BitString bs ( sz_capData*8, (CPU_WORD *) &capData );
        io_cd.Add( i_trgt, Util::hashString("DRAM_REPAIRS_VPD"), bs );

    }while(0);


    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
void captureRowRepairVpd(TargetHandle_t i_trgt, CaptureData & io_cd,
                         uint8_t i_port)
{
    #define PRDF_FUNC "[captureRowRepairVpd] "

    // Get the maximum capture data size.
    static const size_t sz_rank  = sizeof(uint8_t);
    static const size_t sz_port  = sizeof(uint8_t);
    static const size_t sz_entry = ROW_REPAIR::ROW_REPAIR_SIZE;
    static const size_t sz_word  = sizeof(CPU_WORD);

    do
    {
        std::vector<MemRank> masterRanks;
        getMasterRanks<T>( i_trgt, i_port, masterRanks );
        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC "Master Rank list size is 0");
            break;
        }

        // Get the maximum capture data size.
        size_t sz_maxData = masterRanks.size() * MAX_DIMM_PER_RANK *
                            (sz_rank + sz_port + sz_entry);

        // Adjust the size for endianness.
        sz_maxData = ((sz_maxData + sz_word-1) / sz_word) * sz_word;

        // Initialize to 0.
        uint8_t capData[sz_maxData];
        memset( capData, 0x00, sz_maxData );

        // Get the memory port
        TargetHandle_t memport = getConnectedChild(i_trgt, TYPE_MEM_PORT,
                                                   i_port);
        if (nullptr == memport)
        {
            PRDF_ERR(PRDF_FUNC "Failed to get child MEM_PORT %x from parent "
                     "0x%08x", i_port, getHuid(i_trgt));
            return;
        }

        // Get all DIMMs attached to the port
        TargetHandleList dimmList = getConnectedChildren(memport, TYPE_DIMM);

        // Iterate all ranks on each DIMM to get VPD data
        uint32_t idx = 0;
        for ( auto & dimm : dimmList )
        {
            for ( auto & rank : masterRanks )
            {
                MemRowRepair rowRepair;

                if ( SUCCESS != getRowRepairData<T>(dimm, rank, rowRepair) )
                {
                    PRDF_ERR( PRDF_FUNC "getRowRepairData() failed: dimm=0x%08x"
                            " rank=0x%02x", getHuid(i_trgt), rank.getKey() );
                    continue; // skip this dimm
                }

                if ( rowRepair.nonZero() ) // make sure the data is non-zero
                {
                    // Add the rank, port, then the entry data.
                    capData[idx] = rank.getMaster();
                    idx += sz_rank;
                    capData[idx] = getDimmPort( dimm );
                    idx += sz_port;
                    memcpy(&capData[idx], rowRepair.getData(), sz_entry);
                    idx += sz_entry;
                }
            }
        }

        if( 0 == idx ) break; // Nothing to capture

        // Fix endianness issues with non PPC machines.
        size_t sz_capData = idx;
        sz_capData = ((sz_capData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_capData/sz_word); i++ )
            ((CPU_WORD*)capData)[i] = htobe32(((CPU_WORD*)capData)[i]);

        // Add data to capture data.
        BitString bs ( sz_capData*8, (CPU_WORD *) &capData );
        io_cd.Add( i_trgt, Util::hashString("ROW_REPAIR_VPD"), bs );

    }while(0);


    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
void captureIueCounts<OcmbDataBundle*>( TARGETING::TargetHandle_t i_trgt,
                                        OcmbDataBundle * i_db,
                                        CaptureData & io_cd )
{
    #ifdef __HOSTBOOT_MODULE

    uint8_t sz_capData = i_db->iv_iueTh.size()*2;
    uint8_t capData[sz_capData] = {};
    uint8_t idx = 0;

    for ( auto & th_pair : i_db->iv_iueTh )
    {
        capData[idx]   = th_pair.first;
        capData[idx+1] = th_pair.second.getCount();
        idx += 2;
    }

    // Add data to capture data.
    BitString bs ( sz_capData*8, (CPU_WORD *) &capData );
    io_cd.Add( i_trgt, Util::hashString("IUE_COUNTS"), bs );

    #endif
}

//------------------------------------------------------------------------------

template<>
void addEccData<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
                                 STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_OCMB_CHIP == i_chip->getType() );

    CaptureData & cd = io_sc.service_data->GetCaptureData();
    OcmbDataBundle * db = getOcmbDataBundle( i_chip );

    TargetHandle_t ocmbTrgt = i_chip->getTrgt();

    if (nullptr != getConnectedChild(i_chip->getTrgt(), TYPE_MEM_PORT, 0))
    {
        // Add DRAM repairs data from hardware for port0 if it exists.
        captureDramRepairsData<TYPE_OCMB_CHIP>( ocmbTrgt, cd, 0 );

        // Add DRAM repairs data from VPD for port0 if it exists.
        captureDramRepairsVpd<TYPE_OCMB_CHIP>( ocmbTrgt, cd, 0 );

        // Add Row Repair data from VPD for port0 if it exists
        captureRowRepairVpd<TYPE_OCMB_CHIP>( ocmbTrgt, cd, 0 );
    }

    if (isOdysseyOcmb(i_chip->getTrgt()) &&
        nullptr != getConnectedChild(i_chip->getTrgt(), TYPE_MEM_PORT, 1))
    {
        // Add DRAM repairs data from hardware for port1 if it exists.
        captureDramRepairsData<TYPE_OCMB_CHIP>( ocmbTrgt, cd, 1 );

        // Add DRAM repairs data from VPD for port1 if it exists.
        captureDramRepairsVpd<TYPE_OCMB_CHIP>( ocmbTrgt, cd, 1 );

        // Add Row Repair data from VPD for port1 if it exists
        captureRowRepairVpd<TYPE_OCMB_CHIP>( ocmbTrgt, cd, 1 );
    }

    // Add IUE counts to capture data.
    captureIueCounts<OcmbDataBundle*>( ocmbTrgt, db, cd );

    // Add CE table to capture data.
    db->iv_ceTable.addCapData( cd );

    // Add UE table to capture data.
    db->iv_ueTable.addCapData( cd );
}

//------------------------------------------------------------------------------

template<>
void addEccData<TYPE_OCMB_CHIP>( TargetHandle_t i_trgt,
                                 errlHndl_t io_errl )
{
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_trgt) );

    CaptureData cd;

    if (nullptr != getConnectedChild(i_trgt, TYPE_MEM_PORT, 0))
    {
        // Add DRAM repairs data from hardware for port0 if it exists.
        captureDramRepairsData<TYPE_OCMB_CHIP>( i_trgt, cd, 0 );

        // Add DRAM repairs data from VPD for port0 if it exists.
        captureDramRepairsVpd<TYPE_OCMB_CHIP>( i_trgt, cd, 0 );
    }

    if (isOdysseyOcmb(i_trgt) &&
        nullptr != getConnectedChild(i_trgt, TYPE_MEM_PORT, 1))
    {
        // Add DRAM repairs data from hardware for port1 if it exists.
        captureDramRepairsData<TYPE_OCMB_CHIP>( i_trgt, cd, 1 );

        // Add DRAM repairs data from VPD for port1 if it exists.
        captureDramRepairsVpd<TYPE_OCMB_CHIP>( i_trgt, cd, 1 );
    }

    ErrDataService::AddCapData( cd, io_errl );
}

//------------------------------------------------------------------------------

}  //end namespace MemCaptureData

} // end namespace PRDF

