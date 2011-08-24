//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/ecmddatabuffer/ecmdDataBuffer.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 * @file ecmdDataBuffer.C
 * @brief Provides a means to handle data from the eCMD C API
 *
 ********************************************************************
 * @todo - This is only a temporary file created to compile code.
 * We will use John Farrugia's version
 *********************************************************************
 */

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <stdint.h>
#include <string.h>
#include <trace/interface.H>
#include <ecmdDataBuffer.H>

#define EDB_ADMIN_TOTAL_SIZE 2
#define EDB_ADMIN_HEADER_SIZE 1
#define EDB_ADMIN_FOOTER_SIZE 1
#define EDB_ADMIN_TOTAL_SIZE 2
#define EDB_RETURN_CODE 0
#define EDB_RANDNUM 0x12345678
#define ECMD_DBUF_BUFFER_OVERFLOW           (ECMD_ERR_ECMD | 0x2011)

// Trace definition
trace_desc_t* g_trac_ecmd = NULL;
TRAC_INIT(&g_trac_ecmd, "ECMD", 4096);

//---------------------------------------------------------------------
//  Constructors
//---------------------------------------------------------------------
ecmdDataBufferBase::ecmdDataBufferBase()  // Default constructor
: iv_Capacity(0), iv_NumBits(0), iv_Data(NULL), iv_RealData(NULL)
{
    iv_UserOwned = true;
}

ecmdDataBufferBase::ecmdDataBufferBase(uint32_t i_numBits)
: iv_Capacity(0), iv_NumBits(0), iv_Data(NULL), iv_RealData(NULL)
{
    iv_UserOwned = true;
    if (i_numBits > 0)
    {
      setBitLength(i_numBits);
    }
}

//---------------------------------------------------------------------
//  Destructor
//---------------------------------------------------------------------
ecmdDataBufferBase::~ecmdDataBufferBase()
{
    // Only call clear() if buffer is owned by this user (ie, not shared)
    if (iv_UserOwned)
    {
        clear();
    }
}

uint32_t ecmdDataBufferBase::getWordLength() const
{
    return (iv_NumBits + 31) / 32;
}

uint32_t ecmdDataBufferBase::flushTo0()
{
  uint32_t rc = ECMD_DBUF_SUCCESS;
  if (getWordLength() > 0)
  {
    memset(iv_Data, 0x00, getWordLength() * 4); /* init to 0 */
  }
  return rc;
}


uint32_t ecmdDataBufferBase::clear() {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if (iv_RealData != NULL)
  {
    /* That looked okay, reset everything else */
    /* Only do the delete if we alloc'd something */
    if (iv_RealData != iv_LocalData)
    {
        delete[] iv_RealData;
    }
    iv_RealData = NULL;
    iv_Capacity = 0;
    iv_NumBits = 0;
  }
  return rc;
}

uint32_t ecmdDataBufferBase::setCapacity(uint32_t i_newCapacity) {
  uint32_t rc = ECMD_DBUF_SUCCESS;

  if(!iv_UserOwned) {
    TRACFCOMP(g_trac_ecmd, "**** ERROR (ecmdDataBuffer) : Attempt to modify non user owned buffer size.");
    return 0;
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
        TRACFCOMP(g_trac_ecmd, "**** ERROR : ecmdDataBuffer::setCapacity : Unable to allocate memory for new databuffer");
        return 0;
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

uint32_t ecmdDataBufferBase::setDoubleWord(uint32_t i_doublewordoffset, uint64_t i_value)
{
    uint32_t rc = ECMD_DBUF_SUCCESS;
    if (i_doublewordoffset >= ((getWordLength()+1)/2))
    {
        TRACFCOMP(g_trac_ecmd, "**** ERROR : ecmdDataBuffer::setDoubleWord: doubleWordOffset %d >= NumDoubleWords (%d)",
               i_doublewordoffset, ((getWordLength()+1)/2));
        return (ECMD_DBUF_BUFFER_OVERFLOW);
    }

     // Create mask if part of this byte is not in the valid part of the ecmdDataBuffer
    if (((i_doublewordoffset + 1) == ((getWordLength()+1)/2)) && (iv_NumBits % 64))
    {
        uint64_t bitMask = 0xFFFFFFFFFFFFFFFFul;
        /* Shift it left by the amount of unused bits */
        bitMask <<= ((64 * ((getWordLength()+1)/2)) - iv_NumBits);
        /* Clear the unused bits */
        i_value &= bitMask;
    }
    uint32_t hivalue = (uint32_t)((i_value & 0xFFFFFFFF00000000ul) >> 32);
    uint32_t lovalue = (uint32_t)((i_value & 0x00000000FFFFFFFFul));

    iv_Data[i_doublewordoffset*2] = hivalue;
    /* Don't set the second word if we are on oddwords */
    if (!((i_doublewordoffset*2)+1 >= getWordLength()) ) {
        iv_Data[(i_doublewordoffset*2)+1] = lovalue;
    }
    return rc;
}

uint64_t ecmdDataBufferBase::getDoubleWord(uint32_t i_doublewordoffset) const
{
    // Round up to the next word and check length
    if (i_doublewordoffset >= ((getWordLength()+1)/2))
    {
        TRACFCOMP(g_trac_ecmd, "**** ERROR : ecmdDataBuffer::getDoubleWord: doubleWordOffset %d >= NumDoubleWords (%d)",
                i_doublewordoffset, ((getWordLength()+1)/2));
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

