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

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// HWP entry point
//------------------------------------------------------------------------------
    fapi2::ReturnCode p9_l2err_linedelete(const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_target,
                                          const p9_l2err_extract_err_data& i_err_data)
    {


        uint8_t                 member = 0;
        uint8_t                 bank = 0;
        uint16_t                cgc = 0;
        fapi2::buffer<uint64_t> l_l2_l2cerrs_prd_purge_cmd_reg;

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
        FAPI_TRY(fapi2::getScom(i_target, EX_PRD_PURGE_CMD_REG, l_l2_l2cerrs_prd_purge_cmd_reg),
                 "Error from getScom (l_l2_l2cerrs_prd_purge_cmd_reg)");
        FAPI_DBG("l_l2_l2cerrs_prd_purge_cmd_reg_data: %#lx", l_l2_l2cerrs_prd_purge_cmd_reg);

        l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight<EX_PRD_PURGE_CMD_REG_MEM, EX_PRD_PURGE_CMD_REG_MEM_LEN>(member);
        l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight<EX_PRD_PURGE_CMD_REG_CGC, EX_PRD_PURGE_CMD_REG_CGC_LEN>(cgc);
        l_l2_l2cerrs_prd_purge_cmd_reg.insertFromRight<EX_PRD_PURGE_CMD_REG_BANK, 1>(bank);

        FAPI_DBG("l_l2_l2cerrs_prd_purge_cmd_reg_data: %#lx", l_l2_l2cerrs_prd_purge_cmd_reg);
        FAPI_TRY(fapi2::putScom(i_target, EX_PRD_PURGE_CMD_REG, l_l2_l2cerrs_prd_purge_cmd_reg),
                 "Error from putScom (l_l2_l2cerrs_prd_purge_cmd_reg)");

        // mark HWP exit
    fapi_try_exit:
        FAPI_INF("Exiting p9_l2err_linedelete...");
        return fapi2::current_err;
    } // p9_l2err_extract

} // extern "C
