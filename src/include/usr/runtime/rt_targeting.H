/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/rt_targeting.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#ifndef __RT_TARGETING_H
#define __RT_TARGETING_H

#include <errl/errlentry.H>

namespace TARGETING
{
    class Target;
}

namespace RT_TARG
{
    typedef uint64_t rtChipId_t;

    enum
    {
        MEMBUF_ID_SHIFT = 4,    //!< CHIPID for MEMBUF is '<procid>MMMM'b
        MEMBUF_ID_MASK  = 0x0000000F, //!< valid position bits for MEMBUF

        PROC_TYPE        = 0x00000000, //!< PROC chip id type
        MEMBUF_TYPE      = 0x80000000, //!< MEMBUF chip id type
        CORE_TYPE        = 0x40000000, //!< CORE chip id type
        CHIPID_TYPE_MASK = 0xFF000000, //!< TYPE field
    };


    /**
     * @brief Convert a TARGETING::Target to an unit ID that can be used
     * in calls to the runtime host
     * @param[in] The HB TARGETING::Target
     * @param[out] Sapphire target id
     * @return an error handle on error
     */
    errlHndl_t getRtTarget(const TARGETING::Target* i_target,
                           rtChipId_t &o_targetId);

    /**
     * @brier Convert a runtime chip_id (target) into a TARGETING::Target
     * @param[in] The rt chipId
     * @param[out] The TARGETING::Target pointer
     * @return error log handle on error else NULL
     */
    errlHndl_t getHbTarget(rtChipId_t i_rt_chip_id,
                           TARGETING::Target *& o_target);

    /**
     * @brief Apply ATTR_TMP overrides to be available for run time
     */
    void applyTempOverrides( );

};

#endif
