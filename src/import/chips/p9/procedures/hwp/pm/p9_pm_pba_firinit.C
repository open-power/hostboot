/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pba_firinit.C $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_pba_firinit.C
/// @brief Configures the PBA LFIR, Mask and Action
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW  Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: HS
//

/// High-level procedure flow:
/// \verbatim
///   if reset:
///      Mask all bits of FIR
///   else if init:
///      Establish the respective mask/action bits for the following settings:
///          1) Checkstop
///          2) Malf Alert
///          3) Recoverable Attention
///          4) Recoverable Interrupt
///
/// \endverbatim
///
/// Procedure Prereq:
///   o System clocks are running

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_pba_firinit.H>

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

enum PBA_FIR_BITS
{
    PBAFIR_OCI_APAR_ERR,     // 0
    PBAFIR_PB_RDADRERR_FW,   // 1
    PBAFIR_PB_RDDATATO_FW,   // 2
    PBAFIR_PB_SUE_FW,        // 3
    PBAFIR_PB_UE_FW,         // 4
    PBAFIR_PB_CE_FW,         // 5
    PBAFIR_OCI_SLAVE_INIT,   // 6
    PBAFIR_OCI_WRPAR_ERR,    // 7
    PBAFIR_OCI_REREQTO,      // 8
    PBAFIR_PB_UNEXPCRESP,    // 9
    PBAFIR_PB_UNEXPDATA,     // 10
    PBAFIR_PB_PARITY_ERR,    // 11
    PBAFIR_PB_WRADRERR_FW,   // 12
    PBAFIR_PB_BADCRESP,      // 13
    PBAFIR_PB_ACKDEAD_FW_RD, // 14
    PBAFIR_PB_CRESPTO,       // 15
    PBAFIR_BCUE_SETUP_ERR,   // 16
    PBAFIR_BCUE_PB_ACK_DEAD, // 17
    PBAFIR_BCUE_PB_ADRERR,   // 18
    PBAFIR_BCUE_OCI_DATERR,  // 19
    PBAFIR_BCDE_SETUP_ERR,   // 20
    PBAFIR_BCDE_PB_ACK_DEAD, // 21
    PBAFIR_BCDE_PB_ADRERR,   // 22
    PBAFIR_BCDE_RDDATATO_ERR,// 23
    PBAFIR_BCDE_SUE_ERR,     // 24
    PBAFIR_BCDE_UE_ERR,      // 25
    PBAFIR_BCDE_CE,          // 26
    PBAFIR_BCDE_OCI_DATERR,  // 27
    PBAFIR_INTERNAL_ERR,     // 28
    PBAFIR_ILLEGAL_CACHE_OP, // 29
    PBAFIR_OCI_BAD_REG_ADDR, // 30
    PBAFIR_AXPUSH_WRERR,     // 31
    PBAFIR_AXRCV_DLO_ERR,    // 32
    PBAFIR_AXRCV_DLO_TO,     // 33
    PBAFIR_AXRCV_RSVDATA_TO, // 34
    PBAFIR_AXFLOW_ERR,       // 35
    PBAFIR_AXSND_DHI_RTYTO,  // 36
    PBAFIR_AXSND_DLO_RTYTO,  // 37
    PBAFIR_AXSND_RSVTO,      // 38
    PBAFIR_AXSND_RSVERR,     // 39
    PBAFIR_PB_ACKDEAD_FW_WR, // 40
    PBAFIR_RESERVED_41,      // 41
    PBAFIR_RESERVED_42,      // 42
    PBAFIR_RESERVED_43,      // 43
    PBAFIR_FIR_PARITY_ERR2,  // 44
    PBAFIR_FIR_PARITY_ERR    // 45
};

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

fapi2::ReturnCode p9_pm_pba_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_pba_firinit Enter");

    if(i_mode == p9pm::PM_RESET)
    {
        FAPI_TRY(pm_pba_fir_reset(i_target),
                 "ERROR: Failed to reset the PBA FIRs");
    }
    else if(i_mode == p9pm::PM_INIT)
    {
        FAPI_TRY(pm_pba_fir_init(i_target),
                 "ERROR: Failed to initialize the PBA FIRs");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::PM_PBA_FIRINIT_BAD_MODE().set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p9_pm_pba_firinit. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("p9_pm_pba_firinit Exit");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_pba_fir_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_pba_fir_reset Enter");

    uint8_t firinit_done_flag;
    p9pmFIR::PMFir <p9pmFIR::FIRTYPE_PBA_LFIR> l_pbaFir(i_target);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    if (firinit_done_flag == 1)
    {
        FAPI_TRY(l_pbaFir.get(p9pmFIR::REG_FIRMASK),
                 "ERROR: Failed to get the PBA FIR MASK value");
        /* Fetch the PBA FIR MASK; Save it to HWP attribute; clear it */
        FAPI_TRY(l_pbaFir.saveMask(),
                 "ERROR: Failed to save the PBA FIR Mask to the attribute");
    }

    FAPI_TRY(l_pbaFir.setAllRegBits(p9pmFIR::REG_FIRMASK),
             "ERROR: Faled to set the PBA FIR MASK");

    FAPI_TRY(l_pbaFir.put(),
             "ERROR:Failed to write to the PBA FIR MASK");

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode pm_pba_fir_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("pm_pba_fir_init Enter");

    uint8_t firinit_done_flag;
    p9pmFIR::PMFir <p9pmFIR::FIRTYPE_PBA_LFIR> l_pbaFir(i_target);

    FAPI_TRY(l_pbaFir.get(p9pmFIR::REG_ALL),
             "ERROR: Failed to get the PBA FIR values");

    /* Clear the FIR and action buffers */
    FAPI_TRY(l_pbaFir.clearAllRegBits(p9pmFIR::REG_FIR),
             "ERROR: Failed to clear PBA FIR");
    FAPI_TRY(l_pbaFir.clearAllRegBits(p9pmFIR::REG_ACTION0),
             "ERROR: Failed to clear PBA FIR");
    FAPI_TRY(l_pbaFir.clearAllRegBits(p9pmFIR::REG_ACTION1),
             "ERROR: Failed to clear PBA FIR");

    /*  Set the action and mask for the PBA LFIR bits */
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_OCI_APAR_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_RDADRERR_FW),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_RDDATATO_FW),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_SUE_FW),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_UE_FW),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_CE_FW),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_OCI_SLAVE_INIT),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_OCI_WRPAR_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_OCI_REREQTO),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_UNEXPCRESP),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_UNEXPDATA),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_PARITY_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_WRADRERR_FW),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_BADCRESP),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_ACKDEAD_FW_RD),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_CRESPTO),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCUE_SETUP_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCUE_PB_ACK_DEAD),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCUE_PB_ADRERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCUE_OCI_DATERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCDE_SETUP_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCDE_PB_ACK_DEAD),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCDE_PB_ADRERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCDE_RDDATATO_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCDE_SUE_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCDE_UE_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCDE_CE),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_BCDE_OCI_DATERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_INTERNAL_ERR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_ILLEGAL_CACHE_OP),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_OCI_BAD_REG_ADDR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXPUSH_WRERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXRCV_DLO_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXRCV_DLO_TO),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXRCV_RSVDATA_TO),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXFLOW_ERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXSND_DHI_RTYTO),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXSND_DLO_RTYTO),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXSND_RSVTO),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_AXSND_RSVERR),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_PB_ACKDEAD_FW_WR),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_RESERVED_41),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_RESERVED_42),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.mask(PBAFIR_RESERVED_43),
             "ERROR: Failed to mask bit");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_FIR_PARITY_ERR2),
             "ERROR: Failed to set recovery attention");
    FAPI_TRY(l_pbaFir.setRecvAttn(PBAFIR_FIR_PARITY_ERR),
             "ERROR: Failed to set recovery attention");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                           i_target, firinit_done_flag),
             "ERROR: Failed to fetch the entry status of FIRINIT");

    if (firinit_done_flag)
    {
        FAPI_TRY(l_pbaFir.restoreSavedMask(),
                 "ERROR: Failed to restore the mask saved");
    }

    FAPI_TRY(l_pbaFir.put(),
             "ERROR:Failed to write to the PBA FIR MASK");

fapi_try_exit:
    return fapi2::current_err;
}
