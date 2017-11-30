/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_unmask_errors.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file p9c_mss_unmask_errors.C
/// @brief Tools for DDR4 DIMMs centaur procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
//
//

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <p9c_mss_unmask_errors.H>
#include <cen_gen_scom_addresses.H>
#include <fapi2.H>

///
/// @brief Sets action regs and mask settings for pervasive errors to their runtime settings.
/// @param[in] i_target Centaur target
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode mss_unmask_pervasive_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_INF("ENTER mss_unmask_pervasive_errors()");

    //*************************
    //*************************
    // TP_PERV_LFIR
    //*************************
    //*************************

    fapi2::buffer<uint64_t> l_tp_perv_lfir_mask_or;
    fapi2::buffer<uint64_t> l_tp_perv_lfir_mask_and;
    fapi2::buffer<uint64_t> l_tp_perv_lfir_action0;
    fapi2::buffer<uint64_t> l_tp_perv_lfir_action1;
    fapi2::buffer<uint64_t> l_mem_perv_lfir_mask_or;
    fapi2::buffer<uint64_t> l_mem_perv_lfir_mask_and;
    fapi2::buffer<uint64_t> l_mem_perv_lfir_action0;
    fapi2::buffer<uint64_t> l_mem_perv_lfir_action1;
    fapi2::buffer<uint64_t> l_nest_perv_lfir_mask_or;
    fapi2::buffer<uint64_t> l_nest_perv_lfir_mask_and;
    fapi2::buffer<uint64_t> l_nest_perv_lfir_action0;
    fapi2::buffer<uint64_t> l_nest_perv_lfir_action1;

    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    // Read action0
    FAPI_TRY(fapi2::getScom(i_target, CEN_LOCAL_FIR_ACTION0_PCB, l_tp_perv_lfir_action0));

    // Read action1
    FAPI_TRY(fapi2::getScom(i_target, CEN_LOCAL_FIR_ACTION1_PCB, l_tp_perv_lfir_action1));

    l_tp_perv_lfir_mask_or.flush<0>();
    l_tp_perv_lfir_mask_and.flush<1>();

    // 0    CFIR internal parity error          recoverable     unmask
    l_tp_perv_lfir_action0.clearBit<0>();
    l_tp_perv_lfir_action1.setBit<0>();
    l_tp_perv_lfir_mask_and.clearBit<0>();

    // 1    GPIO (PCB error)                    recoverable     mask (forever)
    // 2    CC (PCB error)                      recoverable     mask (forever)
    // 3    CC (OPCG, parity, scan collision)   recoverable     mask (forever)
    // 4    PSC (PCB error)                     recoverable     mask (forever)
    // 5    PSC (parity error)                  recoverable     mask (forever)
    // 6    Thermal (parity error)              recoverable     mask (forever)
    // 7    Thermal (PCB error)                 recoverable     mask (forever)
    // 8    Thermal (critical Trip error)       recoverable     mask (forever)
    // 9    Thermal (fatal Trip error)          recoverable     mask (forever)
    // 10   Thermal (Voltage trip error)        recoverable     mask (forever)
    // 11   Trace Array                         recoverable     mask (forever)
    // 12   Trace Array                         recoverable     mask (forever)
    l_tp_perv_lfir_action0.clearBit<1, 12>();
    l_tp_perv_lfir_action1.setBit<1, 12>();
    l_tp_perv_lfir_mask_or.setBit<1, 12>();

    // 13   ITR                                 recoverable     unmask
    l_tp_perv_lfir_action0.clearBit<13>();
    l_tp_perv_lfir_action1.setBit<13>();
    l_tp_perv_lfir_mask_and.clearBit<13>();

    // 14   ITR                                 recoverable     unmask
    l_tp_perv_lfir_action0.clearBit<14>();
    l_tp_perv_lfir_action1.setBit<14>();
    l_tp_perv_lfir_mask_and.clearBit<14>();


    // 15   ITR (itr_tc_pcbsl_slave_fir_err)    recoverable     mask (forever)
    // 16   PIB                                 recoverable     mask (forever)
    // 17   PIB                                 recoverable     mask (forever)
    // 18   PIB                                 recoverable     mask (forever)
    l_tp_perv_lfir_action0.clearBit<15, 4>();
    l_tp_perv_lfir_action1.setBit<15, 4>();
    l_tp_perv_lfir_mask_or.setBit<15, 4>();


    // NOTE: 19 and 20 already cleared and unmasked in cen_mem_pll_setup.C
    // 19   nest PLLlock                        recoverable     unmask
    // 20   mem PLLlock                         recoverable     unmask

    // 21:39    unused local errors             recoverable     mask (forever)
    // 40   local xstop in another chiplet      recoverable     mask (forever)
    l_tp_perv_lfir_action0.clearBit<21, 20>();
    l_tp_perv_lfir_action1.setBit<21, 20>();
    l_tp_perv_lfir_mask_or.setBit<21, 20>();

    // 41:63    Reserved            not implemented, so won't touch these


    // Write action0
    FAPI_TRY(fapi2::putScom(i_target, CEN_LOCAL_FIR_ACTION0_PCB, l_tp_perv_lfir_action0));

    // Write action1
    FAPI_TRY(fapi2::putScom(i_target, CEN_LOCAL_FIR_ACTION1_PCB, l_tp_perv_lfir_action1));

    // Write mask OR
    FAPI_TRY(fapi2::putScom(i_target, CEN_LOCAL_FIR_MASK_PCB2, l_tp_perv_lfir_mask_or));

    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target,  CEN_LOCAL_FIR_MASK_PCB1, l_tp_perv_lfir_mask_and));


    //*************************
    //*************************
    // NEST_PERV_LFIR
    //*************************
    //*************************


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_nest_perv_lfir_action0.flush<0>();
    l_nest_perv_lfir_action1.flush<0>();
    l_nest_perv_lfir_mask_or.flush<0>();
    l_nest_perv_lfir_mask_and.flush<1>();

    // 0    CFIR internal parity error          recoverable     unmask
    l_nest_perv_lfir_action0.clearBit<0>();
    l_nest_perv_lfir_action1.setBit<0>();
    l_nest_perv_lfir_mask_and.clearBit<0>();

    // 1    GPIO (PCB error)                    recoverable     mask (forever)
    // 2    CC (PCB error)                      recoverable     mask (forever)
    // 3    CC (OPCG, parity, scan collision)   recoverable     mask (forever)
    // 4    PSC (PCB error)                     recoverable     mask (forever)
    // 5    PSC (parity error)                  recoverable     mask (forever)
    // 6    Thermal (parity error)              recoverable     mask (forever)
    // 7    Thermal (PCB error)                 recoverable     mask (forever)
    // 8    Thermal (critical Trip error)       recoverable     mask (forever)
    // 9    Thermal (fatal Trip error)          recoverable     mask (forever)
    // 10   Thermal (Voltage trip error)        recoverable     mask (forever)
    // 11   Trace Array                         recoverable     mask (forever)
    // 12   Trace Array                         recoverable     mask (forever)
    // 13:39    unused local errors             recoverable     mask (forever)
    // 40   local xstop in another chiplet      recoverable     mask (forever)
    l_nest_perv_lfir_action0.clearBit<1, 40>();
    l_nest_perv_lfir_action1.setBit<1, 40>();
    l_nest_perv_lfir_mask_or.setBit<1, 40>();

    // 41:63    Reserved            not implemented, so won't touch these

    // Write action0
    FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_LOCAL_FIR_ACTION0_PCB, l_nest_perv_lfir_action0));

    // Write action1
    FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_LOCAL_FIR_ACTION1_PCB, l_nest_perv_lfir_action1));

    // Write mask OR
    FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_LOCAL_FIR_MASK_PCB2, l_nest_perv_lfir_mask_or));

    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target,  CEN_TCN_LOCAL_FIR_MASK_PCB1, l_nest_perv_lfir_mask_and));

    //*************************
    //*************************
    // MEM_PERV_LFIR
    //*************************
    //*************************

    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_mem_perv_lfir_action0.flush<0>();
    l_mem_perv_lfir_action1.flush<0>();
    l_mem_perv_lfir_mask_or.flush<0>();
    l_mem_perv_lfir_mask_and.flush<1>();

    // 0    CFIR internal parity error          recoverable     unmask
    l_mem_perv_lfir_action0.clearBit<0>();
    l_mem_perv_lfir_action1.setBit<0>();
    l_mem_perv_lfir_mask_and.clearBit<0>();

    // 1    GPIO (PCB error)                    recoverable     mask (forever)
    // 2    CC (PCB error)                      recoverable     mask (forever)
    // 3    CC (OPCG, parity, scan collision)   recoverable     mask (forever)
    // 4    PSC (PCB error)                     recoverable     mask (forever)
    // 5    PSC (parity error)                  recoverable     mask (forever)
    // 6    Thermal (parity error)              recoverable     mask (forever)
    // 7    Thermal (PCB error)                 recoverable     mask (forever)
    // 8    Thermal (critical Trip error)       recoverable     mask (forever)
    // 9    Thermal (fatal Trip error)          recoverable     mask (forever)
    // 10   Thermal (Voltage trip error)        recoverable     mask (forever)
    // 11   mba01 Trace Array                   recoverable     mask (forever)
    // 12   mba01 Trace Array                   recoverable     mask (forever)
    // 13   mba23 Trace Array                   recoverable     mask (forever)
    // 14   mba23 Trace Array                   recoverable     mask (forever)
    // 15:39    unused local errors             recoverable     mask (forever)
    // 40   local xstop in another chiplet      recoverable     mask (forever)
    l_mem_perv_lfir_action0.clearBit<1, 40>();
    l_mem_perv_lfir_action1.setBit<1, 40>();
    l_mem_perv_lfir_mask_or.setBit<1, 40>();

    // 41:63    Reserved            not implemented, so won't touch these

    // Write action0
    FAPI_TRY(fapi2::putScom(i_target, CEN_TCM_LOCAL_FIR_ACTION0_PCB, l_mem_perv_lfir_action0));

    // Write action1
    FAPI_TRY(fapi2::putScom(i_target, CEN_TCM_LOCAL_FIR_ACTION1_PCB, l_mem_perv_lfir_action1));

    // Write mask OR
    FAPI_TRY(fapi2::putScom(i_target, CEN_TCM_LOCAL_FIR_MASK_PCB2, l_mem_perv_lfir_mask_or));

    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target,  CEN_TCM_LOCAL_FIR_MASK_PCB1, l_mem_perv_lfir_mask_and));

fapi_try_exit:
    FAPI_INF("EXIT mss_unmask_pervasive_errors()");
    return fapi2::current_err;
}

///
/// @brief  Sets action regs and mask settings for inband errors to their runtime settings.
/// @param[in]  i_target Centaur target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of cen_mem_startclocks.C
///
fapi2::ReturnCode mss_unmask_inband_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)

{
    FAPI_INF("ENTER mss_unmask_inband_errors()");

    //*************************
    //*************************
    // MBS_FIR_REG
    //*************************
    //*************************

    fapi2::buffer<uint64_t> l_mbs_fir_mask;
    fapi2::buffer<uint64_t> l_mbs_fir_mask_or;
    fapi2::buffer<uint64_t> l_mbs_fir_mask_and;
    fapi2::buffer<uint64_t> l_mbs_fir_action0;
    fapi2::buffer<uint64_t> l_mbs_fir_action1;

    uint8_t l_dd2_fir_bit_defn_changes = 0;
    uint8_t l_hw414700 = 0;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> l_attached_dmi_target = i_target.getParent<fapi2::TARGET_TYPE_DMI>();
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_attached_proc_target =
        l_attached_dmi_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Get attribute for HW414700 workaround
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, l_attached_proc_target, l_hw414700),
             "Error getting ATTR_CHIP_EC_FEATURE_HW414700");

    // Get attribute that tells us if mbspa 0 cmd complete attention is fixed for dd2
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_DD2_FIR_BIT_DEFN_CHANGES, i_target,
                           l_dd2_fir_bit_defn_changes),
             "Error getting ATTR_CEN_CENTAUR_EC_FEATURE_DD2_FIR_BIT_DEFN_CHANGES");

    // Read mask
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBS_FIR_MASK_REG, l_mbs_fir_mask));


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_mbs_fir_action0.flush<0>();
    l_mbs_fir_action1.flush<0>();
    l_mbs_fir_mask_or.flush<0>();
    l_mbs_fir_mask_and.flush<1>();

    // 0    host_protocol_error     channel checkstop   unmask
    l_mbs_fir_action0.clearBit<0>();
    l_mbs_fir_action1.clearBit<0>();
    l_mbs_fir_mask_and.clearBit<0>();

    // 1    int_protocol_error      channel checkstop   unmask
    l_mbs_fir_action0.clearBit<1>();
    l_mbs_fir_action1.clearBit<1>();
    l_mbs_fir_mask_and.clearBit<1>();

    // 2    invalid_address_error   channel checkstop   mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<2>();
    l_mbs_fir_action1.clearBit<2>();
    l_mbs_fir_mask_or.setBit<2>();

    // 3    external_timeout        recoverable         mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<3>();
    l_mbs_fir_action1.setBit<3>();
    l_mbs_fir_mask_or.setBit<3>();

    // 4    internal_timeout        recoverable         mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<4>();
    l_mbs_fir_action1.setBit<4>();
    l_mbs_fir_mask_or.setBit<4>();

    // 5    int_buffer_ce           recoverable         unmask
    l_mbs_fir_action0.clearBit<5>();
    l_mbs_fir_action1.setBit<5>();
    l_mbs_fir_mask_and.clearBit<5>();

    // 6    int_buffer_ue           channel checkstop   unmask
    // HW278850: 8B ecc UE from SRB,PFB not transformed to SUE when allocating into L4
    l_mbs_fir_action0.clearBit<6>();
    l_mbs_fir_action1.clearBit<6>();
    l_mbs_fir_mask_and.clearBit<6>();

    // 7    int_buffer_sue          recoverable         mask (forever)
    l_mbs_fir_action0.clearBit<7>();
    l_mbs_fir_action1.setBit<7>();
    l_mbs_fir_mask_or.setBit<7>();

    // 8    int_parity_error        channel checkstop   unmask
    l_mbs_fir_action0.clearBit<8>();
    l_mbs_fir_action1.clearBit<8>();
    l_mbs_fir_mask_and.clearBit<8>();

    // 9    cache_srw_ce            recoverable         mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<9>();
    l_mbs_fir_action1.setBit<9>();
    l_mbs_fir_mask_or.setBit<9>();

    // 10    cache_srw_ue           recoverable         mask (until unmask_fetch_errors)
    //       hw414700               channel checkstop   mask (until unmask_fetch_errors)

    if (l_hw414700)
    {
        l_mbs_fir_action0.clearBit<10>();
        l_mbs_fir_action1.clearBit<10>();
        l_mbs_fir_mask_or.setBit<10>();
    }
    else
    {
        l_mbs_fir_action0.clearBit<10>();
        l_mbs_fir_action1.setBit<10>();
        l_mbs_fir_mask_or.setBit<10>();
    }

    // 11    cache_srw_sue          recoverable         mask (forever)
    l_mbs_fir_action0.clearBit<11>();
    l_mbs_fir_action1.setBit<11>();
    l_mbs_fir_mask_or.setBit<11>();

    // 12    cache_co_ce            recoverable         mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<12>();
    l_mbs_fir_action1.setBit<12>();
    l_mbs_fir_mask_or.setBit<12>();

    // 13    cache_co_ue            recoverable         mask (until unmask_fetch_errors)
    //       hw414700               channel checkstop   mask (until unmask_fetch_errors)
    if (l_hw414700)
    {
        l_mbs_fir_action0.clearBit<13>();
        l_mbs_fir_action1.clearBit<13>();
        l_mbs_fir_mask_or.setBit<13>();
    }
    else
    {
        l_mbs_fir_action0.clearBit<13>();
        l_mbs_fir_action1.setBit<13>();
        l_mbs_fir_mask_or.setBit<13>();
    }

    // 14    cache_co_sue           recoverable         mask (forever)
    l_mbs_fir_action0.clearBit<14>();
    l_mbs_fir_action1.setBit<14>();
    l_mbs_fir_mask_or.setBit<14>();

    // 15    dir_ce                 recoverable    DD1: mask (forever)
    // 15    dir_ce                 recoverable    DD2: mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<15>();
    l_mbs_fir_action1.setBit<15>();
    l_mbs_fir_mask_or.setBit<15>();

    // 16    dir_ue                 channel checkstop   mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<16>();
    l_mbs_fir_action1.clearBit<16>();
    l_mbs_fir_mask_or.setBit<16>();

    // 17    dir_member_deleted     recoverable         mask (forever)
    l_mbs_fir_action0.clearBit<17>();
    l_mbs_fir_action1.setBit<17>();
    l_mbs_fir_mask_or.setBit<17>();

    // 18    dir_all_members_deleted channel checkstop  mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<18>();
    l_mbs_fir_action1.clearBit<18>();
    l_mbs_fir_mask_or.setBit<18>();

    // 19    lru_error               recoverable        mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<19>();
    l_mbs_fir_action1.setBit<19>();
    l_mbs_fir_mask_or.setBit<19>();

    // 20    eDRAM error             channel checkstop  mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<20>();
    l_mbs_fir_action1.clearBit<20>();
    l_mbs_fir_mask_or.setBit<20>();

    // 21    emergency_throttle_set  recoverable        mask (forever)
    l_mbs_fir_action0.clearBit<21>();
    l_mbs_fir_action1.setBit<21>();
    l_mbs_fir_mask_or.setBit<21>();

    // 22    Host Inband Read Error  recoverable        mask (forever)
    l_mbs_fir_action0.clearBit<22>();
    l_mbs_fir_action1.setBit<22>();
    l_mbs_fir_mask_or.setBit<22>();

    // 23    Host Inband Write Error recoverable        mask (forever)
    l_mbs_fir_action0.clearBit<23>();
    l_mbs_fir_action1.setBit<23>();
    l_mbs_fir_mask_or.setBit<23>();

    // 24    OCC Inband Read Error   recoverable        mask (forever)
    l_mbs_fir_action0.clearBit<24>();
    l_mbs_fir_action1.setBit<24>();
    l_mbs_fir_mask_or.setBit<24>();

    // 25    OCC Inband Write Error  recoverable        mask (forever)
    l_mbs_fir_action0.clearBit<25>();
    l_mbs_fir_action1.setBit<25>();
    l_mbs_fir_mask_or.setBit<25>();

    // 26    srb_buffer_ce           recoverable        mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<26>();
    l_mbs_fir_action1.setBit<26>();
    l_mbs_fir_mask_or.setBit<26>();

    // 27    srb_buffer_ue           channel checkstop   mask (until unmask_fetch_errors)
    l_mbs_fir_action0.clearBit<27>();
    l_mbs_fir_action1.clearBit<27>();
    l_mbs_fir_mask_or.setBit<27>();

    // 28    srb_buffer_sue          recoverable         mask (forever)
    l_mbs_fir_action0.clearBit<28>();
    l_mbs_fir_action1.setBit<28>();
    l_mbs_fir_mask_or.setBit<28>();

    if (l_dd2_fir_bit_defn_changes)
    {
        // 29    dir_purge_ce               recoverable          mask
        l_mbs_fir_action0.clearBit<29>();
        l_mbs_fir_action1.setBit<29>();
        l_mbs_fir_mask_or.setBit<29>();

        // 30    proximal_ce_ue             channel checkstop    mask (until unmask_fetch_errors)
        l_mbs_fir_action0.clearBit<30>();
        l_mbs_fir_action1.clearBit<30>();
        l_mbs_fir_mask_or.setBit<30>();

        // 31    spare                      recoverable          mask
        l_mbs_fir_action0.clearBit<31>();
        l_mbs_fir_action1.setBit<31>();
        l_mbs_fir_mask_or.setBit<31>();

        // 32    spare                      recoverable          mask
        l_mbs_fir_action0.clearBit<32>();
        l_mbs_fir_action1.setBit<32>();
        l_mbs_fir_mask_or.setBit<33>();

        // 33    internal_scom_error        recoverable          unmask
        l_mbs_fir_action0.clearBit<33>();
        l_mbs_fir_action1.setBit<33>();
        l_mbs_fir_mask_and.clearBit<33>();

        // 34    internal_scom_error_copy   recoverable          unmask
        l_mbs_fir_action0.clearBit<34>();
        l_mbs_fir_action1.setBit<34>();
        l_mbs_fir_mask_and.clearBit<34>();

        // 35:63    Reserved                not implemented, so won't touch these
    }

    else
    {
        // 29    internal_scom_error     recoverable         unmask
        l_mbs_fir_action0.clearBit<29>();
        l_mbs_fir_action1.setBit<29>();
        l_mbs_fir_mask_and.clearBit<29>();

        // 30    internal_scom_error_copy recoverable        unmask
        l_mbs_fir_action0.clearBit<30>();
        l_mbs_fir_action1.setBit<30>();
        l_mbs_fir_mask_and.clearBit<30>();

        // 31:63    Reserved                not implemented, so won't touch these
    }

    // Write action0
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBS_FIR_ACTION0_REG_RO, l_mbs_fir_action0));
    // Write action1
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBS_FIR_ACTION1_REG_RO, l_mbs_fir_action1));


    // Write mask OR
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBS_FIR_MASK_REG_WO_OR, l_mbs_fir_mask_or));
    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBS_FIR_MASK_REG_WO_AND, l_mbs_fir_mask_and))


    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBS_FIR_ACTION0_REG_RO, l_mbs_fir_action0));
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBS_FIR_ACTION1_REG_RO, l_mbs_fir_action1));
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBS_FIR_MASK_REG, l_mbs_fir_mask));

    //************************************************

fapi_try_exit:
    FAPI_INF("EXIT mss_unmask_inband_errors()");
    return fapi2::current_err;

}

///
/// @brief Sets action regs and mask settings for ddr phy errors to runtime settings.
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of proc_cen_framelock.C
///
fapi2::ReturnCode mss_unmask_ddrphy_errors(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
{
    FAPI_INF("ENTER mss_unmask ddrphy_errors()");

    //*************************
    //*************************
    // DDRPHY_FIR_REG
    //*************************
    //*************************

    fapi2::buffer<uint64_t> l_ddrphy_fir_mask;
    fapi2::buffer<uint64_t> l_ddrphy_fir_mask_or;
    fapi2::buffer<uint64_t> l_ddrphy_fir_mask_and;
    fapi2::buffer<uint64_t> l_ddrphy_fir_action0;
    fapi2::buffer<uint64_t> l_ddrphy_fir_action1;
    fapi2::buffer<uint64_t> l_mbafir_mask;
    fapi2::buffer<uint64_t> l_mbafir_mask_or;
    fapi2::buffer<uint64_t> l_mbafir_mask_and;
    fapi2::buffer<uint64_t> l_mbafir_action0;
    fapi2::buffer<uint64_t> l_mbafir_action1;

    uint8_t l_dd2_fir_bit_defn_changes = 0;
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;

    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_ddrphy_fir_action0.flush<0>();
    l_ddrphy_fir_action1.flush<0>();
    l_ddrphy_fir_mask_or.flush<0>();
    l_ddrphy_fir_mask_and.flush<0>();
    l_ddrphy_fir_mask_and.setBit<48, 16>();

    // 0:47 Reserved                not implemented, so won't touch these

    // 48   ddr0_fsm_ckstp          channel checkstop   unmask
    l_ddrphy_fir_action0.clearBit<48>();
    l_ddrphy_fir_action1.clearBit<48>();
    l_ddrphy_fir_mask_and.clearBit<48>();

    // 49   ddr0_parity_ckstp       channel checkstop   unmask
    l_ddrphy_fir_action0.clearBit<49>();
    l_ddrphy_fir_action1.clearBit<49>();
    l_ddrphy_fir_mask_and.clearBit<49>();

    // 50   ddr0_calibration_error  recoverable         mask (forever)
    l_ddrphy_fir_action0.clearBit<50>();
    l_ddrphy_fir_action1.setBit<50>();
    l_ddrphy_fir_mask_or.setBit<50>();

    // 51   ddr0_fsm_err            recoverable         unmask
    l_ddrphy_fir_action0.clearBit<51>();
    l_ddrphy_fir_action1.setBit<51>();
    l_ddrphy_fir_mask_and.clearBit<51>();

    // 52   ddr0_parity_err         recoverable         unmask
    l_ddrphy_fir_action0.clearBit<52>();
    l_ddrphy_fir_action1.setBit<52>();
    l_ddrphy_fir_mask_and.clearBit<52>();

    // 53   ddr01_fir_parity_err    recoverable         unmask
    l_ddrphy_fir_action0.clearBit<53>();
    l_ddrphy_fir_action1.setBit<53>();
    l_ddrphy_fir_mask_and.clearBit<53>();

    // 54   Reserved                recoverable         mask (forever)
    l_ddrphy_fir_action0.clearBit<54>();
    l_ddrphy_fir_action1.setBit<54>();
    l_ddrphy_fir_mask_or.setBit<54>();

    // 55   Reserved                recoverable         mask (forever)
    l_ddrphy_fir_action0.clearBit<55>();
    l_ddrphy_fir_action1.setBit<55>();
    l_ddrphy_fir_mask_or.setBit<55>();

    // 56   ddr1_fsm_ckstp          channel checkstop   unmask
    l_ddrphy_fir_action0.clearBit<56>();
    l_ddrphy_fir_action1.clearBit<56>();
    l_ddrphy_fir_mask_and.clearBit<56>();

    // 57   ddr1_parity_ckstp       channel checkstop   unmask
    l_ddrphy_fir_action0.clearBit<57>();
    l_ddrphy_fir_action1.clearBit<57>();
    l_ddrphy_fir_mask_and.clearBit<57>();

    // 58   ddr1_calibration_error  recoverable         mask (forever)
    l_ddrphy_fir_action0.clearBit<58>();
    l_ddrphy_fir_action1.setBit<58>();
    l_ddrphy_fir_mask_or.setBit<58>();

    // 59   ddr1_fsm_err            recoverable         unmask
    l_ddrphy_fir_action0.clearBit<59>();
    l_ddrphy_fir_action1.setBit<59>();
    l_ddrphy_fir_mask_and.clearBit<59>();

    // 60   ddr1_parity_err         recoverable         unmask
    l_ddrphy_fir_action0.clearBit<60>();
    l_ddrphy_fir_action1.setBit<60>();
    l_ddrphy_fir_mask_and.clearBit<60>();

    // 61   Reserved                recoverable         mask (forever)
    l_ddrphy_fir_action0.clearBit<61>();
    l_ddrphy_fir_action1.setBit<61>();
    l_ddrphy_fir_mask_or.setBit<61>();

    // 62   Reserved                recoverable         mask (forever)
    l_ddrphy_fir_action0.clearBit<62>();
    l_ddrphy_fir_action1.setBit<62>();
    l_ddrphy_fir_mask_or.setBit<62>();

    // 63   Reserved                recoverable         mask (forever)
    l_ddrphy_fir_action0.clearBit<63>();
    l_ddrphy_fir_action1.setBit<63>();
    l_ddrphy_fir_mask_or.setBit<63>();

    // Write action0
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_PHY01_DDRPHY_FIR_ACTION0_REG_RO, l_ddrphy_fir_action0));

    // Write action1
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_PHY01_DDRPHY_FIR_ACTION1_REG_RO, l_ddrphy_fir_action1));

    // Write mask OR
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_PHY01_DDRPHY_FIR_MASK_REG_WO_OR, l_ddrphy_fir_mask_or));
    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_PHY01_DDRPHY_FIR_MASK_REG_WO_AND, l_ddrphy_fir_mask_and));

    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_PHY01_DDRPHY_FIR_ACTION0_REG_RO, l_ddrphy_fir_action0));
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_PHY01_DDRPHY_FIR_ACTION1_REG_RO, l_ddrphy_fir_action1));
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_PHY01_DDRPHY_FIR_MASK_REG, l_ddrphy_fir_mask));

    //************************************************


    //*************************
    //*************************
    // MBAFIR
    //*************************
    //*************************

    // Get Centaur target for the given MBA
    l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
    // Get attribute that tells us if mbspa 0 cmd complete attention is fixed for dd2
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_DD2_FIR_BIT_DEFN_CHANGES, l_targetCentaur,
                           l_dd2_fir_bit_defn_changes), "Error getting ATTR_CEN_CENTAUR_EC_FEATURE_DD2_FIR_BIT_DEFN_CHANGES");


    // Read mask
    FAPI_TRY(fapi2::getScom(i_target,
                            CEN_MBA_MBAFIRMASK,
                            l_mbafir_mask));

    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_mbafir_action0.flush<0>();
    l_mbafir_action1.flush<0>();
    l_mbafir_mask_or.flush<0>();
    l_mbafir_mask_and.flush<1>();


    // 0    Invalid_Maint_Cmd           recoverable         masked (forever)
    l_mbafir_action0.clearBit<0>();
    l_mbafir_action1.setBit<0>();
    l_mbafir_mask_or.setBit<0>();

    // 1    Invalid_Maint_Address       recoverable         masked (forever)
    l_mbafir_action0.clearBit<1>();
    l_mbafir_action1.setBit<1>();
    l_mbafir_mask_or.setBit<1>();

    // 2    Multi_address_Maint_timeout recoverable         masked (until mss_unmask_maint_errors)
    l_mbafir_action0.clearBit<2>();
    l_mbafir_action1.setBit<2>();
    l_mbafir_mask_or.setBit<2>();

    // 3    Internal_fsm_error          channel checkstop   unmask
    l_mbafir_action0.clearBit<3>();
    l_mbafir_action1.clearBit<3>();
    l_mbafir_mask_and.clearBit<3>();

    // 4    MCBIST_Error                recoverable         mask (forever)
    l_mbafir_action0.clearBit<4>();
    l_mbafir_action1.setBit<4>();
    l_mbafir_mask_or.setBit<4>();

    // 5    scom_cmd_reg_pe             channel checkstop   unmask
    l_mbafir_action0.clearBit<5>();
    l_mbafir_action1.clearBit<5>();
    l_mbafir_mask_and.clearBit<5>();

    // 6    channel_chkstp_err          channel checkstop   unmask
    l_mbafir_action0.clearBit<6>();
    l_mbafir_action1.clearBit<6>();
    l_mbafir_mask_and.clearBit<6>();

    // 7    wrd_caw2_data_ce_ue_err     channel checkstop   masked (until mss_unmask_maint_errors)
    l_mbafir_action0.clearBit<7>();
    l_mbafir_action1.clearBit<7>();
    l_mbafir_mask_or.setBit<7>();

    if (l_dd2_fir_bit_defn_changes)
    {
        // 8    maint_1hot_st_error_dd2 channel checkstop   unmask
        l_mbafir_action0.clearBit<8>();
        l_mbafir_action1.clearBit<8>();
        l_mbafir_mask_and.clearBit<8>();
    }
    else
    {
        // 8    RESERVED                recoverable         mask (forever)
        l_mbafir_action0.clearBit<8>();
        l_mbafir_action1.setBit<8>();
        l_mbafir_mask_or.setBit<8>();
    }

    // 9:14 RESERVED                    recoverable         mask (forever)
    l_mbafir_action0.clearBit<9, 6>();
    l_mbafir_action1.setBit<9, 6>();
    l_mbafir_mask_or.setBit<9, 6>();

    // 15   internal scom error         recoverable         unmask
    l_mbafir_action0.clearBit<15>();
    l_mbafir_action1.setBit<15>();
    l_mbafir_mask_and.clearBit<15>();

    // 16   internal scom error clone   recoverable         unmask
    l_mbafir_action0.clearBit<16>();
    l_mbafir_action1.setBit<16>();
    l_mbafir_mask_and.clearBit<16>();


    // 17:63 RESERVED           not implemented, so won't touch these

    // Write action0
    FAPI_TRY(fapi2::putScom(i_target,
                            CEN_MBA_MBAFIRACT0,
                            l_mbafir_action0));

    // Write action1
    FAPI_TRY(fapi2::putScom(i_target,
                            CEN_MBA_MBAFIRACT1,
                            l_mbafir_action1));

    // Write mask OR
    FAPI_TRY(fapi2::putScom(i_target,
                            CEN_MBA_MBAFIRMASK_WO_OR,
                            l_mbafir_mask_or));


    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target,
                            CEN_MBA_MBAFIRMASK_WO_AND,
                            l_mbafir_mask_and));


    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(i_target,
                            CEN_MBA_MBAFIRACT0,
                            l_mbafir_action0));
    FAPI_TRY(fapi2::getScom(i_target,
                            CEN_MBA_MBAFIRACT1,
                            l_mbafir_action1));
    FAPI_TRY(fapi2::getScom(i_target,
                            CEN_MBA_MBAFIRMASK,
                            l_mbafir_mask));

    //************************************************

fapi_try_exit:
    FAPI_INF("EXIT mss_unmask_ddrphy_errors()");
    return fapi2::current_err;
}

///
/// @brief Sets MBACALFIR action regs to their runtime settings.
///        Unmasks errors that are valid for PRD to handle after mss_draminit procedure.
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit.C.
///
fapi2::ReturnCode mss_unmask_draminit_errors(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
{
    FAPI_INF("ENTER mss_unmask_draminit_errors()");

    //*************************
    //*************************
    // MBACALFIR
    //*************************
    //*************************

    fapi2::buffer<uint64_t> l_mbacalfir_mask;
    fapi2::buffer<uint64_t> l_mbacalfir_mask_or;
    fapi2::buffer<uint64_t> l_mbacalfir_mask_and;
    fapi2::buffer<uint64_t> l_mbacalfir_action0;
    fapi2::buffer<uint64_t> l_mbacalfir_action1;

    uint8_t l_dd2_fir_bit_defn_changes = 0;
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;
    uint8_t l_dimm_type = 0;
    uint8_t l_hw414700 = 0;

    // Get Centaur target for the given MBA
    l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

    // Get DMI target for given Centaur, and processor for given DMI
    fapi2::Target<fapi2::TARGET_TYPE_DMI> l_attached_dmi_target = l_targetCentaur.getParent<fapi2::TARGET_TYPE_DMI>();
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_attached_proc_target =
        l_attached_dmi_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Get attribute for HW414700 workaround
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, l_attached_proc_target, l_hw414700),
             "Error getting ATTR_CHIP_EC_FEATURE_HW414700");

    // Get attribute that tells us if mbspa 0 cmd complete attention is fixed for dd2
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_DD2_FIR_BIT_DEFN_CHANGES, l_targetCentaur,
                           l_dd2_fir_bit_defn_changes), "Error getting ATTR_CEN_CENTAUR_EC_FEATURE_DD2_FIR_BIT_DEFN_CHANGES");

    // Get DIMM type
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, i_target, l_dimm_type), "Error getting ATTR_CEN_EFF_DIMM_TYPE");

    // Read mask
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIR_MASK, l_mbacalfir_mask));

    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_mbacalfir_action0.flush<0>();
    l_mbacalfir_action1.flush<0>();
    l_mbacalfir_mask_or.flush<0>();
    l_mbacalfir_mask_and.flush<1>();

    // 0    MBA Recoverable Error       recoverable         mask (until after draminit_training)
    l_mbacalfir_action0.clearBit<0>();
    l_mbacalfir_action1.setBit<0>();
    l_mbacalfir_mask_or.setBit<0>();

    // 1    MBA Nonrecoverable Error    channel checkstop   mask (until after draminit_mc)
    l_mbacalfir_action0.clearBit<1>();
    l_mbacalfir_action1.clearBit<1>();
    l_mbacalfir_mask_or.setBit<1>();

    // 2    Refresh Overrun             recoverable         mask (until after draminit_mc)
    l_mbacalfir_action0.clearBit<2>();
    l_mbacalfir_action1.setBit<2>();
    l_mbacalfir_mask_or.setBit<2>();

    // 3    WAT error                   recoverable         mask (forever)
    l_mbacalfir_action0.clearBit<3>();
    l_mbacalfir_action1.setBit<3>();
    l_mbacalfir_mask_or.setBit<3>();

    // 4    RCD Parity Error 0          recoverable         unmask (if RDIMM or LRDIMM)
    l_mbacalfir_action0.clearBit<4>();
    l_mbacalfir_action1.setBit<4>();

    if ((l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
        || (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM))
    {
        l_mbacalfir_mask_and.clearBit<4>();
    }
    else
    {
        l_mbacalfir_mask_or.setBit<4>();
    }

    // 5    ddr0_cal_timeout_err        recoverable         mask (until after draminit_mc)
    l_mbacalfir_action0.clearBit<5>();
    l_mbacalfir_action1.setBit<5>();
    l_mbacalfir_mask_or.setBit<5>();

    // 6    ddr1_cal_timeout_err        recoverable         mask (until after draminit_mc)
    l_mbacalfir_action0.clearBit<6>();
    l_mbacalfir_action1.setBit<6>();
    l_mbacalfir_mask_or.setBit<6>();

    // 7    RCD Parity Error 1          recoverable         unmask (if RDIMM or LRDIMM)
    l_mbacalfir_action0.clearBit<7>();
    l_mbacalfir_action1.setBit<7>();

    if ((l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
        || (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM))
    {
        l_mbacalfir_mask_and.clearBit<7>();
    }
    else
    {
        l_mbacalfir_mask_or.setBit<7>();
    }

    // 8    mbx to mba par error        channel checkstop   mask (until after draminit_training_adv)
    l_mbacalfir_action0.clearBit<8>();
    l_mbacalfir_action1.clearBit<8>();
    l_mbacalfir_mask_or.setBit<8>();

    // 9    mba_wrd ue                  recoverable         mask (until mainline traffic)
    //      hw414700                    channel checkstop   mask (until mainline traffic)

    if (l_hw414700)
    {
        l_mbacalfir_action0.clearBit<9>();
        l_mbacalfir_action1.clearBit<9>();
        l_mbacalfir_mask_or.setBit<9>();
    }
    else
    {
        l_mbacalfir_action0.clearBit<9>();
        l_mbacalfir_action1.setBit<9>();
        l_mbacalfir_mask_or.setBit<9>();
    }

    // 10   mba_wrd ce                  recoverable         mask (until mainline traffic)
    l_mbacalfir_action0.clearBit<10>();
    l_mbacalfir_action1.setBit<10>();
    l_mbacalfir_mask_or.setBit<10>();

    // 11   mba_maint ue                recoverable         mask (until after draminit_training_adv)
    //      hw414700                    channel checkstop   mask (until after draminit_training_adv)
    if (l_hw414700)
    {
        l_mbacalfir_action0.clearBit<11>();
        l_mbacalfir_action1.clearBit<11>();
        l_mbacalfir_mask_or.setBit<11>();
    }
    else
    {
        l_mbacalfir_action0.clearBit<11>();
        l_mbacalfir_action1.setBit<11>();
        l_mbacalfir_mask_or.setBit<11>();
    }

    // 12   mba_maint ce                recoverable         mask (until after draminit_training_adv)
    l_mbacalfir_action0.clearBit<12>();
    l_mbacalfir_action1.setBit<12>();
    l_mbacalfir_mask_or.setBit<12>();

    // 13   ddr_cal_reset_timeout       channel checkstop   unmask
    l_mbacalfir_action0.clearBit<13>();
    l_mbacalfir_action1.clearBit<13>();
    l_mbacalfir_mask_and.clearBit<13>();

    // 14   wrq_data_ce                 recoverable         mask (until mainline traffic)
    l_mbacalfir_action0.clearBit<14>();
    l_mbacalfir_action1.setBit<14>();
    l_mbacalfir_mask_or.setBit<14>();

    // 15   wrq_data_ue                 recoverable         mask (until mainline traffic)
    //      hw414700                    channel checkstop   mask (until mainline traffic)
    if (l_hw414700)
    {
        l_mbacalfir_action0.clearBit<15>();
        l_mbacalfir_action1.clearBit<15>();
        l_mbacalfir_mask_or.setBit<15>();
    }
    else
    {
        l_mbacalfir_action0.clearBit<15>();
        l_mbacalfir_action1.setBit<15>();
        l_mbacalfir_mask_or.setBit<15>();
    }

    // 16   wrq_data_sue                recoverable         mask (forever)
    l_mbacalfir_action0.clearBit<16>();
    l_mbacalfir_action1.setBit<16>();
    l_mbacalfir_mask_or.setBit<16>();

    // 17   wrq_rrq_hang_err            recoverable         mask (until after draminit_training_adv)
    l_mbacalfir_action0.clearBit<17>();
    l_mbacalfir_action1.setBit<17>();
    l_mbacalfir_mask_or.setBit<17>();

    // 18   sm_1hot_err                 channel checkstop   unmask
    l_mbacalfir_action0.clearBit<18>();
    l_mbacalfir_action1.clearBit<18>();
    l_mbacalfir_mask_and.clearBit<18>();

    // 19   wrd_scom_error              recoverable         unmask
    l_mbacalfir_action0.clearBit<19>();
    l_mbacalfir_action1.setBit<19>();
    l_mbacalfir_mask_and.clearBit<19>();

    if (l_dd2_fir_bit_defn_changes)
    {
        // 20   rhmr_prim_reached_max       recoverable         mask (forever)
        l_mbacalfir_action0.clearBit<20>();
        l_mbacalfir_action1.setBit<20>();
        l_mbacalfir_mask_or.setBit<20>();

        // 21   rhmr_sec_reached_max        recoverable         mask (forever)
        l_mbacalfir_action0.clearBit<21>();
        l_mbacalfir_action1.setBit<21>();
        l_mbacalfir_mask_or.setBit<21>();

        // 22   rhmr_sec_already_full       recoverable         mask (forever)
        l_mbacalfir_action0.clearBit<22>();
        l_mbacalfir_action1.setBit<22>();
        l_mbacalfir_mask_or.setBit<22>();

        // 23   Reserved                    recoverable         mask (forever)
        l_mbacalfir_action0.clearBit<23>();
        l_mbacalfir_action1.setBit<23>();
        l_mbacalfir_mask_or.setBit<23>();

        // 24   internal_scom_error         recoverable         unmask
        l_mbacalfir_action0.clearBit<24>();
        l_mbacalfir_action1.setBit<24>();
        l_mbacalfir_mask_and.clearBit<24>();

        // 25   internal_scom_error_copy    recoverable         unmask
        l_mbacalfir_action0.clearBit<25>();
        l_mbacalfir_action1.setBit<25>();
        l_mbacalfir_mask_and.clearBit<25>();

        // 26-63    Reserved            not implemented, so won't touch these
    }
    else
    {
        // 20   internal_scom_error         recoverable         unmask
        l_mbacalfir_action0.clearBit<20>();
        l_mbacalfir_action1.setBit<20>();
        l_mbacalfir_mask_and.clearBit<20>();

        // 21   internal_scom_error_copy    recoverable         unmask
        l_mbacalfir_action0.clearBit<21>();
        l_mbacalfir_action1.setBit<21>();
        l_mbacalfir_mask_and.clearBit<21>();

        // 22-63    Reserved            not implemented, so won't touch these
    }


    // Write action0
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_ACTION0, l_mbacalfir_action0));

    // Write action1
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_ACTION1, l_mbacalfir_action1));

    // Write mask OR
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_MASK_WO_OR, l_mbacalfir_mask_or));

    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_MASK_WO_AND, l_mbacalfir_mask_and));

    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIR_ACTION0, l_mbacalfir_action0));
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIR_ACTION1, l_mbacalfir_action1));
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIR_MASK, l_mbacalfir_mask));

    //************************************************

fapi_try_exit:
    FAPI_INF("EXIT mss_unmask_draminit_errors()");
    return fapi2::current_err;
}

///
/// @brief Unmasks MBACALFIR errors that are valid for PRD to handle after mss_draminit_training
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit_training.C.
///
fapi2::ReturnCode mss_unmask_draminit_training_errors(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
{
    FAPI_INF("ENTER mss_unmask_draminit_training_errors()");

    //*************************
    //*************************
    // MBACALFIR
    //*************************
    //*************************

    fapi2::buffer<uint64_t> l_mbacalfir_mask;
    fapi2::buffer<uint64_t> l_mbacalfir_mask_and;

    // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
    // called, which has already set the MBACALFIR action regs to their runtime
    // values, so no need to touch the action regs here.

    // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
    // called, which has already unmasked the approproiate MBACALFIR errors
    // following mss_draminit. So all we will do here is unmask a few more
    // errors that would be considered valid after the mss_draminit_training
    // procedure.

    // Read mask
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIR_MASK, l_mbacalfir_mask));

    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_mbacalfir_mask_and.flush<1>();

    // 0    MBA Recoverable Error       recoverable         umask
    FAPI_TRY(l_mbacalfir_mask_and.clearBit(0));

    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_MASK_WO_AND, l_mbacalfir_mask_and));

    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIR_MASK, l_mbacalfir_mask));

    //************************************************

fapi_try_exit:
    FAPI_INF("EXIT mss_unmask_draminit_training_errors()");
    return fapi2::current_err;
}

///
/// @brief Unmasks MBACALFIR errors that are valid for PRD to handle after mss_draminit_training_advanced
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit_training_advanced.C.
///
fapi2::ReturnCode mss_unmask_draminit_training_advanced_errors(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target)
{
    FAPI_INF("ENTER mss_unmask_draminit_training_advanced_errors()");

    //*************************
    //*************************
    // MBACALFIR
    //*************************
    //*************************

    fapi2::buffer<uint64_t> l_mbacalfir_mask;
    fapi2::buffer<uint64_t> l_mbacalfir_mask_and;
    fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> l_targetCentaur;
    uint8_t l_mbaPosition = 0;             // 0 = mba01, 1 = mba23

    constexpr uint32_t l_mbsfir_mask_address[] =
    {
        // port0/1                       port2/3
        CEN_MCBISTS01_MBSFIRMASK,     CEN_MCBISTS23_MBSFIRMASK
    };

    constexpr uint32_t l_mbsfir_mask_or_address[] =
    {
        // port0/1                       port2/3
        CEN_MCBISTS01_MBSFIRMASK_WO_OR,  CEN_MCBISTS23_MBSFIRMASK_WO_OR
    };

    constexpr uint32_t l_mbsfir_mask_and_address[] =
    {
        // port0/1                       port2/3
        CEN_MCBISTS01_MBSFIRMASK_WO_AND, CEN_MCBISTS23_MBSFIRMASK_WO_AND
    };

    constexpr uint32_t l_mbsfir_action0_address[] =
    {
        // port0/1                       port2/3
        CEN_MCBISTS01_MBSFIRACT0,     CEN_MCBISTS23_MBSFIRACT0
    };

    constexpr uint32_t l_mbsfir_action1_address[] =
    {
        // port0/1                       port2/3
        CEN_MCBISTS01_MBSFIRACT1,     CEN_MCBISTS23_MBSFIRACT1
    };

    fapi2::buffer<uint64_t> l_mbsfir_mask;
    fapi2::buffer<uint64_t> l_mbsfir_mask_or;
    fapi2::buffer<uint64_t> l_mbsfir_mask_and;
    fapi2::buffer<uint64_t> l_mbsfir_action0;
    fapi2::buffer<uint64_t> l_mbsfir_action1;

    // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
    // called, which has already set the MBACALFIR action regs to their runtime
    // values, so no need to touch the action regs here.

    // NOTE: In the IPL sequence, mss_unmask_draminit_errors and
    // mss_unmask_draminit_training has already been
    // called, which has already unmasked the approproiate MBACALFIR errors
    // following mss_draminit and mss_draminit_training. So all we will do here
    // is unmask a few more errors that would be considered valid after the
    // mss_draminit_training_advanced procedure.

    // Read mask
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIR_MASK, l_mbacalfir_mask));


    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_mbacalfir_mask_and.flush<1>();

    // 8    mbx to mba par error        channel checkstop   unmask
    l_mbacalfir_mask_and.clearBit<8>();

    // 11   mba_maint ue                recoverable         unmask
    l_mbacalfir_mask_and.clearBit<11>();

    // 12   mba_maint ce                recoverable         unmask
    l_mbacalfir_mask_and.clearBit<12>();

    // 17   wrq_rrq_hang_err            recoverable         unmask
    l_mbacalfir_mask_and.clearBit<17>();


    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBA_MBACALFIR_MASK_WO_AND, l_mbacalfir_mask_and));

    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBA_MBACALFIR_MASK, l_mbacalfir_mask));

    //************************************************

    //*************************
    //*************************
    // MBSFIR
    //*************************
    //*************************

    // Get Centaur target for the given MBA
    l_targetCentaur = i_target.getParent<fapi2::TARGET_TYPE_MEMBUF_CHIP>();
    // Get MBA position: 0 = mba01, 1 = mba23
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_mbaPosition), "Error getting MBA position");

    // Read mask
    FAPI_TRY(fapi2::getScom(l_targetCentaur,
                            l_mbsfir_mask_address[l_mbaPosition],
                            l_mbsfir_mask));

    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_mbsfir_action0.flush<0>();
    l_mbsfir_action1.flush<0>();
    l_mbsfir_mask_or.flush<0>();
    l_mbsfir_mask_and.flush<1>();

    // 0    scom_par_errors             channel checkstop   unmask
    l_mbsfir_action0.clearBit<0>();
    l_mbsfir_action1.clearBit<0>();
    l_mbsfir_mask_and.clearBit<0>();

    // 1    mbx_par_errors              channel checkstop   unmask
    l_mbsfir_action0.clearBit<1>();
    l_mbsfir_action1.clearBit<1>();
    l_mbsfir_mask_and.clearBit<1>();

    // 2    DD1: reserved               recoverable         mask (forever)
    // 2    DD2: dram_eventn_bit0       recoverable         mask (forever)
    l_mbsfir_action0.clearBit<2>();
    l_mbsfir_action1.setBit<2>();
    l_mbsfir_mask_or.setBit<2>();

    // 3    DD1: reserved               recoverable         mask (forever)
    // 3    DD2: dram_eventn_bit1       recoverable         mask (forever)
    l_mbsfir_action0.clearBit<3>();
    l_mbsfir_action1.setBit<3>();
    l_mbsfir_mask_or.setBit<3>();

    // 4:14 RESERVED                    recoverable         mask (forever)
    l_mbsfir_action0.clearBit<4, 11>();
    l_mbsfir_action1.setBit<4, 11>();
    l_mbsfir_mask_or.setBit<4, 11>();

    // 2:14 RESERVED                    recoverable         mask (forever)
    l_mbsfir_action0.clearBit<2, 13>();
    l_mbsfir_action1.setBit<2, 13>();
    l_mbsfir_mask_or.setBit<2, 13>();

    // 15   internal scom error         recoverable         unmask
    l_mbsfir_action0.clearBit<15>();
    l_mbsfir_action1.setBit<15>();
    l_mbsfir_mask_and.clearBit<15>();

    // 16   internal scom error clone   recoverable         unmask
    l_mbsfir_action0.clearBit<16>();
    l_mbsfir_action1.setBit<16>();
    l_mbsfir_mask_and.clearBit<16>();

    // 17:63 RESERVED           not implemented, so won't touch these

    // Write action0
    FAPI_TRY(fapi2::putScom(l_targetCentaur,
                            l_mbsfir_action0_address[l_mbaPosition],
                            l_mbsfir_action0));

    // Write action1
    FAPI_TRY(fapi2::putScom(l_targetCentaur,
                            l_mbsfir_action1_address[l_mbaPosition],
                            l_mbsfir_action1));

    // Write mask OR
    FAPI_TRY(fapi2::putScom(l_targetCentaur,
                            l_mbsfir_mask_or_address[l_mbaPosition],
                            l_mbsfir_mask_or));

    // Write mask AND
    FAPI_TRY(fapi2::putScom(l_targetCentaur,
                            l_mbsfir_mask_and_address[l_mbaPosition],
                            l_mbsfir_mask_and));

    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(l_targetCentaur,
                            l_mbsfir_action0_address[l_mbaPosition],
                            l_mbsfir_action0));

    FAPI_TRY(fapi2::getScom(l_targetCentaur,
                            l_mbsfir_action1_address[l_mbaPosition],
                            l_mbsfir_action1));

    FAPI_TRY(fapi2::getScom(l_targetCentaur,
                            l_mbsfir_mask_address[l_mbaPosition],
                            l_mbsfir_mask));

    //************************************************

fapi_try_exit:
    FAPI_INF("EXIT mss_unmask_draminit_training_advanced_errors()");
    return fapi2::current_err;

}

///
/// @brief Sets action regs and unmasks maint errors prior to the maint logic
///         Being used in memdiags so that PRD will be able to handle them
///         if they happen during memdiags.
/// @param[in]  i_target MBA target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit_mc.C.
///
fapi2::ReturnCode mss_unmask_maint_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_INF("ENTER mss_unmask_maint_errors()");

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MBA>> l_mbaChiplets;
    uint8_t l_mbaPosition = 0;             // 0 = mba01, 1 = mba23

    fapi2::buffer<uint64_t> l_mbacalfir_mask;
    fapi2::buffer<uint64_t> l_mbacalfir_mask_and;

    fapi2::buffer<uint64_t> l_mbafir_mask;
    fapi2::buffer<uint64_t> l_mbafir_mask_and;

    fapi2::buffer<uint64_t> l_mbaspa_mask;

    constexpr uint32_t l_mbeccfir_mask_address[] =
    {
        // port0/1                            port2/3
        CEN_ECC01_MBECCFIR_MASK,   CEN_ECC23_MBECCFIR_MASK
    };

    constexpr uint32_t l_mbeccfir_mask_or_address[] =
    {
        // port0/1                            port2/3
        CEN_ECC01_MBECCFIR_MASK_WO_OR, CEN_ECC23_MBECCFIR_MASK_WO_OR
    };

    constexpr uint32_t l_mbeccfir_mask_and_address[] =
    {
        // port0/1                            port2/3
        CEN_ECC01_MBECCFIR_MASK_WO_AND, CEN_ECC23_MBECCFIR_MASK_WO_AND
    };

    constexpr uint32_t l_mbeccfir_action0_address[] =
    {
        // port0/1                            port2/3
        CEN_ECC01_MBECCFIR_ACTION0_RO, CEN_ECC23_MBECCFIR_ACTION0_RO
    };

    constexpr uint32_t l_mbeccfir_action1_address[] =
    {
        // port0/1                            port2/3
        CEN_ECC01_MBECCFIR_ACTION1_RO, CEN_ECC23_MBECCFIR_ACTION1_RO
    };

    fapi2::buffer<uint64_t> l_mbeccfir_mask;
    fapi2::buffer<uint64_t> l_mbeccfir_mask_or;
    fapi2::buffer<uint64_t> l_mbeccfir_mask_and;
    fapi2::buffer<uint64_t> l_mbeccfir_action0;
    fapi2::buffer<uint64_t> l_mbeccfir_action1;

    uint8_t l_mbspa_0_fixed_for_dd2 = 0;
    uint8_t l_hw414700 = 0;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> l_attached_dmi_target = i_target.getParent<fapi2::TARGET_TYPE_DMI>();
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_attached_proc_target =
        l_attached_dmi_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Get attribute for HW414700 workaround
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, l_attached_proc_target, l_hw414700),
             "Error getting ATTR_CHIP_EC_FEATURE_HW414700");

    // Get attribute that tells us if mbspa 0 cmd complete attention is fixed for dd2
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_HW217608_MBSPA_0_CMD_COMPLETE_ATTN_FIXED, i_target,
                           l_mbspa_0_fixed_for_dd2), "Error getting ATTR_CEN_CENTAUR_EC_FEATURE_HW217608_MBSPA_0_CMD_COMPLETE_ATTN_FIXED");

    // Get associated functional MBAs on this centaur
    l_mbaChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MBA>();

    // Loop through functional MBAs on this Centaur
    for (uint32_t i = 0; i < l_mbaChiplets.size(); ++i)
    {

        // Get MBA position: 0 = mba01, 1 = mba23
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mbaChiplets[i], l_mbaPosition), "Error getting MBA position");

        //*************************
        //*************************
        // MBACALFIR
        //*************************
        //*************************

        // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
        // called, which has already set the MBACALFIR action regs to their runtime
        // values, so no need to touch the action regs here.

        // NOTE: In the IPL sequence, mss_unmask_draminit_errors,
        // mss_unmask_draminit_training and mss_unmask_draminit_training_advanced
        // have already been called, which have already unmasked the approproiate
        // MBACALFIR errors following mss_draminit, mss_draminit_training, and
        // mss_unmask_draminit_training_advanced. So all we will do here
        // is unmask a few more errors that would be considered valid after the
        // mss_draminit_mc procedure.

        // Read mask
        FAPI_TRY(fapi2::getScom(l_mbaChiplets[i],
                                CEN_MBA_MBACALFIR_MASK,
                                l_mbacalfir_mask));

        //(Action0, Action1, Mask)
        //
        // (0,0,0) = checkstop
        // (0,1,0) = recoverable error
        // (1,0,0) = report unused
        // (1,1,0) = machine check
        // (x,x,1) = error is masked

        l_mbacalfir_mask_and.flush<1>();

        // 1    MBA Nonrecoverable Error    channel checkstop   unmask
        l_mbacalfir_mask_and.clearBit<1>();

        // 2    Refresh Overrun             recoverable         unmask
        l_mbacalfir_mask_and.clearBit<2>();

        // 5    ddr0_cal_timeout_err        recoverable         unmask
        l_mbacalfir_mask_and.clearBit<5>();

        // 6    ddr1_cal_timeout_err        recoverable         unmask
        l_mbacalfir_mask_and.clearBit<6>();

        // Write mask AND
        FAPI_TRY(fapi2::putScom(l_mbaChiplets[i],
                                CEN_MBA_MBACALFIR_MASK_WO_AND,
                                l_mbacalfir_mask_and));

        //************************************************
        // DEBUG: read them all back to verify
        FAPI_TRY(fapi2::getScom(l_mbaChiplets[i],
                                CEN_MBA_MBACALFIR_MASK,
                                l_mbacalfir_mask));

        //************************************************


        //*************************
        //*************************
        // MBAFIR
        //*************************
        //*************************

        // NOTE: In the IPL sequence, mss_unmask_ddr_phy_errors has already been
        // called, which has already set the MBAFIR action regs to their runtime
        // values, so no need to touch the action regs here.

        // NOTE: In the IPL sequence, mss_unmask_ddr_phy_errors,
        // has already been called, which has already unmasked the approproiate
        // MBAFIR errors following mss_ddr_phy_reset. So all we will do here
        // is unmask a few more errors that would be considered valid after the
        // mss_draminit_mc procedure.

        // Read mask
        FAPI_TRY(fapi2::getScom(l_mbaChiplets[i],
                                CEN_MBA_MBAFIRMASK,
                                l_mbafir_mask));

        //
        // (0,0,0) = checkstop
        // (0,1,0) = recoverable error
        // (1,0,0) = report unused
        // (1,1,0) = machine check
        // (x,x,1) = error is masked

        l_mbafir_mask_and.flush<1>();

        // 2    Multi_address_Maint_timeout recoverable         unmask
        l_mbafir_mask_and.clearBit<2>();


        // 7    wrd_caw2_data_ce_ue_err     channel checkstop   unmask
        l_mbafir_mask_and.clearBit<7>();

        // Write mask AND
        FAPI_TRY(fapi2::putScom(l_mbaChiplets[i],
                                CEN_MBA_MBAFIRMASK_WO_AND,
                                l_mbafir_mask_and));

        //************************************************
        // DEBUG: read them all back to verify
        FAPI_TRY(fapi2::getScom(l_mbaChiplets[i],
                                CEN_MBA_MBAFIRMASK,
                                l_mbafir_mask));

        //************************************************

        //*************************
        //*************************
        // MBSPA
        //*************************
        //*************************


        // Read mask
        FAPI_TRY(fapi2::getScom(l_mbaChiplets[i],
                                CEN_MBA_MBSPAMSKQ,
                                l_mbaspa_mask));

        // 0    Command_Complete
        if (l_mbspa_0_fixed_for_dd2)
        {
            l_mbaspa_mask.clearBit<0>();         // DD2: unmask (fixed)
        }
        else
        {
            l_mbaspa_mask.setBit<0>();           // DD1: masked (broken)
        }

        // 1    Hard_CE_ETE_Attn                             mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the
        // cmd complete attention, then checking these manually to see if
        // they cause the cmd to stop
        // NOTE: Hards counted during super fast read, but can't be called
        // true hard CEs since super fast read doesn't write back and read again.
        l_mbaspa_mask.setBit<1>();
        // 2    Soft_CE_ETE_Attn                             mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the
        // cmd complete attention, then checking these manually to see if
        // they cause the cmd to stop
        // NOTE: Softs not counted during super fast read.
        l_mbaspa_mask.setBit<2>();

        // 3    Intermittent_ETE_Attn                        mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the
        // cmd complete attention, then checking these manually to see if
        // they cause the cmd to stop
        // NOTE: Intermittents not counted during super fast read.
        l_mbaspa_mask.setBit<3>();

        // 4    RCE_ETE_Attn                                 mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the
        // cmd complete attention, then checking these manually to see if
        // they cause the cmd to stop
        // NOTE: RCEs not counted during super fast read.
        l_mbaspa_mask.setBit<4>();

        // 5    Emergency_Throttle_Attn                      masked (forever)
        l_mbaspa_mask.setBit<5>();

        // 6    Firmware_Attn0                               masked (forever)
        l_mbaspa_mask.setBit<6>();

        // 7    Firmware_Attn1                               masked (forever)
        l_mbaspa_mask.setBit<7>();

        // 8    wat_debug_attn
        if (l_mbspa_0_fixed_for_dd2)
        {
            l_mbaspa_mask.setBit<8>();           // DD2: masked (workaround for mbspa 0 not needed)
        }
        else
        {
            l_mbaspa_mask.clearBit<8>();         // DD1: unmasked (workaround for mbspa 0 needed)
        }

        // 9    Spare_Attn1                                  masked (forever)
        l_mbaspa_mask.setBit<9>();

        // 10   MCBIST_Done                                  masked (forever)
        l_mbaspa_mask.setBit<10>();

        // 11:63 RESERVED     not implemented, so won't touch these


        // Write mask
        FAPI_TRY(fapi2::putScom(l_mbaChiplets[i],
                                CEN_MBA_MBSPAMSKQ,
                                l_mbaspa_mask));

        // DEBUG: read them all back to verify
        FAPI_TRY(fapi2::getScom(l_mbaChiplets[i],
                                CEN_MBA_MBSPAMSKQ,
                                l_mbaspa_mask));

        //*************************
        //*************************
        // MBECCFIR
        //*************************
        //*************************

        // Read mask
        FAPI_TRY(fapi2::getScom(i_target,
                                l_mbeccfir_mask_address[l_mbaPosition],
                                l_mbeccfir_mask));



        l_mbeccfir_action0.flush<0>();
        l_mbeccfir_action1.flush<0>();
        l_mbeccfir_mask_or.flush<0>();
        l_mbeccfir_mask_and.flush<1>();

        // 0:7  Memory MPE Rank 0:7         recoverable         mask (until mainline traffic)
        l_mbeccfir_action0.clearBit<0, 8>();
        l_mbeccfir_action1.setBit<0, 8>();
        l_mbeccfir_mask_or.setBit<0, 8>();

        // 8:15 Reserved                    recoverable         mask (forever)
        l_mbeccfir_action0.clearBit<8, 8>();
        l_mbeccfir_action1.setBit<8, 8>();
        l_mbeccfir_mask_or.setBit<8, 8>();

        // 16   Memory NCE                  recoverable         mask (until mainline traffic)
        l_mbeccfir_action0.clearBit<16>();
        l_mbeccfir_action1.setBit<16>();
        l_mbeccfir_mask_or.setBit<16>();

        // 17   Memory RCE                  recoverable         mask (until mainline traffic)
        l_mbeccfir_action0.clearBit<17>();
        l_mbeccfir_action1.setBit<17>();

        l_mbeccfir_mask_or.setBit<17>();

        // 18   Memory SUE                  recoverable         mask (forever)
        l_mbeccfir_action0.clearBit<18>();
        l_mbeccfir_action1.setBit<18>();
        l_mbeccfir_mask_or.setBit<18>();

        // 19   Memory UE                   recoverable         mask (until mainline traffic)
        //      hw414700                    channel checkstop   mask (until mainline traffic)

        if (l_hw414700)
        {
            l_mbeccfir_action0.clearBit<19>();
            l_mbeccfir_action1.clearBit<19>();
            l_mbeccfir_mask_or.setBit<19>();
        }
        else
        {
            l_mbeccfir_action0.clearBit<19>();
            l_mbeccfir_action1.setBit<19>();
            l_mbeccfir_mask_or.setBit<19>();
        }

        // 20:27    Maint MPE Rank 0:7      recoverable         mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the
        // cmd complete attention, then checking these manually to see if
        // they cause the cmd to stop
        l_mbeccfir_action0.clearBit<20, 8>();
        l_mbeccfir_action1.setBit<20, 8>();
        l_mbeccfir_mask_or.setBit<20, 8>();

        // 28:35    Reserved                recoverable         mask (forever)
        l_mbeccfir_action0.clearBit<28, 8>();
        l_mbeccfir_action1.setBit<28, 8>();
        l_mbeccfir_mask_or.setBit<28, 8>();

        // 36   Maintenance NCE             recoverable         mask (forever)
        // NOTE: PRD planning to use maint CE thresholds instead.
        l_mbeccfir_action0.clearBit<36>();
        l_mbeccfir_action1.setBit<36>();
        l_mbeccfir_mask_or.setBit<36>();

        // 37   Maintenance SCE             recoverable         mask (forever)
        // NOTE: Don't care if symbol still bad after it's symbol marked.
        l_mbeccfir_action0.clearBit<37>();
        l_mbeccfir_action1.setBit<37>();
        l_mbeccfir_mask_or.setBit<37>();

        // 38   Maintenance MCE             recoverable         mask (forever)
        // NOTE: PRD plans to check manually as part of verify chip mark procedure.
        l_mbeccfir_action0.clearBit<38>();
        l_mbeccfir_action1.setBit<38>();
        l_mbeccfir_mask_or.setBit<38>();

        // 39   Maintenance RCE             recoverable         mask (forever)
        // NOTE: PRD planning to use maint RCE thresholds instead.
        l_mbeccfir_action0.clearBit<39>();
        l_mbeccfir_action1.setBit<39>();
        l_mbeccfir_mask_or.setBit<39>();

        // 40   Maintenance SUE             recoverable         mask (forever)
        l_mbeccfir_action0.clearBit<40>();
        l_mbeccfir_action1.setBit<40>();
        l_mbeccfir_mask_or.setBit<40>();

        // 41   Maintenance UE              recoverable         mask (forever)
        // NOTE: FW wants to mask these and rely instead on detecting the
        // cmd complete attention, then checking these manually to see if
        // they cause the cmd to stop
        l_mbeccfir_action0.clearBit<41>();
        l_mbeccfir_action1.setBit<41>();
        l_mbeccfir_mask_or.setBit<41>();

        // 42   MPE during maintenance mark mode  recoverable   mask (forever)
        l_mbeccfir_action0.clearBit<42>();
        l_mbeccfir_action1.setBit<42>();
        l_mbeccfir_mask_or.setBit<42>();

        // 43   Prefetch Memory UE          recoverable         mask (until mainline traffic)
        l_mbeccfir_action0.clearBit<43>();
        l_mbeccfir_action1.setBit<43>();
        l_mbeccfir_mask_or.setBit<43>();

        // 44   Memory RCD parity error     recoverable         mask (forever)
        //      hw414700                    channel checkstop   mask (until mainline traffic)
        if (l_hw414700)
        {
            l_mbeccfir_action0.clearBit<44>();
            l_mbeccfir_action1.clearBit<44>();
            l_mbeccfir_mask_or.setBit<44>();
        }
        else
        {
            l_mbeccfir_action0.clearBit<44>();
            l_mbeccfir_action1.setBit<44>();
            l_mbeccfir_mask_or.setBit<44>();
        }

        // 45   Maint RCD parity error.     recoverable         mask (forever)
        l_mbeccfir_action0.clearBit<45>();
        l_mbeccfir_action1.setBit<45>();
        l_mbeccfir_mask_or.setBit<45>();

        // 46   Recoverable reg parity      recoverable         unmask
        l_mbeccfir_action0.clearBit<46>();
        l_mbeccfir_action1.setBit<46>();
        l_mbeccfir_mask_and.clearBit<46>();


        // 47   Unrecoverable reg parity    channel checkstop   unmask
        l_mbeccfir_action0.clearBit<47>();
        l_mbeccfir_action1.clearBit<47>();
        l_mbeccfir_mask_and.clearBit<47>();

        // 48   Maskable reg parity error   recoverable         unmask
        l_mbeccfir_action0.clearBit<48>();
        l_mbeccfir_action1.setBit<48>();
        l_mbeccfir_mask_and.clearBit<48>();

        // 49   ecc datapath parity error   channel checkstop   unmask
        l_mbeccfir_action0.clearBit<49>();
        l_mbeccfir_action1.clearBit<49>();
        l_mbeccfir_mask_and.clearBit<49>();

        // 50   internal scom error         recovereble         unmask
        l_mbeccfir_action0.clearBit<50>();
        l_mbeccfir_action1.setBit<50>();
        l_mbeccfir_mask_and.clearBit<50>();

        // 51   internal scom error clone   recovereble         unmask
        l_mbeccfir_action0.clearBit<51>();
        l_mbeccfir_action1.setBit<51>();
        l_mbeccfir_mask_and.clearBit<51>();

        // 52:63    Reserved    not implemented, so won't touch these

        // Write action0
        FAPI_TRY(fapi2::putScom(i_target,
                                l_mbeccfir_action0_address[l_mbaPosition],
                                l_mbeccfir_action0));

        // Write action1
        FAPI_TRY(fapi2::putScom(i_target,
                                l_mbeccfir_action1_address[l_mbaPosition],
                                l_mbeccfir_action1));


        // Write mask OR
        FAPI_TRY(fapi2::putScom(i_target,
                                l_mbeccfir_mask_or_address[l_mbaPosition],
                                l_mbeccfir_mask_or));

        // Write mask AND
        FAPI_TRY(fapi2::putScom(i_target,
                                l_mbeccfir_mask_and_address[l_mbaPosition],
                                l_mbeccfir_mask_and));


        //************************************************
        // DEBUG: read them all back to verify
        FAPI_TRY(fapi2::getScom(i_target,
                                l_mbeccfir_action0_address[l_mbaPosition],
                                l_mbeccfir_action0));

        FAPI_TRY(fapi2::getScom(i_target,
                                l_mbeccfir_action1_address[l_mbaPosition],
                                l_mbeccfir_action1));

        FAPI_TRY(fapi2::getScom(i_target,
                                l_mbeccfir_mask_address[l_mbaPosition],
                                l_mbeccfir_mask));

        //************************************************

    } // End for loop through functional MBAs on this Centaur

    FAPI_INF("EXIT mss_unmask_maint_errors()");
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets action regs and unmasks fetch errors prior to the start of mainline traffic.
/// @param[in] i_target Centaur target
/// @return FAPI2_RC_SUCCESS iff okay
/// @note To be called at the end of mss_draminit_mc.C.
///
fapi2::ReturnCode mss_unmask_fetch_errors(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_INF("ENTER mss_unmask_fetch_errors()");

    uint8_t l_dimm_type = 0;
    uint8_t l_cfg_wrdone_dly = 0;
    uint8_t l_cfg_rdtag_dly = 0;
    uint8_t l_max_cfg_rcd_protection_time = 0;

    fapi2::buffer<uint64_t> l_mba_dsm0;
    fapi2::buffer<uint64_t> l_mba_farb0;

    uint8_t l_hw414700 = 0;

    fapi2::Target<fapi2::TARGET_TYPE_DMI> l_attached_dmi_target = i_target.getParent<fapi2::TARGET_TYPE_DMI>();
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_attached_proc_target =
        l_attached_dmi_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    //*************************
    //*************************
    // SCAC_LFIR
    //*************************
    //*************************

    fapi2::buffer<uint64_t> l_scac_lfir_mask;
    fapi2::buffer<uint64_t> l_scac_lfir_mask_or;
    fapi2::buffer<uint64_t> l_scac_lfir_mask_and;
    fapi2::buffer<uint64_t> l_scac_lfir_action0;
    fapi2::buffer<uint64_t> l_scac_lfir_action1;
    fapi2::buffer<uint64_t> l_mbs_fir_mask;
    fapi2::buffer<uint64_t> l_mbs_fir_mask_and;
    uint8_t l_dd2_fir_bit_defn_changes = 0;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_L4>> l_L4_vector;
    bool l_L4_functional = false;
    uint8_t l_mbaPosition = 0;             // 0 = mba01, 1 = mba23
    uint32_t l_mbeccfir_mask_address[] =
    {
        // port0/1                            port2/3
        CEN_ECC01_MBECCFIR_MASK, CEN_ECC23_MBECCFIR_MASK
    };

    uint32_t l_mbeccfir_mask_and_address[] =
    {
        // port0/1                            port2/3
        CEN_ECC01_MBECCFIR_MASK_WO_AND, CEN_ECC23_MBECCFIR_MASK_WO_AND
    };

    fapi2::buffer<uint64_t> l_mbeccfir_mask;
    fapi2::buffer<uint64_t> l_mbeccfir_mask_and;
    fapi2::buffer<uint64_t> l_mbacalfir_mask;
    fapi2::buffer<uint64_t> l_mbacalfir_mask_and;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_MBA>> l_mbaChiplets;

    // Read mask
    FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_FIRMASK, l_scac_lfir_mask));



    //(Action0, Action1, Mask)
    //
    // (0,0,0) = checkstop
    // (0,1,0) = recoverable error
    // (1,0,0) = report unused
    // (1,1,0) = machine check
    // (x,x,1) = error is masked

    l_scac_lfir_action0.flush<0>();
    l_scac_lfir_action1.flush<0>();
    l_scac_lfir_mask_or.flush<0>();
    l_scac_lfir_mask_and.flush<1>();

    // 0    I2CMInvAddr                 recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<0>();
    l_scac_lfir_action1.setBit<0>();
    l_scac_lfir_mask_or.setBit<0>();

    // 1    I2CMInvWrite                recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<1>();
    l_scac_lfir_action1.setBit<1>();
    l_scac_lfir_mask_or.setBit<1>();

    // 2    I2CMInvRead                 recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<2>();
    l_scac_lfir_action1.setBit<2>();
    l_scac_lfir_mask_or.setBit<2>();

    // 3    I2CMApar                    recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<3>();
    l_scac_lfir_action1.setBit<3>();
    l_scac_lfir_mask_or.setBit<3>();

    // 4    I2CMPar                     recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<4>();
    l_scac_lfir_action1.setBit<4>();
    l_scac_lfir_mask_or.setBit<4>();

    // 5    I2CMLBPar                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<5>();
    l_scac_lfir_action1.setBit<5>();
    l_scac_lfir_mask_or.setBit<5>();

    // 6:9  Expansion                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<6, 4>();
    l_scac_lfir_action1.setBit<6, 4>();
    l_scac_lfir_mask_or.setBit<6, 4>();

    // 10   I2CMInvCmd                  recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<10>();
    l_scac_lfir_action1.setBit<10>();
    l_scac_lfir_mask_or.setBit<10>();

    // 11   I2CMPErr                    recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<11>();
    l_scac_lfir_action1.setBit<11>();
    l_scac_lfir_mask_or.setBit<11>();

    // 12   I2CMOverrun                 recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<12>();
    l_scac_lfir_action1.setBit<12>();
    l_scac_lfir_mask_or.setBit<12>();

    // 13   I2CMAccess                  recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<13>();
    l_scac_lfir_action1.setBit<13>();
    l_scac_lfir_mask_or.setBit<13>();

    // 14   I2CMArb                     recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<14>();
    l_scac_lfir_action1.setBit<14>();
    l_scac_lfir_mask_or.setBit<14>();

    // 15   I2CMNack                    recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<15>();
    l_scac_lfir_action1.setBit<15>();
    l_scac_lfir_mask_or.setBit<15>();

    // 16   I2CMStop                    recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<16>();
    l_scac_lfir_action1.setBit<16>();
    l_scac_lfir_mask_or.setBit<16>();

    // 17   LocalPib1                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<17>();
    l_scac_lfir_action1.setBit<17>();
    l_scac_lfir_mask_or.setBit<17>();

    // 18   LocalPib2                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<18>();
    l_scac_lfir_action1.setBit<18>();
    l_scac_lfir_mask_or.setBit<18>();

    // 19   LocalPib3                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<19>();
    l_scac_lfir_action1.setBit<19>();
    l_scac_lfir_mask_or.setBit<19>();

    // 20   LocalPib4                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<20>();
    l_scac_lfir_action1.setBit<20>();
    l_scac_lfir_mask_or.setBit<20>();

    // 21   LocalPib5                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<21>();
    l_scac_lfir_action1.setBit<21>();
    l_scac_lfir_mask_or.setBit<21>();

    // 22   LocalPib6                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<22>();
    l_scac_lfir_action1.setBit<22>();
    l_scac_lfir_mask_or.setBit<22>();

    // 23   LocalPib7                   recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<23>();
    l_scac_lfir_action1.setBit<23>();
    l_scac_lfir_mask_or.setBit<23>();

    // 24   StallError                  recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<24>();
    l_scac_lfir_action1.setBit<24>();
    l_scac_lfir_mask_or.setBit<24>();

    // 25   RegParErr                   channel checkstop   unmask
    l_scac_lfir_action0.clearBit<25>();
    l_scac_lfir_action1.clearBit<25>();
    l_scac_lfir_mask_and.clearBit<25>();

    // 26   RegParErrX                  channel checkstop   unmask
    l_scac_lfir_action0.clearBit<26>();
    l_scac_lfir_action1.clearBit<26>();
    l_scac_lfir_mask_and.clearBit<26>();

    // 27:31    Reserved                recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<27, 5>();
    l_scac_lfir_action1.setBit<27, 5>();
    l_scac_lfir_mask_or.setBit<27, 5>();

    // 32   SMErr                       recoverable         unmask
    l_scac_lfir_action0.clearBit<32>();
    l_scac_lfir_action1.setBit<32>();
    l_scac_lfir_mask_and.clearBit<32>();

    // 33   RegAccErr                   recoverable         unmask
    l_scac_lfir_action0.clearBit<33>();
    l_scac_lfir_action1.setBit<33>();
    l_scac_lfir_mask_and.clearBit<33>();

    // 34   ResetErr                    recoverable         masked (forever)
    l_scac_lfir_action0.clearBit<34>();
    l_scac_lfir_action1.setBit<34>();
    l_scac_lfir_mask_or.setBit<34>();

    // 35   internal_scom_error         recoverable         unmask
    l_scac_lfir_action0.clearBit<35>();
    l_scac_lfir_action1.setBit<35>();
    l_scac_lfir_mask_and.clearBit<35>();

    // 36   internal_scom_error_clone   recoverable         unmask
    l_scac_lfir_action0.clearBit<36>();
    l_scac_lfir_action1.setBit<36>();
    l_scac_lfir_mask_and.clearBit<36>();

    // 37:63    Reserved
    // Can we write to these bits?

    // Write action0
    FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_FIRACTION0_RO, l_scac_lfir_action0));

    // Write action1
    FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_FIRACTION1_RO, l_scac_lfir_action1));

    // Write mask OR
    FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_FIRMASK_WO_OR, l_scac_lfir_mask_or));

    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target, CEN_SCAC_FIRMASK_WO_AND, l_scac_lfir_mask_and));

    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_FIRACTION0_RO, l_scac_lfir_action0));
    FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_FIRACTION1_RO, l_scac_lfir_action1));
    FAPI_TRY(fapi2::getScom(i_target, CEN_SCAC_FIRMASK, l_scac_lfir_mask));

    //************************************************

    //*************************
    //*************************
    // MBS_FIR_REG
    //*************************
    //*************************

    // NOTE: In the IPL sequence, mss_unmask_inband_errors has already been
    // called, which has already set the MBS_FIR_REG action regs to their
    // runtime values, so no need to touch the action regs here.

    // NOTE: In the IPL sequence, mss_unmask_inband_errors,
    // has already been called, which has already unmasked the approproiate
    // MBS_FIR_REG errors following mss_unmask_inband_errors. So all we will do
    // here is unmask errors requiring mainline traffic which would be
    // considered valid after the mss_thermal_init procedure.

    // Get attribute for HW414700 workaround
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, l_attached_proc_target, l_hw414700),
             "Error getting ATTR_CHIP_EC_FEATURE_HW414700");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_CENTAUR_EC_FEATURE_DD2_FIR_BIT_DEFN_CHANGES, i_target,
                           l_dd2_fir_bit_defn_changes),
             "Error getting ATTR_CEN_CENTAUR_EC_FEATURE_DD2_FIR_BIT_DEFN_CHANGES");

    // Check if L4 is functional
    l_L4_vector = i_target.getChildren<fapi2::TARGET_TYPE_L4>();

    if (l_L4_vector.size() > 0)
    {
        l_L4_functional = true;
    }

    // Read mask
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBS_FIR_MASK_REG, l_mbs_fir_mask));


    l_mbs_fir_mask_and.flush<1>();

    // 2    invalid_address_error   channel checkstop   unmask
    l_mbs_fir_mask_and.clearBit<2>();

    // 3    external_timeout        recoverable         unmask
    l_mbs_fir_mask_and.clearBit<3>();

    // 4    internal_timeout        recoverable         unmask
    l_mbs_fir_mask_and.clearBit<4>();


    if (l_L4_functional)
    {
        // 9    cache_srw_ce            recoverable         unmask
        l_mbs_fir_mask_and.clearBit<9>();

        // 10    cache_srw_ue           recoverable         unmask
        l_mbs_fir_mask_and.clearBit<10>();

        // 12    cache_co_ce            recoverable         unmask
        l_mbs_fir_mask_and.clearBit<12>();

        // 13    cache_co_ue            recoverable         unmask
        l_mbs_fir_mask_and.clearBit<13>();

        // 15    dir_ce
        if (l_dd2_fir_bit_defn_changes)
        {
            // NOTE: SW248520: Known DD1 problem - higher temp causes
            // L4 Dir CEs. Want to ignore. Unmask for DD2 only

            //                          recoverable         unmask
            l_mbs_fir_mask_and.clearBit<15>();
        }

        // 16    dir_ue                 channel checkstop   unmask
        l_mbs_fir_mask_and.clearBit<16>();

        // 18    dir_all_members_deleted channel checkstop  unmask
        l_mbs_fir_mask_and.clearBit<18>();

        // 19    lru_error               recoverable        unmask
        l_mbs_fir_mask_and.clearBit<19>();

        // 20    eDRAM error             channel checkstop  unmask
        l_mbs_fir_mask_and.clearBit<20>();
    }

    // 26    srb_buffer_ce           recoverable        unmask
    l_mbs_fir_mask_and.clearBit<26>();

    // 27    srb_buffer_ue           recoverable        unmask
    l_mbs_fir_mask_and.clearBit<27>();

    if (l_dd2_fir_bit_defn_changes && l_L4_functional)
    {
        // 30    proximal_ce_ue      channel checkstop  unmask
        l_mbs_fir_mask_and.clearBit<30>();
    }


    // Write mask AND
    FAPI_TRY(fapi2::putScom(i_target, CEN_MBS_FIR_MASK_REG_WO_AND, l_mbs_fir_mask_and));


    //************************************************
    // DEBUG: read them all back to verify
    FAPI_TRY(fapi2::getScom(i_target, CEN_MBS_FIR_MASK_REG, l_mbs_fir_mask));

    //************************************************


    // Get associated functional MBAs on this centaur
    l_mbaChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MBA>();

    // Loop through functional MBAs on this Centaur
    for (uint32_t i = 0; i < l_mbaChiplets.size(); ++i)
    {

        // Get MBA position: 0 = mba01, 1 = mba23
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mbaChiplets[i], l_mbaPosition),
                 "Error getting MBA position");

        // Get DIMM type
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_DIMM_TYPE, l_mbaChiplets[i], l_dimm_type),
                 "Error getting ATTR_CEN_EFF_DIMM_TYPE");

        // If RDIMM or LRDIMM, load max_cfg_rcd_protection_time and enable RCD recovery
        if ((l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_RDIMM)
            || (l_dimm_type == fapi2::ENUM_ATTR_CEN_EFF_DIMM_TYPE_LRDIMM))
        {

            FAPI_TRY(fapi2::getScom(l_mbaChiplets[i], CEN_MBA_MBA_DSM0Q, l_mba_dsm0));

            // Get 24:29 cfg_wrdone_dly
            l_mba_dsm0.extract < 24, 6, 8 - 6 > (l_cfg_wrdone_dly);

            // Get 36:41 cfg_rdtag_dly
            l_mba_dsm0.extract < 36, 6, 8 - 6 > (l_cfg_rdtag_dly);

            // Pick lower of the two: cfg_wrdone_dly and cfg_rdtag_dly, and use that for l_max_cfg_rcd_protection_time
            if (l_cfg_wrdone_dly <= l_cfg_rdtag_dly)
            {
                l_max_cfg_rcd_protection_time = l_cfg_wrdone_dly;
            }
            else
            {
                l_max_cfg_rcd_protection_time = l_cfg_rdtag_dly;
            }

            // Read FARB0
            FAPI_TRY(fapi2::getScom(l_mbaChiplets[i], CEN_MBA_MBA_FARB0Q, l_mba_farb0));

            // Load l_max_cfg_rcd_protection_time
            FAPI_TRY(l_mba_farb0.insert( l_max_cfg_rcd_protection_time, 48, 6, 8 - 6 ));

            // Clear bit 54, cfg_disable_rcd_recovery, to enable RCD recovery
            l_mba_farb0.clearBit<54>();

            // Write FARB0
            FAPI_TRY(fapi2::putScom(l_mbaChiplets[i], CEN_MBA_MBA_FARB0Q, l_mba_farb0));
        }


        //*************************
        //*************************
        // MBASPA
        //*************************
        //*************************
        // NOTE: FW wants to mask these and rely instead on detecting the
        // cmd complete attention, then checking these manually to see if
        // they cause the cmd to stop

        //*************************
        //*************************
        // MBECCFIR
        //*************************
        //*************************

        // Read mask
        FAPI_TRY(fapi2::getScom(i_target,
                                l_mbeccfir_mask_address[l_mbaPosition],
                                l_mbeccfir_mask));

        // NOTE: In the IPL sequence, mss_unmask_maint_errors has already been
        // called, which has already set the MBECCFIR action regs to their runtime
        // values, so no need to touch the action regs here.

        // NOTE: In the IPL sequence, mss_unmask_maint_errors,
        // has already been called, which has already unmasked the approproiate
        // MBECCFIR errors following mss_unmask_maint_errors. So all we will do
        // here is unmask errors requiring mainline traffic which would be
        // considered valid after the mss_thermal_init procedure.

        l_mbeccfir_mask_and.flush<1>();

        // 0:7  Memory MPE Rank 0:7         recoverable         unmask
        l_mbeccfir_mask_and.clearBit<0, 8>();

        // 16   Memory NCE                  recoverable         unmask
        l_mbeccfir_mask_and.clearBit<16>();

        // 17   Memory RCE                  recoverable         unmask
        l_mbeccfir_mask_and.clearBit<17>();

        // 19   Memory UE                   recoverable         unmask
        l_mbeccfir_mask_and.clearBit<19>();

#if 0 // Should this be removed - AAM ?
        // NOTE: FW wants to mask these and rely instead on detecting the
        // cmd complete attention, then checking these manually to see if
        // they cause the cmd to stop

        // 20:27    Maint MPE Rank 0:7      recoverable         unmask
        l_mbeccfir_mask_and.clearBit<20, 8>();

        // 41   Maintenance UE              recoverable         unmask
        l_mbeccfir_mask_and.clearBit<41>();
#endif

        // 43   Prefetch Memory UE          recoverable         unmask
        l_mbeccfir_mask_and.clearBit<43>();

        // 44   Memory RCD Parity Error     channel checkstop   unmask (hw414700)
        if (l_hw414700)
        {
            l_mbeccfir_mask_and.clearBit<44>();
        }

        // Write mask AND
        FAPI_TRY(fapi2::putScom(i_target,
                                l_mbeccfir_mask_and_address[l_mbaPosition],
                                l_mbeccfir_mask_and));

        //************************************************
        // DEBUG: read them all back to verify
        FAPI_TRY(fapi2::getScom(i_target,
                                l_mbeccfir_mask_address[l_mbaPosition],
                                l_mbeccfir_mask));

        //************************************************
    }

    //*************************
    //*************************
    // MBACALFIR
    //*************************
    //*************************


    // NOTE: In the IPL sequence, mss_unmask_draminit_errors has already been
    // called, which has already set the MBACALFIR action regs to their runtime
    // values, so no need to touch the action regs here.

    // NOTE: In the IPL sequence, various bits have already been unmasked
    // after the approproiate procedures. So all we will do here is unmask
    // errors requiring mainline traffic which would be considered valid after
    // the mss_thermal_init procedure.

    // Loop through functional MBAs on this Centaur
    for (uint32_t i = 0; i < l_mbaChiplets.size(); ++i)
    {

        // Read mask
        FAPI_TRY(fapi2::getScom(l_mbaChiplets[i],
                                CEN_MBA_MBACALFIR_MASK,
                                l_mbacalfir_mask));


        l_mbacalfir_mask_and.flush<1>();

        // 9    mba_wrd ue                  recoverable         unmask
        l_mbacalfir_mask_and.clearBit<9>();

        // 10   mba_wrd ce                  recoverable         unmask
        l_mbacalfir_mask_and.clearBit<10>();

        // 14   wrq_data_ce                 recoverable         unmask
        l_mbacalfir_mask_and.clearBit<14>();

        // 15   wrq_data_ue                 recoverable         unmask
        l_mbacalfir_mask_and.clearBit<15>();

        // Write mask AND
        FAPI_TRY(fapi2::putScom(l_mbaChiplets[i],
                                CEN_MBA_MBACALFIR_MASK_WO_AND,
                                l_mbacalfir_mask_and));

        //************************************************
        // DEBUG: read them all back to verify
        FAPI_TRY(fapi2::getScom(l_mbaChiplets[i],
                                CEN_MBA_MBACALFIR_MASK,
                                l_mbacalfir_mask));

        //************************************************
    }

fapi_try_exit:
    FAPI_INF("EXIT mss_unmask_fetch_errors()");
    return fapi2::current_err;
}
