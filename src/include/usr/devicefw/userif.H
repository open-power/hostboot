/** @file userif.H
 *  @brief Provides the user application interfaces for performing device 
 *         access.  
 *
 *  @note These interfaces should not be used directly by device drivers.
 *        Use driverif.H instead.
 */

#ifndef __DEVICEFW_USERIF
#define __DEVICEFW_USERIF

#include <stdint.h>
#include <errl/errltypes.H>
#include <targeting/targetservice.H>

namespace DeviceFW
{
    /** @enum AccessType
     *  @brief Access types for accessing a hardware device.
     */
    enum AccessType
    {
        SCOM = 0,
        PNOR,
        MAILBOX,
        PRESENT,

        LAST_ACCESS_TYPE,
    };
    
    /** Construct the device addressing parameters for SCOM device ops. 
     *  @param[in] i_address - Scom address to operate on.
     */
    #define DEVICE_SCOM_ADDRESS(i_address) \
        DeviceFW::SCOM, static_cast<uint64_t>((i_address))
    
    /** Construct the device addressing parameters for the PRESENT device ops.
     */
    #define DEVICE_PRESENT_ADDRESS() \
        DeviceFW::PRESENT

    /**
     * Construct a PNOR DD address
     *    address = 0000_0000_0000_000c_aaaa_aaaa_aaaa_aaaa
     *      c=side, a=address
     * @param[in] chip  Chip Select
     * @param[in] addr  Offset (from zero) into selected flash chip
     * @return  64-bit address to pass into PNOR device commands
     */
     #define DEVICE_PNOR_ADDRESS( chip, addr )  \
        DeviceFW::PNOR, (((chip)<<32)|(addr))
    

    /** 
     *  @brief Perform a hardware read operation.
     *
     *  @param[in]     i_target     Device target to operate on.
     *  @param[out]    o_buffer     Buffer to put result data into.
     *  @param[in,out] io_buflen    Length of the buffer on input, length of
     *                              data on output (in bytes).
     *  @param[in]     i_accessType Operation to perform on target.
     *  @param[in]     ...          Operation specific addressing parameters.
     *
     *  @return NULL - No error.
     *  @return Non-NULL - An error handle when error has occured, typically
     *                     passed directly from device driver but potentially
     *                     created by the device framework as in the case of
     *                     not finding an installed driver for the desired
     *                     operation.
     *
     *  It is expected that the callers will use operation specific macros to
     *  assist in the AccessType parameter and variable arguments.
     *
     *  <PRE>
     *  Example usage:
     *      errl = deviceRead(chip, buf, bufsize, DEVICE_SCOM_ADDRESS(0x42));
     *  </PRE>
     *
     */
    errlHndl_t deviceRead(TARGETING::Target* i_target, 
                          void* o_buffer, size_t& io_buflen,
                          AccessType i_accessType, ...);

    /** 
     *  @brief Perform a hardware write operation.
     *
     *  @param[in]     i_target     Device target to operate on.
     *  @param[in]     i_buffer     Buffer to get write data from.
     *  @param[in,out] io_buflen    Length of the buffer on input, length of
     *                              data on output (in bytes).
     *  @param[in]     i_accessType Operation to perform on target.
     *  @param[in]     ...          Operation specific addressing parameters.
     *
     *  @return NULL - No error.
     *  @return Non-NULL - An error handle when error has occured, typically
     *                     passed directly from device driver but potentially
     *                     created by the device framework as in the case of
     *                     not finding an installed driver for the desired
     *                     operation.
     *
     *  It is expected that the callers will use operation specific macros to
     *  assist in the AccessType parameter and variable arguments.
     *
     *  <PRE>
     *  Example usage:
     *      errl = deviceWrite(chip, buf, bufsize, DEVICE_SCOM_ADDRESS(0x42));
     *  </PRE>
     *
     */
    errlHndl_t deviceWrite(TARGETING::Target* i_target,
                           void* i_buffer, size_t& io_buflen,
                           AccessType i_accessType, ...);

};


#endif
