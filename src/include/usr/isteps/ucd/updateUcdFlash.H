/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/ucd/updateUcdFlash.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __UPDATE_UCD_FLASH_H
#define __UPDATE_UCD_FLASH_H

#include <targeting/common/target.H>
#include <errl/errlentry.H>

namespace POWER_SEQUENCER
{

namespace TI // Texas Instruments
{

namespace UCD // UCD series
{

/**
 *  @brief Updates a UCD target's flash image
 *
 *  @param[in] i_pUcd UCD's target; must not be nullptr
 *  @param[in] i_pFlashImage pointer to the start of the data flash
 *      image (its table of contents).  Must not be nullptr.
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Successfully updated the UCD's data flash image
 *  @retval !nullptr Failed to update the UCD's data flash image.  Handle
 *      points to valid error log
 */
errlHndl_t updateUcdFlash(
          TARGETING::Target* i_pUcd,
    const void*              i_pFlashImage);

} // End namespace POWER_SEQUENCER

} // End namespace TI

} // End namespace UCD

#endif // __UPDATE_UCD_FLASH_H

