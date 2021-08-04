/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/common/include/mds_scom_addresses.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

///
/// @file mds_scom_addresses.H
/// @brief MDS I2C scom register definitions
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
/// EKB-Mirror-To: hostboot
///

#ifndef __MDS_SCOM_ADDRESSES_H
#define __MDS_SCOM_ADDRESSES_H

static const uint32_t MDS_I2C_RCW_F0RC0A                     = 0x0000000Dul;

static const uint32_t MDS_I2C_RCW_F1RCCX                     = 0x0001001Bul;
static const uint32_t MDS_I2C_RCW_F1RCDX                     = 0x0001001Cul;
static const uint32_t MDS_I2C_RCW_F1RCEX                     = 0x0001001Dul;
static const uint32_t MDS_I2C_RCW_F1RCFX                     = 0x0001001Eul;

static const uint32_t MDS_I2C_RCW_FCRCDX                     = 0x000C001Cul;

static const uint32_t MDS_I2C_RCW_BURST_ORDER_MODE           = 0x00040027ul;

static const uint32_t MDS_I2C_RCW_F2RC00                     = 0x00020008ul;
static const uint32_t MDS_I2C_RCW_F2RC02                     = 0x00020009ul;


// TODO: Fix the below register values
//       All below are placeholder names/values
//       Spec/scripts have missing values/duplicates

static const uint32_t MDS_RCW_LTB_SA_RDDQ18_VOLT_CODE        = 0x000A0024ul;
static const uint32_t MDS_RCW_LTB_SA_RDDQ8_VOLT_CODE_EN      = 0x000A0027ul;
static const uint32_t MDS_RCW_LTB_SA_WRDQS3_TIME_CODE        = 0x0004002Cul;

static const uint32_t MDS_RCW_LTB_SA_RDDQ16_VOLT_CODE        = 0x00040022ul;
static const uint32_t MDS_RCW_LTB_SA_WRDQS9_TIME_CODE        = 0x00040032ul;
static const uint32_t MDS_RCW_LTB_SA_RDDQ17_VOLT_CODE        = 0x00040023ul;

static const uint32_t MDS_RCW_LTB_SA_RDDQ7_TIME_CODE         = 0x00090082ul;
static const uint32_t MDS_RCW_LTB_SA_RDDQ9_TIME_CODE         = 0x00090084ul;
static const uint32_t MDS_RCW_LTB_SABD_CAG2_TIME_CODE        = 0x00080033ul;
static const uint32_t MDS_RCW_LTB_SA_RDDQ16_TIME_CODE_EN     = 0x00040011ul;
static const uint32_t MDS_RCW_LTB_SA_RDDQ0_VOLT_CODE         = 0x00040012ul;
static const uint32_t MDS_RCW_LTB_SA_RDDQ3_VOLT_CODE         = 0x00040015ul;

static const uint32_t MDS_RCW_LTB_SA_WRDQS10_TIME_CODE       = 0x000F006Cul;
static const uint32_t MDS_RCW_LTB_SA_RDEN13_TIME_CODE        = 0x0004005Aul;
static const uint32_t MDS_RCW_LTB_SAAU_CAG3_TIME_CODE        = 0x0004000Dul;
static const uint32_t MDS_RCW_LTB_SAAU_CID_TIME_CODE         = 0x00040009ul;

static const uint32_t MDS_RCW_LTB_SAAD_CAG8_TIME_CODE        = 0x0006001Ful;
static const uint32_t MDS_RCW_LTB_SA_RDDQ14_VOLT_CODE        = 0x00060020ul;
static const uint32_t MDS_RCW_LTB_SA_RDDQ5_VOLT_CODE         = 0x00060017ul;

static const uint32_t MDS_RCW_LTB_SAAD_CAG1_TIME_CODE        = 0x00060018ul;
static const uint32_t MDS_RCW_LTB_SABD_CSN_TIME_CODE         = 0x0006002Ful;
static const uint32_t MDS_RCW_LTB_SABD_CID_TIME_CODE         = 0x00060030ul;

static const uint32_t MDS_RCW_LTB_SABU_CAG4_TIME_CODE        = 0x00060028ul;
static const uint32_t MDS_RCW_LTB_SABU_CAG3_TIME_CODE        = 0x00060027ul;

static const uint32_t MDS_RCW_LTB_SABU_CAG7_TIME_CODE        = 0x0006002Bul;
static const uint32_t MDS_RCW_LTB_SAAU_CAG8_TIME_CODE        = 0x00060012ul;
static const uint32_t MDS_RCW_LTB_SA_RDEN8_TIME_CODE_EN      = 0x00050062ul;

static const uint32_t MDS_RCW_LTB_SA_RDDQ8_TIME_CODE         = 0x000E0083ul;
static const uint32_t MDS_RCW_LTB_SAAU_CAG4_CA_LATENCY       = 0x0004003Dul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_0           = 0x00800671ul;

static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_1           = 0x00800672ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_2           = 0x00800673ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_3           = 0x00800674ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_4           = 0x00800675ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_5           = 0x00800676ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_6           = 0x00800677ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_7           = 0x00800678ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_8           = 0x00800679ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_9           = 0x0080067Aul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_A           = 0x0080067Bul;

static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_B           = 0x00400006ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_C           = 0x00800524ul;

static const uint32_t MDS_RCW_LTB_SA_WRDQ3_TIME_CODE         = 0x00060043ul;

static const uint32_t MDS_RCW_LTB_SABU_RDDQ13                = 0x00070008ul;
static const uint32_t MDS_RCW_LTB_SABU_RDDQ14                = 0x00070009ul;
static const uint32_t MDS_RCW_LTB_SABU_RDDQ15                = 0x0007000Aul;
static const uint32_t MDS_RCW_LTB_SABU_RDDQ16                = 0x0007000Bul;

static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_D           = 0x0080064Cul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_E           = 0x00800650ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_F           = 0x00800654ul;

static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_11          = 0x00800658ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_12          = 0x0080065Cul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_13          = 0x00800660ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_14          = 0x00800664ul;
static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_15          = 0x00800668ul;

static const uint32_t MDS_NO_MATCHING_SPEC_VALUE_16          = 0x000E0077ul;

static const uint32_t MDS_RCW_LTB_SABU_CAG5_TIME_CODE        = 0x00040029ul;

#endif
