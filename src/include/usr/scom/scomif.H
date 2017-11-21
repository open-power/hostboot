/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scom/scomif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#ifndef __SCOMIF_H
#define __SCOMIF_H

namespace SCOM
{

/**
 * @brief This function translates a relative scom address
 *        to an absolute scom address
 *
 * @param[in]           i_target         SCom target
 * @param[in|out]       io_addr          SCom address
 * @param[out]          o_needsWakeup    Enable SW before scom
 * @param[in]           i_opMode         Defaults to 0 (Standard)
 * @return              errlHndl_t
 */
errlHndl_t scomTranslate(TARGETING::Target * &i_target,
                         uint64_t & io_addr,
                         bool & o_needsWakeup,
                         uint64_t i_opMode = 0);

#ifndef __HOSTBOOT_RUNTIME
/**
 * @brief Enable scoms to all cores for multicast workaround
 */
void enableSlaveCoreMulticast( void );

/**
 * @brief Enable scoms to the memory chiplets for multicast workaround
 */
void enableMemChipletMulticast( void );
#endif

};  // end namespace SCOM

#endif  // end __SCOMIF_H
