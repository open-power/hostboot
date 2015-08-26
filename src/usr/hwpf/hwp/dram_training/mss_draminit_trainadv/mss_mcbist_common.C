/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_mcbist_common.C $ */
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
// $Id: mss_mcbist_common.C,v 1.76 2015/08/07 11:08:45 sasethur Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             : mss_mcbist_common.C
// *! TITLE                :
// *! DESCRIPTION          : MCBIST Procedures
// *! CONTEXT              :
// *!
// *! OWNER  NAME          : Preetham Hosmane        	   Email: preeragh@in.ibm.com
// *! BACKUP               : Sethuraman, Saravanan         Email: saravanans@in.ibm.com
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.76  |preeragh|07/15/15|R_W Infinite Added
//   1.75  |lapietra|06/26/15|added RMWFIX and RMWFIX_I tests
//   1.74  |preeragh|06/15/15|o_error_map Correction
//   1.73  |sglancy |02/16/15|Merged in lab needs
//   1.72  |sglancy |02/09/15|Fixed FW comments and addressed bugs
//   1.71  |preeragh|01/16/15|Fixed FW comments
//   1.70  |preeragh|12/16/14|Revert to FW build v.1.66
//   1.68  |rwheeler|11/19/14|option to pass in rotate data seed
//   1.67  |sglancy |11/03/14|Fixed MCBIST to allow for a custom user generated address - removed forcing of l_new_addr=1
//   1.66  |preeragh|11/03/14|Fix Addressing Map and enable Refresh
//   1.65  |        | -      | - 
//   1.64  |rwheeler|10/24/14|Added thermal sensor data 
//   1.63  |adityamd|02/07/14|RAS Review Updates
//   1.62  |mjjones |01/17/14|RAS Review Updates
//   1.61  |aditya  |01/15/14|Updated attr ATTR_EFF_CUSTOM_DIMM
//   1.60  |aditya  |12/20/13|Updated max timeout for Mcbist Polling
//   1.59  |aditya  |12/17/13|Updated mcb_error_map function parameters
//   1.58  |aditya  |12/10/13|Updated Target for MBS registers
//   1.57  |rwheeler|10/29/13 |added W_ONLY_INFINITE_RAND test
//   1.56  |aditya  |10/29/13|Updated mcb_error_map function parameters
//   1.55  |aditya  |10/24/13|Removed DD2.0 attribute check  for  ECC setup
//   1.54  |aditya  |10/17/13|Minor fix in byte mask function
//   1.53  |aditya  |10/05/13|Updated fw comments
//   1.52  |aditya  |09/27/13|Updated for Host Boot Compile
//   1.51  |aditya  |09/18/13|Updated parameters for random seed attribute and Error map masking
//   1.50  |aditya  |08/08/13|Updated for Host Boot Compile
//   1.49  |aditya  |08/02/13|Updated Error Map  function
//   1.48  |aditya  |07/09/13|Added l_random_addr_enable and l_fixed_addr_enable for struct Subtest_info
//   1.47  |aditya  |06/11/13|Replaced FAPI_INF to FAPI_DBG,Added target details for Prints
//   1.46  |aditya  |06/11/13|Enabled pattern and testtype prints
//   1.45  |aditya  |06/11/13|Added attributes ATTR_MCBIST_PRINTING_DISABLE
//   1.44  |aditya  |05/23/13|Added TEST_RR and TEST_RF testtypes
//   1.43  |aditya  |05/22/13|updated parameters for Subtest Printing
//   1.41  |aditya  |05/14/13|updated parameters for random seed details
//   1.40  |aditya  |05/07/13|Small Fix
//   1.39  |aditya  |05/07/13|Moved some parameters to attributes.
//   1.38  |aditya  |04/30/13|Minor fix for firmware
//   1.37  |aditya  |04/22/13|Minor Fix
//   1.36  |aditya  |04/09/13|Updated cfg_byte_mask and setup_mcbist functions
//   1.35  |aditya  |03/18/13|Updated cfg_byte_mask and error map functions
//   1.34  |aditya  |03/15/13|Added ISDIMM error map
//   1.33  |aditya  |03/06/13|Updated Error map and addressing
//   1.32  |aditya  |02/27/13|removed Port looping
//   1.29  |aditya  |02/19/13|Updated Testtypes and removed rank looping
//   1.26  |aditya  |02/13/13|Modified Addressing
//   1.24  |aditya  |02/12/13|Modified Addressing
//   1.23  |aditya  |02/07/13|Added MBS23 registers
//   1.22  |abhijit |02/06/13|Updated cfg_byte_mask function
//   1.21  |abhijit |01/30/13|Updated cfg_byte_mask function
//   1.20  |aditya  |01/30/13|Updated fw comments
//   1.18  |aditya  |01/30/13|Updated fw comments
//   1.17  |aditya  |01/16/13|Updated setup_mcbist function
//   1.16  |aditya  |01/11/13|Updated function headers
//   1.15  |aditya  |01/11/13|added  parameters to setup_mcbist function
//   1.14  |aditya  |01/07/13|Updated Review Comments
//   1.13  |aditya  |01/03/13| Updated FW Comments
//   1.10  |sasethur|12/14/12| Updated for warnings
//   1.9   |aditya  |12/14/12| Updated FW review comments
//   1.8   |aditya  |12/6/12 | Updated Review Comments
//   1.7   |aditya  |11/15/12| Updated for FW REVIEW COMMENTS
//   1.6   |aditya  |10/31/12| Fixed issue in mcb_error_map function
//   1.5   |abhijit |10/29/12| fixed issue in byte mask function
//   1.4   |aditya  |10/29/12| Updated from ReturnCode to fapi::ReturnCode and Target to const fapi::Target &
//   1.3   |aditya  |10/18/12| Replaced insertFromBin by InsertFromRight
//   1.2   |aditya  |10/17/12| updated code to be compatible with ecmd 13 release
//   1.1   |aditya  |10/01/12| updated fw review comments, datapattern, testtype, addressing	
//
//
//This File mss_mcbist_common.C contains the definition of common procedures for the files mss_mcbist.C and mss_mcbist_lab.C
//------------------------------------------------------------------------------
#include "mss_mcbist.H"
#include "mss_mcbist_address.H"
#include <mss_access_delay_reg.H>
#include <fapiTestHwpDq.H>
#include <dimmBadDqBitmapFuncs.H>
#ifdef FAPI_MSSLABONLY
#include <mss_cen_dimm_temp_sensor.H>
#endif
extern "C"
{
using namespace fapi;

#define MCB_DEBUG
#define MCB_DEBUG1
#define MCB_DEBUG2

const uint8_t MAX_PORT = 2;
const uint8_t MAX_DRAM = 20;
const uint8_t MAX_ISDIMM_DQ = 72;
const uint8_t MAX_BYTE = 10;
const uint8_t MAX_RANK = 8;
const uint8_t MAX_NIBBLES = 2;
const uint8_t MCB_TEST_NUM = 16;
const uint64_t MCB_MAX_TIMEOUT = 0000000000060000ull;
const uint64_t DELAY_100US = 100000; // general purpose 100 usec delay for HW mode (2000000 sim cycles if simclk = 20ghz)
const uint64_t DELAY_2000SIMCYCLES = 2000; // general purpose 2000 sim cycle delay for sim mode     (100 ns if simclk = 20Ghz)

const uint64_t END_ADDRESS = 0x0000000010000000ull; //Will be fixed later, once the address generation function is ready
const uint64_t START_ADDRESS = 0x0000000004000000ull;
const uint64_t FEW_INTERVAL = 0x000000000C000000ull;
const uint64_t FOUR = 0x0000000000000004ull;

//*****************************************************************/
// Funtion name : setup_mcbist
// Description  : Will setup the required MCBIST configuration register
// Input Parameters :
//     const fapi::Target &            Centaur.mba
//     uint8_t i_port                   Port on which we are operating.

//     mcbist_data_gen i_mcbpatt        Data pattern
//     mcbist_test_mem i_mcbtest        subtest Type
//     mcbist_byte_mask i_mcbbytemask   It is used to mask bad bits read from SPD
//     uint8_t i_mcbrotate              Provides the number of bit to shift per burst
//     uint64_t i_mcbrotdata            Provides the rotate data to shift per burst

//     uint8_t i_pattern                Data Pattern
//     uint8_t i_test_type              Subtest Type
//     uint8_t i_rank                   Current Rank
//     ,uint8_t i_bit32                 Flag to set bit 32 of register 02011674
//uint64_t i_start                      Flag to set start address
// uint64_t i_end                       Flag to set End address
//uint8_t new_address_map				Flag to Enable Custom Address Map
//****************************************************************/

fapi::ReturnCode setup_mcbist(const fapi::Target & i_target_mba,
                              mcbist_byte_mask i_mcbbytemask,
                              uint8_t i_mcbrotate,
                              uint64_t i_mcbrotdata,
                              struct Subtest_info l_sub_info[30],
			      char * l_str_cust_addr)
{
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    uint8_t l_bit32 = 0;

    FAPI_DBG("%s:Function Setup_MCBIST", i_target_mba.toEcmdString());
    FAPI_DBG("Custom Addr Mode %s",l_str_cust_addr);
    ecmdDataBufferBase l_data_buffer_64(64);
    ecmdDataBufferBase l_data_bufferx1_64(64);
    ecmdDataBufferBase l_data_bufferx2_64(64);
    ecmdDataBufferBase l_data_bufferx3_64(64);
    ecmdDataBufferBase l_data_bufferx4_64(64);
    uint64_t io_start_address = 0;
    uint64_t io_end_address = 0;
    uint8_t l_new_addr = 1;
    uint32_t i_mcbpatt, i_mcbtest;

    mcbist_test_mem i_mcbtest1;
    mcbist_data_gen i_mcbpatt1;
    i_mcbtest1 = CENSHMOO;
    i_mcbpatt1 = ABLE_FIVE;

    uint8_t l_index = 0;
    uint8_t l_flag = 0;
    uint64_t scom_array[8] = {
        MBA01_MBABS0_0x03010440, MBA01_MBABS1_0x03010441,
        MBA01_MBABS2_0x03010442, MBA01_MBABS3_0x03010443,
        MBA01_MBABS4_0x03010444, MBA01_MBABS5_0x03010445,
        MBA01_MBABS6_0x03010446, MBA01_MBABS7_0x03010447 };

    uint64_t l_scom_array_MBS[16] = {
        MBS_ECC0_MBSBS2_0x02011460, MBS_ECC0_MBSBS3_0x02011461,
        MBS_ECC0_MBSBS4_0x02011462, MBS_ECC0_MBSBS5_0x02011463,
        MBS_ECC0_MBSBS6_0x02011464, MBS_ECC0_MBSBS7_0x02011465,
        MBS_ECC1_MBSBS0_0x0201149E, MBS_ECC1_MBSBS1_0x0201149F,
        MBS_ECC1_MBSBS2_0x020114A0, MBS_ECC1_MBSBS3_0x020114A1,
        MBS_ECC1_MBSBS4_0x020114A2, MBS_ECC1_MBSBS5_0x020114A3,
        MBS_ECC1_MBSBS6_0x020114A4, MBS_ECC1_MBSBS7_0x020114A5,
        MBS_ECC0_MBSBS0_0x0201145E, MBS_ECC0_MBSBS1_0x0201145F };

    Target i_target_centaur;
    rc = fapiGetParentChip(i_target_mba, i_target_centaur);
    if (rc) return rc;

    rc = FAPI_ATTR_GET(ATTR_MCBIST_PATTERN, &i_target_mba, i_mcbpatt);
    if (rc) return rc;//-----------i_mcbpatt------->run
    rc = FAPI_ATTR_GET(ATTR_MCBIST_TEST_TYPE, &i_target_mba, i_mcbtest);
    if (rc) return rc;//---------i_mcbtest------->run

    rc = mss_conversion_testtype(i_target_mba, i_mcbtest, i_mcbtest1);
    if (rc) return rc;
    rc = mss_conversion_data(i_target_mba, i_mcbpatt, i_mcbpatt1);
    if (rc) return rc;

    rc = mcb_reset_trap(i_target_mba);
    if (rc) return rc;
    //shd set attr for this 1st 8 or last 8
    rc = FAPI_ATTR_GET(ATTR_MCBIST_ERROR_CAPTURE, &i_target_mba, l_bit32);
    if (rc) return rc;
    if (l_bit32 == 1)
    {
        FAPI_DBG("%s: error capture set to last 8 Bits", i_target_mba.toEcmdString());
        rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer_64);
        if (rc) return rc;
        rc_num = l_data_buffer_64.setBit(32);
        if (rc_num)
        {
            FAPI_ERR("Error in function  setup_mcbist:");
            rc.setEcmdError(rc_num);
            return rc;
        }

        rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer_64);
        if (rc) return rc;

        rc = fapiGetScom(i_target_centaur, 0x02011774, l_data_buffer_64);
        if (rc) return rc;
        rc_num = l_data_buffer_64.setBit(32);
        if (rc_num)
        {
            FAPI_ERR("Buffer error in function setup_mcbist");
            rc.setEcmdError(rc_num);
            return rc;
        }

        rc = fapiPutScom(i_target_centaur, 0x02011774, l_data_buffer_64);
        if (rc) return rc;
    }

    rc = fapiGetScom(i_target_mba, 0x0301040d, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.clearBit(5);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function setup_mcbist");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target_mba, 0x0301040d, l_data_buffer_64);
    if (rc) return rc;

    //#RRQ FIFO Mode OFF
    rc = fapiGetScom(i_target_mba, 0x0301040e, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.setBit(6);
    rc_num |= l_data_buffer_64.setBit(7);
    rc_num |= l_data_buffer_64.setBit(8);
    rc_num |= l_data_buffer_64.setBit(9);
    rc_num |= l_data_buffer_64.setBit(10);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function setup_mcbist");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target_mba, 0x0301040e, l_data_buffer_64);
    if (rc) return rc;

    //power bus ECC setting for random data
    //# MBA01_MBA_WRD_MODE - disbale powerbus ECC checking and correction
    rc = fapiGetScom(i_target_mba, 0x03010449, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.setBit(0);
    rc_num |= l_data_buffer_64.setBit(1);
    rc_num |= l_data_buffer_64.setBit(5);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function setup_mcbist");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, 0x03010449, l_data_buffer_64);
    if (rc) return rc;
    //# MBS_ECC01_MBSECCQ - set EEC checking On but ECC correction OFF
    rc = fapiGetScom(i_target_centaur, 0x0201144a, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.clearBit(0);
    rc_num |= l_data_buffer_64.setBit(1);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function setup_mcbist");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_centaur, 0x0201144a, l_data_buffer_64);
    if (rc) return rc;

    rc = fapiGetScom(i_target_centaur, 0x0201148a, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.clearBit(0);
    rc_num |= l_data_buffer_64.setBit(1);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function setup_mcbist");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_centaur, 0x0201148a, l_data_buffer_64);
    if (rc) return rc;

    rc = fapiGetScom(i_target_mba, MBA01_CCS_MODEQ_0x030106a7, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.clearBit(29);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function setup_mcbist");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target_mba, MBA01_CCS_MODEQ_0x030106a7, l_data_buffer_64);
    if (rc) return rc;

    for (l_index = 0; l_index < 8; l_index++)
    {
        rc = fapiGetScom(i_target_mba, scom_array[l_index], l_data_buffer_64);
        if (rc) return rc;
        l_flag = (l_data_buffer_64.getDoubleWord(0)) ? 1 : 0;
        if (l_flag == 1)
        {
            break;
        }
    }

    for (l_index = 0; l_index < 16; l_index++)
    {
        rc = fapiGetScom(i_target_centaur, l_scom_array_MBS[l_index], l_data_buffer_64);
        if (rc) return rc;
        l_flag = (l_data_buffer_64.getDoubleWord(0)) ? 1 : 0;
        if (l_flag == 1)
        {
            break;
        }
    }

    if (l_flag == 1)
    {
        FAPI_DBG("%s:WARNING: Bit Steering  is enabled !!!", i_target_mba.toEcmdString());
    }
    else
    {
        FAPI_DBG("%s:steer mode is not enabled", i_target_mba.toEcmdString());
    }

    rc = cfg_mcb_test_mem(i_target_mba, i_mcbtest1, l_sub_info);
    if (rc) return rc;
    rc = cfg_mcb_dgen(i_target_mba, i_mcbpatt1, i_mcbrotate, i_mcbrotdata);
    if (rc) return rc;
    uint8_t i_port = 0;
    uint8_t i_rank = 0;

  FAPI_DBG("%s:DEBUG-----Print----Address Gen ",i_target_mba.toEcmdString());
  rc = FAPI_ATTR_GET(ATTR_MCBIST_ADDR_MODES, &i_target_mba, l_new_addr);
  if (rc) return rc;
  FAPI_DBG("DEBUG----- l_new_addr = %d ",l_new_addr);

    if (l_new_addr != 0)
    {
        rc = address_generation(i_target_mba, i_port, SF, BANK_RANK, i_rank,
                                io_start_address, io_end_address, l_str_cust_addr);
        if (rc)
        {
            FAPI_DBG("%s:BAD - RC ADDR Generation\n", i_target_mba.toEcmdString());
            return rc;
        }
    }
	
 FAPI_INF( "+++ Enabling Refresh +++");

	rc = fapiGetScom(i_target_mba, 0x03010432, l_data_buffer_64);
	if(rc) return rc;
	//Bit 0 is enable		   
	rc_num = rc_num | l_data_buffer_64.setBit(0);
        if(rc_num)
        {
           rc.setEcmdError(rc_num);
           return rc;
        }
	rc = fapiPutScom(i_target_mba, 0x03010432, l_data_buffer_64);
        if(rc)return rc;
        
    if (i_mcbbytemask != NONE)
    {
        rc = cfg_byte_mask(i_target_mba);
        if (rc) return rc;
    }

    return rc;
}

//*****************************************************************/
// Funtion name : mcb_reset_trap
// Description: Clears all the trap registers in MCBIST engine
//Input Parameters :
//     const fapi::Target &            centaur.mba
//*****************************************************************/

fapi::ReturnCode mcb_reset_trap(const fapi::Target & i_target_mba)
{
    ecmdDataBufferBase l_data_buffer_64(64);
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    uint8_t l_mbaPosition = 0;
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbaPosition);

    Target i_target_centaur;
    rc = fapiGetParentChip(i_target_mba, i_target_centaur);
    if (rc) return rc;
    FAPI_DBG("%s:Function - mcb_reset_trap", i_target_mba.toEcmdString());
    //FAPI_DBG("%s:Using MCB Reset Trap Function -- This automatically resets error log RA, error counters, Status Reg and error map",i_target_mba.toEcmdString());
    //Reset the MCBIST runtime counter
    FAPI_DBG("%s:Clearing the MCBIST Runtime Counter ", i_target_mba.toEcmdString());
    rc_num = l_data_buffer_64.flushTo0();
    if (rc_num)
    {
        FAPI_ERR("Error in function  mcb_reset_trap:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiGetScom(i_target_mba, MBA01_MCBIST_RUNTIMECTRQ_0x030106b0, l_data_buffer_64);
    if (rc) return rc;
    rc_num = l_data_buffer_64.clearBit(0, 37);
    if (rc_num)
    {
        FAPI_ERR("Error in function  mcb_reset_trap:");
        rc.setEcmdError(rc_num);
        return rc;
    }
    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_RUNTIMECTRQ_0x030106b0, l_data_buffer_64);
    if (rc) return rc;

    //FAPI_DBG("%s:To clear Port error map registers ",i_target_mba.toEcmdString());
    rc_num = l_data_buffer_64.flushTo0();
    if (rc_num)
    {
        FAPI_ERR("Error in function  mcb_reset_trap:");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMA1Q_0x02011672, l_data_buffer_64);
    if (rc) return (rc);
    rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMB1Q_0x02011673, l_data_buffer_64);
    if (rc) return (rc);
    rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer_64);
    if (rc) return (rc);
    rc = fapiPutScom(i_target_centaur, 0x02011772, l_data_buffer_64);
    if (rc) return (rc);
    rc = fapiPutScom(i_target_centaur, 0x02011773, l_data_buffer_64);
    if (rc) return (rc);
    rc = fapiPutScom(i_target_centaur, 0x02011774, l_data_buffer_64);
    if (rc) return (rc);

    return rc;
}

//*****************************************************************/
// Funtion name : start_mcb
// Description: Checks for dimms drop in the particular port & starts MCBIST
//Input Parameters :
//     const fapi::Target &            Centaur.mba
//*****************************************************************/

fapi::ReturnCode start_mcb(const fapi::Target & i_target_mba)
{
    ecmdDataBufferBase l_data_buffer_64(64);
    ecmdDataBufferBase l_data_buffer_trap_64(64);
    uint8_t l_num_ranks_per_dimm[2][2];
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    FAPI_DBG("%s:Function - start_mcb", i_target_mba.toEcmdString());

    rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBAGRAQ_0x030106d6, l_data_buffer_64);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, l_num_ranks_per_dimm);
    if (rc) return rc;

    if (l_num_ranks_per_dimm[0][0] > 0)
    {
        FAPI_DBG("%s: Socket 0 Configured", i_target_mba.toEcmdString());
        rc_num = l_data_buffer_64.setBit(24);
        rc_num |= l_data_buffer_64.clearBit(25);
        if (rc_num)
        {
            FAPI_ERR("Buffer error in function start_mcb");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    else if (l_num_ranks_per_dimm[0][1] > 0)
    {
        FAPI_DBG("%s: Socket 1 Configured", i_target_mba.toEcmdString());
        rc_num = l_data_buffer_64.clearBit(24);
        rc_num |= l_data_buffer_64.setBit(25);
        if (rc_num)
        {
            FAPI_ERR("Buffer error in function start_mcb");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    else if ((l_num_ranks_per_dimm[0][0] > 0) && (l_num_ranks_per_dimm[0][1] > 0))
    {
        FAPI_DBG("%s: Socket 0, 1 Configured", i_target_mba.toEcmdString());
        rc_num = l_data_buffer_64.setBit(24);
        rc_num |= l_data_buffer_64.setBit(25);
        if (rc_num)
        {
            FAPI_ERR("Buffer error in function start_mcb");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    else
    {
        FAPI_DBG("%s:No Socket found", i_target_mba.toEcmdString());
    }

    //rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES);if(rc) return rc; // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)

    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBAGRAQ_0x030106d6, l_data_buffer_64);
    if (rc) return rc;
    FAPI_DBG("%s:STARTING MCBIST for Centaur Target", i_target_mba.toEcmdString());
    rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc, l_data_buffer_64);
    if (rc) return rc;

    if (l_data_buffer_64.isBitSet(0))
    {
        FAPI_DBG("%s:MCBIST already in progess, wait till MCBIST completes",
                 i_target_mba.toEcmdString());
        return rc;
    }

    rc_num = l_data_buffer_64.flushTo0();
    rc_num |= l_data_buffer_64.setBit(0);
    if (rc_num)
    {
        FAPI_ERR("Buffer error in function start_mcb");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCB_CNTLQ_0x030106db, l_data_buffer_64);
    if (rc) return rc;

    //rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES);if(rc) return rc; // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)

    return rc;
}

//*****************************************************************/
// Funtion name : poll_mcb
// Description  : Will check the MCBIST Configuration Register for mcb fail, in progress
//                fail. It will print the corresponding  centaur on which MCBIST has
//                been completed, in progress or failed.
// Input Parameters :
//    const fapi::Target &             Centaur.mba
//    bool           l_mcb_stop_on_fail       Whether MCBIST should stop on fail or not
//    uint64_t i_time                          Sets the max Time out value
// Output Parameter :
//    uint32    status  = 1                 MCBIST done with fail or MCBIST not complete (default value)
//                      = 0                 MCBIST Done without fail
//****************************************************************/
fapi::ReturnCode poll_mcb(const fapi::Target & i_target_mba,
                          uint8_t *o_mcb_status,
                          struct Subtest_info l_sub_info[30],
                          uint8_t i_flag)
{
    fapi::ReturnCode rc; // return value after each SCOM access/buffer modification
    uint32_t rc_num = 0;
    ecmdDataBufferBase l_data_buffer_64(64);
    ecmdDataBufferBase l_data_buffer1_64(64);
    ecmdDataBufferBase l_data_buffer_trap_64(64);
    ecmdDataBufferBase l_stop_on_fail_buffer_64(64);
    //Current status of the MCB (done, fail, in progress)
    uint8_t l_mcb_done = 0;
    uint8_t l_mcb_fail = 0;
    uint8_t l_mcb_ip = 0;
    //Time out variables
    uint64_t l_mcb_timeout = 0;
    uint32_t l_count = 0;
    uint64_t l_time = 0;
    uint32_t l_time_count = 0;
    uint8_t l_index = 0;
    uint8_t l_Subtest_no = 0;
    uint64_t l_counter = 0x0ll;
    uint32_t i_mcbtest = 0;
    uint32_t l_st_ln = 0;
    uint32_t l_len = 0;
    uint32_t l_dts_0 = 0;
    uint32_t l_dts_1 = 0;
    uint8_t l_mcb_stop_on_fail = 0;
    mcbist_test_mem i_mcbtest1;
    Target i_target_centaur;
    rc = fapiGetParentChip(i_target_mba, i_target_centaur);
    if (rc) return rc;
    // Clear to register to zero;

    //Should get the attributes l_time
    uint8_t test_array_count[44] = { 0, 2, 2, 1, 1, 1, 6, 6, 30, 30,
                                     2, 7, 4, 2, 1, 5, 4, 2, 1, 1,
                                     3, 1, 1, 4, 2, 1, 1, 1, 1, 10,
                                     0, 5, 3, 3, 3, 3, 9, 4, 30, 1,
                                     2, 2, 3, 3 };

    FAPI_DBG("%s:Function Poll_MCBIST", i_target_mba.toEcmdString());
    rc = FAPI_ATTR_GET(ATTR_MCBIST_MAX_TIMEOUT, &i_target_mba, l_time);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MCBIST_STOP_ON_ERROR, &i_target_mba, l_mcb_stop_on_fail);
    if (rc) return rc;

    if (l_time == 0x0000000000000000)
    {
        l_time = MCB_MAX_TIMEOUT;
    }
    FAPI_DBG("%s:Value  of max time %016llX", i_target_mba.toEcmdString(), l_time);

    while ((l_mcb_done == 0) && (l_mcb_timeout <= l_time))
    {
        rc = fapiDelay(DELAY_100US, DELAY_2000SIMCYCLES);
        if (rc) return rc; // wait 2000 simcycles (in sim mode) OR 100 uS (in hw mode)
        rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc, l_data_buffer_64);
        if (rc) return rc;
        if (l_data_buffer_64.isBitSet(0))
        {
            l_time_count++;
            if (l_time_count == 500)
            {
                l_time_count = 0;
                FAPI_DBG("%s:POLLING STATUS:POLLING IN PROGRESS...........",
                         i_target_mba.toEcmdString());
		#ifdef FAPI_MSSLABONLY
		rc = mss_cen_dimm_temp_sensor(i_target_centaur);if (rc) return rc;
		#endif
		rc = fapiGetScom(i_target_centaur, 0x02050000, l_data_buffer_64);if (rc) return rc;
                rc_num = l_data_buffer_64.extractToRight(&l_dts_0, 0, 12);
                rc_num = rc_num | l_data_buffer_64.extractToRight(&l_dts_1, 16, 12);
		if (rc_num)
                {
                     FAPI_ERR("Buffer error in function poll_mcb");
                     rc.setEcmdError(rc_num);
                     return rc;
                 }

                FAPI_DBG("%s:DTS Thermal Sensor 0 Results %d", i_target_centaur.toEcmdString(), l_dts_0);
                FAPI_DBG("%s:DTS Thermal Sensor 1 Results %d", i_target_centaur.toEcmdString(), l_dts_1);
		
                if (i_flag == 0)
                {
                    // Read Counter Reg
                    
                    rc = fapiGetScom(i_target_mba, 0x030106b0, l_data_buffer_64);
                    if (rc) return rc;
                    l_counter = l_data_buffer_64.getDoubleWord (0);
                   
                   FAPI_DBG("%s:MCBCounter  %016llX  ", i_target_mba.toEcmdString(), l_counter);
                    
                    //Read Sub-Test number
                    rc = fapiGetScom(i_target_centaur, 0x02011670, l_data_buffer_64);
                    if (rc) return rc;
                    l_st_ln = 3;
                    l_len = 5;
                    rc_num = l_data_buffer_64.extract(&l_Subtest_no, l_st_ln, l_len);
                    if (rc_num)
                    {
                        FAPI_ERR("Buffer error in function poll_mcb");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                     
                    //FAPI_DBG("%s:SUBTEST No  %08x  ", i_target_mba.toEcmdString(), l_Subtest_no);
                    rc = FAPI_ATTR_GET(ATTR_MCBIST_TEST_TYPE, &i_target_mba, i_mcbtest);
                    if (rc) return rc;//---------i_mcbtest------->run
                    rc = mss_conversion_testtype(i_target_mba, i_mcbtest, i_mcbtest1);
                    if (rc) return rc;

                    //l_Subtest_no = Extracted value from 3 to 7
                    l_index = test_array_count[i_mcbtest];
                    //FAPI_DBG("%s:INDEX No  %d  ",l_index);

                    if (l_Subtest_no < l_index)
                    {
                        switch (l_sub_info[l_Subtest_no].l_operation_type)
                        {
                        case 0:
                            FAPI_DBG("%s:SUBTEST        :WRITE", i_target_mba.toEcmdString());
                            break;
                        case 1:
                            FAPI_DBG("%s:SUBTEST        :READ", i_target_mba.toEcmdString());
                            break;
                        case 2:
                            FAPI_DBG("%s:SUBTEST        :READ - WRITE", i_target_mba.toEcmdString());
                            break;
                        case 3:
                            FAPI_DBG("%s:SUBTEST        :WRITE - READ", i_target_mba.toEcmdString());
                            break;
                        case 4:
                            FAPI_DBG("%s:SUBTEST        :READ - WRITE - READ", i_target_mba.toEcmdString());
                            break;
                        case 5:
                            FAPI_DBG("%s:SUBTEST        :READ - WRITE - WRITE", i_target_mba.toEcmdString());
                            break;
                        case 6:
                            FAPI_DBG("%s:SUBTEST        :RANDOM COMMAND SEQUENCE", i_target_mba.toEcmdString());
                            break;
                        case 7:
                            FAPI_DBG("%s:SUBTEST        :GOTO SUBTEST N OR REFRESH ONLY", i_target_mba.toEcmdString());
                            break;
                        default:
                            FAPI_DBG("%s:Wrong Operation selected for Subtest", i_target_mba.toEcmdString());
                        }

                        switch (l_sub_info[l_Subtest_no].l_data_mode)
                        {
                        case 0:
                            FAPI_DBG("%s:DATA MODE      :FIXED DATA", i_target_mba.toEcmdString());
                            break;
                        case 1:
                            FAPI_DBG("%s:DATA MODE      :DATA_RANDOM_FORWARD", i_target_mba.toEcmdString());
                            break;
                        case 2:
                            FAPI_DBG("%s:DATA MODE      :DATA_RANDOM_REVERSE", i_target_mba.toEcmdString());
                            break;
                        case 3:
                            FAPI_DBG("%s:DATA MODE      :RANDOM w/ECC FORWARD", i_target_mba.toEcmdString());
                            break;
                        case 4:
                            FAPI_DBG("%s:DATA MODE      :RANDOM w/ECC REVERSE", i_target_mba.toEcmdString());
                            break;
                        case 5:
                            FAPI_DBG("%s:DATA MODE      :DATA EQUAL ADDRESS", i_target_mba.toEcmdString());
                            break;
                        case 6:
                            FAPI_DBG("%s:DATA MODE      :DATA ROTATE LEFT", i_target_mba.toEcmdString());
                            break;
                        case 7:
                            FAPI_DBG("%s:DATA MODE      :DATA ROTATE RIGHT", i_target_mba.toEcmdString());
                            break;
                        default:
                            FAPI_DBG("%s:Wrong Data Mode selected for Subtest", i_target_mba.toEcmdString());
                        }

                        switch (l_sub_info[l_Subtest_no].l_addr_mode)
                        {
                        case 0:
                            FAPI_DBG("%s:ADDRESS MODE   :SEQUENTIAL FORWARD", i_target_mba.toEcmdString());
                            break;
                        case 1:
                            FAPI_DBG("%s:ADDRESS MODE   :SEQUENTIAL REVERSE", i_target_mba.toEcmdString());
                            break;
                        case 2:
                            FAPI_DBG("%s:ADDRESS MODE   :RANDOM FORWARD", i_target_mba.toEcmdString());
                            break;
                        case 3:
                            FAPI_DBG("%s:ADDRESS MODE   :RANDOM REVERSE", i_target_mba.toEcmdString());
                            break;
                        default:
                            FAPI_DBG("%s:Wrong Address Mode selected for Subtest", i_target_mba.toEcmdString());
                        }
                    }
                }
            }
            l_mcb_ip = 1;
        }
        if (l_data_buffer_64.isBitSet(1))
        {
            FAPI_DBG("%s:POLLING STATUS:MCBIST POLLING DONE",
                     i_target_mba.toEcmdString());
            FAPI_DBG("%s:MCBIST is done", i_target_mba.toEcmdString());
            l_mcb_ip = 0;
            l_mcb_done = 1;

            rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBCFGQ_0x030106e0, l_data_buffer_trap_64);
            if (rc) return rc;
            rc_num = l_data_buffer_64.clearBit(60);
            if (rc_num)
            {
                FAPI_ERR("Error in function  Poll_mcb:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBCFGQ_0x030106e0, l_data_buffer_trap_64);
            if (rc) return rc;

        }
        if (l_data_buffer_64.isBitSet(2))
        {
            l_mcb_fail = 1;
            FAPI_DBG("%s:POLLING STATUS:MCBIST FAILED", i_target_mba.toEcmdString());

            if (l_mcb_stop_on_fail == 1) //if stop on error is 1, break after the current subtest completes
            {
                rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBCFGQ_0x030106e0, l_stop_on_fail_buffer_64);
                if (rc) return rc;
                rc_num = l_stop_on_fail_buffer_64.setBit(62);
                if (rc_num)
                {
                    FAPI_ERR("Error in function  poll_mcb:");
                    rc.setEcmdError(rc_num);
                    return rc;
                } // Set bit 61 to break after current subtest
                rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBCFGQ_0x030106e0,
                                 l_stop_on_fail_buffer_64);
                if (rc) return rc;
                FAPI_DBG("%s:MCBIST will break after Current Subtest",
                         i_target_mba.toEcmdString());

                while (l_mcb_done == 0) // Poll till MCBIST is done
                {
                    rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCB_CNTLSTATQ_0x030106dc, l_data_buffer_64);
                    if (rc) return rc;
                    if (l_data_buffer_64.isBitSet(1))
                    {
                        l_mcb_ip = 0;
                        l_mcb_done = 1;

                        rc = fapiGetScom(i_target_mba, MBA01_MCBIST_MCBCFGQ_0x030106e0, l_data_buffer_trap_64);
                        if (rc) return rc;
                        rc_num = l_data_buffer_64.clearBit(60);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  Poll_mcb:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                        rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBCFGQ_0x030106e0, l_data_buffer_trap_64);
                        if (rc) return rc;

                        FAPI_DBG("%s:MCBIST Done", i_target_mba.toEcmdString());
                        rc_num = l_stop_on_fail_buffer_64.clearBit(62);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  poll_mcb:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        } // Clearing bit 61 to avoid breaking after current subtest
                        rc = fapiPutScom(i_target_mba, MBA01_MCBIST_MCBCFGQ_0x030106e0, l_stop_on_fail_buffer_64);
                        if (rc) return rc;
                    }
                }
            }
        }
        l_mcb_timeout++;
        if (l_mcb_timeout >= l_time)
        {
            FAPI_ERR("poll_mcb:Maximun time out");
            const fapi::Target & MBA_CHIPLET = i_target_mba;
            FAPI_SET_HWP_ERROR(rc, RC_MSS_MCBIST_TIMEOUT_ERROR);
            return rc;
        }

#ifdef MCB_DEBUG_1
        //if((l_count%100 == 0)&&(l_print == 0))//Can be changed later
        if(l_count%100 == 0)
        {
            FAPI_DBG("%s:MCB done bit : l_mcb_done",i_target_mba.toEcmdString());
            FAPI_DBG("%s:MCB fail bit : l_mcb_fail",i_target_mba.toEcmdString());
            FAPI_DBG("%s:MCB IP   bit : l_mcb_ip",i_target_mba.toEcmdString());
        }
#endif
        l_count++;
    }

    if ((l_mcb_done == 1) && (l_mcb_fail == 1) && (l_mcb_stop_on_fail == true))
    {
        *o_mcb_status = 1; /// MCB fail
#ifdef MCB_DEBUG_2
        FAPI_DBG("%s:*************************************************",i_target_mba.toEcmdString());
        FAPI_DBG("%s:MCB done bit : %d",i_target_mba.toEcmdString(),l_mcb_done);
        FAPI_DBG("%s:MCB fail bit : %d",i_target_mba.toEcmdString(),l_mcb_fail);
        FAPI_DBG("%s:MCB IP   bit : %d",i_target_mba.toEcmdString(),l_mcb_ip);
        FAPI_DBG("%s:*************************************************",i_target_mba.toEcmdString());
#endif
    }
    else if ((l_mcb_done == 1) && (l_mcb_fail == 0))
    {
        *o_mcb_status = 0;//pass;
#ifdef MCB_DEBUG2
        FAPI_DBG("%s:*************************************************",
                 i_target_mba.toEcmdString());
        FAPI_DBG("%s:MCB done bit : %d", i_target_mba.toEcmdString(),
                 l_mcb_done);
        FAPI_DBG("%s:MCB fail bit : %d", i_target_mba.toEcmdString(),
                 l_mcb_fail);
        FAPI_DBG("%s:MCB IP   bit : %d", i_target_mba.toEcmdString(), l_mcb_ip);
        FAPI_DBG("%s:*************************************************",
                 i_target_mba.toEcmdString());
#endif
    }
    else if ((l_mcb_done == 0) && (l_mcb_ip == 1) && (l_mcb_timeout == l_time))
    {
        *o_mcb_status = 1;//fail;
#ifdef MCB_DEBUG2
        FAPI_DBG("%s:****************************************",
                 i_target_mba.toEcmdString());
        FAPI_DBG("%s:MCB done bit : %d", i_target_mba.toEcmdString(),
                 l_mcb_done);
        FAPI_DBG("%s:MCB fail bit : %d", i_target_mba.toEcmdString(),
                 l_mcb_fail);
        FAPI_DBG("%s:MCB IP   bit : %d", i_target_mba.toEcmdString(), l_mcb_ip);
        FAPI_DBG("%s:****************************************",
                 i_target_mba.toEcmdString());

#endif
    }

    if (*o_mcb_status == 1)
    {
        FAPI_DBG("poll_mcb:MCBIST failed");
	return rc;
    }

    return rc;
}
fapi::ReturnCode mcb_error_map_print(const fapi::Target & i_target_mba,
                                     ecmdDataBufferBase & i_mcb_fail_160,
                                     uint8_t i_port,
                                     uint8_t i_array[80],
                                     uint8_t i_number,
                                     ecmdDataBufferBase i_data_buf_port,
                                     ecmdDataBufferBase i_data_buf_spare)
{
    ReturnCode rc;
    uint32_t rc_num=0;
    uint8_t l_num_ranks_per_dimm[MAX_PORT][MAX_PORT];
    uint8_t l_rankpair_table[MAX_RANK];
    uint8_t l_cur_rank = 0;
    uint16_t l_index0, l_index1, l_byte, l_nibble;
    uint8_t l_max_rank = 0;
    uint8_t l_rank_pair = 0;
    char l_str1[200] = "";
    ecmdDataBufferBase l_mcb(64);
    uint8_t i_rank = 0;
    uint8_t l_mbaPosition = 0;
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbaPosition);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba,
                       l_num_ranks_per_dimm);
    if (rc) return rc;
    l_max_rank = l_num_ranks_per_dimm[i_port][0] + l_num_ranks_per_dimm[i_port][1];

    uint64_t l_generic_buffer;
    uint32_t l_sbit, l_len;
    uint16_t l_output;

    rc = mss_getrankpair(i_target_mba, i_port, 0, &l_rank_pair, l_rankpair_table);
    if (rc) return rc;
    if (l_max_rank == 0)
    {
        FAPI_DBG("%s: NO RANK FOUND ON PORT %d ", i_target_mba.toEcmdString(), i_port);
        return rc;
    }
    else
    {
        for (l_cur_rank = 0; l_cur_rank < l_max_rank; l_cur_rank++)
        {
            i_rank = l_rankpair_table[l_cur_rank];
            //FAPI_DBG("%s:i am rank  %d cur_index %d",i_target_mba.toEcmdString(),i_rank,l_cur_rank);
            if (i_rank > MAX_RANK)
            {
                break;
            }
        }
    }

    if (i_port == 0)
    {
        if (l_mbaPosition == 0)
        {
            l_sbit = 0;
            l_len = 16;
            l_generic_buffer = i_data_buf_port.getDoubleWord(0);
            rc_num |= i_data_buf_spare.extractToRight(&l_output, l_sbit, l_len);
            FAPI_DBG("%s:################# MBA01 ###########################\n", i_target_mba.toEcmdString());
            FAPI_DBG("%s:################# PORT0  ERROR MAP #################\n", i_target_mba.toEcmdString());
            FAPI_DBG("%s:Byte      00112233445566778899", i_target_mba.toEcmdString());
            FAPI_DBG("%s:Nibble    01010101010101010101", i_target_mba.toEcmdString());
            FAPI_DBG("%s:MASK      %016llX%04X\n", i_target_mba.toEcmdString(), l_generic_buffer, l_output);
        }
        else
        {
            l_sbit = 0;
            l_len = 16;
            l_generic_buffer = i_data_buf_port.getDoubleWord(0);
            rc_num |= i_data_buf_spare.extractToRight(&l_output, l_sbit, l_len);
            FAPI_DBG("%s:################# MBA23 ###########################\n", i_target_mba.toEcmdString());
            FAPI_DBG("%s:################# PORT0 ERROR MAP #################\n", i_target_mba.toEcmdString());
            FAPI_DBG("%s:Byte      00112233445566778899", i_target_mba.toEcmdString());
            FAPI_DBG("%s:Nibble    01010101010101010101", i_target_mba.toEcmdString());
            FAPI_DBG("%s:MASK      %016llX%04X\n", i_target_mba.toEcmdString(), l_generic_buffer, l_output);
        }
    }
    else
    {
        if (l_mbaPosition == 0)
        {
            l_sbit = 16;
            l_len = 16;
            l_generic_buffer = i_data_buf_port.getDoubleWord(0);
            rc_num |= i_data_buf_spare.extractToRight(&l_output, l_sbit, l_len);
            FAPI_DBG("%s:################# MBA01 ###########################\n", i_target_mba.toEcmdString());
            FAPI_DBG("%s:################# PORT1 ERROR MAP #################\n", i_target_mba.toEcmdString());
            FAPI_DBG("%s:Byte      00112233445566778899", i_target_mba.toEcmdString());
            FAPI_DBG("%s:Nibble    01010101010101010101", i_target_mba.toEcmdString());
            FAPI_DBG("%s:MASK      %016llX%04X\n", i_target_mba.toEcmdString(), l_generic_buffer, l_output);
        }
        else
        {
            l_sbit = 16;
            l_len = 16;
            l_generic_buffer = i_data_buf_port.getDoubleWord(0);
            rc_num = rc_num | i_data_buf_spare.extractToRight(&l_output,
                                                              l_sbit, l_len);
            FAPI_DBG("%s:################# MBA23 ###########################\n", i_target_mba.toEcmdString());
            FAPI_DBG("%s:################# PORT1 ERROR MAP #################\n", i_target_mba.toEcmdString());
            FAPI_DBG("%s:Byte      00112233445566778899", i_target_mba.toEcmdString());
            FAPI_DBG("%s:Nibble    01010101010101010101", i_target_mba.toEcmdString());
            FAPI_DBG("%s:MASK      %016llX%04X\n", i_target_mba.toEcmdString(), l_generic_buffer, l_output);
        }
    }

    uint8_t l_index, l_value, l_value1;
    uint8_t l_marray0[80] = { 0 };
    ecmdDataBufferBase l_data_buffer1_64(64), l_data_buffer3_64(64);

    rc_num |= l_data_buffer1_64.flushTo0();
    //FAPI_ERR("Buffer error in function mcb_error_map_print");
	
	if (rc_num) //The check for if bad rc_num was misplaced
        {
            FAPI_ERR("Error in function  mcb_error_map_print:");
            rc.setEcmdError(rc_num);
            return rc;
        }

    uint8_t l_num, io_num, l_inter, l_num2, l_index2;
    l_num = 0;
    //FAPI_INF("%s:l_max_rank%d",i_target_mba.toEcmdString(),l_max_rank);
    //FAPI_INF("%s:rank:%d",i_target_mba.toEcmdString(),i_rank);
    for (l_index = 0; l_index < i_number; l_index++)
    {
        l_value = i_array[l_index];
        l_inter = (l_value / 4);
        l_num2 = l_num - 1;
        if (l_inter == l_marray0[l_num2] && (l_num != 0))
        {
            continue;
        }

        l_value1 = l_inter;
        l_marray0[l_num] = l_value1;
        l_num++;
        //FAPI_INF("%s:l_value,l_value1,l_num:%d,%d,%d",i_target_mba.toEcmdString(),l_value,l_value1,l_num);
    }

    //FAPI_INF("%s:l_value,l_value1,l_num:%d,%d,%d",i_target_mba.toEcmdString(),l_value,l_value1,l_num);
    io_num = l_num;

    //To be in error map print function

    //Debug Prints
    /*
     uint8_t l_i;
     l_i = 0;


     FAPI_INF("________________________________________________________________________________________________________");
     for(l_i = 0;l_i < i_number;l_i++)
     {
     FAPI_INF("%s:INITIAL ARRAY:%d",i_target_mba.toEcmdString(),i_array[l_i] );
     }
     FAPI_INF("________________________________________________________________________________________________________");
     for(l_i = 0;l_i < io_num;l_i++)
     {
     FAPI_INF("%s:FINAL ARRAY:%d",i_target_mba.toEcmdString(),l_marray0[l_i] );
     }
     FAPI_INF("________________________________________________________________________________________________________");*/

    l_cur_rank = 0;
    i_rank = 0;
    l_num = 0;
    l_value = 0;

    //FAPI_DBG("%s:          --------------------",i_target_mba.toEcmdString());

    rc = mss_getrankpair(i_target_mba, i_port, 0, &l_rank_pair, l_rankpair_table);
    if (rc) return rc;
    for (l_cur_rank = 0; l_cur_rank < l_max_rank; l_cur_rank++)
    {
        l_index2 = 0;
        l_num = 0;
        i_rank = l_rankpair_table[l_cur_rank];
        sprintf(l_str1, "%s:%-4s%d%5s", i_target_mba.toEcmdString(), "RANK", i_rank, "");
        for (l_byte = 0; l_byte < MAX_BYTE; l_byte++)
        {
            for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
            {
                l_value = l_marray0[l_num];
                //FAPI_DBG("%s:l_value %d l_num %d",i_target_mba.toEcmdString(),l_value,l_num);
                l_index0 = (i_rank * 20) + (l_byte * 2) + l_nibble;
                l_index2 = (l_byte * 2) + l_nibble;
                l_index1 = l_index0;
                if ((l_value == l_index2) && (l_num < io_num))
                {
                    strcat(l_str1, "M");
                    //FAPI_DBG("%s:l_value %d l_num %d",i_target_mba.toEcmdString(),l_value,l_num);
                    l_num++;
                }
                else
                {
                    if (i_mcb_fail_160.isBitSet(l_index1))
                    {
                        strcat(l_str1, "X");
                    }
                    else
                    {
                        strcat(l_str1, ".");
                    }
                }
            }
        }
        FAPI_DBG("%s", l_str1);
    }

    return rc;
}

/*****************************************************************/
// Funtion name : mcb_error_map
// Description  : Reads the nibblewise Error map registers into o_error_map
// Input Parameters :
//    const fapi::Target &             Centaur.mba
//    uint8_t i_port                   Current port
//    uint8_t i_rank                   Current Rank
// Output Parameter :
//    uint8_t o_error_map[][8][10][2]   Contains the error map
//****************************************************************/
fapi::ReturnCode mcb_error_map(const fapi::Target & i_target_mba,
                               uint8_t o_error_map[][8][10][2],
                               uint8_t i_CDarray0[80],
                               uint8_t i_CDarray1[80],
                               uint8_t count_bad_dq[2])
{
    ecmdDataBufferBase l_mcbem1ab(64);
    ecmdDataBufferBase l_mcbem2ab(64);
    ecmdDataBufferBase l_mcbem3ab(64);
    ecmdDataBufferBase l_data_buffer_64(64);

    ecmdDataBufferBase l_mcb_fail_320(320);
    ecmdDataBufferBase l_mcb_fail_160(160);
    ecmdDataBufferBase l_mcb_fail1_160(160);
    ecmdDataBufferBase l_mcb(64);
    ecmdDataBufferBase l_ISDIMM_BUF1(64), l_ISDIMM_BUF0(64);
    ecmdDataBufferBase l_ISDIMM_spare1(8), l_ISDIMM_spare0(8);
    uint8_t l_max_rank0, l_max_rank1;

    uint8_t i_rank, i_port;
    fapi::Target i_target_centaur;
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    uint16_t l_index0 = 0;
    uint32_t l_index1 = 0;
    uint8_t l_port = 0;
    uint8_t l_rank = 0;
    uint8_t l_byte = 0;
    uint8_t l_nibble = 0;
    uint8_t l_num_ranks_per_dimm[MAX_PORT][MAX_PORT];
    uint8_t l_mbaPosition = 0;
    uint8_t rank_pair, i_byte, i_nibble, i_input_index_u8, o_val, i_byte1, i_nibble1;

    uint8_t l_index, l_i, l_number, l_value, l_value1, l_number1;//l_cur_rank,
    l_number1 = 0; //HB
    uint8_t l_array[80] = { 0 };
    uint8_t l_marray11[80] = { 0 };
    uint8_t l_array0[80] = { 0 };
    uint8_t l_marray0[80] = { 0 };
    uint8_t l_array1[80] = { 0 };
    uint8_t l_marray1[80] = { 0 };
    uint8_t l_marray[80] = { 0 };
    uint8_t cdimm_dq0[72] = { 0 };
    uint8_t cdimm_dq1[72] = { 0 };
    uint8_t cdimm_dq[80] = { 0 };
    uint8_t l_ISarray1[80] = { 0 };
    uint8_t l_ISarray0[80] = { 0 };
    uint8_t l_ISarray[80] = { 0 };
    uint8_t l_rankpair_table[MAX_RANK];
    ecmdDataBufferBase l_data_buffer1_64(64), l_data_buffer3_64(64),
        l_data_buf_port0(64), l_data_buf_port1(64), l_data_buf_spare(64);
    uint64_t l_generic_buffer0, l_generic_buffer1, l_generic_buffer;
    uint32_t l_sbit, l_len;
    uint8_t l_output0, l_output1, l_output, l_j;

    input_type l_input_type_e = ISDIMM_DQ;
    uint8_t valid_rank[MAX_RANK];
    char l_str[200] = "";
    uint8_t l_max_bytes = 9;
    uint8_t l_max_rank;
    uint8_t l_attr_eff_dimm_type_u8;
    FAPI_DBG("%s:Function MCB_ERROR_MAP", i_target_mba.toEcmdString());

    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbaPosition);
    if (rc)
    {
        FAPI_ERR("Error getting MBA position");
        return rc;
    }

    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba,
                       l_num_ranks_per_dimm);
    if (rc) return rc;

    l_max_rank0 = l_num_ranks_per_dimm[0][0] + l_num_ranks_per_dimm[0][1];
    l_max_rank1 = l_num_ranks_per_dimm[1][0] + l_num_ranks_per_dimm[1][1];

    rc = fapiGetParentChip(i_target_mba, i_target_centaur);
    if (rc)
    {
        FAPI_ERR("Error in getting Parent Chiplet");
        return rc;
    }

    if (l_mbaPosition == 0)
    {
        rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBEMA1Q_0x0201166a, l_mcbem1ab);
        if (rc) return rc;
        rc_num = l_mcb_fail_160.insert(l_mcbem1ab, 0, 60, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBEMA2Q_0x0201166b, l_mcbem2ab);
        if (rc) return rc;
        rc_num = l_mcb_fail_160.insert(l_mcbem2ab, 60, 60, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBEMA3Q_0x0201166c, l_mcbem3ab);
        if (rc) return rc;
        rc_num = l_mcb_fail_160.insert(l_mcbem3ab, 120, 40, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBEMB1Q_0x0201166d, l_mcbem1ab);
        if (rc) return rc;
        rc_num = l_mcb_fail1_160.insert(l_mcbem1ab, 0, 60, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBEMB2Q_0x0201166e, l_mcbem2ab);
        if (rc) return rc;
        rc_num = l_mcb_fail1_160.insert(l_mcbem2ab, 60, 60, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBEMB3Q_0x0201166f, l_mcbem3ab);
        if (rc) return rc;
        rc_num = l_mcb_fail1_160.insert(l_mcbem3ab, 120, 40, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }
    else if (l_mbaPosition == 1)
    {
        rc = fapiGetScom(i_target_centaur, 0x0201176a, l_mcbem1ab);
        if (rc) return rc;
        rc_num = l_mcb_fail_160.insert(l_mcbem1ab, 0, 60, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, 0x0201176b, l_mcbem2ab);
        if (rc) return rc;
        rc_num = l_mcb_fail_160.insert(l_mcbem2ab, 60, 60, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, 0x0201176c, l_mcbem3ab);
        if (rc) return rc;
        rc_num = l_mcb_fail_160.insert(l_mcbem3ab, 120, 40, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, 0x0201176d, l_mcbem1ab);
        if (rc) return rc;
        rc_num = l_mcb_fail1_160.insert(l_mcbem1ab, 0, 60, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, 0x0201176e, l_mcbem2ab);
        if (rc) return rc;
        rc_num = l_mcb_fail1_160.insert(l_mcbem2ab, 60, 60, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        rc = fapiGetScom(i_target_centaur, 0x0201176f, l_mcbem3ab);
        if (rc) return rc;
        rc_num = l_mcb_fail1_160.insert(l_mcbem3ab, 120, 40, 0);
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_error_map:");
            rc.setEcmdError(rc_num);
            return rc;
        }
    }

    for (l_port = 0; l_port < MAX_PORT; l_port++)
    {
        rc = mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, valid_rank);
        if (rc) return rc;

        if (l_port == 0)
        {
            l_max_rank = l_max_rank0;
        }
        else
        {
            l_max_rank = l_max_rank1;
        }

        for (l_rank = 0; l_rank < l_max_rank; l_rank++)
        {
            i_rank = valid_rank[l_rank];

            for (l_byte = 0; l_byte < MAX_BYTE; l_byte++)
            {
                for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                {
                    if (l_port == 0)
                    {
                        l_index0 = (i_rank * 20) + (l_byte * 2) + l_nibble;
                        l_index1 = l_index0;

                        if ((l_mcb_fail_160.isBitSet(l_index1)))
                        {
                            o_error_map[l_port][i_rank][l_byte][l_nibble] = 1;
                        }
                        else
                        {
                            o_error_map[l_port][i_rank][l_byte][l_nibble] = 0;
                        }
                    }
                    else if (l_port == 1)
                    {

                        l_index0 = (i_rank * 20) + (l_byte * 2) + l_nibble;
                        l_index1 = l_index0;
                        if ((l_mcb_fail1_160.isBitSet(l_index1)))
                        {

                            o_error_map[l_port][i_rank][l_byte][l_nibble] = 1;
                        }
                        else
                        {
                            o_error_map[l_port][i_rank][l_byte][l_nibble] = 0;
                        }
                    }
                }
            }
        }
    }

    rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_attr_eff_dimm_type_u8);
    if (rc) return rc;

    l_i = 0;
    rc_num = l_data_buffer1_64.flushTo0();
    i_port = 0;

    while (i_port < 2)
    {
        rc_num = l_data_buffer1_64.flushTo0();
        rc_num = l_data_buffer3_64.flushTo0();
        if (l_mbaPosition == 0)
        {
            if (i_port == 0)
            {
                //FAPI_INF("l_array:%d",l_i);
                l_i = 0;
                rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMA1Q_0x02011672, l_data_buf_port0);
                if (rc)
                    return rc;
                rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buf_spare);
                if (rc) return rc;
                for (l_index = 0; l_index < 64; l_index++)
                {
                    if (l_data_buf_port0.isBitSet(l_index))
                    {
                        l_array0[l_i] = l_index;
                        l_i++;
                        //FAPI_INF("l_array:%d",l_i);
                    }
                }
                for (l_index = 0; l_index < 16; l_index++)
                {
                    if (l_data_buf_spare.isBitSet(l_index))
                    {
                        l_array0[l_i] = l_index + 64;
                        l_i++;
                        //FAPI_INF("l_array:%d",l_i);
                    }
                }
                l_number1 = l_i;
            }

            else
            {
                //FAPI_INF("l_array:%d",l_i);
                l_i = 0;
                rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMB1Q_0x02011673, l_data_buf_port1);
                if (rc) return rc;
                rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buf_spare);
                if (rc) return rc;
                for (l_index = 0; l_index < 64; l_index++)
                {
                    if (l_data_buf_port1.isBitSet(l_index))
                    {
                        l_array1[l_i] = l_index;
                        l_i++;//FAPI_INF("l_array:%d",l_i);
                    }
                }
                for (l_index = 16; l_index < 32; l_index++)
                {
                    if (l_data_buf_spare.isBitSet(l_index))
                    {
                        l_array1[l_i] = l_index + 64 - 16;
                        l_i++;//FAPI_INF("l_array:%d",l_i);
                    }
                }
                l_number = l_i;
            }
        }
        else
        {
            if (i_port == 0)
            {
                //FAPI_INF("l_array:%d",l_i);
                l_i = 0;
                rc = fapiGetScom(i_target_centaur, 0x02011774, l_data_buf_spare);
                if (rc) return rc;
                rc = fapiGetScom(i_target_centaur, 0x02011772, l_data_buf_port0);
                if (rc) return rc;
                for (l_index = 0; l_index < 64; l_index++)
                {
                    if (l_data_buf_port0.isBitSet(l_index))
                    {
                        l_array0[l_i] = l_index;
                        l_i++;//FAPI_INF("l_array:%d",l_i);
                    }
                }
                for (l_index = 0; l_index < 16; l_index++)
                {
                    if (l_data_buf_spare.isBitSet(l_index))
                    {
                        l_array0[l_i] = l_index + 64;
                        l_i++;//FAPI_INF("l_array:%d",l_i);
                    }
                }
                l_number1 = l_i;
            }
            else
            {
                l_i = 0;
                //FAPI_INF("l_array:%d",l_i);
                rc = fapiGetScom(i_target_centaur, 0x02011774, l_data_buf_spare);
                if (rc) return rc;
                rc = fapiGetScom(i_target_centaur, 0x02011773, l_data_buf_port1);
                if (rc) return rc;
                for (l_index = 0; l_index < 64; l_index++)
                {
                    if (l_data_buf_port1.isBitSet(l_index))
                    {
                        l_array1[l_i] = l_index;
                        l_i++;//FAPI_INF("l_array:%d",l_i);
                    }
                }
                for (l_index = 16; l_index < 32; l_index++)
                {
                    if (l_data_buf_spare.isBitSet(l_index))
                    {
                        l_array1[l_i] = l_index + 64 - 16;
                        l_i++;//FAPI_INF("l_array:%d",l_i);
                    }
                }
                l_number = l_i;
            }
        }
        i_port++;
    }

    //Conversion from CDIMM larray to ISDIMM larray
    //port 0
    for (l_i = 0; l_i < MAX_ISDIMM_DQ; l_i++)
    {
        rc = rosetta_map(i_target_mba, 0, l_input_type_e, l_i, 0, o_val);
        if (rc) return rc;
        cdimm_dq0[o_val] = l_i;
    }

    //port 1
    for (l_i = 0; l_i < MAX_ISDIMM_DQ; l_i++)
    {
        rc = rosetta_map(i_target_mba, 1, l_input_type_e, l_i, 0, o_val);
        if (rc) return rc;
        cdimm_dq1[o_val] = l_i;
    }

    uint8_t l_num, io_num, io_num0, io_num1, l_inter, l_flag, l_n;
    l_n = 0;
    io_num0 = 0;
    io_num1 = 0;

    //FAPI_INF("%s:l_max_rank%d",i_target_mba.toEcmdString(),l_max_rank);
    l_port = 0;
    while (l_port < 2)
    {
        l_num = 0;
        if (l_port == 0)
        {
            for (l_index = 0; l_index < l_number1; l_index++)
            {
                l_array[l_index] = l_array0[l_index];
            }
            l_n = l_number1;
            rc = mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, l_rankpair_table);
            if (rc) return rc;

            for (l_i = 0; l_i < MAX_ISDIMM_DQ; l_i++)
            {
                cdimm_dq[l_i] = cdimm_dq0[l_i];
            }
        }
        else
        {
            for (l_index = 0; l_index < l_number; l_index++)
            {
                l_array[l_index] = l_array1[l_index];
                l_n = l_number;
            }
            rc = mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, l_rankpair_table);
            if (rc) return rc;

            for (l_i = 0; l_i < MAX_ISDIMM_DQ; l_i++)
            {
                cdimm_dq[l_i] = cdimm_dq1[l_i];
            }
        }
        //Getting array for converting CDIMM values as index and ISDIMM values as value of array for that index
        for (l_index = 0; l_index < l_n; l_index++)
        {
            l_value = l_array[l_index];

            l_value1 = cdimm_dq[l_value];
            if (l_value >= 72)
            {
                l_value1 = 255;
            }

            l_ISarray[l_index] = l_value1;
            //FAPI_INF("L_ISARRAY port %d index %d  value %d ",l_port,l_index,l_ISarray[l_index]);
        }

        if (l_attr_eff_dimm_type_u8 != ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
        {
            //For ISDIMM marray
            for (l_index = 0; l_index < l_n; l_index++)
            {
                l_value = l_ISarray[l_index];
                l_inter = (l_value / 4);
                l_value1 = l_num - 1;
                l_marray[l_num] = l_inter * 4;
                l_num++;
                //FAPI_INF("%s:l_value,l_value1,l_num:%d,%d,%d",i_target_mba.toEcmdString(),l_value,l_value1,l_num);
            }
        }
        else
        {
            //For CDIMM marray
            for (l_index = 0; l_index < l_n; l_index++)
            {
                l_value = l_array[l_index];
                l_inter = (l_value / 4);
                l_value1 = l_num - 1;
                l_marray[l_num] = l_inter * 4;
                l_num++;
                //FAPI_INF("%s:l_value,l_value1,l_num:%d,%d,%d",i_target_mba.toEcmdString(),l_value,l_value1,l_num);
            }
        }

        //Loop to sort Masked ISDIMM array
        for (l_i = 0; l_i < l_num - 1; l_i++)
        {
            for (l_j = l_i + 1; l_j < l_num; l_j++)
            {
                if (l_marray[l_i] > l_marray[l_j])
                {
                    l_value = l_marray[l_j];
                    l_marray[l_j] = l_marray[l_i];
                    l_marray[l_i] = l_value;
                    //FAPI_INF("port %d value %d index %d",l_port,l_marray[l_i],l_i);
                }
            }
        }

        //loop to remove repetition elements
        l_j = 0;
        for (l_i = 0; l_i < l_num; l_i++)
        {
            l_flag = 0;

            if ((l_marray[l_i] == l_marray[l_i + 1]) && (l_num != 0))
            {
                l_flag = 1;
            }

            if (l_flag == 0)
            {
                l_marray11[l_j] = l_marray[l_i];
                l_j++;
            }
        }
        l_num = l_j;

        if (l_port == 0)
        {
            io_num0 = l_num;
            if (io_num0 >= 21)
            {
                io_num0 = 21;
            }
            for (l_index = 0; l_index < io_num0; l_index++)
            {
                l_marray0[l_index] = l_marray11[l_index];
            }

            for (l_index = 0; l_index < l_number1; l_index++)
            {

                l_ISarray0[l_index] = l_ISarray[l_index];
            }
        }
        else
        {
            io_num1 = l_num;
            if (io_num1 >= 21)
            {
                io_num1 = 21;
            }
            for (l_index = 0; l_index < io_num1; l_index++)
            {
                l_marray1[l_index] = l_marray11[l_index];
            }
            for (l_index = 0; l_index < l_number; l_index++)
            {

                l_ISarray1[l_index] = l_ISarray[l_index];
            }
        }
        l_port++;
    }

    count_bad_dq[0] = l_number1;
    count_bad_dq[1] = l_number;
    // FAPI_INF("\n abhijit's number is  number=%d and %d \n",count_bad_dq[0],count_bad_dq[1]);
    for (l_i = 0; l_i < l_number1; l_i++)
    {
        i_CDarray0[l_i] = l_array0[l_i];
    }
    for (l_i = 0; l_i < l_number; l_i++)
    {
        i_CDarray1[l_i] = l_array1[l_i];
    }

    if(l_attr_eff_dimm_type_u8 != fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)  //Calling ISDIMM error mAP and LRDIMM
    {
        FAPI_DBG("%s:#################  Error MAP for ISDIMM #################",
                 i_target_mba.toEcmdString());
        for (l_port = 0; l_port < 2; l_port++)
        {
            if (l_port == 0)
            {
                l_max_rank = l_max_rank0;

                io_num = io_num0;
                for (l_index = 0; l_index < io_num; l_index++)
                {
                    l_marray[l_index] = l_marray0[l_index];
                }
            }
            else
            {
                l_max_rank = l_max_rank1;

                io_num = io_num1;
                for (l_index = 0; l_index < io_num; l_index++)
                {
                    l_marray[l_index] = l_marray1[l_index];
                }
            }

            if (l_max_rank == 0)
            {
                FAPI_DBG("%s: NO RANKS FOUND ON  PORT  %d", i_target_mba.toEcmdString(), l_port);
            }
            else
            {
                //To set the mask print in error map
                l_value = 0;
                if (l_port == 0)
                {
                    //For Port 0
                    for (l_index = 0; l_index < l_number1; l_index++)
                    {
                        l_flag = 0;
                        l_value = l_ISarray0[l_index];
                        //FAPI_INF("Value is %d for index %d", l_value,l_index);
                        if (l_value >= 72)
                        {
                            l_flag = 1;
                            //FAPI_INF("Value (72)is here for index %d",l_index);
                        }
                        if ((l_value >= 64) && (l_value < 72))
                        {
                            l_value1 = l_value - 64;
                            l_flag = 2;
                            //FAPI_INF("Value (64)is here for index %d,l_value1 %d",l_index,l_value1);
                            rc_num = l_ISDIMM_spare0.setBit(l_value1);
                            if (rc_num)
                            {
                                FAPI_ERR("Error in function  Error Map:");
                                rc.setEcmdError(rc_num);
                                return rc;
                            }
                        }
                        if (l_flag == 0)
                        {
                            rc_num = l_ISDIMM_BUF0.setBit(l_value);
                            if (rc_num)
                            {
                                FAPI_ERR("Error in function  Error Map:");
                                rc.setEcmdError(rc_num);
                                return rc;
                            }
                        }
                        //FAPI_INF("VALUE OF FLAG %d",l_flag);
                    }

                    l_generic_buffer0 = 0;
                    l_output0 = 0;
                    l_generic_buffer0 = l_ISDIMM_BUF0.getDoubleWord(0);
                    l_sbit = 0;
                    l_len = 8;
                    rc_num |= l_ISDIMM_spare0.extractToRight(&l_output0, l_sbit, l_len);
                    //FAPI_DBG("%s:MASK      %016llX%02X\n",i_target_mba.toEcmdString(),l_generic_buffer0,l_output0);
                    l_generic_buffer = l_generic_buffer0;
                    l_output = l_output0;
                }
                else
                {
                    for (l_index = 0; l_index < l_number; l_index++)
                    {
                        l_flag = 0;
                        l_value = l_ISarray1[l_index];
                        //FAPI_INF("Value is %d for index %d", l_value,l_index);
                        if (l_value >= 72)
                        {
                            l_flag = 1;
                            //FAPI_INF("Value (72)is here for index %d",l_index);
                        }
                        if ((l_value >= 64) && (l_value < 72))
                        {
                            l_value1 = l_value - 64;
                            l_flag = 2;
                            //FAPI_INF("Value (64)is here for index %d,l_value1 %d",l_index,l_value1);
                            rc_num = l_ISDIMM_spare1.setBit(l_value1);
                            if (rc_num)
                            {
                                FAPI_ERR("Error in function  Error Map:");
                                rc.setEcmdError(rc_num);
                                return rc;
                            }
                        }
                        if (l_flag == 0)
                        {
                            rc_num = l_ISDIMM_BUF1.setBit(l_value);
                            if (rc_num)
                            {
                                FAPI_ERR("Error in function  Error Map:");
                                rc.setEcmdError(rc_num);
                                return rc;
                            }
                        }
                        //FAPI_INF("VALUE OF FLAG %d",l_flag);
                    }

                    l_generic_buffer1 = 0;
                    l_output1 = 0;
                    l_generic_buffer1 = l_ISDIMM_BUF1.getDoubleWord(0);
                    l_sbit = 0;
                    l_len = 8;
                    rc_num |= l_ISDIMM_spare1.extractToRight(&l_output1, l_sbit, l_len);
                    //FAPI_DBG("%s:MASK      %016llX%02X\n",i_target_mba.toEcmdString(),l_generic_buffer1,l_output1);
                    l_generic_buffer = l_generic_buffer1;
                    l_output = l_output1;
                }

                //Mask calculation Ends

                if (l_mbaPosition == 0)
                {
                    //FAPI_DBG("%s:MASK      %016llX%02X\n",i_target_mba.toEcmdString(),l_generic_buffer0,l_output0);
                    FAPI_DBG("%s:################# MBA01 ###########################\n", i_target_mba.toEcmdString());
                    FAPI_DBG("%s:################# PORT%d ERROR MAP #################\n", i_target_mba.toEcmdString(), l_port);
                    FAPI_DBG("%s:Byte      001122334455667788", i_target_mba.toEcmdString());
                    FAPI_DBG("%s:Nibble    010101010101010101", i_target_mba.toEcmdString());
                    FAPI_DBG("%s:MASK      %016llX%02X\n", i_target_mba.toEcmdString(), l_generic_buffer, l_output);
                }
                else
                {
                    //FAPI_DBG("%s:MASK      %016llX%02X\n",i_target_mba.toEcmdString(),l_generic_buffer1,l_output1);
                    FAPI_DBG("%s:################# MBA23 ###########################\n", i_target_mba.toEcmdString());
                    FAPI_DBG(
                             "%s:################# PORT%d ERROR MAP #################\n",i_target_mba.toEcmdString(), l_port);
                    FAPI_DBG("%s:Byte      001122334455667788", i_target_mba.toEcmdString());
                    FAPI_DBG("%s:Nibble    010101010101010101", i_target_mba.toEcmdString());
                    FAPI_DBG("%s:MASK      %016llX%02X\n", i_target_mba.toEcmdString(), l_generic_buffer, l_output);
                }

                for (l_rank = 0; l_rank < l_max_rank; l_rank++)
                {
                    l_num = 0;
                    rc = mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, valid_rank);
                    if (rc) return rc;
                    i_rank = valid_rank[l_rank];
                    sprintf(l_str, "%s:%-4s%d%5s", i_target_mba.toEcmdString(), "RANK", i_rank, "");
                    l_flag = 0;
                    for (i_byte = 0; i_byte < l_max_bytes; i_byte++)
                    {
                        for (i_nibble = 0; i_nibble < 2; i_nibble++)
                        {
                            l_flag = 0;
                            l_inter = l_marray[l_num];

                            i_input_index_u8 = (8 * i_byte) + (4 * i_nibble);

                            if ((l_inter == i_input_index_u8) && (l_num < io_num))
                            {
                                //FAPI_INF("l_flag %d,l_inter %d,i_input_index_u8 %d",l_flag,l_inter,i_input_index_u8);
                                l_num++;
                                l_flag = 1;
                            }

                            //FAPI_INF("l_flag %d,l_inter %d,i_input_index_u8 %d",l_flag,l_inter,i_input_index_u8);
                            rc = rosetta_map(i_target_mba, l_port,
                                             l_input_type_e, i_input_index_u8,
                                             0, o_val);
                            if (rc) return rc;
                            i_byte1 = o_val / 8;
                            i_nibble1 = o_val % 8;
                            if (i_nibble1 > 3)
                            {
                                i_nibble1 = 1;
                            }
                            else
                            {
                                i_nibble1 = 0;
                            }
                            if (l_flag == 1)
                            {
                                strcat(l_str, "M");
                            }
                            else
                            {
                                if (o_error_map[l_port][i_rank][i_byte1][i_nibble1] == 1)
                                {
                                    strcat(l_str, "X");
                                }
                                else
                                {
                                    strcat(l_str, ".");
                                }
                            }
                        }
                    }
                    FAPI_DBG("%s", l_str);
                }
            }
        }
    }

    else //Calling CDIMM error Map print
    {
        FAPI_DBG("%s:################# CDIMM ERROR MAP ###########################\n", i_target_mba.toEcmdString());
        i_port = 0;
        mcb_error_map_print(i_target_mba, l_mcb_fail_160, i_port, l_array0,
                            l_number1, l_data_buf_port0, l_data_buf_spare);

        i_port = 1;
        mcb_error_map_print(i_target_mba, l_mcb_fail1_160, i_port, l_array1,
                            l_number, l_data_buf_port1, l_data_buf_spare);
    }

    return rc;
}

/*****************************************************************/
// Funtion name : mcb_write_test_mem
// Description  :   : Based on parameters passed we write data into Register being passed
// Input Parameters :
//    const fapi::Target &                     Centaur.mba
//    const uint64_t i_reg_addr                 Register address
//    mcbist_oper_type i_operation_type         Operation Type
//    mcbist_addr_mode i_addr_mode              Sequential or Random address modes
//    mcbist_data_mode i_data_mode              Data Mode
//    uint8_t i_done                               Done Bit
//   mcbist_data_select_mode i_data_select_mode Different BURST modes or DEFAULT
//    mcbist_add_select_mode i_addr_select_mode Address Select mode
//    uint8_t i_testnumber                      Subtest number
//    uint8_t i_cfg_test_123_cmd                Integer value

//****************************************************************/
fapi::ReturnCode mcb_write_test_mem(const fapi::Target & i_target_mba,
                                    const uint64_t i_reg_addr,
                                    mcbist_oper_type i_operation_type,
                                    uint8_t i_cfg_test_123_cmd,
                                    mcbist_addr_mode i_addr_mode,
                                    mcbist_data_mode i_data_mode,
                                    uint8_t i_done,
                                    mcbist_data_select_mode i_data_select_mode,
                                    mcbist_add_select_mode i_addr_select_mode,
                                    uint8_t i_testnumber,
                                    uint8_t i_testnumber1,
                                    uint8_t total_subtest_no,
                                    struct Subtest_info l_sub_info[30])
{
    fapi::ReturnCode rc;
    uint32_t rc_num = 0;
    uint8_t l_index = 0;
    uint8_t l_operation_type = i_operation_type;
    uint8_t l_cfg_test_123_cmd = i_cfg_test_123_cmd;
    uint8_t l_addr_mode = i_addr_mode;
    uint8_t l_data_mode = i_data_mode;
    uint8_t l_data_select_mode = i_data_select_mode;
    uint8_t l_addr_select_mode = i_addr_select_mode;
    ecmdDataBufferBase l_data_buffer_64(64);

    FAPI_DBG("%s:Function mcb_write_test_mem", i_target_mba.toEcmdString());
    rc = fapiGetScom(i_target_mba, i_reg_addr, l_data_buffer_64);
    if (rc) return rc;
    l_index = i_testnumber * (MCB_TEST_NUM);

    uint8_t l_done_bit;
    rc = FAPI_ATTR_GET(ATTR_MCBIST_ADDR_BANK, &i_target_mba, l_done_bit);
    if (rc) return rc;
    if (l_done_bit == 1)
    {
        return rc;
    }

    l_sub_info[i_testnumber1].l_operation_type = l_operation_type;
    l_sub_info[i_testnumber1].l_data_mode = l_data_mode;
    l_sub_info[i_testnumber1].l_addr_mode = l_addr_mode;

    // Operation type
    rc_num |= l_data_buffer_64.insertFromRight(l_operation_type, l_index, 3);
    rc_num |= l_data_buffer_64.insertFromRight(l_cfg_test_123_cmd, l_index + 3, 3);
    // ADDR MODE
    rc_num |=  l_data_buffer_64.insertFromRight(l_addr_mode, l_index + 6, 2);
    // DATA MODE
    rc_num |= l_data_buffer_64.insertFromRight(l_data_mode, l_index + 8, 3);
    // Done bit
    rc_num |=  l_data_buffer_64.insertFromRight(i_done, l_index + 11, 1);
    // Data Select Mode
    rc_num |= l_data_buffer_64.insertFromRight(l_data_select_mode, l_index + 12, 2);

    // Address Select mode
    rc_num |= l_data_buffer_64.insertFromRight(l_addr_select_mode, l_index + 14, 2);

    if (rc_num)
    {
        FAPI_ERR("Error in function  mcb_write_test_mem:");
        rc.setEcmdError(rc_num);
        return rc;
    }

    rc = fapiPutScom(i_target_mba, i_reg_addr, l_data_buffer_64);
    if (rc) return rc;
    rc = fapiGetScom(i_target_mba, i_reg_addr, l_data_buffer_64);
    if (rc) return rc;

    FAPI_DBG("%s:SUBTEST %d of %d in Progress.................... ",
             i_target_mba.toEcmdString(), i_testnumber1, total_subtest_no);
    //FAPI_DBG("%s:SUBTEST %d  in Progress.................... ",i_testnumber);
    FAPI_DBG("%s:SUBTEST DETAILS", i_target_mba.toEcmdString());

    switch (l_operation_type)
    {
    case 0:
        FAPI_DBG("%s:SUBTEST        :WRITE", i_target_mba.toEcmdString());
        break;
    case 1:
        FAPI_DBG("%s:SUBTEST        :READ", i_target_mba.toEcmdString());
        break;
    case 2:
        FAPI_DBG("%s:SUBTEST        :READ - WRITE", i_target_mba.toEcmdString());
        break;
    case 3:
        FAPI_DBG("%s:SUBTEST        :WRITE - READ", i_target_mba.toEcmdString());
        break;
    case 4:
        FAPI_DBG("%s:SUBTEST        :READ - WRITE - READ", i_target_mba.toEcmdString());
        break;
    case 5:
        FAPI_DBG("%s:SUBTEST        :READ - WRITE - WRITE", i_target_mba.toEcmdString());
        break;
    case 6:
        FAPI_DBG("%s:SUBTEST        :RANDOM COMMAND SEQUENCE", i_target_mba.toEcmdString());
        break;
    case 7:
        FAPI_DBG("%s:SUBTEST        :GOTO SUBTEST N OR REFRESH ONLY", i_target_mba.toEcmdString());
        break;
    default:
        FAPI_DBG("%s:Wrong Operation selected for Subtest", i_target_mba.toEcmdString());
    }

    switch (l_data_mode)
    {
    case 0:
        FAPI_DBG("%s:DATA MODE      :FIXED DATA", i_target_mba.toEcmdString());
        break;
    case 1:
        FAPI_DBG("%s:DATA MODE      :DATA_RANDOM_FORWARD", i_target_mba.toEcmdString());
        break;
    case 2:
        FAPI_DBG("%s:DATA MODE      :DATA_RANDOM_REVERSE", i_target_mba.toEcmdString());
        break;
    case 3:
        FAPI_DBG("%s:DATA MODE      :RANDOM w/ECC FORWARD", i_target_mba.toEcmdString());
        break;
    case 4:
        FAPI_DBG("%s:DATA MODE      :RANDOM w/ECC REVERSE", i_target_mba.toEcmdString());
        break;
    case 5:
        FAPI_DBG("%s:DATA MODE      :DATA EQUAL ADDRESS", i_target_mba.toEcmdString());
        break;
    case 6:
        FAPI_DBG("%s:DATA MODE      :DATA ROTATE LEFT", i_target_mba.toEcmdString());
        break;
    case 7:
        FAPI_DBG("%s:DATA MODE      :DATA ROTATE RIGHT", i_target_mba.toEcmdString());
        break;
    default:
        FAPI_DBG("%s:Wrong Data Mode selected for Subtest", i_target_mba.toEcmdString());
    }

    switch (l_addr_mode)
    {
    case 0:
        FAPI_DBG("%s:ADDRESS MODE   :SEQUENTIAL FORWARD", i_target_mba.toEcmdString());
        break;
    case 1:
        FAPI_DBG("%s:ADDRESS MODE   :SEQUENTIAL REVERSE", i_target_mba.toEcmdString());
        break;
    case 2:
        FAPI_DBG("%s:ADDRESS MODE   :RANDOM FORWARD", i_target_mba.toEcmdString());
        break;
    case 3:
        FAPI_DBG("%s:ADDRESS MODE   :RANDOM REVERSE", i_target_mba.toEcmdString());
        break;
    default:
        FAPI_DBG("%s:Wrong Address Mode selected for Subtest", i_target_mba.toEcmdString());
    }

    FAPI_DBG("%s:SUBTEST %d of %d done ", i_target_mba.toEcmdString(),
             i_testnumber1, total_subtest_no);

    if (i_done == 1)
    {
        FAPI_DBG("%s:DONE BIT IS SET FOR CURRENT SUBTEST %d",
                 i_target_mba.toEcmdString(), i_testnumber1);
        //FAPI_DBG("%s:DONE BIT IS SET FOR CURRENT SUBTEST %d",i_testnumber);
    }
    if ((l_data_mode == 0) || (l_data_mode == 6) || (l_data_mode == 7)|| (l_data_mode == 5))
    {
        //FAPI_DBG("%s:fixed set and value of datamode is %d",l_data_mode);
        l_sub_info[i_testnumber1].l_fixed_data_enable = 1;
    }
    else if ((l_data_mode == 1) || (l_data_mode == 2) || (l_data_mode == 3) || (l_data_mode == 4))
    {
        l_sub_info[i_testnumber1].l_random_data_enable = 1;
        //FAPI_DBG("%s:random set and value of datamode is %d",l_data_mode);
    }

    if ((l_addr_mode == 0) || (l_addr_mode == 1))
    {
        //FAPI_DBG("fixed addr and value of addrmode is %d",l_addr_mode);
        l_sub_info[i_testnumber1].l_fixed_addr_enable = 1;
    }
    else if ((l_addr_mode == 2) || (l_addr_mode == 3))
    {
        l_sub_info[i_testnumber1].l_random_addr_enable = 1;
        //FAPI_DBG("random addr and value of addrmode is %d",l_addr_mode);
    }
    return rc;
}

/*****************************************************************/
// Funtion name : cfg_byte_mask
// Description  :
// Input Parameters :  It is used to mask bad bits read from SPD
//    const fapi::Target &                     Centaur.mba
//    uint8_t i_rank                            Current Rank
//    uint8_t i_port                            Current Port
//****************************************************************/

fapi::ReturnCode cfg_byte_mask(const fapi::Target & i_target_mba)
{
    uint32_t rc_num;
    uint8_t l_port = 0;
    uint8_t l_dimm = 0;
    uint8_t l_rank = 0;
    uint8_t l_max_0 = 0;
    uint8_t l_max_1 = 0;
    fapi::ReturnCode rc;
    uint8_t l_rnk = 0;
    uint8_t num_ranks_per_dimm[2][2];
    uint8_t l_MAX_RANKS = 8;
    uint8_t rank_pair = 0;
    uint64_t l_var = 0xFFFFFFFFFFFFFFFFull;
    uint16_t l_spare = 0xFFFF;
    ecmdDataBufferBase l_data_buffer1_64(64);
    Target i_target_centaur;
    rc = fapiGetParentChip(i_target_mba, i_target_centaur);
    if (rc) return rc;
    uint8_t valid_rank[l_MAX_RANKS];
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, num_ranks_per_dimm);
    if (rc) return rc;
    uint8_t l_mbaPosition = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target_mba, l_attr_eff_dimm_type_u8);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_mba, l_mbaPosition);
    if (rc) return rc;

    for (l_port = 0; l_port < 2; l_port++)
    {
        l_MAX_RANKS = num_ranks_per_dimm[l_port][0] + num_ranks_per_dimm[l_port][1];
        rc = mss_getrankpair(i_target_mba, l_port, 0, &rank_pair, valid_rank);
        if (rc) return rc;

        for (l_rank = 0; l_rank < l_MAX_RANKS; l_rank++)
        {
            l_rnk = valid_rank[l_rank];
            if (l_rnk == 255)
            {
                continue;
            }

            ecmdDataBufferBase l_data_buffer2_64(64);
            ecmdDataBufferBase l_data_buffer3_64(64);
            ecmdDataBufferBase l_data_buffer4_64(64);
            ecmdDataBufferBase l_data_buffer5_64(64);

            l_max_0 = num_ranks_per_dimm[0][0] + num_ranks_per_dimm[0][1];
            l_max_1 = num_ranks_per_dimm[1][0] + num_ranks_per_dimm[1][1];

            rc_num = l_data_buffer3_64.flushTo0();
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE];
            uint8_t l_dq[8] = { 0 };
            uint8_t l_sp[2] = { 0 };
            uint16_t l_index0 = 0;
            uint8_t l_index_sp = 0;
            uint16_t l_sp_isdimm = 0xff;

            FAPI_DBG("%s:Function cfg_byte_mask", i_target_mba.toEcmdString());
            if (l_rnk > 3)
            {
                l_dimm = 1;
                l_rnk = l_rnk - 4;
            }
            else
            {
                l_dimm = 0;
            }
            rc = dimmGetBadDqBitmap(i_target_mba, l_port, l_dimm, l_rnk, l_dqBitmap);
            if (rc) return rc;

            for (l_index0 = 0; l_index0 < DIMM_DQ_RANK_BITMAP_SIZE; l_index0++)
            {
                if (l_index0 < 8)
                {
                    l_dq[l_index0] = l_dqBitmap[l_index0];
                    if (l_dqBitmap[l_index0])
                    {
                        FAPI_DBG("%s:\n the port=%d  bad dq=%x on dq=%d",
                                 i_target_mba.toEcmdString(), l_port,
                                 l_dqBitmap[l_index0], l_index0);
                    }
                }
                else
                {
                    if (l_dqBitmap[l_index0])
                    {
                        FAPI_DBG("%s:\n the port=%d  bad dq=%x on dq=%d",
                                 i_target_mba.toEcmdString(), l_port,
                                 l_dqBitmap[l_index0], l_index0);
                    }
                    l_sp[l_index_sp] = l_dqBitmap[l_index0];
                    l_index_sp++;
                }
            }

            rc_num = l_data_buffer1_64.insertFromRight(l_dq, 0, 64);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }

            if (l_mbaPosition == 0)
            {
                if (l_port == 0)
                {
                    if(l_attr_eff_dimm_type_u8 != fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
                    {
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp_isdimm, 8, 8);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp, 0, 8);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                    }
                    else
                    {
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp, 0, 16);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                    }
                    rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMA1Q_0x02011672, l_data_buffer4_64);
                    if (rc) return rc;
                    rc_num = l_data_buffer1_64.setOr(l_data_buffer4_64, 0, 64);
                    if (rc_num)
                    {
                        FAPI_ERR("Error in function  cfg_byte_mask:");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                    rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMA1Q_0x02011672, l_data_buffer1_64);
                    if (rc) return rc;
                    rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer5_64);
                    if (rc) return rc;
                    rc_num = l_data_buffer2_64.setOr(l_data_buffer5_64, 0, 64);
                    if (rc_num)
                    {
                        FAPI_ERR("Error in function  cfg_byte_mask:");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                    rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer2_64);
                    if (rc) return rc;
                }
                else
                {
                    rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer2_64);
                    if (rc) return rc;
                    if(l_attr_eff_dimm_type_u8 != fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
                    {
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp_isdimm, 24, 8);
                        rc_num |= l_data_buffer2_64.insertFromRight(l_sp, 16, 8);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                    }
                    else
                    {
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp, 16, 16);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                    }
                    rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMB1Q_0x02011673, l_data_buffer4_64);
                    if (rc) return rc;
                    rc_num = l_data_buffer1_64.setOr(l_data_buffer4_64, 0, 64);
                    if (rc_num)
                    {
                        FAPI_ERR("Error in function  cfg_byte_mask:");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                    rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMB1Q_0x02011673, l_data_buffer1_64);
                    if (rc) return rc;
                    rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer5_64);
                    if (rc) return rc;
                    rc_num = l_data_buffer2_64.setOr(l_data_buffer5_64, 0, 64);
                    if (rc_num)
                    {
                        FAPI_ERR("Error in function  cfg_byte_mask:");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                    rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer2_64);
                    if (rc) return rc;
                }
            }
            else
            {
                if (l_port == 0)
                {
                    if(l_attr_eff_dimm_type_u8 != fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
                    {
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp_isdimm, 8, 8);
                        rc_num |= l_data_buffer2_64.insertFromRight(l_sp, 0, 8);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                    }
                    else
                    {
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp, 0, 16);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                    }
                    rc = fapiGetScom(i_target_centaur, 0x02011772, l_data_buffer4_64);
                    if (rc) return rc;
                    rc_num = l_data_buffer1_64.setOr(l_data_buffer4_64, 0, 64);
                    if (rc_num)
                    {
                        FAPI_ERR("Error in function  cfg_byte_mask:");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                    rc = fapiPutScom(i_target_centaur, 0x02011772, l_data_buffer1_64);
                    if (rc) return rc;
                    rc = fapiGetScom(i_target_centaur, 0x02011774, l_data_buffer5_64);
                    if (rc) return rc;
                    rc_num = l_data_buffer2_64.setOr(l_data_buffer5_64, 0, 64);
                    if (rc_num)
                    {
                        FAPI_ERR("Error in function  cfg_byte_mask:");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                    rc = fapiPutScom(i_target_centaur, 0x02011774, l_data_buffer2_64);
                    if (rc) return rc;
                }
                else
                {
                    rc = fapiGetScom(i_target_centaur, 0x02011774, l_data_buffer2_64);
                    if (rc) return rc;
                    if(l_attr_eff_dimm_type_u8 != fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
                    {
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp_isdimm, 24, 8);
                        rc_num |= l_data_buffer2_64.insertFromRight(l_sp, 16, 8);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                    }
                    else
                    {
                        rc_num = l_data_buffer2_64.insertFromRight(l_sp, 16, 16);
                        if (rc_num)
                        {
                            FAPI_ERR("Error in function  cfg_byte_mask:");
                            rc.setEcmdError(rc_num);
                            return rc;
                        }
                    }

                    rc = fapiGetScom(i_target_centaur, 0x02011773, l_data_buffer4_64);
                    if (rc) return rc;
                    rc_num = l_data_buffer1_64.setOr(l_data_buffer4_64, 0, 64);
                    if (rc_num)
                    {
                        FAPI_ERR("Error in function  cfg_byte_mask:");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                    rc = fapiPutScom(i_target_centaur, 0x02011773,
                                     l_data_buffer1_64);
                    if (rc) return rc;
                    rc = fapiGetScom(i_target_centaur, 0x02011774, l_data_buffer5_64);
                    if (rc) return rc;
                    rc_num = l_data_buffer2_64.setOr(l_data_buffer5_64, 0, 64);
                    if (rc_num)
                    {
                        FAPI_ERR("Error in function  cfg_byte_mask:");
                        rc.setEcmdError(rc_num);
                        return rc;
                    }
                    rc = fapiPutScom(i_target_centaur, 0x02011774, l_data_buffer2_64);
                    if (rc) return rc;
                }
            }
        }
    }

    if (l_max_0 == 0)
    {
        if (l_mbaPosition == 0)
        {
            rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMA1Q_0x02011672, l_data_buffer1_64);
            if (rc) return rc;
            rc_num = l_data_buffer1_64.setDoubleWord(0, l_var);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMA1Q_0x02011672, l_data_buffer1_64);
            if (rc) return rc;
            rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer1_64);
            if (rc) return rc;
            rc_num = l_data_buffer1_64.insertFromRight(l_spare, 0, 16);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer1_64);
            if (rc) return rc;
        }
        else
        {
            rc = fapiGetScom(i_target_centaur, 0x02011772, l_data_buffer1_64);
            if (rc) return rc;
            rc_num = l_data_buffer1_64.setDoubleWord(0, l_var);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_centaur, 0x02011772, l_data_buffer1_64);
            if (rc) return rc;
            rc = fapiGetScom(i_target_centaur, 0x02011774, l_data_buffer1_64);
            if (rc) return rc;
            rc_num = l_data_buffer1_64.insertFromRight(l_spare, 0, 16);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_centaur, 0x02011774, l_data_buffer1_64);
            if (rc) return rc;
        }
    }

    if (l_max_1 == 0)
    {
        if (l_mbaPosition == 0)
        {
            rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMB1Q_0x02011673, l_data_buffer1_64);
            if (rc) return rc;
            rc_num = l_data_buffer1_64.setDoubleWord(0, l_var);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMB1Q_0x02011673, l_data_buffer1_64);
            if (rc) return rc;
            rc = fapiGetScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer1_64);
            if (rc)  return rc;
            rc_num = l_data_buffer1_64.insertFromRight(l_spare, 16, 16);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBCMABQ_0x02011674, l_data_buffer1_64);
            if (rc) return rc;
        }
        else
        {
            rc = fapiGetScom(i_target_centaur, 0x02011773, l_data_buffer1_64);
            if (rc) return rc;
            rc_num = l_data_buffer1_64.setDoubleWord(0, l_var);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_centaur, 0x02011773, l_data_buffer1_64);
            if (rc) return rc;
            rc = fapiGetScom(i_target_centaur, 0x02011774, l_data_buffer1_64);
            if (rc) return rc;
            rc_num = l_data_buffer1_64.insertFromRight(l_spare, 16, 16);
            if (rc_num)
            {
                FAPI_ERR("Error in function  cfg_byte_mask:");
                rc.setEcmdError(rc_num);
                return rc;
            }
            rc = fapiPutScom(i_target_centaur, 0x02011774, l_data_buffer1_64);
            if (rc) return rc;
        }
    }

    return rc;
}

fapi::ReturnCode mss_conversion_testtype(const fapi::Target & i_target_mba,
                                         uint8_t l_pattern,
                                         mcbist_test_mem &i_mcbtest)
{
    ReturnCode rc;

    FAPI_INF("%s:value of testtype is %d", i_target_mba.toEcmdString(), l_pattern);
    switch (l_pattern)
    {
    case 0:
        i_mcbtest = USER_MODE;
        FAPI_INF("%s:TESTTYPE :USER_MODE", i_target_mba.toEcmdString());
        break;
    case 1:
        i_mcbtest = CENSHMOO;
        FAPI_INF("%s:TESTTYPE :CENSHMOO", i_target_mba.toEcmdString());
        break;
    case 2:
        i_mcbtest = SUREFAIL;
        FAPI_INF("%s:TESTTYPE :SUREFAIL", i_target_mba.toEcmdString());
        break;
    case 3:
        i_mcbtest = MEMWRITE;
        FAPI_INF("%s:TESTTYPE :MEMWRITE", i_target_mba.toEcmdString());
        break;
    case 4:
        i_mcbtest = MEMREAD;
        FAPI_INF("%s:TESTTYPE :MEMREAD", i_target_mba.toEcmdString());
        break;
    case 5:
        i_mcbtest = CBR_REFRESH;
        FAPI_INF("%s:TESTTYPE :CBR_REFRESH", i_target_mba.toEcmdString());
        break;
    case 6:
        i_mcbtest = MCBIST_SHORT;
        FAPI_INF("%s:TESTTYPE :MCBIST_SHORT", i_target_mba.toEcmdString());
        break;
    case 7:
        i_mcbtest = SHORT_SEQ;
        FAPI_INF("%s:TESTTYPE :SHORT_SEQ", i_target_mba.toEcmdString());
        break;
    case 8:
        i_mcbtest = DELTA_I;
        FAPI_INF("%s:TESTTYPE :DELTA_I", i_target_mba.toEcmdString());
        break;
    case 9:
        i_mcbtest = DELTA_I_LOOP;
        FAPI_INF("%s:TESTTYPE :DELTA_I_LOOP", i_target_mba.toEcmdString());
        break;
    case 10:
        i_mcbtest = SHORT_RAND;
        FAPI_INF("%s:TESTTYPE :SHORT_RAND", i_target_mba.toEcmdString());
        break;
    case 11:
        i_mcbtest = LONG1;
        FAPI_INF("%s:TESTTYPE :LONG1", i_target_mba.toEcmdString());
        break;
    case 12:
        i_mcbtest = BUS_TAT;
        FAPI_INF("%s:TESTTYPE :BUS_TAT", i_target_mba.toEcmdString());
        break;
    case 13:
        i_mcbtest = SIMPLE_FIX;
        FAPI_INF("%s:TESTTYPE :SIMPLE_FIX", i_target_mba.toEcmdString());
        break;
    case 14:
        i_mcbtest = SIMPLE_RAND;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RAND", i_target_mba.toEcmdString());
        break;
    case 15:
        i_mcbtest = SIMPLE_RAND_2W;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RAND_2W", i_target_mba.toEcmdString());
        break;
    case 16:
        i_mcbtest = SIMPLE_RAND_FIXD;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RAND_FIXD", i_target_mba.toEcmdString());
        break;
    case 17:
        i_mcbtest = SIMPLE_RA_RD_WR;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RA_RD_WR", i_target_mba.toEcmdString());
        break;
    case 18:
        i_mcbtest = SIMPLE_RA_RD_R;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RA_RD_R", i_target_mba.toEcmdString());
        break;
    case 19:
        i_mcbtest = SIMPLE_RA_FD_R;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RA_FD_R", i_target_mba.toEcmdString());
        break;
    case 20:
        i_mcbtest = SIMPLE_RA_FD_R_INF;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RA_FD_R_INF", i_target_mba.toEcmdString());
        break;
    case 21:
        i_mcbtest = SIMPLE_SA_FD_R;
        FAPI_INF("%s:TESTTYPE :SIMPLE_SA_FD_R", i_target_mba.toEcmdString());
        break;
    case 22:
        i_mcbtest = SIMPLE_RA_FD_W;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RA_FD_W", i_target_mba.toEcmdString());
        break;
    case 23:
        i_mcbtest = INFINITE;
        FAPI_INF("%s:TESTTYPE :INFINITE", i_target_mba.toEcmdString());
        break;
    case 24:
        i_mcbtest = WR_ONLY;
        FAPI_INF("%s:TESTTYPE :WR_ONLY", i_target_mba.toEcmdString());
        break;
    case 25:
        i_mcbtest = W_ONLY;
        FAPI_INF("%s:TESTTYPE :W_ONLY", i_target_mba.toEcmdString());
        break;
    case 26:
        i_mcbtest = R_ONLY;
        FAPI_INF("%s:TESTTYPE :R_ONLY", i_target_mba.toEcmdString());
        break;
    case 27:
        i_mcbtest = W_ONLY_RAND;
        FAPI_INF("%s:TESTTYPE :W_ONLY_RAND", i_target_mba.toEcmdString());
        break;
    case 28:
        i_mcbtest = R_ONLY_RAND;
        FAPI_INF("%s:TESTTYPE :R_ONLY_RAND", i_target_mba.toEcmdString());
        break;
    case 29:
        i_mcbtest = R_ONLY_MULTI;
        FAPI_INF("%s:TESTTYPE :R_ONLY_MULTI", i_target_mba.toEcmdString());
        break;
    case 30:
        i_mcbtest = SHORT;
        FAPI_INF("%s:TESTTYPE :SHORT", i_target_mba.toEcmdString());
        break;
    case 31:
        i_mcbtest = SIMPLE_RAND_BARI;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RAND_BARI", i_target_mba.toEcmdString());
        break;
    case 32:
        i_mcbtest = W_R_INFINITE;
        FAPI_INF("%s:TESTTYPE :W_R_INFINITE", i_target_mba.toEcmdString());
        break;
    case 33:
        i_mcbtest = W_R_RAND_INFINITE;
        FAPI_INF("%s:TESTTYPE :W_R_RAND_INFINITE", i_target_mba.toEcmdString());
        break;
    case 34:
        i_mcbtest = R_INFINITE1;
        FAPI_INF("%s:TESTTYPE :R_INFINITE1", i_target_mba.toEcmdString());
        break;
    case 35:
        i_mcbtest = R_INFINITE_RF;
        FAPI_INF("%s:TESTTYPE :R_INFINITE_RF", i_target_mba.toEcmdString());
        break;
    case 36:
        i_mcbtest = MARCH;
        FAPI_INF("%s:TESTTYPE :MARCH", i_target_mba.toEcmdString());
        break;
    case 37:
        i_mcbtest = SIMPLE_FIX_RF;
        FAPI_INF("%s:TESTTYPE :SIMPLE_FIX_RF", i_target_mba.toEcmdString());
        break;
    case 38:
        i_mcbtest = SHMOO_STRESS;
        FAPI_INF("%s:TESTTYPE :SHMOO_STRESS", i_target_mba.toEcmdString());
        break;
    case 39:
        i_mcbtest = SIMPLE_RAND_RA;
        FAPI_INF("%s:TESTTYPE :SIMPLE_RAND_RA", i_target_mba.toEcmdString());
        break;
    case 40:
        i_mcbtest = SIMPLE_FIX_RA;
        FAPI_INF("%s:TESTTYPE :SIMPLE_FIX_RA", i_target_mba.toEcmdString());
        break;
    case 41:
        i_mcbtest = SIMPLE_FIX_RF_RA;
        FAPI_INF("%s:TESTTYPE :SIMPLE_FIX_RF_RA", i_target_mba.toEcmdString());
        break;
    case 42:
        i_mcbtest = TEST_RR;
        FAPI_INF("%s:TESTTYPE :TEST_RR", i_target_mba.toEcmdString());
        break;
    case 43:
        i_mcbtest = TEST_RF;
        FAPI_INF("%s:TESTTYPE :TEST_RF", i_target_mba.toEcmdString());
        break;
    case 44:
        i_mcbtest = W_ONLY_INFINITE_RAND;
        FAPI_INF("%s:TESTTYPE :W_ONLY_INFINITE_RAND", i_target_mba.toEcmdString());
        break;
    case 45:
        i_mcbtest = MCB_2D_CUP_SEQ;
        FAPI_INF("%s:TESTTYPE :MCB_2D_CUP_SEQ", i_target_mba.toEcmdString());
        break;
    case 46:
        i_mcbtest = MCB_2D_CUP_RAND;
        FAPI_INF("%s:TESTTYPE :MCB_2D_CUP_RAND", i_target_mba.toEcmdString());
        break;
    case 47:
        i_mcbtest = SHMOO_STRESS_INFINITE;
        FAPI_INF("%s:TESTTYPE :SHMOO_STRESS_INFINITE", i_target_mba.toEcmdString());
        break;
    case 48:
        i_mcbtest = HYNIX_1_COL;
        FAPI_INF("%s:TESTTYPE :HYNIX_1_COL", i_target_mba.toEcmdString());
        break;
    case 49:
        i_mcbtest = RMWFIX;
        FAPI_INF("%s:TESTTYPE :RMWFIX", i_target_mba.toEcmdString());
        break;
    case 50:
        i_mcbtest = RMWFIX_I;
        FAPI_INF("%s:TESTTYPE :RMWFIX_I", i_target_mba.toEcmdString());
        break;
    case 51:
        i_mcbtest = W_INFINITE;
        FAPI_INF("%s:TESTTYPE :W_INFINITE", i_target_mba.toEcmdString());
        break;
    case 52:
        i_mcbtest = R_INFINITE;
        FAPI_INF("%s:TESTTYPE :R_INFINITE", i_target_mba.toEcmdString());
        break;


    default:
        FAPI_INF("%s:Wrong Test_type,so using default test_type",
                 i_target_mba.toEcmdString());
    }

    return rc;
}

fapi::ReturnCode mss_conversion_data(const fapi::Target & i_target_mba,
                                     uint8_t l_pattern,
                                     mcbist_data_gen &i_mcbpatt)
{
    ReturnCode rc;
    FAPI_INF("%s:value of pattern is %d", i_target_mba.toEcmdString(), l_pattern);
    switch (l_pattern)
    {
    case 0:
        i_mcbpatt = ABLE_FIVE;
        FAPI_INF("%s:PATTERN :ABLE_FIVE", i_target_mba.toEcmdString());
        break;
    case 1:
        i_mcbpatt = USR_MODE;
        FAPI_INF("%s:PATTERN :USER_MODE", i_target_mba.toEcmdString());
        break;
    case 2:
        i_mcbpatt = ONEHOT;
        FAPI_INF("%s:PATTERN :ONEHOT", i_target_mba.toEcmdString());
        break;
    case 3:
        i_mcbpatt = DQ0_00011111_RESTALLONE;
        FAPI_INF("%s:PATTERN :DQ0_00011111_RESTALLONE", i_target_mba.toEcmdString());
        break;
    case 4:
        i_mcbpatt = DQ0_11100000_RESTALLZERO;
        FAPI_INF("%s:PATTERN :DQ0_11100000_RESTALLZERO", i_target_mba.toEcmdString());
        break;
    case 5:
        i_mcbpatt = ALLZERO;
        FAPI_INF("%s:PATTERN :ALLZERO", i_target_mba.toEcmdString());
        break;
    case 6:
        i_mcbpatt = ALLONE;
        FAPI_INF("%s:PATTERN :ALLONE", i_target_mba.toEcmdString());
        break;
    case 7:
        i_mcbpatt = BYTE_BURST_SIGNATURE;
        FAPI_INF("%s:PATTERN :BYTE_BURST_SIGNATURE", i_target_mba.toEcmdString());
        break;
    case 8:
        i_mcbpatt = BYTE_BURST_SIGNATURE_V1;
        FAPI_INF("%s:PATTERN :BYTE_BURST_SIGNATURE_V1", i_target_mba.toEcmdString());
        break;
    case 9:
        i_mcbpatt = BYTE_BURST_SIGNATURE_V2;
        FAPI_INF("%s:PATTERN :BYTE_BURST_SIGNATURE_V2", i_target_mba.toEcmdString());
        break;
    case 10:
        i_mcbpatt = BYTE_BURST_SIGNATURE_V3;
        FAPI_INF("%s:PATTERN :BYTE_BURST_SIGNATURE_V3", i_target_mba.toEcmdString());
        break;
    case 11:
        i_mcbpatt = DATA_GEN_DELTA_I;
        FAPI_INF("%s:PATTERN :DATA_GEN_DELTA_I", i_target_mba.toEcmdString());
        break;
    case 12:
        i_mcbpatt = MCBIST_2D_CUP_PAT0;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT0", i_target_mba.toEcmdString());
        break;
    case 13:
        i_mcbpatt = MPR;
        FAPI_INF("%s:PATTERN :MPR", i_target_mba.toEcmdString());
        break;
    case 14:
        i_mcbpatt = MPR03;
        FAPI_INF("%s:PATTERN :MPR03", i_target_mba.toEcmdString());
        break;
    case 15:
        i_mcbpatt = MPR25;
        FAPI_INF("%s:PATTERN :MPR25", i_target_mba.toEcmdString());
        break;
    case 16:
        i_mcbpatt = MPR47;
        FAPI_INF("%s:PATTERN :MPR47", i_target_mba.toEcmdString());
        break;
    case 17:
        i_mcbpatt = DELTA_I1;
        FAPI_INF("%s:PATTERN :DELTA_I1", i_target_mba.toEcmdString());
        break;
    case 18:
        i_mcbpatt = MCBIST_2D_CUP_PAT1;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT1", i_target_mba.toEcmdString());
        break;
    case 19:
        i_mcbpatt = MHC_55;
        FAPI_INF("%s:PATTERN :MHC_55", i_target_mba.toEcmdString());
        break;
    case 20:
        i_mcbpatt = MHC_DQ_SIM;
        FAPI_INF("%s:PATTERN :MHC_DQ_SIM", i_target_mba.toEcmdString());
        break;
    case 21:
        i_mcbpatt = MCBIST_2D_CUP_PAT2;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT2", i_target_mba.toEcmdString());
        break;
    case 22:
        i_mcbpatt = MCBIST_2D_CUP_PAT3;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT3", i_target_mba.toEcmdString());
        break;
    case 23:
        i_mcbpatt = MCBIST_2D_CUP_PAT4;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT4", i_target_mba.toEcmdString());
        break;
    case 24:
        i_mcbpatt = MCBIST_2D_CUP_PAT5;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT5", i_target_mba.toEcmdString());
        break;
    case 25:
        i_mcbpatt = MCBIST_2D_CUP_PAT6;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT6", i_target_mba.toEcmdString());
        break;
    case 26:
        i_mcbpatt = MCBIST_2D_CUP_PAT7;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT7", i_target_mba.toEcmdString());
        break;
    case 27:
        i_mcbpatt = MCBIST_2D_CUP_PAT8;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT8", i_target_mba.toEcmdString());
        break;
    case 28:
        i_mcbpatt = MCBIST_2D_CUP_PAT9;
        FAPI_INF("%s:PATTERN :MCBIST_2D_CUP_PAT9", i_target_mba.toEcmdString());
        break;
    case 29:
        i_mcbpatt = CWLPATTERN;
        FAPI_INF("%s:PATTERN :CWLPATTERN", i_target_mba.toEcmdString());
        break;
    case 30:
        i_mcbpatt = GREY1;
        FAPI_INF("%s:PATTERN :GREY1", i_target_mba.toEcmdString());
        break;
    case 31:
        i_mcbpatt = DC_ONECHANGE;
        FAPI_INF("%s:PATTERN :DC_ONECHANGE", i_target_mba.toEcmdString());
        break;
    case 32:
        i_mcbpatt = DC_ONECHANGEDIAG;
        FAPI_INF("%s:PATTERN :DC_ONECHANGEDIAG", i_target_mba.toEcmdString());
        break;
    case 33:
        i_mcbpatt = GREY2;
        FAPI_INF("%s:PATTERN :GREY2", i_target_mba.toEcmdString());
        break;
    case 34:
        i_mcbpatt = FIRST_XFER;
        FAPI_INF("%s:PATTERN :FIRST_XFER", i_target_mba.toEcmdString());
        break;
    case 35:
        i_mcbpatt = MCBIST_222_XFER;
        FAPI_INF("%s:PATTERN :MCBIST_222_XFER", i_target_mba.toEcmdString());
        break;
    case 36:
        i_mcbpatt = MCBIST_333_XFER;
        FAPI_INF("%s:PATTERN :MCBIST_333_XFER", i_target_mba.toEcmdString());
        break;
    case 37:
        i_mcbpatt = MCBIST_444_XFER;
        FAPI_INF("%s:PATTERN :MCBIST_444_XFER", i_target_mba.toEcmdString());
        break;
    case 38:
        i_mcbpatt = MCBIST_555_XFER;
        FAPI_INF("%s:PATTERN :MCBIST_555_XFER", i_target_mba.toEcmdString());
        break;
    case 39:
        i_mcbpatt = MCBIST_666_XFER;
        FAPI_INF("%s:PATTERN :MCBIST_666_XFER", i_target_mba.toEcmdString());
        break;
    case 40:
        i_mcbpatt = MCBIST_777_XFER;
        FAPI_INF("%s:PATTERN :MCBIST_777_XFER", i_target_mba.toEcmdString());
        break;
    case 41:
        i_mcbpatt = MCBIST_888_XFER;
        FAPI_INF("%s:PATTERN :MCBIST_888_XFER", i_target_mba.toEcmdString());
        break;
    case 42:
        i_mcbpatt = FIRST_XFER_X4MODE;
        FAPI_INF("%s:PATTERN :FIRST_XFER_X4MODE", i_target_mba.toEcmdString());
        break;
    case 43:
        i_mcbpatt = MCBIST_LONG;
        FAPI_INF("%s:PATTERN :MCBIST_LONG", i_target_mba.toEcmdString());
        break;
    case 44:
        i_mcbpatt = PSEUDORANDOM;
        FAPI_INF("%s:PATTERN :PSEUDORANDOM", i_target_mba.toEcmdString());
        break;
    case 45:
        i_mcbpatt = CASTLE;
        FAPI_INF("%s:PATTERN :CASTLE", i_target_mba.toEcmdString());
        break;
    default:
        FAPI_INF("%s:Wrong Data Pattern,so using default pattern",
                 i_target_mba.toEcmdString());
    }

    return rc;
}

}

