//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/dmi_training/proc_cen_framelock.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: proc_cen_framelock.C,v 1.2 2012/01/06 23:44:48 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_cen_framelock.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_cen_framelock.H
// *! DESCRIPTION : Run framelock and FRTL (FAPI)
// *!
// *! OWNER NAME  : Irving Baysah           Email: baysah@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_cen_framelock.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: utility subroutine to create proper SCOM address for P8 MCI 
//           resource given base SCOM address (associated with MCS0) and target
//           MCS chiplet offset
// parameters: i_base_addr  => base SCOM address (associated with MCS0) for
//                             desired MCI resource
//             i_mcs        => MCS target chiplet offset to operate on
//             o_xlate_addr => translated SCOM address for desired MCI resource
// returns: FAPI_RC_SUCCESS if address translation was successful,
//          else RC_PROC_CEN_FRAMELOCK_INTERNAL_ERR if MCS target chiplet offset
//                                                  is out of range or base
//                                                  address is unsupported
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_translate_mci_scom_addr(
    const uint32_t& i_base_addr,
    const uint8_t& i_mcs,
    uint32_t& o_xlate_addr)
{
    fapi::ReturnCode rc;

    // validate that MCS offset is in range
    if (i_mcs > PROC_CEN_FRAMELOCK_MAX_MCS_OFFSET)
    {
        FAPI_ERR(
            "proc_cen_framelock_translate_mci_scom_addr: Out of range value %d presented for MCS offset argument value!",
            i_mcs);
        const uint8_t & ERR_DATA = i_mcs;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_INTERNAL_ERR);
    }
    // check that base address matches one of the supported addresses
    else if ((i_base_addr != MCI_FIR_0x02011840) &&
             (i_base_addr != MCI_CFG_0x0201184A) &&
             (i_base_addr != MCI_STAT_0x0201184B))
    {
        FAPI_ERR(
            "proc_cen_framelock_translate_mci_scom_addr: Unsupported base SCOM address value 0x%x presented for translation!",
            i_base_addr);
        const uint32_t & ERR_DATA = i_base_addr;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_INTERNAL_ERR);
    }
    else
    {
        // perform SCOM address translation
        o_xlate_addr = i_base_addr;
        
        // add base offset for MC
        o_xlate_addr += ((i_mcs / 2) * 0x100);
        if ((i_mcs / 2) > 1)
        {
            o_xlate_addr += 0x200;
        }
        
        // add offset for odd MCS numbers
        if (i_mcs % 2)
        {
            o_xlate_addr += 0x80;
        }
    }
    return rc;
}

//------------------------------------------------------------------------------
// function: utility subroutine to clear the Centaur MBI Status Register
// parameters: i_mem_target  => Centaur target
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_clear_cen_mbi_stat_reg(
    const fapi::Target& i_mem_target)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase zero_data(64);
    
    FAPI_DBG("proc_cen_framelock_clear_cen_mbi_stat_reg: Start");
    
    rc = fapiPutScom(i_mem_target, MBI_STAT_0x0201080B, zero_data);
    
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_clear_cen_mbi_stat_reg: fapiPutScom error");
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
    
    FAPI_DBG("proc_cen_framelock_get_cen_mbi_stat_reg: Start");
    
    rc = fapiGetScom(i_mem_target, MBI_STAT_0x0201080B, o_data);
    
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_get_cen_mbi_stat_reg: fapiGetScom error");
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
    
    FAPI_DBG("proc_cen_framelock_clear_cen_mbi_fir_reg: Start");
    
    rc = fapiPutScom(i_mem_target, MBI_FIR_0x02010800, zero_data);
    
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_clear_cen_mbi_fir_reg: fapiPutScom error");
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
    
    FAPI_DBG("proc_cen_framelock_get_cen_mbi_fir_reg: Start");
    
    rc = fapiGetScom(i_mem_target, MBI_FIR_0x02010800, o_data);
    
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_get_cen_mbi_fir_reg: fapiGetScom error");
    }
    
    return rc;
}

//------------------------------------------------------------------------------
// function: utility subroutine to clear the P8 MCI Status Register
// parameters: i_pu_target  => P8 target
//             i_args       => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_clear_pu_mci_stat_reg(
    const fapi::Target& i_pu_target,
    const proc_cen_framelock_args& i_args)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase zero_data(64);
    uint32_t mci_xlate_scom_addr = 0;
    
    FAPI_DBG("proc_cen_framelock_clear_pu_mci_stat_reg: Start");
    rc = proc_cen_framelock_translate_mci_scom_addr(MCI_STAT_0x0201184B,
                                                    i_args.mcs_pu,
                                                    mci_xlate_scom_addr);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_clear_pu_mci_stat_reg: xlate error");
    }
    else
    {
        rc = fapiPutScom(i_pu_target, mci_xlate_scom_addr, zero_data);
        
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_clear_pu_mci_stat_reg: fapiPutScom error");
        }
    }
    
    return rc;    
}

//------------------------------------------------------------------------------
// function: utility subroutine to get the P8 MCI Status Register
// parameters: i_pu_target  => P8 target
//             i_args       => proc_cen_framelock HWP argumemt structure
//             o_data       => Output data
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_get_pu_mci_stat_reg(
    const fapi::Target& i_pu_target,
    const proc_cen_framelock_args& i_args,
    ecmdDataBufferBase& o_data)
{
    fapi::ReturnCode rc;
    uint32_t mci_xlate_scom_addr = 0;
    
    FAPI_DBG("proc_cen_framelock_get_pu_mci_stat_reg: Start");
    rc = proc_cen_framelock_translate_mci_scom_addr(MCI_STAT_0x0201184B,
                                                    i_args.mcs_pu,
                                                    mci_xlate_scom_addr);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_get_pu_mci_stat_reg: xlate error");
    }
    else
    {
        rc = fapiGetScom(i_pu_target, mci_xlate_scom_addr, o_data);
        
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_get_pu_mci_stat_reg: fapiGetScom error");
        }
    }
    
    return rc;    
}

//------------------------------------------------------------------------------
// function: utility subroutine to clear the P8 MCI FIR Register
// parameters: i_pu_target  => P8 target
//             i_args       => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_clear_pu_mci_fir_reg(
    const fapi::Target& i_pu_target,
    const proc_cen_framelock_args& i_args)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase zero_data(64);
    uint32_t mci_xlate_scom_addr = 0;
    
    FAPI_DBG("proc_cen_framelock_clear_pu_mci_fir_reg: Start");
    rc = proc_cen_framelock_translate_mci_scom_addr(MCI_FIR_0x02011840,
                                                    i_args.mcs_pu,
                                                    mci_xlate_scom_addr);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_clear_pu_mci_fir_reg: xlate error");
    }
    else
    {
        rc = fapiPutScom(i_pu_target, mci_xlate_scom_addr, zero_data);
        
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_clear_pu_mci_fir_reg: fapiPutScom error");
        }
    }
    
    return rc;
}

//------------------------------------------------------------------------------
// function: utility subroutine to get the P8 MCI FIR Register
// parameters: i_pu_target  => P8 target
//             i_args       => proc_cen_framelock HWP argumemt structure
//             o_data       => output data
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_get_pu_mci_fir_reg(
    const fapi::Target& i_pu_target,
    const proc_cen_framelock_args& i_args,
    ecmdDataBufferBase& o_data)
{
    fapi::ReturnCode rc;
    uint32_t mci_xlate_scom_addr = 0;
    
    FAPI_DBG("proc_cen_framelock_get_pu_mci_fir_reg: Start");
    rc = proc_cen_framelock_translate_mci_scom_addr(MCI_FIR_0x02011840,
                                                    i_args.mcs_pu,
                                                    mci_xlate_scom_addr);
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_get_pu_mci_fir_reg: xlate error");
    }
    else
    {
        rc = fapiGetScom(i_pu_target, mci_xlate_scom_addr, o_data);
        
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_get_pu_mci_fir_reg: fapiGetScom error");
        }
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
    
    FAPI_DBG("proc_cen_framelock_set_cen_mbi_cfg_reg: Start");
    rc = fapiPutScomUnderMask(i_mem_target, MBI_CFG_0x0201080A, i_data, i_mask);
    
    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_cen_mbi_cfg_reg: fapiPutScomUnderMask error");
    }
    
    return rc;    
}

//------------------------------------------------------------------------------
// function: utility subroutine to set the P8 MCI Config Register
// parameters: i_pu_target => P8 target
//             i_data      => Input data 
//             i_mask      => Input mask
//             i_args      => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_set_pu_mci_cfg_reg(
    const fapi::Target& i_pu_target,
    ecmdDataBufferBase& i_data,
    ecmdDataBufferBase& i_mask,
    const proc_cen_framelock_args& i_args)
{
    fapi::ReturnCode rc;
    uint32_t mci_xlate_scom_addr = 0;
    
    FAPI_DBG("proc_cen_framelock_set_pu_mci_cfg_reg: Start");
    rc = proc_cen_framelock_translate_mci_scom_addr(MCI_CFG_0x0201184A,
                                                    i_args.mcs_pu,
                                                    mci_xlate_scom_addr);

    if (rc)
    {
        FAPI_ERR("proc_cen_framelock_set_pu_mci_cfg_reg: xlate error");
    }
    else
    {
        rc = fapiPutScomUnderMask(i_pu_target, mci_xlate_scom_addr, i_data,
                                  i_mask);
        
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_set_pu_mci_cfg_reg: fapiPutScomUnderMask error");
        }
    }
    
    return rc;
}

//------------------------------------------------------------------------------
// function: utility subroutine to claer the P8 and Centaur Status/FIR Registers
// parameters: i_pu_target  => P8 target
//             i_mem_target => Centaur target 
//             i_args      => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_clear_stat_fir_regs(
    const fapi::Target& i_pu_target,
    const fapi::Target& i_mem_target,
    const proc_cen_framelock_args& i_args)
{
    fapi::ReturnCode rc;
    
    FAPI_DBG("proc_cen_framelock_clear_stat_fir_regs: Start");

    do
    {
        // Clear Centaur MBI Status Register
        rc = proc_cen_framelock_clear_cen_mbi_stat_reg(i_mem_target);

        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_clear_stat_fir_regs: Error from proc_cen_framelock_clear_cen_mbi_stat_reg");
            break;
        }

        // Clear Centaur MBI FIR Register
        rc = proc_cen_framelock_clear_cen_mbi_fir_reg(i_mem_target);
        
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_clear_stat_fir_regs: Error from proc_cen_framelock_clear_cen_mbi_fir_reg");
            break;
        }
        
        // Clear P8 MCI Status Register
        rc = proc_cen_framelock_clear_pu_mci_stat_reg(i_pu_target, i_args);
        
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_clear_stat_fir_regs: Error from proc_cen_framelock_clear_pu_mci_stat_reg");
            break;
        }

        // Clear P8 MCI FIR Register
        rc = proc_cen_framelock_clear_pu_mci_fir_reg(i_pu_target, i_args);
        
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_clear_stat_fir_regs: Error from proc_cen_framelock_clear_pu_mci_fir_reg");
            break;
        }
        
    } while(0);
    
    return rc;    
}

//------------------------------------------------------------------------------
// function: utility subroutine to initiate P8/Centaur framelock operation and
//           poll for completion
// parameters: i_pu_target  => P8 chip target
//             i_mem_target => Centaur chip target
//             i_args       => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if framelock sequence completes successfully,
//          RC_PROC_CEN_FRAMELOCK_INTERNAL_ERR
//              if internal program logic error is encountered,
//          RC_PROC_CEN_FRAMELOCK_FL_CEN_FIR_ERR
//          RC_PROC_CEN_FRAMELOCK_FL_P8_FIR_ERR
//              if MCI/MBI FIR is set during framelock operation, 
//          RC_PROC_CEN_FRAMELOCK_FL_CEN_FAIL_ERR
//          RC_PROC_CEN_FRAMELOCK_FL_P8_FAIL_ERR
//              if MCI/MBI indicates framelock operation failure
//          RC_PROC_CEN_FRAMELOCK_FL_TIMEOUT_ERR
//              if MCI/MBI does not post pass/fail indication after framelock
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
    ecmdDataBufferBase mbi_stat(64);
    ecmdDataBufferBase mbi_fir(64);
    ecmdDataBufferBase mci_stat(64);
    ecmdDataBufferBase mci_fir(64);

    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    FAPI_DBG("proc_cen_framelock_run_framelock: Starting framelock sequence ...");

    do
    {
        // Clear Centaur/P8 Status/FIR registers
        rc = proc_cen_framelock_clear_stat_fir_regs(i_pu_target, i_mem_target,
                                                    i_args);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Error clearing Centaur/P8 Status/FIR regs");
            break;
        }

        // If error state is set, force framelock bit in Centaur MBI
        // Configuration Register
        if (i_args.in_error_state)
        {
            FAPI_DBG("proc_cen_framelock_run_framelock: Writing Centaur MBI Configuration Register to force framelock ...");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(MBI_CFG_FORCE_FRAMELOCK_BIT);
            rc_ecmd |= data.copy(mask);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Error 0x%x setting up data buffers to force framelock",
                         rc_ecmd);
                rc = rc_ecmd;
                break;
            }
        
            rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data,
                                                        mask);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Error writing Centaur MBI Configuration Register to force framelock");
                break;
            }
        }

        // set channel init timeout value in P8 MCI Configuration Register
        FAPI_DBG("proc_cen_framelock_run_framelock: Writing P8 MCI Configuration Register to set channel init timeout value ...");
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
            rc = rc_ecmd;
            break;
        }
        
        rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask,
                                                   i_args);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Error writing P8 MCI Configuration register to set init timeout");
            break;
        }

        // start framelock
        FAPI_DBG("proc_cen_framelock_run_framelock: Writing P8 MCI Configuration Register to initiate framelock ...");
        rc_ecmd |= data.flushTo0();
        rc_ecmd |= data.setBit(MCI_CFG_START_FRAMELOCK_BIT);
        rc_ecmd |= data.copy(mask);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Error 0x%x setting up data buffers to initiate framelock",
                     rc_ecmd);
            rc = rc_ecmd;
            break;
        }
        
        rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask,
                                                   i_args);   
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_framelock: Error writing P8 MCI Configuration register to initiate framelock");
            break;
        }

        // poll until framelock operation is finished, a timeout is deemed to
        // have occurred, or an error is detected
        uint8_t polls = 0;
        
        while (1)
        {
            // Read Centaur MBI Status Register
            rc = proc_cen_framelock_get_cen_mbi_stat_reg(i_mem_target,
                                                         mbi_stat);        
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Error reading Centaur MBI Status Register");
                break;
            }
        
            // Read Centaur MBI FIR Register
            rc = proc_cen_framelock_get_cen_mbi_fir_reg(i_mem_target, mbi_fir);
        
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Error reading Centaur MBI FIR Register");
                break;
            }
        
            // Read P8 MCI Status Register
            rc = proc_cen_framelock_get_pu_mci_stat_reg(i_pu_target, i_args,
                                                        mci_stat);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Error reading P8 MCI Status Register");
                break;
            }
        
            // Read P8 MCI FIR Register
            rc = proc_cen_framelock_get_pu_mci_fir_reg(i_pu_target, i_args,
                                                       mci_fir);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Error reading P8 MCI FIR Register");
                break;
            }
        
            // Fail if any Centaur FIR bits are set
            if (mbi_fir.getDoubleWord(0))
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Framelock fail. Centaur MBI FIR bit on (0x%llx)",
                         mbi_fir.getDoubleWord(0));
                ecmdDataBufferBase & FIR_REG = mbi_fir;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_CEN_FIR_ERR);
                break;
            }
        
            // Fail if any P8 FIR bits are set
            if (mci_fir.getDoubleWord(0))
            {
                // TODO: seeing FIR[25] set on e8052+cen050 model due to flush
                // state parity error fixed in future P8 models, skip check for
                // now
                FAPI_ERR("TODO. IGNORING. proc_cen_framelock_run_framelock: Framelock fail. P8 MCI FIR bit on (0x%llx)",
                         mci_fir.getDoubleWord(0));
                //ecmdDataBufferBase & FIR_REG = mci_fir;
                //FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_P8_FIR_ERR);
                //break;
            }
        
            // Fail if Centaur FAIL bit set
            if (mbi_stat.isBitSet(MBI_STAT_FRAMELOCK_FAIL_BIT))
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Framelock fail. Centaur MBI_STAT_FRAMELOCK_FAIL_BIT set");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_CEN_FAIL_ERR);
                break;
            }
        
            // Fail if P8 FAIL bit set
            if (mci_stat.isBitSet(MCI_STAT_FRAMELOCK_FAIL_BIT))
            {
                FAPI_ERR("proc_cen_framelock_run_framelock: Framelock fail. P8 MCI_STAT_FRAMELOCK_FAIL_BIT set");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_P8_FAIL_ERR);
                break;
            }
        
            // Success if Centaur and P8 PASS bits set
            if ((mbi_stat.isBitSet(MBI_STAT_FRAMELOCK_PASS_BIT)) &&
                (mci_stat.isBitSet(MCI_STAT_FRAMELOCK_PASS_BIT)))
            {
                FAPI_DBG("proc_cen_framelock_run_framelock: Framelock completed successfully!");
                break;
            }
        
            if (polls >= PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS)
            {
                // Loop count has expired, timeout
                if (mbi_stat.isBitClear(MBI_STAT_FRAMELOCK_PASS_BIT))
                {
                    FAPI_ERR("proc_cen_framelock_run_framelock: Framelock timeout waiting on pass/fail indication in Centaur MBI Status Register!");
                }
                if (mci_stat.isBitClear(MCI_STAT_FRAMELOCK_PASS_BIT))
                {
                    FAPI_ERR("proc_cen_framelock_run_framelock: Framelock timeout waiting on pass/fail indication in P8 MCI Status Register!");
                }
                FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_TIMEOUT_ERR);
                break;
            }
            else
            {
                // polls left, keep waiting for pass/fail bits to come on
                polls++;
                FAPI_DBG("proc_cen_framelock_run_framelock: Loop %d of %d ...\n",
                         polls, PROC_CEN_FRAMELOCK_MAX_FRAMELOCK_POLLS);
            }
        }
    } while (0);
        
    return rc;
}

//------------------------------------------------------------------------------
// function: utility subroutine to initiate P8/Centaur FRTL (frame round trip
//           latency) determination and check for completion
// parameters: i_pu_target  => P8 chip target
//             i_mem_target => Centaur chip target
//             i_args       => proc_cen_framelock HWP argumemt structure
// returns: FAPI_RC_SUCCESS if FRTL sequence completes successfully,
//          RC_PROC_CEN_FRAMELOCK_INTERNAL_ERR
//              if internal program logic error is encountered,
//          RC_PROC_CEN_FRAMELOCK_FRTL_CEN_FIR_ERR
//          RC_PROC_CEN_FRAMELOCK_FRTL_P8_FIR_ERR
//              if MCI/MBI FIR is set during FRTL operation, 
//          RC_PROC_CEN_FRAMELOCK_FRTL_CEN_FAIL_ERR
//          RC_PROC_CEN_FRAMELOCK_FRTL_P8_FAIL_ERR
//              if MCI/MBI indicates FRTL operation failure,
//          RC_PROC_CEN_FRAMELOCK_FRTL_TIMEOUT_ERR
//              if MCI/MBI does not post pass/fail indication after FRTL
//              operation is started,
//          else FAPI getscom/putscom return code for failing SCOM operation
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock_run_frtl(
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

    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // mark function entry
    FAPI_DBG("proc_cen_framelock_run_frtl: Starting FRTL sequence ...");

    do
    {
        // Clear Centaur/P8 Status/FIR registers
        rc = proc_cen_framelock_clear_stat_fir_regs(i_pu_target, i_mem_target,
                                                    i_args);
        if (rc)
        {
            FAPI_ERR("proc_cen_framelock_run_frtl: Error clearing Centaur/P8 Status/FIR regs");
            break;
        }

        if (i_args.frtl_auto_not_manual)
        {
            // Auto mode
            
            // if error state is set, force FRTL bit in Centaur MBI
            // Configuration Register
            if (i_args.in_error_state)
            {
                FAPI_DBG("proc_cen_framelock_run_frtl: Writing Centaur MBI Configuration register to force FRTL ...");
                rc_ecmd |= data.flushTo0();
                rc_ecmd |= data.setBit(MBI_CFG_FORCE_FRTL_BIT);
                rc_ecmd |= data.copy(mask);
                if (rc_ecmd)
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to force FRTL",
                             rc_ecmd);
                    rc = rc_ecmd;
                    break;
                }
                
                rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data,
                                                            mask);
                if (rc)
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: Error writing Centaur MBI Configuration Register to force FRTL");
                    break;
                }
            }

            // set channel init timeout value in P8 MCI Configuration Register
            FAPI_DBG("proc_cen_framelock_run_frtl: Writing P8 MCI Configuration Register to set channel init timeout value ...");
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
                FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to set init timeout",
                         rc_ecmd);
                rc = rc_ecmd;
                break;
            }
            
            rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask,
                                                       i_args);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error writing P8 MCI Configuration register to set init timeout");
                break;
            }

            // start FRTL
            FAPI_DBG("proc_cen_framelock_run_frtl: Writing P8 MCI Configuration Register to initiate FRTL ...");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(MCI_CFG_START_FRTL_BIT);
            rc_ecmd |= data.copy(mask);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to initiate FRTL",
                         rc_ecmd);
                rc = rc_ecmd;
                break;
            }
            
            rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask,
                                                       i_args);   
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error writing P8 MCI Configuration register to initiate FRTL");
                break;
            }

            // Poll until FRTL operation is finished, a timeout is deemed to
            // have occurred, or an error is detected
            uint8_t polls = 0;
            
            while (1)
            {
                // Read Centaur MBI Status Register
                rc = proc_cen_framelock_get_cen_mbi_stat_reg(i_mem_target,
                                                             mbi_stat);
                if (rc)
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: Error reading Centaur MBI Status Register");
                    break;
                }
            
                // Read Centaur MBI FIR Register
                rc = proc_cen_framelock_get_cen_mbi_fir_reg(i_mem_target,
                                                            mbi_fir);
                if (rc)
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: Error reading Centaur MBI FIR Register");
                    break;
                }
            
                // Read P8 MCI Status Register
                rc = proc_cen_framelock_get_pu_mci_stat_reg(i_pu_target, i_args,
                                                            mci_stat);
                if (rc)
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: Error reading P8 MCI Status Register");
                    break;
                }
            
                // Read P8 MCI FIR Register
                rc = proc_cen_framelock_get_pu_mci_fir_reg(i_pu_target, i_args,
                                                           mci_fir);
                if (rc)
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: Error reading P8 MCI FIR Register");
                    break;
                }
                
                // Fail if any Centaur FIR bits are set
                if (mbi_fir.getDoubleWord(0))
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: FRTL fail (auto). Centaur MBI FIR bit on (0x%llx)",
                             mbi_fir.getDoubleWord(0));
                    ecmdDataBufferBase & FIR_REG = mbi_fir;
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_PROC_CEN_FRAMELOCK_FRTL_CEN_FIR_ERR);
                    break;
                }
            
                // Fail if any P8 FIR bits are set
                if (mci_fir.getDoubleWord(0))
                {
                    // TODO: seeing FIR[25] set on e8052+cen050 model due to
                    // flush state parity error fixed in future P8 models, skip
                    // check for now
                    FAPI_ERR("TODO. IGNORING. proc_cen_framelock_run_frtl: FRTL fail (auto). P8 MCI FIR bit on (0x%llx)",
                             mci_fir.getDoubleWord(0));
                    //ecmdDataBufferBase & FIR_REG = mci_fir;
                    //FAPI_SET_HWP_ERROR(rc,
                    //                   RC_PROC_CEN_FRAMELOCK_FRTL_P8_FIR_ERR);
                    //break;
                }
            
                // Fail if Centaur FAIL bit set
                if (mbi_stat.isBitSet(MBI_STAT_FRTL_FAIL_BIT))
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: FRTL fail (auto). Centaur MBI_STAT_FRTL_FAIL_BIT set");
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_PROC_CEN_FRAMELOCK_FRTL_CEN_FAIL_ERR);
                    break;
                }
            
                // Fail if P8 FAIL bit set
                if (mci_stat.isBitSet(MCI_STAT_FRTL_FAIL_BIT))
                {
                    FAPI_ERR("proc_cen_framelock_run_frtl: FRTL fail (auto). P8 MCI_STAT_FRTL_FAIL_BIT set");
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_PROC_CEN_FRAMELOCK_FRTL_P8_FAIL_ERR);
                    break;
                }
            
                // Success if Centaur and P8 PASS bits set
                if ((mbi_stat.isBitSet(MBI_STAT_FRTL_PASS_BIT)) &&
                    (mci_stat.isBitSet(MCI_STAT_FRTL_PASS_BIT)))
                {
                    FAPI_DBG("proc_cen_framelock_run_frtl: FRTL (auto) completed successfully!");
                    break;
                }
            
                if (polls >= PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS)
                {
                    // Loop count has expired, timeout
                    if (mbi_stat.isBitClear(MBI_STAT_FRTL_PASS_BIT))
                    {
                        FAPI_ERR("proc_cen_framelock_run_frtl: FRTL timeout (auto) waiting on pass/fail indication in Centaur MBI Status Register!");
                    }
                    if (mci_stat.isBitClear(MCI_STAT_FRTL_PASS_BIT))
                    {
                        FAPI_ERR("proc_cen_framelock_run_frtl: FRTL timeout (auto) waiting on pass/fail indication in P8 MCI Status Register!");
                    }
                    FAPI_SET_HWP_ERROR(rc,
                                       RC_PROC_CEN_FRAMELOCK_FRTL_TIMEOUT_ERR);
                    break;
                }
                else
                {
                    // polls left, keep waiting for pass/fail bits to come on
                    polls++;
                    FAPI_DBG("proc_cen_framelock_run_frtl: Loop %d of %d ...\n",
                             polls, PROC_CEN_FRAMELOCK_MAX_FRTL_POLLS);
                }
            }
        }
        else
        {
            // Manual mode

            // Disable auto FRTL mode & channel init timeout in Centaur MBI
            // Configuration Register
            FAPI_DBG("proc_cen_framelock_run_frtl: Writing Centaur MBI Configuration register to disable auto FRTL mode & channel init timeout ...");
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
                FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to disable Centaur auto FRTL mode",
                         rc_ecmd);
                rc = rc_ecmd;
                break;
            }
            
            rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data,
                                                        mask);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error writing Centaur MBI Configuration register to disable auto FRTL mode");
                break;
            }

            // write specified FRTL value into Centaur MBI Configuration
            // Register
            FAPI_DBG("proc_cen_framelock_run_frtl: Writing Centaur MBI Configuration register to set manual FRTL value ...");
            if (i_args.frtl_manual_mem > MBI_CFG_MANUAL_FRTL_FIELD_MASK)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Out of range value %d presented for Centaur manual FRTL argument value!",
                         i_args.frtl_manual_mem);
                const proc_cen_framelock_args & ARGS = i_args;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_INVALID_ARGS);
                break;
            }
            
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
                FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to set Centaur manual FRTL value",
                         rc_ecmd);
                rc = rc_ecmd;
                break;
            }
            
            rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data,
                                                        mask);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error writing Centaur MBI Configuration register to set manual FRTL value");
                break;
            }

            // write FRTL manual done bit into Centaur MBI Configuration
            // Register
            FAPI_DBG("proc_cen_framelock_run_frtl: Writing Centaur MBI Configuration register to set manual FRTL done bit ...");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(MBI_CFG_MANUAL_FRTL_DONE_BIT);
            rc_ecmd |= data.copy(mask);
            if (rc_ecmd)
            {
                FAPI_ERR( "proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to set Centaur manual FRTL done",
                          rc_ecmd);
                rc = rc_ecmd;
                break;
            }
            
            rc = proc_cen_framelock_set_cen_mbi_cfg_reg(i_mem_target, data,
                                                        mask);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error writing Centaur MBI Configuration register to set manual FRTL done");
                break;
            }

            // disable auto FRTL mode & channel init timeout in P8 MCI
            // Configuration Register
            FAPI_DBG("proc_cen_framelock_run_frtl: Writing P8 MCI Configuration register to disable auto FRTL mode & channel init timeout ...");
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
                FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to disable P8 auto FRTL mode",
                         rc_ecmd);
                rc = rc_ecmd;
                break;
            }
            
            rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask,
                                                       i_args);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error writing P8 MCI Configuration register to disable auto FRTL mode");
                break;
            }

            // write specified FRTL value into P8 MCI Configuration Register
            FAPI_DBG("proc_cen_framelock_run_frtl: Writing P8 MCI Configuration register to set manual FRTL value ...");
            if (i_args.frtl_manual_pu > MCI_CFG_MANUAL_FRTL_FIELD_MASK)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Out of range value 0x%x presented for P8 manual FRTL argument value!",
                         i_args.frtl_manual_pu);
                const proc_cen_framelock_args & ARGS = i_args;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_INVALID_ARGS);
                break;
            }
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
                FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to set P8 manual FRTL value",
                         rc_ecmd);
                rc = rc_ecmd;
                break;
            }
            
            rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask,
                                                       i_args);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error writing P8 MCI Configuration register to set manual FRTL value");
                break;
            }

            // write FRTL manual done bit into P8 MCI Configuration Register
            FAPI_DBG("proc_cen_framelock_run_frtl: Writing P8 MCI Configuration register to set manual FRTL done bit ...");
            rc_ecmd |= data.flushTo0();
            rc_ecmd |= data.setBit(MCI_CFG_MANUAL_FRTL_DONE_BIT);
            rc_ecmd |= data.copy(mask);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error 0x%x setting up data buffers to write P8 manual FRTL done",
                         rc_ecmd);
                rc = rc_ecmd;
                break;
            }
            
            rc = proc_cen_framelock_set_pu_mci_cfg_reg(i_pu_target, data, mask,
                                                       i_args);
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error writing P8 MCI Configuration register to set manual FRTL done");
                break;
            }
        
            // Read Centaur MBI FIR Register
            rc = proc_cen_framelock_get_cen_mbi_fir_reg(i_mem_target, mbi_fir);
    
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error reading Centaur MBI FIR Register");
                break;
            }

            // Read P8 MCI FIR Register
            rc = proc_cen_framelock_get_pu_mci_fir_reg(i_pu_target, i_args,
                                                       mci_fir);
    
            if (rc)
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: Error reading P8 MCI FIR Register");
                break;
            }

            // Fail if any Centaur FIR bits are set
            if (mbi_fir.getDoubleWord(0))
            {
                FAPI_ERR("proc_cen_framelock_run_frtl: FRTL fail (manual). Centaur MBI FIR bit on (0x%llx)",
                         mbi_fir.getDoubleWord(0));
                ecmdDataBufferBase & FIR_REG = mbi_fir;
                FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_CEN_FIR_ERR);
                break;
            }
    
            // Fail if any P8 FIR bits are set
            if (mci_fir.getDoubleWord(0))
            {
                // TODO: seeing FIR[25] set on e8052+cen050 model due to flush
                // state parity error fixed in future P8 models, skip check for
                // now
                FAPI_ERR("TODO. IGNORING. proc_cen_framelock_run_frtl: FRTL fail (manual). P8 MCI FIR bit on (0x%llx)",
                         mci_fir.getDoubleWord(0));
                //ecmdDataBufferBase & FIR_REG = mci_fir;
                //FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_FL_P8_FIR_ERR);
                //break;
            }
        }
        
    } while (0);
         
    return rc;
}

//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
fapi::ReturnCode proc_cen_framelock(const fapi::Target& i_pu_target,
                                    const fapi::Target& i_mem_target,
                                    const proc_cen_framelock_args& i_args)
{
    fapi::ReturnCode rc;

    // mark HWP entry
    FAPI_IMP("proc_cen_framelock: Entering ...");

    do
    {
        // validate arguments
        if (i_args.mcs_pu > PROC_CEN_FRAMELOCK_MAX_MCS_OFFSET)
        {
            FAPI_ERR("proc_cen_framelock: Out of range value %d presented for P8 MCS offset argument value!",
                     i_args.mcs_pu);
            const proc_cen_framelock_args & ARGS = i_args;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_INVALID_ARGS);
            break;
        }
    
        if (i_args.frtl_manual_mem > MBI_CFG_MANUAL_FRTL_FIELD_MASK)
        {
            FAPI_ERR("proc_cen_framelock: Out of range value %d presented for manual FRTL mem argument value!",
                     i_args.frtl_manual_mem);
            const proc_cen_framelock_args & ARGS = i_args;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_INVALID_ARGS);
            break;
        }
    
        if (i_args.frtl_manual_pu > MCI_CFG_MANUAL_FRTL_FIELD_MASK)
        {
            FAPI_ERR("proc_cen_framelock: Out of range value %d presented for manual FRTL pu argument value!",
                     i_args.frtl_manual_pu);
            const proc_cen_framelock_args & ARGS = i_args;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CEN_FRAMELOCK_INVALID_ARGS);
            break;
        }

        // execute framelock
        rc = proc_cen_framelock_run_framelock(i_pu_target, i_mem_target,
                                              i_args);
        if (rc)
        {
            break;
        }
        
        // execute FRTL
        rc = proc_cen_framelock_run_frtl(i_pu_target, i_mem_target, i_args);
        if (rc)
        {
            break;
        }
        
    } while (0);

    // mark HWP exit
    FAPI_IMP("proc_cen_framelock: Exiting ...");
    return rc;
}

} // extern "C"
