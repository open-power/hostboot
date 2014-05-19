/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/pll_accessors/getPllRingInfoAttr.H $ */
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
// $Id: getPllRingInfoAttr.H,v 1.2 2014/01/17 23:50:25 whs Exp $
/**
 *  @file getPllRingInfoAttr.H
 *
 *  @brief Accessor HWP that gets attributes containing information about PLL
 *         Rings
 */

#ifndef _GETPLLRINGINFOATTR_
#define _GETPLLRINGINFOATTR_

#include <fapi.H>

namespace fapi
{
    // Attributes supported
    namespace getPllRingInfo
    {
        enum Attr
        {
            PROC_DMI_CUPLL_PFD360_OFFSET     = 0x01,
            PROC_DMI_CUPLL_REFCLKSEL_OFFSET  = 0x02,
            PROC_ABUS_CUPLL_PFD360_OFFSET    = 0x03,
            PROC_ABUS_CUPLL_REFCLKSEL_OFFSET = 0x04,
            MEMB_DMI_CUPLL_PFD360_OFFSET     = 0x05,
            MEMB_DMI_CUPLL_REFCLKSEL_OFFSET  = 0x06,
            MEMB_MEM_PLL_CFG_UPDATE_OFFSET   = 0x07,
        };
    }
}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getPllRingInfoAttr_FP_t) (
    const fapi::Target &,
    const fapi::getPllRingInfo::Attr,
    void *, const size_t);

extern "C"
{
/**
 * @brief Accessor HWP that gets attributes containing information about PLL
 *        Rings
 *
 * FAPI_ATTR_GET checks at compile time that the user's attribute is the correct
 * type. Assuming that the platform routes the access of the attribute to the
 * corresponding attribute enum defined in this file  then the size of o_pVal
 * will be correct, in the unlikely event of a misroute where the buffer is too
 * small, an error will be returned.
 *
 * @param[in]  i_chip Reference to Processor/Membuf Chip fapi target
 * @param[in]  i_attr The Attribute to get
 * @param[out] o_pVal Pointer to data buffer filled in with attribute data
 * @param[in]  i_len  Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode getPllRingInfoAttr(const fapi::Target & i_chip,
                                    const fapi::getPllRingInfo::Attr i_attr,
                                    void * o_pVal,
                                    const size_t i_len);
}

#endif
