/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_pm_utils.H $      */
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
/// @file  p10_pm_utils.H
/// @brief General utility functions
///
/// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner         : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *Team                 : PM
/// *Consumed by          : HB:CRO
///

#ifndef __PM_UTILS_H__
#define __PM_UTILS_H__

#include <p10_pm_get_poundv_bucket.H>
#include <pstates_common.H>

// Masks for #V Model Data (aka Flags) field
static const uint8_t PDV_MODEL_DATA_PNEXT           = 0x80;
static const uint8_t PDV_MODEL_DATA_ISC             = 0x40;
static const uint8_t PDV_MODEL_DATA_SLT             = 0x20;
static const uint8_t PDV_MODEL_DATA_VDN_CORRECT     = 0x10;
static const uint8_t PDV_MODEL_DATA_WOF_READY       = 0x02;
static const uint8_t PDV_MODEL_DATA_MODELED         = 0x01;

// Byte-reverse a 16-bit integer if on a little-endian machine
uint16_t revle16(const uint16_t i_x);

// Byte-reverse a 32-bit integer if on a little-endian machine
uint32_t revle32(const uint32_t i_x);

// Byte-reverse a 64-bit integer if on a little-endian machine
uint64_t revle64(const uint64_t i_x);

/// ----------------------------------------------------------------------------
/// @brief Compute bias value for pre-defined percentage unit
/// @param[in]     i_value Biased value
/// @return bias value
/// ----------------------------------------------------------------------------
double calc_bias(const int8_t i_value);

/// ----------------------------------------------------------------------------
/// @brief Compute smallest value for a given input
/// @param[in]     x value
/// @return smallest value
/// ----------------------------------------------------------------------------
double internal_ceil(double x);

/// ----------------------------------------------------------------------------
/// @brief Compute largest value for a given input
/// @param[in]     x value
/// @return largest value
/// ----------------------------------------------------------------------------
double internal_floor(double x);

/// -----------------------------------------------------------------------
/// @brief Compute the rounded value for a given input
/// @param[in]     x value
/// @return rounded value
/// -----------------------------------------------------------------------
double internal_round(double x);

/// ----------------------------------------------------------------------------
/// @brief Adjust bias value for given frequency value
/// @param[in]     i_value  frequency value
/// @param[in]     i_bias_0p5pct  bias value
/// @return computed biase value
/// ----------------------------------------------------------------------------
uint32_t bias_adjust_mhz(
    const uint32_t i_value,
    const int32_t i_bias_0p5pct);

/// ----------------------------------------------------------------------------
/// @brief Adjust bias value for given vdd/vcs voltage
/// @param[in]     i_value vdd/vcs value
/// @param[in]     i_bias_0p5pct  bias value
/// @return computed biase value
/// ----------------------------------------------------------------------------
uint32_t bias_adjust_mv(
    const uint32_t i_value,
    const int8_t i_bias_0p5pct);

#ifndef DFT
/// ----------------------------------------------------------------------------
/// @brief Get the WOF Table Header
/// @param[in]    i_proc_target Chip Target
/// @param[out]   i_wof_table_data points to WOF data tables
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------------------
fapi2::ReturnCode wof_get_tables(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::ATTR_WOF_TABLE_DATA_Type* i_wof_table_data);


namespace wth
{
enum EFFICIENCY_PARMS
{
    MAX_SORTS = 8,
};

enum EFFICIENCY_MEMBERS
{
    ALG,
    IDLE_TIME,
    IDLE_THRESH,
    CEFF_ADJ,
    FREQ_LIMIT
};

enum EFFICIENCY_MODES
{
    FAVOR_POWER     = 0,
    FAVOR_PERF      = 1,
    BALANCED_PERF   = 2,
    NON_DETERM      = 3,
    EFFIC_MODES     = 4
};

extern const char* EFFICIENCY_MODES_NAMES[];

#define EFFICIENCY_MODES_NAMES_STR \
    { \
        "FAVOR_POWER",   \
        "FAVOR_PERF",    \
        "BALANCED_PERF", \
        "NON_DETERM"     \
    }

enum IDLE_TRANSITIONS
{
    ENTRY              = 0,
    EXIT               = 1,
    IDLE_TRANSITIONS   = 2
};

extern const char* IDLE_TRANSITIONS_NAMES[];

#define IDLE_TRANSITIONS_NAMES_STR \
    { \
        "ENTRY", \
        "EXIT"   \
    }

enum IDLE_MODES
{
    UTIL               = 0,
    CEFF               = 1,
    IDLE_MODES         = 2
};

extern const char* IDLE_MODES_NAMES[];

#define IDLE_MODES_STR \
    { \
        "UTIL", \
        "CEFF"  \
    }

/// @struct Struct holding override flags to allow for marking entries
///         in print/trace output
class ECOOverrideFlags
{
    private:
        bool iv_alg;                                        ///< Algorithm change
        bool iv_idle_times[MAX_SORTS][IDLE_TRANSITIONS];    ///< Idle transition times
        bool iv_idle_threshs[MAX_SORTS][IDLE_TRANSITIONS];  ///< Idle threshold parameters
        bool iv_ceff_adj[MAX_SORTS][EFFIC_MODES];           ///< Ceff Adjustments
        bool iv_freq_limits[MAX_SORTS][EFFIC_MODES];        ///< Frequency maximums

    public:
        /// @brief Constructor
        ECOOverrideFlags()
        {
            iv_alg = false;
            memset(iv_idle_times, false, sizeof(iv_idle_times));
            memset(iv_idle_threshs, false, sizeof(iv_idle_threshs));
            memset(iv_ceff_adj, false, sizeof(iv_ceff_adj));
            memset(iv_freq_limits, false, sizeof(iv_freq_limits));
        }

        /// @brief Set a member flag by sort and element
        void set(EFFICIENCY_MEMBERS i_mem, uint8_t i_sort, uint8_t i_element = 0xFF)
        {
            switch (i_mem)
            {
                case ALG:
                    iv_alg = true;
                    break;

                case IDLE_TIME:
                    iv_idle_times[i_sort][i_element] = true;
                    break;

                case IDLE_THRESH:
                    iv_idle_threshs[i_sort][i_element] = true;
                    break;

                case CEFF_ADJ:
                    iv_ceff_adj[i_sort][i_element] = true;
                    break;

                case FREQ_LIMIT:
                    iv_freq_limits[i_sort][i_element] = true;
                    break;

                default:
                    FAPI_ERR("Invalid member %u", i_mem);
            }
        }

        /// @brief Get a member flag by sort and element
        bool get(EFFICIENCY_MEMBERS i_mem, uint8_t i_sort, uint8_t i_element = 0xFF)
        {
            bool value = false;

            switch (i_mem)
            {
                case ALG:
                    value = iv_alg;
                    break;

                case IDLE_TIME:
                    value = iv_idle_times[i_sort][i_element];
                    break;

                case IDLE_THRESH:
                    value = iv_idle_threshs[i_sort][i_element];
                    break;

                case CEFF_ADJ:
                    value = iv_ceff_adj[i_sort][i_element];
                    break;

                case FREQ_LIMIT:
                    value = iv_freq_limits[i_sort][i_element];
                    break;

                default:
                    FAPI_ERR("Invalid member %u", i_mem);
            }

            return value;
        }

        /// @brief See if any override flags are set
        bool are_any_set()
        {
            bool b_state = false;

            b_state = iv_alg;

            if (b_state)
            {
                goto set_break;
            }

            for (uint32_t s = 0; s < MAX_SORTS; ++s)
            {
                for (uint32_t t = 0; t < IDLE_TRANSITIONS; ++t)
                {
                    b_state = iv_idle_times[s][t];

                    if (b_state)
                    {
                        goto set_break;
                    }

                    b_state = iv_idle_threshs[s][t];

                    if (b_state)
                    {
                        goto set_break;
                    }
                }

                for (uint32_t m = 0; m < EFFIC_MODES; ++m)
                {
                    b_state = iv_ceff_adj[s][m];

                    if (b_state)
                    {
                        goto set_break;
                    }

                    b_state = iv_freq_limits[s][m];

                    if (b_state)
                    {
                        goto set_break;
                    }
                }
            };

        set_break :
            return b_state;
        }

        /// @brief Print override flags
        void print()
        {
            const char* IDLE_TRANSITIONS_NAMES[] = IDLE_TRANSITIONS_NAMES_STR;
            const char* EFFICIENCY_MODES_NAMES[] = EFFICIENCY_MODES_NAMES_STR;

            if (iv_alg)
            {
                FAPI_INF("ECOOverrideFlags alg set");
            }

            for (uint32_t s = 0; s < MAX_SORTS; ++s)
            {
                for (uint32_t t = 0; t < IDLE_TRANSITIONS; ++t)
                {
                    if (iv_idle_times[s][t])
                    {
                        FAPI_INF("ECOOverrideFlags idle_times[%u][%s] set", s, IDLE_TRANSITIONS_NAMES[t]);
                    }

                    if (iv_idle_threshs[s][t])
                    {
                        FAPI_INF("ECOOverrideFlags idle_threshs[%u][%s] set", s, IDLE_TRANSITIONS_NAMES[t]);
                    }
                }

                for (uint32_t m = 0; m < EFFIC_MODES; ++m)
                {
                    if (iv_ceff_adj[s][m])
                    {
                        FAPI_INF("ECOOverrideFlags ceff_adj[%u][%s] set", s, EFFICIENCY_MODES_NAMES[m]);
                    }

                    if (iv_freq_limits[s][m])
                    {
                        FAPI_INF("ECOOverrideFlags ceff_adj[%u][%s] set", s, EFFICIENCY_MODES_NAMES[m]);
                    }
                }
            };
        }
}; // ECOOverrideFlags
}  // namespace wth

/// @brief Override some WOF Table Header fields
/// @param[in]    i_proc_target Chip Target
/// @param[in]    i_wof_table_data points to WOF data tables
/// @param[out]   o_wth_override_flags to track field overrides
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------------------
fapi2::ReturnCode wof_table_header_overrides(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::ATTR_WOF_TABLE_DATA_Type* i_wof_table_data,
    wth::ECOOverrideFlags* o_wth_override_flags);

/// ----------------------------------------------------------------------------
/// @brief Validate the WOF Table Header
/// @param[in]    i_proc_target Chip Target
/// @param[in]    i_wof_table_data points to WOF data tables
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------------------
fapi2::ReturnCode wof_validate_header(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::ATTR_WOF_TABLE_DATA_Type* i_wof_table_data);
#endif //DFT

/// ----------------------------------------------------------------------------
/// @brief Apply the WOF Table Overrides to #V
/// @param[in]    i_proc_target Chip Target
/// @param[inout] o_wof_table_data points to WOF data tables
/// @param[in]    i_wof_state enabled or disabled
/// @return fapi2::ReturnCode: FAPI2_RC_SUCCESS if success, else error code.
/// ----------------------------------------------------------------------------
fapi2::ReturnCode wof_apply_overrides(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::voltageBucketData_t* o_poundV_data,
    const bool i_wof_state);

/// ----------------------------------------------------------------------------
/// @brief  Print the WOF Table Header to the trace
/// @param[in]    i_proc_target Chip Target
/// @param[in]    i_wfth points to WOF Table Header
/// @param[in]    i_wth_override_flags that tracks field overrides
/// @param[in]    i_title string to give the print out a title
/// ----------------------------------------------------------------------------
void wfth_print(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    WofTablesHeader_t* i_wfth,
    wth::ECOOverrideFlags* i_wfth_override_flags,
    const char* i_title);

/// ----------------------------------------------------------------------------
/// @brief Print the raw #V bucket structure
/// @param[in]    o_poundV_data Pointer to structure
/// ----------------------------------------------------------------------------
fapi2::ReturnCode print_voltage_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    fapi2::voltageBucketData_t* o_poundV_data);


#endif  // __PM_UTILS_H__
