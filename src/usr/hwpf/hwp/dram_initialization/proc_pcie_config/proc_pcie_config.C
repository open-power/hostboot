/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_pcie_config/proc_pcie_config.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: proc_pcie_config.C,v 1.3 2012/12/11 23:59:02 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_config.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
#include "proc_pcie_config.H"

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
// parameters: i_target => processor chip target
// returns: FAPI_RC_SUCCESS if all actions are successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pcie_config_pbcq_fir(
    const fapi::Target & i_target)
{
    fapi::ReturnCode rc;

    ecmdDataBufferBase zero_data(64);

    // mark function entry
    FAPI_INF("proc_pcie_config_pbcq_fir: Start");

    // loop over all PHBs
    for (size_t i = 0; i < PROC_PCIE_CONFIG_NUM_PHB; i++)
    {
        // clear FIR
        rc = fapiPutScom(i_target,
                         PROC_PCIE_CONFIG_PCIE_NEST_FIR[i],
                         zero_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error from fapiPutScom (PCIE%d_FIR_0x%08X)",
                     i, PROC_PCIE_CONFIG_PCIE_NEST_FIR[i]);
            break;
        }

        // clear FIR WOF
        rc = fapiPutScom(i_target,
                         PROC_PCIE_CONFIG_PCIE_NEST_FIR_WOF[i],
                         zero_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error from fapiPutScom (PCIE%d_FIR_WOF_0x%08X)",
                     i, PROC_PCIE_CONFIG_PCIE_NEST_FIR_WOF[i]);
            break;
        }

        // clear FIR mask
        rc = fapiPutScom(i_target,
                         PROC_PCIE_CONFIG_PCIE_NEST_FIR_MASK[i],
                         zero_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_config_pbcq_fir: Error from fapiPutScom (PCIE%d_FIR_MASK_0x%08X)",
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

    // mark HWP entry
    FAPI_INF("proc_pcie_config: Start");

    do
    {
        // check for supported target type
        if (i_target.getType() != fapi::TARGET_TYPE_PROC_CHIP)
        {
            FAPI_ERR("proc_pcie_config: Unsupported target type");
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
            rc = proc_pcie_config_pbcq(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_config: Error from proc_pcie_config_pbcq");
                break;
            }

            rc = proc_pcie_config_pbcq_fir(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_config: Error from proc_pcie_config_pbcq_fir");
                break;
            }
        }

    } while(0);

    // mark HWP exit
    FAPI_INF("proc_pcie_config: End");
    return rc;
}


} // extern "C"
