/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_pcie_config/proc_pcie_config.C $ */
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
// $Id: proc_pcie_config.C,v 1.10 2014/11/18 17:41:59 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_config.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_pcie_config.C
// *! DESCRIPTION : Perform PCIe PBCQ/AIB Inits (Phase 2, Steps 9-22) (FAPI)
// *!
// *! OWNER NAME  : Joe McGill        Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include <proc_pcie_config.H>
#include <proc_a_x_pci_dmi_pll_setup.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: apply PBCQ/AIB customization via SCOM initfile
// parameters: i_target => processor chip target
// returns: FAPI_RC_SUCCESS if initfile evaluation is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pcie_config_pbcq(
    const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    std::vector<fapi::Target> targets;

    // mark function entry
    FAPI_INF("proc_pcie_config_pbcq: Start");

    do
    {
        // execute Phase2 SCOM initfile
        targets.push_back(i_target);
        FAPI_INF("proc_pcie_config_pbcq: Executing %s on %s",
                 PROC_PCIE_CONFIG_PHASE2_IF, i_target.toEcmdString());
        FAPI_EXEC_HWP(
            rc,
            fapiHwpExecInitFile,
            targets,
            PROC_PCIE_CONFIG_PHASE2_IF);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq: Error from fapiHwpExecInitfile executing %s on %s",
                     PROC_PCIE_CONFIG_PHASE2_IF,
                     i_target.toEcmdString());
            break;
        }
    } while(0);

    // mark function exit
    FAPI_INF("proc_pcie_config_pbcq: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: initialize PBCQ FIRs
//             clear FIR/WOF
//             initialize FIR action settings
//             reset FIR masks
// parameters: i_target  => processor chip target
//             i_num_phb => number of PHB units
// returns: FAPI_RC_SUCCESS if all actions are successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pcie_config_pbcq_fir(
    const fapi::Target & i_target,
    uint8_t i_num_phb)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_INF("proc_pcie_config_pbcq_fir: Start");

    // loop over all PHBs
    for (size_t i = 0; i < i_num_phb; i++)
    {
        // clear FIR
        rc_ecmd |= data.flushTo0();
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error 0x%x setting up PCIE Nest FIR clear data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
        rc = fapiPutScom(i_target,
                         PROC_PCIE_CONFIG_PCIE_NEST_FIR[i],
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error from fapiPutScom (PCIE%zd_FIR_0x%08X)",
                     i, PROC_PCIE_CONFIG_PCIE_NEST_FIR[i]);
            break;
        }
    
        // clear FIR WOF
        rc = fapiPutScom(i_target,
                         PROC_PCIE_CONFIG_PCIE_NEST_FIR_WOF[i],
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error from fapiPutScom (PCIE%zd_FIR_WOF_0x%08X)",
                     i, PROC_PCIE_CONFIG_PCIE_NEST_FIR_WOF[i]);
            break;
        }
    
        // set action0
        rc_ecmd |= data.setDoubleWord(0, PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION0_VAL);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error 0x%x setting up PCIE Nest FIR Action0 register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
    
        rc = fapiPutScom(i_target,
                         PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION0[i],
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error from fapiPutScom (PCIE%zd_FIR_ACTION0_0x%08X)",
                     i, PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION0[i]);
            break;
        }
    
        // set action1
        rc_ecmd |= data.setDoubleWord(0, PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION1_VAL);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error 0x%x setting up PCIE Nest FIR Action1 register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
    
        rc = fapiPutScom(i_target,
                         PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION1[i],
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error from fapiPutScom (PCIE%zd_FIR_ACTION1_0x%08X)",
                     i, PROC_PCIE_CONFIG_PCIE_NEST_FIR_ACTION1[i]);
            break;
        }
    
        // set mask
        rc_ecmd |= data.setDoubleWord(0, PROC_PCIE_CONFIG_PCIE_NEST_FIR_MASK_VAL);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error 0x%x setting up PCIE Nest FIR Mask register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }
    
        rc = fapiPutScom(i_target,
                         PROC_PCIE_CONFIG_PCIE_NEST_FIR_MASK[i],
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error from fapiPutScom (PCIE%zd_FIR_MASK_0x%08X)",
                     i, PROC_PCIE_CONFIG_PCIE_NEST_FIR_MASK[i]);
            break;
        }
    }

    // mark function exit
    FAPI_INF("proc_pcie_config_pbcq_fir: End");
    return rc;
}


// HWP entry point, comments in header
fapi::ReturnCode proc_pcie_config(
    const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint8_t pcie_enabled;
    uint8_t num_phb;

    // mark HWP entry
    FAPI_INF("proc_pcie_config: Start");

    do
    {
        // check for supported target type
        if (i_target.getType() != fapi::TARGET_TYPE_PROC_CHIP)
        {
            FAPI_ERR("proc_pcie_config: Unsupported target type");
            const fapi::Target & TARGET = i_target;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_PCIE_CONFIG_INVALID_TARGET);
            break;
        }

        // query PCIE partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_ENABLE,
                           &i_target,
                           pcie_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config: Error querying ATTR_PROC_PCIE_ENABLE");
            break;
        }

        // initialize PBCQ/AIB, configure PBCQ FIRs (only if partial good
        // atttribute is set)
        if (pcie_enabled == fapi::ENUM_ATTR_PROC_PCIE_ENABLE_ENABLE)
        {
            // determine PHB configuration
            rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_NUM_PHB,
                               &i_target,
                               num_phb);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_config: Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_NUM_PHB)");
                break;
            }

            rc = proc_pcie_config_pbcq(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_config: Error from proc_pcie_config_pbcq");
                break;
            }

            rc = proc_pcie_config_pbcq_fir(i_target, num_phb);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_config: Error from proc_pcie_config_pbcq_fir");
                break;
            }

            rc = proc_a_x_pci_dmi_pll_setup_unmask_lock(
                i_target,
                PCIE_CHIPLET_0x09000000);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_config: Error from proc_a_x_pci_dmi_pll_setup_unmask_lock");
                break;
            }
        }
        else
        {
            FAPI_DBG("proc_pcie_config: Skipping initialization (partial good)");
        }

    } while(0);

    // mark HWP exit
    FAPI_INF("proc_pcie_config: End");
    return rc;
}


} // extern "C"
