/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromdd.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
/**
 * @file eepromdd.C
 *
 * @brief Implementation of the EEPROM device driver,
 *      which will access various EEPROMs within the
 *      system via the I2C device driver
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>     // errlHndl_t
#include <devicefw/driverif.H>  // DeviceFW::OperationTyp
                                // TARGETING::Target
                                // va_list
#include "eepromCache.H"
#include "eepromdd_hardware.H"

extern trace_desc_t* g_trac_eeprom;

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

namespace EEPROM
{

#ifdef CONFIG_SUPPORT_EEPROM_CACHING

/**
*
* @brief Determine if a given EEPROM has been cached into pnor's EECACHE
*        section yet or not. If it has source will be CACHE, if it has not
*        been cached yet, then source will be HARDWARE
*
*
* @param[in] i_target  - Target device associated with the eeprom.
*
* @param[in/out] io_i2cInfo - Struct containing information that tells us which
*                             EEPROM associated with the given Target we wish
*                             to lookup. NOTE it is assumed eepromRole member
*                             in this struct has been filled out prior to it
*                             being passed to this function.
*
* @pre i_i2cInfo.eepromRole is expected to have a valid value set
*
* @post o_source will either be EEPROM::CACHE or EEPROM::HARDWARE
*       io_i2cInfo will have info filled out (side effect not used)
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t resolveSource(TARGETING::Target * i_target,
                         eeprom_addr_t & io_i2cInfo,
                         EEPROM::EEPROM_SOURCE & o_source)
{
    eepromRecordHeader l_eepromRecordHeader;
    errlHndl_t err = nullptr;

    err = buildEepromRecordHeader(i_target,
                                  io_i2cInfo,
                                  l_eepromRecordHeader);
    // if lookupEepromAddr returns non-zero address
    // then we know it exists in cache somewhere
    if(lookupEepromAddr(l_eepromRecordHeader))
    {
        TRACDCOMP(g_trac_eeprom,"Eeprom found in cache, looking at eecache");
        o_source = EEPROM::CACHE;
    }
    else
    {
        TRACDCOMP(g_trac_eeprom,"Eeprom not found in cache, looking at hardware");
        o_source = EEPROM::HARDWARE;
    }

    return err;
}

#endif //  CONFIG_SUPPORT_EEPROM_CACHING

// ------------------------------------------------------------------
// eepromPerformOp
// ------------------------------------------------------------------
/**
*
* @brief Perform an EEPROM access operation.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target - Target device.
*
* @param[in/out] io_buffer
*       INPUT: Pointer to the data that will be  written to the target
*           device.
*       OUTPUT: Pointer to the data that was read from the target device.
*
* @param[in/out] io_buflen
*       INPUT: Length of the buffer to be written to target device.
*       OUTPUT: Length of buffer that was written, or length of buffer
*           to be read from target device.
*
* @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
*       usrif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.  This argument list consists of the chip number of
*       the EEPROM to access from the given I2C Master target and the
*       internal offset to use on the slave I2C device.
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t eepromPerformOp( DeviceFW::OperationType i_opType,
                            TARGETING::Target * i_target,
                            void * io_buffer,
                            size_t & io_buflen,
                            int64_t i_accessType,
                            va_list i_args )
{
    errlHndl_t err = nullptr;
    eeprom_addr_t i2cInfo;

    i2cInfo.eepromRole = va_arg( i_args, uint64_t );
    i2cInfo.offset     = va_arg( i_args, uint64_t );
    #ifdef CONFIG_SUPPORT_EEPROM_CACHING
    EEPROM_SOURCE l_source  = (EEPROM_SOURCE)va_arg(i_args, uint64_t);
    #endif
    TRACDCOMP( g_trac_eeprom,
               ENTER_MRK"eepromPerformOp()" );

    TRACUCOMP (g_trac_eeprom, ENTER_MRK"eepromPerformOp(): "
               "i_opType=%d, chip=%d, offset=%x, len=%d",
               (uint64_t) i_opType, i2cInfo.eepromRole, i2cInfo.offset, io_buflen);
    do{

        #ifdef CONFIG_SUPPORT_EEPROM_CACHING
        if(l_source == EEPROM::AUTOSELECT)
        {
            err = resolveSource(i_target, i2cInfo, l_source);
        }

        if(err)
        {
            TRACFCOMP( g_trac_eeprom,
                  "eepromPerformOp() An error occured trying to resolve what source to perform op on (CACHE or HARDWARE)");
            break;
        }

        if(l_source == EEPROM::CACHE  )
        {
            // Read the copy of the EEPROM data we have cached in PNOR
            err = eepromPerformOpCache(i_opType, i_target, io_buffer, io_buflen, i2cInfo);

            if(err)
            {
                break;
            }

            // If the operation is a write we also need to "write through" to HW after
            // we write cache
            if(i_opType == DeviceFW::WRITE)
            {
                err = eepromPerformOpHW(i_opType, i_target, io_buffer, io_buflen, i2cInfo);
            }
        }
        else if(l_source == EEPROM::HARDWARE)
        {
            // Read from the actual physical EEPROM device
            err = eepromPerformOpHW(i_opType, i_target, io_buffer, io_buflen, i2cInfo);
        }
        #else

        // Read from the actual physical EEPROM device
        err = eepromPerformOpHW(i_opType, i_target, io_buffer, io_buflen, i2cInfo);

        #endif // CONFIG_SUPPORT_EEPROM_CACHING


    }while(0);


    TRACDCOMP( g_trac_eeprom,
               EXIT_MRK"eepromPerformOp() - %s",
               ((NULL == err) ? "No Error" : "With Error") );

    return err;
} // end eepromPerformOp

// Register the perform Op with the routing code for Procs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_PROC,
                       eepromPerformOp );

// Register the perform Op with the routing code for DIMMs.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_DIMM,
                       eepromPerformOp );

// Register the perform Op with the routing code for Memory Buffers.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_MEMBUF,
                       eepromPerformOp );

// Register the perform Op with the routing code for Nodes.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_NODE,
                       eepromPerformOp );

// Register the perform Op with the routing code for MCS chiplets.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_MCS,
                       eepromPerformOp );

// Register the perform Op with the routing code for Open-Capi Memory Buffer Chips.
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::EEPROM,
                       TARGETING::TYPE_OCMB_CHIP,
                       eepromPerformOp );

} // end namespace EEPROM
