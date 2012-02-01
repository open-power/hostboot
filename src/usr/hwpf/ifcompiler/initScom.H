// IBM_PROLOG_BEGIN_TAG
// This is an automatically generated prolog.
//
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/ifcompiler/initScom.H,v $
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
#if !defined(INITSPY_H)
#define INITSPY_H

// Change Log *************************************************************************************
//
//  Flag Track     Userid   Date     Description
//  ----- -------- -------- -------- -------------------------------------------------------------
//         D754106 dgilbert 06/14/10 Create
//  dg002 SW039868 dgilbert 10/15/10 Add support to filter unneeded inits by EC
//  dg003 SW047506 dgilbert 12/09/10 More filtering enhancements
//                 andrewg  05/24/11 Port over for VPL/PgP
//                 andrewg  09/19/11 Updates based on review
//                 mjjones  11/17/11 Output attribute listing
//                 camvanng 12/12/11 Support multiple address ranges within a SCOM address
//                                   Use strtoull vs strtoul for 32-bit platforms
//                 camvanng 12/15/11 Support for multiple duplicate addresses setting different bits
//                 camvanng 01/20/12 Support for using a range of indexes for array attributes
// End Change Log *********************************************************************************

/**
 * @file initSpy.H
 * @brief Declairation of the initSpy Class. Represents the information parsed from an initfile spy
 *        statement.
 */

#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <initRpn.H>
#include <initSymbols.H>


using namespace std;

namespace init
{
    typedef vector<string> SCOM_ADDR;
    typedef vector<Rpn> RPN_LIST;
    typedef vector<RPN_LIST> COL_LIST;
    typedef vector<uint32_t> VAR_LIST;
    typedef pair<uint32_t,uint32_t> RANGE;
    typedef vector<RANGE> RANGE_LIST;

    enum SCOM_WHEN
    {
        NONE                = 0x00000000,

        // WHEN= types
        LONG_SCAN           = 0x00000001,
        SCOM                = 0x00000002,
        DRAMINIT            = 0x00000003,
        CFAMINIT            = 0x00000004,
        LAST_WHEN_TYPE      = CFAMINIT,
        WHEN_MASK           = 0x000000FF,

        // WHEN= sub types
        SUBTYPE_MASK        = 0x0000F000,
        HOT_ADD_NODE        = 0x00004000,
        AFTER_HOT_ADD_NODE  = 0x00006000,
        HOT_ADD_GX          = 0x00008000,
        HOT_ADD_GX0         = 0x00007000,
        HOT_ADD_GX1         = 0x00005000,
        AFTER_HOT_ADD_GX    = 0x0000A000,
        AFTER_HOT_ADD_GX0   = 0x00003000,
        AFTER_HOT_ADD_GX1   = 0x00002000,
    };

    const char when_char[] = { '@','L','S','D','C' };

    class Scom
    {
        public:

            enum SPY_TYPE
            {
                NOTYPE,
                ISPY,
                ESPY,
                ARRAY
            };


            Scom(Symbols * i_symbols,uint32_t i_line = 0) :
                iv_symbols(i_symbols),
                iv_line(i_line),
                iv_scom_length(0),
                iv_scom_offset(0),
                iv_when(NONE)        {}

            // Build from binary sequence
            Scom(BINSEQ::const_iterator & bli, Symbols * i_symbols);

            bool compare(Scom & that);
            uint32_t get_when(void)              { return(iv_when); }
            void set_when(SCOM_WHEN i_when)              { iv_when |= (uint32_t)i_when; }
            void set_when(const string * when_str);
            bool do_when(SCOM_WHEN i_when)      { return ((uint32_t)i_when == (WHEN_MASK & iv_when)); }
            void set_sub_when(SCOM_WHEN i_when)          { iv_when |= i_when; }
            void set_when_rpn(const Rpn * i_rpn)        { iv_when_rpn = *i_rpn; delete i_rpn; }
            uint32_t get_line() { return iv_line; }
            void add_scom_rpn(const Rpn * i_rpn)        { iv_scom_rpn.push_back(*i_rpn); delete i_rpn; }



            /**
             * Is when statement valid for this spy
             * @param stats: ostream to print debug information
             * @param ec restriction - true if valid for this ec, 0xffffffff means ANY ec
             * @return false if Rpn for when statement resolves to false, otherwise true
             */
            bool valid_when(ostream & stats, uint32_t i_ec = 0xffffffff);

            void add_col(const string & i_colname);

            /**
             * Add a row rpn to the current column
             * @param pointer to Rpn object
             * @pre add_col()
             */
            void add_row_rpn(Rpn * i_rpn);

            void add_bit_range(uint32_t start, uint32_t end);
            void add_target_range(uint32_t r1, uint32_t r2);
            void make_target(const char * i_symbol);


            uint64_t get_address(void) {return(strtoull(iv_scom_addr[0].c_str(),NULL,16));}

            /**
             * @brief Get the SCOM address
             * @return iv_scom_addr_hex  the SCOM address
             */
            uint64_t get_address_hex(void) {return iv_scom_addr_hex;}

            /**
             * @brief Get the bit offset to start writing the SCOM data
             * @return iv_scom_offset  the starting bit within the SCOM to write the data
             */
            uint32_t get_scom_offset(void) {return iv_scom_offset;}

            /**
             * @brief Get the total number of bits to write
             * @return iv_scom_length  the number of bits to write
             */
            uint32_t get_scom_length(void) {return iv_scom_length;}

            // string name();
            string listing();

            /**
             * Append binary listing of this Spy
             * @param when [init::LONG_SCAN | init::SCOM]
             * @param BINSEQ binary listing to append
             * @returns uint32_t number of spies added
             */
            uint32_t bin_listing(BINSEQ & blist);

            void set_scom_address(const string & i_scom_addr);
            void dup_scom_address(const string & i_scom_addr);
            void copy_dup_scom_address();
            void set_scom_suffix(const string & i_scom_addr);

        private:  // functions

            string list_one(RANGE range);
            void bin_list_one(BINSEQ & blist,uint64_t i_addr, uint32_t i_addr_num, RANGE range);

            /**
             * Optimize the row RPNs
             * @note Remove any rows that resolve to unconditionally false.
             */
            void row_optimize();

        private:  // data

          typedef map<string,SCOM_WHEN> WHEN_SUBTYPE_MAP;

            SCOM_ADDR   iv_scom_addr;
            SCOM_ADDR   iv_dup_scom_addr;      ///< contains the duplicate scom addresses
            uint64_t    iv_scom_addr_hex;
            uint32_t    iv_scom_length;
            uint32_t    iv_scom_offset;
            RPN_LIST    iv_scom_rpn;            ///< spyv - for each row
            RPN_LIST    iv_col_vars;            ///< RPNs of column name for each column
            COL_LIST    iv_cols_rpn;            ///< A list of row rpn segments one rpn list for each column
            RPN_LIST    iv_row_rpn;             ///< row rpns for current column being parsed.
            RANGE_LIST  iv_range_list;          ///< bit range list
            RANGE_LIST  iv_target_ranges;       ///< target range for current target begin parsed.
            Symbols   * iv_symbols;
            uint32_t    iv_line;                ///< line # in the initfile
            uint32_t    iv_when;
            Rpn         iv_when_rpn;


            static WHEN_SUBTYPE_MAP  cv_when_subtypes;

    };


    //=================================================================================================
    //  SpyList Class declarations
    //=================================================================================================
    // Container to track scoms
    typedef multimap<uint64_t, init::Scom *> SCOM_LIST;

    class ScomList
    {
        public:
            ScomList(const string & initfile, FILELIST & defines, ostream & stats, uint32_t i_ec = 0xFFFFFFFF);
            ~ScomList();
            //size_t size() { return iv_spy_list.size(); }
            //SPY_LIST::iterator begin() { return iv_spy_list.begin(); }
            //SPY_LIST::iterator end() { return iv_spy_list.end(); }
            void clear();
            void insert(Scom * i_scom);

            void compile(BINSEQ & bin_seq);

            void listing(BINSEQ & bin_seq, ostream & out);
            void attr_listing(BINSEQ & bin_seq, ostream & out);

            /**
             * Compare two spylists for equivalance
             * @returns true if equal
             * @note Both spylists should have been built from a binary sequence
             *    not directly from an initfile
             */
            bool compare(ScomList & that);



            void set_cvs_versions(const string * s) { iv_cvs_versions = *s; }
            void set_syntax_version(uint32_t v);
            size_t get_syntax_version() { return iv_syntax_version; }
            void clear_defines() { iv_symbols->clear_defines(); }
            void add_define(const string * name, const Rpn * rpn)
                    { iv_symbols->add_define(name,rpn); }

            Symbols * get_symbols() { return iv_symbols; }

        private: // functions

            string fmt8(uint32_t val);

        private:

              SCOM_LIST iv_scom_list;
              string iv_cvs_versions;
              uint32_t iv_syntax_version;
              Symbols * iv_symbols;
              ostream & iv_stats;
              uint32_t iv_ec;
    };
};
#endif
