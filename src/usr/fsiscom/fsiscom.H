//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/fsiscom/fsiscom.H $
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
#ifndef __FSISCOM_H
#define __FSISCOM_H

/** @file  fsiscom.H
 *  @brief Provides the interfaces to perform a FSI SCOM
 */

namespace FSISCOM
{

  enum {
    //FSI addresses are byte offsets, so need to multiply by 4 since each register is 4 bytes long.
    //prefix with 0x10xx for engine offset
    DATA0_REG   = 0x1000,  /* SCOM Data Register 0 (0x00) */
    DATA1_REG   = 0x1004,  /* SCOM Data Register 1 (0x01) */
    COMMAND_REG = 0x1008,  /* SCOM Command Register (0x02) */
    STATUS_REG  = 0x101C,  /* STATUS Register (0x07) */
  };

/**
 * @brief Performs an FSI SCOM operation
 * This function performs an SCom Read/Write operation. It follows a
 * pre-defined prototype functions in order to be registered with the
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        SCom target
 * @param[in/out] io_buffer     Read: pointer to output data storage
 *                              Write: pointer to data to be written
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output: Read: size of output data
 *                                      Write: size of data written
 * @param[in]   i_accessType    Select from DeviceFW::AccessType enum
 *                              (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the SCom address value.
 *
 * @return  errlHndl_t
 */
errlHndl_t fsiScomPerformOp(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args);






}; // End namespace

#endif
