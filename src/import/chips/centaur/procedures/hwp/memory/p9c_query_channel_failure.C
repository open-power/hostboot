/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_query_channel_failure.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9c_query_channel_failure.C
/// @brief Query IOMCFIRS and CHIFIRS for an active attention that is
///        configured to channel failure
///

//
// *HWP HWP Owner: Matt Derksen <mderkse1@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: HB
// *HWP Level: 2
// *HWP Consumed by: HB and PRDF
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9c_query_channel_failure.H>
#include <generic/memory/lib/utils/c_str.H>

// How many DMIs are allowed on MC
constexpr uint32_t DMI_TARGETS_PER_MC = 4;

// SCOM registers needed for channel failure checking
// MC target register addresses
constexpr uint64_t SCOM_IOMCFIR_ADDR = 0x07011000ull;
constexpr uint64_t SCOM_MODE_PB_ADDR = 0x07011020ull;

// DMI target register addresses
constexpr uint64_t SCOM_CHIFIR_ADDR =  0x07010900ull;
constexpr uint64_t SCOM_MCICFG0_ADDR = 0x0701090Aull;
constexpr uint64_t SCOM_MCICFG1_ADDR = 0x0701090Eull;

// MCICFG1 bits
constexpr uint8_t MCICFG1Q_DIS_TAG_OVERRUN_ERROR_BIT    = 43; // enabled = 1
constexpr uint8_t MCICFG1Q_DIS_BUF_OVERRUN_ERROR_BIT    = 44;
constexpr uint8_t MCICFG1Q_DIS_DSFF_ASYNC_CMD_ERROR_BIT = 45;
constexpr uint8_t MCICFG1Q_DIS_DSFF_SM_ERROR_BIT        = 46;
constexpr uint8_t MCICFG1Q_DIS_DMI_CHANNEL_FAIL_BIT     = 47;
constexpr uint8_t MCICFG1Q_DIS_CHINIT_TIMEOUT_BIT       = 48;
constexpr uint8_t MCICFG1Q_DIS_REPLAY_BUF_UE_BIT        = 49;
constexpr uint8_t MCICFG1Q_DIS_NO_FWD_PROGRESS_BIT      = 50;
constexpr uint8_t MCICFG1Q_DIS_DF_SM_PERR_BIT           = 51;
constexpr uint8_t MCICFG1Q_DIS_CEN_XSTOP_BIT            = 52;
constexpr uint8_t MCICFG1Q_DIS_INTERLOCK_FAIL_BIT       = 53;

// MCICFG0 bit
constexpr uint8_t MCICFG0Q_DISABLE_DSFF_CHANNEL_TIMEOUT_ERR_BIT = 46;

// CHIFIR bits
constexpr uint8_t FIR_DSRC_NO_FORWARD_PROGRESS_BIT   = 2;
constexpr uint8_t FIR_DMI_CHANNEL_FAIL_BIT           = 4;
constexpr uint8_t FIR_CHANNEL_INIT_TIMEOUT_BIT       = 5;
constexpr uint8_t FIR_CHANNEL_INTERLOCK_ERR_BIT      = 6;
constexpr uint8_t FIR_REPLAY_BUFFER_UE_BIT           = 12;
constexpr uint8_t FIR_REPLAY_BUFFER_OVERRUN_BIT      = 14;
constexpr uint8_t FIR_DF_SM_PERR_BIT                 = 15;
constexpr uint8_t FIR_CEN_CHECKSTOP_BIT              = 16;
constexpr uint8_t FIR_DSFF_TAG_OVERRUN_BIT           = 32;
constexpr uint8_t FIR_DSFF_MCA_ASYNC_CMD_ERROR_1_BIT = 40;
constexpr uint8_t FIR_DSFF_MCA_ASYNC_CMD_ERROR_2_BIT = 41;
constexpr uint8_t FIR_DSFF_SEQ_ERROR_BIT             = 42;
constexpr uint8_t FIR_DSFF_TIMEOUT_BIT               = 61;

// Bits used to describe L_chifir_cfgX_association arrays
constexpr int ASSOC_CHIFIR_BIT     = 0;
constexpr int ASSOC_CFG_BIT        = 1;
constexpr int ASSOC_FAILURE_ENABLE = 2;


// Array containing what bit to check in CHIFIR register
// if the bit in MCICFG1 is set to the Failure Enabled value
constexpr uint8_t L_CHIFIR_CFG1_ASSOCIATION[][3] =
{
    //                                                                      Failure
    // CHIFIR bit                        MCICFG1 bit                        Enabled
    {FIR_DSRC_NO_FORWARD_PROGRESS_BIT,   MCICFG1Q_DIS_NO_FWD_PROGRESS_BIT,      0},
    {FIR_DMI_CHANNEL_FAIL_BIT,           MCICFG1Q_DIS_DMI_CHANNEL_FAIL_BIT,     0},
    {FIR_CHANNEL_INIT_TIMEOUT_BIT,       MCICFG1Q_DIS_CHINIT_TIMEOUT_BIT,       0},
    {FIR_CHANNEL_INTERLOCK_ERR_BIT,      MCICFG1Q_DIS_INTERLOCK_FAIL_BIT,       0},
    {FIR_REPLAY_BUFFER_UE_BIT,           MCICFG1Q_DIS_REPLAY_BUF_UE_BIT,        0},
    {FIR_REPLAY_BUFFER_OVERRUN_BIT,      MCICFG1Q_DIS_BUF_OVERRUN_ERROR_BIT,    0},
    {FIR_DF_SM_PERR_BIT,                 MCICFG1Q_DIS_DF_SM_PERR_BIT,           0},
    {FIR_CEN_CHECKSTOP_BIT,              MCICFG1Q_DIS_CEN_XSTOP_BIT,            0},
    {FIR_DSFF_TAG_OVERRUN_BIT,           MCICFG1Q_DIS_TAG_OVERRUN_ERROR_BIT,    1},
    {FIR_DSFF_MCA_ASYNC_CMD_ERROR_1_BIT, MCICFG1Q_DIS_DSFF_ASYNC_CMD_ERROR_BIT, 0},
    {FIR_DSFF_MCA_ASYNC_CMD_ERROR_2_BIT, MCICFG1Q_DIS_DSFF_ASYNC_CMD_ERROR_BIT, 0},
    {FIR_DSFF_SEQ_ERROR_BIT,             MCICFG1Q_DIS_DSFF_SM_ERROR_BIT,        0}
};

// Array containing what bit to check in CHIFIR register
// if the bit in MCICFG0 is set to the Failure Enabled value
constexpr uint8_t L_CHIFIR_CFG0_ASSOCIATION[][3] =
{
    //                                                                      Failure
    // CHIFIR bit             MCICFG0 bit                                   Enabled
    {FIR_DSFF_TIMEOUT_BIT,    MCICFG0Q_DISABLE_DSFF_CHANNEL_TIMEOUT_ERR_BIT,    0}
};


/**
 * @brief HWP that checks for a channel failure associated with DMI target
 * Should be called for all valid/connected DMI endpoints
 *
 * @param[in] i_tgt     Reference to DMI chiplet target
 * @param[out] o_failed Channel failure status
 *
 * @return FAPI2_RC_SUCCESS on success, error otherwise
 */
fapi2::ReturnCode p9c_query_channel_failure(
    const fapi2::Target<fapi2::TARGET_TYPE_DMI>& i_tgt,
    bool& o_failed )
{
    FAPI_INF("Start (%s)", mss::c_str(i_tgt));

    // assume no channel failure to begin
    o_failed = false;

    // storage for register data
    fapi2::buffer<uint64_t> l_iomcfir_data;
    fapi2::buffer<uint64_t> l_scom_mode_pb_data;
    fapi2::buffer<uint64_t> l_chifir_data;
    fapi2::buffer<uint64_t> l_mcicfg1_data;
    fapi2::buffer<uint64_t> l_mcicfg0_data;

    do
    {
        // IOMCFIR
        //   - These FIRs exist on the MC targets.
        //   Each FIR characterizes the four DMI targets attached to the MC
        //  (DMI 0: bits 8-15,  DMI 1: bits 16-23,
        //   DMI 2: bits 24-31, DMI 3: bits 32-39).
        // - Each logical byte within that FIR is configured with
        //   SCOM_MODE_PB[15:22].
        // - So all that we need to do is AND the eight bits for the target DMI
        //   in the IOMCFIR with the eight bits from SCOM_MODE_PB. If the value
        //   is non-zero, there was a channel failure.

        // get the MC target from the child DMI
        const auto& l_mc_tgt = i_tgt.getParent<fapi2::TARGET_TYPE_MC>();

        FAPI_TRY(fapi2::getScom(l_mc_tgt, SCOM_IOMCFIR_ADDR, l_iomcfir_data),
                 "Error from getScom (IOMCFIR Register)");

        FAPI_TRY(fapi2::getScom(l_mc_tgt, SCOM_MODE_PB_ADDR, l_scom_mode_pb_data),
                 "Error from getScom (SCOM_MODE_PB Register)");


        // Calculate the starting index based on relative DMI target position
        // DMI 0: 8, DMI 1: 16, DMI 2: 24, DMI 3: 32
        uint32_t l_pos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FAPI_POS, i_tgt, l_pos));
        uint32_t l_iomcfir_idx = ((l_pos % DMI_TARGETS_PER_MC) + 1) * 8;

        uint8_t l_firData_byte = 0x00;
        uint8_t l_modePB_byte  = 0x00;

        // extract logical byte within the FIR based on DMI relative position
        FAPI_TRY( l_iomcfir_data.extract(l_firData_byte, l_iomcfir_idx, 8),
                  " Error grabbing IOMCFIR buffer" );

        // extract configuration byte at SCOM_MOD_PB[15:22]
        l_scom_mode_pb_data.extract<15, 8>(l_modePB_byte);

        // check for channel failure(s) in configured byte
        if ((l_firData_byte & l_modePB_byte) != 0)
        {
            FAPI_INF("Found channel failure in IOMCFIR (0x%02X & 0x%02X) "
                     "of %s target", l_firData_byte, l_modePB_byte,
                     mss::c_str(l_mc_tgt));
            o_failed = true;
            break;  // Found a channel failure, no need to keep looking for one
        }

        ////////////////////////////////////////////////////////////////
        // Check for channel failures using CHIFIR of the DMI target
        ////////////////////////////////////////////////////////////////
        FAPI_TRY(fapi2::getScom(i_tgt, SCOM_CHIFIR_ADDR, l_chifir_data),
                 "Error from getScom (CHIFIR Register)");

        FAPI_TRY(fapi2::getScom(i_tgt, SCOM_MCICFG1_ADDR, l_mcicfg1_data),
                 "Error from getScom (MCICFG1 Register)");


        /////////////////////////////////////////////////
        // Check the MCICFG1 data first
        /////////////////////////////////////////////////
        int rows = sizeof L_CHIFIR_CFG1_ASSOCIATION /
                   sizeof(L_CHIFIR_CFG1_ASSOCIATION[0]);

        for (int row = 0; row < rows; row++)
        {
            const uint8_t failure_enabled_value =
                L_CHIFIR_CFG1_ASSOCIATION[row][ASSOC_FAILURE_ENABLE];

            FAPI_DBG("%d) %s cfg1 bit %d (expect %d), failure bit %d",
                     row, mss::c_str(i_tgt),
                     L_CHIFIR_CFG1_ASSOCIATION[row][ASSOC_CFG_BIT],
                     failure_enabled_value,
                     L_CHIFIR_CFG1_ASSOCIATION[row][ASSOC_CHIFIR_BIT]);

            // First check for the failure as there should only be one channel fail attention
            // This check should only be true once, so placed first for better performance
            if (l_chifir_data.getBit(L_CHIFIR_CFG1_ASSOCIATION[row][ASSOC_CHIFIR_BIT]))
            {
                // now verify channel failure is enabled
                if (l_mcicfg1_data.getBit(L_CHIFIR_CFG1_ASSOCIATION[row][ASSOC_CFG_BIT])
                    == failure_enabled_value)
                {
                    // found channel failure
                    FAPI_INF("Found channel failure in bit %d of CHIFIR for %s target",
                             L_CHIFIR_CFG1_ASSOCIATION[row][ASSOC_CHIFIR_BIT],
                             mss::c_str(i_tgt));
                    o_failed = true;
                    break;
                }
            }
        }

        // Found a channel failure, no need to keep looking for one
        if (o_failed)
        {
            break;
        }

        /////////////////////////////////////////////////
        // Now check MCICFG0 data
        /////////////////////////////////////////////////
        FAPI_TRY(fapi2::getScom(i_tgt, SCOM_MCICFG0_ADDR, l_mcicfg0_data),
                 "Error from getScom (MCICFG0 Register)");

        rows = sizeof L_CHIFIR_CFG0_ASSOCIATION /
               sizeof(L_CHIFIR_CFG0_ASSOCIATION[0]);

        for (int row = 0; row < rows; row++)
        {
            const uint8_t failure_enabled_value =
                L_CHIFIR_CFG0_ASSOCIATION[row][ASSOC_FAILURE_ENABLE];

            FAPI_DBG("%d) %s cfg0 bit %d (expect %d), failure bit %d",
                     row, mss::c_str(i_tgt),
                     L_CHIFIR_CFG0_ASSOCIATION[row][ASSOC_CFG_BIT],
                     failure_enabled_value,
                     L_CHIFIR_CFG0_ASSOCIATION[row][ASSOC_CHIFIR_BIT]);


            // First check for the failure
            if (l_chifir_data.getBit(L_CHIFIR_CFG0_ASSOCIATION[row][ASSOC_CHIFIR_BIT]))
            {
                // Now verify that the channel failure is enabled
                if ( l_mcicfg0_data.getBit(L_CHIFIR_CFG0_ASSOCIATION[row][ASSOC_CFG_BIT])
                     == failure_enabled_value )
                {
                    // found channel failure
                    FAPI_INF("Found channel failure in bit %d of CHIFIR for %s target",
                             L_CHIFIR_CFG0_ASSOCIATION[row][ASSOC_CHIFIR_BIT],
                             mss::c_str(i_tgt));
                    o_failed = true;
                    break;
                }
            }
        }

    }
    while (0);

fapi_try_exit:
    FAPI_INF("End (%s)", mss::c_str(i_tgt));
    return fapi2::current_err;
}
