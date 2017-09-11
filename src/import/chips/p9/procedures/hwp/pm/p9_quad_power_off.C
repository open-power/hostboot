/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_quad_power_off.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
///
/// @file p9_quad_power_off.C
/// @brief Power off the EQ including the functional cores associatated with it.
///
//----------------------------------------------------------------------------
// *HWP HWP Owner       : Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 3
// *HWP Consumed by     : OCC:CME:FSP
//----------------------------------------------------------------------------
//
// @verbatim
// High-level procedure flow:
//     - For each good EC associated with the targeted EQ, power it off.
//     - Power off the EQ.
// @endverbatim
//
//------------------------------------------------------------------------------


// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_quad_power_off.H>
#include <p9_block_wakeup_intr.H>
#include <p9_quad_scom_addresses.H>
#include <p9_pm_pfet_control.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// Nimus DD1 ring offsets where a PBIEX buffer pointers are
// Used only if ATTR_CHIP_EC_FEATURE_RING_SAVE_MPIPL is set
static const uint64_t RING_INDEX[10] =
{
    0, 5039, 5100, 5664, 5725, 5973, 6034, 6282, 6343, 17871,
};

// Procedure p9_quad_power_off entry point, comments in header
fapi2::ReturnCode p9_quad_power_off(
    const fapi2::Target < fapi2::TARGET_TYPE_EQ>& i_target,
    uint64_t* o_ring_save_data)
{
    fapi2::buffer<uint64_t> l_data64;
    constexpr uint64_t l_rawData = 0x1100000000000000ULL; // Bit 3 & 7 are set to be manipulated
    constexpr uint32_t MAX_CORE_PER_QUAD = 4;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    uint32_t l_cnt = 0;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_chip =
        i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    uint8_t  l_isMpipl = 0;
    uint8_t  l_isRingSaveMpipl = 0;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_DBG("> p9_quad_power_off");

    // Print chiplet position
    FAPI_DBG("Quad power off chiplet no.%d", i_target.getChipletNumber());

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL, FAPI_SYSTEM, l_isMpipl),
             "fapiGetAttribute of ATTR_IS_MPIPL failed!");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_RING_SAVE_MPIPL,
                           l_chip,
                           l_isRingSaveMpipl),
             "fapiGetAttribute of ATTR_CHIP_EC_FEATURE_RING_SAVE_MPIPL failed");


    if (l_isMpipl && l_isRingSaveMpipl)
    {
        l_data64.setBit<EQ_SCAN_REGION_TYPE_PERV>();
        l_data64.setBit<EQ_SCAN_REGION_TYPE_UNIT1>();
        l_data64.setBit<EQ_SCAN_REGION_TYPE_UNIT7>();
        l_data64.setBit<EQ_SCAN_REGION_TYPE_INEX>();

        FAPI_TRY(fapi2::putScom(i_target,
                                EQ_SCAN_REGION_TYPE,
                                l_data64));

        l_data64.flush<0>().set(0xa5a5a5a5a5a5a5a5);

        FAPI_TRY(fapi2::putScom(i_target,
                                EQ_SCAN64,
                                l_data64));


        const uint32_t MAX_CLKCNTL_POLL_COUNT = 1000;

        for(uint32_t l_spin = 1; l_spin < 10; l_spin++)
        {
            uint64_t l_scandata = ((l_spin == 0) || (l_spin == 9)) ? 0x0 : (l_spin & 0x1) ?
                                  0xE000000000000000 : 0xC1E061FFED5F0000;
            l_data64.flush<0>().set((RING_INDEX[l_spin] - RING_INDEX[l_spin - 1]) << 32);

            FAPI_TRY(fapi2::putScom(i_target,
                                    EQ_SCAN_LONG_ROTATE,
                                    l_data64));
            l_data64.flush<0>();

            uint32_t l_pollcount = MAX_CLKCNTL_POLL_COUNT;

            do
            {
                FAPI_TRY(fapi2::getScom(i_target,
                                        EQ_CPLT_STAT0,
                                        l_data64));
                --l_pollcount;
            }
            while (l_data64.getBit<EQ_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC>() == 0 &&
                   l_pollcount != 0);

            FAPI_ASSERT(l_pollcount,
                        fapi2::P9_PM_QUAD_POWEROFF_CLKCNTL_TIMEOUT()
                        .set_EQ(i_target)
                        .set_EQ_CPLT_STAT0_CC_CTRL(l_data64),
                        "Clock Controller timeout with OPCG Done");

            l_data64.flush<0>();

            if (l_spin == 9)
            {
                FAPI_TRY(fapi2::getScom(i_target,
                                        EQ_SCAN64,
                                        l_data64));

                if(l_data64 != 0xa5a5a5a5a5a5a5a5)
                {
                    FAPI_ASSERT(false,
                                fapi2::P9_PM_QUAD_POWEROFF_INCORRECT_EQ_SCAN64_VAL()
                                .set_EQ(i_target)
                                .set_EQ_SCAN64_VAL(l_data64),
                                "Incorrect Value from EQ_SCAN64, Expected Value [0xa5a5a5a5a5a5a5a5]");
                }
            }
            else
            {
                l_data64.flush<0>();
                FAPI_TRY(fapi2::getScom(i_target,
                                        EQ_SCAN64,
                                        l_data64));
                o_ring_save_data[l_spin - 1] = l_scandata & l_data64;
            }
        }

        l_data64.flush<0>();
        FAPI_TRY(fapi2::putScom(i_target,
                                EQ_SCAN_REGION_TYPE,
                                l_data64));
    }


    FAPI_DBG("Disabling bits 20/22/24/26 in EQ_QPPM_QPMMR_CLEAR, to gain access"
             " to PFET controller, otherwise Quad Power off scom will fail");
    l_data64.setBit<EQ_QPPM_QPMMR_CME_INTERPPM_IVRM_ENABLE>();
    l_data64.setBit<EQ_QPPM_QPMMR_CME_INTERPPM_ACLK_ENABLE>();
    l_data64.setBit<EQ_QPPM_QPMMR_CME_INTERPPM_VDATA_ENABLE>();
    l_data64.setBit<EQ_QPPM_QPMMR_CME_INTERPPM_DPLL_ENABLE>();
    FAPI_TRY(fapi2::putScom(i_target, EQ_QPPM_QPMMR_CLEAR, l_data64));

    // QPPM_QUAD_CTRL_REG
    do
    {
        // EX0, Enables the EDRAM charge pumps in L3 EX0, on power down they
        // must be de-asserted in the opposite order 3 -> 0
        // EX1, Enables the EDRAM charge pumps in L3 EX1, on power down they
        // must be de-asserted in the opposite order 7 -> 4
        FAPI_DBG("De-asserting EDRAM charge pumps in Ex0 & Ex1 in Sequence for "
                 "Reg EQ_QPPM_QCCR_SCOM1, Data Value [0x%0X%0X]",
                 uint32_t((l_rawData << l_cnt) >> 32), uint32_t(l_rawData << l_cnt));
        FAPI_TRY(fapi2::putScom(i_target, EQ_QPPM_QCCR_SCOM1, (l_rawData << l_cnt)));
    }
    while(++l_cnt < MAX_CORE_PER_QUAD);

    // Call the procedure
    FAPI_EXEC_HWP(rc, p9_pm_pfet_control_eq, i_target,
                  PM_PFET_TYPE_C::BOTH, PM_PFET_TYPE_C::OFF);
    FAPI_TRY(rc);

    //Enable regular wakeup for each core after the quad has been powered off
    for (const auto& l_core : i_target.getChildren<fapi2::TARGET_TYPE_CORE>())
    {
        FAPI_EXEC_HWP(rc, p9_block_wakeup_intr, l_core, p9pmblockwkup::CLEAR);
    }

fapi_try_exit:
    FAPI_DBG("< p9_quad_power_off");
    return fapi2::current_err;
}
