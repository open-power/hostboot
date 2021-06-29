/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_occ_gpe_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_pm_occ_gpe_init.C
/// @brief Initialize or reset the targeted GPE0 and/or GPE1
///
// *HWP HWP Owner           :   Greg Still  <stillgs@us.ibm.com>
// *HWP Backup Owner        :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW  Owner           :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team                :   PM
// *HWP Level               :   3
// *HWP Consumed by         :   HS

///
/// High-level procedure flow:
/// @verbatim
///
///     Check for valid parameters
///     if PM_HALT {
///         for each GPE,
///             halt the GPE
///             wait for the GPE to become inactive
///             clear instruction address register
///             clear interrupt vector prefix register
///     }
///     if PM_START {
///         operation performed by OCC firmware.
///         Thus, noop
///     }
///
///  Procedure Prereq:
///     - System clocks are running
///
/// @endverbatim
///

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p10_pm_occ_gpe_init.H>
#include <p10_ppe_defs.H>
#include <p10_hcd_common.H>

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// OCC GPE Reset Function
//------------------------------------------------------------------------------
/// @brief Reset the targeted GPE0 and/or GPE1
///
/// param[in] i_target   Chip target
/// param[in] i_engine   Targeted engine:  GPE0, GPE1, GPEALL
///
/// @return FAPI2_RC_SUCCESS incase of success or error code
///
fapi2::ReturnCode pm_occ_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const occgpe::GPE_ENGINES i_engine);

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p10_pm_occ_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode,
    const occgpe::GPE_ENGINES i_engine)
{
    FAPI_IMP(">> p10_pm_occ_gpe_init");

    // Initialization:  perform order or dynamic operations to initialize
    // the GPEs using necessary Platform or Feature attributes.
    if (i_mode == pm::PM_START)
    {
        FAPI_INF("OCC-GPE initialization and start-up is performed by "
                 "OCC firmware. No action taken here");
    }
    // Reset:  perform reset of GPE engines so that they can be reconfigured
    // and reinitialized
    else if (i_mode == pm::PM_HALT)
    {
        if (i_engine == occgpe::GPE0 || i_engine == occgpe::GPEALL)
        {
            FAPI_TRY(pm_occ_gpe_reset(i_target, occgpe::GPE0),
                     "ERROR: Failed to reset GPE0");
        }

        if (i_engine == occgpe::GPE1 || i_engine == occgpe::GPEALL)
        {
            FAPI_TRY(pm_occ_gpe_reset(i_target, occgpe::GPE1),
                     "ERROR: Failed to reset GPE1");
        }
    }
    else
    {
        FAPI_ASSERT(false,
                    fapi2::PM_OCC_GPE_BAD_MODE()
                    .set_BADMODE(i_mode)
                    .set_CURPROC(i_target),
                    "Unknown mode 0x%X passed to p10_pm_occ_gpe_init", i_mode);
    }

fapi_try_exit:
    FAPI_IMP("<< p10_pm_occ_gpe_init");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_occ_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const occgpe::GPE_ENGINES i_engine)
{
    FAPI_IMP(">> pm_occ_gpe_reset");

    fapi2::buffer<uint64_t> l_data64;
    uint64_t l_controlReg = 0;
    uint64_t l_statusReg = 0;
    uint64_t l_instrAddrReg = 0;
    uint64_t l_intVecReg = 0;
    uint32_t l_pollCount = 10; // poll 10 times
    uint32_t l_timeout = 1; // in micro seconds;
    uint64_t l_gpeBaseAddress = 0x0;

    do
    {
        if (i_engine == occgpe::GPE0)
        {
            l_controlReg    =   GPE0_BASE_ADDRESS;
            l_statusReg     =   scomt::proc::TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIXSR;
            l_instrAddrReg  =   scomt::proc::TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIDBGPRO;
            l_intVecReg     =   scomt::proc::TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEIVPR;
            l_gpeBaseAddress = GPE0_BASE_ADDRESS;
        }
        else if (i_engine == occgpe::GPE1)
        {
            l_controlReg    =   GPE1_BASE_ADDRESS;
            l_statusReg     =   scomt::proc::TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIXSR;
            l_instrAddrReg  =   scomt::proc::TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO;
            l_intVecReg     =   scomt::proc::TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEIVPR;
            l_gpeBaseAddress = GPE1_BASE_ADDRESS;
        }

        // Halt the OCC GPE
        l_data64.flush<0>().insertFromRight(XCR_HALT, 1, 3);
        FAPI_TRY(putScom(i_target, l_controlReg, l_data64),
                 "ERROR: Failed to halt the OCC GPE");

        // Wait for OCC GPE to halt
        do
        {
            FAPI_TRY(fapi2::getScom(i_target, l_statusReg, l_data64),
                     "ERROR: Failed to get the OCC GPE status");

            if (l_data64.getBit<XSR_HALTED_STATE>() == 1)
            {
                FAPI_INF("OCC GPE has been halted");
                break;
            }

            FAPI_TRY(fapi2::delay(l_timeout * 1000, 200000),
                     " fapi2::delay Failed. ");   // In microseconds
        }
        while(--l_pollCount != 0);

        if (i_engine == occgpe::GPE0)
        {
            FAPI_ASSERT_NOEXIT((l_pollCount != 0),
                               fapi2::PM_OCC_GPE0_HALT_TIMEOUT()
                               .set_CHIP( i_target )
                               .set_GPE0_MODE( XCR_HALT )
                               .set_GPE0_BASE_ADDRESS( l_gpeBaseAddress ),
                               "OCC GPE0 could not be halted during reset operation.");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            break;
        }
        else if (i_engine == occgpe::GPE1)
        {
            FAPI_ASSERT_NOEXIT((l_pollCount != 0),
                               fapi2::PM_OCC_GPE1_HALT_TIMEOUT()
                               .set_CHIP( i_target )
                               .set_GPE1_MODE( XCR_HALT )
                               .set_GPE1_BASE_ADDRESS( l_gpeBaseAddress ),
                               "OCC GPE1 could not be halted during reset operation.");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            break;
        }

        //Clear status (Instruction Address) register
        l_data64.flush<0>();
        FAPI_TRY(fapi2::putScom(i_target, l_instrAddrReg, l_data64),
                 "ERROR: Failed to Clear the status register");

        //Clear Interrupt vector prefix register
        FAPI_TRY(putScom(i_target, l_intVecReg, l_data64),
                 "ERROR: Failed to clear interrupt vector prefix register");
    }
    while(0);

fapi_try_exit:
    FAPI_IMP("<< pm_occ_gpe_reset");
    return fapi2::current_err;
}
