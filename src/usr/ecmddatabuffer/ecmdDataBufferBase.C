/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ecmddatabuffer/ecmdDataBufferBase.C $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
//#include <ecmdDefines.H>
#include <ecmdDataBufferBase.H>
#include <prdfCompressBuffer.H>

#ifndef __HOSTBOOT_MODULE
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <zlib.h>
#include <netinet/in.h>
#else
#include <fapiUtil.H>
#include <fapiPlatTrace.H>
#define htonl(foo) (foo)
#define ntohl(foo) (foo)
#endif

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------
#ifdef FIPSODE
tracDesc_t g_etrc; /** Trace Descriptor **/
TRAC_INIT(&g_etrc, "ECMD", 0x1000);
#elif defined ZSERIES_SWITCH
#define TRACE_ID ECMDBUF
#endif

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
#define EDB_RANDNUM 0x12345678
#define EDB_ADMIN_HEADER_SIZE 1
#define EDB_ADMIN_FOOTER_SIZE 1
// This define is the sum of EDB_ADMIN_HEADER_SIZE + EDB_ADMIN_FOOTER_SIZE
#define EDB_ADMIN_TOTAL_SIZE 2
#define EDB_RETURN_CODE 0

// New Constants for improved performance
//#define MIN(x,y)            (((x)<(y))?x:y) - Removed 7/23/08 because prdfCompressBuffer.H defines this function
#define UNIT_SZ             32

#define RETURN_ERROR(i_rc) if ((iv_RealData != NULL) && (iv_RealData[EDB_RETURN_CODE] == 0)) { iv_RealData[EDB_RETURN_CODE] = i_rc; } return i_rc;
#define SET_ERROR(i_rc) if ((iv_RealData != NULL) && (iv_RealData[EDB_RETURN_CODE] == 0)) { iv_RealData[EDB_RETURN_CODE] = i_rc; }

//----------------------------------------------------------------------
//  Forward declarations
//----------------------------------------------------------------------
uint32_t ecmdExtract(uint32_t *i_sourceData, uint32_t i_startBit, uint32_t i_numBitsToExtract, uint32_t *o_destData);
void * ecmdBigEndianMemCopy(void * dest, const void *src, size_t count);

// new declaration here for performance improvement
// This function does NOT do input checks and does NOT handle xstate
inline uint32_t ecmdFastInsert(uint32_t *i_target, const uint32_t * i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart); 


//----------------------------------------------------------------------
//  Inlined Functions used to improve Performance
//----------------------------------------------------------------------
inline /* leave this inlined */
uint32_t fast_mask32(int32_t i_pos, int32_t i_len) {
  /* generates an arbitrary 32-bit mask using two
   operations, not too shabby */

  static const uint32_t l_mask32[] = {
    0x00000000,
    0x80000000, 0xC0000000, 0xE0000000, 0xF0000000,
    0xF8000000, 0xFC000000, 0xFE000000, 0xFF000000,
    0xFF800000, 0xFFC00000, 0xFFE00000, 0xFFF00000,
    0xFFF80000, 0xFFFC0000, 0xFFFE0000, 0xFFFF0000,
    0xFFFF8000, 0xFFFFC000, 0xFFFFE000, 0xFFFFF000,
    0xFFFFF800, 0xFFFFFC00, 0xFFFFFE00, 0xFFFFFF00,
    0xFFFFFF80, 0xFFFFFFC0, 0xFFFFFFE0, 0xFFFFFFF0,
    0xFFFFFFF8, 0xFFFFFFFC, 0xFFFFFFFE, 0xFFFFFFFF,
  };
  return l_mask32[i_len] >> i_pos;
}

inline /* leave this inlined */
uint32_t fast_set32(uint32_t i_trg, int32_t i_pos, int32_t i_len) {
  return fast_mask32(i_pos, i_len) | i_trg;
}

inline /* leave this inlined */
uint32_t fast_clear32(uint32_t i_trg, int32_t i_pos, int32_t i_len) {
  return fast_mask32(i_pos, i_len) & ~i_trg;
}

inline /* leave this inlined */
uint8_t fast_reverse8(uint8_t data) {
  static const uint8_t reverse8[] = {
    0x00,0x80,0x40,0xc0,0x20,0xa0,0x60,0xe0,
    0x10,0x90,0x50,0xd0,0x30,0xb0,0x70,0xf0,
    0x08,0x88,0x48,0xc8,0x28,0xa8,0x68,0xe8,
    0x18,0x98,0x58,0xd8,0x38,0xb8,0x78,0xf8,
    0x04,0x84,0x44,0xc4,0x24,0xa4,0x64,0xe4,
    0x14,0x94,0x54,0xd4,0x34,0xb4,0x74,0xf4,
    0x0c,0x8c,0x4c,0xcc,0x2c,0xac,0x6c,0xec,
    0x1c,0x9c,0x5c,0xdc,0x3c,0xbc,0x7c,0xfc,
    0x02,0x82,0x42,0xc2,0x22,0xa2,0x62,0xe2,
    0x12,0x92,0x52,0xd2,0x32,0xb2,0x72,0xf2,
    0x0a,0x8a,0x4a,0xca,0x2a,0xaa,0x6a,0xea,
    0x1a,0x9a,0x5a,0xda,0x3a,0xba,0x7a,0xfa,
    0x06,0x86,0x46,0xc6,0x26,0xa6,0x66,0xe6,
    0x16,0x96,0x56,0xd6,0x36,0xb6,0x76,0xf6,
    0x0e,0x8e,0x4e,0xce,0x2e,0xae,0x6e,0xee,
    0x1e,0x9e,0x5e,0xde,0x3e,0xbe,0x7e,0xfe,
    0x01,0x81,0x41,0xc1,0x21,0xa1,0x61,0xe1,
    0x11,0x91,0x51,0xd1,0x31,0xb1,0x71,0xf1,
    0x09,0x89,0x49,0xc9,0x29,0xa9,0x69,0xe9,
    0x19,0x99,0x59,0xd9,0x39,0xb9,0x79,0xf9,
    0x05,0x85,0x45,0xc5,0x25,0xa5,0x65,0xe5,
    0x15,0x95,0x55,0xd5,0x35,0xb5,0x75,0xf5,
    0x0d,0x8d,0x4d,0xcd,0x2d,0xad,0x6d,0xed,
    0x1d,0x9d,0x5d,0xdd,0x3d,0xbd,0x7d,0xfd,
    0x03,0x83,0x43,0xc3,0x23,0xa3,0x63,0xe3,
    0x13,0x93,0x53,0xd3,0x33,0xb3,0x73,0xf3,
    0x0b,0x8b,0x4b,0xcb,0x2b,0xab,0x6b,0xeb,
    0x1b,0x9b,0x5b,0xdb,0x3b,0xbb,0x7b,0xfb,
    0x07,0x87,0x47,0xc7,0x27,0xa7,0x67,0xe7,
    0x17,0x97,0x57,0xd7,0x37,0xb7,0x77,0xf7,
    0x0f,0x8f,0x4f,0xcf,0x2f,0xaf,0x6f,0xef,
    0x1f,0x9f,0x5f,0xdf,0x3f,0xbf,0x7f,0xff,
  };
  return reverse8[data];
}

inline /* leave this inlined */
uint32_t fast_reverse32(uint32_t data) {
  return fast_reverse8((data & 0xFF000000) >> 24) |
    fast_reverse8((data & 0x00FF0000) >> 16) << 8 |
    fast_reverse8((data & 0x0000FF00) >> 8) << 16 |
    fast_reverse8(data & 0x000000FF) << 24;
}

//---------------------------------------------------------------------
//  Constructors
//---------------------------------------------------------------------
ecmdDataBufferBase::ecmdDataBufferBase()  // Default constructor
: iv_Capacity(0), iv_NumBits(0), iv_Data(NULL), iv_RealData(NULL)
{
  iv_UserOwned = true;
  iv_BufferOptimizable = false;

#ifndef REMOVE_SIM
  iv_DataStr = NULL;
  iv_XstateEnabled = false;
#endif
}

ecmdDataBufferBase::ecmdDataBufferBase(uint32_t i_numBits)
: iv_Capacity(0), iv_NumBits(0), iv_Data(NULL), iv_RealData(NULL)
{
  iv_UserOwned = true;
  iv_BufferOptimizable = false;

#ifndef REMOVE_SIM
  iv_DataStr = NULL;
  iv_XstateEnabled = false;
#endif

  if (i_numBits > 0) {
    setBitLength(i_numBits);
  }
}

ecmdDataBufferBase::ecmdDataBufferBase(const ecmdDataBufferBase& i_other) 
: iv_Capacity(0), iv_NumBits(0), iv_Data(NULL), iv_RealData(NULL)
{
  iv_UserOwned = true;
  iv_BufferOptimizable = false;

#ifndef REMOVE_SIM
  iv_DataStr = NULL;
  iv_XstateEnabled = false;
#endif

  if (i_other.iv_NumBits != 0) {

    this->setBitLength(i_other.iv_NumBits);
    // iv_Data
    memcpy(iv_Data, i_other.iv_Data, getWordLength() * 4);
    // Error state
    iv_RealData[EDB_RETURN_CODE] = i_other.iv_RealData[EDB_RETURN_CODE];

  }
  /* else do nothing.  already have an empty buffer */

}

//---------------------------------------------------------------------
//  Destructor
//---------------------------------------------------------------------
ecmdDataBufferBase::~ecmdDataBufferBase()
{
    // Only call clear() if buffer is owned by this user (ie, not shared)
    if(iv_UserOwned) clear();
}

//---------------------------------------------------------------------
//  Public Member Function Specifications
//---------------------------------------------------------------------
uint32_t ecmdDataBufferBase::clear() {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if(!iv_UserOwned)  // If this buffer is shared
  {
      if (!isBufferOptimizable()) { // If the buffer is not optimizable, error
        ETRAC0("**** ERROR (ecmdDataBufferBase) : Attempt to modify non user owned buffer size.");
        RETURN_ERROR(ECMD_DBUF_NOT_OWNER);
      }
      else {  // It's a shared/optimizable buffer, don't flag error
        return ECMD_DBUF_SUCCESS;
      }
  }

  if (iv_RealData != NULL) {

    /* Let's check our header,footer info */
    if (iv_RealData[getWordLength() + EDB_ADMIN_HEADER_SIZE] != EDB_RANDNUM) {
      /* Ok, something is wrong here */
      ETRAC2("**** SEVERE ERROR (ecmdDataBufferBase) : iv_RealData[0]: %X, getWordLength(): %X",iv_RealData[EDB_RETURN_CODE],getWordLength());
      ETRAC1("**** SEVERE ERROR (ecmdDataBufferBase) : iv_RealData[getWordLength() + EDB_ADMIN_HEADER_SIZE]: %X",iv_RealData[getWordLength() + EDB_ADMIN_HEADER_SIZE]);
      ETRAC0("**** SEVERE ERROR (ecmdDataBufferBase) : PROBLEM WITH DATABUFFER - INVALID HEADER/FOOTER");
#ifdef __HOSTBOOT_MODULE
      fapiAssert(false);
#else
      abort();
#endif
    }

    /* That looked okay, reset everything else */
    /* Only do the delete if we alloc'd something */
    if (iv_RealData != iv_LocalData) {
      delete[] iv_RealData;
    }
    iv_RealData = NULL;
    iv_Capacity = 0;
    iv_NumBits = 0;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::getDoubleWordLength() const { return (iv_NumBits + 63) / 64; }
uint32_t ecmdDataBufferBase::getWordLength() const { return (iv_NumBits + 31) / 32; }
uint32_t ecmdDataBufferBase::getHalfWordLength() const { return (iv_NumBits + 15) / 16; }
uint32_t ecmdDataBufferBase::getByteLength() const { return (iv_NumBits + 7) / 8; }
uint32_t ecmdDataBufferBase::getBitLength() const { return iv_NumBits; }
uint32_t ecmdDataBufferBase::getCapacity() const { return iv_Capacity; }

uint32_t ecmdDataBufferBase::setDoubleWordLength(uint32_t i_newNumDoubleWords) {
  return setBitLength(i_newNumDoubleWords * 64);
}  

uint32_t ecmdDataBufferBase::setWordLength(uint32_t i_newNumWords) {
  return setBitLength(i_newNumWords * 32);
}

uint32_t ecmdDataBufferBase::setHalfWordLength(uint32_t i_newNumHalfWords) {
  return setBitLength(i_newNumHalfWords * 16);
}

uint32_t ecmdDataBufferBase::setByteLength(uint32_t i_newNumBytes) {
  return setBitLength(i_newNumBytes * 8);
}  

uint32_t ecmdDataBufferBase::setBitLength(uint32_t i_newNumBits) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if ((i_newNumBits == 0) && (iv_NumBits == 0)) {
    // Do Nothing:  this data doesn't already have iv_RealData,iv_Data defined, and it doesn't want to define it
    return rc;
  }

  /* Assign i_newNumBits to iv_NumBits and figure out how many words that is */
  iv_NumBits = i_newNumBits;

  /* Now call setCapacity to do all the data buffer resizing and setup */
  rc = setCapacity(getWordLength());
  if (rc) return rc;

  return rc;
}  

uint32_t ecmdDataBufferBase::setCapacity(uint32_t i_newCapacity) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if(!iv_UserOwned) {
    ETRAC0("**** ERROR (ecmdDataBufferBase) : Attempt to modify non user owned buffer size.");
    RETURN_ERROR(ECMD_DBUF_NOT_OWNER);
  }

  /* for case where i_newCapacity is 0 (like in unflatten) use iv_LocalData for iv_RealData */
  /* This allows for iv_Data, the header, and the tail to be setup right */
  if (iv_Capacity == 0) { 
      /* We are using iv_LocalData, so point iv_RealData to the start of that */
      iv_RealData = iv_LocalData;
  }

  /* only resize to make the capacity bigger */
  if (iv_Capacity < i_newCapacity) {
    iv_Capacity = i_newCapacity;

    /* Now setup iv_RealData */
    if (iv_Capacity <= 2) {
      /* We are using iv_LocalData, so point iv_RealData to the start of that */
      iv_RealData = iv_LocalData;
    } else {
      /* If we are going from <= 64 to > 64, there was no malloc done so can't do delete */
      if ((iv_RealData != NULL) && (iv_RealData != iv_LocalData)) {
        delete[] iv_RealData;
      }
      iv_RealData = NULL;

      iv_RealData = new uint32_t[iv_Capacity + EDB_ADMIN_TOTAL_SIZE]; 
      if (iv_RealData == NULL) {
        ETRAC0("**** ERROR : ecmdDataBufferBase::setCapacity : Unable to allocate memory for new databuffer");
        RETURN_ERROR(ECMD_DBUF_INIT_FAIL);
      }
    }

  }

  /* Now setup iv_Data to point into the offset inside of iv_RealData */
  iv_Data = iv_RealData + EDB_ADMIN_HEADER_SIZE;

  /* We are all setup, now init everything to 0 */
  /* We want to do this regardless of if the buffer was resized. */
  /* This function is meant to be a destructive operation */
  /* Ok, now setup the header, and tail */
  iv_RealData[EDB_RETURN_CODE] = 0; ///< Reset error code
  iv_RealData[getWordLength() + EDB_ADMIN_HEADER_SIZE] = EDB_RANDNUM;

  rc = flushTo0();
  if (rc) return rc;

  return rc;
}

uint32_t ecmdDataBufferBase::shrinkBitLength(uint32_t i_newNumBits) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if(!iv_UserOwned) {
    ETRAC0("**** ERROR (ecmdDataBufferBase::shrinkBitLength) : Attempt to modify non user owned buffer size.");
    RETURN_ERROR(ECMD_DBUF_NOT_OWNER);
  }

  if (i_newNumBits > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::shrinkBitLength: New Bit Length (%d) > current NumBits (%d)", i_newNumBits, iv_NumBits);
    rc = ECMD_DBUF_BUFFER_OVERFLOW;
    RETURN_ERROR(rc);
  }

  /* If the length is the same, do nothing */
  if (i_newNumBits == iv_NumBits) {
    return rc;
  }

  // before shrinking, clear all data that is going to now be invalid
  this->clearBit(i_newNumBits, (iv_NumBits-i_newNumBits));
  if (rc != ECMD_DBUF_SUCCESS) { 
    ETRAC3("**** ERROR : ecmdDataBufferBase::shrinkBitLength: Error Back from clearBit(%d, %d). rc=0x%x", i_newNumBits, (iv_NumBits-i_newNumBits), rc); 
    RETURN_ERROR(rc);  
  }

  iv_NumBits = i_newNumBits;

  /* Ok, now setup the header, and tail */
  iv_RealData[getWordLength() + EDB_ADMIN_HEADER_SIZE] = EDB_RANDNUM;

  return rc;
}

uint32_t ecmdDataBufferBase::growBitLength(uint32_t i_newNumBits) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t prevwordsize;
  uint32_t prevbitsize;

  if(!iv_UserOwned) {
    ETRAC0("**** ERROR (ecmdDataBufferBase::growBitLength) : Attempt to modify non user owned buffer size.");
    RETURN_ERROR(ECMD_DBUF_NOT_OWNER);
  }

  /* Maybe we don't need to do anything */
  if (iv_NumBits == i_newNumBits) {
    return rc;
  } else if (i_newNumBits < iv_NumBits) {
    /* You can't grow smaller, use shrink */
    ETRAC0("**** ERROR (ecmdDataBufferBase::growBitLength) : Attempted to grow to a smaller size then current buffer size.");
    RETURN_ERROR(ECMD_DBUF_INVALID_ARGS);
  }

  /* We need to verify we have room to do this shifting */
  /* Set our new length */
  prevwordsize = getWordLength();
  prevbitsize = iv_NumBits;
  iv_NumBits = i_newNumBits;
  if (getWordLength() > iv_Capacity) {
    /* UhOh we are out of room, have to resize */
    uint32_t * tempBuf = new uint32_t[prevwordsize];
    if (tempBuf == NULL) {
      ETRAC0("**** ERROR : ecmdDataBufferBase::growBitLength : Unable to allocate temp buffer");
      RETURN_ERROR(ECMD_DBUF_INIT_FAIL);
    }
    memcpy(tempBuf, iv_Data, prevwordsize * 4);

    /* Now resize with the new capacity */
    rc = setCapacity(getWordLength());
    if (rc) {
      if (tempBuf) {
        delete[] tempBuf;
      }
      return rc;
    }

    /* Restore the data */
    ecmdBigEndianMemCopy(iv_Data, tempBuf, (prevbitsize + 7) / 8);
    delete[] tempBuf;

    /* Clear any odd bits in the byte */
    for (uint32_t idx = prevbitsize; (idx < iv_NumBits) && (idx % 8); idx ++) {
      clearBit(idx);
    }

  } else if (prevwordsize < getWordLength()) {
    /* We didn't have to grow the buffer capacity, but we did move into a new word(s) so clear that data space out */
    for (uint32_t idx = prevwordsize; idx < getWordLength(); idx++) {
      memset(&iv_Data[idx], 0, 4);  // Clear the word
    }
  }    

  /* Only reset this stuff if things have changed */
  if (prevwordsize != getWordLength()) {
    iv_RealData[EDB_RETURN_CODE] = 0;  // error state
    iv_RealData[getWordLength() + EDB_ADMIN_HEADER_SIZE] = EDB_RANDNUM;
  }

  return rc;
}

bool ecmdDataBufferBase::getBit(uint32_t i_bit) const {
  /* This just calls is bit set and returns that value */
  return this->isBitSet(i_bit);
}


uint32_t ecmdDataBufferBase::setBit(uint32_t i_bit) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  if (i_bit >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::setBit: bit %d >= NumBits (%d)", i_bit, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  int index = i_bit/32;
  iv_Data[index] |= 0x00000001 << (31 - (i_bit-(index * 32)));

  return rc;
}

uint32_t ecmdDataBufferBase::setBit(uint32_t i_bit, uint32_t i_len) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_bit+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::setBit: bit %d + len %d > NumBits (%d)", i_bit, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  for (uint32_t idx = 0; idx < i_len; idx ++) {
    rc |= this->setBit(i_bit + idx);
  }    

  return rc;
}

uint32_t ecmdDataBufferBase::writeBit(uint32_t i_bit, uint32_t i_value) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_value) {
    rc = setBit(i_bit);
  } else {
    rc = clearBit(i_bit);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::setWord(uint32_t i_wordOffset, uint32_t i_value) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_wordOffset >= getWordLength()) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::setWord: wordoffset %d >= NumWords (%d)", i_wordOffset, getWordLength());
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  // Create mask if part of this word is not in the valid part of the ecmdDataBufferBase 
  if (((i_wordOffset + 1) == getWordLength()) && (iv_NumBits % 32)) {
    /* Create my mask */
    uint32_t bitMask = 0xFFFFFFFF;
    /* Shift it left by the amount of unused bits */
    bitMask <<= ((32 * getWordLength()) - iv_NumBits);
    /* Clear the unused bits */
    i_value &= bitMask;
  }

  iv_Data[i_wordOffset] = i_value;

  return rc;
}

uint32_t ecmdDataBufferBase::setByte(uint32_t i_byteOffset, uint8_t i_value) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_byteOffset >= getByteLength()) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::setByte: byteOffset %d >= NumBytes (%d)", i_byteOffset, getByteLength());
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  // Create mask if part of this byte is not in the valid part of the ecmdDataBufferBase 
  if (((i_byteOffset + 1) == getByteLength()) && (iv_NumBits % 8)) {
    /* Create my mask */
    uint8_t bitMask = 0xFF;
    /* Shift it left by the amount of unused bits */
    bitMask <<= ((8 * getByteLength()) - iv_NumBits);
    /* Clear the unused bits */
    i_value &= bitMask;
  }

#if defined (i386)
  ((uint8_t*)(this->iv_Data))[i_byteOffset^3] = i_value;
#else
  ((uint8_t*)(this->iv_Data))[i_byteOffset] = i_value;
#endif

  return rc;
}

uint8_t ecmdDataBufferBase::getByte(uint32_t i_byteOffset) const {
  if (i_byteOffset >= getByteLength()) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::getByte: byteOffset %d >= NumBytes (%d)", i_byteOffset, getByteLength());
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return 0;
  }
#if defined (i386)
  return ((uint8_t*)(this->iv_Data))[i_byteOffset^3];
#else
  return ((uint8_t*)(this->iv_Data))[i_byteOffset];
#endif
}


uint32_t ecmdDataBufferBase::setHalfWord(uint32_t i_halfwordoffset, uint16_t i_value) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_halfwordoffset >= ((getByteLength()+1)/2)) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::setHalfWord: halfWordOffset %d >= NumHalfWords (%d)", i_halfwordoffset, ((getByteLength()+1)/2));
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  // Create mask if part of this byte is not in the valid part of the ecmdDataBufferBase 
  if (((i_halfwordoffset + 1) == ((getByteLength()+1)/2)) && (iv_NumBits % 16)) {
    /* Create my mask */
    uint16_t bitMask = 0xFFFF;
    /* Shift it left by the amount of unused bits */
    bitMask <<= ((16 * ((getByteLength()+1)/2)) - iv_NumBits);
    /* Clear the unused bits */
    i_value &= bitMask;
  }

  uint32_t value32 = (uint32_t)i_value;
  if (i_halfwordoffset % 2) {
    iv_Data[i_halfwordoffset/2] = (iv_Data[i_halfwordoffset/2] & 0xFFFF0000) | (value32 & 0x0000FFFF);
  } else {
    iv_Data[i_halfwordoffset/2] = (iv_Data[i_halfwordoffset/2] & 0x0000FFFF) | ((value32 << 16) & 0xFFFF0000);
  }

  return rc;
}
 

uint16_t ecmdDataBufferBase::getHalfWord(uint32_t i_halfwordoffset) const {
  if (i_halfwordoffset >= ((getByteLength()+1)/2)) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::getHalfWord: halfWordOffset %d >= NumHalfWords (%d)", i_halfwordoffset, ((getByteLength()+1)/2));
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return 0;
  }
  uint16_t ret;
  if (i_halfwordoffset % 2) 
    ret = (uint16_t)(iv_Data[i_halfwordoffset/2] & 0x0000FFFF);
  else
    ret = (uint16_t)(iv_Data[i_halfwordoffset/2] >> 16);
  return ret;
}

uint32_t ecmdDataBufferBase::setDoubleWord(uint32_t i_doublewordoffset, uint64_t i_value) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_doublewordoffset >= ((getWordLength()+1)/2)) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::setDoubleWord: doubleWordOffset %d >= NumDoubleWords (%d)"
       , i_doublewordoffset, ((getWordLength()+1)/2));
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  // Create mask if part of this byte is not in the valid part of the ecmdDataBufferBase 
  if (((i_doublewordoffset + 1) == ((getWordLength()+1)/2)) && (iv_NumBits % 64)) {
    /* Create my mask */
#ifdef _LP64
    uint64_t bitMask = 0xFFFFFFFFFFFFFFFFul;
#else
    uint64_t bitMask = 0xFFFFFFFFFFFFFFFFull;
#endif
    /* Shift it left by the amount of unused bits */
    bitMask <<= ((64 * ((getWordLength()+1)/2)) - iv_NumBits);
    /* Clear the unused bits */
    i_value &= bitMask;
  }

#ifdef _LP64
  uint32_t hivalue = (uint32_t)((i_value & 0xFFFFFFFF00000000ul) >> 32);
  uint32_t lovalue = (uint32_t)((i_value & 0x00000000FFFFFFFFul));
#else
  uint32_t hivalue = (uint32_t)((i_value & 0xFFFFFFFF00000000ull) >> 32);
  uint32_t lovalue = (uint32_t)((i_value & 0x00000000FFFFFFFFull));
#endif

  iv_Data[i_doublewordoffset*2] = hivalue;
  /* Don't set the second word if we are on oddwords */
  if (!((i_doublewordoffset*2)+1 >= getWordLength()) ) {
    iv_Data[(i_doublewordoffset*2)+1] = lovalue;
  }
  
  return rc;
}

uint64_t ecmdDataBufferBase::getDoubleWord(uint32_t i_doublewordoffset) const {
  // Round up to the next word and check length
  if (i_doublewordoffset >= ((getWordLength()+1)/2)) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::getDoubleWord: doubleWordOffset %d >= NumDoubleWords (%d)", 
       i_doublewordoffset, ((getWordLength()+1)/2));
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return 0;
  }
  uint64_t ret;
  ret = ((uint64_t)(iv_Data[i_doublewordoffset*2])) << 32;
  // If we have an odd length of words we can't pull the second word if we are at the end
  if (!((i_doublewordoffset*2)+1 >= getWordLength()) ) {
    ret |= iv_Data[(i_doublewordoffset*2)+1];
  }
  return ret;
}

uint32_t ecmdDataBufferBase::clearBit(uint32_t i_bit) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  if (i_bit >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::clearBit: bit %d >= NumBits (%d)", i_bit, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  int index = i_bit/32;
  iv_Data[index] &= ~(0x00000001 << (31 - (i_bit-(index * 32))));

  return rc;
}

uint32_t ecmdDataBufferBase::clearBit(uint32_t i_bit, uint32_t i_len) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  if (i_bit+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::clearBit: bit %d + len %d > NumBits (%d)", i_bit, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  
  for (uint32_t idx = 0; idx < i_len; idx ++) {
    rc |= this->clearBit(i_bit + idx);
  }   
  
  return rc;
}

uint32_t ecmdDataBufferBase::flipBit(uint32_t i_bit) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  if (i_bit >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::flipBit: bit %d >= NumBits (%d)", i_bit, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  if (this->isBitSet(i_bit)) {
    rc = this->clearBit(i_bit);      
  } else {
    rc = this->setBit(i_bit);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::flipBit(uint32_t i_bit, uint32_t i_len) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  if (i_bit+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::flipBit: i_bit %d + i_len %d > NumBits (%d)", i_bit, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  for (uint32_t i = 0; i < i_len; i++) {
    this->flipBit(i_bit+i);
  }

  return rc;
}

bool   ecmdDataBufferBase::isBitSet(uint32_t i_bit) const {
  if (i_bit >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::isBitSet: i_bit %d >= NumBits (%d)", i_bit, iv_NumBits);
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return false;
  }

  uint32_t index = i_bit/32;
  return (iv_Data[index] & 0x00000001 << (31 - (i_bit-(index * 32)))); 
}

bool   ecmdDataBufferBase::isBitSet(uint32_t i_bit, uint32_t i_len) const {
  if (i_bit+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::isBitSet: i_bit %d + i_len %d > NumBits (%d)", i_bit, i_len, iv_NumBits);
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return false;
  }

  bool rc = true;
  for (uint32_t i = 0; i < i_len; i++) {
    if (!this->isBitSet(i_bit + i)) {
      rc = false;
      break;
    }
  }
  return rc;
}

bool   ecmdDataBufferBase::isBitClear(uint32_t i_bit) const {
  if (i_bit >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::isBitClear: i_bit %d >= NumBits (%d)", i_bit, iv_NumBits);
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return false;
  }

  uint32_t index = i_bit/32;
  return (!(iv_Data[index] & 0x00000001 << (31 - (i_bit-(index * 32))))); 
}

bool ecmdDataBufferBase::isBitClear(uint32_t i_bit, uint32_t i_len) const
{
  if (i_bit+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::isBitClear: i_bit %d + i_len %d > NumBits (%d)", i_bit, i_len, iv_NumBits);
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return false;
  }

  bool rc = true;
  for (uint32_t i = 0; i < i_len; i++) {
    if (!this->isBitClear(i_bit + i)) {
      rc = false;
      break;
    }
  }

  return rc;
}

uint32_t ecmdDataBufferBase::getNumBitsSet(uint32_t i_bit, uint32_t i_len) const {
  if (i_bit+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::getNumBitsSet: i_bit %d + i_len %d > NumBits (%d)", i_bit, i_len, iv_NumBits);
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return 0;
  }
  static const uint8_t l_num_bits[] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
  };

  uint32_t count = 0;

  do {
    const uint32_t * p_data = iv_Data + i_bit / UNIT_SZ;
    int32_t slop = i_bit % UNIT_SZ;

    /* "cnt" = largest number of bits to be counted each pass */
    int32_t cnt = MIN(i_len, UNIT_SZ);
    cnt = MIN(cnt, UNIT_SZ - slop);

    uint32_t bits = *p_data;

    /* "slop" = unaligned bits */
    if (slop || cnt < UNIT_SZ)
      bits &= fast_mask32(slop, cnt);

    /* count the set bits in each byte */
    count += l_num_bits[(bits & 0x000000FF) >> 0];
    count += l_num_bits[(bits & 0x0000FF00) >> 8];
    count += l_num_bits[(bits & 0x00FF0000) >> 16];
    count += l_num_bits[(bits & 0xFF000000) >> 24];

    i_bit += cnt;
    i_len -= cnt;
  } while (0 < i_len);

  return count;
}

uint32_t ecmdDataBufferBase::shiftRight(uint32_t i_shiftNum, uint32_t i_offset) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  /* Error check */
  if (i_offset > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::shiftRight: i_offset %d > NumBits (%d)", i_offset, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  /* To shift the data, extact the piece being shifted and then re-insert it at the new location */
  ecmdDataBufferBase shiftData;

  // Get the hunk of data
  rc = extract(shiftData, i_offset, (iv_NumBits - i_offset));
  if (rc) return rc;

  // Clear the hole that was opened
  rc = clearBit(i_offset, i_shiftNum);
  if (rc) return rc;

  // Stick the data back in
  rc = insert(shiftData, (i_offset + i_shiftNum), (shiftData.getBitLength() - i_shiftNum));
  if (rc) return rc;

  return rc;
}

uint32_t ecmdDataBufferBase::shiftLeft(uint32_t i_shiftNum, uint32_t i_offset) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  /* If the offset is equal to 0xFFFFFFFF, take that to mean iv_NumBits, or the end of the buffer */
  if (i_offset == 0xFFFFFFFF) {
    i_offset = iv_NumBits;
  }

  /* Error check */
  if (i_offset > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::shiftLeft: i_offset %d > NumBits (%d)", i_offset, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  /* To shift the data, extact the piece being shifted and then re-insert it at the new location */
  ecmdDataBufferBase shiftData;

  // Get the hunk of data
  rc = extract(shiftData, 0, i_offset);
  if (rc) return rc;

  // Clear the hole that was opened
  rc = clearBit((i_offset - i_shiftNum), i_shiftNum);
  if (rc) return rc;

  // Stick the data back in
  rc = insert(shiftData, 0, (shiftData.getBitLength() - i_shiftNum), i_shiftNum);
  if (rc) return rc;

  return rc;
}


uint32_t ecmdDataBufferBase::shiftRightAndResize(uint32_t i_shiftNum, uint32_t i_offset) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t iv_NumBitsOrig = iv_NumBits;

  /* Make room in the data before we shift right */
  rc = growBitLength((iv_NumBitsOrig + i_shiftNum));
  if (rc) return rc;

  /* We have enough room, move our data over */
  rc = shiftRight(i_shiftNum, i_offset);
  if (rc) return rc;

 return rc;
}

uint32_t ecmdDataBufferBase::shiftLeftAndResize(uint32_t i_shiftNum) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  /* Move our data over */
  rc = shiftLeft(i_shiftNum);
  if (rc) return rc;

  /* Adjust our length based on the shift */
  rc = shrinkBitLength((iv_NumBits - i_shiftNum));
  if (rc) return rc;

  return rc;
}

uint32_t ecmdDataBufferBase::rotateRight(uint32_t i_rotateNum) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  /* The quickest way to rotate the data is to grab the two chunks and swap their position */
  ecmdDataBufferBase leftPart;
  ecmdDataBufferBase rightPart;

  // Grab the two pieces
  rc = extract(leftPart, 0, (iv_NumBits - i_rotateNum));
  if (rc) return rc;

  rc = extract(rightPart, (iv_NumBits - i_rotateNum), i_rotateNum);
  if (rc) return rc;

  // Stick the two pieces back together in a different order
  rc = insert(rightPart, 0, rightPart.getBitLength());
  if (rc) return rc;

  rc = insert(leftPart, rightPart.getBitLength(), leftPart.getBitLength());
  if (rc) return rc;

  return rc;
}

uint32_t ecmdDataBufferBase::rotateLeft(uint32_t i_rotateNum) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  /* The quickest way to rotate the data is to grab the two chunks and swap their position */
  ecmdDataBufferBase leftPart;
  ecmdDataBufferBase rightPart;

  // Grab the two pieces
  rc = extract(leftPart, 0, i_rotateNum);
  if (rc) return rc;

  rc = extract(rightPart, i_rotateNum, (iv_NumBits - i_rotateNum));
  if (rc) return rc;

  // Stick the two pieces back together in a different order
  rc = insert(rightPart, 0, rightPart.getBitLength());
  if (rc) return rc;

  rc = insert(leftPart, rightPart.getBitLength(), leftPart.getBitLength());
  if (rc) return rc;

  return rc;
}

uint32_t ecmdDataBufferBase::flushTo0() {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  if (getWordLength() > 0) {
    memset(iv_Data, 0x00, getWordLength() * 4); /* init to 0 */
  }
  return rc;
}

uint32_t ecmdDataBufferBase::flushTo1() {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  if (getWordLength() > 0) {
    memset(iv_Data, 0xFF, getWordLength() * 4); /* init to 1 */

    /* Call setword on the last word to mask off any extra bits past iv_NumBits */
    setWord((getWordLength()-1), 0xFFFFFFFF);

  }
  return rc;
}

uint32_t ecmdDataBufferBase::invert() { 
  uint32_t rc = ECMD_DBUF_SUCCESS;
  rc = this->flipBit(0, iv_NumBits);
  return rc;
}

uint32_t ecmdDataBufferBase::reverse() {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t l_words=0;
  uint32_t l_slop =  (iv_NumBits % UNIT_SZ);

  if (l_slop)
    l_words = iv_NumBits/32+1;
  else
    l_words = iv_NumBits/32;

  // reverse words
  for (uint32_t i=0;i< l_words/2;i++){
    uint32_t l_tmp = fast_reverse32(iv_Data[l_words-1-i]); 
    iv_Data[l_words-1-i] = fast_reverse32(iv_Data[i]);
    iv_Data[i] = l_tmp;
  }

  // if odd number of words, reverse middle word; if only 1 word, reverse this word
  if (l_words&1){
    iv_Data[l_words/2 ] = fast_reverse32(iv_Data[l_words/2]);
  }

  // now account for slop
  if (l_slop != 0){

    for (uint32_t i=0;i<l_words;i++){ // loop through all words

      if ((l_words>1)&&(i!=(l_words-1))){ // deal with most words here                
        uint32_t mask = 0xffffffff >> (32-l_slop);
        uint32_t tmp1 = (iv_Data[i]& mask)<< (32-l_slop);

        mask =~mask;
        uint32_t tmp2 = (iv_Data[i+1] & mask)>>l_slop;

        tmp1 |=tmp2;
        iv_Data[i]=tmp1;

      } else { //dealing with the last word separately; Also, handle if there is only one word here
        uint32_t mask = 0xffffffff >> (32-l_slop);
        iv_Data[l_words-1] = (iv_Data[l_words-1]& mask) <<(32-l_slop); 
      }
    } // end of for loop through all words
  } // end of slop check

  return rc;
}

uint32_t ecmdDataBufferBase::applyInversionMask(const ecmdDataBufferBase & i_invMaskBuffer, uint32_t i_invByteLen) {
  return applyInversionMask(i_invMaskBuffer.iv_Data, (i_invMaskBuffer.getByteLength() < i_invByteLen) ? i_invMaskBuffer.getByteLength() : i_invByteLen);
}


uint32_t ecmdDataBufferBase::applyInversionMask(const uint32_t * i_invMask, uint32_t i_invByteLen) {

  ECMD_NULL_PTR_CHECK(i_invMask);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  /* Do the smaller of data provided or size of buffer */
  uint32_t wordlen = (i_invByteLen / 4) + 1 < getWordLength() ? (i_invByteLen / 4) + 1 : getWordLength();

  for (uint32_t i = 0; i < wordlen; i++) {
    iv_Data[i] = iv_Data[i] ^ i_invMask[i]; /* Xor */
  }

  /* We need to make sure our last word is clean if numBits isn't on a word boundary */
  if ((wordlen == getWordLength()) && (iv_NumBits % 32)) {
    /* Reading out the last word and writing it back will clear any bad bits on */
    uint32_t myWord = getWord((wordlen-1));
    rc = setWord((wordlen-1), myWord);
    if (rc) return rc;
  }
     
  return rc;
}

inline uint32_t ecmdFastInsert(uint32_t *i_target, const uint32_t * i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart) {

  uint32_t rc = ECMD_DBUF_SUCCESS;

  do {
    const uint32_t * p_src = i_data + i_sourceStart / UNIT_SZ;
    uint32_t * p_trg = i_target + i_targetStart / UNIT_SZ;

    // "slop" = unaligned bits 
    int32_t src_slop = i_sourceStart % UNIT_SZ;
    int32_t trg_slop = i_targetStart % UNIT_SZ;
    // "shift" = amount of shifting needed for target alignment 
    int32_t shift = trg_slop - src_slop;

    int32_t cnt = i_len;

    // "cnt" = largest number of bits to be moved each pass 
    cnt = MIN(cnt, UNIT_SZ);
    cnt = MIN(cnt, UNIT_SZ - src_slop);
    cnt = MIN(cnt, UNIT_SZ - trg_slop);

    // generate the source mask only once 
    uint32_t mask = fast_mask32(src_slop, cnt);
    // read the source bits only once 
    uint32_t src_bits = *p_src & mask;

    // ideally (i << -1) would yield (i >> 1), but it
    //   doesn't, so we need an extra branch here 
    if (shift < 0) {
      shift = -shift;
      src_bits <<= shift;
      mask <<= shift;
    } else {
      src_bits >>= shift;
      mask >>= shift;
    }

    // clear source '0' bits in the target 
    *p_trg &= ~mask;
    // set source '1' bits in the target  
    *p_trg |= src_bits;


    i_sourceStart += cnt;
    i_targetStart += cnt;

    i_len -= cnt;
  } while (0 < i_len);

  return rc;  
}


uint32_t ecmdDataBufferBase::insert(const ecmdDataBufferBase &i_bufferIn, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart) {
  uint32_t rc = ECMD_DBUF_SUCCESS;    

  if (i_targetStart+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::insert: i_targetStart %d + i_len %d > iv_NumBits (%d)",
           i_targetStart, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_targetStart >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_targetStart %d >= iv_NumBits (%d)",
           i_targetStart, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_len %d > iv_NumBits (%d)",
           i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  rc = ecmdFastInsert(this->iv_Data,i_bufferIn.iv_Data, i_targetStart, i_len, i_sourceStart );
  if (rc) return rc;

  return rc;      
}

uint32_t ecmdDataBufferBase::insert(const uint32_t * i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart) {      
  ECMD_NULL_PTR_CHECK(i_data);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;
    
  if (i_targetStart+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::insert: i_targetStart %d + i_len %d > iv_NumBits (%d)", i_targetStart, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_targetStart >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_targetStart %d >= iv_NumBits (%d)", i_targetStart, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_len %d > iv_NumBits (%d)", i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
    
  rc = ecmdFastInsert(this->iv_Data,i_data, i_targetStart, i_len, i_sourceStart);
  if (rc) return rc;

  return rc;
}

uint32_t ecmdDataBufferBase::insert(uint32_t i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if ( i_sourceStart + i_len > 32 ) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_sourceStart %d + i_len %d > sizeof i_data (32)\n", i_sourceStart, i_len );
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_sourceStart >= 32) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insert: i_sourceStart %d >= sizeof i_data (32)", i_sourceStart);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > 32) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insert: i_len %d > sizeof i_data (32)", i_len);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks are perfomred in the insert function called below
  
  rc = this->insert(&i_data, i_targetStart, i_len, i_sourceStart);

  return rc;
}

uint32_t ecmdDataBufferBase::insertFromRight(const uint32_t * i_data, uint32_t i_start, uint32_t i_len) {

  ECMD_NULL_PTR_CHECK(i_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  int offset;
  if((i_len % 32) == 0) {
    offset = 0;
  } else {
    offset = 32 - (i_len % 32);
  }  

  if (i_start+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::insertFromRight: start %d + len %d > iv_NumBits (%d)", i_start, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks happen below in setBit and clearBit
    
  uint32_t mask = 0x80000000 >> offset;
  for (uint32_t i = 0; i < i_len; i++) {
    if (i_data[(i+offset)/32] & mask) {
      rc = this->setBit(i_start+i);
    }
    else { 
      rc = this->clearBit(i_start+i);
    }

    mask >>= 1;
    if (mask == 0x00000000) {
      mask = 0x80000000;
    }
    if (rc) break;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::insertFromRight(uint32_t i_data, uint32_t i_start, uint32_t i_len) {

  if (i_len > 32) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insertFromRight: i_len %d > sizeof i_data (32)", i_len);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    // other input checks are perfomred in the insertFromRight function called below
  }

  return this->insertFromRight(&i_data, i_start, i_len);
}

uint32_t ecmdDataBufferBase::insert(const uint16_t * i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart) {      
  ECMD_NULL_PTR_CHECK(i_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;
    
  if (i_targetStart+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::insert: i_targetStart %d + i_len %d > iv_NumBits (%d)", i_targetStart, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_targetStart >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_targetStart %d >= iv_NumBits (%d)", i_targetStart, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_len %d > iv_NumBits (%d)", i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
    
  for (uint32_t i = 0; i < i_len; i++) {

    int index = (i + i_sourceStart) / 16;
    if (i_data[index] & 0x00000001 << (15-(i+i_sourceStart -(index*16)))) {
      rc = this->setBit(i_targetStart + i);
    } else {
      rc = this->clearBit(i_targetStart + i);
    }
    if (rc) break;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::insert(uint16_t i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if ( i_sourceStart + i_len > 16) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_sourceStart %d + i_len %d > sizeof i_data (16)\n", i_sourceStart, i_len );
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_sourceStart >= 16) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insert: i_sourceStart %d >= sizeof i_data (16)", i_sourceStart);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > 16) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insert: i_len %d > sizeof i_data (16)", i_len);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks are perfomred in the insert function called below
  
  rc = this->insert(&i_data, i_targetStart, i_len, i_sourceStart);

  return rc;
}

uint32_t ecmdDataBufferBase::insertFromRight(const uint16_t * i_data, uint32_t i_start, uint32_t i_len) {

  ECMD_NULL_PTR_CHECK(i_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_start+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::insertFromRight: start %d + len %d > iv_NumBits (%d)", i_start, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks happen below in setBit and clearBit

  int offset;
  if ((i_len % 16) == 0) {
    offset = 0;
  } else {
    offset = 16 - (i_len % 16);
  }  
    
  uint16_t mask = 0x8000 >> offset;
  for (uint32_t i = 0; i < i_len; i++) {
    if (i_data[(i+offset)/16] & mask) {
      rc = this->setBit(i_start+i);
    }
    else { 
      rc = this->clearBit(i_start+i);
    }

    mask >>= 1;
    if (mask == 0x0000) {
      mask = 0x8000;
    }
    if (rc) break;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::insertFromRight(uint16_t i_data, uint32_t i_start, uint32_t i_len) {

  if (i_len > 16) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insertFromRight: i_len %d > sizeof i_data (16)", i_len);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    // other input checks are perfomred in the insertFromRight function called below
  }

  return this->insertFromRight(&i_data, i_start, i_len);
}

uint32_t ecmdDataBufferBase::insert(const uint8_t *i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart) {

  ECMD_NULL_PTR_CHECK(i_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_targetStart+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::insert: i_targetStart %d + i_len %d > iv_NumBits (%d)", i_targetStart, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    // other input checks are perfomred in the setBit(), clearBit() functions called below
  }

  for (uint32_t i = 0; i < i_len; i++) {

    int index = (i + i_sourceStart) / 8;
    if (i_data[index] & 0x00000001 << (7-(i+i_sourceStart -(index*8)))) {
      rc = this->setBit(i_targetStart + i);
    } else {
      rc = this->clearBit(i_targetStart + i);
    }
    if (rc) break;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::insert(uint8_t i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if ( i_sourceStart + i_len > 8) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::insert: i_sourceStart %d + i_len %d > sizeof i_data (8)\n", i_sourceStart, i_len );
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_sourceStart >= 8) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insert: i_sourceStart %d >= sizeof i_data (8)", i_sourceStart);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > 8) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insert: i_len %d > sizeof i_data (8)", i_len);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks are perfomred in the insert function called below
  
  rc = this->insert(&i_data, i_targetStart, i_len, i_sourceStart);

  return rc;
}

uint32_t ecmdDataBufferBase::insertFromRight(const uint8_t *i_data, uint32_t i_start, uint32_t i_len) {

  ECMD_NULL_PTR_CHECK(i_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  int offset;
  if((i_len % 8) == 0) {
    offset = 0;
  } else {
    offset = 8 - (i_len % 8);
  }  

  if (i_start+i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::insertFromRight: start %d + len %d > iv_NumBits (%d)", i_start, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks happen below in setBit and clearBit

  uint8_t mask = 0x80 >> offset;
  for (uint32_t i = 0; i < i_len; i++) {
    if (i_data[(i+offset)/8] & mask) {
      rc = this->setBit(i_start+i);
    }
    else { 
      rc = this->clearBit(i_start+i);
    }

    mask >>= 1;
    if (mask == 0x00) {
      mask = 0x80;
    }
    if (rc) break;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::insertFromRight(uint8_t i_data, uint32_t i_start, uint32_t i_len) {

  if (i_len > 8) {
    ETRAC1("**** ERROR : ecmdDataBufferBase::insertFromRight: i_len %d > sizeof i_data (8)", i_len);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    // other input checks are perfomred in the insertFromRight function called below
  }

  return this->insertFromRight(&i_data, i_start, i_len);
}

uint32_t ecmdDataBufferBase::extract(ecmdDataBufferBase& o_bufferOut, uint32_t i_start, uint32_t i_len) const {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  // ecmdExtract can't make good input checks, so we have to do that here
  if (i_start + i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::extract: start %d + len %d > iv_NumBits (%d)\n", i_start, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_start >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::extract: start %d >= iv_NumBits (%d)\n", i_start, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::extract: len %d > iv_NumBits (%d)\n", i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  rc = o_bufferOut.setBitLength(i_len);
  if (rc) return rc;

  rc = ecmdExtract(this->iv_Data, i_start, i_len, o_bufferOut.iv_Data);
  if (rc) return rc;   

  return rc;
}

uint32_t ecmdDataBufferBase::extract(uint32_t *o_data, uint32_t i_start, uint32_t i_len) const {

  ECMD_NULL_PTR_CHECK(o_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  // ecmdExtract can't make good input checks, so we have to do that here
  if (i_start + i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::extract: i_start %d + i_len %d > iv_NumBits (%d)\n", i_start, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_start >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::extract: i_start %d >= iv_NumBits (%d)", i_start, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::extract: i_len %d > iv_NumBits (%d)", i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len == 0) {
    return ECMD_DBUF_SUCCESS;
  }

  rc = ecmdExtract(this->iv_Data, i_start, i_len, o_data);
  if (rc) {
    RETURN_ERROR(rc);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::extract(uint16_t *o_data, uint32_t i_start, uint32_t i_len) const {

  ECMD_NULL_PTR_CHECK(o_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  // ecmdExtract can't make good input checks, so we have to do that here
  if (i_start + i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::extract: i_start %d + i_len %d > iv_NumBits (%d)\n", i_start, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_start >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::extract: i_start %d >= iv_NumBits (%d)", i_start, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::extract: i_len %d > iv_NumBits (%d)", i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_len == 0) {
    return ECMD_DBUF_SUCCESS;
  }

  // Put the users data into a temporary buffer, which will align it on byte boundaries.
  // Then just loop over the extractBuffer, placing it byte by byte into o_data
  ecmdDataBufferBase extractBuffer(i_len);
  rc = extractBuffer.insert(*this, 0, i_len, i_start);
  if (rc) {
    RETURN_ERROR(rc);
  }

  // Now do a byte loop, setting the data in o_data
  int numHalfWords = extractBuffer.getHalfWordLength();
  for (int i = 0; i < numHalfWords; i++) {
    o_data[i] = extractBuffer.getHalfWord(i);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::extract(uint8_t * o_data, uint32_t i_start, uint32_t i_bitLen) const {

  ECMD_NULL_PTR_CHECK(o_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  // Error checking
  if (i_start + i_bitLen > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::extract: i_start %d + i_bitLen %d > iv_NumBits (%d)\n", i_start, i_bitLen, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_start >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::extract: i_start %d >= iv_NumBits (%d)", i_start, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_bitLen > iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::extract: i_bitLen %d > iv_NumBits (%d)", i_bitLen, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_bitLen == 0) {
    return ECMD_DBUF_SUCCESS;
  }

  // Put the users data into a temporary buffer, which will align it on byte boundaries.
  // Then just loop over the extractBuffer, placing it byte by byte into o_data
  ecmdDataBufferBase extractBuffer(i_bitLen);
  rc = extractBuffer.insert(*this, 0, i_bitLen, i_start);
  if (rc) {
    RETURN_ERROR(rc);
  }

  // Now do a byte loop, setting the data in o_data
  int numBytes = extractBuffer.getByteLength();
  for (int i = 0; i < numBytes; i++) {
    o_data[i] = extractBuffer.getByte(i);
  }

  return rc;
}


// extractPreserve() takes data from current and inserts it in the passed in
//  buffer at a given offset. This is the same as insert() with the args and
//  the data flow reversed, so insert() is called to do the work
uint32_t ecmdDataBufferBase::extractPreserve(ecmdDataBufferBase & o_bufferOut, uint32_t i_start, uint32_t i_len, uint32_t i_targetStart) const {
  // input checks done in the insert function
  return o_bufferOut.insert( *this, i_targetStart, i_len, i_start );
}

// extractPreserve() with a generic data buffer is hard to work on, so the
// output buffer is first copied into an ecmdDataBufferBase object, then insert()
// is called to do the work
uint32_t ecmdDataBufferBase::extractPreserve(uint32_t *o_outBuffer, uint32_t i_start, uint32_t i_len, uint32_t i_targetStart) const {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  // input checks done in the insert function

  const uint32_t numWords = ( i_targetStart + i_len + 31 ) / 32;
  if ( numWords == 0 ) return rc;

  ecmdDataBufferBase *tempBuf = new ecmdDataBufferBase;

  if ( NULL == tempBuf ) {
    ETRAC0("**** ERROR : ecmdDataBufferBase::extractPreserve : Unable to allocate memory for new databuffer\n");
    RETURN_ERROR(ECMD_DBUF_INIT_FAIL);
  } 

  if(o_outBuffer == NULL)
  {
      ETRAC0("**** ERROR : ecmdDataBufferBase::extractPreserve : o_outBuffer of type uint32_t * is not initialized. NULL buffer passed.");
      delete tempBuf;
      tempBuf = NULL;
      RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  rc = tempBuf->setWordLength( numWords );

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->memCopyIn( o_outBuffer, numWords * 4);

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->insert( *this, i_targetStart, i_len, i_start);

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->memCopyOut( o_outBuffer, numWords * 4);

  delete tempBuf;
  return rc;
}

// extractPreserve() with a generic data buffer is hard to work on, so the
// output buffer is first copied into an ecmdDataBufferBase object, then insert()
// is called to do the work
uint32_t ecmdDataBufferBase::extractPreserve(uint16_t *o_outBuffer, uint32_t i_start, uint32_t i_len, uint32_t i_targetStart) const {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  // input checks done in the insert function

  const uint32_t numHalfWords = ( i_targetStart + i_len + 15 ) / 16;
  if ( numHalfWords == 0 ) return rc;

  ecmdDataBufferBase *tempBuf = new ecmdDataBufferBase;

  if ( NULL == tempBuf ) {
    ETRAC0("**** ERROR : ecmdDataBufferBase::extractPreserve : Unable to allocate memory for new databuffer\n");
    RETURN_ERROR(ECMD_DBUF_INIT_FAIL);
  } 

  if(o_outBuffer == NULL)
  {
      ETRAC0("**** ERROR : ecmdDataBufferBase::extractPreserve : o_outBuffer of type uint16_t * is not initialized. NULL buffer passed.");
      delete tempBuf;
      tempBuf = NULL;
      RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  rc = tempBuf->setHalfWordLength(numHalfWords);

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->memCopyIn( o_outBuffer, numHalfWords * 2);

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->insert( *this, i_targetStart, i_len, i_start);

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->memCopyOut( o_outBuffer, numHalfWords * 2);

  delete tempBuf;
  return rc;
}

uint32_t ecmdDataBufferBase::extractPreserve(uint8_t * o_data, uint32_t i_start, uint32_t i_len, uint32_t i_targetStart) const {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  // input checks done in the insert function

  const uint32_t numBytes = ( i_targetStart + i_len + 7 ) / 8;
  if ( numBytes == 0 ) return rc;

  ecmdDataBufferBase *tempBuf = new ecmdDataBufferBase;

  if ( NULL == tempBuf ) {
    ETRAC0("**** ERROR : ecmdDataBufferBase::extractPreserve : Unable to allocate memory for new databuffer\n");
    RETURN_ERROR(ECMD_DBUF_INIT_FAIL);
  } 

  if(o_data == NULL)
  {
      ETRAC0("**** ERROR : ecmdDataBufferBase::extractPreserve : o_data of type uint8_t * is not initialized. NULL buffer passed.");
      delete tempBuf;
      tempBuf = NULL;
      RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  rc = tempBuf->setByteLength( numBytes );

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->memCopyIn( o_data, numBytes);

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->insert( *this, i_targetStart, i_len, i_start);

  if ( rc == ECMD_DBUF_SUCCESS ) 
    rc = tempBuf->memCopyOut( o_data, numBytes);

  delete tempBuf;
  return rc;
} 

uint32_t ecmdDataBufferBase::extractToRight(ecmdDataBufferBase & o_bufferOut, uint32_t i_start, uint32_t i_len) const {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  // input checks done in the extract function
  rc = this->extract(o_bufferOut, i_start, i_len);
  if (rc) return rc;

  if (i_len < 32)
    rc = o_bufferOut.shiftRightAndResize(32 - i_len);
  return rc;
}

uint32_t ecmdDataBufferBase::extractToRight(uint32_t * o_data, uint32_t i_start, uint32_t i_len) const {

  ECMD_NULL_PTR_CHECK(o_data);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;

  // input checks done in the extract function
  rc = this->extract(o_data, i_start, i_len);

  if (i_len < 32)
    *o_data >>= (32 - i_len);
  return rc;
}

uint32_t ecmdDataBufferBase::extractToRight(uint16_t * o_data, uint32_t i_start, uint32_t i_len) const {

  ECMD_NULL_PTR_CHECK(o_data);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;

  // input checks done in the extract function
  rc = this->extract(o_data, i_start, i_len);

  if (i_len < 16) {
    *o_data >>= (16 - i_len);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::extractToRight(uint8_t * o_data, uint32_t i_start, uint32_t i_len) const {

  ECMD_NULL_PTR_CHECK(o_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;
  // input checks done in the extract function
  rc = this->extract(o_data, i_start, i_len);

  if (i_len < 8)
    *o_data >>= (8 - i_len);
  return rc;
} 

uint32_t ecmdDataBufferBase::concat(const ecmdDataBufferBase & i_buf0, const ecmdDataBufferBase & i_buf1) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  rc = this->setBitLength(i_buf0.iv_NumBits + i_buf1.iv_NumBits); if (rc) return rc;
  rc = this->insert(i_buf0, 0, i_buf0.iv_NumBits); if (rc) return rc;
  rc = this->insert(i_buf1, i_buf0.iv_NumBits, i_buf1.iv_NumBits);
  return rc;
}

uint32_t ecmdDataBufferBase::concat(const std::vector<ecmdDataBufferBase> & i_bufs) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t totalSize = 0, offset = 0, x;
  /* Loop through and get the total bit size and set length */
  for (x = 0; x < i_bufs.size(); x++) {
    totalSize += i_bufs[x].iv_NumBits;
  }
  rc = this->setBitLength(totalSize); if (rc) return rc;

  /* Now that the size is set, loop through and insert */
  for (x = 0; x < i_bufs.size(); x++) {
    rc = this->insert(i_bufs[x], offset, i_bufs[x].iv_NumBits); if (rc) return rc;
    offset += i_bufs[x].iv_NumBits;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::setOr(const ecmdDataBufferBase& i_bufferIn, uint32_t i_startBit, uint32_t i_len) {
  if (i_len > i_bufferIn.iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::setOr: len %d > NumBits of incoming buffer (%d)", i_len, i_bufferIn.iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  return this->setOr(i_bufferIn.iv_Data, i_startBit, i_len);
}

uint32_t ecmdDataBufferBase::setOr(const uint32_t * i_data, uint32_t i_startBit, uint32_t i_len) {

  ECMD_NULL_PTR_CHECK(i_data);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_startBit + i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::setOr: bit %d + len %d > NumBits (%d)", i_startBit, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks done as part of setBit()

  uint32_t mask = 0x80000000;
  for (uint32_t i = 0; i < i_len; i++) {
    if (i_data[i/32] & mask) {
      rc = this->setBit(i_startBit + i);
    }
    mask >>= 1;
    if (mask == 0x00000000) {
      mask = 0x80000000;
    }
    if (rc) break;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::setOr(uint32_t i_data, uint32_t i_startBit, uint32_t i_len) {
  // input checks done as part of setOr()
  return this->setOr(&i_data, i_startBit, i_len);
}

uint32_t ecmdDataBufferBase::setXor(const ecmdDataBufferBase& i_bufferIn, uint32_t i_startBit, uint32_t i_len) {
  if (i_len > i_bufferIn.iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::setXor: len %d > NumBits of incoming buffer (%d)", i_len, i_bufferIn.iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks done as part of setXor()
  return this->setXor(i_bufferIn.iv_Data, i_startBit, i_len);
}

uint32_t ecmdDataBufferBase::setXor(const uint32_t * i_data, uint32_t i_startBit, uint32_t i_len) {

  ECMD_NULL_PTR_CHECK(i_data);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_startBit + i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::setOr: bit %d + len %d > NumBits (%d)", i_startBit, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks done as part of writeBit()

  uint32_t mask = 0x80000000;
  for (uint32_t i = 0; i < i_len; i++) {
    rc = this->writeBit(i_startBit + i, ((i_data[i/32] & mask) ^ (this->iv_Data[i/32] & mask)));
    mask >>= 1;
    if (mask == 0x00000000) {
      mask = 0x80000000;
    }
    if (rc) break;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::setXor(uint32_t i_data, uint32_t i_startBit, uint32_t i_len) {
  // input checks done as part of setXor()
  return this->setXor(&i_data, i_startBit, i_len);
}

uint32_t ecmdDataBufferBase::merge(const ecmdDataBufferBase& i_bufferIn) {
  if (iv_NumBits != i_bufferIn.iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::merge: NumBits in (%d) do not match NumBits (%d)", i_bufferIn.iv_NumBits, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else {
    return this->setOr(i_bufferIn, 0, iv_NumBits);
  }
}

uint32_t ecmdDataBufferBase::setAnd(const ecmdDataBufferBase& i_bufferIn, uint32_t i_startBit, uint32_t i_len) {
  if (i_len > i_bufferIn.iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::setAnd: len %d > NumBits of incoming buffer (%d)", i_len, i_bufferIn.iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }
  // other input checks done as part of setAnd()
  return this->setAnd(i_bufferIn.iv_Data, i_startBit, i_len);
}

uint32_t ecmdDataBufferBase::setAnd(const uint32_t * i_data, uint32_t i_startBit, uint32_t i_len) {

  ECMD_NULL_PTR_CHECK(i_data);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (i_startBit + i_len > iv_NumBits) {
    ETRAC3("**** ERROR : ecmdDataBufferBase::setAnd: i_start %d + i_len %d > iv_NumBits (%d)", i_startBit, i_len, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    // other input checks done as part of setClearBit()
  }

  uint32_t mask = 0x80000000;
  for (uint32_t i = 0; i < i_len; i++) {
    if (!(i_data[i/32] & mask)) {
      this->clearBit(i_startBit + i);
    }
    mask >>= 1;
    if (mask == 0x00000000) {
      mask = 0x80000000;
    }
    if (rc) break;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::setAnd(uint32_t i_data, uint32_t i_startBit, uint32_t i_len) {
  // input checks done as part of setAnd()
  return this->setAnd(&i_data, i_startBit, i_len);
}

uint32_t ecmdDataBufferBase::oddParity(uint32_t i_start, uint32_t i_stop) const {
  int charOffset;
  int posOffset;
  uint32_t counter;
  int parity = 1;
  uint32_t mask;

  if (i_start >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::oddParity: i_start %d >= iv_NumBits (%d)\n", i_start, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_stop >= iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::oddParity: i_stop %d >= iv_NumBits (%d)\n", i_stop, iv_NumBits);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (i_start > i_stop) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::oddParity: i_start %d >= i_stop (%d)\n", i_start, i_stop);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else {

    charOffset = i_start / 32;
    posOffset = i_start - charOffset * 32;
    mask = 0x80000000 >> posOffset;

    for (counter = 0; counter < (i_stop - i_start + 1); counter++) {
      if (mask & iv_Data[charOffset]) {
        parity ^= 1;
      }
      posOffset++;
      mask >>= 1;
      if (posOffset > 31) {
        charOffset++;
        posOffset = 0;
        mask = 0x80000000;
      }
    }

  }

  return parity;
}

uint32_t ecmdDataBufferBase::evenParity(uint32_t i_start, uint32_t i_stop) const {
  // input checks done as part of oddParity()
  if (this->oddParity(i_start, i_stop)) {
    return 0;
  } else {
    return 1;
  }
}

uint32_t ecmdDataBufferBase::oddParity(uint32_t i_start, uint32_t i_stop, uint32_t i_insertPos) {
  // input checks done as part of oddParity()
  if (this->oddParity(i_start,i_stop)) {
    this->setBit(i_insertPos);
  } else { 
    this->clearBit(i_insertPos);
  }

  return 0;
}

uint32_t ecmdDataBufferBase::evenParity(uint32_t i_start, uint32_t i_stop, uint32_t i_insertPos) {
  // input checks done as part of evenParity()...which calls oddParity
  if (this->evenParity(i_start,i_stop)) {
    this->setBit(i_insertPos);
  } else {
    this->clearBit(i_insertPos);
  }

  return 0;
}

uint32_t ecmdDataBufferBase::getWord(uint32_t i_wordOffset) const {
  if (i_wordOffset >= getWordLength()) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::getWord: i_wordOffset %d >= NumWords (%d)", i_wordOffset, getWordLength());
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
    return 0;
  }

  return this->iv_Data[i_wordOffset];
}

uint32_t ecmdDataBufferBase::copy(ecmdDataBufferBase &o_newCopy) const {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  rc = o_newCopy.setBitLength(iv_NumBits);
  
  if (!rc && iv_NumBits != 0) {
    // iv_Data
    memcpy(o_newCopy.iv_Data, iv_Data, getWordLength() * 4);
    // Error state
    o_newCopy.iv_RealData[EDB_RETURN_CODE] = iv_RealData[EDB_RETURN_CODE];
  }
  return rc;

}

/* Copy Constructor */
ecmdDataBufferBase& ecmdDataBufferBase::operator=(const ecmdDataBufferBase & i_master) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  rc = setBitLength(i_master.iv_NumBits);

  if (!rc && iv_NumBits != 0) {
    // iv_Data
    memcpy(iv_Data, i_master.iv_Data, getWordLength() * 4);
    // Error state
    iv_RealData[EDB_RETURN_CODE] = i_master.iv_RealData[EDB_RETURN_CODE];
  }
  return *this;
}


uint32_t ecmdDataBufferBase::memCopyIn(const uint32_t* i_buf, uint32_t i_bytes) { /* Does a memcpy from supplied buffer into ecmdDataBufferBase */

  ECMD_NULL_PTR_CHECK(i_buf);

  uint32_t rc = ECMD_DBUF_SUCCESS;

  uint32_t cbytes = i_bytes < getByteLength() ? i_bytes : getByteLength();
  if (cbytes == 0) {
    ETRAC0("**** ERROR : ecmdDataBufferBase: memCopyIn: Copy performed on buffer with length of 0");
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  ecmdBigEndianMemCopy(iv_Data, i_buf, cbytes);

  /* We're worried we might have data on in our last byte copied in that excedes numbits */
  if (cbytes == getByteLength()) {
    /* We'll cheat and do a getByte and then write that value back so the masking logic is done */
    uint8_t myByte = getByte((getByteLength() - 1));
    rc = setByte((getByteLength() - 1), myByte);
    if (rc) return rc;
  }

  return rc;
}

uint32_t ecmdDataBufferBase::memCopyOut(uint32_t* o_buf, uint32_t i_bytes) const { /* Does a memcpy from ecmdDataBufferBase into supplied buffer */

  ECMD_NULL_PTR_CHECK(o_buf);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t cbytes = i_bytes < getByteLength() ? i_bytes : getByteLength();
  if (cbytes == 0) {
    ETRAC0("**** ERROR : ecmdDataBufferBase: memCopyOut: Copy performed on buffer with length of 0");
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  ecmdBigEndianMemCopy(o_buf, iv_Data, cbytes);

  return rc;
}

uint32_t ecmdDataBufferBase::memCopyIn(const uint16_t* i_buf, uint32_t i_bytes) { /* Does a memcpy from supplied buffer into ecmdDataBufferBase */

  ECMD_NULL_PTR_CHECK(i_buf);

  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t cbytes = i_bytes < getByteLength() ? i_bytes : getByteLength();
  uint32_t numHalfWords = (cbytes + 1) / 2;
  if (cbytes == 0) {
    ETRAC0("**** ERROR : ecmdDataBufferBase: memCopyIn: Copy performed on buffer with length of 0");
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  for (uint32_t i = 0; i < numHalfWords; i++) {
    setHalfWord(i, i_buf[i]);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::memCopyOut(uint16_t* o_buf, uint32_t i_bytes) const { /* Does a memcpy from ecmdDataBufferBase into supplied buffer */

  ECMD_NULL_PTR_CHECK(o_buf);

  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t cbytes = i_bytes < getByteLength() ? i_bytes : getByteLength();
  uint32_t numHalfWords = (cbytes + 1) / 2;
  if (cbytes == 0) {
    ETRAC0("**** ERROR : ecmdDataBufferBase: memCopyOut: Copy performed on buffer with length of 0");
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  for (uint32_t i = 0; i < numHalfWords; i++) {
    o_buf[i] = getHalfWord(i);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::memCopyIn(const uint8_t* i_buf, uint32_t i_bytes) { /* Does a memcpy from supplied buffer into ecmdDataBufferBase */
  
  ECMD_NULL_PTR_CHECK(i_buf);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t cbytes = i_bytes < getByteLength() ? i_bytes : getByteLength();
  if (cbytes == 0) {
    ETRAC0("**** ERROR : ecmdDataBufferBase: memCopyIn: Copy performed on buffer with length of 0");
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  for (uint32_t i=0; i<cbytes; i++) {
    setByte(i, i_buf[i]);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::memCopyOut(uint8_t* o_buf, uint32_t i_bytes) const { /* Does a memcpy from supplied buffer into ecmdDataBufferBase */

  ECMD_NULL_PTR_CHECK(o_buf);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t cbytes = i_bytes < getByteLength() ? i_bytes : getByteLength();
  if (cbytes == 0) {
    ETRAC0("**** ERROR : ecmdDataBufferBase: memCopyIn: Copy performed on buffer with length of 0");
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  for (uint32_t i=0; i<cbytes; i++) {
    o_buf[i] = getByte(i);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::flatten(uint8_t * o_data, uint32_t i_len) const {

  ECMD_NULL_PTR_CHECK(o_data);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;

  uint32_t * o_ptr = (uint32_t *) o_data;

  if ((i_len < 8) || (iv_Capacity*32 > ((i_len - 8) * 8))) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::flatten: i_len %d bytes is too small to flatten a capacity of %d words ", i_len, iv_Capacity);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  memset(o_data, 0, this->flattenSize());
  o_ptr[0] = htonl(iv_Capacity*32);
  o_ptr[1] = htonl(iv_NumBits);
  if (iv_Capacity > 0) {
    for (uint32_t i = 0; i < iv_Capacity; i++)
      o_ptr[2+i] = htonl(iv_Data[i]);
  }

  return rc;
}

uint32_t ecmdDataBufferBase::unflatten(const uint8_t * i_data, uint32_t i_len) {

  ECMD_NULL_PTR_CHECK(i_data);
  
  uint32_t rc = ECMD_DBUF_SUCCESS;

  uint32_t newCapacity;
  uint32_t newBitLength;
  uint32_t * i_ptr = (uint32_t *) i_data;
  uint32_t newWordLength;

  newCapacity = (ntohl(i_ptr[0]) + 31) / 32;
  newBitLength = ntohl(i_ptr[1]);

  if ((i_len < 8) || (newCapacity > ((i_len - 8) * 8))) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::unflatten: i_len %d bytes is too small to unflatten a capacity of %d words ", i_len, newCapacity);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else if (newBitLength > newCapacity * 32) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::unflatten: iv_NumBits %d cannot be greater than iv_Capacity*32 %d", newBitLength, newCapacity*32);
    RETURN_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  }

  rc = this->setCapacity(newCapacity);
  if (rc != ECMD_DBUF_SUCCESS) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::unflatten: this->setCapacity() Failed. rc=0x%08x, newCapacity = %d words ", rc, newCapacity);
    RETURN_ERROR(rc);
  }

  rc = this->setBitLength(newBitLength);
  if (rc != ECMD_DBUF_SUCCESS) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::unflatten: this->setBitLength() Failed. rc=0x%08x, newBitLength = %d bits ", rc, newBitLength);
    RETURN_ERROR(rc);
  }

  newWordLength = getWordLength();
  if (newCapacity > 0) {
    for (uint32_t i = 0; i < newWordLength ; i++) {
      rc = setWord(i, ntohl(i_ptr[i+2]));
      if (rc != ECMD_DBUF_SUCCESS) {
        ETRAC5("**** ERROR : ecmdDataBufferBase::unflatten: this->setWord() Failed. rc=0x%08x  newBitLength = %d bits, newWordLength= %d words, newCapacity = %d words, loop parm i = %d ", rc, newBitLength, newWordLength, newCapacity, i);
        RETURN_ERROR(rc);
      }
    }
  }

  return rc;
}

uint32_t ecmdDataBufferBase::flattenSize() const {
  return (iv_Capacity + 2) * 4;
}


int ecmdDataBufferBase::operator == (const ecmdDataBufferBase& i_other) const {

  /* Check the length */
  uint32_t maxBits = 32;
  uint32_t numBits = getBitLength();
  uint32_t numToFetch = numBits < maxBits ? numBits : maxBits;
  uint32_t myData, otherData;
  uint32_t wordCounter = 0;

  if (getBitLength() != i_other.getBitLength()) {
    return 0;
  }

  if (getBitLength() == 0) /* two empty buffers are equal */
    return 1;

  /* Now run through the data */
  while (numToFetch > 0) {

    myData = iv_Data[wordCounter];
    otherData = i_other.iv_Data[wordCounter];

    if (numToFetch == maxBits) {
      if (myData != otherData) 
        return 0;
    }
    else {
      uint32_t mask = 0x80000000;
      for (uint32_t i = 0; i < numToFetch; i++, mask >>= 1) {
        if ( (myData & mask) != (otherData & mask) ) {
          return 0;
        }
      }
    }

    numBits -= numToFetch;
    numToFetch = (numBits < maxBits) ? numBits : maxBits;
    wordCounter++;
  }

  /* Must have matched */
  return 1;
}

int ecmdDataBufferBase::operator != (const ecmdDataBufferBase& i_other) const {
  return !(*this == i_other);
}

ecmdDataBufferBase ecmdDataBufferBase::operator & (const ecmdDataBufferBase& i_other) const {

  ecmdDataBufferBase newItem = *this;

  if (iv_NumBits != i_other.iv_NumBits) {
    ETRAC2("**** ERROR : ecmdDataBufferBase::operater &: NumBits in (%d) do not match NumBits (%d)", i_other.iv_NumBits, iv_NumBits);
    SET_ERROR(ECMD_DBUF_BUFFER_OVERFLOW);
  } else {
    newItem.setAnd(i_other.iv_Data, 0, iv_NumBits);
  }

  return newItem;
}

ecmdDataBufferBase ecmdDataBufferBase::operator | (const ecmdDataBufferBase& i_other) const {

  ecmdDataBufferBase newItem = *this;

  newItem.setOr(i_other.iv_Data, 0, iv_NumBits);

  return newItem;
}


uint32_t ecmdExtract(uint32_t *i_sourceData, uint32_t i_startBit, uint32_t i_numBitsToExtract, uint32_t *o_destData) {
  uint32_t temp;
  uint32_t len; 
  uint32_t mask1;
  uint32_t mask2;
  uint32_t offset;
  uint32_t index; 
  uint32_t count; 

  // Error check
  if ((i_numBitsToExtract == 0) || (i_sourceData == NULL)){
    ETRAC0("**** ERROR : ecmdDataBufferBase ecmdExtract: Number of bits to extract = 0");
    o_destData = NULL;
    return ECMD_DBUF_INVALID_ARGS;
  } 

  count = (i_numBitsToExtract + 31) / 32;

  /*------------------------------------------------------------------*/
  /* calculate number of fws (32-bit pieces) of the destination buffer*/
  /* to be processed.                                                 */
  /*----------------------------line 98-------------------------------*/
  /* all 32-bit (or < 32 bits) pieces of the destination buffer */
  for (uint32_t i = 0; i < count; i++) {

    len = i_numBitsToExtract;
    /* length of bits to process is > 32 */
    if (len > 32) {
      len = 32;
    }

    /*******************************************************************/
    /* calculate index for accessing proper fw of the scan ring buffer */
    /*******************************************************************/
    index = i_startBit/32;

    /*----------------------------------------------------------------*/
    /* generate the mask to zero out some extra extracted bits (if    */
    /* there are any) in the temporary buffer.                        */
    /*----------------------------------------------------------------*/
    if (len == 32) {
      mask1 = 0xFFFFFFFF;
    } else {
      mask1 = ~(0xFFFFFFFF << len);
    }

    /*-------------line 121--------------------------------------------*/
    /* generate the mask to prevent zeroing of unused bits positions  */
    /* in the destination buffer.                                     */
    /*----------------------------------------------------------------*/
    if (len == 0) {
      mask2 = 0xFFFFFFFF;
    } else {
      mask2 = ~(mask1 << (32-len));
    }

    /******************************************************************/
    /* NOTE:- In this loop a max of 32 bits are extracted at a time.  */
    /* we may require to access either one or two fw's of scan ring   */
    /* buffer depending on the starting bit position & number of bits */
    /* to be extracted.                                               */
    /******************************************************************/
    /* only one fw of scan ring buffer required to do extract */
    if (index == ((i_startBit + (len-1))/32)) {
      /*--------------------------------------------------------------*/
      /* Extract required bits from the proper fw of the scan ring    */
      /* buffer as shown below (follow the steps):                    */
      /* step1 - right justify bits to be extracted from the fw of the*/
      /*         scan ring buffer.(we may have extra bits which are   */
      /*         not required to be extracted, in the high order bit  */
      /*         positions but they will be masked off later on).     */
      /* step2 - left justify the extracted bits in the temp buffer.  */
      /* result = (dest buffer with reqd bits zeroed) | step2         */
      /*          (Unused bit positions in the dest buffer will not   */
      /*           be changed.)                                       */
      /*--------------------------------------------------------------*/
      /* step1 */
      temp = ((*(i_sourceData + index)) >> (32-((i_startBit + len) - (index*32))));
      if ((32-((i_startBit + len) - (index*32))) >= 32)
        temp = 0x0;

      if ((32 - len) >= 32)
        temp = 0x0;
      else
        temp = (temp & mask1) << (32 - len); /* step2 */

      *(o_destData + i) = (*(o_destData + i) & mask2) | temp;
      /* two fws of scan ring buffer required to do extract */
    } else {
      /*-----------------line 158--------------------------------------*/
      /* calculate number of bits to process in the 1st fw of the     */
      /* scan ring buffer.(fw pointed by index)                       */
      /*--------------------------------------------------------------*/
      offset = (32 * (index + 1)) - i_startBit;

      /*--------------------------------------------------------------*/
      /* Extract required bits from the proper fws of the scan ring   */
      /* buffer as shown below (follow the steps):                    */
      /* step1 - Shift 1st fw of the scan ring buffer left by the     */
      /*         number of bits to be extracted from the 2nd fw.      */
      /*         Shift 2nd fw of the scan ring buffer right such that */
      /*         the required bits to be extracted are right justifed */
      /*         in that fw.                                          */
      /*         OR the results of the above shifts and save it in a  */
      /*         temporary buffer. (we will have required bits        */
      /*         extracted and right justifed in the temp buffer. Also*/
      /*         we may have some extra bits in the high order bits   */
      /*         position of the temp buffer, but they will be masked */
      /*         off later on.)                                       */
      /* step2 - left justify the extracted bits in the temp buffer.  */
      /* result = (dest buffer with reqd bits zeroed) | step2         */
      /*          (Unused bit positions in the dest buffer will not   */
      /*           be changed.)                                       */
      /*--------------------------------------------------------------*/
      /* step1 */
      uint32_t val1 = 0x0;
      uint32_t val2 = 0x0;
      if (len-offset < 32) {
        val1 = ((*(i_sourceData+index)) << (len-offset));  /* 1st fw*/
      }

      if ((32-(len-offset)) < 32) {
        val2 = ((*(i_sourceData+index+1)) >> (32-(len-offset)));
      }
      temp = (val1 | val2);/* 2nd fw */

      if (32-len >= 32) {
        temp = 0x0;
      } else {
        temp = (temp & mask1) << (32-len); /* step2 */
      }

      *(o_destData+i) = (*(o_destData+i) & mask2) | temp;
    }
    i_numBitsToExtract -= 32; /* decrement length by a fw */
    i_startBit += 32; /* increment start by a fw */
  }

  return ECMD_DBUF_SUCCESS;
}

uint32_t ecmdDataBufferBase::shareBuffer(ecmdDataBufferBase* i_sharingBuffer)
{
    uint32_t rc = ECMD_DBUF_SUCCESS;

    if(i_sharingBuffer == NULL)
    return(ECMD_DBUF_INVALID_ARGS);
    //delete data if currently has any
    if (i_sharingBuffer->iv_RealData != NULL)
    {
    i_sharingBuffer->clear();
    }

    //copy the buffer called from minus the owner flag
    i_sharingBuffer->iv_Capacity = iv_Capacity;
    i_sharingBuffer->iv_NumBits = iv_NumBits;
    i_sharingBuffer->iv_Data = iv_Data;
    i_sharingBuffer->iv_RealData = iv_RealData;
    i_sharingBuffer->iv_UserOwned = false;
    return(rc);
}

void ecmdDataBufferBase::queryErrorState( uint32_t & o_errorState) {
  if (iv_RealData != NULL) {
    o_errorState = iv_RealData[EDB_RETURN_CODE];
  } else {
    o_errorState = 0;
  }
}

/* Here is the plan for the compression format
 3 byte header, includes a version
 4 byte length
 Then the data as returned by the compression algorithm that PRD is kindly letting us use
*/

uint32_t ecmdDataBufferBase::compressBuffer(ecmdCompressionMode_t i_mode) {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  ecmdDataBufferBase compressedBuffer;
  uint32_t byteOffset = 0;

  /* Get the length, and make sure it doesn't over flow our length variable */
  uint32_t length = this->getBitLength();

  /* Set it big enough for the header/length below.  Then we'll grow as need */
  compressedBuffer.setBitLength(56);

  /* Set the header, which is C2A3FV, where V is the version */
  compressedBuffer.setByte(byteOffset++, 0xC2);
  compressedBuffer.setByte(byteOffset++, 0xA3);
  if (i_mode == ECMD_COMP_PRD) {
    compressedBuffer.setByte(byteOffset++, 0xF2);
  } else if (i_mode == ECMD_COMP_ZLIB || i_mode == ECMD_COMP_ZLIB_SPEED || i_mode == ECMD_COMP_ZLIB_COMPRESSION) {
#ifndef __HOSTBOOT_MODULE
    // All three of these are zlib compression, so they get the same version
    compressedBuffer.setByte(byteOffset++, 0xF3);
#else
    ETRAC0("**** ERROR : zlib support removed!");
    RETURN_ERROR(ECMD_DBUF_INVALID_ARGS); 
#endif
  } else {
    ETRAC0("**** ERROR : Unknown compression mode passed in!");
    RETURN_ERROR(ECMD_DBUF_INVALID_ARGS); 
  }

  /* Set the length, which is 4 bytes long */
  compressedBuffer.setByte(byteOffset++, ((0xFF000000 & length) >> 24));
  compressedBuffer.setByte(byteOffset++, ((0x00FF0000 & length) >> 16));
  compressedBuffer.setByte(byteOffset++, ((0x0000FF00 & length) >> 8));
  compressedBuffer.setByte(byteOffset++, (0x000000FF & length));

  /* Our common variables used in all modes */
  size_t uncompressedSize = this->getByteLength();
  size_t compressedSize = 0;
  uint8_t* uncompressedData = new uint8_t[uncompressedSize];
  uint8_t* compressedData = NULL;
  /* The data has to be copied into a uint8_t buffer.  If you try to pass in (uint8_t*)this->iv_Data
   instead of uncompressedData, you have big endian vs little endian issues */
  this->extract(uncompressedData, 0, this->getBitLength());

  if (compressedBuffer.getByte(2) == 0xF2) {
    /* Now setup our inputs and call the compress */
    compressedSize = PrdfCompressBuffer::compressedBufferMax(uncompressedSize);
    compressedData = new uint8_t[compressedSize];

    PrdfCompressBuffer::compressBuffer(uncompressedData, uncompressedSize, compressedData, compressedSize);
  } else if (compressedBuffer.getByte(2) == 0xF3) {
#ifndef __HOSTBOOT_MODULE
    /* Now setup our inputs and call the compress */
    compressedSize = compressBound(uncompressedSize);
    compressedData = new uint8_t[compressedSize];
    /* Select the proper compression level */
    int level;
    if (i_mode == ECMD_COMP_ZLIB) {
      level = Z_DEFAULT_COMPRESSION;
    } else if (i_mode == ECMD_COMP_ZLIB_SPEED) {
      level = Z_BEST_SPEED;
    } else if (i_mode == ECMD_COMP_ZLIB_COMPRESSION) {
      level = Z_BEST_COMPRESSION;
    } else {
      ETRAC0("**** ERROR : Unknown compression mode passed in!");
      delete[] uncompressedData;
      delete[] compressedData;
      RETURN_ERROR(ECMD_DBUF_INVALID_ARGS); 
    }

    /* Create a local compressedSize variable to get around a PFD compile error with -Os*/
    /* They didn't like it when we did (uLongf*)&compressedSize */
    uLongf l_compressedSize = compressedSize;
    /* Do the work */
    uint32_t rc = compress2(compressedData, &l_compressedSize, uncompressedData, uncompressedSize, level);
    if (rc) {
      ETRAC0("**** ERROR : Error occurred on the zlib compress2 call!");
      RETURN_ERROR(rc); 
    }

    /* Assign the value back so we can use it below */
    compressedSize = l_compressedSize;
#endif
  }

  /* Now grow the buffer to the size of the compressed data */
  compressedBuffer.growBitLength((compressedBuffer.getBitLength() + (compressedSize * 8)));

  /* Insert the data and cleanup after ourselves */
  compressedBuffer.insert(compressedData, (byteOffset * 8), (compressedSize * 8));
  delete[] uncompressedData;
  delete[] compressedData;

  /* Finally, copy the compressBuffer into our current buffer */
  *this = compressedBuffer;

  return rc;
}

uint32_t ecmdDataBufferBase::uncompressBuffer() {
  uint32_t rc = ECMD_DBUF_SUCCESS;
  uint32_t length = 0;
  ecmdDataBufferBase uncompressedBuffer;
  uint32_t byteOffset = 0;
  ecmdCompressionMode_t mode;

  /* See if the compression header is there */
  uint32_t header = this->getWord(0);
  if ((header & 0xFFFFF000) != 0xC2A3F000) {
    ETRAC1("**** ERROR : Compression header doesn't match.  Found: 0x%X.", header);
    RETURN_ERROR(ECMD_DBUF_INVALID_ARGS); 
  }
  /* Make sure it's a supported version of compression */
  if ((header & 0x00000F00) == 0x00000200) {
    mode = ECMD_COMP_PRD;
  } else if ((header & 0x00000F00) == 0x00000300) {
#ifndef __HOSTBOOT_MODULE
    mode = ECMD_COMP_ZLIB;
#else
    ETRAC0("**** ERROR : zlib support removed!");
    RETURN_ERROR(ECMD_DBUF_INVALID_ARGS); 
#endif
  } else {
    ETRAC1("**** ERROR : Unknown version. Found: 0x%X.", header);
    RETURN_ERROR(ECMD_DBUF_INVALID_ARGS); 
  }
  byteOffset+=3;

  /* Get the length, use it to set the uncompress buffer length */
  // split the following line up to avoid warnings:
  // length = (this->getByte(byteOffset++) << 24) | (this->getByte(byteOffset++) << 16) | (this->getByte(byteOffset++) << 8) | this->getByte(byteOffset++);
  length  = this->getByte(byteOffset++) << 24;
  length |= this->getByte(byteOffset++) << 16;
  length |= this->getByte(byteOffset++) << 8;
  length |= this->getByte(byteOffset++);

  uncompressedBuffer.setBitLength(length);

  /* Setup our inputs and call the uncompress */
  size_t uncompressedSize = uncompressedBuffer.getByteLength();
  size_t compressedSize = this->getByteLength() - byteOffset;
  uint8_t* uncompressedData = new uint8_t[uncompressedSize];
  uint8_t* compressedData = new uint8_t[compressedSize];
  /* The data has to be copied into a uint8_t buffer.  If you try to pass in (uint8_t*)this->iv_Data
   instead of compressedData, you have big endian vs little endian issues */
  this->extract(compressedData, (byteOffset * 8), (compressedSize * 8));

  if (mode == ECMD_COMP_PRD) {
    PrdfCompressBuffer::uncompressBuffer(compressedData, compressedSize, uncompressedData, uncompressedSize);
  } else if (mode == ECMD_COMP_ZLIB) {
#ifndef __HOSTBOOT_MODULE
    /* Create a local compressedSize variable to get around a PFD compile error with -Os*/
    /* They didn't like it when we did (uLongf*)&uncompressedSize */
    uLongf l_uncompressedSize = uncompressedSize;
    /* Do the work */
    uint32_t rc = uncompress(uncompressedData, &l_uncompressedSize, compressedData, compressedSize);
    if (rc) {
      ETRAC0("**** ERROR : Error occurred on the zlib uncompress call!");
      RETURN_ERROR(rc); 
    }
    /* Assign the value back so we can use it below */
    uncompressedSize = l_uncompressedSize;
#endif
  }

  /* Error check the length */
  if (uncompressedBuffer.getByteLength() != uncompressedSize) {
    ETRAC2("**** ERROR : Expected byte length of %d, got back %d", uncompressedBuffer.getByteLength(), uncompressedSize);
    RETURN_ERROR(ECMD_DBUF_MISMATCH); 
  }

  /* Insert the data and cleanup after ourselves */
  uncompressedBuffer.insert(uncompressedData, 0, length);
  delete[] uncompressedData;
  delete[] compressedData;

  /* Finally, copy the uncompressBuffer into our current buffer */
  *this = uncompressedBuffer;

  return rc;
}

bool ecmdDataBufferBase::isBufferCompressed() {
  bool compressed = false;

  /* The first 5 nibbles are a fixed pattern when compressed.  If the user happens to have this pattern in
   uncompressed data, we could have a problem */
  if ((getWord(0) & 0xFFFFF000) == 0xC2A3F000) {
    compressed = true;
  }

  return compressed;
} 

void * ecmdBigEndianMemCopy(void * dest, const void *src, size_t count) {
#if defined (i386)
  char *tmp = (char *) dest, *s = (char *) src;
  int remainder = 0;
  uint32_t whole_num = 0;

  remainder = count % 4;
  whole_num = count - remainder;

  /* note: whole_num + remainder = count */

  if (whole_num == count) {
    while (count--) *tmp++ = *s++;
    return dest;
  }
  if (whole_num) {
    while (whole_num--) *tmp++ = *s++;
  }
  if (remainder == 3) {
    tmp[1] = s[1];
    tmp[2] = s[2];
    tmp[3] = s[3];
  }
  else if (remainder == 2) {
    tmp[2] = s[2];
    tmp[3] = s[3];
  }//'constant condition' has been added to avoid BEAM errors
  else if (remainder == 1) { /*constant condition*/
    tmp[3] = s[3];
  }

  return dest;
#else
  return memcpy(dest,src,count);
#endif

}

uint32_t* ecmdDataBufferBaseImplementationHelper::getDataPtr( void* i_buffer ) {
  if (i_buffer == NULL) return NULL;
  ecmdDataBufferBase* buff = (ecmdDataBufferBase*)i_buffer;
  return buff->iv_Data;
};


/********************************************************************************
       These routines belong to derived class ecmdOptimizableDataBufferBase
 ********************************************************************************/

ecmdOptimizableDataBufferBase::ecmdOptimizableDataBufferBase()
{
   iv_BufferOptimizable = true;     
}

ecmdOptimizableDataBufferBase::ecmdOptimizableDataBufferBase(uint32_t i_numBits)
 : ecmdDataBufferBase(i_numBits) {
       iv_BufferOptimizable = true;     
}

