/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/edi_ei_initialization/proc_fab_iovalid/proc_fab_iovalid.C $ */
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
// $Id: proc_fab_iovalid.C,v 1.9 2013/01/21 01:42:45 jmcgill Exp $
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
#include "p8_scom_addresses.H"
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
// parameters: i_proc_chip     => structure providing:
//                                o target for this chip
//                                o X busses to act on
//             i_set_not_clear => define desired operation (true=set,
//                                false=clear)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid_manage_x_links(
    proc_fab_iovalid_proc_chip& i_proc_chip,
    bool i_set_not_clear)
{
    // data buffer to hold iovalid bit mask
    ecmdDataBufferBase active_link_mask(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // partial good attribute
    uint8_t xbus_enable_attr;

    // mark function entry
    FAPI_DBG("proc_fab_iovalid_manage_x_links: Start");

    do
    {
        // set mask bit for each link to act on
        if (i_proc_chip.x0 ||
            i_proc_chip.x1 ||
            i_proc_chip.x2 ||
            i_proc_chip.x3)
        {
            // query XBUS partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_X_ENABLE,
                               &(i_proc_chip.this_chip),
                               xbus_enable_attr);
            if (!rc.ok())
            {
                FAPI_ERR("proc_fab_iovalid_manage_x_links: Error querying ATTR_PROC_X_ENABLE");
                break;
            }

            if (xbus_enable_attr != fapi::ENUM_ATTR_PROC_X_ENABLE_ENABLE)
            {
                FAPI_ERR("proc_fab_iovalid_manage_x_links: Partial good attribute error");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_FAB_IOVALID_X_PARTIAL_GOOD_ERR);
                break;
            }

            if (i_proc_chip.x0)
            {
                FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X0 to active link mask");
                rc_ecmd |= active_link_mask.setBit(X_GP0_X0_IOVALID_BIT);
            }
            if (i_proc_chip.x1)
            {
                FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X1 to active link mask");
                rc_ecmd |= active_link_mask.setBit(X_GP0_X1_IOVALID_BIT);
            }
            if (i_proc_chip.x2)
            {
                FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X2 to active link mask");
                rc_ecmd |= active_link_mask.setBit(X_GP0_X2_IOVALID_BIT);
            }
            if (i_proc_chip.x3)
            {
                FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X3 to active link mask");
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
            rc = proc_fab_iovalid_write_gp0_mask(i_proc_chip.this_chip,
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
    } while(0);

    // mark function exit
    FAPI_DBG("proc_fab_iovalid_manage_x_links: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set/clear A bus iovalid bits on one chip
// parameters: i_proc_chip     => structure providing:
//                                o target for this chip
//                                o A busses to act on
//             i_set_not_clear => define desired operation (true=set,
//                                false=clear)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid_manage_a_links(
    proc_fab_iovalid_proc_chip& i_proc_chip,
    bool i_set_not_clear)
{
    // data buffer to hold iovalid bit mask
    ecmdDataBufferBase active_link_mask(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // partial good attribute
    uint8_t abus_enable_attr;

    // mark function entry
    FAPI_DBG("proc_fab_iovalid_manage_a_links: Start");

    do
    {
        // set mask bit for each link to act on
        if (i_proc_chip.a0 ||
            i_proc_chip.a1 ||
            i_proc_chip.a2)
        {
            // query ABUS partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_A_ENABLE,
                               &(i_proc_chip.this_chip),
                               abus_enable_attr);
            if (!rc.ok())
            {
                FAPI_ERR("proc_fab_iovalid_manage_a_links: Error querying ATTR_PROC_A_ENABLE");
                break;
            }

            if (abus_enable_attr != fapi::ENUM_ATTR_PROC_A_ENABLE_ENABLE)
            {
                FAPI_ERR("proc_fab_iovalid_manage_a_links: Partial good attribute error");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_FAB_IOVALID_A_PARTIAL_GOOD_ERR);
                break;
            }

            if (i_proc_chip.a0)
            {
                FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A0 to active link mask");
                rc_ecmd |= active_link_mask.setBit(A_GP0_A0_IOVALID_BIT);
            }
            if (i_proc_chip.a1)
            {
                FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A1 to active link mask");
                rc_ecmd |= active_link_mask.setBit(A_GP0_A1_IOVALID_BIT);
            }
            if (i_proc_chip.a2)
            {
                FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A2 to active link mask");
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
            rc = proc_fab_iovalid_write_gp0_mask(i_proc_chip.this_chip,
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
    } while(0);

    // mark function exit
    FAPI_DBG("proc_fab_iovalid_manage_a_links: End");
    return rc;
}


//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid(
    std::vector<proc_fab_iovalid_proc_chip>& i_proc_chips,
    bool i_set_not_clear)
{
    // return code
    fapi::ReturnCode rc;
    // iterator for HWP input vector
    std::vector<proc_fab_iovalid_proc_chip>::iterator iter;

    // mark HWP entry
    FAPI_IMP("proc_fab_iovalid: Entering ...");

    do
    {
        // loop over all chips in input vector
        for (iter = i_proc_chips.begin();
             iter != i_proc_chips.end();
             iter++)
        {
            rc = proc_fab_iovalid_manage_x_links(*iter, i_set_not_clear);
            if (!rc.ok())
            {
                FAPI_ERR("proc_fab_iovalid: Error from proc_fab_iovalid_manage_x_links");
                break;
            }

            rc = proc_fab_iovalid_manage_a_links(*iter, i_set_not_clear);
            if (!rc.ok())
            {
                FAPI_ERR("proc_fab_iovalid: Error from proc_fab_iovalid_manage_a_links");
                break;
            }
        }
    } while(0);

    // log function exit
    FAPI_IMP("proc_fab_iovalid: Exiting ...");
    return rc;
}

} // extern "C"
