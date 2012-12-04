/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/register/prdfCaptureData.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/**
  @file prdfCaptureData.C
  @brief Squadrons implementation of capture data
*/
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

// For hostboot, these are no-ops
#define htonl(foo) (foo)
#define htons(foo) (foo)
#define ntohl(foo) (foo)
#define ntohs(foo) (foo)

#else

// for hton funcs.
#include <netinet/in.h>

#endif
#include <iipbits.h>
#include <prdfHomRegisterAccess.H>  // dg06a
#include <prdfScomRegister.H>
#include <iipchip.h>
#include <iipCaptureData.h>
#include <string.h>
#include <algorithm>    // @jl04 a Add this for the Drop function.

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


// @jl04 c Changed this to add the type parm.
void CaptureData::Add(  TARGETING::TargetHandle_t i_pchipHandle, int scomId,
                        SCAN_COMM_REGISTER_CLASS & scr, Place place, RegType type)
{
  uint16_t bufferLength = scr.GetBitLength() / 8;

  if((scr.GetBitLength() % 8) != 0)
    bufferLength += 1;

  Data dataElement(i_pchipHandle, scomId, bufferLength, NULL);

  AddDataElement(dataElement, scr, place, type);
}

// start dg02
void CaptureData::Add( TARGETING::TargetHandle_t i_pchipHandle, int scomId,
                       BIT_STRING_CLASS & bs, Place place)
{
  uint16_t bufferLength = bs.GetLength() / 8;

  if((bs.GetLength() % 8) != 0)
    bufferLength += 1;

  Data dataElement(i_pchipHandle, scomId, bufferLength, NULL);

  DataIterator dataIterator;

  if(place == FRONT)
  {
    data.insert(data.begin(), dataElement);
    dataIterator = data.begin();
  }
  else
  {
    data.push_back(dataElement);
    dataIterator = data.end();
    dataIterator--;
  }
  if(!bs.IsZero())
  {
    uint8_t *bufferPtr = new uint8_t[(*dataIterator).dataByteLength];
    BIT_STRING_ADDRESS_CLASS bitString(0, bs.GetLength(), (CPU_WORD *) bufferPtr);

    bitString.SetBits(bs);
    (*dataIterator).dataPtr = bufferPtr;
  }
  else
  {
    (*dataIterator).dataByteLength = 0;
  }


}

// end dg02


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

// @jl04 c Changed the AddDataElement to include a type.
void CaptureData::AddDataElement( Data & dataElement,
                                  SCAN_COMM_REGISTER_CLASS & scr,
                                  Place place, RegType type )
{
  DataIterator dataIterator;

  if(place == FRONT)
  {
    data.insert(data.begin(), dataElement);
    dataIterator = data.begin();
  }
  else
  {
    data.push_back(dataElement);
    dataIterator = data.end();
    dataIterator--;
  }

//$TEMP @jl04 or @jl05.
      (*dataIterator).registerType = type;
//$TEMP @jl04 or @jl05.

  if(scr.Read() == SUCCESS)
  {
    const BIT_STRING_CLASS *bitStringPtr = scr.GetBitString();

    if(!bitStringPtr->IsZero())
    {
      uint8_t *bufferPtr = new uint8_t[(*dataIterator).dataByteLength];
      BIT_STRING_ADDRESS_CLASS bitString(0, bitStringPtr->GetLength(),
                                         (CPU_WORD *) bufferPtr);

      bitString.SetBits(*bitStringPtr);
      (*dataIterator).dataPtr = bufferPtr;
    }
    else
    {
      (*dataIterator).dataByteLength = 0;
    }
  }
  else
  {
    // Zero out data length if SCRs failed
    (*dataIterator).dataByteLength = 0;
  }

}
// ------------------------------------------------------------------------------------------------

/* CaptureData Format:
 *        capture data -> ( <chip header> <registers> )*
 *        chip header -> ( <chip id:32> <# registers:32> )
 *        registers -> ( <reg id:16> <reg byte len:16> <bytes>+ )
 */
unsigned int CaptureData::Copy(uint8_t *i_buffer, unsigned int i_bufferSize) const
{
    using namespace TARGETING;

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
    using namespace TARGETING;

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
