/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfCaptureData.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
  @file prdfCaptureData.C
  @brief Squadrons implementation of capture data
*/
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <iipbits.h>
#include <prdfHomRegisterAccess.H>  // dg06a
#include <prdfScomRegister.H>
#include <iipchip.h>
#include <iipCaptureData.h>
#include <string.h>
#include <algorithm>    // @jl04 a Add this for the Drop function.

using namespace TARGETING;

namespace PRDF
{

//---------------------------------------------------------------------
// Member Function Specifications
//---------------------------------------------------------------------

CaptureData::CaptureData(void):data()
{
//  data.reserve(INITIAL_DATA_COUNT);
}

// dg05d CaptureData::~CaptureData(void)
// dg05d {
// dg05d   if(!data.empty())
// dg05d   {
// dg05d     Clear();
// dg05d   }
// dg05d }

void CaptureData::Clear(void)
{

  if(!data.empty())
  {
// dg05d   for(DataContainerType::iterator i  = data.begin();i != data.end();i++)
// dg05d   {
// dg05d     delete [] (*i).dataPtr;
// dg05d   }

    data.erase(data.begin(), data.end());

  }                             /* if not empty */
}

//------------------------------------------------------------------------------

void CaptureData::AddDataElement( TargetHandle_t i_trgt, int i_scomId,
                                  const BIT_STRING_CLASS * i_bs,
                                  Place i_place, RegType i_type )
{
    // Initial values of the bit string buffer if i_bs has a zero value.
    uint8_t * buf = NULL;
    size_t sz_buf = 0;

    // Add buffer only if the value is non-zero.
    if ( !i_bs->IsZero() )
    {
        // Get the size of i_bs and ensure byte alignment.
        sz_buf = (i_bs->GetLength() + 8-1) / 8;

        // Since we are using a BitString below, which does everything on a
        // CPU_WORD boundary, we must make sure the buffer is CPU_WORD aligned.
        const size_t sz_word = sizeof(CPU_WORD);
        sz_buf = ((sz_buf + sz_word-1) / sz_word) * sz_word;

        // Allocate memory for the buffer.
        buf = new uint8_t[sz_buf];
        memset( buf, 0x00, sz_buf );

        // Use a BitString to copy i_bs to the buffer.
        BIT_STRING_ADDRESS_CLASS bs ( 0, i_bs->GetLength(), (CPU_WORD *)buf );
        bs.SetBits( *i_bs );

        // Create the new data element.
        Data element( i_trgt, i_scomId, sz_buf, buf );
        element.registerType = i_type;

        // Add the new element to the data.
        if ( FRONT == i_place )
            data.insert( data.begin(), element );
        else
            data.push_back( element );
    }
}

//------------------------------------------------------------------------------

void CaptureData::Add( TargetHandle_t i_trgt, int32_t i_scomId,
                       SCAN_COMM_REGISTER_CLASS & io_scr,
                       Place i_place, RegType i_type )
{
    if ( SUCCESS == io_scr.Read() )
    {
        AddDataElement( i_trgt, i_scomId, io_scr.GetBitString(),
                        i_place, i_type );
    }
}

//------------------------------------------------------------------------------

void CaptureData::Add( TargetHandle_t i_trgt, int i_scomId,
                       const BIT_STRING_CLASS & i_bs, Place i_place )
{
    AddDataElement( i_trgt, i_scomId, &i_bs, i_place );
}

//------------------------------------------------------------------------------

// start jl04a
void CaptureData::Drop(RegType i_type)
{
  //  Function below requires a predicate function above to Drop
  //  a data element from the capture data if it is
  //    defined as secondary data instead of primary data in the rule files.
  //  This predicate has to exist within the CaptureData Class because the
  //  class "Data" is defined within CaptureData class.
  data.erase( std::remove_if(data.begin(),data.end(),
              prdfCompareCaptureDataType(i_type)), data.end() );
}
// end jl04a

//------------------------------------------------------------------------------

/* CaptureData Format:
 *        capture data -> ( <chip header> <registers> )*
 *        chip header -> ( <chip id:32> <# registers:32> )
 *        registers -> ( <reg id:16> <reg byte len:16> <bytes>+ )
 */
unsigned int CaptureData::Copy(uint8_t *i_buffer, unsigned int i_bufferSize) const
{
    TargetHandle_t  l_pcurrentChipHandle =NULL ;
    uint8_t * l_entryCountPos = NULL;
    uint32_t l_regEntries = 0;

    uint32_t l_bytesWritten = 0;
    for (ConstDataIterator i = data.begin(); i != data.end(); i++)
    {
        // Check for new chip.
        if (i->chipHandle != l_pcurrentChipHandle)
        {   // Update previous header, write new header.

            if (NULL != l_entryCountPos) // Update previous entry count.
            {
                l_regEntries = htonl(l_regEntries);
                memcpy(l_entryCountPos, &l_regEntries, sizeof(l_regEntries));
                l_regEntries = 0;
            }

            // Update chip Handles....
            TargetHandle_t l_ptempHandle = l_pcurrentChipHandle = i->chipHandle;
            HUID l_chipHuid =PlatServices::getHuid(l_ptempHandle);
            const size_t l_huidSize = sizeof(l_chipHuid);
            l_chipHuid = htonl(l_chipHuid);

            // Verify space.
            if (i_bufferSize < l_bytesWritten + 2 * l_huidSize)
            {
                break;
            }
            // Write header.
            memcpy(&i_buffer[l_bytesWritten],
                   &l_chipHuid, l_huidSize);
            l_bytesWritten += l_huidSize;
            l_entryCountPos = &i_buffer[l_bytesWritten];
            l_ptempHandle = NULL;
            memcpy(l_entryCountPos, &l_chipHuid, l_huidSize);
            l_bytesWritten += l_huidSize;
        }

        // Go to next entry if 0 data length.
        if (0 == i->dataByteLength)
            continue;

        // Check room.
        if ((l_bytesWritten + 2*sizeof(uint16_t) + i->dataByteLength) >
                i_bufferSize)
            continue;

        // Write register ID.
        uint16_t l_regId = htons(i->address);
        memcpy(&i_buffer[l_bytesWritten], &l_regId, sizeof(l_regId));
        l_bytesWritten += sizeof(l_regId);

        // Write register length.
        uint16_t l_regLen = htons(i->dataByteLength);
        memcpy(&i_buffer[l_bytesWritten], &l_regLen, sizeof(l_regLen));
        l_bytesWritten += sizeof(l_regLen);

        // Write register data.
        uint32_t l_dataWritten = 0;
        while ((l_dataWritten + 4) <= i->dataByteLength)
        {
            uint32_t l_temp32;
            memcpy(&l_temp32, &i->dataPtr[l_dataWritten], sizeof(l_temp32));
            l_temp32 = htonl(l_temp32);
            memcpy(&i_buffer[l_bytesWritten], &l_temp32, 4);
            l_dataWritten += 4; l_bytesWritten += 4;
        }
        if (l_dataWritten != i->dataByteLength)
        {
            uint32_t l_temp32;
            memcpy(&l_temp32, &i->dataPtr[l_dataWritten], sizeof(l_temp32));
            l_temp32 = htonl(l_temp32);
            memcpy(&i_buffer[l_bytesWritten],
                   &l_temp32, i->dataByteLength - l_dataWritten);
            l_bytesWritten += i->dataByteLength - l_dataWritten;
        }

        // Update entry count.
        l_regEntries++;
    }

    // Update previous entry count.
    if (NULL != l_entryCountPos)
    {
        l_regEntries = htonl(l_regEntries);
        memcpy(l_entryCountPos, &l_regEntries, sizeof(l_regEntries));
        l_regEntries = 0;
    }

    return l_bytesWritten;
}

// dg08a -->
CaptureData & CaptureData::operator=(const uint8_t *i_flatdata)
{
    uint32_t l_tmp32 = 0;
    uint16_t l_tmp16 = 0;

    HUID  l_chipHuid = INVALID_HUID;
    const size_t l_huidSize = sizeof(l_chipHuid);

    // Read size.
    memcpy(&l_tmp32, i_flatdata, sizeof(uint32_t));
    uint32_t size = ntohl(l_tmp32);
    i_flatdata += sizeof(uint32_t);

    Clear();

    // Calculate end of buffer.
    const uint8_t *eptr = i_flatdata + size;

    while(i_flatdata < eptr)
    {
        // Read chip Handle.
        memcpy(&l_chipHuid , i_flatdata,l_huidSize );
        i_flatdata += l_huidSize ;
        TargetHandle_t l_pchipHandle  =NULL;
        l_chipHuid =  ntohl(l_chipHuid);
        l_pchipHandle = PlatServices::getTarget(l_chipHuid );
        if(NULL ==l_pchipHandle)
        {
            continue;
        }

        // Read # of entries.
        memcpy(&l_tmp32, i_flatdata, sizeof(uint32_t));
        i_flatdata += sizeof(l_tmp32);
        uint32_t entries = ntohl(l_tmp32);

        // Input each entry.
        for(uint32_t i = 0; i < entries; ++i)
        {
            // Read register id.
            memcpy(&l_tmp16, i_flatdata, sizeof(uint16_t));
            i_flatdata += sizeof(uint16_t);
            int regid = ntohs(l_tmp16);

            // Read byte count.
            memcpy(&l_tmp16, i_flatdata, sizeof(uint16_t));
            i_flatdata += sizeof(uint16_t);
            uint32_t bytecount = ntohs(l_tmp16);

            // Read data for register.
            BitStringBuffer bs(bytecount * 8);
            for(uint32_t bc = 0; bc < bytecount; ++bc)
            {
                bs.SetFieldJustify(bc*8,8,(CPU_WORD)(*(i_flatdata+bc))); //mp01a
            }
            i_flatdata += bytecount;

            // Add to capture data.
            Add(l_pchipHandle, regid, bs);
        }
    }

    return *this;
}

// <-- dg08a

void CaptureData::mergeData(CaptureData & i_cd)
{
    DataContainerType l_data = *(i_cd.getData());

    if( !l_data.empty() )
    {
        // Remove duplicate entries from secondary capture data
        for (ConstDataIterator i = data.begin(); i != data.end(); i++)
        {
            l_data.remove_if(prdfCompareCaptureDataEntry(i->chipHandle,
                                                         i->address) );
        }

        // Add secondary capture data to primary one
        data.insert( data.end(),
                     l_data.begin(),
                     l_data.end() );
    }
}


// copy ctor for Data class
CaptureData::Data::Data(const Data & d):
chipHandle(d.chipHandle), address(d.address),
dataByteLength(d.dataByteLength), dataPtr(NULL)
{
    if(d.dataPtr != NULL)
    {
        dataPtr = new uint8_t[dataByteLength];

        memcpy(dataPtr, d.dataPtr, dataByteLength);
    }
}

CaptureData::Data & CaptureData::Data::operator=(const Data & d)
{
    chipHandle = d.chipHandle;
    address = d.address;
    dataByteLength = d.dataByteLength;
    if(dataPtr != NULL)
    {
        delete[]dataPtr;
        dataPtr = NULL;
    }
    if(d.dataPtr != NULL)
    {
        dataPtr = new uint8_t[dataByteLength];
        memcpy(dataPtr, d.dataPtr, dataByteLength);
    }

    return *this;
}

} // end of namespace PRDF
