/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/scominfo/p10_scom_addr.H $        */
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
/// @file p10_scom_addr.H
/// @brief P10 SCOM address class
///
/// HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// HWP FW Maintainer:
/// HWP Consumed by: CRONUS, HOSTBOOT, HWSV
///

#ifndef P10_SCOM_ADDR_H
#define P10_SCOM_ADDR_H

// includes
#include <stdint.h>

//@thi-TODO: Need to revisit the following items once design is finalized:
//           PPE, IOHS, PAU, MI, MCC, OMI, OMIC

extern "C"
{
    /// Constants
    const uint32_t NUM_CORES_PER_EQ = 4;  // Num of cores in an EQ chiplet

    /// P10 Chiplet ID enumeration
    typedef enum
    {
        PIB_CHIPLET_ID   = 0x00,    ///< PIB chiplet (FSI)
        PERV_CHIPLET_ID  = 0x01,    ///< TP chiplet

        N0_CHIPLET_ID    = 0x02,    ///< Nest0 (North) chiplet
        N1_CHIPLET_ID    = 0x03,    ///< Nest1 (South) chiplet

        PCI0_CHIPLET_ID  = 0x08,    ///< PCIe0 chiplet
        PCI1_CHIPLET_ID  = 0x09,    ///< PCIe1 chiplet

        MC0_CHIPLET_ID   = 0x0C,    ///< MC0 chiplet
        MC1_CHIPLET_ID   = 0x0D,    ///< MC1 chiplet
        MC2_CHIPLET_ID   = 0x0E,    ///< MC2 chiplet
        MC3_CHIPLET_ID   = 0x0F,    ///< MC3 chiplet

        PAU0_CHIPLET_ID  = 0x10,    ///< PAU0 chiplet
        PAU1_CHIPLET_ID  = 0x11,    ///< PAU1 chiplet
        PAU2_CHIPLET_ID  = 0x12,    ///< PAU2 chiplet
        PAU3_CHIPLET_ID  = 0x13,    ///< PAU3 chiplet

        AXON0_CHIPLET_ID = 0x18,    ///< AXON0 chiplet (high speed io)
        AXON1_CHIPLET_ID = 0x19,    ///< AXON1 chiplet (high speed io)
        AXON2_CHIPLET_ID = 0x1A,    ///< AXON2 chiplet (high speed io)
        AXON3_CHIPLET_ID = 0x1B,    ///< AXON3 chiplet (high speed io)
        AXON4_CHIPLET_ID = 0x1C,    ///< AXON4 chiplet (high speed io)
        AXON5_CHIPLET_ID = 0x1D,    ///< AXON5 chiplet (high speed io)
        AXON6_CHIPLET_ID = 0x1E,    ///< AXON6 chiplet (high speed io)
        AXON7_CHIPLET_ID = 0x1F,    ///< AXON7 chiplet (high speed io)

        EQ0_CHIPLET_ID   = 0x20,    ///< Quad0 chiplet (super chiplet)
        EQ1_CHIPLET_ID   = 0x21,    ///< Quad1 chiplet (super chiplet)
        EQ2_CHIPLET_ID   = 0x22,    ///< Quad2 chiplet (super chiplet)
        EQ3_CHIPLET_ID   = 0x23,    ///< Quad3 chiplet (super chiplet)
        EQ4_CHIPLET_ID   = 0x24,    ///< Quad4 chiplet (super chiplet)
        EQ5_CHIPLET_ID   = 0x25,    ///< Quad5 chiplet (super chiplet)
        EQ6_CHIPLET_ID   = 0x26,    ///< Quad6 chiplet (super chiplet)
        EQ7_CHIPLET_ID   = 0x27,    ///< Quad7 chiplet (super chiplet)
    } p10ChipletId_t;

    /// P10 SCOM Endpoint ID enumeration
    typedef enum
    {
        CHIPLET_CTRL_ENDPOINT   = 0x0,    ///< Chiplet Control
        PSCOM_ENDPOINT          = 0x1,    ///< EQ:PSCOM (L3), others: PSCOM
        PSCOM_2_ENDPOINT        = 0x2,    ///< EQ:PSCOM (Core/L2), TP:ITR, Nest:TOD (Time Of Day)
        CLOCK_CTRL_ENDPOINT     = 0x3,    ///< Clock controller
        FIR_ENDPOINT            = 0x4,    ///< FIR
        THERMAL_ENDPOINT        = 0x5,    ///< Thermal
        DPLL_ENDPOINT           = 0x6,    ///< TP (only): DPLL
        QME_ENDPOINT            = 0xE,    ///< EQ (only): QME
        PCBSLV_ENDPOINT         = 0xF,    ///< PCB Slave registers
    } p10EndpointID_t;

    /// P10 region select (CoreId/One-hot)
    typedef enum
    {
        EQ_REGION_SEL       = 0x0,
        MULTI_HOT_SELECT_C0 = 0x8,
        MULTI_HOT_SELECT_C1 = 0x4,
        MULTI_HOT_SELECT_C2 = 0x2,
        MULTI_HOT_SELECT_C3 = 0x1,
    } p10RegionSelect_t;

    /// *************************************
    ///          Ring ID enums
    /// *************************************

    /// P10 N0 chiplet ring ID enumeration
    typedef enum
    {
        N0_MM0_RING_ID  = 0x3,
        N0_PE0_RING_ID   = 0x6,
    } p10_N0_RingId_t;

    /// P10 N1 chiplet ring ID enumeration
    /// source: tpc_p10_n1_top.vhdl
    typedef enum
    {
        N1_MM1_RING_ID  = 0x3,
        N1_PE1_RING_ID  = 0x6,
    } p10_N1_RingId_t;

    /// P10 PCIe chiplet SCOM ring ID enumeration
    typedef enum
    {
        PCI_RING_ID      = 0x2,
        IO_PCI0_RING_ID  = 0x3,
        IO_PCI1_RING_ID  = 0x4,
        IO_PCI2_RING_ID  = 0x5,
    } p10_PCI_RingId_t;

    /// P10 PERV chiplet and PSCOM ring ID enumeration
    typedef enum
    {
        PSCOM_RING_ID = 0x0,
        PERV_RING_ID  = 0x1,
    } p10_PSCOM_PERV_RingId_t;

    /// P10 AXONE chiplet ring ID enumeration
    typedef enum
    {
        AXONE_PERV_RING_ID = 0x1,
        AXONE_ODL_RING_ID  = 0x3,
        AXONE_NDL_RING_ID  = 0x4,
        AXONE_PDL_RING_ID  = 0x5,
    } p10_AXONE_RingId_t;

    /// P10 PAU chiplet ring ID enumeration
    typedef enum
    {
        PAU0346_0_RING_ID   = 0x2,
        PAU0346_1_RING_ID   = 0x3,
        PAU57_0_RING_ID     = 0x4,
        PAU57_1_RING_ID     = 0x5,
        PBPAU0346_0_RING_ID = 0x6,
        PBPAU0346_1_RING_ID = 0x7,
        PBPAU57_0_RING_ID   = 0x8,
        PBPAU57_1_RING_ID   = 0x9,
        PAU_TL_RING_ID      = 0xA,
        PAU_DLP_RING_ID     = 0xC,
    } p10_PAU_RingId_t;

    /// P10 MC chiplet ring ID enumeration
    typedef enum
    {
        MC_RING_ID   = 0x2,
        OMI0_RING_ID = 0x3,
        OMI1_RING_ID = 0x4,
        IOO0_RING_ID = 0x5,
        IOO1_RING_ID = 0x6,
    } p10_MC_RingId_t;

    /// -----------------------
    /// Satellite ID defintions
    /// -----------------------
    typedef enum
    {
        NMMU_SAT_ID = 0x0,
    } p10_NMMU_SatId_t;

    typedef enum
    {
        PCI_SAT_ID  = 0x0,
    } p10_PCI_SatId_t;

    typedef enum
    {
        MC_SAT_ID0  = 0x0,
        MC_SAT_ID4  = 0x4,
        MC_SAT_ID5  = 0x5,
        MC_SAT_ID8  = 0x8,
        MC_SAT_ID9  = 0x9,
        MC_SAT_ID12 = 0xC,
    } p10_MC_SatId_t;

    /// *************************************
    ///          Perv target table
    /// *************************************
    const p10ChipletId_t PervTargetChipletIdTable[] =
    {
        PIB_CHIPLET_ID,
        PERV_CHIPLET_ID,
        N0_CHIPLET_ID,
        N1_CHIPLET_ID,
        PCI0_CHIPLET_ID,
        PCI1_CHIPLET_ID,
        MC0_CHIPLET_ID,
        MC1_CHIPLET_ID,
        MC2_CHIPLET_ID,
        MC3_CHIPLET_ID,
        PAU0_CHIPLET_ID,
        PAU1_CHIPLET_ID,
        PAU2_CHIPLET_ID,
        PAU3_CHIPLET_ID,
        AXON0_CHIPLET_ID,
        AXON1_CHIPLET_ID,
        AXON2_CHIPLET_ID,
        AXON3_CHIPLET_ID,
        AXON4_CHIPLET_ID,
        AXON5_CHIPLET_ID,
        AXON6_CHIPLET_ID,
        AXON7_CHIPLET_ID,
        EQ0_CHIPLET_ID,
        EQ1_CHIPLET_ID,
        EQ2_CHIPLET_ID,
        EQ3_CHIPLET_ID,
        EQ4_CHIPLET_ID,
        EQ5_CHIPLET_ID,
        EQ6_CHIPLET_ID,
        EQ7_CHIPLET_ID,
    };

    struct PpeTargetInfo_t
    {
        const uint8_t targetInstance;    // Target instance
        const uint8_t chipletId;         // Chiplet ID
        const uint8_t endpointId;        // Endpoint ID
        const uint8_t ringId;            // Ring ID
        const uint8_t satId;             // Sat ID, 0xFF = don't care
    };

    /// *************************************
    ///          PPE target table
    /// *************************************
    const PpeTargetInfo_t PpeTargetInfoTable[] =
    {
        // Instance  ChipletID    EndpointID  RingID    SatId
        {     0,       0x00,         0xE,       0,       0x0 },
        {     4,       0x00,         0x5,       0,       0x0 },
        {     5,       0x00,         0x6,       0,       0x0 },
        {     6,       0x00,         0x7,       0,       0x0 },
        {     7,       0x00,         0x8,       0,       0x0 },
        {    16,       0x10,         0x1,      11,       0x0 },
        {    17,       0x11,         0x1,      11,       0x0 },
        {    18,       0x12,         0x1,      11,       0x0 },
        {    19,       0x13,         0x1,      11,       0x0 },
        {    32,       0x20,         0xE,       0,       0x0 },
        {    33,       0x21,         0xE,       0,       0x0 },
        {    34,       0x22,         0xE,       0,       0x0 },
        {    35,       0x23,         0xE,       0,       0x0 },
        {    36,       0x24,         0xE,       0,       0x0 },
        {    37,       0x25,         0xE,       0,       0x0 },
        {    38,       0x26,         0xE,       0,       0x0 },
        {    39,       0x27,         0xE,       0,       0x0 },
    };

// ----------------------
// For non-EQ chiplets
// ----------------------
//        8             7             6             5             4             3          2         1
//
//  |0 1 2 3| |4 5 6 7| |8 9 10 11| |12 13 14 15| |16 17 18 19| |20 21 22 23| |24 25 26 27| |28 29 30 31|
//    {A}{     B     }               {     C   }   0  0  {      D    } {     E     } {        F        }
//
// A - Is multiCast if bit 1 = 0x1
// B - Chiplet ID (6 bits) [2:7]
// C - Endpoint ID (4 bits) [12:15]
// D - Ring (4 bits) [18:21]
// E - Sat ID (4 bits) [22:25]
// F - Sat Offset (6 bits) [26:31]

// ----------------------
// For EQ/Core chiplets
// ----------------------
//        8             7             6             5             4             3          2         1
//
//  |0 1 2 3| |4 5 6 7| |8 9 10 11| |12 13 14 15| |16 17 18 19| |20 21 22 23| |24 25 26 27| |28 29 30 31|
//    {A}{     B      }             {     C     }  {    D    }   E   F { G  }  {         H             }
//
// A - Is multiCast if bit 1 = 0x1
// B - Chiplet ID (6 bits) [2:7]
// C - Endpoint ID (4 bits) [12:15]
// D - Region select (4 bits) [16:19]
// E - QME per core (1 bit) [20]
// F - QME Sat Enable (1 bit) [21]
// G - QME Sat sel (2 bits) [22:23]
// H - QME reg (8 bits) [24:31]

    /// P10 SCOM address class
    class p10_scom_addr
    {
        public:

            /// @brief Construct a SCOM address object
            /// @param[in] i_addr 64-bit raw SCOM address
            p10_scom_addr(const uint64_t i_addr)
                : iv_addr(i_addr)
            {
            }

            /// @brief Set full/raw SCOM address
            /// @param[in] i_addr 64-bit SCOM address
            /// @retval none
            inline void setAddr(const uint64_t i_addr)
            {
                iv_addr = i_addr;
                return;
            }

            /// @brief Retrieve full/raw SCOM address
            /// @retval uint64_t 64-bit SCOM address
            inline uint64_t getAddr() const
            {
                return (iv_addr);
            }

            /// @brief Determine if SCOM address is direct-form (bit 0)
            /// @retval bool True if SCOM address is direct-form, false otherwise
            inline bool isDirect() const
            {
                return (((iv_addr >> 63) & 0x1) == 0x0);
            }

            /// @brief Determine if SCOM address is indirect-form
            /// @retval bool True if SCOM address is indirect-form, false otherwise
            inline bool isIndirect() const
            {
                return (!isDirect());
            }

            /// @brief Determine if SCOM address is multicast (bit 1)
            /// @retval bool True if SCOM address is multicast, false otherwise
            inline bool isMulticast() const
            {
                return (((iv_addr >> 30) & 0x1) == 0x1);
            }

            /// @brief Determine if SCOM address is unicast
            /// @retval bool True if SCOM address is unicast, false otherwise
            inline bool isUnicast() const
            {
                return (!(isMulticast()));
            }

            /// @brief Extract pervasive chiplet ID from SCOM address (bits 2:7)
            /// @retval uint8_t Pervasive chiplet ID value
            inline uint8_t getChipletId() const
            {
                return ((iv_addr >> 24) & 0x3F);
            }

            /// @brief Modify SCOM address, update pervasive chiplet ID
            /// @param[in] i_chiplet_id Chiplet ID value to write
            /// @retval none
            inline void setChipletId(const uint8_t i_chiplet_id)
            {
                iv_addr &= 0xFFFFFFFFC0FFFFFFULL;
                iv_addr |= ((i_chiplet_id & 0x3F) << 24);
                return;
            }

            /// @brief Extract Endpoint field from SCOM address (bits 12:15)
            /// @retval uint8_t Endpoint field value
            inline uint8_t getEndpoint() const
            {
                return ((iv_addr >> 16) & 0xF);
            }

            /// @brief Modify the Endpoint field from SCOM address
            /// @retval none
            inline void setEndpoint(const uint8_t i_port)
            {
                iv_addr &= 0xFFFFFFFFFFF0FFFFULL;
                iv_addr |= ((i_port & 0xF) << 16);
                return;
            }

            /// @brief Extract region select field (core id) from SCOM address (bits 16:19)
            /// @retval uint8_t Region select value
            inline uint8_t getRegionSelect() const
            {
                return ((iv_addr >> 12) & 0xF);
            }

            /// @brief Modify the region select field (core id) from SCOM address
            /// @retval none
            inline void setRegionSelect(const uint8_t i_regionSelect)
            {
                iv_addr &= 0xFFFFFFFFFFFF0FFFULL;
                iv_addr |= ((i_regionSelect & 0xF) << 12);
                return;
            }

            /// @brief Extract ring field from SCOM address (bits 18:21)
            /// @retval uint8_t Ring id value
            inline uint8_t getRingId() const
            {
                return ((iv_addr >> 10) & 0xF);
            }

            /// @brief Modify SCOM address, update ring field value
            /// @param[in] i_ring Ring field value to write
            /// @retval none
            inline void setRingId(const uint8_t i_ring)
            {
                iv_addr &= 0xFFFFFFFFFFFF03FFULL;
                iv_addr |= ((i_ring & 0x3F) << 10);
                return;
            }

            /// @brief Extract satellite ID field from SCOM address (bits 22:25)
            /// @retval uint8_t Satellite ID field value
            inline uint8_t getSatId() const
            {
                return ((iv_addr >> 6) & 0xF);
            }

            /// @brief Modify SCOM address, update satellite ID field
            /// @param[in] i_sat_id Satellite ID value to write
            /// @retval none
            inline void setSatId(const uint8_t i_satId)
            {
                iv_addr &= 0xFFFFFFFFFFFFFC3FULL;
                iv_addr |= ((i_satId & 0xF) << 6);
                return;
            }

            /// @brief Extract satellite register offset field from SCOM address (bits 26:31)
            /// @retval uint8_t Satellite register offset field value
            inline uint8_t getSatOffset() const
            {
                return (iv_addr & 0x3F);
            }

            /// @brief Modify SCOM address, update satellite offset field
            /// @param[in] i_sat_offset Satellite offset value to write
            /// @retval none
            inline void setSatOffset(const uint8_t i_sat_offset)
            {
                iv_addr &= 0xFFFFFFFFFFFFFFC0ULL;
                iv_addr |= (i_sat_offset & 0x3F);
                return;
            }

            /// @brief Determine if SCOM address is valid/well-formed
            /// @retval bool True if SCOM address is valid, false otherwise
            inline bool isValid() const
            {
                return true;
            }

            /// @brief Determine if this address belongs to EQ target type
            /// @retval true or false.
            bool isEqTarget();

            /// @brief Determine the EQ instance for this address
            /// Function prereq: Address must belong to EQ target type
            /// @retval uint8_t EQ target instance
            uint8_t getEqTargetInstance();

            /// @brief  Determine if this address belongs to core target type
            /// @retval true or false.
            bool isCoreTarget();

            /// @brief  Determine the core instance for this address.
            /// Function prereq: Address must belong to core target type
            /// @retval uint8_t Core target instance
            uint8_t getCoreTargetInstance();

            /// @brief Determine if this address belongs to PEC target type
            /// @retval true or false.
            bool isPecTarget();

            /// @brief Determine the pec instance for this address
            /// Function prereq: Address must belong to PEC target type
            /// @retval uint8_t PEC target instance
            uint8_t getPecTargetInstance();

            /// @brief Determine if this address belongs to PHB target type
            /// @retval true or false.
            bool isPhbTarget();

            /// @brief Determine the PHB instance for this address
            /// Function prereq: Address must belong to PHB target type
            /// @retval uint8_t PHB target instance
            uint8_t getPhbTargetInstance();

            /// @brief Determine if this address belongs to NMMU target type
            /// @retval true or false.
            bool isNmmuTarget();

            /// @brief Determine the NMMU instance for this address
            /// Function prereq: Address must belong to NMMU target type
            /// @retval uint8_t NMMU target instance
            uint8_t getNmmuTargetInstance();

            /// @brief Get the QME Per Core value (bit 20, EQ/Core only)
            /// Function prereq: Address must belong to EQ or Core target type
            /// @retval uint8_t QME Per Core value
            inline uint8_t getQMEPerCore()
            {
                return (iv_addr >> 11) & 0x1;
            }

            /// @brief Get the QME Sat Enable value (bit 21, EQ/Core only)
            /// Function prereq: Address must belong to EQ or Core target type
            /// @retval uint8_t QME Sat Enable value
            inline uint8_t getQMESatEn()
            {
                return (iv_addr >> 10) & 0x1;
            }

            /// @brief Get the QME Sat Select value (bit 22:23, EQ/Core only)
            /// Function prereq: Address must belong to EQ or Core target type
            /// @retval uint8_t QME Sat Sel value
            inline uint8_t getQMESatSel()
            {
                return (iv_addr >> 8) & 0x3;
            }

            /// @brief Get the QME reg value (bit 24:31, EQ/Core only)
            /// Function prereq: Address must belong to EQ or Core target type
            /// @retval uint8_t QME reg value
            inline uint8_t getQMEReg()
            {
                return (iv_addr & 0xFF);
            }

            /// @brief Determine if this address belongs to PERV target type
            /// @retval true or false.
            bool isPervTarget();

            /// @brief Determine the PERV instance for this address
            /// Function prereq: Address must belong to PERV target type
            /// @retval uint8_t PERV target instance.
            uint8_t getPervTargetInstance();

            /// @brief Determine if this address belongs to IOHS target type
            /// @retval true or false.
            bool isIoHsTarget();

            /// @brief Determine the IOHS instance for this address
            /// Function prereq: Address must belong to IOHS target type
            /// @retval uint8_t IOHS target instance.
            uint8_t getIoHsTargetInstance();

            /// @brief Determine if this address belongs to PAU target type
            /// @retval true or false.
            bool isPauTarget();

            /// @brief Determine the PAU instance for this address
            /// Function prereq: Address must belong to PAU target type
            /// @retval uint8_t PAU target instance.
            uint8_t getPauTargetInstance();

            /// @brief Determine if this address belongs to MC target type
            /// @retval true or false.
            bool isMcTarget();

            /// @brief Determine the MC instance for this address
            /// Function prereq: Address must belong to MI target type
            /// @retval uint8_t MC target instance.
            uint8_t getMcTargetInstance();

            /// @brief Determine if this address belongs to MI target type
            /// @retval true or false.
            bool isMiTarget();

            /// @brief Determine the MI instance for this address
            /// Function prereq: Address must belong to MI target type
            /// @retval uint8_t MI target instance.
            uint8_t getMiTargetInstance();

            /// @brief Determine if this address belongs to MCC target type
            /// @retval true or false.
            bool isMccTarget();

            /// @brief Determine the MCC instance for this address
            /// Function prereq: Address must belong to MCC target type
            /// @retval uint8_t MCC target instance.
            uint8_t getMccTargetInstance();

            /// @brief Determine if this address belongs to OMI target type
            /// @retval true or false.
            bool isOmiTarget();

            /// @brief Determine the OMI instance for this address
            /// Function prereq: Address must belong to OMI target type
            /// @retval uint8_t OMI target instance.
            uint8_t getOmiTargetInstance();

            /// @brief Determine if this address belongs to OMIC target type
            /// @retval true or false.
            bool isOmicTarget();

            /// @brief Determine the OMIC instance for this address
            /// Function prereq: Address must belong to OMIC target type
            /// @retval uint8_t OMIC target instance.
            uint8_t getOmicTargetInstance();

            /// @brief Determine if this address belongs to PPE target type
            /// @retval true or false.
            bool isPpeTarget();

            /// @brief Determine the PPE instance for this address
            /// Function prereq: Address must belong to PPE target type
            /// @retval uint8_t PPE target instance.
            uint8_t getPpeTargetInstance();

        private:
            uint64_t iv_addr;   ///< 64-bit raw SCOM address
    };

} // extern "C"

#endif /* P10_SCOM_ADDR_H */
