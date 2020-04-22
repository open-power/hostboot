/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/hbrt_target.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#ifndef __HBRT_TARGET_H
#define __HBRT_TARGET_H

#include <targeting/common/error.H>
#include <targeting/common/attributes.H>

namespace TARGETING
{
    typedef uint64_t rtChipId_t;

    static const TARGETING::ATTR_HBRT_HYP_ID_type HBRT_HYP_ID_UNKNOWN
       = 0xFFFFFFFFFFFFFFFFULL;

    struct ocmbMmioAddressRange_t {
        rtChipId_t hbrtId;  // Keep hbrtId as the first member of this struct
                            // there is some tricky casting that depends on this
        uint64_t mmioBaseAddr;
        uint64_t mmioEndAddr;
        uint8_t  accessSize;

        ocmbMmioAddressRange_t() :
        hbrtId(0), mmioBaseAddr(0), mmioEndAddr(0), accessSize(4)
        {}

        ocmbMmioAddressRange_t(uint64_t id, uint64_t start_addr, uint64_t end_addr, uint8_t io_size) :
        hbrtId(id), mmioBaseAddr(start_addr), mmioEndAddr(end_addr), accessSize(io_size)
        {}
    } __attribute__((packed));

     /**
     * @brief Convert a TARGETING::Target to an unit ID that can be used
     * in calls to the runtime host
     * @param[in] The HB TARGETING::Target
     * @param[out] Hypervisor target id
     * @return an error handle on error
     */
    errlHndl_t getRtTarget(const TARGETING::Target* i_target,
                                     rtChipId_t &o_targetId);

     /**
     * @brief Takes a TARGETING::Target and passes back a vector of ocmbMmioAddressRange_t
     *        structs, one for each memory mapped i/o space associated with a given memory
     *        target.
     * @param[in] The HB Memory TARGETING::Target
     * @param[out] Vector of structs representing the mmio spaces associated with
     *             the given memory target
     * @return an error handle on error
     */
    errlHndl_t getMemTargetMmioInfo ( TARGETING::Target * i_memTarget,
                                      std::vector<TARGETING::ocmbMmioAddressRange_t>& o_ocmbMmioSpaces);

}

#endif