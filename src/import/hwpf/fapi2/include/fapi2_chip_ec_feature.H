/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/fapi2_chip_ec_feature.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file fapi2_chip_ec_feature.H
///
/// @brief Defines the queryChipEcFeature function that allows HWPs to
///        query if a particular chip has a feature determined by its EC level.
///        Chip EC features are specified in attribute XML files and the
///        queryChipEcFeature function implementation is auto-generated.
///        HWPs should not call this function directly, but should access the
///        corresponding HWPF attribute using FAPI_ATTR_GET
///

#ifndef FAPI2CHIPECFEATURE_H_
#define FAPI2CHIPECFEATURE_H_

#include <stdint.h>
#include <target.H>
#include <return_code.H>
#include <attribute_ids.H>

namespace fapi2
{

///
/// @brief Queries if a Chip has a particular feature
///
/// This should only be called by FAPI during the processing of a FAPI_ATTR_GET
/// for a Chip EC Feature attribute
///
/// @param[in]  i_id         Attribute ID of the Chip EC Feature
/// @param[in]  i_target     Reference to chip target
/// @param[out] o_hasFeature Set to 1 if chip has feature else 0
/// @return ReturnCode. Zero on success, else platform specified error
///
template< TargetType K >
ReturnCode queryChipEcFeature(AttributeId i_id,
                              const Target<K>& i_target,
                              uint8_t& o_hasFeature);
}

#endif
