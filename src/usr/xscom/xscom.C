//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/xscom/xscom.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
#include <targeting/targetservice.H>
#include <xscom/xscomreasoncodes.H>
#include "xscom.H"
#include <assert.h>

// Trace definition
trace_desc_t* g_trac_xscom = NULL;
TRAC_INIT(&g_trac_xscom, "XSCOM", 4096);

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
 * @brief Internal routine that checks to see if retry is
 *        possible on an XSCOM error
 *
 * @return  true if retry is possible; false otherwise.
 */
bool XSComRetry(const HMER i_hmer)
{
    bool l_retry = false;
    switch (i_hmer.mXSComStatus)
    {
        // Should retry if parity or timeout error.
        case HMER::XSCOM_PARITY_ERROR:
        case HMER::XSCOM_TIMEOUT:
             l_retry = true;
             break;
        default:
             break;
    }
    return l_retry;
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
                                            va_arg(i_args,uint64_t));
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
                                            va_arg(i_args,uint64_t));
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
    //@todo - Need to verify if this number is correct
    // for both Salerno and Venice
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
 *              @todo:
 *              Currently virt addr attribute is not supported, so we
 *              must call unmap in xscomPerfomOp function once the
 *              xscom operation is done.
 *              When virt addr attribute is supported, the code that saves
 *              virt addr code in this function will be uncommented,
 *              and the mmio_dev_unmap() call in xscomPerformOp()
 *              function must be removed.
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
errlHndl_t getTargetVirtualAddress(const TARGETING::Target* i_target,
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

        // Figure out the virtual address
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
                l_XSComBaseAddr = MASTER_PROC_XSCOM_BASE_ADDR;
                uint64_t* l_tempVirtAddr =  static_cast<uint64_t*>
                    (mmio_dev_map(reinterpret_cast<void*>(l_XSComBaseAddr),
                    THIRTYTWO_GB));
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
                                reinterpret_cast<uint64_t>(l_tempVirtAddr));
                        break;
                    }
                }
            }

            // Set virtual address to sentinel's value
            o_virtAddr = g_masterProcVirtAddr;
        }
        else
        {
            // This is not the master processor chip

            // @todo:
            // We (Nick/Patrick/Thi) agree to review the performance cost of
            // map/unmap calls for each xscom to determine if it's justified
            // to add virtual address as one of the chip's attributes.
            // For now, call map/unmap to get virtual address.
            // If virtual address attribute is implemented, call the target
            // to get it
            // Get the virtual addr value of the chip
            // l_virtAddr = i_target->getAttr<TARGETING::<ATTR_VIRTUAL_ADDR>();

            // If virtual addr value is NULL, need to calculate it
            if (o_virtAddr == NULL)
            {
                // Get the target chip info
                TARGETING::XscomChipInfo l_xscomChipInfo = {0};
                l_xscomChipInfo =
                        i_target->getAttr<TARGETING::ATTR_XSCOM_CHIP_INFO>();
                //@todo
                // Save the node id of the master chip in a global as well and
                // update it. For Rainer systems the node id of the master chip may
                // not be 0 if it is on a second node.

                // Get system XSCOM base address
                // Note: can't call TARGETING code prior to PNOR being
                // brought up.
                TARGETING::TargetService& l_targetService =
                                        TARGETING::targetService();
                TARGETING::Target* l_pTopLevel = NULL;
                (void) l_targetService.getTopLevelTarget(l_pTopLevel);
                assert(l_pTopLevel != NULL);
                XSComBase_t l_systemBaseAddr =
                    l_pTopLevel->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();

                // Target's XSCOM Base address
                l_XSComBaseAddr = l_systemBaseAddr +
                    ( ( (g_xscomMaxChipsPerNode * l_xscomChipInfo.nodeId) +
                            l_xscomChipInfo.chipId ) * THIRTYTWO_GB);

                // Target's virtual address
                o_virtAddr = static_cast<uint64_t*>
                    (mmio_dev_map(reinterpret_cast<void*>(l_XSComBaseAddr),
                      THIRTYTWO_GB));

                // @todo - Save as an attribute if Virtual address attribute
                // is implemented,
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
                // i_target->setAttr<ATTR_VIRTUAL_ADDR>(l_virtAddr);
            }
        }

    } while (0);

    return l_err;
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
    mutex_t* l_XSComMutex;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    //@todo - Override the target to be the master sentinel
    i_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

    // Retry loop
    bool l_retry = false;
    uint8_t l_retryCtr = 0;
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

        // Re-init l_retry for loop
        l_retry = false;

        // Pin this thread to current CPU
        task_affinity_pin();

        // Lock other XSCom in this same thread from running
        l_XSComMutex = mmio_xscom_mutex();
        mutex_lock(l_XSComMutex);

        // Get the target chip's virtual address
        uint64_t* l_virtAddr = NULL;
        l_err = getTargetVirtualAddress(i_target, l_virtAddr);
        if (l_err)
        {
            // Unlock
            mutex_unlock(l_XSComMutex);
            // Done, un-pin
            task_affinity_unpin();
            break;
        }

        // Build the XSCom address (relative to node 0, chip 0)
        XSComP8Address l_mmioAddr(l_addr);

        // Get the offset
        uint64_t l_offset = l_mmioAddr.offset();

        TRACDCOMP(g_trac_xscom, "xscomPerformOp: OpType 0x%.16llX, Address 0x%llX, l_virtAddr+l_offset %p",
          static_cast<uint64_t>(i_opType),
          l_addr,
          l_virtAddr + l_offset);

        // Keep MMIO access until XSCOM successfully done or error
        uint64_t l_data = 0;
        do
        {
            // Reset status
            resetHMERStatus();

            // The dereferencing should handle Cache inhibited internally
            // Use local variable and memcpy to avoid unaligned memory access
            l_data = 0;

            if (i_opType == DeviceFW::READ)
            {
                 l_data = *(l_virtAddr + l_offset);
                 memcpy(io_buffer, &l_data, sizeof(l_data));
            }
            else
            {
                memcpy(&l_data, io_buffer, sizeof(l_data));
                *(l_virtAddr + l_offset) = l_data;
            }

            // Check for error or done
            l_hmer = waitForHMERStatus();

        } while (l_hmer.mXSComStatus == HMER::XSCOM_BLOCKED);


        // @todo: this block of code is to un-map the slave devices.
        //        It should be removed if Virtual Addr attribute
        //        is supported (since we only map it once then cache
        //        the virtual addr value
        if (i_target != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* l_masterProcTarget = NULL;
            TARGETING::TargetService& l_targetService =
                                        TARGETING::targetService();
            l_targetService.masterProcChipTargetHandle( l_masterProcTarget );
            if (l_masterProcTarget != i_target)
            {
                int rc = 0;
                rc =  mmio_dev_unmap(reinterpret_cast<void*>(l_virtAddr));
                if (rc != 0)
                {
                    /*@
                     * @errortype
                     * @moduleid     XSCOM_PERFORM_OP
                     * @reasoncode   XSCOM_MMIO_UNMAP_ERR
                     * @userdata1    Return Code
                     * @userdata2    Unmap address
                     * @devdesc      mmio_dev_unmap() returns error
                     */
                    l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            XSCOM_PERFORM_OP,
                            XSCOM_MMIO_UNMAP_ERR,
                            rc,
                            reinterpret_cast<uint64_t>(l_virtAddr));

                    // Unlock
                    mutex_unlock(l_XSComMutex);
                    // Done, un-pin
                    task_affinity_unpin();
                    break;
                }
            }
        }

        // Unlock
        mutex_unlock(l_XSComMutex);

        // Done, un-pin
        task_affinity_unpin();

        TRACDCOMP(g_trac_xscom, "xscomPerformOp: OpType 0x%.16llX, Address 0x%llX, MMIO Address 0x%llX",
                       static_cast<uint64_t>(i_opType),
                       l_addr,
                       static_cast<uint64_t>(l_mmioAddr));
        TRACDCOMP(g_trac_xscom, "xscomPerformOp: l_offset 0x%.16llX; VirtAddr %p; l_virtAddr+l_offset %p",
                       l_offset,
                       l_virtAddr,
                       l_virtAddr + l_offset);

        if (i_opType == DeviceFW::READ)
        {
            TRACDCOMP(g_trac_xscom, "xscomPerformOp: Read data: %.16llx", l_data);        }
        else
        {
            TRACDCOMP(g_trac_xscom, "xscomPerformOp: Write data: %.16llx", l_data);
        }

        // Handle error
        if (l_hmer.mXSComStatus != HMER::XSCOM_GOOD)
        {
            uint64_t l_hmerVal = l_hmer;
            TRACFCOMP(g_trac_xscom, ERR_MRK "XSCOM status error HMER: %.16llx, XSComStatus %llx",
                    l_hmerVal, l_hmer.mXSComStatus);
            /*@
             * @errortype
             * @moduleid     XSCOM_PERFORM_OP
             * @reasoncode   XSCOM_STATUS_ERR
             * @userdata1    HMER value
             * @userdata2    XSCom address
             * @devdesc      XSCom access error
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            XSCOM_PERFORM_OP,
                                            XSCOM_STATUS_ERR,
                                            l_hmer,
                                            l_mmioAddr);

            // @todo - Collect more FFDC: HMER value, target ID, other registers?

            // Retry
            if (l_retryCtr <= MAX_XSCOM_RETRY)
            {
                l_retryCtr++;
                // If retry is possible, commit error as informational.
                l_retry = XSComRetry(l_hmer);
                if (l_retry == true)
                {
                    l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    // Commit/delete error
                    errlCommit(l_err,XSCOM_COMP_ID);
                }
            }
        }
        else
        {
            // No error, set output buffer size.
            // Always 8 bytes for XSCOM, but we want to make it consistent
            // with all other device drivers
            io_buflen = XSCOM_BUFFER_SIZE;
        }

    } while (l_retry == true); // End retry loop

    return l_err;
}

} // end namespace
