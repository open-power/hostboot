/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio_odyssey.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
 * @file  mmio_odyssey.C
 * @brief Function definitions that are specific to the Odyssey OCMB
 * implementation of MMIO.
 */

#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <mmio/mmio_reasoncodes.H>
#include <sys/sync.h>
#include "mmio_odyssey.H"
#include <endian.h>

// Trace definition
extern trace_desc_t* g_trac_mmio; //from mmio.C

using namespace TARGETING;

namespace MMIOODY
{



/*******************************************************************************
 *
 * See header file for comments
 */
errlHndl_t determineOdyCallouts(const TARGETING::TargetHandle_t i_odyTarget,
                                const uint64_t i_offset,
                                DeviceFW::OperationType i_opType,
                                errlHndl_t i_err,
                                bool& o_fwFailure)
{
    bool l_fwFailure = false; //default to a hw failure
    errlHndl_t l_err = nullptr;
    size_t l_reqSize = 0;
    ERRORLOG::ErrlUserDetailsLogRegister l_regDump(i_odyTarget);

    do
    {
        // If the transaction was a read to any of these error registers,
        // that we're about to read then we know that it already failed.
        // Don't keep trying to read it or we could end up in a recursive
        // loop.
        if(i_opType == DeviceFW::READ)
        {
            switch(i_offset)
            {
                case MMIOCOMMON_scom_to_offset(ODY_MMIO_MCFGERR):
                case MMIOCOMMON_scom_to_offset(ODY_MMIO_MCFGERRA):
                case MMIOCOMMON_scom_to_offset(ODY_MMIO_MMIOERR):
                case MMIOCOMMON_scom_to_offset(ODY_MMIO_MFIR):
                case MMIOCOMMON_scom_to_offset(ODY_MMIO_MFIRWOF):
                    TRACFCOMP(g_trac_mmio,
                      "determineOdyCallouts: recursive loop detected:"
                      " OCMB[0x%08x] offset[0x%016llx]",
                      TARGETING::get_huid(i_odyTarget), i_offset);
                    /*@
                     * @errortype
                     * @moduleid         MMIO::MOD_DETERMINE_ODY_CALLOUTS
                     * @reasoncode       MMIO::RC_BAD_MMIO_READ
                     * @userdata1        OCMB huid
                     * @userdata2        Address offset
                     * @devdesc          OCMB MMIO read failed
                     * @custdesc         Unexpected memory subsystem firmware
                     *                   error.
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_DETERMINE_ODY_CALLOUTS,
                                    MMIO::RC_BAD_MMIO_READ,
                                    TARGETING::get_huid(i_odyTarget),
                                    i_offset,
                                    ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                    break;

                default:
                    break;
            }
            if(l_err)
            {
                break;
            }
        }

        // Check if this is an access to config space
        if(i_offset < MMIOCOMMON::OCMB_IB_MMIO_OFFSET)
        {
            MMIOCOMMON::mcfgerrReg_t l_reg;

            TRACFCOMP(g_trac_mmio,
                   "determineOdyCallouts: getting callouts for failed config"
                   " space transaction on OCMB[0x%08x]", get_huid(i_odyTarget));

            // Read the Odyssey MCFGERR register
            // NOTE: This register is not clearable
            l_reqSize = sizeof(l_reg.word64);
            l_err = DeviceFW::deviceRead(
                                     i_odyTarget,
                                     &l_reg.word64,
                                     l_reqSize,
                                     DEVICE_SCOM_ADDRESS(ODY_MMIO_MCFGERR));
            if(l_err)
            {
                TRACFCOMP(g_trac_mmio, ERR_MRK
                          "determineOdyCallouts: getscom(MCFGERR) failed"
                          " on OCMB[0x%08x]", get_huid(i_odyTarget));
                break;
            }

            TRACFCOMP(g_trac_mmio,
                      "determineOdyCallouts: MCFGERR: 0x%016llx on"
                      " OCMB[0x%08x]", l_reg.word64, get_huid(i_odyTarget));

            // Extract the OCAPI response code from the register
            switch(l_reg.resp_code)
            {
                // Firmware Errors
                case MMIOCOMMON::OCAPI_UNSUPPORTED_OP_LENGTH:
                case MMIOCOMMON::OCAPI_BAD_ADDRESS:
                    l_fwFailure = true;
                    break;

                // This one could be caused by a bad address (FW) if there is
                // a device/function mismatch.  Otherwise, it's bad HW.
                case MMIOCOMMON::OCAPI_FAILED:
                    if(l_reg.dev_func_mismatch)
                    {
                        l_fwFailure = true;
                        break;
                    }
                    break;

                // Everything else is HW failure
                default:
                    break;
            }

            // Dump some regs specific to config failures
            l_regDump.addDataBuffer(&l_reg.word64, sizeof(l_reg.word64),
                                    DEVICE_SCOM_ADDRESS(ODY_MMIO_MCFGERR));
            l_regDump.addData(DEVICE_SCOM_ADDRESS(ODY_MMIO_MCFGERRA));
            break;
        }

    }while(0);

    if(!l_err)
    {
        // Dump some registers common to both types of transaction types
        l_regDump.addData(DEVICE_SCOM_ADDRESS(ODY_MMIO_MFIR));
        l_regDump.addData(DEVICE_SCOM_ADDRESS(ODY_MMIO_MFIRWOF));

        // Add our register dump to the error log.
        l_regDump.addToLog(i_err);
    }

    // Notify caller of HW or FW failure
    o_fwFailure = l_fwFailure;
    return l_err;
}

/**
 * @brief Executes an IBSCOM (MMIO) access operation to an Odyssey chip
 * This function performs an MMIO-based SCOM access operation.
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
 * @param[in]   i_accessType    DeviceFW::AccessType enum (=IBSCOM_ODY)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              which is the scom address
 * @return  errlHndl_t
 */
errlHndl_t routeIbScom(DeviceFW::OperationType i_opType,
                       TARGETING::Target* i_target,
                       void* io_buffer,
                       size_t& io_buflen,
                       int64_t i_accessType,
                       va_list i_args)
{
    errlHndl_t l_errhdl = nullptr;

    // Since the error handling is not atomic, need to make sure only one
    //  thread is doing a scom at a time.
    auto mutex = i_target->getHbMutexAttr<TARGETING::ATTR_SCOM_ACCESS_MUTEX>();
    recursive_mutex_lock(mutex);

    do {
        // Only one arg : scom address
        uint64_t l_scomAddr = va_arg(i_args,uint64_t);

        // SCOMs must be exactly 8-bytes
        assert(io_buflen==8,"routeIbScom> buffer is %d != 8 bytes", io_buflen);

        // Transform the scom address into the MMIO address
        // There is a workaround in place for handling Odyssey multicast operations.
        uint64_t l_mmioAddr = MMIOCOMMON_scom_to_offset(l_scomAddr);

        // Make a convenient local var to deal with
        uint64_t* l_scomdata = (reinterpret_cast<uint64_t *>(io_buffer));

        // Use a local buffer to avoid changing the input buffer value on writes
        uint64_t* l_buffer = (uint64_t*)malloc(io_buflen);
        memcpy(l_buffer, l_scomdata, io_buflen);

        // OMI is little-endian, need to byteswap the data
        if(i_opType == DeviceFW::WRITE)
        {
            *l_buffer = __builtin_bswap64(*l_buffer);
        }

        // Call the MMIO driver to actually perform the operation
        l_errhdl = DeviceFW::deviceOp(i_opType,
                                      i_target,
                                      l_buffer,
                                      io_buflen,
                                      DEVICE_MMIO_ADDRESS(l_mmioAddr, io_buflen));
        if( l_errhdl )
        {
            TRACFCOMP(g_trac_mmio,
                      "routeIbScom: MMIO failed for SCOM 0x%.8X on %.8X",
                      l_scomAddr,
                      TARGETING::get_huid(i_target));
            free(l_buffer);
            break;
        }

        // OMI is little-endian, need to byteswap the data
        if(i_opType == DeviceFW::READ)
        {
            *l_scomdata = __builtin_bswap64(*l_buffer);
        }

        free(l_buffer);

    } while(0);

    recursive_mutex_unlock(mutex);

    return l_errhdl;
}

// Connect up the driver
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::IBSCOM_ODY,
                      TYPE_OCMB_CHIP,
                      routeIbScom);


}; // End MMIOODY namespace
