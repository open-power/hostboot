/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/ifcompiler/initCompiler.y $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
// Change Log *************************************************************************************
//                                                                      
//  Flag Track    Userid   Date       Description                
//  ---- -------- -------- --------   -------------------------------------------------------------
//        D754106  dgilbert 06/14/10  Create
//        D774126  dgilbert 09/30/10  Add ERROR: to yyerror message
//                 andrewg  09/19/11  Updates based on review
//                 camvanng 11/08/11  Added support for attribute enums
//                 andrewg  11/09/11  Refactor to use common include with hwp framework.
//                 camvanng 12/12/11  Support multiple address ranges within a SCOM address
//                 camvanng 01/20/12  Support for using a range indexes for array attributes
//                 camvanng 02/14/12  Support binary and hex scom addresses
//                                    Support for array at beginning of scom address
//                 camvanng 04/16/12  Support defines for SCOM address
//                                    Support defines for bits, scom_data and attribute columns
//                                    Delete obsolete code for defines support
//                 camvanng 05/22/12  Ability to do simple operations on attributes
//                                    in the scom_data column
//                 camvanng 06/11/12  Ability to do logical operations with attribute columns
//                                    Fix shift/reduce warnings from yacc
//                 camvanng 06/15/12  Ability to do bitwise OR and AND operations
//                 camvanng 06/27/12  Improve error and debug tracing
// End Change Log *********************************************************************************
// $Id: initCompiler.y,v 1.10 2014/06/30 19:49:24 thi Exp $
/**
 * @file initCompiler.y
 * @brief Contains the yacc/bison code for parsing an initfile.
 * 
 * This code runs as part of the build process to generate a
 * byte-coded representation of an initfile
 */
%{
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <initCompiler.H>
#include <initSymbols.H>


init::Scom * current_scom = NULL;

extern int yylex();
void yyerror(const char * s);

int scom;

%}

/* Union for the yylval variable in lex or $$ variables in bsion code.
 * Used to store the data associated with a parsed token.
 */
%union{
    uint32_t integer;
    uint64_t uint64;
    std::string * str_ptr;
    init::Rpn * rpn_ptr;
}

    /* indicates the name for the start symbol */
%start input

    /* Define terminal symbols and the union type
     * associated with each. */

%token <integer> INIT_INTEGER
%token <uint64>  INIT_INT64
%token <str_ptr>  INIT_INT64_STR
%token <str_ptr>  INIT_SCOM_ADDR
%token <str_ptr>  INIT_SCOM_SUFFIX
%token <str_ptr>  INIT_BINARY_STR
%token <str_ptr>  INIT_SCOM_ADDR_BIN
%token <str_ptr>  INIT_SCOM_SUFFIX_BIN
%token <uint64>  INIT_SCOM_DATA
%token <str_ptr> INIT_ID
%token <str_ptr> INIT_VERSIONS
%token <str_ptr> ATTRIBUTE_INDEX
%token <str_ptr> ATTRIBUTE_ENUM


    /* Define terminal symbols that don't have any associated data */

%token INIT_VERSION
%token INIT_ENDINITFILE
%token INIT_BITS
%token INIT_EXPR
%token INIT_TARG
%token INIT_EQ
%token INIT_NE
%token INIT_LE
%token INIT_GE
%token INIT_SCANINIT
%token INIT_SCOMINIT
%token INIT_SCOM
%token INIT_SCOMD


    /* non-terminal tokens and the union data-type associated with them */

%type <str_ptr> bitsrows
%type <rpn_ptr> expr id_colexpr id_col num_list scomdexpr





/* top is lowest precedent - done last */
%left INIT_LOGIC_OR
%left INIT_LOGIC_AND
%left '|'     /* bitwise OR */
%left '^'     /* bitwise XOR */
%left '&'     /* bitwise AND */
%left INIT_EQ INIT_NE
%left INIT_LE INIT_GE '<' '>'
%left INIT_SHIFT_RIGHT INIT_SHIFT_LEFT
%left '-' '+'
%left '*' '/' '%'
%right '!' '~'   /* logic negation  bitwise complement*/
%left ATTRIBUTE_INDEX /* highest precedence */
/* bottom is highest precedent - done first */




%%
/* Grammars */
    /* the 'input' is simply all the lines */
input:
        | input line
;

line:   scom
        | cvs_versions
        | syntax_version
        | INIT_ENDINITFILE   {}
;


cvs_versions:   INIT_VERSIONS
            {
                yyscomlist->set_cvs_versions($1); delete $1;
            }
;

syntax_version: INIT_VERSION '=' INIT_INTEGER
            { 
                yyscomlist->set_syntax_version($3);
            }
;

scom:       INIT_SCOM {current_scom = new init::Scom(yyscomlist->get_symbols(),yyline);}
            | scom scomaddr '{' scombody '}'
		{
                     /* printf("Found an INIT_SCOM!\n"); */
                    /* current_scom = new init::Scom(yyscomlist->get_symbols(),yyline); */
                    yyscomlist->insert(current_scom);
                    init::dbg << current_scom->addr_listing() << std::endl;
                }
;	

scomaddr: 
      scomaddr_hex { /*printf("Found a hex scom address\n");*/ }
      | scomaddr_bin { /*printf("Found a binary scom address\n");*/
                       current_scom->append_scom_address_bin(); }
      | scomaddr '.' scomaddr_hex { /*printf("Found a hex scom address 2\n");*/ }
      | scomaddr '.' scomaddr_bin { /*printf("Append binary scom address 2\n");*/
                                current_scom->append_scom_address_bin(); }
;



scomaddr_hex:  INIT_SCOM_ADDR { /*printf("Found an INIT_SCOM_ADDR %s\n", (*($1)).c_str());*/
                                current_scom->set_scom_address(*($1)); delete $1; }
                | scom_list { current_scom->copy_dup_scom_address(); }
                | INIT_SCOM_SUFFIX { current_scom->set_scom_suffix(*($1)); delete $1; }
                | scomaddr_hex scom_list { /*printf("Found a scom_list 2\n");*/
                                           current_scom->copy_dup_scom_address(); }
                | scomaddr_hex INIT_SCOM_SUFFIX { /*printf("Found a scom suffix %s\n", (*($2)).c_str());*/
                                                  current_scom->set_scom_suffix(*($2)); delete $2;}
;


scom_list:       INIT_INT64_STR                { current_scom->dup_scom_address(*($1));delete $1;}
                | scom_list ',' INIT_INT64_STR  { current_scom->dup_scom_address(*($3));delete $3;}
;


scomaddr_bin:    INIT_SCOM_ADDR_BIN { /*printf("Found an INIT_SCOM_ADDR_BIN %s\n", (*($1)).c_str());*/
                                      current_scom->set_scom_address_bin(*($1)); delete $1; }
                | scom_bin_list { /*printf("Found a scom_bin_list\n");*/
                                  current_scom->copy_dup_scom_address_bin(); }
                | scomaddr_bin INIT_SCOM_ADDR_BIN { /*printf("Found an INIT_SCOM_ADDR_BIN 2 %s\n", (*($2)).c_str());*/
                                                    current_scom->set_scom_suffix_bin(*($2)); delete $2;}
                | scomaddr_bin scom_bin_list { /*printf("Found a scom_bin_list 2\n");*/
                                               current_scom->copy_dup_scom_address_bin(); }
                | scomaddr_bin INIT_SCOM_SUFFIX_BIN { /*printf("Found a scom binary suffix %s\n", (*($2)).c_str());*/
                                                      current_scom->set_scom_suffix_bin(*($2)); delete $2;}
;

scom_bin_list:   INIT_BINARY_STR { current_scom->dup_scom_address_bin(*($1));delete $1; }
                | scom_bin_list ',' INIT_BINARY_STR { current_scom->dup_scom_address_bin(*($3));delete $3; }
;

    /* The scombody was reformatted by the scanner
     * colname1 , row1 , row 2, ... , row n ;
     * colname2 , row1 , row 2, ... , row n ;
     */

scombody:        scombodyline ';' {}
                | scombody scombodyline ';' {}
;

scombodyline:   INIT_SCOMD  ',' scomdrows  {}
                | INIT_BITS ',' bitsrows  {}
                | INIT_EXPR ',' exprrows  { init::dbg << "Add col EXPR" << endl; current_scom->add_col("EXPR"); }
                | INIT_ID   ',' idrows  {
                                            current_scom->add_col(*($1));
                                            init::dbg << "Add col " << *($1) << endl;
                                            delete $1;
                                        }
;


scomdrows:      scomdexpr  {
                          /* printf("\n\nscomdrows - RPN Address:0x%X\n\n\n",$1); */
                          init::dbg << $1->listing("Length scom RPN");
                          current_scom->add_scom_rpn($1);
                       }
                | scomdrows ',' scomdexpr {  init::dbg << $3->listing("Length scom RPN"); current_scom->add_scom_rpn($3); }
;
    
scomdexpr:   INIT_INTEGER               { $$= new init::Rpn($1,yyscomlist->get_symbols());}
        | INIT_ID                       { $$= new init::Rpn(*($1),yyscomlist->get_symbols()); delete $1;}
        | ATTRIBUTE_ENUM                { $$= new init::Rpn((yyscomlist->get_symbols())->get_attr_enum_val(*($1)),yyscomlist->get_symbols()); delete $1; }
        | INIT_INT64                    { $$=new init::Rpn($1,yyscomlist->get_symbols()); }
        | scomdexpr ATTRIBUTE_INDEX     { $1->push_array_index(*($2)); delete $2; }
        | scomdexpr INIT_SHIFT_RIGHT scomdexpr  { $$ = $1->push_merge($3,SHIFTRIGHT); }
        | scomdexpr INIT_SHIFT_LEFT scomdexpr   { $$ = $1->push_merge($3,SHIFTLEFT); }
        | scomdexpr '+' scomdexpr               { $$ = $1->push_merge($3,PLUS); }
        | scomdexpr '-' scomdexpr               { $$ = $1->push_merge($3,MINUS); }
        | scomdexpr '*' scomdexpr               { $$ = $1->push_merge($3,MULT); }
        | scomdexpr '/' scomdexpr               { $$ = $1->push_merge($3,DIVIDE); }
        | scomdexpr '%' scomdexpr               { $$ = $1->push_merge($3,MOD); }
        | scomdexpr '&' scomdexpr               { $$ = $1->push_merge($3,BITWISEAND); }
        | scomdexpr '|' scomdexpr               { $$ = $1->push_merge($3,BITWISEOR); }
        | '!' scomdexpr                         { $$ = $2->push_op(NOT); }
        | '(' scomdexpr ')'             { $$ = $2; }
;

bitsrows:       bitrange {}
                | bitsrows ',' bitrange {}
;

bitrange:       INIT_INTEGER { current_scom->add_bit_range($1,$1);  }
                | INIT_INTEGER ':' INIT_INTEGER 
                    { current_scom->add_bit_range($1,$3); }
;

exprrows:       expr { init::dbg << $1->listing(NULL); current_scom->add_row_rpn($1); }
                | exprrows ',' expr
                        { init::dbg << $3->listing(NULL); current_scom->add_row_rpn($3); }
;

idrows:         id_colexpr  { init::dbg << $1->listing(NULL); current_scom->add_row_rpn($1); }
                | idrows ',' id_colexpr { init::dbg << $3->listing(NULL); current_scom->add_row_rpn($3); }
;

        // TODO num_list could be VARs,LITs, or even ranges eg {1,2..5,7}

id_colexpr: id_col { $1->push_op(EQ); }
            | INIT_EQ id_col { $$ = $2; $2->push_op(EQ); }
            | INIT_NE id_col { $$ = $2; $2->push_op(NE); }
            | INIT_LE id_col { $$ = $2; $2->push_op(LE); }
            | INIT_GE id_col { $$ = $2; $2->push_op(GE); }
            | '<' id_col     { $$ = $2; $2->push_op(LT); }
            | '>' id_col     { $$ = $2; $2->push_op(GT); }
;

id_col:         INIT_ID { $$ = new init::Rpn(*($1),yyscomlist->get_symbols()); delete $1; }  
                | INIT_INTEGER { $$ = new init::Rpn($1,yyscomlist->get_symbols()); }
                | '{' num_list '}' { $$ = $2; $2->push_op(LIST); }
                | ATTRIBUTE_ENUM { $$ = new init::Rpn((yyscomlist->get_symbols())->get_attr_enum_val(*($1)),yyscomlist->get_symbols()); delete $1; }  
;

num_list:       INIT_INTEGER { $$ = new init::Rpn($1,yyscomlist->get_symbols()); }
                | INIT_ID    { $$ = new init::Rpn(*($1),yyscomlist->get_symbols()); }
                | num_list ',' INIT_INTEGER { $$ = $1; $1->merge(new init::Rpn($3,yyscomlist->get_symbols())); }
                | num_list ',' INIT_ID { $$ = $1; $1->merge(new init::Rpn(*($3),yyscomlist->get_symbols())); }
                | ATTRIBUTE_ENUM { $$ = new init::Rpn((yyscomlist->get_symbols())->get_attr_enum_val(*($1)),yyscomlist->get_symbols()); }
;

 /* expr should return an RPN string of some kind */
expr:   INIT_INTEGER                    { $$= new init::Rpn($1,yyscomlist->get_symbols()); }
        | INIT_ID                       { $$= new init::Rpn(*($1),yyscomlist->get_symbols()); delete $1; }
        | ATTRIBUTE_ENUM                { $$= new init::Rpn((yyscomlist->get_symbols())->get_attr_enum_val(*($1)),yyscomlist->get_symbols()); delete $1; }
        | INIT_INT64                    { $$=new init::Rpn($1,yyscomlist->get_symbols()); }
        | expr ATTRIBUTE_INDEX          { $1->push_array_index(*($2)); delete $2; }
        | expr INIT_LOGIC_OR expr       { $$ = $1->push_merge($3,OR); }
        | expr INIT_LOGIC_AND expr      { $$ = $1->push_merge($3,AND); }
        | expr INIT_EQ expr             { $$ = $1->push_merge($3,EQ); }
        | expr INIT_NE expr             { $$ = $1->push_merge($3,NE); }
        | expr INIT_LE expr             { $$ = $1->push_merge($3,LE); }
        | expr INIT_GE expr             { $$ = $1->push_merge($3,GE); }
        | expr '<' expr                 { $$ = $1->push_merge($3,LT); }
        | expr '>' expr                 { $$ = $1->push_merge($3,GT); }
        | expr INIT_SHIFT_RIGHT expr    { $$ = $1->push_merge($3,SHIFTRIGHT); }
        | expr INIT_SHIFT_LEFT expr     { $$ = $1->push_merge($3,SHIFTLEFT); }
        | expr '+' expr                 { $$ = $1->push_merge($3,PLUS); }
        | expr '-' expr                 { $$ = $1->push_merge($3,MINUS); }
        | expr '*' expr                 { $$ = $1->push_merge($3,MULT); }
        | expr '/' expr                 { $$ = $1->push_merge($3,DIVIDE); }
        | expr '%' expr                 { $$ = $1->push_merge($3,MOD); }
        | expr '&' expr                 { $$ = $1->push_merge($3,BITWISEAND); }
        | expr '|' expr                 { $$ = $1->push_merge($3,BITWISEOR); }
        | '!' expr                      { $$ = $2->push_op(NOT); }
        | '(' expr ')'                  { $$ = $2; }
;


%%

void yyerror(const char * s)
{
    //dump dbg stringstream to file
    init::capture_dbg(dbg_fname);

    init::erros << setfill('-') << setw(80) << '-' << endl;
    init::erros << setfill('0');
    init::erros << "Parse Error: " << yyfname.back().c_str() << ", line "
                << dec << setw(4) << yyline << ": yychar = " 
                << dec << (uint32_t) yychar << " = 0x" << hex << (uint32_t) yychar << " = '";
    if(isprint(yychar)) init::erros << (char)yychar;
    else  init::erros << ' ';
    init::erros << "'  yylval = " << hex << "0x" <<  setw(16) << yylval.uint64 << endl;
    init::erros << "ERROR: " << s << endl;
    init::erros << setfill('-') << setw(80) << '-' << endl << endl;

    cout << init::erros.str() << endl;
}
