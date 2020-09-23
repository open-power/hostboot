/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errled.H $                               */
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
#ifndef ERRLED_H
#define ERRLED_H

/**
 *  @file errled.H
 *
 *  @brief A class for the 'ED' section of an error log.
 *  This class manages those ErrlEntry data items that are destined
 *  to be saved in the ED PEL section.
*/

#include <errl/errlentry.H>
#include <errl/errlsctnhdr.H>

namespace ERRORLOG
{


class ErrlED
{

    // ErrlEntry may access private elements of this class.  Data items that
    // you would expect to be part of ErrlEntry are actually instance data
    // in this class.
    friend class ErrlEntry;

private:

    /**
     *  @brief Data export size. Amount of flat storage (in bytes) required to
     *  store the object.
     *
     *  @return size in bytes
     */
    uint64_t flatSize() const;

    /**
     *  @brief Data Export facility. Flatten the object into PEL for the
     *  'ED' section.
     *
     *  @param[in,out] io_pBuffer Pointer to buffer where flat data will go.
     *  @param[in]     i_cbBuffer Count of bytes in target buffer
     *  @return        uint64_t  The size of the flattened data in the output buffer
     *
     */
    uint64_t flatten(  void * io_pBuffer, const uint64_t i_cbBuffer );

    /**
     * @brief Import data
     * @param[in] i_buf, the pointer to the flattened data
     * @return number of bytes consumed
     */
    uint64_t unflatten( const void * i_buf );

    /**  @brief Set the component ID into the ED.
     *   Only should be called from ErrlEntry instance.
     *
     *   @param[in]  i_compId   component ID
     */
    void setComponentId( compId_t i_compId );

    static const int VER = 1; // section version
    static const int SST = 0; // section subtype
    static const int SLEN = 0xD4; // 212 total bytes
                                  // 8 section header
                                  // 4 creatorId
                                  // 200 data

    pelEDHeaderSection_t iv = {
        pelSectionHeader_t { ERRL_SID_EXTENDED_USER_DEFINED,
                             ErrlED::SLEN,
                             ErrlED::VER,
                             ErrlED::SST,
                             0 } // Component ID is zero until commit time
    };

    static_assert(SLEN == sizeof(iv));

};


/*****************************************************************************/
// Export data size

inline uint64_t ErrlED::flatSize() const
{
    return sizeof(iv);
}

/*****************************************************************************/
// For user headers, the comp ID represents the committing component.

inline void ErrlED::setComponentId( const compId_t i_compId )
{
  iv.sectionheader.compId = i_compId;
}

} // namespace

#endif //ERRLED_H
