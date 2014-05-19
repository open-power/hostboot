/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/runtime/rt_xscom.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include <runtime/rt_targeting.H>

// Trace definition
trace_desc_t* g_trac_xscom = NULL;
TRAC_INIT(&g_trac_xscom, "XSCOM", 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace XSCOM
{

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

/**
 * @brief Do the scom operation
 */
errlHndl_t  xScomDoOp(DeviceFW::OperationType i_ioType,
                      TARGETING::Target * i_target,
                      uint64_t i_scomAddr,
                      void * io_buffer)
{
    errlHndl_t l_err = NULL;
    int rc = 0;
    RT_TARG::rtChipId_t proc_id = 0;

    // Convert target to something  Sapphire understands
    l_err = RT_TARG::getRtTarget(i_target,
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
                          l_addr,
                          io_buffer);
    }

    TRACDCOMP(g_trac_xscom,EXIT_MRK"xscomPerformOp");

    return l_err;
}

}; // end namespace XSCOM

