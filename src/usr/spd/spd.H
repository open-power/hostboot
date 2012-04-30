/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/spd/spd.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __SPD_H
#define __SPD_H

/**
 * @file spd.H
 *
 * @brief Provides the interfaces for the SPD device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>
#include <spd/spdif.H>

namespace SPD
{

/**
* @brief Miscellaneous enumerations for SPD
*/
enum
{
    MEM_TYPE_ADDR = 0x2,        // DIMM Basic Memory Type address
    MEM_TYPE_ADDR_SZ = 0x1,     // DIMM Basic Memory Type address size

    DIMM_SPD_SECTION_SIZE = 0x200,  // Size each DIMM SPD section
    DIMM_SPD_MAX_SECTIONS = 512,    // Maximum number of sections

    // Basic Memory Type Enumerations
    SPD_DDR3 = 0xB,
    SPD_DDR4 = 0xC,  // TODO - Proposed value from draft Spec.
};

/**
 * @brief Enumerations for Module Specfic Keywords
 */
typedef enum
{
    NA      = 0x00,
    UMM     = 0x01,
    RMM     = 0x02,
    CMM     = 0x04,
    LRMM    = 0x08,
    ALL     = 0xFFFF,
} modSpecTypes_t;


/**
* @brief Structure to define the lookup table for SPD keywords
*       for DIMMs.
*/
struct KeywordData
{
    uint16_t keyword;   // SPD keyword this data corresponds to
    uint8_t offset;     // Byte offset in the SPD data
    uint8_t length;     // Number of bytes to retrieve
    bool useBitMask;    // Use the bitmask to mask off bits, if true, length must be
                        //      l byte, unless it is a "special" case
    uint8_t bitMask;    // Bit mask
    uint8_t shift;      // Used for fields < 1 byte to right justify all values.
    bool isSpecialCase; // Whether or not this entry is a special case.
    bool writable;      // Whether this keyword can be written to.
    modSpecTypes_t modSpec; // Module Specific type keyword is valid for.
};


/**
 * @brief This function is used to read SPD keywords from collected
 *      SPD data for the given target
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target - DIMM Target device
*
* @param [in/out] io_buffer - Pointer to the data that was read from
*       the target device.
*
* @param [in/out] io_buflen - Length of the buffer to be read
*       from the target.  This value should indicate the size of the
*       io_buffer parameter that has been allocated.  Being returned it will
*       indicate the number of valid bytes in the buffer being returned.
*
* @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
*       usrif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdGetKeywordValue ( DeviceFW::OperationType i_opType,
                                TARGETING::Target * i_target,
                                void * io_buffer,
                                size_t & io_buflen,
                                int64_t i_accessType,
                                va_list i_args );

/**
 * @brief This function is used to write SPD keyword values.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target - DIMM Target device
*
* @param [in/out] io_buffer - Pointer to the data that will contain data
*       to be written to the device.
*
* @param [in/out] io_buflen - Length of the buffer to be written
*       to the target.  This value should indicate the size of the
*       io_buffer parameter that has been allocated.  Being returned it will
*       indicate the number of valid bytes written to the target.
*
* @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
*       usrif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdWriteKeywordValue ( DeviceFW::OperationType i_opType,
                                  TARGETING::Target * i_target,
                                  void * io_buffer,
                                  size_t & io_buflen,
                                  int64_t i_accessType,
                                  va_list i_args );

/**
 * @param This function is a wrapper for reading the correct keyword.
 *      It will route the read to whatever function has the latest
 *      supported access code.
 *
 * @param[in] i_byteAddress - The offset into the JEDEC SPD layout.
 *
 * @param[in] i_numbytes - Number of bytes to read.
 *
 * @param[out] o_data - The data buffer that will return the data read.
 *
 * @param[in] i_target - The target DIMM to access.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdFetchData ( uint64_t i_byteAddr,
                          size_t i_numBytes,
                          void * o_data,
                          TARGETING::Target * i_target );

/**
 * @brief This function is a wrapper for writing the correct keyword.
 *      It will route the write to whatever function has the latest
 *      supported access code.
 *
 * @param[in] i_offset - The offset into the JEDEC SPD layout.
 *
 * @param[in] i_numbytes - Number of bytes to read.
 *
 * @param[in] i_data - The data buffer that will return the data read.
 *
 * @param[in] i_target - The target DIMM to access.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdWriteData ( uint64_t i_offset,
                          size_t i_numBytes,
                          void * i_data,
                          TARGETING::Target * i_target );


/**
 * @param This function will read the SPD keyword from the appropriate
 *      table.
 *
 * @param[in] i_keyword - The SPD keyword to access.
 *
 * @param[in/out] io_buffer - The buffer that will contain the data
 *      read from the SPD data.
 *
 * @param[in/out] io_buflen - The requested number of bytes to read.
 *      The actual number of bytes read will be returned.
 *
 * @param[in] i_target - The target DIMM to access the data for.
 *
 * @param[in] i_DDRRev - The DIMM DDR Revision.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdGetValue ( uint64_t i_keyword,
                         void * io_buffer,
                         size_t & io_buflen,
                         TARGETING::Target * i_target,
                         uint64_t i_DDRRev );


/**
 * @brief This function will write the SPD keyword from the appropriate
 *      table.
 *
 * @param[in] i_keyword - The SPD keyword to access.
 *
 * @param[in/out] io_buffer - The buffer that will contain the data
 *      written from the SPD data.
 *
 * @param[in/out] io_buflen - The requested number of bytes to write.
 *      The actual number of bytes written will be returned.
 *
 * @param[in] i_target - The target DIMM to access the data for.
 *
 * @param[in] i_DDRRev - The DIMM DDR Revision.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdWriteValue ( uint64_t i_keyword,
                           void * io_buffer,
                           size_t & io_buflen,
                           TARGETING::Target * i_target,
                           uint64_t i_DDRRev );


/**
 * @param This function handles the special case keywords where
 *      the data isn't sequential, or is broken up between two different
 *      offsets within the layout.
 *
 * @param[in] i_kwdData - The SPD keyword to access.
 *
 * @param[in/out] io_buffer - The buffer that will contain the data
 *      read from the SPD data.
 *
 * @param[in/out] io_buflen - The requested number of bytes to read.
 *      The actual number of bytes read will be returned.
 *
 * @param[in] i_target - The target DIMM to access the data for.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdSpecialCases ( KeywordData i_kwdData,
                             void * io_buffer,
                             size_t & io_buflen,
                             TARGETING::Target * i_target,
                             uint64_t i_DDRRev );

/**
 * @brief This function checks to make sure that the buffer allocated
 *      is large enough to hold the data that needs to be returned.
 *
 * @param[in] i_bufferSz - The size of the buffer passed in by the caller.
 *
 * @param[in] i_expBufferSz - The expected buffer size for the keyword
 *      requested.
 *
 * @param[in] i_keyword - The SPD Keyword requested.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdCheckSize ( size_t i_bufferSz,
                          size_t i_expBufferSz,
                          uint64_t i_keyword );

/**
 * @brief This function will read a binary file from PNOR.  This is
 *      not the long term solution, but mainly for initial testing.
 *
 * @param[in] i_byteAddr - The byte offset into the SPD layout.
 *
 * @param[in] i_bytes - Number of bytes to access.
 *
 * @param[out] o_data - The data buffer containing the data read.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t spdReadBinaryFile ( uint64_t i_byteAddr,
                               size_t i_numBytes,
                               void * o_data );

/**
 * @brief This function performs the presence detect for all DIMMs.
 *
 * @param[in] i_opType - Operation type, see DeviceFW::OperationType
 *      in driverif.H
 *
 * @param[in] i_target - The target to query.
 *
 * @param[in/out] io_buffer - Buffer to contain the boolean for presence
 *      detect.
 *
 * @param[in/out] io_buflen - Size of buffer provided for doing the presence
 *      detect.  Will always be 1.  If size returned equals 0, the request
 *      failed.
 *
 * @param[in] i_accessType - DeviceFW::AccessType enum.
 *
 * @param[in] i_args - An arguement for the Device Driver framework.  There
 *      are no args for this function.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t dimmPresenceDetect( DeviceFW::OperationType i_opType,
                               TARGETING::Target * i_target,
                               void * io_buffer,
                               size_t & io_buflen,
                               int64_t i_accessType,
                               va_list i_args );

/**
 * @brief This function is used to check the parameters in the SPD data that
 *      indicate which module specific keywords are valid, and then check that
 *      against the data in the table flags.
 *
 * @param[in] i_kwdData - The table entry for the keyword being requested.
 *
 * @param[in] i_memType - The DDRx revision value from Byte 2 of the SPD data.
 *
 * @param[in] i_target - The chip target.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t checkModSpecificKeyword ( KeywordData i_kwdData,
                                     uint64_t i_memType,
                                     TARGETING::Target * i_target );

/**
 * @brief This function will query the PNOR RP to get the offset of the
 *      section requested.  It will then set global variables to save this
 *      value away for later use.  This function only needs to be called once.
 *
 * @param[in] i_pnorInfo - Structure of common PNOR information needed to
 *      query for the sections address.
 *
 * @param[in/out] io_cachedAddr - This parameter is a gloval variable in the
 *      calling code.  It is the address that is obtained from the PNOR
 *      RP.
 *
 * @param[in] i_mutex - The Mutex from the calling code.  It is locked when
 *      the globals are modified.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      Error log.
*/
errlHndl_t getPnorAddr ( pnorInformation & i_pnorInfo,
                         uint64_t &io_cachedAddr,
                         mutex_t * i_mutex );

/**
 * @brief This function is used to query the attribute code to get the VPD
 *      Location value for the target provided.
 *
 * @param[out] o_vpdLocation - The value of the VPD Location attribute.
 *
 * @param[in] i_target - The target to query.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      Error log.
 */
errlHndl_t getVpdLocation ( int64_t & o_vpdLocation,
                            TARGETING::Target * i_target );


/**
 * @brief This function will read the PNOR at the correct offset and number of
 *      bytes for the keyword requested.
 *
 * @param[in] i_byteAddr - The offset to access in the PNOR.
 *
 * @param[in] i_numBytes - Number of bytes to read.
 *
 * @param[out] o_data - The data buffer that the read data will be placed
 *      into.
 *
 * @param[in] i_target - The chip target to access the data for.
 *
 * @param[in] i_pnorInfo - Information about the PNOR section and side that we
 *      need to know to make the request.
 *
 * @param[in/out] io_cachedAddr - The address offset to the data chunk in
 *      PNOR.
 *
 * @param[in] i_mutex - The mutex to lock/unlock while setting io_isAddrCached
 *      and io_cachedAddr.  It is assumed that those parameters are global
 *      variables in the code where they reside.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t readPNOR ( uint64_t i_byteAddr,
                      size_t i_numBytes,
                      void * o_data,
                      TARGETING::Target * i_target,
                      pnorInformation & i_pnorInfo,
                      uint64_t &io_cachedAddr,
                      mutex_t i_mutex );

/**
 * @brief This function will write the PNOR at the correct offset and number
 *      of bytes for the keyword requested.
 *
 * @param[in] i_byteAddr - The offset to access in the PNOR.
 *
 * @param[in] i_numBytes - The number of bytes to write.
 *
 * @param[in] i_data - The data buffer of the data to be written.
 *
 * @param[in] i_target - The chip target to access the data for.
 *
 * @param[in] i_pnorInfo - Information about the PNOR section and side that we
 *      need to know to make the request.
 *
 * @param[in/out] io_cachedAddr - The address offset to the data chunk in
 *      PNOR.
 *
 * @param[in] i_mutex - The mutex to lock/unlock while setting io_isAddrCached
 *      and io_cachedAddr.  It is assumed that those parameters are global
 *      variables in the code where they reside.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t writePNOR ( uint64_t i_byteAddr,
                       size_t i_numBytes,
                       void * i_data,
                       TARGETING::Target * i_target,
                       pnorInformation & i_pnorInfo,
                       uint64_t &io_cachedAddr,
                       mutex_t * i_mutex );

/**
 * @brief This function handles sending the mailbox message to the Fsp to
 *      notify of updates to the data.
 *
 * TODO with Story 41365
 * @param NONE, yet.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the error
 *      log.
 */
errlHndl_t spdSendMboxWriteMsg ( void );

}; // end SPD namespace

#endif  // __SPD_H
