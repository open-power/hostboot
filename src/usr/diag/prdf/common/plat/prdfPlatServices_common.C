/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/prdfPlatServices_common.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#include <p9c_query_channel_failure.H>

#ifdef __HOSTBOOT_MODULE
#include <prdfParserUtils.H>
#include <dimmBadDqBitmapFuncs.H>
#include <p9_io_xbus_read_erepair.H>
#include <p9_io_xbus_pdwn_lanes.H>
#include <p9_io_xbus_clear_firs.H>
#include <p9_io_erepairAccessorHwpFuncs.H>
#include <p9_io_cen_read_erepair.H>
#include <p9_io_cen_pdwn_lanes.H>
#include <p9_io_dmi_read_erepair.H>
#include <p9_io_dmi_clear_firs.H>
#include <p9_io_dmi_pdwn_lanes.H>
#include <p9_io_obus_pdwn_lanes.H>
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
//##                       Lane Repair functions
//##############################################################################

template<>
int32_t readErepair<TYPE_XBUS>(TargetHandle_t i_rxBusTgt,
                               std::vector<uint8_t> &o_rxFailLanes,
                               uint8_t i_clkGrp)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_XBUS == getTargetType(i_rxBusTgt) );
    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapiTrgt (i_rxBusTgt);
    FAPI_INVOKE_HWP(err,
                    p9_io_xbus_read_erepair,
                    fapiTrgt,
                    i_clkGrp,
                    o_rxFailLanes);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::readErepair] HUID: 0x%08x "
        "p9_io_xbus_read_erepair failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

template<>
int32_t readErepair<TYPE_MEMBUF>(TargetHandle_t i_rxBusTgt,
                                 std::vector<uint8_t> &o_rxFailLanes,
                                 uint8_t i_clkGrp)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_MEMBUF == getTargetType(i_rxBusTgt) );
    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fapiTrgt (i_rxBusTgt);
    FAPI_INVOKE_HWP(err,
                    p9_io_cen_read_erepair,
                    fapiTrgt,
                    o_rxFailLanes);

    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::readErepairMembuf] HUID: 0x%08x "
          "p9_io_cen_restore_erepair failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

template<>
int32_t readErepair<TYPE_DMI>(TargetHandle_t i_rxBusTgt,
                              std::vector<uint8_t> &o_rxFailLanes,
                              uint8_t i_clkGrp)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_DMI == getTargetType(i_rxBusTgt) );
    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> fapiTrgt (i_rxBusTgt);
    FAPI_INVOKE_HWP(err,
                    p9_io_dmi_read_erepair,
                    fapiTrgt,
                    o_rxFailLanes);

    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::readErepairDmi] HUID: 0x%08x "
                  "p9_io_dmi_read_erepair failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

//------------------------------------------------------------------------------
template<>
int32_t clearIOFirs<TYPE_XBUS>(TargetHandle_t i_rxBusTgt)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_XBUS == getTargetType(i_rxBusTgt) );

    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapiTrgt (i_rxBusTgt);

    for (uint8_t i=0; i<2; ++i) // clear both clock groups
    {
        FAPI_INVOKE_HWP(err, p9_io_xbus_clear_firs, fapiTrgt, i);
        if(nullptr != err)
        {
            PRDF_ERR( "[PlatServices::clearIOFirs<TYPE_XBUS>] HUID: 0x%08x "
            "p9_io_xbus_clear_firs failed", getHuid(i_rxBusTgt) );
            PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
            o_rc = FAIL;
        }
    }

    #endif

    return o_rc;
}

template<>
int32_t clearIOFirs<TYPE_MEMBUF>(TargetHandle_t  i_rxBusTgt)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_MEMBUF == getTargetType(i_rxBusTgt) );

    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fapiCenTrgt (i_rxBusTgt);
    // Clear Centaur side
    FAPI_INVOKE_HWP(err,
                    p9_io_dmi_cn_clear_firs,
                    fapiCenTrgt);

    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::clearIOFirs<TYPE_MEMBUF>] HUID: 0x%08x "
                  "p9_io_dmi_cn_clear_firs failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

template<>
int32_t clearIOFirs<TYPE_DMI>(TargetHandle_t  i_rxBusTgt)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_DMI == getTargetType(i_rxBusTgt) );

    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> fapiTrgt (i_rxBusTgt);

    FAPI_INVOKE_HWP(err,
                    p9_io_dmi_proc_clear_firs,
                    fapiTrgt);

    if (nullptr != err)
    {
        PRDF_ERR( "[PlatServices::clearIOFirs<TYPE_DMI>] HUID: 0x%08x "
                  "p9_io_dmi_proc_clear_firs failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

//------------------------------------------------------------------------------
template<>
int32_t powerDownLanes<TYPE_XBUS>( TargetHandle_t i_rxBusTgt,
                                   const std::vector<uint8_t> &i_rxFailLanes,
                                   const std::vector<uint8_t> &i_txFailLanes,
                                   uint8_t i_clkGrp )
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_XBUS == getTargetType(i_rxBusTgt) );
    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapiTrgt (i_rxBusTgt);
    FAPI_INVOKE_HWP(err,
                    p9_io_xbus_pdwn_lanes,
                    fapiTrgt,
                    i_clkGrp,
                    i_rxFailLanes,
                    i_txFailLanes);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::powerDownLanes] HUID: 0x%08x "
                  "p9_io_xbus_pdwn_lanes failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

template<>
int32_t powerDownLanes<TYPE_MEMBUF>(TargetHandle_t i_rxBusTgt,
                                    const std::vector<uint8_t> &i_rxFailLanes,
                                    const std::vector<uint8_t> &i_txFailLanes,
                                    uint8_t i_clkGrp )
{

    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_MEMBUF == getTargetType(i_rxBusTgt) );

    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fapiTrgt (i_rxBusTgt);
    FAPI_INVOKE_HWP(err,
                    p9_io_cen_pdwn_lanes,
                    fapiTrgt,
                    i_rxFailLanes,
                    i_txFailLanes);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::powerDownLanesMembuf] HUID: 0x%08x "
                  "p9_io_cen_pdwn_lanes failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

template<>
int32_t powerDownLanes<TYPE_DMI>(TargetHandle_t i_rxBusTgt,
                                 const std::vector<uint8_t> &i_rxFailLanes,
                                 const std::vector<uint8_t> &i_txFailLanes,
                                 uint8_t i_clkGrp )
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_DMI == getTargetType(i_rxBusTgt) );
    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> fapiTrgt (i_rxBusTgt);
    FAPI_INVOKE_HWP(err,
                    p9_io_dmi_pdwn_lanes,
                    fapiTrgt,
                    i_rxFailLanes,
                    i_txFailLanes);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::powerDownLanesDmi] HUID: 0x%08x "
                  "p9_io_dmi_pdwn_lanes failed", getHuid(i_rxBusTgt) );
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

int32_t powerDownObusLink(TargetHandle_t i_obusTrgt, unsigned int i_link)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    PRDF_ASSERT(nullptr != i_obusTrgt);
    PRDF_ASSERT(TYPE_OBUS == getTargetType(i_obusTrgt));
    PRDF_ASSERT(i_link < 2);


    errlHndl_t errl = nullptr;
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> fapiTrgt { i_obusTrgt };

    // The lane vector is a 24-bit unsigned integer (right justified). Each bit
    // represents lanes 23 to 0 (left to right). Each link is defined as such:
    //   Lanes 23-13 => link 1
    //   Lanes 12-11 => unused
    //   Lanes 10-0  => link 0
    uint32_t laneVector = (0 == i_link) ? 0x0007ff : 0xffe000;

    FAPI_INVOKE_HWP(errl, p9_io_obus_pdwn_lanes, i_obusTrgt, laneVector);

    if (nullptr != errl)
    {
        PRDF_ERR("[PlatServices::powerDownObusLink] p9_io_obus_pdwn_lanes "
                 "failed: i_obusTrgt=0x%08x i_link=%u", getHuid(i_obusTrgt),
                 i_link );
        PRDF_COMMIT_ERRL(errl, ERRL_ACTION_REPORT);
        o_rc = FAIL;
    }

    #endif

    return o_rc;
}

//------------------------------------------------------------------------------
template<>
int32_t getVpdFailedLanes<TYPE_XBUS>(TargetHandle_t i_rxBusTgt,
                                     std::vector<uint8_t> &o_rxFailLanes,
                                     std::vector<uint8_t> &o_txFailLanes,
                                     uint8_t i_clkGrp)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_XBUS == getTargetType(i_rxBusTgt) );

    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapiTrgt (i_rxBusTgt);

    FAPI_INVOKE_HWP(err,
                    erepairGetFailedLanes,
                    fapiTrgt,
                    i_clkGrp,
                    o_txFailLanes,
                    o_rxFailLanes);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::getVpdFailedLanes] HUID: 0x%08x "
                  "erepairGetFailedLanes failed",
                  getHuid(i_rxBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

template<>
int32_t getVpdFailedLanes<TYPE_MEMBUF>(TargetHandle_t i_rxBusTgt,
                              std::vector<uint8_t> &o_rxFailLanes,
                              std::vector<uint8_t> &o_txFailLanes,
                              uint8_t i_clkGrp)
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_MEMBUF == getTargetType(i_rxBusTgt) );

    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fapiTrgt (i_rxBusTgt);

    FAPI_INVOKE_HWP(err,
                    erepairGetFailedLanes,
                    fapiTrgt,
                    i_clkGrp,
                    o_txFailLanes,
                    o_rxFailLanes);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::getVpdFailedLanesMembuf] HUID: 0x%08x "
                  "erepairGetFailedLanes failed",
                  getHuid(i_rxBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

template<>
int32_t getVpdFailedLanes<TYPE_DMI>( TargetHandle_t i_rxBusTgt,
                                     std::vector<uint8_t> &o_rxFailLanes,
                                     std::vector<uint8_t> &o_txFailLanes,
                                     uint8_t i_clkGrp )
{
    int32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( TYPE_DMI == getTargetType(i_rxBusTgt) );

    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> fapiTrgt (i_rxBusTgt);

    FAPI_INVOKE_HWP(err,
                    erepairGetFailedLanes,
                    fapiTrgt,
                    i_clkGrp,
                    o_txFailLanes,
                    o_rxFailLanes);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::getVpdFailedLanesDmi] HUID: 0x%08x "
                  "erepairGetFailedLanes failed",
                  getHuid(i_rxBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

//------------------------------------------------------------------------------
template<>
int32_t setVpdFailedLanes<TYPE_XBUS,TYPE_XBUS>(
                                            TargetHandle_t i_rxBusTgt,
                                            TargetHandle_t i_txBusTgt,
                                            std::vector<uint8_t> &i_rxFailLanes,
                                            bool & o_thrExceeded,
                                            uint8_t i_clkGrp )
{
    int32_t o_rc = SUCCESS;
    o_thrExceeded = false;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( nullptr != i_txBusTgt);
    PRDF_ASSERT( TYPE_XBUS == getTargetType(i_rxBusTgt) );
    PRDF_ASSERT( TYPE_XBUS == getTargetType(i_txBusTgt) );


    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapiRxTrgt (i_rxBusTgt);
    fapi2::Target<fapi2::TARGET_TYPE_XBUS> fapiTxTrgt (i_txBusTgt);

    FAPI_INVOKE_HWP(err,
                    erepairSetFailedLanes,
                    fapiTxTrgt,
                    fapiRxTrgt,
                    i_clkGrp,
                    i_rxFailLanes,
                    o_thrExceeded);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::setVpdFailedLanes] rxHUID: 0x%08x "
                  "txHUID: 0x%08x erepairSetFailedLanes failed",
                  getHuid(i_rxBusTgt), getHuid(i_txBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}


template<>
int32_t setVpdFailedLanes<TYPE_MEMBUF, TYPE_DMI>(
                                            TargetHandle_t i_rxBusTgt,
                                            TargetHandle_t i_txBusTgt,
                                            std::vector<uint8_t> &i_rxFailLanes,
                                            bool & o_thrExceeded,
                                            uint8_t i_clkGrp )
{
    int32_t o_rc = SUCCESS;
    o_thrExceeded = false;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( nullptr != i_txBusTgt);
    PRDF_ASSERT( TYPE_MEMBUF == getTargetType(i_rxBusTgt) );
    PRDF_ASSERT( TYPE_DMI == getTargetType(i_txBusTgt) );


    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fapiRxTrgt (i_rxBusTgt);
    fapi2::Target<fapi2::TARGET_TYPE_DMI> fapiTxTrgt (i_txBusTgt);

    FAPI_INVOKE_HWP(err,
                    erepairSetFailedLanes,
                    fapiTxTrgt,
                    fapiRxTrgt,
                    i_clkGrp,
                    i_rxFailLanes,
                    o_thrExceeded);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::setVpdFailedLanesMembuf] rxHUID: 0x%08x "
                  "txHUID: 0x%08x erepairSetFailedLanes failed",
                  getHuid(i_rxBusTgt), getHuid(i_txBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}


template<>
int32_t setVpdFailedLanes<TYPE_DMI,TYPE_MEMBUF>(
                                            TargetHandle_t i_rxBusTgt,
                                            TargetHandle_t i_txBusTgt,
                                            std::vector<uint8_t> &i_rxFailLanes,
                                            bool & o_thrExceeded,
                                            uint8_t i_clkGrp )
{
    int32_t o_rc = SUCCESS;
    o_thrExceeded = false;

    #ifdef __HOSTBOOT_MODULE
    PRDF_ASSERT( nullptr != i_rxBusTgt);
    PRDF_ASSERT( nullptr != i_txBusTgt);
    PRDF_ASSERT( TYPE_DMI == getTargetType(i_rxBusTgt) );
    PRDF_ASSERT( TYPE_MEMBUF == getTargetType(i_txBusTgt) );


    errlHndl_t err = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> fapiRxTrgt (i_rxBusTgt);
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fapiTxTrgt (i_txBusTgt);

    FAPI_INVOKE_HWP(err,
                    erepairSetFailedLanes,
                    fapiTxTrgt,
                    fapiRxTrgt,
                    i_clkGrp,
                    i_rxFailLanes,
                    o_thrExceeded);

    if(nullptr != err)
    {
        PRDF_ERR( "[PlatServices::setVpdFailedLanesDmi] rxHUID: 0x%08x "
                  "txHUID: 0x%08x erepairSetFailedLanes failed",
                  getHuid(i_rxBusTgt), getHuid(i_txBusTgt));
        PRDF_COMMIT_ERRL( err, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    #endif
    return o_rc;
}

//------------------------------------------------------------------------------
bool obusInSmpMode( TargetHandle_t obus )
{
    return obus->getAttr<ATTR_OPTICS_CONFIG_MODE>() == OPTICS_CONFIG_MODE_SMP;
}


//##############################################################################
//##                        Memory specific functions
//##############################################################################

template <fapi2::TargetType T>
uint32_t __getBadDqBitmap( TargetHandle_t i_trgt, const MemRank & i_rank,
                           MemDqBitmap & o_bitmap )
{
    #define PRDF_FUNC "[PlatServices::__getBadDqBitmap] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    BitmapData data;

    for ( uint32_t ps = 0; ps < MAX_SUB_PORT; ps++ )
    {
        // Skip if the DIMM doesn't exist
        if ( nullptr == getConnectedDimm(i_trgt, i_rank, ps) ) continue;

        errlHndl_t errl = nullptr;

        fapi2::Target<T> l_fapiTrgt( i_trgt );

        FAPI_INVOKE_HWP( errl, p9DimmGetBadDqBitmap, l_fapiTrgt,
                         i_rank.getDimmSlct(), i_rank.getRankSlct(),
                         data[ps].bitmap, ps );

        if ( nullptr != errl )
        {
            PRDF_ERR( PRDF_FUNC "p9DimmGetBadDqBitmap() failed: i_trgt=0x%08x "
                    "ps=%d ds=%d rs=%d", getHuid(i_trgt), ps,
                    i_rank.getDimmSlct(), i_rank.getRankSlct() );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }
    }

    if ( SUCCESS == o_rc )
    {
        o_bitmap = MemDqBitmap( i_trgt, i_rank, data );
    }

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}

uint32_t getBadDqBitmap( TargetHandle_t i_trgt, const MemRank & i_rank,
                         MemDqBitmap & o_bitmap )
{
    #define PRDF_FUNC "[PlatServices::getBadDqBitmap] "

    uint32_t o_rc = SUCCESS;
    TYPE trgtType = getTargetType( i_trgt );

    switch( trgtType )
    {
        case TYPE_MCA:
            o_rc = __getBadDqBitmap<fapi2::TARGET_TYPE_MCA>( i_trgt, i_rank,
                                                             o_bitmap );
            break;
        case TYPE_MBA:
            o_rc = __getBadDqBitmap<fapi2::TARGET_TYPE_MBA>( i_trgt, i_rank,
                                                             o_bitmap );
            break;
        case TYPE_MEM_PORT:
            o_rc = __getBadDqBitmap<fapi2::TARGET_TYPE_MEM_PORT>( i_trgt,
                i_rank, o_bitmap );
            break;
        case TYPE_OCMB_CHIP:
            o_rc = __getBadDqBitmap<fapi2::TARGET_TYPE_OCMB_CHIP>( i_trgt,
                i_rank, o_bitmap );
            break;
        default:
            PRDF_ERR( PRDF_FUNC "Invalid trgt type" );
            o_rc = FAIL;
            break;
    }

    return o_rc;

    #undef PRDF_FUNC
}


//------------------------------------------------------------------------------

template <fapi2::TargetType T>
uint32_t __setBadDqBitmap( TargetHandle_t i_trgt, const MemRank & i_rank,
                        const MemDqBitmap & i_bitmap )
{
    #define PRDF_FUNC "[PlatServices::setBadDqBitmap] "

    uint32_t o_rc = SUCCESS;

    #ifdef __HOSTBOOT_MODULE

    if ( !areDramRepairsDisabled() )
    {
        const BitmapData data = i_bitmap.getData();

        size_t maxPorts = i_bitmap.getNumPorts();
        for ( uint32_t ps = 0; ps < maxPorts; ps++ )
        {
            // Don't proceed unless the DIMM exists
            PRDF_ASSERT( nullptr != getConnectedDimm(i_trgt, i_rank, ps) );

            errlHndl_t errl = nullptr;

            fapi2::Target<T> l_fapiTrgt( i_trgt );

            FAPI_INVOKE_HWP( errl, p9DimmSetBadDqBitmap, l_fapiTrgt,
                             i_rank.getDimmSlct(), i_rank.getRankSlct(),
                             data.at(ps).bitmap, ps );

            if ( nullptr != errl )
            {
                PRDF_ERR( PRDF_FUNC "p9DimmSetBadDqBitmap() failed: "
                          "i_trgt=0x%08x ps=%d ds=%d rs=%d", getHuid(i_trgt),
                          ps, i_rank.getDimmSlct(), i_rank.getRankSlct() );
                PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
                o_rc = FAIL;
            }
        }
    }

    #endif // __HOSTBOOT_MODULE

    return o_rc;

    #undef PRDF_FUNC
}

uint32_t setBadDqBitmap( TargetHandle_t i_trgt, const MemRank & i_rank,
    const MemDqBitmap & i_bitmap )
{
    #define PRDF_FUNC "[PlatServices::setBadDqBitmap] "

    uint32_t o_rc = SUCCESS;
    TYPE trgtType = getTargetType( i_trgt );

    switch( trgtType )
    {
        case TYPE_MCA:
            o_rc = __setBadDqBitmap<fapi2::TARGET_TYPE_MCA>( i_trgt, i_rank,
                                                             i_bitmap );
            break;
        case TYPE_MBA:
            o_rc = __setBadDqBitmap<fapi2::TARGET_TYPE_MBA>( i_trgt, i_rank,
                                                             i_bitmap );
            break;
        case TYPE_MEM_PORT:
            o_rc = __setBadDqBitmap<fapi2::TARGET_TYPE_MEM_PORT>( i_trgt,
                i_rank, i_bitmap );
            break;
        case TYPE_OCMB_CHIP:
            o_rc = __setBadDqBitmap<fapi2::TARGET_TYPE_OCMB_CHIP>( i_trgt,
                i_rank, i_bitmap );
            break;
        default:
            PRDF_ERR( PRDF_FUNC "Invalid trgt type" );
            o_rc = FAIL;
            break;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

uint32_t clearBadDqBitmap( TargetHandle_t i_trgt, const MemRank & i_rank )
{
    #define PRDF_FUNC "[PlatServices::clearBadDqBitmap] "

    uint32_t o_rc = SUCCESS;

    do
    {
        MemDqBitmap dqBitmap;
        o_rc = getBadDqBitmap( i_trgt, i_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap(0x%08x, 0x%02x) failed.",
                      getHuid(i_trgt), i_rank.getKey() );
            break;
        }

        dqBitmap.clearBitmap();

        o_rc = setBadDqBitmap( i_trgt, i_rank, dqBitmap );
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
void getDimmDqAttr<TYPE_MCA>( TargetHandle_t i_target,
                              uint8_t (&o_dqMapPtr)[DQS_PER_DIMM] )
{
    #define PRDF_FUNC "[PlatServices::getDimmDqAttr<TYPE_MCA>] "

    PRDF_ASSERT( TYPE_MCA == getTargetType(i_target) );

    TargetHandle_t mcs = getConnectedParent( i_target, TYPE_MCS );

    uint32_t mcaRelMcs = getTargetPosition( i_target ) % MAX_MCA_PER_MCS;
    uint8_t  tmpData[MAX_MCA_PER_MCS][DQS_PER_DIMM];

    if ( !mcs->tryGetAttr<ATTR_MSS_VPD_DQ_MAP>(tmpData) )
    {
        PRDF_ERR( PRDF_FUNC "Failed to get ATTR_MSS_VPD_DQ_MAP" );
        PRDF_ASSERT( false );
    }

    memcpy( &o_dqMapPtr[0], &tmpData[mcaRelMcs][0], DQS_PER_DIMM );

    #undef PRDF_FUNC
} // end function getDimmDqAttr

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

template<>
void getDimmDqAttr<TYPE_OCMB_CHIP>( TargetHandle_t i_target,
                                    uint8_t (&o_dqMapPtr)[DQS_PER_DIMM] )
{
    PRDF_ASSERT( TYPE_OCMB_CHIP == getTargetType(i_target) );

    // TODO RTC 210072 - Support for multiple ports per OCMB
    TargetHandle_t memPort = getConnectedChild( i_target, TYPE_MEM_PORT, 0 );
    getDimmDqAttr<TYPE_MEM_PORT>( memPort, o_dqMapPtr );
}

template<>
void getDimmDqAttr<TYPE_DIMM>( TargetHandle_t i_target,
                               uint8_t (&o_dqMapPtr)[DQS_PER_DIMM] )
{
    #define PRDF_FUNC "[PlatServices::getDimmDqAttr<TYPE_DIMM>] "

    PRDF_ASSERT( TYPE_DIMM == getTargetType(i_target) );

    const uint8_t DIMM_BAD_DQ_SIZE_BYTES = 80;

    uint8_t tmpData[DIMM_BAD_DQ_SIZE_BYTES];

    if ( !i_target->tryGetAttr<ATTR_CEN_DQ_TO_DIMM_CONN_DQ>(tmpData) )
    {
        PRDF_ERR( PRDF_FUNC "Failed to get ATTR_CEN_DQ_TO_DIMM_CONN_DQ" );
        PRDF_ASSERT( false );
    }

    memcpy( &o_dqMapPtr[0], &tmpData[0], DQS_PER_DIMM );

    #undef PRDF_FUNC
} // end function getDimmDqAttr


//------------------------------------------------------------------------------

template<>
int32_t mssGetSteerMux<TYPE_MCA>( TargetHandle_t i_mca,
                                  const MemRank & i_rank,
                                  MemSymbol & o_port0Spare,
                                  MemSymbol & o_port1Spare,
                                  MemSymbol & o_eccSpare )
{
    // NO-OP for MCA
    o_port0Spare = MemSymbol(); // default invalid
    o_port1Spare = MemSymbol(); // default invalid
    o_eccSpare   = MemSymbol(); // default invalid
    return SUCCESS;
}

template<>
int32_t mssGetSteerMux<TYPE_MBA>( TargetHandle_t i_mba, const MemRank & i_rank,
                            MemSymbol & o_port0Spare, MemSymbol & o_port1Spare,
                            MemSymbol & o_eccSpare )
{
    int32_t o_rc = SUCCESS;

    // called by FSP code so can't just move to hostboot side
#ifdef __HOSTBOOT_MODULE
    errlHndl_t errl = NULL;

    uint8_t port0Spare, port1Spare, eccSpare;

    fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiMba(i_mba);
    FAPI_INVOKE_HWP( errl, mss_check_steering, fapiMba,
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
        o_port0Spare = MemSymbol::fromSymbol( i_mba, i_rank, port0Spare );
        o_port1Spare = MemSymbol::fromSymbol( i_mba, i_rank, port1Spare );
        o_eccSpare   = MemSymbol::fromSymbol( i_mba, i_rank, eccSpare   );
    }
#endif
    return o_rc;
}

template<>
int32_t mssGetSteerMux<TYPE_OCMB_CHIP>( TargetHandle_t i_ocmb,
                                        const MemRank & i_rank,
                                        MemSymbol & o_port0Spare,
                                        MemSymbol & o_port1Spare,
                                        MemSymbol & o_eccSpare )
{
    int32_t o_rc = SUCCESS;

    /* TODO RTC 199032 - sparing support

    // called by FSP code so can't just move to hostboot side
#ifdef __HOSTBOOT_MODULE
    errlHndl_t errl = NULL;

    uint8_t port0Spare, port1Spare, eccSpare;

    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiPort(i_ocmb);
    FAPI_INVOKE_HWP( errl, mss_check_steering, fapiPort,
            i_rank.getMaster(), port0Spare, port1Spare, eccSpare );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssGetSteerMux] mss_check_steering() "
                  "failed. HUID: 0x%08x rank: %d",
                  getHuid(i_ocmb), i_rank.getMaster() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
    else
    {
        o_port0Spare = MemSymbol::fromSymbol( i_ocmb, i_rank, port0Spare );
        o_port1Spare = MemSymbol::fromSymbol( i_ocmb, i_rank, port1Spare );
        o_eccSpare   = MemSymbol::fromSymbol( i_ocmb, i_rank, eccSpare   );
    }
#endif
    */

    return o_rc;
}

//------------------------------------------------------------------------------

template<>
int32_t mssSetSteerMux<TYPE_MBA>( TargetHandle_t i_mba, const MemRank & i_rank,
                                const MemSymbol & i_symbol, bool i_x4EccSpare )
{
    int32_t o_rc = SUCCESS;
#ifdef __HOSTBOOT_MODULE
    errlHndl_t errl = NULL;
    fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiMba(i_mba);

    uint8_t l_dramSymbol = PARSERUTILS::dram2Symbol<TYPE_MBA>(
                                                     i_symbol.getDram(),
                                                     isDramWidthX4(i_mba) );

    FAPI_INVOKE_HWP( errl, mss_do_steering, fapiMba,
                     i_rank.getMaster(), l_dramSymbol,
                     i_x4EccSpare );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssSetSteerMux] mss_do_steering "
                  "failed. HUID: 0x%08x rank: %d symbol: %d eccSpare: %c",
                  getHuid(i_mba), i_rank.getMaster(), l_dramSymbol,
                  i_x4EccSpare ? 'T' : 'F' );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
#endif
    return o_rc;
}

template<>
int32_t mssSetSteerMux<TYPE_OCMB_CHIP>( TargetHandle_t i_memPort,
    const MemRank & i_rank, const MemSymbol & i_symbol, bool i_x4EccSpare )
{
    int32_t o_rc = SUCCESS;

    /* TODO RTC 199032 - sparing support

#ifdef __HOSTBOOT_MODULE
    errlHndl_t errl = NULL;
    fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> fapiPort(i_memPort);

    TargetHandle_t dimm = getConnectedDimm( i_memPort, i_rank,
                                            i_symbol.getPortSlct() );
    uint8_t l_dramSymbol = PARSERUTILS::dram2Symbol<TYPE_MBA>(
                                                     i_symbol.getDram(),
                                                     isDramWidthX4(dimm) );

    FAPI_INVOKE_HWP( errl, mss_do_steering, fapiPort,
                     i_rank.getMaster(), l_dramSymbol,
                     i_x4EccSpare );

    if ( NULL != errl )
    {
        PRDF_ERR( "[PlatServices::mssSetSteerMux] mss_do_steering "
                  "failed. HUID: 0x%08x rank: %d symbol: %d eccSpare: %c",
                  getHuid(i_memPort), i_rank.getMaster(), l_dramSymbol,
                  i_x4EccSpare ? 'T' : 'F' );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }
#endif
    */
    return o_rc;
}

//------------------------------------------------------------------------------

template<>
int32_t getDimmSpareConfig<TYPE_MCA>( TargetHandle_t i_mca, MemRank i_rank,
                                      uint8_t i_ps, uint8_t & o_spareConfig )
{
    // No spares for MCAs
    o_spareConfig = CEN_VPD_DIMM_SPARE_NO_SPARE;
    return SUCCESS;
}

template<>
int32_t getDimmSpareConfig<TYPE_MEM_PORT>( TargetHandle_t i_memPort,
                        MemRank i_rank, uint8_t i_ps, uint8_t & o_spareConfig )
{
    #define PRDF_FUNC "[PlatServices::getDimmSpareConfig] "
    int32_t o_rc = SUCCESS;

#ifdef __HOSTBOOT_MODULE
    using namespace fapi2;

    ATTR_MEM_EFF_DIMM_SPARE_Type attr;
    o_spareConfig = ENUM_ATTR_MEM_EFF_DIMM_SPARE_NO_SPARE;
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
        if ( NULL != errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get ATTR_MEM_EFF_DIMM_SPARE for "
                      "Target: 0x%08X", getHuid( i_memPort ) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }
        o_spareConfig = attr[i_rank.getDimmSlct()][i_rank.getRankSlct()];

        // Check for valid values
        // For X4 DRAM, we can not have full byte as spare config. Also for X8
        // DRAM we can not have nibble as spare.

        if( ENUM_ATTR_MEM_EFF_DIMM_SPARE_NO_SPARE == o_spareConfig) break;

        bool isFullByte = ( ENUM_ATTR_MEM_EFF_DIMM_SPARE_FULL_BYTE ==
                            o_spareConfig );

        TargetHandle_t dimm = getConnectedDimm( i_memPort, i_rank, i_ps );
        bool isX4Dram = isDramWidthX4(dimm);

        if ( ( isX4Dram && isFullByte ) || ( !isX4Dram && !isFullByte ) )
        {
            PRDF_ERR( PRDF_FUNC "Invalid Configuration: o_spareConfig:%u",
                      o_spareConfig );
            o_rc = FAIL; break;
        }

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
    return getDimmSpareConfig<TYPE_MEM_PORT>( memPort, i_rank, i_ps,
                                              o_spareConfig );
}

template<>
int32_t getDimmSpareConfig<TYPE_MBA>( TargetHandle_t i_mba, MemRank i_rank,
                                      uint8_t i_ps, uint8_t & o_spareConfig )
{
    #define PRDF_FUNC "[PlatServices::getDimmSpareConfig] "
    int32_t o_rc = SUCCESS;

#ifdef __HOSTBOOT_MODULE
    using namespace fapi2;

    ATTR_CEN_VPD_DIMM_SPARE_Type attr;
    o_spareConfig = ENUM_ATTR_CEN_VPD_DIMM_SPARE_NO_SPARE;
    do
    {
        if( TYPE_MBA != getTargetType( i_mba ) )
        {
            PRDF_ERR( PRDF_FUNC "Invalid Target:0x%08X", getHuid( i_mba ) );
            o_rc = FAIL; break;
        }

        if ( MAX_PORT_PER_MBA <= i_ps )
        {
            PRDF_ERR( PRDF_FUNC "Invalid parameters i_ps:%u", i_ps );
            o_rc = FAIL; break;
        }

        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapiMba(i_mba);
        ReturnCode l_rc = FAPI_ATTR_GET(ATTR_CEN_VPD_DIMM_SPARE, fapiMba, attr);
        errlHndl_t errl = fapi2::rcToErrl(l_rc);
        if ( NULL != errl )
        {
            PRDF_ERR( PRDF_FUNC "Failed to get ATTR_VPD_DIMM_SPARE for Target:"
                      "0x%08X", getHuid( i_mba ) );
            PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
            o_rc = FAIL; break;
        }
        o_spareConfig = attr[i_ps][i_rank.getDimmSlct()][i_rank.getRankSlct()];

        // Check for valid values
        // For X4 DRAM, we can not have full byte as spare config. Also for X8
        // DRAM we can not have nibble as spare.

        if( ENUM_ATTR_CEN_VPD_DIMM_SPARE_NO_SPARE == o_spareConfig) break;

        bool isFullByte = ( ENUM_ATTR_CEN_VPD_DIMM_SPARE_FULL_BYTE ==
                                                            o_spareConfig );
        bool isX4Dram = isDramWidthX4(i_mba);

        if ( ( isX4Dram && isFullByte ) || ( !isX4Dram && !isFullByte ) )
        {
            PRDF_ERR( PRDF_FUNC "Invalid Configuration: o_spareConfig:%u",
                      o_spareConfig );
            o_rc = FAIL; break;
        }

    }while(0);
#endif

    return o_rc;
    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
uint32_t isDramSparingEnabled<TYPE_MCA>( TARGETING::TargetHandle_t i_trgt,
                                         MemRank i_rank, uint8_t i_ps,
                                         bool & o_spareEnable )
{
    // DRAM sparing not supported for MCA
    o_spareEnable = false;
    return SUCCESS;
}

template<>
uint32_t isDramSparingEnabled<TYPE_MEM_PORT>( TARGETING::TargetHandle_t i_trgt,
                                              MemRank i_rank, uint8_t i_ps,
                                              bool & o_spareEnable )
{
    #define PRDF_FUNC "[PlatServices::isDramSparingEnabled<TYPE_MEM_PORT>] "

    uint32_t o_rc = SUCCESS;
    o_spareEnable = false;

    /* TODO RTC 199032 - DRAM Sparing disabled for now
    do
    {
        TargetHandle_t dimm = getConnectedDimm( i_trgt, i_rank, i_ps );
        const bool isX4 = isDramWidthX4( dimm );
        if ( isX4 )
        {
            // Always an ECC spare in x4 mode.
            o_spareEnable = true;
            break;
        }

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
    */

    return o_rc;

    #undef PRDF_FUNC
}

template<>
uint32_t isDramSparingEnabled<TYPE_MBA>( TARGETING::TargetHandle_t i_trgt,
                                         MemRank i_rank, uint8_t i_ps,
                                         bool & o_spareEnable )
{
    #define PRDF_FUNC "[PlatServices::isDramSparingEnabled<TYPE_MBA>] "

    uint32_t o_rc = SUCCESS;
    o_spareEnable = false;

    do
    {
        const bool isX4 = isDramWidthX4( i_trgt );
        if ( isX4 )
        {
            // Always an ECC spare in x4 mode.
            o_spareEnable = true;
            break;
        }

        // Check for any DRAM spares.
        uint8_t cnfg = TARGETING::CEN_VPD_DIMM_SPARE_NO_SPARE;
        o_rc = getDimmSpareConfig<TYPE_MBA>( i_trgt, i_rank, i_ps, cnfg );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getDimmSpareConfig(0x%08x,0x%02x,%d) "
                      "failed", getHuid(i_trgt), i_rank.getKey(), i_ps );
            break;
        }
        o_spareEnable = (TARGETING::CEN_VPD_DIMM_SPARE_NO_SPARE != cnfg);

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<TARGETING::TYPE T>
uint32_t isSpareAvailable( TARGETING::TargetHandle_t i_trgt, MemRank i_rank,
                           uint8_t i_ps, bool & o_spAvail, bool & o_eccAvail )
{
    #define PRDF_FUNC "[PlatServices::isSpareAvailable] "

    uint32_t o_rc = SUCCESS;

    o_spAvail = false;
    o_eccAvail = false;

    do
    {
        bool dramSparingEnabled = false;
        o_rc = isDramSparingEnabled<T>( i_trgt, i_rank, i_ps,
                                        dramSparingEnabled );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isDramSparingEnabled() failed." );
            break;
        }

        // Break out if dram sparing isn't enabled
        if ( !dramSparingEnabled ) break;

        // Get the current spares in hardware
        TargetHandle_t steerTrgt = i_trgt;
        MemSymbol sp0, sp1, ecc;
        if ( TYPE_MEM_PORT == T )
        {
            steerTrgt = getConnectedParent( i_trgt, TYPE_OCMB_CHIP );
            o_rc = mssGetSteerMux<TYPE_OCMB_CHIP>( steerTrgt, i_rank, sp0, sp1,
                                                   ecc );
        }
        else
        {
            o_rc = mssGetSteerMux<T>( steerTrgt, i_rank, sp0, sp1, ecc );
        }
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "mssGetSteerMux(0x%08x,0x%02x) failed",
                      getHuid(steerTrgt), i_rank.getKey() );
            break;
        }

        bool dramSparePossible = false;
        bool eccSparePossible  = false;

        // Get the bad dq data
        MemDqBitmap dqBitmap;
        o_rc = getBadDqBitmap( i_trgt, i_rank, dqBitmap );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "getBadDqBitmap() failed" );
            break;
        }

        o_rc = dqBitmap.isSpareAvailable( i_ps, dramSparePossible,
                                          eccSparePossible );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "isSpareAvailable() failed" );
            break;
        }

        if (dramSparePossible && (0 == i_ps ? !sp0.isValid() : !sp1.isValid()))
        {
            o_spAvail = true;
        }
        if ( eccSparePossible && !ecc.isValid() )
        {
            o_eccAvail = true;
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC

}

template
uint32_t isSpareAvailable<TYPE_MBA>( TARGETING::TargetHandle_t i_trgt,
    MemRank i_rank, uint8_t i_ps, bool & o_spAvail, bool & o_eccAvail );

template
uint32_t isSpareAvailable<TYPE_MEM_PORT>( TARGETING::TargetHandle_t i_trgt,
    MemRank i_rank, uint8_t i_ps, bool & o_spAvail, bool & o_eccAvail );

//------------------------------------------------------------------------------

template<>
uint32_t queryChnlFail<TYPE_DMI>( ExtensibleChip * i_chip, bool & o_chnlFail )
{
    #define PRDF_FUNC "[PlatServices::queryChnlFail] "

    PRDF_ASSERT( nullptr != i_chip );
    PRDF_ASSERT( TYPE_DMI == i_chip->getType() );

    uint32_t o_rc = SUCCESS;

    errlHndl_t errl = nullptr;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> fapiTrgt ( i_chip->getTrgt() );

    FAPI_INVOKE_HWP( errl, p9c_query_channel_failure, fapiTrgt, o_chnlFail );
    if ( nullptr != errl )
    {
        PRDF_ERR( PRDF_FUNC "p9c_query_channel_failure(0x%08x) failed",
                  i_chip->getHuid() );
        PRDF_COMMIT_ERRL( errl, ERRL_ACTION_REPORT );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------
// Constants defined from Serial Presence Detect (SPD) specs
//---------------------------------------------------------------------
const uint8_t SPD_IDX_MODSPEC_COM_REF_BASIC_MEMORY_TYPE = 0x02;
const uint8_t SPD_IDX_DDR3_MODSPEC_COM_REF_RAW_CARD_EXT = 0x3e;
const uint8_t SPD_IDX_DDR3_MODSPEC_COM_REF_RAW_CARD     = 0x3e;
const uint8_t SPD_IDX_DDR4_MODSPEC_COM_REF_RAW_CARD_EXT = 0x82;
const uint8_t SPD_IDX_DDR4_MODSPEC_COM_REF_RAW_CARD     = 0x82;

const uint8_t RAW_CARD_EXT_MASK         = 0x80;
const uint8_t RAW_CARD_EXT_SHIFT        = 0x07;
const uint8_t RAW_CARD_MASK             = 0x1f;
const uint8_t BASIC_MEMORY_TYPE_DDR4    = 0x0c;

enum SPD_MODSPEC_COM_REF_RAW_CARD
{
  SPD_MODSPEC_COM_REF_RAW_CARD_A = 0x00,
  SPD_MODSPEC_COM_REF_RAW_CARD_B = 0x01,
  SPD_MODSPEC_COM_REF_RAW_CARD_C = 0x02,
  SPD_MODSPEC_COM_REF_RAW_CARD_D = 0x03,
};
//---------------------------------------------------------------------

int32_t  getSpdModspecComRefRawCard(
                      const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_pTarget,
                      uint8_t & o_rawCard )
{
#define PRDF_FUNC "[PlatServices::getSpdModspecComRefRawCard] "

    int32_t rc = SUCCESS;
    o_rawCard = 0xff; // something invalid
    size_t l_size = 0;
    uint8_t * l_blobData = nullptr;

    do{
      // Grab the SPD data for this DIMM
      // This has an FSP and Hostboot implementation
      rc = getSpdData(i_pTarget, l_blobData, l_size);
      if (rc != SUCCESS)
      {
        break;
      }

      // Now parse the SPD data for the RawCard
      uint8_t l_card = 0;
      uint8_t l_cardExt = 0;  // 0 or 1

      uint8_t RawCardIdx = SPD_IDX_DDR3_MODSPEC_COM_REF_RAW_CARD;
      uint8_t RawCardExtIdx = SPD_IDX_DDR3_MODSPEC_COM_REF_RAW_CARD_EXT;

      if ( (l_size > SPD_IDX_MODSPEC_COM_REF_BASIC_MEMORY_TYPE) &&
           l_blobData[SPD_IDX_MODSPEC_COM_REF_BASIC_MEMORY_TYPE] ==
           BASIC_MEMORY_TYPE_DDR4 )
      {
         RawCardIdx = SPD_IDX_DDR4_MODSPEC_COM_REF_RAW_CARD;
         RawCardExtIdx = SPD_IDX_DDR4_MODSPEC_COM_REF_RAW_CARD_EXT;
      }

      // Get the Reference Raw Card Extension (0 or 1)
      if (l_size > RawCardExtIdx)
      {
         l_cardExt = ( (l_blobData[RawCardExtIdx] & RAW_CARD_EXT_MASK) >>
                       RAW_CARD_EXT_SHIFT );
      }
      else
      {
         PRDF_ERR( PRDF_FUNC "SPD data size too small (%ld, RAW_CARD_EXT %d)",
                    l_size, RawCardExtIdx );
         rc = FAIL;
         break;
      }

      // Get the References Raw Card (bits 4-0)
      // When Reference Raw Card Extension = 0
      //    Reference raw cards A through AL
      // When Reference Raw Card Extension = 1
      //    Reference raw cards AM through CB
      if (l_size > RawCardIdx)
      {
         l_card = (l_blobData[RawCardIdx] & RAW_CARD_MASK);
      }
      else
      {
         PRDF_ERR( PRDF_FUNC "SPD data size too small (%d, RAW_CARD %d)",
                    l_size, RawCardIdx );
         rc = FAIL;
         break;
      }

      // Raw Card = 0x1f(ZZ) means no JEDEC reference raw card design used.
      // Have one ZZ in the return merged enumeration.
      if (0x1f == l_card)
      {
          l_cardExt = 1;  //Just one ZZ in the enumeration (0x3f)
      }

      // Merge into a single enumeration
      o_rawCard = (l_cardExt << 5) | l_card;

    } while (0);

    free(l_blobData);

    return rc;
#undef PRDF_FUNC
}

//------------------------------------------------------------------------------

template<>
CEN_SYMBOL::WiringType getMemBufRawCardType<TYPE_MBA>( TargetHandle_t i_trgt )
{
    #define PRDF_FUNC "[PlatServices::getMemBufRawCardType] "

    PRDF_ASSERT( nullptr != i_trgt );
    PRDF_ASSERT( TYPE_MBA == getTargetType(i_trgt) );

    // Ensure invalid card type if something fails.
    CEN_SYMBOL::WiringType o_cardType = CEN_SYMBOL::WIRING_INVALID;

    do
    {
        // Must be a custom DIMM with Centaur chip.
        if ( !isMembufOnDimm<TYPE_MBA>(i_trgt) ) break;

        TargetHandleList l_dimmList = getConnected( i_trgt, TYPE_DIMM );
        PRDF_ASSERT( 0 != l_dimmList.size() ); // MBA configured with no DIMMs

        // All logical DIMMs connected to this MBA are on the same card as the
        // MBA so we can use any connected DIMM to query for the raw card type.
        uint8_t l_cardType;
        if ( SUCCESS != getSpdModspecComRefRawCard(l_dimmList[0], l_cardType) )
        {
            PRDF_ERR( PRDF_FUNC "getSpdModspecComRefRawCard(0x%08x) failed",
                      getHuid(l_dimmList[0]) );
            break;
        }

        uint8_t l_version = getDramGen<TYPE_MBA>( i_trgt );

        // Centaur raw card types are only used for DRAM site locations. If an
        // invalid wiring type is passed to the error log parser, the parser
        // will simply print out the symbol and other data instead of
        // translating it into a DRAM site location. Therefore, do not fail out
        // if the raw card is currently not supported. Otherwise, there may be
        // some downstream effects to the functional (non-parsing) code for
        // data that is only needed for parsing.

        switch ( l_cardType )
        {
            case SPD_MODSPEC_COM_REF_RAW_CARD_A:
                if (CEN_EFF_DRAM_GEN_DDR3 == l_version)
                {
                    o_cardType = CEN_SYMBOL::CEN_TYPE_A;
                }
                else if (CEN_EFF_DRAM_GEN_DDR4 == l_version)
                {
                    o_cardType = CEN_SYMBOL::CEN_TYPE_A4;
                }
                break;

            case SPD_MODSPEC_COM_REF_RAW_CARD_B:
                if (CEN_EFF_DRAM_GEN_DDR3 == l_version)
                {
                    o_cardType = CEN_SYMBOL::CEN_TYPE_B;
                }
                else if (CEN_EFF_DRAM_GEN_DDR4 == l_version)
                {
                    o_cardType = CEN_SYMBOL::CEN_TYPE_B4;
                }
                break;

            case SPD_MODSPEC_COM_REF_RAW_CARD_C:
                if (CEN_EFF_DRAM_GEN_DDR3 == l_version)
                {
                    o_cardType = CEN_SYMBOL::CEN_TYPE_C;
                }
                else if (CEN_EFF_DRAM_GEN_DDR4 == l_version)
                {
                    o_cardType = CEN_SYMBOL::CEN_TYPE_C4;
                }
                break;

            case SPD_MODSPEC_COM_REF_RAW_CARD_D:
                if (CEN_EFF_DRAM_GEN_DDR3 == l_version)
                {
                    o_cardType = CEN_SYMBOL::CEN_TYPE_D;
                }
                else if (CEN_EFF_DRAM_GEN_DDR4 == l_version)
                {
                    o_cardType = CEN_SYMBOL::CEN_TYPE_D4;
                }
                break;

            default:
                PRDF_INF( PRDF_FUNC "Unsupported card type 0x%02x or DRAM "
                          "version 0x%02x on DIMM 0x%08x", l_cardType,
                          l_version, getHuid(l_dimmList[0]) );
        }

    } while(0);

    return o_cardType;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

} // end namespace PlatServices

} // end namespace PRDF

