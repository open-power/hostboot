/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errleh.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#ifndef ERRLEH_H
#define ERRLEH_H

/**
 *  @file errleh.H
 *
 *  @brief Defines a class for the user header 'EH' section of an error log.
 *  This classes manages those ErrlEntry data items that are destined to be
 *  saved in the extended user header PEL section. See Platform Event Log and
 *  SRC PLDD §4.1.26, "Extended User Header Section Details".
 */

#include <assert.h>
#include <string.h>
#include <stdio.h>

#include <util/align.H>
#include <trace/interface.H>

#include "errlentry.H"
#include "errlsctnhdr.H"
#include "hberrltypes.H"

namespace ERRORLOG
{

class ErrlEH
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
        return sizeof(iv) - sizeof(iv.symptom_id) + iv.symptom_id_length;
    }

    /**
     *  @brief Data Export facility. Flatten the object into PEL for the
     *  'EH' user header section.
     *
     *  @param[in,out] io_pBuffer Pointer to buffer where flat data will go
     *  @param[in]     i_cbBuffer Size of the target buffer
     *  @return        uint64_t   The size of the flattened data in the output buffer
     */
    uint64_t flatten(void* const io_pBuffer, const uint64_t i_cbBuffer) const
    {
#ifdef __HOSTBOOT_MODULE
        assert(io_pBuffer, "ErrlEH::flatten: io_pBuffer is nullptr");
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
            TRACFCOMP(g_trac_errl, "ErrlEH::flatten: buffer too small");
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
        const auto hdr = static_cast<const pelExtendedUserHeaderSection_t*>(i_buffer);

        size_t flat_size = SLEN + hdr->symptom_id_length;

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

    /**
     * @brief Set the symptom ID in the EH header from the given SRC words.
     *
     * @param[in] i_refcode    The SRC reference code
     * @param[in] i_src_words  The binary SRC data
     * @param[in] i_word_count Number of SRC words
     */
    void setSymptomId(const char* const i_refcode,
                      const void* const i_src_words,
                      const uint64_t i_word_count)
    {
        // Clear out old symptom ID
        memset(iv.symptom_id, 0, sizeof(iv.symptom_id));

        // Put the reference code at the beginning of the symptom ID (8
        // characters) followed by an underscore
        strncat(iv.symptom_id, i_refcode, 8);
        strcat(iv.symptom_id, "_");

        // Hexify each SRC word and append it to the symptom ID
        for (uint64_t i = 0; i < i_word_count; ++i)
        {
            snprintf(iv.symptom_id + strlen(iv.symptom_id),
                     sizeof(iv.symptom_id) - strlen(iv.symptom_id),
                     "%.08X",
                     static_cast<const uint32_t*>(i_src_words)[i]);
        }

        // Spec requires this size to be a multiple of 4 (padded with zeroes).
        iv.symptom_id_length = ALIGN_4(strlen(iv.symptom_id));

        // Update section length
        iv.sectionheader.len = SLEN + iv.symptom_id_length;
    }

    /* @brief Set the machine type/model data in the EH section
     * @param[in] i_mtm The machine type/model
     */
    void setMTM(const char* const i_mtm)
    {
        set_string(iv.mtms.mtm, i_mtm);
    }

    /* @brief Set the Serial Number string in the EH section
     * @param[in] i_serial The serial number
     */
    void setSerial(const char* const i_serial)
    {
        set_string(iv.mtms.serial, i_serial);
    }

    /* @brief Set the Firmware Version string in the EH section
     * @param[in] i_firmware The firmware version string
     */
    void setFirmwareVersion(const char* const i_firmware)
    {
        set_string(iv.firmware, i_firmware);
    }

    /* @brief Set the Subsystem Version string in the EH section
     * @param[in] i_subsystem The subsystem version string
     */
    void setSubsystemVersion(const char* const i_subsystem)
    {
        set_string(iv.subsystem, i_subsystem);
    }

private:
    /* @brief Helper function to set the value of member string variables.
     * @param[out] o_array Array to set
     * @param[in] i_value  Value to assign to array
     *
     * This function will zero out the given array and set its contents to the
     * given value, without writing beyond the bounds of the array. If the given
     * value is too long, it will be truncated. The string in the output array
     * will always be zero-terminated.
     */
    template<uint64_t Size>
    uint64_t set_string(char(&o_array)[Size], const char* const i_value)
    {
        const uint64_t value_len = std::min(strlen(i_value), Size - 1);
        memset(o_array, 0, Size);
        memcpy(o_array, i_value, value_len);
        return value_len;
    }

     // size does not include that of the section header
    static const int VER = 1; // section version
    static const int SST = 0; // section subtype

    // This is the size of this section when the symptom ID is empty.
    static const int SLEN = 0x4C;

    pelExtendedUserHeaderSection_t iv = {
        { ERRL_SID_EXTENDED_HEADER,
          ErrlEH::SLEN, // length will be updated when the symptom ID is set
          ErrlEH::VER,
          ErrlEH::SST,
          0 } // Component ID is zero until commit time
    };

    // Ensure that our serializable structure is as big as we say it is in
    // flatSize()
    static_assert(SLEN == sizeof(iv) - sizeof(iv.symptom_id));
};

} // namespace

#endif //ERRLEH_H
