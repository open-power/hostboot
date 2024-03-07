/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/dwc_ddrphy_phyinit_LoadPieProdCode.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
/// @file dwc_ddrphy_phyinit_LoadPieProdCode.C
/// @brief Odyssey PHY init loading PIE production code procedures
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB


#include <fapi2.H>

#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/c_str.H>

#include <lib/phy/dwc_ddrphy_phyinit_LoadPieProdCode.H>
#include <lib/phy/ody_ddrphy_phyinit_structs.H>
#include <lib/phy/ody_ddrphy_phyinit_config.H>
#include <lib/phy/ody_ddrphy_csr_defines.H>

#ifdef __PPE__
    #ifdef FAPI_INF
        #undef FAPI_INF
    #endif
    #ifdef FAPI_DBG
        #undef FAPI_DBG
    #endif

    #define FAPI_INF(_fmt_, _args_...)
    #define FAPI_DBG(_fmt_, _args_...)

#endif

///
/// @brief Loads the PHY Initialization Engine (PIE) code
/// @param[in] i_target - the memory port on which to operate
/// @param[in] i_runtime_config - the runtime configuration
/// @param[in] code_data - hwp_bit_istream for the PIE image data
/// @param[in] code_sections - hwp_bit_istream for the PIE code sections
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dwc_ddrphy_phyinit_LoadPieProdCode(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const runtime_config_t& i_runtime_config,
        fapi2::hwp_bit_istream& code_data,
        fapi2::hwp_bit_istream& code_sections)
{
    // This is the size of the PIE code image, computed as sizeof(code_data)/sizeof(code_data[0]) where
    // sizeof(code_data[0]) = 2 since the original array is of type uint16
    constexpr uint16_t COUNTOF_CODE_DATA = 10775;

    // This is the size of the PIE code sections array, in number of elements
    constexpr uint16_t COUNTOF_CODE_SECTIONS = 319;

    static uint32_t D5ACSM_1N_StartAddr;
    static uint32_t D5ACSM_2N_StartAddr;
    static uint32_t D5ACSM_2N_StopAddr;
    static uint32_t lp3Addr_StartAddr;
    static uint32_t pptAddr_StartAddr;
    static uint32_t startAddr_StartAddr;
    static code_marker_t code_markers[] =
    {
        { 1, &D5ACSM_1N_StartAddr },
        { 72, &D5ACSM_2N_StartAddr },
        { 143, &D5ACSM_2N_StopAddr },
        { 287, &startAddr_StartAddr },
        { 300, &pptAddr_StartAddr },
        { 316, &lp3Addr_StartAddr },
    };
    uint16_t startAddr = 0;
    uint16_t pptAddr = 0;
    uint16_t lp3Addr = 0;
    uint16_t D5ACSMStartAddrVal_1N = 0;
    uint16_t D5ACSMStartAddrVal_2N = 0;
    uint16_t D5ACSMStopAddrVal_1N = 0;
    uint16_t D5ACSMStopAddrVal_2N = 0;
    uint16_t D5ACSMPtrXlat01 = 0;
    uint16_t D5ACSMPtrXlat23 = 0;
    FAPI_TRY(dwc_ddrphy_phyinit_LoadPIECodeSections(i_target, i_runtime_config, code_sections, COUNTOF_CODE_SECTIONS,
             code_data, COUNTOF_CODE_DATA, code_markers, COUNTOF(code_markers)));
    D5ACSMStartAddrVal_1N = 0;
    D5ACSMStartAddrVal_2N = (D5ACSM_2N_StartAddr - D5ACSM_1N_StartAddr) >> 2;
    D5ACSMStopAddrVal_1N = D5ACSMStartAddrVal_2N - 1;
    D5ACSMStopAddrVal_2N = ((D5ACSM_2N_StopAddr - D5ACSM_1N_StartAddr) >> 2) - 1;
    D5ACSMPtrXlat01 = (D5ACSMStopAddrVal_1N << csr_D5ACSMStopAddrVal0_LSB) | (D5ACSMStartAddrVal_1N <<
                      csr_D5ACSMStartAddrVal0_LSB);
    D5ACSMPtrXlat23 = (D5ACSMStopAddrVal_2N << csr_D5ACSMStopAddrVal0_LSB) | (D5ACSMStartAddrVal_2N <<
                      csr_D5ACSMStartAddrVal0_LSB);

    for(int fsp = 0; fsp < 2; fsp++)
    {
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, tMASTER | c0 | (csr_D5ACSMPtrXlat0_ADDR + fsp),
                 D5ACSMPtrXlat01));
        FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, tMASTER | c0 | (csr_D5ACSMPtrXlat2_ADDR + fsp),
                 D5ACSMPtrXlat23));
    };

    startAddr = (startAddr_StartAddr - startAddr_StartAddr) / 3;

    pptAddr = (pptAddr_StartAddr - startAddr_StartAddr) / 3;

    lp3Addr = (lp3Addr_StartAddr - startAddr_StartAddr) / 3;

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): ---------------------------------------------------------------------------------------------------\n",
             TARGTID);

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): Programming the 0B sequencer 0b0000 start vector registers with %d.\n", TARGTID,
             startAddr);

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): Programming the 0B sequencer 0b1000 start vector register with %d.\n", TARGTID,
             pptAddr);

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): Programming the 0B sequencer 0b1111 start vector register with %d.\n", TARGTID,
             lp3Addr);

    FAPI_DBG(TARGTIDFORMAT
             " seq0b_LoadPstateSeqProductionCode(): ---------------------------------------------------------------------------------------------------\n",
             TARGTID);

    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tINITENG | csr_StartVector0b0_ADDR), startAddr));

    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tINITENG | csr_StartVector0b8_ADDR), pptAddr));

    FAPI_TRY(dwc_ddrphy_phyinit_userCustom_io_write16(i_target, (c0 | tINITENG | csr_StartVector0b15_ADDR), lp3Addr));

fapi_try_exit :
    return fapi2::current_err;
}
