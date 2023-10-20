/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio_explorer.C $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
 * @file  mmio_explorer.C
 * @brief Function definitions that are specific to the Explorer OCMB
 * implementation of MMIO.
 */

#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <explorer_scom_addresses.H>
#include <exp_inband.H>
#include <mmio/mmio_reasoncodes.H>

// Trace definition
extern trace_desc_t* g_trac_mmio; //from mmio.C

using namespace TARGETING;

namespace MMIOEXP
{

#define MMIOEXP_SCOM2OFFSET(_SCOM_ADDR) \
    (mss::exp::ib::EXPLR_IB_MMIO_OFFSET | (_SCOM_ADDR << 3))

/**
 * @brief Possible Open CAPI response codes for config operations
 */
enum
{
    OCAPI_RETRY_REQUEST         = 0x2,
    OCAPI_DATA_ERROR            = 0x8,
    OCAPI_UNSUPPORTED_OP_LENGTH = 0x9,
    OCAPI_BAD_ADDRESS           = 0xB,
    OCAPI_FAILED                = 0xE,
};

/**
 * @brief Possible PCB error codes for non-config operations
 */
enum
{
    PCB_OK                      = 0x0,
    PCB_INVALID_ADDRESS         = 0x4,
    PCB_PARITY_ERROR            = 0x6,
    PCB_TIMEOUT                 = 0x7,
};

/**
 * @brief bit-field definitions for MCFGERR register
 */
typedef union mcfgerrReg
{
    struct
    {
        uint64_t reserved           :16;
        uint64_t resp_code          :4;
        uint64_t bdi                :1;
        uint64_t error_type         :3;
        uint64_t device             :5;
        uint64_t function           :3;
        uint64_t dev_func_mismatch  :1;
        uint64_t detect_bad_op      :1;
        uint64_t tbit_is_1          :1;
        uint64_t data_is_bad        :1;
        uint64_t pl_is_invalid      :1;
        uint64_t bad_op_or_align    :1;
        uint64_t addr_no_implemented:1;
        uint64_t rdata_vld          :1;
        uint64_t tbit               :1;
        uint64_t plen               :3;
        uint64_t portnun            :2;
        uint64_t dl                 :2;
        uint64_t capptag            :16;
    };
    uint64_t word64;
}mcfgerrReg_t;

/**
 * @brief bit-field definitions for GIF2PCB_ERROR register
 */
typedef union gif2pcbErrorReg
{
    struct
    {
        uint64_t parity_error_rsp_info              :1;
        uint64_t parity_error_rsp_data_0            :1;
        uint64_t parity_error_rsp_data_1            :1;
        uint64_t parity_error_rsp_data_2            :1;
        uint64_t parity_error_rsp_data_3            :1;
        uint64_t timeout_error                      :1;
        uint64_t int_addr_access_error              :1;
        uint64_t invalid_access                     :1;
        uint64_t pcb_err_code                       :3;
        uint64_t axi_read_addr_parity_error         :1;
        uint64_t axi_write_addr_parity_error        :1;
        uint64_t axi_write_data_parity_error_31_24  :1;
        uint64_t axi_write_data_parity_error_23_16  :1;
        uint64_t axi_write_data_parity_error_15_8   :1;
        uint64_t axi_write_data_parity_error_7_0    :1;
        uint64_t pib2gif_parity_error               :1;
        uint64_t reserved                           :46;
    };
    struct
    {
        uint64_t used_bits                          :18;
        uint64_t unused_bits                        :46;
    };
    uint64_t word64;
}gif2pcbErrorReg_t;

/**
 * @brief bit-field definitions for PIB2GIF_ERROR register
 */
typedef union pib2gifErrorReg
{
    struct
    {
        uint64_t parity_error_req_data_0:1;
        uint64_t parity_error_req_data_1:1;
        uint64_t parity_error_req_data_2:1;
        uint64_t parity_error_req_data_3:1;
        uint64_t parity_error_req_addr_0:1;
        uint64_t parity_error_req_addr_1:1;
        uint64_t parity_error_req_ctrl:1;
        uint64_t timeout_error:1;
        uint64_t int_addr_access_error:1;
        uint64_t parity_error_on_fsm:1;
        uint64_t parity_error_on_reg0:1;
        uint64_t parity_error_on_reg1:1;
        uint64_t parity_error_on_reg2:1;
        uint64_t parity_error_on_reg3:1;
        uint64_t parity_error_on_reg4:1;
        uint64_t parity_error_on_reg5:1;
        uint64_t invalid_address_error:1;
        uint64_t reserved1:15;
        uint64_t gif2pcb_error:18;
        uint64_t reserved2:14;
    };
    uint64_t word64;
}pib2gifErrorReg_t;


/*******************************************************************************
 *
 * See header file for comments
 */
errlHndl_t determineExpCallouts(const TARGETING::TargetHandle_t i_expTarget,
                                const uint64_t i_offset,
                                DeviceFW::OperationType i_opType,
                                errlHndl_t i_err,
                                bool& o_fwFailure)
{
    bool l_fwFailure = false; //default to a hw failure
    errlHndl_t l_err = nullptr;
    size_t l_reqSize = 0;
    ERRORLOG::ErrlUserDetailsLogRegister l_regDump(i_expTarget);

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
                case MMIOEXP_SCOM2OFFSET(EXPLR_MMIO_MCFGERR):
                case MMIOEXP_SCOM2OFFSET(EXPLR_MMIO_MCFGERRA):
                case MMIOEXP_SCOM2OFFSET(EXPLR_MMIO_MMIOERR):
                case MMIOEXP_SCOM2OFFSET(EXPLR_TP_MB_UNIT_TOP_PIB2GIF_ERROR_REG):
                case MMIOEXP_SCOM2OFFSET(EXPLR_TP_MB_UNIT_TOP_GIF2PCB_ERROR_REG):
                case MMIOEXP_SCOM2OFFSET(EXPLR_MMIO_MFIR):
                case MMIOEXP_SCOM2OFFSET(EXPLR_MMIO_MFIRWOF):
                    TRACFCOMP(g_trac_mmio,
                      "determineExpCallouts: recursive loop detected:"
                      " OCMB[0x%08x] offset[0x%016llx]",
                      TARGETING::get_huid(i_expTarget), i_offset);
                    /*@
                     * @errortype
                     * @moduleid         MMIO::MOD_DETERMINE_EXP_CALLOUTS
                     * @reasoncode       MMIO::RC_BAD_MMIO_READ
                     * @userdata1        OCMB huid
                     * @userdata2        Address offset
                     * @devdesc          OCMB MMIO read failed
                     * @custdesc         Unexpected memory subsystem firmware
                     *                   error.
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_DETERMINE_EXP_CALLOUTS,
                                    MMIO::RC_BAD_MMIO_READ,
                                    TARGETING::get_huid(i_expTarget),
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
        if(i_offset < mss::exp::ib::EXPLR_IB_MMIO_OFFSET)
        {
            mcfgerrReg_t l_reg;

            TRACFCOMP(g_trac_mmio,
                   "determineExpCallouts: getting callouts for failed config"
                   " space transaction on OCMB[0x%08x]", get_huid(i_expTarget));

            // Read the Explorer MCFGERR register
            // NOTE: This register is not clearable
            l_reqSize = sizeof(l_reg.word64);
            l_err = DeviceFW::deviceRead(
                                     i_expTarget,
                                     &l_reg.word64,
                                     l_reqSize,
                                     DEVICE_SCOM_ADDRESS(EXPLR_MMIO_MCFGERR));
            if(l_err)
            {
                TRACFCOMP(g_trac_mmio, ERR_MRK
                          "determineExpCallouts: getscom(MCFGERR) failed"
                        " on OCMB[0x%08x]", get_huid(i_expTarget));
                break;
            }

            TRACFCOMP(g_trac_mmio,
                      "determineExpCallouts: MCFGERR: 0x%016llx on"
                        " OCMB[0x%08x]", l_reg.word64, get_huid(i_expTarget));

            // Extract the OCAPI response code from the register
            switch(l_reg.resp_code)
            {
                // Firmware Errors
                case OCAPI_UNSUPPORTED_OP_LENGTH:
                case OCAPI_BAD_ADDRESS:
                    l_fwFailure = true;
                    break;

                // This one could be caused by a bad address (FW) if there is
                // a device/function mismatch.  Otherwise, it's bad HW.
                case OCAPI_FAILED:
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
                                    DEVICE_SCOM_ADDRESS(EXPLR_MMIO_MCFGERR));
            l_regDump.addData(DEVICE_SCOM_ADDRESS(EXPLR_MMIO_MCFGERRA));
            break;
        }

        // We were accessing a SCOM reg, MSCC reg, or SRAM

        pib2gifErrorReg_t l_pib2gif;
        gif2pcbErrorReg_t l_gif2pcb;

        TRACFCOMP(g_trac_mmio,
                  "determineExpCallouts: getting callouts for failed MMIO space"
                  " transaction on OCMB[0x%08x]", get_huid(i_expTarget));

        // Read the PIB2GIF error reg
        // NOTE: This register is ONLY accessible through MMIO path, not I2C.
        l_reqSize = sizeof(l_pib2gif.word64);
        l_err = DeviceFW::deviceRead(
                   i_expTarget,
                   &l_pib2gif.word64,
                   l_reqSize,
                   DEVICE_SCOM_ADDRESS(EXPLR_TP_MB_UNIT_TOP_PIB2GIF_ERROR_REG));
        if(l_err)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                    "determineExpCallouts: getscom(PIB2GIF_ERROR_REG) failed"
                    " on OCMB[0x%08x]", get_huid(i_expTarget));
            break;
        }

        TRACFCOMP(g_trac_mmio,
                  "determineExpCallouts: PIB2GIF_ERROR_REG: 0x%016llx"
                  " on OCMB[0x%08x]", l_pib2gif.word64, get_huid(i_expTarget));

        // The pib2gif error register contains a copy of the gif2pcb error reg.
        // No need to read it again, just copy it into our struct.
        l_gif2pcb.word64 = 0;
        l_gif2pcb.used_bits = l_pib2gif.gif2pcb_error;

        TRACFCOMP(g_trac_mmio,
                  "determineExpCallouts: GIF2PCB_ERROR_REG: 0x%016llx"
                  " on OCMB[0x%08x]", l_gif2pcb.word64, get_huid(i_expTarget));

        // Check for software errors
        if((l_pib2gif.invalid_address_error) ||
           (l_gif2pcb.invalid_access) ||
           (l_gif2pcb.pcb_err_code == PCB_INVALID_ADDRESS))
        {
            l_fwFailure = true;
        }

        // dump some regs specific to MMIO failures
        l_regDump.addDataBuffer(&l_pib2gif.word64, sizeof(l_pib2gif.word64),
                   DEVICE_SCOM_ADDRESS(EXPLR_TP_MB_UNIT_TOP_PIB2GIF_ERROR_REG));
        l_regDump.addData(
                   DEVICE_SCOM_ADDRESS(EXPLR_TP_MB_UNIT_TOP_GIF2PCB_ERROR_REG));
        l_regDump.addData(DEVICE_SCOM_ADDRESS(EXPLR_MMIO_MMIOERR));
        break;
    }while(0);

    if(!l_err)
    {
        // Dump some registers common to both types of transaction types
        l_regDump.addData(DEVICE_SCOM_ADDRESS(EXPLR_MMIO_MFIR));
        l_regDump.addData(DEVICE_SCOM_ADDRESS(EXPLR_MMIO_MFIRWOF));

        // Add our register dump to the error log.
        l_regDump.addToLog(i_err);
    }

    // Notify caller of HW or FW failure
    o_fwFailure = l_fwFailure;
    return l_err;
}

}; // End MMIOEXP namespace
