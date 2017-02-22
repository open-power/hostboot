/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemCaptureData.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <prdfErrlUtil.H>

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

    // Add CE table to capture data.
    db->iv_ceTable.addCapData( cd );

    // Add UE table to capture data.
    db->iv_ueTable.addCapData( cd );
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

void addExtMemMruData( const MemoryMru & i_memMru, errlHndl_t io_errl )
{
    #define PRDF_FUNC "[addExtMemMruData] "

    MemoryMruData::ExtendedData extMemMru ( i_memMru.toUint32() );

    do
    {
        int32_t l_rc = SUCCESS;

        TargetHandle_t trgt = i_memMru.getTrgt();

        // Get the DRAM width.
        extMemMru.isX4Dram = isDramWidthX4( trgt ) ? 1 : 0;

        // Get the DIMM type.
        bool isBufDimm = false;
        l_rc = isMembufOnDimm( trgt, isBufDimm );
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "isMembufOnDimm() failed. Trgt:0x%08x",
                      getHuid(trgt) );
            break;
        }
        extMemMru.isBufDimm = isBufDimm ? 1 : 0;

        if ( isBufDimm )
        {
            // TODO RTC 169956
            //// Get the raw card type (Centaur DIMMs only).
            //CEN_SYMBOL::WiringType cardType = CEN_SYMBOL::WIRING_INVALID;
            //l_rc = getMemBufRawCardType( trgt, cardType );
            //if ( SUCCESS != l_rc )
            //{
            //    PRDF_ERR( PRDF_FUNC "getMemBufRawCardType() failed. MBA:0x%08x",
            //              getHuid(trgt) );
            //    break;
            //}
            //extMemMru.cardType = cardType;
        }
        else
        {
            // Get the 80-byte DQ map (ISDIMMs only). This is only needed if the
            // MemoryMru contains a single DIMM callout with a valid symbol.
            if ( i_memMru.getSymbol().isValid() )
            {
                TargetHandleList partList = i_memMru.getCalloutList();
                if ( 1 != partList.size() ||
                     TYPE_DIMM != getTargetType(partList[0]) )
                {
                    PRDF_ERR( PRDF_FUNC "Symbol is valid but callout is not a "
                              "single DIMM." );
                    break;
                }
                getDimmDqAttr( trgt, extMemMru.dqMapping );
            }
        }

        // If we reach this point, nothing failed and the data is valid.
        extMemMru.isValid = 1;

    }while(0);

    size_t sz_buf = sizeof(extMemMru);
    BitStringBuffer bsb( sz_buf*8 );
    uint32_t curPos = 0;

    bsb.setFieldJustify( curPos, 32, extMemMru.mmMeld.u  ); curPos+=32;
    bsb.setFieldJustify( curPos,  8, extMemMru.cardType  ); curPos+= 8;
    bsb.setFieldJustify( curPos,  1, extMemMru.isBufDimm ); curPos+= 1;
    bsb.setFieldJustify( curPos,  1, extMemMru.isX4Dram  ); curPos+= 1;
    bsb.setFieldJustify( curPos,  1, extMemMru.isValid   ); curPos+= 1;

    BitString bs( sizeof(extMemMru.dqMapping)*8,
                  (CPU_WORD *)extMemMru.dqMapping );
    bsb.setString( bs, 0, bs.getBitLen(), curPos );

    // Add the extended MemoryMru to the error log.
    PRDF_ADD_FFDC( io_errl, bsb.getBufAddr(), sz_buf, ErrlVer1, ErrlMruData );

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

}  //end namespace MemCaptureData

} // end namespace PRDF

