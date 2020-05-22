/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pstate_parameter_block.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include "p9_resclk_defines.H"
#include <attribute_ids.H>
#include <math.h>

using namespace pm_pstate_parameter_block;


//Pstate macros
#define PSTATE_MAX                 255
#define PSTATE_MIN                 0
#define NUM_OP_POINTS              4

#define VPD_PV_POWERSAVE           1
#define VPD_PV_NOMINAL             0
#define VPD_PV_TURBO               2
#define VPD_PV_ULTRA               3
#define VPD_PV_POWERBUS            4

#define VPD_PV_CORE_FREQ_MHZ       0
#define VPD_PV_VDD_MV              1
#define VPD_PV_IDD_100MA           2
#define VPD_PV_VCS_MV              3
#define VPD_PV_ICS_100MA           4
#define VPD_PV_PB_FREQ_MHZ         0
#define VPD_PV_VDN_MV              1
#define VPD_PV_IDN_100MA           2



#define SET_ATTR(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_SET(attr_name, target, attr_assign),"Attribute set failed"); \
    FAPI_INF("%-60s = 0x%08x %d", #attr_name, attr_assign, attr_assign);



#define VPD_PV_ORDER               {VPD_PV_POWERSAVE, VPD_PV_NOMINAL, VPD_PV_TURBO, VPD_PV_ULTRA}
#define VPD_PV_ORDER_STR           {"Nominal   ","PowerSave ", "Turbo     ", "UltraTurbo"}
#define VPD_THRESHOLD_ORDER_STR    {"Overvolt", "Small", "Large", "Extreme" }
#define PV_OP_ORDER                {POWERSAVE, NOMINAL, TURBO, ULTRA}
#define PV_OP_ORDER_STR            {"PowerSave ", "Nominal   ","Turbo     ", "UltraTurbo"}
#define IDDQ_ARRAY_VOLTAGES        { 0.60 ,  0.70 ,  0.80 ,  0.90 ,  1.00 ,  1.10}
#define IDDQ_ARRAY_VOLTAGES_STR    {"0.60", "0.70", "0.80", "0.90", "1.00", "1.10"}
#define POUNDV_SLOPE_CHECK(x,y)   x > y ? " is GREATER (ERROR!) than " : " is less than "


const uint8_t pv_op_order[NUM_OP_POINTS] = VPD_PV_ORDER;
const char*   pv_op_str[NUM_OP_POINTS] = VPD_PV_ORDER_STR;

#define MAX_ACTIVE_CORES           24
#define ACTIVE_QUADS               6

//WOF constants
#define HOMER_WOF_TABLE_SIZE       258176
#define VDN_PERCENT_KEY            35
#define QID_KEY                    6

//VPD(#V & #W) constants
#define PV_D                       5
#define PV_W                       5
#define IQ_BUFFER_ALLOC            255
#define FULLY_VALID_POUNDW_VERSION 3
#define GREYCODE_INDEX_M32MV       4

//#W data verification
#define VALIDATE_VID_VALUES(w, x, y, z, state)   \
    if (!((w <= x) && (x <= y) && (y <= z)))  \
    { state = 0; }

#define VALIDATE_THRESHOLD_VALUES(w, x, y, z, state) \
    if ((w > 0x7 && w != 0xC) || /* overvolt */   \
        (x == 8) ||  (x == 9) || (x > 0xF) ||     \
        (y == 8) ||  (y == 9) || (y > 0xF) ||     \
        (z == 8) ||  (z == 9) || (z > 0xF)   )    \
    { state = 0; }

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


#define VALIDATE_WOF_HEADER_DATA(a, b, c, d, e, f, g, state)         \
    if ( ((!a) || (!b) || (!c) || (!d) || (!e) || (!f) || (!g)))  \
    { state = 0; }
// #W sample data
const fapi2::vdmData_t g_vpdData =
{
    1, 2,
    {
        0x29, 0x0C, 0x05, 0xC3, 0x61, 0x36, 0x1, 0x3, 0x0, 0x0,   //Nominal
        0x28, 0xa8, 0x05, 0x5f, 0x21, 0x36, 0x1, 0x3, 0x0, 0x0,   //PowerSave
        0x29, 0x70, 0x06, 0x27, 0x71, 0x36, 0x1, 0x3, 0x0, 0x0,   //Turbo
        0x29, 0xD4, 0x06, 0x8b, 0x51, 0x36, 0x1, 0x3, 0x0, 0x0,   //UltraTurbo
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0, 0x0, 0x0, 0x0,   //Resistance
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0, 0x0, 0x0, 0x0    //Spare
    }
};



//Sample data to verify functionality
//
// WOF sample data
const uint8_t g_wofData[] =
{
    0x57, 0x46, 0x54, 0x48  /*MAGIC CODE WFTH*/,
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

//Sample VFRT data
const uint8_t g_sysvfrtData[] =
{
    0x56, 0x54,      // Magic_code 2B)
    0x00, 0x00,      // reserved (2B)
    0x02,            // type(4b),version(4b)
    VDN_PERCENT_KEY, // vdn percentage(1B),
    0x05,            // vdd percentage(1B)
    QID_KEY,         // quad id(1B)
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA5, 0xA5, 0xA1, 0x9D, 0x9A, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA5, 0xA5,
    0xA1, 0x9D, 0x9A, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA5, 0xA5, 0xA1, 0x9D, 0x9A,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA5, 0xA5, 0xA1, 0x9D, 0x9A, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8,
    0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA8, 0xA5, 0xA5,
    0xA1, 0x9D, 0x9A
};


// Strings used in traces
char const* vpdSetStr[NUM_VPD_PTS_SET] = VPD_PT_SET_ORDER_STR;
char const* region_names[]             = { "REGION_POWERSAVE_NOMINAL",
                                           "REGION_NOMINAL_TURBO",
                                           "REGION_TURBO_ULTRA"
                                         };
char const* prt_region_names[]         = VPD_OP_SLOPES_REGION_ORDER_STR;

const uint32_t LEGACY_RESISTANCE_ENTRY_SIZE =  10;

//the value in this table are in Index format
uint8_t g_GreyCodeIndexMapping [] =
{
    /*   0mV  0x00*/ 0,
    /* - 8mV  0x01*/ 1,
    /* -24mV  0x02*/ 3,
    /* -16mV  0x03*/ 2,
    /* -56mV  0x04*/ 7,
    /* -48mV  0x05*/ 6,
    /* -32mV  0x06*/ 4,
    /* -40mV  0x07*/ 5,
    /* -96mV  0x08*/ 12,
    /* -96mV  0x09*/ 12,
    /* -96mV  0x0a*/ 12,
    /* -96mV  0x0b*/ 12,
    /* -64mV  0x0c*/ 8,
    /* -72mV  0x0d*/ 9,
    /* -88mV  0x0e*/ 11,
    /* -80mV  0x0f*/ 10
};


///////////////////////////////////////////////////////////
////////     p9_pstate_parameter_block
///////////////////////////////////////////////////////////
fapi2::ReturnCode
p9_pstate_parameter_block( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           PstateSuperStructure* io_pss,
                           uint8_t* o_buf,
                           uint32_t& io_size)
{
    FAPI_IMP("> p9_pstate_parameter_block");
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ReturnCode l_rc         = 0;
    io_size = 0;

    do
    {
        //Instantiate pstate object
        PlatPmPPB l_pmPPB(i_target);

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
        LocalPstateParmBlock l_localppb[MAX_QUADS_PER_CHIP];
        memset ( &l_localppb, 0, ( MAX_QUADS_PER_CHIP * sizeof(LocalPstateParmBlock) ) );

        // OCC content
        OCCPstateParmBlock l_occppb;
        memset (&l_occppb , 0, sizeof (OCCPstateParmBlock));

        //if PSTATES_MODE is off then we dont need to execute further to collect
        //the data.
        if (l_pmPPB.isPstateModeEnabled())
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
        FAPI_TRY(l_pmPPB.vpd_init(),"vpd_init function failed");

        if (!l_pmPPB.isEqChipletPresent())
        {
            FAPI_IMP("**** WARNING : There are no EQ chiplets present which means there is no valid #V VPD");
            FAPI_IMP("**** WARNING : Pstates and all related functions will NOT be enabled.");

            // Set the io_size to 0 so that memory allocation issues won't be
            // detected by the caller.
            io_size = 0;
            break;
        }

        // ----------------
        // get IVRM Parameters data
        // ----------------
        // TBD
        FAPI_INF("Getting IVRM Parameters Data");
        FAPI_TRY(l_pmPPB.get_ivrm_parms());

        // ----------------
        // Compute VPD points for different regions
        // ----------------
        l_pmPPB.compute_vpd_pts();

        // ----------------
        // Safe mode freq and volt init
        // ----------------
        FAPI_TRY(l_pmPPB.safe_mode_init());

        // ----------------
        // Initialize  VDM data
        // ----------------
        FAPI_TRY(l_pmPPB.vdm_init());

        // ----------------
        // get Resonant clocking attributes
        // ----------------
        FAPI_TRY(l_pmPPB.resclk_init());

        // ----------------
        // Initialize GPPB structure
        // ----------------
        FAPI_TRY(l_pmPPB.gppb_init(&l_globalppb));

        // ----------------
        // Initialize LPPB structure
        // ----------------
        FAPI_TRY(l_pmPPB.lppb_init(&l_localppb[0]));

        // ----------------
        // WOF initialization
        // ----------------
        io_size = 0;
        FAPI_TRY(l_pmPPB.wof_init(
                 o_buf,
                 io_size),
                 "WOF initialization failure");

        // ----------------
        //Initialize OPPB structure
        // ----------------
        FAPI_TRY(l_pmPPB.oppb_init(&l_occppb));

        // ----------------
        //Initialize pstate feature attribute state
        // ----------------
        FAPI_TRY(l_pmPPB.set_global_feature_attributes());


        // Put out the Parmater Blocks to the trace
        FAPI_TRY(gppb_print(&(l_globalppb), i_target));
        oppb_print(&(l_occppb));

        // Populate Global,local and OCC parameter blocks into Pstate super structure
        (*io_pss).globalppb =   l_globalppb;
        (*io_pss).occppb    =   l_occppb;

        memcpy( &((*io_pss).localppb), &l_localppb, ( MAX_QUADS_PER_CHIP * sizeof(LocalPstateParmBlock) ) );
    }
    while(0);

fapi_try_exit:
    FAPI_IMP("< p9_pstate_parameter_block");
    return fapi2::current_err;
}
// END OF PSTATE PARAMETER BLOCK function


///////////////////////////////////////////////////////////
////////    freq2pState
///////////////////////////////////////////////////////////
int PlatPmPPB::freq2pState (const uint32_t i_freq_khz,
                            Pstate* o_pstate,
                            const FREQ2PSTATE_ROUNDING i_round)
{
    int rc = 0;
    float pstate32 = 0;

    // ----------------------------------
    // compute pstate for given frequency
    // ----------------------------------
    pstate32 = ((float)((iv_reference_frequency_khz) - (float)i_freq_khz)) /
                (float) (iv_frequency_step_khz);
    // @todo Bug fix from Characterization team to deal with VPD not being
    // exactly in step increments
    //       - not yet included to separate changes
    // As higher Pstate numbers represent lower frequencies, the pstate must be
    // snapped to the nearest *higher* integer value for safety.  (e.g. slower
    // frequencies are safer).
    if ((i_round ==  ROUND_SLOW) && (i_freq_khz))
    {
        *o_pstate  = (Pstate)internal_ceil(pstate32);
        FAPI_DBG("freq2pState: ROUND SLOW");
    }
    else
    {
        *o_pstate  = (Pstate)pstate32;
         FAPI_DBG("freq2pState: ROUND FAST");
    }

    FAPI_DBG("freq2pState: i_freq_khz = %u (0x%X); pstate32 = %f; o_pstate = %u (0x%X)",
                i_freq_khz, i_freq_khz, pstate32, *o_pstate, *o_pstate);
    FAPI_DBG("freq2pState: ref_freq_khz = %u (0x%X); step_freq_khz= %u (0x%X)",
                (iv_reference_frequency_khz),
                (iv_reference_frequency_khz),
                (iv_frequency_step_khz),
                (iv_frequency_step_khz));

    // ------------------------------
    // perform pstate bounds checking
    // ------------------------------
    if (pstate32 < PSTATE_MIN)
    {
        rc = -PSTATE_LT_PSTATE_MIN;
        *o_pstate = PSTATE_MIN;
    }

    if (pstate32 > PSTATE_MAX)
    {
        rc = -PSTATE_GT_PSTATE_MAX;
        *o_pstate = PSTATE_MAX;
    }

    return rc;
} //end of freq2pState


///////////////////////////////////////////////////////////
////////    set_global_feature_attributes
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::set_global_feature_attributes()
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

    fapi2::ATTR_WOV_UNDERV_ENABLED_Type l_wov_underv_enabled =
        (fapi2::ATTR_WOV_UNDERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_UNDERV_ENABLED_FALSE;

    fapi2::ATTR_WOV_OVERV_ENABLED_Type l_wov_overv_enabled =
        (fapi2::ATTR_WOV_OVERV_ENABLED_Type)fapi2::ENUM_ATTR_WOV_OVERV_ENABLED_FALSE;


      //Check whether to enable WOV Undervolting. WOV can
      //only be enabled if VDMs are enabled
      if (!is_wov_underv_enabled() ||
          !is_vdm_enabled())
      {
          FAPI_DBG("UNDERV_DISABLED")
          iv_wov_underv_enabled = false;
      }

      //Check whether to enable WOV Overvolting. WOV can
      //only be enabled if VDMs are enabled
      if (!is_wov_overv_enabled() || 
          !is_vdm_enabled())
      {
          FAPI_DBG("OVERV_DISABLED")
          iv_wov_overv_enabled = false;
      }

    if (iv_pstates_enabled)
    {
        l_ps_enabled = (fapi2::ATTR_PSTATES_ENABLED_Type)fapi2::ENUM_ATTR_PSTATES_ENABLED_TRUE;
    }

    if (iv_resclk_enabled)
    {
        l_resclk_enabled = (fapi2::ATTR_RESCLK_ENABLED_Type)fapi2::ENUM_ATTR_RESCLK_ENABLED_TRUE;
    }

    if (iv_vdm_enabled)
    {
        l_vdm_enabled = (fapi2::ATTR_VDM_ENABLED_Type)fapi2::ENUM_ATTR_VDM_ENABLED_TRUE;
    }

    if (iv_ivrm_enabled)
    {
        l_ivrm_enabled = (fapi2::ATTR_IVRM_ENABLED_Type)fapi2::ENUM_ATTR_IVRM_ENABLED_TRUE;
    }

    if (iv_wof_enabled)
    {
        l_wof_enabled = (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_TRUE;
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
    SET_ATTR(fapi2::ATTR_VDM_ENABLED, iv_procChip, l_vdm_enabled);
    SET_ATTR(fapi2::ATTR_IVRM_ENABLED, iv_procChip, l_ivrm_enabled);
    SET_ATTR(fapi2::ATTR_WOF_ENABLED, iv_procChip, l_wof_enabled);
    SET_ATTR(fapi2::ATTR_WOV_UNDERV_ENABLED, iv_procChip, l_wov_underv_enabled);
    SET_ATTR(fapi2::ATTR_WOV_OVERV_ENABLED, iv_procChip, l_wov_overv_enabled);


fapi_try_exit:
    return fapi2::current_err;
} //end of set_global_feature_attributes

///////////////////////////////////////////////////////////
////////   oppb_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::oppb_init(
                             OCCPstateParmBlock *i_occppb )
{
    FAPI_INF(">>>>>>>> oppb_init");
    do
    {
        // -----------------------------------------------
        // OCC parameter block
        // -----------------------------------------------
        i_occppb->magic = revle64(OCC_PARMSBLOCK_MAGIC);

        i_occppb->wof.wof_enabled = iv_wof_enabled;
        i_occppb->vdd_sysparm     = iv_vdd_sysparam;
        i_occppb->vcs_sysparm     = iv_vcs_sysparam;
        i_occppb->vdn_sysparm     = iv_vdn_sysparam;

        //load vpd operating points
        for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
        {
            i_occppb->operating_points[i].frequency_mhz  = revle32(iv_biased_vpd_pts[i].frequency_mhz);
            i_occppb->operating_points[i].vdd_mv         = revle32(iv_biased_vpd_pts[i].vdd_mv);
            i_occppb->operating_points[i].idd_100ma      = revle32(iv_biased_vpd_pts[i].idd_100ma);
            i_occppb->operating_points[i].vcs_mv         = revle32(iv_biased_vpd_pts[i].vcs_mv);
            i_occppb->operating_points[i].ics_100ma      = revle32(iv_biased_vpd_pts[i].ics_100ma);
            i_occppb->operating_points[i].pstate            = iv_biased_vpd_pts[i].pstate;
        }


        // frequency_min_khz - Value from Power safe operating point after biases
        Pstate l_ps;

        //Translate safe mode frequency to pstate
        freq2pState((iv_attrs.attr_pm_safe_frequency_mhz * 1000),
                    &l_ps, ROUND_FAST);

        //Compute real frequency
        i_occppb->frequency_min_khz = iv_reference_frequency_khz -
                                     (l_ps * iv_frequency_step_khz);

        i_occppb->frequency_min_khz = revle32(i_occppb->frequency_min_khz);

        // frequency_max_khz - Value from Ultra Turbo operating point after biases
        i_occppb->frequency_max_khz = revle32(iv_reference_frequency_khz);

        // frequency_step_khz
        i_occppb->frequency_step_khz = revle32(iv_frequency_step_khz);

        // Power bus nest freq
        uint16_t l_pbus_nest_freq = revle16(iv_poundV_raw_data.pbFreq);

        FAPI_INF("l_pbus_nest_freq 0x%x (%d)", l_pbus_nest_freq, l_pbus_nest_freq);

        // I- VDN PB current
        uint16_t l_vpd_idn_100ma = revle16(iv_poundV_raw_data.IdnPbCurr);
        FAPI_INF("l_vpd_idn_100ma 0x%x (%d)", l_vpd_idn_100ma, l_vpd_idn_100ma);

        if (is_wof_enabled())
        {
            // Iddq Table
            i_occppb->iddq = iv_iddqt;

            i_occppb->wof.tdp_rdp_factor = (iv_attrs.attr_tdp_rdp_current_factor);
            FAPI_INF("l_occppb.wof.tdp_rdp_factor 0x%x", revle32(i_occppb->wof.tdp_rdp_factor));

            // nest leakage percent
            i_occppb->nest_leakage_percent = iv_attrs.attr_nest_leakage_percent;
            FAPI_INF("l_occppb.nest_leakage_percent 0x%x", i_occppb->nest_leakage_percent);

            i_occppb->lac_tdp_vdd_turbo_10ma =
                    revle16(iv_poundW_data.poundw[TURBO].ivdd_tdp_ac_current_10ma);
            i_occppb->lac_tdp_vdd_nominal_10ma =
                    revle16(iv_poundW_data.poundw[NOMINAL].ivdd_tdp_ac_current_10ma);
            FAPI_INF("l_occppb.lac_tdp_vdd_turbo_10ma 0x%x (%d)",
                    i_occppb->lac_tdp_vdd_turbo_10ma, i_occppb->lac_tdp_vdd_turbo_10ma);
            FAPI_INF("l_occppb.lac_tdp_vdd_nominal_10ma 0x%x (%d)",
                    i_occppb->lac_tdp_vdd_nominal_10ma, i_occppb->lac_tdp_vdd_nominal_10ma);

            // As the Vdn dimension is not supported in the WOF tables,
            // hardcoding this value to the OCC as non-zero to keep it
            // happy.
            i_occppb->ceff_tdp_vdn = 1;
            FAPI_INF(" l_occppb.ceff_tdp_vdn 0x%x (note: the Vdn dimension is not supported; this value is forced)",
                        i_occppb->ceff_tdp_vdn);

        }
        else
        {
            iv_wof_enabled = false;
        }

        //Update nest frequency in OPPB
        i_occppb->nest_frequency_mhz = revle32(iv_nest_freq_mhz);

        // The minimum Pstate must be rounded FAST so that core floor
        // constraints are not violated.
        Pstate pstate_min;
        int rc = freq2pState(revle32(i_occppb->frequency_min_khz),
                             &pstate_min,
                             ROUND_FAST);

        switch (rc)
        {
            case -PSTATE_LT_PSTATE_MIN:
                FAPI_INF("OCC Minimum Frequency was clipped to Pstate 0");
                break;

            case -PSTATE_GT_PSTATE_MAX:
                FAPI_INF("OCC Minimum Frequency %d KHz is outside the range that can be represented"
                         " by a Pstate with a base frequency of %d KHz and step size %d KHz",
                         revle32(i_occppb->frequency_min_khz),
                         (iv_reference_frequency_khz),
                         (iv_frequency_step_khz));
                FAPI_INF("Pstate is set to %X (%d)", pstate_min);
                break;
        }

        i_occppb->pstate_min = revle32(pstate_min);
        FAPI_INF("l_occppb.pstate_min 0x%x (%u)", pstate_min, pstate_min);


    }while(0);

    FAPI_INF("<<<<<<<< oppb_init");
    return fapi2::current_err;
} //end of oppb_init


///////////////////////////////////////////////////////////
////////   lppb_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::lppb_init(
                             LocalPstateParmBlock *i_localppb)
{
    FAPI_INF(">>>>>>>> lppb_init");
    do
    {
        uint8_t l_eqPos     =   0;
        auto  l_eqChiplets  =   iv_procChip.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);
        LocalPstateParmBlock *l_pLocalPspbTemp  =   NULL;

        for( auto eq : l_eqChiplets )
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, eq, l_eqPos ));
            l_pLocalPspbTemp    =   i_localppb + l_eqPos;

            // -----------------------------------------------
            // Local parameter block
            // -----------------------------------------------
            l_pLocalPspbTemp->magic = revle64(LOCAL_PARMSBLOCK_MAGIC);

            // VpdBias External and Internal Biases for Global and Local parameter
            // block
            for (uint8_t i = 0; i < NUM_OP_POINTS; i++)
            {
                l_pLocalPspbTemp->ext_biases[i] = iv_bias[i];
                l_pLocalPspbTemp->int_biases[i] = iv_bias[i];
            }

            //load vpd operating points
            for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
            {
                l_pLocalPspbTemp->operating_points[i].frequency_mhz  = revle32(iv_biased_vpd_pts[i].frequency_mhz);
                l_pLocalPspbTemp->operating_points[i].vdd_mv         = revle32(iv_biased_vpd_pts[i].vdd_mv);
                l_pLocalPspbTemp->operating_points[i].idd_100ma      = revle32(iv_biased_vpd_pts[i].idd_100ma);
                l_pLocalPspbTemp->operating_points[i].vcs_mv         = revle32(iv_biased_vpd_pts[i].vcs_mv);
                l_pLocalPspbTemp->operating_points[i].ics_100ma      = revle32(iv_biased_vpd_pts[i].ics_100ma);
                l_pLocalPspbTemp->operating_points[i].pstate         = iv_biased_vpd_pts[i].pstate;
            }

            l_pLocalPspbTemp->vdd_sysparm = iv_vdd_sysparam;

            // IvrmParmBlock
            l_pLocalPspbTemp->ivrm = iv_ivrmpb;

            // VDMParmBlock
            memset (&(l_pLocalPspbTemp->vdm), 0, sizeof(l_pLocalPspbTemp->vdm));

            l_pLocalPspbTemp->dpll_pstate0_value =
                    ((iv_reference_frequency_khz)  /
                            (iv_frequency_step_khz));
            l_pLocalPspbTemp->dpll_pstate0_value = revle32(l_pLocalPspbTemp->dpll_pstate0_value);

            FAPI_INF("l_localppb.dpll_pstate0_value  %X (%d)",
                    revle32(l_pLocalPspbTemp->dpll_pstate0_value),
                    revle32(l_pLocalPspbTemp->dpll_pstate0_value));

            l_pLocalPspbTemp->resclk = iv_resclk_setup;

            if (iv_attrs.attr_system_vdm_disable == fapi2::ENUM_ATTR_SYSTEM_VDM_DISABLE_OFF)
            {

               //Initializing threshold and jump values for LPPB
               memcpy ( l_pLocalPspbTemp->vid_point_set,
                        iv_vid_point_set,
                        sizeof(l_pLocalPspbTemp->vid_point_set));

               memcpy ( l_pLocalPspbTemp->threshold_set,
                        iv_threshold_set,
                        sizeof(l_pLocalPspbTemp->threshold_set));

               memcpy ( l_pLocalPspbTemp->jump_value_set,
                        iv_jump_value_set,
                        sizeof(l_pLocalPspbTemp->jump_value_set));

               memcpy ( l_pLocalPspbTemp->PsVIDCompSlopes,
                        iv_PsVIDCompSlopes,
                        sizeof(l_pLocalPspbTemp->PsVIDCompSlopes));

               memcpy ( l_pLocalPspbTemp->PsVDMThreshSlopes,
                        iv_PsVDMThreshSlopes,
                        sizeof(l_pLocalPspbTemp->PsVDMThreshSlopes));

               memcpy ( l_pLocalPspbTemp->PsVDMJumpSlopes,
                        iv_PsVDMJumpSlopes,
                        sizeof(l_pLocalPspbTemp->PsVDMJumpSlopes));
            }

        }// for eq
    }while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<< lppb_init");
    return fapi2::current_err;

} //end of lppb_init


///////////////////////////////////////////////////////////
////////   gppb_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::gppb_init(
                             GlobalPstateParmBlock *io_globalppb)
{
    FAPI_INF(">>>>>>>> gppb_init");
    do
    {
        // Needs to be Endianness corrected going into the block

        io_globalppb->magic = revle64(PSTATE_PARMSBLOCK_MAGIC);

        io_globalppb->options.options = 0;   // until options get defined.

        io_globalppb->reference_frequency_khz = revle32(iv_reference_frequency_khz);

        io_globalppb->nest_frequency_mhz = revle32(iv_nest_freq_mhz);

        io_globalppb->frequency_step_khz = revle32(iv_frequency_step_khz);

        FAPI_INF("Pstate Base Frequency %X (%d)",
                revle32(io_globalppb->reference_frequency_khz),
                revle32(io_globalppb->reference_frequency_khz));

        // VpdBias External and Internal Biases for Global and Local parameter
        // block
        for (uint8_t i = 0; i < NUM_OP_POINTS; i++)
        {
            io_globalppb->ext_biases[i] = iv_bias[i];
            io_globalppb->int_biases[i] = iv_bias[i];
        }

        io_globalppb->vdd_sysparm = iv_vdd_sysparam;
        io_globalppb->vcs_sysparm = iv_vcs_sysparam;
        io_globalppb->vdn_sysparm = iv_vdn_sysparam;

        // External VRM parameters
        io_globalppb->ext_vrm_transition_start_ns =
           revle32(iv_attrs.attr_ext_vrm_transition_start_ns);
        io_globalppb->ext_vrm_transition_rate_inc_uv_per_us =
           revle32(iv_attrs.attr_ext_vrm_transition_rate_inc_uv_per_us);
        io_globalppb->ext_vrm_transition_rate_dec_uv_per_us =
           revle32(iv_attrs.attr_ext_vrm_transition_rate_dec_uv_per_us);
        io_globalppb->ext_vrm_stabilization_time_us =
           revle32(iv_attrs.attr_ext_vrm_stabilization_time_us);
        io_globalppb->ext_vrm_step_size_mv =
           revle32(iv_attrs.attr_ext_vrm_step_size_mv);



        // safe_voltage_mv
        io_globalppb->safe_voltage_mv = revle32(iv_attrs.attr_pm_safe_voltage_mv);

        // safe_frequency_khz
        io_globalppb->safe_frequency_khz =
            iv_attrs.attr_pm_safe_frequency_mhz * 1000;
        io_globalppb->safe_frequency_khz = revle32(io_globalppb->safe_frequency_khz);
        FAPI_INF("Safe Mode Frequency %d (0x%X) kHz;  Voltage %d (0x%X) mV",
                revle32(io_globalppb->safe_frequency_khz),
                revle32(io_globalppb->safe_frequency_khz),
                revle32(io_globalppb->safe_voltage_mv),
                revle32(io_globalppb->safe_voltage_mv));

        io_globalppb->vdm = iv_vdmpb;

        // IvrmParmBlock
        io_globalppb->ivrm = iv_ivrmpb;

        //load vpd operating points
        for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
        {
            io_globalppb->operating_points[i].frequency_mhz  = revle32(iv_biased_vpd_pts[i].frequency_mhz);
            io_globalppb->operating_points[i].vdd_mv         = revle32(iv_biased_vpd_pts[i].vdd_mv);
            io_globalppb->operating_points[i].idd_100ma      = revle32(iv_biased_vpd_pts[i].idd_100ma);
            io_globalppb->operating_points[i].vcs_mv         = revle32(iv_biased_vpd_pts[i].vcs_mv);
            io_globalppb->operating_points[i].ics_100ma      = revle32(iv_biased_vpd_pts[i].ics_100ma);
            io_globalppb->operating_points[i].pstate            = iv_biased_vpd_pts[i].pstate;
        }

        // Initialize res clk data

        io_globalppb->resclk = iv_resclk_setup;

        // -----------------------------------------------
        // populate VpdOperatingPoint with biased MVPD attributes
        // -----------------------------------------------
        for (uint8_t i = 0; i < NUM_VPD_PTS_SET; i++)
        {
            for (uint8_t j = 0; j < NUM_OP_POINTS; j++)
            {
                io_globalppb->operating_points_set[i][j].frequency_mhz =  revle32(iv_operating_points[i][j].frequency_mhz);
                io_globalppb->operating_points_set[i][j].vdd_mv =  revle32(iv_operating_points[i][j].vdd_mv);
                io_globalppb->operating_points_set[i][j].idd_100ma =  revle32(iv_operating_points[i][j].idd_100ma);
                io_globalppb->operating_points_set[i][j].vcs_mv =  revle32(iv_operating_points[i][j].vcs_mv);
                io_globalppb->operating_points_set[i][j].ics_100ma =  revle32(iv_operating_points[i][j].ics_100ma);
                io_globalppb->operating_points_set[i][j].pstate =  iv_operating_points[i][j].pstate;
            }
        }

        // Calculate pre-calculated slopes
        compute_PStateV_slope(io_globalppb);
        FAPI_INF("Finished compute_PStateV_slope");

        io_globalppb->dpll_pstate0_value =
            revle32(revle32(io_globalppb->reference_frequency_khz)  /
                    revle32(io_globalppb->frequency_step_khz));

        FAPI_INF("l_globalppb.dpll_pstate0_value %X (%d)",
                revle32(io_globalppb->dpll_pstate0_value),
                revle32(io_globalppb->dpll_pstate0_value));

        if (iv_attrs.attr_system_vdm_disable == fapi2::ENUM_ATTR_SYSTEM_VDM_DISABLE_OFF)
        {
            //Initializing threshold and jump values for GPPB
            for (uint8_t p = 0; p < NUM_OP_POINTS; p++) {
                io_globalppb->vid_point_set[p] = iv_vid_point_set[0][p];
            }

            memcpy ( io_globalppb->threshold_set,
                    iv_threshold_set,
                    sizeof(io_globalppb->threshold_set));

            memcpy ( io_globalppb->jump_value_set,
                    iv_jump_value_set,
                    sizeof(io_globalppb->jump_value_set));

            for (uint32_t r = 0; r < VPD_NUM_SLOPES_REGION; r++) {
                io_globalppb->PsVIDCompSlopes[r] = iv_PsVIDCompSlopes[0][r];
            }

            memcpy ( io_globalppb->PsVDMThreshSlopes,
                    iv_PsVDMThreshSlopes,
                    sizeof(io_globalppb->PsVDMThreshSlopes));

            memcpy ( io_globalppb->PsVDMJumpSlopes,
                    iv_PsVDMJumpSlopes,
                    sizeof(io_globalppb->PsVDMJumpSlopes));

            // Put the good_normal_cores value into the GPPB for PGPE
            // This is done as a union overlay so that the inter-platform headers
            // are not touched.
            GPPBOptionsPadUse pad;

            pad.fields.good_cores_in_sort = iv_iddqt.good_normal_cores_per_sort;
            io_globalppb->options.pad = pad.value;
            // Note:  the following is presently accurate as the first 3 bytes
            // are reserved.
            FAPI_INF("good normal cores per sort %d 0x%X",
                    revle32(io_globalppb->options.pad),
                    revle32(io_globalppb->options.pad));

        }

        //WOV parameters
        io_globalppb->wov_sample_125us                = revle32(iv_attrs.attr_wov_sample_125us);
        io_globalppb->wov_max_droop_pct               = revle32(iv_attrs.attr_wov_max_droop_pct);
        io_globalppb->wov_underv_perf_loss_thresh_pct = iv_attrs.attr_wov_underv_perf_loss_thresh_pct;
        io_globalppb->wov_underv_step_incr_pct        = iv_attrs.attr_wov_underv_step_incr_pct;
        io_globalppb->wov_underv_step_decr_pct        = iv_attrs.attr_wov_underv_step_decr_pct;
        io_globalppb->wov_underv_max_pct              = iv_attrs.attr_wov_underv_max_pct;
        io_globalppb->wov_underv_vmin_mv              = revle16(iv_attrs.attr_wov_underv_vmin_mv);
        io_globalppb->wov_overv_vmax_mv               = revle16(iv_attrs.attr_wov_overv_vmax_mv);
        io_globalppb->wov_overv_step_incr_pct         = iv_attrs.attr_wov_overv_step_incr_pct;
        io_globalppb->wov_overv_step_decr_pct         = iv_attrs.attr_wov_overv_step_decr_pct;
        io_globalppb->wov_overv_max_pct               = iv_attrs.attr_wov_overv_max_pct;

        if (io_globalppb->wov_underv_vmin_mv == 0)
        {
            io_globalppb->wov_underv_vmin_mv = revle16(uint16_t(revle32(io_globalppb->safe_voltage_mv)));
            FAPI_INF("WOV_VMIN_MV=%u",revle16(io_globalppb->wov_underv_vmin_mv));
            FAPI_INF("SafeVoltage=%u",revle32(io_globalppb->safe_voltage_mv));
        }

        //Avs Bus topplogy
        io_globalppb->avs_bus_topology.vdd_avsbus_num  = iv_attrs.vdd_bus_num;
        io_globalppb->avs_bus_topology.vdd_avsbus_rail = iv_attrs.vdd_rail_select;
        io_globalppb->avs_bus_topology.vdn_avsbus_num  = iv_attrs.vdn_bus_num;
        io_globalppb->avs_bus_topology.vdn_avsbus_rail = iv_attrs.vdn_rail_select;
        io_globalppb->avs_bus_topology.vcs_avsbus_num  = iv_attrs.vcs_bus_num;
        io_globalppb->avs_bus_topology.vcs_avsbus_rail = iv_attrs.vcs_rail_select;

    } while (0);

    FAPI_INF("<<<<<<<<<< gppb_init");
    return fapi2::current_err;
} //end of gppb_init


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
///////////////////////////////////////////////////////////
////////  compute_PStateV_slope
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_PStateV_slope(
                GlobalPstateParmBlock* o_gppb)
{
    for(auto pt_set = 0; pt_set < NUM_VPD_PTS_SET; ++pt_set)
    {

        // ULTRA TURBO pstate check is not required..because it's pstate will be
        // 0
        if (!(iv_operating_points[pt_set][POWERSAVE].pstate) ||
            !(iv_operating_points[pt_set][NOMINAL].pstate) ||
            !(iv_operating_points[pt_set][TURBO].pstate))
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
                    compute_slope_4_12((iv_operating_points[pt_set][region + 1].vdd_mv),
                                       (iv_operating_points[pt_set][region].vdd_mv),
                                       iv_operating_points[pt_set][region].pstate,
                                       iv_operating_points[pt_set][region + 1].pstate)
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
                    compute_slope_4_12(iv_operating_points[pt_set][region].pstate,
                                       iv_operating_points[pt_set][region + 1].pstate,
                                       (iv_operating_points[pt_set][region + 1].vdd_mv),
                                       (iv_operating_points[pt_set][region].vdd_mv))
                );

            FAPI_DBG("VPStateSlopes[%s][%s] 0x%04x %d", vpdSetStr[pt_set], region_names[region],
                     revle16(o_gppb->VPStateSlopes[pt_set][region]),
                     revle16(o_gppb->VPStateSlopes[pt_set][region]));
        }
    }
}


///////////////////////////////////////////////////////////
////////  wof_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::wof_init(
                             uint8_t* o_buf,
                             uint32_t& io_size)
{
    FAPI_DBG(">> WOF initialization");

    fapi2::ReturnCode l_rc = 0;
    uint16_t l_vdd_size = 0;
    uint16_t l_vdn_size = 0;

    //this structure has VFRT header + data
    HomerVFRTLayout_t l_vfrt;
    memset (&l_vfrt, 0, sizeof(l_vfrt));
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

        FAPI_DBG("l_wof_table_data  addr = %p size = %d",
                l_wof_table_data, sizeof(fapi2::ATTR_WOF_TABLE_DATA_Type));


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
            l_vdn_size = revle16(p_wfth->vdn_size);
            l_vdd_size = revle16(p_wfth->vdd_size);

            if (l_sys_vfrt_static_data == fapi2::ENUM_ATTR_SYS_VFRT_STATIC_DATA_ENABLE_VDN_STEP_OFF)
            {
                l_vdn_size = 1;
            }

            FAPI_INF("STATIC WOF: l_vdn_size %04x, l_vdd_size %04x",l_vdn_size,l_vdd_size);
            memcpy(&l_vfrt, &g_sysvfrtData, sizeof (g_sysvfrtData));

            for (uint32_t vdn = 0; vdn < l_vdn_size; ++vdn)
            {
                // This creates a VDN percentage value can that can test the trace
                // filtering.
                l_vfrt.vfrtHeader.res_vdnId = (vdn+1)*VDN_PERCENT_KEY;
                for (uint32_t vdd = 0; vdd < l_vdd_size; ++vdd)
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
                iv_wof_enabled = false;

                // Write the returned error content to the error log
                fapi2::logError(l_rc,fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
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
            iv_wof_enabled = false;
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

        l_vdn_size = revle16(p_wfth->vdn_size) ? revle16(p_wfth->vdn_size) : 1;
        l_vdd_size = revle16(p_wfth->vdd_size) ? revle16(p_wfth->vdd_size) : 1;

        FAPI_INF("WOF: l_vdn_size %04x, l_vdd_size %04x",l_vdn_size,l_vdd_size);

        // Convert system vfrt to homer vfrt
        for (auto vfrt_index = 0;
                vfrt_index < (l_vdn_size * l_vdd_size * ACTIVE_QUADS);
                ++vfrt_index)
        {

            l_rc = update_vfrt (
                    ((*l_wof_table_data) + l_wof_table_index),
                    &l_vfrt
                    );
            if (l_rc)
            {
                iv_wof_enabled = false;
                FAPI_TRY(l_rc);  // Exit the function as a fail
            }

            // Check for "VT" at the start of the magic number
            if (revle16(l_vfrt.vfrtHeader.magic_number) != 0x5654)
            {
                iv_wof_enabled = false;
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

    // This is for the case that the magic number didn't match and we don't
    // want to fail;  rather, we just disable WOF.
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    if (l_wof_table_data)
    {
       delete l_wof_table_data;
    }

    FAPI_DBG("<< WOF initialization");
    return fapi2::current_err;
} //end of wof_init


///////////////////////////////////////////////////////////
//////// update_vfrt
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::update_vfrt(
                             uint8_t* i_pBuffer,
                             HomerVFRTLayout_t* o_vfrt_data)
{
    uint32_t l_index_0 = 0;
    uint32_t l_index_1 = 0;
    uint8_t  l_type = 0;
    uint32_t l_freq_khz = 0;
    uint32_t l_step_freq_khz;
    Pstate   l_ps;

    l_step_freq_khz = (iv_frequency_step_khz);
    FAPI_DBG("l_step_freq_khz = 0x%X (%d)", l_step_freq_khz, l_step_freq_khz);

#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))
    //Initialize VFRT header
    o_vfrt_data->vfrtHeader.magic_number = revle16(UINT16_GET(i_pBuffer));
    i_pBuffer += 2;
    o_vfrt_data->vfrtHeader.reserved     = revle16(UINT16_GET(i_pBuffer));
    i_pBuffer += 2;
    o_vfrt_data->vfrtHeader.type_version = *i_pBuffer;
    i_pBuffer++;
    o_vfrt_data->vfrtHeader.res_vdnId    = *i_pBuffer;  // Future: this name is not accurate but takes a header change.
    i_pBuffer++;
    o_vfrt_data->vfrtHeader.VddId_QAId   = *i_pBuffer;  // Future: this name is not accurate but takes a header change.
    i_pBuffer++;
    o_vfrt_data->vfrtHeader.rsvd_QAId    = *i_pBuffer;
    i_pBuffer++;


    //find type
    l_type = (o_vfrt_data->vfrtHeader.type_version) >> 4;

    char l_buffer_str[256];   // Temporary formatting string buffer
    char l_line_str[256];     // Formatted output line string

    // Filtering Tracing output to only only QID of 0
    bool b_output_trace = false;
    if (o_vfrt_data->vfrtHeader.rsvd_QAId == QID_KEY &&
        o_vfrt_data->vfrtHeader.res_vdnId <= VDN_PERCENT_KEY)
    {
        b_output_trace = true;
    }
    FAPI_DBG("res_vdnId = %X, VDN_PERCENT_KEY = %X, .rsvd_QAId  = %X, QID_KEY = %X, trace = %u",
            o_vfrt_data->vfrtHeader.res_vdnId, VDN_PERCENT_KEY,
            o_vfrt_data->vfrtHeader.rsvd_QAId, QID_KEY,
            b_output_trace);

    if (b_output_trace)
    {
        strcpy(l_line_str, "VFRT:");
        sprintf(l_buffer_str, " %X Ver/Type %X VDN%% %3d VDD%% %3d QID %d",
                revle16(o_vfrt_data->vfrtHeader.magic_number),
                revle16(o_vfrt_data->vfrtHeader.type_version),
                o_vfrt_data->vfrtHeader.res_vdnId,   /// BUG:  this should be VDN!!!
                o_vfrt_data->vfrtHeader.VddId_QAId,  /// BUG:  this should be VDD!!!
                o_vfrt_data->vfrtHeader.rsvd_QAId);  /// BUG:  this should be resvQID!!!
        strcat(l_line_str, l_buffer_str);
    }

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
    bool b_first_vratio_set = true;

    // Get the frequency biases in place and check that they all match
    double f_freq_bias = 0;
    int freq_bias_value_hp = 0;
    int freq_bias_value_m1_hp = 0;
    bool b_bias_error = false;
    for (auto v = 0; v < NUM_OP_POINTS; ++v)
    {
        freq_bias_value_hp = iv_bias[v].frequency_hp;
        if (v > 0)
        {
            if (freq_bias_value_hp != freq_bias_value_m1_hp)
            {
                b_bias_error = true;
                FAPI_DBG("FATAL Bias mismatch error: v = %d; freq_bias_value_hp = %d; freq_bias_value_m1_hp = %d",
                        v, freq_bias_value_hp, freq_bias_value_m1_hp );
            }
        }

        freq_bias_value_m1_hp = freq_bias_value_hp;

        if (v == ULTRA)
        {
            f_freq_bias = calc_bias(freq_bias_value_hp);
        }
    }

    FAPI_ASSERT(!b_bias_error,
            fapi2::PSTATE_PB_VFRT_BIAS_ERROR()
            .set_CHIP_TARGET(iv_procChip)
            .set_FREQ_BIAS_HP_ULTRATURBO(iv_bias[ULTRA].frequency_hp)
            .set_FREQ_BIAS_HP_TURBO(iv_bias[TURBO].frequency_hp)
            .set_FREQ_BIAS_HP_NOMINAL(iv_bias[NOMINAL].frequency_hp)
            .set_FREQ_BIAS_HP_POWERSAVE(iv_bias[POWERSAVE].frequency_hp)
            .set_UT_FREQ(iv_reference_frequency_khz),
            "Frequency Biases do not match so VFRT biasing cannot occur");

    if (f_freq_bias != 1)
        FAPI_INF("A frequency bias multiplier of %f being applied to all VFRT entries",
                    f_freq_bias);

    //Initialize VFRT data part
    for (l_index_0 = 0; l_index_0 < VFRT_FRATIO_SIZE; ++l_index_0)
    {
        strcpy(l_buffer_str, "");

        for (l_index_1 = 0; l_index_1 < VFRT_VRATIO_SIZE; ++l_index_1)
        {
            // Offset MHz*1000 (khz) + step (khz) * sysvalue
            float l_freq_raw_khz;
            float l_freq_biased_khz;
            l_freq_raw_khz = (float)(1000 * 1000 + (l_step_freq_khz * (*i_pBuffer)));

            l_freq_biased_khz = l_freq_raw_khz * f_freq_bias;

            // Round to nearest MHz as that is how the system tables are generated
            float l_freq_raw_up_mhz = (l_freq_biased_khz + 500)/1000;
            float l_freq_raw_dn_mhz = (l_freq_biased_khz)/1000;
            float l_freq_rounded_khz;
            if (l_freq_raw_up_mhz >= l_freq_raw_dn_mhz)
                l_freq_rounded_khz = (uint32_t)(l_freq_raw_up_mhz * 1000);
            else
                l_freq_rounded_khz = (uint32_t)(l_freq_raw_dn_mhz * 1000);

            l_freq_khz = (uint32_t)(l_freq_rounded_khz);

            FAPI_DBG("freq_raw_khz  = %f; freq_biased_khz = %f; freq_rounded = 0x%X (%d); sysvalue = 0x%X (%d)",
                        l_freq_raw_khz,
                        l_freq_biased_khz,
                        l_freq_khz, l_freq_khz,
                        *i_pBuffer, *i_pBuffer);

            // Translate to Pstate.  The called function will clip to the
            // legal range.  The rc is only interesting if we care that
            // the pstate was clipped;  in this case, we don't.
            freq2pState(l_freq_khz, &l_ps);

            o_vfrt_data->vfrt_data[l_index_0][l_index_1] = l_ps;

            if (b_first_vratio_set && l_index_1 >= 20 && b_output_trace)
            {
               sprintf(l_buffer_str, "[%2d][%2d] 0x%2X %4d; ",
                       l_index_0, l_index_1,
                       l_ps,  l_freq_khz / 1000);
               strcat(l_line_str, l_buffer_str);
            }

            // Trace the last 8 values of the 24 for debug. As this is
            // in a loop that is processing over 1000 tables, the last
            // 8 gives a view that can correlate that the input data read
            // is correct without overfilling the HB trace buffer.
            if (l_index_1+1 == VFRT_VRATIO_SIZE && b_first_vratio_set && b_fratio_set && b_output_trace)
            {
                FAPI_INF("%s ", l_line_str);
                strcpy(l_buffer_str, "");
                strcpy(l_line_str, "    ");
                b_first_vratio_set = false;
            }

            i_pBuffer++;
        }

        // If fratio is not enabled, don't trace the remaining, duplicate entries.
        if (!l_enable_fratio)
        {
            b_fratio_set = false;
            b_first_vratio_set = false;
        }
        else
        {
            b_fratio_set = true;
            b_first_vratio_set = true;
        }

    }

    // Flip the type from System (0) to HOMER (1)
    l_type = 1;
    o_vfrt_data->vfrtHeader.type_version |=  l_type << 4;

fapi_try_exit:
    return fapi2::current_err;
} // end of update_vfrt


///////////////////////////////////////////////////////////
////////  safe_mode_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::safe_mode_init( void )
{
    FAPI_INF(">>>>>>>>>> safe_mode_init");
    uint8_t l_ps_pstate = 0;
    Safe_mode_parameters l_safe_mode_values;
    uint32_t l_ps_freq_khz =
    iv_operating_points[VPD_PT_SET_BIASED][POWERSAVE].frequency_mhz * 1000;

    do
    {
        if (!iv_attrs.attr_pm_safe_voltage_mv &&
                !iv_attrs.attr_pm_safe_frequency_mhz)
        {
            freq2pState( l_ps_freq_khz, &l_ps_pstate);

            //Compute safe mode values
            FAPI_TRY(safe_mode_computation (
                        l_ps_pstate,
                        &l_safe_mode_values),
                    "Error from safe_mode_computation function");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                        iv_procChip,iv_attrs.attr_pm_safe_frequency_mhz ));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                        iv_procChip, iv_attrs.attr_pm_safe_voltage_mv));

        }
    }while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<<<< safe_mode_init");
    return fapi2::current_err;
} //end of safe_mode_init


///////////////////////////////////////////////////////////
////////  vdm_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::vdm_init( void )
{
    FAPI_INF(">>>>>>>> vdm_init");
    do
    {
        uint8_t l_biased_pstate[NUM_OP_POINTS];
        memset( &iv_vid_point_set[0],   0,  sizeof(iv_vid_point_set) );
        memset(iv_threshold_set,        0,  sizeof(iv_threshold_set));
        memset( &iv_PsVIDCompSlopes[0], 0,  sizeof(iv_PsVIDCompSlopes) );
        memset(iv_PsVDMThreshSlopes,    0,  sizeof(iv_PsVDMThreshSlopes));
        memset(iv_jump_value_set,       0,  sizeof(iv_jump_value_set));
        memset(iv_PsVDMJumpSlopes,      0,  sizeof(iv_PsVDMJumpSlopes));

        for (uint8_t i = 0; i < NUM_OP_POINTS; ++i)
        {
            l_biased_pstate[i] = iv_operating_points[VPD_PT_SET_BIASED][i].pstate;
            FAPI_INF ("l_biased_pstate %d ", l_biased_pstate[i]);
        }

        if (iv_attrs.attr_system_vdm_disable == fapi2::ENUM_ATTR_SYSTEM_VDM_DISABLE_OFF)
        {
            //loop thru the quad list
            FAPI_TRY(compute_vdm_threshold_pts());

            // VID slope calculation
            FAPI_TRY(compute_PsVIDCompSlopes_slopes(l_biased_pstate));

            // VDM threshold slope calculation
            compute_PsVDMThreshSlopes(l_biased_pstate);

            // VDM Jump slope calculation
            compute_PsVDMJumpSlopes (l_biased_pstate);
        }
    }while(0);

    FAPI_INF("<<<<<<<< vdm_init");

fapi_try_exit:
    return fapi2::current_err;
} //end of vdm_init


///////////////////////////////////////////////////////////
////////  compute_PsVDMJumpSlopes
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_PsVDMJumpSlopes(
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
                iv_PsVDMJumpSlopes[region][i] =
                  revle16(
                        compute_slope_thresh(iv_jump_value_set[region + 1][i],
                                             iv_jump_value_set[region][i],
                                             i_pstate[region],
                                             i_pstate[region + 1])
                    );

                FAPI_INF("PsVDMJumpSlopes %s %x N_S %d N_L %d L_S %d S_N %d",
                         prt_region_names[region],
                         revle16(iv_PsVDMJumpSlopes[region][i]),
                         iv_jump_value_set[region+1][i],
                         iv_jump_value_set[region][i],
                         i_pstate[region],
                         i_pstate[region+1]);
            }
        }
    }
    while(0);
} //end of compute_PsVDMJumpSlopes


///////////////////////////////////////////////////////////
////////  compute_PsVDMThreshSlopes
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_PsVDMThreshSlopes(
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
                iv_PsVDMThreshSlopes[region][i] =
                  revle16(
                        compute_slope_thresh(iv_threshold_set[region + 1][i],
                                             iv_threshold_set[region][i],
                                             i_pstate[region],
                                             i_pstate[region+1])
                    );

                FAPI_INF("PsVDMThreshSlopes %s %x TH_N %d TH_P %d PS_P %d PS_N %d",
                         prt_region_names[region],
                         revle16(iv_PsVDMThreshSlopes[region][i]),
                         iv_threshold_set[region+1][i],
                         iv_threshold_set[region][i],
                         i_pstate[region],
                         i_pstate[region+1]);
            }
        }
    }
    while(0);
} //end of compute_PsVDMThreshSlopes


///////////////////////////////////////////////////////////
////////  compute_PsVIDCompSlopes_slopes
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_PsVIDCompSlopes_slopes(
                                       uint8_t* i_pstate)
{
    do
    {
        char const* region_names[] = { "REGION_POWERSAVE_NOMINAL",
                                       "REGION_NOMINAL_TURBO",
                                       "REGION_TURBO_ULTRA"
                                     };
        uint8_t l_eqPos     =   0;
        auto  l_eqChiplets  =   iv_procChip.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

        // ULTRA TURBO pstate check is not required..because its pstate will be
        // 0
        if (!(i_pstate[POWERSAVE]) ||
            !(i_pstate[NOMINAL]) ||
            !(i_pstate[TURBO]))
        {
            FAPI_ERR("Non-UltraTurbo PSTATE value shouldn't be zero");
            break;
        }

        for( auto eq : l_eqChiplets )
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, eq, l_eqPos ));

            for(auto region(REGION_POWERSAVE_NOMINAL); region <= REGION_TURBO_ULTRA; ++region)
            {
                iv_PsVIDCompSlopes[l_eqPos][region] =
                    revle16(
                        compute_slope_4_12( iv_vid_point_set[l_eqPos][region + 1],
                                            iv_vid_point_set[l_eqPos][region],
                                            i_pstate[region],
                                            i_pstate[region + 1])
                    );

                FAPI_DBG( "PsVIDCompSlopes[%s] 0x%04x %d", region_names[region],
                          revle16(iv_PsVIDCompSlopes[l_eqPos][region]),
                          revle16(iv_PsVIDCompSlopes[l_eqPos][region]) );
            }
        }
    }
    while(0);

fapi_try_exit:
return fapi2::current_err;

} // end of compute_PsVIDCompSlopes_slopes


///////////////////////////////////////////////////////////
////////  compute_vdm_threshold_pts
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_vdm_threshold_pts()
{
    int p = 0;
    uint8_t l_eqPos     =   0;
    auto  l_eqChiplets  =   iv_procChip.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

    for( auto eq : l_eqChiplets )
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, eq, l_eqPos ));

        //VID POINTS
        for (p = 0; p < NUM_OP_POINTS; p++)
        {
            iv_vid_point_set[l_eqPos][p] = iv_poundW_data.poundw[p].vdm_vid_compare_per_quad[l_eqPos];
            FAPI_INF("Bi:VID=%x", iv_vid_point_set[l_eqPos][p]);
        }
    }

    // Threshold points
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        // overvolt threshold
        iv_threshold_set[p][VDM_OVERVOLT_INDEX] = g_GreyCodeIndexMapping[(iv_poundW_data.poundw[p].vdm_overvolt_small_thresholds >> 4) & 0x0F];

        FAPI_INF("Bi: OV TSHLD =%d", iv_threshold_set[p][0]);
        // small threshold
        iv_threshold_set[p][VDM_SMALL_INDEX] = (g_GreyCodeIndexMapping[iv_poundW_data.poundw[p].vdm_overvolt_small_thresholds  & 0x0F]);

        FAPI_INF("Bi: SM TSHLD =%d", iv_threshold_set[p][1]);
        // large threshold
        iv_threshold_set[p][VDM_LARGE_INDEX] =  (g_GreyCodeIndexMapping[(iv_poundW_data.poundw[p].vdm_large_extreme_thresholds >> 4) & 0x0F]);

        FAPI_INF("Bi: LG TSHLD =%d", iv_threshold_set[p][2]);
        // extreme threshold
        iv_threshold_set[p][VDM_XTREME_INDEX] =  (g_GreyCodeIndexMapping[iv_poundW_data.poundw[p].vdm_large_extreme_thresholds & 0x0F]);

        FAPI_INF("Bi: EX TSHLD =%d", iv_threshold_set[p][3]);

    }
    // Jump value points
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        // N_L value
        iv_jump_value_set[p][VDM_N_S_INDEX] = (iv_poundW_data.poundw[p].vdm_normal_freq_drop >> 4) & 0x0F;

        FAPI_INF("Bi: N_S =%d", iv_jump_value_set[p][0]);
        // N_S value
        iv_jump_value_set[p][VDM_N_L_INDEX] = iv_poundW_data.poundw[p].vdm_normal_freq_drop & 0x0F;

        FAPI_INF("Bi: N_L =%d", iv_jump_value_set[p][1]);
        // L_S value
        iv_jump_value_set[p][VDM_L_S_INDEX] =  (iv_poundW_data.poundw[p].vdm_normal_freq_return >> 4) & 0x0F;

        FAPI_INF("Bi: L_S =%d", iv_jump_value_set[p][2]);
        // S_L value
        iv_jump_value_set[p][VDM_S_N_INDEX] =  iv_poundW_data.poundw[p].vdm_normal_freq_return & 0x0F;

        FAPI_INF("Bi: S_L =%d", iv_jump_value_set[p][3]);
    }

fapi_try_exit:
return fapi2::current_err;
} //end of compute_vdm_threshold_pts

///////////////////////////////////////////////////////////
////////  ps2v_mv
///////////////////////////////////////////////////////////
uint32_t PlatPmPPB::ps2v_mv(const Pstate i_pstate)
{

    uint32_t region_start, region_end;
    const char* pv_op_str[NUM_OP_POINTS] = PV_OP_ORDER_STR;

    FAPI_DBG("i_pstate = 0x%x, (%d)", i_pstate, i_pstate);

    // Determine the VPD region
    if(i_pstate > iv_operating_points[VPD_PT_SET_BIASED_SYSP][NOMINAL].pstate)
    {
        region_start = POWERSAVE;
        region_end = NOMINAL;
        FAPI_DBG("Region POWERSAVE_NOMINAL detected");
    }
    else if(i_pstate > iv_operating_points[VPD_PT_SET_BIASED_SYSP][TURBO].pstate)
    {
        region_start = NOMINAL;
        region_end = TURBO;
        FAPI_DBG("Region NOMINAL_TURBO detected");
    }
    else
    {
        region_start = TURBO;
        region_end = ULTRA;
        FAPI_DBG("Region TURBO_ULTRA detected");
    }

    uint32_t l_SlopeValue =
        compute_slope_4_12((iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_end].vdd_mv),
                           (iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].vdd_mv),
                           iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].pstate,
                           iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_end].pstate);

    FAPI_INF("l_globalppb.i_operating_points[%s].vdd_mv 0x%-3x (%d)",
        pv_op_str[region_end],
        (iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_end].vdd_mv),
        (iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_end].vdd_mv));
    FAPI_INF("l_globalppb.i_operating_points[%s].vdd_mv 0x%-3x (%d)",
        pv_op_str[region_start],
        (iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].vdd_mv),
        (iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].vdd_mv));
    FAPI_INF("l_globalppb.i_operating_points[%s].pstate 0x%-3x (%d)",
        pv_op_str[region_end],
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_end].pstate,
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_end].pstate);
    FAPI_INF("l_globalppb.i_operating_points[%s].pstate 0x%-3x (%d)",
        pv_op_str[region_start],
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].pstate,
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].pstate);

    FAPI_INF ("l_SlopeValue %x",l_SlopeValue);


    uint32_t x = (l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].pstate));
    uint32_t y = x >> VID_SLOPE_FP_SHIFT_12;

    uint32_t l_vdd =
        (((l_SlopeValue * (-i_pstate + iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].pstate)) >> VID_SLOPE_FP_SHIFT_12)
           + (iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].vdd_mv));

    // Round up
    l_vdd = (l_vdd << 1) + 1;
    l_vdd = l_vdd >> 1;

    FAPI_DBG("i_pstate = %d "
             "i_operating_points[%s].pstate) = %d "
             "i_operating_points[%s].vdd_mv  = %d "
             "VID_SLOPE_FP_SHIFT_12 = %X "
             "x = %x  (%d) y = %x (%d)",
             i_pstate,
             pv_op_str[region_start], iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].pstate,
             pv_op_str[region_start], (iv_operating_points[VPD_PT_SET_BIASED_SYSP][region_start].vdd_mv),
             VID_SLOPE_FP_SHIFT_12,
             x, x,
             y, y);


    FAPI_INF ("l_vdd 0x%x (%d)", l_vdd, l_vdd);

    return l_vdd;
} //end of ps2v_mv


///////////////////////////////////////////////////////////
////////   safe_mode_computation
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::safe_mode_computation(
                                const Pstate i_ps_pstate,
                                Safe_mode_parameters *o_safe_mode_values)
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    Safe_mode_parameters                     l_safe_mode_values;
    fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ_Type l_safe_mode_freq_mhz;
    fapi2::ATTR_SAFE_MODE_VOLTAGE_MV_Type    l_safe_mode_mv;
    fapi2::ATTR_VDD_BOOT_VOLTAGE_Type        l_boot_mv;
    uint32_t                                 l_safe_mode_op_ps2freq_mhz;
    uint32_t                                 l_core_floor_mhz;
    uint32_t                                 l_op_pt;


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR_MHZ,
                           FAPI_SYSTEM,
                           l_core_floor_mhz));

    // Core floor frequency should be less than ultra turbo freq..
    // if not log an error
    if ((l_core_floor_mhz*1000) > iv_reference_frequency_khz)
    {
        FAPI_ERR("Core floor frequency %08x is greater than UltraTurbo frequency %08x",
                  (l_core_floor_mhz*1000), iv_reference_frequency_khz);
        FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_CORE_FLOOR_FREQ_GT_UT_FREQ()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_CORE_FLOOR_FREQ(l_core_floor_mhz*1000)
                    .set_UT_FREQ(iv_reference_frequency_khz),
                    "Core floor freqency is greater than UltraTurbo frequency");
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                           iv_procChip, l_safe_mode_freq_mhz));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                           iv_procChip, l_safe_mode_mv));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDD_BOOT_VOLTAGE,
                           iv_procChip, l_boot_mv));

    FAPI_DBG ("l_safe_mode_freq_mhz 0%08x (%d)",
                l_safe_mode_freq_mhz, l_safe_mode_freq_mhz);
    FAPI_DBG ("l_safe_mode_mv 0%08x (%d)",
                l_safe_mode_mv, l_safe_mode_mv);
    FAPI_DBG ("l_boot_mv 0%08x (%d)",
                l_boot_mv, l_boot_mv);

    FAPI_INF ("core_floor_mhz 0%08x (%d)",
                l_core_floor_mhz,
                l_core_floor_mhz);
    FAPI_INF("operating_point[POWERSAVE].frequency_mhz 0%08x (%d)",
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][POWERSAVE].frequency_mhz),
                (iv_operating_points[VPD_PT_SET_BIASED_SYSP][POWERSAVE].frequency_mhz));
    FAPI_INF ("reference_freq 0%08x (%d)",
                iv_reference_frequency_khz, iv_reference_frequency_khz);
    FAPI_INF ("step_frequency 0%08x (%d)",
                iv_frequency_step_khz, iv_frequency_step_khz);

    l_op_pt = (iv_operating_points[VPD_PT_SET_BIASED_SYSP][POWERSAVE].frequency_mhz);
    // Safe operational frequency is the MAX(core floor, VPD Powersave).
    // PowerSave is the lowest operational frequency that the part was tested at
    if (l_core_floor_mhz > l_op_pt)
    {
        FAPI_INF("Core floor greater that POWERSAVE");
        l_safe_mode_values.safe_op_freq_mhz = l_core_floor_mhz;
    }
    else
    {
        FAPI_INF("Core floor less than or equal to POWERSAVE");
        l_safe_mode_values.safe_op_freq_mhz = l_op_pt;
    }

    FAPI_INF ("safe_mode_values.safe_op_freq_mhz 0%08x (%d)",
                 l_safe_mode_values.safe_op_freq_mhz,
                 l_safe_mode_values.safe_op_freq_mhz);

    // Calculate safe operational pstate.  This must be rounded down to create
    // a faster Pstate than the floor
    l_safe_mode_values.safe_op_ps = ((float)(iv_reference_frequency_khz) -
                                     (float)(l_safe_mode_values.safe_op_freq_mhz * 1000)) /
                                     (float)iv_frequency_step_khz;

    l_safe_mode_op_ps2freq_mhz    = (iv_reference_frequency_khz -
                                    (l_safe_mode_values.safe_op_ps * iv_frequency_step_khz)) / 1000;

    while (l_safe_mode_op_ps2freq_mhz < l_safe_mode_values.safe_op_freq_mhz)
    {
        l_safe_mode_values.safe_op_ps--;

        l_safe_mode_op_ps2freq_mhz =
            (iv_reference_frequency_khz - (l_safe_mode_values.safe_op_ps * iv_frequency_step_khz)) / 1000;
    }

    // Calculate safe jump value for large frequency
    l_safe_mode_values.safe_vdm_jump_value =
            large_jump_interpolate(l_safe_mode_values.safe_op_ps,
                                   i_ps_pstate);
    FAPI_INF ("l_safe_mode_values.safe_vdm_jump_value %x -> %5.2f %%",
                    l_safe_mode_values.safe_vdm_jump_value,
                    ((float)l_safe_mode_values.safe_vdm_jump_value/32)*100);

    // Calculate safe mode frequency - Round up to nearest MHz
    // The uplifted frequency is based on the fact that the DPLL percentage is a
    // "down" value. Hence:
    //     X (uplifted safe) = Y (safe operating) / (1 - droop percentage)
    l_safe_mode_values.safe_mode_freq_mhz = (uint32_t)
        (((float)l_safe_mode_op_ps2freq_mhz * 1000 /
          (1 - (float)l_safe_mode_values.safe_vdm_jump_value/32) + 500) / 1000);

    if (l_safe_mode_freq_mhz)
    {
        l_safe_mode_values.safe_mode_freq_mhz = l_safe_mode_freq_mhz;
        FAPI_INF("Applying override safe mode freq value of %d MHz",
            l_safe_mode_freq_mhz);
    }
    else
    {
        FAPI_INF("Setting safe mode frequency to %d MHz (0x%x) %x",
                    l_safe_mode_values.safe_mode_freq_mhz,
                    l_safe_mode_values.safe_mode_freq_mhz, iv_reference_frequency_khz);
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ, iv_procChip, l_safe_mode_values.safe_mode_freq_mhz));
    }
    FAPI_INF ("l_safe_mode_values.safe_mode_freq_mhz 0x%0x (%d)",
                l_safe_mode_values.safe_mode_freq_mhz,
                l_safe_mode_values.safe_mode_freq_mhz);

    // Safe frequency must be less than ultra turbo freq.
    // if not log an error
    if ((l_safe_mode_values.safe_mode_freq_mhz*1000) > iv_reference_frequency_khz)
    {
        FAPI_ERR("Safe mode frequency %08x is greater than UltraTurbo frequency %08x",
                  (l_safe_mode_values.safe_mode_freq_mhz*1000), iv_reference_frequency_khz);
        FAPI_ASSERT(false,
                    fapi2::PSTATE_PB_SAFE_FREQ_GT_UT_FREQ()
                    .set_CHIP_TARGET(iv_procChip)
                    .set_SAFE_FREQ(l_safe_mode_values.safe_mode_freq_mhz*1000)
                    .set_UT_FREQ(iv_reference_frequency_khz),
                    "Safe mode freqency is greater than UltraTurbo frequency");
    }

    l_safe_mode_values.safe_mode_ps = ((float)(iv_reference_frequency_khz) -
                                       (float)(l_safe_mode_values.safe_mode_freq_mhz * 1000)) /
                                       (float)iv_frequency_step_khz;

    FAPI_INF ("l_safe_mode_values.safe_mode_ps %x (%d)",
                l_safe_mode_values.safe_mode_ps,
                l_safe_mode_values.safe_mode_ps);

    // Calculate safe mode voltage
    // Use the biased with system parms operating points

    l_safe_mode_values.safe_mode_mv = ps2v_mv(l_safe_mode_values.safe_mode_ps);

    if (l_safe_mode_mv)
    {
        l_safe_mode_values.safe_mode_mv = l_safe_mode_mv;
        FAPI_INF("Applying override safe mode voltage value of %d mV",
                l_safe_mode_mv);
    }
    else
    {
        FAPI_INF("Setting safe mode voltage to %d mv (0x%x)",
                    l_safe_mode_values.safe_mode_mv,
                    l_safe_mode_values.safe_mode_mv);
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                               iv_procChip,
                               l_safe_mode_values.safe_mode_mv));
    }

    FAPI_INF ("l_safe_mode_values.safe_mode_mv 0x%x (%d)",
        l_safe_mode_values.safe_mode_mv,
        l_safe_mode_values.safe_mode_mv);

    fapi2::ATTR_SAFE_MODE_NOVDM_UPLIFT_MV_Type l_uplift_mv;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SAFE_MODE_NOVDM_UPLIFT_MV, iv_procChip, l_uplift_mv));

    // Calculate boot mode voltage
    l_safe_mode_values.boot_mode_mv = l_safe_mode_values.safe_mode_mv + l_uplift_mv;

    if (!iv_attrs.vdd_voltage_mv)
    {
        iv_attrs.vdd_voltage_mv = l_safe_mode_values.boot_mode_mv;
    }

    FAPI_INF("l_safe_mode_values.boot_mode_mv 0x%x (%d)",
        l_safe_mode_values.boot_mode_mv,
        l_safe_mode_values.boot_mode_mv);

    memcpy (o_safe_mode_values,&l_safe_mode_values, sizeof(Safe_mode_parameters));

fapi_try_exit:
    return fapi2::current_err;
} // end of safe_mode_computation


///////////////////////////////////////////////////////////
////////  attr_init
///////////////////////////////////////////////////////////
void PlatPmPPB::attr_init( void )
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
    iv_attrs.attr_dpll_bias                 = 0;
    iv_attrs.attr_undervolting              = 0;

    // ---------------------------------------------------------------
    // set ATTR_PROC_DPLL_DIVIDER
    // ---------------------------------------------------------------
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_DPLL_DIVIDER, iv_procChip,
                           iv_attrs.attr_proc_dpll_divider), "fapiGetAttribute of ATTR_PROC_DPLL_DIVIDER failed");

    // If value is 0, set a default
    if (!iv_attrs.attr_proc_dpll_divider)
    {
        FAPI_DBG("ATTR_PROC_DPLL_DIVIDER - setting default to %x", iv_attrs.attr_proc_dpll_divider);
        iv_attrs.attr_proc_dpll_divider = 8;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_DPLL_DIVIDER, iv_procChip,
                               iv_attrs.attr_proc_dpll_divider), "fapiSetAttribute of ATTR_PROC_DPLL_DIVIDER failed");
    }

    FAPI_INF("ATTR_PROC_DPLL_DIVIDER - %x", iv_attrs.attr_proc_dpll_divider);

    // ----------------------------
    // attributes currently defined
    // ----------------------------

#define DATABLOCK_GET_ATTR(attr_name, target, attr_assign) \
FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, iv_attrs.attr_assign),"Attribute read failed"); \
FAPI_INF("%-60s = 0x%08x %d", #attr_name, iv_attrs.attr_assign, iv_attrs.attr_assign);

    // Frequency Bias attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_ULTRATURBO, iv_procChip, attr_freq_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_TURBO,      iv_procChip, attr_freq_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_NOMINAL,    iv_procChip, attr_freq_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_FREQ_BIAS_POWERSAVE,  iv_procChip, attr_freq_bias_powersave);

    // Voltage Bias attributes
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_ULTRATURBO, iv_procChip, attr_voltage_ext_vdd_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_TURBO,      iv_procChip, attr_voltage_ext_vdd_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_NOMINAL,    iv_procChip, attr_voltage_ext_vdd_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDD_BIAS_POWERSAVE,  iv_procChip, attr_voltage_ext_vdd_bias_powersave);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VCS_BIAS,            iv_procChip, attr_voltage_ext_vcs_bias);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_EXT_VDN_BIAS,            iv_procChip, attr_voltage_ext_vdn_bias);

    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_ULTRATURBO, iv_procChip, attr_voltage_int_vdd_bias_ultraturbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_TURBO,      iv_procChip, attr_voltage_int_vdd_bias_turbo);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_NOMINAL,    iv_procChip, attr_voltage_int_vdd_bias_nominal);
    DATABLOCK_GET_ATTR(ATTR_VOLTAGE_INT_VDD_BIAS_POWERSAVE,  iv_procChip, attr_voltage_int_vdd_bias_powersave);

    // Frequency attributes
    DATABLOCK_GET_ATTR(ATTR_FREQ_DPLL_REFCLOCK_KHZ, FAPI_SYSTEM, attr_freq_dpll_refclock_khz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_PB_MHZ,            FAPI_SYSTEM, attr_nest_frequency_mhz);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_CEILING_MHZ,  FAPI_SYSTEM, attr_freq_core_ceiling_mhz);
    DATABLOCK_GET_ATTR(ATTR_SAFE_MODE_FREQUENCY_MHZ,iv_procChip, attr_pm_safe_frequency_mhz);
    DATABLOCK_GET_ATTR(ATTR_SAFE_MODE_VOLTAGE_MV,   iv_procChip, attr_pm_safe_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_FREQ_CORE_FLOOR_MHZ,    FAPI_SYSTEM, attr_freq_core_floor_mhz);

    // Loadline, Distribution loss and Distribution offset attributes
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDD_UOHM, iv_procChip, attr_proc_r_loadline_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDD_UOHM, iv_procChip, attr_proc_r_distloss_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDD_UV,  iv_procChip, attr_proc_vrm_voffset_vdd_uv);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDN_UOHM, iv_procChip, attr_proc_r_loadline_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDN_UOHM, iv_procChip, attr_proc_r_distloss_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDN_UV,  iv_procChip, attr_proc_vrm_voffset_vdn_uv);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VCS_UOHM, iv_procChip, attr_proc_r_loadline_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VCS_UOHM, iv_procChip, attr_proc_r_distloss_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VCS_UV,  iv_procChip, attr_proc_vrm_voffset_vcs_uv);

    // Read IVRM,WOF and DPLL attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_IVRM_DISABLE,   FAPI_SYSTEM, attr_system_ivrm_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOF_DISABLE,    FAPI_SYSTEM, attr_system_wof_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_VDM_DISABLE,    FAPI_SYSTEM, attr_system_vdm_disable);
    DATABLOCK_GET_ATTR(ATTR_DPLL_VDM_RESPONSE,     FAPI_SYSTEM, attr_dpll_vdm_response);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_RESCLK_DISABLE, FAPI_SYSTEM, attr_resclk_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_PSTATES_MODE,   FAPI_SYSTEM, attr_pstate_mode);

    DATABLOCK_GET_ATTR(ATTR_CHIP_EC_FEATURE_WOF_NOT_SUPPORTED, iv_procChip, attr_dd_wof_not_supported);
    DATABLOCK_GET_ATTR(ATTR_CHIP_EC_FEATURE_VDM_NOT_SUPPORTED, iv_procChip, attr_dd_vdm_not_supported);
    DATABLOCK_GET_ATTR(ATTR_TDP_RDP_CURRENT_FACTOR,            iv_procChip, attr_tdp_rdp_current_factor);


    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_START_NS,
                       FAPI_SYSTEM, attr_ext_vrm_transition_start_ns);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_RATE_INC_UV_PER_US,
                       FAPI_SYSTEM, attr_ext_vrm_transition_rate_inc_uv_per_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_RATE_DEC_UV_PER_US,
                       FAPI_SYSTEM, attr_ext_vrm_transition_rate_dec_uv_per_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_TRANSITION_STABILIZATION_TIME_NS,
                       FAPI_SYSTEM, attr_ext_vrm_stabilization_time_us);
    DATABLOCK_GET_ATTR(ATTR_EXTERNAL_VRM_STEPSIZE, FAPI_SYSTEM, attr_ext_vrm_step_size_mv);
    DATABLOCK_GET_ATTR(ATTR_NEST_LEAKAGE_PERCENT,  FAPI_SYSTEM, attr_nest_leakage_percent);

    // AVSBus ... needed by p9_setup_evid
    DATABLOCK_GET_ATTR(ATTR_VDD_AVSBUS_BUSNUM, iv_procChip, vdd_bus_num);
    DATABLOCK_GET_ATTR(ATTR_VDD_AVSBUS_RAIL,   iv_procChip, vdd_rail_select);
    DATABLOCK_GET_ATTR(ATTR_VDN_AVSBUS_BUSNUM, iv_procChip, vdn_bus_num);
    DATABLOCK_GET_ATTR(ATTR_VDN_AVSBUS_RAIL,   iv_procChip, vdn_rail_select);
    DATABLOCK_GET_ATTR(ATTR_VCS_AVSBUS_BUSNUM, iv_procChip, vcs_bus_num);
    DATABLOCK_GET_ATTR(ATTR_VCS_AVSBUS_RAIL,   iv_procChip, vcs_rail_select);
    DATABLOCK_GET_ATTR(ATTR_VCS_BOOT_VOLTAGE,  iv_procChip, vcs_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_VDD_BOOT_VOLTAGE,  iv_procChip, vdd_voltage_mv);
    DATABLOCK_GET_ATTR(ATTR_VDN_BOOT_VOLTAGE,  iv_procChip, vdn_voltage_mv);

    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDD_UOHM, iv_procChip, r_loadline_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDD_UOHM, iv_procChip, r_distloss_vdd_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDD_UV,  iv_procChip, vrm_voffset_vdd_uv );
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VDN_UOHM, iv_procChip, r_loadline_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VDN_UOHM, iv_procChip, r_distloss_vdn_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VDN_UV,  iv_procChip, vrm_voffset_vdn_uv );
    DATABLOCK_GET_ATTR(ATTR_PROC_R_LOADLINE_VCS_UOHM, iv_procChip, r_loadline_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_R_DISTLOSS_VCS_UOHM, iv_procChip, r_distloss_vcs_uohm);
    DATABLOCK_GET_ATTR(ATTR_PROC_VRM_VOFFSET_VCS_UV,  iv_procChip, vrm_voffset_vcs_uv);
    DATABLOCK_GET_ATTR(ATTR_FREQ_DPLL_REFCLOCK_KHZ,   FAPI_SYSTEM, freq_proc_refclock_khz);
    DATABLOCK_GET_ATTR(ATTR_PROC_DPLL_DIVIDER,        iv_procChip, proc_dpll_divider);
    // AVSBus ... needed by p9_setup_evid
    //Get WOV attributes
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOV_OVERV_DISABLE,        FAPI_SYSTEM,attr_wov_overv_disable);
    DATABLOCK_GET_ATTR(ATTR_SYSTEM_WOV_UNDERV_DISABLE,       FAPI_SYSTEM,attr_wov_underv_disable);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_FORCE,               iv_procChip,attr_wov_underv_force);
    DATABLOCK_GET_ATTR(ATTR_WOV_SAMPLE_125US,               iv_procChip,attr_wov_sample_125us);
    DATABLOCK_GET_ATTR(ATTR_WOV_MAX_DROOP_10THPCT,          iv_procChip,attr_wov_max_droop_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_PERF_LOSS_THRESH_10THPCT, iv_procChip,attr_wov_underv_perf_loss_thresh_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_STEP_INCR_10THPCT,   iv_procChip,attr_wov_underv_step_incr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_STEP_DECR_10THPCT,   iv_procChip,attr_wov_underv_step_decr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_MAX_10THPCT,         iv_procChip,attr_wov_underv_max_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_UNDERV_VMIN_MV,             iv_procChip,attr_wov_underv_vmin_mv);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_VMAX_SETPOINT_MV,     iv_procChip,attr_wov_overv_vmax_mv);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_STEP_INCR_10THPCT,    iv_procChip,attr_wov_overv_step_incr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_STEP_DECR_10THPCT,    iv_procChip,attr_wov_overv_step_decr_pct);
    DATABLOCK_GET_ATTR(ATTR_WOV_OVERV_MAX_10THPCT,          iv_procChip,attr_wov_overv_max_pct);



    // Deal with defaults if attributes are not set
#define SET_DEFAULT(_attr_name, _attr_default) \
    if (!(iv_attrs._attr_name)) \
    { \
       iv_attrs._attr_name = _attr_default; \
       FAPI_INF("Setting %-44s = 0x%08x %d (internal default)", \
                #_attr_name, iv_attrs._attr_name, iv_attrs._attr_name); \
    }

    SET_DEFAULT(attr_freq_dpll_refclock_khz, 133333);
    SET_DEFAULT(freq_proc_refclock_khz,      133333); // Future: collapse this out
    SET_DEFAULT(attr_ext_vrm_transition_start_ns, EXT_VRM_TRANSITION_START_NS)
    SET_DEFAULT(attr_ext_vrm_transition_rate_inc_uv_per_us, EXT_VRM_TRANSITION_RATE_INC_UV_PER_US)
    SET_DEFAULT(attr_ext_vrm_transition_rate_dec_uv_per_us, EXT_VRM_TRANSITION_RATE_DEC_UV_PER_US)
    SET_DEFAULT(attr_ext_vrm_stabilization_time_us, EXT_VRM_STABILIZATION_TIME_NS)
    SET_DEFAULT(attr_ext_vrm_step_size_mv, EXT_VRM_STEPSIZE_MV)


    SET_DEFAULT(attr_wov_sample_125us, 2);
    SET_DEFAULT(attr_wov_max_droop_pct, 125);
    SET_DEFAULT(attr_wov_overv_step_incr_pct, 5);
    SET_DEFAULT(attr_wov_overv_step_decr_pct, 5);
    SET_DEFAULT(attr_wov_overv_max_pct, 0);
    SET_DEFAULT(attr_wov_overv_vmax_mv, 1150);
    SET_DEFAULT(attr_wov_underv_step_incr_pct, 5);
    SET_DEFAULT(attr_wov_underv_step_decr_pct, 5);
    SET_DEFAULT(attr_wov_underv_max_pct, 100);
    SET_DEFAULT(attr_wov_underv_perf_loss_thresh_pct, 5);


    //Ensure that the ranges for WOV attributes are honored
    if (iv_attrs.attr_wov_sample_125us < 2) {
        iv_attrs.attr_wov_sample_125us = 2;
    }

    if(iv_attrs.attr_wov_overv_step_incr_pct > 20) {
        iv_attrs.attr_wov_overv_step_incr_pct = 20;
    }

    if(iv_attrs.attr_wov_overv_step_decr_pct > 20) {
        iv_attrs.attr_wov_overv_step_decr_pct = 20;
    }

    if(iv_attrs.attr_wov_overv_max_pct > 100) {
        iv_attrs.attr_wov_overv_max_pct = 100;
    }

    if(iv_attrs.attr_wov_underv_step_incr_pct > 20) {
        iv_attrs.attr_wov_underv_step_incr_pct = 20;
    }

    if(iv_attrs.attr_wov_underv_step_decr_pct > 20) {
        iv_attrs.attr_wov_underv_step_decr_pct = 20;
    }

    if(iv_attrs.attr_wov_underv_max_pct < 10) {
        iv_attrs.attr_wov_underv_step_decr_pct = 10;
    }

    if (iv_attrs.attr_wov_underv_perf_loss_thresh_pct > 20) {
        iv_attrs.attr_wov_underv_perf_loss_thresh_pct = 20;
    }

    // Deal with crital attributes that are not set and that any defaults chosen
    // could well be very wrong
    FAPI_ASSERT(iv_attrs.attr_nest_frequency_mhz,
                fapi2::PSTATE_PB_NEST_FREQ_EQ_ZERO()
                .set_CHIP_TARGET(iv_procChip),
                "ATTR_FREQ_PB_MHZ has a zero value");

    // -----------------------------------------------
    // System power distribution parameters
    // -----------------------------------------------
    // VDD rail
    iv_vdd_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_vdd_uohm);
    iv_vdd_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_vdd_uohm);
    iv_vdd_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_vdd_uv);

    // VCS rail
    iv_vcs_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_vcs_uohm);
    iv_vcs_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_vcs_uohm);
    iv_vcs_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_vcs_uv);

    // VDN rail
    iv_vdn_sysparam.loadline_uohm = revle32(iv_attrs.attr_proc_r_loadline_vdn_uohm);
    iv_vdn_sysparam.distloss_uohm = revle32(iv_attrs.attr_proc_r_distloss_vdn_uohm);
    iv_vdn_sysparam.distoffset_uv = revle32(iv_attrs.attr_proc_vrm_voffset_vdn_uv);

    //TBD
    // -----------------------
    // get VDM Parameters data
    // ----------------------
    if (iv_attrs.attr_system_vdm_disable == fapi2::ENUM_ATTR_SYSTEM_VDM_DISABLE_OFF)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_DROOP_SMALL_OVERRIDE,
                                FAPI_SYSTEM,
                                iv_vdmpb.droop_small_override));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_DROOP_LARGE_OVERRIDE,
                                FAPI_SYSTEM,
                                iv_vdmpb.droop_large_override));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_DROOP_EXTREME_OVERRIDE,
                                FAPI_SYSTEM,
                                iv_vdmpb.droop_extreme_override));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_OVERVOLT_OVERRIDE,
                                FAPI_SYSTEM,
                                iv_vdmpb.overvolt_override));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_FMIN_OVERRIDE_KHZ,
                                FAPI_SYSTEM,
                                iv_vdmpb.fmin_override_khz));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_FMAX_OVERRIDE_KHZ,
                                FAPI_SYSTEM,
                                iv_vdmpb.fmax_override_khz));
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_VDM_VID_COMPARE_OVERRIDE_MV,
                                FAPI_SYSTEM,
                                iv_vdmpb.vid_compare_override_mv));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DPLL_VDM_RESPONSE,
                               FAPI_SYSTEM,
                               iv_vdmpb.vdm_response));
    }
    else
    {
        FAPI_DBG("   VDM is disabled.  Skipping VDM attribute accesses");
    }

    //Set default values
    SET_ATTR(fapi2::ATTR_PSTATES_ENABLED, iv_procChip, iv_pstates_enabled);
    SET_ATTR(fapi2::ATTR_RESCLK_ENABLED,  iv_procChip, iv_resclk_enabled);
    SET_ATTR(fapi2::ATTR_VDM_ENABLED,     iv_procChip, iv_vdm_enabled);
    SET_ATTR(fapi2::ATTR_IVRM_ENABLED,    iv_procChip, iv_ivrm_enabled);
    SET_ATTR(fapi2::ATTR_WOF_ENABLED,     iv_procChip, iv_wof_enabled);
    SET_ATTR(fapi2::ATTR_WOV_UNDERV_ENABLED, iv_procChip, iv_wov_underv_enabled);
    SET_ATTR(fapi2::ATTR_WOV_OVERV_ENABLED, iv_procChip, iv_wov_overv_enabled);

    iv_pstates_enabled = true;
    iv_resclk_enabled  = true;
    iv_vdm_enabled     = true;
    iv_ivrm_enabled    = true;
    iv_wof_enabled     = true;
    iv_wov_underv_enabled = true;
    iv_wov_overv_enabled = true;

    //Calculate nest & frequency_step_khz
    iv_frequency_step_khz = (iv_attrs.attr_freq_dpll_refclock_khz /
                             iv_attrs.attr_proc_dpll_divider);

    iv_nest_freq_mhz      = iv_attrs.attr_nest_frequency_mhz;


fapi_try_exit:
    if (fapi2::current_err)
    {
        FAPI_ASSERT(false,
                fapi2::PSTATE_PB_ATTRIBUTE_ACCESS_ERROR()
                .set_CHIP_TARGET(iv_procChip),
                "Pstate Parameter Block attribute access error");
    }
} //end of attr_init


///////////////////////////////////////////////////////////
////////   compute_vpd_pts
///////////////////////////////////////////////////////////
void PlatPmPPB::compute_vpd_pts()
{
    int p = 0;

    uint32_t l_vdd_loadline_uohm    = revle32(iv_vdd_sysparam.loadline_uohm);
    uint32_t l_vdd_distloss_uohm    = revle32(iv_vdd_sysparam.distloss_uohm);
    uint32_t l_vdd_distoffset_uv    = revle32(iv_vdd_sysparam.distoffset_uv);
    uint32_t l_vcs_loadline_uohm    = revle32(iv_vcs_sysparam.loadline_uohm);
    uint32_t l_vcs_distloss_uohm    = revle32(iv_vcs_sysparam.distloss_uohm);
    uint32_t l_vcs_distoffset_uv    = revle32(iv_vcs_sysparam.distoffset_uv);

    //RAW POINTS. We just copy them as is
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv = iv_raw_vpd_pts[p].vdd_mv;
        iv_operating_points[VPD_PT_SET_RAW][p].vcs_mv = iv_raw_vpd_pts[p].vcs_mv;
        iv_operating_points[VPD_PT_SET_RAW][p].idd_100ma = iv_raw_vpd_pts[p].idd_100ma;
        iv_operating_points[VPD_PT_SET_RAW][p].ics_100ma = iv_raw_vpd_pts[p].ics_100ma;
        iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz = iv_raw_vpd_pts[p].frequency_mhz;
        iv_operating_points[VPD_PT_SET_RAW][p].pstate = iv_raw_vpd_pts[p].pstate;

        FAPI_DBG("GP: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d)",
                    VPD_PT_SET_RAW, p,
                    iv_operating_points[VPD_PT_SET_RAW][p].pstate,
                    (iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_RAW][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_RAW][p].vdd_mv));
    }

    //SYSTEM PARAMS APPLIED POINTS
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        uint32_t l_vdd_mv = (iv_raw_vpd_pts[p].vdd_mv);
        uint32_t l_idd_ma = (iv_raw_vpd_pts[p].idd_100ma * 100);
        uint32_t l_vcs_mv = (iv_raw_vpd_pts[p].vcs_mv);
        uint32_t l_ics_ma = (iv_raw_vpd_pts[p].ics_100ma * 100);

        iv_operating_points[VPD_PT_SET_SYSP][p].vdd_mv =
                  sysparm_uplift(l_vdd_mv,
                                 l_idd_ma,
                                 l_vdd_loadline_uohm,
                                 l_vdd_distloss_uohm,
                                 l_vdd_distoffset_uv);


        iv_operating_points[VPD_PT_SET_SYSP][p].vcs_mv =
                  sysparm_uplift(l_vcs_mv,
                                 l_ics_ma,
                                 l_vcs_loadline_uohm,
                                 l_vcs_distloss_uohm,
                                 l_vcs_distoffset_uv);

        iv_operating_points[VPD_PT_SET_SYSP][p].idd_100ma =
                   iv_raw_vpd_pts[p].idd_100ma;
        iv_operating_points[VPD_PT_SET_SYSP][p].ics_100ma =
                   iv_raw_vpd_pts[p].ics_100ma;
        iv_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz =
                   iv_raw_vpd_pts[p].frequency_mhz;
        iv_operating_points[VPD_PT_SET_SYSP][p].pstate =
                   iv_raw_vpd_pts[p].pstate;

        FAPI_DBG("SP: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d)",
                    VPD_PT_SET_RAW, p,
                    iv_operating_points[VPD_PT_SET_SYSP][p].pstate,
                    (iv_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_SYSP][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_SYSP][p].vdd_mv));
    }

    //BIASED POINTS
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        uint32_t l_frequency_mhz = (iv_raw_vpd_pts[p].frequency_mhz);
        uint32_t l_vdd_mv = (iv_raw_vpd_pts[p].vdd_mv);
        uint32_t l_vcs_mv = (iv_raw_vpd_pts[p].vcs_mv);

        iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv =
                    bias_adjust_mv(l_vdd_mv, iv_bias[p].vdd_ext_hp);

        iv_operating_points[VPD_PT_SET_BIASED][p].vcs_mv =
                    bias_adjust_mv(l_vcs_mv, iv_bias[p].vcs_ext_hp);

        iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz =
                    bias_adjust_mhz(l_frequency_mhz, iv_bias[p].frequency_hp);

        iv_operating_points[VPD_PT_SET_BIASED][p].idd_100ma =
                    iv_biased_vpd_pts[p].idd_100ma;
        iv_operating_points[VPD_PT_SET_BIASED][p].ics_100ma =
                    iv_biased_vpd_pts[p].ics_100ma;
    }

    // As this is memory to memory, Endianess correction is not necessary.
    iv_reference_frequency_khz =
        (iv_operating_points[VPD_PT_SET_BIASED][ULTRA].frequency_mhz) * 1000;

    FAPI_DBG("Reference into GPPB: LE local Freq=%X (%d);  Freq=%X (%d)",
                iv_reference_frequency_khz,
                iv_reference_frequency_khz,
                (iv_reference_frequency_khz),
                (iv_reference_frequency_khz));

    // Now that the ULTRA frequency is known, Pstates can be calculated
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        iv_operating_points[VPD_PT_SET_BIASED][p].pstate =
            ((((iv_operating_points[VPD_PT_SET_BIASED][ULTRA].frequency_mhz) -
               (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz)) * 1000) /
             (iv_frequency_step_khz));

        FAPI_DBG("Bi: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d), UT Freq=%3X (%4d) Step Freq=%5d",
                    VPD_PT_SET_BIASED, p,
                    iv_operating_points[VPD_PT_SET_BIASED][p].pstate,
                    (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_BIASED][ULTRA].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_BIASED][ULTRA].frequency_mhz),
                    (iv_frequency_step_khz));

    }

    //BIASED POINTS and SYSTEM PARMS APPLIED POINTS
    for (p = 0; p < NUM_OP_POINTS; p++)
    {
        uint32_t l_vdd_mv = (iv_operating_points[VPD_PT_SET_BIASED][p].vdd_mv);
        uint32_t l_idd_ma = (iv_operating_points[VPD_PT_SET_BIASED][p].idd_100ma) * 100;
        uint32_t l_vcs_mv = (iv_operating_points[VPD_PT_SET_BIASED][p].vcs_mv);
        uint32_t l_ics_ma = (iv_operating_points[VPD_PT_SET_BIASED][p].ics_100ma) * 100;

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

        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].idd_100ma =
                    iv_operating_points[VPD_PT_SET_BIASED][p].idd_100ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].ics_100ma =
                    iv_operating_points[VPD_PT_SET_BIASED][p].ics_100ma;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].frequency_mhz =
                    iv_operating_points[VPD_PT_SET_BIASED][p].frequency_mhz;
        iv_operating_points[VPD_PT_SET_BIASED_SYSP][p].pstate =
                    iv_operating_points[VPD_PT_SET_BIASED][p].pstate;

        FAPI_DBG("BS: OpPoint=[%d][%d], PS=%3d, Freq=%3X (%4d), Vdd=%3X (%4d)",
                    VPD_PT_SET_BIASED_SYSP, p,
                    iv_operating_points[VPD_PT_SET_SYSP][p].pstate,
                    (iv_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_SYSP][p].frequency_mhz),
                    (iv_operating_points[VPD_PT_SET_SYSP][p].vdd_mv),
                    (iv_operating_points[VPD_PT_SET_SYSP][p].vdd_mv));

    }
} //end of compute_vpd_pts


///////////////////////////////////////////////////////////
////////   resclk_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::resclk_init( void )
{
    memset (&iv_resclk_setup,0,sizeof(iv_resclk_setup));

    if (iv_attrs.attr_resclk_disable == fapi2::ENUM_ATTR_SYSTEM_RESCLK_DISABLE_OFF)
    {
        FAPI_TRY(set_resclk_table_attrs(),"set_resclk_table_attrs failed");

        if (iv_resclk_enabled)
        {
            FAPI_TRY(res_clock_setup( ));
        }

        FAPI_INF("Resonant Clocks are enabled");
    }
    else
    {
        iv_resclk_enabled = false;
        FAPI_INF("Resonant Clocks are disabled.  Skipping setup.");
    }
fapi_try_exit:
    return fapi2::current_err;
} // end of resclk_init


///////////////////////////////////////////////////////////
////////  res_clock_setup
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::res_clock_setup (void)
{
    FAPI_DBG(">> res_clock_setup");
    uint8_t l_resclk_freq_index[RESCLK_FREQ_REGIONS];
    uint16_t l_step_delay_ns;
    uint16_t l_l3_threshold_mv;
    uint16_t l_steparray[RESCLK_STEPS];
    uint16_t l_resclk_freq_regions[RESCLK_FREQ_REGIONS];
    uint32_t l_ultra_turbo_freq_khz = (iv_reference_frequency_khz);

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_SYSTEM_RESCLK_STEP_DELAY,
                            FAPI_SYSTEM,
                            l_step_delay_ns));
    iv_resclk_setup.step_delay_ns = revle16(l_step_delay_ns);

    // Resonant Clocking Frequency and Index arrays
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGIONS, iv_procChip,
                           l_resclk_freq_regions));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGION_INDEX, iv_procChip,
                           l_resclk_freq_index));

    // Convert frequencies to pstates
    for (uint8_t i = 0; i < RESCLK_FREQ_REGIONS; ++i)
    {
        Pstate pstate;
        // Frequencies are given in MHz, convert to KHz
        uint32_t freq_khz = static_cast<uint32_t>((l_resclk_freq_regions[i])) * 1000;
        uint8_t idx = l_resclk_freq_index[i];

        FAPI_INF("l_resclk_freq_regions %d l_resclk_freq_index %d %d %d %d",l_resclk_freq_regions[i],l_resclk_freq_index[i],
        (freq_khz), l_ultra_turbo_freq_khz, iv_reference_frequency_khz);

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

        int rc = freq2pState(freq_khz, &pstate);

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
                         (iv_frequency_step_khz));
                FAPI_INF("Pstate is set to %X (%d)", pstate);
                break;
        }

        iv_resclk_setup.resclk_freq[i] = pstate;
        iv_resclk_setup.resclk_index[i] = idx;

        FAPI_DBG("Resclk: freq = %d kHz; pstate = %d; idx = %d", freq_khz, pstate, idx);
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VALUE, iv_procChip,
                           iv_resclk_setup.l3_steparray));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV, iv_procChip,
                           l_l3_threshold_mv));
    iv_resclk_setup.l3_threshold_mv = revle16(l_l3_threshold_mv);

    // Resonant Clocking Step array
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_VALUE, iv_procChip,
                           l_steparray));

    for (uint8_t i = 0; i < RESCLK_STEPS; i++)
    {
        iv_resclk_setup.steparray[i].value = revle16(l_steparray[i]);
    }

fapi_try_exit:
    FAPI_DBG("<< res_clock_setup");
    return fapi2::current_err;
} // end of res_clock_setup


///////////////////////////////////////////////////////////
////////  set_resclk_table_attrs
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::set_resclk_table_attrs()
{
    uint8_t  l_resclk_freq_index[RESCLK_FREQ_REGIONS];
    uint8_t  l_l3_steparray[RESCLK_L3_STEPS];
    uint16_t l_resclk_freq_regions[RESCLK_FREQ_REGIONS];
    uint16_t l_resclk_value[RESCLK_STEPS];
    uint16_t l_l3_threshold_mv;
    iv_resclk_enabled = true;

    do
    {
        // Perform some basic sanity checks on the header data structures (since
        // the header values are provided by another team)
        FAPI_ASSERT_NOEXIT(
               (p9_resclk_defines::RESCLK_INDEX_VEC.size() == RESCLK_FREQ_REGIONS),
                fapi2::PSTATE_PB_RESCLK_INDEX_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                .set_FREQ_REGIONS(RESCLK_FREQ_REGIONS)
                .set_INDEX_VEC_SIZE(p9_resclk_defines::RESCLK_INDEX_VEC.size()),
                "p9_resclk_defines.h RESCLK_INDEX_VEC.size() mismatch");

        FAPI_ASSERT_NOEXIT(
               (p9_resclk_defines::RESCLK_TABLE_VEC.size() == RESCLK_STEPS),
                fapi2::PSTATE_PB_RESCLK_TABLE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                .set_STEPS(RESCLK_STEPS)
                .set_TABLE_VEC_SIZE(p9_resclk_defines::RESCLK_TABLE_VEC.size()),
                "p9_resclk_defines.h RESCLK_TABLE_VEC.size() mismatch");

        FAPI_ASSERT_NOEXIT(
               (p9_resclk_defines::L3CLK_TABLE_VEC.size() == RESCLK_L3_STEPS),
                fapi2::PSTATE_PB_RESCLK_L3_TABLE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                .set_L3_STEPS(RESCLK_L3_STEPS)
                .set_L3_VEC_SIZE(p9_resclk_defines::L3CLK_TABLE_VEC.size()),
                "p9_resclk_defines.h L3CLK_TABLE_VEC.size() mismatch");
        //FAPI_ASSERT_NOEXIT will log an error with recoverable.. but rc won't be
        //cleared.. So we are initializing again to continue further
        if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
        {
            iv_resclk_enabled = false;
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            break;
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VALUE, iv_procChip,
                               l_l3_steparray));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGIONS, iv_procChip,
                               l_resclk_freq_regions));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGION_INDEX, iv_procChip,
                               l_resclk_freq_index));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_VALUE, iv_procChip,
                               l_resclk_value));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV, iv_procChip,
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
                FAPI_INF("entered resclk_attr init %x", l_resclk_freq_index[i]);
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

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_L3_VALUE, iv_procChip,
                               l_l3_steparray));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGIONS, iv_procChip,
                               l_resclk_freq_regions));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_FREQ_REGION_INDEX, iv_procChip,
                               l_resclk_freq_index));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_VALUE, iv_procChip,
                               l_resclk_value));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SYSTEM_RESCLK_L3_VOLTAGE_THRESHOLD_MV, iv_procChip,
                               l_l3_threshold_mv));
    }while(0);

fapi_try_exit:
    return fapi2::current_err;
} // end of set_resclk_table_attrs


///////////////////////////////////////////////////////////
////////   get_ivrm_parms
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_ivrm_parms ()
{
    FAPI_DBG(">> proc_get_ivrm_parms");

    if (iv_attrs.attr_system_ivrm_disable == fapi2::ENUM_ATTR_SYSTEM_IVRM_DISABLE_OFF)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STRENGTH_LOOKUP, FAPI_SYSTEM,
                               iv_ivrmpb.strength_lookup));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_VIN_MULTIPLIER, FAPI_SYSTEM,
                               iv_ivrmpb.vin_multiplier));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_VIN_MAX_MV, FAPI_SYSTEM,
                               iv_ivrmpb.vin_max_mv));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STEP_DELAY_NS, FAPI_SYSTEM,
                               iv_ivrmpb.step_delay_ns));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_STABILIZATION_DELAY_NS, FAPI_SYSTEM,
                               iv_ivrmpb.stablization_delay_ns));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_DEADZONE_MV, FAPI_SYSTEM,
                               iv_ivrmpb.deadzone_mv));


        // This is presently hardcoded to FALSE until validation code is in
        // place to ensure turning IVRM on is a good thing.  This attribute write is
        // needed to allocate the HWP attribute in Cronus.

        // Indicate that IVRM is good to be enabled (or not)
        FAPI_INF("   NOTE: This level of code is forcing the iVRM to OFF");
        {
            fapi2::ATTR_IVRM_ENABLED_Type l_ivrm_enabled =
                (fapi2::ATTR_IVRM_ENABLED_Type)fapi2::ENUM_ATTR_IVRM_ENABLED_FALSE;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IVRM_ENABLED, iv_procChip, l_ivrm_enabled));
        }
    }
    else
    {
        memset (&iv_ivrmpb,0,sizeof(iv_ivrmpb));
        FAPI_DBG("   IVRM is disabled.  Skipping IVRM attribute accesses");
        iv_ivrm_enabled = false;
    }

fapi_try_exit:
    FAPI_DBG("<< get_ivrm_parms");
    return fapi2::current_err;

} // end of get_ivrm_parms


///////////////////////////////////////////////////////////
////////   chk_valid_poundv
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::chk_valid_poundv(
                      const bool i_biased_state)
{
    const uint8_t   pv_op_order[NUM_OP_POINTS] = VPD_PV_ORDER;
    const char*     pv_op_str[NUM_OP_POINTS] = VPD_PV_ORDER_STR;
    uint8_t         i = 0;
    bool            suspend_ut_check = false;
    uint8_t         l_chiplet_num = iv_procChip.getChipletNumber();

    VpdPoint        l_attr_mvpd_data[5];
    memcpy (l_attr_mvpd_data,iv_attr_mvpd_poundV_raw,sizeof(l_attr_mvpd_data));

    if (i_biased_state)
    {
        memcpy (l_attr_mvpd_data,iv_attr_mvpd_poundV_biased,sizeof(l_attr_mvpd_data));
    }

    FAPI_DBG(">> chk_valid_poundv for %s values", (i_biased_state) ? "biased" : "non-biased" );

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_SYSTEM_POUNDV_VALIDITY_HALT_DISABLE_Type      attr_poundv_validity_halt_disable;
    fapi2::ATTR_CHIP_EC_FEATURE_POUNDV_VALIDATE_DISABLE_Type  attr_poundv_validate_ec_disable;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_POUNDV_VALIDITY_HALT_DISABLE,
                           FAPI_SYSTEM,
                           attr_poundv_validity_halt_disable));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_POUNDV_VALIDATE_DISABLE,
                           iv_procChip,
                           attr_poundv_validate_ec_disable));

    if (attr_poundv_validate_ec_disable)
    {
         iv_pstates_enabled = false;
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
                      (l_attr_mvpd_data[pv_op_order[i]].frequency_mhz),
                      (l_attr_mvpd_data[pv_op_order[i]].vdd_mv),
                      (l_attr_mvpd_data[pv_op_order[i]].idd_100ma),
                      (l_attr_mvpd_data[pv_op_order[i]].vcs_mv),
                      (l_attr_mvpd_data[pv_op_order[i]].ics_100ma));

            if (is_wof_enabled() &&
               (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))
            {
                if (l_attr_mvpd_data[pv_op_order[i]].frequency_mhz == 0 ||
                    l_attr_mvpd_data[pv_op_order[i]].vdd_mv        == 0 ||
                    l_attr_mvpd_data[pv_op_order[i]].idd_100ma     == 0 ||
                    l_attr_mvpd_data[pv_op_order[i]].vcs_mv        == 0 ||
                    l_attr_mvpd_data[pv_op_order[i]].ics_100ma     == 0 )
                {
                    FAPI_INF("**** WARNING: WOF is enabled but zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                             l_chiplet_num, iv_poundV_bucket_id, pv_op_str[pv_op_order[i]]);
                    FAPI_INF("**** WARNING: Disabling WOF and continuing");
                    suspend_ut_check = true;

                    // Set ATTR_WOF_ENABLED so the caller can set header flags
                    iv_wof_enabled = false;

                    // Take out an informational error log and then keep going.
                    if (i_biased_state)
                    {
                        FAPI_ASSERT_NOEXIT(false,
                            fapi2::PSTATE_PB_BIASED_POUNDV_WOF_UT_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                            .set_CHIP_TARGET(iv_procChip)
                            .set_CHIPLET_NUMBER(l_chiplet_num)
                            .set_BUCKET(iv_poundV_bucket_id)
                            .set_FREQUENCY(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                            .set_VDD(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                            .set_IDD(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                            .set_VCS(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                            .set_ICS(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                            "Pstate Parameter Block WOF Biased #V UT error being logged");
                    }
                    else
                    {
                        FAPI_ASSERT_NOEXIT(false,
                            fapi2::PSTATE_PB_POUNDV_WOF_UT_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                            .set_CHIP_TARGET(iv_procChip)
                            .set_CHIPLET_NUMBER(l_chiplet_num)
                            .set_BUCKET(iv_poundV_bucket_id)
                            .set_FREQUENCY(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                            .set_VDD(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                            .set_IDD(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                            .set_VCS(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                            .set_ICS(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                            "Pstate Parameter Block WOF #V UT error being logged");
                    }
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }
            }
            else if ((!is_wof_enabled()) && (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))
            {
                FAPI_INF("**** NOTE: WOF is disabled so the UltraTurbo VPD is not being checked");
                suspend_ut_check = true;
            }
            else
            {
                if (l_attr_mvpd_data[pv_op_order[i]].frequency_mhz == 0 ||
                    l_attr_mvpd_data[pv_op_order[i]].vdd_mv        == 0 ||
                    l_attr_mvpd_data[pv_op_order[i]].idd_100ma     == 0 ||
                    l_attr_mvpd_data[pv_op_order[i]].vcs_mv        == 0 ||
                    l_attr_mvpd_data[pv_op_order[i]].ics_100ma     == 0 )
                {

                    iv_pstates_enabled = false;

                    if (attr_poundv_validity_halt_disable)
                    {
                        FAPI_IMP("**** WARNING : halt on #V validity checking has been disabled and errors were found");
                        FAPI_IMP("**** WARNING : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                                 l_chiplet_num, iv_poundV_bucket_id, pv_op_str[pv_op_order[i]]);
                        FAPI_IMP("**** WARNING : Pstates are not enabled but continuing on.");

                        // Log errors based on biased inputs or not
                        if (i_biased_state)
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                                .set_VDD(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                                .set_IDD(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                                .set_VCS(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                                .set_ICS(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                                "Pstate Parameter Block Biased #V Zero contents error being logged");
                        }
                        else
                        {
                            FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_POUNDV_ZERO_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                                .set_VDD(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                                .set_IDD(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                                .set_VCS(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                                .set_ICS(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                                "Pstate Parameter Block #V Zero contents error being logged");
                        }
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    }
                    else
                    {
                        FAPI_ERR("**** ERROR : Zero valued data found in #V (chiplet = %u  bucket id = %u  op point = %s)",
                                  l_chiplet_num, iv_poundV_bucket_id, pv_op_str[pv_op_order[i]]);

                        // Error out has Pstate and all dependent functions are suspious.
                        if (i_biased_state)
                        {
                            FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_ZERO_ERROR()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                                .set_VDD(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                                .set_IDD(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                                .set_VCS(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                                .set_ICS(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
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
                                .set_FREQUENCY(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                                .set_VDD(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                                .set_IDD(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                                .set_VCS(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                                .set_ICS(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                                "Pstate Parameter Block #V Zero contents error being logged");
                        }
                    }  // Halt disable
                }  // #V point zero check
            }  // WOF and UT conditions
        } // Operating poing loop
    } // validate #V EC

    // Adjust the valid operating point based on UltraTurbo presence
    // and WOF enablement
    iv_valid_pdv_points = NUM_OP_POINTS;

    if (suspend_ut_check)
    {
        iv_valid_pdv_points--;
    }

    FAPI_DBG("iv_valid_pdv_points = %d", iv_valid_pdv_points);

    if (attr_poundv_validate_ec_disable)
    {
        iv_pstates_enabled = false;
        FAPI_INF("**** WARNING : #V relationship checking is not being performed on this chip EC level");
        FAPI_INF("**** WARNING : Pstates are not enabled");
    }
    else
    {
        // check valid operating points' values have this relationship (power save <= nominal <= turbo <= ultraturbo)
        for (i = 1; i <= (iv_valid_pdv_points) - 1; i++)
        {
            FAPI_INF("Checking for relationship between #V operating point (%s <= %s)",
                     pv_op_str[pv_op_order[i - 1]], pv_op_str[pv_op_order[i]]);

            // Only skip checkinug for WOF not enabled and UltraTurbo.
            if ( is_wof_enabled()    ||
               (!( !is_wof_enabled() &&
               (strcmp(pv_op_str[pv_op_order[i]], "UltraTurbo") == 0))))
            {
                if (l_attr_mvpd_data[pv_op_order[i - 1]].frequency_mhz >
                    l_attr_mvpd_data[pv_op_order[i]].frequency_mhz     ||
                    l_attr_mvpd_data[pv_op_order[i - 1]].vdd_mv        >
                    l_attr_mvpd_data[pv_op_order[i]].vdd_mv            ||
                    l_attr_mvpd_data[pv_op_order[i - 1]].idd_100ma     >
                    l_attr_mvpd_data[pv_op_order[i]].idd_100ma         ||
                    l_attr_mvpd_data[pv_op_order[i - 1]].vcs_mv        >
                    l_attr_mvpd_data[pv_op_order[i]].vcs_mv            ||
                    l_attr_mvpd_data[pv_op_order[i - 1]].ics_100ma     >
                    l_attr_mvpd_data[pv_op_order[i]].ics_100ma  )
                {
                    iv_pstates_enabled = false;

                    if (attr_poundv_validity_halt_disable)
                    {
                        FAPI_IMP("**** WARNING : halt on #V validity checking has been "
                                 "disabled and relationship errors were found");
                        FAPI_IMP("**** WARNING : Relationship error between #V operating point "
                                "(%s > %s)(power save <= nominal <= turbo <= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                            pv_op_str[pv_op_order[i - 1]], pv_op_str[pv_op_order[i]], l_chiplet_num, iv_poundV_bucket_id, pv_op_order[i]);
                        FAPI_IMP("**** WARNING : Pstates are not enabled but continuing on.");
                    }
                    else
                    {
                        FAPI_ERR("**** ERROR : Relation../../xml/attribute_info/pm_plat_attributes.xmlship "
                                 "error between #V operating point (%s > %s)(power save <= nominal <= turbo "
                                 "<= ultraturbo) (chiplet = %u  bucket id = %u  op point = %u)",
                                 pv_op_str[pv_op_order[i - 1]], pv_op_str[pv_op_order[i]], l_chiplet_num, iv_poundV_bucket_id,pv_op_order[i]);
                    }

                    FAPI_INF("%s Frequency value %u is %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], l_attr_mvpd_data[pv_op_order[i - 1]].frequency_mhz,
                           POUNDV_SLOPE_CHECK(l_attr_mvpd_data[pv_op_order[i - 1]].frequency_mhz,
                           l_attr_mvpd_data[pv_op_order[i]].frequency_mhz),pv_op_str[pv_op_order[i]], l_attr_mvpd_data[pv_op_order[i]].frequency_mhz);

                    FAPI_INF("%s VDD voltage value %u is %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], l_attr_mvpd_data[pv_op_order[i - 1]].vdd_mv,
                           POUNDV_SLOPE_CHECK(l_attr_mvpd_data[pv_op_order[i - 1]].vdd_mv, l_attr_mvpd_data[pv_op_order[i]].vdd_mv),
                           pv_op_str[pv_op_order[i]], l_attr_mvpd_data[pv_op_order[i]].vdd_mv);

                    FAPI_INF("%s VDD current value %u is %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], l_attr_mvpd_data[pv_op_order[i - 1]].idd_100ma,
                           POUNDV_SLOPE_CHECK(l_attr_mvpd_data[pv_op_order[i - 1]].idd_100ma, l_attr_mvpd_data[pv_op_order[i]].idd_100ma),
                           pv_op_str[pv_op_order[i]], l_attr_mvpd_data[pv_op_order[i]].idd_100ma);

                    FAPI_INF("%s VCS voltage value %u is %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], l_attr_mvpd_data[pv_op_order[i - 1]].vcs_mv,
                           POUNDV_SLOPE_CHECK(l_attr_mvpd_data[pv_op_order[i - 1]].vcs_mv, l_attr_mvpd_data[pv_op_order[i]].vcs_mv),
                           pv_op_str[pv_op_order[i]], l_attr_mvpd_data[pv_op_order[i]].vcs_mv);

                    FAPI_INF("%s VCS current value %u i../../xml/attribute_info/pm_plat_attributes.xmls %s %s Frequency value %u",
                           pv_op_str[pv_op_order[i - 1]], l_attr_mvpd_data[pv_op_order[i - 1]].ics_100ma,
                           POUNDV_SLOPE_CHECK(l_attr_mvpd_data[pv_op_order[i - 1]].ics_100ma, l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                           pv_op_str[pv_op_order[i]], l_attr_mvpd_data[pv_op_order[i]].ics_100ma);

                    if (i_biased_state)
                    {
                        if (attr_poundv_validity_halt_disable)
                        {
                            // Log the error only.
                            FAPI_ASSERT_NOEXIT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY_A(l_attr_mvpd_data[pv_op_order[i - 1]].frequency_mhz)
                                .set_VDD_A(l_attr_mvpd_data[pv_op_order[i - 1]].vdd_mv)
                                .set_IDD_A(l_attr_mvpd_data[pv_op_order[i - 1]].idd_100ma)
                                .set_VCS_A(l_attr_mvpd_data[pv_op_order[i - 1]].vcs_mv)
                                .set_ICS_A(l_attr_mvpd_data[pv_op_order[i - 1]].ics_100ma)
                                .set_FREQUENCY_B(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                                .set_VDD_B(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                                .set_IDD_B(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                                .set_VCS_B(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                                .set_ICS_B(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                                "Pstate Parameter Block Biased #V disorder contents error being logged");

                             fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;

                        }
                        else
                        {
                            // Error out has Pstate and all dependent functions are suspious.
                            FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_BIASED_POUNDV_SLOPE_ERROR()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY_A(l_attr_mvpd_data[pv_op_order[i - 1]].frequency_mhz)
                                .set_VDD_A(l_attr_mvpd_data[pv_op_order[i - 1]].vdd_mv)
                                .set_IDD_A(l_attr_mvpd_data[pv_op_order[i - 1]].idd_100ma)
                                .set_VCS_A(l_attr_mvpd_data[pv_op_order[i - 1]].vcs_mv)
                                .set_ICS_A(l_attr_mvpd_data[pv_op_order[i - 1]].ics_100ma)
                                .set_FREQUENCY_B(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                                .set_VDD_B(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                                .set_IDD_B(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                                .set_VCS_B(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                                .set_ICS_B(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
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
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY_A(l_attr_mvpd_data[pv_op_order[i - 1]].frequency_mhz)
                                .set_VDD_A(l_attr_mvpd_data[pv_op_order[i - 1]].vdd_mv)
                                .set_IDD_A(l_attr_mvpd_data[pv_op_order[i - 1]].idd_100ma)
                                .set_VCS_A(l_attr_mvpd_data[pv_op_order[i - 1]].vcs_mv)
                                .set_ICS_A(l_attr_mvpd_data[pv_op_order[i - 1]].ics_100ma)
                                .set_FREQUENCY_B(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                                .set_VDD_B(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                                .set_IDD_B(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                                .set_VCS_B(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                                .set_ICS_B(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                                "Pstate Parameter Block #V disorder contents error being logged");

                             fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                        }
                        else
                        {
                            // Error out has Pstate and all dependent functions are suspious.
                            FAPI_ASSERT(false,
                                fapi2::PSTATE_PB_POUNDV_SLOPE_ERROR()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CHIPLET_NUMBER(l_chiplet_num)
                                .set_BUCKET(iv_poundV_bucket_id)
                                .set_POINT(i)
                                .set_FREQUENCY_A(l_attr_mvpd_data[pv_op_order[i - 1]].frequency_mhz)
                                .set_VDD_A(l_attr_mvpd_data[pv_op_order[i - 1]].vdd_mv)
                                .set_IDD_A(l_attr_mvpd_data[pv_op_order[i - 1]].idd_100ma)
                                .set_VCS_A(l_attr_mvpd_data[pv_op_order[i - 1]].vcs_mv)
                                .set_ICS_A(l_attr_mvpd_data[pv_op_order[i - 1]].ics_100ma)
                                .set_FREQUENCY_B(l_attr_mvpd_data[pv_op_order[i]].frequency_mhz)
                                .set_VDD_B(l_attr_mvpd_data[pv_op_order[i]].vdd_mv)
                                .set_IDD_B(l_attr_mvpd_data[pv_op_order[i]].idd_100ma)
                                .set_VCS_B(l_attr_mvpd_data[pv_op_order[i]].vcs_mv)
                                .set_ICS_B(l_attr_mvpd_data[pv_op_order[i]].ics_100ma),
                                "Pstate Parameter Block #V disorder contents error being logged");
                        }
                    }
                }  // validity failed
            }  // Skip UT check
        } // point loop
    }  // validity disabled
fapi_try_exit:
    FAPI_DBG("<< chk_valid_poundv");
    return fapi2::current_err;
} // end of chk_valid_poundv


///////////////////////////////////////////////////////////
////////   get_mvpd_poundV
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundV()
{
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
    fapi2::voltageBucketData_t l_fstChlt_vpd_data;
    fapi2::Target<fapi2::TARGET_TYPE_EQ> l_firstEqChiplet;
    uint8_t    j                = 0;
    uint8_t    first_chplt      = 1;
    uint8_t    bucket_id        = 0;
    uint8_t*   l_buffer         =
    reinterpret_cast<uint8_t*>(malloc(sizeof(voltageBucketData_t)) );
    uint8_t*   l_buffer_inc     = NULL;

    do
    {
        memset(&l_fstChlt_vpd_data,0,sizeof(l_fstChlt_vpd_data));
        // initialize
        iv_eq_chiplet_state = 0;

        // -----------------------------------------------------------------
        // get list of quad chiplets and loop over each and get #V data from each
        // -----------------------------------------------------------------
        // check that frequency is the same per chiplet
        // for voltage, get the max for use for the chip

        l_eqChiplets = iv_procChip.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);
        iv_eq_chiplet_state = l_eqChiplets.size();

        FAPI_INF("Number of EQ chiplets present => %u", iv_eq_chiplet_state);

        for (j = 0; j < l_eqChiplets.size(); j++)
        {
            uint8_t l_chipNum = 0xFF;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_eqChiplets[j], l_chipNum));

            FAPI_INF("Chip Number => %u", l_chipNum);

            FAPI_TRY(p9_pm_get_poundv_bucket(l_eqChiplets[j], iv_poundV_raw_data));

            bucket_id = iv_poundV_raw_data.bucketId;
            memset(l_buffer, 0, sizeof(iv_poundV_raw_data));

            // fill chiplet_mvpd_data 2d array with data iN buffer (skip first byte - bucket id)
#define UINT16_GET(__uint8_ptr)   ((uint16_t)( ( (*((const uint8_t *)(__uint8_ptr)) << 8) | *((const uint8_t *)(__uint8_ptr) + 1) ) ))

            //memcpy(iv_attr_mvpd_poundV_raw,&iv_poundV_raw_data.nomFreq,sizeof(iv_attr_mvpd_poundV_raw));
            memcpy(l_buffer, &iv_poundV_raw_data, sizeof(iv_poundV_raw_data));

            FAPI_INF("#V chiplet = %u bucket id = %u", l_chipNum, bucket_id);

            l_buffer_inc = l_buffer;
            l_buffer_inc++;
            for (int i = 0; i <= 4; i++)
            {
                iv_attr_mvpd_poundV_raw[i].frequency_mhz = (uint32_t) UINT16_GET(l_buffer_inc);
                l_buffer_inc += 2;
                FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].frequency_mhz,
                             iv_attr_mvpd_poundV_raw[i].frequency_mhz);
                iv_attr_mvpd_poundV_raw[i].vdd_mv= (uint32_t) UINT16_GET(l_buffer_inc);
                FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vdd_mv,
                             iv_attr_mvpd_poundV_raw[i].vdd_mv);
                l_buffer_inc += 2;
                iv_attr_mvpd_poundV_raw[i].idd_100ma= (uint32_t) UINT16_GET(l_buffer_inc);
                FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].idd_100ma,
                             iv_attr_mvpd_poundV_raw[i].idd_100ma);
                l_buffer_inc += 2;
                iv_attr_mvpd_poundV_raw[i].vcs_mv= (uint32_t) UINT16_GET(l_buffer_inc);
                FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].vcs_mv,
                             iv_attr_mvpd_poundV_raw[i].vcs_mv);
                l_buffer_inc += 2;
                iv_attr_mvpd_poundV_raw[i].ics_100ma= (uint32_t) UINT16_GET(l_buffer_inc);
                FAPI_INF("#V data = 0x%04X  %-6d", iv_attr_mvpd_poundV_raw[i].ics_100ma,
                             iv_attr_mvpd_poundV_raw[i].ics_100ma);
                l_buffer_inc += 2;
            }

            FAPI_TRY(chk_valid_poundv(false));

            // on first chiplet put each bucket's data into attr_mvpd_voltage_control
            if (first_chplt)
            {
                l_firstEqChiplet = l_eqChiplets[j];
                iv_poundV_bucket_id = bucket_id;
                memcpy(&l_fstChlt_vpd_data,&iv_poundV_raw_data,sizeof(iv_poundV_raw_data));
                first_chplt = 0;
            }
            else
            {
                // on subsequent chiplets, check that frequencies are same for each operating point for each chiplet
                if ( (iv_poundV_raw_data.nomFreq    != l_fstChlt_vpd_data.nomFreq) ||
                     (iv_poundV_raw_data.PSFreq     != l_fstChlt_vpd_data.PSFreq) ||
                     (iv_poundV_raw_data.turboFreq  != l_fstChlt_vpd_data.turboFreq) ||
                     (iv_poundV_raw_data.uTurboFreq != l_fstChlt_vpd_data.uTurboFreq) ||
                     (iv_poundV_raw_data.pbFreq     != l_fstChlt_vpd_data.pbFreq) )
                {
                    iv_pstates_enabled = false;
                    // Error out has Pstate and all dependent functions are suspious.
                    FAPI_ASSERT(false,
                                fapi2::PSTATE_MVPD_CHIPLET_VOLTAGE_NOT_EQUAL()
                                .set_CHIP_TARGET(iv_procChip)
                                .set_CURRENT_EQ_CHIPLET_TARGET(l_eqChiplets[j])
                                .set_FIRST_EQ_CHIPLET_TARGET(l_firstEqChiplet)
                                .set_BUCKET(bucket_id),
                                "frequencies are not the same for each operating point for each chiplet");

                }
            }

            // check each bucket for max voltage and if max, put bucket's data into attr_mvpd_voltage_control
            //
            if ( (iv_poundV_raw_data.VddNomVltg    > l_fstChlt_vpd_data.VddNomVltg) ||
                 (iv_poundV_raw_data.VddPSVltg     > l_fstChlt_vpd_data.VddPSVltg) ||
                 (iv_poundV_raw_data.VddTurboVltg  > l_fstChlt_vpd_data.VddTurboVltg) ||
                 (iv_poundV_raw_data.VddUTurboVltg > l_fstChlt_vpd_data.VddUTurboVltg) ||
                 (iv_poundV_raw_data.VdnPbVltg     > l_fstChlt_vpd_data.VdnPbVltg) )
            {
                memcpy(&l_fstChlt_vpd_data,&iv_poundV_raw_data,sizeof(iv_poundV_raw_data));
                iv_poundV_bucket_id = bucket_id;
            }

        } // end for loop
    }
    while(0);


fapi_try_exit:

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        iv_pstates_enabled = false;
    }
    free (l_buffer);

    return fapi2::current_err;

} // end of get_mvpd_poundV


///////////////////////////////////////////////////////////
////////   get_extint_bias
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_extint_bias( )
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
               iv_bias[p].frequency_hp    = iv_attrs.attr_freq_bias_powersave;
               iv_bias[p].vdd_ext_hp      = iv_attrs.attr_voltage_ext_vdd_bias_powersave;
               iv_bias[p].vdd_int_hp      = iv_attrs.attr_voltage_int_vdd_bias_powersave;

               break;
            case NOMINAL:
               iv_bias[p].frequency_hp    = iv_attrs.attr_freq_bias_nominal;
               iv_bias[p].vdd_ext_hp      = iv_attrs.attr_voltage_ext_vdd_bias_nominal;
               iv_bias[p].vdd_int_hp      = iv_attrs.attr_voltage_int_vdd_bias_nominal;
               break;
            case TURBO:
               iv_bias[p].frequency_hp    = iv_attrs.attr_freq_bias_turbo;
               iv_bias[p].vdd_ext_hp      = iv_attrs.attr_voltage_ext_vdd_bias_turbo;
               iv_bias[p].vdd_int_hp      = iv_attrs.attr_voltage_int_vdd_bias_turbo;
               break;
            case ULTRA:
               iv_bias[p].frequency_hp    = iv_attrs.attr_freq_bias_ultraturbo;
               iv_bias[p].vdd_ext_hp      = iv_attrs.attr_voltage_ext_vdd_bias_ultraturbo;
               iv_bias[p].vdd_int_hp      = iv_attrs.attr_voltage_int_vdd_bias_ultraturbo;
        }

        iv_bias[p].vdn_ext_hp      = iv_attrs.attr_voltage_ext_vdn_bias;
        iv_bias[p].vcs_ext_hp      = iv_attrs.attr_voltage_ext_vcs_bias;

        freq_bias[p]                 = calc_bias(iv_bias[p].frequency_hp);
        voltage_ext_vdd_bias[p]      = calc_bias(iv_bias[p].vdd_ext_hp);

        FAPI_DBG("    Biases[%d](bias): Freq=%f (%f%%); VDD=%f (%f%%)",
                    p,
                    freq_bias[p],            iv_bias[p].frequency_hp/2,
                    voltage_ext_vdd_bias[p], iv_bias[p].vdd_ext_hp/2);
    }

    // VCS bias applied to all operating points
    voltage_ext_vcs_bias = calc_bias(iv_attrs.attr_voltage_ext_vcs_bias);

    // VDN bias applied to all operating points
    voltage_ext_vdn_bias = calc_bias(iv_attrs.attr_voltage_ext_vdn_bias);

    // Change the VPD frequency, VDD and VCS values with the bias multiplers
    for (auto p = 0; p < NUM_OP_POINTS; p++)
    {
        FAPI_DBG("    Orig values[%d](bias): Freq=%d (%f); VDD=%d (%f), VCS=%d (%f)",
                    p,
                    iv_attr_mvpd_poundV_biased[p].frequency_mhz, freq_bias[p],
                    iv_attr_mvpd_poundV_biased[p].vdd_mv, voltage_ext_vdd_bias[p],
                    iv_attr_mvpd_poundV_biased[p].vcs_mv, voltage_ext_vcs_bias);

        double freq_mhz =
            (( (double)iv_attr_mvpd_poundV_biased[p].frequency_mhz) * freq_bias[p]);
        double vdd_mv =
            (( (double)iv_attr_mvpd_poundV_biased[p].vdd_mv) * voltage_ext_vdd_bias[p]);
        double vcs_mv =
            (( (double)iv_attr_mvpd_poundV_biased[p].vcs_mv) * voltage_ext_vcs_bias);

        iv_attr_mvpd_poundV_biased[p].frequency_mhz = (uint16_t)internal_floor(freq_mhz);
        iv_attr_mvpd_poundV_biased[p].vdd_mv        = (uint16_t)internal_ceil(vdd_mv);
        iv_attr_mvpd_poundV_biased[p].vcs_mv        = (uint16_t)(vcs_mv);

        FAPI_DBG("    Biased values[%d]: Freq=%f %d; VDD=%f %d, VCS=%f %d ",
                    p,
                    freq_mhz, iv_attr_mvpd_poundV_biased[p].frequency_mhz,
                    vdd_mv, iv_attr_mvpd_poundV_biased[p].vdd_mv,
                    vcs_mv, iv_attr_mvpd_poundV_biased[p].vcs_mv);
    }

    // Power bus operating point
    double vdn_mv =
           (( (double)iv_attr_mvpd_poundV_biased[VPD_PV_POWERBUS].vdd_mv) * voltage_ext_vdn_bias);

    iv_attr_mvpd_poundV_biased[VPD_PV_POWERBUS].vdd_mv = (uint32_t)internal_ceil(vdn_mv);

    return fapi2::FAPI2_RC_SUCCESS;
} // end of get_extint_bias


///////////////////////////////////////////////////////////
////////   apply_biased_values
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::apply_biased_values ()
{
    FAPI_INF(">>>>>>>>>>>>> apply_biased_values");

    do
    {
        // ---------------------------------------------
        // process external and internal bias attributes
        // ---------------------------------------------
        FAPI_IMP("Apply Biasing to #V");

        // Copy to Bias array
        memcpy(iv_attr_mvpd_poundV_biased,iv_attr_mvpd_poundV_raw,sizeof(iv_attr_mvpd_poundV_raw));

        for (int i = 0; i <= NUM_OP_POINTS - 1; i++)
        {
            FAPI_DBG("BIASED #V operating point (%s) f=%u v=%u i=%u v=%u i=%u",
                    pv_op_str[pv_op_order[i]],
                    iv_attr_mvpd_poundV_biased[pv_op_order[i]].frequency_mhz,
                    iv_attr_mvpd_poundV_biased[pv_op_order[i]].vdd_mv,
                    iv_attr_mvpd_poundV_biased[pv_op_order[i]].idd_100ma,
                    iv_attr_mvpd_poundV_biased[pv_op_order[i]].vcs_mv,
                    iv_attr_mvpd_poundV_biased[pv_op_order[i]].ics_100ma);
        }

        FAPI_TRY(get_extint_bias(),
                 "Bias application function failed");

        //Validating Bias values
        FAPI_INF("Validate Biasd Voltage and Frequency values");

        FAPI_TRY(chk_valid_poundv(BIASED));

        FAPI_DBG("Pstate Base Frequency - after bias %X (%d)",
                 iv_attr_mvpd_poundV_biased[ULTRA].frequency_mhz * 1000,
                 iv_attr_mvpd_poundV_biased[ULTRA].frequency_mhz * 1000);
    }while(0);

fapi_try_exit:
    FAPI_INF("<<<<<<<<<<<< apply_biased_values");
    return fapi2::current_err;

} // end of apply_biased_values


///////////////////////////////////////////////////////////
////////   large_jump_defaults
///////////////////////////////////////////////////////////
void PlatPmPPB::large_jump_defaults()
{
    const float DEFAULT_VDM_DROP_PERCENT = 12.5;
    const float DEFAULT_VDM_DROP_DIVISOR = 32;
    float poundw_freq_drop_float = (DEFAULT_VDM_DROP_PERCENT/100)*DEFAULT_VDM_DROP_DIVISOR;
    uint8_t poundw_freq_drop_value = (uint8_t)poundw_freq_drop_float;
    FAPI_DBG ("DEFAULT_VDM_DROP_PERCENT = %6.3f%%; DEFAULT_VDM_DROP_DIVISOR = %6.3f; poundw_freq_drop_value = %f %X",
        DEFAULT_VDM_DROP_PERCENT,
        DEFAULT_VDM_DROP_DIVISOR,
        poundw_freq_drop_float,
        poundw_freq_drop_value);

    // N_S/N_L - each a nibble in a byte
    iv_poundW_data.poundw[POWERSAVE].vdm_normal_freq_drop = poundw_freq_drop_value;
    iv_poundW_data.poundw[NOMINAL].vdm_normal_freq_drop = poundw_freq_drop_value;

    FAPI_INF ("Using default Large Jump percentage (%6.3f%%) for N_L (%X) for both POWERSAVE and NOMINAL due to #W access failure ",
        DEFAULT_VDM_DROP_PERCENT,
        iv_poundW_data.poundw[POWERSAVE].vdm_normal_freq_drop);

    return;
} // end of large_jump_defaults


///////////////////////////////////////////////////////////
////////  get_mvpd_poundW
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_poundW (void)
{
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_EQ>> l_eqChiplets;
    fapi2::vdmData_t l_vdmBuf;
    uint8_t    selected_eq      = 0;
    uint8_t    bucket_id        = 0;
    uint8_t    version_id       = 0;

    const char*     pv_op_str[NUM_OP_POINTS] = PV_OP_ORDER_STR;

    FAPI_DBG(">> get_mvpd_poundW");

    do
    {
         FAPI_DBG("get_mvpd_poundW: VDM enable = %d, WOF enable %d",
                    is_vdm_enabled(), is_wof_enabled());

        // Exit if both VDM and WOF is disabled
        if ((!is_vdm_enabled() && !is_wof_enabled()))
        {
            FAPI_INF("   get_mvpd_poundW: BOTH VDM and WOF are disabled.  Skipping remaining checks");
            iv_vdm_enabled = false;
            iv_wof_enabled = false;
            iv_wov_underv_enabled = false;
            iv_wov_overv_enabled = false;
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
        l_eqChiplets = iv_procChip.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);

        for (selected_eq = 0; selected_eq < l_eqChiplets.size(); selected_eq++)
        {
            uint8_t l_chipletNum = 0xFF;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_eqChiplets[selected_eq], l_chipletNum));

            FAPI_INF("Chiplet Number => %u", l_chipletNum);

            // clear out buffer to known value before calling fapiGetMvpdField
            memset(&l_vdmBuf, 0, sizeof(l_vdmBuf));

            FAPI_TRY(p9_pm_get_poundw_bucket(l_eqChiplets[selected_eq], l_vdmBuf));

            bucket_id   =   l_vdmBuf.bucketId;
            version_id  =   l_vdmBuf.version;

            FAPI_INF( "#W chiplet = %u bucket id = %u", l_chipletNum, bucket_id );

            if( version_id < POUNDW_VERSION_30 )
            {
                PoundW_data_per_quad  l_poundwPerQuad;
                PoundW_data           l_poundw;
                memcpy( &l_poundw, l_vdmBuf.vdmData, sizeof( PoundW_data ) );
                memset( &l_poundwPerQuad, 0, sizeof(PoundW_data_per_quad) );

                for( size_t op = 0; op <= ULTRA; op++ )
                {
                    //structure mapping
                    l_poundwPerQuad.poundw[op].ivdd_tdp_ac_current_10ma      =   l_poundw.poundw[op].ivdd_tdp_ac_current_10ma;

                    l_poundwPerQuad.poundw[op].ivdd_tdp_dc_current_10ma      =   l_poundw.poundw[op].ivdd_tdp_dc_current_10ma;
                    l_poundwPerQuad.poundw[op].vdm_overvolt_small_thresholds =   l_poundw.poundw[op].vdm_overvolt_small_thresholds;
                    l_poundwPerQuad.poundw[op].vdm_large_extreme_thresholds  =   l_poundw.poundw[op].vdm_large_extreme_thresholds;
                    l_poundwPerQuad.poundw[op].vdm_normal_freq_drop          =   l_poundw.poundw[op].vdm_normal_freq_drop;
                    l_poundwPerQuad.poundw[op].vdm_normal_freq_return        =   l_poundw.poundw[op].vdm_normal_freq_return;
                    l_poundwPerQuad.poundw[op].vdm_vid_compare_per_quad[0]   =   l_poundw.poundw[op].vdm_vid_compare_ivid;
                    l_poundwPerQuad.poundw[op].vdm_vid_compare_per_quad[1]   =   l_poundw.poundw[op].vdm_vid_compare_ivid;
                    l_poundwPerQuad.poundw[op].vdm_vid_compare_per_quad[2]   =   l_poundw.poundw[op].vdm_vid_compare_ivid;
                    l_poundwPerQuad.poundw[op].vdm_vid_compare_per_quad[3]   =   l_poundw.poundw[op].vdm_vid_compare_ivid;
                    l_poundwPerQuad.poundw[op].vdm_vid_compare_per_quad[4]   =   l_poundw.poundw[op].vdm_vid_compare_ivid;
                    l_poundwPerQuad.poundw[op].vdm_vid_compare_per_quad[5]   =   l_poundw.poundw[op].vdm_vid_compare_ivid;
                }

                memcpy( &l_poundwPerQuad.resistance_data, &l_poundw.resistance_data , LEGACY_RESISTANCE_ENTRY_SIZE );
                l_poundwPerQuad.resistance_data.r_undervolt_allowed =   l_poundw.undervolt_tested;
                memset(&l_vdmBuf.vdmData, 0, sizeof(l_vdmBuf.vdmData));
                memcpy(&l_vdmBuf.vdmData, &l_poundwPerQuad, sizeof( PoundW_data_per_quad ) );
            }

            //if we match with the bucket id, then we don't need to continue
            if (iv_poundV_bucket_id == bucket_id)
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
            memcpy (&iv_poundW_data, &g_vpdData, sizeof (g_vpdData));
        }
        else
        {
            FAPI_INF("attribute ATTR_POUND_W_STATIC_DATA_ENABLE is NOT set");
            // copy the data to the pound w structure from the actual VPD image
            memcpy (&iv_poundW_data, l_vdmBuf.vdmData, sizeof (l_vdmBuf.vdmData));
        }

        //Re-ordering to Natural order
        // When we read the data from VPD image the order will be N,PS,T,UT.
        // But we need the order PS,N,T,UT.. hence we are swapping the data
        // between PS and Nominal.
        poundw_entry_per_quad_t l_tmp_data;
        memset( &l_tmp_data ,0, sizeof(poundw_entry_per_quad_t));
        memcpy (&l_tmp_data,
                &(iv_poundW_data.poundw[VPD_PV_NOMINAL]),
                sizeof (poundw_entry_per_quad_t));

        memcpy (&(iv_poundW_data.poundw[VPD_PV_NOMINAL]),
                &(iv_poundW_data.poundw[VPD_PV_POWERSAVE]),
                sizeof(poundw_entry_per_quad_t));

        memcpy (&(iv_poundW_data.poundw[VPD_PV_POWERSAVE]),
                &l_tmp_data,
                sizeof(poundw_entry_per_quad_t));

        // If the #W version is less than 3, validate Turbo VDM large threshold
        // not larger than -32mV. This filters out parts that have bad VPD.  If
        // this check fails, log a recovered error, mark the VDMs disabled and
        // break out of the reset of the checks.
        uint32_t turbo_vdm_large_threshhold =
            (iv_poundW_data.poundw[TURBO].vdm_large_extreme_thresholds >> 4) & 0x0F;

        FAPI_DBG("iv_poundW_data.poundw[TURBO].vdm_large_thresholds 0x%X; grey code index %d; max grey code index %d",
                  turbo_vdm_large_threshhold,g_GreyCodeIndexMapping[turbo_vdm_large_threshhold],
                  GREYCODE_INDEX_M32MV);

        if (version_id < FULLY_VALID_POUNDW_VERSION &&
            g_GreyCodeIndexMapping[turbo_vdm_large_threshhold] > GREYCODE_INDEX_M32MV)
        {
            iv_vdm_enabled = false;

            fapi2::ATTR_CHIP_EC_FEATURE_VDM_POUNDW_SUPPRESS_ERROR_Type l_suppress_pdw_error;
            FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_VDM_POUNDW_SUPPRESS_ERROR,
                          iv_procChip,
                          l_suppress_pdw_error);

            if (l_suppress_pdw_error)
            {
                FAPI_INF("VDM #W ERROR: Turbo Large Threshold less than -32mV. Indicates bad VPD so VDMs being disabled and pressing on");
            }
            else
            {
                FAPI_ASSERT_NOEXIT(false,
                   fapi2::PSTATE_PB_POUND_W_VERY_INVALID_VDM_DATA(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                   .set_CHIP_TARGET(iv_procChip)
                   .set_TURBO_LARGE_THRESHOLD(iv_poundW_data.poundw[TURBO].vdm_large_extreme_thresholds),
                   "VDM #W ERROR: Turbo Large Threshold less than -32mV. Indicates bad VPD so VDMs being disabled and pressing on");
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }

            break;

        }

        // Validate the WOF content is non-zero if WOF is enabled
        if (is_wof_enabled())
        {
            bool b_tdp_ac = true;
            bool b_tdp_dc = true;
            // Check that the WOF currents are non-zero
            for (auto p = 0; p < NUM_OP_POINTS; ++p)
            {
                FAPI_INF("%s ivdd_tdp_ac_current %5d (10mA) %6.2f (A)",
                          pv_op_str[p],
                          revle16(iv_poundW_data.poundw[p].ivdd_tdp_ac_current_10ma),
                         ((double)revle16(iv_poundW_data.poundw[p].ivdd_tdp_ac_current_10ma)/100));
                FAPI_INF("%s ivdd_tdp_dc_current %5d (10mA) %6.2f (A)",
                          pv_op_str[p],
                          revle16(iv_poundW_data.poundw[p].ivdd_tdp_dc_current_10ma),
                          ((double)revle16(iv_poundW_data.poundw[p].ivdd_tdp_dc_current_10ma)/100));

                if (!iv_poundW_data.poundw[p].ivdd_tdp_ac_current_10ma)
                {
                    FAPI_ERR("%s.ivdd_tdp_ac_current_10ma is zero!!!",
                              pv_op_str[p]);
                    b_tdp_ac = false;
                    iv_wof_enabled = false;

                }
                if (!iv_poundW_data.poundw[p].ivdd_tdp_dc_current_10ma)
                {
                    FAPI_ERR("%s.ivdd_tdp_dc_current_10ma is zero!!!",
                              pv_op_str[p]);
                    b_tdp_dc = false;
                    iv_wof_enabled = false;
                }
            }

            FAPI_ASSERT_NOEXIT(b_tdp_ac,
                               fapi2::PSTATE_PB_POUND_W_TDP_IAC_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(iv_procChip)
                               .set_EQ_TARGET(l_eqChiplets[selected_eq])
                               .set_NOMINAL_TDP_IAC(iv_poundW_data.poundw[NOMINAL].ivdd_tdp_dc_current_10ma)
                               .set_POWERSAVE_TDP_IAC(iv_poundW_data.poundw[POWERSAVE].ivdd_tdp_dc_current_10ma)
                               .set_TURBO_TDP_IAC(iv_poundW_data.poundw[TURBO].ivdd_tdp_dc_current_10ma)
                               .set_ULTRA_TDP_IAC(iv_poundW_data.poundw[ULTRA].ivdd_tdp_dc_current_10ma),
                               "Pstate Parameter Block #W : one or more Idd TDP AC values are zero");
            FAPI_ASSERT_NOEXIT(b_tdp_dc,
                               fapi2::PSTATE_PB_POUND_W_TDP_IDC_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(iv_procChip)
                               .set_EQ_TARGET(l_eqChiplets[selected_eq])
                               .set_NOMINAL_TDP_IDC(iv_poundW_data.poundw[NOMINAL].ivdd_tdp_dc_current_10ma)
                               .set_POWERSAVE_TDP_IDC(iv_poundW_data.poundw[POWERSAVE].ivdd_tdp_dc_current_10ma)
                               .set_TURBO_TDP_IDC(iv_poundW_data.poundw[TURBO].ivdd_tdp_dc_current_10ma)
                               .set_ULTRA_TDP_IDC(iv_poundW_data.poundw[ULTRA].ivdd_tdp_dc_current_10ma),
                               "o_dataPstate Parameter Block #W : one or more Idd TDP DC values are zero");

            // Set the return code to success to keep going.
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
        }

        // The rest of the processing here is all checking of the VDM content
        // within #W.  If VDMs are not enabled (or supported), skip all of it
        if (!is_vdm_enabled())
        {
            FAPI_INF( "get_mvpd_poundW: VDM is disabled.  Skipping remaining checks" );
            iv_vdm_enabled = false;
            break;
        }

        // validate threshold values
        bool l_threshold_value_state = 1;

        validate_quad_spec_data( );

        for (uint8_t p = 0; p < NUM_OP_POINTS; ++p)
        {
            FAPI_INF("iv_poundW_data.poundw[%d].vdm_overvolt_thresholds 0x%X",
                     p,(iv_poundW_data.poundw[p].vdm_overvolt_small_thresholds >> 4) & 0x0F);
            FAPI_INF("iv_poundW_data.poundw[%d].vdm_small_thresholds    0x%X",
                     p,(iv_poundW_data.poundw[p].vdm_overvolt_small_thresholds ) & 0x0F);
            FAPI_INF("iv_poundW_data.poundw[%d].vdm_large_thresholds    0x%X",
                     p,(iv_poundW_data.poundw[p].vdm_large_extreme_thresholds >> 4) & 0x0F);
            FAPI_INF("iv_poundW_data.poundw[%d].vdm_extreme_thresholds  0x%X",
                     p,(iv_poundW_data.poundw[p].vdm_large_extreme_thresholds) & 0x0F);
            VALIDATE_THRESHOLD_VALUES(((iv_poundW_data.poundw[p].vdm_overvolt_small_thresholds >> 4) & 0x0F), // overvolt
                                      ((iv_poundW_data.poundw[p].vdm_overvolt_small_thresholds) & 0x0F),      // small
                                      ((iv_poundW_data.poundw[p].vdm_large_extreme_thresholds >> 4) & 0x0F),  // large
                                      ((iv_poundW_data.poundw[p].vdm_large_extreme_thresholds) & 0x0F),       // extreme
                                      l_threshold_value_state);

            if (!l_threshold_value_state)
            {
                iv_vdm_enabled = false;
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_POUND_W_INVALID_THRESHOLD_VALUE(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CHIP_TARGET(iv_procChip)
                                   .set_EQ_TARGET(l_eqChiplets[selected_eq])
                                   .set_OP_POINT_TYPE(p)
                                   .set_VDM_OVERVOLT((iv_poundW_data.poundw[p].vdm_overvolt_small_thresholds >> 4) & 0x0F)
                                   .set_VDM_SMALL(iv_poundW_data.poundw[p].vdm_overvolt_small_thresholds & 0x0F)
                                   .set_VDM_EXTREME((iv_poundW_data.poundw[p].vdm_large_extreme_thresholds >> 4) & 0x0F)
                                   .set_VDM_LARGE((iv_poundW_data.poundw[p].vdm_large_extreme_thresholds) & 0x0F),
                                   "Pstate Parameter Block #W VDM threshold data are invalid");
                break;
            }
        }

        bool l_frequency_value_state = 1;

        for (uint8_t p = 0; p < NUM_OP_POINTS; ++p)
        {
            // These fields are 4 bits wide, and stored in a uint8, hence the shifting
            // N_S, N_L, L_S, S_N
            FAPI_INF("iv_poundW_data.poundw[%d] VDM_FREQ_DROP   N_S = %d",
                      p, ((iv_poundW_data.poundw[p].vdm_normal_freq_drop >> 4) & 0x0F));
            FAPI_INF("iv_poundW_data.poundw[%d] VDM_FREQ_DROP   N_L = %d",
                      p, ((iv_poundW_data.poundw[p].vdm_normal_freq_drop) & 0x0F));
            FAPI_INF("iv_poundW_data.poundw[%d] VDM_FREQ_RETURN L_S = %d",
                      p, ((iv_poundW_data.poundw[p].vdm_normal_freq_return >> 4) & 0x0F));
            FAPI_INF("iv_poundW_data.poundw[%d] VDM_FREQ_RETURN S_N = %d",
                      p, ((iv_poundW_data.poundw[p].vdm_normal_freq_return) & 0x0F));

            VALIDATE_FREQUENCY_DROP_VALUES(((iv_poundW_data.poundw[p].vdm_normal_freq_drop) & 0x0F),        // N_L
                                           ((iv_poundW_data.poundw[p].vdm_normal_freq_drop >> 4) & 0x0F),   // N_S
                                           ((iv_poundW_data.poundw[p].vdm_normal_freq_return >> 4) & 0x0F), // L_S
                                           ((iv_poundW_data.poundw[p].vdm_normal_freq_return) & 0x0F),      // S_N
                                           l_frequency_value_state);

            if (!l_frequency_value_state)
            {
                iv_vdm_enabled = false;
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_POUND_W_INVALID_FREQ_DROP_VALUE(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CHIP_TARGET(iv_procChip)
                                   .set_EQ_TARGET(l_eqChiplets[selected_eq])
                                   .set_OP_POINT_TYPE(p)
                                   .set_VDM_NORMAL_SMALL((iv_poundW_data.poundw[p].vdm_normal_freq_drop >> 4) & 0x0F)
                                   .set_VDM_NORMAL_LARGE(iv_poundW_data.poundw[p].vdm_normal_freq_drop & 0x0F)
                                   .set_VDM_LARGE_SMALL((iv_poundW_data.poundw[p].vdm_normal_freq_return >> 4) & 0x0F)
                                   .set_VDM_SMALL_NORMAL((iv_poundW_data.poundw[p].vdm_normal_freq_return) & 0x0F),
                                   "Pstate Parameter Block #W VDM frequency drop data are invalid");
                break;
            }
        }

        //If we have reached this point, that means VDM is ok to be enabled. Only then we try to
        //enable wov undervolting
        if ( ((iv_poundW_data.resistance_data.r_undervolt_allowed == 1) || (iv_attrs.attr_wov_underv_force == 1))  &&
            is_wov_underv_enabled() == 1 )
        {
            iv_wov_underv_enabled = true;
            FAPI_DBG("UNDERV_TESTED or UNDERV_FORCE set to 1");
        } else {
            iv_wov_underv_enabled = false;
            FAPI_DBG("UNDERV_TESTED and UNDERV_FORCE set to 0");
        }


    }
    while(0);


fapi_try_exit:

    // Given #W has both VDM and WOF content, a failure needs to disable both
    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        iv_vdm_enabled = false;
        iv_wof_enabled = false;
        iv_wov_underv_enabled = false;
        iv_wov_overv_enabled = false;
    }

    if (!(iv_vdm_enabled))
    {
        // With VDMs disabled, we have to ensure that we have some Large
        // Jump values to compute the safe mode frequency and voltage as some
        // part sorts assume that uplift in their guardbands.  As systems are
        // offered assuming VDM operability which elevates the floor, default
        // values are needed.
        large_jump_defaults();
    }
    FAPI_DBG("<< get_mvpd_poundW");
    return fapi2::current_err;

} // end of get_mvpd_poundW

fapi2::ReturnCode PlatPmPPB::validate_quad_spec_data( )
{
    auto  l_eqChiplets  =   iv_procChip.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);
    uint8_t eqNum       =   0;
    const uint16_t VDM_VOLTAGE_IN_MV            =   512;
    const uint16_t VDM_GRANULARITY              =   4;
    const uint16_t MIN_VDM_VOLTAGE_IN_MV        =   576;
    const char*    pv_op_str[NUM_OP_POINTS]     =   VPD_PV_ORDER_STR;
    uint32_t l_vdm_compare_raw_mv[NUM_OP_POINTS];
    uint32_t l_vdm_compare_biased_mv[NUM_OP_POINTS];

    for( auto eq : l_eqChiplets )
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, eq, eqNum ));

        for (int i = 0; i < NUM_OP_POINTS; ++i)
        {
            l_vdm_compare_raw_mv[i] = VDM_VOLTAGE_IN_MV + (iv_poundW_data.poundw[i].vdm_vid_compare_per_quad[eqNum] << 2);

            FAPI_INF( "%10s Op Point [%d] vdm_vid_compare_per_quad[%d]  %3d  => %d mv",
                       pv_op_str[i], i, eqNum, iv_poundW_data.poundw[i].vdm_vid_compare_per_quad[eqNum],
                       l_vdm_compare_raw_mv[i] );
        }

        //Validation of VPD Data
        //If all VID compares are zero then use #V VDD voltage to populate local
        //data structure..So that we make progress in lab with early hardware
        if ( !(iv_poundW_data.poundw[NOMINAL].vdm_vid_compare_per_quad[eqNum])   &&
             !(iv_poundW_data.poundw[POWERSAVE].vdm_vid_compare_per_quad[eqNum]) &&
             !(iv_poundW_data.poundw[TURBO].vdm_vid_compare_per_quad[eqNum])     &&
             !(iv_poundW_data.poundw[ULTRA].vdm_vid_compare_per_quad[eqNum]))
        {
            //vdm_vid_compare_per_quad[eqNum] will be in ivid units (eg HEX((Compare
            //Voltage (mv) - 512mV)/4mV).
            iv_poundW_data.poundw[NOMINAL].vdm_vid_compare_per_quad[eqNum]    =
                (iv_poundV_raw_data.VddNomVltg    - VDM_VOLTAGE_IN_MV ) / VDM_GRANULARITY;
            iv_poundW_data.poundw[POWERSAVE].vdm_vid_compare_per_quad[eqNum]  =
                (iv_poundV_raw_data.VddPSVltg     - VDM_VOLTAGE_IN_MV ) / VDM_GRANULARITY;
            iv_poundW_data.poundw[TURBO].vdm_vid_compare_per_quad[eqNum]      =
                (iv_poundV_raw_data.VddTurboVltg  - VDM_VOLTAGE_IN_MV ) / VDM_GRANULARITY;
            iv_poundW_data.poundw[ULTRA].vdm_vid_compare_per_quad[eqNum] =
                (iv_poundV_raw_data.VddUTurboVltg - VDM_VOLTAGE_IN_MV ) / VDM_GRANULARITY;
        }//if any one of the VID compares are zero, then need to fail because of BAD VPD image.
        else if ( !(iv_poundW_data.poundw[NOMINAL].vdm_vid_compare_per_quad[eqNum]) ||
                  !(iv_poundW_data.poundw[POWERSAVE].vdm_vid_compare_per_quad[eqNum]) ||
                  !(iv_poundW_data.poundw[TURBO].vdm_vid_compare_per_quad[eqNum]) ||
                  !(iv_poundW_data.poundw[ULTRA].vdm_vid_compare_per_quad[eqNum]))
        {
            iv_vdm_enabled = false;
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_POUND_W_INVALID_VID_VALUE(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(iv_procChip)
                               .set_EQ_TARGET(eq)
                               .set_NOMINAL_VID_COMPARE_IVID_VALUE(iv_poundW_data.poundw[NOMINAL].vdm_vid_compare_per_quad[eqNum])
                               .set_POWERSAVE_VID_COMPARE_IVID_VALUE(iv_poundW_data.poundw[POWERSAVE].vdm_vid_compare_per_quad[eqNum])
                               .set_TURBO_VID_COMPARE_IVID_VALUE(iv_poundW_data.poundw[TURBO].vdm_vid_compare_per_quad[eqNum])
                               .set_ULTRA_VID_COMPARE_IVID_VALUE(iv_poundW_data.poundw[ULTRA].vdm_vid_compare_per_quad[eqNum]),
                               "Pstate Parameter Block #W : one of the VID compare value is zero");
            break;
        }

        // validate vid values
        bool l_compare_vid_value_state = 1;
        VALIDATE_VID_VALUES (iv_poundW_data.poundw[POWERSAVE].vdm_vid_compare_per_quad[eqNum],
                             iv_poundW_data.poundw[NOMINAL].vdm_vid_compare_per_quad[eqNum],
                             iv_poundW_data.poundw[TURBO].vdm_vid_compare_per_quad[eqNum],
                             iv_poundW_data.poundw[ULTRA].vdm_vid_compare_per_quad[eqNum],
                             l_compare_vid_value_state);

        if (!l_compare_vid_value_state)
        {
            iv_vdm_enabled = false;
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::PSTATE_PB_POUND_W_INVALID_VID_ORDER(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(iv_procChip)
                               .set_EQ_TARGET(eq)
                               .set_NOMINAL_VID_COMPARE_IVID_VALUE(iv_poundW_data.poundw[NOMINAL].vdm_vid_compare_per_quad[eqNum])
                               .set_POWERSAVE_VID_COMPARE_IVID_VALUE(iv_poundW_data.poundw[POWERSAVE].vdm_vid_compare_per_quad[eqNum])
                               .set_TURBO_VID_COMPARE_IVID_VALUE(iv_poundW_data.poundw[TURBO].vdm_vid_compare_per_quad[eqNum])
                               .set_ULTRA_VID_COMPARE_IVID_VALUE(iv_poundW_data.poundw[ULTRA].vdm_vid_compare_per_quad[eqNum]),
                               "Pstate Parameter Block #W VID compare data are not in increasing order");
            break;
        }

        //Biased compare vid data
        fapi2::ATTR_VDM_VID_COMPARE_BIAS_0P5PCT_Type l_bias_value;


        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_VID_COMPARE_BIAS_0P5PCT,
                               iv_procChip,
                               l_bias_value),
                 "Error from FAPI_ATTR_GET for attribute ATTR_VDM_VID_COMPARE_BIAS_0P5PCT");

        float l_pound_w_points[NUM_OP_POINTS];

        for (uint8_t i = 0; i < NUM_OP_POINTS; i++)
        {
            l_pound_w_points[i]  = calc_bias(l_bias_value[i]);
            l_vdm_compare_biased_mv[i] = internal_ceil( (l_vdm_compare_raw_mv[i] * l_pound_w_points[i]));

            if (l_vdm_compare_biased_mv[i] < MIN_VDM_VOLTAGE_IN_MV)
            {
                l_vdm_compare_biased_mv[i] = MIN_VDM_VOLTAGE_IN_MV;
            }

            iv_poundW_data.poundw[i].vdm_vid_compare_per_quad[eqNum] =
            (l_vdm_compare_biased_mv[i] - VDM_VOLTAGE_IN_MV) >> 2;

            FAPI_INF("vdm_vid_compare_per_quad[eqNum] %x %x, %x",
                        iv_poundW_data.poundw[i].vdm_vid_compare_per_quad[eqNum],
                        iv_poundW_data.poundw[i].vdm_vid_compare_per_quad[eqNum],
                        l_pound_w_points[i]);
        }

    }//for eq

fapi_try_exit:
    return fapi2::current_err;

}

///////////////////////////////////////////////////////////
//////// iddq_print
///////////////////////////////////////////////////////////
void iddq_print(IddqTable* i_iddqt)
{
    uint32_t        i, j;
    const char*     idd_meas_str[IDDQ_MEASUREMENTS] = IDDQ_ARRAY_VOLTAGES_STR;
    char            l_buffer_str[1024];   // Temporary formatting string buffer
    char            l_line_str[1024];     // Formatted output line string
    size_t          l_line_str_len;

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
    // the length for l_line_str_len is added by extra 2: 1 for a space in format "%-*s ";
    // another 1 for terminating null.

    l_line_str_len = strlen(l_line_str) - 1;
    snprintf(l_buffer_str, l_line_str_len, "%-*s ", IDDQ_DESC_SIZE, l_line_str);

//    l_line_str_len = strlen(l_line_str)+ 2;
//    snprintf(l_buffer_str, l_line_str_len, "%-*s ", IDDQ_DESC_SIZE, l_line_str);
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

    // get average temperature measurements with all cores and caches OFF
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
} // end of  iddq_print


///////////////////////////////////////////////////////////
////////  get_mvpd_iddq
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::get_mvpd_iddq( void )
{

    uint8_t*        l_buffer_iq_c =  NULL;
    uint32_t        l_record = 0;
    uint32_t        l_bufferSize_iq  = IQ_BUFFER_ALLOC;


    // --------------------------------------------
    // Process IQ Keyword (IDDQ) Data
    // --------------------------------------------

    // set l_record to appropriate cprx record
    l_record = (uint32_t)fapi2::MVPD_RECORD_CRP0;

    //First read is to get size of vpd record, note the o_buffer is NULL
    FAPI_TRY( getMvpdField((fapi2::MvpdRecord)l_record,
                           fapi2::MVPD_KEYWORD_IQ,
                           iv_procChip,
                           NULL,
                           l_bufferSize_iq) );

    //Allocate memory for vpd data
    l_buffer_iq_c = reinterpret_cast<uint8_t*>(malloc(l_bufferSize_iq));

    // Get Chip IQ MVPD data from the CRPx records
    FAPI_TRY(getMvpdField((fapi2::MvpdRecord)l_record,
                          fapi2::MVPD_KEYWORD_IQ,
                          iv_procChip,
                          l_buffer_iq_c,
                          l_bufferSize_iq));

    //copy VPD data to IQ structure table
    memcpy(&iv_iddqt, l_buffer_iq_c, l_bufferSize_iq);

    //Verify Payload header data.
    if ( !(iv_iddqt.iddq_version) ||
         !(iv_iddqt.good_quads_per_sort) ||
         !(iv_iddqt.good_normal_cores_per_sort) ||
         !(iv_iddqt.good_caches_per_sort))
    {
        iv_wof_enabled = false;
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::PSTATE_PB_IQ_VPD_ERROR(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                           .set_CHIP_TARGET(iv_procChip)
                           .set_VERSION(iv_iddqt.iddq_version)
                           .set_GOOD_QUADS_PER_SORT(iv_iddqt.good_quads_per_sort)
                           .set_GOOD_NORMAL_CORES_PER_SORT(iv_iddqt.good_normal_cores_per_sort)
                           .set_GOOD_CACHES_PER_SORT(iv_iddqt.good_caches_per_sort),
                           "Pstate Parameter Block IQ Payload data error being logged");
        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    }

    //Verify ivdd_all_cores_off_caches_off has MSB bit is set
    //if yes then initialized to 0
    for (int i = 0; i < IDDQ_MEASUREMENTS; ++i)
    {
       if ( iv_iddqt.ivdd_all_cores_off_caches_off[i] & 0x8000)
       {
           iv_iddqt.ivdd_all_cores_off_caches_off[i] = 0;
       }
    }
    // Put out the structure to the trace
    iddq_print(&iv_iddqt);

fapi_try_exit:

    // Free up memory buffer
    free(l_buffer_iq_c);

    if (fapi2::current_err != fapi2::FAPI2_RC_SUCCESS)
    {
        iv_wof_enabled = false;
    }

    return fapi2::current_err;
} // end of get_mvpd_iddq


///////////////////////////////////////////////////////////
////////  load_mvpd_operating_point
///////////////////////////////////////////////////////////
void PlatPmPPB::load_mvpd_operating_point (vpd_type i_type)
{
    FAPI_DBG(">> load_mvpd_operating_point");
    const uint8_t pv_op_order[NUM_OP_POINTS] = VPD_PV_ORDER;


    if (i_type == RAW)
    {
        for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
        {
            iv_raw_vpd_pts[i].frequency_mhz  = (iv_attr_mvpd_poundV_raw[pv_op_order[i]].frequency_mhz);
            iv_raw_vpd_pts[i].vdd_mv         = (iv_attr_mvpd_poundV_raw[pv_op_order[i]].vdd_mv);
            iv_raw_vpd_pts[i].idd_100ma      = (iv_attr_mvpd_poundV_raw[pv_op_order[i]].idd_100ma);
            iv_raw_vpd_pts[i].vcs_mv         = (iv_attr_mvpd_poundV_raw[pv_op_order[i]].vcs_mv);
            iv_raw_vpd_pts[i].ics_100ma      = (iv_attr_mvpd_poundV_raw[pv_op_order[i]].ics_100ma);
            iv_raw_vpd_pts[i].pstate = (iv_attr_mvpd_poundV_raw[ULTRA].frequency_mhz -
            iv_attr_mvpd_poundV_raw[pv_op_order[i]].frequency_mhz) * 1000 / (iv_frequency_step_khz);
            FAPI_INF("PSTATE %x %x %d",iv_attr_mvpd_poundV_raw[ULTRA].frequency_mhz,iv_attr_mvpd_poundV_raw[pv_op_order[i]].frequency_mhz,iv_raw_vpd_pts[i].pstate);
        }
    }
    if (i_type == BIASED)
    {
        for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
        {
            iv_biased_vpd_pts[i].frequency_mhz  = (iv_attr_mvpd_poundV_biased[pv_op_order[i]].frequency_mhz);
            iv_biased_vpd_pts[i].vdd_mv         = (iv_attr_mvpd_poundV_biased[pv_op_order[i]].vdd_mv);
            iv_biased_vpd_pts[i].idd_100ma      = (iv_attr_mvpd_poundV_biased[pv_op_order[i]].idd_100ma);
            iv_biased_vpd_pts[i].vcs_mv         = (iv_attr_mvpd_poundV_biased[pv_op_order[i]].vcs_mv);
            iv_biased_vpd_pts[i].ics_100ma      = (iv_attr_mvpd_poundV_biased[pv_op_order[i]].ics_100ma);
            iv_biased_vpd_pts[i].pstate = (iv_attr_mvpd_poundV_biased[ULTRA].frequency_mhz -
            iv_attr_mvpd_poundV_biased[pv_op_order[i]].frequency_mhz) * 1000 / (iv_frequency_step_khz);
        }
    }

    FAPI_DBG("<< load_mvpd_operating_point");
} //end of load_mvpd_operating_point


///////////////////////////////////////////////////////////
////////  vpd_init
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::vpd_init( void )
{
    FAPI_INF(">>>>>>>>>> vpd_init");
    fapi2::ReturnCode l_rc;
    do
    {
        memset (&iv_raw_vpd_pts, 0, sizeof(iv_raw_vpd_pts));
        memset (&iv_biased_vpd_pts, 0, sizeof(iv_biased_vpd_pts));
        memset (&iv_poundW_data, 0, sizeof(iv_poundW_data));
        memset (&iv_iddqt, 0, sizeof(iv_iddqt));
        memset (iv_operating_points,0,sizeof(iv_operating_points));
        memset (&iv_attr_mvpd_poundV_raw, 0, sizeof(iv_attr_mvpd_poundV_raw));
        memset (&iv_attr_mvpd_poundV_biased, 0, sizeof(iv_attr_mvpd_poundV_biased));

        //Read #V data
        FAPI_TRY(get_mvpd_poundV(),
                 "get_mvpd_poundV function failed to retrieve pound V data");


        if (!iv_eq_chiplet_state)
        {
            break;
        }
        // Apply biased values if any
        //
        FAPI_IMP("Apply Biasing to #V");
        FAPI_TRY(apply_biased_values(),"apply_biased_values function failed");

        //Read #W data

        // ----------------
        // get VDM Parameters data
        // ----------------
        // Note:  the get_mvpd_poundW has the conditional checking for VDM
        // and WOF enablement as #W has both VDM and WOF content
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

        //Read #IQ data

        //if wof is disabled.. don't call IQ function
        if (is_wof_enabled())
        {
            // ----------------
            // get IQ (IDDQ) data
            // ----------------
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

        FAPI_INF("Load RAW VPD");
        load_mvpd_operating_point(RAW);

        FAPI_INF("Load VPD");
        // VPD operating point
        load_mvpd_operating_point(BIASED);

    }while(0);

    FAPI_INF("<<<<<<<<< vpd_init");

fapi_try_exit:
    return fapi2::current_err;

} // end of vpd_init

///////////////////////////////////////////////////////////
////////  is_wov_underv_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wov_underv_enabled()
{
    return(!(iv_attrs.attr_wov_underv_disable) &&
         iv_wov_underv_enabled)
         ? true : false;
}

///--------------------------------------
///////////////////////////////////////////////////////////
//////// is_wov_overv_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wov_overv_enabled()
{
    return (!(iv_attrs.attr_wov_overv_disable) &&
         iv_wov_overv_enabled)
         ? true : false;
}

///////////////////////////////////////////////////////////
////////  is_wof_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_wof_enabled()
{
    uint8_t attr_dd_wof_not_supported;
    uint8_t attr_system_wof_disable;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_DISABLE, FAPI_SYSTEM, attr_system_wof_disable);
    FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_WOF_NOT_SUPPORTED, iv_procChip, attr_dd_wof_not_supported);

    return
        (!(attr_system_wof_disable) &&
         !(attr_dd_wof_not_supported) &&
         iv_wof_enabled)
        ? true : false;
} //end of is_wof_enabled

///////////////////////////////////////////////////////////
////////   is_vdm_enabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::is_vdm_enabled()
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    uint8_t attr_dd_vdm_not_supported;
    uint8_t attr_system_vdm_disable;

    FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_VDM_DISABLE, FAPI_SYSTEM, attr_system_vdm_disable);
    FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_VDM_NOT_SUPPORTED, iv_procChip, attr_dd_vdm_not_supported);

    return
        (!(attr_system_vdm_disable) &&
         !(attr_dd_vdm_not_supported) &&
         iv_vdm_enabled)
         ? true : false;
} // end of is_vdm_enabled


///////////////////////////////////////////////////////////
////////   isPstateModeEnabled
///////////////////////////////////////////////////////////
bool PlatPmPPB::isPstateModeEnabled()
{
    return((iv_attrs.attr_pstate_mode == fapi2::ENUM_ATTR_SYSTEM_PSTATES_MODE_OFF) ?
            true : false);
} //end of isPstateModeEnabled


///////////////////////////////////////////////////////////
////////   isEqChipletPresent
///////////////////////////////////////////////////////////
bool PlatPmPPB::isEqChipletPresent ()
{
    return iv_eq_chiplet_state;
} //end of isEqChipletPresent


///////////////////////////////////////////////////////////
////////   large_jump_interpolate
///////////////////////////////////////////////////////////
uint32_t PlatPmPPB::large_jump_interpolate(const Pstate i_pstate,
            const Pstate i_ps_pstate)
{

    uint8_t l_jump_value_set_ps  =
        iv_poundW_data.poundw[POWERSAVE].vdm_normal_freq_drop & 0x0F;
    uint8_t l_jump_value_set_nom =
        iv_poundW_data.poundw[NOMINAL].vdm_normal_freq_drop & 0x0F;

    uint32_t l_slope_value =
        compute_slope_thresh(l_jump_value_set_nom,
                l_jump_value_set_ps,
                iv_operating_points[VPD_PT_SET_BIASED][POWERSAVE].pstate,
                iv_operating_points[VPD_PT_SET_BIASED][NOMINAL].pstate);

    uint32_t l_vdm_jump_value =
        (uint32_t)((int32_t)l_jump_value_set_ps + (((int32_t)l_slope_value *
                        (i_ps_pstate - i_pstate)) >> THRESH_SLOPE_FP_SHIFT));
    return l_vdm_jump_value;
} //end of large_jump_interpolate


///////////////////////////////////////////////////////////
////////   get_pstate_attrs
///////////////////////////////////////////////////////////
void PlatPmPPB::get_pstate_attrs(AttributeList *o_attr)
{
    memcpy(o_attr,&iv_attrs, sizeof(iv_attrs));
} // end of get_pstate_attrs


///////////////////////////////////////////////////////////
////////    compute_boot_safe
///////////////////////////////////////////////////////////
fapi2::ReturnCode PlatPmPPB::compute_boot_safe(
                  const VoltageConfigActions_t i_action)
{
    fapi2::ReturnCode l_rc;

    iv_pstates_enabled = true;
    iv_resclk_enabled  = true;
    iv_vdm_enabled     = true;
    iv_ivrm_enabled    = true;
    iv_wof_enabled     = false;

    do
    {

        //We only wish to compute voltage setting defaults if the action
        //inputed to the HWP tells us to
        if(i_action == COMPUTE_VOLTAGE_SETTINGS)
        {

            // query VPD if any of the voltage attributes are zero
            if (!iv_attrs.vdd_voltage_mv ||
                !iv_attrs.vcs_voltage_mv ||
                !iv_attrs.vdn_voltage_mv)
            {
                // ----------------
                // get VPD data (#V,#W)
                // ----------------

                FAPI_TRY(vpd_init(),"vpd_init function failed");

                if (!isEqChipletPresent())
                {
                    FAPI_IMP("**** WARNING : There are no EQ chiplets present which means there is no valid #V VPD");
                    FAPI_IMP("**** WARNING : Pstates and all related functions will NOT be enabled.");

                    break;
                }

                // Compute the VPD operating points
                compute_vpd_pts();

                FAPI_TRY(safe_mode_init());


                // set VDD voltage to PowerSave Voltage from MVPD data (if no override)
                if (iv_attrs.vdd_voltage_mv)
                {
                    FAPI_INF("VDD boot voltage override set.");
                }
                else
                {
//                    iv_attrs.vdd_voltage_mv = l_safe_mode_values.boot_mode_mv;
                    FAPI_INF("VDD boot voltage set to %d mV.", iv_attrs.vdd_voltage_mv);
                }



                // set VCS voltage to UltraTurbo Voltage from MVPD data (if no override)
                if (iv_attrs.vcs_voltage_mv)
                {
                    FAPI_INF("VCS boot voltage override set.");
                }
                else
                {
                    FAPI_INF("VCS boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t l_int_vcs_mv = (iv_attr_mvpd_poundV_biased[POWERSAVE].vcs_mv);
                    uint32_t l_ics_ma = (iv_attr_mvpd_poundV_biased[POWERSAVE].ics_100ma) * 100;

                    uint32_t l_ext_vcs_mv = sysparm_uplift(l_int_vcs_mv,
                            l_ics_ma,
                            revle32(iv_attrs.r_loadline_vcs_uohm),
                            revle32(iv_attrs.r_distloss_vcs_uohm),
                            revle32(iv_attrs.vrm_voffset_vcs_uv));


                    FAPI_INF("VCS VPD voltage %d mV; Corrected voltage: %d mV; ICS: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                            l_int_vcs_mv,
                            (l_ext_vcs_mv),
                            l_ics_ma,
                            revle32(iv_attrs.r_loadline_vcs_uohm),
                            revle32(iv_attrs.r_distloss_vcs_uohm),
                            revle32(iv_attrs.vrm_voffset_vcs_uv));


                    iv_attrs.vcs_voltage_mv = (l_ext_vcs_mv);

                }

                // set VDN voltage to PowerSave Voltage from MVPD data (if no override)
                if (iv_attrs.vdn_voltage_mv)
                {
                    FAPI_INF("VDN boot voltage override set");
                }
                else
                {
                    FAPI_INF("VDN boot voltage override not set, using VPD value and correcting for applicable load line setting");
                    uint32_t l_int_vdn_mv = (iv_attr_mvpd_poundV_biased[POWERBUS].vdd_mv);
                    uint32_t l_idn_ma = (iv_attr_mvpd_poundV_biased[POWERBUS].idd_100ma) * 100;
                    // Returns revle32
                    uint32_t l_ext_vdn_mv = sysparm_uplift(l_int_vdn_mv,
                            l_idn_ma,
                            revle32(iv_attrs.r_loadline_vdn_uohm),
                            revle32(iv_attrs.r_distloss_vdn_uohm),
                            revle32(iv_attrs.vrm_voffset_vdn_uv));

                    FAPI_INF("VDN VPD voltage %d mV; Corrected voltage: %d mV; IDN: %d mA; LoadLine: %d uOhm; DistLoss: %d uOhm;  Offst: %d uOhm",
                            l_int_vdn_mv,
                            (l_ext_vdn_mv),
                            l_idn_ma,
                            revle32(iv_attrs.r_loadline_vdn_uohm),
                            revle32(iv_attrs.r_distloss_vdn_uohm),
                            revle32(iv_attrs.vrm_voffset_vdn_uv));

                    iv_attrs.vdn_voltage_mv = (l_ext_vdn_mv);
                }
            }
            else
            {
                FAPI_INF("Using overrides for all boot voltages (VDD/VCS/VDN) and core frequency");

                // Set safe frequency to the default BOOT_FREQ_MULT
                fapi2::ATTR_BOOT_FREQ_MULT_Type l_boot_freq_mult;
                FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_BOOT_FREQ_MULT,
                                        iv_procChip,
                                        l_boot_freq_mult));

                uint32_t l_boot_freq_mhz =
                    ((l_boot_freq_mult * iv_attrs.freq_proc_refclock_khz ) /
                     iv_attrs.proc_dpll_divider )
                    / 1000;



                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_FREQUENCY_MHZ,
                                       iv_procChip,
                                       l_boot_freq_mhz));
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_SAFE_MODE_VOLTAGE_MV,
                                       iv_procChip,
                                       (iv_attrs.vdd_voltage_mv)));
                FAPI_INF("Safe mode Frequency = %d MHz (0x%x), Safe mode voltage = %d mV (0x%x)",
                         l_boot_freq_mhz, l_boot_freq_mhz,
                         (iv_attrs.vdd_voltage_mv), (iv_attrs.vdd_voltage_mv));
            }

            FAPI_INF("Setting Boot Voltage attributes: VDD = %dmV; VCS = %dmV; VDN = %dmV",
                     (iv_attrs.vdd_voltage_mv), (iv_attrs.vcs_voltage_mv), (iv_attrs.vdn_voltage_mv));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VDD_BOOT_VOLTAGE, iv_procChip, (iv_attrs.vdd_voltage_mv)),
                     "Error from FAPI_ATTR_SET (ATTR_VDD_BOOT_VOLTAGE)");
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VCS_BOOT_VOLTAGE, iv_procChip, (iv_attrs.vcs_voltage_mv)),
                     "Error from FAPI_ATTR_SET (ATTR_VCS_BOOT_VOLTAGE)");
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_VDN_BOOT_VOLTAGE, iv_procChip, (iv_attrs.vdn_voltage_mv)),
                     "Error from FAPI_ATTR_SET (ATTR_VDN_BOOT_VOLTAGE)");
        }  // COMPUTE_VOLTAGE_SETTINGS
    }
    while(0);

    // trace values to be used
    FAPI_INF("VDD boot voltage = %d mV (0x%x)",
             (iv_attrs.vdd_voltage_mv), (iv_attrs.vdd_voltage_mv));
    FAPI_INF("VCS boot voltage = %d mV (0x%x)",
             (iv_attrs.vcs_voltage_mv), (iv_attrs.vcs_voltage_mv));
    FAPI_INF("VDN boot voltage = %d mV (0x%x)",
             (iv_attrs.vdn_voltage_mv), (iv_attrs.vdn_voltage_mv));

fapi_try_exit:
    return fapi2::current_err;
} // end of compute_boot_safe

// Note: the caller to this macro function should make sure that the buffer _buffer
//  should be large enough.
// the length for _l_str_len (with _variable) is added by 4: 
// 3 for 3 spaces in format " %*s%*s  ";
// another 1 for terminating null.
#define CENTER_STR(_buffer, _variable, _width)                  \
   {                                                            \
       int _w_ = _width-strlen(_variable)/2;                    \
       int _l_str_len = ((_w_ + strlen(_variable) + _w_) + 4);  \
       snprintf(_buffer, _l_str_len, " %*s%*s  ", _w_, _variable, _w_, "");            \
   }

#define HEX_DEC_STR(_buffer, _hex, _dec)                        \
   {                                                            \
       char _temp_buffer[64];                                   \
       sprintf(_temp_buffer, " %04X (%4d) ", _dec, _hex);       \
       strcat(_buffer, _temp_buffer);                           \
   }


///////////////////////////////////////////////////////////
////////    gppb_print
///////////////////////////////////////////////////////////
fapi2::ReturnCode gppb_print(GlobalPstateParmBlock* i_gppb, const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target )
{
    static const uint32_t   BUFFSIZE = 512;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];
    char                    l_temp_buffer1[BUFFSIZE];
    const char*     pv_op_str[NUM_OP_POINTS] = PV_OP_ORDER_STR;
    const char*     thresh_op_str[NUM_THRESHOLD_POINTS] = VPD_THRESHOLD_ORDER_STR;
    const char*     slope_region_str[VPD_NUM_SLOPES_REGION] = VPD_OP_SLOPES_REGION_ORDER_STR;
    auto  l_eqChiplets  =   i_target.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_FUNCTIONAL);
    uint8_t eqPos       =   0;
    int l_len           =   strlen(l_buffer);
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

    for( auto eq  : l_eqChiplets )
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, eq, eqPos ));
        strcpy(l_buffer,"");
        strcpy(l_temp_buffer, "");

        //FIXME avoiding changes in GPSPB to address compatibility issues between
        //hardware image and HWP
        for (auto i = 0; i < NUM_OP_POINTS; ++i)
        {
            //sprintf (l_buffer, "Q[%d]  %-16s :  %02X ", eqPos, pv_op_str[i], i_gppb->vid_point_set[eqPos][i]);
            //FAPI_INF("%s", l_buffer);
        }

        for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
        {
            //sprintf(l_temp_buffer1, "%04X",
            //        revle16(i_gppb->PsVIDCompSlopes[eqPos][j]));
            //CENTER_STR(l_temp_buffer, l_temp_buffer1, 8);
            //strcat(l_buffer, l_temp_buffer);
        }

        //FAPI_INF("%s", l_buffer);
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
    for (auto j = 0; j < VPD_NUM_SLOPES_REGION; ++j)
    {
        sprintf(l_temp_buffer1, "%s", prt_region_names[j]);
        CENTER_STR(l_temp_buffer, l_temp_buffer1, 8);
        strcat(l_buffer, l_temp_buffer);
    }
    FAPI_INF("%s", l_buffer);

    sprintf( l_buffer,  "%*s", l_len+6," ");

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
fapi_try_exit:
    return fapi2::current_err;
} // end of gppb_print


///////////////////////////////////////////////////////////
////////    oppb_print
///////////////////////////////////////////////////////////
void oppb_print(OCCPstateParmBlock* i_oppb)
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
             revle32(i_oppb->nest_frequency_mhz),
             revle32(i_oppb->nest_frequency_mhz));

    FAPI_INF("Nest Leakage Percent:        %02X (%3d)",
             revle16(i_oppb->nest_leakage_percent),
             revle16(i_oppb->nest_leakage_percent));

    FAPI_INF("Ceff TDP Vdn:                %02X (%3d)",
             revle16(i_oppb->ceff_tdp_vdn),
             revle16(i_oppb->ceff_tdp_vdn));

    FAPI_INF("Iac TDP VDD Turbo(10ma):     %02X (%3d)",
             revle16(i_oppb->lac_tdp_vdd_turbo_10ma),
             revle16(i_oppb->lac_tdp_vdd_turbo_10ma));

    FAPI_INF("Iac TDP VDD Nominal(10ma):   %02X (%3d)",
             revle16(i_oppb->lac_tdp_vdd_nominal_10ma),
             revle16(i_oppb->lac_tdp_vdd_nominal_10ma));

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
} // end of oppb_print

// *INDENT-ON*
