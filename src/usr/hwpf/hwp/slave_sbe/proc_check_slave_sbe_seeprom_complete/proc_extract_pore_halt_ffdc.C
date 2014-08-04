/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_halt_ffdc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $Id: proc_extract_pore_halt_ffdc.C,v 1.2 2014/08/07 13:32:17 thi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_pore_halt_ffdc.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_pore_halt_ffdc.C
// *! DESCRIPTION : Extract halt-fail related FFDC for selected SBE/SLW errors
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_extract_pore_halt_ffdc.H>


// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// X Clock Adjust Set register bit/field definitions
const uint32_t X_CLK_ADJ_SET_REG_SYNC_BIT = 2;
const uint32_t X_CLK_ADJ_SET_REG_RLM_SELECT_BIT = 5;
const uint32_t X_CLK_ADJ_SET_REG_CMD_START_BIT = 6;
const uint32_t X_CLK_ADJ_SET_REG_CMD_END_BIT = 9;
const uint32_t X_CLK_ADJ_SET_REG_DATA_START_BIT = 21;
const uint32_t X_CLK_ADJ_SET_REG_DATA_END_BIT = 28;

const uint8_t X_CLK_ADJ_CMD_TYPE_READ = 0xE;


const uint64_t scan_ffdc_addr_arr[] =
{
    GENERIC_CLK_SYNC_CONFIG_0x00030000,
    GENERIC_OPCG_CNTL0_0x00030002,
    GENERIC_OPCG_CNTL1_0x00030003,
    GENERIC_OPCG_CNTL2_0x00030004,
    GENERIC_OPCG_CNTL3_0x00030005,
    GENERIC_CLK_REGION_0x00030006,
    GENERIC_CLK_SCANSEL_0x00030007,
    GENERIC_CLK_STATUS_0x00030008,
    GENERIC_CLK_ERROR_0x00030009,
    GENERIC_CLK_SCANDATA0_0x00038000
};

const uint64_t instruct_start_ffdc_addr_arr[] =
{
    EX_PERV_TCTL0_R_MODE_0x10013001,
    EX_PERV_TCTL0_R_STAT_0x10013002,
    EX_PERV_TCTL0_POW_STAT_0x10013004,
    EX_PCNE_REG0_HOLD_OUT_0x1001300D,
    EX_PERV_THREAD_ACTIVE_0x1001310E,
    EX_CORE_FIR_0x10013100,
    EX_SPATTN_0x10040004,
    PM_SPECIAL_WKUP_FSP_0x100F010B,
    PM_SPECIAL_WKUP_OCC_0x100F010C,
    PM_SPECIAL_WKUP_PHYP_0x100F010D,
    EX_OHA_RO_STATUS_REG_0x1002000B,
    EX_OHA_MODE_REG_RWx1002000D,
    EX_OHA_ARCH_IDLE_STATE_REG_RWx10020011,
    EX_OHA_RO_STATUS_REG_0x1002000B,
    EX_OHA_AISS_IO_REG_0x10020014,   
    EX_GP3_0x100F0012,
    EX_PMGP0_0x100F0100,
    EX_PMGP1_0x100F0103,
    EX_PFET_CTL_REG_0x100F0106,
    EX_PFET_STAT_REG_0x100F0107,
    EX_PFET_CTL_REG_0x100F010E,
    EX_PMSTATEHISTPERF_REG_0x100F0113,
    EX_PCBS_FSM_MONITOR1_REG_0x100F0170,
    EX_PCBS_FSM_MONITOR2_REG_0x100F0171,   
    EX_PMErr_REG_0x100F0109,   
    EX_PCBS_DPLL_STATUS_REG_100F0161,   
    EX_DPLL_CPM_PARM_REG_0x100F0152        
};

const uint64_t dpll_lock_ffdc_addr_arr[] =
{
    EX_DPLL_CPM_PARM_REG_0x100F0152,
    EX_PMGP0_0x100F0100,
    EX_GP3_0x100F0012
};


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


/**
 * proc_extract_pore_halt_ffdc_unicast - collect FFDC data for one chiplet
 *
 * @param[in]   i_target         - target for FFDC collection
 * @param[in]   i_halt_type      - FFDC type, for logging
 * @param[in]   i_ffdc_addrs     - FFDC addresses to log
 * @param[in]   i_base_scom_addr - base SCOM address (XX000000) to apply
 *                                 to entries of i_ffdc_addrs_log
 * @param[out]  o_rc             - target return code for extra FFDC
 *
 * @retval      fapi::ReturnCode = SUCCESS
 */
fapi::ReturnCode proc_extract_pore_halt_ffdc_unicast(const fapi::Target & i_target,
                                                     const por_halt_type_t i_halt_type,
                                                     const std::vector<uint64_t> * i_ffdc_addrs,
                                                     const uint32_t i_base_scom_addr,
                                                     fapi::ReturnCode & o_rc)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;

    // FFDC collection
    ecmdDataBufferBase ffdc_reg_addrs(64*(i_ffdc_addrs->size()));
    ecmdDataBufferBase ffdc_reg_data(64*(i_ffdc_addrs->size()));
    uint8_t dw_index = 0;

    FAPI_INF("proc_extract_pore_halt_ffdc_unicast: Start (target = %s, base = 0x%08X)",
             i_target.toEcmdString(), i_base_scom_addr);

    do
    {
        rc_ecmd |= ffdc_reg_addrs.flushTo1();
        rc_ecmd |= ffdc_reg_data.flushTo1();
        if (rc_ecmd)
        {
            FAPI_ERR("proc_extract_pore_halt_ffdc_unicast: Error %x flushing FFDC data buffers", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        for (std::vector<uint64_t>::const_iterator i = i_ffdc_addrs->begin();
             i != i_ffdc_addrs->end();
             i++)
        {
            ecmdDataBufferBase data(64);
            uint32_t scom_addr = (uint32_t) (*i);
            scom_addr &= 0x0FFFFFFF;
            scom_addr += i_base_scom_addr;

            FAPI_DBG("proc_extract_pore_halt_ffdc_unicast: Dumping 0x%08X on %s",
                     scom_addr, i_target.toEcmdString());

            // explicitly ignore return code, attempt to collect all FFDC registers
            rc = fapiGetScom(i_target, scom_addr, data);
            rc_ecmd |= ffdc_reg_addrs.setDoubleWord(dw_index, scom_addr);
            if (rc.ok())
            {
                rc_ecmd |= ffdc_reg_data.setDoubleWord(dw_index, data.getDoubleWord(0));
            }
            else
            {
                rc = fapi::FAPI_RC_SUCCESS;
            }

            if (rc_ecmd)
            {
                FAPI_ERR("proc_extract_pore_halt_ffdc_unicast: Error %x forming FFDC data buffers", rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
            dw_index++;
        }
        if (!rc.ok())
        {
            break;
        }

    } while(0);

    const fapi::Target & TARGET = i_target;
    const por_halt_type_t & PORE_HALT_TYPE = i_halt_type;
    const ecmdDataBufferBase & FFDC_ADDRESSES = ffdc_reg_addrs;
    const ecmdDataBufferBase & FFDC_DATA = ffdc_reg_data;
    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PROC_EXTRACT_PORE_HALT_FFDC);

    FAPI_INF("proc_extract_pore_halt_ffdc_unicast: End");
    return rc;
}


/**
 * proc_extract_pore_halt_ffdc_skew_adjust - collect FFDC data for XBUS skew adjust halt
 *
 * @param[in]   i_target         - target for FFDC collection
 * @param[in]   i_halt_type      - FFDC type, for logging
 * @param[out]  o_rc             - target return code for extra FFDC
 *
 * @retval      fapi::ReturnCode = SUCCESS
 */
fapi::ReturnCode proc_extract_pore_halt_ffdc_skew_adjust(const fapi::Target & i_target,
                                                         const por_halt_type_t i_halt_type,
                                                         fapi::ReturnCode & o_rc)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;

    // FFDC collection
    const uint8_t READ_REGS = 16;
    ecmdDataBufferBase ffdc_reg_addrs(64*READ_REGS);
    ecmdDataBufferBase ffdc_reg_data(64*READ_REGS);

    FAPI_INF("proc_extract_pore_halt_ffdc_skew_adjust: Start (target = %s)",
             i_target.toEcmdString());

    for (uint8_t dw_index = 0; dw_index < READ_REGS; dw_index++)
    {
        ecmdDataBufferBase data(64);
        bool iter_valid = true;

        // write set register with sync bit asserted
        rc_ecmd |= data.setBit(X_CLK_ADJ_SET_REG_SYNC_BIT);
        rc_ecmd |= data.setBit(X_CLK_ADJ_SET_REG_RLM_SELECT_BIT);
        rc_ecmd |= data.insertFromRight(
            X_CLK_ADJ_CMD_TYPE_READ,
            X_CLK_ADJ_SET_REG_CMD_START_BIT,
            (X_CLK_ADJ_SET_REG_CMD_END_BIT-
             X_CLK_ADJ_SET_REG_CMD_START_BIT+1));
        rc_ecmd |= data.insertFromRight(
            dw_index,
            X_CLK_ADJ_SET_REG_DATA_START_BIT,
            (X_CLK_ADJ_SET_REG_DATA_END_BIT-
             X_CLK_ADJ_SET_REG_DATA_START_BIT+1));
        if (rc_ecmd)
        {
            FAPI_ERR("proc_extract_pore_halt_ffdc_skew_adjust: Error %x forming X CLK Adjust Set register data buffer (set)",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        
        rc = fapiPutScom(i_target, X_CLK_ADJ_SET_0x040F0016, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_extract_pore_halt_ffdc_skew_adjust: Error from fapiPutScom (X_CLK_ADJ_SET_0x040F0016)");
            iter_valid = false;
        }

        // write set register with sync bit cleared
        rc_ecmd |= data.clearBit(X_CLK_ADJ_SET_REG_SYNC_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_extract_pore_halt_ffdc_skew_adjust: Error %x forming X CLK Adjust Set register data buffer (clear)",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        rc = fapiPutScom(i_target, X_CLK_ADJ_SET_0x040F0016, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_extract_pore_halt_ffdc_skew_adjust: Error from fapiPutScom (X_CLK_ADJ_SET_0x040F0016)");
            iter_valid = false;
        }

        rc = fapiGetScom(i_target, X_CLK_ADJ_DAT_REG_0x040F0015, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_extract_pore_halt_ffdc_skew_adjust: Error from fapiGetScom (X_CLK_ADJ_DAT_REG_0x040F0015)");
            iter_valid = false;
        }

        rc_ecmd |= ffdc_reg_addrs.setDoubleWord(dw_index, dw_index);
        if (iter_valid)
        {
            rc_ecmd |= ffdc_reg_data.setDoubleWord(dw_index, data.getDoubleWord(0));
        }
        else
        {
            rc_ecmd |= ffdc_reg_data.setDoubleWord(dw_index, 0xFFFFFFFFFFFFFFFFULL);
            rc = fapi::FAPI_RC_SUCCESS;
        }
        if (rc_ecmd)
        {
            FAPI_ERR("proc_extract_pore_halt_ffdc_skew_adjust: Error %x forming FFDC data buffers", rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
    }

    const fapi::Target & TARGET = i_target;
    const por_halt_type_t & PORE_HALT_TYPE = i_halt_type;
    const ecmdDataBufferBase & FFDC_ADDRESSES = ffdc_reg_addrs;
    const ecmdDataBufferBase & FFDC_DATA = ffdc_reg_data;
    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PROC_EXTRACT_PORE_HALT_FFDC);

    FAPI_INF("proc_extract_pore_halt_ffdc_skew_adjust: End");
    return rc;
}



/**
 * proc_extract_pore_halt_ffdc - HWP entry point, log PORE fail FFDC
 *
 * @param[in]   i_pore_state - struct holding PORE state
 * @param[in]   i_halt_type  - FFDC type to collect
 * @param[in]   i_offset     - offset to apply to FFDC registers for
 *                             i_halt_type (constant/value of PORE
 *                             pervasive base registers/none)
 * @param[out]  o_rc         - target return code for extra FFDC
 *
 * @retval      fapi::ReturnCode = SUCCESS
 */
fapi::ReturnCode proc_extract_pore_halt_ffdc(const por_base_state & i_pore_state,
                                             const por_halt_type_t i_halt_type,
                                             const por_ffdc_offset_t i_offset,
                                             fapi::ReturnCode & o_rc)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;

    // FFDC register collection pointer
    const std::vector<uint64_t> *p = NULL;
    std::vector<uint64_t> scan_ffdc_addr(scan_ffdc_addr_arr, scan_ffdc_addr_arr + (sizeof(scan_ffdc_addr_arr) / sizeof(scan_ffdc_addr_arr[0])));
    std::vector<uint64_t> instruct_start_ffdc_addr(instruct_start_ffdc_addr_arr, instruct_start_ffdc_addr_arr + (sizeof(instruct_start_ffdc_addr_arr) / sizeof(instruct_start_ffdc_addr_arr[0])));
    std::vector<uint64_t> dpll_lock_ffdc_addr(dpll_lock_ffdc_addr_arr, dpll_lock_ffdc_addr_arr + (sizeof(dpll_lock_ffdc_addr_arr) / sizeof(dpll_lock_ffdc_addr_arr[0])));

    FAPI_INF("proc_extract_pore_halt_ffdc: Start");

    do
    {
        const fapi::Target & TARGET = i_pore_state.target;
        const por_halt_type_t & PORE_HALT_TYPE = i_halt_type;

        if (i_halt_type == PORE_HALT_SKEW_ADJUST_FAIL)
        {
            FAPI_DBG("proc_extract_pore_halt_ffdc: Collecting skew adjust FFDC");
            if (i_pore_state.target.getType() == fapi::TARGET_TYPE_PROC_CHIP)
            {
                rc = proc_extract_pore_halt_ffdc_skew_adjust(i_pore_state.target,
                                                             i_halt_type,
                                                             o_rc);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_extract_pore_halt_ffdc: Error from proc_extract_pore_halt_ffdc_skew_adjust");
                    break;
                }
            }
            else
            {
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_HALT_FFDC_BAD_TYPE);
                break;
            }
        }
        else if (i_halt_type == PORE_HALT_FIR_FAIL)
        {
            FAPI_DBG("proc_extract_pore_halt_ffdc: Collecting FIR FFDC");
            if (i_pore_state.target.getType() == fapi::TARGET_TYPE_PROC_CHIP)
            {
                FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PROC_FIR_FFDC);
                break;
            }
            else if (i_pore_state.target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP)
            {
                FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_CEN_FIR_FFDC);
                break;
            }
            else
            {
                FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_HALT_FFDC_BAD_TYPE);
                break;
            }
        }
        else
        {
            // set pointer based on halt type
            switch (i_halt_type)
            {
                case PORE_HALT_SCAN_FAIL:
                case PORE_HALT_SCAN_FLUSH_FAIL:
                case PORE_HALT_ARRAYINIT_FAIL:
                    p = &(scan_ffdc_addr);
                    FAPI_DBG("proc_extract_pore_halt_ffdc: Pointer set to scan FFDC array");
                    break;
                case PORE_HALT_INSTRUCT_FAIL:
                    p = &(instruct_start_ffdc_addr);
                    FAPI_DBG("proc_extract_pore_halt_ffdc: Pointer set to instruction start FFDC array");
                    break;
                case PORE_HALT_DPLL_LOCK_FAIL:
                    p = &(dpll_lock_ffdc_addr);
                    FAPI_DBG("proc_extract_pore_halt_ffdc: Pointer set to DPLL lock FFDC array");
                    break;
                default:
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_HALT_FFDC_BAD_TYPE);
                    break;
            }
            if (!rc.ok())
            {
                break;
            }
            
            // determine chiplet ID offset to apply to FFDC registers collected
            // for this halt type
            uint32_t chiplet_id = i_offset;
            if ((i_offset == POR_FFDC_OFFSET_USE_P0) ||
                (i_offset == POR_FFDC_OFFSET_USE_P1))
            {
                chiplet_id = 0x0;
                // chiplet addressed is stored in one of the PORE pervasive base registers
                // use the value of that register to form the chiplet portion of the FFDC
                // SCOM addresses
                rc_ecmd |= i_pore_state.engine_state.extractPreserve(
                    &chiplet_id,
                    (64*(i_offset)) + 24,
                    8,
                    0);
                
                if (rc_ecmd)
                {
                    FAPI_ERR("proc_extract_pore_halt_ffdc: Error %x extracting P%d pervasive base content",
                             rc_ecmd, (i_offset == POR_FFDC_OFFSET_USE_P0)?(0):(1));
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
            }
            
            // multicast address
            // only support EX multicast unrolling for processor chip targets
            if (chiplet_id & 0x40000000)
            {
                uint8_t mc_group = (chiplet_id >> 24) & 0x3;
                std::vector<fapi::Target> ex_chiplets;
            
                if ((i_pore_state.target.getType() == fapi::TARGET_TYPE_PROC_CHIP) &&
                    ((mc_group == 1) || (mc_group == 2)))
                {
                    // determine set of EX chiplets
                    rc = fapiGetChildChiplets(i_pore_state.target,
                                              fapi::TARGET_TYPE_EX_CHIPLET,
                                              ex_chiplets,
                                              fapi::TARGET_STATE_FUNCTIONAL);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_extract_pore_halt_ffdc: Error from fapiGetChildChiplets");
                        break;
                    }
            
                    // collect FFDC for chiplets which are part of the multicast group
                    for (std::vector<fapi::Target>::iterator i = ex_chiplets.begin();
                         i != ex_chiplets.end();
                         i++)
                    {
                        ecmdDataBufferBase mc_config_data(64);
                        uint64_t mc_group_addr = (mc_group == 1)?(EX_MCGR2_0x100F0002):(EX_MCGR3_0x100F0003);
                        uint8_t mc_group_listen;
            
                        rc = fapiGetScom(*i, mc_group_addr, mc_config_data);
                        if (!rc.ok())
                        {
                            FAPI_ERR("proc_extract_pore_halt_ffdc: Error from fapiGetScom (EX_MCGR%d_0x%08llX)",
                                     mc_group+1, mc_group_addr);
                            break;
                        }
            
                        rc_ecmd |= mc_config_data.extractToRight(&mc_group_listen, 3, 3);
                        if (rc_ecmd)
                        {
                            FAPI_ERR("proc_extract_pore_halt_ffdc: Error %x extracting multicast group listen configuration", rc_ecmd);
                            rc.setEcmdError(rc_ecmd);
                            break;
                        }
            
                        if (mc_group_listen == mc_group)
                        {
                            rc = proc_extract_pore_halt_ffdc_unicast(*i, i_halt_type, p, 0x10000000, o_rc);
                            if (!rc.ok())
                            {
                                if (!rc.ok())
                                {
                                    FAPI_ERR("proc_extract_pore_halt_ffdc: Error from proc_extract_pore_halt_ffdc_unicast");
                                    break;
                                }
                            }
                        }
                        else
                        {
                            FAPI_INF("proc_extract_pore_halt_ffdc: Skipping %s, not part of multicast group",
                                     i->toEcmdString());
                        }
                    }
                    if (!rc.ok())
                    {
                        break;
                    }
                }
                else
                {
                    FAPI_ERR("proc_extract_halt_ffdc: Unsupported multicast extraction for target: %s, group: %d",
                             i_pore_state.target.toEcmdString(), mc_group);
                    const uint8_t & CHIPLET_ID = chiplet_id;
                    const uint8_t & MC_GROUP = mc_group;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_HALT_FFDC_BAD_MULTICAST);
                    break;
                }
            }
            // unicast address
            else
            {
                rc = proc_extract_pore_halt_ffdc_unicast(i_pore_state.target, i_halt_type, p, chiplet_id, o_rc);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_extract_pore_halt_ffdc: Error from proc_extract_pore_halt_ffdc_unicast");
                    break;
                }
            }
        }
    } while(0);

    FAPI_INF("proc_extract_pore_halt_ffdc: End");
    return rc;
}


} // extern "C"
