/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/runtime/rt_targeting.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
#include <targeting/common/hbrt_target.H>

namespace TARGETING
{
    class Target;
}

namespace RT_TARG
{

    enum
    {
        // @TODO RTC 244718
        // Until all MEMBUF references are removed, map OCMB and MEMBUF to the
        // same values. All new/updated code should use OCMB* instead of
        // MEMBUF*
        OCMB_ID_SHIFT = 4,            //!< CHIPID for OCMB is '<procid>XXXX'b
        OCMB_ID_MASK  = 0x0000000F,   //!< valid position bits for OCMB

        MEMBUF_ID_SHIFT = 4,          //!< CHIPID for MEMBUF is '<procid>XXXX'b
        MEMBUF_ID_MASK  = 0x0000000F, //!< valid position bits for MEMBUF
    };

    /**
     * @brief Save/Restore attribute values from current Reserved Memory data
     * into new LID Structure data
     * @param[in] Pointer to current Reserved Memory targeting binary data
     * @param[in/out] Pointer to new LID Structure targeting binary data
     * @param[in] Instance, ie, Node ID
     * @return nullptr on success, else error log
     */
    errlHndl_t saveRestoreAttrs(void *i_rsvdMemPtr,
                                void *io_lidStructPtr,
                                uint8_t i_instance);

    /**
     * @brief Validate LID Structure against Reserved Memory.  Check that the
     * TargetingHeader eyecatchers are valid, that the TargetingHeader number of
     * sections match, and that the types and sizes of each TargetingSection
     * match.
     * @param[in] Pointer to new LID Structure targeting binary data
     * @param[in] Pointer to current Reserved Memory targeting binary data
     * @param[out] Total size of all sections in the new lid
     * @return nullptr on success, else error log
     */
    errlHndl_t validateData(void *i_lidStructPtr,
                            void *i_rsvdMemPtr,
                            size_t& o_lidTotalSize);

    /**
     * @brief Apply ATTR_TMP overrides to be available for run time
     */
    void applyTempOverrides( );

};

#endif
