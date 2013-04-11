/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_pcie_scominit/proc_pcie_scominit.C $ */
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
// $Id: proc_pcie_scominit.C,v 1.6 2013/04/08 14:57:39 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_pcie_scominit.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : proc_pcie_scominit.C
// *! DESCRIPTION : Perform PCIe Physical IO Inits (Phase 1, Steps 1-9) (FAPI)
// *!
// *! OWNER NAME  : Joe McGill        Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapiHwpExecInitFile.H>
#include "proc_pcie_scominit.H"

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: initialize IOP/PHB
//             set master IOP lane configuration and IOP swap bits via PCIe GP4
//             set PHB iovalids via PCIe GP0
//             remove IOP logic from reset via PCIe GP4
// parameters: i_target => processor chip target
// returns: FAPI_RC_SUCCESS if all actions are successful,
//          RC_PROC_PCIE_SCOMINIT_IOP_CONFIG_ATTR_ERR if invalid IOP lane
//            configuration attribute value is presented,
//          RC_PROC_PCIE_SCOMINIT_IOP_SWAP_ATTR_ERR if invalid IOP swap
//            attribute value is presented,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pcie_scominit_iop_init(
    const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // attribute storage
    uint8_t iop_config;
    uint8_t iop_swap[PROC_PCIE_SCOMINIT_NUM_IOP];
    uint8_t phb_active_mask;
    bool    phb_active[PROC_PCIE_SCOMINIT_NUM_PHB];
    uint8_t refclock_active_mask;
    bool    refclock_active[PROC_PCIE_SCOMINIT_NUM_PHB];

    // data buffers for GP4/GP0 accesses
    ecmdDataBufferBase gp4_data(64);
    ecmdDataBufferBase gp0_data(64);

    // mark function entry
    FAPI_INF("proc_pcie_scominit_iop_init: Start");

    do
    {
        // retrieve IOP lane configuration and check value received
        FAPI_DBG("proc_pcie_scominit_iop_init: Querying IOP lane configuration attribute");
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_IOP_CONFIG,
                           &i_target,
                           iop_config);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_IOP_CONFIG)");
            break;
        }
        FAPI_DBG("proc_pcie_scominit_iop_init: ATTR_PROC_PCIE_IOP_CONFIG = %02X",
                 iop_config);
        // ensure that encoded value is supported
        if (iop_config > PCIE_GP4_IOP_LANE_CFG_MAX)
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Invalid IOP lane configuration attribute value 0x%02X",
                     iop_config);
            const uint8_t& ATTR_DATA = iop_config;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_PCIE_SCOMINIT_IOP_CONFIG_ATTR_ERR);
            break;
        }

        // retrieve per-IOP swap configuration and check value received
        FAPI_DBG("proc_pcie_scominit_iop_init: Querying per-IOP swap attribute");
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_IOP_SWAP,
                           &i_target,
                           iop_swap);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_IOP_SWAP)");
            break;
        }
        for (size_t i = 0; (i < PROC_PCIE_SCOMINIT_NUM_IOP) && rc.ok(); i++)
        {
            FAPI_DBG("proc_pcie_scominit_iop_init: ATTR_PROC_PCIE_IOP_SWAP[%d]= %02X",
                     i, iop_swap[i]);
            if (iop_swap[i] > PCIE_GP4_IOP_SWAP_MAX)
            {
                FAPI_ERR("proc_pcie_scominit_iop_init: Invalid IOP%d swap attribute value 0x%02X",
                         i, iop_swap[i]);
                const uint8_t& IOP_DATA = i;
                const uint8_t ATTR_DATA = iop_swap[i];
                FAPI_SET_HWP_ERROR(rc, RC_PROC_PCIE_SCOMINIT_IOP_SWAP_ATTR_ERR);
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // set PCIe GP4 mask for IOP lane configuration/swap setup
        rc_ecmd |= gp4_data.insertFromRight(
            iop_config,
            PCIE_GP4_IOP_LANE_CFG_START_BIT,
            (PCIE_GP4_IOP_LANE_CFG_END_BIT-
             PCIE_GP4_IOP_LANE_CFG_START_BIT+1));

        for (size_t i = 0; (i < PROC_PCIE_SCOMINIT_NUM_IOP) && !rc_ecmd; i++)
        {
            rc_ecmd |= gp4_data.insertFromRight(
                iop_swap[i],
                PCIE_GP4_IOP_SWAP_START_BIT[i],
                (PCIE_GP4_IOP_SWAP_END_BIT[i]-
                 PCIE_GP4_IOP_SWAP_START_BIT[i]+1));
        }
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error 0x%x setting up PCIe GP4 IOP config data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write PCIe GP4 data via OR mask register
        FAPI_DBG("proc_pcie_scominit_iop_init: Writing PCIe GP4 to set IOP configuration");
        rc = fapiPutScom(i_target, PCIE_GP4_OR_0x09000007, gp4_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error from fapiPutScom (PCIE_GP4_OR_0x09000007)");
            break;
        }

        // retrieve active PHB/refclock enable attributes and check value received
        FAPI_DBG("proc_pcie_scominit_iop_init: Querying PHB active attribute");
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_PHB_ACTIVE,
                           &i_target,
                           phb_active_mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_PHB_ACTIVE)");
            break;
        }

        FAPI_DBG("proc_pcie_scominit_iop_init: Querying refclock enable attribute");
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_REFCLOCK_ENABLE,
                           &i_target,
                           refclock_active_mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_REFCLOCK_ENABLE)");
            break;
        }

        for (size_t i = 0; (i < PROC_PCIE_SCOMINIT_NUM_PHB); i++)
        {
            phb_active[i] = ((phb_active_mask >> (7-i)) & 0x1)?(true):(false);
            refclock_active[i] = ((refclock_active_mask >> (7-i)) & 0x1)?(true):(false);
        }

        // set PCIe GP0 mask for PHB iovalid/refclock enable
        for (size_t i = 0; (i < PROC_PCIE_SCOMINIT_NUM_PHB) && !rc_ecmd; i++)
        {
            rc_ecmd |= gp0_data.writeBit(
                PCIE_GP0_PHB_IOVALID_BIT[i],
                phb_active[i]);
            rc_ecmd |= gp0_data.writeBit(
                PCIE_GP0_PHB_REFCLOCK_DRIVE_EN_BIT[i],
                refclock_active[i]);
        }
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error 0x%x setting up PCIe GP0 data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write PCIe GP0 data via OR mask register
        FAPI_DBG("proc_pcie_scominit_iop_init: Writing PCIe GP0 to set PHB iovalids and refclock drive enables");
        rc = fapiPutScom(i_target, PCIE_GP0_OR_0x09000005, gp0_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error from fapiPutScom (PCIE_GP0_OR_0x09000005)");
            break;
        }

        // set PCIe GP4 mask for IOP reset
        rc_ecmd |= gp4_data.flushTo0();
        for (size_t i = 0; (i < PROC_PCIE_SCOMINIT_NUM_IOP) && !rc_ecmd; i++)
        {
            rc_ecmd |= gp4_data.setBit(
                PCIE_GP4_IOP_RESET_BIT[i]);
        }
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error 0x%x setting up PCIe GP4 IOP reset data buffer (set)",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write PCIe GP4 OR mask register (set reset bit)
        FAPI_DBG("proc_pcie_scominit_iop_init: Writing PCIe GP4 to set IOP reset");
        rc = fapiPutScom(i_target, PCIE_GP4_OR_0x09000007, gp4_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error from fapiPutScom (PCIE_GP4_OR_0x09000007)");
            break;
        }

        // invert data buffer to clear reset bits
        rc_ecmd |= gp4_data.invert();
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error 0x%x setting up PCIe GP4 IOP reset data buffer (clear)",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write PCIe GP4 AND mask register (clear reset bit)
        FAPI_DBG("proc_pcie_scominit_iop_init: Writing PCIe GP4 to clear IOP reset");
        rc = fapiPutScom(i_target, PCIE_GP4_AND_0x09000006, gp4_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_init: Error from fapiPutScom (PCIE_GP4_AND_0x09000006)");
            break;
        }

    } while(0);

    // mark function exit
    FAPI_INF("proc_pcie_scominit_iop_init: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: apply IOP customization via SCOM initfile
// parameters: i_target => processor chip target
// returns: FAPI_RC_SUCCESS if initfile evaluation is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pcie_scominit_iop_config(
    const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    std::vector<fapi::Target> targets;

    // mark function entry
    FAPI_INF("proc_pcie_scominit_iop_config: Start");

    do
    {
        // execute Phase1 SCOM initfile
        targets.push_back(i_target);
        FAPI_INF("proc_pcie_scominit_iop_config: Executing %s on %s",
                 PROC_PCIE_SCOMINIT_PHASE1_IF, i_target.toEcmdString());
        FAPI_EXEC_HWP(
            rc,
            fapiHwpExecInitFile,
            targets,
            PROC_PCIE_SCOMINIT_PHASE1_IF);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit_iop_config: Error from fapiHwpExecInitfile executing %s on %s",
                     PROC_PCIE_SCOMINIT_PHASE1_IF,
                     i_target.toEcmdString());
            break;
        }
    } while(0);

    // mark function exit
    FAPI_INF("proc_pcie_scominit_iop_config: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: mark IOP programming complete (executed after all IOP
//           customization is complete)
// parameters: i_target => processor chip target
// returns: FAPI_RC_SUCCESS if program complete is successful for all IOPs,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_pcie_scominit_iop_complete(
    const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data(64), mask(64);

    // mark function entry
    FAPI_INF("proc_pcie_scominit_iop_complete: Start");

    do
    {
        // configure data/mask required to set program complete data pattern
        rc_ecmd |= data.setBit(PLL_GLOBAL_CONTROL2_PROG_COMPLETE_BIT);
        rc_ecmd |= mask.setBit(PLL_GLOBAL_CONTROL2_PROG_COMPLETE_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_scominit_iop_complete: Error 0x%x setting up PCIe PLL Global Control 2 register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // set IOP program complete
        for (size_t i = 0; i < PROC_PCIE_SCOMINIT_NUM_IOP; i++)
        {
            rc = fapiPutScomUnderMask(i_target,
                                      PROC_PCIE_SCOMINIT_PLL_GLOBAL_CONTROL2[i],
                                      data,
                                      mask);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_scominit_iop_complete: Error from fapiPutScomUnderMask (PCIE_IOP%d_PLL_GLOBAL_CONTROL2_0x%016llX)",
                         i, PROC_PCIE_SCOMINIT_PLL_GLOBAL_CONTROL2[i]);
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // form ETU reset data buffer
        rc_ecmd |= data.flushTo0();
        if (rc_ecmd)
        {
            FAPI_ERR("proc_pcie_scominit_iop_complete: Error 0x%x setting up ETU reset register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // clear ETU reset
        for (size_t i = 0; (i < PROC_PCIE_SCOMINIT_NUM_PHB); i++)
        {
            rc = fapiPutScom(i_target,
                             PROC_PCIE_SCOMINIT_ETU_RESET[i],
                             data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_scominit_iop_complete: Error from fapiPutScom (PCIE%d_ETU_RESET_0x%016llX)",
                          i, PROC_PCIE_SCOMINIT_ETU_RESET[i]);
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }

    } while(0);

    // mark function exit
    FAPI_INF("proc_pcie_scominit_iop_complete: End");
    return rc;
}


// HWP entry point, comments in header
fapi::ReturnCode proc_pcie_scominit(
    const fapi::Target & i_target)
{
    fapi::ReturnCode rc;
    uint8_t pcie_enabled;

    // mark HWP entry
    FAPI_INF("proc_pcie_scominit: Start");

    do
    {
        // check for supported target type
        if (i_target.getType() != fapi::TARGET_TYPE_PROC_CHIP)
        {
            FAPI_ERR("proc_pcie_scominit: Unsupported target type");
            FAPI_SET_HWP_ERROR(rc, RC_PROC_PCIE_SCOMINIT_INVALID_TARGET);
            break;
        }

        // query PCIE partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_ENABLE,
                           &i_target,
                           pcie_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_pcie_scominit: Error querying ATTR_PROC_PCIE_ENABLE");
            break;
        }

        // initialize/configure/finalize IOP programming (only if partial good
        // attribute is set)
        if (pcie_enabled == fapi::ENUM_ATTR_PROC_PCIE_ENABLE_ENABLE)
        {
            rc = proc_pcie_scominit_iop_init(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_scominit: Error from proc_pcie_scominit_iop_init");
                break;
            }

            rc = proc_pcie_scominit_iop_config(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_scominit: Error from proc_pcie_scominit_iop_config");
                break;
            }

            rc = proc_pcie_scominit_iop_complete(i_target);
            if (!rc.ok())
            {
                FAPI_ERR("proc_pcie_scominit: Error from proc_pcie_scominit_iop_complete");
                break;
            }
        }
        else
        {
            FAPI_DBG("proc_pcie_scominit: Skipping initialization (partial good)");
        }

    } while(0);

    // mark HWP exit
    FAPI_INF("proc_pcie_scominit: End");
    return rc;
}


} // extern "C"
