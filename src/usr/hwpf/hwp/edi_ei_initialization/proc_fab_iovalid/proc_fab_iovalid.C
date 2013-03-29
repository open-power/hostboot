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
// $Id: proc_fab_iovalid.C,v 1.10 2013/03/05 02:53:19 jmcgill Exp $
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
// function: utility subroutine which writes AND/OR mask register to
//           set/clear desired bits
// parameters: i_target        => target
//             i_active_mask   => bit mask defining active bits to act on
//             i_set_not_clear => define desired operation
//                                (true=set, false=clear)
//             i_and_mask_addr => SCOM address for AND mask register
//             i_or_mask_addr  => SCOM address for OR mask register
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid_write_active_mask(
    const fapi::Target& i_target,
    ecmdDataBufferBase& i_active_mask,
    bool i_set_not_clear,
    const uint32_t& i_and_mask_addr,
    const uint32_t& i_or_mask_addr)
{
    // data buffer to hold final bit mask
    ecmdDataBufferBase mask(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_fab_iovalid_write_active_mask: Start");

    do
    {
        // copy input mask
        rc_ecmd = i_active_mask.copy(mask);
        // form final mask based on desired operation (set/clear)
        if (!i_set_not_clear)
        {
            FAPI_DBG("proc_fab_iovalid_write_active_mask: Inverting active mask");
            rc_ecmd |= mask.invert();
        }

        // check return code from buffer manipulation operations
        rc.setEcmdError(rc_ecmd);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_write_active_mask: Error 0x%x setting up active mask data buffer",
                     rc_ecmd);
            break;
        }

        // write register (use OR mask address for set operation,
        // AND mask address for clear operation)
        rc = fapiPutScom(i_target,
                         i_set_not_clear?i_or_mask_addr:i_and_mask_addr,
                         mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_write_active_mask: fapiPutScom error (0x%08X)",
                     i_set_not_clear?i_or_mask_addr:i_and_mask_addr);
            break;
        }

    } while (0);

    // mark function exit
    FAPI_DBG("proc_fab_iovalid_write_active_mask: End");
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
    ecmdDataBufferBase gp0_iovalid_active(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_fab_iovalid_manage_x_links: Start");

    do
    {
        if (i_proc_chip.x0)
        {
            FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X0 to active link mask");
            rc_ecmd |= gp0_iovalid_active.setBit(X_GP0_X0_IOVALID_BIT);
        }
        if (i_proc_chip.x1)
        {
            FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X1 to active link mask");
            rc_ecmd |= gp0_iovalid_active.setBit(X_GP0_X1_IOVALID_BIT);
        }
        if (i_proc_chip.x2)
        {
            FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X2 to active link mask");
            rc_ecmd |= gp0_iovalid_active.setBit(X_GP0_X2_IOVALID_BIT);
        }
        if (i_proc_chip.x3)
        {
            FAPI_DBG("proc_fab_iovalid_manage_x_links: Adding link X3 to active link mask");
            rc_ecmd |= gp0_iovalid_active.setBit(X_GP0_X3_IOVALID_BIT);
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
        rc = proc_fab_iovalid_write_active_mask(i_proc_chip.this_chip,
                                                gp0_iovalid_active,
                                                i_set_not_clear,
                                                X_GP0_AND_0x04000004,
                                                X_GP0_OR_0x04000005);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_x_links: Error from proc_fab_iovalid_write_active_mask");
            break;
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
    ecmdDataBufferBase gp0_iovalid_active(64);
    ecmdDataBufferBase secure_iovalid_data(64);
    ecmdDataBufferBase secure_iovalid_mask(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;

    // secure iovalid attribute
    uint8_t secure_iovalid_present_attr = 1;

    // mark function entry
    FAPI_DBG("proc_fab_iovalid_manage_a_links: Start");

    do
    {
        // query secure iovalid attribute
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_SECURE_IOVALID_PRESENT,
                           &(i_proc_chip.this_chip),
                           secure_iovalid_present_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_a_links: Error querying ATTR_CHIP_EC_FEATURE_SECURE_IOVALID_PRESENT");
            break;
        }

        if (i_proc_chip.a0)
        {
            FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A0 to active link mask");
            rc_ecmd |= gp0_iovalid_active.setBit(A_GP0_A0_IOVALID_BIT);
            if (secure_iovalid_present_attr)
            {
                FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A0 to active link mask (secure)");
                if (i_set_not_clear)
                {
                    rc_ecmd |= secure_iovalid_data.setBit(ADU_IOS_LINK_EN_A0_IOVALID_BIT);
                }
                rc_ecmd |= secure_iovalid_mask.setBit(ADU_IOS_LINK_EN_A0_IOVALID_BIT);
            }
        }
        if (i_proc_chip.a1)
        {
            FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A1 to active link mask");
            rc_ecmd |= gp0_iovalid_active.setBit(A_GP0_A1_IOVALID_BIT);
            if (secure_iovalid_present_attr)
            {
                FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A1 to active link mask (secure)");
                if (i_set_not_clear)
                {
                    rc_ecmd |= secure_iovalid_data.setBit(ADU_IOS_LINK_EN_A1_IOVALID_BIT);
                }
                rc_ecmd |= secure_iovalid_mask.setBit(ADU_IOS_LINK_EN_A1_IOVALID_BIT);
            }
        }
        if (i_proc_chip.a2)
        {
            FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A2 to active link mask");
            rc_ecmd |= gp0_iovalid_active.setBit(A_GP0_A2_IOVALID_BIT);
            if (secure_iovalid_present_attr)
            {
                FAPI_DBG("proc_fab_iovalid_manage_a_links: Adding link A2 to active link mask (secure)");
                if (i_set_not_clear)
                {
                    rc_ecmd |= secure_iovalid_data.setBit(ADU_IOS_LINK_EN_A2_IOVALID_BIT);
                }
                rc_ecmd |= secure_iovalid_mask.setBit(ADU_IOS_LINK_EN_A2_IOVALID_BIT);
            }
        }

        // check aggregate return code from buffer manipulation operations
        rc.setEcmdError(rc_ecmd);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_a_links: Error 0x%x setting up active link mask data buffersa",
                     rc_ecmd);
            break;
        }

        // write appropriate GP0 mask register to perform desired operation
        rc = proc_fab_iovalid_write_active_mask(i_proc_chip.this_chip,
                                                gp0_iovalid_active,
                                                i_set_not_clear,
                                                A_GP0_AND_0x08000004,
                                                A_GP0_OR_0x08000005);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_a_links: Error from proc_fab_iovalid_write_active_mask");
            break;
        }

        // adjust secure iovalids if present
        if (secure_iovalid_present_attr)
        {
            rc = fapiPutScomUnderMask(i_proc_chip.this_chip,
                                      ADU_IOS_LINK_EN_0x02020019,
                                      secure_iovalid_data,
                                      secure_iovalid_mask);
            if (!rc.ok())
            {
                FAPI_ERR("proc_fab_iovalid_manage_a_links: fapiPutScomUnderMask error (ADU_IOS_LINK_EN_0x02020019)");
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_fab_iovalid_manage_a_links: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to manage PB RAS FIR setup
// parameters: i_proc_chip     => structure providing:
//                                o target for this chip
//                                o A/X busses to act on
//             i_set_not_clear => define desired iovalid operation (true=set,
//                                false=clear)
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_fab_iovalid_manage_ras_fir(
    proc_fab_iovalid_proc_chip& i_proc_chip,
    bool i_set_not_clear)
{
    ecmdDataBufferBase mask_active(64);
    ecmdDataBufferBase zero_data(64);
    ecmdDataBufferBase action_mask(64);

    // return codes
    uint32_t rc_ecmd = 0;
    fapi::ReturnCode rc;


    // mark function entry
    FAPI_DBG("proc_fab_iovalid_manage_ras_fir: Start");

    do
    {
        if (i_proc_chip.x0)
        {
            FAPI_DBG("proc_fab_iovalid_manage_ras_fir: Configuring RAS FIR for link X0");
            rc_ecmd |= mask_active.setBit(PB_RAS_FIR_X0_BIT);
            rc_ecmd |= action_mask.setBit(PB_RAS_FIR_X0_BIT);
        }
        if (i_proc_chip.x1)
        {
            FAPI_DBG("proc_fab_iovalid_manage_ras_fir: Configuring RAS FIR for link X1");
            rc_ecmd |= mask_active.setBit(PB_RAS_FIR_X1_BIT);
            rc_ecmd |= action_mask.setBit(PB_RAS_FIR_X1_BIT);
        }
        if (i_proc_chip.x2)
        {
            FAPI_DBG("proc_fab_iovalid_manage_ras_fir: Configuring RAS FIR for link X2");
            rc_ecmd |= mask_active.setBit(PB_RAS_FIR_X2_BIT);
            rc_ecmd |= action_mask.setBit(PB_RAS_FIR_X2_BIT);
        }
        if (i_proc_chip.x3)
        {
            FAPI_DBG("proc_fab_iovalid_manage_ras_fir: Configuring RAS FIR for link X3");
            rc_ecmd |= mask_active.setBit(PB_RAS_FIR_X3_BIT);
            rc_ecmd |= action_mask.setBit(PB_RAS_FIR_X3_BIT);
        }
        if (i_proc_chip.a0)
        {
            FAPI_DBG("proc_fab_iovalid_manage_ras_fir: Configuring RAS FIR for link A0");
            rc_ecmd |= mask_active.setBit(PB_RAS_FIR_A0_BIT);
            rc_ecmd |= action_mask.setBit(PB_RAS_FIR_A0_BIT);
        }
        if (i_proc_chip.a1)
        {
            FAPI_DBG("proc_fab_iovalid_manage_ras_fir: Configuring RAS FIR for link A1");
            rc_ecmd |= mask_active.setBit(PB_RAS_FIR_A1_BIT);
            rc_ecmd |= action_mask.setBit(PB_RAS_FIR_A1_BIT);
        }
        if (i_proc_chip.a2)
        {
            FAPI_DBG("proc_fab_iovalid_manage_ras_fir: Configuring RAS FIR for link A2");
            rc_ecmd |= mask_active.setBit(PB_RAS_FIR_A2_BIT);
            rc_ecmd |= action_mask.setBit(PB_RAS_FIR_A2_BIT);
        }

        // check aggregate return code from buffer manipulation operations
        rc.setEcmdError(rc_ecmd);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_ras_fir: Error 0x%x setting up active link mask data buffers",
                     rc_ecmd);
            break;
        }

        // write appropriate RAS FIR mask register to perform desired operation
        rc = proc_fab_iovalid_write_active_mask(i_proc_chip.this_chip,
                                                mask_active,
                                                !i_set_not_clear,
                                                PB_RAS_FIR_MASK_AND_0x02010C72,
                                                PB_RAS_FIR_MASK_OR_0x02010C73);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_ras_fir: Error from proc_fab_iovalid_write_active_mask");
            break;
        }

        // set RAS FIR action registers (action0=0b0, action1=0b0 for checkstop)
        rc = fapiPutScomUnderMask(i_proc_chip.this_chip,
                                  PB_RAS_FIR_ACTION0_0x02010C74,
                                  zero_data,
                                  action_mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_ras_fir: fapiPutScomUnderMask error (PB_RAS_FIR_ACTION0_0x02010C74)");
            break;
        }

        rc = fapiPutScomUnderMask(i_proc_chip.this_chip,
                                  PB_RAS_FIR_ACTION1_0x02010C75,
                                  zero_data,
                                  action_mask);
        if (!rc.ok())
        {
            FAPI_ERR("proc_fab_iovalid_manage_ras_fir: fapiPutScomUnderMask error (PB_RAS_FIR_ACTION1_0x02010C75)");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_fab_iovalid_manage_ras_fir: End");
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

    // partial good attributes
    uint8_t abus_enable_attr;
    uint8_t xbus_enable_attr;
    bool x_changed = false;
    bool a_changed = false;

    // mark HWP entry
    FAPI_IMP("proc_fab_iovalid: Entering ...");

    do
    {
        // loop over all chips in input vector
        for (iter = i_proc_chips.begin();
             iter != i_proc_chips.end();
             iter++)
        {
            // process X links
            if (iter->x0 ||
                iter->x1 ||
                iter->x2 ||
                iter->x3)
            {
                // query XBUS partial good attribute
                rc = FAPI_ATTR_GET(ATTR_PROC_X_ENABLE,
                                   &(iter->this_chip),
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

                rc = proc_fab_iovalid_manage_x_links(*iter, i_set_not_clear);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_fab_iovalid: Error from proc_fab_iovalid_manage_x_links");
                    break;
                }

                x_changed = true;
            }

            // process A links
            if (iter->a0 ||
                iter->a1 ||
                iter->a2)
            {
                // query ABUS partial good attribute
                rc = FAPI_ATTR_GET(ATTR_PROC_A_ENABLE,
                                   &(iter->this_chip),
                                   abus_enable_attr);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_fab_iovalid: Error querying ATTR_PROC_A_ENABLE");
                    break;
                }

                if (abus_enable_attr != fapi::ENUM_ATTR_PROC_A_ENABLE_ENABLE)
                {
                    FAPI_ERR("proc_fab_iovalid: Partial good attribute error");
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_FAB_IOVALID_A_PARTIAL_GOOD_ERR);
                    break;
                }

                rc = proc_fab_iovalid_manage_a_links(*iter, i_set_not_clear);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_fab_iovalid: Error from proc_fab_iovalid_manage_a_links");
                    break;
                }

                a_changed = true;
            }

            if (x_changed || a_changed)
            {
                rc = proc_fab_iovalid_manage_ras_fir(*iter, i_set_not_clear);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_fab_iovalid: Error from proc_fab_iovalid_manage_ras_fir");
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
