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
/// HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// HWP FW Maintainer:
/// HWP Consumed by: Cronus, HB, HWSV
///

// includes
#include <p10_scominfo.H>
#include <p10_scom_addr.H>
#include <p10_cu_utils.H>

#define P10_SCOMINFO_C

extern "C"
{

    // ---------------------------
    // Internal functions
    // ---------------------------

    //################################################################################
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

    //################################################################################
    /// @brief Translate the upper 32-bit of an indirect scom address.
    ///        IOHS and OMI chip units can be targeted using PAU chiplets with
    ///        indirect SCOM addresses.
    ///
    /// @param[in] i_p10CU         Chip unit type
    /// @param[in] i_ecLevel       Chip EC level
    /// @param[in] i_chipUnitNum   Instance number of the chip unit
    /// @param[in] i_scomAddr      P10 SCOM address object
    /// @param[in] i_mode          Translation mode, specifying different addr translation methods.
    /// @retval Non-zero if error
    ///
    uint8_t xlateIoUpperAddr(
        const p10ChipUnits_t i_p10CU,
        const uint8_t i_ecLevel,
        const uint8_t i_chipUnitNum,
        p10_scom_addr& i_scomAddr,
        const uint32_t i_mode)
    {
        uint8_t l_rc = 0;

        do
        {
            ///
            ///  PAU0 (lower right) -> MC0 (OMI 0/1/2/3) + IOHS0 + IOHS1
            ///  PAU1 (upper right) -> MC2 (OMI 8/9/10/11) + IOHS2 + IOHS3
            ///  PAU2 (lower left) -> MC1 (OMI 4/5/6/7) + IOHS4 + IOHS5
            ///  PAU3 (upper left) -> MC3 (OMI 12/13/14/15) + IOHS6 + IOHS7
            ///
            ///  Group address bits (22:26) of upper 32-bit
            ///    Group 0: IOHS[0]
            ///    Group 1: IOHS[1]
            ///
            ///   From the OMI Link point of view, two DLs will target the same OMI PHY Group
            ///     Group 2: OMIPHY[0] Lanes 0-7  (OMI DL0 x8)
            ///     Group 2: OMIPHY[0] Lanes 8-15 (OMI DL1 x8)
            ///     Group 3: OMIPHY[1] Lanes 0-7  (OMI DL2 x8)
            ///     Group 3: OMIPHY[1] Lanes 8-15 (OMI DL3 x8)

            // IOHS target
            if (i_p10CU == PU_IOHS_CHIPUNIT)
            {
                // Group address = 0b00000 for IOHS0
                //               = 0b00001 for IOHS1
                i_scomAddr.setIoGroupAddr(i_chipUnitNum % 2);
            }
            // OMI target
            else if (i_p10CU == PU_OMI_CHIPUNIT)
            {
                // Group address = 0b00010 for OMI0 and OMI1
                //               = 0b00011 for OMI2 and OMI3
                if ( (i_chipUnitNum % 4 <= 1) ) // OMI DL 0&1
                {
                    i_scomAddr.setIoGroupAddr(0b00010);
                }
                else // OMI DL 2&3
                {
                    i_scomAddr.setIoGroupAddr(0b00011);
                }
            }
            else
            {
                l_rc = 1;
            }

        }
        while (0);

        return l_rc;
    }

    //################################################################################
    /// @brief Get the chiplet ID for a chip unit instance based on given
    ///        address and chip unit type
    /// @param[in]  i_addr          SCOM address
    /// @param[in]  i_chipUnitNum   Instance number
    /// @param[in]  i_chipUnitType  Chip unit type
    /// @param[out] o_chipletId     Output chiplet id
    /// @retval Non-zero if error
    uint8_t getChipletId(const uint64_t i_addr,
                         const uint8_t i_chipUnitNum,
                         const p10ChipUnits_t i_chipUnitType,
                         uint8_t& o_chipletId)
    {
        uint8_t l_rc = 0;

        do
        {
            p10_scom_addr l_scom(i_addr);

            switch (i_chipUnitType)
            {
                case PU_EQ_CHIPUNIT:
                    o_chipletId = EQ0_CHIPLET_ID + i_chipUnitNum;
                    break;

                case PU_C_CHIPUNIT:
                    o_chipletId = EQ0_CHIPLET_ID + (i_chipUnitNum / NUM_CORES_PER_EQ);
                    break;

                case PU_PEC_CHIPUNIT:

                    // If input address is of Nest chiplets
                    if ( (l_scom.getChipletId() >= N0_CHIPLET_ID) &&
                         (l_scom.getChipletId() <= N1_CHIPLET_ID) )
                    {
                        o_chipletId = N0_CHIPLET_ID + i_chipUnitNum;
                    }
                    // If input address is of PCI chiplets
                    else
                    {
                        o_chipletId = PCI0_CHIPLET_ID + i_chipUnitNum;
                    }

                    break;

                case PU_PHB_CHIPUNIT:
                    o_chipletId = (i_chipUnitNum / 3) + PCI0_CHIPLET_ID;
                    break;

                case PU_NMMU_CHIPUNIT:
                    o_chipletId = i_chipUnitNum + N0_CHIPLET_ID;
                    break;

                case PU_PERV_CHIPUNIT:
                    o_chipletId = i_chipUnitNum;
                    break;

                case PU_IOHS_CHIPUNIT:

                    // If input address is of AXON chiplets
                    if ( (l_scom.getChipletId() >= AXON0_CHIPLET_ID) &&      // 0x18
                         (l_scom.getChipletId() <= AXON7_CHIPLET_ID) )       // 0x1F
                    {
                        o_chipletId = AXON0_CHIPLET_ID + i_chipUnitNum;
                    }
                    else if ( (l_scom.getChipletId() >= PAU0_CHIPLET_ID) &&
                              (l_scom.getChipletId() <= PAU3_CHIPLET_ID) )
                    {
                        // PAU0 --> IOHS0, IOHS1
                        // PAU1 --> IOHS2, IOHS3
                        // PAU2 --> IOHS4, IOHS5
                        // PAU3 --> IOHS6, IOHS7
                        o_chipletId = (i_chipUnitNum / 2) + PAU0_CHIPLET_ID;
                    }
                    else
                    {
                        l_rc = 1;
                    }

                    break;

                case PU_MI_CHIPUNIT:
                case PU_MC_CHIPUNIT:
                    o_chipletId = i_chipUnitNum + MC0_CHIPLET_ID;
                    break;

                case PU_MCC_CHIPUNIT:
                case PU_OMIC_CHIPUNIT:
                    o_chipletId = (i_chipUnitNum / 2) + MC0_CHIPLET_ID;
                    break;

                case PU_OMI_CHIPUNIT:
                    if ( (l_scom.getChipletId() >= MC0_CHIPLET_ID) &&    // 0x0C
                         (l_scom.getChipletId() <= MC3_CHIPLET_ID) )     // 0x0F
                    {
                        o_chipletId = (i_chipUnitNum / 4) + MC0_CHIPLET_ID;
                    }
                    else // input address is of PAU chiplets
                    {
                        // PAU0 --> OMI 0/1/2/3
                        // PAU1 --> OMI 8/9/10/11
                        // PAU2 --> OMI 4/5/6/7
                        // PAU3 --> OMI 12/13/14/15
                        if (i_chipUnitNum >= 0 && i_chipUnitNum <= 3)
                        {
                            o_chipletId = PAU0_CHIPLET_ID;
                        }
                        else if (i_chipUnitNum >= 4 && i_chipUnitNum <= 7)
                        {
                            o_chipletId = PAU2_CHIPLET_ID;
                        }
                        else if (i_chipUnitNum >= 8 && i_chipUnitNum <= 11)
                        {
                            o_chipletId = PAU1_CHIPLET_ID;
                        }
                        else if (i_chipUnitNum >= 12 && i_chipUnitNum <= 15)
                        {
                            o_chipletId = PAU3_CHIPLET_ID;
                        }
                        else
                        {
                            l_rc = 1;
                        }
                    }

                    break;

                case PU_PPE_CHIPUNIT:

                    // Look for i_chipUnitNum in table
                    for (uint8_t l_index = 0;
                         l_index < sizeof(PpeTargetInfoTable) / sizeof(PpeTargetInfo_t);
                         l_index++)
                    {
                        if (i_chipUnitNum == PpeTargetInfoTable[l_index].targetInstance)
                        {
                            o_chipletId = PpeTargetInfoTable[l_index].chipletId;
                            break;
                        }
                    }

                    break;

                case PU_PAU_CHIPUNIT:
                    o_chipletId = (i_chipUnitNum / 2) + PAU0_CHIPLET_ID;
                    break;

                default:
                    l_rc = 1;
                    break;
            };

        }
        while (0);

        return (l_rc);
    }

    // See header file for function description
    uint64_t p10_scominfo_createChipUnitScomAddr(
        const p10ChipUnits_t i_p10CU,
        const uint8_t i_ecLevel,
        const uint8_t i_chipUnitNum,
        const uint64_t i_scomAddr,
        const uint32_t i_mode)
    {
        uint8_t l_rc = 0;
        p10_scom_addr l_scom(i_scomAddr);
        uint8_t l_index = 0;
        uint8_t l_chipletId = 0;

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

            // Set the chiplet ID
            l_rc = getChipletId(i_scomAddr, i_chipUnitNum, i_p10CU, l_chipletId);

            if (l_rc)
            {
                break;
            }

            l_scom.setChipletId(l_chipletId);

            // Set other address fields (ringId, satId, etc...)
            // for Chip unit types that are needed.
            switch (i_p10CU)
            {
                case PU_C_CHIPUNIT:
                    // Set the core's region select (core ID)
                    l_scom.setRegionSelect(calcRegionSelect(i_chipUnitNum));
                    break;

                case PU_PHB_CHIPUNIT:

                    // Set ringId
                    if ( i_chipUnitNum < 3 ) // PHB 0-2
                    {
                        l_scom.setRingId(i_chipUnitNum + 3);
                    }
                    else  // PHB 3-5
                    {
                        l_scom.setRingId(i_chipUnitNum);
                    }

                    break;

                case PU_MCC_CHIPUNIT:

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
                            l_scom.setEndpoint(PpeTargetInfoTable[l_index].endpointId);
                            l_scom.setRingId(PpeTargetInfoTable[l_index].ringId);
                            l_scom.setSatId(PpeTargetInfoTable[l_index].satId);
                        }
                    }

                    break;

                case PU_PAU_CHIPUNIT:

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
                    break;
            }

            // Break out if error
            if (l_rc)
            {
                break;
            }

            // Translate upper 32-bit of indirect scom address
            if ( (l_chipletId >= PAU0_CHIPLET_ID) &&
                 (l_chipletId <= PAU3_CHIPLET_ID) &&
                 l_scom.isIndirect() )
            {
                l_rc = xlateIoUpperAddr(i_p10CU, i_ecLevel, i_chipUnitNum, l_scom, i_mode);

                if (l_rc)
                {
                    break;
                }
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
        o_chipUnitPairing.clear();

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

        // PERV registers
        if (l_scom.isPervTarget())
        {
            // if running in engineering data build flow context, do not
            // emit associations for registers which would have only
            // a single association of type PERV
            if (!((o_chipUnitPairing.size() == 0) &&
                  (i_mode == P10_ENGD_BUILD_MODE)))
            {
                o_chipUnitRelated = true;
                // PU_PERV_CHIPUNIT
                o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_PERV_CHIPUNIT,
                                            l_scom.getPervTargetInstance()));
            }
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
