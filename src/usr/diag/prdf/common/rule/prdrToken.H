/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrToken.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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

