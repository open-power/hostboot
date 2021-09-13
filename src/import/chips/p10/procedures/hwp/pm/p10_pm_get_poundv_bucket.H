/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_get_poundv_bucket.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_pm_get_poundv_bucket.H
/// @brief Provide structure for voltageBucketData so that info from #V keyword
/// can be stored inside of this struct.
/// Also define prototype for p10_pm_get_poundv_bucket
///
/// *HWP HW Owner    : Greg Stills(stillgs@us.ibm.com)
/// *HWP FW Owner    : Prasad Bg Ranganath(prasadbgr@in.ibm.com)
/// *HWP Team        : PM - Calling this function.
/// *HWP Consumed by : HB
/// *HWP Level       : 2
///

#ifndef _P10_PM_GET_POUND_V_BUCKET_H_
#define _P10_PM_GET_POUND_V_BUCKET_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

namespace fapi2
{

#define NUM_OP_POINTS  8

typedef struct __attribute__((__packed__))
{
    uint16_t core_frequency;
    uint16_t vdd_voltage;
    uint16_t idd_tdp_ac_cur;
    uint16_t idd_tdp_dc_cur;
    uint16_t idd_rdp_ac_cur;
    uint16_t idd_rdp_dc_cur;
    uint16_t vcs_voltage;
    uint16_t ics_tdp_ac_cur;
    uint16_t ics_tdp_dc_cur;
    uint16_t ics_rdp_ac_cur;
    uint16_t ics_rdp_dc_cur;
    uint16_t core_freq_gb_sort;
    uint16_t vdd_vmin;
    uint16_t ivdd_powr_cur_act;
    uint8_t  core_powr_temp;
    uint16_t rt_tdp_ac_10ma;
    uint16_t rt_tdp_dc_10ma;
    uint8_t  spare[2];
} poundV_entry_pts_t;


typedef struct __attribute__((__packed__))
{
    uint16_t SRVdnVltg;
    uint16_t SRIdnTdpAcCurr;
    uint16_t SRIdnTdpDcCurr;
    uint16_t SRVioVltg;
    uint16_t SRIioTdpAcCurr;
    uint16_t SRIioTdpDcCurr;
    uint16_t SRVpciVltg;
    uint16_t SRIpciTdpAcCurr;
    uint16_t SRIpciTdpDcCurr;
    uint16_t SRVAvddVltg;
    uint16_t SRIAvddTdpAcCurr;
    uint16_t SRIAvddTdpDcCurr;
    uint8_t  modelDataFlag;
    uint16_t SRVDDVmax;
    uint16_t SRVCSVmax;
    uint8_t  QRVRM_enable;
    uint8_t  SRRsvd[3];
} poundV_static_rails_t;

typedef struct __attribute__((__packed__))
{
    uint16_t PAUFreq;
    uint16_t TSrtSocPowTgt;
    uint16_t VdnSrtSocPow;
    uint16_t VIOSrtSocPow;
    uint16_t VPCISrtSocPow;
    uint16_t AVDDSrtSocPow;
    uint16_t TSrtSocPowAct;
    uint16_t IDDRdpLmt;
    uint8_t  VddTdpWofIndx;
    uint8_t  VcsTdpWofIndx;
    uint8_t  VioTdpWofIndx;
    uint8_t  AmbTdpWofIndx;
    uint8_t  ModeIntrPlt;
    uint8_t  RdpSrtPwrTmp;
    uint8_t  TdpSrtPwrTmp;
    uint16_t VddTdpWofCoreFreq;
    uint16_t FxdFreqMdeCoreFreq;
    uint16_t VddPsavCoreFreq;
    uint16_t VddUTCoreFreq;
    uint16_t VddFmxCoreFreq;
    uint8_t  MmaThrTemp;
    uint8_t  IOThrTemp;
    uint16_t FxFreqPowTgt;
} poundV_other_info_t;
//Represents the data contained within a single #V (version=1) bucket
//Note: This structure should not be assumed to be binary identical
//to the contents of the VPD itself.
//Pack the struct so that we can get a consistent size with no
//extra padding
typedef struct __attribute__((__packed__))  voltageBucketData
{
    // bucket Id
    uint8_t bucketId;

    //Curve FIT0 - Curve FIT7
    poundV_entry_pts_t    operating_pts[NUM_OP_POINTS];

    //Static Rails
    poundV_static_rails_t static_rails;

    //Other info
    poundV_other_info_t   other_info;

} voltageBucketData_t;

}

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
///
/// @brief Read #V bucket data from CRP0 record based upon
///        bucket ID read off of parent proc chip. This function
///        will pass out a structured format of the #V data of correct
///        endianness.
/// @param[in]  i_target Proc chiplet target
/// @param[out] o_data structured data describing the #v bucket used
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_pm_get_poundv_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    fapi2::voltageBucketData_t& o_data);


#endif // _P10_PM_GET_POUND_V_BUCKET_H_
