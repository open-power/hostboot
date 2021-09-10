/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mdsaccess/mdsI2cScomdd.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
 *  @file mdsI2cScomdd.C
 *
 *  @brief Implementation of the I2C SCOM operations for the MDS
 *         (Micro-architectural Data Sampling) controller.
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include "mdsI2cScomdd.H"         // mdsI2cScomPerformOp
#include "mdsAccessTrace.H"       // g_trac_mdsaccess
#include "mdsAccessUtils.H"       // MDS_ACCESS::validateMdsI2cScomInputs
#include <errl/errlmanager.H>     // errlCommit
#include <lib/i2c/mds_i2c_scom.H> // i2c_get_scom/i2c_put_scom for target MDS_CTRL
#include <devicefw/driverif.H>    // DeviceFW::WILDCARD, DeviceFW::MDS_I2C
#include <mdsaccess/mdsaccess_reasoncodes.H>       // MDS_ACCESS::MOD_MDS_UTILS
#include <hwpf/fapi2/include/fapi2_hwp_executor.H> // FAPI_EXEC_HWP

namespace MDS_I2C_SCOMDD
{

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::I2CSCOM,
                      TARGETING::TYPE_MDS_CTLR,
                      mdsI2cScomPerformOp);


///////////////////////////////////////////////////////////////////////////////
// mdsI2cScomPerformOp
///////////////////////////////////////////////////////////////////////////////
errlHndl_t mdsI2cScomPerformOp(DeviceFW::OperationType i_opType,
                               TARGETING::Target*      i_target,
                               void*   io_buffer,
                               size_t& i_buflen,
                               int64_t i_accessType,
                               va_list i_args)
{
    errlHndl_t l_err(nullptr);
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);

    auto mutex = i_target->getHbMutexAttr<TARGETING::ATTR_SCOM_ACCESS_MUTEX>();
    recursive_mutex_lock(mutex);

    do
    {
        // The only extra arg should be the SCOM address
        uint64_t l_scomAddr = va_arg(i_args, uint64_t);

        // Validate the input parameters before proceeding
        l_err = MDS_ACCESS::validateMdsI2cScomInputs ( i_opType, i_target, io_buffer,
                                                       i_buflen, l_scomAddr );

        if( unlikely(nullptr != l_err) )
        {
            // Write a trace out to the buffer and then collect it on the log
            TRACFCOMP( g_trac_mdsaccess, ERR_MRK"mdsI2cScomPerformOp> Validation "
                       "of inputs failed see error logs for details ");
            l_err->collectTrace(MDS_ACCESS_COMP_NAME);
            break;
        }

        /// The I2C read/write of the MDS is only 32 bits.  Will make things
        /// easy for ourselves by creating a reference to the LSB of the io_buffer.
        // "Break up" the 64 bit input/output buffer into 32 bit chunks via 32 bit
        // integer pointer
        uint32_t *l_ptrDataBuffer32 = reinterpret_cast<uint32_t *>(io_buffer);
        // The MSB of the 64 bits of the input/output buffer is not needed nor
        // used, therefore set it to 0
        l_ptrDataBuffer32[0] = 0;
        // Create a reference to the LBS of the 64 bit input/output buffer for
        // easy retrieval/updates
        uint32_t &l_dataBuffer = l_ptrDataBuffer32[1];

        TRACDCOMP( g_trac_mdsaccess, INFO_MRK "mdsI2cScomPerformOp> HUID 0x%.8X, %s"
                   " 0x%.8X %s SCOM Address 0x%lX",
                   TARGETING::get_huid(i_target),
                   i_opType == DeviceFW::READ ? "READ" : "WRITE",
                   l_dataBuffer,
                   i_opType == DeviceFW::READ ? "from" : "to",
                   l_scomAddr );

        // Convert the given target to a fapi2 target
        fapi2::Target <fapi2::TARGET_TYPE_MDS_CTLR> l_fapi2Target(i_target);

        // The fapi2 put/get i2cScom interfaces require a 32bit fapi2::buffer.
        // Therefore copy the contents of the io_buffer via the reference l_dataBuffer
        fapi2::buffer<uint32_t> l_fapi2Buffer32(l_dataBuffer);

        // READ and WRITE equates to i2c_get_scom and i2c_put_scom respectively.
        // Any other OP is invalid.
        // i/o data is expected to be 4 bytes for MDS SCOMS.
        if (DeviceFW::READ == i_opType)
        {
            // Clear the output buffer, via the refence l_dataBuffer, and
            // the fapi2 buffer
            l_fapi2Buffer32 = l_dataBuffer = 0;

            // Make the get SCOM call
            FAPI_EXEC_HWP(l_rc , mss::mds::i2c::i2c_get_scom, l_fapi2Target,
                          static_cast<uint32_t>(l_scomAddr),  l_fapi2Buffer32);
            l_err = fapi2::rcToErrl(l_rc);

            if ( unlikely(nullptr != l_err) )
            {
                TRACFCOMP( g_trac_mdsaccess, ERR_MRK "mdsI2cScomPerformOp> "
                           "i2c_get_scom failed for HUID 0x%.8X, SCOM Address 0x%lX",
                           TARGETING::get_huid(i_target), l_scomAddr );
                break;
            }

            // Copy contents of fapi2 buffer to io_buffer via the reference l_dataBuffer
            l_dataBuffer = l_fapi2Buffer32;
        } // if (DeviceFW::READ == i_opType)
        else  // i_opType must be DeviceFW::WRITE, proceed with the write operation
        {
            // Make the put SCOM call
            FAPI_EXEC_HWP(l_rc , mss::mds::i2c::i2c_put_scom, l_fapi2Target,
                          static_cast<uint32_t>(l_scomAddr),  l_fapi2Buffer32);
            l_err = fapi2::rcToErrl(l_rc);

            if ( unlikely(nullptr != l_err) )
            {
                TRACFCOMP( g_trac_mdsaccess, ERR_MRK "mdsI2cScomPerformOp> i2c_put_scom "
                           "failed for HUID 0x%.8X, SCOM Address 0x%lX with value of 0x%.8X",
                           TARGETING::get_huid(i_target),
                           l_scomAddr,
                           l_fapi2Buffer32 );
                 break;
            }
        } // if (DeviceFW::READ == i_opType) .. else
    } while (0);

    // If there was an error during the scom access, deconfigure the target.
    // Errors with module ID of MDS_ACCESS::MOD_MDS_UTILS are input parameter validation
    // errors not scom access errors.
    if (l_err && (l_err->moduleId() != MDS_ACCESS::MOD_MDS_UTILS) )
    {
        // Sizes taken from plat_hwp_invoker.H
        l_err->collectTrace(FAPI_IMP_TRACE_NAME, 256);
        l_err->collectTrace(FAPI_TRACE_NAME, 384);

        // There was an error during the scom access, deconfigure the target
        const auto search_results = l_err->queryCallouts(i_target);
        using compare_enum = ERRORLOG::ErrlEntry::callout_search_criteria;

        // Check if we found any callouts for this
        if((search_results & compare_enum::TARGET_MATCH) == compare_enum::TARGET_MATCH)
        {
            // If we found a callout for this target w/o a DECONFIG,
            // edit the callout to include a deconfig
            if((search_results & compare_enum::DECONFIG_FOUND) != compare_enum::DECONFIG_FOUND)
            {
                l_err->setDeconfigState(i_target, HWAS::DELAYED_DECONFIG);
            }
        }
        else
        {
            // Add HW callout for MDS with low priority
            l_err->addHwCallout(i_target,
                                HWAS::SRCI_PRIORITY_LOW,
                                HWAS::DELAYED_DECONFIG,
                                HWAS::GARD_NULL);
        }
    }

    recursive_mutex_unlock(mutex);
    return l_err;
} // mdsI2cScomPerformOp

} // namespace MDS_I2C_SCOMDD
