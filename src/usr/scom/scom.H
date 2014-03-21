/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/scom.H $                                         */
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
#ifndef __SCOM_H
#define __SCOM_H

#include <devicefw/driverif.H>

/** @file  scom.H
 *  @brief Provides the interfaces to perform a SCom
 */

namespace SCOM
{
/**
 * @brief Indirect SCOM Status
 */
union IndirectScom_t
{
    uint64_t data64;
    struct
    {
        uint64_t :12;        //0:11
        uint64_t addr:20;    //12:31
        uint64_t done:1;     //32
        uint64_t piberr:3;   //33:35
        uint64_t userstat:4; //36:39
        uint64_t :8;         //40:47
        uint64_t data:16;    //48:63
    };
};
enum ScomErrorMask
{
    // checkf for complete bit .. bit 32
    SCOM_IND_COMPLETE_MASK = 0x0000000080000000,
    //check for bits 33-35
    SCOM_IND_ERROR_MASK =    0x0000000070000000
};



/**
 * @brief Performs a SCom operation
 * This function performs a SCOM operation by calling
 * checkIndirectScomOP.  It handles whether the address
 * a regular or an indirect SCOM address
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
 *                              @see usr/devicefw/(userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the SCom address value.
 *
 * @return  errlHndl_t
 */
errlHndl_t scomPerformOp(DeviceFW::OperationType i_opType,
                         TARGETING::Target* i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args);

/**
 * @brief Performs a SCom operation on a target TYPE_MEMBUF
 * This function performs a SCOM operation by calling
 * checkIndirectScomOP.  It handles whether the address
 * a regular or an indirect SCOM address
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
 *                              @see usr/devicefw/(userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the SCom address value.
 *
 * @return  errlHndl_t
 */
errlHndl_t scomMemBufPerformOp(DeviceFW::OperationType i_opType,
                               TARGETING::Target* i_target,
                               void* io_buffer,
                               size_t& io_buflen,
                               int64_t i_accessType,
                               va_list i_args);


/**
 * @brief Performs a SCom operation
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
 *                              @see usr/devicefw/userif.H
 * @param[in]   i_addr         scom Address Value
 *
 * @return  errlHndl_t
 */
errlHndl_t doScomOp(DeviceFW::OperationType i_opType,
                    TARGETING::Target* i_target,
                    void* io_buffer,
                    size_t& io_buflen,
                    int64_t i_accessType,
                    uint64_t i_addr);


/**
 * @brief Performs a SCom operation
 * This function performs a SCOM operation by calling doScomOP after
 * It handles whether the address is  a regular or an indirect SCOM
 * address
 *
 * @param[in]   i_opType        Operation type
 * @param[in]   i_target        SCom target
 * @param[in/out] io_buffer     Read: pointer to output data storage
 *                              Write: pointer to data to be written
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output: Read: size of output data
 *                                      Write: size of data written
 * @param[in]   i_accessType    Select from DeviceFW::AccessType enum
 *                              @see usr/devicefw/userif.H
 * @param[in]   i_addr          Scom Address Value.
 *
 * @return  errlHndl_t
 */
errlHndl_t checkIndirectAndDoScom(DeviceFW::OperationType i_opType,
                                  TARGETING::Target* i_target,
                                  void* io_buffer,
                                  size_t& io_buflen,
                                  int64_t i_accessType,
                                  uint64_t i_addr);


}; // End namespace

#endif
