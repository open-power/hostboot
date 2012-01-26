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
 *  Error Log User Detail Data Helper
 *
 *  Framework defining how User Detail Data sections of error logs should
 *  be created and parsed.
 *
 *  Creation methods will show up when the PARSER macro is NOT defined.
 *  These will compile and run under HostBoot.
 *
 *  Parsing methods will show up when the PARSER macro IS defined.
 *  These will compile and run in the errl tool.
 *
*/

//
//  @page   ErrlUserDetails     Error Log User Details
//
//


/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/


// safe to include these, PARSER or no PARSER
#include    <hbotcompid.H>      // list of compid's supported
#include    <errl/hberrltypes.H>  //  errlver_t, errlsubsec_t




#ifndef PARSER
#include    <errl/errlentry.H>  //  addFFDC, appendFFDC

namespace ERRORLOG
{


/**
 * @brief ERRL User Data Details
 *
 * HostBoot Support - base class for Errorlog User Details.
 *
 *
*/
class ErrlUserDetails
{
public:

    /**
     *  @brief Constructor
     *
     *  Sets up instance variables. A derived class should set up the instance
     *  variables to reflect a specific format of user detail data
     *
     */
    ErrlUserDetails();

    /**
     *  @brief Destructor
     *
     *  Performs any necessary cleanup
     *
     */
    virtual ~ErrlUserDetails();

    /**
     *  @brief Adds or appends more user detail data to error log
     *
     *  Adds or appends user detail data stored in the internal buffer to
     *  the error log
     *  Subclasses should override if the detail data is not stored in the
     *  internal buffer.
     *
     *  @param  i_errl
     *      Error log handle to add detail data to.
     *      This will call appendFFDC() in the errorlog.
     *
     *  @param  i_pappendBuf
     *      pointer to the new data buffer to append.
     *
     *  @param  i_pappendBufLen
     *      length of the new data buffer to append in bytes.
     *
     *  @return None
     *
     */
    virtual void addToLog(
            errlHndl_t      i_errl,
            const void      *i_paddBuf=NULL,
            const uint32_t  i_addBufLen=0 );

protected:

    /**
     *  @brief Allocates the internal data buffer for storing detail data
     *
     *  If the internal buffer is already allocated then it is freed. The
     *  data buffer is allocated with the specified size.
     *
     *  @param  i_size
     *      Size of buffer
     *
     *  @return uint8_t*
     *      Pointer to the data buffer
     *
     */
    uint8_t * allocUsrBuf(const uint32_t i_size);

    /**
     *  @brief Returns the size of the internal data buffer
     *
     *  @return uint32_t
     *      Size of the internal data buffer
     *
     */
    uint32_t getUsrBufSize() const;

    /**
     *  Protected Data: ID of component adding user details
     */
    compId_t    iv_CompId;

    /**
     *  Protected Data: Version number of the user details
     */
    errlver_t    iv_Version;

    /**
     *  Protected Data: Subsection number of the user details
     */
    errlsubsec_t iv_SubSection;

    /**
     *  Pointer to the ErrlFFDC  passed back by addFFDC()
     */
    ErrlFFDC    *iv_pErrlFFDC;

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
} // namespace 

#else // (if PARSER defined)

/**
 *
 *  @brief Error Log User Detail Data Helper
 *
 *  Framework defining how User Detail Data sections of error logs should
 *  be created and parsed.
 *
 *  Creation methods will show up when the PARSER macro is NOT defined.
 *  These will compile and run under HostBoot.
 *
 *  Parsing methods will show up when the PARSER macro IS defined.
 *  These will compile and run in the errl tool.
 *
*/
namespace ERRORLOG
{


class ErrlUserDetails
{
public:

    /**
     *  @brief Constructor
     *
     */
    ErrlUserDetails()
    {

    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~ErrlUserDetails()
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
                       const void * i_pBuffer,
                       const uint32_t i_buflen) const = 0;

private:

    // Disabled
    ErrlUserDetails(const ErrlUserDetails &);
    ErrlUserDetails & operator=(const ErrlUserDetails &);
};

} // namespace


#endif //PARSER

#endif
