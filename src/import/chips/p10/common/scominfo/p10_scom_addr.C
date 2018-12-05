/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/scominfo/p10_scom_addr.C $        */
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
/// @file p10_scom_addr.C
/// @brief P10 chip unit SCOM address platform translation code
///
/// HWP Owner: thi@us.ibm.com
/// HWP Team: NEST
/// HWP Level: 1
/// HWP Consumed by: FSP/HB
///

// includes
#include "p10_scom_addr.H"

#define P10_SCOM_ADDR_C

//@thi-TODO: Need to revisit the following items once design is finalized:
//           PPE, IOHS, PAU, MI, MCC, OMI, OMIC

extern "C"
{
    /// See function description in header file

    // #####################################
    bool p10_scom_addr::isEqTarget()
    {
        bool l_eqTarget = false;

        // Must have region select = 0 and EQ chiplet ID
        if ( (getRegionSelect() == EQ_REGION_SEL) &&
             (getChipletId() >= EQ0_CHIPLET_ID) &&
             (getChipletId() <= EQ7_CHIPLET_ID) )
        {
            // If endpoint is QME (0xE), QME per core (bit 20) must be 0
            if ( (getEndpoint() == QME_ENDPOINT) && (!getQMEPerCore()) )
            {
                l_eqTarget = true;
            }
            // Other endpoints for EQ
            else if ( (getEndpoint() == CHIPLET_CTRL_ENDPOINT) ||  // 0x0
                      (getEndpoint() == CLOCK_CTRL_ENDPOINT)   ||  // 0x3
                      (getEndpoint() == FIR_ENDPOINT)          ||  // 0x4
                      (getEndpoint() == THERMAL_ENDPOINT)      ||  // 0x5
                      (getEndpoint() == PCBSLV_ENDPOINT) )         // 0xF
            {
                l_eqTarget = true;
            }
        }

        return l_eqTarget;
    }

    // ########################################
    uint8_t p10_scom_addr::getEqTargetInstance()
    {
        uint8_t l_instance = 0;
        l_instance = (getChipletId() - EQ0_CHIPLET_ID);
        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isCoreTarget()
    {
        bool l_coreTarget = false;

        // Must have EQ chiplet ID
        if ( (getChipletId() >= EQ0_CHIPLET_ID) &&
             (getChipletId() <= EQ7_CHIPLET_ID) )
        {
            // Region select must be...
            if ( (getRegionSelect() == MULTI_HOT_SELECT_C0) ||  // 0x8
                 (getRegionSelect() == MULTI_HOT_SELECT_C1) ||  // 0x4
                 (getRegionSelect() == MULTI_HOT_SELECT_C2) ||  // 0x2
                 (getRegionSelect() == MULTI_HOT_SELECT_C3) ||  // 0x1
                 (getRegionSelect() == EQ_REGION_SEL) )         // 0x0
            {
                // If QME endpoint (0xE), QME per core (bit 20) must be 1
                if ( (getEndpoint() == QME_ENDPOINT) && getQMEPerCore() )
                {
                    l_coreTarget = true;
                }
                // or must be PSCOM endpoints
                else if ( (getEndpoint() == PSCOM_ENDPOINT) ||    // 0x1
                          (getEndpoint() == PSCOM_2_ENDPOINT) )   // 0x2
                {
                    l_coreTarget = true;
                }
            }
        }

        return l_coreTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getCoreTargetInstance()
    {
        uint8_t l_instance = 0;

        // First core instance of the quad
        l_instance = (getChipletId() - EQ0_CHIPLET_ID) * NUM_CORES_PER_EQ;

        // Get core instance based on region select
        if (getRegionSelect() == MULTI_HOT_SELECT_C3)
        {
            l_instance += 3;
        }
        else if (getRegionSelect() == MULTI_HOT_SELECT_C2)
        {
            l_instance += 2;
        }
        else if (getRegionSelect() == MULTI_HOT_SELECT_C1)
        {
            l_instance += 1;
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isPecTarget()
    {
        bool l_pecTarget = false;

        // Endpoint must be PSCOM (0x1) and Sat ID must be 0
        if ( (getEndpoint() == PSCOM_ENDPOINT) &&  // 0x1
             (getSatId() == PCI_SAT_ID) )          // 0
        {
            // For PEC addresses via NEST regions, ring ID must be 0x6
            if ( (getChipletId() >= N0_CHIPLET_ID) &&  // 0x2
                 (getChipletId() <= N1_CHIPLET_ID) &&  // 0x3
                 (getRingId() == N0_PE0_RING_ID) )     // 0x6
            {
                l_pecTarget = true;
            }

            // For PEC addresses via PCIE, ring ID must be 0x2
            else if ( (getChipletId() >= PCI0_CHIPLET_ID) &&  // 0x8
                      (getChipletId() <= PCI1_CHIPLET_ID) &&  // 0x9
                      (getRingId() == PCI_RING_ID) )          // 0x2
            {
                l_pecTarget = true;
            }
        }

        return l_pecTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getPecTargetInstance()
    {
        uint8_t l_instance = 0;

        // PEC addresses via NEST regions
        l_instance = getChipletId() - N0_CHIPLET_ID;

        // PEC addresses via PCIE
        if ( (getChipletId() == PCI0_CHIPLET_ID) ||
             (getChipletId() == PCI1_CHIPLET_ID) )
        {
            l_instance = getChipletId() - PCI0_CHIPLET_ID;
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isPhbTarget()
    {
        bool l_phbTarget = false;

        // Must have PCIE chiplet ID
        if ( (getChipletId() >= PCI0_CHIPLET_ID) && // 0x8
             (getChipletId() <= PCI1_CHIPLET_ID) )  // 0x9
        {
            // Endpoint must be PSCOM (0x1) and Sat ID must be 0
            if ( (getEndpoint() == PSCOM_ENDPOINT) &&  // 0x1
                 (getSatId() == PCI_SAT_ID) )          // 0
            {
                // Ring ID must be 0x3, 0x4, or 0x5
                if ( (getRingId() >= IO_PCI0_RING_ID) &&  // 0x3
                     (getRingId() <= IO_PCI2_RING_ID) )   // 0x5
                {
                    l_phbTarget = true;
                }
            }
        }

        return l_phbTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getPhbTargetInstance()
    {
        uint8_t l_instance = 0;

        // PCI0, instance 0-2
        if (getChipletId() == PCI0_CHIPLET_ID)
        {
            l_instance = (getRingId() - IO_PCI0_RING_ID);
        }
        // PCI1, instance 3-5
        else
        {
            l_instance = getRingId();
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isNmmuTarget()
    {
        bool l_nmmuTarget = false;

        // Must have NEST chiplet ID
        if ( (getChipletId() == N0_CHIPLET_ID) ||
             (getChipletId() == N1_CHIPLET_ID) )
        {
            // Endpoint must be PSCOM, ring ID must be 0x3, Sat ID must be 0
            if ( (getEndpoint() == PSCOM_ENDPOINT) &&    // 0x1
                 (getRingId() == N0_MM0_RING_ID)  &&    // 0x3
                 (getSatId() == NMMU_SAT_ID) )           // 0x0
            {
                l_nmmuTarget = true;
            }
        }

        return l_nmmuTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getNmmuTargetInstance()
    {
        return (getChipletId() - N0_CHIPLET_ID);
    }

    // #####################################
    bool p10_scom_addr::isPervTarget()
    {
        bool l_pervTarget = false;
        uint8_t l_index = 0;

        // Check chiplet ID by looping through PERV chiplet ID table
        for (l_index = 0;
             l_index < sizeof(PervTargetChipletIdTable) / sizeof(p10ChipletId_t);
             l_index++)
        {
            // See if Chiplet ID is a perv chiplet ID from table
            if (getChipletId() == PervTargetChipletIdTable[l_index])
            {
                // If Endpoint is PSCOM_ENDPOINT, ring ID must be 0 or 1
                if (getEndpoint() == PSCOM_ENDPOINT)        // 0x1
                {
                    if ( (getRingId() == PSCOM_RING_ID) ||  // 0x0
                         (getRingId() == PERV_RING_ID) )    // 0x1
                    {
                        l_pervTarget = true;
                    }
                }

                // Check if Endpoint is a PERV endpoint
                else if ( (getEndpoint() == CHIPLET_CTRL_ENDPOINT) ||     // 0x0
                          (getEndpoint() == CLOCK_CTRL_ENDPOINT)   ||     // 0x3
                          (getEndpoint() == FIR_ENDPOINT)          ||     // 0x4
                          (getEndpoint() == THERMAL_ENDPOINT)      ||     // 0x5
                          (getEndpoint() == PCBSLV_ENDPOINT) )            // 0xF
                {
                    l_pervTarget = true;
                }

                break;
            }
        }

        return l_pervTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getPervTargetInstance()
    {
        return getChipletId();
    }

    // #####################################
    bool p10_scom_addr::isIoHsTarget()
    {
        bool l_iohsTarget = false;

        // Endpoint must be PSCOM
        if ( getEndpoint() == PSCOM_ENDPOINT)
        {
            // If chiplet ID is of AXON chiplets, then RingId must be 1-5
            if ( (getChipletId() >= AXON0_CHIPLET_ID) &&      // 0x18
                 (getChipletId() <= AXON7_CHIPLET_ID) )       // 0x1F
            {
                if ( (getRingId() >= AXONE_PERV_RING_ID) &&   // 0x1
                     (getRingId() <= AXONE_PDL_RING_ID) )     // 0x5
                {
                    l_iohsTarget = true;
                }
            }
            // else if chiplet ID is of PAU chiplets, then RingId must be 10 or 12
            else if ( (getChipletId() >= PAU0_CHIPLET_ID) &&      // 0x10
                      (getChipletId() <= PAU3_CHIPLET_ID) )       // 0x13
            {
                if ( (getRingId() == PAU_TL_RING_ID) ||   // 0xA
                     (getRingId() == PAU_DLP_RING_ID) )   // 0xC
                {
                    l_iohsTarget = true;
                }
            }
        }

        return l_iohsTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getIoHsTargetInstance()
    {
        uint8_t l_instance = 0;

        // Assume chiplet ID is of AXON
        l_instance = getChipletId() - AXON0_CHIPLET_ID;

        // If chiplet ID is of PAU then get instance for PAU
        if ( (getChipletId() >= PAU0_CHIPLET_ID) &&      // 0x10
             (getChipletId() <= PAU3_CHIPLET_ID) )       // 0x13
        {
            //@thi-TODO: Need to update this to distinguish between
            // instance 0 and 1, 2 and 3, etc...  Need more info.
            l_instance = ( (getChipletId() - PAU0_CHIPLET_ID) * 2) + 1;
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isPauTarget()
    {
        bool l_pauTarget = false;

        // Endpoint must be PSCOM
        if ( getEndpoint() == PSCOM_ENDPOINT)
        {
            // Check chiplet ID
            if ( (getChipletId() >= PAU0_CHIPLET_ID) &&
                 (getChipletId() <= PAU3_CHIPLET_ID) )
            {
                if ( (getRingId() == PAU0346_0_RING_ID) || // 0x02
                     (getRingId() == PAU0346_1_RING_ID) || // 0x03
                     (getRingId() == PBPAU0346_0_RING_ID) || // 0x06
                     (getRingId() == PBPAU0346_1_RING_ID) )  // 0x07

                {
                    l_pauTarget = true;
                }
                else if ( (getChipletId() == PAU2_CHIPLET_ID) ||
                          (getChipletId() == PAU3_CHIPLET_ID) )
                {
                    if ( (getRingId() == PAU57_0_RING_ID)   || // 0x04
                         (getRingId() == PAU57_1_RING_ID)   || // 0x05
                         (getRingId() == PBPAU57_0_RING_ID) || // 0x08
                         (getRingId() == PBPAU57_1_RING_ID) )  // 0x09
                    {
                        l_pauTarget = true;
                    }
                }
            }
        }

        return l_pauTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getPauTargetInstance()
    {
        uint8_t l_instance = 0;

        if ( (getRingId() == PAU0346_0_RING_ID) || // 0x02
             (getRingId() == PAU0346_1_RING_ID) || // 0x03
             (getRingId() == PBPAU0346_0_RING_ID) || // 0x06
             (getRingId() == PBPAU0346_1_RING_ID) )  // 0x07
        {
            if (getChipletId() == PAU0_CHIPLET_ID)
            {
                l_instance = 0;
            }
            else if (getChipletId() == PAU1_CHIPLET_ID)
            {
                l_instance = 3;
            }
            else if (getChipletId() == PAU2_CHIPLET_ID)
            {
                l_instance = 4;
            }
            else if (getChipletId() == PAU3_CHIPLET_ID)
            {
                l_instance = 6;
            }
        }

        else if ( (getRingId() == PAU57_0_RING_ID)   || // 0x04
                  (getRingId() == PAU57_1_RING_ID)   || // 0x05
                  (getRingId() == PBPAU57_0_RING_ID) || // 0x08
                  (getRingId() == PBPAU57_1_RING_ID) )  // 0x09
        {
            if (getChipletId() == PAU2_CHIPLET_ID)
            {
                l_instance = 5;
            }
            else if (getChipletId() == PAU3_CHIPLET_ID)
            {
                l_instance = 7;
            }
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isMcTarget()
    {
        // Same as MI
        return isMiTarget();
    }

    // #####################################
    uint8_t p10_scom_addr::getMcTargetInstance()
    {
        // Same as MI
        return getMiTargetInstance();
    }

    // #####################################
    bool p10_scom_addr::isMiTarget()
    {
        bool l_miTarget = false;

        // Chiplet ID must belong to MCs, Endpoint = PSCOM_ENDPOINT,
        // and ringID = MC_RING_ID
        if ( (getChipletId() >= MC0_CHIPLET_ID) &&    // 0x0C
             (getChipletId() <= MC3_CHIPLET_ID) &&    // 0x0F
             (getEndpoint() == PSCOM_ENDPOINT) &&     // 0x1
             (getRingId() == MC_RING_ID) )            // 0x2
        {
            // Must have MI Sat ID
            if ( (getSatId() == MC_SAT_ID0) ||  // 0x0
                 (getSatId() == MC_SAT_ID12) )  // 0xC
            {
                l_miTarget = true;
            }
        }

        return l_miTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getMiTargetInstance()
    {
        return getChipletId() - MC0_CHIPLET_ID;
    }

    // #####################################
    bool p10_scom_addr::isMccTarget()
    {
        bool l_mccTarget = false;

        // Chiplet ID must belong to MCs, Endpoint = PSCOM_ENDPOINT,
        // and ringID = MC_RING_ID
        if ( (getChipletId() >= MC0_CHIPLET_ID) &&    // 0x0C
             (getChipletId() <= MC3_CHIPLET_ID) &&    // 0x0F
             (getEndpoint() == PSCOM_ENDPOINT) &&     // 0x1
             (getRingId() == MC_RING_ID) )            // 0x2
        {
            // Must have MCC Sat ID
            if ( (getSatId() == MC_SAT_ID4) ||  // 0x4
                 (getSatId() == MC_SAT_ID8) ||  // 0x8
                 (getSatId() == MC_SAT_ID5) ||  // 0x5
                 (getSatId() == MC_SAT_ID9) )   // 0x9
            {
                l_mccTarget = true;
            }
        }

        return l_mccTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getMccTargetInstance()
    {
        uint8_t l_instance = (getChipletId() - MC0_CHIPLET_ID) * 2;

        if ( (getSatId() == MC_SAT_ID5) ||  // 5
             (getSatId() == MC_SAT_ID9) )   // 9
        {
            l_instance += 1;
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isOmiTarget()
    {
        bool l_omiTarget = false;

        // Chiplet ID must belong to MCs, Endpoint = PSCOM_ENDPOINT,
        // and ringID = one of MC controller ring IDs
        if ( (getChipletId() >= MC0_CHIPLET_ID) &&    // 0x0C
             (getChipletId() <= MC3_CHIPLET_ID) &&    // 0x0F
             (getEndpoint() == PSCOM_ENDPOINT) )      // 0x1
        {
            // Check RingId
            if ( (getRingId() == OMI0_RING_ID) ||  // 0x3
                 (getRingId() == IOO0_RING_ID) ||  // 0x5
                 (getRingId() == OMI1_RING_ID) ||  // 0x4
                 (getRingId() == IOO1_RING_ID) )   // 0x6
            {
                l_omiTarget = true;
            }
        }

        return l_omiTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getOmiTargetInstance()
    {
        // Instances 0, 4, 8, 12
        uint8_t l_instance = (getChipletId() - MC0_CHIPLET_ID) * 4;

        // Instances 2, 6, 10, 14
        if ( (getRingId() == OMI1_RING_ID) ||  // 0x4
             (getRingId() == IOO1_RING_ID) )   // 0x6
        {
            l_instance += 2;
        }

        // Instances 1, 3, 5, 7, 9, 11, 13, 15
        if (getSatId() == 1)
        {
            l_instance += 1;
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isOmicTarget()
    {
        bool l_omicTarget = false;

        // Chiplet ID must belong to MCs, Endpoint = PSCOM_ENDPOINT,
        // and ringID = one of MC controller ring IDs
        if ( (getChipletId() >= MC0_CHIPLET_ID) &&    // 0x0C
             (getChipletId() <= MC3_CHIPLET_ID) &&    // 0x0F
             (getEndpoint() == PSCOM_ENDPOINT) )      // 0x1
        {
            // Check RingId
            if ( (getRingId() == OMI0_RING_ID) ||  // 0x3
                 (getRingId() == IOO0_RING_ID) ||  // 0x5
                 (getRingId() == OMI1_RING_ID) ||  // 0x4
                 (getRingId() == IOO1_RING_ID) )   // 0x6
            {
                l_omicTarget = true;
            }
        }

        return l_omicTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getOmicTargetInstance()
    {
        uint8_t l_instance = (getChipletId() - MC0_CHIPLET_ID) * 2;

        if ( (getRingId() == OMI1_RING_ID) ||  // 0x4
             (getRingId() == IOO1_RING_ID) )   // 0x6
        {
            l_instance += 1;
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isPpeTarget()
    {
        bool l_ppeTarget = false;
        uint8_t l_index = 0;

        // Check against all entries in PPE target info table
        for (l_index = 0;
             l_index < sizeof(PpeTargetInfoTable) / sizeof(PpeTargetInfo_t);
             l_index++)
        {
            // Check for matches of chipletId, Endpoint, RingId, and SatId
            if ( (getChipletId() == PpeTargetInfoTable[l_index].chipletId) &&
                 (getEndpoint() == PpeTargetInfoTable[l_index].endpointId) &&
                 (getRingId() == PpeTargetInfoTable[l_index].ringId) &&
                 (getSatId() == PpeTargetInfoTable[l_index].satId) )
            {
                l_ppeTarget = true;
                break;
            }
        }

        return l_ppeTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getPpeTargetInstance()
    {
        uint8_t l_instance = 0xFF;
        uint8_t l_index = 0;

        // Check against all entries in PPE target info table
        for (l_index = 0;
             l_index < sizeof(PpeTargetInfoTable) / sizeof(PpeTargetInfo_t);
             l_index++)
        {
            // Check for matches of chipletId, Endpoint, and RingId
            if ( (getChipletId() == PpeTargetInfoTable[l_index].chipletId) &&
                 (getEndpoint() == PpeTargetInfoTable[l_index].endpointId) &&
                 (getRingId() == PpeTargetInfoTable[l_index].ringId) )
            {
                // Check for matches of Sat ID (or Sat ID = don't care)
                if ( (getSatId() == PpeTargetInfoTable[l_index].satId) ||
                     (PpeTargetInfoTable[l_index].satId == 0xFF) )
                {
                    l_instance = PpeTargetInfoTable[l_index].targetInstance;
                    break;
                }
            }
        }

        return l_instance;
    }

} // extern "C"

#undef P10_SCOM_ADDR_C
