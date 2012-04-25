//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errluserdetails.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef ERRL_ERRLUSERDETAILS_H
#define ERRL_ERRLUSERDETAILS_H

/**
 *  @file errluserdetails.H
 *
 *  Defines the ErrlUserDetails and ErrlUserDetailsParser base classes
 *
 *  Derive a class from ErrlUserDetails to create user detail data
 *  Derive a class from ErrlUserDetailsParser to parse user detail data
 */
#include <stdint.h>
#include <errl/hberrltypes.H>  // errlver_t, errlsubsec_t

#ifndef PARSER

#include <errl/errlentry.H>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetails
 *
 * This class creates user detail data. If a component creates user detail data
 * then for each different type of data it should derive a class from this.
 *
 * This class is only compiled when PARSER is not defined.
 */
class ErrlUserDetails
{
public:

    /**
     *  @brief Constructor
     *
     *  Sets up instance variables. A derived class should set up the instance
     *  variables to reflect a specific format of user detail data
     */
    ErrlUserDetails();

    /**
     *  @brief Destructor
     *
     *  Performs any necessary cleanup
     */
    virtual ~ErrlUserDetails();

    /**
     *  @brief Adds user detail data to an error log
     *
     *  Adds the user detail data stored in the internal buffer to the error
     *  log. Subclasses should override if the detail data is not stored in the
     *  internal buffer.
     *
     *  @param  i_errl Error log handle to add detail data to.
     */
    virtual void addToLog(errlHndl_t i_errl);

protected:

    /**
     *  @brief Allocates the internal data buffer for storing detail data
     *
     *  If the internal buffer is already allocated then it is reallocated and
     *  the contents preserved (up to the lesser of the new and old sizes).
     *
     *  @param i_size Size of buffer
     *
     *  @return uint8_t* Pointer to the data buffer
     */
    uint8_t * reallocUsrBuf(const uint32_t i_size);

    /**
     *  @brief Returns the size of the internal data buffer
     *
     *  @return uint32_t Size of the internal data buffer
     */
    uint32_t getUsrBufSize() const;

    /**
     *  Protected Data: ID of component adding user details
     */
    compId_t iv_CompId;

    /**
     *  Protected Data: Version number of the user details
     */
    errlver_t iv_Version;

    /**
     *  Protected Data: Subsection number of the user details
     */
    errlsubsec_t iv_SubSection;

    /**
     *  Protected Data: true/false merge like buffers
     */
    bool      iv_merge;

private:

    // Disabled
    ErrlUserDetails(const ErrlUserDetails &);
    ErrlUserDetails & operator=(const ErrlUserDetails &);

    /**
     *  Private Data members (the internal buffer should be accessed through
     *  public member functions)
     */
    uint8_t * iv_pBuffer;       // Pointer to internal buffer
    uint32_t  iv_BufLen;        // Length of internal buffer
};

}

#else // (if PARSER defined)

namespace ERRORLOG
{

/**
 *
 * @class ErrlUserDetailsParser
 *
 * This is an abstract base class that defines how user detail error log data
 * should be parsed. For every different format of user detail data, a
 * component should create a class that derives from this class.
 *
 * This is only compiled when PARSER is defined.
 *
*/
class ErrlUserDetailsParser
{
public:

    /**
     *  @brief Constructor
     *
     */
    ErrlUserDetailsParser()
    {
    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~ErrlUserDetailsParser()
    {
    }

    /**
     *  @brief Parses user detail data from an error log
     *
     *  Parses the supplied user detail data and outputs info to i_parser. This
     *  is a pure virtual function that must be overridden by a concrete derived
     *  class that is specific to a particular component, version and subsection
     *
     *  @param  i_version
     *      Version of the data
     *
     *  @param  i_parse
     *      ErrlUsrParser object for outputting information
     *
     *  @param  i_pBuffer
     *      Pointer to buffer containing detail data
     *
     *  @param  i_buflen
     *      Length of the buffer
     *
     *  @return None
     *
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const = 0;

private:

    // Disabled
    ErrlUserDetailsParser(const ErrlUserDetailsParser &);
    ErrlUserDetailsParser & operator=(const ErrlUserDetailsParser &);
};

}

#endif
#endif

