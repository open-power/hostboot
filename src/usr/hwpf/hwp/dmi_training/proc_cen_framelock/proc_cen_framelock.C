/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/proc_cen_framelock/proc_cen_framelock.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// $Id: proc_cen_framelock.C,v 1.21 2013/12/10 21:25:35 baysah Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cen_framelock.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_cen_framelock.C
// *! DESCRIPTION : Run framelock and FRTL (FAPI)
// *!
// *! OWNER NAME  : Irving Baysah           Email: baysah@us.ibm.com
// *!
//------------------------------------------------------------------------------

// Change Log
// Version | who      |Date     | Comment
//   1.20  | bellows  |25-NOV-13| Changed include to use <> instead of "" for hostboot
//   1.19  | bellows  |08-NOV-13| Added ATTR_MSS_INIT_STATE to track IPL states

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_cen_framelock.H>


extern "C"
{
using namespace fapi;

//------------------------------------------------------------------------------
// function: utility subroutine to clear the Centaur MBI Status Register
// parameters: i_mem_target  => Centaur target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_clear_cen_mbi_stat_reg(
    const fapi::Target& i_mem_target )
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase zero_data(64);

    //FAPI_DBG("proc_cen_framelock_clear_cen_mbi_stat_reg: Start");

    rc = fapiPutScom(i_mem_target, MBI_STAT_0x0201080B, zero_data);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_clear_cen_mbi_stat_reg: fapiPutScom error (MBI_STAT_0x0201080B)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to get the Centaur MBI Status Register
// parameters: i_mem_target  => Centaur target
//             o_data        => Output data
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_get_cen_mbi_stat_reg(
    const fapi::Target& i_mem_target,
    ecmdDataBufferBase& o_data)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_get_cen_mbi_stat_reg: Start");

    rc = fapiGetScom(i_mem_target, MBI_STAT_0x0201080B, o_data);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_get_cen_mbi_stat_reg: fapiGetScom error (MBI_STAT_0x0201080B)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to clear the Centaur MBI FIR Register
// parameters: i_mem_target  => Centaur target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_clear_cen_mbi_fir_reg(
    const fapi::Target& i_mem_target)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase zero_data(64);

    //FAPI_DBG("proc_cen_framelock_clear_cen_mbi_fir_reg: Start");

    rc = fapiPutScom(i_mem_target, MBI_FIR_0x02010800, zero_data);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_clear_cen_mbi_fir_reg: fapiPutScom error (MBI_FIR_0x02010800)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to get the Centaur MBI FIR Register
// parameters: i_mem_target  => Centaur target
//             o_data        => Output data
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_get_cen_mbi_fir_reg(
    const fapi::Target& i_mem_target,
    ecmdDataBufferBase& o_data)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_get_cen_mbi_fir_reg: Start");

    rc = fapiGetScom(i_mem_target, MBI_FIR_0x02010800, o_data);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_get_cen_mbi_fir_reg: fapiGetScom error (MBI_FIR_0x02010800)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to clear the P8 MCI Status Register
// parameters: i_pu_target  => P8 MCS chip unit target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_clear_pu_mci_stat_reg(
    const fapi::Target& i_pu_target)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase zero_data(64);

    //FAPI_DBG("proc_cen_framelock_clear_pu_mci_stat_reg: Start");

    rc = fapiPutScom(i_pu_target, MCS_MCISTAT_0x0201184B, zero_data);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_clear_pu_mci_stat_reg: fapiPutScom error (MCS_MCISTAT_0x0201184B)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to get the P8 MCI Status Register
// parameters: i_pu_target  => P8 MCS chip unit target
//             o_data       => Output data
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_get_pu_mci_stat_reg(
    const fapi::Target& i_pu_target,
    ecmdDataBufferBase& o_data)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_get_pu_mci_stat_reg: Start");

    rc = fapiGetScom(i_pu_target, MCS_MCISTAT_0x0201184B, o_data);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_get_pu_mci_stat_reg: fapiGetScom error (MCS_MCISTAT_0x0201184B)");
    }
    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to clear the P8 MCI FIR Register
// parameters: i_pu_target  => P8 MCS chip unit target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_clear_pu_mci_fir_reg(
    const fapi::Target& i_pu_target)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase zero_data(64);

    //FAPI_DBG("proc_cen_framelock_clear_pu_mci_fir_reg: Start");

    rc = fapiPutScom(i_pu_target, MCS_MCIFIR_0x02011840, zero_data);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_clear_pu_mci_fir_reg: fapiPutScom error (MCS_MCIFIR_0x02011840)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to get the P8 MCI FIR Register
// parameters: i_pu_target  => P8 MCS chip unit target
//             o_data       => output data
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_get_pu_mci_fir_reg(
    const fapi::Target& i_pu_target,
    ecmdDataBufferBase& o_data)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_get_pu_mci_fir_reg: Start");

    rc = fapiGetScom(i_pu_target, MCS_MCIFIR_0x02011840, o_data);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_get_pu_mci_fir_reg: fapiGetScom error (MCS_MCIFIR_0x02011840)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the Centaur MBI Config Register
// parameters: i_mem_target => Centaur target
//             i_data       => Input data
//             i_mask       => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_cen_mbi_cfg_reg(
    const fapi::Target& i_mem_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_cen_mbi_cfg_reg: Start");
    rc = fapiPutScomUnderMask(i_mem_target, MBI_CFG_0x0201080A, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_cen_mbi_cfg_reg: fapiPutScomUnderMask error (MBI_CFG_0x0201080A)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the P8 MCI Config Register
// parameters: i_pu_target => P8 MCS chip unit target
//             i_data      => Input data
//             i_mask      => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_pu_mci_cfg_reg(
    const fapi::Target& i_pu_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_pu_mci_cfg_reg: Start");

    rc = fapiPutScomUnderMask(i_pu_target, MCS_MCICFG_0x0201184A, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_pu_mci_cfg_reg: fapiPutScomUnderMask error (MCS_MCICFG_0x0201184A)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the Centaur MBI FIR Mask Register
// parameters: i_mem_target => Centaur target
//             i_data       => Input data
//             i_mask       => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_cen_mbi_firmask_reg(
    const fapi::Target& i_mem_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_cen_mbi_firmsk_reg: Start");
    rc = fapiPutScomUnderMask(i_mem_target, MBI_FIRMASK_0x02010803, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_cen_mbi_firmask_reg: fapiPutScomUnderMask error (MBI_FIRMASK_0x02010803)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the Centaur MBI FIR Action0 Register
// parameters: i_mem_target => Centaur target
//             i_data       => Input data
//             i_mask       => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_cen_mbi_firact0_reg(
    const fapi::Target& i_mem_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_cen_mbi_firact0_reg: Start");
    rc = fapiPutScomUnderMask(i_mem_target, MBI_FIRACT0_0x02010806, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_cen_mbi_firact0_reg: fapiPutScomUnderMask error (MBI_FIRACT0_0x02010806)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the Centaur MBI FIR Action1 Register
// parameters: i_mem_target => Centaur target
//             i_data       => Input data
//             i_mask       => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_cen_mbi_firact1_reg(
    const fapi::Target& i_mem_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_cen_mbi_firact1_reg: Start");
    rc = fapiPutScomUnderMask(i_mem_target, MBI_FIRACT1_0x02010807, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_cen_mbi_firact1_reg: fapiPutScomUnderMask error (MBI_FIRACT1_0x02010807)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the P8 MCI FIR Mask Register
// parameters: i_pu_target => P8 MCS chip unit target
//             i_data      => Input data
//             i_mask      => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_pu_mci_firmask_reg(
    const fapi::Target& i_pu_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_pu_mci_firmask_reg: Start");

    rc = fapiPutScomUnderMask(i_pu_target, MCS_MCIFIRMASK_0x02011843, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_pu_mci_firmask_reg: fapiPutScomUnderMask error (MCS_MCIFIRMASK_0x02011843)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the P8 MCI FIR Action0 Register
// parameters: i_pu_target => P8 MCS chip unit target
//             i_data      => Input data
//             i_mask      => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_pu_mci_firact0_reg(
    const fapi::Target& i_pu_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_pu_mci_firact0_reg: Start");

    rc = fapiPutScomUnderMask(i_pu_target, MCS_MCIFIRACT0_0x02011846, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_pu_mci_firact0_reg: fapiPutScomUnderMask error (MCS_MCIFIRACT0_0x02011846)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the P8 MCI FIR Action1 Register
// parameters: i_pu_target => P8 MCS chip unit target
//             i_data      => Input data
//             i_mask      => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_pu_mci_firact1_reg(
    const fapi::Target& i_pu_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_pu_mci_firact1_reg: Start");

    rc = fapiPutScomUnderMask(i_pu_target, MCS_MCIFIRACT1_0x02011847, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_pu_mci_firact1_reg: fapiPutScomUnderMask error (MCS_MCIFIRACT1_0x02011847)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set the P8 MCS Mode4 Register
// parameters: i_pu_target => P8 MCS chip unit target
//             i_data      => Input data
//             i_mask      => Input mask
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_pu_mcs_mode4_reg(
    const fapi::Target& i_pu_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask)
{
    fapi::ReturnCode rc;

    //FAPI_DBG("proc_cen_framelock_set_pu_mcs_mode4_reg: Start");

    rc = fapiPutScomUnderMask(i_pu_target, MCS_MCSMODE4_0x0201181A, i_data, i_mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_pu_mcs_mode4_reg: fapiPutScomUnderMask error (MCS_MCSMODE4_0x0201181A)");
    }

    return rc;
}


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: utility subroutine to initiate P8/Centaur framelock operation and
//           poll for completion
// parameters: i_pu_target  => P8 MCS chip unit target
//             i_mem_target => Centaur chip target
//             i_args       => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if framelock sequence completes successfully,
//          RC_PROC_CEN_FRAMELOCK_FL_P8_FIR_ERR_MCS
//          RC_PROC_CEN_FRAMELOCK_FL_P8_FIR_ERR_MEMBUF
//              if MCI FIR is set during framelock operation,
//          RC_PROC_CEN_FRAMELOCK_FL_P8_FAIL_ERR
//              if MCI indicates framelock operation failure
//          RC_PROC_CEN_FRAMELOCK_FL_TIMEOUT_ERR
//              if MCI does not post pass/fail indication after framelock
//              operation is started,
//          else FAPI getscom/putscom return code for failing SCOM operation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_run_framelock(
    const fapi::Target& i_pu_target,
    const fapi::Target& i_mem_target,
    const proc_cen_framelock_args& i_args)
{
    // data buffers
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);
    ecmdDataBufferBase mci_stat(64);
    ecmdDataBufferBase mci_fir(64);
    ecmdDataBufferBase errstate(8);

    // Reference variables matching error XML
    const ecmdDataBufferBase & MCI_STAT = mci_stat;
    const ecmdDataBufferBase & MCI_FIR = mci_fir;
    const fapi::Target & MCS_CHIPLET = i_pu_target;
    const fapi::Target & MEMBUF_CHIP = i_mem_target;

    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;


    FAPI_DBG("proc_cen_framelock_run_framelock: Starting framelock sequence ...");

    // Clear P8 MCI FIR registers
    rc = proc_cen_framelock_clear_pu_mci_fir_reg(i_pu_target);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_framelock: Error clearing P8 MCI FIR regs");
        return rc;
    }


    // Clear P8 Status registers
    rc = proc_cen_framelock_clear_pu_mci_stat_reg(i_pu_target);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_framelock: Error clearing P8 MCI Status regs");
        return rc;
    }


    // set channel init timeout value in P8 MCI Configuration Register
    // FAPI_DBG("proc_cen_framelock_run_framelock: Writing P8 MCI Configuration Register to set channel init timeout value ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= mask.flushTo0();
    rc_ecmd |= data.insertFromRight(
        (uint32_t) (i_args.channel_init_timeout &
                    MCI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK),
        MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
        (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT -
         MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1));
    rc_ecmd |= mask.setBit(
        MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
        (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT -
         MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1));
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_framelock: Error 0x%x setting up data buffers to set init timeout",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_framelock: Error writing P8 MCI Configuration register to set init timeout");
        return rc;
    }

    // start framelock
    // FAPI_DBG("proc_cen_framelock_run_framelock: Writing P8 MCI Configuration Register to initiate framelock ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MCI_CFG_START_FRAMELOCK_BIT);
    rc_ecmd |= data.copy(mask);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_framelock: Error 0x%x setting up data buffers to initiate framelock",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_framelock: Error writing P8 MCI Configuration register to initiate framelock");
        return rc;
    }

    // poll until framelock operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    uint8_t polls = 0;

    while (polls < PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS)
    {
        // Read P8 MCI Status Register
        rc = proc_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Error reading P8 MCI Status Register");
            return rc;
        }

        // Read P8 MCI FIR Register
        rc = proc_cen_framelock_get_pu_mci_fir_reg(i_pu_target, mci_fir);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Error reading P8 MCI FIR Register");
            return rc;
        }

        // Fail if P8 MCI Frame Lock FAIL
        if (mci_stat.isBitSet(MCI_STAT_FRAMELOCK_FAIL_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Framelock fail. P8 MCI STAT");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_P8_FAIL_ERR);
            return rc;
        }

        // Fail if MCI FIR bits are set
        if (mci_fir.isBitSet(MCI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_DATA_FLOW_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_MCICFGQ_PARITY_ERROR_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Framelock fail. P8 MCI FIR errors set (MCS)");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_P8_FIR_ERR_MCS);
            return rc;
        }

        if (mci_fir.isBitSet(MCI_FIR_DMI_CHANNEL_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_INIT_TIMEOUT_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CENTAUR_CHECKSTOP_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_FAIL_ACTIVE_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Framelock fail. P8 MCI FIR errors set (MEMBUF)");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_P8_FIR_ERR_MEMBUF);
            return rc;
        }

        // Success if P8 PASS bits set
        if ((mci_stat.isBitSet(MCI_STAT_FRAMELOCK_PASS_BIT)) )
        {
            FAPI_INF("proc_cen_framelock_run_framelock: Framelock completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("proc_cen_framelock_run_framelock: Framelock not done, loop %d of %d...",
                     polls, PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS);
        }
    }

    if (polls >= PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS)
    {
        // Loop count has expired, timeout
        FAPI_ERR("proc_cen_framelock_run_framelock:!!!! NO FRAME LOCK STATUS DETECTED !!!!");
        FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_TIMEOUT_ERR);
        return rc;
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to initiate P8/Centaur FRTL (frame round trip
//           latency) determination and check for completion
// parameters: i_pu_target  => P8 MCS chip unit target
//             i_mem_target => Centaur chip target
// returns: FAPI_RC_SUCCESS if FRTL sequence completes successfully,
//          RC_PROC_CEN_FRAMELOCK_FRTL_P8_FIR_ERR_MCS
//          RC_PROC_CEN_FRAMELOCK_FRTL_P8_FIR_ERR_MEMBUF
//              if MCI FIR is set during FRTL operation,
//          RC_PROC_CEN_FRAMELOCK_FRTL_P8_FAIL_ERR
//              if MCI indicates FRTL operation failure,
//          RC_PROC_CEN_FRAMELOCK_FRTL_TIMEOUT_ERR
//              if MCI does not post pass/fail indication after FRTL
//              operation is started,
//          else FAPI getscom/putscom return code for failing SCOM operation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_run_frtl(
    const fapi::Target& i_pu_target,
    const fapi::Target& i_mem_target)
{
    // data buffers for putscom/getscom calls
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);
    ecmdDataBufferBase mci_stat(64);
    ecmdDataBufferBase mci_fir(64);

    // Reference variables matching error XML
    const ecmdDataBufferBase & MCI_STAT = mci_stat;
    const ecmdDataBufferBase & MCI_FIR = mci_fir;
    const fapi::Target & MCS_CHIPLET = i_pu_target;
    const fapi::Target & MEMBUF_CHIP = i_mem_target;

    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // mark function entry
    FAPI_DBG("proc_cen_framelock_run_frtl: Starting FRTL sequence ...");

    // start FRTL
    // FAPI_DBG("proc_cen_framelock_run_frtl: Writing P8 MCI Configuration Register to initiate FRTL ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MCI_CFG_START_FRTL_BIT);
    rc_ecmd |= data.copy(mask);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to initiate FRTL",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_frtl: Error writing P8 MCI Configuration register to initiate FRTL");
        return rc;
    }

    // Poll until FRTL operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    uint8_t polls = 0;

    while (polls < PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        // Read P8 MCI Status Register
        rc = proc_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_frtl: Error reading P8 MCI Status Register");
            return rc;
        }

        // Read P8 MCI FIR Register
        rc = proc_cen_framelock_get_pu_mci_fir_reg(i_pu_target, mci_fir);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_frtl: Error reading P8 MCI FIR Register");
            return rc;
        }

        // Fail if P8 MCI FRTL FAIL or Channel Interlock Fail
        if (mci_stat.isBitSet(MCI_STAT_FRTL_FAIL_BIT)  ||
            mci_stat.isBitSet(MCI_STAT_CHANNEL_INTERLOCK_FAIL_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_frtl: FRTL fail. P8 MCI STAT");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FRTL_P8_FAIL_ERR);
            return rc;
        }

        // Fail if MCI FIR bits are set
        if (mci_fir.isBitSet(MCI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_DATA_FLOW_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_MCICFGQ_PARITY_ERROR_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_frtl: FRTL fail. P8 FIR errors set (MCS)");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FRTL_P8_FIR_ERR_MCS);
            return rc;
        }

        if (mci_fir.isBitSet(MCI_FIR_DMI_CHANNEL_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_INIT_TIMEOUT_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CENTAUR_CHECKSTOP_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_FRTL_COUNTER_OVERFLOW_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_FAIL_ACTIVE_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_frtl: FRTL fail. P8 FIR errors set (MEMBUF)");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_CEN_FRAMELOCK_FRTL_P8_FIR_ERR_MEMBUF);
            return rc;
        }

        // Success if P8 FRTL and InterLock PASS bits are set
        if ((mci_stat.isBitSet(MCI_STAT_FRTL_PASS_BIT)) &&
            (mci_stat.isBitSet(MCI_STAT_CHANNEL_INTERLOCK_PASS_BIT)))
        {
            FAPI_INF("proc_cen_framelock_run_frtl: FRTL (auto) completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("proc_cen_framelock_run_frtl: FRTL not done, loop %d of %d...",
                     polls, PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS);
        }
    }

    if (polls >= PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        // Loop count has expired, timeout
        FAPI_ERR("proc_cen_framelock_run_frtl:!!!! NO FRAME LOCK STATUS DETECTED !!!!");
        FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FRTL_TIMEOUT_ERR);
        return rc;
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to initiate P8/Centaur framelock operation and
//           poll for completion after the first operation fails.
// parameters: i_pu_target  => P8 MCS chip unit target
//             i_mem_target => Centaur chip target
//             i_args       => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if framelock sequence completes successfully,
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_CEN_FIR_ERR
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P8_FIR_ERR_MCS
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P8_FIR_ERR_MEMBUF
//              if MCI/MBI FIR is set during framelock operation,
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_CEN_FAIL_ERR
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P8_FAIL_ERR
//              if MCI/MBI indicates framelock operation failure
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_TIMEOUT_ERR
//              if MCI/MBI does not post pass/fail indication after framelock
//              operation is started,
//          else FAPI getscom/putscom return code for failing SCOM operation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_run_errstate_framelock(
    const fapi::Target& i_pu_target,
    const fapi::Target& i_mem_target,
    const proc_cen_framelock_args& i_args)
{
    // data buffers
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);
    ecmdDataBufferBase mbi_stat(64);
    ecmdDataBufferBase mbi_fir(64);
    ecmdDataBufferBase mci_stat(64);
    ecmdDataBufferBase mci_fir(64);

    // Reference variables matching error XML
    const ecmdDataBufferBase & MCI_STAT = mci_stat;
    const ecmdDataBufferBase & MCI_FIR = mci_fir;
    const ecmdDataBufferBase & MBI_STAT = mbi_stat;
    const ecmdDataBufferBase & MBI_FIR = mbi_fir;
    const fapi::Target & MCS_CHIPLET = i_pu_target;
    const fapi::Target & MEMBUF_CHIP = i_mem_target;

    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_cen_framelock_run_errstate_framelock: Starting framelock Error State sequence ...");


    // Clear MBI Channel Fail Configuration Bit
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MBI_CFG_FORCE_CHANNEL_FAIL_BIT);
    rc_ecmd |= data.copy(mask);
    rc_ecmd |= data.clearBit(MBI_CFG_FORCE_CHANNEL_FAIL_BIT);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error 0x%x clearing MBI force channel fail bit",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data,  mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error writing Centaur MBI Configuration Register to clear the force channel fail bit");
        return rc;
    }


    //Clear MCI Force Channel Fail Configuration Bit
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MCI_CFG_FORCE_CHANNEL_FAIL_BIT);
    rc_ecmd |= data.copy(mask);
    rc_ecmd |= data.clearBit(MCI_CFG_FORCE_CHANNEL_FAIL_BIT);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error 0x%x clearing MCI force channel fail bit",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error writing P8 MCI Configuration register to clear the force channel fail bit");
        return rc;
    }


    // Clear Centaur MBI FIR registers
    rc = proc_cen_framelock_clear_cen_mbi_fir_reg(i_mem_target);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error clearing Centaur MBI FIR regs");
        return rc;
    }


    // Clear Centaur MBI Status registers
    rc = proc_cen_framelock_clear_cen_mbi_stat_reg(i_mem_target);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error clearing Centaur MBI Status regs");
        return rc;
    }


    // Clear P8 MCI FIR registers
    rc = proc_cen_framelock_clear_pu_mci_fir_reg(i_pu_target);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error clearing P8 MCI FIR regs");
        return rc;
    }


    // Clear P8 Status registers
    rc = proc_cen_framelock_clear_pu_mci_stat_reg(i_pu_target);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error clearing P8 MCI Status regs");
        return rc;
    }



    // set channel init timeout value in P8 MCI Configuration Register
    //FAPI_DBG("proc_cen_framelock_run_errstate_framelock: Writing P8 MCI Configuration Register to set channel init timeout value ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= mask.flushTo0();
    rc_ecmd |= data.insertFromRight(
        (uint32_t) (i_args.channel_init_timeout &
                    MCI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK),
        MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
        (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT -
         MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1));
    rc_ecmd |= mask.setBit(
        MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
        (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT -
         MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1));
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error 0x%x setting up data buffers to set init timeout",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error writing P8 MCI Configuration register to set init timeout");
        return rc;
    }


    // start framelock on Centaur MBI
    //FAPI_DBG("proc_cen_framelock_run_errstate_framelock: Writing Centaur MBI Configuration Register to force framelock ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MBI_CFG_FORCE_FRAMELOCK_BIT);
    rc_ecmd |= data.copy(mask);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error 0x%x setting up data buffers to force framelock",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error writing Centaur MBI Configuration Register to force framelock");
        return rc;
    }


    // start framelock on P8 MCI
    //FAPI_DBG("proc_cen_framelock_run_errstate_framelock: Writing P8 MCI Configuration Register to initiate framelock ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MCI_CFG_START_FRAMELOCK_BIT);
    rc_ecmd |= data.copy(mask);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error 0x%x setting up data buffers to initiate framelock",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error writing P8 MCI Configuration register to initiate framelock");
        return rc;
    }

    // poll until framelock operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    uint8_t polls = 0;

    while (polls < PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS)
    {
        // Read CEN MBI Status Register
        rc = proc_cen_framelock_get_cen_mbi_stat_reg(i_mem_target, mbi_stat);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error reading Centaur MBI status Register");
            return rc;
        }

        // Read CEN MBI FIR Register
        rc = proc_cen_framelock_get_cen_mbi_fir_reg(i_mem_target, mbi_fir);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error reading Centaur MBI FIR Register");
            return rc;
        }

        // Read P8 MCI Status Register
        rc = proc_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error reading P8 MCI Status Register");
            return rc;
        }

        // Read P8 MCI FIR Register
        rc = proc_cen_framelock_get_pu_mci_fir_reg(i_pu_target, mci_fir);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Error reading P8 MCI FIR Register");
            return rc;
        }

        // Fail if Centaur MBI Frame Lock FAIL
        if (mbi_stat.isBitSet(MBI_STAT_FRAMELOCK_FAIL_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Framelock fail. Centaur MBI STAT");
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_CEN_FAIL_ERR);
            return rc;
        }

        // Fail if Centaur MBI FIR bits are set
        if (mbi_fir.isBitSet(MBI_FIR_DMI_CHANNEL_FAIL_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_CHANNEL_INIT_TIMEOUT_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_DATA_FLOW_PARITY_ERROR_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_MBICFGQ_PARITY_ERROR_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Framelock fail. Centaur MBI FIR errors set");
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_CEN_FIR_ERR);
            return rc;
        }

        // Fail if P8 MCI Frame Lock FAIL
        if (mci_stat.isBitSet(MCI_STAT_FRAMELOCK_FAIL_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Framelock fail. P8 MCI STAT");
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P8_FAIL_ERR);
            return rc;
        }

        // Fail if P8 MCI FIR bits are set
        if (mci_fir.isBitSet(MCI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_DATA_FLOW_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_MCICFGQ_PARITY_ERROR_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Framelock fail. P8 MCI FIR errors set (MCS)");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P8_FIR_ERR_MCS);
            return rc;
        }

        // Fail if P8 MCI FIR bits are set
        if (mci_fir.isBitSet(MCI_FIR_DMI_CHANNEL_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_INIT_TIMEOUT_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CENTAUR_CHECKSTOP_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_FAIL_ACTIVE_BIT)                )
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_framelock: Framelock fail. P8 MCI FIR errors set (MEMBUF)");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_P8_FIR_ERR_MEMBUF);
            return rc;
        }

        // Success if P8 and Centaur PASS bits set
        if ((mbi_stat.isBitSet(MBI_STAT_FRAMELOCK_PASS_BIT)) &&
            (mci_stat.isBitSet(MCI_STAT_FRAMELOCK_PASS_BIT)))
        {
            FAPI_INF("proc_cen_framelock_run_errstate_framelock: Framelock completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("proc_cen_framelock_run_errstate_framelock: Framelock not done, loop %d of %d...",
                     polls, PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS);
        }
    }

    if (polls >= PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_framelock:!!!! NO FRAME LOCK STATUS DETECTED !!!!");
        FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_ERRSTATE_FL_TIMEOUT_ERR);
        return rc;
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to initiate P8/Centaur FRTL (frame round trip
//           latency) determination and check for completion
// parameters: i_pu_target  => P8 MCS chip unit target
//             i_mem_target => Centaur chip target
// returns: FAPI_RC_SUCCESS if FRTL sequence completes successfully,
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_CEN_FIR_ERR
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P8_FIR_ERR_MCS
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P8_FIR_ERR_MEMBUF
//              if MCI/MBI FIR is set during FRTL operation,
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_CEN_FAIL_ERR
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P8_FAIL_ERR
//              if MCI/MBI indicates FRTL operation failure,
//          RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_TIMEOUT_ERR
//              if MCI/MBI does not post pass/fail indication after FRTL
//              operation is started,
//          else FAPI getscom/putscom return code for failing SCOM operation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_run_errstate_frtl(
    const fapi::Target& i_pu_target,
    const fapi::Target& i_mem_target)
{
    // data buffers for putscom/getscom calls
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);
    ecmdDataBufferBase mbi_stat(64);
    ecmdDataBufferBase mbi_fir(64);
    ecmdDataBufferBase mci_stat(64);
    ecmdDataBufferBase mci_fir(64);

    // Reference variables matching error XML
    const ecmdDataBufferBase & MCI_STAT = mci_stat;
    const ecmdDataBufferBase & MCI_FIR = mci_fir;
    const ecmdDataBufferBase & MBI_STAT = mbi_stat;
    const ecmdDataBufferBase & MBI_FIR = mbi_fir;
    const fapi::Target & MCS_CHIPLET = i_pu_target;
    const fapi::Target & MEMBUF_CHIP = i_mem_target;

    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // mark function entry
    FAPI_DBG("proc_cen_framelock_run_errstate_frtl: Starting FRTL Error State sequence ...");




    // if error state is set, force FRTL bit in Centaur MBI
    //FAPI_DBG("proc_cen_framelock_run_errstate_frtl: Writing Centaur MBI Configuration register to force FRTL ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MBI_CFG_FORCE_FRTL_BIT);
    rc_ecmd |= data.copy(mask);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_frtl: Error 0x%x setting up data buffers to force FRTL",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_frtl: Error writing Centaur MBI Configuration Register to force FRTL");
        return rc;
    }


    // start FRTL
    //FAPI_DBG("proc_cen_framelock_run_errstate_frtl: Writing P8 MCI Configuration Register to initiate FRTL ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MCI_CFG_START_FRTL_BIT);
    rc_ecmd |= data.copy(mask);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_frtl: Error 0x%x setting up data buffers to initiate FRTL",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_errstate_frtl: Error writing P8 MCI Configuration register to initiate FRTL");
        rc.setEcmdError(rc);
        return rc;
    }

    // Poll until FRTL operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    uint8_t polls = 0;

    while (polls < PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        // Read Centaur MBI Status Register
        rc = proc_cen_framelock_get_cen_mbi_stat_reg(i_mem_target, mbi_stat);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: Error reading Centaur MBI Status Register");
            return rc;
        }

        // Read Centaur MBI FIR Register
        rc = proc_cen_framelock_get_cen_mbi_fir_reg(i_mem_target, mbi_fir);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: Error reading Centaur MBI FIR Register");
            return rc;
        }

        // Read P8 MCI Status Register
        rc = proc_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: Error reading P8 MCI Status Register");
            return rc;
        }

        // Read P8 MCI FIR Register
        rc = proc_cen_framelock_get_pu_mci_fir_reg(i_pu_target, mci_fir);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: Error reading P8 MCI FIR Register");
            return rc;
        }

        // Fail if Centaur MBI FRTL FAIL or Channel Interlock Fail
        if (mbi_stat.isBitSet(MBI_STAT_FRTL_FAIL_BIT)  ||
            mbi_stat.isBitSet(MBI_STAT_CHANNEL_INTERLOCK_FAIL_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: FRTL fail. Centaur MBI STAT");
            FAPI_SET_HWP_ERROR(rc,
                              RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_CEN_FAIL_ERR);
            return rc;
        }

        // Fail if Centaur MBI FIR bits are set
        if (mbi_fir.isBitSet(MBI_FIR_DMI_CHANNEL_FAIL_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_CHANNEL_INIT_TIMEOUT_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_DATA_FLOW_PARITY_ERROR_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_FRTL_COUNTER_OVERFLOW_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_MBICFGQ_PARITY_ERROR_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: FRTL fail. Centaur MBI FIR errors set");
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_CEN_FIR_ERR);
            return rc;
        }

        // Fail if P8 MCI FRTL FAIL or Channel Interlock Fail
        if (mci_stat.isBitSet(MCI_STAT_FRTL_FAIL_BIT)  ||
            mci_stat.isBitSet(MCI_STAT_CHANNEL_INTERLOCK_FAIL_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: FRTL fail. P8 MCI STAT");
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P8_FAIL_ERR);
            return rc;
        }

        // Fail if MCI FIR bits are set
        if (mci_fir.isBitSet(MCI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_DATA_FLOW_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_MCICFGQ_PARITY_ERROR_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: FRTL fail. P8 MCI FIR errors set (MCS)");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P8_FIR_ERR_MCS);
            return rc;
        }

        if (mci_fir.isBitSet(MCI_FIR_DMI_CHANNEL_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_INIT_TIMEOUT_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CENTAUR_CHECKSTOP_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_FRTL_COUNTER_OVERFLOW_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_FAIL_ACTIVE_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_errstate_frtl: FRTL fail. P8 MCI FIR errors set (MEMBUF)");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_P8_FIR_ERR_MEMBUF);
            return rc;
        }

        // Success if Centaur and P8 PASS bits set
        if ((mbi_stat.isBitSet(MBI_STAT_FRTL_PASS_BIT)) &&
            (mbi_stat.isBitSet(MBI_STAT_CHANNEL_INTERLOCK_PASS_BIT)) &&
            (mci_stat.isBitSet(MCI_STAT_CHANNEL_INTERLOCK_PASS_BIT)) &&
            (mci_stat.isBitSet(MCI_STAT_FRTL_PASS_BIT)))
        {
            FAPI_INF("proc_cen_framelock_run_errstate_frtl: FRTL (auto) completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("proc_cen_framelock_run_errstate_frtl: FRTL not done, loop %d of %d ...\n",
                     polls, PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS);
        }
    }

    if (polls >= PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        // Loop count has expired, timeout
        FAPI_ERR("proc_cen_framelock_run_errstate_frtl:!!!! NO FRAME LOCK STATUS DETECTED !!!!");
        FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_ERRSTATE_FRTL_TIMEOUT_ERR);
        return rc;
    }

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to initiate P8/Centaur FRTL (frame round trip
//           latency) determination and check for completion
// parameters: i_pu_target  => P8 MCS chip unit target
//             i_mem_target => Centaur chip target
//             i_args       => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if FRTL sequence completes successfully,
//          RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_CEN_FIR_ERR
//          RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P8_FIR_ERR_MCS
//          RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P8_FIR_ERR_MEMBUF
//              if MCI/MBI FIR is set during FRTL operation,
//          RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_CEN_FAIL_ERR
//          RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P8_FAIL_ERR
//              if MCI/MBI indicates FRTL operation failure,
//          RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_TIMEOUT_ERR
//              if MCI/MBI does not post pass/fail indication after FRTL
//              operation is started,
//          else FAPI getscom/putscom return code for failing SCOM operation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_run_manual_frtl(
    const fapi::Target& i_pu_target,
    const fapi::Target& i_mem_target,
    const proc_cen_framelock_args& i_args)
{
    // data buffers for putscom/getscom calls
    ecmdDataBufferBase data(64);
    ecmdDataBufferBase mask(64);
    ecmdDataBufferBase mbi_stat(64);
    ecmdDataBufferBase mbi_fir(64);
    ecmdDataBufferBase mci_stat(64);
    ecmdDataBufferBase mci_fir(64);

    // Reference variables matching error XML
    const ecmdDataBufferBase & MCI_STAT = mci_stat;
    const ecmdDataBufferBase & MCI_FIR = mci_fir;
    const ecmdDataBufferBase & MBI_STAT = mbi_stat;
    const ecmdDataBufferBase & MBI_FIR = mbi_fir;
    const fapi::Target & MCS_CHIPLET = i_pu_target;
    const fapi::Target & MEMBUF_CHIP = i_mem_target;

    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // mark function entry
    FAPI_DBG("proc_cen_framelock_run_manual_frtl: Starting FRTL manual sequence ...");




    // Manual mode

    // Disable auto FRTL mode & channel init timeout in Centaur MBI
    // Configuration Register
    //FAPI_DBG("proc_cen_framelock_run_manual_frtl: Writing Centaur MBI Configuration register to disable auto FRTL mode & channel init timeout ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MBI_CFG_AUTO_FRTL_DISABLE_BIT);
    rc_ecmd |= data.copy(mask);
    rc_ecmd |= data.insertFromRight(
        (uint32_t) (CHANNEL_INIT_TIMEOUT_NO_TIMEOUT &
                    MBI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK),
        MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
        (MBI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT -
         MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1));
    rc_ecmd |= mask.setBit(
        MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
        (MBI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT -
         MBI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1));
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error 0x%x setting up data buffers to disable Centaur auto FRTL mode",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error writing Centaur MBI Configuration register to disable auto FRTL mode");
        return rc;
    }

    // write specified FRTL value into Centaur MBI Configuration
    // Register
    //FAPI_DBG("proc_cen_framelock_run_manual_frtl: Writing Centaur MBI Configuration register to set manual FRTL value ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= mask.flushTo0();
    rc_ecmd |= data.insertFromRight(
        (uint32_t) (i_args.frtl_manual_mem &
                    MBI_CFG_MANUAL_FRTL_FIELD_MASK),
        MBI_CFG_MANUAL_FRTL_START_BIT,
        (MBI_CFG_MANUAL_FRTL_END_BIT -
         MBI_CFG_MANUAL_FRTL_START_BIT + 1));
    rc_ecmd |= mask.setBit(
        MBI_CFG_MANUAL_FRTL_START_BIT,
        (MBI_CFG_MANUAL_FRTL_END_BIT -
         MBI_CFG_MANUAL_FRTL_START_BIT + 1));

    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error 0x%x setting up data buffers to set Centaur manual FRTL value",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error writing Centaur MBI Configuration register to set manual FRTL value");
        return rc;
    }


    // disable auto FRTL mode & channel init timeout in P8 MCI
    // Configuration Register
    //FAPI_DBG("proc_cen_framelock_run_manual_frtl: Writing P8 MCI Configuration register to disable auto FRTL mode & channel init timeout ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MCI_CFG_AUTO_FRTL_DISABLE_BIT);
    rc_ecmd |= data.copy(mask);
    rc_ecmd |= data.insertFromRight(
        (uint32_t)(CHANNEL_INIT_TIMEOUT_NO_TIMEOUT &
                   MCI_CFG_CHANNEL_INIT_TIMEOUT_FIELD_MASK),
        MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
        (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT -
         MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1));
    rc_ecmd |= mask.setBit(
        MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT,
        (MCI_CFG_CHANNEL_INIT_TIMEOUT_END_BIT -
         MCI_CFG_CHANNEL_INIT_TIMEOUT_START_BIT + 1));
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error 0x%x setting up data buffers to disable P8 auto FRTL mode",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error writing P8 MCI Configuration register to disable auto FRTL mode");
        return rc;
    }

    // write specified FRTL value into P8 MCI Configuration Register
    //FAPI_DBG("proc_cen_framelock_run_manual_frtl: Writing P8 MCI Configuration register to set manual FRTL value ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= mask.flushTo0();
    rc_ecmd |= data.insertFromRight(
        (uint32_t)(i_args.frtl_manual_pu &
                   MCI_CFG_MANUAL_FRTL_FIELD_MASK),
        MCI_CFG_MANUAL_FRTL_START_BIT,
        (MCI_CFG_MANUAL_FRTL_END_BIT -
         MCI_CFG_MANUAL_FRTL_START_BIT + 1));
    rc_ecmd |= mask.setBit(
        MCI_CFG_MANUAL_FRTL_START_BIT,
        (MCI_CFG_MANUAL_FRTL_END_BIT -
         MCI_CFG_MANUAL_FRTL_START_BIT + 1));

    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error 0x%x setting up data buffers to set P8 manual FRTL value",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error writing P8 MCI Configuration register to set manual FRTL value");
        rc.setEcmdError(rc_ecmd);
        return rc;
    }


    // write FRTL manual done bit into Centaur MBI Configuration
    // Register
    //FAPI_DBG("proc_cen_framelock_run_manual_frtl: Writing Centaur MBI Configuration register to set manual FRTL done bit ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MBI_CFG_MANUAL_FRTL_DONE_BIT);
    rc_ecmd |= data.copy(mask);
    if (rc_ecmd)
    {
        FAPI_ERR( "proc_cen_framelock_run_manual_frtl: Error 0x%x setting up data buffers to set Centaur manual FRTL done",
                  rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error writing Centaur MBI Configuration register to set manual FRTL done");
        return rc;
    }

    // write FRTL manual done bit into P8 MCI Configuration Register
    //FAPI_DBG("proc_cen_framelock_run_manual_frtl: Writing P8 MCI Configuration register to set manual FRTL done bit ...");
    rc_ecmd |= data.flushTo0();
    rc_ecmd |= data.setBit(MCI_CFG_MANUAL_FRTL_DONE_BIT);
    rc_ecmd |= data.copy(mask);
    if (rc_ecmd)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error 0x%x setting up data buffers to write P8 manual FRTL done",
                 rc_ecmd);
        rc.setEcmdError(rc_ecmd);
        return rc;
    }

    rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error writing P8 MCI Configuration register to set manual FRTL done");
        return rc;
    }




    // Poll until FRTL operation is finished, a timeout is deemed to
    // have occurred, or an error is detected
    uint8_t polls = 0;

    while (polls < PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        // Read Centaur MBI Status Register
        rc = proc_cen_framelock_get_cen_mbi_stat_reg(i_mem_target, mbi_stat);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error reading Centaur MBI Status Register");
            return rc;
        }

        // Read Centaur MBI FIR Register
        rc = proc_cen_framelock_get_cen_mbi_fir_reg(i_mem_target, mbi_fir);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error reading Centaur MBI FIR Register");
            return rc;
        }

        // Read P8 MCI Status Register
        rc = proc_cen_framelock_get_pu_mci_stat_reg(i_pu_target, mci_stat);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error reading P8 MCI Status Register");
            return rc;
        }

        // Read P8 MCI FIR Register
        rc = proc_cen_framelock_get_pu_mci_fir_reg(i_pu_target, mci_fir);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: Error reading P8 MCI FIR Register");
            return rc;
        }

        // Fail if Centaur MBI FRTL FAIL or Channel Interlock Fail
        if (mbi_stat.isBitSet(MBI_STAT_FRTL_FAIL_BIT)  ||
            mbi_stat.isBitSet(MBI_STAT_CHANNEL_INTERLOCK_FAIL_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: FRTL fail. Centaur MBI STAT");
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_CEN_FAIL_ERR);
            return rc;
        }

        // Fail if Centaur MBI FIR bits are set
        if (mbi_fir.isBitSet(MBI_FIR_DMI_CHANNEL_FAIL_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_CHANNEL_INIT_TIMEOUT_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_DATA_FLOW_PARITY_ERROR_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_FRTL_COUNTER_OVERFLOW_BIT) ||
            mbi_fir.isBitSet(MBI_FIR_MBICFGQ_PARITY_ERROR_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: FRTL fail. Centaur MBI FIR errors set");
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_CEN_FIR_ERR);
            return rc;
        }

        // Fail if P8 MCI FRTL FAIL or Channel Interlock Fail
        if (mci_stat.isBitSet(MCI_STAT_FRTL_FAIL_BIT)  ||
            mci_stat.isBitSet(MCI_STAT_CHANNEL_INTERLOCK_FAIL_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: FRTL fail. P8 MCI STAT");
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P8_FAIL_ERR);
            return rc;
        }

        // Fail if MCI FIR bits are set
        if (mci_fir.isBitSet(MCI_FIR_INTERNAL_CONTROL_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_DATA_FLOW_PARITY_ERROR_BIT) ||
            mci_fir.isBitSet(MCI_FIR_MCICFGQ_PARITY_ERROR_BIT))
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: FRTL fail. P8 MCI FIR errors set (MCS)");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P8_FIR_ERR_MCS);
            return rc;
        }

        if (mci_fir.isBitSet(MCI_FIR_DMI_CHANNEL_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_INIT_TIMEOUT_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CENTAUR_CHECKSTOP_FAIL_BIT) ||
            mci_fir.isBitSet(MCI_FIR_FRTL_COUNTER_OVERFLOW_BIT) ||
            mci_fir.isBitSet(MCI_FIR_CHANNEL_FAIL_ACTIVE_BIT)                )
        {
            FAPI_ERR("proc_cen_framelock_run_manual_frtl: FRTL fail. P8 MCI FIR errors set (MEMBUF)");
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_P8_FIR_ERR_MEMBUF);
            return rc;
        }

        // Success if Centaur and P8 PASS bits set
        if ((mbi_stat.isBitSet(MBI_STAT_FRTL_PASS_BIT)) &&
            (mbi_stat.isBitSet(MBI_STAT_CHANNEL_INTERLOCK_PASS_BIT)) &&
            (mci_stat.isBitSet(MCI_STAT_CHANNEL_INTERLOCK_PASS_BIT)) &&
            (mci_stat.isBitSet(MCI_STAT_FRTL_PASS_BIT)))
        {
            FAPI_INF("proc_cen_framelock_run_manual_frtl: FRTL (manual) completed successfully!");
            break;
        }
        else
        {
            polls++;
            FAPI_INF("proc_cen_framelock_run_manual_frtl: FRTL not done, loop %d of %d...\n",
                     polls, PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS);
        }
    }

    if (polls >= PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS)
    {
        // Loop count has expired, timeout
        FAPI_ERR("proc_cen_framelock_run_manual_frtl:!!!! NO FRAME LOCK STATUS DETECTED !!!!");
        FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_MANUAL_FRTL_TIMEOUT_ERR);
        return rc;
    }

    return rc;
}


//------------------------------------------------------------------------------
// The Main Hardware Procedure
// ##################################################
// The frame lock procedure initializes the Centaur DMI memory channel.  In the
// event of errors, it will attempt to rerun the procedure.  There will be up to 3 attempts
// at initialization before giving up.  This procedure assumes the DMI/EDI channel training
// states completed successfully and that the DMI fence was lowered.
//
// When the procedure is first run, NO SCOM will be performed on Centaur.  All the scom accesses
// are limited to Murano/Venice.  This allows for very fast initialization of the channels.  However,
// if the initialization does encounter a fail event, the procedure will make a second (if necessary,
// a third attempt) at intializing the channel.  The second and third attempts require scoms to both
// P8 and Centaur chips.
//
//
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock(const fapi::Target& i_pu_target,
                                    const fapi::Target& i_mem_target,
                                    const proc_cen_framelock_args& i_args)
{

 // data buffers for putscom/getscom calls
    ecmdDataBufferBase mci_data(64);
    ecmdDataBufferBase mbi_data(64);
    ecmdDataBufferBase mci_mask(64);
    ecmdDataBufferBase mbi_mask(64);

    fapi::ReturnCode l_rc;
    uint32_t l_ecmdRc = 0;

    // mark HWP entry
    FAPI_IMP("proc_cen_framelock: Entering ...");

    // validate arguments
    if (i_args.frtl_manual_mem > MBI_CFG_MANUAL_FRTL_FIELD_MASK)
    {
        FAPI_ERR("proc_cen_framelock: Out of range value %d presented for manual FRTL mem argument value!",
                 i_args.frtl_manual_mem);
        const proc_cen_framelock_args & ARGS = i_args;
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_CEN_FRAMELOCK_INVALID_ARGS);
        return l_rc;
    }

    if (i_args.frtl_manual_pu > MCI_CFG_MANUAL_FRTL_FIELD_MASK)
    {
        FAPI_ERR("proc_cen_framelock: Out of range value %d presented for manual FRTL pu argument value!",
                 i_args.frtl_manual_pu);
        const proc_cen_framelock_args & ARGS = i_args;
        FAPI_SET_HWP_ERROR(l_rc, RC_PROC_CEN_FRAMELOCK_INVALID_ARGS);
        return l_rc;
    }

    // Execute Framelock
    l_rc = proc_cen_framelock_run_framelock(i_pu_target, i_mem_target, i_args);

    if (!l_rc)
    {
        // Execute FRTL
        if (i_args.frtl_auto_not_manual)
        {
            l_rc = proc_cen_framelock_run_frtl(i_pu_target, i_mem_target);
        }
        else
        {
            l_rc = proc_cen_framelock_run_manual_frtl(i_pu_target, i_mem_target,
                                                      i_args);
        }
    }

    if (l_rc)
    {
        // The regular framelock/frtl failed, retry up to twice using the
        // errorstate functions
        const uint8_t NUM_FRAMELOCK_ERR_RETRIES = 2;
        for (uint8_t i=0; i<NUM_FRAMELOCK_ERR_RETRIES; i++)
        {
            // Force MBI in Channel Fail State
            l_ecmdRc |= mbi_data.flushTo0();
            l_ecmdRc |= mbi_data.setBit(MBI_CFG_FORCE_CHANNEL_FAIL_BIT);
            l_ecmdRc |= mbi_data.copy(mbi_mask);
            if (l_ecmdRc)
            {
                FAPI_ERR("proc_cen_framelock: Error 0x%x setting up data buffers to force MBI in channel fail state",
                         l_ecmdRc);
                l_rc.setEcmdError(l_ecmdRc);
                return l_rc;
            }

            l_rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, mbi_data,  mbi_mask);
            if (l_rc)
            {
                FAPI_ERR("proc_cen_framelock: Error writing Centaur MBI Configuration Register to force framelock");
                return l_rc;
            }

            //Force MCI in Channel Fail State
            l_ecmdRc |= mci_data.flushTo0();
            l_ecmdRc |= mci_data.setBit(MCI_CFG_FORCE_CHANNEL_FAIL_BIT);
            l_ecmdRc |= mci_data.copy(mci_mask);
            if (l_ecmdRc)
            {
                FAPI_ERR("proc_cen_framelock: Error 0x%x setting up data buffers to force MCI in channel fail state",
                         l_ecmdRc);
                l_rc.setEcmdError(l_ecmdRc);
                return l_rc;
            }

            l_rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, mci_data, mci_mask);
            if (l_rc)
            {
                 FAPI_ERR("proc_cen_framelock: Error writing P8 MCI Configuration register to force MCI in channel fail state");
                 return l_rc;
            }

            // 1ms/100simcycles delay
            fapiDelay(1000000, 100); //fapiDelay(nanoseconds, simcycles)

            // Execute errorstate Framelock
            l_rc = proc_cen_framelock_run_errstate_framelock(i_pu_target,
                                                             i_mem_target,
                                                             i_args);

            // In error state attempt FRTL although FL might have failed
            fapi::ReturnCode l_rc2;
            if (i_args.frtl_auto_not_manual)
            {
                l_rc2 = proc_cen_framelock_run_errstate_frtl(i_pu_target,
                                                             i_mem_target);
            }
            else
            {
                l_rc2 = proc_cen_framelock_run_manual_frtl(i_pu_target,
                                                           i_mem_target,
                                                           i_args);
            }

            if (!l_rc)
            {
                // Framelock successful, use FRTL result
                l_rc = l_rc2;
            }

            if (!l_rc)
            {
                // Success, break out of retry loop
                break;
            }
        }
    }

    if (l_rc)
    {
        return l_rc;
    }

    // Clear FIR register before exiting procedure
    // Clear P8 MCI FIR registers
    l_rc = proc_cen_framelock_clear_pu_mci_fir_reg(i_pu_target);
    if (l_rc)
    {
        FAPI_ERR("proc_cen_framelock: Error clearing P8 MCI FIR regs");
        return l_rc;
    }

    // Clear Centaur MBI FIR registers
    l_rc = proc_cen_framelock_clear_cen_mbi_fir_reg(i_mem_target);
    if (l_rc)
    {
        FAPI_ERR("proc_cen_framelock: Error clearing Centaur MBI FIR regs");
        return l_rc;
    }

    // EXIT Procedure
    // by setting the MCI and MBI fir action and mask registers according to PRD requirements.

    // (Action0, Action1, Mask)
    // ------------------------
    // (0,0,0) = Checkstop
    // (0,1,0) = Recoverable Error
    // (1,0,x) = Recoverable Interrupt
    // (1,1,0) = Machine Check
    // (x,x,1) = MASKED
    // (1,0,0) = Use this setting for non-implemented bits

    // Set P8 MCI FIR ACT0
    //     Set action regs to recoverable interrupt (action0=1, action1=0) for MCIFIR's 12,15,16 and 17
    //     On 4/25/2013, PRD asked to change bit 12 action from recov intr to recover error
    //     On 12/10/2013, PRD asked to change bit 12 action back from recov error to recover interrupt
    l_ecmdRc |= mci_data.flushTo0();
    l_ecmdRc |= mci_data.setBit(12);    //Centaur Checkstop
    l_ecmdRc |= mci_data.setBit(15);    //Centaur Recoverable Attention
    l_ecmdRc |= mci_data.setBit(16);    //Centaur Special Attention
    l_ecmdRc |= mci_data.setBit(17);    //Centaur Maintenance Complete
    l_ecmdRc |= mci_data.copy(mci_mask);
    if (l_ecmdRc)
    {
        FAPI_ERR("proc_cen_framelock: Error 0x%x setting up data buffers to set MCI FIR actions",
                 l_ecmdRc);
        l_rc.setEcmdError(l_ecmdRc);
        return l_rc;
    }

    l_rc = proc_cen_framelock_set_pu_mci_firact0_reg(i_pu_target, mci_data, mci_mask);
    if (l_rc)
    {
        FAPI_ERR("proc_cen_framelock: Error writing P8 MCI Fir Action0 Register");
        return l_rc;
    }

    // Set P8 MCI FIR ACT1
    //     Set action regs to recoverable error (action0=0, action1=1) for the following MCIFIR's
    l_ecmdRc |= mci_data.flushTo0();
    l_ecmdRc |= mci_data.setBit(0);     //Replay Timeout
    l_ecmdRc |= mci_data.setBit(4);     //Seqid OOO
    l_ecmdRc |= mci_data.setBit(5);     //Replay Buffer CE
    l_ecmdRc |= mci_data.setBit(6);     //Replay Buffer UE
    l_ecmdRc |= mci_data.setBit(8);     //MCI Internal Control Parity Error
    l_ecmdRc |= mci_data.setBit(9);     //MCI Data Flow Parity Error
    l_ecmdRc |= mci_data.setBit(10);    //CRC Performance Degradation
    //l_ecmdRc |= mci_data.setBit(12);    //Centaur Checkstop
    l_ecmdRc |= mci_data.setBit(20);    //Scom Register parity error
    l_ecmdRc |= mci_data.setBit(22);    //mcicfgq parity error
    l_ecmdRc |= mci_data.setBit(23);    //Replay Buffer Overrun
    l_ecmdRc |= mci_data.setBit(24);    //MCIFIRQ_MCS_RECOVERABLE_ERROR
    l_ecmdRc |= mci_data.setBit(27);    //MCS Command List Timeout due to PowerBus
    l_ecmdRc |= mci_data.setBit(35);    //PowerBus Write Data Buffer CE
    l_ecmdRc |= mci_data.setBit(36);    //PowerBus Write Data Buffer UE
    //l_ecmdRc |= mci_data.setBit(40);    //MCS Channel Timeout Error (On 5/06/2013 changed this fir to xstop, have to re-eval for Murano dd2)
    l_ecmdRc |= mci_data.copy(mci_mask);
    if (l_ecmdRc)
    {
        FAPI_ERR("proc_cen_framelock: Error 0x%x setting up data buffers to set MCI FIR actions",
                 l_ecmdRc);
        l_rc.setEcmdError(l_ecmdRc);
        return l_rc;
    }

    l_rc = proc_cen_framelock_set_pu_mci_firact1_reg(i_pu_target, mci_data, mci_mask);
    if (l_rc)
    {
        FAPI_ERR("proc_cen_framelock: Error writing P8 MCI Fir Action1 Register");
        return l_rc;
    }

    // Set P8 MCS Mode4 Register
    //     Enable recoverable interrupt output of MCS_MCIFIR to drive host attention
    //        MCMODE4Q[12]=0 (disable special attention output)
    //        MCMODE4Q[13]=1 (enable host attention output)

    l_ecmdRc |= mci_data.flushTo0();
    l_ecmdRc |= mci_data.setBit(12);    //MCS FIR recov_int output drives MCS spec_attn_output
    l_ecmdRc |= mci_data.setBit(13);    //MCS FIR recov_int output drives MCS host_attn_output
    l_ecmdRc |= mci_data.copy(mci_mask);
    l_ecmdRc |= mci_data.clearBit(12);  //MCS FIR recov_int output drives MCS spec_attn_output
    if (l_ecmdRc)
    {
        FAPI_ERR("proc_cen_framelock: Error 0x%x setting up data buffers to set MCS Mode4 Register",
                 l_ecmdRc);
        l_rc.setEcmdError(l_ecmdRc);
        return l_rc;
    }

    l_rc = proc_cen_framelock_set_pu_mcs_mode4_reg(i_pu_target, mci_data, mci_mask);
    if (l_rc)
    {
        FAPI_ERR("proc_cen_framelock: Error writing P8 MCS Mode4 Register");
        return l_rc;
    }

    // Set P8 MCI FIR Mask
    l_ecmdRc |= mci_data.flushTo0();
    l_ecmdRc |= mci_data.setBit(0);     //Replay Timeout
    l_ecmdRc |= mci_data.setBit(4);     //Seqid OOO
    l_ecmdRc |= mci_data.setBit(5);     //Replay Buffer CE
    l_ecmdRc |= mci_data.setBit(6);     //Replay Buffer UE
    l_ecmdRc |= mci_data.setBit(8);     //MCI Internal Control Parity Error
    l_ecmdRc |= mci_data.setBit(9);     //MCI Data Flow Parity Error
    l_ecmdRc |= mci_data.setBit(10);    //CRC Performance Degradation
    l_ecmdRc |= mci_data.setBit(12);    //Centaur Checkstop
    l_ecmdRc |= mci_data.setBit(15);    //Centaur Recoverable Attention
    l_ecmdRc |= mci_data.setBit(16);    //Centaur Special Attention
    l_ecmdRc |= mci_data.setBit(17);    //Centaur Maintenance Complete
    l_ecmdRc |= mci_data.setBit(20);    //SCOM Register Parity Error
    l_ecmdRc |= mci_data.setBit(22);    //MCICFGQ Parity Error
    l_ecmdRc |= mci_data.setBit(23);    //Replay Buffer Overrun
    l_ecmdRc |= mci_data.setBit(24);    //Recoverable MC Internal Error
    l_ecmdRc |= mci_data.setBit(25);    //Non-Recoverable MC Internal Error (xstop)
    l_ecmdRc |= mci_data.setBit(26);    //PowerBus Protocol Error (xstop)
    l_ecmdRc |= mci_data.setBit(27);    //MCS Command List Timeout due to PB
    l_ecmdRc |= mci_data.setBit(28);    //Multiple RCMD or CRESP active
    l_ecmdRc |= mci_data.setBit(29);    //Inband Bar Hit with Incorrect TTYPE (xstop)
    l_ecmdRc |= mci_data.setBit(30);    //Multiple Bar Hit (xstop)
    l_ecmdRc |= mci_data.setBit(33);    //Invalid Foreign Bar Access (xstop)
    l_ecmdRc |= mci_data.setBit(35);    //PowerBus Write Data Buffer CE
    l_ecmdRc |= mci_data.setBit(36);    //PowerBus Write Data Buffer UE
    l_ecmdRc |= mci_data.setBit(38);    //HA Illegal Consumer Access Error (xstop)
    l_ecmdRc |= mci_data.setBit(39);    //HA Illegal Producer Access Error (xstop)
    l_ecmdRc |= mci_data.setBit(40);    //MCS Channel Timeout Error
    l_ecmdRc |= mci_data.copy(mci_mask);
    l_ecmdRc |= mci_data.clearBit(0);     //Replay Timeout
    l_ecmdRc |= mci_data.clearBit(4);     //Seqid OOO
    l_ecmdRc |= mci_data.clearBit(5);     //Replay Buffer CE
    l_ecmdRc |= mci_data.clearBit(6);     //Replay Buffer UE
    l_ecmdRc |= mci_data.clearBit(8);     //MCI Internal Control Parity Error
    l_ecmdRc |= mci_data.clearBit(9);     //MCI Data Flow Parity Error
    l_ecmdRc |= mci_data.clearBit(10);    //CRC Performance Degradation
    l_ecmdRc |= mci_data.clearBit(12);    //Centaur Checkstop
    l_ecmdRc |= mci_data.clearBit(15);    //Centaur Recoverable Attention
    l_ecmdRc |= mci_data.clearBit(16);    //Centaur Special Attention
    l_ecmdRc |= mci_data.clearBit(17);    //Centaur Maintenance Complete
    l_ecmdRc |= mci_data.clearBit(20);    //SCOM Register Parity Error
    l_ecmdRc |= mci_data.clearBit(22);    //MCICFGQ Parity Error
    l_ecmdRc |= mci_data.clearBit(23);    //Replay Buffer Overrun
    l_ecmdRc |= mci_data.clearBit(24);    //Recoverable MC Internal Error
    l_ecmdRc |= mci_data.clearBit(25);    //Non-Recoverable MC Internal Error (xstop)
    l_ecmdRc |= mci_data.clearBit(26);    //PowerBus Protocol Error (xstop)
    l_ecmdRc |= mci_data.clearBit(27);    //MCS Command List Timeout due to PB
    l_ecmdRc |= mci_data.clearBit(28);    //Multiple RCMD or CRESP active
    l_ecmdRc |= mci_data.clearBit(29);    //Inband Bar Hit with Incorrect TTYPE (xstop)
    l_ecmdRc |= mci_data.clearBit(30);    //Multiple Bar Hit (xstop)
    l_ecmdRc |= mci_data.clearBit(33);    //Invalid Foreign Bar Access (xstop)
    l_ecmdRc |= mci_data.clearBit(35);    //PowerBus Write Data Buffer CE
    l_ecmdRc |= mci_data.clearBit(36);    //PowerBus Write Data Buffer UE
    l_ecmdRc |= mci_data.clearBit(38);    //HA Illegal Consumer Access Error (xstop)
    l_ecmdRc |= mci_data.clearBit(39);    //HA Illegal Producer Access Error (xstop)
    l_ecmdRc |= mci_data.clearBit(40);    //MCS Channel Timeout Error
    if (l_ecmdRc)
    {
        FAPI_ERR("proc_cen_framelock: Error 0x%x setting up data buffers to mask MCI FIRs",
                 l_ecmdRc);
        l_rc.setEcmdError(l_ecmdRc);
        return l_rc;
    }

    l_rc = proc_cen_framelock_set_pu_mci_firmask_reg(i_pu_target, mci_data, mci_mask);
    if (l_rc)
    {
        FAPI_ERR("proc_cen_framelock: Error writing P8 MCI Fir Mask Register");
        return l_rc;
    }

    // No Bits are set in FIR ACT0

    // Set CEN MBI FIR ACT1
    l_ecmdRc |= mbi_data.flushTo0();
    l_ecmdRc |= mbi_data.setBit(4);     //Seqid OOO
    l_ecmdRc |= mbi_data.setBit(5);     //Replay Buffer CE
    l_ecmdRc |= mbi_data.setBit(10);    //CRC Performance Degradation
    l_ecmdRc |= mbi_data.setBit(16);    //Scom Register parity error
    l_ecmdRc |= mbi_data.copy(mbi_mask);
    if (l_ecmdRc)
    {
        FAPI_ERR("proc_cen_framelock: Error 0x%x setting up data buffers to set MBI FIR actions",
                 l_ecmdRc);
        l_rc.setEcmdError(l_ecmdRc);
        return l_rc;
    }

    l_rc = proc_cen_framelock_set_cen_mbi_firact1_reg(i_mem_target, mbi_data, mbi_mask);
    if (l_rc)
    {
        FAPI_ERR("proc_cen_framelock: Error writing Centaur MBI Fir Action1 Register");
        return l_rc;
    }

    // Set Centaur MBI FIR Mask
    l_ecmdRc |= mbi_data.flushTo0();
    l_ecmdRc |= mbi_data.setBit(0);     //Replay Timeout
    l_ecmdRc |= mbi_data.setBit(4);     //Seqid ooo
    l_ecmdRc |= mbi_data.setBit(5);     //Replay Buffer CE
    l_ecmdRc |= mbi_data.setBit(6);     //Replay Buffer UE
    l_ecmdRc |= mbi_data.setBit(8);     //MBI Internal Control Parity Error
    l_ecmdRc |= mbi_data.setBit(9);     //MBI Data Flow Parity Error
    l_ecmdRc |= mbi_data.setBit(10);    //CRC Performance Degradation
    l_ecmdRc |= mbi_data.setBit(16);    //SCOM Register parity
    l_ecmdRc |= mbi_data.setBit(19);    //MBICFGQ Parity Error
    l_ecmdRc |= mbi_data.setBit(20);    //Replay Buffer Overrun Error
    l_ecmdRc |= mbi_data.copy(mbi_mask);
    l_ecmdRc |= mbi_data.clearBit(0);     //Replay Timeout
    l_ecmdRc |= mbi_data.clearBit(4);     //Seqid ooo
    l_ecmdRc |= mbi_data.clearBit(5);     //Replay Buffer CE
    l_ecmdRc |= mbi_data.clearBit(6);     //Replay Buffer UE
    l_ecmdRc |= mbi_data.clearBit(8);     //MBI Internal Control Parity Error
    l_ecmdRc |= mbi_data.clearBit(9);     //MBI Data Flow Parity Error
    l_ecmdRc |= mbi_data.clearBit(10);    //CRC Performance Degradation
    l_ecmdRc |= mbi_data.clearBit(16);    //SCOM Register parity
    l_ecmdRc |= mbi_data.clearBit(19);    //MBICFGQ Parity Error
    l_ecmdRc |= mbi_data.clearBit(20);    //Replay Buffer Overrun Error
    if (l_ecmdRc)
    {
        FAPI_ERR("proc_cen_framelock: Error 0x%x setting up data buffers to mask MBI FIRs",
                 l_ecmdRc);
        l_rc.setEcmdError(l_ecmdRc);
        return l_rc;
    }

    l_rc = proc_cen_framelock_set_cen_mbi_firmask_reg(i_mem_target, mbi_data, mbi_mask);
    if (l_rc)
    {
        FAPI_ERR("proc_cen_framelock: Error writing Centaur MBI Fir Mask Register");
        return l_rc;
    }

      // set the init state attribute to DMI_ACTIVE
    uint8_t l_attr_mss_init_state;
    l_attr_mss_init_state=ENUM_ATTR_MSS_INIT_STATE_DMI_ACTIVE;
    l_rc = FAPI_ATTR_SET(ATTR_MSS_INIT_STATE, &i_mem_target, l_attr_mss_init_state);
    if(l_rc) return l_rc;

    // mark HWP exit
    FAPI_IMP("proc_cen_framelock: Exiting ...");
    return l_rc;
}

} // extern "C"
