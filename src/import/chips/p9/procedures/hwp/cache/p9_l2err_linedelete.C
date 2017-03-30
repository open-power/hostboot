/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/cache/p9_l2err_linedelete.C $ */
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
//------------------------------------------------------------------------------
// *|
// *! TITLE       : p9_l2err_linedelete.C
// *! DESCRIPTION : Delete the L2 error cache line according to the error extraction information.
// *!
// *! OWNER NAME  : Chen Qian              Email: qianqc@cn.ibm.com
// *!
// *! ADDITIONAL COMMENTS :
// *!  See header file for additional comments.
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_l2err_linedelete.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>
//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint32_t BUSY_POLL_DELAY_IN_NS = 10000000; // 10ms
const uint32_t BUSY_POLL_DELAY_IN_CYCLES = 20000000; // 10ms, assumming 2GHz

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
    fapi2::ReturnCode p9_l2err_linedelete(const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
                                          const p9_l2err_extract_err_data& i_err_data,
                                          const uint64_t p9_l2err_linedelete_TryBusyCounts)
    {



        uint8_t                 member = 0;
        uint8_t                 bank = 0;
        uint16_t                cgc = 0;
        uint64_t                busy_reg_counter = 0;
        fapi2::buffer<uint64_t> l_l2_l2cerrs_prd_purge_cmd_reg;

        bool                    reg_busy = 0;
        bool                    prd_purge_busy = 1;

        // mark function entry
        FAPI_DBG("Entering p9_l2err_linedelete...");

        //   +---------------------------+
        //   |    L2 Line Delete Scom    |
        //   +---------------------------+
        //   |Bit(s)|  Data              |
        //   +------+--------------------+
        //   |    0 | Trigger            |
        //   +------+--------------------+
        //   |  1:4 | Purge type (LD=0x2)|
        //   +------+--------------------+
        //   | 5:16 | Don't care         |
        //   +------+--------------------+
        //   |17:19 | Member             |
        //   +------+--------------------+
        //   |20:27 | CGC  addr 48:55    |
        //   +------+--------------------+
        //   |   28 | Bank               |
        //   +------+--------------------+
        //   |29:30 | Don't care         |
        //   +------+--------------------+


        member = i_err_data.member;
        bank = i_err_data.bank;
        cgc = i_err_data.address;

        // Write member, cgc address and bank into PRD Purge Engine Command Register
        // SCOM Addr: 0x000000001001080E
        // bit 0 is the trigger, the act of writing this bit to 1 sets off the line delete
        // bits 1:4 is ttype 0b0010 = line delete
        // bits 17:19 is the member
        // bits 20:27 is the cgc address
        // bit 28 is the bank


        FAPI_DBG("p9_l2err_linedelete_TryBusyCounts: %ld", p9_l2err_linedelete_TryBusyCounts);

        // wait reg_busy bit for a max counter time which is defined by user
        do
        {
            FAPI_TRY(fapi2::getScom(i_target, EX_PRD_PURGE_CMD_REG, l_l2_l2cerrs_prd_purge_cmd_reg),
                     "Error from getScom (l_l2_l2cerrs_prd_purge_cmd_reg)");
            FAPI_DBG("l_l2_l2cerrs_prd_purge_cmd_reg_data: %#lx", l_l2_l2cerrs_prd_purge_cmd_reg);

            // get the reg_busy bit from scom register
            l_l2_l2cerrs_prd_purge_cmd_reg.extractToRight<EX_PRD_PURGE_CMD_REG_BUSY, 1>(reg_busy);

            if (reg_busy == 0)
            {
                prd_purge_busy = 0;
                break;
            }
            else
            {
                busy_reg_counter = busy_reg_counter + 1;
                FAPI_DBG("reg_busy = %u, wait for 10ms and try again, remaining cout: %u!",
                         reg_busy, busy_reg_counter);
                // Delay for 10ms
                fapi2::delay(BUSY_POLL_DELAY_IN_NS, BUSY_POLL_DELAY_IN_CYCLES);
            }
        }
        while (busy_reg_counter < p9_l2err_linedelete_TryBusyCounts);


        // if the reg_busy is still 1 during the counter time
        // error occurs
        FAPI_ASSERT(!prd_purge_busy,
                    fapi2::P9_L2ERR_LINE_DELETE_REG_BUSY().
                    set_TARGET(i_target),
                    "Error: PRD_PURGE_CMD_REG_BUSY indicats the ie completion bit was not set yet.");

        FAPI_DBG("reg_busy = %u", reg_busy);


        // if reg_busy is 0
        // write trigger, type, cgc address and bank into PRD Purge Engine Command Register
        if (reg_busy == 0)
        {

            l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight<EX_PRD_PURGE_CMD_REG_MEM, EX_PRD_PURGE_CMD_REG_MEM_LEN>(member);
            l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight<EX_PRD_PURGE_CMD_REG_CGC, EX_PRD_PURGE_CMD_REG_CGC_LEN>(cgc);
            l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight<EX_PRD_PURGE_CMD_REG_BANK, 1>(bank);

            l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight<EX_PRD_PURGE_CMD_REG_TRIGGER, 1>(1);
            l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight<EX_PRD_PURGE_CMD_REG_TYPE, EX_PRD_PURGE_CMD_REG_TYPE_LEN>(0x2);

            FAPI_DBG("l_l2_l2cerrs_prd_purge_cmd_reg_data: %#lx", l_l2_l2cerrs_prd_purge_cmd_reg);
            FAPI_TRY(fapi2::putScom(i_target, EX_PRD_PURGE_CMD_REG, l_l2_l2cerrs_prd_purge_cmd_reg),
                     "Error from putScom (l_l2_l2cerrs_prd_purge_cmd_reg)");

            // poll the busy bit again to ensure the purge completed
            do
            {
                FAPI_TRY(fapi2::getScom(i_target, EX_PRD_PURGE_CMD_REG, l_l2_l2cerrs_prd_purge_cmd_reg),
                         "Error from getScom (l_l2_l2cerrs_prd_purge_cmd_reg)");
                FAPI_DBG("l_l2_l2cerrs_prd_purge_cmd_reg_data: %#lx", l_l2_l2cerrs_prd_purge_cmd_reg);

                // get the reg_busy bit from scom register
                l_l2_l2cerrs_prd_purge_cmd_reg.extractToRight<EX_PRD_PURGE_CMD_REG_BUSY, 1>(reg_busy);

                if (reg_busy == 0)
                {
                    prd_purge_busy = 0;
                    break;
                }
                else
                {
                    busy_reg_counter = busy_reg_counter + 1;
                    FAPI_DBG("reg_busy = %u, wait for 10ms and try again, remaining cout: %u!",
                             reg_busy, busy_reg_counter);
                    // Delay for 10ms
                    fapi2::delay(BUSY_POLL_DELAY_IN_NS, BUSY_POLL_DELAY_IN_CYCLES);
                }
            }
            while (busy_reg_counter < p9_l2err_linedelete_TryBusyCounts);

            // if the reg_busy is still 1 during the counter time
            // error occurs
            FAPI_ASSERT(!prd_purge_busy,
                        fapi2::P9_L2ERR_LINE_DELETE_REG_BUSY().
                        set_TARGET(i_target),
                        "Error: PRD_PURGE_CMD_REG_BUSY indicats the ie completion bit was not set yet, the PRD Purge Engine Command Register written failed.");

            FAPI_DBG("Writing PRD Purge Engine Command Register busy bit status, reg_busy = %u", reg_busy);
            //poll the busy bit completed


        }

        // mark HWP exit
    fapi_try_exit:
        FAPI_INF("Exiting p9_l2err_linedelete...");
        return fapi2::current_err;
    } // p9_l2err_extract

} // extern "C
