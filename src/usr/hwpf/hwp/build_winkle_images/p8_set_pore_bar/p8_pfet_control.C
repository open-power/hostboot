/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pfet_control.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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
// $Id: p8_pfet_control.C,v 1.14 2014/03/13 20:48:21 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pfet_control.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
/// \file p8_pfet_control.C
/// \brief Perform override operations to the EX PFET headers
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
///       0:1 - core_vdd_pfet_force_state 00: nop; 01: Voff; 10: Vret; 11: Von (4:5 must be 00)
///       2:3 - eco_vdd_pfet_force_state  00: nop; 01: Voff; 10: Vret; 11: Von (6:7 must be 00)
///       4   - core_vdd_pfet_val_override 0: disable; 1: enable  (0 enables 0:1)
///       5   - core_vdd_pfet_sel_override 0: disable; 1: enable        (0 enables 0:1)
///       6   - eco_vdd_pfet_val_override  0: disable; 1: enable  (0 enables 2:3)
///       7   - eco_vdd_pfet_sel_override  0: disable; 1: enable        (0 enables 2:3)
///
///     Status
///       42:45 - core_vdd_pfet_state (42: Idle; 43: Increment; 44: Decrement; 45: Wait)
///       46:49 - not relevant
///       50:53 - eco_vdd_pfet_state (50: Idle; 51: Increment; 52: Decrement; 53: Wait)
///       54:57 - not relevant
///
///   PFVcsCntlStat (0x10E) layout
///     Control
///       0:1 - core_vcs_pfet_force_state 00: nop; 01: Voff; 10: Vret; 11: Von (4:5 must be 00)
///       2:3 - eco_vcs_pfet_force_state  00: nop; 01: Voff; 10: Vret; 11: Von (6:7 must be 00)
///       4   - core_vcs_pfet_val_override 0: disable; 1: enable  (0 enables 0:1)
///       5   - core_vcs_pfet_sel_override 0: disable; 1: enable        (0 enables 0:1)
///       6   - eco_vcs_pfet_val_override  0: disable; 1: enable  (0 enables 2:3)
///       7   - eco_vcs_pfet_sel_override  0: disable; 1: enable        (0 enables 2:3)
///     Status
///       42:45 - core_vcs_pfet_state (42: Idle; 43: Increment; 44: Decrement; 45: Wait)
///       46:49 - not relevant
///       50:53 - eco_vcs_pfet_state (50: Idle; 51: Increment; 52: Decrement; 53: Wait)
///       54:57 - not relevant
///
///  buildfapiprcd -e "../../xml/error_info/p8_pfet_errors.xml" -C p8_pm_utils.C p8_pfet_control.C
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p8_pm.H"
#include "p8_pm_utils.H"
#include "p8_pfet_control.H"


extern "C" {


using namespace fapi;

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

const uint32_t      CORE_FORCE_STATE        = 0;
const uint32_t      CORE_FORCE_LENGTH       = 2;  // 0:1
const uint32_t      ECO_FORCE_STATE         = 2;
const uint32_t      ECO_FORCE_LENGTH        = 2;  // 2:3
const uint32_t      CORE_OVERRIDE_STATE     = 4;
const uint32_t      CORE_OVERRIDE_LENGTH    = 2;  // 4:5
const uint32_t      ECO_OVERRIDE_STATE      = 6;
const uint32_t      ECO_OVERRIDE_LENGTH     = 2;  // 6:7
const uint32_t      CORE_OVERRIDE_SEL       = 22;
const uint32_t      CORE_OVERRIDE_SEL_LENGTH = 4; // 22:25
const uint32_t      ECO_OVERRIDE_SEL        = 38;
const uint32_t      ECO_OVERRIDE_SEL_LENGTH = 4;  // 38:41
const uint32_t      CORE_FSM_IDLE_BIT       = 42;
const uint32_t      ECO_FSM_IDLE_BIT        = 50;
const uint32_t      PFET_MAX_IDLE_POLLS     = 16;
const uint32_t      PFET_POLL_WAIT          = 1000000;  // 100us (in ns units)
const uint32_t      PFET_POLL_WAIT_SIM      = 1000;     // 100us (in sim cycles)


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

fapi::ReturnCode p8_pfet_on (const fapi::Target& i_target,
                             uint8_t             i_ex_number,
                             pfet_dom_t          i_domain);

fapi::ReturnCode p8_pfet_off(const fapi::Target& i_target,
                             uint8_t             i_ex_number,
                             pfet_dom_t          i_domain);

fapi::ReturnCode p8_pfet_off_override( const fapi::Target& i_target,
                             uint8_t             i_ex_number,
                             pfet_dom_t          i_domain);

fapi::ReturnCode p8_pfet_poll(const fapi::Target& i_target,
                            uint8_t              i_ex_number,
                            uint64_t             i_address,
                            pfet_dom_t           i_domain);

fapi::ReturnCode p8_pfet_read_state(const fapi::Target& i_target,
                            const uint64_t      i_address,
                            const uint32_t      i_bitoffset,
                            char *              o_state);

fapi::ReturnCode p8_pfet_ivrm_fsm_fix(const fapi::Target& i_target,
                            uint8_t             i_ex_number,
                            pfet_dom_t          i_domain,
                            pfet_force_t        i_op);

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// \param[in] i_target     Chip target
/// \param[in] i_ex_number  EX number
/// \param[in] i_domain     Domain: BOTH, ECO, CORE
/// \param[in] i_op         Operation: VON, VOFF, VOFF_OVERRIDE
///
/// \retval FAPI_RC_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode
p8_pfet_control(  const fapi::Target&   i_target,
                    uint8_t             i_ex_number,
                    pfet_dom_t          i_domain,
                    pfet_force_t        i_op
                 )
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data(64);
    ecmdDataBufferBase          pmgp0(64);
    ecmdDataBufferBase          gp3(64);
    uint64_t                    address = 0;
    bool                        restore_pmgp0 = false;
    bool                        restore_gp3 = false;

    // valid domain options
    const char * pfet_dom_names[] =
    {
      "BOTH", // write to both domains
      "ECO",  // eco only
      "CORE"  // core only
    };

    do
    {

        uint8_t ipl_mode = 0;
        l_rc = FAPI_ATTR_GET(ATTR_IS_MPIPL, NULL, ipl_mode);
        if (!l_rc.ok())
        {
            FAPI_ERR("fapiGetAttribute of ATTR_IS_MPIPL rc = 0x%x", (uint32_t)l_rc);
            break;
        }
        FAPI_INF("IPL mode = %s", ipl_mode ? "MPIPL" : "NORMAL");

        l_rc = p8_pm_pcbs_fsm_trace (i_target, i_ex_number,
                                "start of p8_pfet_control");
        if (!l_rc.ok()) { break; }

        // Check for valid operation parameter
        if ((i_op != VON) && (i_op != VOFF) && (i_op != VOFF_OVERRIDE))
        {
            FAPI_ERR("\tInvalid operation parm 0x%x", i_op);
            const uint8_t & EX = i_ex_number;
            const pfet_dom_t & DOMAIN = i_domain;
            const pfet_force_t & OPERATION = i_op;
            FAPI_SET_HWP_ERROR(l_rc, RC_PMPROC_PFETLIB_BAD_OP);
            break;
        }

        // Check for valid domain parameter
        if ((i_domain != CORE) && (i_domain != ECO) && (i_domain != BOTH))
        {
            FAPI_ERR("\tInvalid domain parm 0x%x", i_domain);
            const uint8_t & EX = i_ex_number;
            const pfet_dom_t & DOMAIN = i_domain;
            FAPI_SET_HWP_ERROR(l_rc, RC_PMPROC_PFETLIB_BAD_DOMAIN);
            break;
        }

        FAPI_INF("Processing target %s", i_target.toEcmdString());

        // Check the PM controls and Pervasive clocks are enabled.
        FAPI_DBG("\tChecking PMGP0(0) for enablement on EX %d ", i_ex_number);
        address = EX_PMGP0_0x100F0100 + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        // If not, enable them.
        if (data.isBitSet(0))
        {
            FAPI_INF("\tPM controls not enabled; enabling to allow control");
            restore_pmgp0 = true;
            pmgp0 = data;

            address = EX_PMGP0_AND_0x100F0101 + (0x01000000 * i_ex_number);
            e_rc |= data.flushTo1();
            e_rc |= data.clearBit(0);   // PM disable
            e_rc |= data.clearBit(39);  // Remove logical pervasive/pcbs-pm fence
            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }

            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }

            l_rc = p8_pm_pcbs_fsm_trace (i_target, i_ex_number,
                                "after of PM enablement");
            if (!l_rc.ok()) { break; }

            // Read to allow for Cronus 5.1 or 5.6 to look at the resultant setting
            address = EX_PMGP0_0x100F0100 + (0x01000000 * i_ex_number);
            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }

            // Clear PCB_EP_RESET and the Winkle Electrical Fence to allow
            // settings to take on non-reset values
            address = EX_GP3_0x100F0012 + (0x01000000 * i_ex_number);

            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }
            FAPI_DBG("\tEX_GP3_0x%08llX before  0x%16llX",
                                    address,
                                    data.getDoubleWord(0));

            if (data.isBitSet(1))
            {
                restore_gp3 = true;
                gp3 = data;

                // --- Glitchless Mux reset
                FAPI_DBG("\tClearing glitchless mux reset in GP3");
                address = EX_GP3_AND_0x100F0013 + (0x01000000 * i_ex_number);
                e_rc |= data.flushTo1();
                e_rc |= data.clearBit(2);   // Glitchless Mux reset
                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                l_rc=fapiPutScom( i_target, address, data );
                if(!l_rc.ok())
                {
                    FAPI_ERR("PutScom error 0x%08llX", address);
                    break;
                }

                // --- Test override
                FAPI_DBG("\tSetting test override in GP3");
                address = EX_GP3_OR_0x100F0014 + (0x01000000 * i_ex_number);
                e_rc |= data.flushTo0();
                e_rc |= data.setBit(20);    // Test override

                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                l_rc=fapiPutScom( i_target, address, data );
                if(!l_rc.ok())
                {
                    FAPI_ERR("PutScom error 0x%08llX", address);
                    break;
                }

                // --- End point reset
                FAPI_DBG("\tClearing PCB endpoint reset for allow for non-reset values.");
                address = EX_GP3_AND_0x100F0013 + (0x01000000 * i_ex_number);
                e_rc |= data.flushTo1();
                e_rc |= data.clearBit(1);   // End point reset

                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                l_rc=fapiPutScom( i_target, address, data );
                if(!l_rc.ok())
                {
                     FAPI_ERR("PutScom error 0x%08llX", address);
                    break;
                }

                // GP3
                address = EX_GP3_0x100F0012 + (0x01000000 * i_ex_number);
                l_rc = fapiGetScom(i_target, address, data);
                if (l_rc) {
                  FAPI_ERR("fapiGetScom error (addr: 0x%08llX)", address);
                  break;
                }

                FAPI_DBG("\tDebug Info:  GP3      (addr: 0x%08llX) - 0x%016llX", address, data.getDoubleWord(0));

                // --- Chiplet enable
                FAPI_DBG("\tTemporarily setting chiplet enable in GP3");
                address = EX_GP3_OR_0x100F0014 + (0x01000000 * i_ex_number);
                e_rc |= data.flushTo0();
                e_rc |= data.setBit(0);   // Chiplet enable

                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                l_rc=fapiPutScom( i_target, address, data );
                if(!l_rc.ok())
                {
                    FAPI_ERR("PutScom error 0x%08llX", address);
                    break;
                }

                // --- Vital THOLD, Winkle Fence
                FAPI_DBG("\tSetting Vital THOLD and Winkle Fence in GP3");
                address = EX_GP3_OR_0x100F0014 + (0x01000000 * i_ex_number);
                e_rc |= data.flushTo0();
                e_rc |= data.setBit(16);    // Vital THOLD
                e_rc |= data.setBit(27);    // Electrical Winkle Fence for PM

                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                l_rc=fapiPutScom( i_target, address, data );
                if(!l_rc.ok())
                {
                    FAPI_ERR("PutScom error 0x%08llX", address);
                    break;
                }

                FAPI_DBG("\tSetting DPLL, PERV THOLD and Perv ECO Fence in PMGP0");
                address = EX_PMGP0_OR_0x100F0102 + (0x01000000 * i_ex_number);
                e_rc |= data.flushTo0();
                e_rc |= data.setBit(3);     // DPLL THOLD
                e_rc |= data.setBit(4);     // PERV THOLD
                e_rc |= data.setBit(22);    // PERVASIVE_ECO_FENCE
                e_rc |= data.setBit(39);    // Remove logical pervasive/pcbs-pm fence/

                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                l_rc=fapiPutScom( i_target, address, data );
                if(!l_rc.ok())
                {
                    FAPI_ERR("PutScom error 0x%08llX", address);
                    break;
                }

                FAPI_DBG("\tClearing old winkle fence to match SBE implementation in PMGP0");
                address = EX_PMGP0_AND_0x100F0101 + (0x01000000 * i_ex_number);
                e_rc |= data.flushTo1();
                e_rc |= data.clearBit(23);  // Old

                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                l_rc=fapiPutScom( i_target, address, data );
                if(!l_rc.ok())
                {
                    FAPI_ERR("PutScom error 0x%08llX", address);
                    break;
                }

                // Clear Special Wakeups present in uninitialized chiplets
                FAPI_DBG("\tClear Special Wakeups present in uninitialized chiplets");
                address = EX_PMSpcWkupOCC_REG_0x100F010C + (0x01000000 * i_ex_number);
                e_rc |= data.flushTo0();

                if (e_rc)
                {
                    FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                    l_rc.setEcmdError(e_rc);
                    break;
                }

                l_rc=fapiPutScom( i_target, address, data );
                if(!l_rc.ok())
                {
                    FAPI_ERR("PutScom error 0x%08llX", address);
                    break;
                }

                l_rc = p8_pm_pcbs_fsm_trace (i_target, i_ex_number,
                                "after of GP3(0) handling");
                if (!l_rc.ok()) { break; }
            }
        }

        // Reads to allow for Cronus 5.1 or 5.6 to look at the resultant setting
        address = EX_PMGP0_0x100F0100 + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        address = EX_GP3_0x100F0012 + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        l_rc = p8_pm_pcbs_fsm_trace (i_target, i_ex_number,
                                "before transition choice");
        if (!l_rc.ok()) { break; }

        // Off
        if (i_op == VOFF)
        {
            l_rc=p8_pfet_off(i_target, i_ex_number, i_domain);
            if(!l_rc.ok())
            {
                FAPI_ERR("\tPFET turn off of %s domains failed",
                            pfet_dom_names[i_domain]);
                break;
            }
        }
        else if (i_op == VOFF_OVERRIDE)
        {
            l_rc=p8_pfet_off_override(i_target, i_ex_number, i_domain);
            if(!l_rc.ok())
            {
                FAPI_ERR("\tPFET turn off of %s domains failed",
                            pfet_dom_names[i_domain]);
                break;
            }
        }
        // On
        else if (i_op == VON)
        {
            l_rc=p8_pfet_on(i_target, i_ex_number, i_domain);
            if(!l_rc.ok())
            {
                FAPI_ERR("\tPFET turn on of %s domains failed",
                            pfet_dom_names[i_domain]);
                break;
            }

            l_rc = p8_pm_pcbs_fsm_trace (i_target, i_ex_number,
                                "after VON handling");
            if (!l_rc.ok()) { break; }

        }

        // Restore GP3 except for reinit_endp as this will force power on
        if (restore_gp3)
        {
            address = EX_GP3_0x100F0012 + (0x01000000 * i_ex_number);
            e_rc |= gp3.clearBit(1);   // End point reset

            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }
            FAPI_DBG("\tRestoring GP3 with the exception of endpoint reset:  0x%16llX", gp3.getDoubleWord(0));
            l_rc=fapiPutScom( i_target, address, gp3 );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }
        }

        // Restore PMGP0 settings
        if (restore_pmgp0)
        {
            address = EX_PMGP0_0x100F0100 + (0x01000000 * i_ex_number);
            FAPI_DBG("\tRestoring PMGP0: 0x%16llX", pmgp0.getDoubleWord(0));
            l_rc=fapiPutScom( i_target, address, pmgp0 );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }
        }


    } while(0);



    return l_rc;
}

///-----------------------------------------------------------------------------
/// Turn a chiplet domain on - VCS first, then VDD
///
/// \param[in] i_target     Chip target
/// \param[in] i_ex_number  EX number
/// \param[in] i_domain     Domain: ECO, CORE, BOTH
///
/// \retval FAPI_RC_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode
p8_pfet_on( const fapi::Target& i_target,
            uint8_t             i_ex_number,
            pfet_dom_t          i_domain
          )
{

    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data(64);
    uint64_t                    address;
    bool                        b_core = false;
    bool                        b_eco = false;

    do
    {
        if ((i_domain == CORE) || (i_domain == BOTH))
        {
            b_core = true;
        }
        if ((i_domain == ECO) || (i_domain == BOTH))
        {
            b_eco = true;
        }

        uint8_t  chipHasPFETPoweroffBug = 0;
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_EC_PFET_POWEROFF_BUG,
                             &i_target,
                             chipHasPFETPoweroffBug);
        if(!l_rc.ok())
        {
     		FAPI_ERR("Error querying Chip EC feature: "
                     "ATTR_CHIP_EC_PFET_POWEROFF_BUG");
            break;
        }

        if (chipHasPFETPoweroffBug)
        {
            l_rc = p8_pfet_ivrm_fsm_fix(i_target,
                                        i_ex_number,
                                        i_domain,
                                        VON);
            if(!l_rc.ok())
            {
                FAPI_ERR("PFET IVMR fix error");
                break;
            }

        }
        // VCS ---------------------

        FAPI_INF("Turning on VCS");
        address = EX_PFET_CTL_REG_0x100F010E + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        if (b_core)
        {
            FAPI_DBG("\tEnabling turn on of Core VDD");
            e_rc |= data.clearBit(CORE_OVERRIDE_STATE, CORE_OVERRIDE_LENGTH);
            e_rc |= data.clearBit(CORE_FORCE_STATE, CORE_FORCE_LENGTH);
            e_rc |= data.insert((uint32_t)VON, CORE_FORCE_STATE, CORE_FORCE_LENGTH, 30);
        }

        if (b_eco)
        {
            FAPI_DBG("\tEnabling turn on of ECO VDD");
            e_rc |= data.clearBit(ECO_OVERRIDE_STATE, ECO_OVERRIDE_LENGTH);
            e_rc |= data.clearBit(ECO_FORCE_STATE, ECO_FORCE_LENGTH);
            e_rc |= data.insert((uint32_t)VON, ECO_FORCE_STATE, ECO_FORCE_LENGTH, 30);
        }


        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // Poll for completion
        l_rc=p8_pfet_poll(i_target, i_ex_number, address, i_domain);
        if(!l_rc.ok())
        {
            FAPI_ERR("PFET poll timeout turning on VCS");
            break;
        }

        // Put the controls back to a Nop state
        e_rc |= data.clearBit(CORE_FORCE_STATE, CORE_FORCE_LENGTH);
        e_rc |= data.clearBit(ECO_FORCE_STATE, ECO_FORCE_LENGTH);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // VDD ---------------------

        FAPI_INF("Turning on VDD for EX %d", i_ex_number);
        address = EX_PFET_CTL_REG_0x100F0106 + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        if (b_core)
        {
            FAPI_DBG("\tEnabling turn on of Core VDD");
            e_rc |= data.clearBit(CORE_OVERRIDE_STATE, CORE_OVERRIDE_LENGTH);
            e_rc |= data.clearBit(CORE_FORCE_STATE, CORE_FORCE_LENGTH);
            e_rc |= data.insert((uint32_t)VON, CORE_FORCE_STATE, CORE_FORCE_LENGTH, 30);
        }

        if (b_eco)
        {
            FAPI_DBG("\tEnabling turn on of ECO VDD");
            e_rc |= data.clearBit(ECO_OVERRIDE_STATE, ECO_OVERRIDE_LENGTH);
            e_rc |= data.clearBit(ECO_FORCE_STATE, ECO_FORCE_LENGTH);
            e_rc |= data.insert((uint32_t)VON, ECO_FORCE_STATE, ECO_FORCE_LENGTH, 30);
        }

        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // Poll for completion
        l_rc=p8_pfet_poll(i_target, i_ex_number, address, i_domain);
        if(!l_rc.ok())
        {
            FAPI_ERR("PFET poll timeout turning on VDD");
            break;
        }

        // Put the controls back to a Nop state
        e_rc |= data.clearBit(CORE_FORCE_STATE, CORE_FORCE_LENGTH);
        e_rc |= data.clearBit(ECO_FORCE_STATE, ECO_FORCE_LENGTH);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

    } while(0);
    return l_rc;
}

///-----------------------------------------------------------------------------
/// Turn a chiplet domain off - VDD first, then VCS
///
/// \param[in] i_target     Chip target
/// \param[in] i_ex_number  EX number
/// \param[in] i_domain     Domain: ECO, CORE, BOTH
///
/// \retval FAPI_RC_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode
p8_pfet_off( const fapi::Target& i_target,
             uint8_t             i_ex_number,
             pfet_dom_t          i_domain
           )
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data(64);
    uint64_t                    address;
    bool                        b_core = false;
    bool                        b_eco = false;

    uint8_t                     core_vret_voff_value;
    uint8_t                     eco_vret_voff_value;

    do
    {
        if ((i_domain == CORE) || (i_domain == BOTH))
        {
            b_core = true;
        }
        if ((i_domain == ECO) || (i_domain == BOTH))
        {
            b_eco = true;
        }

        uint8_t  chipHasPFETPoweroffBug = 0;
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_EC_PFET_POWEROFF_BUG,
                             &i_target,
                             chipHasPFETPoweroffBug);
        if(!l_rc.ok())
        {
     		FAPI_ERR("Error querying Chip EC feature: "
                     "ATTR_CHIP_EC_PFET_POWEROFF_BUG");
            break;
        }

        if (chipHasPFETPoweroffBug)
        {
            l_rc = p8_pfet_ivrm_fsm_fix(i_target,
                                        i_ex_number,
                                        i_domain,
                                        VOFF);
            if(!l_rc.ok())
            {
                FAPI_ERR("PFET IVMR fix error");
                break;
            }
        }

        // Check if iVRM Bypasses are active
        address = EX_PCBS_iVRM_Control_Status_Reg_0x100F0154 +
                        (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        FAPI_DBG("\tEX_PCBS_iVRM_Control_Status_Reg_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        e_rc |= data.flushTo0();
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        FAPI_DBG("\tEX_PCBS_iVRM_Control_Status_Reg_0x%08llX after  0x%16llX",
                                address,
                                data.getDoubleWord(0));


        // As we need to turn the PFETs off, ensure the stage pointers to the
        // OFF value are in place (and not assumed).
        core_vret_voff_value = 0xBB;
        eco_vret_voff_value = 0xBB;

        // -------------------------------------------------------------
        FAPI_DBG("\tSetting Core Voff Settings");
        e_rc |= data.insertFromRight(core_vret_voff_value, 0, 8);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        address = EX_CorePFVRET_REG_0x100F0130 + (0x01000000 * i_ex_number);
        l_rc=fapiPutScom(i_target, address, data );
        if (l_rc)
        {
            FAPI_ERR("PutScom error 0x%08llu", address);
            break;
        }

        // -------------------------------------------------------------
        FAPI_DBG("\tSetting ECO Voff Settings");
        e_rc |= data.insertFromRight(eco_vret_voff_value, 0, 8);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        address = EX_ECOPFVRET_REG_0x100F0150 + (0x01000000 * i_ex_number);
        l_rc=fapiPutScom(i_target, address, data );
        if (l_rc)
        {
            FAPI_ERR("PutScom error 0x%08llu", address);
            break;
        }

        // Ensure that the chiplet is electrically fenced before shutting down
        // the power
        FAPI_INF("Force EX electrical fence ON before turning off power");
        e_rc |= data.flushTo0();
        e_rc |= data.setBit(27);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        address = EX_GP3_OR_0x100F0014 + (0x01000000 * i_ex_number);
        l_rc=fapiPutScom( i_target, address, data);
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }
        
        address = EX_GP3_0x100F0012 + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data);
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        FAPI_DBG("\tEX_GP3_0x%08llX with electrical fence set 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        // VDD ---------------------

        FAPI_INF("Turning off VDD");

        address = EX_PFET_CTL_REG_0x100F0106 + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        if (b_core)
        {
            FAPI_DBG("\tClearing overrides to enable turn off of Core VDD");
            e_rc |= data.clearBit(CORE_OVERRIDE_STATE, CORE_OVERRIDE_LENGTH);
            e_rc |= data.clearBit(CORE_FORCE_STATE, CORE_FORCE_LENGTH);
            e_rc |= data.insert((uint32_t)VOFF, CORE_FORCE_STATE, CORE_FORCE_LENGTH, 30);
        }

        if (b_eco)
        {
            FAPI_DBG("\tClearing overrides to enable turn off of ECO VDD");
            e_rc |= data.clearBit(ECO_OVERRIDE_STATE, ECO_OVERRIDE_LENGTH);
            e_rc |= data.clearBit(ECO_FORCE_STATE, ECO_FORCE_LENGTH);
            e_rc |= data.insert((uint32_t)VOFF, ECO_FORCE_STATE, ECO_FORCE_LENGTH, 30);
        }

        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX after  0x%16llX",
                                address,
                                data.getDoubleWord(0));

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // Poll for completion
        l_rc=p8_pfet_poll(i_target, i_ex_number, address, i_domain);
        if(!l_rc.ok())
        {
            FAPI_ERR("PFET poll timeout turning off VDD");
            break;
        }

        FAPI_DBG("Put the controls back to a Nop state");
        e_rc |= data.clearBit(CORE_FORCE_STATE, CORE_FORCE_LENGTH);
        e_rc |= data.clearBit(ECO_FORCE_STATE, ECO_FORCE_LENGTH);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        FAPI_DBG("\tNOP 0x%16llX", data.getDoubleWord(0));
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // Read to allow for Cronus 5.1 or 5.6 to look at the resultant setting
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        // VCS ---------------------

        FAPI_INF("Turning off VCS");
        address = EX_PFET_CTL_REG_0x100F010E + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        if (b_core)
        {
            FAPI_DBG("\tClearing overrides to enable turn off of Core VDD");
            e_rc |= data.clearBit(CORE_OVERRIDE_STATE, CORE_OVERRIDE_LENGTH);
            e_rc |= data.clearBit(CORE_FORCE_STATE, CORE_FORCE_LENGTH);
            e_rc |= data.insert((uint32_t)VOFF, CORE_FORCE_STATE, CORE_FORCE_LENGTH, 30);
        }

        if (b_eco)
        {
            FAPI_DBG("\tClearing overrides to enable turn off of ECO VDD");
            e_rc |= data.clearBit(ECO_OVERRIDE_STATE, ECO_OVERRIDE_LENGTH);
            e_rc |= data.clearBit(ECO_FORCE_STATE, ECO_FORCE_LENGTH);
            e_rc |= data.insert((uint32_t)VOFF, ECO_FORCE_STATE, ECO_FORCE_LENGTH, 30);
        }

        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX after  0x%16llX",
                                address,
                                data.getDoubleWord(0));

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // Poll for completion
        l_rc=p8_pfet_poll(i_target, i_ex_number, address, i_domain);
        if(!l_rc.ok())
        {
            FAPI_ERR("PFET poll timeout turning on VCS");
            break;
        }

        FAPI_DBG("\tPut the controls back to a Nop state");
        e_rc |= data.clearBit(CORE_FORCE_STATE, CORE_FORCE_LENGTH);
        e_rc |= data.clearBit(ECO_FORCE_STATE, ECO_FORCE_LENGTH);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        FAPI_DBG("\tNOP 0x%16llX", data.getDoubleWord(0));
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // Read to allow for Cronus 5.1 or 5.6 to look at the resultant setting
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

    } while(0);
    return l_rc;
}

///-----------------------------------------------------------------------------
/// Turn a chiplet domain off - VDD first, then VCS
///
/// \param[in] i_target     Chip target
/// \param[in] i_ex_number  EX number
/// \param[in] i_domain     Domain: ECO, CORE, BOTH
///
/// \retval FAPI_RC_SUCCESS if something good happens,
/// \retval BAD_RETURN_CODE otherwise
fapi::ReturnCode
p8_pfet_off_override( const fapi::Target& i_target,
             uint8_t             i_ex_number,
             pfet_dom_t          i_domain
           )
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data(64);
    uint64_t                    address;
    bool                        b_core = false;
    bool                        b_eco = false;
    const uint32_t              core_regulation_finger = 10;
    const uint32_t              eco_regulation_finger = 26;

    do
    {
         if ((i_domain == CORE) || (i_domain == BOTH))
        {
            b_core = true;
        }
        if ((i_domain == ECO) || (i_domain == BOTH))
        {
            b_eco = true;
        }

        uint8_t  chipHasPFETPoweroffBug = 0;
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_EC_PFET_POWEROFF_BUG,
                             &i_target,
                             chipHasPFETPoweroffBug);
        if(!l_rc.ok())
        {
     		FAPI_ERR("Error querying Chip EC feature: "
                     "ATTR_CHIP_EC_PFET_POWEROFF_BUG");
            break;
        }

        if (chipHasPFETPoweroffBug)
        {
            l_rc = p8_pfet_ivrm_fsm_fix(i_target,
                                        i_ex_number,
                                        i_domain,
                                        VOFF);
            if(!l_rc.ok())
            {
                FAPI_ERR("PFET IVMR fix error");
                break;
            }
        }

        // Check if iVRM Bypasses are active
        address = EX_PCBS_iVRM_Control_Status_Reg_0x100F0154 +
                        (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        FAPI_DBG("\tEX_PCBS_iVRM_Control_Status_Reg_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        e_rc |= data.flushTo0();
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        FAPI_DBG("\tEX_PCBS_iVRM_Control_Status_Reg_0x%08llX after  0x%16llX",
                                address,
                                data.getDoubleWord(0));

        // VDD ---------------------

        FAPI_INF("Turning off VDD with controller override");

        address = EX_PFET_CTL_REG_0x100F0106 + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        // Turn off the non-regulation fingers (relative bits 1:11)
        for (int i = 1; i <= 11; i++)
        {
            if (b_core)
            {
                FAPI_DBG("\tClearing Core VDD finger %d", core_regulation_finger+i);
                e_rc |= data.clearBit(core_regulation_finger+i);
            }

            if (b_eco)
            {
                FAPI_DBG("\tClearing ECO VDD finger %d", eco_regulation_finger+i);
                e_rc |= data.clearBit(eco_regulation_finger+i);
            }

            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }
            FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX after  0x%16llX",
                                    address,
                                    data.getDoubleWord(0));

            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }

            // Read to allow for Cronus 5.1 or 5.6 to look at the resultant setting
            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }
        }

        // Turn off the regulation finger:  core first, then ECO
        if (b_core)
        {
            FAPI_DBG("\tClearing Core VDD regulation finger %d", core_regulation_finger);
            e_rc |= data.clearBit(core_regulation_finger);
        }

        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        if (b_eco)
        {
            FAPI_DBG("\tClearing ECO regulation VDD finger %d", eco_regulation_finger);
            e_rc |= data.clearBit(eco_regulation_finger);
        }

        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }




        // VCS ---------------------

        FAPI_INF("Turning off VCS with controller override");

        address = EX_PFET_CTL_REG_0x100F010E + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX before 0x%16llX",
                                address,
                                data.getDoubleWord(0));

        // Turn off the non-regulation fingers (relative bits 1:11)
        for (int i = 1; i <= 11; i++)
        {
            if (b_core)
            {
                FAPI_DBG("\tClearing Core VCS finger %d", core_regulation_finger+i);
                e_rc |= data.clearBit(core_regulation_finger+i);
            }

            if (b_eco)
            {
                FAPI_DBG("\tClearing ECO VCS finger %d", eco_regulation_finger+i);
                e_rc |= data.clearBit(eco_regulation_finger+i);
            }

            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }
            FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX after  0x%16llX",
                                    address,
                                    data.getDoubleWord(0));

            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }
        }

        // Turn off the regulation finger:  core first, then ECO
        if (b_core)
        {
            FAPI_DBG("\tClearing Core VCS regulation finger %d", core_regulation_finger);
            e_rc |= data.clearBit(core_regulation_finger);
        }

        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        if (b_eco)
        {
            FAPI_DBG("\tClearing ECO regulation VCS finger %d", eco_regulation_finger);
            e_rc |= data.clearBit(eco_regulation_finger);
        }

        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }

        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        if (b_core)
        {
            FAPI_DBG("\tClearing Core VCS overrides %d", core_regulation_finger);
            e_rc |= data.clearBit(core_regulation_finger);

            FAPI_DBG("\tSetting the select value to indicate OFF for ECO VCS");
            e_rc |= data.setBit(5);
            e_rc |= data.insert((uint32_t)0xB, CORE_OVERRIDE_SEL, CORE_OVERRIDE_SEL_LENGTH, 28);
        }


        // Read to allow for Cronus 5.1 or 5.6 to look at the resultant setting
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

    } while(0);
    return l_rc;
}

/// \param[in] i_target     Chip target
/// \param[in] i_address    Address to poll for PFET State
/// \param[in] i_domain     Domain: BOTH, ECO, CORE
///
/// \retval FAPI_RC_SUCCESS
/// \retval RC_PROCPM_PFET_TIMEOUT otherwise
fapi::ReturnCode
p8_pfet_poll(   const fapi::Target& i_target,
                uint8_t             i_ex_number,
                uint64_t            i_address,
                pfet_dom_t          i_domain)
{
    fapi::ReturnCode            l_rc;
    ecmdDataBufferBase          data(64);
    uint32_t                    i = 0;
    bool                        b_core_idle = false;
    bool                        b_eco_idle = false;
    char                        core_state_buffer[32];
    char                        eco_state_buffer[32];

    uint32_t                    CORE_PFET_IDLE_STATE_START_BIT = 46;
    uint32_t                    ECO_PFET_IDLE_STATE_START_BIT = 54;

    do
    {
        FAPI_DBG("\tPoll for FSM to go back to idle");
        for (i=0; i<=PFET_MAX_IDLE_POLLS; i++)
        {
            l_rc=fapiGetScom(i_target, i_address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", i_address);
                break;
            }

            if ((i_domain == CORE) || (i_domain == BOTH))
            {
                if (data.isBitSet(CORE_FSM_IDLE_BIT))
                {
                    FAPI_DBG("\tCore domain idle");
                    b_core_idle=true;
                }
            }
            if ((i_domain == ECO) || (i_domain == BOTH))
            {
                if (data.isBitSet(ECO_FSM_IDLE_BIT))
                {
                    FAPI_DBG("\tECO domain idle");
                    b_eco_idle=true;
                }
            }

            // Exit the polling loop if selected are idle
            if ( ((i_domain == BOTH) && b_core_idle && b_eco_idle) ||
                 ((i_domain == CORE) && b_core_idle) ||
                 ((i_domain == ECO) && b_eco_idle) )
            {
                FAPI_DBG("\tPoll complete");

                // Check for Core State
                l_rc = p8_pfet_read_state(   i_target,
                                        i_address,
                                        CORE_PFET_IDLE_STATE_START_BIT,
                                        core_state_buffer );
                if(!l_rc.ok())
                {
                    FAPI_ERR("pfet_read_state Core error 0x%08llX", i_address);
                    break;
                }

                // Check for ECO State
                l_rc = p8_pfet_read_state(   i_target,
                                        i_address,
                                        ECO_PFET_IDLE_STATE_START_BIT,
                                        eco_state_buffer );
                if(!l_rc.ok())
                {
                    FAPI_ERR("pfet_read_state ECO error 0x%08llX", i_address);
                    break;
                }

                FAPI_DBG("\tCore State: %s; ECO State: %s", core_state_buffer, eco_state_buffer);
                break;
            }

            // Delay between polls
            l_rc=fapiDelay( PFET_POLL_WAIT, PFET_POLL_WAIT_SIM );
            if(!l_rc.ok())
            {
                FAPI_ERR("fapiDelay error");
                break;
            }
        }

        if (l_rc)
        {
            // Error in for loop
            break;
        }

        if (i >= PFET_MAX_IDLE_POLLS)
        {
            // Poll timeout
            FAPI_ERR("\tERROR: Polling timeout ");
            const uint64_t& ADDRESS = i_address;
            const uint64_t& PFETCONTROLVALUE = data.getDoubleWord(0);
            const uint64_t& DOMAIN = i_domain;
            const fapi::Target & PROC_CHIP_IN_ERROR = i_target;
            const uint8_t & EX_NUMBER_IN_ERROR = i_ex_number;
            FAPI_SET_HWP_ERROR(l_rc, RC_PROCPM_PFETLIB_TIMEOUT);
            break;
        }
    } while(0);
    return l_rc;
}

//------------------------------------------------------------------------------
/// p8_pfet_read_state
///
/// \param[in]  i_target     Chip target
/// \param[in]  i_address    Address to poll for PFET State
/// \param[in]  i_bitoffset  Bit to poll on
/// \param[out] o_state      String representing the state of the controller
///                             "OFF", "ON", "REGULATION", "UNDEFINED"
fapi::ReturnCode
p8_pfet_read_state(const fapi::Target& i_target,
                const uint64_t      i_address,
                const uint32_t      i_bitoffset,
                char *              o_state)
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data;
    uint32_t                    value;

    do
    {
        l_rc=fapiGetScom( i_target, i_address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", i_address);
            break;
        }

        FAPI_DBG("\tEX_PFET_CTL_REG_0x%08llX 0x%16llX",
                                i_address,
                                data.getDoubleWord(0));


        e_rc = data.extractToRight(&value,i_bitoffset,4);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }


        if (value == 0xB)
        {
            strcpy(o_state, "OFF");
        }
        else if (value == 0)
        {
            strcpy(o_state, "ON");
        }
        else if (value == 8)
        {
            strcpy(o_state, "REGULATION");
        }
        else
        {
            strcpy(o_state, "UNDEFINED");
        }

   } while(0);
   return l_rc;
}

//------------------------------------------------------------------------------
/// p8_pfet_ivrm_fsm_fix
///  Fix ivrm FSM interference with PFET power off
/// \param[in] i_target     Chip target
/// \param[in] i_ex_number  EX number
/// \param[in] i_domain     Domain: BOTH, ECO, CORE
/// \param[in] i_op         Operation: VON, VOFF, NONE
//------------------------------------------------------------------------------
fapi::ReturnCode
p8_pfet_ivrm_fsm_fix(const fapi::Target& i_target,
                     uint8_t             i_ex_number,
                     pfet_dom_t          i_domain,
                     pfet_force_t        i_op)
{
    fapi::ReturnCode            l_rc;
    uint32_t                    e_rc = 0;
    ecmdDataBufferBase          data(64);
    uint64_t                    address;
    uint32_t                    value;

    ecmdDataBufferBase          gp3(64);

    ecmdDataBufferBase          pmgp0(64);
    const uint32_t              PM_DISABLE_BIT = 0;
    const uint32_t              PFET_WORKAROUND_MARK_PMGP0_BIT = 47;

    ecmdDataBufferBase          pcbspm_mode(64);
    const uint32_t              TIMER_MODE_BIT = 7;

    ecmdDataBufferBase          cpm_dpll_parm(64);
    const uint32_t              DPLL_LOCK_TIMER_BIT = 15;
    const uint32_t              DPLL_LOCK_TIMER_BITS = 9;

    ecmdDataBufferBase          pmgp1(64);
    const uint32_t              WINKLE_POWER_DN_EN_BIT = 3;
    const uint32_t              WINKLE_POWER_OFF_SEL_BIT = 5;

    ecmdDataBufferBase          ivrm_control_status(64);
    const uint32_t              GOTO_WINKLE_BIT = 3;
    const uint32_t              GOTO_WAKEUP_BIT = 4;
    const uint32_t              BABYSTEPPER_WINKLE_TIMEOUT = 10;
    const uint32_t              BABYSTEPPER_WAKEUP_TIMEOUT = 10;

    ecmdDataBufferBase          core_voff_vret(64);
    ecmdDataBufferBase          eco_voff_vret(64);




    FAPI_INF("Beginning FET work-around for IVRM FSM");
    do
    {

        // ---------------------------------------------------------------------

        // Determine if Pstates have been previously enabled.  If so, the
        // work-around was previously run and cannot be run again.
        address = EX_PCBSPM_MODE_REG_0x100F0156 + 0x01000000*i_ex_number;

        l_rc=fapiGetScom( i_target, address, pmgp0 );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        if (gp3.isBitSet(0))
        {
            FAPI_INF("Skipping PFET work-around as Pstate have already been enabled");
            break;
        }

        // Adding another layer of protection.
        // Set PMGP0(47) [a spare bit in chips that have this bug]
        // to indicated that this work-around has already been run
        // to avoid contaminating the PState mechanism in the event
        // that it was not first disabled.

        address = EX_PMGP0_0x100F0100 + (0x01000000 * i_ex_number);
        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        if (data.isBitSet(PFET_WORKAROUND_MARK_PMGP0_BIT))
        {
            FAPI_INF("Skipping PFET work-around as iVRM/FFET work-around has previously run on %s EX:%d",
                            i_target.toEcmdString(),
                            i_ex_number);
            break;

        }
        else
        {
            e_rc |= data.flushTo0();
            e_rc |= data.setBit(PFET_WORKAROUND_MARK_PMGP0_BIT);
            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }

            address = EX_PMGP0_OR_0x100F0102 + (0x01000000 * i_ex_number);
            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }

             FAPI_INF("Setting flag that PFET work-around cannot be run again on %s EX:%d",
                            i_target.toEcmdString(),
                            i_ex_number);
            // This can set the PMGP0 snitch bit (PMErr(12)).  It is cleared,
            // though, in p8_pfet_init.C (the caller)
        }

        address = EX_GP3_0x100F0012 + 0x01000000*i_ex_number;

        // Save the setting for later restoration
        l_rc=fapiGetScom( i_target, address, gp3 );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        address = EX_PMGP0_0x100F0100 + 0x01000000*i_ex_number;

        // Save the setting for possible setting later
        l_rc=fapiGetScom( i_target, address, pmgp0 );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }


        if (gp3.isBitClear(0))
        {
            FAPI_INF("Set PMGP0 access mode, fence the PCB, raise PB electrical fence");
            e_rc |= data.flushTo0();
            e_rc |= data.setBit(20);
            e_rc |= data.setBit(26);
            e_rc |= data.setBit(27);
            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }

            // Set the bit
            address = EX_GP3_OR_0x100F0014 + 0x01000000*i_ex_number;
            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }

            // ----------------------
            // Read back for debug
            address = EX_GP3_0x100F0012 + 0x01000000*i_ex_number;
            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }
            FAPI_DBG("\tGP3 value: 0x%016llX", data.getDoubleWord(0));

            // ----------------------
            FAPI_INF("Set Slave Winkle fence");
            e_rc |= data.flushTo0();
            e_rc |= data.setBit(39);
            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }

            // Set the bit
            address = EX_PMGP0_OR_0x100F0102 + 0x01000000*i_ex_number;
            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }

            // ----------------------
            // Read back for debug
            address = EX_PMGP0_0x100F0100 + 0x01000000*i_ex_number;
            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }
            FAPI_DBG("\tPMGP0 value: 0x%016llX", data.getDoubleWord(0));

            FAPI_INF("Temporarily enable the chiplet");
            e_rc |= data.flushTo0();
            e_rc |= data.setBit(0);
            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }

            // Set the bit
            address = EX_GP3_OR_0x100F0014 + 0x01000000*i_ex_number;
            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }

            // ----------------------
            // Read back for debug
            address = EX_GP3_OR_0x100F0014 + 0x01000000*i_ex_number;
            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }
            FAPI_DBG("\tGP3 value: 0x%016llX", data.getDoubleWord(0));

            address = EX_PMGP0_0x100F0100 + 0x01000000*i_ex_number;
            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }
            FAPI_DBG("\tPMGP0 value: 0x%016llX", data.getDoubleWord(0));
            // ----------------------
        }

        // ---------------------------------------------------------------------

        if (pmgp0.isBitSet(PM_DISABLE_BIT))
        {
            FAPI_INF("Enabling Power Management as it is needed");
            e_rc |= data.flushTo1();
            e_rc |= data.clearBit(PM_DISABLE_BIT);
            if (e_rc)
            {
                l_rc.setEcmdError(e_rc);
                break;
            }

            // Clear the bit
            address = EX_PMGP0_AND_0x100F0101 + 0x01000000*i_ex_number;
            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }
        }

        // ---------------------------------------------------------------------
        FAPI_INF("Set timer Mode");
        address = EX_PCBSPM_MODE_REG_0x100F0156 + 0x01000000*i_ex_number;

        // Save the setting
        l_rc=fapiGetScom( i_target, address, pcbspm_mode );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        data = pcbspm_mode;
        e_rc |= data.setBit(TIMER_MODE_BIT);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // ---------------------------------------------------------------------
        FAPI_INF("Clear dpll_lock_timer_replacement value to disable waiting");
        address = EX_DPLL_CPM_PARM_REG_0x100F0152 + 0x01000000*i_ex_number;

        // Save the setting
        l_rc=fapiGetScom( i_target, address, cpm_dpll_parm );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        data = cpm_dpll_parm;
        e_rc |= data.clearBit(DPLL_LOCK_TIMER_BIT, DPLL_LOCK_TIMER_BITS);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // ---------------------------------------------------------------------
        FAPI_INF("Set Local Pstate Table VID value to > 0");
        // Set address to 0 to be sure
        address = EX_PCBS_PSTATE_TABLE_CTRL_REG_0x100F015E + 0x01000000*i_ex_number;
        e_rc |= data.flushTo0();
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        address = EX_PCBS_PSTATE_TABLE_REG_0x100F015F + 0x01000000*i_ex_number;
        value = 1;
        e_rc |= data.insertFromRight(&value, 0, 7);
        e_rc |= data.insertFromRight(&value, 7, 7);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // ---------------------------------------------------------------------
        FAPI_INF("Writing Local Pstate Table Size");
        address = EX_PCBS_Power_Management_Bounds_Reg_0x100F015D +
                                0x01000000*i_ex_number;

        uint32_t lpsi_min     = 0;
        uint32_t lpsi_entries_minus_1 = 0;  // one entry
        uint32_t lpsi_min_index = lpsi_min + 128;   // converted into index space


        e_rc |= data.flushTo0();
        e_rc |= data.insertFromRight(&lpsi_min_index, 0, 8);
        e_rc |= data.insertFromRight(&lpsi_entries_minus_1, 8, 7);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // ---------------------------------------------------------------------
        FAPI_INF("Enable IVRM FSM and then PState mode");

        // IVRM Enable
        address = EX_PCBS_iVRM_Control_Status_Reg_0x100F0154 +
                                0x01000000*i_ex_number;


        l_rc=fapiGetScom( i_target, address, ivrm_control_status );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        data = ivrm_control_status;
        e_rc |= data.setBit(0);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // Pstate mode
        address = EX_PCBSPM_MODE_REG_0x100F0156 + 0x01000000*i_ex_number;

        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        e_rc |= data.setBit(0);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // ---------------------------------------------------------------------
        // Setup the appropriate off action when triggering  the babystepper to
        // winkle entry (fast without off for configured chiplets; deep with
        // power loss for deconfigured chiplets).

        address = EX_CorePFVRET_REG_0x100F0130 + 0x01000000*i_ex_number;
        l_rc=fapiGetScom( i_target, address, core_voff_vret );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        address = EX_ECOPFVRET_REG_0x100F0150 + 0x01000000*i_ex_number;
        l_rc=fapiGetScom( i_target, address, eco_voff_vret );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        address = EX_PMGP1_0x100F0103 + 0x01000000*i_ex_number;
        l_rc=fapiGetScom( i_target, address, pmgp1 );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }

        data = pmgp1;

        if (i_op == VOFF)
        {
            FAPI_INF("Set winkle power off select to deep");
            e_rc |= data.setBit(WINKLE_POWER_OFF_SEL_BIT);
            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }

            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }
        }
        else if (i_op == VON)
        {
            FAPI_INF("Set winkle power off select to fast with no power change");
            e_rc |= data.clearBit(WINKLE_POWER_OFF_SEL_BIT);
            e_rc |= data.clearBit(WINKLE_POWER_DN_EN_BIT);

            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }

            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }

            // Don't let the power go off
            e_rc |= data.flushTo0();
            if (e_rc)
            {
                FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
                l_rc.setEcmdError(e_rc);
                break;
            }
            address = EX_CorePFVRET_REG_0x100F0130 + 0x01000000*i_ex_number;
            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }

            address = EX_ECOPFVRET_REG_0x100F0150 + 0x01000000*i_ex_number;
            l_rc=fapiPutScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("PutScom error 0x%08llX", address);
                break;
            }
        }
        else
        {
            FAPI_ERR("Unsupported i_op to iVRM fix");
            break;
        }

        // ---------------------------------------------------------------------
        FAPI_INF("Trigger winkle to synchronize the iVRM babystepper");

        address = EX_IDLEGOTO_0x100F0114 + 0x01000000*i_ex_number;

        e_rc |= data.flushTo0();
        e_rc |= data.setBit(GOTO_WINKLE_BIT);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        uint32_t i = 0;
        do
        {
            FAPI_DBG("Poll for completion:  %d", i);
            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }

            if  (data.isBitClear(GOTO_WINKLE_BIT))
            {
                break;
            }

            l_rc = fapiDelay(10000, 1000);
            if (l_rc)
            {
                FAPI_ERR("Error from fapiDelay");
                break;
            }

            i++;

        } while (data.isBitSet(GOTO_WINKLE_BIT) &&  i < BABYSTEPPER_WINKLE_TIMEOUT);

        if (i >=  BABYSTEPPER_WINKLE_TIMEOUT)
        {
            // This is a workaround for early chip EC levels, just trace and do
            // not return error
            FAPI_ERR("\tBaby Stepper Timeout %d", i_ex_number);
        }

        // ---------------------------------------------------------------------
        FAPI_INF("Trigger winkle wakeup to get get the FSM back to idle");
        // IVRM Enable
        address = EX_IDLEGOTO_0x100F0114 + 0x01000000*i_ex_number;

        e_rc |= data.flushTo0();
        e_rc |= data.setBit(GOTO_WAKEUP_BIT);
        if (e_rc)
        {
            FAPI_ERR("Error (0x%x) setting up  ecmdDataBufferBase", e_rc);
            l_rc.setEcmdError(e_rc);
            break;
        }
        l_rc=fapiPutScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        i = 0;
        do
        {
            l_rc=fapiGetScom( i_target, address, data );
            if(!l_rc.ok())
            {
                FAPI_ERR("GetScom error 0x%08llX", address);
                break;
            }

            if  (data.isBitClear(GOTO_WAKEUP_BIT))
            {
                break;
            }

            i++;

            // No delay needed, hardware reacton should be nearly immediate and
            // this is a workaround for early chip EC levels

        } while (data.isBitSet(GOTO_WAKEUP_BIT) &&  i < BABYSTEPPER_WAKEUP_TIMEOUT);
        if (i >=  BABYSTEPPER_WAKEUP_TIMEOUT)
        {
            // This is a workaround for early chip EC levels, just trace and do
            // not return error
            FAPI_ERR("\tBaby Stepper Timeout on Wakeup %d", i_ex_number);
        }


        // ----- Debug registers   -----
        address = EX_PCBS_FSM_MONITOR1_REG_0x100F0170 +
                        0x01000000*i_ex_number;

        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        FAPI_DBG("\tPCBS Monitor1 for Core %d:  0x%16llX", i_ex_number, data.getDoubleWord(0));

        address = EX_PCBS_FSM_MONITOR2_REG_0x100F0171 +
                        0x01000000*i_ex_number;

        l_rc=fapiGetScom( i_target, address, data );
        if(!l_rc.ok())
        {
            FAPI_ERR("GetScom error 0x%08llX", address);
            break;
        }
        FAPI_DBG("\tPCBS Monitor2 for Core %d:  0x%16llX", i_ex_number, data.getDoubleWord(0));


        // ----- Restore registers -----

        // DPLL_CPM_PARM_REG
        FAPI_DBG("Restore DPLL_CPM_PARM_REG:  0x%16llX", cpm_dpll_parm.getDoubleWord(0));

        address = EX_DPLL_CPM_PARM_REG_0x100F0152 +
                        0x01000000*i_ex_number;

        l_rc=fapiPutScom( i_target, address, cpm_dpll_parm );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // Core OFF/VRET
        FAPI_DBG("Restore Core OFF/VRET pointers:  0x%16llX", core_voff_vret.getDoubleWord(0));

        address = EX_CorePFVRET_REG_0x100F0130 +
                        0x01000000*i_ex_number;

        l_rc=fapiPutScom( i_target, address, core_voff_vret );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // ECO OFF/VRET
        FAPI_DBG("Restore ECO OFF/VRET pointers:  0x%16llX", eco_voff_vret.getDoubleWord(0));

        address = EX_ECOPFVRET_REG_0x100F0150 +
                        0x01000000*i_ex_number;

        l_rc=fapiPutScom( i_target, address, eco_voff_vret );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // PM MODE
        FAPI_DBG("Restore PM MODE:  0x%16llX", pcbspm_mode.getDoubleWord(0));

        address = EX_PCBSPM_MODE_REG_0x100F0156 +
                        0x01000000*i_ex_number;

        l_rc=fapiPutScom( i_target, address, pcbspm_mode );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // iVRM_Control_Status
        FAPI_DBG("Restore IVRM Control / Status:  0x%16llX", ivrm_control_status.getDoubleWord(0));

        address = EX_PCBS_iVRM_Control_Status_Reg_0x100F0154 +
                        0x01000000*i_ex_number;

        l_rc=fapiPutScom( i_target, address, ivrm_control_status );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }
        // PMGP1
        FAPI_DBG("Restore PMGP1:  0x%16llX", pmgp1.getDoubleWord(0));

        address = EX_PMGP1_0x100F0103 + 0x01000000*i_ex_number;

        l_rc=fapiPutScom( i_target, address, pmgp1 );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        // PMGP0
        FAPI_DBG("Restore PMGP0:  0x%16llX", pmgp0.getDoubleWord(0));

        address = EX_PMGP0_0x100F0100 + 0x01000000*i_ex_number;

        l_rc=fapiPutScom( i_target, address, pmgp0 );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

        //  GP3
        FAPI_DBG("Restore GP3:  0x%16llX", gp3.getDoubleWord(0));

        address = EX_GP3_0x100F0012 + 0x01000000*i_ex_number;

        l_rc=fapiPutScom( i_target, address, gp3 );
        if(!l_rc.ok())
        {
            FAPI_ERR("PutScom error 0x%08llX", address);
            break;
        }

   } while(0);

   FAPI_INF("Completing PFET work-around for IVRM FSM");
   return l_rc;
}

} //end extern
