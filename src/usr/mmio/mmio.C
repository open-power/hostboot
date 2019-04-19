/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include <errl/errludtarget.H>
#include <targeting/common/predicates/predicates.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <arch/memorymap.H>
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

#define OMI_PER_MC 8

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
    // called after OMI bars have been written to HW registers
    do
    {
        // map 8 OCMBs at a time, set MMIO_VM_ADDR on each OCMB
        //
        // loop through all the Memory Channels (MC Targets)
        //     call allocate of 32 GB virtual memory space with mmio_dev_map() for each MC
        TARGETING::TargetHandleList l_mcTargetList;
        getAllChiplets(l_mcTargetList, TARGETING::TYPE_MC);

        for (auto & l_mcTarget: l_mcTargetList)
        {
            uint32_t  l_mcChipUnit =
                              l_mcTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            // Get the base BAR address for OpenCapi Memory Interfaces (OMIs) of this Memory Controller (MC)
            auto l_omiBaseAddr =
                  l_mcTarget->getAttr<TARGETING::ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET>();

            // Apply the MMIO base offset so we get the real address
            uint64_t  l_realAddr = ( l_omiBaseAddr | MMIO_BASE );

            // Map the device with a kernal call, each device, the MC,  is 32 GB
            uint64_t l_virtAddr = reinterpret_cast<uint64_t>
                         (mmio_dev_map(reinterpret_cast<void *>(l_realAddr),
                                       THIRTYTWO_GB));

            TRACFCOMP ( g_trac_mmio, "MC%.02X (0x%.08X) MMIO BAR PHYSICAL ADDR = 0x%lX     VIRTUAL ADDR = 0x%lX" ,
                        l_mcChipUnit ? 0x23 : 0x01, TARGETING::get_huid(l_mcTarget),
                        l_realAddr, l_virtAddr);

            // set VM_ADDR on each OCMB
            TARGETING::TargetHandleList l_omiTargetList;
            getChildChiplets(l_omiTargetList, l_mcTarget, TARGETING::TYPE_OMI);

            for (auto & l_omiTarget: l_omiTargetList)
            {
                // ATTR_CHIP_UNIT is relative to other OMI under this PROC
                uint32_t l_omiChipUnit =
                              l_omiTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                // Get the OMI position relative to other OMIs under its parent MC chiplet
                uint32_t l_omiPosRelativeToMc = l_omiChipUnit % OMI_PER_MC;

                // Calculate what we think the real address for this OCMB should be. This should
                // match what the ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET attribute is set to.

                // Each Memory Controller Channel (MCC) uses 8 GB of Memory Mapped IO, 4 GB for each of its child OCMBs.
                // Each OCMB has 2 MMIO distinct spaces that get mapped. The CONFIG space, and the MMIO space. The CONFIG
                // Space is always before the MMIO space we will treat that as the BAR for the OCMB target. These
                // paired OCMB spaces get interleaved as follows :
                //       ocmb  |  BAR ATTRIBUTE     | Type | Base reg           - end addr           | size | sub-ch
                //       +-----+--------------------+------+-----------------------------------------+------+-------
                //       ocmb0 | 0x0006030200000000 | cnfg | 0x0006030200000000 - 0x000603027FFFFFFF | 2GB  | 0
                //       ocmb1 | 0x0006030280000000 | cnfg | 0x0006030280000000 - 0x00060302FFFFFFFF | 2GB  | 1
                //       ocmb0 | N/A                | mmio | 0x0006030300000000 - 0x000603037FFFFFFF | 2GB  | 0
                //       ocmb1 | N/A                | mmio | 0x0006030380000000 - 0x00060303FFFFFFFF | 2GB  | 1
                //       +-----+--------------------+------+-----------------------------------------+------+-------

                // Calculate CNFG space BAR to write to OCMB attribute
                uint64_t l_currentOmiOffset = (( l_omiPosRelativeToMc / 2) * 8 * GIGABYTE) +
                                              (( l_omiPosRelativeToMc % 2) * 2 * GIGABYTE);

                // Calculated real address for this OMI is (BAR from MC attribute) + (currentOmiOffset)
                uint64_t l_calulatedRealAddr = l_omiBaseAddr + l_currentOmiOffset;

                // Grab bar value from attribute to verify it matches our calculations
                auto l_omiBarAttrVal = l_omiTarget->getAttr<TARGETING::ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET>();

                if(l_omiBarAttrVal != l_calulatedRealAddr)
                {
                    TRACFCOMP(g_trac_mmio,
                              "Discrepancy found between calculated OMI MMIO bar offset and what we found in ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET");
                    TRACFCOMP(g_trac_mmio, "Calculated Offset: 0x%lX,  Attribute Value : 0x%lX", l_calulatedRealAddr, l_omiBarAttrVal);

                    /*@
                    * @errortype   ERRORLOG::ERRL_SEV_UNRECOVERABLE
                    * @moduleid    MMIO::MOD_MMIO_SETUP
                    * @reasoncode  MMIO::RC_BAR_OFFSET_MISMATCH
                    * @userdata1   Calculated Bar Offset
                    * @userdata2   Bar offset from attribute
                    * @devdesc     mmioSetup> Mismatch between calculated map value
                    *              and what is in attribute xml
                    * @custdesc    Unexpected memory subsystem firmware error.
                    */
                    l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            MMIO::MOD_MMIO_SETUP,
                                            MMIO::RC_BAR_OFFSET_MISMATCH,
                                            l_calulatedRealAddr,
                                            l_omiBarAttrVal,
                                            ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                    l_err->collectTrace( MMIO_COMP_NAME);
                    ERRORLOG::ErrlUserDetailsTarget(l_omiTarget).addToLog(l_err);

                    break;
                }


                uint64_t l_currentOmiVirtAddr = l_virtAddr + l_currentOmiOffset;

                // set VM_ADDR the associated OCMB
                TARGETING::TargetHandleList l_ocmbTargetList;
                getChildAffinityTargets(l_ocmbTargetList, l_omiTarget,
                                  TARGETING::CLASS_CHIP, TARGETING::TYPE_OCMB_CHIP);

                assert(l_ocmbTargetList.size() == 1 , "OCMB chips list found for a given OMI != 1 as expected");

                TRACFCOMP(g_trac_mmio, "Setting HUID 0x%.08X MMIO vm addr to be 0x%lX , real address is 0x%lX", TARGETING::get_huid(l_ocmbTargetList[0]),
                        l_currentOmiVirtAddr, l_calulatedRealAddr | MMIO_BASE );

                l_ocmbTargetList[0]->setAttr<TARGETING::ATTR_MMIO_VM_ADDR>(l_currentOmiVirtAddr);
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
              i_opType, TARGETING::get_huid(i_target));
    TRACDCOMP(g_trac_mmio, INFO_MRK"buffer=%p, length=%d, accessType=%ld",
              io_buffer, io_buflen, i_accessType);
    TRACDCOMP(g_trac_mmio, INFO_MRK"offset=0x%lX, accessLimit=%ld",
              l_offset, l_accessLimit);

    do
    {
        uint64_t   l_addr = i_target->getAttr<TARGETING::ATTR_MMIO_VM_ADDR>();

        TRACDCOMP(g_trac_mmio, INFO_MRK"MMIO Op l_addr=0x%lX ", l_addr);

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
