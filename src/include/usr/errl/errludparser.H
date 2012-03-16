//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errludparser.H $
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
#ifndef ERRL_UDPARSER_H
#define ERRL_UDPARSER_H

#ifdef PARSER

/**
 *  @file errludparser.H
 *
 *  To create a function that errl calls to parse user detail data, a
 *  component's plugin/<comp>Parse.C file should include this file and call the
 *  ERRL_MAKE_UD_PARSER macro
 */

#include <netinet/in.h>

/**
 * @brief Endian swap a uint64_t. This is not provided by in.h
 */
inline uint64_t ntohll( uint64_t i )
#if __BYTE_ORDER == __LITTLE_ENDIAN
{
    //  CONTEXT_x86_nfp
    uint64_t hi;
    uint64_t lo;
    uint32_t * pword = reinterpret_cast<uint32_t*>(&i);

    hi = ntohl( *pword );
    lo = ntohl( *(pword+1) );

    return (hi<<32)|lo;
}
#elif __BYTE_ORDER == __BIG_ENDIAN
{
    // CONTEXT_ppc (or maybe CONTEXT_aix_nfp)
    return i;
}
#else
#error Unexpected endian context.
#endif

// FSP includes
#include <errlplugins.H>
#include <errlusrparser.H>

/**
 * @brief Macro that generates a function and plugin object to parse a
 *        component's error log user detail data
 */
#define ERRL_MAKE_UD_PARSER(FACTORY, COMPID) \
static bool myDataParse(\
    ErrlUsrParser& i_parser, void* i_buffer, uint32_t i_buflen,\
    errlver_t i_ver, errlsubsec_t i_sst)\
{\
    bool l_rc = false;\
    FACTORY l_factory;\
    ERRORLOG::ErrlUserDetailsParser * l_pParser =\
        l_factory.createParser(i_sst);\
    if (l_pParser)\
    {\
        l_rc = true;\
        l_pParser->parse(i_ver, i_parser, i_buffer, i_buflen);\
    }\
    return l_rc;\
}\
static errl::DataPlugin g_DataPlugin(COMPID, myDataParse);

#endif
#endif

