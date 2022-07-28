/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfCaptureData.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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

#include <prdfBitString.H>
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
                                  const BitString * i_bs,
                                  Place i_place, RegType i_type )
{
    // Initial values of the bit string buffer if i_bs has a zero value.
    uint8_t * buf = nullptr;
    size_t sz_buf = 0;

    // Add buffer only if the value is non-zero.
    if ( !i_bs->isZero() )
    {
        // Get the size of i_bs and ensure byte alignment.
        sz_buf = (i_bs->getBitLen() + 8-1) / 8;

        // Since we are using a BitString below, which does everything on a
        // CPU_WORD boundary, we must make sure the buffer is CPU_WORD aligned.
        const size_t sz_word = sizeof(CPU_WORD);
        sz_buf = ((sz_buf + sz_word-1) / sz_word) * sz_word;

        // Allocate memory for the buffer.
        buf = new uint8_t[sz_buf];
        memset( buf, 0x00, sz_buf );

        // Use a BitString to copy i_bs to the buffer.
        BitString bs ( i_bs->getBitLen(), (CPU_WORD *)buf );
        bs.setString( *i_bs );

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
                       const BitString & i_bs, Place i_place )
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

template <class T>
void __bufferAdd( uint8_t* & i_idx, T i_val )
{
    memcpy( i_idx, &i_val, sizeof(i_val) );
    i_idx += sizeof(i_val);
}

bool __bufferFull( uint8_t * i_buf, size_t i_bufSize,
                   uint8_t * i_idx, size_t i_idxSize )
{
    if ( (i_buf + i_bufSize) < (i_idx + i_idxSize) )
    {
        PRDF_ERR( "[CaptureData::Copy] Buffer is full. Some data may have "
                  "been lost" );
        return true;
    }

    return false;
}

/* CaptureData Format:
 *        capture data -> ( <chip header> <registers> )*
 *        chip header -> ( <chip id:32> <# registers:32> )
 *        registers -> ( <reg id:16> <reg byte len:16> <bytes>+ )
 */
uint32_t CaptureData::Copy( uint8_t * i_buffer, uint32_t i_bufferSize ) const
{
    TargetHandle_t curTrgt = nullptr;

    uint32_t * regCntPtr = nullptr;

    uint8_t * curIdx = i_buffer;

    for ( auto & entry : data )
    {
        // We only need the target data when the target for this entry does not
        // match the previous entry.
        if ( entry.chipHandle != curTrgt )
        {
            // Ensure we have enough space for the entry header.
            if ( __bufferFull( i_buffer, i_bufferSize, curIdx,
                               (sizeof(HUID) + sizeof(uint32_t)) ) )
            {
                break;
            }

            // Update current target.
            curTrgt = entry.chipHandle;

            // Add HUID to buffer.
            __bufferAdd( curIdx, htobe32(PlatServices::getHuid(curTrgt)) );

            // Update the current count pointer.
            regCntPtr = (uint32_t *)curIdx;

            // Zero out the register count.
            __bufferAdd( curIdx, htobe32(0) );
        }

        // Go to next entry if the data byte length is 0.
        if ( 0 == entry.dataByteLength )
            continue;

        // Ensure we have enough space for the entry header.
        if ( __bufferFull( i_buffer, i_bufferSize, curIdx,
                           (2 * sizeof(uint16_t) + entry.dataByteLength) ) )
        {
            break;
        }

        // Write register ID.
        __bufferAdd( curIdx, htobe16(entry.address) );

        // Write data length.
        __bufferAdd( curIdx, htobe16(entry.dataByteLength) );

        // Write the data.
        // >>> TODO: RTC 199045 The data should already be in network format.
        //           However, that is not the case. Instead, the data is
        //           converted here, which would be is fine if we were only
        //           adding registers, but we have additional capture data,
        //           especially in the memory subsytem, that are actually stored
        //           in the network format, but swizzled before adding to the
        //           capture data. Which means we are doing too much.
        //           Unfortunately, it currently works and will take some time
        //           to actually do it right. Therefore, we will leave this
        //           as-is and try to make the appropriate fix later.
        uint32_t l_dataWritten = 0;
        while ((l_dataWritten + 4) <= entry.dataByteLength)
        {
            uint32_t l_temp32;
            memcpy(&l_temp32, &entry.dataPtr[l_dataWritten], sizeof(l_temp32));
            l_temp32 = htobe32(l_temp32);
            memcpy(curIdx, &l_temp32, 4);
            l_dataWritten += 4; curIdx += 4;
        }
        if (l_dataWritten != entry.dataByteLength)
        {
            // TODO: RTC 199045 This is actually pretty bad because it will read
            //       four bytes of memory, sizzle the four bytes, then write
            //       less than four bytes to the buffer. This could cause a
            //       buffer overrun exception if we were at the end of memory.
            //       Also, how can we trust the right most bytes to be correct
            //       since they technically should not be part of the entry
            //       data? Again, we don't seem to be hitting this bug and it
            //       will take time to fix it (see note above). Therefore, we
            //       will leave it for now and fix it when we have time.
            uint32_t l_temp32;
            memcpy(&l_temp32, &entry.dataPtr[l_dataWritten], sizeof(l_temp32));
            l_temp32 = htobe32(l_temp32);
            memcpy(curIdx, &l_temp32, entry.dataByteLength - l_dataWritten);
            curIdx += entry.dataByteLength - l_dataWritten;
        }
        // <<< TODO: RTC 199045

        // Update entry count. It is important to update the buffer just in
        // case we happen to run out of room in the buffer and need to exit
        // early.
        *regCntPtr = htobe32( be32toh(*regCntPtr) + 1 );
    }

    return curIdx - i_buffer;
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
    uint32_t size = be32toh(l_tmp32);
    i_flatdata += sizeof(uint32_t);

    Clear();

    // Calculate end of buffer.
    const uint8_t *eptr = i_flatdata + size;

    while(i_flatdata < eptr)
    {
        // Read chip Handle.
        memcpy(&l_chipHuid , i_flatdata,l_huidSize );
        i_flatdata += l_huidSize ;
        TargetHandle_t l_pchipHandle  =nullptr;
        l_chipHuid =  be32toh(l_chipHuid);
        l_pchipHandle = PlatServices::getTarget(l_chipHuid );
        if(nullptr ==l_pchipHandle)
        {
            continue;
        }

        // Read # of entries.
        memcpy(&l_tmp32, i_flatdata, sizeof(uint32_t));
        i_flatdata += sizeof(l_tmp32);
        uint32_t entries = be32toh(l_tmp32);

        // Input each entry.
        for(uint32_t i = 0; i < entries; ++i)
        {
            // Read register id.
            memcpy(&l_tmp16, i_flatdata, sizeof(uint16_t));
            i_flatdata += sizeof(uint16_t);
            int regid = be16toh(l_tmp16);

            // Read byte count.
            memcpy(&l_tmp16, i_flatdata, sizeof(uint16_t));
            i_flatdata += sizeof(uint16_t);
            uint32_t bytecount = be16toh(l_tmp16);

            // Read data for register.
            BitStringBuffer bs(bytecount * 8);
            for(uint32_t bc = 0; bc < bytecount; ++bc)
            {
                bs.setFieldJustify(bc*8,8,(CPU_WORD)(*(i_flatdata+bc))); //mp01a
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
dataByteLength(d.dataByteLength), dataPtr(nullptr)
{
    if(d.dataPtr != nullptr)
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
    if(dataPtr != nullptr)
    {
        delete[]dataPtr;
        dataPtr = nullptr;
    }
    if(d.dataPtr != nullptr)
    {
        dataPtr = new uint8_t[dataByteLength];
        memcpy(dataPtr, d.dataPtr, dataByteLength);
    }

    return *this;
}

} // end of namespace PRDF
