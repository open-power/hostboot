/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_attr_cleanup/mss_attr_cleanup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: mss_attr_cleanup.C,v 1.3 2014/02/19 13:41:22 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/centaur/working/procedures/ipl/fapi/mss_attr_cleanup.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE       : mss_attr_cleanup
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  : Mark Bellows      Email: bellows@us.ibm.com
// *! BACKUP NAME : Anuwat Saetow     Email: asaetow@us.ibm.com

// *! ADDITIONAL COMMENTS :
//
// clean up any centaur and mba attributes if a centaur is not in the system.
// The main attributes are the ones relating to grouping - other attributes may have settings
// but aren't going to be used by initfiles 
//
// There is a sub function that cleans up an mba that needs to be called if we deconfigure an mba
// this procedure writes attributes and write hardware
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.3   | bellows  |17-FEB-14| RAS Review Comments
//   1.2   | bellows  |11-NOV-13| Gerrit Review Comments
//   1.1   | bellows  |28-NOV-12| First Draft. Functions implemented
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// My Includes
//------------------------------------------------------------------------------
#include <mss_attr_cleanup.H>
#include <cen_scom_addresses.H>
#include <mss_eff_config.H>

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

const uint8_t PORT_SIZE = 2;
const uint8_t DIMM_SIZE = 2;


//------------------------------------------------------------------------------
// extern encapsulation
//------------------------------------------------------------------------------
extern "C"
{

//------------------------------------------------------------------------------
// @brief mss_attr_cleanup(): This function will disable a centaur - fencing it and powering it down
//
// @param const fapi::Target i_target_centaur: the fapi target of the centaur
// @param const fapi::Target i_target_mba0: the mba0 target
// @param const fapi::Target i_target_mba1: the mba1 target
//
// @return fapi::ReturnCode
//------------------------------------------------------------------------------
  fapi::ReturnCode mss_attr_cleanup(const fapi::Target & i_target_centaur, const fapi::Target & i_target_mba0, const fapi::Target & i_target_mba1)
  {
    fapi::ReturnCode rc;

    FAPI_INF("Running mss_attr_cleanup on %s\n", i_target_centaur.toEcmdString());

    do
    {

      rc = mss_attr_cleanup_mba_attributes(i_target_mba0);
      if(rc) break;
      rc = mss_attr_cleanup_mba_attributes(i_target_mba1);
      if(rc) break;

    /* need to add code that fences and centaur and powers off clocks */
    } while(0); 

    return rc;
  } // end mss_attr_cleanup()


  fapi::ReturnCode mss_attr_cleanup_mba_attributes(const fapi::Target & i_target_mba) 
  {
  // turn off functional vector
    fapi::ReturnCode rc;
    uint8_t dimm_functional_vector=0x00; // ready to set all DIMMs to non functional
    uint8_t mba_functional;
    uint8_t eff_dimm_size[PORT_SIZE][DIMM_SIZE];
    int i,j;
    uint8_t dimm_ranks[PORT_SIZE][DIMM_SIZE]; // Number of ranks for each configured DIMM in each MBA
    uint8_t dimm_type;
    uint8_t spd_dimm_ranks[PORT_SIZE][DIMM_SIZE];
    uint8_t module_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM;
    uint8_t custom = fapi::ENUM_ATTR_SPD_CUSTOM_YES;
    uint8_t mba_port;
    uint8_t mba_dimm;

    do
    {
      rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &i_target_mba, mba_functional);
      if(rc) break;

      if(! mba_functional ) 
      {

// read in some SPD attributes that are used in thermal (non functional DIMM/MBA, yet uses power)
// we do this because we are cleaning up a DIMM that may not be functional any more due to whatever reason
        std::vector<fapi::Target> target_dimm_array;
        rc = fapiGetAssociatedDimms(i_target_mba, target_dimm_array);
        if(rc) break;

        for (uint8_t dimm_index = 0; dimm_index <
          target_dimm_array.size(); dimm_index += 1)
        {
          rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &target_dimm_array[dimm_index], mba_port);
          if(rc) break;
          rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &target_dimm_array[dimm_index], mba_dimm);
          if(rc) break;

          if(mba_port == 0 && mba_dimm == 0) 
          {
            rc = FAPI_ATTR_GET(ATTR_SPD_CUSTOM, &target_dimm_array[dimm_index], custom);
            if (rc) break;

            rc = FAPI_ATTR_GET(ATTR_SPD_MODULE_TYPE, &target_dimm_array[dimm_index], module_type);
            if(rc) break;
          }
          //should there be an else check that leads to HWP error?

              rc = FAPI_ATTR_GET(ATTR_SPD_NUM_RANKS, &target_dimm_array[dimm_index], spd_dimm_ranks[mba_port][mba_dimm]);
          if(rc) break;
        }

        // now szap the functional vector and dimm_size
        rc = FAPI_ATTR_SET(ATTR_MSS_EFF_DIMM_FUNCTIONAL_VECTOR, &i_target_mba,
                           dimm_functional_vector);
        if (rc) break;

        for(i=0;i<PORT_SIZE;i++)
        {
          for(j=0;j<DIMM_SIZE;j++)
          {
            eff_dimm_size[i][j]=0;
            switch (spd_dimm_ranks[i][j])
            {
                case fapi::ENUM_ATTR_SPD_NUM_RANKS_R4:
                    dimm_ranks[i][j]=4;
                    break;
                case fapi::ENUM_ATTR_SPD_NUM_RANKS_R2:
                    dimm_ranks[i][j]=2;
                    break;
                case fapi::ENUM_ATTR_SPD_NUM_RANKS_R1:
                    dimm_ranks[i][j]=1;
                    break;
                default:
                    dimm_ranks[i][j]=0;
                    break;
            }
            switch(module_type)
            {
                case fapi::ENUM_ATTR_SPD_MODULE_TYPE_RDIMM:
                    dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_RDIMM;
                    break;
                case fapi::ENUM_ATTR_SPD_MODULE_TYPE_UDIMM:
                    dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM;
                    break;
                case fapi::ENUM_ATTR_SPD_MODULE_TYPE_LRDIMM:
                    dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_LRDIMM;
                    break;
                default:
                    FAPI_INF("DIMM type set to %d on %s", fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM, i_target_mba.toEcmdString());
                    dimm_type = fapi::ENUM_ATTR_EFF_DIMM_TYPE_UDIMM;
                    break;
            }
          }
        }
        rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_SIZE, &i_target_mba, eff_dimm_size);
        if (rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_NUM_RANKS_PER_DIMM, &i_target_mba, dimm_ranks);
        if (rc) break;

        rc = FAPI_ATTR_SET(ATTR_EFF_DIMM_TYPE, &i_target_mba, dimm_type);
        if (rc) break;

      }
      else 
        { // reenable  -reverse everything

      }
    } while(0);

    if(rc) { FAPI_ERR("ERROR: Bad RC in mss_attr_cleanup_mba_attributes"); }
    return rc;
  } // end of mss_attr_cleanup_mba_attributes

} // extern "C"

