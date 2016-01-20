/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/vpd_access_defs.H $                        */
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
///
/// @file vpd_access_defs.H
///
/// @brief VPD access definitions
///

#ifndef __VPDACCESSDEFS_H_
#define __VPDACCESSDEFS_H_

#include <stdint.h>

namespace fapi2
{

// @brief VPD accesss enums
enum MemVpdData
{
    MR, //! Memory phase rotator
    MT, //! Memory Termination
    MP, //! Memory Power related info
};

typedef MemVpdData MemVpdData_t;

/// @brief  Class representing required VPDInfo to be used in vpd collection.
/// @tparam T, the type of target this class is used with.
///
///  NOTE: to be defined by implementor
//
template<fapi2::TargetType T>
class VPDInfo;

}
#endif
