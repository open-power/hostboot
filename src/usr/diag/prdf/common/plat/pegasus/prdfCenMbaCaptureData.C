/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaCaptureData.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
 *  @file prdfCenMbaCaptureData.C
 *  @brief Utility Functions to capture MBA data
 */

#include <prdfCenMbaCaptureData.H>

// Framwork includes
#include <iipServiceDataCollector.h>
#include <prdfDramRepairUsrData.H>
#include <prdfExtensibleChip.H>
#include <prdfRasServices.H>
#include <utilmem.H>
#include <UtilHash.H>

// Pegasus includes
#include <prdfCenDqBitmap.H>
#include <prdfCenMarkstore.H>
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMembufDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace CenMbaCaptureData
{

//------------------------------------------------------------------------------

void addMemChipletFirRegs( ExtensibleChip * i_membChip, CaptureData & io_cd )
{
    #define PRDF_FUNC "[CenMbaCaptureData::addMemChipletFirRegs] "

    int32_t l_rc = SUCCESS;

    do
    {
        if ( NULL == i_membChip )
        {
            PRDF_ERR( PRDF_FUNC"Given target is NULL" );
            break;
        }

        if ( TYPE_MEMBUF != getTargetType(i_membChip->GetChipHandle()) )
        {
            PRDF_ERR( PRDF_FUNC"Invalid target type: i_membChip=0x%08x",
                      i_membChip->GetId() );
            break;
        }

        SCAN_COMM_REGISTER_CLASS * cs_global, * re_global, * spa_global;
        cs_global  = i_membChip->getRegister("GLOBAL_CS_FIR");
        re_global  = i_membChip->getRegister("GLOBAL_RE_FIR");
        spa_global = i_membChip->getRegister("GLOBAL_SPA");
        l_rc  = cs_global->Read() | re_global->Read() | spa_global->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"Failed to read a GLOBAL register on "
                      "0x%08x", i_membChip->GetId() );
            break;
        }

        // If global bit 3 is not on, can't scom mem chiplets or mba's
        if( ! (cs_global->IsBitSet(3) ||
               re_global->IsBitSet(3) ||
               spa_global->IsBitSet(3)) )
        {
            break;
        }

        i_membChip->CaptureErrorData(io_cd,
                                     Util::hashString("MemChipletRegs"));

        CenMembufDataBundle * membdb = getMembufDataBundle( i_membChip );

        for ( uint32_t i = 0; i < MAX_MBA_PER_MEMBUF; i++ )
        {
            ExtensibleChip * mbaChip = membdb->getMbaChip(i);
            if ( NULL == mbaChip )
            {
                PRDF_ERR( PRDF_FUNC"MEM_CHIPLET registers indicated an "
                          "attention but no chip found: i_membChip=0x%08x "
                          "i=%d", i_membChip->GetId(), i );
                continue;
            }

            mbaChip->CaptureErrorData(io_cd,
                                      Util::hashString("MemChipletRegs") );
        }

    } while (0);

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void addMemEccData( TargetHandle_t i_mbaTrgt, errlHndl_t io_errl )
{
    CaptureData cd;

    // Add DRAM repairs data from hardware.
    captureDramRepairsData( i_mbaTrgt, cd );

    // Add DRAM repairs data from VPD.
    captureDramRepairsVpd( i_mbaTrgt, cd );

    ErrDataService::AddCapData( cd, io_errl );
}

//------------------------------------------------------------------------------

void addMemEccData( ExtensibleChip * i_mbaChip, STEP_CODE_DATA_STRUCT & io_sc )
{
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    CenMbaDataBundle * mbadb = getMbaDataBundle( i_mbaChip );
    TargetHandle_t mbaTarget = i_mbaChip->GetChipHandle();

    // Add UE table to capture data.
    mbadb->iv_ueTable.addCapData( mbaTarget, cd );

    // Add CE table to capture data.
    mbadb->iv_ceTable.addCapData( mbaTarget, cd );

    // Add RCE table to capture data.
    mbadb->iv_rceTable.addCapData( mbaTarget, cd );

    // Add DRAM repairs data from hardware.
    captureDramRepairsData( mbaTarget, cd );

    // Add DRAM repairs data from VPD.
    captureDramRepairsVpd( mbaTarget, cd );
}

//------------------------------------------------------------------------------

void captureDramRepairsData( TARGETING::TargetHandle_t i_mbaTrgt,
                             CaptureData & io_cd )
{
    #define PRDF_FUNC "[CenMbaCaptureData::captureDramRepairsData] "
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
            PRDF_ERR( PRDF_FUNC"getMasterRanks() failed" );
            break;
        }
        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC"Master Rank list size is 0");
            break;;
        }
        uint8_t spareConfig = ENUM_ATTR_EFF_DIMM_SPARE_NO_SPARE;
        // check for spare DRAM. Port does not matter.
        // Also this configuration is same for all ranks on MBA.
        rc = getDimmSpareConfig( i_mbaTrgt, masterRanks[0], 0, spareConfig );
        if( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC"getDimmSpareConfig() failed" );
            break;
        }

        if( ENUM_ATTR_EFF_DIMM_SPARE_NO_SPARE != spareConfig )
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
                PRDF_ERR( PRDF_FUNC"mssGetMarkStore() Failed");
                continue;
            }

            // Get DRAM spares
            CenSymbol sp0, sp1, ecc;
            rc = mssGetSteerMux( i_mbaTrgt, *it, sp0, sp1, ecc );
            if ( SUCCESS != rc )
            {
                PRDF_ERR( PRDF_FUNC"mssGetSteerMux() failed");
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
            // Fix endianess issues with non PPC machines.
            // This is a workaround. Though UtilMem takes care of endianess,
            // It seems with capture data its not working
            const size_t sz_word = sizeof(uint32_t);

            // Allign data with 32 bit boundary
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
            BIT_STRING_ADDRESS_CLASS dramRepairData ( 0,( dramStream.size() )*8,
                                               (CPU_WORD *) dramStream.base() );
            io_cd.Add( i_mbaTrgt, Util::hashString("DRAM_REPAIRS_DATA"),
                       dramRepairData );
        }
    }while(0);

    if( FAIL == rc )
        PRDF_ERR( PRDF_FUNC"Failed for MBA 0x%08X", getHuid( i_mbaTrgt ) );

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

void captureDramRepairsVpd( TargetHandle_t i_mbaTrgt, CaptureData & io_cd )
{
    #define PRDF_FUNC "[captureDramRepairsVpd] "

    // Get the maximum capture data size.
    static const size_t sz_rank  = sizeof(uint8_t);
    static const size_t sz_entry = PORT_SLCT_PER_MBA * DIMM_DQ_RANK_BITMAP_SIZE;
    static const size_t sz_word  = sizeof(CPU_WORD);
    int32_t rc = SUCCESS;

    do
    {
        std::vector<CenRank> masterRanks;
        rc = getMasterRanks( i_mbaTrgt, masterRanks );
        if ( SUCCESS != rc )
        {
            PRDF_ERR( PRDF_FUNC"getMasterRanks() failed" );
            break;
        }

        if( masterRanks.empty() )
        {
            PRDF_ERR( PRDF_FUNC"Master Rank list size is 0");
            break;
        }

        // Get the maximum capture data size.
        size_t sz_maxData = masterRanks.size() * (sz_rank + sz_entry);

        // Adjust the size for endianess.
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
                PRDF_ERR( PRDF_FUNC"getBadDqBitmap() failed: MBA=0x%08x"
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

        // Fix endianess issues with non PPC machines.
        size_t sz_capData = idx;
        sz_capData = ((sz_capData + sz_word-1) / sz_word) * sz_word;
        for ( uint32_t i = 0; i < (sz_capData/sz_word); i++ )
            ((CPU_WORD*)capData)[i] = htonl(((CPU_WORD*)capData)[i]);

        // Add data to capture data.
        BIT_STRING_ADDRESS_CLASS bs ( 0, sz_capData*8, (CPU_WORD *) &capData );
        io_cd.Add( i_mbaTrgt, Util::hashString("DRAM_REPAIRS_VPD"), bs );

    }while(0);

    if( FAIL == rc )
        PRDF_ERR( PRDF_FUNC"Failed for MBA 0x%08X", getHuid( i_mbaTrgt ) );

    #undef PRDF_FUNC
}

}  //end namespace MbaCaptureData

} // end namespace PRDF


