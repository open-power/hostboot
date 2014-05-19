/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/prdfTargetFwdRef.H $                 */
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

/** @file  prdfTargetFwdRef.H
 *  @brief Forward references for the targeting code.
 *
 *  Allows the ability to use things like TargetHandle_t in header files without
 *  being required to include targeting/common/target.H.
 */

#ifndef __prdfTargetFwdRef_H
#define __prdfTargetFwdRef_H

namespace TARGETING
{
    class Target;

    typedef const Target* ConstTargetHandle_t;
    typedef       Target* TargetHandle_t;
}

#endif // __prdfTargetFwdRef_H

