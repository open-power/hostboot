/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_setup_bars/mss_setup_bars.C $ */
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
// $Id: mss_setup_bars.C,v 1.25 2012/12/04 14:47:59 bellows Exp $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_setup_bars.C
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
//  1.23   | bellows  | 12/04/12| more updates
//  1.22   | gpaulraj | 10/03/12| review updates
//  1.21   | gpaulraj | 10/02/12| review updates
//  1.19   | bellows  | 09/25/12| review updates
//  1.18   | bellows  | 09/06/12| updates suggested by Van
//  1.17   | bellows  | 08/31/12| use the final 32bit attribute
//  1.16   | bellows  | 08/29/12| remove compile error, use 32bit group info
//         |          |         | as a temporary fix
//  1.10   | bellows  | 07/16/12| added in Id tag
//  1.4    | bellows  | 06-05-12| Updates to Match First Configuration, work for P8 and Murano
//  1.3    | gpaulraj | 05-22-12| 2MCS/group supported for 128GB CDIMM
//  1.2    | gpaulraj | 05-07-12| 256 group configuration in
//  1.1    | gpaulraj | 03-19-12| First drop for centaur
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <mss_setup_bars.H>

extern "C" {

  fapi::ReturnCode mss_setup_bars(
                                  const fapi::Target& i_chip_target)
  {
    fapi::ReturnCode rc;
    std::vector<fapi::Target> l_mcs_chiplets;
    ecmdDataBufferBase MCFGP_data(64);
    ecmdDataBufferBase MCFGPM_data(64);
    ecmdDataBufferBase MCFGPA_data(64);
    ecmdDataBufferBase MCFGPMA_data(64);
//    uint64_t mem_base;
//    uint64_t mirror_base;
    uint64_t mem_bases[8];
    uint64_t l_memory_sizes[8];
    uint64_t mirror_bases[4];
    uint64_t l_mirror_sizes[4];
//    uint64_t alter_mem_base;
//    uint64_t alter_mirror_base;
    uint32_t groupID[16][16];
    uint8_t groups[8];
    do
    {
      rc = FAPI_ATTR_GET(ATTR_MSS_MCS_GROUP_32, &i_chip_target, groupID);
      if (!rc.ok())
      {
        FAPI_ERR("Error reading ATTR_MSS_MCS_GROUP_32");
        break;
      }
      rc = FAPI_ATTR_GET(ATTR_PROC_MEM_SIZES, &i_chip_target, l_memory_sizes);
      if (!rc.ok())
      {
        FAPI_ERR("Error reading ATTR_PROC_MEM_SIZES");
        break;
      }
      rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASES, &i_chip_target, mem_bases);
      if (!rc.ok())
      {
        FAPI_ERR("Error reading ATTR_PROC_MEM_BASES");
        break;
      }
        //base addresses for distinct non-mirrored ranges

        //
        // process non-mirrored ranges
        //

        // read chip base address attribute
        //
        // process mirrored ranges
        //

      rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASES, &i_chip_target, mirror_bases);
      if (!rc.ok())
      {
        FAPI_ERR("Error reading ATTR_PROC_MIRROR_BASES");
        break;
      }
      rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_SIZES, &i_chip_target, l_mirror_sizes);
      if (!rc.ok())
      {
        FAPI_ERR("Error  reading ATTR_PROC_MIRROR_SIZES");
        break;
      }
      rc = FAPI_ATTR_GET(ATTR_MSS_MEM_MC_IN_GROUP, &i_chip_target, groups);
      if (!rc.ok())
      {
        FAPI_ERR("Error  reading ATTR_MSS_MEM_MC_IN_GROUP");
        break;
      }

        //
        // write HW registers
        //

        // get child MCS chiplets
      rc = fapiGetChildChiplets(i_chip_target,
                                fapi::TARGET_TYPE_MCS_CHIPLET,
                                l_mcs_chiplets,
                                fapi::TARGET_STATE_FUNCTIONAL);
      if (!rc.ok())
      {
        FAPI_ERR("Error from fapiGetChildChiplets");
        break;
      }

        // loop through & set configuration of each child
      for (std::vector<fapi::Target>::iterator iter = l_mcs_chiplets.begin();
           iter != l_mcs_chiplets.end() && rc.ok();
           iter++)
      {
        uint8_t mcs_pos = 0x0;
        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*iter), mcs_pos);
        if (!rc.ok())
        {
          FAPI_ERR("Error reading ATTR_CHIP_UNIT_POS");
          break;
        }

        MCFGP_data.flushTo0();
        MCFGPM_data.flushTo0();
        MCFGPA_data.flushTo0();
        MCFGPMA_data.flushTo0();
        rc = fapiGetScom(*iter, MCS_MCFGP_0x02011800, MCFGP_data);
        if (!rc.ok())
        {
          FAPI_ERR("Error Reading  MCS_MCFGP_0x02011800");
          break;
        }
        MCFGP_data.setBit(9);
        MCFGP_data.setBit(10);
        MCFGP_data.setBit(24);
        rc = fapiPutScom(*iter, MCS_MCFGP_0x02011800, MCFGP_data);
        if (!rc.ok())
        {
          FAPI_ERR("Error writing  MCS_MCFGP_0x02011800");
          break;
        }
        rc = fapiGetScom(*iter, MCS_MCFGPM_0x02011801, MCFGPM_data);
        if (!rc.ok())
        {
          FAPI_ERR("Error Reading  MCS_MCFGPM_0x02011801");
          break;
        }	       	
        for(uint8_t i=0; (i<16)&&(rc.ok()); i++)
        {
          uint32_t temp=0;
          temp = groupID[i][1];
          uint32_t b=0;
          for(uint32_t j=4;(j<temp+4)&&(rc.ok());j++)
          {
            if(groupID[i][j]==mcs_pos)
            {
              FAPI_INF(" Group ID of no MCS %d is %d MCS_POS  ID  found for %d as %d ",temp, i,mcs_pos,(j-4));
                        //temp =(temp/2;
              MCFGP_data.insertFromRight(temp/2,1,3);
              MCFGP_data.insertFromRight((j-4),4,5);

              b = ((l_memory_sizes[i]>>30) / 4) - 1;
              MCFGP_data.insertFromRight(b,11,13);
              b = mem_bases[i]>>32;
              MCFGP_data.insertFromRight(b,26,18);
              MCFGP_data.setBit(25);
              rc = fapiPutScom(*iter, MCS_MCFGP_0x02011800, MCFGP_data);
              if (!rc.ok())
              {
                FAPI_ERR("Error writing  MCS_MCFGP_0x02011800");
                break;
              }		
              rc = fapiGetScom(*iter, MCS_MCFGP_0x02011800, MCFGP_data);
              if (!rc.ok())
              {
                FAPI_ERR("Error Reading  MCS_MCFGP_0x02011800");
                break;
              }			
              MCFGP_data.setBit(0);  //  Read registers value and set Zero bit as per register specification
              FAPI_DBG("Writing MCS %d MCFGP = 0x%llx",mcs_pos, MCFGP_data.getDoubleWord(0));
              rc = fapiPutScom(*iter, MCS_MCFGP_0x02011800, MCFGP_data);
              if (!rc.ok())
              {
                FAPI_ERR("Error from fapiPutScom MCS_MCFGP_0x02011800");
                break;
              }

             if(temp>1)
             {

                //setting the MCFGPM register
                  b = ((l_mirror_sizes[i]>>30) / 4) - 1;
                  MCFGPM_data.insertFromRight(b,11,13);
                  b = mirror_bases[i]>>32;
                  MCFGPM_data.insertFromRight(b,26,18);
                  rc = fapiPutScom(*iter, MCS_MCFGPM_0x02011801, MCFGPM_data);
                  if (!rc.ok())
                  {
                     FAPI_ERR("Error writing  MCS_MCFGPM_0x02011801");
                     break;
                  }		       		
                  rc = fapiGetScom(*iter, MCS_MCFGPM_0x02011801, MCFGPM_data);
                  if (!rc.ok())
                  {
                    FAPI_ERR("Error reading  MCS_MCFGPM_0x02011801");
                    break;
                  }

                  MCFGPM_data.setBit(0);
                  FAPI_DBG("Writing MCS %d MCFGPM = 0x%llx",mcs_pos, MCFGPM_data.getDoubleWord(0));
                  rc = fapiPutScom(*iter, MCS_MCFGPM_0x02011801, MCFGPM_data);
                  if (!rc.ok())
                  {
                     FAPI_ERR("Error from fapiPutScom MCS_MCFGPM_0x02011801");
                     break;
                  }
              }

              if(groupID[i][12])

              {

                b = (groupID[i][13] / 4) - 1;
                MCFGPA_data.insertFromRight(b,11,13);
                b = groupID[i][14]>>2;
                MCFGPA_data.insertFromRight(b,26,18);
                rc = fapiPutScom(*iter, MCS_MCFGPA_0x02011814, MCFGPA_data);
                if (!rc.ok())
                {
                  FAPI_ERR("Error writing  MCS_MCFGPA_0x02011814");
                  break;
                }		       		
                rc = fapiGetScom(*iter, MCS_MCFGPA_0x02011814, MCFGPA_data);
                if (!rc.ok())
                {
                  FAPI_ERR("Error reading  MCS_MCFGPA_0x02011814");
                  break;
                }					
                MCFGPA_data.setBit(0);  //  Read registers value and set Zero bit as per register specification
                FAPI_DBG("Writing MCS %d MCFGPA = 0x%llx",mcs_pos, MCFGPA_data.getDoubleWord(0));
                rc = fapiPutScom(*iter, MCS_MCFGPA_0x02011814, MCFGPA_data);
                if (!rc.ok())
                {
                  FAPI_ERR("Error writing  MCS_MCFGPA_0x02011814");
                  break;
                }		       		

                if(temp>1)
                {
                   //setting MCFGPMA
                   b = (groupID[i+8][13]/ 4) - 1;
                   MCFGPMA_data.insertFromRight(b,11,13);
                   b = groupID[i+8][14]>>2;
                   MCFGPMA_data.insertFromRight(b,26,18);
                   rc = fapiPutScom(*iter, MCS_MCFGPMA_0x02011815, MCFGPMA_data);
                   if (!rc.ok())
                   {
                     FAPI_ERR("Error writing  MCS_MCFpGPMA_0x02011815");
                     break;
                   }		       		
                   rc = fapiGetScom(*iter, MCS_MCFGPMA_0x02011815, MCFGPMA_data);
                   if (!rc.ok())
                   {
                     FAPI_ERR("Error reading  MCS_MCFGPMA_0x02011815");
                     break;
                   }					
                   MCFGPMA_data.setBit(0);  //  Read registers value and set Zero bit as per register specification
                   FAPI_DBG("Writing MCS %d MCFGPMA = 0x%llx",mcs_pos, MCFGPMA_data.getDoubleWord(0));
                   rc = fapiPutScom(*iter, MCS_MCFGPMA_0x02011815, MCFGPMA_data);
                   if (!rc.ok())
                   {
                     FAPI_ERR("Error writing  MCS_MCFGPMA_0x02011815");
                     break;
                   }
                 }
              }
            }
          }
        }
      }
       uint8_t final=1;
       rc=FAPI_ATTR_SET( ATTR_MSS_MEM_IPL_COMPLETE, &i_chip_target ,final);
       if (!rc.ok())
       {
           FAPI_ERR("Error writing  TARGET_TYPE_PROC_CHIP");
           break;
        }
    }while(0);
    return rc;
  }

} // extern "C"
