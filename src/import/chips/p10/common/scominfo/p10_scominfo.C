/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/scominfo/p10_scominfo.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
                        o_chipletId = ((i_chipUnitNum) ? (N0_CHIPLET_ID) : (N1_CHIPLET_ID));
                    }
                    // If input address is of PCI chiplets
                    else
                    {
                        o_chipletId = PCI0_CHIPLET_ID + i_chipUnitNum;
                    }

                    break;

                case PU_PHB_CHIPUNIT:

                    // If input address is of Nest chiplets
                    if ( (l_scom.getChipletId() >= N0_CHIPLET_ID) &&
                         (l_scom.getChipletId() <= N1_CHIPLET_ID) )
                    {
                        o_chipletId = ((i_chipUnitNum / 3) ? (N0_CHIPLET_ID) : (N1_CHIPLET_ID));
                    }
                    // If input address is of PCI chiplets
                    else
                    {
                        o_chipletId = (i_chipUnitNum / 3) + PCI0_CHIPLET_ID;
                    }

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
                        // PAU1 --> IOHS3, IOHS2
                        // PAU2 --> IOHS5, IOHS4
                        // PAU3 --> IOHS7, IOHS6
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
                    o_chipletId = (i_chipUnitNum / 2) + MC0_CHIPLET_ID;
                    break;

                case PU_OMIC_CHIPUNIT:

                    // PAU indirect
                    if ( (l_scom.getChipletId() >= PAU0_CHIPLET_ID) &&   // 0x10
                         (l_scom.getChipletId() <= PAU3_CHIPLET_ID) )    // 0x13
                    {
                        // PAU0 --> OMIC 0/1
                        // PAU1 --> OMIC 4/5
                        // PAU2 --> OMIC 2/3
                        // PAU3 --> OMIC 6/7
                        if (i_chipUnitNum >= 0 && i_chipUnitNum <= 1)
                        {
                            o_chipletId = PAU0_CHIPLET_ID;
                        }
                        else if (i_chipUnitNum >= 2 && i_chipUnitNum <= 3)
                        {
                            o_chipletId = PAU2_CHIPLET_ID;
                        }
                        else if (i_chipUnitNum >= 4 && i_chipUnitNum <= 5)
                        {
                            o_chipletId = PAU1_CHIPLET_ID;
                        }
                        else if (i_chipUnitNum >= 6 && i_chipUnitNum <= 7)
                        {
                            o_chipletId = PAU3_CHIPLET_ID;
                        }
                        else
                        {
                            l_rc = 1;
                        }
                    }
                    // MC direct
                    else
                    {
                        o_chipletId = (i_chipUnitNum / 2) + MC0_CHIPLET_ID;
                    }

                    break;

                case PU_OMI_CHIPUNIT:

                    // PAU indirect
                    if ( (l_scom.getChipletId() >= PAU0_CHIPLET_ID) &&   // 0x10
                         (l_scom.getChipletId() <= PAU3_CHIPLET_ID) )    // 0x13
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
                    // MC direct
                    else
                    {
                        o_chipletId = (i_chipUnitNum / 4) + MC0_CHIPLET_ID;
                    }

                    break;

                case PU_PAUC_CHIPUNIT:
                    o_chipletId = i_chipUnitNum + PAU0_CHIPLET_ID;
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
        uint8_t l_chipletId = 0;

        do
        {
            // Make sure i_chipUnitNum is within range
            l_rc = validateChipUnitNum(i_chipUnitNum, i_p10CU);

            if (l_rc)
            {
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

                    // If input address is of Nest chiplets
                    if ( (l_scom.getChipletId() >= N0_CHIPLET_ID) &&
                         (l_scom.getChipletId() <= N1_CHIPLET_ID) )
                    {
                        l_scom.setSatId(1 + (i_chipUnitNum % 3));
                    }
                    // If input address is of PCI chiplets
                    else
                    {
                        if (l_scom.getRingId() == 2)
                        {
                            if ((l_scom.getSatId() >= 1) &&
                                (l_scom.getSatId() <= 3))
                            {
                                l_scom.setSatId(1 + (i_chipUnitNum % 3));
                            }
                            else
                            {
                                l_scom.setSatId(4 + (i_chipUnitNum % 3));
                            }
                        }
                    }

                    break;

                case PU_MCC_CHIPUNIT:

                    // Set Sat ID
                    if (i_chipUnitNum % 2)
                    {
                        uint8_t l_offset = l_scom.getSatOffset();

                        // MCC Sat ID
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
                        // PBI Sat ID
                        else if (l_scom.getSatId() == 0x0)
                        {
                            if ((l_offset >= 0x22) &&
                                (l_offset <= 0x2B))
                            {
                                l_scom.setSatOffset(l_offset + 0x10);
                            }
                        }
                        // MCBIST Sat ID
                        else if (l_scom.getSatId() == 0xD)
                        {
                            if ((l_offset >= 0x00) &&
                                (l_offset <= 0x1F))
                            {
                                l_scom.setSatOffset(l_offset + 0x20);
                            }
                        }
                    }
                    else
                    {
                        uint8_t l_offset = l_scom.getSatOffset();

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
                        // PBI Sat ID
                        else if (l_scom.getSatId() == 0x0)
                        {
                            if ((l_offset >= 0x32) &&
                                (l_offset <= 0x3B))
                            {
                                l_scom.setSatOffset(l_offset - 0x10);
                            }
                        }
                        // MCBIST Sat ID
                        else if (l_scom.getSatId() == 0xD)
                        {
                            if ((l_offset >= 0x20) &&
                                (l_offset <= 0x3F))
                            {
                                l_scom.setSatOffset(l_offset - 0x20);
                            }
                        }
                    }

                    break;


                case PU_IOHS_CHIPUNIT:

                    // PAU indirect
                    if ( (l_scom.getChipletId() >= PAU0_CHIPLET_ID) &&   // 0x10
                         (l_scom.getChipletId() <= PAU3_CHIPLET_ID) )    // 0x13
                    {
                        //AX0/1 logic is flipped for PAUC1..3
                        //Note, IOHS chiplets are ok, connections to AX0/1 are
                        //flipped for ioo1..ioo3 in e10_chip.vhdl
                        if (i_chipUnitNum < 2)
                        {
                            // for odd IOHS instances, set IO group = 1
                            if ( i_chipUnitNum % 2 )
                            {
                                l_scom.setIoGroupAddr(0x1);
                            }
                            // for even IOHS instances, set IO group = 0
                            else
                            {
                                l_scom.setIoGroupAddr(0x0);
                            }
                        }
                        else
                        {
                            // for even IOHS instances, set IO group = 1
                            if ( i_chipUnitNum % 2 == 0 )
                            {
                                l_scom.setIoGroupAddr(0x1);
                            }
                            // for odd IOHS instances, set IO group = 1
                            else
                            {
                                l_scom.setIoGroupAddr(0x0);
                            }
                        }
                    }

                    break;

                case PU_OMI_CHIPUNIT:

                    // PAU indirect
                    if ( (l_scom.getChipletId() >= PAU0_CHIPLET_ID) &&   // 0x10
                         (l_scom.getChipletId() <= PAU3_CHIPLET_ID) )    // 0x13
                    {
                        // for odd OMI instances, set IO lane between 8-15
                        if ( i_chipUnitNum % 2 )
                        {
                            l_scom.setIoLane(8 + (l_scom.getIoLane() % 8));
                        }
                        // for even OMI instances, set IO lane between 0-7
                        else
                        {
                            l_scom.setIoLane(0 + (l_scom.getIoLane() % 8));
                        }

                        // for odd OMI instances after dividing by 2, set IO group = 3
                        if ( (i_chipUnitNum / 2) % 2 )
                        {
                            l_scom.setIoGroupAddr(0x3);
                        }
                        // for even OMI instances after dividing by 2, set IO group = 2
                        else
                        {
                            l_scom.setIoGroupAddr(0x2);
                        }
                    }
                    // MC direct
                    else
                    {
                        // non-PM regs
                        if ((l_scom.getSatOffset() >= 16) && (l_scom.getSatOffset() <= 47))
                        {
                            // for odd OMI instances, set sat reg ID between 32-47
                            if ( i_chipUnitNum % 2 )
                            {
                                l_scom.setSatOffset(32 + (l_scom.getSatOffset() % 16));
                            }
                            // for even OMI instances, set sat reg ID between 16-31
                            else
                            {
                                l_scom.setSatOffset(16 + (l_scom.getSatOffset() % 16));
                            }
                        }
                        // PM regs
                        else
                        {
                            // for odd OMI instances, set sat reg ID between 56-59
                            if ( i_chipUnitNum % 2 )
                            {
                                l_scom.setSatOffset(56 + (l_scom.getSatOffset() % 4));
                            }
                            // for even OMI instances, set sat reg ID between 48-51
                            else
                            {
                                l_scom.setSatOffset(48 + (l_scom.getSatOffset() % 4));
                            }

                        }

                        // for odd OMI instances after dividing by 2, set ring ID = 6
                        if ( (i_chipUnitNum / 2) % 2 )
                        {
                            l_scom.setRingId(0x6);
                        }
                        // for even OMI instances after dividing by 2, set ring ID = 5
                        else
                        {
                            l_scom.setRingId(0x5);
                        }
                    }

                    break;

                case PU_OMIC_CHIPUNIT:

                    // PAU indirect
                    if ( (l_scom.getChipletId() >= PAU0_CHIPLET_ID) &&   // 0x10
                         (l_scom.getChipletId() <= PAU3_CHIPLET_ID) )    // 0x13
                    {
                        if (i_chipUnitNum % 2)
                        {
                            // For odd OMIC instance, set IO group ID=3
                            l_scom.setIoGroupAddr(0x3);
                        }
                        else
                        {
                            // For even OMIC instance, set IO group ID=2
                            l_scom.setIoGroupAddr(0x2);
                        }
                    }
                    // MC direct
                    else
                    {
                        if (i_chipUnitNum % 2)
                        {
                            // For odd OMIC instance, set ring ID=6
                            l_scom.setRingId(0x6);
                        }
                        else
                        {
                            // For even OMIC instance, set ring ID=5
                            l_scom.setRingId(0x5);
                        }
                    }

                    break;

                case PU_PAU_CHIPUNIT:

                    // Setting RingId for instances 0, 3, 4, and 6
                    // If input address has:
                    //   RingId = 0x4 --> set translated RingId to 0x2
                    //            0x5 --> set translated RingId to 0x3
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
                    }

                    // Setting RingId for instances 1, 2, 5, and 7
                    // If input address has:
                    //   RingId = 0x2 --> set translated RingId to 0x4
                    //            0x3 --> set translated RingId to 0x5
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

        }
        while(0);

        if (l_rc)
        {
            l_scom.setAddr(FAILED_TRANSLATION);
        }

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
            // prevent matching on CLKADJ SCOMs in ENGD build mode
            if (!((l_scom.getEndpoint() == PSCOM_ENDPOINT) &&
                  (l_scom.getEQRingId() == PERV_RING_ID) &&
                  (l_scom.getEQSatId()  == CLKADJ_SAT_ID) &&
                  (i_mode == P10_ENGD_BUILD_MODE)))
            {
                o_chipUnitRelated = true;
                // PU_C_CHIPUNIT
                o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_C_CHIPUNIT,
                                            l_scom.getCoreTargetInstance()));
            }
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
        if (l_scom.isNmmuTarget() &&
            // prevent matching on NMMU SCOMs in ENGD build mode
            (i_mode != P10_ENGD_BUILD_MODE))
        {
            o_chipUnitRelated = true;
            // PU_NMMU_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_NMMU_CHIPUNIT,
                                        l_scom.getNmmuTargetInstance()));
        }

        // IOHS registers
        if (l_scom.isIoHsTarget() &&
            // prevent matching on IOHS SCOMs in ENGD build mode
            (i_mode != P10_ENGD_BUILD_MODE))
        {
            o_chipUnitRelated = true;
            // PU_IOHS_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_IOHS_CHIPUNIT,
                                        l_scom.getIoHsTargetInstance()));
        }

        // PAU registers
        if (l_scom.isPauTarget() &&
            // prevent matching on PAU SCOMs in ENGD build mode
            (i_mode != P10_ENGD_BUILD_MODE))
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

        // PAUC registers
        if (l_scom.isPaucTarget() &&
            // prevent matching on indirect SCOMs (physically targeting IOHS
            // scan latches) in ENGD build mode
            ((i_mode != P10_ENGD_BUILD_MODE) ||
             (l_scom.isDirect())))
        {
            o_chipUnitRelated = true;
            // PU_PAUC_CHIPUNIT
            o_chipUnitPairing.push_back(p10_chipUnitPairing_t(PU_PAUC_CHIPUNIT,
                                        l_scom.getPaucTargetInstance()));
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

    //################################################################################
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
                    // Note: We allow content in chiplet ID = 0x00 to be referenced with a perv target instance,
                    //       so do not check for instance = 0 here.
                    if ( ((i_chipUnitNum > 3) && (i_chipUnitNum < 8)) ||
                         ((i_chipUnitNum > 9) && (i_chipUnitNum < 12)) ||
                         ((i_chipUnitNum > 19) && (i_chipUnitNum < 24)) )
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

} // extern "C"

#undef P10_SCOMINFO_C
