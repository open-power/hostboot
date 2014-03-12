/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_eff_grouping.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: mss_eff_grouping.C,v 1.00 2013/11/21 08:50:19 gpaulraj Exp $
// Mike Jones - modified version from 1.28 to 1.00 because it is a sandbox version
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
//  1.28   | gpaulraj | 11-21-13| modified 8MCS/group id as per spec
//  1.27   | gpaulraj | 08-13-13| Fixed alternate BAR settings for Mirror
//  1.26   | gpaulraj | 08-12-13| added mirror policy and HTM/OCC Bar setup
//  1.25   | gpaulraj | 05-23-13| Fixed FW review feedback
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

#include <fapi.H>
#include <mss_eff_grouping.H>
#include "cen_scom_addresses.H"
#include <mss_error_support.H>

//#ifdef FAPIECMD
extern "C"
{

//#endif
  using namespace fapi;

//----------------------------------------------
// MSS EFF GROUPING FUNCTIONs............
//----------------------------------------------------
  ReturnCode mss_eff_grouping (const fapi::Target & i_target, std::vector < fapi::Target > &i_associated_centaurs);     // Target is Proc target & Each MCS connected to each Centaur. Associated centaur is collection of the Centaure location for the processor
  uint8_t mss_eff_grouping_recursion (uint32_t number);

//----------------------------------------------------
// MSS EFF GROUPING Variables..........
//----------------------------------------------------
  const uint8_t MCS_SIZE = 0;
  const uint8_t MCS_IN_GROUP = 1;
  const uint8_t GROUP_SIZE = 2;
  const uint8_t BASE_ADDR = 3;
  const uint8_t MEMBERS_START_ID = 4;
  const uint8_t MEMBERS_END = 11;
  const uint8_t ALT_VALID = 12;
  const uint8_t ALT_SIZE = 13;
  const uint8_t ALT_BASE_ADDR = 14;
  const uint8_t LARGEST_MBA_SIZE = 15;
  const uint8_t MCS_GROUP_8 = 0x8;
  const uint8_t MCS_GROUP_4 = 0x4;
  const uint8_t MCS_GROUP_2 = 0x2;
  const uint8_t MCS_GROUP_1 = 0x1;
  const uint8_t MCSID_0 = 0x0;
  const uint8_t MCSID_1 = 0x1;
  const uint8_t MCSID_2 = 0x2;
  const uint8_t MCSID_3 = 0x3;
  const uint8_t MCSID_4 = 0x4;
  const uint8_t MCSID_5 = 0x5;
  const uint8_t MCSID_6 = 0x6;
  const uint8_t MCSID_7 = 0x7;
  const uint8_t NORMAL_MODE =    0x0;
  const uint8_t FLIPPED_MODE =   0x1;
  const uint8_t SELECTIVE_MODE = 0x2;

  ReturnCode mss_eff_grouping (const fapi::Target & i_target,
                               std::vector < fapi::Target >
                               &i_associated_centaurs)
  {
    ReturnCode rc;
    Eff_Grouping_Data eff_grouping_data, tempgpID;
    uint64_t mss_base_address;
    uint64_t mirror_base;
    uint64_t occ_sandbox_base = 0;
    uint64_t occ_sandbox_size;
    uint64_t htm_bar_base = 0;
    uint64_t htm_bar_size;
    uint32_t l_unit_pos = 0;
    uint8_t gp_pos = 0;
    uint8_t min_group = 1;
    int i, j;
    for (i = 0; i < MBA_SIZE_MCS; i++)
      {
        eff_grouping_data.MCS_size[i] = 0;
        for (j = 0; j < MBA_SIZE_PORT; j++)
          eff_grouping_data.MBA_size[i][j] = 0;
      }
    for (i = 0; i < MBA_GROUP_SIZE; i++)
      {
        for (j = 0; j < MBA_GROUP_DATA; j++)
          eff_grouping_data.groupID[i][j] = 0;
      }

//------------------------------------------------
// do-while used for return rc make more effective
//------------------------------------------------
    do

      {
        FAPI_INF ("MCS level grouping begins");
        uint8_t centaur;
        uint8_t mba_i;
        uint8_t mba = 0;
        uint8_t dimm = 0;
        uint32_t cenpos;
        uint32_t procpos;
        uint8_t port;
        uint8_t mba_pos[2][2] = {
          {
           0, 0}
          ,
          {
           0, 0}
        };
        std::vector < fapi::Target > l_mba_chiplets;
        std::vector < fapi::Target > l_mcs_chiplets;
        FAPI_INF ("Happy starting");
        rc =
          fapiGetChildChiplets (i_target, fapi::TARGET_TYPE_MCS_CHIPLET,
                                l_mcs_chiplets);
        if (rc)
          return rc;
        FAPI_INF ("Number of MCS chiplets: %d", l_mcs_chiplets.size ());
        uint8_t cen_count = 0;
        rc = FAPI_ATTR_GET (ATTR_POS, &i_target, procpos);
        if (rc)
          return rc;

//-----------------------------------------------------------------------
//   Collecting Each centaur total memory size and assigning as MCS size
//-----------------------------------------------------------------------
        for (centaur = 0; centaur < i_associated_centaurs.size (); centaur++)

          {
            mba = 0;
            port = 0;
            dimm = 0;
            fapi::Target & centaur_t = i_associated_centaurs[centaur];
            rc = FAPI_ATTR_GET (ATTR_POS, &centaur_t, cenpos);
            if (rc)
              return rc;
            if (cenpos >= procpos * 8 && cenpos < (procpos * 8 + 8))

              {
                FAPI_INF ("... working on centaur %d", cenpos);
                rc =
                  fapiGetChildChiplets (i_associated_centaurs[centaur],
                                        fapi::TARGET_TYPE_MBA_CHIPLET,
                                        l_mba_chiplets);
                if (rc)
                  return rc;
                for (mba_i = 0; mba_i < l_mba_chiplets.size (); mba_i++)

                  {
                    rc =
                      FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS,
                                     &l_mba_chiplets[mba_i], mba);         // Collecting all Centaur CHIP pos ID for current processor
                    if (rc)
                      return rc;
                    FAPI_INF ("... working on mba %d", mba);
                    rc =
                      FAPI_ATTR_GET (ATTR_EFF_DIMM_SIZE,
                                     &l_mba_chiplets[mba_i], mba_pos);      // Collecting all Centaur DIMM sizes for current processor
                    if (rc)
                      return rc;
                    for (port = 0; port < 2; port++)

                      {
                        for (dimm = 0; dimm < 2; dimm++)

                          {
                            eff_grouping_data.MCS_size[cenpos -
                                                       procpos * 8] +=
                              mba_pos[port][dimm];
                            eff_grouping_data.MBA_size[cenpos -
                                                       procpos * 8][mba] +=
                              mba_pos[port][dimm];
                          }
                      }
                    FAPI_INF (" Cen Pos %d mba %d DIMM SIZE %d \n", cenpos,
                              mba,
                              eff_grouping_data.MBA_size[cenpos -
                                                         procpos * 8][mba]);
                    FAPI_INF (" Cen Pos %d MBA SIZE %d %d  %d %d \n", cenpos,
                              mba_pos[0][0], mba_pos[0][1], mba_pos[1][0],
                              mba_pos[1][1]);
                    FAPI_INF (" MCS SIZE %d\n",
                              eff_grouping_data.MCS_size[cenpos -
                                                         procpos * 8]);
                  }
                cen_count++;
                l_unit_pos++;
              }
          }
        FAPI_INF ("attr_mss_setting %d and  no  of MBAs   %d \n", min_group,
                  l_unit_pos);

//-------------------------------------------------------------------------------------
//    Printing out each MCS size
//------------------------------------------------------------------------------------
        for (uint8_t i = 0; i < 8; i++)

          {
            FAPI_INF ("MCS SIZE %d \n", eff_grouping_data.MCS_size[i]);
          }
        FAPI_INF ("Group parsing Starting..");
        uint8_t count = 0;
        uint8_t done;
        uint8_t pos;
        // Possibility way of forming 4 MCS/GROUP along with priority way assigned in the arrary. array [0] given high priority and array[5] given low priority
        uint8_t config_4MCS[6][4] = {
          {
           MCSID_0, MCSID_1, MCSID_4, MCSID_5}
          ,
          {
           MCSID_2, MCSID_3, MCSID_6, MCSID_7}
          ,
          {
           MCSID_0, MCSID_1, MCSID_6, MCSID_7}
          ,
          {
           MCSID_2, MCSID_3, MCSID_4, MCSID_5}
          ,
          {
           MCSID_0, MCSID_1, MCSID_2, MCSID_3}
          ,
          {
           MCSID_4, MCSID_5, MCSID_6, MCSID_7}
        };
        int flag;
        uint8_t config4_pos[6];
        uint8_t groups_allowed;
        uint8_t grouped[16];
        uint8_t check_board;
        uint8_t gp = 0;
        uint8_t pos1 = 0;
        uint8_t pos2 = 0;
        uint8_t allowed = 0;
        uint8_t selective_mode;
        uint8_t M_valid;
        uint8_t mcs_pos;
        for (uint8_t i = 0; i < 6; i++)
          config4_pos[i] = 0;

//-------------------------------------------------------------------------------------
//   Getting system and cage attriutes for deciding on MCS grouping policy
//-------------------------------------------------------------------------------------
        rc =
          FAPI_ATTR_GET (ATTR_MSS_INTERLEAVE_ENABLE, &i_target,
                         groups_allowed);                                               // Allowed grouping policy for example 0x02 means 2 MCS/group is allowed
        if (!rc.ok ())
          {
            FAPI_ERR ("MSS_INTERLEAVE_ENABLE is not available");
            return rc;
          }
        rc = FAPI_ATTR_GET (ATTR_ALL_MCS_IN_INTERLEAVING_GROUP, NULL, check_board);     // system level attribute, Decided Interleaving enabled for MCS level
        if (!rc.ok ())
          {
            FAPI_ERR ("Error reading ATTR_ALL_MCS_IN_INTERLEAVING_GROUP");
            return rc;
          }
        rc =
          FAPI_ATTR_GET (ATTR_MEM_MIRROR_PLACEMENT_POLICY, NULL,
                         selective_mode);                                              // Baremetal exerciser policy defintation
        if (!rc.ok ())
          {
            FAPI_ERR ("Error reading ATTR_MEM_MIRROR_PLACEMENT_POLICY");
            return rc;
          }

    // Mike Jones: Firmware does not support this right now, set to false as
    // this is value in MRW
    M_valid = 0;
//        rc = FAPI_ATTR_GET (ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING, NULL, M_valid);    // P-series & stradale support
//        if (!rc.ok ())

//          {
//            FAPI_ERR
//              ("mss_setup_bars: Error reading ATTR_MRW_ENHANCED_GROUPING_NO_MIRRORING");
//            return rc;
//          }
        if (M_valid && !(selective_mode == NORMAL_MODE ))

          {
            if (selective_mode == SELECTIVE_MODE)

              {
                FAPI_ERR
                  ("MIRRORING IS DISABLED , SELECTIVE MODE CANNOT BE CONFIGURED");
              }

            else if (selective_mode == FLIPPED_MODE)

              {
                FAPI_ERR
                  ("MIRRORING IS DISABLED , FLIPPED MODE CANNOT BE CONFIGURED");
              }
            return rc;
          }
        if (check_board)        // this is a 1 when interleaving is required to be on  Only acceptable > 1MCS per group
          {
            if ((groups_allowed & MCS_GROUP_2) || (groups_allowed & MCS_GROUP_4)
                || (groups_allowed & MCS_GROUP_8))

              {
                FAPI_INF ("FABRIC IS IN NON-CHECKER BOARD MODE.");
                FAPI_INF ("FABRIC SUPPORTS THE FOLLOWING ");
                if (groups_allowed & MCS_GROUP_2)
                  {
                    FAPI_INF ("2MCS/GROUP");
                  }
                if (groups_allowed & MCS_GROUP_4)
                  {
                    FAPI_INF ("4MCS/GROUP");
                  }
                if (groups_allowed & MCS_GROUP_8)
                  {
                    FAPI_INF ("8MCS/GROUP");
                  }
                FAPI_INF ("FABRIC DOES NOT SUPPORT THE FOLLOWING ");
                FAPI_INF ("1MCS/GROUP");
                if (!(groups_allowed & MCS_GROUP_2))
                  {
                    FAPI_INF ("2MCS/GROUP");
                  }
                if (!(groups_allowed & MCS_GROUP_4))
                  {
                    FAPI_INF ("4MCS/GROUP");
                  }
                if (!(groups_allowed & MCS_GROUP_8))
                  {
                    FAPI_INF ("8MCS/GROUP");
                  }
              }

            else

              {
                FAPI_ERR ("UNABLE TO GROUP");
                FAPI_ERR
                  ("FABRIC IS IN NON-CHECKER BOARD MODE.  SET ATTRIBUTE 'ATTR_MSS_INTERLEAVE_ENABLE' , TO SUPPORT 2MCS , 4MCS AND 8MCS GROUPING. OR ENABLE CHECKER BOARD. ");
                const fapi::Target & PROC_CHIP = i_target;
                FAPI_SET_HWP_ERROR (rc,
                                    RC_MSS_NON_CHECKER_BOARD_MODE_GROUPING_NOT_POSSIBLE);
                return rc;
              }
          }

        else                    // Fabric is in checkerboard mode, allow all sizes.  Anything but 1 will have performance impacts
          {
            if ((groups_allowed & MCS_GROUP_1) || (groups_allowed & MCS_GROUP_2)
                || (groups_allowed & MCS_GROUP_4) || (groups_allowed & MCS_GROUP_8))

              {
                FAPI_INF
                  ("FABRIC IS IN CHECKER BOARD MODE AND IT SUPPORTS THE FOLLOWING ");
                if (groups_allowed & MCS_GROUP_1)
                  {
                    FAPI_INF ("1MCS/GROUP");
                  }
                if (groups_allowed & MCS_GROUP_2)
                  {
                    FAPI_INF ("2MCS/GROUP");
                  }
                if (groups_allowed & MCS_GROUP_4)
                  {
                    FAPI_INF ("4MCS/GROUP");
                  }
                if (groups_allowed & MCS_GROUP_8)
                  {
                    FAPI_INF ("8MCS/GROUP");
                  }
                FAPI_INF ("FABRIC DOES NOT SUPPORT THE FOLLOWING ");
                if (!(groups_allowed & MCS_GROUP_1))
                  {
                    FAPI_INF
                      ("FABRIC IS IN CHECKER BOARD MODE BUT YOU ARE ASKING FOR MORE THAN 1MCS/GROUP. YOU ARE NOT GOING TO HAVE PERFOMRANCE YOU COULD GET IF YOU WERE IN CHECKERBOARD MODE");
                  }
                if (!(groups_allowed & MCS_GROUP_2))
                  {
                    FAPI_INF ("2MCS/GROUP");
                  }
                if (!(groups_allowed & MCS_GROUP_4))
                  {
                    FAPI_INF ("4MCS/GROUP");
                  }
                if (!(groups_allowed & MCS_GROUP_8))
                  {
                    FAPI_INF ("8MCS/GROUP");
                  }
                if ((groups_allowed & MCS_GROUP_2) || (groups_allowed & MCS_GROUP_4)
                    || (groups_allowed & MCS_GROUP_8))
                  {
                    FAPI_INF
                      ("FABRIC IS IN CHECKER BOARD MODE BUT YOU ARE ASKING FOR MORE THAN 1MCS/GROUP. YOU ARE NOT GOING TO HAVE PERFOMRANCE YOU COULD GET IF YOU WERE IN CHECKERBOARD MODE");
                  }
              }

            else

              {
                FAPI_ERR ("UNABLE TO GROUP");
                FAPI_ERR
                  ("FABRIC IS IN CHECKER BOARD MODE . SET ATTRIBUTE 'ATTR_MSS_INTERLEAVE_ENABLE' ");
                const fapi::Target & PROC_CHIP = i_target;
                FAPI_SET_HWP_ERROR (rc,
                                    RC_MSS_CHECKER_BOARD_MODE_GROUPING_NOT_POSSIBLE);
                return rc;
              }
          }
        for (uint8_t i = 0; i < 16; i++)

          {
            grouped[i] = 0;
            for (uint8_t j = 0; j < 16; j++)

              {
                eff_grouping_data.groupID[i][j] = 0;
                tempgpID.groupID[i][j] = 0;
              }
          }
        gp_pos = 0;
        for (pos = 0; pos < 8; pos++)

          {
            eff_grouping_data.groupID[gp_pos][MCS_SIZE] =
              eff_grouping_data.MCS_size[pos];
            eff_grouping_data.groupID[gp_pos][MCS_IN_GROUP] = 1;
            eff_grouping_data.groupID[gp_pos][MEMBERS_START_ID] = pos;
            if (eff_grouping_data.MBA_size[pos][0] >
                eff_grouping_data.MBA_size[pos][1])
              eff_grouping_data.groupID[gp_pos][LARGEST_MBA_SIZE] =
                eff_grouping_data.MBA_size[pos][0];

            else
              eff_grouping_data.groupID[gp_pos][LARGEST_MBA_SIZE] =
                eff_grouping_data.MBA_size[pos][1];
            gp_pos++;
          }
        done = 0;
// setting up 8 MCS/group
        if (!done && (groups_allowed & MCS_GROUP_8))

          {
            count = 0;
            for (pos = 0; pos < gp_pos; pos++)

              {
                if (eff_grouping_data.groupID[0][MCS_SIZE] ==
                    eff_grouping_data.groupID[pos][MCS_SIZE]
                    && eff_grouping_data.groupID[pos][MCS_SIZE] != 0)

                  {
                    count++;
                  }
              }
            if (count == 8)

              {
                done = 1;
                eff_grouping_data.groupID[0][MCS_IN_GROUP] = 8;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 0] = MCSID_0;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 1] = MCSID_4;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 2] = MCSID_2;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 3] = MCSID_6;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 4] = MCSID_1;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 5] = MCSID_5;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 6] = MCSID_3;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 7] = MCSID_7;
                for (uint8_t i = 1; i < 16; i++)
                  for (uint8_t j = 0; j < 16; j++)
                    eff_grouping_data.groupID[i][j] = 0;
              }
          }
// setting up 4 MCS/group
        if (!done && (groups_allowed & MCS_GROUP_4))

          {
            count = 0;
            for (uint8_t i = 0; i < 6; i++)

              {
                flag = 0;
                for (int j = 0; j < 4; j++)

                  {
                    if ((eff_grouping_data.groupID[config_4MCS[i][0]][0] ==
                         0)
                        || (eff_grouping_data.
                            groupID[config_4MCS[i][0]][0] !=
                            eff_grouping_data.groupID[config_4MCS[i][j]][0]))

                      {
                        flag = 1;
                      }
                  }
                if (!flag)

                  {
                    config4_pos[i] = 1;
                    count++;
                  }
              }
            if (count >= 2)

              {
                if (config4_pos[0] && config4_pos[1])

                  {
                    allowed = 1;
                    pos1 = MCSID_0;
                    pos2 = MCSID_1;
                  }

                else if (config4_pos[2] && config4_pos[3])

                  {
                    allowed = 1;
                    pos1 = MCSID_2;
                    pos2 = MCSID_3;
                  }

                else if (config4_pos[4] && config4_pos[5])

                  {
                    allowed = 1;
                    pos1 = MCSID_4;
                    pos2 = MCSID_5;
                  }
              }
            if (allowed)

              {
                done = 1;

                //define the group_data
                eff_grouping_data.groupID[0][MCS_SIZE] =
                  eff_grouping_data.groupID[config_4MCS[pos1][0]][0];
                eff_grouping_data.groupID[0][MCS_IN_GROUP] = 4;
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 0] =
                  config_4MCS[pos1][0];
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 1] =
                  config_4MCS[pos1][2];
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 2] =
                  config_4MCS[pos1][1];
                eff_grouping_data.groupID[0][MEMBERS_START_ID + 3] =
                  config_4MCS[pos1][3];
                eff_grouping_data.groupID[0][LARGEST_MBA_SIZE] =
                  eff_grouping_data.groupID[config_4MCS[pos1][0]][15];
                eff_grouping_data.groupID[1][MCS_SIZE] =
                  eff_grouping_data.groupID[config_4MCS[pos2][0]][0];
                eff_grouping_data.groupID[1][MCS_IN_GROUP] = 4;
                eff_grouping_data.groupID[1][MEMBERS_START_ID + 0] =
                  config_4MCS[pos2][0];
                eff_grouping_data.groupID[1][MEMBERS_START_ID + 1] =
                  config_4MCS[pos2][2];
                eff_grouping_data.groupID[1][MEMBERS_START_ID + 2] =
                  config_4MCS[pos2][1];
                eff_grouping_data.groupID[1][MEMBERS_START_ID + 3] =
                  config_4MCS[pos2][3];
                eff_grouping_data.groupID[1][LARGEST_MBA_SIZE] =
                  eff_grouping_data.groupID[config_4MCS[pos2][0]][15];
                for (uint8_t i = 2; i < 16; i++)
                  for (uint8_t j = 0; j < 16; j++)
                    eff_grouping_data.groupID[i][j] = 0;
              }

            else if (count == 1 || !allowed)

              {
                for (uint8_t i = 0; i < 6; i++)

                  {
                    if (config4_pos[i])

                      {
                        allowed = 1;
                        pos1 = i;
                        break;
                      }
                  }
                if (allowed)

                  {

                    //define the group_data
                    tempgpID.groupID[0][MCS_SIZE] =
                      eff_grouping_data.groupID[config_4MCS[pos1][0]][0];
                    tempgpID.groupID[0][MCS_IN_GROUP] = 4;
                    tempgpID.groupID[0][MEMBERS_START_ID + 0] =
                      config_4MCS[pos1][0];
                    tempgpID.groupID[0][MEMBERS_START_ID + 1] =
                      config_4MCS[pos1][2];
                    tempgpID.groupID[0][MEMBERS_START_ID + 2] =
                      config_4MCS[pos1][1];
                    tempgpID.groupID[0][MEMBERS_START_ID + 3] =
                      config_4MCS[pos1][3];
                    tempgpID.groupID[0][LARGEST_MBA_SIZE] =
                      eff_grouping_data.groupID[config_4MCS[pos1][0]][15];
                    gp++;
                    for (int i = 0; i < 4; i++)

                      {
                        eff_grouping_data.groupID[config_4MCS[pos1][i]][0] =
                          0;
                        grouped[config_4MCS[config4_pos[0]][i]] = 1;
                      }
                  }
              }
          }
// setting up 2 MCS/group
        if (!done && (groups_allowed & MCS_GROUP_2))

          {
            for (pos = 0; pos < gp_pos;)

              {
                if (eff_grouping_data.groupID[pos][MCS_SIZE] ==
                    eff_grouping_data.groupID[pos + 1][MCS_SIZE]
                    && eff_grouping_data.groupID[pos][MCS_SIZE] != 0)

                  {

                    //group
                    tempgpID.groupID[gp][MCS_SIZE] =
                      eff_grouping_data.groupID[pos][MCS_SIZE];
                    tempgpID.groupID[gp][MCS_IN_GROUP] = 2;
                    tempgpID.groupID[gp][MEMBERS_START_ID + 0] = pos;
                    tempgpID.groupID[gp][MEMBERS_START_ID + 1] = pos + 1;
                    tempgpID.groupID[gp][LARGEST_MBA_SIZE] =
                      eff_grouping_data.groupID[pos][LARGEST_MBA_SIZE];
                    grouped[pos] = 1;
                    grouped[pos + 1] = 1;
                    eff_grouping_data.groupID[pos][MCS_SIZE] = 0;
                    eff_grouping_data.groupID[pos + 1][MCS_SIZE] = 0;
                    gp++;
                    pos += 2;
                  }

                else
                  {
                    pos++;
                  }
              }
          }
// setting up 1  MCS/group
        if (!done && (groups_allowed & MCS_GROUP_1 ) && !check_board)

          {
            for (pos = 0; pos < gp_pos; pos++)

              {
                if (eff_grouping_data.groupID[pos][MCS_SIZE] != 0)

                  {

                    //group
                    tempgpID.groupID[gp][MCS_SIZE] =
                      eff_grouping_data.groupID[pos][MCS_SIZE];
                    tempgpID.groupID[gp][MCS_IN_GROUP] = 1;
                    tempgpID.groupID[gp][MEMBERS_START_ID + 0] = pos;
                    tempgpID.groupID[gp][LARGEST_MBA_SIZE] =
                      eff_grouping_data.groupID[pos][LARGEST_MBA_SIZE];
                    grouped[pos] = 1;
                    eff_grouping_data.groupID[pos][MCS_SIZE] = 0;
                    gp++;
                  }
              }
          }
//-------------------------------------------------------------
// Identifying ungrouped MCS and setting DIMM unplug call out
//-------------------------------------------------------------
        if (!done)

          {
            uint8_t ungroup = 0;
            ReturnCode ungroup_rc;
            for (uint8_t i = 0; i < 8; i++)

              {
                if (grouped[i] != 1
                    && eff_grouping_data.groupID[i][MCS_SIZE] != 0)

                  {
                    FAPI_ERR ("UNABLE TO GROUP MCS%d size is %d", i,
                              eff_grouping_data.groupID[i][MCS_SIZE]);
                    ungroup++;
                    if (ungroup == 1)
                      {         // First time, call out the Main error
                        FAPI_SET_HWP_ERROR (ungroup_rc,
                                            RC_MSS_UNABLE_TO_GROUP_SUMMARY);
                      }
                    for (std::vector < fapi::Target >::iterator iter =
                         l_mcs_chiplets.begin ();
                         iter != l_mcs_chiplets.end () && rc.ok (); iter++)

                      {
                        rc =
                          FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, &(*iter),
                                         mcs_pos);
                        if (!rc.ok ())

                          {
                            FAPI_ERR ("Error reading ATTR_CHIP_UNIT_POS");
                          }
                        if (mcs_pos == i)

                          {
                            FAPI_INF (" Trying to deconfigure MCS num %d", i);
                            const fapi::Target & TARGET_MCS = *iter;
                            FAPI_ADD_INFO_TO_HWP_ERROR (rc,
                                                        RC_MSS_UNABLE_TO_GROUP_MCS);
                            fapi::ReturnCode l_rc2;
                            FAPI_SET_HWP_ERROR(l_rc2,RC_MSS_UNABLE_TO_GROUP_MCS);
                            fapiLogError(l_rc2);
                            break;      //break for loop
                          }
                      }
                  }
              }
            if (ungroup)

              {
                return ungroup_rc;
              }
// defining the group array for temp storage
            for (uint8_t i = 0; i < gp; i++)
              for (uint8_t j = 0; j < 16; j++)
                eff_grouping_data.groupID[i][j] = tempgpID.groupID[i][j];
            for (uint8_t i = gp; i < 8; i++)
              for (uint8_t j = 0; j < 16; j++)
                eff_grouping_data.groupID[i][j] = 0;
          }
        flag = 0;
//--------------------------------------------------------------------------
//    Printing out MCS_ID position for each group
//--------------------------------------------------------------------------
        for (uint8_t i = 0; i < 16; i++)
          if (grouped[i])
            flag = 1;
        gp_pos = 0;
        if (done || flag)

          {
            for (uint8_t i = 0; i < 16; i++)

              {
                if (eff_grouping_data.groupID[i][MCS_SIZE] != 0)

                  {
                    gp_pos++;
                    FAPI_INF
                      (" group no= %d , num of MCS = %d , size of MCS = %d \n ",
                       i, eff_grouping_data.groupID[i][MCS_IN_GROUP],
                       eff_grouping_data.groupID[i][MCS_SIZE]);
                    for (uint8_t k = 0; k < eff_grouping_data.groupID[i][1];
                         k++)

                      {
                        FAPI_INF ("MCSID%d = %d \n ", k,
                                  eff_grouping_data.
                                  groupID[i][MEMBERS_START_ID + k]);
                      }
                  }
              }
          }
        uint32_t temp[16];
        uint8_t i = 0;
        uint8_t j = 0;
        count = 0;
        uint64_t total_size_non_mirr = 0;
//----------------------------------------------------------------------------------
//      Calculating Total group size memory
//----------------------------------------------------------------------------------
        for (pos = 0; pos <= gp_pos; pos++)

          {
            eff_grouping_data.groupID[pos][GROUP_SIZE] =
              eff_grouping_data.groupID[pos][MCS_SIZE] *
              eff_grouping_data.groupID[pos][MCS_IN_GROUP];
            count =
              mss_eff_grouping_recursion (eff_grouping_data.
                                          groupID[pos][GROUP_SIZE]);
/// Calculating alternative memory
            if (count > 1)

              {
                FAPI_INF
                  ("MCS pos %d needs alternate bars defintation group Size %d\n",
                   pos, eff_grouping_data.groupID[pos][GROUP_SIZE]);
                eff_grouping_data.groupID[pos][GROUP_SIZE] =
                  eff_grouping_data.groupID[pos][LARGEST_MBA_SIZE] * 2 *
                  eff_grouping_data.groupID[pos][MCS_IN_GROUP];
                eff_grouping_data.groupID[pos][ALT_SIZE] =
                  eff_grouping_data.groupID[pos][MCS_IN_GROUP] *
                  (eff_grouping_data.groupID[pos][MCS_SIZE] -
                   eff_grouping_data.groupID[pos][LARGEST_MBA_SIZE]);
                eff_grouping_data.groupID[pos][ALT_VALID] = 1;
              }
            total_size_non_mirr += eff_grouping_data.groupID[pos][GROUP_SIZE];
          }
        for (i = 0; i < gp_pos; i++)

          {
            for (j = 0; j < 12; j++)

              {
                FAPI_INF (" groupID[%d][%d] = %d", i, j,
                          eff_grouping_data.groupID[i][j]);
              }
            FAPI_INF ("\n");
          }
//----------------------------------------------------------------------------------
// Reorder groups based on total memory size as descending High to low memory size order
//----------------------------------------------------------------------------------
        for (pos = 0; pos <= gp_pos; pos++)

          {
            for (i = pos; i < gp_pos; i++)

              {
                if (eff_grouping_data.groupID[i][GROUP_SIZE] >
                    eff_grouping_data.groupID[pos][GROUP_SIZE])

                  {
                    for (j = 0; j < 16; j++)
                      temp[j] = eff_grouping_data.groupID[pos][j];
                    for (j = 0; j < 16; j++)
                      eff_grouping_data.groupID[pos][j] =
                        eff_grouping_data.groupID[i][j];
                    for (j = 0; j < 16; j++)
                      eff_grouping_data.groupID[i][j] = temp[j];
                  }

                else
                  {
                  }
              }
          }

//-------------------------------------------------------------------------------------
//     Calculating Mirroring group Size and alternate  group size for Mirroing
//------------------------------------------------------------------------------------
        if (!M_valid)

          {

            // calcutate mirrored group size and non mirrored group size
            for (pos = 0; pos < gp_pos; pos++)

              {
                if (eff_grouping_data.groupID[pos][MCS_SIZE] != 0
                    && eff_grouping_data.groupID[pos][MCS_IN_GROUP] > 1)

                  {
                    eff_grouping_data.groupID[pos + 8][GROUP_SIZE] = eff_grouping_data.groupID[pos][GROUP_SIZE] / 2;    // group size when mirrored
                    if (eff_grouping_data.groupID[pos][ALT_VALID])

                      {
                        FAPI_INF
                          ("Mirrored group pos %d needs alternate bars defintation group Size %d\n",
                           pos, eff_grouping_data.groupID[pos][GROUP_SIZE]);

                        //mirrored group
                        eff_grouping_data.groupID[pos + 8][GROUP_SIZE] = eff_grouping_data.groupID[pos][GROUP_SIZE] / 2;        //group size with alternate bars
                        eff_grouping_data.groupID[pos + 8][ALT_SIZE] =
                          eff_grouping_data.groupID[pos][ALT_SIZE] / 2;
                        eff_grouping_data.groupID[pos + 8][ALT_VALID] = 1;
                      }
                  }
              }

            if (selective_mode == SELECTIVE_MODE)

              {
                mss_base_address = 0;
                rc =
                  FAPI_ATTR_GET (ATTR_PROC_MEM_BASE, &i_target,
                                 mss_base_address);
                mss_base_address = mss_base_address >> 30;
                if (!rc.ok ())
                  return rc;
                rc =
                  FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASE, &i_target,
                                 mirror_base);
                mirror_base = mirror_base >> 30;
                if (!rc.ok ())
                  return rc;
                rc =
                  FAPI_ATTR_GET (ATTR_PROC_HTM_BAR_SIZE, &i_target,
                                 htm_bar_size);
                if (!rc.ok ())
                  return rc;
                rc =
                  FAPI_ATTR_GET (ATTR_PROC_OCC_SANDBOX_SIZE, &i_target,
                                 occ_sandbox_size);
                if (!rc.ok ())
                  return rc;
              }

            else
              {
                rc =
                  FAPI_ATTR_GET (ATTR_PROC_MEM_BASE, &i_target,
                                 mss_base_address);
                mss_base_address = mss_base_address >> 30;
                if (!rc.ok ())
                  return rc;
                rc =
                  FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASE, &i_target,
                                 mirror_base);
                mirror_base = mirror_base >> 30;
                if (!rc.ok ())
                  return rc;
                rc =
                  FAPI_ATTR_GET (ATTR_PROC_HTM_BAR_SIZE, &i_target,
                                 htm_bar_size);
                if (!rc.ok ())
                  return rc;
                rc =
                  FAPI_ATTR_GET (ATTR_PROC_OCC_SANDBOX_SIZE, &i_target,
                                 occ_sandbox_size);
                if (!rc.ok ())
                  return rc;
              }
// Checking the memory base address overlapping with mirror memory bas address
// or not

            if (mss_base_address > (mirror_base + total_size_non_mirr / 2)
                || mirror_base > (mss_base_address + total_size_non_mirr))

              {
                for (pos = 0; pos < gp_pos; pos++)

                  {
                    if (pos == 0)

                      {
                        eff_grouping_data.groupID[pos][BASE_ADDR] =
                          mss_base_address;
                        if (eff_grouping_data.groupID[pos][ALT_VALID])

                          {
                            eff_grouping_data.groupID[pos][ALT_BASE_ADDR] =
                              eff_grouping_data.groupID[pos][BASE_ADDR] +
                              eff_grouping_data.groupID[pos][GROUP_SIZE] / 2;
                          }
                      }

                    else

                      {
                        eff_grouping_data.groupID[pos][BASE_ADDR] =
                          eff_grouping_data.groupID[pos - 1][BASE_ADDR] +
                          eff_grouping_data.groupID[pos - 1][GROUP_SIZE];
                        if (eff_grouping_data.groupID[pos][ALT_VALID])

                          {
                            eff_grouping_data.groupID[pos][ALT_BASE_ADDR] =
                              eff_grouping_data.groupID[pos][BASE_ADDR] +
                              eff_grouping_data.groupID[pos][GROUP_SIZE] / 2;
                          }
                      }
                    if (eff_grouping_data.groupID[pos][MCS_IN_GROUP] > 1)

                      {
                        eff_grouping_data.groupID[pos + 8][BASE_ADDR] =
                          mirror_base;
                        mirror_base =
                          mirror_base + eff_grouping_data.groupID[pos +
                                                                  8]
                                                                 [GROUP_SIZE];
                        if (eff_grouping_data.groupID[pos][ALT_VALID])

                          {
                            eff_grouping_data.groupID[pos + 8][ALT_BASE_ADDR]  =
                               eff_grouping_data.groupID[pos + 8][BASE_ADDR]   +
                               eff_grouping_data.groupID[pos + 8][GROUP_SIZE] / 2;     //mirrored base address with alternate bars
                            eff_grouping_data.groupID[pos + 8][ALT_VALID] = 1;
                          }
                      }
                  }
              }

            else

              {
                FAPI_ERR
                  ("Mirror Base address overlaps with memory base address. ");
                const fapi::Target & PROC_CHIP = i_target;
                FAPI_SET_HWP_ERROR (rc,
                                    RC_MSS_BASE_ADDRESS_OVERLAPS_MIRROR_ADDRESS);
                return rc;
              }
          }

        else
          {
            rc =
              FAPI_ATTR_GET (ATTR_PROC_MEM_BASE, &i_target, mss_base_address);
            mss_base_address = mss_base_address >> 30;
            if (!rc.ok ())
              return rc;
            rc =
              FAPI_ATTR_GET (ATTR_PROC_HTM_BAR_SIZE, &i_target, htm_bar_size);
            if (!rc.ok ())
              return rc;
            rc =
              FAPI_ATTR_GET (ATTR_PROC_OCC_SANDBOX_SIZE, &i_target,
                             occ_sandbox_size);
            if (!rc.ok ())
              return rc;
//------------------------------------------------------------------
// Assigning mirroring and non-mirroring base address for each group
//-------------------------------------------------------------------
            for (pos = 0; pos < gp_pos; pos++)

              {
                if (pos == 0)

                  {
                    eff_grouping_data.groupID[pos][BASE_ADDR] =
                      mss_base_address;
                    if (eff_grouping_data.groupID[pos][ALT_VALID])

                      {
                        eff_grouping_data.groupID[pos][ALT_BASE_ADDR] =
                          eff_grouping_data.groupID[pos][BASE_ADDR] +
                          eff_grouping_data.groupID[pos][GROUP_SIZE] / 2;
                      }
                  }

                else

                  {
                    eff_grouping_data.groupID[pos][BASE_ADDR] =
                      eff_grouping_data.groupID[pos - 1][BASE_ADDR] +
                      eff_grouping_data.groupID[pos - 1][GROUP_SIZE];
                    if (eff_grouping_data.groupID[pos][ALT_VALID])

                      {
                        eff_grouping_data.groupID[pos][ALT_BASE_ADDR] =
                          eff_grouping_data.groupID[pos][BASE_ADDR] +
                          eff_grouping_data.groupID[pos][GROUP_SIZE] / 2;
                      }
                  }
              }
          }
// -------------------------------------------------------------
// Setting up No of MCS per group attributes
// -------------------------------------------------------------
        ecmdDataBufferBase MC_IN_GP (8);
        uint8_t mcs_in_group[8];
        for (uint8_t i = 0; i < 8; i++)
          mcs_in_group[i] = 0;
        for (uint8_t i = 0; i < gp_pos; i++)

          {
            count = 0;
            MC_IN_GP.flushTo0 ();
            if (eff_grouping_data.groupID[i][MCS_SIZE] != 0)

              {
                count = eff_grouping_data.groupID[i][MCS_IN_GROUP];
                for (uint8_t j = 0; j < count; j++)
                  MC_IN_GP.setBit (eff_grouping_data.
                                   groupID[i][MEMBERS_START_ID + j]);
                mcs_in_group[i] = MC_IN_GP.getByte (0);
              }
          }
        FAPI_DBG ("  ATTR_MSS_MEM_MC_IN_GROUP[0]: 0x%x", mcs_in_group[0]);
        FAPI_DBG ("  ATTR_MSS_MEM_MC_IN_GROUP[1]: 0x%x", mcs_in_group[1]);
        FAPI_DBG ("  ATTR_MSS_MEM_MC_IN_GROUP[2]: 0x%x", mcs_in_group[2]);
        FAPI_DBG ("  ATTR_MSS_MEM_MC_IN_GROUP[3]: 0x%x", mcs_in_group[3]);
        FAPI_DBG ("  ATTR_MSS_MEM_MC_IN_GROUP[4]: 0x%x", mcs_in_group[4]);
        FAPI_DBG ("  ATTR_MSS_MEM_MC_IN_GROUP[5]: 0x%x", mcs_in_group[5]);
        FAPI_DBG ("  ATTR_MSS_MEM_MC_IN_GROUP[6]: 0x%x", mcs_in_group[6]);
        FAPI_DBG ("  ATTR_MSS_MEM_MC_IN_GROUP[7]: 0x%x", mcs_in_group[7]);
        rc =
          FAPI_ATTR_SET (ATTR_MSS_MEM_MC_IN_GROUP, &i_target, mcs_in_group);
        if (!rc.ok ())

          {
            FAPI_ERR ("Error writing ATTR_MSS_MEM_MC_IN_GROUP");
            break;
          }

//-----------------------------------------------------------------------
//   Assigning base address and base size for mirroring/non-mirroring
//    attributes. There are two sets of attributes group
//    1) Cronus level attributes which used by msinfo  query
//    2) FW attributes used by System hostboot IPLing
//------------------------------------------------------------------------

        uint64_t mem_bases[8];
        uint64_t mem_bases_ack[8];
        uint64_t l_memory_sizes[8];
        uint64_t l_memory_sizes_ack[8];
        uint64_t mirror_bases[4];
        uint64_t mirror_bases_ack[4];
        uint64_t l_mirror_sizes[4];
        uint64_t l_mirror_sizes_ack[4];
        for (uint8_t i = 0; i < 8; i++)

          {
            if (eff_grouping_data.groupID[i][MCS_SIZE] > 0)

              {
                FAPI_INF (" Group   %d MCS Size  %4dGB", i,
                          eff_grouping_data.groupID[i][MCS_SIZE]);
                FAPI_INF (" No of MCS %4d   ",
                          eff_grouping_data.groupID[i][MCS_IN_GROUP]);
                FAPI_INF (" Group Size %4dGB",
                          eff_grouping_data.groupID[i][GROUP_SIZE]);
                FAPI_INF (" Base Add.  %4dGB ",
                          eff_grouping_data.groupID[i][BASE_ADDR]);
                if (!M_valid)

                  {
                    FAPI_INF (" Mirrored Group SIze %4dGB",
                              eff_grouping_data.groupID[i + 8][GROUP_SIZE]);
                    FAPI_INF (" Mirror Base Add %4dGB",
                              eff_grouping_data.groupID[i + 8][BASE_ADDR]);
                  }
                for (uint8_t j = 4;
                     j < 4 + eff_grouping_data.groupID[i][MCS_IN_GROUP]; j++)

                  {
                    FAPI_INF (" MCSID%d- Pos %4d", (j - 4),
                              eff_grouping_data.groupID[i][j]);
                  }
                FAPI_INF (" Alter-bar  %4d",
                          eff_grouping_data.groupID[i][ALT_VALID]);
                FAPI_INF ("Alter-bar base add = %4dGB ",
                          eff_grouping_data.groupID[i][ALT_BASE_ADDR]);
                FAPI_INF ("Alter-bar size = %4dGB",
                          eff_grouping_data.groupID[i][ALT_SIZE]);
                if (!M_valid)

                  {
                    FAPI_INF ("Alter-bar Mirrored Base add = %4dGB ",
                              eff_grouping_data.groupID[i +
                                                        8][ALT_BASE_ADDR]);
                    FAPI_INF ("Alter-bar Mirrored size = %4dGB",
                              eff_grouping_data.groupID[i + 8][ALT_SIZE]);
                  }
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

// base addresses for distinct non-mirrored ranges
        mem_bases[0] = eff_grouping_data.groupID[0][BASE_ADDR];
        mem_bases[1] = eff_grouping_data.groupID[1][BASE_ADDR];
        mem_bases[2] = eff_grouping_data.groupID[2][BASE_ADDR];
        mem_bases[3] = eff_grouping_data.groupID[3][BASE_ADDR];
        mem_bases[4] = eff_grouping_data.groupID[4][BASE_ADDR];
        mem_bases[5] = eff_grouping_data.groupID[5][BASE_ADDR];
        mem_bases[6] = eff_grouping_data.groupID[6][BASE_ADDR];
        mem_bases[7] = eff_grouping_data.groupID[7][BASE_ADDR];
        mem_bases_ack[0] = eff_grouping_data.groupID[0][BASE_ADDR];
        mem_bases_ack[1] = eff_grouping_data.groupID[1][BASE_ADDR];
        mem_bases_ack[2] = eff_grouping_data.groupID[2][BASE_ADDR];
        mem_bases_ack[3] = eff_grouping_data.groupID[3][BASE_ADDR];
        mem_bases_ack[4] = eff_grouping_data.groupID[4][BASE_ADDR];
        mem_bases_ack[5] = eff_grouping_data.groupID[5][BASE_ADDR];
        mem_bases_ack[6] = eff_grouping_data.groupID[6][BASE_ADDR];
        mem_bases_ack[7] = eff_grouping_data.groupID[7][BASE_ADDR];

///  Base size modified for selective mode to do better packing memory
//   which  helps to do bare metal exerciser memory stressing

        if (selective_mode == SELECTIVE_MODE)

          {
            l_memory_sizes[0] = eff_grouping_data.groupID[0][GROUP_SIZE] / 2;
            l_memory_sizes[1] = eff_grouping_data.groupID[1][GROUP_SIZE] / 2;
            l_memory_sizes[2] = eff_grouping_data.groupID[2][GROUP_SIZE] / 2;
            l_memory_sizes[3] = eff_grouping_data.groupID[3][GROUP_SIZE] / 2;
            l_memory_sizes[4] = eff_grouping_data.groupID[4][GROUP_SIZE] / 2;
            l_memory_sizes[5] = eff_grouping_data.groupID[5][GROUP_SIZE] / 2;
            l_memory_sizes[6] = eff_grouping_data.groupID[6][GROUP_SIZE] / 2;
            l_memory_sizes[7] = eff_grouping_data.groupID[7][GROUP_SIZE] / 2;
          }

        else

          {

// sizes for distinct non-mirrored ranges
            l_memory_sizes[0] =
              eff_grouping_data.groupID[0][MCS_SIZE] *
              eff_grouping_data.groupID[0][MCS_IN_GROUP];
            l_memory_sizes[1] =
              eff_grouping_data.groupID[1][MCS_SIZE] *
              eff_grouping_data.groupID[1][MCS_IN_GROUP];
            l_memory_sizes[2] =
              eff_grouping_data.groupID[2][MCS_SIZE] *
              eff_grouping_data.groupID[2][MCS_IN_GROUP];
            l_memory_sizes[3] =
              eff_grouping_data.groupID[3][MCS_SIZE] *
              eff_grouping_data.groupID[3][MCS_IN_GROUP];
            l_memory_sizes[4] =
              eff_grouping_data.groupID[4][MCS_SIZE] *
              eff_grouping_data.groupID[4][MCS_IN_GROUP];
            l_memory_sizes[5] =
              eff_grouping_data.groupID[5][MCS_SIZE] *
              eff_grouping_data.groupID[5][MCS_IN_GROUP];
            l_memory_sizes[6] =
              eff_grouping_data.groupID[6][MCS_SIZE] *
              eff_grouping_data.groupID[6][MCS_IN_GROUP];
            l_memory_sizes[7] =
              eff_grouping_data.groupID[7][MCS_SIZE] *
              eff_grouping_data.groupID[7][MCS_IN_GROUP];
          }
        l_memory_sizes_ack[0] = eff_grouping_data.groupID[0][GROUP_SIZE];
        l_memory_sizes_ack[1] = eff_grouping_data.groupID[1][GROUP_SIZE];
        l_memory_sizes_ack[2] = eff_grouping_data.groupID[2][GROUP_SIZE];
        l_memory_sizes_ack[3] = eff_grouping_data.groupID[3][GROUP_SIZE];
        l_memory_sizes_ack[4] = eff_grouping_data.groupID[4][GROUP_SIZE];
        l_memory_sizes_ack[5] = eff_grouping_data.groupID[5][GROUP_SIZE];
        l_memory_sizes_ack[6] = eff_grouping_data.groupID[6][GROUP_SIZE];
        l_memory_sizes_ack[7] = eff_grouping_data.groupID[7][GROUP_SIZE];
        if (!M_valid)

          {

            // process mirrored ranges
            //
            if (selective_mode == SELECTIVE_MODE)

              {
                uint8_t groupcount = 0;
                for (i = 0; i < 8; i++)

                  {
                    if (eff_grouping_data.groupID[i][GROUP_SIZE] > 1)
                      {
                        groupcount++;
                      }
                  }
                if (groupcount < 7)

                  {
                    mem_bases[groupcount + 0] =
                      eff_grouping_data.groupID[8][BASE_ADDR] +
                      (eff_grouping_data.groupID[8][GROUP_SIZE] / 2);
                    mem_bases[groupcount + 1] =
                      eff_grouping_data.groupID[9][BASE_ADDR] +
                      (eff_grouping_data.groupID[9][GROUP_SIZE] / 2);
                    mem_bases[groupcount + 2] =
                      eff_grouping_data.groupID[10][BASE_ADDR] +
                      (eff_grouping_data.groupID[10][GROUP_SIZE] / 2);
                    mem_bases[groupcount + 3] =
                      eff_grouping_data.groupID[11][BASE_ADDR] +
                      (eff_grouping_data.groupID[11][GROUP_SIZE] / 2);
                  }
                // Selective mode - Mirroring will be moved in non-mirroring space Virutally
                mirror_bases[0] = 0;
                mirror_bases[1] = 0;
                mirror_bases[2] = 0;
                mirror_bases[3] = 0;
              }

            else

              {

                // base addresses for distinct mirrored ranges
                mirror_bases[0] = eff_grouping_data.groupID[8][BASE_ADDR];
                mirror_bases[1] = eff_grouping_data.groupID[9][BASE_ADDR];
                mirror_bases[2] = eff_grouping_data.groupID[10][BASE_ADDR];
                mirror_bases[3] = eff_grouping_data.groupID[11][BASE_ADDR];
              }
            mirror_bases_ack[0] = eff_grouping_data.groupID[8][BASE_ADDR];
            mirror_bases_ack[1] = eff_grouping_data.groupID[9][BASE_ADDR];
            mirror_bases_ack[2] = eff_grouping_data.groupID[10][BASE_ADDR];
            mirror_bases_ack[3] = eff_grouping_data.groupID[11][BASE_ADDR];
            if (selective_mode == SELECTIVE_MODE)

              {
                uint8_t groupcount = 0;
                for (i = 0; i < 8; i++)

                  {
                    if (eff_grouping_data.groupID[i][MCS_IN_GROUP] > 1)
                      {
                        groupcount++;
                      }
                  }
                if (groupcount < 7)

                  {
                    l_memory_sizes[groupcount + 0] =
                      eff_grouping_data.groupID[8][GROUP_SIZE] / 2;
                    l_memory_sizes[groupcount + 1] =
                      eff_grouping_data.groupID[9][GROUP_SIZE] / 2;
                    l_memory_sizes[groupcount + 2] =
                      eff_grouping_data.groupID[10][GROUP_SIZE] / 2;
                    l_memory_sizes[groupcount + 3] =
                      eff_grouping_data.groupID[11][GROUP_SIZE] / 2;
                  }
                l_mirror_sizes[0] = 0;
                l_mirror_sizes[1] = 0;
                l_mirror_sizes[2] = 0;
                l_mirror_sizes[3] = 0;
              }

            else

              {

                // sizes for distinct mirrored ranges
                for (i = 0; i < 4; i++)

                  {
                    if (eff_grouping_data.groupID[i][MCS_IN_GROUP] > 1)
                      l_mirror_sizes[i] =
                        (eff_grouping_data.groupID[i][MCS_SIZE] *
                         eff_grouping_data.groupID[0][MCS_IN_GROUP]) / 2;

                    else

                      {
                        l_mirror_sizes[i] = 0;
                      }
                  }
              }
            l_mirror_sizes_ack[0] = eff_grouping_data.groupID[8][GROUP_SIZE];
            l_mirror_sizes_ack[1] = eff_grouping_data.groupID[9][GROUP_SIZE];
            l_mirror_sizes_ack[2] = eff_grouping_data.groupID[10][GROUP_SIZE];
            l_mirror_sizes_ack[3] = eff_grouping_data.groupID[11][GROUP_SIZE];
          }
        mem_bases[0] = mem_bases[0] << 30;
        mem_bases[1] = mem_bases[1] << 30;
        mem_bases[2] = mem_bases[2] << 30;
        mem_bases[3] = mem_bases[3] << 30;
        mem_bases[4] = mem_bases[4] << 30;
        mem_bases[5] = mem_bases[5] << 30;
        mem_bases[6] = mem_bases[6] << 30;
        mem_bases[7] = mem_bases[7] << 30;
        mem_bases_ack[0] = mem_bases_ack[0] << 30;
        mem_bases_ack[1] = mem_bases_ack[1] << 30;
        mem_bases_ack[2] = mem_bases_ack[2] << 30;
        mem_bases_ack[3] = mem_bases_ack[3] << 30;
        mem_bases_ack[4] = mem_bases_ack[4] << 30;
        mem_bases_ack[5] = mem_bases_ack[5] << 30;
        mem_bases_ack[6] = mem_bases_ack[6] << 30;
        mem_bases_ack[7] = mem_bases_ack[7] << 30;
        l_memory_sizes[0] = l_memory_sizes[0] << 30;
        l_memory_sizes[1] = l_memory_sizes[1] << 30;
        l_memory_sizes[2] = l_memory_sizes[2] << 30;
        l_memory_sizes[3] = l_memory_sizes[3] << 30;
        l_memory_sizes[4] = l_memory_sizes[4] << 30;
        l_memory_sizes[5] = l_memory_sizes[5] << 30;
        l_memory_sizes[6] = l_memory_sizes[6] << 30;
        l_memory_sizes[7] = l_memory_sizes[7] << 30;
        l_memory_sizes_ack[0] = l_memory_sizes_ack[0] << 30;
        l_memory_sizes_ack[1] = l_memory_sizes_ack[1] << 30;
        l_memory_sizes_ack[2] = l_memory_sizes_ack[2] << 30;
        l_memory_sizes_ack[3] = l_memory_sizes_ack[3] << 30;
        l_memory_sizes_ack[4] = l_memory_sizes_ack[4] << 30;
        l_memory_sizes_ack[5] = l_memory_sizes_ack[5] << 30;
        l_memory_sizes_ack[6] = l_memory_sizes_ack[6] << 30;
        l_memory_sizes_ack[7] = l_memory_sizes_ack[7] << 30;
        if (!M_valid)

          {
            mirror_bases[0] = mirror_bases[0] << 30;
            mirror_bases[1] = mirror_bases[1] << 30;
            mirror_bases[2] = mirror_bases[2] << 30;
            mirror_bases[3] = mirror_bases[3] << 30;
            mirror_bases_ack[0] = mirror_bases_ack[0] << 30;
            mirror_bases_ack[1] = mirror_bases_ack[1] << 30;
            mirror_bases_ack[2] = mirror_bases_ack[2] << 30;
            mirror_bases_ack[3] = mirror_bases_ack[3] << 30;
            l_mirror_sizes[0] = l_mirror_sizes[0] << 30;
            l_mirror_sizes[1] = l_mirror_sizes[1] << 30;
            l_mirror_sizes[2] = l_mirror_sizes[2] << 30;
            l_mirror_sizes[3] = l_mirror_sizes[3] << 30;
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES[0]: %016llx",
                      l_mirror_sizes[0]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES[1]: %016llx",
                      l_mirror_sizes[1]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES[2]: %016llx",
                      l_mirror_sizes[2]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES[3]: %016llx",
                      l_mirror_sizes[3]);
            l_mirror_sizes_ack[0] = l_mirror_sizes_ack[0] << 30;
            l_mirror_sizes_ack[1] = l_mirror_sizes_ack[1] << 30;
            l_mirror_sizes_ack[2] = l_mirror_sizes_ack[2] << 30;
            l_mirror_sizes_ack[3] = l_mirror_sizes_ack[3] << 30;
          }
        ReturnCode ungroup_rc;
        if (selective_mode == SELECTIVE_MODE)

          {
            if (htm_bar_size != 0 || occ_sandbox_size != 0)

              {
                FAPI_ERR
                  ("Selective mode does not support the HTM and OCC SANDBOX BARS");

                //    FAPI_SET_HWP_ERROR(ungroup_rc,RC_OPT_MEMMAP_ALLOC_ERR);
                break;
              }
          }
//------------------------------------------------------------------
//  Defining HTM and OCC base address based on HTM/OCC bar size
//
//------------------------------------------------------------------
        else if (selective_mode == NORMAL_MODE)

          {
            uint64_t total_size = 0;
            uint8_t memhole = 0;
            for (i = 0; i < 8; i++)

              {
                total_size += l_memory_sizes[i];
                if (eff_grouping_data.groupID[i][ALT_VALID])
                  {
                    memhole++;
                  }
              }
            if ((total_size >= (htm_bar_size + occ_sandbox_size))
                && ((htm_bar_size + occ_sandbox_size) > 0))

              {
                uint64_t other_bar_size = 0;
                other_bar_size = htm_bar_size + occ_sandbox_size;
                uint64_t non_mirroring_size = total_size - other_bar_size;
                uint64_t temp_size = 0;
                uint8_t done = 0;
                uint8_t j;
                i = 0;
                while (!done)

                  {
                    if ((temp_size <= non_mirroring_size)
                        && (non_mirroring_size <=
                            (temp_size += l_memory_sizes[i++])))

                      {
                        done = 1;
                      }
                  }
                j = i;

                if (memhole)

                  {
                    if (l_memory_sizes[j - 1] < other_bar_size)

                      {
                        FAPI_ERR (" MEMORY HTM/OCC BAR not possible ");
                        FAPI_DBG (" TOTAL MEMORY %016llx",
                                  l_memory_sizes[j - 1]);
                        break;
                      }

                    else
                      {
                        l_memory_sizes[i - 1] =
                          l_memory_sizes[i - 1] - (temp_size -
                                                   non_mirroring_size);
                      }
                  }

                else
                  {
                    l_memory_sizes[i - 1] =
                      l_memory_sizes[i - 1] - (temp_size -
                                               non_mirroring_size);
                    for (; i < 8; i++)
                      {
                        if (l_memory_sizes[i])
                          l_memory_sizes[i] = 0;
                      }
                  }
                if (htm_bar_size < occ_sandbox_size)

                  {
                    occ_sandbox_base =
                      mem_bases[j - 1] + l_memory_sizes[j - 1];
                    htm_bar_base = occ_sandbox_base + occ_sandbox_size;
                  }

                else

                  {
                    htm_bar_base = mem_bases[j - 1] + l_memory_sizes[j - 1];
                    occ_sandbox_base = htm_bar_base + htm_bar_size;
                  }
                FAPI_DBG (" TOTAL MEMORY %016llx", total_size);
                if (!M_valid)

                  {
                    FAPI_DBG ("  MIRRORING SIZE: %016llx & %d",
                              l_mirror_sizes[j - 1], j);
                    FAPI_DBG ("  Requitred MIRRORING SIZE: %016llx ",
                              non_mirroring_size);
                  }
                FAPI_DBG ("  HTM_BASE : %016llx", htm_bar_base);
                FAPI_DBG ("  OCC_BASE : %016llx", occ_sandbox_base);
              }

            else if ((total_size >= (htm_bar_size + occ_sandbox_size))
                     && ((htm_bar_size + occ_sandbox_size) == 0))
              {
              }

            else

              {
                FAPI_ERR
                  (" Required memory space for the HTM and OCC SANDBOX BARS is not available ");

                // FAPI_SET_HWP_ERROR((ungroup_rc,RC_OPT_MEMMAP_ALLOC_ERR);
                break;
              }
          }

        else if (selective_mode == FLIPPED_MODE)

          {
            uint64_t total_size = 0;
            uint8_t memhole = 0;
            uint8_t j = 0;
            for (i = 0; i < 4; i++)

              {
                total_size += l_mirror_sizes[i];
                if (eff_grouping_data.groupID[i][ALT_VALID])
                  {
                    memhole++;
                  }
              }

            //if (total_size >= (htm_bar_size+occ_sandbox_size))
            if ((total_size >= (htm_bar_size + occ_sandbox_size))
                && ((htm_bar_size + occ_sandbox_size) > 0))

              {
                uint64_t other_bar_size = 0;
                other_bar_size = htm_bar_size + occ_sandbox_size;
                uint64_t non_mirroring_size = total_size - other_bar_size;
                uint64_t temp_size = 0;
                uint8_t done = 0;
                i = 0;
                while (!done)

                  {
                    if ((temp_size <= non_mirroring_size)
                        && (non_mirroring_size <=
                            (temp_size += l_mirror_sizes[i++])))

                      {
                        done = 1;
                      }
                  }
                j = i;

                if (memhole)

                  {
                    if (l_mirror_sizes[j - 1] < other_bar_size)

                      {
                        FAPI_ERR (" MEMORY HTM/OCC BAR not possible ");
                        FAPI_DBG (" TOTAL MEMORY %016llx",
                                  l_memory_sizes[j - 1]);
                        break;
                      }

                    else
                      {
                        l_mirror_sizes[i - 1] =
                          l_mirror_sizes[i - 1] - (temp_size -
                                                   non_mirroring_size);
                      }
                  }

                else
                  {
                    l_mirror_sizes[i - 1] =
                      l_mirror_sizes[i - 1] - (temp_size -
                                               non_mirroring_size);
                    for (; i < 8; i++)
                      {
                        if (l_memory_sizes[i])
                          l_memory_sizes[i] = 0;
                      }
                  }
                if (htm_bar_size < occ_sandbox_size)

                  {
                    occ_sandbox_base =
                      mirror_bases[j - 1] + l_mirror_sizes[j - 1];
                    htm_bar_size = occ_sandbox_base + occ_sandbox_size;
                  }

                else

                  {
                    htm_bar_base =
                      mirror_bases[j - 1] + l_mirror_sizes[j - 1];
                    occ_sandbox_base = htm_bar_base + htm_bar_size;
                  }
                FAPI_DBG (" TOTAL MEMORY %016llx", total_size);
                FAPI_DBG ("  MIRRORING SIZE: %016llx & %d",
                          l_mirror_sizes[j - 1], j);
                FAPI_DBG ("  Requitred MIRRORING SIZE: %016llx ",
                          non_mirroring_size);
                FAPI_DBG ("  HTM_BASE : %016llx", htm_bar_base);
                FAPI_DBG ("  OCC_BASE : %016llx", occ_sandbox_base);
              }

            else if ((total_size >= (htm_bar_size + occ_sandbox_size))
                     && ((htm_bar_size + occ_sandbox_size) == 0))
              {
              }

//
//     Calling out No Required memory found for HTM/OCC bars
//
            else
              {
                FAPI_ERR
                  (" Required memory space for the HTM and OCC SANDBOX BARS is not available ");

                //  FAPI_SET_HWP_ERROR((ungroup_rc,RC_OPT_MEMMAP_ALLOC_ERR);
                break;
              }
          }

//--------------------------------------------------------------------------------
//  Setting up Calculated Attributes in the mss_eff_grouping procedure
//--------------------------------------------------------------------------------
        FAPI_DBG ("  ATTR_PROC_MEM_BASES[0]: %016llx", mem_bases[0]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES[1]: %016llx", mem_bases[1]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES[2]: %016llx", mem_bases[2]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES[3]: %016llx", mem_bases[3]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES[4]: %016llx", mem_bases[4]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES[5]: %016llx", mem_bases[5]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES[6]: %016llx", mem_bases[6]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES[7]: %016llx", mem_bases[7]);
        rc = FAPI_ATTR_SET (ATTR_PROC_MEM_BASES, &i_target, mem_bases);
        if (!rc.ok ())

          {
            FAPI_ERR ("Error writing ATTR_PROC_MEM_BASES");
            break;
          }
        FAPI_DBG ("  ATTR_PROC_MEM_BASES_ACK[0]: %016llx", mem_bases_ack[0]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES_ACK[1]: %016llx", mem_bases_ack[1]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES_ACK[2]: %016llx", mem_bases_ack[2]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES_ACK[3]: %016llx", mem_bases_ack[3]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES_ACK[4]: %016llx", mem_bases_ack[4]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES_ACK[5]: %016llx", mem_bases_ack[5]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES_ACK[6]: %016llx", mem_bases_ack[6]);
        FAPI_DBG ("  ATTR_PROC_MEM_BASES_ACK[7]: %016llx", mem_bases_ack[7]);
        rc =
          FAPI_ATTR_SET (ATTR_PROC_MEM_BASES_ACK, &i_target, mem_bases_ack);
        if (!rc.ok ())

          {
            FAPI_ERR ("Error writing ATTR_PROC_MEM_BASES_ACK");
            break;
          }
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES[0]: %016llx", l_memory_sizes[0]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES[1]: %016llx", l_memory_sizes[1]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES[2]: %016llx", l_memory_sizes[2]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES[3]: %016llx", l_memory_sizes[3]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES[4]: %016llx", l_memory_sizes[4]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES[5]: %016llx", l_memory_sizes[5]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES[6]: %016llx", l_memory_sizes[6]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES[7]: %016llx", l_memory_sizes[7]);
        rc = FAPI_ATTR_SET (ATTR_PROC_MEM_SIZES, &i_target, l_memory_sizes);
        if (!rc.ok ())

          {
            FAPI_ERR ("Error writing ATTR_PROC_MEM_SIZES");
            break;
          }
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES_ACK[0]: %016llx",
                  l_memory_sizes_ack[0]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES_ACK[1]: %016llx",
                  l_memory_sizes_ack[1]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES_ACK[2]: %016llx",
                  l_memory_sizes_ack[2]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES_ACK[3]: %016llx",
                  l_memory_sizes_ack[3]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES_ACK[4]: %016llx",
                  l_memory_sizes_ack[4]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES_ACK[5]: %016llx",
                  l_memory_sizes_ack[5]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES_ACK[6]: %016llx",
                  l_memory_sizes_ack[6]);
        FAPI_DBG ("  ATTR_PROC_MEM_SIZES_ACK[7]: %016llx",
                  l_memory_sizes_ack[7]);
        rc =
          FAPI_ATTR_SET (ATTR_PROC_MEM_SIZES_ACK, &i_target,
                         l_memory_sizes_ack);
        if (!rc.ok ())

          {
            FAPI_ERR ("Error writing ATTR_PROC_MEM_SIZES_ACK");
            break;
          }
        rc =
          FAPI_ATTR_SET (ATTR_MSS_MCS_GROUP_32, &i_target,
                         eff_grouping_data.groupID);
        if (!rc.ok ())

          {
            FAPI_ERR ("Error writing ATTR_MSS_MCS_GROUP");
            break;
          }
        if (!M_valid)

          {
            FAPI_DBG ("  ATTR_PROC_MIRROR_BASES[0]: %016llx",
                      mirror_bases[0]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_BASES[1]: %016llx",
                      mirror_bases[1]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_BASES[2]: %016llx",
                      mirror_bases[2]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_BASES[3]: %016llx",
                      mirror_bases[3]);
            rc =
              FAPI_ATTR_SET (ATTR_PROC_MIRROR_BASES, &i_target, mirror_bases);
            if (!rc.ok ())

              {
                FAPI_ERR ("Error writing ATTR_PROC_MIRROR_BASES");
                break;
              }
            FAPI_DBG ("  ATTR_PROC_MIRROR_BASES[0]: %016llx",
                      mirror_bases_ack[0]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_BASES[1]: %016llx",
                      mirror_bases_ack[1]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_BASES[2]: %016llx",
                      mirror_bases_ack[2]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_BASES[3]: %016llx",
                      mirror_bases_ack[3]);
            rc =
              FAPI_ATTR_SET (ATTR_PROC_MIRROR_BASES_ACK, &i_target,
                             mirror_bases_ack);
            if (!rc.ok ())

              {
                FAPI_ERR ("Error writing ATTR_PROC_MIRROR_BASES_ACK");
                break;
              }
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES[0]: %016llx",
                      l_mirror_sizes[0]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES[1]: %016llx",
                      l_mirror_sizes[1]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES[2]: %016llx",
                      l_mirror_sizes[2]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES[3]: %016llx",
                      l_mirror_sizes[3]);
            rc =
              FAPI_ATTR_SET (ATTR_PROC_MIRROR_SIZES, &i_target,
                             l_mirror_sizes);
            if (!rc.ok ())

              {
                FAPI_ERR ("Error writing ATTR_PROC_MIRROR_SIZES");
                break;
              }
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES_ACK[0]: %016llx",
                      l_mirror_sizes_ack[0]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES_ACK[1]: %016llx",
                      l_mirror_sizes_ack[1]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES_ACK[2]: %016llx",
                      l_mirror_sizes_ack[2]);
            FAPI_DBG ("  ATTR_PROC_MIRROR_SIZES_ACK[3]: %016llx",
                      l_mirror_sizes_ack[3]);
            rc =
              FAPI_ATTR_SET (ATTR_PROC_MIRROR_SIZES_ACK, &i_target,
                             l_mirror_sizes_ack);
            if (!rc.ok ())

              {
                FAPI_ERR ("Error writing ATTR_PROC_MIRROR_SIZES_ACK");
                break;
              }
          }
        rc =
          FAPI_ATTR_SET (ATTR_PROC_HTM_BAR_BASE_ADDR, &i_target,
                         htm_bar_base);
        if (!rc.ok ())

          {
            FAPI_ERR ("Error writing ATTR_PROC_HTM_BAR_BASE_ADDR");
            break;
          }
        rc =
          FAPI_ATTR_SET (ATTR_PROC_OCC_SANDBOX_BASE_ADDR, &i_target,
                         occ_sandbox_base);
        if (!rc.ok ())

          {
            FAPI_ERR ("Error writing  ATTR_PROC_OCC_SANDBOX_BASE_ADDR");
            break;
          }
      }
    while (0);
    return rc;
  }
//--------------------------------------------------------------------------
//     This function is used for identifying no of 1s in memory size
//--------------------------------------------------------------------------
  uint8_t mss_eff_grouping_recursion (uint32_t number)
  {
    uint32_t temp = number;
    uint8_t count = 0;
    uint8_t buffersize = 0;
    while (1)

      {
        if (temp % 2)

          {
            count++;
            buffersize++;
            temp = temp / 2;
            FAPI_INF (" %d buffer Size %d*Count %d\n", number, buffersize,
                      count);
          }

        else

          {
            temp = temp / 2;
            buffersize++;
          }
        if (temp == 0 || temp == 1)

          {
            if (temp)

              {
                count++;
              }
            buffersize++;
            FAPI_INF (" %d buffer Size %d*Count %d\n", number, buffersize,
                      count);
            break;
          }
      }
    return count;
  }

//#ifdef FAPIECMD
}                               //end extern C

//#endif
