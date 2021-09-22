/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pstate_parameter_block.C $ */
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
/// @file  p10_pstate_parameter_block.C
/// @brief Setup Pstate super structure for PGPE/CME HCode
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
/// *HWP Consumed by     : HB,PGPE,OCC
///
/// @verbatim
/// Procedure Summary:
///   - Read VPD and attributes to create the Pstate Parameter Block(s) (one each for PGPE and OCC).
/// @endverbatim

// *INDENT-OFF*
//
// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pstate_parameter_block.H>
#include <p10_setup_evid.H>
#include <p10_pm_set_system_freq.H>
#include <p10_pm_utils.H>
#include <mvpd_access_defs.H>
#include <fapi2_subroutine_executor.H>

#ifdef __HOSTBOOT_MODULE
    #include <util/misc.H>                   // Util::isSimicsRunning
#endif

using namespace pm_pstate_parameter_block;

#define IQ_BUFFER_ALLOC            255
#define PSTATE_MAX                 255
#define PSTATE_MIN                 0
#define PROC_PLL_DIVIDER           8
#define CF1_3_PERCENTAGE           0.33
#define CF2_4_PERCENTAGE           0.50
#define NORMAL                     0
#define INVERTED                   1

#define POUNDV_POINT_CALC(VAL,X,Y,Z)     if (VAL == 0) {VAL = ( (Y - X) * Z) + X; }


#define POUNDV_POINTS_CHECK(i) \
                (iv_attr_mvpd_data[i].frequency_mhz   == 0 || \
                 iv_attr_mvpd_data[i].vdd_mv          == 0 || \
                 iv_attr_mvpd_data[i].idd_tdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_tdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_rdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].idd_rdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].vcs_mv          == 0 || \
                 iv_attr_mvpd_data[i].ics_tdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].ics_tdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].ics_rdp_ac_10ma == 0 || \
                 iv_attr_mvpd_data[i].ics_rdp_dc_10ma == 0 || \
                 iv_attr_mvpd_data[i].vdd_vmin == 0)

// TODO; need to reenable when RT values are guarenteed to be present
//                 iv_attr_mvpd_data[i].rt_tdp_ac_10ma == 0 ||
//                 iv_attr_mvpd_data[i].rt_tdp_dc_10ma == 0 ||


#define POUNDV_POINTS_PRINT(i,suffix)   \
                  .set_FREQUENCY_##suffix(iv_attr_mvpd_data[i].frequency_mhz)  \
                  .set_VDD_##suffix(iv_attr_mvpd_data[i].vdd_mv) \
                 .set_IDD_TDP_AC_##suffix(iv_attr_mvpd_data[i].idd_tdp_ac_10ma) \
                 .set_IDD_TDP_DC_##suffix(iv_attr_mvpd_data[i].idd_tdp_dc_10ma) \
                 .set_IDD_RDP_AC_##suffix(iv_attr_mvpd_data[i].idd_rdp_ac_10ma) \
                 .set_IDD_RDP_DC_##suffix(iv_attr_mvpd_data[i].idd_rdp_dc_10ma) \
                 .set_VCS_##suffix(iv_attr_mvpd_data[i].vcs_mv) \
                 .set_ICS_TDP_AC_##suffix(iv_attr_mvpd_data[i].ics_tdp_ac_10ma) \
                 .set_ICS_TDP_DC_##suffix(iv_attr_mvpd_data[i].ics_tdp_dc_10ma) \
                 .set_ICS_RDP_AC_##suffix(iv_attr_mvpd_data[i].ics_rdp_ac_10ma) \
                 .set_ICS_RDP_DC_##suffix(iv_attr_mvpd_data[i].ics_rdp_dc_10ma) \
                 .set_ICS_RDP_AC_##suffix(iv_attr_mvpd_data[i].rt_tdp_ac_10ma) \
                 .set_ICS_RDP_DC_##suffix(iv_attr_mvpd_data[i].rt_tdp_dc_10ma) \
                 .set_VDD_VMIN_##suffix(iv_attr_mvpd_data[i].vdd_vmin)

//w => N_L (w > 7 is invalid)
//x => N_S (x > N_L is invalid)
//y => L_S (y > (N_L - S_N) is invalid)
//z => S_N (z > N_S is invalid
#define VALIDATE_FREQUENCY_DROP_VALUES(w, x, y, z, state) \
    if ((w > 7)         ||      \
        (x > w)         ||      \
        (y > (w - z))   ||      \
        (z > x)         ||      \
        ((w | x | y | z) == 0)) \
    { state = 0; }

#define POUNDV_SLOPE_CHECK(x,y)   x > y ? "GREATER (ERROR!) than" : "less than"

#define PRINT_LEAD1(_buffer, _format, _var1)                    \
    {                                                           \
        char _temp_buffer[64];                                  \
        strcpy(_buffer,"");                                     \
        sprintf(_temp_buffer, _format, _var1);                  \
        strcat(_buffer, _temp_buffer);                          \
    }

#define HEX_DEC_STR(_buffer, _value)                            \
   {                                                            \
       char _temp_buffer[64];                                   \
       sprintf(_temp_buffer, "0x%04X (%5d)  ", _value, _value); \
       strcat(_buffer, _temp_buffer);                           \
   }

#define HEX_STR(_buffer, _value)                                \
   {                                                            \
       char _temp_buffer[64];                                   \
       sprintf(_temp_buffer, "0x%04X  ", _value);               \
       strcat(_buffer, _temp_buffer);                           \
   }

#define HEX_STR_64(_buffer, _value)                             \
   {                                                            \
       char _temp_buffer[64];                                   \
       sprintf(_temp_buffer, "0x%016lX  ", _value);             \
       strcat(_buffer, _temp_buffer);                           \
   }

#define VALIDATE_WOF_HEADER_DATA(a, b, c, d, e, f, g, h, i, state)         \
    if ( ((!a) || (!b) || (!c) || (!d) || (!e) || (!f) || (!g) || (!h) || (!i)))  \
    { state = 0; }


char const* vpdSetStr[] = VPD_PT_SET_STR;
char const* ddsFieldStr[] = POUNDW_DDS_FIELDS_STR;
char const* region_names[] = VPD_OP_SLOPES_REGION_ORDER_STR;

using namespace pm_pstate_parameter_block;

///////////////////////////////////////////////////////////
////////     p10_pstate_parameter_block
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p10_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           PstateSuperStructure* io_pss,
                           uint8_t* o_buf,
                           uint32_t& io_size)
{

    const uint32_t BUFFSIZE = 64;
    char  l_proc_str[BUFFSIZE];
    fapi2::toString(i_target, l_proc_str, BUFFSIZE);

    FAPI_INF("> p10_pstate_parameter_block - %s", l_proc_str);

    PlatPmPPB *l_pmPPB = new PlatPmPPB(i_target);
    GlobalPstateParmBlock_v1_t *l_globalppb = new GlobalPstateParmBlock_v1_t;
    OCCPstateParmBlock_t l_occppb;;

    do
    {

        //Instantiate pstate object

        FAPI_ASSERT(l_pmPPB->iv_init_error == false,
                fapi2::PSTATE_PB_ATTRIBUTE_ACCESS_ERROR()
                .set_CHIP_TARGET(i_target),
                "Pstate Parameter Block attribute access error");

        // -----------------------------------------------------------
        // Clear the PstateSuperStructure and install the magic number
        //----------------------------------------------------------
        memset(io_pss, 0, sizeof(PstateSuperStructure));

        FAPI_INF("Populating magic number in Pstate Parameter block structure");
        (*io_pss).iv_magic = revle64(PSTATE_PARMSBLOCK_MAGIC);

        //Local variables for Global,local and OCC parameter blocks
        // PGPE content
        memset (l_globalppb, 0, sizeof(GlobalPstateParmBlock_v1_t));

        // OCC content
        memset (&l_occppb , 0, sizeof (OCCPstateParmBlock_t));

        //if PSTATES_MODE is off then we don't need to execute further to collect
        //the data.
        if (!(l_pmPPB->isPstateModeEnabled()))
        {
            FAPI_INF("Pstate mode is to not boot the PGPE.  Thus, none of the parameter blocks will be constructed");

            // Set the io_size to 0 so that memory allocation issues won't be
            // detected by the caller.
            io_size = 0;
            break;
        }

        // ----------------
        // get VPD data (#V,#W,IQ)
        // ----------------
        FAPI_TRY(l_pmPPB->vpd_init(),"vpd_init function failed");

        // ----------------
        // Compute VPD points for different regions
        // ----------------
        FAPI_TRY(l_pmPPB->compute_vpd_pts());

        // Safe mode freq and volt init
        // ----------------
        FAPI_TRY(l_pmPPB->safe_mode_init());

        // ----------------
        // Retention voltage computation
        // ----------------
        FAPI_TRY(l_pmPPB->compute_retention_vid());

        // ----------------
        // RVRM enablement state
        // ----------------
        FAPI_TRY(l_pmPPB->rvrm_enablement());

        // ----------------
        // RESCLK Initialization
        // ----------------
        l_pmPPB->resclk_init();

        // ----------------
        // WOF initialization
        // ----------------
        io_size = 0;
        FAPI_TRY(l_pmPPB->wof_init(
                 o_buf,
                 io_size),
                 "WOF initialization failure");

        // ----------------
        // Set this part's fmax value based on VPD and attributes
        // ----------------
        FAPI_TRY(l_pmPPB->part_fmax());

        // ----------------
        // Initialize GPPB structure
        // ----------------
        FAPI_TRY(l_pmPPB->gppb_init(l_globalppb));

        // ----------------
        //Initialize OPPB structure
        // ----------------
        FAPI_TRY(l_pmPPB->oppb_init(&l_occppb));

        // ----------------
        //Initialize pstate feature attribute state
        // ----------------
        FAPI_TRY(l_pmPPB->set_global_feature_attributes());

        // Put out the Parmater Blocks to the trace
        gppb_print(i_target, l_globalppb);
        oppb_print(i_target, &l_occppb);
        print_offsets();

        // Populate Global,local and OCC parameter blocks into Pstate super structure
        (*io_pss).iv_globalppb = *l_globalppb;
        (*io_pss).iv_occppb = l_occppb;
    }
    while(0);

fapi_try_exit:
    delete l_pmPPB;
    delete l_globalppb;
    FAPI_INF("< p10_pstate_parameter_block");
    return fapi2::current_err;
}
// END OF PSTATE PARAMETER BLOCK function

///////////////////////////////////////////////////////////
////////    gppb_print
///////////////////////////////////////////////////////////
void gppb_print(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    GlobalPstateParmBlock_v1_t* i_gppb)
{
    static const uint32_t   BUFFSIZE = 512;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];
    const char*     pv_op_str[NUM_OP_POINTS] = PV_OP_STR;
    const char*     prt_region_names[VPD_NUM_SLOPES_REGION] = VPD_OP_SLOPES_REGION_ORDER_STR;
    const char*     prt_rail_names[RUNTIME_RAILS] = RUNTIME_RAIL_STR;
    const char*     prt_dds_slope_names[NUM_POUNDW_DDS_FIELDS] = POUNDW_DDS_FIELDS_STR;
    char vlt_str[][4] = {"VDD","VCS"};
    uint32_t        s;

    fapi2::toString(i_target, l_buffer, BUFFSIZE);

    // Put out the endian-corrected scalars
    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("Global Pstate Parameter Block - %s", l_buffer);
    FAPI_INF("---------------------------------------------------------------------------------------");

//    strcpy(l_buffer,"");
//    sprintf (l_temp_buffer, "  %-20s : ","Frequency Ref  (KHz)");
//    strcat(l_buffer, l_temp_buffer);

    PRINT_LEAD1(l_buffer, "%-22s : ","Frequency Ref  (KHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->base.reference_frequency_khz));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "%-22s : ","Frequency Step (KHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->base.frequency_step_khz));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "%-22s : ","Frequency Ceil (KHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->base.frequency_ceiling_khz));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "%-22s : ","Frequency OCC  (MHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->base.occ_complex_frequency_mhz));
    FAPI_INF("%s", l_buffer);

    // -------------------

    s = VPD_PT_SET_RAW;

    FAPI_INF("Operating Points(Raw):     Freq(MHz)         VDD(mV)       IDTAC(10mA)     IDTDC(10mA)     IDRAC(10mA)     IDRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-20s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].vdd_mv));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].idd_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].idd_tdp_dc_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].idd_rdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].idd_rdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    // -------------------
    FAPI_INF("Operating Points(Raw):     Freq(MHz)         VCS(mV)       ICTAC(10mA)     ICTDC(10mA)     ICRAC(10mA)     ICRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        PRINT_LEAD1(l_buffer, "  %-20s : ",pv_op_str[i]);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].vcs_mv));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].ics_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].ics_tdp_dc_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].ics_rdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].ics_rdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    // -------------------
    FAPI_INF("Operating Points(Raw):     Freq(MHz)      VDD_vmin(mV)     RTTAC(10mA)     RTTDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        PRINT_LEAD1(l_buffer, "  %-20s : ",pv_op_str[i]);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].vdd_vmin));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].rt_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].rt_tdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    // -------------------

    s = VPD_PT_SET_BIASED;

    FAPI_INF("Operating Points(Biased):  Freq(MHz)         VDD(mV)       IDTAC(10mA)     IDTDC(10mA)     IDRAC(10mA)     IDRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-20s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].vdd_mv));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].idd_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].idd_tdp_dc_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].idd_rdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].idd_rdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    // -------------------
    FAPI_INF("Operating Points(Biased):  Freq(MHz)         VCS(mV)       ICTAC(10mA)     ICTDC(10mA)     ICRAC(10mA)     IDRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        PRINT_LEAD1(l_buffer, "  %-20s : ",pv_op_str[i]);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].vcs_mv));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].ics_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].ics_tdp_dc_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].ics_rdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].ics_rdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    // -------------------
    FAPI_INF("Operating Points(Biased):  Freq(MHz)      VDD_vmin(mV)     RTTAC(10mA)     RTTDC(10mA)");;
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        PRINT_LEAD1(l_buffer, "  %-20s : ",pv_op_str[i]);

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].frequency_mhz));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].vdd_vmin));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].rt_tdp_ac_10ma));

        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->operating_points_set[s][i].rt_tdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    // -------------------
    FAPI_INF("System Parameters:           VDD           VCS           VDN")

    PRINT_LEAD1(l_buffer, "  %-20s : ", "Load line (uOhm)");
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdd_sysparm.loadline_uohm));

    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.loadline_uohm));

    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdn_sysparm.loadline_uohm));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-20s : ", "Dist Loss (uOhm)");
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdd_sysparm.distloss_uohm));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.distloss_uohm));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdn_sysparm.distloss_uohm));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-20s : ", "Offset (uV)");
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vdd_sysparm.distoffset_uv));
    HEX_DEC_STR(l_buffer,
            revle32(i_gppb->vcs_sysparm.distoffset_uv));
    HEX_DEC_STR(l_buffer,
           revle32(i_gppb->vdn_sysparm.distoffset_uv));
    FAPI_INF("%s", l_buffer);

    // -------------------
    FAPI_INF("Safe Parameters:");

    PRINT_LEAD1(l_buffer, "  %-20s : ", "Frequency (KHz)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->base.safe_frequency_khz));
    FAPI_INF("%s", l_buffer);
             ;
    PRINT_LEAD1(l_buffer, "  %-20s : ", "Voltage (mV)");
    HEX_DEC_STR(l_buffer,
             revle32(i_gppb->base.safe_voltage_mv[SAFE_VOLTAGE_VDD]));
    FAPI_INF("%s", l_buffer);

    // -------------------
    FAPI_INF("External VRM Parameters:");
    for (auto i=0; i < RUNTIME_RAILS; ++i)
    {
        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
             revle32(i_gppb->ext_vrm_parms.transition_start_ns[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Trans Start (ns)",
                l_buffer);

        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->ext_vrm_parms.transition_rate_inc_uv_per_us[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Trans Rate-Incr (uv/us)",
                l_buffer);

        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->ext_vrm_parms.transition_rate_dec_uv_per_us[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Trans Rate-Decr (uv/us)",
                l_buffer);

        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
                revle32(i_gppb->ext_vrm_parms.stabilization_time_us[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Stabl Time (us)",
                l_buffer);

        strcpy(l_buffer,"");
        HEX_DEC_STR(l_buffer,
               revle32(i_gppb->ext_vrm_parms.step_size_mv[i]));
        FAPI_INF("  %-3s %-24s : %s ",
                vlt_str[i],
                "Trans Step Size (uV)",
                l_buffer);
    }

#define xstr(s) str(s)
#define str(s) #s
#define PRINT_GPPB_SLOPES(_buffer, _member) \
    { \
        char _temp_buffer[64]; \
        sprintf(_buffer,  "  %-25s", xstr(_member)); \
        FAPI_INF("%s", _buffer); \
        for (auto i = 0; i < NUM_VPD_PTS_SET; ++i) \
        { \
            sprintf(_buffer, "  %20s (%s) : ", vpdSetStr[i], "hex"); \
            for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j) \
            { \
                for (auto x = 0; x < RUNTIME_RAILS; ++x) \
                { \
                    sprintf(_temp_buffer, "0x%04X%1s ", \
                            revle16(i_gppb->_member[x][i][j])," "); \
                    strcat(_buffer, _temp_buffer); \
                } \
                strcat(_buffer, " "); \
            } \
            FAPI_INF("%s", _buffer); \
        } \
        FAPI_INF(""); \
        for (auto i = 0; i < NUM_VPD_PTS_SET; ++i) \
        { \
            sprintf(_buffer, "  %20s (%s) : ", vpdSetStr[i], "dec"); \
            for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j) \
            { \
                for (auto x = 0; x < RUNTIME_RAILS; ++x) \
                { \
                    sprintf(_temp_buffer, "%6.3f%1s ", \
                            (float)(revle16(i_gppb->_member[x][i][j])) / (1 << VID_SLOPE_FP_SHIFT_12)," "); \
                    strcat(_buffer, _temp_buffer); \
                } \
                strcat(_buffer, " "); \
            } \
            FAPI_INF("%s", _buffer); \
        } \
        FAPI_INF(""); \
    }

    // -------------------
    sprintf(l_buffer, "%-22s", "Pstate Slopes / Region");
    sprintf(l_temp_buffer, "%-10s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, "   %s       ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s",l_buffer);

    sprintf(l_buffer,  "%-31s", "");
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        for (auto x = 0; x < RUNTIME_RAILS; ++x)
        {
            sprintf(l_temp_buffer, "  %s   ", prt_rail_names[x]);
            strcat(l_buffer, l_temp_buffer);
        }
        strcat(l_buffer, " ");
    }
    FAPI_INF("%s", l_buffer);

    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.ps_voltage_slopes);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.ps_voltage_slopes);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.voltage_ps_slopes);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.ps_ac_current_tdp);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.ac_current_ps_tdp);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.ps_dc_current_tdp);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.dc_current_ps_tdp);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.ps_ac_current_rdp);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.ac_current_ps_rdp);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.ps_dc_current_rdp);
    PRINT_GPPB_SLOPES(l_buffer, poundv_slopes.dc_current_ps_rdp);

    int i = VPD_PT_SET_RAW;

    sprintf(l_buffer, "%-28s", "ps_dds_delay_slopes (C0)");
    sprintf(l_temp_buffer, "%-2s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, " %s ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s",l_buffer);

    sprintf(l_buffer, " %21s (%s) : ", vpdSetStr[i], "hex");
    for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, "0x%04X%3s",
                revle16(i_gppb->poundw_slopes.ps_dds_delay_slopes[i][0][j])," ");
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);

    sprintf(l_buffer, "%-28s", "ps_dds_slopes (C0) Raw");
    sprintf(l_temp_buffer, "%-2s", "");
    strcat(l_buffer, l_temp_buffer);
    for (auto  j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer, " %s ", prt_region_names[j]);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s",l_buffer);

    for (uint8_t dds_cnt = TRIP_OFFSET; dds_cnt < NUM_POUNDW_DDS_FIELDS; ++dds_cnt)
    {
        sprintf(l_buffer, " %21s (%s) : ", prt_dds_slope_names[dds_cnt], "hex");
        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            sprintf(l_temp_buffer, "0x%04X%3s",
                    i_gppb->poundw_slopes.ps_dds_slopes[dds_cnt][i][0][j]," ");
            strcat(l_buffer, l_temp_buffer);
        }
        FAPI_INF("%s", l_buffer);
    }

    // -------------------
    sprintf(l_buffer, "DDS Controls (* indicates an override value)");
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "DDS Calibration Version");
    HEX_STR(l_buffer,
            i_gppb->dds_other.dds_calibration_version);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "Droop Freq Resp Reference");
    HEX_STR(l_buffer,
            revle16(i_gppb->dds_other.droop_freq_resp_reference_mhz));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "Droop Count Control (DCCR)");
    HEX_STR_64(l_buffer,
            revle64(i_gppb->dds_other.droop_count_control));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "FTC Large Droop Mde (FLMR)");
    HEX_STR_64(l_buffer,
            revle64(i_gppb->dds_other.ftc_large_droop_mode_reg_setting));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "FTC Misc Droop Mode (FMMR)");
    HEX_STR_64(l_buffer,
            revle64(i_gppb->dds_other.ftc_misc_droop_mode_reg_setting));
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "DDS Calibration Bin");
    HEX_STR(l_buffer,
            i_gppb->dds_other.calibration_bin);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "DDS Mode Setting");
    HEX_STR(l_buffer,
            i_gppb->dds_other.mode_setting);
    FAPI_INF("%s", l_buffer);

    // -------------------
    sprintf(l_buffer, "AVS Bus topology:");
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VDD AVS BUS NUM");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vdd_avsbus_num);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VDD AVS BUS RAIL SELECT");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vdd_avsbus_rail);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VCS AVS BUS NUM");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vcs_avsbus_num);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VCS AVS BUS RAIL SELECT");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vcs_avsbus_rail);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VDN AVS BUS NUM");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vdn_avsbus_num);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VDN AVS BUS RAIL SELECT");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vdn_avsbus_rail);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VIO AVS BUS NUM");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vio_avsbus_num);
    FAPI_INF("%s", l_buffer);

    PRINT_LEAD1(l_buffer, "  %-26s : ", "VII AVS BUS RAIL SELECT");
    HEX_STR(l_buffer,
            i_gppb->avs_bus_topology.vio_avsbus_rail);
    FAPI_INF("%s", l_buffer);

    // -------------------
    FAPI_INF("PGPE Flags:");

    FAPI_INF("  %-26s : %1d", "resclk_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_RESCLK_ENABLE]);

    FAPI_INF("  %-26s : %1d", "current_read_disable",
            i_gppb->pgpe_flags[PGPE_FLAG_CURRENT_READ_DISABLE]);

    FAPI_INF("  %-26s : %1d", "ocs_disable",
            i_gppb->pgpe_flags[PGPE_FLAG_OCS_DISABLE]);

    FAPI_INF("  %-26s : %1d", "wof_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_WOF_ENABLE]);

    FAPI_INF("  %-26s : %1d", "underv_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_WOV_UNDERVOLT_ENABLE]);

    FAPI_INF("  %-26s : %1d","overv_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_WOV_OVERVOLT_ENABLE]);

    FAPI_INF("  %-26s : %1d", "dds_coarse_throttle_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_DDS_COARSE_THROTTLE_ENABLE]);

    FAPI_INF("  %-26s : %1d", "dds_slew_mode",
            i_gppb->pgpe_flags[PGPE_FLAG_DDS_SLEW_MODE]);

    FAPI_INF("  %-26s : %1d", "freq_jump_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_FREQ_JUMP_ENABLE]);

    FAPI_INF("  %-26s : %1d", "pmcr_most_recent_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_PMCR_MOST_RECENT_ENABLE]);

    FAPI_INF("  %-26s : %1d", "wof_ipc_immediate_mode",
            i_gppb->pgpe_flags[PGPE_FLAG_OCC_IPC_IMMEDIATE_MODE]);

    FAPI_INF("  %-26s : %1d", "wof_ipc_immediate_mode",
            i_gppb->pgpe_flags[PGPE_FLAG_WOF_IPC_IMMEDIATE_MODE]);

    FAPI_INF("  %-26s : %1d", "phant479om_halt_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_PHANTOM_HALT_ENABLE]);

    FAPI_INF("  %-26s : %1d", "rvrm_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_RVRM_ENABLE]);

    FAPI_INF("  %-26s : %1d", "dds_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_DDS_ENABLE]);

    FAPI_INF("  %-26s : %1d", "trip_mode",
            i_gppb->pgpe_flags[PGPE_FLAG_TRIP_MODE]);

    FAPI_INF("  %-26s : %1d", "trip_interpolation_control",
            i_gppb->pgpe_flags[PGPE_FLAG_TRIP_INTERPOLATION_CONTROL]);

    FAPI_INF("  %-26s : %1d", "static_voltage_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_STATIC_VOLTAGE_ENABLE]);

    FAPI_INF("  %-26s : %1d", "wof_throttle_enable",
            i_gppb->pgpe_flags[PGPE_FLAG_WOF_THROTTLE_ENABLE]);

    FAPI_INF("  %-26s : %1d", "wof_throttle_control_mode",
            i_gppb->pgpe_flags[PGPE_FLAG_WOF_THROTTLE_CONTROL_MODE]);

    FAPI_INF("  %-26s : %1d", "wof_disable_vratio",
            i_gppb->pgpe_flags[PGPE_FLAG_WOF_DISABLE_VRATIO]);

    FAPI_INF("---------------------------------------------------------------------------------------");
}

///////////////////////////////////////////////////////////
////////    print_offsets
///////////////////////////////////////////////////////////
void print_offsets()
{

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("Pstate Parameter Block Offsets");
    FAPI_INF("---------------------------------------------------------------------------------------");

    #define PRINT_PSS_GPPB(_member) \
        FAPI_INF("PSS %-30s : %05d (0x%04X) %05d (0x%04X)", #_member, \
                    offsetof(PstateSuperStructure,_member), \
                    offsetof(PstateSuperStructure,_member), \
                    sizeof(GlobalPstateParmBlock_v1_t), \
                    sizeof(GlobalPstateParmBlock_v1_t));
    #define PRINT_PSS_OPPB(_member) \
        FAPI_INF("PSS %-30s : %05d (0x%04X) %05d (0x%04X)", #_member, \
                    offsetof(PstateSuperStructure,_member), \
                    offsetof(PstateSuperStructure,_member), \
                    sizeof(OCCPstateParmBlock_t), \
                    sizeof(OCCPstateParmBlock_t));

    FAPI_INF(" %-40s %s %-6s %s", " ", "Offset", " ", "Size");
    PRINT_PSS_GPPB(iv_globalppb);
    PRINT_PSS_OPPB(iv_occppb);

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("Global Pstate Parameter Block Offsets");
    FAPI_INF("---------------------------------------------------------------------------------------");

    #define PRINT_GPPB_OFS(_member) \
        FAPI_INF("GPPB %-30s: %05d (0x%04X) %05d (0x%04X)", #_member, \
                    offsetof(GlobalPstateParmBlock_v1_t,_member) + offsetof(PstateSuperStructure,iv_globalppb), \
                    offsetof(GlobalPstateParmBlock_v1_t,_member) + offsetof(PstateSuperStructure,iv_globalppb), \
                    offsetof(GlobalPstateParmBlock_v1_t,_member), \
                    offsetof(GlobalPstateParmBlock_v1_t,_member));

    FAPI_INF(" %-33s     %s    %s", " ", "PSS Offset", "GPPB Offset");
    PRINT_GPPB_OFS(magic);
//    PRINT_GPPB_OFS(attr);
    PRINT_GPPB_OFS(base.reference_frequency_khz);
    PRINT_GPPB_OFS(base.frequency_step_khz);
    PRINT_GPPB_OFS(base.occ_complex_frequency_mhz);
    PRINT_GPPB_OFS(base.dpll_pstate0_value);
    PRINT_GPPB_OFS(operating_points_set);
    PRINT_GPPB_OFS(poundv_biases_0p05pct);
    PRINT_GPPB_OFS(vdd_sysparm);
    PRINT_GPPB_OFS(vcs_sysparm);
    PRINT_GPPB_OFS(vdn_sysparm);
    PRINT_GPPB_OFS(ext_vrm_parms);
    PRINT_GPPB_OFS(base.safe_voltage_mv);
    PRINT_GPPB_OFS(base.safe_frequency_khz);
    PRINT_GPPB_OFS(dds);
    PRINT_GPPB_OFS(dds_alt_cal);
    PRINT_GPPB_OFS(dds_tgt_act_bin);
    PRINT_GPPB_OFS(dds_other);

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("OCC Pstate Parameter Block Offsets");
    FAPI_INF("---------------------------------------------------------------------------------------");

    #define PRINT_OPPB_OFS(_member) \
        FAPI_INF("OPPB %-30s: %05d (0x%04X) %05d (0x%04X)", #_member, \
                    offsetof(OCCPstateParmBlock_t,_member) + offsetof(PstateSuperStructure,iv_occppb), \
                    offsetof(OCCPstateParmBlock_t,_member) + offsetof(PstateSuperStructure,iv_occppb), \
                    offsetof(OCCPstateParmBlock_t,_member), \
                    offsetof(OCCPstateParmBlock_t,_member));

    FAPI_INF(" %-33s     %s    %s", " ", "PSS Offset", "OPPB Offset");
    PRINT_OPPB_OFS(magic);
    PRINT_OPPB_OFS(attr);
    PRINT_OPPB_OFS(operating_points);
    PRINT_OPPB_OFS(vdd_sysparm);
    PRINT_OPPB_OFS(vcs_sysparm);
    PRINT_OPPB_OFS(vdn_sysparm)
    PRINT_OPPB_OFS(iddq);
    PRINT_OPPB_OFS(frequency_min_khz);
    PRINT_OPPB_OFS(frequency_max_khz);
    PRINT_OPPB_OFS(frequency_step_khz);
    PRINT_OPPB_OFS(pstate_min);
    PRINT_OPPB_OFS(occ_complex_frequency_mhz);
    PRINT_OPPB_OFS(tdp_wof_base_frequency_mhz);
    PRINT_OPPB_OFS(fixed_freq_mode_frequency_mhz);
    PRINT_OPPB_OFS(pstate_max_throttle);
    PRINT_OPPB_OFS(vdd_vret_mv);
    PRINT_OPPB_OFS(altitude_temp_adj_degCpm);
    PRINT_OPPB_OFS(frequency_ceiling_khz);
    PRINT_OPPB_OFS(wof_dimension_disable_vector);
    PRINT_OPPB_OFS(ultraturbo_freq_mhz);
    PRINT_OPPB_OFS(fmax_freq_mhz);

}

///////////////////////////////////////////////////////////
////////   gppb_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::gppb_init(
                             GlobalPstateParmBlock_v1_t *io_globalppb)
{
    FAPI_INF(">>>>>>>> gppb_init");
    do
    {
        fapi2::ATTR_CHIP_EC_FEATURE_HW543384_Type l_hw543384;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW543384,
                           iv_procChip, l_hw543384),
              "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW543384)");
        // Needs to be Endianness corrected going into the block

        io_globalppb->magic.value = revle64(PSTATE_PARMSBLOCK_MAGIC_V1);

        io_globalppb->offsets[PGPE_FLAGS_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,pgpe_flags));
        io_globalppb->offsets[BASE_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,base));
        io_globalppb->offsets[AVSBUS_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,avs_bus_topology));
        io_globalppb->offsets[SYSPARMS_VDD_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,vdd_sysparm));
        io_globalppb->offsets[SYSPARMS_VCS_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,vcs_sysparm));
        io_globalppb->offsets[SYSPARMS_VDN_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,vdn_sysparm));
        io_globalppb->offsets[VRM_PARMS_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,ext_vrm_parms));
        io_globalppb->offsets[VPD_OP_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,operating_points_set));
        io_globalppb->offsets[POUNDV_BIAS_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,poundv_biases_0p05pct));
        io_globalppb->offsets[POUNDV_SLOPES_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,poundv_slopes));
        io_globalppb->offsets[POUNDW_SLOPES_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,poundw_slopes));
        io_globalppb->offsets[RESCLK_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,resclk));

        io_globalppb->offsets[DDS_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,dds));
        io_globalppb->offsets[DDS_ALT_CAL_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,dds_alt_cal));
        io_globalppb->offsets[DDS_TGT_ACT_BIN_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,dds_tgt_act_bin));
        io_globalppb->offsets[DDS_OTHER_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,dds_other));
        io_globalppb->offsets[DDS_VDD_CAL_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,vdd_cal));
        io_globalppb->offsets[WOF_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,wof));
        io_globalppb->offsets[WOV_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,wov));
        io_globalppb->offsets[THR_OFFSET_IDX] = revle16(offsetof(GlobalPstateParmBlock_v1_t,thr));

        io_globalppb->base.reference_frequency_khz = revle32(iv_reference_frequency_khz);

        io_globalppb->base.frequency_step_khz = revle32(iv_frequency_step_khz);

        io_globalppb->base.frequency_ceiling_khz = revle32(iv_part_ceiling_freq_mhz * 1000);

        FAPI_INF("io_globalppb->base.frequency_ceiling_khz = %X (%d)",
                        revle32(io_globalppb->base.frequency_ceiling_khz),
                        revle32(io_globalppb->base.frequency_ceiling_khz));

        io_globalppb->base.occ_complex_frequency_mhz = revle32(iv_attrs.attr_pau_frequency_mhz/4);

        FAPI_INF("Pstate Base Frequency %X (%d)",
                revle32(io_globalppb->base.reference_frequency_khz),
                revle32(io_globalppb->base.reference_frequency_khz));

        io_globalppb->vdd_sysparm.loadline_uohm  = revle32(iv_vdd_sysparam.loadline_uohm);
        io_globalppb->vdd_sysparm.distloss_uohm  = revle32(iv_vdd_sysparam.distloss_uohm);
        io_globalppb->vdd_sysparm.distoffset_uv  = revle32(iv_vdd_sysparam.distoffset_uv);
        io_globalppb->vcs_sysparm.loadline_uohm  = revle32(iv_vcs_sysparam.loadline_uohm);
        io_globalppb->vcs_sysparm.distloss_uohm  = revle32(iv_vcs_sysparam.distloss_uohm);
        io_globalppb->vcs_sysparm.distoffset_uv  = revle32(iv_vcs_sysparam.distoffset_uv);
        io_globalppb->vdn_sysparm.loadline_uohm  = revle32(iv_vdn_sysparam.loadline_uohm);
        io_globalppb->vdn_sysparm.distloss_uohm  = revle32(iv_vdn_sysparam.distloss_uohm);
        io_globalppb->vdn_sysparm.distoffset_uv  = revle32(iv_vdn_sysparam.distoffset_uv);


        io_globalppb->base.array_write_vdn_mv = revle16(iv_array_vdn_mv);
        io_globalppb->base.array_write_vdd_mv = revle16(iv_array_vdd_mv);
        io_globalppb->base.rvrm_deadzone_mv   = iv_attrs.attr_rvrm_deadzone_mv;

        //Avs bus topology
        io_globalppb->avs_bus_topology.vdd_avsbus_num  = iv_attrs.attr_avs_bus_num[VDD];
        io_globalppb->avs_bus_topology.vdd_avsbus_rail = iv_attrs.attr_avs_bus_rail_select[VDD];
        io_globalppb->avs_bus_topology.vdn_avsbus_num  = iv_attrs.attr_avs_bus_num[VDN];
        io_globalppb->avs_bus_topology.vdn_avsbus_rail = iv_attrs.attr_avs_bus_rail_select[VDN];
        io_globalppb->avs_bus_topology.vcs_avsbus_num  = iv_attrs.attr_avs_bus_num[VCS];
        io_globalppb->avs_bus_topology.vcs_avsbus_rail = iv_attrs.attr_avs_bus_rail_select[VCS];
        io_globalppb->avs_bus_topology.vio_avsbus_num  = iv_attrs.attr_avs_bus_num[VIO];
        io_globalppb->avs_bus_topology.vio_avsbus_rail = iv_attrs.attr_avs_bus_rail_select[VIO];

        // External VRM parameters
        for(auto i = 0; i < RUNTIME_RAILS; ++i)
        {
            io_globalppb->ext_vrm_parms.transition_start_ns[i] =
                revle32(iv_attrs.attr_ext_vrm_transition_start_ns[i]);
            io_globalppb->ext_vrm_parms.transition_rate_inc_uv_per_us[i] =
                revle32(iv_attrs.attr_ext_vrm_transition_rate_inc_uv_per_us[i]);
            io_globalppb->ext_vrm_parms.transition_rate_dec_uv_per_us[i] =
                revle32(iv_attrs.attr_ext_vrm_transition_rate_dec_uv_per_us[i]);
            io_globalppb->ext_vrm_parms.stabilization_time_us[i] =
                revle32(iv_attrs.attr_ext_vrm_stabilization_time_us[i]);
            io_globalppb->ext_vrm_parms.step_size_mv[i] =
                revle32(iv_attrs.attr_ext_vrm_step_size_mv[i]);
        }

        //Bias values
        memcpy(&io_globalppb->poundv_biases_0p05pct,&iv_bias,sizeof(iv_bias));

        // safe_voltage_mv
        io_globalppb->base.safe_voltage_mv[SAFE_VOLTAGE_VDD] = revle32(iv_attrs.attr_pm_safe_voltage_mv[VDD]);
        io_globalppb->base.safe_voltage_mv[SAFE_VOLTAGE_VCS] = revle32(iv_attrs.attr_pm_safe_voltage_mv[VCS]);

        // safe_frequency_khz
        io_globalppb->base.safe_frequency_khz =
            iv_attrs.attr_pm_safe_frequency_mhz * 1000;
        io_globalppb->base.safe_frequency_khz = revle32(io_globalppb->base.safe_frequency_khz);
        FAPI_INF("Safe Mode Frequency %d (0x%X) kHz; VDD Voltage %d (0x%X) mV ",
                revle32(io_globalppb->base.safe_frequency_khz),
                revle32(io_globalppb->base.safe_frequency_khz),
                revle32(io_globalppb->base.safe_voltage_mv[SAFE_VOLTAGE_VDD]),
                revle32(io_globalppb->base.safe_voltage_mv[SAFE_VOLTAGE_VDD]));

        // Initialize res clk data
        memset(&io_globalppb->resclk,0,sizeof(ResClkSetup_t));

        // -----------------------------------------------
        // populate VpdOperatingPoint with biased MVPD attributes
        // -----------------------------------------------
        for (uint8_t i = 0; i < NUM_VPD_PTS_SET; i++)
        {
            for (uint8_t j = 0; j < NUM_OP_POINTS; j++)
            {
                io_globalppb->operating_points_set[i][j].frequency_mhz   = revle32(iv_operating_points[i][j].frequency_mhz);
                io_globalppb->operating_points_set[i][j].vdd_mv          = revle32(iv_operating_points[i][j].vdd_mv);
                io_globalppb->operating_points_set[i][j].idd_tdp_ac_10ma = revle32(iv_operating_points[i][j].idd_tdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].idd_tdp_dc_10ma = revle32(iv_operating_points[i][j].idd_tdp_dc_10ma);
                io_globalppb->operating_points_set[i][j].idd_rdp_ac_10ma = revle32(iv_operating_points[i][j].idd_rdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].idd_rdp_dc_10ma = revle32(iv_operating_points[i][j].idd_rdp_dc_10ma);
                io_globalppb->operating_points_set[i][j].vcs_mv          = revle32(iv_operating_points[i][j].vcs_mv);
                io_globalppb->operating_points_set[i][j].ics_tdp_ac_10ma = revle32(iv_operating_points[i][j].ics_tdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].ics_tdp_dc_10ma = revle32(iv_operating_points[i][j].ics_tdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].vdd_vmin        = revle32(iv_operating_points[i][j].vdd_vmin);
                io_globalppb->operating_points_set[i][j].rt_tdp_ac_10ma =
                    revle32(iv_operating_points[i][j].rt_tdp_ac_10ma);
                io_globalppb->operating_points_set[i][j].rt_tdp_dc_10ma =
                    revle32(iv_operating_points[i][j].rt_tdp_dc_10ma);
                io_globalppb->operating_points_set[i][j].pstate          = iv_operating_points[i][j].pstate;
            }
        }

        // Calculate pre-calculated slopes
        compute_PStateV_I_slope(io_globalppb);

        //Copy over the DDS data
        for (uint8_t i = 0; i < NUM_OP_POINTS; i++)
        {
            for (auto c = 0; c < MAXIMUM_CORES; c++) {
                io_globalppb->dds[i][c].ddsc.value =  revle64(iv_poundW_data.entry[i].entry[c].ddsc.value);
                io_globalppb->dds_tgt_act_bin[i][c].target_act_bin.value =  iv_poundW_data.entry[i].entry_tgt_act_bin[c].target_act_bin.value;
                io_globalppb->dds_alt_cal[i][c].alt_cal.value  =  revle16(iv_poundW_data.entry[i].entry_alt_cal[c].alt_cal.value);
            }
            io_globalppb->vdd_cal[i].cal_vdd  =  revle16(iv_poundW_data.entry[i].vdd_cal.cal_vdd);
            io_globalppb->vdd_cal[i].alt_cal_vdd =  revle16(iv_poundW_data.entry[i].vdd_cal.alt_cal_vdd);
            io_globalppb->vdd_cal[i].large_droop_vdd =  revle16(iv_poundW_data.entry[i].vdd_cal.large_droop_vdd);
            io_globalppb->vdd_cal[i].worst_droop_min_vdd =  revle16(iv_poundW_data.entry[i].vdd_cal.worst_droop_min_vdd);
            io_globalppb->vdd_cal[i].non_perf_loss_vdd =  revle16(iv_poundW_data.entry[i].vdd_cal.non_perf_loss_vdd);
        }
        io_globalppb->dds_other.dds_calibration_version = iv_poundW_data.other.dds_calibration_version;
        io_globalppb->dds_other.droop_freq_resp_reference_mhz = revle16(iv_poundW_data.other.dds_calibration_version);
        io_globalppb->dds_other.droop_count_control = revle64(dccr_value());
        io_globalppb->dds_other.ftc_large_droop_mode_reg_setting = revle64(iv_poundW_data.other.ftc_large_droop_mode_reg_setting);
        io_globalppb->dds_other.ftc_misc_droop_mode_reg_setting = revle64(iv_poundW_data.other.ftc_misc_droop_mode_reg_setting);
        io_globalppb->dds_other.calibration_bin = iv_poundW_data.other.calibration_bin;
        io_globalppb->dds_other.mode_setting = iv_poundW_data.other.mode_setting;


#ifndef __HOSTBOOT_MODULE
        for(auto region(REGION_CF0_CF1); region <= REGION_CF6_CF7; ++region)
        {
                for (auto cores = 0; cores < MAXIMUM_CORES; cores++)
                {
                    PoundWEntry_t pwe;
                    pwe.ddsc.value = revle64(io_globalppb->dds[region][cores].ddsc.value);
                    FAPI_DBG("global_ppb[%s][%u]: 0x%016llx  delay: 0x%04x, %d"
                            , region_names[region],cores,
                            pwe.ddsc.value,
                            pwe.ddsc.fields.insrtn_dely,
                            pwe.ddsc.fields.insrtn_dely
                            );
                }
        }
#endif

        FAPI_INF("DCCR=0x%016lx",revle64(io_globalppb->dds_other.droop_count_control));
        FAPI_INF("FLMR=0x%016lx",revle64(io_globalppb->dds_other.ftc_large_droop_mode_reg_setting));
        FAPI_INF("FMMR=0x%016lx",revle64(io_globalppb->dds_other.ftc_misc_droop_mode_reg_setting));

        //If ATTR_DDS_BIAS_ENABLE = ON, use the ALT_TRIP_OFFSET, ALT_CAL_ADJ,
        //ALT_DELAY values for each core instead of TRIP_OFFSET, CAL_ADJ, DELAY.
        if (iv_attrs.attr_dds_bias_enable)
        {
            for (uint8_t i = 0; i < NUM_OP_POINTS; i++)
            {
                for (uint8_t j = 0; j < MAXIMUM_CORES; j++)
                {
                    io_globalppb->dds[i][j].ddsc.fields.trip_offset = io_globalppb->dds_alt_cal[i][j].alt_cal.fields.alt_trip_offset;
                    io_globalppb->dds[i][j].ddsc.fields.insrtn_dely = io_globalppb->dds_alt_cal[i][j].alt_cal.fields.alt_delay;
                    io_globalppb->dds[i][j].ddsc.fields.calb_adj    = io_globalppb->dds_alt_cal[i][j].alt_cal.fields.alt_cal_adj;
                }
            }

        }

        //Compute dds slopes
        compute_dds_slopes(io_globalppb);

        float pstatef = (float)(iv_attrs.attr_pstate0_freq_mhz * 1000) /(float)(iv_frequency_step_khz);
        io_globalppb->base.dpll_pstate0_value = revle32((Pstate)internal_round(pstatef));

        FAPI_INF("l_globalppb.dpll_pstate0_value %X (%d)",
                revle32(io_globalppb->base.dpll_pstate0_value),
                revle32(io_globalppb->base.dpll_pstate0_value));

        //Set PGPE Flags
        io_globalppb->pgpe_flags[PGPE_FLAG_RESCLK_ENABLE] = is_resclk_enabled();
        io_globalppb->pgpe_flags[PGPE_FLAG_CURRENT_READ_DISABLE] = iv_attrs.attr_system_current_read_disable;
        io_globalppb->pgpe_flags[PGPE_FLAG_OCS_DISABLE] = !is_ocs_enabled();
        io_globalppb->pgpe_flags[PGPE_FLAG_WOF_ENABLE] = iv_wof_enabled;
        io_globalppb->pgpe_flags[PGPE_FLAG_WOF_DISABLE_VRATIO] = iv_attrs.attr_system_wof_disable_dimension[4];
        io_globalppb->pgpe_flags[PGPE_FLAG_WOV_UNDERVOLT_ENABLE] = is_wov_underv_enabled();
        io_globalppb->pgpe_flags[PGPE_FLAG_WOV_OVERVOLT_ENABLE] = is_wov_overv_enabled();
        io_globalppb->pgpe_flags[PGPE_FLAG_DDS_COARSE_THROTTLE_ENABLE] = iv_attrs.attr_dds_coarse_thr_enable;
        io_globalppb->pgpe_flags[PGPE_FLAG_PMCR_MOST_RECENT_ENABLE] = iv_attrs.attr_pmcr_most_recent_enable;
        io_globalppb->pgpe_flags[PGPE_FLAG_DDS_ENABLE] = is_dds_enabled();
        io_globalppb->pgpe_flags[PGPE_FLAG_TRIP_MODE] = iv_attrs.attr_dds_trip_mode;
        io_globalppb->pgpe_flags[PGPE_FLAG_TRIP_INTERPOLATION_CONTROL] = iv_attrs.attr_dds_trip_interpolation_control;
        // turn off voltage movement when the WAR MODE defect exists.
        io_globalppb->pgpe_flags[PGPE_FLAG_STATIC_VOLTAGE_ENABLE] =
                           (l_hw543384 && iv_attrs.attr_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_TIE_NEST_TO_PAU) ? 1 : 0;

#ifdef __HOSTBOOT_MODULE
        if (Util::isSimicsRunning())
        {
            iv_attrs.attr_pgpe_hcode_function_enable = 0;
        }
#endif

        if (iv_attrs.attr_pgpe_hcode_function_enable == 0) {
            io_globalppb->pgpe_flags[PGPE_FLAG_OCC_IPC_IMMEDIATE_MODE] = 1;
            io_globalppb->pgpe_flags[PGPE_FLAG_WOF_IPC_IMMEDIATE_MODE] = 1;
        } else {
            io_globalppb->pgpe_flags[PGPE_FLAG_OCC_IPC_IMMEDIATE_MODE] = 0;
            io_globalppb->pgpe_flags[PGPE_FLAG_WOF_IPC_IMMEDIATE_MODE] = 0;
        }
        io_globalppb->pgpe_flags[PGPE_FLAG_PHANTOM_HALT_ENABLE] = iv_attrs.attr_phantom_halt_enable;
        io_globalppb->pgpe_flags[PGPE_FLAG_RVRM_ENABLE] = iv_rvrm_enabled;
        io_globalppb->pgpe_flags[PGPE_FLAG_RVRM_QVID_ENABLE_VEC] = iv_qrvrm_enable_flag;
        io_globalppb->pgpe_flags[PGPE_FLAG_WOF_THROTTLE_ENABLE] = is_wof_throttle_enabled();
        io_globalppb->base.vcs_vdd_offset_mv= revle16(uint16_t(iv_attrs.attr_vcs_vdd_offset_mv & 0xFF));//Attribute is 1-byte only so truncate it
        io_globalppb->base.vcs_floor_mv  = revle16(iv_attrs.attr_vcs_floor_mv);

        //WOV parameters
        io_globalppb->wov.wov_sample_125us                = revle32(iv_attrs.attr_wov_sample_125us);
        io_globalppb->wov.wov_max_droop_pct               = revle32(iv_attrs.attr_wov_max_droop_pct);
        io_globalppb->wov.wov_underv_perf_loss_thresh_pct = iv_attrs.attr_wov_underv_perf_loss_thresh_pct;
        io_globalppb->wov.wov_underv_step_incr_pct        = iv_attrs.attr_wov_underv_step_incr_pct;
        io_globalppb->wov.wov_underv_step_decr_pct        = iv_attrs.attr_wov_underv_step_decr_pct;
        io_globalppb->wov.wov_underv_max_pct              = iv_attrs.attr_wov_underv_max_pct;
        io_globalppb->wov.wov_underv_vmin_mv              = revle16(iv_attrs.attr_wov_underv_vmin_mv);
        io_globalppb->wov.wov_overv_vmax_mv               = revle16(iv_attrs.attr_wov_overv_vmax_mv);
        io_globalppb->wov.wov_overv_step_incr_pct         = iv_attrs.attr_wov_overv_step_incr_pct;
        io_globalppb->wov.wov_overv_step_decr_pct         = iv_attrs.attr_wov_overv_step_decr_pct;
        io_globalppb->wov.wov_overv_max_pct               = iv_attrs.attr_wov_overv_max_pct;
        if (io_globalppb->wov.wov_underv_vmin_mv == 0)
        {
            io_globalppb->wov.wov_underv_vmin_mv = revle16(iv_vdd_vpd_vmin);

            fapi2::ATTR_WOV_UNDERV_VMIN_MV_Type l_wov_uv_vmin = revle16(io_globalppb->wov.wov_underv_vmin_mv);
            FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_WOV_UNDERV_VMIN_MV,
                                    iv_procChip,
                                    l_wov_uv_vmin));

            FAPI_INF("WOV_VMIN_MV=%u",revle16(io_globalppb->wov.wov_underv_vmin_mv));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOV_UNDERV_VMIN_MV,
                                     iv_procChip,
                                     iv_vdd_vpd_vmin));
            FAPI_INF("SafeVoltage=%u",revle32(io_globalppb->base.safe_voltage_mv[SAFE_VOLTAGE_VDD]));
        }

        for(uint32_t i = 0; i < NUM_WOV_DIRTY_UC_CTRL; i++) {
            io_globalppb->wov.wov_dirty_undercurr_control[i] = iv_attrs.attr_wov_dirty_uncurrent_ctrl[i];
            FAPI_INF("WOV_DIRTY_UNDERCURR_CTRL[%u]=%u",i,io_globalppb->wov.wov_dirty_undercurr_control[i]);
        }
        io_globalppb->wov.wov_idd_thresh                  =  revle16(iv_attr_mvpd_poundV_other_info.idd_rdp_limit_0p1A);

        //Throttle
        io_globalppb->thr.thr_kp = iv_attrs.attr_system_wof_throttle_control_kp;
        io_globalppb->thr.thr_ki = iv_attrs.attr_system_wof_throttle_control_ki;

#if 0
        io_globalppb->attr.fields.pstates_enabled     = is_pstates_enabled();
        io_globalppb->attr.fields.resclk_enabled      = is_resclk_enabled();
        io_globalppb->attr.fields.wof_enabled         = is_wof_enabled();
        io_globalppb->attr.fields.dds_enabled         = is_dds_enabled();
        io_globalppb->attr.fields.ocs_enabled         = is_ocs_enabled();
        io_globalppb->attr.fields.underv_enabled      = is_wov_underv_enabled();
        io_globalppb->attr.fields.overv_enabled       = is_wov_overv_enabled();
        io_globalppb->attr.fields.rvrm_enabled        = is_rvrm_enabled();
        io_globalppb->attr.fields.wof_disable_vdd     = iv_attrs.attr_system_wof_disable_dimension[0];
        io_globalppb->attr.fields.wof_disable_vcs     = iv_attrs.attr_system_wof_disable_dimension[1];
        io_globalppb->attr.fields.wof_disable_io      = iv_attrs.attr_system_wof_disable_dimension[2];
        io_globalppb->attr.fields.wof_disable_amb     = iv_attrs.attr_system_wof_disable_dimension[3];
        io_globalppb->attr.fields.wof_disable_vratio  = iv_attrs.attr_system_wof_disable_dimension[4];
#endif

        //Current Scaling Factor - only VDD, VCS and VDN are sent to PGPE
        for (auto i=0; i < 3; ++i)
        {
            io_globalppb->ext_vrm_parms.current_scaling_factor[i] = iv_attrs.attr_current_scaling_factor[i];
            FAPI_INF("Current_scaling_factor[%u]=%u, attr=%u",io_globalppb->ext_vrm_parms.current_scaling_factor[i],iv_attrs.attr_current_scaling_factor[i]);
        }
        for (uint8_t i = 0; i < NUM_WOF_VRATIO_PCT; i++) {
            io_globalppb->wof.vratio_vdd_64ths[i] = uint16_t(internal_ceil(iv_attrs.attr_vratio_vdd_10th_pct[i] / 15.625));
            io_globalppb->wof.vratio_vcs_64ths[i] = uint16_t(internal_ceil(iv_attrs.attr_vratio_vcs_10th_pct[i] / 15.625));
        }


    } while (0);

fapi_try_exit:
    FAPI_INF("<<<<<<<<<< gppb_init");
    return fapi2::current_err;
}


///////////////////////////////////////////////////////////
////////   oppb_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::oppb_init(
                             OCCPstateParmBlock_t *i_occppb )
{
    FAPI_INF(">>>>>>>> oppb_init");

    do
    {
        fapi2::ReturnCode l_rc;

        fapi2::ATTR_CHIP_EC_FEATURE_HW543384_Type l_hw543384;
        fapi2::ATTR_RVRM_VID_Type   l_rvrm_rvid;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RVRM_VID,
                               iv_procChip,
                               l_rvrm_rvid));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW543384,
                           iv_procChip, l_hw543384),
              "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW543384)");
        // -----------------------------------------------
        // OCC parameter block
        // -----------------------------------------------
        i_occppb->magic.value = revle64(OCC_PARMSBLOCK_MAGIC);

        i_occppb->vdd_sysparm.loadline_uohm  = revle32(iv_vdd_sysparam.loadline_uohm);
        i_occppb->vdd_sysparm.distloss_uohm  = revle32(iv_vdd_sysparam.distloss_uohm);
        i_occppb->vdd_sysparm.distoffset_uv  = revle32(iv_vdd_sysparam.distoffset_uv);
        i_occppb->vcs_sysparm.loadline_uohm  = revle32(iv_vcs_sysparam.loadline_uohm);
        i_occppb->vcs_sysparm.distloss_uohm  = revle32(iv_vcs_sysparam.distloss_uohm);
        i_occppb->vcs_sysparm.distoffset_uv  = revle32(iv_vcs_sysparam.distoffset_uv);
        i_occppb->vdn_sysparm.loadline_uohm  = revle32(iv_vdn_sysparam.loadline_uohm);
        i_occppb->vdn_sysparm.distloss_uohm  = revle32(iv_vdn_sysparam.distloss_uohm);
        i_occppb->vdn_sysparm.distoffset_uv  = revle32(iv_vdn_sysparam.distoffset_uv);


        i_occppb->attr.fields.pstates_enabled     = is_pstates_enabled();
        i_occppb->attr.fields.resclk_enabled      = is_resclk_enabled();
        i_occppb->attr.fields.wof_enabled         = is_wof_enabled();
        i_occppb->attr.fields.dds_enabled         = is_dds_enabled();
        i_occppb->attr.fields.ocs_enabled         = is_ocs_enabled();
        i_occppb->attr.fields.underv_enabled      = is_wov_underv_enabled();
        i_occppb->attr.fields.overv_enabled       = is_wov_overv_enabled();
        i_occppb->attr.fields.rvrm_enabled        = is_rvrm_enabled();
        i_occppb->attr.fields.wof_disable_vdd     = iv_attrs.attr_system_wof_disable_dimension[0];
        i_occppb->attr.fields.wof_disable_vcs     = iv_attrs.attr_system_wof_disable_dimension[1];
        i_occppb->attr.fields.wof_disable_io      = iv_attrs.attr_system_wof_disable_dimension[2];
        i_occppb->attr.fields.wof_disable_amb     = iv_attrs.attr_system_wof_disable_dimension[3];
        i_occppb->attr.fields.wof_disable_vratio  = iv_attrs.attr_system_wof_disable_dimension[4];


        FAPI_INF("OPPB i_occppb->attr.fields.pstates_enabled %d, i_occppb->attr.fields.wof_enabled %d %d",
        i_occppb->attr.fields.pstates_enabled,i_occppb->attr.fields.wof_enabled, iv_wof_enabled);


        //load vpd operating points
        for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
        {
            i_occppb->operating_points[i].frequency_mhz   = revle32(iv_attr_mvpd_poundV_biased[i].frequency_mhz);
            i_occppb->operating_points[i].vdd_mv          = revle32(iv_attr_mvpd_poundV_biased[i].vdd_mv);
            i_occppb->operating_points[i].idd_tdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_tdp_ac_10ma);
            i_occppb->operating_points[i].idd_tdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_tdp_dc_10ma);
            i_occppb->operating_points[i].idd_rdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_rdp_ac_10ma);
            i_occppb->operating_points[i].idd_rdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].idd_rdp_dc_10ma);
            i_occppb->operating_points[i].vcs_mv          = revle32(iv_attr_mvpd_poundV_biased[i].vcs_mv);
            i_occppb->operating_points[i].ics_tdp_ac_10ma = revle32(iv_attr_mvpd_poundV_biased[i].ics_tdp_ac_10ma);
            i_occppb->operating_points[i].ics_tdp_dc_10ma = revle32(iv_attr_mvpd_poundV_biased[i].ics_tdp_ac_10ma);
            i_occppb->operating_points[i].vdd_vmin        = revle32(iv_attr_mvpd_poundV_biased[i].vdd_vmin);
            i_occppb->operating_points[i].rt_tdp_ac_10ma =
            revle32(iv_attr_mvpd_poundV_biased[i].rt_tdp_ac_10ma);
            i_occppb->operating_points[i].rt_tdp_dc_10ma =
            revle32(iv_attr_mvpd_poundV_biased[i].rt_tdp_dc_10ma);
            i_occppb->operating_points[i].pstate          = iv_attr_mvpd_poundV_biased[i].pstate;
        }


        // frequency_min_khz - Value from Power safe operating point after biases
        Pstate l_ps;

        if (l_hw543384 && iv_attrs.attr_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_TIE_NEST_TO_PAU)
        {
            //Translate pau  frequency to pstate

            l_rc = freq2pState((iv_attrs.attr_pau_frequency_mhz * 1000),
                    &l_ps, ROUND_NEAR);
            if (l_rc)
            {
                // TODO put in notification controls
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
        else
        {
            //Translate safe mode frequency to pstate
            l_rc = freq2pState((iv_attrs.attr_pm_safe_frequency_mhz * 1000),
                    &l_ps, ROUND_NEAR);

            if (l_rc)
            {
                // TODO put in notification controls
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }

        //Compute real frequency
        i_occppb->frequency_min_khz = iv_attrs.attr_pm_safe_frequency_mhz * 1000;

        i_occppb->frequency_min_khz = revle32(i_occppb->frequency_min_khz);

        // frequency_max_khz - Value from max pstate0
        i_occppb->frequency_max_khz = iv_attrs.attr_pstate0_freq_mhz * 1000;
        i_occppb->frequency_max_khz = revle32(i_occppb->frequency_max_khz);
        FAPI_INF("frequency_max_khz %08x",i_occppb->frequency_max_khz);

        // frequency_ceiling_khz - Maximum operational frquency
        i_occppb->frequency_ceiling_khz = revle32(iv_part_ceiling_freq_mhz * 1000);

        FAPI_INF("i_occppb->frequency_ceiling_khz = %X (%d)",
                        revle32(i_occppb->frequency_ceiling_khz),
                        revle32(i_occppb->frequency_ceiling_khz));

        // frequency_step_khz
        i_occppb->frequency_step_khz = revle32(iv_frequency_step_khz);

        if (is_wof_enabled())
        {
            // Iddq Table
            i_occppb->iddq = iv_iddqt;
        }
        else
        {
            iv_wof_enabled = false;
        }

        //Update OCC frequency in OPPB
        i_occppb->occ_complex_frequency_mhz = revle32(iv_occ_freq_mhz);

        // The minimum Pstate must be rounded FAST so that core floor
        // constraints are not violated.
        Pstate pstate_min;
        l_rc = freq2pState(revle32(i_occppb->frequency_min_khz),
                             &pstate_min,
                             ROUND_NEAR);

        switch ((int)l_rc)
        {
            case fapi2::RC_PSTATE_PB_XLATE_UNDERFLOW:
                FAPI_INF("OCC Minimum Frequency was clipped to Pstate 0");
                break;

            case fapi2::RC_PSTATE_PB_XLATE_OVERFLOW:
                FAPI_INF("OCC Minimum Frequency %d KHz is outside the range that can be represented"
                         " by a Pstate with a base frequency of %d KHz and step size %d KHz",
                         revle32(i_occppb->frequency_min_khz),
                         iv_reference_frequency_khz,
                         iv_frequency_step_khz);
                FAPI_INF("Pstate is set to %X (%d)", pstate_min);
                break;
        }
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

        i_occppb->pstate_min = pstate_min;
        i_occppb->pstate_min = revle32(i_occppb->pstate_min);
        FAPI_INF("l_occppb.pstate_min 0x%x (%u)", pstate_min, pstate_min);

        //wof_base_frequency_mhz
        i_occppb->tdp_wof_base_frequency_mhz =
            revle32(iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz);

        //fixed_freq_mode_frequency_mhz
        i_occppb->fixed_freq_mode_frequency_mhz =
            revle32(iv_attr_mvpd_poundV_other_info.fixed_freq_mhz);

        //ultra_turbo_frequency_mhz
        i_occppb->ultraturbo_freq_mhz =
            revle32(iv_attr_mvpd_poundV_other_info.ultraturbo_freq_mhz);

        //fmax_frequency_mhz
        i_occppb->fmax_freq_mhz =
            revle32(iv_attr_mvpd_poundV_other_info.fmax_freq_mhz);

        //pstate_max_throttle
        i_occppb->pstate_max_throttle =  revle32(pstate_min + iv_attrs.attr_throttle_pstate_number_limit);

        //VDD voltage (in mV) associated with cores in retention
        i_occppb->vdd_vret_mv =  l_rvrm_rvid << 3;
        i_occppb->vdd_vret_mv = revle32(i_occppb->vdd_vret_mv);

        // Altitude temperature adjustment (in (degrees Celcius/km)*1000)
        i_occppb->altitude_temp_adj_degCpm =  revle32(uint32_t(iv_attrs.attr_system_wof_altitude_temp_adjustment));

        // Altitude base (in meters))
        i_occppb->altitude_reference_m =  revle32(uint32_t(iv_attrs.attr_system_wof_tdp_altitude_reference));

        // TDP Sort Temperature from #V
        i_occppb->tdp_sort_power_temp_0p5C =
            revle32(iv_attr_mvpd_poundV_other_info.tdp_sort_power_temp_0p5C);

        // I/O Throttle Temperature from #V
        i_occppb->io_throttle_temp_0p5C =
            revle32(iv_attr_mvpd_poundV_other_info.io_throttle_temp_0p5C);

    }while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<< oppb_init");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////    oppb_print
///////////////////////////////////////////////////////////
void oppb_print(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    OCCPstateParmBlock_t* i_oppb)
{
    static const uint32_t   BUFFSIZE = 256;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];
    const char*     pv_op_str[NUM_OP_POINTS] = PV_OP_STR;

    // Put out the endian-corrected scalars
    fapi2::toString(i_target, l_buffer, BUFFSIZE);

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("OCC Pstate Parameter Block - %s", l_buffer);
    FAPI_INF("---------------------------------------------------------------------------------------");

    FAPI_INF("Operating Points(biased):  Freq(MHz)     VDD(mV)       IDTAC(10mA)     IDTDC(10mA)     IDRAC(10mA)     IDRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-20s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].frequency_mhz));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].vdd_mv));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].idd_tdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].idd_tdp_dc_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].idd_rdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].idd_rdp_dc_10ma));
        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("Operating Points(biased):  Freq(MHz)     VCS(mV)       ICTAC(10mA)     ICTDC(10mA)     ICRAC(10mA)     ICRDC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-20s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].frequency_mhz));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].vcs_mv));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].ics_tdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].ics_tdp_dc_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].ics_rdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].ics_rdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("Operating Points(Biased):  Freq(MHz)      VDD_vmin(mV)     RTTAC(10mA)     RTTAC(10mA)");
    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        strcpy(l_buffer,"");
        sprintf (l_temp_buffer, "  %-20s : ",pv_op_str[i]);
        strcat(l_buffer, l_temp_buffer);

        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].frequency_mhz));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].vdd_vmin));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].rt_tdp_ac_10ma));
        HEX_DEC_STR(l_buffer,
                revle32(i_oppb->operating_points[i].rt_tdp_dc_10ma));

        FAPI_INF("%s", l_buffer);
    }

    FAPI_INF("System Parameters:                          VDD           VCS           VDN");
    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-32s :", "Load line (uOhm)");
    strcat(l_buffer, l_temp_buffer);

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

    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-32s :", "Dist Loss (uOhm)");
    strcat(l_buffer, l_temp_buffer);

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

    strcpy(l_buffer,"");
    sprintf(l_temp_buffer, "  %-32s :", "Offset (uV)");
    strcat(l_buffer, l_temp_buffer);

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

    FAPI_INF("  %-32s : 0x%04X (%3d)",
             "Frequency Minumum (kHz)",
             revle32(i_oppb->frequency_min_khz),
             revle32(i_oppb->frequency_min_khz));

    FAPI_INF("  %-32s : 0x%04X (%3d)",
             "Frequency Maximum (system) (kHz)",
             revle32(i_oppb->frequency_max_khz),
             revle32(i_oppb->frequency_max_khz));

    FAPI_INF("  %-32s : 0x%04X (%3d)",
             "Frequency Ceiling (kHz)",
             revle32(i_oppb->frequency_ceiling_khz),
             revle32(i_oppb->frequency_ceiling_khz));

     FAPI_INF("  %-32s : 0x%04X (%3d)",
             "Frequency Step (kHz)",
             revle32(i_oppb->frequency_step_khz),
             revle32(i_oppb->frequency_step_khz));

    FAPI_INF("  %-32s : 0x%04X (%3d)",
             "Frequency Minimum (Pstate)",
             revle32(i_oppb->pstate_min),
             revle32(i_oppb->pstate_min));

    FAPI_INF("  %-32s : 0x%04X (%3d)",
             "Frequency OCC Complex (MHz)",
             revle32(i_oppb->occ_complex_frequency_mhz),
             revle32(i_oppb->occ_complex_frequency_mhz));

   FAPI_INF("  %-32s : 0x%04X (%3d)",
             "Frequency UltraTurbo (MHz)",
             revle32(i_oppb->ultraturbo_freq_mhz),
             revle32(i_oppb->ultraturbo_freq_mhz));

    FAPI_INF("  %-32s : 0x%04X (%3d)",
             "Frequency Fmax (this part) (MHz)",
             revle32(i_oppb->fmax_freq_mhz),
             revle32(i_oppb->fmax_freq_mhz));

    FAPI_INF("Attributes:");

    FAPI_INF("  %-32s : %1d",
             "pstates_enabled",
             i_oppb->attr.fields.pstates_enabled);

    FAPI_INF("  %-32s : %1d",
             "resclk_enabled",
             i_oppb->attr.fields.resclk_enabled);

    FAPI_INF("  %-32s : %1d",
             "wof_enabled",
             i_oppb->attr.fields.wof_enabled);

    FAPI_INF("  %-32s : %1d",
             "wof_disable_vdd",
             i_oppb->attr.fields.wof_disable_vdd);

    FAPI_INF("  %-32s : %1d",
             "wof_disable_vcs",
             i_oppb->attr.fields.wof_disable_vcs);

    FAPI_INF("  %-32s : %1d",
             "wof_disable_io",
             i_oppb->attr.fields.wof_disable_io);

    FAPI_INF("  %-32s : %1d",
             "wof_disable_amb",
             i_oppb->attr.fields.wof_disable_amb);

    FAPI_INF("  %-32s : %1d",
             "wof_disable_vratio",
             i_oppb->attr.fields.wof_disable_vratio);

    FAPI_INF("  %-32s : %1d",
             "dds_enabled",
             i_oppb->attr.fields.dds_enabled);

    FAPI_INF("  %-32s : %1d",
             "ocs_enabled",
             i_oppb->attr.fields.ocs_enabled);

    FAPI_INF("  %-32s : %1d",
             "underv_enabled",
             i_oppb->attr.fields.underv_enabled);

    FAPI_INF("  %-32s : %1d",
             "overv_enabled",
             i_oppb->attr.fields.overv_enabled);

    FAPI_INF("  %-32s : %1d",
             "throttle_control_enabled",
             i_oppb->attr.fields.throttle_control_enabled);

    FAPI_INF("  %-32s : %1d",
             "rvrm_enabled",
             i_oppb->attr.fields.rvrm_enabled);

    // Put out the structure to the trace
    iddq_print(&(i_oppb->iddq));

    FAPI_INF("---------------------------------------------------------------------------------------");
}

///////////////////////////////////////////////////////////
////////  attr_init
///////////////////////////////////////////////////////////
void PlatPmPPB::attr_init( void )
{
    // Rails:  0-VDD; 1-VCS; 2-VDN; 3-VIO
    const uint32_t EXT_VRM_TRANSITION_START_NS[]            = {8000, 8000, 8000, 0};
    const uint32_t EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[]  = {10000, 10000, 10000, 0};
    const uint32_t EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[]  = {10000, 10000, 10000, 0};
    const uint32_t EXT_VRM_STABILIZATION_TIME_NS[]          = {5, 5, 5, 0};
    const uint32_t EXT_VRM_STEPSIZE_MV[]                    = {50, 50, 50, 0};

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    // --------------------------
    // attributes not yet defined
    // --------------------------
    iv_attrs.attr_dpll_bias                 = 0;
    iv_attrs.attr_undervolting              = 0;

    // ----------------------------
    // attributes currently defined
    // ----------------------------

#define PPB_GET_ATTR(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
    FAPI_INF("%-54s    = 0x%08x %d", #attr_name, iv_attrs.attr_assign, iv_attrs.attr_assign);

#define PPB_GET_ATTR_U64(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
    FAPI_INF("%-54s    = 0x%016llx %d", #attr_name, iv_attrs.attr_assign, iv_attrs.attr_assign);

#define PPB_GET_ATTR_2(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed");\
    FAPI_INF("%-54s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]); \
    FAPI_INF("%-54s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]);

#define PPB_GET_ATTR_4(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed");\
    FAPI_INF("%-54s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]); \
    FAPI_INF("%-54s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]); \
    FAPI_INF("%-54s[2] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[2], iv_attrs.attr_assign[2]); \
    FAPI_INF("%-54s[3] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[3], iv_attrs.attr_assign[3]);

#define PPB_GET_ATTR_5(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed");\
    FAPI_INF("%-54s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]); \
    FAPI_INF("%-54s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]); \
    FAPI_INF("%-54s[2] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[2], iv_attrs.attr_assign[2]); \
    FAPI_INF("%-54s[3] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[3], iv_attrs.attr_assign[3]); \
    FAPI_INF("%-54s[4] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[4], iv_attrs.attr_assign[4]);

#define PPB_GET_ATTR_8(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed");\
    FAPI_INF("%-54s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]); \
    FAPI_INF("%-54s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]); \
    FAPI_INF("%-54s[2] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[2], iv_attrs.attr_assign[2]); \
    FAPI_INF("%-54s[3] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[3], iv_attrs.attr_assign[3]); \
    FAPI_INF("%-54s[4] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[4], iv_attrs.attr_assign[4]); \
    FAPI_INF("%-54s[5] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[5], iv_attrs.attr_assign[5]); \
    FAPI_INF("%-54s[6] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[6], iv_attrs.attr_assign[6]); \
    FAPI_INF("%-54s[7] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[7], iv_attrs.attr_assign[7]);

#define PPB_GET_ATTR_2_8(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed");\
    FAPI_INF("%-51s[0][0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0][0], iv_attrs.attr_assign[0][0]); \
    FAPI_INF("%-51s[0][1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0][1], iv_attrs.attr_assign[0][1]); \
    FAPI_INF("%-51s[0][2] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0][2], iv_attrs.attr_assign[0][2]); \
    FAPI_INF("%-51s[0][3] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0][3], iv_attrs.attr_assign[0][3]); \
    FAPI_INF("%-51s[0][4] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0][4], iv_attrs.attr_assign[0][4]); \
    FAPI_INF("%-51s[0][5] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0][5], iv_attrs.attr_assign[0][5]); \
    FAPI_INF("%-51s[0][6] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0][6], iv_attrs.attr_assign[0][6]); \
    FAPI_INF("%-51s[0][7] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0][7], iv_attrs.attr_assign[0][7]); \
    FAPI_INF("%-51s[1][0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1][0], iv_attrs.attr_assign[1][0]); \
    FAPI_INF("%-51s[1][1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1][1], iv_attrs.attr_assign[1][1]); \
    FAPI_INF("%-51s[1][2] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1][2], iv_attrs.attr_assign[1][2]); \
    FAPI_INF("%-51s[1][3] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1][3], iv_attrs.attr_assign[1][3]); \
    FAPI_INF("%-51s[1][4] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1][4], iv_attrs.attr_assign[1][4]); \
    FAPI_INF("%-51s[1][5] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1][5], iv_attrs.attr_assign[1][5]); \
    FAPI_INF("%-51s[1][6] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1][6], iv_attrs.attr_assign[1][6]); \
    FAPI_INF("%-51s[1][7] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1][7], iv_attrs.attr_assign[1][7]);

    // Frequency attributes
    PPB_GET_ATTR(ATTR_SYSTEM_PSTATE0_FREQ_MHZ,              FAPI_SYSTEM,  attr_pstate0_freq_mhz);
    PPB_GET_ATTR(ATTR_NOMINAL_FREQ_MHZ,                     FAPI_SYSTEM,  attr_nominal_freq_mhz);
    PPB_GET_ATTR(ATTR_FREQ_PAU_MHZ,                         FAPI_SYSTEM,  attr_pau_frequency_mhz);
    PPB_GET_ATTR(ATTR_SYSTEM_FMAX_ENABLE,                   FAPI_SYSTEM,  attr_fmax_enable);
    PPB_GET_ATTR(ATTR_FREQ_BIAS,                            FAPI_SYSTEM,  attr_freq_bias);
    PPB_GET_ATTR(ATTR_FREQ_DPLL_REFCLOCK_KHZ,               FAPI_SYSTEM,  attr_freq_proc_refclock_khz);
    PPB_GET_ATTR(ATTR_HW543384_WAR_MODE,                    FAPI_SYSTEM,  attr_war_mode);


    PPB_GET_ATTR(ATTR_SYSTEM_THROTTLE_PSTATE_NUMBER_LIMIT,  FAPI_SYSTEM,  attr_throttle_pstate_number_limit);
    PPB_GET_ATTR(ATTR_PROC_DPLL_DIVIDER,                    iv_procChip,  attr_proc_dpll_divider);
    PPB_GET_ATTR(ATTR_FREQ_CORE_CEILING_MHZ,                iv_procChip,  attr_freq_core_ceiling_mhz);
    PPB_GET_ATTR(ATTR_FREQ_CORE_FLOOR_MHZ,                  iv_procChip,  attr_freq_core_floor_mhz);

    // Voltage Bias attributes
    PPB_GET_ATTR(ATTR_RVRM_DEADZONE_MV,                     iv_procChip,  attr_rvrm_deadzone_mv);
    PPB_GET_ATTR_2_8(ATTR_VOLTAGE_EXT_BIAS,                 iv_procChip,  attr_voltage_ext_bias);
    PPB_GET_ATTR(ATTR_VOLTAGE_EXT_VDN_BIAS,                 iv_procChip,  attr_voltage_ext_vdn_bias);
    PPB_GET_ATTR_4(ATTR_EXTERNAL_VRM_STEPSIZE,              iv_procChip,  attr_ext_vrm_step_size_mv);
    iv_attrs.attr_ext_vrm_step_size_mv[0] = 0;
    iv_attrs.attr_ext_vrm_step_size_mv[1] = 0;
    iv_attrs.attr_ext_vrm_step_size_mv[2] = 0;
    iv_attrs.attr_ext_vrm_step_size_mv[3] = 0;

    // Voltage Transition attributes
    PPB_GET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_RATE_DEC_UV_PER_US,
                                                            iv_procChip,  attr_ext_vrm_transition_rate_dec_uv_per_us);
    PPB_GET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_RATE_INC_UV_PER_US,
                                                            iv_procChip,  attr_ext_vrm_transition_rate_inc_uv_per_us);
    PPB_GET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_STABILIZATION_TIME_NS,
                                                            iv_procChip,  attr_ext_vrm_stabilization_time_us);
    PPB_GET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_START_NS, iv_procChip,    attr_ext_vrm_transition_start_ns);

   // Safe Mode attributes
    PPB_GET_ATTR(ATTR_SAFE_MODE_FREQUENCY_MHZ,              iv_procChip,  attr_pm_safe_frequency_mhz);
    PPB_GET_ATTR_2(ATTR_SAFE_MODE_VOLTAGE_MV,               iv_procChip,  attr_pm_safe_voltage_mv);
    PPB_GET_ATTR_2(ATTR_SAFE_MODE_NODDS_UPLIFT_0P5PCT,      iv_procChip,  attr_safe_mode_nodds_uplift_0p5pct);

    // AVSBus ... needed by p10_setup_evid
    PPB_GET_ATTR(ATTR_AVSBUS_FREQUENCY,                     iv_procChip,  attr_avs_bus_freq);
    PPB_GET_ATTR_4(ATTR_AVSBUS_BUSNUM,                      iv_procChip,  attr_avs_bus_num);
    PPB_GET_ATTR_4(ATTR_AVSBUS_RAIL,                        iv_procChip,  attr_avs_bus_rail_select);
    PPB_GET_ATTR_4(ATTR_BOOT_VOLTAGE,                       iv_procChip,  attr_boot_voltage_mv);
    PPB_GET_ATTR(ATTR_BOOT_VOLTAGE_BIAS_0P5PCT,             iv_procChip,  attr_boot_voltage_biase_0p5pct);
    PPB_GET_ATTR_4(ATTR_PROC_R_DISTLOSS_UOHM,               iv_procChip,  attr_proc_r_distloss_uohm);
    PPB_GET_ATTR_4(ATTR_PROC_R_LOADLINE_UOHM,               iv_procChip,  attr_proc_r_loadline_uohm);
    PPB_GET_ATTR_4(ATTR_PROC_VRM_VOFFSET_UV,                iv_procChip,  attr_proc_vrm_voffset_uv);

    // Feature control
    PPB_GET_ATTR(ATTR_SYSTEM_PSTATES_MODE,                  FAPI_SYSTEM,  attr_pstate_mode);
    PPB_GET_ATTR(ATTR_SYSTEM_WOF_DISABLE,                   FAPI_SYSTEM,  attr_system_wof_disable);
    PPB_GET_ATTR(ATTR_SYSTEM_RVRM_DISABLE,                  FAPI_SYSTEM,  attr_system_rvrm_disable);
    PPB_GET_ATTR(ATTR_SYSTEM_DDS_DISABLE,                   FAPI_SYSTEM,  attr_system_dds_disable);
    PPB_GET_ATTR(ATTR_SYSTEM_RESCLK_DISABLE,                FAPI_SYSTEM,  attr_resclk_disable);
    PPB_GET_ATTR(ATTR_SYSTEM_OCS_DISABLE,                   FAPI_SYSTEM,  attr_system_ocs_disable);
    PPB_GET_ATTR(ATTR_SYSTEM_PGPE_CURRENT_READ_DISABLE,     FAPI_SYSTEM,  attr_system_current_read_disable);
    PPB_GET_ATTR(ATTR_SYSTEM_WOV_OVERV_DISABLE,             FAPI_SYSTEM,  attr_wov_overv_disable);
    PPB_GET_ATTR(ATTR_SYSTEM_WOV_UNDERV_DISABLE,            FAPI_SYSTEM,  attr_wov_underv_disable);
    PPB_GET_ATTR_5(ATTR_SYSTEM_WOF_DISABLE_DIMENSION,       FAPI_SYSTEM,  attr_system_wof_disable_dimension);
    PPB_GET_ATTR(ATTR_PGPE_HCODE_FUNCTION_ENABLE,           FAPI_SYSTEM,  attr_pgpe_hcode_function_enable);
    PPB_GET_ATTR(ATTR_PGPE_PHANTOM_HALT_ENABLE,             FAPI_SYSTEM,  attr_phantom_halt_enable);
    PPB_GET_ATTR(ATTR_DDS_TRIP_MODE,                        FAPI_SYSTEM,  attr_dds_trip_mode);
    PPB_GET_ATTR(ATTR_DDS_TRIP_INTERPOLATION_CONTROL,       FAPI_SYSTEM,  attr_dds_trip_interpolation_control);
    PPB_GET_ATTR(ATTR_DDS_DPLL_SLEW_MODE,                   FAPI_SYSTEM,  attr_dds_dpll_slew_mode);
    PPB_GET_ATTR(ATTR_DDS_BIAS_ENABLE,                      iv_procChip,  attr_dds_bias_enable);
    PPB_GET_ATTR(ATTR_DDS_COARSE_THROTTLE_ENABLE,           iv_procChip,  attr_dds_coarse_thr_enable)
    PPB_GET_ATTR(ATTR_WOF_THROTTLE_CONTROL_LOOP_DISABLE,    FAPI_SYSTEM,  attr_system_wof_throttle_control_loop_disable);

    PPB_GET_ATTR(ATTR_WOF_THROTTLE_CONTROL_KI,              FAPI_SYSTEM,  attr_system_wof_throttle_control_ki);
    PPB_GET_ATTR(ATTR_WOF_THROTTLE_CONTROL_KP,              FAPI_SYSTEM,  attr_system_wof_throttle_control_kp);

    PPB_GET_ATTR(ATTR_WOF_PITCH_ENABLE,                     FAPI_SYSTEM,  attr_system_pitch_enable);
    PPB_GET_ATTR(ATTR_WOF_THROTTLE_CONTROL_LOOP_MODE,       FAPI_SYSTEM,  attr_system_wof_throttle_control_loop_mode);
    PPB_GET_ATTR(ATTR_WOF_ALTITUDE_TEMP_ADJUSTMENT,         FAPI_SYSTEM,  attr_system_wof_altitude_temp_adjustment);
    PPB_GET_ATTR(ATTR_WOF_TDP_ALTITUDE_REFERENCE_M,         FAPI_SYSTEM,  attr_system_wof_tdp_altitude_reference);
    PPB_GET_ATTR(ATTR_WOF_ALTITUDE_TEMP_ADJUSTMENT,         FAPI_SYSTEM,  attr_system_wof_altitude_temp_adjustment);
    PPB_GET_ATTR_8(ATTR_WOF_VRATIO_VDD_10THPCT,             iv_procChip,  attr_vratio_vdd_10th_pct);
    PPB_GET_ATTR_8(ATTR_WOF_VRATIO_VCS_10THPCT,             iv_procChip,  attr_vratio_vcs_10th_pct);
    PPB_GET_ATTR_U64(ATTR_WOF_DCCR_VALUE,                   iv_procChip,  attr_wof_dccr_value);
    PPB_GET_ATTR_U64(ATTR_WOF_FLMR_VALUE,                   iv_procChip,  attr_wof_flmr_value);
    PPB_GET_ATTR_U64(ATTR_WOF_FMMR_VALUE,                   iv_procChip,  attr_wof_fmmr_value);
    PPB_GET_ATTR(ATTR_PMCR_MOST_RECENT_MODE,                iv_procChip,  attr_pmcr_most_recent_enable);

    //TBD
    //PPB_GET_ATTR(ATTR_CHIP_EC_FEATURE_WOF_NOT_SUPPORTED, iv_procChip, attr_dd_wof_not_supported);
    PPB_GET_ATTR(ATTR_CHIP_EC_FEATURE_DDS_NOT_SUPPORTED,    iv_procChip, attr_dd_dds_not_supported);

    // WOV attributes
    PPB_GET_ATTR(ATTR_WOV_UNDERV_STEP_INCR_10THPCT,         iv_procChip,  attr_wov_underv_step_incr_pct);
    PPB_GET_ATTR(ATTR_WOV_UNDERV_STEP_DECR_10THPCT,         iv_procChip,  attr_wov_underv_step_decr_pct);
    PPB_GET_ATTR(ATTR_WOV_UNDERV_MAX_10THPCT,               iv_procChip,  attr_wov_underv_max_pct);
    PPB_GET_ATTR(ATTR_WOV_UNDERV_VMIN_MV,                   iv_procChip,  attr_wov_underv_vmin_mv);
    PPB_GET_ATTR(ATTR_WOV_OVERV_VMAX_SETPOINT_MV,           iv_procChip,  attr_wov_overv_vmax_mv);
    PPB_GET_ATTR(ATTR_WOV_OVERV_STEP_INCR_10THPCT,          iv_procChip,  attr_wov_overv_step_incr_pct);
    PPB_GET_ATTR(ATTR_WOV_OVERV_STEP_DECR_10THPCT,          iv_procChip,  attr_wov_overv_step_decr_pct);
    PPB_GET_ATTR(ATTR_WOV_OVERV_MAX_10THPCT,                iv_procChip,  attr_wov_overv_max_pct);
    PPB_GET_ATTR_2(ATTR_WOV_DIRTY_UNCURRENT_CONTROL,        FAPI_SYSTEM,  attr_wov_dirty_uncurrent_ctrl);

    // Current Scaling Factors
    PPB_GET_ATTR_8(ATTR_CURRENT_SCALING_FACTOR,             FAPI_SYSTEM,  attr_current_scaling_factor);

    // DDS #W Biases
    PPB_GET_ATTR_8(ATTR_DDS_DELAY_ADJUST,                   FAPI_SYSTEM,  attr_dds_delay_adjust);
    PPB_GET_ATTR_8(ATTR_DDS_TRIP_OFFSET_ADJUST,             FAPI_SYSTEM,  attr_dds_trip_offset_adjust);
    PPB_GET_ATTR_8(ATTR_DDS_LARGE_DROOP_DETECT_ADJUST,      FAPI_SYSTEM,  attr_dds_large_droop_detect_adjust);

    // Deal with defaults if attributes are not set
#define SET_DEFAULT(_attr_name, _attr_default) \
    if (!(iv_attrs._attr_name)) \
    { \
       iv_attrs._attr_name = _attr_default; \
       FAPI_INF("Setting %-46s    = 0x%08x %05d (internal default)", \
                #_attr_name, iv_attrs._attr_name, iv_attrs._attr_name); \
    }

#define SET_DEFAULT_2(_attr_name, _attr_default_0,_attr_default_1) \
    if (!(iv_attrs._attr_name[0] && iv_attrs._attr_name[1])) \
    { \
       iv_attrs._attr_name[0] = _attr_default_0; \
       iv_attrs._attr_name[1] = _attr_default_1; \
       FAPI_INF("Setting %-46s[0] = 0x%08x %05d (internal default)", \
                #_attr_name, iv_attrs._attr_name[0], iv_attrs._attr_name[0]); \
       FAPI_INF("Setting %-46s[1] = 0x%08x %05d (internal default)", \
                #_attr_name, iv_attrs._attr_name[1], iv_attrs._attr_name[1]); \
    }

#define SET_DEFAULT_4(_attr_name, _attr_default_0,_attr_default_1, _attr_default_2,_attr_default_3) \
    if (!(iv_attrs._attr_name[0] && iv_attrs._attr_name[1] && iv_attrs._attr_name[2] && iv_attrs._attr_name[3])) \
    { \
       iv_attrs._attr_name[0] = _attr_default_0; \
       iv_attrs._attr_name[1] = _attr_default_1; \
       iv_attrs._attr_name[2] = _attr_default_2; \
       iv_attrs._attr_name[3] = _attr_default_3; \
       FAPI_INF("Setting %-46s[0] = 0x%08x %05d (internal default)", \
                #_attr_name, iv_attrs._attr_name[0], iv_attrs._attr_name[0]); \
       FAPI_INF("Setting %-46s[1] = 0x%08x %05d (internal default)", \
                #_attr_name, iv_attrs._attr_name[1], iv_attrs._attr_name[1]); \
       FAPI_INF("Setting %-46s[2] = 0x%08x %05d (internal default)", \
                #_attr_name, iv_attrs._attr_name[2], iv_attrs._attr_name[2]); \
       FAPI_INF("Setting %-46s[3] = 0x%08x %05d (internal default)", \
                #_attr_name, iv_attrs._attr_name[3], iv_attrs._attr_name[3]); \
    }

    FAPI_INF("Setting attribute defaults");

    SET_DEFAULT(attr_proc_dpll_divider, 8);

    SET_DEFAULT_4(attr_ext_vrm_transition_start_ns,
        EXT_VRM_TRANSITION_START_NS[0],
        EXT_VRM_TRANSITION_START_NS[1],
        EXT_VRM_TRANSITION_START_NS[2],
        EXT_VRM_TRANSITION_START_NS[3]);
    SET_DEFAULT_4(attr_ext_vrm_transition_rate_inc_uv_per_us,
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[0],
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[1],
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[2],
        EXT_VRM_TRANSITION_RATE_INC_UV_PER_US[3]);
    SET_DEFAULT_4(attr_ext_vrm_transition_rate_dec_uv_per_us,
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[0],
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[1],
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[2],
        EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US[3]);
    SET_DEFAULT_4(attr_ext_vrm_stabilization_time_us,
        EXT_VRM_STABILIZATION_TIME_NS[0],
        EXT_VRM_STABILIZATION_TIME_NS[1],
        EXT_VRM_STABILIZATION_TIME_NS[3],
        EXT_VRM_STABILIZATION_TIME_NS[3]);
    SET_DEFAULT_4(attr_ext_vrm_step_size_mv,
        EXT_VRM_STEPSIZE_MV[0],
        EXT_VRM_STEPSIZE_MV[1],
        EXT_VRM_STEPSIZE_MV[2],
        EXT_VRM_STEPSIZE_MV[3]);

    SET_DEFAULT(attr_wov_overv_step_incr_pct, 5);
    SET_DEFAULT(attr_wov_overv_step_decr_pct, 5);
    SET_DEFAULT(attr_wov_overv_max_pct, 30);
    SET_DEFAULT(attr_wov_overv_vmax_mv, 1275);
    SET_DEFAULT(attr_wov_underv_step_incr_pct, 5);
    SET_DEFAULT(attr_wov_underv_step_decr_pct, 5);
    SET_DEFAULT(attr_wov_underv_max_pct, 100);

#define SET_FLOOR(_attr_name, _attr_default) \
    if (iv_attrs._attr_name < _attr_default) \
    { \
       iv_attrs._attr_name = _attr_default; \
       FAPI_INF("Raising  %-45s    to 0x%08x %04d", \
                #_attr_name, iv_attrs._attr_name, iv_attrs._attr_name); \
    }

#define SET_CEIL(_attr_name, _attr_default) \
    if (iv_attrs._attr_name > _attr_default) \
    { \
       iv_attrs._attr_name = _attr_default; \
       FAPI_INF("Clipping %-45s    to 0x%08x %04d", \
                #_attr_name, iv_attrs._attr_name, iv_attrs._attr_name); \
    }
    //Ensure that the ranges for WOV attributes are honored

    SET_CEIL (attr_wov_overv_step_incr_pct,         20  );
    SET_CEIL (attr_wov_overv_step_decr_pct,         20  );
    SET_CEIL (attr_wov_overv_max_pct,               100 );
    SET_CEIL (attr_wov_underv_step_incr_pct,        20  );
    SET_CEIL (attr_wov_underv_step_decr_pct,        20  );
    SET_FLOOR(attr_wov_underv_max_pct,              200 );

#define PPB_SET_ATTR(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_SET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute write failed"); \
    FAPI_INF("Writing %-46s    = 0x%08x %d (after default and range filtering)", \
                  #attr_name, iv_attrs.attr_assign, iv_attrs.attr_assign);

#define PPB_SET_ATTR_4(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_SET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed");\
    FAPI_INF("Writing %-46s[0] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[0], iv_attrs.attr_assign[0]); \
    FAPI_INF("Writing %-46s[1] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[1], iv_attrs.attr_assign[1]); \
    FAPI_INF("Writing %-46s[2] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[2], iv_attrs.attr_assign[2]); \
    FAPI_INF("Writing %-46s[3] = 0x%08x %d", #attr_name, iv_attrs.attr_assign[3], iv_attrs.attr_assign[3]);

    // Write the values that might have been defaulted or clipped back out
    PPB_SET_ATTR(ATTR_WOV_OVERV_STEP_INCR_10THPCT,          iv_procChip,  attr_wov_overv_step_incr_pct);
    PPB_SET_ATTR(ATTR_WOV_OVERV_STEP_DECR_10THPCT,          iv_procChip,  attr_wov_overv_step_decr_pct);
    PPB_SET_ATTR(ATTR_WOV_OVERV_MAX_10THPCT,                iv_procChip,  attr_wov_overv_max_pct);
    PPB_SET_ATTR(ATTR_WOV_OVERV_VMAX_SETPOINT_MV,           iv_procChip,  attr_wov_overv_vmax_mv);
    PPB_SET_ATTR(ATTR_WOV_UNDERV_STEP_INCR_10THPCT,         iv_procChip,  attr_wov_underv_step_incr_pct);
    PPB_SET_ATTR(ATTR_WOV_UNDERV_STEP_DECR_10THPCT,         iv_procChip,  attr_wov_underv_step_decr_pct);
    PPB_SET_ATTR(ATTR_WOV_UNDERV_MAX_10THPCT,               iv_procChip,  attr_wov_underv_max_pct);

    PPB_SET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_RATE_DEC_UV_PER_US,
                                                            iv_procChip,  attr_ext_vrm_transition_rate_dec_uv_per_us);
    PPB_SET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_RATE_INC_UV_PER_US,
                                                            iv_procChip,  attr_ext_vrm_transition_rate_inc_uv_per_us);
    PPB_SET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_STABILIZATION_TIME_NS,
                                                            iv_procChip,  attr_ext_vrm_stabilization_time_us);
    PPB_SET_ATTR_4(ATTR_EXTERNAL_VRM_TRANSITION_START_NS, iv_procChip,    attr_ext_vrm_transition_start_ns);

    // Deal with critical attributes that are not set and that any defaults chosen
    // could well be very wrong
    FAPI_ASSERT(iv_attrs.attr_pau_frequency_mhz,
                fapi2::PSTATE_PAU_FREQ_EQ_ZERO()
                .set_CHIP_TARGET(iv_procChip),
                "ATTR_FREQ_PAU_MHZ has a zero value");

    // System power distribution parameters
    // VDD rail
    iv_vdd_sysparam.loadline_uohm = iv_attrs.attr_proc_r_loadline_uohm[0];
    iv_vdd_sysparam.distloss_uohm = iv_attrs.attr_proc_r_distloss_uohm[0];
    iv_vdd_sysparam.distoffset_uv = iv_attrs.attr_proc_vrm_voffset_uv[0];

    // VCS rail
    iv_vcs_sysparam.loadline_uohm = iv_attrs.attr_proc_r_loadline_uohm[1];
    iv_vcs_sysparam.distloss_uohm = iv_attrs.attr_proc_r_distloss_uohm[1];
    iv_vcs_sysparam.distoffset_uv = iv_attrs.attr_proc_vrm_voffset_uv[1];

    // VDN rail
    iv_vdn_sysparam.loadline_uohm = iv_attrs.attr_proc_r_loadline_uohm[2];
    iv_vdn_sysparam.distloss_uohm = iv_attrs.attr_proc_r_distloss_uohm[2];
    iv_vdn_sysparam.distoffset_uv = iv_attrs.attr_proc_vrm_voffset_uv[2];

    // VIO rail
    iv_vio_sysparam.loadline_uohm = iv_attrs.attr_proc_r_loadline_uohm[3];
    iv_vio_sysparam.distloss_uohm = iv_attrs.attr_proc_r_distloss_uohm[3];
    iv_vio_sysparam.distoffset_uv = iv_attrs.attr_proc_vrm_voffset_uv[3];

#define SET_ATTR(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_SET(attr_name, target, attr_assign),"Attribute set failed"); \
    FAPI_INF("Setting %-46s[0] = 0x%08x %d", #attr_name, attr_assign, attr_assign);

    iv_pstates_enabled = true;
    iv_resclk_enabled  = true;
    iv_dds_enabled     = true;
    iv_rvrm_enabled    = true;
    iv_wof_enabled     = true;
    iv_ocs_enabled     = true;
    iv_wof_throttle_enabled = true;
    iv_wov_underv_enabled = true;
    iv_wov_overv_enabled = true;

    //Calculate nest & frequency_step_khz
    iv_frequency_step_khz = (iv_attrs.attr_freq_proc_refclock_khz /
                             iv_attrs.attr_proc_dpll_divider);

    // Round
    iv_frequency_step_khz = ((iv_frequency_step_khz << 2) + 5) >> 2 ;

    FAPI_INF ("iv_frequency_step_khz calculated %08X %d",
            iv_frequency_step_khz, iv_frequency_step_khz);

    FAPI_INF ("iv_attrs.attr_freq_proc_refclock_khz %08X %d iv_attrs.attr_proc_dpll_divider %08x",
            iv_attrs.attr_freq_proc_refclock_khz, iv_attrs.attr_freq_proc_refclock_khz,
            iv_attrs.attr_proc_dpll_divider);
    FAPI_INF ("iv_frequency_step_khz %08X %d",
            iv_frequency_step_khz, iv_frequency_step_khz);

    iv_occ_freq_mhz      = iv_attrs.attr_pau_frequency_mhz/4;

    if (iv_attrs.attr_throttle_pstate_number_limit > THROTTLE_PSTATES) {
        iv_attrs.attr_throttle_pstate_number_limit = THROTTLE_PSTATES;
    }

    // Pull in the bias contents into the class
    iv_bias.frequency_0p5pct = iv_attrs.attr_freq_bias;
    for (int p=0;  p < NUM_PV_POINTS; ++p)
    {
        for (int r=0;  r < RUNTIME_RAILS; ++r)
        {
            iv_bias.vdd_ext_0p5pct[p] = iv_attrs.attr_voltage_ext_bias[RUNTIME_RAIL_VDD][r];
            iv_bias.vcs_ext_0p5pct[p] = iv_attrs.attr_voltage_ext_bias[RUNTIME_RAIL_VCS][r];
        }
    }

fapi_try_exit:
    if (fapi2::current_err)
    {
        iv_init_error = true;
    }
}

///////////////////////////////////////////////////////////
////////    compute_boot_safe
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_boot_safe(
                  const VoltageConfigActions_t i_action)
{
    fapi2::ReturnCode l_rc;

    static const uint32_t PAU_UPLIFT_FREQ_MHZ = 2050;   // PAU frequency for VDN adjustments
    uint32_t        l_vdn_adjust_mv = 0;
    bool            b_vdn_allow_uplift = true;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    iv_boot_mode       = true;
    iv_pstates_enabled = true;
    iv_resclk_enabled  = true;
    iv_dds_enabled     = true;
    iv_rvrm_enabled    = true;
    iv_wof_enabled     = true;

    do
    {

        //We only wish to compute voltage setting defaults if the action
        //inputed to the HWP tells us to
        if(i_action == COMPUTE_VOLTAGE_SETTINGS)
        {
            // get VPD data (#V,#W)
            FAPI_TRY(vpd_init(),"vpd_init function failed")

            FAPI_INF("VDN VPD voltage before:  %d mV (0x%X)",
                        iv_attr_mvpd_poundV_static_rails.vdn_mv,
                        iv_attr_mvpd_poundV_static_rails.vdn_mv);

            // Compute the VPD operating points
            FAPI_TRY(compute_vpd_pts());

            FAPI_TRY(safe_mode_init());

            if (iv_attrs.attr_boot_voltage_mv[VDN])
            {
                FAPI_INF("VDN boot voltage override set: %d mV (0x%X)",
                        revle16(iv_attrs.attr_boot_voltage_mv[VDN]),
                        revle16(iv_attrs.attr_boot_voltage_mv[VDN]));
            }
            else if(iv_attrs.attr_avs_bus_num[VDN] == INVALID_BUS_NUM)
            {
                FAPI_INF("Skipping VDN access as this rail is not configured for AVSBus");
            }
            else
            {
                FAPI_INF("Using VDN #V VPD value and correcting for applicable system parameters");

                fapi2::ATTR_CHIP_EC_FEATURE_HW543384_Type l_hw543384;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW543384,
                                       iv_procChip, l_hw543384),
                          "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW543384)");

                if (l_hw543384 && iv_attrs.attr_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_TIE_NEST_TO_PAU)
                {
                    FAPI_INF("ATTR_HW543384_WAR_MODE is set to TIE_NEST_TO_PAU on an applicable part.  Not performing VDN uplifts.");
                    b_vdn_allow_uplift = false;
                }

                if (((iv_pdv_model_data & 0x01) != 0x01) && b_vdn_allow_uplift)
                {
                    fapi2::ATTR_CHIP_EC_FEATURE_PAU_VDN_UPLIFT_Type b_pau_vdn_uplift;
                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_PAU_VDN_UPLIFT,
                                           iv_procChip, b_pau_vdn_uplift),
                            "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_PAU_VDN_UPLIFT)");

                    FAPI_INF("PAU freq: %d (0x%X)",
                        iv_attr_mvpd_poundV_other_info.pau_frequency_mhz,
                        iv_attr_mvpd_poundV_other_info.pau_frequency_mhz);
                    if (b_pau_vdn_uplift && (iv_attr_mvpd_poundV_other_info.pau_frequency_mhz == PAU_UPLIFT_FREQ_MHZ))
                    {
                        fapi2::ATTR_VDN_UPLIFT_MV_Type l_pau_vdn_uplift_mv;
                        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDN_UPLIFT_MV,
                                           FAPI_SYSTEM, l_pau_vdn_uplift_mv),
                            "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_PAU_VDN_UPLIFT)");
                        FAPI_INF("VDN #V adjust for parts having PAU frequency = %d.  Uplifting by %d mV",
                            PAU_UPLIFT_FREQ_MHZ, l_pau_vdn_uplift_mv);
                        l_vdn_adjust_mv = l_pau_vdn_uplift_mv;
                    }
                }

                uint32_t l_int_vdn_mv = (uint32_t)(iv_attr_mvpd_poundV_static_rails.vdn_mv) + l_vdn_adjust_mv;
                uint32_t l_idn_ma =
                        (uint32_t)((iv_attr_mvpd_poundV_static_rails.idn_tdp_ac_10ma +
                                    iv_attr_mvpd_poundV_static_rails.idn_tdp_dc_10ma) * 10);

                uint32_t l_ext_vdn_mv = l_int_vdn_mv;
                if (b_vdn_allow_uplift)
                {
                    l_ext_vdn_mv = sysparm_uplift(l_int_vdn_mv,
                        l_idn_ma,
                        iv_vdn_sysparam.loadline_uohm,
                        iv_vdn_sysparam.distloss_uohm,
                        iv_vdn_sysparam.distoffset_uv);
                }

                FAPI_INF("VDN values: VPD %d (0x%X) mV; Adjusted %d mV; Set point: %d mV; IDN: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                        iv_attr_mvpd_poundV_static_rails.vdn_mv,
                        revle16(iv_attr_mvpd_poundV_static_rails.vdn_mv),
                        l_int_vdn_mv,
                        l_ext_vdn_mv,
                        l_idn_ma,
                        iv_vdn_sysparam.loadline_uohm,
                        iv_vdn_sysparam.distloss_uohm,
                        iv_vdn_sysparam.distoffset_uv);

                iv_attrs.attr_boot_voltage_mv[VDN] = (l_ext_vdn_mv);
                FAPI_INF("VDN AW voltage: %d mV (0x%X)",
                        revle16(iv_array_vdn_mv),
                        revle16(iv_array_vdn_mv));
                if (iv_array_vdn_mv && iv_attrs.attr_boot_voltage_mv[VDN] >= iv_array_vdn_mv)
                {
                    FAPI_INF("Setting array write assist flag");
                    iv_attrs.attr_array_write_assist_set = 1;
                }
            }

            if (iv_attrs.attr_boot_voltage_mv[VIO])
            {
                FAPI_INF("VIO boot voltage override set");
            }
            else if(iv_attrs.attr_avs_bus_num[VIO] == INVALID_BUS_NUM)
            {
                FAPI_INF("Skipping VIO VPD access as this rail is not configured for AVSBus");
            }
            else
            {
                FAPI_INF("VIO boot voltage override not set, using VPD value and correcting for applicable load line setting");
                uint32_t l_int_vio_mv = (uint32_t)(iv_attr_mvpd_poundV_static_rails.vio_mv);
                uint32_t l_iio_ma =
                        (uint32_t)((iv_attr_mvpd_poundV_static_rails.iio_tdp_ac_10ma +
                                    iv_attr_mvpd_poundV_static_rails.iio_tdp_dc_10ma) * 10);

                uint32_t l_ext_vio_mv = sysparm_uplift(l_int_vio_mv,
                        l_iio_ma,
                        iv_vio_sysparam.loadline_uohm,
                        iv_vio_sysparam.distloss_uohm,
                        iv_vio_sysparam.distoffset_uv);

                FAPI_INF("VIO VPD voltage %d mV; Corrected voltage: %d mV; IDN: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                        l_int_vio_mv,
                        l_ext_vio_mv,
                        l_iio_ma,
                        iv_vio_sysparam.loadline_uohm,
                        iv_vio_sysparam.distloss_uohm,
                        iv_vio_sysparam.distoffset_uv);

                iv_attrs.attr_boot_voltage_mv[VIO]= (l_ext_vio_mv);
            }

            FAPI_INF("Setting Boot Voltage attributes: VDD = %dmV; VCS = %dmV; VDN = %dmV",
                     iv_attrs.attr_boot_voltage_mv[VDD], iv_attrs.attr_boot_voltage_mv[VCS],
                     iv_attrs.attr_boot_voltage_mv[VDN], iv_attrs.attr_boot_voltage_mv[VIO]);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_BOOT_VOLTAGE,
                        iv_procChip, iv_attrs.attr_boot_voltage_mv),
                     "Error from FAPI_ATTR_SET (ATTR_BOOT_VOLTAGE)");

            fapi2::ATTR_BOOT_VOLTAGE_Type l_boot_voltages;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BOOT_VOLTAGE,
                        iv_procChip, l_boot_voltages),
                     "Error from FAPI_ATTR_gET (ATTR_BOOT_VOLTAGE)");

            FAPI_INF("Read back Boot Voltage attributes: VDD = %dmV; VCS = %dmV; VDN = %dmV",
                     l_boot_voltages[VDD], l_boot_voltages[VCS],
                     l_boot_voltages[VDN], l_boot_voltages[VIO]);

            if (l_boot_voltages[VDD] != iv_attrs.attr_boot_voltage_mv[VDD])
            {
                FAPI_INF ("Attribute override VDD boot voltage being used");
            }

            if (l_boot_voltages[VDN] != iv_attrs.attr_boot_voltage_mv[VDN])
            {
                FAPI_INF ("Attribute override VDN boot voltage being used");
            }


        }  // COMPUTE_VOLTAGE_SETTINGS
    }
    while(0);

    // trace values to be used
    FAPI_INF("VDD boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VDD]), (iv_attrs.attr_boot_voltage_mv[VDD]));
    FAPI_INF("VCS boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VCS]), (iv_attrs.attr_boot_voltage_mv[VCS]));
    FAPI_INF("VDN boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VDN]), (iv_attrs.attr_boot_voltage_mv[VDN]));
    FAPI_INF("VIO boot voltage = %d mV (0x%x)",
             (iv_attrs.attr_boot_voltage_mv[VIO]), (iv_attrs.attr_boot_voltage_mv[VIO]));

fapi_try_exit:
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  vpd_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::vpd_init( void )
{
    FAPI_INF(">>>>>>>>>> vpd_init");
    fapi2::ReturnCode l_rc;
    do
    {
        memset (&iv_poundW_data, 0, sizeof(iv_poundW_data));
        memset (&iv_iddqt, 0, sizeof(iv_iddqt));
        memset (iv_operating_points,0,sizeof(iv_operating_points));
        memset (&iv_attr_mvpd_poundV_raw, 0, sizeof(iv_attr_mvpd_poundV_raw));
        memset (&iv_attr_mvpd_poundV_biased, 0, sizeof(iv_attr_mvpd_poundV_biased));

        //Compute fmax, ceil freq
        FAPI_TRY(pm_set_frequency(),
                "pm_set_frequency function failed");;

        //Read #V data
        FAPI_TRY(get_mvpd_poundV(),
                 "get_mvpd_poundV function failed to retrieve pound V data");

        // Apply biased #V values if any
        FAPI_IMP("Apply Biasing to #V");
        FAPI_TRY(apply_biased_values(),
                "apply_biased_values function failed");

        // Compute Pstates
        // This must be done after all stretch and biasing as the reference
        // frequency can be modified
        FAPI_TRY(update_biased_pstates(),
                "update_biased_pstates function failed");

        // Read #AW data
        FAPI_TRY(get_mvpd_poundAW(),
                "get_mvpd_poundAW function failed to retrieve pound AW data");

        // Read #W data
        // Note:  the get_mvpd_poundW has the conditional checking for DDS
        // enablement
        l_rc = get_mvpd_poundW();
        if (l_rc)
        {
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_POUND_W_ACCESS_FAIL(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                              .set_CHIP_TARGET(iv_procChip)
                              .set_FAPI_RC(l_rc),
                               "Pstate Parameter Block get_mvpd_poundW function failed");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

        // Apply biased #W values if any
        FAPI_IMP("Apply Biasing to #W");
        FAPI_TRY(apply_pdw_biased_values(),
                "apply_pdw_biased_values function failed");

        // Read #IQ data
        // if wof is disabled.. don't call IQ function
        if (is_wof_enabled())
        {

            FAPI_INF("Getting IQ (IDDQ) Data");
            l_rc = get_mvpd_iddq ();

            if (l_rc)
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_IQ_ACCESS_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CHIP_TARGET(iv_procChip)
                                   .set_FAPI_RC(l_rc),
                                   "Pstate Parameter Block get_mvpd_iddq function failed");
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
        }
        else
        {
            FAPI_INF("Skipping IQ (IDDQ) Data as WOF is disabled");
            iv_wof_enabled = false;
        }

    } while(0);

    FAPI_INF("<<<<<<<<< vpd_init");

fapi_try_exit:
    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////   get_mvpd_poundAW
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundAW()
{
    FAPI_INF(">>>>>>>>> get_mvpd_poundAW");
    uint8_t* l_fullVpdData = nullptr;
    uint32_t l_vpdSize = 0;

    do
    {

        // First read is to get size of VPD record, note the o_buffer is nullptr
        FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CP00,
                    fapi2::MVPD_KEYWORD_AW,
                    iv_procChip,
                    nullptr,
                    l_vpdSize) );
         FAPI_DBG("AW record size %d", l_vpdSize);

        // Allocate memory for VPD data
        l_fullVpdData = reinterpret_cast<uint8_t*>(malloc(l_vpdSize));

        ATTR_AW_STATIC_DATA_ENABLE_Type l_aw_static_data = 0;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_AW_STATIC_DATA_ENABLE,
                    FAPI_SYSTEM,
                    l_aw_static_data),
                "Error from FAPI_ATTR_GET for attribute ATTR_POUND_AW_STATIC_DATA_ENABLE");

        if (l_aw_static_data)
        {
            //// AW sample data
            const uint8_t g_AWData[] =
            {
                0x02, 0xBC              /*VDN - 700*/,
                0x02, 0xC6              /*VDD - 710*/,
            };

            FAPI_INF("attribute ATTR_AW_STATIC_DATA_ENABLE is set");
            memcpy(l_fullVpdData, &g_AWData, sizeof(l_vpdSize));
        }
        else
        {
            FAPI_INF("attribute ATTR_AW_STATIC_DATA_ENABLE is NOT set");
            // Second read is to get data of VPD record
            FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CP00,
                    fapi2::MVPD_KEYWORD_AW,
                    iv_procChip,
                    l_fullVpdData,
                    l_vpdSize) );
        }

        memcpy(&iv_array_vdn_mv,l_fullVpdData,sizeof(iv_array_vdn_mv));
        memcpy(&iv_array_vdd_mv,(l_fullVpdData + 2),sizeof(iv_array_vdd_mv));

        FAPI_INF("AW VDN array voltage (mv) = %d (0x%X); VDd array voltage (mv) = %d (0x%X)",
                revle16(iv_array_vdn_mv), revle16(iv_array_vdn_mv),
                revle16(iv_array_vdd_mv), revle16(iv_array_vdd_mv));
    }
    while(0);


fapi_try_exit:

    if (l_fullVpdData != nullptr)
    {
        free(l_fullVpdData);
        l_fullVpdData = nullptr;
    }

    FAPI_INF("<<<<<<<<< get_mvpd_poundAW");

    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////   get_mvpd_poundV
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundV()
{
    uint8_t             bucket_id    = 0;
    uint8_t*            l_buffer      =
        reinterpret_cast<uint8_t*>(malloc(sizeof(voltageBucketData_t)) );
    uint8_t*            l_buffer_inc  = nullptr;
    char                outstr[50];
    fapi2::ATTR_SOCKET_POWER_NOMINAL_Type l_powr_nom;
    uint16_t            l_temp;

    do
    {
        FAPI_INF(">>>>>>>>> get_mvpd_poundV");

        memset(l_buffer, 0, sizeof(iv_poundV_raw_data));

        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        ATTR_POUND_V_STATIC_DATA_ENABLE_Type l_poundv_static_data = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUND_V_STATIC_DATA_ENABLE,
                    FAPI_SYSTEM,
                    l_poundv_static_data),
                "Error from FAPI_ATTR_GET for attribute ATTR_POUND_V_STATIC_DATA_ENABLE");

        if (l_poundv_static_data == 1)
        {

            // Bring in data for local testing
#define __INTERNAL_POUNDV__
#include <p10_pstate_parameter_block_int_vpd.H>

            FAPI_INF("attribute ATTR_POUND_V_STATIC_DATA_ENABLE is set");
            memcpy(l_buffer, &g_vpd_PVData, sizeof(g_vpd_PVData));
        }
        else
        {
            FAPI_INF("attribute ATTR_POUND_V_STATIC_DATA_ENABLE is NOT set");
            FAPI_TRY(p10_pm_get_poundv_bucket(iv_procChip, iv_poundV_raw_data))
                memcpy(l_buffer, &iv_poundV_raw_data, sizeof(iv_poundV_raw_data));
        }

        voltageBucketData_t* p_poundV_data = reinterpret_cast<voltageBucketData_t*>(l_buffer);
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SOCKET_POWER_NOMINAL,
                    iv_procChip, l_powr_nom));
        //Update power nominal target
        if (!l_powr_nom)
        {
            l_powr_nom = p_poundV_data->other_info.TSrtSocPowTgt;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SOCKET_POWER_NOMINAL,
                        iv_procChip, l_powr_nom));
        }

        FAPI_INF("Raw #V pre-overrides");
        FAPI_TRY(print_voltage_bucket(iv_procChip, p_poundV_data));

        // Deal with parts having erroneous CF0-CF2 VPD frequencies.  If the CF0-CF3
        // frequencies match, replace the CF0-CF2 with 2000, 2400 and 2800 respectively.
        // The voltages and currents will still have the CF3 values but these will at
        // least be legal.
        if (p_poundV_data->operating_pts[CF0].core_frequency == p_poundV_data->operating_pts[CF3].core_frequency &&
            p_poundV_data->operating_pts[CF1].core_frequency == p_poundV_data->operating_pts[CF3].core_frequency &&
            p_poundV_data->operating_pts[CF2].core_frequency == p_poundV_data->operating_pts[CF3].core_frequency )
        {
            if (p_poundV_data->operating_pts[CF3].core_frequency != 0)
            {
                FAPI_IMP("VPD CORRECTION: Parts with replicated CF3 data in CF0-CF2 detected.");
                FAPI_INF("VPD CORRECTION: CF0 %04d CF1 %04d CF2 %04d CF3 %04d",
                            p_poundV_data->operating_pts[CF0].core_frequency,
                            p_poundV_data->operating_pts[CF1].core_frequency,
                            p_poundV_data->operating_pts[CF2].core_frequency,
                            p_poundV_data->operating_pts[CF3].core_frequency);
                FAPI_IMP("VPD CORRECTION: Changing internal structures for CF0-CF2 to 2000, 2400 and 2800 respectively");
                p_poundV_data->operating_pts[CF0].core_frequency = revle16(2000);
                p_poundV_data->operating_pts[CF1].core_frequency = revle16(2400);
                p_poundV_data->operating_pts[CF2].core_frequency = revle16(2800);

                FAPI_INF("VPD CORRECTION: post #V update");
                FAPI_TRY(print_voltage_bucket(iv_procChip, p_poundV_data));
            }
            else
            {
                FAPI_INF("VPD CORRECTION: Zero CF3 detected");
                disable_pstates();
                break;
            }

        }

        // Apply WOF Table Overrides as applicable
        FAPI_INF("> Applying WOF Overrides");

        bool wof_state = is_wof_enabled();

        FAPI_TRY(wof_apply_overrides(iv_procChip, p_poundV_data,wof_state));
        FAPI_INF("< Applying WOF Overrides");

        // Update the class variables
        FAPI_TRY(set_wof_override_flags(p_poundV_data));

#define UINT16_GET(__uint8_ptr)  \
        ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))

        bucket_id = iv_poundV_raw_data.bucketId;
        FAPI_INF("#V bucket id = %u", bucket_id);

        l_buffer_inc = l_buffer;
        l_buffer_inc++;
        for (int i = 0; i < NUM_PV_POINTS; i++)
        {
            //frequency_mhz
            iv_attr_mvpd_poundV_raw[i].frequency_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].frequency_mhz,
                    iv_attr_mvpd_poundV_raw[i].frequency_mhz);
            l_buffer_inc += 2;
            //vdd_mv
            iv_attr_mvpd_poundV_raw[i].vdd_mv= (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vdd_mv,
                    iv_attr_mvpd_poundV_raw[i].vdd_mv);
            l_buffer_inc += 2;
            //idd_tdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma);
            l_buffer_inc += 2;
            //idd_tdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_dc_10ma);
            l_buffer_inc += 2;
            //idd_rdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].idd_rdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_rdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_tdp_ac_10ma);
            l_buffer_inc += 2;
            //idd_rdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_rdp_dc_10ma);
            l_buffer_inc += 2;
            //vcs_mv
            iv_attr_mvpd_poundV_raw[i].vcs_mv= (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vcs_mv,
                    iv_attr_mvpd_poundV_raw[i].vcs_mv);
            l_buffer_inc += 2;
            //ics_tdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_tdp_ac_10ma);
            l_buffer_inc += 2;
            //ics_tdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_tdp_dc_10ma);
            l_buffer_inc += 2;
            //ics_rdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].ics_rdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_rdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_rdp_ac_10ma);
            l_buffer_inc += 2;
            //ics_rdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].ics_rdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_rdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].ics_rdp_dc_10ma);
            l_buffer_inc += 2;
            //frequency_guardband_sort_mhz
#if 0
            iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz,
                    iv_attr_mvpd_poundV_raw[i].frequency_guardband_sort_mhz);
#endif
            l_buffer_inc += 2;
            //vdd_vmin
            iv_attr_mvpd_poundV_raw[i].vdd_vmin = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vdd_vmin,
                    iv_attr_mvpd_poundV_raw[i].vdd_vmin);
            l_buffer_inc += 2;

            //idd_power_pattern_10ma
#if 0
            iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma,
                    iv_attr_mvpd_poundV_raw[i].idd_power_pattern_10ma);
#endif
            l_buffer_inc += 2;
            //core_power_pattern_temp_0p5C
#if 0
            iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C = (uint32_t) *l_buffer_inc;
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C,
                    iv_attr_mvpd_poundV_raw[i].core_power_pattern_temp_0p5C);
#endif
            l_buffer_inc += 1;

            //rt_tdp_ac_10ma
            iv_attr_mvpd_poundV_raw[i].rt_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].rt_tdp_ac_10ma,
                    iv_attr_mvpd_poundV_raw[i].rt_tdp_ac_10ma);

            l_buffer_inc += 2;

            //rt_tdp_dc_10ma
            iv_attr_mvpd_poundV_raw[i].rt_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
            FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].rt_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_raw[i].rt_tdp_dc_10ma);

            // rt_tdp_dc_10ma(wbyte) + spare (2byte)
            l_buffer_inc += 4;
        }

        iv_poundV_bucket_id = bucket_id;
//        poison_mvpd_poundV();
        FAPI_TRY(chk_valid_poundv(false));

        iv_vddPsavFreq = (uint32_t)(revle16(iv_poundV_raw_data.other_info.VddPsavCoreFreq));
        iv_vddWofBaseFreq = (uint32_t)(revle16(iv_poundV_raw_data.other_info.VddTdpWofCoreFreq));
        iv_vddUTFreq = (uint32_t)(revle16(iv_poundV_raw_data.other_info.VddUTCoreFreq));
        iv_vddFmaxFreq = (uint32_t)(revle16(iv_poundV_raw_data.other_info.VddFmxCoreFreq));

        FAPI_INF("Pointer Frequencies:  PSAV  0x%04x (%04d) WOF  0x%04x (%04d) UT  0x%04x (%04d) Fmax  0x%04x (%04d)",
                        iv_vddPsavFreq, iv_vddPsavFreq,
                        iv_vddWofBaseFreq, iv_vddWofBaseFreq,
                        iv_vddUTFreq, iv_vddUTFreq,
                        iv_vddFmaxFreq, iv_vddFmaxFreq);

        FAPI_INF("Reference Frequency: 0x%04x (%04d)",
                        iv_reference_frequency_mhz, iv_reference_frequency_mhz);

        //Update pstate for all points
        for (uint32_t i = 0; i < NUM_PV_POINTS; i++)
        {
            iv_attr_mvpd_poundV_raw[i].pstate = (iv_reference_frequency_mhz  -
            iv_attr_mvpd_poundV_raw[i].frequency_mhz) * 1000 / (iv_frequency_step_khz);

            FAPI_INF("CF[%d] Raw Frequency: 0x%04x (%04d) PSTATE 0x%02x (%03d)",
                        i,
                        iv_attr_mvpd_poundV_raw[i].frequency_mhz, iv_attr_mvpd_poundV_raw[i].frequency_mhz,
                        iv_attr_mvpd_poundV_raw[i].pstate, iv_attr_mvpd_poundV_raw[i].pstate);
        }

        // Static Rails
        strcpy(outstr, "vdn_mv");
        iv_attr_mvpd_poundV_static_rails.vdn_mv = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.vdn_mv,
                iv_attr_mvpd_poundV_static_rails.vdn_mv,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "idn_tdp_ac_10ma");
        iv_attr_mvpd_poundV_static_rails.idn_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.idn_tdp_ac_10ma,
                iv_attr_mvpd_poundV_static_rails.idn_tdp_ac_10ma,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "idn_tdp_dc_10ma");
        iv_attr_mvpd_poundV_static_rails.idn_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.idn_tdp_dc_10ma,
                iv_attr_mvpd_poundV_static_rails.idn_tdp_dc_10ma,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vio_mv");
        iv_attr_mvpd_poundV_static_rails.vio_mv = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.vio_mv,
                iv_attr_mvpd_poundV_static_rails.vio_mv,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "iio_tdp_ac_10ma");
        iv_attr_mvpd_poundV_static_rails.iio_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.iio_tdp_ac_10ma,
                iv_attr_mvpd_poundV_static_rails.iio_tdp_ac_10ma,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "iio_tdp_dc_10ma");
        iv_attr_mvpd_poundV_static_rails.iio_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.iio_tdp_dc_10ma,
                iv_attr_mvpd_poundV_static_rails.iio_tdp_dc_10ma,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vpci_mv");
        iv_attr_mvpd_poundV_static_rails.vpci_mv = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.vpci_mv,
                iv_attr_mvpd_poundV_static_rails.vpci_mv,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "ipci_tdp_ac_10ma");
        iv_attr_mvpd_poundV_static_rails.ipci_tdp_ac_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.ipci_tdp_ac_10ma,
                iv_attr_mvpd_poundV_static_rails.ipci_tdp_ac_10ma,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "ipci_tdp_dc_10ma");
        iv_attr_mvpd_poundV_static_rails.ipci_tdp_dc_10ma = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_static_rails.ipci_tdp_dc_10ma,
                iv_attr_mvpd_poundV_static_rails.ipci_tdp_dc_10ma,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "avdd_voltage_mv (used)");
        l_temp = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", l_temp, l_temp, outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "avdd_tdp_ac_10ma (used)");
        l_temp = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", l_temp, l_temp, outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "avdd_tdp_ac_10ma (used)");
        l_temp = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", l_temp, l_temp, outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "model_data_flag");
        iv_pdv_model_data = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_pdv_model_data, iv_pdv_model_data, outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "vdd_vmax_mv (used)");
        l_temp = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", l_temp, l_temp, outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vcs_vmax_mv (used)");
        l_temp = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", l_temp, l_temp, outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "QRVRM enable flag");
        iv_qrvrm_enable_flag = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_pdv_model_data, iv_pdv_model_data, outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "spare (used)");
        l_temp = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", l_temp, l_temp, outstr);
        l_buffer_inc += 3;

        // Other Rails

        strcpy(outstr, "pau_frequency_mhz");
        iv_attr_mvpd_poundV_other_info.pau_frequency_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.pau_frequency_mhz,
                iv_attr_mvpd_poundV_other_info.pau_frequency_mhz,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "total_sort_socket_power_target_W");
        iv_attr_mvpd_poundV_other_info.total_sort_socket_power_target_W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.total_sort_socket_power_target_W,
                iv_attr_mvpd_poundV_other_info.total_sort_socket_power_target_W,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vdn_sort_socket_power_alloc_W");
        iv_attr_mvpd_poundV_other_info.vdn_sort_socket_power_alloc_W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vdn_sort_socket_power_alloc_W,
                iv_attr_mvpd_poundV_other_info.vdn_sort_socket_power_alloc_W,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vio_sort_socket_power_alloc_W");
        iv_attr_mvpd_poundV_other_info.vio_sort_socket_power_alloc_W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vio_sort_socket_power_alloc_W,
                iv_attr_mvpd_poundV_other_info.vio_sort_socket_power_alloc_W,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vpci_sort_socket_power_alloc_W");
        iv_attr_mvpd_poundV_other_info.vpci_sort_socket_power_alloc_W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vpci_sort_socket_power_alloc_W,
                iv_attr_mvpd_poundV_other_info.vpci_sort_socket_power_alloc_W,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "avdd_power_actual_0p1W");
        l_temp = *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", l_temp, l_temp, outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "total_sort_socket_power_actual_0p1W");
        iv_attr_mvpd_poundV_other_info.total_sort_socket_power_actual_0p1W = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.total_sort_socket_power_actual_0p1W,
                iv_attr_mvpd_poundV_other_info.total_sort_socket_power_actual_0p1W,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "idd_rdp_limit_0p1A");
        iv_attr_mvpd_poundV_other_info.idd_rdp_limit_0p1A = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.idd_rdp_limit_0p1A,
                iv_attr_mvpd_poundV_other_info.idd_rdp_limit_0p1A,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "vdd_tdp_wof_index");
        iv_attr_mvpd_poundV_other_info.vdd_tdp_wof_index = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vdd_tdp_wof_index,
                iv_attr_mvpd_poundV_other_info.vdd_tdp_wof_index,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "vcs_tdp_wof_index");
        iv_attr_mvpd_poundV_other_info.vcs_tdp_wof_index = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vcs_tdp_wof_index,
                iv_attr_mvpd_poundV_other_info.vcs_tdp_wof_index,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "vio_tdp_wof_index");
        iv_attr_mvpd_poundV_other_info.vio_tdp_wof_index = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.vio_tdp_wof_index,
                iv_attr_mvpd_poundV_other_info.vio_tdp_wof_index,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "amb_cond_tdp_wof_index");
        iv_attr_mvpd_poundV_other_info.amb_cond_tdp_wof_index = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.amb_cond_tdp_wof_index,
                iv_attr_mvpd_poundV_other_info.amb_cond_tdp_wof_index,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "mode_interpolation");
        iv_attr_mvpd_poundV_other_info.mode_interpolation = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.mode_interpolation,
                iv_attr_mvpd_poundV_other_info.mode_interpolation,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "rdp_sort_power_temp_0p5C");
        iv_attr_mvpd_poundV_other_info.rdp_sort_power_temp_0p5C = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.rdp_sort_power_temp_0p5C,
                iv_attr_mvpd_poundV_other_info.rdp_sort_power_temp_0p5C,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "tdp_sort_power_temp_0p5C");
        iv_attr_mvpd_poundV_other_info.tdp_sort_power_temp_0p5C = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.tdp_sort_power_temp_0p5C,
                iv_attr_mvpd_poundV_other_info.tdp_sort_power_temp_0p5C,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "tdp_wof_base_freq_mhz");
        iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz,
                iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "fixed_freq_mhz");
        iv_attr_mvpd_poundV_other_info.fixed_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.fixed_freq_mhz,
                iv_attr_mvpd_poundV_other_info.fixed_freq_mhz,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "powersave_freq_mhz");
        iv_attr_mvpd_poundV_other_info.powersave_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.powersave_freq_mhz,
                iv_attr_mvpd_poundV_other_info.powersave_freq_mhz,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "ultraturbo_freq_mhz");
        iv_attr_mvpd_poundV_other_info.ultraturbo_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.ultraturbo_freq_mhz,
                iv_attr_mvpd_poundV_other_info.ultraturbo_freq_mhz,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "fmax_freq_mhz");
        iv_attr_mvpd_poundV_other_info.fmax_freq_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.fmax_freq_mhz,
                iv_attr_mvpd_poundV_other_info.fmax_freq_mhz,
                outstr);
        l_buffer_inc += 2;

        strcpy(outstr, "mma_throttle_temp_0p5C");
        iv_attr_mvpd_poundV_other_info.mma_throttle_temp_0p5C = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.mma_throttle_temp_0p5C,
                iv_attr_mvpd_poundV_other_info.mma_throttle_temp_0p5C,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "io_throttle_temp_0p5C");
        iv_attr_mvpd_poundV_other_info.io_throttle_temp_0p5C = (uint32_t) *l_buffer_inc;
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.io_throttle_temp_0p5C,
                iv_attr_mvpd_poundV_other_info.io_throttle_temp_0p5C,
                outstr);
        l_buffer_inc += 1;

        strcpy(outstr, "fixed_freq_mode_power_target_0p");
        iv_attr_mvpd_poundV_other_info.fixed_freq_mode_power_target_0p = (uint32_t) UINT16_GET(l_buffer_inc);
        FAPI_INF("#V data = 0x%04X  %-6d (%s)", iv_attr_mvpd_poundV_other_info.fixed_freq_mode_power_target_0p,
                iv_attr_mvpd_poundV_other_info.fixed_freq_mode_power_target_0p,
                outstr);
        l_buffer_inc += 2;

        // Pull out the "pointer" frequencies that referenece the CF curve
        iv_vddPsavFreq = (uint32_t)(iv_attr_mvpd_poundV_other_info.powersave_freq_mhz);

        iv_vddWofBaseFreq = (uint32_t)(iv_attr_mvpd_poundV_other_info.tdp_wof_base_freq_mhz);
        iv_vddUTFreq = (uint32_t)(iv_attr_mvpd_poundV_other_info.ultraturbo_freq_mhz);
        iv_vddFmaxFreq = (uint32_t)(iv_attr_mvpd_poundV_other_info.fmax_freq_mhz);

        FAPI_INF("Pointer Frequencies: PSAV 0x%03X (%04d) WOF 0x%03X (%04d) UT 0x%03X (%04d) Fmax 0x%03X (%04d)",
                iv_vddPsavFreq,
                iv_vddPsavFreq,
                iv_vddWofBaseFreq,
                iv_vddWofBaseFreq,
                iv_vddUTFreq,
                iv_vddUTFreq,
                iv_vddFmaxFreq,
                iv_vddFmaxFreq);

        // Validate the Model Data Flag(6) to see if WOF can be enabled
        // with the TDP currents present
        fapi2::ATTR_CHIP_EC_FEATURE_PDV_CURRENT_MARK_Type l_pdv_current_mark;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_PDV_CURRENT_MARK,
                    iv_procChip,
                    l_pdv_current_mark),
                "Error from FAPI_ATTR_GET for attribute ATTR_CHIP_EC_FEATURE_PDV_CURRENT_MARK");

        if (l_pdv_current_mark && is_wof_enabled())
        {
#ifdef __HOSTBOOT_MODULE
            fapi2::ATTR_SYSTEM_PDV_TDP_CURRENT_VALIDATION_MODE_Type l_pdv_tdp_current_mode;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_TDP_CURRENT_VALIDATION_MODE,
                    FAPI_SYSTEM,
                    l_pdv_tdp_current_mode),
                "Error from FAPI_ATTR_GET for attribute ATTR_SYSTEM_PDV_TDP_CURRENT_FW_VALIDATION_MODE");
            FAPI_INF("Running TDP current mark checking under FW controls = %d", l_pdv_tdp_current_mode);
#else

            fapi2::ATTR_SYSTEM_PDV_TDP_CURRENT_LAB_VALIDATION_MODE_Type l_pdv_tdp_current_mode;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_TDP_CURRENT_LAB_VALIDATION_MODE,
                    FAPI_SYSTEM,
                    l_pdv_tdp_current_mode),
                "Error from FAPI_ATTR_GET for attribute ATTR_SYSTEM_PDV_TDP_CURRENT_LAB_VALIDATION_MODE_Type");
            FAPI_INF("Running TDP current mark checking under Lab controls = %d", l_pdv_tdp_current_mode);
#endif
            if ((iv_pdv_model_data & 0x01) == 0x01)
            {
                FAPI_INF("WOF will be disabled as model_data field indicates not a sorted part");
                disable_wof();
                disable_dds();
            }

            if (l_pdv_tdp_current_mode != fapi2::ENUM_ATTR_SYSTEM_PDV_TDP_CURRENT_VALIDATION_MODE_OFF )
            {
                if ((iv_pdv_model_data & 0x02) != 0x02)
                {
                    disable_wof();

                    if ( l_pdv_tdp_current_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_TDP_CURRENT_VALIDATION_MODE_WARN )
                    {
                        FAPI_INF("WARNING: TDP current mark is off for this DD level.  WOF Disabled.");
                    }

                    if ( l_pdv_tdp_current_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_TDP_CURRENT_VALIDATION_MODE_INFO )
                    {
                        FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_PDV_TDP_CURRENT_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_MODEL_DATA_FLAG(iv_pdv_model_data),
                                "Pstate Parameter Block #V TDP Current Marker fail");
                    }
                    else if ( l_pdv_tdp_current_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_TDP_CURRENT_VALIDATION_MODE_FAIL )
                    {
                        FAPI_ERR("ERROR: TDP current mark is off for this DD level.  WOF Disabled.");
                        FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_PDV_TDP_CURRENT_ERROR()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_MODEL_DATA_FLAG(iv_pdv_model_data),
                                "Pstate Parameter Block #V TDP Current Marker fail");
                    }
                }
            }
        }
        else
        {
            if ((iv_pdv_model_data & 0x01) == 0x01)
            {
                FAPI_INF("WOF will be disabled as model_data field indicates not a sorted part");
                disable_wof();
                disable_dds();
            }
        }
    }
    while(0);

fapi_try_exit:

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        disable_pstates();
    }
    free (l_buffer);
    FAPI_INF("<<<<<<<<< get_mvpd_poundV");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   chk_valid_poundv
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::chk_valid_poundv(
                      const bool i_biased_state)
{
    const char*     pv_op_str[NUM_PV_POINTS] = VPD_PV_STR;
    uint8_t         i = 0;
    uint8_t         l_chiplet_num = iv_procChip.getChipletNumber();

    FAPI_INF("> chk_valid_poundv" );
    //Biased
    if (i_biased_state)
    {
        memcpy (iv_attr_mvpd_data,iv_attr_mvpd_poundV_biased,sizeof(iv_attr_mvpd_data));
    }
    else
    {
        memcpy (iv_attr_mvpd_data,iv_attr_mvpd_poundV_raw,sizeof(iv_attr_mvpd_data));
    }

    FAPI_INF(">> chk_valid_poundv for %s values", (i_biased_state) ? "biased" : "non-biased" );


    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE_Type l_pdv_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE,
                FAPI_SYSTEM, l_pdv_mode));

    do
    {
        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_OFF)
        {
            disable_pstates();
            FAPI_INF("**** WARNING : #V zero value checking is not being performed");
            FAPI_INF("**** WARNING : Pstates are disabled");
            break;
        }

        // check for non-zero freq, voltage, or current in valid operating points
        for (i = 0; i <= NUM_PV_POINTS - 1; i++)
        {
            FAPI_INF("Checking for Zero valued %s data in each #V operating point (%s) "
                    "f=%u vd=%u idtac=%u idtdc=%u idrac=%u idrdc=%u vc=%u ictac=%u ictdc=%u "
                    "icrac=%u icrdc=%u vdmin=%u irtrac=%u irtrdc=%u ",
                    (i_biased_state) ? "biased" : "non-biased",
                    pv_op_str[i],
                    iv_attr_mvpd_data[i].frequency_mhz,
                    iv_attr_mvpd_data[i].vdd_mv,
                    iv_attr_mvpd_data[i].idd_tdp_ac_10ma,
                    iv_attr_mvpd_data[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_data[i].idd_rdp_ac_10ma,
                    iv_attr_mvpd_data[i].idd_rdp_dc_10ma,
                    iv_attr_mvpd_data[i].vcs_mv,
                    iv_attr_mvpd_data[i].ics_tdp_ac_10ma,
                    iv_attr_mvpd_data[i].ics_tdp_dc_10ma,
                    iv_attr_mvpd_data[i].ics_rdp_ac_10ma,
                    iv_attr_mvpd_data[i].ics_rdp_dc_10ma,
                    iv_attr_mvpd_data[i].vdd_vmin,
                    iv_attr_mvpd_data[i].rt_tdp_ac_10ma,
                    iv_attr_mvpd_data[i].rt_tdp_dc_10ma
                    );

            if (POUNDV_POINTS_CHECK(i))
            {
                disable_pstates();

                if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_WARN ||
                    l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO   )
                {
                    FAPI_INF("**** WARNING : Zero valued data found in #V (bucket id = %u  op point = %s)",
                            iv_poundV_bucket_id, pv_op_str[i]);
                    FAPI_INF("**** WARNING : Pstates (and all dependent functions) are disabled but continuing on anyway.");
                    FAPI_INF("**** WARNING : Tracing due to ATTR_SYSTEM_PDV_VALIDATION_MODE = WARN or INFO");

                    // Log errors based on biased inputs or not
                    if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO)
                    {
                        if (i_biased_state)
                        {
                            if (!fapi2::is_platform<fapi2::PLAT_CRONUS>())
                            {
                                FAPI_ASSERT_NOEXIT(false,
                                        fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                        .set_CHIP_TARGET(iv_procChip)
                                        .set_CHIPLET_NUMBER(l_chiplet_num)
                                        .set_BUCKET(iv_poundV_bucket_id)
                                        .set_POINT(i)
                                        POUNDV_POINTS_PRINT(i,A),
                                        "Pstate Parameter Block Biased #V Zero contents error being logged");
                            }
                        }
                        else
                        {
                            if (!fapi2::is_platform<fapi2::PLAT_CRONUS>())
                            {
                                FAPI_ASSERT_NOEXIT(false,
                                        fapi2::PSTATE_PB_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                        .set_CHIP_TARGET(iv_procChip)
                                        .set_CHIPLET_NUMBER(l_chiplet_num)
                                        .set_BUCKET(iv_poundV_bucket_id)
                                        .set_POINT(i)
                                        POUNDV_POINTS_PRINT(i,A),
                                        "Pstate Parameter Block #V Zero contents error being logged");
                            }
                        }
                    }
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    break;
                }

                if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
                {
                    FAPI_ERR("**** ERROR : Zero valued data found in #V (bucket id = %u  op point = %s)",
                            iv_poundV_bucket_id, pv_op_str[i]);
                    FAPI_ERR("**** ERROR : Halting due to ATTR_SYSTEM_PDV_VALIDATION_MODE = FAIL");

                    // Error out has Pstate and all dependent functions are suspious.
                    if (i_biased_state)
                    {
                        FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                POUNDV_POINTS_PRINT(i,A),
                                "Pstate Parameter Block Biased #V Zero contents error being logged");
                    }
                    else
                    {
                        FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_POUNDV_ZERO_ERROR()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                POUNDV_POINTS_PRINT(i,A),
                                "Pstate Parameter Block #V Zero contents error being logged");
                    }
                }  // Halt disable
            }  // #V point zero check
        } // Operating point loop

        // Don't do slope checks if the 0 checks failed.
        if (!is_pstates_enabled())
        {
            break;
        }

        // check valid operating points' values have this relationship (power save <= nominal <= turbo <= ultraturbo)
        for (i = 1; i <= (NUM_PV_POINTS) - 1; i++)
        {
            FAPI_INF("Checking for relationship between #V operating point (%s <= %s)",
                    pv_op_str[i - 1], pv_op_str[i]);

             if ((iv_attr_mvpd_data[i - 1].frequency_mhz >=
                 iv_attr_mvpd_data[i].frequency_mhz) ||
                (iv_attr_mvpd_data[i - 1].vdd_mv >
                 iv_attr_mvpd_data[i].vdd_mv) ||
                (iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma >
                 iv_attr_mvpd_data[i].idd_tdp_ac_10ma) ||
                (iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma >
                iv_attr_mvpd_data[i].idd_tdp_dc_10ma) ||
                (iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma >
                iv_attr_mvpd_data[i].idd_rdp_ac_10ma) ||
                (iv_attr_mvpd_data[i  -1].idd_rdp_dc_10ma >
                iv_attr_mvpd_data[i].idd_rdp_dc_10ma) ||
                (iv_attr_mvpd_data[i - 1].vcs_mv >
                iv_attr_mvpd_data[i].vcs_mv) ||
                (iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma >
                iv_attr_mvpd_data[i].ics_tdp_ac_10ma) ||
                (iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma >
                iv_attr_mvpd_data[i].ics_tdp_dc_10ma) ||
                (iv_attr_mvpd_data[i - 1].ics_rdp_ac_10ma >
                iv_attr_mvpd_data[i].ics_rdp_ac_10ma) ||
                (iv_attr_mvpd_data[i - 1].ics_rdp_dc_10ma >
                iv_attr_mvpd_data[i].ics_rdp_dc_10ma) ||
                (iv_attr_mvpd_data[i - 1].rt_tdp_ac_10ma >
                iv_attr_mvpd_data[i].rt_tdp_ac_10ma) ||
                (iv_attr_mvpd_data[i - 1].rt_tdp_ac_10ma >
                iv_attr_mvpd_data[i].rt_tdp_ac_10ma))
            {
                disable_pstates();

                 FAPI_INF("%s Frequency value %u is %s %s Frequency value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].frequency_mhz,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].frequency_mhz,
                            iv_attr_mvpd_data[i].frequency_mhz),pv_op_str[i], iv_attr_mvpd_data[i].frequency_mhz);
                FAPI_INF("%s VDD voltage value %u is %s %s VDD voltage value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].vdd_mv,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].vdd_mv,
                            iv_attr_mvpd_data[i].vdd_mv),pv_op_str[i], iv_attr_mvpd_data[i].vdd_mv);
                FAPI_INF("%s IDD tdp ac value %u is %s %s IDD tdp ac value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_tdp_ac_10ma,
                            iv_attr_mvpd_data[i].idd_tdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_tdp_ac_10ma);
                FAPI_INF("%s IDD tdp dc value %u is %s %s IDD tdp dc value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_tdp_dc_10ma,
                            iv_attr_mvpd_data[i].idd_tdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_tdp_dc_10ma);
                FAPI_INF("%s IDD rdp ac value %u is %s %s IDD rdp ac value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_rdp_ac_10ma,
                            iv_attr_mvpd_data[i].idd_rdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_rdp_ac_10ma);
                FAPI_INF("%s IDD rdp dc value %u is %s %s IDD rdp dc value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].idd_rdp_dc_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].idd_rdp_dc_10ma,
                            iv_attr_mvpd_data[i].idd_rdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].idd_rdp_dc_10ma);
                FAPI_INF("%s VCS voltage value %u is %s %s VCS voltage value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].vcs_mv,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].vcs_mv,
                            iv_attr_mvpd_data[i].vcs_mv),pv_op_str[i], iv_attr_mvpd_data[i].vcs_mv);
                FAPI_INF("%s ICS tdp ac value %u is %s %s ICS tdp ac value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_tdp_ac_10ma,
                            iv_attr_mvpd_data[i].ics_tdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_tdp_ac_10ma);
                FAPI_INF("%s ICS tdp dc value %u is %s %s ICS tdp dc value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_tdp_dc_10ma,
                            iv_attr_mvpd_data[i].ics_tdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_tdp_dc_10ma);
                FAPI_INF("%s ICS rdp ac value %u is %s %s ICS rdp ac value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_rdp_ac_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_rdp_ac_10ma,
                            iv_attr_mvpd_data[i].ics_rdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_rdp_ac_10ma);
                FAPI_INF("%s ICS rdp dc value %u is %s %s ICS rdp dc value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].ics_rdp_dc_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].ics_rdp_dc_10ma,
                            iv_attr_mvpd_data[i].ics_rdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].ics_rdp_dc_10ma);

                FAPI_INF("%s TDP RT AC value %u is %s %s TDP RT AC value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].rt_tdp_ac_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].rt_tdp_ac_10ma,
                            iv_attr_mvpd_data[i].rt_tdp_ac_10ma),pv_op_str[i], iv_attr_mvpd_data[i].rt_tdp_ac_10ma);
                FAPI_INF("%s TDP RT DC value %u is %s %s TDP RT DC value %u",
                        pv_op_str[i - 1], iv_attr_mvpd_data[i - 1].rt_tdp_dc_10ma,
                        POUNDV_SLOPE_CHECK(iv_attr_mvpd_data[i - 1].rt_tdp_dc_10ma,
                            iv_attr_mvpd_data[i].rt_tdp_dc_10ma),pv_op_str[i], iv_attr_mvpd_data[i].rt_tdp_dc_10ma);

                if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_WARN ||
                    l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO   )
                {
                    FAPI_INF("**** WARNING : halt on #V validity checking has been "
                            "disabled due to ATTR_SYSTEM_PDV_VALIDATION_MODE = WARN | INFO");
                    FAPI_INF("**** WARNING : Relationship error between #V operating point "
                            "%s > %s  bucket id = %u  op point = %u",
                            pv_op_str[i - 1], pv_op_str[i], iv_poundV_bucket_id, i);
                    FAPI_INF("**** WARNING : Pstates have been disabled but continuing on.");
                }

                else // FAIL
                {
                    FAPI_INF("**** ERROR : Relationship "
                            "error between #V operating point %s > %s  bucket id = %u  op point = %u",
                            pv_op_str[i - 1], pv_op_str[i], iv_poundV_bucket_id, i);
                }

                if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO)
                {
                    // Log the error only.
                    if (i_biased_state)
                    {
                        FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                POUNDV_POINTS_PRINT(i-1,A)
                                POUNDV_POINTS_PRINT(i,B),
                                "Pstate Parameter Block Biased #V disorder contents error being logged");

                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                        break;
                    }
                    else
                    {
                        FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                POUNDV_POINTS_PRINT(i-1,A)
                                POUNDV_POINTS_PRINT(i,B),
                                "Pstate Parameter Block #V disorder contents error being logged");
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                        break;
                    }
                }

                if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
                {
                    // Error out has Pstate and all dependent functions are suspicious.
                    if (i_biased_state)
                    {
                        FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                POUNDV_POINTS_PRINT(i-1,A)
                                POUNDV_POINTS_PRINT(i,B),
                                "Pstate Parameter Block Biased #V disorder contents error being logged");
                    }
                    else
                    {
                        FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                POUNDV_POINTS_PRINT(i-1,A)
                                POUNDV_POINTS_PRINT(i,B),
                                "Pstate Parameter Block #V disorder contents error being logged");
                    }
                } // fail
            }  // validity failed
        } // point loop
    } while(0);

fapi_try_exit:

    FAPI_INF("< chk_valid_poundv");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   disable_pstates
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_pstates()
{
    FAPI_INF(">>> Pstates being disabled.")
    FAPI_INF(">>> disable_pstates %d", iv_pstates_enabled);
    if (iv_pstates_enabled)
    {
        FAPI_INF(">>> Pstates going from enabled to disabled.")
        iv_pstates_enabled = false;
    }

    disable_resclk();
    disable_ocs();
    disable_dds();
    disable_wof();
    disable_underv();
    disable_overv();

}

///////////////////////////////////////////////////////////
////////   disable_resclk
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_resclk()
{
    if (iv_resclk_enabled)
    {
        FAPI_INF(">>> Resonant Clocks being disabled.")
        iv_resclk_enabled = false;
    }
}

//////////////////////////////////////////////////////////
////////   disable_wof
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_wof()
{
    if (iv_wof_enabled)
    {
        FAPI_INF(">>> WOF being disabled.")
        iv_wof_enabled = false;
    }
}

//////////////////////////////////////////////////////////
////////   disable_rvrm
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_rvrm()
{
    if (iv_rvrm_enabled)
    {
        FAPI_INF(">>> RVRM being disabled.")
        iv_rvrm_enabled = false;
    }
}

//////////////////////////////////////////////////////////
////////   disable_dds
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_dds()
{
    if (iv_dds_enabled)
    {
        FAPI_INF(">>> DDS being disabled.")
        iv_dds_enabled = false;
    }

    disable_ocs();
    disable_underv();
    disable_overv();

}

//////////////////////////////////////////////////////////
////////   disable_ocs
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_ocs()
{
    if (iv_ocs_enabled)
    {
        FAPI_INF(">>> Over Current Sensor (OCS) being disabled.")
        iv_ocs_enabled = false;
    }

    disable_underv();
    disable_overv();

// RTC 270130
// Commented out to allow for indepenent WOF<>OCS testing
// In the product, they are related depending on the OCS_MODE
// in WOF table it set, then don't disable wof
//    disable_wof();
}

//////////////////////////////////////////////////////////
////////   disable_wov_underv
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_underv()
{
    if (iv_wov_underv_enabled)
    {
        FAPI_INF(">>> Undervolting being disabled.")
        iv_wov_underv_enabled = false;
    }
}

///////////////////////////////////////////////////////////
////////   disable_wov_overv
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_overv()
{
    if (iv_wov_overv_enabled)
    {
        FAPI_INF(">>> Overvolting being disabled.")
        iv_wov_overv_enabled = false;
    }
}

//////////////////////////////////////////////////////////
////////   disable_wof_throttle
///////////////////////////////////////////////////////////
void PlatPmPPB::disable_wof_throttle()
{
    if (iv_wov_underv_enabled)
    {
        FAPI_INF(">>> WOF throttling being disabled.")
        iv_wof_throttle_enabled = false;
    }
}

///////////////////////////////////////////////////////////
////////   is_pstates_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_pstates_enabled()
{
    if (!isPstateModeEnabled() && !iv_boot_mode)
    {
        FAPI_INF(">>> Pstates being disabled due to isPstateModeEnabled not being true.")
        iv_pstates_enabled = false;
    }

    return iv_pstates_enabled;
}

///////////////////////////////////////////////////////////
////////   is_resclk_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_resclk_enabled()
{
    if (iv_attrs.attr_resclk_disable && iv_resclk_enabled)
    {
        FAPI_INF(">>> Resclk disabled due to system attribute control.")
        iv_resclk_enabled = false;
    }
    return iv_resclk_enabled;
}

///////////////////////////////////////////////////////////
////////   is_dds_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_dds_enabled()
{
    if (iv_attrs.attr_system_dds_disable && iv_dds_enabled)
    {
        FAPI_INF(">>> DDS disabled due to system attribute control.")
        iv_dds_enabled = false;
    }
    else if (iv_attrs.attr_dd_dds_not_supported)
    {
        FAPI_INF(">>> DDS disabled due to unsupported EC level.")
        iv_dds_enabled = false;
    }

    return iv_dds_enabled;
}

///////////////////////////////////////////////////////////
////////  is_wof_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wof_enabled()
{
    if (iv_attrs.attr_system_wof_disable && iv_wof_enabled)
    {
        FAPI_DBG(">>> WOF disabled due to system attribute control.")
        iv_wof_enabled = false;
    }

    return iv_wof_enabled;
}

///////////////////////////////////////////////////////////
////////  is_rvrm_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_rvrm_enabled()
{
    if (iv_attrs.attr_system_rvrm_disable && iv_rvrm_enabled)
    {
        FAPI_DBG(">>> RVRM disabled due to system attribute control.")
        iv_rvrm_enabled = false;
    }

    return iv_rvrm_enabled;
}

///////////////////////////////////////////////////////////
////////  is_ocs_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_ocs_enabled()
{
    if (iv_attrs.attr_system_ocs_disable && iv_ocs_enabled)
    {
        FAPI_DBG(">>> OCS disabled due to system attribute control.")
        iv_ocs_enabled = false;
    }

    return iv_ocs_enabled;
}

///////////////////////////////////////////////////////////
////////  is_wov_underv_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wov_underv_enabled()
{
    if (iv_attrs.attr_wov_underv_disable && iv_wov_underv_enabled)
    {
        FAPI_DBG(">>> Undervolting disabled due to system attribute control.")
        iv_wov_underv_enabled = false;
    }

    return iv_wov_underv_enabled;
}

///////////////////////////////////////////////////////////
//////// is_wov_overv_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wov_overv_enabled()
{
    if (iv_attrs.attr_wov_overv_disable && iv_wov_overv_enabled)
    {
        FAPI_DBG(">>> Overrvolting disabled due to system attribute control.")
        iv_wov_overv_enabled = false;
    }

    return iv_wov_overv_enabled;
}

///////////////////////////////////////////////////////////
////////  is_wof_throttle_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wof_throttle_enabled()
{
    if ( iv_attrs.attr_system_wof_throttle_control_loop_disable &&
        !iv_attrs.attr_system_pitch_enable  &&
        iv_wof_throttle_enabled                                   )
    {
        iv_wof_throttle_enabled = false;
    }

    return iv_wof_throttle_enabled;
}

///////////////////////////////////////////////////////////
////////   apply_biased_values
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::apply_biased_values ()
{
    FAPI_INF(">>>>>>>>>>>>> apply_biased_values");
    const char*     pv_op_str[NUM_PV_POINTS] = VPD_PV_STR;

    do
    {
        // ---------------------------------------------
        // process external and internal bias attributes
        // ---------------------------------------------
        FAPI_IMP("Apply Biasing to #V to all CF points");

        // Copy to Bias array
        memcpy(iv_attr_mvpd_poundV_biased,iv_attr_mvpd_poundV_raw,sizeof(iv_attr_mvpd_poundV_raw));

        for (int i = 0; i <= NUM_PV_POINTS - 1; i++)
        {

            iv_attr_mvpd_poundV_biased[i].frequency_mhz =
                bias_adjust_mhz(iv_attr_mvpd_poundV_biased[i].frequency_mhz, iv_bias.frequency_0p5pct);

            iv_attr_mvpd_poundV_biased[i].vdd_mv =
                bias_adjust_mv(iv_attr_mvpd_poundV_biased[i].vdd_mv, iv_bias.vdd_ext_0p5pct[i]);

            iv_attr_mvpd_poundV_biased[i].vcs_mv =
                bias_adjust_mv(iv_attr_mvpd_poundV_biased[i].vcs_mv, iv_bias.vcs_ext_0p5pct[i]);

            FAPI_DBG("BIASED #V operating point (%s) f=%u v=%u i=%u v=%u i=%u",
                    pv_op_str[i],
                    iv_attr_mvpd_poundV_biased[i].frequency_mhz,
                    iv_attr_mvpd_poundV_biased[i].vdd_mv,
                    iv_attr_mvpd_poundV_biased[i].idd_tdp_dc_10ma,
                    iv_attr_mvpd_poundV_biased[i].vcs_mv,
                    iv_attr_mvpd_poundV_biased[i].ics_tdp_dc_10ma);
        }

        //Validating Bias values
        FAPI_INF("Validate Biased Voltage and Frequency values");

        FAPI_TRY(chk_valid_poundv(BIASED));

        //Update pstate for all points
        for (int i = 0; i < NUM_PV_POINTS; i++)
        {
            iv_attr_mvpd_poundV_biased[i].pstate = (iv_attr_mvpd_poundV_biased[CF7].frequency_mhz -
            iv_attr_mvpd_poundV_biased[i].frequency_mhz) * 1000 / (iv_frequency_step_khz);

            FAPI_INF("PSTATE %x %x %d",iv_attr_mvpd_poundV_biased[CF7].frequency_mhz,
                     iv_attr_mvpd_poundV_biased[i].frequency_mhz,iv_attr_mvpd_poundV_biased[i].pstate);
        }

        FAPI_DBG("Pstate Base Frequency - after bias %X (%d)",
                 iv_attr_mvpd_poundV_biased[CF7].frequency_mhz * 1000,
                 iv_attr_mvpd_poundV_biased[CF7].frequency_mhz * 1000);

        // Bias the pointer frequencies

        #define BIAS_POINTER_FREQ(_member) \
            iv_attr_mvpd_poundV_other_info._member = \
                bias_adjust_mhz(iv_attr_mvpd_poundV_other_info._member, iv_bias.frequency_0p5pct); \
            FAPI_INF("Biased Pointer %s:  %4d (0x%4X)", #_member, \
                iv_attr_mvpd_poundV_other_info._member, iv_attr_mvpd_poundV_other_info._member);

        BIAS_POINTER_FREQ(fixed_freq_mhz);
        BIAS_POINTER_FREQ(powersave_freq_mhz);
        BIAS_POINTER_FREQ(ultraturbo_freq_mhz);
        BIAS_POINTER_FREQ(fmax_freq_mhz);

    } while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<<<<<< apply_biased_values");
    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////   update_biased_pstates
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::update_biased_pstates()
{
    FAPI_INF(">>>>>>>>>>>>> update_pstates");

    fapi2::ReturnCode   l_rc;
    Pstate              l_ps;

    FAPI_INF("PSTATE Reference: 0x%X (%d)",
        iv_attrs.attr_pstate0_freq_mhz, iv_attrs.attr_pstate0_freq_mhz);
    FAPI_INF("PSTATE Reference Khz: 0x%X (%d)",
        iv_reference_frequency_khz, iv_reference_frequency_khz);

    for (int i = 0; i < NUM_PV_POINTS; i++)
    {
        l_rc = freq2pState(iv_attr_mvpd_poundV_biased[i].frequency_mhz*1000, &l_ps, ROUND_NEAR);
        if (l_rc)
        {
            disable_pstates();
            // TODO: put in notification controls
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            goto fapi_try_exit;
        }

        iv_attr_mvpd_poundV_biased[i].pstate = l_ps;

        FAPI_INF("Biased point %d: PSTATE=%03d  Frequency: 0x%04x (%04d)",
            i,
            iv_attr_mvpd_poundV_biased[i].pstate,
            iv_attr_mvpd_poundV_biased[i].frequency_mhz,
            iv_attr_mvpd_poundV_biased[i].frequency_mhz);
    }

fapi_try_exit:
    FAPI_INF("<<<<<<<<<< update_pstates");
    return fapi2::current_err;
}

// Macro to compress duplicate code in apply_pdw_biased_values
#define PDW_HANDLE_ERROR(_rc, _msg) \
        limit = LIMITS[field][error];                                                                          \
        FAPI_ASSERT_NOEXIT(b_dds_error[field][error] == false || b_suppress_dds_error[field][error] == true,   \
                            fapi2::_rc(fapi2::FAPI2_ERRL_SEV_RECOVERED)                                        \
                            .set_CHIP_TARGET(iv_procChip)                                                      \
                            .set_LIMIT(limit)                                                                  \
                            .set_ATTR_ADJ_VALUE(adjust)                                                        \
                            .set_PDW_VALUE(value)                                                              \
                            .set_ERROR_VALUE(calculated),                                                      \
                            "Pstate Parameter Block: #_msg: Value %d Adjust %d Update %d Limit %d",            \
                                    value, adjust, update, LIMITS[field][error]);                              \
                                                                                                               \
        if (b_dds_error[field][error])                                                                         \
        {                                                                                                      \
            b_suppress_dds_error[field][error] = true;                                                         \
            sprintf(buffer, "{%s} ", PDW_STR[error]);                                                          \
            strcat(mark, buffer);                                                                              \
        }

///////////////////////////////////////////////////////////
////////   apply_pdw_biased_values
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::apply_pdw_biased_values ()
{
    FAPI_INF(">>>>>>>>>>>>> apply_pdw_biased_values");

    char     mark[128];
    char     buffer[32];

    // boolean array usage [Underflow(UF)/Overflow(OF)]
    static const int PDW_UF = 0;
    static const int PDW_OF = 1;

    static const char *PDW_STR[2] = {"UF", "OF"};

    // fields array usage
    typedef enum
    {
        PDW_DELAY       = 0,
        PDW_LARGE_DROOP = 1,
        PDW_TRIP_OFFSET = 2,
        PDW_NUM_FIELDS  = 3
    } PDW_BIAS_FIELDS;

    bool b_dds_error[PDW_NUM_FIELDS][2] = {0};
    bool b_suppress_dds_error[PDW_NUM_FIELDS][2] = {0};

    int LIMITS[PDW_NUM_FIELDS][2] =
        {
            {0, 255},   // Delay
            {0, 15},    // Large Droop
            {0, 7}      // Trip Offset
        };

    do
    {
        FAPI_DBG("apply_pdw_biased_values: DDS enable = %d", is_dds_enabled());

        // Exit if DDS is disabled
        if (!is_dds_enabled())
        {
            FAPI_INF("   apply_pdw_biased_values: DDS is disabled.  Skipping futher #W processing");
            disable_dds();   // this is to ensure the dependent functions are disabled.
            break;
        }

        //  Breakout if this part doesn't need biasing
        if ((iv_poundW_data.other.dds_calibration_version & 0xC0) >> 6 == 1)
        {
            FAPI_INF("No Biasing applied to #W as calibration version indicates it's not necessary");
            break;
        };

        FAPI_INF("Apply Biasing to #W to all CF points. * indicates adjustment");

        for (int i = 0; i < NUM_OP_POINTS; i++)
        {
            for (int j = 0; j < MAXIMUM_CORES; j++)
            {

                for(auto a = 0; a < PDW_NUM_FIELDS; ++a)
                    for(auto b = 0; b < 2; ++b)
                        b_dds_error[a][b] = false;

                strcpy(mark, "");
                for (int field = 0; field <  PDW_NUM_FIELDS; ++field)
                {
                    int value = 0;
                    int adjust = 0;
                    int calculated = 0;
                    int update = 0;
                    strcpy(buffer, "");

                    switch (field)
                    {
                        case PDW_DELAY:
                            value = iv_poundW_data.entry[i].entry[j].ddsc.fields.insrtn_dely;
                            adjust = iv_attrs.attr_dds_delay_adjust[i];
                            break;
                        case PDW_LARGE_DROOP:
                            value = iv_poundW_data.entry[i].entry[j].ddsc.fields.large_droop;
                            adjust = iv_attrs.attr_dds_large_droop_detect_adjust[i];
                            break;
                        case PDW_TRIP_OFFSET:
                            value = iv_poundW_data.entry[i].entry[j].ddsc.fields.trip_offset;
                            adjust = iv_attrs.attr_dds_trip_offset_adjust[i];
                            break;
                    }

                    if (strcmp(mark, "") == 0 && adjust != 0)
                    {
                        strcpy(mark, "[*] ");
                    }

                    update = value + adjust;

                    if (update < LIMITS[field][PDW_UF])
                    {
                        b_dds_error[field][PDW_UF] = true;
                        calculated = update;
                        update = LIMITS[field][PDW_UF];
                    }
                    else if (update > LIMITS[field][PDW_OF])
                    {
                        b_dds_error[field][PDW_OF] = true;
                        calculated = update;
                        update = LIMITS[field][PDW_OF];
                    }

                    int error = 0;
                    int limit = 0;
                    switch (field)
                    {
                        case PDW_DELAY:
                            iv_poundW_data.entry[i].entry[j].ddsc.fields.insrtn_dely = update;
                            if (adjust)
                            {
                                sprintf(buffer, "delay: orig 0x%02X adj %d ", value, adjust);
                                strcat(mark, buffer);
                            }

                            error = PDW_UF;
                            PDW_HANDLE_ERROR(PSTATE_PB_DDS_ADJ_DELAY_OVERFLOW, "DDS Delay Adjust Underflow");

                            error = PDW_OF;
                            PDW_HANDLE_ERROR(PSTATE_PB_DDS_ADJ_DELAY_UNDERFLOW, "DDS Delay Adjust Overflow");

                            break;
                        case PDW_LARGE_DROOP:
                            iv_poundW_data.entry[i].entry[j].ddsc.fields.large_droop = update;
                            if (adjust)
                            {
                                sprintf(buffer, "large: orig 0x%02X adj %d ", value, adjust);
                                strcat(mark, buffer);
                            }

                            error = PDW_UF;
                            PDW_HANDLE_ERROR(PSTATE_PB_DDS_ADJ_LARGE_DROOP_UNDERFLOW, "DDS Large Droop Adjust Underflow");

                            error = PDW_OF;
                            PDW_HANDLE_ERROR(PSTATE_PB_DDS_ADJ_LARGE_DROOP_OVERFLOW, "DDS Large Droop Adjust Overflow");

                            break;
                        case PDW_TRIP_OFFSET:
                            iv_poundW_data.entry[i].entry[j].ddsc.fields.trip_offset = update;
                            if (adjust)
                            {
                                sprintf(buffer, "trip: orig 0x%02X adj %d ", value, adjust);
                                strcat(mark, buffer);
                            }

                            error = PDW_UF;
                            PDW_HANDLE_ERROR(PSTATE_PB_DDS_ADJ_TRIP_OFFSET_UNDERFLOW, "DDS Trip Offset Adjust Underflow");

                            error = PDW_OF;
                            PDW_HANDLE_ERROR(PSTATE_PB_DDS_ADJ_TRIP_OFFSET_OVERFLOW, "DDS Trip Offset Adjust Overflow");

                            break;
                    }
                }

                if (strcmp(mark, "") != 0)
                {
                    FAPI_INF("#W DDSC [CF %u][C %02u] = 0x%016llX %s" , i, j, iv_poundW_data.entry[i].entry[j].ddsc.value, mark );
                }
                else
                {
                    FAPI_INF("#W DDSC [CF %u][C %02u] = 0x%016llX" , i, j, iv_poundW_data.entry[i].entry[j].ddsc.value);
                }
            }
        }
    } while(0);

    // Always return success as the function does set recovered values.
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    FAPI_INF("<<<<<<<<<<<< apply_pdw_biased_values");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   part_fmax
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::part_fmax()
{
    FAPI_INF(">>>>>>>>>>>>> part_fmax");

    fapi2::ReturnCode   l_rc;
    if (iv_vddFmaxFreq < iv_attrs.attr_freq_core_ceiling_mhz)
    {
        FAPI_INF("Part ceiling limit to fmax of %X (%d)",
                    iv_vddFmaxFreq,  iv_vddFmaxFreq);
        iv_part_ceiling_freq_mhz = iv_vddFmaxFreq;
    }
    else
    {
        FAPI_INF("Part ceiling set to system ceiling of %X (%d)",
                    iv_attrs.attr_freq_core_ceiling_mhz, iv_attrs.attr_freq_core_ceiling_mhz);
        iv_part_ceiling_freq_mhz = iv_attrs.attr_freq_core_ceiling_mhz;
    }

    FAPI_INF("<<<<<<<<<< part_fmax");
    return fapi2::current_err;
}


///////////////////////////////////////////////////////////
////////  get_mvpd_poundW
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundW (void)
{
    fapi2::ddscData_t *l_ddscBuf = new fapi2::ddscData_t;
    uint8_t    bucket_id        = 0;
    uint8_t    version_id       = 0;

    FAPI_DBG(">> get_mvpd_poundW");

    do
    {
        FAPI_DBG("get_mvpd_poundW: DDS enable = %d", is_dds_enabled());

        // Exit if DDS is disabled
        if (!is_dds_enabled())
        {
            FAPI_INF("   get_mvpd_poundW: DDS is disabled.  Skipping futher #W processing");
            disable_dds();   // this is to ensure the dependent functions are disabled.
            break;
        }

        // clear out buffer to known value before calling fapiGetMvpdField
        memset(l_ddscBuf, 0, sizeof(fapi2::ddscData_t));

        FAPI_TRY(p10_pm_get_poundw_bucket(iv_procChip, l_ddscBuf));

        bucket_id = l_ddscBuf->bucketId;
        version_id = l_ddscBuf->version;

        FAPI_INF("#W bucket_id  = %u version_id = %u", bucket_id, version_id);


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
            //            memcpy (&iv_poundW_data, &g_vpdData, sizeof (g_vpdData));
        }
        else
        {
            FAPI_INF("attribute ATTR_POUND_W_STATIC_DATA_ENABLE is NOT set");
            // copy the data to the pound w structure from the actual VPD image
            memcpy (&iv_poundW_data, l_ddscBuf->ddscData, sizeof (l_ddscBuf->ddscData));
#ifndef __HOSTBOOT_MODULE
            for (uint8_t i = 0; i < NUM_OP_POINTS; i++)
            {
                for (uint8_t j = 0; j < 32; j++)
                {
                    iv_poundW_data.entry[i].entry[j].ddsc.value =
                        revle64(iv_poundW_data.entry[i].entry[j].ddsc.value);

                    iv_poundW_data.entry[i].entry_alt_cal[j].alt_cal.value =
                        revle16(iv_poundW_data.entry[i].entry_alt_cal[j].alt_cal.value);

                }

                iv_poundW_data.entry[i].vdd_cal.cal_vdd =
                    revle16(iv_poundW_data.entry[i].vdd_cal.cal_vdd);
                iv_poundW_data.entry[i].vdd_cal.alt_cal_vdd =
                    revle16(iv_poundW_data.entry[i].vdd_cal.alt_cal_vdd);
                iv_poundW_data.entry[i].vdd_cal.large_droop_vdd =
                    revle16(iv_poundW_data.entry[i].vdd_cal.large_droop_vdd);
                iv_poundW_data.entry[i].vdd_cal.worst_droop_min_vdd =
                    revle16(iv_poundW_data.entry[i].vdd_cal.worst_droop_min_vdd);
                iv_poundW_data.entry[i].vdd_cal.worst_droop_max_vdd =
                    revle16(iv_poundW_data.entry[i].vdd_cal.worst_droop_max_vdd);
                iv_poundW_data.entry[i].vdd_cal.non_perf_loss_vdd =
                    revle16(iv_poundW_data.entry[i].vdd_cal.non_perf_loss_vdd);
            }

            iv_poundW_data.other.dpll_settings.value = revle16(iv_poundW_data.other.dpll_settings.value);
            iv_poundW_data.other.droop_freq_resp_reference_mhz =
                revle16(iv_poundW_data.other.droop_freq_resp_reference_mhz);
            iv_poundW_data.other.droop_count_control =
                revle64(iv_poundW_data.other.droop_count_control);
            iv_poundW_data.other.ftc_large_droop_mode_reg_setting =
                revle64(iv_poundW_data.other.ftc_large_droop_mode_reg_setting);
            iv_poundW_data.other.ftc_misc_droop_mode_reg_setting =
                revle64(iv_poundW_data.other.ftc_misc_droop_mode_reg_setting);
#endif

        }


        FAPI_INF("iv_poundW_data.other.droop_freq_resp_reference_mhz %x",iv_poundW_data.other.droop_freq_resp_reference_mhz);
        FAPI_INF("iv_poundW_data.other.droop_count_control %x",iv_poundW_data.other.droop_count_control);
        FAPI_INF("iv_poundW_data.other.ftc_large_droop_mode_reg_setting %x",iv_poundW_data.other.ftc_large_droop_mode_reg_setting);
        FAPI_INF("iv_poundW_data.other.ftc_misc_droop_mode_reg_setting %x",iv_poundW_data.other.ftc_misc_droop_mode_reg_setting);

        // validate vid values
        bool l_frequency_value_state = 1;
        FAPI_INF("iv_poundW_data.other.dpll_settings.fields.N_S_drop_3p125pct %x",iv_poundW_data.other.dpll_settings.fields.N_S_drop_3p125pct);
        FAPI_INF("iv_poundW_data.other.dpll_settings.fields.N_L_drop_3p125pct %x",iv_poundW_data.other.dpll_settings.fields.N_L_drop_3p125pct);
        FAPI_INF("iv_poundW_data.other.dpll_settings.fields.L_S_return_3p125pct %x",iv_poundW_data.other.dpll_settings.fields.L_S_return_3p125pct);
        FAPI_INF("iv_poundW_data.other.dpll_settings.fields.S_N_return_3p125pct %x",iv_poundW_data.other.dpll_settings.fields.S_N_return_3p125pct);
        if (iv_poundW_data.other.dds_calibration_version)
        {
            VALIDATE_FREQUENCY_DROP_VALUES(iv_poundW_data.other.dpll_settings.fields.N_S_drop_3p125pct,
                    iv_poundW_data.other.dpll_settings.fields.N_L_drop_3p125pct,
                    iv_poundW_data.other.dpll_settings.fields.L_S_return_3p125pct,
                    iv_poundW_data.other.dpll_settings.fields.S_N_return_3p125pct,
                    l_frequency_value_state);
        }

        if (!l_frequency_value_state)
        {
            FAPI_INF("l_frequency_value_state=0");
            //iv_dds_enabled = false; // \\todo determine if this check should disable/enable dds
        }

        // Check the validity of some PoundW fields if DDSs are enabled
        if (is_dds_enabled() && !dccr_value())
        {
            FAPI_INF("#W DCCR is 0. Disabling Over-Current Sensor, Undervolting and Overvolting");
            disable_ocs();
            disable_underv();
            disable_overv();

            if (is_wof_enabled())
            {
                FAPI_INF("WARNING: WOF is enabled with Over-Current Sensor disabled!");
            }

            const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
            fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE_Type l_sys_pdw_mode;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDW_VALIDATION_MODE, FAPI_SYSTEM,l_sys_pdw_mode));
            if (l_sys_pdw_mode == fapi2::ENUM_ATTR_SYSTEM_PDW_VALIDATION_MODE_INFO)
            {
                FAPI_ASSERT_NOEXIT(false,
                        fapi2::PSTATE_PB_ZERO_DCCR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                        .set_CHIP_TARGET(iv_procChip),
                        "Pstate Parameter Block: #W DCCR has value of 0");
            }
            else if (l_sys_pdw_mode == fapi2::ENUM_ATTR_SYSTEM_PDW_VALIDATION_MODE_WARN)
            {
                FAPI_INF("WARNING: #W DCCR has value of 0");
            }
            else if (l_sys_pdw_mode == fapi2::ENUM_ATTR_SYSTEM_PDW_VALIDATION_MODE_FAIL)
            {
                FAPI_ASSERT(false,
                        fapi2::PSTATE_PB_ZERO_DCCR()
                        .set_CHIP_TARGET(iv_procChip),
                        "Pstate Parameter Block: #W DCCR has value of 0");
            }
        }

        // Get any FLMR and FMMR overrides
        iv_poundW_data.other.ftc_large_droop_mode_reg_setting = flmr_value();
        iv_poundW_data.other.ftc_misc_droop_mode_reg_setting = fmmr_value();
    }
    while(0);

fapi_try_exit:
    delete l_ddscBuf;
    return fapi2::FAPI2_RC_SUCCESS;
}

///////////////////////////////////////////////////////////
////////  get_mvpd_iddq
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_iddq( void )
{

    uint8_t*        l_buffer_iq_c =  nullptr;
    uint32_t        l_record = 0;
    uint32_t        l_bufferSize_iq  = IQ_BUFFER_ALLOC;
    fapi2::ATTR_SYSTEM_IQ_VALIDATION_MODE_Type l_iq_mode = 0;


    // --------------------------------------------
    // Process IQ Keyword (IDDQ) Data
    // --------------------------------------------

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IQ_VALIDATION_MODE, FAPI_SYSTEM, l_iq_mode));
    // set l_record to appropriate cprx record
    l_record = (uint32_t)fapi2::MVPD_RECORD_CRP0;

    //First read is to get size of vpd record, note the o_buffer is nullptr
    FAPI_TRY( getMvpdField((fapi2::MvpdRecord)l_record,
                fapi2::MVPD_KEYWORD_IQ,
                iv_procChip,
                nullptr,
                l_bufferSize_iq) );

    //Allocate memory for vpd data
    l_buffer_iq_c = reinterpret_cast<uint8_t*>(malloc(l_bufferSize_iq));

    // Get Chip IQ MVPD data from the CRPx records
    FAPI_TRY(getMvpdField((fapi2::MvpdRecord)l_record,
                fapi2::MVPD_KEYWORD_IQ,
                iv_procChip,
                l_buffer_iq_c,
                l_bufferSize_iq));

    //skip keyword version and
    //copy VPD data to IQ structure table
    memcpy(&iv_iddqt, (l_buffer_iq_c+1), l_bufferSize_iq);

    //Verify Payload header data.
    if ( ( !(iv_iddqt.iddq_version) ||
           !(iv_iddqt.good_normal_cores_per_sort)) &&
           l_iq_mode != fapi2::ENUM_ATTR_SYSTEM_IQ_VALIDATION_MODE_OFF)
    {

        if (l_iq_mode == fapi2::ENUM_ATTR_SYSTEM_IQ_VALIDATION_MODE_WARN)
        {
            FAPI_INF("Pstate Parameter Block IQ Payload data error:  version %u; good cores %u",
                    iv_iddqt.iddq_version, iv_iddqt.good_normal_cores_per_sort);
        }
        else if (l_iq_mode == fapi2::ENUM_ATTR_SYSTEM_IQ_VALIDATION_MODE_INFO)
        {
            FAPI_INF("Pstate Parameter Block IQ Payload data error:  version %u; good cores %u",
                    iv_iddqt.iddq_version, iv_iddqt.good_normal_cores_per_sort);
            //because IQ data was not valid
            FAPI_ASSERT_NOEXIT(false,
                    fapi2::PSTATE_PB_IQ_VPD_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                    .set_CHIP_TARGET(iv_procChip)
                    .set_VERSION(iv_iddqt.iddq_version)
                    .set_GOOD_NORMAL_CORES_PER_SORT(iv_iddqt.good_normal_cores_per_sort),
                    "Pstate Parameter Block IQ Payload data error being logged");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }
        else if (l_iq_mode == fapi2::ENUM_ATTR_SYSTEM_IQ_VALIDATION_MODE_FAIL)
        {
            FAPI_INF("Pstate Parameter Block IQ Payload data error:  version %u; good cores %u",
                    iv_iddqt.iddq_version, iv_iddqt.good_normal_cores_per_sort);
            //because IQ data was not valid
            FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_IQ_VPD_ERROR()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_VERSION(iv_iddqt.iddq_version)
                    .set_GOOD_NORMAL_CORES_PER_SORT(iv_iddqt.good_normal_cores_per_sort),
                    "Pstate Parameter Block IQ Payload data error being logged");
        }
    }

    //Verify ivdd_all_cores_off_caches_off has MSB bit is set
    //if yes then initialized to 0
    for (int i = 0; i < IDDQ_MEASUREMENTS; ++i)
    {
        if ( iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i] & 0x8000)
        {
            iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i] = 0;
        }
    }
    for (int i = 0; i < IDDQ_MEASUREMENTS; ++i)
    {
        iv_iddqt.iddq_all_good_cores_on_caches_on_5ma[i] =
            revle16(iv_iddqt.iddq_all_good_cores_on_caches_on_5ma[i]);
        iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i] =
            revle16(iv_iddqt.iddq_all_good_cores_off_good_caches_off_5ma[i]);
        iv_iddqt.iddq_all_good_cores_off_good_caches_on_5ma[i] =
            revle16(iv_iddqt.iddq_all_good_cores_off_good_caches_on_5ma[i]);
        iv_iddqt.icsq_all_good_cores_on_caches_on_5ma[i] =
            revle16(iv_iddqt.icsq_all_good_cores_on_caches_on_5ma[i]);
        iv_iddqt.icsq_all_good_cores_off_good_caches_off_5ma[i] =
            revle16(iv_iddqt.icsq_all_good_cores_off_good_caches_off_5ma[i]);
        iv_iddqt.icsq_all_good_cores_off_good_caches_on_5ma[i] =
            revle16(iv_iddqt.icsq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    for (int x = 0; x < MAXIMUM_EQ_SETS; ++x)
    {
        for (int i = 0; i < IDDQ_MEASUREMENTS; ++i)
        {
            iv_iddqt.iddq_eqs_good_cores_on_good_caches_on_5ma[x][i] =
                revle16(iv_iddqt.iddq_eqs_good_cores_on_good_caches_on_5ma[x][i]);
            iv_iddqt.icsq_eqs_good_cores_on_good_caches_on_5ma[x][i] =
                revle16(iv_iddqt.icsq_eqs_good_cores_on_good_caches_on_5ma[x][i]);
        }
    }
    // Put out the structure to the trace
    iddq_print(&iv_iddqt);

fapi_try_exit:

    // Free up memory buffer
    free(l_buffer_iq_c);

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        disable_wof();
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
//////// iddq_print
///////////////////////////////////////////////////////////
void iddq_print(IddqTable_t* i_iddqt)
{
    uint32_t        i, j;
    const char*     idd_meas_str[IDDQ_MEASUREMENTS] = IDDQ_ARRAY_VOLTAGES_STR;
    char            l_buffer_str[1024];   // Temporary formatting string buffer
    char            l_line_str[1024];     // Formatted output line string

    FAPI_INF("IDDQ");

    // Put out the endian-corrected scalars

    // get IQ version and advance pointer 1-byte
    FAPI_INF("  IDDQ Version Number = %u", i_iddqt->iddq_version);
    FAPI_INF("  Sort Info:");
    FAPI_INF("    %-30s : %02d", "Good Cores",             i_iddqt->good_normal_cores_per_sort);
    FAPI_INF("    %-30s : %02d", "Good cores per Cache01", i_iddqt->good_normal_cores_per_EQs[0]);
    FAPI_INF("    %-30s : %02d", "Good cores per Cache23", i_iddqt->good_normal_cores_per_EQs[1]);
    FAPI_INF("    %-30s : %02d", "Good cores per Cache45", i_iddqt->good_normal_cores_per_EQs[2]);
    FAPI_INF("    %-30s : %02d", "Good cores per Cache67", i_iddqt->good_normal_cores_per_EQs[3]);

    FAPI_INF("  %-32s : %d", "MMA state", i_iddqt->mma_not_active);
    FAPI_INF("  %-32s : %d", "MMA leakage percent", i_iddqt->mma_off_leakage_pct);

    // All IQ IDDQ measurements are at 5mA resolution. The OCC wants to
    // consume these at 1mA values.  thus, all values are multiplied by
    // 5 upon installation into the paramater block.
    static const uint32_t CONST_5MA_1MA = 5;
    FAPI_INF("  IDDQ data is converted 5mA units to 1mA units");

#define IDDQ_TRACE(string) \
        strcpy(l_line_str, string); \
        sprintf(l_buffer_str, "%-43s", l_line_str);\
        strcpy(l_line_str, l_buffer_str); \
        strcat(l_line_str, " :        ");

#define IDDQ_TRACE_QUAD(string) \
        strcpy(l_line_str, string); \
        sprintf(l_buffer_str, "%-43s", l_line_str);\
        strcpy(l_line_str, l_buffer_str); \
        strcat(l_line_str, " : ");

    // Put out the measurement voltages to the trace.
    IDDQ_TRACE ("  Measurement voltages:");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        sprintf(l_buffer_str, "  %*sV ", 5, idd_meas_str[i]);
        strcat(l_line_str, l_buffer_str);
    }

    FAPI_INF("%s", l_line_str);

#define IDDQ_CURRENT_EXTRACT(_member) \
        { \
        uint16_t _temp = (i_iddqt->_member) * CONST_5MA_1MA;     \
        sprintf(l_buffer_str, "  %6.3f ", (double)_temp/1000);   \
        strcat(l_line_str, l_buffer_str); \
        }

// Temps are all 1B quantities.  Not endianess issues.
#define IDDQ_TEMP_EXTRACT(_member) \
        sprintf(l_buffer_str, "    %4.1f ", ((double)i_iddqt->_member)/2); \
        strcat(l_line_str, l_buffer_str);

    // get IVDDQ measurements with all good cores ON
    IDDQ_TRACE ("  IDDQ all good cores ON");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_on_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get IVDDQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  IVDDQ all cores, caches OFF");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
       IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_off_good_caches_off_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);;

    // get IVDDQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  IVDDQ all good cores OFF, caches ON");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get IVDDQ measurements with all good cores in each quad
    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        IDDQ_TRACE_QUAD ("  IVDDQ all good cores ON, caches ON:");
        sprintf(l_buffer_str, "Quad %d:", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(iddq_eqs_good_cores_on_good_caches_on_5ma[i][j]);
        }

        FAPI_INF("%s", l_line_str);
    }

    // get ICSQ measurements with all good cores ON
    IDDQ_TRACE ("  ICSQ all good cores ON");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_on_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get ICSQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  ICSQ all cores, caches OFF");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
       IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_off_good_caches_off_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);;

    // get ICSQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  ICSQ all good cores OFF, caches ON");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get ICSQ measurements with all good cores in each quad
    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        IDDQ_TRACE_QUAD ("  ICSQ all good cores ON, caches ON");
        sprintf(l_buffer_str, "Quad %d:", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(icsq_eqs_good_cores_on_good_caches_on_5ma[i][j]);
        }

        FAPI_INF("%s", l_line_str);
    }

    // get average temperature measurements with all good cores ON
    IDDQ_TRACE ("  Avg temp all good cores ON");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
         IDDQ_TEMP_EXTRACT(avgtemp_all_cores_on_good_caches_on_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all cores and caches OFF
    IDDQ_TRACE ("  Avg temp all cores OFF, caches OFF");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_cores_off_caches_off_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);

    // get average temperature measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  Avg temp all good cores OFF, caches ON");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_good_cores_off_good_caches_on_p5c[i]);
    }

    FAPI_INF("%s", l_line_str);
}

///////////////////////////////////////////////////////////
////////   compute_vpd_pts
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_vpd_pts()
{
    uint32_t l_vdd_loadline_uohm    = iv_vdd_sysparam.loadline_uohm;
    uint32_t l_vdd_distloss_uohm    = iv_vdd_sysparam.distloss_uohm;
    uint32_t l_vdd_distoffset_uv    = iv_vdd_sysparam.distoffset_uv;
    uint32_t l_vcs_loadline_uohm    = iv_vcs_sysparam.loadline_uohm;
    uint32_t l_vcs_distloss_uohm    = iv_vcs_sysparam.distloss_uohm;
    uint32_t l_vcs_distoffset_uv    = iv_vcs_sysparam.distoffset_uv;

    fapi2::ReturnCode l_rc;

    FAPI_INF(">>>>>>>>>> compute_vpd_pts");

    //RAW POINTS. We just copy them as is
    memcpy (iv_operating_points[VPD_PT_SET_RAW],
            iv_attr_mvpd_poundV_raw,
            sizeof(iv_attr_mvpd_poundV_raw));
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        FAPI_DBG("GP: OpPoint=[%d][%d], PS=%3d, Freq=0x%3X (%4d), Vdd=0x%3X (%4d)",
                VPD_PT_SET_RAW, p,
                iv_operating_points[VPD_PT_SET_RAW][p].pstate,
                (iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv),
                (iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv));

        //BIASED POINTS
        uint32_t l_frequency_mhz = (iv_attr_mvpd_poundV_raw[p].frequency_mhz);
        uint32_t l_vdd_mv = (iv_attr_mvpd_poundV_raw[p].vdd_mv);
        uint32_t l_vcs_mv = (iv_attr_mvpd_poundV_raw[p].vcs_mv);

        iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv =
            bias_adjust_mv(l_vdd_mv, iv_bias.vdd_ext_0p5pct[p]);

        iv_operating_points[VPD_PT_SET_BIASED][p].vcs_mv =
            bias_adjust_mv(l_vcs_mv, iv_bias.vcs_ext_0p5pct[p]);

        iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz =
            bias_adjust_mhz(l_frequency_mhz, iv_bias.frequency_0p5pct);

        iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_rdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].idd_rdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].idd_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_rdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_rdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].vdd_vmin =
            iv_attr_mvpd_poundV_biased[p].vdd_vmin;
        iv_operating_points[VPD_PT_SET_BIASED][p].rt_tdp_ac_10ma =
            iv_attr_mvpd_poundV_biased[p].rt_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].rt_tdp_dc_10ma =
            iv_attr_mvpd_poundV_biased[p].rt_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].pstate =
            iv_attr_mvpd_poundV_biased[p].pstate;
    }

    // Now that the Pstate 0 frequency is known, Pstates can be calculated
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        Pstate l_ps;
        l_rc = freq2pState(iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz*1000, \
                            &l_ps, ROUND_NEAR, PPB_INFO);
        if (l_rc)
        {
            // As this is fundamental to the rest of the Pstate functionality,
            // disable them (all the dependent functions)
            disable_pstates();
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        FAPI_DBG("Bi: OpPoint=[%d][%d], PS=%3d, Freq=0x%3X (%4d), Vdd=0x%3X (%4d), CF6 Freq=0x%3d (%4d) Step Freq=%5d",
                    VPD_PT_SET_BIASED, p,
                    iv_operating_points[VPD_PT_SET_BIASED][p].pstate,
                    (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF6].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF6].frequency_mhz),
                    (iv_frequency_step_khz));

    }
    //BIASED POINTS and SYSTEM PARMS APPLIED POINTS
    for (auto p = 0; p < NUM_PV_POINTS; p++)
    {
        uint32_t l_vdd_mv = (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv);
        uint32_t l_idd_ma = (iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_dc_10ma) * 10 +
                             (iv_operating_points[VPD_PT_SET_BIASED][p].idd_tdp_ac_10ma) * 10;
        uint32_t l_vcs_mv = (iv_operating_points[VPD_PT_SET_BIASED][p].vcs_mv);
        uint32_t l_ics_ma = (iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_dc_10ma) * 10 +
                             (iv_operating_points[VPD_PT_SET_BIASED][p].ics_tdp_ac_10ma) * 10;

        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vdd_mv =
                    sysparm_uplift(l_vdd_mv,
                                   l_idd_ma,
                                   l_vdd_loadline_uohm,
                                   l_vdd_distloss_uohm,
                                   l_vdd_distoffset_uv);


        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vcs_mv =
                    sysparm_uplift(l_vcs_mv,
                                   l_ics_ma,
                                   l_vcs_loadline_uohm,
                                   l_vcs_distloss_uohm,
                                   l_vcs_distoffset_uv);

        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_tdp_ac_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_tdp_dc_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_rdp_ac_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_rdp_dc_10ma=
                   iv_attr_mvpd_poundV_biased[p].idd_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_tdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_tdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_rdp_ac_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_rdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_rdp_dc_10ma=
            iv_attr_mvpd_poundV_biased[p].ics_rdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].vdd_vmin =
                   iv_attr_mvpd_poundV_biased[p].vdd_vmin;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].rt_tdp_ac_10ma =
                   iv_attr_mvpd_poundV_biased[p].rt_tdp_ac_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].rt_tdp_dc_10ma =
                   iv_attr_mvpd_poundV_biased[p].rt_tdp_dc_10ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].pstate =
                   iv_attr_mvpd_poundV_biased[p].pstate;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].frequency_mhz =
               iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz;
    }
fapi_try_exit:
    FAPI_INF("<<<<<<<<<< compute_vpd_pts");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  safe_mode_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::safe_mode_init( void )
{
    FAPI_INF(">>>>>>>>>> safe_mode_init");
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type ps_ovrd;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_PS, FAPI_SYSTEM, ps_ovrd));

    if (!iv_attrs.attr_pm_safe_voltage_mv[VDD] ||
        !iv_attrs.attr_pm_safe_voltage_mv[VCS] ||
        !iv_attrs.attr_pm_safe_frequency_mhz ||
        ps_ovrd)
    {
        //Compute safe mode values
        FAPI_TRY(safe_mode_computation (
                    ),
                "Error from safe_mode_computation function");
    }

fapi_try_exit:
    FAPI_INF("<<<<<<<<<< safe_mode_init");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   safe_mode_computation
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::safe_mode_computation()
{
    fapi2::ReturnCode                        l_rc;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_safe_mode_freq_mhz;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type    l_safe_mode_mv;
    fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ_Type l_sys_pstate0_freq_mhz = 0;
    uint32_t                                 l_safe_mode_op_ps2freq_khz;
    uint32_t                                 l_safe_op_freq_mhz;
    uint8_t                                  l_safe_op_ps;
    uint32_t                                 l_core_floor_mhz;
    uint32_t                                 l_op_pt_mhz;
    Pstate                                   l_safe_mode_ps;
    fapi2::ATTR_CHIP_EC_FEATURE_HW543384_Type l_hw543384;

    FAPI_INF(">>>>>>>>>> safe_mode_computation");

    fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE_Type l_pdv_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE,
            FAPI_SYSTEM, l_pdv_mode));

    fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type ps_ovrd;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_PS, FAPI_SYSTEM, ps_ovrd));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,
                           iv_procChip,
                           l_core_floor_mhz));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW543384,
                           iv_procChip, l_hw543384),
              "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW543384)");

    if (!is_pstates_enabled())
    {
        FAPI_INF("Pstates are disabled which implies the #V is not able to be used.  Skipping safe mode computation being skipped");
        goto fapi_try_exit;
    }

    // Core floor frequency should be less than ultra turbo freq..
    // if not log an error
    if ((l_core_floor_mhz*1000) > iv_reference_frequency_khz)
    {
        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_WARN )
        {

            FAPI_INF("Core floor frequency %04x (%04d) is greater than Pstate0 frequency %04x (%04d)",
                      (l_core_floor_mhz*1000),
                      (l_core_floor_mhz*1000),
                      iv_reference_frequency_khz,
                      iv_reference_frequency_khz);
            goto fapi_try_exit;
        }

        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO ||
            l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
        {
            FAPI_ERR("Core floor frequency %04x (%04d) is greater than Pstate0 frequency %04x (%04d)",
                      (l_core_floor_mhz*1000),
                      (l_core_floor_mhz*1000),
                      iv_reference_frequency_khz,
                      iv_reference_frequency_khz);
        }

        if ( l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO)
        {
            FAPI_ASSERT_NOEXIT(false,
                        fapi2::PSTATE_PB_CORE_FLOOR_FREQ_GT_CF6_FREQ()
                        .set_CHIP_TARGET(iv_procChip)
                        .set_CORE_FLOOR_FREQ(l_core_floor_mhz*1000)
                        .set_UT_FREQ(iv_reference_frequency_khz),
                        "Core floor freqency is greater than UltraTurbo frequency");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            goto fapi_try_exit;
        }

        if ( l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
        {
            FAPI_ASSERT(false,
                        fapi2::PSTATE_PB_CORE_FLOOR_FREQ_GT_CF6_FREQ()
                        .set_CHIP_TARGET(iv_procChip)
                        .set_CORE_FLOOR_FREQ(l_core_floor_mhz*1000)
                        .set_UT_FREQ(iv_reference_frequency_khz),
                        "Core floor freqency is greater than UltraTurbo frequency");
        }
    }

    FAPI_INF ("core_floor_mhz 0x%04x (%4d)",
                l_core_floor_mhz,
                l_core_floor_mhz);
    FAPI_INF("biased operating_point[VPD_PV_CF0].frequency_mhz 0x%04x (%4d)",
                (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF0].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_BIASED][VPD_PV_CF0].frequency_mhz));
    FAPI_INF ("reference_freq_khz 0x%08x (%d)",
                iv_reference_frequency_khz, iv_reference_frequency_khz);
    FAPI_INF ("step_frequency_khz 0x%08x (%d)",
                iv_frequency_step_khz, iv_frequency_step_khz);
    FAPI_INF ("iv_attrs.attr_pm_safe_frequency_mhz 0x%08x (%d)",
                iv_attrs.attr_pm_safe_frequency_mhz, iv_attrs.attr_pm_safe_frequency_mhz);

    if ( iv_attrs.attr_pm_safe_frequency_mhz)
    {
        //If WOF override is applied then we should consider
        //updated core floor freq to compute safe mode freq
        if (ps_ovrd)
        {
             l_op_pt_mhz = l_core_floor_mhz;
        }
        else
        {
             l_op_pt_mhz = iv_attrs.attr_pm_safe_frequency_mhz;
        }
        FAPI_INF ("Using safe operating point from the safe mode attribute 0%04x (%d)",
                l_op_pt_mhz, l_op_pt_mhz);
    }
    else
    {
        l_op_pt_mhz = iv_vddPsavFreq;
        FAPI_INF ("Seeding safe operating point from PowerSave 0%04x (%d)",
                l_op_pt_mhz, l_op_pt_mhz);
    }

    // Safe operational frequency is the MAX(core floor, VPD Powersave).
    // PowerSave is the lowest operational frequency that the part was tested at
    if (l_core_floor_mhz > l_op_pt_mhz)
    {
        FAPI_INF("Moving safe operating to Core floor 0%04x (%d)",
                l_core_floor_mhz, l_core_floor_mhz);
        l_safe_op_freq_mhz = l_core_floor_mhz;
    }
    else
    {
        l_safe_op_freq_mhz = l_op_pt_mhz;
    }

    FAPI_INF ("safe_op_freq_mhz  0x%04x (%4d)",
                 l_safe_op_freq_mhz,
                 l_safe_op_freq_mhz);

    // Calculate safe operational pstate.  This must be rounded to create
    // a faster Pstate than the floor
    l_rc = freq2pState(l_safe_op_freq_mhz*1000, &l_safe_op_ps, ROUND_NEAR, PPB_WARN);
    if (l_rc)
    {
        disable_pstates();
        // TODO: put in notification controls
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        goto fapi_try_exit;
    }

    // Given the Pstate might round the frequency, get that frequency
    pState2freq(l_safe_op_ps, &l_safe_mode_op_ps2freq_khz);
    l_safe_mode_freq_mhz = l_safe_mode_op_ps2freq_khz / 1000;

    FAPI_INF("Setting safe mode frequency MHz:  0x%04x (%4d)",
              l_safe_mode_freq_mhz,
              l_safe_mode_freq_mhz);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                            iv_procChip,
                            l_safe_mode_freq_mhz));

    // Read back to get any overrides
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                            iv_procChip,
                            iv_attrs.attr_pm_safe_frequency_mhz));

    FAPI_INF ("Read back safe mode frequency MHz:  0x%04x (%4d)",
                iv_attrs.attr_pm_safe_frequency_mhz,
                iv_attrs.attr_pm_safe_frequency_mhz);

    if (l_safe_mode_freq_mhz != iv_attrs.attr_pm_safe_frequency_mhz)
    {
        FAPI_INF ("Attribute override safe mode frequency being used");
    }

    // Safe frequency must be less than Pstate 0 frequency.
    // if not log an error
    if ((iv_attrs.attr_pm_safe_frequency_mhz*1000) > iv_reference_frequency_khz)
    {
        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_WARN )
        {

            FAPI_INF("Safe mode frequency %08x (%d) is greater than UltraTurbo frequency %08x (%d)",
                  l_safe_mode_freq_mhz*1000, l_safe_mode_freq_mhz*1000,
                  iv_reference_frequency_khz, iv_reference_frequency_khz);
            goto fapi_try_exit;
        }

        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO ||
            l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
        {
             FAPI_ERR("Safe mode frequency %08x (%d) is greater than UltraTurbo frequency %08x (%d)",
                  l_safe_mode_freq_mhz*1000, l_safe_mode_freq_mhz*1000,
                  iv_reference_frequency_khz, iv_reference_frequency_khz);
        }

        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO)
        {
            FAPI_ASSERT_NOEXIT(false,
                    fapi2::PSTATE_PB_SAFE_FREQ_GT_PS0_FREQ()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_SAFE_FREQ(l_safe_mode_freq_mhz*1000)
                    .set_UT_FREQ(iv_reference_frequency_khz),
                    "Safe mode freqency is greater than UltraTurbo frequency");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            goto fapi_try_exit;
        }

        if ( l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
        {
            FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_SAFE_FREQ_GT_PS0_FREQ()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_SAFE_FREQ(iv_attrs.attr_pm_safe_frequency_mhz*1000)
                    .set_UT_FREQ(iv_reference_frequency_khz),
                    "Safe mode freqency is greater than UltraTurbo frequency");
        }
    }

    // Recalculate the Pstate as jump uplifts may have changed the previous result
    l_rc = freq2pState(iv_attrs.attr_pm_safe_frequency_mhz*1000,
                        &l_safe_mode_ps, ROUND_NEAR, PPB_WARN);
    if (l_rc)
    {
        disable_pstates();
        // TODO: put in notification controls
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        goto fapi_try_exit;
    }

    FAPI_INF ("l_safe_mode_ps 0x%x (%d)",l_safe_mode_ps, l_safe_mode_ps);

    // Calculate safe mode set point voltage for use if an HWP has to perform
    // safe mode actuation.  Note: PGPE uses the safe mode frequency in Pstate
    // form to compute the safe mode voltage.

    if (iv_attrs.attr_system_dds_disable)
    {
        if (l_hw543384 && iv_attrs.attr_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_TIE_NEST_TO_PAU)
        {
            l_safe_mode_mv[VDD] = iv_operating_points[VPD_PT_SET_RAW][VPD_PV_CF0].vdd_mv;
            l_safe_mode_mv[VCS] = iv_operating_points[VPD_PT_SET_RAW][VPD_PV_CF0].vcs_mv;
        }
        else
        {
            l_safe_mode_mv[VDD] = ps2v_mv(l_safe_mode_ps, VDD, VPD_PT_SET_BIASED_SYSP);
            l_safe_mode_mv[VCS] = ps2v_mv(l_safe_mode_ps, VCS, VPD_PT_SET_BIASED_SYSP);
        }
        FAPI_INF("DDS disabled: Setting safe mode VDD voltage to %d mv (0x%x)",
                l_safe_mode_mv[VDD],
                l_safe_mode_mv[VDD]);
        FAPI_INF("DDS disabled: Setting safe mode VCS voltage to %d mv (0x%x)",
                l_safe_mode_mv[VCS],
                l_safe_mode_mv[VCS]);
    }
    else
    {
        uint32_t l_vdd_sm_uplift = 0;
        uint32_t l_vcs_sm_uplift = 0;

        if (l_hw543384 && iv_attrs.attr_war_mode == fapi2::ENUM_ATTR_HW543384_WAR_MODE_TIE_NEST_TO_PAU)
        {
            l_safe_mode_mv[VDD] = iv_operating_points[VPD_PT_SET_RAW][VPD_PV_CF0].vdd_mv;
            l_safe_mode_mv[VCS] = iv_operating_points[VPD_PT_SET_RAW][VPD_PV_CF0].vcs_mv;
        }
        else
        {
            l_safe_mode_mv[VDD]  = ps2v_mv(l_safe_mode_ps, VDD, VPD_PT_SET_BIASED_SYSP);
            l_vdd_sm_uplift      = l_safe_mode_mv[VDD] * iv_attrs.attr_safe_mode_nodds_uplift_0p5pct[VDD] / 1000;
            l_safe_mode_mv[VDD] += l_vdd_sm_uplift;

            l_safe_mode_mv[VCS]  = ps2v_mv(l_safe_mode_ps, VCS, VPD_PT_SET_BIASED_SYSP);
            l_vcs_sm_uplift      = l_safe_mode_mv[VCS] * iv_attrs.attr_safe_mode_nodds_uplift_0p5pct[VCS] / 1000;
            l_safe_mode_mv[VCS] += l_vcs_sm_uplift;
        }

        FAPI_INF("DDS enabled: Setting safe mode VDD voltage to %d mv (0x%x) from a base of %d mV with an uplift of %d mv",
                l_safe_mode_mv[VDD], l_safe_mode_mv[VDD],
                l_safe_mode_mv[VDD]-l_vdd_sm_uplift,
                l_vdd_sm_uplift);
        FAPI_INF("DDS enabled: Setting safe mode VCS voltage to %d mv (0x%x) from a base of %d mV with an uplift of %d mv",
                l_safe_mode_mv[VCS], l_safe_mode_mv[VCS],
                l_safe_mode_mv[VCS]-l_vcs_sm_uplift,
                l_vcs_sm_uplift);
    }


    FAPI_INF ("Setting safe mode voltages mV: VDD 0x%04x (%4d) VCS=N 0x%04x (%4d)",
                l_safe_mode_mv[VDD], l_safe_mode_mv[VDD],
                l_safe_mode_mv[VCS], l_safe_mode_mv[VCS]);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                               iv_procChip,
                               l_safe_mode_mv));

    // Read back to get any overrides
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                                iv_procChip,
                                iv_attrs.attr_pm_safe_voltage_mv));

    FAPI_INF ("Read back safe mode voltages mV: VDD 0x%04x (%4d) VDN 0x%04x (%4d)",
                iv_attrs.attr_boot_voltage_mv[VDD], iv_attrs.attr_boot_voltage_mv[VDD],
                iv_attrs.attr_boot_voltage_mv[VCS], iv_attrs.attr_boot_voltage_mv[VCS]);

    if (l_safe_mode_mv[VDD] != iv_attrs.attr_pm_safe_voltage_mv[VDD])
    {
        FAPI_INF ("Attribute override safe mode VDD voltage being used");
    }

    if (l_safe_mode_mv[VCS] != iv_attrs.attr_pm_safe_voltage_mv[VCS])
    {
        FAPI_INF ("Attribute override safe mode VCS voltage being used");
    }

    // Calculate boot mode voltages
    if (!iv_attrs.attr_boot_voltage_mv[VDD])
    {
        iv_attrs.attr_boot_voltage_mv[VDD] =
                bias_adjust_mv(iv_attrs.attr_pm_safe_voltage_mv[VDD], iv_attrs.attr_boot_voltage_biase_0p5pct);
    }

    if (!iv_attrs.attr_boot_voltage_mv[VCS])
    {
        iv_attrs.attr_boot_voltage_mv[VCS] =
                bias_adjust_mv(iv_attrs.attr_pm_safe_voltage_mv[VCS], iv_attrs.attr_boot_voltage_biase_0p5pct);
    }


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ,
                FAPI_SYSTEM, l_sys_pstate0_freq_mhz));
    if (!l_sys_pstate0_freq_mhz)
    {
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ,
        FAPI_SYSTEM, iv_attrs.attr_pm_safe_frequency_mhz));
    }

    FAPI_INF("VDD boot_mode_mv 0x%x (%d)",
        iv_attrs.attr_boot_voltage_mv[VDD],
        iv_attrs.attr_boot_voltage_mv[VDD]);

    FAPI_INF("VCS boot_mode_mv 0x%x (%d)",
        iv_attrs.attr_boot_voltage_mv[VCS],
        iv_attrs.attr_boot_voltage_mv[VCS]);


fapi_try_exit:
    FAPI_INF("<<<<<<<<<< safe_mode_computation");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   compute_retention_vid
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_retention_vid()
{
    fapi2::ReturnCode           l_rc = fapi2::FAPI2_RC_SUCCESS;
    const uint32_t              RVRM_MIN_MV = 448;
    const uint32_t              RVRM_MAX_MV = 848;

    uint32_t                    l_psave_mv;
    Pstate                      l_psave_ps;
    uint32_t                    l_ret_mv;
    fapi2::ATTR_RVRM_VID_Type   l_rvrm_rvid;

    FAPI_INF("> PlatPmPPB:compute_retention_voltage");

    // Needs kHz
    l_rc = freq2pState (iv_vddPsavFreq * 1000, &l_psave_ps, ROUND_FAST);
    if (l_rc)
    {
        FAPI_INF("PowerSave pointer frequency cannot be converted to a Pstate :  %d", iv_vddPsavFreq);
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    l_psave_mv = ps2v_mv(l_psave_ps, VDD, VPD_PT_SET_RAW);

    FAPI_DBG("PowerSave vdd_mv 0x%08x (%d)", l_psave_mv, l_psave_mv);

    // The wov_underv_vmin_mv member of the GPPB is needed to set the floor
    // voltage as seen at the circuits (but still with biases).  The safe mode
    // voltage above may have system parameter (load line, distribution loss)
    // uplifts as well core floor uplifts so it can't be used. Thus, fill in
    // wov_underv_vmin_mv with the biased VPD voltage associated with PowerSave.
    // Save the value into the PPB class for use in filling in the GPPB later.

    iv_vdd_vpd_vmin = ps2v_mv(l_psave_ps, VDD, VPD_PT_SET_BIASED);
    FAPI_INF("VDD VMIN %u mV", iv_vdd_vpd_vmin);

    l_ret_mv = l_psave_mv;
    if (l_psave_mv < RVRM_MIN_MV)
    {
        FAPI_INF("Retention voltage clipped to minimum circuit value.  Retention: %d, PSave: %d",
                    l_psave_mv, RVRM_MIN_MV);
        l_ret_mv = RVRM_MIN_MV;
    }

    if (l_psave_mv > RVRM_MAX_MV)
    {
        FAPI_INF("Retention voltage clipped to maximum circuit value.  Retention: %d, PSave: %d",
                    l_psave_mv, RVRM_MAX_MV);
        l_ret_mv = RVRM_MAX_MV;
    }

    // Rentention VID has 8mV granularity
    l_rvrm_rvid = l_ret_mv >> 3;

    FAPI_DBG("Retention:  voltage %dmV; VID: 0%08X", l_ret_mv, l_rvrm_rvid);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_RVRM_VID,
                               iv_procChip,
                               l_rvrm_rvid));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RVRM_VID,
                               iv_procChip,
                               l_rvrm_rvid));

    FAPI_DBG("Retention check VID: 0x%08X", l_rvrm_rvid);

fapi_try_exit:
    FAPI_INF("< PlatPmPPB:compute_retention_voltage");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   rvrm enablement
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::rvrm_enablement()
{
    fapi2::ATTR_RVRM_VID_Type   l_rvrm_rvid;
    uint32_t l_rvrm_rvid_mv;
    iv_rvrm_enabled = false;


    do {
        //Below class variable data comes from #V VPD, if the value is 0 then
        //QVID circut is bad, else it is good
        if ( iv_qrvrm_enable_flag == 0)
        {
            FAPI_INF("RVRM is not enabled in the #V VPD");
            iv_rvrm_enabled = false;
            break;
        }
        if (!is_rvrm_enabled())
        {
            FAPI_INF("RVRM is not enabled");
            iv_rvrm_enabled = false;
            break;
        }

        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_IS_SIMULATION_Type is_sim;
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, is_sim));

        FAPI_INF("> PlatPmPPB:rvrm_enablement");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RVRM_VID,
                        iv_procChip,
                        l_rvrm_rvid));

        FAPI_DBG("Retention check VID: 0x%08X", l_rvrm_rvid);

        // Rentention VID has 8mV granularity
        l_rvrm_rvid_mv = l_rvrm_rvid << 3;

        if (l_rvrm_rvid_mv == 0) {
            iv_rvrm_enabled = false;
        }
    } while(0);

fapi_try_exit:
    FAPI_INF("< PlatPmPPB:rvrm_enablement");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////   resclk_init
///////////////////////////////////////////////////////////
void PlatPmPPB::resclk_init()
{
    if (iv_attrs.attr_resclk_disable == fapi2::ENUM_ATTR_SYSTEM_RESCLK_DISABLE_OFF)
    {
        iv_resclk_enabled = true;
        FAPI_INF("Resonant Clocks are enabled");
    }
    else
    {
        iv_resclk_enabled = false;
        FAPI_INF("Resonant Clocks are disabled.");
    }
} // end of resclk_init


///////////////////////////////////////////////////////////
////////  ps2v_mv
///////////////////////////////////////////////////////////
uint32_t PlatPmPPB::ps2v_mv(const Pstate i_pstate,
                            const voltage_type i_type,
                            const uint32_t i_point_set)
{

    int16_t  l_SlopeValue = 1;
    uint32_t l_voltage_mv = 0;
    uint32_t r;
    bool     l_region_found = false;

    FAPI_DBG("i_pstate = 0x%02X (%3d)", i_pstate, i_pstate);

    // Find the region
    for (r = 0; r < NUM_PV_POINTS-1; ++r)
    {
        FAPI_DBG("iv_operating_points[i_point_set][%d] 0x%02X (%3d) [%d] 0x%02X (%3d)",
            r,
            iv_operating_points[i_point_set][r].pstate,
            iv_operating_points[i_point_set][r].pstate,
            r+1,
            iv_operating_points[i_point_set][r+1].pstate,
            iv_operating_points[i_point_set][r+1].pstate);
        if ((i_pstate <= iv_operating_points[i_point_set][r].pstate) &&
            (i_pstate >  iv_operating_points[i_point_set][r+1].pstate)  )
        {
            l_region_found = true;
            break;
        }
    }

    if (!l_region_found)
    {
        FAPI_INF("ERROR:  Invalid region");
        return 0;
        // Bad Region
    }

    // in 4.12 form
    l_SlopeValue =
        compute_slope_4_12( iv_operating_points[i_point_set][r+1].vdd_mv,
                            iv_operating_points[i_point_set][r].vdd_mv,
                            iv_operating_points[i_point_set][r].pstate,
                            iv_operating_points[i_point_set][r+1].pstate );

    int16_t x = l_SlopeValue * (-i_pstate + iv_operating_points[i_point_set][r].pstate);
    int16_t l_mx = x >> (VID_SLOPE_FP_SHIFT_12 -1);
    // l_mx is in the form off IIII.D

    FAPI_DBG("i_pstate = %d "
            "p2s_mv Slope = 0x%x "
            "x = 0x%x (%d) mx = 0x%x (%d)",
            i_pstate,
            l_SlopeValue,
            x, x,
            l_mx, l_mx);

    if (i_type == VDD)
    {
        FAPI_INF("VDD iv_operating_points[%d].vdd_mv 0x%-3x (%d)", r,
                 iv_operating_points[i_point_set][r].vdd_mv,
                 iv_operating_points[i_point_set][r].vdd_mv);
        FAPI_INF("VDD iv_operating_points[%d].vdd_mv 0x%-3x (%d)", r+1,
                iv_operating_points[i_point_set][r+1].vdd_mv,
                iv_operating_points[i_point_set][r+1].vdd_mv);
                              // Shift B to form IIII.D
        l_voltage_mv = l_mx + (iv_operating_points[i_point_set][r].vdd_mv << 1);
    }

    if (i_type == VCS)
    {

        FAPI_INF("VCS iv_operating_points[%d].vcs_mv 0x%-3x (%d)", r,
                (iv_operating_points[i_point_set][r].vcs_mv),
                (iv_operating_points[i_point_set][r].vcs_mv));
        FAPI_INF("VCS iv_operating_points[%d].vcs_mv 0x%-3x (%d)", r+1,
                iv_operating_points[i_point_set][r+1].vcs_mv,
                iv_operating_points[i_point_set][r+1].vcs_mv);
                              // Shift B to form IIII.D
        l_voltage_mv = l_mx + (iv_operating_points[i_point_set][r].vcs_mv << 1);
    }

    // Round up -- IIII.D + 1 and then shift to IIII
    l_voltage_mv++;
    l_voltage_mv = l_voltage_mv >> 1;

    FAPI_INF ("ps2v_mv voltage %d (0x%x)", l_voltage_mv, l_voltage_mv);

    return l_voltage_mv;
}

///////////////////////////////////////////////////////////
////////    freq2pState
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::freq2pState (
    const uint32_t i_freq_khz,
    Pstate* o_pstate,
    const FREQ2PSTATE_ROUNDING i_round,
    const PPB_ERROR i_error_mode)
{
    float deltaf = 0;
    float pstate32 = 0;
    char  round_str[32];

    deltaf = (float)iv_reference_frequency_khz - (float)i_freq_khz;

    if (!(deltaf >= 0))
    {
        if (i_error_mode != PPB_OFF)
        {
            if (i_error_mode != PPB_FAIL)
                FAPI_INF("WARNING: iv_reference_frequency_khz %d;  i_freq_khz: %d; deltaf %f",
                            iv_reference_frequency_khz, i_freq_khz, deltaf);

            if (i_error_mode == PPB_INFO)
            {
                FAPI_ASSERT_NOEXIT(false,
                            fapi2::PSTATE_PB_FREQ_GT_PSTATE0_FREQ()
                               .set_CHIP_TARGET(iv_procChip)
                               .set_FREQ_KHZ(i_freq_khz)
                               .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz),
                            "Pstate conversion frequency is greater than Pstate 0 reference");
            }
            if (i_error_mode == PPB_FAIL)
            {
                FAPI_ERR("ERROR: iv_reference_frequency_khz %d;  i_freq_khz: %d; deltaf %f",
                            iv_reference_frequency_khz, i_freq_khz, deltaf);
                FAPI_ASSERT(false,
                            fapi2::PSTATE_PB_FREQ_GT_PSTATE0_FREQ()
                               .set_CHIP_TARGET(iv_procChip)
                               .set_FREQ_KHZ(i_freq_khz)
                               .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz),
                            "Pstate conversion frequency is greater than Pstate 0 reference");
            }
        }
    }

    if (i_error_mode != PPB_OFF)
    {
        FAPI_DBG("iv_reference_frequency_khz %d;  i_freq_khz: %d; deltaf %f",
                    iv_reference_frequency_khz, i_freq_khz, deltaf);

        if (i_error_mode == PPB_INFO)
        {
            FAPI_ASSERT_NOEXIT(iv_frequency_step_khz,
                        fapi2::PSTATE_PB_PSTATE_STEP_EQ_0()
                           .set_CHIP_TARGET(iv_procChip)
                           .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz),
                       "Pstate step size is 0");
        }
        if (i_error_mode == PPB_FAIL)
        {
            FAPI_ASSERT(iv_frequency_step_khz,
                        fapi2::PSTATE_PB_PSTATE_STEP_EQ_0()
                           .set_CHIP_TARGET(iv_procChip)
                           .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz),
                       "Pstate step size is 0");
        }
    }

    // ----------------------------------
    // compute pstate for given frequency
    // ----------------------------------
    pstate32 = deltaf / (float) (iv_frequency_step_khz);
    // @todo Bug fix from Characterization team to deal with VPD not being
    // exactly in step increments
    //       - not yet included to separate changes
    // As higher Pstate numbers represent lower frequencies, the pstate must be
    // snapped to the nearest *higher* integer value for safety.  (e.g. slower
    // frequencies are safer).
    if ((i_round ==  ROUND_SLOW) && (i_freq_khz))
    {
        *o_pstate  = (Pstate)internal_ceil(pstate32);
         strcpy(round_str, "SLOW");
    }
    else if (i_round ==  ROUND_NEAR)
    {
        *o_pstate  = (Pstate)internal_round(pstate32);
         strcpy(round_str, "NEAR");
    }
    else
    {
        *o_pstate  = (Pstate)pstate32;
         strcpy(round_str, "FAST");
    }

    FAPI_DBG("freq2pState: i_freq_khz = %u (0x%X); pstate32 = %f; o_pstate = %u (0x%X) Rounding: %s",
                i_freq_khz, i_freq_khz, pstate32, *o_pstate, *o_pstate, round_str);
    FAPI_DBG("freq2pState: ref_freq_khz = %u (0x%X); step_freq_khz= %u (0x%X)",
                iv_reference_frequency_khz,
                iv_reference_frequency_khz,
                iv_frequency_step_khz,
                iv_frequency_step_khz);

    // ------------------------------
    // perform pstate bounds checking
    // ------------------------------
    if (pstate32 < PSTATE_MIN)
    {
        *o_pstate = PSTATE_MIN;
        if (i_error_mode != PPB_OFF)
        {
            if (i_error_mode == PPB_WARN)
                FAPI_INF("WARNING: Pstate is less than PSTATE_MIN");

            if (i_error_mode == PPB_INFO)
            {
                FAPI_ASSERT_NOEXIT(false,
                        fapi2::PSTATE_PB_XLATE_UNDERFLOW(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_CHIP_TARGET(iv_procChip)
                           .set_FREQ_KHZ(i_freq_khz)
                           .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz)
                           .set_PSTATE(pstate32)
                           .set_PSTATE_MIN(PSTATE_MIN),
                       "Pstate is less than PSTATE_MIN");
            }
            if (i_error_mode == PPB_FAIL)
            {
                FAPI_ASSERT(false,
                        fapi2::PSTATE_PB_XLATE_UNDERFLOW()
                           .set_CHIP_TARGET(iv_procChip)
                           .set_FREQ_KHZ(i_freq_khz)
                           .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz)
                           .set_PSTATE(pstate32)
                           .set_PSTATE_MIN(PSTATE_MIN),
                       "Pstate is less than PSTATE_MIN");
             }
        }
    }

    if (pstate32 > PSTATE_MAX)
    {
        *o_pstate = PSTATE_MAX;
        if (i_error_mode != PPB_OFF)
        {
            if (i_error_mode == PPB_WARN)
                FAPI_INF("WARNING: Pstate is greater than PSTATE_MAX");

            if (i_error_mode == PPB_INFO)
            {
                FAPI_ASSERT_NOEXIT(false,
                        fapi2::PSTATE_PB_XLATE_OVERFLOW(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_CHIP_TARGET(iv_procChip)
                           .set_FREQ_KHZ(i_freq_khz)
                           .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz)
                           .set_PSTATE(pstate32)
                           .set_PSTATE_MAX(PSTATE_MIN),
                       "Pstate is greater than PSTATE_MAX");
            }
            if (i_error_mode == PPB_FAIL)
            {
                FAPI_ASSERT(false,
                        fapi2::PSTATE_PB_XLATE_OVERFLOW()
                           .set_CHIP_TARGET(iv_procChip)
                           .set_FREQ_KHZ(i_freq_khz)
                           .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz)
                           .set_PSTATE(pstate32)
                           .set_PSTATE_MAX(PSTATE_MIN),
                       "Pstate is greater than PSTATE_MAX");
             }
        }
    }

fapi_try_exit:
    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
////////    pState2freq
///////////////////////////////////////////////////////////
void PlatPmPPB::pState2freq (const Pstate i_pstate,
                            uint32_t* o_freq_khz)
{

    // ----------------------------------
    // compute the frequency for a given Pstate
    // ----------------------------------
    *o_freq_khz = (iv_reference_frequency_khz - (i_pstate * iv_frequency_step_khz)) + 1000;

    FAPI_DBG("pState2freq: pstate = %d; o_freq_khz = %u (0x%X)",
                i_pstate,  *o_freq_khz, *o_freq_khz);
    FAPI_DBG("pState2freq: ref_freq_khz = %u (0x%X); step_freq_khz= %u (0x%X)",
                (iv_reference_frequency_khz),
                (iv_reference_frequency_khz),
                (iv_frequency_step_khz),
                (iv_frequency_step_khz));
}

///////////////////////////////////////////////////////////
////////   get_pstate_attrs
///////////////////////////////////////////////////////////
void PlatPmPPB::get_pstate_attrs(AttributeList &o_attr)
{
    memcpy(&o_attr,&iv_attrs, sizeof(iv_attrs));
} // end of get_pstate_attrs


///////////////////////////////////////////////////////////
////////  compute_PStateV_I_slope
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_PStateV_I_slope(
                GlobalPstateParmBlock_v1_t * o_gppb)
{
    uint32_t l_voltage_mv_max = 0;
    uint32_t l_voltage_mv_min = 0;
    uint8_t  l_pstate_max = 0;
    uint8_t  l_pstate_min = 0;
    uint32_t l_current_10ma_ac_tdp_max = 0;
    uint32_t l_current_10ma_ac_tdp_min = 0;
    uint32_t l_current_10ma_dc_tdp_max = 0;
    uint32_t l_current_10ma_dc_tdp_min = 0;

    uint32_t l_current_10ma_ac_rdp_max = 0;
    uint32_t l_current_10ma_ac_rdp_min = 0;
    uint32_t l_current_10ma_dc_rdp_max = 0;
    uint32_t l_current_10ma_dc_rdp_min = 0;

    char vlt_str[][4] = {"VDD","VCS"};
    char cur_str[][4] = {"IDD","ICS"};

    for(auto pt_set = 0; pt_set < NUM_VPD_PTS_SET_V1; ++pt_set)
    {
        if (!(iv_operating_points[pt_set][CF0].pstate) ||
                !(iv_operating_points[pt_set][CF1].pstate) ||
                !(iv_operating_points[pt_set][CF2].pstate) ||
                !(iv_operating_points[pt_set][CF3].pstate) ||
                !(iv_operating_points[pt_set][CF4].pstate) ||
                !(iv_operating_points[pt_set][CF5].pstate) ||
                !(iv_operating_points[pt_set][CF6].pstate)    )
        {
            FAPI_INF("Non-UltraTurbo PSTATE value shouldn't be zero for %s", vpdSetStr[pt_set]);
            return;
        }

#define COMPUTE_V_I_SLOPES(PS_V_I, slope_type, V_I_MAX, V_I_MIN, PSTATE_MAX, PSTATE_MIN)  \
     if (slope_type == NORMAL) \
    {\
        PS_V_I = revle16( \
                  compute_slope_4_12(V_I_MAX, V_I_MIN, PSTATE_MIN, PSTATE_MAX) );\
    } \
    else if (slope_type == INVERTED) \
    {\
        PS_V_I = revle16( \
                  compute_slope_4_12( PSTATE_MIN, PSTATE_MAX, V_I_MAX, V_I_MIN) );\
    }

        for(auto region(REGION_CF0_CF1); region <= REGION_CF6_CF7; ++region)
        {
            for (auto rails = RUNTIME_RAIL_VDD; rails <= RUNTIME_RAIL_VCS; rails++)
            {
                l_pstate_max = iv_operating_points[pt_set][region + 1].pstate;
                l_pstate_min = iv_operating_points[pt_set][region].pstate;
                //VOLTAGE pstate slopes
                //Calculate slopes
                if (rails == RUNTIME_RAIL_VDD)
                {
                    l_voltage_mv_max = iv_operating_points[pt_set][region + 1].vdd_mv;
                    l_voltage_mv_min = iv_operating_points[pt_set][region].vdd_mv;
                }
                else
                {
                    l_voltage_mv_max = iv_operating_points[pt_set][region + 1].vcs_mv;
                    l_voltage_mv_min = iv_operating_points[pt_set][region].vcs_mv;
                }
                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.

                //VDD Voltage slopes
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.ps_voltage_slopes[rails][pt_set][region],
                                    NORMAL, l_voltage_mv_max,l_voltage_mv_min,
                                    l_pstate_max,l_pstate_min)

                FAPI_DBG("%s ps_voltage_slopes   [%s][%s] 0x%04x %d",vlt_str[rails],
                        vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.ps_voltage_slopes[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.ps_voltage_slopes[rails][pt_set][region]));

                //Voltage inverted slopes
                //Calculate inverted slopes
                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.voltage_ps_slopes[rails][pt_set][region],
                                    INVERTED, l_voltage_mv_max,l_voltage_mv_min,
                                    l_pstate_max,l_pstate_min)

                FAPI_DBG("%s voltage_ps_slopes   [%s][%s] 0x%04x %d", vlt_str[rails],
                        vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.voltage_ps_slopes[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.voltage_ps_slopes[rails][pt_set][region]));

                //CURRENT pstate slopes
                //Calculate slopes
                if (rails == RUNTIME_RAIL_IDD)
                {
                    l_current_10ma_ac_tdp_max = iv_operating_points[pt_set][region + 1].idd_tdp_ac_10ma;
                    l_current_10ma_ac_tdp_min = iv_operating_points[pt_set][region].idd_tdp_ac_10ma;
                    l_current_10ma_dc_tdp_max = iv_operating_points[pt_set][region + 1].idd_tdp_dc_10ma;
                    l_current_10ma_dc_tdp_min = iv_operating_points[pt_set][region].idd_tdp_dc_10ma;

                    l_current_10ma_ac_rdp_max = iv_operating_points[pt_set][region + 1].idd_rdp_ac_10ma;
                    l_current_10ma_ac_rdp_min = iv_operating_points[pt_set][region].idd_rdp_ac_10ma;
                    l_current_10ma_dc_rdp_max = iv_operating_points[pt_set][region + 1].idd_rdp_dc_10ma;
                    l_current_10ma_dc_rdp_min = iv_operating_points[pt_set][region].idd_rdp_dc_10ma;
                }
                else
                {
                    l_current_10ma_ac_tdp_max = iv_operating_points[pt_set][region + 1].ics_tdp_ac_10ma;
                    l_current_10ma_ac_tdp_min = iv_operating_points[pt_set][region].ics_tdp_ac_10ma;
                    l_current_10ma_dc_tdp_max = iv_operating_points[pt_set][region + 1].ics_tdp_dc_10ma;
                    l_current_10ma_dc_tdp_min = iv_operating_points[pt_set][region].ics_tdp_dc_10ma;

                    l_current_10ma_ac_rdp_max = iv_operating_points[pt_set][region + 1].ics_rdp_ac_10ma;
                    l_current_10ma_ac_rdp_min = iv_operating_points[pt_set][region].ics_rdp_ac_10ma;
                    l_current_10ma_dc_rdp_max = iv_operating_points[pt_set][region + 1].ics_rdp_dc_10ma;
                    l_current_10ma_dc_rdp_min = iv_operating_points[pt_set][region].ics_rdp_dc_10ma;
                }

                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                // AC
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.ps_ac_current_tdp[rails][pt_set][region],
                                    NORMAL, l_current_10ma_ac_tdp_max,l_current_10ma_ac_tdp_min,
                                    l_pstate_max,l_pstate_min)

                FAPI_DBG("%s AC ps_ac_current_tdp[%s][%s] 0x%04x %d", cur_str[rails], vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.ps_ac_current_tdp[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.ps_ac_current_tdp[rails][pt_set][region]));
                //DC
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.ps_dc_current_tdp[rails][pt_set][region],
                                    NORMAL, l_current_10ma_dc_tdp_max,l_current_10ma_dc_tdp_min,
                                    l_pstate_max,l_pstate_min)

                FAPI_DBG("%s DC ps_dc_current_tdp[%s][%s] 0x%04x %d",cur_str[rails], vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.ps_dc_current_tdp[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.ps_dc_current_tdp[rails][pt_set][region]));

                //Current inverted slopes
                //Calculate inverted slopes

                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                // AC
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.ac_current_ps_tdp[rails][pt_set][region],
                                    INVERTED, l_current_10ma_ac_tdp_max,l_current_10ma_ac_tdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s AC ac_current_ps_tdp[%s][%s] 0x%04x %d",cur_str[rails],vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.ac_current_ps_tdp[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.ac_current_ps_tdp[rails][pt_set][region]));

                //DC
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.dc_current_ps_tdp[rails][pt_set][region],
                                    INVERTED, l_current_10ma_dc_tdp_max,l_current_10ma_dc_tdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s DC dc_current_ps_tdp[%s][%s] 0x%04x %d", cur_str[rails],vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.dc_current_ps_tdp[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.dc_current_ps_tdp[rails][pt_set][region]));

                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                // AC
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.ps_ac_current_rdp[rails][pt_set][region],
                                    NORMAL, l_current_10ma_ac_rdp_max,l_current_10ma_ac_rdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s AC ps_ac_current_rdp[%s][%s] 0x%04x %d", cur_str[rails], vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.ps_ac_current_rdp[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.ps_ac_current_rdp[rails][pt_set][region]));

                //DC
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.ps_dc_current_rdp[rails][pt_set][region],
                                    NORMAL, l_current_10ma_dc_rdp_max,l_current_10ma_dc_rdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s DC ps_dc_current_rdp[%s][%s] 0x%04x %d",cur_str[rails], vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.ps_dc_current_rdp[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.ps_dc_current_rdp[rails][pt_set][region]));

                //Current inverted slopes
                //Calculate inverted slopes

                // Pstate value decreases with increasing region.  Thus the values
                // are swapped to result in a positive difference.
                // AC
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.ac_current_ps_rdp[rails][pt_set][region],
                                    INVERTED, l_current_10ma_ac_rdp_max,l_current_10ma_ac_rdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s AC ac_current_ps_rdp[%s][%s] 0x%04x %d",cur_str[rails],vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.ac_current_ps_rdp[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.ac_current_ps_rdp[rails][pt_set][region]));

                //DC
                COMPUTE_V_I_SLOPES(o_gppb->poundv_slopes.dc_current_ps_rdp[rails][pt_set][region],
                                    INVERTED, l_current_10ma_dc_rdp_max,l_current_10ma_dc_rdp_min,
                                    l_pstate_max,l_pstate_min)
                FAPI_DBG("%s DC dc_current_ps_rdp[%s][%s] 0x%04x %d", cur_str[rails],vpdSetStr[pt_set], region_names[region],
                        revle16(o_gppb->poundv_slopes.dc_current_ps_rdp[rails][pt_set][region]),
                        revle16(o_gppb->poundv_slopes.dc_current_ps_rdp[rails][pt_set][region]));
            }//end of rails
        }//end of region
    } //end of pts

}


///////////////////////////////////////////////////////////
////////  compute_dds_slopes
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_dds_slopes(
                GlobalPstateParmBlock_v1_t * o_gppb)
{
    uint32_t l_max = 0;
    uint32_t l_min = 0;


#ifndef __HOSTBOOT_MODULE
    for(auto pt_set = 0; pt_set < NUM_VPD_PTS_SET_V1; ++pt_set)
    {
        for(auto region(REGION_CF0_CF1); region <= REGION_CF6_CF7; ++region)
        {
            for (auto cores = 0; cores < MAXIMUM_CORES; cores++)
            {
                PoundWEntry_t pwe;
                pwe.ddsc.value = iv_poundW_data.entry[region].entry[cores].ddsc.value;
                FAPI_DBG("ps_dds_ddsc[%s][%s][%u]: 0x%016llx  delay: 0x%04x, %d",
                        vpdSetStr[pt_set], region_names[region],cores,
                        pwe.ddsc.value,
                        pwe.ddsc.fields.insrtn_dely,
                        pwe.ddsc.fields.insrtn_dely
                        );
            }
        }
    }

    for(auto pt_set = 0; pt_set < NUM_VPD_PTS_SET_V1; ++pt_set)
    {
        for(auto region(REGION_CF0_CF1); region <= REGION_CF6_CF7; ++region)
        {
            for (auto cores = 0; cores < MAXIMUM_CORES; cores++)
            {
                PoundWEntry_t pwe;
                pwe.ddsc.value = revle64(iv_poundW_data.entry[region].entry[cores].ddsc.value);
                FAPI_DBG("ps_dds_ddsc[%s][%s][%u]: 0x%016llx  delay: 0x%04x, %d",
                        vpdSetStr[pt_set], region_names[region],cores,
                        pwe.ddsc.value,
                        pwe.ddsc.fields.insrtn_dely,
                        pwe.ddsc.fields.insrtn_dely
                        );
            }
        }
    }
#endif

    for(auto pt_set = 0; pt_set < NUM_VPD_PTS_SET_V1; ++pt_set)
    {
        for(auto region(REGION_CF0_CF1); region <= REGION_CF6_CF7; ++region)
        {
            for (auto cores = 0; cores < MAXIMUM_CORES; cores++)
            {
                //Insertion delay slopes
                if(iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.insrtn_dely >=
                    iv_poundW_data.entry[region].entry[cores].ddsc.fields.insrtn_dely)
                {

                    o_gppb->poundw_slopes.ps_dds_delay_slopes[pt_set][cores][region] =
                            revle16(compute_slope_4_12(iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.insrtn_dely,
                                iv_poundW_data.entry[region].entry[cores].ddsc.fields.insrtn_dely,
                                iv_operating_points[pt_set][region].pstate,
                                iv_operating_points[pt_set][region + 1].pstate)
                           );
                } else {
                    o_gppb->poundw_slopes.ps_dds_delay_slopes[pt_set][cores][region] =
                           revle16(compute_slope_4_12(iv_poundW_data.entry[region].entry[cores].ddsc.fields.insrtn_dely,
                                iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.insrtn_dely,
                                iv_operating_points[pt_set][region].pstate,
                                iv_operating_points[pt_set][region + 1].pstate)
                           );
                }

                FAPI_DBG("ps_dds_delay_slopes: [%s][%s][%u] 0x%04x %u 0x%04x %u delay[r]=%u delay[r+1]=%u",
                        vpdSetStr[pt_set], region_names[region],cores,
                        revle16(o_gppb->poundw_slopes.ps_dds_delay_slopes[pt_set][cores][region]),
                        revle16(o_gppb->poundw_slopes.ps_dds_delay_slopes[pt_set][cores][region]),
                        o_gppb->poundw_slopes.ps_dds_delay_slopes[pt_set][cores][region],
                        o_gppb->poundw_slopes.ps_dds_delay_slopes[pt_set][cores][region],
                        iv_poundW_data.entry[region].entry[cores].ddsc.fields.insrtn_dely,
                        iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.insrtn_dely
                        );
            }

            for (uint8_t dds_cnt = TRIP_OFFSET; dds_cnt < NUM_POUNDW_DDS_FIELDS; ++dds_cnt)
            {
                for (auto cores = 0; cores < MAXIMUM_CORES; cores++)
                {
                    switch (dds_cnt)
                    {
                        case TRIP_OFFSET:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.trip_offset;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.trip_offset;
                            break;
                        case DATA0_OFFSET:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.data0_select;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.data0_select;
                            break;
                        case DATA1_OFFSET:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.data1_select;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.data1_select;
                            break;
                        case DATA2_OFFSET:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.data2_select;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.data2_select;
                            break;
                        case LARGE_DROOP_DETECT:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.large_droop;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.large_droop;
                            break;
                        case SMALL_DROOP_DETECT:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.small_droop;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.small_droop;
                            break;
                        case SLOPEA_START_DETECT:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.slopeA_start;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.slopeA_start;
                            break;
                        case SLOPEA_END_DETECT:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.slopeA_end;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.slopeA_end;
                            break;
                        case SLOPEB_START_DETECT:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.slopeB_start;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.slopeB_start;
                            break;
                        case SLOPEB_END_DETECT:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.slopeB_end;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.slopeB_end;
                            break;
                        case SLOPEA_CYCLES:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.slopeA_cycles;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.slopeA_cycles;
                            break;
                        case SLOPEB_CYCLES:
                            l_max = iv_poundW_data.entry[region+1].entry[cores].ddsc.fields.slopeB_cycles;
                            l_min = iv_poundW_data.entry[region].entry[cores].ddsc.fields.slopeB_cycles;
                            break;
                    }

                    if(l_max >= l_min)
                    {
                        o_gppb->poundw_slopes.ps_dds_slopes[dds_cnt][pt_set][cores][region] =
                                    compute_slope_2_6(
                                        l_max,
                                        l_min,
                                        iv_operating_points[pt_set][region].pstate,
                                        iv_operating_points[pt_set][region + 1].pstate);
                    }
                    else
                    {
                        o_gppb->poundw_slopes.ps_dds_slopes[dds_cnt][pt_set][cores][region] =
                                    compute_slope_2_6(
                                        l_min,
                                        l_max,
                                        iv_operating_points[pt_set][region].pstate,
                                        iv_operating_points[pt_set][region + 1].pstate);
                    }
                    FAPI_DBG("ps_dds_slopes [%s][%s][%s][%u] max 0x%x min 0x%x slope 0x%04x %d",
                            ddsFieldStr[dds_cnt],  vpdSetStr[pt_set], region_names[region],cores,
                            l_max, l_min,
                            o_gppb->poundw_slopes.ps_dds_slopes[dds_cnt][pt_set][cores][region],
                            o_gppb->poundw_slopes.ps_dds_slopes[dds_cnt][pt_set][cores][region]);
                }
            }//end of dds_cnt
        }//end of region
    } //end of pts
}

///////////////////////////////////////////////////////////
//////// update_vrt
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::update_vrt(
                             uint8_t* i_pBuffer,
                             VRT_t* o_vrt_data)
{
    uint32_t          l_index_0 = 0;
    uint8_t           l_type = 0;
    uint32_t          l_freq_khz = 0;
    uint32_t          l_step_freq_khz;
    Pstate            l_ps;
    uint8_t           l_temp = 0;
    uint32_t          l_core_floor_mhz = 0;

    l_step_freq_khz = iv_frequency_step_khz;
//    FAPI_DBG("l_step_freq_khz = 0x%X (%d)", l_step_freq_khz, l_step_freq_khz);

#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))
    //Initialize VRT header

    o_vrt_data->vrtHeader.fields.marker       = *i_pBuffer;
    i_pBuffer++;
    o_vrt_data->vrtHeader.fields.type         = (*i_pBuffer & 0x80) >> 7;
    o_vrt_data->vrtHeader.fields.content      = (*i_pBuffer & 0x40) >> 6;
    o_vrt_data->vrtHeader.fields.version      = (*i_pBuffer & 0x30) >> 4;
    l_temp                                    = (*i_pBuffer & 0x0F);   // upper 4 bits of 5
    i_pBuffer++;
    o_vrt_data->vrtHeader.fields.io_id        = (l_temp << 1) | ((*i_pBuffer & 0x80) >> 7);
    o_vrt_data->vrtHeader.fields.ac_id        = (*i_pBuffer & 0x7C) >> 2;  // 5 bits of 5
    l_temp                                    = (*i_pBuffer & 0x03);  // upper 2 bits of 5
    i_pBuffer++;
    o_vrt_data->vrtHeader.fields.vcs_ceff_id  = (l_temp << 6) | ((*i_pBuffer & 0xE0) >> 5);
    o_vrt_data->vrtHeader.fields.vdd_ceff_id  = (*i_pBuffer & 0x1F);
    i_pBuffer++;

    //find type
    l_type = (o_vrt_data->vrtHeader.fields.type);

    char l_buffer_str[256];   // Temporary formatting string buffer
    char l_line_str[256];     // Formatted output line string

    // Filtering Tracing output to only the maximum of some dimensions
    // as these have the most interesting values to corroborate.
    bool b_output_trace = false;
    if (o_vrt_data->vrtHeader.fields.vdd_ceff_id == 25 &&
        o_vrt_data->vrtHeader.fields.vcs_ceff_id == 3 &&
        o_vrt_data->vrtHeader.fields.ac_id == 3)
    {
        b_output_trace = true;
    }

    if (b_output_trace)
    {
        strcpy(l_line_str, "VRT:");
        sprintf(l_buffer_str, " %X Type %X Content %d Ver %d IO %d AC %d VCS %d VDD %2d  ",
                o_vrt_data->vrtHeader.fields.marker,
                o_vrt_data->vrtHeader.fields.type,
                o_vrt_data->vrtHeader.fields.content,
                o_vrt_data->vrtHeader.fields.version,
                o_vrt_data->vrtHeader.fields.io_id,
                o_vrt_data->vrtHeader.fields.ac_id,
                o_vrt_data->vrtHeader.fields.vcs_ceff_id,
                o_vrt_data->vrtHeader.fields.vdd_ceff_id);
        strcat(l_line_str, l_buffer_str);
        FAPI_INF("%s ", l_line_str)
    }

    // Get the frequency biases in place and check that they all match
    double f_freq_bias = 0;
    int freq_bias_value_hp = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,
                            iv_procChip,
                            l_core_floor_mhz));
    freq_bias_value_hp = iv_bias.frequency_0p5pct;

    f_freq_bias = calc_bias(freq_bias_value_hp);

    if (f_freq_bias != 1)
        FAPI_INF("A frequency bias multiplier of %f being applied to all VRT entries",
                    f_freq_bias);

    //Initialize VRT data part
    for (l_index_0 = 0; l_index_0 < WOF_VRT_SIZE; ++l_index_0)
    {
        strcpy(l_line_str, "    ");
        strcpy(l_buffer_str, "");

        // Offset MHz*1000 (khz) + step (khz) * (sysvalue - 60)
        // Note: the table generation already did rounding so simply translate
        float l_freq_raw_khz = 0;
        float l_freq_biased_khz = 0;
        //THis condition to handle if sys vrt is less than 60
        //CeffRatio overage
        if (*i_pBuffer <= 60 )
        {
            FAPI_TRY(freq2pState(l_core_floor_mhz*1000, &l_ps, ROUND_NEAR));
            l_ps = l_ps + *i_pBuffer;
        }
        else
        {
            l_freq_raw_khz = (float)(1000 * 1000 + (l_step_freq_khz * ((*i_pBuffer) - 60)));

            l_freq_biased_khz = l_freq_raw_khz * f_freq_bias;
            l_freq_khz = (uint32_t)(l_freq_biased_khz);

            // Translate to Pstate.  The called function will clip to the
            // legal range.
            FAPI_TRY(freq2pState(l_freq_khz, &l_ps, ROUND_NEAR));
        }
        o_vrt_data->data[l_index_0] = l_ps;

        if (b_output_trace)
        {
            FAPI_DBG("sysvalue: 0x%X (%d); freq_raw_khz: %7.0f; freq_biased_khz: %7.0f; freq: %d",
            *i_pBuffer, *i_pBuffer,
            l_freq_raw_khz,
            l_freq_biased_khz,
            l_freq_khz);

            sprintf(l_buffer_str, "[%2d] PS 0x%02X MHz %4d",
                    l_index_0, o_vrt_data->data[l_index_0],  l_freq_khz / 1000);
            strcat(l_line_str, l_buffer_str);
            FAPI_INF("%s ", l_line_str);
        }

        i_pBuffer++;
    }

    // Flip the type from System (0) to HOMER (1)
    l_type = 1;
    o_vrt_data->vrtHeader.fields.type =  l_type;

fapi_try_exit:
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  dccr_value
///////////////////////////////////////////////////////////
uint64_t  PlatPmPPB::dccr_value()
{
    if (!is_dds_enabled())
    {
        iv_dccr_value = 0;
    }
    else if (!iv_dccr_value)
    {
        if (iv_attrs.attr_wof_dccr_value)
        {
            // Attributes are already Endianness corrected
            iv_dccr_value = iv_attrs.attr_wof_dccr_value;
            FAPI_INF("Setting DCCR to attribute value of %016llX", iv_dccr_value);
        }
        else if (iv_poundW_data.other.droop_count_control != 0)
        {
            iv_dccr_value = iv_poundW_data.other.droop_count_control;
            FAPI_INF("Using #W DCCR value of %016llX", iv_dccr_value);
        }
        else
        {
          iv_dccr_value = 0x283E93E9C0000000ull;
          FAPI_INF("Setting DCCR to internal default of 0x%016llX as #W value is 0.",
                    iv_dccr_value);
        }
        FAPI_ATTR_SET(fapi2::ATTR_WOF_DCCR_VALUE, iv_procChip, iv_dccr_value);
    }
    return iv_dccr_value;
}

///////////////////////////////////////////////////////////
////////  flmr_value
///////////////////////////////////////////////////////////
uint64_t  PlatPmPPB::flmr_value()
{
    if (!is_dds_enabled())
    {
        iv_flmr_value = 0;
    }
    else if (!iv_flmr_value)
    {
        if (iv_attrs.attr_wof_flmr_value)
        {
            // Attributes are already Endianness corrected
            iv_flmr_value = iv_attrs.attr_wof_flmr_value;
            FAPI_INF("Setting FLMR to attribute value of %016llX", iv_flmr_value);
        }
        else if (iv_poundW_data.other.ftc_large_droop_mode_reg_setting != 0)
        {
            iv_flmr_value = iv_poundW_data.other.ftc_large_droop_mode_reg_setting;
            FAPI_INF("Using #W FLMR value of %016llX", iv_flmr_value);
        }
        else
        {
          iv_flmr_value = 0x23E0404000000000ull;
          FAPI_INF("Setting FLMR to internal default of 0x%016llX as #W value is 0.",
                    iv_flmr_value);
        }
        FAPI_ATTR_SET(fapi2::ATTR_WOF_FLMR_VALUE, iv_procChip, iv_flmr_value);
    }
    return iv_flmr_value;
}

///////////////////////////////////////////////////////////
////////  fmmr_value
///////////////////////////////////////////////////////////
uint64_t  PlatPmPPB::fmmr_value()
{
    if (!is_dds_enabled())
    {
        iv_fmmr_value = 0;
    }
    else if (!iv_fmmr_value)
    {
        if (iv_attrs.attr_wof_fmmr_value)
        {
            // Attributes are already Endianness corrected
            iv_fmmr_value = iv_attrs.attr_wof_fmmr_value;
            FAPI_INF("Setting FMMR to attribute value of %016llX", iv_fmmr_value);
        }
        else if (iv_poundW_data.other.ftc_misc_droop_mode_reg_setting != 0 )
        {
            iv_fmmr_value = iv_poundW_data.other.ftc_misc_droop_mode_reg_setting;
            FAPI_INF("Using #W FMMR value of %016llX", iv_fmmr_value);
        }
        else
        {
            iv_fmmr_value = 0x048022C004424010ull;
            FAPI_INF("Setting FMMR to internal default of 0x%016llX as #W value is 0.",
                    iv_fmmr_value);
        }
        FAPI_ATTR_SET(fapi2::ATTR_WOF_FMMR_VALUE, iv_procChip, iv_fmmr_value);
    }
    return iv_fmmr_value;
}

///////////////////////////////////////////////////////////
//////// wof_convert_tables
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::wof_convert_tables(
                             fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data,
                             uint8_t* o_buf,
                             uint32_t& io_size)
{
    FAPI_DBG(">> wof_convert_tables");

    fapi2::ReturnCode l_rc = 0;
    uint16_t l_vdd_size = 0;
    uint16_t l_vcs_size = 0;
    uint16_t l_io_size  = 0;
    uint16_t l_ac_size  = 0;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

#ifdef __HOSTBOOT_MODULE
    fapi2::ATTR_SYSTEM_WOF_VALIDATION_MODE_Type l_wof_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_VALIDATION_MODE, FAPI_SYSTEM, l_wof_mode));
    FAPI_INF("Running WOF Validation checking under FW controls = %d", l_wof_mode);
#else
    fapi2::ATTR_SYSTEM_WOF_LAB_VALIDATION_MODE_Type l_wof_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_LAB_VALIDATION_MODE, FAPI_SYSTEM, l_wof_mode));
    FAPI_INF("Running WOF Validation checking under LAB controls = %d", l_wof_mode);
#endif

    VRT_t l_vrt;
    memset (&l_vrt, 0, sizeof(l_vrt));

    do
    {

        // Copy WOF header data to the output buffer
        memcpy (o_buf, (*l_wof_table_data), sizeof(WofTablesHeader_t));

        uint32_t l_wof_table_index = sizeof(WofTablesHeader_t);
        uint32_t l_index = sizeof(WofTablesHeader_t);

        WofTablesHeader_t* p_wfth;
        p_wfth = reinterpret_cast<WofTablesHeader_t*>(o_buf);

        l_vcs_size = revle16(p_wfth->vcs_size);
        l_vdd_size = revle16(p_wfth->vdd_size);
        l_io_size  = revle16(p_wfth->io_size);
        l_ac_size  = revle16(p_wfth->amb_cond_size);

        uint32_t l_total_index = l_vcs_size * l_vdd_size * l_io_size * l_ac_size;

        FAPI_INF("WOF: vcs_size %02d, vdd_size %02d io_size %02d, ac_size %02d",
                        l_vcs_size, l_vdd_size, l_io_size,l_ac_size);
        FAPI_INF("WOF: total_index  %02d", l_total_index);

        //init ATTR_WOF_TDP_IO_INDEX to facilitate IODLR operation by XGPE
        fapi2::ATTR_WOF_TDP_IO_INDEX_Type l_wof_tdp_io_index;
        l_wof_tdp_io_index  =   p_wfth->io_tdp_pwr_indx;
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_WOF_TDP_IO_INDEX, iv_procChip, l_wof_tdp_io_index ) );
        FAPI_DBG( "ATTR_WOF_TDP_IO_INDEX value is 0x%02x", l_wof_tdp_io_index );

        // Convert system vrt to homer vrt
        for (uint32_t vrt_index = 0;
                vrt_index < l_total_index;
                ++vrt_index)
        {
            FAPI_DBG ("l_wof_table_index %d vrt_index %d", l_wof_table_index, vrt_index);
            FAPI_DBG("Addresses: *l_wof_table_data %p  *l_wof_table_data+l_wof_table_index %p",
                    *l_wof_table_data,  (*l_wof_table_data) + l_wof_table_index);

            l_rc = update_vrt (
                    ((*l_wof_table_data) + l_wof_table_index),
                    &l_vrt
                    );
            if (l_rc)
            {
                disable_wof();
                FAPI_TRY(l_rc);  // Exit the function as a fail
            }

            FAPI_DBG("VRT post update: index %04d  l_vrt fields marker %X io %01d ac %01d vc %02d vd %02d",
                    l_wof_table_index,
                    l_vrt.vrtHeader.fields.marker,
                    l_vrt.vrtHeader.fields.io_id,
                    l_vrt.vrtHeader.fields.ac_id,
                    l_vrt.vrtHeader.fields.vcs_ceff_id,
                    l_vrt.vrtHeader.fields.vdd_ceff_id
                    );

            // Check for "V" at the start of the magic number

            if ((l_vrt.vrtHeader.fields.marker != 0x56) && is_wof_enabled())
            {

                disable_wof();

                if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_WARN ||
                    l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_INFO   )
                {
                    FAPI_INF("WARNING: VRT marker not detected:  Marker: %X.  WOF is being disabled.",
                            l_vrt.vrtHeader.fields.marker);
                }

                if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_INFO)
                {
                    FAPI_ASSERT_NOEXIT(false,
                        fapi2::PSTATE_PB_VRT_HEADER_DATA_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                        .set_CHIP_TARGET(FAPI_SYSTEM)
                        .set_MAGIC_NUMBER(l_vrt.vrtHeader.fields.marker)
                        .set_VRT_INDEX(vrt_index),
                        "Pstate Parameter Block: Invalid VRT Magic word");
                }
                else if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_FAIL)
                {
                    FAPI_ERR("ERROR: VRT marker not detected:  Marker: %X.  WOF is being disabled.",
                            l_vrt.vrtHeader.fields.marker);
                    FAPI_ASSERT(false,
                        fapi2::PSTATE_PB_VRT_HEADER_DATA_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                        .set_CHIP_TARGET(FAPI_SYSTEM)
                        .set_MAGIC_NUMBER(l_vrt.vrtHeader.fields.marker)
                        .set_VRT_INDEX(vrt_index),
                        "Pstate Parameter Block: Invalid VRT Magic word");
                break;
                }
            }
            l_vrt.vrtHeader.value = revle32(l_vrt.vrtHeader.value);
            l_wof_table_index += sizeof (l_vrt);

            memcpy(o_buf + l_index, &l_vrt, sizeof (l_vrt));
            l_index += sizeof (l_vrt);
        }

        io_size = l_index;
        FAPI_DBG("Converted io_size = %d", io_size);
    }
    while(0);

fapi_try_exit:
    FAPI_DBG("<< wof_convert_tables");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  wof_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::wof_init(
                             uint8_t* o_buf,
                             uint32_t& io_size)
{
    FAPI_DBG(">> WOF initialization");
    bool b_wof_error = false;

    // Use new to avoid over-running the stack
    fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data =
        (fapi2::ATTR_WOF_TABLE_DATA_Type*)new fapi2::ATTR_WOF_TABLE_DATA_Type;

    do
    {
        if (!is_wof_enabled())
        {
            FAPI_INF("WOF is not enabled");
            iv_wof_enabled = false;
            break;
        }

        if (wof_get_tables(iv_procChip, l_wof_table_data))
        {
            b_wof_error = true;
        }
        if (wof_validate_header(iv_procChip, l_wof_table_data))
        {
          b_wof_error = true;
        }
        if (wof_convert_tables( l_wof_table_data, o_buf, io_size ))
        {
          b_wof_error = true;
        }
    } while(0);

    // This is for the case that the magic number didn't match and we don't
    // want to fail;  rather, we just disable WOF.
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

    if(b_wof_error)
    {
        FAPI_INF("Disabling WOF");
        disable_wof();
    }
    if (l_wof_table_data)
    {
        delete[] l_wof_table_data;
        l_wof_table_data = nullptr;
    }
    FAPI_DBG("<< WOF initialization");
    return  fapi2::FAPI2_RC_SUCCESS;
}

///////////////////////////////////////////////////////////
////////    set_global_feature_attributes
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::set_global_feature_attributes()
{

    FAPI_INF("set_global_feature_attributes")
    fapi2::ATTR_PSTATES_ENABLED_Type l_ps_enabled =
        (fapi2::ATTR_PSTATES_ENABLED_Type)fapi2::ENUM_ATTR_PSTATES_ENABLED_FALSE;

    fapi2::ATTR_RESCLK_ENABLED_Type l_resclk_enabled =
        (fapi2::ATTR_RESCLK_ENABLED_Type)fapi2::ENUM_ATTR_RESCLK_ENABLED_FALSE;

    fapi2::ATTR_DDS_ENABLED_Type l_dds_enabled =
        (fapi2::ATTR_DDS_ENABLED_Type)fapi2::ENUM_ATTR_DDS_ENABLED_FALSE;

    fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled =
        (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_FALSE;

    fapi2::ATTR_RVRM_ENABLED_Type l_rvrm_enabled =
        (fapi2::ATTR_RVRM_ENABLED_Type)fapi2::ENUM_ATTR_RVRM_ENABLED_FALSE;

    fapi2::ATTR_OCS_ENABLED_Type l_ocs_enabled =
        (fapi2::ATTR_OCS_ENABLED_Type)fapi2::ENUM_ATTR_OCS_ENABLED_FALSE;

    fapi2::ATTR_WOF_THROTTLE_CONTROL_DISABLED_Type l_wof_throttle_disabled =
        (fapi2::ATTR_WOF_THROTTLE_CONTROL_DISABLED_Type)fapi2::ENUM_ATTR_WOF_THROTTLE_CONTROL_DISABLED_FALSE;

    fapi2::ATTR_WOV_UNDERV_ENABLED_Type l_wov_underv_enabled =
        (fapi2::ATTR_WOV_UNDERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_UNDERV_ENABLED_FALSE;

    fapi2::ATTR_WOV_OVERV_ENABLED_Type l_wov_overv_enabled =
        (fapi2::ATTR_WOV_OVERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_OVERV_ENABLED_FALSE;

    if (iv_pstates_enabled)
    {
        l_ps_enabled = (fapi2::ATTR_PSTATES_ENABLED_Type)fapi2::ENUM_ATTR_PSTATES_ENABLED_TRUE;
    }

    if (iv_resclk_enabled)
    {
        l_resclk_enabled = (fapi2::ATTR_RESCLK_ENABLED_Type)fapi2::ENUM_ATTR_RESCLK_ENABLED_TRUE;
    }

    if (iv_dds_enabled)
    {
        l_dds_enabled = (fapi2::ATTR_DDS_ENABLED_Type)fapi2::ENUM_ATTR_DDS_ENABLED_TRUE;
    }

    if (iv_rvrm_enabled)
    {
        l_rvrm_enabled = (fapi2::ATTR_RVRM_ENABLED_Type)fapi2::ENUM_ATTR_RVRM_ENABLED_TRUE;
    }

    if (iv_wof_enabled)
    {
        l_wof_enabled = (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_TRUE;
    }

    if (iv_ocs_enabled)
    {
        l_ocs_enabled = (fapi2::ATTR_OCS_ENABLED_Type)fapi2::ENUM_ATTR_OCS_ENABLED_TRUE;
    }

    if (iv_wof_throttle_enabled)
    {
        l_wof_throttle_disabled = (fapi2::ATTR_WOF_THROTTLE_CONTROL_DISABLED_Type)fapi2::ENUM_ATTR_WOF_THROTTLE_CONTROL_DISABLED_FALSE;
    }

    if (iv_wov_underv_enabled)
    {
        l_wov_underv_enabled = (fapi2::ATTR_WOV_UNDERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_UNDERV_ENABLED_TRUE;
    }

    if (iv_wov_overv_enabled)
    {
        l_wov_overv_enabled = (fapi2::ATTR_WOV_OVERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_OVERV_ENABLED_TRUE;
    }

    SET_ATTR(fapi2::ATTR_PSTATES_ENABLED, iv_procChip, l_ps_enabled);
    SET_ATTR(fapi2::ATTR_RESCLK_ENABLED, iv_procChip, l_resclk_enabled);
    SET_ATTR(fapi2::ATTR_DDS_ENABLED, iv_procChip, l_dds_enabled);
    SET_ATTR(fapi2::ATTR_RVRM_ENABLED, iv_procChip, l_rvrm_enabled);
    SET_ATTR(fapi2::ATTR_WOF_ENABLED, iv_procChip, l_wof_enabled);
    SET_ATTR(fapi2::ATTR_OCS_ENABLED, iv_procChip, l_ocs_enabled);
    SET_ATTR(fapi2::ATTR_WOF_THROTTLE_CONTROL_DISABLED, iv_procChip, l_wof_throttle_disabled);
    SET_ATTR(fapi2::ATTR_WOV_UNDERV_ENABLED, iv_procChip, l_wov_underv_enabled);
    SET_ATTR(fapi2::ATTR_WOV_OVERV_ENABLED, iv_procChip, l_wov_overv_enabled);


fapi_try_exit:
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  pdv_freq_override
///////////////////////////////////////////////////////////
bool pdv_override(uint16_t* value, uint16_t override_value)
{
    bool override_flag;
    if (override_value == 0)
    {
        override_flag = false;
    }
    else
    {
        *value = override_value;
        override_flag = true;
    }
    return override_flag;
}

///////////////////////////////////////////////////////////
////////  pm_set_frequency
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::pm_set_frequency()
{
    FAPI_INF("PlatPmPPB::pm_set_frequency >>>>>");
    fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ_Type l_sys_pstate0_freq_mhz = 0;

    fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled;
    auto sys_target = iv_procChip.getParent<fapi2::TARGET_TYPE_SYSTEM>();
    bool wof_state = false;

    //We need to check this , for the specific enum
    //value to check FORCE_DISABLED, because for non sorted parts
    //we set this value to disable the wof
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLED, iv_procChip, l_wof_enabled));
    if (l_wof_enabled == fapi2::ENUM_ATTR_WOF_ENABLED_FORCE_DISABLED)
    {
        iv_wof_enabled = false;
        wof_state = iv_wof_enabled;
    }
    else
    {
        wof_state = is_wof_enabled();
    }

    FAPI_TRY(p10_pm_set_system_freq(sys_target,wof_state), "p10_pm_set_system_freq failed.");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PSTATE0_FREQ_MHZ,
             sys_target, l_sys_pstate0_freq_mhz));

    iv_attrs.attr_pstate0_freq_mhz = l_sys_pstate0_freq_mhz;
    iv_reference_frequency_mhz = l_sys_pstate0_freq_mhz;
    iv_reference_frequency_khz = iv_reference_frequency_mhz * 1000;

    if ((iv_reference_frequency_mhz == 0) || (iv_reference_frequency_khz == 0))
    {

        disable_pstates();

        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE_Type l_pdv_mode;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PDV_VALIDATION_MODE,
                    FAPI_SYSTEM, l_pdv_mode));

        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_WARN ||
            l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO   )
        {
            FAPI_INF("**** WARNING : Pstate0 frequency is not set.");
            FAPI_INF("**** WARNING : Pstates (and all dependent functions) are disabled but continuing on anyway.");
            FAPI_INF("**** WARNING : Tracing due to ATTR_SYSTEM_PDV_VALIDATION_MODE = WARN or INFO");
        }

        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_INFO)
        {
            if (!fapi2::is_platform<fapi2::PLAT_CRONUS>())
            {
            	FAPI_ASSERT_NOEXIT(false,
            	        fapi2::PSTATE_PB_PSTATE0_FREQ_NOT_SET(fapi2::FAPI2_ERRL_SEV_RECOVERED)
            	        .set_CHIP_TARGET(iv_procChip)
            	        .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz),
            	        "Pstate Parameter Block Pstate0 reference frequency not set");
            }
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

        if (l_pdv_mode == fapi2::ENUM_ATTR_SYSTEM_PDV_VALIDATION_MODE_FAIL)
        {
            FAPI_ERR("**** ERROR : Pstate0 frequency is not set.");
            FAPI_ERR("**** ERROR : Pstates (and all dependent functions) are disabled but continuing on anyway.");
            FAPI_ERR("**** ERROR : Halting due to ATTR_SYSTEM_PDV_VALIDATION_MODE = FAIL");

           FAPI_ASSERT_NOEXIT(false,
                    fapi2::PSTATE_PB_PSTATE0_FREQ_NOT_SET()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_SYSTEM_PSTATE0_FREQ_KHZ(iv_reference_frequency_khz),
                    "Pstate Parameter Block Pstate0 reference frequency not set");
        }
    }

fapi_try_exit:
    FAPI_INF("PlatPmPPB::pm_set_frequency <<<<<<<");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  set_wof_override_flags
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::set_wof_override_flags(
                      voltageBucketData_t* i_poundV_data)
{
    FAPI_INF("PlatPmPPB::set_wof_override_flags >>>>>");

    do
    {
        fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLED, iv_procChip, l_wof_enabled));

        if (!l_wof_enabled)
        {
            FAPI_INF("  WOF not enabled.  No overrides are applied.");
            break;
        }

        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type ps_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_PS, FAPI_SYSTEM, ps_ovrd));
        iv_wts_vddPsavFreqOverride = ps_ovrd ? true : false;

        fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type wb_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_WB, FAPI_SYSTEM, wb_ovrd));
        iv_wts_vddWofBaseFreqOverride = wb_ovrd ? true : false;

        fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type ut_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_UT, FAPI_SYSTEM, ut_ovrd));
        iv_wts_vddUTFreqOverride = ut_ovrd ? true : false;

        fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type ff_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_FF, FAPI_SYSTEM, ff_ovrd));
        iv_wts_vddFixedFreqOverride = ff_ovrd ? true : false;

        fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type sp_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_SP, FAPI_SYSTEM, sp_ovrd));
        iv_wts_sortPowerOverride = sp_ovrd ? true : false;

        fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type rc_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_RC, FAPI_SYSTEM, rc_ovrd));
        iv_wts_sortRdpCurrent = rc_ovrd ? true : false;

        // Put #V into processable data structures.
        // Note: because the way #V keyword was defined, it does not allow for direct
        //    structure mapping as there is an intermediate byte that throws off C++
        //    member alignment. Thus, the keyword data is processed as a byte stream.

        FAPI_INF("Raw #V post-overrides");
        FAPI_TRY(print_voltage_bucket(iv_procChip, i_poundV_data));
    }while(0);


fapi_try_exit:
    FAPI_INF("PlatPmPPB::set_wof_override_flags <<<<<<<");
    return fapi2::current_err;
}

// *INDENT-ON*
