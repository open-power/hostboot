/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPlatServices_common.C $     */
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
#include <target_types.H>

#ifdef __HOSTBOOT_MODULE
#include <prdfParserUtils.H>
#include <dimmBadDqBitmapFuncs.H>
#include <exp_maint_cmds.H>

#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>
#include <plat_hwp_invoker.H>
#endif


#if !defined(__HOSTBOOT_MODULE) // FSP only
  #include <services/todservice/hwsvTodControls.H>
#elif defined(__HOSTBOOT_RUNTIME) // HBRT only
  #include <rt_todintf.H>
#endif

using namespace TARGETING;

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

/*
IMPORTANT - getFapiTarget NO LONGER IN USE
Because of the new templatized format of fapi Targets with the changes in
fapi2 we will no longer be able to dynamically convert a TARGETING::Target to
a fapi2::Target. Fapi TargetTypes must be determined at compile time, as such,
we will need to use the fapi2::TargetType constants in declarations of fapi
Targets. For example:

Where we previously would have had:
    fapi::Target fapiProc = getFapiTarget(i_proc);

We would now need:
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> fapiProc(i_proc);

If you would like to take a look at the changes to fapi Targets, their class
definition is located in src/hwsv/server/hwpf2/fapi2/fapi2_target.H
Note: the fapi2::TargetType enum is declared in
src/hwsv/server/hwpf2/fapi2/target_types.H for a list of all the TargetTypes
*/

//##############################################################################
//##                        Memory specific functions
//##############################################################################

template<>
uint32_t getBadDqBitmap<TYPE_MEM_PORT>( TargetHandle_t i_trgt,
    const MemRank & i_rank, MemDqBitmap & o_bitmap )
{
    #define PRDF_FUNC "[PlatServices::getBadDqBitmap] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    errlHndl_t errl = nullptr;
    uint8_t data[DQ_BITMAP::BITMAP_SIZE];

    fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> l_fapiTrgt( i_trgt );
    uint8_t ps = i_trgt->getAttr<ATTR_REL_POS>();

    FAPI_INVOKE_HWP( errl, p10DimmGetBadDqBitmap, l_fapiTrgt,
                     i_rank.getDimmSlct(), i_rank.getRankSlct(),
                     data, ps );

    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "p10DimmGetBadDqBitmap() failed: i_trgt=0x%08x "
                  "ps=%d ds=%d rs=%d", getHuid(i_trgt), ps,
                  i_rank.getDimmSlct(), i_rank.getRankSlct() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    if ( SUCCESS == o_rc )
    {
        o_bitmap = MemDqBitmap( i_trgt, i_rank, data );
    }

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}


//------------------------------------------------------------------------------

template<>
uint32_t setBadDqBitmap<TYPE_MEM_PORT>( TargetHandle_t i_trgt,
    const MemRank & i_rank, const MemDqBitmap & i_bitmap )
{
    #define PRDF_FUNC "[PlatServices::setBadDqBitmap] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    if ( !areDramRepairsDisabled() )
    {
        uint8_t data[DQ_BITMAP::BITMAP_SIZE];
        memcpy(data, i_bitmap.getData(), sizeof(data));

        errlHndl_t errl = nullptr;

        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> l_fapiTrgt( i_trgt );
        uint8_t ps = i_trgt->getAttr<ATTR_REL_POS>();

        FAPI_INVOKE_HWP( errl, p10DimmSetBadDqBitmap, l_fapiTrgt,
                         i_rank.getDimmSlct(), i_rank.getRankSlct(),
                         data, ps );

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "p10DimmSetBadDqBitmap() failed: "
                      "i_trgt=0x%08x ps=%d ds=%d rs=%d", getHuid(i_trgt),
                      ps, i_rank.getDimmSlct(), i_rank.getRankSlct() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }
    }

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t clearBadDqBitmap<TYPE_MEM_PORT>( TargetHandle_t i_trgt,
                                          const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::clearBadDqBitmap] "

    uint32_t o_rc = SUCCESS;

    do
    {
        MemDqBitmap dqBitmap;
        o_rc = getBadDqBitmap<TYPE_MEM_PORT>( i_trgt, i_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x, 0x%02x) failed.",
                      getHuid(i_trgt), i_rank.getKey() );
            break;
        }

        dqBitmap.clearBitmap();

        o_rc = setBadDqBitmap<TYPE_MEM_PORT>( i_trgt, i_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "setBadDqBitmap(0x%08x, 0x%02x) failed.",
                      getHuid(i_trgt), i_rank.getKey() );
            break;
        }
    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}


//------------------------------------------------------------------------------

template<>
void getDimmDqAttr<TYPE_MEM_PORT>( TargetHandle_t i_target,
                                   uint8_t (&o_dqMapPtr)[DQS_PER_DIMM] )
{
    #define PRDF_FUNC "[PlatServices::getDimmDqAttr<TYPE_MEM_PORT>] "

    PRDF_ASSERT( TYPE_MEM_PORT == getTargetType(i_target) );

    uint8_t tmpData[DQS_PER_DIMM];

    if ( !i_target->tryGetAttr<ATTR_MEM_VPD_DQ_MAP>(tmpData) )
    {
        PRDF_ERR( PRDF_FUNC "Failed to get ATTR_MEM_VPD_DQ_MAP" );
        PRDF_ASSERT( false );
    }

    memcpy( &o_dqMapPtr[0], &tmpData[0], DQS_PER_DIMM );

    #undef PRDF_FUNC
} // end function getDimmDqAttr

//------------------------------------------------------------------------------

template<>
int32_t mssGetSteerMux<TYPE_MEM_PORT>( TargetHandle_t i_memport,
                                       const MemRank & i_rank,
                                       MemSymbol & o_spare0,
                                       MemSymbol & o_spare1 )
{
    int32_t o_rc = SUCCESS;


    // called by FSP code so can't just move to hostboot side
#ifdef __HOSTBOOT_MODULE
    errlHndl_t errl = nullptr;

    uint8_t spare0, spare1;

    fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> fapiPort(i_memport);

    TargetHandle_t ocmb = getConnectedParent(i_memport, TYPE_OCMB_CHIP);
    if (isOdysseyOcmb(ocmb))
    {
        FAPI_INVOKE_HWP( errl, ody_check_steering, fapiPort,
                         i_rank.getMaster(), spare0, spare1 );
    }
    else
    {
        FAPI_INVOKE_HWP( errl, exp_check_steering, fapiPort,
                         i_rank.getMaster(), spare0, spare1 );
    }

    if ( nullptr != errl )
    {
        PRDF_ERR( "[PlatServices::mssGetSteerMux] check_steering() "
                  "failed. HUID: 0x%08x rank: %d",
                  getHuid(i_memport), i_rank.getMaster() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    else
    {
        o_spare0 = MemSymbol::fromSparedSymbol( i_memport, i_rank, spare0,
                                                true, false );
        o_spare1 = MemSymbol::fromSparedSymbol( i_memport, i_rank, spare1,
                                                false, true );
    }
#endif

    return o_rc;
}

//------------------------------------------------------------------------------

template<>
int32_t mssSetSteerMux<TYPE_MEM_PORT>( TargetHandle_t i_memport,
    const MemRank & i_rank, const MemSymbol & i_symbol )
{
    int32_t o_rc = SUCCESS;

#ifdef __HOSTBOOT_MODULE
    errlHndl_t errl = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> fapiPort(i_memport);

    TargetHandle_t dimm = getConnectedChild( i_memport, TYPE_DIMM,
                                             i_rank.getDimmSlct() );
    uint8_t l_dramSymbol = PARSERUTILS::dram2Symbol<TYPE_OCMB_CHIP>(
                                                     i_symbol.getDram(),
                                                     isDramWidthX4(dimm) );

    TargetHandle_t ocmb = getConnectedParent(i_memport, TYPE_OCMB_CHIP);
    if (isOdysseyOcmb(ocmb))
    {
        FAPI_INVOKE_HWP( errl, ody_do_steering, fapiPort,
                         i_rank.getMaster(), l_dramSymbol );
    }
    else
    {
        FAPI_INVOKE_HWP( errl, exp_do_steering, fapiPort,
                         i_rank.getMaster(), l_dramSymbol );
    }

    if ( nullptr != errl )
    {
        PRDF_ERR( "[PlatServices::mssSetSteerMux] do_steering() "
                  "failed. HUID: 0x%08x, rank: %d, symbol: %d",
                  getHuid(i_memport), i_rank.getMaster(), l_dramSymbol );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
#endif

    return o_rc;
}

//------------------------------------------------------------------------------

template<>
int32_t mssUndoSteerMux<TYPE_MEM_PORT>( TargetHandle_t i_memport,
    const MemRank & i_rank, const size_t i_spare )
{
    int32_t o_rc = SUCCESS;

#ifdef __HOSTBOOT_MODULE
    errlHndl_t errl = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> fapiPort(i_memport);

    TargetHandle_t ocmb = getConnectedParent(i_memport, TYPE_OCMB_CHIP);
    if (isOdysseyOcmb(ocmb))
    {
        FAPI_INVOKE_HWP( errl, ody_unspare, fapiPort,
                         i_rank.getMaster(), i_spare );
    }
    else
    {
        FAPI_INVOKE_HWP( errl, exp_unspare, fapiPort,
                         i_rank.getMaster(), i_spare );
    }

    if ( nullptr != errl )
    {
        PRDF_ERR( "[PlatServices::mssUndoSteerMux] unspare() "
                  "failed. HUID: 0x%08x, rank: %d, spare: %d",
                  getHuid(i_memport), i_rank.getMaster(), i_spare );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
#endif

    return o_rc;
}

//------------------------------------------------------------------------------

template<>
int32_t getDimmSpareConfig<TYPE_MEM_PORT>( TargetHandle_t i_memPort,
                        MemRank i_rank, uint8_t i_ps, uint8_t & o_spareConfig )
{
    #define PRDF_FUNC "[PlatServices::getDimmSpareConfig] "
    int32_t o_rc = SUCCESS;

#ifdef __HOSTBOOT_MODULE
    using namespace fapi2;

    ATTR_MEM_EFF_DIMM_SPARE_Type attr;
    o_spareConfig = fapi2::ENUM_ATTR_MEM_EFF_DIMM_SPARE_NO_SPARE;
    do
    {
        if( TYPE_MEM_PORT != getTargetType( i_memPort ) )
        {
            PRDF_ERR( PRDF_FUNC "Invalid Target:0x%08X", getHuid( i_memPort ) );
            o_rc = FAIL; break;
        }

        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> fapiPort(i_memPort);
        ReturnCode l_rc = FAPI_ATTR_GET( fapi2::ATTR_MEM_EFF_DIMM_SPARE,
                                         fapiPort, attr );
        errlHndl_t errl = fapi2::rcToErrl(l_rc);
        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get ATTR_MEM_EFF_DIMM_SPARE for "
                      "Target: 0x%08X", getHuid( i_memPort ) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }
        o_spareConfig = attr[i_rank.getDimmSlct()][i_rank.getRankSlct()];

    }while(0);
#endif

    return o_rc;
    #undef PRDF_FUNC
}

template<>
int32_t getDimmSpareConfig<TYPE_OCMB_CHIP>( TargetHandle_t i_ocmb,
                        MemRank i_rank, uint8_t i_ps, uint8_t & o_spareConfig )
{
    PRDF_ASSERT( nullptr != i_ocmb );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_ocmb) );

    TargetHandle_t memPort = getConnectedChild( i_ocmb, TYPE_MEM_PORT, i_ps );

    // If the returned MEM_PORT is null, just return.
    if (nullptr == memPort)
    {
        PRDF_ERR("getDimmSpareConfig: Could not get child MEM_PORT %d from "
                 "0x%08x", i_ps, getHuid(i_ocmb));
        return FAIL;
    }

    return getDimmSpareConfig<TYPE_MEM_PORT>( memPort, i_rank, i_ps,
                                              o_spareConfig );
}

//------------------------------------------------------------------------------

template<>
uint32_t isDramSparingEnabled<TYPE_MEM_PORT>( TARGETING::TargetHandle_t i_trgt,
                                              MemRank i_rank, uint8_t i_ps,
                                              bool & o_spareEnable )
{
    #define PRDF_FUNC "[PlatServices::isDramSparingEnabled<TYPE_MEM_PORT>] "

    uint32_t o_rc = SUCCESS;
    o_spareEnable = false;

    do
    {
        // Check for any DRAM spares.
        uint8_t cnfg = TARGETING::MEM_EFF_DIMM_SPARE_NO_SPARE;
        o_rc = getDimmSpareConfig<TYPE_MEM_PORT>( i_trgt, i_rank, i_ps, cnfg );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getDimmSpareConfig(0x%08x,0x%02x,%d) "
                      "failed", getHuid(i_trgt), i_rank.getKey(), i_ps );
            break;
        }
        o_spareEnable = (TARGETING::MEM_EFF_DIMM_SPARE_NO_SPARE != cnfg);

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t isDramSparingEnabled<TYPE_OCMB_CHIP>( TARGETING::TargetHandle_t i_trgt,
                                               MemRank i_rank, uint8_t i_ps,
                                               bool & o_spareEnable )
{
    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_trgt) );

    TargetHandle_t memPort = getConnectedChild( i_trgt, TYPE_MEM_PORT, i_ps );

    // If the returned MEM_PORT is null, just return.
    if (nullptr == memPort)
    {
        PRDF_ERR("isDramSparingEnabled: Could not get child MEM_PORT %d from "
                 "0x%08x", i_ps, getHuid(i_trgt));
        return FAIL;
    }

    return isDramSparingEnabled<TYPE_MEM_PORT>( memPort, i_rank, i_ps,
                                                o_spareEnable );
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t isSpareAvailable( TARGETING::TargetHandle_t i_trgt, MemRank i_rank,
                           bool & o_spAvail )
{
    #define PRDF_FUNC "[PlatServices::isSpareAvailable] "

    uint32_t o_rc = SUCCESS;

    o_spAvail = false;

    do
    {
        uint8_t ps = i_trgt->getAttr<ATTR_REL_POS>();

        bool dramSparingEnabled = false;
        o_rc = isDramSparingEnabled<T>( i_trgt, i_rank, ps,
                                        dramSparingEnabled );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isDramSparingEnabled() failed." );
            break;
        }

        // Break out if dram sparing isn't enabled
        if ( !dramSparingEnabled ) break;

        // Get the current spares in hardware
        MemSymbol sp0, sp1;
        o_rc = mssGetSteerMux<T>( i_trgt, i_rank, sp0, sp1 );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux(0x%08x,0x%02x) failed",
                      getHuid(i_trgt), i_rank.getKey() );
            break;
        }

        bool sp0Avail = false;
        bool sp1Avail = false;

        // Get the bad dq data
        MemDqBitmap dqBitmap;
        o_rc = getBadDqBitmap<T>( i_trgt, i_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
            break;
        }

        o_rc = dqBitmap.isSpareAvailable( sp0Avail, sp1Avail );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isSpareAvailable() failed" );
            break;
        }

        if ( (sp0Avail && !sp0.isValid()) ||
             (sp1Avail && !sp1.isValid()) )
        {
            o_spAvail = true;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

template
uint32_t isSpareAvailable<TYPE_MEM_PORT>( TARGETING::TargetHandle_t i_trgt,
    MemRank i_rank, bool & o_spAvail );

//##############################################################################
//##                         TOD functions
//##############################################################################

// FSP or HBRT only, not Hostboot
#if !defined(__HOSTBOOT_MODULE) || defined(__HOSTBOOT_RUNTIME)

int32_t getTodPortControlReg(const TARGETING::TargetHandle_t& i_procTgt,
                             bool i_slvPath0, uint32_t &o_regValue)
{
    #define PRDF_FUNC "[PlatServices::getTodPortControlReg] "

    // Query the TOD data file via HWSV.
    #ifdef __HOSTBOOT_RUNTIME

    TOD::TodChipDataContainer todRegData;
    errlHndl_t errl = TOD::readTodProcDataFromFile(todRegData);

    #else // FSP

    HWSV::TodChipDataContainer todRegData;
    const auto& hwsv = HWSV::theHwsvTodControls_t::Instance();
    errlHndl_t errl = hwsv.readTodProcDataFromFile(todRegData);

    #endif

    if (nullptr != errl)
    {
        PRDF_ERR(PRDF_FUNC "Failed to get TOD reg data from hwsv: "
                 "i_procTgt=0x%08x", getHuid(i_procTgt));
        PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
        return FAIL;
    }

    // Look for the chip matching this ordinal ID.
    const uint32_t ordId = i_procTgt->getAttr<ATTR_ORDINAL_ID>();
    bool foundChip = false;

    for (const auto& chip : todRegData)
    {
        if (chip.header.chipID == ordId)
        {
            o_regValue = i_slvPath0 ? chip.regs.pcrp0 : chip.regs.scrp1;
            foundChip = true;
            break;
        }
    }

    if (!foundChip)
    {
        PRDF_ERR(PRDF_FUNC "Could not find TOD reg data: i_procTgt=0x%08x "
                 "ordId=%d", getHuid(i_procTgt), ordId );
        return FAIL;
    }

    return SUCCESS;

    #undef PRDF_FUNC
}

#endif // FSP or HBRT only, not Hostboot

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

