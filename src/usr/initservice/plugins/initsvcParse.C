//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/initservice/plugins/initsvcParse.C $
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
/**
 *  @file initsvcParse.C
 *
 *  Initservice user data parser
 */
#include <netinet/in.h>

// FSP includes
#include <errlplugins.H>
#include <errlusrparser.H>

// Hostboot includes
#include <initservice/initsvcudparserfactory.H>

static bool myDataParse(
    ErrlUsrParser& i_parser,
    void* i_buffer,
    uint32_t i_buflen,
    errlver_t i_ver,
    errlsubsec_t i_sst)
{
    bool l_rc = false;

    // Create a InitSvcUserDetailsParserFactory object
    INITSERVICE::InitSvcUserDetailsParserFactory l_factory;
    
    // Use the factory to create a ErrlUserDetailsParser object
    ERRORLOG::ErrlUserDetailsParser * l_pParser = l_factory.createParser(i_sst);
    
    if (l_pParser)
    {
        l_rc = true;
        l_pParser->parse(i_ver, i_parser, i_buffer, i_buflen);
    }
    
    return l_rc;
}

// Map my Hostboot component ID to the function above.
static errl::DataPlugin g_DataPlugin(INITSVC_COMP_ID, myDataParse );

