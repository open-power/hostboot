/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/ifcompiler/initCompiler.lex $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
/* Change Log *************************************************************************************
//                                                                      
//  Flag Track    Userid   Date       Description                
//  ---- -------- -------- --------   -------------------------------------------------------------
//       D754106  dgilbert 06/14/10   Create
//  dg01 D766229  dgilbert 08/03/10   add check for hex/bin data > 64 bits
//  dg02 SW058986 dgilbert 02/28/11   More noticeable fail for missing col headers
//                andrewg  09/19/11   Updates based on review
//                camvanng 11/08/11   Added support for attribute enums
//                camvanng 11/16/11   Support system & target attributes
//                camvanng 12/12/11   Support multiple address ranges within a SCOM address
//                camvanng 01/20/12   Support for using a range of indexes for array attributes
//                camvanng 02/07/12   Ability to #include common scom initfile defines
//                camvanng 02/14/12   Support binary and hex scom addresses
//                                    Support for array at beginning of scom address
//                camvanng 04/12/12   Right justify SCOM data
//                                    Ability to specify search paths for include files
//                camvanng 04/16/12   Support defines for SCOM address
//                                    Support defines for bits, scom_data and attribute columns
//                camvanng 05/07/12   Support for associated target attributes
//                                    Save and restore line numbers for each include file
//                camvanng 05/22/12   Fix "OP" definition
//                camvanng 06/11/12   Fix shift/reduce warnings from yacc
//                camvanng 06/15/12   Ability to do bitwise OR and AND operations
//                camvanng 06/27/12   Improve error handling
//                camvanng 07/12/12   Support for "ANY"
// End Change Log *********************************************************************************/
/**
 * @file initCompiler.lex
 * @brief Contains the rules for the lex/flex  lexical scanner for scanning initfiles
 * 
 * This code runs as part of the build process to generate a
 * byte-coded representation of an initfile
 */
%{
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <initRpn.H>
#include <ifcompiler.y.tab.h>

uint64_t bits2int( const char * bitString);
uint64_t hexs2int(const char * hexString, int32_t size);
void pushBackScomBody();
void push_col(const char *s);
void lex_err(const char *s );
void add_define(const char *s);
void pushBackDefine(const char *s);

std::ostringstream oss;
std::ostringstream t_oss;

typedef std::vector<std::ostringstream *> OSS_LIST;
OSS_LIST g_colstream;

inline void clear_colstream() 
{ for( OSS_LIST::iterator i = g_colstream.begin(); i != g_colstream.end(); ++i) delete *i;
  g_colstream.clear();
}
uint32_t g_scomcol;
uint32_t g_coltype = 0;
uint32_t g_scomtype = 0;
uint32_t g_paren_level = 0;
bool g_equation = false;   // equation inside scomv col
std::string g_scomdef_name;
std::map<std::string,std::string> g_defines; //container for all the defines
    //i.e. define def_A = (attrA > 1) => key = "DEF_A", value = "(attr_A > 1)"

std::string g_target;  //storage for current target

extern int yyline;
extern std::vector<std::string> yyincludepath;
extern std::map<std::string,std::string> yytarget; //container for all defined targets
    //i.e. define MBA0 = TGT1 => key = "TGT1", value = "MBA0"

#define MAX_INCLUDE_DEPTH 10
YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH];
int yyline_stack[MAX_INCLUDE_DEPTH];
int include_stack_num = 0;

extern std::vector<std::string> yyfname;

%}




NEWLINE  \n
FILENAME [A-Za-z][A-Za-z0-9_\.]*
ID      [A-Za-z][A-Za-z0-9_]*
ID2     [A-Za-z][A-Za-z0-9_]*(\[[0-9]+(\.\.[0-9]+)?(,[0-9]+(\.\.[0-9]+)?)*\]){0,4}
ID3      [0-9]+[A-Za-z_]+[0-9]*
DIGIT    [0-9]
COMMENT  #.*\n
OP      "="|"+"|"-"|"!"|"<"|">"|"*"|"/"|"%"|"&"|"|"
FLOAT   [0-9]+"."[0-9]*
BINARY  0[bB][0-1]+
SINGLE_BIN [0-1]
SCOM_DATA [ ]*[scom_data][ ]+
HEX     0[xX][A-Fa-f0-9]+
SINGLE_HEX [A-Fa-f0-9]
ATTRIBUTE [\[[A-Fa-f0-9]\]]
MULTI_DIGIT [0-9]+
MULTI_INDEX_RANGE [0-9]+(\.\.[0-9]+)?(,[0-9]+(\.\.[0-9]+)?)*

%x      scomop 
%x      scomop_hex 
%x      scomop_hex_array
%x      scomop_hex_suffix
%x      scomop_bin
%x      scomop_bin_array
%x      scomop_bin_suffix
%x      scomdata
%x      when_kw
%x      when_expr
%x      scomcolname
%x      scomrow
%x      list
%x      enumcol
%x      fnames
%x      target
%x      attribute
%x      array
%x      incl
%x      scomdef
%x      scomdef_value


%%

{COMMENT}               ++yyline;    /* toss comments  - need first line */
\$Id:.*\n               ++yyline;    /* toss this - read by initCompiler.C */

 /* Special end-of-file character. */
<<EOF>>		        {
                        if (--include_stack_num < 0)
                        {
                            g_defines.clear();
                            return 0;
                        }
                        else
                        {
                            yy_delete_buffer(YY_CURRENT_BUFFER);
                            fclose(yyin);
                            yy_switch_to_buffer(include_stack[include_stack_num]);
                            yyline = yyline_stack[include_stack_num];
                            yyfname.pop_back();
                        }
                    }

SyntaxVersion           return INIT_VERSION;

 /* The list of initfile versions is just copied into the *.if file
  * so just make it one chunk of string data */
Versions                BEGIN(fnames);
<fnames>[=]             oss.str("");
<fnames>{FLOAT}         oss << yytext;
<fnames>[:]             oss << yytext;
<fnames>[,]             oss << ", ";
<fnames>{FILENAME}      oss << yytext;
<fnames>{NEWLINE}       {   ++yyline;
                            yylval.str_ptr = new std::string(oss.str());
                            BEGIN(INITIAL);
                            return INIT_VERSIONS;
                        }

include                 { BEGIN(incl); }
<incl>[ \t]*            /* Eat up whitespace */
<incl>[^ \t\n]+         {   /* Got the include file name */
                            /*printf("lex: include file %s\n", yytext);*/
                            if ( include_stack_num >= MAX_INCLUDE_DEPTH )
                            {
                                lex_err("Include nested too deeply");
                                lex_err(yytext);
                                exit( 1 );
                            }

                            /* Save current line number */
                            yyline_stack[include_stack_num] =
                                yyline;

                            /* Save current input buffer */
                            include_stack[include_stack_num++] =
                                YY_CURRENT_BUFFER;

                            /* Switch input buffer */
                            std::string filename = yytext;
                            yyin = fopen( filename.c_str(), "r" );
                            for (size_t i = 0; (i < yyincludepath.size()) && (NULL == yyin); i++)
                            {
                                filename = yyincludepath.at(i) + "/" + yytext;
                                yyin = fopen( filename.c_str(), "r" );
                            }
                            if (NULL == yyin)
                            {
                                oss.str("");
                                oss << "Cannot open include file: " << yytext;
                                lex_err(oss.str().c_str());
                                exit(1);
                            }
                            printf("Include file %s\n", filename.c_str());
                            yyline = 1;  //set line number for new buffer
                            yyfname.push_back(filename); //save file name of new file being parsed
                            yy_switch_to_buffer(yy_create_buffer(yyin, YY_BUF_SIZE));

                            BEGIN(INITIAL);
                        }

                         /* Adding the ability to use defines for SCOM address and the different
                          * columns (bits, scom_data and attribute columns).
                          * Since the SCOM address and the different columns all have different
                          * parsing rules, it is complicated to handle this in both the scanner and parser.
                          * The simplest thing to do is to keep track of all the defines in the scanner
                          * then push the specific define value back into the input stream for scanning
                          * when it is used.
                          */

define                       { BEGIN(scomdef); }

<scomdef>{ID}                { g_scomdef_name = yytext; }
<scomdef>[ \t\r]*=[ \t\r]*   { BEGIN(scomdef_value); }
<scomdef_value>[^;\n#\{\}]+  { add_define(yytext); }
<scomdef_value>;             { g_scomdef_name = ""; BEGIN(INITIAL); }

scom              { BEGIN(scomop); oss.str("");  return INIT_SCOM; }

<scomop>{HEX} { /*printf("lex: hex string %s\n", yytext);*/
                yylval.str_ptr = new std::string(yytext);
                BEGIN(scomop_hex);
                return INIT_SCOM_ADDR; 
              }

<scomop>0[xX] { BEGIN(scomop_hex); }
<scomop>0[bB] { BEGIN(scomop_bin); }

<scomop_hex,scomop_hex_suffix>[\(] {
                    /*printf("lex: hex string %s\n", yytext);*/
                    BEGIN(scomop_hex_array);
                }

<scomop_hex_array>{SINGLE_HEX}+\.\.{SINGLE_HEX}+ {
                    /*printf("lex: hex string %s\n", yytext);*/
                    yylval.str_ptr = new std::string(yytext);
                    return INIT_INT64_STR; 
                }

<scomop_hex_array>{SINGLE_HEX}+ {
                    /*printf("lex: hex string %s\n", yytext);*/
                    yylval.str_ptr = new std::string(yytext);
                    return INIT_INT64_STR; 
                }

<scomop_hex_array>[\)] {
                    /*printf("lex: hex string %s\n", yytext);*/
                    BEGIN(scomop_hex_suffix);
                }

<scomop_hex,scomop_hex_suffix>{SINGLE_HEX}+ {
                    /*printf("lex: hex string %s\n", yytext);*/
                    yylval.str_ptr = new std::string(yytext);
                    return INIT_SCOM_SUFFIX; 
                }

<scomop_hex,scomop_hex_suffix>\.0[bB] { BEGIN(scomop_bin); return yytext[0]; }

<scomop_bin>{SINGLE_BIN}+ {
                    /*printf("lex: bin string %s\n", yytext);*/
                    yylval.str_ptr = new std::string(yytext);
                    return INIT_SCOM_ADDR_BIN;
                }

<scomop_bin,scomop_bin_suffix>[\(] {
                    /*printf("lex: bin string %s\n", yytext);*/
                    BEGIN(scomop_bin_array);
                }
<scomop_bin_array>{SINGLE_BIN}+\.\.{SINGLE_BIN}+ {
                    /*printf("lex: bin string %s\n", yytext);*/
                    yylval.str_ptr = new std::string(yytext);
                    return INIT_BINARY_STR;
                }

<scomop_bin_array>{SINGLE_BIN}+ {
                    /*printf("lex: bin string %s\n", yytext);*/
                    yylval.str_ptr = new std::string(yytext);
                    return INIT_BINARY_STR;
                }

<scomop_bin_array>[\)] {
                    /*printf("lex: bin string %s\n", yytext);*/
                    BEGIN(scomop_bin_suffix);
                }

<scomop_bin_suffix>{SINGLE_BIN}+ {
                    /*printf("lex: bin string %s\n", yytext);*/
                    yylval.str_ptr = new std::string(yytext);
                    return INIT_SCOM_SUFFIX_BIN;
                }

<scomop_bin,scomop_bin_suffix>\.(0[xX])? {
                    /*printf("lex: bin string %s\n", yytext);*/
                    BEGIN(scomop_hex); return yytext[0];
                }

<scomop_bin,scomop_bin_suffix>\.0[bB] {
                    /*printf("lex: bin string %s\n", yytext);*/
                }

<scomop_hex_array,scomop_bin_array>{ID}\.\.{ID} { pushBackDefine(yytext); }
<scomop_hex,scomop_hex_suffix,scomop_bin,scomop_bin_suffix>\.{ID} { pushBackDefine(yytext + 1); unput('.'); }
<scomop,scomop_hex_array,scomop_hex_suffix,scomop_bin_array,scomop_bin_suffix>{ID}  { pushBackDefine(yytext); }

<scomop>[:;\[]    { BEGIN(INITIAL); g_coltype = 0; return yytext[0]; }
<scomop>{NEWLINE} { BEGIN(INITIAL); ++yyline; }

<scomop_hex,scomop_hex_suffix,scomop_bin,scomop_bin_suffix>[\{]   {  
                                 oss.str("");
                                 BEGIN(scomcolname);
                                 return yytext[0];
                             }




                         /* The column & row format is really hard to handle in the parser,
                          * especially since each column can have different parsing rules.
                          * So fix it here in the scanner by converting the format to
                          * coltitle1 , row1, row2, ..., row n ;
                          * coltitle2 , row1, row2, ..., row n ;
                          * then push it all back into the input stream and scan the new format
                          */	

<scomcolname>{COMMENT}   ++yyline;
<scomcolname>\n          ++yyline;
<scomcolname>{ID}        {  // Only non-array attributes are supported for attribute column
                            g_colstream.push_back(new std::ostringstream());
                            *(g_colstream.back()) << yytext;
                         }
<scomcolname>,           {}
<scomcolname>;           { BEGIN(scomrow); g_scomcol = 0; }

<scomrow>{COMMENT}       ++yyline;
<scomrow>{NEWLINE}       ++yyline;
<scomrow>([^,;\n#\{\}]+{ID2}*)+ push_col(yytext);
<scomrow>[,]             ++g_scomcol;
<scomrow>[;]             { 
                             if ((g_scomcol + 1) < g_colstream.size())
                             {
                                 lex_err("# Scom columns < # of column headers");
                                 exit(1);
                             }
                             g_scomcol = 0;
                         }
<scomrow>[\}]            {
                            pushBackScomBody();  // create new format and put it back on yyin
                            BEGIN(INITIAL);
                         }


                        /* The scombody is the modified format - don't track yyline as it's already
                         * accounted for. Any errors in here will point back to the last line in the
                         * 'real' scombody 
                         */
              
bits                    { g_coltype = INIT_BITS;  return INIT_BITS;}
expr                    { g_coltype = INIT_EXPR;  return INIT_EXPR;}
scom_data               { g_coltype = INIT_SCOMD; return INIT_SCOMD;}

                        /*HEX and Binary numbers in the scombody can be up to 64bit, 
                        * decimal numbers will always fit in 32bit int */

{BINARY}                { yylval.uint64 = bits2int(yytext); return INIT_INT64; }

<*>;                    { g_coltype = 0; return ';'; }
                            
END_INITFILE            return INIT_ENDINITFILE;

<*>SYS\.                yymore(); //System attribute

<*>TGT{MULTI_DIGIT}\.   {
                            if (g_target.length())
                            {
                                std::string tgt(yytext);
                                tgt = tgt.substr(0, tgt.length() -1);
                                yytarget[tgt] = g_target;
                                g_target.clear();
                            }

                            yymore(); //Associated target attribute
                        }

                        /* All attribute enums start with "ENUM_ATTR_" */
<*>ENUM_ATTR_{ID}       {
                            yylval.str_ptr = new std::string(yytext); return ATTRIBUTE_ENUM;
                        } 

                        /* All attributes start with "ATTR_"; then there's "any". */
<*>ATTR_{ID}|"any"|"ANY" {
                            yylval.str_ptr = new std::string(yytext); return INIT_ID; 
                        }

                        /* Anything else is a define.
                         * Removing any requirements that defines has to start with "def_" or "DEF_" */
<*>{ID}\.               {   // push back the define value for scanning
                            g_target = yytext;
                            g_target = g_target.substr(0, g_target.length() - 1);
                            //printf("lex: %s\n", g_target.c_str());
                            unput('.');
                            pushBackDefine(g_target.c_str());
                        }

<*>{ID}                 {   // push back the define value for scanning
                            pushBackDefine(yytext);
                        } 

<*>{DIGIT}+             {
                          sscanf(yytext, "%d", &yylval.integer); return INIT_INTEGER;
                        }

<*>{HEX}                {
                            // normal right-justified 64 bit hex integer
                            yylval.uint64 = hexs2int(yytext,yyleng);
                            return INIT_INT64;
                        }

<*>"&&"                 return INIT_LOGIC_AND;
<*>"||"                 return INIT_LOGIC_OR;
<*>"=="                 return INIT_EQ;
<*>"!="                 return INIT_NE;
<*>"<="                 return INIT_LE;
<*>">="                 return INIT_GE;
<*>">>"                 return INIT_SHIFT_RIGHT;
<*>"<<"                 return INIT_SHIFT_LEFT;

<*>{OP}                 { g_equation = true; return yytext[0]; }
<*>[\(]                 { ++g_paren_level; return yytext[0]; }
<*>[\)]                 { --g_paren_level; return yytext[0]; }

<*>\[{MULTI_INDEX_RANGE}\]    { yylval.str_ptr = new std::string(yytext);  return ATTRIBUTE_INDEX; }

<*>[\{\},:]             {g_equation = false; return yytext[0]; }

<*>[ \t\r]+             /* Eat up whitespace */
[\n]                    { BEGIN(INITIAL);++yyline;}

<*>.                    {
                            oss.str("");
                            oss << yytext << " is not valid syntax";
                            lex_err(oss.str().c_str());
                            exit(1);
                        }

%%

int yywrap() { return 1; }

void lex_err(const char *s )
{
    std::cerr << "\nERROR: lex: " << yyfname.back().c_str()
              << ", line " << yyline << ": " << s << std::endl << std::endl;
}

// Convert left justified bitstring to right-justified 64 bit integer
uint64_t bits2int( const char * bitString)
{
    uint32_t idx = 0;
    uint64_t mask = 0x0000000000000001ull;
    uint64_t val = 0;

    if( (bitString[0] != '0') ||
        ((bitString[1] != 'b') && (bitString[1] != 'B')))
    {
        lex_err("Invalid bit string");
        lex_err(bitString);
        exit(1);
    }
    idx = 2;

    while( bitString[idx] != 0 )
    {
        val <<= 1;
        char c = bitString[idx];
        if( c == '1') val |= mask;
        else if(c != '0')
        {
            lex_err("Invalid bit string");
            lex_err(bitString);
            exit(1);
        }
        ++idx;
    }
    if(idx > 66) //dg01a  64bits + "0B" prefix
    {
        lex_err("Bit string greater than 64 bits!");
        lex_err(bitString);
        exit(1);
    }

    return val;   
}

// Convert left justified hex string to 64 right-justified bit integer
uint64_t hexs2int(const char * hexString, int32_t size)
{
    uint64_t val = 0;
    std::string s(hexString);
    if(size > 18) //dg01a
    {
        lex_err("HEX literal greater than 64 bits");
        lex_err(hexString);
        exit(1);
    }
    s.insert(2, 18-size,'0');  // 0x + 16 digits
    val = strtoull(s.c_str(),NULL,16);
    return val;
}

void pushBackScomBody()
{
    std::ostringstream ost;
    for(OSS_LIST::iterator i = g_colstream.begin(); i != g_colstream.end(); ++i)
    {
        ost << (*i)->str() << ';';
    }
    ost << '}';
    std::string t = ost.str();  // Was causing weird stuff if I didn't copy the string out first
    //std::cout << "<lex comment> Pushing:" << t << std::endl;
    //std::cout << "<lex comment> " << std::endl;

    for(std::string::reverse_iterator r = t.rbegin();
        r != t.rend();
        ++r)
    {
       //std::cout << *r;
        unput(*r);
    }
    //std::cout << std::endl;
    clear_colstream();
}


/// help collect column data
void push_col(const char * s)
{
    if(g_scomcol >= g_colstream.size())  // more data cols than headers cols
    {
        lex_err("Missing column header");
        exit(1);
    }

    std::ostringstream & o = *(g_colstream[g_scomcol]);
    std::ostringstream token;
    std::istringstream iss(s);
    std::string t;
    //std::cout << "Pushing ";
    while(iss >> t) token << t; // get rid of white space
    if(token.str().size()) // don't add blank tokens
    {
        //std::cout << "Pushing ," << token.str() << std::endl;
        o << ',' << token.str();
    }
}


/// Save the define
void add_define(const char * s)
{
    if (g_defines.end() != g_defines.find(g_scomdef_name))
    {
        oss.str("");
        oss << g_scomdef_name << " already defined";
        lex_err(oss.str().c_str());
        exit(1);
    }

    //remove trailing white spaces
    std::string str(s);
    std::string whitespaces(" \t\r");
    size_t pos;
    pos=str.find_last_not_of(whitespaces);
    if (pos != std::string::npos)
    {
        str.erase(pos+1);
    }

    g_defines[g_scomdef_name] =  str;
    //std::cout << "g_defines[" << g_scomdef_name << "] = " << g_defines[g_scomdef_name] << std::endl;
}

// Push the define(s) back into the input stream for scanning
void pushBackDefine(const char *s)
{
    std::string key(s); //set key to input string
    std::string key2;
    std::string value;

    //std::cout << "lex: pushBackDefine input string: " << s << " key: " << key << std::endl;

    //Is this a range?
    size_t pos = key.find("..");
    if (pos != std::string::npos)
    {
        key2 = key.substr(pos+2); //2nd key in the range
        key = key.substr(0,pos);  //Reset 1st key in the range
    }

    //Exit if cannot find 1st key
    if (g_defines.end() == g_defines.find(key))
    {
        oss.str("");
        oss << "Cannot find define " << key;
        lex_err(oss.str().c_str());
        exit(1);
    }

    // Set value string
    value = g_defines[key];
    if (key2.size())
    {
        //Exit if cannot find 2nd key
        if (g_defines.end() == g_defines.find(key2))
        {
            oss.str("");
            oss << "Cannot find define " << key;
            lex_err(oss.str().c_str());
            exit(1);
        }

        //Get rid of spaces & append key2 value
        size_t pos = value.find(' ');
        if (pos != std::string::npos)
        {
            value = value.substr(0,pos);
        }
        value += ".." + g_defines[key2];
    }

    //std::cout << "lex: pushBackDefine: " << value << std::endl;

    //Push back the value into the input stream
    for(std::string::reverse_iterator r = value.rbegin();
        r != value.rend();
        ++r)
    {
        //std::cout << *r;
        unput(*r);
    }
    //std::cout << std::endl;
}
