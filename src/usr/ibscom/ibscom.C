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
#include <targeting/common/targetservice.H>
#include <ibscom/ibscomreasoncodes.H>
#include "ibscom.H"
#include <assert.h>
#include <limits.h>

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
                break;
            }
            parentMCS = *(mcs_list.begin());

            l_IBScomBaseAddr =
              parentMCS->getAttr<ATTR_IBSCOM_MCS_BASE_ADDR>();

            TRACFCOMP(g_trac_ibscom, INFO_MRK
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
errlHndl_t ibscomPerformOp(DeviceFW::OperationType i_opType,
                          Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    do
    {
        TRACDCOMP(g_trac_ibscom, INFO_MRK
                  ">>ibscomPerformOp: Perform op to SCOM Address 0x%X",
                  l_addr);

        // inband scom operation sanity check
        l_err = ibscomOpSanityCheck(i_opType, i_target, io_buffer,
                                    io_buflen, l_addr);
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

        // The dereferencing should handle Cache inhibited internally
        // Use local variable and memcpy to avoid unaligned memory access
        uint64_t l_data = 0;

        if (i_opType == DeviceFW::READ)
        {
            //TODO: Check that address isn't greater than allocated 32GB range
            // RTC: 47212
            l_data = l_virtAddr[l_addr];

            memcpy(io_buffer, &l_data, sizeof(l_data));
            TRACDCOMP(g_trac_ibscom,
                      "ibscomPerformOp: Read data: %.16llx",
                      l_data);

        }
        else
        {
            TRACDCOMP(g_trac_ibscom,
                      "ibscomPerformOp: Write data: %.16llx",
                      l_data);
            memcpy(&l_data, io_buffer, sizeof(l_data));
            l_virtAddr[l_addr] = l_data;
        }

        // Check for error or done
        //TODO - check for errors  RTC: 47212
        //assume successful for now
        io_buflen = sizeof(uint64_t);

        TRACDCOMP(g_trac_ibscom,
                  "ibscomPerformOp: OpType 0x%.16llX, SCOM Address 0x%llX, Virtual Address 0x%llX",
                  static_cast<uint64_t>(i_opType),
                  l_addr,
                  &(l_virtAddr[l_addr]));

    } while (0);

    return l_err;
}

} // end namespace
