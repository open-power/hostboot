/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/scominfo/odyssey_scom_addr.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2023                        */
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
/// @file odyssey_scom_addr.H
/// @brief ODYSSEY SCOM address class
///
/// HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// HWP FW Maintainer:
/// HWP Consumed by: Cronus, HB
///

#ifndef ODYSSEY_SCOM_ADDR_H
#define ODYSSEY_SCOM_ADDR_H

// includes
#include <stdint.h>

extern "C"
{
    /// Constants

    /// ODYSSEY Chiplet ID enumeration
    typedef enum
    {
        ODY_PIB_CHIPLET_ID       = 0x00,    ///< PIB chiplet (FSI)
        ODY_PERV_CHIPLET_ID      = 0x01,    ///< TP chiplet
        ODY_MEM_CHIPLET_ID       = 0x08,
    } odysseyChipletId_t;

    /// ODYSSEY SCOM Endpoint ID enumeration
    typedef enum
    {
        ODY_CHIPLET_CTRL_ENDPOINT   = 0x0,    ///< Chiplet Control
        ODY_PSCOM_ENDPOINT          = 0x1,    ///< PSCOM
        ODY_CLOCK_CTRL_ENDPOINT     = 0x3,    ///< Clock controller
        ODY_FIR_ENDPOINT            = 0x4,    ///< FIR
        ODY_THERMAL_ENDPOINT        = 0x5,    ///< Thermal
        ODY_PCBSLV_ENDPOINT         = 0xF,    ///< PCB Slave registers
    } odysseyEndpointID_t;

    /// ODYSSEY PERV chiplet and PSCOM ring ID enumeration
    typedef enum
    {
        ODY_PSCOM_RING_ID = 0x0,
        ODY_PERV_RING_ID  = 0x1,
    } odyssey_PSCOM_PERV_RingId_t;
    typedef enum
    {
        ODY_OMI0_RING_ID = 0x3,
        ODY_DLX_RING_ID  = 0x9,
    } odyssey_MC_RingId_t;

    /// ODYSSEY MEMPORT chiplet ring ID enumeration
    typedef enum
    {
        ODY_MEMPORT0_RING_ID = 0x6,  // RDF0
        ODY_MEMPORT1_RING_ID = 0xA,  // RDF1
        ODY_MEMPORT0_PHY_RING_ID = 0xC,
        ODY_MEMPORT1_PHY_RING_ID = 0xD,
    } odyssey_MEMPORT_RingId_t;

    /// ODYSSEY SCOM address class
    class odyssey_scom_addr
    {
        public:

            /// @brief Construct a SCOM address object
            /// @param[in] i_addr 64-bit raw SCOM address
            odyssey_scom_addr(const uint64_t i_addr)
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

            /// @brief Extract ring field from SCOM address (bits 18:21)
            /// @retval uint8_t Ring id value
            inline uint8_t getRingId() const
            {
                return ((iv_addr >> 10) & 0xF);
            }

            /// @brief Modify SCOM address, update ring field value (bits 18:21)
            /// @param[in] i_ring Ring field value to write
            /// @retval none
            inline void setRingId(const uint8_t i_ring)
            {
                iv_addr &= 0xFFFFFFFFFFFFC3FFULL;
                iv_addr |= ((i_ring & 0xF) << 10);
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

            /// @brief Get the OBUS Super Wrapper Group address (bits 22:26) of
            ///        an indirect scom address
            /// @retval uint8_t Group address
            inline uint8_t getIoGroupAddr() const
            {
                return ((iv_addr >> 37) & 0x1F);
            }

            /// @brief Set the OBUS Super Wrapper Group address (bits 22:26) of
            ///        an indirect scom address
            /// @param[in] i_group_addr Group address value to write
            /// @retval none
            inline void setIoGroupAddr(const uint8_t i_group_addr)
            {
                iv_addr &= 0xFFFFFC1FFFFFFFFFULL;
                iv_addr |= ( ((uint64_t)i_group_addr & 0x1F) << 37 );
                return;
            }

            /// @brief Get  Super Wrapper Register address (bits 12:20)
            ///        of an indirect scom address
            /// @retval uint32_t Register address
            inline uint32_t getIoRegAddr() const
            {
                return ((iv_addr >> 43) & 0x1FF);
            }

            /// @brief Get the OBUS Super Wrapper TX/RX bit (bit 21)
            ///        of an indirect scom address
            /// @retval uint8_t TX/RX bit
            inline uint32_t getIoTxRxBit() const
            {
                return ((iv_addr >> 42) & 0x1);
            }

            /// @brief Get the OBUS Super Wrapper Lane (bits 27:31)
            ///        of an indirect scom address
            /// @retval uint8_t Lane
            inline uint32_t getIoLane() const
            {
                return ((iv_addr >> 32) & 0x1F);
            }

            /// @brief Set the OBUS Super Wrapper Lane (bits 27:31)
            ///        of an indirect scom address
            /// @retval uint8_t Lane
            inline void setIoLane(const uint8_t i_lane)
            {
                iv_addr &= 0xFFFFFFE0FFFFFFFFULL;
                iv_addr |= ( ((uint64_t)i_lane & 0x1F) <<  32);
            }

            /// @brief Determine if SCOM address is valid/well-formed
            /// @retval bool True if SCOM address is valid, false otherwise
            inline bool isValid() const
            {
                return true;
            }

            /// @brief Determine if this address belongs to PERV target type
            /// @retval true or false.
            bool isPervTarget();

            /// @brief Determine the PERV instance for this address
            /// Function prereq: Address must belong to PERV target type
            /// @retval uint8_t PERV target instance.
            uint8_t getPervTargetInstance();

            /// @brief Determine if this address belongs to OMI target type
            /// @retval true or false.
            bool isOmiTarget();    // This is for re-use of OMI procedures on Odyssey

            /// @brief Determine the OMI instance for this address
            /// Function prereq: Address must belong to OMI target type
            /// @retval uint8_t OMI target instance.
            uint8_t getOmiTargetInstance(); // This is for re-use of OMI procedures on Odyssey

            /// @brief  Determine if this address belongs to Memport target type
            /// @retval true or false.
            bool isMemportTarget();

            /// @brief Determine the Memport instance for this address
            /// Function prereq: Address must belong to Memport target type
            /// @retval uint8_t Memport target instance.
            uint8_t getMemportTargetInstance();

        private:
            uint64_t iv_addr;   ///< 64-bit raw SCOM address
    };

} // extern "C"

#endif /* ODYSSEY_SCOM_ADDR_H */
