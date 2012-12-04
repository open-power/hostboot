/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdrCompile.lex $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2013              */
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

/* Pre C stuff: headers, etc. */
%{

/** @file prdrCompile.lex
 *
 *  This file contains all of the flex code for parsing rule-table tokens.
 */

#include <stdlib.h>

#include <prdrToken.H>            // Token structure definition.
#include <prdrCompile.y.H>  // Token enums from yacc code.

#define YY_NO_UNPUT            // No "Unput" function defined.
%}

/* --- Basic type definitions --- */

/* Digits */
digit       [0-9]
hexdigit    [0-9a-fA-F]

/* Numerical constants */
integer     {digit}+
hexint      0[xX]{hexdigit}+
    /* Bit-string is a hex string between two back-ticks */
bitstring   `{hexdigit}+`

/* White space */
whitespace  [ \t]*
newline     \n

/* # starts a comment line */
comment     #.*{newline}

/* IDs are any letter or underscore followed by any number of letters/numbers */
id      [A-Za-z_][A-Za-z0-9_]*

/* --- end Basic type definitions --- */

/* Define special parse contexts for comments and .include headers */
%x DOX_COMMENT
%x INCLUDED

/* --- Begin Token Definitions --- */
%%

 /* Parse numerical constants to "INTEGER" type. */
{integer}   { sscanf(yytext, "%llu", &yylval.long_integer); return PRDR_INTEGER; }
{hexint}    { sscanf(yytext, "%llx", &yylval.long_integer); return PRDR_INTEGER; }

 /* Parse a bitstring to "BIT_STRING" type. */
{bitstring} {
            yylval.str_ptr = new std::string(yytext);
            return PRDR_BIT_STRING;
            }
 /* Parse a string to a "STRING" type.  Any number of characters between two
  * quotes.
  */
\"[^"]*\"   {
            yylval.str_ptr = new std::string(yytext);
            return PRDR_STRING;
            }
 /* Special end-of-file character. */
<<EOF>>     { return 0; }

 /* Various keyword tokens converted directly to the enum type. */
chipid      { return PRDR_CHIPID; }
sigoff      { return PRDR_SIGNATURE_OFFSET; }
PRDR_ERROR_SIGNATURE { return PRDR_SIGNATURE_EXTRA; }
targettype  { return PRDR_TARGETTYPE; }
register    { return PRDR_REGISTER; }
name        { return PRDR_NAME_KW; }
scomaddr    { return PRDR_SCOMADDR; }
scomlen     { return PRDR_SCOMLEN; }
bit         { return PRDR_BIT_KW; }
reset       { return PRDR_RESET_ADDR; }
mask        { return PRDR_MASK_ADDR; }

chip        { return PRDR_CHIP; }
group       { return PRDR_GROUP; }
type        { return PRDR_TYPE; }  /* @jl04 a Add this for primary/secondary type.*/
actionclass { return PRDR_ACTIONCLASS; }
rule        { return PRDR_RULE; }

threshold   { return PRDR_ACT_THRESHOLD; }
analyse     { return PRDR_ACT_ANALYSE; }
analyze     { return PRDR_ACT_ANALYSE; }
try         { return PRDR_ACT_TRY; }
dump        { return PRDR_ACT_DUMP; }
funccall    { return PRDR_ACT_FUNCCALL; }
gard        { return PRDR_ACT_GARD; }
callout     { return PRDR_ACT_CALLOUT; }
flag        { return PRDR_ACT_FLAG; }
capture     { return PRDR_ACT_CAPTURE; }

connected   { return PRDR_CONNECTED; }
alternate   { return PRDR_ALTERNATE; }
procedure   { return PRDR_PROCEDURE; }

attntype    { return PRDR_ATTNTYPE; }
shared      { return PRDR_SHARED_KW; }
req         { return PRDR_REQUIRED_KW; }
field       { return PRDR_FLD_KW; }
mfg         { return PRDR_MFG_KW; }
mfg_file    { return PRDR_MFG_FILE_KW; }
sec         { return PRDR_TIME_SEC; }
min         { return PRDR_TIME_MIN; }
hour        { return PRDR_TIME_HOUR; }
day         { return PRDR_TIME_DAY; }

filter      { return PRDR_FILTER; }
singlebit   { return PRDR_FILTER_SINGLE_BIT; }
priority    { return PRDR_FILTER_PRIORITY; }

"\<\<"      { return PRDR_OP_LEFTSHIFT; }
"\>\>"      { return PRDR_OP_RIGHTSHIFT; }

 /* Parse an "ID" type */
{id}        { yylval.str_ptr = new std::string(yytext); return PRDR_ID;}

 /* Ignore extra white space */
{whitespace}    { }
 /* Newline or comment line increments line count */
{newline}   { yyline++; }
{comment}   { yyline++; }

 /* Any other arbitrary character is returned unchanged (used for parens, |,
  * {, etc. in yacc code).
  */
.           { return yytext[0]; }

 /* When we find the .included directive, we need to enter a special parse
  * context.  There is a preprocessor that runs that changes .include directives
  * to a .included / .end_included pair.  This is used for line counting on
  * errors.
  */
"\.included"        BEGIN INCLUDED;
 /* Ignore extra whitespace */
<INCLUDED>{whitespace}  { }
 /* Find the name of the file that was included, push current file and line
  * number on to a "stack".  When the included file is complete, we pop a pair
  * of the stack to determine where we left off in the old file.
  */
<INCLUDED>\".*\"                {
                                    yyincfiles.push(
                                        std::pair<std::string,int>(
                                            std::string(yytext),
                                            yyline)
                                        );
                                    yyline = 1;
                                }
 /* The newline after the .included indicates the .included directive is
  * complete.  We then return to the "INITIAL" context to parse the included
  * file properly.
  */
<INCLUDED>{newline}                BEGIN INITIAL;
 /* The .end_included directive indicates an included file has ended.  Pop the
  * parent file/line number off the stack.
  */
"\.end_included"                 {
                                    yyline = yyincfiles.top().second;
                                    yyincfiles.pop();
                                }

 /* A "slash-star-star" indicates a special comment context.  This is used for
  * the doxygen-style commenting and HTML documentation generation.
  */
"/**"+[ \t]*                        BEGIN DOX_COMMENT;
 /* A "star-slash" indicates the end of a doxygen comment context. (just like
  * C++)
  */
<DOX_COMMENT>[ \t]*\*[/]        BEGIN INITIAL;
 /* Any number of tabs at the beginning of a line, followed by a star followed
  * by anything but a slash, followed by any number of tabs is ignored.
  */
<DOX_COMMENT>\n[ \t]*\*[^/][ \t]*        { yyline++; return PRDR_DOX_ENDL; }
 /* Find any comment line itself (non-star, non-newline) */
<DOX_COMMENT>[^*\n]*                {
                                    yylval.str_ptr = new std::string(yytext);
                                    return PRDR_DOX_COMMENT;
                                }
 /* New-line in a comment is a special token. */
<DOX_COMMENT>\n                        { yyline++; return PRDR_DOX_ENDL; }
%%

/* User Code */
int yywrap() { return 1;}; // We're only parsing one file, so always return 1.
                           // This is a lex-ism.

