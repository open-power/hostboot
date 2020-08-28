/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devicefw/userif.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
     *
     *  NOTE: Any changes to the values must be reflected in the function
     *  ErrlUserDetailsParserLogRegister located in src/usr/errl/plugins/ebmc/b0100.py
     */

    enum AccessType
    {
        SCOM = 0,     // SCOM registers
        PNOR,         // PNOR flash
        MAILBOX,      // FSP mailbox
        PRESENT,      // Presence detection
        FSI,          // FSI/CFAM registers
        SPD,          // Serial Presence Detect Data for JEDEC DIMMs
        MVPD,         // Module (processor) VPD
        SCAN,         // Scan rings
        EEPROM,       // Standard EEPROM/SEEPROM over i2c
        GPIO,         // GPIO registers
        LPC,          // Low Pin Count bus
        IPMIBT,       // As opposed to other phy's
        PVPD,         // Planar VPD
        TPM,          // Trusted Platform Module
        SIO,          // BMC Super I/O registers
        AHB_SIO,      // AST Hostbridge via SIO
        DVPD,         // Direct access memory VPD
        NODECOMM,     // Internode communication
        NVDIMM,       // Non-volatile DIMM controller access
        FAPI_I2C,     // FAPI2-triggered i2c accesses
        MMIO,         // Memory Mapped I/O
        IDEC,         // Read and set EC and CHIPID values
        EEPROM_CACHE, // Read EEPROM over I2C and write to PNOR
        LAST_ACCESS_TYPE,
    };

#ifndef PARSER

    /** Single argument version of the macro to provide the correct information
    *   to perform a scomRead or scomWrite. Takes in a scom address
    *
    *  @param[in] i_address - scom address that you are writing to or reading from
    */
    #define DEVICE_SCOM_ADDRESS_1_ARGS(i_address)\
        DeviceFW::SCOM, static_cast<uint64_t>((i_address)), static_cast<uint64_t>(0)

    /** 2 argument version of the macro to provide the correct information to
    *  preform a scomRead or scomWrite. Takes in a scom address and an opmode
    *
    *  @param[in] i_address - scom addr that you are writing to or reading from
    *  @param[in] i_opMode -  fapi2 opMode used by HWPs to conduct scoms in a
    *                         certain way
    */
    #define DEVICE_SCOM_ADDRESS_2_ARGS(i_address, i_opMode)\
        DeviceFW::SCOM, static_cast<uint64_t>((i_address)), static_cast<uint64_t>(i_opMode)

    /** This is the trick to figuring out if the second argument is there or not
    *   by using this in conjunction with __VA_ARGS__ , which has variable length
    *   you can select the appropriate macro for the number of arguments present
    *
    *  @param[in] arg1 - __VA_ARGS__ that you are trying to determine size of
    *  @param[in] arg2 - 2 argument version of macro
    *  @param[in] arg1 - 1 argument version of macro
    */
    #define GET_3RD_ARG(arg1, arg2, arg3, ...) arg3

    /** This is the implementation GET_3RD_ARG macro that selects either
    *   the 1 argument macro for scom address that only takes an addressing
    *   or else use the 2 arg macro that takes in an address as well as an opmode
    *
    *  @param[in] _VA_ARGS__ - __VA_ARGS__ that you are trying to determine size of
    */
    #define DEVICE_SCOM_ADDRESS_MACRO_CHOOSER(...) \
        GET_3RD_ARG(__VA_ARGS__,  DEVICE_SCOM_ADDRESS_2_ARGS, DEVICE_SCOM_ADDRESS_1_ARGS )

    /** Construct the device addressing parameters for SCOM device ops.
    *  @param[in] i_address - Scom address to operate on.
    */
    #define DEVICE_SCOM_ADDRESS(...) DEVICE_SCOM_ADDRESS_MACRO_CHOOSER(__VA_ARGS__)(__VA_ARGS__)

    /** Construct the device addressing parameters for the PRESENT device ops.
    */
    #define DEVICE_PRESENT_ADDRESS() \
        DeviceFW::PRESENT

    /** Construct the device addressing parameters for the EEPROM_CACHE device ops.
    *  @param[in] i_present indicates if target is present or not.
    *  @param[in] i_eepromType indicates which EEPROM we wish to cache (PRIMARY/BACKUP etc)
    */
    #define DEVICE_CACHE_EEPROM_ADDRESS(i_present, i_eepromType) \
        DeviceFW::EEPROM_CACHE, static_cast<uint64_t>((i_present)), static_cast<uint64_t>((i_eepromType))

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

    /** Construct the device addressing parameters for FSI device ops
     *   using the more common CFAM address format : EEEE.EEEA.AAAA.AAAA.
     *   E=Engine, A=Address in 4-byte words
     *  @param[in] i_address - CFAM address to operate on.
     */
    #define DEVICE_CFAM_ADDRESS(i_address) \
        DeviceFW::FSI, static_cast<uint64_t>((i_address & 0xFE00) | ((i_address & 0x01FF)*4) )

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
     * Construct the device addressing parameters for the PVPD device ops.
     * @param[in] i_record - The enumeration of the PVPD record to access.
     * @param[in] i_keyword - The enumeration of the PVPD keyword, located
     *      within the i_record Record to access.
     */
    #define DEVICE_PVPD_ADDRESS( i_record, i_keyword )\
        DEVICE_PVPD_FORCE_ADDRESS( i_record, i_keyword, VPD::AUTOSELECT )

    /**
     * Construct the device addressing parameters for the PVPD device ops.
     * @param[in] i_record - The enumeration of the PVPD record to access.
     * @param[in] i_keyword - The enumeration of the PVPD keyword, located
     *      within the i_record Record to access.
     * @param[in] i_location - The location of the data (PNOR/SEEPROM)
            see vpd_if.H
     */
    #define DEVICE_PVPD_FORCE_ADDRESS( i_record, i_keyword, i_location )\
        DeviceFW::PVPD, static_cast<uint64_t>(( i_record )),\
            static_cast<uint64_t>(( i_keyword )),\
            static_cast<uint64_t>(( i_location ))

    /**
     * Construct the device addressing parameters for the DVPD (Direct access
     * memory VPD) device ops.
     * @param[in] i_record - The enumeration of the DVPD record to access.
     * @param[in] i_keyword - The enumeration of the DVPD keyword, located
     *      within the i_record Record to access.
     */
    #define DEVICE_DVPD_ADDRESS( i_record, i_keyword )\
        DEVICE_DVPD_FORCE_ADDRESS( i_record, i_keyword, VPD::AUTOSELECT )

    /**
     * Construct the device addressing parameters for the DVPD device ops.
     * @param[in] i_record - The enumeration of the DVPD record to access.
     * @param[in] i_keyword - The enumeration of the DVPD keyword, located
     *      within the i_record Record to access.
     * @param[in] i_location - The location of the data (PNOR/SEEPROM)
            see vpd_if.H
     */
    #define DEVICE_DVPD_FORCE_ADDRESS( i_record, i_keyword, i_location )\
        DeviceFW::DVPD, static_cast<uint64_t>(( i_record )),\
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
        * Construct the device addressing parameters for the SCAN device ops.
        * @param[in] i_ringID   - ring ID
        * @param[in] i_ringMode - Ring Mode
        *
        * @param[in] i_flag    - flags
        * PUT_RING_FROM_IMAGE_COMMAND - is for Put Ring from Image command
        */

       #define PUT_RING_FROM_IMAGE_COMMAND (0xFFFFFFFFFFFFFFFF)
       #define DEVICE_SCAN_SBE_ADDRESS( i_ringID, i_ringMode, i_flag )\
           DeviceFW::SCAN, static_cast<uint64_t>(( i_ringID )),\
               static_cast<uint64_t>(( i_ringMode )),\
               static_cast<uint64_t>(( i_flag )),\
               static_cast<uint64_t>(PUT_RING_FROM_IMAGE_COMMAND)

    /**
     * Construct the device addressing parameters for the LPC device ops.
     * @param[in] i_trans_type - LPC transaction type.
     * @param[in] i_address - LPC address to operate on.
     *     Flag options are located in: src/include/usr/lpc/lpcif.H
     *
     */
    #define DEVICE_LPC_ADDRESS( i_trans_type, i_address )\
        DeviceFW::LPC, static_cast<uint64_t>(( i_trans_type )),\
            static_cast<uint64_t>(( i_address ))

    /**
     * Construct the device addressing parameters for the SIO device ops.
     * @param[i] i_device - SIO device to operate on
     * @param[i] i_address - SIO address to operate on
     */
    #define DEVICE_SIO_ADDRESS(i_device, i_address)\
        DeviceFW::SIO, static_cast<uint64_t>((i_device)),\
            static_cast<uint64_t>((i_address))

    /**
     * Construct the device addressing parameters for the AHB_SIO device ops.
     * @param[i] i_address - AHB_SIO address to operate on
     */
    #define DEVICE_AHB_SIO_ADDRESS(i_address)\
        DeviceFW::AHB_SIO, static_cast<uint64_t>((i_address))

    /**
     * Construct the device addressing parameters for the EEPROM device ops.
     * @param[in] i_eeprom_enum - The chip number of the EEPROM to access. See
     *                            EEPROM_ROLE in eeprom_const.H
     * @param[in] i_offset - The internal offset of the EEPROM slave device.
     * @param[in] i_deviceSelect - Choose which device you want to perform op on:
     *                             AUTOSELECT , CACHE, or HARDWARE
     */
    #define DEVICE_EEPROM_ADDRESS( i_eeprom_enum, i_offset, i_deviceSelect )\
        DeviceFW::EEPROM, static_cast<uint64_t>(( i_eeprom_enum )),\
            static_cast<uint64_t>(( i_offset )), static_cast<uint64_t>((i_deviceSelect))

    /**
     * Construct the device addressing parameters for the TPM device ops.
     * @param[in] i_tpm_operation The TPM operation to perform. See
     *                            tpm_op_types_t in tpmddif.H
     * @param[in] i_command_len Command length to write during transmit
     *                            operations
     * @param[in] i_locality The TPM locality to use. See tpm_locality_t
     *                            in tpmddif.H
     */
    #define DEVICE_TPM_ADDRESS( i_tpm_op, i_command_len, i_locality )  \
        DeviceFW::TPM,\
            static_cast<uint64_t>(( i_tpm_op )),\
            static_cast<uint64_t>(( i_command_len )),\
            static_cast<uint64_t>(( i_locality ))

    /**
     * Construct the device addressing parameters for the GPIO port extender ops
     * @param[in] i_gpio_num - The port extender device type.
     * @param[in] i_gpio_pin = The GPIO port address
     */
    #define DEVICE_GPIO_ADDRESS( i_device_type , i_gpio_portAddr) \
        DeviceFW::GPIO, static_cast<uint64_t>(( i_device_type )),\
            static_cast<uint64_t>(( i_gpio_portAddr ))

    /**
     * Construct the device addressing parameters for the Node Comm device ops.
     * @param[in] i_link_id     The Link Id used for routing the message.
     *                          MAX value is defined in nodecommif.H.
     * @param[in] i_mailbox_id  Tha Mailbox Id used for routing the message.
     *                          NOTE: Only "0" or "1" are supported.
     *
     * @note      This interface only supports the reading and writing of
     *            8 bytes (64 bits) per operation. Anything else will fail.
     */
    #define DEVICE_NODECOMM_ADDRESS( i_link_id, i_mailbox_id )  \
        DeviceFW::NODECOMM,\
            static_cast<uint64_t>(( i_link_id )),\
            static_cast<uint64_t>(( i_mailbox_id ))

    /**
     * Construct the device addressing parameters for the NVDIMM device ops.
     * @param[i] i_address - NVDIMM address to internal register
     */
    #define DEVICE_NVDIMM_ADDRESS(i_address)\
        DeviceFW::NVDIMM, static_cast<uint64_t>((i_address))


    /**
     * Construct the device addressing parameters for the FAPI I2C operation
     * with an initial configuration needed
     *
     * @param[in] i_cfg_buf_size - cfg buffer size
     * @param[in] i_cfg_buf - buffer that holds data to write to the HW target.
     */
    #define DEVICE_FAPI_I2C_ADDRESS_WCONFIG(i_cfg_buf_size,  i_cfg_buf) \
        DeviceFW::FAPI_I2C,\
          static_cast<size_t>(( i_cfg_buf_size )),\
          static_cast<uint8_t*>(( i_cfg_buf ))

    /**
     * Construct the device addressing parameters for the FAPI I2C operation
     */
    #define DEVICE_FAPI_I2C_ADDRESS()\
        DEVICE_FAPI_I2C_ADDRESS_WCONFIG( 0, NULL )

    /**
     * @brief Additional device addressing parameters for MMIO ops.
     *  @param[in] i_offset      - offset (bytes) into the device
     *  @param[in] i_accessLimit - number of bytes to read/write at a
     *                             time (device limitation)
     */
    #define DEVICE_MMIO_ADDRESS(i_offset, i_accessLimit) \
        DeviceFW::MMIO, \
        static_cast<uint64_t>((i_offset)), \
        static_cast<uint64_t>((i_accessLimit))

    /**
     * @brief Additional device addressing parameters for MMIO ops.
     * Construct the device addressing parameters for the IDEC operation
     *  (no parameters)
     */
    #define DEVICE_IDEC_ADDRESS()\
        DeviceFW::IDEC

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
     *  @return Non-NULL - An error handle when error has occurred, typically
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
     *  @return Non-NULL - An error handle when error has occurred, typically
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
