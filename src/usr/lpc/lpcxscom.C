/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/lpcxscom.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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
 *  @file lpcxscom.C
 *
 *  @brief Implementation of the XSCOM LPC device driver.
 */

#include <sys/mmio.h>
#include <sys/mm.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <errl/errlmanager.H>
#include "lpcdd.H"
#include <lpc/lpc_const.H>
#include <sys/time.h>
#include <lpc/lpc_reasoncodes.H>
#include <initservice/initserviceif.H>
#include <kernel/console.H> //@todo - RTC:97495 -- Resolve console access
#include <kernel/bltohbdatamgr.H>
#include <errl/errludlogregister.H>
#include <initservice/taskargs.H>
#include <arch/memorymap.H>
#include <util/misc.H>
#include <errl/errlreasoncodes.H>
#include <fapiPlatTrace.H>
#include <fapi2/plat_target.H>
#include <fapi2/target.H>
#include <p10_scom_proc.H>
#include <p10_lpc_utils.H>
#include <algorithm>
#include <fapi2/plat_hwp_invoker.H>
#include <p10_sbe_lpc_init.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include "lpcxscom.H"

namespace S=scomt::proc;

extern trace_desc_t* g_trac_lpc;

/**
 *  @brief Map of LPC transaction types to string name.  Note: this must be kept
 *      in sync with TramsType enum in lpcif.H
 */
const std::map<LPC::TransType,const char*> XscomLpc::cv_lpcTypeDecoder =
{
    {LPC::TRANS_IO, "TRANS_IO"},
    {LPC::TRANS_MEM,"TRANS_MEM"},
    {LPC::TRANS_FW, "TRANS_FW"},
    {LPC::TRANS_REG,"TRANS_REG"},
    {LPC::TRANS_ABS,"TRANS_ABS"},
    {LPC::TRANS_ERR,"TRANS_ERR"},
};

/**
 *  @brief Array of LPC registers to capture on error paths
 */
const std::array<uint32_t,48> XscomLpc::cv_lpcErrRegAddrs = {

    // OPB Master (4 bytes accesses)
    OPBM_ACCUM_STATUS_REG,
    OPBM_ACCUM_STATUS_INT_ENABLE_REG,
    OPBM_CONTROL_REG,
    OPBM_IOMUX_CONTROL_REG,
    OPBM_TRACE_00_REG,
    OPBM_TRACE_01_REG,
    OPBM_TRACE_02_REG,
    OPBM_TRACE_03_REG,
    OPBM_TRACE_04_REG,
    OPBM_TRACE_05_REG,
    OPBM_TRACE_06_REG,
    OPBM_TRACE_07_REG,
    OPBM_TRACE_08_REG,
    OPBM_TRACE_09_REG,
    OPBM_BUF_ERR_INJECT_REG,
    OPBM_TIMEOUT_VALUE_REG,
    OPBM_ACCUM_STATUS_ERR_INJECT_REG,
    OPBM_ACTUAL_STATUS_REG,
    OPBM_INT_REG,
    OPBM_INT_ENABLE_REG,
    OPBM_INT_POLARITY_REG,
    OPBM_INT_INPUTS_REG,

    // OPB Arbiter (1 byte accesses)
    OPB_ARB_PRIORITY_REG,
    OPB_ARB_CONTROL_REG,
    OPB_ARB_REVISION_ID_0_REG,
    OPB_ARB_REVISION_ID_1_REG,
    OPB_ARB_REVISION_ID_2_REG,
    OPB_ARB_REVISION_ID_3_REG,

    // LPCHC (4 byte accesses)
    LPCHC_BASE_ADDR_0_INT_REG,
    LPCHC_BASE_ADDR_1_IO_REG,
    LPCHC_BASE_ADDR_2_MEM_REG,
    LPCHC_BASE_ADDR_3_FW_REG,
    LPCHC_MEM_SEGMENT_REG,
    LPCHC_FW_SEGMENT_REG,
    LPCHC_FW_READ_ACCESS_SIZE_REG,
    LPCHC_SYNC_CYCLE_CNT_REG,
    LPCHC_LPCIRQSER_CONTROL_REG,
    LPCHC_LPCIRQ_MASK_REG,
    LPCHC_LPCIRQ_STATUS_REG,
    LPCHC_ERROR_ADDR_REG,
    LPCHC_LPC_BUS_MASTER_GRANT_REG,
    LPCHC_LPC_BUS_MASTER_DATA_REG,
    LPCHC_LPC_BUS_MASTER_ADDR_REG,
    LPCHC_LPC_BUS_MASTER_SYNC_REG,
    LPCHC_WATERMARK_REG,
    LPCHC_LPC_BUS_ABORT_CYCLE_REG,
    LPCHC_RESET_REG,
};

/**
 *  @brief Returns whether the given input is a power of two
 *
 *  @param[in] i_val Input value to check for whether it is a power of two
 *
 *  @return bool Whether input value is a power of two
 */
bool isPowerOf2(const size_t i_val)
{
    return (i_val && (!(i_val & (i_val-1))));
}


/**
 *  @brief Returns the highest power of two (including 2^0=1) that is less than
 *      or equal to the given input value.
 *
 *  @param[in] i_val Input value.  Must not be 0.  Must not be greater than
 *      1<<63 (asserts in either case).
 *
 *  @return size_t Highest power of two less than or equal to the input
 */
size_t highestPowerOf2(const size_t i_val)
{
    assert(i_val,"highestPowerOf2: Input value of 0 not supported");
    assert(i_val<= (static_cast<size_t>(1)<<63), "highestPowerOf2: "
           "Input value > (1<<63) not supported");

    size_t powerOf2 = 1; // 2^0

    while((powerOf2<<1) <= i_val)
    {
        powerOf2 <<= 1;
    }

    return powerOf2;
}


XscomLpc::XscomLpc(TARGETING::Target* i_pProc)
: LpcDD(i_pProc)
{
    TRACFCOMP(g_trac_lpc, ENTER_MRK "XscomLpc::XscomLpc.  Proc HUID = 0x%08X",
              TARGETING::get_huid(i_pProc));

    TRACFCOMP(g_trac_lpc, EXIT_MRK "XscomLpc::XscomLpc");
}


XscomLpc::~XscomLpc()
{
    TRACFCOMP(g_trac_lpc, ENTER_MRK "XscomLpc::~XscomLpc");
    TRACFCOMP(g_trac_lpc, EXIT_MRK "XscomLpc::~XscomLpc");
}


errlHndl_t XscomLpc::hwReset(const ResetLevels i_resetLevel)
{
    TRACFCOMP(g_trac_lpc, ENTER_MRK "XscomLpc::hwReset: i_resetLevel=0x%08X",
              i_resetLevel);

    errlHndl_t pError = nullptr;

    // Check iv_resetActive to avoid infinite loops
    // and don't reset if in the middle of FFDC collection
    // and don't bother if we already failed the recovery once
    if ( ( iv_resetActive == false ) &&
         ( iv_ffdcActive == false  ) &&
         ( iv_errorRecoveryFailed == false) )
    {
        iv_resetActive = true;

        do
        {

        switch(i_resetLevel)
        {
            case RESET_CLEAR:
            {
                break;
            }

            case RESET_INIT:
            case RESET_OPB_LPCHC_HARD:
            case RESET_OPB_LPCHC_SOFT:
            {

                TRACFCOMP(g_trac_lpc, INFO_MRK "XscomLpc::hwReset: "
                    "Invoking LPC complex reset");
                fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> fapiProc
                       (iv_proc);
                const bool HAS_PNOR=true;
                const bool RESET_LPC_BUS=true;
                FAPI_INVOKE_HWP(pError, p10_sbe_lpc_init_any, fapiProc,
                    HAS_PNOR,!RESET_LPC_BUS);
                if(pError)
                {
                    break;
                }

                TRACFCOMP(g_trac_lpc, INFO_MRK "XscomLpc::hwReset: "
                    "Invoking LPC bus abort");

                // Write LPCHC LPC Bus Abort Cycle Register
                uint32_t addr = LPCHC_LPC_BUS_ABORT_CYCLE_REG;

                // Note the abort data is arbitrary
                uint32_t abort = 0x72667984; // "HBOT"
                size_t buflen = sizeof(abort);

                pError = _rwLPC(false,LPC::TRANS_ERR,addr,&abort,buflen);
                if(pError)
                {
                    // Timeout, bad address, or XSCOM fail ... no point
                    // attempting HW reset when already in a HW reset handler
                    break;
                }

                // Note this error check could call hwReset again, but in that
                // case iv_resetActive will inhibit any further attempts to
                // reset
                pError = checkForLpcErrors();
                if(pError)
                {
                    break;
                }

                break;
            }

            default:
            {
                TRACFCOMP(g_trac_lpc, ERR_MRK "XscomLpc::hwReset: "
                          "Unsupported reset level %d",
                          i_resetLevel);

                /*@
                 * @errortype
                 * @severity     ERRL_SEV_UNRECOVERABLE
                 * @moduleid     LPC::MOD_XSCOMLPC_HWRESET
                 * @reasoncode   LPC::RC_UNSUPPORTED_OPERATION
                 * @userdata1    Unsupported reset level parameter
                 * @devdesc      Caller passed unsupported reset level into
                 *               XscomLpc::hwReset()
                 * @custdesc     Platform firmware detected processor-attached
                 *               low-bandwidth I/O bus related error implicating
                 *               platform firmware.
                 */
                pError = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    LPC::MOD_XSCOMLPC_HWRESET,
                    LPC::RC_UNSUPPORTED_OPERATION,
                    i_resetLevel,
                    0,
                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

                ERRORLOG::ErrlUserDetailsTarget(iv_proc).addToLog(pError);

                pError->collectTrace(LPC_COMP_NAME,2*KILOBYTE);
                break;
            }

        }// end switch

        if (pError)
        {
            // Note the failed reset
            iv_errorRecoveryFailed = true;
            TRACFCOMP(g_trac_lpc,ERR_MRK "XscomLpc::hwReset> Failed doing LPC "
                      "reset at level=%d, recovery count=%d.  " TRACE_ERR_FMT,
                      i_resetLevel, iv_errorHandledCount,
                      TRACE_ERR_ARGS(pError));
            break;
        }
        else
        {
            // Successful, so increment recovery count
            if( i_resetLevel != RESET_CLEAR )
            {
                iv_errorHandledCount++;
            }

            TRACFCOMP(g_trac_lpc,INFO_MRK "XscomLpc::hwReset> Successful LPC "
                      "reset at level=%d, recovery count=%d",
                      i_resetLevel, iv_errorHandledCount);
        }

        } while(0);

        // reset RESET active flag
        iv_resetActive = false;
    }

    TRACFCOMP(g_trac_lpc, EXIT_MRK "XscomLpc::hwReset: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(pError));

    return pError;
}


errlHndl_t XscomLpc::_rwLPC(
    const bool           i_read_notwrite,
    const LPC::TransType i_type,
    const uint32_t       i_addr,
          void*    const io_pBuffer,
          size_t&        io_buflen)
{
    TRACDCOMP(g_trac_lpc, ENTER_MRK
              "XscomLpc::_rwLPC: read(1) or write(0): %d, i_type = 0x%08X, "
              "i_addr = 0x%08X, "
              "len = %llu, isPowerOf2 ? %d, is <= 8? %d, is >0? %d, "
              "aligned_to_size %d",
              i_read_notwrite, i_type, i_addr, io_buflen,isPowerOf2(io_buflen),
              io_buflen <= 8,io_buflen>0,i_addr % io_buflen==0);

    assert(io_pBuffer != nullptr,"Buffer pointer was nullptr");

    assert(isPowerOf2(io_buflen),
           "XscomLpc::_rwLPC: read(1) or write(0): %d size of %llu was not a "
           "power of 2",
           i_read_notwrite, io_buflen);

    assert(io_buflen > 0,"XscomLpc::_rwLPC: read(1) or write(0): %d size was 0 "
           "bytes",
           i_read_notwrite);

    assert(io_buflen <= 8,"XscomLpc::_rwLPC: read(1) or write(0): %d size "
           "(%llu) was > 8 bytes",
           i_read_notwrite,io_buflen);

    assert(i_addr % io_buflen == 0,"XscomLpc::_rwLPC: read(1) or write(0): %d "
           "addr 0x%08X "
           "is not aligned for size of %llu",
           i_read_notwrite,i_addr,io_buflen);

    errlHndl_t pError = nullptr;

    do {

    uint64_t fullAddr = 0;
    pError = checkAddr(i_type, i_addr, &fullAddr);
    if(pError)
    {
        break;
    }

    // Truncate 64 bit LPC address to 32 bits for XSCOM accesses, since the
    // register protocol only uses 32 bit addresses.  Add the LPC starting
    // address in since the register protocol wants the full address
    auto xscomLpcAddr = static_cast<uint32_t>(fullAddr) + LPC_ADDR_START;

    union Cmd_t
    {
        uint64_t value;

        struct {
            uint64_t read_not_write : 1;
            uint64_t reserved_1_4   : 4;
            uint64_t size           : 7;
            uint64_t reserved_12_31 : 20;
            uint64_t addr           : 32;
        };

        Cmd_t() : value(0) {}
    };

    Cmd_t cmd;
    cmd.read_not_write = i_read_notwrite;
    cmd.size = io_buflen;
    cmd.addr = xscomLpcAddr;

    // This computation determines the starting bit in the 8 byte data register
    // to start reading data from or writing data to, taking into account the
    // alignment of the input starting address.  For example, if the starting
    // address is 7 and the length of transfer is one, then the write of that
    // one byte will start 56 bits into the data register.
    const int bitOffset = (xscomLpcAddr & 7 & ~(io_buflen - 1)) << 3;

    TRACDCOMP(g_trac_lpc, INFO_MRK
              "XscomLpc::_rwLPC: Bit offset = %d",
              bitOffset);

    const size_t expectedScomSize = sizeof(cmd.value);
    size_t scomSize = expectedScomSize;

    pError = DeviceFW::deviceWrite(
                 iv_proc,
                 &(cmd.value),
                 scomSize,
                 DEVICE_SCOM_ADDRESS(S::TP_TPBR_AD_LPC_CMD_REG));
    if(pError)
    {
        TRACFCOMP(g_trac_lpc, ERR_MRK
                  "XscomLpc::_rwLPC: Failed writing LPC command register "
                  "(0x%08X). command = 0x%016llX.",
                  S::TP_TPBR_AD_LPC_CMD_REG,
                  cmd.value);
        break;
    }

    assert(scomSize == expectedScomSize,"SCOM size changed from %llu to %llu "
           "unexpectedly",expectedScomSize,scomSize);

    if (!i_read_notwrite) // Write
    {
        uint64_t data = 0;
        scomSize = sizeof(data);
        memcpy(&data,io_pBuffer,io_buflen);

        TRACDCOMP(g_trac_lpc, INFO_MRK
                  "XscomLpc::_rwLPC: Pre-shifted data 0x%016llX",
                  data);

        data >>= bitOffset;

        TRACDCOMP(g_trac_lpc, INFO_MRK
                  "XscomLpc::_rwLPC: Post-shifted data 0x%016llX",
                  data);

        pError = DeviceFW::deviceWrite(
                     iv_proc,
                     &(data),
                     scomSize,
                     DEVICE_SCOM_ADDRESS(S::TP_TPBR_AD_LPC_DATA_REG));
        if(pError)
        {
            TRACFCOMP(g_trac_lpc, ERR_MRK
                      "XscomLpc::_rwLPC: Failed writing LPC data register "
                      "(0x%08X) for write operation.  data = 0x%016llX.",
                      S::TP_TPBR_AD_LPC_DATA_REG,
                      data);
            break;
        }

        assert(scomSize == expectedScomSize,"SCOM size changed from %llu to "
               "%llu unexpectedly",expectedScomSize,scomSize);
    }

    union LpcStatus_t
    {
        struct {
            uint64_t done : 1;
            uint64_t reserved_2_63 : 63;
        };

        uint64_t value;

    } lpcDone = {{.done=1,.reserved_2_63=0}};

    uint64_t statusReg = 0;

    size_t timeout = LPC_CMD_TIMEOUT_COUNT;
    while (timeout--)
    {
        scomSize = expectedScomSize;
        pError = DeviceFW::deviceRead(
                        iv_proc,
                        &(statusReg),
                        scomSize,
                        DEVICE_SCOM_ADDRESS(S::TP_TPBR_AD_LPC_STATUS_REG));
        if(pError)
        {
            TRACFCOMP(g_trac_lpc, ERR_MRK
                      "XscomLpc::_rwLPC: Failed reading LPC status register "
                      "(0x%08X).",S::TP_TPBR_AD_LPC_STATUS_REG);
            break;
        }

        assert(scomSize == expectedScomSize,"SCOM size changed from %llu to "
               "%llu unexpectedly",expectedScomSize,scomSize);

        if(statusReg & lpcDone.value)
        {
            TRACDCOMP(g_trac_lpc, INFO_MRK
                      "XscomLpc::_rwLPC: Status reg done 0x%016llX",
                      statusReg);
            break;
        }
        else
        {
            TRACDCOMP(g_trac_lpc, INFO_MRK
                      "XscomLpc::_rwLPC: Status reg not done 0x%016llX",
                      statusReg);
        }

        nanosleep(0,LPC_CMD_TIMEOUT_DELAY_NS);
    }

    if(pError)
    {
        break;
    }
    else if(!(statusReg & lpcDone.value)) // timer expired
    {
        TRACFCOMP(g_trac_lpc, ERR_MRK
                  "Xscom:Lpc::_rwLPC: Timed out waiting for LPC op to finish. "
                  "Status reg = 0x%016llX.",
                  statusReg);
        /*@
        * @errortype
        * @severity         ERRL_SEV_UNRECOVERABLE
        * @moduleid         LPC::MOD_XSCOMLPC_LPCRW
        * @reasoncode       LPC::RC_LPC_TIMEOUT
        * @userdata1[00:15] Read (1) or write (0)
        * @userdata1[16:31] Size of request, in bytes
        * @userdata1[32:63] Effective LPC space address
        * @userdata2        Status register
        * @devdesc          An XSCOM LPC operation timed out; resetting LPC
        *                   complex to recover.
        * @custdesc         Platform firmware detected processor-attached
        *                   low-bandwidth I/O bus related error implicating
        *                   bus endpoint, processor hardware, or platform
        *                   firmware.
        */
        pError = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            LPC::MOD_XSCOMLPC_LPCRW,
            LPC::RC_LPC_TIMEOUT,
            TWO_UINT32_TO_UINT64(
                TWO_UINT16_TO_UINT32(i_read_notwrite,io_buflen),
                xscomLpcAddr),
            statusReg,
            ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

        // In P10, alternate boot chip LPC access errors start out as predictive
        // since it's possible to boot without that chip's LPC bus
        const auto bootChipType =
            iv_proc->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();
        if(bootChipType != TARGETING::PROC_MASTER_TYPE_ACTING_MASTER)
        {
            pError->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        }

        pError->addPartCallout(iv_proc,
                               HWAS::LPC_SLAVE_PART_TYPE,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_NULL);

        pError->addPartCallout(iv_proc,
                               HWAS::PNOR_PART_TYPE,
                               HWAS::SRCI_PRIORITY_MED,
                               HWAS::NO_DECONFIG,
                               HWAS::GARD_Fatal);

        pError->addHwCallout(iv_proc,
                             HWAS::SRCI_PRIORITY_MED,
                             HWAS::NO_DECONFIG,
                             HWAS::GARD_NULL);

        pError->addClockCallout(iv_proc,
                                HWAS::LPCREFCLK_TYPE,
                                HWAS::SRCI_PRIORITY_MED);

        pError->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                    HWAS::SRCI_PRIORITY_LOW);

        pError->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_LOW);

        ERRORLOG::ErrlUserDetailsTarget(iv_proc).addToLog(pError);

        // Gather additional ffdc data, but only for the XSCOM registers
        // involved in the LPC operation (not the rest of the LPC complex)
        addFFDC(pError,true);

        pError->collectTrace(LPC_COMP_NAME,2*KILOBYTE);
        pError->collectTrace(XSCOM_COMP_NAME);

        // Reset the entire LPC complex, which will reset the entire
        // register space
        errlHndl_t pResetError = hwReset(RESET_OPB_LPCHC_HARD);
        if(pResetError)
        {
            // Already in error path, so make reset error informational
            // and remove guard/deconfig records
            pResetError->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            pResetError->plid(pError->plid());
            pResetError->removeGardAndDeconfigure();
            errlCommit(pResetError,LPC_COMP_ID);
        }

        break;
    }

    if (i_read_notwrite)
    {
        uint64_t data = 0;
        scomSize = expectedScomSize;
        pError = DeviceFW::deviceRead(
                    iv_proc,
                    &(data),
                    scomSize,
                    DEVICE_SCOM_ADDRESS(S::TP_TPBR_AD_LPC_DATA_REG));
        if(pError)
        {
            TRACFCOMP(g_trac_lpc, ERR_MRK
                      "XscomLpc::_rwLPC: Failed reading LPC data register "
                      "(0x%08X) for "
                      "read operation.",
                      S::TP_TPBR_AD_LPC_DATA_REG);
            break;
        }

        assert(scomSize == expectedScomSize,"SCOM size changed from %llu to "
               "%llu unexpectedly",expectedScomSize,scomSize);

        TRACDCOMP(g_trac_lpc, INFO_MRK
                  "XscomLpc::_rwLPC: Pre-shifted read data 0x%016llX",
                  data);

        data <<= bitOffset;

        TRACDCOMP(g_trac_lpc, INFO_MRK
                  "XscomLpc::_rwLPC: Post-shifted data 0x%016llX",
                  data);

        memcpy(io_pBuffer,&data,io_buflen);
    }

    } while(0);

    TRACDCOMP(g_trac_lpc, EXIT_MRK
              "XscomLpc::_rwLPC: completed");

    return pError;
}


errlHndl_t XscomLpc::_readLPC(
    const LPC::TransType       i_type,
    const uint32_t             i_addr,
          void*          const o_pBuffer,
          size_t&              io_buflen)
{
    errlHndl_t pError = nullptr;

    do {

    pError = _rwLPC(true,i_type,i_addr,o_pBuffer,io_buflen);
    if(pError)
    {
        break;
    }

    pError = checkForLpcErrors();

    } while(0);

    return pError;
}


errlHndl_t XscomLpc::_writeLPC(
    const LPC::TransType       i_type,
    const uint32_t             i_addr,
    const void*          const i_pBuffer,
          size_t&              io_buflen)
{
    errlHndl_t pError = nullptr;

    do {

    pError = _rwLPC(false,i_type,i_addr,const_cast<void*>(i_pBuffer),io_buflen);
    if(pError)
    {
        break;
    }

    pError = checkForLpcErrors();

    } while(0);

    return pError;
}


void XscomLpc::addFFDC(
          errlHndl_t& io_pError,
    const bool        i_timeoutDataOnly)
{
    assert(io_pError != nullptr,"Input error log was nullptr");

    errlHndl_t pError = nullptr;

    do {

    // Don't nest FFDC collection attempts
    if (iv_ffdcActive == false)
    {
        iv_ffdcActive = true;

        TRACFCOMP(g_trac_lpc,INFO_MRK "XscomLpc::addFFDC> Adding XSCOM FFDC to "
                  "error log. "
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(io_pError));

        const std::array<uint64_t,4> scomRegisterAddrs = {
            S::TP_TPBR_AD_LPC_BASE_REG,
            S::TP_TPBR_AD_LPC_CMD_REG,
            S::TP_TPBR_AD_LPC_DATA_REG,
            S::TP_TPBR_AD_LPC_STATUS_REG
        };

        ERRORLOG::ErrlUserDetailsLogRegister registerData(iv_proc);
        for(const auto &scomRegisterAddr : scomRegisterAddrs)
        {
            TRACFCOMP(g_trac_lpc,INFO_MRK "XscomLpc::addFFDC> adding reg "
                      "0x%016llX to error log",
                      scomRegisterAddr);
            registerData.addData(DEVICE_SCOM_ADDRESS(scomRegisterAddr));
        }

        if(i_timeoutDataOnly)
        {
            // Add whatever we collected to the log
            registerData.addToLog(io_pError);
            iv_ffdcActive = false;
            break;
        }

        TRACFCOMP(g_trac_lpc,INFO_MRK "XscomLpc::addFFDC> Adding LPC space "
                  "FFDC to error log. "
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(io_pError));

        // Handle different access sizes
        union LpcData
        {
            uint32_t data32;
            uint8_t  data8;

            LpcData() : data32(0) { }
        };

        for(const auto lpcErrRegAddr : cv_lpcErrRegAddrs)
        {
            LpcData data;

            // By default, all accesses are 4 bytes in size ...
            size_t buflen = sizeof(data.data32);
            void* pData = &data.data32;

            // ... except for OPB Arbiter accesses, which are 1 byte in size
            if(opbArbiterRange(lpcErrRegAddr))
            {
                buflen = sizeof(data.data8);
                pData = &data.data8;
            }

            pError = _rwLPC(true,LPC::TRANS_ERR,lpcErrRegAddr,pData,buflen);
            if(pError)
            {
                // Either a XSCOM failed or timeout occurred and whole
                // LPC complex was reset (losing all remaining FFDC).
                // Either way, it's pointless to continue.
                delete pError;
                pError=nullptr;
                break;
            }

            // If access was to the OPB Master, the result can be trusted.
            // If access was to the LPCHC or OPB Arbiter space, first
            // check for OPB errors before the result can actually be trusted
            if(!opbMasterRange(lpcErrRegAddr))
            {
                // Since the accumulated status register could already be
                // locking in an error, use the actual status which resets per
                // transaction
                pError = XscomLpc::checkAndHandleOpbmError(true);
                if(pError)
                {
                    // Any error here will prevent obtaining the rest
                    // of the FFDC, so just bail.
                    delete pError;
                    pError=nullptr;
                    break;
                }
            }

            if(opbArbiterRange(lpcErrRegAddr))
            {
                TRACFCOMP(g_trac_lpc,INFO_MRK "XscomLpc::addFFDC> adding reg "
                    "0x%016llX, value = 0x%02X to error log",
                    lpcErrRegAddr,*reinterpret_cast<uint8_t*>(pData));
            }
            else
            {
                TRACFCOMP(g_trac_lpc,INFO_MRK "XscomLpc::addFFDC> adding reg "
                    "0x%016llX, value = 0x%08X to error log",
                    lpcErrRegAddr,*reinterpret_cast<uint32_t*>(pData));
            }

            registerData.addDataBuffer(
                pData,buflen,
                DEVICE_LPC_ADDRESS(LPC::TRANS_ERR,lpcErrRegAddr));
        }

        // Add whatever we collected to the log
        registerData.addToLog(io_pError);

        // No longer in FFDC path
        iv_ffdcActive = false;
    }

    } while(0);

    if(pError)
    {
       // Already in error path, so make any errors informational
       // and remove guard/deconfig records
       pError->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
       pError->plid(io_pError->plid());
       pError->removeGardAndDeconfigure();
       errlCommit(pError,LPC_COMP_ID);
    }

    return;
}


errlHndl_t XscomLpc::checkAndHandleOpbmError(const bool i_useActual)
{
    errlHndl_t pError = nullptr;

    do {

    // LPC error registers are not modeled in SIMICS, so skip reading them in
    // that case.
    if (Util::isSimicsRunning())
    {
        break;
    }

    // Read OPB Master Accumulated Status Register
    uint32_t addr = i_useActual ?   OPBM_ACTUAL_STATUS_REG
                                  : OPBM_ACCUM_STATUS_REG;
    uint32_t opbm_buffer = 0;
    size_t buflen = sizeof(opbm_buffer);
    pError = _rwLPC(true,LPC::TRANS_ERR,addr,&opbm_buffer,buflen);
    if(pError)
    {
        // Either a SCOM error or LPC complex timeout occurred and was reset.
        // Regardless, the error status cannot be obtained.
        break;
    }

    // If there was no timeout, OPB master registers are guaranteed to have
    // been read correctly.

    // Mask error bits
    OpbmErrReg_t opbmErrUnion;
    opbmErrUnion.data32 = (opbm_buffer & LPC::OPB_ERROR_MASK);

    // Look for errors in the OPB Master Accumulated Status Register
    // bitmask
    if (opbmErrUnion.data32 != 0)
    {
        TRACFCOMP( g_trac_lpc, ERR_MRK "XscomLpc::checkAndHandleOpbmError> "
            "Error found in OPB Master Accumulated Status Register: 0x%08X",
            opbmErrUnion.data32);
        ResetLevels opbmResetLevel = RESET_CLEAR;
        computeOpbmErrSev(opbmErrUnion, opbmResetLevel);

        if(opbmResetLevel != RESET_CLEAR)
        {
            /*@
             * @errortype
             * @severity     ERRL_SEV_UNRECOVERABLE
             * @moduleid     LPC::MOD_XSCOMLPC_CHECK_OPBM_ERRORS
             * @reasoncode   LPC::RC_OPB_ERROR
             * @userdata1    OPB Master Accumulated Status Register
             * @userdata2    Reset Level
             * @devdesc      Found error(s) in OPB Master Accumulated Status
             *               Register after attempting an XSCOM LPC operation.
             * @custdesc     Platform firmware detected processor-attached
             *               low-bandwidth I/O bus related error implicating
             *               bus endpoint, processor hardware, or platform
             *               firmware.
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                LPC::MOD_XSCOMLPC_CHECK_OPBM_ERRORS,
                LPC::RC_OPB_ERROR,
                opbm_buffer,
                opbmResetLevel,
                ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

            // In P10, alternate boot chip LPC access errors start out as
            // predictive since it's possible to boot without that chip's LPC
            // bus
            const auto bootChipType =
                iv_proc->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();
            if(bootChipType != TARGETING::PROC_MASTER_TYPE_ACTING_MASTER)
            {
                pError->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            }

            pError->addPartCallout(iv_proc,
                                   HWAS::LPC_SLAVE_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            pError->addPartCallout(iv_proc,
                                   HWAS::PNOR_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_MED,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_Fatal);

            pError->addHwCallout(iv_proc,
                                 HWAS::SRCI_PRIORITY_MED,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );

            pError->addClockCallout(iv_proc,
                                    HWAS::LPCREFCLK_TYPE,
                                    HWAS::SRCI_PRIORITY_MED);

            pError->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                        HWAS::SRCI_PRIORITY_LOW);

            pError->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW);

            ERRORLOG::ErrlUserDetailsTarget(iv_proc).addToLog(pError);

            addFFDC(pError);

            pError->collectTrace(LPC_COMP_NAME,2*KILOBYTE);
            pError->collectTrace(XSCOM_COMP_NAME);

            errlHndl_t pResetError = hwReset(opbmResetLevel);
            if(pResetError)
            {
                // Already in error path, so make reset error informational
                // and remove guard/deconfig records
                pResetError->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                pResetError->plid(pError->plid());
                pResetError->removeGardAndDeconfigure();
                errlCommit(pResetError,LPC_COMP_ID);
            }

            // Entire register space is reset, so no point doing anything else
            break;
        }
    }

    } while(0);

    return pError;
}


errlHndl_t XscomLpc::checkForLpcErrors()
{
    errlHndl_t pError = nullptr;

    do {

    // LPC error registers are not modeled in SIMICS, so skip reading them in
    // that case.
    if (Util::isSimicsRunning())
    {
        break;
    }

    pError = checkAndHandleOpbmError();
    if(pError)
    {
        break;
    }

    // Read LPCHC LPCIRQ Status Register
    uint32_t addr = LPCHC_LPCIRQ_STATUS_REG;
    uint32_t lpchcBuffer = 0;
    size_t buflen = sizeof(lpchcBuffer);
    pError = _rwLPC(true,LPC::TRANS_ERR,addr,&lpchcBuffer,buflen);
    if(pError)
    {
        break;
    }

    // If the LPCHC access did not time out/error, the OPB master accumulated
    // status register must be checked (again) to make sure there were no
    // errors reading from LPCHC space!
    pError = checkAndHandleOpbmError();
    if(pError)
    {
        break;
    }

    // Mask error bits
    LpchcErrReg_t lpchcErrUnion;
    lpchcErrUnion.data32 = (lpchcBuffer & LPCHC_ERROR_MASK);

    // Check the LPC host controller bit mask, only if there are no errors
    //    from OPBM space
    if (lpchcErrUnion.data32 != 0)
    {
        TRACFCOMP(g_trac_lpc, ERR_MRK "XscomLpc::checkForLpcErrors> Error "
                  "found in LPCHC LPCIRQ Status Register: 0x%8X",
                  lpchcErrUnion.data32);

        ResetLevels lpchcResetLevel = RESET_CLEAR;
        computeLpchcErrSev(lpchcErrUnion, lpchcResetLevel);

        if(lpchcResetLevel != RESET_CLEAR)
        {
            /*@
             * @errortype
             * @severity     ERRL_SEV_UNRECOVERABLE
             * @moduleid     LPC::MOD_XSCOMLPC_CHECKFORLPCERRORS
             * @reasoncode   LPC::RC_LPCHC_ERROR
             * @userdata1    LPCHC Error Status Register
             * @userdata2    Reset Level
             * @devdesc      Error(s) found in LPCHC LPCIRQ Status Register when
             *               performing an LPC operation.
             * @custdesc     Platform firmware detected processor-attached
             *               low-bandwidth I/O bus related error implicating
             *               bus endpoint, processor hardware or platform
             *               firmware
             */
            pError = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                LPC::MOD_XSCOMLPC_CHECKFORLPCERRORS,
                LPC::RC_LPCHC_ERROR,
                lpchcBuffer,
                lpchcResetLevel,
                ERRORLOG::ErrlEntry::NO_SW_CALLOUT);

            // In P10, alternate boot chip LPC access errors start out as
            // predictive since it's possible to boot without that chip's LPC
            // bus
            const auto bootChipType =
                iv_proc->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();
            if(bootChipType != TARGETING::PROC_MASTER_TYPE_ACTING_MASTER)
            {
                pError->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            }

            pError->addPartCallout(iv_proc,
                                   HWAS::LPC_SLAVE_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            pError->addPartCallout(iv_proc,
                                   HWAS::PNOR_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_MED,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_Fatal);

            pError->addHwCallout(iv_proc,
                                 HWAS::SRCI_PRIORITY_MED,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );

            pError->addClockCallout(iv_proc,
                                    HWAS::LPCREFCLK_TYPE,
                                    HWAS::SRCI_PRIORITY_MED);

            pError->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                        HWAS::SRCI_PRIORITY_LOW);

            pError->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                        HWAS::SRCI_PRIORITY_LOW);

            ERRORLOG::ErrlUserDetailsTarget(iv_proc).addToLog(pError);

            addFFDC(pError);

            pError->collectTrace(LPC_COMP_NAME,2*KILOBYTE);
            pError->collectTrace(XSCOM_COMP_NAME);

            errlHndl_t pResetError = hwReset(lpchcResetLevel);
            if(pResetError)
            {
                // Already in error path, so make reset error informational
                // and remove guard/deconfig records
                pResetError->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                pResetError->plid(pError->plid());
                pResetError->removeGardAndDeconfigure();
                errlCommit(pResetError,LPC_COMP_ID);
            }

            // If we had to reset the entire register space is reset, so no
            // point doing anything else
            break;
        }
    }

    } while(0);

    return pError;
}


errlHndl_t XscomLpc::readLPC(
    const LPC::TransType i_type,
    const uint32_t       i_addr,
          void*    const o_pBuffer,
          size_t&        io_buflen)
{
    // Grab the lock and call the internal function
    mutex_lock(ivp_mutex);

    //First check/clear the LPC bus of errors and commit any errors found
    errlHndl_t pErrPrecheck = checkForLpcErrors();
    if (pErrPrecheck)
    {
        // Existing errors are informational only and should not create
        // guards/deconfigs
        pErrPrecheck->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        pErrPrecheck->removeGardAndDeconfigure();
    }

    errlHndl_t pErrOp = nullptr;

    size_t rem = io_buflen; // Remaining total bytes to xfer
    size_t totalRead = 0; // total amt read so far
    size_t cur = 0; // Current # bytes to move in this LPC read
    auto addr = i_addr; // Current LPC address to move from
    std::array<size_t,4> div={8,4,2,1}; // Array of divisors

    TRACDCOMP(g_trac_lpc, INFO_MRK "XscomLpc::readLPC on addr 0x%08X for "
              "%llu bytes",
              i_addr,io_buflen);

    while(rem) // While more than 0 data remains to fetch
    {
        // Loop all the alignments greatest to least
        for(size_t i=0;i<div.size();++i)
        {
            // If address aligned to this boundary, can transfer the highest
            // remaining power of two bytes <= this divisor from the remaining
            // amount
            if(addr % div[i] ==0)
            {
                // Move this many bytes
                cur = highestPowerOf2(std::min(div[i],rem));
                pErrOp = _readLPC( i_type, addr, reinterpret_cast<uint8_t*>
                    (o_pBuffer)+totalRead, cur);
                if (pErrOp)
                {
                    break;
                }

                totalRead += cur;
                rem -= cur; // Decrement remaining
                addr += cur; // Increment address same number bytes
                break;
            }
        }
        if(pErrOp)
        {
            break;
        }
    }

    // If this op failed and there was something wrong before we started,
    //  attach the logs together to aid debug
    if( pErrOp && pErrPrecheck )
    {
        pErrPrecheck->plid(pErrOp->plid());
        //Note-ideally we would up the severity of pErrPrecheck here
        // as well so that it would be visible everywhere, but we can't
        // because that breaks the scenario where the caller might want
        // to delete the log they get back (see SIO).  We don't want
        // any visible logs in that case.
    }

    if(pErrOp)
    {
        addOriginalRequestToLog(true,i_type,i_addr,io_buflen,pErrOp);
    }

    // Always just commit the log for any errors that were present
    if( pErrPrecheck )
    {
        errlCommit(pErrPrecheck, LPC_COMP_ID);
    }

    mutex_unlock(ivp_mutex);

    return pErrOp;
}


errlHndl_t XscomLpc::writeLPC(
    const LPC::TransType i_type,
    const uint32_t       i_addr,
    const void*    const i_pBuffer,
    size_t&              io_buflen)
{
    // Grab the lock and call the internal function
    mutex_lock(ivp_mutex);

    //First check/clear the LPC bus of errors and commit any errors found
    errlHndl_t pErrPrecheck = checkForLpcErrors();
    if (pErrPrecheck)
    {
        // Existing errors are informational only and should not create
        // guards/deconfigs
        pErrPrecheck->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        pErrPrecheck->removeGardAndDeconfigure();
    }

    errlHndl_t pErrOp = nullptr;

    size_t rem = io_buflen; // Remaining total bytes to write
    size_t totalWritten = 0; // total amt read so far
    size_t cur = 0; // Current # bytes to move in this LPC read
    auto addr = i_addr; // Current LPC address to move from
    std::array<size_t,4> div={8,4,2,1}; // Array of divisors

    TRACDCOMP(g_trac_lpc, ERR_MRK "XscomLpc::writeLPC on addr 0x%08X for %llu "
              "bytes",
              i_addr,io_buflen);

    while(rem) // While more than 0 data remains to fetch
    {
        // Loop all the alignments greatest to least
        for(size_t i=0;i<div.size();++i)
        {
            // If address aligned to this boundary, can transfer the highest
            // remaining power of two bytes <= this divisor from the remaining
            // amount
            if(addr % div[i] ==0)
            {
                // Transfer this many bytes
                cur = highestPowerOf2(std::min(div[i],rem));
                pErrOp = _writeLPC(i_type, addr,
                                     reinterpret_cast<const uint8_t*>(i_pBuffer)
                                   + totalWritten,
                                   cur);
                if (pErrOp)
                {
                    break;
                }

                totalWritten += cur;
                rem -= cur; // Decrement remaining
                addr += cur; // Increment address same number bytes
                break;
            }
        }
        if(pErrOp)
        {
            break;
        }
    }

    // If this op failed and there was something wrong before we started,
    //  attach the logs together to aid debug
    if( pErrOp && pErrPrecheck )
    {
        pErrPrecheck->plid(pErrOp->plid());
        //Note-ideally we would up the severity of pErrPrecheck here
        // as well so that it would be visible everywhere, but we can't
        // because that breaks the scenario where the caller might want
        // to delete the log they get back (see SIO).  We don't want
        // any visible logs in that case.
    }

    if(pErrOp)
    {
        addOriginalRequestToLog(false,i_type,i_addr,io_buflen,pErrOp);
    }

    // Always just commit the log for any errors that were present
    if( pErrPrecheck )
    {
        errlCommit(pErrPrecheck, LPC_COMP_ID);
    }

    mutex_unlock(ivp_mutex);

    return pErrOp;
}


void XscomLpc::addOriginalRequestToLog(
    const bool           i_readNotWrite,
    const LPC::TransType i_type,
    const uint32_t       i_addr,
    const size_t         i_sizeBytes,
          errlHndl_t&    io_pError) const
{
    assert(io_pError != nullptr,"Input error log handle was nullptr");

    ERRORLOG::ErrlUserDetailsStringSet originalRequest;

    originalRequest.add("R/W",i_readNotWrite ? "Read" : "Write");

    originalRequest.add("LPC type",decodeLpcType(i_type));

    // 2 char/byte + 2 char (the '0x') + 1 null byte
    char buf[  2*std::max(sizeof(i_sizeBytes),sizeof(i_addr))
             + strlen("0x")
             + 1]={0};
    sprintf(buf,"0x%08X",i_addr);
    originalRequest.add("LPC address",buf);

    sprintf(buf,"0x%016llX",i_sizeBytes);
    originalRequest.add("Size (bytes)",buf);

    originalRequest.addToLog(io_pError);
}


const char* XscomLpc::decodeLpcType(const LPC::TransType i_type) const
{
    const char* pType = "Unknown";
    auto pTypeItr = cv_lpcTypeDecoder.find(i_type);
    if(pTypeItr != cv_lpcTypeDecoder.end())
    {
        pType = pTypeItr->second;
    }
    return pType;
}

