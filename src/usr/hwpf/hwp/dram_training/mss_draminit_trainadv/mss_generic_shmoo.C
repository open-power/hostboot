/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/mss_draminit_trainadv/mss_generic_shmoo.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
// $Id: mss_generic_shmoo.C,v 1.111 2016/03/25 14:15:04 sglancy Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_generic_shmoo.C,v $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             : mss_generic_shmoo.C
// *! TITLE                : MSS Generic Shmoo Implementation
// *! DESCRIPTION          : Memory Subsystem Generic Shmoo -- abstraction for HB
// *! CONTEXT              : To make all shmoos share a common abstraction layer
// *!
// *! OWNER  NAME          : Preetham Hosmane         Email: preeragh@in.ibm.com
// *! BACKUP NAME          : Saravanan Sethuraman
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// --------|--------|---------|--------------------------------------------------
//   1.109 |sglancy |08-MAR-16| Fixed compile error
//   1.108 |sglancy |07-MAR-16| Updated for box shmoo
//   1.107 |preeragh|13-Nov-15| Run Shmoos Only on Master Ranks 256GB 3DTSV
//   1.106 |preeragh|02-Sep-15| Run Shmoos Only on Master Ranks!
//   1.105 |sglancy| 10-Oct-15| Changed attribute names
//   1.104 |preeragh|20-Oct-15| Fix Report Prints and Range for WR_DDR4_Vref Range 0-50
//   1.103 |preeragh|20-Oct-15| Remove Floating Point for V-ref Prints
//   1.102 |preeragh|07-Oct-15| PDA - Write Back Fix - DDR4
//   1.101 |sglancy |25-Sep-15| Fixed bug where shmoos only had a granularity of 2 ticks instead of 1
//   1.100 |preeragh|25-Aug-15| More FW Review Comments
//   1.99  |preeragh|25-Aug-15| More FW Review Comments
//   1.98  |preeragh|19-Aug-15| FW Review Comments
//   1.97  |preeragh|11-Aug-15| Removed -composite/bin dependency for WRT_DQS
//   1.96  |preeragh|05-Aug-15| Optimized for Linear / Comp / Bin Schmoos
//   1.95  |preeragh|22-Jul-15| 64bit compile fix
//   1.94  |preeragh|22-Jun-15| DDR4 Enhancements and Optimizations
//   1.93  |sglancy |16-Feb-15| Merged FW comments with lab needs
//   1.92  |preeragh|15-Dec-14| Reverted Changes to v.1.87
//   1.88  |rwheeler|10-Nov-14| Updated setup_mcbist for added variable.
//   1.87  |abhijsau|7-Feb-14| added sanity check and error call out for schmoo's , removed printing of disconnected DQS.
//   1.86  |abhijsau|24-Jan-14| Fixed code as per changes in access delay error check
//   1.85  |mjjones |24-Jan-14| Fixed layout and error handling for RAS Review
//   1.84  |abhijit |16-JAN-14| Changed EFF_DIMM_TYPE attribute to   ATTR_EFF_CUSTOM_DIMM
//   1.83  |abhijit	|17-DEC-13| Changed the whole code structure to enable run from firmware
//   1.81  |abhijit	|07-nov-13| Fixed memory release as per fw suggestion
//   1.80  |abhijit	|07-nov-13| Fixed array initialization of bad bit array as per fw suggestion
//   1.79  |abhijit	|07-nov-13| Fixed array initialization of valid_ranks[] in schmoo constructor & modified prints in report function to support 2D script
//   1.78  |abhijit	|29-oct-13| added feature of not schmooing on bad dq and also added the target prints
//   1.77  |abhijit	|21-oct-13| fixed the printing for tdqss min and tdqss max
//   1.76  |abhijit	|17-oct-13| fixed the printing for dqs by 4
//   1.74  |abhijit	|4-oct-13 | fixed fw comments
//   1.73  |abhijit	|1-oct-13 | fixed write dqs by 8 for isdimm
//   1.72  |abhijit	|20-sep-13| fixed printing of rd eye report as -1 for not finding left bound
//   1.71  |abhijit	|18-sep-13| changed for mcbist call
//   1.70  |abhijit	|12-sep-13| Fixed binary debug prints
//   1.69  |abhijit	|12-sep-13| Fixed binary debug prints
//   1.68  |abhijit	|11-sep-13| Added Binary Schmoo algorithm
//   1.67  |abhijit	|4-sep-13 | fixed fw comment
//   -		-		-			-
//------------------------------------------------------------------------------
#include <fapi.H>
#include "mss_generic_shmoo.H"
#include "mss_mcbist.H"
#include <mss_draminit_training.H>
#include <dimmBadDqBitmapFuncs.H>
#include <mss_access_delay_reg.H>

//#define DBG 0

extern "C"
{
    using namespace fapi;

    // START IMPLEMENTATION OF generic_shmoo CLASS METHODS
    //! shmoo_mask - What shmoos do you want to run ... encoded as Hex 0x2,0x4,0x8,0x16
    /*------------------------------------------------------------------------------
    * constructor: generic_shmoo
    * Description  :Constructor used to initialize variables and do the initial settings
    *
    @param uint8_t  addr:
    @param shmoo_type_t shmoo_mask:
    @param shmoo_algorithm_t shmoo_algorithm:
    * ---------------------------------------------------------------------------*/
    generic_shmoo::generic_shmoo(uint8_t addr,shmoo_type_t shmoo_mask,shmoo_algorithm_t shmoo_algorithm)
    {
        this->shmoo_mask=shmoo_mask; //! Sets what Shmoos the caller wants to run
        this->algorithm=shmoo_algorithm ;
        this->iv_shmoo_type = shmoo_mask;
        this->iv_addr=addr;
        iv_MAX_BYTES=10;
        iv_DQS_ON=0;
        iv_pattern=0;
        iv_test_type=0;
        iv_dmm_type=0;
        iv_shmoo_param=0;
        iv_binary_diff=2;
        iv_vref_mul=0;
        iv_SHMOO_ON = 0;

        for(int p=0; p<MAX_PORT; p++)
        {
            for(int i=0; i<MAX_RANK; i++)
            {
                valid_rank1[p][i]=0;
                valid_rank[i]=0;
            }
        }
        iv_MAX_RANKS[0]=4;
        iv_MAX_RANKS[1]=4;

        if (shmoo_mask & TEST_NONE)
        {
            FAPI_INF("mss_generic_shmoo : NONE selected %d", shmoo_mask);
        }

        if (shmoo_mask & MCBIST)
        {
            FAPI_INF("mss_generic_shmoo : MCBIST selected %d", shmoo_mask);
            iv_shmoo_type = 1;
        }
        if (shmoo_mask & WR_EYE)
        {
            FAPI_INF("mss_generic_shmoo : WR_EYE selected %d", shmoo_mask);
            iv_shmoo_type = 2;
        }

        if (shmoo_mask & RD_EYE)
        {
            FAPI_INF("mss_generic_shmoo : RD_EYE selected %d", shmoo_mask);
            iv_shmoo_type = 8;
        }
        if (shmoo_mask & WRT_DQS)
        {
            FAPI_INF("mss_generic_shmoo : WRT_DQS selected %d", shmoo_mask);
            iv_shmoo_type = 4;
            iv_DQS_ON = 1;
        }

        if(iv_DQS_ON==1) {
            for (int k = 0; k < MAX_SHMOO; k++)
            {
                for (int i = 0; i < MAX_PORT; i++)
                {
                    for (int j = 0; j < iv_MAX_RANKS[i]; j++)
                    {
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.nom_val, 250);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.lb_regval, 0);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.rb_regval, 512);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.last_pass, 0);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.last_fail, 0);
                        init_multi_array(SHMOO[k].MBA.P[i].S[j].K.curr_val, 0);
                    }
                }
            }
        }
    }

    /*------------------------------------------------------------------------------
    * Function: run
    * Description  : ! Delegator function that runs shmoo using other  functions
    *
    * Parameters: i_target: mba;		iv_port: 0, 1
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::run(const fapi::Target & i_target,
                                        uint32_t *o_right_min_margin,
                                        uint32_t *o_left_min_margin,
                                        uint32_t i_vref_mul)
    {
        fapi::ReturnCode rc;
        uint8_t num_ranks_per_dimm[2][2];
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_schmoo_test_type_u8 = 0;
        uint8_t l_attr_schmoo_multiple_setup_call_u8 = 0;
        uint8_t l_mcbist_prnt_off = 0;
        uint64_t i_content_array[10];
        uint8_t l_rankpgrp0[2] = { 0 };
        uint8_t l_rankpgrp1[2] = { 0 };
        uint8_t l_rankpgrp2[2] = { 0 };
        uint8_t l_rankpgrp3[2] = { 0 };
        uint8_t l_totrg_0 = 0;
        uint8_t l_totrg_1 = 0;
        uint8_t l_pp = 0;
        uint8_t l_shmoo_param = 0;
        uint8_t rank_table_port0[8] = {0};
        uint8_t rank_table_port1[8] = {0};
		uint8_t l_dram_gen = 0;
        rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_MODE, &i_target, l_shmoo_param);
        if (rc) return rc;
        iv_shmoo_param = l_shmoo_param;
        FAPI_INF(" +++++ The iv_shmoo_param = %d ++++ ",iv_shmoo_param);
        iv_vref_mul = i_vref_mul;

        ecmdDataBufferBase l_data_buffer1_64(64);
        uint8_t l_dram_width = 0;
		uint8_t eff_stack_type[2][2];

        rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_dram_width);
        if(rc) return rc;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_PRINTING_DISABLE, &i_target, l_mcbist_prnt_off);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_ranks_per_dimm);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target, l_attr_eff_dimm_type_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_TEST_VALID, &i_target, l_attr_schmoo_test_type_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_SCHMOO_MULTIPLE_SETUP_CALL, &i_target, l_attr_schmoo_multiple_setup_call_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP0, &i_target, l_rankpgrp0);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP1, &i_target, l_rankpgrp1);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP2, &i_target, l_rankpgrp2);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_PRIMARY_RANK_GROUP3, &i_target, l_rankpgrp3);
        if(rc) return rc;
		rc = FAPI_ATTR_GET(ATTR_EFF_STACK_TYPE, &i_target,eff_stack_type);
		if(rc) return rc;
		rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, l_dram_gen); 
		if(rc) return rc;
        iv_MAX_RANKS[0]=num_ranks_per_dimm[0][0]+num_ranks_per_dimm[0][1];
        iv_MAX_RANKS[1]=num_ranks_per_dimm[1][0]+num_ranks_per_dimm[1][1];
        iv_pattern=0;
        iv_test_type=0;
        if ( l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES )
        {
            iv_MAX_BYTES=10;
        }
        else
        {

            iv_dmm_type=1;
            iv_MAX_BYTES=9;
        }
        uint8_t i_rp = 0;

        for (int l_rnk=0; l_rnk< iv_MAX_RANKS[0]; l_rnk++)
        {   // Byte loop
            rc = mss_getrankpair(i_target,0,0,&i_rp,rank_table_port0);
            if(rc) return rc;
        }

        for (int l_rnk=0; l_rnk< iv_MAX_RANKS[0]; l_rnk++)
        {   // Byte loop
            rc = mss_getrankpair(i_target,1,0,&i_rp,rank_table_port1);
            if(rc) return rc;
        }

        for(int l_p =0; l_p < 2; l_p++)
        {
            for (int l_rnk=0; l_rnk < 8; l_rnk++)
            {   // Byte loop
                if(l_p == 0)
                    valid_rank1[l_p][l_rnk] = rank_table_port0[l_rnk];
                else
                    valid_rank1[l_p][l_rnk] = rank_table_port1[l_rnk];
			if((l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES) && (eff_stack_type[l_p][0] == fapi::ENUM_ATTR_EFF_STACK_TYPE_STACK_3DS) && (l_dram_gen == fapi::ENUM_ATTR_EFF_DRAM_GEN_DDR4))
			{ //3ds 256 GB Dimm
				//FAPI_INF("3DS - 2H 256GB");
				rank_table_port0[0] = 0;
				rank_table_port0[1] = 4;
				rank_table_port0[2] = 255;
				rank_table_port0[3] = 255;
				rank_table_port1[0] = 0;
				rank_table_port1[1] = 4;
				rank_table_port1[2] = 255;
				rank_table_port1[3] = 255;
			}
                //FAPI_INF("PORT - %d - RANK %d\n",l_p,valid_rank1[l_p][l_rnk]);
            }
        }
        FAPI_DBG("mss_generic_shmoo : run() for shmoo type %d", shmoo_mask);
        // Check if all bytes/bits are in a pass condition initially .Otherwise quit

        //Value of l_attr_schmoo_test_type_u8 are  0x01,     0x02,   0x04,      0x08,   0x10 ===
        //                                       "MCBIST","WR_EYE","RD_EYE","WRT_DQS","RD_DQS" resp.

        if (l_attr_schmoo_test_type_u8 == 0)
        {
            FAPI_INF("%s:This procedure wont change any delay settings",
                     i_target.toEcmdString());
            return rc;
        }
        if (l_attr_schmoo_test_type_u8 == 1)
        {
            rc = sanity_check(i_target); // Run MCBIST only when ATTR_EFF_SCHMOO_TEST_VALID is mcbist only

            if (!rc.ok())
            {
                FAPI_ERR("generic_shmoo::run MSS Generic Shmoo failed initial Sanity Check. Memory not in an all pass Condition");
                return rc;
            }
        }
	//runs the box shmoo
	else if (l_attr_schmoo_test_type_u8 == BOX) {
	    rc=get_all_noms(i_target);
            if(rc) return rc;
            if(l_attr_schmoo_multiple_setup_call_u8==0) {
                rc=schmoo_setup_mcb(i_target);
                if(rc) return rc;
            }
	    rc=do_box_shmoo(i_target);
            if(rc) return rc;
	}
        else if (l_attr_schmoo_test_type_u8 == 8)
        {
            if (l_rankpgrp0[0] != 255)
            {
                l_totrg_0++;
            }
            if (l_rankpgrp1[0] != 255)
            {
                l_totrg_0++;
            }
            if (l_rankpgrp2[0] != 255)
            {
                l_totrg_0++;
            }
            if (l_rankpgrp3[0] != 255)
            {
                l_totrg_0++;
            }
            if (l_rankpgrp0[1] != 255)
            {
                l_totrg_1++;
            }
            if (l_rankpgrp1[1] != 255)
            {
                l_totrg_1++;
            }
            if (l_rankpgrp2[1] != 255)
            {
                l_totrg_1++;
            }
            if (l_rankpgrp3[1] != 255)
            {
                l_totrg_1++;
            }
            if ((l_totrg_0 == 1) || (l_totrg_1 == 1))
            {
                rc = shmoo_save_rest(i_target, i_content_array, 0);
                if(rc) return rc;
                l_pp = 1;
            }

            if (l_pp == 1)
            {
                FAPI_INF("%s:Ping pong is disabled", i_target.toEcmdString());
            }
            else
            {
                FAPI_INF("%s:Ping pong is enabled", i_target.toEcmdString());
            }

            if ((l_pp = 1) && ((l_totrg_0 == 1) || (l_totrg_1 == 1)))
            {
                FAPI_INF("%s:Rank group is not good with ping pong. Hope you have set W2W gap to 10",
                         i_target.toEcmdString());
            }

            iv_shmoo_type=4;   //for Gate Delays
            rc=get_all_noms_dqs(i_target);
            if(rc) return rc;

            iv_shmoo_type=2; // For Access delays
            rc=get_all_noms(i_target);
            if(rc) return rc;

            rc=schmoo_setup_mcb(i_target);
            if(rc) return rc;
            //Find RIGHT BOUND OR SETUP BOUND
            rc=find_bound(i_target,RIGHT);
            if(rc) return rc;

            //Find LEFT BOUND OR HOLD BOUND
            rc=find_bound(i_target,LEFT);
            if(rc) return rc;
            iv_shmoo_type=4;

            if (l_dram_width == 4)
            {
                rc = get_margin_dqs_by4(i_target);
                if (rc) return rc;
            }
            else
            {
                rc = get_margin_dqs_by8(i_target);
                if (rc) return rc;
            }

            rc = print_report_dqs(i_target);
            if (rc) return rc;

            rc = get_min_margin_dqs(i_target, o_right_min_margin,o_left_min_margin);
            if (rc) return rc;

            if ((l_totrg_0 == 1) || (l_totrg_1 == 1))
            {
                rc = shmoo_save_rest(i_target, i_content_array, 1);
                if(rc) return rc;
            }

            FAPI_INF("%s: Least tDQSSmin(ps)=%d ps and Least tDQSSmax=%d ps",i_target.toEcmdString(), *o_left_min_margin,*o_right_min_margin);
        }
        else
        {
            FAPI_INF("************ ++++++++++++++++++ ***************** +++++++++++++ *****************");
            rc=get_all_noms(i_target);
            if(rc) return rc;
            if(l_attr_schmoo_multiple_setup_call_u8==0) {
                rc=schmoo_setup_mcb(i_target);
                if(rc) return rc;
            }
            rc=set_all_binary(i_target,RIGHT);
            if(rc) return rc;

            //Find RIGHT BOUND OR SETUP BOUND
            rc=find_bound(i_target,RIGHT);
            if(rc) return rc;
            rc=set_all_binary(i_target,LEFT);
            if(rc) return rc;
            //Find LEFT BOUND OR HOLD BOUND
            rc=find_bound(i_target,LEFT);
            if(rc) return rc;

            //Find the margins in Ps i.e setup margin ,hold margin,Eye width
            rc=get_margin2(i_target);
            if(rc) return rc;
            //It is used to find the lowest of setup and hold margin
            if(iv_shmoo_param==6)
            {

                rc=get_min_margin2(i_target,o_right_min_margin,o_left_min_margin);
                if(rc) return rc;
                rc=print_report2(i_target);
                if(rc) return rc;
                FAPI_INF("%s:Minimum hold margin=%d ps and setup margin=%d ps",i_target.toEcmdString(), *o_left_min_margin,*o_right_min_margin);
            }
            else
            {
                rc=get_min_margin2(i_target,o_right_min_margin,o_left_min_margin);
                if(rc) return rc;
                rc=print_report2(i_target);
                if(rc) return rc;
                FAPI_INF("%s:Minimum hold margin=%d ps and setup margin=%d ps",i_target.toEcmdString(), *o_left_min_margin,*o_right_min_margin);
            }
        }
        l_mcbist_prnt_off=0;
        rc = FAPI_ATTR_SET(ATTR_MCBIST_PRINTING_DISABLE, &i_target, l_mcbist_prnt_off);
        if(rc) return rc;
        return rc;
    }

    fapi::ReturnCode generic_shmoo::shmoo_save_rest(const fapi::Target & i_target,
            uint64_t i_content_array[],
            uint8_t i_mode)
    {
        ReturnCode rc;
        uint32_t rc_num;
        uint8_t l_index = 0;
        uint64_t l_value = 0;
        uint64_t l_val_u64 = 0;
        ecmdDataBufferBase l_shmoo1ab(64);
        uint64_t l_Databitdir[10] = { 0x800000030301143full, 0x800004030301143full,
                                      0x800008030301143full, 0x80000c030301143full, 0x800010030301143full,
                                      0x800100030301143full, 0x800104030301143full, 0x800108030301143full,
                                      0x80010c030301143full, 0x800110030301143full
                                    };
        if (i_mode == 0)
        {
            FAPI_INF("%s: Saving DP18 data bit direction register contents",
                     i_target.toEcmdString());
            for (l_index = 0; l_index < MAX_BYTE; l_index++)
            {
                l_value = l_Databitdir[l_index];
                rc = fapiGetScom(i_target, l_value, l_shmoo1ab);
                if (rc) return rc;
                rc_num = l_shmoo1ab.setBit(57);
                if (rc_num)
                {
                    FAPI_ERR("Error in function  shmoo_save_rest:");
                    rc.setEcmdError(rc_num);
                    return rc;
                }
                rc = fapiPutScom(i_target, l_value, l_shmoo1ab);
                if (rc) return rc;
                i_content_array[l_index] = l_shmoo1ab.getDoubleWord(0);
            }
        }
        else if (i_mode == 1)
        {
            FAPI_INF("%s: Restoring DP18 data bit direction register contents",
                     i_target.toEcmdString());
            for (l_index = 0; l_index < MAX_BYTE; l_index++)
            {
                l_val_u64 = i_content_array[l_index];
                l_value = l_Databitdir[l_index];
                rc_num = l_shmoo1ab.setDoubleWord(0, l_val_u64);
                if (rc_num)
                {
                    FAPI_ERR("Error in function  shmoo_save_rest:");
                    rc.setEcmdError(rc_num);
                    return rc;
                }
                rc = fapiPutScom(i_target, l_value, l_shmoo1ab);
                if (rc) return rc;
            }
        }
        else
        {
            FAPI_INF("%s:Invalid value of MODE", i_target.toEcmdString());
        }
        return rc;
    }

    /*------------------------------------------------------------------------------
    * Function: sanity_check
    * Description  : do intial mcbist check in nominal and report spd if any bad bit found
    *
    * Parameters: i_target: mba;
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::sanity_check(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        mcbist_mode = QUARTER_SLOW;
        uint8_t l_mcb_status = 0;
        uint8_t l_CDarray0[80] = { 0 };
        uint8_t l_CDarray1[80] = { 0 };
        uint8_t l_byte, l_rnk;
        uint8_t l_nibble;
        uint8_t l_n = 0;
        uint8_t l_p = 0;
        uint8_t rank = 0;
        uint8_t l_faulted_rank = 255;
        uint8_t l_faulted_port = 255;
        uint8_t l_faulted_dimm = 255;
        uint8_t l_memory_health = 0;
        uint8_t l_max_byte = 10;

        struct Subtest_info l_sub_info[30];

        rc = schmoo_setup_mcb(i_target);
        if (rc) return rc;
        //FAPI_INF("%s:  starting  mcbist now",i_target.toEcmdString());
        rc = start_mcb(i_target);
        if (rc) return rc;
        //FAPI_INF("%s:  polling   mcbist now",i_target.toEcmdString());
        rc = poll_mcb(i_target, &l_mcb_status, l_sub_info, 1);
        if (rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: POLL MCBIST failed !!");
            return rc;
        }
        //FAPI_INF("%s:  checking error map ",i_target.toEcmdString());
        rc = mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1,
                           count_bad_dq);
        if (rc) return rc;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {   // Byte loop
                rank = valid_rank1[l_p][l_rnk];

                l_n = 0;
                for (l_byte = 0; l_byte < l_max_byte; l_byte++)
                {
                    //Nibble loop
                    for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                    {
                        if (mcbist_error_map[l_p][rank][l_byte][l_nibble] == 1)
                        {
                            l_memory_health = 1;
                            l_faulted_rank = rank;
                            l_faulted_port = l_p;
                            if(rank>3) {
                                l_faulted_dimm = 1;
                            } else {
                                l_faulted_dimm = 0;
                            }
                            break;
                        }

                        l_n++;

                    }
                }
            }
        }


        //////////////// changed the check condition ... The error call out need to gard the dimm=l_faulted_dimm(0 or 1) //// port=l_faulted_port(0 or 1) target=i_target ...
        if (l_memory_health)
        {
            FAPI_INF("generic_shmoo:sanity_check failed !! MCBIST failed on intial run , memory is not in good state needs investigation port=%d rank=%d dimm=%d",
                     l_faulted_port, l_faulted_rank, l_faulted_dimm);
            const fapi::Target & MBA_CHIPLET = i_target;
            const uint8_t & MBA_PORT_NUMBER = l_faulted_port;
            const uint8_t & MBA_DIMM_NUMBER = l_faulted_dimm;
            FAPI_SET_HWP_ERROR(rc, RC_MSS_GENERIC_SHMOO_MCBIST_FAILED);
            return rc;
        }

        return rc;
    }
    /*------------------------------------------------------------------------------
    * Function: do_mcbist_reset
    * Description  : do mcbist reset
    *
    * Parameters: i_target: mba,iv_port 0/1 , rank 0-7 , byte 0-7, nibble 0/1, pass;
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::do_mcbist_reset(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint32_t rc_num = 0;

        Target i_target_centaur;
        rc = fapiGetParentChip(i_target, i_target_centaur);
        if (rc) return rc;

        ecmdDataBufferBase l_data_buffer_64(64);
        rc_num = l_data_buffer_64.flushTo0();
        if (rc_num)
        {
            FAPI_ERR("Error in function  mcb_reset_trap:");
            rc.setEcmdError(rc_num);
            return rc;
        }
        //PORT - A
        rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBEMA1Q_0x0201166a, l_data_buffer_64);
        if (rc) return (rc);
        rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBEMA2Q_0x0201166b, l_data_buffer_64);
        if (rc) return (rc);
        rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBEMA3Q_0x0201166c, l_data_buffer_64);
        if (rc) return (rc);

        //PORT - B
        rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBEMB1Q_0x0201166d, l_data_buffer_64);
        if (rc) return (rc);
        rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBEMB2Q_0x0201166e, l_data_buffer_64);
        if (rc) return (rc);
        rc = fapiPutScom(i_target_centaur, MBS_MCBIST01_MCBEMB3Q_0x0201166f, l_data_buffer_64);
        if (rc) return (rc);

        // MBS 23
        rc = fapiPutScom(i_target_centaur, 0x0201176a, l_data_buffer_64);
        if (rc) return (rc);
        rc = fapiPutScom(i_target_centaur, 0x0201176b, l_data_buffer_64);
        if (rc) return (rc);
        rc = fapiPutScom(i_target_centaur, 0x0201176c, l_data_buffer_64);
        if (rc) return (rc);

        //PORT - B
        rc = fapiPutScom(i_target_centaur, 0x0201176d, l_data_buffer_64);
        if (rc) return (rc);
        rc = fapiPutScom(i_target_centaur, 0x0201176e, l_data_buffer_64);
        if (rc) return (rc);
        rc = fapiPutScom(i_target_centaur, 0x0201176f, l_data_buffer_64);
        if (rc) return (rc);

        return rc;
    }
    /*------------------------------------------------------------------------------
    * Function: do_mcbist_test
    * Description  : do mcbist check for error on particular nibble
    *
    * Parameters: i_target: mba,iv_port 0/1 , rank 0-7 , byte 0-7, nibble 0/1, pass;
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::do_mcbist_test(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint8_t l_mcb_status = 0;
        struct Subtest_info l_sub_info[30];

        rc = start_mcb(i_target);
        if (rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: Start MCBIST failed !!");
            return rc;
        }
        rc = poll_mcb(i_target, &l_mcb_status, l_sub_info, 1);
        if (rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: POLL MCBIST failed !!");
            return rc;
        }

        return rc;

    }
    /*------------------------------------------------------------------------------
    * Function: check_error_map
    * Description  : used by do_mcbist_test  to check the error map for particular nibble
    *
    * Parameters: iv_port 0/1 , rank 0-7 , byte 0-7, nibble 0/1, pass;
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::check_error_map(const fapi::Target & i_target,
            uint8_t l_p,
            uint8_t &pass)
    {
        fapi::ReturnCode rc;
        uint8_t l_byte,l_rnk;
        uint8_t l_nibble;
        uint8_t l_byte_is;
        uint8_t l_nibble_is;
        uint8_t l_n=0;
        pass=1;
        input_type l_input_type_e =  ISDIMM_DQ;
        uint8_t i_input_index_u8=0;
        uint8_t l_val =0;
        uint8_t rank=0;
        uint8_t l_max_byte=10;
        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};

        if(iv_dmm_type==1)
        {
            l_max_byte=9;
            //l_max_nibble=18;
        }

        rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

            return rc;
        }
        // for (l_p=0;l_p<MAX_PORT;l_p++){
        for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
        {   // Byte loop
            //////
            rank=valid_rank1[l_p][l_rnk];

            l_n=0;
            for(l_byte=0; l_byte<l_max_byte; l_byte++)
            {
                //Nibble loop
                for(l_nibble=0; l_nibble< MAX_NIBBLES; l_nibble++)
                {
                    if(iv_dmm_type==1)
                    {
                        i_input_index_u8=8*l_byte+4*l_nibble;

                        rc=rosetta_map(i_target,l_p,l_input_type_e,i_input_index_u8,0,l_val);
                        if(rc) return rc;

                        l_byte_is=l_val/8;
                        l_nibble_is=l_val%8;
                        if(l_nibble_is>3) {
                            l_nibble_is=1;
                        }
                        else {
                            l_nibble_is=0;
                        }

                        if( mcbist_error_map [l_p][rank][l_byte_is][l_nibble_is] == 1) {
                            schmoo_error_map[l_p][rank][l_n]=1;
                            pass = 1;
                        }
                        else
                        {

                            schmoo_error_map[l_p][rank][l_n]=0;
                            pass = 0;
                        }
                    }
                    else {
                        if( mcbist_error_map [l_p][rank][l_byte][l_nibble] == 1) {

                            schmoo_error_map[l_p][rank][l_n]=1;
                            pass = 1;
                        }
                        else
                        {
                            schmoo_error_map[l_p][rank][l_n]=0;
                            pass = 0;
                        }
                    }
                    l_n++;
                }//end of nibble loop
            }//end byte loop
        }//end rank loop
        //}//end port loop

        return rc;
    }

    fapi::ReturnCode generic_shmoo::check_error_map2(const fapi::Target & i_target,uint8_t port,uint8_t &pass)
    {

        fapi::ReturnCode rc;
        uint8_t l_byte,l_rnk;
        uint8_t l_nibble;
        uint8_t l_byte_is;
        uint8_t l_nibble_is;
        uint8_t l_n=0;
        pass=1;
        uint8_t l_p=0;
        input_type l_input_type_e =  ISDIMM_DQ;
        uint8_t i_input_index_u8=0;
        uint8_t l_val =0;
        uint8_t rank=0;
        uint8_t l_max_byte=10;
        uint8_t l_max_nibble=20;
        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};



        if(iv_dmm_type==1)
        {
            l_max_byte=9;
            l_max_nibble=18;
        }

        rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

            return rc;
        }
        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {   // Byte loop

                rank=valid_rank1[l_p][l_rnk];

                l_n=0;
                for(l_byte=0; l_byte<l_max_byte; l_byte++)
                {
                    //Nibble loop
                    for(l_nibble=0; l_nibble< MAX_NIBBLES; l_nibble++)
                    {
                        if(iv_dmm_type==1)
                        {
                            i_input_index_u8=8*l_byte+4*l_nibble;

                            rc=rosetta_map(i_target,l_p,l_input_type_e,i_input_index_u8,0,l_val);
                            if(rc) return rc;

                            l_byte_is=l_val/8;
                            l_nibble_is=l_val%8;
                            if(l_nibble_is>3) {
                                l_nibble_is=1;
                            }
                            else {
                                l_nibble_is=0;
                            }

                            if( mcbist_error_map [l_p][rank][l_byte_is][l_nibble_is] == 1) {
                                //pass=0;
                                schmoo_error_map[l_p][rank][l_n]=1;

                            }
                            else
                            {

                                schmoo_error_map[l_p][rank][l_n]=0;


                            }

                        } else {


                            if( mcbist_error_map [l_p][rank][l_byte][l_nibble] == 1) {
                                //pass=0;
                                schmoo_error_map[l_p][rank][l_n]=1;
                                //FAPI_INF("We are in error and nibble is %d and rank is %d and port is %d \n",l_n,rank,l_p);
                            }
                            else
                            {

                                schmoo_error_map[l_p][rank][l_n]=0;


                            }
                        }
                        l_n++;
                    }
                }
            }
        }
        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {   // Byte loop
                rank=valid_rank1[l_p][l_rnk];
                for (l_n=0; l_n<l_max_nibble; l_n++) {
                    if(schmoo_error_map[l_p][rank][l_n]==0) {

                        pass=0;
                    }

                }
            }
        }


        return rc;
    }



    /*------------------------------------------------------------------------------
    * Function: init_multi_array
    * Description  : This function do the initialization of various schmoo parameters
    *
    * Parameters: the array address and the initial value
    * ---------------------------------------------------------------------------*/
    void generic_shmoo::init_multi_array(uint16_t(&array)[MAX_DQ],
                                         uint16_t init_val)
    {

        uint8_t l_byte, l_nibble, l_bit;
        uint8_t l_dq = 0;
        // Byte loop

        for (l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
        {   //Nibble loop
            for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
            {
                //Bit loop
                for (l_bit = 0; l_bit < MAX_BITS; l_bit++)
                {
                    l_dq = 8 * l_byte + 4 * l_nibble + l_bit;
                    array[l_dq] = init_val;
                }
            }
        }

    }

    fapi::ReturnCode generic_shmoo::set_all_binary(const fapi::Target & i_target,bound_t bound)
    {

        fapi::ReturnCode rc;
        uint8_t l_rnk,l_byte,l_nibble,l_bit;
        uint8_t l_dq=0;
        uint8_t l_p=0;
        uint32_t l_max=512;
        uint32_t l_max_offset=64;
        uint8_t rank = 0;

        //if RD_EYE
        if(iv_shmoo_type == 8)
        {
            l_max=127;
        }

        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {   // Byte loop

                rank = valid_rank1[l_p][l_rnk];

                for(l_byte=0; l_byte<iv_MAX_BYTES; l_byte++)
                {   //Nibble loop
                    for(l_nibble=0; l_nibble< MAX_NIBBLES; l_nibble++)
                    {
                        //Bit loop
                        for(l_bit=0; l_bit<MAX_BITS; l_bit++)
                        {
                            l_dq=8*l_byte+4*l_nibble+l_bit;


                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq];
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq];

                            if(bound==RIGHT)
                            {
                                if((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_max_offset)>l_max) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]=l_max;
                                }
                                else {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_max_offset;

                                }
                            }

                            else
                            {
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq] > 64)
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_max_offset;

                                }
                                else
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]=0;

                                }
                            }
                        }
                    }
                }
            }
        }
        return rc;
    }


    /*------------------------------------------------------------------------------
    * Function: get_all_noms
    * Description  : This function gets the nominal values for each DQ
    *
    * Parameters: Target:MBA
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::get_all_noms(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk,l_byte,l_nibble,l_bit;
        uint8_t i_rnk=0;
        uint16_t val=0;
        uint8_t l_dq=0;
        uint8_t l_p=0;
        input_type_t l_input_type_e = WR_DQ;
        access_type_t l_access_type_e = READ;
        FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");

        if(iv_shmoo_type == 2)
        {
            l_input_type_e = WR_DQ;
        }
        else if(iv_shmoo_type == 8)
        {
            l_input_type_e = RD_DQ;
        }
        else if(iv_shmoo_type == 16)
        {
            l_input_type_e = RD_DQS;
        }

        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {   // Byte loop
                i_rnk = valid_rank1[l_p][l_rnk];
                for(l_byte=0; l_byte<iv_MAX_BYTES; l_byte++)
                {   //Nibble loop
                    for(l_nibble=0; l_nibble< MAX_NIBBLES; l_nibble++)
                    {
                        //Bit loop
                        for(l_bit=0; l_bit<MAX_BITS; l_bit++)
                        {
                            l_dq=8*l_byte+4*l_nibble+l_bit;
                            //printf("Before access call");
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,i_rnk,l_input_type_e,l_dq,0,val);
                            if(rc) return rc;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rnk].K.nom_val[l_dq]=val;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rnk].K.rb_regval[l_dq]=val;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rnk].K.lb_regval[l_dq]=val;

                        }
                    }
                }
            }
        }
        return rc;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    fapi::ReturnCode generic_shmoo::get_all_noms_dqs(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk;
        uint32_t val=0;
        uint8_t l_p=0;
        uint8_t l_max_nibble=20;
        uint8_t rank=0;
        uint8_t l_n=0;
        FAPI_INF("%s:mss_generic_shmoo : get_all_noms_dqs : Reading in all nominal values and schmoo type=%d \n",i_target.toEcmdString(),1);
        if(iv_dmm_type==1)
        {

            l_max_nibble=18;
        }

        input_type_t l_input_type_e = WR_DQS;
        access_type_t l_access_type_e = READ ;
        FAPI_DBG("mss_generic_shmoo : get_all_noms : Reading in all nominal values");

        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {   // Byte loop

                rank=valid_rank1[l_p][l_rnk];

                for (l_n=0; l_n<l_max_nibble; l_n++) {

                    rc=mss_access_delay_reg(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_n,0,val);
                    if(rc) return rc;
                    SHMOO[1].MBA.P[l_p].S[rank].K.nom_val[l_n]=val;

                }
            }
        }
        return rc;
    }

    /*------------------------------------------------------------------------------
    * Function: knob_update
    * Description  : This is a key function is used to find right and left bound using new algorithm -- there is an option u can chose not to use it by setting a flag
    *
    * Parameters: Target:MBA,bound:RIGHT/LEFT,scenario:type of schmoo,iv_port:0/1,rank:0-7,byte:0-7,nibble:0/1,bit:0-3,pass,
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::knob_update(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase data_buffer_64(64);
        ecmdDataBufferBase data_buffer_64_1(64);
        input_type_t l_input_type_e = WR_DQ;
        uint8_t l_dq=0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n=0;
        uint8_t l_i=0;
        uint8_t l_p=0;
        uint16_t l_delay=0;
        uint16_t l_max_limit=500;
        uint8_t rank=0;
        uint8_t l_rank=0;
        uint8_t l_SCHMOO_NIBBLES=20;
        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }

        //l_SCHMOO_NIBBLES = 2; //temp preet del this
        rc=do_mcbist_reset(i_target);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
            return rc;
        }

        FAPI_INF("Linear in Progress FW --> %d",scenario);

        if(iv_shmoo_type == 2)
        {
            l_input_type_e = WR_DQ;
        }
        else if(iv_shmoo_type == 8)
        {
            l_input_type_e = RD_DQ;
            l_max_limit=127;
        }
        else if(iv_shmoo_type == 4)
        {
            l_input_type_e = WR_DQS;
        }
        //else if(iv_shmoo_type == 16)
        //{l_input_type_e = RD_DQS;}

        for (l_p=0; l_p < 2; l_p++) {
            for(int i=0; i < iv_MAX_RANKS[l_p]; i++) {

                rank = valid_rank1[l_p][i];
                for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                    schmoo_error_map[l_p][rank][l_n]=0;
                }
            }
        }

        if(bound==RIGHT)
        {
            for (l_delay=1; ((pass==0)); l_delay=l_delay+1) {

                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=bit;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {


                            if(schmoo_error_map[l_p][rank][l_n]==0) {

                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;

                            }
                            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
                            if(rc) return rc;


                            if(l_p == 0) {

                                for(l_i=0; l_i<count_bad_dq[0]; l_i++) {

                                    if(l_CDarray0[l_i]==l_dq) {

                                        schmoo_error_map[l_p][rank][l_n]=1;
                                    }
                                }
                            }
                            else {
                                for(l_i=0; l_i<count_bad_dq[1]; l_i++) {

                                    if(l_CDarray1[l_i]==l_dq) {

                                        schmoo_error_map[l_p][rank][l_n]=1;
                                    }
                                }
                            }
                            if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] > l_max_limit) {
                                schmoo_error_map[l_p][rank][l_n]=1;
                            }


                            l_dq=l_dq+4;

                        } //end of nibble
                    } //end of rank
                } //end of port loop

                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 35)
                    break;
            } //end of Delay loop;


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    l_dq=bit;

                    rank=valid_rank1[l_p][l_rank];
                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                        if(rc) return rc;
                        l_dq=l_dq+4;
                    }
                }
            }


        }

        if(bound==LEFT)
        {
            for (l_delay=1; (pass==0); l_delay+=1) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=bit;

                        rank=valid_rank1[l_p][l_rank];

                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {



                            if(schmoo_error_map[l_p][rank][l_n]==0) {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;
                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                            }

                            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
                            if(rc) return rc;

                            if(l_p==0) {
                                for(l_i=0; l_i<count_bad_dq[0]; l_i++) {
                                    if(l_CDarray0[l_i]==l_dq) {
                                        schmoo_error_map[l_p][rank][l_n]=1;
                                    }
                                }
                            } else {
                                for(l_i=0; l_i<count_bad_dq[1]; l_i++) {
                                    if(l_CDarray1[l_i]==l_dq) {
                                        schmoo_error_map[l_p][rank][l_n]=1;
                                    }
                                }
                            }

                            if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] == 0) {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }

                            l_dq=l_dq+4;

                        }
                    }

                }
                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                if (l_delay > 35)
                    break;
            }


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    l_dq=bit;

                    rank=valid_rank1[l_p][l_rank];

                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                        if(rc) return rc;
                        l_dq=l_dq+4;
                    }
                }
            }



        }

        return rc;
    }
    
    //runs the box shmoo going to +5 and -5 ticks
    fapi::ReturnCode generic_shmoo::do_box_shmoo(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase data_buffer_64(64);
	uint8_t l_p;
	uint8_t l_rank;
	uint8_t l_dq;
	uint8_t l_n;
	uint8_t rank=0;
        uint8_t l_SCHMOO_NIBBLES=18;
        input_type_t l_input_type_e = WR_DQ;
        access_type_t l_access_type_e = WRITE;
	
	uint8_t delay_train_step_size;
	rc = FAPI_ATTR_GET( ATTR_MRW_WR_VREF_CHECK_VREF_STEP_SIZE, NULL, delay_train_step_size);
        if(rc) return rc;
	
	for(l_p = 0; l_p < MAX_PORT; l_p++) {

             for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
             {
            	 //l_dq+l_n*4=bit;
            	 //////
            	 rank=valid_rank1[l_p][l_rank];
            	 //printf ("Current Rank : %d",rank );

            	 for(l_dq = 0; l_dq < 4; l_dq++) {
            	     for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
            		SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq+l_n*4]+delay_train_step_size);
            		rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]);
            		if(rc) return rc;
            	     }
            	 }
             }
       }

       rc=do_mcbist_reset(i_target);
       if(rc)
       {
           FAPI_INF("generic_shmoo::find_bound do_mcbist_reset failed");
           return rc;
       }
       rc=do_mcbist_test(i_target);
       if(rc)
       {
           FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
           return rc;
       }

       rc = fapiGetScom(i_target, 0x030106dc, data_buffer_64);
       if (rc) return rc;
       
       if(data_buffer_64.isBitSet(2)) {
          //I do want to send an error out here, because we want to just note the fail and move on in the IPL
	  //this is a margins check - if we fail, that's ok we might have adequate margins to run, but we'll want to note it and move on
          FAPI_ERR("FOUND FAILING MCBIST BIT AT + 0x%02x DELAY and VREF 0x%02x!!!",delay_train_step_size,iv_vref_mul);
       }
       else {
          FAPI_INF("FOUND PASSING MCBIST BIT AT + 0x%02x DELAY and VREF 0x%02x!!!",delay_train_step_size,iv_vref_mul);
       }
       
       for(l_p = 0; l_p < MAX_PORT; l_p++) {

             for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
             {
            	 //l_dq+l_n*4=bit;
            	 //////
            	 rank=valid_rank1[l_p][l_rank];
            	 //printf ("Current Rank : %d",rank );

            	 for(l_dq = 0; l_dq < 4; l_dq++) {
            	     for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
            		SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq+l_n*4]-delay_train_step_size);

            		rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]);
            		if(rc) return rc;
            	     }
            	 }
             }
       }

       
       rc=do_mcbist_reset(i_target);
       if(rc)
       {
           FAPI_INF("generic_shmoo::find_bound do_mcbist_reset failed");
           return rc;
       }
       rc=do_mcbist_test(i_target);
       if(rc)
       {
           FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
           return rc;
       }
		    
       rc = fapiGetScom(i_target, 0x030106dc, data_buffer_64);
       if (rc) return rc;
       
       if(data_buffer_64.isBitSet(2)) {
          //I do want to send an error out here, because we want to just note the fail and move on in the IPL
	  //this is a margins check - if we fail, that's ok we might have adequate margins to run, but we'll want to note it and move on
          FAPI_ERR("FOUND FAILING MCBIST BIT AT - 0x%02x DELAY and VREF 0x%02x!!!",delay_train_step_size,iv_vref_mul);
       }
       else {
          FAPI_INF("FOUND PASSING MCBIST BIT AT - 0x%02x DELAY and VREF 0x%02x!!!",delay_train_step_size,iv_vref_mul);
       }
	
	for(l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
            {
        	//l_dq+l_n*4=bit;
        	//////
        	rank=valid_rank1[l_p][l_rank];
        	//printf("Valid rank of %d %d %d %d %d %d %d %d",valid_rank1[0],valid_rank1[1],valid_rank1[2],valid_rank1[3],valid_rank1[4],valid_rank1[5],valid_rank1[6],valid_rank1[7]);
        	for(l_dq = 0; l_dq < 4; l_dq++) {
        	    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
        		rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq+l_n*4]);
        		if(rc) return rc;
        		//l_dq+l_n*4=l_dq+l_n*4+4;
        	    }
        	}
            }
        }
	return rc;
    }
    

    fapi::ReturnCode generic_shmoo::knob_update_bin(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase data_buffer_64(64);
        ecmdDataBufferBase data_buffer_64_1(64);
        input_type_t l_input_type_e = WR_DQ;
        uint8_t l_dq=0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n=0;
        uint8_t l_i=0;
        uint8_t l_flag_p0=0;
        uint8_t l_flag_p1=0;
        FAPI_INF("Inside - Binary Schmoo FW - %d",scenario);
        uint8_t l_p=0;
        uint8_t rank=0;
        uint8_t l_rank=0;
        uint8_t l_SCHMOO_NIBBLES=20;
        uint8_t l_status=1;
        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }

        if(iv_shmoo_type == 2)
        {
            l_input_type_e = WR_DQ;
        }
        else if(iv_shmoo_type == 8)
        {
            l_input_type_e = RD_DQ;
        }
        else if(iv_shmoo_type == 4)
        {
            l_input_type_e = WR_DQS;
        }
        else if(iv_shmoo_type == 16)
        {
            l_input_type_e = RD_DQS;
        }


        rc=do_mcbist_reset(i_target);
        if(rc)
        {
            FAPI_INF("generic_shmoo::find_bound do_mcbist_reset failed");
            return rc;
        }


        //Reset schmoo_error_map

        for(l_p = 0; l_p < MAX_PORT; l_p++) {
            for(int i=0; i<iv_MAX_RANKS[l_p]; i++) {

                rank=valid_rank1[l_p][i];
                for (l_n=0; l_n < l_SCHMOO_NIBBLES; l_n++) {
                    schmoo_error_map[l_p][rank][l_n]=0;
                    binary_done_map[l_p][rank][l_n]=0;
                }
            }
        }
        int count_cycle = 0;

        if(bound==RIGHT)
        {

            //FAPI_INF("Algorithm is %d vs seq_lin %d\n",algorithm,SEQ_LIN);
            //FAPI_INF("\n.....Inside Right Bound \n");
            for(l_p = 0; l_p < MAX_PORT; l_p++) {
                do {


                    l_status=0;
                    ////////////////////////////////////////////
                    //FAPI_INF("\n +++ Cycle %d +++ ",count_cycle);
                    //FAPI_INF(" . . . . .");

                    ////////////////////////////////////////////


                    //FAPI_INF("\nMBA = %d",l_mba);
                    rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
                    if(rc) return rc;


                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=bit;
                        //////
                        rank=valid_rank1[l_p][l_rank];
                        //FAPI_INF ("Current Rank : %d",rank );


                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            if(binary_done_map[l_p][rank][l_n]==0) {
                                l_status=1;
                            }
                            l_flag_p0=0;
                            l_flag_p1=0;
                            if(l_p == 0) {
                                for(l_i=0; l_i<count_bad_dq[0]; l_i++) {
                                    if(l_CDarray0[l_i]==l_dq) {
                                        schmoo_error_map[l_p][rank][l_n]=1;
                                        l_flag_p0=1;
                                        //FAPI_INF(" \n I port=%d am the culprit %d ",l_p,l_dq);
                                        //SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+1;
                                    }
                                }
                            } else {
                                for(l_i=0; l_i<count_bad_dq[1]; l_i++) {

                                    if(l_CDarray1[l_i]==l_dq) {
                                        schmoo_error_map[l_p][rank][l_n]=1;
                                        l_flag_p1=1;

                                    }
                                }
                            }

                            if(schmoo_error_map[l_p][rank][l_n]==0) {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq];
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq])/2;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]);
                                if(rc) return rc;
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                }
                                else {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq];
                                }

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]<=1) {
                                    binary_done_map[l_p][rank][l_n]=1;
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                    // FAPI_INF("\n the right bound for port=%d rank=%d dq=%d is %d \n",l_p,rank,l_dq,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]);
                                }
                            }
                            else {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq];
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq])/2;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]);
                                if(rc) return rc;
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                } else {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq];
                                }
                                if(l_p==0) {
                                    if(l_flag_p0==1) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=1;
                                    }
                                }
                                else {
                                    if(l_flag_p1==1) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=1;
                                    }
                                }

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]<=1) {
                                    binary_done_map[l_p][rank][l_n]=1;
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];

                                }
                            }
                            l_dq=l_dq+4;
                        }
                    }


                    rc=do_mcbist_reset(i_target);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_reset failed");
                        return rc;
                    }
                    rc=do_mcbist_test(i_target);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
                        return rc;
                    }

                    rc=check_error_map(i_target,l_p,pass);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
                        return rc;
                    }
                    //printf("\n the status =%d \n",l_status);
                    count_cycle++;
                } while(l_status==1);
            }

            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    l_dq=bit;
                    //////
                    rank=valid_rank1[l_p][l_rank];

                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                        if(rc) return rc;
                        l_dq=l_dq+4;
                    }
                }
            }




        }
        count_cycle = 0;
        if(bound==LEFT)
        {
            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                l_status = 1;

                while(l_status==1)
                {
                    l_status=0;

                    rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
                    if(rc) return rc;

                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++) {
                        l_dq=bit;
                        //////
                        rank=valid_rank1[l_p][l_rank];

                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {

                            if(binary_done_map[l_p][rank][l_n]==0) {
                                l_status=1;
                            }

                            l_flag_p0=0;
                            l_flag_p1=0;
                            if(l_p == 0) {
                                for(l_i=0; l_i<count_bad_dq[0]; l_i++) {
                                    if(l_CDarray0[l_i]==l_dq) {
                                        schmoo_error_map[l_p][rank][l_n]=1;
                                        l_flag_p0=1;

                                    }
                                }
                            }
                            else {
                                for(l_i=0; l_i<count_bad_dq[1]; l_i++) {

                                    if(l_CDarray1[l_i]==l_dq) {
                                        schmoo_error_map[l_p][rank][l_n]=1;
                                        l_flag_p1=1;

                                    }
                                }
                            }

                            if(schmoo_error_map[l_p][rank][l_n]==0) {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq];
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq])/2;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]);
                                if(rc) return rc;
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                } else {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq];
                                }
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]<=1) {
                                    binary_done_map[l_p][rank][l_n]=1;
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];

                                }
                            } else {

                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq];
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq])/2;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq]);
                                if(rc) return rc;
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];
                                } else {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq];
                                }


                                if(l_p==0) {
                                    if(l_flag_p0==1) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=1;
                                    }
                                }
                                else {
                                    if(l_flag_p1==1) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]=1;
                                    }
                                }

                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq]<=1) {
                                    binary_done_map[l_p][rank][l_n]=1;
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq];

                                }
                            }
                            l_dq=l_dq+4;
                        }
                    }
                    rc=do_mcbist_reset(i_target);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_reset failed");
                        return rc;
                    }
                    rc=do_mcbist_test(i_target);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
                        return rc;
                    }

                    rc=check_error_map(i_target,l_p,pass);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
                        return rc;
                    }

                    count_cycle++;
                }
            }

            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    l_dq=bit;
                    //////
                    rank=valid_rank1[l_p][l_rank];
                    //printf("Valid rank of %d %d %d %d %d %d %d %d",valid_rank1[0],valid_rank1[1],valid_rank1[2],valid_rank1[3],valid_rank1[4],valid_rank1[5],valid_rank1[6],valid_rank1[7]);

                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                        if(rc) return rc;
                        l_dq=l_dq+4;
                    }
                }
            }

        } // End of LEFT


        return rc;
    }

    /*------------------------------------------------------------------------------
    * Function: knob_update_dqs
    * Description  : This is a key function is used to find right and left bound using new algorithm -- there is an option u can chose not to use it by setting a flag
    *
    * Parameters: Target:MBA,bound:RIGHT/LEFT,iv_SHMOO_ON:type of schmoo,iv_port:0/1,rank:0-7,byte:0-7,nibble:0/1,bit:0-3,pass,
    * --------------------------------------------------------------------------- */
    fapi::ReturnCode generic_shmoo::knob_update_dqs_by4(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase data_buffer_64(64);
        ecmdDataBufferBase data_buffer_64_1(64);

        input_type_t l_input_type_e = WR_DQ;
        input_type_t l_input_type_e_dqs = WR_DQS;
        uint8_t l_dq=0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n=0;
        uint8_t l_dqs=1;
        uint8_t l_p=0;
        uint8_t l_i=0;
        uint16_t l_delay=0;
        //uint32_t l_max=0;
        uint16_t l_max_limit=500;
        uint8_t rank=0;
        uint8_t l_rank=0;
        uint8_t l_SCHMOO_NIBBLES=20;

        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};
        FAPI_INF("\nWRT_DQS --- > CDIMM  X4 - Scenario = %d",scenario);

        rc=do_mcbist_test(i_target);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
            return rc;
        }

        rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

            return rc;
        }

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }


        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for(int i=0; i<iv_MAX_RANKS[l_p]; i++) {

                rank=valid_rank1[l_p][i];
                for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                    schmoo_error_map[l_p][rank][l_n]=0;
                }
            }
        }

        if(bound==RIGHT)
        {

            for (l_delay=1; ((pass==0)); l_delay++) {

                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=0;

                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            l_dq=4*l_n;
                            if(l_p == 0) {

                                for(l_i=0; l_i<count_bad_dq[0]; l_i++) {

                                    if(l_CDarray0[l_i]==l_dq) {

                                        schmoo_error_map[l_p][rank][l_n]=1;
                                    }
                                }
                            } else {
                                for(l_i=0; l_i<count_bad_dq[1]; l_i++) {

                                    if(l_CDarray1[l_i]==l_dq) {

                                        schmoo_error_map[l_p][rank][l_n]=1;
                                    }
                                }
                            }
                            if(schmoo_error_map[l_p][rank][l_n]==0) {

                                SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n]);
                                if(rc) return rc;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                            }

                            if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dq] > l_max_limit) {
                                schmoo_error_map[l_p][rank][l_n]=1;
                            }

                        }


                    }

                }

                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 70)
                    break;
            } //end of delay


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {


                    rank=valid_rank1[l_p][l_rank];

                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {

                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]);
                        if(rc) return rc;

                    }
                }
            }
            for(int l_bit=0; l_bit<4; l_bit++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=l_bit;

                        rank=valid_rank1[l_p][l_rank];

                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                            if(rc) return rc;
                            l_dq=l_dq+4;
                        }
                    }
                }
            }
            rc=do_mcbist_test(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                return rc;
            }

            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

                return rc;
            }



        }

        if(bound==LEFT)
        {


            for (l_delay=1; (pass==0); l_delay++) {

                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=0;

                        rank=valid_rank1[l_p][l_rank];

                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            l_dq=4*l_n;

                            if(l_p == 0) {

                                for(l_i=0; l_i<count_bad_dq[0]; l_i++) {

                                    if(l_CDarray0[l_i]==l_dq) {

                                        schmoo_error_map[l_p][rank][l_n]=1;
                                    }
                                }
                            } else {
                                for(l_i=0; l_i<count_bad_dq[1]; l_i++) {

                                    if(l_CDarray1[l_i]==l_dq) {

                                        schmoo_error_map[l_p][rank][l_n]=1;
                                    }
                                }
                            }
                            if(schmoo_error_map[l_p][rank][l_n]==0) {
                                SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]-l_delay;
                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n]);
                                if(rc) return rc;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                            }
                            if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n] == 0) {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }



                        }
                    }

                }
                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 70)
                    break;

            }


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank=valid_rank1[l_p][l_rank];
                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]);
                        if(rc) return rc;

                    }
                }
            }

            for(int l_bit=0; l_bit<4; l_bit++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=l_bit;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                            if(rc) return rc;
                            l_dq=l_dq+4;
                        }
                    }
                }
            }

            rc=do_mcbist_test(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                return rc;
            }

            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");
                return rc;
            }
        }
        return rc;
    }
    fapi::ReturnCode generic_shmoo::knob_update_dqs_by4_isdimm(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase data_buffer_64(64);
        ecmdDataBufferBase data_buffer_64_1(64);
        //uint8_t  l_rp=0;
        input_type_t l_input_type_e = WR_DQ;
        input_type_t l_input_type_e_dqs = WR_DQS;
        uint8_t l_dq=0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n=0;
        uint8_t l_dqs=1;
        uint8_t l_my_dqs=0;
        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};
        uint8_t l_p=0;
        uint16_t l_delay=0;
        uint16_t l_max_limit=500;
        uint8_t rank=0;
        uint8_t l_rank=0;
        uint8_t l_SCHMOO_NIBBLES=20;
        //uint8_t i_rp=0;

        rc=do_mcbist_test(i_target);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
            return rc;
        }

        rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

            return rc;
        }

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }
        uint8_t l_dqs_arr[18]= {0,9,1,10,2,11,3,12,4,13,5,14,6,15,7,16,8,17};


        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for(int i=0; i<iv_MAX_RANKS[l_p]; i++) {

                rank=valid_rank1[l_p][i];
                for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                    schmoo_error_map[l_p][rank][l_n]=0;
                }
            }
        }



        if(bound==RIGHT)
        {

            for (l_delay=1; ((pass==0)); l_delay++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=0;
                        l_my_dqs=0;

                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            l_dq=4*l_n;
                            l_my_dqs=l_dqs_arr[l_n];
                            if(schmoo_error_map[l_p][rank][l_n]==0) {

                                SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_my_dqs,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_my_dqs]);
                                if(rc) return rc;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                            }

                            if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dq]>l_max_limit) {
                                schmoo_error_map[l_p][rank][l_n]=1;
                            }
                        } //end of nibble loop
                    } //end of rank
                } //end of port

                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 70)
                    break;

            } //end of delay loop

            //////////////////////////////////////////////////////////////

            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank=valid_rank1[l_p][l_rank];
                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]);
                        if(rc) return rc;
                    }
                }
            }

            for(int l_bit=0; l_bit<4; l_bit++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=l_bit;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                            if(rc) return rc;
                            l_dq=l_dq+4;
                        }
                    } //end of rank
                } //end of port
            } //end of bit

            rc=do_mcbist_test(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                return rc;
            }

            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

                return rc;
            }
        }

        if(bound==LEFT)
        {
            for (l_delay=1; (pass==0); l_delay++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=0;
                        l_my_dqs=0;

                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            l_dq=4*l_n;
                            l_my_dqs=l_dqs_arr[l_n];

                            if(schmoo_error_map[l_p][rank][l_n]==0) {
                                SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_my_dqs]=SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_my_dqs]-l_delay;
                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_my_dqs,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_my_dqs]);
                                if(rc) return rc;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                            }

                            if(SHMOO[l_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dq] == 0) {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                            }
                        }
                    }
                }

                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 70)
                    break;
            } //end of delay loop


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank=valid_rank1[l_p][l_rank];
                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]);
                        if(rc) return rc;
                    }
                }
            }

            for(int l_bit=0; l_bit<4; l_bit++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=l_bit;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                            if(rc) return rc;
                            l_dq=l_dq+4;
                        } //end of nibble
                    } //end of rank
                } //port loop
            } //bit loop

            rc=do_mcbist_test(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                return rc;
            }

            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

                return rc;
            }
        } //end of Left
        return rc;
    }

    fapi::ReturnCode generic_shmoo::knob_update_dqs_by8(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase data_buffer_64(64);
        ecmdDataBufferBase data_buffer_64_1(64);
        //uint8_t  l_rp=0;
        input_type_t l_input_type_e = WR_DQ;
        input_type_t l_input_type_e_dqs = WR_DQS;
        uint8_t l_dq=0;
        uint8_t l_dqs=0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n=0;
        uint8_t l_scen_dqs=1;
        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};
        uint8_t l_p=0;
        uint16_t l_delay=0;
        uint16_t l_max_limit=500;
        uint8_t rank=0;
        uint8_t l_rank=0;
        uint8_t l_SCHMOO_NIBBLES=20;

        FAPI_INF("\nWRT_DQS --- > CDIMM  X8 - Scenario = %d",scenario);
        rc=do_mcbist_test(i_target);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
            return rc;
        }

        rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");
            return rc;
        }

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }

        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for(int i=0; i<iv_MAX_RANKS[l_p]; i++) {

                rank=valid_rank1[l_p][i];
                for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                    schmoo_error_map[l_p][rank][l_n]=0;
                } //end of nib
            } //end of rank
        } //end of port loop

        if(bound==RIGHT)
        {
            for (l_delay=1; ((pass==0)); l_delay++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=0;
                        l_dqs=0;

                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            l_dq=4*l_n;
                            if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)) {
                                //Increase delay of DQS
                                SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]+l_delay;
                                //Write it to register DQS delay
                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_n]);
                                if(rc) return rc;

                                //Increase Delay of DQ
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;
                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;

                                l_dq=l_dq+1;

                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;
                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;

                            }

                            if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq] > l_max_limit) {
                                schmoo_error_map[l_p][rank][l_n]=1;
                                schmoo_error_map[l_p][rank][l_n+1]=1;
                            }

                            if((schmoo_error_map[l_p][rank][l_n]==1)||(schmoo_error_map[l_p][rank][l_n+1]==1)) {

                                schmoo_error_map[l_p][rank][l_n]=1;
                                schmoo_error_map[l_p][rank][l_n+1]=1;
                            }
                            l_n=l_n+1;
                            l_dqs=l_dqs+1;

                        } //end of nibble loop
                    } //end of rank loop
                } //end of port loop


                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 70)
                    break;
            } //end of delay loop


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {   rank=valid_rank1[l_p][l_rank];
                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {

                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]);
                        if(rc) return rc;

                    } //end of nib
                } //end of rank
            } //end of port loop

            for(int l_bit=0; l_bit<4; l_bit++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=l_bit;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                            if(rc) return rc;
                            l_dq=l_dq+4;
                        } //end of nib
                    } //end of rank
                } //end of port loop
            } //end of bit loop

            rc=do_mcbist_test(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                return rc;
            }

            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

                return rc;
            }
        }

        if(bound==LEFT)
        {
            for (l_delay=1; (pass==0); l_delay++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=0;
                        l_dqs=0;

                        rank=valid_rank1[l_p][l_rank];

                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            l_dq=4*l_n;



                            if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)) {
                                SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]-l_delay;
                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_n]);
                                if(rc) return rc;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                            }
                            if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq] == 0) {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n+1] = 1;
                            }

                            if((schmoo_error_map[l_p][rank][l_n]==1)||(schmoo_error_map[l_p][rank][l_n+1]==1)) {

                                schmoo_error_map[l_p][rank][l_n]=1;
                                schmoo_error_map[l_p][rank][l_n+1]=1;
                            }

                            l_n=l_n+1;
                            l_dqs=l_dq+1;

                        }  //nibble loop
                    } //rank loop
                } //port loop

                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 70)
                    break;

            } //end of l delay loop


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank=valid_rank1[l_p][l_rank];
                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]);
                        if(rc) return rc;

                    }
                }
            }

            for(int l_bit=0; l_bit<4; l_bit++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=l_bit;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                            if(rc) return rc;
                            l_dq=l_dq+4;
                        }
                    }
                }
            }

            rc=do_mcbist_test(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                return rc;
            }

            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

                return rc;
            }
        } //end of bound Left

        return rc;
    }
    fapi::ReturnCode generic_shmoo::knob_update_dqs_by8_isdimm(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
    {
        fapi::ReturnCode rc;
        ecmdDataBufferBase data_buffer_64(64);
        ecmdDataBufferBase data_buffer_64_1(64);
        //uint8_t  l_rp=0;
        input_type_t l_input_type_e = WR_DQ;
        input_type_t l_input_type_e_dqs = WR_DQS;
        uint8_t l_dq=0;
        uint8_t l_dqs=0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_n=0;
        uint8_t l_scen_dqs=1;
        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};
        uint8_t l_p=0;
        uint16_t l_delay=0;
        uint16_t l_max_limit=500;
        uint8_t rank=0;
        uint8_t l_rank=0;
        uint8_t l_SCHMOO_NIBBLES=20;
        //uint8_t i_rp=0;

        rc=do_mcbist_test(i_target);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
            return rc;
        }

        rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
        if(rc)
        {
            FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

            return rc;
        }

        if(iv_dmm_type==1)
        {

            l_SCHMOO_NIBBLES=18;
        }


        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for(int i=0; i<iv_MAX_RANKS[l_p]; i++) {

                rank=valid_rank1[l_p][i];
                for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                    schmoo_error_map[l_p][rank][l_n]=0;
                }
            }
        }

        if(bound==RIGHT)
        {

            for (l_delay=1; ((pass==0)); l_delay++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=0;
                        l_dqs=0;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            l_dq=4*l_n;
                            l_dqs=l_n/2;

                            if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)) {

                                SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_dqs,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs]);
                                if(rc) return rc;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]+l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq]);
                                if(rc) return rc;

                            }

                            if(SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.rb_regval[l_dqs]>l_max_limit) {

                                schmoo_error_map[l_p][rank][l_n]=1;
                                schmoo_error_map[l_p][rank][l_n+1]=1;
                            }

                            if((schmoo_error_map[l_p][rank][l_n]==1)||(schmoo_error_map[l_p][rank][l_n+1]==1)) {

                                schmoo_error_map[l_p][rank][l_n]=1;
                                schmoo_error_map[l_p][rank][l_n+1]=1;
                            }

                            l_n=l_n+1;

                        }


                    }

                }
                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 70)
                    break;
            }


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank=valid_rank1[l_p][l_rank];
                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]);
                        if(rc) return rc;
                    }
                }
            }

            for(int l_bit=0; l_bit<4; l_bit++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=l_bit;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                            if(rc) return rc;
                            l_dq=l_dq+4;
                        }
                    }
                }
            }

            rc=do_mcbist_test(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                return rc;
            }

            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

                return rc;
            }

        }

        if(bound==LEFT)
        {

            for (l_delay=1; (pass==0); l_delay++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=0;
                        l_dqs=0;
                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            l_dq=4*l_n;

                            l_dqs=l_n/2;

                            if((schmoo_error_map[l_p][rank][l_n]==0)&&(schmoo_error_map[l_p][rank][l_n+1]==0)) {
                                SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs]=SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_dqs]-l_delay;
                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_dqs,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs]);
                                if(rc) return rc;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                                l_dq=l_dq+1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]-l_delay;

                                rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq]);
                                if(rc) return rc;
                            }
                            if(SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.lb_regval[l_dqs] == 0) {
                                schmoo_error_map[l_p][rank][l_n] = 1;
                                schmoo_error_map[l_p][rank][l_n+1] = 1;
                            }

                            if((schmoo_error_map[l_p][rank][l_n]==1)||(schmoo_error_map[l_p][rank][l_n+1]==1)) {

                                schmoo_error_map[l_p][rank][l_n]=1;
                                schmoo_error_map[l_p][rank][l_n+1]=1;
                            }

                            l_n=l_n+1;

                        } //nibble loop
                    } //rank loop
                } //port loop

                rc=do_mcbist_test(i_target);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }

                rc=check_error_map2(i_target,l_p,pass);
                if(rc)
                {
                    FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                    return rc;
                }
                if (l_delay > 70)
                    break;

            }


            for (l_p=0; l_p<MAX_PORT; l_p++) {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    rank=valid_rank[l_rank];
                    for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {

                        rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e_dqs,l_n,0,SHMOO[l_scen_dqs].MBA.P[l_p].S[rank].K.nom_val[l_n]);
                        if(rc) return rc;

                    }
                }
            }

            for(int l_bit=0; l_bit<4; l_bit++) {
                for (l_p=0; l_p<MAX_PORT; l_p++) {
                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        l_dq=l_bit;

                        rank=valid_rank1[l_p][l_rank];
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq]);
                            if(rc) return rc;
                            l_dq=l_dq+4;
                        }
                    } //rank loop
                } //port loop
            } //bit loop

            rc=do_mcbist_test(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_test failed");
                return rc;
            }

            rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::do_mcbist_test: mcb_error_map failed!!");

                return rc;
            }

        } //end of LEFT

        return rc;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*------------------------------------------------------------------------------
    * Function: find_bound
    * Description  : This function calls the knob_update for each DQ which is used to find bound  that is left/right according to schmoo type
    *
    * Parameters: Target:MBA,bound:RIGHT/LEFT,
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::find_bound(const fapi::Target & i_target,
            bound_t bound)
    {
        uint8_t l_bit = 0;
        fapi::ReturnCode rc;
        uint8_t l_comp = 0;
        uint8_t pass = 0;
        uint8_t l_dram_width = 0;
        bool flag = false;

        rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_dram_width);
        if (rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_SCHMOO_MODE, &i_target, l_comp);
        if(rc) return rc;

        FAPI_INF("%s:\n SCHMOO IS IN PROGRESS ...... \n", i_target.toEcmdString());

        //WRT_DQS Portion
        if(iv_DQS_ON == 1)
        {
            rc=do_mcbist_reset(i_target);
            if(rc)
            {
                FAPI_ERR("generic_shmoo::find_bound do_mcbist_reset failed");
                return rc;
            }
            pass=0;
            if(l_dram_width == 4) {
                if(iv_dmm_type==1)
                {
                    rc=knob_update_dqs_by4_isdimm(i_target,bound,iv_shmoo_type,l_bit,pass,flag);
                    if(rc) return rc;
                }
                else {
                    rc=knob_update_dqs_by4(i_target,bound,iv_shmoo_type,l_bit,pass,flag);
                    if(rc) return rc;
                }
            } //end of if dram_width 4
            else {
                if(iv_dmm_type==1)
                {
                    rc=knob_update_dqs_by8_isdimm(i_target,bound,iv_shmoo_type,l_bit,pass,flag);
                    if(rc) return rc;
                }
                else {
                    rc=knob_update_dqs_by8(i_target,bound,iv_shmoo_type,l_bit,pass,flag);
                    if(rc) return rc;
                }
            }
        } //end of if iv_DQS_ON 1 or WRT_DQS

        else if(l_comp == 6) {
            pass=0;
            rc=knob_update_bin_composite(i_target,bound,iv_shmoo_type,l_bit,pass,flag);
            if(rc) return rc;
        }
        else
        {
            //Bit loop
            for (l_bit = 0; l_bit < MAX_BITS; l_bit++)
            {
                // preetham function here
                pass = 0;

                ////////////////////////////////////////////////////////////////////////////////////
                if (l_comp  == 4)
                {
                    FAPI_INF("Calling Binary - %d",iv_shmoo_type);
                    rc = knob_update_bin(i_target, bound, iv_shmoo_type, l_bit, pass, flag);
                    if (rc) return rc;
                }
                else
                {


                    rc = knob_update(i_target, bound, iv_shmoo_type, l_bit, pass, flag);
                    if (rc) return rc;
                }
            }
        }

        return rc;
    }
    /*------------------------------------------------------------------------------
    * Function: print_report
    * Description  : This function is used to print the information needed such as freq,voltage etc, and also the right,left and total margin
    *
    * Parameters: Target:MBA
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::print_report(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;

        uint8_t l_rnk,l_byte,l_nibble,l_bit;
        uint8_t l_dq=0;
        //uint8_t l_rp=0;
        uint8_t l_p=0;
        uint8_t i_rank=0;
        uint8_t l_mbapos = 0;
        uint32_t l_attr_mss_freq_u32 = 0;
        uint32_t l_attr_mss_volt_u32 = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
        uint8_t l_attr_eff_dram_width_u8 = 0;

        fapi::Target l_target_centaur;


        rc = fapiGetParentChip(i_target, l_target_centaur);
        if(rc) return rc;

        rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target, l_attr_eff_dimm_type_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target, l_attr_eff_num_drops_per_port_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_attr_eff_dram_width_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbapos);
        if(rc) return rc;



        FAPI_INF("%s:freq = %d on %s.",i_target.toEcmdString(),l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
        FAPI_INF("%s: volt = %d on %s.",i_target.toEcmdString(), l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
        FAPI_INF("%s: dimm_type = %d on %s.",i_target.toEcmdString(), l_attr_eff_dimm_type_u8, i_target.toEcmdString());
        if ( l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES )
        {
            FAPI_INF("%s: It is a CDIMM",i_target.toEcmdString());
        }
        else
        {
            FAPI_INF("%s: It is an ISDIMM",i_target.toEcmdString());
        }
        FAPI_INF("%s: \n Number of ranks on port = 0 is %d ",i_target.toEcmdString(),iv_MAX_RANKS[0]);
        FAPI_INF("%s: \n Number of ranks on port = 1 is %d \n \n",i_target.toEcmdString(),iv_MAX_RANKS[1]);
        FAPI_INF("%s:+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",i_target.toEcmdString());
        //// Based on schmoo param the print will change eventually
        if(iv_shmoo_type==2)
        {
            FAPI_INF("%s:Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ",i_target.toEcmdString());
        }
        else {
            FAPI_INF("%s:Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit\tRdD_Setup(ps)\tRdD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ",i_target.toEcmdString());
        }


        for (l_p=0; l_p < 2; l_p++) {
            for (l_rnk=0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {   i_rank = valid_rank1[l_p][l_rnk];
                for(l_byte=0; l_byte < 10; l_byte++)
                {

                    //Nibble loop
                    for(l_nibble=0; l_nibble< 2; l_nibble++)
                    {
                        for(l_bit=0; l_bit< 4; l_bit++)
                        {
                            l_dq=8*l_byte+4*l_nibble+l_bit;

                            if(iv_shmoo_type==2)
                            {
                                FAPI_INF("%s:WR_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",i_target.toEcmdString(),l_mbapos,l_p,i_rank,l_byte,l_nibble,l_bit,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_dq],l_attr_mss_freq_u32,iv_vref_mul);
                            }
                            if(iv_shmoo_type==8)
                            {
                                FAPI_INF("%s:RD_EYE %d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",i_target.toEcmdString(),l_mbapos,l_p,i_rank,l_byte,l_nibble,l_bit,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_dq],l_attr_mss_freq_u32,iv_vref_mul);
                            }

                        }
                    }
                }
            }
        }

        return rc;
    }

    fapi::ReturnCode generic_shmoo::print_report_dqs(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;

        uint8_t l_rnk, l_nibble;
        uint8_t l_p = 0;
        uint8_t i_rank = 0;
        uint8_t l_mbapos = 0;
        uint16_t l_total_margin = 0;
        uint32_t l_attr_mss_freq_u32 = 0;
        uint32_t l_attr_mss_volt_u32 = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
        uint8_t l_attr_eff_dram_width_u8 = 0;
        fapi::Target l_target_centaur;
        uint8_t l_SCHMOO_NIBBLES = 20;
        uint8_t l_by8_dqs = 0;
        char * l_pMike = new char[128];
        char * l_str = new char[128];

        uint8_t l_i = 0;
        uint8_t l_dq = 0;
        uint8_t l_flag = 0;
        uint8_t l_CDarray0[80] = { 0 };
        uint8_t l_CDarray1[80] = { 0 };

        rc = mcb_error_map(i_target, mcbist_error_map, l_CDarray0, l_CDarray1,
                           count_bad_dq);
        if (rc)
        {
            FAPI_ERR("generic_shmoo::print report: mcb_error_map failed!!");
            return rc;
        }

        if (iv_dmm_type == 1)
        {
            l_SCHMOO_NIBBLES = 18;
        }

        rc = fapiGetParentChip(i_target, l_target_centaur);
        if (rc) return rc;

        rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32);
        if (rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32);
        if (rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target, l_attr_eff_dimm_type_u8);
        if (rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target,
                           l_attr_eff_num_drops_per_port_u8);
        if (rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target,
                           l_attr_eff_dram_width_u8);
        if (rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbapos);
        if (rc) return rc;

        if (l_attr_eff_dram_width_u8 == 8)
        {
            l_SCHMOO_NIBBLES = 10;
            if (iv_dmm_type == 1)
            {
                l_SCHMOO_NIBBLES = 9;
            }
        }

        //FAPI_INF("%s:Shmoonibbles val is=%d",l_SCHMOO_NIBBLES);

        FAPI_INF("%s:      freq = %d on %s.", i_target.toEcmdString(),
                 l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
        FAPI_INF("%s:volt = %d on %s.", i_target.toEcmdString(),
                 l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
        FAPI_INF("%s:dimm_type = %d on %s.", i_target.toEcmdString(),
                 l_attr_eff_dimm_type_u8, i_target.toEcmdString());
        FAPI_INF("%s:\n Number of ranks on port=0 is %d ", i_target.toEcmdString(),
                 iv_MAX_RANKS[0]);
        FAPI_INF("%s:\n Number of ranks on port=1 is %d ", i_target.toEcmdString(),
                 iv_MAX_RANKS[1]);

        if (l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
        {
            FAPI_INF("%s:It is a CDIMM", i_target.toEcmdString());
        }
        else
        {
            FAPI_INF("%s:It is an ISDIMM", i_target.toEcmdString());
        }

        FAPI_INF("%s:\n Number of ranks on port=0 is %d ", i_target.toEcmdString(),
                 iv_MAX_RANKS[0]);
        FAPI_INF("%s:\n Number of ranks on port=1 is %d \n \n",
                 i_target.toEcmdString(), iv_MAX_RANKS[1]);

        FAPI_INF(
            "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        sprintf(l_pMike, "Schmoo  POS\tPort\tRank\tDQS\tNominal\t\ttDQSSmin_PR_limit\ttDQSSmax_PR_limit\ttDQSSmin(ps)\ttDQSSmax(ps)\ttDQSS_Window(ps)\tBitRate  ");
        FAPI_INF("%s", l_pMike);
        delete[] l_pMike;

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                ////

                i_rank = valid_rank1[l_p][l_rnk];
                //
                if (rc) return rc;

                for (l_nibble = 0; l_nibble < l_SCHMOO_NIBBLES; l_nibble++)
                {
                    l_by8_dqs = l_nibble;
                    if (iv_dmm_type == 0)
                    {
                        if (l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble = l_nibble * 2;
                        }
                    }
                    l_dq=4* l_nibble;
                    l_flag=0;
                    if (l_p == 0)
                    {
                        for (l_i = 0; l_i < count_bad_dq[0]; l_i++)
                        {
                            if (l_CDarray0[l_i] == l_dq)
                            {
                                l_flag=1;

                            }
                        }
                    }
                    else
                    {
                        for (l_i = 0; l_i < count_bad_dq[1]; l_i++)
                        {
                            if (l_CDarray1[l_i] == l_dq)
                            {
                                l_flag=1;

                            }
                        }
                    }

                    if(l_flag==1)
                    {
                        continue;
                    }

                    l_total_margin
                        = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble]
                          + SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble];
                    sprintf(l_str, "%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
                            l_mbapos, l_p, i_rank, l_nibble,
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.curr_val[l_nibble],
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble],
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble],
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble],
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble],
                            l_total_margin, l_attr_mss_freq_u32);

                    FAPI_INF("WR_DQS %s", l_str);

                    if (iv_dmm_type == 0)
                    {
                        if (l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble = l_by8_dqs;
                        }
                    }

                }
            }
        }
        delete[] l_str;
        return rc;
    }




    fapi::ReturnCode generic_shmoo::print_report_dqs2(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk,l_nibble;
        uint8_t l_p=0;
        uint8_t i_rank=0;
        uint8_t l_mbapos = 0;
        uint32_t l_attr_mss_freq_u32 = 0;
        uint32_t l_attr_mss_volt_u32 = 0;
        uint8_t l_attr_eff_dimm_type_u8 = 0;
        uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
        uint8_t l_attr_eff_dram_width_u8 = 0;
        fapi::Target l_target_centaur;
        uint8_t l_SCHMOO_NIBBLES=20;
        uint8_t l_by8_dqs=0;


        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }

        rc = fapiGetParentChip(i_target, l_target_centaur);
        if(rc) return rc;

        rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target, l_attr_eff_dimm_type_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target, l_attr_eff_num_drops_per_port_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_attr_eff_dram_width_u8);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbapos);
        if(rc) return rc;

        if(l_attr_eff_dram_width_u8 == 8) {
            l_SCHMOO_NIBBLES=10;
            if(iv_dmm_type==1)
            {
                l_SCHMOO_NIBBLES=9;
            }
        }
        FAPI_INF("%s:freq = %d on %s.",i_target.toEcmdString(), l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
        FAPI_INF("%s:volt = %d on %s.",i_target.toEcmdString(), l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
        FAPI_INF("%s:dimm_type = %d on %s.",i_target.toEcmdString(), l_attr_eff_dimm_type_u8, i_target.toEcmdString());
        FAPI_INF("%s:\n Number of ranks on port=0 is %d ",i_target.toEcmdString(),iv_MAX_RANKS[0]);
        FAPI_INF("%s:\n Number of ranks on port=1 is %d ",i_target.toEcmdString(),iv_MAX_RANKS[1]);


        if ( l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES )
        {
            FAPI_INF("%s:It is a CDIMM",i_target.toEcmdString());
        }
        else
        {
            FAPI_INF("%s:It is an ISDIMM",i_target.toEcmdString());
        }

        FAPI_INF("%s:\n Number of ranks on port=0 is %d ",i_target.toEcmdString(),iv_MAX_RANKS[0]);
        FAPI_INF("%s:\n Number of ranks on port=1 is %d \n \n",i_target.toEcmdString(),iv_MAX_RANKS[1]);

        FAPI_INF("%s:+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",i_target.toEcmdString());
        FAPI_INF("%s:Schmoo  POS\tPort\tRank\tDQS\tNominal\t\ttDQSSmin_PR_limit\ttDQSSmax_PR_limit\ttDQSSmin(ps)\ttDQSSmax(ps)\ttDQSS_Window(ps)\tBitRate  ",i_target.toEcmdString());

        iv_shmoo_type=4;


        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank=valid_rank1[l_p][l_rnk];
                for(l_nibble=0; l_nibble< l_SCHMOO_NIBBLES; l_nibble++)
                {
                    l_by8_dqs=l_nibble;
                    if(iv_dmm_type==0)
                    {
                        if(l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble=l_nibble*2;
                        }
                    }

                    FAPI_INF("%s:WR_DQS %d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n ",i_target.toEcmdString(),l_mbapos,l_p,i_rank,l_nibble,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble],SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_nibble],l_attr_mss_freq_u32);

                    if(iv_dmm_type==0)
                    {
                        if(l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble=l_by8_dqs;
                        }
                    }


                }
            }
        }

        //fclose(fp);
        return rc;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*------------------------------------------------------------------------------
    * Function: get_margin
    * Description  : This function is used to get margin for setup,hold and total eye width in Ps by using frequency
    *
    * Parameters: Target:MBA
    * ---------------------------------------------------------------------------*/
    fapi::ReturnCode generic_shmoo::get_margin(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk, l_byte, l_nibble, l_bit;
        uint32_t l_attr_mss_freq_margin_u32 = 0;
        uint32_t l_freq = 0;
        uint64_t l_cyc = 1000000000000000ULL;
        uint8_t l_dq = 0;
        uint8_t l_p = 0;
        uint8_t i_rank = 0;
        uint64_t l_factor = 0;
        uint64_t l_factor_ps = 1000000000;
        fapi::Target l_target_centaur;
        rc = fapiGetParentChip(i_target, l_target_centaur);
        if (rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur,
                           l_attr_mss_freq_margin_u32);
        if (rc) return rc;
        l_freq = l_attr_mss_freq_margin_u32 / 2;
        l_cyc = l_cyc / l_freq;// converting to zepto to get more accurate data
        l_factor = l_cyc / 128;
        //FAPI_INF("l_factor is % llu ",l_factor);

        for (l_p = 0; l_p < MAX_PORT; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {
                ////

                i_rank = valid_rank1[l_p][l_rnk];
                //
                if (rc) return rc;
                for (l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
                {
                    //Nibble loop
                    for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                    {
                        for (l_bit = 0; l_bit < MAX_BITS; l_bit++)
                        {
                            l_dq = 8 * l_byte + 4 * l_nibble + l_bit;

                            if (iv_shmoo_type == 1)
                            {
                                if (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] == 0)
                                {

                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] = 0;


                                }
                            }

                            if (iv_shmoo_param == 4)
                            {
                                if (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]
                                        > SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]
                                        = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq] - 1;
                                }
                                if (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]
                                        < SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])
                                {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]
                                        = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] + 1;
                                }
                            }
                            else
                            {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]
                                    = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]- 1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]
                                    = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] + 1;
                            }

                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq]
                                = ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]
                                    - SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])
                                   * l_factor) / l_factor_ps;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq]
                                = ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq]
                                    - SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq])
                                   * l_factor) / l_factor_ps;
                        }
                    }
                }
            }
        }

        return rc;
    }

    fapi::ReturnCode generic_shmoo::get_margin2(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk,l_byte,l_nibble,l_bit;
        uint32_t l_attr_mss_freq_margin_u32 = 0;
        uint32_t l_freq=0;
        uint64_t l_cyc = 1000000000000000ULL;
        uint8_t l_dq=0;
        uint8_t  l_p=0;
        uint8_t i_rank=0;
        uint64_t l_factor=0;
        uint64_t l_factor_ps=1000000000;
        fapi::Target l_target_centaur;
        rc = fapiGetParentChip(i_target, l_target_centaur);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_margin_u32);
        if(rc) return rc;
        l_freq=l_attr_mss_freq_margin_u32/2;
        l_cyc=l_cyc/l_freq;// converting to zepto to get more accurate data
        l_factor=l_cyc/128;

        for (l_p=0; l_p< 2; l_p++) {
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {
                //////
                i_rank=valid_rank1[l_p][l_rnk];
                //////
                for(l_byte=0; l_byte< 10; l_byte++)
                {

                    //Nibble loop
                    for(l_nibble=0; l_nibble< 2; l_nibble++)
                    {
                        for(l_bit=0; l_bit< 4; l_bit++)
                        {
                            l_dq=8*l_byte+4*l_nibble+l_bit;

                            if(iv_shmoo_type==8)
                            {
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq] == 0) {

                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]=0;
                                    if((iv_shmoo_param==4)||(iv_shmoo_param==6)) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]-1;
                                    } else {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]-2;
                                    }
                                    //FAPI_INF("\n the value of left bound after is %d \n",SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]);
                                }
                            }

                            if((iv_shmoo_param==4)||(iv_shmoo_param==6)) {
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq]) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]-1;
                                }
                                if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]<SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq]) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]+1;
                                }
                            } else {
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]-1;
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq]+1;
                            }

                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq]=((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq])*l_factor)/l_factor_ps;
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq]= ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq])*l_factor)/l_factor_ps;//((1/uint32_t_freq*1000000)/128);
                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_dq]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq];
                        }
                    }
                }
            }
        }

        return rc;
    }

fapi::ReturnCode generic_shmoo::print_report2(const fapi::Target & i_target)
{
    fapi::ReturnCode rc;

    uint8_t l_rnk, l_byte, l_nibble, l_bit;
    uint8_t l_p = 0;
    uint8_t i_rank = 0;
    uint8_t l_mbapos = 0;
    uint32_t l_attr_mss_freq_u32 = 0;
    uint32_t l_attr_mss_volt_u32 = 0;
    uint8_t l_attr_eff_dimm_type_u8 = 0;
    uint8_t l_attr_eff_num_drops_per_port_u8 = 0;
    uint8_t l_attr_eff_dram_width_u8 = 0;
    uint16_t l_total_margin = 0;
	uint8_t l_dq = 0;
	uint8_t vrefdq_train_value[2][2][4];
	char * l_pMike = new char[128];
    char * l_str = new char[128];
	
	fapi::Target l_target_centaur;

    rc = fapiGetParentChip(i_target, l_target_centaur);
    if (rc) return rc;
	
	uint8_t l_dram_gen = 1;
	uint32_t base_percent = 60000;
	uint32_t index_mul_print = 650;
	uint32_t vref_val_print = 0;
    uint8_t vrefdq_train_range[2][2][4];
	
	rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_RANGE, &i_target, vrefdq_train_range);if(rc) return rc;
	rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_GEN, &i_target, l_dram_gen); if(rc) return rc;
	rc = FAPI_ATTR_GET( ATTR_EFF_VREF_DQ_TRAIN_VALUE, &i_target, vrefdq_train_value); if(rc) return rc;
	if(vrefdq_train_range[0][0][0] == 1)
	{
	base_percent = 45000;
	}
	
	vref_val_print = base_percent + (vrefdq_train_value[0][0][0] * index_mul_print);
    rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_u32);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_MSS_VOLT, &l_target_centaur, l_attr_mss_volt_u32);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_CUSTOM_DIMM, &i_target, l_attr_eff_dimm_type_u8);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_NUM_DROPS_PER_PORT, &i_target,
                       l_attr_eff_num_drops_per_port_u8);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target,
                       l_attr_eff_dram_width_u8);
    if (rc) return rc;
    rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target, l_mbapos);
    if (rc) return rc;

    FAPI_INF("%s: freq = %d on %s.", i_target.toEcmdString(),
             l_attr_mss_freq_u32, l_target_centaur.toEcmdString());
    FAPI_INF("%s: volt = %d on %s.", i_target.toEcmdString(),
             l_attr_mss_volt_u32, l_target_centaur.toEcmdString());
    FAPI_INF("%s: dimm_type = %d on %s.", i_target.toEcmdString(),
             l_attr_eff_dimm_type_u8, i_target.toEcmdString());
	//FAPI_INF("%s: +++ Preet1 %d +++ ", i_target.toEcmdString(),vref_val_print);
			 
    if (l_attr_eff_dimm_type_u8 == fapi::ENUM_ATTR_EFF_CUSTOM_DIMM_YES)
    {
        FAPI_INF("%s: It is a CDIMM", i_target.toEcmdString());
    }
    else
    {
        FAPI_INF("%s: It is an ISDIMM", i_target.toEcmdString());
    }
    FAPI_INF("%s: \n Number of ranks on port = 0 is %d ",
             i_target.toEcmdString(), iv_MAX_RANKS[0]);
    FAPI_INF("%s: \n Number of ranks on port = 1 is %d \n \n",
             i_target.toEcmdString(), iv_MAX_RANKS[1]);

    //FAPI_INF("%s:num_drops_per_port = %d on %s.", l_attr_eff_num_drops_per_port_u8, i_target.toEcmdString());
    //FAPI_INF("%s:num_ranks  = %d on %s.", iv_MAX_RANKS,i_target.toEcmdString());
    FAPI_INF("dram_width = %d  \n\n", l_attr_eff_dram_width_u8);
    FAPI_INF("%s:+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
             i_target.toEcmdString());
    //// Based on schmoo param the print will change eventually

    if (iv_shmoo_type == 0)
    {
        sprintf(l_pMike, "Schmoo  POS\tPort\tRank\tByte\tnibble\t\tSetup_Limit\tHold_Limit\tWrD_Setup(ps)\tWrD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ");
    }
    else
    {
        sprintf(l_pMike, "Schmoo  POS\tPort\tRank\tByte\tnibble\t\tSetup_Limit\tHold_Limit\tRdD_Setup(ps)\tRdD_Hold(ps)\tEye_Width(ps)\tBitRate\tVref_Multiplier  ");
    }
    //FAPI_INF("Schmoo  POS\tPort\tRank\tByte\tnibble\tbit\tNominal\t\tSetup_Limit\tHold_Limit \n");
    FAPI_INF("%s", l_pMike);
    delete[] l_pMike;

    for (l_p = 0; l_p < MAX_PORT; l_p++)
    {
        for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
        {
            
            i_rank = valid_rank1[l_p][l_rnk];
            
            for (l_byte = 0; l_byte < iv_MAX_BYTES; l_byte++)
            {
                //Nibble loop
                for (l_nibble = 0; l_nibble < MAX_NIBBLES; l_nibble++)
                {	
				
                    for (l_bit = 0; l_bit < MAX_BITS; l_bit++) 
                    {
                        l_dq = 8 * l_byte + 4 * l_nibble + l_bit;
                        l_total_margin
                            = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq]
                                + SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq];
								if(l_dram_gen==2)
								{
								sprintf(l_str, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
                                l_mbapos, l_p, i_rank, l_byte, l_nibble, l_bit,
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq],
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq],
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq],
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq],
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq],
                                l_total_margin, l_attr_mss_freq_u32, vref_val_print);
								}
								else 
								{
								sprintf(l_str, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
                                l_mbapos, l_p, i_rank, l_byte, l_nibble, l_bit,
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_dq],
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_dq],
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_dq],
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq],
                                SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq],
                                l_total_margin, l_attr_mss_freq_u32, iv_vref_mul);
								}
                        if (iv_shmoo_type == 2)
                        {
                            FAPI_IMP("WR_EYE %s ", l_str);
                            
                        }
                        if (iv_shmoo_type == 8)
                        {
                            FAPI_IMP("RD_EYE %s ", l_str);
                            
                        }
                    }
                }
            }
        }
    }

    delete[] l_str;
    return rc;
}

    fapi::ReturnCode generic_shmoo::get_margin_dqs_by4(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk;
        uint32_t l_attr_mss_freq_margin_u32 = 0;
        uint32_t l_freq=0;
        uint64_t l_cyc = 1000000000000000ULL;
        uint8_t l_nibble=0;
        uint8_t  l_p=0;
        uint8_t i_rank=0;
        uint64_t l_factor=0;
        uint64_t l_factor_ps=1000000000;
        uint8_t l_SCHMOO_NIBBLES=20;

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }

        //FAPI_INF("   the factor is % llu ",l_cyc);

        fapi::Target l_target_centaur;
        rc = fapiGetParentChip(i_target, l_target_centaur);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_margin_u32);
        if(rc) return rc;
        l_freq=l_attr_mss_freq_margin_u32/2;
        l_cyc=l_cyc/l_freq;// converting to zepto to get more accurate data
        l_factor=l_cyc/128;

        for (l_p=0; l_p<MAX_PORT; l_p++) {

            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank=valid_rank1[l_p][l_rnk];
                //Nibble loop

                for(l_nibble=0; l_nibble<l_SCHMOO_NIBBLES; l_nibble++)
                {
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble]-1;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble]+1;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble]=((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble])*l_factor)/l_factor_ps;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble]= ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble])*l_factor)/l_factor_ps;//((1/uint32_t_freq*1000000)/128);
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_nibble]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble];

                }
            }
        }
        return rc;
    }

    fapi::ReturnCode generic_shmoo::get_margin_dqs_by8(const fapi::Target & i_target)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk;
        uint32_t l_attr_mss_freq_margin_u32 = 0;
        uint32_t l_freq=0;
        uint64_t l_cyc = 1000000000000000ULL;
        //uint8_t l_dq=0;
        uint8_t l_nibble=0;

        uint8_t  l_p=0;
        uint8_t i_rank=0;
        uint64_t l_factor=0;
        uint64_t l_factor_ps=1000000000;
        uint8_t l_SCHMOO_NIBBLES=20;

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=9;
        }

        //FAPI_INF("   the factor is % llu ",l_cyc);

        fapi::Target l_target_centaur;
        rc = fapiGetParentChip(i_target, l_target_centaur);
        if(rc) return rc;
        rc = FAPI_ATTR_GET(ATTR_MSS_FREQ, &l_target_centaur, l_attr_mss_freq_margin_u32);
        if(rc) return rc;
        l_freq=l_attr_mss_freq_margin_u32/2;
        l_cyc=l_cyc/l_freq;// converting to zepto to get more accurate data
        l_factor=l_cyc/128;
        //FAPI_INF("l_factor is % llu ",l_factor);




        for (l_p=0; l_p<MAX_PORT; l_p++) {
            //FAPI_INF("\n Abhijit is here before %d \n",l_p);
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank=valid_rank1[l_p][l_rnk];
                //Nibble loop
                for(l_nibble=0; l_nibble < l_SCHMOO_NIBBLES; l_nibble++)
                {
                    if(iv_dmm_type==0)
                    {
                        if((l_nibble%2)) {
                            continue ;
                        }
                    }

                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble]-1;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble]+1;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble]=((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.rb_regval[l_nibble]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble])*l_factor)/l_factor_ps;
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble]= ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.nom_val[l_nibble]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.lb_regval[l_nibble])*l_factor)/l_factor_ps;//((1/uint32_t_freq*1000000)/128);
                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.total_margin[l_nibble]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble];
                }
            }

        }
        return rc;
    }

    fapi::ReturnCode generic_shmoo::knob_update_bin_composite(const fapi::Target & i_target,bound_t bound,uint8_t scenario,uint8_t bit,uint8_t pass,bool &flag)
    {

        fapi::ReturnCode rc;
        ecmdDataBufferBase data_buffer_64(64);
        ecmdDataBufferBase data_buffer_64_1(64);
        input_type_t l_input_type_e = WR_DQ;
        uint8_t l_n=0;
        access_type_t l_access_type_e = WRITE;
        uint8_t l_dq = 0;
        uint8_t l_i=0;
        uint8_t l_flag_p0=0;
        uint8_t l_flag_p1=0;
        FAPI_INF("SHMOOING VIA COMPOSITE EYE  FW !!!!");
        uint8_t l_p=0;
        uint8_t rank=0;
        uint8_t l_rank=0;
        uint8_t l_SCHMOO_NIBBLES=20;
        uint8_t l_status=1;
        uint8_t l_CDarray0[80]= {0};
        uint8_t l_CDarray1[80]= {0};

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }

        if(iv_shmoo_type == 2)
        {
            l_input_type_e = WR_DQ;
        }
        else if(iv_shmoo_type == 8)
        {
            l_input_type_e = RD_DQ;
        }
        else if(iv_shmoo_type == 4)
        {
            l_input_type_e = WR_DQS;
        }
        else if(iv_shmoo_type == 16)
        {
            l_input_type_e = RD_DQS;
        }

        rc=do_mcbist_reset(i_target);
        if(rc)
        {
            FAPI_INF("generic_shmoo::find_bound do_mcbist_reset failed");
            return rc;
        }


        //Reset schmoo_error_map

        for(l_p = 0; l_p < MAX_PORT; l_p++) {
            for(int i=0; i<iv_MAX_RANKS[l_p]; i++) {

                rank=valid_rank1[l_p][i];
                for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                    schmoo_error_map[l_p][rank][l_n]=0;
                    binary_done_map[l_p][rank][l_n]=0;
                }
            }
        }
        int count_cycle = 0;

        if(bound==RIGHT)
        {

            for(l_p = 0; l_p < MAX_PORT; l_p++) {
                do {


                    l_status=0;


                    rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
                    if(rc) return rc;


                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                    {
                        //l_dq+l_n*4=bit;
                        //////
                        rank=valid_rank1[l_p][l_rank];
                        //printf ("Current Rank : %d",rank );

                        for(l_dq = 0; l_dq < 4; l_dq++) {
                            for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                                if(binary_done_map[l_p][rank][l_n]==0) {
                                    l_status=1;
                                }
                                l_flag_p0=0;
                                l_flag_p1=0;
                                if(l_p == 0) {
                                    for(l_i=0; l_i<count_bad_dq[0]; l_i++) {
                                        if(l_CDarray0[l_i]==l_dq+l_n*4) {
                                            schmoo_error_map[l_p][rank][l_n]=1;
                                            l_flag_p0=1;

                                        }
                                    }
                                } else {
                                    for(l_i=0; l_i<count_bad_dq[1]; l_i++) {

                                        if(l_CDarray1[l_i]==l_dq+l_n*4) {
                                            schmoo_error_map[l_p][rank][l_n]=1;
                                            l_flag_p1=1;

                                        }
                                    }
                                }

                                if(schmoo_error_map[l_p][rank][l_n]==0) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4];
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4])/2;

                                    rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]);
                                    if(rc) return rc;
                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4];
                                    }
                                    else {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4];
                                    }

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]<=1) {
                                        binary_done_map[l_p][rank][l_n]=1;
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4];
                                        // printf("\n the right bound for port=%d rank=%d dq=%d is %d \n",l_p,rank,l_dq+l_n*4,FAPI_INF.MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]);
                                    }
                                }
                                else {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4];
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4])/2;

                                    rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]);
                                    if(rc) return rc;
                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4];
                                    } else {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4];
                                    }
                                    if(l_p==0) {
                                        if(l_flag_p0==1) {
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=1;
                                        }
                                    }
                                    else {
                                        if(l_flag_p1==1) {
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=1;
                                        }
                                    }

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]<=1) {
                                        binary_done_map[l_p][rank][l_n]=1;
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.rb_regval[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4];

                                    }
                                }
                                //l_dq+l_n*4=l_dq+l_n*4+4;
                            }
                        }
                    }


                    rc=do_mcbist_reset(i_target);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_reset failed");
                        return rc;
                    }
                    rc=do_mcbist_test(i_target);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
                        return rc;
                    }

                    rc=check_error_map(i_target,l_p,pass);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
                        return rc;
                    }
                    //FAPI_INF("\n the status =%d \n",l_status);
                    count_cycle++;
                } while(l_status==1);
            }

            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    //l_dq+l_n*4=bit;
                    //////
                    rank=valid_rank1[l_p][l_rank];
                    for(l_dq = 0; l_dq < 4; l_dq++) {
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq+l_n*4]);
                            if(rc) return rc;
                            //l_dq+l_n*4=l_dq+l_n*4+4;
                        }
                    }
                }
            }




        }
        count_cycle = 0;
        if(bound==LEFT)
        {
            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                l_status = 1;
                //printf("\n +++ Inside LEFT bound -- bin ");
                while(l_status==1)
                {
                    l_status=0;


                    rc=mcb_error_map(i_target,mcbist_error_map,l_CDarray0,l_CDarray1,count_bad_dq);
                    if(rc) return rc;

                    for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++) {
                        //l_dq+l_n*4=bit;
                        //////
                        rank=valid_rank1[l_p][l_rank];
                        //printf ("Current Rank : %d",rank );

                        for(l_dq = 0; l_dq < 4; l_dq++) {
                            for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {

                                if(binary_done_map[l_p][rank][l_n]==0) {
                                    l_status=1;
                                }

                                l_flag_p0=0;
                                l_flag_p1=0;
                                if(l_p == 0) {
                                    for(l_i=0; l_i<count_bad_dq[0]; l_i++) {
                                        if(l_CDarray0[l_i]==l_dq+l_n*4) {
                                            schmoo_error_map[l_p][rank][l_n]=1;
                                            l_flag_p0=1;

                                        }
                                    }
                                }
                                else {
                                    for(l_i=0; l_i<count_bad_dq[1]; l_i++) {

                                        if(l_CDarray1[l_i]==l_dq+l_n*4) {
                                            schmoo_error_map[l_p][rank][l_n]=1;
                                            l_flag_p1=1;

                                        }
                                    }
                                }

                                if(schmoo_error_map[l_p][rank][l_n]==0) {
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4];
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4])/2;

                                    rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]);
                                    if(rc) return rc;
                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4];
                                    } else {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4];
                                    }
                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]<=1) {
                                        binary_done_map[l_p][rank][l_n]=1;
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4];

                                    }
                                } else {

                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4];
                                    SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]=(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]+SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4])/2;

                                    rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_val[l_dq+l_n*4]);
                                    if(rc) return rc;
                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]>SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]) {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4];
                                    } else {
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4]-SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_pass[l_dq+l_n*4];
                                    }


                                    if(l_p==0) {
                                        if(l_flag_p0==1) {
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=1;
                                        }
                                    }
                                    else {
                                        if(l_flag_p1==1) {
                                            SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]=1;
                                        }
                                    }

                                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.curr_diff[l_dq+l_n*4]<=1) {
                                        binary_done_map[l_p][rank][l_n]=1;
                                        SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.lb_regval[l_dq+l_n*4]=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.last_fail[l_dq+l_n*4];

                                    }
                                }
                                //l_dq+l_n*4=l_dq+l_n*4+4;
                            }
                        }
                    }
                    rc=do_mcbist_reset(i_target);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_reset failed");
                        return rc;
                    }
                    rc=do_mcbist_test(i_target);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
                        return rc;
                    }

                    rc=check_error_map(i_target,l_p,pass);
                    if(rc)
                    {
                        FAPI_INF("generic_shmoo::find_bound do_mcbist_test failed");
                        return rc;
                    }


                    //printf("\n the status =%d \n",l_status);
                    count_cycle++;
                }
            }

            for(l_p = 0; l_p < MAX_PORT; l_p++)
            {
                for (l_rank=0; l_rank<iv_MAX_RANKS[l_p]; l_rank++)
                {
                    //l_dq+l_n*4=bit;
                    //////
                    rank=valid_rank1[l_p][l_rank];
                    //printf("Valid rank of %d %d %d %d %d %d %d %d",valid_rank1[0],valid_rank1[1],valid_rank1[2],valid_rank1[3],valid_rank1[4],valid_rank1[5],valid_rank1[6],valid_rank1[7]);
                    for(l_dq = 0; l_dq < 4; l_dq++) {
                        for (l_n=0; l_n<l_SCHMOO_NIBBLES; l_n++) {
                            rc=mss_access_delay_reg_schmoo(i_target,l_access_type_e,l_p,rank,l_input_type_e,l_dq+l_n*4,0,SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[rank].K.nom_val[l_dq+l_n*4]);
                            if(rc) return rc;
                            //l_dq+l_n*4=l_dq+l_n*4+4;
                        }
                    }
                }
            }

        } // End of LEFT


        return rc;


    }

	fapi::ReturnCode generic_shmoo::get_nibble_pda(const fapi::Target & i_target,uint32_t pda_nibble_table[2][2][4][16][2])
	{
		fapi::ReturnCode rc;
		//uint8_t i_rank = 0;
		uint8_t l_dimm = 0;
		uint8_t num_ranks_per_dimm[2][2];
		
		rc = FAPI_ATTR_GET(ATTR_EFF_NUM_MASTER_RANKS_PER_DIMM, &i_target, num_ranks_per_dimm); if(rc) return rc;
		
		for (int l_p=0;l_p < MAX_PORT;l_p++){
		 for (l_dimm=0;l_dimm < 2;l_dimm++){
			for (int l_rnk=0;l_rnk < num_ranks_per_dimm[l_p][l_dimm];l_rnk++)
			{
				////
				for(int l_dq = 0; l_dq < 4;l_dq++){
					for (int l_n=0; l_n < 16;l_n++){
						// do necessary
						//if(pda_nibble_table[l_p][i_rank][l_n][1] < FAPI_INF.MBA.P[l_p].S[i_rank].K.total_margin[l_dq+l_n*4])
						{
							pda_nibble_table[l_p][l_dimm][l_rnk][l_n][0] = iv_vref_mul;
							
							if(l_dimm == 0)
							{pda_nibble_table[l_p][l_dimm][l_rnk][l_n][1] = SHMOO[iv_DQS_ON].MBA.P[l_p].S[l_rnk].K.total_margin[l_dq+l_n*4];}
							else
							{pda_nibble_table[l_p][l_dimm][l_rnk][l_n][1] = SHMOO[iv_DQS_ON].MBA.P[l_p].S[l_rnk+4].K.total_margin[l_dq+l_n*4];}
						}
						//FAPI_INF("\n Port %d Rank:%d Pda_Nibble: %d  V-ref:%d  Margin:%d",l_p,i_rank,l_n,pda_nibble_table[l_p][i_rank][l_n][0],pda_nibble_table[l_p][i_rank][l_n][1]);
					}
				}
				
			}
		}
		}						
		return rc;
	}
	/*------------------------------------------------------------------------------
* Function: get_min_margin
* Description  : This function is used to get the minimum margin of all the schmoo margins
*
* Parameters: Target:MBA,right minimum margin , left minimum margin, pass fail
* ---------------------------------------------------------------------------*/

    fapi::ReturnCode generic_shmoo::get_min_margin2(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk,l_byte,l_nibble,l_bit,i_rank;
        uint16_t l_temp_right=4800;
        uint16_t l_temp_left=4800;
        uint8_t l_dq=0;
        uint8_t l_p=0;
        FAPI_INF("In GET_MIN_MARGIN - iv_shmoo_type = %d",iv_shmoo_type);

        for (l_p = 0; l_p < 2; l_p++)
        {
            for (l_rnk = 0; l_rnk < iv_MAX_RANKS[l_p]; l_rnk++)
            {

                i_rank = valid_rank1[l_p][l_rnk];
                ////
                if (rc) return rc;
                for (l_byte = 0; l_byte < 10; l_byte++)
                {
                    //Nibble loop
                    for (l_nibble = 0; l_nibble < 2; l_nibble++)
                    {
                        //l_dq=8 * l_byte + 4 * l_nibble;


                        for (l_bit = 0; l_bit < 4; l_bit++)
                        {
                            l_dq = 8 * l_byte + 4 * l_nibble + l_bit;
                            if ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq]
                                    < l_temp_right) && (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq] != 0 ))
                            {
                                l_temp_right
                                    = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_dq];
                            }
                            if ((SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq]
                                    < l_temp_left) && (SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq] !=0))
                            {
                                l_temp_left
                                    = SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_dq];
                            }
                        }
                    }
                }
            }
        }



        if(iv_shmoo_type==8)
        {
            *o_right_min_margin=l_temp_left;
            *o_left_min_margin=l_temp_right;
        } else {
            *o_right_min_margin=l_temp_right;
            *o_left_min_margin=l_temp_left;
        }
        return rc;
    }


    fapi::ReturnCode generic_shmoo::get_min_margin_dqs(const fapi::Target & i_target,uint32_t *o_right_min_margin,uint32_t *o_left_min_margin)
    {
        fapi::ReturnCode rc;
        uint8_t l_rnk,l_nibble,i_rank;
        uint16_t l_temp_right=4800;
        uint16_t l_temp_left=4800;
        uint8_t l_p=0;
        uint8_t l_attr_eff_dram_width_u8=0;
        uint8_t l_SCHMOO_NIBBLES=20;
        uint8_t l_by8_dqs=0;

        rc = FAPI_ATTR_GET(ATTR_EFF_DRAM_WIDTH, &i_target, l_attr_eff_dram_width_u8);
        if(rc) return rc;

        if(iv_dmm_type==1)
        {
            l_SCHMOO_NIBBLES=18;
        }

        if(l_attr_eff_dram_width_u8 == 8) {
            l_SCHMOO_NIBBLES=10;
            if(iv_dmm_type==1)
            {
                l_SCHMOO_NIBBLES=9;
            }
        }
        iv_shmoo_type=4;

        for (l_p=0; l_p<MAX_PORT; l_p++) {
            for (l_rnk=0; l_rnk<iv_MAX_RANKS[l_p]; l_rnk++)
            {
                i_rank=valid_rank1[l_p][l_rnk];


                for(l_nibble=0; l_nibble< l_SCHMOO_NIBBLES; l_nibble++)
                {

                    l_by8_dqs=l_nibble;
                    if(iv_dmm_type==0)
                    {
                        if(l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble=l_nibble*2;
                        }
                    }

                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble]<l_temp_right)
                    {
                        l_temp_right=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.right_margin_val[l_nibble];
                    }
                    if(SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble]<l_temp_left)
                    {
                        l_temp_left=SHMOO[iv_SHMOO_ON].MBA.P[l_p].S[i_rank].K.left_margin_val[l_nibble];
                    }

                    if(iv_dmm_type==0)
                    {
                        if(l_attr_eff_dram_width_u8 == 8)
                        {
                            l_nibble=l_by8_dqs;
                        }
                    }
                }
            }
        }


        // hacked for now till schmoo is running
        if(iv_shmoo_type==8)
        {
            *o_right_min_margin=l_temp_left;
            *o_left_min_margin=l_temp_right;
        } else {
            *o_right_min_margin=l_temp_right;
            *o_left_min_margin=l_temp_left;
        }
        return rc;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    fapi::ReturnCode generic_shmoo::schmoo_setup_mcb(const fapi::Target & i_target)
    {

        struct Subtest_info l_sub_info[30];
        uint32_t l_pattern = 0;
        uint32_t l_testtype = 0;
        mcbist_byte_mask i_mcbbytemask1;
        char l_str_cust_addr[] = "ba0,ba1,mr3,mr2,mr1,mr0,ba2,ba3,cl2,cl3,cl4,cl5,cl6,cl7,cl8,cl9,cl11,cl13,r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,sl2,sl1,sl0";

        i_mcbbytemask1 = UNMASK_ALL;

        fapi::ReturnCode rc;

        l_pattern = iv_pattern;
        l_testtype = iv_test_type;

        if (iv_shmoo_type == 16)
        {
            FAPI_INF("%s:\n Read DQS is running \n", i_target.toEcmdString());
            if (iv_SHMOO_ON == 1)
            {
                l_testtype = 3;
            }
            if (iv_SHMOO_ON == 2)
            {
                l_testtype = 4;
            }
        }
        //send shmoo mode to vary the address range
        if (iv_shmoo_type == 16)
        {
            rc = FAPI_ATTR_SET(ATTR_MCBIST_PATTERN, &i_target, l_pattern);
            if (rc) return rc;//-----------i_mcbpatt------->run
            rc = FAPI_ATTR_SET(ATTR_MCBIST_TEST_TYPE, &i_target, l_testtype);
            if (rc) return rc;//---------i_mcbtest------->run
        }

        rc = setup_mcbist(i_target, i_mcbbytemask1, 0,0x0ull ,l_sub_info,l_str_cust_addr);
        if (rc) return rc;

        return rc;
    }

}//Extern C
