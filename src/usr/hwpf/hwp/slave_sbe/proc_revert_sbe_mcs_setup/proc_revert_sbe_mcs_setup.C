/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_revert_sbe_mcs_setup/proc_revert_sbe_mcs_setup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: proc_revert_sbe_mcs_setup.C,v 1.7 2013/04/27 17:23:41 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_revert_sbe_mcs_setup.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_revert_sbe_mcs_setup.C
// *! DESCRIPTION : Revert MCS configuration applied by SBE (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "p8_scom_addresses.H"
#include "proc_revert_sbe_mcs_setup.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: translate base SCOM address to chiplet specific offset
// parameters: i_input_addr   => input SCOM address
//             i_mcs_unit_num => chip unit number
// returns: translated SCOM address
//------------------------------------------------------------------------------
uint64_t proc_revert_sbe_mcs_setup_xlate_address(
    const uint64_t i_input_addr,
    const uint8_t i_mcs_unit_num)
{
    return(i_input_addr +
           (0x400 * (i_mcs_unit_num / 4)) +
           (0x80 * (i_mcs_unit_num % 4)));
}


//------------------------------------------------------------------------------
// function: reset MCFGP BAR valid bit, base address and size fields to restore
//           register flush state
// parameters: i_target       => chip target
//             i_mcs_unit_num => chip unit number
// returns: FAPI_RC_SUCCESS if register write is successful,
//          else failing return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_revert_sbe_mcs_setup_reset_mcfgp(
    const fapi::Target& i_target,
    const uint8_t i_mcs_unit_num)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase mcfgp_data(64);
    ecmdDataBufferBase mcfgp_mask(64);

    // mark function entry
    FAPI_DBG("proc_revert_sbe_mcs_setup_reset_mcfgp: Start");

    do
    {
        // clear fields manipulated by SBE (to restore logic flush state)
        rc_ecmd |= mcfgp_mask.setBit(MCFGP_VALID_BIT);
        rc_ecmd |= mcfgp_mask.setBit(
            MCFGP_UNITS_PER_GROUP_START_BIT,
            (MCFGP_UNITS_PER_GROUP_END_BIT -
             MCFGP_UNITS_PER_GROUP_START_BIT + 1));
        rc_ecmd |= mcfgp_mask.setBit(
            MCFGP_GROUP_MEMBER_ID_START_BIT,
            (MCFGP_GROUP_MEMBER_ID_END_BIT -
             MCFGP_GROUP_MEMBER_ID_START_BIT + 1));
        rc_ecmd |= mcfgp_mask.setBit(
            MCFGP_GROUP_SIZE_START_BIT,
            (MCFGP_GROUP_SIZE_END_BIT -
             MCFGP_GROUP_SIZE_START_BIT + 1));
        rc_ecmd |= mcfgp_mask.setBit(MCFGP_FASTPATH_ENABLE_BIT);
        rc_ecmd |= mcfgp_mask.setBit(
            MCFGP_GROUP_BASE_ADDR_START_BIT,
            (MCFGP_GROUP_BASE_ADDR_END_BIT -
             MCFGP_GROUP_BASE_ADDR_START_BIT + 1));

        // check buffer manipulation return code
        if (rc_ecmd)
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup_reset_mcfgp: Error 0x%X setting up MCFGP mask data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register
        rc = fapiPutScomUnderMask(
            i_target,
            proc_revert_sbe_mcs_setup_xlate_address(MCS_MCFGP_0x02011800,
                                                    i_mcs_unit_num),
            mcfgp_data,
            mcfgp_mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup_reset_mcfgp: fapiPutScomUnderMask error (MCS_MCFGP_0x%08llX)",
                     proc_revert_sbe_mcs_setup_xlate_address(MCS_MCFGP_0x02011800,
                                                             i_mcs_unit_num));
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_revert_sbe_mcs_setup_reset_mcfgp: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set MCI FIR Mask channel timeout bits, to restore register flush
//           state
// parameters: i_target       => chip target
//             i_mcs_unit_num => chip unit number
// returns: FAPI_RC_SUCCESS if register write is successful,
//          else failing return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_revert_sbe_mcs_setup_reset_mcifirmask(
    const fapi::Target& i_target,
    const uint8_t i_mcs_unit_num)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase mcifirmask_or_data(64);

    // mark function entry
    FAPI_DBG("proc_revert_sbe_mcs_setup_reset_mcifirmask: Start");

    do
    {
        // set fields manipulated by SBE (to restore logic flush state)
        rc_ecmd |= mcifirmask_or_data.setBit(
            MCIFIR_CL_TIMEOUT_BIT);
       rc_ecmd |= mcifirmask_or_data.setBit(
            MCIFIR_CL_TIMEOUT_DUE_TO_CHANNEL_BIT);

        // check buffer manipulation return code
        if (rc_ecmd)
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup_reset_mcifirmask: Error 0x%X setting up MCI FIR Mask register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register
        rc = fapiPutScom(
            i_target,
            proc_revert_sbe_mcs_setup_xlate_address(MCS_MCIFIRMASK_OR_0x02011845,
                                                    i_mcs_unit_num),
            mcifirmask_or_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup_reset_mcifirmask: fapiPutScom error (MCS_MCIFIRMASK_OR_0x%08llX)",
                     proc_revert_sbe_mcs_setup_xlate_address(MCS_MCIFIRMASK_OR_0x02011845,
                                                             i_mcs_unit_num));
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_revert_sbe_mcs_setup_reset_mcifirmask: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: proc_revert_sbe_mcs_setup HWP entry point
//           NOTE: see comments above function prototype in header
//------------------------------------------------------------------------------
fapi::ReturnCode proc_revert_sbe_mcs_setup(
    const fapi::Target& i_target)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase gp0_data(64);
    ecmdDataBufferBase mcsmode1_reset_data(64);
    bool mc_fenced[2] = { true, true };
    uint8_t mcs_unit_id = 0x0;

    // vector to hold MCS chiplet targets
    std::vector<fapi::Target> mcs_chiplets;

    // mark HWP entry
    FAPI_IMP("proc_revert_sbe_mcs_setup: Entering ...");

    do
    {
        // read GP0 to determine MCL/MCR partial good state
        rc = fapiGetScom(i_target, NEST_GP0_0x02000000, gp0_data);

        if (!rc.ok())
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup: fapiGetScom error (NEST_GP0_0x02000000)");
            break;
        }

        mc_fenced[0] = gp0_data.isBitClear(NEST_GP0_MCL_FENCE_B_BIT);
        mc_fenced[1] = gp0_data.isBitClear(NEST_GP0_MCR_FENCE_B_BIT);

        // loop over all present MCS chiplets, revert SBE configuration
        // of BAR/FIR mask registers back to flush state
        rc = fapiGetChildChiplets(i_target,
                                  fapi::TARGET_TYPE_MCS_CHIPLET,
                                  mcs_chiplets,
                                  fapi::TARGET_STATE_PRESENT);
        if (!rc.ok())
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup: Error from fapiGetChildChiplets");
            break;
        }

        for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin();
             i != mcs_chiplets.end();
             i++)
        {
            // read chip unit number
            rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS,
                               &(*i),
                               mcs_unit_id);

            if (!rc.ok())
            {
                FAPI_ERR("proc_revert_sbe_mcs_setup: Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
                break;
            }

            // reset all chiplets which are present (based on GP0 partial good data)
            // this handles the case of reverting configuration which was written
            // by SBE code for chiplets which are not considered functional by platform
            if (!mc_fenced[mcs_unit_id / 4])
            {
                rc = proc_revert_sbe_mcs_setup_reset_mcfgp(i_target,
                                                           mcs_unit_id);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_revert_sbe_mcs_setup: Error from proc_revert_sbe_mcs_setup_reset_mcfgp");
                    break;
                }

                FAPI_DBG("proc_revert_sbe_mcs_setup: reset MCSMODE1");
                rc = fapiPutScom(
                    i_target,
                    proc_revert_sbe_mcs_setup_xlate_address(MCS_MCSMODE1_0x02011808,
                                                            mcs_unit_id),
                    mcsmode1_reset_data);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_revert_sbe_mcs_setup: fapiPutScom error (MCS_MCSMODE1_0x%08llX)",
                             proc_revert_sbe_mcs_setup_xlate_address(MCS_MCSMODE1_0x02011808, mcs_unit_id));
                    break;
                }

                rc = proc_revert_sbe_mcs_setup_reset_mcifirmask(i_target,
                                                                mcs_unit_id);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_revert_sbe_mcs_setup: Error from proc_revert_sbe_mcs_setup_reset_mcfgp");
                    break;
                }
            }
        }
    } while(0);

    // log function exit
    FAPI_IMP("proc_revert_sbe_mcs_setup: Exiting ...");
    return rc;
}


} // extern "C"
