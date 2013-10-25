/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilmem.C $                                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file utilmem.C
 *
 * @brief   Stream manipulation
 *
 * Used for creating and manipulating streams
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

#include <sys/task.h>
#include <util/utilmem.H>
#include <util/utilfile.H>
#include <util/util_reasoncodes.H>
#include <errl/errlentry.H>

#include "utilbase.H"

using namespace Util;
using namespace ERRORLOG;

/*****************************************************************************/
// Default Constructor
/*****************************************************************************/
UtilMem::UtilMem()
: iv_memStart( 0 ), iv_offset( 0 ), iv_size( 0 ), iv_autoGrow( true ),
  iv_autoCleanup( true )
{
    UTIL_DT("I> UtilMem: Default Constructor, no memory");
}

/*****************************************************************************/
// Constructor with Size parameter
/*****************************************************************************/
UtilMem::UtilMem(uint32_t i_size)
: iv_memStart( 0 ), iv_offset( 0 ), iv_size( i_size ), iv_autoGrow( false ),
  iv_autoCleanup( true )
{
    UTIL_DT("I> UtilMem: Memory size constructor: %i, p=%p",
            i_size,iv_memStart);
    iv_memStart = static_cast<uint8_t *>(malloc(i_size));
    reset(0);
}

/*****************************************************************************/
// Constructor with Buffer and Size parameters
/*****************************************************************************/
UtilMem::UtilMem(void * i_buffer, uint32_t i_size)
: iv_memStart(static_cast<uint8_t*>(i_buffer)), iv_offset( 0 ),
  iv_size( i_size ), iv_autoGrow( false ), iv_autoCleanup( false )
{
    UTIL_DT("I> UtilMem: Foreign buffer constructor: %i, p=%p",
            i_size,i_buffer);
}


/*****************************************************************************/
// Assignment operator
/*****************************************************************************/
UtilMem & UtilMem::operator = ( const UtilMem & i_right )
{
    if ( &i_right != this )
    {
        // Base assignment
        UtilStream::operator=( i_right );

        // Cleanup
        if ( iv_autoCleanup )
        {
            free(iv_memStart);
        }

        // Setup
        iv_offset = i_right.iv_offset;
        iv_size = i_right.iv_size;
        iv_autoGrow = i_right.iv_autoGrow;
        iv_autoCleanup = i_right.iv_autoCleanup;

        if ( i_right.iv_autoCleanup )
        {
            iv_memStart = static_cast<uint8_t*>(malloc( i_right.iv_size ));
            memcpy(iv_memStart,i_right.iv_memStart,iv_size);
        }
        else
        {
            UTIL_FT("W> UtilMem: Assignment results in 2 Interfaces to "
                    "1 buffer, p=%p", i_right.iv_memStart);
            iv_memStart = i_right.iv_memStart;
        }


        // Trace
        UTIL_DT("I> UtilMem: dst=%p,offset=%i,size=%i,autogrow=%s,autoclean=%s",
                iv_memStart,iv_offset,iv_size,UTIL_BOOL_ALPHA(iv_autoGrow),
                UTIL_BOOL_ALPHA(iv_autoCleanup));

    }

    return *this;

}

/*****************************************************************************/
// UtilFile assignment
/*****************************************************************************/
UtilMem & UtilMem::operator = ( UtilFile & i_right )
{
    UtilFile & l_file = i_right;

    l_file.read( iv_memStart, iv_size );

    return *this;
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
UtilMem::~UtilMem()
{
    UTIL_DT("I> UtilMem: Destructor: p=%p,size=%i,autoclean=%s",
            iv_memStart,iv_size,UTIL_BOOL_ALPHA(iv_autoCleanup));

    if (iv_autoCleanup)
    {
        free(iv_memStart);
        iv_memStart = 0;
    }
}

/*****************************************************************************/
// Read the file
/*****************************************************************************/
uint32_t UtilMem::read(
    void *      o_buffer,
    uint32_t    i_size
    )
{
    ReasonCode      l_erc = UTIL_ERC_NONE;
    uint32_t        l_rc = 0;

    if ( ! iv_memStart )                    // Invalid pointer
    {
        UTIL_FT("E> UtilMem: Bad memory receive pointer, can't read");

        /*@
         * @errortype
         * @moduleid            Util::UTIL_MOD_MEM_READ
         * @reasoncode          Util::UTIL_ERC_BAD_PTR
         * @userdata1[0:31]     Task ID.
         * @userdata1[31:64]    End of File (boolean)
         * @userdata2           Address of memory buffer.
         * @devdesc             Bad memory pointer recieved.
         */
        l_erc = UTIL_ERC_BAD_PTR;
    }
    else if ( iv_eof )                      // Not at EOF
    {
        UTIL_FT("E> UtilMem: Stream is at end of file");

        /*@
         * @errortype
         * @moduleid            Util::UTIL_MOD_MEM_READ
         * @reasoncode          Util::UTIL_ERC_EOF
         * @userdata1[0:31]     Task ID.
         * @userdata1[31:64]    End of File (boolean)
         * @userdata2           Address of memory buffer.
         * @devdesc             End of file reached.
         */
        l_erc = UTIL_ERC_EOF;
    }
    else if ( i_size && ! iv_lastError )    // Size > 0 && no errors
    {
        l_rc = i_size;

        if ( ( iv_offset + i_size )  > iv_size )
        {
            // Recalculate i_size
            l_rc = iv_size - iv_offset;

            // Set EOF
            iv_eof = true;
            l_erc = UTIL_ERC_EOF;
        }

        // Copy memory
        memcpy( o_buffer, (iv_memStart + iv_offset), l_rc );

        // Set the new current position
        iv_offset += l_rc;

    }


    if ( iv_lastError == 0 && l_erc != UTIL_ERC_NONE )
    {
        UTIL_FT("E> UtilMem: Read Failed, Buffer 0x%p, Offset 0x%X, Size 0x%X, "
                "Error Code 0x%X",
                iv_memStart, iv_offset, i_size, l_erc);

        iv_lastError = new ErrlEntry(
            ERRL_SEV_UNRECOVERABLE,
            UTIL_MOD_MEM_READ,
            l_erc,
            TWO_UINT32_TO_UINT64(task_gettid(), iv_eof),
            reinterpret_cast<uint64_t>(iv_memStart)
            );

        // collect some trace by default
        iv_lastError->collectTrace( UTIL_COMP_NAME );

    }
    else if ( iv_lastError )
    {
        UTIL_FT("E> UtilMem: Suspended on %p due to %x - %x",
                iv_memStart,iv_lastError->reasonCode(),
                iv_lastError->moduleId());
    }

    return l_rc;
}


/*****************************************************************************/
// Write the file
/*****************************************************************************/
uint32_t UtilMem::write(
    const void *i_buffer,
    uint32_t    i_size
    )
{
    ReasonCode      l_erc = UTIL_ERC_NONE;
    uint32_t        l_rc = 0;


    if ( ! iv_memStart && ! iv_autoGrow )   // Invalid pointer
    {
        UTIL_FT("E> UtilMem: Bad memory receive pointer, can't write");

        /*@
         * @errortype
         * @moduleid            Util::UTIL_MOD_MEM_WRITE
         * @reasoncode          Util::UTIL_ERC_BAD_PTR
         * @userdata1[0:31]     Task ID.
         * @userdata1[31:64]    End of File (boolean)
         * @userdata2           Address of memory buffer.
         * @devdesc             Bad memory pointer recieved.
         */
        l_erc = UTIL_ERC_BAD_PTR;
    }
    else if ( iv_eof && ! iv_autoGrow )     // Not at EOF
    {
        UTIL_FT("E> UtilMem: Stream is at end of file");

        /*@
         * @errortype
         * @moduleid            Util::UTIL_MOD_MEM_WRITE
         * @reasoncode          Util::UTIL_ERC_EOF
         * @userdata1[0:31]     Task ID.
         * @userdata1[31:64]    End of File (boolean)
         * @userdata2           Address of memory buffer.
         * @devdesc             End of file reached.
         */
        l_erc = UTIL_ERC_EOF;
    }
    else if ( i_size && ! iv_lastError )   // Size > 0 && no errors
    {
        l_rc = i_size;

        if ( ( iv_offset + i_size ) > iv_size )
        {
            if (iv_autoGrow)
            {
                iv_size = iv_offset + i_size;
                iv_memStart =
                    static_cast<uint8_t *>(realloc( iv_memStart, iv_size ));
            }
            else
            {
                // Recalculate i_size
                l_rc = iv_size - iv_offset;

                // Set EOF
                iv_eof = true;
                l_erc = UTIL_ERC_EOF;
            }
        }

        // Copy memory
        assert(NULL != iv_memStart); // Impossible condition, but BEAM flags.
        memcpy((iv_memStart + iv_offset), i_buffer, l_rc);

        // Set the new current position
        iv_offset += l_rc;

    }


    if ( iv_lastError == 0 && l_erc != UTIL_ERC_NONE )
    {
        UTIL_FT("E> UtilMem: Write Failed, Buffer 0x%p, Offset 0x%X, "
                "Size 0x%X, Error Code 0x%X",
                iv_memStart, iv_offset, i_size, l_erc);

        // Create an Error Log
        iv_lastError = new ErrlEntry(
            ERRL_SEV_UNRECOVERABLE,
            UTIL_MOD_MEM_WRITE,
            l_erc,
            TWO_UINT32_TO_UINT64(task_gettid(), iv_eof),
            reinterpret_cast<uint64_t>(iv_memStart)
            );

        // collect some trace by default
        iv_lastError->collectTrace( UTIL_COMP_NAME );

    }
    else if (iv_lastError)
    {
        UTIL_FT("E> UtilMem: Suspended on %p due to %x - %x",
                iv_memStart,iv_lastError->reasonCode(),
                iv_lastError->moduleId());
    }

    return l_rc;

}

/*****************************************************************************/
// Seek the file
/*****************************************************************************/
uint32_t UtilMem::seek(
    int     i_pos,
    whence  i_whence
    )
{
    ssize_t  l_offset = 0;
    uint32_t l_origin = 0;

    if (!iv_lastError)
    {
        if ( i_whence == START )
        {
            // Set the origin
            l_origin = 0;
        }
        else if (i_whence == CURRENT)
        {
            // Set the current position
            l_origin = iv_offset;
        }
        else if ( i_whence == END )
        {
            l_origin = iv_size;
        }

        l_offset = l_origin + i_pos;

        if (l_offset < 0)
        {
            // Set the offset to the beginning
            iv_offset = 0;
        }
        else if (l_offset > iv_size)
        {
            iv_offset = iv_size - 1;
        }
        else
        {
            iv_offset = l_offset;
        }

        // Clear the EOF indicator
        iv_eof = false;
    }
    else
    {
        UTIL_FT("E> UtilMem: Suspended on %p due to %x - %x",
                iv_memStart,iv_lastError->reasonCode(),
                iv_lastError->moduleId());
    }

    return iv_offset;
}

/*****************************************************************************/
// Change size
/*****************************************************************************/
void UtilMem::changeSize( uint32_t i_size )
{
    if ( iv_autoCleanup )
    {
        iv_offset = 0;
        iv_size = i_size;
        iv_memStart = static_cast<uint8_t*>(realloc( iv_memStart, iv_size ));
    }
}



/*****************************************************************************/
// Reset the object
/*****************************************************************************/
void UtilMem::reset( int i_c )
{
    memset( iv_memStart, i_c, iv_size );
    iv_offset = 0;
    iv_eof = 0;
    delete getLastError();
}

