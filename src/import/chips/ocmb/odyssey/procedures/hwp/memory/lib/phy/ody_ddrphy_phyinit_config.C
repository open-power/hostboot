/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_ddrphy_phyinit_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
/* [+] International Business Machines Corp.                              */
/* [+] Synopsys, Inc.                                                     */
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

// Note: Synopsys, Inc. owns the original copyright of the code
// This file is ported into IBM's code stream with the permission of Synopsys, Inc.

// EKB-Mirror-To: hostboot
///
/// @file ody_ddrphy_phyinit_config.C
/// @brief Odyssey PHY init procedure functions
/// @note Using a separate file as simulation might need a different PHY init procedure for now
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB



#include <fapi2.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <lib/phy/ody_ddrphy_phyinit_structs.H>
#include <lib/phy/ody_ddrphy_phyinit_config.H>
#include <lib/phy/ody_ddrphy_csr_defines.H>
#include <lib/phy/ody_phy_utils.H>
#include <lib/phy/ody_phy_reset.H>

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

///
/// @brief Maps from drive strength in Ohms to the register value
/// @param[in] DrvStren_ohm drive strength in ohms
/// @return The register setting to be used
///
int dwc_ddrphy_phyinit_mapDrvStren (const int DrvStren_ohm)
{
    int Stren_setting;

    if      (DrvStren_ohm == 0)
    {
        Stren_setting = 0x00;    // High-impedance
    }
    else if (DrvStren_ohm < 26)
    {
        Stren_setting = 0x3f;    // 25.3 ohm
    }
    else if (DrvStren_ohm < 27)
    {
        Stren_setting = 0x3e;    // 26.7 ohm
    }
    else if (DrvStren_ohm < 29)
    {
        Stren_setting = 0x3d;    // 28.2 ohm
    }
    else if (DrvStren_ohm < 31)
    {
        Stren_setting = 0x3c;    // 30.0 ohm
    }
    else if (DrvStren_ohm < 33)
    {
        Stren_setting = 0x1f;    // 32.0 ohm
    }
    else if (DrvStren_ohm < 35)
    {
        Stren_setting = 0x1e;    // 34.3 ohm
    }
    else if (DrvStren_ohm < 38)
    {
        Stren_setting = 0x1d;    // 36.9 ohm
    }
    else if (DrvStren_ohm < 41)
    {
        Stren_setting = 0x1c;    // 40.0 ohm
    }
    else if (DrvStren_ohm < 45)
    {
        Stren_setting = 0x0f;    // 43.6 ohm
    }
    else if (DrvStren_ohm < 50)
    {
        Stren_setting = 0x0e;    // 48.0 ohm
    }
    else if (DrvStren_ohm < 56)
    {
        Stren_setting = 0x0d;    // 53.3 ohm
    }
    else if (DrvStren_ohm < 64)
    {
        Stren_setting = 0x0c;    // 60.0 ohm
    }
    else if (DrvStren_ohm < 74)
    {
        Stren_setting = 0x07;    // 68.6 ohm
    }
    else if (DrvStren_ohm < 88)
    {
        Stren_setting = 0x06;    // 80.0 ohm
    }
    else if (DrvStren_ohm < 108)
    {
        Stren_setting = 0x05;    // 96.0 ohm
    }
    else if (DrvStren_ohm < 140)
    {
        Stren_setting = 0x04;    // 120.0 ohm
    }
    else if (DrvStren_ohm < 200)
    {
        Stren_setting = 0x03;    // 160.0 ohm
    }
    else if (DrvStren_ohm < 360)
    {
        Stren_setting = 0x02;    // 240.0 ohm
    }
    else if (DrvStren_ohm < 481)
    {
        Stren_setting = 0x01;    // 480.0 ohm
    }
    else
    {
        Stren_setting = 0x00;    // High-impedance
    }

    return Stren_setting;
}



///
/// @brief Checks if a dbyte is disabled
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_user_input_basic - Synopsys basic user input structure
/// @param[in] i_user_input_dram_config - DRAM configuration inputs needed for PHY init (MRS/RCW)
/// @param[in] DbyteNumber the Dbyte to check to see if it is disabled
/// @param[out] o_rc fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @return 0 if enabled, 1 if disabled
///
int dwc_ddrphy_phyinit_IsDbyteDisabled( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        const user_input_basic_t& i_user_input_basic,
                                        const user_input_dram_config_t& i_user_input_dram_config,
                                        const int DbyteNumber,
                                        fapi2::ReturnCode& o_rc)
{
    int DisableDbyte;
    DisableDbyte = 0; // default assume Dbyte is Enabled.

    int nad0 = i_user_input_basic.NumActiveDbyteDfi0;
    int nad1 = i_user_input_basic.NumActiveDbyteDfi1;

    // DfiMode is 5 if 2 channel but only Dfi0 is connected and using more than half the dbyte.
    int isDfiMode5 = 0;

    // DDR5 BYTE Mapping variables.
    int db_first0 = 100; // Chan 0 first Dbyte num
    int db_last0  = 100; // Chan 0 last Dbyte num (excluded ECC)
    int db_ecc0   = 100; // Chan 0 ECC Dbyte num
    int db_first1 = 100; // Chan 1 first Dbyte num
    int db_last1  = 100; // Chan 1 last Dbyte num (excluded ECC)
    int db_ecc1   = 100; // Chan 1 ECC Dbyte num

    FAPI_ASSERT(DbyteNumber >= 0,
                fapi2::ODY_PHYINIT_INVALID_DBYTENUMBER().
                set_PORT_TARGET(i_target).
                set_DBYTENUMBER(DbyteNumber),
                TARGTIDFORMAT " invalid DbyteNumber %d", TARGTID, DbyteNumber);

    FAPI_ASSERT((nad0 + nad1) <= i_user_input_basic.NumDbyte,
                fapi2::ODY_PHYINIT_INVALID_CONFIGURATION().
                set_PORT_TARGET(i_target).
                set_NUMACTIVEDBYTEDFI0(nad0).
                set_NUMACTIVEDBYTEDFI1(nad1).
                set_NUMDBYTE(i_user_input_basic.NumDbyte),
                TARGTIDFORMAT " invalid PHY configuration:NumActiveDbyteDfi0(%d)+NumActiveDbyteDfi1(%d)>NumDbytes(%d).\n",
                TARGTID, nad0, nad1, i_user_input_basic.NumDbyte);

    // Implements Section 1.3 of Pub Databook

    if ((i_user_input_basic.Dfi1Exists == 1) &&
        (i_user_input_basic.NumActiveDbyteDfi1 == 0) &&
        (i_user_input_basic.NumActiveDbyteDfi0 > (i_user_input_basic.NumDbyte / 2)))
    {
        isDfiMode5 = 1;
    }

    // ##############################################
    // DDR5 BYTE Mapping depends on DfiMode.
    // DfiMode != 5:
    //   DDR5 DBYTE Mapping (NumDbyte > 5):
    //       channel-0 : 0,1,2,3,8(ecc)
    //       channel-1 : 4,5,6,7,9(ecc)
    //   DDR5 DBYTE Mapping (NumDbyte < 6, channel 0 only):
    //       channel-0 : 0,1,2,3,4(ecc)
    //   DDR5 DBYTE Mapping (NumDbyte < 6, two channels, no ecc can be supported):
    //       channel-0 : 0,1
    //       channel-1 : 2,3
    // DfiMode == 5:
    //       channel-0 : 0,1,2,3,4,...
    // ##############################################

    if (i_user_input_basic.NumDbyte > 6)
    {
        if (i_user_input_basic.NumActiveDbyteDfi0 > 0)
        {
            db_first0 = 0;

            if ((isDfiMode5 == 0) && (i_user_input_basic.NumActiveDbyteDfi0 > 4))
            {
                db_last0  = 3;
                db_ecc0   = 8;
            }
            else
            {
                db_last0  = 0 + i_user_input_basic.NumActiveDbyteDfi0 - 1;
            }
        }

        if (i_user_input_basic.NumActiveDbyteDfi1 > 0)
        {
            db_first1 = 4;

            if (i_user_input_basic.NumActiveDbyteDfi1 > 4)
            {
                db_last1  = 7;
                db_ecc1   = 9;
            }
            else
            {
                db_last1  = 4 + i_user_input_basic.NumActiveDbyteDfi1 - 1;
            }
        }
    }
    else if (i_user_input_basic.Dfi1Exists == 1)
    {
        // NumDbyte should be 4...
        if (i_user_input_basic.NumActiveDbyteDfi0 > 0)
        {
            // NumActiveDbyteDfi0 must be < 3
            db_first0 = 0;
            db_last0  = 0 + i_user_input_basic.NumActiveDbyteDfi0 - 1;
        }

        if (i_user_input_basic.NumActiveDbyteDfi1 > 0)
        {
            // NumActiveDbyteDfi1 must be < 3
            db_first1 = 0;
            db_last1  = 2 + i_user_input_basic.NumActiveDbyteDfi1 - 1;
        }
    }
    else     // Only channel 0 can be populated...
    {
        // NumActiveDbyteDfi0 must be > 0, can be 5 for ECC
        db_first0 = 0;
        db_last0  = 0 + i_user_input_basic.NumActiveDbyteDfi0 - 1;
    }

    // Disable dbyte outside dbyte range for channel 0 or 1
    if (! (((DbyteNumber >= db_first0) && (DbyteNumber <= db_last0 )) ||
           (DbyteNumber == db_ecc0)                                   ||
           ((DbyteNumber >= db_first1) && (DbyteNumber <= db_last1 )) ||
           (DbyteNumber == db_ecc1)                                  ) )
    {
        DisableDbyte = 1;
    }

    // Consider also DisableDbyte message block parameter
    if ((DbyteNumber < 8 ) && (i_user_input_dram_config.DisabledDbyte & (0x1 << DbyteNumber)))
    {
        DisableDbyte = 1;
    }

    // Qualify results against MessageBlock
    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return DisableDbyte;

fapi_try_exit:
    o_rc = fapi2::current_err;
    return DisableDbyte;
}

///
/// @brief Checks if 2T timing is needed for this configuration
/// @param[in] i_user_input_dram_config - DRAM configuration inputs needed for PHY init (MRS/RCW)
/// @return 0 if in 2N mode, otherwise 1
///
int dwc_ddrphy_phyinit_is2Ttiming(const user_input_dram_config_t& i_user_input_dram_config)
{
    int in_slow_mode = (i_user_input_dram_config.MR2_A0 & 0x4) ? 0 : 1;
    return in_slow_mode;
} // End if dwc_ddrphy_phyinit_is2Ttiming()

///
/// @brief Helper function to compute the globalVrefInDAD
/// @param[in] i_phy_vref the PHY vref from the data structure
/// @return the register setting for the global VREF DAC
///
int compute_global_vref_in_dac(const uint8_t i_phy_vref)
{
    // Note: 1000 could work, but 10,000 should give the code more precision
    // This code has been converted over from floats to using ints as the SBE cannot support float
    constexpr int SCALING_FACTOR = 10000;
    constexpr int PERCENT_DIVISOR = 128;
    constexpr int START = 3450;
    constexpr int PERCENT_TO_DAC = 50;
    const int PhyVrefPrcnt = (SCALING_FACTOR * i_phy_vref) / PERCENT_DIVISOR;
    const int GlobalVrefInDAC = (PhyVrefPrcnt - START) / PERCENT_TO_DAC;
    return GlobalVrefInDAC;
}

///
/// @brief Computes the ps count of the passed in value at a given frequency
/// @param[in] i_value the value to count
/// @param[in] i_freq the frequency
/// @return the ps count
///
int compute_ps_count(const int i_value, const int i_freq)
{
    return (int)( i_value * i_freq / 8000);
}

///
/// @brief Calculates the ticks per 1us
/// @param[in] i_mem_clock_freq - half the DDR frequency rate
/// @return calculates the number of ticks per 1 uS, rounding up
///
int calculate_clk_tick_per_1us(const int i_mem_clock_freq)
{
    return (i_mem_clock_freq / 2) + (i_mem_clock_freq % 2);
}

///
/// @brief Translates from the Synopsys register information and does the scom
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_addr - the Synopsys address on which to operate on
/// @param[in] i_data - the data to write out to the register
///
fapi2::ReturnCode dwc_ddrphy_phyinit_userCustom_io_write16(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_addr,
        const int i_data)
{
    fapi2::buffer<uint64_t> l_data(i_data);
    const uint64_t IBM_ADDR = mss::ody::phy::convert_synopsys_to_ibm_reg_addr(i_addr);

    // Prints out the Synopsys style for the register accesses
    // Note: this is added to facilitate with simulation and debugging
    // Need to split trace to limit variables per trace message to <= 4
    FAPI_LAB("dwc_ddrphy_apb_wr(32'h%x,16'h%x); // " TARGTIDFORMAT, i_addr, i_data, TARGTID);
    FAPI_LAB("                                  // " TARGTIDFORMAT " IBM ADDR:" UINT64FORMAT, TARGTID,
             UINT64_VALUE(IBM_ADDR));
    FAPI_LAB("                                  // " TARGTIDFORMAT " IBM data:" UINT64FORMAT, TARGTID,
             UINT64_VALUE(uint64_t(l_data)));

    return fapi2::putScom(i_target, IBM_ADDR, l_data);
}

///
/// @brief Configures the PHY to be ready for DRAMINIT
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_user_input_basic - Synopsys basic user input structure
/// @param[in] i_user_input_advanced - Synopsys advanced user input structure
/// @param[in] i_user_input_dram_config - DRAM configuration inputs needed for PHY init (MRS/RCW)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode init_phy_config( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                   const user_input_basic_t& i_user_input_basic,
                                   const user_input_advanced_t& i_user_input_advanced,
                                   const user_input_dram_config_t& i_user_input_dram_config)
{
    constexpr uint32_t pubRev = 0x350;

    FAPI_DBG ("////##############################################################");
    FAPI_DBG ("////");
    FAPI_DBG ("//// Step (C) Initialize PHY Configuration ");
    FAPI_DBG ("////");
    FAPI_DBG ("//// Load the required PHY configuration registers for the appropriate mode and memory configuration");
    FAPI_DBG ("////");
    FAPI_DBG ("////##############################################################");
    FAPI_DBG ("//");

    int lane;
    int b_addr;
    int byte;
    int anib;
    int c_addr;
    int p_addr;
    int r_addr;
    int tg;

    // Common used variables
    int WLm13;
    int RLm13;
    int VshCtrlUpdate = 0;
    int VREGCtrl3;

    int pstate;
    int f5200 = (((pubRev >= 0x0200) && (pubRev < 0x0300)) || (pubRev >= 0x0400));

    FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Start of dwc_ddrphy_phyinit_C_initPhyConfig()", TARGTID);


    //##############################################################
    // Forces the gaters of DfiTxClkEn and DfiRxClkEn to be 0
    // to clock gate part of the PUB
    // This is to prevent X propagation from CSRs on multi-cycle paths
    //##############################################################
    {
        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming ForceClkGaterEnables::ForcePubDxClkEnLow to 0x1",
                  TARGTID);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_ForceClkGaterEnables_ADDR),
                 csr_ForcePubDxClkEnLow_MASK ));
    }

    //##############################################################
    //
    // Set VshDAC based on DramType and userInputAdvanced.IsHighVDD
    //
    // VshCtrlUpdate is used as strobe by the hard macros to register
    // VshDAC values, it reset first here and set later in this function.
    //
    //##############################################################
    {
        int VshDAC_sub;
        int VshDAC;
        int VshCurrentLoad = 0;
        int VREGCtrl1;

        if (i_user_input_advanced.IsHighVDD)
        {
            VshDAC_sub = 0x13;
        }
        else
        {
            VshDAC_sub = 0x16;
        }


        VshDAC = VshDAC_sub;

        VREGCtrl1 = (VshDAC << csr_VshDAC_LSB) | (VshCurrentLoad << csr_VshCurrentLoad_LSB);
        VREGCtrl3 = (VshCtrlUpdate << csr_VshCtrlUpdate_LSB);

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for MASTER",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_VREGCtrl3_ADDR), VREGCtrl3));

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for all DBYTEs",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);

        for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
        {
            c_addr = byte << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tDBYTE | c_addr | csr_VREGCtrl3_ADDR), VREGCtrl3));
        }

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for all ANIBs",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);

        for (anib = 0; anib < i_user_input_basic.NumAnib; anib++)
        {
            c_addr = anib << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tANIB | c_addr | csr_VREGCtrl3_ADDR), VREGCtrl3));
        }

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            FAPI_DBG (TARGTIDFORMAT
                      " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl1::VshDAC to 0x%x for MASTER",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], VshDAC);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tMASTER | csr_VREGCtrl1_ADDR), VREGCtrl1));

            FAPI_DBG (TARGTIDFORMAT
                      " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl1::VshDAC to 0x%x for all DBYTEs",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], VshDAC);

            for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
            {
                c_addr = byte << 12;
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tDBYTE | c_addr | csr_VREGCtrl1_ADDR),
                         VREGCtrl1));
            }

            FAPI_DBG (TARGTIDFORMAT
                      " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl1::VshDAC to 0x%x for all ANIBs",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], VshDAC);

            for (anib = 0; anib < i_user_input_basic.NumAnib; anib++)
            {
                c_addr = anib << 12;
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tANIB | c_addr | csr_VREGCtrl1_ADDR),
                         VREGCtrl1));
            }

            // Program CSR:
            //    Seq0BGPR1: VREGCtrl1={VshDAC,VshCurrentLoad=0x1}
            //    Seq0BGPR2: VREGCtrl1={VshDAC,VshCurrentLoad=0x0}
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tINITENG | csr_Seq0BGPR1_ADDR),
                     ((VshDAC << csr_VshDAC_LSB) | (0x1 << csr_VshCurrentLoad_LSB))));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tINITENG | csr_Seq0BGPR2_ADDR),
                     ((VshDAC << csr_VshDAC_LSB) | (0x0 << csr_VshCurrentLoad_LSB))));
        }
    }

    //##############################################################
    //
    // Program CSR:
    //    TxSlewRate::TxPreDrvMode
    //    TxSlewRate::CsrTxSrc
    //
    // TxSlewRate::CsrTxSrc are technology-specific
    // User should consult the "Output Slew Rate" section of
    // HSpice Model App Note in specific technolog for recommended settings
    //
    //##############################################################
    {
        int TxSlewRate;
        int CsrTxSrc;
        int TxPreDrvMode;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            TxPreDrvMode = i_user_input_advanced.IsHighVDD;

            if(i_user_input_advanced.TxSlewRiseDQ[pstate] == 0 && i_user_input_advanced.TxSlewFallDQ[pstate] == 0)
            {
                CsrTxSrc = 0;
            }
            else
            {
                FAPI_DBG(TARGTIDFORMAT " Value check! %i %i %i %i", TARGTID, (i_user_input_advanced.IsHighVDD),
                         (i_user_input_basic.DramType),
                         (i_user_input_advanced.TxSlewRiseDQ[pstate]), (i_user_input_advanced.TxSlewFallDQ[pstate]));
                CsrTxSrc = (i_user_input_advanced.IsHighVDD << 6) | (i_user_input_basic.DramType << 5) |
                           (i_user_input_advanced.TxSlewRiseDQ[pstate] << 2) | (i_user_input_advanced.TxSlewFallDQ[pstate] << 0);
            }

            TxSlewRate = (TxPreDrvMode << csr_TxPreDrvMode_LSB) | (CsrTxSrc << csr_CsrTxSrc_LSB);

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxSlewRate::CsrTxSrc to 0x%x",
                      TARGTID,
                      pstate,  i_user_input_basic.Frequency[pstate], CsrTxSrc);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxSlewRate::TxPreDrvMode to 0x%x",
                      TARGTID,
                      pstate,  i_user_input_basic.Frequency[pstate], TxPreDrvMode);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxSlewRate to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], TxSlewRate);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] ### NOTE ### Optimal setting for TxSlewRate::CsrTxSrc are technology specific.",
                      TARGTID);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] ### NOTE ### Please consult the \"Output Slew Rate\" section of HSpice Model App Note in specific technology for recommended settings\n",
                      TARGTID);

            for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
            {
                c_addr = byte << 12;

                for (lane = 0; lane <= b_max ; lane++)
                {
                    b_addr = lane << 8;
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tDBYTE | c_addr | b_addr | csr_TxSlewRate_ADDR),
                             TxSlewRate));

                }
            }
        }
    }


    //##############################################################
    //
    // Program CSR:
    //    ATxSlewRate::ATxPreDrvMode
    //    ATxSlewRate::CsrATxSrc
    //
    // TxSlewRate::CsrATxSrc are technology-specific
    // User should consult the "Output Slew Rate" section of
    // HSpice Model App Note in specific technolog for recommended settings
    //
    //##############################################################
    {
        int ATxSlewRate;
        int CsrATxSrc;
        int ATxPreDrvMode;
        int ck_anib;
        //int EnableDischarge = 1; // This is TxPreDrvMode[8] and it's default to 1.

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            ATxPreDrvMode = i_user_input_advanced.IsHighVDD;

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ATxSlewRate::ATxPreDrvMode to 0x%x",
                      TARGTID,
                      pstate,  i_user_input_basic.Frequency[pstate], ATxPreDrvMode);

            for (anib = 0; anib < i_user_input_basic.NumAnib; anib++)
            {
                c_addr = anib << 12;

                if(anib == 5)
                {
                    ck_anib = 1;
                }
                else if(anib == 6 && (i_user_input_basic.NumAnib == 12 || i_user_input_basic.NumAnib == 14))
                {
                    ck_anib = 1;
                }
                // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
                else if((anib == 7 || anib == 8) && i_user_input_basic.NumAnib == 14)
                {
                    ck_anib = 1;
                }
                else
                {
                    ck_anib = 0;
                }

                CsrATxSrc = (i_user_input_advanced.IsHighVDD << 6) | (i_user_input_basic.DramType << 5) | (ck_anib << 4);

                if(ck_anib)
                {
                    CsrATxSrc |= (i_user_input_advanced.TxSlewRiseCK << 2) | (i_user_input_advanced.TxSlewFallCK << 0);
                }
                else
                {
                    CsrATxSrc |= (i_user_input_advanced.TxSlewRiseAC << 2) | (i_user_input_advanced.TxSlewFallAC << 0);
                }

                if((ck_anib && i_user_input_advanced.TxSlewRiseCK == 0 && i_user_input_advanced.TxSlewFallCK == 0) || (!ck_anib
                        && i_user_input_advanced.TxSlewRiseAC == 0 && i_user_input_advanced.TxSlewFallAC == 0))
                {
                    CsrATxSrc = 0;
                }

                ATxSlewRate = (ATxPreDrvMode << csr_ATxPreDrvMode_LSB) | (CsrATxSrc << csr_CsrATxSrc_LSB);

                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ATxSlewRate::CsrATxSrc ANIB %d to 0x%x",
                          TARGTID, pstate,  i_user_input_basic.Frequency[pstate], anib, CsrATxSrc);
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ATxSlewRate ANIB %d to 0x%x",
                          TARGTID, pstate,
                          i_user_input_basic.Frequency[pstate], anib, ATxSlewRate);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tANIB | c_addr | csr_ATxSlewRate_ADDR),
                         ATxSlewRate));
            }
        }

        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] ### NOTE ### Optimal setting for ATxSlewRate::CsrATxSrc are technology specific.",
                  TARGTID);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] ### NOTE ### Please consult the \"Output Slew Rate\" section of HSpice Model App Note in specific technology for recommended settings\n",
                  TARGTID);
    }


    //##############################################################
    //
    // Program CSR:
    //    CalPreDriverOverride::CsrTxOvSrc
    //    CalPreDriverOverride::TxCalBaseN
    //    CalPreDriverOverride::TxCalBaseP
    //
    // Dependencies:
    //      userInputAdvanced.TxSlewFallCK
    //      userInputAdvanced.TxSlewRiseCK
    //
    //##############################################################
    {
        const int DbTxCalBaseN = 0x1;
        const int DbTxCalBaseP = 0x1;
        const int ATxCalBaseN  = 0x1;
        const int ATxCalBaseP  = 0x1;
        int TxCalBaseN;
        int TxCalBaseP;
        TxCalBaseN = TxCalBaseP = (DbTxCalBaseN && DbTxCalBaseP) || (ATxCalBaseN && ATxCalBaseP);

        int TxOvSrc = (i_user_input_advanced.TxSlewFallCK << (csr_CsrTxOvSrc_LSB + 4)) | (i_user_input_advanced.TxSlewRiseCK <<
                      csr_CsrTxOvSrc_LSB);
        int MasterTxSlewRate = (TxOvSrc) | (TxCalBaseN << csr_TxCalBaseN_LSB) | (TxCalBaseP << csr_TxCalBaseP_LSB);

        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming CalPreDriverOverride::CsrTxOvSrc to 0x%x",
                  TARGTID, 0,  i_user_input_basic.Frequency[0], TxOvSrc);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming CalPreDriverOverride::TxCalBaseN to 0x%x",
                  TARGTID, 0,  i_user_input_basic.Frequency[0], TxCalBaseN);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming CalPreDriverOverride::TxCalBaseP to 0x%x",
                  TARGTID, 0,  i_user_input_basic.Frequency[0], TxCalBaseP);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming CalPreDriverOverride to 0x%x",
                  TARGTID, 0,
                  i_user_input_basic.Frequency[0], MasterTxSlewRate);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] ### NOTE ### Optimal setting for CalPreDriverOverride::CsrTxOvSrc are technology specific.",
                  TARGTID);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] ### NOTE ### Please consult the \"Output Slew Rate\" section of HSpice Model App Note in specific technology for recommended settings\n",
                  TARGTID);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_CalPreDriverOverride_ADDR),
                 MasterTxSlewRate));
    }



    //##############################################################
    //
    // Calculate PLL controls per p-state from Frequency
    // CSRs to program:
    //   PllCtrl2::PllFreqSel
    //   PllTestMode
    //   PllCtrl1::PllCpPropCtrl
    //   PllCtrl1::PllCpIntCtrl
    //   PllCtrl4::PllCpPropGsCtrl
    //   PllCtrl4::PllCpIntGsCtrl
    //
    // User input dependencies::
    //      Frequency
    //
    //##############################################################
    {
        int PllCtrl2;
        int PllFreqSel;
        int PllTestMode;
        int PllCtrl1;
        int PllCpPropCtrl;
        int PllCpIntCtrl;
        int PllCtrl4;
        int PllCpPropGsCtrl;
        int PllCpIntGsCtrl;
        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] PUB revision is 0x%04x.", TARGTID, pubRev);


        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            if (((pubRev >= 0x0250) && (pubRev < 0x0300)) || (pubRev >= 0x0400))
            {
                if (i_user_input_basic.Frequency[pstate] / 2 <= 235)
                {
                    PllFreqSel        = 0x7;
                    PllCpPropCtrl     = 0x10;
                    PllCpIntCtrl      = 0x4;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 <= 313)
                {
                    PllFreqSel        = 0x6;
                    PllCpPropCtrl     = 0x10;
                    PllCpIntCtrl      = 0x4;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 <= 469)
                {
                    PllFreqSel        = 0xb;
                    PllCpPropCtrl     = 0x3;
                    PllCpIntCtrl      = 0x1;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 <= 625)
                {
                    PllFreqSel        = 0xa;
                    PllCpPropCtrl     = 0x10;
                    PllCpIntCtrl      = 0x4;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 <= 938)
                {
                    PllFreqSel        = 0x19;
                    PllCpPropCtrl     = 0x10;
                    PllCpIntCtrl      = 0x4;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 <= 1250)
                {
                    PllFreqSel        = 0x18;
                    PllCpPropCtrl     = 0x10;
                    PllCpIntCtrl      = 0x4;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 <= 1400)
                {
                    PllFreqSel        = 0x18;
                    PllCpPropCtrl     = 0x10;
                    PllCpIntCtrl      = 0x4;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x4017;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 <= 1600)
                {
                    PllFreqSel        = 0x38;
                    PllCpPropCtrl     = 0x10;
                    PllCpIntCtrl      = 0x4;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x4017;
                }
                else
                {
                    PllFreqSel        = 0x38;
                    PllCpPropCtrl     = 0x10;
                    PllCpIntCtrl      = 0x4;
                    PllCpPropGsCtrl   = 0x04;
                    PllCpIntGsCtrl    = 0x1f;
                    PllTestMode       = 0x4017;
                }
            }
            else if ((pubRev >= 0x0310) && (pubRev < 0x0400))
            {
                if (i_user_input_basic.Frequency[pstate] / 2 < 235)
                {
                    PllFreqSel        = 0x7;
                    PllCpPropCtrl     = 0x3;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 313)
                {
                    PllFreqSel        = 0x6;
                    PllCpPropCtrl     = 0x2;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 469)
                {
                    PllFreqSel        = 0xb;
                    PllCpPropCtrl     = 0x3;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 625)
                {
                    PllFreqSel        = 0xa;
                    PllCpPropCtrl     = 0x2;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 938)
                {
                    PllFreqSel        = 0x19;
                    PllCpPropCtrl     = 0x3;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 1250)
                {
                    PllFreqSel        = 0x18;
                    PllCpPropCtrl     = 0x2;
                    PllTestMode       = 0x400f;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 1400)
                {
                    PllFreqSel        = 0x18;
                    PllCpPropCtrl     = 0x2;
                    PllTestMode       = 0x4017;
                }
                else
                {
                    PllFreqSel        = 0x18;
                    PllCpPropCtrl     = 0x2;
                    PllTestMode       = 0x4017;
                }

                PllCpIntCtrl        = 0x1;
                PllCpIntGsCtrl      = 0x12;
                PllCpPropGsCtrl     = 0x6;
            }
            else     // pubRev
            {
                PllCpIntCtrl = 0;
                PllCpPropGsCtrl = 0;
                PllCpIntGsCtrl = 0;

                if (i_user_input_basic.Frequency[pstate] / 2 < 235)
                {
                    PllFreqSel = 0x7;
                    PllCpPropCtrl = 0x1;
                    PllTestMode = 0x124;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 313)
                {
                    PllFreqSel = 0x6;
                    PllCpPropCtrl = 0x1;
                    PllTestMode = 0x124;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 469)
                {
                    PllFreqSel = 0xb;
                    PllCpPropCtrl = 0x1;
                    PllTestMode = 0x124;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 625)
                {
                    PllFreqSel = 0xa;
                    PllCpPropCtrl = 0x1;
                    PllTestMode = 0x124;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 938)
                {
                    PllFreqSel = 0x19;
                    PllCpPropCtrl = 0x1;
                    PllTestMode = 0x124;
                }
                else if(i_user_input_basic.Frequency[pstate] / 2 < 1200)
                {
                    PllFreqSel = 0x18;
                    PllCpPropCtrl = 0x1;
                    PllTestMode = 0x124;
                }
                else
                {
                    PllFreqSel = 0x18;
                    PllCpPropCtrl = 0x1;
                    PllTestMode = 0x124;
                }
            }


            PllCtrl2 = (PllFreqSel << csr_PllFreqSel_LSB);
            PllCtrl1 = (PllCpPropCtrl << csr_PllCpPropCtrl_LSB) | (PllCpIntCtrl << csr_PllCpIntCtrl_LSB);
            PllCtrl4 = (PllCpPropGsCtrl << csr_PllCpPropGsCtrl_LSB) | (PllCpIntGsCtrl << csr_PllCpIntGsCtrl_LSB);

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllCtrl2::PllFreqSel to 0x%x based on DfiClk frequency = %d.",
                      TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCtrl2,
                      i_user_input_basic.Frequency[pstate] / 2);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tMASTER | csr_PllCtrl2_ADDR), PllCtrl2 ));

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllCtrl1::PllCpPropCtrl to 0x%x based on DfiClk frequency = %d.",
                      TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCpPropCtrl,
                      i_user_input_basic.Frequency[pstate] / 2);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllCtrl1::PllCpIntCtrl to 0x%x based on DfiClk frequency = %d.",
                      TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCpIntCtrl,
                      i_user_input_basic.Frequency[pstate] / 2);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllCtrl1 to 0x%x based on DfiClk frequency = %d.",
                      TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCtrl1,
                      i_user_input_basic.Frequency[pstate] / 2);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tMASTER | csr_PllCtrl1_ADDR), PllCtrl1 ));

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllTestMode to 0x%x based on DfiClk frequency = %d.",
                      TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllTestMode & 0xffff,
                      i_user_input_basic.Frequency[pstate] / 2);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tMASTER | csr_PllTestMode_ADDR),
                     PllTestMode & 0xffff));


            if (pubRev >= 0x400)
            {
                int PllTestModeHi = PllTestMode >> 16;
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllTestModeHi to 0x%x based on DfiClk frequency = %d.",
                          TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllTestModeHi,
                          i_user_input_basic.Frequency[pstate] / 2);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tMASTER | csr_PllTestModeHi_ADDR),
                         PllTestModeHi ));
            }

            if (((pubRev >= 0x0310) && (pubRev < 0x0400)) || ((pubRev >= 0x0250) && (pubRev < 0x0300)) || (pubRev >= 0x0400))
            {
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllCtrl4::PllCpPropGsCtrl to 0x%x based on DfiClk frequency = %d.",
                          TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCpPropGsCtrl,
                          i_user_input_basic.Frequency[pstate] / 2);
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllCtrl4::PllCpIntGsCtrl to 0x%x based on DfiClk frequency = %d.",
                          TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCpIntGsCtrl,
                          i_user_input_basic.Frequency[pstate] / 2);
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming PllCtrl4 to 0x%x based on DfiClk frequency = %d.",
                          TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCtrl4,
                          i_user_input_basic.Frequency[pstate] / 2);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tMASTER | csr_PllCtrl4_ADDR), PllCtrl4 ));
            }
            else
            {
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, [NOT] Programming PllCtrl4::PllCpPropGsCtrl to 0x%x based on DfiClk frequency = %d.",
                          TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCpPropGsCtrl,
                          i_user_input_basic.Frequency[pstate] / 2);
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, [NOT] Programming PllCtrl4::PllCpIntGsCtrl to 0x%x based on DfiClk frequency = %d.",
                          TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCpIntGsCtrl,
                          i_user_input_basic.Frequency[pstate] / 2);
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, [NOT] Programming PllCtrl4 to 0x%x based on DfiClk frequency = %d.",
                          TARGTID, pstate,  i_user_input_basic.Frequency[pstate], PllCtrl4,
                          i_user_input_basic.Frequency[pstate] / 2);
            }

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] ### NOTE ### Optimal setting for PllCtrl1 and PllTestMode are technology specific.",
                      TARGTID);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] ### NOTE ### Please consult technology specific PHY Databook for recommended settings\n",
                      TARGTID);
        }
    }

    //##############################################################
    //
    // Program ARdPtrInitVal based on Frequency and PLL Bypass inputs
    // The values programmed here assume ideal properties of DfiClk
    // and Pclk including:
    // - DfiClk skew
    // - DfiClk jitter
    // - DfiClk PVT variations
    // - Pclk skew
    // - Pclk jitter
    //
    // PLL Bypassed mode:
    //     For MemClk frequency > 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 2-5
    //     For MemClk frequency < 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 1-5
    //
    // PLL Enabled mode:
    //     For MemClk frequency > 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 1-5
    //     For MemClk frequency < 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 0-5
    //
    //
    // CSRs to program:
    //    ARdPtrInitVal_px
    //
    //##############################################################
    {
        int ARdPtrInitVal[4] = {};
        FAPI_DBG ("");
        FAPI_DBG ("////##############################################################");
        FAPI_DBG ("////");
        FAPI_DBG ("//// Program ARdPtrInitVal based on Frequency and PLL Bypass inputs");
        FAPI_DBG ("//// The values programmed here assume ideal properties of DfiClk");
        FAPI_DBG ("//// and Pclk including:");
        FAPI_DBG ("//// - DfiClk skew");
        FAPI_DBG ("//// - DfiClk jitter");
        FAPI_DBG ("//// - DfiClk PVT variations");
        FAPI_DBG ("//// - Pclk skew");
        FAPI_DBG ("//// - Pclk jitter");
        FAPI_DBG ("////");
        FAPI_DBG ("//// PLL Bypassed mode:");
        FAPI_DBG ("////     For MemClk frequency > 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 2-5");
        FAPI_DBG ("////     For MemClk frequency < 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 1-5");
        FAPI_DBG ("////");
        FAPI_DBG ("//// PLL Enabled mode:");
        FAPI_DBG ("////     For MemClk frequency > 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 1-5");
        FAPI_DBG ("////     For MemClk frequency < 933MHz, the valid range of ARdPtrInitVal_p0[3:0] is: 0-5");
        FAPI_DBG ("////");
        FAPI_DBG ("////##############################################################" );

        //
        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            if((i_user_input_basic.Frequency[pstate] == 3200))
            {
                ARdPtrInitVal[pstate] = 0x3;
            }
            else if (i_user_input_basic.Frequency[pstate] >= 933)
            {
                ARdPtrInitVal[pstate] = 0x1;
            }
            else
            {
                ARdPtrInitVal[pstate] = 0x0;
            }

            // Add one UI for synchronizer on SyncBus when PLL is bypassed
            if (i_user_input_basic.PllBypass[pstate] == 1)
            {
                ARdPtrInitVal[pstate] ++;
            }

            if(i_user_input_basic.ARdPtrInitValOvr == 0)
            {
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ARdPtrInitVal to 0x%x",
                          TARGTID, pstate,
                          i_user_input_basic.Frequency[pstate], ARdPtrInitVal[pstate]);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_ARdPtrInitVal_ADDR),
                         ARdPtrInitVal[pstate]));
            }
            else
            {
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ARdPtrInitVal to 0x%x",
                          TARGTID, pstate,
                          i_user_input_basic.Frequency[pstate], i_user_input_basic.ARdPtrInitVal[pstate]);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_ARdPtrInitVal_ADDR),
                         i_user_input_basic.ARdPtrInitVal[pstate]));
            }
        }

        if (pubRev >= 0x200)
        {
            //##############################################################
            // programming DisPtrInitClrTxTracking based on user input
            //
            //##############################################################
            for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
            {
                p_addr = pstate << 20;
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DisPtrInitClrTxTracking to 0x%x",
                          TARGTID,
                          pstate, i_user_input_basic.Frequency[pstate], i_user_input_basic.DisPtrInitClrTxTracking[pstate]);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_PtrInitTrackingModeCntrl_ADDR),
                         i_user_input_basic.DisPtrInitClrTxTracking[pstate]));
            }
        }
    }

    //##############################################################
    //
    // Program DqsPreambleControl based on DramType
    //
    // CSRs to program:
    //      DqsPreambleControl::TwoTckRxDqsPre
    //                        ::TwoTckTxDqsPre
    //                        ::PositionDfeInit
    //                        ::DisDlyAdjPosDI
    //                        ::WDQSEXTENSION
    //                        ::DDR5RxPreambleEn
    //                        ::DDR5RxPreamble
    //                        ::DDR5RxPostamble
    //                        ::PositionTxPhaseUpdate
    //                        ::PositionRxPhaseUpdate
    //
    // User input dependencies::
    //      DramType
    //
    //##############################################################
    {
        int DqsPreambleControl;
        int TwoTckRxDqsPre[4];
        int TwoTckTxDqsPre = 0;
        int PositionDfeInit;
        int WDQSEXTENSION = 0;
        int DDR5RxPreambleEn = 0;
        int DDR5RxPreamble;
        int DDR5RxPostamble;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {

            p_addr = pstate << 20;



            // DDR5

            DDR5RxPreambleEn           = 0x1;
            DDR5RxPreamble             = (i_user_input_dram_config.MR8_A0 & 0x4) | (i_user_input_dram_config.MR8_A0 & 0x2) |
                                         (i_user_input_dram_config.MR8_A0 & 0x1); // MR8[2:0] Read Preamble Settings
            DDR5RxPostamble            = (i_user_input_dram_config.MR8_A0 & 0x40) >> 6; // MR8[6:6] Read Postamble Settings
            TwoTckRxDqsPre[pstate]     = 0x0;
            TwoTckTxDqsPre             = 0;
            PositionDfeInit            = 0x2;
            WDQSEXTENSION              = 0x0;



            DqsPreambleControl = (DDR5RxPostamble << csr_DDR5RxPostamble_LSB) | (DDR5RxPreamble << csr_DDR5RxPreamble_LSB) |
                                 (DDR5RxPreambleEn << csr_DDR5RxPreambleEn_LSB) | (WDQSEXTENSION << csr_WDQSEXTENSION_LSB) |
                                 (PositionDfeInit << csr_PositionDfeInit_LSB) | (TwoTckTxDqsPre << csr_TwoTckTxDqsPre_LSB) |
                                 (TwoTckRxDqsPre[pstate] << csr_TwoTckRxDqsPre_LSB) ;

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreambleControl::TwoTckRxDqsPre  to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TwoTckRxDqsPre[pstate]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreambleControl::TwoTckTxDqsPre  to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TwoTckTxDqsPre);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreambleControl::PositionDfeInit to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], PositionDfeInit);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreambleControl::DDR5RxPreamble  to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], DDR5RxPreamble);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreambleControl::DDR5RxPostamble to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], DDR5RxPostamble);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreambleControl                  to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], DqsPreambleControl);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_DqsPreambleControl_ADDR),
                     DqsPreambleControl));

        }
    }

    //##############################################################
    //
    // For DDR5, program:
    //      DqsPreamblePattern
    //      DqsPostamblePattern
    //      DqPreamblePattern
    //      DmPreamblePattern
    //
    //##############################################################
    {
        int DqsPreamblePattern;
        // Note: needed to avoid a compile error
        // All others are uninitialized to keep as close as possible to the original source
        int EnTxDqsPreamblePattern = 0;
        int TxDqsPreamblePattern = 0;

        int WrPost;
        int DqsPostamblePattern;
        int EnTxDqsPostamblePattern;
        int TxDqsPostamblePattern;

        int DmPreamblePattern;
        int DqPreamblePatternU0;
        int DqPreamblePatternU1;
        // Note: needed to avoid a compile error
        // All others are uninitialized to keep as close as possible to the original source
        int EnTxDqPreamblePattern = 0;
        int TxDqPreamblePattern = 0;
        int WrPre;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;
            WrPre = ((i_user_input_dram_config.MR8_A0 & 0x8) >> 3) |
                    ((i_user_input_dram_config.MR8_A0 & 0x10) >> 3); // MR8[4:3] Write Preamble Settings
            WrPost = (i_user_input_dram_config.MR8_A0 & 0x80) >> 7; // MR8[7:7] Write Postamble Settings

            //############################################
            // DqsPreamblePattern
            //############################################
            switch (WrPre)
            {
                case 1 :
                    EnTxDqsPreamblePattern = 0x07;
                    TxDqsPreamblePattern   = 0x01;
                    break;

                case 2 :
                    EnTxDqsPreamblePattern = 0x1f;
                    TxDqsPreamblePattern   = 0x01;
                    break;

                case 3 :
                    EnTxDqsPreamblePattern = 0x7f;
                    TxDqsPreamblePattern   = 0x05;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::ODY_PHYINIT_INVALID_WRITE_PREAMBLE().
                                set_PORT_TARGET(i_target).
                                set_WRPRE(WrPre).
                                set_MR8A0(i_user_input_dram_config.MR8_A0),
                                TARGTIDFORMAT " Pstate=%d, Invalid value for Write Preamble Settings - MR8[4:3] = %d. Valid range is 1 - 3. (MR8 = %x)",
                                TARGTID, pstate, WrPre, i_user_input_dram_config.MR8_A0);
            }

            DqsPreamblePattern = (EnTxDqsPreamblePattern << csr_EnTxDqsPreamblePattern_LSB) | (TxDqsPreamblePattern <<
                                 csr_TxDqsPreamblePattern_LSB);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreamblePattern::EnTxDqsPreamblePattern to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], EnTxDqsPreamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreamblePattern::TxDqsPreamblePattern to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TxDqsPreamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPreamblePattern to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], DqsPreamblePattern);

            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_DqsPreamblePattern_ADDR),
                     DqsPreamblePattern));

            //############################################
            // DqsPostamblePattern
            //############################################
            switch (WrPost)
            {
                case 0 :
                    EnTxDqsPostamblePattern = 0x0;
                    TxDqsPostamblePattern   = 0x0;
                    break;

                case 1 :
                    EnTxDqsPostamblePattern = 0xc;
                    TxDqsPostamblePattern   = 0x0;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::ODY_PHYINIT_INVALID_WRITE_POSTAMBLE().
                                set_PORT_TARGET(i_target).
                                set_WRPOST(WrPost).
                                set_MR8A0(i_user_input_dram_config.MR8_A0),
                                TARGTIDFORMAT
                                " Pstate=%d, Invalid value for Write Postamble Settings - MR8[7:7] = %d. Valid range is 0 - 1. (MR8 = %x)",
                                TARGTID, pstate, WrPost, i_user_input_dram_config.MR8_A0);
            }

            DqsPostamblePattern = (EnTxDqsPostamblePattern << csr_EnTxDqsPostamblePattern_LSB) |
                                  (TxDqsPostamblePattern << csr_TxDqsPostamblePattern_LSB);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPostamblePattern::EnTxDqsPostamblePattern to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], EnTxDqsPostamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPostamblePattern::TxDqsPostamblePattern to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TxDqsPostamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqsPostamblePattern to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], DqsPostamblePattern);

            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_DqsPostamblePattern_ADDR),
                     DqsPostamblePattern));


            //############################################
            // DqPreamblePattern
            //############################################
            switch (i_user_input_advanced.D5TxDqPreambleCtrl[pstate])
            {
                case 0 :
                    EnTxDqPreamblePattern = 0x0;
                    TxDqPreamblePattern   = 0x0;
                    break;

                case 1 :
                    EnTxDqPreamblePattern = 0xf;
                    TxDqPreamblePattern   = 0x5;
                    break;

                case 2 :
                    EnTxDqPreamblePattern = 0xf;
                    TxDqPreamblePattern   = 0x5;
                    break;

                case 3 :
                    EnTxDqPreamblePattern = 0xf;
                    TxDqPreamblePattern   = 0x5;
                    break;

                case 4 :
                    EnTxDqPreamblePattern = 0xf;
                    TxDqPreamblePattern   = 0x5;
                    break;

                default:
                    FAPI_ASSERT(false,
                                fapi2::ODY_PHYINIT_INVALID_PREAMBLE_CTRL().
                                set_PORT_TARGET(i_target).
                                set_PREAMBLECTRL(i_user_input_advanced.D5TxDqPreambleCtrl[pstate]),
                                TARGTIDFORMAT " Invalid value for userInputAdvanced.D5TxDqPreambleCtrl[%d] = %d. Valid range is 0 - 4.",
                                TARGTID, pstate, i_user_input_advanced.D5TxDqPreambleCtrl[pstate]);
            }

            DmPreamblePattern = (EnTxDqPreamblePattern << csr_EnTxDmPreamblePattern_LSB) | (TxDqPreamblePattern <<
                                csr_TxDmPreamblePattern_LSB);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DmPreamblePattern::EnTxDmPreamblePattern to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], EnTxDqPreamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DmPreamblePattern::TxDmPreamblePattern to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], EnTxDqPreamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DmPreamblePattern to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], DmPreamblePattern);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_DmPreamblePattern_ADDR),
                     DmPreamblePattern));

            DqPreamblePatternU0 = (EnTxDqPreamblePattern << csr_EnTxDqPreamblePatternU0_LSB) | (TxDqPreamblePattern <<
                                  csr_TxDqPreamblePatternU0_LSB);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqPreamblePatternU0::EnTxDqPreamblePatternU0 to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], EnTxDqPreamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqPreamblePatternU0::TxDqPreamblePatternU0 to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], EnTxDqPreamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqPreamblePatternU0 to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], DqPreamblePatternU0);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_DqPreamblePatternU0_ADDR),
                     DqPreamblePatternU0));

            DqPreamblePatternU1 = (EnTxDqPreamblePattern << csr_EnTxDqPreamblePatternU1_LSB) | (TxDqPreamblePattern <<
                                  csr_TxDqPreamblePatternU1_LSB);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqPreamblePatternU1::EnTxDqPreamblePatternU1 to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], EnTxDqPreamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqPreamblePatternU1::TxDqPreamblePatternU1 to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], EnTxDqPreamblePattern);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DqPreamblePatternU1 to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], DqPreamblePatternU1);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_DqPreamblePatternU1_ADDR),
                     DqPreamblePatternU1));

        }
    }


    //##############################################################
    //
    // Program DbyteDllModeCntrl based on DramType and MR50.OP[0]
    //
    // CSRs to program:
    //      DbyteDllModeCntrl::DllRxPreambleMode
    //      DbyteDllModeCntrl::DllRxBurstLengthMode
    //
    // User input dependencies::
    //      MR50.OP[0] (Read CRC Enable, DDR5 only)
    //
    //##############################################################
    {
        int DbyteDllModeCntrl;
        int DllRxPreambleMode;
        int DllRxBurstLengthMode;

        DllRxPreambleMode = 0x1; // togglging read preamble in DDR4 and DDR5



        int D5ReadCRCEnable = i_user_input_dram_config.MR50_A0 & 0x1; // MR50:OP[0:0] (Read CRC Enable)
        DllRxBurstLengthMode = D5ReadCRCEnable;


        DbyteDllModeCntrl = (DllRxPreambleMode << csr_DllRxPreambleMode_LSB) | (DllRxBurstLengthMode <<
                            csr_DllRxBurstLengthMode_LSB);

        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming DbyteDllModeCntrl::DllRxPreambleMode to 0x%x",
                  TARGTID,
                  DllRxPreambleMode);
        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming DbyteDllModeCntrl::DllRxBurstLengthMode to 0x%x",
                  TARGTID,
                  DllRxBurstLengthMode);
        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming DbyteDllModeCntrl to 0x%x", TARGTID,
                  DbyteDllModeCntrl);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_DbyteDllModeCntrl_ADDR), DbyteDllModeCntrl));
    }




    //##############################################################
    //
    // Program TxOdtDrvStren based on Dram type and user desired
    // ODT strength
    //
    // CSRs to program:
    //   TxOdtDrvStren::TxOdtStrenPu_px[5:0]
    //                ::TxOdtStrenPd_px[11:6]
    //
    // User input dependencies:
    //   DramType
    //   ODTImpedance
    //
    //##############################################################
    {
        int TxOdtDrvStren[4];
        int TxOdtStrenPu[4];
        int TxOdtStrenPd[4];

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            // DDR5 & DDR4 - P is non-zero, N is high-Z
            //TxOdtStrenPu[pstate] = map_TxOdtDrvStren(i_user_input_advanced.ODTImpedance[pstate]);
            TxOdtStrenPu[pstate] = dwc_ddrphy_phyinit_mapDrvStren(i_user_input_advanced.ODTImpedance[pstate]);
            TxOdtStrenPd[pstate] = 0;
            TxOdtDrvStren[pstate] = (TxOdtStrenPd[pstate] << csr_TxOdtStrenPd_LSB) | TxOdtStrenPu[pstate];

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxOdtDrvStren::TxOdtStrenPu to 0x%x",
                      TARGTID,
                      pstate, i_user_input_basic.Frequency[pstate], TxOdtStrenPu[pstate]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxOdtDrvStren::TxOdtStrenPd to 0x%x",
                      TARGTID,
                      pstate, i_user_input_basic.Frequency[pstate], TxOdtStrenPd[pstate]);

            //dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tDBYTE | cbrd | bbrd | csr_TxOdtDrvStren_ADDR), TxOdtDrvStren[pstate]);
            for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
            {
                c_addr = byte << 12;

                //FAPI_DBG ("\tPHYINT: Writing TxOdtDrvStren/1/2/3 for Dbyte %pstate", byte);
                for (lane = 0; lane <= b_max ; lane++)
                {
                    b_addr = lane << 8;
                    //FAPI_DBG ("\t\tPHYINT: Writing TxDqDlyTg0/1/2/3 for b_addr = %pstate", lane);
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,
                             (p_addr | tDBYTE | c_addr | b_addr | csr_TxOdtDrvStren_ADDR),
                             TxOdtDrvStren[pstate]));
                }
            }
        }
    }

    //##############################################################
    //
    // Program ATxImpedance based on user desired Address Tx drive strength
    //
    // CSRs to program:
    //   ATxImpedance::ADrvStrenP[5:0]
    //               ::ADrvStrenN[11:6]
    //               ::ATxReserved13x12[13:12]
    //               ::ATxCalBaseN[14:14]
    //               ::ATxCalBaseP[15:15]
    //
    // User input dependencies:
    //   ATxImpedance
    //##############################################################
    {
        int ATxImpedance     = i_user_input_advanced.ATxImpedance;
        int ADrvStrenP       = (ATxImpedance & csr_ADrvStrenP_MASK)       >> csr_ADrvStrenP_LSB;
        int ADrvStrenN       = (ATxImpedance & csr_ADrvStrenN_MASK)       >> csr_ADrvStrenN_LSB;
        int ATxReserved13x12 = (ATxImpedance & csr_ATxReserved13x12_MASK) >> csr_ATxReserved13x12_LSB;
        int ATxCalBaseN_a    = (ATxImpedance & csr_ATxCalBaseN_MASK)      >> csr_ATxCalBaseN_LSB;
        int ATxCalBaseP_a    = (ATxImpedance & csr_ATxCalBaseP_MASK)      >> csr_ATxCalBaseP_LSB;

        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ATxImpedance::ADrvStrenP to 0x%x",
                  TARGTID, 0,
                  i_user_input_basic.Frequency[0], ADrvStrenP);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ATxImpedance::ADrvStrenN to 0x%x",
                  TARGTID, 0,
                  i_user_input_basic.Frequency[0], ADrvStrenN);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ATxImpedance::ATxReserved13x12 to 0x%x",
                  TARGTID, 0, i_user_input_basic.Frequency[0], ATxReserved13x12);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ATxImpedance::ATxCalBaseN to 0x%x",
                  TARGTID,
                  0, i_user_input_basic.Frequency[0], ATxCalBaseN_a);
        FAPI_DBG (TARGTIDFORMAT
                  " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming ATxImpedance::ATxCalBaseP to 0x%x",
                  TARGTID,
                  0, i_user_input_basic.Frequency[0], ATxCalBaseP_a);

        for (anib = 0 ; anib < i_user_input_basic.NumAnib; anib++)
        {
            c_addr = anib << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | c_addr | csr_ATxImpedance_ADDR), ATxImpedance));
        }
    }

    //##############################################################
    //
    // Program TxImpedanceCtrl0,1,2 based on user desired Tx drive strength
    //
    // CSRs to program:
    //   TxImpedanceCtrl0::TxStrenEqHiPu_px[5:0]
    //                   ::TxStrenEqLoPd_px[11:6]
    //
    //   TxImpedanceCtrl1::TxStrenPu_px[5:0]
    //                   ::TxStrenPd_px[11:6]
    //
    //   TxImpedanceCtrl2::TxStrenEqLoPu_px[5:0]
    //                   ::TxStrenEqHiPd_px[11:6]
    //
    // User input dependencies:
    //   TxImpedance
    //   TxImpedanceCtrl1
    //   TxImpedanceCtrl2
    //##############################################################
    {
        int TxImpedanceCtrl0[4];
        int TxStrenEqHiPu[4];
        int TxStrenEqLoPd[4];

        int TxImpedanceCtrl1[4];
        int TxStrenPu[4];
        int TxStrenPd[4];

        int TxImpedanceCtrl2[4];
        int TxStrenEqLoPu[4];
        int TxStrenEqHiPd[4];

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            TxStrenEqHiPu[pstate] = dwc_ddrphy_phyinit_mapDrvStren (i_user_input_advanced.TxImpedance[pstate]);
            TxStrenEqLoPd[pstate] = TxStrenEqHiPu[pstate];

            TxStrenPu[pstate]     = dwc_ddrphy_phyinit_mapDrvStren (i_user_input_advanced.TxImpedanceCtrl1[pstate]);
            TxStrenPd[pstate]     = TxStrenPu[pstate];

            TxStrenEqLoPu[pstate] = (i_user_input_advanced.TxImpedanceCtrl2[pstate] & csr_TxStrenEqLoPu_MASK) >>
                                    csr_TxStrenEqLoPu_LSB;
            TxStrenEqHiPd[pstate] = (i_user_input_advanced.TxImpedanceCtrl2[pstate] & csr_TxStrenEqHiPd_MASK) >>
                                    csr_TxStrenEqHiPd_LSB;

            TxImpedanceCtrl0[pstate] = (TxStrenEqLoPd[pstate] << csr_TxStrenEqLoPd_LSB) | (TxStrenEqHiPu[pstate] <<
                                       csr_TxStrenEqHiPu_LSB);
            TxImpedanceCtrl1[pstate] = (TxStrenPd[pstate]     << csr_TxStrenPd_LSB)     | (TxStrenPu[pstate]     <<
                                       csr_TxStrenPu_LSB);
            TxImpedanceCtrl2[pstate] = (TxStrenEqHiPd[pstate] << csr_TxStrenEqHiPd_LSB) | (TxStrenEqLoPu[pstate] <<
                                       csr_TxStrenEqLoPu_LSB);


            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxImpedanceCtrl0::TxStrenEqHiPu to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TxStrenEqHiPu[pstate]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxImpedanceCtrl0::TxStrenEqLoPd to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TxStrenEqLoPd[pstate]);

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxImpedanceCtrl1::TxStrenPu to 0x%x",
                      TARGTID,
                      pstate, i_user_input_basic.Frequency[pstate], TxStrenPu[pstate]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxImpedanceCtrl1::TxStrenPd to 0x%x",
                      TARGTID,
                      pstate, i_user_input_basic.Frequency[pstate], TxStrenPd[pstate]);

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxImpedanceCtrl2::TxStrenEqLoPu to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TxStrenEqLoPu[pstate]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TxImpedanceCtrl2::TxStrenEqHiPd to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TxStrenEqHiPd[pstate]);

            for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
            {
                c_addr = byte << 12;

                for (lane = 0; lane <= b_max ; lane++)
                {
                    b_addr = lane << 8;
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,
                             (p_addr | tDBYTE | c_addr | b_addr | csr_TxImpedanceCtrl0_ADDR),
                             TxImpedanceCtrl0[pstate]));
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,
                             (p_addr | tDBYTE | c_addr | b_addr | csr_TxImpedanceCtrl1_ADDR),
                             TxImpedanceCtrl1[pstate]));
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,
                             (p_addr | tDBYTE | c_addr | b_addr | csr_TxImpedanceCtrl2_ADDR),
                             TxImpedanceCtrl2[pstate]));
                }
            }
        }
    }

    //##############################################################
    //
    // Program DfiMode based on dram type and DFI related user inputs.
    //
    // CSRs to program:
    //      DfiMode
    //
    // User input dependencies::
    //      DramType
    //      Dfi1Exists
    //
    //##############################################################
    {
        int DfiMode;

        if(i_user_input_basic.Dfi1Exists == 1)
        {
            if (i_user_input_basic.NumActiveDbyteDfi1 > 0)
            {
                DfiMode = 0x3;    // Both DFI0 and DFI1 active
            }
            else if (i_user_input_basic.NumActiveDbyteDfi0 > (i_user_input_basic.NumDbyte / 2))
            {
                DfiMode = 0x5;    // Only DFI0 active, but control both channel
            }
            else
            {
                DfiMode = 0x1;    // Only DFI0 active
            }
        }
        else
        {
            DfiMode = 0x1;      // DFI1 does not physically exists
        }

        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming DfiMode to 0x%x", TARGTID, DfiMode);
        FAPI_TRY( dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_DfiMode_ADDR), DfiMode));

    }



    //##############################################################
    //
    // Program DfiCAMode based on dram type
    //
    // CSRs to program:
    //      DfiCAMode::DfiLp3CAMode
    //               ::DfiD4CAMode
    //               ::DfiLp4CAMode
    //               ::DfiD4AltCAMode
    //               ::DfiD5CAMode
    //
    // User input dependencies::
    //      DramType
    //
    //##############################################################
    {
        int DfiCAMode = 0;

        // DDR5
        if (i_user_input_basic.DimmType == RDIMM || i_user_input_basic.DimmType == LRDIMM)
        {
            DfiCAMode = 32;
        }
        else
        {
            DfiCAMode = 16;
        }

        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming DfiCAMode to 0x%x", TARGTID, DfiCAMode);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_DfiCAMode_ADDR), DfiCAMode));
    }

    //##############################################################
    //
    // Program CalDrvStr0 based on user input. CalDrvStrPd50 and CalDrvStrPu50
    // will be programmed to same value
    //
    // CSRs to program:
    //      CalDrvStr0::CalDrvStrPd50[5:0]
    //                  CalDrvStrPu50[11:6]
    //
    // User input dependencies::
    //      ExtCalResVal
    //
    //##############################################################
    {
        int CalDrvStr0;
        int CalDrvStrPd50;
        int CalDrvStrPu50;

        CalDrvStrPu50 = dwc_ddrphy_phyinit_mapDrvStren(i_user_input_advanced.ExtCalResVal);
        CalDrvStrPd50 = CalDrvStrPu50;

        CalDrvStr0 = (CalDrvStrPu50 << csr_CalDrvStrPu50_LSB) | (CalDrvStrPd50 << csr_CalDrvStrPd50_LSB);

        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming CalDrvStr0::CalDrvStrPd50 to 0x%x", TARGTID,
                  CalDrvStrPd50);
        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming CalDrvStr0::CalDrvStrPu50 to 0x%x", TARGTID,
                  CalDrvStrPu50);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_CalDrvStr0_ADDR), CalDrvStr0));
    }


    //##############################################################
    //
    // Program Calibration Related registers based on user input and
    // frequency.
    //
    // CSRs to program:
    //      CalUclkInfo::CalUClkTicksPer1uS
    //
    // User input dependencies::
    //      Frequency
    //
    //##############################################################
    {
        int     CalUClkTicksPer1uS[4];

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            // Number of DfiClk cycles per 1us
            CalUClkTicksPer1uS[pstate]        = calculate_clk_tick_per_1us( i_user_input_basic.Frequency[pstate] );

            if (CalUClkTicksPer1uS[pstate] < 24)
            {
                CalUClkTicksPer1uS[pstate] = 24;    // Minimum value of CalUClkTicksPer1uS = 24
            }

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming CalUclkInfo::CalUClkTicksPer1uS to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], CalUClkTicksPer1uS[pstate]);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_CalUclkInfo_ADDR),
                     CalUClkTicksPer1uS[pstate]));
        }
    }


    //##############################################################
    //
    // Program Calibration CSRs based on user input
    //
    // CSRs to program:
    //      CalRate:: CalInterval
    //             :: CalOnce
    //
    // User input dependencies::
    //      CalInterval
    //      CalOnce
    //
    //##############################################################
    {
        int CalRate;
        int CalInterval;
        int CalOnce;

        CalInterval = i_user_input_advanced.CalInterval;
        CalOnce = i_user_input_advanced.CalOnce;

        CalRate = (CalOnce << csr_CalOnce_LSB) | (CalInterval << csr_CalInterval_LSB);

        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming CalRate::CalInterval to 0x%x", TARGTID,
                  CalInterval);
        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming CalRate::CalOnce to 0x%x", TARGTID, CalOnce);

        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_CalRate_ADDR), CalRate));
    }


    //##############################################################
    //
    // Program csrVrefInGlobal to select Global VREF
    // from Master to be used in each DQ
    //
    // CSRs to be programmed:
    //
    //     VrefInGlobal::GlobalVrefInSel
    //     VrefInGlobal::GlobalVrefInDAC
    //
    // User input dependencies::
    //      DramType
    //
    //##############################################################
    {
        int VrefInGlobal;
        int GlobalVrefInSel = 0;
        int GlobalVrefInDAC = 0;

        // DDR5
        GlobalVrefInSel = 0;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            GlobalVrefInDAC = compute_global_vref_in_dac(i_user_input_dram_config.PhyVref );

            VrefInGlobal = (GlobalVrefInDAC << csr_GlobalVrefInDAC_LSB) | GlobalVrefInSel;
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d, Programming VrefInGlobal::GlobalVrefInSel to 0x%x",
                      TARGTID, pstate,
                      GlobalVrefInSel);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d, Programming VrefInGlobal::GlobalVrefInDAC to 0x%x",
                      TARGTID, pstate,
                      GlobalVrefInDAC);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d, Programming VrefInGlobal to 0x%x", TARGTID, pstate,
                      VrefInGlobal);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_VrefInGlobal_ADDR), VrefInGlobal));
        }
    }


    //##############################################################
    //
    // Program csrDqDqsRcvCntrl
    //
    // CSRs to be programmed:
    //
    //     DqDqsRcvCntrl::SelAnalogVref
    //     DqDqsRcvCntrl::GainCurrAdj
    //
    // User input dependencies::
    //      DramType
    //
    //##############################################################
    {
        int DqDqsRcvCntrl;
        int SelAnalogVref = 0x0; // Use the local VREF generator in the DBYTEs
        int ExtVrefRange_defval = 0x0;
        int DfeCtrl_defval = 0x0;
        int RxCurrAdj_dq;

        int RxEnLEDly = 0x0;  //1 delay asserting edge of RxEn by 0.5 UI, no change to deasserting edge

        if (i_user_input_advanced.IsHighVDD)
        {
            RxCurrAdj_dq  = 0x19;
        }
        else
        {
            RxCurrAdj_dq  = 0x29;
        }


        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            //dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tDBYTE | cbrd | bbrd | csr_DqDqsRcvCntrl_ADDR), DqDqsRcvCntrl);
            for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
            {
                c_addr = byte << 12;

                for (lane = 0; lane <= b_max ; lane++)
                {
                    b_addr = lane << 8;

                    DqDqsRcvCntrl = (RxCurrAdj_dq << csr_GainCurrAdj_LSB) | (RxEnLEDly << csr_RxEnLEDly_LSB) |
                                    (DfeCtrl_defval << csr_DfeCtrl_LSB) | (ExtVrefRange_defval << csr_ExtVrefRange_LSB) |
                                    (SelAnalogVref << csr_SelAnalogVref_LSB);

                    FAPI_DBG (TARGTIDFORMAT
                              " //// [phyinit_C_initPhyConfig] Pstate=%d, Programming DqDqsRcvCntrl (Byte=%d, Upper/Lower=%d) to 0x%x",
                              TARGTID,
                              pstate, byte, lane, DqDqsRcvCntrl);

                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,
                             (p_addr | tDBYTE | c_addr | b_addr | csr_DqDqsRcvCntrl_ADDR),
                             DqDqsRcvCntrl));
                }
            }
        }
    }

    //##############################################################
    //
    // CSRs to be programmed:
    //
    //     DqDqsRcvCntrl2::RxChPowerDown
    //
    //##############################################################
    {
        int RxChPowerDown;
        int FourTap = (((pubRev >= 0x0240) && (pubRev < 0x0300)) || (pubRev >= 0x0400));

        if (FourTap)
        {
            RxChPowerDown = 0;
        }
        else
        {
            RxChPowerDown = 0xe;
        }

        int DqDqsRcvCntrl2 = (RxChPowerDown << csr_RxChPowerDown_LSB);

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d, Programming DqDqsRcvCntrl2 to 0x%x", TARGTID,
                      pstate,
                      DqDqsRcvCntrl2);

            for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
            {
                c_addr = byte << 12;
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tDBYTE | c_addr | csr_DqDqsRcvCntrl2_ADDR),
                         DqDqsRcvCntrl2));
            }
        }
    }


    //##############################################################
    //
    // Program MAlertControl and ATxOdtDrvStren based on user Input
    //
    // CSRs to be programmed:
    //
    //      MAlertControl::MAlertRxEn
    //      ATxOdtDrvStren::AODTStrenP (ANIB_1 only)
    //      ATxOdtDrvStren::AODTStrenN  (ANIB_1 only)
    //
    // User input dependencies:
    //      MemAlertEn
    //      MtestPUImp
    //
    //##############################################################
    {
        int MAlertControl;
        int MALERTRxEn;
        int MALERTPuStren;
        int ATxOdtDrvStren = 0;
        int MALERTDisableVal_defval = 1;

        if (i_user_input_advanced.MemAlertEn == 1)
        {
            MALERTRxEn = 1;
            MAlertControl = (MALERTDisableVal_defval << csr_MALERTDisableVal_LSB) | (MALERTRxEn << csr_MALERTRxEn_LSB);

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming MAlertControl::MALERTRxEn to 0x%x", TARGTID,
                      MALERTRxEn);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming MAlertControl to 0x%x", TARGTID, MAlertControl);

            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_MAlertControl_ADDR), MAlertControl));

            MALERTPuStren = dwc_ddrphy_phyinit_mapDrvStren(i_user_input_advanced.MtestPUImp);

            ATxOdtDrvStren = (MALERTPuStren << csr_AODTStrenP_LSB);

            // Since MemAlert pin is BP_A5, ODT strength is enabled for ANIB_1 only
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming ATxOdtDrvStren::AODTStrenP (ANIB_1 only) to 0x%x",
                      TARGTID,
                      MALERTPuStren);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming ATxOdtDrvStren (ANIB_1 only) to 0x%x", TARGTID,
                      ATxOdtDrvStren);

            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | c1 | csr_ATxOdtDrvStren_ADDR), ATxOdtDrvStren));
        }

        // Program ATxOdtDrvStren for each ANIB that is selected as Receive for NVDIMMP
        int nv_channel;

        for (anib = 0 ; anib <= i_user_input_basic.NumAnib; anib++)
        {
            c_addr = anib << 12;

            for (nv_channel = 0; nv_channel <= 4; nv_channel++)
            {
                if (i_user_input_advanced.AnibRcvEn[nv_channel] == 1 && i_user_input_advanced.NvAnibRcvSel[nv_channel] == anib)
                {
                    FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming ATxOdtDrvStren of ANIB_%d to 0x%x", TARGTID, anib,
                              ATxOdtDrvStren);
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | c_addr | csr_ATxOdtDrvStren_ADDR),
                             ATxOdtDrvStren));
                }
            }
        }
    }




    //##############################################################
    //
    // Program TristateModeCA based on DramType and 2T Timing
    //
    // CSRs to program:
    //      TristateModeCA::DisDynAdrTri
    //      TristateModeCA::DDR2TMode
    //
    // User input dependencies::
    //      DramType

    //
    //##############################################################
    {
        int TristateModeCA[4];
        int DisDynAdrTri[4];
        int DDR2TMode[4];
        int CkDisVal_def;

        // CkDisVal depends on DramType but is 1 for DDR4 and DDR5
        CkDisVal_def = 1; // {CLK_t,CLK_c} = 2'b00;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;
            DisDynAdrTri[pstate] = i_user_input_advanced.DisDynAdrTri[pstate];
            DDR2TMode[pstate] = dwc_ddrphy_phyinit_is2Ttiming(i_user_input_dram_config);
            TristateModeCA[pstate] = (CkDisVal_def << csr_CkDisVal_LSB) | (DDR2TMode[pstate] << csr_DDR2TMode_LSB) |
                                     (DisDynAdrTri[pstate] << csr_DisDynAdrTri_LSB) ;

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TristateModeCA::DisDynAdrTri_p%d to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], pstate, DisDynAdrTri[pstate]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming TristateModeCA::DDR2TMode_p%d to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], pstate, DDR2TMode[pstate]);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_TristateModeCA_ADDR),
                     TristateModeCA[pstate]));

        }
    }


    //##############################################################
    //
    // Program DfiXlat based on PLL Bypass input
    // CSRs to program:
    //   DfiFreqXlat0
    //   DfiFreqXlat1
    //   DfiFreqXlat2
    //   DfiFreqXlat3
    //   DfiFreqXlat4
    //   DfiFreqXlat5
    //   DfiFreqXlat6
    //   DfiFreqXlat7
    //
    //##############################################################
    {
        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming DfiFreqXlat*", TARGTID);

        uint16_t loopVector;
        uint16_t dfifreqxlat_dat;
        uint16_t pllbypass_dat;
        pllbypass_dat = (i_user_input_basic.PllBypass[3] << 12) | (i_user_input_basic.PllBypass[2] << 8) |
                        (i_user_input_basic.PllBypass[1] << 4) | (i_user_input_basic.PllBypass[0]);

        for(loopVector = 0; loopVector < 8; loopVector++)
        {

            if (loopVector ==
                0)            // Retrain & Relock DfiFreq = 00,01,02,03)  Use StartVec 0 (pll_enabled) or StartVec 1 (pll_bypassed)
            {
                dfifreqxlat_dat = pllbypass_dat + 0x0000;
                //FAPI_DBG(TARGTIDFORMAT ":DEBUG: LP4 : loopVector = %d : dfifreqxlat_dat = %x.", TARGTID, loopVector, dfifreqxlat_dat);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tMASTER | (csr_DfiFreqXlat0_ADDR + loopVector)),
                         dfifreqxlat_dat));
            }
            else if (loopVector == 2)       // Retrain only DfiFreq = 08,09,0A,0B)  Use StartVec 4 (1, and maybe 2,3, used by verif)
            {
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tMASTER | (csr_DfiFreqXlat0_ADDR + loopVector)),
                         0x4444));
            }
            else if (loopVector == 3)       // phymstr type state change, StartVec 8
            {
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tMASTER | (csr_DfiFreqXlat0_ADDR + loopVector)),
                         0x8888));
            }
            // Relock only DfiFreq = 10,11,12,13   Use StartVec 5 (pll_enabled) or StartVec 6 (pll_bypassed)
            else if (loopVector == 4)
            {
                dfifreqxlat_dat = pllbypass_dat + 0x5555;
                //FAPI_DBG(TARGTIDFORMAT ":DEBUG: LP4 : loopVector = %d : dfifreqxlat_dat = %x.", TARGTID, loopVector, dfifreqxlat_dat);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tMASTER | (csr_DfiFreqXlat0_ADDR + loopVector)),
                         dfifreqxlat_dat));
            }
            else if (loopVector == 7)       // LP3-entry DfiFreq = 1F
            {
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tMASTER | (csr_DfiFreqXlat0_ADDR + loopVector)),
                         0xF000));
            }
            else                            // everything else
            {
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tMASTER | (csr_DfiFreqXlat0_ADDR + loopVector)),
                         0x0000));
            }


        }
    }

    //##############################################################
    //
    // Program Seq0BDLY0/1/2/3 based on Frequency
    //
    // CSRs to program:
    //   Seq0BDLY0_px
    //   Seq0BDLY1_px
    //   Seq0BDLY2_px
    //   Seq0BDLY3_px
    //
    // User input dependencies:
    //   Frequency
    //
    //##############################################################
    {
        // Need delays for 0.5us, 1us, 10us, and 25us.
        uint16_t psCount[4][4];

        // Calculate the counts to obtain the correct delay for each frequency
        // Need to divide by 4 since the delay value are specified in units of
        // 4 clocks.
        int memfrq, dllLock;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;
            memfrq = i_user_input_basic.Frequency[pstate];

            psCount[pstate][0] = compute_ps_count(  500, memfrq);
            psCount[pstate][1] = compute_ps_count( 1000, memfrq);
            psCount[pstate][2] = compute_ps_count( 3500, memfrq);

            if      (memfrq > 533)
            {
                dllLock = 176;
            }
            else if (memfrq <= 533 && memfrq > 400)
            {
                dllLock = 132;
            }
            else
            {
                dllLock = 64;
            }

            psCount[pstate][3] = (int)(dllLock / 4);

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming Seq0BDLY0 to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], psCount[pstate][0]);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | c0 | tMASTER | csr_Seq0BDLY0_ADDR),
                     psCount[pstate][0]));

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming Seq0BDLY1 to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], psCount[pstate][1]);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | c0 | tMASTER | csr_Seq0BDLY1_ADDR),
                     psCount[pstate][1]));

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming Seq0BDLY2 to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], psCount[pstate][2]);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | c0 | tMASTER | csr_Seq0BDLY2_ADDR),
                     psCount[pstate][2]));

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming Seq0BDLY3 to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], psCount[pstate][3]);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | c0 | tMASTER | csr_Seq0BDLY3_ADDR),
                     psCount[pstate][3]));

        }
    }

    //##############################################################
    //
    // Program Phy Misc CSRs. See program_pwrdnCSR(). Below is
    //
    // DDR5 DBYTE Mapping:
    //     channel-0 : 0,1,2,3,8(ecc)
    //     channel-1 : 4,5,6,7,9(ecc)
    //
    // CSRs to program:
    //   DbyteMiscMode::
    //
    // User input dependencies:
    //   Frequency
    //
    //##############################################################
    {
        uint16_t regData;
        regData = 0x1 << csr_DByteDisable_LSB;
        unsigned int regData1;
        regData1 = (0x1ff << csr_PowerDownRcvr_LSB | 0x1 << csr_PowerDownRcvrDqs_LSB | 0x1 << csr_RxPadStandbyEn_LSB) ;
        unsigned int PowerDownDBI; // turn off Rx of DBI lane and enabled standby power saving on rxdq and rxdqs
        PowerDownDBI = (0x100 << csr_PowerDownRcvr_LSB | csr_RxPadStandbyEn_MASK) ;
        fapi2::ReturnCode l_rc;

        // Implements Section 1.3 of Pub Databook
        for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++) // for each dbyte
        {
            c_addr = byte << 12;

            if (dwc_ddrphy_phyinit_IsDbyteDisabled(i_target, i_user_input_basic, i_user_input_dram_config, byte, l_rc))
            {
                FAPI_TRY(l_rc);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Disabling DBYTE %d", TARGTID, byte);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c_addr | tDBYTE | csr_DbyteMiscMode_ADDR), regData));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c_addr | tDBYTE | csr_DqDqsRcvCntrl1_ADDR), regData1));
            }
            else
            {
                FAPI_TRY(l_rc);

                // DBI is not available for DDR5
                if ( (i_user_input_basic.DramDataWidth[0] != 4 ) &&
                     (i_user_input_basic.DramDataWidth[1] != 4 ) &&
                     (i_user_input_basic.DramDataWidth[2] != 4 ) &&
                     (i_user_input_basic.DramDataWidth[3] != 4 ) )
                {

                    FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Disabling DBYTE %d Lane 8 (DBI) Receiver to save power.",
                              TARGTID, byte);
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c_addr | tDBYTE | csr_DqDqsRcvCntrl1_ADDR), PowerDownDBI));
                }
                else
                {
                    FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Enabling DBYTE %d RxPadSandby to save power.", TARGTID, byte);
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c_addr | tDBYTE | csr_DqDqsRcvCntrl1_ADDR),
                             csr_RxPadStandbyEn_MASK));
                }
            } // not byte disabled
        } // for each dbyte
    }


    //##############################################################
    //
    // Program MasterX4Config::X4TG based on DramDataWidth
    //
    // CSRs to program:
    //   MasterX4Config::X4TG[3:0]
    //
    // Note: PHY does not support mixed dram device data width
    //
    //##############################################################
    {
        int X4TG = 0x0;
        int MasterX4Config;

        for (tg = 0; tg < 4; tg ++)
        {
            X4TG = ((i_user_input_basic.DramDataWidth[tg] == 4)) ? (((0x1 << tg) & 0xf) | X4TG) : (0x0 | X4TG);
        }

        MasterX4Config = X4TG << csr_X4TG_LSB;

        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming MasterX4Config::X4TG to 0x%x", TARGTID,
                  MasterX4Config);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_MasterX4Config_ADDR), MasterX4Config));
    }


    //##############################################################
    //
    // Program :
    //     DfiDataEnLatency::WLm13/WLm9
    //     DfiDataEnLatency::RLm9
    //     Based on pUserInputBasic Frequency
    //##############################################################
    {
        if ((pubRev >= 0x340 && pubRev < 0x0400) || (pubRev >= 0x0410))
        {
            WLm13 = 1;
            RLm13 = 1;
            FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming DfiDataEnLatency::WLm13 and RLm13", TARGTID);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_DfiDataEnLatency_ADDR),
                     csr_WLm13_MASK | csr_RLm13_MASK ));
        }
        else  if ((pubRev <= 0x0242) || (pubRev >= 0x0300 && pubRev <= 0x0320))
        {
            WLm13 = 0;
            RLm13 = 0;
            FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming DfiDataEnLatency::WLm9 and RLm9", TARGTID);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_DfiDataEnLatency_ADDR),
                     csr_WLm9_MASK | csr_RLm9_MASK ));
        }
        else
        {
            WLm13 = 1;
            RLm13 = 0;
            FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming DfiDataEnLatency::WLm13 and RLm9", TARGTID);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_DfiDataEnLatency_ADDR),
                     csr_WLm13_MASK | csr_RLm9_MASK ));
        }
    }

    //##############################################################
    //
    // Program D5ACSM registers
    //
    // CSRs to program:
    //
    //
    // User input dependencies::
    //      MR0_A0
    //
    //##############################################################
    {
        unsigned int AcsmCtrl5;
        unsigned int AcsmCtrl6;
        unsigned int mr_cl, cl, cwl;
        int RxEnPulse, RxEnDelay, RxEnWidth;
        int RxValPulse, RxValDelay, RxValWidth;
        int RdcsPulse, RdcsDelay, RdcsWidth;
        int TxEnPulse, TxEnDelay, TxEnWidth;
        int WrcsPulse, WrcsDelay, WrcsWidth;
        int SnoopPulse, SnoopDelay, SnoopWidth;
        int SnoopVal, HwtSnoopEn1, HwtSnoopEn2, HwtSnoopEn3;
        int D5ReadCRCEnable = i_user_input_dram_config.MR50_A0 & 0x1; // MR50:OP[0:0] (Read CRC Enable)

        // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
        // UDIMM timing
        int D52Nmode;

        // RDIMM timing
        //int D5RdimmSDRmode;


        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;
            mr_cl = ( i_user_input_dram_config.MR0_A0 & 0x7c) >> 2;

            // TODO:ZEN:MST-1598 Fix ODY PHY init to allow for 80 bit wide UDIMM bus
            // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
            // Note: UDIMM
            D52Nmode = dwc_ddrphy_phyinit_is2Ttiming(i_user_input_dram_config);

            // Note: RDIMM
# if 0
            D5RdimmSDRmode = (i_user_input_dram_config.RCW00_ChA_D0 & 0x1) ? 0 : 1; // RCW00_ChA_D0[0]
            // Note: this line I think can be deleted as it is set on 1106
            //D5ReadCRCEnable = i_user_input_dram_config.MR50_A0 & 0x1; // MR50:OP[0:0] (Read CRC Enable)
#endif

            cl = 0;
            cwl = 0;

            if(mr_cl < 23)
            {
                cl = 2 * mr_cl + 22;
                cwl = cl - 2;
            }

            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, rd_Crc = %0d cwl= %0d , cl = %0d mr_cl =%0d MR0_A0 = 0x%x ",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], D5ReadCRCEnable, cwl, cl, mr_cl,
                      i_user_input_dram_config.MR0_A0 );

            //AcsmCtrl5 = dwc_ddrphy_phyinit_userCustom_io_read16(csr_AcsmCtrl5_ADDR | tACSM | c0);
            //AcsmCtrl6 = dwc_ddrphy_phyinit_userCustom_io_read16(csr_AcsmCtrl6_ADDR | tACSM | c0);
            //AcsmCtrl5 = (AcsmCtrl5 & ~csr_AcsmRCasLat_MASK) | ((cl-9)  << csr_AcsmRCasLat_LSB);
            //AcsmCtrl6 = (AcsmCtrl6 & ~csr_AcsmWCasLat_MASK) | ((cwl-9) << csr_AcsmWCasLat_LSB);
            if (pstate == 0)
            {
                AcsmCtrl5 = ((cl - 8)  << csr_AcsmRCasLat_LSB);
                AcsmCtrl6 = ((cwl - 8) << csr_AcsmWCasLat_LSB);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, csr_AcsmCtrl5_ADDR | tACSM | c0, AcsmCtrl5));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, csr_AcsmCtrl6_ADDR | tACSM | c0, AcsmCtrl6));
            }

            int ReadCRCDly = 0;

            if (D5ReadCRCEnable && (i_user_input_basic.Frequency[pstate] > 3000 && i_user_input_basic.Frequency[pstate] <= 3200))
            {
                ReadCRCDly = 2;
            }

            // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
            // UDIMM timings
            {
                RxEnDelay   = cl - (8 + (4 * RLm13)) + D52Nmode * 2 + ReadCRCDly;
                RxValDelay  = cl - (8 + (4 * RLm13)) + D52Nmode * 2 + ReadCRCDly;
                RdcsDelay   = cl - (8 + (4 * RLm13)) + D52Nmode * 2 + ReadCRCDly;
                SnoopDelay  = cl - (8 + (4 * RLm13)) + D52Nmode * 2 + ReadCRCDly;
                TxEnDelay   = cwl - (8 + (4 * WLm13)) + 2 * D52Nmode;
                WrcsDelay   = cwl - (8 + (4 * WLm13)) + 2 * D52Nmode;
            }

            // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
            // RDIMM timings
#if 0
            RxEnDelay   = cl - (8 + (4 * RLm13) - (2 * D5RdimmSDRmode)) + ReadCRCDly;
            RxValDelay  = cl - (8 + (4 * RLm13) - (2 * D5RdimmSDRmode)) + ReadCRCDly;
            RdcsDelay   = cl - (8 + (4 * RLm13) - (2 * D5RdimmSDRmode)) + ReadCRCDly;
            SnoopDelay  = cl - (8 + (4 * RLm13) - (2 * D5RdimmSDRmode)) + ReadCRCDly;
            TxEnDelay   = cwl - (8 + (4 * WLm13) - (2 * D5RdimmSDRmode));
            WrcsDelay   = cwl - (8 + (4 * WLm13) - (2 * D5RdimmSDRmode));
#endif

            RxEnWidth   = 8 + D5ReadCRCEnable;
            RxValWidth  = 8 + D5ReadCRCEnable;
            RdcsWidth   = 8 + D5ReadCRCEnable;
            SnoopWidth  = 8 + D5ReadCRCEnable;
            TxEnWidth   = 8;
            WrcsWidth   = 8;
            HwtSnoopEn1 = 1;
            HwtSnoopEn2 = 2;
            HwtSnoopEn3 = 3;
            RxEnPulse   = (RxEnWidth << csr_D5ACSM0RxEnWidth_LSB) | (RxEnDelay << csr_D5ACSM0RxEnDelay_LSB);
            RxValPulse  = (RxValWidth << csr_D5ACSM0RxValWidth_LSB) | (RxValDelay << csr_D5ACSM0RxValDelay_LSB);
            RdcsPulse   = (RdcsWidth << csr_D5ACSM0RdcsWidth_LSB) | (RdcsDelay << csr_D5ACSM0RdcsDelay_LSB);
            TxEnPulse   = (TxEnWidth << csr_D5ACSM0TxEnWidth_LSB) | (TxEnDelay << csr_D5ACSM0TxEnDelay_LSB);
            WrcsPulse   = (WrcsWidth << csr_D5ACSM0WrcsWidth_LSB) | (WrcsDelay << csr_D5ACSM0WrcsDelay_LSB);
            SnoopPulse  = (SnoopWidth << csr_D5ACSM0SnoopWidth_LSB) | (SnoopDelay << csr_D5ACSM0SnoopDelay_LSB);
            SnoopVal    = (HwtSnoopEn3 << csr_D5ACSM0HwtSnoopEn3_LSB) | (HwtSnoopEn2 << csr_D5ACSM0HwtSnoopEn2_LSB) |
                          (HwtSnoopEn1 << csr_D5ACSM0HwtSnoopEn1_LSB);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM0RxEnPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], RxEnPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM0RxValPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], RxValPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM0RdcsPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], RdcsPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM0TxEnPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], TxEnPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM0WrcsPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], WrcsPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM0SnoopPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], SnoopPulse);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM0RxEnPulse_ADDR),
                     RxEnPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM0RxValPulse_ADDR),
                     RxValPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM0RdcsPulse_ADDR),
                     RdcsPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM0TxEnPulse_ADDR),
                     TxEnPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM0WrcsPulse_ADDR),
                     WrcsPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM0SnoopPulse_ADDR),
                     SnoopPulse));

            if (pstate == 0)
            {
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM0SnoopVal to %d",
                          TARGTID, pstate,
                          i_user_input_basic.Frequency[pstate], SnoopVal);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM0SnoopVal_ADDR),
                         SnoopVal));
            }

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM1RxEnPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], RxEnPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM1RxValPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], RxValPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM1RdcsPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], RdcsPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM1TxEnPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], TxEnPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM1WrcsPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], WrcsPulse);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM1SnoopPulse to %d",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], SnoopPulse);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM1RxEnPulse_ADDR),
                     RxEnPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM1RxValPulse_ADDR),
                     RxValPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM1RdcsPulse_ADDR),
                     RdcsPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM1TxEnPulse_ADDR),
                     TxEnPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM1WrcsPulse_ADDR),
                     WrcsPulse));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM1SnoopPulse_ADDR),
                     SnoopPulse));

            if (pstate == 0)
            {
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d,  Memclk=%dMHz, Programming D5ACSM1SnoopVal to %d",
                          TARGTID, pstate,
                          i_user_input_basic.Frequency[pstate], SnoopVal);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | c0 | csr_D5ACSM1SnoopVal_ADDR),
                         SnoopVal));
            }
        }
    }


    //##############################################################
    // Program Seq0BGPR7 :: storing the value of csrAlertRecovery
    // based on userInputAdvanced.AlertRecoveryEnable & userInputAdvanced.RstRxTrkState
    //##############################################################
    {
        if (pubRev >= 0x330)
        {
            int Seq0BGPR7;
            Seq0BGPR7 = (i_user_input_advanced.AlertRecoveryEnable << csr_AlertRecoveryEnable_LSB) |
                        (i_user_input_advanced.RstRxTrkState << csr_RstRxTrkState_LSB);

            for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
            {
                p_addr = pstate << 20;
                FAPI_DBG (TARGTIDFORMAT
                          " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming GPR7(csrAlertRecovery) to 0x%x",
                          TARGTID,
                          pstate, i_user_input_basic.Frequency[pstate], Seq0BGPR7);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tINITENG | csr_Seq0BGPR7_ADDR), Seq0BGPR7));
            }
        }
    }


    //##############################################################
    //
    // Program DMIPinPresent based on DramType and Read-DBI enable
    //
    // CSRs to program:
    //      DMIPinPresent::RdDbiEnabled
    //
    // User input dependencies::
    //      UserInputBasic.ReadDBIEnable
    //
    //##############################################################


    //##############################################################
    //
    // Program AnibRcvControl0-3 based on DramType and DimmType
    //
    // CSRs to program:
    //     AnibRcvControl0-3
    //


    //##############################################################
    {
        int nv_num;

        if (i_user_input_basic.DimmType == NVDIMMP)
        {
            for (nv_num = 0; nv_num < 4; nv_num++)
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, tMASTER | (csr_AnibRcvControl0_ADDR + nv_num),
                         (
                             ( ( (i_user_input_advanced.NvAnibRcvSel[nv_num] << 2) |
                                 i_user_input_advanced.AnibRcvLaneSel[nv_num] ) << csr_AnibRcvSel0_LSB ) | //AnibRcvSel
                             ( i_user_input_advanced.AnibRcvEn[nv_num] << csr_AnibRcvEn0_LSB ) | //AnibRcvEn
                             (0 << csr_AnibRcvSErrEn0_LSB) //AnibRcvSErrEn
                         )));
        }
    }

    //##############################################################
    //
    // Program TimingModeCntrl::Dly64Prec to use 1/64UI
    // precision in delay lines.
    //
    // DDR5 - always uses 1/64UI precision.
    // DDR4 - 1/32 UI for 1D or 1/64 UI for 2D
    //
    //##############################################################
    {
        int Dly64Prec;
        Dly64Prec = 0x1;

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming TimingModeCntrl::Dly64Prec to 0x%x", TARGTID,
                  Dly64Prec);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_TimingModeCntrl_ADDR),
                 (Dly64Prec << csr_Dly64Prec_LSB) ));
    }

    //##############################################################
    //
    // Set VshCntrlUpdate to 1 - this is used as strobe by the
    // hard macros to register VshDAC values set earlier in this
    // function.
    //
    //##############################################################
    {
        VshCtrlUpdate = 0x1;

        VREGCtrl3 = (VshCtrlUpdate << csr_VshCtrlUpdate_LSB);

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for MASTER",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_VREGCtrl3_ADDR), VREGCtrl3));

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for all DBYTEs",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);

        for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
        {
            c_addr = byte << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tDBYTE | c_addr | csr_VREGCtrl3_ADDR), VREGCtrl3));
        }

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for all ANIBs",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);

        for (anib = 0; anib < i_user_input_basic.NumAnib; anib++)
        {
            c_addr = anib << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tANIB | c_addr | csr_VREGCtrl3_ADDR), VREGCtrl3));
        }
    }

    //##############################################################
    //
    // Program AcClkDLLControl
    //
    //##############################################################
    {
        int AcClkDLLControl = 0x1080;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming AcClkDLLControl to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], AcClkDLLControl);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_AcClkDLLControl_ADDR),
                     AcClkDLLControl));
        }
    }


    //##############################################################
    //
    // Program ArcPmuEccCtl based on userInputAdvanced.DisablePmuEcc
    //
    //##############################################################
    {
        int ArcPmuEccCtl;
        ArcPmuEccCtl = i_user_input_advanced.DisablePmuEcc;

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming ArcPmuEccCtl to 0x%x", TARGTID, ArcPmuEccCtl);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tDRTUB | csr_ArcPmuEccCtl_ADDR), ArcPmuEccCtl));
    }

    //##############################################################
    //
    // Set VshMissionMode to 1 to prepare voltage regulator for mission mode
    //
    //##############################################################
    {
        int VshPowerModes_master = 0x3;
        int VshPowerModes_dbyte = 0;
        int VshPowerModes_anib = 0;
        int VshAnalog = 0x20;
        int VREGCtrl2_master;
        int VREGCtrl2_dbyte;
        int VREGCtrl2_anib;

        VREGCtrl2_master = csr_VshMissionMode_MASK | (VshAnalog << csr_VshAnalog_LSB) | (VshPowerModes_master <<
                           csr_VshPowerModes_LSB);
        VREGCtrl2_dbyte  = csr_VshMissionMode_MASK | (VshAnalog << csr_VshAnalog_LSB) | (VshPowerModes_dbyte <<
                           csr_VshPowerModes_LSB);
        VREGCtrl2_anib   = csr_VshMissionMode_MASK | (VshAnalog << csr_VshAnalog_LSB) | (VshPowerModes_anib <<
                           csr_VshPowerModes_LSB);

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming VREGCtrl2 to 0x%x for MASTER", TARGTID,
                  VREGCtrl2_master);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_VREGCtrl2_ADDR), VREGCtrl2_master));

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming VREGCtrl2 to 0x%x for all DBYTEs", TARGTID,
                  VREGCtrl2_dbyte);

        for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
        {
            c_addr = byte << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tDBYTE | c_addr | csr_VREGCtrl2_ADDR), VREGCtrl2_dbyte));
        }

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming VREGCtrl2 to 0x%x for all ANIBs", TARGTID,
                  VREGCtrl2_anib);

        for (anib = 0; anib < i_user_input_basic.NumAnib; anib++)
        {
            c_addr = anib << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tANIB | c_addr | csr_VREGCtrl2_ADDR), VREGCtrl2_anib));
        }
    }


    //##############################################################
    //
    // Set VshCtrlUpdate to 0 - de-asserting the strobe
    //
    //##############################################################
    {
        VshCtrlUpdate = 0x0;

        VREGCtrl3 = (VshCtrlUpdate << csr_VshCtrlUpdate_LSB);

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for MASTER",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_VREGCtrl3_ADDR), VREGCtrl3));

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for all DBYTEs",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);

        for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
        {
            c_addr = byte << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tDBYTE | c_addr | csr_VREGCtrl3_ADDR), VREGCtrl3));
        }

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming VREGCtrl3::VshCtrlUpdate to 0x%x for all ANIBs",
                  TARGTID, 0, i_user_input_basic.Frequency[0], VshCtrlUpdate);

        for (anib = 0; anib < i_user_input_basic.NumAnib; anib++)
        {
            c_addr = anib << 12;
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tANIB | c_addr | csr_VREGCtrl3_ADDR), VREGCtrl3));
        }
    }

    //##############################################################
    //
    // Program VREFDACn
    //
    //##############################################################
    {
        int VrefDAC0 = 0x3f;
        int VrefDAC1 = 0x3f;

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming VrefDAC0 to 0x%x for all DBYTEs and lanes", TARGTID,
                  VrefDAC0);
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming VrefDAC1 to 0x%x for all DBYTEs and lanes", TARGTID,
                  VrefDAC1);

        int VrefDAC2 = 0x3f;
        int VrefDAC3 = 0x3f;

        if (!f5200)
        {
            FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming VrefDAC2 to 0x%x for all DBYTEs and lanes", TARGTID,
                      VrefDAC2);
            FAPI_DBG (TARGTIDFORMAT " // [phyinit_C_initPhyConfig] Programming VrefDAC3 to 0x%x for all DBYTEs and lanes", TARGTID,
                      VrefDAC3);
        }

        for (byte = 0; byte < i_user_input_basic.NumDbyte; byte++)
        {
            c_addr = byte << 12;

            for (lane = 0; lane <= r_max ; lane++)
            {
                r_addr = lane << 8;

                for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
                {
                    p_addr = pstate << 20;
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tDBYTE | c_addr | r_addr | csr_VrefDAC0_ADDR),
                             VrefDAC0));

                    if (f5200)
                    {
                        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (p_addr | tDBYTE | c_addr | r_addr | csr_VrefDAC1_ADDR),
                                 VrefDAC1));
                    }
                }

                if (!f5200)
                {
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tDBYTE | c_addr | r_addr | csr_VrefDAC1_ADDR), VrefDAC1));
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tDBYTE | c_addr | r_addr | csr_VrefDAC2_ADDR), VrefDAC2));
                    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tDBYTE | c_addr | r_addr | csr_VrefDAC3_ADDR), VrefDAC3));
                }
            }
        }


        /**
        * - Program DfiFreqRatio:
        *   - Dependencies:
        *     - user_input_basic.DfiFreqRatio
        */
        int DfiFreqRatio;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            DfiFreqRatio = i_user_input_basic.DfiFreqRatio[pstate];

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Pstate=%d, Memclk=%dMHz, Programming DfiFreqRatio_p%d to 0x%x",
                      TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate], pstate, DfiFreqRatio);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_DfiFreqRatio_ADDR), DfiFreqRatio));

        }
    }

    //##############################################################
    //
    // Program PptCtlStatic::DOCByteSelTg0/1/2/3 for PPT
    // Program PptCtlStatic::NoX4onUpperNibbleTg0/1/2/3 based on DraType,DramDataWidth and DimmType
    //
    // Note: PHY supports mixed dram device data width combination of 16 & 8
    //##############################################################
    {
        int PptCtlStatic;
        unsigned int DOCByteSelTg[4];
        unsigned int NoX4onUpperNibbleTg[4];

        for (byte = 0; byte < i_user_input_basic.NumDbyte ; byte++) // Each Dbyte could have a different configuration.
        {
            c_addr = byte * c1;

            for (tg = 0; tg < 4; tg ++)
            {
                int dbyteSwapped = (i_user_input_basic.DramDataWidth[tg] == 16) && (byte < 8) &&
                                   (((i_user_input_advanced.DramByteSwap[tg] >> (byte / 2)) & 0x1) != 0);

                if (dbyteSwapped)
                {
                    DOCByteSelTg[tg] = (i_user_input_dram_config.X16Present & ((0x1 << tg) & 0xf)) ? 1 : 0;
                }
                else // X16 odd DBYTES
                {
                    DOCByteSelTg[tg] = 0;
                }

                // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
                // UDIMM
                // ECC byte in X4 and X8
                if ((i_user_input_basic.DramDataWidth[tg] == 4 || i_user_input_basic.DramDataWidth[tg] == 8) && (byte > 7 || (byte == 4
                        && i_user_input_basic.NumDbyte == 5)))
                {
                    NoX4onUpperNibbleTg[tg] = 0x1;
                }
                else
                {
                    NoX4onUpperNibbleTg[tg] = 0x0;
                }

                // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
                // RDIMM
#if 0
                NoX4onUpperNibbleTg[tg] = 0x0;
#endif
            }

            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming PptCtlStatic::DOCByteSelTg0 (dbyte=%d) to 0x%x",
                      TARGTID, byte,
                      DOCByteSelTg[0]);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming PptCtlStatic::DOCByteSelTg1 (dbyte=%d) to 0x%x",
                      TARGTID, byte,
                      DOCByteSelTg[1]);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming PptCtlStatic::DOCByteSelTg2 (dbyte=%d) to 0x%x",
                      TARGTID, byte,
                      DOCByteSelTg[2]);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming PptCtlStatic::DOCByteSelTg3 (dbyte=%d) to 0x%x",
                      TARGTID, byte,
                      DOCByteSelTg[3]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Programming PptCtlStatic::NoX4onUpperNibbleTg0 (dbyte=%d) to 0x%x",
                      TARGTID, byte,
                      NoX4onUpperNibbleTg[0]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Programming PptCtlStatic::NoX4onUpperNibbleTg1 (dbyte=%d) to 0x%x",
                      TARGTID, byte,
                      NoX4onUpperNibbleTg[1]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Programming PptCtlStatic::NoX4onUpperNibbleTg2 (dbyte=%d) to 0x%x",
                      TARGTID, byte,
                      NoX4onUpperNibbleTg[2]);
            FAPI_DBG (TARGTIDFORMAT
                      " //// [phyinit_C_initPhyConfig] Programming PptCtlStatic::NoX4onUpperNibbleTg3 (dbyte=%d) to 0x%x",
                      TARGTID, byte,
                      NoX4onUpperNibbleTg[3]);

            PptCtlStatic = (DOCByteSelTg[0] << csr_DOCByteSelTg0_LSB) |
                           (DOCByteSelTg[1] << csr_DOCByteSelTg1_LSB) |
                           (DOCByteSelTg[2] << csr_DOCByteSelTg2_LSB) |
                           (DOCByteSelTg[3] << csr_DOCByteSelTg3_LSB) |
                           (NoX4onUpperNibbleTg[0] << csr_NoX4onUpperNibbleTg0_LSB) |
                           (NoX4onUpperNibbleTg[1] << csr_NoX4onUpperNibbleTg1_LSB) |
                           (NoX4onUpperNibbleTg[2] << csr_NoX4onUpperNibbleTg2_LSB) |
                           (NoX4onUpperNibbleTg[3] << csr_NoX4onUpperNibbleTg3_LSB) ;

            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c_addr | tDBYTE | csr_PptCtlStatic_ADDR), PptCtlStatic));
        }
    }


    //##############################################################
    // De-assert ForcePubDxClkEnLow to un-gate part of the PUB
    //##############################################################
    {
        FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming ForceClkGaterEnables::ForcePubDxClkEnLow to 0x0",
                  TARGTID);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_ForceClkGaterEnables_ADDR), 0x0 ));
    }


    //##############################################################
    //
    // Program csr_AForceTriCont_ADDR to disabled unused ANIBs
    // bumps to reduce power consumption
    //
    //##############################################################
    {
        // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
        // UDIMM
        {
            if(i_user_input_basic.NumAnib == 6)
            {
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=0) to 0xc", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=4) to 0x8", TARGTID);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x0000 | csr_AForceTriCont_ADDR), 0xc));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x4000 | csr_AForceTriCont_ADDR), 0x8));
            }
            else if(i_user_input_basic.NumAnib == 10)
            {
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=0) to 0xc", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=4) to 0x8", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=6) to 0xf", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=7) to 0xf", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=8) to 0xf", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=9) to 0xf", TARGTID);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x0000 | csr_AForceTriCont_ADDR), 0xc));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x4000 | csr_AForceTriCont_ADDR), 0x8));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x6000 | csr_AForceTriCont_ADDR), 0xf));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x7000 | csr_AForceTriCont_ADDR), 0xf));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x8000 | csr_AForceTriCont_ADDR), 0xf));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x9000 | csr_AForceTriCont_ADDR), 0xf));
            }
            else if(i_user_input_basic.NumAnib == 12)
            {
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=0) to 0xc", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=3) to 0x8", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=8) to 0x1", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=10) to 0x4", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=11) to 0xc", TARGTID);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x0000 | csr_AForceTriCont_ADDR), 0xc));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x3000 | csr_AForceTriCont_ADDR), 0x8));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x8000 | csr_AForceTriCont_ADDR), 0x1));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0xa000 | csr_AForceTriCont_ADDR), 0x4));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0xb000 | csr_AForceTriCont_ADDR), 0xc));
            }
            else if(i_user_input_basic.NumAnib == 14)
            {
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=3) to 0x8", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=10) to 0x1", TARGTID);
                FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=12) to 0x4", TARGTID);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x3000 | csr_AForceTriCont_ADDR), 0x8));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0xa000 | csr_AForceTriCont_ADDR), 0x1));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0xc000 | csr_AForceTriCont_ADDR), 0x4));
            }
        }

        // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
        // RDIMM
#if 0

        if(i_user_input_basic.NumAnib == 12)
        {
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=1) to 0x8", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=2) to 0xa", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=3) to 0xa", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=4) to 0xa", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=5) to 0xc", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=6) to 0xc", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=7) to 0xa", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=8) to 0xa", TARGTID);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x1000 | csr_AForceTriCont_ADDR), 0x8));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x2000 | csr_AForceTriCont_ADDR), 0xa));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x3000 | csr_AForceTriCont_ADDR), 0xa));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x4000 | csr_AForceTriCont_ADDR), 0xa));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x5000 | csr_AForceTriCont_ADDR), 0xc));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x6000 | csr_AForceTriCont_ADDR), 0xc));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x7000 | csr_AForceTriCont_ADDR), 0xa));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x8000 | csr_AForceTriCont_ADDR), 0xa));
        }
        else if(i_user_input_basic.NumAnib == 14)
        {
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=1) to 0x8", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=2) to 0xa", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=3) to 0xa", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=4) to 0xa", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=5) to 0xc", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=6) to 0xc", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=7) to 0xf", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=8) to 0xf", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=9) to 0xa", TARGTID);
            FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] Programming AForceTriCont (anib=10) to 0xa", TARGTID);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x1000 | csr_AForceTriCont_ADDR), 0x8));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x2000 | csr_AForceTriCont_ADDR), 0xa));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x3000 | csr_AForceTriCont_ADDR), 0xa));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x4000 | csr_AForceTriCont_ADDR), 0xa));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x5000 | csr_AForceTriCont_ADDR), 0xc));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x6000 | csr_AForceTriCont_ADDR), 0xc));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x7000 | csr_AForceTriCont_ADDR), 0xf));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x8000 | csr_AForceTriCont_ADDR), 0xf));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0x9000 | csr_AForceTriCont_ADDR), 0xa));
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tANIB | 0xa000 | csr_AForceTriCont_ADDR), 0xa));
        }

#endif
    }

    /*     //##############################################################
         // Assert PhyUpdAckDelay0/1 unconditionally
         //##############################################################
        FAPI_DBG (TARGTIDFORMAT " Programming DfiHandshakeDelays0::PhyUpdAckDelay0 to 0x1", TARGTID);
        dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_DfiHandshakeDelays0_ADDR), 0x1 );
        FAPI_DBG (TARGTIDFORMAT " Programming DfiHandshakeDelays1::PhyUpdAckDelay1 to 0x1", TARGTID);
        dwc_ddrphy_phyinit_userCustom_io_write16(i_target,  (tMASTER | csr_DfiHandshakeDelays1_ADDR), 0x1 );


    //##############################################################
    //############################################################## */
// removed it as a part of DDR45 STD project, delay 0x1 is no more required
    FAPI_DBG (TARGTIDFORMAT " //// [phyinit_C_initPhyConfig] End of dwc_ddrphy_phyinit_C_initPhyConfig()", TARGTID);

fapi_try_exit:
    return fapi2::current_err;

}
// End of dwc_ddrphy_phyinit_C_initPhyConfig()
//#################################################################################################################
//#################################################################################################################

///
/// @brief Initializes all of the PHY init structures
/// @param[in] i_target - the memory port on which to operate
/// @param[in,out] io_user_input_basic - Synopsys basic user input structure
/// @param[in,out] io_user_input_advanced - Synopsys advanced user input structure
/// @param[in,out] io_user_input_dram_config - DRAM configuration inputs needed for PHY init (MRS/RCW)
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Currently, hardcoding these structures for simulation purposes
/// TODO:ZEN:MST-1591 Convert PY init structures to be initialized from attributes
///
fapi2::ReturnCode init_phy_structs( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                    user_input_basic_t& io_user_input_basic,
                                    user_input_advanced_t& io_user_input_advanced,
                                    user_input_dram_config_t& io_user_input_dram_config)
{

    // Basic init structure
    {
        // DDR5 DRAM generation
        io_user_input_basic.DramType                 = DDR5;

        // Do not override ARdPtrInitVal
        io_user_input_basic.ARdPtrInitValOvr         = 0;
        io_user_input_basic.ARdPtrInitVal[0]         = 3;
        io_user_input_basic.ARdPtrInitVal[1]         = 3;
        io_user_input_basic.ARdPtrInitVal[2]         = 3;
        io_user_input_basic.ARdPtrInitVal[3]         = 3;

        // Using default of 0
        io_user_input_basic.DisPtrInitClrTxTracking[0]  = 0x0;
        io_user_input_basic.DisPtrInitClrTxTracking[1]  = 0x0;
        io_user_input_basic.DisPtrInitClrTxTracking[2]  = 0x0;
        io_user_input_basic.DisPtrInitClrTxTracking[3]  = 0x0;

        // Using a UDIMM
        io_user_input_basic.DimmType                 = UDIMM;

        // 80 bit interface -> 8 bits per DBYTE -> 10 DBYTES
        io_user_input_basic.NumDbyte                 = 0x000a;

        // 5 DBYTE's per channel (DIMM half)
        io_user_input_basic.NumActiveDbyteDfi0       = 0x0005;
        io_user_input_basic.NumActiveDbyteDfi1       = 0x0005;
        // 14 AC4X
        io_user_input_basic.NumAnib                  = 0x000e;

        // 1 rank per channel
        io_user_input_basic.NumRank_dfi0             = 0x0001;
        io_user_input_basic.NumRank_dfi1             = 0x0001;

        // Only 1 pstate
        io_user_input_basic.NumPStates               = 0x0001;

        // Only 4800 memory rate for frequency at our pstate
        io_user_input_basic.Frequency[3]             = 800;
        io_user_input_basic.Frequency[2]             = 933;
        io_user_input_basic.Frequency[1]             = 1067;
        io_user_input_basic.Frequency[0]             = 2400;   // 4800Mbps
        io_user_input_basic.PllBypass[0]             = 0x0000;
        io_user_input_basic.PllBypass[1]             = 0x0000;
        io_user_input_basic.PllBypass[2]             = 0x0000;
        io_user_input_basic.PllBypass[3]             = 0x0000;

        // Use the default
        io_user_input_basic.DfiFreqRatio[0]          = 0x0001;
        io_user_input_basic.DfiFreqRatio[1]          = 0x0001;
        io_user_input_basic.DfiFreqRatio[2]          = 0x0001;
        io_user_input_basic.DfiFreqRatio[3]          = 0x0001;
        io_user_input_basic.Dfi1Exists               = 0x0001;

        // x8 DRAM
        io_user_input_basic.DramDataWidth[0]         = 0x0008; //x8
        io_user_input_basic.DramDataWidth[1]         = 0x0008; //x8
        io_user_input_basic.DramDataWidth[2]         = 0x0008; //x8
        io_user_input_basic.DramDataWidth[3]         = 0x0008; //x8
    }

    // Advanced init structure
    {
        // The sim team noted this needed to be set to a 0x0001
        io_user_input_advanced.RedundantCs_en           = 0x0001;

        io_user_input_advanced.ExtCalResVal             = 240; // 240 Ohm
        io_user_input_advanced.ODTImpedance[0]          = 60;
        io_user_input_advanced.ODTImpedance[1]          = 60;
        io_user_input_advanced.ODTImpedance[2]          = 60;
        io_user_input_advanced.ODTImpedance[3]          = 60;
        io_user_input_advanced.ATxImpedance             = 0xcfff;
        io_user_input_advanced.TxImpedance[0]           = 25; //Ohms
        io_user_input_advanced.TxImpedance[1]           = 25; //Ohms
        io_user_input_advanced.TxImpedance[2]           = 25; //Ohms
        io_user_input_advanced.TxImpedance[3]           = 25; //Ohms
        io_user_input_advanced.TxImpedanceCtrl1[0]      = 25; //Ohms
        io_user_input_advanced.TxImpedanceCtrl1[1]      = 25; //Ohms
        io_user_input_advanced.TxImpedanceCtrl1[2]      = 25; //Ohms
        io_user_input_advanced.TxImpedanceCtrl1[3]      = 25; //Ohms
        io_user_input_advanced.TxImpedanceCtrl2[0]      = 0x000;
        io_user_input_advanced.TxImpedanceCtrl2[1]      = 0x000;
        io_user_input_advanced.TxImpedanceCtrl2[2]      = 0x000;
        io_user_input_advanced.TxImpedanceCtrl2[3]      = 0x000;
        io_user_input_advanced.MemAlertEn               = 0x0000;
        io_user_input_advanced.MtestPUImp               = 240;
        io_user_input_advanced.CalInterval              = 0x0009;
        io_user_input_advanced.CalOnce                  = 0x0000;
        io_user_input_advanced.AlertRecoveryEnable      = 0x0000;
        io_user_input_advanced.RstRxTrkState            = 0x0000;
        io_user_input_advanced.Apb32BitMode             = 0x0000;
        io_user_input_advanced.en_3DS                   = 0x0000;
        io_user_input_advanced.en_16LogicalRanks_3DS    = 0x0000;
        io_user_input_advanced.rtt_term_en              = 0x0000;
        io_user_input_advanced.DramByteSwap[0]          = 0x0000;
        io_user_input_advanced.DramByteSwap[1]          = 0x0000;
        io_user_input_advanced.DramByteSwap[2]          = 0x0000;
        io_user_input_advanced.DramByteSwap[3]          = 0x0000;

        io_user_input_advanced.TxSlewRiseDQ[0]          = 0x0;
        io_user_input_advanced.TxSlewRiseDQ[1]          = 0x0;
        io_user_input_advanced.TxSlewRiseDQ[2]          = 0x0;
        io_user_input_advanced.TxSlewRiseDQ[3]          = 0x0;
        io_user_input_advanced.TxSlewFallDQ[0]          = 0x0;
        io_user_input_advanced.TxSlewFallDQ[1]          = 0x0;
        io_user_input_advanced.TxSlewFallDQ[2]          = 0x0;
        io_user_input_advanced.TxSlewFallDQ[3]          = 0x0;
        io_user_input_advanced.TxSlewRiseAC             = 0x1;
        io_user_input_advanced.TxSlewFallAC             = 0x2;
        io_user_input_advanced.TxSlewRiseCK             = 0x0;
        io_user_input_advanced.TxSlewFallCK             = 0x0;

        io_user_input_advanced.IsHighVDD                 = 0x0001;
        io_user_input_advanced.DisablePmuEcc            = 0x0000;

        // Per solvnet, set to a 1 for disable
        io_user_input_advanced.DisDynAdrTri[0]          = 0x0001;
        io_user_input_advanced.DisDynAdrTri[1]          = 0x0001;
        io_user_input_advanced.DisDynAdrTri[2]          = 0x0001;
        io_user_input_advanced.DisDynAdrTri[3]          = 0x0001;

        io_user_input_advanced.PhyMstrTrainInterval[0]  = 0x0000;
        io_user_input_advanced.PhyMstrTrainInterval[1]  = 0x0000;
        io_user_input_advanced.PhyMstrTrainInterval[2]  = 0x0000;
        io_user_input_advanced.PhyMstrTrainInterval[3]  = 0x0000;
        io_user_input_advanced.PhyMstrMaxReqToAck[0]    = 0x0000;
        io_user_input_advanced.PhyMstrMaxReqToAck[1]    = 0x0000;
        io_user_input_advanced.PhyMstrMaxReqToAck[2]    = 0x0000;
        io_user_input_advanced.PhyMstrMaxReqToAck[3]    = 0x0000;
        io_user_input_advanced.PhyMstrCtrlMode[0]       = 0x0000;
        io_user_input_advanced.PhyMstrCtrlMode[1]       = 0x0000;
        io_user_input_advanced.PhyMstrCtrlMode[2]       = 0x0000;
        io_user_input_advanced.PhyMstrCtrlMode[3]       = 0x0000;


        io_user_input_advanced.D4RxPreambleLength[0]    = 0x0001;
        io_user_input_advanced.D4RxPreambleLength[1]    = 0x0001;
        io_user_input_advanced.D4RxPreambleLength[2]    = 0x0001;
        io_user_input_advanced.D4RxPreambleLength[3]    = 0x0001;
        io_user_input_advanced.D4TxPreambleLength[0]    = 0x0000;
        io_user_input_advanced.D4TxPreambleLength[1]    = 0x0000;
        io_user_input_advanced.D4TxPreambleLength[2]    = 0x0000;
        io_user_input_advanced.D4TxPreambleLength[3]    = 0x0000;
        io_user_input_advanced.NvAnibRcvSel[0]         = 0x0000;
        io_user_input_advanced.NvAnibRcvSel[1]         = 0x0000;
        io_user_input_advanced.NvAnibRcvSel[2]         = 0x0000;
        io_user_input_advanced.NvAnibRcvSel[3]         = 0x0000;
        io_user_input_advanced.NvAnibRcvSel[4]         = 0x0000;
        io_user_input_advanced.NvAnibRcvSel[5]         = 0x0000;
        io_user_input_advanced.NvAnibRcvSel[6]         = 0x0000;
        io_user_input_advanced.NvAnibRcvSel[7]         = 0x0000;
        io_user_input_advanced.AnibRcvLaneSel[0]         = 0x0000;
        io_user_input_advanced.AnibRcvLaneSel[1]         = 0x0000;
        io_user_input_advanced.AnibRcvLaneSel[2]         = 0x0000;
        io_user_input_advanced.AnibRcvLaneSel[3]         = 0x0000;
        io_user_input_advanced.AnibRcvLaneSel[4]         = 0x0000;
        io_user_input_advanced.AnibRcvLaneSel[5]         = 0x0000;
        io_user_input_advanced.AnibRcvLaneSel[6]         = 0x0000;
        io_user_input_advanced.AnibRcvLaneSel[7]         = 0x0000;
        io_user_input_advanced.AnibRcvEn[0]              = 0x0000;
        io_user_input_advanced.AnibRcvEn[1]              = 0x0000;
        io_user_input_advanced.AnibRcvEn[2]              = 0x0000;
        io_user_input_advanced.AnibRcvEn[3]              = 0x0000;
        io_user_input_advanced.AnibRcvEn[4]              = 0x0000;
        io_user_input_advanced.AnibRcvEn[5]              = 0x0000;
        io_user_input_advanced.AnibRcvEn[6]              = 0x0000;
        io_user_input_advanced.AnibRcvEn[7]              = 0x0000;

        io_user_input_advanced.EnTdqs2dqTrackingTg0[0]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg0[1]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg0[2]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg0[3]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg1[0]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg1[1]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg1[2]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg1[3]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg2[0]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg2[1]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg2[2]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg2[3]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg3[0]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg3[1]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg3[2]  = 0x0000;
        io_user_input_advanced.EnTdqs2dqTrackingTg3[3]  = 0x0000;
        io_user_input_advanced.DqsOscRunTimeSel[0]      = 0x0100; // 256 MemClk
        io_user_input_advanced.DqsOscRunTimeSel[1]      = 0x0100; // 256 MemClk
        io_user_input_advanced.DqsOscRunTimeSel[2]      = 0x0100; // 256 MemClk
        io_user_input_advanced.DqsOscRunTimeSel[3]      = 0x0100; // 256 MemClk
        io_user_input_advanced.EnRxDqsTracking[0]       = 0x0000;
        io_user_input_advanced.EnRxDqsTracking[1]       = 0x0000;
        io_user_input_advanced.EnRxDqsTracking[2]       = 0x0000;
        io_user_input_advanced.EnRxDqsTracking[3]       = 0x0000;
        io_user_input_advanced.D5TxDqPreambleCtrl[0]    = 0x0000;
        io_user_input_advanced.D5TxDqPreambleCtrl[1]    = 0x0000;
        io_user_input_advanced.D5TxDqPreambleCtrl[2]    = 0x0000;
        io_user_input_advanced.D5TxDqPreambleCtrl[3]    = 0x0000;

        io_user_input_advanced.D5DisableRetraining      = 0x0000;

    }

    // DRAM input structure
    // Values taken from dwc_ddrphy_phyinit_initStruct.C
    {
        io_user_input_dram_config.MR0_A0 = 0x24;
        io_user_input_dram_config.MR2_A0 = 0x90;
        io_user_input_dram_config.MR8_A0 = 0x08;
        io_user_input_dram_config.MR50_A0 = 0x00;
        io_user_input_dram_config.PhyVref = 0x40;
        io_user_input_dram_config.X16Present = 0x00;

        // Note: not seeing this one setup anyway in particular
        // Leaving to a 0 as no DBYTES should be disabled to my knowledge
        io_user_input_dram_config.DisabledDbyte = 0x00;

        // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
        // Note: default value is 0x00 anyways
        io_user_input_dram_config.RCW00_ChA_D0 = 0x00;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Runs PHY init on a specific port
/// @param[in] i_target - the memory port on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Using a helper function here so we can get accurate target trace
/// TRGTID uses i_target in a macro and we want the port target (not i_target)
///
fapi2::ReturnCode run_phy_init( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // Create the variables that are needed below
    user_input_basic_t l_user_input_basic;
    user_input_advanced_t l_user_input_advanced;
    user_input_dram_config_t l_user_input_dram_config;

    // Perform PHY reset for Odyssey
    FAPI_TRY(mss::ody::phy::reset(i_target));

    // Configure the structure values
    FAPI_TRY(init_phy_structs(i_target,
                              l_user_input_basic,
                              l_user_input_advanced,
                              l_user_input_dram_config), TARGTIDFORMAT "failed init_phy_structs", TARGTID);

    // Configure the PY based upon the structures
    FAPI_TRY(init_phy_config(i_target,
                             l_user_input_basic,
                             l_user_input_advanced,
                             l_user_input_dram_config), TARGTIDFORMAT "failed init_phy_config", TARGTID);

fapi_try_exit:
    return fapi2::current_err;

}
/*! @} */
