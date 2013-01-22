/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errluserdetails.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
#ifndef ERRL_ERRLUSERDETAILS_H
#define ERRL_ERRLUSERDETAILS_H

/**
 *  @file errluserdetails.H
 *
 *  Defines the ErrlUserDetailsParser base class
 *
 *  For each class derived from ErrlUserDetails used to create user detail data,
 *  derive a class from ErrlUserDetailsParser to parse user detail data
 */
#include <stdint.h>

namespace ERRORLOG
{

/**
 *
 * @class ErrlUserDetailsParser
 *
 * This is an abstract base class that defines how user detail error log data
 * should be parsed. For every different format of user detail data, a
 * component should create a class that derives from this class.
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

