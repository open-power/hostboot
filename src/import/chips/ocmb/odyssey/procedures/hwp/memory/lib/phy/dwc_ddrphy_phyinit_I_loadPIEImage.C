/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/dwc_ddrphy_phyinit_I_loadPIEImage.C $ */
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
/// @file dwc_ddrphy_phyinit_I_loadPIEImage.C
/// @brief Odyssey PHY init engine procedure implements Step I of initialization sequence
///
/// This file contains the implementation of dwc_ddrphy_phyinit_I_initPhyConfig
/// function.
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/c_str.H>

#include <lib/shared/ody_consts.H>
#include <lib/phy/dwc_ddrphy_phyinit_I_loadPIEImage.H>
#include <lib/phy/dwc_ddrphy_phyinit_LoadPieProdCode.H>
#include <lib/phy/ody_ddrphy_phyinit_structs.H>
#include <lib/phy/ody_ddrphy_phyinit_config.H>
#include <lib/phy/ody_ddrphy_csr_defines.H>

///
/// @brief Translates from the Synopsys register information, does the scom, and adds delay
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_addr - the Synopsys address on which to operate on
/// @param[in] i_data - the data to write out to the register
/// @param[in] i_delay_dfi - the delay in DFI clocks
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_userCustom_io_write16_wait(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
        const uint64_t i_addr,
        const int i_data,
        const uint64_t i_delay_dfi)
{
    // The worst case for the DFI to DDR clock occurs at 3200 (DDR rate)
    // The DFI runs at 1/4 the rate of the DDR clock
    // As fapi2::delay uses ns, the DFI clock has 2.5 ns per cycles
    // This is rounded up to 3 for the calculations
    constexpr uint64_t DFI_TO_NS_WORST_CASE = 3;
    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, i_addr, i_data));
    FAPI_TRY(fapi2::delay(i_delay_dfi * DFI_TO_NS_WORST_CASE, i_delay_dfi * DFI_TO_NS_WORST_CASE));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Generates structures, loads registers and programs the PHY initialization engine (PIE) after training
/// @param[in] i_target - the memory port on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_I_loadPIEImage( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // Configuring the runtime config via hard codes -> none of these values should change for firmware
    runtime_config_t l_runtime_config;

    l_runtime_config.skip_train = 0; // Do not skip training
    // Setting enable bits to 0, should be overwritten later
    l_runtime_config.enableBits[0] = 0;
    l_runtime_config.enableBits[1] = 0;
    l_runtime_config.enableBits[2] = 0;
    l_runtime_config.pubRev = mss::ody::PUB_REV;

    // These appear to be unused -> keeping them in for parity to the original Synopsys code
    {
        l_runtime_config.debug = 0; // No debug
        l_runtime_config.Train2D = 0; // This appears to be a holdover from DDR4
        l_runtime_config.RetEn = 0;
        l_runtime_config.initCtrl = 0;
    }

    user_input_basic_t l_user_input_basic;
    user_input_advanced_t l_user_input_advanced;
    user_input_dram_config_t l_dram_config;

    FAPI_TRY(init_phy_structs( i_target,
                               l_user_input_basic,
                               l_user_input_advanced,
                               l_dram_config));

    FAPI_TRY(dwc_ddrphy_phyinit_I_loadPIEImage( i_target,
             l_runtime_config,
             l_user_input_basic,
             l_user_input_advanced,
             l_dram_config));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Loads registers and programs the PHY initialization engine (PIE) after training
/// @param[in] i_target - the memory port on which to operate
/// @param[in,out] io_runtime_config - the runtime configuration
/// @param[in] i_user_input_basic - Synopsys basic user input structure
/// @param[in] i_user_input_advanced - Synopsys advanced user input structure
/// @param[in] i_dram_config the draminit message block
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_I_loadPIEImage( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        runtime_config_t& io_runtime_config,
        const user_input_basic_t& i_user_input_basic,
        const user_input_advanced_t& i_user_input_advanced,
        const user_input_dram_config_t& i_dram_config)
{

    int skip_training = io_runtime_config.skip_train;

    initRuntimeConfigEnableBits(i_target, io_runtime_config, i_user_input_advanced, i_dram_config);

    FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Start of dwc_ddrphy_phyinit_I_loadPIEImage()", TARGTID);

    int pstate;
    int p_addr;
    FAPI_DBG (TARGTIDFORMAT " ", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " ", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " //##############################################################", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " //", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " // 4.3.9(I) Load PHY Init Engine Image ", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " // ", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " // Load the PHY Initialization Engine memory with the provided initialization sequence.",
              TARGTID);
    FAPI_DBG (TARGTIDFORMAT " // ", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " //##############################################################", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " ", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " ", TARGTID);

    FAPI_DBG (TARGTIDFORMAT " // Enable access to the internal CSRs by setting the MicroContMuxSel CSR to 0. ", TARGTID);
    FAPI_DBG (TARGTIDFORMAT " // This allows the memory controller unrestricted access to the configuration CSRs. ",
              TARGTID);
    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16_wait(i_target, (tAPBONLY | csr_MicroContMuxSel_ADDR), 0x0, 40));


    //##############################################################
    // Forces the gaters of DfiTxClkEn and DfiRxClkEn to be 0
    // to clock gate part of the PUB
    // This is to prevent X propagation from CSRs on multi-cycle paths
    //##############################################################
    {
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming ForceClkGaterEnables::ForcePubDxClkEnLow to 0x1",
                  TARGTID);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_ForceClkGaterEnables_ADDR),
                 csr_ForcePubDxClkEnLow_MASK ));


        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming PIE Production Code", TARGTID);

        FAPI_TRY(dwc_ddrphy_phyinit_LoadPieProdCode(i_target, io_runtime_config));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag0_ADDR), 0x0000));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag1_ADDR), 0x0173));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag2_ADDR), 0x8160));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag3_ADDR), 0x6110));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag4_ADDR), 0x2152));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag5_ADDR), 0xDFBD));

        if(skip_training != 0 || i_user_input_advanced.D5DisableRetraining == 1)
        {
            // Diable DRAM Drift Compensation if training is skipped
            FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Disabling DRAM drift compensation since training was skipped",
                      TARGTID);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag6_ADDR), 0xffff));
        }
        else
        {
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag6_ADDR), 0x8060));
        }

        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tINITENG | csr_Seq0BDisableFlag7_ADDR), 0x6152));

        // Enable Async MAlert
        if(i_user_input_advanced.EnableMAlertAsync == 0x1)
        {
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_PGCR_ADDR), 0x4)); // Set csrMAlertAsync
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c1 | tANIB | csr_AsyncAnibRxEn_ADDR),
                     0x2)); //Give firmware direct access to ANIB pins

            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c1 | tANIB | csr_AsyncAnibMode_ADDR),
                     0x2)); // Enable bypass mode on BP_A[5]

            FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Enabling MAlert Async", TARGTID);
        }

        int PPTTrainSetup[4];

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            if (skip_training == 0)
            {
                // Enable PMI if training firmware was run
                FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Enabling Phy Master Interface for DRAM drift compensation",
                          TARGTID);
                PPTTrainSetup[pstate] = (i_user_input_advanced.PhyMstrTrainInterval[pstate] << csr_PhyMstrTrainInterval_LSB) |
                                        (i_user_input_advanced.PhyMstrMaxReqToAck[pstate] << csr_PhyMstrMaxReqToAck_LSB) |
                                        (i_user_input_advanced.PhyMstrCtrlMode[pstate] << csr_PhyMstrCtrlMode_LSB);

                FAPI_DBG (TARGTIDFORMAT
                          " // [phyinit_I_loadPIEImage] Pstate=%d, Memclk=%dMHz, Programming PPTTrainSetup::PhyMstrTrainInterval to 0x%x",
                          TARGTID, pstate, i_user_input_basic.Frequency[pstate], i_user_input_advanced.PhyMstrTrainInterval[pstate]);
                FAPI_DBG (TARGTIDFORMAT
                          " // [phyinit_I_loadPIEImage] Pstate=%d, Memclk=%dMHz, Programming PPTTrainSetup::PhyMstrMaxReqToAck to 0x%x",
                          TARGTID, pstate, i_user_input_basic.Frequency[pstate], i_user_input_advanced.PhyMstrMaxReqToAck[pstate]);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_PPTTrainSetup_ADDR),
                         PPTTrainSetup[pstate]));
            }

            FAPI_DBG (TARGTIDFORMAT
                      " // [phyinit_I_loadPIEImage] Pstate=%d, Memclk=%dMHz, Programming PPTTrainSetup2::PhyMstrFreqOverride to 0x3",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate]);

            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_PPTTrainSetup2_ADDR), 0x0003));
        }

        // Setting D5ACSMXlatSelect to 1
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming D5ACSMXlatSelect to 0x1", TARGTID);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_D5ACSMXlatSelect_ADDR), 0x0001));
    }


    //##############################################################
    //
    // Program DbyteRxEnTrain::EnDqsSampNegRxEn to 1 if
    // i_user_input_advanced.EnRxDqsTracking[pstate] == 1
    //
    //##############################################################
    {
        int EnDqsSampNegRxEn;
        int DbyteRxEnTrain;

        // Enable DQS sampling on negedge of RxEn if EnRxDqsTracking=1 for any pstate
        EnDqsSampNegRxEn = i_user_input_advanced.EnRxDqsTracking[0] | i_user_input_advanced.EnRxDqsTracking[1] |
                           i_user_input_advanced.EnRxDqsTracking[2] | i_user_input_advanced.EnRxDqsTracking[3];

        DbyteRxEnTrain = EnDqsSampNegRxEn << csr_EnDqsSampNegRxEn_LSB;

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming DbyteRxEnTrain::EnDqsSampNegRxEn to 0x%x", TARGTID,
                  EnDqsSampNegRxEn);

        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_DbyteRxEnTrain_ADDR), DbyteRxEnTrain));
    }




    //##############################################################
    //
    // Program TrackingModeCntrl::
    //      EnDfiTdqs2dqTrackingTg0..3
    //      EnRxDqsTracking
    //      DqsOscRunTimeSel
    //
    // NOTE: Programming this in step_I because firmware needs EnDfiTdqs2dqTrackingTg*
    //       to be 0x0 during training
    //
    //##############################################################
    {
        int EnDfiTdqs2dqTrackingTg0;
        int EnDfiTdqs2dqTrackingTg1;
        int EnDfiTdqs2dqTrackingTg2;
        int EnDfiTdqs2dqTrackingTg3;
        int EnRxDqsTracking;
        int DqsOscRunTimeSel = 0;
        int Tdqs2dqTrackingLimit = 0;   // Default to 0 (see CSR description for definition)
        int RxDqsTrackingThreshold = 1; // Default to 1 (see CSR description for definition)
        int TrackingModeCntrl;


        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;

            EnDfiTdqs2dqTrackingTg0 = i_user_input_advanced.EnTdqs2dqTrackingTg0[pstate];
            EnDfiTdqs2dqTrackingTg1 = i_user_input_advanced.EnTdqs2dqTrackingTg1[pstate];
            EnDfiTdqs2dqTrackingTg2 = i_user_input_advanced.EnTdqs2dqTrackingTg2[pstate];
            EnDfiTdqs2dqTrackingTg3 = i_user_input_advanced.EnTdqs2dqTrackingTg3[pstate];

            EnRxDqsTracking = i_user_input_advanced.EnRxDqsTracking[pstate];

            switch (i_user_input_advanced.DqsOscRunTimeSel[pstate])
            {
                case (256)  :
                    {
                        DqsOscRunTimeSel = 0;
                        break;
                    }

                case (512)  :
                    {
                        DqsOscRunTimeSel = 1;
                        break;
                    }

                case (1024) :
                    {
                        DqsOscRunTimeSel = 2;
                        break;
                    }

                case (2048) :
                    {
                        DqsOscRunTimeSel = 3;
                        break;
                    }

                case (4096) :
                    {
                        DqsOscRunTimeSel = 4;
                        break;
                    }

                case (8192) :
                    {
                        DqsOscRunTimeSel = 5;
                        break;
                    }

                default     :
                    {
                        FAPI_ASSERT(false,
                                    fapi2::ODY_PHYINIT_PIE_INVALID_DQS_OSC_TIME()
                                    .set_PORT_TARGET(i_target)
                                    .set_DQS_OSC_TIME(i_user_input_advanced.DqsOscRunTimeSel[pstate]),
                                    TARGTIDFORMAT
                                    " // [phyinit_I_loadPIEImage] Invalid value for i_user_input_advanced.DqsOscRunTimeSel[Pstate=%d] = %d. Check dwc_ddrphy_phyinit_struct.h for valid values.",
                                    TARGTID, pstate, i_user_input_advanced.DqsOscRunTimeSel[pstate]);
                    }
            }

            // csrDqsOscRunTimeSel must be 0x3 for PHY-initiated re-training
            if (i_user_input_advanced.D5DisableRetraining == 0)
            {
                DqsOscRunTimeSel = 3;
            }

            TrackingModeCntrl = (EnDfiTdqs2dqTrackingTg0 << csr_EnDfiTdqs2dqTrackingTg0_LSB) |
                                (EnDfiTdqs2dqTrackingTg1 << csr_EnDfiTdqs2dqTrackingTg1_LSB) |
                                (EnDfiTdqs2dqTrackingTg2 << csr_EnDfiTdqs2dqTrackingTg2_LSB) |
                                (EnDfiTdqs2dqTrackingTg3 << csr_EnDfiTdqs2dqTrackingTg3_LSB) |
                                (Tdqs2dqTrackingLimit    << csr_Tdqs2dqTrackingLimit_LSB)    |
                                (EnRxDqsTracking         << csr_EnRxDqsTracking_LSB)         |
                                (DqsOscRunTimeSel        << csr_DqsOscRunTimeSel_LSB)        |
                                (RxDqsTrackingThreshold  << csr_RxDqsTrackingThreshold_LSB)  ;

            FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Pstate=%d, Memclk=%dMHz, Programming TrackingModeCntrl to 0x%x",
                      TARGTID, pstate, i_user_input_basic.Frequency[pstate], TrackingModeCntrl);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tMASTER | csr_TrackingModeCntrl_ADDR),
                     TrackingModeCntrl));
        }
    }


    //##############################################################
    // Program D5ACSM0MaskCs[3:0] and D5ACSM1MaskCs[3:0] based
    // on number of ranks
    //##############################################################
    {
        int MaskCs_dfi0 = ~(i_dram_config.CsPresentChA) & 0xf;
        int MaskCs_dfi1 = ~(i_dram_config.CsPresentChB) & 0xf;

        if ((i_user_input_basic.NumRank_dfi0 < 0) || (i_user_input_basic.NumRank_dfi0 > 4))
        {
            FAPI_ASSERT(false,
                        fapi2::ODY_PHYINIT_PIE_INVALID_NUM_RANKS()
                        .set_PORT_TARGET(i_target)
                        .set_NUM_RANKS(i_user_input_basic.NumRank_dfi0)
                        .set_DFI(0),
                        TARGTIDFORMAT
                        " // [phyinit_I_loadPIEImage] Invalid value for i_user_input_basic.NumRank_dfi0 = %d. Valid values are 0 to 4. ",
                        TARGTID, i_user_input_basic.NumRank_dfi0);
        }

        if (i_user_input_basic.Dfi1Exists == 0 || i_user_input_advanced.Dfi1Active == 0)
        {
            MaskCs_dfi1 = 0xf; // Mask all D5ACSM1 CS[3:0] since DFI1 is not acive
        }
        else if ((i_user_input_basic.NumRank_dfi1 < 0)
                 || (i_user_input_basic.NumRank_dfi1 > 4))     // Dfi1Exists and Dfi1Active
        {
            FAPI_ASSERT(false,
                        fapi2::ODY_PHYINIT_PIE_INVALID_NUM_RANKS()
                        .set_PORT_TARGET(i_target)
                        .set_NUM_RANKS(i_user_input_basic.NumRank_dfi1)
                        .set_DFI(1),
                        TARGTIDFORMAT
                        " // [phyinit_I_loadPIEImage] Invalid value for i_user_input_basic.NumRank_dfi1 = %d. Valid values are 0 to 4. ",
                        TARGTID, i_user_input_basic.NumRank_dfi1);
        }

#ifdef csr_Seq0BGPR9_ADDR
        // GPR9 exists, GPRs have been moved so csr_Seq0BGPR4_ADDR below is conditional on pubRev
        int pubRev = io_runtime_config.pubRev;
#endif // csr_Seq0BGPR9_ADDR

        // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
#if 0
        dwc_ddrphy_phyinit_cmnt ("%s Programming GPR4 to 0x%x\n", printf_header, MaskCs_dfi0);
        dwc_ddrphy_phyinit_cmnt ("%s Programming GPR5 to 0x%x\n", printf_header, MaskCs_dfi1);

        for (pstate = 0; pstate < pUserInputBasic->NumPStates; pstate++)
        {
            p_addr = pstate << 20;
            dwc_ddrphy_phyinit_userCustom_io_write16((p_addr | tINITENG | csr_Seq0BGPR4_ADDR), MaskCs_dfi0);
            dwc_ddrphy_phyinit_userCustom_io_write16((p_addr | tINITENG | csr_Seq0BGPR5_ADDR), MaskCs_dfi1);
        }

        MaskCs_dfi0 = 0;
        MaskCs_dfi1 = 0;
#endif
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming D5ACSM0MaskCs to 0x%x", TARGTID, MaskCs_dfi0);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_D5ACSM0MaskCs_ADDR), MaskCs_dfi0 ));

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming D5ACSM1MaskCs to 0x%x", TARGTID, MaskCs_dfi1);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_D5ACSM1MaskCs_ADDR), MaskCs_dfi1 ));

        //##############################################################
        // Program Seq0BGPR6/D5ACSM<0/1>OuterLoopRepeatCnt
        //   - Storing the values of the OuterLoopRepeatCnt in Seq0BGPR6.
        //##############################################################

        uint16_t OuterLoopRepeatCnt;

        for (pstate = 0; pstate < i_user_input_basic.NumPStates; pstate++)
        {
            p_addr = pstate << 20;
            OuterLoopRepeatCnt = i_user_input_basic.Frequency[pstate] / (8400 / 20) - 1;
            FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Pstate=%d, Memclk=%dMHz,", TARGTID, pstate,
                      i_user_input_basic.Frequency[pstate]);
            FAPI_DBG (TARGTIDFORMAT " Programming Seq0BGPR6[%d] with OuterLoopRepeatCnt values to 0x%x", TARGTID, pstate,
                      OuterLoopRepeatCnt);
            FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (p_addr | tINITENG | csr_Seq0BGPR6_ADDR),
                     OuterLoopRepeatCnt));

            if (pstate == 0)
            {
                FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming D5ACSM<0/1>OuterLoopRepeatCnt=%x ", TARGTID,
                          OuterLoopRepeatCnt);
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,
                         (p_addr | tMASTER | c0 | csr_D5ACSM0OuterLoopRepeatCnt_ADDR),
                         OuterLoopRepeatCnt ));
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target,
                         (p_addr | tMASTER | c0 | csr_D5ACSM1OuterLoopRepeatCnt_ADDR),
                         OuterLoopRepeatCnt ));
            }
        }
    }

    //##############################################################
    // Program Seq0BGPR8/D5ACSM<0/1>AddressMask
    //   - Storing the values of the AddressMask in Seq0BGPR8 for RDIMM based on SDR values.
    //   - Program the AddressMask  values directly for UDIMM.
    //##############################################################
    // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
#if 0

    uint16_t AddressMask;
    int D5RdimmSDRmode[4];

    for (pstate = 0; pstate < pUserInputBasic->NumPStates; pstate++)
    {
        p_addr = pstate << 20;
        D5RdimmSDRmode[pstate] = (mb_DDR5R_1D[pstate].RCW00_ChA_D0 & 0x1) ? 0 : 1; // RCW00_ChA_D0[0]

        switch (pUserInputAdvanced->Num_Logical_Ranks)
        {
            case (16)  :
                {
                    AddressMask = (D5RdimmSDRmode[pstate]) ? 0x078f : 0x07ff;
                    break;
                }

            case (8)   :
                {
                    AddressMask = (D5RdimmSDRmode[pstate]) ? 0x078f : 0x07ff;
                    break;
                }

            case (4)   :
                {
                    AddressMask = (D5RdimmSDRmode[pstate]) ? 0x27cf : 0x27ff;
                    break;
                }

            case (2)   :
                {
                    AddressMask = (D5RdimmSDRmode[pstate]) ? 0x37ef : 0x37ff;
                    break;
                }

            default    :
                {
                    AddressMask = (D5RdimmSDRmode[pstate]) ? 0x078f : 0x07ff;
                }
        }

        dwc_ddrphy_phyinit_cmnt ("%s Pstate=%d, Memclk=%dMHz, Programming Seq0BGPR8[%d] with D5ACSM<0/1>AddressMask values to 0x%x\n",
                                 printf_header, pstate, pUserInputBasic->Frequency[pstate], pstate, AddressMask);
        dwc_ddrphy_phyinit_userCustom_io_write16( (p_addr | tINITENG | csr_Seq0BGPR8_ADDR), AddressMask);
    }

#endif

    {
        uint16_t AddressMask;

        switch (i_user_input_advanced.Num_Logical_Ranks)
        {
            case (16)  :
                {
                    AddressMask = 0x07df;
                    break;
                }

            case (8)   :
                {
                    AddressMask = 0x07ff;
                    break;
                }

            case (4)   :
                {
                    AddressMask = 0x27ff;
                    break;
                }

            case (2)   :
                {
                    AddressMask = 0x37ff;
                    break;
                }

            default    :
                {
                    AddressMask = 0x07ff;
                }
        }

        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming D5ACSM<0/1>AddressMask=%x ", TARGTID, AddressMask);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_D5ACSM0AddressMask_ADDR), AddressMask ));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_D5ACSM1AddressMask_ADDR), AddressMask ));
    }


    //##############################################################
    // Program D5ACSM<0/1>AlgaIncVal
    // - Storing the values of the AlgaIncVal in Seq0BGPR7 for RDIMM based on SDR values.
    // - Program the AlgaIncVal  values directly for UDIMM.
    //##############################################################
    // TODO:ZEN:MST-1585 Add in UDIMM vs RDIMM switches into the PHY init code
#if 0
    int AlgaIncVal;

    for (pstate = 0; pstate < pUserInputBasic->NumPStates; pstate++)
    {
        p_addr = pstate << 20;
        AlgaIncVal = (D5RdimmSDRmode[pstate]) ? 0x81 : 0x1;
        dwc_ddrphy_phyinit_cmnt ("%s Pstate=%d, Memclk=%dMHz, Programming Seq0BGPR7[%d] with D5ACSM<0/1>AlgaIncVal values to 0x%x\n",
                                 printf_header, pstate, pUserInputBasic->Frequency[pstate], pstate, AlgaIncVal);
        dwc_ddrphy_phyinit_userCustom_io_write16( (p_addr | tINITENG | csr_Seq0BGPR7_ADDR), AlgaIncVal);
    }

#endif
    {
        int AlgaIncVal;
        AlgaIncVal = 0x1;
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming D5ACSM<0/1>AlgaIncVal=%x ", TARGTID, AlgaIncVal);
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_D5ACSM0AlgaIncVal_ADDR), AlgaIncVal ));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_D5ACSM1AlgaIncVal_ADDR), AlgaIncVal ));
    }

    //##############################################################
    // Program CalRate::CalRun and CalZap
    //   - Prepare the calibration controller for mission mode
    //   - Turn on calibration and hold idle until dfi_init_start is asserted sequence is triggered.
    //##############################################################
    {
        int CalRate;
        int CalRun = 0x1;
        CalRate =  CalRun << csr_CalRun_LSB | (i_user_input_advanced.CalOnce << csr_CalOnce_LSB) |
                   (i_user_input_advanced.CalInterval << csr_CalInterval_LSB);

        FAPI_DBG (TARGTIDFORMAT
                  " // [phyinit_I_loadPIEImage] Turn on calibration and hold idle until dfi_init_start is asserted sequence is triggered.",
                  TARGTID);
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming CalZap to 0x%x", TARGTID, 0x1);
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming CalRate::CalRun to 0x%x", TARGTID, CalRun);
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming CalRate to 0x%x", TARGTID, CalRate);

        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_CalZap_ADDR), 0x1));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_CalRate_ADDR), CalRate));
    }

    //##############################################################
    // De-assert ForcePubDxClkEnLow to un-gate part of the PUB
    //##############################################################
    FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] Programming ForceClkGaterEnables::ForcePubDxClkEnLow to 0x0",
              TARGTID);
    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tMASTER | csr_ForceClkGaterEnables_ADDR), 0x0 ));

    //##############################################################
    //
    // Gate off UcClk/Hclk and flip MicroContMuxSel before going
    // into mission mode
    //
    //##############################################################
    FAPI_DBG (TARGTIDFORMAT " // Disabling Ucclk (PMU) and Hclk (training hardware)", TARGTID);
    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (tDRTUB | csr_UcclkHclkEnables_ADDR), 0x0));

    FAPI_DBG (TARGTIDFORMAT " // Isolate the APB access from the internal CSRs by setting the MicroContMuxSel CSR to 1. ",
              TARGTID);
    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16_wait(i_target, (tAPBONLY | csr_MicroContMuxSel_ADDR), 0x1, 40));

    FAPI_DBG (TARGTIDFORMAT " // [phyinit_I_loadPIEImage] End of dwc_ddrphy_phyinit_I_loadPIEImage()", TARGTID);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Tests that the given enable bits are set in the phyctx
/// @param[in] i_runtime_config - the runtime configuration
/// @param[in] enable_bits Bitmap to test against the contents of phyctx
/// @param[in] mode        Comparison mode
/// @param[in] type        Type of enable bits field to use
/// @return int - 1 if enable_bits are set in phyctx
/// @note This function allows the PHY Initialization Engine (PIE) and ACSM
/// instructions and the associated registers to be programmed conditionally.
///
int dwc_ddrphy_phyinit_TestPIEProdEnableBits( const runtime_config_t& i_runtime_config,
        uint32_t enable_bits,
        int mode,
        int type)
{

    uint32_t phyctx_enable_bits = i_runtime_config.enableBits[type];
    uint32_t tested_bits = phyctx_enable_bits & enable_bits;
    int test_value;

    switch (mode)
    {
        case ENABLE_BITS_ANY_BITS:
            {
                test_value = (tested_bits) ? 1 : 0;
                return test_value;
            }

        case ENABLE_BITS_NO_BITS:
            {
                test_value = (tested_bits) ? 1 : 0;
                return !test_value;
            }

        case ENABLE_BITS_ALL_BITS:
            {
                test_value = (tested_bits == enable_bits) ? 1 : 0;
                return test_value;
            }

        default:
            return 0;
    }
}

///
/// @brief Generates calls to dwc_ddrphy_phyinit_userCustom_io_write16
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_runtime_config - the runtime configuration
/// @param[in] code_sections Array of structures for continuous address sections of code
/// @param[in] code_section_count Size of the code_sections array
/// @param[in] code_data     Array of words that make up data for the code sections
/// @param[in] code_data_count Size of the code_data array
/// @param[in] code_markers  Array of code_markers, sorted by code index
/// @param[in] code_marker_count Size of the code_markers array
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note This function translates the code section and code data (word) arrays
/// into calls to dwc_ddrphy_phyinit_userCustom_io_write16 that create the PIE
/// and (for DDR5) ACSM images.
/// This function also fills in code markers with the start address of each
/// given code section.
/// IBM note: leaving the pointers in here to keep code inline with what was provided by Synopsys
///
fapi2::ReturnCode dwc_ddrphy_phyinit_LoadPIECodeSections(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const runtime_config_t& i_runtime_config,
        code_section_t* code_sections, size_t code_section_count,
        uint16_t* code_data, size_t code_data_count,
        code_marker_t* code_markers, size_t code_marker_count)
{
    FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] Start of dwc_ddrphy_phyinit_LoadPIECodeSections()",
              TARGTID);

    code_section_t* current_code_section = code_sections;
    uint32_t current_address = 0;
    size_t marker_index = 0;
    size_t data_index = 0;
    uint32_t pubRev = i_runtime_config.pubRev;

    for (size_t section_index = 0; section_index < code_section_count;
         data_index += current_code_section->section_len,
         ++section_index, ++current_code_section)
    {
        // Handle conditional and start address (jump) sections
        uint8_t section_type = current_code_section->section_type;

        switch (section_type)
        {
            case NORMAL_SECTION:
                break;

            case START_ADDRESS:
                FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] Moving start address from %x to %x", TARGTID,
                          current_address, current_code_section->start_address);
                current_address = current_code_section->start_address;
                break;

            case ENABLE_BITS_ANY_BITS:
                {
                    if (!(dwc_ddrphy_phyinit_TestPIEProdEnableBits(i_runtime_config,
                            current_code_section->enable_bits, ENABLE_BITS_ANY_BITS, current_code_section->enable_type)))
                    {
                        FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] No match for ANY enable_bits = %x, type = %x", TARGTID,
                                  current_code_section->enable_bits, current_code_section->enable_type);
                        continue;
                    }

                    FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] Matched ANY enable_bits = %x, type = %x", TARGTID,
                              current_code_section->enable_bits, current_code_section->enable_type);
                    break;
                }

            case ENABLE_BITS_NO_BITS:
                {
                    if (!(dwc_ddrphy_phyinit_TestPIEProdEnableBits(i_runtime_config,
                            current_code_section->enable_bits, ENABLE_BITS_NO_BITS, current_code_section->enable_type)))
                    {
                        FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] No match for NO enable_bits = %x, type = %x", TARGTID,
                                  current_code_section->enable_bits, current_code_section->enable_type);
                        continue;
                    }

                    FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] Matched NO enable_bits = %x, type = %x", TARGTID,
                              current_code_section->enable_bits, current_code_section->enable_type);
                    break;
                }

            case ENABLE_BITS_ALL_BITS:
                {
                    if (!(dwc_ddrphy_phyinit_TestPIEProdEnableBits(i_runtime_config,
                            current_code_section->enable_bits, ENABLE_BITS_ALL_BITS, current_code_section->enable_type)))
                    {
                        FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] No match for ALL enable_bits = %x, type = %x", TARGTID,
                                  current_code_section->enable_bits, current_code_section->enable_type);
                        continue;
                    }

                    FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] Matched ALL enable_bits = %x, type = %x", TARGTID,
                              current_code_section->enable_bits, current_code_section->enable_type);
                    break;
                }

            default:
                FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] Warning, unknown code section %u, ignoring", TARGTID,
                          current_code_section->section_type);
                break;
        }

        // Fill in required markers for current section
        while (marker_index < code_marker_count)
        {
            code_marker_t* current_code_marker = &(code_markers[marker_index]);

            if (current_code_marker->section_index > section_index)
            {
                break;
            }

            uint32_t* marker_location = current_code_marker->marker_location;
            *marker_location = current_address;
            ++marker_index;
        }

        // Call dwc_ddrphy_phyinit_userCustom_io_write16 to write data
        uint16_t section_len = current_code_section->section_len;

        if (data_index + section_len > code_data_count)
        {
            break;
        }

        uint16_t* current_data = &(code_data[data_index]);

        for (uint16_t j = 0; j < section_len; ++j, ++current_address, ++current_data)
        {
            if ((current_address == ((csr_SequenceReg0b175s2_ADDR | tINITENG) + 0x1))  && ((pubRev >= 0x0350 && pubRev < 0x0400)
                    || (pubRev >= 0x0420)))   // 40 bit 176 PIE instructions
            {
                FAPI_ASSERT(false,
                            fapi2::ODY_PHYINIT_PIE_SPACE_OVERFILL()
                            .set_PORT_TARGET(i_target)
                            .set_ADDRESS(current_address)
                            .set_END_ADDRESS((csr_SequenceReg0b175s2_ADDR | tINITENG) + 0x1)
                            .set_PUB_REV(pubRev),
                            TARGTIDFORMAT
                            " // [phyinit_LoadPIECodeSections] PIE instruction space overspilled, Address %x is not part of PIE instruction space for PUB REVISION %x ",
                            TARGTID, current_address, pubRev);
            }
            else if ((current_address == ((csr_SequenceReg0b143s2_ADDR | tINITENG) + 0x1))  && (!((pubRev >= 0x0350
                     && pubRev < 0x0400) || (pubRev >= 0x0420))))   // 40 bit 144 PIE instructions
            {
                FAPI_ASSERT(false,
                            fapi2::ODY_PHYINIT_PIE_SPACE_OVERFILL()
                            .set_PORT_TARGET(i_target)
                            .set_ADDRESS(current_address)
                            .set_END_ADDRESS((csr_SequenceReg0b143s2_ADDR | tINITENG) + 0x1)
                            .set_PUB_REV(pubRev),
                            TARGTIDFORMAT
                            " // [phyinit_LoadPIECodeSections] PIE instruction space overspilled, Address %x is not part of PIE instruction space for PUB REVISION %x ",
                            TARGTID, current_address, pubRev);
            }
            else if ((current_address == 0x41400)
                     || (current_address == 0x42400))     // 64 bit 256 instructions/128 bit 128 instruction pairs strating from 41000/42000
            {
                FAPI_ASSERT(false,
                            fapi2::ODY_PHYINIT_PIE_SPACE_OVERFILL()
                            .set_PORT_TARGET(i_target)
                            .set_ADDRESS(current_address)
                            .set_END_ADDRESS(0x41400)
                            .set_PUB_REV(pubRev),
                            TARGTIDFORMAT
                            " // [phyinit_LoadPIECodeSections] ACSM instruction space overspilled, Address %x is not part of ACSM instruction space for PUB REVISION %x ",
                            TARGTID, current_address, pubRev);
            }
            else
            {
                FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, current_address, *current_data));
            }
        }
    }

    // Warn of mismatched input data
    if (data_index != code_data_count)
    {
        FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] Warning, sum of code section lengths (%zu) != "
                  "code data count (%zu)", TARGTID, data_index, code_data_count);
    }

    // Fill in remaining markers
    while (marker_index < code_marker_count)
    {
        code_marker_t* current_code_marker = &(code_markers[marker_index]);
        uint32_t* marker_location = current_code_marker->marker_location;
        *marker_location = current_address;
        ++marker_index;
    }

    FAPI_DBG (TARGTIDFORMAT " // [phyinit_LoadPIECodeSections] End of dwc_ddrphy_phyinit_LoadPIECodeSections()", TARGTID);

fapi_try_exit:
    return fapi2::current_err;
}

// PIE/ACSM configuration enable bits (must match hwt_common_uctl.h)
#define ENABLE_BITS_HCLKEN_PWRDN                               (0x00000001) // PUB_REV > 0x0220 && PUB_REV != 0x0300
#define ENABLE_BITS_3DS_EN                                     (0x00000002) // pUserInputAdvanced->en_3DS
#define ENABLE_BITS_RTT_REDUNDANTCS_EN                         (0x00000004) // pUserInputAdvanced->special_feature_1_en || pUserInputAdvanced->rtt_en
#define ENABLE_BITS_ALERT_RECOVERY_EN_RSTRXTRKSTATE_EN         (0x00000008) // pubRev >= 0x0330 && phyctx->userInputAdvanced.AlertRecoveryEnable==1 && phyctx->userInputAdvanced.RstRxTrkState==1
#define ENABLE_BITS_REDUNDANTCS_EN                             (0x00000010) // pUserInputAdvanced->special_feature_1_en
#define ENABLE_BITS_REDUNDANTCS_3DS_8_LOGICAL_RANKS            (0x00000020) // pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS & PUserInputAdvanced->Num_Logical_Ranks==8
#define ENABLE_BITS_NOREDUNDANTCS_3DS_8_LOGICAL_RANKS          (0x00000040) // !pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS & PUserInputAdvanced->Num_Logical_Ranks==8
#define ENABLE_BITS_REDUNDANTCS_3DS_16_LOGICAL_RANKS           (0x00000080) // pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS & PUserInputAdvanced->Num_Logical_Ranks==16
#define ENABLE_BITS_NOREDUNDANTCS_3DS_16_LOGICAL_RANKS         (0x00000100) // !pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS & PUserInputAdvanced->Num_Logical_Ranks==16
#define ENABLE_BITS_RTT_TERMINATION_EN                         (0x00000200) // pUserInputAdvanced->rtt_term_en
#define ENABLE_BITS_PHYINLP2_EN                                (0x00000400) // ((pubRev >= 0x0420)) && pubRev != 0x0421 && phyctx->userInputAdvanced.PhyInLP2En_Pwr_Saving)
#define ENABLE_BITS_VREGCTRL_LP2_PWRSAVINGS_EN                 (0x00000800) // pUserInputAdvanced->VREGCtrl_LP2_PwrSavings_En
#define ENABLE_BITS_ALERT_RECOVERY_EN_RSTRXTRKSTATE_DIS        (0x00001000) // PUB_REV >= 0x0330 && phyctx->userInputAdvanced.AlertRecoveryEnable==1 && phyctx->userInputAdvanced.RstRxTrkState==0
#define ENABLE_BITS_REDUNDANTCS_3DS_2_LOGICAL_RANKS            (0x00002000) // pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS & PUserInputAdvanced->Num_Logical_Ranks==2
#define ENABLE_BITS_NOREDUNDANTCS_3DS_2_LOGICAL_RANKS          (0x00004000) // !pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS & PUserInputAdvanced->Num_Logical_Ranks==2
#define ENABLE_BITS_REDUNDANTCS_3DS_4_LOGICAL_RANKS            (0x00008000) // pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS & PUserInputAdvanced->Num_Logical_Ranks==4
#define ENABLE_BITS_NOREDUNDANTCS_3DS_4_LOGICAL_RANKS          (0x00010000) // !pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS & PUserInputAdvanced->Num_Logical_Ranks==4
#define ENABLE_BITS_REDUNDANTCS_3DS_EN                         (0x00020000) // pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS
#define ENABLE_BITS_NOREDUNDANTCS_3DS_EN                       (0x00040000) // !pUserInputAdvanced->special_feature_1_en & pUserInputAdvanced->en_3DS

#define ENABLE_BITS_TYPE_GENERAL            0
#define ENABLE_BITS_TYPE_RTT_A              1
#define ENABLE_BITS_TYPE_RTT_B              2

///
/// @brief Set enable bits based on PUB revision
/// @param[in] i_target - the memory port on which to operate
/// @param[in,out] io_runtime_config - the runtime configuration
/// @param[in] i_user_input_advanced - Synopsys advanced user input structure
/// @param[in] i_dram_config the draminit message block
///
void initRuntimeConfigEnableBits(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                 runtime_config_t& io_runtime_config,
                                 const user_input_advanced_t& i_user_input_advanced,
                                 const user_input_dram_config_t& i_dram_config)
{
    FAPI_DBG (TARGTIDFORMAT " // [initRuntimeConfigEnableBits] Start of initRuntimeConfigEnableBits()", TARGTID);

    uint32_t enableBits = 0;
    uint32_t pubRev = io_runtime_config.pubRev;

    if ((pubRev > 0x0220) && (pubRev != 0x0300))
    {
        enableBits |= ENABLE_BITS_HCLKEN_PWRDN;
    }

    if (i_user_input_advanced.en_3DS)
    {
        enableBits |= ENABLE_BITS_3DS_EN;
    }

    if ((pubRev >= 0x0330) && (i_user_input_advanced.AlertRecoveryEnable == 1)
        && (i_user_input_advanced.RstRxTrkState == 1))
    {
        enableBits |= ENABLE_BITS_ALERT_RECOVERY_EN_RSTRXTRKSTATE_EN;
    }

    if (i_user_input_advanced.special_feature_1_en)
    {
        enableBits |= ENABLE_BITS_REDUNDANTCS_EN;
    }

    if ((i_user_input_advanced.special_feature_1_en == 1) && (i_user_input_advanced.Num_Logical_Ranks == 8)
        && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_REDUNDANTCS_3DS_8_LOGICAL_RANKS;
    }

    if ((i_user_input_advanced.special_feature_1_en == 0) && (i_user_input_advanced.Num_Logical_Ranks == 8)
        && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_NOREDUNDANTCS_3DS_8_LOGICAL_RANKS;
    }

    if ((i_user_input_advanced.special_feature_1_en == 1) && (i_user_input_advanced.Num_Logical_Ranks == 16)
        && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_REDUNDANTCS_3DS_16_LOGICAL_RANKS;
    }

    if ((i_user_input_advanced.special_feature_1_en == 0) && (i_user_input_advanced.Num_Logical_Ranks == 16)
        && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_NOREDUNDANTCS_3DS_16_LOGICAL_RANKS;
    }

    if (i_user_input_advanced.rtt_term_en)
    {
        enableBits |= ENABLE_BITS_RTT_TERMINATION_EN;
    }

    if ((i_user_input_advanced.special_feature_1_en == 1) || (i_user_input_advanced.rtt_term_en == 1))
    {
        enableBits |= ENABLE_BITS_RTT_REDUNDANTCS_EN;
    }

    if (i_user_input_advanced.VREGCtrl_LP2_PwrSavings_En == 1)
    {
        enableBits |= ENABLE_BITS_VREGCTRL_LP2_PWRSAVINGS_EN;
    }

    if (((pubRev >= 0x0420) && (pubRev != 0x0421)) && (i_user_input_advanced.PhyInLP2En_Pwr_Saving))
    {
        enableBits |= ENABLE_BITS_PHYINLP2_EN;
    }

    if ((pubRev >= 0x0330) && (i_user_input_advanced.AlertRecoveryEnable == 1)
        && (i_user_input_advanced.RstRxTrkState == 0))
    {
        enableBits |= ENABLE_BITS_ALERT_RECOVERY_EN_RSTRXTRKSTATE_DIS;
    }

    if ((i_user_input_advanced.special_feature_1_en == 1) && (i_user_input_advanced.Num_Logical_Ranks == 2)
        && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_REDUNDANTCS_3DS_2_LOGICAL_RANKS;
    }

    if ((i_user_input_advanced.special_feature_1_en == 0) && (i_user_input_advanced.Num_Logical_Ranks == 2)
        && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_NOREDUNDANTCS_3DS_2_LOGICAL_RANKS;
    }

    if ((i_user_input_advanced.special_feature_1_en == 1) && (i_user_input_advanced.Num_Logical_Ranks == 4)
        && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_REDUNDANTCS_3DS_4_LOGICAL_RANKS;
    }

    if ((i_user_input_advanced.special_feature_1_en == 0) && (i_user_input_advanced.Num_Logical_Ranks == 4)
        && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_NOREDUNDANTCS_3DS_4_LOGICAL_RANKS;
    }

    if ((i_user_input_advanced.special_feature_1_en == 1) && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_REDUNDANTCS_3DS_EN;
    }

    if ((i_user_input_advanced.special_feature_1_en == 0) && (i_user_input_advanced.en_3DS == 1))
    {
        enableBits |= ENABLE_BITS_NOREDUNDANTCS_3DS_EN;
    }

    io_runtime_config.enableBits[ENABLE_BITS_TYPE_GENERAL] = enableBits;
    FAPI_DBG (TARGTIDFORMAT " // [initRuntimeConfigEnableBits] enableBits[%u] = 0x%08x", TARGTID, 0, enableBits);


    unsigned l_array[2][4] =
    {
        // Channel A ranks 0->3
        {
            i_dram_config.WR_RD_RTT_PARK_A0,
            i_dram_config.WR_RD_RTT_PARK_A1,
            i_dram_config.WR_RD_RTT_PARK_A2,
            i_dram_config.WR_RD_RTT_PARK_A3,
        },

        // Channel B ranks 0->3
        {
            i_dram_config.WR_RD_RTT_PARK_B0,
            i_dram_config.WR_RD_RTT_PARK_B1,
            i_dram_config.WR_RD_RTT_PARK_B2,
            i_dram_config.WR_RD_RTT_PARK_B3,
        },
    };

    for(uint8_t chan = 0; chan < 2; ++chan)
    {
        enableBits = 0; //clear previous enableBits
        unsigned rtt_enable_bit = 1;

        for(uint8_t rank = 0, rank_bit = 1; rank < 4; ++rank, rank_bit <<= 1)
        {
            unsigned wr_rd_rtt_park = l_array[chan][rank];
            unsigned rtt_required = ((wr_rd_rtt_park >> 4) & 0xfu) | rank_bit;
            FAPI_DBG (TARGTIDFORMAT " // [initRuntimeConfigEnableBits] WR_RD_RTT_PARK_%c%u = 0x%08x, rtt_required = 0x%08x",
                      TARGTID,
                      chan == 0 ? 'A' : 'B', rank, wr_rd_rtt_park);

            FAPI_DBG (TARGTIDFORMAT " // [initRuntimeConfigEnableBits] rtt_required = 0x%08x", TARGTID, rtt_required);

            for(unsigned rtt = 0; rtt < 16; ++rtt)
            {
                if ((rtt & rank_bit) == 0)
                {
                    continue;
                }

                if (rtt == rtt_required)
                {
                    enableBits |= rtt_enable_bit;
                }

                rtt_enable_bit <<= 1;
            }
        }

        int disable_rtt = (i_user_input_advanced.special_feature_1_en == 1) || (i_user_input_advanced.rtt_term_en == 0) ;
        io_runtime_config.enableBits[ENABLE_BITS_TYPE_RTT_A + chan] = (disable_rtt) ? 0x0 : enableBits;
        FAPI_DBG (TARGTIDFORMAT " // [initRuntimeConfigEnableBits] enableBits[%u] = 0x%08x", TARGTID,
                  ENABLE_BITS_TYPE_RTT_A + chan, (disable_rtt) ? 0x0 : enableBits );
    }

    FAPI_DBG (TARGTIDFORMAT " // [initRuntimeConfigEnableBits] End of initRuntimeConfigEnableBits()", TARGTID);
}
