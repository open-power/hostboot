/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/ibscom/runtime/rt_ibscom.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <ibscom/ibscomreasoncodes.H>
#include "../ibscom.H"
#include <scom/scomif.H>
#include <scom/runtime/rt_scomif.H>
#include <ibscom/ibscomif.H>

// Trace definition
trace_desc_t* g_trac_ibscom = NULL;
TRAC_INIT(&g_trac_ibscom, IBSCOM_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace IBSCOM
{

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::IBSCOM,
                      TARGETING::TYPE_MEMBUF,
                      ibscomPerformOp);


/**
 * @brief Complete the ibscom op
 *
 * @param[in]     i_opType    Operation type, see driverif.H
 * @param[in]     i_target    IBSCom target
 * @param[in/out] io_buffer   Read: Pointer to output data storage
 *                            Write: Pointer to input data storage
 * @param[in/out] io_buflen   Input: size of io_buffer (in bytes)
 *                            Output: Read:  Size of output data
 *                                    Write: Size of data written
 * @param[in]   i_accessType  Access type
 * @param[in]   i_args        This is an argument list for DD framework.
 *                            In this function, there's only one argument,
 *                               which is the MMIO IBSCom address
 * @return  errlHndl_t
 */
errlHndl_t ibscomPerformOp(DeviceFW::OperationType i_opType,
                           TARGETING::Target* i_target,
                           void* io_buffer,
                           size_t& io_buflen,
                           int64_t i_accessType,
                           va_list i_args)
{
    TRACDCOMP(g_trac_ibscom,ENTER_MRK"ibscomPerformOp");
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    do
    {
        l_err = SCOM::scomOpSanityCheck(i_opType,
                                        i_target,
                                        io_buffer,
                                        io_buflen,
                                        l_addr,
                                        IBSCOM_BUFFER_SIZE);
        if( l_err )
        {
            // Trace here - sanity check does not know scom type
            TRACFCOMP(g_trac_ibscom,"Runtime IBScom sanity check failed");
            break;
        }

        // Multicast is not handled correctly by inband scom
        // Call workaround to complete manually
        bool l_didWorkaround = false;
        l_err = doIBScomMulticast(i_opType,
                                i_target,
                                io_buffer,
                                io_buflen,
                                l_addr,
                                l_didWorkaround);
        if( l_err || l_didWorkaround )
        {
            break;
        }

        l_err = SCOM::sendScomToHyp(i_opType, i_target, l_addr, io_buffer);

    } while(0);

    TRACDCOMP(g_trac_ibscom,EXIT_MRK"ibscomPerformOp");

    return l_err;
}

}; // end namespace IBSCOM

