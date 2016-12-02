/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCaptureData.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#include <prdfMemCaptureData.H>

// Framework includes
#include <iipCaptureData.h>

// Platform includes
#include <prdfPlatServices.H>
#include <prdfP9McaDataBundle.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace MemCaptureData
{

//------------------------------------------------------------------------------

template<>
void addEccData<TYPE_MCA>( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MCA == i_chip->getType() );

    CaptureData & cd = io_sc.service_data->GetCaptureData();
    McaDataBundle * db = getMcaDataBundle( i_chip );

    // Add UE table to capture data.
    db->iv_ueTable.addCapData( i_chip, cd );
}

template<>
void addEccData<TYPE_MCBIST>( ExtensibleChip * i_chip,
                              STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MCBIST == i_chip->getType() );

    // Add data for each connected MCA.
    ExtensibleChipList list = getConnected( i_chip, TYPE_MCA );
    for ( auto & mcaChip : list ) { addEccData<TYPE_MCA>(mcaChip, io_sc); }
}

template<>
void addEccData<TYPE_MBA>( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    PRDF_ASSERT( TYPE_MBA == i_chip->getType() );

/* TODO: RTC 157888
    CaptureData & cd = io_sc.service_data->GetCaptureData();
    CenMbaDataBundle * db = getMbaDataBundle( i_chip );

    // Add UE table to capture data.
    db->iv_ueTable.addCapData( i_chip, cd );

    // Add CE table to capture data.
    db->iv_ceTable.addCapData( cd );

    // Add RCE table to capture data.
    db->iv_rceTable.addCapData( cd );

    // Add DRAM repairs data from hardware.
    captureDramRepairsData( i_chip->getTrgt(), cd );

    // Add DRAM repairs data from VPD.
    captureDramRepairsVpd( i_chip->getTrgt(), cd );
*/
}

//------------------------------------------------------------------------------

}  //end namespace MemCaptureData

} // end namespace PRDF

