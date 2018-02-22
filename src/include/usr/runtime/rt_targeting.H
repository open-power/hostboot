/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/runtime/rt_targeting.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2018                        */
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
     * @brief Convert a runtime chip_id (target) into a TARGETING::Target
     * @param[in] The rt chipId
     * @param[out] The TARGETING::Target pointer
     * @return error log handle on error else NULL
     */
    errlHndl_t getHbTarget(rtChipId_t i_rt_chip_id,
                           TARGETING::Target *& o_target);

    /**
     * @brief Save/Restore attribute values from current Reserved Memory data
     * into new LID Structure data
     * @param[in] Pointer to current Reserved Memory targeting binary data
     * @param[in/out] Pointer to new LID Structure targeting binary data
     * @param[out] Error log userdata2 value associated with non-zero rtn code
     * @return nullptr on success, else error log
     */
    errlHndl_t saveRestoreAttrs(void *i_rsvdMemPtr,
                                void *io_lidStructPtr,
                                uint64_t& o_userdata2);

    /**
     * @brief Validate LID Structure against Reserved Memory.  Check that the
     * TargetingHeader eyecatchers are valid, that the TargetingHeader number of
     * sections match, and that the types and sizes of each TargetingSection
     * match.
     * @param[in] Pointer to new LID Structure targeting binary data
     * @param[in] Pointer to current Reserved Memory targeting binary data
     * @param[out] Total size of all sections in the new lid
     * @param[out] Error log userdata2 value associated with non-zero rtn code
     * @return nullptr on success, else error log
     */
    errlHndl_t validateData(void *i_lidStructPtr,
                            void *i_rsvdMemPtr,
                            size_t& o_lidTotalSize,
                            uint64_t& o_userdata2);

    /**
     * @brief Apply ATTR_TMP overrides to be available for run time
     */
    void applyTempOverrides( );

};

#endif
