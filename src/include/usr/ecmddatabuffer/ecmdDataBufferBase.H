/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ecmddatabuffer/ecmdDataBufferBase.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
#ifndef ecmdDataBufferBase_H
#define ecmdDataBufferBase_H
/* $Header: /gsa/rchgsa/projects/e/ecmd/.cvsroot/capi/ecmdDataBufferBase.H,v 1.2 2012/09/14 18:52:12 farrugia Exp $ */
// Copyright **********************************************************
//
// File ecmdDataBufferBase.H
//
// 
// OCO Source Materials
// 9400 Licensed Internal Code
// (C) COPYRIGHT IBM CORP. 2003
//
// The source code for this program is not published or otherwise
// divested of its trade secrets, irrespective of what has been
// deposited with the U.S. Copyright Office.
//
// End Copyright ******************************************************

/**
 * @file ecmdDataBufferBase.H
 * @brief Provides a means to handle data from the eCMD C API
 *
 * DataBuffers handle and store data in a Big Endian fashion with Bit 0 being the MSB
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#include <vector>
#include <stdint.h>
//#include <ecmdDefines.H>

#ifdef ENABLE_MPATROL
 #include <mpatrol.h>
#endif

#ifdef FIPSODE
#include <fips_trace.H>
#elif defined ZSERIES_SWITCH
#include <yemtraceinterface.h>
#elif defined __HOSTBOOT_MODULE
#include <fapiPlatTrace.H>
#endif

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------
#ifdef FIPSODE
extern tracDesc_t g_etrc; /** Trace Descriptor **/
#elif defined ZSERIES_SWITCH
#define g_etrc TRACE_ID
#endif

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
/* Define these if for some reason we are building without ecmdReturnCodes.H */
#ifndef ECMD_DBUF_SUCCESS
 #define ECMD_ERR_ECMD                           0x01000000 ///< Error came from eCMD

 #define ECMD_DBUF_SUCCESS                       0x0    ///< DataBuffer returned successfully
 #define ECMD_DBUF_INIT_FAIL                     (ECMD_ERR_ECMD | 0x2001) ///< Initialization of the DataBuffer failed
 #define ECMD_DBUF_BUFFER_OVERFLOW               (ECMD_ERR_ECMD | 0x2011) ///< Attempt to read/write data beyond the length of the DataBuffer
 #define ECMD_DBUF_XSTATE_ERROR                  (ECMD_ERR_ECMD | 0x2021) ///< An 'X' character occured where it was not expected
 #define ECMD_DBUF_UNDEFINED_FUNCTION            (ECMD_ERR_ECMD | 0x2031) ///< Function not included in this version of DataBuffer
 #define ECMD_DBUF_INVALID_ARGS                  (ECMD_ERR_ECMD | 0x2041) ///< Args provided to dataBuffer were invalid
 #define ECMD_DBUF_INVALID_DATA_FORMAT           (ECMD_ERR_ECMD | 0x2043) ///< String data didn't match expected input format
 #define ECMD_DBUF_FOPEN_FAIL                    (ECMD_ERR_ECMD | 0x2051) ///< File open on file for reading or writing the data buffer failed
 #define ECMD_DBUF_FILE_FORMAT_MISMATCH          (ECMD_ERR_ECMD | 0x2053) ///< In readFile specified format not found in the data file
 #define ECMD_DBUF_DATANUMBER_NOT_FOUND          (ECMD_ERR_ECMD | 0x2055) ///< In readFileMultiple specified data number  not found in file
 #define ECMD_DBUF_FILE_OPERATION_FAIL           (ECMD_ERR_ECMD | 0x2057) ///< File operation failed
 #define ECMD_DBUF_NOT_OWNER                     (ECMD_ERR_ECMD | 0x2061) ///< Don't own this buffer so can't do this operation
 #define ECMD_DBUF_XSTATE_NOT_ENABLED            (ECMD_ERR_ECMD | 0x2063) ///< Xstate function called on a buffer that doesn't have xstates enabled
 #define ECMD_DBUF_MISMATCH                      (ECMD_ERR_ECMD | 0x2065) ///< There was a mismatch between a comparision operation in the buffer
 #define ECMD_DBUF_NULL_POINTER                  (ECMD_ERR_ECMD | 0x2067) ///< Null pointer passed
#endif

//--------------------------------------------------------------------
// Macros
//--------------------------------------------------------------------
#ifdef FIPSODE
#define ETRAC0(fmt) \
  TRACFCOMP0(g_etrc, fmt);
#define ETRAC1(fmt, arg1) \
  TRACFCOMP1(g_etrc, fmt, arg1)
#define ETRAC2(fmt, arg1, arg2) \
  TRACFCOMP2(g_etrc, fmt, arg1, arg2)
#define ETRAC3(fmt, arg1, arg2, arg3) \
  TRACFCOMP3(g_etrc, fmt, arg1, arg2, arg3)
#define ETRAC4(fmt, arg1, arg2, arg3, arg4) \
  TRACFCOMP4(g_etrc, fmt, arg1, arg2, arg3, arg4)
#define ETRAC5(fmt, arg1, arg2, arg3, arg4, arg5) \
  TRACFCOMP5(g_etrc, fmt, arg1, arg2, arg3, arg4, arg5)
#define ETRAC6(fmt, arg1, arg2, arg3, arg4, arg5, arg6) \
  TRACFCOMP6(g_etrc, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define ETRAC7(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
  TRACFCOMP7(g_etrc, fmt, arg1, arg2, arg3, arg4, arg5, arg6, \
  arg7)
#define ETRAC8(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
  TRACFCOMP8(g_etrc, fmt, arg1, arg2, arg3, arg4, arg5, arg6, \
  arg7, arg8)
#define ETRAC9(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
  TRACFCOMP9(g_etrc, fmt, arg1, arg2, arg3, arg4, arg5, arg6, \
  arg7, arg8, arg9)
#elif defined ZSERIES_SWITCH
#define ETRAC0(fmt) \
  FTRACE(SYS_TB, fmt)
#define ETRAC1(fmt, arg1) \
  FTRACE1(SYS_TB, fmt, arg1)
#define ETRAC2(fmt, arg1, arg2) \
  FTRACE2(SYS_TB, fmt, arg1, arg2)
#define ETRAC3(fmt, arg1, arg2, arg3) \
  FTRACE3(SYS_TB, fmt, arg1, arg2, arg3)
#define ETRAC4(fmt, arg1, arg2, arg3, arg4) \
  FTRACE4(SYS_TB, fmt, arg1, arg2, arg3, arg4)
#define ETRAC5(fmt, arg1, arg2, arg3, arg4, arg5) \
  FTRACE5(SYS_TB, fmt, arg1, arg2, arg3, arg4, arg5)
#define ETRAC6(fmt, arg1, arg2, arg3, arg4, arg5, arg6) \
  FTRACE6(SYS_TB, fmt, arg1, arg2, arg3, arg4, arg5, arg6)
#define ETRAC7(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
  FTRACE7(SYS_TB, fmt, arg1, arg2, arg3, arg4, arg5, arg6, \
  arg7)
#define ETRAC8(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) \
  FTRACE8(SYS_TB, fmt, arg1, arg2, arg3, arg4, arg5, arg6, \
  arg7, arg8)
#define ETRAC9(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) \
  FTRACE9(SYS_TB, fmt, arg1, arg2, arg3, arg4, arg5, arg6, \
  arg7, arg8, arg9)
#elif defined __HOSTBOOT_MODULE
#define ETRAC0(fmt) FAPI_ERR(fmt);
#define ETRAC1(fmt, arg1) FAPI_ERR(fmt, arg1);
#define ETRAC2(fmt, arg1, arg2) FAPI_ERR(fmt, arg1, arg2);
#define ETRAC3(fmt, arg1, arg2, arg3) FAPI_ERR(fmt, arg1, arg2, arg3);
#define ETRAC4(fmt, arg1, arg2, arg3, arg4) FAPI_ERR(fmt, arg1, arg2, arg4);
#define ETRAC5(fmt, arg1, arg2, arg3, arg4, arg5) FAPI_ERR(fmt, arg1, arg2, arg5);
#define ETRAC6(fmt, arg1, arg2, arg3, arg4, arg5, arg6) FAPI_ERR(fmt, arg1, arg2, arg6);
#define ETRAC7(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7) FAPI_ERR(fmt, arg1, arg2, arg7);
#define ETRAC8(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) FAPI_ERR(fmt, arg1, arg2, arg8);
#define ETRAC9(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) FAPI_ERR(fmt, arg1, arg2, arg9);
#else
#define ETRAC0(fmt) printf( "%s> ETRC: " fmt "\n", __FUNCTION__);
#define ETRAC1(fmt, arg1) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1);
#define ETRAC2(fmt, arg1, arg2) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1, arg2);
#define ETRAC3(fmt, arg1, arg2, arg3) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1, arg2, arg3);
#define ETRAC4(fmt, arg1, arg2, arg3, arg4) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1, arg2, arg3, arg4);
#define ETRAC5(fmt, arg1, arg2, arg3, arg4, arg5) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1, arg2, arg3, arg4, arg5);
#define ETRAC6(fmt, arg1, arg2, arg3, arg4, arg5, arg6) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1, arg2, arg3, arg4, arg5, arg6);
#define ETRAC7(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
#define ETRAC8(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
#define ETRAC9(fmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9) printf( "%s> ETRC: " fmt "\n", __FUNCTION__, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
#endif

#ifdef FIPSODE
#define  ECMD_NULL_PTR_CHECK(ptr) \
  if ( ptr == NULL ) { \
    ETRAC2("**** ERROR : %s : Argument %s is NULL", __PRETTY_FUNCTION__, #ptr); \
    return ECMD_DBUF_NULL_POINTER; \
  };
#else
#define  ECMD_NULL_PTR_CHECK(ptr) \
  if ( ptr == NULL ) { \
    ETRAC1("**** ERROR : Argument %s is NULL",#ptr); \
    return ECMD_DBUF_NULL_POINTER; \
  };
#endif

//----------------------------------------------------------------------
//  Global Variables
//----------------------------------------------------------------------

//--------------------------------------------------------------------
//  Defines
//--------------------------------------------------------------------
/**
 @brief This is the different write modes for writing databuffer into a file
*/
typedef enum {
  ECMD_COMP_UNKNOWN,            ///< Default value
  ECMD_COMP_PRD,                ///< Use the PRD compression algorithm, owned by IBM.  The Default mode.
  ECMD_COMP_ZLIB,               ///< Use the default zlib compression algorithm.
  ECMD_COMP_ZLIB_SPEED,         ///< Use the best speed zlib compression algorithm.
  ECMD_COMP_ZLIB_COMPRESSION,   ///< Use the best compression zlib compression algorithm.
} ecmdCompressionMode_t;

//----------------------------------------------------------------------
//  User Types
//----------------------------------------------------------------------
/**
 @brief This is used to help low-level implementation of the ecmdDataBufferBase, this CAN NOT be used by any eCMD client or data corruption will occur
*/
class ecmdDataBufferBaseImplementationHelper {
public:
  static uint32_t* getDataPtr( void* i_buffer );
};

class ecmdDataBuffer;


/**
 @brief Provides a means to handle data from the eCMD C API
*/

class ecmdDataBufferBase {
  friend class ecmdDataBufferBaseImplementationHelper;
  friend class ecmdDataBuffer;

public:

  /** @name ecmdDataBufferBase Constructors */
  //@{
  /**
   * @brief Default Constructor
   * @post buffer is not allocated, can be allocated later with setWordLength, setCapacity or setBitLength
   */
  ecmdDataBufferBase();

  /**
   * @brief Constructor
   * @param i_numBits Size of data in bits to initialize
   * @post ecmdDataBufferBase is initialized and zero'd out
   */
  //STGC01056640 - remove implicit conversion ability. data = 08FF doesn't work
  explicit ecmdDataBufferBase(uint32_t i_numBits);

  /**
   * @brief Copy Constructor
   * @param i_other Buffer to copy
   */
  ecmdDataBufferBase(const ecmdDataBufferBase &i_other);

  /**
   * @brief Default Destructor
   */
  virtual ~ecmdDataBufferBase();
  //@}


  // Member Functions
  /** @name Buffer Size Functions */
  //@{
  /**
   * @brief Called by the destructor, available to user to reset buffer to default constructor state
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   * @retval nonzero on failure
   * @post Memory deallocated and size set to 0
   */
  virtual uint32_t clear();

  /**
   * @brief Return the length of the buffer in double words
   * @retval Buffer length in double words rounded up
   */
  uint32_t   getDoubleWordLength() const;

  /**
   * @brief Return the length of the buffer in words
   * @retval Buffer length in words rounded up
   */
  uint32_t   getWordLength() const;

  /**
   * @brief Return the length of the buffer in half words
   * @retval Buffer length in half words rounded up
   */
  uint32_t   getHalfWordLength() const;

  /**
   * @brief Return the length of the buffer in bytes
   * @retval Buffer length in bytes rounded up
   */
  uint32_t   getByteLength() const;

  /**
   * @brief Return the length of the buffer in bits
   * @retval Buffer length in bits
   */
  uint32_t   getBitLength() const;

  /**
   * @brief Return the actual capacity of the internal buffer in words
   * @retval Actual capacity in words of internal buffer
   */
  uint32_t   getCapacity() const;

  /**
   * @brief Reinitialize the Buffer to specified length
   * @param i_newNumDoubleWords Length of new buffer in words
   * @post Buffer is reinitialized and zero'd out
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL failure occurred setting new length
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   *
   * NOTE : Capacity will be adjusted to fit new size if neccesary
   * CAUTION : All data stored in buffer will be lost
   */
  uint32_t  setDoubleWordLength(uint32_t i_newNumDoubleWords);

  /**
   * @brief Reinitialize the Buffer to specified length
   * @param i_newNumWords Length of new buffer in words
   * @post Buffer is reinitialized and zero'd out
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL failure occurred setting new length
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   *
   * NOTE : Capacity will be adjusted to fit new size if neccesary
   * CAUTION : All data stored in buffer will be lost
   */
  uint32_t  setWordLength(uint32_t i_newNumWords);

  /**
   * @brief Reinitialize the Buffer to specified length
   * @param i_newNumHalfWords Length of new buffer in words
   * @post Buffer is reinitialized and zero'd out
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL failure occurred setting new length
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   *
   * NOTE : Capacity will be adjusted to fit new size if neccesary
   * CAUTION : All data stored in buffer will be lost
   */
  uint32_t  setHalfWordLength(uint32_t i_newNumHalfWords);

  /**
   * @brief Reinitialize the Buffer to specified length
   * @param i_newNumBytes Length of new buffer in bytes
   * @post Buffer is reinitialized and zero'd out
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL failure occurred setting new length
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   *
   * NOTE : Capacity will be adjusted to fit new size if neccesary
   * CAUTION : All data stored in buffer will be lost
   */
  uint32_t  setByteLength(uint32_t i_newNumBytes);

  /**
   * @brief Reinitialize the Buffer to specified length
   * @param i_newNumBits Length of new buffer in bits
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL failure occurred setting new length
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   * @post Buffer is reinitialized and zero'd out
   *
   * NOTE : Capacity will be adjusted to fit new size if neccesary
   * CAUTION : All data stored in buffer will be lost
   */
  uint32_t  setBitLength(uint32_t i_newNumBits);

  /**
   * @brief Reinitialize the internal buffer to specified length
   * @param i_newNumWords length of internal data buffer in words
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL failure occurred setting new length
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   * @post Internal buffer is reinitialized and zero'd out.  Requests to decrease the capacity are ignored
   *
   * CAUTION : All data stored in buffer will be lost
   */
  virtual uint32_t setCapacity (uint32_t i_newNumWords);

  /**
   * @brief Shrink buffer size to a new bit size
   * @param i_newNumBits New bit length for buffer (must be <= current buffer length)
   * @retval ECMD_DBUF_SUCCESS on success
   * @post Internal buffer size is reset but data inside new size is not lost
   */
  uint32_t shrinkBitLength(uint32_t i_newNumBits);

  /**
   * @brief Expand buffer size to a new bit size maintaining current data
   * @param i_newNumBits New bit length for buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @post Internal buffer size is reset but data inside is not lost
   *
   * NOTE : Capacity will be adjusted to fit new size if neccesary
   */
  uint32_t growBitLength(uint32_t i_newNumBits);

  /**
   * @brief Returns value of iv_BufferOptimizable
   */
  virtual inline bool isBufferOptimizable(void) { return iv_BufferOptimizable; }

  //@}

  /** @name Bit/Word Manipulation Functions */
  //@{
  /**
   * @brief Get the value of a bit in the buffer
   * @param i_bit Bit in buffer to get
   * @retval true/1 if bit is on, false/0 if bit is off
   */
  bool getBit(uint32_t i_bit) const;

  /**
   * @brief Turn on a bit in buffer
   * @param i_bit Bit in buffer to turn on
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_bit is not contained in the size of this buffer
   */
  uint32_t setBit(uint32_t i_bit);

  /**
   * @brief Turn on a bit in buffer
   * @param i_bit start bit in buffer to turn on
   * @param i_len Number of consecutive bits from start bit to turn on
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_bit is not contained in the size of this buffer
   */
  uint32_t setBit(uint32_t i_bit, uint32_t i_len);

  /**
   * @brief Write a bit to specified value in buffer
   * @param i_bit Bit in buffer to turn on
   * @param i_value Value to write
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_bit is not contained in the size of this buffer
   */
  uint32_t writeBit(uint32_t i_bit, uint32_t i_value);

  /**
   * @brief Set a word of data in buffer
   * @param i_wordoffset Offset of word to set
   * @param i_value 32 bits of data to put into word
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_wordoffset is not contained in the size of this buffer
   *
   * NOTE : If the buffer length != word boundary, when setting the last word
   *        data in i_value past the buffer length is cleared before being stored in the buffer
   */
  virtual uint32_t setWord(uint32_t i_wordoffset, uint32_t i_value);

  /**
   * @brief Fetch a word from ecmdDataBufferBase
   * @param i_wordoffset Offset of word to fetch
   * @retval Value of word requested
   */
  uint32_t getWord(uint32_t i_wordoffset) const;

  /**
   * @brief Set a byte of data in buffer
   * @param i_byteoffset Offset of byte to set
   * @param i_value 8 bits of data to put into byte
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_byteoffset is not contained in the size of this buffer
   *
   * NOTE : If the buffer length != byte boundary, when setting the last byte
   *        data in i_value past the buffer length is cleared before being stored in the buffer
   */
  virtual uint32_t setByte(uint32_t i_byteoffset, uint8_t i_value);

  /**
   * @brief Fetch a byte from ecmdDataBufferBase
   * @param i_byteoffset Offset of byte to fetch
   * @retval Value of byte requested
   *
   * NOTE : If offset > buffer length retval = 0 and error printed
   */
  uint8_t getByte(uint32_t i_byteoffset) const;

  /**
   * @brief Set a halfword of data in buffer
   * @param i_halfwordoffset Offset of halfword to set
   * @param i_value 16 bits of data to put into halfword
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_halfwordoffset is not contained in the size of this buffer
   *
   * NOTE : If the buffer length != half word boundary, when setting the last half word
   *        data in i_value past the buffer length is cleared before being stored in the buffer
   */
  virtual uint32_t setHalfWord(uint32_t i_halfwordoffset, uint16_t i_value);

  /**
   * @brief Fetch a halfword from ecmdDataBufferBase
   * @param i_halfwordoffset Offset of halfword to fetch
   * @retval Value of halfword requested
   */
  uint16_t getHalfWord(uint32_t i_halfwordoffset) const;

  /**
   * @brief Set a doubleword of data in buffer
   * @param i_doublewordoffset Offset of doubleword to set
   * @param i_value 64 bits of data to put into doubleword
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_doublewordoffset is not contained in the size of this buffer
   *
   * NOTE : If the buffer length != double word boundary, when setting the last double word
   *        data in i_value past the buffer length is cleared before being stored in the buffer
   */
  virtual uint32_t setDoubleWord(uint32_t i_doublewordoffset, uint64_t i_value);

  /**
   * @brief Fetch a doubleword from ecmdDataBufferBase
   * @param i_doublewordoffset Offset of doubleword to fetch
   * @retval Value of doubleword requested
   */
  uint64_t getDoubleWord(uint32_t i_doublewordoffset) const;

  /**
   * @brief Clear a bit in buffer
   * @param i_bit Bit in buffer to turn off
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_bit is not contained in the size of this buffer
   */
  virtual uint32_t clearBit(uint32_t i_bit);
  /**
   * @brief Clear multiple bits in buffer
   * @param i_bit Start bit in buffer to turn off
   * @param i_len Number of consecutive bits from start bit to off
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_bit is not contained in the size of this buffer
   */
  uint32_t clearBit(uint32_t i_bit, uint32_t i_len);

  /**
   * @brief Invert bit
   * @param i_bit Bit in buffer to invert
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_bit is not contained in the size of this buffer
   */
  virtual uint32_t flipBit(uint32_t i_bit);
  /**
   * @brief Invert multiple bits
   * @param i_bit Start bit in buffer to invert
   * @param i_len Number of consecutive bits to invert
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW i_bit is not contained in the size of this buffer
   */
  uint32_t flipBit(uint32_t i_bit, uint32_t i_len);

  /**
   * @brief Test if bit is set
   * @param i_bit Bit to test
   * @retval true if bit is set - false if bit is clear
   */
  bool   isBitSet(uint32_t i_bit) const;
  /**
   * @brief Test if multiple bits are set
   * @param i_bit Start bit to test
   * @param i_len Number of consecutive bits to test
   * @retval true if all bits in range are set - false if any bit is clear
   */
  bool   isBitSet(uint32_t i_bit, uint32_t i_len) const;
  /**
   * @brief Test if bit is clear
   * @param i_bit Bit to test
   * @retval true if bit is clear - false if bit is set
   */
  bool   isBitClear(uint32_t i_bit) const;
  /**
   * @brief Test if multiple bits are clear
   * @param i_bit Start bit to test
   * @param i_len Number of consecutive bits to test
   * @retval true if all bits in range are clear - false if any bit is set
   */
  bool   isBitClear(uint32_t i_bit, uint32_t i_len) const;
  /**
   * @brief Count number of bits set in a range
   * @param i_bit Start bit to test
   * @param i_len Number of consecutive bits to test
   * @retval Number of bits set in range
   */
  uint32_t getNumBitsSet(uint32_t i_bit, uint32_t i_len) const;
  //@}


  /** @name Buffer Manipulation Functions */
  //@{
  /**
   * @brief Shift data to right
   * @param i_shiftnum Number of bits to shift
   * @param i_offset Offset into the buffer to start the shift from.  Default is bit 0.
   * @post Bits in buffer are shifted to right by specified number of bits - data is shifted off the end
   * @post Buffer size is unchanged
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t shiftRight(uint32_t i_shiftnum, uint32_t i_offset = 0);
  /**
   * @brief Shift data to left
   * @param i_shiftnum Number of bits to shift
   * @param i_offset Offset into the buffer to start the shift from.  Default is to start at end of buffer.
   * @post Bits in buffer are shifted to left by specified number of bits - data is shifted off the beginning
   * @post Buffer size is unchanged
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t shiftLeft(uint32_t i_shiftnum, uint32_t i_offset = 0xFFFFFFFF);
  /**
   * @brief Shift data to right - resizing buffer
   * @param i_shiftnum Number of bits to shift
   * @param i_offset Offset into the buffer to start the shift from.  Default is bit 0.
   * @post Bits in buffer are shifted to right by specified number of bits
   * @post Buffer size is resized to accomodate shift
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   */
  uint32_t shiftRightAndResize(uint32_t i_shiftnum, uint32_t i_offset = 0);

  /**
   * @brief Shift data to left - resizing buffer
   * @param i_shiftnum Number of bits to shift
   * @post Bits in buffer are shifted to left by specified number of bits - data is shifted off the beginning
   * @post Buffer size is resized to accomodate shift
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   */
  uint32_t shiftLeftAndResize(uint32_t i_shiftnum);

  /**
   * @brief Rotate data to right
   * @param i_rotatenum Number of bits to rotate
   * @post Bits in buffer are rotated to the right by specified number of bits - data is rotated to the beginning
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t rotateRight(uint32_t i_rotatenum);

  /**
   * @brief Rotate data to left
   * @param i_rotatenum Number of bits to rotate
   * @post Bits in buffer are rotated to the left by specified number of bits - data is rotated to the end
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t rotateLeft(uint32_t i_rotatenum);

  /**
   * @brief Clear entire buffer to 0's
   * @retval ECMD_DBUF_SUCCESS on success
   */
  virtual uint32_t flushTo0();

  /**
   * @brief Set entire buffer to 1's
   * @retval ECMD_DBUF_SUCCESS on success
   */
  virtual uint32_t flushTo1();

  /**
   * @brief Invert entire buffer
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t invert();

  /**
   * @brief Bit reverse entire buffer
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t reverse();

  /**
   * @brief Apply an inversion mask to data inside buffer
   * @param i_invMask Buffer that stores inversion mask
   * @param i_invByteLen Buffer length provided in bytes
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t applyInversionMask(const uint32_t * i_invMask, uint32_t i_invByteLen);

  /**
   * @brief Apply an inversion mask to data inside buffer
   * @brief Just a wrapper that takes in a ecmdDataBufferBase and calls uint32_t applyInversionMask
   * @param i_invMaskBuffer Buffer that stores inversion mask
   * @param i_invByteLen Buffer length provided in bytes
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t applyInversionMask(const ecmdDataBufferBase & i_invMaskBuffer, uint32_t i_invByteLen);

  /**
   * @brief Copy part of another DataBuffer into this one
   * @param i_bufferIn DataBuffer to copy data from - data is taken left aligned
   * @param i_targetStart Start bit to insert to
   * @param i_len Length of bits to insert
   * @param i_sourceStart Start bit in i_bufferIn - default value is zero
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from i_bufferIn to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  virtual uint32_t insert(const ecmdDataBufferBase & i_bufferIn, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart = 0);

  /**
   * @brief Copy part of a uint32_t array into this DataBuffer
   * @param i_data uint32_t array to copy into this DataBuffer - data is taken left aligned
   * @param i_targetStart Start bit to insert into
   * @param i_len Length of bits to insert
   * @param i_sourceStart Start bit in i_data - default value is zero
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from i_data to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  virtual uint32_t insert(const uint32_t * i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart = 0);

  /**
   * @brief Copy part of a uint32_t into the DataBuffer
   * @param i_data uint32_t value to copy into DataBuffer - data is taken left aligned
   * @param i_targetStart Start bit to insert into
   * @param i_len Length of bits to insert (must be <= 32)
   * @param i_sourceStart Start bit in i_data - default value is zero
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from bufferIn to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t insert(uint32_t i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart = 0);

  /**
   * @brief Copy a right aligned (decimal) uint32_t array into this DataBuffer
   * @param i_data uint32_t array to copy into this DataBuffer - data is taken right aligned
   * @param i_start Start bit to insert into
   * @param i_len Length of bits to insert
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from datain into this DataBuffer at specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   *
   * NOTE : Data is assumed to be aligned on the word boundary of i_len
   */
  uint32_t insertFromRight(const uint32_t * i_data, uint32_t i_start, uint32_t i_len);

  /**
   * @brief Copy a right aligned (decimal) uint32_t into the DataBuffer
   * @param i_data uint32_t value to copy into DataBuffer - data is taken right aligned
   * @param i_start Start bit to insert into
   * @param i_len Length of bits to insert (must be <= 32)
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from datain into this DataBuffer at specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t insertFromRight(uint32_t i_data, uint32_t i_start, uint32_t i_len);

  // The uint16_t and uint8_t interfaces confuse perl.  Since scalars aren't typed, we want them to always use the uint32_t interface
  // Swig sees the 736 below and decides it should be a uint16_t.  If you put in a larger number, it assumes 32.
  //my $data4 = new ecmd::ecmdDataBufferBase(64);
  //my $val=736;
  //$data4->insertFromRight($val,0,28);
  // Removing these interfaces keeps the behvavior consistent with previous versions of the perl module - JTA 07/10/09
#ifndef ECMD_PERLAPI
  /**
   * @brief Copy part of a uint16_t array into this DataBuffer
   * @param i_datain uint16_t array to copy into this DataBuffer - data is taken left aligned
   * @param i_targetStart Start bit to insert into
   * @param i_len Length of bits to insert
   * @param i_sourceStart Start bit in i_datain - default value is zero
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from i_datain to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t insert(const uint16_t * i_datain, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart = 0);

  /**
   * @brief Copy part of a uint16_t into the DataBuffer
   * @param i_datain uint16_t value to copy into DataBuffer - data is taken left aligned
   * @param i_targetStart Start bit to insert into
   * @param i_len Length of bits to insert (must be <= 32)
   * @param i_sourceStart Start bit in i_datain - default value is zero
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from bufferIn to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t insert(uint16_t i_datain, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart = 0);

  /**
   * @brief Copy a right aligned (decimal) uint16_t array into this DataBuffer
   * @param i_datain uint16_t array to copy into this DataBuffer - data is taken right aligned
   * @param i_start Start bit to insert into
   * @param i_len Length of bits to insert
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from datain into this DataBuffer at specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   *
   * NOTE : Data is assumed to be aligned on the word boundary of i_len
   */
  uint32_t insertFromRight(const uint16_t * i_datain, uint32_t i_start, uint32_t i_len);

  /**
   * @brief Copy a right aligned (decimal) uint16_t into the DataBuffer
   * @param i_datain uint16_t value to copy into DataBuffer - data is taken right aligned
   * @param i_start Start bit to insert into
   * @param i_len Length of bits to insert (must be <= 32)
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from datain into this DataBuffer at specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t insertFromRight(uint16_t i_datain, uint32_t i_start, uint32_t i_len);

  /**
   * @brief Copy part of a uint8_t array into this DataBuffer
   * @param i_data uint8_t array to copy into this DataBuffer - data is taken left aligned
   * @param i_targetStart Start bit to insert into
   * @param i_len Length of bits to insert
   * @param i_sourceStart Start bit in i_data - default value is zero
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from i_data to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t insert(const uint8_t * i_data, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart = 0);

  /**
   * @brief Copy part of a uint8_t into the DataBuffer
   * @param i_datain uint32_t value to copy into DataBuffer - data is taken left aligned
   * @param i_targetStart Start bit to insert into
   * @param i_len Length of bits to insert (must be <= 32)
   * @param i_sourceStart Start bit in i_datain - default value is zero
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from bufferIn to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t insert(uint8_t i_datain, uint32_t i_targetStart, uint32_t i_len, uint32_t i_sourceStart = 0);

  /**
   * @brief Copy a right aligned (decimal) uint8_t array into this DataBuffer
   * @param i_data uint8_t array to copy into this DataBuffer - data is taken right aligned
   * @param i_start Start bit to insert into
   * @param i_len Length of bits to insert
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from datain into this DataBuffer at specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   *
   * NOTE : Data is assumed to be aligned on the word boundary of i_len
   */
  uint32_t insertFromRight(const uint8_t * i_data, uint32_t i_start, uint32_t i_len);

  /**
   * @brief Copy a right aligned (decimal) uint8_t array into this DataBuffer
   * @param i_datain uint8_t array to copy into this DataBuffer - data is taken right aligned
   * @param i_start Start bit to insert into
   * @param i_len Length of bits to insert
   * @pre DataBuffer must be pre-allocated
   * @post Data is copied from datain into this DataBuffer at specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   *
   * NOTE : Data is assumed to be aligned on the word boundary of i_len
   */
  uint32_t insertFromRight(const uint8_t i_datain, uint32_t i_start, uint32_t i_len);
#endif // ECMD_PERLAPI

  /**
   * @brief Copy data from this DataBuffer into another
   * @param o_bufferOut DataBuffer to copy into - data is placed left aligned
   * @param i_start Start bit of data in this DataBuffer to copy
   * @param i_len Length of consecutive bits to copy
   * @post Data is copied from specified location in this DataBuffer to bufferOut
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range

   * NOTE : The o_bufferOut buffer is resized to the extract length and any data in the buffer is lost
   */
  uint32_t extract(ecmdDataBufferBase & o_bufferOut, uint32_t i_start, uint32_t i_len) const;

  /**
   * @brief Copy data from this DataBuffer into a uint32_t buffer
   * @param o_data uint32_t buffer to copy into - data is placed left aligned - must be pre-allocated
   * @param i_start Start bit of data in DataBuffer to copy
   * @param i_len Length of consecutive bits to copy
   * @post Data is copied from specified location in this DataBuffer to o_data
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t extract(uint32_t * o_data, uint32_t i_start, uint32_t i_len) const;

#ifndef ECMD_PERLAPI
  /**
   * @brief Copy data from this DataBuffer into a uint16_t buffer
   * @param o_data uint16_t buffer to copy into - data is placed left aligned - must be pre-allocated
   * @param i_start Start bit of data in DataBuffer to copy
   * @param i_len Length of consecutive bits to copy
   * @post Data is copied from specified location in this DataBuffer to o_data
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t extract(uint16_t * o_data, uint32_t i_start, uint32_t i_len) const;

  /**
   * @brief Copy data from this DataBuffer into a uint8_t buffer
   * @param o_data uint8_t buffer to copy into - data is placed left aligned - must be pre-allocated
   * @param i_start Start bit of data in DataBuffer to copy
   * @param i_len Length of consecutive bits to copy
   * @post Data is copied from specified location in this DataBuffer to o_data
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t extract(uint8_t * o_data, uint32_t i_start, uint32_t i_len) const;
#endif //ECMD_PERLAPI

  /**
   * @brief Copy data from this buffer into another at a given offset, preserving the size and other data in the output buffer
   * @param o_bufferOut Target data buffer where data is copied into
   * @param i_start Start bit in this DataBuffer to begin copy
   * @param i_len Length of consecutive bits to copy
   * @param i_targetStart Start bit in output buffer where data is copied defaults to zero
   * @post Data is copied from offset in this buffer to offset in out buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval EMCD_DBUF_BUFFER_OVERFLOW data requested is out of range in one of the 2 buffers
   */
  uint32_t extractPreserve(ecmdDataBufferBase & o_bufferOut, uint32_t i_start, uint32_t i_len, uint32_t i_targetStart = 0) const;

  /**
   * @brief Copy data from this DataBuffer into a generic output buffer at a given offset, preserving the size and other data in the output buffer
   * @param o_data Array of data to write into, must be pre-allocated
   * @param i_start Start bit in this DataBuffer to begin the copy
   * @param i_len Length of consecutive bits to copy
   * @param i_targetStart Starting bit in output data to place extracted data, defaults to zero
   * @post Data is copied from offset in this DataBuffer to offset in output buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL unable to allocate databuffer
   * @retval ECMD_DBUF BUFFER_OVERFLOW request is out of range for this DataBuffer, output buffer is NOT checked for overflow
   */
  uint32_t extractPreserve(uint32_t * o_data, uint32_t i_start, uint32_t i_len, uint32_t i_targetStart = 0) const;

#ifndef ECMD_PERLAPI
  /**
   * @brief Copy data from this DataBuffer into a generic output buffer at a given offset, preserving the size and other data in the output buffer
   * @param o_data Array of data to write into, must be pre-allocated
   * @param i_start Start bit in this DataBuffer to begin the copy
   * @param i_len Length of consecutive bits to copy
   * @param i_targetStart Starting bit in output data to place extracted data, defaults to zero
   * @post Data is copied from offset in this DataBuffer to offset in output buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL unable to allocate databuffer
   * @retval ECMD_DBUF BUFFER_OVERFLOW request is out of range for this DataBuffer, output buffer is NOT checked for overflow
   */
  uint32_t extractPreserve(uint16_t * o_data, uint32_t i_start, uint32_t i_len, uint32_t i_targetStart = 0) const;

  /**
   * @brief Copy data from this DataBuffer into a generic output buffer at a given offset, preserving the size and other data in the output buffer
   * @param o_data Array of data to write into, must be pre-allocated
   * @param i_start Start bit in this DataBuffer to begin the copy
   * @param i_len Length of consecutive bits to copy
   * @param i_targetStart Starting bit in output data to place extracted data, defaults to zero
   * @post Data is copied from offset in this DataBuffer to offset in output buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_INIT_FAIL unable to allocate databuffer
   * @retval ECMD_DBUF BUFFER_OVERFLOW request is out of range for this DataBuffer, output buffer is NOT checked for overflow
   */
  uint32_t extractPreserve(uint8_t * o_data, uint32_t i_start, uint32_t i_len, uint32_t i_targetStart = 0) const;
#endif //ECMD_PERLAPI

  /**
   * @brief Copy data from this DataBuffer into another DataBuffer and right justify
   * @param o_bufferOut DataBuffer to copy into - data is placed right aligned
   * @param i_start Start bit of data in DataBuffer to copy
   * @param i_len Length of consecutive bits to copy
   * @post Data is copied from specified location in this DataBuffer to o_bufferOut, right aligned.  Data is only right aligned if i_len < 32
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t extractToRight(ecmdDataBufferBase & o_bufferOut, uint32_t i_start, uint32_t i_len) const;

  /**
   * @brief Copy data from this DataBuffer into a uint32_t buffer
   * @param o_data uint32_t buffer to copy into - data is placed right aligned - must be pre-allocated
   * @param i_start Start bit of data in DataBuffer to copy
   * @param i_len Length of consecutive bits to copy
   * @post Data is copied from specified location in this DataBuffer to o_data, right aligned.  Data is only right aligned if i_len < 32
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t extractToRight(uint32_t * o_data, uint32_t i_start, uint32_t i_len) const;

#ifndef ECMD_PERLAPI
  /**
   * @brief Copy data from this DataBuffer into a uint16_t buffer
   * @param o_data uint16_t buffer to copy into - data is placed right aligned - must be pre-allocated
   * @param i_start Start bit of data in DataBuffer to copy
   * @param i_len Length of consecutive bits to copy
   * @post Data is copied from specified location in this DataBuffer to o_data, right aligned.  Data is only right aligned if i_len < 16
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t extractToRight(uint16_t * o_data, uint32_t i_start, uint32_t i_len) const;

  /**
   * @brief Copy data from this DataBuffer into a uint8_t buffer
   * @param o_data uint8_t buffer to copy into - data is placed right aligned - must be pre-allocated
   * @param i_start Start bit of data in DataBuffer to copy
   * @param i_len Length of consecutive bits to copy
   * @post Data is copied from specified location in this DataBuffer to o_data, right aligned.  Data is only right aligned if i_len < 8
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t extractToRight(uint8_t * o_data, uint32_t i_start, uint32_t i_len) const;
#endif //ECMD_PERLAPI

  /**
   * @brief Concatenate 2 DataBuffers into in this one
   * @param i_buf0 First DataBuffer to concatenate; copied to beginning of this buffer
   * @param i_buf1 Second DataBuffer to concatenate; copied to this buffer after the first buffer
   * @post Space is allocated, and data from the 2 DataBuffers is concatenated and copied to this buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t concat(const ecmdDataBufferBase & i_buf0, const ecmdDataBufferBase & i_buf1);
  /**
   * @brief Concatenate multiple DataBuffers into in this one
   * @param i_bufs The vector of databuffers to concatenate; copied in order into this buffer
   * @post Space is allocated, and data from the vector is concatenated and copied to this buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t concat(const std::vector<ecmdDataBufferBase> & i_bufs);


  /* these functions OR the datain into the DataBuffer buffer */
  /**
   * @brief OR data into DataBuffer
   * @param i_bufferIn DataBuffer to OR data from - data is taken left aligned
   * @param i_startbit Start bit to OR to
   * @param i_len Length of bits to OR
   * @post Data is ORed from i_bufferIn to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  virtual uint32_t setOr(const ecmdDataBufferBase & i_bufferIn, uint32_t i_startbit, uint32_t i_len);

  /**
   * @brief OR data into DataBuffer
   * @param i_data uint32_t buffer to OR data from - data is taken left aligned
   * @param i_startbit Start bit to OR to
   * @param i_len Length of bits to OR
   * @post Data is ORed from datain to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t setOr(const uint32_t * i_data, uint32_t i_startbit, uint32_t i_len);

  /**
   * @brief OR data into DataBuffer
   * @param i_data uint32_t to OR data from - data is taken left aligned
   * @param i_startbit Start bit to OR to
   * @param i_len Length of bits to OR (must be <= 32)
   * @post Data is ORed from datain to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t setOr(uint32_t i_data, uint32_t i_startbit, uint32_t i_len);

  /**
   * @brief OR data into DataBuffer
   * @param i_bufferIn DataBuffer to OR data from - data is taken left aligned
   * @post Entire data is ORed from bufferIn to this DataBuffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t merge(const ecmdDataBufferBase & i_bufferIn); // does a setor on the whole buffer

  /* these functions XOR the datain into the DataBuffer buffer */
  /**
   * @brief XOR data into DataBuffer
   * @param i_bufferIn DataBuffer to XOR data from - data is taken left aligned
   * @param i_startbit Start bit to XOR to
   * @param i_len Length of bits to XOR
   * @post Data is XORed from i_bufferIn to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t setXor(const ecmdDataBufferBase & i_bufferIn, uint32_t i_startbit, uint32_t i_len);

  /**
   * @brief XOR data into DataBuffer
   * @param i_data uint32_t buffer to XOR data from - data is taken left aligned
   * @param i_startbit Start bit to XOR to
   * @param i_len Length of bits to XOR
   * @post Data is XORed from datain to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t setXor(const uint32_t * i_data, uint32_t i_startbit, uint32_t i_len);

  /**
   * @brief XOR data into DataBuffer
   * @param i_data uint32_t to XOR data from - data is taken left aligned
   * @param i_startbit Start bit to XOR to
   * @param i_len Length of bits to XOR (must be <= 32)
   * @post Data is XORed from datain to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t setXor(uint32_t i_data, uint32_t i_startbit, uint32_t i_len);

  /* these functions AND the datain into the DataBuffer buffer */
  /**
   * @brief AND data into DataBuffer
   * @param i_bufferIn ecmdDataBufferBase to AND data from - data is taken left aligned
   * @param i_startbit Start bit to AND to
   * @param i_len Length of bits to AND
   * @post Data is ANDed from bufferIn to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t setAnd(const ecmdDataBufferBase & i_bufferIn, uint32_t i_startbit, uint32_t i_len);

  /**
   * @brief AND data into DataBuffer
   * @param i_data uint32_t buffer to AND data from - data is taken left aligned
   * @param i_startbit Start bit to AND to
   * @param i_len Length of bits to AND
   * @post Data is ANDed from datain to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t setAnd(const uint32_t * i_data, uint32_t i_startbit, uint32_t i_len);

  /**
   * @brief AND data into DataBuffer
   * @param i_data uint32_t to AND data from - data is taken left aligned
   * @param i_startbit Start bit to AND to
   * @param i_len Length of bits to AND (must be <= 32)
   * @post Data is ANDed from datain to this DataBuffer in specified location
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t setAnd(uint32_t i_data, uint32_t i_startbit, uint32_t i_len);

  /**
   * @brief Copy entire contents of this ecmdDataBufferBase into o_copyBuffer
   * @param o_copyBuffer DataBuffer to copy data into
   * @post copyBuffer is allocated, is an exact duplicate of this DataBuffer
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t copy(ecmdDataBufferBase & o_copyBuffer) const;

#ifndef ECMD_PERLAPI
  /**
   * @brief Copy Constructor
   * @param i_master DataBuffer to copy from
   * @post this DataBuffer is allocated, is an exact duplicate of the other
   */
  ecmdDataBufferBase& operator=(const ecmdDataBufferBase & i_master);
#endif

  /* These are only to be used to apply a buffer to the entire ecmdDataBufferBase, not just sections */
  /**
   * @brief Copy buffer into this ecmdDataBufferBase
   * @param i_buf Buffer to copy from
   * @param i_bytes Byte length to copy
   * @pre DataBuffer must be pre-allocated
   * @post  Xstate and Raw buffer are set to value in i_buf for smaller of i_bytes or buffer capacity
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  virtual uint32_t memCopyIn(const uint32_t * i_buf, uint32_t i_bytes); /* Does a memcpy from supplied buffer into ecmdDataBufferBase */

  /**
   * @brief Copy DataBuffer into supplied uint32_t buffer
   * @param o_buf Buffer to copy into - must be pre-allocated
   * @param i_bytes Byte length to copy
   * @post o_buf has contents of databuffer for smaller of i_bytes or buffer capacity
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t memCopyOut(uint32_t * o_buf, uint32_t i_bytes) const; /* Does a memcpy from ecmdDataBufferBase into supplied buffer */

  /**
   * @brief Copy buffer into this ecmdDataBufferBase
   * @param i_buf Buffer to copy from
   * @param i_bytes Byte length to copy
   * @pre DataBuffer must be pre-allocated
   * @post  Xstate and Raw buffer are set to value in i_buf for smaller of i_bytes or buffer capacity
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t memCopyIn(const uint16_t * i_buf, uint32_t i_bytes); /* Does a memcpy from supplied buffer into ecmdDataBufferBase */

  /**
   * @brief Copy DataBuffer into supplied uint32_t buffer
   * @param o_buf Buffer to copy into - must be pre-allocated
   * @param i_bytes Byte length to copy
   * @post o_buf has contents of databuffer for smaller of i_bytes or buffer capacity
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t memCopyOut(uint16_t * o_buf, uint32_t i_bytes) const; /* Does a memcpy from ecmdDataBufferBase into supplied buffer */

  /**
   * @brief Copy buffer into this ecmdDataBufferBase
   * @param i_buf Buffer to copy from
   * @param i_bytes Byte length to copy
   * @pre DataBuffer must be pre-allocated
   * @post  Xstate and Raw buffer are set to value in i_buf for smaller of i_bytes or buffer capacity
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t memCopyIn(const uint8_t * i_buf, uint32_t i_bytes); /* Does a memcpy from supplied buffer into ecmdDataBufferBase */

  /**
   * @brief Copy DataBuffer into supplied uint8_t buffer
   * @param o_buf Buffer to copy into - must be pre-allocated
   * @param i_bytes Byte length to copy
   * @post o_buf has contents of databuffer for smaller of i_bytes or buffer capacity
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t memCopyOut(uint8_t * o_buf, uint32_t i_bytes) const; /* Does a memcpy from ecmdDataBufferBase into supplied buffer */

  /**
   * @brief Flatten all the object data into a uint8_t buffer
   * @param o_data Byte buffer to write the flattened data to - should
   * @param i_len Number of bytes in the o_data buffer
   * @post o_data buffer has a flattened version of the DataBuffer - must be pre-allocated
   * Data format (all in network byte order):
   * First Word:      iv_Capacity*32 (in bits)
   * Second Word:     iv_NumBits
   * Remaining Words: Buffer data
   */
  uint32_t flatten(uint8_t * o_data, uint32_t i_len) const;

  /**
   * @brief Unflatten object data from a uint8_t buffer into this DataBuffer
   * @param i_data Byte buffer to read the flattened data from
   * @param i_len Number of bytes in the i_data buffer
   * @post This DataBuffer is allocated and initialized with the unflattened version of i_data
   * Data format (all in network byte order):
   * First Word:      iv_Capacity*32 (in bits)
   * Second Word:     iv_NumBits
   * Remaining Words: Buffer data
   */
  uint32_t unflatten(const uint8_t * i_data, uint32_t i_len);

  /**
   * @brief Return number of bytes needed for a buffer to flatten the object
   * @retval Number of bytes needed
   */
  uint32_t flattenSize(void) const;

  //@}


  /** @name Parity Functions */
  //@{
  /**
   * @brief Generate odd parity over a range of bits
   * @param i_start Start bit of range
   * @param i_stop Stop bit of range
   * @retval 0 or 1 depending on parity of range
   */
  uint32_t oddParity(uint32_t i_start, uint32_t i_stop) const;

  /**
   * @brief Generate even parity over a range of bits
   * @param i_start Start bit of range
   * @param i_stop Stop bit of range
   * @retval 0 or 1 depending on parity of range
   */
  uint32_t evenParity(uint32_t i_start, uint32_t i_stop) const;

  /**
   * @brief Generate odd parity over a range of bits and insert into DataBuffer
   * @param i_start Start bit of range
   * @param i_stop Stop bit of range
   * @param i_insertpos Bit position to insert parity
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t oddParity(uint32_t i_start, uint32_t i_stop, uint32_t i_insertpos);

  /**
   * @brief Generate even parity over a range of bits and insert into DataBuffer
   * @param i_start Start bit of range
   * @param i_stop Stop bit of range
   * @param i_insertpos Bit position to insert parity
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_BUFFER_OVERFLOW operation requested out of range
   */
  uint32_t evenParity(uint32_t i_start, uint32_t i_stop, uint32_t i_insertpos);
  //@}


  /** @name Misc Functions */
  //@{

  /**
   * @brief This function will take the passed in buffer, delete any current data it holds, and point its data var to that which is owned by the one being called with.  It will not have iv_UserOwned flag set, so it should not delete the buffer it points to, nor resize it, but it can alter the data.  The use of this function is for caching data for reads.
   * @param i_sharingBuffer input buffer
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t shareBuffer(ecmdDataBufferBase* i_sharingBuffer);

  /**
   * @brief Compress the data in the buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval non-zero on failure
   */
  uint32_t compressBuffer(ecmdCompressionMode_t i_mode = ECMD_COMP_PRD);

  /**
   * @brief Compress the data in the buffer
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval non-zero on failure
   */
  uint32_t uncompressBuffer();

  /**
   * @brief Look to see if the compression header is at the start of the buffer
   * @retval true if compressed, false if not
   */
  bool isBufferCompressed();


  /**
   * @brief This function returns the stored error state that could have been caused by any number of previous operations on the buffer
   * @param o_errorState Stored Error state
   */
  void queryErrorState(uint32_t & o_errorState);
  //@}

  /** @name Operator overloads */
  //@{
  /**
   * @brief Overload the == operator
   */
  int operator == (const ecmdDataBufferBase& i_other) const;

  /**
   * @brief Overload the != operator
   */
  int operator != (const ecmdDataBufferBase& i_other) const;

  /**
   * @brief Overload the & operator
   */
  ecmdDataBufferBase operator & (const ecmdDataBufferBase& i_other) const;

  /**
   * @brief Overload the | operator
   */
  ecmdDataBufferBase operator | (const ecmdDataBufferBase& i_other) const;

  //@}


protected:  //data
  /*************************************************************************/
  /* Layout of the eCMD Data Buffer                                        */
  /*                                                                       */
  /* If iv_NumBits <= 64, we use the variable iv_LocalData                 */
  /*   iv_LocalData[0] = Error Code.  Stored here for db sharing           */
  /*   iv_LocalData[1] = Word 0 of actual user data                        */
  /*   iv_LocalData[2] = Word 1 of actual user data                        */
  /*   iv_LocalData[3] = A footer put at the end of data to catch problems */
  /*                                                                       */
  /* The internal pointers are then set as such                            */
  /*   iv_RealData -> iv_LocalData[0]                                      */
  /*   iv_Data -> iv_LocalData[1]                                          */
  /*                                                                       */
  /* If iv_NumBits > 63, we actually malloc iv_RealData                    */
  /*   iv_RealData[0] = Error Code.  Stored here for db sharing            */
  /*   iv_RealData[1..X] = Actual user data.  X-1 = iv_Capacity            */
  /*   iv_RealData[1 + getNumWords()] = Same footer as above               */
  /*                                                                       */
  /* The internal pointers are then set as such                            */
  /*   iv_RealData -> malloced                                             */
  /*   iv_Data -> iv_RealData[1]                                           */
  /*                                                                       */
  /*************************************************************************/

  uint32_t iv_Capacity;         ///< Actual buffer capacity - always >= getNumWords()
  uint32_t iv_NumBits;          ///< Specified buffer size in bits
  uint32_t *iv_Data;            ///< Pointer to buffer inside iv_RealData
  uint32_t *iv_RealData;        ///< Real buffer - with header and tail
  uint32_t iv_LocalData[4];     ///< If the buffer is <= 64 bits, we'll store the data locally in the class
  bool     iv_UserOwned;        ///< Whether or not this buffer owns the data
  bool     iv_BufferOptimizable;///< Whether or not this is an optimizable buffer

protected:
#ifndef REMOVE_SIM
  char* iv_DataStr; /* binary or x data */
  bool iv_XstateEnabled;
#endif
};

  /** @name Derived OptimizableDataBufferBase */
  //@{
  /********************************************************************************
     Derived class ecmdOptimizableDataBufferBase definitions
  ********************************************************************************/
class ecmdOptimizableDataBufferBase : public ecmdDataBufferBase {

  public:
     /**
      * @brief Default constructor for ecmdOptimizableDataBufferBase class
      */
     ecmdOptimizableDataBufferBase();

     /**
      * @brief Constructor with bit length specified
      */
     ecmdOptimizableDataBufferBase(uint32_t i_numBits);

     /**
      * @brief Destructor for ecmdOptimizableDataBufferBase class
      */
     ~ecmdOptimizableDataBufferBase() {}
};

  //@}

#endif  /* ecmdDataBufferBase_H */
