/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/ifcompiler/initRpn.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2010-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#if !defined(INITRPN_H)
#define INITRPN_H

// Change Log *************************************************************************************
//                                                                      
//  Flag  Reason   Userid   Date     Description                
//  ---- --------  -------- -------- -------------------------------------------------------------
//       D754106   dgilbert 06/14/10 Create
//                 dgilbert 10/15/10 Add support to filter unneeded inits by EC
//  dg002 SW039868 dgilbert 10/15/10 Add support to filter unneeded inits by EC
//  dg003 SW047506 dgilbert 12/09/10 SERIES filtering
//                 andrewg  09/19/11 Updates based on review
//                 camvanng 11/08/11 Added support for attribute enums
//                 andrewg  11/09/11 Multi-dimensional array and move to common fapi include
//                 camvanng 01/20/12 Support for using a range of indexes for array attributes
//                 camvanng 05/22/12 Ability to do simple operations on attributes
//                                   in the scom_data column
// End Change Log *********************************************************************************

/**
 * @file initRpn.H
 * @brief Declaration of the initRpn class. Handles Reverse Polish Notation equations for initfiles
 */

#include <stdint.h>
#include <string>
#include <vector>
#include <map>
#include <fapiHwpInitFileInclude.H>


namespace init
{
    class Symbols;

    typedef std::vector<uint8_t> BINSEQ;

    typedef std::pair<std::string,uint32_t> SYMBOL_VAL_PAIR;
    typedef std::vector<SYMBOL_VAL_PAIR> SYMBOL_VAL_LIST;

    class Rpn
    {
    public:

        enum TYPE
        {
            DEFINE       = 0x08000000,
            SYMBOL       = 0x10000000,
            NUMBER       = 0x20000000,
            ARRAY_INDEX  = 0x40000000,
            OPERATION    = 0x80000000,
            TYPE_MASK    = 0xF8000000,

        };

        /**
         * @brief Create empty RPN
         *
         */
        Rpn() : iv_symbols(NULL) {}

        /**
         * @brief Create empty RPN w/ symbol table
         *
         * @param[in] i_symbols   Pointer to Symbol Table
         */
        Rpn(Symbols * i_symbols) : iv_symbols(i_symbols) {}

        /**
         * @brief Create empty RPN w/ symbol table and input integer
         *
         * @param[in] i_int Integer to populate RPN with
         * @param[in] i_symbols   Pointer to Symbol Table
         */
        Rpn(uint32_t i_int, Symbols * i_symbols);

        Rpn(uint64_t i_int, Symbols * symbols);             //<<< Create RPN with single 64 bit integer
        Rpn(std::string  i_id, Symbols * symbols, TYPE i_type=SYMBOL);   //<<< Create RPN with single symbol
        Rpn(BINSEQ::const_iterator & bli, Symbols * symbols) //<<< Create RPN from binary sequence
          : iv_symbols(symbols) { bin_read(bli); }

        /**
         * Compare two Rpn sequences for equivalence
         * @note Currently the two Rpn sequences must use the same symbol table to be considered equal.
         * @note TODO: Allow different symbol tables and resolve the symbols before comparing.
         */
        bool operator==(const Rpn & r);
        bool operator!=(const Rpn & r) { return !(this->operator==(r)); }

        void push_int(uint32_t i_val);              //<<< Add a 32 bit integer to the Rpn sequence
        void push_id(std::string & i_id, TYPE i_type=SYMBOL); //<<Add a symbol or Spy enum to the Rpn sequence
        void push_int64(uint64_t i_uint);           //<<< Add a 64 bit integer to the Rpn sequence

        /**
         * @brief Add an attribute array index
         *
         * @param[in] i_array_idx Array index for this attribute
         *
         * @return Void
         */
        void push_array_index(std::string &i_array_idx);

        /**
         * @brief Add an attribute enum
         *
         * @param[in] i_attr_enum attribute enum name
         *
         * @return Void
         */
        void push_attr_enum(std::string &i_attr_enum);

        Rpn * push_op(IfRpnOp op);                   //<<< Add an operation to the Rpn sequence

        /**
         * @brief Merge an Rpn to this Rpn sequence with input operation
         *
         * @param[inout] io_rpn Input RPN to merge into this one.  Will be deleted.
         * @param[in] i_op Operation to perform between the 2 RPN's
         *
         * @return Merged RPN
         */
        Rpn * push_merge(Rpn * io_rpn, IfRpnOp i_op);

        /**
         * Merge (append) Rpn with this Rpn sequence
         * @returns this
         * @post i_rpn is deleted
         */
        Rpn * merge(Rpn * i_rpn);

        /**
         * Append a copy of an Rpn sequence to this Rpn sequence
         */
        void append(const Rpn & i_rpn);

        void append(uint32_t i_rpn_id) { iv_rpnstack.push_back(i_rpn_id); }

        /**
         * isTrue returns true if the RPN has a single element that is RPN_TRUE
         * @note Used in RPN optimization
         */
        bool isTrue() const;  //dg003a

        /**
         * isFalse returns true if the RPN has a single element that is RPN_FALSE
         * @note Used in RPN optimization
         */
        bool isFalse() const; //dg003a

        void clear() { iv_rpnstack.clear(); } //<<< clear the sequence

        /**
         * Human readable listing of RPN string
         * @param String Description to use;  NULL -> use default: "n BYTES"
         * @param bool i_final true: convert cini symbol id's to offset tags
         * @returns string
         * @NOTE i_final should never be set to true until all symbols in the
         * init file have been "looked up"
         */
        std::string listing(const char * i_desc,
                            const std::string & spyname = cv_empty_str,
                            bool i_final = false);

        std::string symbol_names() const;  //<<< Return a string of all the SYMBOL names in the Rpn

        /**
         * @brief Push all RPN stack entries of object as numerical values onto input blist
         *
         * @param blist Binary string of RPN to write to file
         * @param i_num_addrs number of Scom addresses for this Scom
         * @param i_addr_num the nth addr with the range of Scom addresses
         * @param i_prepend_count Flag to indicate prepend rpn count to binary string
         * @PRE should never be called until all symbols in the initfile have been
         * "looked up" or the binary tags for Symbols and Numbers may not be accurate
         * @return void
         */
        void bin_str(BINSEQ & blist, uint32_t i_num_addrs, uint32_t i_addr_num,
                     bool i_prepend_count = false);

        /**
         * Read binary sequence to recreate this Rpn sequence
         * @param binary sequence interator
         * @param number of bytes to read
         * @param symbol table to use
         * @post this rpn sequence is appended
         * @post if symbols != NULL then iv_symbols is replaced with symbols
         */
        void bin_read(BINSEQ::const_iterator & bli,
                      uint8_t i_size = 2,
                      Symbols * symbols = NULL); // read binary sequence to recreate RPN

        /**
         * Copy one rpn operation from bli and add to this Rpn sequence
         * @returns an iterator one past the last byte used.
         * @param iterator of a binary rpn sequence
         * @param symbol table to use.
         * @pre bli points to a valid rpn sequence - ie the correct number of PUSHES for the operand
         * @post this Rpn sequence is appended
         * @post Internal symbol table ptr is replace with given symbol table ptr if not NULL
         * @note Reads byte sequence from bli sequence until an operation is found.
         * @note The input sequence should NOT have a size byte on the front
         */
        BINSEQ::const_iterator bin_read_one_op(BINSEQ::const_iterator & bli, Symbols * symbols = NULL); // read one rpn operation from bli to create Rpn

        /**
         * Copy one numeric literal or attribute from io_bli and add to this Rpn sequence
         * @param[in,out] io_bli  iterator of a binary rpn sequence
         * @param[in] i_symbols table to use.
         * @pre io_bli points to a valid rpn sequence
         * @post this Rpn sequence is appended
         * @post Internal symbol table ptr is replaced with given symbol table ptr if not NULL
         * @post iterator of binary sequence is one past the last byte used.
         */
        void bin_read_one_id(BINSEQ::const_iterator & io_bli, Symbols * i_symbols = NULL);

        //dg002a
        /**
         * Resolve the RPN and returns false if the given EC level causes the RPN expression to be false.
         * @returns true | false
         * @note This routine will always return true unless the RPN contains an EC comparison that resolves to false.
         */
        bool resolve_ec(uint32_t i_ec);

        //dg003a
        /**
         * Resove as much of the RPN as possible, given the list of Symbol -> value substitutions. Result is true until proven false.
         * @returns true | false. False is returned if the Rpn is unconditionally false; otherwise true is returned.
         * @note Any Symbol found in the RPN not included in i_varlist resolves to ANY.  All comparison operands to ANY resolves to true
         * @code
         * // Example 1
         * SYMBOL_VAL_PAIR p(string("EC"),0x10);
         * SYMBOL_VAL_LIST lst;
         * lst.push_back(p);
         * if(anRpn.resolve(lst)) { .... }
         * // In this example, any instants of the variable "EC" in the RPN will be replaced with the value 0x10.
         * // Any other variables will be set to ANY and the RPN will be evaluated.
         * // if the RPN does not contain the variable "EC", it will resolve to true.
         *
         * // Example 2
         * SYMBOL_VAL_PAIR p1(string("SERIES"),0xA000006C);
         * SYMBOL_VAL_PAIR p2(string("SERIES_IP"),0xA000006C);
         * SYMBOL_VAL_PAIR p3(string("SERIES_Z"),0xA000006D);
         * SYMBOL_VAL_LIST lst;
         * lst.push_back(p1);
         * lst.push_back(p2);
         * lst.push_back(p3);
         * if(anRpn.resolve(lst)) {.....}  // resolves to false if rpn contains SERIES == SERIES_Z
         *                                 //  or SERIES != SERIES_IP
         * @endcode
         */
        bool resolve(SYMBOL_VAL_LIST & i_varlist);


        uint32_t op_count() const { return iv_rpnstack.size(); }

        // Helper functions in reading and writing binary sequences (compiled initfiles *.if)
        static uint8_t extract8(BINSEQ::const_iterator & bli);
        static uint16_t extract16(BINSEQ::const_iterator & bli);
        static uint32_t extract32(BINSEQ::const_iterator & bli);
        static uint64_t extract64(BINSEQ::const_iterator & bli);
        static void set8(BINSEQ & bl, uint8_t v);
        static void set16(BINSEQ & bl, uint16_t v);
        static void set32(BINSEQ & bl, uint32_t v);
        static void set64(BINSEQ & bl, uint64_t v);

        static std::string cv_empty_str;

      private: // types and data
        typedef std::vector<uint32_t> RPNSTACK;
        typedef std::vector<uint32_t> INDEXRANGE;

        RPNSTACK iv_rpnstack;       ///< Rpn sequence
        Symbols * iv_symbols;       ///< Symbol table to use
        INDEXRANGE iv_array_idx_range; ///< indicates range of indexes for an array attribute




        //dg002a begin  Used in resolve operations to interpret the Rpn sequence
        enum RPN_TYPE
        {
          RPN_NUMBER = 0,
          RPN_FALSE  = 1,
          RPN_TRUE   = 2,
          RPN_ANY    = 3,
        };

        // Used in resolve operations to interpret the Rpn sequence
        struct RPN_VALUE
        { 
          uint64_t data;
          RPN_TYPE type;
          RPN_VALUE() : data(0), type(RPN_NUMBER) {}
          RPN_VALUE(RPN_TYPE i_type) : data(0), type(i_type) {}
          RPN_VALUE(uint64_t i_data, RPN_TYPE i_type) : data(i_data), type(i_type) {}
          RPN_VALUE(uint64_t i_data) : data(i_data), type(RPN_NUMBER) {}
        };

        typedef std::vector<RPN_VALUE> EVAL_STACK;

      private: // functions

        // Used in resolve operations to interpret the Rpn sequence
        static void pop_bool(EVAL_STACK & i_stack, RPN_VALUE & o_value);
        static void pop_number(EVAL_STACK & i_stack, RPN_VALUE & o_value);
        // dg002a end
    };
};

#endif
