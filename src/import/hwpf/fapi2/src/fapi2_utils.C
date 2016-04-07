/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/src/fapi2_utils.C $                                */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file utils.C
 *  @brief Implements fapi2 utilities
 */
#include <fapi2_attribute_service.H>
#include <attribute_ids.H>
#include <return_code.H>
#include <plat_trace.H>
#include <target.H>

namespace fapi2
{

ReturnCode queryChipEcAndName(
    const Target < fapi2::TARGET_TYPE_PROC_CHIP |
    fapi2::TARGET_TYPE_MEMBUF_CHIP > & i_target,
    fapi2::ATTR_NAME_Type& o_chipName, fapi2::ATTR_EC_Type& o_chipEc )
{

    ReturnCode l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_target, o_chipName);

    if ( l_rc != FAPI2_RC_SUCCESS )
    {
        FAPI_ERR("queryChipEcFeature: error getting chip name");
    }
    else
    {
        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_target, o_chipEc);

        if ( l_rc != FAPI2_RC_SUCCESS )
        {
            FAPI_ERR("queryChipEcFeature: error getting chip ec");
        }
    }

    return l_rc;
}
};
