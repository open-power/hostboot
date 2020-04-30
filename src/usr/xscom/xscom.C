/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/xscom.C $                                       */
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
/**
 *  @file xscom.C
 *
 *  @brief Implementation of SCOM operations
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <sys/misc.h>
#include <sys/time.h>
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <xscom/xscomreasoncodes.H>
#include "xscom.H"
#include <assert.h>
#include <errl/errludlogregister.H>
#include <xscom/piberror.H>
#include <scom/scomif.H>
#include <arch/pirformat.H>
#include <lpc/lpcif.H>
#include <sys/mm.h>
#include <kernel/bltohbdatamgr.H>
#undef HMER // from securerom/ROM.H

using namespace TARGETING;
using namespace MEMMAP;

// Trace definition
trace_desc_t* g_trac_xscom = NULL;
TRAC_INIT(&g_trac_xscom, XSCOM_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace XSCOM
{

// Master processor virtual address
uint64_t* g_masterProcVirtAddr = NULL;

// Register XSCcom access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::XSCOM,
                      TARGETING::TYPE_PROC,
                      xscomPerformOp);

// Helper function to map in the master proc's XSCOM space
uint64_t* getCpuIdVirtualAddress( XSComBase_t& o_mmioAddr );

/**
 * @brief Internal routine that reset XSCOM status bits
 *        of HMER register before an XSCOM operation
 *
 * @return  None
 */
void resetHMERStatus()
{

    // mtspr on the HMER is an AND write.
    // This is not set the bits value to 1s, it's clearing
    // the xscom status bits while leaving the rest of the bits
    // in the register alone.
    HMER hmer(-1);

    hmer.mXSComDone = 0;
    hmer.mXSComFail = 0;
    hmer.mXSComStatus = 0;
    mmio_hmer_write(hmer);
    return;
}

/**
 * @brief Internal routine that monitor XSCOM Fail and XSCOM Done
 *        status bits of HMER register
 *
 * @return  None
 */
HMER waitForHMERStatus()
{
    HMER hmer;

    do
    {
        hmer = mmio_hmer_read();
    }
    while(!hmer.mXSComFail && !hmer.mXSComDone);
    return hmer;
}


/**
 * @brief Get the virtual address of the input target
 *        for an XSCOM access.
 *
 * Logic:
 *
 * If sentinel:
 *      If never XSCOM to sentinel
 *          Calculate virtual addr for sentinel
 *          Save it to g_masterProcVirtAddr for future XSCOM to sentinel
 *      Else
 *          Use virtual addr stored in g_masterProcVirtAddr
 *      End if
 * Else (not sentinel)
 *      If never XSCOM to this chip:
 *          If this is a master processor object
 *              Use virtual addr stored for sentinel (g_masterProcVirtAddr)
 *          Else
 *              Call mmio_dev_map() to get virtual addr for this slave proc
 *          End if
 *          Save virtual addr used to this chip's attribute
 *      Else
 *          Use virtual address stored in this chip's attributes.
 *      End if
 * End if
 *
 * @param[in]   i_target        XSCom target
 * @param[out]  o_virtAddr      Target's virtual address
 *
 * @return errlHndl_t
 */
errlHndl_t getTargetVirtualAddress(TARGETING::Target* i_target,
                                   uint64_t*& o_virtAddr)
{
    errlHndl_t l_err = NULL;
    o_virtAddr = NULL;
    XSComBase_t l_XSComBaseAddr = 0;

    do
    {

        // Find out if the target pointer is the master processor chip
        bool l_isMasterProcChip = false;

        if (i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            // Sentinel pointer representing the master processor chip
            l_isMasterProcChip = true;
        }
        else
        {
            TARGETING::Target* l_pMasterProcChip = NULL;
            TARGETING::targetService().
                masterProcChipTargetHandle(l_pMasterProcChip);

            if (i_target == l_pMasterProcChip)
            {
                // Target Service reports that this is the master processor chip
                l_isMasterProcChip = true;
            }
        }


        // If the target is the master processor chip sentinel
        if (l_isMasterProcChip)
        {

            // This is the master processor chip. The virtual address is
            // g_masterProcVirtAddr. If this is NULL then initialize it

            // Use atomic update instructions here to avoid
            // race condition between different threads.
            // Keep in mind that the mutex used in XSCOM is hardware mutex,
            // not a mutex for the whole XSCOM logic.
            if (__sync_bool_compare_and_swap(&g_masterProcVirtAddr,
                                     NULL, NULL))
            {
                // Note: can't call TARGETING code prior to PNOR being
                // brought up.
                uint64_t l_mmioAddr = 0;
                uint64_t* l_tempVirtAddr = getCpuIdVirtualAddress(l_mmioAddr);
                if (!__sync_bool_compare_and_swap(&g_masterProcVirtAddr,
                                         NULL, l_tempVirtAddr))
                {
                    // If g_masterProcVirtAddr has already been updated by
                    // another thread, we need to unmap the dev_map we just
                    // called above.
                    int rc = 0;
                    rc =  mmio_dev_unmap(reinterpret_cast<void*>
                                        (l_tempVirtAddr));
                    if (rc != 0)
                    {
                        /*@
                         * @errortype
                         * @moduleid     XSCOM_GET_TARGET_VIRT_ADDR
                         * @reasoncode   XSCOM_MMIO_UNMAP_ERR
                         * @userdata1    Return Code
                         * @userdata2    Unmap address
                         * @devdesc      mmio_dev_unmap() returns error
                         * @custdesc     A problem occurred during the IPL
                         *               of the system.
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                XSCOM_GET_TARGET_VIRT_ADDR,
                                XSCOM_MMIO_UNMAP_ERR,
                                rc,
                                reinterpret_cast<uint64_t>(l_tempVirtAddr),
                                true /*Add HB Software Callout*/);
                        break;
                    }
                }
                else
                {
                    TRACFCOMP(g_trac_xscom,
                              "Master Proc : pir=%.8X, mmio=0x%0.16llX, virt=0x%llX",
                              task_getcpuid(),
                              l_mmioAddr,
                              reinterpret_cast<uint64_t>(l_tempVirtAddr));
                }
            }

            // Set virtual address to sentinel's value
            o_virtAddr = g_masterProcVirtAddr;
        }
        else // This is not the master sentinel
        {

            // Get the virtual addr value of the chip from the virtual address
            // attribute
            o_virtAddr =
              reinterpret_cast<uint64_t*>(
                i_target->getAttr<TARGETING::ATTR_XSCOM_VIRTUAL_ADDR>());


            // If the virtual address equals NULL(default) then this is the
            // first XSCOM to this target so we need to map in the appropriate
            // address
            if (o_virtAddr == NULL)
            {
                uint8_t xscomTopoId =
                    i_target->getAttr<TARGETING::ATTR_PROC_FABRIC_TOPOLOGY_ID>();
                uint8_t xscomGroupId = 0;
                uint8_t xscomChipId = 0;
                extractGroupAndChip(xscomTopoId, xscomGroupId, xscomChipId);

                // Get assigned XSCOM base address
                l_XSComBaseAddr =
                  i_target->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();

                TRACFCOMP(g_trac_xscom,
                          "Target %.8X :: Group:%d Chip:%d :: XscomBase:0x%llX",
                          TARGETING::get_huid(i_target),
                          xscomGroupId,
                          xscomChipId,
                          l_XSComBaseAddr);

                // Target's virtual address
                o_virtAddr = static_cast<uint64_t*>
                    (mmio_dev_map(reinterpret_cast<void*>(l_XSComBaseAddr),
                      THIRTYTWO_GB));

                TRACDCOMP(g_trac_xscom, "xscomPerformOp: o_Virtual Address   =  0x%llX\n",o_virtAddr);

                // Implemented the virtual address attribute..

                // Leaving the comments as a discussion point...
                // Technically there is a race condition here. The mutex is
                // a per-hardware thread mutex, not a mutex for the whole XSCOM
                // logic. So there is possibility that this same thread is running
                // on another thread at the exact same time. We can use atomic
                // update instructions here.
                // Future note : This is a good candidate for having a way
                // to return a reference to the attribute instead of requiring
                // to call setAttr. We currently have no way to SMP-safely update
                // this attribute, where as if we had a reference to it we could use
                // the atomic update functions (_sync_bool_compare_and_swap in
                // this case.

                // Save the virtual address attribute.
                i_target->setAttr<TARGETING::ATTR_XSCOM_VIRTUAL_ADDR>(
                                        reinterpret_cast<uint64_t>(o_virtAddr));

            }
        }

    } while (0);

    return l_err;
}




/**
 * @brief Do the scom operation
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_virtAddr      XSCOM area Virtual Address space
 * @param[in]   i_xscomAddr    Xscom Address
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in/out]   io_hmer     Hmer Status - Need this returned to determine if
 *                              a retry can occur based on the failure type.

 * @return errlhndl_t
 */
errlHndl_t  xScomDoOp(DeviceFW::OperationType i_opType,
                      uint64_t* i_virtAddr,
                      uint64_t i_xscomAddr,
                      void* io_buffer,
                      size_t& io_buflen,
                      HMER &io_hmer)
{

    // Build the XSCom address (relative to group 0, chip 0)
    XSComP10Address l_mmioAddr(i_xscomAddr);

    // Get the offset
    uint64_t l_offset = l_mmioAddr.offset();

    // Keep MMIO access until XSCOM successfully done or error
    uint64_t l_data = 0;

    // retry counter.
    uint32_t l_retryCtr = 1;

    errlHndl_t l_err = NULL;

    do
    {
        // Reset status
        resetHMERStatus();

        // The dereferencing should handle Cache inhibited internally
        // Use local variable and memcpy to avoid unaligned memory access
        l_data = 0;

        if (i_opType == DeviceFW::READ)
        {
            l_data = *(i_virtAddr + l_offset);
            memcpy(io_buffer, &l_data, sizeof(l_data));
        }
        else
        {
            memcpy(&l_data, io_buffer, sizeof(l_data));
            *(i_virtAddr + l_offset) = l_data;
        }

        // Check for error or done
        io_hmer = waitForHMERStatus();


        // If the retry counter is a multiple of 128,256,512,etc.
        if (l_retryCtr % 100000 == 0)
        {
            // print a trace message.. for debug purposes
            // incase we are stuck in a retry loop.
            TRACFCOMP(g_trac_xscom,"xscomDoOp - RESOURCE OCCUPIED LOOP Cntr = %d: OpType 0x%.16llX, Address 0x%llX, MMIO Address 0x%llX, HMER=%.16X", l_retryCtr, static_cast<uint64_t>(i_opType), i_xscomAddr, static_cast<uint64_t>(l_mmioAddr), io_hmer.mRegister );

            // we don't want to hang forever so break out after
            //  an obscene amount of time
            if( l_retryCtr > 500000 )
            {
                TRACFCOMP( g_trac_xscom, "Giving up, we're still locked on 0x%.16llX...", l_offset );
                break;
            }
        }
        l_retryCtr++;
    } while (io_hmer.mXSComStatus == PIB::PIB_RESOURCE_OCCUPIED);


    TRACDCOMP(g_trac_xscom,"xscomDoOp: OpType 0x%.16llX, Address 0x%llX, MMIO Address 0x%llX", static_cast<uint64_t>(i_opType),i_xscomAddr,static_cast<uint64_t>(l_mmioAddr));

    TRACDCOMP(g_trac_xscom, "xscomDoOp: l_offset 0x%.16llX; VirtAddr %p; i_virtAddr+l_offset %p",l_offset,i_virtAddr,i_virtAddr + l_offset);

    if (i_opType == DeviceFW::READ)
    {
        TRACDCOMP(g_trac_xscom, "xscomDoOp: Read data: %.16llx", l_data);
    }
    else
    {
        TRACDCOMP(g_trac_xscom, "xscomDoOp: Write data: %.16llx", l_data);
    }

    do
    {
        // Handle error
        if (io_hmer.mXSComStatus != PIB::PIB_NO_ERROR)
        {
            uint64_t l_hmerVal = io_hmer;
            uint64_t l_fullAddr = mm_virt_to_phys(i_virtAddr + l_offset);

            TRACFCOMP(g_trac_xscom,ERR_MRK "XSCOM status error HMER: %.16llx ,XSComStatus = %llx, Addr=%llx",l_hmerVal,io_hmer.mXSComStatus, i_xscomAddr );
            /*@
             * @errortype
             * @moduleid     XSCOM_DO_OP
             * @reasoncode   XSCOM_STATUS_ERR
             * @userdata1    HMER value (piberr in bits 21:23)
             * @userdata2    XSCom address
             * @devdesc      XSCom access error
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            XSCOM_DO_OP,
                                            XSCOM_STATUS_ERR,
                                            io_hmer,
                                            l_fullAddr);
            //Note: Callouts are added by the caller if needed
        }
    }
    while (0);

    return l_err;

}

/**
 * @brief Get the Virtual Address of the XSCOM space for the processor
 *  associated with this thread (the source chip)
 *
 * @param[out] o_mmioAddr  Physical mmio address that was mapped in
 * @return uint64_t* virtualAddress
 */
uint64_t* getCpuIdVirtualAddress( XSComBase_t& o_mmioAddr )
{
    uint64_t* o_virtAddr = 0;

    // Read the MMIO setup by the SBE
    o_mmioAddr = g_BlToHbDataManager.getXscomBAR();

    // Target's virtual address
    o_virtAddr = static_cast<uint64_t*>
      (mmio_dev_map(reinterpret_cast<void*>(o_mmioAddr),
                    THIRTYTWO_GB));

    TRACDCOMP(g_trac_xscom, "getCpuIdVirtualAddress: o_Virtual Address   =  0x%llX\n",o_virtAddr);

    return o_virtAddr;

}

/**
 * @brief Reset the Scom engine regs
 *
 * @param[in]  i_target        Target of the CPU that the xscom is for
 * @param[in]  i_virtAddr      virtual address of the CPU that the xscom is
 *                             targeted for
 * @param[in]  i_mXSComStatus  The XSCOM error, from a previous XSCOM call,
 *                             that caused this method to be called.
 *
 * @return none
 */
void resetScomEngine(TARGETING::Target* i_target,
                              uint64_t* i_virtAddr,
                        const uint64_t  i_mXSComStatus)
{
    errlHndl_t l_err = NULL;
    HMER l_hmer;
    uint64_t io_buffer = 0;
    size_t io_buflen = XSCOM_BUFFER_SIZE;
    uint64_t* l_virtAddr = 0;

    // xscom registers that need to be set.
    XscomAddrType_t XscomAddr[] = {
        {0x00090018, CurThreadCpu}, //XSCOM_RCVED_STAT_REG
        {0x00090012, TargetCpu}, //XSCOM_LOG_REG
        {0x00090013, TargetCpu}, //XSCOM_ERR_REG
        {0x000A0009, TargetCpu}, //Flush stale state out of the ADU
    };

    TRACFCOMP(g_trac_xscom, ENTER_MRK"resetScomEngine");

    // Loop through the registers you want to write to 0
    for (size_t i = 0; i<(sizeof(XscomAddr)/sizeof(XscomAddr[0])); i++)
    {
        // First address we need to read is for the Cpu that this thread is
        // running on.  Need to find the virtAddr for that CPU.
        if (XscomAddr[i].target_type == CurThreadCpu)
        {
            XSComBase_t l_ignored = 0;
            l_virtAddr =  getCpuIdVirtualAddress(l_ignored);
        }
        // The rest are xscoms are to the target cpu.
        else
        {
            l_virtAddr = i_virtAddr;
        }

        if (0x000A0009 == XscomAddr[i].addr)
        {
            if (i_mXSComStatus != PIB::PIB_TIMEOUT)
            {
                // Cause of the previous error was *NOT* an HMER timeout, no need to
                // flush stale state out of the ADU.
                // Continue to next XSCOM address ...
                continue;
            }
            else
            {
                // If the XSCOM register is 0x000A0009 and the cause of error is a
                // PIB::PIB_TIMEOUT, then need to flush stale state out of the ADU.
                // This resolves issue associated with CQ:HW530410.
                TRACFCOMP(g_trac_xscom, INFO_MRK "resetScomEngine: Previous XSCOM caused a time out error, "
                                                 "flushing the stale state out of the ADU." );
            }
        } // if (0x000A0009 == XscomAddr[i].addr)

        //*********************************************************
        // Write SCOM ADDR To reset the XSCOM ENGINE
        //*********************************************************
        l_err = xScomDoOp(DeviceFW::WRITE,
                          l_virtAddr,
                          XscomAddr[i].addr,
                          &io_buffer,
                          io_buflen,
                          l_hmer);


        // If not successful
        if (l_err)
        {
            // Delete thie errorlog as this is in the errorpath already.
            delete l_err;
            l_err = nullptr;

            TRACFCOMP(g_trac_xscom, ERR_MRK "resetScomEngine: RESET FAILED: XscomAddr = %.16llx, VAddr=%llx",
                                             XscomAddr[i], l_virtAddr );
        }
        else
        {
            TRACFCOMP(g_trac_xscom, INFO_MRK "resetScomEngine: RESET SUCCEEDED: XscomAddr = %.16llx, VAddr=%llx",
                                              XscomAddr[i], l_virtAddr );
        }

        // unmap the device now that we are done with the scom to that area.
        if (XscomAddr[i].target_type == CurThreadCpu)
        {
            mmio_dev_unmap(reinterpret_cast<void*>(l_virtAddr));
        }
    } // for (size_t i = 0; i<(sizeof(XscomAddr)/sizeof(XscomAddr[0])); i++)

    TRACFCOMP(g_trac_xscom, EXIT_MRK"resetScomEngine");
}

/**
 * @brief Collect XSCOM FFDC data and add to the originating xscom failing
 *    errorlog.
 *
 * @param[in]  i_target        XSCom target
 * @param[in]  i_virtAddr      Target's virtual address
 * @param[in/out] io_errl      Originating errorlog that we will add FFDC data
 *                             to
 * @return none
 */
void collectXscomFFDC(TARGETING::Target* i_target,
                            uint64_t* i_virtAddr,
                            errlHndl_t& io_errl)
{
    errlHndl_t l_err = NULL;
    HMER l_hmer;
    uint64_t io_buffer = 0;
    size_t io_buflen = XSCOM_BUFFER_SIZE;
    uint64_t* l_virtAddr = 0;

    // xscom registers that need to be read.
    XscomAddrType_t XscomAddr[4] = {
        {0x00090018, CurThreadCpu}, //XSCOM_RCVED_STAT_REG
        {0x00090012, TargetCpu}, //XSCOM_LOG_REG
        {0x00090013, TargetCpu}, //XSCOM_ERR_REG
        {0x0009001C, TargetCpu}, //ADS_XSCOM_CMD_REG
    };


    TRACFCOMP(g_trac_xscom,"collectXscomFFDC: XSCOM COLLECT FFDC STARTED");

    ERRORLOG::ErrlUserDetailsLogRegister l_logReg(i_target);

    // Loop through the addresses you want to collect.
    for (size_t i = 0; i<(sizeof(XscomAddr)/sizeof(XscomAddr[0])); i++)
    {

        // If collecting first address, need to collect from Source Chip
        if (XscomAddr[i].target_type == CurThreadCpu)
        {
            XSComBase_t l_ignored = 0;
            l_virtAddr =  getCpuIdVirtualAddress(l_ignored);
        }
        else
        {
            l_virtAddr = i_virtAddr;
        }

        //*********************************************************
        // READ SCOM ADDR
        //*********************************************************
        l_err = xScomDoOp(DeviceFW::READ,
                          l_virtAddr,
                          XscomAddr[i].addr,
                          &io_buffer,
                          io_buflen,
                          l_hmer);

        // If not successful
        if (l_err)
        {
            delete l_err;
            l_err = nullptr;

            TRACFCOMP(g_trac_xscom,ERR_MRK "XSCOM Collect FFDC FAILED: XscomAddr = %.16llx, VAddr=%llx",XscomAddr[i], l_virtAddr);
        }
        // only add the Register data to the originating errorlog if successful
        else
        {
            // Collect the data from the read
            l_logReg.addDataBuffer(&io_buffer, sizeof(io_buffer),
                                   DEVICE_XSCOM_ADDRESS(XscomAddr[i].addr));
        }

        // unmap the device now that we are done with the scom to that area.
        if (XscomAddr[i].target_type == CurThreadCpu)
        {
            mmio_dev_unmap(reinterpret_cast<void*>(l_virtAddr));
        }

    }

    // Add the register FFDC to the errorlog passed in.
    l_logReg.addToLog(io_errl);
    return;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t xscomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    errlHndl_t l_err = NULL;
    HMER l_hmer;
    mutex_t* l_XSComMutex = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);
    uint64_t l_noErrors = va_arg(i_args,uint64_t);

    do
    {
        // XSCOM operation sanity check
        l_err = SCOM::scomOpSanityCheck(i_opType, i_target, io_buffer,
                                        io_buflen, l_addr, XSCOM_BUFFER_SIZE);
        if (l_err)
        {
            // Trace here - sanity check does not know scom type
            TRACFCOMP(g_trac_xscom,"XScom sanity check failed");
            break;
        }

        // Set to buffer len to 0 until successfully access
        io_buflen = 0;

        // Get the target chip's virtual address
        uint64_t* l_virtAddr = NULL;
        l_err = getTargetVirtualAddress(i_target, l_virtAddr);

        if (l_err)
        {
            break;
        }

        // Pin this thread to current CPU
        task_affinity_pin();

        // Lock other XSCom in this same thread from running
        l_XSComMutex = mmio_xscom_mutex();
        mutex_lock(l_XSComMutex);

        // this function will return an errorlog if bad status is detected on
        // the read or write.
        l_err = xScomDoOp(i_opType,
                          l_virtAddr,
                          l_addr,
                          io_buffer,
                          io_buflen,
                          l_hmer);

        // If we got a scom error.
        if (l_err && l_noErrors)
        {
            // ignoring errors because the caller doesn't care
            //  just return all zero data
            delete l_err;
            l_err = nullptr;
            io_buflen = XSCOM_BUFFER_SIZE;
            memset( io_buffer, 0, io_buflen );

            // still need to reset the scomEngine.
            resetScomEngine(i_target,
                            l_virtAddr,
                            l_hmer.mXSComStatus);
        }
        else if (l_err)
        {
            // Call XscomCollectFFDC..
            collectXscomFFDC(i_target,
                             l_virtAddr,
                             l_err);

            // reset the scomEngine.
            resetScomEngine(i_target,
                            l_virtAddr,
                            l_hmer.mXSComStatus);

            // Add traces to errorlog..
            l_err->collectTrace("XSCOM",1024);

        }
        else
        {
            // No error, set output buffer size.
            // Always 8 bytes for XSCOM, but we want to make it consistent
            // with all other device drivers
            io_buflen = XSCOM_BUFFER_SIZE;
        }

        // Unlock
        mutex_unlock(l_XSComMutex);

        // Done, un-pin
        task_affinity_unpin();

        // FRU callouts use targeting so this must be after the
        //  mutex is unlocked
        // Add Callouts to the errorlog
        if( l_err )
        {
            PIB::addFruCallouts(i_target,
                                l_hmer.mXSComStatus,
                                l_addr,
                                l_err);
        }
    } while (0);

    return l_err;
}

/**
 * @brief Return the value of the XSCOM BAR that the driver is using
 */
uint64_t get_master_bar( void )
{
    return mm_virt_to_phys(g_masterProcVirtAddr);
}

/**
 * @brief Generate a fully-qualified MMIO address for a physical scom
 *        address, relative to the given processor target
 */
uint64_t generate_mmio_addr( TARGETING::Target* i_proc,
                             uint64_t i_scomAddr )
{
    uint64_t l_returnAddr = 0;

    // Get the target chip's physical mmio address
    uint64_t l_XSComBaseAddr =
      i_proc->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();

    // Build the XSCom address (relative to group 0, chip 0)
    XSComP10Address l_mmioAddr(i_scomAddr);

    // Compute value relative to target chip
    l_returnAddr = l_XSComBaseAddr + l_mmioAddr;

    return l_returnAddr;
}


/**
 * @brief Read of XSCOM register on remote Node
 */
uint64_t readRemoteScom( uint64_t i_node,
                         uint64_t i_scomAddr )
{
    // definitions of 64 bit xscom address contents that are
    //   useful for this function
    //                             hi 32 bits  lo 32 bits
    //  representation :          0x0000_0000__0000_0000
    //
    //           (hi 32 bits, xscom mmio control)
    //
    //  chip field                0x0000_0400__0000_0000
    //    (to be multiplied by chip ID to give field value)
    //
    //  node/group field (0-7)    0xE000_0000__0000_0000
    //
    //           (lo 32 bits, scom addr)
    //
    //  multicast                 0x0000_0000__4000_0000
    //  multicast op type         0x0000_0000__3800_0000
    //    - read OR                            00
    //    - read AND                           08
    //    - read bitwise                       10
    //    - rsvd                               18
    //    - write compare                      20
    //    - write                              28
    //    - rsvd                               30
    //    - rsvd                               38
    //  multicast group           0x0000_0000__0700_0000
    //  relative scomAddr field   0x0000_0000__00FF_FFFF

    // Symmetry between nodes is enforced so we know the remote
    //  node contains this chip
    TARGETING::Target * l_MasterProcTarget = nullptr;
    TARGETING::Target* l_sys = nullptr;
    TARGETING::TargetService & l_tgtServ = TARGETING::targetService();
    l_tgtServ.masterProcChipTargetHandle( l_MasterProcTarget );
    l_tgtServ.getTopLevelTarget(l_sys);
    assert(l_sys, "Top lever target is nullptr!");

    const auto l_localTopoId =
        l_MasterProcTarget->getAttr<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID>();
    const auto l_topoMode =
        l_sys->getAttr<ATTR_PROC_FABRIC_TOPOLOGY_MODE>();
    uint8_t l_chipId = 0;
    uint8_t l_groupId = 0;
    extractGroupAndChip(l_localTopoId, l_groupId, l_chipId);
    const auto l_remoteTopoId = makeTopoId(l_topoMode, i_node, l_chipId);

    // compute xscom address & control
    // This will return xscom base of the remote node
    uint64_t l_xscomBaseAddr =
            computeMemoryMapOffset( MMIO_GROUP0_CHIP0_XSCOM_BASE_ADDR,
                                    l_topoMode,
                                    l_remoteTopoId);


    //Map xscom base into processor space
    uint64_t * l_virtAddr =
            static_cast<uint64_t*>
            (mmio_dev_map(reinterpret_cast<void*>(l_xscomBaseAddr),
                          THIRTYTWO_GB));

    // execute the SCOM op to do the multicast read
    // init return value to dummy to verify read happened
    uint64_t l_rv = IPC_INVALID_REMOTE_ADDR | i_node;
    size_t l_rvSize = sizeof(l_rv);
    HMER l_hmer;

    do
    {
        errlHndl_t  l_err = xScomDoOp( DeviceFW::READ,
                l_virtAddr,
                i_scomAddr,
                &l_rv,
                l_rvSize,
                l_hmer );

        // If not successful
        if (l_err)
        {
            delete l_err;
            l_err = nullptr;

            TRACFCOMP( g_trac_xscom,
                    ERR_MRK "readRemoteScom()  Read xScom Failed: "
                    "XscomAddr = %.16llx, VAddr=%llx",
                    i_scomAddr, l_virtAddr );

            // re-seed return value in case changed before error detected
            l_rv = IPC_INVALID_REMOTE_ADDR | i_node;
            break;
        }

        // regs not yet populated
        if (l_rv == 0 )
        {
          // delay to allow remote core to populate regs
          nanosleep(0, (NS_PER_MSEC * 100));
        }

        // wait for remote node to populate its core scom regs
    } while( l_rv == 0 );

    mmio_dev_unmap(reinterpret_cast<void*>(l_virtAddr));

    return l_rv;
}

} // end namespace
