/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/service/prdfPlatServices_common.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

/**
 * @file  prdfPlatServices_common.C
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly common between FSP and Hostboot. All
 * platform specific code should be in the respective FSP only or Hostboot only
 * files.
 */

#include <prdfPlatServices.H>

#include <prdfGlobal.H>
#include <prdfAssert.h>
#include <prdfTrace.H>
#include <prdfErrlUtil.H>

#include <prdfCenAddress.H>
#include <prdfCenDqBitmap.H>
#include <prdfCenMarkstore.H>

#include <dimmBadDqBitmapFuncs.H> // for dimm[S|G]etBadDqBitmap()

#include <io_read_erepair.H>
#include <io_power_down_lanes.H>
#include <io_clear_firs.H>
#include <erepairAccessorHwpFuncs.H>
#include <io_fir_isolation.H>
#include <fapiAttributeIds.H>

using namespace TARGETING;

//------------------------------------------------------------------------------

namespace PRDF
{
using namespace CEN_SYMBOL;
namespace PlatServices
{

//##############################################################################
//##                     Utility Functions (for this file only)
//##############################################################################

fapi::TargetType getFapiType( TARGETING::TargetHandle_t i_target )
{
    fapi::TargetType o_type = fapi::TARGET_TYPE_NONE;

    switch ( getTargetType(i_target) )
    {
        case TYPE_PROC:   o_type = fapi::TARGET_TYPE_PROC_CHIP;     break;
        case TYPE_EX:     o_type = fapi::TARGET_TYPE_EX_CHIPLET;    break;
        case TYPE_ABUS:   o_type = fapi::TARGET_TYPE_ABUS_ENDPOINT; break;
        case TYPE_XBUS:   o_type = fapi::TARGET_TYPE_XBUS_ENDPOINT; break;
        case TYPE_MCS:    o_type = fapi::TARGET_TYPE_MCS_CHIPLET;   break;
        case TYPE_MEMBUF: o_type = fapi::TARGET_TYPE_MEMBUF_CHIP;   break;
        case TYPE_MBA:    o_type = fapi::TARGET_TYPE_MBA_CHIPLET;   break;
        case TYPE_DIMM:   o_type = fapi::TARGET_TYPE_DIMM;          break;
        default: ;
    }

    return o_type;
}

//##############################################################################
//##                     System Level Utility Functions
//##############################################################################

void getECIDString( TargetHandle_t i_target, char * o_ecidStr )
{
    sprintf(o_ecidStr, "%s", "N/A");
    PRDF_ERR( "[PlatServices::getECIDString] Function not implemented yet" );
}

//------------------------------------------------------------------------------

fapi::Target getFapiTarget( TARGETING::TargetHandle_t i_target )
{
    return fapi::Target( getFapiType(i_target), i_target );
}


//##############################################################################
//##                       Processor specific functions
//##############################################################################

//##############################################################################
//##                       Lane Repair functions
//##############################################################################

int32_t readErepair(TargetHandle_t i_rxBusTgt,
                    std::vector<uint8_t> &o_rxFailLanes)
{
    int32_t o_rc = SUCCESS;
    errlHndl_t err = NULL;

    PRD_FAPI_TO_ERRL(err,
                     io_read_erepair,
                     getFapiTarget(i_rxBusTgt),
                     o_rxFailLanes);

    if(NULL != err)
    {
        PRDF_ERR( "[PlatServices::readErepair] HUID: 0x%08x io_read_erepair "
                  "failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}

int32_t clearIOFirs(TargetHandle_t i_rxBusTgt)
{
    int32_t o_rc = SUCCESS;
    errlHndl_t err = NULL;

    PRD_FAPI_TO_ERRL(err,
                     io_clear_firs,
                     getFapiTarget(i_rxBusTgt));

    if(NULL != err)
    {
        PRDF_ERR( "[PlatServices::clearIOFirs] HUID: 0x%08x io_clear_firs "
                  "failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}

int32_t powerDownLanes(TargetHandle_t i_rxBusTgt,
                       const std::vector<uint8_t> &i_rxFailLanes,
                       const std::vector<uint8_t> &i_txFailLanes)
{
    int32_t o_rc = SUCCESS;
    errlHndl_t err = NULL;

    PRD_FAPI_TO_ERRL(err,
                     io_power_down_lanes,
                     getFapiTarget(i_rxBusTgt),
                     i_txFailLanes,
                     i_rxFailLanes);

    if(NULL != err)
    {
        PRDF_ERR( "[PlatServices::powerDownLanes] HUID: 0x%08x "
                  "io_power_down_lanes failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    return o_rc;
}


int32_t getVpdFailedLanes(TargetHandle_t i_rxBusTgt,
                          std::vector<uint8_t> &o_rxFailLanes,
                          std::vector<uint8_t> &o_txFailLanes)
{
    int32_t o_rc = SUCCESS;
    errlHndl_t err = NULL;

    PRD_FAPI_TO_ERRL(err,
                     erepairGetFailedLanes,
                     getFapiTarget(i_rxBusTgt),
                     o_txFailLanes,
                     o_rxFailLanes);

    if(NULL != err)
    {
        PRDF_ERR( "[PlatServices::getVpdFailedLanes] HUID: 0x%08x "
                  "erepairGetFailedLanes failed",
                  getHuid(i_rxBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    return o_rc;
}

int32_t setVpdFailedLanes(TargetHandle_t i_rxBusTgt,
                          TargetHandle_t i_txBusTgt,
                          std::vector<uint8_t> &i_rxFailLanes,
                          bool & o_thrExceeded)
{
    int32_t o_rc = SUCCESS;
    errlHndl_t err = NULL;

    PRD_FAPI_TO_ERRL(err,
                    erepairSetFailedLanes,
                    getFapiTarget(i_txBusTgt),
                    getFapiTarget(i_rxBusTgt),
                    i_rxFailLanes,
                    o_thrExceeded);
    if(NULL != err)
    {
        PRDF_ERR( "[PlatServices::setVpdFailedLanes] rxHUID: 0x%08x "
                  "txHUID: 0x%08x erepairSetFailedLanes failed",
                  getHuid(i_rxBusTgt), getHuid(i_txBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    return o_rc;
}

int32_t erepairFirIsolation(TargetHandle_t i_rxBusTgt)
{
    #define PRDF_FUNC "[PlatServices::erepairFirIsolation] "

    errlHndl_t err = NULL;

    PRD_FAPI_TO_ERRL(err, io_fir_isolation, getFapiTarget(i_rxBusTgt));

    if(NULL != err)
    {
        PRDF_ERR( PRDF_FUNC"rxHUID: 0x%08x committing io_fir_isolation log",
                  getHuid(i_rxBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
    }

    // Return SUCCESS since we expect this procedure to generate an error
    return SUCCESS;

    #undef PRDF_FUNC
}

//##############################################################################
//##                        Memory specific functions
//##############################################################################

// Helper function for the for several other memory functions.
int32_t getMemAddrRange( TargetHandle_t i_mba, uint8_t i_mrank,
                         ecmdDataBufferBase & o_startAddr,
                         ecmdDataBufferBase & o_endAddr,
                         uint8_t i_srank = 0, bool i_slaveOnly = false )
{
    #define PRDF_FUNC "[PlatServices::getMemAddrRange] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Check parameters.
        if ( TYPE_MBA != getTargetType(i_mba) )
        {
            PRDF_ERR( PRDF_FUNC"The given target is not TYPE_MBA" );
            o_rc = FAIL; break;
        }

        if ( (MSS_ALL_RANKS != i_mrank && MASTER_RANKS_PER_MBA <= i_mrank) ||
             (SLAVE_RANKS_PER_MASTER_RANK <= i_srank) )
        {
            PRDF_ERR( PRDF_FUNC"The given rank is not valid" );
            o_rc = FAIL; break;
        }

        errlHndl_t errl = NULL;

        if ( i_slaveOnly )
        {
            // TODO: RTC 82157 Use new interface when available, for now use
            //       current interface.
//          PRD_FAPI_TO_ERRL( errl, mss_get_address_range, getFapiTarget(i_mba),
//                            i_mrank, i_srank, o_startAddr, o_endAddr );
            PRD_FAPI_TO_ERRL( errl, mss_get_address_range, getFapiTarget(i_mba),
                              i_mrank, o_startAddr, o_endAddr );
        }
        else
        {
            PRD_FAPI_TO_ERRL( errl, mss_get_address_range, getFapiTarget(i_mba),
                              i_mrank, o_startAddr, o_endAddr );
        }

        if ( NULL != errl )
        {
            PRDF_ERR( PRDF_FUNC"mss_get_address_range() failed" );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

        // Verify addresses are of the valid register size.
        if ( 64 != o_startAddr.getBitLength() ||
             64 != o_endAddr.getBitLength() )
        {
            PRDF_ERR( PRDF_FUNC"Addresses returned from "
                      "mss_get_address_range() are not 64-bit" );
            o_rc = FAIL; break;
        }

    } while (0);

    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_mba=0x%08x i_mrank=%d i_srank=%d "
                  "i_slaveOnly=%s", getHuid(i_mba), i_mrank, i_srank,
                  i_slaveOnly ? "true" : "false" );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getBadDqBitmap( TargetHandle_t i_mba, const CenRank & i_rank,
                        CenDqBitmap & o_bitmap, bool i_allowNoDimm )
{
    #define PRDF_FUNC "[PlatServices::getBadDqBitmap] "

    int32_t o_rc = SUCCESS;

    uint8_t data[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE];

    for ( int32_t ps = 0; ps < PORT_SLCT_PER_MBA; ps++ )
    {
        fapi::ReturnCode l_rc = dimmGetBadDqBitmap( getFapiTarget(i_mba),
                                                    ps, i_rank.getDimmSlct(),
                                                    i_rank.getRankSlct(),
                                                    data[ps] );

        if ( i_allowNoDimm && (fapi::RC_BAD_DQ_DIMM_NOT_FOUND == l_rc) )
        {
            memset( &data[ps], 0x00, DIMM_DQ_RANK_BITMAP_SIZE );
        }
        else
        {
            errlHndl_t errl = fapi::fapiRcToErrl(l_rc);
            if ( NULL != errl )
            {
                PRDF_ERR( PRDF_FUNC"dimmGetBadDqBitmap() failed: MBA=0x%08x "
                          "ps=%d ds=%d rs=%d", getHuid(i_mba), ps,
                          i_rank.getDimmSlct(), i_rank.getRankSlct() );
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                o_rc = FAIL; break;
            }
        }
    }

    if ( SUCCESS == o_rc )
    {
        o_bitmap = CenDqBitmap ( i_mba, i_rank, data );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t setBadDqBitmap( TargetHandle_t i_mba, const CenRank & i_rank,
                        const CenDqBitmap & i_bitmap )
{
    #define PRDF_FUNC "[PlatServices::setBadDqBitmap] "

    int32_t o_rc = SUCCESS;

    if ( !areDramRepairsDisabled() )
    {
        const uint8_t (&data)[PORT_SLCT_PER_MBA][DIMM_DQ_RANK_BITMAP_SIZE]
                                                        = i_bitmap.getData();

        for ( int32_t ps = 0; ps < PORT_SLCT_PER_MBA; ps++ )
        {
            errlHndl_t errl = NULL;
            PRD_FAPI_TO_ERRL( errl, dimmSetBadDqBitmap, getFapiTarget(i_mba),
                              ps, i_rank.getDimmSlct(), i_rank.getRankSlct(),
                              data[ps] );
            if ( NULL != errl )
            {
                PRDF_ERR( PRDF_FUNC"dimmSetBadDqBitmap() failed: MBA=0x%08x "
                          "ps=%d ds=%d rs=%d", getHuid(i_mba), ps,
                          i_rank.getDimmSlct(), i_rank.getRankSlct() );
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
            }
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t mssGetMarkStore( TargetHandle_t i_mba, const CenRank & i_rank,
                         CenMark & o_mark )
{
    #define PRDF_FUNC "[PlatServices::mssGetMarkStore] "

    int32_t o_rc = SUCCESS;

    do
    {
        errlHndl_t errl = NULL;
        uint8_t symbolMark, chipMark;
        PRD_FAPI_TO_ERRL( errl, mss_get_mark_store, getFapiTarget(i_mba),
                          i_rank.getMaster(), symbolMark, chipMark );

        if ( NULL != errl )
        {
            PRDF_ERR( PRDF_FUNC"mss_get_mark_store() failed. HUID: 0x%08x "
                      "rank: %d", getHuid(i_mba), i_rank.getMaster() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }

        CenSymbol sm = CenSymbol::fromSymbol( i_mba, i_rank, symbolMark );
        CenSymbol cm = CenSymbol::fromSymbol( i_mba, i_rank, chipMark   );

        // Check if the chip or symbol mark are on any of the spares.
        CenSymbol sp0, sp1, ecc;
        o_rc = mssGetSteerMux( i_mba, i_rank, sp0, sp1, ecc );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mssGetSteerMux() failed. HUID: 0x%08x "
                      "rank: %d", getHuid(i_mba), i_rank.getMaster() );
            break;
        }

        if ( sp0.isValid() )
        {
            if ( sp0.getDram() == sm.getDram() ) sm.setDramSpared();
            if ( sp0.getDram() == cm.getDram() ) cm.setDramSpared();
        }

        if ( sp1.isValid() )
        {
            if ( sp1.getDram() == sm.getDram() ) sm.setDramSpared();
            if ( sp1.getDram() == cm.getDram() ) cm.setDramSpared();
        }

        if ( ecc.isValid() )
        {
            if ( ecc.getDram() == sm.getDram() ) sm.setEccSpared();
            if ( ecc.getDram() == cm.getDram() ) cm.setEccSpared();
        }

        o_mark = CenMark( sm, cm );

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t mssSetMarkStore( TargetHandle_t i_mba, const CenRank & i_rank,
                         CenMark & io_mark, bool & o_writeBlocked,
                         bool i_allowWriteBlocked )
{
    #define PRDF_FUNC "[PlatServices::mssSetMarkStore] "

    int32_t o_rc = SUCCESS;
    errlHndl_t errl = NULL;
    o_writeBlocked = false;

    uint8_t sm = io_mark.getSM().isValid() ? io_mark.getSM().getSymbol()
                                           : MSS_INVALID_SYMBOL;
    uint8_t cm = io_mark.getCM().isValid() ? io_mark.getCM().getDramSymbol()
                                           : MSS_INVALID_SYMBOL;

    fapi::ReturnCode l_rc = mss_put_mark_store( getFapiTarget(i_mba),
                                                i_rank.getMaster(), sm, cm );

    if ( i_allowWriteBlocked &&
         fapi::RC_MSS_MAINT_MARKSTORE_WRITE_BLOCKED == l_rc )
    {
        o_writeBlocked = true;

        // Read hardware and get the new chip mark.
        CenMark hwMark;
        o_rc = mssGetMarkStore( i_mba, i_rank, hwMark );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC"mssGetMarkStore() failed." );
        }
        else
        {
            // Update io_mark with the new chip mark.
            io_mark.setCM( hwMark.getCM() );
        }
    }
    else
    {
        errl = fapi::fapiRcToErrl(l_rc);
        if ( NULL != errl )
        {
            PRDF_ERR( PRDF_FUNC"mss_put_mark_store() failed. HUID: 0x%08x "
                      "rank: %d sm: %d cm: %d", getHuid(i_mba),
                      i_rank.getMaster(), sm, cm );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t mssGetSteerMux( TargetHandle_t i_mba, const CenRank & i_rank,
                        CenSymbol & o_port0Spare, CenSymbol & o_port1Spare,
                        CenSymbol & o_eccSpare )
{
    int32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;

    uint8_t port0Spare, port1Spare, eccSpare;
    PRD_FAPI_TO_ERRL( errl, mss_check_steering, getFapiTarget(i_mba),
                      i_rank.getMaster(), port0Spare, port1Spare, eccSpare );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssGetSteerMux] mss_check_steering() "
                  "failed. HUID: 0x%08x rank: %d",
                  getHuid(i_mba), i_rank.getMaster() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    else
    {
        o_port0Spare = CenSymbol::fromSymbol( i_mba, i_rank, port0Spare );
        o_port1Spare = CenSymbol::fromSymbol( i_mba, i_rank, port1Spare );
        o_eccSpare   = CenSymbol::fromSymbol( i_mba, i_rank, eccSpare   );

        if ( o_port0Spare.isValid() ) o_port0Spare.setDramSpared();
        if ( o_port1Spare.isValid() ) o_port1Spare.setDramSpared();
        if ( o_eccSpare.isValid()   ) o_eccSpare.setEccSpared();
    }

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t mssSetSteerMux( TargetHandle_t i_mba, const CenRank & i_rank,
                        const CenSymbol & i_symbol, bool i_x4EccSpare )
{
    int32_t o_rc = SUCCESS;

    errlHndl_t errl = NULL;

    PRD_FAPI_TO_ERRL( errl, mss_do_steering, getFapiTarget(i_mba),
                      i_rank.getMaster(), i_symbol.getDramSymbol(),
                      i_x4EccSpare );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssSetSteerMux] mss_do_steering "
                  "failed. HUID: 0x%08x rank: %d symbol: %d eccSpare: %c",
                  getHuid(i_mba), i_rank.getMaster(), i_symbol.getSymbol(),
                  i_x4EccSpare ? 'T' : 'F' );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t getMemAddrRange( TargetHandle_t i_mba, CenAddr & o_startAddr,
                         CenAddr & o_endAddr )
{
    #define PRDF_FUNC "[PlatServices::getMemAddrRange] "

    ecmdDataBufferBase startAddr(64), endAddr(64);
    int32_t o_rc = getMemAddrRange( i_mba, MSS_ALL_RANKS, startAddr, endAddr );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_mba=0x%08x", getHuid(i_mba) );
    }
    else
    {
        o_startAddr = CenAddr::fromMaintStartAddr( startAddr.getDoubleWord(0) );
        o_endAddr   = CenAddr::fromMaintEndAddr(   endAddr.getDoubleWord(0)   );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getMemAddrRange( TargetHandle_t i_mba, const CenRank & i_rank,
                         CenAddr & o_startAddr, CenAddr & o_endAddr,
                         bool i_slaveOnly )
{
    #define PRDF_FUNC "[PlatServices::getMemAddrRange] "

    ecmdDataBufferBase startAddr(64), endAddr(64);
    int32_t o_rc = getMemAddrRange( i_mba, i_rank.getMaster(),
                                    startAddr, endAddr,
                                    i_rank.getSlave(), i_slaveOnly );
    if ( SUCCESS != o_rc )
    {
        PRDF_ERR( PRDF_FUNC"Failed: i_mba=0x%08x i_rank=M%dS%d i_slaveOnly=%s",
                  getHuid(i_mba), i_rank.getMaster(), i_rank.getSlave(),
                  i_slaveOnly ? "true" : "false" );
    }
    else
    {
        o_startAddr = CenAddr::fromMaintStartAddr( startAddr.getDoubleWord(0) );
        o_endAddr   = CenAddr::fromMaintEndAddr(   endAddr.getDoubleWord(0)   );
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getDimmSpareConfig( TargetHandle_t i_mba, CenRank i_rank,
                            uint8_t i_ps, uint8_t & o_spareConfig )
{
    #define PRDF_FUNC "[PlatServices::getDimmSpareConfig] "
    int32_t o_rc = SUCCESS;

    using namespace fapi;

    ATTR_VPD_DIMM_SPARE_Type attr;
    o_spareConfig = ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE;
    do
    {
        if( TYPE_MBA != getTargetType( i_mba ) )
        {
            PRDF_ERR( PRDF_FUNC"Invalid Target:0x%08X", getHuid( i_mba ) );
            o_rc = FAIL; break;
        }

        if ( MAX_PORT_PER_MBA <= i_ps )
        {
            PRDF_ERR( PRDF_FUNC"Invalid parameters i_ps:%u", i_ps );
            o_rc = FAIL; break;
        }

        fapi::Target fapiMba = getFapiTarget(i_mba);
        ReturnCode l_rc = FAPI_ATTR_GET( ATTR_VPD_DIMM_SPARE, &fapiMba, attr );
        errlHndl_t errl = fapi::fapiRcToErrl(l_rc);
        if ( NULL != errl )
        {
            PRDF_ERR( PRDF_FUNC"Failed to get ATTR_VPD_DIMM_SPARE for Target:"
                      "0x%08X", getHuid( i_mba ) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }
        o_spareConfig = attr[i_ps][i_rank.getDimmSlct()][i_rank.getRankSlct()];

        // Check for valid values
        // For X4 DRAM, we can not have full byte as spare config. Also for X8
        // DRAM we can not have nibble as spare.

        if( ENUM_ATTR_VPD_DIMM_SPARE_NO_SPARE == o_spareConfig) break;

        bool isFullByte = ( ENUM_ATTR_VPD_DIMM_SPARE_FULL_BYTE ==
                                                            o_spareConfig );
        bool isX4Dram = isDramWidthX4(i_mba);

        if ( ( isX4Dram && isFullByte ) || ( !isX4Dram && !isFullByte ) )
        {
            PRDF_ERR( PRDF_FUNC"Invalid Configuration: o_spareConfig:%u",
                      o_spareConfig );
            o_rc = FAIL; break;
        }

    }while(0);

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getMemBufRawCardType( TargetHandle_t i_mba,
                              WiringType & o_cardType )
{
    #define PRDF_FUNC "[PlatServices::getMemBufRawCardType] "

    o_cardType = WIRING_INVALID;
    uint8_t l_cardType = WIRING_INVALID;
    int32_t o_rc = FAIL;

    do
    {
        if( TYPE_MBA != getTargetType( i_mba ) )
        {
            PRDF_ERR( PRDF_FUNC" Invalid target 0x%08x",getHuid( i_mba ) );
            break;
        }

        TargetHandleList l_dimmList = getConnected( i_mba, TYPE_DIMM );

        if( 0 == l_dimmList.size() )
        {
            PRDF_ERR( PRDF_FUNC " No DIMM connected with mba 0x%08x",
                      getHuid( i_mba ) );
            break;
        }

        errlHndl_t errl = NULL;
        fapi::Target fapiDimm = getFapiTarget( l_dimmList[0] );

        PRD_FAPI_TO_ERRL( errl,
                          fapi::platAttrSvc::fapiPlatGetSpdModspecComRefRawCard,
                          &fapiDimm,
                          l_cardType );

        if( NULL != errl )
        {
            PRDF_ERR( PRDF_FUNC" fapiPlatGetSpdModspecComRefRawCard failed for"
                      "DIMM 0x%08X", getHuid( l_dimmList[0] ) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            break;
        }

        switch( l_cardType )
        {
            case ENUM_ATTR_SPD_MODSPEC_COM_REF_RAW_CARD_A :
                o_cardType = CEN_TYPE_A;
                break;

            case ENUM_ATTR_SPD_MODSPEC_COM_REF_RAW_CARD_B :
                o_cardType = CEN_TYPE_B;
                break;

            case ENUM_ATTR_SPD_MODSPEC_COM_REF_RAW_CARD_D:
                o_cardType = CEN_TYPE_D;
                break;

            default:
                o_cardType = WIRING_INVALID;
                break;
        }

    }while(0);

    if( WIRING_INVALID != o_cardType )
    {
        o_rc = SUCCESS;
    }

    return o_rc;
    #undef PRDF_FUNC
}


//------------------------------------------------------------------------------

/* TODO - Get the type of the card a DIMM is plugged into. This is needed for
          the DRAM site locations for IS DIMMs. Should be able to get this from
          an attribute but doesn't look like this is available yet.
getDimmPlugCardType()
{
}
*/

//##############################################################################
//##                    Maintance Command class wrapper
//##############################################################################

mss_MaintCmdWrapper::mss_MaintCmdWrapper( mss_MaintCmd * i_maintCmd ) :
    iv_cmd(i_maintCmd)
{}

//------------------------------------------------------------------------------

mss_MaintCmdWrapper::~mss_MaintCmdWrapper()
{
    delete iv_cmd;
}

//------------------------------------------------------------------------------

int32_t mss_MaintCmdWrapper::setupAndExecuteCmd()
{
    #define PRDF_FUNC "[mss_MaintCmdWrapper::setupAndExecuteCmd] "

    int32_t o_rc = SUCCESS;

    fapi::ReturnCode l_rc = iv_cmd->setupAndExecuteCmd();
    errlHndl_t errl = fapi::fapiRcToErrl( l_rc );
    if ( NULL != errl )
    {
        PRDF_GET_REASONCODE( errl, o_rc );
        PRDF_ERR( PRDF_FUNC"setupAndExecuteCmd() failed: rc=0x%x", o_rc );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t mss_MaintCmdWrapper::stopCmd()
{
    #define PRDF_FUNC "[mss_MaintCmdWrapper::stopCmd] "

    int32_t o_rc = SUCCESS;

    fapi::ReturnCode l_rc = iv_cmd->stopCmd();
    errlHndl_t errl = fapi::fapiRcToErrl( l_rc );
    if ( NULL != errl )
    {
        PRDF_GET_REASONCODE( errl, o_rc );
        PRDF_ERR( PRDF_FUNC"stopCmd() failed: rc=0x%x", o_rc );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t mss_MaintCmdWrapper::cleanupCmd()
{
    #define PRDF_FUNC "[mss_MaintCmdWrapper::cleanupCmd] "

    int32_t o_rc = SUCCESS;

    fapi::ReturnCode l_rc = iv_cmd->cleanupCmd();
    errlHndl_t errl = fapi::fapiRcToErrl( l_rc );
    if ( NULL != errl )
    {
        PRDF_GET_REASONCODE( errl, o_rc );
        PRDF_ERR( PRDF_FUNC"cleanupCmd() failed: rc=0x%x", o_rc );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

// Helper function for the other createMssCmd() functions.
mss_MaintCmdWrapper * createMssCmd( mss_MaintCmdWrapper::CmdType i_cmdType,
                                    TargetHandle_t i_mba, uint32_t i_stopCond,
                                    mss_MaintCmd::TimeBaseSpeed i_cmdSpeed,
                                    ecmdDataBufferBase i_startAddr,
                                    ecmdDataBufferBase i_endAddr )
{
    #define PRDF_FUNC "[PlatServices::getMssCmd] "

    mss_MaintCmdWrapper * o_cmd = NULL;

    mss_MaintCmd * cmd = NULL;

    switch ( i_cmdType )
    {
        case mss_MaintCmdWrapper::TIMEBASE_SCRUB:
            cmd = new mss_TimeBaseScrub( getFapiTarget(i_mba), i_startAddr,
                                         i_endAddr, i_cmdSpeed, i_stopCond,
                                         false );
            break;
        case mss_MaintCmdWrapper::TIMEBASE_STEER_CLEANUP:
            cmd = new mss_TimeBaseSteerCleanup( getFapiTarget(i_mba),
                                                i_startAddr, i_endAddr,
                                                i_cmdSpeed, i_stopCond, false );
            break;
        case mss_MaintCmdWrapper::SUPERFAST_READ:
            cmd = new mss_SuperFastRead( getFapiTarget(i_mba), i_startAddr,
                                         i_endAddr, i_stopCond, false );
            break;
        default:
            PRDF_ERR( PRDF_FUNC"Unsupported command type: 0x%x", i_cmdType );
    }

    if ( NULL != cmd )
        o_cmd = new mss_MaintCmdWrapper(cmd);

    return o_cmd;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

mss_MaintCmdWrapper * createMssCmd( mss_MaintCmdWrapper::CmdType i_cmdType,
                                    TargetHandle_t i_mba,
                                    const CenRank & i_rank, uint32_t i_stopCond,
                                    mss_MaintCmd::TimeBaseSpeed i_cmdSpeed,
                                    uint32_t i_flags,
                                    const CenAddr * i_sAddrOverride )
{
    mss_MaintCmdWrapper * o_cmd = NULL;

    bool slaveOnly = ( 0 != (i_flags & mss_MaintCmdWrapper::SLAVE_RANK_ONLY) );
    bool allMemory = ( 0 != (i_flags & mss_MaintCmdWrapper::END_OF_MEMORY  ) );

    do
    {

        int32_t l_rc = SUCCESS;

        // Get the address range of i_rank.
        ecmdDataBufferBase sAddr(64), eAddr(64);
        l_rc = getMemAddrRange( i_mba, i_rank.getMaster(), sAddr, eAddr,
                                i_rank.getSlave(), slaveOnly );
        if ( SUCCESS != l_rc ) break;

        // Override the start address, if needed.
        if ( NULL != i_sAddrOverride )
        {
            sAddr.setDoubleWord( 0, i_sAddrOverride->toReadAddr() );
        }

        // Get the last address in memory, if needed.
        if ( allMemory )
        {
            ecmdDataBufferBase junk(64);
            l_rc = getMemAddrRange( i_mba, MSS_ALL_RANKS, junk, eAddr );
            if ( SUCCESS != l_rc ) break;
        }

        // Create the command
        o_cmd = createMssCmd( i_cmdType, i_mba, i_stopCond, i_cmdSpeed,
                              sAddr, eAddr );

    } while (0);

    return o_cmd;
}

} // end namespace PlatServices

} // end namespace PRDF

