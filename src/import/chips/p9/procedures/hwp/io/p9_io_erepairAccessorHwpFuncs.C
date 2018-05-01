/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/io/p9_io_erepairAccessorHwpFuncs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_io_erepairAccessorHwpFuncs.C
/// @brief FW Team utility functions that access fabric and memory eRepair data.
///
//----------------------------------------------------------------------------
#include <fapi2.H>
#include <string.h>
#include <p9_io_erepairConsts.H>

using namespace EREPAIR;
using namespace fapi2;

/***** Function definitions *****/

/**
 * @brief This function checks to see if the passed vectors have matching
 *        fail lane numbers. If no matching lane number is found, such lane
 *        value will be invalidated in the vector
 *
 * @param [in]  io_endp1_txFaillanes        Reference to vector which has fail
 *                                          lane numbers of Tx side
 * @param [in]  io_endp2_rxFaillanes        Reference to vector which has fail
 *                                          lane numbers of Rx side
 * @param [out] o_invalidFails_inTx_Ofendp1 If TRUE, indicates that Tx has fail
 *                                          lane numbers for which there is no
 *                                          matching entry on Rx side
 * @param [out] o_invalidFails_inRx_Ofendp2 If TRUE, indicates that Tx has fail
 *                                          lane numbers for which there is no
 *                                          matching entry on Tx side
 *
 * @return void
 */
void invalidateNonMatchingFailLanes(std::vector<uint8_t>& io_endp1_txFaillanes,
                                    std::vector<uint8_t>& io_endp2_rxFaillanes,
                                    bool& o_invalidFails_inTx_Ofendp1,
                                    bool& o_invalidFails_inRx_Ofendp2)
{
    std::vector<uint8_t>::iterator l_it;
    std::vector<uint8_t>::iterator l_itTmp;
    std::vector<uint8_t>::iterator l_itDrv;
    std::vector<uint8_t>::iterator l_itRcv;

    o_invalidFails_inTx_Ofendp1 = false;
    o_invalidFails_inRx_Ofendp2 = false;

    std::sort(io_endp1_txFaillanes.begin(), io_endp1_txFaillanes.end());
    std::sort(io_endp2_rxFaillanes.begin(), io_endp2_rxFaillanes.end());

    // Start with drive side fail lanes and check for matching lanes
    // on the recieve side
    l_itTmp = io_endp2_rxFaillanes.begin();

    for(l_itDrv = io_endp1_txFaillanes.begin();
        l_itDrv != io_endp1_txFaillanes.end();
        l_itDrv++)
    {
        l_it = std::lower_bound(io_endp2_rxFaillanes.begin(),
                                io_endp2_rxFaillanes.end(),
                                *l_itDrv);

        // If matching fail lane is not found on the receive side,
        // invalidate the drive side fail lane number
        if((l_it == io_endp2_rxFaillanes.end()) || (*l_it > *l_itDrv))
        {
            *l_itDrv = INVALID_FAIL_LANE_NUMBER;
            o_invalidFails_inTx_Ofendp1 = true;
        }
        else
        {
            // save the iterator for the next search
            l_itTmp = l_it;
        }
    }

    // Sort again as we might have invalidated some lanes
    std::sort(io_endp1_txFaillanes.begin(), io_endp1_txFaillanes.end());

    // Now, traverse through the receive side fail lanes and
    // check for matching lanes on the drive side
    for(l_itRcv = io_endp2_rxFaillanes.begin();
        ((l_itRcv <= l_itTmp) && (l_itRcv != io_endp2_rxFaillanes.end()));
        l_itRcv++)
    {
        l_it = std::lower_bound(io_endp1_txFaillanes.begin(),
                                io_endp1_txFaillanes.end(),
                                *l_itRcv);

        // If matching lane is not found on the driver side,
        // invalidate the receive side fail lane number
        if((l_it == io_endp1_txFaillanes.end()) || (*l_it > *l_itRcv))
        {
            *l_itRcv = INVALID_FAIL_LANE_NUMBER;
            o_invalidFails_inRx_Ofendp2 = true;
        }
    }

    // Need to invalidate all the entries beyond the last
    // lower bound of first search
    if(l_itTmp != io_endp2_rxFaillanes.end())
    {
        for(l_itTmp++; l_itTmp != io_endp2_rxFaillanes.end(); l_itTmp++)
        {
            *l_itTmp = INVALID_FAIL_LANE_NUMBER;
        }
    }
}

/**
 * @brief This function combines the eRepair lane numbers read from
 *        Manufacturing VPD and Field VPD
 *
 * @param [in]  i_mnfgFaillanes  The eRepair lane numbers read from the
 *                               Manufacturing VPD
 * @param [in]  i_fieldFaillanes The eRepair lane numbers read from the
 *                               Field VPD
 * @param [out] o_allFaillanes   The eRepair lane numbers which is the union
 *                               of the Field and Manufacturing eRepair lanes
 *                               passed as first iand second params
 *
 * @return void
 */
void combineFieldandMnfgLanes(std::vector<uint8_t>& i_mnfgFaillanes,
                              std::vector<uint8_t>& i_fieldFaillanes,
                              std::vector<uint8_t>& o_allFaillanes)
{
    std::vector<uint8_t>::iterator l_it;

    // Merge the Field and Mnfg fail lanes
    l_it = o_allFaillanes.begin();
    o_allFaillanes.insert(l_it,
                          i_mnfgFaillanes.begin(),
                          i_mnfgFaillanes.end());

    l_it = o_allFaillanes.end();
    o_allFaillanes.insert(l_it,
                          i_fieldFaillanes.begin(),
                          i_fieldFaillanes.end());

    // Check if Mfg VPD and Field VPD have same fail lanes.
    // If found, erase them
    std::sort(o_allFaillanes.begin(), o_allFaillanes.end());

    o_allFaillanes.erase(std::unique(o_allFaillanes.begin(),
                                     o_allFaillanes.end()),
                         o_allFaillanes.end());

}
