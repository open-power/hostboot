/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/erepairSetFailedLanesHwp.H $         */
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
// $Id: erepairSetFailedLanesHwp.H,v 1.2 2014/04/30 09:45:10 bilicon Exp $
/**
 *  @file erepairSetFailedLanesHwp.H
 *
 *  @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     10-Jan-2013 Created.
 */

#ifndef EREPAIRSETFAILEDLANESHWP_H_
#define EREPAIRSETFAILEDLANESHWP_H_

#include <fapi.H>
#include <erepairConsts.H>


typedef fapi::ReturnCode (*erepairSetFailedLanesHwp_FP_t)(
                          const fapi::Target         &i_tgtHandle,
                          EREPAIR::erepairVpdType    i_vpdType,
                          const std::vector<uint8_t> &i_txFailLanes,
                          const std::vector<uint8_t> &i_rxFailLanes);

extern "C"
{

/**
 * @brief FW Team HWP that writes the eRepair fail lanes to the VPD.
 *        The fail lanes will be written to either the P8 MVPD or the
 *        Centaur FRU VPD depending on the passed target type.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS or memBuf Target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[in] i_txFailLanes Reference to a vector that has the Tx side
 *                          (of i_tgtHandle) fail lane numbers that need
 *                          to be written to the VPD
 * @param[in] i_rxFailLanes Reference to a vector that has the Rx side
 *                          (of i_tgtHandle) fail lane numbers that need
 *                          to be written to the VPD
 *
 * @return ReturnCode
 *
 */
fapi::ReturnCode erepairSetFailedLanesHwp(
                                     const fapi::Target         &i_tgtHandle,
                                     EREPAIR::erepairVpdType    i_vpdType,
                                     const std::vector<uint8_t> &i_txFailLanes,
                                     const std::vector<uint8_t> &i_rxFailLanes);

}// end of extern C

#endif
