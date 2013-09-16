/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/runtime/rt_xscom.C $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <xscom/xscomreasoncodes.H>
#include "../xscom.H"
#include <assert.h>
#include <errl/errludlogregister.H>
#include <runtime/interface.h>
#include <errl/errludtarget.H>

// Trace definition
trace_desc_t* g_trac_xscom = NULL;
TRAC_INIT(&g_trac_xscom, "XSCOM", 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace XSCOM
{

enum
{
    CHIPID_NODE_SHIFT = 3,  // CHIPID is 'NNNCCC'b, shift 3
    MEMBUF_ID_SHIFT = 4,    // CHIPID for MEMBUF is 'NNNCCCMMMM'b 
    MEMBUF_ID_FLAG  = 0x80000000, // MEMBUF chip id has MSbit on
};


DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::XSCOM,
                      TARGETING::TYPE_PROC,
                      xscomPerformOp);

// Direct all scom calls though this interface at runtime
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::FSISCOM,
                      TARGETING::TYPE_PROC,
                      xscomPerformOp);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::FSISCOM,
                      TARGETING::TYPE_MEMBUF,
                      xscomPerformOp);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::IBSCOM,
                      TARGETING::TYPE_MEMBUF,
                      xscomPerformOp);
/**
 * @brief Convert target into chipId that the hypervisor uses
 * @param[in]   i_target   The HB TARGETING target
 * @param[out]  o_chipId    32-bit chipid
 * @return      errlHndl_t  Error handle if there was an error
 */
errlHndl_t get_rt_target(TARGETING::Target* i_target,
                         uint32_t & o_chipId);

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
                              const va_list i_args);



errlHndl_t xscomOpSanityCheck(const DeviceFW::OperationType i_opType,
                              const TARGETING::Target* i_target,
                              const void* i_buffer,
                              const size_t& i_buflen,
                              const va_list i_args){
    errlHndl_t l_err = NULL;

    do
    {
        // Verify data buffer
        if ( (i_buflen < XSCOM_BUFFER_SIZE) ||
             (i_buffer == NULL) )
        {
            /*@
             * @errortype
             * @moduleid     XSCOM_RT_SANITY_CHECK
             * @reasoncode   XSCOM_INVALID_DATA_BUFFER
             * @userdata1    Buffer size
             * @userdata2    XSCom address
             * @devdesc      XSCOM buffer size < 8 bytes or NULL data buff
             */
            l_err =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        XSCOM_RT_SANITY_CHECK,
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
             * @moduleid     XSCOM_RT_SANITY_CHECK
             * @reasoncode   XSCOM_INVALID_OP_TYPE
             * @userdata1    Operation type
             * @userdata2    XSCom address
             * @devdesc      XSCOM invalid operation type
             */
            l_err =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        XSCOM_RT_SANITY_CHECK,
                                        XSCOM_INVALID_OP_TYPE,
                                        i_opType,
                                        va_arg(i_args,uint64_t));
            break;
        }


    } while(0);

    return l_err;
}


errlHndl_t get_rt_target(TARGETING::Target* i_target,
                         uint32_t &o_chipId)
{
    errlHndl_t l_err = NULL;

    do
    {
        if(i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            TARGETING::Target* masterProcChip = NULL;
            TARGETING::targetService().
                masterProcChipTargetHandle(masterProcChip);

            i_target = masterProcChip;
        }

        uint32_t target_type = i_target->getAttr<TARGETING::ATTR_TYPE>();

        if(target_type == TARGETING::TYPE_MEMBUF)
        {
            TARGETING::TargetHandleList targetList;

            // need to get assoicated MC for this MEMBUF
            getParentAffinityTargets(targetList,
                                     i_target,
                                     TARGETING::CLASS_UNIT,
                                     TARGETING::TYPE_MCS);
            if( targetList.empty() )
            {
                uint32_t huid = get_huid(i_target);
                TRACFCOMP(g_trac_xscom,ERR_MRK
                          "No MSC target found for MEMBUF. MEMBUF huid: %08x",
                          huid);
                /*@
                 * @errortype
                 * @moduleid     XSCOM_RT_GET_TARGET
                 * @reasoncode   XSCOM_RT_NO_MCS_TARGET
                 * @userdata1    HUID of MEMBUF target
                 * @devdesc      No memory controller target found for the
                 *               given Memory data controller
                 */
                l_err =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            XSCOM_RT_GET_TARGET,
                                            XSCOM_RT_NO_MCS_TARGET,
                                            huid,
                                            0);

                l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                           HWAS::SRCI_PRIORITY_HIGH);

                ERRORLOG::ErrlUserDetailsTarget(i_target,"SCOM Target").
                    addToLog(l_err);

                break;
            }

            TARGETING::Target * mcs_target = targetList[0];
            uint32_t mcpos = mcs_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();

            // Get associated proc chip
            targetList.clear();
            getParentAffinityTargets(targetList,
                                     mcs_target,
                                     TARGETING::CLASS_CHIP,
                                     TARGETING::TYPE_PROC);

            if(targetList.empty())
            {
                uint32_t huid = get_huid(mcs_target);
                TRACFCOMP(g_trac_xscom,ERR_MRK
                          "No proc target found for MSC. MSC huid: %08x",
                          huid);
                /*@
                 * @errortype
                 * @moduleid     XSCOM_RT_GET_TARGET
                 * @reasoncode   XSCOM_RT_NO_PROC_TARGET
                 * @userdata1    HUID of the MSC target
                 * @devdesc      No processor target found for the Memory
                 *               controller.
                 */
                l_err =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            XSCOM_RT_GET_TARGET,
                                            XSCOM_RT_NO_PROC_TARGET,
                                            huid,
                                            0);

                l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                           HWAS::SRCI_PRIORITY_HIGH);

                ERRORLOG::ErrlUserDetailsTarget(mcs_target,"SCOM Target").
                    addToLog(l_err);

                break;
            }

            TARGETING::Target * proc_target = targetList[0];
            uint32_t fabId =
                proc_target->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();
            uint32_t procPos =
                proc_target->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

            o_chipId = (fabId << CHIPID_NODE_SHIFT) + procPos;
            o_chipId = (o_chipId << MEMBUF_ID_SHIFT) | MEMBUF_ID_FLAG;
            o_chipId += mcpos;
        }
        else // must be proc
        {
            uint32_t fabId = i_target->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();
            uint32_t procPos = i_target->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

            o_chipId = (fabId << CHIPID_NODE_SHIFT) + procPos;
        }
    } while(0);
    
    return l_err;
}


/**
 * @brief Do the scom operation
 */
errlHndl_t  xScomDoOp(DeviceFW::OperationType i_ioType,
                      TARGETING::Target * i_target,
                      uint32_t i_scomAddr,
                      void * io_buffer)
{
    errlHndl_t l_err = NULL;
    int rc = 0;
    uint32_t proc_id = 0;

    // Convert target to something  Sapphire understands
    l_err = get_rt_target(i_target,
                          proc_id);

    if(l_err)
    {
        return l_err;
    }

    if(g_hostInterfaces != NULL &&
       g_hostInterfaces->scom_read != NULL &&
       g_hostInterfaces->scom_write != NULL)
    {

        if(i_ioType == DeviceFW::READ)
        {
            rc =
                g_hostInterfaces->scom_read(proc_id,
                                            i_scomAddr,
                                            io_buffer
                                           );
        }
        else if (i_ioType == DeviceFW::WRITE)
        {
            rc =
                g_hostInterfaces->scom_write(proc_id,
                                             i_scomAddr,
                                             io_buffer
                                            );
        }

        if(rc)
        {
            // convert rc to error log
            /*@
             * @errortype
             * @moduleid     XSCOM_RT_DO_OP
             * @reasoncode   XSCOM_RUNTIME_ERR
             * @userdata1    Hypervisor return code
             * @userdata2    SCOM address
             * @devdesc      XSCOM access error
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            XSCOM_RT_DO_OP,
                                            XSCOM_RUNTIME_ERR,
                                            rc,
                                            i_scomAddr);

            // TODO - RTC 86782 need to know what kind of errors Sapphire can
            // return - could effect callout.
            l_err->addHwCallout(i_target,
                                HWAS::SRCI_PRIORITY_LOW,
                                HWAS::NO_DECONFIG,
                                HWAS::GARD_NULL);

            // Note: no trace buffer available at runtime
        }
    }
    else // Hypervisor interface not initialized
    {
        TRACFCOMP(g_trac_xscom,ERR_MRK"Hypervisor scom interface not linked");
        /*@
         * @errortype
         * @moduleid     XSCOM_RT_DO_OP
         * @reasoncode   XSCOM_RUNTIME_INTERFACE_ERR
         * @userdata1    0
         * @userdata2    SCOM address
         * @devdesc      XSCOM runtime interface not linked.
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        XSCOM_RT_DO_OP,
                                        XSCOM_RUNTIME_INTERFACE_ERR,
                                        0,
                                        i_scomAddr);

        l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                   HWAS::SRCI_PRIORITY_HIGH);
    }

    return l_err;
}


errlHndl_t xscomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    TRACDCOMP(g_trac_xscom,ENTER_MRK"xscomPerformOp");
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    l_err = xscomOpSanityCheck(i_opType,
                               i_target,
                               io_buffer,
                               io_buflen,
                               i_args);

    if (!l_err)
    {

        l_err = xScomDoOp(i_opType,
                          i_target,
                          (uint32_t)l_addr,
                          io_buffer);
    }

    TRACDCOMP(g_trac_xscom,EXIT_MRK"xscomPerformOp");

    return l_err;
}

}; // end namespace XSCOM

