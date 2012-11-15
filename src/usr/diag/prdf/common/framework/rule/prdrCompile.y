/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/framework/rule/prdrCompile.y $       */
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
    PrdrRegisterList * reglist;
    /** A single parsed register. */
    PrdrRegister * reg;
    /** A structure for the reset / mask keywords. */
    PrdrResetOrMaskStruct * reg_mask;
    /** A chip object */
    PrdrChip * chip;
    /** A sub-expression token. */
    PrdrExpr * expr;
    /** A parsed group of bit-operation / action pairs */
    PrdrGroup * grp;
    /** A list of strings */
    std::list<std::string *>* strlist;
    /** A list of filters */
    std::list<PrdrGroup_Filter *>* filterlist;
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
%token PRDR_RESET_ADDR
%token PRDR_MASK_ADDR
%token PRDR_BIT_KW
%token PRDR_OP_LEFTSHIFT
%token PRDR_OP_RIGHTSHIFT

%token PRDR_ACT_THRESHOLD
%token PRDR_ACT_ANALYSE
%token PRDR_ACT_TRY
%token PRDR_ACT_DUMP
%token PRDR_ACT_FUNCCALL
%token PRDR_ACT_GARD
%token PRDR_ACT_CALLOUT
%token PRDR_ACT_FLAG
%token PRDR_ACT_CAPTURE

%token PRDR_CONNECTED
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

    /* Terminal tokens for Doxygen-style comments */
%token <str_ptr> PRDR_DOX_COMMENT
%token <str_ptr> PRDR_DOX_ENDL

    /* Non-terminal tokens and the data-type associated with them. */
%type <reg> register reglines regline
%type <reg_mask> register_mask
%type <chip> chiplines chipline
%type <expr> ruleexpr ruleexpr_small ruleexpr_shift ruleop1 ruleop2
%type <expr> bitgroup bitandlist bitorlist
%type <expr> time_units
%type <grp> grouplines groupline
%type <grp> actionlines

%type <expr> actionline
%type <expr> action_threshold action_shared_threshold action_analyse
%type <expr> action_analyse_conn action_try action_capture
%type <expr> action_dump action_gard action_callout action_funccall action_flag
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
        if (NULL == $4)
            $4 = new PrdrChip();

        // Assign chip's shortname from ID.
        $4->cv_sname = $2;

        // Set current chip to be this chip.
        g_currentChip = $4;
    }
;

    /* Any number of lines can make up a chiplines token.  */
chiplines:  { $$ = NULL; }  // empty line.
        | chiplines chipline ';'
    {
        // Merge the chip lines together into a single object as needed.
        if (NULL != $1)
        {
            if (NULL == $2)
                $$ = NULL;
            else
            {
                // Both are non-NULL, merge.
                PrdrChip::merge($1, $2);
                $$ = $1;
                delete $2;
            }
        }
        else
        {
            if (NULL == $2)
                $$ = NULL;
            else
                $$ = $2;
        }
    }

;

    /* Create a chip object based on the contents of the line. */
chipline:   { $$ = NULL; } // allow a free ;.
        | PRDR_CHIPID PRDR_INTEGER
    {
        $$ = new PrdrChip();
        $$->cv_chipid = $2;
    }
        | PRDR_SIGNATURE_OFFSET PRDR_INTEGER
    {
        $$ = new PrdrChip();
        $$->cv_signatureOffset = $2;
    }
        | PRDR_SIGNATURE_EXTRA '(' PRDR_ID ',' PRDR_INTEGER ','
            PRDR_STRING ',' PRDR_STRING ')'
    {
        $$ = new PrdrChip();
        $$->cv_sigExtras.push_back(PrdrExtraSignature($5, $7, $9));
    }
        | PRDR_TARGETTYPE PRDR_ID
    {
        $$ = new PrdrChip();
        $$->cv_targetType = prdrActionArgMap(*$2);
    }
        | PRDR_NAME_KW PRDR_STRING
    {
        $$ = new PrdrChip();
        $$->cv_name = $2;
    }
        | register        // register non-terminal token.
    {
        $$ = new PrdrChip();
        $$->cv_reglist.push_back($1);
    }
        | PRDR_SCOMLEN PRDR_INTEGER
    {
        $$ = new PrdrChip();
        $$->cv_scomlen = $2;
    }
        | PRDR_ACT_DUMP PRDR_ID                        //@ecdf
    {
        $$ = new PrdrChip();
        $$->cv_dumptype = prdrActionArgMap(*$2);
    }
;

    /* A register is the register-keyword, id, and a number of "lines". */
register: PRDR_REGISTER PRDR_ID '{' reglines '}'
    {
        // Create register object as needed.
        if (NULL == $4)
            $$ = new PrdrRegister();
        else
            $$ = $4;

        // Assign short-name.
        $$->cv_sname = $2;
    }
;
    /* Any number of lines can make up a reglines token.  */
reglines:   { $$ = NULL; }
        | reglines regline ';'
    {
        // Merge register lines as needed.
        if (NULL != $1)
        {
            if (NULL == $2)
                $$ = NULL;
            else
            {
                // Both are non-NULL, merge.
                PrdrRegister::merge($1, $2);
                $$ = $1;
                delete $2;
            }
        }
        else
        {
            if (NULL == $2)
                $$ = NULL;
            else
                $$ = $2;
        }
    }
;

    /* Define all of the lines (expressions) that can be found in a register */
regline:    { $$ = NULL; }
        | PRDR_NAME_KW PRDR_STRING
    {
        $$ = new PrdrRegister();
        $$->cv_name = $2;
    }
        | PRDR_NAME_KW PRDR_ID
    {
        $$ = new PrdrRegister();
        $$->cv_name = $2;
    }
        | PRDR_SCOMADDR PRDR_INTEGER
    {
        $$ = new PrdrRegister();
        $$->cv_scomaddr = $2;
    }
        | PRDR_SCOMLEN PRDR_INTEGER
    {
        $$ = new PrdrRegister();
        $$->cv_scomlen = $2;

        // Indicate that the register contains a non-default scomlen.
        $$->cv_flags |= Prdr::PRDR_REGISTER_SCOMLEN;
    }
        | PRDR_RESET_ADDR '(' register_mask ')'
    {
        $$ = new PrdrRegister();

        // Add reset register to list.
        $$->cv_resets.push_back(*$3);
        delete $3;
    }
        | PRDR_MASK_ADDR '(' register_mask ')'
    {
        $$ = new PrdrRegister();

        // Add mask register to list.
        $$->cv_masks.push_back(*$3);
        delete $3;
    }
        | PRDR_ACT_CAPTURE PRDR_GROUP PRDR_ID
    {
        $$ = new PrdrRegister();

        // Define capture group.
        PrdrCaptureReqStruct tmp;
        tmp.type = PrdrCaptureReqStruct::PRDR_CAPTURE_GROUPID;
        tmp.data[0] = prdrCaptureGroupMap(*$3);

        $$->cv_captures.push_back(tmp);
    }
//@jl04 Add  a new capture "type" here for regsiters.
        | PRDR_ACT_CAPTURE PRDR_TYPE PRDR_ID
    {
        $$ = new PrdrRegister();

        // Define capture type.
        PrdrCaptureReqStruct tmp;
        tmp.type = PrdrCaptureReqStruct::PRDR_CAPTURE_TYPE;
        tmp.data[0] = prdrCaptureTypeMap(*$3);
        $$->cv_captures.push_back(tmp);
    }
//@jl04 End.

        |  PRDR_ACT_CAPTURE PRDR_REQUIRED_KW PRDR_CONNECTED '(' PRDR_ID  ')'
    {
        $$ = new PrdrRegister();

        // Define capture "connected" requirement.
        PrdrCaptureReqStruct tmp;
        tmp.type = PrdrCaptureReqStruct::PRDR_CAPTURE_CONN;
        tmp.data[0] = prdrActionArgMap(*$5);
        tmp.data[1] = 0;

        $$->cv_captures.push_back(tmp);
    }
        | PRDR_ACT_CAPTURE PRDR_REQUIRED_KW PRDR_CONNECTED '(' PRDR_ID ',' PRDR_INTEGER ')'
    {
        $$ = new PrdrRegister();

        // Define capture "connected" requirement.
        PrdrCaptureReqStruct tmp;
        tmp.type = PrdrCaptureReqStruct::PRDR_CAPTURE_CONN;
        tmp.data[0] = prdrActionArgMap(*$5);
        tmp.data[1] = $7;

        $$->cv_captures.push_back(tmp);
    }
        | PRDR_ACT_CAPTURE PRDR_REQUIRED_KW PRDR_ACT_FUNCCALL '(' PRDR_STRING ')'
    {
        $$ = new PrdrRegister();

        // Define funccall requirement.
        PrdrCaptureReqStruct tmp;
        tmp.type = PrdrCaptureReqStruct::PRDR_CAPTURE_FUNC;
        tmp.str = *$5;

        $$->cv_captures.push_back(tmp);
    }
;

    /* Define the possible reset/mask instructions. */
register_mask: '|' ',' PRDR_INTEGER
    {
        $$ = new PrdrResetOrMaskStruct();
        $$->type = '|';
        $$->addr_r = $3;
        $$->addr_w = $3;
    }
        | '|' ',' PRDR_INTEGER ',' PRDR_INTEGER
    {
        $$ = new PrdrResetOrMaskStruct();
        $$->type = '|';
        $$->addr_r = $3;
        $$->addr_w = $5;
    }
        |  '&' ',' PRDR_INTEGER
    {
        $$ = new PrdrResetOrMaskStruct();
        $$->type = '&';
        $$->addr_r = $3;
        $$->addr_w = $3;
    }
        | '&' ',' PRDR_INTEGER ',' PRDR_INTEGER
    {
        $$ = new PrdrResetOrMaskStruct();
        $$->type = '&';
        $$->addr_r = $3;
        $$->addr_w = $5;
    }
        |  '^' ',' PRDR_INTEGER
    {
        $$ = new PrdrResetOrMaskStruct();
        $$->type = '^';
        $$->addr_r = $3;
        $$->addr_w = $3;
    }
        | '^' ',' PRDR_INTEGER ',' PRDR_INTEGER
    {
        $$ = new PrdrResetOrMaskStruct();
        $$->type = '^';
        $$->addr_r = $3;
        $$->addr_w = $5;
    }
        |  '~' ',' PRDR_INTEGER
    {
        $$ = new PrdrResetOrMaskStruct();
        $$->type = '~';
        $$->addr_r = $3;
        $$->addr_w = $3;
    }
        | '~' ',' PRDR_INTEGER ',' PRDR_INTEGER
    {
        $$ = new PrdrResetOrMaskStruct();
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
        if (NULL != $3)
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
        if (NULL != $4)
        {
            for (std::list<PrdrGroup_Filter *>::iterator i = $4->begin();
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
grpattns:   { $$ = NULL; }
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
grpfilters:     { $$ = NULL; }
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
        $$ = new std::list<PrdrGroup_Filter *>;
        $$->push_back(new PrdrGroup_Filter_SingleBit);
    }
;

grpfilt_item: PRDR_FILTER_PRIORITY '(' bitandlist ')'
    {
        $$ = new std::list<PrdrGroup_Filter *>;
        $$->push_back(new PrdrGroup_Filter_Priority($3));
    }
;



grouplines:     { $$ = new PrdrGroup(); }
        | grouplines groupline ';'
    {
        PrdrGroup::merge($1,$2);
        $$ = $1;
        delete $2;
    }        | grouplines dox_comment groupline ';'
    {
        $3->setComment(*$2);
        PrdrGroup::merge($1,$3);
        $$ = $1;
        delete $3;
    }
;

groupline:      { $$ = new PrdrGroup(); }
        | '(' PRDR_ID ',' bitgroup ')' '?' PRDR_ID
    {
        $$ = new PrdrGroup();
        $$->cv_rules.push_front(new PrdrExprRule($2,$4,$7));
        g_references.push_front(PrdrRefPair("r",*$2));
        g_references.push_front(PrdrRefPair("a",*$7));
    }
        | '(' PRDR_ID ',' bitgroup ')' '?' action_analyse
    {
        $$ = new PrdrGroup();
        $$->cv_rules.push_front(new PrdrExprRule($2,$4,static_cast<PrdrExprRef *>($7)->cv_name));
        g_references.push_front(PrdrRefPair("r",*$2));
        g_references.push_front(PrdrRefPair("g",*static_cast<PrdrExprRef *>($7)->cv_name));
    }
        | PRDR_ID
    {
        $$ = new PrdrGroup();
        $$->cv_rules.push_front(new PrdrExprRef($1));
        g_references.push_front(PrdrRefPair("g",*$1));
    }
;

bitgroup: PRDR_BIT_KW '(' bitandlist ')'        { $$ = $3; }
        | PRDR_BIT_KW '(' bitorlist ')'                { $$ = $3; }
;

// TODO: Change to & instead of ,
bitandlist: bitandlist ',' PRDR_INTEGER
    {
        $$ = new PrdrExprOp2(Prdr::AND,
                             $1,
                             new PrdrExprInt($3, Prdr::INT_SHORT));
    }
        | PRDR_INTEGER
    {
        $$ = new PrdrExprInt($1, Prdr::INT_SHORT);
    }
;

bitorlist: bitorlist '|' PRDR_INTEGER
    {
        $$ = new PrdrExprOp2(Prdr::OR,
                             $1,
                             new PrdrExprInt($3, Prdr::INT_SHORT));
    }
        | PRDR_INTEGER '|' PRDR_INTEGER
    {
        $$ = new PrdrExprOp2(Prdr::OR,
                             new PrdrExprInt($1, Prdr::INT_SHORT),
                             new PrdrExprInt($3, Prdr::INT_SHORT));
    }
;

// TODO: Merge attention types.
rule: PRDR_RULE PRDR_ID '{' ruleexpr ';' '}' ';'
    {
        g_rules[*$2] = new PrdrExprOp1(Prdr::RULE, $4);
        delete $2;
    }
    | PRDR_RULE PRDR_ID '{' PRDR_ID ':' ruleexpr ';' '}' ';'
    {
        g_rules[*$2] = new PrdrExprOp1(Prdr::RULE,
                       new PrdrExprAttnLink($4, $6, NULL, NULL, NULL, NULL, NULL, NULL));
        delete $2;
        delete $4;
    }
    | PRDR_RULE PRDR_ID '{' PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                        '}' ';'
    {
        g_rules[*$2] = new PrdrExprOp1(Prdr::RULE,
                       new PrdrExprAttnLink($4, $6, $8, $10, NULL, NULL, NULL, NULL));
        delete $2;
        delete $4;
        delete $8;
    }
    | PRDR_RULE PRDR_ID '{' PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                            PRDR_ID ':' ruleexpr ';'
                        '}' ';'
    {
        g_rules[*$2] = new PrdrExprOp1(Prdr::RULE,
                       new PrdrExprAttnLink($4, $6, $8, $10, $12, $14, NULL, NULL));
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
        g_rules[*$2] = new PrdrExprOp1(Prdr::RULE,
                       new PrdrExprAttnLink($4, $6, $8, $10, $12, $14, $16, $18));
        delete $2;
        delete $4;
        delete $8;
        delete $12;
        delete $16;
    }
;

ruleexpr: ruleexpr_small                { $$ = $1; }
        | ruleexpr_small ruleop2 ruleexpr
    {
        $$ = $2;
        static_cast<PrdrExprOp2 *>($$)->cv_arg[0] = $1;
        static_cast<PrdrExprOp2 *>($$)->cv_arg[1] = $3;
    }
        | ruleexpr_shift                { $$ = $1; }
;

ruleexpr_small: '(' ruleexpr ')'        { $$ = $2; }
        | PRDR_ID
    {
        $$ = new PrdrExprRef($1);
        g_references.push_front(PrdrRefPair("re", *$1));
    }
        | ruleop1 ruleexpr_small
    {
        $$ = $1;
        static_cast<PrdrExprOp1 *>($$)->cv_arg = $2;
    }
        | PRDR_BIT_STRING
    {
        $$ = new PrdrExprBitString(*$1);
        delete $1;
    }
;

ruleexpr_shift: ruleexpr_small PRDR_OP_LEFTSHIFT PRDR_INTEGER
    {
        $$ = new PrdrExprOp2(Prdr::LSHIFT,
                             $1,
                             new PrdrExprInt($3));

    }
        | ruleexpr_small PRDR_OP_RIGHTSHIFT PRDR_INTEGER
    {
        $$ = new PrdrExprOp2(Prdr::RSHIFT,
                             $1,
                             new PrdrExprInt($3, Prdr::INT_SHORT));
    }
;

ruleop1: '~'
    {
        $$ = new PrdrExprOp1(Prdr::NOT);
    }
;

ruleop2: '|'
    {
        $$ = new PrdrExprOp2(Prdr::OR);
    }
        | '&'
    {
        $$ = new PrdrExprOp2(Prdr::AND);
    }
        | '^'
    {
        $$ = new PrdrExprOp2(Prdr::XOR);
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
        $$ = new PrdrGroup(Prdr::ACTION);
    }
        | actionlines actionline ';'
    {
        if (NULL != $2)
            $1->cv_rules.push_back($2);
        $$ = $1;
    }
;

actionline:
    {
        $$ = NULL;
    }
        | PRDR_ID
    {
        $$ = new PrdrExprRef($1);
        g_references.push_front(PrdrRefPair("a", *$1));
    }
        | action_threshold          { $$ = $1; }
        | action_shared_threshold   { $$ = $1; }
        | action_analyse            { $$ = $1; }
        | action_analyse_conn       { $$ = $1; }
        | action_try                { $$ = $1; }
        | action_dump               { $$ = $1; }
        | action_gard               { $$ = $1; }
        | action_callout            { $$ = $1; }
        | action_funccall           { $$ = $1; }
        | action_flag               { $$ = $1; }
        | action_capture            { $$ = $1; }
;

action_threshold: PRDR_ACT_THRESHOLD '(' ')'
    {
        $$ = new PrdrExprAct_Thresh();
    }
    | PRDR_ACT_THRESHOLD '(' PRDR_FLD_KW '(' PRDR_INTEGER  time_units ')' ')'
    {
        $$ = new PrdrExprAct_Thresh($5, $6);
    }
    | PRDR_ACT_THRESHOLD '(' PRDR_FLD_KW '(' PRDR_INTEGER  time_units ')' ','  PRDR_MFG_KW '(' PRDR_INTEGER  time_units ')' ')'
    {
        $$ = new PrdrExprAct_Thresh($5, $6, $11, $12);
    }
    | PRDR_ACT_THRESHOLD '(' PRDR_FLD_KW '(' PRDR_INTEGER  time_units ')' ','  PRDR_MFG_FILE_KW  '(' PRDR_ID ')' ')'
    {
        $$ = new PrdrExprAct_Thresh($5, $6, 0, NULL, $11);
    }
;

action_shared_threshold: action_threshold PRDR_SHARED_KW '(' PRDR_INTEGER ')'
    {
        static_cast<PrdrExprAct_Thresh *>($1)->cv_3 = $4;
        $$ = $1;
    }
;

time_units:
    {
        $$ = new PrdrExprTime(0xffffffff, Prdr::PRDR_TIME_BASE_SEC);
    }
    // FIXME: (RTC 51218) It is impossible to reach a theshold of 1000 per
    //        second because PRD cannot respond to attentions that quickly (at
    //        least on the FSP). Need to add code to check if the threshold is
    //        possible to based on the reaction type per attention ratio.
    | '/' PRDR_TIME_SEC
    {
        $$ = new PrdrExprTime(1, Prdr::PRDR_TIME_BASE_SEC);
    }
    | '/' PRDR_TIME_MIN
    {
        $$ = new PrdrExprTime(1, Prdr::PRDR_TIME_BASE_MIN);
    }
    | '/' PRDR_TIME_HOUR
    {
        $$ = new PrdrExprTime(1, Prdr::PRDR_TIME_BASE_HOUR);
    }
    | '/' PRDR_TIME_DAY
    {
        $$ = new PrdrExprTime(1, Prdr::PRDR_TIME_BASE_DAY);
    }
    | '/' PRDR_INTEGER PRDR_TIME_SEC
    {
        $$ = new PrdrExprTime($2, Prdr::PRDR_TIME_BASE_SEC);
    }
    | '/' PRDR_INTEGER PRDR_TIME_MIN
    {
        $$ = new PrdrExprTime($2, Prdr::PRDR_TIME_BASE_MIN);
    }
    | '/' PRDR_INTEGER PRDR_TIME_HOUR
    {
        $$ = new PrdrExprTime($2, Prdr::PRDR_TIME_BASE_HOUR);
    }
    | '/' PRDR_INTEGER PRDR_TIME_DAY
    {
        $$ = new PrdrExprTime($2, Prdr::PRDR_TIME_BASE_DAY);
    }
;

action_analyse: PRDR_ACT_ANALYSE '(' PRDR_ID ')'
    {
        $$ = new PrdrExprRef($3);
        g_references.push_front(PrdrRefPair("g",*$3));
    }
;

action_analyse_conn: PRDR_ACT_ANALYSE '(' PRDR_CONNECTED '(' PRDR_ID ')' ')'
    {
        $$ = new PrdrExprAct_Analyse($5);
    }
;

action_analyse_conn: PRDR_ACT_ANALYSE '(' PRDR_CONNECTED '(' PRDR_ID ','  PRDR_INTEGER ')' ')'
    {
        $$ = new PrdrExprAct_Analyse($5, $7);
    }
;

action_try: PRDR_ACT_TRY '(' actionline ',' actionline ')'
    {
        $$ = new PrdrExprAct_Try($3,$5);
    }
;

action_dump: PRDR_ACT_DUMP '(' PRDR_ID ')'  //@ecdf
    {
        $$ = new PrdrExprAct_Dump($3);
    }
    // TODO: Allow Dump connected.
;

action_gard: PRDR_ACT_GARD '(' PRDR_ID ')'
    {
        $$ = new PrdrExprAct_Gard($3);
    }
;

action_callout: PRDR_ACT_CALLOUT '(' PRDR_ID ')'
    {
        $$ = new PrdrExprAct_Callout($3);
    }
        | PRDR_ACT_CALLOUT '(' PRDR_CONNECTED '(' PRDR_ID  action_callout_alt ')' ',' PRDR_ID ')'
    {
        $$ = new PrdrExprAct_Callout($9, $5, PrdrExprAct_Callout::CALLOUT_CHIP, 0xffffffff, $6);
    }
        | PRDR_ACT_CALLOUT '(' PRDR_CONNECTED '(' PRDR_ID  ',' PRDR_INTEGER action_callout_alt ')' ',' PRDR_ID ')'
    {
        $$ = new PrdrExprAct_Callout($11, $5, PrdrExprAct_Callout::CALLOUT_CHIP, $7, $8);
    }


        | PRDR_ACT_CALLOUT '(' PRDR_PROCEDURE '(' PRDR_ID ')' ',' PRDR_ID ')'
    {
        $$ = new PrdrExprAct_Callout($8, $5, PrdrExprAct_Callout::CALLOUT_PROC);
    }

;

action_callout_alt:
    {
        $$ = NULL;
    }
        | ',' PRDR_ALTERNATE '(' actionline ')'
    {
        $$ = $4;
    }
;

action_funccall: PRDR_ACT_FUNCCALL '(' PRDR_STRING ')'
    {
        $$ = new PrdrExprAct_Funccall($3);
    }
        | PRDR_ACT_FUNCCALL '(' PRDR_STRING ',' PRDR_ID ')'
    {
        $$ = new PrdrExprAct_Funccall($3, $5);
    }
;

action_flag: PRDR_ACT_FLAG '(' PRDR_ID ')'
    {
        $$ = new PrdrExprAct_Flag($3);
    }
;

action_capture: PRDR_ACT_CAPTURE '(' PRDR_ID ')'
    {
        $$ = new PrdrExprAct_Capture($3);
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

