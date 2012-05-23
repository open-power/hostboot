//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/util/utilfile.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2003-2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef UTILFILE_H
#define UTILFILE_H

/**
 * @file utilfile.H
 *
 * @brief File Stream manipulation
 *
 * Used for creating and manipulating file streams
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/

// Utility Includes
#include <util/utilstream.H>
#include <util/utilmem.H>
#include <util/util_reasoncodes.H>

/*****************************************************************************/
// File Stream class
/*****************************************************************************/
/**
 *  @brief     Utility file stream class
 *
 *  Used for file streams
 *
 */
class UtilFile : public UtilStream
{
  public:

    /**
     *  @brief Default Constructor
     *
     *  Initializes internals to NULL and will thus cause an exception if
     *  an invalid operation is performed ( such as writing to the file
     *  without opening it )
     *
     */
    UtilFile();

    /**
     *  @brief Constructor
     *
     *  Initializes internals of the file stream object with the file path name.
     *
     */
    UtilFile(const char * i_filePathName);

    /**
     *  @brief Destructor
     *
     *  1. Closes the file ( if it's open )
     *  2. Deletes allocated resources
     *  3. Deletes any pending error logs ( effectively aborting )
     *
     */
    virtual ~UtilFile();

    /**
     *  @brief Determines if the file is available in the filesystem
     *
     *  Attempts to open the file for readonly to determine if it exists
     *  in the file system.  Secondary failures are not reported by
     *  this interface.
     *
     *  @return
     *      Bool: true, the file exists.  false, it doesn't exist or a
     *      secondary failure occurred while making the determination.
     *
     */
    bool exists( void ) const;

    /**
     *  @brief Determines if the file is available in the filesystem
     *
     *  This is a static function that to determine if it exists
     *  in the file system and is a REGULAR file.
     *  Secondary failures are not reported by this interface.
     *
     *  @return
     *      Bool: true, the file exists.  false, it doesn't exist or a
     *      secondary failure occurred while making the determination.
     *
     */
    static bool exists(const char * );

    /**
     *  @brief Open the file associated with the object
     *
     *  Opens the file based off of the file name associated with the object
     *  with the specified file mode by calling Open with the flag set to false
     *  to always open the flash file by default.
     *
     *  @return
     *      Nothing. Errors are deferred until the user calls getLastError
     *
     */
    void Open(
        const char * i_mode ///<Mode file is to be opened in
    );

    /**
     *  @brief Open the file associated with the object
     *
     *  Opens the file based off of the file name associated with the object
     *  with the specified file mode calling the open with the flag set to false
     *  to always open the flash file by default.
     *
     *  @return
     *      A error handle specifying the failure ( if any ).
     *
     */
    errlHndl_t open(
        const char * i_mode ///<Mode file is to be opened in
    )
    {
        Open(i_mode);
        return getLastError();
    }

    /**
     *  @brief Open a file for the specified access
     *
     *  If a file is currently open, it will be closed.  Then the
     *  specified file will be opened for the given access mode.
     *  Any failures are reported through the return code
     *
     *  @return
     *      Nothing. Errors are deferred until the user calls getLastError
     *
     */
    void Open(
        const char * i_file,    ///< Path filename
        const char * i_mode     ///< Mode file is to be opened in
    );

    /**
     *  @brief Open a file for the specified access
     *
     *  If a file is currently open, it will be closed.  Then the
     *  specified file will be opened for the given access mode.
     *  Any failures are reported through the return code
     *
     *  @return
     *      A error handle specifying the failure ( if any ).
     *
     */
    errlHndl_t open(
        const char * i_file,    ///< Path filename
        const char * i_mode     ///< Mode file is to be opened in
    )
    {
        Open(i_file,i_mode);
        return getLastError();
    }

    /**
     *  @brief Close the file associated with the object
     *
     *  Closes the file based off file pointer associated with the file.
     *
     *  @return
     *      Nothing. Errors are deferred until the user calls getLastError
     *
     */
    void Close();

    /**
     *  @brief Close the file associated with the object
     *
     *  Closes the file based off file pointer associated with the file.
     *
     *  @return
     *      A error handle specifying the failure ( if any ).
     *
     */
    errlHndl_t close()
    {
        Close();
        return getLastError();
    }

    /**
     *  @brief Reads data from current position of the stream
     *
     *  Reads data from the current postion of the stream for the
     *  specified number of bytes.
     *
     */
    uint32_t read(
        void * o_buffer,    ///< Buffer data is read into
        uint32_t i_size     ///< Size in bytes of data to be read
    );

    /**
     *  @brief Writes data to current position of the stream
     *
     *  Writes data to the current postion of the stream for the
     *  specified number of bytes.
     *
     *  @note This will assert in Hostboot! Writing of files is not supported.
     *
     */
    uint32_t write(
        const void *i_buffer,     ///< Source buffer data is written from
        uint32_t    i_size        ///< Size in bytes of data to be written
    );

    /**
     *  @brief Seek to the specified position in the stream
     *
     *  Performs a seek based on the specified position and offset.
     *
     */
    uint32_t seek(
        int i_pos,          ///< Seek offset in bytes
        whence i_whence     ///< Position to seek from
    );

    /**
     *  @brief Return the current size of the stream
     *
     *  Returns the current size of the stream.
     *
     */
    uint32_t size() const;

    /**
     * @brief Query the file's open/closed state
     *
     * Determines if the file is currently open
     *
     * @return bool value indicating the open status of the file
     *
    */
    bool isOpen( void ) const
    {
        return ( iv_contents.size() != 0 );
    }

    /**
     *  @brief Expose the filename
     *
     *  Return a const char * to the filename
     *
     *  @return Filename pointer
     *
     */
    const char * Name() const;

private:

    /**
     * @brief Change the object's filename
     *
     * Set the object's filename
     *
     * @param i_name
     *      New name, or null to simply get
     *
     * @return void
     *
    */
    void FileName( const char * i_name );

    // Instance variables
    char*       iv_filePathName;    ///< Name of file being operated on
    UtilMem     iv_contents;
};


/*****************************************************************************/
// Get Filename
/*****************************************************************************/
inline const char * UtilFile::Name() const
{
    return iv_filePathName;
}

#endif //UTILFILE_H
