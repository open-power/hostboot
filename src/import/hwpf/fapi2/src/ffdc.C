/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/src/ffdc.C $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2011,2015                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file ffdc.C
 *  @brief Implements the FirstFailureData class
 */

#include <plat_trace.H>
#include <ffdc.H>
#include <error_info.H>

namespace fapi2
{

///
/// @brief Add error information to this ffdc object
/// @param[in] A pointer to a list of objects
/// @param[in] A pointer to the list of entries
/// @param[in] The count of how many entries there are
/// @return void
///
template<>
void FirstFailureData<ReturnCode>::addErrorInfo(
    const void* const* i_pObjects,
    const ErrorInfoEntry* i_pEntries,
    const uint8_t i_count)
{
    FAPI_DBG("%d entries", i_count);

    for (uint32_t i = 0; i < i_count; i++)
    {
        i_pEntries[i].addErrorInfo(iv_info, i_pObjects);
    }
}



};
