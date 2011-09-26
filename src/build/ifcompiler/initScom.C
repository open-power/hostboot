// IBM_PROLOG_BEGIN_TAG
// This is an automatically generated prolog.
//
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/ifcompiler/initScom.C,v $
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

// Change Log *************************************************************************************
//                                                                      
//  Flag  Track    Userid   Date     Description                
//  ----- -------- -------- -------- -------------------------------------------------------------
//         D754106 dgilbert 06/14/10 Create
//  dg001  D774126 dgilbert 09/30/10 Check that colname EXPR is last column in spytable
//  dg002 SW039868 dgilbert 10/15/10 Add support to filter unneeded inits by EC
//  dg003 SW047506 dgilbert 12/09/10 More filtering enhancements
//                 andrewg  05/24/11 Port over for VPL/PgP
// End Change Log *********************************************************************************

/**
 * @file initSpy.C
 * @brief Definition of the initScom Class. Represents the information parsed from an initfile scom
 *        statement.
 */

#include <initScom.H>
#include <initSymbols.H>
#include <initCompiler.H>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <set>
#include <stdexcept>

extern void yyerror(const char * s);
extern init::ScomList * yyscomlist;  // only use this during parsing

namespace init {
extern ostringstream dbg;  // debug output
};

using namespace init;

Scom::WHEN_SUBTYPE_MAP Scom::cv_when_subtypes;

//-------------------------------------------------------------------------------------------------

Scom::Scom(BINSEQ::const_iterator & bli, Symbols * i_symbols):
             iv_symbols(i_symbols),
             iv_when(NONE),
             iv_scom_length(0),
             iv_scom_offset(0),
             iv_when_rpn(i_symbols)
             
{

    iv_scom_length   = Rpn::extract16(bli);
    iv_scom_offset   = Rpn::extract16(bli);
    uint32_t id      = Rpn::extract16(bli);
    uint32_t numcols = Rpn::extract16(bli);
    uint32_t numrows = Rpn::extract16(bli);
    //uint32_t hier    = *bli++;
    ++bli;      // don't need hier

    //iv_when |= numcols & SUBTYPE_MASK;
    numcols &= ~SUBTYPE_MASK;

    // Get our SCOM address
    uint32_t l_addr_size = 0;
    //iv_scom_addr[0] = iv_symbols->get_numeric_data(iv_symbols->get_rpn_id(id),l_addr_size);
    iv_scom_addr_hex = iv_symbols->get_numeric_data(iv_symbols->get_rpn_id(id),l_addr_size);


    if( iv_scom_length != 0 && iv_scom_length != 0xffff) // most common values
    {
        if(iv_scom_length < 65)  // max scom len is 64 bits
        {
            for(size_t i = 0; i < numrows; ++i)
                add_bit_range(iv_scom_offset, iv_scom_offset + iv_scom_length - 1);
        }
        else // What's this?
        {
            ostringstream errs;
            errs << "ERROR: Invalid scom bit length [" << iv_scom_length << "]" << endl;
            throw range_error(errs.str());
        }
    }

    // when Rpn iv_when_rpn
    //iv_when_rpn.bin_read(bli);

    //
    for(size_t i = 0; i < numrows; ++i)
    {
        Rpn rpn(bli,iv_symbols);
        iv_scom_rpn.push_back(rpn);
    }

    if(numcols)
    {
        for(size_t i = 0; i < numrows; ++i) iv_row_rpn.push_back(Rpn(iv_symbols)); // blank RPNs

        // Read col heads
        for(size_t i = 0; i < numcols; ++i)
        {
            uint32_t var_tag = Rpn::extract16(bli);
            Rpn col_name_rpn(iv_symbols);
            col_name_rpn.append(iv_symbols->get_rpn_id(var_tag));
            iv_col_vars.push_back(col_name_rpn);
            iv_cols_rpn.push_back(iv_row_rpn);  // copy in blank row RPNs for this column
        }

        for(size_t row_n = 0; row_n < numrows; ++row_n)
        {
            COL_LIST::iterator cli = iv_cols_rpn.begin();       // *cli is list of row rpns for col
            RPN_LIST::iterator rpi = (*cli).begin() + row_n;    // *rpi is current row rpn for first col
            BINSEQ::const_iterator bli_end = bli + (*bli);      // end of rpn in bin seq
            ++bli; ++bli_end;                                   // adjust for first byte being len
            // The next len bytes belong to this row
            // Simple cols are divided by OPs
            // LIST op has two additional bytes (len,op)
            while(bli < bli_end) 
            {
                // Last col rpn is not limited to one op if it's "expr" - it gets the rest of the RPN
                if(cli == (iv_cols_rpn.end() - 1))
                {
                    while(bli < bli_end) bli = rpi->bin_read_one_op(bli);
                    break;
                }
                bli = rpi->bin_read_one_op(bli);
                ++cli;
                rpi = (*cli).begin() + row_n;
            }
        }
    }
    else ++bli;
}

//-------------------------------------------------------------------------------------------------

void Scom::set_when(const string * when_str)
{

    string s(*when_str);
    for(string::iterator c = s.begin(); c != s.end(); ++c) *c = toupper(*c);
    if(s.size())
    {
        size_t i = 0;
        for(size_t i = 1; i < sizeof(when_char)/sizeof(when_char[0]); ++i)
        {
            if(s[0] == when_char[i])
            {
                set_when((SCOM_WHEN)i);
                break;
            }
        }
        if(i == sizeof(when_char)/sizeof(when_char[0]))
        {
            string errs("Illegal when=");
            errs.append(s);
            yyerror(errs.c_str());
        }
        s.erase(0,1);

        if(s.size())
        {
            WHEN_SUBTYPE_MAP::const_iterator i = cv_when_subtypes.find(s);
            if(i != cv_when_subtypes.end())
            {
                set_sub_when(i->second);
            }
            else
            {
                std::ostringstream oss;
                oss << "Illegal 'when=' subvalue: [" << s << ']';
                yyerror(oss.str().c_str());
            }
        }
    }
    else
    {
        yyerror("Missing 'when =' value");
    }
}

//-------------------------------------------------------------------------------------------------

void Scom::add_col(const string & i_colname)
{
    string s(i_colname);
    for(string::iterator i = s.begin(); i != s.end(); ++i) *i = toupper(*i);
    Rpn col_rpn(s,iv_symbols); // = iv_symbols->use_symbol(s);
    
    // add check - Can't add any more cols after EXPR column dg001a
    if(iv_col_vars.size() && s != "EXPR")
    {
        Rpn exp_rpn("EXPR",iv_symbols);
        if(exp_rpn == iv_col_vars.back()) // expr col already added - can't add any more cols
        {
            yyerror("EXPR must be the last column");
        }
    }

    // if the entire column is unconditionally true it can be left out
    //  This check will be done later as this scom might be split by bit-ranges.

    iv_col_vars.push_back(col_rpn);
    iv_cols_rpn.push_back(iv_row_rpn); // add the collected row RPNs
    iv_row_rpn.clear();
}

//-------------------------------------------------------------------------------------------------

void Scom::add_row_rpn(Rpn * i_rpn)
{
    // The row gets parsed before the col name
    //  So collect the row RPNs and apply them when the col name gets added

    // Replace the Rpn "ANY" EQ with TRUE   dg003a
    Rpn any_rpn("ANY",iv_symbols);
    Rpn true_rpn(iv_symbols);
    true_rpn.push_op(Rpn::TRUE_OP);

    // The column EXPR can have an lone "ANY" rpn - so add EQ.
    if(any_rpn == (*i_rpn)) i_rpn->push_op(Rpn::EQ);
    any_rpn.push_op(Rpn::EQ);

    if(any_rpn == (*i_rpn)) iv_row_rpn.push_back(true_rpn); // Replace col == ANY with TRUE
    else
    {
        iv_row_rpn.push_back(*i_rpn);
    }
    delete i_rpn;
}

//-------------------------------------------------------------------------------------------------

void Scom::add_bit_range(uint32_t start, uint32_t end)
{
    // make sure they are added in order
    dbg << "Add bit range " << start << " to " << end;
    iv_range_list.push_back(RANGE(start,end));
}

//-------------------------------------------------------------------------------------------------
// Range gets parsed before the target symbol (k,n,p,c) - so save it
void Scom::add_target_range(uint32_t r1, uint32_t r2)
{
    if(r1 > r2)
    {
        uint32_t rt = r1;
        r1 = r2;
        r2 = rt;
    }
    iv_target_ranges.push_back(RANGE(r1,r2));
}

//-------------------------------------------------------------------------------------------------

void Scom::make_target(const char * i_symbol)
{
    string s(i_symbol);
    Rpn r(iv_symbols);
    size_t rsize = iv_target_ranges.size();

    if(rsize == 0)
    {
        yyerror("Target given w/o a range");
    }
    // if more than one target - use list
    else
    {
        for(RANGE_LIST::iterator iter = iv_target_ranges.begin(); iter != iv_target_ranges.end(); ++iter)
        {
            for(uint32_t v = iter->first; v <= iter->second; ++v)
            {
                r.push_int(v);
            }
        }
        if(rsize > 1) r.push_op(Rpn::LIST);   // if more than one target
        r.push_op(Rpn::EQ);
    }

    iv_row_rpn.push_back(r);
    add_col(s);
    iv_target_ranges.clear();
}

//-------------------------------------------------------------------------------------------------

string Scom::list_one(RANGE range)
{
    ostringstream oss;

    uint32_t numcols = iv_col_vars.size() | (iv_when & SUBTYPE_MASK);  // WHEN subtype goes in numcols
    uint32_t bitlen = range.second + 1 - range.first;
    if (bitlen) 
    {
        iv_scom_length = bitlen;         // don't overwrite iv_scom_length if bitlen == 0
        iv_scom_offset = range.first;    // don't overwrite iv_scom_offset if bitlen == 0
    }

    uint32_t allrows = 0;
    uint32_t numrows = 0;

    if(iv_cols_rpn.size()) allrows = iv_cols_rpn.front().size();
    if (allrows == 0) allrows = 1;

    // If there is a bit range we need to select only the rows that apply to this spyname
    if(bitlen)
    {
        for(RANGE_LIST::iterator r = iv_range_list.begin(); r != iv_range_list.end(); ++r)
        {
            if((*r) == range) ++numrows;
        }
    }
    else numrows = allrows; // else select all the rows

    uint32_t hierarchy = 0xFF;
#if 0
    for(SPY_NAMES::iterator hier = cv_hier_list.begin(); hier != cv_hier_list.end(); ++hier)
    {
        if((spyname.length() > hier->length()) && (spyname.compare(0,hier->length(),*hier) == 0))
        {
            char c = spyname[hier->length()];
            if(isdigit(c)) hierarchy = c - '0';
            break;
        }
    }
#endif
    oss << hex << setfill('0');
    oss << "------------";
    oss << " Scom Address: 0x" << setw(16) << iv_scom_addr_hex;
    if(bitlen)
    {
        oss << '~' << dec << range.first;
        if(range.first != range.second) oss << ':' << range.second;
        oss << hex;
    }
    oss << ' ' << "------------" << endl
        << "When= " << (iv_when & WHEN_MASK) << endl;

    oss << "0x" << setw(4) << iv_scom_length << "\t\t" << "Scom length" << endl
      << "0x" << setw(4) << iv_scom_offset << "\t\t" << "Scom offset" << endl;

    //oss << "0x" << setw(8) << iv_symbols->get_spy_id(spyname) << '\t';

    oss << "0x" << setw(4) << numcols << "\t\t" << "Number of columns" << endl
        << "0x" << setw(4) << numrows << "\t\t" << "Number of rows" << endl
        << "0x" << setw(2) << hierarchy << "\t\t" << "Hierarchy Instance\n" << endl;
        //<< iv_when_rpn.listing("Length of when RPN",spyname,true) << endl;

    // If there is a bit range we need to select only the spyv rows that apply to this spyname

    if(bitlen)
    {
        RPN_LIST::iterator i = iv_scom_rpn.begin();
        for(RANGE_LIST::iterator r = iv_range_list.begin(); r != iv_range_list.end(); ++r,++i)
        {
            if ((*r) == range)
            {
                oss << i->listing("Length of rpn for spyv",Rpn::cv_empty_str,true);
            }
        }
    }
    else // get all rows
    {
        for(RPN_LIST::iterator i = iv_scom_rpn.begin(); i != iv_scom_rpn.end(); ++i)
        {
            oss << i->listing("Length of rpn for spyv",Rpn::cv_empty_str,true);
        }
    }
    oss << endl;

#if 0
    // list the column names that are really CINI VARS
    for(RPN_LIST::iterator i = iv_col_vars.begin(); i != iv_col_vars.end(); ++i)
    {
        oss << i->listing("",spyname,true);
        //Rpn col_rpn = *i;
        //string desc = iv_symbols->find_name(rpn_id);
        //if(desc.size() == 0) desc = "Variable not found!";

        //oss << "0x" << setw(4) << iv_symbols->get_tag(*i) << "\t\t" << desc << endl;
    }
    oss << endl << endl;

#endif

    uint32_t usedrows = 0;
    if(iv_cols_rpn.size() == 0)
    {
        oss << "ROW " << 1 << "\n0x00" << "\t\t" << "0 BYTES" << endl;
    }
    else
    {
        for(size_t n = 0; n < allrows; ++n)
        {
            Rpn rpn(iv_symbols);
            if(bitlen) // only get rows that match the current bitrange
            {
                if(iv_range_list[n] != range) continue;
            }
            ++usedrows;
            oss << "ROW " << usedrows << endl;

            // Build up the row Rpn for row n
            for(COL_LIST::iterator i = iv_cols_rpn.begin(); i != iv_cols_rpn.end(); ++i)
            {
                rpn.append(i->at(n));
            }
            oss << rpn.listing(NULL,Rpn::cv_empty_str,true) << endl;
        }
    }

    return oss.str();
}

//-------------------------------------------------------------------------------------------------

string Scom::listing()
{
    ostringstream oss;

    set<RANGE> ranges;
    ranges.insert(iv_range_list.begin(),iv_range_list.end());

    //oss << list_one(RANGE(1,0)) << endl;
    if(ranges.size())
    {
        for(set<RANGE>::iterator r = ranges.begin(); r != ranges.end(); ++r)
        {
            oss << list_one(*r) << endl;
        }
    }
    else
    {
        oss << list_one(RANGE(1,0)) << endl;
    }

    return oss.str();
}

//-------------------------------------------------------------------------------------------------

uint32_t Scom::bin_listing(BINSEQ & blist)
{
    set<RANGE> ranges;
    uint32_t scom_count = 0;

    row_optimize();   // delete any rows that are unconditionally false. + merge rows

    ranges.insert(iv_range_list.begin(),iv_range_list.end());

    SCOM_ADDR::iterator i = iv_scom_addr.begin();
    // if more than one spyname, the first is just the stem of the name - skip it
    if(iv_scom_addr.size() > 1) ++i; 

    for(; i != iv_scom_addr.end(); ++i)
    {
        if(ranges.size())
        {
            for(set<RANGE>::iterator r = ranges.begin(); r != ranges.end(); ++r)
            {
                ++scom_count;
                //bin_list_one(blist,*i,*r);
                // The following sequence will optimize the bytecode for this spy
                //   - Compile the spy into bytecode for a range of bits
                //   - Recreate the spy from the bytecode
                //   - Compile the recreated spy back into bytecode.
                BINSEQ temp;
                bin_list_one(temp,strtoul((*i).c_str(),NULL,16), *r);
                BINSEQ::const_iterator bi = temp.begin();
                Scom s(bi,iv_symbols);
                s.bin_list_one(blist,strtoul((*i).c_str(),NULL,16), RANGE(1,0));
            }
        }
        else
        {
            ++scom_count;
            bin_list_one(blist,strtoul((*i).c_str(),NULL,16), RANGE(1,0));
        }
    }

    return scom_count;
}

//-------------------------------------------------------------------------------------------------

void Scom::bin_list_one(BINSEQ & blist,uint64_t i_addr, RANGE range)
{

    uint32_t numcols = iv_col_vars.size() | (iv_when & SUBTYPE_MASK); // WHEN subtype goes in numcols

// No range support
    uint32_t bitlen = range.second + 1 - range.first;

    if (bitlen) 
    {
        iv_scom_length = bitlen;         // don't overwrite iv_scom_length if bitlen == 0
        iv_scom_offset = range.first;    // don't overwrite iv_scom_offset if bitlen == 0
    }

    uint32_t allrows = 0;
    uint32_t numrows = 0;

    if(iv_cols_rpn.size()) allrows = iv_cols_rpn.front().size();
    if (allrows == 0) allrows = 1;

    // If there is a bit range we need to select only the rows that apply to this spyname
    if(bitlen)
    {
        for(RANGE_LIST::iterator r = iv_range_list.begin(); r != iv_range_list.end(); ++r)
        {
            if((*r) == range) ++numrows;
        }
    }
    else numrows = allrows; // else select all the rows


    uint32_t hierarchy = 0xFF;
// No hierarchy support
#if 0
    for(SPY_NAMES::iterator hier = cv_hier_list.begin(); hier != cv_hier_list.end(); ++hier)
    {
        if((spyname.length() > hier->length()) && (spyname.compare(0,hier->length(),*hier) == 0))
        {
            char c = spyname[hier->length()];
            if(isdigit(c)) hierarchy = c - '0';
            break;
        }
    }
#endif

    // If every row rpn in a column is unconditionally true then remove the col.
    if(iv_col_vars.size())
    {
        vector< pair<RPN_LIST::iterator, COL_LIST::iterator> > deletes;
        RPN_LIST::iterator cv = iv_col_vars.begin();  // -> column header Rpn
        COL_LIST::iterator cr = iv_cols_rpn.begin();  // -> RPN list of row segments for the column
        for(; cv != iv_col_vars.end(); ++cv,++cr)
        {
            bool remove_it = true;
            for(RPN_LIST::const_iterator r = cr->begin(); r != cr->end(); ++r)
            {
                if(!(r->isTrue()))
                {
                    remove_it = false;
                    break;
                }
            }
            if(remove_it)
            {
                deletes.push_back( pair<RPN_LIST::iterator, COL_LIST::iterator>(cv,cr) );
            }
        }
        while(deletes.size())
        {
            pair<RPN_LIST::iterator, COL_LIST::iterator> p = deletes.back();
            deletes.pop_back();
            dbg << "COL is unconditionally true. Removing column " << (p.first)->symbol_names()
                << endl;
            iv_col_vars.erase(p.first);
            iv_cols_rpn.erase(p.second);
            --numcols;
        }
    }

    Rpn::set16(blist,(uint16_t)iv_scom_length);
    Rpn::set16(blist,(uint16_t)iv_scom_offset);

    // Just put the SCOM address in place of the spy id
    //uint32_t id = iv_symbols->get_spy_id(spyname);
    //Rpn::set32(blist,id);
    // TODO - Probably need to get scom address id here
    //Rpn::set32(blist,(uint32_t)iv_address);

    Rpn *l_scom_addr = new init::Rpn(i_addr,yyscomlist->get_symbols());
    l_scom_addr->bin_str(blist,false);
    delete l_scom_addr;


// TODO - No Array support
#if 0
    if(iv_spy_type == ARRAY)
    {
        Rpn::set32(blist,iv_array_addr);
    }
#endif

    Rpn::set16(blist,(uint16_t)numcols);
    Rpn::set16(blist,(uint16_t)numrows);
    blist.push_back((uint8_t) hierarchy);

#if 0

    iv_when_rpn.bin_str(blist,spyname);
#endif

    // If there is a bit range we need to select only the spyv rows that apply to this spyname
    if(bitlen)
    {
        RPN_LIST::iterator i = iv_scom_rpn.begin();
        for(RANGE_LIST::iterator r = iv_range_list.begin(); r != iv_range_list.end(); ++r,++i)
        {
            if ((*r) == range)
            {
                i->bin_str(blist);
            }
        }
    }
    else // get all rows
    {
        for(RPN_LIST::iterator i = iv_scom_rpn.begin(); i != iv_scom_rpn.end(); ++i)
        {
            i->bin_str(blist);
        }
    }

    // list the column names that are really CINI VARS
    for(RPN_LIST::iterator i = iv_col_vars.begin(); i != iv_col_vars.end(); ++i)
    {
        i->bin_str(blist,false);  // false means don't prepend an RPN byte count to the binary rpn appended.
        //uint16_t tag = iv_symbols->get_tag(*i);
        //blist.push_back((uint8_t)(tag >> 8));
        //blist.push_back((uint8_t) tag);
    }

    if(iv_cols_rpn.size() == 0) blist.push_back(0);
    else
    {
        for(size_t n = 0; n < allrows; ++n)
        {
            Rpn rpn(iv_symbols);
            if(bitlen) // only get rows that match the current bitrange
            {
                if(iv_range_list[n] != range) continue;
            }

            // Build up the row Rpn for row n
            for(COL_LIST::iterator i = iv_cols_rpn.begin(); i != iv_cols_rpn.end(); ++i)
            {
                rpn.append(i->at(n));
            }
            rpn.bin_str(blist);
        }
    }
}

//-------------------------------------------------------------------------------------------------
// Delete any rows that are unconditionally false
// Merge rows that can be merged
//
void Scom::row_optimize()  //dg003a
{
    size_t row = 0;
    if (iv_cols_rpn.size()) row = iv_cols_rpn.front().size();
    if(row == 0) return;

    // Look for false rows
    do
    {
        bool remove_me = false;
        --row;
        for(COL_LIST::iterator i = iv_cols_rpn.begin(); i != iv_cols_rpn.end(); ++i)
        {
            if (i->at(row).isFalse())
            {
                remove_me = true;
                break;
            }
        }
        if(remove_me)
        {
            iv_scom_rpn.erase(iv_scom_rpn.begin() + row);   //remove spyv
            //Need to remove rpn row segment from each iv_cols_rpn rpn list
            for(COL_LIST::iterator i = iv_cols_rpn.begin(); i != iv_cols_rpn.end(); ++i)
            {
                i->erase(i->begin() + row);
            }
            if(iv_range_list.size()) iv_range_list.erase(iv_range_list.begin() + row);

            //dbg << "ROW is unconditionally false. Removing row " << row+1 << " from " << get_key_name() << endl;
        }
    } while (row);

    // now look for rows to merge
    // for now limit to spies with EXPR as the only column
    // Because the interpreter looks down the rows until it finds one that's "true" then stops, the order
    // of rows cant't be modified. This means only rows next to each other can be merged.
    // This makes for very large Rpn strings - turn on later when we have better redundancy reduction in RPNs
#if defined(__LATER__)
    Rpn r_expr("EXPR", iv_symbols);
    row = iv_spyv_rpn.size();
    if ((row > 1) && (iv_col_vars.size() == 1) && (iv_col_vars.front() == r_expr))
    {
        --row;
        do
        {
            size_t row1 = row - 1;

            if (iv_spyv_rpn.at(row) == iv_spyv_rpn.at(row1))
            {
                if (iv_range_list.size() == 0 || (iv_range_list.at(row) == iv_range_list.at(row1)))
                {
                    // merge
                    Rpn * rp = new Rpn(iv_cols_rpn.back().at(row));
                    iv_cols_rpn.back().at(row1).push_merge(rp, Rpn::OR); // this will delete rp
                    iv_spyv_rpn.erase(iv_spyv_rpn.begin() + row);
                    if (iv_range_list.size()) iv_range_list.erase(iv_range_list.begin() + row);
                    for (COL_LIST::iterator i = iv_cols_rpn.begin(); i != iv_cols_rpn.end(); ++i)
                    {
                        i->erase(i->begin() + row);
                    }
                    dbg << "ROW " << row+1 << " and " << row1+1 << " have been merged in " << get_key_name() << endl;
                }
            }
        } while (--row);
    }
#endif
}



//-------------------------------------------------------------------------------------------------

bool Scom::compare(Scom & that)
{
    bool result = false; //true;
// TODO
#if 0
    ostringstream oss;
    oss << hex << setfill('0');
    // spyname(s) should have already been tested
    oss << get_key_name() << endl;
    if(iv_spy_type != that.iv_spy_type ||
       iv_when != that.iv_when ||
       iv_spy_length != that.iv_spy_length ||
       iv_spy_offset != that.iv_spy_offset ||
       iv_array_addr != that.iv_array_addr)
    {
        result = false;
        oss << "type:   " << setw(8) << iv_spy_type << ' ' << that.iv_spy_type << endl;
        oss << "when:   " << setw(8) << iv_when << ' ' << that.iv_when << endl;
        oss << "len:    " << setw(8) << iv_spy_length << ' ' << that.iv_spy_length << endl;
        oss << "offset: " << setw(8) << iv_spy_offset << ' ' << that.iv_spy_offset << endl;
        oss << "array:  " << setw(8) << iv_array_addr << ' ' << that.iv_array_addr << endl;
    }
    // need to expand all Rpns to verify resolution of vars and lits
    // when Rpn
    string rpn1 = iv_when_rpn.listing("",iv_spy_names.front(),false);
    string rpn2 = that.iv_when_rpn.listing("",iv_spy_names.front(),false);
    if(rpn1 != rpn2)
    {
        result = false;
        oss << "this when Rpn:" << endl << rpn1 << endl;
        oss << "that when Rpn:" << endl << rpn2 << endl;
    }

    // spyv Rpn
    if(iv_spyv_rpn.size() != that.iv_spyv_rpn.size())
    {
       result = false;
       oss << "this spyv Rpn(s):" << endl;
       for(RPN_LIST::iterator r1 = iv_spyv_rpn.begin(); r1 != iv_spyv_rpn.end(); ++r1)
           oss << r1->listing("",iv_spy_names.front(),false) << endl;
       oss << "that spyv Rpn(s):" << endl;
       for(RPN_LIST::iterator r1 = that.iv_spyv_rpn.begin(); r1 != that.iv_spyv_rpn.end(); ++r1)
           oss << r1->listing("",iv_spy_names.front(),false) << endl;
    }
    else
    {
        RPN_LIST::iterator r1 = iv_spyv_rpn.begin();
        RPN_LIST::iterator r2 = that.iv_spyv_rpn.begin();
        for(; r1 != iv_spyv_rpn.end(); ++r1, ++r2)
        {
            rpn1 = r1->listing("",iv_spy_names.front(),false);
            rpn2 = r2->listing("",iv_spy_names.front(),false);
            if(rpn1 != rpn2)
            {
                result = false;
                oss << "this spyv Rpn:" << endl << rpn1 << endl;
                oss << "that spyv Rpn:" << endl << rpn2 << endl;
            }
        }
    }
    
    // column names
    if(iv_col_vars.size() != that.iv_col_vars.size())
    {
        result = false;
        oss << "this col names:" << endl;
        for(RPN_LIST::iterator i = iv_col_vars.begin(); i != iv_col_vars.end(); ++i)
        {
            oss << i->symbol_names() << endl;
        }
        oss << "that col names:" << endl;
        for(RPN_LIST::iterator i = that.iv_col_vars.begin(); i != that.iv_col_vars.end(); ++i)
        {
            oss << i->symbol_names() << endl;
        }
    }
    else
    {
        RPN_LIST::iterator i = iv_col_vars.begin();
        RPN_LIST::iterator j = that.iv_col_vars.begin();
        for(;i != iv_col_vars.end(); ++i, ++j)
        {
            //string s1 = iv_symbols->find_name(*i);
            //string s2 = that.iv_symbols->find_name(*j);
            if((*i) != (*j))
            {
                result = false;
                oss << "this col name: " << i->symbol_names() << endl;
                oss << "that col name: " << j->symbol_names() << endl;
            }
        }
    }
    
    // row Rpns
    Rpn r1(iv_symbols);
    Rpn r2(that.iv_symbols);
    for(COL_LIST::iterator c = iv_cols_rpn.begin(); c != iv_cols_rpn.end(); ++c)
    {
        for(RPN_LIST::iterator r = c->begin(); r != c->end(); ++r)
        {
            r1.append(*r);
        }
    }
    for(COL_LIST::iterator c = that.iv_cols_rpn.begin(); c != that.iv_cols_rpn.end(); ++c)
    {
        for(RPN_LIST::iterator r = c->begin(); r != c->end(); ++r)
        {
            r2.append(*r);
        }
    }
    rpn1 = r1.listing("",iv_spy_names.front(),false);
    rpn2 = r2.listing("",iv_spy_names.front(),false);
    if(rpn1 != rpn2)
    {
        result = false;
        oss << "this row/col rpn:" << endl;
        oss << rpn1 << endl;
        oss << "that row/col rpn:" << endl;
        oss << rpn2 << endl;
    }

    if(!result) cout << oss.str();
#endif
    return result;
}


//=================================================================================================
//  SpyList Class definitions
//=================================================================================================

ScomList::ScomList(const string & initfile, FILELIST & defines, ostream & stats, uint32_t i_ec)
    :
        iv_syntax_version(0),
        iv_symbols(new Symbols(defines)),
        iv_stats(stats),
        iv_ec(i_ec)

{
    yyscomlist = this;

    // What type of input? text(*.initfile) or binary(*.if) ?
    size_t pos = initfile.rfind('.');
    string type;
    if(pos != string::npos)
    {
        type = initfile.substr(pos+1);
    }

    if(type.compare(0,8,"initfile") == 0)   // source is text *.initfile
    {
        char line[100];
        string first_line;
        yyin = fopen(initfile.c_str(), "r");
        if(!yyin)
        {
            string ers("ERROR: Could not open initfile: ");
            ers.append(initfile);
            throw invalid_argument(ers);
        }
 
        // In Syntax version 1 the first or second line contains the CVS version
        fgets(line,100,yyin);
        first_line = line;
        fgets(line,100,yyin);
        first_line.append(line);
        yyline = 3;

        dbg << "======================= Begin Parse ========================" << endl;
        yyparse();   // Parse the initfile
        dbg << "======================= End Parse ==========================" << endl;

        if(iv_syntax_version == 1)
        {
            // example pattern  ..... $Id: galaxy.initfile,v 5.0 ......
            size_t pos = first_line.find("$Id:");
            if(pos != string::npos)
            {
                istringstream iss(first_line.substr(pos+4));
                string tok;
                iss >> tok;     // ex. galaxy.initfile,v
                iss >> tok;     // ex. 5.0
                iv_cvs_versions = tok;    // just want the version number - eg '5.0'
            }
        }

        iv_stats << '*' << setw(20) << "lines:" << setw(6) << yyline-1 << endl;
        iv_stats << '*' << setw(20) << "Scom statements:" << setw(6) << iv_scom_list.size() << endl;
        // TODO num var/lits num lits found
    }
    else if(type.compare(0,2,"if") == 0)  // source is binary *.if file
    {
// TODO - No support for this currently
#if 0
        dbg << "======================= Begin Uncompiling ========================" << endl;

        BINSEQ bin_seq;
        ifstream ifs(initfile.c_str(), ios_base::in | ios_base::binary);
        if(!ifs)
        {
            string msg("ERROR: SpyList::Could not open ");
            msg.append(initfile);
            throw invalid_argument(msg);
        }
        while(1)
        {
            int ch = ifs.get();
            if (!(ifs.good())) break;
            bin_seq.push_back(ch);
        }
        ifs.close();

        // Turn this back into a list of spies
        BINSEQ::const_iterator bli = bin_seq.begin();
        BINSEQ::const_iterator b;

        iv_syntax_version = Rpn::extract32(bli);
        bli += 8;
        if(iv_syntax_version == 1)
        {
            for(b = bli-8; (b != bli) && (*b); ++b)
            {
                iv_cvs_versions.push_back(*b);
            }
        }
        else
        {
            // offset to CVS sub version section
            b = bin_seq.begin() + Rpn::extract32(bli);
            size_t size = Rpn::extract16(b);
            while(size--) iv_cvs_versions.push_back(*b++); 
        }

        b = bin_seq.begin() + Rpn::extract32(bli);
        iv_symbols->restore_var_bseq(b);

        b =  bin_seq.begin() + Rpn::extract32(bli);
        iv_symbols->restore_lit_bseq(b);
        
        size_t section_count    = Rpn::extract32(bli);
        if(section_count > LAST_WHEN_TYPE)
        {
            throw range_error("ERROR: SpyList::SpyList - Inalid # of sections");
        }

        for(size_t i = 0; i < section_count; ++i)
        {
            size_t spy_type = Rpn::extract32(bli);        // type
            size_t offset   = Rpn::extract32(bli);        // offset
            size_t count    = Rpn::extract32(bli);        // Number of spies

            b = bin_seq.begin() + offset;
            if(!(b < bin_seq.end()))
            {
                throw overflow_error("ERROR: SpyList::SpyList - iterator overflowed sequence");
            }
            if(spy_type > LAST_WHEN_TYPE || spy_type == 0)
            {
                throw range_error("ERROR: SpyList::SpyList - when= type out of range");
            }
            while(count--)
            {
                Scom * s = new Scom(b,iv_symbols);
                insert(s);
                s->set_when((SPY_WHEN)spy_type);
            }
        }
#endif
        dbg << "======================= End Uncompiling ========================" << endl;
    }
    else
    {
        ostringstream ess;
        ess << "ERROR: SpyList::SpyList Invalid file type: " << type;
        ess << "\n   source: " << initfile;
        throw invalid_argument(ess.str());
    }
}

//-------------------------------------------------------------------------------------------------

ScomList::~ScomList()
{
    delete iv_symbols;
}

//-------------------------------------------------------------------------------------------------

void ScomList::clear()
{
    for(SCOM_LIST::iterator i = iv_scom_list.begin(); i != iv_scom_list.end(); ++i) delete i->second;
    iv_scom_list.clear();
}

//-------------------------------------------------------------------------------------------------

void ScomList::set_syntax_version(uint32_t v)
{
    if(v != 1 && v != 2) yyerror("Invalid Syntax Version");
    iv_syntax_version = v;
}

//-------------------------------------------------------------------------------------------------

void ScomList::compile(BINSEQ & bin_seq)
{
    uint32_t count_l = 0;
    uint32_t count_s = 0;
    uint32_t count_c = 0;
    uint32_t count_d = 0;
    uint32_t section_count = 0;
    size_t   offset = 0;


    BINSEQ blist_v;     // vars
    BINSEQ blist_i;     // lits
    BINSEQ blist_l;     // when=L spies
    BINSEQ blist_s;     // when=S spies
    BINSEQ blist_c;     // when=C spies
    BINSEQ blist_d;     // when=D spies

    // Make the BINSEQs big enough to hopefully never have to resize
    blist_v.reserve(0x00400);
    blist_i.reserve(0x02000);
    blist_l.reserve(0x30000);
    blist_s.reserve(0x03000);
    blist_c.reserve(0x03000);
    blist_d.reserve(0x03000);


    dbg << "======================== Begin compile ============================" << endl;
    Rpn::set32(bin_seq,iv_syntax_version);      //  bytes[0:3]

    // bytes [4:12]
    if(iv_syntax_version == 2) 
    {
        const char * s = "SEE SUBV";
        for(; *s != 0; ++s) bin_seq.push_back(*s);
        istringstream iss(iv_cvs_versions);
        string vers;
        while(iss >> vers)
        {
            stats << '*' << setw(20) << "Version:" << "  " << vers << endl;
        }
    }
    else if (iv_syntax_version == 1)
    {
        if(iv_cvs_versions.size())
        {
            size_t len = iv_cvs_versions.size();
            if(len > 8) { iv_cvs_versions.erase(9); len = 8; }
            for(string::const_iterator s = iv_cvs_versions.begin();
                s != iv_cvs_versions.end(); ++s)
            {
                bin_seq.push_back(*s);
            }
            while(len < 8) { bin_seq.push_back(0); ++len; }
            stats << '*' << setw(20) << "Version:" << setw(6) << iv_cvs_versions << endl;
        }
        else
        {
            throw range_error("ERROR: No CVS version(s) specified");
        }
    }
    else // syntax version already validated to be 1 or 2 - so if we get here it was never set.
    {
        throw range_error("ERROR: No sytax version specified!");
    }
    stats << '*' << setw(20) << "Syntax Version:" << setw(6) << iv_syntax_version << endl;


    // Determine the number of scoms in each section

    for(SCOM_LIST::iterator i = iv_scom_list.begin(); i != iv_scom_list.end(); ++i)
    {
        // Filter out filtered spies dg003a
        if(!(i->second->valid_when(dbg,iv_ec)))
        {
            continue;
        }

        if     (i->second->do_when(LONG_SCAN))  count_l += i->second->bin_listing(blist_l);
        else if(i->second->do_when(SCOM))       count_s += i->second->bin_listing(blist_s);
        else if(i->second->do_when(CFAMINIT))   count_c += i->second->bin_listing(blist_c);
        else if(i->second->do_when(DRAMINIT))   count_d += i->second->bin_listing(blist_d);
        else
        {
            ostringstream oss;
            oss << "ERROR: Invalid 'when=' type:\n" 
                << i->second->listing();
            throw range_error(oss.str());
        }

    }
    if(count_l) ++section_count;
    if(count_s) ++section_count;
    if(count_c) ++section_count;
    if(count_d) ++section_count;

    offset = bin_seq.size() + 12 + (12 * section_count);   // offset to the end of the header section
    stats << '*' << setw(20) << "Sections:" << setw(6) << section_count << endl;
   
    // for verion 2 add offset to CVS versions section
    if(iv_syntax_version == 2) 
    {
        offset += 4;
        Rpn::set32(bin_seq,offset);
        offset += iv_cvs_versions.length() + 2;
    }
    // offset now points to start of Var Symbol Table

    iv_symbols->bin_vars(blist_v);         // get Var table
    iv_symbols->bin_lits(blist_i);         // Get Lit table
    
    Rpn::set32(bin_seq,offset);           // Offset to Variable Symbol Table
    offset += blist_v.size();             // offset += var table byte size
    Rpn::set32(bin_seq,offset);           // Offset to Literal Symbol Table
    offset += blist_i.size();             // offset += lit table byte size
    Rpn::set32(bin_seq,section_count);    // Number of Spy Sections

    if(count_l)
    {
        Rpn::set32(bin_seq,LONG_SCAN);          // Spy Section Type (L)
        Rpn::set32(bin_seq,offset);             // Spy Section Type L Offset
        Rpn::set32(bin_seq,count_l);            // Number of L spies
        offset += blist_l.size();               // offset += byte size of when=L tables
    }
    if(count_c)
    {
        Rpn::set32(bin_seq,CFAMINIT);           // Spy Section Type (C)
        Rpn::set32(bin_seq,offset);             // Spy Section Type L Offset
        Rpn::set32(bin_seq,count_c);            // Number of L spies
        offset += blist_c.size();               // offset += byte size of when=L tables
    }
    if(count_d)
    {
        Rpn::set32(bin_seq,DRAMINIT);           // Spy Section Type (D)
        Rpn::set32(bin_seq,offset);             // Spy Section Type L Offset
        Rpn::set32(bin_seq,count_d);            // Number of L spies
        offset += blist_d.size();               // offset += byte size of when=L tables
    }
    if(count_s)
    {
        Rpn::set32(bin_seq,SCOM);               // Spy Section Type (S)
        Rpn::set32(bin_seq,offset);             // Spy Section Type S Offset
        Rpn::set32(bin_seq,count_s);            // Number of S spies
    }

    if(iv_syntax_version == 2) // Add Sub-version section
    {
        Rpn::set16(bin_seq,(uint16_t)iv_cvs_versions.length()); // Length of Sub version
        bin_seq.insert(bin_seq.end(), iv_cvs_versions.begin(), iv_cvs_versions.end());
    }

    bin_seq.insert(bin_seq.end(), blist_v.begin(), blist_v.end());      // add var table section
    bin_seq.insert(bin_seq.end(), blist_i.begin(), blist_i.end());      // add lit table section
    if(count_l) 
    {
        bin_seq.insert(bin_seq.end(), blist_l.begin(), blist_l.end());  // add when=L spies
        stats << '*' << setw(20) << "L scoms:" << setw(6) << count_l << endl;
    }
    if(count_c)
    {
        bin_seq.insert(bin_seq.end(), blist_c.begin(), blist_c.end());  // add when=C spies
        stats << '*' << setw(20) << "C scoms:" << setw(6) << count_c << endl;
    }
    if(count_d)
    {
        bin_seq.insert(bin_seq.end(), blist_d.begin(), blist_d.end());  // add when=D spies
        stats << '*' << setw(20) << "D scoms:" << setw(6) << count_d << endl;
    }
    if(count_s)
    {
        bin_seq.insert(bin_seq.end(), blist_s.begin(), blist_s.end());  // add when=S spies
        stats << '*' << setw(20) << "S scoms:" << setw(6) << count_s << endl;
    }
    dbg << "======================== End compile ============================" << endl;
}

//-------------------------------------------------------------------------------------------------

bool Scom::valid_when(ostream & msg, uint32_t i_ec)    //dg002a dg003c
{
    bool result = true;

    // unconditional state was determined earlier
    if( iv_when_rpn.isTrue()) // unconditionally true - Rpn is not needed.
        iv_when_rpn.clear();
    else if( iv_when_rpn.isFalse()) //unconditionally false
        result = false;
    else if(i_ec != 0xffffffff)
    {
        if(iv_when_rpn.resolve_ec(i_ec) == false) result = false;
    }
#if 0
    if(result == false)
    {
        msg << hex;
        SPY_NAMES::iterator i = iv_spy_names.begin();
        // if more than one spyname, the first is just the stem of the name - skip it
        if(iv_spy_names.size() > 1) ++i; 

        for(; i != iv_spy_names.end(); ++i)
        {
            if(i_ec != 0xffffffff)
                msg << "For EC " << i_ec << ": ";

            msg << "Removing spy " << *i << endl;
        }
        msg << iv_when_rpn.listing("WHEN RPN","",true) << endl;
    }
#endif
    return result;
}

//-------------------------------------------------------------------------------------------------

void ScomList::listing(BINSEQ & bin_seq,ostream & olist)
{
    dbg << "======================= Begin Listing ========================" << endl;

    BINSEQ::const_iterator bli = bin_seq.begin();
    BINSEQ::const_iterator b;
    uint32_t syntax_version = Rpn::extract32(bli);

    string cvs_versions;

    olist << hex << setfill('0');
    olist << "--------------- FILE HEADER ------------------------\n\n";
    olist << fmt8(syntax_version)               << "[Syntax Version]\n"
          << "0x";
    bli += 8;
    for(b = bli-8; b != bli; ++b) olist << setw(2) << (uint32_t)(*b);
    olist << " [";
    for(b = bli-8; b != bli; ++b) if((*b) != 0) olist << (char)(*b);
    olist << "]\t[CVS Version]\n";
    if(syntax_version == 2)
    {
        size_t offset = Rpn::extract32(bli);
        olist << fmt8(offset)    << "[Offset to Sub-Version Section]\n";
    }
  
    uint32_t var_table_offset = Rpn::extract32(bli);
    uint32_t lit_table_offset = Rpn::extract32(bli);
    uint32_t section_count    = Rpn::extract32(bli);

    olist << fmt8(var_table_offset)             << "[Offset to Variable Symbol Table]\n";
    olist << fmt8(lit_table_offset)             << "[Offset to Literal Symbol Table]\n";
    olist << fmt8(section_count)                << "[Number of Scom Sections]\n";


    b = bin_seq.begin() + var_table_offset;
    iv_symbols->restore_var_bseq(b);

    b =  bin_seq.begin() + lit_table_offset;
    iv_symbols->restore_lit_bseq(b);

    if(section_count > LAST_WHEN_TYPE)
    {
        throw range_error("ERROR: ScomList::listing - Inalid # of sections");
    }

    b = bli;  // save

    for(size_t i = 0; i < section_count; ++i)
    {
        size_t spy_type = Rpn::extract32(bli);        // type
        size_t offset   = Rpn::extract32(bli);        // offset
        size_t count    = Rpn::extract32(bli);        // Number of spies

        if(spy_type == 0 || spy_type > LAST_WHEN_TYPE)
        {
            throw range_error("ERROR: ScomList::listing - when= type out of range");
        }
        char t = when_char[spy_type];

        olist << fmt8(spy_type) << "[Scom Section Type (" << t << ")]\n";
        olist << fmt8(offset)   << "[Scom Section Type (" << t << ") Offset]\n";
        olist << fmt8(count)    << "[Number of " << t << " scoms]\n";
    }
    olist << endl;

    if(syntax_version == 2)
    {
        olist << "--------------- Sub Version Section ---------------\n\n";
        uint16_t len = Rpn::extract16(bli);
        olist << "0x" << setw(4) << len << "\t\t"
            << "Length of Sub Version Section\n\n";
        for(uint16_t i = 0; i < len; ++i) olist << (char)(*bli++);
        olist << endl;
    }

    olist << iv_symbols->listing() << endl;
    olist << "------------------- SCOM TABLES ------------------------\n\n"
          << endl;

    bli = b;   // restore
    for(size_t i = 0; i < section_count; ++i)
    {

        size_t scom_type = Rpn::extract32(bli);        // type
        size_t offset   = Rpn::extract32(bli);        // offset
        size_t count    = Rpn::extract32(bli);        // Number of scoms


        if(scom_type == 0 || scom_type > LAST_WHEN_TYPE)
        {
            throw range_error("ERROR: ScomList::listing - when= type out of range");
        }
        char t = when_char[scom_type];

        olist << "------------ " << t << " Scoms -----------\n\n";

        b = bin_seq.begin() + offset;
        if(!(b < bin_seq.end()))
        {
            throw overflow_error("ERROR: ScomList::listing - iterator overflowed sequence");
        }
        while(count--)
        {
            Scom s(b,iv_symbols);
            s.set_when((SCOM_WHEN)scom_type);
            olist << s.listing() << endl;
        }
    }
    dbg << "======================= End Listing ========================" << endl;
}

//-------------------------------------------------------------------------------------------------

string ScomList::fmt8(uint32_t val)
{
    ostringstream oss;
    oss << setfill('0');
    oss << "0x" << hex << setw(8) << val << "\t   " << '[' << dec << val << ']' << '\t';
    if(val < 100) oss  << '\t';
    return oss.str();
}


//-------------------------------------------------------------------------------------------------

void ScomList::insert(Scom * i_scom)
{
    uint64_t l_addr = i_scom->get_address();
    SCOM_LIST::iterator i = iv_scom_list.find(l_addr);
    if(i == iv_scom_list.end())
    {
        iv_scom_list[l_addr] = i_scom;
    }
    else
    {
        ostringstream oss;
        oss << "Duplicate scom statement found on line " << i_scom->get_line() << endl;
        oss << "First instance found on line " << i->second->get_line() << "Address: " << i_scom->get_address() << endl;
        yyerror(oss.str().c_str());
    }
}

//-------------------------------------------------------------------------------------------------

bool ScomList::compare(ScomList & that)
{
    bool result = true;
    dbg << "======================= Begin Compare ========================" << endl;
    if(iv_scom_list.size() != that.iv_scom_list.size())
    {
        cout << "E> Lists are not the same size" << endl;
        result = false;
    }

    // check each spy section
    for(SCOM_LIST::iterator i = iv_scom_list.begin(); i != iv_scom_list.end(); ++i)
    {
        // The name checks spyname, arrayaddr (if array), bitrange(s) (if any)
        uint64_t l_addr = i->second->get_address();
        SCOM_LIST::iterator j = that.iv_scom_list.find(l_addr);
        if(j == that.iv_scom_list.end())
        {
            cout << "E> " << l_addr << " not found in both lists!" << endl;
            result = false;
            continue;
        }
        if(i->second->compare(*(j->second)) == false)
        {
            cout << "E> Spy: " << l_addr << " does not match!" << endl;
            result = false;   
        }
    }

    // check for spies in that that are not in this
    for(SCOM_LIST::iterator i = that.iv_scom_list.begin(); i != that.iv_scom_list.end(); ++i)
    {
        uint64_t l_addr = i->second->get_address();
        SCOM_LIST::iterator j = iv_scom_list.find(l_addr);
        if(j == iv_scom_list.end())
        {
            cout << "E> " << l_addr << " not found in both lists!" << endl;
            result = false;
        }
    }
    dbg << "======================= End Compare ========================" << endl;
    return result;
}

//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------

void Scom::set_scom_address(const string & i_scom_addr)
{

    if(iv_scom_addr.size())
    {
        yyerror("SCOM Address already set!");
    }
    else
    {
        iv_scom_addr.push_back(i_scom_addr);
        // cout << "I>Scom::set_scom_address: " << i_scom_addr << " is the output string!" << endl;
    }
}

//-------------------------------------------------------------------------------------------------


void Scom::dup_scom_address(const string & i_scom_addr)
{


    if(iv_scom_addr.size())
    {
        iv_scom_addr.push_back(iv_scom_addr.front() + i_scom_addr);
    }
    else
        yyerror("No base scom address to dulicate for append!");

        // cout << "I>Scom::dup_scom_address: "<< i_scom_addr << " is the output string!" << endl;
}

//-------------------------------------------------------------------------------------------------

void Scom::set_scom_suffix(const string & i_scom_addr)
{

    if(iv_scom_addr.size() == 1) iv_scom_addr[0] = iv_scom_addr[0] + i_scom_addr;
    else if(iv_scom_addr.size() > 1)
    {
        SCOM_ADDR::iterator i = iv_scom_addr.begin();
        ++i;
        for(;i != iv_scom_addr.end(); ++i)
        {
            *i += i_scom_addr;
        }
    }
    else
        yyerror("No base scom address to append suffix");

        // cout << "I>Scom::set_scom_suffix: "<< i_scom_addr << " is the output string!" << endl;
}
