/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/lpcxscom.H $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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

#ifndef __LPC_LPCXSCOM_H
#define __LPC_LPCXSCOM_H

#include "lpcdd.H"
#include <lpc/lpcif.H>

/**
 *  @file lpcxscom.H
 *
 *  @brief Provides an interface for an LPC driver that performs all LPC
 *      operations via XSCOM
 */

/**
 *  @brief LPC device driver that performs all operations via XSCOM instead of
 *     via MMIO (to bypass a chip hardware bug that leads to a checkstop in
 *     specific error conditions, at the expense of decreased performance).  It
 *     provides access to the LPC bus for a specific processor.
 */
class XscomLpc : public LpcDD
{
  public:

    /**
     *  @brief Constructor
     *
     *  @param[in] i_pProc Processor target associated with the LPC controller
     */
    XscomLpc(TARGETING::Target* i_pProc);

    /**
     *  @brief Destructor
     */
    virtual ~XscomLpc();

    /**
     *  @brief Performs an XSCOM LPC read operation (breaks larger requests into
     *      smaller LPC reads, handles cases where errors already exist before
     *      executing the LPC operation)
     *
     *  @param[in]     i_type     LPC transaction type
     *  @param[in]     i_addr     LPC address
     *  @param[out]    o_pBuffer  Pointer to buffer to receive the
     *      read data.  It must not be nullptr (or API asserts), and the buffer
     *      must hold >= io_buflen bytes.  On success, the pointed-to data
     *      contains the actual number of bytes read.
     *  @param[in/out] io_buflen  On input: number of bytes to read.
     *       On output (and success): number of bytes actually read.
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr LPC read succeeded
     *  @retval !nullptr LPC read failed; Error log handle points to valid error
     *      log.
     */
    virtual errlHndl_t readLPC(
        LPC::TransType i_type,
        uint32_t       i_addr,
        void*          o_pBuffer,
        size_t&        io_buflen);

    /**
     *  @brief Performs an XSCOM LPC write operation (breaks larger requests
     *      into smaller LPC writes, handles cases where errors already exist
     *      before executing the LPC operation)
     *
     *  @param[in]     i_type    LPC transaction type
     *  @param[in]     i_addr    LPC address
     *  @param[in]     i_pBuffer Pointer to buffer containing data to write.  It
     *      must not be nullptr (or API asserts), and the number of valid bytes
     *      in the buffer must match io_buflen.
     *  @param[in/out] io_buflen On input: number of bytes to write;
     *       On output (and success): number of bytes actually written.
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr LPC write succeeded
     *  @retval !nullptr LPC write failed; Error log handle points to valid
     *      error log.
     */
    virtual errlHndl_t writeLPC(
        LPC::TransType i_type,
        uint32_t       i_addr,
        const void*    i_pBuffer,
        size_t&        io_buflen);

    /**
     *  @brief Reset LPC complex to a clean state
     *
     *  @parm[in] i_resetLevel Type of LPC reset to perform
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr LPC reset succeeded
     *  @retval !nullptr LPC reset failed; Error log handle points to valid
     *      error log.
     */
    virtual errlHndl_t hwReset( ResetLevels i_resetLevel );

    /**
     *  @brief Check for errors in LPC complex by examining the OPB Master
     *      Accumulated Status Register and LPCHC LPCIRQ Status Register
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr Found no LPC complex status errors
     *  @retval !nullptr Failed to read one of the LPC complex status registers
     *      or one of said status registers reported fault conditions.  Error
     *      log handle points to valid error log.
     */
    virtual errlHndl_t checkForLpcErrors();

  protected:

    /**
     *  @brief Adds FFDC to the input error log.  Unless only the XSCOM FFDC
     *     is requested, gathers up XSCOM registers related to the LPC XSCOM
     *     facility, as well as a firehose dump of all registers in LPC error
     *     space (OPB master, OPB arbiter, LPCHC).  All data is dumped into the
     *     error log within a user detail section.
     *
     *  @param[in/out] io_pError On input: reference to error log handle to
     *      append FFDC to and to trace info of.  Must not be nullptr (or API
     *      asserts).  On output (and success): error log content updated with
     *      FFDC data.
     *  @param[in] i_timeoutDataOnly Whether to include ONLY XSCOM LPC related
     *      SCOM register FFDC in the error log. Default = include everything.
     */
    void addFFDC(
        errlHndl_t& io_pError,
        bool        i_timeoutDataOnly=false);

    /**
     *  @brief Read LPC space via XSCOM (non-MMIO!)
     *
     *  @par Detailed Description:
     *      Reads LPC space via XSCOM facility, as opposed to
     *      direct MMIO access.  This API performs address translation and error
     *      checking, balking most of the work to the _rwLPC function.
     *
     *  @param[in] i_type Area of LPC space to read from
     *  @param[in] i_addr Address in LPC space to read from
     *  @param[out] o_pBuffer Pointer to buffer to receive the
     *      read data.  It must not be nullptr (or API asserts), and the buffer
     *      must hold >= io_buflen bytes.  On success, the pointed-to data
     *      contains the actual number of bytes read.
     *  @param[in/out] io_buflen On input: amount of data to read, in bytes.
     *      Must be a power of two.  Must be > 0 bytes.  Must be <= 8 bytes.
     *      Any violation of these conditions results in an assert in lower
     *      level code.  On output: the amount of data read, in bytes.
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr LPC read succeeded
     *  @retval !nullptr LPC read failed; error log handle points to valid
     *      error log object
     */
    errlHndl_t _readLPC(
        LPC::TransType i_type,
        uint32_t       i_addr,
        void*          o_pBuffer,
        size_t&        io_buflen);

    /**
     *  @brief Write LPC space via XSCOM (non-MMIO!)
     *
     *  @par Detailed Description:
     *      Writes LPC space via XSCOM facility, as opposed to
     *      direct MMIO access.  This API performs address translation and error
     *      checking, balking most of the work to the _rwLPC function.
     *
     *  @param[in] i_type Area of LPC space to write to
     *  @param[in] i_addr Address in LPC space to write to
     *  @param[in] i_pBuffer Pointer to buffer containing data to write.  It
     *      must not be nullptr (or API asserts), and the number of valid bytes
     *      in the buffer must match io_buflen.
     *  @param[in/out] io_buflen On input: amount of data to write, in bytes.
     *      Must be a power of two.  Must be > 0 bytes.  Must be <= 8 bytes.
     *      Any violation of these conditions results in an assert in lower
     *      level code.  On output: the amount of data written, in bytes.
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr LPC write succeeded
     *  @retval !nullptr LPC write failed; error log handle points to valid
     *      error log object
     */
    errlHndl_t _writeLPC(
        LPC::TransType i_type,
        uint32_t       i_addr,
        const void*    i_pBuffer,
        size_t&        io_buflen);

    /**
     *  @brief Read/write LPC space via XSCOM (non-MMIO!)
     *
     *  @par Detailed Description:
     *      Reads and writes to LPC space via XSCOM facility, as opposed to
     *      direct MMIO access.  API assumes class interfaces handle taking
     *      locks to guarantee atomicity.  On a timeout condition, the whole
     *      LPC complex needs to be reset to be used again, and that act will
     *      reset any potential FFDC sitting in LPC complex registers.
     *
     *  @param[in] i_read_notwrite Whether to read (0b1) or write (0b0) LPC
     *      space
     *  @param[in] i_type LPC transaction type
     *  @param[in] i_addr Address in LPC space to read or write
     *  @param[in/out] io_pBuffer Pointer to buffer to write data to LPC space
     *      (on write) or to read data from LPC space (on read).  Must not be
     *      nullptr (or API asserts).
     *  @param[in/out] io_buflen On input: amount of data to read or write, in
     *      bytes. Must be a power of two.  Must be > 0 bytes.  Must be <= 8
     *      bytes. Any violation of these conditions results in an assert.  On
     *      output: the amount of data read or written, in bytes.
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr LPC read/write succeeded
     *  @retval !nullptr LPC read/write failed; error log handle points to valid
     *      error log object
     */
    errlHndl_t _rwLPC(
        bool           i_read_notwrite,
        LPC::TransType i_type,
        uint32_t       i_addr,
        void*          io_pBuffer,
        size_t&        io_buflen);

    /**
     *  @brief Check for an OPB Master errors by examining the OPB Master
     *      Accumulated Status Register and reset LPC complex on severe errors
     *
     *  @param[in] i_useActual Check state of the OPB Master Actual Status
     *      register instead of the OPB Master Accumulated Status Register.
     *      Default is to use the OPB Master Accumulated Status Register.  The
     *      alternative is typically used to collect FFDC data when it's already
     *      likely that the OPB Master Accumulated Status Register is set.
     *
     *  @return errlHndl_t Error log handle
     *  @retval nullptr Successfully read OPB Master Accumulated Status Register
     *      and found no fault conditions
     *  @retval !nullptr Failed to read OPB Master Accumulated Status Register
     *      of found fault conditions.  Error log handle points to valid error
     *      log.
     */
    errlHndl_t checkAndHandleOpbmError(bool i_useActual=false);

    /**
     *  @brief Records the original LPC request FFDC into the provided error log
     *
     *  @param[in] i_readNotWrite Whether the request was for read (1) or write
     *       (0)
     *  @param[in] i_type LPC transaction type
     *  @param[in] i_addr LPC address
     *  @param[in] i_sizeBytes Size of LPC request in bytes
     *  @param[in/out] io_pError On input: reference to error log handle to
     *      append FFDC to (API asserts if nullptr).  On output: error log
     *      updated to contain the new FFDC data.
     */
    void addOriginalRequestToLog(
        bool           i_readNotWrite,
        LPC::TransType i_type,
        uint32_t       i_addr,
        size_t         i_sizeBytes,
        errlHndl_t&    io_pError) const;

    /**
     *  @brief Decodes an LPC transaction type to a string
     *
     *  @param[in] i_type LPC transaction type to decode
     *
     *  @return const char* String representation of LPC transaction type
     */
    const char* decodeLpcType(LPC::TransType i_type) const;

    // Map of LPC transaction types to string names
    static const std::map<LPC::TransType,const char*> cv_lpcTypeDecoder;

    // Array of LPC complex register addresses to save on failure
    static const std::array<uint32_t,48> cv_lpcErrRegAddrs;
};

#endif // __LPC_LPCXSCOM_H
