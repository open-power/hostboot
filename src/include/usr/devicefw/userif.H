/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devicefw/userif.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
/* [+] Google Inc.                                                        */
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
/** @file userif.H
 *  @brief Provides the user application interfaces for performing device
 *         access.
 *
 *  @note These interfaces should not be used directly by device drivers.
 *        Use driverif.H instead.
 */

#ifndef __DEVICEFW_USERIF
#define __DEVICEFW_USERIF

#ifndef PARSER
#include <stdint.h>
#include <errl/errlentry.H>
#include <vpd/vpd_if.H>
#include <targeting/common/targetservice.H>
#endif // not PARSER

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
        FSI,
        SPD,
        MVPD,
        CVPD,
        SCAN,
        EEPROM,
        GPIO,
        LPC,

        LAST_ACCESS_TYPE,
    };

#ifndef PARSER
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
     *      c=chip, a=address
     * @param[in] i_chip  Chip Select
     * @param[in] i_addr  Offset (from zero) into selected flash chip
     * @return  64-bit address to pass into PNOR device commands
     */
     #define DEVICE_PNOR_ADDRESS( i_chip, i_addr )  \
        DeviceFW::PNOR, ((static_cast<uint64_t>(i_chip)<<32)|static_cast<uint64_t>(i_addr))

    /** Construct the device addressing parameters for FSI device ops.
     *  @param[in] i_address - FSI address to operate on.
     */
    #define DEVICE_FSI_ADDRESS(i_address) \
        DeviceFW::FSI, static_cast<uint64_t>((i_address))

    /**
     * Construct the device addressing parameters for the SPD device ops.
     * @param[in] i_keyword - The keyword enumeration value to be accessed
     *      by the device driver.
     */
    #define DEVICE_SPD_ADDRESS( i_keyword )\
        DEVICE_SPD_FORCE_ADDRESS( i_keyword, VPD::AUTOSELECT )

    /**
     * Construct the device addressing parameters for the SPD device ops.
     * @param[in] i_keyword - The keyword enumeration value to be accessed
     *      by the device driver.
     * @param[in] i_location - The location to be used for
     *      accessing the keyword (PNOR/SEEPROM).
     */
    #define DEVICE_SPD_FORCE_ADDRESS( i_keyword, i_location )\
        DeviceFW::SPD, static_cast<uint64_t>(( i_keyword )),\
                       static_cast<uint64_t>(( i_location))

    /**
     * Construct the device addressing parameters for the MAILBOX device.
     * @param[out] o_status - Set with all available status bits
     *                        from MBOX::MboxReadStatus
     */
    #define DEVICE_MBOX_ADDRESS(o_status) \
        DeviceFW::MAILBOX, static_cast<uint64_t*>((o_status))

    /**
     * Construct the device addressing parameters for the MVPD device ops.
     * @param[in] i_record - The enumeration of the MVPD record to access.
     * @param[in] i_keyword - The enumeration of the MVPD keyword, located
     *      within the i_record Record to access.
     */
    #define DEVICE_MVPD_ADDRESS( i_record, i_keyword )\
        DEVICE_MVPD_FORCE_ADDRESS( i_record, i_keyword, VPD::AUTOSELECT )

    /**
     * Construct the device addressing parameters for the MVPD device ops.
     * @param[in] i_record - The enumeration of the MVPD record to access.
     * @param[in] i_keyword - The enumeration of the MVPD keyword, located
     *      within the i_record Record to access.
     * @param[in] i_location - The location of the data (PNOR/SEEPROM)
            see vpd_if.H
     */
    #define DEVICE_MVPD_FORCE_ADDRESS( i_record, i_keyword, i_location )\
        DeviceFW::MVPD, static_cast<uint64_t>(( i_record )),\
            static_cast<uint64_t>(( i_keyword )),\
            static_cast<uint64_t>(( i_location ))

    /**
     * Construct the device addressing parameters for the CVPD device ops.
     * @param[in] i_record - The enumeration of the CVPD record to access.
     * @param[in] i_keyword - The enumeration of the CVPD keyword, located
     *      within the i_record Record to access.
     */
    #define DEVICE_CVPD_ADDRESS( i_record, i_keyword )\
        DEVICE_CVPD_FORCE_ADDRESS( i_record, i_keyword, VPD::AUTOSELECT )

    /**
     * Construct the device addressing parameters for the CVPD device ops.
     * @param[in] i_record - The enumeration of the CVPD record to access.
     * @param[in] i_keyword - The enumeration of the CVPD keyword, located
     *      within the i_record Record to access.
     * @param[in] i_location - The location of the data (PNOR/SEEPROM)
            see vpd_if.H
     */
    #define DEVICE_CVPD_FORCE_ADDRESS( i_record, i_keyword, i_location )\
        DeviceFW::CVPD, static_cast<uint64_t>(( i_record )),\
            static_cast<uint64_t>(( i_keyword )),\
            static_cast<uint64_t>(( i_location ))

    /**
     * Construct the device addressing parameters for the SCAN device ops.
     * @param[in] i_ring - The ring address to scan 
     * @param[in] i_ringlen - The length of the ring to scan in bits
     *                 NOTE: This value is the scanring length must
     *                       match the scandef file value. 
     * @param[in] i_flag - Specific requests on the scan such as
     *             check the header, or set pulse option.
     *     Flag options are located in: src/include/usr/scan/scanif.H
     */
    #define DEVICE_SCAN_ADDRESS( i_ring, i_ringlen, i_flag )\
        DeviceFW::SCAN, static_cast<uint64_t>(( i_ring )),\
            static_cast<uint64_t>(( i_ringlen )),\
            static_cast<uint64_t>(( i_flag ))

    /**
     * Construct the device addressing parameters for the LPC device ops.
     * @param[in] i_trans_type - LPC transaction type.
     * @param[in] i_address - LPC address to operate on.
     *     Flag options are located in: src/include/usr/lpc/lpcif.H
     */
    #define DEVICE_LPC_ADDRESS( i_trans_type, i_address )\
        DeviceFW::LPC, static_cast<uint64_t>(( i_trans_type )),\
            static_cast<uint64_t>(( i_address ))


    /**
     * Construct the device addressing parameters for the EEPROM device ops.
     * @param[in] i_eeprom_enum - The chip number of the EEPROM to access. See
     *                            eeprom_chip_types_t in eepromif.H
     * @param[in] i_offset - The internal offset of the EEPROM slave device.
     */
    #define DEVICE_EEPROM_ADDRESS( i_eeprom_enum, i_offset )\
        DeviceFW::EEPROM, static_cast<uint64_t>(( i_eeprom_enum )),\
            static_cast<uint64_t>(( i_offset ))

    /**
     * Construct the device addressing paramters for the GPIO port extender ops
     * @param[in] i_gpio_num - The port extender device type.
     * @param[in] i_gpio_pin = The GPIO port address
     */
    #define DEVICE_GPIO_ADDRESS( i_device_type , i_gpio_portAddr) \
        DeviceFW::GPIO, static_cast<uint64_t>(( i_device_type )),\
            static_cast<uint64_t>(( i_gpio_portAddr ))

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
#endif // not PARSER

};


#endif
