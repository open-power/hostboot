/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlsctn.H $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef ERRLSCTN_H
#define ERRLSCTN_H
/**
 *  @file errlsctn.H
 *
 *  @brief  Base class that abstracts a section in an error log.
 *          A section may be used to store unique data for the
 *          error such as FFDC, Software error information, etc...
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <errl/hberrltypes.H>
#include "errlsctnhdr.H"

namespace ERRORLOG
{

/**
 *  @brief Base class that abstracts a section in an error log object.
 */
class ErrlSctn
{

public:

    /**
     * @brief   Constructor
     *          Initializes the base object with section information
     *
     * @param[in]   i_compId     Component Id of the caller
     * @param[in]   i_sctnVer    A user supplied identifier which
     *                           classifies the data in the section
     * @param[in]   i_subSect    A user supplied sub section identifier
     *                           which classifies the data.  This in
     *                           conjunction with the version can be used
     *                           to decode the data.
     * @return void
     *
     */
    ErrlSctn(const compId_t i_compId,
             const uint8_t i_sctnVer,
             const uint8_t i_subSect);

    /**
     * @brief   Default destructor
     *
     * @return void
     */
    virtual ~ErrlSctn();

    /**
     *  @brief Get section's version
     *
     *  @return Section version (uint8_t)
     *
     */
    uint8_t sctnVer() const;

    /**
     *  @brief Get section's subsection type
     *
     *  @return Subsection type (uint8_t)
     *
     */
    uint8_t subSect() const;

    /**
     *  @brief Get section's component Id
     *
     *  @return Component Id of the section creator
     *
     */
    compId_t compId() const;


    /**
     *  @brief Appends data to the section
     *  Grows the section by the given amount
     *
     *  @param[in]  i_data      Pointer to data source
     *  @param[in]  i_size      Data size (bytes)
     *
     *  @return Size of new data or else zero on error.
     */
    uint64_t addData(const void *i_data, const uint64_t i_size);


    /**
     *  @brief Get flattened size. Typically called prior to flatten().
     *  Allocate space for the flat data, then call flatten().  These
     *  functions commonly used by ErrlManager when committing error
     *  logs.
     *
     *  @return size
     *
     */
    uint64_t flattenedSize();

    /**
     *  @brief Get flattened data.
     *
     *  @param[in,out] io_pBuffer  Pointer to memory where flattened
     *  error log will go.
     *  @param[in]     i_cbBuffer  Count of bytes of memory available
     *  at io_pBuffer.  Caller should ensure there is enough memory
     *  available by calling flattenedSize() first.
     *
     *  @return Count of bytes flattened.
     *
     */
    uint64_t flatten( void * io_pBuffer, const uint64_t i_cbBuffer );



private:

    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlSctn(const ErrlSctn& i_right);
    ErrlSctn& operator=(const ErrlSctn& i_right);

    // A section header object for this section.
    ErrlSctnHdr iv_ErrlSctnHdr;

    // Pointer to user-added data
    uint8_t*    iv_pData;

    // Count of bytes of user-added data
    uint64_t    iv_cbData;

};

//-----------------------------------------------------------------------
// In-line functions
//-----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint8_t ErrlSctn::sctnVer() const
{
    return iv_ErrlSctnHdr.iv_sctnVer;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint8_t ErrlSctn::subSect() const
{
    return iv_ErrlSctnHdr.iv_subSect;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline compId_t ErrlSctn::compId() const
{
    return iv_ErrlSctnHdr.iv_compId;
}




} // End namespace


#endif //ERRLSCTN_H

