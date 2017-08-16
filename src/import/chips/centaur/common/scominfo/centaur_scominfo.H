/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/common/scominfo/centaur_scominfo.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file centaur_scominfo.H
/// @brief Centaur chip unit SCOM address platform translation code
///
/// HWP HWP Owner: unknown
/// HWP FW Owner: dcrowell@us.ibm.com
/// HWP Team: Infrastructure
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

#ifndef centaur_scominfo_h
#define centaur_scominfo_h

#include <vector>
#include <stdint.h>

extern "C" {
    typedef enum
    {
        CENTAUR_CHIP = 0, //Included as we might need this for future expansion
        MBA_CHIPUNIT = 1
    } centaurChipUnits_t;

    struct centaur_chipUnitPairing_t
    {
        centaurChipUnits_t chipUnitType;
        uint32_t chipUnitNum;
    };


    /**
     @brief creates the actual scom addr based on the chipunit, chipUnitNum, and chipUnit Zero's scom addr
     @param i_CentaurCU enumeration of the ChipUnit
     @param i_ChipUnitNum number of the chipUnit
     @param i_scomAddr the scom addr of chipUnit zero
     @param i_mode, used for special purposes, default to 0
     @retval uint64_t actual scom addr for the chipUnit/chipUnitNum passed in
    */
    uint64_t centaur_scominfo_createChipUnitScomAddr(centaurChipUnits_t i_CentaurCU, uint8_t i_ChipUnitNum,
            uint64_t i_scomAddr, uint32_t i_mode = 0);

    /**
     @brief determines if the scom address correlates to a chipUnit, if so create a list of chipUnits and their number
     @param i_scomAddr scom address that we want to test
     @param o_chipUnitRelated, bool returns true if scom addr is a chipUnit Addr
     @param o_chipUnitPairing, list of the enum of chipUnitPairings
     @param i_mode, used for special purposes, default to 0
     @retval uint32_t return non-zero for error
    */
    uint32_t centaur_scominfo_isChipUnitScom(uint64_t i_scomAddr, bool& o_chipUnitRelated,
            std::vector<centaur_chipUnitPairing_t>& o_chipUnitPairing, uint32_t i_mode = 0);

}

#endif /* centaur_scominfo_h */
