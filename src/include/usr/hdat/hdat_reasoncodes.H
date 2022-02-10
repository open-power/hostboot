/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hdat/hdat_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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


/**
 *  @file hdat_service_codes.H
 *
 *  @brief This file contains the definition of constants used to create SRCs
 *         and error logs.
 */

#ifndef HDATSERVICECODES_H
#define HDATSERVICECODES_H

/*----------------------------------------------------------------------------*/
/* Includes                                                                   */
/*----------------------------------------------------------------------------*/
#include <hbotcompid.H>

namespace HDAT
{

#define HDAT_TRACE_NAME "HDAT"

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
const uint8_t  SUBSEC_ADDITIONAL_SRC = 0x01;

/** @enum hdatModId
 *  "Module ids" for hypervisor data area SRCs
 *  Actually, these are ids assigned to each function/method within
 *  a module (.C file).  The ids must be unique across all component
 *  modules
 */
enum HDATModuleId
{
  MOD_UTIL_IS_FUNCTIONAL       = 0x01,
  MOD_PCIA_LOAD                = 0x02,
  MOD_PCIA_SET_CORE_INF        = 0x03,
  MOD_UTIL_CARD_ID             = 0x04,
  MOD_UTIL_GET_PARENT          = 0x05,
  MOD_PCIA_DESTRUCTOR          = 0x06,
  MOD_UTIL_GET_ECID_CHIPID     = 0x07,
  MOD_HDAT_INTERFACE           = 0x08,
  MOD_SLCA_DESTRUCTOR          = 0x09,
  MOD_IPLPARMS_DESTRUCTOR      = 0x0A,
  MOD_UTIL_GET_RID             = 0x0B,
  MOD_IOHUB_GET_RID            = 0x0C,
  MOD_IOHUB_FETCH_DAUGHTER     = 0x0D,
  MOD_IOHUB_BUILD_DAUGHTER     = 0x0E,
  MOD_IOHUB_LOAD_DATA          = 0x0F,
  MOD_IOHUB_ADD_CHIP           = 0x10,
  MOD_UTIL_VPD                 = 0x11,
  MOD_UTIL_CVPD_READ_FUNC      = 0x12,
  MOD_UTIL_SPD_READ_FUNC       = 0x13,
  MOD_ADD_IMT_ADDR_RANGE       = 0x14,
  MOD_ADD_UE_ADDR_RANGE        = 0x15,
  MOD_ADD_RES_HB_ADDR_RANGE    = 0x16,
  MOD_ADD_MS_AREA_FRU          = 0x17,
  MOD_ADD_RAM_FRU              = 0x18,
  MOD_ADD_ADDR_RANGE           = 0x19,
  MOD_ADD_RAM                  = 0x1a,
  MOD_MSVPD_DESTRUCTOR         = 0x1b,
  MOD_GET_PATH_INFO            = 0x1c,
  MOD_HDAT_SP_SUBSYS_CTOR      = 0x1d,
  MOD_HDAT_SP_SUBSYS_DTOR      = 0x1e,
  MOD_PCRD_LOAD                = 0x1f,
  MOD_PCRD_SET_PROC_INF        = 0x20,
  MOD_PCRD_DESTRUCTOR          = 0x21,
  MOD_UTIL_PVPD_READ_FUNC      = 0x22,
  MOD_PROCESS_FRU              = 0x23,
  MOD_BUILD_SPECIFIED_VPD      = 0x24,
  MOD_HDAT_SERVICEDATA_CTOR    = 0x25,
  MOD_HDAT_NODEDATA_DTOR       = 0x26,
  MOD_SPIRAS_CREATE_DATA_AREA  = 0x27,
  MOD_SPIRAS_DESTRUCTOR        = 0x28,
  MOD_HDAT_SPIRAH_DTOR         = 0x29,
  MOD_HDAT_GET_SPIRAH          = 0x2a,
  MOD_NACA_GET_MEM             = 0x2b,
  MOD_HBRT_LOAD_DATA           = 0x2c,
  MOD_UTIL_FULL_MVPD_READ_FUNC = 0x2d,
  MOD_HDAT_SPSUBSYS_FILL_DATA_PTRS = 0x2e,
  MOD_UTIL_PVPD_FULL_READ_FUNC = 0x2f,
  MOD_UTIL_MVPD                = 0x30,
  MOD_HDAT_IPMI_DTOR           = 0x31,
  MOD_TPMDATA_CONSTRUCTOR      = 0x32,
  MOD_TPMDATA_DESTRUCTOR       = 0x33,
  MOD_UTIL_SMP_LINK_INFO       = 0x34,
  MOD_ADD_MMIO_ADDR_RANGE      = 0x35,
  MOD_ADD_MS_AREA_IPZ_VPD      = 0x36,
  MOD_ADD_RAM_AREA_IPZ_VPD     = 0x37,
  MOD_SPD_RAW_CONVERT_TO_IPZ_TYPE   = 0x38,
  MOD_SPD_RAW_CONVERT_TO_IPZ_MODULE   = 0x39,
  MOD_SPD_TO_IPZ_CONVERT_TEMPLATE = 0x3a,
};


/** @enum HDATReasonCode
 *  Reason codes for hypervisor data area SRCs. Reason codes can be
 *  used in more than one location.  The combination of module id
 *  and reason code points to a unique piece of code.
 *  Therefore, if the same error can occur in multiple places within the
 *  same function/method, each error would need its own unique extended
 *  ref code.
 *
 *  The range is 0x9001 through 0x90FF
 */
enum HDATReasonCode
{
    RC_INVALID_OBJECT                 = HDAT_COMP_ID | 0x01,
    RC_TOP_LVL_TGT_NOT_FOUND          = HDAT_COMP_ID | 0x02,
    RC_INVALID_TGT_ATTR               = HDAT_COMP_ID | 0x03,
    RC_TARGET_UNSUPPORTED             = HDAT_COMP_ID | 0x04,
    RC_DEV_MAP_FAIL                   = HDAT_COMP_ID | 0x05,
    RC_EMPTY_TARGET_LIST              = HDAT_COMP_ID | 0x06,
    RC_SLCA_INDEX_RETRIEVE_FAIL       = HDAT_COMP_ID | 0x07,
    RC_SLCA_RID_RETRIEVE_FAIL         = HDAT_COMP_ID | 0x08,
    RC_ORDINAL_ID_RETRIEVE_FAIL       = HDAT_COMP_ID | 0x09,
    RC_TGT_ATTR_NOTFOUND              = HDAT_COMP_ID | 0x0A,
    RC_MEM_ALLOC_FAIL                 = HDAT_COMP_ID | 0x0B,
    RC_EXCEED_IOCHIP_NUM              = HDAT_COMP_ID | 0x0C,
    RC_DEV_READ_FAIL                  = HDAT_COMP_ID | 0x0D,
    RC_CVPD_READ_FAIL                 = HDAT_COMP_ID | 0x0E,
    RC_CVPD_FAIL                      = HDAT_COMP_ID | 0x0F,
    RC_SPD_READ_FAIL                  = HDAT_COMP_ID | 0x10,
    RC_ERC_MAX_EXCEEDED               = HDAT_COMP_ID | 0x11,
    RC_ERC_NO_PARENT                  = HDAT_COMP_ID | 0x12,
    RC_INPUT_TARGET_NULL              = HDAT_COMP_ID | 0x13,
    RC_MASTER_PROC_TARGET_NULL        = HDAT_COMP_ID | 0x14,
    RC_PVPD_READ_FAIL                 = HDAT_COMP_ID | 0x15,
    RC_PVPD_FAIL                      = HDAT_COMP_ID | 0x16,
    RC_PROCESS_FRU_FAIL               = HDAT_COMP_ID | 0x17,
    RC_DEV_UNMAP_FAIL                 = HDAT_COMP_ID | 0x18,
    RC_DATA_AREA_FAIL                 = HDAT_COMP_ID | 0x19,
    RC_NULL_PTR_PASSED                = HDAT_COMP_ID | 0x1a,
    RC_INVALID_NACA                   = HDAT_COMP_ID | 0x1b,
    RC_DEV_READ_VPD_FAIL              = HDAT_COMP_ID | 0x1c,
    RC_NO_BMC_TARGET_FOUND            = HDAT_COMP_ID | 0x1d,
    RC_INVALID_OBUS_BRICKID           = HDAT_COMP_ID | 0x1e,
    RC_INVALID_OBUS_FREQ_BUCKET       = HDAT_COMP_ID | 0x1f,
    RC_UNDEFINED_PROC_MODEL_EC        = HDAT_COMP_ID | 0x20,
    RC_INVALID_OBUS_PLL_FREQ          = HDAT_COMP_ID | 0x21,
    RC_OCMB_IPZ_CONVERT_FAIL          = HDAT_COMP_ID | 0x22,
    RC_DIMM_IPZ_CONVERT_FAIL          = HDAT_COMP_ID | 0x23,
    RC_INVALID_DIMM_TYPE              = HDAT_COMP_ID | 0x24,
    RC_INVALID_DIMM_MODULE            = HDAT_COMP_ID | 0x25,
    RC_SPD_IPZ_TEMPLATE_PROCESS_FAIL  = HDAT_COMP_ID | 0x26,
};

}  //namespace HDAT
#endif // HDATSERVICECODES_H
