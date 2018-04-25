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

// Platform includes
#include <prdfMemUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace cen_centaur
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_mbChip A Centaur chip.
 * @param  io_sc    The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_mbChip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[cen_centaur::PostAnalysis] "

    if ( CHECK_STOP != io_sc.service_data->getPrimaryAttnType() )
    {
        // Cleanup processor FIR bits on the other side of the channel.
        if ( SUCCESS != MemUtils::chnlFirCleanup(i_mbChip) )
        {
            PRDF_ERR( PRDF_FUNC "chnlFirCleanup(0x%08x) failed",
                      i_mbChip->getHuid() );
        }
    }

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( cen_centaur, PostAnalysis );

//##############################################################################
//
//                                  MBSFIR
//
//##############################################################################

/**
 * @brief  Calls analyze() on the connected DMI target if there is an active
 *         channel fail attention on the DMI side of the bus.
 * @param  i_mbChip MEMBUF chip.
 * @param  io_sc    Step code data struct
 * @return SUCCESS if the channel fail error was present and analyzed properly.
 *         Non-SUCCESS otherwise.
 */
int32_t analyzeDmiChnlFail( ExtensibleChip * i_mbChip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[analyzeDmiChnlFail] "

    int32_t o_rc = PRD_SCAN_COMM_REGISTER_ZERO; // default, nothing found

    do
    {
        ExtensibleChip * dmiChip = getConnectedParent( i_mbChip, TYPE_DMI );

        // TODO: RTC 136123 Need to call new interface that queries if there was
        //       a channel fail attention on the other side of the interface.
        bool dmiChnlFail = false;

        // If there is a channel fail attention on the other side of the bus,
        // analyze the DMI target.
        if ( dmiChnlFail )
        {
            o_rc = dmiChip->Analyze( io_sc,
                                io_sc.service_data->getSecondaryAttnType() );
        }

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( cen_centaur, analyzeDmiChnlFail );

//------------------------------------------------------------------------------

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
PRDF_PLUGIN_DEFINE( cen_centaur, analyzeMbaRcdParityError );

// Define the plugins for RCD parity error memory UE side-effects
#define PLUGIN_RCD_PARITY_UE_SIDEEFFECTS( MBA ) \
int32_t analyzeMbaRcdParityError##MBA( ExtensibleChip * i_mbChip, \
                                       STEP_CODE_DATA_STRUCT & io_sc) \
{ \
    return analyzeMbaRcdParityError( i_mbChip, io_sc, MBA ); \
} \
PRDF_PLUGIN_DEFINE( cen_centaur, analyzeMbaRcdParityError##MBA );

PLUGIN_RCD_PARITY_UE_SIDEEFFECTS( 0 )
PLUGIN_RCD_PARITY_UE_SIDEEFFECTS( 1 )

#undef PLUGIN_RCD_PARITY_UE_SIDEEFFECTS

//------------------------------------------------------------------------------

} // end namespace cen_centaur

} // end namespace PRDF

