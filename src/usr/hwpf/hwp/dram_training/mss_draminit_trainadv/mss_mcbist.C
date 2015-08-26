/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mcbist.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
// $Id: mss_mcbist.C,v 1.57 2015/08/26 16:17:41 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             : mss_mcbist.C
// *! TITLE                : 
// *! DESCRIPTION          : MCBIST Procedures
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Hosmane, Preetham             Email: preeragh@in.ibm.com
// *! BACKUP               : Sethuraman, Saravanan         Email: saravanans@in.ibm.com
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.57  |preeragh|08/25/15| FW Review Comments  MPR
//   1.53  |preeragh|06/22/15| Added MPR
//   1.52  |sglancy |02/16/15| Merged in FW comments with lab needs
//   1.51  |sglancy |02/09/15| Fixed FW comments and adjusted whitespace
//   1.50  |preeragh|01/16/15| Fixed FW comments
//   1.48  |preeragh|01/05/15| Added FW workaround for drand
//   1.48  |preeragh|12/16/14| Revert back changes. v.1.46
//   1.47  |rwheeler|11/19/14|option to pass in rotate data seed
//   1.46  |mjjones |01/20/14|RAS Review Updates
//   1.45  |aditya  |12/17/13|Added Simple_fix_rf
//   1.43  |aditya  |10/05/13|Updated fw comments
//   1.42  |aditya  |09/18/13|Updated Call for functions
//   1.41  |aditya  |08/10/13|Minor Fix for Hostboot compile
//   1.40  |aditya  |06/11/13|Added attributes ATTR_MCBIST_PRINTING_DISABLE and ATTR_MCBIST_DATA_ENABLE
//   1.39  |aditya  |05/22/13|updated parameters for Subtest Printing
//   1.38  |aditya  |05/14/13|updated parameters for cfg_mcb_dgen
//   1.37  |aditya  |02/19/13|updated testtypes
//   1.34  |aditya  |02/13/13|updated testtypes
//   1.33  |aditya  |02/12/13|updated testtypes
//   1.32  |aditya  |02/11/13|updated testtypes  
//   1.31  |aditya  |02/06/13|Updated SIMPLE_RAND test_type
//   1.30  |aditya  |01/30/13|Updated fw comments
//   1.29  |aditya  |01/11/13|Updated  cfg_mcb_dgen function
//   1.28  |aditya  |01/11/13|Updated  cfg_mcb_dgen function
//   1.27  |aditya  |01/11/13|Updated  cfg_mcb_dgen function
//   1.26  |aditya  |01/07/13|Updated Review Comments
//   1.25  |aditya  |01/03/13| Updated FW Comments 
//   1.23  |aditya  |12/18/12| Updated Review Comments 
//   1.22  |aditya  |12/14/12| Updated FW review comments   
//   1.22  |aditya  |12/6/12 | Updated Review Comments
//   1.21  |aditya  |11/15/12| Updated for FIRMWARE REVIEW COMMENTS
//   1.20  |aditya  |10/29/12| updated fw review comments 
//   1.18  |aditya  |10/29/12| Updated from ReturnCode to fapi::ReturnCode and Target to const fapi::Target &  
//   1.17  |aditya  |10/18/12| Replaced insertFromHexRight by SetDoubleWord   
//   1.16  |aditya  |10/17/12| updated code to be compatible with ecmd 13 release
//   1.15  |aditya  |10/01/12| updated fw review comments, datapattern, testtype, addressing	
//   1.14  |mwuu    |07/17/12| updated dram_width tests to new definition
//   1.13  |bellows |07/16/12| added in Id tag
//   1.10  |gaushard|04/26/12| Added ONE_SHMOO parameter
//   1.9   |gaushard|03/26/12| Updated start_mcbist 
//   1.8   |gaushard|03/26/12| Removed Extra Comments/Codes
//   1.7   |gaushard|03/26/12| Added new shmoo modes
//   1.6   |sasethur|03/23/12| Corrected Warning Messages 
//   1.5   |sasethur|03/23/12| Corrected Warning messages
//   1.4   |gaushard|03/22/12| Added Address generation
//   1.3   |gaushard|02/29/12| Added rc_num for Buffer operation
//   1.2   |gaushard|02/14/12| Added rc_buff for buffer access
//   1.1   |gaushard|02/13/12| Updated scom addresses
//   1.0   |gaushard|01/19/12| Initial Version
//------------------------------------------------------------------------------

#include "mss_mcbist.H"
extern "C"
{
using namespace fapi;

const uint8_t MAX_BYTE = 10;
//*****************************************************************/
// Funtion name : cfg_mcb_test_mem
// Description  : This function executes different MCBIST subtests
// Input Parameters :
//     const fapi::Target & i_target_mba      Centaur.mba
//     mcbist_test_mem i_test_type      Subtest Type
//****************************************************************/

fapi::ReturnCode cfg_mcb_test_mem(const fapi::Target & i_target_mba,
                                  mcbist_test_mem i_test_type,
                                  struct Subtest_info l_sub_info[30])
{
    fapi::ReturnCode rc;
    uint8_t l_print = 0;
    uint32_t l_mcbtest;
    uint8_t l_index, l_data_flag, l_random_flag, l_count, l_data_attr;
    l_index = 0;
    l_data_flag = 0;
    l_random_flag = 0;
    l_data_attr = 0;
    uint8_t test_array_count[44] = { 0, 2, 2, 1, 1, 1, 6, 6, 30, 30,
                                     2, 7, 4, 2, 1, 5, 4, 2, 1, 1,
                                     3, 1, 1, 4, 2, 1, 1, 1, 1, 10,
                                     0, 5, 3, 3, 3, 3, 9, 4, 30, 1,
                                     2, 2, 3, 3 };
    rc = FAPI_ATTR_GET(ATTR_MCBIST_PRINTING_DISABLE, &i_target_mba, l_print);
    if (rc) return rc;
    if (l_print == 0)
    {
        FAPI_INF("Function Name: cfg_mcb_test_mem");
        FAPI_INF("Start Time");
    }
    rc = FAPI_ATTR_GET(ATTR_MCBIST_TEST_TYPE, &i_target_mba, l_mcbtest);
    if (rc) return rc;

    if (l_print == 0)
    {
        FAPI_INF("Function - cfg_mcb_test_mem");
    }

    uint8_t l_done_bit = 0;
    rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, l_done_bit);
    if (rc) return rc;

    if (i_test_type == CENSHMOO)
    {
        if (l_print == 0)
        {
            FAPI_INF("Current MCBIST TESTTYPE : CENSHMOO ");
        }
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, SF, FIX, 0, DEFAULT, FIX_ADDR, 0, 0, 1, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 1, 1, 1, l_sub_info);
        if (rc) return rc;
    }
    else if (i_test_type == MEMWRITE)
    {
        if (l_print == 0)
        {
            FAPI_INF("Current MCBIST TESTTYPE : MEMWRITE ");
        }
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 0, 0, 0, l_sub_info);
        if (rc) return rc;
    }
    else if (i_test_type == MEMREAD)
    {
        if (l_print == 0)
        {
            FAPI_INF("Current MCBIST TESTTYPE : MEMREAD ");
        }
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 0, 0, 0, l_sub_info);
        if (rc) return rc;
    }
    else if (i_test_type == SIMPLE_FIX)
    {
        if (l_print == 0)
        {
            FAPI_INF("Current MCBIST TESTTYPE : SIMPLE_FIX ");
        }
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, SF, FIX, 0, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info);
        if (rc) return rc;

        l_done_bit = 1;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, l_done_bit);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 2, 2, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                OPER_RAND, 0, RF, FIX, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR1Q_0x030106a9,
                                RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info);
        if (rc)
            return rc;
    }
    else if (i_test_type == SIMPLE_RAND)
    {
        if (l_print == 0)
            FAPI_INF("Current MCBIST TESTTYPE : SIMPLE_RAND ");
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                WR, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info);
        if (rc) return rc;

        l_done_bit = 1;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, l_done_bit);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 1, SF, DATA_RF, 0, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 2, 2, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, RF, DATA_RF, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR1Q_0x030106a9,
                                RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info);
        if (rc) return rc;
    }
    else if (i_test_type == WR_ONLY)
    {
        if (l_print == 0)
        {
            FAPI_INF("Current MCBIST TESTTYPE : WR_ONLY ");
        }
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, SF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info);
        if (rc) return rc;

        l_done_bit = 1;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, l_done_bit);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, RF, FIX, 0, DEFAULT, FIX_ADDR, 2, 2, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                OPER_RAND, 0, RF, FIX, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR1Q_0x030106a9,
                                RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info);
        if (rc) return rc;
    }
    else if (i_test_type == W_ONLY)
    {
        if (l_print == 0)
        {
            FAPI_INF("Current MCBIST TESTTYPE : W_ONLY ");
        }
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info);
        if (rc) return rc;

        l_done_bit = 1;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, l_done_bit);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, SF, FIX, 1, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, RF, FIX, 0, DEFAULT, FIX_ADDR, 2, 2, 4,
                                l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                OPER_RAND, 0, RF, FIX, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR1Q_0x030106a9,
                                RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info);
        if (rc) return rc;
    }
    else if (i_test_type == R_ONLY)
    {
        if (l_print == 0)
        {
            FAPI_INF("Current MCBIST TESTTYPE : R_ONLY ");
        }
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info);
        if (rc) return rc;

        l_done_bit = 1;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, l_done_bit);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                GOTO, 0, SF, FIX, 0, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, RF, FIX, 0, DEFAULT, FIX_ADDR, 2, 2, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                OPER_RAND, 0, RF, FIX, 1, DEFAULT, FIX_ADDR, 3, 3, 4, l_sub_info);
        if (rc) return rc;

        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR1Q_0x030106a9,
                                RW, 4, RF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 4, 4, l_sub_info);
        if (rc) return rc;
    }
    else if (i_test_type == SIMPLE_FIX_RF)
    {
        FAPI_DBG("%s:Current MCBIST TESTTYPE : SIMPLE_FIX_RF ",
                 i_target_mba.toEcmdString());
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                W, 0, SF, DATA_RF, 0, DEFAULT, FIX_ADDR, 0, 0, 4, l_sub_info);
        if (rc) return rc;
        rc = mcb_write_test_mem(i_target_mba, MBA01_MCBIST_MCBMR0Q_0x030106a8,
                                R, 0, SF, DATA_RF, 1, DEFAULT, FIX_ADDR, 1, 1, 4, l_sub_info);
        if (rc) return rc;
        l_done_bit = 1;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, l_done_bit);
        if (rc) return rc;
    }
    else
    {
        FAPI_ERR("Invalid MCBIST test type (%d)! cfg_mcb_test_mem Function",
                 i_test_type);
        const mcbist_test_mem & TEST_TYPE_PARAM = i_test_type;
        FAPI_SET_HWP_ERROR(rc, RC_CFG_MCB_TEST_MEM_INVALID_INPUT);
        return rc;
    }

    if (l_print == 0)
    {
        FAPI_INF("Function Name: cfg_mcb_test_mem");
        FAPI_INF("Stop Time");
    }

    l_count = test_array_count[l_mcbtest];
    for (l_index = 0; l_index < l_count; l_index++)
    {
        if (l_sub_info[l_index].l_fixed_data_enable == 1)
        {
            l_data_flag = 1;
        }
        if (l_sub_info[l_index].l_random_data_enable == 1)
        {
            l_random_flag = 1;
        }
    }
    if ((l_data_flag == 0) && (l_random_flag == 1))
    {
        l_data_attr = 1;
    }
    else if ((l_data_flag == 1) && (l_random_flag == 0))
    {
        l_data_attr = 2;
    }
    else if ((l_data_flag == 1) && (l_random_flag == 1))
    {
        l_data_attr = 3;
    }
    else
    {
        l_data_attr = 3;
    }
    rc = FAPI_ATTR_SET(ATTR_MCBIST_DATA_ENABLE, &i_target_mba, l_data_attr);
    if (rc) return rc;

    return rc;

}

//*****************************************************************/
// Funtion name : cfg_mcb_dgen
// Description  : This function writes data patterns based on i_datamode passed
// Input Parameters :
//     const fapi::Target & i_target_mba      Centaur.mba
//     mcbist_data_gen i_datamode       MCBIST Data mode 
//     uint8_t i_mcbrotate              Provides the number of bit to shift per burst
//     uint64_t i_mcbrotdata            Provides the data seed to shift per burst
//****************************************************************/
fapi::ReturnCode cfg_mcb_dgen(const fapi::Target & i_target_mba,
                              mcbist_data_gen i_datamode,
                              uint8_t i_mcbrotate,
                              uint64_t i_mcbrotdata)
{
    uint8_t l_print = 0;

    uint8_t l_data_attr, l_random_flag, l_data_flag;
    l_data_flag = 1;
    l_random_flag = 1;
    l_data_attr = 3;
    uint8_t l_seed_choice;
    uint32_t i_seed;
    i_seed = 0x20;
    l_seed_choice = 1;
    ecmdDataBufferBase l_data_buffer_64(64);
    ecmdDataBufferBase l_var_data_buffer_64(64);
    ecmdDataBufferBase l_var1_data_buffer_64(64);
    ecmdDataBufferBase l_spare_data_buffer_64(64);
    ecmdDataBufferBase l_data_buffer_32(32);
    ecmdDataBufferBase l_data_buffer_16(16);
    ecmdDataBufferBase l_data_buffer_4(4);
    ecmdDataBufferBase l_data_buffer1_4(4);
    uint64_t l_var = 0x0000000000000000ull;
    uint64_t l_var1 = 0x0000000000000000ull;
    uint64_t l_spare = 0x0000000000000000ull;
    uint8_t l_rotnum = 0;
    uint32_t l_mba01_mcb_pseudo_random[MAX_BYTE] = {
        MBA01_MCBIST_MCBFD0Q_0x030106be, MBA01_MCBIST_MCBFD1Q_0x030106bf,
        MBA01_MCBIST_MCBFD2Q_0x030106c0, MBA01_MCBIST_MCBFD3Q_0x030106c1,
        MBA01_MCBIST_MCBFD4Q_0x030106c2, MBA01_MCBIST_MCBFD5Q_0x030106c3,
        MBA01_MCBIST_MCBFD6Q_0x030106c4, MBA01_MCBIST_MCBFD7Q_0x030106c5,
        MBA01_MCBIST_MCBFDQ_0x030106c6, MBA01_MCBIST_MCBFDSPQ_0x030106c7 };
    uint32_t l_mba01_mcb_random[MAX_BYTE] = { MBA01_MCBIST_MCBRDS0Q_0x030106b2,
        MBA01_MCBIST_MCBRDS1Q_0x030106b3, MBA01_MCBIST_MCBRDS2Q_0x030106b4,
        MBA01_MCBIST_MCBRDS3Q_0x030106b5, MBA01_MCBIST_MCBRDS4Q_0x030106b6,
        MBA01_MCBIST_MCBRDS5Q_0x030106b7, MBA01_MCBIST_MCBRDS6Q_0x030106b8,
        MBA01_MCBIST_MCBRDS7Q_0x030106b9, MBA01_MCBIST_MCBRDS8Q_0x030106ba,
        0x030106bb };
    uint32_t l_mbs01_mcb_random[MAX_BYTE] = { 0x02011675, 0x02011676,
        0x02011677, 0x02011678, 0x02011679, 0x0201167a, 0x0201167b, 0x0201167c,
        0x0201167d, 0x0201167e };
    uint32_t l_mbs23_mcb_random[MAX_BYTE] = { 0x02011775, 0x02011776,
        0x02011777, 0x02011778, 0x02011779, 0x0201177a, 0x0201177b, 0x0201177c,
        0x0201177d, 0x0201177e };

    uint8_t l_index, l_index1 = 0;
    uint32_t l_rand_32 = 0;
    uint32_t l_rand_8 = 0;
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    if (l_print == 0)
    {
        FAPI_INF("Function Name: cfg_mcb_dgen");
        FAPI_INF(" Data mode is %d ", i_datamode);
    }
    uint8_t l_mbaPosition = 0;

    fapi::Target i_target_centaur;
    rc = fapiGetParentChip(i_target_mba, i_target_centaur);
    if (rc)
    {
        if (l_print == 0)
        {
            FAPI_INF("Error in getting parent chip!");
        }
        return rc;
    }

    if (l_print == 0)
    {
        FAPI_INF("Function cfg_mcb_dgen");
    }
    //Read MBA position attribute 0 - MBA01 1 - MBA23
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbaPosition);
    if (rc)
    {
        FAPI_ERR("Error getting MBA position");
        return rc;
    }
    rc = FAPI_ATTR_GET(ATTR_MCBIST_PRINTING_DISABLE, &i_target_mba, l_print);
    if (rc) return rc;

    rc = FAPI_ATTR_GET(ATTR_MCBIST_DATA_ENABLE, &i_target_mba, l_data_attr);
    if (rc) return rc;

    if (l_data_attr == 1)
    {
        l_data_flag = 0;
        l_random_flag = 1;
    }
    else if (l_data_attr == 2)
    {
        l_data_flag = 1;
        l_random_flag = 0;
    }
    else if (l_data_attr == 3)
    {
        l_data_flag = 1;
        l_random_flag = 1;
    }
    else
    {
        l_data_flag = 1;
        l_random_flag = 1;
    }

    if (l_data_flag == 1)
    {
        if (i_datamode == MCBIST_2D_CUP_PAT5)
        {
            l_var = 0xFFFF0000FFFF0000ull;
            l_var1 = 0x0000FFFF0000FFFFull;
            l_spare = 0xFF00FF00FF00FF00ull;

            rc_num = l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            rc_num |= l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6, l_spare_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7, l_spare_data_buffer_64);
            if (rc) return rc;
        }
        else if (i_datamode == MCBIST_2D_CUP_PAT8)
        {
            l_var = 0xFFFFFFFFFFFFFFFFull;
            l_var1 = 0x0000000000000000ull;
            l_spare = 0xFFFF0000FFFF0000ull;
            rc_num = l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            rc_num |= l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6, l_spare_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7, l_spare_data_buffer_64);
            if (rc) return rc;
        }
        else if (i_datamode == ABLE_FIVE)
        {
            l_var = 0xA5A5A5A5A5A5A5A5ull;
            l_var1 = 0x5A5A5A5A5A5A5A5Aull;
            l_spare = 0xA55AA55AA55AA55Aull;

            rc_num = l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            rc_num |= l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6, l_spare_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7, l_spare_data_buffer_64);
            if (rc) return rc;
        }
		else if(i_datamode == MPR)
		{
			l_var = 0x0000000000000000ull;
			l_var1 =0xFFFFFFFFFFFFFFFFull;
			l_spare = 0x00FF00FF00FF00FFull;
			
			rc_num = l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            rc_num |= l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_var_data_buffer_64); if(rc) return rc;
		 
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_var1_data_buffer_64); if(rc) return rc;
		 
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_var_data_buffer_64); if(rc) return rc;
	  
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_var1_data_buffer_64); if(rc) return rc;
		 
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_var_data_buffer_64); if(rc) return rc;
		 
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_var1_data_buffer_64); if(rc) return rc;
 
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_var_data_buffer_64); if(rc) return rc;	
		 
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_var1_data_buffer_64); if(rc) return rc;
	 
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6 , l_spare_data_buffer_64); if(rc) return rc;
		
		rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7 , l_spare_data_buffer_64); if(rc) return rc;
		}
		else if ((i_datamode == DATA_GEN_DELTA_I) ||
                 (i_datamode == MCBIST_2D_CUP_PAT0))
        {
            l_var = 0xFFFFFFFFFFFFFFFFull;
            l_var1 = 0x0000000000000000ull;
            l_spare = 0xFF00FF00FF00FF00ull;
            rc_num = l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            rc_num |= l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD0Q_0x030106be, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD1Q_0x030106bf, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD2Q_0x030106c0, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD3Q_0x030106c1, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD4Q_0x030106c2, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD5Q_0x030106c3, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD6Q_0x030106c4, l_var_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFD7Q_0x030106c5, l_var1_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDQ_0x030106c6, l_spare_data_buffer_64);
            if (rc) return rc;
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBFDSPQ_0x030106c7, l_spare_data_buffer_64);
            if (rc) return rc;
        }
        else if (i_datamode == PSEUDORANDOM)
        {
            l_rand_32 = 0xFFFFFFFF;//Hard Coded Temporary Fix till random function is fixed
            // srand(2);
            if (l_seed_choice == 1)
            {
                if (i_seed == 0)
                {
                    i_seed = 0xFFFFFFFF;
                }
                l_rand_32 = i_seed;
            }

            for (l_index = 0; l_index < (MAX_BYTE); l_index++)
            {
                //l_rand_32 = rand();

                rc_num |= l_data_buffer_32.insertFromRight(l_rand_32, 0, 32);
                rc_num |= l_data_buffer_64.insert(l_data_buffer_32, 0, 32, 0);
                //l_rand_32 = rand();
                rc_num |= l_data_buffer_32.insertFromRight(l_rand_32, 0, 32);
                rc_num |= l_data_buffer_64.insert(l_data_buffer_32, 32, 32, 0);
                if (rc_num)
                {
                    FAPI_ERR("cfg_mcb_dgen:");
                    rc.setEcmdError(rc_num);
                    return rc;
                }
                rc = fapiPutScom(i_target_mba, l_mba01_mcb_pseudo_random[l_index],
                                 l_data_buffer_64);
                if (rc) return rc;
            }
        }
        else
        {
            FAPI_ERR("cfg_mcb_dgen: Invalid data mode (%d)", i_datamode);
            const mcbist_data_gen & DATA_MODE_PARAM = i_datamode;
            FAPI_SET_HWP_ERROR(rc, RC_CFG_MCB_DGEN_INVALID_INPUT);
            return rc;
        }

        if (i_datamode == MCBIST_2D_CUP_PAT5)
        {
            l_var = 0xFFFF0000FFFF0000ull;
            l_var1 = 0x0000FFFF0000FFFFull;
            l_spare = 0xFF00FF00FF00FF00ull;

            rc_num = l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            rc_num |= l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            if (l_mbaPosition == 0)
            {
                //Writing MBS 01 pattern registers for comparison mode
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD0Q_0x02011681, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD1Q_0x02011682, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD2Q_0x02011683, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD3Q_0x02011684, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD4Q_0x02011685, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD5Q_0x02011686, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD6Q_0x02011687, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD7Q_0x02011688, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDQ_0x02011689, l_spare_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A, l_spare_data_buffer_64);
                if (rc) return rc;
            }
            else if (l_mbaPosition == 1)
            {
                //Writing MBS 23 pattern registers for comparison mode
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD0Q_0x02011781, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD1Q_0x02011782, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD2Q_0x02011783, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD3Q_0x02011784, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD4Q_0x02011785, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD5Q_0x02011786, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD6Q_0x02011787, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD7Q_0x02011788, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDQ_0x02011789, l_spare_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A, l_spare_data_buffer_64);
                if (rc) return rc;
            }
        }
        else if (i_datamode == MCBIST_2D_CUP_PAT8)
        {
            l_var = 0xFFFFFFFFFFFFFFFFull;
            l_var1 = 0x0000000000000000ull;
            l_spare = 0xFFFF0000FFFF0000ull;

            rc_num = l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            rc_num |= l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            if (l_mbaPosition == 0)
            {
                //Writing MBS 01 pattern registers for comparison mod
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD0Q_0x02011681, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD1Q_0x02011682, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD2Q_0x02011683, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD3Q_0x02011684, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD4Q_0x02011685, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD5Q_0x02011686, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD6Q_0x02011687, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD7Q_0x02011688, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDQ_0x02011689, l_spare_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A, l_spare_data_buffer_64);
                if (rc) return rc;
            }
            else if (l_mbaPosition == 1)
            {
                //Writing MBS 23 pattern registers for comparison mod
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD0Q_0x02011781, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD1Q_0x02011782, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD2Q_0x02011783, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD3Q_0x02011784, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD4Q_0x02011785, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD5Q_0x02011786, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD6Q_0x02011787, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD7Q_0x02011788, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDQ_0x02011789, l_spare_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A, l_spare_data_buffer_64);
                if (rc) return rc;
            }
        }
        else if (i_datamode == ABLE_FIVE)
        {
            l_var = 0xA5A5A5A5A5A5A5A5ull;
            l_var1 = 0x5A5A5A5A5A5A5A5Aull;
            l_spare = 0xA55AA55AA55AA55Aull;

            rc_num = l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            rc_num |= l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            if (l_mbaPosition == 0)
            {
                //Writing MBS 01 pattern registers for comparison mod
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD0Q_0x02011681, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD1Q_0x02011682, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD2Q_0x02011683, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD3Q_0x02011684, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD4Q_0x02011685, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD5Q_0x02011686, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD6Q_0x02011687, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD7Q_0x02011688, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDQ_0x02011689,  l_spare_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A, l_spare_data_buffer_64);
                if (rc) return rc;
            }
            else if (l_mbaPosition == 1)
            {
                //Writing MBS 23 pattern registers for comparison mod
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD0Q_0x02011781, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD1Q_0x02011782, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD2Q_0x02011783, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD3Q_0x02011784, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD4Q_0x02011785, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD5Q_0x02011786, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD6Q_0x02011787, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD7Q_0x02011788, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDQ_0x02011789, l_spare_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A, l_spare_data_buffer_64);
                if (rc) return rc;
            }
        }
        else if ((i_datamode == DATA_GEN_DELTA_I) || (i_datamode
            == MCBIST_2D_CUP_PAT0))
        {
            l_var = 0xFFFFFFFFFFFFFFFFull;
            l_var1 = 0x0000000000000000ull;
            l_spare = 0xFF00FF00FF00FF00ull;

            rc_num = l_var_data_buffer_64.setDoubleWord(0, l_var);
            rc_num |= l_var1_data_buffer_64.setDoubleWord(0, l_var1);
            rc_num |= l_spare_data_buffer_64.setDoubleWord(0, l_spare);
            if (rc_num)
            {
                FAPI_ERR("cfg_mcb_dgen:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            if (l_mbaPosition == 0)
            {
                //Writing MBS 01 pattern registers for comparison mod
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD0Q_0x02011681, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur,MBS_MCBIST01_MBS_MCBFD1Q_0x02011682, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD2Q_0x02011683, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD3Q_0x02011684, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD4Q_0x02011685, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD5Q_0x02011686, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD6Q_0x02011687, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFD7Q_0x02011688, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDQ_0x02011689, l_spare_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MBS_MCBFDSPQ_0x0201168A, l_spare_data_buffer_64);
                if (rc) return rc;
            }
            else if (l_mbaPosition == 1)
            {
                //Writing MBS 23 pattern registers for comparison mod
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD0Q_0x02011781, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD1Q_0x02011782, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD2Q_0x02011783, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD3Q_0x02011784, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD4Q_0x02011785, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD5Q_0x02011786, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD6Q_0x02011787, l_var_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFD7Q_0x02011788, l_var1_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDQ_0x02011789, l_spare_data_buffer_64);
                if (rc) return rc;
                rc = fapiPutScom(i_target_centaur, MBS_MCBIST23_MBS_MCBFDSPQ_0x0201178A, l_spare_data_buffer_64);
                if (rc) return rc;
            }
        }
        else
        {
            FAPI_ERR("cfg_mcb_dgen: Invalid data mode (%d)", i_datamode);
            const mcbist_data_gen & DATA_MODE_PARAM = i_datamode;
            FAPI_SET_HWP_ERROR(rc, RC_CFG_MCB_DGEN_INVALID_INPUT);
            return rc;
        }
    }

    if (l_random_flag == 1)
    {
        for (l_index = 0; l_index < MAX_BYTE; l_index++)
        {

            for (l_index1 = 0; l_index1 < 8; l_index1++)
            {
                //l_rand_8 = rand();
                l_rand_8 = 0xFF;
                rc_num = l_data_buffer_64.insert(l_rand_8, 8 * l_index1, 8, 24);
                if (rc_num)
                {
                    FAPI_ERR("cfg_mcb_dgen:");
                    rc.setEcmdError(rc_num);
                    return rc;
                } // Source start in sn is given as 24 -- need to ask
            }
            rc = fapiPutScom(i_target_mba, l_mba01_mcb_random[l_index], l_data_buffer_64);
            if (rc) return rc;

            if (l_mbaPosition == 0)
            {
                rc = fapiPutScom(i_target_centaur, l_mbs01_mcb_random[l_index], l_data_buffer_64);
                if (rc) return rc;

            }
            else
            {
                rc = fapiPutScom(i_target_centaur, l_mbs23_mcb_random[l_index], l_data_buffer_64);
                if (rc) return rc;
            }
        }
    }
    
    #ifdef FAPI_MSSLABONLY
    struct drand48_data randBuffer;
    double l_rand_D = 0;
    uint8_t l_rand_l = 0; 
    #endif
    uint64_t l_data_buffer_64_value = 0;

    // get the rotate value loaded into reg, if rotate value 0 / not defined the default to rotate =13
    if(i_mcbrotate == 0)
    {
        FAPI_DBG("%s:i_mcbrotate == 0 , the l_rotnum is set to 13",i_target_mba.toEcmdString());
        l_rotnum = 13;   // for random data generation - basic setup
    }
    else
    {
        l_rotnum = i_mcbrotate;
    }
	
	
    rc_num = rc_num | l_data_buffer_64.flushTo0();
    
    // get the rotate data seed loaded into reg, if rotate data value = 0 / not defined the default rotate pttern is randomlly generated.    
    if(i_mcbrotdata == 0)
    {   // generate the random number
        
	#ifdef FAPI_MSSLABONLY
     	for(l_index1 = 0; l_index1 < 8; l_index1++)
     	{
     	   //l_rand_8 = drand48_r();
     	   drand48_r(&randBuffer, &l_rand_D);
     	   //l_rand_l = (uint8_t)l_rand_D;
     	   l_rand_l = static_cast<unsigned int>((l_rand_D * 100) + 0.5);
     	   if(l_rand_l == 0x00)
     	   {
     	      l_rand_l = 0xFF;
     	   }
     	   //FAPI_INF("%s:Value of seed drand48_r : %02X",i_target_mba.toEcmdString(), l_rand_l  );
     	   rc_num = rc_num | l_data_buffer_64.insert(l_rand_l,8*l_index1,8);	   // Source start in sn is given as 24 -- need to ask
	   if (rc_num)
           {
              FAPI_ERR( "cfg_mcb_dgen: setting up mcbrotate data error");       // Error setting up buffers
              rc.setEcmdError(rc_num);
              return rc;
           }
     	}
        #else
	   rc_num = rc_num | l_data_buffer_64.setDoubleWord(0,0x863A822CDF2924C4ull);
	   if (rc_num)
           {
              FAPI_ERR( "cfg_mcb_dgen: setting up mcbrotate data error");       // Error setting up buffers
              rc.setEcmdError(rc_num);
              return rc;
           }
	#endif
    }
    else
    {
     	rc_num = rc_num | l_data_buffer_64.setDoubleWord(0,i_mcbrotdata);	
	if (rc_num)
        {
          FAPI_ERR( "cfg_mcb_dgen:");       // Error setting up buffers
          rc.setEcmdError(rc_num);
          return rc;
       }
    }
    
    // load the mcbist and mba with rotnum and rotdata.
    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBDRSRQ_0x030106bc , l_data_buffer_64); if(rc) return rc;//added
    if(l_mbaPosition == 0)
    {
       rc = fapiPutScom(i_target_centaur, 0x0201167F , l_data_buffer_64); if(rc) return rc;
       l_data_buffer_64_value = l_data_buffer_64.getDoubleWord (0);
       FAPI_INF("%s:Value of Rotate data seed %016llX for reg %08X",i_target_mba.toEcmdString(), l_data_buffer_64_value, 0x0201167F );
       
       rc_num = rc_num | l_data_buffer_16.insert(l_data_buffer_64,0,16); 
       rc = fapiGetScom(i_target_centaur, 0x02011680 , l_data_buffer_64); if(rc) return rc;
       rc_num = rc_num | l_data_buffer_64.insert(l_rotnum,0,4,4);
       rc_num = rc_num | l_data_buffer_64.insert(l_data_buffer_16,4,16);
       if (rc_num)
       {
          FAPI_ERR( "cfg_mcb_dgen:");       // Error setting up buffers
          rc.setEcmdError(rc_num);
          return rc;
       }	   
       rc = fapiPutScom(i_target_centaur, 0x02011680 , l_data_buffer_64); if(rc) return rc;
       
    }
    else
    {
       rc = fapiPutScom(i_target_centaur, 0x0201177F , l_data_buffer_64); if(rc) return rc;//added
       l_data_buffer_64_value = l_data_buffer_64.getDoubleWord (0);
       FAPI_INF("%s:Value of Rotate data seed %016llX for reg %08X",i_target_mba.toEcmdString(), l_data_buffer_64_value, 0x0201177F );

       rc_num = rc_num | l_data_buffer_16.insert(l_data_buffer_64,0,16);        
       rc = fapiGetScom(i_target_centaur, 0x02011780 , l_data_buffer_64); if(rc) return rc;
       rc_num = rc_num | l_data_buffer_64.insert(l_rotnum,0,4,4);
       rc_num = rc_num | l_data_buffer_64.insert(l_data_buffer_16,4,16);
       if (rc_num)
       {
          FAPI_ERR( "cfg_mcb_dgen:");       // Error setting up buffers
          rc.setEcmdError(rc_num);
          return rc;
       }	  	   
       rc = fapiPutScom(i_target_centaur, 0x02011780 , l_data_buffer_64); if(rc) return rc;
       
    }

    FAPI_DBG("%s: Preet Clearing bit 20 of MBA01_MCBIST_MCBDRCRQ_0x030106bd to avoid inversion of data to the write data flow",i_target_mba.toEcmdString());
    rc_num = rc_num | l_data_buffer_64.clearBit(20,2); 
    if (rc_num)
    {
       FAPI_ERR( "cfg_mcb_dgen:");	 // Error setting up buffers
       rc.setEcmdError(rc_num);
       return rc;
    }
    rc = fapiPutScom(i_target_mba,MBA01_MCBIST_MCBDRCRQ_0x030106bd,l_data_buffer_64); 
   
    return rc;
}

}
