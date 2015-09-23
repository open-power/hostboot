/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_pfet_control.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_pm_pfet_control.C
/// @brief Perform override operations to the EX PFET headers
///
// *HWP HWP Owner: Greg Still  <stillgs@us.ibm.com>
// *HWP FW  Owner: Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS
///
/// High-level procedure flow:
/// \verbatim
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///
///   PFVddCntlStat (0x106) layout
///     Control
///       0:1 - core_vdd_pfet_force_state 00: nop; 01: Voff; 10: Vret;
///             11: Von (4:5 must be 00)
///       2:3 - eco_vdd_pfet_force_state  00: nop; 01: Voff; 10: Vret;
///             11: Von (6:7 must be 00)
///       4   - core_vdd_pfet_val_override 0: disable; 1: enable
///             (0 enables 0:1)
///       5   - core_vdd_pfet_sel_override 0: disable; 1: enable(0 enables 0:1)
///       6   - eco_vdd_pfet_val_override  0: disable; 1: enable(0 enables 2:3)
///       7   - eco_vdd_pfet_sel_override  0: disable; 1: enable:(0 enables 2:3)
///
///     Status
///       42:45 - core_vdd_pfet_state
///               (42: Idle; 43: Increment; 44: Decrement; 45: Wait)
///       46:49 - not relevant
///       50:53 - eco_vdd_pfet_state
///               (50: Idle; 51: Increment; 52: Decrement; 53: Wait)
///       54:57 - not relevant
///
///   PFVcsCntlStat (0x10E) layout
///     Control
///       0:1 - core_vcs_pfet_force_state 00: nop; 01: Voff; 10: Vret;
//              11: Von (4:5 must be 00)
///       2:3 - eco_vcs_pfet_force_state  00: nop; 01: Voff; 10: Vret;
///             11: Von (6:7 must be 00)
///       4   - core_vcs_pfet_val_override 0: disable; 1: enable(0 enables 0:1)
///       5   - core_vcs_pfet_sel_override 0: disable; 1: enable(0 enables 0:1)
///       6   - eco_vcs_pfet_val_override  0: disable; 1: enable(0 enables 2:3)
///       7   - eco_vcs_pfet_sel_override  0: disable; 1: enable(0 enables 2:3)
///     Status
///       42:45 - core_vcs_pfet_state
///               (42: Idle; 43: Increment; 44: Decrement; 45: Wait)
///       46:49 - not relevant
///       50:53 - eco_vcs_pfet_state
//                (50: Idle; 51: Increment; 52: Decrement; 53: Wait)
///       54:57 - not relevant
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p9_pm_pfet_control.H"

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------------

enum PFETCONTROL_Constants
{
    CORE_FORCE_STATE        = 0,
    CORE_FORCE_LENGTH       = 2,  // 0:1
    ECO_FORCE_STATE         = 2,
    ECO_FORCE_LENGTH        = 2,  // 2:3
    CORE_OVERRIDE_STATE     = 4,
    CORE_OVERRIDE_LENGTH    = 2,  // 4:5
    ECO_OVERRIDE_STATE      = 6,
    ECO_OVERRIDE_LENGTH     = 2,  // 6:7
    CORE_OVERRIDE_SEL       = 22,
    CORE_OVERRIDE_SEL_LENGTH = 4,  // 22:25
    ECO_OVERRIDE_SEL        = 38,
    ECO_OVERRIDE_SEL_LENGTH = 4,  // 38:41
    CORE_FSM_IDLE_BIT       = 42,
    ECO_FSM_IDLE_BIT        = 50,
    PFET_MAX_IDLE_POLLS     = 16,
    PFET_POLL_WAIT          = 1000000,  // 100us (in ns units)
    PFET_POLL_WAIT_SIM      = 1000      // 100us (in sim cycles)
};

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

fapi2::ReturnCode pm_pfet_on(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_ex_number,
    const PMPFETTYPE_C::pfet_dom_t i_domain);

fapi2::ReturnCode pm_pfet_off(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_ex_number,
    const PMPFETTYPE_C::pfet_dom_t i_domain);

fapi2::ReturnCode pm_pfet_off_override(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_ex_number,
    const PMPFETTYPE_C::pfet_dom_t i_domain);

fapi2::ReturnCode pm_pfet_poll(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_ex_number,
    const uint64_t i_address,
    const PMPFETTYPE_C::pfet_dom_t i_domain);

fapi2::ReturnCode pm_pfet_read_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_address,
    const uint32_t i_bitoffset,
    char* o_state);

fapi2::ReturnCode pm_pfet_ivrm_fsm_fix(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_ex_number,
    const PMPFETTYPE_C::pfet_dom_t i_domain,
    const PMPFETTYPE_C::pfet_force_t i_op);

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_pm_pfet_control(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                   const uint8_t i_ex_number, PMPFETTYPE_C::pfet_dom_t i_domain,
                   PMPFETTYPE_C::pfet_force_t i_op)
{
    FAPI_IMP("p9_pm_pfet_control Enter");

    FAPI_IMP("p9_pm_pfet_control Exit");
    return fapi2::FAPI2_RC_SUCCESS;
}

///-----------------------------------------------------------------------------
/// pm_pfet_on
///
/// @brief  Turn a chiplet domain on - VCS first, then VDD
///
/// @param[in] i_target     Chip target
/// @param[in] i_ex_number  EX number
/// @param[in] i_domain     Domain: ECO, CORE, BOTH
///
/// @retval FAPI_RC_SUCCESS in case of Success,
/// @retval BAD_RETURN_CODE otherwise
fapi2::ReturnCode
pm_pfet_on(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
           const uint8_t i_ex_number,
           const PMPFETTYPE_C::pfet_dom_t i_domain)
{
    FAPI_IMP("p9_pm_pfet_on Enter");

    return fapi2::FAPI2_RC_SUCCESS;
}

///-----------------------------------------------------------------------------
/// pm_pfet_off
///
/// @brief  Turn a chiplet domain off - VDD first, then VCS
///
/// @param[in] i_target     Chip target
/// @param[in] i_ex_number  EX number
/// @param[in] i_domain     Domain: ECO, CORE, BOTH
///
/// @retval FAPI_RC_SUCCESS in case of success,
/// @retval BAD_RETURN_CODE otherwise
fapi2::ReturnCode
pm_pfet_off(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
            const uint8_t i_ex_number,
            const PMPFETTYPE_C::pfet_dom_t i_domain)
{
    FAPI_IMP("p9_pm_pfet_off Enter");

    return fapi2::FAPI2_RC_SUCCESS;
}

///-----------------------------------------------------------------------------
/// pm_pfet_off_override
///
/// @param[in] i_target     Chip target
/// @param[in] i_ex_number  EX number
/// @param[in] i_domain     Domain: ECO, CORE, BOTH
///
/// @retval FAPI_RC_SUCCESS in case of success,
/// @retval BAD_RETURN_CODE otherwise

fapi2::ReturnCode
pm_pfet_off_override(const
                     fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     const uint8_t i_ex_number,
                     const PMPFETTYPE_C::pfet_dom_t i_domain)
{
    FAPI_IMP("p9_pm_pfet_off_override Enter");

    return fapi2::FAPI2_RC_SUCCESS;

}
///-----------------------------------------------------------------------------
/// pm_pfet_poll
///
/// @param[in] i_target     Chip target
/// @param[in] i_address    Address to poll for PFET State
/// @param[in] i_domain     Domain: BOTH, ECO, CORE
///
/// @retval FAPI_RC_SUCCESS in case of success
/// @retval RC_PROCPM_PFET_TIMEOUT otherwise

fapi2::ReturnCode
pm_pfet_poll(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
             const uint8_t i_ex_number, const uint64_t i_address,
             const PMPFETTYPE_C::pfet_dom_t i_domain)
{
    FAPI_IMP("p9_pm_pfet_poll Enter");

    return fapi2::FAPI2_RC_SUCCESS;

}

//------------------------------------------------------------------------------
/// pm_pfet_read_state
///
/// @param[in]  i_target     Chip target
/// @param[in]  i_address    Address to poll for PFET State
/// @param[in]  i_bitoffset  Bit to poll on
/// @param[out] o_state      String representing the state of the controller
///                          "OFF", "ON", "REGULATION", "UNDEFINED"
/// @retval FAPI_RC_SUCCESS in case of success
/// @retval RC_PROCPM_PFET_TIMEOUT otherwise

fapi2::ReturnCode
pm_pfet_read_state(const
                   fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                   const uint64_t i_address,
                   const uint32_t i_bitoffset,
                   const char* o_state)
{
    FAPI_IMP("p9_pm_pfet_read_state Enter");

    return fapi2::FAPI2_RC_SUCCESS;

}

//-----------------------------------------------------------------------------
/// pm_pfet_ivrm_fsm_fix
///
/// @brief Fix ivrm FSM interference with PFET power off
/// @param[in] i_target     Chip target
/// @param[in] i_ex_number  EX number
/// @param[in] i_domain     Domain: BOTH, ECO, CORE
/// @param[in] i_op         Operation: VON, VOFF, NONE

fapi2::ReturnCode
pm_pfet_ivrm_fsm_fix(const
                     fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     const uint8_t i_ex_number,
                     const PMPFETTYPE_C::pfet_dom_t i_domain,
                     const PMPFETTYPE_C::pfet_force_t i_op)
{
    FAPI_IMP("p9_pm_pfet_ivrm_fsm_fix Enter");

    return fapi2::FAPI2_RC_SUCCESS;
}

