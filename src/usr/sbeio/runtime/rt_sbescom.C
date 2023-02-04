/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/runtime/rt_sbescom.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
 *  @file rt_sbescom.C
 *  @brief Runtime SBE Scom support for ocmb channel failure handling
 */
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

#include <scom/scomif.H>
#include <scom/runtime/rt_scomif.H>
#include <targeting/common/utilFilter.H>
#include <sbeio/sbeioif.H>

#include <map>

extern trace_desc_t* g_trac_sbeio;

namespace SBESCOM
{

/**
 * @brief Mark the ocmb target as useSbeScom
 * @param[in] OCMB target
 */
static void markUseSbeScom(TARGETING::TargetHandle_t i_ocmb)
{
    TARGETING::ScomSwitches l_switches = {0};
    if (i_ocmb->tryGetAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches))
    {
        TRACFCOMP(g_trac_sbeio,
              "markUseSbeScom: switching to use SBESCOM on OCMB 0x%.8X",
              TARGETING::get_huid(i_ocmb));

        l_switches.useSbeScom = 1;
        l_switches.useInbandScom = 0;

        // Mark target
        i_ocmb->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
    }
}


/**
 * @brief OMI channel has checkstopped.  Mark it bad and switch to FSP/SBE access.
 *
 * @param[in]     i_target    ocmb target
 * @return  None
 */
void switchToSbeScomAccess(TARGETING::TargetHandle_t i_ocmb)
{
    TRACDCOMP(g_trac_sbeio,ENTER_MRK"switchToSbeScomAccess : 0x%.8X OCMB",
              TARGETING::get_huid(i_ocmb));

    // switch to sbe scom since inband path does not work anymore
    markUseSbeScom(i_ocmb);

    TRACDCOMP(g_trac_sbeio,EXIT_MRK"switchToSbeScomAccess");
}


/**
 * @brief Complete the SCOM operation through SBE.
 *
 * @param[in]     i_opType    Operation type, see driverif.H
 * @param[in]     i_ocmb      SCOM OCMB target
 * @param[in/out] io_buffer   Read: Pointer to output data storage
 *                            Write: Pointer to input data storage
 * @param[in/out] io_buflen   Input: size of io_buffer (in bytes)
 *                            Output: Read:  Size of output data
 *                                    Write: Size of data written
 * @param[in]   i_accessType  Access type
 * @param[in]   i_args        This is an argument list for DD framework.
 *                            In this function, there's only one argument,
 *                            which is the SCOM address
 * @return  errlHndl_t
 */
errlHndl_t sbeScomPerformOp(DeviceFW::OperationType i_opType,
                            TARGETING::TargetHandle_t i_ocmb,
                            void* io_buffer,
                            size_t& io_buflen,
                            int64_t i_accessType,
                            va_list i_args)
{
    TRACDCOMP(g_trac_sbeio,ENTER_MRK"sbeScomPerformOp");
    errlHndl_t l_err  = nullptr;
    uint64_t   l_addr = va_arg(i_args,uint64_t);

    l_err = SCOM::scomOpSanityCheck(i_opType,
                                    i_ocmb,
                                    io_buffer,
                                    io_buflen,
                                    l_addr,
                                    sizeof(uint64_t));

    if (l_err)
    {
        // Trace here - sanity check does not know scom type
        TRACFCOMP(g_trac_sbeio,"Runtime SBE Scom sanity check failed on %.8X",
            get_huid(i_ocmb));
    }
    else
    {
        assert(io_buflen == sizeof(uint64_t) ,
               "We only support read lengths of 8 bytes for PSU scom ops");
        l_err = SBEIO::sendPsuGetHwRegRequest(
                                i_ocmb,
                                l_addr,
                                *static_cast<uint64_t *>(io_buffer));
    }

    TRACDCOMP(g_trac_sbeio,EXIT_MRK"sbeScomPerformOp");

    return l_err;
}

// Direct OCMB SBE SCOM calls through this interface at runtime.
// This is an alternate route for when a OMI channel checkstop has
// occurred, and PHYP cannot service the operation.
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::SBESCOM,
                      TARGETING::TYPE_OCMB_CHIP,
                      sbeScomPerformOp);

}; // end namespace SBESCOM
