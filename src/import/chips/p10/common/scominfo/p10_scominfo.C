/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/scominfo/p10_scominfo.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p10_scominfo.C
/// @brief P10 chip unit SCOM address platform translation code
///
/// HWP Owner: thi@us.ibm.com
/// HWP Team: NEST
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

// includes
#include "p10_scominfo.H"
#include "p10_scom_addr.H"

#define P10_SCOMINFO_C

//@thi-TODO: Need to revisit the following items once design is finalized:
//           PPE, IOHS, PAU, MI, MCC, OMI, OMIC
extern "C"
{

    // ---------------------------
    // Internal functions
    // ---------------------------

    /// @brief Calculate the region select (core ID) value for given core
    ///        instance
    /// @param[in] i_coreInstance   Core instance number (0-31)
    /// @retval uint8_t Region select value
    uint8_t calcRegionSelect(uint8_t i_coreInstanceNum)
    {
        uint8_t l_regionSel = 0;

        if (i_coreInstanceNum % NUM_CORES_PER_EQ == 0)
        {
            l_regionSel = 8;
        }
        else if (i_coreInstanceNum % NUM_CORES_PER_EQ == 1)
        {
            l_regionSel = 4;
        }
        else if (i_coreInstanceNum % NUM_CORES_PER_EQ == 2)
        {
            l_regionSel = 2;
        }
        else
        {
            l_regionSel = 1;
        }

        return l_regionSel;
    }

    /// @brief Validate the chip unit number to be within range
    ///        of a chip unit type.
    /// @param[in] i_chipUnitNum   Value of chip unit number (instance)
    /// @param[in] i_chipUnitType  Chip unit type
    /// @retval Non-zero if error
    uint8_t validateChipUnitNum(const uint8_t i_chipUnitNum,
                                const p10ChipUnits_t i_chipUnitType)
    {
        uint8_t l_rc = 0;
        uint8_t l_index;

        for (l_index = 0;
             l_index < (sizeof(ChipUnitDescriptionTable) / sizeof(p10_chipUnitDescription_t));
             l_index++)
        {
            // Looking for input chip unit type in table
            if (i_chipUnitType == ChipUnitDescriptionTable[l_index].enumVal)
            {
                // Found a match, check input i_chipUnitNum to be <= max chip unit num
                // for this unit type
                if (i_chipUnitNum > ChipUnitDescriptionTable[l_index].maxChipUnitNum)
                {
                    l_rc = 1;
                }

                // Additional check for PERV targets, where there are gaps between instances
                else if (i_chipUnitType == PU_PERV_CHIPUNIT)
                {
                    if ( (i_chipUnitNum == 0) ||
                         ((i_chipUnitNum > 3) && (i_chipUnitNum < 8)) ||
                         ((i_chipUnitNum > 9) && (i_chipUnitNum < 12)) ||
                         ((i_chipUnitNum > 19) && (i_chipUnitNum < 24)) )
                    {
                        l_rc = 1;
                    }
                }

                // Additional check for PPE targets, where there are gaps between instances
                else if (i_chipUnitType == PU_PPE_CHIPUNIT)
                {
                    if ( ((i_chipUnitNum > 0) && (i_chipUnitNum < 4))   ||
                         ((i_chipUnitNum > 7) && (i_chipUnitNum < 16))  ||
                         ((i_chipUnitNum > 19) && (i_chipUnitNum < 32)) )
                    {
                        l_rc = 1;
                    }
                }

                // Additional check for PAU targets, where instance 1 and 2 are not valid
                else if (i_chipUnitType == PU_PAU_CHIPUNIT)
                {
                    if ( (i_chipUnitNum == 1) || (i_chipUnitNum == 2) )
                    {
                        l_rc = 1;
                    }
                }

                break;
            }
        }

        // Can't find i_chipUnitType in table
        if ( l_index >= (sizeof(ChipUnitDescriptionTable) / sizeof(p10_chipUnitDescription_t)) )
        {
            l_rc = 1;
        }

        return (l_rc);
    }

    // See header file for function description
    uint64_t p10_scominfo_createChipUnitScomAddr(const p10ChipUnits_t i_p10CU,
            const uint8_t i_ecLevel,
            const uint8_t i_chipUnitNum,
            const uint64_t i_scomAddr,
            const uint32_t i_mode)
    {
        uint8_t l_rc = 0;
        p10_scom_addr l_scom(i_scomAddr);
        uint8_t l_index = 0;

        do
        {
            // Make sure i_chipUnitNum is within range
            l_rc = validateChipUnitNum(i_chipUnitNum, i_p10CU);

            if (l_rc)
            {
                l_scom.setAddr(FAILED_TRANSLATION);
                break;
            }

            // If chip unit type is a chip, return input address
            if (i_p10CU == P10_NO_CU)
            {
                l_scom.setAddr(i_scomAddr);
                break;
            }

            switch (i_p10CU)
            {
                case PU_EQ_CHIPUNIT:
                    l_scom.setChipletId(EQ0_CHIPLET_ID + i_chipUnitNum);
                    break;

                case PU_C_CHIPUNIT:
                    // Set the EQ chiplet ID for this core's unit num
                    l_scom.setChipletId(EQ0_CHIPLET_ID + (i_chipUnitNum / NUM_CORES_PER_EQ));

                    // Set the core's region select (core ID)
                    l_scom.setRegionSelect(calcRegionSelect(i_chipUnitNum));
                    break;

                case PU_PEC_CHIPUNIT:

                    // PEC (Nest)
                    if ( (l_scom.getChipletId() >= N0_CHIPLET_ID) &&
                         (l_scom.getChipletId() <= N1_CHIPLET_ID) )
                    {
                        l_scom.setChipletId(N0_CHIPLET_ID + i_chipUnitNum);
                    }
                    // PEC (PCIe)
                    else if ( (l_scom.getChipletId() >= PCI0_CHIPLET_ID) &&
                              (l_scom.getChipletId() <= PCI1_CHIPLET_ID) )
                    {
                        l_scom.setChipletId(PCI0_CHIPLET_ID + i_chipUnitNum);
                    }

                    break;

                case PU_PHB_CHIPUNIT:

                    // phb 0-2 use PCI0 chiplet ID
                    // ring id = 3-5
                    if ( i_chipUnitNum < 3 )
                    {
                        l_scom.setChipletId(PCI0_CHIPLET_ID);
                        l_scom.setRingId(i_chipUnitNum + 3);
                    }
                    // phb 3-5 use PCI1 chiplet ID
                    // ring id = 3-5
                    else
                    {
                        l_scom.setChipletId(PCI1_CHIPLET_ID);
                        l_scom.setRingId(i_chipUnitNum);
                    }

                    break;

                case PU_NMMU_CHIPUNIT:
                    if ( i_chipUnitNum == 0)
                    {
                        l_scom.setChipletId(N0_CHIPLET_ID);
                    }
                    else
                    {
                        l_scom.setChipletId(N1_CHIPLET_ID);
                    }

                    break;

                case PU_PERV_CHIPUNIT:
                    l_scom.setChipletId(i_chipUnitNum);
                    break;

                case PU_IOHS_CHIPUNIT:

                    // If chiplet ID is of AXON chiplets
                    if ( (l_scom.getChipletId() >= AXON0_CHIPLET_ID) &&      // 0x18
                         (l_scom.getChipletId() <= AXON7_CHIPLET_ID) )       // 0x1F
                    {
                        l_scom.setChipletId(AXON0_CHIPLET_ID + i_chipUnitNum);
                    }
                    else // chiplet ID is of PAU chiplets
                    {
                        l_scom.setChipletId(PAU0_CHIPLET_ID + (i_chipUnitNum / 2));
                    }

                    break;

                case PU_MI_CHIPUNIT:
                case PU_MC_CHIPUNIT:
                    l_scom.setChipletId(MC0_CHIPLET_ID + i_chipUnitNum);
                    break;

                case PU_MCC_CHIPUNIT:
                    l_scom.setChipletId(MC0_CHIPLET_ID + (i_chipUnitNum / 2));

                    // Set Sat ID
                    if (i_chipUnitNum % 2)
                    {
                        // For odd MCC instance, Sat Id is to be set to 5, or 9
                        // If input address is an even instance that has:
                        //   SatId = 0x4 --> set translated SatId to 0x5
                        //         = 0x8 --> set translated SatId to 0x9
                        // If input address is an odd instance, leave the SatId
                        // as input address.
                        if (l_scom.getSatId() == 0x4)
                        {
                            l_scom.setSatId(0x5);
                        }
                        else if (l_scom.getSatId() == 0x8)
                        {
                            l_scom.setSatId(0x9);
                        }
                    }
                    else
                    {
                        // For even MCC instance, Sat Id is to be set to 4, or 8
                        // If input address is an odd instance that has:
                        //   SatId = 0x5 --> set translated SatId to 0x4
                        //         = 0x9 --> set translated SatId to 0x8
                        // If input address is an even instance, leave the SatId
                        // as input address.
                        if (l_scom.getSatId() == 0x5)
                        {
                            l_scom.setSatId(0x4);
                        }
                        else if (l_scom.getSatId() == 0x9)
                        {
                            l_scom.setSatId(0x8);
                        }
                    }

                    break;

                case PU_OMI_CHIPUNIT:
                    l_scom.setChipletId(MC0_CHIPLET_ID + (i_chipUnitNum / 4));

                    // Set Ring ID
                    if ( (i_chipUnitNum / 2) % 2 )
                    {
                        // For odd OMI instances after dividing by 2 (2, 3, 6, 7, 10, 11, 14, and 15)
                        // If input address has ringId = 0x3 --> set translated RingId to 0x4
                        //                             = 0x5 --> set translated RingId to 0x6
                        // Leave RingId as is otherwise.
                        if (l_scom.getRingId() == 0x3)
                        {
                            l_scom.setRingId(0x4);
                        }
                        else if (l_scom.getRingId() == 0x5)
                        {
                            l_scom.setRingId(0x6);
                        }
                    }
                    else
                    {
                        // For even OMI instances after dividing by 2 (0, 1, 4, 5, 8, 9, 12, and 13)
                        // If input address has ringId = 0x4 --> set translated RingId to 0x3
                        //                             = 0x6 --> set translated RingId to 0x5
                        // Leave RingId as is otherwise.
                        if (l_scom.getRingId() == 0x4)
                        {
                            l_scom.setRingId(0x3);
                        }
                        else if (l_scom.getRingId() == 0x6)
                        {
                            l_scom.setRingId(0x5);
                        }
                    }

                    break;

                case PU_OMIC_CHIPUNIT:
                    l_scom.setChipletId(MC0_CHIPLET_ID + (i_chipUnitNum / 2));

                    if (i_chipUnitNum % 2)
                    {
                        // For odd OMIC instance, RingId is to be set to 4, or 6
                        // If input address is an even instance that has:
                        //   RingId = 0x3 --> set translated RingId to 0x4
                        //          = 0x5 --> set translated RingId to 0x6
                        //
                        // If input address is an odd instance, leave the RingId
                        // as input address.
                        if (l_scom.getRingId() == 0x3)
                        {
                            l_scom.setRingId(0x4);
                        }
                        else if (l_scom.getRingId() == 0x5)
                        {
                            l_scom.setRingId(0x6);
                        }
                    }
                    else
                    {
                        // For even OMIC instance, RingId is to be set to 3, or 5
                        // If input address is an odd instance that has:
                        //   RingId = 0x4 --> set translated RingId to 0x3
                        //          = 0x6 --> set translated RingId to 0x5
                        // If input address is an even instance, leave the RingId
                        // as input address.
                        if (l_scom.getRingId() == 0x4)
                        {
                            l_scom.setRingId(0x3);
                        }
                        else if (l_scom.getRingId() == 0x6)
                        {
                            l_scom.setRingId(0x5);
                        }
                    }

                    break;

                case PU_PPE_CHIPUNIT:

                    // Look for i_chipUnitNum in table (instance)
                    for (l_index = 0;
                         l_index < sizeof(PpeTargetInfoTable) / sizeof(PpeTargetInfo_t);
                         l_index++)
                    {
                        if (i_chipUnitNum == PpeTargetInfoTable[l_index].targetInstance)
                        {
                            l_scom.setChipletId(PpeTargetInfoTable[l_index].chipletId);
                            l_scom.setEndpoint(PpeTargetInfoTable[l_index].endpointId);
                            l_scom.setRingId(PpeTargetInfoTable[l_index].ringId);
                            l_scom.setSatId(PpeTargetInfoTable[l_index].satId);
                        }
                    }

                    break;

                case PU_PAU_CHIPUNIT:
                    l_scom.setChipletId( PAU0_CHIPLET_ID + (i_chipUnitNum / 2) );

                    // Setting RingId for instances 0, 3, 4, and 6
                    // If input address has:
                    //   RingId = 0x4 --> set translated RingId to 0x2
                    //            0x5 --> set translated RingId to 0x3
                    //            0x8 --> set translated RingId to 0x6
                    //            0x9 --> set translated RingId to 0x7
                    // Leave RingId as is otherwise
                    if ( (i_chipUnitNum == 0) ||
                         (i_chipUnitNum == 3) ||
                         (i_chipUnitNum == 4) ||
                         (i_chipUnitNum == 6) )
                    {
                        if (l_scom.getRingId() == 0x4)
                        {
                            l_scom.setRingId(0x2);
                        }
                        else if (l_scom.getRingId() == 0x5)
                        {
                            l_scom.setRingId(0x3);
                        }
                        else if (l_scom.getRingId() == 0x8)
                        {
                            l_scom.setRingId(0x6);
                        }
                        else if (l_scom.getRingId() == 0x9)
                        {
                            l_scom.setRingId(0x7);
                        }
                    }

                    // Setting RingId for instances 1, 2, 5, and 7
                    // If input address has:
                    //   RingId = 0x2 --> set translated RingId to 0x4
                    //            0x3 --> set translated RingId to 0x5
                    //            0x6 --> set translated RingId to 0x8
                    //            0x7 --> set translated RingId to 0x9
                    // Leave RingId as is otherwise
                    else if ( (i_chipUnitNum == 1) ||
                              (i_chipUnitNum == 2) ||
                              (i_chipUnitNum == 5) ||
                              (i_chipUnitNum == 7) )
                    {
                        if (l_scom.getRingId() == 0x2)
                        {
                            l_scom.setRingId(0x4);
                        }
                        else if (l_scom.getRingId() == 0x3)
                        {
                            l_scom.setRingId(0x5);
                        }
                        else if (l_scom.getRingId() == 0x6)
                        {
                            l_scom.setRingId(0x8);
                        }
                        else if (l_scom.getRingId() == 0x7)
                        {
                            l_scom.setRingId(0x9);
                        }
                    }

                    break;

                default:
                    l_scom.setAddr(FAILED_TRANSLATION);
                    break;
            }

        }
        while(0);

        return l_scom.getAddr();
    }

    // See header file for function description
    uint32_t p10_scominfo_isChipUnitScom(const p10ChipUnits_t i_p10CU,
                                         const uint8_t i_ecLevel,
                                         const uint64_t i_scomAddr,
                                         bool& o_chipUnitRelated,
                                         std::vector<p10_chipUnitPairing_t>& o_chipUnitPairing,
                                         const p10TranslationMode_t i_mode)
    {
        p10_scom_addr l_scom(i_scomAddr);
        o_chipUnitRelated = false;

        // Quad registers which can be addressed by EQ target type
        // eq: 0..7
        if (l_scom.isEqTarget())
        {
            o_chipUnitRelated = true;
            // PU_EQ_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_EQ_CHIPUNIT,
                                        l_scom.getEqTargetInstance()));
        }

        // Core, L2, L3 registers which can be addressed by core target type
        // c: 0..31
        if (l_scom.isCoreTarget())
        {
            o_chipUnitRelated = true;
            // PU_C_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_C_CHIPUNIT,
                                        l_scom.getCoreTargetInstance()));
        }

        // PEC registers which can be addressed by pec target type
        // pec: 0..1
        if (l_scom.isPecTarget())
        {
            o_chipUnitRelated = true;
            // PU_PEC_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_PEC_CHIPUNIT,
                                        l_scom.getPecTargetInstance()));
        }

        // PHB registers
        // phb: 0..5
        if (l_scom.isPhbTarget())
        {
            o_chipUnitRelated = true;
            // PU_PHB_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_PHB_CHIPUNIT,
                                        l_scom.getPhbTargetInstance()));
        }

        // NMMU registers
        // nmmu: 0..1
        if (l_scom.isNmmuTarget())
        {
            o_chipUnitRelated = true;
            // PU_NMMU_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_NMMU_CHIPUNIT,
                                        l_scom.getNmmuTargetInstance()));
        }

        // PERV registers
        if (l_scom.isPervTarget())
        {
            o_chipUnitRelated = true;
            // PU_PERV_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_PERV_CHIPUNIT,
                                        l_scom.getPervTargetInstance()));
        }

        // IOHS registers
        if (l_scom.isIoHsTarget())
        {
            o_chipUnitRelated = true;
            // PU_IOHS_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_IOHS_CHIPUNIT,
                                        l_scom.getIoHsTargetInstance()));
        }

        // PAU registers
        if (l_scom.isPauTarget())
        {
            o_chipUnitRelated = true;
            // PU_PAU_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_PAU_CHIPUNIT,
                                        l_scom.getPauTargetInstance()));
        }

        // MC registers
        if (l_scom.isMcTarget())
        {
            o_chipUnitRelated = true;
            // PU_MC_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_MC_CHIPUNIT,
                                        l_scom.getMcTargetInstance()));
        }

        // MI registers
        if (l_scom.isMiTarget())
        {
            o_chipUnitRelated = true;
            // PU_MI_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_MI_CHIPUNIT,
                                        l_scom.getMiTargetInstance()));
        }

        // MCC registers
        if (l_scom.isMccTarget())
        {
            o_chipUnitRelated = true;
            // PU_MCC_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_MCC_CHIPUNIT,
                                        l_scom.getMccTargetInstance()));
        }

        // OMI registers
        if (l_scom.isOmiTarget())
        {
            o_chipUnitRelated = true;
            // PU_OMI_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_OMI_CHIPUNIT,
                                        l_scom.getOmiTargetInstance()));
        }

        // OMIC registers
        if (l_scom.isOmicTarget())
        {
            o_chipUnitRelated = true;
            // PU_OMIC_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_OMIC_CHIPUNIT,
                                        l_scom.getOmicTargetInstance()));
        }

        // PPE registers
        if (l_scom.isPpeTarget())
        {
            o_chipUnitRelated = true;
            // PU_PPE_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_PPE_CHIPUNIT,
                                        l_scom.getPpeTargetInstance()));
        }

        /// Address may be of a chip, let it pass through
        return (!l_scom.isValid());
    }

    uint32_t p10_scominfo_fixChipUnitScomAddrOrTarget(const p10ChipUnits_t i_p10CU,
            const uint8_t i_ecLevel,
            const uint32_t i_targetChipUnitNum,
            const uint64_t i_scomaddr,
            uint64_t& o_modifiedScomAddr,
            p10ChipUnits_t& o_p10CU,
            uint32_t& o_modifiedChipUnitNum,
            const uint32_t i_mode)
    {
        uint32_t rc = 0;

        o_modifiedScomAddr = i_scomaddr;
        o_p10CU = i_p10CU;
        o_modifiedChipUnitNum = i_targetChipUnitNum;

        return rc;
    }


} // extern "C"

#undef P10_SCOMINFO_C
