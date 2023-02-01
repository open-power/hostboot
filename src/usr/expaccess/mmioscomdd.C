/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/mmioscomdd.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
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
 *  @file mmioscomdd.C
 *
 *  @brief Implementation of MMIO SCOM operations to OCMB chip             */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

#include <exp_inband.H>              // getMMIO32
#include <lib/shared/exp_consts.H>   // IBM_SCOM_INDICATOR
#include <fapi2/plat_hwp_invoker.H>  // FAPI_INVOKE_HWP
#include <targeting/common/commontargeting.H>   // get_huid
#include "mmioscomdd.H"    //mmioScomPerformOp
#include "expscom_trace.H" //g_trac_expscom
#include "expscom_utils.H" //validateInputs

using namespace TARGETING;

namespace MMIOSCOMDD
{

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::IBSCOM_EXP,
                      TYPE_OCMB_CHIP,
                      mmioScomPerformOp);

///////////////////////////////////////////////////////////////////////////////
// See header for doxygen documentation
///////////////////////////////////////////////////////////////////////////////
errlHndl_t mmioScomPerformOp(DeviceFW::OperationType i_opType,
                          Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    errlHndl_t l_err = nullptr;

    // The only extra arg should be the scomAddress
    uint64_t l_expAddr = va_arg(i_args,uint64_t);

    // The fapi2 put/get mmioScom interfaces require a fapi2::buffer so convert
    // to a uint64_t buffer (for IBM scom) and uint32_t buffer (for Microchip
    // scoms)
    fapi2::buffer<uint64_t>
        l_fapi2Buffer64(*reinterpret_cast<uint64_t *>(io_buffer));
    fapi2::buffer<uint32_t> l_fapi2Buffer32;
    l_fapi2Buffer64.extractToRight<32,32>(l_fapi2Buffer32);

    TRACDCOMP( g_trac_expscom, INFO_MRK "mmioScomPerformOp> HUID 0x%x %s "
               "address 0x%lx %s buffer 0x%p",
               get_huid(i_target),
               i_opType == DeviceFW::READ ? "READ from" : "WRITE to",
               l_expAddr,
               i_opType == DeviceFW::READ ? "to" : "from",
               io_buffer );

    auto mutex = i_target->getHbMutexAttr<TARGETING::ATTR_SCOM_ACCESS_MUTEX>();
    recursive_mutex_lock(mutex);

    do
    {
        // First make sure the inputs are valid
        l_err = EXPSCOM::validateInputs ( i_opType, i_target, io_buflen,
                                          l_expAddr);

        if(l_err)
        {
            // Write a trace out to the buffer and then collect it on the log
            // this way we can know if the fail was in i2cScomPerformOp or
            // mmioScomPerformOp
            TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> Validation "
                "of inputs failed. "
                TRACE_ERR_FMT,
                TRACE_ERR_ARGS(l_err));

            l_err->collectTrace(EXPSCOM_COMP_NAME);
            break;
        }

        // validateInputs() verifies the i_target is of TYPE_OCMB_CHIP
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
            (i_target);

        // Check if this is a IBM_SCOM address by &ing the address with
        // IBM_SCOM_INDICATOR
        // If the indicator is not set, then we will assume this is a microChip
        // address
        if( (l_expAddr & mss::exp::i2c::IBM_SCOM_INDICATOR) ==
            mss::exp::i2c::IBM_SCOM_INDICATOR)
        {
            // READ and WRITE equates to mss::exp::ib::getScom and
            // mss::exp::ib::putScom respectively.
            // Any other OP is invalid. i/o data is expected to be 8 bytes for
            // IBM scoms
            if(i_opType == DeviceFW::READ)
            {
                FAPI_INVOKE_HWP(l_err, mss::exp::ib::getScom,
                                l_fapi_ocmb_target,
                                l_expAddr,
                                l_fapi2Buffer64);
                if(l_err)
                {
                    TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> "
                        "mss::exp::ib::getScom failed for HUID 0x%x "
                        "Address 0x%lx. "
                        TRACE_ERR_FMT,
                        get_huid(i_target), l_expAddr,
                        TRACE_ERR_ARGS(l_err));
                }
                else
                {
                    // Copy contents of what we read to io_buffer
                    memcpy(io_buffer,
                           reinterpret_cast<uint8_t *>(
                                l_fapi2Buffer64.pointer()),
                           sizeof(uint64_t));
                }
            }
            else
            {
                FAPI_INVOKE_HWP(l_err,
                                mss::exp::ib::putScom,
                                l_fapi_ocmb_target,
                                l_expAddr,
                                l_fapi2Buffer64);
                if(l_err)
                {
                    TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> "
                        "mss::exp::ib::putScom failed for HUID 0x%x "
                        "Address 0x%lx. "
                        TRACE_ERR_FMT,
                        get_huid(i_target), l_expAddr,
                        TRACE_ERR_ARGS(l_err));
                }
            }
        }
        else // not IBM_SCOM_INDICATOR
        {
            // READ and WRITE equates to mss::exp::ib::gettMMIO32 and
            // mss::exp::ib::putMMIO32 respectively.
            // Any other OP is invalid.
            if(i_opType == DeviceFW::READ)
            {
                FAPI_INVOKE_HWP(l_err,
                                mss::exp::ib::getMMIO32,
                                l_fapi_ocmb_target,
                                l_expAddr,
                                l_fapi2Buffer32);

                if(l_err)
                {
                    TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> "
                        "getMMIO32 failed for HUID 0x%x Address 0x%lx. "
                        TRACE_ERR_FMT,
                        get_huid(i_target), l_expAddr,
                        TRACE_ERR_ARGS(l_err));
                }
                else
                {
                    // Put the contexts of the 32 bit buffer right justified
                    // into the 64 bit buffer
                    l_fapi2Buffer64.flush<0>();
                    l_fapi2Buffer64.insertFromRight<32,32>(l_fapi2Buffer32);
                    // Copy contents of 64 bit buffer to io_buffer
                    memcpy(io_buffer,
                           reinterpret_cast<uint8_t *>(
                                l_fapi2Buffer64.pointer()),
                           sizeof(uint64_t));
                }
            }
            else
            {
                FAPI_INVOKE_HWP(l_err,
                                mss::exp::ib::putMMIO32,
                                l_fapi_ocmb_target,
                                l_expAddr,
                                l_fapi2Buffer32);

                if(l_err)
                {
                    TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> "
                        "putMMIO32 failed for HUID 0x%x Address 0x%lx. "
                        TRACE_ERR_FMT,
                        get_huid(i_target), l_expAddr,
                        TRACE_ERR_ARGS(l_err));
                }
            }

        }

    } while (0);

    recursive_mutex_unlock(mutex);

    return l_err;
}

} // namespace MMIOSCOMDD
