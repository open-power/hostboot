/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ibscom/ibscom.C $                                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

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
#include <errl/errludlogregister.H>
#include <targeting/common/targetservice.H>
#include <ibscom/ibscomreasoncodes.H>
#include "ibscom.H"
#include <assert.h>
#include <limits.h>

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

// Trace definition
trace_desc_t* g_trac_ibscom = NULL;
TRAC_INIT(&g_trac_ibscom, "IBSCOM", KILOBYTE);

using namespace ERRORLOG;
using namespace TARGETING;

namespace IBSCOM
{

// Register XSCcom access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::IBSCOM,
                      TYPE_MEMBUF,
                      ibscomPerformOp);

/**
 * @brief Internal routine that verifies the validity of input parameters
 * for an inband scom access.
 *
 * @param[in]   i_opType       Operation type, see DeviceFW::OperationType
 *                             in driverif.H
 * @param[in]   i_target       inband scom target
 * @param[in] i_buffer         Read: Pointer to output data storage
 *                             Write: Pointer to input data storage
 * @param[in] i_buflen         Input: size of io_buffer (in bytes)
 * @param[in] i_addr           Address being accessed (Used for FFDC)
 * @return  errlHndl_t
 */
errlHndl_t ibscomOpSanityCheck(const DeviceFW::OperationType i_opType,
                              const Target* i_target,
                              const void* i_buffer,
                              const size_t& i_buflen,
                              const uint64_t i_addr)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP(g_trac_ibscom, INFO_MRK
              ">>ibscomOpSanityCheck: Entering Function");

    do
    {
        // Verify address is somewhat valid (not over 32-bits long)
        if(0 != (i_addr & 0xFFFFFFFF00000000))
        {
            TRACFCOMP(g_trac_ibscom, ERR_MRK"ibscomOpSanityCheck: Impossible address.  i_addr=0x%.16X",
                      i_buflen);
            /*@
             * @errortype
             * @moduleid     IBSCOM_SANITY_CHECK
             * @reasoncode   IBSCOM_INVALID_ADDRESS
             * @userdata1    Inband Scom  address
             * @userdata2    <none>
             * @devdesc      The provided address is over 32 bits long
             *               which makes it invalid.
             */
            l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                  IBSCOM_SANITY_CHECK,
                                  IBSCOM_INVALID_ADDRESS,
                                  i_addr,
                                  0);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);
            break;
        }

        // Verify data buffer
        if ( (i_buflen < IBSCOM_BUFFER_SIZE) ||
             (i_buffer == NULL) )
        {
            TRACFCOMP(g_trac_ibscom, ERR_MRK
                      "ibscomOpSanityCheck: Invalid buffer.  i_buflen=0x%X",
                      i_buflen);
            /*@
             * @errortype
             * @moduleid     IBSCOM_SANITY_CHECK
             * @reasoncode   IBSCOM_INVALID_DATA_BUFFER
             * @userdata1    Buffer size
             * @userdata2    Inband Scom  address
             * @devdesc      Inband  buffer size < 8 bytes or NULL
             *               data buffer
             */
            l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                  IBSCOM_SANITY_CHECK,
                                  IBSCOM_INVALID_DATA_BUFFER,
                                  i_buflen,
                                  i_addr);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);
            break;
        }

        // Verify OP type
        if ( (i_opType != DeviceFW::READ) &&
             (i_opType != DeviceFW::WRITE) )
        {
            TRACFCOMP(g_trac_ibscom, ERR_MRK
                      "ibscomOpSanityCheck: Invalid opType.  i_opType=0x%X",
                      i_opType);
            /*@
             * @errortype
             * @moduleid     IBSCOM_SANITY_CHECK
             * @reasoncode   IBSCOM_INVALID_OP_TYPE
             * @userdata1    Operation type
             * @userdata2    inband scom address
             * @devdesc      inband scom invalid operation type
             */
            l_err = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                  IBSCOM_SANITY_CHECK,
                                  IBSCOM_INVALID_OP_TYPE,
                                  i_opType,
                                  i_addr);
            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                       HWAS::SRCI_PRIORITY_HIGH);
            break;
        }


    } while(0);

    return l_err;
}

/**
 * @brief Get the virtual address of the input target
 *        for an inband scom access.
 *
 * Logic:
 * If never inband scom to this chip:
 *     Call mmio_dev_map() to get virtual addr for this slave proc
 *     Save virtual addr used to this chip's attribute
 * Else
 *     Use virtual address stored in this chip's attributes.
 * End if
 *
 * @param[in]   i_target        inband scom target
 * @param[out]  o_virtAddr      Target's virtual address
 *
 * @return errlHndl_t
 */
errlHndl_t getTargetVirtualAddress(Target* i_target,
                                   uint64_t*& o_virtAddr)
{
    errlHndl_t l_err = NULL;
    o_virtAddr = NULL;
    IBScomBase_t l_IBScomBaseAddr = 0;

    do
    {
        // Get the virtual addr value of the chip from attribute
        o_virtAddr =  reinterpret_cast<uint64_t*>
          (i_target->getAttr<ATTR_IBSCOM_VIRTUAL_ADDR>());

        // If the virtual address equals NULL(default) then this is the
        // first IBSCOM to this target so we need to allocate
        // the virtual address and save it in the xscom address attribute.
        if (o_virtAddr == NULL)
        {

            TRACDCOMP(g_trac_ibscom, INFO_MRK
                      "getTargetVirtualAddress: Need to compute virtual address for Centaur");

            //Get MMIO Offset from parent MCS attribute.

            //Get the parent MCS
            Target* parentMCS = NULL;

            PredicateCTM l_mcs(CLASS_UNIT,
                               TYPE_MCS,
                               MODEL_NA);

            TargetHandleList mcs_list;
            targetService().
              getAssociated(mcs_list,
                            i_target,
                            TargetService::PARENT_BY_AFFINITY,
                            TargetService::ALL,
                            &l_mcs);

            if( mcs_list.size() != 1 )
            {
                TRACFCOMP(g_trac_ibscom, ERR_MRK
                          "getTargetVirtualAddress:  mcs_list size is zero");
                /*@
                 * @errortype
                 * @moduleid     IBSCOM_GET_TARG_VIRT_ADDR
                 * @reasoncode   IBSCOM_INVALID_CONFIG
                 * @userdata1[0:31]   HUID of Centaur Target
                 * @userdata2    Not Used
                 * @devdesc      System configuration does not have a Parent MCS
                 *               for the current centaur.
                 */
                l_err =
                  new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                IBSCOM_GET_TARG_VIRT_ADDR,
                                IBSCOM_INVALID_CONFIG,
                                TWO_UINT32_TO_UINT64(
                                                     get_huid(i_target),
                                                     0),
                                0);
                l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                           HWAS::SRCI_PRIORITY_HIGH);
                break;
            }
            parentMCS = *(mcs_list.begin());

            l_IBScomBaseAddr =
              parentMCS->getAttr<ATTR_IBSCOM_MCS_BASE_ADDR>();

            TRACUCOMP(g_trac_ibscom, INFO_MRK
                      "getTargetVirtualAddress: From Attribute query l_IBScomBaseAddr=0x%llX, i_target=0x%.8x",
                      l_IBScomBaseAddr,
                      i_target->getAttr<ATTR_HUID>());

            // Map target's virtual address
            //NOTE: mmio_dev_map only supports 32 GB Allocation.  Technically,
            //hostboot IBSCOM MMIO allocated 64GB, but the SCOM address space
            //is small enough that 32 GB is sufficient.
            o_virtAddr = static_cast<uint64_t*>
              (mmio_dev_map(reinterpret_cast<void*>(l_IBScomBaseAddr),
                            THIRTYTWO_GB));

            // Save the virtual address attribute.

            // Leaving the comments as a discussion point...
            // This issue is tracked under RTC: 35315
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
            i_target->setAttr<ATTR_IBSCOM_VIRTUAL_ADDR>
              (reinterpret_cast<uint64_t>(o_virtAddr));
        }

    } while (0);

    TRACDCOMP(g_trac_ibscom, EXIT_MRK
              "getTargetVirtualAddress: o_Virtual Base Address   =  0x%llX",
              o_virtAddr);


    return l_err;
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t doIBScom(DeviceFW::OperationType i_opType,
                          Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          uint64_t i_addr,
                          bool i_errDataPath)
{
    errlHndl_t l_err = NULL;
    mutex_t* l_mutex = NULL;
    bool need_unlock = false;

    do
    {
        TRACUCOMP(g_trac_ibscom, INFO_MRK
                  ">>doIBScom: Perform op to SCOM Address 0x%X",
                  i_addr);

        // inband scom operation sanity check
        l_err = ibscomOpSanityCheck(i_opType, i_target, io_buffer,
                                    io_buflen, i_addr);
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

        TRACDCOMP(g_trac_ibscom,
                  "doIBScom: Base Virt Addr: 0x%.16X, Read addr: 0x%.16X",
                  l_virtAddr, &(l_virtAddr[i_addr]));


        // The dereferencing should handle Cache inhibited internally
        // Use local variable and memcpy to avoid unaligned memory access
        uint64_t l_data = 0;
        bool rw_error = false;

        //Device already locked when re-entering function for error collection..
        if(!i_errDataPath)
        {
            l_mutex = i_target->getHbMutexAttr<TARGETING::ATTR_IBSCOM_MUTEX>();
            mutex_lock(l_mutex);
            need_unlock = true;
        }

        if (i_opType == DeviceFW::READ)
        {
            //This is the actual MMIO Read
            l_data = l_virtAddr[i_addr];
            eieio();

            TRACUCOMP(g_trac_ibscom,
                      "doIBScom: Read address: 0x%.8X data: %.16X",
                      i_addr, l_data);

            // Check for error or done
            if(l_data == MMIO_IBSCOM_UE_DETECTED)
            {
                if(i_errDataPath)
                {
                    TRACFCOMP(g_trac_ibscom, ERR_MRK"doIBScom:  SUE Occurred during IBSCOM Error path");
                    /*@
                     * @errortype
                     * @moduleid     IBSCOM_DO_IBSCOM
                     * @reasoncode   IBSCOM_SUE_IN_ERR_PATH
                     * @userdata1[0:31]   HUID of Centaur Target
                     * @userdata1[32:64]  SCOM Address
                     * @userdata2    Not Used
                     * @devdesc      SUE Encountered when collecting IBSCOM
                     *               Error Data
                     */
                    l_err =
                      new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    IBSCOM_DO_IBSCOM,
                                    IBSCOM_SUE_IN_ERR_PATH,
                                    TWO_UINT32_TO_UINT64(
                                                         get_huid(i_target),
                                                         i_addr),
                                    0);
                    //This error should NEVER get returned to caller, so it's a
                    //FW bug if it actually gets comitted.
                    l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                               HWAS::SRCI_PRIORITY_HIGH);
                    break;
                }
                else
                {
                    TRACFCOMP(g_trac_ibscom,
                              "doIBScom: Error code found in read data");
                    rw_error = true;
                }
            }
            else
            {
                //Copy data to user buffer
                memcpy(io_buffer, &l_data, sizeof(l_data));
            }
        }
        else //i_opType == DeviceFW::WRITE
        {
            memcpy(&l_data, io_buffer, sizeof(l_data));
            TRACUCOMP(g_trac_ibscom,
                      "doIBScom: Write addr: 0x%.8X data: %.16X",
                      i_addr, l_data);
            //This is the actual MMIO Write
            l_virtAddr[i_addr] = l_data;
            eieio();

            TRACDCOMP(g_trac_ibscom,
                      "doIBScom: Read MBSIBWRSTAT to check for error");
            //Read MBSIBWRSTAT to check for errors
            //If an error occured on last write, reading MBSIBWRSTAT will
            //trigger a SUE.
            const uint32_t MBSIBWRSTAT = 0x201141D;
            uint64_t statData = 0;
            size_t readSize = sizeof(uint64_t);
            l_err = doIBScom(DeviceFW::READ,
                                  i_target,
                                  &statData,
                                  readSize,
                                  MBSIBWRSTAT,
                                  true);
            if(l_err != NULL)
            {
                if( IBSCOM_SUE_IN_ERR_PATH == l_err->reasonCode() )
                {
                    TRACFCOMP(g_trac_ibscom, ERR_MRK
                              "doIBScom: SUE on write detected");
                    delete l_err;
                    l_err = NULL;
                    rw_error = true;
                }
                else
                {
                    TRACFCOMP(g_trac_ibscom, ERR_MRK"doIBScom: Unexpected error when checking for SUE");
                    break;
                }
            }

        }

        if(rw_error)
        {
            bool busDown = false;
            TRACUCOMP(g_trac_ibscom,
                      "doIBScom: Get Error data, read MBSIBERR0");
            const uint32_t MBSIBERR0 = 0x201141B;
            const uint64_t HOST_ERROR_VALID = 0x0000000080000000;
            const uint64_t PIB_ERROR_STATUS_MASK = 0x0000000070000000;
            const uint64_t PIB_ERROR_SHIFT = 28;
            uint64_t errData = 0;
            size_t readSize = sizeof(uint64_t);

            //Use FSISCOM as workaround for DD1.x centaur chips (HW246298)
            if(i_target->getAttr<TARGETING::ATTR_EC>() < 0x20)
            {
                //Need to explicitly use FSI SCOM in DD1X chips
                l_err = deviceOp( DeviceFW::READ,
                                     i_target,
                                     &errData,
                                     readSize,
                                     DEVICE_FSISCOM_ADDRESS(MBSIBERR0) );
                if(l_err)
                {
                    TRACFCOMP(g_trac_ibscom, ERR_MRK
                              "doIBScom: Error reading MBSIBERR0 over FSI");
                    //Save away the IBSCOM address
                    ERRORLOG::ErrlUserDetailsLogRegister
                      l_logReg(i_target);
                    //Really just want to save the addres, so stick in some
                    //obvious dummy data
                    uint64_t dummyData = 0x00000000DEADBEEF;
                    l_logReg.addDataBuffer(&dummyData, sizeof(dummyData),
                                           DEVICE_IBSCOM_ADDRESS(i_addr));
                    l_logReg.addToLog(l_err);
                    break;
                }
                TRACUCOMP(g_trac_ibscom,
                          "doIBScom: MBSIBERR0(0x%.16x) = 0x%.16X",
                          MBSIBERR0, errData);

                //attempt to clear the error register so future accesses
                //will work
                uint64_t zeroData = 0x0;
                readSize = sizeof(uint64_t);
                l_err = deviceOp( DeviceFW::WRITE,
                                     i_target,
                                     &zeroData,
                                     readSize,
                                     DEVICE_FSISCOM_ADDRESS(MBSIBERR0) );
                if(l_err )
                {
                    errlCommit(l_err,IBSCOM_COMP_ID);
                    l_err = NULL;
                }


                uint64_t pib_code = (errData & PIB_ERROR_STATUS_MASK)
                  >> PIB_ERROR_SHIFT;
                if((errData & HOST_ERROR_VALID) &&//bit 32
                   // technically between 0x001 && 0x7, but only 3
                   // bits are valid.
                   (pib_code > 0x000))
                {
                    //TODO RTC: 35064 - This will be the same as the FSI SCOM
                    //error handling.
                    //Look at data to decide if bus is down
                    //Make smart decisions based on PIB error code.

                    //Assume caller provided bad address for now.
                    TRACFCOMP(g_trac_ibscom, "doIBScom: MBSIBERR0 bit 0 set, caller most likely used a bad address (0x%.8x)",
                              i_addr);

                    /*@
                     * @errortype
                     * @moduleid     IBSCOM_DO_IBSCOM
                     * @reasoncode   IBSCOM_INVALID_ADDRESS
                     * @userdata1[0:31]   HUID of Centaur Target
                     * @userdata1[32:64]  SCOM Address
                     * @userdata2    Contents of MBSIBERR0 register
                     * @devdesc      Operation rejected by HW due to bad
                     *               address.
                     */
                    l_err =
                      new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                    IBSCOM_DO_IBSCOM,
                                    IBSCOM_INVALID_ADDRESS,
                                    TWO_UINT32_TO_UINT64(
                                                         get_huid(i_target),
                                                         i_addr),
                                    errData);
                    l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                               HWAS::SRCI_PRIORITY_HIGH);
                    break;
                }
                else
                {
                    //Bus is down
                    busDown = true;
                }


            }
            else  // >= DD20
            {
                //TODO RTC: 68984: Validate error path on DD2.0 Centaurs
                l_err = doIBScom(DeviceFW::READ,
                                    i_target,
                                    &errData,
                                    readSize,
                                    MBSIBERR0,
                                    true);
                if(l_err != NULL)
                {
                    if( IBSCOM_SUE_IN_ERR_PATH == l_err->reasonCode() )
                    {
                        TRACFCOMP(g_trac_ibscom, ERR_MRK
                                  "doIBScom: SUE on write detected");
                        delete l_err;
                        l_err = NULL;
                        busDown = true;
                    }
                    else
                    {
                        TRACFCOMP(g_trac_ibscom, ERR_MRK"doIBScom: Unexpected error when checking for SUE");
                        break;
                    }
                }
                else //MBSIBERR0 returned valid data
                {
                    //TODO RTC: 35064 - This will be the same as the FSI SCOM
                    //error handling.
                    //Look at data to decide if bus is down
                    //Make smart decisions based on PIB error code.

                    //For now, assume bus is Down
                    busDown = true;

                }
            } // >= DD20

            if(busDown)
            {
                //TODO RTC: 69115 - call PRD to do FIR analysis, return PRD
                //error instead.
                /*@
                 * @errortype
                 * @moduleid     IBSCOM_DO_IBSCOM
                 * @reasoncode   IBSCOM_BUS_FAILURE
                 * @userdata1[0:31]   HUID of Centaur Target
                 * @userdata1[32:64]  SCOM Address
                 * @userdata2    Contents of MBSIBERR0 register
                 * @devdesc      Bus failure when attempting to perform
                 *               IBSCOM operation.  IBSCOM disabled.
                 */
                l_err =
                  new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                IBSCOM_DO_IBSCOM,
                                IBSCOM_BUS_FAILURE,
                                TWO_UINT32_TO_UINT64(
                                                     get_huid(i_target),
                                                     i_addr),
                                errData);

                l_err->addHwCallout(i_target,
                                    HWAS::SRCI_PRIORITY_HIGH,
                                    HWAS::NO_DECONFIG,
                                    HWAS::GARD_NULL);

                //disable IBSCOM
                ScomSwitches l_switches =
                  i_target->getAttr<ATTR_SCOM_SWITCHES>();

                // If IBSCOM is not already disabled.
                if ((l_switches.useFsiScom != 1) ||
                    (l_switches.useInbandScom != 0))
                {
                    l_switches.useFsiScom = 1;
                    l_switches.useInbandScom = 0;

                    // Turn off IBSCOM and turn on FSI SCOM.
                    i_target->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
                }
                break;
            }
        }
        else
        {
            //Operation was a success, set buffer length
            io_buflen = sizeof(uint64_t);
        }

        TRACDCOMP(g_trac_ibscom,"doIBScom: OpType 0x%.16llX, SCOM Address 0x%llX, Virtual Address 0x%llX",
                  static_cast<uint64_t>(i_opType),
                  i_addr,
                  &(l_virtAddr[i_addr]));

    } while (0);

    if( need_unlock && l_mutex )
    {
        mutex_unlock(l_mutex);
    }

    return l_err;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
errlHndl_t ibscomPerformOp(DeviceFW::OperationType i_opType,
                          Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    l_err = doIBScom(i_opType,
                     i_target,
                     io_buffer,
                     io_buflen,
                     l_addr,
                     false);
    return l_err;
}

} // end namespace
