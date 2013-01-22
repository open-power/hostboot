/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludcallout.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#ifndef ERRL_UDCALLOU_H
#define ERRL_UDCALLOU_H

/**
 *  @file errludcallout.H
 *
 *  Defines the ErrlUserDetailsParserCallout class that parses
 *  callout user detail in an error log
 */

#include "errluserdetails.H"

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsCallout
 *
 * Parses Callout user detail in an error log
 */
class ErrlUserDetailsParserCallout : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserCallout() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserCallout() {}

    /**
     *  @brief Parses callout user detail data from an error log
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
        // TODO fix when parser fixed
        // RTC 41707
    }

private:
    // Disabled
    ErrlUserDetailsParserCallout(const ErrlUserDetailsParserCallout &);
    ErrlUserDetailsParserCallout & operator=(
        const ErrlUserDetailsParserCallout &);
};

}

#endif

