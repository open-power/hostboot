/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_tod_utils.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
//--------------------------------------------------------------------------
//
//
/// @file p9_tod_utils.C
/// @brief Utilities and classes for the tod_init and tod_setup procedures
///
// *HWP HWP Owner Christina Graves clgraves@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: SBE
//
//--------------------------------------------------------------------------


//--------------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------------
#include <p9_tod_utils.H>

extern "C" {

//--------------------------------------------------------------------------
//  HWP entry point
//--------------------------------------------------------------------------
    fapi2::ReturnCode p9_tod_utils_get_tfmr_reg(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const uint8_t i_thread_num,
        fapi2::buffer<uint64_t>& o_tfmr_val)
    {
        // mark HWP entry
        FAPI_DBG("Entering ...\n");

        fapi2::buffer<uint64_t> data;
        fapi2::buffer<uint64_t> data2;

        //FAPI_DBG("proc_tod_utils_get_tfmr_reg: Setting SPR_MODE to thread number");
        data.flush<0>().setBit<SPR_MODE_REG_MODE_SPRC_WR_EN>().setBit<SPR_MODE_REG_MODE_SPRC0_SEL>();
        data2.flush<0>();

        switch(i_thread_num)
        {
            case(0):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T0_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T0, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(1):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T1_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T1, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(2):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T2_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T2, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(3):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T3_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T3, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(4):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T4_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T4, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(5):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T5_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T5, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(6):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T6_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T6, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(7):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T7_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T7, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            default:
                FAPI_ASSERT(true, fapi2::P9_INVALID_THREAD_NUM().set_TARGET(i_target).set_THREADNUMBER(i_thread_num),
                            "Thread number error ");
        }

        FAPI_TRY(fapi2::putScom(i_target, C_SPR_MODE, data), "Error writing to EX_PERV_SPR_MODE");

        FAPI_TRY(fapi2::putScom(i_target, C_SCOMC, data2), "Error writing to EX_PERV_L0_SCOM_SPRC");

        //FAPI_DBG("proc_tod_utils_get_tfmr_reg: Reading SPRD for T0's TMFR");
        //FAPI_TRY(fapi2::getScom(i_target, 0x2E010A81, o_tfmr_val), "Error getting EX_PERV_SPRD_L0");
        FAPI_TRY(fapi2::getScom(i_target, 0x20010A81, o_tfmr_val), "Error getting EX_PERV_SPRD_L0");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

    fapi2::ReturnCode p9_tod_utils_set_tfmr_reg(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const uint8_t i_thread_num,
        fapi2::buffer<uint64_t>& i_tfmr_val)
    {
        // mark HWP entry
        FAPI_DBG("Entering ...\n");

        fapi2::buffer<uint64_t> data;
        fapi2::buffer<uint64_t> data2;

        //FAPI_DBG("proc_tod_utils_set_tfmr_reg: Setting SPR_MODE to thread number");
        //FAPI_DBG("proc_tod_utils_set_tfmr_reg: Setting SPRC to thread's TMFR");
        data.flush<0>().setBit<SPR_MODE_REG_MODE_SPRC_WR_EN>().setBit<SPR_MODE_REG_MODE_SPRC0_SEL>();
        data2.flush<0>();

        switch(i_thread_num)
        {
            case(0):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T0_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T0, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(1):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T1_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T1, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(2):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T2_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T2, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(3):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T3_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T3, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(4):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T4_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T4, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(5):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T5_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T5, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(6):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T6_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T6, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            case(7):
                data.setBit<SPR_MODE_REG_MODE_SPRC_T7_SEL>();
                data2.insertFromRight(SPRC_REG_SEL_TFMR_T7, SPRC_REG_SEL, SPRC_REG_SEL_LEN);
                break;

            default:
                FAPI_ASSERT(true, fapi2::P9_INVALID_THREAD_NUM().set_TARGET(i_target).set_THREADNUMBER(i_thread_num),
                            "Thread number error ");
                break;
        }

        FAPI_TRY(fapi2::putScom(i_target, C_SPR_MODE, data), "Error doing putscom to EX_PERV_SPR_MODE");

        FAPI_TRY(fapi2::putScom(i_target, C_SCOMC, data2), "Error doing putscom to EX_PERV_L0_SCOM_SPRC");

        //FAPI_DBG("proc_tod_utils_set_tfmr_reg: Writing SPRD to set T0's TMFR");
        //FAPI_TRY(fapi2::putScom(i_target, 0x2E010A81, i_tfmr_val), "Error doing putscom to EX_PERV_SPRD_L0");
        FAPI_TRY(fapi2::putScom(i_target, 0x20010A81, i_tfmr_val), "Error doing putscom to EX_PERV_SPRD_L0");

    fapi_try_exit:
        FAPI_DBG("Exiting...");
        return fapi2::current_err;
    }

} // extern "C"

