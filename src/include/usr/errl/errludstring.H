/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errludstring.H $                         */
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
#ifndef ERRL_UDSTRING_H
#define ERRL_UDSTRING_H

/**
 *  @file errludstring.H
 *
 *  Defines the ErrlUserDetailsString class that adds string FFDC to an
 *  error log as user detail data
 */

#include <errl/errluserdetails.H>

namespace ERRORLOG
{

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

}

#endif

