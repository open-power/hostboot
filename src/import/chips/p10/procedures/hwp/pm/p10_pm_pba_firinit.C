/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_pba_firinit.C $ */
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
/// @file p10_pm_pba_firinit.C
/// @brief Configures the PBA LFIR, Mask and Action
///
// *HWP HW Owner        :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   3
// *HWP Consumed by     :   HS


/// High-level procedure flow:
/// @verbatim
///   if reset:
///      Mask all bits of FIR
///   else if init:
///      Establish the respective mask/action bits for the following settings:
///          1) Checkstop
///          2) Malf Alert
///          3) Recoverable Attention
///          4) Recoverable Interrupt
///
/// @endverbatim
///
/// Procedure Prereq:
///   o System clocks are running

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pm_pba_firinit.H>

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

namespace pbao
{
enum PBAO_FIR_BITS
{
    OCI_APAR_ERR = 0,
    OCI_SLAVE_INIT = 1,
    OCI_WRPAR_ERR = 2,
    RESERVED_3 = 3,
    BCUE_SETUP_ERR = 4,
    BCUE_OCI_DATERR = 5,
    BCDE_SETUP_ERR = 6,
    BCDE_OCI_DATERR = 7,
    INTERNAL_ERR = 8,
    OCI_BAD_REG_ADDR = 9,
    AXPUSH_WRERR = 10,
    AXIPUSH_WRERR = 11,
    AXFLOW_ERR = 12,
    AXIFLOW_ERR = 13,
    AXSND_RSVERR = 14,
    AXISND_RSVERR = 15,
    HTM_WRITE_OVERFLOW = 16,
    INVALID_TOPOLOGY_ID = 17,
    RESERVED_18 = 18,
    RESERVED_19 = 19,
};
}

namespace pbaf
{
enum PBAF_FIR_BITS
{
    PB_RDADRERR_FW = 0,
    PB_RDDATATO_FW = 1,
    PB_SUE_FW = 2,
    PB_UE_FW = 3,
    PB_CE_FW = 4,
    PB_UNEXPCRESP = 5,
    PB_UNEXPDATA = 6,
    PB_PARITY_ERR = 7,
    PB_WRADRERR_FW = 8,
    PB_BADCRESP = 9,
    PB_ACKDEAD_FW_RD = 10,
    PB_OPERTO = 11,
    BCUE_PB_ACK_DEAD = 12,
    BCUE_PB_ADRERR = 13,
    BCDE_PB_ACK_DEAD = 14,
    BCDE_PB_ADRERR = 15,
    BCDE_RDDATATO_ERR = 16,
    BCDE_SUE_ERR = 17,
    BCDE_UE_ERR = 18,
    BCDE_CE = 19,
    INTERNAL_ERR = 20,
    ILLEGAL_CACHE_OP = 21,
    AXRCV_DLO_ERR = 22,
    AXRCV_DLO_TO = 23,
    AXRCV_RSVDATA_TO = 24,
    AXFLOW_ERR = 25,
    AXSND_DHI_RTYTO = 26,
    AXSND_DLO_RTYTO = 27,
    AXSND_RSVTO = 28,
    PB_ACKDEAD_FW_WR = 29,
    AXIRCV_DLO_ERR = 30,
    AXIRCV_DLO_TO = 31,
    AXIRCV_RSVDATA_TO = 32,
    AXIFLOW_ERR = 33,
    AXISND_DHI_RTYTO = 34,
    AXISND_DLO_RTYTO = 35,
    AXISND_RSVTO = 36,
    RESERVED_37 = 37,
    RESERVED_38 = 38,
    RESERVED_39 = 39,
};
}



// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

fapi2::ReturnCode pm_pba_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode pm_pba_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p10_pm_pba_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p10_pm_pba_firinit Enter");

    if(i_mode == pm::PM_RESET_SOFT)
    {
        FAPI_TRY(pm_pba_fir_reset(i_target),
                 "ERROR: Failed to reset the PBA FIRs");
    }
    else if(i_mode == pm::PM_INIT_SOFT)
    {
        FAPI_TRY(pm_pba_fir_init(i_target),
                 "ERROR: Failed to initialize the PBA FIRs");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_PBA_FIRINIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p10_pm_pba_firinit. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("p10_pm_pba_firinit Exit");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_pba_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_pba_fir_reset Enter");

    // PBAO
    pmFIR::PMFir <pmFIR::FIRTYPE_PBAO_LFIR,
          fapi2::TARGET_TYPE_PROC_CHIP> l_pbaoFir(i_target);
    // PBAF
    pmFIR::PMFir <pmFIR::FIRTYPE_PBAF_LFIR,
          fapi2::TARGET_TYPE_PROC_CHIP> l_pbafFir(i_target);

    // PBAO
    FAPI_TRY(l_pbaoFir.get(pmFIR::REG_FIRMASK),
             "ERROR: Failed to get the PBAO FIR MASK value");

    /* Fetch the PBAO FIR MASK; Save it to HWP attribute; clear its contents */
    FAPI_TRY(l_pbaoFir.saveMask(),
             "ERROR: Failed to save the PBAO FIR Mask to the attribute");

    // PBAF
    FAPI_TRY(l_pbafFir.get(pmFIR::REG_FIRMASK),
             "ERROR: Failed to get the PBAF FIR MASK value");

    /* Fetch the PBAF FIR MASK; Save it to HWP attribute; clear its contents */
    FAPI_TRY(l_pbafFir.saveMask(),
             "ERROR: Failed to save the PBAF FIR Mask to the attribute");

    // PBAO
    FAPI_TRY(l_pbaoFir.setAllRegBits(pmFIR::REG_FIRMASK),
             "ERROR: Faled to set the PBAO FIR MASK");

    FAPI_TRY(l_pbaoFir.put(),
             "ERROR:Failed to write to the PBAO FIR MASK");

    // PBAF
    FAPI_TRY(l_pbafFir.setAllRegBits(pmFIR::REG_FIRMASK),
             "ERROR: Faled to set the PBAF FIR MASK");

    FAPI_TRY(l_pbafFir.put(),
             "ERROR:Failed to write to the PBAF FIR MASK");

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode pm_pba_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_pba_fir_init Enter");
    // PBAO
    pmFIR::PMFir <pmFIR::FIRTYPE_PBAO_LFIR,
          fapi2::TARGET_TYPE_PROC_CHIP> l_pbaoFir(i_target);
    // PBAF
    pmFIR::PMFir <pmFIR::FIRTYPE_PBAF_LFIR,
          fapi2::TARGET_TYPE_PROC_CHIP> l_pbafFir(i_target);

    FAPI_TRY(l_pbaoFir.get(pmFIR::REG_ALL),
             "ERROR: Failed to get the PBAO FIR values");

    FAPI_TRY(l_pbafFir.get(pmFIR::REG_ALL),
             "ERROR: Failed to get the PBAF FIR values");

    /* Clear all the PBAO and PBAF FIR and action buffers */
    // PBAO
    FAPI_TRY(l_pbaoFir.clearAllRegBits(pmFIR::REG_FIR),
             "ERROR: Failed to clear PBAO FIR");
    FAPI_TRY(l_pbaoFir.clearAllRegBits(pmFIR::REG_ACTION0),
             "ERROR: Failed to clear PBAO action 0");
    FAPI_TRY(l_pbaoFir.clearAllRegBits(pmFIR::REG_ACTION1),
             "ERROR: Failed to clear PBAO action 1");

    // PBAF
    FAPI_TRY(l_pbafFir.clearAllRegBits(pmFIR::REG_FIR),
             "ERROR: Failed to clear PBAF FIR");
    FAPI_TRY(l_pbafFir.clearAllRegBits(pmFIR::REG_ACTION0),
             "ERROR: Failed to clear PBAF action 0");
    FAPI_TRY(l_pbafFir.clearAllRegBits(pmFIR::REG_ACTION1),
             "ERROR: Failed to clear PBAF action 1");
    // PBAO
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::OCI_APAR_ERR),         FIR_REC_ATTN_ERROR);    // 0
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::OCI_SLAVE_INIT),       FIR_REC_ATTN_ERROR);    // 1
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::OCI_WRPAR_ERR),        FIR_REC_ATTN_ERROR);    // 2
    FAPI_TRY(l_pbaoFir.mask(pbao::RESERVED_3),                  FIR_MASK_ERROR);        // 3
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::BCUE_SETUP_ERR),       FIR_REC_ATTN_ERROR);    // 4
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::BCUE_OCI_DATERR),      FIR_REC_ATTN_ERROR);    // 5
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::BCDE_SETUP_ERR),       FIR_REC_ATTN_ERROR);    // 6
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::BCDE_OCI_DATERR),      FIR_REC_ATTN_ERROR);    // 7
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::INTERNAL_ERR),         FIR_REC_ATTN_ERROR);    // 8
    FAPI_TRY(l_pbaoFir.mask(pbao::OCI_BAD_REG_ADDR),            FIR_MASK_ERROR);        // 9  Firmware error
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::AXPUSH_WRERR),         FIR_REC_ATTN_ERROR);    // 10
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::AXIPUSH_WRERR),        FIR_REC_ATTN_ERROR);    // 11
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::AXFLOW_ERR),           FIR_REC_ATTN_ERROR);    // 12
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::AXIFLOW_ERR),          FIR_REC_ATTN_ERROR);    // 13
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::AXSND_RSVERR),         FIR_REC_ATTN_ERROR);    // 14
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::AXISND_RSVERR),        FIR_REC_ATTN_ERROR);    // 15
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::HTM_WRITE_OVERFLOW),   FIR_REC_ATTN_ERROR);    // 16
    FAPI_TRY(l_pbaoFir.setRecvAttn(pbao::INVALID_TOPOLOGY_ID),  FIR_REC_ATTN_ERROR);    // 17
    FAPI_TRY(l_pbaoFir.mask(pbao::RESERVED_18),                 FIR_MASK_ERROR);        // 18
    FAPI_TRY(l_pbaoFir.mask(pbao::RESERVED_19),                 FIR_MASK_ERROR);        // 19

    // PBAF
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_RDADRERR_FW),       FIR_REC_ATTN_ERROR);    // 0
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_RDDATATO_FW),       FIR_REC_ATTN_ERROR);    // 1
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_SUE_FW),            FIR_REC_ATTN_ERROR);    // 2
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_UE_FW),             FIR_REC_ATTN_ERROR);    // 3
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_CE_FW),             FIR_REC_ATTN_ERROR);    // 4
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_UNEXPCRESP),        FIR_REC_ATTN_ERROR);    // 5
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_UNEXPDATA),         FIR_REC_ATTN_ERROR);    // 6
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_PARITY_ERR),        FIR_REC_ATTN_ERROR);    // 7
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_WRADRERR_FW),       FIR_REC_ATTN_ERROR);    // 8
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_BADCRESP),          FIR_REC_ATTN_ERROR);    // 9
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_ACKDEAD_FW_RD),     FIR_REC_ATTN_ERROR);    // 10
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_OPERTO),            FIR_REC_ATTN_ERROR);    // 11
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::BCUE_PB_ACK_DEAD),     FIR_REC_ATTN_ERROR);    // 12
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::BCUE_PB_ADRERR),       FIR_REC_ATTN_ERROR);    // 13
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::BCDE_PB_ACK_DEAD),     FIR_REC_ATTN_ERROR);    // 14
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::BCDE_PB_ADRERR),       FIR_REC_ATTN_ERROR);    // 15
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::BCDE_RDDATATO_ERR),    FIR_REC_ATTN_ERROR);    // 16
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::BCDE_SUE_ERR),         FIR_REC_ATTN_ERROR);    // 17
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::BCDE_UE_ERR),          FIR_REC_ATTN_ERROR);    // 18
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::BCDE_CE),              FIR_REC_ATTN_ERROR);    // 19
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::INTERNAL_ERR),         FIR_REC_ATTN_ERROR);    // 20
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::ILLEGAL_CACHE_OP),     FIR_REC_ATTN_ERROR);    // 21
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXRCV_DLO_ERR),        FIR_REC_ATTN_ERROR);    // 22
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXRCV_DLO_TO),         FIR_REC_ATTN_ERROR);    // 23
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXRCV_RSVDATA_TO),     FIR_REC_ATTN_ERROR);    // 24
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXFLOW_ERR),           FIR_REC_ATTN_ERROR);    // 25
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXSND_DHI_RTYTO),      FIR_REC_ATTN_ERROR);    // 26
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXSND_DLO_RTYTO),      FIR_REC_ATTN_ERROR);    // 27
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXSND_RSVTO),          FIR_REC_ATTN_ERROR);    // 38
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::PB_ACKDEAD_FW_WR),     FIR_REC_ATTN_ERROR);    // 39
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXIRCV_DLO_ERR),       FIR_REC_ATTN_ERROR);    // 30
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXIRCV_DLO_TO),        FIR_REC_ATTN_ERROR);    // 31
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXIRCV_RSVDATA_TO),    FIR_REC_ATTN_ERROR);    // 32
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXIFLOW_ERR),          FIR_REC_ATTN_ERROR);    // 33
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXISND_DHI_RTYTO),     FIR_REC_ATTN_ERROR);    // 34
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXISND_DLO_RTYTO),     FIR_REC_ATTN_ERROR);    // 35
    FAPI_TRY(l_pbafFir.setRecvAttn(pbaf::AXISND_RSVTO),         FIR_REC_ATTN_ERROR);    // 36
    FAPI_TRY(l_pbafFir.mask(pbaf::RESERVED_37),                 FIR_MASK_ERROR);        // 37
    FAPI_TRY(l_pbafFir.mask(pbaf::RESERVED_38),                 FIR_MASK_ERROR);        // 38
    FAPI_TRY(l_pbafFir.mask(pbaf::RESERVED_39),                 FIR_MASK_ERROR);        // 39

    // PBAO
    FAPI_TRY(l_pbaoFir.put(),
             "ERROR: Failed to write the PBAO FIR values");
    // PBAF
    FAPI_TRY(l_pbafFir.put(),
             "ERROR: Failed to write the PBAF FIR values");


fapi_try_exit:
    return fapi2::current_err;
}
