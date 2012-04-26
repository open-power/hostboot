//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/edi_ei_initialization/proc_fab_iovalid/proc_fab_iovalid.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
// $Id: proc_fab_iovalid.C,v 1.6 2012/04/16 19:44:55 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_fab_iovalid.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_fab_iovalid.C
// *! DESCRIPTION : Manage X/A link iovalid controls (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_fab_iovalid.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: utility subroutine which writes chiplet GP0 register to
//           set/clear desired iovalid bits
// parameters: i_target            => chip target
//             i_active_link_mask  => bit mask defining active links to act on
//             i_set_not_clear     => define desired operation
//                                    (true=set, false=clear)
//             i_gp0_and_mask_addr => SCOM address for chiplet GP0 AND
//                                    mask register
//             i_gp0_or_mask_addr  => SCOM address for chiplet GP0 OR
//                                    mask register
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid_write_gp0_mask(
    const fapi::Target& i_target,
    ecmdDataBufferBase& i_active_link_mask,
    bool i_set_not_clear,
    const uint32_t& i_gp0_and_mask_addr,
    const uint32_t& i_gp0_or_mask_addr)
{
    // data buffer to hold final iovalid bit mask
    ecmdDataBufferBase mask(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_fab_iovalid_write_gp0_mask: Start");

    do
    {
        // copy input mask
        rc_ecmd = i_active_link_mask.copy(mask);
        // form final mask based on desired operation (set/clear)
        if (!i_set_not_clear)
        {
            FAPI_DBG("proc_fab_iovalid_write_gp0_mask: Inverting active link mask");
            rc_ecmd |= mask.invert();
        }

        // check return code from buffer manipulation operations
        rc.setEcmdError(rc_ecmd);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_write_gp0_mask: Error 0x%x setting up iovalid mask data buffer",
                     rc_ecmd);
            break;
        }

        // write GP0 register (use OR mask address for set operation,
        // AND mask address for clear operation)
        rc = fapiPutScom(i_target,
                         i_set_not_clear?i_gp0_or_mask_addr:i_gp0_and_mask_addr,
                         mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_write_gp0_mask: fapiPutScom error (GP0 Register 0x%08X)",
                     i_set_not_clear?i_gp0_or_mask_addr:i_gp0_and_mask_addr);
            break;
        }

    } while (0);

    // mark function exit
    FAPI_DBG("proc_fab_iovalid_write_gp0_mask: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set/clear X bus iovalid bits on one chip
// parameters: i_smp_proc_chip => pointer to structure providing:
//                                  o target for this chip
//                                  o vector of structs representing X bus
//                                    connections (empty if no connection)
//             i_set_not_clear => define desired operation (true=set, false=clear)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid_manage_x_links(
    proc_fab_smp_proc_chip* i_smp_proc_chip,
    bool i_set_not_clear)
{
    // data buffer to hold iovalid bit mask
    ecmdDataBufferBase active_link_mask(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_fab_iovalid_manage_x_links: Start");

    // set mask bit for each link
    std::vector<proc_fab_smp_x_bus*>::iterator i;
    for (i = i_smp_proc_chip->x_busses.begin();
         i != i_smp_proc_chip->x_busses.end();
         i++)
    {
        proc_fab_smp_x_bus_id src_chip_bus_id = (*i)->src_chip_bus_id;
        FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X%d to active link mask",
                 (*i)->src_chip_bus_id);
        if (src_chip_bus_id == FBC_BUS_X0)
        {
            rc_ecmd |= active_link_mask.setBit(X_GP0_X0_IOVALID_BIT);
        }
        else if (src_chip_bus_id == FBC_BUS_X1)
        {
            rc_ecmd |= active_link_mask.setBit(X_GP0_X1_IOVALID_BIT);
        }
        else if (src_chip_bus_id == FBC_BUS_X2)
        {
            rc_ecmd |= active_link_mask.setBit(X_GP0_X2_IOVALID_BIT);
        }
        else
        {
            rc_ecmd |= active_link_mask.setBit(X_GP0_X3_IOVALID_BIT);
        }

        // check aggregate return code from buffer manipulation operations
        rc.setEcmdError(rc_ecmd);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_x_links: Error 0x%x setting up active link mask data buffer",
                     rc_ecmd);
            break;
        }

        // write appropriate GP0 mask register to perform desired operation
        rc = proc_fab_iovalid_write_gp0_mask(i_smp_proc_chip->this_chip,
                                             active_link_mask,
                                             i_set_not_clear,
                                             X_GP0_AND_0x04000004,
                                             X_GP0_OR_0x04000005);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_x_links: Error from proc_fab_iovalid_write_gp0_mask");
            break;
        }
    }

    // mark function exit
    FAPI_DBG("proc_fab_iovalid_manage_x_links: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set/clear A bus iovalid bits on one chip
// parameters: i_smp_proc_chip => pointer to structure providing:
//                                  o target for this chip
//                                  o vector of structs representing A bus
//                                    connections (empty if no connection)
//             i_set_not_clear => define desired operation (true=set, false=clear)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid_manage_a_links(
    proc_fab_smp_proc_chip* i_smp_proc_chip,
    bool i_set_not_clear)
{
    // data buffer to hold iovalid bit mask
    ecmdDataBufferBase active_link_mask(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_fab_iovalid_manage_a_links: Start");

    // set mask bit for each link
    std::vector<proc_fab_smp_a_bus*>::iterator i;
    for (i = i_smp_proc_chip->a_busses.begin();
         i != i_smp_proc_chip->a_busses.end();
         i++)
    {
        proc_fab_smp_a_bus_id src_chip_bus_id = (*i)->src_chip_bus_id;
        FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A%d to active link mask",
                 (*i)->src_chip_bus_id);
        if (src_chip_bus_id == FBC_BUS_A0)
        {
            rc_ecmd |= active_link_mask.setBit(A_GP0_A0_IOVALID_BIT);
        }
        else if (src_chip_bus_id == FBC_BUS_A1)
        {
            rc_ecmd |= active_link_mask.setBit(A_GP0_A1_IOVALID_BIT);
        }
        else
        {
            rc_ecmd |= active_link_mask.setBit(A_GP0_A2_IOVALID_BIT);
        }

        // check aggregate return code from buffer manipulation operations
        rc.setEcmdError(rc_ecmd);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_a_links: Error 0x%x setting up active link mask data buffer",
                     rc_ecmd);
            break;
        }

        // write appropriate GP0 mask register to perform desired operation
        rc = proc_fab_iovalid_write_gp0_mask(i_smp_proc_chip->this_chip,
                                             active_link_mask,
                                             i_set_not_clear,
                                             A_GP0_AND_0x08000004,
                                             A_GP0_OR_0x08000005);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_a_links: Error from proc_fab_iovalid_write_gp0_mask");
            break;
        }
    }

    // mark function exit
    FAPI_DBG("proc_fab_iovalid_manage_a_links: End");
    return rc;
}


//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid(std::vector<proc_fab_smp_proc_chip *>& i_smp,
                                  bool i_manage_x,
                                  bool i_manage_a,
                                  bool i_set_not_clear)
{
    // return code
    fapi::ReturnCode rc;

    // mark HWP entry
    FAPI_IMP("proc_fab_iovalid: Entering ...");

    do
    {
        // make pass through entire SMP, validate inputs
        rc = proc_fab_smp_validate_smp(i_smp);
        if (rc)
        {
            FAPI_ERR("proc_fab_iovalid: Error from proc_fab_smp_validate_smp");
            break;
        }

        // loop over all chips composing SMP
        for (std::vector<proc_fab_smp_proc_chip *>::iterator i = i_smp.begin();
             i != i_smp.end();
             i++)
        {
            // operate on X links?
            if (i_manage_x)
            {
                rc = proc_fab_iovalid_manage_x_links(*i,
                                                     i_set_not_clear);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_fab_iovalid: Error from proc_fab_iovalid_manage_x_links");
                    break;
                }
            }

            // operate on A links?
            if (i_manage_a)
            {
                rc = proc_fab_iovalid_manage_a_links(*i,
                                                     i_set_not_clear);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_fab_iovalid: Error from proc_fab_iovalid_manage_a_links");
                    break;
                }
            }
        }
    } while(0);

    // log function exit
    FAPI_IMP("proc_fab_iovalid: Exiting ...");
    return rc;
}

} // extern "C"
