//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errlUserDetailsTarget.H $
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
#ifndef ERRL_USERDETAILS_TARGET_H
#define ERRL_USERDETAILS_TARGET_H

/**
 *  @file ErrlTarget.H
 *
 *  Target FFDC Helper
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

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include    <stdint.h>
#include    <errl/errluserdetails.H>
#include    <targeting/targetservice.H>

namespace ERRORLOG
{

#ifndef PARSER

class ErrlUserDetailsTarget : public ErrlUserDetails
{
public:

    /**
     *  @brief Constructor
     *
     */
    ErrlUserDetailsTarget(TARGETING::Target * i_target);

    /**
     *  @brief Destructor
     *
     */
    virtual ~ErrlUserDetailsTarget();

    /**
     *  @brief Adds or appends FFDC data to error log
     *
     *  @param  i_errl
     *      Error log handle to add detail data to.
     *
     *  @param  i_buf
     *      pointer to the new data buffer to be added/appended.
     *
     *  @param  i_len
     *      length of the new data buffer to be added/appended in bytes
     *
     *  @return none
     *
     */
    void addToLog( errlHndl_t i_errl, void *i_buf, const uint32_t i_len );

private:

    // Disabled
    ErrlUserDetailsTarget(const ErrlUserDetailsTarget &);
    ErrlUserDetailsTarget & operator=(const ErrlUserDetailsTarget &);

    TARGETING::Target *iv_pTarget;
};

#else // (if PARSER defined)

/**
 *  @brief Target FFDC Helper
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

class ErrlUserDetailsTarget : public ErrlUserDetails
{
public:

    /**
     *  @brief Constructor
     *
     */
    ErrlUserDetailsTarget() : ErrlUserDetails() {}

    /**
     *  @brief Destructor
     *
     */
    virtual ~ErrlUserDetailsTarget() {}

    /**
     *  @brief Parses user detail data from an error log
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
                       const void * i_pBuffer, const uint32_t i_buflen) const
    {
        char * l_ptr = i_pBuffer;
        for (uint32_t i = 0; i < i_buflen; )
        {
            i_parser.PrintString( "", l_ptr );
            i += strlen(l_ptr) + 1;
            l_ptr += strlen(l_ptr) + 1;
        }
    }

private:

    // Disabled
    ErrlUserDetailsTarget(const ErrlUserDetailsTarget &);
    ErrlUserDetailsTarget & operator=(const ErrlUserDetailsTarget &);

};

#endif

}

#endif
