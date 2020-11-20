/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_hiomapdd.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <console/consoleif.H>
#include <devicefw/driverif.H>
#include <initservice/initserviceif.H>
#include <pnor/pnor_reasoncodes.H>
#include "pnor_ipmidd.H"
#include "pnor_mboxdd.H"
#include "pnor_hiomapdd.H"
#include "pnor_utils.H"

namespace PNOR
{

/**
 * @brief Performs an PNOR Read Operation
 * This function performs a PNOR Read operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the PNOR address and chip select
 * @return  errlHndl_t
 */
errlHndl_t ddRead(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args, uint64_t);

    do
    {
        //@todo (RTC:36951) - add support for unaligned data
        // Ensure we are operating on a 32-bit (4-byte) boundary
        assert( reinterpret_cast<uint64_t>(io_buffer) % 4 == 0 );
        assert( io_buflen % 4 == 0 );

        // The PNOR device driver interface is initialized with the
        // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL.  Other target
        // access requires a separate PnorHiomapDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

        // Read the flash
        l_err = Singleton<PnorHiomapDD>::instance().readFlash(io_buffer,
                io_buflen,
                l_addr);

        if(l_err)
        {
            break;
        }

    }
    while(0);

    return l_err;
}

/**
 * @brief Performs an PNOR Write Operation
 * This function performs a PNOR Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the PNOR address and chip select
 * @return  errlHndl_t
 */
errlHndl_t ddWrite(DeviceFW::OperationType i_opType,
                   TARGETING::Target* i_target,
                   void* io_buffer,
                   size_t& io_buflen,
                   int64_t i_accessType,
                   va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args, uint64_t);

    do
    {
        //@todo (RTC:36951) - add support for unaligned data
        // Ensure we are operating on a 32-bit (4-byte) boundary
        assert( reinterpret_cast<uint64_t>(io_buffer) % 4 == 0 );
        assert( io_buflen % 4 == 0 );

        // The PNOR device driver interface is initialized with the
        // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL.  Other target
        // access requires a separate PnorHiomapDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

        // Write the flash
        l_err = Singleton<PnorHiomapDD>::instance().writeFlash(io_buffer,
                io_buflen,
                l_addr);

        if(l_err)
        {
            break;
        }

    }
    while(0);

    return l_err;
}

/**
 * @brief Informs caller if the driver is using
 *        L3 Cache for fake PNOR or not.
 *
 * @return Indicate state of fake PNOR
 *         true = PNOR DD is using L3 Cache for fake PNOR
 *         false = PNOR DD not using L3 Cache for fake PNOR
 */
bool usingL3Cache()
{
    return false;
}

/**
 * @brief Retrieve some information about the PNOR/SFC hardware
 */
void getPnorInfo( PnorInfo_t& o_pnorInfo )
{
    o_pnorInfo.mmioOffset = LPC_SFC_MMIO_OFFSET | LPC_FW_SPACE;
    o_pnorInfo.norWorkarounds =
        Singleton<PnorHiomapDD>::instance().getNorWorkarounds();
    o_pnorInfo.flashSize =
        Singleton<PnorHiomapDD>::instance().getNorSize();
}

/**
 * @brief Get HIOMAP PNOR access mode
 */
PNOR::hiomapMode getPnorAccessMode(void)
{
    return Singleton<PnorHiomapDD>::instance().getAccessMode();
}

// Register access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddRead);

DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddWrite);

}; //namespace PNOR

errlHndl_t PnorHiomapDD::readFlash(void* o_buffer,
                    size_t& io_buflen,
                    uint64_t i_address)
{
    return iv_pnor->readFlash(o_buffer, io_buflen, i_address);
}

errlHndl_t PnorHiomapDD::writeFlash(const void* i_buffer,
                     size_t& io_buflen,
                     uint64_t i_address)
{
    return iv_pnor->writeFlash(i_buffer, io_buflen, i_address);
}

uint32_t PnorHiomapDD::getNorSize(void)
{
    return iv_pnor->getNorSize();
}

uint32_t PnorHiomapDD::getNorWorkarounds(void)
{
    return iv_pnor->getNorWorkarounds();
}

PNOR::hiomapMode PnorHiomapDD::getAccessMode(void)
{
    return iv_mode;
}

static PnorIf* probeHiomapTransport(TARGETING::Target* i_target,
                                    PNOR::hiomapMode& io_mode)
{
    PnorIf* pnor;

    do {
        if ((pnor = PnorIpmiDD::probe(i_target)))
        {
            io_mode = PNOR::PNOR_IPMI;
            break;
        }

        if ((pnor = PnorMboxDD::probe(i_target)))
        {
            io_mode = PNOR::PNOR_MBOX;
            break;
        }
    } while (0);

    if (pnor)
    {
        return pnor;
    }

    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "Probes for MBOX and IPMI HIOMAP transports failed\n");
    CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "Cannot access PNOR!\n");
    CONSOLE::flush();
    INITSERVICE::doShutdown(PNOR::RC_PNOR_INIT_FAILURE);

    assert(false && "Unreachable");

    return NULL;
}

PnorHiomapDD::PnorHiomapDD(TARGETING::Target* i_target)
:iv_mode(PNOR::PNOR_UNKNOWN)
{
    iv_pnor = probeHiomapTransport(i_target, iv_mode);
}

PnorHiomapDD::~PnorHiomapDD()
{
    delete iv_pnor;
}
