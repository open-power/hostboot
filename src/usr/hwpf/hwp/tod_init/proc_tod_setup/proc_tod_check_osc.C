/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/proc_tod_setup//proc_tod_check_osc.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $Id: proc_tod_check_osc.C,v 1.1 2014/12/11 17:01:53 jklazyns Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *!
// *! TITLE : proc_tod_check_osc.C
// *!
// *! DESCRIPTION : Checks the validity of TOD oscillators connected to a target
// *!
// *! OWNER NAME  : Nick Klazynski  Email: jklazyns@us.ibm.com
// *! BACKUP NAME :                 Email:
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_tod_utils.H"
#include "proc_tod_check_osc.H"
#include "p8_scom_addresses.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: proc_tod_check_osc
// parameters:
// i_target   FAPI target which will have its oscillator validity checked
// o_osc_stat Oscillator(s) which passed the validity check
//
// returns:   FAPI_RC_SUCCESS if the oscillators were successfully tested
//            (o_osc_stat will have the check's result)
//            else FAPI or ECMD error is sent through
//------------------------------------------------------------------------------
fapi::ReturnCode proc_tod_check_osc(const fapi::Target* i_target,
        proc_tod_setup_osc_sel* o_osc_stat)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase m_path_ctrl_reg_save_data(64);
    ecmdDataBufferBase data(64);
    uint32_t rc_ecmd = 0;

    FAPI_INF("proc_tod_check_osc: Start");
    do
    {
        // Read TOD_M_PATH_CTRL_REG_00040000 to be restored at the end of the procedure
        rc=fapiGetScom(*i_target,TOD_M_PATH_CTRL_REG_00040000,m_path_ctrl_reg_save_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_check_osc: Error from fapiGetScom when retrieving TOD_M_PATH_CTRL_REG_00040000!");
            break;
        }

        FAPI_DBG("proc_tod_check_osc: Configuring Master OSC paths in TOD_M_PATH_CTRL_REG_00040000 for oscillator testing.");

        // OSC0 is connected
        rc_ecmd |= data.clearBit(TOD_M_PATH_CTRL_REG_M_PATH_0_OSC_NOT_VALID);

        // OSC0 step alignment enabled
        rc_ecmd |= data.clearBit(TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_ALIGN_DIS);

        // Set 512 steps per sync for path 0
        rc_ecmd |= data.insertFromRight(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_512,
                                        TOD_M_PATH_CTRL_REG_M_PATH_0_SYNC_FREQ_SEL,
                                        TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_LEN);

        // Set step check CPS deviation to 50%
        rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_50_00_PCENT,
                                        TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_CHECK_CPS_DEVIATION,
                                        STEP_CHECK_CPS_DEVIATION_LEN);

        // 8 valid steps are required before step check is enabled
        rc_ecmd |= data.insertFromRight(STEP_CHECK_VALIDITY_COUNT_8,
                                        TOD_M_PATH_CTRL_REG_M_PATH_0_STEP_CHECK_VALIDITY_COUNT,
                                        STEP_CHECK_VALIDITY_COUNT_LEN);

        // OSC1 is connected
        rc_ecmd |= data.clearBit(TOD_M_PATH_CTRL_REG_M_PATH_1_OSC_NOT_VALID);

        // OSC1 step alignment enabled
        rc_ecmd |= data.clearBit(TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_ALIGN_DIS);

        // Set 512 steps per sync for path 1
        rc_ecmd |= data.insertFromRight(TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_512,
                                        TOD_M_PATH_CTRL_REG_M_PATH_1_SYNC_FREQ_SEL,
                                        TOD_M_PATH_CTRL_REG_M_PATH_SYNC_FREQ_SEL_LEN);

        // Set step check CPS deviation to 50%
        rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_50_00_PCENT,
                                        TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_CHECK_CPS_DEVIATION,
                                        STEP_CHECK_CPS_DEVIATION_LEN);

        // 8 valid steps are required before step check is enabled
        rc_ecmd |= data.insertFromRight(STEP_CHECK_VALIDITY_COUNT_8,
                                        TOD_M_PATH_CTRL_REG_M_PATH_1_STEP_CHECK_VALIDITY_COUNT,
                                        STEP_CHECK_VALIDITY_COUNT_LEN);

        // CPS deviation factor configures both path-0 and path-1
        rc_ecmd |= data.insertFromRight(STEP_CHECK_CPS_DEVIATION_FACTOR_1,
                                            TOD_M_PATH_CTRL_REG_M_PATH_STEP_CHECK_DEVIATION_FACTOR,
                                            STEP_CHECK_CPS_DEVIATION_FACTOR_LEN);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_tod_check_osc: Error 0x%08X in ecmdDataBuffer setup for TOD_M_PATH_CTRL_REG_00040000 SCOM.",  rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(*i_target,TOD_M_PATH_CTRL_REG_00040000,data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_check_osc: fapiPutScom error for TOD_M_PATH_CTRL_REG_00040000 SCOM.");
            break;
        }

        FAPI_DBG("proc_tod_check_osc: Checking oscillator validity.");
        rc=fapiGetScom(*i_target,TOD_PSS_MSS_STATUS_REG_00040008,data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_check_osc: Error from fapiGetScom when retrieving TOD_PSS_MSS_STATUS_REG_00040008!");
            break;
        }

        *o_osc_stat = TOD_OSC_NONE;
        if (data.isBitSet(TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID) &&
            data.isBitSet(TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID)) {
            FAPI_DBG("proc_tod_check_osc: both master path-0 and path-1 are valid! (TOD_PSS_MSS_STATUS_REG = 0x%016llX)",data.getDoubleWord(0));
            *o_osc_stat = TOD_OSC_0_AND_1;
        }
        else if (data.isBitSet(TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID)) {
            FAPI_DBG("proc_tod_check_osc: master path-0 is valid; path-1 is not! (TOD_PSS_MSS_STATUS_REG = 0x%016llX)",data.getDoubleWord(0));
            *o_osc_stat = TOD_OSC_0;
        }
        else if (data.isBitSet(TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID)) {
            FAPI_DBG("proc_tod_check_osc: master path-1 is valid; path-0 is not! (TOD_PSS_MSS_STATUS_REG = 0x%016llX)",data.getDoubleWord(0));
            *o_osc_stat = TOD_OSC_1;
        }

        FAPI_DBG("proc_tod_check_osc: Restoring previous TOD_M_PATH_CTRL_REG_00040000 value.");
        rc = fapiPutScom(*i_target,TOD_M_PATH_CTRL_REG_00040000,m_path_ctrl_reg_save_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_tod_check_osc: fapiPutScom error for TOD_M_PATH_CTRL_REG_00040000 SCOM.");
            break;
        }

    } while (0);

    FAPI_INF("proc_tod_check_osc: End");
    return rc;
}

} // extern "C"
