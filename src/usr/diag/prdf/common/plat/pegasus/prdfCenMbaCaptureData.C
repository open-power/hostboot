/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaCaptureData.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2013              */
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
#include <utilmem.H>
#include <UtilHash.H>
#include <prdfDramRepairUsrData.H>
#include <iipServiceDataCollector.h>
#include <prdfRasServices.H>

// Pegasus includes
#include <prdfCenMarkstore.H>
#include <prdfCenDqBitmap.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace CenMbaCaptureData
{

//------------------------------------------------------------------------------

void addMemEccData( TargetHandle_t i_mba, errlHndl_t io_errl )
{
    CaptureData cd;

    // Add DRAM repairs data from hardware.
    captureDramRepairsData( i_mba, cd );

    // Add DRAM repairs data from VPD.
    captureDramRepairsVpd( i_mba, cd );

    ErrDataService::AddCapData( cd, io_errl );
}

//------------------------------------------------------------------------------

void addMemEccData( TargetHandle_t i_mba, STEP_CODE_DATA_STRUCT & io_sc )
{
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    // Add DRAM repairs data from hardware.
    captureDramRepairsData( i_mba, cd );

    // Add DRAM repairs data from VPD.
    captureDramRepairsVpd( i_mba, cd );
}

//------------------------------------------------------------------------------

void captureDramRepairsData( TARGETING::TargetHandle_t i_mbaTarget,
                             CaptureData & o_cd )
{
    int32_t rc = SUCCESS;
    DramRepairMbaData mbaData;

    // Iterate all ranks to get DRAM repair data
    for ( uint32_t r = 0; r < MASTER_RANKS_PER_MBA; r++ )
    {
        CenRank rank ( r );

        // Get chip/symbol marks
        CenMark mark;
        rc = PlatServices::mssGetMarkStore( i_mbaTarget, rank, mark );
        if ( SUCCESS != rc )
        {
            PRDF_ERR("Failed to get markstore data");
            continue;
        }

        // Get DRAM spares
        CenSymbol sp0, sp1, ecc;
        rc = PlatServices::mssGetSteerMux( i_mbaTarget, rank, sp0, sp1, ecc );
        if ( SUCCESS != rc )
        {
            PRDF_ERR("Failed to get DRAM steer data");
            continue;
        }

        // Add data
        DramRepairRankData rankData = { rank.getMaster(),
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
        bool isCentaurDimm = true;
        mbaData.header.rankCount = mbaData.rankDataList.size();
        PlatServices::isMembufOnDimm( i_mbaTarget, isCentaurDimm );
        mbaData.header.isIsDimm = !isCentaurDimm;
        mbaData.header.isX4Dram = PlatServices::isDramWidthX4( i_mbaTarget );
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
        BIT_STRING_ADDRESS_CLASS dramRepairData ( 0, ( dramStream.size() )*8,
                                               (CPU_WORD *) dramStream.base() );
        o_cd.Add( i_mbaTarget, Util::hashString("DRAM_REPAIRS_DATA"),
                  dramRepairData );
    }
}

//------------------------------------------------------------------------------

void captureDramRepairsVpd( TargetHandle_t i_mba, CaptureData & io_cd )
{
    #define PRDF_FUNC "[captureDramRepairsVpd] "

    // Get the maximum capture data size.
    static const size_t sz_rank  = sizeof(uint8_t);
    static const size_t sz_entry = PORT_SLCT_PER_MBA * DIMM_DQ_RANK_BITMAP_SIZE;
    static const size_t sz_word  = sizeof(CPU_WORD);

    // Get the maximum capture data size.
    size_t sz_maxData = MASTER_RANKS_PER_MBA * (sz_rank + sz_entry);

    // Adjust the size for endianess.
    sz_maxData = ((sz_maxData + sz_word-1) / sz_word) * sz_word;

    // Initialize to 0.
    uint8_t capData[sz_maxData];
    memset( capData, 0x00, sz_maxData );

    // Get the data for each rank.
    uint32_t idx = 0;
    for ( uint8_t r = 0; r < MASTER_RANKS_PER_MBA; r++ )
    {
        CenRank rank ( r );
        CenDqBitmap bitmap;

        if ( SUCCESS != getBadDqBitmap(i_mba, rank, bitmap, true) )
        {
            PRDF_ERR( PRDF_FUNC"getBadDqBitmap() failed: MBA=0x%08x rank=%d",
                      getHuid(i_mba), r );
            continue; // skip this rank
        }

        if ( bitmap.badDqs() ) // make sure the data is non-zero
        {
            // Add the rank, then the entry data.
            capData[idx] = r;                                  idx += sz_rank;
            memcpy(&capData[idx], bitmap.getData(), sz_entry); idx += sz_entry;
        }
    }

    // Fix endianess issues with non PPC machines.
    size_t sz_capData = idx;
    sz_capData = ((sz_capData + sz_word-1) / sz_word) * sz_word;
    for ( uint32_t i = 0; i < (sz_capData/sz_word); i++ )
        ((CPU_WORD*)capData)[i] = htonl(((CPU_WORD*)capData)[i]);

    // Add data to capture data.
    BIT_STRING_ADDRESS_CLASS bs ( 0, sz_capData*8, (CPU_WORD *) &capData );
    io_cd.Add( i_mba, Util::hashString("DRAM_REPAIRS_VPD"), bs );

    #undef PRDF_FUNC
}

}  //end namespace MbaCaptureData

} // end namespace PRDF


