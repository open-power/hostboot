/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmifruinv.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#ifndef __IPMI_IPMIFRUINV_H
#define __IPMI_IMPIFRUINV_H

namespace IPMIFRUINV
{
    /**
     * @brief Base function to be called to set the IPMI Fru
     *     inventory data for all targets in system
     *
     * @param[in]  updateData, Boolean indicating whether the data
     *             is being updated. If false, this function will send
     *             all the IPMI FRU Data. If True, it will only send
     *             updated data for procs/centaurs.
     */
    void setData(bool i_updateData=false);

    /**
     * @brief Clears fru data from BMC
     * @param[in] fruId, The fruId to be cleared
     */
    void clearData(uint8_t i_fruId);

    /**
     * @brief Gathers potential list of frus who may need their fru
     *        data cleared from the BMC
     * @param[in] pSys, Top level system target
     * @param[in/out] frusToClear, Map of potential frus to clear
     */
    void gatherClearData(const TARGETING::Target* i_pSys,
                                    std::map<uint8_t,bool>& io_frusToClear);

    /**
     * @brief Updates vector of potential frus to set inventory
     *        data for. Updates map of frus that need their
     *        fru inventory data cleared.
     * @param[in] pSys, Top level system target
     * @param[in/out] frusToClear, Map of potential frus to clear
     * @param[in] updateData, Bool indicating the data is being updated
     *            True - Doing an update to previously set data
     *            False - Setting base data
     */
    void gatherSetData(const TARGETING::Target* i_pSys,
                                  std::map<uint8_t,bool>& io_frusToClear,
                   std::vector< std::pair<TARGETING::TargetHandle_t, uint8_t> >&
                                                               io_potentialFrus,
                                  bool i_updateData);

};

#endif
