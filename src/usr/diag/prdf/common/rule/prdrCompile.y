/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrCompile.y $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

/* chip.y */

/** @file prdrCompile.y
 *
 *  This file contains all of the yacc code for parsing rule-table syntax and
 *  creating the abstract-syntax tree.
 *
 *  None of this code is ran on the FSP.  It is all used to generate data
 *  files.
 *
 *  Important background:
 *
 *  Compilers, such as yacc/bison, have the concept of a terminal vs.
 *  non-terminal token.  A terminal token is one which is not built from others,
 *  such as a keyword.  A non-terminal token is one that has syntax associated
 *  with it, such as an "expression" token that is made up of many sub-tokens.
 *
 *  Suggested reading material on parsers/compilers would be
 *          http://en.wikipedia.org/wiki/Backus-Naur_form
 */

/* Pre C stuff: headers, etc. */
%{
#include <prdrToken.H>
#include <prdrCommon.H>

#include <string>

#include <prdrRegister.H> // REVIEW NOTE: Move to token.h?

using namespace PRDR_COMPILER;

%}


/* Union for the 'yylval' variable in lex or $$ variables in yacc code.  Used
 * to store the data associated with a parsed token.
 */
%union{

    /* NOTE: Though we will read from rule file every integer as 64 bit number,
     *       when creating prf file we will use, 64 bit number only for
     *       registers. For other we will use it as per need (mostly 32 bit) and
     *       number will be truncated. It will be dictated by code defined in
     *       prdrExpr.H and other rule parsing classes. */

    /** 64 bit unsigned integer value from a token. */
    uint64_t long_integer;

    /** string value from a token. */
    std::string * str_ptr;
    /** Parsed list of registers. */
    PRDR_COMPILER::RegisterList * reglist;
    /** A single parsed register. */
    PRDR_COMPILER::Register * reg;
    /** A structure for the reset / mask keywords. */
    PRDR_COMPILER::ResetOrMaskStruct * reg_mask;
    /** A chip object */
    PRDR_COMPILER::Chip * chip;
    /** A sub-expression token. */
    PRDR_COMPILER::Expr * expr;
    /** A parsed group of bit-operation / action pairs */
    PRDR_COMPILER::Group * grp;
    /** A list of strings */
    std::list<std::string *>* strlist;
    /** A list of filters */
    std::list<PRDR_COMPILER::Group_Filter *>* filterlist;
}

    /* Indicates the name for the start symbol. (non-terminal) */
%start input

    /* Define a number of terminal symbols and the portion of the union
     * associated with each of them.
     */
%token <long_integer> PRDR_INTEGER
%token <str_ptr> PRDR_ID
%token <str_ptr> PRDR_STRING
%token <str_ptr> PRDR_BIT_STRING

    /* Define a number of terminal symbols without associated data:
     * the keywords.
     */
%token PRDR_CHIP
%token PRDR_GROUP
%token PRDR_TYPE
%token PRDR_ACTIONCLASS
%token PRDR_RULE

%token PRDR_CHIPID
%token PRDR_TARGETTYPE
%token PRDR_SIGNATURE_OFFSET
%token PRDR_SIGNATURE_EXTRA
%token PRDR_REGISTER
%token PRDR_NAME_KW
%token PRDR_SCOMADDR
%token PRDR_SCOMLEN
%token PRDR_REGISTER_ACCESS
%token PRDR_REGISTER_READ_ACCESS
%token PRDR_REGISTER_WRITE_ACCESS
%token PRDR_REGISTER_NO_ACCESS
%token PRDR_RESET_ADDR
%token PRDR_MASK_ADDR
%token PRDR_BIT_KW
%token PRDR_OP_LEFTSHIFT
%token PRDR_OP_RIGHTSHIFT
%token PRDR_SUMMARY

%token PRDR_ACT_THRESHOLD
%token PRDR_ACT_ANALYSE
%token PRDR_ACT_TRY
%token PRDR_ACT_DUMP
%token PRDR_ACT_FUNCCALL
%token PRDR_ACT_CALLOUT
%token PRDR_ACT_FLAG
%token PRDR_ACT_CAPTURE

%token PRDR_CONNECTED
%token PRDR_CONNECTED_PEER
%token PRDR_ACT_NONZERO
%token PRDR_ALTERNATE
%token PRDR_PROCEDURE

%token PRDR_ATTNTYPE
%token PRDR_SHARED_KW
%token PRDR_REQUIRED_KW
%token PRDR_MFG_KW
%token PRDR_FLD_KW
%token PRDR_MFG_FILE_KW
%token PRDR_TIME_SEC
%token PRDR_TIME_MIN
%token PRDR_TIME_HOUR
%token PRDR_TIME_DAY
%token PRDR_FILTER

%token PRDR_FILTER_SINGLE_BIT
%token PRDR_FILTER_PRIORITY
%token PRDR_FILTER_CS_ROOT_CAUSE

    /* Terminal tokens for Doxygen-style comments */
%token <str_ptr> PRDR_DOX_COMMENT
%token <str_ptr> PRDR_DOX_ENDL

    /* Non-terminal tokens and the data-type associated with them. */
%type <reg> register reglines regline
%type <reg_mask> register_mask
%type <chip> chiplines chipline
%type <expr> ruleexpr ruleexpr_small ruleexpr_shift ruleop1 ruleop2 summary
%type <expr> bitgroup bitandlist bitorlist
%type <expr> time_units
%type <grp> grouplines groupline
%type <grp> actionlines

%type <expr> actionline
%type <expr> action_threshold action_shared_threshold action_analyse
%type <expr> action_analyse_conn action_try action_capture
%type <expr> action_dump action_callout action_funccall action_flag
%type <expr> action_callout_alt

%type <strlist> grpattns grpattns_item
%type <filterlist> grpfilters grpfilt_items grpfilt_item

%type <str_ptr> dox_comment dox_commentline dox_commentblk

%%
/* Grammars */

    /* The 'input' (or start token) is simply any number of lines. */
input:
        | input line
;

    /* Lines can be a full chip, group, rule, or actionclass.  */
line:   chip
        | group
        | rule
        | actionclass
;

    /* A chip is a chip-keyword, id, and any number of "lines" */
chip:   PRDR_CHIP PRDR_ID '{' chiplines '}' ';'
    {
        // Create a default chip object is chiplines are empty.
        if (nullptr == $4)
            $4 = new Chip();

        // Assign chip's shortname from ID.
        $4->cv_sname = $2;

        // Set current chip to be this chip.
        g_currentChip = $4;
    }
;

    /* Any number of lines can make up a chiplines token.  */
chiplines:  { $$ = nullptr; }  // empty line.
        | chiplines chipline ';'
    {
        // Merge the chip lines together into a single object as needed.
        if (nullptr != $1)
        {
            if (nullptr == $2)
                $$ = nullptr;
            else
            {
                // Both are non-nullptr, merge.
                Chip::merge($1, $2);
                $$ = $1;
                delete $2;
            }
        }
        else
        {
            if (nullptr == $2)
                $$ = nullptr;
            else
                $$ = $2;
        }
    }

;

    /* Create a chip object based on the contents of the line. */
chipline:   { $$ = nullptr; } // allow a free ;.
        | PRDR_CHIPID PRDR_INTEGER
    {
        $$ = new Chip();
        $$->cv_chipid = $2;
    }
        | PRDR_SIGNATURE_OFFSET PRDR_INTEGER
    {
        $$ = new Chip();
        $$->cv_signatureOffset = $2;
    }
        | PRDR_SIGNATURE_EXTRA '(' PRDR_ID ',' PRDR_INTEGER ','
            PRDR_STRING ',' PRDR_STRING ')'
    {
        $$ = new Chip();
        $$->cv_sigExtras.push_back(ExtraSignature($5, $7, $9));
    }
        | PRDR_TARGETTYPE PRDR_ID
    {
        $$ = new Chip();
        $$->cv_targetType = prdrActionArgMap(*$2);
    }
        | PRDR_NAME_KW PRDR_STRING
    {
        $$ = new Chip();
        $$->cv_name = $2;
    }
        | register        // register non-terminal token.
    {
        $$ = new Chip();
        $$->cv_reglist.push_back($1);
    }
        | PRDR_SCOMLEN PRDR_INTEGER
    {
        $$ = new Chip();
        $$->cv_scomlen = $2;
    }
        | PRDR_ACT_DUMP PRDR_ID                        //@ecdf
    {
        $$ = new Chip();
        $$->cv_dumptype = prdrActionArgMap(*$2);
    }
;

    /* A register is the register-keyword, id, and a number of "lines". */
register: PRDR_REGISTER PRDR_ID '{' reglines '}'
    {
        // Create register object as needed.
        if (nullptr == $4)
            $$ = new Register();
        else
            $$ = $4;

        // Assign short-name.
        $$->cv_sname = $2;
    }
;
    /* Any number of lines can make up a reglines token.  */
reglines:   { $$ = nullptr; }
        | reglines regline ';'
    {
        // Merge register lines as needed.
        if (nullptr != $1)
        {
            if (nullptr == $2)
                $$ = nullptr;
            else
            {
                // Both are non-nullptr, merge.
                Register::merge($1, $2);
                $$ = $1;
                delete $2;
            }
        }
        else
        {
            if (nullptr == $2)
                $$ = nullptr;
            else
                $$ = $2;
        }
    }
;

    /* Define all of the lines (expressions) that can be found in a register */
regline:    { $$ = nullptr; }
        | PRDR_NAME_KW PRDR_STRING
    {
        $$ = new Register();
        $$->cv_name = $2;
    }
        | PRDR_NAME_KW PRDR_ID
    {
        $$ = new Register();
        $$->cv_name = $2;
    }
        | PRDR_SCOMADDR PRDR_INTEGER
    {
        $$ = new Register();
        $$->cv_scomaddr = $2;
    }
        | PRDR_SCOMLEN PRDR_INTEGER
    {
        $$ = new Register();
        $$->cv_scomlen = $2;

        // Indicate that the register contains a non-default scomlen.
        $$->cv_flags |= Prdr::PRDR_REGISTER_SCOMLEN;
    }
        | PRDR_RESET_ADDR '(' register_mask ')'
    {
        $$ = new Register();

        // Add reset register to list.
        $$->cv_resets.push_back(*$3);
        delete $3;
    }
        | PRDR_MASK_ADDR '(' register_mask ')'
    {
        $$ = new Register();

        // Add mask register to list.
        $$->cv_masks.push_back(*$3);
        delete $3;
    }
        | PRDR_ACT_CAPTURE PRDR_GROUP PRDR_ID
    {
        $$ = new Register();

        // Define capture group.
        CaptureReqStruct tmp;
        tmp.type = CaptureReqStruct::PRDR_CAPTURE_GROUPID;
        tmp.data[0] = prdrCaptureGroupMap(*$3);

        $$->cv_captures.push_back(tmp);
    }
//@jl04 Add  a new capture "type" here for regsiters.
        | PRDR_ACT_CAPTURE PRDR_TYPE PRDR_ID
    {
        $$ = new Register();

        // Define capture type.
        CaptureReqStruct tmp;
        tmp.type = CaptureReqStruct::PRDR_CAPTURE_TYPE;
        tmp.data[0] = prdrCaptureTypeMap(*$3);
        $$->cv_captures.push_back(tmp);
    }
//@jl04 End.

        |  PRDR_ACT_CAPTURE PRDR_REQUIRED_KW PRDR_CONNECTED '(' PRDR_ID  ')'
    {
        $$ = new Register();

        // Define capture "connected" requirement.
        CaptureReqStruct tmp;
        tmp.type = CaptureReqStruct::PRDR_CAPTURE_CONN;
        tmp.data[0] = prdrActionArgMap(*$5);
        tmp.data[1] = 0;

        $$->cv_captures.push_back(tmp);
    }
        | PRDR_ACT_CAPTURE PRDR_REQUIRED_KW PRDR_CONNECTED '(' PRDR_ID ',' PRDR_INTEGER ')'
    {
        $$ = new Register();

        // Define capture "connected" requirement.
        CaptureReqStruct tmp;
        tmp.type = CaptureReqStruct::PRDR_CAPTURE_CONN;
        tmp.data[0] = prdrActionArgMap(*$5);
        tmp.data[1] = $7;

        $$->cv_captures.push_back(tmp);
    }
        | PRDR_ACT_CAPTURE PRDR_REQUIRED_KW PRDR_ACT_FUNCCALL '(' PRDR_STRING ')'
    {
        $$ = new Register();

        // Define funccall requirement.
        CaptureReqStruct tmp;
        tmp.type = CaptureReqStruct::PRDR_CAPTURE_FUNC;
        tmp.str = *$5;

        $$->cv_captures.push_back(tmp);
    }
        | PRDR_ACT_CAPTURE PRDR_REQUIRED_KW PRDR_ACT_NONZERO '(' PRDR_STRING ')'
    {
        $$ = new Register();

        CaptureReqStruct tmp;
        tmp.type = CaptureReqStruct::PRDR_CAPTURE_NONZERO;
        tmp.str = *$5;

        $$->cv_captures.push_back(tmp);
    }
        | PRDR_REGISTER_ACCESS PRDR_REGISTER_READ_ACCESS
    {
        $$ = new Register();
        $$->cv_flags |= Prdr::PRDR_REGISTER_READ;
    }
        | PRDR_REGISTER_ACCESS PRDR_REGISTER_WRITE_ACCESS
    {
        $$ = new Register();
        $$->cv_flags |= Prdr::PRDR_REGISTER_WRITE;
    }
        | PRDR_REGISTER_ACCESS PRDR_REGISTER_NO_ACCESS
    {
        $$ = new Register();
        $$->cv_flags |= Prdr::PRDR_REGISTER_ACCESS_NIL;
    }
;

    /* Define the possible reset/mask instructions. */
register_mask: '|' ',' PRDR_INTEGER
    {
        $$ = new ResetOrMaskStruct();
        $$->type = '|';
        $$->addr_r = $3;
        $$->addr_w = $3;
    }
        | '|' ',' PRDR_INTEGER ',' PRDR_INTEGER
    {
        $$ = new ResetOrMaskStruct();
        $$->type = '|';
        $$->addr_r = $3;
        $$->addr_w = $5;
    }
        |  '&' ',' PRDR_INTEGER
    {
        $$ = new ResetOrMaskStruct();
        $$->type = '&';
        $$->addr_r = $3;
        $$->addr_w = $3;
    }
        | '&' ',' PRDR_INTEGER ',' PRDR_INTEGER
    {
        $$ = new ResetOrMaskStruct();
        $$->type = '&';
        $$->addr_r = $3;
        $$->addr_w = $5;
    }
        |  '^' ',' PRDR_INTEGER
    {
        $$ = new ResetOrMaskStruct();
        $$->type = '^';
        $$->addr_r = $3;
        $$->addr_w = $3;
    }
        | '^' ',' PRDR_INTEGER ',' PRDR_INTEGER
    {
        $$ = new ResetOrMaskStruct();
        $$->type = '^';
        $$->addr_r = $3;
        $$->addr_w = $5;
    }
        |  '~' ',' PRDR_INTEGER
    {
        $$ = new ResetOrMaskStruct();
        $$->type = '~';
        $$->addr_r = $3;
        $$->addr_w = $3;
    }
        | '~' ',' PRDR_INTEGER ',' PRDR_INTEGER
    {
        $$ = new ResetOrMaskStruct();
        $$->type = '~';
        $$->addr_r = $3;
        $$->addr_w = $5;
    }
;

    /* Define a group object. */
group:  PRDR_GROUP PRDR_ID grpattns grpfilters '{' grouplines '}' ';'
    {
        // Add to group map.
        g_groups[*$2] = $6;

        // Add attentions to attention start list.
        if (nullptr != $3)
        {
            for (std::list<std::string *>::iterator i = $3->begin();
                 i != $3->end();
                 ++i)
            {
                g_attentionStartGroup[*(*i)] = *$2;
                delete (*i);
            }
        }

        // Add filters to group.
        if (nullptr != $4)
        {
            for (std::list<Group_Filter *>::iterator i = $4->begin();
                 i != $4->end();
                 ++i)
            {
                (*i)->AddFilter($6);
                delete (*i);
            }
        }

        // Free string for group name.
        delete $2;
    }
;

    /* Definitions for attention directives. */
grpattns:   { $$ = nullptr; }
        | PRDR_ATTNTYPE grpattns_item        { $$ = $2; }
;

    /* Individual attention types defined for group. */
grpattns_item: grpattns_item ',' PRDR_ID
    {
        $$ = $1;
        $$->push_back($3);
    }
        | PRDR_ID
    {
        $$ = new std::list<std::string *>;
        $$->push_back($1);
    }
;

    /* Definitions for filter directives. */
grpfilters:     { $$ = nullptr; }
        | PRDR_FILTER grpfilt_items        { $$ = $2; }
;

    /* Individual filter types defined for group. */
grpfilt_items: grpfilt_items ',' grpfilt_item
    {
        $$ = $1;
        $$->push_back(*($3->begin()));
    }
        | grpfilt_item
    {
        $$ = $1;
    }
;

grpfilt_item: PRDR_FILTER_SINGLE_BIT
    {
        $$ = new std::list<Group_Filter *>;
        $$->push_back(new Group_Filter_SingleBit);
    }
;

grpfilt_item: PRDR_FILTER_PRIORITY '(' bitandlist ')'
    {
        $$ = new std::list<Group_Filter *>;
        $$->push_back(new Group_Filter_Priority($3));
    }
;

grpfilt_item: PRDR_FILTER_CS_ROOT_CAUSE '(' bitandlist ')'
    {
        $$ = new std::list<Group_Filter *>;
        $$->push_back(new Group_Filter_CS_Root_Cause($3));
    }
;

grpfilt_item: PRDR_FILTER_CS_ROOT_CAUSE
    {
        $$ = new std::list<Group_Filter *>;
        $$->push_back(new Group_Filter_CS_Root_Cause_Null);
    }
;

grouplines:     { $$ = new Group(); }
        | grouplines groupline ';'
    {
        Group::merge($1,$2);
        $$ = $1;
        delete $2;
    }        | grouplines dox_comment groupline ';'
    {
        $3->setComment(*$2);
        Group::merge($1,$3);
        $$ = $1;
        delete $3;
    }
;

groupline:      { $$ = new Group(); }
        | '(' PRDR_ID ',' bitgroup ')' '?' PRDR_ID
    {
        $$ = new Group();
        $$->cv_rules.push_front(new ExprRule($2,$4,$7));
        g_references.push_front(RefPair("r",*$2));
        g_references.push_front(RefPair("a",*$7));
    }
        | '(' PRDR_ID ',' bitgroup ')' '?' action_analyse
    {
        $$ = new Group();
        $$->cv_rules.push_front(new ExprRule($2,$4,static_cast<ExprRef *>($7)->cv_name));
        g_references.push_front(RefPair("r",*$2));
        g_references.push_front(RefPair("g",*static_cast<ExprRef *>($7)->cv_name));
    }
        | PRDR_ID
    {
        $$ = new Group();
        $$->cv_rules.push_front(new ExprRef($1));
        g_references.push_front(RefPair("g",*$1));
    }
;

bitgroup: PRDR_BIT_KW '(' bitandlist ')'        { $$ = $3; }
        | PRDR_BIT_KW '(' bitorlist ')'                { $$ = $3; }
;

bitandlist: bitandlist ',' PRDR_INTEGER
    {
        $$ = new ExprOp2(Prdr::AND,
                             $1,
                             new ExprInt($3, Prdr::INT_SHORT));
    }
        | PRDR_INTEGER
    {
        $$ = new ExprInt($1, Prdr::INT_SHORT);
    }
;

bitorlist: bitorlist '|' PRDR_INTEGER
    {
        $$ = new ExprOp2(Prdr::OR,
                             $1,
                             new ExprInt($3, Prdr::INT_SHORT));
    }
        | PRDR_INTEGER '|' PRDR_INTEGER
    {
        $$ = new ExprOp2(Prdr::OR,
                             new ExprInt($1, Prdr::INT_SHORT),
                             new ExprInt($3, Prdr::INT_SHORT));
    }
;

rule: PRDR_RULE PRDR_ID '{' ruleexpr ';' '}' ';'
    {
        g_rules[*$2] = new ExprOp1(Prdr::RULE, $4);
        delete $2;
    }
    | PRDR_RULE PRDR_ID '{' PRDR_ID ':' ruleexpr ';' '}' ';'
    {
        g_rules[*$2] = new ExprOp1(Prdr::RULE,
                       new ExprAttnLink($4, $6, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr));
        delete $2;
        delete $4;
    }
    | PRDR_RULE PRDR_ID '{' PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                        '}' ';'
    {
        g_rules[*$2] = new ExprOp1(Prdr::RULE,
                       new ExprAttnLink($4, $6, $8, $10, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr));
        delete $2;
        delete $4;
        delete $8;
    }
    | PRDR_RULE PRDR_ID '{' PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                        '}' ';'
    {
        g_rules[*$2] = new ExprOp1(Prdr::RULE,
                       new ExprAttnLink($4, $6, $8, $10, $12, $14, nullptr, nullptr, nullptr, nullptr));
        delete $2;
        delete $4;
        delete $8;
        delete $12;
    }
    | PRDR_RULE PRDR_ID '{' PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                        '}' ';'
    {
        g_rules[*$2] = new ExprOp1(Prdr::RULE,
                       new ExprAttnLink($4, $6, $8, $10, $12, $14, $16, $18, nullptr, nullptr));
        delete $2;
        delete $4;
        delete $8;
        delete $12;
        delete $16;
    }
    | PRDR_RULE PRDR_ID '{' PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                        '}' ';'
    {
        g_rules[*$2] = new ExprOp1(Prdr::RULE,
                       new ExprAttnLink($4, $6, $8, $10, $12, $14, $16, $18, $20, $22));
        delete $2;
        delete $4;
        delete $8;
        delete $12;
        delete $16;
        delete $20;
    }
;

ruleexpr: ruleexpr_small                { $$ = $1; }
        | ruleexpr_small ruleop2 ruleexpr
    {
        $$ = $2;
        static_cast<ExprOp2 *>($$)->cv_arg[0] = $1;
        static_cast<ExprOp2 *>($$)->cv_arg[1] = $3;
    }
        | ruleexpr_shift                { $$ = $1; }
;

ruleexpr_small: '(' ruleexpr ')'        { $$ = $2; }
        | PRDR_ID
    {
        $$ = new ExprRef($1);
        g_references.push_front(RefPair("re", *$1));
    }
        | ruleop1 ruleexpr_small
    {
        $$ = $1;
        static_cast<ExprOp1 *>($$)->cv_arg = $2;
    }
        | PRDR_BIT_STRING
    {
        $$ = new ExprBitString(*$1);
        delete $1;
    }
        | summary
    {
        $$ = $1;
    }
;

summary: PRDR_SUMMARY '(' PRDR_INTEGER ',' PRDR_ID ')'
    {
        $$ = new ExprOp2(Prdr::SUMMARY, new ExprInt($3, Prdr::INT_SHORT),
                new ExprRef($5));
        g_references.push_front(RefPair("r", *$5));
    }
;

ruleexpr_shift: ruleexpr_small PRDR_OP_LEFTSHIFT PRDR_INTEGER
    {
        $$ = new ExprOp2(Prdr::LSHIFT,
                             $1,
                             new ExprInt($3));

    }
        | ruleexpr_small PRDR_OP_RIGHTSHIFT PRDR_INTEGER
    {
        $$ = new ExprOp2(Prdr::RSHIFT,
                             $1,
                             new ExprInt($3, Prdr::INT_SHORT));
    }
;

ruleop1: '~'
    {
        $$ = new ExprOp1(Prdr::NOT);
    }
;

ruleop2: '|'
    {
        $$ = new ExprOp2(Prdr::OR);
    }
        | '&'
    {
        $$ = new ExprOp2(Prdr::AND);
    }
        | '^'
    {
        $$ = new ExprOp2(Prdr::XOR);
    }
;

actionclass: PRDR_ACTIONCLASS PRDR_ID '{' actionlines '}' ';'
    {
        g_actionclasses[*$2] = $4;
        delete $2;
    }
    | dox_comment PRDR_ACTIONCLASS PRDR_ID '{' actionlines '}' ';'
    {
        $5->setComment(*$1);
        g_actionclasses[*$3] = $5;
        delete $3;
    }
;

actionlines:
    {
        $$ = new Group(Prdr::ACTION);
    }
        | actionlines actionline ';'
    {
        if (nullptr != $2)
            $1->cv_rules.push_back($2);
        $$ = $1;
    }
;

actionline:
    {
        $$ = nullptr;
    }
        | PRDR_ID
    {
        $$ = new ExprRef($1);
        g_references.push_front(RefPair("a", *$1));
    }
        | action_threshold          { $$ = $1; }
        | action_shared_threshold   { $$ = $1; }
        | action_analyse            { $$ = $1; }
        | action_analyse_conn       { $$ = $1; }
        | action_try                { $$ = $1; }
        | action_dump               { $$ = $1; }
        | action_callout            { $$ = $1; }
        | action_funccall           { $$ = $1; }
        | action_flag               { $$ = $1; }
        | action_capture            { $$ = $1; }
;

action_threshold: PRDR_ACT_THRESHOLD '(' ')'
    {
        $$ = new ExprAct_Thresh();
    }
    | PRDR_ACT_THRESHOLD '(' PRDR_FLD_KW '(' PRDR_INTEGER  time_units ')' ')'
    {
        $$ = new ExprAct_Thresh($5, $6);
    }
    | PRDR_ACT_THRESHOLD '(' PRDR_FLD_KW '(' PRDR_INTEGER  time_units ')' ','  PRDR_MFG_KW '(' PRDR_INTEGER  time_units ')' ')'
    {
        $$ = new ExprAct_Thresh($5, $6, $11, $12);
    }
    | PRDR_ACT_THRESHOLD '(' PRDR_FLD_KW '(' PRDR_INTEGER  time_units ')' ','  PRDR_MFG_FILE_KW  '(' PRDR_ID ')' ')'
    {
        $$ = new ExprAct_Thresh($5, $6, 0, nullptr, $11);
    }
;

action_shared_threshold: action_threshold PRDR_SHARED_KW '(' PRDR_INTEGER ')'
    {
        static_cast<ExprAct_Thresh *>($1)->cv_3 = $4;
        $$ = $1;
    }
;

time_units:
    {
        $$ = new ExprTime(0xffffffff, Prdr::PRDR_TIME_BASE_SEC);
    }
    // FIXME: (RTC 51218) It is impossible to reach a theshold of 1000 per
    //        second because PRD cannot respond to attentions that quickly (at
    //        least on the FSP). Need to add code to check if the threshold is
    //        possible to based on the reaction type per attention ratio.
    | '/' PRDR_TIME_SEC
    {
        $$ = new ExprTime(1, Prdr::PRDR_TIME_BASE_SEC);
    }
    | '/' PRDR_TIME_MIN
    {
        $$ = new ExprTime(1, Prdr::PRDR_TIME_BASE_MIN);
    }
    | '/' PRDR_TIME_HOUR
    {
        $$ = new ExprTime(1, Prdr::PRDR_TIME_BASE_HOUR);
    }
    | '/' PRDR_TIME_DAY
    {
        $$ = new ExprTime(1, Prdr::PRDR_TIME_BASE_DAY);
    }
    | '/' PRDR_INTEGER PRDR_TIME_SEC
    {
        $$ = new ExprTime($2, Prdr::PRDR_TIME_BASE_SEC);
    }
    | '/' PRDR_INTEGER PRDR_TIME_MIN
    {
        $$ = new ExprTime($2, Prdr::PRDR_TIME_BASE_MIN);
    }
    | '/' PRDR_INTEGER PRDR_TIME_HOUR
    {
        $$ = new ExprTime($2, Prdr::PRDR_TIME_BASE_HOUR);
    }
    | '/' PRDR_INTEGER PRDR_TIME_DAY
    {
        $$ = new ExprTime($2, Prdr::PRDR_TIME_BASE_DAY);
    }
;

action_analyse: PRDR_ACT_ANALYSE '(' PRDR_ID ')'
    {
        $$ = new ExprRef($3);
        g_references.push_front(RefPair("g",*$3));
    }
;

action_analyse_conn: PRDR_ACT_ANALYSE '(' PRDR_CONNECTED '(' PRDR_ID ')' ')'
    {
        $$ = new ExprAct_Analyse($5);
    }
;

action_analyse_conn: PRDR_ACT_ANALYSE '(' PRDR_CONNECTED '(' PRDR_ID ','  PRDR_INTEGER ')' ')'
    {
        $$ = new ExprAct_Analyse($5, $7);
    }
;

action_try: PRDR_ACT_TRY '(' actionline ',' actionline ')'
    {
        $$ = new ExprAct_Try($3,$5);
    }
;

action_dump: PRDR_ACT_DUMP '(' PRDR_ID ')'
    {
        $$ = new ExprAct_Dump($3);
    }
;

action_callout: PRDR_ACT_CALLOUT '(' PRDR_ID ')'
    {
        $$ = new ExprAct_Callout($3);
    }
        | PRDR_ACT_CALLOUT '(' PRDR_CONNECTED '(' PRDR_ID  action_callout_alt ')' ',' PRDR_ID ')'
    {
        $$ = new ExprAct_Callout($9, $5, Prdr::CALLOUT_GARD_CHIP, 0xffffffff, $6 );
    }
        | PRDR_ACT_CALLOUT '(' PRDR_CONNECTED '(' PRDR_ID  ',' PRDR_INTEGER action_callout_alt ')' ',' PRDR_ID ')'
    {
        $$ = new ExprAct_Callout($11, $5, Prdr::CALLOUT_GARD_CHIP, $7, $8);
    }

        | PRDR_ACT_CALLOUT '(' PRDR_PROCEDURE '(' PRDR_ID ')' ',' PRDR_ID ')'
    {
        $$ = new ExprAct_Callout($8, $5, Prdr::CALLOUT_PROC );
    }
        | PRDR_ACT_CALLOUT '(' PRDR_CONNECTED_PEER '(' PRDR_ID  ',' PRDR_INTEGER  action_callout_alt ')' ',' PRDR_ID ')'
    {
        $$ = new ExprAct_Callout($11, $5, Prdr::CALLOUT_GARD_PEER, $7, $8 );
    }
        | PRDR_ACT_CALLOUT '(' PRDR_ID ',' PRDR_ID ')'
    {
        $$ = new ExprAct_Callout($3, nullptr, Prdr::CALLOUT_GARD_SELF, 0xffffffff, nullptr, $5);
    }

        | PRDR_ACT_CALLOUT '(' PRDR_CONNECTED '(' PRDR_ID  action_callout_alt')' ',' PRDR_ID ',' PRDR_ID ')'
    {
        $$ = new ExprAct_Callout($9, $5, Prdr::CALLOUT_GARD_CHIP, 0xffffffff, $6, $11 );
    }

        | PRDR_ACT_CALLOUT '(' PRDR_CONNECTED '(' PRDR_ID  ',' PRDR_INTEGER action_callout_alt ')' ',' PRDR_ID ',' PRDR_ID  ')'
    {
        $$ = new ExprAct_Callout($11, $5, Prdr::CALLOUT_GARD_CHIP, $7, $8, $13 );
    }

        | PRDR_ACT_CALLOUT '(' PRDR_CONNECTED_PEER '(' PRDR_ID  ',' PRDR_INTEGER  action_callout_alt ')' ',' PRDR_ID ',' PRDR_ID ')'
    {
        $$ = new ExprAct_Callout($11, $5, Prdr::CALLOUT_GARD_PEER, $7, $8, $13 );
    }
;

action_callout_alt:
    {
        $$ = nullptr;
    }
        | ',' PRDR_ALTERNATE '(' actionline ')'
    {
        $$ = $4;
    }
;

action_funccall: PRDR_ACT_FUNCCALL '(' PRDR_STRING ')'
    {
        $$ = new ExprAct_Funccall($3);
    }
        | PRDR_ACT_FUNCCALL '(' PRDR_STRING ',' PRDR_ID ')'
    {
        $$ = new ExprAct_Funccall($3, $5);
    }
;

action_flag: PRDR_ACT_FLAG '(' PRDR_ID ')'
    {
        $$ = new ExprAct_Flag($3);
    }
;

action_capture: PRDR_ACT_CAPTURE '(' PRDR_ID ')'
    {
        $$ = new ExprAct_Capture($3);
    }
;


dox_comment: dox_commentblk
    {
        $$ = $1;
    }
        | dox_commentblk dox_comment
    {
        (*$1) += (*$2);
        $$ = $1;
    }
;

dox_commentblk: dox_commentline
    {
        $$ = $1;
    }
        | PRDR_DOX_ENDL
    {
        $$ = new std::string("\n");
    }
;

dox_commentline: PRDR_DOX_COMMENT
    {
        $$ = $1;
    }
;

%%
/* Additional C Code */

void yyerror(const char * s)
{
    if (yyincfiles.empty())
        fprintf(stderr, "Line %d: %s\n", yyline, s);
    else
        fprintf(stderr, "File %s Line %d: %s\n",
                yyincfiles.top().first.c_str(),
                yyline,
                s);

    g_hadError = true;
}

