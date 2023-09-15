/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_getCodeLevels.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2023                        */
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
#ifndef _SBE_GET_CODE_LEVELS_H
#define _SBE_GET_CODE_LEVELS_H

#include <ody_sbe_utils.H>

namespace SBEIO
{
    /**
     * @brief Get the code levels of the SBE via FIFO
     *
     *    sets ATTR_SBE_NUM_CAPABILITIES
     *    sets ATTR_SBE_NUM_IMAGES
     *
     * @param[in]  i_target    Target with SBE to get code levels from
     * @param[out] o_response  data from get code levels
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t getFifoSbeCodeLevels(TARGETING::TargetHandle_t i_target,
                                     getCodeLevelsResponse_t &o_response);
}

#endif
