/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_error_support.C $ */
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
// $Id: mss_error_support.C,v 1.3 2014/02/19 13:41:28 bellows Exp $

//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : mss_error_support.C
// *! DESCRIPTION : common and hwp error collecting programs
// *! OWNER NAME : bellows@us.ibm.com
// *! BACKUP NAME :
// #! ADDITIONAL COMMENTS :
//

//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.3    | bellows  |19-FEB-14| RAS Review Updates
//  1.2    | bellows  | 05/08/13| Fixed error return code checking
//  1.1    | bellows  | 03/08/13| Initial Version

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

#include <fapi.H>
#include <mss_error_support.H>
#include <cen_scom_addresses.H>
using namespace fapi;

// This is the FFDC HWP specially written to collect the data specified by RC_ERROR_MEM_GROUPING
fapi::ReturnCode hwpCollectMemGrouping(const fapi::Target & i_target,fapi::ReturnCode & o_rc)
{
  fapi::ReturnCode l_rc = fapi::FAPI_RC_SUCCESS;

  uint32_t _ATTR_PROC_POS;
  uint32_t _ATTR_CEN_POS;
  uint8_t _ATTR_CHIP_UNIT_POS_MBA0;
  uint8_t _ATTR_CHIP_UNIT_POS_MBA1;
  uint8_t _ATTR_EFF_DIMM_SIZE0[2][2];
  uint8_t _ATTR_EFF_DIMM_SIZE1[2][2];
  uint8_t _ATTR_MSS_INTERLEAVE_ENABLE;
  uint8_t _ATTR_ALL_MCS_IN_INTERLEAVING_GROUP;
  uint64_t _ATTR_PROC_MEM_BASE;
  uint64_t _ATTR_PROC_MIRROR_BASE;
  uint8_t _ATTR_MSS_MEM_MC_IN_GROUP[8];
  uint64_t _ATTR_PROC_MEM_BASES[8];
  uint64_t _ATTR_PROC_MEM_SIZES[8];
  uint32_t _ATTR_MSS_MCS_GROUP_32[16][16];
  uint64_t _ATTR_PROC_MIRROR_BASES[4];
  uint64_t _ATTR_PROC_MIRROR_SIZES[4];

  std::vector<fapi::Target> l_mba_chiplets;
  std::vector<fapi::Target> l_memb;

  unsigned i;

  do
  {
    l_rc = FAPI_ATTR_GET(ATTR_POS, &i_target, _ATTR_PROC_POS);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_POS (Proc)");
      break;
    }

    l_rc = fapiGetChildChiplets(i_target, fapi::TARGET_TYPE_MEMBUF_CHIP, l_memb);
    if (l_rc)
    {
      FAPI_ERR("Error fapiGetChildChiplets");
      break;
    }

    for(i=0;i<l_memb.size();i++)
    {
      l_rc = FAPI_ATTR_GET(ATTR_POS, &l_memb[i], _ATTR_CEN_POS);
      if (l_rc)
      {
        FAPI_ERR("Error reading ATTR_POS (cen)");
        break;
      }

      l_rc = fapiGetChildChiplets(l_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mba_chiplets);
      if (l_rc)
      {
        FAPI_ERR("Error fapiGetChildChiplets");
        break;
      }


      l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mba_chiplets[0], _ATTR_CHIP_UNIT_POS_MBA0);
      if (l_rc)
      {
        FAPI_ERR("Error reading ATTR_CHIP_UNIT_POS (0)");
        break;
      }

      l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mba_chiplets[1], _ATTR_CHIP_UNIT_POS_MBA1);
      if (l_rc)
      {
        FAPI_ERR("Error reading ATTR_CHIP_UNIT_POS (1)");
        break;
      }

      l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &l_mba_chiplets[0], _ATTR_EFF_DIMM_SIZE0);
      if (l_rc)
      {
        FAPI_ERR("Error reading ATTR_EFF_DIMM_SIZE (0)");
        break;
      }

      l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &l_mba_chiplets[1], _ATTR_EFF_DIMM_SIZE1);
      if (l_rc)
      {
        FAPI_ERR("Error reading ATTR_EFF_DIMM_SIZE (1)");
        break;
      }
    }

    l_rc = FAPI_ATTR_GET(ATTR_MSS_INTERLEAVE_ENABLE,&i_target, _ATTR_MSS_INTERLEAVE_ENABLE);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_MSS_INTERLEAVE_ENABLE");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_ALL_MCS_IN_INTERLEAVING_GROUP, NULL,_ATTR_ALL_MCS_IN_INTERLEAVING_GROUP); // system level attribute
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_ALL_MCS_IN_INTERLEAVING_GROUP");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE,&i_target,_ATTR_PROC_MEM_BASE);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_PROC_MEM_BASE");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASE,&i_target,_ATTR_PROC_MIRROR_BASE);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_PROC_MIRROR_BASE");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_MSS_MEM_MC_IN_GROUP, &i_target, _ATTR_MSS_MEM_MC_IN_GROUP);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_MSS_MEM_MC_IN_GROUP");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASES, &i_target, _ATTR_PROC_MEM_BASES);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_PROC_MEM_BASES");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_PROC_MEM_SIZES, &i_target, _ATTR_PROC_MEM_SIZES);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_PROC_MEM_SIZES");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_MSS_MCS_GROUP_32,&i_target, _ATTR_MSS_MCS_GROUP_32);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_MSS_MCS_GROUP_32");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASES, &i_target, _ATTR_PROC_MIRROR_BASES);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_PROC_MIRROR_BASES");
      break;
    }

    l_rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_SIZES, &i_target, _ATTR_PROC_MIRROR_SIZES);
    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_PROC_MIRROR_SIZES");
      break;
    }

    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_ERROR_MSS_GROUPING_ATTRS);

  }while(0);

  return l_rc;
}

fapi::ReturnCode hwpCollectMemFIRs(const fapi::Target & i_target,fapi::ReturnCode & o_rc)
{
  fapi::ReturnCode l_rc;

  const fapi::Target & CENCHIP = i_target;

  FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_ERROR_MSS_FIRS);


  std::vector<fapi::Target> l_mba_chiplets;
  unsigned i;
  l_rc = fapiGetChildChiplets(i_target, fapi::TARGET_TYPE_MBA_CHIPLET, l_mba_chiplets);
  if (l_rc)
  {
    FAPI_ERR("Error fapiGetChildChiplets");
    return l_rc;
  }

  for(i=0;i<l_mba_chiplets.size(); i++)
  {
    const fapi::Target & CENCHIP_MBA = l_mba_chiplets[i];
    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_ERROR_MBA_FIRS);

  }
  return fapi::FAPI_RC_SUCCESS;
}
