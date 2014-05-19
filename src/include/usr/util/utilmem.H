/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utilmem.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2014              */
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
#ifndef UTILMEM_H
#define UTILMEM_H

/**
 * @file utilmem.H
 *
 * @brief Memory Stream manipulation
 *
 * Used for creating and manipulating memory streams
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// Utility Includes
#include <util/utilstream.H>

/*****************************************************************************/
// Forwards
/*****************************************************************************/
class UtilFile;

//*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/
/*****************************************************************************/
// Memory Stream class
/*****************************************************************************/
/**
 *  @brief     Utility Memory Stream class
 *
 *  Used for memory streams
 *
 */
class UtilMem : public UtilStream
{
public:

    /**
     *  @brief Default constructor
     *
     *  Initializes internals of the memory stream object, setting autogrow
     *  to true.
     *
     */
    UtilMem();

    /**
     *  @brief Constructor with size parameter
     *
     *  Initializes internals of the memory stream object and allocates a
     *  stream of the specified size.
     *
     */
    UtilMem(uint32_t i_size);

    /**
     *  @brief Constructor with buffer pointer and size parameter
     *
     *  Initializes internals of the memory stream object.
     *
     */
    UtilMem(void * i_buffer, uint32_t i_size);

    /**
     *  @brief Assignment operator
     *
     */
    UtilMem & operator = ( const UtilMem & i_right );

    /**
     *  @brief UtilFile assignment
     *
     *  Easy way to transfer data between a file and a memory object
     *
     *  The file object is read from the current position up to the
     *  size of the mem object.
     *
     *  @return UtilMem reference
     *
     *  @note Errors are reported by getLastError()
     *
     */
    UtilMem & operator = ( UtilFile & i_right );

    /**
     *  @brief Default destructor
     *
     *
     */
    virtual ~UtilMem();

    /**
     *  @brief Reads data from current position of the stream
     *
     *  Reads data from the current postion of the stream for the
     *  specified number of bytes.
     *
     */
    uint32_t read(
        void *        o_buffer, ///< Buffer data is read into
        uint32_t      i_size    ///< Size in bytes of data to be read
        );

    /**
     *  @brief Writes data to current position of the stream
     *
     *  Writes data to the current postion of the stream for the
     *  specified number of bytes.
     *
     */
    uint32_t write(
        const void *i_buffer,   ///< Source buffer data is written from
        uint32_t    i_size      ///< Size in bytes of data to be written
        );

    /**
     *  @brief Seek to the specified position in the stream
     *
     *  Performs a seek based on the specified position and offset.
     *
     */
    uint32_t seek(
        int         i_pos,      ///< Seek offset in bytes
        whence    i_whence      ///< Position to seek from
        );

    /**
     *  @brief Return the current size of the stream
     *
     *  Returns the current size of the stream.
     *
     */
    uint32_t size() const
    {
        return iv_size;
    }

    /**
     *  @brief Change size
     *
     *  Change the size of the memory object to the requested
     *  size.  The data is maintained.
     *
     */
    void changeSize( uint32_t i_size );

    /**
     *  @brief Set autoGrow flag as specified
     *
     *  Sets the autoGrow flag as specified.
     *
     */
    void autoGrow(bool i_flag);

    /**
     *  @brief Query the autoGrow flag
     *
     *  Queries the autoGrow flag.
     *
     */
    bool autoGrow();

    /**
     *  @brief Base pointer access
     *
     *  Obtains a constant pointer to the data
     *
     */
    const void * base() const
    {
        return iv_memStart;
    }

    /**
     *  @brief Reset the the object
     *
     *  1. Clears the memory to the specified value
     *  2. Sets the offest back to 0
     *  3. Deletes any pending errors
     */
    void reset( int i_c = 0 );

private:

    uint8_t *   iv_memStart;
    uint32_t    iv_offset;
    uint32_t    iv_size;
    bool        iv_autoGrow;
    bool        iv_autoCleanup;

};

/*****************************************************************************/
// I n l i n e s
/*****************************************************************************/

/*****************************************************************************/
// Set the autoGrow flag
/*****************************************************************************/
inline void UtilMem::autoGrow(bool i_flag)
{
    if ( iv_autoCleanup )
    {
        // Can only autogrow if the memory is ours
        iv_autoGrow = i_flag;
    }
}

/*****************************************************************************/
// Query the autoGrow flag
/*****************************************************************************/
inline bool UtilMem::autoGrow()
{
    return iv_autoGrow;
}

#endif //UTILMEM_H
