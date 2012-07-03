/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/slave_sbe/proc_revert_sbe_mcs_setup/proc_revert_sbe_mcs_setup.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
// $Id: proc_revert_sbe_mcs_setup.C,v 1.2 2012/06/29 06:15:33 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_revert_sbe_mcs_setup.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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
#include "proc_revert_sbe_mcs_setup.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: reset MCFGP BAR valid bit, base address and size fields to restore
//           register flush state
// parameters: i_target => MCS chiplet target
// returns: FAPI_RC_SUCCESS if register write is successful,
//          else failing return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_revert_sbe_mcs_setup_reset_mcfgp(
    const fapi::Target& i_target)
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
        rc = fapiPutScomUnderMask(i_target,
                                  MCS_MCFGP_0x02011800,
                                  mcfgp_data,
                                  mcfgp_mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup_reset_mcfgp: fapiPutScomUnderMask error (MCS_MCFGP_0x02011800)");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_revert_sbe_mcs_setup_reset_mcfgp: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set MCI FIR Mask channel timeout bit, to restore register flush
//           state
// parameters: i_target => MCS chiplet target
// returns: FAPI_RC_SUCCESS if register write is successful,
//          else failing return code
//------------------------------------------------------------------------------
fapi::ReturnCode proc_revert_sbe_mcs_setup_reset_mcifirmask(
    const fapi::Target& i_target)
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
        rc = fapiPutScom(i_target,
                         MCS_MCIFIRMASK_OR_0x02011845,
                         mcifirmask_or_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup_reset_mcifirmask: fapiPutScom error (MCS_MCIFIRMASK_OR_0x02011845)");
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

    // vector to hold MCS chiplet targets
    std::vector<fapi::Target> mcs_chiplets;

    // mark HWP entry
    FAPI_IMP("proc_revert_sbe_mcs_setup: Entering ...");

    do
    {
        // loop over all functional MCS chiplets, revert SBE configuration
        // of BAR/FIR mask registers back to flush state
        rc = fapiGetChildChiplets(i_target,
                                  fapi::TARGET_TYPE_MCS_CHIPLET,
                                  mcs_chiplets,
                                  fapi::TARGET_STATE_FUNCTIONAL);
        if (!rc.ok())
        {
            FAPI_ERR("proc_revert_sbe_mcs_setup: Error from fapiGetChildChiplets");
            break;
        }

        for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin();
             i != mcs_chiplets.end();
             i++)
        {
            rc = proc_revert_sbe_mcs_setup_reset_mcfgp(*i);
            if (!rc.ok())
            {
                FAPI_ERR("proc_revert_sbe_mcs_setup: Error from proc_revert_sbe_mcs_setup_reset_mcfgp");
                break;
            }

            rc = proc_revert_sbe_mcs_setup_reset_mcifirmask(*i);
            if (!rc.ok())
            {
                FAPI_ERR("proc_revert_sbe_mcs_setup: Error from proc_revert_sbe_mcs_setup_reset_mcfgp");
                break;
            }
        }
    } while(0);

    // log function exit
    FAPI_IMP("proc_revert_sbe_mcs_setup: Exiting ...");
    return rc;
}


} // extern "C"
