/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/scominfo/p10_scom_addr.C $        */
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
/// @file p10_scom_addr.C
/// @brief P10 chip unit SCOM address platform translation code
///
/// HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// HWP FW Maintainer:
/// HWP Consumed by: Cronus, HB, HWSV
///

// includes
#include "p10_scom_addr.H"

#define P10_SCOM_ADDR_C

extern "C"
{
    /// See function description in header file

    // #####################################
    bool p10_scom_addr::isEqTarget()
    {
        bool l_eqTarget = false;

        // Must have EQ chiplet ID
        if ( (getChipletId() >= EQ0_CHIPLET_ID) &&
             (getChipletId() <= EQ7_CHIPLET_ID) )
        {
            // If endpoint is QME (0xE):
            // QME per core (bit 20) must be 0
            // region select (bits 16:19) must be 0
            if ( (getEndpoint() == QME_ENDPOINT) && (!getQMEPerCore()) &&
                 (getRegionSelect() == EQ_REGION_SEL) )
            {
                l_eqTarget = true;
            }
            // associate perv target resources with EQ
            else if (isPervTarget())
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
                // or must be PSCOM endpoints -- ensure that ring ID is
                // associated with a core resource on the first PSCOM
                // endpoint (0x1), all are core rings on the second
                // PSCOM endpoint (0x2)
                else if ( ((getEndpoint() == PSCOM_ENDPOINT) &&   // 0x1
                           ((getEQRingId() != PERV_RING_ID ||     // 0x1
                             getEQSatId() == CLKADJ_SAT_ID) &&    // 0x4
                            (getEQRingId() != QME_RING_ID))) ||   // 0x2
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

        // associate perv target resources with PCIE
        if ( (getChipletId() >= PCI0_CHIPLET_ID) &&      // 0x8
             (getChipletId() <= PCI1_CHIPLET_ID) )       // 0x9
        {
            l_pecTarget = isPervTarget();
        }

        // Endpoint must be PSCOM (0x1)
        if (getEndpoint() == PSCOM_ENDPOINT)  // 0x1
        {
            // For PEC addresses via NEST regions:
            // Ring ID must be 0x6, sat ID must be 0
            if ( (getChipletId() >= N0_CHIPLET_ID) &&  // 0x2
                 (getChipletId() <= N1_CHIPLET_ID) &&  // 0x3
                 (getRingId() == N0_PE1_RING_ID) &&    // 0x6
                 (getSatId() == PEC_SAT_ID) )          // 0x0

            {
                l_pecTarget = true;
            }
            // For PEC addresses via PCIE:
            else if ( (getChipletId() >= PCI0_CHIPLET_ID) &&  // 0x8
                      (getChipletId() <= PCI1_CHIPLET_ID) )   // 0x9
            {
                // Ring IDs must be 0x4-0x5 (iopci rings) or
                // Ring ID is 0x2 (pci ring) and sat Id = 0x0
                if ( (getRingId() == IO_PCI0_RING_ID) ||   // 0x4
                     (getRingId() == IO_PCI1_RING_ID) ||   // 0x5
                     ((getRingId() == PCI_RING_ID) &&      // 0x2
                      (getSatId() == PEC_SAT_ID)) )        // 0x0
                {
                    l_pecTarget = true;
                }
            }
        }

        return l_pecTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getPecTargetInstance()
    {
        uint8_t l_instance = 0;

        // PEC addresses via NEST regions
        l_instance = N1_CHIPLET_ID - getChipletId();

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

        // Endpoint must be PSCOM (0x1)
        if ( (getEndpoint() == PSCOM_ENDPOINT) )  // 0x1
        {
            // PCIE chiplet ID
            if ( (getChipletId() >= PCI0_CHIPLET_ID) && // 0x8
                 (getChipletId() <= PCI1_CHIPLET_ID) )  // 0x9
            {
                // Ring ID of 0x2, Sat ID 1-6
                if ( (getRingId() == PCI_RING_ID) && // 0x2
                     (getSatId() >= PHB0_AIB_SAT_ID) &&  // 0x1
                     (getSatId() <= PHB2_PHB_SAT_ID) )   // 0x6
                {
                    l_phbTarget = true;
                }
            }

            // N0/N1 chiplet ID
            if ( (getChipletId() >= N0_CHIPLET_ID) &&  // 0x2
                 (getChipletId() <= N1_CHIPLET_ID) &&  // 0x3
                 (getRingId() == N0_PE1_RING_ID)  &&   // 0x6
                 (getSatId() >= PHB0_AIB_SAT_ID) &&    // 0x1
                 (getSatId() <= PHB2_AIB_SAT_ID) )     // 0x3
            {
                l_phbTarget = true;
            }
        }

        return l_phbTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getPhbTargetInstance()
    {
        uint8_t l_instance = 0;

        if ( (getChipletId() == N0_CHIPLET_ID) ||
             (getChipletId() == PCI1_CHIPLET_ID) )
        {
            l_instance += 3;
        }

        if ( (getRingId() == N0_PE1_RING_ID) )
        {
            l_instance += (getSatId() - 1);
        }
        else if ( (getRingId() == PCI_RING_ID ) )
        {
            l_instance += ((getSatId() - 1) % 3);
        }
        else
        {
            l_instance += (getRingId() - 3);
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
            // Endpoint must be PSCOM, ring ID must be 0x3, Sat ID must be 0/1
            if ( (getEndpoint() == PSCOM_ENDPOINT) &&    // 0x1
                 (getRingId() == N0_MM0_RING_ID)  &&     // 0x3
                 (getSatId() >= NMMU_SAT_ID0) &&         // 0x0
                 (getSatId() <= NMMU_SAT_ID1) )          // 0x1
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
                if (getEndpoint() == PSCOM_ENDPOINT)            // 0x1
                {
                    // EQ specific PSCOM endpoint logic
                    // ensure ring being accessed is EQ scoped (non-core)
                    if ( (getChipletId() >= EQ0_CHIPLET_ID) &&
                         (getChipletId() <= EQ7_CHIPLET_ID) )
                    {
                        if ( (getEQRingId() == PERV_RING_ID) || // 0x1
                             (getEQRingId() == QME_RING_ID) )   // 0x2
                        {
                            l_pervTarget = true;
                        }
                    }

                    // non-EQ chiplet, just match for ring ID = 0 / 1
                    else
                    {
                        if ( (getRingId() == PSCOM_RING_ID) ||  // 0x0
                             (getRingId() == PERV_RING_ID) )    // 0x1
                        {
                            l_pervTarget = true;
                        }
                    }
                }
                else if (getEndpoint() == CLOCK_CTRL_ENDPOINT)  // 0x3
                {
                    l_pervTarget = true;
                }
                // Check if Endpoint is a PERV endpoint
                else if ( (getEndpoint() == CHIPLET_CTRL_ENDPOINT) ||     // 0x0
                          (getEndpoint() == FIR_ENDPOINT)          ||     // 0x4
                          (getEndpoint() == THERMAL_ENDPOINT)      ||     // 0x5
                          (getEndpoint() == PCBSLV_ENDPOINT) )            // 0xF
                {
                    if ( getRingId() == PSCOM_RING_ID)                    // 0x0
                    {
                        l_pervTarget = true;
                    }
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

        // IOHS can be targeted by AXON or PAU chiplets (indirect scom),

        // Associate perv target resources with AXON
        if ( (getChipletId() >= AXON0_CHIPLET_ID) &&       // 0x18
             (getChipletId() <= AXON7_CHIPLET_ID) )        // 0x1F
        {
            l_iohsTarget = isPervTarget();

            // If not a PERV target check for IOHS target that uses AXON chiplet
            if (l_iohsTarget == false)
            {
                if ( (getEndpoint() == PSCOM_ENDPOINT)  &&
                     (getRingId() == AXONE_PDL_RING_ID) &&  // 0x4
                     (getSatId() == DLP_SAT_ID) )           // 0x0
                {
                    l_iohsTarget = true;
                }
            }
        }

        // Target via PAU chiplets
        else if ( isIndirect()                        &&
                  (getChipletId() >= PAU0_CHIPLET_ID) &&   // 0x10
                  (getChipletId() <= PAU3_CHIPLET_ID) )   // 0x13
        {
            // Endpoint must be PSCOM and RingID is IOPPE
            if ( (getEndpoint() == PSCOM_ENDPOINT) &&
                 (getRingId() == PAU_IOPPE_RING_ID) )     // 0xB
            {
                // Group address (bits 22:26 of upper address) must be 0b00000 or 0b00001,
                // and indirect register address should be per-group or per-lane
                // Group 0: IOHS[0]
                // Group 1: IOHS[1]
                if ( ( (getIoGroupAddr() == 0x0) ||
                       (getIoGroupAddr() == 0x1) ) &&
                     ((getIoRegAddr() & 0x1E0) != 0x1E0) )
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

        // Chiplet ID is AXON
        if ( (getChipletId() >= AXON0_CHIPLET_ID) &&
             (getChipletId() <= AXON7_CHIPLET_ID) )
        {
            l_instance = getChipletId() - AXON0_CHIPLET_ID;
        }
        // Chiplet ID is PAU
        else
        {
            // If chiplet ID is PAU then this is indirect address.
            // Use PAU and Group address (bits 22:26) to calculate instance.
            //   PAU0 (lower right) -> IOHS0 + IOHS1
            //   PAU1 (upper right) -> IOHS3 + IOHS2
            //   PAU2 (lower left)  -> IOHS5 + IOHS4
            //   PAU3 (upper left)  -> IOHS7 + IOHS6
            //
            // Group address bits (22:26) of upper 32-bit
            //   Group 0: IOHS[0]
            //   Group 1: IOHS[1]
            if ( (getChipletId() >= PAU0_CHIPLET_ID) &&      // 0x10
                 (getChipletId() <= PAU3_CHIPLET_ID) )       // 0x13
            {
                l_instance = (getChipletId() - PAU0_CHIPLET_ID) * 2;

                //AX0/1 instances are flipped for pauc1..3
                //Note, IOHS chiplets are ok, connections to AX0/1 are
                //flipped for ioo1..ioo3 in e10_chip.vhdl
                if (getChipletId() == PAU0_CHIPLET_ID)
                {
                    if (getIoGroupAddr() == 0x1)
                    {
                        l_instance += 1;
                    }
                }
                else
                {
                    if (getIoGroupAddr() == 0x0)
                    {
                        l_instance += 1;
                    }
                }
            }
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
                     (getRingId() == PAU0346_1_RING_ID) )  // 0x03

                {
                    l_pauTarget = true;
                }
                else if ( (getChipletId() == PAU2_CHIPLET_ID) ||
                          (getChipletId() == PAU3_CHIPLET_ID) )
                {
                    if ( (getRingId() == PAU57_0_RING_ID) || // 0x04
                         (getRingId() == PAU57_1_RING_ID) )  // 0x05
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
             (getRingId() == PAU0346_1_RING_ID) )  // 0x03
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

        else if ( (getRingId() == PAU57_0_RING_ID) || // 0x04
                  (getRingId() == PAU57_1_RING_ID) )  // 0x05
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

        // Chiplet ID must belong to MCs
        if ( (getChipletId() >= MC0_CHIPLET_ID)   &&    // 0x0C
             (getChipletId() <= MC3_CHIPLET_ID) )       // 0x0F
        {
            // allow access to perv endpoints on MC chiplets
            if (isPervTarget())
            {
                l_miTarget = true;
            }
            // Endpoint = PSCOM_ENDPOINT, and ringID = MC_0_RING_ID
            else if ( (getEndpoint() == PSCOM_ENDPOINT) &&     // 0x1
                      (getRingId() == MC_0_RING_ID) )          // 0x3
            {
                // PBI satellite
                if (getSatId() == MC_SAT_ID0)  // 0x0 (PBI)
                {
                    // avoid match on MCC register space
                    if (!(((getSatOffset() >= 0x22) &&
                           (getSatOffset() <= 0x2B)) ||
                          ((getSatOffset() >= 0x32) &&
                           (getSatOffset() <= 0x3B))))
                    {
                        l_miTarget = true;
                    }
                }

                // MCBIST satellite ID space
                // avoid match on MCC register space in 0xD
                if ( (getSatId() == MC_SAT_ID12) || // 0xC,0xE,0xF (MCBIST)
                     (getSatId() == MC_SAT_ID14) ||
                     (getSatId() == MC_SAT_ID15) )
                {
                    l_miTarget = true;
                }
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
        // and ringID = MC_0_RING_ID
        if ( (getChipletId() >= MC0_CHIPLET_ID) &&    // 0x0C
             (getChipletId() <= MC3_CHIPLET_ID) &&    // 0x0F
             (getEndpoint() == PSCOM_ENDPOINT) &&     // 0x1
             (getRingId() == MC_0_RING_ID) )          // 0x3
        {
            // MCC Sat ID
            if ( (getSatId() == MC_SAT_ID4) ||  // 0x4
                 (getSatId() == MC_SAT_ID8) ||  // 0x8
                 (getSatId() == MC_SAT_ID5) ||  // 0x5
                 (getSatId() == MC_SAT_ID9) )   // 0x9
            {
                l_mccTarget = true;
            }

            // MCC register space in PBI
            if (getSatId() == MC_SAT_ID0)
            {
                if (((getSatOffset() >= 0x22) &&
                     (getSatOffset() <= 0x2B)) ||
                    ((getSatOffset() >= 0x32) &&
                     (getSatOffset() <= 0x3B)))
                {
                    l_mccTarget = true;
                }
            }

            // MCC register space in MCBIST
            if (getSatId() == MC_SAT_ID13)
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

        // MCC Sat ID
        if ( (getSatId() == MC_SAT_ID5) ||  // 5
             (getSatId() == MC_SAT_ID9) )   // 9
        {
            l_instance += 1;
        }

        // MCC register space in PBI
        if ( getSatId() == MC_SAT_ID0 )     // 0
        {
            if ((getSatOffset() >= 0x32) &&
                (getSatOffset() <= 0x3B))
            {
                l_instance += 1;
            }
        }

        // MCC register space in MCBIST
        if ( getSatId() == MC_SAT_ID13)    // 13
        {
            // MSB of SatOffset denotes channel
            if (getSatOffset() >= 0x20)
            {
                l_instance += 1;
            }
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isOmiTarget()
    {
        bool l_omiTarget = false;

        // PAU chiplet, IOPPE ringId (indirect scom)
        if ( isIndirect()                          &&   // indirect
             ( getChipletId() >= PAU0_CHIPLET_ID ) &&   // 0x10
             ( getChipletId() <= PAU3_CHIPLET_ID ) &&   // 0x13
             ( getEndpoint() == PSCOM_ENDPOINT )   &&   // 0x1
             ( getRingId() == PAU_IOPPE_RING_ID)   &&   // 0xB
             ( getSatId() == PPE_SAT_ID0) )             // 0x0
        {
            // Group address (bits 22:26 of upper address)
            // must be 0b00010 or 0b00011 (for OMI)
            if ( (getIoGroupAddr() == 0x2 ) ||
                 (getIoGroupAddr() == 0x3 ) )
            {
                // Reg address must start with 0xxx (per lane)
                uint32_t regAddr = getIoRegAddr();

                if ( ( regAddr & 0x100 ) == 0x000 )
                {
                    l_omiTarget = true;
                }
            }
        }

        // MC chiplet direct SCOM
        if ( ( getChipletId() >= MC0_CHIPLET_ID ) &&   // 0x0C
             ( getChipletId() <= MC3_CHIPLET_ID ) &&   // 0x0F
             ( getEndpoint() == PSCOM_ENDPOINT )  &&   // 0x1
             ( getRingId() >= OMI0_RING_ID )      &&   // 0x5
             ( getRingId() <= OMI1_RING_ID )      &&   // 0x6
             ( getSatId()  == MC_SAT_ID0 ) )           // 0x0 (DL)
        {
            if (((getSatOffset() >= 16) &&             // 16:31 (subchannel 0)
                 (getSatOffset() <= 47)) ||            // 32:47 (subchannel 1)
                ((getSatOffset() >= 48) &&             // 48:51 (subchannel 0, pm regs)
                 (getSatOffset() <= 51)) ||
                ((getSatOffset() >= 56) &&             // 48:51 (subchannel 1, pm regs)
                 (getSatOffset() <= 59)))
            {
                l_omiTarget = true;
            }
        }

        return l_omiTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getOmiTargetInstance()
    {
        uint8_t l_instance = 0;

        // PAU chiplet indirect SCOM
        if ( (getChipletId() >= PAU0_CHIPLET_ID) &&      // 0x10
             (getChipletId() <= PAU3_CHIPLET_ID) )       // 0x13
        {
            // PAU0 --> OMI 0/1/2/3
            // PAU1 --> OMI 8/9/10/11
            // PAU2 --> OMI 4/5/6/7
            // PAU3 --> OMI 12/13/14/15
            // set basis based on direct chiplet ID
            if (getChipletId() == PAU0_CHIPLET_ID)
            {
                l_instance = 0;
            }
            else if (getChipletId() == PAU1_CHIPLET_ID)
            {
                l_instance = 8;
            }
            else if (getChipletId() == PAU2_CHIPLET_ID)
            {
                l_instance = 4;
            }
            else
            {
                l_instance = 12;
            }

            // account for IO group address
            if (getIoGroupAddr() == 0x3)
            {
                l_instance += 2;
            }

            // account for IO lane selection
            if ( ( getIoLane() >= 8 ) &&
                 ( getIoLane() <= 15) )
            {
                l_instance += 1;
            }
        }

        // MC direct
        if ( (getChipletId() >= MC0_CHIPLET_ID) &&
             (getChipletId() <= MC3_CHIPLET_ID) )
        {
            // Instances 0, 4, 8, 12
            l_instance = (getChipletId() - MC0_CHIPLET_ID) * 4;

            // Instances 2, 6, 10, 14
            if ( getRingId() == OMI1_RING_ID )     // 0x6
            {
                l_instance += 2;
            }

            // Instances 1, 3, 5, 7, 9, 11, 13, 15
            if ( ((getSatOffset() >= 32) &&
                  (getSatOffset() <= 47)) ||
                 ((getSatOffset() >= 56) &&
                  (getSatOffset() <= 59)) )
            {
                l_instance += 1;
            }
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isOmicTarget()
    {
        bool l_omicTarget = false;

        // PAU chiplet, IOPPE ringId (indirect scom)
        if ( isIndirect()                          &&   // indirect
             ( getChipletId() >= PAU0_CHIPLET_ID ) &&   // 0x10
             ( getChipletId() <= PAU3_CHIPLET_ID ) &&   // 0x13
             ( getEndpoint() == PSCOM_ENDPOINT )   &&   // 0x1
             ( getRingId() == PAU_IOPPE_RING_ID)   &&   // 0xB
             ( getSatId() == PPE_SAT_ID0) )             // 0x0
        {
            // Group address (bits 22:26 of upper address)
            // must be 0b00010 or 0b00011 (for OMI)
            if ( (getIoGroupAddr() == 0x2 ) ||
                 (getIoGroupAddr() == 0x3 ) )
            {
                // Reg address must start with 1xxx (per group),
                // excluding 1111 (per bus)
                uint32_t regAddr = getIoRegAddr();

                if ( ( ( regAddr & 0x1E0 ) != 0x1E0 ) &&
                     ( ( regAddr & 0x100 ) == 0x100 ) )
                {
                    l_omicTarget = true;
                }
            }
        }

        // MC chiplet direct SCOM
        if ( ( getChipletId() >= MC0_CHIPLET_ID ) &&   // 0x0C
             ( getChipletId() <= MC3_CHIPLET_ID ) &&   // 0x0F
             ( getEndpoint() == PSCOM_ENDPOINT )  &&   // 0x1
             ( getRingId() >= OMI0_RING_ID )      &&   // 0x5
             ( getRingId() <= OMI1_RING_ID )      &&   // 0x6
             ( getSatId()  == MC_SAT_ID0 ) )           // 0x0 (DL)
        {
            l_omicTarget = true;
        }

        return l_omicTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getOmicTargetInstance()
    {
        uint8_t l_instance = 0;

        // PAU indirect
        if ( ( getChipletId() >= PAU0_CHIPLET_ID ) &&   // 0x10
             ( getChipletId() <= PAU3_CHIPLET_ID ) )    // 0x13
        {
            // PAU0 --> OMIC 0/1
            // PAU1 --> OMIC 4/5
            // PAU2 --> OMIC 2/3
            // PAU3 --> OMIC 6/7
            if (getChipletId() == PAU0_CHIPLET_ID)
            {
                l_instance = 0;
            }
            else if (getChipletId() == PAU1_CHIPLET_ID)
            {
                l_instance = 4;
            }
            else if (getChipletId() == PAU2_CHIPLET_ID)
            {
                l_instance = 2;
            }
            else // PAU3_CHIPLET_ID
            {
                l_instance = 6;
            }

            if (getIoGroupAddr() == 0x3)
            {
                l_instance += 1;
            }
        }

        // MC direct
        if ( ( getChipletId() >= MC0_CHIPLET_ID ) &&   // 0x0C
             ( getChipletId() <= MC3_CHIPLET_ID ) )    // 0x0F
        {
            l_instance = (getChipletId() - MC0_CHIPLET_ID) * 2;

            if (getRingId() == 0x6)
            {
                l_instance += 1;
            }
        }

        return l_instance;
    }

    // #####################################
    bool p10_scom_addr::isPaucTarget()
    {
        bool l_paucTarget = false;

        if ( (getChipletId() >= PAU0_CHIPLET_ID) &&    // 0x10
             (getChipletId() <= PAU3_CHIPLET_ID) )     // 0x13
        {
            // allow access to perv endpoints on MC chiplets
            if (isPervTarget())
            {
                l_paucTarget = true;
            }
            else if ( getEndpoint() == PSCOM_ENDPOINT )  // 0x1
            {
                // IO PPE access
                if ( isDirect()                         && // direct
                     (getRingId() == PAU_IOPPE_RING_ID) && // 0xB
                     ( (getSatId() == PPE_SAT_ID0) ||      // 0x0
                       (getSatId() == PPE_SAT_ID1) ) )     // 0x1
                {
                    l_paucTarget = true;
                }

                // TL access
                if ( (getRingId() == PAU_TL_RING_ID) &&    // 0x6
                     ( (getSatId() == TL_SAT_ID) ) )       // 0x0
                {
                    l_paucTarget = true;
                }

                // per-bus IO super wrapper registers
                if ( isIndirect()                        && // indirect
                     ((getIoRegAddr() & 0x1E0) == 0x1E0) && // register(0:3) = 0b1111
                     (getRingId() == PAU_IOPPE_RING_ID)  && // 0xB
                     (getSatId() == PPE_SAT_ID0) )          // 0x0
                {
                    l_paucTarget = true;
                }
            }
        }

        return l_paucTarget;
    }

    // #####################################
    uint8_t p10_scom_addr::getPaucTargetInstance()
    {
        uint8_t l_instance = (getChipletId() - PAU0_CHIPLET_ID);

        return l_instance;
    }

} // extern "C"

#undef P10_SCOM_ADDR_C
