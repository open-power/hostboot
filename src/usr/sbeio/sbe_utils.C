/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_utils.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
extern trace_desc_t* g_trac_sbeio;

#define VIRTUAL_CHIPLET_ID_BASE_MCS_TARGET_TYPE (0x80)

namespace SBEIO
{
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
                sbeType = SBE_TARGET_TYPE_PROC;
                break;
            }
            case(TARGETING::TYPE_EX):
            {
                sbeType = SBE_TARGET_TYPE_EX;
                break;
            }
            case(TARGETING::TYPE_PERV):
            case(TARGETING::TYPE_XBUS):
            case(TARGETING::TYPE_MCBIST):
            case(TARGETING::TYPE_OBUS):
            case(TARGETING::TYPE_PCI):
            case(TARGETING::TYPE_L2):
            case(TARGETING::TYPE_L3):
            case(TARGETING::TYPE_L4):
            case(TARGETING::TYPE_CORE):
            {
                sbeType = SBE_TARGET_TYPE_PERV;
                break;
            }
            case(TARGETING::TYPE_MCS):
            {
                sbeType = SBE_TARGET_TYPE_MCS;
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