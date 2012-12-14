/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/nest_chiplets/proc_start_clocks_chiplets/proc_start_clocks_chiplets.C $
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
// $Id: proc_start_clocks_chiplets.C,v 1.5 2012/08/08 12:05:11 rkoester Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_start_clocks_chiplets.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ****
// *|
// *! TITLE       : proc_start_clocks_chiplets.H
// *! DESCRIPTION : Start X/A/PCIE chiplet clocks (FAPI)
// *!
// *! OWNER NAME  : Ralph Koester           Email: rkoester@de.ibm.com
// *! BACKUP NAME : Gebhard Weber           Email: gweber@de.ibm.com
// *!
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_start_clocks_chiplets.H"

extern "C"
{


//------------------------------------------------------------------------------
// function: utility subroutine to clear chiplet fence in GP3 register
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_clear_chiplet_fence(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase mask_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_GP3_AND_0x000F0013;

    FAPI_DBG("proc_start_clocks_chiplet_clear_chiplet_fence: Start");

    do
    {
        // form AND mask to clear chiplet fence bit
        rc_ecmd |= mask_data.flushTo1();
        rc_ecmd |= mask_data.clearBit(GP3_FENCE_EN_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_chiplet_fence: Error 0x%x setting up data buffer to clear chiplet fence",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write chiplet GP3 AND mask register to clear fence bit
        rc = fapiPutScom(i_target, scom_addr, mask_data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_chiplet_fence: fapiPutScom error (GP3_AND_0x%08X)",
                     scom_addr);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_clear_chiplet_fence: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to clear pervasive fence in GP0 register
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_clear_perv_fence(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase mask_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_GP0_AND_0x00000004;

    FAPI_DBG("proc_start_clocks_chiplet_clear_perv_fence: Start");

    do
    {
        // form AND mask to clear pervasive fence bit
        rc_ecmd |= mask_data.flushTo1();
        rc_ecmd |= mask_data.clearBit(GP0_PERV_FENCE_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_perv_fence: Error 0x%x setting up data buffer to clear pervasive fence",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write chiplet GP0 AND mask register to clear pervasive fence bit
        rc = fapiPutScom(i_target, scom_addr, mask_data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_perv_fence: fapiPutScom error (GP0_AND_0x%08X)",
                     scom_addr);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_clear_perv_fence: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set functional mode clock mux selects
//           in GP0 register
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_set_mux_selects(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase mask_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_GP0_AND_0x00000004;

    FAPI_DBG("proc_start_clocks_chiplet_set_mux_selects: Start");

    do
    {
        // form AND mask to clear mux selects
        rc_ecmd |= mask_data.flushTo1();
        rc_ecmd |= mask_data.clearBit(GP0_ABSTCLK_MUXSEL_BIT);
        rc_ecmd |= mask_data.clearBit(GP0_SYNCCLK_MUXSEL_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_start_clocks_chiplet_set_mux_selects: Error 0x%x setting up data buffer to clear chiplet mux selects",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write chiplet GP0 AND mask register to clear mux selects
        rc = fapiPutScom(i_target, scom_addr, mask_data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_set_mux_selects: fapiPutScom error (GP0_AND_0x%08X)",
                     scom_addr);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_set_mux_selects: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to clear scan select register
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_clear_clk_scansel_reg(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase zero_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_CLK_SCANSEL_0x00030007;

    FAPI_DBG("proc_start_clocks_chiplet_clear_clk_scansel_reg: Start");

    do
    {
        // clear chiplet scan select register
        rc = fapiPutScom(i_target, scom_addr, zero_data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_clk_scansel_reg: fapiPutScom error (CLK_SCANSEL_0x%08X)",
                     scom_addr);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_clear_clk_scansel_reg: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set clock region register (starts clocks)
// parameters: i_target                 => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_set_clk_region_reg(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_CLK_REGION_0x00030006;

    FAPI_DBG("proc_start_clocks_chiplet_set_clk_region_reg: Start");

    do
    {
        // start NSL/array clocks
        rc_ecmd |= data.setDoubleWord(0, PROC_START_CLOCKS_CHIPLETS_CLK_REGION_REG_START_NSL_ARY);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_start_clocks_chiplet_set_clk_region_reg: Error 0x%x setting up data buffer for NSL/ARY clock start",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        rc = fapiPutScom(i_target, scom_addr, data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_set_clk_region_reg: fapiPutScom error (CLK_REGION_0x%08X)",
                     scom_addr);
            break;
        }

        // start all clocks
        rc_ecmd |= data.setDoubleWord(0, PROC_START_CLOCKS_CHIPLETS_CLK_REGION_REG_START_ALL);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_start_clocks_chiplet_set_clk_region_reg: Error 0x%x setting up data buffer for SL/NSL/ARY clock start",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        rc = fapiPutScom(i_target, scom_addr, data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_set_clk_region_reg: fapiPutScom error (CLK_REGION_0x%08X)",
                     scom_addr);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_set_clk_region_reg: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to check clock status register to ensure
//           all desired clock domains have been started
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
//             i_status_reg_exp    => expected value for clock status register
//                                    after clock start
// returns: FAPI_RC_SUCCESS if operation was successful, else
//          RC_PROC_START_CLOCKS_CHIPLETS_CLK_STATUS_ERR if status register
//          data does not match expected pattern
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_check_clk_status_reg(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr,
    const uint64_t i_status_reg_exp)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase status_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_CLK_STATUS_0x00030008;

    FAPI_DBG("proc_start_clocks_chiplet_check_clk_status_reg: Start");

    do
    {
        // read clock status register
        rc = fapiGetScom(i_target, scom_addr, status_data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_check_clk_status_reg: fapiGetScom error (CLK_STATUS_0x%08X)",
                     scom_addr);
            break;
        }

        // check that value matches expected pattern
        // set a unique HWP_ERROR
        if (status_data.getDoubleWord(0) != i_status_reg_exp)
        {
            FAPI_ERR("proc_start_clocks_chiplet_check_clk_status_reg: Clock status register actual value (%016llX) does not match expected value (%016llX)",
                     status_data.getDoubleWord(0), i_status_reg_exp);
            ecmdDataBufferBase & STATUS_REG = status_data;
            uint32_t CHIPLET_BASE_SCOM_ADDR = i_chiplet_base_addr;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_CHIPLETS_CLK_STATUS_ERR);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_check_clk_status_reg: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to clear force align in GP0 register
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_clear_force_align(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase mask_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_GP0_AND_0x00000004;

    FAPI_DBG("proc_start_clocks_chiplet_clear_force_align: Start");

    do
    {
        // form AND mask to clear force align bit
        rc_ecmd |= mask_data.flushTo1();
        rc_ecmd |= mask_data.clearBit(GP0_FORCE_ALIGN_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_force_align: Error 0x%x setting up data buffer to clear force align",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write chiplet GP0 AND mask register to clear force align bit
        rc = fapiPutScom(i_target, scom_addr, mask_data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_force_align: fapiPutScom error (GP0_AND_0x%08X)",
                     scom_addr);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_clear_force_align: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to clear flushmode inhibit in GP0 register
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_clear_flushmode_inhibit(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase mask_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_GP0_AND_0x00000004;

    FAPI_DBG("proc_start_clocks_chiplet_clear_flushmode_inhibit: Start");

    do
    {
        // form AND mask to clear force align bit
        rc_ecmd |= mask_data.flushTo1();
        rc_ecmd |= mask_data.clearBit(GP0_FLUSHMODE_INHIBIT_BIT);
        if (rc_ecmd)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_flushmode_inhibit: Error 0x%x setting up data buffer to clear flushmode inhibit",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write chiplet GP0 AND mask register to clear force align bit
        rc = fapiPutScom(i_target, scom_addr, mask_data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_clear_flushmode_inhibit: fapiPutScom error (GP0_AND_0x%08X)",
                     scom_addr);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_clear_flushmode_inhibit: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to check chiplet FIR register for errors
//           after clocks have been started
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else
//          RC_PROC_START_CLOCKS_CHIPLETS_FIR_ERR if FIR register data doesn't
//          match expected pattern
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_check_fir(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase fir_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_XSTOP_0x00040000;

    FAPI_DBG("proc_start_clocks_chiplet_check_fir: Start");

    do
    {
        // read chiplet FIR register
        rc = fapiGetScom(i_target, scom_addr, fir_data);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_chiplet_check_fir: fapiGetScom error (XSTOP_0x%08X)",
                     scom_addr);
            break;
        }

        // check that value matches expected pattern
        // set a unique HWP_ERROR
        if (fir_data.getDoubleWord(0) !=
            PROC_START_CLOCKS_CHIPLETS_CHIPLET_FIR_REG_EXP)
        {
            FAPI_ERR("proc_start_clocks_chiplet_check_fir: FIR register actual value (%016llX) does not match expected value (%016llX)",
                     fir_data.getDoubleWord(0), PROC_START_CLOCKS_CHIPLETS_CHIPLET_FIR_REG_EXP);
            ecmdDataBufferBase & FIR_REG = fir_data;
            uint32_t CHIPLET_BASE_SCOM_ADDR = i_chiplet_base_addr;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_CHIPLETS_FIR_ERR);
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_check_fir: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to run clock start sequence on a generic chiplet
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
//             i_status_reg_exp    => expected value for clock status register
//                                    after clock start
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_generic_chiplet(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr,
    const uint64_t i_status_reg_exp)
{
    fapi::ReturnCode rc;

    FAPI_DBG("proc_start_clocks_generic_chiplet: Start");

    do
    {
        // clear chiplet fence in GP3 register
        FAPI_DBG("Writing GP3 AND mask to clear chiplet fence ...");
        rc = proc_start_clocks_chiplet_clear_chiplet_fence(i_target,
                                                           i_chiplet_base_addr);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error writing GP3 AND mask to clear chiplet fence");
            break;
        }

        // clear pervasive fence in GP0 register
        FAPI_DBG("Writing GP0 AND mask to clear pervasive fence ...");
        rc = proc_start_clocks_chiplet_clear_perv_fence(i_target,
                                                        i_chiplet_base_addr);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error writing GP0 AND mask to clear pervasive fence");
            break;
        }

        // set functional clock mux selects in GP0 register
        FAPI_DBG("Writing GP0 AND mask to set functional clock mux selects ...");
        rc = proc_start_clocks_chiplet_set_mux_selects(i_target,
                                                       i_chiplet_base_addr);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error writing GP0 AND mask to set functional clock mux selects");
            break;
        }

        // clear clock scansel register
        FAPI_DBG("Clearing clock scansel register ...");
        rc = proc_start_clocks_chiplet_clear_clk_scansel_reg(i_target,
                                                             i_chiplet_base_addr);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error clearing clock scansel register");
            break;
        }

        // write clock region register to start clocks
        FAPI_DBG("Writing clock region register to start clocks ...");
        rc = proc_start_clocks_chiplet_set_clk_region_reg(i_target,
                                                          i_chiplet_base_addr);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error writing clock region register");
            break;
        }

        // check clock status register to ensure that all clocks are started
        FAPI_DBG("Chcecking clock status register ...");
        rc = proc_start_clocks_chiplet_check_clk_status_reg(i_target,
                                                            i_chiplet_base_addr,
                                                            i_status_reg_exp);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error checking clock status register");
            break;
        }

        // clear force align bit in GP0 register
        FAPI_DBG("Writing GP0 AND mask to clear force align ...");
        rc = proc_start_clocks_chiplet_clear_force_align(i_target,
                                                         i_chiplet_base_addr);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error writing GP0 AND mask to clear force align");
            break;
        }

        // clear flushmode inhibit bit in GP0 register
        FAPI_DBG("Writing GP0 AND mask to clear flushmode inhibit ...");
        rc = proc_start_clocks_chiplet_clear_flushmode_inhibit(i_target,
                                                               i_chiplet_base_addr);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error writing GP0 AND mask to clear flushmode inhibit");
            break;
        }

        // check chiplet FIR register
        FAPI_DBG("Checking chiplet FIR register for errors after clock start ...");
        rc = proc_start_clocks_chiplet_check_fir(i_target,
                                                 i_chiplet_base_addr);
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error checking chiplet FIR register after clock start");
            break;
        }

    } while(0);

    FAPI_DBG("proc_start_clocks_generic_chiplet: End");

    return rc;
}


//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplets(const fapi::Target& i_target,
                                            bool xbus, bool abus, bool pcie)
{
    fapi::ReturnCode rc;

    // mark HWP entry
    FAPI_IMP("proc_start_clocks_chiplets: Entering ...");

    do
    {
        if (xbus)
        {
            FAPI_DBG("Starting X bus chiplet clocks ...");
            rc = proc_start_clocks_generic_chiplet(
                i_target,
                X_BUS_CHIPLET_0x04000000,
                PROC_START_CLOCKS_CHIPLETS_XBUS_CLK_STATUS_REG_EXP);
            if (rc)
            {
                break;
            }
        }

        if (abus)
        {
            FAPI_DBG("Starting A bus chiplet clocks ...");
            rc = proc_start_clocks_generic_chiplet(
                i_target,
                // TODO MJJ Updated to A_BUS_CHIPLET_0x08000000 to match new
                // p8_scom_addresses, this will go away when this HWP is
                // refreshed
                A_BUS_CHIPLET_0x08000000,
                PROC_START_CLOCKS_CHIPLETS_ABUS_CLK_STATUS_REG_EXP);
            if (rc)
            {
                break;
            }
        }

        if (pcie)
        {
            FAPI_DBG("Starting PCIE chiplet clocks ...");
            rc = proc_start_clocks_generic_chiplet(
                i_target,
                // TODO MJJ Updated to PCIE_CHIPLET_0x09000000 to match new
                // p8_scom_addresses, this will go away when this HWP is
                // refreshed
                PCIE_CHIPLET_0x09000000,
                PROC_START_CLOCKS_CHIPLETS_PCIE_CLK_STATUS_REG_EXP);
            if (rc)
            {
                break;
            }
        }

    } while (0);

    // mark HWP exit
    FAPI_IMP("proc_start_clocks_chiplets: Exiting ...");
    return rc;
}


} // extern "C"
