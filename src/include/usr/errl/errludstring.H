//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errludstring.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef ERRL_UDSTRING_H
#define ERRL_UDSTRING_H

/**
 *  @file errludstring.H
 *
 *  Defines the following classes:
 *
 *  ErrlUserDetailsString: Adds string FFDC to an error log as user detail data
 *  ErrlUserDetailsParserString: Parses string FFDC user detail in an error log
*/

#include <errl/errluserdetails.H>

namespace ERRORLOG
{

#ifndef PARSER

/**
 * @class ErrlUserDetailsString
 *
 * Adds String FFDC to an error log as user detail data
 */
class ErrlUserDetailsString : public ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Captures the supplied string internally
     *  
     *  @param i_pString Pointer to string to capture as user detail data
     */
    ErrlUserDetailsString(const char * i_pString);

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsString();

private:
    // Disabled
    ErrlUserDetailsString(const ErrlUserDetailsString &);
    ErrlUserDetailsString & operator=(const ErrlUserDetailsString &);
};

#else // (if PARSER defined)

/**
 * @class ErrlUserDetailsString
 *
 * Parses String user detail in an error log
*/
class ErrlUserDetailsParserString : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserString() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserString() {}

    /**
     *  @brief Parses string user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        i_parser.PrintString("String data", static_cast<char *>(i_pBuffer));
    }

private:
    // Disabled
    ErrlUserDetailsParserString(const ErrlUserDetailsParserString &);
    ErrlUserDetailsParserString & operator=(
        const ErrlUserDetailsParserString &);
};

#endif

}

#endif

