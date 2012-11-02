/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdrToken.H $         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

#ifndef __PRDRTOKEN_H
#define __PRDRTOKEN_H

/**
 * @file prdrToken.H
 * @brief Collect of function defines and includes for prdrcompiler.
 */

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <string>
#include <stack>
#include <utility>

#include <prdrRegister.H>
#include <prdrChip.H>
#include <prdrExpr.H>
#include <prdrGroup.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

extern int yylex();
extern int yyparse();
extern void yyerror(const char *);

extern int yyline;
extern std::stack<std::pair<std::string, int> > yyincfiles;

namespace PRDR_COMPILER
{

extern Chip * g_currentChip;

} // end namespace PRDR_COMPILER

#endif

