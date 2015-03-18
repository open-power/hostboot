/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_base_ffdc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
// $Id: proc_extract_pore_base_ffdc.C,v 1.3 2015/03/01 21:45:05 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_pore_base_ffdc.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_pore_base_ffdc.C
// *! DESCRIPTION : Log base FFDC for SBE/SLW errors
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *! BACKUP NAME : Johannes Koesters       Email: koesters@de.ibm.com
// *!
// *! Overview:
// *!   - Dump state of SBE/SLW engine
// *!   - Extract additional FFDC based on engine type
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p8_scom_addresses.H>
#include <proc_extract_pore_base_ffdc.H>
#include <proc_tp_collect_dbg_data.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


/**
 * proc_extract_pore_engine_state - HWP entry point, log PORE engine state
 *
 * @param[in]   i_pore_state     - struct holding PORE state
 * @param[in]   i_pore_sbe_state - struct holding PORE SBE specific state
 * @param[out]  o_rc             - target return code for extra FFDC
 *
 * @retval      fapi::ReturnCode = SUCCESS
 */
fapi::ReturnCode proc_extract_pore_base_ffdc(const por_base_state & i_pore_state,
                                             const por_sbe_base_state & i_pore_sbe_state,
                                             fapi::ReturnCode & o_rc)

{
    // return code
    fapi::ReturnCode rc;

    FAPI_INF("proc_extract_pore_base_ffdc: Start");

    do
    {
        // append to return code
        const fapi::Target & CHIP = i_pore_state.target;
        const por_engine_t & ENGINE = i_pore_state.engine;
        const bool & VIRTUAL = i_pore_state.is_virtual;
        const uint64_t & PORE_VITAL_REG = i_pore_state.vital_state.getDoubleWord(0);
        const uint64_t & PORE_STATUS_REG = i_pore_state.engine_state.getDoubleWord(PORE_STATUS_OFFSET);
        const uint64_t & PORE_CONTROL_REG = i_pore_state.engine_state.getDoubleWord(PORE_CONTROL_OFFSET);
        const uint64_t & PORE_RESET_REG = i_pore_state.engine_state.getDoubleWord(PORE_RESET_OFFSET);
        const uint64_t & PORE_ERR_MASK_REG = i_pore_state.engine_state.getDoubleWord(PORE_ERR_MASK_OFFSET);
        const uint64_t & PORE_P0_REG = i_pore_state.engine_state.getDoubleWord(PORE_P0_OFFSET);
        const uint64_t & PORE_P1_REG = i_pore_state.engine_state.getDoubleWord(PORE_P1_OFFSET);
        const uint64_t & PORE_A0_REG = i_pore_state.engine_state.getDoubleWord(PORE_A0_OFFSET);
        const uint64_t & PORE_A1_REG = i_pore_state.engine_state.getDoubleWord(PORE_A1_OFFSET);
        const uint64_t & PORE_TBL_BASE_REG = i_pore_state.engine_state.getDoubleWord(PORE_TBL_BASE_OFFSET);
        const uint64_t & PORE_EXE_TRIGGER_REG = i_pore_state.engine_state.getDoubleWord(PORE_EXE_TRIGGER_OFFSET);
        const uint64_t & PORE_CTR_REG = i_pore_state.engine_state.getDoubleWord(PORE_CTR_OFFSET);
        const uint64_t & PORE_D0_REG = i_pore_state.engine_state.getDoubleWord(PORE_D0_OFFSET);
        const uint64_t & PORE_D1_REG = i_pore_state.engine_state.getDoubleWord(PORE_D1_OFFSET);
        const uint64_t & PORE_IBUF0_REG = i_pore_state.engine_state.getDoubleWord(PORE_IBUF0_OFFSET);
        const uint64_t & PORE_IBUF1_REG = i_pore_state.engine_state.getDoubleWord(PORE_IBUF1_OFFSET);
        const uint64_t & PORE_DEBUG0_REG = i_pore_state.engine_state.getDoubleWord(PORE_DEBUG0_OFFSET);
        const uint64_t & PORE_DEBUG1_REG = i_pore_state.engine_state.getDoubleWord(PORE_DEBUG1_OFFSET);
        const uint64_t & PORE_STACK0_REG = i_pore_state.engine_state.getDoubleWord(PORE_STACK0_OFFSET);
        const uint64_t & PORE_STACK1_REG = i_pore_state.engine_state.getDoubleWord(PORE_STACK1_OFFSET);
        const uint64_t & PORE_STACK2_REG = i_pore_state.engine_state.getDoubleWord(PORE_STACK2_OFFSET);
        const uint64_t & PORE_IDFLAGS_REG = i_pore_state.engine_state.getDoubleWord(PORE_IDFLAGS_OFFSET);
        const uint64_t & PORE_SPRG0_REG = i_pore_state.engine_state.getDoubleWord(PORE_SPRG0_OFFSET);
        const uint64_t & PORE_MRR_REG = i_pore_state.engine_state.getDoubleWord(PORE_MRR_OFFSET);
        const uint64_t & PORE_I2CE0_REG = i_pore_state.engine_state.getDoubleWord(PORE_I2CE0_OFFSET);
        const uint64_t & PORE_I2CE1_REG = i_pore_state.engine_state.getDoubleWord(PORE_I2CE1_OFFSET);
        const uint64_t & PORE_I2CE2_REG = i_pore_state.engine_state.getDoubleWord(PORE_I2CE2_OFFSET);
        const uint64_t & PORE_PC = i_pore_state.pc;
        const uint64_t & PORE_RC = i_pore_state.rc;
        FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PROC_EXTRACT_PORE_BASE_FFDC_ENGINE_STATE);


        //
        // collect additional FFDC based on engine type
        //

        if (i_pore_state.target.getType() == fapi::TARGET_TYPE_PROC_CHIP)
        {
            if (i_pore_state.engine == SBE)
            {
                const uint64_t & PNOR_ECCB_STATUS = i_pore_sbe_state.pnor_eccb_status.getDoubleWord(0);
                const uint64_t & SEEPROM_ECCB_STATUS = i_pore_sbe_state.i2cm_eccb_status.getDoubleWord(0);
                const uint8_t & SOFT_ERROR_STATUS = i_pore_sbe_state.soft_err;
                const bool & ATTN_REPORTED = i_pore_sbe_state.reported_attn;
                if ((o_rc == fapi::RC_SBE_TRIGGER_WINKLE_HOSTBOOT_DID_NOT_RESPOND) ||
                    (o_rc == fapi::RC_SBE_TRIGGER_WINKLE_EX_DID_NOT_ENTER_WINKLE) ||
                    (o_rc == fapi::RC_SBE_TRIGGER_WINKLE_EX_WAKEUP_DID_NOT_HIT_GOTO) ||
                    (o_rc == fapi::RC_SBE_TRIGGER_WINKLE_EX_WAKEUP_DID_NOT_FINISH))
                {
                    FAPI_ERR("proc_extract_pore_base_ffdc: Collecting base FFDC for SBE deadman timer fail...");
                    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PROC_EXTRACT_PORE_BASE_FFDC_SBE_DEADMAN);
                }
                else
                {
                    FAPI_ERR("proc_extract_pore_base_ffdc: Collecting base FFDC for SBE non-deadman timer fail...");
                    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PROC_EXTRACT_PORE_BASE_FFDC_SBE);
                }
            }
            else
            {
                FAPI_ERR("proc_extract_pore_base_ffdc: Collecting base FFDC for SLW fail...");
                FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PROC_EXTRACT_PORE_BASE_FFDC_SLW);
            }
        }
    } while(0);

    FAPI_INF("proc_extract_pore_base_ffdc: End");
    return rc;
}


} // extern "C"
