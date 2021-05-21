/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludlogregister.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
 *  @file errludlogregister.C
 *
 *  @brief Implementation of ErrlUserDetailsLogRegister
 */
#include <errl/errludlogregister.H>
#include <errl/errlreasoncodes.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/util.H>
#include <targeting/common/trace.H>

#include <devicefw/driverif.H>

namespace ERRORLOG
{

using namespace TARGETING;
using namespace DeviceFW;

extern TARG_TD_t g_trac_errl;

// internal function:
void ErrlUserDetailsLogRegister::setStateLogHUID()
{
    // Set up ErrlUserDetails instance variables
    iv_CompId = ERRL_COMP_ID;
    iv_Version = 1;
    iv_SubSection = ERRL_UDT_LOGREGISTER;

    // override the default of false.
    iv_merge = true;

    // write the HUID of the target into the error log buffer
    // @todo RTC 108241 - improve workaround for MASTER_..._SENTINEL
    uint32_t attrHuid = 0;
    if( iv_pTarget == NULL ) {
        attrHuid = 0x0;
    } else if( iv_pTarget == MASTER_PROCESSOR_CHIP_TARGET_SENTINEL ) {
        attrHuid = 0xFFFFFFFF;
    } else {
        attrHuid = get_huid(iv_pTarget);
    }
    uint8_t *pBuf = reinterpret_cast<uint8_t *>
            (reallocUsrBuf(sizeof(uint32_t) + sizeof(uint8_t)));
    memcpy(pBuf, &attrHuid, sizeof(uint32_t));
    iv_dataSize += sizeof(uint32_t);

    // add space for the count and initialize to 0
#define REGISTER_COUNT_OFFSET (sizeof(uint32_t))
    *(pBuf + REGISTER_COUNT_OFFSET) = 0;
    iv_dataSize += sizeof(uint8_t);

} // setStateLogHUID

// internal function:
void ErrlUserDetailsLogRegister::writeRegisterData(
    void *i_dataBuf, size_t i_dataSize,
    int32_t i_numAddressArgs,
    uint8_t i_accessType, va_list i_args)
{

    uint64_t regParam[i_numAddressArgs];
    for (int32_t i = 0;i < i_numAddressArgs;i++)
    {
        regParam[i] = va_arg(i_args, uint64_t);
    } // for

    // write the data into the buffer; format is:
    // i_accessType, regParam[i], uint8_t(i_dataSize), i_dataBuf
    uint32_t newSize = sizeof(i_accessType) +
                        sizeof(regParam) +
                        sizeof(uint8_t) +
                        i_dataSize;

    uint8_t *pBuf;
    pBuf = reinterpret_cast<uint8_t *>(reallocUsrBuf(iv_dataSize + newSize));
    memcpy(pBuf + iv_dataSize, &i_accessType, sizeof(i_accessType) );
    iv_dataSize += sizeof(i_accessType);
    for (int32_t i = 0;i < i_numAddressArgs;i++)
    {
        memcpy(pBuf + iv_dataSize, &regParam[i], sizeof(regParam[i]) );
        iv_dataSize += sizeof(regParam[i]);
    } // for
    uint8_t regSize = (uint8_t)i_dataSize;
    memcpy(pBuf + iv_dataSize, &regSize, sizeof(regSize) );
    iv_dataSize += sizeof(regSize);
    if (i_dataSize > 0)
    {
        memcpy(pBuf + iv_dataSize, i_dataBuf, i_dataSize);
        iv_dataSize += i_dataSize;
    }

    // increment the count
    *(pBuf + REGISTER_COUNT_OFFSET) += 1;

} // writeRegisterData

// internal function:
void ErrlUserDetailsLogRegister::readRegister(
    uint8_t i_accessType, va_list i_args)
{
    // we allow 0 in case there is some future type that has no parameter.
    //  (DeviceFW::PRESENT is an example, but we chose not to log that type)
    int32_t numAddressArgs = -1;

    // do we do the deviceOpValist or not, and how many
    //  parameters are there to be logged
    switch (i_accessType)
    {
        // one parameter
        case DeviceFW::SCOM:        // userif.H
        case DeviceFW::FSI:         // userif.H
        case DeviceFW::SPD:         // userif.H
        case DeviceFW::XSCOM:       // driverif.H
        case DeviceFW::FSISCOM:     // driverif.H
        case DeviceFW::IBSCOM:      // driverif.H
        {
            numAddressArgs = 1;
            break;
        }
        // two parameters
        case DeviceFW::MVPD:        // userif.H
        case DeviceFW::EEPROM:      // driverif.H
        case DeviceFW::LPC:         // userif.H
        {
            numAddressArgs = 2;
            break;
        }
        // three parameters
        case DeviceFW::I2C:         // driverif.H
        {
            numAddressArgs = 3;
            break;
        }
        // not logged!
        case DeviceFW::PRESENT:     // userif.H
        case DeviceFW::PNOR:        // userif.H
        case DeviceFW::MAILBOX:     // userif.H
        default:
        {   // no action - not logged
            TRACFCOMP(g_trac_errl, "LogRegister: AccessType %x not logged",
                i_accessType);
            break;
        } // default
    } // switch i_accessType

    if (numAddressArgs != -1)
    {
        // place for register data to go, and (max) size we expect.
        uint64_t reg_data = 0;
        size_t reg_size = sizeof(reg_data);

        if ( i_accessType == DeviceFW::FSI)
        {
            reg_size = sizeof(uint32_t);
        }

        TRACDCOMP(g_trac_errl, "LogRegister: deviceOpValist()");
        errlHndl_t errl;
        errl = DeviceFW::deviceOpValist(DeviceFW::READ,
                    const_cast<TARGETING::Target *>(iv_pTarget),
                    &reg_data, reg_size,
                    (DeviceFW::AccessType) i_accessType, i_args);

        if (unlikely(errl != nullptr))
        {   // error!
            TRACFCOMP(g_trac_errl, "LogRegister: deviceOpValist type %d"
                        " threw errl! deleting errl.",
                        i_accessType);
            delete errl; // eat the error - just delete it
            errl = nullptr;

            // nothing gets written out
        }
        else
        {
            // internal worker function to put reg data into the log
            writeRegisterData(&reg_data, reg_size, numAddressArgs,
                    i_accessType, i_args);
            TRACDCOMP(g_trac_errl, "LogRegister: iv_dataSize %d", iv_dataSize);
        }
    }
    // else: nothing gets written out
} // readRegister

// internal function:
void ErrlUserDetailsLogRegister::copyRegisterData(
    void *i_dataBuf, size_t i_dataSize,
    uint8_t i_accessType, va_list i_args)
{
    // we allow 0 in case there is some future type that has no parameter.
    //  (DeviceFW::PRESENT is an example, but we chose not to log that type)
    int32_t numAddressArgs = -1;

    // do we do the writeRegisterData or not, and how many
    //  parameters are there to be logged
    switch (i_accessType)
    {
        // one parameter
        case DeviceFW::SCOM:        // userif.H
        case DeviceFW::FSI:         // userif.H
        case DeviceFW::SPD:         // userif.H
        case DeviceFW::XSCOM:       // driverif.H
        case DeviceFW::FSISCOM:     // driverif.H
        case DeviceFW::IBSCOM:      // driverif.H
        {
            numAddressArgs = 1;
            break;
        }
        // two parameters
        case DeviceFW::MVPD:        // userif.H
        case DeviceFW::EEPROM:      // driverif.H
        case DeviceFW::LPC:         // userif.H
        {
            numAddressArgs = 2;
            break;
        }
        // three parameters
        case DeviceFW::I2C:         // driverif.H
        {
            numAddressArgs = 3;
            break;
        }
        // not logged!
        case DeviceFW::PRESENT:     // userif.H
        case DeviceFW::PNOR:        // userif.H
        case DeviceFW::MAILBOX:     // userif.H
        case DeviceFW::SPI_EEPROM:  // driverif.H
        case DeviceFW::SPI_TPM:     // driverif.H
        default:
        {   // no action - not logged
            TRACFCOMP(g_trac_errl, "LogRegister: AccessType %x not logged",
                i_accessType);
            break;
        } // default
    } // switch i_accessType

    if (numAddressArgs != -1)
    {
        // internal worker function to put reg data into the log
        writeRegisterData(i_dataBuf, i_dataSize, numAddressArgs,
                i_accessType, i_args);
        TRACDCOMP(g_trac_errl, "LogRegister: iv_dataSize %d", iv_dataSize);
    }
    // else: nothing gets written out
} // copyRegisterData

//------------------------------------------------------------------------------
/*
 * The public addData() function are templates allowing i_accesstype to change:
 *  either the DeviceFW::AccessType values in devicefw/userif.H
 *  OR the DeviceFW::AccessType_DriverOnly values in devicefw/driverif.H
 *  We don't want to include driverif.H in the errludlogregister.H file, so
 *  we do the template.
 *
 *  We don't want/need to include a different separate addData() for each of
 *  those instances tho, so we create one __addData() function, and then use
 *  this alias to have both public template functions point to this function.
 *
 *  This function will call the readRegister() function to log and do the read.
 */

// This extension will silence warnings relating to the mis-match of argument
// types used in the various aliases created in this document.

// The following flag is only available in GCC 8
#if __GNUC__ >= 8
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattribute-alias"
#endif

template <>
void ErrlUserDetailsLogRegister::addData<>(
    DeviceFW::AccessType i_accessType, ...)
__attribute__((alias("_ZN8ERRORLOG26ErrlUserDetailsLogRegister9__addDataEhz")));
template <>
void ErrlUserDetailsLogRegister::addData<>(
    DeviceFW::AccessType_DriverOnly i_accessType, ...)
__attribute__((alias("_ZN8ERRORLOG26ErrlUserDetailsLogRegister9__addDataEhz")));

void ErrlUserDetailsLogRegister::__addData(
    uint8_t i_accessType, ...)
{
    static_assert(LAST_DRIVER_ACCESS_TYPE <= UINT8_MAX,
        "Logic violation, LAST_DRIVER_ACCESS_TYPE is greater than UINT8_MAX.");

    TRACDCOMP(g_trac_errl, "LogRegister::addData: type %x",
        i_accessType);

    // get the data - do the read
    va_list args;
    va_start(args, i_accessType);
    readRegister(i_accessType, args);
    va_end(args);

} // __addData

/*
 * Same as above with regards to templates and alias.
 *
 * This function will just store the passed-in data, unless it's NULL.
 */
template <>
void ErrlUserDetailsLogRegister::addDataBuffer<>(
    void *i_dataBuf, size_t i_dataSize,
    DeviceFW::AccessType i_accessType, ...)
__attribute__((alias("_ZN8ERRORLOG26ErrlUserDetailsLogRegister15__addDataBufferEPvmhz")));
template <>
void ErrlUserDetailsLogRegister::addDataBuffer<>(
    void *i_dataBuf, size_t i_dataSize,
    DeviceFW::AccessType_DriverOnly i_accessType, ...)
__attribute__((alias("_ZN8ERRORLOG26ErrlUserDetailsLogRegister15__addDataBufferEPvmhz")));

#if __GNUC__ >= 8
#pragma GCC diagnostic pop
#endif // ignoring -Wattribute-alias in GCC 8

void ErrlUserDetailsLogRegister::__addDataBuffer(
    void *i_dataBuf, size_t i_dataSize,
    uint8_t i_accessType, ...)
{
    TRACDCOMP(g_trac_errl, "LogRegister::addDataBuffer: type %x from %p size %d",
        i_accessType, i_dataBuf, i_dataSize);

    // if there's data, just copy it thru.
    if (i_dataBuf != NULL)
    {
        // get the data - do the copy
        va_list args;
        va_start(args, i_accessType);
        copyRegisterData(i_dataBuf, i_dataSize, i_accessType, args);
        va_end(args);
    }
    else
    {   // user didn't give us any data -
        // get the data ourselves - do the read
        va_list args;
        va_start(args, i_accessType);
        readRegister(i_accessType, args);
        va_end(args);
    }
} // __addDataBuffer


//------------------------------------------------------------------------------
ErrlUserDetailsLogRegister::ErrlUserDetailsLogRegister(
    const TARGETING::Target * i_pTarget)
    : iv_pTarget(i_pTarget), iv_dataSize(0)
{
    TRACDCOMP(g_trac_errl, "LogRegister: target %p",
        i_pTarget);

    setStateLogHUID();

    // done - user will have to do addData() or addDataBuffer() calls.
} // ctor with target only

//------------------------------------------------------------------------------
ErrlUserDetailsLogRegister::ErrlUserDetailsLogRegister(
    const TARGETING::Target * i_pTarget,
    DeviceFW::AccessType i_accessType, ...)
    : iv_pTarget(i_pTarget), iv_dataSize(0)
{
    TRACDCOMP(g_trac_errl, "LogRegister: target %p type %x",
        i_pTarget, i_accessType);

    setStateLogHUID();

    // get the data - do the read
    va_list args;
    va_start(args, i_accessType);
    readRegister(i_accessType, args);
    va_end(args);

} // ctor with target and register type/address

//------------------------------------------------------------------------------
ErrlUserDetailsLogRegister::ErrlUserDetailsLogRegister(
    const TARGETING::Target * i_pTarget,
    void *i_dataBuf,
    size_t i_dataSize,
    DeviceFW::AccessType i_accessType, ...)
    : iv_pTarget(i_pTarget), iv_dataSize(0)
{
    TRACDCOMP(g_trac_errl, "LogRegister: target %p type %x dataBuf %p size %d",
        i_pTarget, i_accessType,
        i_dataBuf, i_dataSize
        );

    setStateLogHUID();

    // if there's data, just copy it thru.
    if (i_dataBuf != NULL)
    {
        // get the data - do the copy
        va_list args;
        va_start(args, i_accessType);
        copyRegisterData(i_dataBuf, i_dataSize, i_accessType, args);
        va_end(args);
    }
    else
    {   // user didn't give us any data -
        // get the data ourselves - do the read
        va_list args;
        va_start(args, i_accessType);
        readRegister(i_accessType, args);
        va_end(args);
    }
} // ctor with target, register type/address and already-read data

}
