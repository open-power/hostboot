/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_pm_utils.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2025                        */
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
/// @file  p10_utils.C
/// @brief General utility functions
///
/// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner         : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *Team                 : PM
/// *Consumed by          : HB:CRO
///

#include <fapi2.H>
#include <pstates_common.H>
#include <p10_pm_utils.H>
#include <stdint.h>

// Byte-reverse a 16-bit integer if on a little-endian machine
uint16_t
revle16(const uint16_t i_x)
{
    uint16_t rx;

#ifndef _BIG_ENDIAN
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    *(prx + 0) = *(pix + 1);
    *(prx + 1) = *(pix + 0);
#else
    rx = i_x;
#endif

    return rx;
}


// Byte-reverse a 32-bit integer if on a little-endian machine
uint32_t
revle32(const uint32_t i_x)
{
    uint32_t rx;

#ifndef _BIG_ENDIAN
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    *(prx + 0) = *(pix + 3);
    *(prx + 1) = *(pix + 2);
    *(prx + 2) = *(pix + 1);
    *(prx + 3) = *(pix + 0);
#else
    rx = i_x;
#endif

    return rx;
}


// Byte-reverse a 64-bit integer if on a little-endian machine
uint64_t
revle64(const uint64_t i_x)
{
    uint64_t rx;

#ifndef _BIG_ENDIAN
    uint8_t* pix = (uint8_t*)(&i_x);
    uint8_t* prx = (uint8_t*)(&rx);

    *(prx + 0) = *(pix + 7);
    *(prx + 1) = *(pix + 6);
    *(prx + 2) = *(pix + 5);
    *(prx + 3) = *(pix + 4);
    *(prx + 4) = *(pix + 3);
    *(prx + 5) = *(pix + 2);
    *(prx + 6) = *(pix + 1);
    *(prx + 7) = *(pix + 0);
#else
    rx = i_x;
#endif

    return rx;
}


#define BIAS_PCT_UNIT  0.5
/// -----------------------------------------------------------------------
/// @brief Compute bias value for pre-defined percentage unit
/// @param[in]     i_value Biased value
/// @return bias value
/// -----------------------------------------------------------------------
double calc_bias(const int8_t i_value)
{
    double temp = 1.0 + ((BIAS_PCT_UNIT / 100) * static_cast<double>(i_value));
    FAPI_DBG("    calc_bias: input bias (in 1/2 percent) = %d; percent = %4.1f biased multiplier = %6.3f",
             i_value, (i_value * BIAS_PCT_UNIT), temp);
    return temp;
}

/// -----------------------------------------------------------------------
/// @brief Compute smallest value for a given input
/// @param[in]     x value
/// @return smallest value
/// -----------------------------------------------------------------------
double internal_ceil(double x)
{
    if ((x - static_cast<int>(x)) > 0)
    {
        return static_cast<int>(x) + 1;
    }

    return (static_cast<int>(x));
}

/// -----------------------------------------------------------------------
/// @brief Compute largest value for a given input
/// @param[in]     x value
/// @return largest value
/// -----------------------------------------------------------------------
double internal_floor(double x)
{
    if(x >= 0)
    {
        return static_cast<int>(x);
    }

    return static_cast<int>(x - 0.9999999999999999);
}

/// -----------------------------------------------------------------------
/// @brief Compute the rounded value for a given input
/// @param[in]     x value
/// @return rounded value
/// -----------------------------------------------------------------------
double internal_round(double x)
{

    if(x >= 0)
    {
        return static_cast<int>(x + 0.5);
    }

    return static_cast<int>(x - 0.5 - 0.9999999999999999);
}

/// -----------------------------------------------------------------------
/// @brief Adjust bias value for given frequency value
/// @param[in]     i_value  frequency value
/// @param[in]     i_bias_0p5pct  bias value
/// @return computed biase value
/// -----------------------------------------------------------------------
uint32_t bias_adjust_mhz(const uint32_t i_value,
                         const int32_t  i_bias_0p5pct)
{
    double l_mult = calc_bias(i_bias_0p5pct);
    double l_biased_value = static_cast<double>(i_value) * l_mult;
    FAPI_DBG("  bias_adjust_mhz: i_value=%d; mult=%5.3f; biased value=%3.0f",
             i_value,
             l_mult,
             l_biased_value);
    return (static_cast<uint32_t>(internal_floor(l_biased_value)));
}

/// -----------------------------------------------------------------------
/// @brief Adjust bias value for given vdd/vcs voltage
/// @param[in]     i_value vdd/vcs value
/// @param[in]     i_bias_0p5pct  bias value
/// @return computed biase value
/// -----------------------------------------------------------------------
uint32_t bias_adjust_mv(const uint32_t i_value,
                        const int8_t i_bias_0p5pct)
{
    double l_mult = calc_bias(i_bias_0p5pct);
    double l_biased_value = static_cast<double>(i_value) * l_mult;
    double l_ceiling = internal_ceil(l_biased_value);
    uint32_t l_result = static_cast<uint32_t>(l_ceiling);
    FAPI_DBG("  bias_adjust_mv:  i_value=%d; mult=%5.3f; biased value=%3.0f ceiling = %3.0f result = %d",
             i_value,
             l_mult,
             l_biased_value,
             l_ceiling,
             l_result);
    return (l_result);
}

#ifndef FIPSODE
///////////////////////////////////////////////////////////
//////// wof_get_tables
///////////////////////////////////////////////////////////
fapi2::ReturnCode wof_get_tables(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::ATTR_WOF_TABLE_DATA_Type* i_wof_table_data)
{
#define __WOF_INTERNAL_HEADER__
#define __WOF_INTERNAL_DATA__
#include <p10_pstate_parameter_block_int_vpd.H>
#undef __WOF_INTERNAL_HEADER__
#undef __WOF_INTERNAL_DATA__

    FAPI_INF(">> WOF get tables");

    fapi2::ReturnCode l_rc = 0;
    uint16_t l_vdd_size     = 0;
    uint16_t l_vcs_size     = 0;
    uint16_t l_io_size      = 0;
    uint16_t l_ac_size      = 0;

    VRT_t l_vrt;
    memset (&l_vrt, 0, sizeof(l_vrt));

    do
    {
        FAPI_DBG("i_wof_table_data  addr = %p size = %d",
                 i_wof_table_data, sizeof(fapi2::ATTR_WOF_TABLE_DATA_Type));

        // If this attribute is set, fill in i_wof_table_data with the VRT data
        // from the internal, static table.
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_SYS_VRT_STATIC_DATA_ENABLE_Type l_sys_vrt_static_data = 0;
        FAPI_ATTR_GET(fapi2::ATTR_SYS_VRT_STATIC_DATA_ENABLE,
                      FAPI_SYSTEM,
                      l_sys_vrt_static_data);

        if (l_sys_vrt_static_data)
        {
            FAPI_INF("ATTR_SYS_VRT_STATIC_DATA_ENABLE is SET");

            // Copy base WOF header data
            memcpy (i_wof_table_data, &g_wofData, sizeof(WofTablesHeader_t));
            uint32_t l_index = sizeof(WofTablesHeader_t);

            FAPI_DBG("Static WOF Table Header size: %d", sizeof(WofTablesHeader_t));

            uint64_t* ptr = (uint64_t*) i_wof_table_data;

            for (auto x = 0; x < 8; ++x)
            {

                FAPI_INF("Raw wof_table_data (may be big or little endian based on platform) @  offset  %02d = %016llX", x, *ptr);
                ptr++;
            }

            WofTablesHeader_t* p_wfth;
            p_wfth = reinterpret_cast<WofTablesHeader_t*>(i_wof_table_data);
            FAPI_INF("WFTH: %X", revle32(p_wfth->magic_number.value));

            // Set some defaults into the header
            p_wfth->header_version = 2;
            p_wfth->sys_flags =  0x54;   // Blueridge-2U, Extended frequency
            p_wfth->max_powr_min_freq_watts =  200;   // Made up number

            strcpy(p_wfth->table_version, "v9.9.9");
            strcpy(p_wfth->package_name,  "DCM");

            FAPI_INF("before l_vcs_start %d (0x%X) l_vdd_start %d (0x%X) l_io_start %d (0x%X) l_ac_start %d (0x%X) ",
                     revle16(p_wfth->vcs_start),
                     revle16(p_wfth->vcs_start),
                     revle16(p_wfth->vdd_start),
                     revle16(p_wfth->vdd_start),
                     revle16(p_wfth->io_start),
                     revle16(p_wfth->io_start),
                     revle16(p_wfth->amb_cond_start),
                     revle16(p_wfth->amb_cond_start) );

            FAPI_INF("before l_vcs_size %d (0x%X) l_vdd_size %d (0x%X) l_io_size %d (0x%X) l_ac_size %d (0x%X) ",
                     revle16(p_wfth->vcs_size),
                     revle16(p_wfth->vcs_size),
                     revle16(p_wfth->vdd_size),
                     revle16(p_wfth->vdd_size),
                     revle16(p_wfth->io_size),
                     revle16(p_wfth->io_size),
                     revle16(p_wfth->amb_cond_size),
                     revle16(p_wfth->amb_cond_size) );

            FAPI_INF("before l_vcs_step %d (0x%X) l_vdd_step %d (0x%X) l_io_step %d (0x%X) l_ac_step %d (0x%X) ",
                     revle16(p_wfth->vcs_step),
                     revle16(p_wfth->vcs_step),
                     revle16(p_wfth->vdd_step),
                     revle16(p_wfth->vdd_step),
                     revle16(p_wfth->io_step),
                     revle16(p_wfth->io_step),
                     revle16(p_wfth->amb_cond_step),
                     revle16(p_wfth->amb_cond_step) );

            l_vcs_size = revle16(p_wfth->vcs_size);
            l_vdd_size = revle16(p_wfth->vdd_size);
            l_io_size  = revle16(p_wfth->io_size);
            l_ac_size  = revle16(p_wfth->amb_cond_size);

            //Sample VRT data
            l_vrt.vrtHeader.fields.marker  = 0x56; // "V"
            l_vrt.vrtHeader.fields.type    = 1;    // system
            l_vrt.vrtHeader.fields.content = 0;    // CeffRatio
            l_vrt.vrtHeader.fields.version = 0;    // 12 entry

            FAPI_INF("VRT default: l_vrt fields value 0x%08X marker %X type %d content %d io %02d ac %02d vc %02d vd %02d",
                     l_vrt.vrtHeader.value,
                     l_vrt.vrtHeader.fields.marker,
                     l_vrt.vrtHeader.fields.type,
                     l_vrt.vrtHeader.fields.content,
                     l_vrt.vrtHeader.fields.io_id,
                     l_vrt.vrtHeader.fields.ac_id,
                     l_vrt.vrtHeader.fields.vcs_ceff_id,
                     l_vrt.vrtHeader.fields.vdd_ceff_id
                    );

            for (auto i = 0; i < WOF_VRT_SIZE; ++i)
            {
                fapi2::ATTR_IS_IBM_SIMULATION_Type is_sim;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_IBM_SIMULATION, FAPI_SYSTEM, is_sim));

                if (is_sim)
                {
                    l_vrt.data[i] = g_static_vrt[i];
                }
                else
                {
                    l_vrt.data[i] = g_static_vrt_hw[i];
                }

                FAPI_INF("Static System VRT data[%02d] = 0x%X", i, l_vrt.data[i]);
            }

            for (uint32_t vcs = 0; vcs < l_vcs_size; ++vcs)
            {
                l_vrt.vrtHeader.fields.vcs_ceff_id = vcs;

                for (uint32_t vdd = 0; vdd < l_vdd_size; ++vdd)
                {
                    l_vrt.vrtHeader.fields.vdd_ceff_id = vdd;

                    for (uint32_t io = 0; io < l_io_size; ++io)
                    {
                        l_vrt.vrtHeader.fields.io_id = io;

                        for (uint32_t amb = 0; amb < l_ac_size; ++amb)
                        {
                            l_vrt.vrtHeader.fields.ac_id = amb;

                            // Store to structure in BE
                            l_vrt.vrtHeader.value = revle32(l_vrt.vrtHeader.value);
                            memcpy((*i_wof_table_data + l_index), &l_vrt, sizeof (l_vrt));
                            // Restore the fixed structure
                            l_vrt.vrtHeader.value = revle32(l_vrt.vrtHeader.value);

                            FAPI_DBG("VRT default: l_index 0x%X (%4u) l_vrt fields value 0x%08X marker %X type %d content %d io %02d ac %02d vc %02d vd %02d",
                                     l_index, l_index,
                                     l_vrt.vrtHeader.value,
                                     l_vrt.vrtHeader.fields.marker,
                                     l_vrt.vrtHeader.fields.type,
                                     l_vrt.vrtHeader.fields.content,
                                     l_vrt.vrtHeader.fields.io_id,
                                     l_vrt.vrtHeader.fields.ac_id,
                                     l_vrt.vrtHeader.fields.vcs_ceff_id,
                                     l_vrt.vrtHeader.fields.vdd_ceff_id
                                    );

                            l_index += sizeof (l_vrt);
                        }
                    }
                }
            }
        }
        else
        {
            FAPI_DBG("ATTR_SYS_VRT_STATIC_DATA_ENABLE is not SET");

            // Read System VRT data
            l_rc = FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_DATA,
                                 i_proc_target,
                                 (*i_wof_table_data));

            if (l_rc)
            {

                FAPI_INF("ATTR_WOF_TABLE_DATA attribute failed.  Disabling WOF");
                fapi2::ATTR_WOF_ENABLED_Type l_wof_disabled = fapi2::ENUM_ATTR_WOF_ENABLED_FALSE;
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_ENABLED,
                                       i_proc_target,
                                       l_wof_disabled));

                // Write the returned error content to the error log
                fapi2::logError(l_rc, fapi2::FAPI2_ERRL_SEV_UNRECOVERABLE);
                break;
            }
        }
    }
    while(0);

fapi_try_exit:
    FAPI_INF("<< WOF get tables");
    return fapi2::current_err;
}

#define WTH_GET_ATTR_8_2(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, attr_assign),"Attribute read failed");\
    FAPI_INF("%-51s[0][0] = 0x%08x %d", #attr_name, attr_assign[0][0], attr_assign[0][0]); \
    FAPI_INF("%-51s[0][1] = 0x%08x %d", #attr_name, attr_assign[0][1], attr_assign[0][1]); \
    FAPI_INF("%-51s[1][0] = 0x%08x %d", #attr_name, attr_assign[1][0], attr_assign[1][0]); \
    FAPI_INF("%-51s[1][1] = 0x%08x %d", #attr_name, attr_assign[1][1], attr_assign[1][1]); \
    FAPI_INF("%-51s[2][0] = 0x%08x %d", #attr_name, attr_assign[2][0], attr_assign[2][0]); \
    FAPI_INF("%-51s[2][1] = 0x%08x %d", #attr_name, attr_assign[2][1], attr_assign[2][1]); \
    FAPI_INF("%-51s[3][0] = 0x%08x %d", #attr_name, attr_assign[3][0], attr_assign[3][0]); \
    FAPI_INF("%-51s[3][1] = 0x%08x %d", #attr_name, attr_assign[3][1], attr_assign[3][1]); \
    FAPI_INF("%-51s[4][0] = 0x%08x %d", #attr_name, attr_assign[4][0], attr_assign[4][0]); \
    FAPI_INF("%-51s[4][1] = 0x%08x %d", #attr_name, attr_assign[4][1], attr_assign[4][1]); \
    FAPI_INF("%-51s[5][0] = 0x%08x %d", #attr_name, attr_assign[5][0], attr_assign[5][0]); \
    FAPI_INF("%-51s[5][1] = 0x%08x %d", #attr_name, attr_assign[5][1], attr_assign[5][1]); \
    FAPI_INF("%-51s[6][0] = 0x%08x %d", #attr_name, attr_assign[6][0], attr_assign[6][0]); \
    FAPI_INF("%-51s[6][1] = 0x%08x %d", #attr_name, attr_assign[6][1], attr_assign[6][1]); \
    FAPI_INF("%-51s[7][0] = 0x%08x %d", #attr_name, attr_assign[7][0], attr_assign[7][0]); \
    FAPI_INF("%-51s[7][1] = 0x%08x %d", #attr_name, attr_assign[7][1], attr_assign[7][1]);

#define WTH_GET_ATTR_8_4(attr_name, target, attr_assign) \
    FAPI_TRY(FAPI_ATTR_GET(fapi2::attr_name, target, attr_assign),"Attribute read failed");\
    FAPI_INF("%-51s[0][0] = 0x%08x %d", #attr_name, attr_assign[0][0], attr_assign[0][0]); \
    FAPI_INF("%-51s[0][1] = 0x%08x %d", #attr_name, attr_assign[0][1], attr_assign[0][1]); \
    FAPI_INF("%-51s[0][2] = 0x%08x %d", #attr_name, attr_assign[0][2], attr_assign[0][2]); \
    FAPI_INF("%-51s[0][3] = 0x%08x %d", #attr_name, attr_assign[0][3], attr_assign[0][3]); \
    FAPI_INF("%-51s[1][0] = 0x%08x %d", #attr_name, attr_assign[1][0], attr_assign[1][0]); \
    FAPI_INF("%-51s[1][1] = 0x%08x %d", #attr_name, attr_assign[1][1], attr_assign[1][1]); \
    FAPI_INF("%-51s[1][2] = 0x%08x %d", #attr_name, attr_assign[1][2], attr_assign[1][2]); \
    FAPI_INF("%-51s[1][3] = 0x%08x %d", #attr_name, attr_assign[1][3], attr_assign[1][3]); \
    FAPI_INF("%-51s[2][0] = 0x%08x %d", #attr_name, attr_assign[2][0], attr_assign[2][0]); \
    FAPI_INF("%-51s[2][1] = 0x%08x %d", #attr_name, attr_assign[2][1], attr_assign[2][1]); \
    FAPI_INF("%-51s[2][2] = 0x%08x %d", #attr_name, attr_assign[2][2], attr_assign[2][2]); \
    FAPI_INF("%-51s[2][3] = 0x%08x %d", #attr_name, attr_assign[2][3], attr_assign[2][3]); \
    FAPI_INF("%-51s[3][0] = 0x%08x %d", #attr_name, attr_assign[3][0], attr_assign[3][0]); \
    FAPI_INF("%-51s[3][1] = 0x%08x %d", #attr_name, attr_assign[3][1], attr_assign[3][1]); \
    FAPI_INF("%-51s[3][2] = 0x%08x %d", #attr_name, attr_assign[3][2], attr_assign[3][2]); \
    FAPI_INF("%-51s[3][3] = 0x%08x %d", #attr_name, attr_assign[3][3], attr_assign[3][3]); \
    FAPI_INF("%-51s[4][0] = 0x%08x %d", #attr_name, attr_assign[4][0], attr_assign[4][0]); \
    FAPI_INF("%-51s[4][1] = 0x%08x %d", #attr_name, attr_assign[4][1], attr_assign[4][1]); \
    FAPI_INF("%-51s[4][2] = 0x%08x %d", #attr_name, attr_assign[4][2], attr_assign[4][2]); \
    FAPI_INF("%-51s[4][3] = 0x%08x %d", #attr_name, attr_assign[4][3], attr_assign[4][3]); \
    FAPI_INF("%-51s[5][0] = 0x%08x %d", #attr_name, attr_assign[5][0], attr_assign[5][0]); \
    FAPI_INF("%-51s[5][1] = 0x%08x %d", #attr_name, attr_assign[5][1], attr_assign[5][1]); \
    FAPI_INF("%-51s[5][2] = 0x%08x %d", #attr_name, attr_assign[5][2], attr_assign[5][2]); \
    FAPI_INF("%-51s[5][3] = 0x%08x %d", #attr_name, attr_assign[5][3], attr_assign[5][3]); \
    FAPI_INF("%-51s[6][0] = 0x%08x %d", #attr_name, attr_assign[6][0], attr_assign[6][0]); \
    FAPI_INF("%-51s[6][1] = 0x%08x %d", #attr_name, attr_assign[6][1], attr_assign[6][1]); \
    FAPI_INF("%-51s[6][2] = 0x%08x %d", #attr_name, attr_assign[6][2], attr_assign[6][2]); \
    FAPI_INF("%-51s[6][3] = 0x%08x %d", #attr_name, attr_assign[6][3], attr_assign[6][3]); \
    FAPI_INF("%-51s[7][0] = 0x%08x %d", #attr_name, attr_assign[7][0], attr_assign[7][0]); \
    FAPI_INF("%-51s[7][1] = 0x%08x %d", #attr_name, attr_assign[7][1], attr_assign[7][1]); \
    FAPI_INF("%-51s[7][2] = 0x%08x %d", #attr_name, attr_assign[7][2], attr_assign[7][2]); \
    FAPI_INF("%-51s[7][3] = 0x%08x %d", #attr_name, attr_assign[7][3], attr_assign[7][3]);

///////////////////////////////////////////////////////////
//////// wof_table_header_overrides
///////////////////////////////////////////////////////////
fapi2::ReturnCode wof_table_header_overrides(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::ATTR_WOF_TABLE_DATA_Type* i_wof_table_data,
    wth::ECOOverrideFlags* o_wth_override_flags)
{
    using namespace wth;

    FAPI_INF(">> WOF override tables");

    enum SYS_FLAGS_BITS
    {
        EFFIC_MODE_BIT     = 6,
        OCS_MODE_BIT       = 7,
    };

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    fapi2::ATTR_WTH_OVERRIDE_TEST_CORE_COUNT_Type l_cc_test;
    fapi2::ATTR_WTH_OVERRIDE_CORE_COUNT_INDEX_Type l_cci;
    fapi2::ATTR_WTH_OVERRIDE_CORE_COUNT_INDEX_ARRAY_Type l_core_count_index_arr;    // [8]
    fapi2::ATTR_WTH_OVERRIDE_EFFICIENCY_ALG_Type l_effic_alg;
    fapi2::ATTR_WTH_OVERRIDE_EFFICIENCY_IDLE_TIMES_Type  l_effic_idle_times;        // [8][2]
    fapi2::ATTR_WTH_OVERRIDE_EFFICIENCY_IDLE_THRESH_Type l_effic_idle_threshs;      // [8][2]
    fapi2::ATTR_WTH_OVERRIDE_EFFICIENCY_CEFF_ADJUST_Type l_effic_ceff_adj;          // [8][4]
    fapi2::ATTR_WTH_OVERRIDE_EFFICIENCY_FREQ_LIMITS_Type l_effic_freq_limits;       // [8][4]

    uint8_t  l_cc_value = 0;            ///< Core Count value to search for
    bool     b_scc_found = false;       ///< Flag that sore core count was found
    bool     b_alg_override = false;    ///< Flag indicating that an alg change is happening
    bool     b_alg_override_ok = false; ///<Flag indicating that an alg change is valid
    fapi2::buffer<uint8_t>  l_sys_flags_buf = 0;    ///< Buffer to do bit manipulations

    do
    {
        FAPI_DBG("i_wof_table_data  addr = %p size = %d",
                 i_wof_table_data, sizeof(fapi2::ATTR_WOF_TABLE_DATA_Type));

        const char* IDLE_TRANSITIONS_NAMES[] = IDLE_TRANSITIONS_NAMES_STR;
        const char* IDLE_MODES_NAMES[] = IDLE_MODES_STR;

        WofTablesHeader_t* p_wfth;
        p_wfth = reinterpret_cast<WofTablesHeader_t*>(i_wof_table_data);
        FAPI_INF("WFTH: %X", revle32(p_wfth->magic_number.value));

        // Get the test value of core count
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_WTH_OVERRIDE_TEST_CORE_COUNT,
                                FAPI_SYSTEM,
                                l_cc_test));

        // Use core test input if set
        if (l_cc_test)
        {
            l_cc_value = l_cc_test;
        }
        else
        {
            l_cc_value = p_wfth->core_count;
        }

        // Determine the WTH override index
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_WTH_OVERRIDE_CORE_COUNT_INDEX_ARRAY,
                                FAPI_SYSTEM,
                                l_core_count_index_arr));

        for (uint32_t i = 0; i < MAX_SORTS; ++i)
        {
            if (l_cc_value == l_core_count_index_arr[i])
            {
                l_cci = i;
                b_scc_found = true;
                FAPI_INF("WOF Table core count %u matches at override index %u",
                         p_wfth->core_count, l_cci);
                break;
            }
        }

        // Determine if a sort was found
        if (!b_scc_found)
        {
            FAPI_INF("No matching WOF Table attribute override found for core count %u",
                     p_wfth->core_count);
            break;
        }

        // Write out the index for use in marking the overrides in trace output
        FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_WTH_OVERRIDE_CORE_COUNT_INDEX,
                                FAPI_SYSTEM,
                                l_cci));

        // Get the override attributes
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_WTH_OVERRIDE_EFFICIENCY_ALG,
                                FAPI_SYSTEM,
                                l_effic_alg));
        WTH_GET_ATTR_8_2(ATTR_WTH_OVERRIDE_EFFICIENCY_IDLE_TIMES,
                         FAPI_SYSTEM,
                         l_effic_idle_times);
        WTH_GET_ATTR_8_2(ATTR_WTH_OVERRIDE_EFFICIENCY_IDLE_THRESH,
                         FAPI_SYSTEM,
                         l_effic_idle_threshs);
        WTH_GET_ATTR_8_4(ATTR_WTH_OVERRIDE_EFFICIENCY_CEFF_ADJUST,
                         FAPI_SYSTEM,
                         l_effic_ceff_adj);
        WTH_GET_ATTR_8_4(ATTR_WTH_OVERRIDE_EFFICIENCY_FREQ_LIMITS,
                         FAPI_SYSTEM,
                         l_effic_freq_limits);

        // Determine if there is an idle mode change happening
        l_sys_flags_buf = p_wfth->sys_flags;
        bool b_effic_alg = l_effic_alg ? true : false;

        if (l_sys_flags_buf.getBit(EFFIC_MODE_BIT) != b_effic_alg)
        {
            b_alg_override = true;
            FAPI_INF("Attempting override change of WTH Efficiency mode to %s",
                     IDLE_MODES_NAMES[l_effic_alg]);
        }

        // Check that if the Idle mode is changing, the times and thresholds
        // in the the attributes must be valid (eg not 0xFFFF)
        if (b_alg_override)
        {
            b_alg_override_ok = true;

            for (uint32_t s = 0; s < MAX_SORTS; ++s)
            {
                for (uint32_t t = 0; t < IDLE_TRANSITIONS; ++t)
                {
                    if (l_effic_idle_times[s][t] == 0xFFFF)
                    {
                        FAPI_ERR("Efficiency Idle Times override to %s mode for Sort Index %u, Transition %u FAILED.  Value must not be 0xFFFF",
                                 IDLE_TRANSITIONS_NAMES[l_effic_alg], s, t);
                        b_alg_override_ok = false;
                    }

                    if (l_effic_idle_threshs[s][t] == 0xFFFF)
                    {
                        FAPI_ERR("Efficiency Idle Threshold override to %s mode for Sort Index %u, Transition %u FAILED.  Value must not be 0xFFFF",
                                 IDLE_TRANSITIONS_NAMES[l_effic_alg], s, t);
                        b_alg_override_ok = false;
                    }
                }
            }

            if (b_alg_override && b_alg_override_ok)
            {
                FAPI_INF("Changing WTH Efficiency mode in current sysflags 0x%02X to %u",
                         p_wfth->sys_flags, l_effic_alg);

                if (l_sys_flags_buf.getBit(EFFIC_MODE_BIT))
                {
                    l_sys_flags_buf.setBit(EFFIC_MODE_BIT);
                }
                else
                {
                    l_sys_flags_buf.clearBit(EFFIC_MODE_BIT);
                }

                p_wfth->sys_flags = l_sys_flags_buf;
                FAPI_DBG("After changing WTH Efficiency mode sysflags 0x%02X",
                         p_wfth->sys_flags);
                o_wth_override_flags->set(wth::ALG, l_cci, 0xFF);
            }
        }

        // Macro to check for a valid 1B override
#define WTH_OVERRIDE_SET_1B(_m_member, _m_var, _m_flag, _m_sort, _m_index) \
    if (l_effic_##_m_var[_m_sort][_m_index] != 0xFF) \
    { \
        FAPI_INF("Overriding WTH field %s from 0x%02X to 0x%02X", \
                 #_m_member, p_wfth->_m_member, l_effic_##_m_var[_m_sort][_m_index]); \
        p_wfth->_m_member = l_effic_##_m_var[_m_sort][_m_index]; \
        o_wth_override_flags->set(_m_flag, _m_sort, _m_index); \
    }

        // Macro to check for a valid 2B override
#define WTH_OVERRIDE_SET_2B(_m_member, _m_var, _m_flag, _m_sort, _m_index) \
    if (l_effic_##_m_var[_m_sort][_m_index] != 0xFFFF) \
    { \
        FAPI_INF("Overriding WTH field %s from 0x%04X to 0x%04X", \
                 #_m_member, p_wfth->_m_member, l_effic_##_m_var[_m_sort][_m_index]); \
        p_wfth->_m_member = l_effic_##_m_var[_m_sort][_m_index]; \
        o_wth_override_flags->set(_m_flag, _m_sort, _m_index); \
    }

        WTH_OVERRIDE_SET_2B(eff_mode_idle_chip_entry_time, idle_times,   IDLE_TIME,   l_cci, ENTRY);
        WTH_OVERRIDE_SET_2B(eff_mode_idle_chip_exit_time,  idle_times,   IDLE_TIME,   l_cci, EXIT);
        WTH_OVERRIDE_SET_2B(eff_mode_idle_chip_entry_thld, idle_threshs, IDLE_THRESH, l_cci, ENTRY);
        WTH_OVERRIDE_SET_2B(eff_mode_idle_chip_exit_thld,  idle_threshs, IDLE_THRESH, l_cci, EXIT);

        WTH_OVERRIDE_SET_1B(bal_perf_ceff_pct, ceff_adj, CEFF_ADJ, l_cci, BALANCED_PERF);
        WTH_OVERRIDE_SET_1B(fav_perf_ceff_pct, ceff_adj, CEFF_ADJ, l_cci, FAVOR_PERF);
        WTH_OVERRIDE_SET_1B(fav_pow_ceff_pct,  ceff_adj, CEFF_ADJ, l_cci, FAVOR_POWER);
        WTH_OVERRIDE_SET_1B(non_det_ceff_pct,  ceff_adj, CEFF_ADJ, l_cci, NON_DETERM);

        WTH_OVERRIDE_SET_2B(bal_perf_freq_limit_mhz, freq_limits, FREQ_LIMIT, l_cci, BALANCED_PERF);
        WTH_OVERRIDE_SET_2B(fav_perf_freq_limit_mhz, freq_limits, FREQ_LIMIT, l_cci, FAVOR_PERF);
        WTH_OVERRIDE_SET_2B(fav_pow_freq_limit_mhz,  freq_limits, FREQ_LIMIT, l_cci, FAVOR_POWER);
        WTH_OVERRIDE_SET_2B(non_det_freq_limit_mhz,  freq_limits, FREQ_LIMIT, l_cci, NON_DETERM);

    }
    while(0);

    // Put out the WOF Table Header if there are any overrides
    if (o_wth_override_flags->are_any_set())
    {
        const char title[] = "* Overridden";
        wfth_print(i_proc_target, (WofTablesHeader_t*)i_wof_table_data, o_wth_override_flags, title);
    }

fapi_try_exit:
    FAPI_INF("<< WOF override tables");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////    wfth_print
///////////////////////////////////////////////////////////
void wfth_print(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    WofTablesHeader_t* i_wfth,
    wth::ECOOverrideFlags* i_wfth_override_flags,
    const char* i_title)
{
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_DBG("i_wfth  addr = %p size = %d",
             i_wfth, sizeof(fapi2::ATTR_WOF_TABLE_DATA_Type));

    // Put out the endian-corrected scalars

#define WFTH_PRINT8_h4_d1(_member) \
    FAPI_INF("%-35s = 0x%04X (%01d)", #_member, i_wfth->_member, i_wfth->_member);

#define WFTH_PRINT8_h4_d2(_member) \
    FAPI_INF("%-35s = 0x%04X (%02d)", #_member, i_wfth->_member, i_wfth->_member);

#define WFTH_PRINT8_h4_d3(_member) \
    FAPI_INF("%-35s = 0x%04X (%03d)", #_member, i_wfth->_member, i_wfth->_member);

#define WFTH_PRINT8_h4_d5(_member) \
    FAPI_INF("%-35s = 0x%04X (%05d)", #_member, i_wfth->_member, i_wfth->_member);

#define WFTH_PRINT8_h4_d5_FLAGS(_member, _flag, _sort, _element) \
    if (i_wfth_override_flags->get(_flag, _sort, _element)) \
    { \
        FAPI_INF("%-35s = 0x%04X (%05d) (*)", #_member, i_wfth->_member, i_wfth->_member); \
    } \
    else \
    { \
        FAPI_INF("%-35s = 0x%04X (%05d)", #_member, i_wfth->_member, i_wfth->_member); \
    }

#define WFTH_PRINT16_h4_d5(_member) \
    FAPI_INF("%-35s = 0x%04X (%05d)", #_member, revle16(i_wfth->_member), revle16(i_wfth->_member));

#define WFTH_PRINT16_h4_d5_FLAGS(_member, _flag, _sort, _element) \
    if (i_wfth_override_flags->get(_flag, _sort, _element)) \
    { \
        FAPI_INF("%-35s = 0x%04X (%05d) (*)", #_member, i_wfth->_member, i_wfth->_member); \
    } \
    else \
    { \
        FAPI_INF("%-35s = 0x%04X (%05d)", #_member, i_wfth->_member, i_wfth->_member); \
    }

#define WFTH_PRINT16_h8_d0(_member) \
    FAPI_INF("%-35s = 0x%08X", #_member, revle16(i_wfth->_member), revle16(i_wfth->_member));

#define WFTH_PRINT32(_member) \
    FAPI_INF("%-35s = 0x%0*X (%0*d)", #_member, revle32(i_wfth->_member), revle32(i_wfth->_member));

#define WFTH_PRINTS(_member, _member_str) \
    { \
        char l_temp[8]; \
        memcpy(&l_temp, i_wfth->_member, 4); \
        memcpy(&l_temp[4], "", 1); \
        FAPI_INF("%-35s = %s", #_member_str, l_temp); \
    }


    const uint32_t BUFFSIZE = 64;
    char  l_proc_str[BUFFSIZE];
    fapi2::toString(i_proc_target, l_proc_str, BUFFSIZE);

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("WOF Table Header - %s (%s)", l_proc_str, i_title);
    FAPI_INF("---------------------------------------------------------------------------------------");

    WFTH_PRINTS       (magic_number.text, magic_number );
    WFTH_PRINT8_h4_d3 (wov_credit_knob       );
    WFTH_PRINT8_h4_d1 (header_version        );
    WFTH_PRINT8_h4_d5 (vrt_block_size        );
    WFTH_PRINT8_h4_d5 (vrt_block_header_size );
    WFTH_PRINT8_h4_d5 (vrt_data_size         );
    WFTH_PRINT8_h4_d1 (sys_flags             );
    WFTH_PRINT8_h4_d2 (core_count            );
    WFTH_PRINT16_h4_d5(vcs_start             );
    WFTH_PRINT16_h4_d5(vcs_step              );
    WFTH_PRINT16_h4_d5(vcs_size              );
    WFTH_PRINT16_h4_d5(vdd_start             );
    WFTH_PRINT16_h4_d5(vdd_step              );
    WFTH_PRINT16_h4_d5(vdd_size              );
    WFTH_PRINT16_h4_d5(vratio_start          );
    WFTH_PRINT16_h4_d5(vratio_step           );
    WFTH_PRINT16_h4_d5(vratio_size           );
    WFTH_PRINT16_h4_d5(io_start              );
    WFTH_PRINT16_h4_d5(io_step               );
    WFTH_PRINT16_h4_d5(io_size               );
    WFTH_PRINT16_h4_d5(amb_cond_start        );
    WFTH_PRINT16_h4_d5(amb_cond_step         );
    WFTH_PRINT16_h4_d5(amb_cond_size         );
    WFTH_PRINT16_h4_d5(socket_power_w        );
    WFTH_PRINT16_h4_d5(sort_power_freq_mhz   );
    WFTH_PRINT16_h4_d5(rdp_current_a         );
    WFTH_PRINT16_h4_d5(boost_current_a       );
    WFTH_PRINT8_h4_d5 (vcs_tdp_ceff_indx     );
    WFTH_PRINT8_h4_d5 (vdd_tdp_ceff_indx     );
    WFTH_PRINT8_h4_d5 (io_tdp_pwr_indx       );
    WFTH_PRINT8_h4_d5 (amb_cond_tdp_indx     );
    WFTH_PRINT16_h4_d5(sort_throttle_freq_mhz);
//    WFTH_PRINT8_h4_d5(io_tdp_w);
//    WFTH_PRINT8_h4_d5(io_dis_w);
    WFTH_PRINT16_h4_d5(sort_ultraturbo_freq_mhz);
    WFTH_PRINT16_h8_d0(table_date_timestamp);
    WFTH_PRINT16_h4_d5(override_match_power_w);
    WFTH_PRINT16_h4_d5(override_match_freq_mhz);
//    WFTH_PRINTS       (table_version);  // Commented as contents can be terminating
//    WFTH_PRINTS       (package_name);   // Commented as contents can be terminating
    WFTH_PRINT8_h4_d1(cur_scale_pct[0]);
    WFTH_PRINT8_h4_d1(cur_scale_pct[1]);
    WFTH_PRINT8_h4_d1(cur_scale_pct[2]);
    WFTH_PRINT8_h4_d1(cur_scale_pct[3]);
    WFTH_PRINT8_h4_d1(cur_scale_pct[4]);
    WFTH_PRINT8_h4_d1(cur_scale_pct[5]);
    WFTH_PRINT8_h4_d1(cur_scale_pct[6]);
    WFTH_PRINT8_h4_d1(cur_scale_pct[7]);
    WFTH_PRINT16_h4_d5(sort_power_save_freq_mhz);
    WFTH_PRINT16_h4_d5(sort_fixed_freq_mhz);

    fapi2::ATTR_WTH_OVERRIDE_CORE_COUNT_INDEX_Type l_cci;
    FAPI_ATTR_GET(fapi2::ATTR_WTH_OVERRIDE_CORE_COUNT_INDEX, FAPI_SYSTEM, l_cci);

    WFTH_PRINT16_h4_d5_FLAGS(eff_mode_idle_chip_entry_time, wth::IDLE_TIME, l_cci, wth::ENTRY);
    WFTH_PRINT16_h4_d5_FLAGS(eff_mode_idle_chip_exit_time,  wth::IDLE_TIME, l_cci, wth::EXIT);
    WFTH_PRINT16_h4_d5_FLAGS(eff_mode_idle_chip_entry_thld, wth::IDLE_THRESH, l_cci, wth::ENTRY);
    WFTH_PRINT16_h4_d5_FLAGS(eff_mode_idle_chip_exit_thld,  wth::IDLE_THRESH, l_cci, wth::EXIT);

    WFTH_PRINT8_h4_d5_FLAGS(bal_perf_ceff_pct       , wth::CEFF_ADJ, l_cci, wth::BALANCED_PERF);
    WFTH_PRINT8_h4_d5_FLAGS(fav_perf_ceff_pct       , wth::CEFF_ADJ, l_cci, wth::FAVOR_PERF);
    WFTH_PRINT8_h4_d5_FLAGS(fav_pow_ceff_pct        , wth::CEFF_ADJ, l_cci, wth::FAVOR_POWER);
    WFTH_PRINT8_h4_d5_FLAGS(non_det_ceff_pct        , wth::CEFF_ADJ, l_cci, wth::NON_DETERM);

    WFTH_PRINT16_h4_d5_FLAGS(bal_perf_freq_limit_mhz, wth::FREQ_LIMIT, l_cci, wth::BALANCED_PERF);
    WFTH_PRINT16_h4_d5_FLAGS(fav_perf_freq_limit_mhz, wth::FREQ_LIMIT, l_cci, wth::FAVOR_PERF);
    WFTH_PRINT16_h4_d5_FLAGS(fav_pow_freq_limit_mhz , wth::FREQ_LIMIT, l_cci, wth::FAVOR_POWER);
    WFTH_PRINT16_h4_d5_FLAGS(non_det_freq_limit_mhz , wth::FREQ_LIMIT, l_cci, wth::NON_DETERM);

    WFTH_PRINT16_h4_d5(max_powr_min_freq_watts);
}

#ifndef VALIDATE_WOF_HEADER_DATA
#define VALIDATE_WOF_HEADER_DATA(a, b, c, d, e, f, g, h, i, state)         \
    if ( ((!a) || (!b) || (!c) || (!d) || (!e) || (!f) || (!g) || (!h) || (!i)))  \
    { state = 0; }
#endif

///////////////////////////////////////////////////////////
//////// wof_validate_tables
///////////////////////////////////////////////////////////
fapi2::ReturnCode wof_validate_header(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data)
{
    FAPI_DBG(">> wof_validate_tables");

    fapi2::ReturnCode l_rc = 0;

    fapi2::ATTR_WOF_IO_START_Type l_io_start;
    fapi2::ATTR_WOF_TABLE_IO_POWER_BASE_W_Type l_io_pwr_base_w;
    fapi2::ATTR_WOF_IO_STEP_Type l_io_step;
    fapi2::ATTR_WOF_IO_COUNT_Type l_io_cnt;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled = fapi2::ENUM_ATTR_WOF_ENABLED_TRUE;

#ifdef __HOSTBOOT_MODULE
    FAPI_INF("Running WOF Validation checking under FW controls");
    fapi2::ATTR_SYSTEM_WOF_VALIDATION_MODE_Type l_wof_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_VALIDATION_MODE, FAPI_SYSTEM, l_wof_mode));
#else
    FAPI_INF("Running WOF Validation checking under LAB controls");
    fapi2::ATTR_SYSTEM_WOF_LAB_VALIDATION_MODE_Type l_wof_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_LAB_VALIDATION_MODE, FAPI_SYSTEM, l_wof_mode));
#endif

    do
    {
        //Validate WOF header part
        WofTablesHeader_t* p_wfth;
        p_wfth = reinterpret_cast<WofTablesHeader_t*>(l_wof_table_data);

        const char title[] = "Original";
        wth::ECOOverrideFlags l_wfh_override_flags;
        wfth_print(i_proc_target, p_wfth, &l_wfh_override_flags, title);

        bool l_wof_header_data_state = 1;
        VALIDATE_WOF_HEADER_DATA(
            p_wfth->magic_number.value,
            p_wfth->header_version,
            p_wfth->vrt_block_size,
            p_wfth->vrt_block_header_size,
            p_wfth->vrt_data_size,
            p_wfth->core_count,
            p_wfth->vcs_start,
            p_wfth->vcs_step,
            p_wfth->vcs_size,
            l_wof_header_data_state);

        if (!l_wof_header_data_state && (l_wof_mode != fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_OFF))
        {

            l_wof_enabled = fapi2::ENUM_ATTR_WOF_ENABLED_FALSE;

            if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_WARN ||
                l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_INFO   )
            {
                FAPI_INF("WOF Header validation failed. One or more of the following fields are zero.");
                FAPI_INF("  vdd_start, vdd_step, vdd_size, io_start, io_step, io_size, amb_cond_start, amb_cond_step, amb_cond_size");
            }

            if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_INFO)
            {
                // Write the returned error content to the error log
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PSTATE_PB_WOF_HEADER_DATA_INVALID()
                                   .set_CHIP_TARGET(i_proc_target)
                                   .set_MAGIC_NUMBER(p_wfth->magic_number.value)
                                   .set_VERSION(p_wfth->header_version)
                                   .set_VRT_BLOCK_SIZE(p_wfth->vrt_block_size)
                                   .set_VRT_HEADER_SIZE(p_wfth->vrt_block_header_size)
                                   .set_VRT_DATA_SIZE(p_wfth->vrt_data_size)
                                   .set_CORE_COUNT(p_wfth->core_count)
                                   .set_VCS_START(p_wfth->vcs_start)
                                   .set_VCS_STEP(p_wfth->vcs_step)
                                   .set_VCS_SIZE(p_wfth->vcs_size)
                                   .set_VDD_START(p_wfth->vdd_start)
                                   .set_VDD_STEP(p_wfth->vdd_step)
                                   .set_VDD_SIZE(p_wfth->vdd_size)
                                   .set_IO_START(p_wfth->io_start)
                                   .set_IO_STEP(p_wfth->io_step)
                                   .set_IO_SIZE(p_wfth->io_size)
                                   .set_AMB_COND_START(p_wfth->amb_cond_start)
                                   .set_AMB_COND_STEP(p_wfth->amb_cond_step)
                                   .set_AMB_COND_SIZE(p_wfth->amb_cond_size),
                                   "WOF Header validation failed");
                fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            }
            else if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_FAIL)
            {
                FAPI_ERR("WOF Header validation failed. One or more of the following fields are zero.");
                FAPI_ERR("  vdd_start, vdd_step, vdd_size, io_start, io_step, io_size, amb_cond_start, amb_cond_step, amb_cond_size");

                FAPI_ASSERT(false,
                            fapi2::PSTATE_PB_WOF_HEADER_DATA_INVALID()
                            .set_CHIP_TARGET(i_proc_target)
                            .set_MAGIC_NUMBER(p_wfth->magic_number.value)
                            .set_VERSION(p_wfth->header_version)
                            .set_VRT_BLOCK_SIZE(p_wfth->vrt_block_size)
                            .set_VRT_HEADER_SIZE(p_wfth->vrt_block_header_size)
                            .set_VRT_DATA_SIZE(p_wfth->vrt_data_size)
                            .set_CORE_COUNT(p_wfth->core_count)
                            .set_VCS_START(p_wfth->vcs_start)
                            .set_VCS_STEP(p_wfth->vcs_step)
                            .set_VCS_SIZE(p_wfth->vcs_size)
                            .set_VDD_START(p_wfth->vdd_start)
                            .set_VDD_STEP(p_wfth->vdd_step)
                            .set_VDD_SIZE(p_wfth->vdd_size)
                            .set_IO_START(p_wfth->io_start)
                            .set_IO_STEP(p_wfth->io_step)
                            .set_IO_SIZE(p_wfth->io_size)
                            .set_AMB_COND_START(p_wfth->amb_cond_start)
                            .set_AMB_COND_STEP(p_wfth->amb_cond_step)
                            .set_AMB_COND_SIZE(p_wfth->amb_cond_size),
                            "WOF Header validation failed");
            }
        }

        // Don't continue validation as WOF is now disabled
        if (!l_wof_enabled)
        {
            break;
        }

        //Set Max powr
        fapi2::ATTR_MIN_PROC_POWER_PER_CHIP_Type attr_max_powr_min_freq;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MIN_PROC_POWER_PER_CHIP, FAPI_SYSTEM, attr_max_powr_min_freq));

        uint16_t l_max_powr = revle16(p_wfth->max_powr_min_freq_watts);

        if (!attr_max_powr_min_freq && l_max_powr)
        {
            attr_max_powr_min_freq = l_max_powr;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MIN_PROC_POWER_PER_CHIP, FAPI_SYSTEM, attr_max_powr_min_freq));
        }
        else if ( attr_max_powr_min_freq && !l_max_powr)
        {
            p_wfth->max_powr_min_freq_watts = attr_max_powr_min_freq;
        }
        else
        {

            FAPI_ERR("WOF header data -max_powr_min_freq_watts- value is invalid");
            FAPI_ERR("ATTR_MAX_POWR_MIN_FREQ %d, wof_max_powr_min_freq_watts %d",
                     attr_max_powr_min_freq, p_wfth->max_powr_min_freq_watts);
#if 0
            FAPI_ASSERT_NOEXIT(false,
                               fapi2::WOF_HEADER_DATA_MAX_POWR_INVALID(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CHIP_TARGET(i_proc_target)
                               .set_WFTH_MAX_POWR_MIN_FREQ(revle16(p_wfth->max_powr_min_freq_watts))
                               .set_ATTR_MAX_POWR_MIN_FREQ(attr_max_powr_min_freq),
                               "WOF header data -max_powr_min_freq_watts- value is invalid.");
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
#endif
        }


        //Set IO attributes
        //
        l_io_start = revle16(p_wfth->io_start);
        l_io_pwr_base_w = p_wfth->io_pwr_base_w;
        l_io_step  = revle16(p_wfth->io_step);
        l_io_cnt   = revle16(p_wfth->io_size);
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_IO_START, i_proc_target, l_io_start));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_IO_STEP, i_proc_target, l_io_step));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_IO_COUNT, i_proc_target, l_io_cnt));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_TABLE_IO_POWER_BASE_W, i_proc_target, l_io_pwr_base_w));

        // Overrides are present only if the frequency and power fields are both
        // non-zero.  Thus, skip processing if either is zero.
        // For zero checks, endianess doesn't matter
        if (!p_wfth->override_match_freq_mhz || !p_wfth->override_match_power_w)
        {
            break;
        }

        FAPI_INF("WOF Table Header Overrides:");
        FAPI_INF("    Override Match Frequency: 0x%04X (%04d)",
                 revle16(p_wfth->override_match_freq_mhz),
                 revle16(p_wfth->override_match_freq_mhz));

        FAPI_INF("    Override Match Power:     0x%04X (%04d)",
                 revle16(p_wfth->override_match_power_w),
                 revle16(p_wfth->override_match_power_w));

        FAPI_INF("    PowerSave Frequency:      0x%04X (%04d)",
                 revle16(p_wfth->sort_power_save_freq_mhz),
                 revle16(p_wfth->sort_power_save_freq_mhz));
        FAPI_INF("    WOF Base:Frequency:       0x%04X (%04d)",
                 revle16(p_wfth->sort_power_freq_mhz),
                 revle16(p_wfth->sort_power_freq_mhz));
        FAPI_INF("    UltraTurbo Frequency:     0x%04X (%04d)",
                 revle16(p_wfth->sort_ultraturbo_freq_mhz),
                 revle16(p_wfth->sort_ultraturbo_freq_mhz));
        FAPI_INF("    Fixed Frequency:          0x%04X (%04d)",
                 revle16(p_wfth->sort_fixed_freq_mhz),
                 revle16(p_wfth->sort_fixed_freq_mhz));
        FAPI_INF("    Socket Power:             0x%04X (%04d)",
                 revle16(p_wfth->socket_power_w),
                 revle16(p_wfth->socket_power_w));
        FAPI_INF("    Boost Current:            0x%04X (%04d)",
                 revle16(p_wfth->boost_current_a),
                 revle16(p_wfth->boost_current_a));

        // Read the present system values
        fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type ps_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_PS, FAPI_SYSTEM, ps_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_WB_Type wb_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_WB, FAPI_SYSTEM, wb_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_UT_Type ut_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_UT, FAPI_SYSTEM, ut_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_FF_Type ff_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_FF, FAPI_SYSTEM, ff_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_SP_Type sp_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_SP, FAPI_SYSTEM, sp_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_RC_Type rc_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_RC, FAPI_SYSTEM, rc_ovrd));

        // If all the system values are zero (indicating the first chip), then write the
        // chip present values to the system value
        if (!ps_ovrd && !wb_ovrd && !ut_ovrd && !ff_ovrd && !sp_ovrd && !rc_ovrd)
        {
            FAPI_INF("Setting WOF Table Header Override Attributes");

            ps_ovrd = revle16(p_wfth->sort_power_save_freq_mhz);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_TABLE_OVERRIDE_PS, FAPI_SYSTEM, ps_ovrd));

            wb_ovrd = revle16(p_wfth->sort_power_freq_mhz);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_TABLE_OVERRIDE_WB, FAPI_SYSTEM, wb_ovrd));

            ut_ovrd = revle16(p_wfth->sort_ultraturbo_freq_mhz);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_TABLE_OVERRIDE_UT, FAPI_SYSTEM, ut_ovrd));

            ff_ovrd = revle16(p_wfth->sort_fixed_freq_mhz);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_TABLE_OVERRIDE_FF, FAPI_SYSTEM, ff_ovrd));

            sp_ovrd = revle16(p_wfth->socket_power_w);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_TABLE_OVERRIDE_SP, FAPI_SYSTEM, sp_ovrd));

            rc_ovrd = revle16(p_wfth->rdp_current_a);
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_WOF_TABLE_OVERRIDE_RC, FAPI_SYSTEM, rc_ovrd));
        }
        // Check that the present chip value all match the system value once the
        // system value is set
        else
        {
            bool b_ps_override_fail = (ps_ovrd != revle16(p_wfth->sort_power_save_freq_mhz)) ?
                                      true : false;
            bool b_wb_override_fail = (wb_ovrd != revle16(p_wfth->sort_power_freq_mhz))      ?
                                      true : false;
            bool b_ut_override_fail = (ut_ovrd != revle16(p_wfth->sort_ultraturbo_freq_mhz)) ?
                                      true : false;
            bool b_ff_override_fail = (ff_ovrd != revle16(p_wfth->sort_fixed_freq_mhz))      ?
                                      true : false;
            bool b_sp_override_fail = (sp_ovrd != revle16(p_wfth->socket_power_w))           ?
                                      true : false;
            bool b_rc_override_fail = (rc_ovrd != revle16(p_wfth->rdp_current_a))          ?
                                      true : false;


            if (b_ps_override_fail || b_wb_override_fail || b_ut_override_fail ||
                b_ff_override_fail || b_sp_override_fail || b_rc_override_fail   )
            {

                FAPI_INF("WOF Tables Override validation failed. The following fields don't match.");

                if (b_ps_override_fail)
                {
                    FAPI_INF("  ATTR_WOF_TABLE_OVERRIDE_PS = 0x%04X (%04d)", ps_ovrd, ps_ovrd);
                }

                if (b_wb_override_fail)
                {
                    FAPI_INF("  ATTR_WOF_TABLE_OVERRIDE_WB = 0x%04X (%04d)", wb_ovrd, wb_ovrd);
                }

                if (b_ut_override_fail)
                {
                    FAPI_INF("  ATTR_WOF_TABLE_OVERRIDE_UT = 0x%04X (%04d)", ut_ovrd, ut_ovrd);
                }

                if (b_ff_override_fail)
                {
                    FAPI_INF("  ATTR_WOF_TABLE_OVERRIDE_FF = 0x%04X (%04d)", ff_ovrd, ff_ovrd);
                }

                if (b_sp_override_fail)
                {
                    FAPI_INF("  ATTR_WOF_TABLE_OVERRIDE_SP = 0x%04X (%04d)", sp_ovrd, sp_ovrd);
                }

                if (b_rc_override_fail)
                {
                    FAPI_INF("  ATTR_WOF_TABLE_OVERRIDE_RC = 0x%04X (%04d)", rc_ovrd, rc_ovrd);
                }

                if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_INFO)
                {
                    FAPI_ASSERT_NOEXIT(false,
                                       fapi2::PSTATE_PB_WOF_OVERRIDE_INVALID()
                                       .set_CHIP_TARGET(i_proc_target)
                                       .set_CHIP_PS(revle16(p_wfth->sort_power_save_freq_mhz))
                                       .set_SYS_PS(ps_ovrd)
                                       .set_CHIP_WB(revle16(p_wfth->sort_power_freq_mhz))
                                       .set_SYS_WB(wb_ovrd)
                                       .set_CHIP_UT(revle16(p_wfth->sort_ultraturbo_freq_mhz))
                                       .set_SYS_UT(ut_ovrd)
                                       .set_CHIP_FF(revle16(p_wfth->sort_fixed_freq_mhz))
                                       .set_SYS_FF(ff_ovrd)
                                       .set_CHIP_SP(revle16(p_wfth->socket_power_w))
                                       .set_SYS_SP(sp_ovrd)
                                       .set_CHIP_RC(revle16(p_wfth->rdp_current_a))
                                       .set_SYS_RC(rc_ovrd),
                                       "WOF Tables Override validation failed.  One of more fields mismatch.");
                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                }
                else
                {

                    if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_WARN)
                    {
                        FAPI_ASSERT_NOEXIT(false,
                                           fapi2::PSTATE_PB_WOF_OVERRIDE_INVALID()
                                           .set_CHIP_TARGET(i_proc_target)
                                           .set_CHIP_PS(revle16(p_wfth->sort_power_save_freq_mhz))
                                           .set_SYS_PS(ps_ovrd)
                                           .set_CHIP_WB(revle16(p_wfth->sort_power_freq_mhz))
                                           .set_SYS_WB(wb_ovrd)
                                           .set_CHIP_UT(revle16(p_wfth->sort_ultraturbo_freq_mhz))
                                           .set_SYS_UT(ut_ovrd)
                                           .set_CHIP_FF(revle16(p_wfth->sort_fixed_freq_mhz))
                                           .set_SYS_FF(ff_ovrd)
                                           .set_CHIP_SP(revle16(p_wfth->socket_power_w))
                                           .set_SYS_SP(sp_ovrd)
                                           .set_CHIP_RC(revle16(p_wfth->rdp_current_a))
                                           .set_SYS_RC(rc_ovrd),
                                           "WOF Tables Override validation failed.  One of more fields mismatch.");
                        fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    }

                    if (l_wof_mode == fapi2::ENUM_ATTR_SYSTEM_WOF_VALIDATION_MODE_FAIL)
                    {
                        FAPI_ASSERT(false,
                                    fapi2::PSTATE_PB_WOF_OVERRIDE_INVALID()
                                    .set_CHIP_TARGET(i_proc_target)
                                    .set_CHIP_PS(revle16(p_wfth->sort_power_save_freq_mhz))
                                    .set_SYS_PS(ps_ovrd)
                                    .set_CHIP_WB(revle16(p_wfth->sort_power_freq_mhz))
                                    .set_SYS_WB(wb_ovrd)
                                    .set_CHIP_UT(revle16(p_wfth->sort_ultraturbo_freq_mhz))
                                    .set_SYS_UT(ut_ovrd)
                                    .set_CHIP_FF(revle16(p_wfth->sort_fixed_freq_mhz))
                                    .set_SYS_FF(ff_ovrd)
                                    .set_CHIP_SP(revle16(p_wfth->socket_power_w))
                                    .set_SYS_SP(sp_ovrd)
                                    .set_CHIP_RC(revle16(p_wfth->rdp_current_a))
                                    .set_SYS_RC(rc_ovrd),
                                    "WOF Tables Override validation failed.  One of more fields mismatch.");
                    }

                    l_wof_enabled = fapi2::ENUM_ATTR_WOF_ENABLED_FALSE;
                }
            }
        }
    }
    while(0);

fapi_try_exit:

    if (!l_wof_enabled)
    {
        FAPI_INF("WOF has been disabled due to validation issues");
    }

    FAPI_ATTR_SET(fapi2::ATTR_WOF_ENABLED, i_proc_target, l_wof_enabled);

    FAPI_DBG("<< wof_validate_tables");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  wof_apply_overrides
///////////////////////////////////////////////////////////
fapi2::ReturnCode wof_apply_overrides(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::voltageBucketData_t* o_poundV_data,
    const bool i_wof_state)
{
    FAPI_INF(">> wof_apply_overrides");

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    // Use new to avoid over-running the stack
    fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data =
        (fapi2::ATTR_WOF_TABLE_DATA_Type*)new fapi2::ATTR_WOF_TABLE_DATA_Type;
    fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLED,
                           i_proc_target, l_wof_enabled));

    do
    {
        if (!i_wof_state)
        {
            FAPI_INF("  WOF not enabled.  No overrides are applied.");
            break;
        }

        if (l_wof_enabled == (fapi2::ATTR_WOF_ENABLED_Type)fapi2::ENUM_ATTR_WOF_ENABLED_FORCE_DISABLED)
        {
            FAPI_INF("  WOF forcibly disabled via ATTR_WOF_ENABLED.  No overrides are applied.");
            break;
        }

        fapi2::current_err = wof_get_tables(i_proc_target, l_wof_table_data);

        if (fapi2::current_err)
        {
            // wof_get_table disabled WOF.  Exit as success to allow IPL to continue.
            fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
            break;
        }

        // This sets the fapi2::ATTR_WOF_ENABLED attribute with the result
        FAPI_TRY(wof_validate_header(i_proc_target, l_wof_table_data));

        // Determine if we can continue
        fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLED, i_proc_target, l_wof_enabled));

        if (!l_wof_enabled)
        {
            break;
        }

        fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type ps_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_PS, FAPI_SYSTEM, ps_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_WB_Type wb_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_WB, FAPI_SYSTEM, wb_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_UT_Type ut_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_UT, FAPI_SYSTEM, ut_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_FF_Type ff_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_FF, FAPI_SYSTEM, ff_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_SP_Type sp_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_SP, FAPI_SYSTEM, sp_ovrd));

        fapi2::ATTR_WOF_TABLE_OVERRIDE_RC_Type rc_ovrd;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_RC, FAPI_SYSTEM, rc_ovrd));

        // If all the system values are zero, no overrides exist
        if (!ps_ovrd && !wb_ovrd && !ut_ovrd && !ff_ovrd && !sp_ovrd && !rc_ovrd)
        {
            break;
        }

        o_poundV_data->other_info.VddPsavCoreFreq    = revle16(ps_ovrd);
        o_poundV_data->other_info.VddTdpWofCoreFreq  = revle16(wb_ovrd);
        o_poundV_data->other_info.VddUTCoreFreq      = revle16(ut_ovrd);
        o_poundV_data->other_info.FxdFreqMdeCoreFreq = revle16(ff_ovrd);

        FAPI_INF("WOF Override updates to #V");
        FAPI_INF("    PowerSave Frequency:      0x%04X (%04d)",
                 revle16(o_poundV_data->other_info.VddPsavCoreFreq),
                 revle16(o_poundV_data->other_info.VddPsavCoreFreq));
        FAPI_INF("    WOF Base:Frequency:       0x%04X (%04d)",
                 revle16(o_poundV_data->other_info.VddTdpWofCoreFreq),
                 revle16(o_poundV_data->other_info.VddTdpWofCoreFreq));
        FAPI_INF("    UltraTurbo Frequency:     0x%04X (%04d)",
                 revle16(o_poundV_data->other_info.VddUTCoreFreq),
                 revle16(o_poundV_data->other_info.VddUTCoreFreq));
        FAPI_INF("    Fixed Frequency:          0x%04X (%04d)",
                 revle16(o_poundV_data->other_info.FxdFreqMdeCoreFreq),
                 revle16(o_poundV_data->other_info.FxdFreqMdeCoreFreq));

    }
    while(0);

fapi_try_exit:

    if (l_wof_table_data)
    {
        delete[] l_wof_table_data;
        l_wof_table_data = nullptr;
    }

    FAPI_INF("<< wof_apply_overrides");
    return fapi2::current_err;
}

///////////////////////////////////////////////////////////
////////  print_voltage_bucket
///////////////////////////////////////////////////////////
fapi2::ReturnCode print_voltage_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::voltageBucketData_t* o_poundV_data)
{

    const uint32_t BUFFSIZE = 64;
    char  l_proc_str[BUFFSIZE];
    fapi2::toString(i_proc_target, l_proc_str, BUFFSIZE);

    FAPI_INF(">> print_voltage_bucket - %s", l_proc_str);

#define PRINT_BKT_PT_16(_member, _pt) \
    FAPI_INF("    Pt %d  %-20s = 0x%04x (%4d)", _pt, #_member,  \
             revle16(o_poundV_data->operating_pts[_pt]._member),     \
             revle16(o_poundV_data->operating_pts[_pt]._member));

#define PRINT_BKT_PT_8(_member, _pt) \
    FAPI_INF("    Pt %d  %-20s = 0x%04x (%4d)", _pt, #_member, \
             o_poundV_data->operating_pts[_pt]._member, \
             o_poundV_data->operating_pts[_pt]._member);


#define PRINT_BKT_ST_16(_member) \
    FAPI_INF("           %-20s = 0x%04x (%4d)", #_member, \
             revle16(o_poundV_data->static_rails._member),         \
             revle16(o_poundV_data->static_rails._member));

#define PRINT_BKT_ST_8(_member) \
    FAPI_INF("           %-20s = 0x%04x (%4d)", #_member, \
             o_poundV_data->static_rails._member, \
             o_poundV_data->static_rails._member);

#define PRINT_BKT_OTR_16(_member) \
    FAPI_INF("           %-20s = 0x%04x (%4d)", #_member, \
             revle16(o_poundV_data->other_info._member), \
             revle16(o_poundV_data->other_info._member));

#define PRINT_BKT_OTR_16_OVR(_member, _ovrd) \
    {                                                               \
        char flag[4] = "";                                          \
        if (_ovrd)                                                  \
        {                                                           \
            strcpy(flag, "(*)");                                    \
        }                                                           \
        FAPI_INF("           %-20s = 0x%04x (%4d) %s", #_member,    \
                 revle16(o_poundV_data->other_info._member),             \
                 revle16(o_poundV_data->other_info._member),             \
                 flag);                                                  \
    }

#define PRINT_BKT_OTR_8(_member) \
    FAPI_INF("           %-20s = 0x%04x (%4d)", #_member, \
             o_poundV_data->other_info._member, \
             o_poundV_data->other_info._member);

    for (int p = 0; p <= NUM_PV_POINTS - 1; p++)
    {
        FAPI_INF("Bucket #V - CF %d", p);
        PRINT_BKT_PT_16(core_frequency, p);
        PRINT_BKT_PT_16(vdd_voltage, p);
        PRINT_BKT_PT_16(idd_tdp_ac_cur, p);
        PRINT_BKT_PT_16(idd_tdp_dc_cur, p);
        PRINT_BKT_PT_16(idd_rdp_ac_cur, p);
        PRINT_BKT_PT_16(idd_rdp_dc_cur, p);
        PRINT_BKT_PT_16(vcs_voltage, p);
        PRINT_BKT_PT_16(ics_tdp_ac_cur, p);
        PRINT_BKT_PT_16(ics_tdp_dc_cur, p);
        PRINT_BKT_PT_16(ics_rdp_ac_cur, p);
        PRINT_BKT_PT_16(ics_rdp_dc_cur, p);
        PRINT_BKT_PT_16(core_freq_gb_sort, p);
        PRINT_BKT_PT_16(vdd_vmin, p);
        PRINT_BKT_PT_16(ivdd_powr_cur_act, p);
        PRINT_BKT_PT_8 (core_powr_temp, p);
        PRINT_BKT_PT_16(rt_tdp_ac_10ma, p);
        PRINT_BKT_PT_16(rt_tdp_dc_10ma, p);
    }

    FAPI_INF("Bucket #V - Static");
    PRINT_BKT_ST_16(SRVdnVltg);
    PRINT_BKT_ST_16(SRIdnTdpAcCurr);
    PRINT_BKT_ST_16(SRIdnTdpDcCurr);
    PRINT_BKT_ST_16(SRVioVltg);
    PRINT_BKT_ST_16(SRIioTdpAcCurr);
    PRINT_BKT_ST_16(SRIioTdpDcCurr);
    PRINT_BKT_ST_16(SRVpciVltg);
    PRINT_BKT_ST_16(SRIpciTdpAcCurr);
    PRINT_BKT_ST_16(SRIpciTdpDcCurr);
    PRINT_BKT_ST_16(SRVAvddVltg);
    PRINT_BKT_ST_16(SRIAvddTdpAcCurr);
    PRINT_BKT_ST_16(SRIAvddTdpDcCurr);
    PRINT_BKT_ST_8 (modelDataFlag);
    PRINT_BKT_ST_16(SRVDDVmax);
    PRINT_BKT_ST_16(SRVCSVmax);

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_WOF_TABLE_OVERRIDE_PS_Type ps_ovrd;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_PS, FAPI_SYSTEM, ps_ovrd));

    fapi2::ATTR_WOF_TABLE_OVERRIDE_WB_Type wb_ovrd;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_WB, FAPI_SYSTEM, wb_ovrd));

    fapi2::ATTR_WOF_TABLE_OVERRIDE_UT_Type ut_ovrd;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_UT, FAPI_SYSTEM, ut_ovrd));

    fapi2::ATTR_WOF_TABLE_OVERRIDE_FF_Type ff_ovrd;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_FF, FAPI_SYSTEM, ff_ovrd));

    fapi2::ATTR_WOF_TABLE_OVERRIDE_SP_Type sp_ovrd;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_SP, FAPI_SYSTEM, sp_ovrd));

    fapi2::ATTR_WOF_TABLE_OVERRIDE_RC_Type rc_ovrd;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_TABLE_OVERRIDE_RC, FAPI_SYSTEM, rc_ovrd));

    FAPI_INF("Bucket #V - Other.  (*) indicates value came from a WOF Table Override");
    PRINT_BKT_OTR_16    (PAUFreq                    );
    PRINT_BKT_OTR_16_OVR(TSrtSocPowTgt,     sp_ovrd );
    PRINT_BKT_OTR_16    (VdnSrtSocPow               );
    PRINT_BKT_OTR_16    (VIOSrtSocPow               );
    PRINT_BKT_OTR_16    (VPCISrtSocPow              );
    PRINT_BKT_OTR_16    (AVDDSrtSocPow              );
    PRINT_BKT_OTR_16    (TSrtSocPowAct              );
    PRINT_BKT_OTR_16_OVR(IDDRdpLmt,         rc_ovrd );
    PRINT_BKT_OTR_8     (VddTdpWofIndx              );
    PRINT_BKT_OTR_8     (VcsTdpWofIndx              );
    PRINT_BKT_OTR_8     (VioTdpWofIndx              );
    PRINT_BKT_OTR_8     (AmbTdpWofIndx              );
    PRINT_BKT_OTR_8     (ModeIntrPlt                );
    PRINT_BKT_OTR_8     (RdpSrtPwrTmp               );
    PRINT_BKT_OTR_8     (TdpSrtPwrTmp               );
    PRINT_BKT_OTR_16_OVR(VddTdpWofCoreFreq, wb_ovrd );
    PRINT_BKT_OTR_16_OVR(FxdFreqMdeCoreFreq, ff_ovrd );
    PRINT_BKT_OTR_16_OVR(VddPsavCoreFreq,   ps_ovrd );
    PRINT_BKT_OTR_16_OVR(VddUTCoreFreq,     ut_ovrd );
    PRINT_BKT_OTR_16    (VddFmxCoreFreq             );
    PRINT_BKT_OTR_8     (MmaThrTemp                 );
    PRINT_BKT_OTR_8     (IOThrTemp                  );
    PRINT_BKT_OTR_16    (FxFreqPowTgt               );

fapi_try_exit:
    FAPI_INF("<< print_voltage_bucket");
    return fapi2::current_err;
}
#endif
