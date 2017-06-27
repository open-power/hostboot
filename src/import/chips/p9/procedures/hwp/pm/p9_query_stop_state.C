/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_query_stop_state.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_query_stop_state.C
/// @brief Determine the state of cores, L2, and L3 of the targeted EX
///        Set ATTRs to know the scommable/scannable state of the logic
///        Further operations in the dump flow will only operate on scommable
///        portions of the targets.   FW/Platform is responsible for checking these
///        states before calling HWPs
///
// *HWP HWP Owner: Brian Vanderpool <vanderp@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS
///
///
///
/// @verbatim
/// High-level procedure flow:
///     - For each EX, check the PPMC stop state history to know the state
///       of the core.  Check the PPMQ stop state history to know the state of L2/L3
///
///     - Then read the PFETSNS in the C/QPPM and CLOCK_STAT registers in the EPS to determine
///       the actual state of the hardware.   Use the HW values to print out a warning if
///       different, and override the attributes
///
///     - Set ATTRs to know the scommable/scannable state of the logic
///          L2_HASCLOCKS      indicates the L2 region has clocks running and scommable
///          L3_HASCLOCKS      indicates the L3 region has clocks running and scommable
///          C0_EXEC_HASCLOCKS indicates the execution units in core 0 have clocks running and scommable
///          C1_EXEC_HASCLOCKS indicates the execution units in core 1 have clocks running and scommable
///          C0_PC_HASCLOCKS   indicates the core pervasive unit in core 0 has clocks running and scommable
///          C1_PC_HASCLOCKS   indicates the core pervasive unit in core 1 has clocks running and scommable
///          L2_HASPOWER      indicates L2 has power and has valid latch state that could be scanned
///          L3_HASPOWER      indicates L3 has power and has valid latch state that could be scanned
///          C0_HASPOWER      indicates core 0 has power and has valid latch state that could be scanned
///          C1_HASPOWER      indicates core 1 has power and has valid latch state that could be scanned
/// @endverbatim
///
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p9_query_stop_state.H"


// ----------------------------------------------------------------------
// Data Structure Definitions
// ----------------------------------------------------------------------

typedef struct
{

    uint8_t  l2_hasclocks;
    uint8_t  l3_hasclocks;
    uint8_t  c_exec_hasclocks[2];
    uint8_t  c_pc_hasclocks[2];

    uint8_t  vdd_pfet_disable_quad;
    uint8_t  vcs_pfet_disable_quad;
    uint8_t  vdd_pfet_disable_core[2];


    bool c0_haspower()
    {
        return !vdd_pfet_disable_core[0];
    }

    bool c1_haspower()
    {
        return !vdd_pfet_disable_core[1];
    }

    bool l2_haspower()
    {
        return (!vdd_pfet_disable_quad && !vcs_pfet_disable_quad);
    }

    bool l3_haspower()
    {
        return (!vdd_pfet_disable_quad && !vcs_pfet_disable_quad);
    }

} hw_state_t;

// Bit positions in the CLOCK_SL register for the L20, L21 and L30, L31 running state
const uint32_t eq_clk_l2_pos[] = {8, 9};
const uint32_t eq_clk_l3_pos[] = {6, 7};

// ----------------------------------------------------------------------
// Procedure Prototypes
// ----------------------------------------------------------------------

void compare_ss_hw(const char* msg, const uint8_t hw_state, uint8_t& stop_state);

#define SSHSRC_STOP_GATED 0

// ----------------------------------------------------------------------
// Procedure Function
// ----------------------------------------------------------------------

void compare_ss_hw(const char* msg, const uint8_t hw_state, uint8_t& stop_state)
{

    // Compare the HW (pfet/clock) state with the value the stop state history registers would indicate,
    //  and if there is a mismatch, use the HW value.

    if (hw_state != stop_state)
    {
        FAPI_INF("WARNING: %s mismatch.  HW(%d) StopState(%d).  Using HW value", msg, hw_state, stop_state);
        // Use the HW value
        stop_state = hw_state;
    }
}

fapi2::ReturnCode
query_stop_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target,
    stop_attrs_t& o_stop_attrs)
{
    fapi2::buffer<uint64_t>  l_qsshsrc, l_csshsrc[2], l_qpfetsense, l_cpfetsense[2], l_qStopGated, l_cStopGated;
    fapi2::buffer<uint64_t> l_data64, l_sisr;
    uint8_t  l_chpltNumber = 0;
    uint32_t l_quadStopLevel = 0;
    uint32_t l_exPos = 0;
    uint32_t l_coreStopLevel[2] = {0, 0};
    uint8_t  l_data8 = 0;

    hw_state_t l_clk_pfet = {0, 0, {0, 0}, {0, 0}, 0, 0, {0, 0}}; // Initialize all fields to 0


    FAPI_INF("> p9_query_stop_state...");


    // Get the parent EQ and core children
    auto l_eq_target    = i_ex_target.getParent<fapi2::TARGET_TYPE_EQ>();
    auto l_coreChiplets = i_ex_target.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_FUNCTIONAL);


    FAPI_DBG("   Read QPPM Stop State History");
    FAPI_TRY(fapi2::getScom(l_eq_target, EQ_PPM_SSHSRC, l_qsshsrc), "Error reading data from QPPM SSHSRC");


    // Get the status of each SSHSRC in each configured CPPM.
    // Initialize both states to disabled in case one core is deconfigured
    l_csshsrc[0].flush<0>().insertFromRight<0, 12>(0x80F);
    l_csshsrc[1].flush<0>().insertFromRight<0, 12>(0x80F);

    for (auto l_core_chplt : l_coreChiplets)
    {
        // Fetch the position of the Core target
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core_chplt, l_chpltNumber),
                 "ERROR: Failed to get the position of the Core:0x%08X",
                 l_core_chplt);

        //In case a core is deconfigured, figure out if this is the odd or even core and write the appropriate array
        uint32_t l_pos = l_chpltNumber % 2;

        FAPI_DBG("   Read CPPM Stop State History for core %d", l_chpltNumber);
        FAPI_TRY(fapi2::getScom(l_core_chplt, C_PPM_SSHSRC, l_csshsrc[l_pos]), "Error reading data from CPPM SSHSRC");

    }

    // A unit is scomable if clocks are running
    // A unit is scannable if the unit is powered up.

    // Extract the quad and core stop states
    if (l_qsshsrc.getBit<SSHSRC_STOP_GATED>() == 1)
    {
        l_qsshsrc.extractToRight<uint32_t>(l_quadStopLevel, 8, 4);
    }

    if (l_csshsrc[0].getBit<SSHSRC_STOP_GATED>() == 1)
    {
        l_csshsrc[0].extractToRight<uint32_t>(l_coreStopLevel[0], 8, 4);
    }

    if (l_csshsrc[1].getBit<SSHSRC_STOP_GATED>() == 1)
    {
        l_csshsrc[1].extractToRight<uint32_t>(l_coreStopLevel[1], 8, 4);
    }


    // if the quad is not stop gated, double check the CME SISR register to make sure we aren't in stop 1
    if (l_qsshsrc.getBit<SSHSRC_STOP_GATED>() == 0)
    {

        // if cores aren't stop gated, double check the SISR register to make sure it isn't in stop 1
        FAPI_TRY(fapi2::getScom(i_ex_target, EX_CME_LCL_SISR_SCOM, l_sisr), "Error reading data from CME SISR register");

        if (l_coreStopLevel[0] == 0 && l_sisr.getBit<EX_CME_LCL_SISR_PM_STATE_ACTIVE_C0>() )
        {
            l_sisr.extractToRight<uint32_t>(l_coreStopLevel[0], EX_CME_LCL_SISR_PM_STATE_C0, EX_CME_LCL_SISR_PM_STATE_C0_LEN);
        }

        if (l_coreStopLevel[1] == 0 && l_sisr.getBit<EX_CME_LCL_SISR_PM_STATE_ACTIVE_C1>() )
        {
            l_sisr.extractToRight<uint32_t>(l_coreStopLevel[1], EX_CME_LCL_SISR_PM_STATE_C1, EX_CME_LCL_SISR_PM_STATE_C1_LEN);
        }
    }



    FAPI_INF("EX Stop States: Q(%d) C0(%d) C1(%d)", l_quadStopLevel, l_coreStopLevel[0], l_coreStopLevel[1]);

    // Error check that the core stop states are >= the quad stop state
    FAPI_ASSERT( (l_coreStopLevel[0] >= l_quadStopLevel) && (l_coreStopLevel[1] >= l_quadStopLevel),
                 fapi2::P9_QUERY_STOP_STATE_INCONSISTENT()
                 .set_QSSHSRC(l_quadStopLevel)
                 .set_C0SSHSRC(l_coreStopLevel[0])
                 .set_C1SSHSRC(l_coreStopLevel[1]),
                 "ERROR: Stop States are inconsistent Q(%d) C0(%d) C1(%d)",
                 l_quadStopLevel, l_coreStopLevel[0], l_coreStopLevel[1]);


    //----------------------------------------------------------------------------------
    // Based on the stop state history registers,
    //  Set the attributes for the L2, L3 scanable and scomable
    //----------------------------------------------------------------------------------

    // STOP1 - NAP
    //  VSU, ISU are clocked off
    if (l_coreStopLevel[0] >= 1)
    {
        o_stop_attrs.c0_exec_hasclocks = 0;
    }

    if (l_coreStopLevel[1] >= 1)
    {
        o_stop_attrs.c1_exec_hasclocks = 0;
    }

    // STOP2 - Fast Sleep
    //   VSU, ISU are clocked off
    //   IFU, LSU are clocked off
    //   PC, Core EPS are clocked off
    if (l_coreStopLevel[0] >= 2)
    {
        o_stop_attrs.c0_pc_hasclocks = 0;
    }

    if (l_coreStopLevel[1] >= 2)
    {
        o_stop_attrs.c1_pc_hasclocks = 0;
    }

    // STOP4 - Deep Sleep  (special exception for stop 9 - lab use only)
    //   VSU, ISU are powered off
    //   IFU, LSU are powered off
    //   PC, Core EPS are powered off
    if (l_coreStopLevel[0] >= 4 && l_coreStopLevel[0] != 9)
    {
        o_stop_attrs.c0_haspower = 0;
    }

    if (l_coreStopLevel[1] >= 4 && l_coreStopLevel[1] != 9)
    {
        o_stop_attrs.c1_haspower = 0;
    }


    // STOP8 - Half Quad Deep Sleep
    //   VSU, ISU are powered off
    //   IFU, LSU are powered off
    //   PC, Core EPS are powered off
    //   L20-EX0 is clocked off if both cores are >= 8
    //   L20-EX1 is clocked off if both cores are >= 8
    if (l_quadStopLevel >= 8)
    {

        // The FAPI_ASSERT above ensures both cores are >= the quad stop state
        o_stop_attrs.l2_hasclocks = 0;
    }

    // STOP9 - Fast Winkle (lab use only)
    // Both cores and cache are clocked off
    if (l_quadStopLevel >= 9)
    {
        o_stop_attrs.l3_hasclocks = 0;
    }

    // STOP11 - Deep Winkle
    // Both cores and cache are powered off
    if (l_quadStopLevel >= 11)
    {
        o_stop_attrs.l2_haspower = 0;
        o_stop_attrs.l3_haspower = 0;
    }

    //----------------------------------------------------------------------------------
    // Read clock status and pfet_sense_disabled to confirm stop state history is accurate
    //----------------------------------------------------------------------------------

    // Read voltage state to make sure pfets are enabled.
    FAPI_DBG("   Read QPPM PFETSENSE");
    FAPI_TRY(fapi2::getScom(l_eq_target, EQ_PPM_PFSNS, l_qpfetsense), "Error reading data from QPPM PFSNS");

    // Get the status of each PFSNS in each configured CPPM.
    // Initialize variables as disabled (bits 1 (VDD) and 3 (VCS)) for partial good readiness
    l_cpfetsense[0].flush<0>().insertFromRight<0, 4>(0x5);
    l_cpfetsense[1].flush<0>().insertFromRight<0, 4>(0x5);

    for (auto l_core_chplt : l_coreChiplets)
    {
        // Fetch the position of the Core target
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core_chplt, l_chpltNumber),
                 "ERROR: Failed to get the position of the Core:0x%08X",
                 l_core_chplt);

        FAPI_DBG("   Read CPPM PFETSENSE for core %d", l_chpltNumber);
        //In case a core is deconfigured, figure out if this is the odd or even core and write the appropriate array
        uint32_t l_pos = l_chpltNumber % 2;

        FAPI_TRY(fapi2::getScom(l_core_chplt, C_PPM_PFSNS, l_cpfetsense[l_pos]), "Error reading data from CPPM SSHSRC");

    }

    // Extract out the disabled bits
    l_qpfetsense.extractToRight<uint8_t>(l_clk_pfet.vdd_pfet_disable_quad, 1, 1);
    l_qpfetsense.extractToRight<uint8_t>(l_clk_pfet.vcs_pfet_disable_quad, 3, 1);

    l_cpfetsense[0].extractToRight<uint8_t>(l_clk_pfet.vdd_pfet_disable_core[0], 1, 1);
    l_cpfetsense[1].extractToRight<uint8_t>(l_clk_pfet.vdd_pfet_disable_core[1], 1, 1);

    // Read clocks running registers if the quad is powered up

    if (l_clk_pfet.vdd_pfet_disable_quad == 0 )
    {

        // Determine if this is an odd or even EX for checking EX clock state
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_ex_target, l_chpltNumber),
                 "ERROR: Failed to get the position of the EX:0x%08X",
                 i_ex_target);

        l_exPos = l_chpltNumber % 2;

        FAPI_TRY(fapi2::getScom(l_eq_target, EQ_CLOCK_STAT_SL,  l_data64), "Error reading data from EQ_CLOCK_STAT_SL");


        l_data64.extractToRight<uint8_t>(l_data8, eq_clk_l2_pos[l_exPos], 1);
        l_clk_pfet.l2_hasclocks = (l_data8 == 1) ? 0 : 1; // If the bit is 0, clocks are running

        l_data64.extractToRight<uint8_t>(l_data8, eq_clk_l3_pos[l_exPos], 1);
        l_clk_pfet.l3_hasclocks = (l_data8 == 1) ? 0 : 1; // If the bit is 0, clocks are running

    }


    for (auto l_core_chplt : l_coreChiplets)
    {
        // Fetch the position of the Core target
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core_chplt, l_chpltNumber),
                 "ERROR: Failed to get the position of the Core:0x%08X",
                 l_core_chplt);


        //In case a core is deconfigured, figure out if this is the odd or even core and write the appropriate array
        uint32_t l_pos = l_chpltNumber % 2;

        if (l_clk_pfet.vdd_pfet_disable_core[l_pos] == 0)
        {
            FAPI_DBG("   Read Core EPS clock status for core %d", l_chpltNumber);


            FAPI_TRY(fapi2::getScom(l_core_chplt, C_CLOCK_STAT_SL,  l_data64), "Error reading data from C_CLOCK_STAT_SL");

            l_data64.extractToRight<uint8_t>(l_data8, 6, 1);
            l_clk_pfet.c_exec_hasclocks[l_pos] = (l_data8 == 1) ? 0 : 1; // If the bit is 0, clocks are running

            l_data64.extractToRight<uint8_t>(l_data8, 5, 1);
            l_clk_pfet.c_pc_hasclocks[l_pos] = (l_data8 == 1) ? 0 : 1; // If the bit is 0, clocks are running
        }
    }

    FAPI_DBG("Comparing Stop State vs Actual HW settings");
    FAPI_DBG("C0_EXEC_HASCLOCKS   ATTR(%d)  HW(%d)", o_stop_attrs.c0_exec_hasclocks, l_clk_pfet.c_exec_hasclocks[0]);
    FAPI_DBG("C1_EXEC_HASCLOCKS   ATTR(%d)  HW(%d)", o_stop_attrs.c1_exec_hasclocks, l_clk_pfet.c_exec_hasclocks[1]);

    FAPI_DBG("C0_PC_HASCLOCKS     ATTR(%d)  HW(%d)", o_stop_attrs.c0_pc_hasclocks, l_clk_pfet.c_pc_hasclocks[0]);
    FAPI_DBG("C1_PC_HASCLOCKS     ATTR(%d)  HW(%d)", o_stop_attrs.c1_pc_hasclocks, l_clk_pfet.c_pc_hasclocks[1]);

    FAPI_DBG("L2_HASCLOCKS        ATTR(%d)  HW(%d)", o_stop_attrs.l2_hasclocks, l_clk_pfet.l2_hasclocks);
    FAPI_DBG("L3_HASCLOCKS        ATTR(%d)  HW(%d)", o_stop_attrs.l3_hasclocks, l_clk_pfet.l3_hasclocks);



    FAPI_DBG("C0_HASPOWER         ATTR(%d)  HW(%d)", o_stop_attrs.c0_haspower, l_clk_pfet.c0_haspower());
    FAPI_DBG("C1_HASPOWER         ATTR(%d)  HW(%d)", o_stop_attrs.c1_haspower, l_clk_pfet.c1_haspower());

    FAPI_DBG("L2_HASPOWER         ATTR(%d)  HW(%d)", o_stop_attrs.l2_haspower, l_clk_pfet.l2_haspower());
    FAPI_DBG("L3_HASPOWER         ATTR(%d)  HW(%d)", o_stop_attrs.l3_haspower, l_clk_pfet.l3_haspower());

    //----------------------------------------------------------------------------------
    // Compare Hardware status vs stop state status.   If there is a mismatch, the HW value overrides the stop state
    //----------------------------------------------------------------------------------

    compare_ss_hw("C0_exec_HASCLOCKS", l_clk_pfet.c_exec_hasclocks[0], o_stop_attrs.c0_exec_hasclocks);
    compare_ss_hw("C1_exec_HASCLOCKS", l_clk_pfet.c_exec_hasclocks[1], o_stop_attrs.c1_exec_hasclocks);
    compare_ss_hw("C0_pc_HASCLOCKS",   l_clk_pfet.c_pc_hasclocks[0],   o_stop_attrs.c0_pc_hasclocks);
    compare_ss_hw("C1_pc_HASCLOCKS",   l_clk_pfet.c_pc_hasclocks[1],   o_stop_attrs.c1_pc_hasclocks);
    compare_ss_hw("L2_HASCLOCKS",      l_clk_pfet.l2_hasclocks,        o_stop_attrs.l2_hasclocks);
    compare_ss_hw("L3_HASCLOCKS",      l_clk_pfet.l3_hasclocks,        o_stop_attrs.l3_hasclocks);

    compare_ss_hw("C0_HASPOWER",       l_clk_pfet.c0_haspower(),       o_stop_attrs.c0_haspower);
    compare_ss_hw("C1_HASPOWER",       l_clk_pfet.c1_haspower(),       o_stop_attrs.c1_haspower);
    compare_ss_hw("L2_HASPOWER",       l_clk_pfet.l2_haspower(),       o_stop_attrs.l2_haspower);
    compare_ss_hw("L3_HASPOWER",       l_clk_pfet.l3_haspower(),       o_stop_attrs.l3_haspower);


fapi_try_exit:
    FAPI_INF("< p9_query_stop_state...");
    return fapi2::current_err;
}

fapi2::ReturnCode
p9_query_stop_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target)
{


    stop_attrs_t  l_stop_attrs = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // Initialize all fields to 1

    FAPI_TRY(query_stop_state(i_ex_target, l_stop_attrs));

    //----------------------------------------------------------------------------------
    // Set the Attributes
    //----------------------------------------------------------------------------------
    FAPI_DBG("Setting attributes\n");
    // HASCLOCKS attributes (scomable)
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_L2_HASCLOCKS,      i_ex_target, l_stop_attrs.l2_hasclocks));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_L3_HASCLOCKS,      i_ex_target, l_stop_attrs.l3_hasclocks));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C0_EXEC_HASCLOCKS, i_ex_target, l_stop_attrs.c0_exec_hasclocks));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C1_EXEC_HASCLOCKS, i_ex_target, l_stop_attrs.c1_exec_hasclocks));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C0_PC_HASCLOCKS,   i_ex_target, l_stop_attrs.c0_pc_hasclocks));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C1_PC_HASCLOCKS,   i_ex_target, l_stop_attrs.c1_pc_hasclocks));

    // HASPOWER attributes (scanable)
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_L2_HASPOWER,      i_ex_target, l_stop_attrs.l2_haspower));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_L3_HASPOWER,      i_ex_target, l_stop_attrs.l3_haspower));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C0_HASPOWER,      i_ex_target, l_stop_attrs.c0_haspower));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_C1_HASPOWER,      i_ex_target, l_stop_attrs.c1_haspower));

fapi_try_exit:
    FAPI_INF("< p9_query_stop_state...");
    return fapi2::current_err;
}
