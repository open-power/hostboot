#ifndef __SCOM_H
#define __SCOM_H

/** @file  scom.H
 *  @brief Provides the interfaces to perform a SCom
 */

namespace SCOM
{

/**
 * @brief Performs an SCom operation
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
errlHndl_t scomPerformOp(DeviceFW::OperationType i_opType,
                         DeviceFW::TargetHandle_t i_target,
                         void* io_buffer,
                         size_t& io_buflen,
                         int64_t i_accessType,
                         va_list i_args);
}; // End namespace

#endif
