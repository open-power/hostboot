/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/mvpd/mvpd.H $
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
#ifndef __MVPD_H
#define __MVPD_H

/**
 * @file mvpd.H
 *
 * @brief Provides the interfaces for the MVPD device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>

namespace MVPD
{

/**
* @brief Miscelaneous MVPD definitions
*/
enum
{
    RECORD_BYTE_SIZE        = 4,
    RECORD_ADDR_BYTE_SIZE   = 2,
    KEYWORD_BYTE_SIZE       = 2,
    KEYWORD_SIZE_BYTE_SIZE  = 1,
    RECORD_TOC_UNUSED       = 2,
    RT_SKIP_BYTES           = 3,

    MVPD_SECTION_SIZE       = 0x10000,
    MVPD_MAX_SECTIONS       = 8,
};

/**
* @brief Structure for all MVPD dd input parameter arguments
*/
typedef struct
{
    mvpdRecord record;
    mvpdKeyword keyword;
} input_args_t;

/**
 * @brief Structure of information needed to access requested
 *      record/keyword combinations.
 */
typedef struct
{
    mvpdRecord record;
    char recordName[MVPD_LAST_RECORD];
} mvpdRecordInfo;

/**
 */
typedef struct
{
    mvpdKeyword keyword;
    char keywordName[MVPD_LAST_KEYWORD];
} mvpdKeywordInfo;


/**
 * @brief Conversion of MVPD Records to corresponding character representation.
 */
const mvpdRecordInfo mvpdRecords[] =
{
    // -------------------------------------------------------------------
    // NOTE: This list must remain an ordered list!  There will be a
    //      testcase that checks this.  When adding new entries to the
    //      list, be sure that the keyword in each entry (value 0)
    //      are in ascending order.
    // -------------------------------------------------------------------
    { CRP0, "CRP0" },
    { CP00, "CP00" },
    { VINI, "VINI" },
    { LRP0, "LRP0" },
    { LRP1, "LRP1" },
    { LRP2, "LRP2" },
    { LRP3, "LRP3" },
    { LRP4, "LRP4" },
    { LRP5, "LRP5" },
    { LRP6, "LRP6" },
    { LRP7, "LRP7" },
    { LRP8, "LRP8" },
    { LRP9, "LRP9" },
    { LRPA, "LRPA" },
    { LRPB, "LRPB" },
    { LRPC, "LRPC" },
    { LRPD, "LRPD" },
    { LRPE, "LRPE" },
    { LWP0, "LWP0" },
    { LWP1, "LWP1" },
    { LWP2, "LWP2" },
    { LWP3, "LWP3" },
    { LWP4, "LWP4" },
    { LWP5, "LWP5" },
    { LWP6, "LWP6" },
    { LWP7, "LWP7" },
    { LWP8, "LWP8" },
    { LWP9, "LWP9" },
    { LWPA, "LWPA" },
    { LWPB, "LWPB" },
    { LWPC, "LWPC" },
    { LWPD, "LWPD" },
    { LWPE, "LWPE" },
    { VWML, "VWML" },
    // -------------------------------------------------------------------
    // DO NOT USE!!  This is for test purposes ONLY!
    { MVPD_TEST_RECORD, "TEST" },
    // -------------------------------------------------------------------
};

/**
 * @brief Conversion of MVPD Keywords to corresponding character representation.
 */
const mvpdKeywordInfo mvpdKeywords[] =
{
    // -------------------------------------------------------------------
    // NOTE: This list must remain an ordered list!  There will be a
    //      testcase that checks this.  When adding new entries to
    //      the list, be sure that the keyword in each entry (value 0)
    //      are in ascending order.
    // -------------------------------------------------------------------
    { VD,  "VD" },
    { ED,  "ED" },
    { TE,  "TE" },
    { DD,  "DD" },
    { pdP, "#P" },
    { ST,  "ST" },
    { DN,  "DN" },
    { PG,  "PG" },
    { PK,  "PK" },
    { pdR, "#R" },
    { pdV, "#V" },
    { pdH, "#H" },
    { SB,  "SB" },
    { DR,  "DR" },
    { VZ,  "VZ" },
    { CC,  "CC" },
    { CE,  "CE" },
    { FN,  "FN" },
    { PN,  "PN" },
    { SN,  "SN" },
    { PR,  "PR" },
    { HE,  "HE" },
    { CT,  "CT" },
    { HW,  "HW" },
    { pdM, "#M" },
    { IN,  "IN" },
    { pd2, "#2" },
    { pd3, "#3" },
    { OC,  "OC" },
    { FO,  "FO" },
    { pdI, "#I" },
    { pdG, "#G" },
    { MK,  "MK" },
    { PB,  "PB" },
    { CH,  "CH" },
    // -------------------------------------------------------------------
    // DO NOT USE!!  This is for test purposes ONLY!
    { MVPD_TEST_KEYWORD, "TEST" },
    // -------------------------------------------------------------------
};


/**
 * @brief This function will perform the steps required to do a read from
 *      the Hostboot MVPD data.
 *
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *       driververif.H
 *
 * @param[in] i_target - Processor Target device
 *
 * @param [in/out] io_buffer - Pointer to the data that was read from
 *       the target device.  This parameter, when set to NULL, will return the
 *       keyword size value in io_buflen.
 *
 * @param [in/out] io_buflen - Length of the buffer to be read or written
 *       to/from the target.  This value should indicate the size of the
 *       io_buffer parameter that has been allocated.  Being returned it will
 *       indicate the number of valid bytes in the buffer being returned.
 *       This parameter will contain the size of a keyword when the io_buffer
 *       parameter is passed in NULL.
 *
 * @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
 *       usrif.H
 *
 * @param [in] i_args - This is an argument list for the device driver
 *       framework.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *       error log.
*/
errlHndl_t mvpdRead ( DeviceFW::OperationType i_opType,
                      TARGETING::Target * i_target,
                      void * io_buffer,
                      size_t & io_buflen,
                      int64_t i_accessType,
                      va_list i_args );

/**
 * @brief This function will perform the steps required to do a write to
 *      the Hostboot MVPD data.
 *
 * @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
 *       driververif.H
 *
 * @param[in] i_target - Processor Target device
 *
 * @param [in/out] io_buffer - Pointer to the data that was read from
 *       the target device.  It will also be used to contain data to
 *       be written to the device.
 *
 * @param [in/out] io_buflen - Length of the buffer to be read or written
 *       to/from the target.  This value should indicate the size of the
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
 *       error log.
*/
errlHndl_t mvpdWrite ( DeviceFW::OperationType i_opType,
                       TARGETING::Target * i_target,
                       void * io_buffer,
                       size_t & io_buflen,
                       int64_t i_accessType,
                       va_list i_args );

/**
 * @brief This function actually reads the data from the source of the MVPD
 *      data.
 *
 * @param[in] i_byteAddr - The offset to be read.
 *
 * @param[in] i_numBytes - The number of bytes to read.
 *
 * @param[out] o_data - The data buffer where the data will be placed.
 *
 * @param[in] i_target - Processor Target device.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
*/
errlHndl_t mvpdFetchData ( uint64_t i_byteAddr,
                           size_t i_numBytes,
                           void * o_data,
                           TARGETING::Target * i_target );

/**
 * @brief This function reads a binary file that contains the MVPD data for
 *      all targets.
 *
 * @param[in] i_offset - The offset to read.
 *
 * @param[in] i_numBytes - The number of bytes to read.
 *
 * @param[out] o_data - The Data buffer where the data will be placed.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
*/
errlHndl_t mvpdReadBinaryFile ( uint64_t i_offset,
                                size_t i_numBytes,
                                void * o_data );

/**
 * @brief This function will translate the enumeration for the MVPD record
 *      into a char * variable to be used for comparing what was read from
 *      the MVPD data.
 *
 * @param[in] i_record - The record enumeration.
 *
 * @param[out] o_record - The char representation of the record.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t mvpdTranslateRecord ( mvpdRecord i_record,
                                 const char *& o_record );

/**
 * @brief This function will translate the enumeration for the MVPD keyword
 *      into a char * variable to be used for comparing what was read from
 *      the MVPD data.
 *
 * @param[in] i_keyword - The keyword enumeration.
 *
 * @param[out] o_keyword - The char representation of the record.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t mvpdTranslateKeyword ( mvpdKeyword i_keyword,
                                  const char *& o_keyword );

/**
 * @brief This function will read the MVPD TOC to find the offset where the
 *      given record is located within the chunk of data.
 *
 * @param[in] i_record - String value for the record to look for.
 *
 * @param[out] o_offset - The offset where the record is located.
 *
 * @param[in] i_target - The target to retrieve the data for.
 *
 * @param[in] i_args - The input arguments.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t mvpdFindRecordOffset ( const char * i_record,
                                  uint16_t & o_offset,
                                  TARGETING::Target * i_target,
                                  input_args_t i_args );

/**
 * @brief This function will read the required keyword from the MVPD data.
 *
 * @param[in] i_keywordName - String representation of the keyword.
 *
 * @param[in] i_recordName - String representation of the record.
 *
 * @param[in] i_offset - The offset to start reading.
 *
 * @param[in] i_target - The target to retrieve data for.
 *
 * @param[out] io_buffer - The buffer to place the data in.
 *
 * @param[in/out] io_buflen - Length of the buffer to be read or written
 *       to/from the target.  This value should indicate the size of the
 *       io_buffer parameter that has been allocated.  Being returned it will
 *       indicate the number of valid bytes in the buffer being returned.
 *
 * @param[in] i_args - The input arguments.
 *
 * @return errHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t mvpdRetrieveKeyword ( const char * i_keywordName,
                                 const char * i_recordName,
                                 uint16_t i_offset,
                                 TARGETING::Target * i_target,
                                 void * io_buffer,
                                 size_t & io_buflen,
                                 input_args_t i_args );


}; // end MVPD namespace

#endif  // __MVPD_H
