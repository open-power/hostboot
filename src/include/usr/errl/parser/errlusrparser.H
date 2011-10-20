//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/parser/errlusrparser.H $
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
#ifndef PARSER_ERRLUSRPARSER_H
#define PARSER_ERRLUSRPARSER_H

/**
 *  @file errlusrparser.H
 *
 *  @brief Console interface implementation for error log parser
 *
 *  Concrete implementation of the parser interface specialization for
 *  the console.
 *
*/


/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


#include <errl/parser/errlparserbase.H>

/*****************************************************************************/
// User Types
/*****************************************************************************/
class ErrlUsrParser : public ErrlParser
{
public:


    /**
     *  @brief Build an associated parser object
     *
     *  Builds an associated parser object which is tied to the
     *  given stream.  The net effect is the addition of some
     *  simple methods to standardize log output
     *
     *  @param	i_output
     *	    Stream to be used for output
     *
     *  @param	i_parent
     *	    A pointer to the parent object
     *
     *  @note The parent could be null
     *
     */
    ErrlUsrParser(
            FILE *		    i_output = stdout
    )
    : ErrlParser( i_output )
    {
    }


     // String
    void PrintString(
            const char * i_label,
            const char * i_string
    );


    // Print a Number
    void PrintNumber(
            const char * i_label,
            const char * i_fmt,
            uint32_t     i_value
    );


    // Hex Dump
    void PrintHexDump(
            const void * i_data,
            uint32_t     i_len
    );


};



#endif //ERRLUSRPARSER_H
