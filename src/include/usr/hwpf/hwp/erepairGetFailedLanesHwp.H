/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/erepairGetFailedLanesHwp.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: erepairGetFailedLanesHwp.H,v 1.3 2014/04/29 11:59:55 bilicon Exp $
/**
 *  @file erepairGetFailedLanesHwp.H
 *
 *  @brief FW Team HWP that accesses the fail lanes of Fabric and Memory buses.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          bilicon     09/14/2012  Created.
 */

#ifndef EREPAIRGETFAILEDLANESHWP_H_
#define EREPAIRGETFAILEDLANESHWP_H_

#include <fapi.H>
#include <erepairConsts.H>


typedef fapi::ReturnCode (*erepairGetFailedLanesHwp_FP_t)(
                          const fapi::Target       &i_tgtHandle,
                          EREPAIR::erepairVpdType  i_vpdType,
                          std::vector<uint8_t>     &o_txFailLanes,
                          std::vector<uint8_t>     &o_rxFailLanes);

extern "C"
{

/**
 * @brief FW Team HWP that retrieves the eRepair fail lanes.
 *        It retrieves the eRepair data from the P8 MVPD and the Centaur FRU
 *        VPD sections depending on the passed target type. It then parses the
 *        eRepair data to determine the fail lane numbers on the sub-interfaces
 *        (Tx and Rx) of the passed bus target.
 *
 * @param[in] i_tgtHandle   Reference to X-Bus or A-Bus or MCS or memBuf Target
 * @param[in] i_vpdType     Specifies which VPD (MNFG or Field) to access.
 * @param[o]  o_txFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Tx sub-interface.
 * @param[o]  o_rxFailLanes Reference to a vector that will hold eRepair fail
 *                          lane numbers of the Rx sub-interface.
 *
 * @return ReturnCode
 *
 */
fapi::ReturnCode erepairGetFailedLanesHwp(
                                        const fapi::Target      &i_tgtHandle,
                                        EREPAIR::erepairVpdType i_vpdType,
                                        std::vector<uint8_t>    &o_txFailLanes,
                                        std::vector<uint8_t>    &o_rxFailLanes);

}// end of extern C

#endif
