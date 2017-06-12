/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_eq_clear_atomic_lock.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
///
/// @file   p9_eq_clear_atomic_lock.C
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : SBE, HB

#include <hwp_error_info.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>
#include <p9_eq_clear_atomic_lock.H>

extern "C"
{
    fapi2::ReturnCode
    p9_eq_clear_atomic_lock ( const fapi2::ffdc_t& i_eq_target,
                              fapi2::ReturnCode&   io_rc )
    {
        FAPI_INF (">> p9_eq_clear_atomic_lock");
#if 0
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_value;

        // Note: Not using FAPI_TRY in FFDC callback context, as it can
        // potentially reset the fapi2::current_err
        // Note: No FFDC to be added to io_rc in this particular callback

        fapi2::Target<fapi2::TARGET_TYPE_EQ> l_eq =
            *(reinterpret_cast<const fapi2::Target<fapi2::TARGET_TYPE_EQ> *>
              (i_eq_target.ptr()));

        l_rc = fapi2::getScom (l_eq, EQ_ATOMIC_LOCK_REG, l_value);

        if ( (l_rc == fapi2::FAPI2_RC_SUCCESS) &&
             (l_value.getBit<EQ_ATOMIC_LOCK_REG_ENABLE>() == 1))
        {
            // Pick the atomic lock if it was already taken
            l_rc = fapi2::putScom (l_eq, EQ_ATOMIC_LOCK_REG, l_value);

            if (l_rc == fapi2::FAPI2_RC_SUCCESS)
            {
                l_value.flush<0>();
                // Clear the atomic lock
                l_rc = fapi2::putScom (l_eq, EQ_ATOMIC_LOCK_REG, l_value);
            }
        }

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR ("Could not clear eq atomic lock for FFDC");
        }

#endif
        FAPI_INF ("<< p9_eq_clear_atomic_lock");
        return fapi2::FAPI2_RC_SUCCESS; // always return success
    }
}

