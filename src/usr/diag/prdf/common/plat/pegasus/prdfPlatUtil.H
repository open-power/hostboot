/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPlatUtil.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#ifndef PRDF_PLATUTIL_H
#define PRDF_PLATUTIL_H

/**
 * @file  prdfPlatUtil.H
 * @brief Intended for util functions common between all platforms.
 */

namespace PRDF
{

struct STEP_CODE_DATA_STRUCT;
namespace PlatUtil
{

/**
 * @return  True, if it is an OPAL based system in field environment, false
 *          otherwise.
 */
bool ignoreErrorForSapphire( STEP_CODE_DATA_STRUCT & i_stepcode );

} // namespace PlatUtil

} // namespace PRDF
#endif
