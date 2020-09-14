/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimmErrorLog.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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

#include "nvdimm.H"
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <fapi2.H>
#include <isteps/nvdimm/nvdimmreasoncodes.H>
#include <isteps/nvdimm/nvdimm.H>
#include "errlud_nvdimm.H"

using namespace TARGETING;

namespace NVDIMM
{

/**
 * @brief Read and save various status registers needed for error log traces
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[out] o_RegInfo - struct to hold register data
 *
 */
void nvdimmTraceRegs(Target *i_nvdimm, nvdimm_reg_t& o_RegInfo)
{
    uint8_t l_data = 0x0;
    errlHndl_t l_err = nullptr;

    // Read MODULE HEALTH register
    l_err = nvdimmReadReg(i_nvdimm, MODULE_HEALTH, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Module_Health = l_data;

    // Read MODULE HEALTH STATUS0 register
    l_err = nvdimmReadReg(i_nvdimm, MODULE_HEALTH_STATUS0, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Module_Health_Status0 = l_data;

    // Read MODULE HEALTH STATUS1 register
    l_err = nvdimmReadReg(i_nvdimm, MODULE_HEALTH_STATUS1, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Module_Health_Status1 = l_data;

    // Read CSAVE STATUS register
    l_err = nvdimmReadReg(i_nvdimm, CSAVE_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.CSave_Status = l_data;

    // Read CSAVE INFO register
    l_err = nvdimmReadReg(i_nvdimm, CSAVE_INFO, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.CSave_Info = l_data;

    // Read CSAVE FAIL INFO0 register
    l_err = nvdimmReadReg(i_nvdimm, CSAVE_FAIL_INFO0, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.CSave_Fail_Info0 = l_data;

    // Read CSAVE FAIL INFO1 register
    l_err = nvdimmReadReg(i_nvdimm, CSAVE_FAIL_INFO1, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.CSave_Fail_Info1 = l_data;

    // Read CSAVE TIMEOUT0 register
    l_err = nvdimmReadReg(i_nvdimm, CSAVE_TIMEOUT0, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.CSave_Timeout0 = l_data;

    // Read CSAVE TIMEOUT1 register
    l_err = nvdimmReadReg(i_nvdimm, CSAVE_TIMEOUT1, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.CSave_Timeout1 = l_data;

    // Read ERROR THRESHOLD STATUS register
    l_err = nvdimmReadReg(i_nvdimm, ERROR_THRESHOLD_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Error_Threshold_Status = l_data;

    // Read NVDIMM READY register
    l_err = nvdimmReadReg(i_nvdimm, NVDIMM_READY, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.NVDimm_Ready = l_data;

    // Read NVDIMM CMD STATUS0 register
    l_err = nvdimmReadReg(i_nvdimm, NVDIMM_CMD_STATUS0, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.NVDimm_CMD_Status0 = l_data;

    // Read ERASE STATUS register
    l_err = nvdimmReadReg(i_nvdimm, ERASE_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Erase_Status = l_data;

    // Read ERASE FAIL INFO register
    l_err = nvdimmReadReg(i_nvdimm, ERASE_FAIL_INFO, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Erase_Fail_Info = l_data;

    // Read ERASE TIMEOUT0 register
    l_err = nvdimmReadReg(i_nvdimm, ERASE_TIMEOUT0, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Erase_Timeout0 = l_data;

    // Read ERASE TIMEOUT1 register
    l_err = nvdimmReadReg(i_nvdimm, ERASE_TIMEOUT1, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Erase_Timeout1 = l_data;

    // Read ABORT CMD TIMEOUT register
    l_err = nvdimmReadReg(i_nvdimm, ABORT_CMD_TIMEOUT, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Abort_CMD_Timeout = l_data;

    // Read SET ES POLICY STATUS register
    l_err = nvdimmReadReg(i_nvdimm, SET_ES_POLICY_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Set_ES_Policy_Status = l_data;

    // Read RESTORE STATUS register
    l_err = nvdimmReadReg(i_nvdimm, RESTORE_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Restore_Status = l_data;

    // Read RESTORE FAIL INFO register
    l_err = nvdimmReadReg(i_nvdimm, RESTORE_FAIL_INFO, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Restore_Fail_Info = l_data;

    // Read RESTORE TIMEOUT0 register
    l_err = nvdimmReadReg(i_nvdimm, RESTORE_TIMEOUT0, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Restore_Timeout0 = l_data;

    // Read RESTORE TIMEOUT1 register
    l_err = nvdimmReadReg(i_nvdimm, RESTORE_TIMEOUT1, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Restore_Timeout1 = l_data;

    // Read ARM STATUS register
    l_err = nvdimmReadReg(i_nvdimm, ARM_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Arm_Status = l_data;

    // Read ARM FAIL INFO register
    l_err = nvdimmReadReg(i_nvdimm, ARM_FAIL_INFO, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Arm_Fail_Info = l_data;

    // Read ARM TIMEOUT0 register
    l_err = nvdimmReadReg(i_nvdimm, ARM_TIMEOUT0, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Arm_Timeout0 = l_data;

    // Read ARM TIMEOUT1 register
    l_err = nvdimmReadReg(i_nvdimm, ARM_TIMEOUT1, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Arm_Timeout1 = l_data;

    // Read SET EVENT NOTIFICATION STATUS register
    l_err = nvdimmReadReg(i_nvdimm, SET_EVENT_NOTIFICATION_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Set_Event_Notification_Status = l_data;

    // Read NVDIMM Encryption Configuration and Status Register for Security Errors
    l_err = nvdimmReadReg(i_nvdimm, ENCRYPTION_CONFIG_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    o_RegInfo.Encryption_Config_Status = l_data;
}

/**
 * @brief Helper function for standard callout of an NVDIMM
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_step - the nvdimm function calling the health check
 *
 * @param[out] o_err - error log handler to be modified
 *
 * @return bool - true to commit log and continue, false to return
 *      the error log to caller and exit.
 */
bool nvdimmCalloutDimm(Target *i_nvdimm, uint8_t i_step, errlHndl_t& o_err)
{
    bool l_continue = true;
    uint8_t l_data;
    errlHndl_t l_err = nullptr;

    // Check which callout check is necessary
    switch(i_step)
    {
        // Post save errors always continue with callouts
        case HEALTH_SAVE:
        {
            // Check to see if the nvdimm image is still valid
            l_err = nvdimmValidImage(i_nvdimm, l_continue);
            if(l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
            }

            // Checkout image validity and set dimm status accordingly
            if(l_continue)
            {
                // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);

                // Callout dimm but do not deconfig or gard
                o_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_LOW,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL);
            }
            else
            {
                // Callout, deconfig and gard the dimm
                o_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_HIGH,
                                       HWAS::DECONFIG,
                                       HWAS::GARD_Fatal);
            }

            break;
        }

        // Post restore errors always continue with callouts
        case HEALTH_RESTORE:
        {
            // Check restore status
            l_err = nvdimmReadReg(i_nvdimm, RESTORE_STATUS, l_data);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
            }
            else if ((l_data & RSTR_SUCCESS) != RSTR_SUCCESS)
            {
                l_continue = false;
            }

            // Check restore status and set dimm status accordingly
            if(l_continue)
            {
                // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);

                // Callout dimm but do not deconfig or gard
                o_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_LOW,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL);
            }
            else
            {
                Target* l_sys = nullptr;
                targetService().getTopLevelTarget( l_sys );
                assert(l_sys, "nvdimmCalloutDimm: no TopLevelTarget");
                uint8_t l_mpipl = l_sys->getAttr<ATTR_IS_MPIPL_HB>();
                if (l_mpipl)
                {
                    TRACFCOMP( g_trac_nvdimm, "nvdimmCalloutDimm() - "
                        "mask MBCALFIR eventN & refresh overrun for "
                        "deconfigured nvdimm[%X]", get_huid(i_nvdimm) );

                    // To avoid PRD error during mpipl need to Mask
                    // MBACALFIR EventN & Refresh Overrun but only for
                    // deconfigured nvdimm
                    maskMbacalfir(i_nvdimm,  MBACALFIR_REFRESH_OVERRUN_OR_BIT |
                                             MBACALFIR_EVENTN_OR_BIT);
                    o_err->collectTrace(NVDIMM_COMP_NAME, 512);
                }

                // Callout, deconfig and gard the dimm
                o_err->addHwCallout( i_nvdimm,
                                     HWAS::SRCI_PRIORITY_HIGH,
                                     HWAS::DECONFIG,
                                     HWAS::GARD_Fatal);
            }

            break;
        }

        // Post ARM errors need check for arm success
        case HEALTH_PRE_ARM:
        {

            // Check arm status
            l_err = nvdimmReadReg(i_nvdimm, ARM_STATUS, l_data);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
            }
            else if (((l_data & ARM_SUCCESS) != ARM_SUCCESS) || ((l_data & RESET_N_ARMED) != RESET_N_ARMED))
            {
                l_continue = false;
            }

            // Check arm status and set dimm status accordingly
            if(l_continue)
            {
                // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
                notifyNvdimmProtectionChange(i_nvdimm,NVDIMM_RISKY_HW_ERROR);

                // Callout dimm without deconfig or gard
                o_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_LOW,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL);
            }
            else
            {
                // Set ATTR_NV_STATUS_FLAG to dimm diarmed
                l_err = notifyNvdimmProtectionChange(i_nvdimm, NVDIMM_DISARMED);
                if (l_err)
                {
                    errlCommit( l_err, NVDIMM_COMP_ID );
                }

                // Callout and gard the dimm
                o_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_HIGH,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_Fatal);
            }

            break;
        }

        // Post ARM errors need check for arm success
        case HEALTH_POST_ARM:
        {
            // Callout dimm but do not deconfig or gard
            o_err->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            // Set ATTR_NV_STATUS_FLAG to partially working as data may persist despite errors
            notifyNvdimmProtectionChange(i_nvdimm,NVDIMM_RISKY_HW_ERROR);

            break;
       }

    }

    return l_continue;
}

/**
 * @brief Helper function for BPM/Cable high, NVDIMM low callout
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_step - the nvdimm function calling the health check
 *
 * @param[out] o_err - error log handler to be modified
 *
 * @return bool - true to commit log and continue, false to return
 *      the error log to caller and exit.
 */
bool nvdimmBPMCableCallout(Target *i_nvdimm, uint8_t i_step, errlHndl_t& o_err)
{
    bool l_continue = true;
    uint8_t l_data;
    errlHndl_t l_err = nullptr;

    // Check which callout check is necessary
    switch(i_step)
    {
        // Post save errors always continue with callouts
        case HEALTH_SAVE:
        {
            // Check to see if the nvdimm image is still valid
            l_err = nvdimmValidImage(i_nvdimm, l_continue);
            if(l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
            }

            // Callout BPM and Cable but cannot deconfig or gard
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_CABLE_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);

            // Check image validity and set dimm status accordingly
            if(l_continue)
            {
                // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);

                // Callout dimm but do not deconfig or gard
                o_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_LOW,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL);
            }
            else
            {
                // Callout dimm, deconfig and gard
                o_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_LOW,
                                       HWAS::DECONFIG,
                                       HWAS::GARD_Fatal);
            }

            break;
       }

        // Post restore errors always continue with callouts
        case HEALTH_RESTORE:
        {
            // Check restore status
            l_err = nvdimmReadReg(i_nvdimm, RESTORE_STATUS, l_data);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
            }
            else if ((l_data & RSTR_SUCCESS) != RSTR_SUCCESS)
            {
                l_continue = false;
            }

            // Callout dimm but do not deconfig or gard
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_CABLE_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            // Callout dimm but do not deconfig or gard
            o_err->addHwCallout( i_nvdimm,
                                 HWAS::SRCI_PRIORITY_LOW,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL);

            // Check restore status and set dimm status accordingly
            if(l_continue)
            {
                // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
                nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);
            }

            break;
        }

        // Post ARM errors need check for arm success
        case HEALTH_PRE_ARM:
        {
            // Check arm status
            l_err = nvdimmReadReg(i_nvdimm, ARM_STATUS, l_data);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
            }
            else if (((l_data & ARM_SUCCESS) != ARM_SUCCESS) || ((l_data & RESET_N_ARMED) != RESET_N_ARMED))
            {
                l_continue = false;
            }

            // Callout BPM and Cable but cannot deconfig or gard
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_CABLE_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);

            // Check arm status and set dimm status accordingly
            if(l_continue)
            {
                // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
                notifyNvdimmProtectionChange(i_nvdimm,NVDIMM_RISKY_HW_ERROR);
            }

            // Callout dimm but do not deconfig or gard
            o_err->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);
            break;
        }

        // Post ARM errors need check for arm success
        case HEALTH_POST_ARM:
        {
            // Callout dimm but do not deconfig or gard
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_CABLE_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);
            o_err->addHwCallout( i_nvdimm,
                                       HWAS::SRCI_PRIORITY_LOW,
                                       HWAS::NO_DECONFIG,
                                       HWAS::GARD_NULL);

            // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
            notifyNvdimmProtectionChange(i_nvdimm,NVDIMM_RISKY_HW_ERROR);

            break;
        }

    }

    return l_continue;
}

/**
 * @brief Helper function for BPM high, NVDIMM low callout
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_step - the nvdimm function calling the health check
 *
 * @param[out] o_err - error log handler to be modified
 *
 * @return bool - true to commit log and continue, false to return
 *      the error log to caller and exit.
 */
bool nvdimmBPMCallout(Target *i_nvdimm, uint8_t i_step, errlHndl_t& o_err)
{
    bool l_continue = true;
    uint8_t l_data;
    errlHndl_t l_err = nullptr;

    // Check which callout check is necessary
    switch(i_step)
    {
        // Post save errors always continue with callouts
        case HEALTH_SAVE:
        {
            // Callout BPM on high
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);

            // Callout dimm but do not deconfig or gard
            o_err->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);

            break;
        }

        // Post restore errors always continue with callouts
        case HEALTH_RESTORE:
        {
            // Callout BPM on high
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);

            // Callout dimm but do not deconfig or gard
            o_err->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
            nvdimmSetStatusFlag(i_nvdimm, NSTD_ERR_VAL_SR);

            break;
        }

        // Post ARM errors need check for arm success
        case HEALTH_PRE_ARM:
        {
            // Check arm status
            l_err = nvdimmReadReg(i_nvdimm, ARM_STATUS, l_data);
            if (l_err)
            {
                errlCommit( l_err, NVDIMM_COMP_ID );
            }
            else if (((l_data & ARM_SUCCESS) != ARM_SUCCESS) || ((l_data & RESET_N_ARMED) != RESET_N_ARMED))
            {
                l_continue = false;
            }

            // Callout BPM on high
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);

            // Callout dimm but do not deconfig or gard
            o_err->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            // Check arm status and set dimm status accordingly
            if(l_continue)
            {
                // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
                notifyNvdimmProtectionChange(i_nvdimm,NVDIMM_RISKY_HW_ERROR);
            }
            else
            {
                // Set ATTR_NV_STATUS_FLAG to dimm diarmed
                l_err = notifyNvdimmProtectionChange(i_nvdimm, NVDIMM_DISARMED);
                if (l_err)
                {
                    errlCommit( l_err, NVDIMM_COMP_ID );
                }
            }

            break;
        }

        // Post ARM errors need check for arm success
        case HEALTH_POST_ARM:
        {
            // Callout BPM on high
            o_err->addPartCallout( i_nvdimm,
                                   HWAS::BPM_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH);

            // Callout dimm but do not deconfig or gard
            o_err->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);

            // Set ATTR_NV_STATUS_FLAG to partially working as data may still persist
            notifyNvdimmProtectionChange(i_nvdimm,NVDIMM_RISKY_HW_ERROR);

            break;
        }

    }

    return l_continue;
}

/**
 * @brief Function checking the Health Status Registers for an nvdimm
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_step - the nvdimm step calling the check
 *
 * @param[out] o_continue - bool to signal a return to caller fail
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmHealthStatusCheck(Target *i_nvdimm, uint8_t i_step, bool& o_continue)
{
    uint8_t l_data = 0x0;
    errlHndl_t l_err = nullptr;
    errlHndl_t l_err_t = nullptr;
    nvdimm_reg_t l_RegInfo;
    bool l_arm_timeout = false;

    if (i_step == HEALTH_PRE_ARM)
    {
        l_arm_timeout = o_continue;
    }

    //Collect Register data for parsing and traces
    nvdimmTraceRegs(i_nvdimm, l_RegInfo);

    // Read SET_EVENT_NOTIFICATION_STATUS register
    l_err = nvdimmReadReg(i_nvdimm, SET_EVENT_NOTIFICATION_STATUS, l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    l_RegInfo.Set_Event_Notification_Status = l_data;

    // Read RESTORE STATUS register
    l_err = nvdimmReadReg(i_nvdimm, RESTORE_STATUS , l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    l_RegInfo.Restore_Status = l_data;

    // Read RESTORE_FAIL_INFO register
    l_err = nvdimmReadReg(i_nvdimm, RESTORE_FAIL_INFO , l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    l_RegInfo.Restore_Fail_Info = l_data;

    // Read NVDIMM_CMD_STATUS0 register
    l_err = nvdimmReadReg(i_nvdimm, NVDIMM_CMD_STATUS0 , l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    l_RegInfo.NVDimm_CMD_Status0 = l_data;

    // Read ARM_STATUS register
    l_err = nvdimmReadReg(i_nvdimm, ARM_STATUS , l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    l_RegInfo.Arm_Status = l_data;

    // Read SET_ES_POLICY_STATUS register
    l_err = nvdimmReadReg(i_nvdimm, SET_ES_POLICY_STATUS , l_data);
    if(l_err)
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }
    l_RegInfo.Set_ES_Policy_Status = l_data;

    // Check all nvdimm deconfig cases
    do
    {
        // Check MODULE_HEALTH_STATUS0[0]
        if ((l_RegInfo.Module_Health_Status0 & VOLTAGE_REGULATOR_FAILED) == VOLTAGE_REGULATOR_FAILED)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_VOLTAGE_REGULATOR_FAILED
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  voltage regulator failure
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_VOLTAGE_REGULATOR_FAILED,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS0[1]
        if ((l_RegInfo.Module_Health_Status0 & VDD_LOST) == VDD_LOST)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_VDD_LOST
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  vdd loss
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_VDD_LOST,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS0[2]
        if ((l_RegInfo.Module_Health_Status0 & VPP_LOST) == VPP_LOST)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_VPP_LOST
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  vpp loss
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_VPP_LOST,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS0[3]
        if ((l_RegInfo.Module_Health_Status0 & VTT_LOST) == VTT_LOST)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_VTT_LOST
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  vtt loss
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_VTT_LOST,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS0[4]
        if ((l_RegInfo.Module_Health_Status0 & DRAM_NOT_SELF_REFRESH) == DRAM_NOT_SELF_REFRESH)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_DRAM_NOT_SELF_REFRESH
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  no self refresh on the nvdimm
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_DRAM_NOT_SELF_REFRESH,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS0[5]
        if ((l_RegInfo.Module_Health_Status0 & CONTROLLER_HARDWARE_ERROR) == CONTROLLER_HARDWARE_ERROR)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_CONTROLLER_HARDWARE_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  error with the hardware controller
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_CONTROLLER_HARDWARE_ERROR,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS0[6]
        if ((l_RegInfo.Module_Health_Status0 & NVM_CONTROLLER_ERROR) == NVM_CONTROLLER_ERROR)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_NVM_CONTROLLER_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  error with the nvdimm controller
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_NVM_CONTROLLER_ERROR,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }


        // Check MODULE_HEALTH_STATUS0[7]
        if ((l_RegInfo.Module_Health_Status0 & NVM_LIFETIME_ERROR) == NVM_LIFETIME_ERROR)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_NVM_LIFETIME_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  an nvdimm lifetime error
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_NVM_LIFETIME_ERROR,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS1[1]
        if ((l_RegInfo.Module_Health_Status1 & INVALID_FIRMWARE_ERROR) == INVALID_FIRMWARE_ERROR)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_INVALID_FIRMWARE_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  an invalid firmware image
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_INVALID_FIRMWARE_ERROR,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS1[2]
        if ((l_RegInfo.Module_Health_Status1 & CONFIG_DATA_ERROR) == CONFIG_DATA_ERROR)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_CONFIG_DATA_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  invalid configuration data
            *@custdesc         NVDIMM failed module health status check
            */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                             NVDIMM_CONFIG_DATA_ERROR,
                                             TARGETING::get_huid(i_nvdimm),
                                             0x0,
                                             ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

    }while(0);

    if (l_err)
    {
        // Setup Trace
        l_err->collectTrace( NVDIMM_COMP_NAME );

        // Add reg traces to the error log
        NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err);

        // Callout nvdimm depending on istep call
        o_continue &= nvdimmCalloutDimm(i_nvdimm, i_step, l_err);

        if(l_arm_timeout)
        {
            // Callout and gard the dimm
            l_err->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_Fatal);
        }
    }

    // Check all BPM and Cable high, nvdimm low cases
    do
    {
        // If function calling is SAVE, ignore NOT_ENOUGH_ENERGY_FOR_CSAVE
        if (i_step != HEALTH_SAVE)
        {
            // Check MODULE_HEALTH_STATUS1[0]
            if ((l_RegInfo.Module_Health_Status1 & NOT_ENOUGH_ENERGY_FOR_CSAVE) == NOT_ENOUGH_ENERGY_FOR_CSAVE)
            {
               /*@
                *@errortype
                *@reasoncode       NVDIMM_NOT_ENOUGH_ENERGY_FOR_CSAVE
                *@severity         ERRORLOG_SEV_PREDICTIVE
                *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
                *@userdata1[0:31]  Target Huid
                *@userdata2        <UNUSED>
                *@devdesc          NVDIMM failed module health status check due to
                *                  insufficient energy for csave
                *@custdesc         NVDIMM failed module health status check
                */
                l_err_t = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                                   NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                                   NVDIMM_NOT_ENOUGH_ENERGY_FOR_CSAVE,
                                                   TARGETING::get_huid(i_nvdimm),
                                                   0x0,
                                                   ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
                break;
            }
        }

        // Check MODULE_HEALTH_STATUS1[3]
        if ((l_RegInfo.Module_Health_Status1 & NO_ES_PRESENT) == NO_ES_PRESENT)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_NO_ES_PRESENT
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  no ES active
            *@custdesc         NVDIMM failed module health status check
            */
            l_err_t = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                               NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                               NVDIMM_NO_ES_PRESENT,
                                               TARGETING::get_huid(i_nvdimm),
                                               0x0,
                                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS1[5]
        if ((l_RegInfo.Module_Health_Status1 & ES_HARDWARE_FAILURE) == ES_HARDWARE_FAILURE)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_ES_HARDWARE_FAILURE
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  ES hardware failure
            *@custdesc         NVDIMM failed module health status check
            */
            l_err_t = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                               NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                               NVDIMM_ES_HARDWARE_FAILURE,
                                               TARGETING::get_huid(i_nvdimm),
                                               0x0,
                                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check MODULE_HEALTH_STATUS1[6]
        if ((l_RegInfo.Module_Health_Status1 & ES_HEALTH_ASSESSMENT_ERROR) == ES_HEALTH_ASSESSMENT_ERROR)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_ES_HEALTH_ASSESSMENT_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  ES error during health assessment
            *@custdesc         NVDIMM failed module health status check
            */
            l_err_t = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                               NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                               NVDIMM_ES_HEALTH_ASSESSMENT_ERROR,
                                               TARGETING::get_huid(i_nvdimm),
                                               0x0,
                                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

    }while(0);

    if (l_err_t)
    {
        // Setup Trace
        l_err_t->collectTrace( NVDIMM_COMP_NAME );

        // Add reg traces to the error log
        NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err_t);

        // Callout BPM, Cable, and nvdimm
        o_continue &= nvdimmBPMCableCallout(i_nvdimm, i_step, l_err_t);
    }

    // Check for multiple errors and commit old error
    if ((l_err) && (l_err_t))
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }

    // If there was a new error, save off to l_err
    if (l_err_t)
    {
        l_err = l_err_t;
        l_err_t = nullptr;
    }

    // Check all BPM high, nvdimm low cases
    do
    {
        // Check ERROR_THRESHOLD_STATUS[1]
        if ((l_RegInfo.Error_Threshold_Status & ES_LIFETIME_ERROR) == ES_LIFETIME_ERROR)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_ES_LIFETIME_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  ES lifetime error
            *@custdesc         NVDIMM failed module health status check
            */
            l_err_t = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                               NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                               NVDIMM_ES_LIFETIME_ERROR,
                                               TARGETING::get_huid(i_nvdimm),
                                               0x0,
                                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

        // Check ERROR_THRESHOLD_STATUS[2]
        if ((l_RegInfo.Error_Threshold_Status & ES_TEMP_ERROR) == ES_TEMP_ERROR)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_ES_TEMP_ERROR
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  ES temporary error
            *@custdesc         NVDIMM failed module health status check
            */
            l_err_t = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                               NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                               NVDIMM_ES_TEMP_ERROR,
                                               TARGETING::get_huid(i_nvdimm),
                                               0x0,
                                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            break;
        }

    }while(0);

    if (l_err_t)
    {
        // Setup Trace
        l_err_t->collectTrace( NVDIMM_COMP_NAME );

        // Add reg traces to the error log
        NVDIMM::UdNvdimmOPParms( l_RegInfo ).addToLog(l_err_t);

        // Callout nvdimm
        o_continue &= nvdimmBPMCallout(i_nvdimm, i_step, l_err_t);
    }

    // Check for multiple errors and commit old error
    if ((l_err) && (l_err_t))
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }

    // If there was a new error, save off to l_err
    if (l_err_t)
    {
        l_err = l_err_t;
        l_err_t = nullptr;
    }

    // Check special pre arm case
    if (i_step == HEALTH_PRE_ARM)
    {
        // Check ES_POLICY_NOT_SET[4]
        if ((l_RegInfo.Set_ES_Policy_Status & ES_POLICY_NOT_SET) == ES_POLICY_NOT_SET)
        {
           /*@
            *@errortype
            *@reasoncode       NVDIMM_ES_POLICY_NOT_SET
            *@severity         ERRORLOG_SEV_PREDICTIVE
            *@moduleid         NVDIMM_MODULE_HEALTH_STATUS_CHECK
            *@userdata1[0:31]  Target Huid
            *@userdata2        <UNUSED>
            *@devdesc          NVDIMM failed module health status check due to
            *                  ES policy not being set during an arm
            *@custdesc         NVDIMM failed module health status check
            */
            l_err_t = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                               NVDIMM_MODULE_HEALTH_STATUS_CHECK,
                                               NVDIMM_ES_POLICY_NOT_SET,
                                               TARGETING::get_huid(i_nvdimm),
                                               0x0,
                                               ERRORLOG::ErrlEntry::NO_SW_CALLOUT );
            o_continue = false;
            // Callout dimm but no deconfig and gard
            l_err_t->addHwCallout( i_nvdimm,
                                   HWAS::SRCI_PRIORITY_LOW,
                                   HWAS::NO_DECONFIG,
                                   HWAS::GARD_NULL);
        }
    }

    // Check for multiple errors and commit old error
    if ((l_err) && (l_err_t))
    {
        errlCommit( l_err, NVDIMM_COMP_ID );
    }

    // If there was a new error, save off to l_err
    if (l_err_t)
    {
        l_err = l_err_t;
        l_err_t = nullptr;
    }

    return l_err;
}

} // end NVDIMM namespace
