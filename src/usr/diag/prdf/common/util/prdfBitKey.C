/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/prdfBitKey.C $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#define prdfBitKey_C

//#include <prdfAssert.h>
#include <prdfBitKey.H>
#include <prdfBitString.H>
#include <string.h>

#undef prdfBitKey_C

//-------------------------------------------------------------------------------------------------
// Local
//-------------------------------------------------------------------------------------------------
inline uint32_t getWordSize(uint32_t bitCount) // # of bit32's needed for this bit_count
{
  return (bitCount/32) + ((bitCount%32)? 1:0);
}

//-------------------------------------------------------------------------------------------------
// member function definitions
//-------------------------------------------------------------------------------------------------

prdfBitKey::prdfBitKey(void)
: iv_Capacity(0), iv_storage1(0)
{
  iv_rep.storage2 = 0;
}

//-------------------------------------------------------------------------------------------------

prdfBitKey::prdfBitKey(uint32_t i_bitPos)
: iv_Capacity(0), iv_storage1(0)
{
  iv_rep.storage2 = 0;
  setBit(i_bitPos);
}

//-------------------------------------------------------------------------------------------------

prdfBitKey::prdfBitKey(const uint8_t * i_array,uint8_t i_size)
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

//-------------------------------------------------------------------------------------------------

prdfBitKey::prdfBitKey(const char * i_ble)
: iv_Capacity(0), iv_storage1(0)
{
  iv_rep.storage2 = 0;
  while(*i_ble != 0)
  {
    setBit((*i_ble) - 1);
    ++i_ble;
  }
}

//-------------------------------------------------------------------------------------------------

prdfBitKey::~prdfBitKey(void)
{
  if(!IsDirect()) delete [] iv_rep.buffer;
}

//-------------------------------------------------------------------------------------------------

prdfBitKey::prdfBitKey (const prdfBitKey & bit_list)
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

//-------------------------------------------------------------------------------------------------

prdfBitKey & prdfBitKey::operator=(const prdfBitKey & bit_list)
{
  if(iv_Capacity)
  {
    prdfBitString bs(iv_Capacity,DataPtr());
    bs.Pattern(0x00000000);
  }
  ReAllocate(bit_list.iv_Capacity);
  if(IsDirect()) // implies bit_list is also direct
  {
    iv_storage1 = bit_list.iv_storage1;
    iv_rep.storage2 = bit_list.iv_rep.storage2;
  }
  else
  {
    const uint32_t * dataPtr = NULL;
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

//-------------------------------------------------------------------------------------------------

prdfBitKey & prdfBitKey::operator=(const prdfBitString & bit_string)
{
  if(iv_Capacity)
  {
    prdfBitString bs(iv_Capacity,DataPtr());
    bs.Pattern(0x00000000);
  }
  ReAllocate(bit_string.GetLength());
  prdfBitString dbs(iv_Capacity,DataPtr());
  dbs.SetBits(bit_string);
  return(*this);
}

//-------------------------------------------------------------------------------------------------

prdfBitKey & prdfBitKey::operator=(const char * string_ptr)
{
  if(iv_Capacity)
  {
    prdfBitString bs(iv_Capacity,DataPtr());
    bs.Pattern(0x00000000);
  }

  while(*string_ptr != '\0')
  {
    uint32_t bit_position = (uint32_t) ((*string_ptr) - 1);
    setBit(bit_position);
    ++string_ptr;
  }
  return(*this);
}

//-------------------------------------------------------------------------------------------------

bool prdfBitKey::operator==(const prdfBitKey & that) const
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


//-------------------------------------------------------------------------------------------------

// Candidate funciton for bs class
bool prdfBitKey::isSubset(const prdfBitKey & that) const
{
  bool result = true;
  const uint32_t * mydata = cDataPtr();
  const uint32_t * yodata = that.cDataPtr();
  uint32_t mysize = getWordSize(iv_Capacity);
  uint32_t yosize = getWordSize(that.iv_Capacity);
  uint32_t smsize = (yosize < mysize)? yosize : mysize;
  // size can be non-zero with no bits on - so if that has no bits than use operator==
  prdfBitKey zero;
  if(that == zero) result = operator==(that); // only true if both are empty - eg not bits on"
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

//-------------------------------------------------------------------------------------------------

// get bit position of nth bit that is set
uint32_t prdfBitKey::getListValue(uint32_t n) const
{
  ++n;
  uint32_t setCount = 0;
  uint32_t bitPos = 0xffffffff;

  prdfBitString bs(iv_Capacity,(CPU_WORD *)cDataPtr());
  for(uint32_t i = 0; i < iv_Capacity; ++i)
  {
    if(bs.IsSet(i)) ++setCount;
    if(setCount == n)
    {
      bitPos = i;
      break;
    }
  }
  return bitPos;
}

//-------------------------------------------------------------------------------------------------

uint32_t prdfBitKey::size(void) const
{
  const prdfBitString bs(iv_Capacity,(CPU_WORD *)cDataPtr());
  return bs.GetSetCount();
}

//-------------------------------------------------------------------------------------------------

void prdfBitKey::removeBit(uint32_t n)
{
  if(n < size())
  {
    prdfBitString bs(iv_Capacity,DataPtr());
    bs.Clear(getListValue(n));
  }
}

//-------------------------------------------------------------------------------------------------

void prdfBitKey::removeBit(void)
{
  prdfBitString bs(iv_Capacity,DataPtr());
  uint32_t i = iv_Capacity;
  while(i != 0)
  {
    --i;
    if(bs.IsSet(i))
    {
      bs.Clear(i);
      break;
    }
  }
}

//-------------------------------------------------------------------------------------------------

void prdfBitKey::removeBits(const prdfBitKey & i_bk)
{
  prdfBitString mybs(iv_Capacity,(CPU_WORD *)DataPtr());
  const prdfBitString yobs(i_bk.iv_Capacity,(CPU_WORD *)i_bk.cDataPtr());
  mybs.Mask(yobs);
}

//-------------------------------------------------------------------------------------------------

void prdfBitKey::setBit(uint32_t i_bitValue)
{
  if(i_bitValue >= iv_Capacity)
  {
    ReAllocate(i_bitValue+1);
  }
  prdfBitString bs(iv_Capacity,DataPtr());
  bs.Set(i_bitValue);
}

//-------------------------------------------------------------------------------------------------

void prdfBitKey::ReAllocate(uint32_t i_len)
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
      prdfBitString dbs(iv_Capacity,newBuffer);
      dbs.Pattern(0x00000000);
      prdfBitString sbs(oldSize,oldPtr);
      dbs.SetBits(sbs);
      iv_storage1 = 0;
      if(!wasDirect) // from indirect
      {
        delete [] iv_rep.buffer;
      }
      iv_rep.buffer = newBuffer;
    }
  }
}


// Change Log *************************************************************************************
//
//  Flag Reason   Vers Date     Coder    Description
//  ---- -------- ---- -------- -------- ---------------------------------------------------------
//                              dgilbert Initial Creation
//
// End Change Log *********************************************************************************
