/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_grouping.C $ */
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
// $Id: mss_eff_grouping.C,v 1.24 2013/04/09 20:34:54 bellows Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_grouping.C
// *! DESCRIPTION : see additional comments below
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
//Owner :- Girisankar paulraj
//Back-up owner :- Mark bellows
//
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.24   | bellows  | 04-09-13| Updates that really allow checkboard and all group sizes.  Before, group size of 1 was all that was possible
//  1.23   | bellows  | 03-26-13| Allow for checkboard mode with more than one mcs per group
//  1.22   | bellows  | 03-21-13| Error Logging support
//  1.21   | bellows  | 03-11-13| Fixed syntax error with respect to the fapi macro under cronus
//  1.20   | bellows  | 03-08-13| Proper way to deconfigure mulitple/variable MCS
//  1.19   | bellows  | 02-27-13| Added back in mirror overlap check.  Added in error rc for grouping
//  1.18   | asaetow  | 02-01-13| Removed FAPI_ERR("Mirror Base address overlaps with memory base address. "); temporarily.
//         |          |         | NOTE: Need Giri to check mirroring enable before checking for overlaps.
//  1.17   | gpaulraj | 01-31-13| Error place holders added
//  1.16   | gpaulraj | 12-14-12| Modified "nnable to group dimm size" as Error message
//  1.15   | bellows  | 12-11-12| Picked up latest updates from Girisankar
//  1.14   | bellows  | 12-11-12| added ; to DBG line
//  1.13   | bellows  | 12-07-12| fix for interleaving attr and array bounds
//  1.11   | bellows  | 11-27-12| review updates
//  1.10   | bellows  | 09-27-12| Additional Review Updates
//  1.9    | bellows  | 09-25-12| updates from review, code from Girisankar
//  1.8    | bellows  | 09-06-12| updates suggested by Van
//  1.7    | bellows  | 08-31-12| updates from Girisankar: C++ Object. Also use 32 bit Attribute
//  1.6    | bellows  | 08-29-12| expanded group id temporaily to 32 bits, fixed compiler warnings
//         |          |         | Read old 8bit attr, and move to 32
//         |          |         | Removed read of attr that has not been written
//  1.2    | bellows  | 07-16-12| bellows | added in Id tag
//  1.1    | gpaulraj | 03-19-12| First drop for centaur
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <mss_eff_grouping.H>
#include <fapi.H>
#include "cen_scom_addresses.H"
#include <mss_error_support.H>
//#include <mss_funcs.H>

//#ifdef FAPIECMD
extern "C" {
//#endif

  using namespace fapi;
//----------------------------------------------
// MSS EFF GROUPING FUNCTIONs............
//----------------------------------------------------

  ReturnCode mss_eff_grouping(const fapi::Target & i_target, std::vector<fapi::Target> & i_associated_centaurs); // Target is Proc target & Each MCS connected to each Centaur. Associated centaur is collection of the Centaure location for the processor
  uint8_t mss_eff_grouping_recursion(uint32_t number);
//ReturnCode mba_collection(std::vector<fapi::Target> & associated_centaurs);
//ReturnCode mcs_grouping(const fapi::Target & target);
//ReturnCode mcs_grouping_general();
//ReturnCode mcs_grouping_reorder();
//ReturnCode mcs_group_base_address(const fapi::Target & target);
//ReturnCode mcs_attributes_setting(const fapi::Target & target);

// PLAN:---
//    Parameter  of the populated Dimm details for each MCS looper
//    Starts with Zero MCS base address. Identifies Dimm parameters belong to MCS
//    Configure the Group primary MCS0 Registers
//    Configure the Group seconary MCS0 Registers /// identifies it base address based on the Primary group size
//    Identify Mirror details setup accordingly
//    Set up each translation registry accordingly
//    SIM configuration
//    Venice model has MCS0 & MCS1 - Murano model has MCS4 & MCS5
//    -------------------------|-----------------------------------|
//    -------    MCS0 ---------|-------------MCS1------------------|
//    -------------------------|-----------------------------------|
//    ---  MBA0  --- MBA1 -----|--------  MBA0  --- MBA1 ----------|
//     0-  32GB  --- 32GB -----|---- D0-  32GB  --- 32GB ----------|
//    D1-  32GB  --- 32GB  ----|-----D1-  32GB  --- 32GB  ---------|
//    -------------------------|-----------------------------------|
//    - Base address MCS0 - 0x0  Group Size - 128GB
//    - MCS0 -  Grouping base address  - 0GB Group size - 128GB
//    - MCS1 -  Grouping base address  - 128GB+ Group size - 128GB
//----------------------------------------------------
// MSS EFF GROUPING Variables..........
//----------------------------------------------------



  ReturnCode mss_eff_grouping(
                              const fapi::Target & i_target,
                              std::vector<fapi::Target> & i_associated_centaurs
                              ) {
    ReturnCode rc;
    Eff_Grouping_Data eff_grouping_data,tempgpID;
       //Eff_Grouping_Data &eff_grouping_data;
        //eff_grouping_data.groupID[16][16]={{0}};
    //uint32_t pos=0;
    uint64_t mss_base_address;
    uint64_t mirror_base;
        //uint32_t MBA_size[8][2]={{0}};
        //uint32_t MCS_size[8]={0};
    uint32_t l_unit_pos =0;
        //uint32_t l_count=0;
    uint8_t gp_pos=0;
    uint8_t min_group = 1;
    std::vector<fapi::Target> l_proc_chiplets;
    int i; int j;
    for(i=0;i<MBA_SIZE_MCS;i++) {
      eff_grouping_data.MCS_size[i]=0;
      for(j=0;j<MBA_SIZE_PORT;j++)
        eff_grouping_data.MBA_size[i][j]=0;
    }
    for(i=0;i<MBA_GROUP_SIZE;i++) {
      for(j=0;j<MBA_GROUP_DATA;j++)
        eff_grouping_data.groupID[i][j]=0;
    }

    do
    {
      FAPI_INF("MCS grouping begins");
//	rc=mba_collection(associated_centaurs, &eff_grouping_data);
//	if(!rc.ok()) {FAPI_ERR("MBA memory: There is no valid memory dimm available"); break;}
///	rc=mcs_grouping(target);
//    	if(!rc.ok()) {FAPI_ERR("MCS Grouping: MCS grouping is not feasible"); break;}
//	rc=mcs_grouping_reorder();
//	if(!rc.ok()) {FAPI_ERR("MCS Grouping: MCS grouping re-ordering is not feasible"); break;}
//	rc=mcs_group_base_address(target);
//  /  if(!rc.ok()) {FAPI_ERR("MCS Grouping: MCS grouping base address is greater not than largest group size"); break;}
//	rc=mcs_attributes_setting(target);
//    if(!rc.ok()) {FAPI_ERR("MCS Grouping: MCS gruping attributes is not defined correctly"); break;}

      uint8_t centaur;
      uint8_t mba_i;
      uint8_t mba=0;
      uint8_t dimm=0;
      uint32_t cenpos;
      uint32_t procpos;
      uint8_t port;
      uint8_t mba_pos[2][2] = { {0, 0},{0,0}};
      std::vector<fapi::Target> l_mba_chiplets;
      FAPI_INF("Happy starting");
      uint8_t cen_count=0;
      rc = FAPI_ATTR_GET(ATTR_POS,&i_target, procpos);
      if(rc) return rc;
   //   for(centaur= procpos*8; centaur <= procpos*8+8; centaur++) {
      for(centaur= 0; centaur < i_associated_centaurs.size(); centaur++) {
        mba=0;port=0;dimm=0;
        fapi::Target & centaur_t = i_associated_centaurs[centaur];
//        centaur_t=i_associated_centaurs[centaur];
        rc = FAPI_ATTR_GET(ATTR_POS,&centaur_t, cenpos);
        if(rc) return rc;
        if(cenpos>=procpos*8 && cenpos<(procpos*8+8)){
                FAPI_INF("... working on centaur %d", cenpos);
                rc = fapiGetChildChiplets(i_associated_centaurs[centaur], fapi::TARGET_TYPE_MBA_CHIPLET, l_mba_chiplets);
                if(rc) return rc;
                for(mba_i=0; mba_i<l_mba_chiplets.size(); mba_i++) {

                  rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mba_chiplets[mba_i], mba);
                  if(rc) return rc;
                  FAPI_INF("... working on mba %d", mba);
                  rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &l_mba_chiplets[mba_i],mba_pos);
                  if(rc) return rc;
                  for(port = 0; port<2; port++)
                  {	
                    for(dimm=0; dimm<2; dimm++) {
                      eff_grouping_data.MCS_size[cenpos - procpos * 8]+=mba_pos[port][dimm];
                      eff_grouping_data.MBA_size[cenpos - procpos * 8][mba] += mba_pos[port][dimm];
                    }
                  }
                  FAPI_INF(" Cen Pos %d mba %d DIMM SIZE %d \n",cenpos,mba,eff_grouping_data.MBA_size[cenpos - procpos * 8][mba]);
                  FAPI_INF(" Cen Pos %d MBA SIZE %d %d  %d %d \n",cenpos, mba_pos[0][0],mba_pos[0][1],mba_pos[1][0],mba_pos[1][1]);
                  FAPI_INF(" MCS SIZE %d\n",eff_grouping_data.MCS_size[cenpos - procpos * 8]);
   //               cen_count++; l_unit_pos++;
            }
            cen_count++;l_unit_pos++;
        }
//        cen_count++; l_unit_pos++;
      }
      FAPI_INF("attr_mss_setting %d and  no  of MBAs   %d \n",min_group,l_unit_pos);
      for (uint8_t i=0;i<8;i++)
      {
        FAPI_INF("MCS SIZE %d \n",eff_grouping_data.MCS_size[i]);
      }
      FAPI_INF("Group parsing Starting..");
// 	groupID[i][0]=Size;
//  groupID[i][1]= number of MBA in the group for example 4 MBA in the group
//  groupID[i][2]= Total size of memory
//  groupID[i][3] to groupIDsize[i][6]  - group pos indication
    //  uint32_t temp[12];
      uint8_t count=0;
        uint8_t done;
        uint8_t pos;
        uint8_t config_4MCS[6][4]={{0,1,4,5},{2,3,6,7},{0,1,6,7},{2,3,4,5},{0,1,2,3},{4,5,6,7}};
        int flag;
        uint8_t config4_pos[6];
        uint8_t groups_allowed;
        // uint8_t tempgpID.groupID[16][16];
        uint8_t grouped[16];
        uint8_t check_board;
        uint8_t gp=0;
        uint8_t pos1=0;
        uint8_t pos2=0;
        uint8_t allowed=0;



        for(uint8_t i=0;i<6;i++)
          config4_pos[i]=0;

	rc = FAPI_ATTR_GET(ATTR_MSS_INTERLEAVE_ENABLE,&i_target,groups_allowed);
	if(!rc.ok()) {FAPI_ERR("MSS_INTERLEAVE_ENABLE is not available"); return rc; }
	rc = FAPI_ATTR_GET(ATTR_ALL_MCS_IN_INTERLEAVING_GROUP, NULL,check_board); // system level attribute
	if (!rc.ok()) { FAPI_ERR("Error reading ATTR_ALL_MCS_IN_INTERLEAVING_GROUP"); return rc; }

        if(check_board) // this is a 1 when interleaving is required to be on  Only acceptable > 1MCS per group
        {
          if((groups_allowed & 0x02) || (groups_allowed & 0x04)||(groups_allowed & 0x08))
          {

            FAPI_INF("FABRIC IS IN NON-CHECKER BOARD MODE.");
            FAPI_INF("FABRIC SUPPORTS THE FOLLOWING ");
            if(groups_allowed & 0x02){FAPI_INF("2MCS/GROUP");}
            if(groups_allowed & 0x04){FAPI_INF("4MCS/GROUP");}
            if(groups_allowed & 0x08){FAPI_INF("8MCS/GROUP");}
            FAPI_INF("FABRIC DOES NOT SUPPORT THE FOLLOWING ");
            FAPI_INF("1MCS/GROUP");
            if(!(groups_allowed & 0x02)){FAPI_INF("2MCS/GROUP");}
            if(!(groups_allowed & 0x04)){FAPI_INF("4MCS/GROUP");}
            if(!(groups_allowed & 0x08)){FAPI_INF("8MCS/GROUP");}
           }
           else
           {
              FAPI_ERR("UNABLE TO GROUP");
              FAPI_ERR("FABRIC IS IN NON-CHECKER BOARD MODE.  SET ATTRIBUTE 'ATTR_MSS_INTERLEAVE_ENABLE' , TO SUPPORT 2MCS , 4MCS AND 8MCS GROUPING. OR ENABLE CHECKER BOARD. ");
//@thi - hack              const fapi::Target & PROC_CHIP = i_target;
              FAPI_SET_HWP_ERROR(rc, RC_MSS_NON_CHECKER_BOARD_MODE_GROUPING_NOT_POSSIBLE);
              return rc;
           }
         }
         else // Fabric is in checkerboard mode, allow all sizes.  Anything but 1 will have performance impacts
         {
            if((groups_allowed & 0x01) || (groups_allowed & 0x02) || (groups_allowed & 0x04)||(groups_allowed & 0x08))
            {
               FAPI_INF("FABRIC IS IN CHECKER BOARD MODE AND IT SUPPORTS THE FOLLOWING ");
               if(groups_allowed & 0x01){FAPI_INF("1MCS/GROUP");}
               if(groups_allowed & 0x02){FAPI_INF("2MCS/GROUP");}
               if(groups_allowed & 0x04){FAPI_INF("4MCS/GROUP");}
               if(groups_allowed & 0x08){FAPI_INF("8MCS/GROUP");}
               FAPI_INF("FABRIC DOES NOT SUPPORT THE FOLLOWING ");
               if(!(groups_allowed & 0x01)){FAPI_INF("FABRIC IS IN CHECKER BOARD MODE BUT YOU ARE ASKING FOR MORE THAN 1MCS/GROUP. YOU ARE NOT GOING TO HAVE PERFOMRANCE YOU COULD GET IF YOU WERE IN CHECKERBOARD MODE");}
               if(!(groups_allowed & 0x02)){FAPI_INF("2MCS/GROUP");}
               if(!(groups_allowed & 0x04)){FAPI_INF("4MCS/GROUP");}
               if(!(groups_allowed & 0x08)){FAPI_INF("8MCS/GROUP");}
               if((groups_allowed & 0x02) || (groups_allowed & 0x04)||(groups_allowed & 0x08)){FAPI_INF("FABRIC IS IN CHECKER BOARD MODE BUT YOU ARE ASKING FOR MORE THAN 1MCS/GROUP. YOU ARE NOT GOING TO HAVE PERFOMRANCE YOU COULD GET IF YOU WERE IN CHECKERBOARD MODE");}




            }
            else
            {
               FAPI_ERR("UNABLE TO GROUP");
               FAPI_ERR("FABRIC IS IN CHECKER BOARD MODE . SET ATTRIBUTE 'ATTR_MSS_INTERLEAVE_ENABLE' ");
//@thi - hack               const fapi::Target & PROC_CHIP = i_target;
               FAPI_SET_HWP_ERROR(rc, RC_MSS_CHECKER_BOARD_MODE_GROUPING_NOT_POSSIBLE);
               return rc;

            }


         }
        for(uint8_t i=0;i<16;i++)
        {
             grouped[i]=0;
             for(uint8_t j=0;j<16;j++)
             {
                 eff_grouping_data.groupID[i][j]=0;
                 tempgpID.groupID[i][j]=0;
             }
         }


        gp_pos=0;

        for(pos=0;pos<8;pos++)
        {
             eff_grouping_data.groupID[gp_pos][0] = eff_grouping_data.MCS_size[pos];
             eff_grouping_data.groupID[gp_pos][1] = 1;
             eff_grouping_data.groupID[gp_pos][4]= pos;

             if(eff_grouping_data.MBA_size[pos][0]>eff_grouping_data.MBA_size[pos][1])
                  eff_grouping_data.groupID[gp_pos][15]= eff_grouping_data.MBA_size[pos][0];
             else
                  eff_grouping_data.groupID[gp_pos][15]= eff_grouping_data.MBA_size[pos][1];

             gp_pos++;
         }


           done = 0 ;
           if(!done && (groups_allowed & 0x08))
           {
          	
                count =0;
                for(pos=0;pos< gp_pos;pos++)
                {
                    if(eff_grouping_data.groupID[0][0] == eff_grouping_data.groupID[pos][0] && eff_grouping_data.groupID[pos][0] !=0)
                    {
                      count++;
                    }
                 }

                 if(count == 8)
                 {
                   done=1;
                   eff_grouping_data.groupID[0][1] = 8;
                   eff_grouping_data.groupID[0][4] = 0;
                   eff_grouping_data.groupID[0][5] = 4;
                   eff_grouping_data.groupID[0][6] = 1;
                   eff_grouping_data.groupID[0][7] = 5;
                   eff_grouping_data.groupID[0][8] = 2;
                   eff_grouping_data.groupID[0][9] = 6;
                   eff_grouping_data.groupID[0][10] = 3;
                   eff_grouping_data.groupID[0][11] = 7;
                   for(uint8_t i=1;i<16;i++)
                     for(uint8_t j=0;j<16;j++)
                       eff_grouping_data.groupID[i][j]=0;
                 }

            }
            if(!done && (groups_allowed & 0x04))
            {
                 count=0;
                 for(uint8_t i=0;i<6;i++)
                 {
                   flag=0;
                   for( int j=0;j<4;j++)
                    {
                      if((eff_grouping_data.groupID[config_4MCS[i][0]][0]== 0) || (eff_grouping_data.groupID[config_4MCS[i][0]][0] != eff_grouping_data.groupID[config_4MCS[i][j]][0]))
                       {
                         flag=1;
                       }
                    }
                    if(!flag)
                    {

                    config4_pos[i]=1;
                    count++;
                    }
                 }
                 if(count>=2)
                 {
                    if(config4_pos[0] && config4_pos[1])
                    {
                       allowed=1;
                       pos1=0;
                       pos2=1;
                    }
                    else if(config4_pos[2] && config4_pos[3])
                    {
                       allowed=1;
                       pos1=2;
                       pos2=3;
                    }
                    else if(config4_pos[4] && config4_pos[5])
                    {
                       allowed=1;
                       pos1=4;
                       pos2=5;
                    }
                 }
                 if(allowed)
                  {
          	           done =1;
                         //define the group_data
                         eff_grouping_data.groupID[0][0] =eff_grouping_data.groupID[config_4MCS[pos1][0]][0];
                         eff_grouping_data.groupID[0][1] = 4;
                         eff_grouping_data.groupID[0][4] = config_4MCS[pos1][0];
                         eff_grouping_data.groupID[0][5] = config_4MCS[pos1][2];
                         eff_grouping_data.groupID[0][6] = config_4MCS[pos1][1];
                         eff_grouping_data.groupID[0][7] = config_4MCS[pos1][3];
                         eff_grouping_data.groupID[0][15] =eff_grouping_data.groupID[config_4MCS[pos1][0]][15];

                         eff_grouping_data.groupID[1][0] =eff_grouping_data.groupID[config_4MCS[pos2][0]][0];
                         eff_grouping_data.groupID[1][1] = 4;
                         eff_grouping_data.groupID[1][4] = config_4MCS[pos2][0];
                         eff_grouping_data.groupID[1][5] = config_4MCS[pos2][2];
                         eff_grouping_data.groupID[1][6] = config_4MCS[pos2][1];
                         eff_grouping_data.groupID[1][7] = config_4MCS[pos2][3];
                         eff_grouping_data.groupID[1][15] =eff_grouping_data.groupID[config_4MCS[pos2][0]][15];

                         for(uint8_t i=2;i<16;i++)
                           for(uint8_t j=0;j<16;j++)
                             eff_grouping_data.groupID[i][j]=0;
                  }
                  else if (count ==1 || !allowed )
                  {
                       for(uint8_t i=0;i<6;i++)
                       {
                         if(config4_pos[i])
                         {
                           allowed=1;
                           pos1=i;
                           break;
                         }
                       }
                       if(allowed)
                       {
          	          //define the group_data
          	           tempgpID.groupID[0][0] = eff_grouping_data.groupID[config_4MCS[pos1][0]][0];
                           tempgpID.groupID[0][1] = 4;
                           tempgpID.groupID[0][4] = config_4MCS[pos1][0];
                           tempgpID.groupID[0][5] = config_4MCS[pos1][2];
                           tempgpID.groupID[0][6] = config_4MCS[pos1][1];
                           tempgpID.groupID[0][7] = config_4MCS[pos1][3];
                           tempgpID.groupID[0][15] = eff_grouping_data.groupID[config_4MCS[pos1][0]][15];
          	           gp++;
                           for(int i=0; i<4;i++)
                           {
                              eff_grouping_data.groupID[config_4MCS[pos1][i]][0]=0;
                              grouped[config_4MCS[config4_pos[0]][i]]=1;
                           }
                       }
                   }
           }
           if(!done && (groups_allowed & 0x02))
           {
            for(pos=0;pos< gp_pos;pos=pos+2)
            {
                 if(eff_grouping_data.groupID[pos][0] == eff_grouping_data.groupID[pos+1][0] && eff_grouping_data.groupID[pos][0] !=0  )
                 {
                  //group
                  tempgpID.groupID[gp][0] =eff_grouping_data.groupID[pos][0] ;
                  tempgpID.groupID[gp][1] = 2;
                  tempgpID.groupID[gp][4] =  pos;
                  tempgpID.groupID[gp][5] = pos+1;
                  tempgpID.groupID[gp][15] =eff_grouping_data.groupID[pos][15] ;
                  grouped[pos]=1;
                  grouped[pos+1]=1;
                  eff_grouping_data.groupID[pos][0]=0;
                  eff_grouping_data.groupID[pos+1][0]=0;
                  gp++;
                 }
             }
           }
           if(!done && (groups_allowed & 0x01) && !check_board)
           {
            for(pos=0;pos< gp_pos;pos++)
            {
                 if(eff_grouping_data.groupID[pos][0] !=0  )
                 {
                  //group
                  tempgpID.groupID[gp][0] =eff_grouping_data.groupID[pos][0] ;
                  tempgpID.groupID[gp][1] = 1;
                  tempgpID.groupID[gp][4] =  pos;
                  tempgpID.groupID[gp][15] =eff_grouping_data.groupID[pos][15] ;
                  grouped[pos]=1;
                  eff_grouping_data.groupID[pos][0]=0;
                  gp++;
                 }
             }

           }
           if(!done)
           {
             uint8_t ungroup =0;
             ReturnCode ungroup_rc;

             for(uint8_t i=0;i<8;i++)
             {
               if(grouped[i] !=1 && eff_grouping_data.groupID[i][0] != 0 )
               {
                 FAPI_ERR ("UNABLE TO GROUP MCS%d size is %d", i,eff_grouping_data.groupID[i][0]);
                 ungroup++;
                 if(ungroup == 1) { // First time, call out the Main error
                   FAPI_SET_HWP_ERROR(ungroup_rc, RC_MSS_UNABLE_TO_GROUP_SUMMARY);
                 }
                 const fapi::Target & TARGET_MCS = l_proc_chiplets[i];
                 FAPI_ADD_INFO_TO_HWP_ERROR(rc, RC_MSS_UNABLE_TO_GROUP_MCS);

               }
             }
            if (ungroup)
             {
	        return ungroup_rc;
             }
             for(uint8_t i=0;i<gp;i++)
               for(uint8_t j=0;j<16;j++)
                 eff_grouping_data.groupID[i][j]=tempgpID.groupID[i][j];

             for(uint8_t i=gp ; i<8 ; i++)
               for(uint8_t j=0;j<16;j++)
               eff_grouping_data.groupID[i][j]=0;
           }
            flag=0;
            for(uint8_t i=0;i<16;i++)
               if(grouped[i])
                  flag=1;
            gp_pos=0;
            if(done || flag)
            {
               for(uint8_t i=0;i<16;i++)
               {
            	      if( eff_grouping_data.groupID[i][0] !=0)
            	      {
                         gp_pos++;
                         FAPI_INF(" group no= %d , num of MCS = %d , size of MCS = %d \n ", i,eff_grouping_data.groupID[i][1],eff_grouping_data.groupID[i][0]);
                         for(uint8_t k=0 ; k< eff_grouping_data.groupID[i][1];k++)
                         {
            	           FAPI_INF("MCSID%d = %d \n ", k, eff_grouping_data.groupID[i][4+k]);
                         }
                      }
                  }
             }
      uint32_t temp[16];
      uint8_t i=0;
      uint8_t j=0;
      count=0;

    uint64_t total_size_non_mirr =0;
    for(pos=0;pos<=gp_pos;pos++)
      {
        eff_grouping_data.groupID[pos][2] = eff_grouping_data.groupID[pos][0]*eff_grouping_data.groupID[pos][1];
        //eff_grouping_data.groupID[pos+8][2]= eff_grouping_data.groupID[pos][2]/2; // group size when mirrored

        count =  mss_eff_grouping_recursion(eff_grouping_data.groupID[pos][2]);
        if(count>1)
        {
          FAPI_INF("MCS pos %d needs alternate bars defintation group Size %d\n",pos,eff_grouping_data.groupID[pos][3]);



            eff_grouping_data.groupID[pos][2] = eff_grouping_data.groupID[pos][15]*2*eff_grouping_data.groupID[pos][1];
            eff_grouping_data.groupID[pos][13] = eff_grouping_data.groupID[pos][1]*(eff_grouping_data.groupID[pos][0]-eff_grouping_data.groupID[pos][15]);

            //mirrored group
            //eff_grouping_data.groupID[pos+8][2] = eff_grouping_data.groupID[pos][2]/2;  //group size with alternate bars
            //eff_grouping_data.groupID[pos+8][13] = eff_grouping_data.groupID[pos][13]/2;
             eff_grouping_data.groupID[pos][12] =1;
        }

        total_size_non_mirr += eff_grouping_data.groupID[pos][2];
      }
      for(i=0;i<gp_pos;i++)
      {
          for(j=0;j<12;j++)
          {
            FAPI_INF(" groupID[%d][%d] = %d",i,j,eff_grouping_data.groupID[i][j]);
          }
          FAPI_INF("\n");
      }
      for(pos=0;pos<=gp_pos;pos++)
      {	
        for(i=pos;i< gp_pos;i++)
        {
          if ( eff_grouping_data.groupID[i][2] > eff_grouping_data.groupID[pos][2])
          {
            for(j=0;j<16;j++)	temp[j] = eff_grouping_data.groupID[pos][j];
            for(j=0;j<16;j++)	eff_grouping_data.groupID[pos][j] = eff_grouping_data.groupID[i][j];
            for(j=0;j<16;j++)	eff_grouping_data.groupID[i][j] = temp[j];
          }
          else {}
        }
      }


       // calcutate mirrored group size
       for(pos=0;pos<gp_pos;pos++)
      {
        if(eff_grouping_data.groupID[pos][0]!=0 && eff_grouping_data.groupID[pos][1]>1 )
        {
          eff_grouping_data.groupID[pos+8][2]= eff_grouping_data.groupID[pos][2]/2; // group size when mirrored


          if(eff_grouping_data.groupID[pos][12])
          {
            FAPI_INF("Mirrored group pos %d needs alternate bars defintation group Size %d\n",pos,eff_grouping_data.groupID[pos][3]);
            //mirrored group
            eff_grouping_data.groupID[pos+8][2] = eff_grouping_data.groupID[pos][2]/2;  //group size with alternate bars
            eff_grouping_data.groupID[pos+8][13] = eff_grouping_data.groupID[pos][13]/2;

          }
        }
      }



      rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE,&i_target,mss_base_address);
      mss_base_address =   mss_base_address >> 30;
      if(!rc.ok()) return rc;

      rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASE,&i_target,mirror_base);
      mirror_base =   mirror_base >> 30;

      if(!rc.ok()) return rc;

      if( mss_base_address > (mirror_base + total_size_non_mirr/2)  || mirror_base > (mss_base_address + total_size_non_mirr))
      {

          for(pos=0;pos<gp_pos;pos++)
          {
             if(pos==0)
              {

                 eff_grouping_data.groupID[pos][3] =mss_base_address;

                 if(eff_grouping_data.groupID[pos][12])
                  {

                      eff_grouping_data.groupID[pos][14] = eff_grouping_data.groupID[pos][3]+ eff_grouping_data.groupID[pos][2]/2;

                  }
              }
             else
              {
                 eff_grouping_data.groupID[pos][3] = eff_grouping_data.groupID[pos-1][3]+eff_grouping_data.groupID[pos-1][2];


                 if(eff_grouping_data.groupID[pos][12])
                 {
                   eff_grouping_data.groupID[pos][14] = eff_grouping_data.groupID[pos][3]+ eff_grouping_data.groupID[pos][2]/2;

                 }
              }

              if(eff_grouping_data.groupID[pos][1]>1 )
              {
                 eff_grouping_data.groupID[pos+8][3]=mirror_base;
                 mirror_base= mirror_base + eff_grouping_data.groupID[pos+8][2];
                 if(eff_grouping_data.groupID[pos][12])
                  {
                     eff_grouping_data.groupID[pos+8][14] = eff_grouping_data.groupID[pos+8][3]+ eff_grouping_data.groupID[pos+8][2]/2; //mirrored base address with alternate bars
                  }

               }
          }

       }

       else
       {
          FAPI_ERR("Mirror Base address overlaps with memory base address. ");
//@thi - hack          const fapi::Target & PROC_CHIP = i_target;
          FAPI_SET_HWP_ERROR(rc, RC_MSS_BASE_ADDRESS_OVERLAPS_MIRROR_ADDRESS);
          return rc;
       }


      ecmdDataBufferBase MC_IN_GP(8);
      uint8_t mcs_in_group[8];
      for(uint8_t i=0;i<8;i++)
           mcs_in_group[i]=0;
      for(uint8_t i=0;i<gp_pos;i++)
      {
        count=0;
        MC_IN_GP.flushTo0();
        if(eff_grouping_data.groupID[i][0]!=0)
        {
          count = eff_grouping_data.groupID[i][1];
          for(uint8_t j=0;j<count;j++)
                 MC_IN_GP.setBit(eff_grouping_data.groupID[i][4+j]);
          mcs_in_group[i]= MC_IN_GP.getByte(0);
        }
       }
       FAPI_DBG("  ATTR_MSS_MEM_MC_IN_GROUP[0]: 0x%x", mcs_in_group[0]);
       FAPI_DBG("  ATTR_MSS_MEM_MC_IN_GROUP[1]: 0x%x", mcs_in_group[1]);
       FAPI_DBG("  ATTR_MSS_MEM_MC_IN_GROUP[2]: 0x%x", mcs_in_group[2]);
       FAPI_DBG("  ATTR_MSS_MEM_MC_IN_GROUP[3]: 0x%x", mcs_in_group[3]);
       FAPI_DBG("  ATTR_MSS_MEM_MC_IN_GROUP[4]: 0x%x", mcs_in_group[4]);
       FAPI_DBG("  ATTR_MSS_MEM_MC_IN_GROUP[5]: 0x%x", mcs_in_group[5]);
       FAPI_DBG("  ATTR_MSS_MEM_MC_IN_GROUP[6]: 0x%x", mcs_in_group[6]);
       FAPI_DBG("  ATTR_MSS_MEM_MC_IN_GROUP[7]: 0x%x", mcs_in_group[7]);

       rc= FAPI_ATTR_SET(ATTR_MSS_MEM_MC_IN_GROUP, &i_target, mcs_in_group);
       if (!rc.ok())FAPI_ERR("Error writing ATTR_MSS_MEM_MC_IN_GROUP");

      uint64_t mem_bases[8];
      uint64_t l_memory_sizes[8];
      //uint64_t mirror_base;
      uint64_t mirror_bases[4];
      uint64_t l_mirror_sizes[4];
        //uint32_t temp[8];
      for(uint8_t i=0;i<8;i++)
      {
        if(eff_grouping_data.groupID[i][0]>0)
        {
          FAPI_INF (" Group   %d MCS Size  %4dGB",i,eff_grouping_data.groupID[i][0]);
          FAPI_INF (" No of MCS %4d   ",eff_grouping_data.groupID[i][1]);
          FAPI_INF (" Group Size %4dGB",eff_grouping_data.groupID[i][2]);
          FAPI_INF (" Base Add.  %4dGB ",eff_grouping_data.groupID[i][3]);
          FAPI_INF (" Mirrored Group SIze %4dGB", eff_grouping_data.groupID[i+8][2]);
          FAPI_INF (" Mirror Base Add %4dGB" , eff_grouping_data.groupID[i+8][3]);
          for(uint8_t j=4;j<4+eff_grouping_data.groupID[i][1];j++)
          {
            FAPI_INF (" MCSID%d- Pos %4d",(j-4),eff_grouping_data.groupID[i][j]);
          }
          FAPI_INF (" Alter-bar  %4d",eff_grouping_data.groupID[i][12]);
          FAPI_INF("Alter-bar base add = %4dGB ",eff_grouping_data.groupID[i][14]);
          FAPI_INF("Alter-bar size = %4dGB",eff_grouping_data.groupID[i][13]);
          FAPI_INF("Alter-bar Mirrored Base add = %4dGB ", eff_grouping_data.groupID[i+8][14]);
          FAPI_INF("Alter-bar Mirrored size = %4dGB", eff_grouping_data.groupID[i+8][13]);
        }
        else
        {
          eff_grouping_data.groupID[i][0] = 0;
          eff_grouping_data.groupID[i][1] = 0;
          eff_grouping_data.groupID[i][2] = 0;
          eff_grouping_data.groupID[i][3] = 0;
          eff_grouping_data.groupID[i][4] = 0;
          eff_grouping_data.groupID[i][5] = 0;
          eff_grouping_data.groupID[i][6] = 0;
          eff_grouping_data.groupID[i][7] = 0;
          eff_grouping_data.groupID[i][8] = 0;
          eff_grouping_data.groupID[i][9] = 0;
        }
      }
//       rc = FAPI_ATTR_GET(ATTR_MSS_MCS_GROUP_32, &target, eff_grouping_data.groupID);
//        if (!rc.ok())
//        {
//            FAPI_ERR("Error reading ATTR_MSS_MCS_GROUP");
//          //  break;
//        }
        // base addresses for distinct non-mirrored ranges
      mem_bases[0]=eff_grouping_data.groupID[0][3];
      mem_bases[0] = mem_bases[0] <<30;
      mem_bases[1]=eff_grouping_data.groupID[1][3];
      mem_bases[1] =  mem_bases[1] <<30;
      mem_bases[2]=eff_grouping_data.groupID[2][3];
      mem_bases[2] =  mem_bases[2] <<30;
      mem_bases[3]=eff_grouping_data.groupID[3][3];
      mem_bases[3] =  mem_bases[3] <<30;
      mem_bases[4]=eff_grouping_data.groupID[4][3];
      mem_bases[4] =  mem_bases[4] <<30;
      mem_bases[5]=eff_grouping_data.groupID[5][3];
      mem_bases[5] =  mem_bases[5] <<30;
      mem_bases[6]=eff_grouping_data.groupID[6][3];
      mem_bases[6] =  mem_bases[6] <<30;
      mem_bases[7]=eff_grouping_data.groupID[7][3];
      mem_bases[7] =  mem_bases[7] <<30;

      FAPI_DBG("  ATTR_PROC_MEM_BASES[0]: %016llx", mem_bases[0]);
      FAPI_DBG("  ATTR_PROC_MEM_BASES[1]: %016llx", mem_bases[1]);
      FAPI_DBG("  ATTR_PROC_MEM_BASES[2]: %016llx", mem_bases[2]);
      FAPI_DBG("  ATTR_PROC_MEM_BASES[3]: %016llx", mem_bases[3]);
      FAPI_DBG("  ATTR_PROC_MEM_BASES[4]: %016llx", mem_bases[4]);
      FAPI_DBG("  ATTR_PROC_MEM_BASES[5]: %016llx", mem_bases[5]);
      FAPI_DBG("  ATTR_PROC_MEM_BASES[6]: %016llx", mem_bases[6]);
      FAPI_DBG("  ATTR_PROC_MEM_BASES[7]: %016llx", mem_bases[7]);

      rc = FAPI_ATTR_SET(ATTR_PROC_MEM_BASES, &i_target, mem_bases);
      if (!rc.ok())
      {
        FAPI_ERR("Error writing ATTR_PROC_MEM_BASES");
            //break;
      }

        // sizes for distinct non-mirrored ranges
      l_memory_sizes[0]=eff_grouping_data.groupID[0][2];
      l_memory_sizes[0] =  l_memory_sizes[0] <<30;
      l_memory_sizes[1]=eff_grouping_data.groupID[1][2];
      l_memory_sizes[1] =  l_memory_sizes[1] <<30;
      l_memory_sizes[2]=eff_grouping_data.groupID[2][2];
      l_memory_sizes[2] =  l_memory_sizes[2] <<30;
      l_memory_sizes[3]=eff_grouping_data.groupID[3][2];
      l_memory_sizes[3] =  l_memory_sizes[3] <<30;
      l_memory_sizes[4]=eff_grouping_data.groupID[4][2];
      l_memory_sizes[4] =  l_memory_sizes[4] <<30;
      l_memory_sizes[5]=eff_grouping_data.groupID[5][2];
      l_memory_sizes[5] =  l_memory_sizes[5] <<30;
      l_memory_sizes[6]=eff_grouping_data.groupID[6][2];
      l_memory_sizes[6] =  l_memory_sizes[6] <<30;
      l_memory_sizes[7]=eff_grouping_data.groupID[7][2];
      l_memory_sizes[7] =  l_memory_sizes[7] <<30;

      FAPI_DBG("  ATTR_PROC_MEM_SIZES[0]: %016llx", l_memory_sizes[0]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[1]: %016llx", l_memory_sizes[1]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[2]: %016llx", l_memory_sizes[2]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[3]: %016llx", l_memory_sizes[3]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[4]: %016llx", l_memory_sizes[4]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[5]: %016llx", l_memory_sizes[5]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[6]: %016llx", l_memory_sizes[6]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[7]: %016llx", l_memory_sizes[7]);

      rc = FAPI_ATTR_SET(ATTR_PROC_MEM_SIZES, &i_target, l_memory_sizes);
      if (!rc.ok())
      {
        FAPI_ERR("Error writing ATTR_PROC_MEM_SIZES");
        break;
      }
       rc = FAPI_ATTR_GET(ATTR_PROC_MEM_SIZES, &i_target, l_memory_sizes);
        if (!rc.ok())
      {
        FAPI_ERR("Error writing ATTR_PROC_MEM_SIZES");
        break;
      }
       FAPI_DBG("  ATTR_PROC_MEM_SIZES[0]: %016llx", l_memory_sizes[0]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[1]: %016llx", l_memory_sizes[1]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[2]: %016llx", l_memory_sizes[2]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[3]: %016llx", l_memory_sizes[3]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[4]: %016llx", l_memory_sizes[4]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[5]: %016llx", l_memory_sizes[5]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[6]: %016llx", l_memory_sizes[6]);
      FAPI_DBG("  ATTR_PROC_MEM_SIZES[7]: %016llx", l_memory_sizes[7]);

      rc = FAPI_ATTR_SET(ATTR_MSS_MCS_GROUP_32,&i_target, eff_grouping_data.groupID);
      if (!rc.ok())
      {
        FAPI_ERR("Error writing ATTR_MSS_MCS_GROUP");
        break;
      }
          // process mirrored ranges
        //

        // read chip base address attribute
///      rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASE, &i_chip_target, mirror_base);
//      if (!rc.ok())
//      {
//        FAPI_ERR("Error reading ATTR_PROC_MIRROR_BASE");
//        break;
//      }

        // base addresses for distinct mirrored ranges
      mirror_bases[0] = eff_grouping_data.groupID[8][3];
      mirror_bases[1] = eff_grouping_data.groupID[9][3];
      mirror_bases[2] = eff_grouping_data.groupID[10][3];
      mirror_bases[3] = eff_grouping_data.groupID[11][3];

      mirror_bases[0] = mirror_bases[0]<<30;
      mirror_bases[1] = mirror_bases[1]<<30;
      mirror_bases[2] = mirror_bases[2]<<30;
      mirror_bases[3] = mirror_bases[3]<<30;
      FAPI_DBG("  ATTR_PROC_MIRROR_BASES[0]: %016llx", mirror_bases[0]);
      FAPI_DBG("  ATTR_PROC_MIRROR_BASES[1]: %016llx", mirror_bases[1]);
      FAPI_DBG("  ATTR_PROC_MIRROR_BASES[2]: %016llx", mirror_bases[2]);
      FAPI_DBG("  ATTR_PROC_MIRROR_BASES[3]: %016llx", mirror_bases[3]);

      rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_BASES, &i_target, mirror_bases);
      if (!rc.ok())
      {
        FAPI_ERR("Error writing ATTR_PROC_MIRROR_BASES");
        break;
      }

        // sizes for distinct mirrored ranges
      l_mirror_sizes[0]=eff_grouping_data.groupID[8][2];
      l_mirror_sizes[1]=eff_grouping_data.groupID[9][2];
      l_mirror_sizes[2]=eff_grouping_data.groupID[10][2];
      l_mirror_sizes[3]=eff_grouping_data.groupID[11][2];

      l_mirror_sizes[0] = l_mirror_sizes[0]<<30;
      l_mirror_sizes[1] = l_mirror_sizes[1]<<30;
      l_mirror_sizes[2] = l_mirror_sizes[2]<<30;
      l_mirror_sizes[3] = l_mirror_sizes[3]<<30;

      FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[0]: %016llx", l_mirror_sizes[0]);
      FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[1]: %016llx", l_mirror_sizes[1]);
      FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[2]: %016llx", l_mirror_sizes[2]);
      FAPI_DBG("  ATTR_PROC_MIRROR_SIZES[3]: %016llx", l_mirror_sizes[3]);

      rc = FAPI_ATTR_SET(ATTR_PROC_MIRROR_SIZES, &i_target, l_mirror_sizes);
      if (!rc.ok())
      {
        FAPI_ERR("Error writing ATTR_PROC_MIRROR_SIZES");
        break;
       }
    }while(0);
    return rc;			
  }

  uint8_t  mss_eff_grouping_recursion(uint32_t number){
    uint32_t temp = number;
    uint8_t count=0;
    uint8_t buffersize=0;	
    while(1)
    {
      if(temp%2)
      {
        count++;buffersize++;
        temp=temp/2;
        FAPI_INF(" %d buffer Size %d*Count %d\n",number,buffersize,count);
      }
      else
      {
        temp=temp/2;
        buffersize++;
      }
      if (temp ==0 || temp ==1)
      {
        if(temp)
        {count++;}
        buffersize++;
        FAPI_INF(" %d buffer Size %d*Count %d\n",number,buffersize,count);
        break;	  	
      }
    }	
    return count;
  }

//#ifdef FAPIECMD
} //end extern C
//#endif
