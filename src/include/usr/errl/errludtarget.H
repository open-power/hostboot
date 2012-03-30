//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errludtarget.H $
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
#ifndef ERRL_UDTARGET_H
#define ERRL_UDTARGET_H

/**
 *  @file errludTarget.H
 *
 *  Defines the following classes:
 *
 *  ErrlUserDetailsTarget: Adds Target FFDC to an error log as user detail data
 *  ErrlUserDetailsParserTarget: Parses Target FFDC user detail in an error log
 */

#include <errl/errluserdetails.H>

#ifndef PARSER

// Forward reference
namespace TARGETING
{
    class Target;
}

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsTarget
 *
 * Adds Target FFDC to an error log as user detail data
*/
class ErrlUserDetailsTarget : public ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Captures the supplied Target's FFDC data internally
     *  
     *  @param i_pTarget Pointer to Target to capture as user detail data
     */
    ErrlUserDetailsTarget(const TARGETING::Target * i_pTarget);

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsTarget();

    /**
     *  @brief Adds the Target as user detail data to an error log
     *
     *  @param  i_errl Error log to add detail data to.
     */
    virtual void addToLog(errlHndl_t i_errl);

private:
    // Target pointer
    const TARGETING::Target * iv_pTarget;
    
    // Disabled
    ErrlUserDetailsTarget(const ErrlUserDetailsTarget &);
    ErrlUserDetailsTarget & operator=(const ErrlUserDetailsTarget &);
};

}

#else // (if PARSER defined)

#include <string.h>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsParserTarget
 *
 * Parses Target FFDC user detail in an error log
 */
class ErrlUserDetailsParserTarget : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserTarget() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserTarget() {}

    /**
     *  @brief Parses Target user detail data from an error log
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
        i_parser.PrintString("Target data", NULL);
        char * l_ptr = static_cast<char *>(i_pBuffer);
        for (uint32_t i = 0; i < i_buflen; )
        {
            i_parser.PrintString(NULL, l_ptr);
            i += strlen(l_ptr) + 1;
            l_ptr += strlen(l_ptr) + 1;
        }
    }

private:
    // Disabled
    ErrlUserDetailsParserTarget(const ErrlUserDetailsParserTarget &);
    ErrlUserDetailsParserTarget & operator=(
        const ErrlUserDetailsParserTarget &);
};

}

#endif
#endif

