/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/cen/prdfCenMba_common.C $       */
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
#include <prdfCenMbaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace cen_mba
{

//##############################################################################
//
//                             Special plugins
//
//##############################################################################

/**
 * @brief  Plugin that initializes the data bundle.
 * @param  i_mbaChip An MBA chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_mbaChip )
{
    i_mbaChip->getDataBundle() = new MbaDataBundle( i_mbaChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( cen_mba, Initialize );

//##############################################################################
//
//                             MBACALFIR
//
//##############################################################################

void __calloutDimmsOnPort( ExtensibleChip * i_chip, uint32_t i_port,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    for ( auto & dimm : getConnected(i_chip->getTrgt(), TYPE_DIMM) )
    {
        if ( getDimmPort(dimm) == i_port )
            io_sc.service_data->SetCallout( dimm, MRU_MEDA );
    }
}

/**
 * @brief  Adds all DIMMs connected to MBA port 0 to the callout list.
 * @param  i_chip MBA chip
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t CalloutDimmsOnPort0( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    __calloutDimmsOnPort( i_chip, 0, io_sc );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( cen_mba, CalloutDimmsOnPort0 );

/**
 * @brief  Adds all DIMMs connected to MBA port 1 to the callout list.
 * @param  i_chip MBA chip
 * @param  io_sc  The step code data struct.
 * @return SUCCESS
 */
int32_t CalloutDimmsOnPort1( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc )
{
    __calloutDimmsOnPort( i_chip, 1, io_sc );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( cen_mba, CalloutDimmsOnPort1 );

/**
 * @brief  Masks the all side effect attentions of an RCD parity error.
 * @param  i_mbaChip MBA chip
 * @param  io_sc     The step code data struct.
 * @return SUCCESS
 */
int32_t MaskRcdParitySideEffects( ExtensibleChip * i_mbaChip,
                                  STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[cen_mba::MaskRcdParitySideEffects] "

    uint32_t l_rc = SUCCESS;

    do
    {
        // Don't do anything if this is a checkstop attention.
        if ( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() ) break;

        ExtensibleChip * membChip = getConnectedParent(i_mbaChip, TYPE_MEMBUF);

        SCAN_COMM_REGISTER_CLASS * mbsFir;
        SCAN_COMM_REGISTER_CLASS * mbsFirMaskOr;
        SCAN_COMM_REGISTER_CLASS * mbaCalFir;
        SCAN_COMM_REGISTER_CLASS * mbaCalFirMaskOr;
        SCAN_COMM_REGISTER_CLASS * mbaFir;
        SCAN_COMM_REGISTER_CLASS * mbaFirMaskOr;

        mbsFir          = membChip->getRegister( "MBSFIR"           );
        mbsFirMaskOr    = membChip->getRegister( "MBSFIR_MASK_OR"   );
        mbaCalFir       = i_mbaChip->getRegister("MBACALFIR"        );
        mbaCalFirMaskOr = i_mbaChip->getRegister("MBACALFIR_MASK_OR");
        mbaFir          = i_mbaChip->getRegister("MBAFIR"           );
        mbaFirMaskOr    = i_mbaChip->getRegister("MBAFIR_MASK_OR"   );

        l_rc |= mbsFir->Read();
        l_rc |= mbaCalFir->Read();
        l_rc |= mbaFir->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "FIR read failed for MBA 0x%08x",
                      i_mbaChip->getHuid() );
            break;
        }

        // Mask only if the side effect bit is set.

        if ( mbsFir->IsBitSet(4) ) // internal timeout
        {
            mbsFirMaskOr->SetBit(4);
            l_rc |= mbsFirMaskOr->Write();
        }

        if ( mbaCalFir->IsBitSet(2) ) // refresh overrun
        {
            mbaCalFirMaskOr->SetBit(2);
            l_rc = mbaCalFirMaskOr->Write();
        }

        if ( mbaCalFir->IsBitSet(17) ) // WRQ RRQ hang error
        {
            mbaCalFirMaskOr->SetBit(17);
            l_rc = mbaCalFirMaskOr->Write();
        }

        if ( mbaFir->IsBitSet(2) ) // multi-address maint cmd timeout
        {
            mbaFirMaskOr->SetBit(2);
            l_rc = mbaFirMaskOr->Write();
        }

        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "MASK_OR write failed for MBA 0x%08x",
                      i_mbaChip->getHuid() );
            break;
        }

    } while (0);

    return SUCCESS;

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( cen_mba, MaskRcdParitySideEffects );

//------------------------------------------------------------------------------

} // end namespace cen_mba

} // end namespace PRDF

