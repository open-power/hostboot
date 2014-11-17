/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaDataBundle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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

#ifndef __prdfCenMbaDataBundle_H
#define __prdfCenMbaDataBundle_H

/** @file  prdfCenMbaDataBundle.H
 *  @brief Contains the data bundle for a PRD Centaur MBA object.
 */

#include <prdfCenMbaDataBundle_common.H>

//------------------------------------------------------------------------------

#if defined(__HOSTBOOT_MODULE) && !defined(__HOSTBOOT_RUNTIME)
  #include <prdfCenMbaDataBundle_ipl.H>
#else
  #include <prdfCenMbaDataBundle_rt.H>
#endif

//------------------------------------------------------------------------------

namespace PRDF
{

/**
 * @brief  Wrapper function for the CenMbaDataBundle.
 * @param  i_mbaChip The MBA chip.
 * @return This MBA's data bundle.
 */
inline CenMbaDataBundle * getMbaDataBundle( ExtensibleChip * i_mbaChip )
{
    return static_cast<CenMbaDataBundle *>(i_mbaChip->getDataBundle());
}

} // end namespace PRDF

#endif // __prdfCenMbaDataBundle_H

