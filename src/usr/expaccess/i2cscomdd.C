/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/expaccess/i2cscomdd.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
 *  @file i2cscomdd.C
 *
 *  @brief Implementation of I2C SCOM operations to OCMB chip             */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>      // errlCommit
#include <lib/i2c/exp_i2c_scom.H>  // i2c_get_scom
#include <errl/errludtarget.H>     // ErrlUserDetailsTarget
#include <hwpf/fapi2/include/fapi2_hwp_executor.H> // FAPI_EXEC_HWP
#include <expscom/expscom_reasoncodes.H> //  EXPSCOM::MOD_I2CSCOM_PERFORM_OP
#include "i2cscomdd.H" //i2cScomPerformOp
#include "expscom_trace.H" //g_trac_expscom
#include "expscom_utils.H" //validateInputs

namespace I2CSCOMDD
{

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::I2CSCOM,
                      TARGETING::TYPE_OCMB_CHIP,
                      i2cScomPerformOp);

///////////////////////////////////////////////////////////////////////////////
// See header for doxygen documentation
///////////////////////////////////////////////////////////////////////////////
errlHndl_t i2cScomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    errlHndl_t l_err = nullptr;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    // The only extra arg should be the scomAddress
    uint64_t l_scomAddr = va_arg(i_args,uint64_t);

    // The fapi2 put/get i2cScom interfaces require a fapi2::buffer so convert
    // to a uint64_t buffer (for IBM scom) and
    // uint32_t buffer (for Microchip scoms)
    fapi2::buffer<uint64_t> l_fapi2Buffer64(
                *reinterpret_cast<uint64_t *>(io_buffer));
    fapi2::buffer<uint32_t> l_fapi2Buffer32;
    l_fapi2Buffer64.extractToRight<32,32>(l_fapi2Buffer32);

    TRACDCOMP( g_trac_expscom, INFO_MRK "i2cScomPerformOp> HUID 0x%x %s 0x%.16x"
                " or 0x%.8x to  Address 0x%lx ",
                TARGETING::get_huid(i_target),
                i_opType == DeviceFW::READ ? "READ" : "WRITE",
                l_fapi2Buffer64(), l_fapi2Buffer32() , l_scomAddr );

    auto mutex = i_target->getHbMutexAttr<TARGETING::ATTR_SCOM_ACCESS_MUTEX>();
    recursive_mutex_lock(mutex);

    do
    {
        // First make sure the inputs are valid
        l_err = EXPSCOM::validateInputs ( i_opType, i_target, io_buflen,
                                            l_scomAddr );

        if(l_err)
        {
            // Write a trace out to the buffer and then collect it on the log
            // this way we can know if the fail was in i2cScomPerformOp or
            // mmioScomPerformOp
            TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> Validation "
                        "of inputs failed see error logs for details ");
            l_err->collectTrace(EXPSCOM_COMP_NAME);
            break;
        }

        fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(i_target);

        // Check if this is a IBM_SCOM address by &ing the address with
        // IBM_SCOM_INDICATOR
        // If the indicator is not set, then we will assume this is
        // a microChip address
        if( (l_scomAddr & mss::exp::i2c::IBM_SCOM_INDICATOR) ==
             mss::exp::i2c::IBM_SCOM_INDICATOR)
        {
            // READ and WRITE equates to i2c_get_scom and i2c_put_scom
            // respectively. any other OP is invalid
            // i/o data is expected to be 8 bytes for IBM scoms
            if(i_opType == DeviceFW::READ)
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_get_scom,
                              l_fapi_target, static_cast<uint32_t>(l_scomAddr),
                              l_fapi2Buffer64);

                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    // Sizes stolen from plat_hwp_invoker.H
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_err->collectTrace(FAPI_TRACE_NAME, 384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> "
                        "i2c_get_scom failed for HUID 0x%x Address 0x%lx ",
                        TARGETING::get_huid(i_target), l_scomAddr );
                    //no break, want common handling below
                }
                else
                {
                    // Copy contents of what we read to io_buffer
                    memcpy(io_buffer,
                        reinterpret_cast<uint8_t *>(l_fapi2Buffer64.pointer()),
                        sizeof(uint64_t));
                }
            }
            else
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_put_scom, l_fapi_target,
                     static_cast<uint32_t>(l_scomAddr), l_fapi2Buffer64);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    // Sizes stolen from plat_hwp_invoker.H
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_err->collectTrace(FAPI_TRACE_NAME, 384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> "
                            "i2c_put_scom failed for HUID 0x%x Address 0x%lx ",
                            TARGETING::get_huid(i_target), l_scomAddr );
                    //no break, want common handling below
                }
            }
        }
        else
        {
            // READ and WRITE equates to i2c_get_scom and i2c_put_scom
            // respectively. any other OP is invalid
            // i/o data is expected to be 4 bytes for Microchip scoms
            if(i_opType == DeviceFW::READ)
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_get_scom, l_fapi_target,
                     static_cast<uint32_t>(l_scomAddr), l_fapi2Buffer32);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    // Sizes stolen from plat_hwp_invoker.H
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_err->collectTrace(FAPI_TRACE_NAME, 384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> "
                        "i2c_get_scom failed for HUID 0x%x Address 0x%lx ",
                        TARGETING::get_huid(i_target), l_scomAddr );
                    //no break, want common handling below
                }
                else
                {
                    // Put the contexts of the 32 bit buffer right justified
                    // into the 64 bit buffer
                    l_fapi2Buffer64.flush<0>();
                    l_fapi2Buffer64.insertFromRight<32,32>(l_fapi2Buffer32);
                    // Copy contents of 64 bit buffer to io_buffer
                    memcpy(io_buffer,
                        reinterpret_cast<uint8_t *>(l_fapi2Buffer64.pointer()),
                        sizeof(uint64_t));
                }
            }
            else
            {
                FAPI_EXEC_HWP(l_rc , mss::exp::i2c::i2c_put_scom, l_fapi_target,
                    static_cast<uint32_t>(l_scomAddr), l_fapi2Buffer32);
                l_err = fapi2::rcToErrl(l_rc);
                if(l_err)
                {
                    // Sizes stolen from plat_hwp_invoker.H
                    l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_err->collectTrace(FAPI_TRACE_NAME, 384);
                    TRACFCOMP( g_trac_expscom, ERR_MRK "i2cScomPerformOp> "
                        "i2c_put_scom failed for HUID 0x%x Address 0x%lx ",
                        TARGETING::get_huid(i_target), l_scomAddr );
                    //no break, want common handling below
                }
            }
        }
        // If we hit any errors during the scom access, deconfigure the explorer
        if( l_err )
        {
            const auto search_results = l_err->queryCallouts(i_target);
            using compare_enum = ERRORLOG::ErrlEntry::callout_search_criteria;
            // Check if we found any callouts for this Explorer
            if((search_results & compare_enum::TARGET_MATCH) == compare_enum::TARGET_MATCH)
            {
                // If we found a callout for this Explorer w/o a DECONFIG,
                // edit the callout to include a deconfig
                if((search_results & compare_enum::DECONFIG_FOUND) != compare_enum::DECONFIG_FOUND)
                {
                    l_err->setDeconfigState(i_target, HWAS::DELAYED_DECONFIG);
                }
            }
            else
            {
                // Add HW callout for TPM with low priority
                l_err->addHwCallout(i_target,
                                    HWAS::SRCI_PRIORITY_LOW,
                                    HWAS::DELAYED_DECONFIG,
                                    HWAS::GARD_NULL);
            }
        }
    } while (0);

    recursive_mutex_unlock(mutex);
    return l_err;
}
}
