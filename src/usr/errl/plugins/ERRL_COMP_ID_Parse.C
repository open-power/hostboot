/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/HBERRL_COMP_ID_Parse.C $                 */
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

/*
 *  @file ERRL_COMP_ID_Parse.C
 *
 *  Creates the ERRL User Detail Data Parser
 */
#include "errludparser.H"
#include "errludparserfactoryerrl.H"

ERRL_MAKE_UD_PARSER(ERRORLOG::ErrlUserDetailsParserFactoryErrl,
                    hbfw::ERRL_COMP_ID)

