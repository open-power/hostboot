/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/scominfo/odyssey_scominfo.C $ */
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
/// @file odyssey_scominfo.C
/// @brief ODYSSEY chip unit SCOM address platform translation code
///
/// HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// HWP FW Maintainer:
/// HWP Consumed by: Cronus, HB
///

// includes
#include <odyssey_scominfo.H>
#include <odyssey_scom_addr.H>

#define ODYSSEY_SCOMINFO_C

extern "C"
{

    // ---------------------------
    // Internal functions
    // ---------------------------

    // See header file for function description
    uint64_t odyssey_scominfo_createChipUnitScomAddr(
        const odysseyChipUnits_t i_odysseyCU,
        const uint8_t i_ecLevel,
        const uint8_t i_chipUnitNum,
        const uint64_t i_scomAddr,
        const odysseyTranslationMode_t i_mode)
    {
        uint8_t l_rc = 0;
        odyssey_scom_addr l_scom(i_scomAddr);

        do
        {
            // If chip unit type is a chip, return input address
            if (i_odysseyCU == ODYSSEY_NO_CU)
            {
                l_scom.setAddr(i_scomAddr);
                break;
            }

            // Make sure i_chipUnitNum is within range
            l_rc = odyssey_validateChipUnitNum(i_chipUnitNum, i_odysseyCU);

            if (l_rc)
            {
                break;
            }

            // Set other address fields (ringId, satId, etc...)
            // for Chip unit types that are needed.
            switch (i_odysseyCU)
            {
                case ODYSSEY_PERV_CHIPUNIT:
                    l_scom.setChipletId(i_chipUnitNum);
                    break;

                case ODYSSEY_MEMPORT_CHIPUNIT:
                    {
                        uint8_t l_ring = l_scom.getRingId();

                        if (l_ring == ODY_MEMPORT0_RING_ID || l_ring == ODY_MEMPORT1_RING_ID)
                        {
                            if (i_chipUnitNum == 0)
                            {
                                l_scom.setRingId(ODY_MEMPORT0_RING_ID);
                            }
                            else
                            {
                                l_scom.setRingId(ODY_MEMPORT1_RING_ID);
                            }
                        }

                        if (l_ring == ODY_MEMPORT0_PHY_RING_ID || l_ring == ODY_MEMPORT1_PHY_RING_ID)
                        {
                            if (i_chipUnitNum == 0)
                            {
                                l_scom.setRingId(ODY_MEMPORT0_PHY_RING_ID);
                            }
                            else
                            {
                                l_scom.setRingId(ODY_MEMPORT1_PHY_RING_ID);
                            }
                        }
                    }
                    break;

                case ODYSSEY_OMI_CHIPUNIT:
                    break;

                default:
                    break;
            }

        }
        while (0);

        if (l_rc)
        {
            l_scom.setAddr(ODY_FAILED_TRANSLATION);
        }

        return l_scom.getAddr();
    }

    // See header file for function description
    uint32_t odyssey_scominfo_isChipUnitScom(const odysseyChipUnits_t i_odysseyCU,
            const uint8_t i_ecLevel,
            const uint64_t i_scomAddr,
            bool& o_chipUnitRelated,
            std::vector<odyssey_chipUnitPairing_t>& o_chipUnitPairing,
            const odysseyTranslationMode_t i_mode)
    {
        odyssey_scom_addr l_scom(i_scomAddr);
        o_chipUnitRelated = false;
        o_chipUnitPairing.clear();

        // All Odyssey SCOM regs are not chip unit related in ENGD
        if (i_mode == ODYSSEY_ENGD_BUILD_MODE)
        {
            return (!l_scom.isValid());
        }

        // OMI registers
        if (l_scom.isOmiTarget())
        {
            o_chipUnitRelated = true;
            // ODYSSEY_OMI_CHIPUNIT
            o_chipUnitPairing.push_back(odyssey_chipUnitPairing_t(ODYSSEY_OMI_CHIPUNIT,
                                        l_scom.getOmiTargetInstance()));
        }

        // PERV registers
        if (l_scom.isPervTarget())
        {
            o_chipUnitRelated = true;
            // ODYSSEY_PERV_CHIPUNIT
            o_chipUnitPairing.push_back(odyssey_chipUnitPairing_t(ODYSSEY_PERV_CHIPUNIT,
                                        l_scom.getPervTargetInstance()));
        }

        // Memport registers
        if (l_scom.isMemportTarget())
        {
            o_chipUnitRelated = true;
            // ODYSSEY_MEMPORT_CHIPUNIT
            o_chipUnitPairing.push_back(odyssey_chipUnitPairing_t(ODYSSEY_MEMPORT_CHIPUNIT,
                                        l_scom.getMemportTargetInstance()));
        }

        /// Address may be of a chip, let it pass through
        return (!l_scom.isValid());
    }

    // See header file for function description
    uint64_t odyssey_scominfo_screenIndirectStatus(const uint8_t i_ecLevel,
            const uint64_t i_scomAddr,
            const uint64_t i_indirectStatus)
    {
        uint64_t o_indirectStatus = i_indirectStatus;

        // IOO/OMI satellite passes non-error information into bits 38:39 of the user status
        // fields, filter them out:
        // - 38 = Command Echo Bit - Indicates that the GCR command travelled around the ring and
        //        returned to the GCR Main. Cleared on next write to this addr.
        // - 39 = Valid/Done Bit - Indicates that read data is valid or that a write has completed.
        //        Cleared on next write to this addr.
        if ((i_scomAddr & 0x8000000008010C3FULL) == 0x8000000008010C3FULL)
        {
            o_indirectStatus &= 0xFFFFFFFFFCFFFFFFULL;
        }

        return o_indirectStatus;
    }

    // See header file for function description
    uint32_t odyssey_scominfo_fixChipUnitScomAddrOrTarget(const odysseyChipUnits_t i_odysseyCU,
            const uint8_t i_ecLevel,
            const uint32_t i_targetChipUnitNum,
            const uint64_t i_scomaddr,
            uint64_t& o_modifiedScomAddr,
            odysseyChipUnits_t& o_odysseyCU,
            uint32_t& o_modifiedChipUnitNum,
            const odysseyTranslationMode_t i_mode)
    {
        uint32_t l_rc = 0;
        o_modifiedScomAddr = i_scomaddr;
        o_odysseyCU = i_odysseyCU;
        o_modifiedChipUnitNum = i_targetChipUnitNum;
        return l_rc;
    }

    // See header file for function description
    uint8_t odyssey_validateChipUnitNum(const uint8_t i_chipUnitNum,
                                        const odysseyChipUnits_t i_chipUnitType)
    {
        uint8_t l_rc = 0;
        uint8_t l_index;

        for (l_index = 0;
             l_index < (sizeof(odysseyChipUnitDescriptionTable) / sizeof(odyssey_chipUnitDescription_t));
             l_index++)
        {
            // Looking for input chip unit type in table
            if (i_chipUnitType == odysseyChipUnitDescriptionTable[l_index].enumVal)
            {
                // Found a match, check input i_chipUnitNum to be <= max chip unit num
                // for this unit type
                if (i_chipUnitNum > odysseyChipUnitDescriptionTable[l_index].maxChipUnitNum)
                {
                    l_rc = 1;
                }

                // Additional check for PERV targets, where there are gaps between instances
                else if (i_chipUnitType == ODYSSEY_PERV_CHIPUNIT)
                {
                    if (i_chipUnitNum > MAX_ODYSSEY_PERV_CHIPUNIT) //invalid for pervasive target
                    {
                        l_rc = 1;
                    }
                }

                break;
            }
        }

        // Can't find i_chipUnitType in table
        if ( l_index >= (sizeof(odysseyChipUnitDescriptionTable) / sizeof(odyssey_chipUnitDescription_t)) )
        {
            l_rc = 1;
        }

        return (l_rc);
    }

} // extern "C"

#undef ODYSSEY_SCOMINFO_C
