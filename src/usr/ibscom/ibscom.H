/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ibscom/ibscom.H $                                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
#ifndef __IBSCOM_H
#define __IBSCOM_H

/** @file ibscom.H
 *  @brief Provides the interfaces to perform IBSCOM
 */

#include <stdint.h>

/**
 *  @brief  Type definition for IBSCOM address
 */
typedef uint64_t IBScomBase_t;

namespace IBSCOM
{

const size_t  IBSCOM_BUFFER_SIZE = 8;   // 8 bytes

/**
 * @brief Performs an inband scom access operation
 * This function performs an inband scom access operation. It follows a 
 * pre-defined prototype functions in order to be registered with the 
 * device-driver framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        inband scom target
 * @param[in] io_buffer      Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in] i_args            This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the MMIO inband scom address
 * @return  errlHndl_t
 */
errlHndl_t ibscomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args);



};


#endif
