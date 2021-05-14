/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfPaucPlugins.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

// Framework includes
#include <iipServiceDataCollector.h>
#include <iipSystem.h>
#include <prdfExtensibleChip.H>
#include <prdfGlobal_common.H>
#include <prdfPluginMap.H>

// Platform includes
#include <prdfMemUtils.H>
#include <prdfPlatServices.H>
#include <prdfMemExtraSig.H>
#include <prdfP10IohsExtraSig.H>
#ifndef ESW_SIM_COMPILE
#include <fapi2.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_pauc
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Calls out the connected peer proc of this PAUC through the IOHS
 * @param  i_chip A PAUC chip.
 * @param  io_sc  The step code data struct.
 * @param  i_iohs Position of the connected IOHS (0:1)
 * @return SUCCESS
 */
int32_t __calloutConnectedPeerProcFromIohs( ExtensibleChip * i_chip,
                                            STEP_CODE_DATA_STRUCT& io_sc,
                                            uint8_t i_iohs )
{
    ExtensibleChip * iohs = getConnectedChild( i_chip, TYPE_IOHS, i_iohs );
    TargetHandle_t peerIohs = getConnectedPeerTarget( iohs->getTrgt() );
    TargetHandle_t peerProc = getConnectedParent( peerIohs, TYPE_PROC );

    io_sc.service_data->SetCallout( peerProc, MRU_MEDA );

    return SUCCESS;
}

#define PLUGIN_CALLOUT_PEER_PROC_IOHS( POS ) \
int32_t calloutConnectedPeerProcFromIohs_##POS( ExtensibleChip * i_chip, \
        STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return __calloutConnectedPeerProcFromIohs( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_pauc, calloutConnectedPeerProcFromIohs_##POS );

PLUGIN_CALLOUT_PEER_PROC_IOHS( 0 );
PLUGIN_CALLOUT_PEER_PROC_IOHS( 1 );

/**
 * @brief  Calls out the connected peer proc of this PAUC through the SMPGROUP
 * @param  i_chip A PAUC chip.
 * @param  io_sc  The step code data struct.
 * @param  i_link Position of the connected SMPGROUP (0:3)
 * @return SUCCESS
 */
int32_t __calloutPeerProcFromSmpgroup( ExtensibleChip * i_chip,
                                       STEP_CODE_DATA_STRUCT& io_sc,
                                       uint8_t i_link )
{
    #define PRDF_FUNC "[p10_pauc::__calloutPeerProcFromSmpgroup] "

    PRDF_ASSERT(nullptr != i_chip);
    PRDF_ASSERT(TYPE_PAUC == i_chip->getType());
    PRDF_ASSERT(i_link < MAX_LINK_PER_PAUC);

    // Get the peer SMPGROUP
    TargetHandle_t smpgroup = getConnectedChild( i_chip->getTrgt(),
                                                 TYPE_SMPGROUP, i_link );
    TargetHandle_t peerSmp = getConnectedPeerTarget( smpgroup );

    if ( nullptr != peerSmp )
    {
        // Get and callout the peer proc
        TargetHandle_t peerProc = getConnectedParent( peerSmp, TYPE_PROC );
        io_sc.service_data->SetCallout( peerProc, MRU_MEDA );
    }
    else
    {
        PRDF_TRAC( PRDF_FUNC "No peer target found for SMPGROUP 0x%08x",
                   getHuid(smpgroup) );
    }

    return SUCCESS;

    #undef PRDF_FUNC
}

#define PLUGIN_CALLOUT_PEER_PROC_SMPGROUP( POS ) \
int32_t calloutPeerProcFromSmpgroup_##POS( ExtensibleChip * i_chip, \
                                           STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return __calloutPeerProcFromSmpgroup( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_pauc, calloutPeerProcFromSmpgroup_##POS );

PLUGIN_CALLOUT_PEER_PROC_SMPGROUP( 0 );
PLUGIN_CALLOUT_PEER_PROC_SMPGROUP( 1 );
PLUGIN_CALLOUT_PEER_PROC_SMPGROUP( 2 );
PLUGIN_CALLOUT_PEER_PROC_SMPGROUP( 3 );


/**
 * @brief  Checks for framer (fmr) errors flagged in the peer trgt, calls out
 *         peer proc if fmr errors are present, else calls out both peer and
 *         parent proc
 * @param  i_chip A PAUC chip.
 * @param  io_sc  The step code data struct.
 * @param  i_link Position of the connected SMPGROUP (0:3)
 * @return SUCCESS
 */
int32_t __checkPeerFmrErrs( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT& io_sc,
                            uint8_t i_link )
{
    #define PRDF_FUNC "[p10_pauc::__checkPeerFmrErrs] "

    PRDF_ASSERT(nullptr != i_chip);
    PRDF_ASSERT(TYPE_PAUC == i_chip->getType());
    PRDF_ASSERT(i_link < MAX_LINK_PER_PAUC);

    // Get the peer SMPGROUP target
    TargetHandle_t smpgroup = getConnectedChild( i_chip->getTrgt(),
                                                 TYPE_SMPGROUP, i_link );
    TargetHandle_t peerSmp = getConnectedPeerTarget( smpgroup );

    // If we can't get the peer target, just callout this proc
    if ( nullptr == peerSmp )
    {
        PRDF_TRAC( PRDF_FUNC "No peer SMPGROUP found for 0x%08x",
                   getHuid(smpgroup) );
        TargetHandle_t parentProc = getConnectedParent( i_chip->getTrgt(),
                                                        TYPE_PROC );
        io_sc.service_data->SetCallout( parentProc, MRU_MED );
        return SUCCESS;
    }

    // Always callout the peer proc
    TargetHandle_t peerProc = getConnectedParent( peerSmp, TYPE_PROC );
    io_sc.service_data->SetCallout( peerProc, MRU_MEDA );

    // Get the PB_FM0123_ERR register on the peer PAUC to check for fmr errors
    TargetHandle_t peerPauc = getConnectedParent( peerSmp, TYPE_PAUC );
    ExtensibleChip * paucChip = (ExtensibleChip *)systemPtr->GetChip(peerPauc);

    SCAN_COMM_REGISTER_CLASS * pb_fm0123_err =
        paucChip->getRegister( "PB_FM0123_ERR" );

    if ( SUCCESS == pb_fm0123_err->Read() )
    {
        uint8_t peerSmpPos = getTargetPosition(peerSmp) % MAX_LINK_PER_PAUC;
        uint8_t fmrBitPos = peerSmpPos * 16; // fmr0 = 0:15, fmr1 = 16:31, etc
        if ( 0 == pb_fm0123_err->GetBitFieldJustified( fmrBitPos, 16 ) )
        {
            // No equivalent fmr errors found on peer target, callout the parent
            // proc as well.
            TargetHandle_t parentProc = getConnectedParent( i_chip->getTrgt(),
                                                            TYPE_PROC );
            io_sc.service_data->SetCallout( parentProc, MRU_MEDA );
        }
        else
        {
            PRDF_TRAC( PRDF_FUNC "Framer errors found on peer target. Only "
                       "calling out peer proc." );
        }
    }

    return SUCCESS;

    #undef PRDF_FUNC
}

#define PLUGIN_CHECK_PEER_FMR_ERRS( POS ) \
int32_t checkPeerFmrErrs_##POS( ExtensibleChip * i_chip, \
                                STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return __checkPeerFmrErrs( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_pauc, checkPeerFmrErrs_##POS );

PLUGIN_CHECK_PEER_FMR_ERRS( 0 );
PLUGIN_CHECK_PEER_FMR_ERRS( 1 );
PLUGIN_CHECK_PEER_FMR_ERRS( 2 );
PLUGIN_CHECK_PEER_FMR_ERRS( 3 );

/**
 * @brief  Calls out an entire SMPGROUP bus with the given link.
 * @param  i_chip A PAUC chip
 * @param  io_sc  The step code data struct.
 * @param  i_link Position of the connected SMPGROUP (0:3)
 * @return SUCCESS always.
 */
int32_t __smp_callout( ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc,
                       uint8_t i_link )
{
    #define PRDF_FUNC "[p10_pauc::__smp_callout] "

    PRDF_ASSERT(nullptr != i_chip);
    PRDF_ASSERT(TYPE_PAUC == i_chip->getType());
    PRDF_ASSERT(i_link < MAX_LINK_PER_PAUC);

    // Get the connected IOHS (0:1)
    uint8_t iohsPos = i_link / 2;
    ExtensibleChip * iohs = getConnectedChild( i_chip, TYPE_IOHS, iohsPos );

    // Get the position of the connected SMPGROUP from the IOHS perspective
    uint8_t iohsLink = i_link % 2;

    return smp_callout( iohs, io_sc, iohsLink );

    #undef PRDF_FUNC
}

#define PLUGIN_PAUC_SMP_CALLOUT( POS ) \
int32_t smp_callout_##POS( ExtensibleChip * i_chip, \
                           STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return __smp_callout( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_pauc, smp_callout_##POS );

PLUGIN_PAUC_SMP_CALLOUT( 0 );
PLUGIN_PAUC_SMP_CALLOUT( 1 );
PLUGIN_PAUC_SMP_CALLOUT( 2 );
PLUGIN_PAUC_SMP_CALLOUT( 3 );

/**
 * @brief  For use with CRC root cause bits in the PAU_PHY_FIR, this will leave
 *         the FIR bit on, but still mask it once it has hit threshold.
 * @param  i_chip A PAUC chip
 * @param  io_sc  The step code data struct.
 * @param  i_bit  The bit in the PAU_PHY_FIR to mask but not clear.
 * @return PRD_NO_CLEAR_FIR_BITS if at threshold, SUCCESS otherwise.
 */
int32_t __crcRootCause( ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc,
                        uint8_t i_bit )
{
    #define PRDF_FUNC "[p10_pauc::CrcRootCause] "

    PRDF_ASSERT(nullptr != i_chip);
    PRDF_ASSERT(TYPE_PAUC == i_chip->getType());

    #ifdef __HOSTBOOT_MODULE
    // Mask the bit in the PAU_PHY_FIR manually if we're at threshold
    if ( io_sc.service_data->IsAtThreshold() )
    {
        SCAN_COMM_REGISTER_CLASS * mask_or =
            i_chip->getRegister( "PAU_PHY_FIR_MASK_OR" );

        mask_or->SetBit(i_bit);
        if ( SUCCESS != mask_or->Write() )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed for PAU_PHY_FIR_MASK_OR on "
                      "0x%08x", i_chip->getHuid() );
        }

        // Return PRD_NO_CLEAR_FIR_BITS so the rule code doesn't clear the bit
        return PRD_NO_CLEAR_FIR_BITS;
    }
    #endif

    return SUCCESS;

    #undef PRDF_FUNC
}

#define PLUGIN_CRC_ROOT_CAUSE( POS ) \
int32_t CrcRootCause_##POS( ExtensibleChip * i_chip, \
                            STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return __crcRootCause( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( p10_pauc, CrcRootCause_##POS );

PLUGIN_CRC_ROOT_CAUSE( 2 );
PLUGIN_CRC_ROOT_CAUSE( 3 );
PLUGIN_CRC_ROOT_CAUSE( 6 );
PLUGIN_CRC_ROOT_CAUSE( 7 );
PLUGIN_CRC_ROOT_CAUSE( 9 );
PLUGIN_CRC_ROOT_CAUSE( 10 );
PLUGIN_CRC_ROOT_CAUSE( 11 );
PLUGIN_CRC_ROOT_CAUSE( 12 );
PLUGIN_CRC_ROOT_CAUSE( 13 );
PLUGIN_CRC_ROOT_CAUSE( 14 );
PLUGIN_CRC_ROOT_CAUSE( 19 );
PLUGIN_CRC_ROOT_CAUSE( 22 );
PLUGIN_CRC_ROOT_CAUSE( 23 );

} // end namespace p10_pauc

} // end namespace PRDF

