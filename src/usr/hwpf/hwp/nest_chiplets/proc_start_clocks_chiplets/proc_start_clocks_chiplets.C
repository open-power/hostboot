/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/proc_start_clocks_chiplets/proc_start_clocks_chiplets.C $ */
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
// $Id: proc_start_clocks_chiplets.C,v 1.16 2013/05/16 21:08:54 mjjones Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_start_clocks_chiplets.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ****
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
// function: utility subroutine to get partial good vector from SEEPROM
// parameters: i_target                 => chip target
//             i_chiplet_base_addr      => base SCOM address for chiplet
//             o_chiplet_reg_vec        => output vector
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------

// note:
// expected value out of SEEPROM (in case of "all good", the "Partial Good Region"-Pattern are:
// XBUS = 0xF00, ABUS = 0xE100, PCIE = 0xF700

fapi::ReturnCode proc_start_clocks_get_partial_good_vector(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr,
    uint64_t * o_chiplet_reg_vec
    )
{
    fapi::ReturnCode rc;
    uint64_t partial_good_regions[32];

    FAPI_DBG("proc_start_clocks_get_partial_good_vector: Start");

    do
    {

        FAPI_DBG("proc_start_clocks_get_partial_good_vector: Get attribute ATTR_CHIP_REGIONS_TO_ENABLE (partial good region data) " );
        rc = FAPI_ATTR_GET( ATTR_CHIP_REGIONS_TO_ENABLE, &i_target, partial_good_regions);
        if (rc) {
            FAPI_ERR("fapi_attr_get( ATTR_CHIP_REGIONS_TO_ENABLE ) failed. With rc = 0x%x",
                     (uint32_t) rc );
            break;
        }


        FAPI_DBG("proc_start_clocks_get_partial_good_vector: start assignment of the partial good vector per chiplet");

        switch (i_chiplet_base_addr)
        {

          case X_BUS_CHIPLET_0x04000000:
              FAPI_DBG("proc_start_clocks_get_partial_good_vector: XBUS, attribute for XBUS (%016llX)", partial_good_regions[4]);
              *o_chiplet_reg_vec = partial_good_regions[4];
              break;


          case A_BUS_CHIPLET_0x08000000:
              FAPI_DBG("proc_start_clocks_get_partial_good_vector: ABUS, attribute for ABUS (%016llX)", partial_good_regions[8]);
              *o_chiplet_reg_vec = partial_good_regions[8];
              break;

          case PCIE_CHIPLET_0x09000000:
              FAPI_DBG("proc_start_clocks_get_partial_good_vector: PCIE, attribute for PCIE (%016llX)", partial_good_regions[9]);
              *o_chiplet_reg_vec = partial_good_regions[9];
              break;

          default:

               FAPI_ERR("proc_start_clocks_get_partial_good_vector: invalid chiplet base address selected when selecting par. good vector (0x%08X)",
                        i_chiplet_base_addr);
               uint32_t CHIPLET_BASE_SCOM_ADDR = i_chiplet_base_addr;
               FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_CHIPLETS_PARTIAL_GOOD_ERR);
               break;

        }


    } while(0);

    FAPI_DBG("proc_start_clocks_get_partial_good_vector: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to set clock region register (starts clocks)
// parameters: i_target              => chip target
//             i_chiplet_base_addr   => base SCOM address for chiplet
//             i_chiplet_reg_vec     => vector from SEEPROM with partial good
//                                      clock regions
//             o_chiplet_clkreg_vec  => output vector which contains
//                                      the masked vector -> used to set the
//					clock region register	
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_set_clk_region_reg(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr,
    const uint64_t i_chiplet_reg_vec,
    uint64_t * o_chiplet_clkreg_vec
    )


{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_CLK_REGION_0x00030006;
    uint64_t extracted_rec_vec;
    uint64_t clk_region_start_nsl_ary_masked;
    uint64_t clk_region_start_all_masked;

    FAPI_DBG("proc_start_clocks_chiplet_set_clk_region_reg: Start");

    do
    {


        // bitwise ORing of input vector
        extracted_rec_vec = PROC_START_CLOCKS_CHIPLETS_CLOCK_REGION_MANIPULATION | i_chiplet_reg_vec;

        // start NSL/array clocks

        clk_region_start_nsl_ary_masked = PROC_START_CLOCKS_CHIPLETS_CLK_REGION_REG_START_NSL_ARY & extracted_rec_vec;

        rc_ecmd |= data.setDoubleWord(0, clk_region_start_nsl_ary_masked);
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

        clk_region_start_all_masked = PROC_START_CLOCKS_CHIPLETS_CLK_REGION_REG_START_ALL & extracted_rec_vec;

        // output: value written into clk_region register, reused for status register checking

        *o_chiplet_clkreg_vec = clk_region_start_all_masked;

        rc_ecmd |= data.setDoubleWord(0, clk_region_start_all_masked);
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
// parameters: i_target             => chip target
//             i_chiplet_base_addr  => base SCOM address for chiplet
//             i_chiplet_clkreg_vec => region vector of SEEPROM for clock regions
//                                     need to be turned on
// returns: FAPI_RC_SUCCESS if operation was successful, else
//          RC_PROC_START_CLOCKS_CHIPLETS_CLK_STATUS_ERR if status register
//          data does not match expected pattern
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_chiplet_check_clk_status_reg(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr,
    const uint64_t i_chiplet_clkreg_vec)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;
    ecmdDataBufferBase vec_data(64);
    ecmdDataBufferBase status_data(64);
    ecmdDataBufferBase exp_data(64);
    uint32_t scom_addr = i_chiplet_base_addr |
                         GENERIC_CLK_STATUS_0x00030008;
    const uint32_t xbus = X_BUS_CHIPLET_0x04000000;
    const uint32_t abus = A_BUS_CHIPLET_0x08000000;
    const uint32_t pcie = PCIE_CHIPLET_0x09000000;

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

        // load it with reference data
        rc_ecmd |= vec_data.setDoubleWord(0, i_chiplet_clkreg_vec);
        // generate expected value databuffer
        rc_ecmd |= exp_data.flushTo1();

        if ( i_chiplet_base_addr == xbus)
        {

           if ( vec_data.isBitSet(4)) { rc_ecmd |= exp_data.clearBit(0,3); }
           if ( vec_data.isBitSet(5)) { rc_ecmd |= exp_data.clearBit(3,6); }
           if ( vec_data.isBitSet(6)) { rc_ecmd |= exp_data.clearBit(9,6); }
           if ( vec_data.isBitSet(7)) { rc_ecmd |= exp_data.clearBit(15,3);}

        }

        else
        {

           if ( vec_data.isBitSet(4))  { rc_ecmd |= exp_data.clearBit(0,3); }
           if ( vec_data.isBitSet(5))  { rc_ecmd |= exp_data.clearBit(3,3); }
           if ( vec_data.isBitSet(6))  { rc_ecmd |= exp_data.clearBit(6,3); }
           if ( vec_data.isBitSet(7))  { rc_ecmd |= exp_data.clearBit(9,3); }
           if ( vec_data.isBitSet(9))  { rc_ecmd |= exp_data.clearBit(15,3);}
           if ( vec_data.isBitSet(10)) { rc_ecmd |= exp_data.clearBit(18,3);}
           if ( vec_data.isBitSet(11)) { rc_ecmd |= exp_data.clearBit(21,3);}

        }


        if (rc_ecmd)
        {
            FAPI_ERR("proc_start_clocks_chiplet_check_clk_status_reg: Error 0x%x setting up data buffer to set clock status",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }


        // check that value matches expected pattern
        // set a unique HWP_ERROR
        if (status_data.getDoubleWord(0) != exp_data.getDoubleWord(0))
        {
            FAPI_ERR("proc_start_clocks_chiplet_check_clk_status_reg: Clock status register actual value (%016llX) does not match expected value (%016llX)",
                     status_data.getDoubleWord(0), exp_data.getDoubleWord(0));
            ecmdDataBufferBase & STATUS_REG = status_data;
            ecmdDataBufferBase & EXPECTED_REG = exp_data;

            if ( i_chiplet_base_addr == xbus)
            {
               FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_XBUS_CHIPLET_CLK_STATUS_ERR);
               break;
            }
            if ( i_chiplet_base_addr == abus)
            {
               FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_ABUS_CHIPLET_CLK_STATUS_ERR);
               break;
            }
            if ( i_chiplet_base_addr == pcie)
            {
               const fapi::Target & CHIP_IN_ERROR  = i_target;
               FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_PCIE_CHIPLET_CLK_STATUS_ERR);
               break;
            }

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
    const uint32_t xbus = X_BUS_CHIPLET_0x04000000;
    const uint32_t abus = A_BUS_CHIPLET_0x08000000;
    const uint32_t pcie = PCIE_CHIPLET_0x09000000;


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
            const uint64_t & FIR_EXP_REG = PROC_START_CLOCKS_CHIPLETS_CHIPLET_FIR_REG_EXP;


            if ( i_chiplet_base_addr == xbus)
            {
               FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_XBUS_CHIPLET_FIR_ERR);
               break;
            }
            if ( i_chiplet_base_addr == abus)
            {
               FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_ABUS_CHIPLET_FIR_ERR);
               break;
            }
            if ( i_chiplet_base_addr == pcie)
            {

               const fapi::Target & CHIP_IN_ERROR  = i_target;
               FAPI_SET_HWP_ERROR(rc, RC_PROC_START_CLOCKS_PCIE_CHIPLET_FIR_ERR);
               break;
            }

        }

    } while(0);

    FAPI_DBG("proc_start_clocks_chiplet_check_fir: End");

    return rc;
}


//------------------------------------------------------------------------------
// function: utility subroutine to run clock start sequence on a generic chiplet
// parameters: i_target            => chip target
//             i_chiplet_base_addr => base SCOM address for chiplet
// returns: FAPI_RC_SUCCESS if operation was successful, else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_start_clocks_generic_chiplet(
    const fapi::Target& i_target,
    const uint32_t i_chiplet_base_addr)

{
    fapi::ReturnCode rc;
    uint64_t chiplet_reg_vec;
    uint64_t chiplet_clkreg_vec;

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

        // pick partial good region vector from SEEPROM
        FAPI_DBG("Get partial good region vector ...");
        rc = proc_start_clocks_get_partial_good_vector(i_target,
                                                       i_chiplet_base_addr,
                                                       & chiplet_reg_vec
                                                       );
        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error getting partial good region vector");
            break;
        }


        // write clock region register to start clocks
        FAPI_DBG("Writing clock region register to start clocks ...");
        rc = proc_start_clocks_chiplet_set_clk_region_reg(i_target,
                                                          i_chiplet_base_addr,
                                                          chiplet_reg_vec,
                                                          & chiplet_clkreg_vec
                                                          );


        if (rc)
        {
            FAPI_ERR("proc_start_clocks_generic_chiplet: Error writing clock region register");
            break;
        }

        // check clock status register to ensure that all clocks are started
        FAPI_DBG("Checking clock status register ...");
        rc = proc_start_clocks_chiplet_check_clk_status_reg(i_target,
                                                            i_chiplet_base_addr,
                                                            chiplet_clkreg_vec);
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
    uint8_t xbus_enable_attr;
    uint8_t abus_enable_attr;
    uint8_t pcie_enable_attr;

    // mark HWP entry
    FAPI_IMP("proc_start_clocks_chiplets: Entering ...");

    do
    {
        if (xbus)
        {
            // query XBUS partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_X_ENABLE,
                               &i_target,
                               xbus_enable_attr);
            if (!rc.ok())
            {
                FAPI_ERR("proc_start_clocks_chiplets: Error querying ATTR_PROC_X_ENABLE");
                break;
            }

            if (xbus_enable_attr == fapi::ENUM_ATTR_PROC_X_ENABLE_ENABLE)
            {
                FAPI_DBG("Starting X bus chiplet clocks ...");
                rc = proc_start_clocks_generic_chiplet(
                    i_target,
                    X_BUS_CHIPLET_0x04000000);
                if (rc)
                {
                    FAPI_ERR("proc_start_clocks_chiplets: Error from proc_start_clocks_generic_chiplet (X)");
                    break;
                }
            }
            else
            {
                FAPI_DBG("Skipping XBUS chiplet clock start (partial good).");
            }
        }

        if (abus)
        {
            // query ABUS partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_A_ENABLE,
                               &i_target,
                               abus_enable_attr);
            if (!rc.ok())
            {
                FAPI_ERR("proc_start_clocks_chiplets: Error querying ATTR_PROC_A_ENABLE");
                break;
            }

            if (abus_enable_attr == fapi::ENUM_ATTR_PROC_A_ENABLE_ENABLE)
            {
                FAPI_DBG("Starting A bus chiplet clocks ...");
                rc = proc_start_clocks_generic_chiplet(
                    i_target,
                    A_BUS_CHIPLET_0x08000000);
                if (rc)
                {
                    FAPI_ERR("proc_start_clocks_chiplets: Error from proc_start_clocks_generic_chiplet (A)");
                    break;
                }
            }
            else
            {
                FAPI_DBG("Skipping ABUS chiplet clock start (partial good).");
            }
        }

        if (pcie)
        {
            // query PCIE partial good attribute
            rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_ENABLE,
                               &i_target,
                               pcie_enable_attr);
            if (!rc.ok())
            {
                FAPI_ERR("proc_start_clocks_chiplets: Error querying ATTR_PROC_PCIE_ENABLE");
                break;
            }

            if (pcie_enable_attr == fapi::ENUM_ATTR_PROC_PCIE_ENABLE_ENABLE)
            {
                FAPI_DBG("Starting PCIE chiplet clocks ...");
                rc = proc_start_clocks_generic_chiplet(
                    i_target,
                    PCIE_CHIPLET_0x09000000);
                if (rc)
                {
                    FAPI_ERR("proc_start_clocks_chiplets: Error from proc_start_clocks_generic_chiplet (PCIE)");
                    break;
                }
            }
            else
            {
                FAPI_DBG("Skipping PCIE chiplet clock start (partial good).");
            }
        }

    } while (0);

    // mark HWP exit
    FAPI_IMP("proc_start_clocks_chiplets: Exiting ...");
    return rc;
}


} // extern "C"
