/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/ibscom.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
 * @file ibscom.C
 * @brief Routes generic IBSCOM driver calls to appropriate
 *        chip-specific implementation.
 */

#include <devicefw/driverif.H>
#include <scom/scomreasoncodes.H>
#include <chipids.H>

extern trace_desc_t* g_trac_scom; //defined in scom.C

/**
 * @brief Routes an IBSCOM (MMIO) access operation
 * This function routes a IBSCOM driver call to the appropriate driver.
 * It follows a pre-defined prototype functions in order to be registered
 * with the device-driver framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        OCMB Chip target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (=IBSCOM)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the IBM scom address
 * @return  errlHndl_t
 */
errlHndl_t routeIbScom(DeviceFW::OperationType i_opType,
                       TARGETING::Target* i_ocmb,
                       void* io_buffer,
                       size_t& io_buflen,
                       int64_t i_accessType,
                       va_list i_args)
{
    errlHndl_t l_errhdl = nullptr;

    do {
        // Only one arg : scom address
        uint64_t l_scomAddr = va_arg(i_args,uint64_t);

        // Read the chipid to determine what kind of OCMB it is
        const auto l_ocmbChipId = i_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>();

        // Call the appropriate driver
        switch(l_ocmbChipId)
        {
            case POWER_CHIPID::EXPLORER_16:
                l_errhdl = deviceOp(i_opType,
                                    i_ocmb,
                                    io_buffer,
                                    io_buflen,
                                    DEVICE_IBSCOM_EXP_ADDRESS(l_scomAddr));
                break;

            case POWER_CHIPID::ODYSSEY_16:
                l_errhdl = deviceOp(i_opType,
                                    i_ocmb,
                                    io_buffer,
                                    io_buflen,
                                    DEVICE_IBSCOM_ODY_ADDRESS(l_scomAddr));
                break;

            default:
                // Should never get here, but just in case...
                TRACFCOMP(g_trac_scom, ERR_MRK
                          "routeIbScom: Unsupported chip ID[0x%08x] on OCMB[0x%08x]",
                          l_ocmbChipId, TARGETING::get_huid(i_ocmb));
                /*@
                 * @errortype
                 * @moduleid         SCOM::MOD_ROUTE_IBSCOM
                 * @reasoncode       SCOM::SCOM_UNSUPPORTED_CHIPID
                 * @userdata1[00:31] OCMB HUID
                 * @userdata1[32:63] OCMB chip ID
                 * @userdata2        SCOM Address
                 * @devdesc          A MMIO operation was attempted
                 *                   on an unsupported OCMB chip.
                 * @custdesc         Unexpected memory subsystem firmware error.
                 */
                l_errhdl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                SCOM::MOD_ROUTE_IBSCOM,
                                SCOM::SCOM_UNSUPPORTED_CHIPID,
                                TWO_UINT32_TO_UINT64(TARGETING::get_huid(i_ocmb),
                                                     l_ocmbChipId),
                                l_scomAddr,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
        }

    } while(0);

    return l_errhdl;
}

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::IBSCOM,
                      TARGETING::TYPE_OCMB_CHIP,
                      routeIbScom);
