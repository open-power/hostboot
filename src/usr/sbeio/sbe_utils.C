/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_utils.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
/**
* @file sbe_psudd.C
* @brief SBE PSU device driver
*/

#include <sbeio/sbe_utils.H>
#include <targeting/common/utilFilter.H>
extern trace_desc_t* g_trac_sbeio;

#define VIRTUAL_CHIPLET_ID_BASE_MCS_TARGET_TYPE (0x80)

using namespace TARGETING;

namespace SBEIO
{
    Target* getChipForPsuOp(Target *i_target)
    {
        Target* chip_for_psu_op = nullptr;
        switch(i_target->getAttr<ATTR_TYPE>())
        {
            case(TYPE_PROC):
            {
                chip_for_psu_op = i_target;
                break;
            }
            case(TYPE_OCMB_CHIP):
            {
                auto i2c_info = i_target->getAttr<ATTR_FAPI_I2C_CONTROL_INFO>();
                chip_for_psu_op = targetService().toTarget(i2c_info.i2cMasterPath);
                break;
            }
            default:
            {
                // try looking up the parent chip as a final effort
                chip_for_psu_op = const_cast<Target*>(getParentChip(i_target));

                if(chip_for_psu_op != nullptr)
                {
                    auto parent_chip_type = chip_for_psu_op->getAttr<ATTR_TYPE>();
                    if(parent_chip_type == TYPE_OCMB_CHIP)
                    {
                        // If we find TYPE_OCMB_CHIP as type of the parent chip
                        // recursively call this function again to find the parent processor
                        chip_for_psu_op = getChipForPsuOp(chip_for_psu_op);
                    }
                    else if(parent_chip_type != TYPE_PROC)
                    {
                        // If the parent chip is not an ocmb or a processor we don't
                        // know how to find the processor so return nullptr
                        chip_for_psu_op = nullptr;
                    }
              }
          }
        }
        return chip_for_psu_op;
    }

    /// @brief translates HB target types to SBE target type groups
    /// @param[in] i_hbTarget includes the HB target type
    /// @return SBE_TARGET_TYPES returns SBE_TARGET_TYPE_UNKNOWN in error
    SBE_TARGET_TYPES translateToSBETargetType(TARGETING::Target *i_hbTarget)
    {
        TRACDCOMP( g_trac_sbeio,
                   ENTER_MRK "entering translateToSBETargetType()");
        SBE_TARGET_TYPES sbeType;
        sbeType =  SBE_TARGET_TYPE_UNKNOWN;

        switch( i_hbTarget->getAttr<TARGETING::ATTR_TYPE>())
        {
            case(TARGETING::TYPE_PROC):
            {
                sbeType = SBE_TARGET_TYPE_PROC_CHIP;
                break;
            }
            case(TARGETING::TYPE_EQ):
            {
                sbeType = SBE_TARGET_TYPE_EQ;
                break;
            }
            case(TARGETING::TYPE_CORE):
            {
                sbeType = SBE_TARGET_TYPE_CORE;
                break;
            }
            case(TARGETING::TYPE_OCMB_CHIP):
            {
                sbeType = SBE_TARGET_TYPE_OCMB_CHIP;
                break;
            }
            case(TARGETING::TYPE_PERV):
            {
                sbeType = SBE_TARGET_TYPE_PERV;
                break;
            }
            default:
                TRACFCOMP( g_trac_sbeio,
                            ERR_MRK "translateToSBETargetType:>"
                            " Not supported Target type =%.8X ",
                            i_hbTarget->getAttr<TARGETING::ATTR_TYPE>() );
                break;
        }
        TRACDCOMP( g_trac_sbeio, EXIT_MRK "exiting translateToSBETargetType()");
        return sbeType;
    }

    /// @brief returns a ChipletID for a give target
    /// @param[in] i_hbTarget includes the HB target type
    /// @return: ChipletID for i_hbTarget target
    uint8_t getChipletIDForSBE(TARGETING::Target * i_hbTarget)
    {
        uint8_t l_chipletID = 0;
        TRACDCOMP( g_trac_sbeio, ENTER_MRK "entering getChipletIDForSBE()");

        //based on the Host to SBE Interface specification ver 0.70+
        switch( i_hbTarget->getAttr<TARGETING::ATTR_TYPE>())
        {
            case(TARGETING::TYPE_PROC):
            {   //not all targets will have CHIPLET_IDs
                l_chipletID = 0;
                break;
            }
            //MCS has a virtual Chiplet ID
            case (TARGETING::TYPE_MCS):
            {
                l_chipletID = VIRTUAL_CHIPLET_ID_BASE_MCS_TARGET_TYPE
                + static_cast<uint8_t>(i_hbTarget->
                getAttr<TARGETING::ATTR_CHIP_UNIT>());
                break;
            }
            default:
            {
                l_chipletID = static_cast<uint8_t>(i_hbTarget->
                getAttr<TARGETING::ATTR_CHIPLET_ID>());
                break;
            }
        }

        TRACDCOMP( g_trac_sbeio, EXIT_MRK "exiting getChipletIDForSBE()");
        return l_chipletID;
    }

}