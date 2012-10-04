/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_grouping.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: mss_eff_grouping.C,v 1.10 2012/09/27 11:11:53 bellows Exp $
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
//#include <mss_funcs.H>

//#ifdef FAPIECMD
extern "C" {
//#endif

  using namespace fapi;
//----------------------------------------------
// MSS EFF GROUPING FUNCTIONs............
//----------------------------------------------------

  ReturnCode mss_eff_grouping(const fapi::Target & i_target, std::vector<fapi::Target> & i_associated_centaurs); // Target is Proc target & Each MCS connected to each Centaur. Associated centaur is collection of the Centaure location for the processor
  uint8_t mss_eff_grouping_recursion(uint8_t number);
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
    Eff_Grouping_Data eff_grouping_data;
       //Eff_Grouping_Data &eff_grouping_data;
        //eff_grouping_data.groupID[16][16]={{0}};
    uint32_t pos=0;
    uint64_t mss_base_address;
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
      rc =  FAPI_ATTR_GET(ATTR_MSS_INTERLEAVE_ENABLE,&i_target,min_group);
      if(!rc.ok()) {FAPI_ERR("MSS_INTERLEAV_ENABLE is not available"); return rc;}
        //rc=mcs_grouping_general();
      if(!rc.ok()) {FAPI_ERR("MCS Grouping: fails at generating the MCS size"); return rc;}			
// 	groupID[i][0]=Size;
//  groupID[i][1]= number of MBA in the group for example 4 MBA in the group
//  groupID[i][2]= Total size of memory
//  groupID[i][3] to groupIDsize[i][6]  - group pos indication
      uint32_t temp[12];
      uint8_t min_group = 1;
      uint32_t max_group = 8;
      uint32_t mirroring =0;
      uint8_t pos_t=0;
      uint8_t count=0;
      uint8_t onemcs=0;
      if ((((eff_grouping_data.MCS_size[0] == eff_grouping_data.MCS_size[4])
            && (eff_grouping_data.MCS_size[1] == eff_grouping_data.MCS_size[5]))
           &&(eff_grouping_data.MCS_size[3]==eff_grouping_data.MCS_size[4])
           &&(eff_grouping_data.MCS_size[5]==eff_grouping_data.MCS_size[6])
           &&((eff_grouping_data.MCS_size[2] == eff_grouping_data.MCS_size[6])
              &&(eff_grouping_data.MCS_size[3] ==eff_grouping_data.MCS_size[7])))
          && l_unit_pos==8)
      {
        eff_grouping_data.groupID[0][1] =4;
        eff_grouping_data.groupID[0][4] =0;
        eff_grouping_data.groupID[0][5] =2;
        eff_grouping_data.groupID[0][6] =1;
        eff_grouping_data.groupID[0][7] =3;
        eff_grouping_data.groupID[0][0] = eff_grouping_data.MCS_size[4];	
        gp_pos=1;
        mirroring =1;
        FAPI_INF("Mirroring enabled\n");
      }
      else if ((((eff_grouping_data.MCS_size[0] == eff_grouping_data.MCS_size[1])
                 &&(eff_grouping_data.MCS_size[0] == eff_grouping_data.MCS_size[4])
                 &&(eff_grouping_data.MCS_size[4] == eff_grouping_data.MCS_size[5]))
                ||((eff_grouping_data.MCS_size[2] == eff_grouping_data.MCS_size[3])
                   &&(eff_grouping_data.MCS_size[2] == eff_grouping_data.MCS_size[6])
                   &&(eff_grouping_data.MCS_size[6] == eff_grouping_data.MCS_size[7])))
               && l_unit_pos==4)
      {
        eff_grouping_data.groupID[0][1] =2;
        eff_grouping_data.groupID[0][4] =4;
        eff_grouping_data.groupID[0][5] =5;
        eff_grouping_data.groupID[0][0] = eff_grouping_data.MCS_size[4];
        eff_grouping_data.groupID[1][1] =2;
        eff_grouping_data.groupID[1][4] =6;
        eff_grouping_data.groupID[1][5] =7;
        eff_grouping_data.groupID[1][0] = eff_grouping_data.MCS_size[5];
        gp_pos=2;
        mirroring =1;         	
        FAPI_INF("Mirroring enabled\n");
      }
      else
      {
        while(max_group>=min_group)
        {
          for(uint8_t i=0;i<16;i++)
            for(uint8_t j=0;j<16;j++)
              eff_grouping_data.groupID[i][j]=0;
          gp_pos=0;
          count=0;
          for(pos=0;pos<8;pos++)
          {
            eff_grouping_data.groupID[gp_pos][0] = eff_grouping_data.MCS_size[pos];
            eff_grouping_data.groupID[gp_pos][1] = 1;
            eff_grouping_data.groupID[gp_pos][4]= pos;
            gp_pos++;
          }
          for(pos_t=0;pos_t<=gp_pos;pos_t++)
          {
            for(pos=pos_t+1; pos<=gp_pos;pos++)
            {
              if(eff_grouping_data.groupID[pos_t][0] == eff_grouping_data.groupID[pos][0])
              {
                if( eff_grouping_data.groupID[pos_t][1]<max_group)
                {
                  eff_grouping_data.groupID[pos_t][1]++;
                  eff_grouping_data.groupID[pos_t][eff_grouping_data.groupID[pos_t][1]+3]=pos;
                  eff_grouping_data.groupID[pos][0]=0;
                  eff_grouping_data.groupID[pos][1]=0;
                }
                else {}
              }
            }	 	
          }
          for(uint8_t i=0;i<8;i++)
          {
            if ((eff_grouping_data.groupID[i][0]!= 0) && (eff_grouping_data.groupID[i][1] == max_group))
            { count += eff_grouping_data.groupID[i][1];FAPI_INF("group ID %dMCS size %d\n",i,eff_grouping_data.groupID[i][1]);}
          }
          if (count == l_unit_pos) { FAPI_INF("group done correctly\n");onemcs=0;break;}
          else{ FAPI_INF("this grouping is not possible with %d\n",max_group);onemcs=0;}
          max_group= max_group/2;
        }
      }  	  	
   // uint32_t temp[12];
      uint8_t i=0;
      uint8_t j=0;
    //uint8_t count=0;
      for(i=0;i<8;i++)
      {
        for(j=0;j<12;j++)
        {
          FAPI_INF(" groupID[%d][%d] = %d",i,j,eff_grouping_data.groupID[i][j]);
        }
        FAPI_INF("\n");
      }
      for(pos=0;pos<=gp_pos;pos++)
      {
        eff_grouping_data.groupID[pos][2] = eff_grouping_data.groupID[pos][0]*eff_grouping_data.groupID[pos][1];
        count =  mss_eff_grouping_recursion(eff_grouping_data.groupID[pos][2]);
        if(count>1)
        {
          FAPI_INF("MCS pos %d needs alternate bars defintation group Size %d\n",pos,eff_grouping_data.groupID[pos][3]);
          if (eff_grouping_data.MBA_size[pos][1] > eff_grouping_data.MBA_size[pos][0])
          {
            eff_grouping_data.groupID[pos][2] = eff_grouping_data.MBA_size[pos][1]*2*eff_grouping_data.groupID[pos][1];
            eff_grouping_data.groupID[pos][13] = eff_grouping_data.groupID[pos][1]*eff_grouping_data.MBA_size[pos][1];
          }
          else
          {
            eff_grouping_data.groupID[pos][2] = eff_grouping_data.MBA_size[pos][0]*2*eff_grouping_data.groupID[pos][1];
            eff_grouping_data.groupID[pos][13] = eff_grouping_data.groupID[pos][1]*eff_grouping_data.MBA_size[pos][0];
          }
          eff_grouping_data.groupID[pos][12] =1;
        }		
      }
      for(pos=0;pos<=gp_pos;pos++)
      {
        eff_grouping_data.groupID[pos][2] = eff_grouping_data.groupID[pos][0]*eff_grouping_data.groupID[pos][1];
      }
      for(pos=0;pos<=gp_pos;pos++)
      {	
        for(i=pos;i< gp_pos;i++)
        {
          if ( eff_grouping_data.groupID[i][2] > eff_grouping_data.groupID[pos][2])
          {
            for(j=0;j<12;j++)	temp[j] = eff_grouping_data.groupID[pos][j];
            for(j=0;j<12;j++)	eff_grouping_data.groupID[pos][j] = eff_grouping_data.groupID[i][j];
            for(j=0;j<12;j++)	eff_grouping_data.groupID[i][j] = temp[j];
          }
          else {}
        }	
      }			
      rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE,&i_target,mss_base_address);
      mss_base_address =   mss_base_address >> 30;
      if(!rc.ok()) return rc;
      for(pos=0;pos<=gp_pos;pos++)
      {
        if(pos==0)
        {
          eff_grouping_data.groupID[pos][3] = mss_base_address;
          if(eff_grouping_data.groupID[pos][12])
          {
            eff_grouping_data.groupID[pos][14] = eff_grouping_data.groupID[pos][3]+ eff_grouping_data.groupID[pos][2];
          }
        }
        else
        {
          eff_grouping_data.groupID[pos][3] = eff_grouping_data.groupID[pos-1][3]+eff_grouping_data.groupID[pos-1][2];
          if(eff_grouping_data.groupID[pos][12])
          {
            eff_grouping_data.groupID[pos][14] = eff_grouping_data.groupID[pos][3]+ eff_grouping_data.groupID[pos][2];
          }
        }		
      }		
      uint64_t mem_bases[8];
      uint64_t l_memory_sizes[8];
        //uint32_t temp[8];
      for(uint8_t i=0;i<8;i++)
      {
        if(eff_grouping_data.groupID[i][0]>0)
        {
          FAPI_INF (" Group   %d MCS Size  %4d   ",i,eff_grouping_data.groupID[i][0]);
          FAPI_INF (" No of MCS %4d ",eff_grouping_data.groupID[i][1]);
          FAPI_INF (" Group Size %4d ",eff_grouping_data.groupID[i][2]);
          FAPI_INF (" Base Add.  %4d ",eff_grouping_data.groupID[i][3]);
          for(uint8_t j=4;j<4+eff_grouping_data.groupID[i][1];j++)
          {
            FAPI_INF (" MCSID%d- Pos %4d",(j-4),eff_grouping_data.groupID[i][j]);
          }
          FAPI_INF (" Alter-bar  %4d",eff_grouping_data.groupID[i][12]);
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
      rc = FAPI_ATTR_SET(ATTR_MSS_MCS_GROUP_32,&i_target,eff_grouping_data.groupID);
      if (!rc.ok())
      {
        FAPI_ERR("Error writing ATTR_MSS_MCS_GROUP");
        break;
      }
    }while(0);
    return rc;			
  }

  uint8_t  mss_eff_grouping_recursion(uint8_t number){
    uint8_t temp = number;
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
