/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#include <sys/mmio.h>
#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <arch/ppc.H>

#include "mmio.H"
#include <mmio/mmio.H>
#include <mmio/mmio_reasoncodes.H>

#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <error_info_defs.H>

// Trace definition
trace_desc_t* g_trac_mmio = NULL;
TRAC_INIT(&g_trac_mmio, MMIO_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace MMIO
{

// Helper function declarations (definitions at the bottom of this file)
static
TARGETING::TargetHandle_t getParentProc(TARGETING::TargetHandle_t i_target);
static
errlHndl_t getProcScom(TARGETING::TargetHandle_t i_target,
                       uint64_t i_scomAddr,
                       uint64_t &o_scomData);
static
errlHndl_t setProcScom(TARGETING::TargetHandle_t i_target,
                       uint64_t i_scomAddr,
                       uint64_t i_scomData);
static
void *mmio_memcpy(void *vdest, const void *vsrc, size_t len);


errlHndl_t mmioSetup()
{
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_mmio, ENTER_MRK"mmioSetup");
    // called from istep 12.3

    do
    {
        // Get the base BAR address for an OCMB and use it to calculate the base
        // BAR address for OCMB0 on PROC0 (beginning of reserved physical memory
        // for all OCMBs).
        // Each pair of OCMBs uses 8GB of interleaved memory,
        // the second OCMB's memory starts 2GB after the first's.
        TARGETING::TargetHandleList l_omiTargetList;

        getAllChiplets(l_omiTargetList, TARGETING::TYPE_OMI);
        if (l_omiTargetList.size() == 0)
        {
            TRACFCOMP(g_trac_mmio,
                      INFO_MRK"mmioSetup: Exiting, non-OMI system");
            break;
        }

        auto l_omi = l_omiTargetList[0];
        auto l_omiParentProc = getParentProc(l_omi);
        if (l_omiParentProc == nullptr)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                      "mmioSetup: Unable to find the parent processor for an"
                      " OMI(0x%X).",
                      l_omi->getAttr<TARGETING::ATTR_HUID>());
            /*@
             * @errortype
             * @moduleid    MMIO::MOD_MMIO_SETUP
             * @reasoncode  MMIO::RC_PROC_NOT_FOUND
             * @userdata1   Target huid
             * @userdata2   None
             * @devdesc     mmioSetup> Unable to find parent processor for OMI.
             * @custdesc    Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_SETUP,
                                    MMIO::RC_PROC_NOT_FOUND,
                                    l_omi->getAttr<TARGETING::ATTR_HUID>(),
                                    0,
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        // There's a 1:1 relationship between OMIs and OCMBs, so we can directly
        // relate the OMI position and BAR base addr to its associated OCMB.

        // Get the position of the random OCMB. (OCMBs 0-15 will be on proc0,
        // 16-31 on proc1, etc)
        auto l_ocmbPos  = l_omi->getAttr<TARGETING::ATTR_CHIP_UNIT>();
             l_ocmbPos += l_omiParentProc->getAttr<TARGETING::ATTR_POSITION>() *
                          fapi2::MAX_OMI_PER_PROC;

        // Get the base BAR address of the OCMB.
        auto l_ocmbBaseAddr =
              l_omi->getAttr<TARGETING::ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET>();

        // Calculate the base BAR address of OCMB0 on PROC0 by subtracting 8GB
        // for every pair of OCMBs beyond the first pair, and subtract an
        // additional 2GB if the initial OCMB is the second in a pair.
        l_ocmbBaseAddr -= ((l_ocmbPos / 2) * 8 * GIGABYTE) +
                          ((l_ocmbPos % 2) * 2 * GIGABYTE);

        // map 8 OCMBs at a time, set MMIO_VM_ADDR on each OCMB
        //
        // loop through all the procs
        //     call mmio_dev_map() on OCMBs 0-7 and 8-15
        //     set VM_ADDR on each OCMB
        //         each pair of OCMBs has their memories interleaved with their
        //         2GB config sections together and their 2GB mmio sections
        //         together, we will be setting VM_ADDR to point to the cfg
        //         section of each ocmb
        //         Example
        //             0GB  ocmb0 cfg
        //             2GB  ocmb1 cfg
        //             4GB  ocmb0 mmio
        //             6GB  ocmb1 mmio
        TARGETING::TargetHandleList l_procTargetList;

        getAllChips(l_procTargetList, TARGETING::TYPE_PROC);
        for (auto & l_procTarget: l_procTargetList)
        {
            // map all 16 OCMBs, 8 OCMBs (32GB) at a time
            uint64_t *l_virtAddr[2] = {nullptr};
            uint32_t  l_procNum =
                              l_procTarget->getAttr<TARGETING::ATTR_POSITION>();
            uint64_t  l_realAddr =
                              l_ocmbBaseAddr + (l_procNum * 2 * THIRTYTWO_GB);

            l_virtAddr[0] = static_cast<uint64_t *>
                         (mmio_dev_map(reinterpret_cast<void *>(l_realAddr),
                                       THIRTYTWO_GB));
            l_realAddr += THIRTYTWO_GB;
            l_virtAddr[1] = static_cast<uint64_t *>
                         (mmio_dev_map(reinterpret_cast<void *>(l_realAddr),
                                       THIRTYTWO_GB));

            // set VM_ADDR on each OCMB
            TARGETING::TargetHandleList l_ocmbTargetList;
            l_ocmbTargetList.clear();
            getChildAffinityTargets(l_ocmbTargetList, l_procTarget,
                              TARGETING::CLASS_CHIP, TARGETING::TYPE_OCMB_CHIP);
            for (auto & l_ocmbTarget: l_ocmbTargetList)
            {
                uint64_t l_ocmbVmAddr = 0;
                uint32_t l_ocmbNum =
                              l_ocmbTarget->getAttr<TARGETING::ATTR_POSITION>();

                // OCMBs 0-7 in first map, 8-15 in second map
                l_ocmbVmAddr =
                          reinterpret_cast<uint64_t>(l_virtAddr[l_ocmbNum / 8]);

                // Each pair of OCMBs uses 8GB of interleaved memory,
                // the second OCMB's memory starts 2GB after the first's
                l_ocmbVmAddr += ((l_ocmbNum / 2) * 8 * GIGABYTE) +
                                ((l_ocmbNum % 2) * 2 * GIGABYTE);

                l_ocmbTarget->
                    setAttr<TARGETING::ATTR_MMIO_VM_ADDR>(l_ocmbVmAddr);
            }
        }
    } while(0);

    TRACFCOMP(g_trac_mmio, EXIT_MRK"mmioSetup");

    return l_err;
}

// Direct OCMB reads and writes to the device's memory mapped memory.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::MMIO,
                      TARGETING::TYPE_OCMB_CHIP,
                      ocmbMmioPerformOp);

errlHndl_t ocmbMmioPerformOp(DeviceFW::OperationType   i_opType,
                             TARGETING::TargetHandle_t i_target,
                             void*   io_buffer,
                             size_t& io_buflen,
                             int64_t i_accessType,
                             va_list i_args)
{
    errlHndl_t l_err         = nullptr;
    uint64_t   l_offset      = va_arg(i_args, uint64_t);
    uint64_t   l_accessLimit = va_arg(i_args, uint64_t);

    TRACDCOMP(g_trac_mmio, ENTER_MRK"ocmbMmioPerformOp");
    TRACDCOMP(g_trac_mmio, INFO_MRK"op=%d, target=0x%.8X",
              i_opType, i_target);
    TRACDCOMP(g_trac_mmio, INFO_MRK"buffer=%p, length=%d, accessType=%ld",
              io_buffer, io_buflen, i_accessType);
    TRACDCOMP(g_trac_mmio, INFO_MRK"offset=0x%lX, accessLimit=%ld",
              l_offset, l_accessLimit);

    do
    {
        uint64_t   l_addr = i_target->getAttr<TARGETING::ATTR_MMIO_VM_ADDR>();

        if (l_addr == 0)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                           "ocmbMmioPerformOp: MMIO has not been initialized!");

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
             * @reasoncode       MMIO::RC_INVALID_SETUP
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          mmioPerformOp> A MMIO operation was attempted
             *                   before MMIO was initialized.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_INVALID_SETUP,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                      ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        if (io_buffer == nullptr)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                                   "ocmbMmioPerformOp: buffer is invalid!");

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
             * @reasoncode       MMIO::RC_INVALID_BUFFER
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          mmioPerformOp> Invalid data buffer for a MMIO
             *                   operation.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_INVALID_BUFFER,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        switch (l_accessLimit) {
            case 0:
                l_accessLimit = io_buflen; // no access size restriction
            case 4:
            case 8:
                break; // expected values
            default:
                TRACFCOMP(g_trac_mmio, ERR_MRK
                   "ocmbMmioPerformOp: accessLimit(%ld) should be 0, 4 or 8!!!",
                   l_accessLimit);

                /*@
                 * @errortype
                 * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
                 * @reasoncode       MMIO::RC_INVALID_ACCESS_LIMIT
                 * @userdata1[0:31]  Target huid
                 * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
                 *                   (allows offsets to fit in 32 bits)
                 * @userdata2[0:0]   Operation Type
                 * @userdata2[28:31] Access Limit
                 * @userdata2[32:63] Buffer Length
                 * @devdesc          mmioPerformOp> Specified access limit was
                 *                   invalid for a MMIO operation.
                 * @custdesc         Unexpected memory subsystem firmware error.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_INVALID_ACCESS_LIMIT,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
        }

        if (l_err)
        {
            break;
        }

        if (io_buflen < l_accessLimit)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                           "ocmbMmioPerformOp: buffer is too small for the"
                           " request, buflen=%d, accessLimit=%ld",
                           io_buflen, l_accessLimit);

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
             * @reasoncode       MMIO::RC_INSUFFICIENT_BUFFER
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          mmioPerformOp> Data buffer too small for a
             *                   MMIO operation.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_INSUFFICIENT_BUFFER,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        if (io_buflen % l_accessLimit)
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                                   "ocmbMmioPerformOp: buffer length must be a"
                                   " multiple of the access limit,"
                                   " buflen=%d, accessLimit=%ld",
                                   io_buflen, l_accessLimit);

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
             * @reasoncode       MMIO::RC_INCORRECT_BUFFER_LENGTH
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          mmioPerformOp> Buffer length not a multiple
             *                                  of access limit.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_INCORRECT_BUFFER_LENGTH,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        if (!(((l_offset >= 0) && (l_offset < (2 * GIGABYTE))) ||
              ((l_offset >= (4 * GIGABYTE)) && (l_offset < (6 * GIGABYTE)))))
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                                   "ocmbMmioPerformOp: offset(0x%lX) must be"
                                   " either 0-2G or 4G-6G!",
                                   l_offset);

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
             * @reasoncode       MMIO::RC_INVALID_OFFSET
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          mmioPerformOp> Invalid offset, requested
             *                   address was out of range for a MMIO operation.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_INVALID_OFFSET,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        if ( ((l_accessLimit == 4) || (l_accessLimit == 8)) &&
             ((l_offset % l_accessLimit) != 0) )
        {
            TRACFCOMP(g_trac_mmio, ERR_MRK
                 "ocmbMmioPerformOp: offset must be aligned with access limit,"
                 " offset=0x%lX, accessLimit=%ld",
                 l_offset, l_accessLimit);

            /*@
             * @errortype
             * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
             * @reasoncode       MMIO::RC_INVALID_OFFSET_ALIGNMENT
             * @userdata1[0:31]  Target huid
             * @userdata1[32:63] Data Offset, if >= 4GB then subtract 2GB
             *                   (allows offsets to fit in 32 bits)
             * @userdata2[0:0]   Operation Type
             * @userdata2[28:31] Access Limit
             * @userdata2[32:63] Buffer Length
             * @devdesc          mmioPerformOp> Requested MMIO address was not
             *                   aligned properly for the associated device.
             * @custdesc         Unexpected memory subsystem firmware error.
             */
            l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_INVALID_OFFSET_ALIGNMENT,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);

            break;
        }

        // TODO RTC 201493 - Remove these consts once HW group has defined them.
        static const uint8_t P9A_MC_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION = 20;
        static const uint8_t P9A_MC_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION = 21;

        // read or write io_buflen bytes, l_accessLimit bytes at a time
        uint8_t *mm_ptr = reinterpret_cast<uint8_t *>(l_addr + l_offset);
        uint8_t *io_ptr = reinterpret_cast<uint8_t *>(io_buffer);
        size_t   bytes_read_or_written = 0;
        for (size_t i = 0;i < io_buflen;i += l_accessLimit)
        {
            if (i_opType == DeviceFW::READ)
            {
                mmio_memcpy(io_ptr + i, mm_ptr + i, l_accessLimit);
                eieio();
                if (!memcmp(io_ptr + i,
                            &MMIO_OCMB_UE_DETECTED,
                            sizeof(MMIO_OCMB_UE_DETECTED)))
                {
                    uint64_t   scom_data = 0;
                    uint64_t   scom_mask = 0;

                    TRACFCOMP(g_trac_mmio, ERR_MRK
                                     "ocmbMmioPerformOp: unable to complete"
                                     " MMIO read, SUE detected");

                    /*@
                     * @errortype
                     * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
                     * @reasoncode       MMIO::RC_BAD_MMIO_READ
                     * @userdata1[0:31]  Target huid
                     * @userdata1[32:63] Data Offset, if >= 4GB then subtract
                     *                   2GB (allows offsets to fit in 32 bits)
                     * @userdata2[0:0]   Operation Type
                     * @userdata2[28:31] Access Limit
                     * @userdata2[32:63] Buffer Length
                     * @devdesc          mmioPerformOp> MMIO read of an OCMB
                     *                                  failed.
                     * @custdesc         Unexpected memory subsystem firmware
                     *                   error.
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_BAD_MMIO_READ,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                    // add OCMB to error log
                    l_err->addHwCallout(i_target,
                                        HWAS::SRCI_PRIORITY_HIGH,
                                        HWAS::DECONFIG,
                                        HWAS::GARD_NULL);
                    l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                               HWAS::SRCI_PRIORITY_LOW);
                    const auto plid = l_err->plid();

                    auto l_err2 = getProcScom(i_target,
                                              P9A_MCC_USTLFIR,
                                              scom_data);
                    if (l_err2)
                    {
                        l_err2->plid(plid);
                        errlCommit(l_err2, MMIO_COMP_ID);
                    }
                    else
                    {
                        scom_mask = (1ull << P9A_MC_USTLFIR_CHANA_BAD_DATA) |
                                    (1ull << P9A_MC_USTLFIR_CHANB_BAD_DATA);
                        if (scom_data & scom_mask)
                        {
                            // TODO RTC 201588 - Error checking on Explorer side
                            TRACFCOMP(g_trac_mmio, ERR_MRK
                                   "ocmbMmioPerformOp: there was an error on"
                                   " the Explorer side, P9A_MCC_USTLFIR=0x%lX",
                                   scom_data);

                            // Clear FIR bits
                            scom_data &= ~scom_mask;
                            l_err2 = setProcScom(i_target,
                                                P9A_MCC_USTLFIR,
                                                scom_data);
                            if (l_err2)
                            {
                                l_err2->plid(plid);
                                errlCommit(l_err2, MMIO_COMP_ID);
                            }
                        }
                    }

                    l_err2 = getProcScom(i_target,
                                         P9A_MCC_DSTLFIR,
                                         scom_data);
                    if (l_err2)
                    {
                        l_err2->plid(plid);
                        errlCommit(l_err2, MMIO_COMP_ID);
                    }
                    else
                    {
                        scom_mask =
                             (1ull << P9A_MC_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION) |
                             (1ull << P9A_MC_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION);
                        if (scom_data & scom_mask)
                        {
                            // A channel checkstop has occurred.
                            // TODO RTC 201778 - Channel Fail Handling for
                            //                   Explorer
                            TRACFCOMP(g_trac_mmio, ERR_MRK
                                 "ocmbMmioPerformOp: there was an error on"
                                 " the Explorer channel, P9A_MCC_DSTLFIR=0x%lX",
                                 scom_data);
                        }
                    }

                    break;
                }
            }
            else if (i_opType == DeviceFW::WRITE)
            {
                mmio_memcpy(mm_ptr + i, io_ptr + i, l_accessLimit);
                eieio();

                // TODO RTC 201901 - find a better OCMB register to read, should
                //                   be able to optimize error handling.

                // do a read on the OCMB after writing to it, since writes and
                // reads are sequential, the read won't complete until after the
                // write.
                uint64_t scom_addr = (4 * GIGABYTE) + 4; // RTC 201901
                uint8_t l_ocmbReg[8] = {0};

                mmio_memcpy(l_ocmbReg, mm_ptr + scom_addr, sizeof(l_ocmbReg));
                eieio();
                if (!memcmp(io_ptr + i,
                            &MMIO_OCMB_UE_DETECTED,
                            sizeof(MMIO_OCMB_UE_DETECTED)))
                {
                    uint64_t scom_data = 0;
                    uint64_t scom_mask = 0;

                    TRACFCOMP(g_trac_mmio, ERR_MRK
                                    "ocmbMmioPerformOp: unable to complete MMIO"
                                    " write, SUE detected");

                    /*@
                     * @errortype
                     * @moduleid         MMIO::MOD_MMIO_PERFORM_OP
                     * @reasoncode       MMIO::RC_BAD_MMIO_WRITE
                     * @userdata1[0:31]  Target huid
                     * @userdata1[32:63] Data Offset, if >= 4GB then subtract
                     *                   2GB (allows offsets to fit in 32 bits)
                     * @userdata2[0:0]   Operation Type
                     * @userdata2[28:31] Access Limit
                     * @userdata2[32:63] Buffer Length
                     * @devdesc          mmioPerformOp> MMIO write of an OCMB
                     *                   failed.
                     * @custdesc         Unexpected memory subsystem firmware
                     *                   error.
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    MMIO::MOD_MMIO_PERFORM_OP,
                                    MMIO::RC_BAD_MMIO_WRITE,
                                    TWO_UINT32_TO_UINT64(
                                      i_target->getAttr<TARGETING::ATTR_HUID>(),
                                      (l_offset < (4 * GIGABYTE)) ?
                                                   (l_offset) :
                                                   (l_offset - (2 * GIGABYTE))),
                                    TWO_UINT32_TO_UINT64(
                                      (i_opType << 31) | l_accessLimit,
                                      io_buflen),
                                    ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                    // add OCMB to error log
                    l_err->addHwCallout(i_target,
                                        HWAS::SRCI_PRIORITY_HIGH,
                                        HWAS::DECONFIG,
                                        HWAS::GARD_NULL);
                    l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                               HWAS::SRCI_PRIORITY_LOW);
                    const auto plid = l_err->plid();

                    auto l_err2 = getProcScom(i_target,
                                              P9A_MCC_DSTLFIR,
                                              scom_data);
                    if (l_err2)
                    {
                        l_err2->plid(plid);
                        errlCommit(l_err2, MMIO_COMP_ID);
                    }
                    else
                    {
                        scom_mask =
                             (1ull << P9A_MC_DSTLFIR_SUBCHANNEL_A_FAIL_ACTION) |
                             (1ull << P9A_MC_DSTLFIR_SUBCHANNEL_B_FAIL_ACTION);
                        if (scom_data & scom_mask)
                        {
                            // A channel checkstop has occurred.
                            // TODO RTC 201778 - Channel Fail Handling for
                            //                   Explorer
                            TRACFCOMP(g_trac_mmio, ERR_MRK
                                 "ocmbMmioPerformOp: there was an error on"
                                 " the Explorer channel, P9A_MCC_DSTLFIR=0x%lX",
                                 scom_data);
                        }
                    }

                    break;
                }
            }

            bytes_read_or_written += l_accessLimit;
        }

        io_buflen = bytes_read_or_written;
    } while(0);

    if (l_err)
    {
        l_err->collectTrace(MMIO_COMP_NAME);
    }

    TRACDCOMP(g_trac_mmio, EXIT_MRK"mmioPerformOp");

    return l_err;
}

static
TARGETING::TargetHandle_t getParentProc(TARGETING::TargetHandle_t i_target)
{
    TARGETING::TargetHandle_t   proc = nullptr;
    TARGETING::TargetHandleList list;
    TARGETING::PredicateCTM     pred(TARGETING::CLASS_CHIP,
                                     TARGETING::TYPE_PROC);

    TARGETING::targetService().getAssociated(
                                   list,
                                   i_target,
                                   TARGETING::TargetService::PARENT_BY_AFFINITY,
                                   TARGETING::TargetService::ALL,
                                   &pred);

    if (list.size() == 1)
    {
        proc = list[0];
    }

    return proc;
}

static
errlHndl_t getProcScom(TARGETING::TargetHandle_t i_target,
                       uint64_t i_scomAddr,
                       uint64_t &o_scomData)
{
    errlHndl_t l_err = nullptr;
    auto proc = getParentProc(i_target);

    if (proc == nullptr)
    {
        TRACFCOMP(g_trac_mmio, ERR_MRK
                "getProcScom: Unable to find parent processor for target(0x%X)",
                i_target->getAttr<TARGETING::ATTR_HUID>());

        /*@
         * @errortype
         * @moduleid    MMIO::MOD_MMIO_GET_PROC_SCOM
         * @reasoncode  MMIO::RC_PROC_NOT_FOUND
         * @userdata1   Target huid
         * @userdata2   SCOM address
         * @devdesc     getProcScom> Unable to find parent processor for target.
         * @custdesc    Unexpected memory subsystem firmware error.
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                MMIO::MOD_MMIO_GET_PROC_SCOM,
                                MMIO::RC_PROC_NOT_FOUND,
                                i_target->getAttr<TARGETING::ATTR_HUID>(),
                                i_scomAddr,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
    else
    {
        auto reqSize = sizeof(o_scomData);

        l_err = DeviceFW::deviceRead(proc,
                                     &o_scomData,
                                     reqSize,
                                     DEVICE_SCOM_ADDRESS(i_scomAddr));
    }

    return l_err;
}

static
errlHndl_t setProcScom(TARGETING::TargetHandle_t i_target,
                       uint64_t i_scomAddr,
                       uint64_t i_scomData)
{
    errlHndl_t l_err = nullptr;
    auto proc = getParentProc(i_target);

    if (proc == nullptr)
    {
        TRACFCOMP(g_trac_mmio, ERR_MRK
                "setProcScom: Unable to find parent processor for target(0x%X)",
                i_target->getAttr<TARGETING::ATTR_HUID>());

        /*@
         * @errortype
         * @moduleid    MMIO::MOD_MMIO_SET_PROC_SCOM
         * @reasoncode  MMIO::RC_PROC_NOT_FOUND
         * @userdata1   Target huid
         * @userdata2   SCOM address
         * @devdesc     setProcScom> Unable to find parent processor for target.
         * @custdesc    Unexpected memory subsystem firmware error.
         */
        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                MMIO::MOD_MMIO_SET_PROC_SCOM,
                                MMIO::RC_PROC_NOT_FOUND,
                                i_target->getAttr<TARGETING::ATTR_HUID>(),
                                i_scomAddr,
                                ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
    }
    else
    {
        auto reqSize = sizeof(i_scomData);

        l_err = DeviceFW::deviceWrite(proc,
                                      &i_scomData,
                                      reqSize,
                                      DEVICE_SCOM_ADDRESS(i_scomAddr));
    }

    return l_err;
}

static
void *mmio_memcpy(void *vdest, const void *vsrc, size_t len)
{
    assert((len % 4) == 0, "Length must be a multiple of 4!");
    assert((reinterpret_cast<uintptr_t>(vdest) % 4) == 0,
           "Destination must be 4 byte aligned!");

    // Loop, copying 8 bytes every 5 instructions
    long *ldest = reinterpret_cast<long *>(vdest);
    const long *lsrc = reinterpret_cast<const long *>(vsrc);

    while (len >= sizeof(long))
    {
        *ldest++ = *lsrc++;
        len -= sizeof(long);
    }

    // Loop, copying 4 bytes every 5 instructions
    int *idest = reinterpret_cast<int *>(ldest);
    const int *isrc = reinterpret_cast<const int *>(lsrc);

    while (len >= sizeof(int))
    {
        *idest++ = *isrc++;
        len -= sizeof(int);
    }

    return vdest;
}

}; // end namespace MMIO
