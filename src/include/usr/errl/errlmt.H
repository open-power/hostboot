/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlmt.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
#ifndef ERRLMT_H
#define ERRLMT_H

/**
 *  @file errlmt.H
 *
 *  @brief Defines a class for the Failing Enclosure MTMS 'MT' section of an error log.
 *  This class manages those ErrlEntry data items that are destined to be
 *  saved in failing enclosure MTMS PEL section. See Platform Event Log and
 *  SRC PLDD §4.1.16, "Failing Enclosure MTMS Section".
 */

#include <trace/interface.H>

namespace ERRORLOG
{

class ErrlMT
{
public:

    /**
     *  @brief Data export size. Amount of flat storage (in bytes) required to
     *  store the object.
     *
     *  @return size in bytes
     */
    uint64_t flatSize() const
    {
        return SLEN;
    }

    /**
     *  @brief Data Export facility. Flatten the object into PEL for the
     *  'MT' user header section.
     *
     *  @param[in,out] io_pBuffer Pointer to buffer where flat data will go
     *  @param[in]     i_cbBuffer Size of the target buffer
     *  @return        uint64_t   The size of the flattened data in the output buffer
     *                            or 0 if i_cbBuffer is not large enough to hold the data
     */
    uint64_t flatten(void* const io_pBuffer, const uint64_t i_cbBuffer) const
    {
#ifdef __HOSTBOOT_MODULE
        assert(io_pBuffer, "ErrlMT::flatten: io_pBuffer is nullptr");
#endif

        extern trace_desc_t* g_trac_errl;
        uint64_t serialsize = 0;

        if (i_cbBuffer >= flatSize())
        {
            serialsize = flatSize();
            memcpy(io_pBuffer, &iv, serialsize);
        }
        else
        {
            TRACFCOMP(g_trac_errl, "ErrlMT::flatten: buffer too small");
        }

        return serialsize;
    }

    /**
     * @brief Deserialize the object from flag storage.
     *
     * @param[in] i_buffer Buffer to read from
     * @return    uint64_t Number of bytes consumed
     */
    uint64_t unflatten(const void* const i_buffer)
    {
        const auto hdr = static_cast<const pelFailingEnclosureMtmsSection_t*>(i_buffer);

        size_t flat_size = SLEN;

        memcpy(&iv, hdr, flat_size);

        return flat_size;
    }

    /**  @brief Set the component ID in the user header.
     *   The component ID in the user header identifies
     *   the component that committed the error log.
     *
     *   @param[in]  i_compId   component ID
     */
    void setComponentId(const compId_t i_compId)
    {
        iv.sectionheader.compId = i_compId;
    }

    /* @brief Set the machine type/model data in the MT section
     * @param[in] i_mtm The machine type/model
     */
    void setMTM(const char* const i_mtm)
    {
        set_errl_string(iv.mtms.mtm,
                        i_mtm,
                        false);  // Do not add a NULL-terminating character
    }

    /* @brief Set the Serial Number string in the MT section
     * @param[in] i_serial The serial number
     */
    void setSerial(const char* const i_serial)
    {
        set_errl_string(iv.mtms.serial,
                        i_serial,
                        false);  // Do not add a NULL-terminating character
    }

private:
     // size does not include that of the section header
    static const int VER = 1; // section version
    static const int SST = 0; // section subtype

    // Size of this section
    static const int SLEN = 0x1C;

    pelFailingEnclosureMtmsSection_t iv = {
        { ERRL_SID_FAILING_ENCLOSURE_MTMS,
          ErrlMT::SLEN,
          ErrlMT::VER,
          ErrlMT::SST,
          0 } // Component ID is zero until commit time
    };

    // Ensure that our serializable structure is as big as we say it is in
    // flatSize()
    static_assert(SLEN == sizeof(iv));

};

} // namespace

#endif //ERRLMT_H
