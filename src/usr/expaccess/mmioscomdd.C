/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/mmioscomdd.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#include <exp_inband.H>              // mmio_get_scom
#include <lib/shared/exp_consts.H>   // IBM_SCOM_INDICATOR
#include <hwpf/fapi2/include/fapi2_hwp_executor.H>// FAPI_EXEC_HWP
#include "mmioscomdd.H"   //mmioScomPerformOp
#include "expscom_trace.H" //g_trac_expscom
#include "expscom_utils.H" //validateInputs

namespace MMIOSCOMDD
{

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::IBSCOM,
                      TARGETING::TYPE_OCMB_CHIP,
                      mmioScomPerformOp);

///////////////////////////////////////////////////////////////////////////////
// See header for doxygen documentation
///////////////////////////////////////////////////////////////////////////////
errlHndl_t mmioScomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    errlHndl_t l_err = nullptr;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    // The only extra arg should be the scomAddress
    uint64_t l_expAddr = va_arg(i_args,uint64_t);

    // The fapi2 put/get mmioScom interfaces require a fapi2::buffer so convert
    // to a uint64_t buffer (for IBM scom) and uint32_t buffer (for Microchip scoms)
    fapi2::buffer<uint64_t> l_fapi2Buffer64(*reinterpret_cast<uint64_t *>(io_buffer));
    fapi2::buffer<uint32_t> l_fapi2Buffer32;
    l_fapi2Buffer64.extractToRight<32,32>(l_fapi2Buffer32);

    do
    {
        // First make sure the inputs are valid
        l_err = EXPSCOM::validateInputs ( i_opType, i_target, io_buflen, l_expAddr);

        if(l_err)
        {
            // Write a trace out to the buffer and then collect it on the log
            // this way we can know if the fail was in i2cScomPerformOp or mmioScomPerformOp
            TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> Validation of inputs failed see error logs for details ");
            l_err->collectTrace(EXPSCOM_COMP_NAME);
            break;
        }

        // Check if this is a IBM_SCOM address by &ing the address with IBM_SCOM_INDICATOR
        // If the indicator is not set, then we will assume this is a microChip address
        if( (l_expAddr & mss::exp::i2c::IBM_SCOM_INDICATOR) == mss::exp::i2c::IBM_SCOM_INDICATOR)
        {
            // READ and WRITE equates to mss::exp::ib::getScom and mss::exp::ib::putScom respectively.
            //  any other OP is invalid. i/o data is expected to be 8 bytes for IBM scoms
            if(i_opType == DeviceFW::READ)
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::ib::getScom, i_target, l_expAddr, l_fapi2Buffer64);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME,256);
                    l_err->collectTrace(FAPI_TRACE_NAME,384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> mss::exp::ib::getScom failed for HUID 0x%x Address 0x%lx ",
                               TARGETING::get_huid(i_target), l_expAddr );
                }
                else
                {
                    // Copy contents of what we read to io_buffer
                    memcpy(io_buffer, reinterpret_cast<uint8_t *>(l_fapi2Buffer64.pointer()), sizeof(uint64_t));
                }
            }
            else
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::ib::putScom, i_target, l_expAddr, l_fapi2Buffer64);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME,256);
                    l_err->collectTrace(FAPI_TRACE_NAME,384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> mss::exp::ib::putScom failed for HUID 0x%x Address 0x%lx ",
                               TARGETING::get_huid(i_target), l_expAddr );
                }
            }
        }
        else
        {
            // READ and WRITE equates to mss::exp::ib::gettMMIO32 and mss::exp::ib::putMMIO32 respectively.
            //  any other OP is invalid.
            if(i_opType == DeviceFW::READ)
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::ib::getMMIO32, i_target, l_expAddr, l_fapi2Buffer32);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> getMMIO32 failed for HUID 0x%x Address 0x%lx ",
                              TARGETING::get_huid(i_target), l_expAddr );
                }
                else
                {
                    // Put the contexts of the 32 bit buffer right justified into the 64 bit buffer
                    l_fapi2Buffer64.flush<0>();
                    l_fapi2Buffer64.insertFromRight<32,32>(l_fapi2Buffer32);
                    // Copy contents of 64 bit buffer to io_buffer
                    memcpy(io_buffer, reinterpret_cast<uint8_t *>(l_fapi2Buffer64.pointer()), sizeof(uint64_t));
                }
            }
            else
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::ib::putMMIO32, i_target, l_expAddr, l_fapi2Buffer32);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    TRACFCOMP( g_trac_expscom, ERR_MRK "mmioscomPerformOp> putMMIO32 failed for HUID 0x%x Address 0x%lx ",
                              TARGETING::get_huid(i_target), l_expAddr );
                }
            }

        }

    } while (0);
    return l_err;
}
}