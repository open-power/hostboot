/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pstate_parameter_block.C $ */
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

///
/// @file  p9_pstate_parameter_block.C
/// @brief Setup Pstate super structure for PGPE/CME HCode
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 3
/// *HWP Consumed by     : PGPE,CME
///
/// @verbatim
/// Procedure Summary:
///   - Read VPD and attributes to create the Pstate Parameter Block(s) (one each for PGPE,OCC and CMEs).
/// @endverbatim

// *INDENT-OFF*
//
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pstate_parameter_block.H>
#include <p9_hcd_memmap_base.H>
#include "p9_pm_get_poundw_bucket.H"
#include "p9_resclk_defines.H"
#include <attribute_ids.H>
#include <math.h>
//the value in this table are in Index format
uint8_t g_GreyCodeIndexMapping [] =
{
/*    0x00*/ 0,
/*    0x01*/ 1,
/*    0x02*/ 3,
/*    0x03*/ 2,
/*    0x04*/ 7,
/*    0x05*/ 6,
/*    0x06*/ 4,
/*    0x07*/ 5,
/*    0x08*/ 12,
/*    0x09*/ 12,
/*    0x0a*/ 12,
/*    0x0b*/ 12,
/*    0x0c*/ 8,
/*    0x0d*/ 9,
/*    0x0e*/ 11,
/*    0x0f*/ 10
};

fapi2::vdmData_t g_vpdData = {1,
                              2,
{
    0x29, 0x0C, 0x05, 0xC3, 0x61, 0x36, 0x1, 0x3, 0x0, 0x0,   //Nominal
    0x28, 0xa8, 0x05, 0x5f, 0x21, 0x36, 0x1, 0x3, 0x0, 0x0,   //PowerSave
    0x29, 0x70, 0x06, 0x27, 0x71, 0x36, 0x1, 0x3, 0x0, 0x0,   //Turbo
    0x29, 0xD4, 0x06, 0x8b, 0x51, 0x36, 0x1, 0x3, 0x0, 0x0,   //UltraTurbo
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0, 0x0, 0x0, 0x0,   //Resistance
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0, 0x0, 0x0, 0x0    //Spare
}
                             };


uint8_t g_wofData[] = { 0x57, 0x46, 0x54, 0x48  /*MAGIC CODE WFTH*/,
                        0x00, 0x00, 0x00, 0x01  /*version*/,
                        0x00, 0x80              /*VFRT block size*/,
                        0x00, 0x08              /*VFRT header size*/,
                        0x00, 0x01              /*VFRT data size*/,
                        0x6                     /*Quad value*/,
                        0x18                    /*core count*/,
                        0x00, 0xFA              /*Vdn start*/,
                        0x00, 0x64              /*Vdn step*/,
                        0x00, 0x08              /*Vdn size*/,
                        0x00, 0x00              /*Vdd start*/,
                        0x00, 0x32              /*Vdd step*/,
                        0x00, 0x15              /*Vdd size*/,
                        0x03, 0xE8              /*Vratio start*/,
                        0x00, 0x53              /*Vratio step*/,
                        0x00, 0x18              /*Vratio size*/,
                        0x03, 0xE8              /*Fratio start*/,
                        0x00, 0x64              /*Fratio step*/,
                        0x00, 0x5               /*Fratio size*/,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*Vdn percent*/,
                        0x00, 0x64              /*Socket power Watts*/,
                        0x07, 0x4a              /*nest freq*/,
                        0x09, 0x60              /*nominl freq*/,
                        0x00, 0x00              /*RDP capacity*/,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /* WOF table source tag*/,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*package name*/,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /*Pad to 128B*/
                      };


uint8_t g_sysvfrtData[] = {0x56, 0x54, 0x00, 0x00, 0x02, 0x01, 0x01, 0x06, /// VFRT header values
                           // Magic_codea(2B)
                           // reserved(2B)
                           // type(4b),version(4b)
                           // vdn(1B),vdd(1B)
                           // quad id(1B)
                           0xB1, 0xB1, 0xB0, 0xAF, 0xA9, 0xA1, 0x97, 0x8E, 0x86, 0x7F, 0x78, 0x73, 0x6D, 0x68, 0x63, 0x5F, 0x5B, 0x57, 0x53, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D,
                           0xB1, 0xB1, 0xB0, 0xAF, 0xA9, 0xA1, 0x97, 0x8E, 0x86, 0x7F, 0x78, 0x73, 0x6D, 0x68, 0x63, 0x5F, 0x5B, 0x57, 0x53, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D,
                           0xB1, 0xB1, 0xB0, 0xAF, 0xA9, 0xA1, 0x97, 0x8E, 0x86, 0x7F, 0x78, 0x73, 0x6D, 0x68, 0x63, 0x5F, 0x5B, 0x57, 0x53, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D,
                           0xB1, 0xB1, 0xB0, 0xAF, 0xA9, 0xA1, 0x97, 0x8E, 0x86, 0x7F, 0x78, 0x73, 0x6D, 0x68, 0x63, 0x5F, 0x5B, 0x57, 0x53, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D,
                           0xB1, 0xB1, 0xB0, 0xAF, 0xA9, 0xA1, 0x97, 0x8E, 0x86, 0x7F, 0x78, 0x73, 0x6D, 0x68, 0x63, 0x5F, 0x5B, 0x57, 0x53, 0x4E, 0x4D, 0x4D, 0x4D, 0x4D
                          };

#define VALIDATE_VID_VALUES(w,x,y,z,state) \
    if (!((w < x) && (x < y) && (y < z)))  \
       {state = 0;}

#define VALIDATE_THRESHOLD_VALUES(w,x,y,z,state) \
    if ((w > 0x7 && w != 0xC) || /* overvolt */ \
        (x == 8) ||  (x == 9) || (x > 0xF) ||  \
        (y == 8) ||  (y == 9) || (y > 0xF) ||  \
        (z == 8) ||  (z == 9) || (z > 0xF)   ) \
       {state = 0;}

//w => N_L (w > 7 is invalid)
//x => N_S (x > N_L is invalid)
//y => L_S (y > (N_L - S_N) is invalid)
//z => S_N (z > N_S is invalid
#define VALIDATE_FREQUENCY_DROP_VALUES(w,x,y,z,state) \
    if ((w > 7)         ||  \
        (x > w)         ||  \
        (y > (w - z))   ||  \
        (z > x)         ||  \
        ((w | x | y | z) == 0)) \
       {state = 0; }

#define VALIDATE_WOF_HEADER_DATA(a,b,c,d,e,f,g,state) \
     if ( ((!a) || (!b) || (!c) || (!d) || (!e) || (!f) || (!g)))  \
       {state = 0; }



double internal_ceil(double x)
{
    if ((x-(int)(x))>0) return (int)x+1;
    return ((int)x);
}

double internal_floor(double x)
{
    if(x>=0)return (int)x;
    return (int)(x-0.9999999999999999);
}


// Struct Variable for all attributes
AttributeList attr;

// Strings used in traces
char const* vpdSetStr[NUM_VPD_PTS_SET] = VPD_PT_SET_ORDER_STR;
char const* region_names[]     = { "REGION_POWERSAVE_NOMINAL",
                                   "REGION_NOMINAL_TURBO",
                                   "REGION_TURBO_ULTRA"
                                 };
char const* prt_region_names[] = VPD_OP_SLOPES_REGION_ORDER_STR;

///--------------------------------------
/// @brief Check wof is enabled or not
/// @param[in]  pstate attribute state
/// @return true or false
///--------------------------------------
bool
is_wof_enabled(PSTATE_attribute_state* i_state)
{
    return
        (!(attr.attr_system_wof_disable) &&
         !(attr.attr_dd_wof_not_supported) &&
         i_state->iv_wof_enabled)
        ? true : false;
}

///--------------------------------------
/// @brief Check vdm is enabled or not
/// @param[in]  pstate attribute state
/// @return true or false
///--------------------------------------
bool
is_vdm_enabled(PSTATE_attribute_state* i_state)
{
    return
        (!(attr.attr_system_vdm_disable) &&
         !(attr.attr_dd_vdm_not_supported) &&
         i_state->iv_vdm_enabled)
         ? true : false;
}

// START OF PSTATE PARAMETER BLOCK function
fapi2::ReturnCode
p9_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           PstateSuperStructure* io_pss,
                           uint8_t* o_buf,
                           uint32_t& io_size)
{
    FAPI_DBG("> p9_pstate_parameter_block");
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ReturnCode l_rc         = 0;
    io_size = 0;

    do
    {

        // -----------------------------------------------------------
        // Clear the PstateSuperStructure and install the magic number
        //----------------------------------------------------------
        memset(io_pss, 0, sizeof(PstateSuperStructure));

        FAPI_INF("Populating magic number in Pstate Parameter block structure");
        (*io_pss).magic = revle64(PSTATE_PARMSBLOCK_MAGIC);

        //Local variables for Global,local and OCC parameter blocks
        // PGPE content
        GlobalPstateParmBlock l_globalppb;
        memset (&l_globalppb, 0, sizeof(GlobalPstateParmBlock));

        // CME content
        LocalPstateParmBlock l_localppb;
        memset (&l_localppb, 0, sizeof(LocalPstateParmBlock));

        // OCC content
        OCCPstateParmBlock l_occppb;
        memset (&l_occppb , 0, sizeof (OCCPstateParmBlock));

        PSTATE_attribute_state l_state;
        l_state.iv_pstates_enabled = true;
        l_state.iv_resclk_enabled  = true;
        l_state.iv_vdm_enabled     = true;
        l_state.iv_ivrm_enabled    = true;
        l_state.iv_wof_enabled     = true;

        // Enablement state
        PoundW_data l_poundw_data;
        memset (&l_poundw_data,0,sizeof(l_poundw_data));

        // MVPD #V variables
        uint32_t attr_mvpd_voltage_control[PV_D][PV_W];
        uint8_t present_chiplets = 0;
        uint32_t valid_pdv_points = 0;

        //Variables for Loadline, Distribution loss and offset
        SysPowerDistParms l_vdd_sysparm;
        memset(&l_vdd_sysparm,0x00,sizeof(SysPowerDistParms));

        SysPowerDistParms l_vcs_sysparm;
        memset(&l_vcs_sysparm,0x00,sizeof(SysPowerDistParms));

        SysPowerDistParms l_vdn_sysparm;
        memset(&l_vdn_sysparm,0x00,sizeof(SysPowerDistParms));

        // Local IDDQ table variable
        IddqTable l_iddqt;
        memset( & l_iddqt, 0x00, sizeof(IddqTable));

        // Frequency step variable
        double l_frequency_step_khz;

        //VDM Parm block
        GP_VDMParmBlock l_gp_vdmpb;
        memset (&l_gp_vdmpb,0x00,sizeof(GP_VDMParmBlock));

        LP_VDMParmBlock   l_lp_vdmpb;
        memset (&l_lp_vdmpb, 0x00, sizeof(LP_VDMParmBlock));

        //Resonant Clocking setup
        ResonantClockingSetup l_resclk_setup;
        memset (&l_resclk_setup,0x00, sizeof(ResonantClockingSetup));

        //IVRM Parm block
        IvrmParmBlock l_ivrmpb;
        memset (&l_ivrmpb, 0x00,sizeof(IvrmParmBlock));

        // VPD voltage and frequency biases
        VpdBias l_vpdbias[NUM_OP_POINTS];
        memset (l_vpdbias,0,sizeof(VpdBias));

        // -------------------------
        // Get all attributes needed
        // -------------------------
        FAPI_INF("Getting Attributes to build Pstate Superstructure");

        FAPI_TRY(proc_get_attributes(i_target, &attr), "Get attributes function failed");

        //if PSTATES_MODE is off then we dont need to execute further to collect
        //the data.
        if (attr.attr_pstate_mode == fapi2::ENUM_ATTR_SYSTEM_PSTATES_MODE_OFF)
        {
            FAPI_INF("Pstate mode is to not boot the PGPE.  Thus, none of the parameter blocks will be constructed");

            // Set the io_size to 0 so that memory allocation issues won't be
            // detected by the caller.
            io_size = 0;
            break;
        }

        // ----------------
        // get #V data
        // ----------------
        FAPI_IMP("Getting #V Data");
        uint8_t l_poundv_bucketId = 0;

        // clear MVPD array
        memset(attr_mvpd_voltage_control, 0, sizeof(attr_mvpd_voltage_control));
        fapi2::voltageBucketData_t l_poundv_data;

        FAPI_TRY(proc_get_mvpd_data(i_target, attr_mvpd_voltage_control,
                                    &valid_pdv_points,
                                    &present_chiplets,
                                    l_poundv_bucketId,
                                    &l_poundv_data, &l_state),
                 "proc_get_mvpd_data function failed to retrieve pound V data");

        if (!present_chiplets)
        {
            FAPI_IMP("**** WARNING : There are no EQ chiplets present which means there is no valid #V VPD");
            FAPI_IMP("**** WARNING : Pstates and all related functions will NOT be enabled.");
            l_state.iv_pstates_enabled  = false;
            l_state.iv_resclk_enabled   = false;
            l_state.iv_resclk_enabled   = false;
            l_state.iv_wof_enabled      = false;

            // Set the io_size to 0 so that memory allocation issues won't be
            // detected by the caller.
            io_size = 0;
            break;
        }

        FAPI_DBG("Pstate Base Frequency - Raw %X (%d)",
                 attr_mvpd_voltage_control[ULTRA][0] * 1000,
                 attr_mvpd_voltage_control[ULTRA][0] * 1000);

        //Calculate freq step value
        l_frequency_step_khz = (attr.attr_freq_proc_refclock_khz /
                                attr.attr_proc_dpll_divider);

        VpdOperatingPoint l_raw_operating_points[NUM_OP_POINTS];
        FAPI_INF("Load RAW VPD");
        FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control,
                                           l_raw_operating_points,
                                           l_frequency_step_khz),
                 "Loading MVPD operating point failed");

        // ---------------------------------------------
        // process external and internal bias attributes
        // ---------------------------------------------
        FAPI_IMP("Apply Biasing to #V");

        FAPI_TRY(proc_get_extint_bias(attr_mvpd_voltage_control,
                                      &attr,
                                      l_vpdbias),
                 "Bias application function failed");

        //Validating Bias values
        FAPI_INF("Validate Biasd Voltage and Frequency values");

        FAPI_TRY(proc_chk_valid_poundv( i_target,
                                        attr_mvpd_voltage_control,
                                        &valid_pdv_points,
                                        i_target.getChipletNumber(),
                                        l_poundv_bucketId,
                                        &l_state,true));

        FAPI_DBG("Pstate Base Frequency - after bias %X (%d)",
                 attr_mvpd_voltage_control[ULTRA][0] * 1000,
                 attr_mvpd_voltage_control[ULTRA][0] * 1000);

        // -----------------------------------------------
        // System power distribution parameters
        // -----------------------------------------------
        // VDD rail
        l_vdd_sysparm.loadline_uohm = revle32(attr.attr_proc_r_loadline_vdd_uohm);
        l_vdd_sysparm.distloss_uohm = revle32(attr.attr_proc_r_distloss_vdd_uohm);
        l_vdd_sysparm.distoffset_uv = revle32(attr.attr_proc_vrm_voffset_vdd_uv);

        // VCS rail
        l_vcs_sysparm.loadline_uohm = revle32(attr.attr_proc_r_loadline_vcs_uohm);
        l_vcs_sysparm.distloss_uohm = revle32(attr.attr_proc_r_distloss_vcs_uohm);
        l_vcs_sysparm.distoffset_uv = revle32(attr.attr_proc_vrm_voffset_vcs_uv);

        // VDN rail
        l_vdn_sysparm.loadline_uohm = revle32(attr.attr_proc_r_loadline_vdn_uohm);
        l_vdn_sysparm.distloss_uohm = revle32(attr.attr_proc_r_distloss_vdn_uohm);
        l_vdn_sysparm.distoffset_uv = revle32(attr.attr_proc_vrm_voffset_vdn_uv);

        //if wof is disabled.. don't call IQ function
        if (is_wof_enabled(&l_state))
        {
            // ----------------
            // get IQ (IDDQ) data
            // ----------------
            FAPI_INF("Getting IQ (IDDQ) Data");
            l_rc = proc_get_mvpd_iddq(i_target, &l_iddqt, &l_state);

            if (l_rc)
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_IQ_ACCESS_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CHIP_TARGET(i_target)
                                   .set_FAPI_RC(l_rc),
                                   "Pstate Parameter Block proc_get_mvpd_iddq function failed");
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
        else
        {
            FAPI_INF("Skipping IQ (IDDQ) Data as WOF is disabled");
            l_state.iv_wof_enabled = false;
        }

        // ----------------
        // get VDM Parameters data
        // ----------------
        FAPI_INF("Getting VDM Parameters Data");
        FAPI_TRY(proc_get_vdm_parms(i_target, &attr, &l_gp_vdmpb));

        // Note:  the proc_get_mvpd_poundw has the conditional checking for VDM
        // and WOF enablement as #W has both VDM and WOF content

        l_rc = proc_get_mvpd_poundw(i_target,
                                    l_poundv_bucketId,
                                    &l_lp_vdmpb,
                                    &l_poundw_data,
                                    l_poundv_data, &l_state);

        if (l_rc)
        {
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_POUND_W_ACCESS_FAIL(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                              .set_CHIP_TARGET(i_target)
                              .set_FAPI_RC(l_rc),
                               "Pstate Parameter Block proc_get_mvpd_poundw function failed");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }


        // ----------------
        // get IVRM Parameters data
        // ----------------
        FAPI_INF("Getting IVRM Parameters Data");
        FAPI_TRY(proc_get_ivrm_parms(i_target,
                                     &attr,
                                     &l_ivrmpb,
                                     &l_state));

        // -----------------------------------------------
        // Global parameter block
        // -----------------------------------------------

        // Needs to be Endianness corrected going into the block

        l_globalppb.magic = revle64(PSTATE_PARMSBLOCK_MAGIC);

        l_globalppb.options.options = 0;   // until options get defined.

        // Pstate Options @todo RTC 161279, Check what needs to be populated here

        // @todo RTC 161279 - Corresponds to Pstate 0 . Setting to ULTRA TURBO
        // frequency point.
        // FIXME this should be the l_operating_points[VPD_PT_SET_BIASED][ULTRA].
        // frequency_mhz value with p9_pstate_compute_vpd_pts ahead of this!!!!
        l_globalppb.reference_frequency_khz =
                revle32((attr_mvpd_voltage_control[ULTRA][0] * 1000));

        FAPI_INF("Pstate Base Frequency %X (%d)",
                 revle32(l_globalppb.reference_frequency_khz),
                 revle32(l_globalppb.reference_frequency_khz));

        // frequency_step_khz
        l_globalppb.frequency_step_khz = revle32(l_frequency_step_khz);
        l_globalppb.nest_frequency_mhz = revle32(attr.attr_nest_frequency_mhz);

        // External VRM parameters
        l_globalppb.ext_vrm_transition_start_ns =
                revle32(attr.attr_ext_vrm_transition_start_ns);
        l_globalppb.ext_vrm_transition_rate_inc_uv_per_us =
                revle32(attr.attr_ext_vrm_transition_rate_inc_uv_per_us);
        l_globalppb.ext_vrm_transition_rate_dec_uv_per_us =
                revle32(attr.attr_ext_vrm_transition_rate_dec_uv_per_us);
        l_globalppb.ext_vrm_stabilization_time_us =
                revle32(attr.attr_ext_vrm_stabilization_time_us);
        l_globalppb.ext_vrm_step_size_mv =
                revle32(attr.attr_ext_vrm_step_size_mv);

        // -----------------------------------------------
        // populate VpdOperatingPoint with biased MVPD attributes
        // -----------------------------------------------

        FAPI_INF("Load VPD");
        // VPD operating point
        FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control,
                                           l_globalppb.operating_points,
                                           l_frequency_step_khz),
                 "Loading MVPD operating point failed");

        // VpdBias External and Internal Biases for Global and Local parameter
        // block
        for (uint8_t i = 0; i < NUM_OP_POINTS; i++)
        {
            l_globalppb.ext_biases[i] = l_vpdbias[i];
            l_globalppb.int_biases[i] = l_vpdbias[i];

            l_localppb.ext_biases[i]  = l_vpdbias[i];
            l_localppb.int_biases[i]  = l_vpdbias[i];
        }

        l_globalppb.vdd_sysparm = l_vdd_sysparm;
        l_globalppb.vcs_sysparm = l_vcs_sysparm;
        l_globalppb.vdn_sysparm = l_vdn_sysparm;

        // safe_voltage_mv
        l_globalppb.safe_voltage_mv = revle32(attr.attr_pm_safe_voltage_mv);

        // safe_frequency_khz
        l_globalppb.safe_frequency_khz =
                        revle32(attr.attr_pm_safe_frequency_mhz / 1000);

        // vrm_stepdelay_range -@todo RTC 161279 potential attributes to be defined

        // vrm_stepdelay_value -@todo RTC 161279 potential attributes to be defined

        VpdOperatingPoint l_operating_points[NUM_VPD_PTS_SET][NUM_OP_POINTS];
        // Compute VPD points
        p9_pstate_compute_vpd_pts(l_operating_points,
                                  &l_globalppb,
                                  l_raw_operating_points);

        memcpy(l_globalppb.operating_points_set,
               l_operating_points,
               sizeof(l_operating_points));

        // ----------------
        // get Resonant clocking attributes
        // ----------------
        {
            if (attr.attr_resclk_disable == fapi2::ENUM_ATTR_SYSTEM_RESCLK_DISABLE_OFF)
            {
                FAPI_TRY(proc_set_resclk_table_attrs(i_target,
                                                     &l_state),
                        "proc_set_resclk_table_attrs failed");

                if (l_state.iv_resclk_enabled)
                {
                    FAPI_TRY(proc_res_clock_setup(i_target,
                                                  &l_resclk_setup,
                                                  &l_globalppb));
                    l_localppb.resclk = l_resclk_setup;
                    l_globalppb.resclk = l_resclk_setup;
                }

                FAPI_INF("Resonant Clocks are enabled");
            }
            else
            {
                l_state.iv_resclk_enabled = false;
                FAPI_INF("Resonant Clocks are disabled.  Skipping setup.");
            }
        }

        // VDMParmBlock vdm
        l_globalppb.vdm = l_gp_vdmpb;

        // IvrmParmBlock
        l_globalppb.ivrm = l_ivrmpb;

        // Calculate pre-calculated slopes
        p9_pstate_compute_PsV_slopes(l_operating_points, &l_globalppb); //Remote this RTC: 174743
        p9_pstate_compute_PStateV_slope(l_operating_points, &l_globalppb);

        l_globalppb.dpll_pstate0_value =
                revle32(revle32(l_globalppb.reference_frequency_khz)  /
                        revle32(l_globalppb.frequency_step_khz));

        FAPI_INF("l_globalppb.dpll_pstate0_value %X",
                revle32(l_globalppb.dpll_pstate0_value));

        // -----------------------------------------------
        // Local parameter block
        // -----------------------------------------------
        l_localppb.magic = revle64(LOCAL_PARMSBLOCK_MAGIC);

        // VPD operating point
        FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control,
                                           l_localppb.operating_points,
                                           l_frequency_step_khz),
                 "Loading MVPD operating point failed");

        l_localppb.vdd_sysparm = l_vdd_sysparm;

        // IvrmParmBlock
        l_localppb.ivrm = l_ivrmpb;

        // VDMParmBlock
        l_localppb.vdm = l_lp_vdmpb;

        l_localppb.dpll_pstate0_value =
                revle32(revle32(l_globalppb.reference_frequency_khz)  /
                        revle32(l_globalppb.frequency_step_khz));

        FAPI_INF("l_localppb.dpll_pstate0_value %X",
                revle32(l_localppb.dpll_pstate0_value));

        uint8_t l_biased_pstate[NUM_OP_POINTS];

        for (uint8_t i = 0; i < NUM_OP_POINTS; ++i)
        {
            l_biased_pstate[i] = l_operating_points[VPD_PT_SET_BIASED][i].pstate;
            FAPI_INF ("l_biased_pstate %d ", l_biased_pstate[i]);
        }

        if (attr.attr_system_vdm_disable == fapi2::ENUM_ATTR_SYSTEM_VDM_DISABLE_OFF)
        {
            p9_pstate_compute_vdm_threshold_pts(l_poundw_data, &l_localppb);

           // VID slope calculation
           p9_pstate_compute_PsVIDCompSlopes_slopes(l_poundw_data,
                                                    &l_localppb,
                                                    l_biased_pstate);

           // VDM threshold slope calculation
           p9_pstate_compute_PsVDMThreshSlopes(&l_localppb, l_biased_pstate);
           // VDM Jump slope calculation
           p9_pstate_compute_PsVDMJumpSlopes (&l_localppb, l_biased_pstate);


           //Initializing threshold values for GPPB
           memcpy ( l_globalppb.vid_point_set,
                    l_localppb.vid_point_set,
                    sizeof(l_localppb.vid_point_set));

           memcpy ( l_globalppb.threshold_set,
                    l_localppb.threshold_set,
                    sizeof(l_localppb.threshold_set));

           memcpy ( l_globalppb.PsVIDCompSlopes,
                    l_localppb.PsVIDCompSlopes,
                    sizeof(l_localppb.PsVIDCompSlopes));

           memcpy ( l_globalppb.PsVDMThreshSlopes,
                    l_localppb.PsVDMThreshSlopes,
                    sizeof(l_localppb.PsVDMThreshSlopes));

           memcpy ( l_globalppb.PsVDMJumpSlopes,
                    l_localppb.PsVDMJumpSlopes,
                    sizeof(l_localppb.PsVDMJumpSlopes));
        }
        // -----------------------------------------------
        // OCC parameter block
        // -----------------------------------------------
        l_occppb.magic = revle64(OCC_PARMSBLOCK_MAGIC);

        // VPD operating point
        FAPI_TRY(load_mvpd_operating_point(attr_mvpd_voltage_control, l_occppb.operating_points, l_frequency_step_khz),
                 "Loading MVPD operating point failed");

        l_occppb.vdd_sysparm = l_vdd_sysparm;
        l_occppb.vcs_sysparm = l_vcs_sysparm;
        l_occppb.vdn_sysparm = l_vdn_sysparm;

        // frequency_min_khz - Value from Power save operating point after biases
        l_occppb.frequency_min_khz = revle32(attr_mvpd_voltage_control[VPD_PV_POWERSAVE][0] * 1000);

        // frequency_max_khz - Value from Ultra Turbo operating point after biases
        l_occppb.frequency_max_khz = revle32(attr_mvpd_voltage_control[VPD_PV_ULTRA][0] * 1000);

        // frequency_step_khz
        l_occppb.frequency_step_khz = revle32(l_frequency_step_khz);

        //Power bus nest freq
        uint16_t l_pbus_nest_freq = revle16(l_poundv_data.pbFreq);
        FAPI_INF("l_pbus_nest_freq %x", (l_pbus_nest_freq));

        // I- VDN PB current
        uint16_t l_vpd_idn_100ma = revle16(l_poundv_data.IdnPbCurr);
        FAPI_INF("l_vpd_idn_100ma %x", (l_vpd_idn_100ma));

        if (is_wof_enabled(&l_state))
        {
            // Iddq Table
            l_occppb.iddq = l_iddqt;

            l_occppb.wof.tdp_rdp_factor = revle32(attr.attr_tdp_rdp_current_factor);
            FAPI_INF("l_occppb.wof.tdp_rdp_factor %x", revle32(l_occppb.wof.tdp_rdp_factor));

            // nest leakage percent
            l_occppb.nest_leakage_percent = attr.attr_nest_leakage_percent;
            FAPI_INF("l_occppb.nest_leakage_percent %x", l_occppb.nest_leakage_percent);

            l_occppb.lac_tdp_vdd_turbo_10ma =
                    revle16(l_poundw_data.poundw[TURBO].ivdd_tdp_ac_current_10ma);
            l_occppb.lac_tdp_vdd_nominal_10ma =
                    revle16(l_poundw_data.poundw[NOMINAL].ivdd_tdp_ac_current_10ma);
            FAPI_INF("l_occppb.lac_tdp_vdd_turbo_10ma %x", l_occppb.lac_tdp_vdd_turbo_10ma);
            FAPI_INF("l_occppb.lac_tdp_vdd_nominal_10ma %x",l_occppb.lac_tdp_vdd_nominal_10ma);

            //Power bus vdn voltage
            uint16_t l_vpd_vdn_mv = revle16(l_poundv_data.VdnPbVltg);
            FAPI_INF("l_vpd_vdn_mv %x", (l_vpd_vdn_mv));

            uint8_t l_nest_leakage_for_occ = 75;
            uint16_t l_iac_tdp_vdn = get_iac_vdn_value ( l_vpd_vdn_mv,
                                                         l_iddqt,
                                                         l_nest_leakage_for_occ,
                                                         l_vpd_idn_100ma);
            if (!l_iac_tdp_vdn)
            {
                l_state.iv_wof_enabled = false;
            }
            else
            {
                l_occppb.ceff_tdp_vdn =
                    revle16(
                        pstate_calculate_effective_capacitance(l_iac_tdp_vdn,
                                                               l_vpd_vdn_mv * 1000,
                                                               l_pbus_nest_freq)
                     );
            }
            FAPI_INF("l_iac_tdp_vdn %x", l_iac_tdp_vdn);
            FAPI_INF("l_occppb.ceff_tdp_vdn %x", revle16(l_occppb.ceff_tdp_vdn));
        }
        else
        {
            l_state.iv_wof_enabled = false;
        }

        // @todo RTC 161279 - Need Pstate 0 definition and freq2pstate function to be coded

        Pstate pstate_min;
        int rc = freq2pState(&l_globalppb, revle32(l_occppb.frequency_min_khz), &pstate_min);

        switch (rc)
        {
            case -PSTATE_LT_PSTATE_MIN:
                FAPI_INF("OCC Minimum Frequency was clipped to Pstate 0");
                break;

            case -PSTATE_GT_PSTATE_MAX:
                FAPI_INF("OCC Minimum FrequenL1617cy %d KHz is outside the range that can be represented"
                         " by a Pstate with a base frequency of %d KHz and step size %d KHz",
                         revle32(l_occppb.frequency_min_khz),
                         revle32(l_globalppb.reference_frequency_khz),
                         revle32(l_globalppb.frequency_step_khz));
                FAPI_INF("Pstate is set to %X (%d)", pstate_min);
                break;
        }

        l_occppb.pstate_min = pstate_min;


        //Check WOF is enabled or not
        io_size = 0;
        if (is_wof_enabled(&l_state))
        {
            p9_pstate_wof_initialization(&l_globalppb,
                                         o_buf,
                                         io_size,
                                         &l_state,
                                         attr_mvpd_voltage_control[VPD_PV_ULTRA][0]);
        }
        else
        {
            FAPI_INF("WOF is not enabled");
            l_state.iv_wof_enabled = false;
        }

        l_occppb.wof.wof_enabled = l_state.iv_wof_enabled;

        // QuadManagerFlags
        QuadManagerFlags l_qm_flags;
        FAPI_TRY(p9_pstate_set_global_feature_attributes(i_target,
                 l_state,
                 &l_qm_flags));
        l_localppb.qmflags = l_qm_flags;

        // Put out the Parmater Blocks to the trace
        gppb_print(&(l_globalppb));
        oppb_print(&(l_occppb));

        // Populate Global,local and OCC parameter blocks into Pstate super structure
        (*io_pss).globalppb = l_globalppb;
        (*io_pss).localppb = l_localppb;
        (*io_pss).occppb = l_occppb;
    }
    while(0);

fapi_try_exit:
    FAPI_DBG("< p9_pstate_parameter_block");
    return fapi2::current_err;
}
// END OF PSTATE PARAMETER BLOCK function


void
p9_pstate_wof_initialization (const GlobalPstateParmBlock* i_gppb,
                              uint8_t* o_buf,
                              uint32_t& io_size,
                              PSTATE_attribute_state* o_state,
                              const uint32_t i_base_state_frequency)
{

    FAPI_DBG(">> WOF initialization");

    fapi2::ReturnCode l_rc = 0;

    //this structure has VFRT header + data
    HomerVFRTLayout_t l_vfrt;
    memset (&l_vfrt, 0, sizeof(l_vfrt));

    // Use new to avoid over-running the stack
    fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data =
                (fapi2::ATTR_WOF_TABLE_DATA_Type*)new fapi2::ATTR_WOF_TABLE_DATA_Type;

    FAPI_DBG("l_wof_table_data  addr = %p size = %d",
                l_wof_table_data, sizeof(fapi2::ATTR_WOF_TABLE_DATA_Type));

    do
    {
        // If this attribute is set, fill in l_wof_table_data with the VFRT data
        // from the internal, static table.
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_SYS_VFRT_STATIC_DATA_ENABLE_Type l_sys_vfrt_static_data = 0;
        FAPI_ATTR_GET(fapi2::ATTR_SYS_VFRT_STATIC_DATA_ENABLE,
                      FAPI_SYSTEM,
                      l_sys_vfrt_static_data);

        if (l_sys_vfrt_static_data)
        {
            FAPI_DBG("ATTR_SYS_VFRT_STATIC_DATA_ENABLE is SET");

            // Copy WOF header data
            memcpy (l_wof_table_data, g_wofData, sizeof(g_wofData));
            uint32_t l_index = sizeof(g_wofData);

            WofTablesHeader_t* p_wfth;
            p_wfth = reinterpret_cast<WofTablesHeader_t*>(l_wof_table_data);
            FAPI_INF("WFTH: %X", revle32(p_wfth->magic_number));

            memcpy(&l_vfrt, &g_sysvfrtData, sizeof (g_sysvfrtData));

            for (uint32_t vdn = 0; vdn < CEF_VDN_INDEX; ++vdn)
            {
                l_vfrt.vfrtHeader.res_vdnId = vdn;
                for (uint32_t vdd = 0; vdd < CEF_VDD_INDEX; ++vdd)
                {
                    for (uint32_t qid = 0; qid < ACTIVE_QUADS; ++qid)
                    {
                        l_vfrt.vfrtHeader.VddId_QAId = vdd << 4 | qid;
                        FAPI_DBG("  l_vfrt.vfrtHeader res_vdnId = %1X VddId_QAId = 0x%2X",
                                    l_vfrt.vfrtHeader.res_vdnId,
                                    l_vfrt.vfrtHeader.VddId_QAId);

                        memcpy((*l_wof_table_data) + l_index, &l_vfrt, sizeof (l_vfrt));
                        l_index += sizeof (g_sysvfrtData);
                    }
                }
            }
            io_size = l_index;
            FAPI_DBG("  io_size = %d", io_size);
        }
        else
        {
            FAPI_DBG("ATTR_SYS_VFRT_STATIC_DATA_ENABLE is not SET");

            // Read System VFRT data
            l_rc = FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_DATA,
                                 FAPI_SYSTEM,
                                 (*l_wof_table_data));
            if (l_rc)
            {

                FAPI_INF("Pstate Parameter Block ATTR_WOF_TABLE_DATA attribute failed.  Disabling WOF");
                o_state->iv_wof_enabled = false;

                // Write the returned error content to the error log
                fapi2::logError(l_rc,fapi2::FAPI2_ERRL_SEV_RECOVERED);
                break;
            }
        }

        // Copy WOF header data
        memcpy (o_buf, (*l_wof_table_data), sizeof(WofTablesHeader_t));
        uint32_t l_wof_table_index = sizeof(WofTablesHeader_t);
        uint32_t l_index = sizeof(WofTablesHeader_t);

        //Validate WOF header part
        WofTablesHeader_t* p_wfth;
        p_wfth = reinterpret_cast<WofTablesHeader_t*>(o_buf);
        FAPI_INF("WFTH: %X", revle32(p_wfth->magic_number));

        bool l_wof_header_data_state = 1;
        VALIDATE_WOF_HEADER_DATA(p_wfth->magic_number,
                                 p_wfth->reserved_version,
                                 p_wfth->vfrt_block_size,
                                 p_wfth->vfrt_block_header_size,
                                 p_wfth->vfrt_data_size,
                                 p_wfth->quads_active_size,
                                 p_wfth->core_count,
                                 l_wof_header_data_state);

        if (!l_wof_header_data_state)
        {
            o_state->iv_wof_enabled = false;
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_WOF_HEADER_DATA_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(FAPI_SYSTEM)
                               .set_MAGIC_NUMBER(p_wfth->magic_number)
                               .set_VERSION(p_wfth->reserved_version)
                               .set_VFRT_BLOCK_SIZE(p_wfth->vfrt_block_size)
                               .set_VFRT_HEADER_SIZE(p_wfth->vfrt_block_header_size)
                               .set_VFRT_DATA_SIZE(p_wfth->vfrt_data_size)
                               .set_QUADS_ACTIVE_SIZE(p_wfth->quads_active_size)
                               .set_CORE_COUNT(p_wfth->core_count),
                               "Pstate Parameter Block WOF Header validation failed");
            break;

        }

        // Convert system vfrt to homer vfrt
        for (uint32_t vfrt_index = 0;
             vfrt_index < (CEF_VDN_INDEX * CEF_VDD_INDEX * ACTIVE_QUADS);
             ++vfrt_index)
        {

            p9_pstate_update_vfrt (i_gppb,
                                   ((*l_wof_table_data) + l_wof_table_index),
                                   &l_vfrt,
                                   i_base_state_frequency);

            FAPI_INF("VFRT: %X", l_vfrt.vfrtHeader.magic_number);
            // Check for "VT" at the start of the magic number
            if (revle16(l_vfrt.vfrtHeader.magic_number) != 0x5654)
            {
                o_state->iv_wof_enabled = false;
                FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_VFRT_HEADER_DATA_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(FAPI_SYSTEM)
                               .set_MAGIC_NUMBER(l_vfrt.vfrtHeader.magic_number)
                               .set_VFRT_INDEX(vfrt_index),
                               "Pstate Parameter Block: Invalid VFRT Magic word");
                break;
            }
            l_wof_table_index += 128; //System vFRT size is 128B..hence need to jump after each VFRT entry

            memcpy(o_buf + l_index, &l_vfrt, sizeof (l_vfrt));
            l_index += sizeof (l_vfrt);
        }

        io_size = l_index;

    } while(0);

    delete l_wof_table_data;

    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    FAPI_DBG("<< WOF initialization");
    return;

}
// START OF GET ATTRIBUTES functionfapi2/include/fapi2_error_scope.H

fapi2::ReturnCode
proc_get_attributes ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      AttributeList* io_attr)
{
    const uint32_t EXT_VRM_TRANSITION_START_NS = 8000;
    const uint32_t EXT_VRM_TRANSITION_RATE_INC_UV_PER_US = 10000;
    const uint32_t EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US = 10000;
    const uint32_t EXT_VRM_STABILIZATION_TIME_NS = 5;
    const uint32_t EXT_VRM_STEPSIZE_MV = 50;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // --------------------------
    // attributes not yet defined
    // --------------------------
    io_attr->attr_dpll_bias                 = 0;
    io_attr->attr_undervolting              = 0;
    // ---------------------------------------------------------------
    // set ATTR_PROC_DPLL_DIVIDER
    // ---------------------------------------------------------------

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_DPLL_DIVIDER, i_target,
                           io_attr->attr_proc_dpll_divider), "fapiGetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
    FAPI_DBG("ATTR_PROC_DPLL_DIVIDER - get to %x", io_attr->attr_proc_dpll_divider);

    // If value is 0, set a default
    if (!io_attr->attr_proc_dpll_divider)
    {
        FAPI_DBG("ATTR_PROC_DPLL_DIVIDER - settfapi2/include/fapi2_error_scope.Hing default to %x", io_attr->attr_proc_dpll_divider);
        io_attr->attr_proc_dpll_divider = 8;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_DPLL_DIVIDER, i_target,
                               io_attr->attr_proc_dpll_divider), "fapiSetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
    }

    FAPI_INF("ATTR_PROC_DPLL_DIVIDER - %x", io_attr->attr_proc_dpll_divider);

    // ----------------------------
    // attributes currently defined
    // ----------------------------
#define DATABLOCK_GET_ATTR(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, io_attr->attr_assign),"Attribute read failed"); \
FAPI_INF("%-60s = 0x%08x %d", #attr_name, io_attr->attr_assign, io_attr->attr_assign);

    // Frequency Bias attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_ULTRATURBO, i_target, attr_freq_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_TURBO, i_target, attr_freq_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_NOMINAL, i_target, attr_freq_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_POWERSAVE, i_target, attr_freq_bias_powersave);

    // Voltage Bias attributes
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_ULTRATURBO, i_target, attr_voltage_ext_vdd_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_TURBO, i_target, attr_voltage_ext_vdd_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_NOMINAL, i_target, attr_voltage_ext_vdd_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_POWERSAVE, i_target, attr_voltage_ext_vdd_bias_powersave);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VCS_BIAS, i_target, attr_voltage_ext_vcs_bias);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDN_BIAS, i_target, attr_voltage_ext_vdn_bias);

    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_ULTRATURBO, i_target, attr_voltage_int_vdd_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_TURBO, i_target, attr_voltage_int_vdd_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_NOMINAL, i_target, attr_voltage_int_vdd_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_POWERSAVE, i_target, attr_voltage_int_vdd_bias_powersave);

    // Frequency attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_PROC_REFCLOCK_KHZ, FAPI_SYSTEM, attr_freq_proc_refclock_khz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_PB_MHZ, FAPI_SYSTEM, attr_nest_frequency_mhz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_CEILING_MHZ, FAPI_SYSTEM, attr_freq_core_ceiling_mhz);
    DATABLOCK_GET_ATTR(ATTR_SAFE_MODE_FREQUENCY_MHZ, i_target, attr_pm_safe_frequency_mhz);
    DATABLOCK_GET_ATTR(ATTR_SAFE_MODE_VOLTAGE_MV, i_target, attr_pm_safe_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_FLOOR_MHZ, FAPI_SYSTEM, attr_freq_core_floor_mhz);

    // Loadline, Distribution loss and Distribution offset attributes
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDD_UOHM, i_target, attr_proc_r_loadline_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDD_UOHM, i_target, attr_proc_r_distloss_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDD_UV, i_target, attr_proc_vrm_voffset_vdd_uv);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDN_UOHM, i_target, attr_proc_r_loadline_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDN_UOHM, i_target, attr_proc_r_distloss_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDN_UV, i_target, attr_proc_vrm_voffset_vdn_uv);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VCS_UOHM, i_target, attr_proc_r_loadline_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VCS_UOHM, i_target, attr_proc_r_distloss_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VCS_UV, i_target, attr_proc_vrm_voffset_vcs_uv);

    // Read IVRM,WOF and DPLL attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_IVRM_DISABLE, FAPI_SYSTEM, attr_system_ivrm_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOF_DISABLE, FAPI_SYSTEM, attr_system_wof_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_VDM_DISABLE, FAPI_SYSTEM, attr_system_vdm_disable);
    DATABLOCK_GET_ATTR(ATTR_DPLL_VDM_RESPONSE, FAPI_SYSTEM, attr_dpll_vdm_response);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_RESCLK_DISABLE, FAPI_SYSTEM, attr_resclk_disable);
    DATABLOCK_GET_ATTR(ATTR_CHIP_EC_FEATURE_WOF_NOT_SUPPORTED, i_target, attr_dd_wof_not_supported);
    DATABLOCK_GET_ATTR(ATTR_CHIP_EC_FEATURE_VDM_NOT_SUPPORTED, i_target, attr_dd_vdm_not_supported);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_PSTATES_MODE, FAPI_SYSTEM, attr_pstate_mode);

    DATABLOCK_GET_ATTR(ATTR_TDP_RDP_CURRENT_FACTOR, i_target, attr_tdp_rdp_current_factor);


    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_START_NS, FAPI_SYSTEM,
                       attr_ext_vrm_transition_start_ns);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_RATE_INC_UV_PER_US, FAPI_SYSTEM,
                       attr_ext_vrm_transition_rate_inc_uv_per_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_RATE_DEC_UV_PER_US, FAPI_SYSTEM,
                       attr_ext_vrm_transition_rate_dec_uv_per_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_STABILIZATION_TIME_NS, FAPI_SYSTEM,
                       attr_ext_vrm_stabilization_time_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_STEPSIZE, FAPI_SYSTEM, attr_ext_vrm_step_size_mv);

    DATABLOCK_GET_ATTR(ATTR_NEST_LEAKAGE_PERCENT, FAPI_SYSTEM, attr_nest_leakage_percent);

    io_attr->attr_ext_vrm_transition_start_ns =
        (io_attr->attr_ext_vrm_transition_start_ns) ? io_attr->attr_ext_vrm_transition_start_ns : EXT_VRM_TRANSITION_START_NS;

    io_attr->attr_ext_vrm_transition_rate_inc_uv_per_us =
        (io_attr->attr_ext_vrm_transition_rate_inc_uv_per_us) ? io_attr->attr_ext_vrm_transition_rate_inc_uv_per_us :
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US;  // 10mV/us

    io_attr->attr_ext_vrm_transition_rate_dec_uv_per_us =
        (io_attr->attr_ext_vrm_transition_rate_dec_uv_per_us) ? io_attr->attr_ext_vrm_transition_rate_dec_uv_per_us :
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US;  // 10mV/us

    io_attr->attr_ext_vrm_stabilization_time_us =
        (io_attr->attr_ext_vrm_stabilization_time_us) ? io_attr->attr_ext_vrm_stabilization_time_us :
        EXT_VRM_STABILIZATION_TIME_NS;

    io_attr->attr_ext_vrm_step_size_mv = (io_attr->attr_ext_vrm_step_size_mv) ? io_attr->attr_ext_vrm_step_size_mv :
                                         EXT_VRM_STEPSIZE_MV;

fapi_try_exit:
    return fapi2::current_err;

}
///  END OF GET ATTRIBUTES function

///  START OF MVPD DATA FUNCTION

fapi2::ReturnCode
proc_get_mvpd_data(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                   uint32_t       o_attr_mvpd_data[PV_D][PV_W],
                   uint32_t*      o_valid_pdv_points,
                   uint8_t*       o_present_chiplets,
                   uint8_t&       o_bucketId,
                   fapi2::voltageBucketData_t* o_poundv_data,
                   PSTATE_attribute_state* o_state)
{

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
    fapi2::voltageBucketData_t l_poundv_data;
    fapi2::Target<fapi2::TARGET_TYPE_EQ> l_firstEqChiplet;
    uint8_t*   l_buffer         =  reinterpret_cast<uint8_t*>(malloc(sizeof(l_poundv_data)) );
    uint8_t*   l_buffer_inc;
    uint32_t   chiplet_mvpd_data[PV_D][PV_W];
    uint8_t    j                = 0;
    uint8_t    i                = 0;
    uint8_t    ii               = 0;
    uint8_t    first_chplt      = 1;
    uint8_t    bucket_id        = 0;

    do
    {
        // initialize
        FAPI_TRY(proc_get_attributes(i_target, &attr), "proc_get_mvpd_data: Get attributes function failed");
        *o_present_chiplets    = 0;

        // -----------------------------------------------------------------
        // get list of quad chiplets and loop over each and get #V data from each
        // -----------------------------------------------------------------
        // check that frequency is the same per chiplet
        // for voltage, get the max for use for the chip

        l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);


        *o_present_chiplets = l_eqChiplets.size();
        FAPI_INF("Number of EQ chiplets present => %u", *o_present_chiplets);

        for (j = 0; j < l_eqChiplets.size(); j++)
        {

            uint8_t l_chipNum = 0xFF;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_eqChiplets[j], l_chipNum));

            FAPI_INF("Chip Number => %u", l_chipNum);

            // clear out buffer to known value before calling fapiGetMvpdField
            memset(l_buffer, 0, sizeof(o_poundv_data));

            FAPI_TRY(p9_pm_get_poundv_bucket(l_eqChiplets[j], l_poundv_data));

            memcpy(l_buffer, &l_poundv_data, sizeof(l_poundv_data));
            memcpy(o_poundv_data, &l_poundv_data, sizeof(l_poundv_data));

            // clear array
            memset(chiplet_mvpd_data, 0, sizeof(chiplet_mvpd_data));

            // fill chiplet_mvpd_data 2d array with data iN buffer (skip first byte - bucket id)
#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))

            l_buffer_inc = l_buffer;

            bucket_id = *l_buffer_inc;
            l_buffer_inc++;

            FAPI_INF("#V chiplet = %u bucket id = %u", l_chipNum, bucket_id);

            for (i = 0; i <= 4; i++)
            {

                for (ii = 0; ii <= 4; ii++)
                {
                    chiplet_mvpd_data[i][ii] = (uint32_t) UINT16_GET(l_buffer_inc);
                    FAPI_INF("#V data = 0x%04X  %-6d", chiplet_mvpd_data[i][ii],
                             chiplet_mvpd_data[i][ii]);
                    // increment to next MVPD value in buffer
                    l_buffer_inc += 2;
                }
            }

            FAPI_TRY(proc_chk_valid_poundv( i_target,
                                            chiplet_mvpd_data,
                                            o_valid_pdv_points,
                                            l_chipNum,
                                            bucket_id,
                                            o_state));

            // on first chiplet put each bucket's data into attr_mvpd_voltage_control
            if (first_chplt)
            {
                l_firstEqChiplet = l_eqChiplets[j];
                o_bucketId = bucket_id;

                for (i = 0; i <= 4; i++)
                {
                    for (ii = 0; ii <= 4; ii++)
                    {
                        o_attr_mvpd_data[i][ii] = chiplet_mvpd_data[i][ii];
                    }
                }

                first_chplt = 0;
            }
            else
            {
                // on subsequent chiplets, check that frequencies are same for each operating point for each chiplet
                if ( (o_attr_mvpd_data[0][0] != chiplet_mvpd_data[0][0]) ||
                     (o_attr_mvpd_data[1][0] != chiplet_mvpd_data[1][0]) ||
                     (o_attr_mvpd_data[2][0] != chiplet_mvpd_data[2][0]) ||
                     (o_attr_mvpd_data[3][0] != chiplet_mvpd_data[3][0]) ||
                     (o_attr_mvpd_data[4][0] != chiplet_mvpd_data[4][0]) )
                {
                    o_state->iv_pstates_enabled = false;
                    // Error out has Pstate and all dependent functions are suspious.
                    FAPI_ASSERT(false,
                                fapi2::PSTATE_MVPD_CHIPLET_VOLTAGE_NOT_EQUAL()
                                .set_CHIP_TARGET(i_target)
                                .set_CURRENT_EQ_CHIPLET_TARGET(l_eqChiplets[j])
                                .set_FIRST_EQ_CHIPLET_TARGET(l_firstEqChiplet)
                                .set_BUCKET(bucket_id),
                                "frequencies are not the same for each operating point for each chiplet");

                }
            }

            // check each bucket for max voltage and if max, put bucket's data into attr_mvpd_voltage_control
            for (i = 0; i <= 4; i++)
            {
                if (o_attr_mvpd_data[i][1] < chiplet_mvpd_data[i][1])
                {
                    o_attr_mvpd_data[i][0] = chiplet_mvpd_data[i][0];
                    o_attr_mvpd_data[i][1] = chiplet_mvpd_data[i][1];
                    o_attr_mvpd_data[i][2] = chiplet_mvpd_data[i][2];
                    o_attr_mvpd_data[i][3] = chiplet_mvpd_data[i][3];
                    o_attr_mvpd_data[i][4] = chiplet_mvpd_data[i][4];
                    o_bucketId = bucket_id;
                }
            }
        } // end for loop
    }
    while(0);


fapi_try_exit:

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        o_state->iv_pstates_enabled = false;
    }
    free (l_buffer);

    return fapi2::current_err;

} // end proc_get_mvpd_data
///  END OF MVPD DATA FUNCTION

///  START OF IDDQ READ FUNCTION

fapi2::ReturnCode
proc_get_mvpd_iddq( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                    IddqTable* io_iddqt,
                    PSTATE_attribute_state* o_state)
{

    uint8_t*        l_buffer_iq_c =  reinterpret_cast<uint8_t*>(malloc(IQ_BUFFER_ALLOC));
    uint32_t        l_record = 0;
    uint32_t        l_bufferSize_iq  = IQ_BUFFER_ALLOC;


    // --------------------------------------------
    // Process IQ Keyword (IDDQ) Data
    // --------------------------------------------

    // clear out buffer to known value before calling fapiGetMvpdField
    memset(l_buffer_iq_c, 0, IQ_BUFFER_ALLOC);

    // set l_record to appropriate cprx record
    l_record = (uint32_t)fapi2::MVPD_RECORD_CRP0;
    l_bufferSize_iq = IQ_BUFFER_ALLOC;

    //First read is to get size of vpd record, note the o_buffer is NULL
    FAPI_TRY( getMvpdField((fapi2::MvpdRecord)l_record,
                           fapi2::MVPD_KEYWORD_IQ,
                           i_target,
                           NULL,
                           l_bufferSize_iq) );

    //Allocate memory for vpd data
    l_buffer_iq_c = reinterpret_cast<uint8_t*>(malloc(l_bufferSize_iq));

    // Get Chip IQ MVPD data from the CRPx records
    FAPI_TRY(getMvpdField((fapi2::MvpdRecord)l_record,
                          fapi2::MVPD_KEYWORD_IQ,
                          i_target,
                          l_buffer_iq_c,
                          l_bufferSize_iq));

    //copy VPD data to IQ structure table
    memcpy(io_iddqt, l_buffer_iq_c, l_bufferSize_iq);

    //Verify Payload header data.
    if ( !(io_iddqt->iddq_version) ||
         !(io_iddqt->good_quads_per_sort) ||
         !(io_iddqt->good_normal_cores_per_sort) ||
         !(io_iddqt->good_caches_per_sort))
    {
        o_state->iv_wof_enabled = false;
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::PSTATE_PB_IQ_VPD_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_CHIP_TARGET(i_target)
                           .set_VERSION(io_iddqt->iddq_version)
                           .set_GOOD_QUADS_PER_SORT(io_iddqt->good_quads_per_sort)
                           .set_GOOD_NORMAL_CORES_PER_SORT(io_iddqt->good_normal_cores_per_sort)
                           .set_GOOD_CACHES_PER_SORT(io_iddqt->good_caches_per_sort),
                           "Pstate Parameter Block IQ Payload data error being logged");
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    // Put out the structure to the trace
    iddq_print(io_iddqt);

fapi_try_exit:

    // Free up memory buffer
    free(l_buffer_iq_c);

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        o_state->iv_wof_enabled = false;
    }

    return fapi2::current_err;
} // proc_get_mvdp_iddq

/// END OF IDDQ READ FUNCTION

/// START OF BIAS APPLICATION FUNCTION

// Bias multiplier helper function
// NOTE: BIAS_PCT_UNIT is a multipler on the percentage that the value represents
double
calc_bias(const int8_t i_value)
{
    double temp = 1.0 + ((BIAS_PCT_UNIT/100) * (double)i_value);
    FAPI_DBG("    calc_bias: input bias (in 1/2 percent) = %d; biased multiplier = %f",
                i_value, temp);
    return temp;
}



fapi2::ReturnCode
proc_get_extint_bias( uint32_t io_attr_mvpd_data[PV_D][PV_W],
                      const AttributeList* i_attr,
                      VpdBias o_vpdbias[NUM_OP_POINTS]
                    )
{
    double freq_bias[NUM_OP_POINTS];
    double voltage_ext_vdd_bias[NUM_OP_POINTS];
    double voltage_ext_vcs_bias;
    double voltage_ext_vdn_bias;

    // Calculate the frequency multiplers and load the biases into the exported
    // structure
    for (auto p = 0; p < NUM_OP_POINTS; p++)
    {
        switch (p)
        {
            case POWERSAVE:
               o_vpdbias[p].frequency_hp    = i_attr->attr_freq_bias_powersave;
               o_vpdbias[p].vdd_ext_hp      = i_attr->attr_voltage_ext_vdd_bias_powersave;
               o_vpdbias[p].vdd_int_hp      = i_attr->attr_voltage_int_vdd_bias_powersave;

               break;
            case NOMINAL:
               o_vpdbias[p].frequency_hp    = i_attr->attr_freq_bias_nominal;
               o_vpdbias[p].vdd_ext_hp      = i_attr->attr_voltage_ext_vdd_bias_nominal;
               o_vpdbias[p].vdd_int_hp      = i_attr->attr_voltage_int_vdd_bias_nominal;
               break;
            case TURBO:
               o_vpdbias[p].frequency_hp    = i_attr->attr_freq_bias_turbo;
               o_vpdbias[p].vdd_ext_hp      = i_attr->attr_voltage_ext_vdd_bias_turbo;
               o_vpdbias[p].vdd_int_hp      = i_attr->attr_voltage_int_vdd_bias_turbo;
               break;
            case ULTRA:
               o_vpdbias[p].frequency_hp    = i_attr->attr_freq_bias_ultraturbo;
               o_vpdbias[p].vdd_ext_hp      = i_attr->attr_voltage_ext_vdd_bias_ultraturbo;
               o_vpdbias[p].vdd_int_hp      = i_attr->attr_voltage_int_vdd_bias_ultraturbo;
        }

        o_vpdbias[p].vdn_ext_hp      = i_attr->attr_voltage_ext_vdn_bias;
        o_vpdbias[p].vcs_ext_hp      = i_attr->attr_voltage_ext_vcs_bias;

        freq_bias[p]                 = calc_bias(o_vpdbias[p].frequency_hp);
        voltage_ext_vdd_bias[p]      = calc_bias(o_vpdbias[p].vdd_ext_hp);

        FAPI_DBG("    Biases[%d](bias): Freq=%f (%f%%); VDD=%f (%f%%)",
                    p,
                    freq_bias[p],            o_vpdbias[p].frequency_hp/2,
                    voltage_ext_vdd_bias[p], o_vpdbias[p].vdd_ext_hp/2);
    }

    // VCS bias applied to all operating points
    voltage_ext_vcs_bias = calc_bias(i_attr->attr_voltage_ext_vcs_bias);

    // VDN bias applied to all operating points
    voltage_ext_vdn_bias = calc_bias(i_attr->attr_voltage_ext_vdn_bias);

    // Change the VPD frequency, VDD and VCS values with the bias multiplers
    for (auto p = 0; p < NUM_OP_POINTS; p++)
    {
        FAPI_DBG("    Orig values[%d](bias): Freq=%d (%f); VDD=%d (%f), VCS=%d (%f)",
                    p,
                    io_attr_mvpd_data[p][VPD_PV_CORE_FREQ_MHZ], freq_bias[p],
                    io_attr_mvpd_data[p][VPD_PV_VDD_MV], voltage_ext_vdd_bias[p],
                    io_attr_mvpd_data[p][VPD_PV_VCS_MV], voltage_ext_vcs_bias);

        double freq_mhz =
            (( (double)io_attr_mvpd_data[p][VPD_PV_CORE_FREQ_MHZ]) * freq_bias[p]);
        double vdd_mv =
            (( (double)io_attr_mvpd_data[p][VPD_PV_VDD_MV]) * voltage_ext_vdd_bias[p]);
        double vcs_mv =
            (( (double)io_attr_mvpd_data[p][VPD_PV_VCS_MV]) * voltage_ext_vcs_bias);

        io_attr_mvpd_data[p][VPD_PV_CORE_FREQ_MHZ] = (uint32_t)internal_floor(freq_mhz);
        io_attr_mvpd_data[p][VPD_PV_VDD_MV] = (uint32_t)internal_ceil(vdd_mv);
        io_attr_mvpd_data[p][VPD_PV_VCS_MV] = (uint32_t)(vcs_mv);

        FAPI_DBG("    Biased values[%d]: Freq=%f %d; VDD=%f %d, VCS=%f %d ",
                    p,
                    freq_mhz, io_attr_mvpd_data[p][VPD_PV_CORE_FREQ_MHZ],
                    vdd_mv, io_attr_mvpd_data[p][VPD_PV_VDD_MV],
                    vcs_mv, io_attr_mvpd_data[p][VPD_PV_VCS_MV]);
    }

    // Power bus operating point
    double vdn_mv =
           (( (double)io_attr_mvpd_data[VPD_PV_POWERBUS][VPD_PV_VDN_MV]) * voltage_ext_vdn_bias);
    io_attr_mvpd_data[VPD_PV_POWERBUS][VPD_PV_VDN_MV] = (uint32_t)internal_ceil(vdn_mv);

    return fapi2::FAPI2_RC_SUCCESS;

} // end proc_get_extint_bias

/// END OF BIAS APPLICATION FUNCTION




fapi2::ReturnCode
proc_chk_valid_poundv(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      const uint32_t i_chiplet_mvpd_data[PV_D][PV_W],
                      uint32_t*      o_valid_pdv_points,
                      const uint8_t  i_chiplet_num,
                      const uint8_t  i_bucket_id,
                      PSTATE_attribute_state* o_state,
                      const bool i_biased_state)
{
    const uint8_t pv_op_order[NUM_OP_POINTS] = VPD_PV_ORDER;
    const char*     pv_op_str[NUM_OP_POINTS] = VPD_PV_ORDER_STR;
    uint8_t         i = 0;
    bool            suspend_ut_check = false;

    FAPI_DBG(">> proc_chk_valid_poundv for %s values", (i_biased_state) ? "biased" : "non-biased" );

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SYSTEM_POUNDV_VALIDITY_HALT_DISABLE_Type  attr_poundv_validity_halt_disable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_POUNDV_VALIDITY_HALT_DISABLE,
                           FAPI_SYSTEM,
                           attr_poundv_validity_halt_disable));

    fapi2::ATTR_CHIP_EC_FEATURE_POUNDV_VALIDATE_DISABLE_Type  attr_poundv_validate_ec_disable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_POUNDV_VALIDATE_DISABLE,
                           i_target,
                           attr_poundv_validate_ec_disable));

    if (attr_poundv_validate_ec_disable)
    {
         o_state->iv_pstates_enabled = false;
         FAPI_INF("**** WARNING : #V zero value checking is not being performed on this chip EC level");
         FAPI_INF("**** WARNING : Pstates are not enabled");
    }
    else
    {
        // check for non-zero freq, voltage, or current in valid operating points
        for (i = 0; i <= NUM_OP_POINTS - 1; i++)
        {
            FAPI_INF("Checking for Zero valued %s data in each #V operating point (%s) f=%u v=%u i=%u v=%u i=%u",
                 (i_biased_state) ? "biased" : "non-biased",
                 pv_op_str[pv_op_order[i]],
                 i_chiplet_mvpd_data[pv_op_order[i]][0],
                 i_chiplet_mvpd_data[pv_op_order[i]][1],
                 i_chiplet_mvpd_data[pv_op_order[i]][2],
                 i_chiplet_mvpd_data[pv_op_order[i]][3],
                 i_chiplet_mvpd_data[pv_op_order[i]][4]);

            if (is_wof_enabled(o_state) && (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))
            {
                if (i_chiplet_mvpd_data[pv_op_order[i]][0] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][1] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][2] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][3] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][4] == 0   )
                {
                    FAPI_INF("**** WARNING: WOF is enabled but zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                             i_chiplet_num, i_bucket_id, pv_op_str[pv_op_order[i]]);
                    FAPI_INF("**** WARNING: Disabling WOF and continuing");
                    suspend_ut_check = true;

                    // Set ATTR_WOF_ENABLED so the caller can set header flags
                    o_state->iv_wof_enabled = false;

                    // Take out an informational error log and then keep going.
                    if (i_biased_state)
                    {
                        FAPI_ASSERT_NOEXIT(false,
                            fapi2::PSTATE_PB_BIASED_POUNDV_WOF_UT_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                            .set_CHIP_TARGET(i_target)
                            .set_CHIPLET_NUMBER(i_chiplet_num)
                            .set_BUCKET(i_bucket_id)
                            .set_FREQUENCY(i_chiplet_mvpd_data[pv_op_order[i]][0])
                            .set_VDD(i_chiplet_mvpd_data[pv_op_order[i]][1])
                            .set_IDD(i_chiplet_mvpd_data[pv_op_order[i]][2])
                            .set_VCS(i_chiplet_mvpd_data[pv_op_order[i]][3])
                            .set_ICS(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                            "Pstate Parameter Block WOF Biased #V UT error being logged");
                    }
                    else
                    {
                        FAPI_ASSERT_NOEXIT(false,
                            fapi2::PSTATE_PB_POUNDV_WOF_UT_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                            .set_CHIP_TARGET(i_target)
                            .set_CHIPLET_NUMBER(i_chiplet_num)
                            .set_BUCKET(i_bucket_id)
                            .set_FREQUENCY(i_chiplet_mvpd_data[pv_op_order[i]][0])
                            .set_VDD(i_chiplet_mvpd_data[pv_op_order[i]][1])
                            .set_IDD(i_chiplet_mvpd_data[pv_op_order[i]][2])
                            .set_VCS(i_chiplet_mvpd_data[pv_op_order[i]][3])
                            .set_ICS(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                            "Pstate Parameter Block WOF #V UT error being logged");
                    }
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }
            }
            else if ((!is_wof_enabled(o_state)) && (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))
            {
                FAPI_INF("**** NOTE: WOF is disabled so the UltraTurbo VPD is not being checked");
                suspend_ut_check = true;
            }
            else
            {
                if (i_chiplet_mvpd_data[pv_op_order[i]][0] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][1] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][2] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][3] == 0 ||
                    i_chiplet_mvpd_data[pv_op_order[i]][4] == 0   )
                {

                    o_state->iv_pstates_enabled = false;

                    if (attr_poundv_validity_halt_disable)
                    {
                        FAPI_IMP("**** WARNING : halt on #V validity checking has been disabled and errors were found");
                        FAPI_IMP("**** WARNING : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                                 i_chiplet_num, i_bucket_id, pv_op_str[pv_op_order[i]]);
                        FAPI_IMP("**** WARNING : Pstates are not enabled but continuing on.");

                        // Log errors based on biased inputs or not
                        if (i_biased_state)
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(i_target)
                                .set_CHIPLET_NUMBER(i_chiplet_num)
                                .set_BUCKET(i_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY(i_chiplet_mvpd_data[pv_op_order[i]][0])
                                .set_VDD(i_chiplet_mvpd_data[pv_op_order[i]][1])
                                .set_IDD(i_chiplet_mvpd_data[pv_op_order[i]][2])
                                .set_VCS(i_chiplet_mvpd_data[pv_op_order[i]][3])
                                .set_ICS(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                                "Pstate Parameter Block Biased #V Zero contents error being logged");
                        }
                        else
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(i_target)
                                .set_CHIPLET_NUMBER(i_chiplet_num)
                                .set_BUCKET(i_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY(i_chiplet_mvpd_data[pv_op_order[i]][0])
                                .set_VDD(i_chiplet_mvpd_data[pv_op_order[i]][1])
                                .set_IDD(i_chiplet_mvpd_data[pv_op_order[i]][2])
                                .set_VCS(i_chiplet_mvpd_data[pv_op_order[i]][3])
                                .set_ICS(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                                "Pstate Parameter Block #V Zero contents error being logged");
                        }
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    }
                    else
                    {
                        FAPI_ERR("**** ERROR : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                             i_chiplet_num, i_bucket_id, pv_op_str[pv_op_order[i]]);

                        // Error out has Pstate and all dependent functions are suspious.
                        if (i_biased_state)
                        {
                            FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR()
                                .set_CHIP_TARGET(i_target)
                                .set_CHIPLET_NUMBER(i_chiplet_num)
                                .set_BUCKET(i_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY(i_chiplet_mvpd_data[pv_op_order[i]][0])
                                .set_VDD(i_chiplet_mvpd_data[pv_op_order[i]][1])
                                .set_IDD(i_chiplet_mvpd_data[pv_op_order[i]][2])
                                .set_VCS(i_chiplet_mvpd_data[pv_op_order[i]][3])
                                .set_ICS(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                                "Pstate Parameter Block Biased #V Zero contents error being logged");
                        }
                        else
                        {
                            FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_POUNDV_ZERO_ERROR()
                                .set_CHIP_TARGET(i_target)
                                .set_CHIPLET_NUMBER(i_chiplet_num)
                                .set_BUCKET(i_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY(i_chiplet_mvpd_data[pv_op_order[i]][0])
                                .set_VDD(i_chiplet_mvpd_data[pv_op_order[i]][1])
                                .set_IDD(i_chiplet_mvpd_data[pv_op_order[i]][2])
                                .set_VCS(i_chiplet_mvpd_data[pv_op_order[i]][3])
                                .set_ICS(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                                "Pstate Parameter Block #V Zero contents error being logged");
                        }
                    }  // Halt disable
                }  // #V point zero check
            }  // WOF and UT conditions
        } // Operating poing loop
    } // validate #V EC

    // Adjust the valid operating point based on UltraTurbo presence
    // and WOF enablement
    *o_valid_pdv_points = NUM_OP_POINTS;

    if (suspend_ut_check)
    {
        (*o_valid_pdv_points)--;
    }

    FAPI_DBG("o_valid_pdv_points = %d", *o_valid_pdv_points);

#define POUNDV_SLOPE_CHECK(x,y)   x > y ? " is GREATER (ERROR!) than " : " is less than "

    if (attr_poundv_validate_ec_disable)
    {
        o_state->iv_pstates_enabled = false;
        FAPI_INF("**** WARNING : #V relationship checking is not being performed on this chip EC level");
        FAPI_INF("**** WARNING : Pstates are not enabled");
    }
    else
    {
        // check valid operating points' values have this relationship (power save <= nominal <= turbo <= ultraturbo)
        for (i = 1; i <= (*o_valid_pdv_points) - 1; i++)
        {
            FAPI_INF("Checking for relationship between #V operating point (%s <= %s)",
                     pv_op_str[pv_op_order[i - 1]], pv_op_str[pv_op_order[i]]);

            // Only skip checkinug for WOF not enabled and UltraTurbo.
            if ( is_wof_enabled(o_state) ||
                (!( !is_wof_enabled(o_state) && (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0)))
               )
            {
                if (i_chiplet_mvpd_data[pv_op_order[i - 1]][0] > i_chiplet_mvpd_data[pv_op_order[i]][0]  ||
                    i_chiplet_mvpd_data[pv_op_order[i - 1]][1] > i_chiplet_mvpd_data[pv_op_order[i]][1]  ||
                    i_chiplet_mvpd_data[pv_op_order[i - 1]][2] > i_chiplet_mvpd_data[pv_op_order[i]][2]  ||
                    i_chiplet_mvpd_data[pv_op_order[i - 1]][3] > i_chiplet_mvpd_data[pv_op_order[i]][3]  ||
                    i_chiplet_mvpd_data[pv_op_order[i - 1]][4] > i_chiplet_mvpd_data[pv_op_order[i]][4]    )
                {

                    o_state->iv_pstates_enabled = false;

                    if (attr_poundv_validity_halt_disable)
                    {
                        FAPI_IMP("**** WARNING : halt on #V validity checking has been disabled and relationship errors were found");
                        FAPI_IMP("**** WARNING : Relationship error between #V operating point (%s > %s)(power save <= nominal <= turbo <= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                            pv_op_str[pv_op_order[i - 1]], pv_op_str[pv_op_order[i]], i_chiplet_num, i_bucket_id,
                            pv_op_order[i]);
                        FAPI_IMP("**** WARNING : Pstates are not enabled but continuing on.");
                    }
                    else
                    {
                        FAPI_ERR("**** ERROR : Relation../../xml/attribute_info/pm_plat_attributes.xmlship error between #V operating point (%s > %s)(power save <= nominal <= turbo <= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                                 pv_op_str[pv_op_order[i - 1]], pv_op_str[pv_op_order[i]], i_chiplet_num, i_bucket_id,
                                 pv_op_order[i]);
                    }

                    FAPI_INF("%s Frequency value %u is %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], i_chiplet_mvpd_data[pv_op_order[i - 1]][0],
                           POUNDV_SLOPE_CHECK(i_chiplet_mvpd_data[pv_op_order[i - 1]][0], i_chiplet_mvpd_data[pv_op_order[i]][0]),
                           pv_op_str[pv_op_order[i]], i_chiplet_mvpd_data[pv_op_order[i]][0]);

                    FAPI_INF("%s VDD voltage value %u is %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], i_chiplet_mvpd_data[pv_op_order[i - 1]][1],
                           POUNDV_SLOPE_CHECK(i_chiplet_mvpd_data[pv_op_order[i - 1]][1], i_chiplet_mvpd_data[pv_op_order[i]][1]),
                           pv_op_str[pv_op_order[i]], i_chiplet_mvpd_data[pv_op_order[i]][1]);

                    FAPI_INF("%s VDD current value %u is %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], i_chiplet_mvpd_data[pv_op_order[i - 1]][2],
                           POUNDV_SLOPE_CHECK(i_chiplet_mvpd_data[pv_op_order[i - 1]][2], i_chiplet_mvpd_data[pv_op_order[i]][2]),
                           pv_op_str[pv_op_order[i]], i_chiplet_mvpd_data[pv_op_order[i]][2]);

                    FAPI_INF("%s VCS voltage value %u is %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], i_chiplet_mvpd_data[pv_op_order[i - 1]][3],
                           POUNDV_SLOPE_CHECK(i_chiplet_mvpd_data[pv_op_order[i - 1]][3], i_chiplet_mvpd_data[pv_op_order[i]][3]),
                           pv_op_str[pv_op_order[i]], i_chiplet_mvpd_data[pv_op_order[i]][3]);

                    FAPI_INF("%s VCS current value %u i../../xml/attribute_info/pm_plat_attributes.xmls %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], i_chiplet_mvpd_data[pv_op_order[i - 1]][4],
                           POUNDV_SLOPE_CHECK(i_chiplet_mvpd_data[pv_op_order[i - 1]][4], i_chiplet_mvpd_data[pv_op_order[i]][4]),
                           pv_op_str[pv_op_order[i]], i_chiplet_mvpd_data[pv_op_order[i]][4]);



                    if (i_biased_state)
                    {
                        if (attr_poundv_validity_halt_disable)
                        {
                            // Log the error only.
                            FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(i_target)
                                .set_CHIPLET_NUMBER(i_chiplet_num)
                                .set_BUCKET(i_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][0])
                                .set_VDD_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][1])
                                .set_IDD_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][2])
                                .set_VCS_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][3])
                                .set_ICS_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][4])
                                .set_FREQUENCY_B(i_chiplet_mvpd_data[pv_op_order[i]][0])
                                .set_VDD_B(i_chiplet_mvpd_data[pv_op_order[i]][1])
                                .set_IDD_B(i_chiplet_mvpd_data[pv_op_order[i]][2])
                                .set_VCS_B(i_chiplet_mvpd_data[pv_op_order[i]][3])
                                .set_ICS_B(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                                "Pstate Parameter Block Biased #V disorder contents error being logged");

                             fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                        }
                        else
                        {
                            // Error out has Pstate and all dependent functions are suspious.
                            FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR()
                                .set_CHIP_TARGET(i_target)
                                .set_CHIPLET_NUMBER(i_chiplet_num)
                                .set_BUCKET(i_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][0])
                                .set_VDD_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][1])
                                .set_IDD_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][2])
                                .set_VCS_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][3])
                                .set_ICS_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][4])
                                .set_FREQUENCY_B(i_chiplet_mvpd_data[pv_op_order[i]][0])
                                .set_VDD_B(i_chiplet_mvpd_data[pv_op_order[i]][1])
                                .set_IDD_B(i_chiplet_mvpd_data[pv_op_order[i]][2])
                                .set_VCS_B(i_chiplet_mvpd_data[pv_op_order[i]][3])
                                .set_ICS_B(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                                "Pstate Parameter Block Biased #V disorder contents error being logged");
                        }
                    }
                    else
                    {
                        if (attr_poundv_validity_halt_disable)
                        {
                            // Log the error only.
                            FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(i_target)
                                .set_CHIPLET_NUMBER(i_chiplet_num)
                                .set_BUCKET(i_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][0])
                                .set_VDD_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][1])
                                .set_IDD_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][2])
                                .set_VCS_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][3])
                                .set_ICS_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][4])
                                .set_FREQUENCY_B(i_chiplet_mvpd_data[pv_op_order[i]][0])
                                .set_VDD_B(i_chiplet_mvpd_data[pv_op_order[i]][1])
                                .set_IDD_B(i_chiplet_mvpd_data[pv_op_order[i]][2])
                                .set_VCS_B(i_chiplet_mvpd_data[pv_op_order[i]][3])
                                .set_ICS_B(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                                "Pstate Parameter Block #V disorder contents error being logged");

                             fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                        }
                        else
                        {
                            // Error out has Pstate and all dependent functions are suspious.
                            FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR()
                                .set_CHIP_TARGET(i_target)
                                .set_CHIPLET_NUMBER(i_chiplet_num)
                                .set_BUCKET(i_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][0])
                                .set_VDD_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][1])
                                .set_IDD_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][2])
                                .set_VCS_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][3])
                                .set_ICS_A(i_chiplet_mvpd_data[pv_op_order[i - 1]][4])
                                .set_FREQUENCY_B(i_chiplet_mvpd_data[pv_op_order[i]][0])
                                .set_VDD_B(i_chiplet_mvpd_data[pv_op_order[i]][1])
                                .set_IDD_B(i_chiplet_mvpd_data[pv_op_order[i]][2])
                                .set_VCS_B(i_chiplet_mvpd_data[pv_op_order[i]][3])
                                .set_ICS_B(i_chiplet_mvpd_data[pv_op_order[i]][4]),
                                "Pstate Parameter Block #V disorder contents error being logged");
                        }
                    }
                }  // validity failed
            }  // Skip UT check
        } // point loop
    }  // validity disabled
fapi_try_exit:
    FAPI_DBG("<< proc_chk_valid_poundv");
    return fapi2::current_err;
}

/// ------------------------------------------------------------
/// \brief Copy VPD operating point into destination in assending order
/// \param[in]  &src[NUM_OP_POINTS]   => reference to source VPD structure (array)
/// \param[out] *dest[NUM_OP_POINTS]  => pointer to destination VpdOperatingPoint structure
//  \param[in]  i_frequency_step_khz  => Base frequency value for pstate calculation
/// ------------------------------------------------------------
/// \note:  this routine reads the keyword information in "VPD order" (eg Nominal,
///         PowerSave, Turbo, UltraTurbo) into the data structures in "Natural Order"
///         (eg (eg PowerSave, Nominal, Turbo, UltraTurbo)
///
fapi2::ReturnCode
load_mvpd_operating_point ( const uint32_t i_src[PV_D][PV_W],
                            VpdOperatingPoint* o_dest,
                            uint32_t i_frequency_step_khz)
{
    FAPI_DBG(">> load_mvpd_operating_point");
    const uint8_t pv_op_order[NUM_OP_POINTS] = VPD_PV_ORDER;

    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        o_dest[i].frequency_mhz  = revle32(i_src[pv_op_order[i]][0]);
        o_dest[i].vdd_mv         = revle32(i_src[pv_op_order[i]][1]);
        o_dest[i].idd_100ma      = revle32(i_src[pv_op_order[i]][2]);
        o_dest[i].vcs_mv         = revle32(i_src[pv_op_order[i]][3]);
        o_dest[i].ics_100ma      = revle32(i_src[pv_op_order[i]][4]);
        o_dest[i].pstate = (i_src[ULTRA][0] - i_src[pv_op_order[i]][0]) * 1000 / i_frequency_step_khz;
    }

    FAPI_DBG("<< load_mvpd_operating_point");
    return fapi2::FAPI2_RC_SUCCESS;
} // end load_mvpd_operating_point

fapi2::ReturnCode
proc_get_vdm_parms (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                    const AttributeList* i_attr,
                    GP_VDMParmBlock* o_vdmpb)
{
    FAPI_DBG(">> proc_get_vdm_parms");

    if (i_attr->attr_system_vdm_disable == fapi2::ENUM_ATTR_SYSTEM_VDM_DISABLE_OFF)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_DROOP_SMALL_OVERRIDE,
                                FAPI_SYSTEM,
                                o_vdmpb->droop_small_override));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_DROOP_LARGE_OVERRIDE,
                                FAPI_SYSTEM,
                                o_vdmpb->droop_large_override));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_DROOP_EXTREME_OVERRIDE,
                                FAPI_SYSTEM,
                                o_vdmpb->droop_extreme_override));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_OVERVOLT_OVERRIDE,
                                FAPI_SYSTEM,
                                o_vdmpb->overvolt_override));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_FMIN_OVERRIDE_KHZ,
                                FAPI_SYSTEM,
                                o_vdmpb->fmin_override_khz));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_FMAX_OVERRIDE_KHZ,
                                FAPI_SYSTEM,
                                o_vdmpb->fmax_override_khz));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_VID_COMPARE_OVERRIDE_MV,
                                FAPI_SYSTEM,
                                o_vdmpb->vid_compare_override_mv));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DPLL_VDM_RESPONSE,
                               FAPI_SYSTEM,
                               o_vdmpb->vdm_response));
    }
    else
    {
        FAPI_DBG("   VDM is diabled.  Skipping VDM attribute accesses");
    }

fapi_try_exit:
    FAPI_DBG("<< proc_get_vdm_parms");
    return fapi2::current_err;

}


fapi2::ReturnCode
proc_res_clock_setup ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                       ResonantClockingSetup* o_resclk_setup,
                       const GlobalPstateParmBlock* i_gppb)
{
    FAPI_DBG(">> proc_res_clock_setup");
    uint8_t l_resclk_freq_index[RESCLK_FREQ_REGIONS];
    uint16_t l_step_delay_ns;
    uint16_t l_l3_threshold_mv;
    uint16_t l_steparray[RESCLK_STEPS];
    uint16_t l_resclk_freq_regions[RESCLK_FREQ_REGIONS];
    uint32_t l_ultra_turbo_freq_khz = revle32(i_gppb->reference_frequency_khz);

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_SYSTEM_RESCLK_STEP_DELAY,
                            FAPI_SYSTEM,
                            l_step_delay_ns));
    o_resclk_setup->step_delay_ns = revle16(l_step_delay_ns);

    // Resonant Clocking Frequency and Index arrays
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGIONS, i_target,
                           l_resclk_freq_regions));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGION_INDEX, i_target,
                           l_resclk_freq_index));

    // Convert frequencies to pstates
    for (uint8_t i = 0; i < RESCLK_FREQ_REGIONS; ++i)
    {
        Pstate pstate;
        // Frequencies are given in MHz, convert to KHz
        uint32_t freq_khz = static_cast<uint32_t>(l_resclk_freq_regions[i]) * 1000;
        uint8_t idx = l_resclk_freq_index[i];

        // Frequencies need to be capped at Ultra-Turbo, frequencies less-than
        // the Minimum can be ignored (because this table is walked from
        // end-begin, and the frequencies are stored in ascending order,
        // the "walk" will never pass the minimum frequency).
        if (freq_khz > l_ultra_turbo_freq_khz)
        {
            freq_khz = l_ultra_turbo_freq_khz;

            // Need to walk the table backwards to find the index for this frequency
            for (uint8_t j = i; j >= 0; --j)
            {
                if (freq_khz >= (l_resclk_freq_regions[j] * 1000))
                {
                    idx = l_resclk_freq_index[j];
                    break;
                }
            }
        }

        int rc = freq2pState(i_gppb, freq_khz, &pstate);

        switch (rc)
        {
            case -PSTATE_LT_PSTATE_MIN:
                FAPI_INF("Resonant clock frequency %d KHz was clipped to Pstate 0",
                         freq_khz);
                break;

            case -PSTATE_GT_PSTATE_MAX:
                FAPI_INF("Resonant clock Frequency %d KHz is outside the range that can be represented"
                         " by a Pstate with a base frequency of %d KHz and step size %d KHz",
                         freq_khz,
                         l_ultra_turbo_freq_khz,
                         revle32(i_gppb->frequency_step_khz));
                FAPI_INF("Pstate is set to %X (%d)", pstate);
                break;
        }

        o_resclk_setup->resclk_freq[i] = pstate;
        o_resclk_setup->resclk_index[i] = idx;

        FAPI_DBG("Resclk:  pstate = %d; idx = %d", pstate, idx);
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VALUE, i_target,
                           o_resclk_setup->l3_steparray));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV, i_target,
                           l_l3_threshold_mv));
    o_resclk_setup->l3_threshold_mv = revle16(l_l3_threshold_mv);

    // Resonant Clocking Step array
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_VALUE, i_target,
                           l_steparray));

    for (uint8_t i = 0; i < RESCLK_STEPS; i++)
    {
        o_resclk_setup->steparray[i].value = revle16(l_steparray[i]);
    }

fapi_try_exit:
    FAPI_DBG("<< proc_res_clock_setup");
    return fapi2::current_err;
}

fapi2::ReturnCode
proc_get_ivrm_parms ( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      const AttributeList* i_attr,
                      IvrmParmBlock* o_ivrmpb,
                      PSTATE_attribute_state* o_state)
{
    FAPI_DBG(">> proc_get_ivrm_parms");

    if (i_attr->attr_system_ivrm_disable == fapi2::ENUM_ATTR_SYSTEM_IVRM_DISABLE_OFF)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        FAPI_INF(">> proc_get_ivrm_parms");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STRENGTH_LOOKUP, FAPI_SYSTEM,
                               o_ivrmpb->strength_lookup));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_VIN_MULTIPLIER, FAPI_SYSTEM,
                               o_ivrmpb->vin_multiplier));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_VIN_MAX_MV, FAPI_SYSTEM,
                               o_ivrmpb->vin_max_mv));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STEP_DELAY_NS, FAPI_SYSTEM,
                               o_ivrmpb->step_delay_ns));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STABILIZATION_DELAY_NS, FAPI_SYSTEM,
                               o_ivrmpb->stablization_delay_ns));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_DEADZONE_MV, FAPI_SYSTEM,
                               o_ivrmpb->deadzone_mv));


        // @todo  this is presently hardcoded to FALSE until validation code is in
        // place to ensure turning IVRM on is a good thing.  This attribute write is
        // needed to allocate the HWP attribute in Cronus.

        // Indicate that IVRM is good to be enabled (or not)
        FAPI_INF("   NOTE: This level of code is forcing the iVRM to OFF");
        {
            fapi2::ATTR_IVRM_ENABLED_Type l_ivrm_enabled =
                (fapi2::ATTR_IVRM_ENABLED_Type)fapi2::ENUM_ATTR_IVRM_ENABLED_FALSE;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IVRM_ENABLED, i_target, l_ivrm_enabled));
        }
    }
    else
    {
        FAPI_DBG("   IVRM is diabled.  Skipping IVRM attribute accesses");
        o_state->iv_ivrm_enabled = false;
    }

fapi_try_exit:
    FAPI_DBG("<< proc_get_ivrm_parms");
    return fapi2::current_err;

}


// Apply system parameters to a VPD value
uint32_t
sysparm_uplift(const uint32_t i_vpd_mv,
               const uint32_t i_vpd_ma,
               const uint32_t i_loadline_uohm,
               const uint32_t i_distloss_uohm,
               const uint32_t i_distoffset_uohm)
{
    return  revle32(i_vpd_mv +  // mV
                    (
                                // mA*uOhm/1000 -> uV
                      ((i_vpd_ma * (i_loadline_uohm + i_distloss_uohm)) / 1000 +
                                // uv
                      i_distoffset_uohm)
                    ) / 1000);  // uV -> mV
}

// Bias Adjust a voltage data value using a 1/2 percent bias amount.  Value
// is always taken to the higher integer value.
uint32_t
bias_adjust_mv(const uint32_t i_value,
               const int32_t i_bias_0p5pct)
{
    double l_mult = calc_bias(i_bias_0p5pct);
    double l_biased_value = (double)i_value * l_mult;
    FAPI_DBG("  bias_adjust_mv:  i_value=%d; mult=%f; biased value=%f",
                i_value,
                l_mult,
                l_biased_value);
    return revle32((uint32_t)internal_ceil(l_biased_value));
}

// Bias Adjust a frequency data value using a 1/2 percent bias amount.  Value
// is always taken to the lower integer value.
uint32_t
bias_adjust_mhz(const uint32_t i_value,
                const int32_t i_bias_0p5pct)
{
    double l_mult = calc_bias(i_bias_0p5pct);
    double l_biased_value = (double)i_value * l_mult;
    FAPI_DBG("  bias_adjust_mhz: i_value=%d; mult=%f; biased value=%f",
                i_value,
                l_mult,
                l_biased_value);
    return revle32((uint32_t)internal_floor(l_biased_value));
}

//
// p9_pstate_compute_vpd_pts
//
void p9_pstate_compute_vpd_pts(VpdOperatingPoint (*o_operating_points)[NUM_OP_POINTS],
                               GlobalPstateParmBlock* i_gppb,
                               VpdOperatingPoint* i_raw_vpd_pts)
{
    int p = 0;

    uint32_t l_vdd_loadline_uohm    = revle32(i_gppb->vdd_sysparm.loadline_uohm);
    uint32_t l_vdd_distloss_uohm    = revle32(i_gppb->vdd_sysparm.distloss_uohm);
    uint32_t l_vdd_distoffset_uv    = revle32(i_gppb->vdd_sysparm.distoffset_uv);
    uint32_t l_vcs_loadline_uohm    = revle32(i_gppb->vcs_sysparm.loadline_uohm);
    uint32_t l_vcs_distloss_uohm    = revle32(i_gppb->vcs_sysparm.distloss_uohm);
    uint32_t l_vcs_distoffset_uv    = revle32(i_gppb->vcs_sysparm.distoffset_uv);

    //RAW POINTS. We just copy them as is
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        o_operating_points[VPD_PT_SET_RAW][p].vdd_mv = i_raw_vpd_pts[p].vdd_mv;
        o_operating_points[VPD_PT_SET_RAW][p].vcs_mv = i_raw_vpd_pts[p].vcs_mv;
        o_operating_points[VPD_PT_SET_RAW][p].idd_100ma = i_raw_vpd_pts[p].idd_100ma;
        o_operating_points[VPD_PT_SET_RAW][p].ics_100ma = i_raw_vpd_pts[p].ics_100ma;
        o_operating_points[VPD_PT_SET_RAW][p].frequency_mhz = i_raw_vpd_pts[p].frequency_mhz;
        o_operating_points[VPD_PT_SET_RAW][p].pstate = i_raw_vpd_pts[p].pstate;

        FAPI_DBG("GP: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d)",
                    VPD_PT_SET_RAW, p,
                    o_operating_points[VPD_PT_SET_RAW][p].pstate,
                    revle32(o_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_RAW][p].vdd_mv),
                    revle32(o_operating_points[VPD_PT_SET_RAW][p].vdd_mv));
    }

    //SYSTEM PARAMS APPLIED POINTS
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        uint32_t l_vdd_mv = revle32(i_gppb->operating_points[p].vdd_mv);
        uint32_t l_idd_ma = revle32(i_gppb->operating_points[p].idd_100ma * 100);
        uint32_t l_vcs_mv = revle32(i_gppb->operating_points[p].vcs_mv);
        uint32_t l_ics_ma = revle32(i_gppb->operating_points[p].ics_100ma * 100);

        o_operating_points[VPD_PT_SET_SYSP][p].vdd_mv =
                  sysparm_uplift(l_vdd_mv,
                                 l_idd_ma,
                                 l_vdd_loadline_uohm,
                                 l_vdd_distloss_uohm,
                                 l_vdd_distoffset_uv);


        o_operating_points[VPD_PT_SET_SYSP][p].vcs_mv =
                  sysparm_uplift(l_vcs_mv,
                                 l_ics_ma,
                                 l_vcs_loadline_uohm,
                                 l_vcs_distloss_uohm,
                                 l_vcs_distoffset_uv);

        o_operating_points[VPD_PT_SET_SYSP][p].idd_100ma =
                   i_gppb->operating_points[p].idd_100ma;
        o_operating_points[VPD_PT_SET_SYSP][p].ics_100ma =
                   i_gppb->operating_points[p].ics_100ma;
        o_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz =
                   i_gppb->operating_points[p].frequency_mhz;
        o_operating_points[VPD_PT_SET_SYSP][p].pstate =
                   i_gppb->operating_points[p].pstate;

        FAPI_DBG("SP: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d)",
                    VPD_PT_SET_RAW, p,
                    o_operating_points[VPD_PT_SET_SYSP][p].pstate,
                    revle32(o_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_SYSP][p].vdd_mv),
                    revle32(o_operating_points[VPD_PT_SET_SYSP][p].vdd_mv));
    }

    //BIASED POINTS
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        uint32_t l_frequency_mhz = revle32(i_gppb->operating_points[p].frequency_mhz);
        uint32_t l_vdd_mv = revle32(i_gppb->operating_points[p].vdd_mv);
        uint32_t l_vcs_mv = revle32(i_gppb->operating_points[p].vcs_mv);

        o_operating_points[VPD_PT_SET_BIASED][p].vdd_mv =
                    bias_adjust_mv(l_vdd_mv, revle32(i_gppb->ext_biases[p].vdd_ext_hp));

        o_operating_points[VPD_PT_SET_BIASED][p].vcs_mv =
                    bias_adjust_mv(l_vcs_mv, revle32(i_gppb->ext_biases[p].vcs_ext_hp));

        o_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz =
                    bias_adjust_mhz(l_frequency_mhz, revle32(i_gppb->ext_biases[p].frequency_hp));

        o_operating_points[VPD_PT_SET_BIASED][p].idd_100ma =
                    i_gppb->operating_points[p].idd_100ma;
        o_operating_points[VPD_PT_SET_BIASED][p].ics_100ma =
                    i_gppb->operating_points[p].ics_100ma;

    }

    // Now that the ULTRA frequency is known, Pstates can be calculated
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        o_operating_points[VPD_PT_SET_BIASED][p].pstate =
            (((revle32(o_operating_points[VPD_PT_SET_BIASED][ULTRA].frequency_mhz) -
               revle32(o_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz)) * 1000) /
             revle32(i_gppb->frequency_step_khz));

        FAPI_DBG("Bi: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d), UT Freq=%3X (%4d) Step Freq=%5d",
                    VPD_PT_SET_RAW, p,
                    o_operating_points[VPD_PT_SET_BIASED][p].pstate,
                    revle32(o_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    revle32(o_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    revle32(o_operating_points[VPD_PT_SET_BIASED][ULTRA].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_BIASED][ULTRA].frequency_mhz),
                    revle32(i_gppb->frequency_step_khz));

    }

    //BIASED POINTS and SYSTEM PARMS APPLIED POINTS
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        uint32_t l_vdd_mv = revle32(o_operating_points[VPD_PT_SET_BIASED][p].vdd_mv);
        uint32_t l_idd_ma = revle32(o_operating_points[VPD_PT_SET_BIASED][p].idd_100ma) * 100;
        uint32_t l_vcs_mv = revle32(o_operating_points[VPD_PT_SET_BIASED][p].vcs_mv);
        uint32_t l_ics_ma = revle32(o_operating_points[VPD_PT_SET_BIASED][p].ics_100ma) * 100;

        o_operating_points[VPD_PT_SET_BIASED_SYSP][p].vdd_mv =
                    sysparm_uplift(l_vdd_mv,
                                   l_idd_ma,
                                   l_vdd_loadline_uohm,
                                   l_vdd_distloss_uohm,
                                   l_vdd_distoffset_uv);


        o_operating_points[VPD_PT_SET_BIASED_SYSP][p].vcs_mv =
                    sysparm_uplift(l_vcs_mv,
                                   l_ics_ma,
                                   l_vcs_loadline_uohm,
                                   l_vcs_distloss_uohm,
                                   l_vcs_distoffset_uv);

        o_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_100ma =
                    o_operating_points[VPD_PT_SET_BIASED][p].idd_100ma;
        o_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_100ma =
                    o_operating_points[VPD_PT_SET_BIASED][p].ics_100ma;
        o_operating_points[VPD_PT_SET_BIASED_SYSP][p].frequency_mhz =
                    o_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz;
        o_operating_points[VPD_PT_SET_BIASED_SYSP][p].pstate =
                    o_operating_points[VPD_PT_SET_BIASED][p].pstate;

        FAPI_DBG("BS: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d)",
                    VPD_PT_SET_RAW, p,
                    o_operating_points[VPD_PT_SET_SYSP][p].pstate,
                    revle32(o_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz),
                    revle32(o_operating_points[VPD_PT_SET_SYSP][p].vdd_mv),
                    revle32(o_operating_points[VPD_PT_SET_SYSP][p].vdd_mv));

    }
}

// Slope of m = (y1-y0)/(x1-x0) in 4.12 Fixed-Pt format
int16_t
compute_slope_4_12(uint32_t y1, uint32_t y0, uint32_t x1, uint32_t x0)
{
    return (int16_t)
           (
               // Perform division using floats for maximum precision
               // Store resulting slope in 4.12 Fixed-Pt format
               ((float)(y1 - y0) / (float)(x1 - x0)) * (1 << VID_SLOPE_FP_SHIFT_12)
           );

}

//  Slope of m = (y1-y0)/(x1-x0) in 3.13 Fixed-Pt format
int16_t
compute_slope_3_13(uint32_t y1, uint32_t y0, uint32_t x1, uint32_t x0)
{
    return (int16_t)
           (
               // Perform division using floats for maximum precision
               // Store resulting slope in 3.13 Fixed-Pt format
               ((float)(y1 - y0) / (float)(x1 - x0)) * (1 << VID_SLOPE_FP_SHIFT)
           );
}

//  Slope of m = (y1-y0)/(x1-x0) in 4.12 Fixed-Pt format for thresholds
int16_t
compute_slope_thresh(int32_t y1, int32_t y0, int32_t x1, int32_t x0)
{
    return (int16_t)
           (
               // Perform division using double for maximum precision
               // Store resulting slope in 4.12 Fixed-Pt format
               ((double)(y1 - y0) / (double)(x1 - x0)) * (1 << THRESH_SLOPE_FP_SHIFT)
           );
}

//
// p9_pstate_compute_PsV_slopes
//
// Computes slope of voltage-PState curve and PState-voltage
//
// PState(Frequency) on y-axis, Voltage is on x-axis for VF curve
// Interpolation formula: (y-y0)/(x-x0) = (y1-y0)/(x1-x0)
// m   = (x1-x0)/(y1-y0), then use this to calculate voltage, x = (y-y0)*m + x0
// 1/m = (y1-y0)/(x1-x0) here, then use this to calculate pstate(frequency), y = (x-x0)*m + y0
// Region 0 is b/w POWERSAVE and NOMINAL
// Region 1 is b/w NOMINAL and TURBO
// Region 2 is between TURBO and ULTRA_TURBO
//
// Inflection Point 3 is ULTRA_TURBO
// Inflection Point 2 is TURBO
// Inflection Point 1 is NOMINAL
// Inflection Point 0 is POWERSAVE
//
//\todo: Remove this. RTC: 174743
void p9_pstate_compute_PsV_slopes(VpdOperatingPoint i_operating_points[][4],
                                  GlobalPstateParmBlock* o_gppb)
{

    for(auto pt_set = 0; pt_set < VPD_NUM_SLOPES_SET; ++pt_set)
    {
        FAPI_DBG("PsVSlopes pt_set %d", pt_set);

        // ULTRA TURBO pstate check is not required because its pstate will be 0
        if (!(i_operating_points[pt_set][POWERSAVE].pstate) ||
            !(i_operating_points[pt_set][NOMINAL].pstate) ||
            !(i_operating_points[pt_set][TURBO].pstate))
        {
            FAPI_ERR("Non-UltraTurbo PSTATE value shouldn't be zero for %s (%d)", vpdSetStr[pt_set], pt_set);
            break;
        }

        //Calculate slopes
        for(auto region(REGION_POWERSAVE_NOMINAL); region <= REGION_TURBO_ULTRA; ++region)
        {
            // Pstate value decreases with increasing region.  Thus the values
            // are swapped to result in a positive difference.
            o_gppb->PsVSlopes[pt_set][region] =
                revle16(
                    compute_slope_3_13(revle32(i_operating_points[pt_set][region + 1].vdd_mv),
                                       revle32(i_operating_points[pt_set][region].vdd_mv),
                                       i_operating_points[pt_set][region].pstate,
                                       i_operating_points[pt_set][region + 1].pstate)
                );

            FAPI_DBG("PsVSlopes[%s][%s] 0x%04x %d", vpdSetStr[pt_set], region_names[region],
                     revle16(o_gppb->PsVSlopes[pt_set][region]),
                     revle16(o_gppb->PsVSlopes[pt_set][region]));
        }

        //Calculate inverted slopes
        for(auto region(REGION_POWERSAVE_NOMINAL); region <= REGION_TURBO_ULTRA; ++region)
        {
            // Pstate value decreases with increasing region.  Thus the values
            // are swapped to result in a positive difference.
            o_gppb->VPsSlopes[pt_set][region] =
                revle16(
                    compute_slope_3_13(i_operating_points[pt_set][region].pstate,
                                       i_operating_points[pt_set][region + 1].pstate,
                                       revle32(i_operating_points[pt_set][region + 1].vdd_mv),
                                       revle32(i_operating_points[pt_set][region].vdd_mv))
                );

            FAPI_DBG("VPsSlopes[%s][%s] 0x%04x %d", vpdSetStr[pt_set], region_names[region],
                     revle16(o_gppb->VPsSlopes[pt_set][region]),
                     revle16(o_gppb->VPsSlopes[pt_set][region]));
        }
    }
}

//This fills up the PStateVSlopes and VPStatesSlopes in GlobalParmBlock
//Going forward this method should be retained in favor of the p9_pstate_compute_PsVSlopes
void p9_pstate_compute_PStateV_slope(VpdOperatingPoint i_operating_points[][4],
                                     GlobalPstateParmBlock* o_gppb)
{
    for(auto pt_set = 0; pt_set < NUM_VPD_PTS_SET; ++pt_set)
    {

        // ULTRA TURBO pstate check is not required..because it's pstate will be
        // 0
        if (!(i_operating_points[pt_set][POWERSAVE].pstate) ||
            !(i_operating_points[pt_set][NOMINAL].pstate) ||
            !(i_operating_points[pt_set][TURBO].pstate))
        {
            FAPI_ERR("Non-UltraTurbo PSTATE value shouldn't be zero for %s", vpdSetStr[pt_set]);
            return;
        }

        //Calculate slopes
        for(auto region(REGION_POWERSAVE_NOMINAL); region <= REGION_TURBO_ULTRA; ++region)
        {
            // Pstate value decreases with increasing region.  Thus the values
            // are swapped to result in a positive difference.
            o_gppb->PStateVSlopes[pt_set][region] =
                revle16(
                    compute_slope_4_12(revle32(i_operating_points[pt_set][region + 1].vdd_mv),
                                       revle32(i_operating_points[pt_set][region].vdd_mv),
                                       i_operating_points[pt_set][region].pstate,
                                       i_operating_points[pt_set][region + 1].pstate)
                );

            FAPI_DBG("PStateVSlopes[%s][%s] 0x%04x %d", vpdSetStr[pt_set], region_names[region],
                     revle16(o_gppb->PStateVSlopes[pt_set][region]),
                     revle16(o_gppb->PStateVSlopes[pt_set][region]));
        }

        //Calculate inverted slopes
        for(auto region(REGION_POWERSAVE_NOMINAL); region <= REGION_TURBO_ULTRA; ++region)
        {
            // Pstate value decreases with increasing region.  Thus the values
            // are swapped to result in a positive difference.
            o_gppb->VPStateSlopes[pt_set][region] =
                revle16(
                    compute_slope_4_12(i_operating_points[pt_set][region].pstate,
                                       i_operating_points[pt_set][region + 1].pstate,
                                       revle32(i_operating_points[pt_set][region + 1].vdd_mv),
                                       revle32(i_operating_points[pt_set][region].vdd_mv))
                );

            FAPI_DBG("VPStateSlopes[%s][%s] 0x%04x %d", vpdSetStr[pt_set], region_names[region],
                     revle16(o_gppb->VPStateSlopes[pt_set][region]),
                     revle16(o_gppb->VPStateSlopes[pt_set][region]));
        }
    }
}

#define CENTER_STR(_buffer, _variable, _width)                  \
   {                                                            \
       int _w_ = _width-strlen(_variable)/2;                    \
       sprintf(_buffer, " %*s%*s  ", _w_, _variable, _w_, "");  \
   }

#define HEX_DEC_STR(_buffer, _hex, _dec)                        \
   {                                                            \
       char _temp_buffer[64];                                   \
       sprintf(_temp_buffer, " %04X (%4d) ", _dec, _hex);       \
       strcat(_buffer, _temp_buffer);                           \
   }

/// Print a GlobalPstateParameterBlock structure on a given stream
///
/// \param gppb The Global Pstate Parameter Block print

void
gppb_print(GlobalPstateParmBlock* i_gppb)
{
    static const uint32_t   BUFFSIZE = 256;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];
    char                    l_temp_buffer1[BUFFSIZE];
    const char*     pv_op_str[NUM_OP_POINTS] = PV_OP_ORDER_STR;
    const char*     thresh_op_str[NUM_THRESHOLD_POINTS] = VPD_THRESHOLD_ORDER_STR;
    const char*     slope_region_str[VPD_NUM_SLOPES_REGION] = VPD_OP_SLOPES_REGION_ORDER_STR;
    // Put out the endian-corrected scalars
    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("Global Pstate Parameter Block @ %p", i_gppb);
    FAPI_INF("---------------------------------------------------------------------------------------");

    FAPI_INF("%-20s : %X",
             "Options",
             revle32(i_gppb->options.options));
    FAPI_INF("%-20s : %X (%d)",
             "Reference Frequency",
             revle32(i_gppb->reference_frequency_khz),
             revle32(i_gppb->reference_frequency_khz));
    FAPI_INF("%-20s : %X (%d)",
             "Frequency Step Size",
             revle32(i_gppb->frequency_step_khz),
             revle32(i_gppb->frequency_step_khz));

    FAPI_INF("Operating Points:         Frequency     VDD(mV)    IDD(100mA)     VCS(mV)    ICS(100mA)");

    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {

        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-18s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points[i].frequency_mhz),
                revle32(i_gppb->operating_points[i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points[i].vdd_mv),
                revle32(i_gppb->operating_points[i].vdd_mv));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points[i].idd_100ma),
                revle32(i_gppb->operating_points[i].idd_100ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points[i].vcs_mv),
                revle32(i_gppb->operating_points[i].vcs_mv));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points[i].ics_100ma),
                revle32(i_gppb->operating_points[i].ics_100ma));

        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("System Parameters:              VDD         VCS         VDN")
    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-30s :", "Load line (uOhm)");
    strcat(l_buffer, l_temp_buffer);

    HEX_DEC_STR(l_buffer,
                revle32(i_gppb->vdd_sysparm.loadline_uohm),
                revle32(i_gppb->vdd_sysparm.loadline_uohm));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.loadline_uohm),
            revle32(i_gppb->vcs_sysparm.loadline_uohm));

    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdn_sysparm.loadline_uohm),
            revle32(i_gppb->vdn_sysparm.loadline_uohm));
    FAPI_INF("%s", l_buffer);

    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-30s :", "Distribution Loss (uOhm)");
    strcat(l_buffer, l_temp_buffer);

    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdd_sysparm.distloss_uohm),
            revle32(i_gppb->vdd_sysparm.distloss_uohm));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.distloss_uohm),
            revle32(i_gppb->vcs_sysparm.distloss_uohm));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdn_sysparm.distloss_uohm),
            revle32(i_gppb->vdn_sysparm.distloss_uohm));
    FAPI_INF("%s", l_buffer);

    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-30s :", "Offset (uV)");
    strcat(l_buffer, l_temp_buffer);

    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdd_sysparm.distoffset_uv),
            revle32(i_gppb->vdd_sysparm.distoffset_uv));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.distoffset_uv),
            revle32(i_gppb->vcs_sysparm.distoffset_uv));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdn_sysparm.distoffset_uv),
            revle32(i_gppb->vdn_sysparm.distoffset_uv));
    FAPI_INF("%s", l_buffer);

    FAPI_INF("Safe Parameters:");
    FAPI_INF("  %-30s : %04X (%3d) ",
             "Frequency",
             revle32(i_gppb->safe_frequency_khz),
             revle32(i_gppb->safe_frequency_khz));
    FAPI_INF("  %-30s : %04X (%3d) ",
             "Voltage",
             revle32(i_gppb->safe_voltage_mv),
             revle32(i_gppb->safe_voltage_mv));

    FAPI_INF("Pstate Stepping Parameters:");
    FAPI_INF("  %-30s : %04X (%3d) ",
             "Delay range exponent",
             revle32(i_gppb->vrm_stepdelay_range),
             revle32(i_gppb->vrm_stepdelay_range));
    FAPI_INF("  %-30s : %04X (%3d) ",
             "Significand",
             revle32(i_gppb->vrm_stepdelay_value),
             revle32(i_gppb->vrm_stepdelay_value));

    FAPI_INF("External VRM Parameters:");
    FAPI_INF("  %-30s : %04X (%3d) ",
             "VRM Transition Start",
             revle32(i_gppb->ext_vrm_transition_start_ns),
             revle32(i_gppb->ext_vrm_transition_start_ns));
    FAPI_INF("  %-30s : %04X (%3d) ",
             "VRM Transition Rate - Rising",
             revle32(i_gppb->ext_vrm_transition_rate_inc_uv_per_us),
             revle32(i_gppb->ext_vrm_transition_rate_inc_uv_per_us));
    FAPI_INF("  %-30s : %04X (%3d) ",
             "VRM Transition Rate - Falling",
             revle32(i_gppb->ext_vrm_transition_rate_dec_uv_per_us),
             revle32(i_gppb->ext_vrm_transition_rate_dec_uv_per_us));
    FAPI_INF("  %-30s : %04X (%3d) ",
             "VRM Settling Time (us)",
             revle32(i_gppb->ext_vrm_transition_rate_dec_uv_per_us),
             revle32(i_gppb->ext_vrm_transition_rate_dec_uv_per_us));
    FAPI_INF("  %-30s : %04X (%3d) ",
             "VRM Transition Step Size (mV)",
             revle32(i_gppb->ext_vrm_step_size_mv),
             revle32(i_gppb->ext_vrm_step_size_mv));

    FAPI_INF("  %-30s : %04X (%3d) ",
             "Nest Frequency",
             revle32(i_gppb->nest_frequency_mhz),
             revle32(i_gppb->nest_frequency_mhz));


    // 2 Slope sets

    sprintf(l_buffer, "PsVSlopes:");
    sprintf( l_temp_buffer,  "%9s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, " %s  ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);
    for (auto i = 0; i < VPD_NUM_SLOPES_SET; ++i)
    {
        sprintf(l_buffer, " %-16s : ", vpdSetStr[i]);
        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer, "%6s%04X%7s ",
                    " ",revle16(i_gppb->PsVSlopes[i][j])," ");
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }

    sprintf(l_buffer, "VPsSlopes:");
    sprintf( l_temp_buffer,  "%9s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, " %s  ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);
    for (auto i = 0; i < VPD_NUM_SLOPES_SET; ++i)
    {
        sprintf(l_buffer, " %-16s : ", vpdSetStr[i]);
        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer, "%6s%04X%7s ",
                    " ",revle16(i_gppb->VPsSlopes[i][j])," ");
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }

    // 4 Slope sets
    sprintf(l_buffer, "PstateVSlopes:");
    sprintf( l_temp_buffer,  "%5s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, " %s  ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);
    for (auto i = 0; i < NUM_VPD_PTS_SET; ++i)
    {
        sprintf(l_buffer, " %-16s : ", vpdSetStr[i]);
        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer, "%6s%04X%7s ",
                    " ",revle16(i_gppb->PStateVSlopes[i][j])," ");
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }

    sprintf(l_buffer, "VPstateSlopes:");
    sprintf( l_temp_buffer,  "%5s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, " %s  ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);
    for (auto i = 0; i < NUM_VPD_PTS_SET; ++i)
    {
        sprintf(l_buffer, " %-16s : ", vpdSetStr[i]);
        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer, "%6s%04X%7s ",
                    " ",revle16(i_gppb->VPStateSlopes[i][j])," ");
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }
    FAPI_INF ("VID Operating Points");

    for (auto i = 0; i < NUM_OP_POINTS; ++i)
    {
        sprintf (l_buffer, " %-16s :  %02X ",pv_op_str[i], i_gppb->vid_point_set[i]);
        FAPI_INF("%s", l_buffer);
    }

    sprintf(l_buffer, "%-25s", "Thrshod Op Points: ");
    for (auto  j = 0; j < NUM_THRESHOLD_POINTS; ++j)
    {
        CENTER_STR(l_temp_buffer, thresh_op_str[j], 8);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);

    strcpy(l_buffer,"");
    for (auto i = 0; i < NUM_OP_POINTS; ++i)
    {
        sprintf(l_buffer, " %-16s :      ", pv_op_str[i]);
        for (auto j = 0; j < NUM_THRESHOLD_POINTS; ++j)
        {
            sprintf(l_temp_buffer1, "%04X",
                    i_gppb->threshold_set[i][j]);
            CENTER_STR(l_temp_buffer, l_temp_buffer1, 8);
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }

    sprintf(l_buffer, "VID Compare Slopes:");
    int l_len = strlen(l_buffer);
    for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer1, "%s", prt_region_names[j]);
        CENTER_STR(l_temp_buffer, l_temp_buffer1, 8);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);

    sprintf( l_buffer,  "%*s", l_len+6," ");
    for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer1, "%04X",
                revle16(i_gppb->PsVIDCompSlopes[j]));
        CENTER_STR(l_temp_buffer, l_temp_buffer1, 8);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "%-18s", "VDM Thrshld Slopes:");
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        CENTER_STR(l_temp_buffer, slope_region_str[j], 8);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);
    for (auto i = 0; i < NUM_THRESHOLD_POINTS; ++i)
    {
        sprintf(l_buffer, " %-16s :      ", thresh_op_str[i]);
        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer1, " %3i ",
                    i_gppb->PsVDMThreshSlopes[i][j]);
            CENTER_STR(l_temp_buffer, l_temp_buffer1, 8);
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }

    sprintf(l_buffer, "%-18s", "VDM Jump Slopes: ");
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        CENTER_STR(l_temp_buffer, slope_region_str[j], 8);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);
    for (auto i = 0; i < NUM_THRESHOLD_POINTS; ++i)
    {
        sprintf(l_buffer, " %-16s :      ", thresh_op_str[i]);
        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer1, " %02X ",
                    i_gppb->PsVDMJumpSlopes[i][j]);
            CENTER_STR(l_temp_buffer, l_temp_buffer1, 8);
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }


//
//
//
//     FAPI_INF ("VDM THRESHOLD SLOPES");
//
//     for (uint8_t i = 0; i < VPD_NUM_SLOPES_REGION; ++i)
//     {
//         strcpy(l_buffer,"");
//         sprintf (l_temp_buffer, " %s  ",slope_region_str[i]);
//         FAPI_INF("%s", l_temp_buffer);
//         for (uint8_t j = 0; j < NUM_THRESHOLD_POINTS; ++j)
//         {
//             sprintf (l_temp_buffer, " %s :  %02X   ",thresh_op_str[j], i_gppb->PsVDMThreshSlopes[i][j]);
//             strcat (l_buffer, l_temp_buffer);
//         }
//         FAPI_INF("%s", l_buffer);
//     }
//
//     FAPI_INF ("VDM JUMP SLOPES");
//
//     for (uint8_t i = 0; i < VPD_NUM_SLOPES_REGION; ++i)
//     {
//         strcpy(l_buffer,"");
//         sprintf (l_temp_buffer, " %s  ",slope_region_str[i]);
//         FAPI_INF("%s", l_temp_buffer);
//         for (uint8_t j = 0; j < NUM_JUMP_VALUES; ++j)
//         {
//             sprintf (l_temp_buffer, " %s :  %02X   ",thresh_op_str[j], i_gppb->PsVDMJumpSlopes[i][j]);
//             strcat (l_buffer, l_temp_buffer);
//         }
//         FAPI_INF("%s", l_buffer);
//     }

    // Resonant Clocking
    FAPI_DBG("Resonant Clocking Setup:");
    FAPI_DBG("Pstates ResClk Index");

    for (auto i = 0; i < RESCLK_FREQ_REGIONS; ++i)
    {
        FAPI_DBG("    %03d           %02d", i_gppb->resclk.resclk_freq[i],
                 i_gppb->resclk.resclk_index[i]);
    }

    FAPI_INF("---------------------------------------------------------------------------------------");
}

/// Print an OCCPstateParameterBlock structure on a given stream
///
/// \param oppb The OCC Pstate Parameter Block print

void
oppb_print(OCCPstateParmBlock* i_oppb)
{
    static const uint32_t   BUFFSIZE = 256;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];

    // Put out the endian-corrected scalars

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("OCC Pstate Parameter Block @ %p", i_oppb);
    FAPI_INF("---------------------------------------------------------------------------------------");

//    fprintf(stream, "Magic:               %llu\n", revle64(i_oppb->magic));
    FAPI_INF("Operating Points:  Frequency     VDD(mV)    IDD(100mA)     VCS(mV)    ICS(100mA)");

    for (auto i = 0; i < NUM_OP_POINTS; i++)
    {
        sprintf(l_buffer, "                 ");
        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_oppb->operating_points[i].frequency_mhz),
                revle32(i_oppb->operating_points[i].frequency_mhz));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_oppb->operating_points[i].vdd_mv),
                revle32(i_oppb->operating_points[i].vdd_mv));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_oppb->operating_points[i].idd_100ma),
                revle32(i_oppb->operating_points[i].idd_100ma));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%4d) ",
                revle32(i_oppb->operating_points[i].vcs_mv),
                revle32(i_oppb->operating_points[i].vcs_mv));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " %04X (%3d) ",
                revle32(i_oppb->operating_points[i].ics_100ma),
                revle32(i_oppb->operating_points[i].ics_100ma));
        strcat(l_buffer, l_temp_buffer);
        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("System Parameters:              VDD         VCS         VDN");
    sprintf(l_buffer, "   Load line (uOhm)         ");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.loadline_uohm),
            revle32(i_oppb->vdd_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.loadline_uohm),
            revle32(i_oppb->vcs_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.loadline_uohm),
            revle32(i_oppb->vdn_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "   Distribution Loss (uOhm) ");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.distloss_uohm),
            revle32(i_oppb->vdd_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.distloss_uohm),
            revle32(i_oppb->vcs_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.distloss_uohm),
            revle32(i_oppb->vdn_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "   Offset (uV)              ");
    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.distoffset_uv),
            revle32(i_oppb->vdd_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.distoffset_uv),
            revle32(i_oppb->vcs_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " %04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.distoffset_uv),
            revle32(i_oppb->vdn_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    FAPI_INF("Frequency Minumum (kHz):     %04X (%3d)",
             revle32(i_oppb->frequency_min_khz),
             revle32(i_oppb->frequency_min_khz));

    FAPI_INF("Frequency Maximum (kHz):     %04X (%3d)",
             revle32(i_oppb->frequency_max_khz),
             revle32(i_oppb->frequency_max_khz));

    FAPI_INF("Frequency Step (kHz):        %04X (%3d)",
             revle32(i_oppb->frequency_step_khz),
             revle32(i_oppb->frequency_step_khz));

    FAPI_INF("Pstate of Minimum Frequency: %02X (%3d)",
             i_oppb->pstate_min,
             i_oppb->pstate_min);

    FAPI_INF("Nest Frequency:              %02X (%3d)",
             i_oppb->nest_frequency_mhz,
             i_oppb->nest_frequency_mhz);

    FAPI_INF("Nest Leakage Percent:        %02X (%3d)",
             i_oppb->nest_leakage_percent,
             i_oppb->nest_leakage_percent);

    FAPI_INF("Ceff TDP Vdn:                %02X (%3d)",
             i_oppb->ceff_tdp_vdn,
             i_oppb->ceff_tdp_vdn);

    FAPI_INF("Iac TDP VDD Turbo(10ma):     %02X (%3d)",
             i_oppb->lac_tdp_vdd_turbo_10ma,
             i_oppb->lac_tdp_vdd_turbo_10ma);

    FAPI_INF("Iac TDP VDD Nominal(10ma):   %02X (%3d)",
             i_oppb->lac_tdp_vdd_nominal_10ma,
             i_oppb->lac_tdp_vdd_nominal_10ma);

    FAPI_INF("WOF Elements");
    sprintf(l_buffer, "   WOF Enabled             ");
    sprintf(l_temp_buffer, "  %1d ",
            i_oppb->wof.wof_enabled);
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "   TDP RDP Factor          ");
    sprintf(l_temp_buffer, "  %04X (%3d) ",
            i_oppb->wof.tdp_rdp_factor,
            i_oppb->wof.tdp_rdp_factor);
    strcat(l_buffer, l_temp_buffer);
    FAPI_INF("%s", l_buffer);

    // Put out the structure to the trace
    iddq_print(&(i_oppb->iddq));

    FAPI_INF("---------------------------------------------------------------------------------------");
}

/// Print an iddq_print structure on a given stream
///
/// \param i_iddqt pointer to Iddq structure to output

void
iddq_print(IddqTable* i_iddqt)
{
    uint32_t        i, j;
    const char*     idd_meas_str[IDDQ_MEASUREMENTS] = IDDQ_ARRAY_VOLTAGES_STR;
    char            l_buffer_str[256];   // Temporary formatting string buffer
    char            l_line_str[256];     // Formatted output line string

    static const uint32_t IDDQ_DESC_SIZE = 56;
    static const uint32_t IDDQ_QUAD_SIZE = IDDQ_DESC_SIZE -
                                            strlen("Quad X:");

    FAPI_INF("IDDQ");

    // Put out the endian-corrected scalars

    // get IQ version and advance pointer 1-byte
    FAPI_INF("  IDDQ Version Number = %u", i_iddqt->iddq_version);
    FAPI_INF("  Sort Info:         Good Quads = %02d Good Cores = %02d Good Caches = %02d",
             i_iddqt->good_quads_per_sort,
             i_iddqt->good_normal_cores_per_sort,
             i_iddqt->good_caches_per_sort);

    // get number of good normal cores in each quad
    strcpy(l_line_str, "  Good normal cores:");
    strcpy(l_buffer_str, "");

    for (i = 0; i < MAXIMUM_QUADS; i++)
    {
        sprintf(l_buffer_str, " Quad %d = %u ", i, i_iddqt->good_normal_cores[i]);
        strcat(l_line_str, l_buffer_str);
    }

    FAPI_INF("%s", l_line_str);

    // get number of good caches in each quad
    strcpy(l_line_str, "  Good caches:      ");
    strcpy(l_buffer_str, "");

    for (i = 0; i < MAXIMUM_QUADS; i++)
    {
        sprintf(l_buffer_str, " Quad %d = %u ", i, i_iddqt->good_caches[i]);
        strcat(l_line_str, l_buffer_str);
    }

    FAPI_INF("%s", l_line_str);

    // get RDP TO TDP scalling factor
    FAPI_INF("  RDP TO TDP scalling factor = %u", revle16(i_iddqt->rdp_to_tdp_scale_factor));

    // get WOF IDDQ margin factor
    FAPI_INF("  WOF IDDQ margin factor     = %u", revle16(i_iddqt->wof_iddq_margin_factor));

    // get VDD Temperature scaling factor
    FAPI_INF("  VDD  Temperature scaling factor = %u", revle16(i_iddqt->vdd_temperature_scale_factor));

    // get VDN Temperature scaling factor
    FAPI_INF("  VDN  Temperature scaling factor = %u", revle16(i_iddqt->vdn_temperature_scale_factor));

    // All IQ IDDQ measurements are at 5mA resolution. The OCC wants to
    // consume these at 1mA values.  thus, all values are multiplied by
    // 5 upon installation into the paramater block.
    static const uint32_t CONST_5MA_1MA = 5;
    FAPI_INF("  IDDQ data is converted 5mA units to 1mA units");

    // Put out the measurement voltages to the trace.
    strcpy(l_line_str, "  Measurement voltages:");
    sprintf(l_buffer_str, "%-*s ", IDDQ_DESC_SIZE, l_line_str);
    strcpy(l_line_str, l_buffer_str);
    strcpy(l_buffer_str, "");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        sprintf(l_buffer_str, "  %*sV  ", 5, idd_meas_str[i]);
        strcat(l_line_str, l_buffer_str);
    }

    FAPI_INF("%s", l_line_str);

#define IDDQ_CURRENT_EXTRACT(_member) \
        { \
        uint16_t _temp = revle16(i_iddqt->_member) * CONST_5MA_1MA;     \
        sprintf(l_buffer_str, "  %6.3f ", (double)_temp/1000);          \
        strcat(l_line_str, l_buffer_str); \
        }

// Temps are all 1B quantities.  Not endianess issues.
#define IDDQ_TEMP_EXTRACT(_member) \
        sprintf(l_buffer_str, "   %4.1f  ", ((double)i_iddqt->_member)/2); \
        strcat(l_line_str, l_buffer_str);

#define IDDQ_TRACE(string, size) \
        strcpy(l_line_str, string); \
        sprintf(l_buffer_str, "%-*s", size, l_line_str);\
        strcpy(l_line_str, l_buffer_str); \
        strcpy(l_buffer_str, "");

    // get IVDDQ measurements with all good cores ON
    IDDQ_TRACE ("  IDDQ all good cores ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(ivdd_all_good_cores_on_caches_on[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get IVDDQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  IVDDQ all cores and caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
       IDDQ_CURRENT_EXTRACT(ivdd_all_cores_off_caches_off[i]);
    }

    FAPI_INF("%s", l_line_str);;

    // get IVDDQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  IVDDQ all good cores OFF and caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(ivdd_all_good_cores_off_good_caches_on[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get IVDDQ measurements with all good cores in each quad
    for (i = 0; i < MAXIMUM_QUADS; i++)
    {
        IDDQ_TRACE ("  IVDDQ all good cores ON and caches ON ", IDDQ_QUAD_SIZE);
        sprintf(l_buffer_str, "Quad %d:", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(ivdd_quad_good_cores_on_good_caches_on[i][j]);
        }

        FAPI_INF("%s", l_line_str);
    }

    // get IVDN data
    IDDQ_TRACE ("  IVDN", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(ivdn[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all good cores ON
    IDDQ_TRACE ("  Average temp all good cores ON:",IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
         IDDQ_TEMP_EXTRACT(avgtemp_all_good_cores_on[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperatur}e measurements with all cores and caches OFF
    IDDQ_TRACE ("  Average temp all cores OFF, caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_cores_off_caches_off[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  Average temp all good cores OFF, caches ON:",IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_good_cores_off[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all good cores in each quad
    for (i = 0; i < MAXIMUM_QUADS; i++)
    {
        IDDQ_TRACE ("  Average temp all good cores ON, good caches ON ",IDDQ_QUAD_SIZE);
        sprintf(l_buffer_str, "Quad %d:", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_TEMP_EXTRACT(avgtemp_quad_good_cores_on[i][j]);
        }

        FAPI_INF("%s", l_line_str);
    }

    // get average nest temperature nest
    IDDQ_TRACE ("  Average temp Nest:",IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_vdn[i]);
    }

    FAPI_INF("%s", l_line_str);
}

// Convert frequency to Pstate number
int
freq2pState (const GlobalPstateParmBlock* gppb,
             const uint32_t freq_khz,
             Pstate* pstate)
{
    int rc = 0;
    float pstate32 = 0;

    // ----------------------------------
    // compute pstate for given frequency
    // ----------------------------------
    pstate32 = ((float)(revle32(gppb->reference_frequency_khz) - (float)freq_khz)) /
               (float)revle32(gppb->frequency_step_khz);
    // @todo Bug fix from Characterization team to deal with VPD not being
    // exactly in step increments
    //       - not yet included to separate changes
    // As higher Pstate numbers represent lower frequencies, the pstate must be
    // snapped to the nearest *higher* integer value for safety.  (e.g. slower
    // frequencies are safer).
    //*pstate  = (Pstate)internal_ceil(pstate32);
    *pstate  = (Pstate)pstate32;

    // ------------------------------
    // perform pstate bounds checking
    // ------------------------------
    if (pstate32 < PSTATE_MIN)
    {
        rc = -PSTATE_LT_PSTATE_MIN;
        *pstate = PSTATE_MIN;
    }

    if (pstate32 > PSTATE_MAX)
    {
        rc = -PSTATE_GT_PSTATE_MAX;
        *pstate = PSTATE_MAX;
    }

    return rc;
}

// Convert Pstate number to frequency
int
pState2freq (const GlobalPstateParmBlock* gppb,
             const Pstate i_pstate,
             uint32_t*   o_freq_khz)
{
    int rc = 0;
    float pstate32 = i_pstate;
    float l_freq_khz = 0;

    // ----------------------------------
    // compute frequency from a pstate
    // ----------------------------------
    l_freq_khz = ((float)(revle32(gppb->reference_frequency_khz)) -
                          (pstate32 * (float)revle32(gppb->frequency_step_khz)));

    *o_freq_khz  = (uint32_t)l_freq_khz;

    return rc;
}


fapi2::ReturnCode
proc_get_mvpd_poundw(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     uint8_t       i_poundv_bucketId,
                     LP_VDMParmBlock* o_vdmpb,
                     PoundW_data* o_data,
                     fapi2::voltageBucketData_t i_poundv_data,
                     PSTATE_attribute_state* o_state,
                     bool i_skip_check)
{
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
    fapi2::vdmData_t l_vdmBuf;
    uint8_t    j                = 0;
    uint8_t    bucket_id        = 0;
    const uint16_t VDM_VOLTAGE_IN_MV = 512;
    const uint16_t VDM_GRANULARITY = 4;

    const char*     pv_op_str[NUM_OP_POINTS] = PV_OP_ORDER_STR;

    FAPI_DBG(">> proc_get_mvpd_poundw");

    do
    {
         FAPI_DBG("proc_get_mvpd_poundw: VDM enable = %d, WOF enable %d",
                    is_vdm_enabled(o_state), is_wof_enabled(o_state));

        // Exit if both VDM and WOF is disabled
        if ((!is_vdm_enabled(o_state) && !is_wof_enabled(o_state)) &&
            !i_skip_check)
        {
            FAPI_INF("   proc_get_mvpd_poundw: BOTH VDM and WOF are disabled.  Skipping remaining checks");
            o_state->iv_vdm_enabled = false;
            o_state->iv_wof_enabled = false;
            break;
        }

        // Below fields for Nominal, Powersave, Turbo, Ultra Turbo
        // I-VDD Nominal TDP AC current  2B
        // I-VDD Nominal TDP DC current 2B
        // Overvolt Threshold 0.5  Upper nibble of byte
        // Small Threshold 0.5  Lower nibble of byte
        // Large Threshold 0.5  Upper nibble of byte
        // eXtreme Threshold 0.5 Lower nibble of byte
        // Small Frequency Drop  1B
        // Large Frequency Drop 1B
        // -----------------------------------------------------------------
        l_eqChiplets = i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

        for (j = 0; j < l_eqChiplets.size(); j++)
        {
            uint8_t l_chipNum = 0xFF;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_eqChiplets[j], l_chipNum));

            FAPI_INF("Chip Number => %u", l_chipNum);

            // clear out buffer to known value before calling fapiGetMvpdField
            memset(&l_vdmBuf, 0, sizeof(l_vdmBuf));

            FAPI_TRY(p9_pm_get_poundw_bucket(l_eqChiplets[j], l_vdmBuf));

            bucket_id = l_vdmBuf.bucketId;

            FAPI_INF("#W chiplet = %u bucket id = %u", l_chipNum, bucket_id);

            //if we match with the bucket id, then we don't need to continue
            if (i_poundv_bucketId == bucket_id)
            {
                break;
            }
        }

        uint8_t l_poundw_static_data = 0;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_W_STATIC_DATA_ENABLE,
                               FAPI_SYSTEM,
                               l_poundw_static_data),
                 "Error from FAPI_ATTR_GET for attribute ATTR_POUND_W_STATIC_DATA_ENABLE");

        if (l_poundw_static_data)
        {
            FAPI_INF("attribute ATTR_POUND_W_STATIC_DATA_ENABLE is set");
            // copy the data to the pound w structure from a hardcoded table
            memcpy (o_data, &g_vpdData, sizeof (g_vpdData));
        }
        else
        {
            FAPI_INF("attribute ATTR_POUND_W_STATIC_DATA_ENABLE is NOT set");
            // copy the data to the pound w structure from the actual VPD image
            memcpy (o_data, l_vdmBuf.vdmData, sizeof (l_vdmBuf.vdmData));
        }

        //Re-ordering to Natural order
        // When we read the data from VPD image the order will be N,PS,T,UT.
        // But we need the order PS,N,T,UT.. hence we are swapping the data
        // between PS and Nominal.
        poundw_entry_t l_tmp_data;
        memcpy (&l_tmp_data,
                &(o_data->poundw[VPD_PV_NOMINAL]),
                sizeof (poundw_entry_t));

        memcpy (&(o_data->poundw[VPD_PV_NOMINAL]),
                &(o_data->poundw[VPD_PV_POWERSAVE]),
                sizeof(poundw_entry_t));

        memcpy (&(o_data->poundw[VPD_PV_POWERSAVE]),
                &l_tmp_data,
                sizeof(poundw_entry_t));

        // Validate the WOF content is non-zero if WOF is enabled
        if (is_wof_enabled(o_state))
        {
            bool b_tdp_ac = true;
            bool b_tdp_dc = true;
            // Check that the WOF currents are non-zero
            for (auto p = 0; p < NUM_OP_POINTS; ++p)
            {
                FAPI_INF("%s ivdd_tdp_ac_current %5d (10mA) %6.2f (A)",
                    pv_op_str[p],
                    revle16(o_data->poundw[p].ivdd_tdp_ac_current_10ma),
                    ((double)revle16(o_data->poundw[p].ivdd_tdp_ac_current_10ma)/100));
                FAPI_INF("%s ivdd_tdp_dc_current %5d (10mA) %6.2f (A)",
                    pv_op_str[p],
                    revle16(o_data->poundw[p].ivdd_tdp_dc_current_10ma),
                    ((double)revle16(o_data->poundw[p].ivdd_tdp_dc_current_10ma)/100));
                if (!o_data->poundw[p].ivdd_tdp_ac_current_10ma)
                {
                    FAPI_ERR("%s.ivdd_tdp_ac_current_10ma is zero!!!",
                                pv_op_str[p]);
                    b_tdp_ac = false;
                    o_state->iv_wof_enabled = false;

                }
                if (!o_data->poundw[p].ivdd_tdp_dc_current_10ma)
                {
                    FAPI_ERR("%s.ivdd_tdp_dc_current_10ma is zero!!!",
                                pv_op_str[p]);
                    b_tdp_dc = false;
                    o_state->iv_wof_enabled = false;
                }
            }

            FAPI_ASSERT_NOEXIT(b_tdp_ac,
                               fapi2::PSTATE_PB_POUND_W_TDP_IAC_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(i_target)
                               .set_NOMINAL_TDP_IAC(o_data->poundw[NOMINAL].ivdd_tdp_dc_current_10ma)
                               .set_POWERSAVE_TDP_IAC(o_data->poundw[POWERSAVE].ivdd_tdp_dc_current_10ma)
                               .set_TURBO_TDP_IAC(o_data->poundw[TURBO].ivdd_tdp_dc_current_10ma)
                               .set_ULTRA_TDP_IAC(o_data->poundw[ULTRA].ivdd_tdp_dc_current_10ma),
                               "Pstate Parameter Block #W : one or more Idd TDP AC values are zero");
            FAPI_ASSERT_NOEXIT(b_tdp_dc,
                               fapi2::PSTATE_PB_POUND_W_TDP_IDC_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(i_target)
                               .set_NOMINAL_TDP_IDC(o_data->poundw[NOMINAL].ivdd_tdp_dc_current_10ma)
                               .set_POWERSAVE_TDP_IDC(o_data->poundw[POWERSAVE].ivdd_tdp_dc_current_10ma)
                               .set_TURBO_TDP_IDC(o_data->poundw[TURBO].ivdd_tdp_dc_current_10ma)
                               .set_ULTRA_TDP_IDC(o_data->poundw[ULTRA].ivdd_tdp_dc_current_10ma),
                               "Pstate Parameter Block #W : one or more Idd TDP DC values are zero");

            // Set the return code to success to keep going.
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

        // The rest of the processing here is all checking of the VDM content
        // within #W.  If VDMs are not enabled (or supported), skip all of it
        if (!is_vdm_enabled(o_state))
        {
            FAPI_INF("   proc_get_mvpd_poundw: VDM is disabled.  Skipping remaining checks");
            o_state->iv_vdm_enabled = false;
            break;
        }

        FAPI_INF("POWERSAVE.vdm_vid_compare_ivid %d",o_data->poundw[POWERSAVE].vdm_vid_compare_ivid);
        FAPI_INF("NOMINAL.vdm_vid_compare_ivid %d",o_data->poundw[NOMINAL].vdm_vid_compare_ivid);
        FAPI_INF("TURBO.vdm_vid_compare_ivid %d",o_data->poundw[TURBO].vdm_vid_compare_ivid);
        FAPI_INF("ULTRA_TURBO.vdm_vid_compare_ivid %d",o_data->poundw[ULTRA].vdm_vid_compare_ivid);
        //Validation of VPD Data
        //
        //If all VID compares are zero then use #V VDD voltage to populate local
        //data structure..So that we make progress in lab with early hardware
        if ( !(o_data->poundw[NOMINAL].vdm_vid_compare_ivid) &&
             !(o_data->poundw[POWERSAVE].vdm_vid_compare_ivid) &&
             !(o_data->poundw[TURBO].vdm_vid_compare_ivid) &&
             !(o_data->poundw[ULTRA].vdm_vid_compare_ivid))
        {
            //vdm_vid_compare_ivid will be in ivid units (eg HEX((Compare
            //Voltage (mv) - 512mV)/4mV).
            o_data->poundw[NOMINAL].vdm_vid_compare_ivid    =
                (i_poundv_data.VddNomVltg    - VDM_VOLTAGE_IN_MV ) / VDM_GRANULARITY;
            o_data->poundw[POWERSAVE].vdm_vid_compare_ivid  =
                (i_poundv_data.VddPSVltg     - VDM_VOLTAGE_IN_MV ) / VDM_GRANULARITY;
            o_data->poundw[TURBO].vdm_vid_compare_ivid      =
                (i_poundv_data.VddTurboVltg  - VDM_VOLTAGE_IN_MV ) / VDM_GRANULARITY;
            o_data->poundw[ULTRA].vdm_vid_compare_ivid =
                (i_poundv_data.VddUTurboVltg - VDM_VOLTAGE_IN_MV ) / VDM_GRANULARITY;
        }//if any one of the VID compares are zero, then need to fail because of BAD VPD image.
        else if ( !(o_data->poundw[NOMINAL].vdm_vid_compare_ivid) ||
                  !(o_data->poundw[POWERSAVE].vdm_vid_compare_ivid) ||
                  !(o_data->poundw[TURBO].vdm_vid_compare_ivid) ||
                  !(o_data->poundw[ULTRA].vdm_vid_compare_ivid))
        {
            o_state->iv_vdm_enabled = false;
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_POUND_W_INVALID_VID_VALUE(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(i_target)
                               .set_NOMINAL_VID_COMPARE_IVID_VALUE(o_data->poundw[NOMINAL].vdm_vid_compare_ivid)
                               .set_POWERSAVE_VID_COMPARE_IVID_VALUE(o_data->poundw[POWERSAVE].vdm_vid_compare_ivid)
                               .set_TURBO_VID_COMPARE_IVID_VALUE(o_data->poundw[TURBO].vdm_vid_compare_ivid)
                               .set_ULTRA_VID_COMPARE_IVID_VALUE(o_data->poundw[ULTRA].vdm_vid_compare_ivid),
                               "Pstate Parameter Block #W : one of the VID compare value is zero");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            break;
        }

        FAPI_INF("POWERSAVE.vdm_vid_compare_ivid %d",o_data->poundw[POWERSAVE].vdm_vid_compare_ivid);
        FAPI_INF("NOMINAL.vdm_vid_compare_ivid %d",o_data->poundw[NOMINAL].vdm_vid_compare_ivid);
        FAPI_INF("TURBO.vdm_vid_compare_ivid %d",o_data->poundw[TURBO].vdm_vid_compare_ivid);
        FAPI_INF("ULTRA_TURBO.vdm_vid_compare_ivid %d",o_data->poundw[ULTRA].vdm_vid_compare_ivid);

        // validate vid values
        bool l_compare_vid_value_state = 1;
        VALIDATE_VID_VALUES (o_data->poundw[POWERSAVE].vdm_vid_compare_ivid,
                             o_data->poundw[NOMINAL].vdm_vid_compare_ivid,
                             o_data->poundw[TURBO].vdm_vid_compare_ivid,
                             o_data->poundw[ULTRA].vdm_vid_compare_ivid,
                             l_compare_vid_value_state);

        if (!l_compare_vid_value_state)
        {
            o_state->iv_vdm_enabled = false;
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_POUND_W_INVALID_VID_ORDER(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(i_target)
                               .set_NOMINAL_VID_COMPARE_IVID_VALUE(o_data->poundw[NOMINAL].vdm_vid_compare_ivid)
                               .set_POWERSAVE_VID_COMPARE_IVID_VALUE(o_data->poundw[POWERSAVE].vdm_vid_compare_ivid)
                               .set_TURBO_VID_COMPARE_IVID_VALUE(o_data->poundw[TURBO].vdm_vid_compare_ivid)
                               .set_ULTRA_VID_COMPARE_IVID_VALUE(o_data->poundw[ULTRA].vdm_vid_compare_ivid),
                               "Pstate Parameter Block #W VID compare data are not in increasing order");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            break;
        }

        // validate threshold values
        bool l_threshold_value_state = 1;

        for (uint8_t p = 0; p < NUM_OP_POINTS; ++p)
        {
            FAPI_INF("o_data->poundw[%d].vdm_overvolt_thresholds %d",p,(o_data->poundw[p].vdm_overvolt_small_thresholds >> 4) & 0x0F);
            FAPI_INF("o_data->poundw[%d].vdm_small_thresholds %d",p,(o_data->poundw[p].vdm_overvolt_small_thresholds ) & 0x0F);
            FAPI_INF("o_data->poundw[%d].vdm_large_thresholds %d",p,(o_data->poundw[p].vdm_large_extreme_thresholds >> 4) & 0x0F);
            FAPI_INF("o_data->poundw[%d].vdm_extreme_thresholds %d",p,(o_data->poundw[p].vdm_large_extreme_thresholds) & 0x0F);
            VALIDATE_THRESHOLD_VALUES(((o_data->poundw[p].vdm_overvolt_small_thresholds >> 4) & 0x0F), // overvolt
                                      ((o_data->poundw[p].vdm_overvolt_small_thresholds) & 0x0F), //small
                                      ((o_data->poundw[p].vdm_large_extreme_thresholds >> 4) & 0x0F), //large
                                      ((o_data->poundw[p].vdm_large_extreme_thresholds) & 0x0F), //extreme
                                      l_threshold_value_state);

            if (!l_threshold_value_state)
            {
                o_state->iv_vdm_enabled = false;
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_POUND_W_INVALID_THRESHOLD_VALUE(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CHIP_TARGET(i_target)
                                   .set_OP_POINT_TYPE(p)
                                   .set_VDM_OVERVOLT((o_data->poundw[p].vdm_overvolt_small_thresholds >> 4) & 0x0F)
                                   .set_VDM_SMALL(o_data->poundw[p].vdm_overvolt_small_thresholds & 0x0F)
                                   .set_VDM_EXTREME((o_data->poundw[p].vdm_large_extreme_thresholds >> 4) & 0x0F)
                                   .set_VDM_LARGE((o_data->poundw[p].vdm_large_extreme_thresholds) & 0x0F),
                                   "Pstate Parameter Block #W VDM threshold data are invalid");
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                break;
            }
        }

        bool l_frequency_value_state = 1;

        for (uint8_t p = 0; p < NUM_OP_POINTS; ++p)
        {
            // These fields are 4 bits wide, and stored in a uint8, hence the shifting
            // N_S, N_L, L_S, S_N
            FAPI_INF("o_data->poundw[%d] VDM_FREQ_DROP N_S = %d", p, ((o_data->poundw[p].vdm_small_large_normal_freq >> 4) & 0x0F));
            FAPI_INF("o_data->poundw[%d] VDM_FREQ_DROP N_L = %d", p, ((o_data->poundw[p].vdm_small_large_normal_freq) & 0x0F));
            FAPI_INF("o_data->poundw[%d] VDM_FREQ_DROP L_S = %d", p, ((o_data->poundw[p].vdm_large_small_normal_freq >> 4) & 0x0F));
            FAPI_INF("o_data->poundw[%d] VDM_FREQ_DROP S_N = %d", p, ((o_data->poundw[p].vdm_large_small_normal_freq) & 0x0F));

            VALIDATE_FREQUENCY_DROP_VALUES(((o_data->poundw[p].vdm_small_large_normal_freq) & 0x0F), //N_L
                                           ((o_data->poundw[p].vdm_small_large_normal_freq >> 4) & 0x0F), // N_S
                                           ((o_data->poundw[p].vdm_large_small_normal_freq >> 4) & 0x0F), //L_S
                                           ((o_data->poundw[p].vdm_large_small_normal_freq) & 0x0F), //S_N
                                           l_frequency_value_state);

            if (!l_frequency_value_state)
            {
                o_state->iv_vdm_enabled = false;
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_POUND_W_INVALID_FREQ_DROP_VALUE(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CHIP_TARGET(i_target)
                                   .set_OP_POINT_TYPE(p)
                                   .set_VDM_NORMAL_SMALL((o_data->poundw[p].vdm_small_large_normal_freq >> 4) & 0x0F)
                                   .set_VDM_NORMAL_LARGE(o_data->poundw[p].vdm_small_large_normal_freq & 0x0F)
                                   .set_VDM_LARGE_SMALL((o_data->poundw[p].vdm_large_small_normal_freq >> 4) & 0x0F)
                                   .set_VDM_SMALL_NORMAL((o_data->poundw[p].vdm_large_small_normal_freq) & 0x0F),
                                   "Pstate Parameter Block #W VDM frequency drop data are invalid");
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                break;
            }
        }

        //Biased compare vid data
        fapi2::ATTR_VDM_VID_COMPARE_BIAS_0P5PCT_Type l_bias_value;


        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_VID_COMPARE_BIAS_0P5PCT,
                               i_target,
                               l_bias_value),
                 "Error from FAPI_ATTR_GET for attribute ATTR_VDM_VID_COMPARE_BIAS_0P5PCT");

        float l_pound_w_points[NUM_OP_POINTS];

        for (uint8_t i = 0; i < NUM_OP_POINTS; i++)
        {
            l_pound_w_points[i]  = calc_bias(l_bias_value[i]);
            o_data->poundw[i].vdm_vid_compare_ivid =
                    (uint32_t)(o_data->poundw[i].vdm_vid_compare_ivid * l_pound_w_points[i]);

            FAPI_INF("vdm_vid_compare_ivid %x %x, %x",
                        o_data->poundw[i].vdm_vid_compare_ivid,
                        o_data->poundw[i].vdm_vid_compare_ivid,
                        l_pound_w_points[i]);
        }


        memcpy(&(o_vdmpb->vpd_w_data), o_data, sizeof(o_vdmpb->vpd_w_data));
    }
    while(0);


fapi_try_exit:

    // Given #W has both VDM and WOF content, a failure needs to disable both
    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        o_state->iv_vdm_enabled = false;
        o_state->iv_wof_enabled = false;
    }
    FAPI_DBG("<< proc_get_mvpd_poundw");
    return fapi2::current_err;

}


fapi2::ReturnCode
proc_set_resclk_table_attrs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                      PSTATE_attribute_state* o_state)
{
    uint8_t l_resclk_freq_index[RESCLK_FREQ_REGIONS];
    uint8_t l_l3_steparray[RESCLK_L3_STEPS];
    uint16_t l_resclk_freq_regions[RESCLK_FREQ_REGIONS];
    uint16_t l_resclk_value[RESCLK_STEPS];
    uint16_t l_l3_threshold_mv;
    o_state->iv_resclk_enabled = true;

    do
    {
        // Perform some basic sanity checks on the header data structures (since
        // the header values are provided by another team)
        FAPI_ASSERT_NOEXIT((p9_resclk_defines::RESCLK_INDEX_VEC.size() == RESCLK_FREQ_REGIONS),
                fapi2::PSTATE_PB_RESCLK_INDEX_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                .set_FREQ_REGIONS(RESCLK_FREQ_REGIONS)
                .set_INDEX_VEC_SIZE(p9_resclk_defines::RESCLK_INDEX_VEC.size()),
                "p9_resclk_defines.h RESCLK_INDEX_VEC.size() mismatch");

        FAPI_ASSERT_NOEXIT((p9_resclk_defines::RESCLK_TABLE_VEC.size() == RESCLK_STEPS),
                fapi2::PSTATE_PB_RESCLK_TABLE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                    .set_STEPS(RESCLK_STEPS)
                    .set_TABLE_VEC_SIZE(p9_resclk_defines::RESCLK_TABLE_VEC.size()),
                    "p9_resclk_defines.h RESCLK_TABLE_VEC.size() mismatch");

        FAPI_ASSERT_NOEXIT((p9_resclk_defines::L3CLK_TABLE_VEC.size() == RESCLK_L3_STEPS),
                    fapi2::PSTATE_PB_RESCLK_L3_TABLE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                    .set_L3_STEPS(RESCLK_L3_STEPS)
                    .set_L3_VEC_SIZE(p9_resclk_defines::L3CLK_TABLE_VEC.size()),
                    "p9_resclk_defines.h L3CLK_TABLE_VEC.size() mismatch");
        //FAPI_ASSERT_NOEXIT will log an error with recoverable.. but rc won't be
        //cleared.. So we are initializing again to continue further
        if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
        {
            o_state->iv_resclk_enabled = false;
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            break;
        }


        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VALUE, i_target,
                               l_l3_steparray));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGIONS, i_target,
                               l_resclk_freq_regions));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGION_INDEX, i_target,
                               l_resclk_freq_index));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_VALUE, i_target,
                               l_resclk_value));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV, i_target,
                               l_l3_threshold_mv));

        for (uint8_t i = 0; i < RESCLK_FREQ_REGIONS; ++i)
        {
            if (l_resclk_freq_regions[i] == 0)
            {
                l_resclk_freq_regions[i] = p9_resclk_defines::RESCLK_INDEX_VEC.at(i).freq;
            }

            if (l_resclk_freq_index[i] == 0)
            {
                l_resclk_freq_index[i] = p9_resclk_defines::RESCLK_INDEX_VEC.at(i).idx;
            }
        }

        for (uint8_t i = 0; i < RESCLK_STEPS; ++i)
        {
            if (l_resclk_value[i] == 0)
            {
                l_resclk_value[i] = p9_resclk_defines::RESCLK_TABLE_VEC.at(i);
            }
        }

        for (uint8_t i = 0; i < RESCLK_L3_STEPS; ++i)
        {
            if (l_l3_steparray[i] == 0)
            {
                l_l3_steparray[i] = p9_resclk_defines::L3CLK_TABLE_VEC.at(i);
            }
        }

        if(l_l3_threshold_mv == 0)
        {
            l_l3_threshold_mv = p9_resclk_defines::L3_VOLTAGE_THRESHOLD_MV;
        }

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_L3_VALUE, i_target,
                               l_l3_steparray));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGIONS, i_target,
                               l_resclk_freq_regions));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGION_INDEX, i_target,
                               l_resclk_freq_index));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_VALUE, i_target,
                               l_resclk_value));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV, i_target,
                               l_l3_threshold_mv));
    }while(0);

fapi_try_exit:
    return fapi2::current_err;
}

//@brief Initialize HOMER VFRT data
void p9_pstate_update_vfrt(const GlobalPstateParmBlock* i_gppb,
                           uint8_t* i_pBuffer,
                           HomerVFRTLayout_t* o_vfrt_data,
                           uint32_t i_reference_freq)
{
    uint32_t l_index_0 = 0;
    uint32_t l_index_1 = 0;
    uint8_t  l_type = 0;
    uint32_t l_freq_khz = 0;
    uint32_t l_step_freq_khz;
    Pstate   l_ps;

    l_step_freq_khz = revle32(i_gppb->frequency_step_khz);

    //Initialize VFRT header
    o_vfrt_data->vfrtHeader.magic_number = revle16(UINT16_GET(i_pBuffer));
    i_pBuffer += 2;
    o_vfrt_data->vfrtHeader.reserved     = revle16(UINT16_GET(i_pBuffer));
    i_pBuffer += 2;
    o_vfrt_data->vfrtHeader.type_version = *i_pBuffer;
    i_pBuffer++;
    o_vfrt_data->vfrtHeader.res_vdnId    = *i_pBuffer;  // @todo this name is not accurate
    i_pBuffer++;
    o_vfrt_data->vfrtHeader.VddId_QAId   = *i_pBuffer;  // @todo this name is not accurate
    i_pBuffer++;
    o_vfrt_data->vfrtHeader.rsvd_QAId    = *i_pBuffer;
    i_pBuffer++;


    //find type
    l_type = (o_vfrt_data->vfrtHeader.type_version) >> 4;

    // @todo RTC 175631
    // This doesn't have the correct error checking in place!!!!!
    // This function should exit if the input type is not "SYSTEM"
    // Correct in Level 3 update.

    char            l_buffer_str[256];   // Temporary formatting string buffer
    char            l_line_str[256];     // Formatted output line string

    strcpy(l_line_str, "VFRT:");
    sprintf(l_buffer_str, " %X Ver/Type %X B5 %X B6 %X  B7 %X",
            revle16(o_vfrt_data->vfrtHeader.magic_number),
            revle16(o_vfrt_data->vfrtHeader.type_version),
            o_vfrt_data->vfrtHeader.res_vdnId,   /// BUG:  this should be VDN!!!
            o_vfrt_data->vfrtHeader.VddId_QAId,    /// BUG:  this should be VDD!!!
            o_vfrt_data->vfrtHeader.rsvd_QAId);  /// BUG:  this should be resvQID!!!
    strcat(l_line_str, l_buffer_str);
    FAPI_INF("%s", l_line_str);

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    fapi2::ATTR_WOF_ENABLE_FRATIO_Type l_enable_fratio;
    FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLE_FRATIO,
                  FAPI_SYSTEM,
                  l_enable_fratio);

    fapi2::ATTR_WOF_ENABLE_VRATIO_Type l_enable_vratio;
    FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLE_VRATIO,
                  FAPI_SYSTEM,
                  l_enable_vratio);

    bool b_fratio_set = true;

    //Initialize VFRT data part
    for (l_index_0 = 0; l_index_0 < VFRT_FRATIO_SIZE; ++l_index_0)
    {
        strcpy(l_buffer_str, "");
        strcpy(l_line_str, "    ");

        bool b_first_vratio_set = true;

        for (l_index_1 = 0; l_index_1 < VFRT_VRATIO_SIZE; ++l_index_1)
        {
            // Offset MHz*1000 (khz) + step (khz) * sysvalue
            l_freq_khz = 1000 * 1000 + (l_step_freq_khz * (*i_pBuffer));

            // Translate to Pstate.  The called function will clip to the
            // legal range.  The rc is only interesting if we care that
            // the pstate was clipped;  in this case, we don't.
            freq2pState(i_gppb, l_freq_khz, &l_ps);

            o_vfrt_data->vfrt_data[l_index_0][l_index_1] = l_ps;

            sprintf(l_buffer_str, "[%2d][%2d] %2d %4d; ",
                    l_index_0, l_index_1,
                    l_ps,  l_freq_khz / 1000);
            strcat(l_line_str, l_buffer_str);

            // Trace the first 8 values of the 24 for debug. As this is
            // in a loop that is processing over 1000 tables, the first
            // 8 gives a view that can correlate that the input data read
            // is correct without overfilling the HB trace buffer.
            if (!((l_index_1 + 1) % 8) && b_first_vratio_set && b_fratio_set)
            {
                FAPI_INF("%s", l_line_str);
                strcpy(l_buffer_str, "");
                strcpy(l_line_str, "    ");
                b_first_vratio_set = false;
            }

            i_pBuffer++;
        }

        // If fratio is not enabled, don't trace the remaining, duplicate entries.
        if (!l_enable_fratio)
            b_fratio_set = false;

    }

    // Flip the type from System (0) to HOMER (1)
    l_type = 1;
    o_vfrt_data->vfrtHeader.type_version |=  l_type << 4;

}

/// Get IAC VDN vlue
uint16_t get_iac_vdn_value (uint16_t i_vpd_vdn_mv,
                            IddqTable i_iddq,
                            uint8_t nest_leakage_percent,
                            uint16_t i_vpd_idn_100ma)
{
    uint16_t l_ac_vdn_value = 0;
    uint8_t l_iddq_index = 0;
    const uint8_t MIN_IDDQ_VALUE = 6; //considering 0.6 as 6 here for easy math
    const uint16_t IDDQ_MIN_VOLT_LEVEL = 600;
    uint8_t l_measured_temp_C[2] = {0};
    uint8_t l_Ivdnq_5ma[2] = {0};
    float l_scaled_leakage_ma[2] = {0};
    uint16_t l_Ivdnq_vpd_ma = 0;
    uint8_t i = 0;
    uint8_t j = 0;

    //check bonunding is required or not
    uint16_t l_bounding_value = i_vpd_vdn_mv % 100;
    //Index to read from IDDQ table
    //Assumption here i_vpd_vdn_mv value will be greater than 600 and lesser
    //than 1100 mv
    l_iddq_index = (i_vpd_vdn_mv / 100) - MIN_IDDQ_VALUE;
    i = l_iddq_index;
    j = l_iddq_index + 1;
    uint16_t l_iq_mv[2] = {0};
    l_iq_mv[0] = IDDQ_MIN_VOLT_LEVEL + (100 * i);
    l_iq_mv[1] = IDDQ_MIN_VOLT_LEVEL + (100 * (i + 1));
    uint8_t l_diff_value = 0;
    do
    {
        if (!l_bounding_value)
        {
            //Read measured temp
            l_measured_temp_C[0] = i_iddq.avgtemp_vdn[i];

            if ((l_measured_temp_C[0] == 0))
            {
                FAPI_INF("Non Bounded measured temp value is 0");
                break;
            }
            else if (l_measured_temp_C[0] < nest_leakage_percent)
            {
                l_diff_value = nest_leakage_percent - l_measured_temp_C[0];
            }
            else
            {
                l_diff_value = l_measured_temp_C[0] - nest_leakage_percent;
            }

            //Read ivdnq_5ma
            l_Ivdnq_5ma[0] = i_iddq.ivdn[i];

            //Scale each bounding Ivdnq_5ma value to 75C in mA

            l_scaled_leakage_ma[0] = l_Ivdnq_5ma[0] * 5 * pow (1.3, (l_diff_value / 10));

            l_Ivdnq_vpd_ma = l_scaled_leakage_ma[0];

            l_ac_vdn_value = (i_vpd_idn_100ma * 10) - (l_Ivdnq_vpd_ma * 10);
        }
        else
        {
            //Read measured temp
            l_measured_temp_C[0] = i_iddq.avgtemp_vdn[i];
            l_measured_temp_C[1] = i_iddq.avgtemp_vdn[i + 1];

            //Read ivdnq_5ma
            l_Ivdnq_5ma[0] = i_iddq.ivdn[i];
            l_Ivdnq_5ma[1] = i_iddq.ivdn[i + 1];

            //Scale each bounding Ivdnq_5ma value to 75C in mA

            for (j = 0; j < 2; j++)
            {
                if ((l_measured_temp_C[j] == 0))
                {
                    FAPI_INF("Bounded measured temp value is 0");
                    break;
                }
                else if (l_measured_temp_C[j] < nest_leakage_percent)
                {
                    l_diff_value = nest_leakage_percent - l_measured_temp_C[j];
                }
                else
                {
                    l_diff_value = l_measured_temp_C[j] - nest_leakage_percent;
                }

                l_scaled_leakage_ma[j] = l_Ivdnq_5ma[j] * 5 * pow (1.3, (l_diff_value / 10));
            }

            //Interpolate between scaled_leakage_ma[i] and scaled_leakage_ma[i+1]
            //using the same ratio as the VPD voltage is to the bounding volages) to
            //arrive at  Ivdnq_vpd_ma
            l_Ivdnq_vpd_ma = l_scaled_leakage_ma[i] + roundUp((i_vpd_vdn_mv - 600 + (100 * i)) / ((l_iq_mv[1] - l_iq_mv[0]) *
                             (l_scaled_leakage_ma[1] - l_scaled_leakage_ma[0])));

            l_ac_vdn_value = (i_vpd_idn_100ma * 10) - (l_Ivdnq_vpd_ma * 10);
        }
    }while(0);

    return l_ac_vdn_value;
}
/**
 * calculate_effective_capacitance
 *
 * Description: Generic function to perform the effective capacitance
 *              calculations.
 *              C_eff = I / (V^1.3 * F)
 *
 *              I is the AC component of Idd in 0.01 Amps (or10 mA)
 *              V is the silicon voltage in 100 uV
 *              F is the frequency in MHz
 *
 *              Note: Caller must ensure they check for a 0 return value
 *                    and disable wof if that is the case
 *
 * Param[in]: i_iAC - the AC component
 * Param[in]: i_voltage - the voltage component in 100uV
 * Param[in]: i_frequency - the frequency component
 *
 * Return: The calculated effective capacitance
 */
uint16_t pstate_calculate_effective_capacitance( uint16_t i_iAC,
        uint16_t i_voltage,
        uint16_t i_frequency )
{

    // Compute V^1.3 using a best-fit equation
    // (V^1.3) = (21374 * (voltage in 100uV) - 50615296)>>10
    uint32_t v_exp_1_dot_3 = (21374 * i_voltage - 50615296) >> 10;

    // Compute I / (V^1.3)
    uint32_t I = i_iAC << 14; // * 16384

    // Prevent divide by zero
    if( v_exp_1_dot_3 == 0 )
    {
        // Return 0 causing caller to disable wof.
        return 0;
    }

    uint32_t c_eff = (I / v_exp_1_dot_3);
    c_eff = c_eff << 14; // * 16384

    // Divide by frequency and return the final value.
    // (I / (V^1.3 * F)) == I / V^1.3 /F
    return c_eff / i_frequency;

}

uint16_t roundUp(float i_value)
{
    return ((uint16_t)(i_value == (uint16_t)i_value ? i_value : i_value + 1));
}
//
// p9_pstate_compute_vdm_threshold_pts
//
void p9_pstate_compute_vdm_threshold_pts(PoundW_data i_data,
        LocalPstateParmBlock* io_lppb)
{
    int p = 0;

    //VID POINTS
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        io_lppb->vid_point_set[p] = i_data.poundw[p].vdm_vid_compare_ivid;
        FAPI_INF("Bi:VID=%x", io_lppb->vid_point_set[p]);
    }

    // Threshold points
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        // overvolt threshold
        io_lppb->threshold_set[p][0] = g_GreyCodeIndexMapping[(i_data.poundw[p].vdm_overvolt_small_thresholds >> 4) & 0x0F];

        FAPI_INF("Bi: OV TSHLD =%d", io_lppb->threshold_set[p][0]);
        // small threshold
        io_lppb->threshold_set[p][1] = (g_GreyCodeIndexMapping[i_data.poundw[p].vdm_overvolt_small_thresholds  & 0x0F]);

        FAPI_INF("Bi: SM TSHLD =%d", io_lppb->threshold_set[p][1]);
        // large threshold
        io_lppb->threshold_set[p][2] =  (g_GreyCodeIndexMapping[(i_data.poundw[p].vdm_large_extreme_thresholds >> 4) & 0x0F]);

        FAPI_INF("Bi: LG TSHLD =%d", io_lppb->threshold_set[p][2]);
        // extreme threshold
        io_lppb->threshold_set[p][3] =  (g_GreyCodeIndexMapping[i_data.poundw[p].vdm_large_extreme_thresholds & 0x0F]);

        FAPI_INF("Bi: EX TSHLD =%d", io_lppb->threshold_set[p][3]);

    }
    // Jump value points
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        // N_L value
        io_lppb->jump_value_set[p][0] = (i_data.poundw[p].vdm_small_large_normal_freq >> 4) & 0x0F;

        FAPI_INF("Bi: N_S =%d", io_lppb->jump_value_set[p][0]);
        // N_S value
        io_lppb->jump_value_set[p][1] = i_data.poundw[p].vdm_small_large_normal_freq & 0x0F;

        FAPI_INF("Bi: N_L =%d", io_lppb->jump_value_set[p][1]);
        // L_S value
        io_lppb->jump_value_set[p][2] =  (i_data.poundw[p].vdm_large_small_normal_freq >> 4) & 0x0F;

        FAPI_INF("Bi: L_S =%d", io_lppb->jump_value_set[p][2]);
        // S_L value
        io_lppb->jump_value_set[p][3] =  i_data.poundw[p].vdm_large_small_normal_freq & 0x0F;

        FAPI_INF("Bi: S_L =%d", io_lppb->jump_value_set[p][3]);
    }
}
//
//
// p9_pstate_compute_PsVIDCompSlopes_slopes
//
void p9_pstate_compute_PsVIDCompSlopes_slopes(PoundW_data i_data,
        LocalPstateParmBlock* io_lppb,
        uint8_t* i_pstate)
{
    do
    {
        char const* region_names[] = { "REGION_POWERSAVE_NOMINAL",
                                       "REGION_NOMINAL_TURBO",
                                       "REGION_TURBO_ULTRA"
                                     };

        // ULTRA TURBO pstate check is not required..because its pstate will be
        // 0
        if (!(i_pstate[POWERSAVE]) ||
            !(i_pstate[NOMINAL]) ||
            !(i_pstate[TURBO]))
        {
            FAPI_ERR("Non-UltraTurbo PSTATE value shouldn't be zero");
            break;
        }

        for(auto region(REGION_POWERSAVE_NOMINAL); region <= REGION_TURBO_ULTRA; ++region)
        {
            io_lppb->PsVIDCompSlopes[region] =
                revle16(
                    compute_slope_4_12( io_lppb->vid_point_set[region + 1],
                                        io_lppb->vid_point_set[region],
                                        i_pstate[region],
                                        i_pstate[region + 1])
                );

            FAPI_DBG("PsVIDCompSlopes[%s] 0x%04x %d", region_names[region],
                     revle16(io_lppb->PsVIDCompSlopes[region]),
                     revle16(io_lppb->PsVIDCompSlopes[region]));
        }
    }
    while(0);
}

//
//
// p9_pstate_compute_PsVDMThreshSlopes
//
void p9_pstate_compute_PsVDMThreshSlopes(
    LocalPstateParmBlock* io_lppb,
    uint8_t* i_pstate)
{
    do
    {
        // ULTRA TURBO pstate check is not required..because its pstate will be
        // 0
        if (!(i_pstate[POWERSAVE]) ||
            !(i_pstate[NOMINAL]) ||
            !(i_pstate[TURBO]))
        {
            FAPI_ERR("Non-UltraTurbo PSTATE value shouldn't be zero");
            break;
        }

        for(auto region(REGION_POWERSAVE_NOMINAL); region <= REGION_TURBO_ULTRA; ++region)
        {
            for (uint8_t i = 0; i < NUM_THRESHOLD_POINTS; ++i)
            {
                io_lppb->PsVDMThreshSlopes[region][i] =
                  revle16(
                        compute_slope_thresh(io_lppb->threshold_set[region+1][i],
                                             io_lppb->threshold_set[region][i],
                                             i_pstate[region],
                                             i_pstate[region+1])
                    );

                FAPI_INF("PsVDMThreshSlopes %s %x TH_N %d TH_P %d PS_P %d PS_N %d",
                         prt_region_names[region],
                         revle16(io_lppb->PsVDMThreshSlopes[region][i]),
                         io_lppb->threshold_set[region+1][i],
                         io_lppb->threshold_set[region][i],
                         i_pstate[region],
                         i_pstate[region+1]);
            }
        }
    }
    while(0);
}

//
// p9_pstate_compute_PsVDMJumpSlopes
//
void p9_pstate_compute_PsVDMJumpSlopes(
    LocalPstateParmBlock* io_lppb,
    uint8_t* i_pstate)
{
    do
    {
        // ULTRA TURBO pstate check is not required..because its pstate will be
        // 0
        if (!(i_pstate[POWERSAVE]) ||
            !(i_pstate[NOMINAL]) ||
            !(i_pstate[TURBO]))
        {
            FAPI_ERR("Non-UltraTurbo PSTATE value shouldn't be zero");
            break;
        }

        //Calculate slopes
        //
        for(auto region(REGION_POWERSAVE_NOMINAL); region <= REGION_TURBO_ULTRA; ++region)
        {
            for (uint8_t i = 0; i < NUM_JUMP_VALUES; ++i)
            {
                io_lppb->PsVDMJumpSlopes[region][i] =
                  revle16(
                        compute_slope_thresh(io_lppb->jump_value_set[region+1][i],
                                             io_lppb->jump_value_set[region][i],
                                             i_pstate[region],
                                             i_pstate[region+1])
                    );

                FAPI_INF("PsVDMJumpSlopes %s %x N_S %d N_L %d L_S %d S_N %d",
                         prt_region_names[region],
                         revle16(io_lppb->PsVDMJumpSlopes[region][i]),
                         io_lppb->jump_value_set[region+1][i],
                         io_lppb->jump_value_set[region][i],
                         i_pstate[region],
                         i_pstate[region+1]);
            }
        }
    }
    while(0);
}
// p9_pstate_set_global_feature_attributes
fapi2::ReturnCode
p9_pstate_set_global_feature_attributes(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                        PSTATE_attribute_state i_state,
                                        QuadManagerFlags* o_qm_flags)
{
    // Quad Manager Flags
    fapi2::buffer<uint16_t> l_data16;

    fapi2::ATTR_PSTATES_ENABLED_Type l_ps_enabled =
        (fapi2::ATTR_PSTATES_ENABLED_Type)fapi2::ENUM_ATTR_PSTATES_ENABLED_FALSE;

    fapi2::ATTR_RESCLK_ENABLED_Type l_resclk_enabled =
        (fapi2::ATTR_RESCLK_ENABLED_Type)fapi2::ENUM_ATTR_RESCLK_ENABLED_FALSE;

    fapi2::ATTR_VDM_ENABLED_Type l_vdm_enabled =
        (fapi2::ATTR_VDM_ENABLED_Type)fapi2::ENUM_ATTR_VDM_ENABLED_FALSE;

    fapi2::ATTR_IVRM_ENABLED_Type l_ivrm_enabled =
        (fapi2::ATTR_IVRM_ENABLED_Type)fapi2::ENUM_ATTR_IVRM_ENABLED_FALSE;

    fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled =
        (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_FALSE;

    if (i_state.iv_pstates_enabled)
    {
        l_ps_enabled = (fapi2::ATTR_PSTATES_ENABLED_Type)fapi2::ENUM_ATTR_PSTATES_ENABLED_TRUE;
    }

    if (i_state.iv_resclk_enabled)
    {
        l_resclk_enabled = (fapi2::ATTR_RESCLK_ENABLED_Type)fapi2::ENUM_ATTR_RESCLK_ENABLED_TRUE;
    }

    if (i_state.iv_vdm_enabled)
    {
        l_vdm_enabled = (fapi2::ATTR_VDM_ENABLED_Type)fapi2::ENUM_ATTR_VDM_ENABLED_TRUE;
    }

    if (i_state.iv_ivrm_enabled)
    {
        l_ivrm_enabled = (fapi2::ATTR_IVRM_ENABLED_Type)fapi2::ENUM_ATTR_IVRM_ENABLED_TRUE;
    }

    if (i_state.iv_wof_enabled)
    {
        l_wof_enabled = (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_TRUE;
    }


#define SET_ATTR(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_SET(attr_name, target, attr_assign),"Attribute set failed"); \
FAPI_INF("%-60s = 0x%08x %d", #attr_name, attr_assign, attr_assign);

    SET_ATTR(fapi2::ATTR_PSTATES_ENABLED, i_target, l_ps_enabled);
    SET_ATTR(fapi2::ATTR_RESCLK_ENABLED, i_target, l_resclk_enabled);
    SET_ATTR(fapi2::ATTR_VDM_ENABLED, i_target, l_vdm_enabled);
    SET_ATTR(fapi2::ATTR_IVRM_ENABLED, i_target, l_ivrm_enabled);
    SET_ATTR(fapi2::ATTR_WOF_ENABLED, i_target, l_wof_enabled);


    // ----------------
    // set CME QM flags
    // ----------------
    l_data16.flush<0>();

    l_data16.insertFromRight<0, 1>(l_resclk_enabled);
    l_data16.insertFromRight<1, 1>(l_ivrm_enabled);
    l_data16.insertFromRight<2, 1>(l_vdm_enabled);
    l_data16.insertFromRight<3, 1>(l_wof_enabled);


    // DROOP_PROTECT          -> DPLL Mode 3
    // DROOP_PROTECT_OVERVOLT -> DPLL Mode 3.5
    // DYNAMIC                -> DPLL Mode 4
    // DYNAMIC_PROTECT        -> DPLL Mode 5

    //                     enable_fmin    enable_fmax   enable_jump
    // DPLL Mode  2             0              0             0
    // DPLL Mode  3             0              0             1
    // DPLL Mode  4             X              1             0
    // DPLL Mode  4             1              X             0
    // DPLL Mode  3.5           0              1             1
    // DPLL Mode  5             1              X             1

    switch (attr.attr_dpll_vdm_response)
    {
        case fapi2::ENUM_ATTR_DPLL_VDM_RESPONSE_DROOP_PROTECT:
            l_data16 |= CME_QM_FLAG_SYS_JUMP_PROTECT;
            FAPI_INF("%-60s", "DPLL Response");
            FAPI_INF("%-60s = Set", "CME_QM_FLAG_SYS_JUMP_PROTECT");
            break;
        case fapi2::ENUM_ATTR_DPLL_VDM_RESPONSE_DROOP_PROTECT_OVERVOLT:
            l_data16 |= CME_QM_FLAG_SYS_DYN_FMAX_ENABLE;
            l_data16 |= CME_QM_FLAG_SYS_JUMP_PROTECT;
            FAPI_INF("%-60s", "DPLL Response");
            FAPI_INF("%-60s = Set", "CME_QM_FLAG_SYS_DYN_FMAX_ENABLE");
            FAPI_INF("%-60s = Set", "CME_QM_FLAG_SYS_JUMP_PROTECT");
            break;
        case fapi2::ENUM_ATTR_DPLL_VDM_RESPONSE_DYNAMIC:
            l_data16 |= CME_QM_FLAG_SYS_DYN_FMIN_ENABLE;
            l_data16 |= CME_QM_FLAG_SYS_DYN_FMAX_ENABLE;
            FAPI_INF("%-60s", "DPLL Response");
            FAPI_INF("%-60s = Set", "CME_QM_FLAG_SYS_DYN_FMIN_ENABLEE");
            FAPI_INF("%-60s = Set", "CME_QM_FLAG_SYS_DYN_FMAX_ENABLE");
            break;
        case fapi2::ENUM_ATTR_DPLL_VDM_RESPONSE_DYNAMIC_PROTECT:
            l_data16 |= CME_QM_FLAG_SYS_DYN_FMIN_ENABLE;
            l_data16 |= CME_QM_FLAG_SYS_JUMP_PROTECT;
            FAPI_INF("%-60s", "DPLL Response");
            FAPI_INF("%-60s = Set", "CME_QM_FLAG_SYS_DYN_FMIN_ENABLE");
            FAPI_INF("%-60s = Set", "CME_QM_FLAG_SYS_JUMP_PROTECT");
            break;
    }

    o_qm_flags->value = revle16(l_data16);
    FAPI_INF("%-60s = 0x%04x %d", "QM Flags", revle16(o_qm_flags->value));

fapi_try_exit:
    return fapi2::current_err;
}

//large_jump_interpolate
uint32_t large_jump_interpolate (const Pstate i_pstate,const uint32_t i_attr_mvpd_data[PV_D][PV_W],
                                 const uint32_t i_step_frequency, const Pstate i_ps_pstate,
                                 const PoundW_data i_data)
{
    VpdOperatingPoint operating_points[NUM_OP_POINTS];
    load_mvpd_operating_point(i_attr_mvpd_data, operating_points, i_step_frequency);
    uint8_t l_jump_value_set_ps = (i_data.poundw[POWERSAVE].vdm_small_large_normal_freq >> 4) & 0x0F;
    uint8_t l_jump_value_set_nom = (i_data.poundw[NOMINAL].vdm_small_large_normal_freq >> 4) & 0x0F;

    uint32_t l_slope_value = compute_slope_thresh(l_jump_value_set_nom,l_jump_value_set_ps,
                                                  operating_points[POWERSAVE].pstate,
                                                  operating_points[NOMINAL].pstate);

    uint32_t l_vdm_jump_value = (uint32_t)((int32_t)l_jump_value_set_ps + (((int32_t)l_slope_value *
                                (i_ps_pstate - i_pstate)) >> THRESH_SLOPE_FP_SHIFT));
   return l_vdm_jump_value;
}

//pstate2voltage
uint32_t pstate2voltage(const Pstate i_pstate,
                        const uint32_t i_attr_mvpd_data[PV_D][PV_W],
                        const uint32_t i_step_frequency)
{
    VpdOperatingPoint operating_points[NUM_OP_POINTS];
    load_mvpd_operating_point(i_attr_mvpd_data, operating_points, i_step_frequency);

    uint32_t l_SlopeValue = revle16(compute_slope_4_12(revle32(operating_points[NOMINAL].vdd_mv),
                                               revle32(operating_points[POWERSAVE].vdd_mv),
                                               operating_points[POWERSAVE].pstate,
                                               operating_points[NOMINAL].pstate));

    FAPI_INF("l_globalppb.operating_points[NOMINAL].vdd_mv %x",revle32(operating_points[NOMINAL].vdd_mv));
    FAPI_INF("l_globalppb.operating_points[POWERSAVE].vdd_mv%x",revle32(operating_points[POWERSAVE].vdd_mv));
    FAPI_INF("l_globalppb.operating_points[NOMINAL].pstate %x",operating_points[NOMINAL].pstate);
    FAPI_INF("l_globalppb.operating_points[POWERSAVE].pstate %x",operating_points[POWERSAVE].pstate);

    FAPI_INF ("l_SlopeValue %x",l_SlopeValue);


    uint32_t l_vdd = (( (l_SlopeValue * (-i_pstate + operating_points[POWERSAVE].pstate)) >>
                      VID_SLOPE_FP_SHIFT_12) + revle32(operating_points[POWERSAVE].vdd_mv));

    FAPI_INF ("l_vdd %x",l_vdd);

    return l_vdd;
}

//p9_pstate_safe_mode_computation
fapi2::ReturnCode
p9_pstate_safe_mode_computation(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                const uint32_t i_attr_mvpd_data[PV_D][PV_W],const uint32_t i_reference_freq,
                                const uint32_t i_step_frequency,
                                const Pstate i_ps_pstate,
                                Safe_mode_parameters *o_safe_mode_values,
                                const PoundW_data i_poundw_data)
{
    Safe_mode_parameters l_safe_mode_values;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_safe_mode_freq;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type l_safe_mode_mv;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ, FAPI_SYSTEM, l_safe_mode_values.safe_op_freq_mhz));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ, i_target, l_safe_mode_freq));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV, i_target, l_safe_mode_mv));

    FAPI_INF ("l_safe_mode_values.safe_op_freq_mhz %08x",l_safe_mode_values.safe_op_freq_mhz);
    FAPI_INF ("i_reference_freq %08x",i_reference_freq);
    FAPI_INF ("i_step_frequency %08x",i_step_frequency);

    // Calculate safe op pstate for Power save
    l_safe_mode_values.safe_op_ps = ((float)(i_reference_freq) -
                                     (float)(l_safe_mode_values.safe_op_freq_mhz * 1000)) /
                                     (float)i_step_frequency;
    FAPI_INF("l_safe_mode_values.safe_op_ps %x",l_safe_mode_values.safe_op_ps);

    // Calculate safe jump value for large frequency
    l_safe_mode_values.safe_vdm_jump_value = large_jump_interpolate
                                            (l_safe_mode_values.safe_op_ps,
                                             i_attr_mvpd_data, i_step_frequency,
                                             i_ps_pstate, i_poundw_data);
    FAPI_INF ("l_safe_mode_values.safe_vdm_jump_value %x",l_safe_mode_values.safe_vdm_jump_value);


    // Calculate safe mode freq
    l_safe_mode_values.safe_mode_freq_mhz = ((1 + l_safe_mode_values.safe_vdm_jump_value /32) *
                                              l_safe_mode_values.safe_op_freq_mhz  /
                                             (i_step_frequency / 1000)) *  //converting from khz to mhz
                                             (i_step_frequency / 1000);


    if (l_safe_mode_freq)
    {
        l_safe_mode_values.safe_mode_freq_mhz = l_safe_mode_freq;
        FAPI_INF("Applying override safe mode freq value");
    }
    else
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ, i_target, l_safe_mode_values.safe_mode_freq_mhz));
    }
    FAPI_INF ("l_safe_mode_values.safe_mode_freq_mhz %0x",l_safe_mode_values.safe_mode_freq_mhz);


    l_safe_mode_values.safe_mode_ps = ((float)(i_reference_freq) -
                                       (float)(l_safe_mode_values.safe_mode_freq_mhz * 1000)) /
                                       (float)i_step_frequency;

    FAPI_INF ("l_safe_mode_values.safe_mode_ps %x",l_safe_mode_values.safe_mode_ps);

    // Calculate safe mode voltage
    l_safe_mode_values.safe_mode_mv = pstate2voltage(l_safe_mode_values.safe_mode_ps,
                                                     i_attr_mvpd_data,
                                                     i_step_frequency);


    if (l_safe_mode_mv)
    {
        l_safe_mode_values.safe_mode_mv = l_safe_mode_mv;
        FAPI_INF("Applying override safe mode voltage value");
    }
    else
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV, i_target, l_safe_mode_values.safe_mode_mv));
    }

    FAPI_INF ("l_safe_mode_values.safe_mode_mv %x",l_safe_mode_values.safe_mode_mv);


    fapi2::ATTR_SAFE_MODE_NOVDM_UPLIFT_MV_Type l_uplift_mv;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_NOVDM_UPLIFT_MV, i_target, l_uplift_mv));

    // Calculate boot mode voltage
    l_safe_mode_values.boot_mode_mv = l_safe_mode_values.safe_mode_mv + l_uplift_mv;

    FAPI_INF("l_safe_mode_values.boot_mode_mv %x",l_safe_mode_values.boot_mode_mv);

    memcpy (o_safe_mode_values,&l_safe_mode_values, sizeof(Safe_mode_parameters));

fapi_try_exit:
    return fapi2::current_err;
}
// *INDENT-ON*
