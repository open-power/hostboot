/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/mc_config/mss_eff_config/mss_error_support.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: mss_error_support.C,v 1.1 2013/03/21 19:04:19 bellows Exp $

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
//  1.1    | 03/08/13 | bellows | Initial Version

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
  fapi::ReturnCode l_rc;

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

  l_rc = FAPI_ATTR_GET(ATTR_POS, &i_target, _ATTR_PROC_POS);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_POS (Proc), ignoring");
  }

  l_rc = fapiGetChildChiplets(i_target, fapi::TARGET_TYPE_MEMBUF_CHIP, l_memb);

  if (l_rc)
  {
    FAPI_ERR("Error fapiGetChildChiplets, ignoring");
  }

  for(i=0;i<l_memb.size();i++) {
    l_rc = FAPI_ATTR_GET(ATTR_POS, &l_memb[i], _ATTR_CEN_POS);

    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_POS (cen), ignoring");
    }

    l_rc = fapiGetChildChiplets(l_memb[i], fapi::TARGET_TYPE_MBA_CHIPLET, l_mba_chiplets);

    if (l_rc)
    {
      FAPI_ERR("Error fapiGetChildChiplets, ignoring");
    }


    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mba_chiplets[0], _ATTR_CHIP_UNIT_POS_MBA0);

    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_CHIP_UNIT_POS (0), ignoring");
    }

    l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_mba_chiplets[1], _ATTR_CHIP_UNIT_POS_MBA1);

    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_CHIP_UNIT_POS (1), ignoring");
    }

    l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &l_mba_chiplets[0], _ATTR_EFF_DIMM_SIZE0);

    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_EFF_DIMM_SIZE (0), ignoring");
    }

    l_rc = FAPI_ATTR_GET(ATTR_EFF_DIMM_SIZE, &l_mba_chiplets[1], _ATTR_EFF_DIMM_SIZE1);

    if (l_rc)
    {
      FAPI_ERR("Error reading ATTR_EFF_DIMM_SIZE (1), ignoring");
    }
  }

  l_rc = FAPI_ATTR_GET(ATTR_MSS_INTERLEAVE_ENABLE,&i_target, _ATTR_MSS_INTERLEAVE_ENABLE);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_MSS_INTERLEAVE_ENABLE, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_ALL_MCS_IN_INTERLEAVING_GROUP, NULL,_ATTR_ALL_MCS_IN_INTERLEAVING_GROUP); // system level attribute

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_ALL_MCS_IN_INTERLEAVING_GROUP, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASE,&i_target,_ATTR_PROC_MEM_BASE);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_PROC_MEM_BASE, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASE,&i_target,_ATTR_PROC_MIRROR_BASE);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_PROC_MIRROR_BASE, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_MSS_MEM_MC_IN_GROUP, &i_target, _ATTR_MSS_MEM_MC_IN_GROUP);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_MSS_MEM_MC_IN_GROUP, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_PROC_MEM_BASES, &i_target, _ATTR_PROC_MEM_BASES);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_PROC_MEM_BASES, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_PROC_MEM_SIZES, &i_target, _ATTR_PROC_MEM_SIZES);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_PROC_MEM_SIZES, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_MSS_MCS_GROUP_32,&i_target, _ATTR_MSS_MCS_GROUP_32);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_MSS_MCS_GROUP_32, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_BASES, &i_target, _ATTR_PROC_MIRROR_BASES);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_PROC_MIRROR_BASES, ignoring");
  }

  l_rc = FAPI_ATTR_GET(ATTR_PROC_MIRROR_SIZES, &i_target, _ATTR_PROC_MIRROR_SIZES);

  if (l_rc)
  {
    FAPI_ERR("Error reading ATTR_PROC_MIRROR_SIZES, ignoring");
  }


  FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_ERROR_MSS_GROUPING_ATTRS);

  return fapi::FAPI_RC_SUCCESS;
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
    FAPI_ERR("Error fapiGetChildChiplets, ignoring");
  }

  for(i=0;i<l_mba_chiplets.size(); i++) {
    const fapi::Target & CENCHIP_MBA = l_mba_chiplets[i];
    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_ERROR_MBA_FIRS);

  }



  return fapi::FAPI_RC_SUCCESS;
}
