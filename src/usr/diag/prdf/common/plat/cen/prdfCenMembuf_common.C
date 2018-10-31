/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/cen/prdfCenMembuf_common.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#include <prdfExtensibleChip.H>
#include <prdfPluginDef.H>
#include <prdfPluginMap.H>
#include <UtilHash.H> // for Util::hashString

// Platform includes
#include <prdfCenMbaDataBundle.H>
#include <prdfCenMembufDataBundle.H>
#include <prdfMemEccAnalysis.H>
#include <prdfMemUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace centaur_membuf
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the data bundle.
 * @param  i_chip A MEMBUF chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_chip )
{
    i_chip->getDataBundle() = new MembufDataBundle( i_chip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( centaur_membuf, Initialize );

/**
 * @brief  Analysis code that is called before the main analyze() function.
 * @param  i_chip     A MEMBUF chip.
 * @param  io_sc      The step code data struct.
 * @param  o_analyzed True if analysis is done on this chip, false otherwise.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t PreAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                     bool & o_analyzed )
{
    // The hardware team requested that we capture the MCFIR in the FFDC.
    ExtensibleChip * dmiChip = getConnectedParent( i_chip,  TYPE_DMI );
    ExtensibleChip * miChip  = getConnectedParent( dmiChip, TYPE_MI  );
    miChip->CaptureErrorData( io_sc.service_data->GetCaptureData(),
                              Util::hashString("MirrorConfig") );

    // Check for a channel failure before analyzing this chip.
    o_analyzed = MemUtils::analyzeChnlFail<TYPE_MEMBUF>( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( centaur_membuf, PreAnalysis );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_chip A MEMBUF chip.
 * @param  io_sc  The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    // Cleanup processor FIR bits on the other side of the channel.
    MemUtils::cleanupChnlAttns<TYPE_MEMBUF>( i_chip, io_sc );

    // If there was a channel failure some cleanup is required to ensure
    // there are no more attentions from this channel.
    MemUtils::cleanupChnlFail<TYPE_MEMBUF>( i_chip, io_sc );

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( centaur_membuf, PostAnalysis );

/**
 * @brief  During system or unit checkstop analysis, this is used to determine
 *         if a chip has any active recoverable attentions.
 * @param  i_chip     A MEMBUF chip.
 * @param  o_hasAttns True if a recoverable attention exists on the Centaur.
 * @return SUCCESS.
 */
int32_t CheckForRecovered( ExtensibleChip * i_chip, bool & o_hasAttns )
{
    o_hasAttns = false;

    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister("GLOBAL_RE_FIR");
    if ( SUCCESS != reg->Read() )
    {
        PRDF_ERR( "[CheckForRecovered] GLOBAL_RE_FIR read failed on 0x%08x",
                  i_chip->getHuid() );
    }
    else if ( 0 != reg->GetBitFieldJustified(1,3) )
    {
        o_hasAttns = true;
    }

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( centaur_membuf, CheckForRecovered );

/**
 * @brief  During system checkstop analysis, this is used to determine if a chip
 *         has any active unit checkstop attentions.
 * @param  i_chip     A MEMBUF chip.
 * @param  o_hasAttns True if a recoverable attention exists on the Centaur.
 * @return SUCCESS.
 */
int32_t CheckForUnitCs( ExtensibleChip * i_chip, bool & o_hasAttns )
{
    o_hasAttns = false;

    // Note that Centaur checkstop attentions are all reported as unit
    // checkstops and they do not directly trigger system checkstops.

    SCAN_COMM_REGISTER_CLASS * reg = i_chip->getRegister("GLOBAL_CS_FIR");
    if ( SUCCESS != reg->Read() )
    {
        PRDF_ERR( "[CheckForUnitCs] GLOBAL_CS_FIR read failed on 0x%08x",
                  i_chip->getHuid() );
    }
    else if ( 0 != reg->GetBitFieldJustified(1,3) )
    {
        o_hasAttns = true;
    }

    return SUCCESS;

} PRDF_PLUGIN_DEFINE( centaur_membuf, CheckForUnitCs );

//##############################################################################
//
//                                  MBSFIR
//
//##############################################################################

/**
 * @brief  Calls analyze() on the target MBA if there is an active RCD parity
 *         error.
 * @param  i_mbChip MEMBUF chip.
 * @param  io_sc    Step code data struct
 * @param  i_mbaPos The MBA position relative to the MEMBUF.
 * @return SUCCESS if the RCD parity error was present and analyzed properly.
 *         Non-SUCCESS otherwise.
 */
int32_t analyzeMbaRcdParityError( ExtensibleChip * i_mbChip,
                                  STEP_CODE_DATA_STRUCT & io_sc,
                                  uint32_t i_mbaPos )
{
    #define PRDF_FUNC "[analyzeMbaRcdParityError] "

    int32_t o_rc = PRD_SCAN_COMM_REGISTER_ZERO; // default, nothing found

    do
    {
        ExtensibleChip * mbaChip = getConnectedChild( i_mbChip, TYPE_MBA,
                                                      i_mbaPos );
        if ( nullptr == mbaChip )
        {
            o_rc = PRD_UNRESOLVED_CHIP_CONNECTION; // no chip
            break;
        }

        SCAN_COMM_REGISTER_CLASS * fir = mbaChip->getRegister("MBACALFIR");
        SCAN_COMM_REGISTER_CLASS * msk = mbaChip->getRegister("MBACALFIR_MASK");

        int32_t l_rc = fir->Read() | msk->Read();

        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "register read failed on 0x%08x",
                      mbaChip->getHuid() );
            o_rc = l_rc; // proper return code from SCOM error.
            break;
        }

        // If any of the MBACALFIR parity error bits are set, analyze the MBA.
        if ( ( fir->IsBitSet(4) && !msk->IsBitSet(4) ) ||
             ( fir->IsBitSet(7) && !msk->IsBitSet(7) ) )
        {
            o_rc = mbaChip->Analyze( io_sc,
                                io_sc.service_data->getSecondaryAttnType() );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( centaur_membuf, analyzeMbaRcdParityError );

// Define the plugins for RCD parity error memory UE side-effects
#define PLUGIN_RCD_PARITY_UE_SIDEEFFECTS( MBA ) \
int32_t analyzeMbaRcdParityError##MBA( ExtensibleChip * i_mbChip, \
                                       STEP_CODE_DATA_STRUCT & io_sc) \
{ \
    return analyzeMbaRcdParityError( i_mbChip, io_sc, MBA ); \
} \
PRDF_PLUGIN_DEFINE( centaur_membuf, analyzeMbaRcdParityError##MBA );

PLUGIN_RCD_PARITY_UE_SIDEEFFECTS( 0 )
PLUGIN_RCD_PARITY_UE_SIDEEFFECTS( 1 )

#undef PLUGIN_RCD_PARITY_UE_SIDEEFFECTS

//------------------------------------------------------------------------------

/**
 * @brief  Clears and ignores MBSFIR[3:4] if both are on at the same time. Masks
 *         them at threshold of 32 per day.
 * @param  i_mbChip MEMBUF chip.
 * @param  io_sc    Step code data struct
 * @return SUCCESS if both MBSFIR[3] and MBSFIR[4] are on.
 *         PRD_SCAN_COMM_REGISTER_ZERO if not.
 */
int32_t mbsInternalTimeoutPrecheck( ExtensibleChip * i_mbChip,
                                    STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[mbsInternalTimeoutPrecheck] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Get MBSFIR
        SCAN_COMM_REGISTER_CLASS * mbsFir = i_mbChip->getRegister("MBSFIR");

        o_rc = mbsFir->Read();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MBSFIR read failed for 0x%08x",
                      i_mbChip->getHuid() );
            break;
        }

        if ( mbsFir->IsBitSet(3) && mbsFir->IsBitSet(4) )
        {
            // We are going to ignore this attention. If there is a system
            // checkstop, we will have to return a DD02 so that the rule code
            // can try to find something else as the root cause. Otherwise,
            // apply the "threshold and mask" policy.

            if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() )
            {
                o_rc = PRD_SCAN_COMM_REGISTER_ZERO;
            }
            else
            {
                // Add Centaur callout just in case.
                io_sc.service_data->SetCallout( i_mbChip->getTrgt() );

                // Clear MBSFIR[3:4].
                SCAN_COMM_REGISTER_CLASS * mbsFirAnd =
                    i_mbChip->getRegister("MBSFIR_AND");

                mbsFirAnd->setAllBits();
                mbsFirAnd->ClearBit(3);
                mbsFirAnd->ClearBit(4);

                o_rc = mbsFirAnd->Write();
                if ( SUCCESS != o_rc )
                {
                    PRDF_ERR( PRDF_FUNC "MBSFIR_AND write failed for 0x%08x",
                              i_mbChip->getHuid() );
                    break;
                }

                if ( io_sc.service_data->IsAtThreshold() )
                {
                    // Prevent a predictive error, if needed.
                    if ( !mfgMode() && !io_sc.service_data->isMemChnlFail() )
                    {
                        io_sc.service_data->clearServiceCall();
                    }

                    // Mask MBSFIR[3:4].
                    SCAN_COMM_REGISTER_CLASS * mbsFirMaskOr =
                        i_mbChip->getRegister("MBSFIR_MASK_OR");

                    mbsFirMaskOr->SetBit(3);
                    mbsFirMaskOr->SetBit(4);

                    o_rc = mbsFirMaskOr->Write();
                    if ( SUCCESS != o_rc )
                    {
                        PRDF_ERR( PRDF_FUNC "MBSFIR_MASK_OR write failed for "
                                  "0x%08x", i_mbChip->getHuid() );
                        break;
                    }
                }
            }
        }
        else
        {
            // Legitimate internal timeout, make the error log predictive.
            io_sc.service_data->SetCallout( i_mbChip->getTrgt() );
            io_sc.service_data->setServiceCall();
        }

    }while(0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( centaur_membuf, mbsInternalTimeoutPrecheck );

//##############################################################################
//
//                                  MBSECCFIRs
//
//##############################################################################

/**
 * @brief  MBSECCFIR[0:7] - Mailine MPE.
 * @param  i_chip MEMBUF chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_MPE_ERROR( POS, RANK ) \
int32_t AnalyzeFetchMpe##POS##_##RANK( ExtensibleChip * i_chip, \
                                       STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    ExtensibleChip * mbaChip = getConnectedChild( i_chip, TYPE_MBA, POS ); \
    PRDF_ASSERT( nullptr != mbaChip ); \
    MemRank rank { RANK }; \
    MemEcc::analyzeFetchMpe<TYPE_MBA>( mbaChip, rank, io_sc );\
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( centaur_membuf, AnalyzeFetchMpe##POS##_##RANK );

PLUGIN_FETCH_MPE_ERROR( 0, 0 )
PLUGIN_FETCH_MPE_ERROR( 0, 1 )
PLUGIN_FETCH_MPE_ERROR( 0, 2 )
PLUGIN_FETCH_MPE_ERROR( 0, 3 )
PLUGIN_FETCH_MPE_ERROR( 0, 4 )
PLUGIN_FETCH_MPE_ERROR( 0, 5 )
PLUGIN_FETCH_MPE_ERROR( 0, 6 )
PLUGIN_FETCH_MPE_ERROR( 0, 7 )

PLUGIN_FETCH_MPE_ERROR( 1, 0 )
PLUGIN_FETCH_MPE_ERROR( 1, 1 )
PLUGIN_FETCH_MPE_ERROR( 1, 2 )
PLUGIN_FETCH_MPE_ERROR( 1, 3 )
PLUGIN_FETCH_MPE_ERROR( 1, 4 )
PLUGIN_FETCH_MPE_ERROR( 1, 5 )
PLUGIN_FETCH_MPE_ERROR( 1, 6 )
PLUGIN_FETCH_MPE_ERROR( 1, 7 )

#undef PLUGIN_FETCH_MPE_ERROR

//------------------------------------------------------------------------------

/**
 * @brief  MBSECCFIR[16] - Mainline CE.
 * @param  i_chip MEMBUF chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_NCE_ERROR( POS ) \
int32_t AnalyzeFetchNce##POS( ExtensibleChip * i_chip, \
                              STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    ExtensibleChip * mbaChip = getConnectedChild( i_chip, TYPE_MBA, POS ); \
    PRDF_ASSERT( nullptr != mbaChip ); \
    MemEcc::analyzeFetchNceTce<TYPE_MBA>( mbaChip, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( centaur_membuf, AnalyzeFetchNce##POS );

PLUGIN_FETCH_NCE_ERROR( 0 )
PLUGIN_FETCH_NCE_ERROR( 1 )

#undef PLUGIN_FETCH_NCE_ERROR

//------------------------------------------------------------------------------

/**
 * @brief  MBSECCFIR[19] - Mainline UE.
 * @param  i_chip MEMBUF chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_UE_ERROR( POS ) \
int32_t AnalyzeFetchUe##POS( ExtensibleChip * i_chip, \
                             STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    ExtensibleChip * mbaChip = getConnectedChild( i_chip, TYPE_MBA, POS ); \
    PRDF_ASSERT( nullptr != mbaChip ); \
    MemEcc::analyzeFetchUe<TYPE_MBA>( mbaChip, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( centaur_membuf, AnalyzeFetchUe##POS );

PLUGIN_FETCH_UE_ERROR( 0 )
PLUGIN_FETCH_UE_ERROR( 1 )

#undef PLUGIN_FETCH_UE_ERROR

//------------------------------------------------------------------------------

/**
 * @brief  MBSECCFIR[17] - Mainline RCE / MBSECCFIR[43] Prefetch UE.
 * @param  i_chip MEMBUF chip.
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
#define PLUGIN_FETCH_RCE_PUE_ERROR( POS ) \
int32_t AnalyzeFetchRcePue##POS( ExtensibleChip * i_chip, \
                                 STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    ExtensibleChip * mbaChip = getConnectedChild( i_chip, TYPE_MBA, POS ); \
    PRDF_ASSERT( nullptr != mbaChip ); \
    MemEcc::analyzeFetchRcePue<TYPE_MBA>( mbaChip, io_sc ); \
    return SUCCESS; \
} \
PRDF_PLUGIN_DEFINE( centaur_membuf, AnalyzeFetchRcePue##POS );

PLUGIN_FETCH_RCE_PUE_ERROR( 0 )
PLUGIN_FETCH_RCE_PUE_ERROR( 1 )

#undef PLUGIN_FETCH_RCE_PUE_ERROR

//------------------------------------------------------------------------------

} // end namespace centaur_membuf

} // end namespace PRDF

