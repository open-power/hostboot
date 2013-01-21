/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/ipvpd.H $                                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef _VPD_IPVPD_H
#define _VPD_IPVPD_H


#include <pnor/pnorif.H>
#include "vpd.H"

/** @file ipvpd.H
 *  @brief Provides base support for i/p-Series style IBM VPD
 */

/**
 *  @brief  Base class for i/p-Series VPD
 *     
 */
class IpVpdFacade
{
  public:

    /**
     * @brief Miscelaneous IPVPD definitions
     */
    enum
    {
        RECORD_BYTE_SIZE        = 4,
        RECORD_ADDR_BYTE_SIZE   = 2,
        KEYWORD_BYTE_SIZE       = 2,
        KEYWORD_SIZE_BYTE_SIZE  = 1,
        RECORD_TOC_UNUSED       = 2,
        RT_SKIP_BYTES           = 3,
    };

    /**
     * @brief typdef for ipVpdRecord values
     */
    typedef uint32_t ipVpdRecord;
    /**
     * @brief typdef for ipVpdKeyword values
     */
    typedef uint32_t ipVpdKeyword;

    /**
     * @brief Structure for all VPD dd input parameter arguments
     */
    typedef struct
    {
        ipVpdRecord record;
        ipVpdKeyword keyword;
    } input_args_t;

    /**
     * @brief Structure of information needed to access requested
     *      record/keyword combinations.
     */
    typedef struct
    {
        ipVpdRecord record;
        char recordName[RECORD_BYTE_SIZE+1];
    } recordInfo;

    /**
     */
    typedef struct
    {
        ipVpdKeyword keyword;
        char keywordName[KEYWORD_BYTE_SIZE+1];
    } keywordInfo;


    /**
     * @brief  Constructor
     *
     * @param[in] i_vpdSectionSize - Space allocated in PNOR for each
     *                               instance of the current chip.
     *
     * @param[in] i_vpdMaxSections - Number of sections allocated in PNOR
     *                               for the current chip.
     *
     * @param[in] i_vpdRecords -     Pointer to array of VPD Records to use
     *
     * @param[in] i_recSize -       size of i_vpdRecords array
     *
     * @param[in] i_vpdKeywords -    Pointer to array of VPD Keywords to use
     *
     * @param[in] i_keyCount -       size of i_vpdKeywords array
     *
     * @param[in] i_pnorSection -    PNOR Section containing VPD for current
     *                               chip
     *
     * @param[in] i_mutex -          Mutex to ensure instance variable updates
     *                               are thread safe
     *
     * @param[in] i_vpdMsgType -     Message type to use when sending write
     *                               data to FSP
     *
     */
    IpVpdFacade(uint64_t i_vpdSectionSize,
                uint64_t i_vpdMaxSections,
                const  recordInfo* i_vpdRecords,
                uint64_t i_recSize,
                const  keywordInfo* i_vpdKeywords,
                uint64_t i_keySize,
                PNOR::SectionId i_pnorSection,
                mutex_t i_mutex,
                VPD::VPD_MSG_TYPE i_vpdMsgType );


    /**
     * @brief This function will perform the steps required to do a read from
     *      the Hostboot I/P Series VPD data.
     *
     * @param[in] i_target -Target device
     *
     * @param [in/out] io_buffer - Pointer to the data that was read from
     *       the target device.  This parameter, when set to NULL, will return
     *       the keyword size value in io_buflen.
     *
     * @param [in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned. This parameter will contain the size of a keyword when
     *       the io_buffer parameter is passed in NULL.
     *
     * @param [in] i_args - Records/Keyword struct
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t read ( TARGETING::Target * i_target,
                      void* io_buffer,
                      size_t & io_buflen,
                      input_args_t i_args );

    /**
     * @brief This function will perform the steps required to do a write to
     *      the Hostboot I/P Series VPD data.
     *
     * @param[in] i_target -Target device
     *
     * @param [in/out] io_buffer - Pointer to the data that was read from
     *       the target device.  It will also be used to contain data to
     *       be written to the device.
     *
     * @param [in/out] io_buflen - Length of the buffer to be read or written
     *       to/from the target.  This value should indicate the size of the
     *       io_buffer parameter that has been allocated.  Being returned it
     *       willindicate the number of valid bytes in the buffer being
     *       returned.
     *
     * @param [in] i_args - Records/Keyword struct
     *
     * @return errlHndl_t - NULL if successful, otherwise a pointer to the
     *       error log.
     */
    errlHndl_t write ( TARGETING::Target * i_target,
                      void* io_buffer,
                      size_t & io_buflen,
                      input_args_t i_args );

  protected:

    /**
     * @brief This function will translate the enumeration for the VPD record
     *      into a char * variable to be used for comparing what was read from
     *      the VPD data.
     *
     * @param[in] i_record - The record enumeration.
     *
     * @param[out] o_record - The char representation of the record.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t translateRecord ( ipVpdRecord i_record,
                                 const char *& o_record );

    /**
     * @brief This function will translate the enumeration for the VPD keyword
     *      into a char * variable to be used for comparing what was read from
     *      the VPD data.
     *
     * @param[in] i_keyword - The keyword enumeration.
     *
     * @param[out] o_keyword - The char representation of the record.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t translateKeyword ( ipVpdKeyword i_keyword,
                                  const char *& o_keyword );

    /**
     * @brief This function will read the VPD TOC to find the offset where the
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
    errlHndl_t findRecordOffset ( const char * i_record,
                                  uint16_t & o_offset,
                                  TARGETING::Target * i_target,
                                  input_args_t i_args );

    /**
     * @brief This function will read the required keyword from the VPD data.
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
     *       io_buffer parameter that has been allocated.  Being returned it
     *       will indicate the number of valid bytes in the buffer being
     *       returned.
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t retrieveKeyword ( const char * i_keywordName,
                                 const char * i_recordName,
                                 uint16_t i_offset,
                                 TARGETING::Target * i_target,
                                 void * io_buffer,
                                 size_t & io_buflen,
                                 input_args_t i_args );

    /**
     * @brief This function will write the required keyword into the VPD data.
     *
     * @param[in] i_keywordName - String representation of the keyword.
     *
     * @param[in] i_recordName - String representation of the record.
     *
     * @param[in] i_offset - The offset to start writing.
     *
     * @param[in] i_target - The target to write data for.
     *
     * @param[in] i_buffer - The buffer to pull the data from.
     *
     * @param[in] i_buflen - Length of the buffer to be written
     *       to the target's VPD area.  This value should indicate the
     *       size of the io_buffer parameter that has been allocated.  
     *
     * @param[in] i_args - The input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t writeKeyword ( const char * i_keywordName,
                              const char * i_recordName,
                              uint16_t i_offset,
                              TARGETING::Target * i_target,
                              void * i_buffer,
                              size_t & i_buflen,
                              input_args_t i_args );

    /**
     * @brief This function will locate the byte address of a keyword
     *   within its VPD section.
     *
     * @param[in] i_keywordName - String representation of the keyword.
     *
     * @param[in] i_recordName - String representation of the record.
     *
     * @param[in] i_offset - The offset to start writing.
     *
     * @param[in] i_target - The target to write data for.
     *
     * @param[out] o_keywordSize - Size of keyword in bytes.
     *
     * @param[out] o_byteAddr - Address of keyword, relative to this target's
     *    section.
     *
     * @param[in] i_args - The original input arguments.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t findKeywordAddr ( const char * i_keywordName,
                                 const char * i_recordName,
                                 uint16_t i_offset,
                                 TARGETING::Target * i_target,
                                 size_t& o_keywordSize,
                                 uint64_t& o_byteAddr,
                                 input_args_t i_args );
    /**
     * @brief This function actually reads the data from the source of the VPD
     *      data.
     *
     * @param[in] i_byteAddr - The offset to be read.
     *
     * @param[in] i_numBytes - The number of bytes to read.
     *
     * @param[out] o_data - The data buffer where the data will be placed.
     *
     * @param[in] i_target - Target device.
     *
     * @return errHndl_t - NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t fetchData ( uint64_t i_byteAddr,
                           size_t i_numBytes,
                           void * o_data,
                           TARGETING::Target * i_target );


    /**
     * @brief This function compares 2 ipvpd record values.  Used for binary
     *       search to find a match.
     *
     * @param[in] e1 - Entry 1 to be compared.
     *
     * @param[in] e2 - Entry 2 to be compared.
     *
     * @return bool - Whether or not the e2 value is larger than the e1 value.
     */
    static bool compareKeywords ( const keywordInfo e1,
                           const keywordInfo e2 );

    /**
     * @brief This function compares 2 vpd keyword values.  Used for binary
     *       search to find a match.
     *
     * @param[in] e1 - Entry 1 to be compared.
     *
     * @param[in] e2 - Entry 2 to be compared.
     *
     * @return bool - Whether or not the e2 value is larger than the e1 value.
     */
    static bool compareRecords ( const recordInfo e1,
                          const recordInfo e2 );

    /**
     * @brief This function compares sizes to be sure buffers are large enough
     *      to handle the data to be put in them.  If it is not, it will return
     *      an error.
     *
     * @param[in] i_bufferSize - The size of the buffer to check.
     *
     * @param[in] i_expectedSize - The minimum size the buffer should be.
     *
     * @return errlHndl_t - An error log will be returned if the buffer is not
     *      large enough.
     */
    errlHndl_t checkBufferSize( size_t i_bufferSize,
                                size_t i_expectedSize );


  protected: // Variables

    /**
     * @brief Indicates allocated space for each chip's VPD
     *        data in PNOR.
     */
    uint64_t iv_vpdSectionSize;

    /**
     * @brief Indicates number of VPD sections in PNOR for
     *        current type of chip
     */
    uint64_t iv_vpdMaxSections;

    /**
     * @brief Pointer to array of VPD Record information
     *        
     */
    const recordInfo* iv_vpdRecords;

    /**
     * @brief Number of VPD Records for current chip
     *        
     */
    uint64_t iv_recSize;

    /**
     * @brief Pointer to array of VPD Keyword information
     *        
     */
    const keywordInfo* iv_vpdKeywords;

    /**
     * @brief Number of VPD Keywords for current chip
     *        
     */
    uint64_t iv_keySize;

    /**
     * @brief PNOR section enum for vpd type
     *
     */
    PNOR::SectionId iv_pnorSection;

    /**
     * @brief VPD Operation Mutex
     *
     */
    mutex_t iv_mutex;

    /**
     * @brief cached PNOR offset for VPD
     *
     */
     uint64_t iv_cachePnorAddr;

     /**
      * @brief cached PNOR offset for VPD
      *
      */
     VPD::VPD_MSG_TYPE iv_vpdMsgType;
};



#endif /* _VPD_IPVPD_H */
