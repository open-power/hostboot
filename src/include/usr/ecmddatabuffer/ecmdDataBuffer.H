//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/ecmddatabuffer/ecmdDataBuffer.H $
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
#ifndef ECMDDATABUFFER_H
#define ECMDDATABUFFER_H

/**
 * @file ecmdDataBuffer.H
 * @brief Provides a means to handle data from the eCMD C API
 *
 * @todo - This is only created to compile code.  Needs to be replaced with John Farrugia's version
 *
 */

//----------------------------------------------------------------------
//  Constants
//----------------------------------------------------------------------
/* Define these if for some reason we are building without ecmdReturnCodes.H */
#define ECMD_ERR_ECMD                           0x01000000 ///< Error came from eCMD
#define ECMD_DBUF_SUCCESS                       0x0    ///< DataBuffer returned successfully

/**
 @brief Provides a means to handle data from the eCMD C API
*/
class ecmdDataBufferBase {

public:

  /** @name ecmdDataBufferBase Constructors */
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
  explicit ecmdDataBufferBase(uint32_t i_numBits);

  /**
   * @brief Default Destructor
   */
  virtual ~ecmdDataBufferBase();

  /**
   * @brief Called by the destructor, available to user to reset buffer to default constructor state
   * @retval ECMD_DBUF_SUCCESS on success
   * @retval ECMD_DBUF_NOT_OWNER when called on buffer not owned
   * @retval nonzero on failure
   * @post Memory deallocated and size set to 0
   */
  uint32_t clear();

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
  uint32_t setCapacity (uint32_t i_newNumWords);


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
  uint32_t setDoubleWord(uint32_t i_doublewordoffset, uint64_t i_value);

  /**
   * @brief Fetch a doubleword from ecmdDataBuffer
   * @param i_doublewordoffset Offset of doubleword to fetch
   * @retval Value of doubleword requested
   */
  uint64_t getDoubleWord(uint32_t i_doublewordoffset) const;

  /**
   * @brief Return the length of the buffer in words
   * @retval Buffer length in words rounded up
   */
  uint32_t   getWordLength() const;

  /**
   * @brief Clear entire buffer to 0's
   * @retval ECMD_DBUF_SUCCESS on success
   */
  uint32_t flushTo0();

protected:
  uint32_t iv_Capacity;         ///< Actual buffer capacity - always >= getNumWords()
  uint32_t iv_NumBits;          ///< Specified buffer size in bits
  uint32_t *iv_Data;            ///< Pointer to buffer inside iv_RealData
  uint32_t *iv_RealData;        ///< Real buffer - with header and tail
  uint32_t iv_LocalData[4];     ///< If the buffer is <= 64 bits, we'll store the data locally in the class
  bool     iv_UserOwned;        ///< Whether or not this buffer owns the data
};

#endif  /* ECMDDATABUFFER_H */
