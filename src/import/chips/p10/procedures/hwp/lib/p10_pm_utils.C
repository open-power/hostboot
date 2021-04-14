/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_pm_utils.C $      */
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

    prx[0] = pix[1];
    prx[1] = pix[0];
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

    prx[0] = pix[3];
    prx[1] = pix[2];
    prx[2] = pix[1];
    prx[3] = pix[0];
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

    prx[0] = pix[7];
    prx[1] = pix[6];
    prx[2] = pix[5];
    prx[3] = pix[4];
    prx[4] = pix[3];
    prx[5] = pix[2];
    prx[6] = pix[1];
    prx[7] = pix[0];
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

    FAPI_DBG(">> WOF get tables");

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
            strcpy(p_wfth->table_version, "Denali.20200125");
            strcpy(p_wfth->package_name,  "DENALI_DCM");

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

                            FAPI_DBG("VRT default: l_vrt fields value 0x%08X marker %X type %d content %d io %02d ac %02d vc %02d vd %02d",
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
    FAPI_DBG("<< WOF get tables");
    return fapi2::current_err;
}


///////////////////////////////////////////////////////////
////////    wfth_print
///////////////////////////////////////////////////////////
void wfth_print(WofTablesHeader_t* i_wfth)
{

    FAPI_DBG("i_wfth  addr = %p size = %d",
             i_wfth, sizeof(fapi2::ATTR_WOF_TABLE_DATA_Type));

    // Put out the endian-corrected scalars

#define WFTH_PRINT8_h4_d1(_member) \
    FAPI_INF("%-25s = 0x%04X (%01d)", #_member, i_wfth->_member, i_wfth->_member);

#define WFTH_PRINT8_h4_d2(_member) \
    FAPI_INF("%-25s = 0x%04X (%02d)", #_member, i_wfth->_member, i_wfth->_member);

#define WFTH_PRINT8_h4_d5(_member) \
    FAPI_INF("%-25s = 0x%04X (%05d)", #_member, i_wfth->_member, i_wfth->_member);

#define WFTH_PRINT16_h4_d5(_member) \
    FAPI_INF("%-25s = 0x%04X (%05d)", #_member, revle16(i_wfth->_member), revle16(i_wfth->_member));

#define WFTH_PRINT16_h8_d0(_member) \
    FAPI_INF("%-25s = 0x%08X", #_member, revle16(i_wfth->_member), revle16(i_wfth->_member));

#define WFTH_PRINT32(_member) \
    FAPI_INF("%-25s = 0x%0*X (%0*d)", #_member, revle32(i_wfth->_member), revle32(i_wfth->_member));

#define WFTH_PRINTS(_member) \
    FAPI_INF("%-25s = %s", #_member, i_wfth->_member);

    FAPI_INF("---------------------------------------------------------------------------------------");
    FAPI_INF("WOF Table Header");
    FAPI_INF("---------------------------------------------------------------------------------------");

    WFTH_PRINTS       (magic_number.text     );
    WFTH_PRINT8_h4_d1 (header_version        );
    WFTH_PRINT8_h4_d5 (vrt_block_size        );
    WFTH_PRINT8_h4_d5 (vrt_block_header_size );
    WFTH_PRINT8_h4_d5 (vrt_data_size         );
    WFTH_PRINT8_h4_d1 (ocs_mode              );
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
    WFTH_PRINT16_h4_d5(sort_power_save_freq_mhz);
    WFTH_PRINT16_h4_d5(sort_fixed_freq_mhz);
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

        wfth_print(p_wfth);

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
    while(0);

fapi_try_exit:

    if (!l_wof_enabled)
    {
        FAPI_INF("WOF has been disabled");
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
    fapi2::voltageBucketData_t* o_poundV_data)
{
    FAPI_INF(">> wof_apply_overrides");

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    // Use new to avoid over-running the stack
    fapi2::ATTR_WOF_TABLE_DATA_Type* l_wof_table_data =
        (fapi2::ATTR_WOF_TABLE_DATA_Type*)new fapi2::ATTR_WOF_TABLE_DATA_Type;


    do
    {
        fapi2::ATTR_SYSTEM_WOF_DISABLE_Type l_wof_sys_disable;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_WOF_DISABLE, FAPI_SYSTEM, l_wof_sys_disable));

        if (l_wof_sys_disable)
        {
            FAPI_INF("  WOF sys attr is disabled.");
            break;
        }

        fapi2::ATTR_WOF_ENABLED_Type l_wof_enabled;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_WOF_ENABLED, i_proc_target, l_wof_enabled));

        if (!l_wof_enabled)
        {
            FAPI_INF("  WOF not enabled.  No overrides are applied.");
            break;
        }


        FAPI_TRY(wof_get_tables(i_proc_target, l_wof_table_data));

        // This sets the OVERRIDE attribute set
        FAPI_TRY(wof_validate_header(i_proc_target, l_wof_table_data));

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
    fapi2::voltageBucketData_t* o_poundV_data)
{
    FAPI_INF(">> print_voltage_bucket");

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
