/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/spd_accessors/getSpdAttrAccessor.H $ */
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
/**
 *  @file getSpdAttrAccessor.H
 *
 *  @brief Accessor HWP that gets DDR neutral DIMM SPD FAPI Attributes
 *
 *  Handles DDR neutral attributes where raw SPD data cannot be returned,
 *  either:
 *  - The raw data has a different meaning between DDR3 and DDR4.
 *  - The raw data has a different size between DDR3 and DDR4.
 *  - The attribute does not map to a single field in both DDR3 and DDR4.
 *
 *  This Accessor HWP reads the DDR specific attribute and figures out the
 *  data to return for the DDR neutral attribute.
 */

#ifndef _GETSPDDATAACCESSOR_
#define _GETSPDDATAACCESSOR_

#include <fapi.H>

namespace fapi
{
    // Attributes supported
    namespace getSpdAttr
    {
        enum Attr
        {
            SPD_SDRAM_BANKS             = 0x01,
            SPD_MODULE_NOMINAL_VOLTAGE  = 0x02,
            SPD_CAS_LATENCIES_SUPPORTED = 0x03,
            SPD_MODULE_REVISION_CODE    = 0x04,
        };
    }
}

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getSpdAttrAccessor_FP_t) (
    const fapi::Target &,
    const fapi::getSpdAttr::Attr,
    void *,
    const size_t);

extern "C"
{
/**
 * @brief Accessor HWP that gets DDR neutral DIMM SPD FAPI Attribute data
 *
 * FAPI_ATTR_GET checks at compile time that the user's attribute is the correct
 * type. Assuming that the platform routes the access of the attribute to the
 * corresponding attribute enum defined in this file (e.g. ATTR_SPD_SDRAM_BANKS
 * -> SPD_SDRAM_BANKS) then the size of o_pVal will be correct, in the unlikely
 * event of a misroute where the buffer is too small, an error will be returned.
 *
 * @param[in]  i_dimm Reference to DIMM fapi target
 * @param[in]  i_attr The Attribute to get
 * @param[out] o_pVal Pointer to data buffer filled in with attribute data
 * @param[in]  i_len  Size of o_pVal
 *
 * @return fapi::ReturnCode Indicating success or error
 */
fapi::ReturnCode getSpdAttrAccessor(const fapi::Target & i_dimm,
                                    const fapi::getSpdAttr::Attr i_attr,
                                    void * o_pVal,
                                    const size_t i_len);
}

#endif
