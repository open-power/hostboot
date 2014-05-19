/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utilfile.C $                                     */
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
/**
  * @file utilfile.C
  *
  * @brief      Stream manipulation
  *
  * Used for creating and manipulating streams
  */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

#include <util/utilfile.H>
#include <util/utilmem.H>
#include <errl/errlentry.H>
#include <vfs/vfs.H>

#include "utilbase.H"

using namespace Util;
using namespace ERRORLOG;

static const char UTIL_FILE_INVALID_NM[] = "";

/*****************************************************************************/
// Default Constructor
/*****************************************************************************/
UtilFile::UtilFile()
: iv_filePathName(NULL), iv_contents()
{
    UTIL_DT("UtilFile: Default Constructor, no filename yet");
    FileName(UTIL_FILE_INVALID_NM);
}


/*****************************************************************************/
// Constructor
/*****************************************************************************/
UtilFile::UtilFile(const char * i_filePathName)
: iv_filePathName(NULL), iv_contents()
{
    UTIL_DT("UtilFile: File name constructor invoked");
    FileName(i_filePathName);
}


/*****************************************************************************/
// Destructor
/*****************************************************************************/
UtilFile::~UtilFile()
{
    UTIL_DT("UtilFile: Destructor invoked on file: %s",iv_filePathName);

    // Eliminate prior errors
    // - this is done bcs close will abort if there are prior errors
    delete getLastError();

    // Close it up: only if it was created by us
    if ( strcmp( iv_filePathName, UTIL_FILE_INVALID_NM ) != 0 )
    {
        Close();
    }


    delete[] iv_filePathName;

    // Note: a lingering iv_lastError will be trashed
    //       by the base destructor

}


/*****************************************************************************/
// Does the file exist?
/*****************************************************************************/
bool UtilFile::exists( void ) const
{
    return VFS::module_exists(iv_filePathName);
}

/*****************************************************************************/
// Does the file exist?
/*****************************************************************************/
bool UtilFile::exists( const char *i_fileName )
{
    return VFS::module_exists(i_fileName);
}

/*****************************************************************************/
// Open the file opening the file in flash by default.
/*****************************************************************************/
void UtilFile::Open(
    const char * i_mode
    )
{
    do
    {
        if (iv_lastError)
        {
            UTIL_FT("E> UtilFile: Stream Operations Suspended on %s",
            iv_filePathName);
            break;
        }

        // Load module.
        iv_lastError = VFS::module_load(iv_filePathName);
        if (iv_lastError)
        {
            break;
        }

        // Get module address / size.
        const char* l_address = NULL;
        size_t      l_size = 0;

        iv_lastError = VFS::module_address(iv_filePathName, l_address, l_size);
        if (iv_lastError)
        {
            break;
        }

        // Create UtilMem object to overlay module location in memory.
        iv_contents.~UtilMem();
        new (&iv_contents) UtilMem(const_cast<char*>(l_address), l_size);

        iv_eof = iv_contents.eof();
        iv_lastError = iv_contents.getLastError();

    } while(0);
}

/*****************************************************************************/
// Open the file
/*****************************************************************************/
void UtilFile::Open(
    const char * i_file,
    const char * i_mode
)
{
    do
    {
        if (iv_lastError)
        {
            UTIL_FT("E> UtilFile: Stream Operations Suspended on %s",
                    iv_filePathName);
            break;
        }

        if (isOpen())
        {
            Close();
        }
        if (iv_lastError)
        {
            break;
        }

        FileName(i_file);
        Open(i_mode);

    } while(0);
}


/*****************************************************************************/
// Close the file
/*****************************************************************************/
void UtilFile::Close()
{
    do
    {

        if ( iv_lastError )
        {
            UTIL_FT("E> UtilFile: Stream operations suspended on %s",
                    iv_filePathName);
            break;
        }

        if (!isOpen())
        {
            UTIL_DT("E> UtilFile: %s not open", iv_filePathName);
            break;
        }

        // Reset underlying UtilMem.
        iv_contents = UtilMem();
        iv_eof = iv_contents.eof();

        // Unload module.
        iv_lastError = VFS::module_unload(iv_filePathName);

    } while(0);

}


/*****************************************************************************/
// Read the file
/*****************************************************************************/
uint32_t UtilFile::read(
    void *   o_buffer,
    uint32_t i_size
    )
{
    size_t l_rc = 0;

    do
    {
        if (iv_lastError)
        {
            UTIL_FT("E> UtilFile: Stream operations suspended on %s",
                    iv_filePathName);
            break;
        }

        l_rc = iv_contents.read(o_buffer, i_size);

        iv_eof = iv_contents.eof();
        iv_lastError = iv_contents.getLastError();

    } while(0);

    return l_rc;
}

/*****************************************************************************/
// Write the file
/*****************************************************************************/
uint32_t UtilFile::write(
    const void *i_buffer,
    uint32_t    i_size
    )
{
    assert(false, "E> UtilFile: Write attempted in Hostboot on %s",
           iv_filePathName);
    return 0;
}

/*****************************************************************************/
// Seek the file
/*****************************************************************************/
uint32_t UtilFile::seek(
    int     i_pos,
    whence  i_whence
    )
{
    uint32_t l_rc = 0;

    do
    {
        if (iv_lastError)
        {
            UTIL_FT("E> UtilFile: Stream operations suspended on %s",
                    iv_filePathName);
            break;
        }

        l_rc = iv_contents.seek(i_pos, i_whence);

        iv_eof = iv_contents.eof();
        iv_lastError = iv_contents.getLastError();

    } while(0);

    return l_rc;
}

/*****************************************************************************/
// Query the file size
/*****************************************************************************/
uint32_t UtilFile::size() const
{
    return iv_contents.size();
}

/*****************************************************************************/
// Set/Get the object's filename
/*****************************************************************************/
void UtilFile::FileName( const char * i_name )
{
    // Cleanup
    delete[] iv_filePathName;

    iv_filePathName = new char[strlen(i_name) + 1];

    strcpy(iv_filePathName, i_name);
}

