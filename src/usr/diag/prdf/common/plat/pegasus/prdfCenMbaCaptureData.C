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
#include <utilmem.H>
#include <UtilHash.H>
#include <prdfDramRepairUsrData.H>
#include <iipServiceDataCollector.h>
#include <prdf_ras_services.H>
#ifdef __HOSTBOOT_MODULE
  #define htonl(foo) (foo) // no-op for HB
#endif

namespace PRDF
{

namespace CenMbaCaptureData
{

// ----------------------------------------------------------------------------

void addDramRepairsData( TARGETING::TargetHandle_t i_mbaTarget,
                         errlHndl_t o_errHdl )
{
    CaptureData cd;
    captureDramRepairsData( i_mbaTarget, cd);
    ErrDataService::AddCapData( cd, o_errHdl );
}

// ----------------------------------------------------------------------------

void addDramRepairsData( TARGETING::TargetHandle_t i_mbaTarget,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    CaptureData & cd = io_sc.service_data->GetCaptureData();
    captureDramRepairsData( i_mbaTarget, cd);
}

// ----------------------------------------------------------------------------

void captureDramRepairsData( TARGETING::TargetHandle_t i_mbaTarget,
                             CaptureData & o_cd )
{
    int32_t rc = SUCCESS;
    DramRepairMbaData mbaData;

    // Iterate all ranks to get DRAM repair data
    for(int rank = 0; rank < MAX_RANKS_PER_MBA ; rank++)
    {
        DramRepairRankData rankData;
        rankData.rank = rank;

        // Get DRAM Repair data

        rc = PlatServices::mssGetMarkStore( i_mbaTarget, rankData.rank,
                              rankData.chipMark, rankData.symbolMark );

        if (SUCCESS != rc)
        {
            PRDF_ERR("Failed to get markstore data");
            continue;
        }

        rc = PlatServices::mssGetSteerMux( i_mbaTarget, rankData.rank,
                                           rankData.port0Spare,
                                           rankData.port1Spare,
                                           rankData.eccSpare );

        if (SUCCESS != rc)
        {
            PRDF_ERR("Failed to get DRAM steer data");
            continue;
        }

        // Check id rank had some DRAM repair data
        if( rankData.valid() )
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
        o_cd.Add( i_mbaTarget, Util::hashString("MBA_DRAM_REPAIRS_DATA"),
                  dramRepairData );
    }
}

}  //end namespace MbaCaptureData

} // end namespace PRDF


