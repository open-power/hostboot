/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio_ocmb_common.C $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
 * @file mmio_ocmb_common.C
 * @brief Function definitions that are common to multiple types of OCMB
 * implementations, specifically Explorer and Odyssey.
 */

#include <devicefw/driverif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <mmio/mmio_reasoncodes.H>
#include <utils/chipids.H>
#include "mmio_ocmb_common.H"
#include "mmio_odyssey.H"
#include "mmio_explorer.H"

extern trace_desc_t* g_trac_mmio; //from mmio.C

namespace MMIOCOMMON
{

/*******************************************************************************
 *
 * See header file for comments
 */
errlHndl_t checkOcmbError(const TARGETING::TargetHandle_t i_ocmbTarget,
                          const uint64_t i_va,
                          const uint64_t i_accessLimit,
                          const uint64_t i_offset,
                          DeviceFW::OperationType i_opType,
                          bool& o_errorAddressMatches,
                          bool& o_errorAddressIsZero)
{
    errlHndl_t l_err = nullptr;
    uint64_t l_errAddr = 0;
    bool l_errorAddressMatches = false;
    bool l_errorAddressIsZero = false;
    const char* l_regStr = nullptr;

    // NOTE: mmio_memcpy could be doing multiple transactions.  This means
    //       we need to test the error address register against a
    //       range of values instead of a single value.
    // NOTE: Odyssey only uses the low 35 bits of the address for MMIO access
    const uint64_t l_mmioAddr35Lo = i_va & MASK_35BITS;
    const uint64_t l_mmioAddr35Hi = (i_va + i_accessLimit) & MASK_35BITS;

    do
    {
        const uint64_t* l_scomAddrs = nullptr;
        const auto l_ocmbChipId = i_ocmbTarget->getAttr<TARGETING::ATTR_CHIP_ID>();
        switch(l_ocmbChipId)
        {
            case POWER_CHIPID::EXPLORER_16:
                l_scomAddrs = MMIOEXP::REG_ADDRS;
                break;
            case POWER_CHIPID::ODYSSEY_16:
                l_scomAddrs = MMIOODY::REG_ADDRS;
                break;
            default:
                // Should never get here, but just in case...
                TRACFCOMP(g_trac_mmio, ERR_MRK
                          "checkOcmbError: Unsupported chip ID[0x%08x] on OCMB[0x%08x]",
                          l_ocmbChipId, get_huid(i_ocmbTarget));
                /*@
                 * @errortype
                 * @moduleid         MMIO::MOD_CHECK_OCMB_ERRORS
                 * @reasoncode       MMIO::RC_UNSUPPORTED_CHIPID
                 * @userdata1        OCMB HUID
                 * @userdata2        OCMB chip ID
                 * @devdesc          A MMIO operation was attempted
                 *                   on an unsupported OCMB chip.
                 * @custdesc         Unexpected memory subsystem firmware error.
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MMIO::MOD_CHECK_OCMB_ERRORS,
                                         MMIO::RC_UNSUPPORTED_CHIPID,
                                         get_huid(i_ocmbTarget),
                                         l_ocmbChipId,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
        }
        if( l_err ) { break; }

        // For access to CONFIG space, the MCFGERRA scom register
        // contains the first failing address.
        if(i_offset < OCMB_IB_MMIO_OFFSET)
        {
            auto l_reqSize = sizeof(l_errAddr);
            l_err = DeviceFW::deviceRead(
                                    i_ocmbTarget,
                                    &l_errAddr,
                                    l_reqSize,
                                    DEVICE_SCOM_ADDRESS(l_scomAddrs[MCFGERRA]));
            if(l_err)
            {
                TRACFCOMP(g_trac_mmio, ERR_MRK
                        "checkOcmbError: getscom(MCFGERRA) failed."
                        " huid[0x%08x]", get_huid(i_ocmbTarget));
                break;
            }
            l_regStr = "MCFGERRA";
        }
        // Otherwise, we are accessing a non-config address and, if there
        // is a failure, the MMIO address will show up in the lower 35 bits of
        // the MMIOERR register
        else
        {
            // If the transaction was a read to this error register then
            // we already know that it failed.  Don't keep trying to
            // read it or we could end up in a recursive loop.
            if((i_opType == DeviceFW::READ) &&
               (i_offset == MMIOCOMMON_scom_to_offset(l_scomAddrs[MMIOERR])))
            {
                break;
            }
            auto l_reqSize = sizeof(l_errAddr);
            l_err = DeviceFW::deviceRead(
                                     i_ocmbTarget,
                                     &l_errAddr,
                                     l_reqSize,
                                     DEVICE_SCOM_ADDRESS(l_scomAddrs[MMIOERR]));
            if(l_err)
            {
                TRACFCOMP(g_trac_mmio, ERR_MRK
                        "checkOcmbError: getscom(MMIOERR) failed."
                        " huid[0x%08x]", get_huid(i_ocmbTarget));
                break;
            }
            l_regStr = "MMIOERR";
        }

        // Check if error address from explorer is zero, meaning that
        // explorer did not detect an error.
        if(l_errAddr == 0)
        {
            l_errorAddressIsZero = true;
        }

        // Check if 35-bit error address is outside our transaction
        // access range
        const uint64_t l_errAddr35 = l_errAddr & MASK_35BITS;
        if((l_errAddr35 < l_mmioAddr35Lo) ||
           (l_errAddr35 >=  l_mmioAddr35Hi))
        {
            TRACDCOMP(g_trac_mmio,
                  "checkOcmbError: %s: 0x%09llx is not between 0x%09llx and"
                  " 0x%09llx on huid[0x%08x]",
                  l_regStr, l_errAddr, l_mmioAddr35Lo,
                  l_mmioAddr35Hi, get_huid(i_ocmbTarget));
            // Error address is outside our transaction range so this error
            // was not caused by our transaction.
            break;
        }

        TRACFCOMP(g_trac_mmio, ERR_MRK
                  "checkOcmbError: %s: 0x%09llx is between 0x%09llx and"
                  " 0x%09llx on huid[0x%08x]",
                  l_regStr, l_errAddr35, l_mmioAddr35Lo,
                  l_mmioAddr35Hi, get_huid(i_ocmbTarget));
        l_errorAddressMatches = true;

        // NOTE: These registers cannot be cleared without resetting the chip.

    }while(0);

    o_errorAddressMatches = l_errorAddressMatches;
    o_errorAddressIsZero = l_errorAddressIsZero;
    return l_err;
}

}; //namespace MMIOCOMMON
