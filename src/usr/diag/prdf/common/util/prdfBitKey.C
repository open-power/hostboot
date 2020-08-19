/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfBitKey.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define BitKey_C

//#include <prdfAssert.h>
#include <prdfBitKey.H>
#include <prdfBitString.H>
#include <string.h>

#undef BitKey_C

namespace PRDF
{
//------------------------------------------------------------------------------
// Local
//------------------------------------------------------------------------------
// # of bit32's needed for this bit_count
inline uint32_t getWordSize(uint32_t bitCount)
{
  return (bitCount/32) + ((bitCount%32)? 1:0);
}

//------------------------------------------------------------------------------
// member function definitions
//------------------------------------------------------------------------------

BitKey::BitKey(void)
: iv_Capacity(0), iv_storage1(0)
{
  iv_rep.storage2 = 0;
}

//------------------------------------------------------------------------------

BitKey::BitKey(uint32_t i_bitPos)
: iv_Capacity(0), iv_storage1(0)
{
  iv_rep.storage2 = 0;
  setBit(i_bitPos);
}

//------------------------------------------------------------------------------

BitKey::BitKey(const uint8_t * i_array,uint8_t i_size)
: iv_Capacity(0), iv_storage1(0)
{
  iv_rep.storage2 = 0;
  while(i_size)
  {
    setBit(*i_array);
    --i_size;
    ++i_array;
  }
}

//------------------------------------------------------------------------------

BitKey::BitKey( const std::vector <uint8_t> & i_bitList )
    : iv_Capacity(0), iv_storage1(0)
{
    iv_rep.storage2 = 0;
    std::vector< uint8_t >::const_iterator itList = i_bitList.begin();
    while( itList != i_bitList.end() )
    {
        setBit( *itList );
        itList++;
    }
}

//------------------------------------------------------------------------------

BitKey::BitKey(const char * i_ble)
: iv_Capacity(0), iv_storage1(0)
{
  iv_rep.storage2 = 0;
  while(*i_ble != 0)
  {
    setBit((*i_ble) - 1);
    ++i_ble;
  }
}

//------------------------------------------------------------------------------

BitKey::~BitKey(void)
{
  if(!IsDirect()) delete [] iv_rep.buffer;
}

//------------------------------------------------------------------------------

BitKey::BitKey (const BitKey & bit_list)
: iv_Capacity(bit_list.iv_Capacity), iv_storage1(bit_list.iv_storage1)
{
  if(IsDirect())
  {
    iv_rep.storage2 = bit_list.iv_rep.storage2;
  }
  else
  {
    uint32_t size = getWordSize(iv_Capacity);
    iv_rep.buffer = new uint32_t[size];
    memcpy(iv_rep.buffer,bit_list.iv_rep.buffer,4*size);
  }
}

//------------------------------------------------------------------------------

BitKey & BitKey::operator=(const BitKey & bit_list)
{
  if(iv_Capacity)
  {
    BitString bs(iv_Capacity,DataPtr());
    bs.clearAll();
  }
  ReAllocate(bit_list.iv_Capacity);
  if(IsDirect()) // implies bit_list is also direct
  {
    iv_storage1 = bit_list.iv_storage1;
    iv_rep.storage2 = bit_list.iv_rep.storage2;
  }
  else
  {
    const uint32_t * dataPtr = nullptr;
    if(bit_list.IsDirect())
    {
      dataPtr = &bit_list.iv_storage1;
    } else
    {
      dataPtr = bit_list.iv_rep.buffer;
    }
    memcpy(iv_rep.buffer,dataPtr,4*getWordSize(bit_list.iv_Capacity));
  }
  return(*this);
}

//------------------------------------------------------------------------------

BitKey & BitKey::operator=(const BitString & bit_string)
{
  if(iv_Capacity)
  {
    BitString bs(iv_Capacity,DataPtr());
    bs.clearAll();
  }
  ReAllocate(bit_string.getBitLen());
  BitString dbs(iv_Capacity,DataPtr());
  dbs.setString(bit_string);
  return(*this);
}

//------------------------------------------------------------------------------

BitKey & BitKey::operator=(const char * string_ptr)
{
  if(iv_Capacity)
  {
    BitString bs(iv_Capacity,DataPtr());
    bs.clearAll();
  }

  while(*string_ptr != '\0')
  {
    uint32_t bit_position = (uint32_t) ((*string_ptr) - 1);
    setBit(bit_position);
    ++string_ptr;
  }
  return(*this);
}

//------------------------------------------------------------------------------

bool BitKey::operator==(const BitKey & that) const
{
  bool result = true;
  const uint32_t * mydata = cDataPtr();
  const uint32_t * yodata = that.cDataPtr();
  uint32_t mysize = getWordSize(iv_Capacity);
  uint32_t yosize = getWordSize(that.iv_Capacity);
  uint32_t smsize = (yosize < mysize)? yosize : mysize;

  // If size is different than the extra must be zero
  for(uint32_t i = 0; (i < smsize) && (result == true); ++i,++mydata,++yodata)
  {
    result = (*mydata == *yodata);
  }
  if(result &&  (yosize > mysize))
  {
    for(yosize -= mysize; yosize != 0 && result; --yosize, ++yodata)
    {
      result = *yodata == 0x00000000;
    }
  }
  else if (result && (mysize > yosize))
  {
    for(mysize -= yosize; mysize != 0 && result; --mysize, ++mydata)
    {
      result = *mydata == 0x00000000;
    }
  }

  return result;
}


//------------------------------------------------------------------------------

// Candidate funciton for bs class
bool BitKey::isSubset(const BitKey & that) const
{
  bool result = true;
  const uint32_t * mydata = cDataPtr();
  const uint32_t * yodata = that.cDataPtr();
  uint32_t mysize = getWordSize(iv_Capacity);
  uint32_t yosize = getWordSize(that.iv_Capacity);
  uint32_t smsize = (yosize < mysize)? yosize : mysize;
  // size can be non-zero with no bits on - so if that has no bits than use
  // operator==
  BitKey zero;
  // only true if both are empty - eg not bits on"
  if(that == zero) result = operator==(that);
  // if yosize <= mysize than just match smallest amount of data
  // if yozize > mysize than extra yodata must be zero
  for(uint32_t i = 0; (i < smsize) && (result == true); ++i,++mydata,++yodata)
  {
    result = (*mydata & *yodata) == *yodata;
  }
  if(result &&  (yosize > mysize))
  {
    for(yosize -= mysize; yosize != 0 && result; --yosize, ++yodata)
    {
      result = *yodata == 0x00000000;
    }
  }

  return result;
}

//------------------------------------------------------------------------------

// get bit position of nth bit that is set
uint32_t BitKey::getListValue(uint32_t n) const
{
  ++n;
  uint32_t setCount = 0;
  uint32_t bitPos = 0xffffffff;

  BitString bs(iv_Capacity,(CPU_WORD *)cDataPtr());
  for(uint32_t i = 0; i < iv_Capacity; ++i)
  {
    if(bs.isBitSet(i)) ++setCount;
    if(setCount == n)
    {
      bitPos = i;
      break;
    }
  }
  return bitPos;
}

//------------------------------------------------------------------------------

uint32_t BitKey::size(void) const
{
  const BitString bs(iv_Capacity,(CPU_WORD *)cDataPtr());
  return bs.getSetCount();
}

//------------------------------------------------------------------------------

void BitKey::removeBit(uint32_t n)
{
  if(n < size())
  {
    BitString bs(iv_Capacity,DataPtr());
    bs.clearBit(getListValue(n));
  }
}

//------------------------------------------------------------------------------

void BitKey::removeBit(void)
{
  BitString bs(iv_Capacity,DataPtr());
  uint32_t i = iv_Capacity;
  while(i != 0)
  {
    --i;
    if(bs.isBitSet(i))
    {
      bs.clearBit(i);
      break;
    }
  }
}

//------------------------------------------------------------------------------

void BitKey::removeBits(const BitKey & i_bk)
{
  BitString mybs(iv_Capacity,(CPU_WORD *)DataPtr());
  const BitString yobs(i_bk.iv_Capacity,(CPU_WORD *)i_bk.cDataPtr());
  mybs.maskString(yobs);
}

//------------------------------------------------------------------------------

void BitKey::setBit(uint32_t i_bitValue)
{
  if(i_bitValue >= iv_Capacity)
  {
    ReAllocate(i_bitValue+1);
  }
  BitString bs(iv_Capacity,DataPtr());
  bs.setBit(i_bitValue);
}

//------------------------------------------------------------------------------

void BitKey::ReAllocate(uint32_t i_len)
{
  if(i_len > iv_Capacity)  // never shrink
  {
    bool wasDirect = IsDirect();
    uint32_t oldSize = iv_Capacity;
    uint32_t * oldPtr = DataPtr();

    uint32_t wordsize = getWordSize(i_len);
    iv_Capacity = 32*wordsize;

    bool isDirect = IsDirect();

    if(!isDirect)  // to indirect
    {
      uint32_t * newBuffer = new uint32_t[wordsize];
      BitString dbs(iv_Capacity,newBuffer);
      dbs.clearAll();
      BitString sbs(oldSize,oldPtr);
      if ( !sbs.isZero() ) dbs.setString(sbs);
      iv_storage1 = 0;
      if(!wasDirect) // from indirect
      {
        delete [] iv_rep.buffer;
      }
      iv_rep.buffer = newBuffer;
    }
  }
}

} // end namespace PRDF

