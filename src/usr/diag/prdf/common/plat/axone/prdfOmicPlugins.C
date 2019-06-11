/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/axone/prdfOmicPlugins.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include <prdfPluginMap.H>

// Platform includes
#include <prdfPlatServices.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace axone_omic
{

//##############################################################################
//
//                               OMIDLFIR
//
//##############################################################################

/**
 * @brief  OMIDLFIR[0|20|40] - OMI-DL Fatal Error
 * @param  i_chip An OMIC chip.
 * @param  io_sc  The step code data struct.
 * @param  i_dl   The DL relative to the OMIC.
 * @return PRD_SCAN_COMM_REGISTER_ZERO for the bus callout, else SUCCESS
 */
int32_t DlFatalError( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
                      uint8_t i_dl )
{
    #define PRDF_FUNC "[axone_omic::DlFatalError] "

    int32_t rc = SUCCESS;

    do
    {
        char reg[64];
        sprintf( reg, "DL%d_ERROR_HOLD", i_dl );

        // Check DL#_ERROR_HOLD[52:63] to determine callout
        SCAN_COMM_REGISTER_CLASS * dl_error_hold = i_chip->getRegister( reg );

        if ( SUCCESS != dl_error_hold->Read() )
        {
            PRDF_ERR( PRDF_FUNC "Read() Failed on DL%d_ERROR_HOLD: "
                      "i_chip=0x%08x", i_dl, i_chip->getHuid() );
            break;
        }

        if ( dl_error_hold->IsBitSet(53) ||
             dl_error_hold->IsBitSet(55) ||
             dl_error_hold->IsBitSet(57) ||
             dl_error_hold->IsBitSet(58) ||
             dl_error_hold->IsBitSet(59) ||
             dl_error_hold->IsBitSet(60) ||
             dl_error_hold->IsBitSet(62) ||
             dl_error_hold->IsBitSet(63) )
        {
            // Get and callout the OMI target
            ExtensibleChip * omi = getConnectedChild( i_chip, TYPE_OMI, i_dl );
            io_sc.service_data->SetCallout( omi->getTrgt() );
        }
        else if ( dl_error_hold->IsBitSet(54) ||
                  dl_error_hold->IsBitSet(56) ||
                  dl_error_hold->IsBitSet(61) )
        {
            // callout the OMI target, the OMI bus, and the OCMB
            // Return PRD_SCAN_COMM_REGISTER_ZERO so the rule code makes
            // the appropriate callout.
            rc = PRD_SCAN_COMM_REGISTER_ZERO;
        }

    }while(0);

    return rc;

    #undef PRDF_FUNC
}

#define DL_FATAL_ERROR_PLUGIN( POS ) \
int32_t DlFatalError_##POS( ExtensibleChip * i_chip, \
                            STEP_CODE_DATA_STRUCT & io_sc ) \
{ \
    return DlFatalError( i_chip, io_sc, POS ); \
} \
PRDF_PLUGIN_DEFINE( axone_omic, DlFatalError_##POS );

DL_FATAL_ERROR_PLUGIN( 0 );
DL_FATAL_ERROR_PLUGIN( 1 );
DL_FATAL_ERROR_PLUGIN( 2 );

} // end namespace axone_omic

} // end namespace PRDF
