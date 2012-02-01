/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* fips740 src/engd/initfiles/ifcompiler/initCompiler.lex 1.2             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* OBJECT CODE ONLY SOURCE MATERIALS                                      */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010                   */
/* All Rights Reserved                                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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
#include <y.tab.h>

uint64_t bits2int( const char * bitString);
uint64_t hexs2int(const char * hexString, int32_t size);
void pushBackScomBody();
void push_col(const char *s);
void lex_err(const char *s );

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
std::string g_scomname;     // dg02

extern int yyline;

%}




NEWLINE  \n
FILENAME [A-Za-z][A-Za-z0-9_\.]*
ID      [A-Za-z][A-Za-z0-9_]*
ID2     [A-Za-z][A-Za-z0-9_]*(\[[0-9]+(..[0-9]+)?(,[0-9]+(..[0-9]+)?)*\]){0,4}
ID3      [0-9]+[A-Za-z_]+[0-9]*
DIGIT    [0-9]
COMMENT  #.*\n
OP      "="|"+"|"-"|"|"|"<"|">"|"*"|"/"|"%"
FLOAT   [0-9]+"."[0-9]*
BINARY  0[bB][0-1]+
SCOM_DATA [ ]*[scom_data][ ]+
HEX     0[xX][A-Fa-f0-9]+
SINGLE_HEX [A-Fa-f0-9]
ATTRIBUTE [\[[A-Fa-f0-9]\]]
MULTI_DIGIT [0-9]+

%x      scomop 
%x      scomop_array
%x      scomop_suffix
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


%%

{COMMENT}               ++yyline;    /* toss comments  - need first line */
\$Id:.*\n               ++yyline;    /* toss this - read by initCompiler.C */

 /* Special end-of-file character. */
<<EOF>>		        { return 0; }

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

define                  { return INIT_DEFINE;}


scom              { BEGIN(scomop); oss.str("");  return INIT_SCOM; }

<scomop>{HEX}       { 
	                  yylval.str_ptr = new std::string(yytext);
                        oss.str("");  
                        return INIT_SCOM_ADDR; 
                    }

<scomop>[\(]        {BEGIN(scomop_array); return yytext[0];}

<scomop_array>{SINGLE_HEX}+\.\.{SINGLE_HEX}+ {
	                         yylval.str_ptr = new std::string(yytext);
                               oss.str("");  
                               return INIT_INT64_STR; 
                           }

<scomop_array>{SINGLE_HEX}+ {
	                         yylval.str_ptr = new std::string(yytext);
                               oss.str("");  
                               return INIT_INT64_STR; 
                           }

<scomop_array>[\)] {BEGIN(scomop_suffix); return(yytext[0]);}

<scomop_suffix>{SINGLE_HEX}+ {
                                 yylval.str_ptr = new std::string(yytext);
                                 oss.str("");  
                                 BEGIN(scomop);
                                 return INIT_SCOM_SUFFIX; 
                             }

<scomop_suffix>[\(]      { BEGIN(scomop_array); return yytext[0]; }

<scomop>[:;\[]    { BEGIN(INITIAL); g_coltype = 0; return yytext[0]; }
<scomop>{NEWLINE} { BEGIN(INITIAL); ++yyline; }

<scomop,scomop_suffix>[\{]   {  
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
<scomcolname>{ID2}        {
                            g_colstream.push_back(new std::ostringstream());
                            *(g_colstream.back()) << yytext;
                         }
<scomcolname>,           {}
<scomcolname>;           { BEGIN(scomrow); g_scomcol = 0; }

<scomrow>{COMMENT}       ++yyline;
<scomrow>{NEWLINE}       ++yyline;
<scomrow>([^,;\n#\{\}]+{ID2}*)+ push_col(yytext);
<scomrow>[,]             ++g_scomcol;
<scomrow>[;]             g_scomcol = 0;
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

<*>SYS\.                yymore();

<*>ENUM_{ID}            { 
                            yylval.str_ptr = new std::string(yytext); return ATTRIBUTE_ENUM;
                        } 

<*>{ID}                 { 
                            yylval.str_ptr = new std::string(yytext); return INIT_ID; 
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

<*>\[({MULTI_DIGIT}[,.]*)+\]    { yylval.str_ptr = new std::string(yytext);  return ATTRIBUTE_INDEX; }

<*>[\[\]\{\},:]         {g_equation = false; return yytext[0]; }

<*>[ \t\r]+             /* Eat up whitespace */
[\n]                    { BEGIN(INITIAL);++yyline;}

<*>.                    lex_err(yytext);

%%

int yywrap() { return 1; }

void lex_err(const char *s )
{
    std::cerr << "\nERROR: " << s << " -line " << yyline << std::endl;
}

// Convert left justified bitstring to 64 bit integer
uint64_t bits2int( const char * bitString)
{
    uint32_t idx = 0;
    uint64_t mask = 0x8000000000000000ull;
    uint64_t val = 0;
    do
    {
      if( (bitString[0] != '0') ||
          ((bitString[1] != 'b') && (bitString[1] != 'B')))
      {
          lex_err("Invalid bit string");
          break;
      }
      idx = 2;

      while( bitString[idx] != 0 )
      {
          char c = bitString[idx];
          if( c == '1') val |= mask;
          else if(c != '0')
          {
              lex_err("Invalid bit string");
              break;
          }
          ++idx;
          mask >>= 1;
      }
      if(idx > 66) //dg01a  64bits + "0B" prefix
          lex_err("Bit string greater than 64 bits!");

     } while (0);
    return val;   
}

// Convert left justified hex string to 64 bit integer
uint64_t hexs2int(const char * hexString, int32_t size)
{
    uint64_t val = 0;
    std::string s(hexString);
    if(size > 18) //dg01a
    {
        lex_err("HEX literal greater than 64 bits");
        size = 18;
    }
    s.append(18-size,'0');  // 0x + 16 digits
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
    //dg02a begin
    while(g_scomcol >= g_colstream.size())  // more data cols than headers cols
    {
        // This will force an error in the parser where it can stop the compile.
        g_colstream.push_back(new std::ostringstream());
        *(g_colstream.back()) << "MISSING_COLUMN_HEADER";
        lex_err(g_scomname.c_str());
        lex_err("Invalid number of scom cols");
    }
    //dgxxa end
    //dgxxd remove if(g_colstream < g_colstream.size() 

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
