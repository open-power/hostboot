/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_mb_interleave/mss_eff_mb_interleave.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
// $Id: mss_eff_mb_interleave.C,v 1.7 2014/02/26 21:47:44 thi Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_eff_mb_interleave.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2014
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!  Licensed material - Program property of IBM
// *!  Refer to copyright instructions form no. G120-2083
// *! Created on Wed Jan  8 2014 at 07:56:26
//------------------------------------------------------------------------------
// *! TITLE       : mss_eff_mb_interleave
// *! DESCRIPTION : Set up centaur internal interleaving (between mba's)
// *| Checks and Sets ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE
// *|                 ATTR_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT
// *|
// *! OWNER NAME  :  Bellows Mark D. (Mark D),319432 Email: bellows@us.ibm.com
// *! BACKUP NAME :                 Email: ______@us.ibm.com

// *! ADDITIONAL COMMENTS :
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.7   | thi      |26-FEB-14| Add explanation for 1.6 in this header
//   1.6   | thi      |26-FEB-14| Add rc checking for attribute get
//   1.5   | bellows  |21-FEB-14| Move interleave rule checkking to system level
//   1.4   | bellows  |19-FEB-14| More RAS updates
//   1.3   | bellows  |17-FEB-14| Additional RAS review updates
//   1.2   | bellows  |14-FEB-14| Revamped Plug checking, RAS Review pass #1 comments added
//   1.1   | bellows  |08-JAN-14| Created.

#include <mss_eff_mb_interleave.H>
#include <fapi.H>

extern "C" {

  enum DECONFIG_TYPES  { DECONFIG_PORT_1_SLOT_0_IS_EMPTY_PORT_0_SLOT_0_IS_NOT=0,
  DECONFIG_PORT_1_SLOT_0_IS_NOT_EQUAL_TO_PORT_0_SLOT_0_A=1,
  DECONFIG_PORT_1_SLOT_0_IS_NOT_EQUAL_TO_PORT_0_SLOT_0_B=2,
  DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_WAS_DECONFIGURED=3,
  DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_WAS_DECONFIGURED=4,
  DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_1_SLOT_1_IS_NOT_EQUAL=5,
  DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_1_IS_NOT_EQAUL=6,
  DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_IS_NOT_EQUAL=7,
  DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_IS_NOT_EQUAL=8,
  DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_1_SLOT_1_IS_NOT_VALID=9,
  DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_1_IS_NOT_VALID=10,
  DECONFIG_PORT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY=11,
  DECONFIG_PORT_0_SLOT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY=12,
  DECONFIG_SLOT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY=13,
  DECONFIG_INTERLEAVE_MODE_CONTROL_IS_REQUIRED=99 };


  const uint8_t MSS_MBA_ADDR_INTERLEAVE_BIT = 24; // From Eric Retter:
                                        // the prefetch and cleaner assume that bit 24 is the interleave bit.
                                        // We put other interleave options in for other settings that could be
                                        // tried in performance testing

  using namespace fapi;

  class mss_eff_mb_dimm {
  public:
    uint8_t module_type;
    uint8_t dram_gen;
    uint8_t device_density;
    uint8_t num_of_ranks;
    uint8_t device_width;
    uint8_t module_width;
    uint8_t thermal_sensor;
    uint8_t size;
    Target mydimm_target;
    bool  valid;
    uint8_t side;
    uint8_t port;
    uint8_t slot;

    mss_eff_mb_dimm();
    ReturnCode load(fapi::Target & i_dimms, uint32_t size);
    bool is_valid();
    ReturnCode deconfig(uint8_t i_case);
    bool operator!=(const mss_eff_mb_dimm &) const;
  };

//----------------------------------------------
// MSS EFF GROUPING FUNCTIONs............
//----------------------------------------------------

  ReturnCode mss_eff_mb_interleave(const fapi::Target & i_cen_target) {
    ReturnCode rc;

    mss_eff_mb_dimm l_dimm_array[2][2][2]; // side, port, dimm
    std::vector<fapi::Target> l_target_dimm_array[2];
    std::vector<fapi::Target>  l_mba_chiplets;
    uint8_t mba_i;
    uint8_t mba;
    uint8_t l_cur_mba_port;
    uint8_t l_cur_mba_dimm;
    uint8_t side,port,slot;
    uint8_t hadadeconfig[2];
    uint8_t l_mss_derived_mba_cacheline_interleave_mode;
    uint8_t l_mss_mba_addr_interleave_bit;
    uint8_t mrw_mba_cacheline_interleave_mode_control;
    uint32_t size[2];
    uint8_t eff_dimm_size[2][2];
    uint8_t l_attr_mrw_strict_mba_plug_rule_checking;
    uint8_t l_deconfig_0_0;


    do {
// first step, load up the dimms connected to this centaur
      for(side=0;side<2;side++) {
        for(port=0;port<2;port++) {
          for(slot=0;slot<2;slot++) {
            l_dimm_array[side][port][slot].side = side;
            l_dimm_array[side][port][slot].port = port;
            l_dimm_array[side][port][slot].slot = slot;
          }
        }
      }

      rc = fapiGetChildChiplets(i_cen_target, fapi::TARGET_TYPE_MBA_CHIPLET, l_mba_chiplets);
      if(rc) {
        FAPI_ERR("Error retrieving fapiGetChildChiplets");
        break;
      }

      rc = FAPI_ATTR_GET(ATTR_MRW_STRICT_MBA_PLUG_RULE_CHECKING, NULL, l_attr_mrw_strict_mba_plug_rule_checking);
      if(rc)
      {
        FAPI_ERR("Error retrieving ATTR_MRW_STRICT_MBA_PLUG_RULE_CHECKING");
        break;
      }

      if(l_attr_mrw_strict_mba_plug_rule_checking == ENUM_ATTR_MRW_STRICT_MBA_PLUG_RULE_CHECKING_TRUE) {
        for(mba_i=0; mba_i<l_mba_chiplets.size(); mba_i++) {

          rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mba_chiplets[mba_i], mba);
          if(rc)
          {
            FAPI_ERR("Error retrieving ATTR_CHIP_UNIT_POS");
            break;
          }

          rc = fapiGetAssociatedDimms(l_mba_chiplets[mba_i], l_target_dimm_array[mba]);
          if(rc)
          {
            FAPI_ERR("Error retrieving assodiated dimms");
            break;
          }

          for (uint8_t l_dimm_index = 0; l_dimm_index <
            l_target_dimm_array[mba].size(); l_dimm_index += 1)
          {
            rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &l_target_dimm_array[mba][l_dimm_index],
                               l_cur_mba_port);
            if(rc)
            {
              FAPI_ERR("Error retrieving ATTR_MBA_PORT");
              break;
            }
            rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &l_target_dimm_array[mba][l_dimm_index
                                                                        ], l_cur_mba_dimm);
            if(rc)
            {
              FAPI_ERR("Error retrieving ATTR_MBA_DIMM");
              break;
            }

            rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &l_mba_chiplets[mba_i], eff_dimm_size);
            if(rc)
            {
              FAPI_ERR("Error retrieving ATTR_EFF_DIMM_SIZE");
              break;
            }

            FAPI_INF("Loading up information about dimm for mba %d port %d dimm %d", mba, l_cur_mba_port, l_cur_mba_dimm);

            FAPI_INF("DIMM size is eff_dimm_size[%d][%d] = %d", l_cur_mba_port, l_cur_mba_dimm, eff_dimm_size[l_cur_mba_port][l_cur_mba_dimm]);

            rc = l_dimm_array[mba][l_cur_mba_port][l_cur_mba_dimm].load(l_target_dimm_array[mba][l_dimm_index], eff_dimm_size[l_cur_mba_port][l_cur_mba_dimm]);
            if(rc) break;
          } // Each DIMM off this MBA
          if(rc) break;
        } // Each MBA
        if(rc) break;

// - Logical DIMMs are considered to be identical if they have the following attributes in common: Module Type (RDIMM or LRDIMM), Architecture (DDR3 vs DDR4), Device Density, Number of Ranks, Device Width, Module Width, and Thermal Sensor. 

// Plug Rule 4.1 - Logical DIMMs have to be plugged in pairs on either Port A & B or on Port C & D. Paired DIMMs must be identical.

// Plug Rule 4.2 - If there is a Logical DIMM plugged in Slot 1 then an identical DIMM must be plugged in Slot0

// Plug rules 4.1 and 4.2 define valid configurations which are:
// - DIMM type X populated in slot0 only, slot1 is not populated
// - DIMM type X populated in slot0 and slot1
        for(side=0;side<2;side++) {
          hadadeconfig[side]=0;
        }

        for(side=0;side<2;side++) {
          hadadeconfig[side]=0;
          if(l_dimm_array[side][0][0].is_valid()) { // there is a dimm on port 0, slot 0, this is a must
            l_deconfig_0_0=0;

            // case 0, you don't have a pair of dimms on port 0 and port 1, kill port0,0
            if(! l_dimm_array[side][1][0].is_valid()) {
              FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 0 is empty Port 0 slot 0 is not",side);
              rc = l_dimm_array[side][0][0].deconfig(DECONFIG_PORT_1_SLOT_0_IS_EMPTY_PORT_0_SLOT_0_IS_NOT);
              fapiLogError(rc);
              hadadeconfig[side]=1;
              l_deconfig_0_0=1;
            }

            // case 1, you did not kill dimm 0,0, so now check that 0,0 == 1,0
            if( l_deconfig_0_0 == 0 &&
                ( l_dimm_array[side][0][0] != l_dimm_array[side][1][0])) {
              FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 0 is not equal to Port 0 slot 0",side);
              rc = l_dimm_array[side][0][0].deconfig(DECONFIG_PORT_1_SLOT_0_IS_NOT_EQUAL_TO_PORT_0_SLOT_0_A);
              fapiLogError(rc);
              rc = l_dimm_array[side][1][0].deconfig(DECONFIG_PORT_1_SLOT_0_IS_NOT_EQUAL_TO_PORT_0_SLOT_0_B);
              fapiLogError(rc);
              hadadeconfig[side]=1;
              l_deconfig_0_0=1;
            }

            // if dimm 0,0 is gone, then blow away any dimm 0,1 and 1,1
            if(l_deconfig_0_0 ) {
              if(l_dimm_array[side][0][1].is_valid()) {
                FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 0 on Side %d slot 1 deconfigured because Port 0 slot 0 was deconfigured",side);
                rc =l_dimm_array[side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_WAS_DECONFIGURED);
                fapiLogError(rc);
                hadadeconfig[side]=1;
              }
              if(l_dimm_array[side][1][1].is_valid()) {
                FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 1 deconfigured because Port 0 slot 0 was deconfigured",side);
                rc = l_dimm_array[side][1][1].deconfig(DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_WAS_DECONFIGURED);
                fapiLogError(rc);
                hadadeconfig[side]=1;
              }
            }
            else { // you have 0,0, so check if there is a 0,1 and 1,1 and they are equal
                   // and 0,0 must equal 0,1, otherwise, get rid of 0,1 and 1,1
              if(l_dimm_array[side][0][1].is_valid() && l_dimm_array[side][1][1].is_valid()) {
                if(l_dimm_array[side][0][1] != l_dimm_array[side][1][1]) {
                  FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 0 on Side %d slot 1 deconfigured because Port 1 slot 1 is not equal",side);
                  rc =l_dimm_array[side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_1_SLOT_1_IS_NOT_EQUAL);
                  fapiLogError(rc);
                  FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 1 deconfigured because Port 0 slot 1 is not eqaul",side);
                  rc =l_dimm_array[side][1][1].deconfig(DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_1_IS_NOT_EQAUL);
                  fapiLogError(rc);
                  hadadeconfig[side]=1;
                }
                else {
                  if(l_dimm_array[side][0][0] != l_dimm_array[side][0][1]) {
                    FAPI_ERR("Deconfig Rule 4.2 :Plug Rule 4.2 violated, Port 0 on Side %d slot 1 deconfigured because Port 0 slot 0 is not equal",side);
                    rc =l_dimm_array[side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_IS_NOT_EQUAL);
                    fapiLogError(rc);
                    FAPI_ERR("Deconfig Rule 4.2 :Plug Rule 4.1 violated, Port 1 on Side %d slot 1 deconfigured because Port 0 slot 0 is not equal",side);
                    rc =l_dimm_array[side][1][1].deconfig(DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_0_IS_NOT_EQUAL);
                    fapiLogError(rc);
                    hadadeconfig[side]=1;
                  }
                }
              }
              else {
                if(l_dimm_array[side][0][1].is_valid()) {
                  FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 0 on Side %d slot 1 deconfigured because Port 1 slot 1 is not valid",side);
                  rc =l_dimm_array[side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_DECONFIGURED_BECAUSE_PORT_1_SLOT_1_IS_NOT_VALID);
                  fapiLogError(rc);
                }
                if(l_dimm_array[side][1][1].is_valid()) {
                  FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d slot 1 deconfigured because Port 0 slot 1 is not valid",side);
                  rc = l_dimm_array[side][1][1].deconfig(DECONFIG_PORT_1_SLOT_1_DECONFIGURED_BECAUSE_PORT_0_SLOT_1_IS_NOT_VALID);
                  fapiLogError(rc);
                  hadadeconfig[side]=1;
                }

              }
            }                 
          }
          else { // if there is no slot 0,0, then everything else is invalid
            if(l_dimm_array[side][1][0].is_valid()) {
              FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.1 violated, Port 1 on Side %d has something but Port 0 slot 0 is empty",side);
              rc = l_dimm_array[side][1][0].deconfig(DECONFIG_PORT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY);
              fapiLogError(rc);
              hadadeconfig[side]=1;
            }
            if(l_dimm_array[side][0][1].is_valid()) { // there is a dimm slot 1, but slot 0 is empty
              FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.2 violated, Port 0 on Side %d slot 1 has something but Port 0 slot 0 is empty",side);
              rc = l_dimm_array[side][0][1].deconfig(DECONFIG_PORT_0_SLOT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY);
              fapiLogError(rc);
              hadadeconfig[side]=1;
            }
            if(l_dimm_array[side][1][1].is_valid()) { // there is a dimm slot 1, but slot 0 is empty
              FAPI_ERR("Deconfig Rule 4.1 :Plug Rule 4.2 violated, Port 0 on Side %d slot 1 has something but Port 0 slot 0 is empty",side);
              rc = l_dimm_array[side][1][1].deconfig(DECONFIG_SLOT_1_HAS_SOMETHING_BUT_PORT_0_SLOT_0_IS_EMPTY);
              fapiLogError(rc);
              hadadeconfig[side]=1;
            }
          }
          if(hadadeconfig[side]) {
            FAPI_INF("There was a Deconfig on side %d due to a plug rule 4.1 and/or 4.2", side);
          }
          else {
            FAPI_INF("No Deconfig on side %d so far", side);
          }
        }

// Deconfig Rule 4.1 - When Plug rules 4.1 or 4.2 are violated all Logical DIMMs behind the MBA in violation are deconfiged. This error will be redetected on the next IPL no Persistent guard required. This rule is enforced by mss_eff_cnfg HW procedure.
// 
// 
// Deconfig by Association Rule 4.1 - If a logical DIMM is deconfigured; all logical DIMMs on the same MBA must also be deconfigured by association.  Since MBAs with no configured DIMMs are also deconfigured this will lead to the MBA also being deconfigured. This error will be redetected on the next IPL no Persistent guard required. 
// 
// Deconfig by Association Rule 4.2 MBAs with no configured DIMMs are deconfigured this will lead to the MBA also being deconfigured. This error will be redetected on the next IPL no Persistent guard required. 

//         for(side=0;side<2;side++) {
//           if(hadadeconfig[side]) {
//             for(port=0;port<2;port++) {
//               for(slot=0;slot<2;slot++) {
//                 if(l_dimm_array[side][port][slot].is_valid()) {
//                   FAPI_ERR("Deconfig by Association Rule 4.1 has been called on Side %d",side);
//                   l_dimm_array[side][port][slot].deconfig(11);
//                 }
//               }
//             }
//             FAPI_ERR("Deconfig by Association Rule 4.2 has been called on Side %d",side);
//             const fapi::Target & MBA = l_mba_chiplets[side];
//             FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_MB_INTERLEAVE_PLUG_DECONFIG_MBA_BY_ASSOCIATION);
//           }
//         }
//       }

// Note - In an IS DIMM system that is running in interleave mode: due to the interactions between Plug rules 4.1, 4.2 and 3.3 the IS DIMM will need to be plugged in quads. This means an identical pair of a total size behind one half of a Centaur Pair and another identical pair of the same total size behind the other Centaur in the Pair. Note that the 2 pairs of DIMMs need not be identical to each other just have the same total size.
      } // end of strict checking

      for(side=0;side<2;side++) {
        size[side]=0;
      }

      for(side=0;side<2;side++) {
        for(port=0;port<2;port++) {
          for(slot=0;slot<2;slot++) {
            size[side]+=l_dimm_array[side][port][slot].size;
          }
        }
      }

      FAPI_INF("Sizes on each side %d %d", size[0], size[1]);

      rc=FAPI_ATTR_GET(ATTR_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL, NULL, mrw_mba_cacheline_interleave_mode_control);
      if(rc) return rc;

      switch(mrw_mba_cacheline_interleave_mode_control) {
          case ENUM_ATTR_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL_NEVER:
              l_mss_derived_mba_cacheline_interleave_mode=ENUM_ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_OFF;
              l_mss_mba_addr_interleave_bit=0;
              break;
          case ENUM_ATTR_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL_REQUIRED:
              if(size[0] != size[1]) {
                FAPI_ERR("ATTR_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL is REQUIRED, but size on side 0 does not match size on side 1 sizes %d %d", size[0], size[1]);
                l_mss_derived_mba_cacheline_interleave_mode=ENUM_ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_OFF;
                l_mss_mba_addr_interleave_bit=0;
                for(side=0;side<2;side++) {
                  for(port=0;port<2;port++) {
                    for(slot=0;slot<2;slot++) {
                      if(l_dimm_array[side][port][slot].is_valid()) {
                        FAPI_ERR("Deconfig INTERLEAVE_MODE_CONTROL is REQUIRED violated Port %d on Side %d slot %d", port, side, slot);
                        rc = l_dimm_array[side][port][slot].deconfig(DECONFIG_INTERLEAVE_MODE_CONTROL_IS_REQUIRED);
                        fapiLogError(rc);
                      }
                    }
                  }
                }
              }
              else {
                l_mss_derived_mba_cacheline_interleave_mode=ENUM_ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_ON;
                l_mss_mba_addr_interleave_bit=MSS_MBA_ADDR_INTERLEAVE_BIT; 
              }
              break;
          case ENUM_ATTR_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL_REQUESTED:
              if(size[0] != size[1]) {
                l_mss_derived_mba_cacheline_interleave_mode=ENUM_ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_OFF;
                l_mss_mba_addr_interleave_bit=0;
              }
              else {
                l_mss_derived_mba_cacheline_interleave_mode=ENUM_ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_ON;
                l_mss_mba_addr_interleave_bit=MSS_MBA_ADDR_INTERLEAVE_BIT;
              }
              break;
          default:
              FAPI_ERR("Internal Error: ATTR_MRW_MBA_CACHELINE_INTERLEAVE_MODE_CONTROL is not a known value");
              l_mss_derived_mba_cacheline_interleave_mode=ENUM_ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE_OFF;
              l_mss_mba_addr_interleave_bit=0;
              break;

      }

      rc=FAPI_ATTR_SET(ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE, &i_cen_target, l_mss_derived_mba_cacheline_interleave_mode);
      if (rc)
      {
         FAPI_ERR("mss_eff_mb_interleave: Error from FAPI_ATTR_SET(ATTR_MSS_DERIVED_MBA_CACHELINE_INTERLEAVE_MODE)");
         break;
      }
      
      rc=FAPI_ATTR_SET(ATTR_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT, &i_cen_target, l_mss_mba_addr_interleave_bit);
      if (rc)
      {
         FAPI_ERR("mss_eff_mb_interleave: Error from FAPI_ATTR_SET(ATTR_MSS_DERIVED_MBA_ADDR_INTERLEAVE_BIT)");
         break;
      }

    } while(0);

    return rc;
  }

  // default constructor
  mss_eff_mb_dimm::mss_eff_mb_dimm() {
    module_type=0;
    dram_gen=0;
    device_density=0;
    num_of_ranks=0;
    device_width=0;
    module_width=0;
    thermal_sensor=0;
    size=0;
    valid=0;
  }

  ReturnCode mss_eff_mb_dimm::load(fapi::Target & i_dimm, uint32_t i_size) {
    ReturnCode rc;
    do {
      rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_TYPE, &i_dimm, module_type);
      if(rc) break;

      rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_DEVICE_TYPE, &i_dimm, dram_gen);
      if(rc) break;

      rc = FAPI_ATTR_GET(ATTR_SPD_SDRAM_DENSITY, &i_dimm, device_density);
      if(rc) break;

      rc = FAPI_ATTR_GET(ATTR_SPD_NUM_RANKS, &i_dimm, num_of_ranks);
      if(rc) break;

      rc = FAPI_ATTR_GET(ATTR_SPD_DRAM_WIDTH, &i_dimm, device_width);
      if(rc) break;

      rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_MEMORY_BUS_WIDTH, &i_dimm, module_width);
      if(rc) break;

      rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_THERMAL_SENSOR, &i_dimm, thermal_sensor);
      if(rc) break;

      mydimm_target=i_dimm;

      size=i_size;

      if(i_size != 0) {
        valid=1;
      }
      else {
        valid = 0;
      }
    }
    while (0);

    return rc;
  }

  bool mss_eff_mb_dimm::is_valid() {
    return valid;
  }

  ReturnCode mss_eff_mb_dimm::deconfig(uint8_t i_case){
    ReturnCode rc;
    FAPI_ERR("Deconfiguring a dimm due to a plugging rule violation at centuar/mba level case num %d (%d%d%d)", i_case, side, port, slot);
    const fapi::Target & DIMM =  mydimm_target;
    const uint8_t CASE = i_case;
    FAPI_SET_HWP_ERROR(rc, RC_MSS_EFF_MB_INTERLEAVE_PLUG_DECONFIG_DIMM);
    valid=0;
    size=0;
    return rc;
  }

  bool mss_eff_mb_dimm::operator!=(const mss_eff_mb_dimm &a) const {
    if( module_type == a.module_type && 
        dram_gen == a.dram_gen &&
        device_density == a.device_density &&
        num_of_ranks == a.num_of_ranks &&
        device_width == a.device_width &&
        module_width == a.module_width &&
        thermal_sensor == a.thermal_sensor &&
        size == a.size ){
      return 0;
    }
    else {
      return 1;
    }

  }
}
