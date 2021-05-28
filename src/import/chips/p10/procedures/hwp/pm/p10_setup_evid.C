/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_setup_evid.C $     */
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
/// @file  p10_setup_evid.C
/// @brief Setup External Voltage IDs
///
// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *Team                : PM
// *Consumed by         : HB
// *Level               : 2
///
/// @verbatim
///
/// Procedure Summary:
///   - Use Attributes to send VDD, VDN, VCS and VIO via the AVS bus to VRMs
///
/// @endverbatim

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_setup_evid.H>
#include <p10_pstate_parameter_block.H>
#include <p10_avsbus_lib.H>
#include <p10_avsbus_scom.H>
#include <p10_scom_mc.H>
#include <p10_scom_pauc.H>
#include <p10_scom_iohs.H>
#include <p10_scom_pec.H>
#include <p10_scom_proc.H>
#include <multicast_group_defs.H>

using namespace pm_pstate_parameter_block;
using namespace scomt;
static const uint32_t DPLL_TIMEOUT_MS       = 50000;
static const uint32_t DPLL_TIMEOUT_MCYCLES  = 20;
static const uint32_t DPLL_POLLTIME_MS      = 20;
static const uint32_t DPLL_POLLTIME_MCYCLES = 2;
static const uint32_t TIMEOUT_COUNT = DPLL_TIMEOUT_MS / DPLL_POLLTIME_MS;

static const uint32_t NEST_DPLL_FREQ             = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ;
static const uint32_t NEST_DPLL_STAT             = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT;
static const uint32_t NEST_DPLL_FREQ_FMULT       = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT;
static const uint32_t NEST_DPLL_FREQ_FMULT_LEN   = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMULT_LEN;
static const uint32_t NEST_DPLL_FREQ_FMAX        = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX;
static const uint32_t NEST_DPLL_FREQ_FMAX_LEN    = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMAX_LEN;
static const uint32_t NEST_DPLL_FREQ_FMIN        = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN;
static const uint32_t NEST_DPLL_FREQ_FMIN_LEN    = TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_FREQ_FMIN_LEN;

fapi2::ReturnCode
p10_update_net_ctrl(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
//-----------------------------------------------------------------------------
// Procedure
//-----------------------------------------------------------------------------


struct avsbus_attrs_t
{
    uint8_t vdd_bus_num;
    uint8_t vdd_rail_select;
    uint8_t vdn_bus_num;
    uint8_t vdn_rail_select;
    uint8_t vcs_bus_num;
    uint8_t vcs_rail_select;
    uint32_t vcs_voltage_mv;
    uint32_t vdd_voltage_mv;
    uint32_t vdn_voltage_mv;
    uint32_t r_loadline_vdd_uohm;
    uint32_t r_distloss_vdd_uohm;
    uint32_t vrm_voffset_vdd_uv;
    uint32_t r_loadline_vdn_uohm;
    uint32_t r_distloss_vdn_uohm;
    uint32_t vrm_voffset_vdn_uv;
    uint32_t r_loadline_vcs_uohm;
    uint32_t r_distloss_vcs_uohm;
    uint32_t vrm_voffset_vcs_uv;
    uint32_t freq_proc_refclock_khz;
    uint32_t proc_dpll_divider;
};

/////////////////////////////////////////////////////////////////
//////p10_setup_evid
////////////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_setup_evid (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                const VoltageConfigActions_t i_action)
{

    pm_pstate_parameter_block::AttributeList attrs;
    uint32_t l_present_boot_voltage[MAX_VRM];
    bool  l_dpll_lesser_value = false;
    fapi2::buffer<uint64_t> l_fmult_data(0);
    uint32_t l_safe_mode_dpll_value = 0;
    uint32_t l_safe_mode_dpll_fmin_value = 0;
    //Instantiate PPB object
    PlatPmPPB l_pmPPB(i_target);

    FAPI_ASSERT(l_pmPPB.iv_init_error == false,
                fapi2::PSTATE_PB_ATTRIBUTE_ACCESS_ERROR()
                .set_CHIP_TARGET(i_target),
                "Pstate Parameter Block attribute access error");

    // Compute the boot/safe values
    FAPI_TRY(l_pmPPB.compute_boot_safe(i_action));

    // Compute the RVRM retention Voltage Id
    FAPI_DBG("Compute RVID");
    FAPI_TRY(l_pmPPB.compute_retention_vid());

    //We only wish to apply settings if i_action says to
    // this will be executed in istep 10
    if(i_action == APPLY_VOLTAGE_SETTINGS)
    {
        FAPI_INF("> p10_setup_evid Apply");

        l_pmPPB.get_pstate_attrs(attrs);

        // Read and compare DPLL and safe mode value
        FAPI_TRY (p10_read_dpll_value(i_target,
                                      attrs.attr_freq_proc_refclock_khz,
                                      attrs.attr_proc_dpll_divider,
                                      l_dpll_lesser_value,
                                      l_fmult_data,
                                      l_safe_mode_dpll_value,
                                      l_safe_mode_dpll_fmin_value),
                  "Error from p10_read_dpll_value function");

        //if DPLL is greater than safe mode freq then first set the dpll to safe
        //model freq.
        if (!l_dpll_lesser_value)
        {

            // Set the DPLL frequency values to safe mode values
            FAPI_TRY (p10_update_dpll_value(i_target,
                                            l_safe_mode_dpll_value,
                                            l_safe_mode_dpll_fmin_value),
                      "Error from p10_update_dpll_value function");
        }

        //Read VDD and VCS present voltage from HW
        FAPI_TRY(p10_setup_evid_voltageRead(i_target,
                                            attrs.attr_avs_bus_num,
                                            attrs.attr_avs_bus_rail_select,
                                            l_present_boot_voltage),
                 "Error from voltage read function");

        // Set Boot VDD/VCS Voltage
        if(attrs.attr_avs_bus_num[VDD] != INVALID_BUS_NUM &&
           attrs.attr_avs_bus_num[VCS] != INVALID_BUS_NUM)
        {
            FAPI_INF("Setting Boot voltage values for VDD (%d mv) and VCS (%d mv)",
                     attrs.attr_boot_voltage_mv[VDD], attrs.attr_boot_voltage_mv[VCS]);

            if (attrs.attr_boot_voltage_mv[VDD] &&
                attrs.attr_boot_voltage_mv[VCS])
            {
                FAPI_TRY(update_VDD_VCS_voltage(i_target,
                                                attrs.attr_avs_bus_num,
                                                attrs.attr_avs_bus_rail_select,
                                                attrs.attr_boot_voltage_mv,
                                                attrs.attr_ext_vrm_step_size_mv,
                                                l_present_boot_voltage),
                         "Error from VDD/VCS setup function");
            }
        }

        // Set DPLL after ext volt update because of dpll is lesser the safe
        // mode freq.
        if (l_dpll_lesser_value)
        {
            // Set the DPLL frequency values to safe mode values
            FAPI_TRY (p10_update_dpll_value(i_target,
                                            l_safe_mode_dpll_value,
                                            l_safe_mode_dpll_fmin_value),
                      "Error from p10_update_dpll_value function");
        }

        // Set Boot VDN Voltage
        if(attrs.attr_avs_bus_num[VDN] == INVALID_BUS_NUM)
        {
            FAPI_INF("VDN rail is not connected to AVSBus. Skipping VDN programming");
        }
        else
        {
            if (attrs.attr_boot_voltage_mv[VDN])
            {
                FAPI_INF("Setting Boot voltage value for VDN (%d mv)", attrs.attr_boot_voltage_mv[VDN]);
                FAPI_TRY(p10_setup_evid_voltageWrite(i_target,
                                                     attrs.attr_avs_bus_num[VDN],
                                                     attrs.attr_avs_bus_rail_select[VDN],
                                                     attrs.attr_boot_voltage_mv[VDN],
                                                     attrs.attr_ext_vrm_step_size_mv[VDN],
                                                     l_present_boot_voltage[VDN],
                                                     VDN_SETUP),
                         "error from VDN setup function");

                if (attrs.attr_array_write_assist_set)
                {
                    FAPI_TRY(p10_update_net_ctrl(i_target));

                }
            }
        }

        // AVSbus fails at this point in sim

        // Set Boot VIO Voltage
        if(attrs.attr_avs_bus_num[VIO] == INVALID_BUS_NUM)
        {
            FAPI_INF("VIO rail is not connected to AVSBus. Skipping VIO programming");
        }
        else
        {
            if (attrs.attr_boot_voltage_mv[VIO])
            {
                FAPI_INF("Setting Boot voltage value for VIO (%d mv)", attrs.attr_boot_voltage_mv[VIO]);
                FAPI_TRY(p10_setup_evid_voltageWrite(i_target,
                                                     attrs.attr_avs_bus_num[VIO],
                                                     attrs.attr_avs_bus_rail_select[VIO],
                                                     attrs.attr_boot_voltage_mv[VIO],
                                                     attrs.attr_ext_vrm_step_size_mv[VIO],
                                                     l_present_boot_voltage[VIO],
                                                     VIO_SETUP),
                         "error from VIO setup function");
            }
        }

        FAPI_INF("< p10_setup_evid Apply");
    }

fapi_try_exit:
    return fapi2::current_err;
} // Procedure



/////////////////////////////////////////////////////////////////
//////p10_setup_evid_voltageRead
////////////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_setup_evid_voltageRead(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           const uint8_t* i_bus_num,
                           const uint8_t* i_rail_select,
                           uint32_t* o_voltage_mv)
{
    uint8_t     l_goodResponse = 0;
    uint8_t     l_throwAssert = true;
    uint32_t    l_present_voltage_mv;
    uint32_t    l_count;
    char        rail_str[8];

    FAPI_INF("> p10_setup_evid_voltageRead");

    for (auto i_evid_value = 0; i_evid_value < MAX_VRM; ++i_evid_value)
    {
        switch (i_evid_value)
        {
            case VCS_SETUP:
                if (i_bus_num[i_evid_value] == INVALID_BUS_NUM)
                {
                    FAPI_INF("VCS not connected. skipping");
                    continue;
                }

                strcpy(rail_str, "VCS");
                break;

            case VDD_SETUP:
                if (i_bus_num[i_evid_value] == INVALID_BUS_NUM)
                {
                    FAPI_INF("VDD not connected. skipping");
                    continue;
                }

                strcpy(rail_str, "VDD");
                break;

            case VDN_SETUP:
                if (i_bus_num[i_evid_value] == INVALID_BUS_NUM)
                {
                    FAPI_INF("VDN not connected. skipping");
                    continue;
                }

                strcpy(rail_str, "VDN");
                break;

            case VIO_SETUP:
                if (i_bus_num[i_evid_value] == INVALID_BUS_NUM)
                {
                    FAPI_INF("VIO not connected. skipping");
                    continue;
                }

                strcpy(rail_str, "VIO");
                break;

            default:
                strcpy(rail_str, "ERR");
                ;
        }

        if (i_evid_value != VIO_SETUP)
        {
            // Initialize the buses
            FAPI_TRY(avsInitExtVoltageControl(i_target,
                                              i_bus_num[i_evid_value], BRIDGE_NUMBER),
                     "Initializing AVSBus for %s, bridge %d", rail_str, BRIDGE_NUMBER);
        }

        // Drive AVS Bus with a frame value 0xFFFFFFFF (idle frame) to
        // initialize the AVS slave
        FAPI_INF("   Sending AVSBus idle frame");
        FAPI_TRY(avsIdleFrame(i_target, i_bus_num[i_evid_value], BRIDGE_NUMBER));

        // Read the present voltage

        // This loop is to ensure AVSBus Master and Slave are in sync
        l_count = 0;

        do
        {
            ;
            FAPI_TRY(avsVoltageRead(i_target, i_bus_num[i_evid_value], BRIDGE_NUMBER,
                                    i_rail_select[i_evid_value], l_present_voltage_mv),
                     "AVS Voltage read transaction failed to %d, Bridge %d",
                     i_bus_num[i_evid_value],
                     BRIDGE_NUMBER);
            // Throw an assertion if we don't get a good response.
            l_throwAssert =  (l_count >= AVSBUS_RETRY_COUNT);
            FAPI_TRY(avsValidateResponse(i_target,  i_bus_num[i_evid_value], BRIDGE_NUMBER,
                                         l_throwAssert, l_goodResponse));

            if (!l_goodResponse)
            {
                FAPI_TRY(avsIdleFrame(i_target, i_bus_num[i_evid_value], BRIDGE_NUMBER));
            }

            l_count++;
        }
        while (!l_goodResponse);

        FAPI_DBG("%s voltage read: %d mv", rail_str, l_present_voltage_mv);
        o_voltage_mv[i_evid_value] = l_present_voltage_mv;
    } //end of for

fapi_try_exit:
    FAPI_INF("< p10_setup_evid_voltageRead");
    return fapi2::current_err;
}


/////////////////////////////////////////////////////////////////
//////update_VDD_VCS_voltage
////////////////////////////////////////////////////////////////
fapi2::ReturnCode
update_VDD_VCS_voltage(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       const uint8_t* i_bus_num,
                       const uint8_t* i_rail_select,
                       const uint32_t* i_voltage_mv,
                       const uint32_t* i_ext_vrm_step_size_mv,
                       const uint32_t* i_present_boot_voltage)

{
    enum P10_SETUP_EVID_CONSTANTS l_evid_value;

    do
    {

        if (i_present_boot_voltage[VDD] == i_voltage_mv[VDD] &&
            i_present_boot_voltage[VCS] == i_voltage_mv[VCS])
        {
            FAPI_INF("SKIP:Both VDD and VCS of present and computed voltage are same");
            break;
        }

        // Here if boot voltage is less than computed voltage, then we are
        // moving the voltage upwards, in this case we should first update VCS
        // and then VDD
        if (i_present_boot_voltage[VDD] < i_voltage_mv[VDD] &&
            i_present_boot_voltage[VCS] <= i_voltage_mv[VCS])
        {
            for (int8_t i = VCS; i >= VDD;  --i)
            {
                l_evid_value = (i == VDD) ? VDD_SETUP : VCS_SETUP;

                FAPI_TRY(p10_setup_evid_voltageWrite(i_target,
                                                     i_bus_num[i],
                                                     i_rail_select[i],
                                                     i_voltage_mv[i],
                                                     i_ext_vrm_step_size_mv[i],
                                                     i_present_boot_voltage[i],
                                                     l_evid_value),
                         "Error from p10_setup_evid_voltageWrite setup function");
            }
        }


        //if boot voltage is greater than computed voltage, then we are
        //moving downwards,in this case VDD first and VCS should be updated
        if ((i_present_boot_voltage[VDD] > i_voltage_mv[VDD] &&
             i_present_boot_voltage[VCS] >= i_voltage_mv[VCS]) ||
            (i_present_boot_voltage[VDD] > i_voltage_mv[VDD] &&
             i_present_boot_voltage[VCS] <= i_voltage_mv[VCS]))
        {
            for (int8_t i = VDD; i <= VCS;  ++i)
            {
                l_evid_value = (i == VDD) ? VDD_SETUP : VCS_SETUP;

                FAPI_TRY(p10_setup_evid_voltageWrite(i_target,
                                                     i_bus_num[i],
                                                     i_rail_select[i],
                                                     i_voltage_mv[i],
                                                     i_ext_vrm_step_size_mv[i],
                                                     i_present_boot_voltage[i],
                                                     l_evid_value),
                         "Error from p10_setup_evid_voltageWrite setup function");
            }
        }
    }
    while (0);

fapi_try_exit:
    return fapi2::current_err;
}

/////////////////////////////////////////////////////////////////
//////p10_setup_evid_voltageWrite
////////////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_setup_evid_voltageWrite(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                            const uint8_t i_bus_num,
                            const uint8_t i_rail_select,
                            const uint32_t i_voltage_mv,
                            const uint32_t i_ext_vrm_step_size_mv,
                            const uint32_t i_present_voltage_mv,
                            const P10_SETUP_EVID_CONSTANTS i_evid_value)
{
    uint8_t     l_goodResponse = 0;
    uint8_t     l_throwAssert = true;
    uint32_t    l_present_voltage_mv = i_present_voltage_mv;
    uint32_t    l_target_mv;
    uint32_t    l_count;
    int32_t     l_delta_mv = 0;
    char        rail_str[8];

    switch (i_evid_value)
    {
        case VCS_SETUP:
            strcpy(rail_str, "VCS");
            break;

        case VDD_SETUP:
            strcpy(rail_str, "VDD");
            break;

        case VDN_SETUP:
            strcpy(rail_str, "VDN");
            break;

        case VIO_SETUP:
            strcpy(rail_str, "VIO");
            break;

        default:
            ;
    }

    if (i_evid_value != VCS_SETUP)
    {
        // Initialize the buses
        FAPI_TRY(avsInitExtVoltageControl(i_target,
                                          i_bus_num, BRIDGE_NUMBER),
                 "Initializing avsBus VDD/VDN, bridge %d", BRIDGE_NUMBER);
    }

    FAPI_INF("Present voltage for %s is %d mV", rail_str, i_present_voltage_mv);
    FAPI_INF("Setting voltage for %s to %d mV", rail_str, i_voltage_mv);

    // Drive AVS Bus with a frame value 0xFFFFFFFF (idle frame) to
    // initialize the AVS slave
    FAPI_TRY(avsIdleFrame(i_target, i_bus_num, BRIDGE_NUMBER));

    // Compute the delta
    l_delta_mv = (int32_t)l_present_voltage_mv - (int32_t)i_voltage_mv;

    if (l_delta_mv > 0)
    {
        FAPI_INF("Decreasing voltage - delta = %d", l_delta_mv );
    }
    else if (l_delta_mv < 0)
    {
        FAPI_INF("Increasing voltage - delta = %d", -l_delta_mv );
    }
    else
    {
        FAPI_INF("Voltage to be set equals the initial voltage");
    }

    FAPI_DBG("ext_vrm_step_size_mv %d mV", i_ext_vrm_step_size_mv);

    // Break into steps limited by attr.attr_ext_vrm_step_size_mv
    while (l_delta_mv)
    {
        // Hostboot doesn't support abs()
        uint32_t l_abs_delta_mv = l_delta_mv < 0 ? -l_delta_mv : l_delta_mv;

        if (i_ext_vrm_step_size_mv > 0 && l_abs_delta_mv > i_ext_vrm_step_size_mv )
        {
            if (l_delta_mv > 0)  // Decreasing
            {
                l_target_mv = l_present_voltage_mv - i_ext_vrm_step_size_mv;
            }
            else
            {
                l_target_mv = l_present_voltage_mv + i_ext_vrm_step_size_mv;
            }
        }
        else
        {
            l_target_mv = i_voltage_mv;
        }

        FAPI_INF("Target voltage = %d; Present voltage = %d",
                 l_target_mv, l_present_voltage_mv);

        l_count = 0;

        do
        {
            FAPI_INF("Moving voltage to %d; retry count = %d", l_target_mv, l_count);
            // Set Boot voltage
            FAPI_TRY(avsVoltageWrite(i_target,
                                     i_bus_num,
                                     BRIDGE_NUMBER,
                                     i_rail_select,
                                     l_target_mv),
                     "Setting voltage via AVSBus %d, Bridge %d",
                     i_bus_num,
                     BRIDGE_NUMBER);

            // Throw an assertion if we don't get a good response.
            l_throwAssert =  l_count >= AVSBUS_RETRY_COUNT;
            FAPI_TRY(avsValidateResponse(i_target,
                                         i_bus_num,
                                         BRIDGE_NUMBER,
                                         l_throwAssert,
                                         l_goodResponse));

            if (!l_goodResponse)
            {
                FAPI_TRY(avsIdleFrame(i_target, i_bus_num, BRIDGE_NUMBER));
            }

            l_count++;
        }
        while (!l_goodResponse);

        l_present_voltage_mv = l_target_mv;
        l_delta_mv = (int32_t)l_present_voltage_mv - (int32_t)i_voltage_mv;
        FAPI_INF("New delta = %d", l_delta_mv );
    }

fapi_try_exit:
    return fapi2::current_err;
} // Procedure


/////////////////////////////////////////////////////////////////
//////p10_read_dpll_value
////////////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_read_dpll_value (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     const uint32_t  i_freq_proc_refclock_khz,
                     const uint32_t i_proc_dpll_divider,
                     bool&  o_dpll_lesser_value,
                     fapi2::buffer<uint64_t>& o_fmult_data,
                     uint32_t& o_safe_mode_dpll_value,
                     uint32_t& o_safe_mode_dpll_fmin_value)

{
    fapi2::buffer<uint64_t> l_data64;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_attr_safe_mode_freq;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type l_attr_safe_mode_mv;
    fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_Type l_sys_freq_core_floor_mhz;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ, i_target, l_attr_safe_mode_freq));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV, i_target, l_attr_safe_mode_mv));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ,
                           FAPI_SYSTEM, l_sys_freq_core_floor_mhz));

    do
    {
        FAPI_INF("> p10_read_dpll_value");

        if (!l_attr_safe_mode_freq )
        {

            FAPI_INF("NEST DPLL: safe mode attribute not set");
            break;
        }

        o_fmult_data.flush<0>();
        FAPI_TRY(fapi2::getScom(i_target, NEST_DPLL_FREQ, l_data64),
                 "ERROR: Failed to read NEST_DPLL_FREQ");

        if (!i_freq_proc_refclock_khz || !i_proc_dpll_divider)
        {
            FAPI_IMP("p10_read_dpll_value :i_freq_proc_refclock_khz %x i_proc_dpll_divider %x",
                     i_freq_proc_refclock_khz , !i_proc_dpll_divider);
            break;
        }

        l_data64.extractToRight<NEST_DPLL_FREQ_FMULT,
                                NEST_DPLL_FREQ_FMULT_LEN>(o_fmult_data);

        // Convert back to the complete frequency value
        o_fmult_data =  ((o_fmult_data * i_freq_proc_refclock_khz ) / i_proc_dpll_divider ) / 1000;

        // Convert frequency value to a format that needs to be written to the
        // register
        o_safe_mode_dpll_value = ((l_attr_safe_mode_freq * 1000) * i_proc_dpll_divider) /
                                 i_freq_proc_refclock_khz;

        //TO support DPLL mode 4, need to update the max of min freq between
        //safe mode and sys floor freq
        if ( l_attr_safe_mode_freq < l_sys_freq_core_floor_mhz)
        {
            l_attr_safe_mode_freq = l_sys_freq_core_floor_mhz;
        }

        o_safe_mode_dpll_fmin_value = ((l_attr_safe_mode_freq * 1000) * i_proc_dpll_divider) /
                                      i_freq_proc_refclock_khz;

        FAPI_INF("NEST DPLL fmult 0x%08X safe_mode_dpll_value 0x%04X (%d) safe_mode_dpll_fmin 0x%04X (%d)",
                 o_fmult_data,
                 o_safe_mode_dpll_value, o_safe_mode_dpll_value,
                 o_safe_mode_dpll_fmin_value, o_safe_mode_dpll_fmin_value);

        if (o_fmult_data >= l_attr_safe_mode_freq)
        {
            o_dpll_lesser_value = false;
            FAPI_INF("DPLL setting: Lowering the dpll frequency");
        }
        else
        {
            o_dpll_lesser_value = true;
            FAPI_INF("DPLL setting: Raising the dpll frequency");
        }
    }
    while (0);

fapi_try_exit:
    FAPI_INF("< p10_read_dpll_value");
    return fapi2::current_err;
}

/////////////////////////////////////////////////////////////////
//////p10_update_net_ctrl
////////////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_update_net_ctrl(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)

{
    FAPI_INF("> p10_update_net_ctrl");
    fapi2::buffer<uint64_t> l_data64;

    do
    {
        //Static domain VDN
        l_data64.setBit<mc::NET_CTRL0_ARRAY_WRITE_ASSIST_EN>();
        auto l_mc_mctrl = i_target.getMulticast<fapi2::TARGET_TYPE_PERV>(fapi2::MCGROUP_GOOD_MC);
        FAPI_TRY(mc::PREP_NET_CTRL0_RW_WOR(l_mc_mctrl));
        FAPI_TRY(mc::PUT_NET_CTRL0_RW_WOR(l_mc_mctrl, l_data64));

        auto l_mc_pau   = i_target.getMulticast<fapi2::TARGET_TYPE_PERV>(fapi2::MCGROUP_GOOD_PAU);
        FAPI_TRY(pauc::PREP_NET_CTRL0_RW_WOR(l_mc_pau));
        FAPI_TRY(pauc::PUT_NET_CTRL0_RW_WOR(l_mc_pau, l_data64));

        auto l_mc_iohs  = i_target.getMulticast<fapi2::TARGET_TYPE_PERV>(fapi2::MCGROUP_GOOD_IOHS);
        FAPI_TRY(iohs::PREP_NET_CTRL0_RW_WOR(l_mc_iohs));
        FAPI_TRY(iohs::PUT_NET_CTRL0_RW_WOR(l_mc_iohs, l_data64));

        auto l_mc_pci = i_target.getMulticast<fapi2::TARGET_TYPE_PERV>(fapi2::MCGROUP_GOOD_PCI);
        FAPI_TRY(pec::PREP_NET_CTRL0_RW_WOR(l_mc_pci));
        FAPI_TRY(pec::PUT_NET_CTRL0_RW_WOR(l_mc_pci, l_data64));


    }
    while (0);

fapi_try_exit:
    FAPI_INF("< p10_update_net_ctrl");
    return fapi2::current_err;
}

/////////////////////////////////////////////////////////////////
//////p10_update_dpll_value
////////////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_update_dpll_value (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       const uint32_t  i_safe_mode_dpll_value,
                       const uint32_t  i_safe_mode_dpll_fmin_value)

{
    fapi2::buffer<uint64_t> l_data64;
    uint8_t l_mask_restore = 0;
    using namespace scomt::proc;
    uint32_t l_timeout_counter = TIMEOUT_COUNT;

    // Only change the DPLL if the values are non-zero
    do
    {
        // save original mask value, to be restored later
        FAPI_TRY( fapi2::getScom( i_target, TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG, l_data64 ),
                  "Failed To Write PERV_SLAVE_CONFIG_REG" );

        l_data64.extractToRight < P10_20_TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
                                P10_20_TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN > ( l_mask_restore );

        l_data64.insertFromRight < P10_20_TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
                                 P10_20_TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN > ( l_mask_restore | 0x01 );

        FAPI_TRY( fapi2::putScom( i_target, TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG, l_data64 ),
                  "Failed To Write PERV_SLAVE_CONFIG_REG" );

        FAPI_TRY(fapi2::getScom(i_target, NEST_DPLL_FREQ, l_data64),
                 "ERROR: Failed to read for EQ_QPPM_DPLL_FREQ");

        if (i_safe_mode_dpll_value)
        {
            //FMax
            l_data64.insertFromRight<NEST_DPLL_FREQ_FMAX,
                                     NEST_DPLL_FREQ_FMAX_LEN>(i_safe_mode_dpll_value);

            //FMult
            l_data64.insertFromRight<NEST_DPLL_FREQ_FMULT,
                                     NEST_DPLL_FREQ_FMULT_LEN>(i_safe_mode_dpll_value);
        }

        if (i_safe_mode_dpll_fmin_value)
        {
            //FMin
            l_data64.insertFromRight<NEST_DPLL_FREQ_FMIN,
                                     NEST_DPLL_FREQ_FMIN_LEN>(i_safe_mode_dpll_fmin_value);
        }

        FAPI_TRY(fapi2::putScom(i_target, NEST_DPLL_FREQ, l_data64),
                 "ERROR: Failed to write for EQ_QPPM_DPLL_FREQ");

        //Need to skip dpll lock stat for sim mode
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_IS_SIMULATION_Type l_sim_env;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, l_sim_env),
                 "Error from FAPI_ATTR_GET (ATTR_IS_SIMULATION)");

        if (!l_sim_env)
        {
            do
            {
                FAPI_TRY(fapi2::getScom(i_target, NEST_DPLL_STAT, l_data64),
                         "ERROR: Failed to read for EQ_QPPM_DPLL_STAT");
                // fapi2::delay takes ns as the arg
                fapi2::delay(DPLL_POLLTIME_MS * 1000 * 1000, DPLL_POLLTIME_MCYCLES * 1000 * 1000);
            }
            while((l_data64.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_UPDATE_COMPLETE>() != 1 ||
                   (l_data64.getBit<TP_TPCHIP_TPC_DPLL_CNTL_NEST_REGS_STAT_LOCK>() != 1)) &&
                  (--l_timeout_counter != 0));

            FAPI_ASSERT(l_timeout_counter != 0,
                        fapi2::PM_DPLL_FREQ_UPDATE_FAIL()
                        .set_CHIP_TARGET(i_target)
                        .set_DPLL_FREQ(i_safe_mode_dpll_value)
                        .set_DPLL_STAT(l_data64),
                        "update dpll freq fail");
        }


        // clear sticky PLL unlock indicator before unmasking reporting
        // register is WCLEAR
        l_data64.flush<0>().insertFromRight< TP_TPCHIP_NET_PCBSLPERV_ERROR_REG_PLL_UNLOCK_ERROR,
                       TP_TPCHIP_NET_PCBSLPERV_ERROR_REG_PLL_UNLOCK_ERROR_LEN > ( 0x01 );
        FAPI_TRY( fapi2::putScom( i_target, TP_TPCHIP_NET_PCBSLPERV_ERROR_REG, l_data64 ),
                  "Failed to Write PERV_ERROR_REG");

        // re-enable error reporting
        FAPI_TRY( fapi2::getScom( i_target, TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG, l_data64 ),
                  "Failed To Read PERV_SLAVE_CONFIG_REG" );

        l_data64.insertFromRight< P10_20_TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS,
                                  P10_20_TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN > ( l_mask_restore );

        FAPI_TRY( fapi2::putScom( i_target, TP_TPCHIP_NET_PCBSLPERV_SLAVE_CONFIG_REG, l_data64 ),
                  "Failed To Write PERV_SLAVE_CONFIG_REG" );
    }
    while (0);

fapi_try_exit:
    FAPI_INF("< p10_update_dpll_value");
    return fapi2::current_err;
}


