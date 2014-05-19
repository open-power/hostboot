/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/ifcompiler/initSymbols.H $                       */
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
#if !defined(INITSYMBOLS_H)
#define INITSYMBOLS_H

// Change Log *************************************************************************************
//                                                                      
//  Flag Track     Userid   Date     Description                
//  ---- --------  -------- -------- -------------------------------------------------------------
//       D754106   dgilbert 06/14/10 Create
//                 andrewg  09/19/11 Updates based on review
//                 camvanng 11/08/11 Added support for attribute enums
//                 andrewg  11/09/11 Multi-dimensional array and move to common fapi include
//                 mjjones  11/17/11 Output attribute listing
//                 camvanng 11/17/11 Support for system & target attributes
//                 camvanng 01/07/12 Support for writing an attribute to a SCOM register
//                 camvanng 04/16/12 Support defines for SCOM address
//                                   Support defines for bits, scom_data and attribute columns
//                                   Delete obsolete code for defines support
//                 camvanng 05/07/12 Support for associated target attributes
//                 camvanng 06/27/12 Add get_numeric_array_data()
// End Change Log *********************************************************************************

/**
 * @file initSymbols.H
 * @brief Definition of the initSymbols class. Handles all symbols for initfiles
 */

// Definitions:
// cini_id is the 32 bit symbol tag value of a CINI initfile literal or variable as defined in ciniIfSymbols.H
// rpn_id  is an internal representation used by the Rpn class for all numbers, symbols, Spy enums, etc. that is not an operator
// bin_id  is the 16 bit tag used to represet number, symbols, enums, etc. in the compiled initfile.


#include <stdint.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <initRpn.H>
#include <fapiHwpInitFileInclude.H>  // Requires file from hwpf

using namespace std;


namespace init
{
    typedef set<string> FILELIST;
    const string ASSOC_TGT_ATTR = "TGT";

    class Symbols
    {
        public:

            enum
            {
                CINI_LIT_MASK   = 0xA0000000,
                INIT_ANY_LIT    = 0x07FFFFFE,
                INIT_EXPR_VAR   = 0x07FFFFFF,
            };



            enum 
            {
                NOT_FOUND       = 0x00000000,
                NOT_USED        = 0x00000000,
                CINI_ID_NOT_FOUND = 0x80000000,
            };

            /**
             * Build symbol map for list of files
             * @param List of files to open to build Symbols
             */
            Symbols(FILELIST & i_filenames);

            /**
             * Add a Symbol to the "used" symbol table if not already there
             * @param string Symbols name
             * @returns Symbols Rpn id
             * @post marks the id as 'USED'
             *
             */
            uint32_t use_symbol(string & i_symbol);

            /**
             * Lookup the tag id from the rpn_id provided by use_symbol()
             * @returns tag id
             * @param rpn_id
             * @pre  all the symbols have been marked used (no new symbols)
             * @post tag table built if not already built.
             * @note  tag bits 0btttxxxxx xxxxxxxx
             *               ttt == 0b010 ->  Numeric constant
             *               ttt == 0b100 ->  Target attribute
             *               ttt == 0b101 ->  System attribute
             *               ttt == 0b110 ->  Associated target attribute
             *               xxxxx xxxxxxxx assigned tag offset
             */
            uint16_t get_tag(uint32_t i_rpn_id);

            /**
             * Find the symbol name associated with an rpn_id
             * @param uint32_t rpn_id
             * @returns string Symbol name | "" if not found
             */
            string find_name(uint32_t i_rpn_id);

             /**
             * Find the tag for the numeric lit
             * @param data
             * @param number of significant bytes in the data [1-8]
             * @returns Rpn id
             */
            uint32_t find_numeric_lit(uint64_t i_data, int32_t byte_size);

             /**
             * Find the tag for the numeric array lit
             * @param data
             * @param number of significant bytes in the data [1-8]
             * @returns Rpn id
             */
            uint32_t find_numeric_array_lit(uint64_t i_data, int32_t byte_size);

            /**
             * Convert a numeric literal Rpn tag to an initfile tag
             * @param Rpn id returned by find_numeric_lit
             * @return tag
             * @pre Must not be called until find_numeric_lit() has been called for all numbers
             *      in the initfile.
             */
            uint16_t get_numeric_tag(uint32_t i_rpn_id);

            /**
             * Convert a numeric array literal Rpn tag to an initfile tag
             * @param Rpn id returned by find_numeric_lit
             * @return tag
             * @pre Must not be called until find_numeric_array_lit() has been called for all numbers
             *      in the initfile.
             */
            uint16_t get_numeric_array_tag(uint32_t i_rpn_id);

            /**
             * Get the literal data value from the Rpn id returned by find_numeric_lit()
             * @param uint32_t Rpn id
             * @param uint32_t for returned byte size
             * @returns uint64_t data
             */
            uint64_t get_numeric_data(uint32_t i_rpn_id, uint32_t & o_size);

            /**
             * Get the literal data value from the Rpn id returned by find_numeric_array_lit()
             * @param uint32_t Rpn id
             * @param uint32_t for returned byte size
             * @returns uint64_t data
             */
            uint64_t get_numeric_array_data(uint32_t i_rpn_id, uint32_t & o_size);

            /**
             * Get the attribute enum value for the attr enum
             * @param string attribute enum name
             * @returns uint64_t value
             */
            uint64_t get_attr_enum_val(string & i_attr_enum);


            /**
             * Store enum name & return rpn_id
             */
            uint32_t use_enum(const string & enumname);
            uint32_t get_spy_enum_id(uint32_t i_rpn_id, const string & spyname);
            string get_enum_name(uint32_t i_rpn_id);

            string get_enumname(uint32_t spy_id);
            string get_spyname(uint32_t spy_id);

            /**
             * Return spy id
             */
            uint32_t get_spy_id(const string & spyname);


            string listing();              ///< listing of used vars & lits
            string attr_listing();         ///< listing of used HWPF attributes
            uint32_t bin_vars(BINSEQ & blist);  ///< binary byte output of used vars. ret # vars
            uint32_t bin_lits(BINSEQ & blist);  ///< binary byte sequence of used lits ret # lits

            string full_listing();         ///< listing of all vars & lits (debug)
            string not_found_listing();    ///< listing of all vars searched for, but not found

            /**
             * Get the rpn_id from an initfile binary tag
             */
            uint32_t get_rpn_id(uint32_t bin_tag);


            /**
             * Restore used symbol lists from binary sequence
             * @returns number of symbols
             */
            uint32_t restore_var_bseq(BINSEQ::const_iterator & bli);
            uint32_t restore_lit_bseq(BINSEQ::const_iterator & bli);

            /**
             * Test that all spies in this object are a subset of the object provided
             * @param Symbols object to compare against
             * @return string will all error messages. Empty string indicates success.
             */
            string spies_are_in(Symbols & i_full_list, const set<string> & i_ignore_spies);

            static void translate_spyname(string & s)
            { 
                for(string::iterator i = s.begin(); i != s.end(); ++i)
                    if((*i) == '.' || (*i) == '#' ||
                       (*i) == '=' || (*i) == '&' ||
                       (*i) == '<' || (*i) == '>' ||
                       (*i) == '!' || (*i) == '*' ||
                       (*i) == '/' || (*i) == '%' ||
                       (*i) == '$')                      *i = '_';
                    else *i = toupper(*i);
            }

            /**
             * @brief Get the attribute type
             * @param[in] i_rpn_id RPN id of the attribute
             * @return uint32_t Attribute type
             */
            uint32_t get_attr_type(const uint32_t i_rpn_id);

        private:  // functions

            string find_text(uint32_t i_cini_id);
            uint32_t add_undefined(const string & s);
            uint32_t get_attr_type(const string &i_type, const uint32_t i_array);

        private: //data

            //   map | symbol name | (cini_id, usage flags) |
            typedef pair<uint32_t,uint32_t> MAP_DATA; //cini_id & corresponding rpn_id/NOT_USED
            typedef map<string,MAP_DATA > SYMBOL_MAP; //attr name & corresponding cini_id, rpn_id/NOT_USED pair
            typedef map<string,uint32_t> SPY_MAP;
            typedef map<string,uint32_t> SYMBOL_ATTR_TYPE; //attr name & corresponding type
            typedef map<string,uint64_t> SYMBOL_ATTR_ENUM; //enum name & corresponding value

            typedef pair<string,uint32_t>  RPN_DATA;  //attribute name & corresponding cini_id
            typedef map<uint32_t,RPN_DATA> RPN_MAP;   //rpn_id & corresponding attr name, cini_id pair

            typedef vector<RPN_DATA> VAR_SYMBOL_USED;
            typedef vector<uint32_t>  SYMBOL_USED;

            typedef pair<uint64_t,uint32_t> LIT_DATA; //numeric literal & corresponding size
            typedef vector<LIT_DATA> LIT_LIST; ///< List of numeric literals and their size

            SYMBOL_MAP  iv_symbols;     ///< From ciniIfSymbols.H all vars and enumerated lits
            SYMBOL_ATTR_TYPE iv_attr_type; ///< List of attributes and their type
            SYMBOL_ATTR_ENUM iv_attr_enum; ///< List of attribute enums and their value
            SYMBOL_MAP  iv_not_found;   ///< List of symbols not found
            RPN_MAP     iv_rpn_map;     ///< Map rpn_id to symbol name/cini_id of used Symbols
            VAR_SYMBOL_USED iv_used_var; ///< List of used attributes and their ids ordered by name
            SYMBOL_USED iv_used_lit;    ///< List of cini_ids of used enum lits ordered by name

            LIT_LIST iv_lits;           ///< Numeric literals

            SPY_MAP iv_spymap;          ///< Spies & arrays & enum spies
            SPY_MAP iv_enums;           ///< Spy enums

            uint32_t iv_used_var_count;
            uint32_t iv_used_lit_count;
            uint32_t iv_rpn_id;         ///< Current rpn offset assignment
    };
};


#endif
