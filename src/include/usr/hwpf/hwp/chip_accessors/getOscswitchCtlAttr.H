/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/chip_accessors/getOscswitchCtlAttr.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: getOscswitchCtlAttr.H,v 1.1 2014/05/23 01:23:14 whs Exp $
/**
 *  @file getOscswitchCtlAttr.H
 *
 *  @brief Accessor for providing the ATTR_OSCSWITCH_CTLx attributes
 */

#ifndef _HWP_GETOSCSWITCHCNTL
#define _HWP_GETOSCSWITCHCNTL

#include <fapi.H>

namespace fapi
{
    namespace getOscswitchCtl
    {
        // Attributes supported
        enum Attr
        {
            CTL0    = 0x00,  // ATTR_OSCSWITCH_CTL0
            CTL1    = 0x01,  // ATTR_OSCSWITCH_CTL1
            CTL2    = 0x02,  // ATTR_OSCSWITCH_CTL2
        };

        // Oscswitch control data
        struct OSCSWITCH_CTL_DATA
        {
            ATTR_NAME_Enum l_CHIP_TYPE;
//          uint8_t        l_CHIP_EC;  // can be added if needed
            uint32_t       l_CTL0;
            uint8_t        l_CTL1;
            uint32_t       l_CTL2;
         };

        // This structure could be generated from engineering data as
        // there are more systems with redundant clocks or if values
        // become EC specific
        const OSCSWITCH_CTL_DATA OSCSWITCH_CTL_DATA_array []=
        {
            {   // Entry if there are no redundant clocks
                ENUM_ATTR_NAME_NONE,
                0x0080,
                0x00,
                0x00,
            },
            {   // Entry for Brazos
                ENUM_ATTR_NAME_VENICE,
                0x0A02,
                0x2E,
                0x00,
            }
        };

    }
}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getOscswitchCtlAttr_FP_t)
                         (const fapi::Target &,
                          const fapi::getOscswitchCtl::Attr,
                          void *,
                          const size_t);

extern "C"
{
/**
 * @brief This function is called by the FAPI_ATTR_GET macro when getting the
 *        ATTR_OSCSWITCH_CNTL0,1,2  attributes. It should not be called
 *        directly.
 *
 *  @param[in]  i_pProcTarget Processor Chip Target pointer
 *  @param[in]  i_attr        Attribute selection
 *  @param[out] o_pVal        Pointer to output variable
 *  @param[in]  i_len         Size of o_pVal
 */
fapi::ReturnCode getOscswitchCtlAttr (const fapi::Target & i_pProcTarget,
                                   const fapi::getOscswitchCtl::Attr i_attr,
                                   void * o_pVal,
                                   const size_t i_len);

}

#endif
