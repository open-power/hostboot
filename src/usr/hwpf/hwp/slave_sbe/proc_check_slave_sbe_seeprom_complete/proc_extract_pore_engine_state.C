/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_extract_pore_engine_state.C $ */
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
// $Id: proc_extract_pore_engine_state.C,v 1.3 2014/08/07 15:04:41 thi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_extract_pore_engine_state.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_extract_pore_engine_state.C
// *! DESCRIPTION : Extract PORE (SBE/SLW) engine state
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *! BACKUP NAME : Johannes Koesters       Email: koesters@de.ibm.com
// *!
// *! Overview:
// *!   - Dump state of SBE/SLW engine
// *!
//------------------------------------------------------------------------------


#ifdef FAPIECMD
  #if FAPIECMD == 1
    #define PROC_EXTRACT_PORE_ENGINE_STATE_BUILD_POREVE 0
  #else
    #define PROC_EXTRACT_PORE_ENGINE_STATE_BUILD_POREVE 1
  #endif
#else
  #ifdef __HOSTBOOT_MODULE
    #define PROC_EXTRACT_PORE_ENGINE_STATE_BUILD_POREVE 1
  #else
    #define PROC_EXTRACT_PORE_ENGINE_STATE_BUILD_POREVE 0
  #endif
#endif


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_extract_pore_engine_state.H>
#include <p8_scom_addresses.H>
#include <proc_extract_sbe_rc.H>

#if PROC_EXTRACT_PORE_ENGINE_STATE_BUILD_POREVE == 1
  #include <poreve.H>
#endif


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint32_t SLW_VITAL_PIBMEM_OFFSET = 0x12;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


/**
 * proc_extract_pore_engine_state_sbe_ffdc - Extract SBE-specific engine state
 *
 * @param[in]   i_target         - target of chip with failed SBE
 * @param[out]  o_pore_sbe_state - PORE SBE-specific state/FFDC content
 *
 * @retval      fapi::ReturnCode = SUCCESS
 * @retval      fapi::ReturnCode = results of cfam/SCOM access
 */
fapi::ReturnCode proc_extract_pore_engine_state_sbe_ffdc(
    const fapi::Target & i_target,
    por_sbe_base_state & o_pore_sbe_state)
{
    // return codes
    fapi::ReturnCode rc;

    FAPI_DBG("proc_extract_pore_engine_state_sbe_ffdc: Start");

    do
    {
        // check cfam status register for any PIB errors
        ecmdDataBufferBase cfam_status(32);
        rc = fapiGetCfamRegister(i_target, CFAM_FSI_STATUS_0x00001007, cfam_status);
        if (rc)
        {
            FAPI_ERR("proc_extract_pore_engine_state_sbe_ffdc: Error from fapiGetCfamRegister (CFAM_FSI_STATUS_0x00001007)");
            break;
        }

        // bit 30 indicates SBE reported attention
        if (cfam_status.isBitSet(30))
        {
            FAPI_ERR("proc_extract_pore_engine_state_sbe_ffdc: SBE reported attention to CFAM Status register");
            o_pore_sbe_state.reported_attn = true;
        }

        // check ECCB engines (I2C/LPC) for UE/CE conditions
        // SLW does not use these engines to access main memory, so no need to check
        rc = fapiGetScom(i_target, PORE_ECCB_STATUS_REGISTER_READ_0x000C0002, o_pore_sbe_state.i2cm_eccb_status);
        if (rc)
        {
            FAPI_ERR("proc_extract_pore_engine_state_sbe_ffdc: Error from fapiGetScom (PORE_ECCB_STATUS_REGISTER_READ_0x000C00002)");
            break;
        }

        rc = fapiGetScom(i_target, LPC_STATUS_0x000B0002, o_pore_sbe_state.pnor_eccb_status);
        if (rc)
        {
            FAPI_ERR("proc_extract_pore_engine_state_sbe_ffdc: Error from fapiGetScom (LPC_STATUS_0x000B0002)");
            break;
        }

        // determine if either engine has reached threshold of > 128 CEs
        if (o_pore_sbe_state.i2cm_eccb_status.isBitSet(57))
        {
            o_pore_sbe_state.soft_err = eSOFT_ERR_I2CM;
        }

        if (o_pore_sbe_state.pnor_eccb_status.isBitSet(57))
        {
            if (o_pore_sbe_state.soft_err == eSOFT_ERR_I2CM)
            {
                o_pore_sbe_state.soft_err = eSOFT_ERR_BOTH;
            }
            else
            {
                o_pore_sbe_state.soft_err = eSOFT_ERR_PNOR;
            }
        }
    } while(0);

    FAPI_DBG("proc_extract_pore_engine_state_sbe_ffdc: End");
    return rc;
}


/**
 * proc_extract_pore_engine_state_hw - Extract PORE engine state from HW
 *
 * @param[in]   i_target       - target of chip with failed SBE/SLW engine
 * @param[in]   i_engine       - engine type (SBE/SLW)
 * @param[out]  o_vital_state  - data buffer to hold SBE/SLW vital state
 * @param[out]  o_engine_state - data buffer to hold engine FFDC state
 *
 * @retval      fapi::ReturnCode = SUCCESS
 * @retval      fapi::ReturnCode = results of cfam/SCOM access
 */
fapi::ReturnCode proc_extract_pore_engine_state_hw(
    const fapi::Target & i_target,
    const por_engine_t i_engine,
    ecmdDataBufferBase & o_vital_state,
    ecmdDataBufferBase & o_engine_state)
{
    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;

    FAPI_DBG("proc_extract_pore_engine_state_hw: Start");

    do
    {
        // collect SBE/SLW vital register value
        if (i_engine == SBE)
        {
            ecmdDataBufferBase cfam_vital_data(32);

            // collect from SBE vital HW register
            rc = fapiGetCfamRegister(i_target, CFAM_FSI_SBE_VITAL_0x0000281C, cfam_vital_data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_extract_pore_engine_state_hw: Error from fapiGetCfamRegister (CFAM_FSI_SBE_VITAL_0x0000281C)");
                break;
            }

            rc_ecmd |= o_vital_state.setWord(0, cfam_vital_data.getWord(0));
            rc_ecmd |= o_vital_state.setWord(1, 0x0);
            if (rc_ecmd)
            {
                FAPI_ERR("proc_extract_pore_engine_state_hw: Error %x forming SBE Vital FFDC data buffers",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        else
        {
            // collect from PIBMEM (virtual SLW vital state)
            rc = fapiGetScom(i_target,
                             PIBMEM0_0x00080000 + SLW_VITAL_PIBMEM_OFFSET,
                             o_vital_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_extract_pore_engine_state_hw: Error from fapiGetCfamRegister (CFAM_FSI_SBE_VITAL_0x0000281C)");
                break;
            }
        }

        // collect SBE/SLW engine state
        for (uint8_t offset = PORE_STATUS_OFFSET;
             offset < PORE_NUM_REGS;
             offset++)
        {
            ecmdDataBufferBase reg(64);
        
            rc = fapiGetScom(i_target,
                             (uint32_t) i_engine + offset,
                             reg);
            if (!rc.ok())
            {
                FAPI_ERR("proc_extract_pore_engine_state_hw: Error from fapiGetScom (0x%08X)",
                         (uint32_t) i_engine + offset);
                break;
            }

            rc_ecmd |= o_engine_state.setDoubleWord(offset, reg.getDoubleWord(0));
            if (rc_ecmd)
            {
                FAPI_ERR("proc_extract_pore_engine_state_hw: Error %x inserting engine FFDC data value (DW=%d)",
                         rc_ecmd, offset);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }
    } while(0);

    FAPI_DBG("proc_extract_pore_engine_state_hw: End");
    return rc;
}


/**
 * proc_extract_pore_engine_state_virtual - Extract PORE engine state from virtual engine
 *
 * @param[in]   i_target       - target of chip with failed SBE engine
 * @param[in]   i_poreve       - pointer to PoreVe object
 * @param[out]  o_vital_state  - data buffer to hold SBE vital state
 * @param[out]  o_engine_state - data buffer to hold engine FFDC state
 *
 * @retval      fapi::ReturnCode = SUCCESS
 * @retval      fapi::ReturnCode = RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_MODEL_ERROR
 * @retval      fapi::ReturnCode = RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_PIB_ERROR
 */
#if PROC_EXTRACT_PORE_ENGINE_STATE_BUILD_POREVE == 1
fapi::ReturnCode proc_extract_pore_engine_state_virtual(
    const fapi::Target & i_target,
    vsbe::PoreVe * i_poreve,
    ecmdDataBufferBase & o_vital_state,
    ecmdDataBufferBase & o_engine_state)
{
    // return codes
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    vsbe::ModelError me;

    FAPI_DBG("proc_extract_pore_engine_state_virtual: Start");

    do
    {
        // extract SBE vital state
        // - for processor chips, this should resolve to a getscom
        // - for Centaur, the state should be extracted from the virtual model
        uint64_t vital_data;
        int pib_rc;
        me = i_poreve->getscom(MBOX_SBEVITAL_0x0005001C, vital_data, pib_rc);
        if (me != vsbe::ME_SUCCESS)
        {
            FAPI_ERR("proc_extract_pore_engine_state_virtual: Model error %x extracting SBE vital state",
                     (int) me);
            const fapi::Target & CHIP = i_target;
            const uint32_t & MODEL_ERROR = (uint32_t) me;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_MODEL_ERROR);
            break;
        }
        else if (pib_rc)
        {
            FAPI_ERR("proc_extract_pore_engine_state_virtual: PIB error getting SBE vital state (error code %d)",
                     pib_rc);
            const fapi::Target & CHIP = i_target;
            const int & PIB_ERROR = pib_rc;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_PIB_ERROR);
            break;
        }
        rc_ecmd = o_vital_state.setDoubleWord(0, vital_data);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_extract_pore_engine_state_virtual: Error %x inserting SBE vital FFDC data value",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // extract engine state from model
        vsbe::PoreState ve_state;
        me = i_poreve->iv_pore.extractState(ve_state);
        if (me != vsbe::ME_SUCCESS)
        {
            FAPI_ERR("proc_extract_pore_engine_state_virtual: Model error %x extracting virtual engine state",
                     (int) me);
            const fapi::Target & CHIP = i_target;
            const uint32_t & MODEL_ERROR = (uint32_t) me;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_MODEL_ERROR);
            break;
        }

        uint64_t status;
        ve_state.get(vsbe::PORE_STATUS, status);
        uint64_t control;
        ve_state.get(vsbe::PORE_CONTROL, control);
        uint64_t reset;
        ve_state.get(vsbe::PORE_RESET, reset);
        uint64_t table_base;
        ve_state.get(vsbe::PORE_TABLE_BASE_ADDR, table_base);
        uint64_t ibuf0, ibuf1;
        ve_state.get(vsbe::PORE_IBUF_01, ibuf0);
        ve_state.get(vsbe::PORE_IBUF_2, ibuf1);
        uint64_t dbg0, dbg1;
        ve_state.get(vsbe::PORE_DBG0, dbg0);
        ve_state.get(vsbe::PORE_DBG1, dbg1);
        uint64_t stack0, stack1, stack2;
        ve_state.get(vsbe::PORE_PC_STACK0, stack0);
        ve_state.get(vsbe::PORE_PC_STACK1, stack1);
        ve_state.get(vsbe::PORE_PC_STACK2, stack2);
        uint64_t mrr;
        ve_state.get(vsbe::PORE_MEM_RELOC, mrr);
        uint64_t i2c_e0, i2c_e1, i2c_e2;
        ve_state.get(vsbe::PORE_I2C_E0_PARAM, i2c_e0);
        ve_state.get(vsbe::PORE_I2C_E1_PARAM, i2c_e1);
        ve_state.get(vsbe::PORE_I2C_E2_PARAM, i2c_e2);

        rc_ecmd |= o_engine_state.setDoubleWord(PORE_STATUS_OFFSET, status);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_CONTROL_OFFSET, control);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_RESET_OFFSET, reset);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_ERR_MASK_OFFSET, i_poreve->iv_pore.emr.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_P0_OFFSET, (i_poreve->iv_pore.p0.read() << 32));
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_P1_OFFSET, (i_poreve->iv_pore.p1.read() << 32));
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_A0_OFFSET, i_poreve->iv_pore.a0.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_A1_OFFSET, i_poreve->iv_pore.a1.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_TBL_BASE_OFFSET, table_base);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_EXE_TRIGGER_OFFSET, i_poreve->iv_pore.etr.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_CTR_OFFSET, i_poreve->iv_pore.ctr.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_D0_OFFSET, i_poreve->iv_pore.d0.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_D1_OFFSET, i_poreve->iv_pore.d1.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_IBUF0_OFFSET, ibuf0);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_IBUF1_OFFSET, ibuf1);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_DEBUG0_OFFSET, dbg0);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_DEBUG1_OFFSET, dbg1);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_STACK0_OFFSET, stack0);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_STACK1_OFFSET, stack1);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_STACK2_OFFSET, stack2);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_IDFLAGS_OFFSET, i_poreve->iv_pore.ifr.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_SPRG0_OFFSET, i_poreve->iv_pore.sprg0.read());
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_MRR_OFFSET, mrr);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_I2CE0_OFFSET, i2c_e0);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_I2CE1_OFFSET, i2c_e1);
        rc_ecmd |= o_engine_state.setDoubleWord(PORE_I2CE2_OFFSET, i2c_e2);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_extract_pore_engine_state_virtual: Error %x inserting engine FFDC data value",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

    } while(0);

    FAPI_DBG("proc_extract_pore_engine_state_virtual: End");
    return rc;
}
#endif

/**
 * proc_extract_pore_engine_state - HWP entry point, extract PORE engine state
 *
 * @param[in]   i_target         - chip target, used to collect engine state if
 *                                 i_poreve is NULL
 * @param[in]   i_poreve         - pointer to PoreVe object, used to collect engine
 *                                 state if non NULL
 * @param[in]   i_engine         - engine type to analyze (SBE/SLW)
 * @param[out]  o_pore_state     - PORE state/FFDC content
 * @param[out]  o_pore_sbe_state - PORE SBE-specific state/FFDC content (filled
 *                                 only if i_engine=SBE)
 *
 * @retval      fapi::ReturnCode = SUCCESS
 * @retval      fapi::ReturnCode = RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_MODEL_ERROR
 * @retval      fapi::ReturnCode = RC_PROC_EXTRACT_PORE_ENGINE_STATE_VSBE_PIB_ERROR
 * @retval      fapi::ReturnCode = RC_PROC_EXTRACT_PORE_ENGINE_STATE_UNSUPPORTED_INVOCATION
 */
fapi::ReturnCode proc_extract_pore_engine_state(const fapi::Target & i_target,
                                                void * i_poreve,
                                                const por_engine_t i_engine,
                                                por_base_state & o_pore_state,
                                                por_sbe_base_state & o_pore_sbe_state)
{
    // return code
    fapi::ReturnCode rc;

    do
    {
        //
        // check arguments
        //

        // virtual SBE for processor or Centaur OR
        // real SBE/SLW for processor
        bool is_virtual = (i_poreve != NULL);
#if PROC_EXTRACT_PORE_ENGINE_STATE_BUILD_POREVE == 1
        bool is_virtual_supported = true;
        vsbe::PoreVe * ve = reinterpret_cast<vsbe::PoreVe *>(i_poreve);
#else
        bool is_virtual_supported = false;
#endif
        bool is_processor = (i_target.getType() == fapi::TARGET_TYPE_PROC_CHIP);
        bool is_centaur = (i_target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP);
        bool is_sbe = (i_engine == SBE);
        bool is_slw = (i_engine == SLW);

        o_pore_state.target = i_target;
        o_pore_state.engine = i_engine;
        o_pore_state.is_virtual = is_virtual;

        if (!((is_virtual && is_virtual_supported && (is_processor || is_centaur) && is_sbe) ||
              (!is_virtual && is_processor && (is_sbe || is_slw))))
        {
            FAPI_ERR("proc_extract_pore_engine_state: Unsupported invocation for target: %s, engine type: %s, virtual: %d",
                     i_target.toEcmdString(), ((i_engine == SBE)?("SBE"):("SLW")), is_virtual);
            const fapi::Target & CHIP = i_target;
            const por_engine_t & ENGINE = i_engine;
            const bool & VIRTUAL = is_virtual;
            const bool & VIRTUAL_IS_SUPPORTED = is_virtual_supported;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_EXTRACT_PORE_ENGINE_STATE_UNSUPPORTED_INVOCATION);
            break;
        }


        //
        // extract engine state
        //

        FAPI_INF("proc_extract_pore_engine_state: Extracting PORE engine FFDC for target: %s, engine type: %s, virtual: %d",
                 i_target.toEcmdString(), ((i_engine == SBE)?("SBE"):("SLW")), is_virtual);

        // collect engine state from virtual PORE engine
        if (is_virtual)
        {
#if PROC_EXTRACT_PORE_ENGINE_STATE_BUILD_POREVE == 1
            rc = proc_extract_pore_engine_state_virtual(i_target,
                                                        ve,
                                                        o_pore_state.vital_state,
                                                        o_pore_state.engine_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_extract_pore_engine_state: Error from proc_extract_pore_engine_state_virtual");
                break;
            }
#endif
        }
        // HW
        else
        {
            rc = proc_extract_pore_engine_state_hw(i_target,
                                                   i_engine,
                                                   o_pore_state.vital_state,
                                                   o_pore_state.engine_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_extract_pore_engine_state: Error from proc_extract_pore_engine_state_hw");
                break;
            }
        }

        FAPI_INF("proc_extract_pore_engine_state: PORE_VITAL = 0x%016llX", o_pore_state.vital_state.getDoubleWord(0));
        FAPI_INF("proc_extract_pore_engine_state: PORE_STATUS = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_STATUS_OFFSET));     
        FAPI_INF("proc_extract_pore_engine_state: PORE_CONTROL = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_CONTROL_OFFSET));    
        FAPI_INF("proc_extract_pore_engine_state: PORE_RESET = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_RESET_OFFSET));      
        FAPI_INF("proc_extract_pore_engine_state: PORE_ERR_MASK = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_ERR_MASK_OFFSET));   
        FAPI_INF("proc_extract_pore_engine_state: PORE_P0 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_P0_OFFSET));         
        FAPI_INF("proc_extract_pore_engine_state: PORE_P1 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_P1_OFFSET));         
        FAPI_INF("proc_extract_pore_engine_state: PORE_A0 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_A0_OFFSET));         
        FAPI_INF("proc_extract_pore_engine_state: PORE_A1 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_A1_OFFSET));         
        FAPI_INF("proc_extract_pore_engine_state: PORE_TBL_BASE = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_TBL_BASE_OFFSET));   
        FAPI_INF("proc_extract_pore_engine_state: PORE_EXE_TRIGGER = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_EXE_TRIGGER_OFFSET));
        FAPI_INF("proc_extract_pore_engine_state: PORE_CTR = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_CTR_OFFSET));        
        FAPI_INF("proc_extract_pore_engine_state: PORE_D0 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_D0_OFFSET));         
        FAPI_INF("proc_extract_pore_engine_state: PORE_D1 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_D1_OFFSET));         
        FAPI_INF("proc_extract_pore_engine_state: PORE_IBUF0 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_IBUF0_OFFSET));      
        FAPI_INF("proc_extract_pore_engine_state: PORE_IBUF1 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_IBUF1_OFFSET));      
        FAPI_INF("proc_extract_pore_engine_state: PORE_DEBUG0 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_DEBUG0_OFFSET));     
        FAPI_INF("proc_extract_pore_engine_state: PORE_DEBUG1 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_DEBUG1_OFFSET));     
        FAPI_INF("proc_extract_pore_engine_state: PORE_STACK0 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_STACK0_OFFSET));     
        FAPI_INF("proc_extract_pore_engine_state: PORE_STACK1 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_STACK1_OFFSET));     
        FAPI_INF("proc_extract_pore_engine_state: PORE_STACK2 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_STACK2_OFFSET));     
        FAPI_INF("proc_extract_pore_engine_state: PORE_IDFLAGS = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_IDFLAGS_OFFSET));    
        FAPI_INF("proc_extract_pore_engine_state: PORE_SPRG0 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_SPRG0_OFFSET));      
        FAPI_INF("proc_extract_pore_engine_state: PORE_MRR = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_MRR_OFFSET));        
        FAPI_INF("proc_extract_pore_engine_state: PORE_I2CE0 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_I2CE0_OFFSET));      
        FAPI_INF("proc_extract_pore_engine_state: PORE_I2CE1 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_I2CE1_OFFSET));      
        FAPI_INF("proc_extract_pore_engine_state: PORE_I2CE2 = 0x%016llX", o_pore_state.engine_state.getDoubleWord(PORE_I2CE2_OFFSET));      

        o_pore_state.pc = (o_pore_state.engine_state.getDoubleWord(PORE_STATUS_OFFSET) & 0x0000FFFFFFFFFFFFULL);
        FAPI_INF("proc_extract_pore_engine_state: PORE_PC = 0x%016llX", o_pore_state.pc);

        //
        // processor SBE specific state collection
        //

        if (is_processor && is_sbe)
        {
            rc = proc_extract_pore_engine_state_sbe_ffdc(i_target,
                                                         o_pore_sbe_state);
            if (!rc.ok())
            {
                FAPI_ERR("proc_extract_pore_engine_state: Error from proc_extract_pore_engine_state_sbe_ffdc");
                break;
            }

            FAPI_INF("proc_extract_pore_engine_state: SBE SEEPROM ECCB = %016llX", o_pore_sbe_state.i2cm_eccb_status.getDoubleWord(0));
            FAPI_INF("proc_extract_pore_engine_state: SBE PNOR ECCB = %016llX", o_pore_sbe_state.pnor_eccb_status.getDoubleWord(0));
            FAPI_INF("proc_extract_pore_engine_state: SBE soft error = %d", o_pore_sbe_state.soft_err);
            FAPI_INF("proc_extract_pore_engine_state: SBE attn = %d", o_pore_sbe_state.reported_attn);
        }
    } while(0);

    FAPI_INF("proc_extract_pore_engine_state: End");
    return rc;
}


} // extern "C"
