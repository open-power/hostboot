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

void addMbaFirRegs( ExtensibleChip * i_membChip, CaptureData & io_cd )
{
    #define PRDF_FUNC "[CenMbaCaptureData::addMbaFirRegs] "

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

        SCAN_COMM_REGISTER_CLASS * cs_reg, * re_reg, * firmsk_reg;
        cs_reg     = i_membChip->getRegister("MEM_CHIPLET_CS_FIR");
        re_reg     = i_membChip->getRegister("MEM_CHIPLET_RE_FIR");
        firmsk_reg = i_membChip->getRegister("MEM_CHIPLET_FIR_MASK");

        SCAN_COMM_REGISTER_CLASS * spa_reg, * spamsk_reg;
        spa_reg    = i_membChip->getRegister("MEM_CHIPLET_SPA");
        spamsk_reg = i_membChip->getRegister("MEM_CHIPLET_SPA_MASK");

        l_rc  = cs_reg->Read() | re_reg->Read() | firmsk_reg->Read();
        l_rc |= spa_reg->Read() | spamsk_reg->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC"Failed to read a MEM_CHIPLET register on "
                      "0x%08x", i_membChip->GetId() );
            break;
        }

        uint16_t cs_tmp  = cs_reg->GetBitFieldJustified(0,16);
        uint16_t re_tmp  = re_reg->GetBitFieldJustified(0,16) >> 2;
        uint16_t msk_tmp = firmsk_reg->GetBitFieldJustified(0,16);

        uint16_t csre_attns = (cs_tmp | re_tmp) & ~msk_tmp;

        uint16_t spa_attns = spa_reg->GetBitFieldJustified(0,16) &
                             ~spamsk_reg->GetBitFieldJustified(0,16);

        uint16_t mba_csre_msk[] = { 0x0648,   // bits 5, 6,  9, 12
                                    0x01a4 }; // bits 7, 8, 10, 13
        uint16_t mba_spa_msk[]  = { 0x8000,   // bit 0
                                    0x4000 }; // bit 1

        CenMembufDataBundle * membdb = getMembufDataBundle( i_membChip );

        for ( uint32_t i = 0; i < MAX_MBA_PER_MEMBUF; i++ )
        {
            if ( (0 != (csre_attns & mba_csre_msk[i])) ||
                 (0 != (spa_attns  & mba_spa_msk[i] )) )
            {
                ExtensibleChip * mbaChip = membdb->getMbaChip(i);
                if ( NULL == mbaChip )
                {
                    PRDF_ERR( PRDF_FUNC"MEM_CHIPLET registers indicated an "
                              "attention but no chip found: i_membChip=0x%08x "
                              "i=%d", i_membChip->GetId(), i );
                    continue;
                }

                mbaChip->CaptureErrorData(io_cd, Util::hashString("FirRegs") );
                mbaChip->CaptureErrorData(io_cd, Util::hashString("CerrRegs"));
            }
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
    int32_t rc = SUCCESS;
    DramRepairMbaData mbaData;

    // Iterate all ranks to get DRAM repair data
    for ( uint32_t r = 0; r < MASTER_RANKS_PER_MBA; r++ )
    {
        CenRank rank ( r );

        // Get chip/symbol marks
        CenMark mark;
        rc = PlatServices::mssGetMarkStore( i_mbaTrgt, rank, mark );
        if ( SUCCESS != rc )
        {
            PRDF_ERR("Failed to get markstore data");
            continue;
        }

        // Get DRAM spares
        CenSymbol sp0, sp1, ecc;
        rc = PlatServices::mssGetSteerMux( i_mbaTrgt, rank, sp0, sp1, ecc );
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
        PlatServices::isMembufOnDimm( i_mbaTrgt, isCentaurDimm );
        mbaData.header.isIsDimm = !isCentaurDimm;
        mbaData.header.isX4Dram = PlatServices::isDramWidthX4( i_mbaTrgt );
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
        io_cd.Add( i_mbaTrgt, Util::hashString("DRAM_REPAIRS_DATA"),
                   dramRepairData );
    }
}

//------------------------------------------------------------------------------

void captureDramRepairsVpd( TargetHandle_t i_mbaTrgt, CaptureData & io_cd )
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

        if ( SUCCESS != getBadDqBitmap(i_mbaTrgt, rank, bitmap, true) )
        {
            PRDF_ERR( PRDF_FUNC"getBadDqBitmap() failed: MBA=0x%08x rank=%d",
                      getHuid(i_mbaTrgt), r );
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
    io_cd.Add( i_mbaTrgt, Util::hashString("DRAM_REPAIRS_VPD"), bs );

    #undef PRDF_FUNC
}

}  //end namespace MbaCaptureData

} // end namespace PRDF


