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
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/targetservice.H>
#include <xscom/xscomreasoncodes.H>
#include "xscom.H"

// Trace definition
trace_desc_t* g_trac_xscom = NULL;
TRAC_INIT(&g_trac_xscom, "XSCOM", 4096);

namespace XSCOM
{

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
    // This call always returns 0, no checking needed
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

        // Setup the address

        // Init values are for master processor, as PNOR may not
        // yet available
        XSComBase_t l_XSComBaseAddr = MASTER_PROC_XSCOM_BASE_ADDR;
        TARGETING::XscomChipInfo l_xscomChipInfo = {0};
        if (i_target != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            l_XSComBaseAddr =
                    i_target->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();
            l_xscomChipInfo =
                    i_target->getAttr<TARGETING::ATTR_XSCOM_CHIP_INFO>();
        }

        // Build the XSCom address
        XSComP8Address l_mmioAddr(va_arg(i_args,uint64_t), l_xscomChipInfo.nodeId,
                                  l_xscomChipInfo.chipId, l_XSComBaseAddr);

        // Re-init l_retry for loop
        l_retry = false;

        // Pin this thread to current CPU
        task_affinity_pin();

        // Lock other XSCom in this same thread from running
        l_XSComMutex = mmio_xscom_mutex();
        mutex_lock(l_XSComMutex);

        // Calculate MMIO addr
        uint64_t l_page = l_mmioAddr.page();
        uint64_t l_offset_64 = (l_mmioAddr.offset()/sizeof(uint64_t));
        uint64_t* l_virtAddr = static_cast<uint64_t*>
                (mmio_map(reinterpret_cast<void*>(l_page), 1));

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
                 l_data = *(l_virtAddr + l_offset_64);
                 memcpy(io_buffer, &l_data, sizeof(l_data));
            }
            else
            {
                memcpy(&l_data, io_buffer, sizeof(l_data));
                *(l_virtAddr + l_offset_64) = l_data;
            }

            // Check for error or done
            l_hmer = waitForHMERStatus();

        } while (l_hmer.mXSComStatus == HMER::XSCOM_BLOCKED);

        // @todo - Need to un-map for now
        mmio_unmap(l_virtAddr, 1);

        // Unlock
        mutex_unlock(l_XSComMutex);

        // Done, un-pin
        task_affinity_unpin();

        TRACFCOMP(g_trac_xscom, "xscomPerformOp: OpType 0x%.8X, Address %llx, Page %llx; Offset %llx; VirtAddr %llx; l_virtAddr+l_offset %llx",
                i_opType, static_cast<uint64_t>(l_mmioAddr), l_page,
                l_offset_64, l_virtAddr, l_virtAddr + l_offset_64);

        if (i_opType == DeviceFW::READ)
        {
            TRACFCOMP(g_trac_xscom, "xscomPerformOp: Read data: %llx", l_data);        }
        else
        {
            TRACFCOMP(g_trac_xscom, "xscomPerformOp: Write data: %llx", l_data);
        }

        // Handle error
        if (l_hmer.mXSComStatus != HMER::XSCOM_GOOD)
        {
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
                    errlCommit(l_err);
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
