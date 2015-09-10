/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_chiplet_scominit/proc_chiplet_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: proc_chiplet_scominit.C,v 1.29 2015/08/10 15:15:06 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_chiplet_scominit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_chiplet_scominit.C
// *! DESCRIPTION : Invoke initfiles for proc_chiplet_scominit istep (FAPI)
// *!
// *! OWNER NAME  : Mike Jones        Email: mjjones@us.ibm.com
// *! BACKUP NAME : Joe McGill        Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_chiplet_scominit.H>
#include <p8_scom_addresses.H>
#include <proc_check_master_sbe_seeprom.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// HWP entry point, comments in header
fapi::ReturnCode proc_chiplet_scominit(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    fapi::TargetType target_type;
    std::vector<fapi::Target> initfile_targets;
    std::vector<fapi::Target> ex_targets;
    std::vector<fapi::Target> mcs_targets;
    uint8_t nx_enabled;
    uint8_t mcs_pos;
    uint8_t ex_pos;
    uint8_t num_ex_targets;
    uint8_t master_mcs_pos = 0xFF;
    fapi::Target master_mcs;
    uint8_t enable_xbus_resonant_clocking = 0x0;
    uint8_t i2c_slave_address = 0x0;
    uint8_t dual_capp_present = 0x0;

    ecmdDataBufferBase data(64);
    ecmdDataBufferBase cfam_data(32);
    ecmdDataBufferBase mask(64);

    bool               is_master = false;

    // mark HWP entry
    FAPI_INF("proc_chiplet_scominit: Start");

    do
    {
        rc = proc_check_master_sbe_seeprom(i_target, is_master);
        if (!rc.ok())
        {
            FAPI_ERR("proc_cen_ref_clk_enable: Error from proc_check_master_sbe_seeprom");
            break;
        }

        // obtain target type to determine which initfile(s) to execute
        target_type = i_target.getType();

        // chip level target
        if (target_type == fapi::TARGET_TYPE_PROC_CHIP)
        {
            // execute FBC SCOM initfile
            initfile_targets.push_back(i_target);
            FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                     PROC_CHIPLET_SCOMINIT_FBC_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(
                rc,
                fapiHwpExecInitFile,
                initfile_targets,
                PROC_CHIPLET_SCOMINIT_FBC_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_FBC_IF,
                         i_target.toEcmdString());
                break;
            }

            // execute PSI SCOM initfile
            FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                     PROC_CHIPLET_SCOMINIT_PSI_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(
                rc,
                fapiHwpExecInitFile,
                initfile_targets,
                PROC_CHIPLET_SCOMINIT_PSI_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_PSI_IF,
                         i_target.toEcmdString());
                break;
            }

            // execute TP bridge SCOM initfile
            FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                     PROC_CHIPLET_SCOMINIT_TPBRIDGE_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(
                rc,
                fapiHwpExecInitFile,
                initfile_targets,
                PROC_CHIPLET_SCOMINIT_TPBRIDGE_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_TPBRIDGE_IF,
                         i_target.toEcmdString());
                break;
            }

            // query NX partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_NX_ENABLE,
                               &i_target,
                               nx_enabled);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error querying ATTR_PROC_NX_ENABLE");
                break;
            }

            // apply NX/AS SCOM initfiles only if partial good attribute is set
            if (nx_enabled == fapi::ENUM_ATTR_PROC_NX_ENABLE_ENABLE)
            {
                // execute NX SCOM initfile
                FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_NX_IF, i_target.toEcmdString());
                FAPI_EXEC_HWP(
                    rc,
                    fapiHwpExecInitFile,
                    initfile_targets,
                    PROC_CHIPLET_SCOMINIT_NX_IF);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                             PROC_CHIPLET_SCOMINIT_NX_IF,
                             i_target.toEcmdString());
                    break;
                }

                // execute CXA SCOM initfile
                FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_CXA_IF, i_target.toEcmdString());
                FAPI_EXEC_HWP(
                    rc,
                    fapiHwpExecInitFile,
                    initfile_targets,
                    PROC_CHIPLET_SCOMINIT_CXA_IF);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                             PROC_CHIPLET_SCOMINIT_CXA_IF,
                             i_target.toEcmdString());
                    break;
                }

                // configure CXA APC master LCO settings
                rc = fapiGetChildChiplets(i_target,
                                          fapi::TARGET_TYPE_EX_CHIPLET,
                                          ex_targets,
                                          fapi::TARGET_STATE_FUNCTIONAL);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiGetChildChiplets (EX) on %s",
                             i_target.toEcmdString());
                    break;
                }

                // form valid LCO target list
                for (std::vector<fapi::Target>::iterator i = ex_targets.begin();
                     i != ex_targets.end();
                     i++)
                {
                    // determine EX chiplet number
                    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), ex_pos);

                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_chiplet_scominit: Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS) on %s",
                                 i->toEcmdString());
                        break;
                    }

                    rc_ecmd |= data.setBit(ex_pos-((ex_pos < 8)?(1):(3)));
                }
                if (!rc.ok())
                {
                    break;
                }

                num_ex_targets = ex_targets.size();
                rc_ecmd |= data.insertFromRight(
                    num_ex_targets,
                    CAPP_APC_MASTER_LCO_TARGET_MIN_START_BIT,
                    (CAPP_APC_MASTER_LCO_TARGET_MIN_END_BIT-
                     CAPP_APC_MASTER_LCO_TARGET_MIN_START_BIT+1));

                if (rc_ecmd)
                {
                    FAPI_ERR("proc_chiplet_scominit: Error 0x%x setting APC Master LCO Target register data buffer",
                             rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }

                rc = fapiPutScom(i_target,
                                 CAPP_APC_MASTER_LCO_TARGET_0x02013021,
                                 data);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: fapiPutScom error (CAPP_APC_MASTER_LCO_TARGET_0x02013021) on %s",
                             i_target.toEcmdString());
                    break;
                }

                // get dual CAPP presence attribute
                FAPI_DBG("proc_chiplet_scominit: Querying dual CAPP feature attribute");
                rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_DUAL_CAPP_PRESENT,
                                   &i_target,
                                   dual_capp_present);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error querying ATTR_CHIP_EC_FEATURE_DUAL_CAPP_PRESENT");
                    break;
                }
                
                if (dual_capp_present != 0)
                {
                    rc = fapiPutScom(i_target,
                                     CAPP1_APC_MASTER_LCO_TARGET_0x020131A1,
                                     data);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_chiplet_scominit: fapiPutScom error (CAPP1_APC_MASTER_LCO_TARGET_0x020131A1) on %s",
                                 i_target.toEcmdString());
                        break;
                    }
                }

                // execute AS SCOM initfile
                FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_AS_IF, i_target.toEcmdString());
                FAPI_EXEC_HWP(
                    rc,
                    fapiHwpExecInitFile,
                    initfile_targets,
                    PROC_CHIPLET_SCOMINIT_AS_IF);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                             PROC_CHIPLET_SCOMINIT_AS_IF,
                             i_target.toEcmdString());
                    break;
                }
            }
            else
            {
                FAPI_DBG("proc_chiplet_scominit: Skipping execution of %s/%s/%s (partial good)",
                         PROC_CHIPLET_SCOMINIT_NX_IF, PROC_CHIPLET_SCOMINIT_CXA_IF, PROC_CHIPLET_SCOMINIT_AS_IF);
            }

            // conditionally enable I2C Slave
            rc = FAPI_ATTR_GET(ATTR_I2C_SLAVE_ADDRESS,
                               &i_target,
                               i2c_slave_address);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error querying ATTR_I2C_SLAVE_ADDRESS on %s",
                         i_target.toEcmdString());
                break;
            }
            rc = fapiGetScom(i_target,
                             I2C_SLAVE_CONFIG_REG_0x000D0000,
                             data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: fapiGetScom error (I2C_SLAVE_CONFIG_REG_0x000D0000) on %s",
                         i_target.toEcmdString());
                break;
            }
            if (i2c_slave_address)
            {
                FAPI_DBG("proc_chiplet_scominit: I2C Slave enabled (%s) address = %d",
                     i_target.toEcmdString(),i2c_slave_address);

                //set I2C address
                rc_ecmd |= data.insert(i2c_slave_address,0,7);

                // disable error state.  when this is enabled and there
                // is an error from I2CS it locks up the I2CS and no
                // more operations are allowed unless cleared
                // through FSI.  Not good for a FSPless system.
                rc_ecmd |= data.clearBit(23);

                // enable I2C interface
                rc_ecmd |= data.setBit(21);

            }
            else
            {
                FAPI_DBG("proc_chiplet_scominit: I2C Slave disabled (%s)",
                     i_target.toEcmdString());

                // disable I2C interface when attribute = 0x0
                rc_ecmd |= data.clearBit(21);
            }

            if (rc_ecmd)
            {
                FAPI_ERR("proc_chiplet_scominit: Error 0x%x setting I2C Slave register data buffer",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            rc = fapiPutScom(i_target,
                             I2C_SLAVE_CONFIG_REG_0x000D0000,
                             data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: fapiPutScom error (I2C_SLAVE_CONFIG_REG_0x000D0000) on %s",
                         i_target.toEcmdString());
                break;
            }

            // conditionally enable resonant clocking for XBUS
            rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_XBUS_RESONANT_CLK_VALID,
                               &i_target,
                               enable_xbus_resonant_clocking);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error querying ATTR_CHIP_EC_FEATURE_XBUS_RESONANT_CLK_VALID on %s",
                         i_target.toEcmdString());
                break;
            }

            if (enable_xbus_resonant_clocking)
            {
                FAPI_DBG("proc_chiplet_scominit: Enabling XBUS resonant clocking");
                rc = fapiGetScom(i_target,
                                 MBOX_FSIGP6_0x00050015,
                                 data);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: fapiGetScom error (MBOX_FSIGP6_0x00050015) on %s",
                             i_target.toEcmdString());
                    break;
                }

                rc_ecmd |= data.insertFromRight(
                    XBUS_RESONANT_CLOCK_CONFIG,
                    MBOX_FSIGP6_XBUS_RESONANT_CLOCK_CONFIG_START_BIT,
                    (MBOX_FSIGP6_XBUS_RESONANT_CLOCK_CONFIG_END_BIT-
                     MBOX_FSIGP6_XBUS_RESONANT_CLOCK_CONFIG_START_BIT+1));

                if (rc_ecmd)
                {
                    FAPI_ERR("proc_chiplet_scominit: Error 0x%x setting FSI GP6 register data buffer",
                             rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }

                if (is_master) 
                {
                    rc = fapiPutScom(i_target,
                                 MBOX_FSIGP6_0x00050015,
                                 data);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_chiplet_scominit: fapiPutScom error (MBOX_FSIGP6_0x00050015) on %s",
                             i_target.toEcmdString());
                        break;
                    }
                }
                else 
                {
                    cfam_data.insert(data, 0, 32, 0);
                    rc = fapiPutCfamRegister(i_target, CFAM_FSI_GP6_0x00002815, cfam_data);
                    if (rc)
                    {
                        FAPI_ERR("proc_cen_ref_clk_enable: fapiPutCfamRegister error (CFAM_FSI_GP8_0x00001017)");
                        break;
                    }
                }
            }

            // execute A/X/PCI/DMI FIR init SCOM initfile
            FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                     PROC_CHIPLET_SCOMINIT_A_X_PCI_DMI_IF, i_target.toEcmdString());
            FAPI_EXEC_HWP(
                rc,
                fapiHwpExecInitFile,
                initfile_targets,
                PROC_CHIPLET_SCOMINIT_A_X_PCI_DMI_IF);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_A_X_PCI_DMI_IF,
                         i_target.toEcmdString());
                break;
            }

            // execute NV scominit file
            uint8_t exist_NV = 0x00;
            rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_NV_PRESENT, &i_target, exist_NV);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error getting attribute value ATTR_CHIP_EC_FEATURE_NV_PRESENT");
                break;
            }
            if (exist_NV)
            {
                // mask NPU FIR bit 27
                rc_ecmd = data.flushTo0();
                rc_ecmd = data.setBit(NPU_FIR_NTL_DL2TL_PARITY_ERR_BIT);
                if (rc_ecmd)
                {
                    FAPI_ERR("proc_chiplet_scominit: Error 0x%Xforming NPU FIR mask data buffer",
                  	   rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, NPU_FIR_MASK_OR_0x08013D85, data);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: fapiPutScom error (NPU_FIR_MASK_OR_0x08013D85) on %s",
                             i_target.toEcmdString());
                    break;
                }

                FAPI_INF("proc_chiplet_scominit: Executing  %s on %s",
                         PROC_CHIPLET_SCOMINIT_NPU_IF, i_target.toEcmdString());
                FAPI_EXEC_HWP(
                        rc,
                        fapiHwpExecInitFile,
                        initfile_targets,
                        PROC_CHIPLET_SCOMINIT_NPU_IF);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                             PROC_CHIPLET_SCOMINIT_NPU_IF,
                             i_target.toEcmdString());
                    break;
                }

                // cleanup FIR bit (NPU FIR bit 27) caused by NDL/NTL parity error
                rc_ecmd = data.invert();
                if (rc_ecmd)
                {
                    FAPI_ERR("proc_chiplet_scominit: Error 0x%Xforming NPU FIR cleanup data buffer",
                  	   rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }
                rc = fapiPutScom(i_target, NPU_FIR_AND_0x08013D81, data);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: fapiPutScom error (NPU_FIR_AND_0x08013D81) on %s",
                             i_target.toEcmdString());
                    break;
                }
                rc = fapiPutScom(i_target, NPU_FIR_MASK_AND_0x08013D84, data);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: fapiPutScom error (NPU_FIR_MASK_AND_0x08013D84) on %s",
                             i_target.toEcmdString());
                    break;
                }
            }
            else
            {
                FAPI_INF("proc_chiplet_scominit: NV link logic not present, scom initfile processing skipped");
            }

            // determine set of functional MCS chiplets
            rc = fapiGetChildChiplets(i_target,
                                      fapi::TARGET_TYPE_MCS_CHIPLET,
                                      mcs_targets,
                                      fapi::TARGET_STATE_FUNCTIONAL);
            if (!rc.ok())
            {
                FAPI_ERR("proc_chiplet_scominit: Error from fapiGetChildChiplets (MCS) on %s",
                         i_target.toEcmdString());
                break;
            }

            // apply MCS SCOM initfile only for functional chiplets
            for (std::vector<fapi::Target>::iterator i = mcs_targets.begin();
                 (i != mcs_targets.end()) && rc.ok();
                 i++)
            {
                // execute MCS SCOM initfile
                initfile_targets.clear();
                initfile_targets.push_back(*i);
                initfile_targets.push_back(i_target);
                FAPI_INF("proc_chiplet_scominit: Executing %s on %s",
                         PROC_CHIPLET_SCOMINIT_MCS_IF, i->toEcmdString());
                FAPI_EXEC_HWP(
                    rc,
                    fapiHwpExecInitFile,
                    initfile_targets,
                    PROC_CHIPLET_SCOMINIT_MCS_IF);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from fapiHwpExecInitfile executing %s on %s",
                             PROC_CHIPLET_SCOMINIT_MCS_IF,
                             i->toEcmdString());
                    break;
                }

                // determine MCS position
                rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), mcs_pos);

                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS) on %s",
                             i->toEcmdString());
                    break;
                }

                if (mcs_pos < master_mcs_pos)
                {
                    fapi::Target cen_target_unused;
                    rc = fapiGetOtherSideOfMemChannel(*i,
                                                      cen_target_unused,
                                                      fapi::TARGET_STATE_FUNCTIONAL);
                    // use return code only to indicate presence of connected Centaur,
                    // do not propogate/emit error if not connected
                    if (rc.ok())
                    {
                        FAPI_DBG("Updating master_mcs_pos to %d", mcs_pos);
                        FAPI_DBG("  Target: %s", cen_target_unused.toEcmdString());
                        master_mcs = *i;
                        master_mcs_pos = mcs_pos;
                    }
                    else
                    {
                        rc = fapi::FAPI_RC_SUCCESS;
                    }
                }

            }
            if (!rc.ok())
            {
                break;
            }

            if (master_mcs.getType() == fapi::TARGET_TYPE_MCS_CHIPLET)
            {
                // set MCMODE0Q_ENABLE_CENTAUR_SYNC on first target only
                // (this bit is required to be set on at most one MCS/chip)
                rc_ecmd |= data.flushTo0();
                rc_ecmd |= data.setBit(MCSMODE0_EN_CENTAUR_SYNC_BIT);
                rc_ecmd |= mask.setBit(MCSMODE0_EN_CENTAUR_SYNC_BIT);

                // check buffer manipulation return codes
                if (rc_ecmd)
                {
                    FAPI_ERR("proc_chiplet_scominit: Error 0x%X setting up MCSMODE0 data buffer",
                             rc_ecmd);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }

                // write register with updated content
                rc = fapiPutScomUnderMask(master_mcs,
                                          MCS_MCSMODE0_0x02011807,
                                          data,
                                          mask);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_chiplet_scominit: fapiPutScomUnderMask error (MCS_MCSMODE0_0x02011807) on %s",
                             master_mcs.toEcmdString());
                    break;
                }

            }
        }
        // unsupported target type
        else
        {
            FAPI_ERR("proc_chiplet_scominit: Unsupported target type");
            const fapi::Target & TARGET = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_CHIPLET_SCOMINIT_INVALID_TARGET);
            break;
        }
    } while(0);

    // mark HWP exit
    FAPI_INF("proc_chiplet_scominit: End");
    return rc;
}


} // extern "C"
