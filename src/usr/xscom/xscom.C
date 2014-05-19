/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/xscom.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <xscom/xscomreasoncodes.H>
#include "xscom.H"
#include <assert.h>
#include <errl/errludlogregister.H>
#include <xscom/piberror.H>

// Trace definition
trace_desc_t* g_trac_xscom = NULL;
TRAC_INIT(&g_trac_xscom, XSCOM_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace XSCOM
{

// Master processor virtual address
uint64_t* g_masterProcVirtAddr = NULL;

// Max chip per node in this system
extern uint8_t getMaxChipsPerNode();
static uint8_t g_xscomMaxChipsPerNode = getMaxChipsPerNode();

// Register XSCcom access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::XSCOM,
                      TARGETING::TYPE_PROC,
                      xscomPerformOp);

uint64_t* getCpuIdVirtualAddress();
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
 * @brief Internal routine that verifies the validity of input parameters
 * for an XSCOM access.
 *
 * @param[in]   i_opType       Operation type, see DeviceFW::OperationType
 *                             in driverif.H
 * @param[in]   i_target       XSCom target
 * @param[in/out] i_buffer     Read: Pointer to output data storage
 *                             Write: Pointer to input data storage
 * @param[in/out] i_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_args         This is an argument list for DD framework.
 *                             In this function, there's only one argument,
 *                             which is the MMIO XSCom address
 * @return  errlHndl_t
 */
errlHndl_t xscomOpSanityCheck(const DeviceFW::OperationType i_opType,
                              const TARGETING::Target* i_target,
                              const void* i_buffer,
                              const size_t& i_buflen,
                              const va_list i_args)
{
    errlHndl_t l_err = NULL;

    do
    {
        // Verify data buffer
        if ( (i_buflen < XSCOM_BUFFER_SIZE) ||
             (i_buffer == NULL) )
        {
            /*@
             * @errortype
             * @moduleid     XSCOM_SANITY_CHECK
             * @reasoncode   XSCOM_INVALID_DATA_BUFFER
             * @userdata1    Buffer size
             * @userdata2    XSCom address
             * @devdesc      XSCOM buffer size < 8 bytes or NULL data buffer
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            XSCOM_SANITY_CHECK,
                                            XSCOM_INVALID_DATA_BUFFER,
                                            i_buflen,
                                            va_arg(i_args,uint64_t),
                                            true /*Add HB Software Callout*/);
            break;
        }

        // Verify OP type
        if ( (i_opType != DeviceFW::READ) &&
             (i_opType != DeviceFW::WRITE) )
        {
            /*@
             * @errortype
             * @moduleid     XSCOM_SANITY_CHECK
             * @reasoncode   XSCOM_INVALID_OP_TYPE
             * @userdata1    Operation type
             * @userdata2    XSCom address
             * @devdesc      XSCOM invalid operation type
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            XSCOM_SANITY_CHECK,
                                            XSCOM_INVALID_OP_TYPE,
                                            i_opType,
                                            va_arg(i_args,uint64_t),
                                            true /*Add HB Software Callout*/);
            break;
        }


    } while(0);

    return l_err;
}

/**
 * @brief Returns maximum processors chip per node
 *        base on system type
 *
 * @return uint8_t
 */
uint8_t getMaxChipsPerNode()
{
    uint8_t l_numOfChips = 0;

    ProcessorCoreType l_coreType = cpu_core_type();
    switch (l_coreType)
    {
        case CORE_POWER8_MURANO:
        case CORE_POWER8_VENICE:
        case CORE_UNKNOWN:
        default:
            l_numOfChips = 8;
            break;
    }
    return l_numOfChips;
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
                uint64_t* l_tempVirtAddr = getCpuIdVirtualAddress();
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
            // first XSCOM to this target so we need to calculate
            // the virtual address and save it in the xscom address attribute.
            if (o_virtAddr == NULL)
            {
                uint64_t  xscomNodeId = 0;
                uint64_t  xscomChipId = 0;

                // Get the target Node Id
                xscomNodeId =
                  i_target->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();

                // Get the target Chip Id
                xscomChipId =
                  i_target->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

                // Get system XSCOM base address
                TARGETING::TargetService& l_targetService =
                                        TARGETING::targetService();
                TARGETING::Target* l_pTopLevel = NULL;
                (void) l_targetService.getTopLevelTarget(l_pTopLevel);
                assert(l_pTopLevel != NULL);
                XSComBase_t l_systemBaseAddr =
                    l_pTopLevel->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();

                // Target's XSCOM Base address
                l_XSComBaseAddr = l_systemBaseAddr +
                    ( ( (g_xscomMaxChipsPerNode * xscomNodeId) +
                            xscomChipId ) * THIRTYTWO_GB);

                TRACFCOMP(g_trac_xscom,
                          "Target %.8X :: Node:%d Chip:%d :: XscomBase:0x%llX",
                          TARGETING::get_huid(i_target),
                          xscomNodeId,
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
                // Comment for Nick: This is a good candidate for having a way
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

    // Build the XSCom address (relative to node 0, chip 0)
    XSComP8Address l_mmioAddr(i_xscomAddr);

    // Get the offset
    uint64_t l_offset = l_mmioAddr.offset();

    // Keep MMIO access until XSCOM successfully done or error
    uint64_t l_data = 0;

    // retry counter.
    uint32_t l_retryCtr = 0;

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

        l_retryCtr++;

        // If the retry counter is a multiple of 128
        if (l_retryCtr % 128 == 0)
        {
            // print a trace message.. for debug purposes
            // incase we are stuck in a retry loop.
            TRACFCOMP(g_trac_xscom,"xscomPerformOp - RESOURCE OCCUPIED LOOP Cntr = %d: OpType 0x%.16llX, Address 0x%llX, MMIO Address 0x%llX, HMER=%.16X", l_retryCtr, static_cast<uint64_t>(i_opType), i_xscomAddr, static_cast<uint64_t>(l_mmioAddr), io_hmer.mRegister );

            // we don't want to hang forever so break out after
            //  an obscene amount of time
            if( l_retryCtr > 500000 )
            {
                TRACFCOMP( g_trac_xscom, "Giving up, we're still locked..." );
                break;
            }
        }
    } while (io_hmer.mXSComStatus == PIB::PIB_RESOURCE_OCCUPIED);


    TRACDCOMP(g_trac_xscom,"xscomPerformOp: OpType 0x%.16llX, Address 0x%llX, MMIO Address 0x%llX" static_cast<uint64_t>(i_opType),i_xscomAddr,static_cast<uint64_t>(l_mmioAddr));

    TRACDCOMP(g_trac_xscom, "xscomPerformOp: l_offset 0x%.16llX; VirtAddr %p; i_virtAddr+l_offset %p",l_offset,i_virtAddr,i_virtAddr + l_offset);

    if (i_opType == DeviceFW::READ)
    {
        TRACDCOMP(g_trac_xscom, "xscomPerformOp: Read data: %.16llx", l_data);
    }
    else
    {
        TRACDCOMP(g_trac_xscom, "xscomPerformOp: Write data: %.16llx", l_data);
    }

    do
    {
        // Handle error
        if (io_hmer.mXSComStatus != PIB::PIB_NO_ERROR)
        {
            uint64_t l_hmerVal = io_hmer;

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
                                            l_mmioAddr);
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
 * @return uint64_t* virtualAddress
 */
uint64_t* getCpuIdVirtualAddress()
{
    uint64_t* o_virtAddr = 0;

    // Get the CPU core this thread is running on
    uint32_t cpuid = task_getcpuid();

    //NNNCCCPPPPTTT format fot the cpuid..
    //  N = node, C = chip, P = proc, T = thread
    uint32_t chipId = (cpuid & 0x0380)>>7;
    uint32_t nodeId = (cpuid & 0x1C00)>>10;

    // Can change the above hardcoded values to either a macro or use
    // the info below to do the masking and shifting.
    // uint64_t max_threads = cpu_thread_count();
    // for the number of Chips  - use  g_xscomMaxChipsPerNode instead..
    // For the number of Procs.. MAX_PROCS_RSV = P8_MAX_PROCS*2
    // P8_MAX_PROCS = 8 -- space left for 2* that.

    XSComBase_t l_systemBaseAddr = MASTER_PROC_XSCOM_BASE_ADDR;

    // Target's XSCOM Base address
    XSComBase_t l_XSComBaseAddr = l_systemBaseAddr +
      ( ( (g_xscomMaxChipsPerNode * nodeId) +
          chipId ) * THIRTYTWO_GB);

    // Target's virtual address
    o_virtAddr = static_cast<uint64_t*>
      (mmio_dev_map(reinterpret_cast<void*>(l_XSComBaseAddr),
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
 *
 * @return none
 */
void resetScomEngine(TARGETING::Target* i_target,
                           uint64_t* i_virtAddr)
{
    errlHndl_t l_err = NULL;
    HMER l_hmer;
    uint64_t io_buffer = 0;
    size_t io_buflen = XSCOM_BUFFER_SIZE;
    uint64_t* l_virtAddr = 0;

    // xscom registers that need to be set.
    XscomAddrType_t XscomAddr[] = { {0x0202000F, CurThreadCpu},
                                    {0x02020007, TargetCpu},
                                    {0x02020009, TargetCpu},};

    TRACFCOMP(g_trac_xscom,"resetScomEngine: XSCOM RESET INTIATED");

    // Loop through the registers you want to write to 0
    for (int i = 0; i<3; i++)
    {
        // First address we need to read is for the Cpu that this thread is
        // running on.  Need to find the virtAddr for that CPU.
        if (XscomAddr[i].target_type == CurThreadCpu)
        {
            l_virtAddr =  getCpuIdVirtualAddress();
        }
        // The rest are xscoms are to the target cpu.
        else
        {
            l_virtAddr = i_virtAddr;
        }

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

            TRACFCOMP(g_trac_xscom,ERR_MRK "XSCOM RESET FAILED: XscomAddr = %.16llx, VAddr=%llx",XscomAddr[i], l_virtAddr );
        }

        // unmap the device now that we are done with the scom to that area.
        if (XscomAddr[i].target_type == CurThreadCpu)
        {
            mmio_dev_unmap(reinterpret_cast<void*>(l_virtAddr));
        }
    }

    return;
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

    // xscom registers that need to be set.
    XscomAddrType_t XscomAddr[4] = { {0x0202000F, CurThreadCpu},
                                     {0x02020004, TargetCpu},
                                     {0x02020007, TargetCpu},
                                     {0x02020009, TargetCpu},};


    TRACFCOMP(g_trac_xscom,"collectXscomFFDC: XSCOM COLLECT FFDC STARTED");

    // Loop through the addresses you want to collect.
    for (int i = 0; i<4; i++)
    {

        // If collecting first address, need to collect from Source Chip
        if (XscomAddr[i].target_type == CurThreadCpu)
        {
            l_virtAddr =  getCpuIdVirtualAddress();
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

        // Always want to collect the Register FFDC.  Will append to the
        // errorlog passed in by the caller and if the call got an error will
        // append to that as well.

        // Collect the data from the read
        ERRORLOG::ErrlUserDetailsLogRegister l_logReg(i_target);

        l_logReg.addDataBuffer(&io_buffer, sizeof(io_buffer),
                               DEVICE_XSCOM_ADDRESS(XscomAddr[i].addr));


        // If not successful
        if (l_err)
        {
            delete l_err;

            TRACFCOMP(g_trac_xscom,ERR_MRK "XSCOM Collect FFDC FAILED: XscomAddr = %.16llx, VAddr=%llx",XscomAddr[i], l_virtAddr);
        }
        // only add the Register data to the originating errorlog if successfull
        else
        {
            // Add the register FFDC to the errorlog passed in. DO we do this
            // all the time?  And can we log to more than one errorlog?
            l_logReg.addToLog(io_errl);
        }

        // unmap the device now that we are done with the scom to that area.
        if (XscomAddr[i].target_type == CurThreadCpu)
        {
            mmio_dev_unmap(reinterpret_cast<void*>(l_virtAddr));
        }

    }

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

    do
    {
        // XSCOM operation sanity check
        l_err = xscomOpSanityCheck(i_opType, i_target, io_buffer,
                                   io_buflen, i_args);
        if (l_err)
        {
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
        if (l_err)
        {

            // Add Callouts to the errorlog
            PIB::addFruCallouts(i_target,
                                l_hmer.mXSComStatus,
                                l_err);

            // Call XscomCollectFFDC..
            collectXscomFFDC(i_target,
                             l_virtAddr,
                             l_err);

            // reset the scomEngine.
            resetScomEngine(i_target,
                            l_virtAddr);

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

    } while (0);

    return l_err;
}

} // end namespace
