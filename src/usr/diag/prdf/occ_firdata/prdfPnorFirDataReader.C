/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/occ_firdata/prdfPnorFirDataReader.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#include <prdfPnorFirDataReader.H>

#include <iipCaptureData.h>
#include <prdfGlobal.H>
#include <prdfPfa5Data.h>
#include <prdfPlatServices.H>
#include <prdfRasServices.H>
#include <prdfTrace.H>
#include <UtilHash.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

//------------------------------------------------------------------------------

PnorFirDataReader & PnorFirDataReader::getPnorFirDataReader()
{
    return PRDF_GET_SINGLETON( PnorFirData );
}

//------------------------------------------------------------------------------

errlHndl_t PnorFirDataReader::readPnor( bool & o_validData )
{
    errlHndl_t errl = readPnorFirData( o_validData, iv_trgtRegMap, iv_ffdc,
                                       iv_trgtFfdcMap );
    if ( NULL != errl )
    {
        errl->collectTrace( PRDF_COMP_NAME, 512 );
    }
    return errl;
}

//------------------------------------------------------------------------------

errlHndl_t PnorFirDataReader::clearPnor() const
{
    errlHndl_t errl = clearPnorFirData();
    if ( NULL != errl )
    {
        errl->collectTrace( PRDF_COMP_NAME, 512 );
    }
    return errl;
}

//------------------------------------------------------------------------------

void PnorFirDataReader::getScom( TargetHandle_t i_trgt,
                                 uint64_t i_addr, uint64_t & o_val ) const
{
    o_val = 0;

    PnorTrgtMap::const_iterator trgtItr = iv_trgtRegMap.find( i_trgt );
    if ( iv_trgtRegMap.end() != trgtItr )
    {
        const PnorRegMap & regMap = trgtItr->second;

        PnorRegMap::const_iterator regItr = regMap.find( i_addr );
        if ( regMap.end() != regItr )
        {
            o_val = regItr->second;
        }
    }
}

//------------------------------------------------------------------------------

void PnorFirDataReader::putScom( TargetHandle_t i_trgt,
                                 uint64_t i_addr, uint64_t i_val )
{
    iv_trgtRegMap[i_trgt][i_addr] = i_val;
}

//------------------------------------------------------------------------------

void PnorFirDataReader::addFfdc( errlHndl_t io_errl ) const
{
    size_t u16 = sizeof(uint16_t);
    size_t u32 = sizeof(uint32_t);

    uint32_t trgtFfdcMapCnt = iv_trgtFfdcMap.size();

    if ( 0 != trgtFfdcMapCnt || iv_ffdc.full )
    {
        size_t sz_data = u32 + ((u32 + u16) * trgtFfdcMapCnt);
        uint8_t data[sz_data];

        data[0] = iv_ffdc.trgts;
        data[1] = (iv_ffdc.full ? 1 : 0) << 7;  // 1:7 reserved
        data[2] = 0;                            // 0:7 reserved
        data[3] = trgtFfdcMapCnt;

        uint32_t idx = 4;
        for ( PnorTrgtFfdcMap::const_iterator it = iv_trgtFfdcMap.begin();
              it != iv_trgtFfdcMap.end(); ++it )
        {
            HUID huid = getHuid(it->first);
            memcpy( &data[idx], &huid,                  u32 ); idx += u32;
            memcpy( &data[idx], &(it->second.scomErrs), u16 ); idx += u16;
        }

        BIT_STRING_ADDRESS_CLASS bs ( 0, sz_data * 8, (CPU_WORD *)&data );

        CaptureData cd;
        cd.Add( getSystemTarget(), Util::hashString("OCC_CS_FFDC"), bs );
        ErrDataService::AddCapData( cd, io_errl );
    }
}

//------------------------------------------------------------------------------

} // end namespace PRDF

