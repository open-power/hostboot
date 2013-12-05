/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/pll_accessors/getPllRingInfoAttr.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: getPllRingInfoAttr.H,v 1.1 2013/12/05 18:23:29 mjjones Exp $
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
