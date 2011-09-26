// IBM_PROLOG_BEGIN_TAG
// This is an automatically generated prolog.
//
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/ifcompiler/initSymbols.H,v $
//
// IBM CONFIDENTIAL
//
// COPYRIGHT International Business Machines Corp. 2010,2010
//
//UNDEFINED 
//
// Origin: UNDEFINED
//
// IBM_PROLOG_END_TAG
#if !defined(INITSYMBOLS_H)
#define INITSYMBOLS_H

// Change Log *************************************************************************************
//                                                                      
//  Flag Track    Userid   Date       Description                
//  ---- -------- -------- --------   -------------------------------------------------------------
//       D754106  dgilbert 06/14/10   Create
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

using namespace std;


namespace init
{
    typedef set<string> FILELIST;

    class Symbols
    {
        public:

            enum
            {
                LIT_TYPE        = 0x4000,
                VAR_TYPE        = 0x8000,
                NUM_TYPE        = 0xC000,
                TYPE_MASK       = 0xFFFFC000,
                CINI_LIT_MASK   = 0xA0000000,
                INIT_ANY_LIT    = 0x07FFFFFE,
                INIT_EXPR_VAR   = 0x07FFFFFF,
            };

            enum
            {
                SYM_ATTR_UINT8_TYPE = 0x00,
                SYM_ATTR_UINT32_TYPE,
                SYM_ATTR_UINT64_TYPE,
                SYM_ATTR_STRING_TYPE,
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
             * @param prn_id
             * @pre  all the symbols have been marked used (no new symbols)
             * @post tag table built if not already built.
             * @note  tag bits 0bttxxxxxx xxxxxxxx
             *               tt == 0b01 ->  enumerated literal
             *               tt == 0b10 ->  Variable name
             *               tt == 0b11 ->  Numeric constant
             *               xxxxxx xxxxxxxx assigned tag offset
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
             * Convert a numeric literal Rpn tag to an initfile tag
             * @param Rpn id returned by find_numeric_lit
             * @return tag
             * @pre Must not be called until find_numeric_lit() has been called for all numbers
             *      in the initfile.
             */
            uint16_t get_numeric_tag(uint32_t i_rpn_id);
            /**
             * Get the literal data value from the Rpn id returned by find_numeric_lit()
             * @param uint32_t Rpn id
             * @param uint32_t for returned byte size
             * @returns uint64_t data
             */
            uint64_t get_numeric_data(uint32_t i_rpn_id, uint32_t & o_size);


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

            void add_define(const string * name, const Rpn * rpn);
            Rpn get_define_rpn(uint32_t rpn_id);
            void clear_defines() { iv_defines.clear(); }


            string listing();              ///< listing of used vars & lits
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

        private:  // functions

            string find_text(uint32_t i_cini_id);
            uint32_t add_undefined(const string & s);
            uint32_t get_attr_type(const string &i_type);

        private: //data

            //   map | symbol name | (cini_id, usage flags) |
            typedef pair<uint32_t,uint32_t> MAP_DATA;
            typedef map<string,MAP_DATA > SYMBOL_MAP;
            typedef map<string,uint32_t> SPY_MAP;
            typedef map<string,uint32_t> SYMBOL_ATTR_TYPE;

            typedef pair<Rpn,uint32_t> DEF_DATA;
            typedef map<string,DEF_DATA> DEF_MAP;

            typedef pair<string,uint32_t>  RPN_DATA;
            typedef map<uint32_t,RPN_DATA> RPN_MAP;

            typedef vector<uint32_t>  SYMBOL_USED;

            typedef pair<uint64_t,uint32_t> LIT_DATA;
            typedef vector<LIT_DATA> LIT_LIST;

            SYMBOL_MAP  iv_symbols;     ///< From ciniIfSymbols.H all vars and enumerated lits
            SYMBOL_ATTR_TYPE iv_attr_type;
            SYMBOL_MAP  iv_not_found;   ///< List of symbols not found
            RPN_MAP     iv_rpn_map;     ///< Map rpn_id to symbol name/cini_id of used Symbols
            SYMBOL_USED iv_used_var;    ///< List of cini_ids of used vars ordered by name
            SYMBOL_USED iv_used_lit;    ///< List of cini_ids of used enum lits ordered by name

            LIT_LIST iv_lits;           ///< Numeric literals

            SPY_MAP iv_spymap;          ///< Spies & arrays & enum spies
            SPY_MAP iv_enums;           ///< Spy enums

            DEF_MAP iv_defines;         ///< defines

            uint32_t iv_used_var_count;
            uint32_t iv_used_lit_count;
            uint32_t iv_rpn_id;         ///< Current rpn offset assignment
    };
};


#endif
