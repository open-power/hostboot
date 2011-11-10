// IBM_PROLOG_BEGIN_TAG
// This is an automatically generated prolog.
//
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/ifcompiler/initSymbols.C,v $
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
//  Flag Track     Userid   Date     Description                
//  ---- --------  -------- -------- -------------------------------------------------------------
//       D754106   dgilbert 06/14/10 Create
//                 dgilbert 10/22/10 Add spies_are_in()
//                 andrewg  09/19/11 Updates based on review
//                 camvanng 11/08/11 Added support for attribute enums
// End Change Log *********************************************************************************

/**
 * @file initSymbols.C
 * @brief Definition of the initSymbols class. Handles all symbols for initfiles
 */

#include <initSymbols.H>
#include <initRpn.H>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdlib.h>

using namespace init;

ostringstream errss;

#define SYM_EXPR 0x10000000

// ------------------------------------------------------------------------------------------------

Symbols::Symbols(FILELIST & i_filenames)
    : iv_used_var_count(1), iv_used_lit_count(1), iv_rpn_id(1)
{
    string fileline;

    for(FILELIST::iterator fn = i_filenames.begin(); fn != i_filenames.end(); ++fn)
    {
        printf("Parsing file %s\n",fn->c_str());
        uint32_t lineno = 0;
        ifstream infs(fn->c_str());
        if(!infs)
        {
            errss.str("");
            errss << "ERROR - Could not open " << *fn;
            throw invalid_argument(errss.str());
        }
        while(getline(infs,fileline))
        {
            ++lineno;
            if(fileline.size() == 0) continue;
            if(fileline[0] == '/') continue;
            istringstream iss(fileline);
            string def;
            iss >> def;
            //printf("def: %s\n",def.c_str());
            if(def == "enum")
            {
                // Make sure it's the AttributeId enum
                iss >> def;
                if(def == "AttributeId")
                {
                    // We've now found the beginning of the attribute enum definition
                    // Read and skip the '{' on the next line
                    getline(infs,fileline);
                    getline(infs,fileline);

                    // We're just parsing the enum in order so values start
                    // at 0 and increment by 1 after that.
                    uint32_t value = 0;

                    while(fileline[0] != '}')
                    {
                        istringstream attr_stream(fileline);
                        string attr;
                        attr_stream >> attr;

                        // Strip off the "," at the end.
                        size_t pos = attr.find(',');
                        if(pos != string::npos)
                        {
                            attr = attr.substr(0,attr.length()-1);
                        }

                        //printf("Attribute String:%s\n",attr.c_str());
                        // We now have the first attribute loaded into attr
                        // Get a value for the string

                        iv_symbols[attr] = MAP_DATA(value,NOT_USED);
                        value++;
                        getline(infs,fileline);
                    }
                }
                else
                {
                    // Make sure it's an attribute enum

                    string attribute_enum_name;
                    string find_enum = "_Enum";

                    // Check for _Enum in the name
                    size_t pos = def.find(find_enum);
                    if(pos != string::npos)
                    {
                        // We've now found the beginning of the attribute enum definition
                        // Read and skip the '{' on the next line
                        getline(infs,fileline);
                        getline(infs,fileline);

                        // We're just parsing the enum in order so values start
                        // at 0 and increment by 1 after that unless they are
                        // explicitly assigned.
                        uint64_t value = 0;

                        while(fileline[0] != '}')
                        {
                            istringstream attr_enum_stream(fileline);
                            string attr_enum;
                            string tmp;
                         
                            // Get the attribute enum name
                            attr_enum_stream >> attr_enum;

                            // Strip off the "," at the end.
                            pos = attr_enum.find(',');
                            if(pos != string::npos)
                            {
                                attr_enum = attr_enum.substr(0,attr_enum.length()-1);
                            }
                            else
                            {
                                // Is a value for the enum specified?
                                attr_enum_stream >> tmp;

                                if (!attr_enum_stream.eof())
                                {
                                    //Make sure it's an '='
                                    if ("=" != tmp)
                                    {
                                        printf ("ERROR: Unknown attribute enum! %s\n",attr_enum.c_str());
                                        exit(1);
                                    }
                                    else
                                    {
                                        attr_enum_stream >> tmp;
                                        value = strtoll(tmp.c_str(), NULL, 0);
                                    }
                                }
                            }

                            //printf("Attribute Enum String:%s Value %u\n",attr_enum.c_str(), value);

                            // Get a value for the string
                            iv_attr_enum[attr_enum] = value;
                            value++;
                            getline(infs,fileline);
                        }
                    }
                }
            }
            else if(def == "typedef")
            {
                 string type;
                 string attribute_name;
                 string find_type = "_Type";
                 string find_array = "[";
                 bool array = false;
                 iss >> type;
                 iss >> attribute_name;
                 if(attribute_name == "*")
                 {
                     // It's a pointer type so read in the next string
                     iss >> attribute_name;
                     type = type + "*";
                 }
                 //printf("typedef: type:%s  attribute_name:%s\n",type.c_str(),attribute_name.c_str());

                 // Check if there's a "[" in the string, which would indicate it's an array
                 size_t pos = attribute_name.find(find_array);
                 if(pos != string::npos)
                 {
                     array = true;
                 }

                 // Now strip off the _type in the name
                 pos = attribute_name.find(find_type);
                 if(pos != string::npos)
                 {
                     attribute_name = attribute_name.substr(0,pos);
                 }
                 else
                 {
                     printf ("ERROR: Unknown attribute type! %s\n",attribute_name.c_str());
                     exit(1);
                 }

                 iv_attr_type[attribute_name] = get_attr_type(type,array);
                 //printf("Attribute %s Type for %s is %u\n",attribute_name.c_str(),type.c_str(),get_attr_type(type,array));
            }
        }
        infs.close();
    }
    iv_rpn_map[Rpn::SYMBOL | INIT_EXPR_VAR] = RPN_DATA("EXPR",SYM_EXPR);
    iv_rpn_map[Rpn::SYMBOL | INIT_ANY_LIT]  = RPN_DATA("ANY",CINI_LIT_MASK);
}

uint32_t Symbols::get_attr_type(const string &i_type, bool i_array)
{

    if (i_type == "uint8_t")
    {
        if(i_array == true)
        {
            return(SYM_ATTR_UINT8_ARRAY_TYPE);
        }
        else
        {
            return(SYM_ATTR_UINT8_TYPE);
        }
    }
    else if(i_type == "uint32_t")
    {
        if(i_array == true)
        {
            return(SYM_ATTR_UINT32_ARRAY_TYPE);
        }
        else
        {
            return(SYM_ATTR_UINT32_TYPE);
        }
    }
    else if(i_type == "uint64_t")
    {
        if(i_array == true)
        {
            return(SYM_ATTR_UINT64_ARRAY_TYPE);
        }
        else
        {
            return(SYM_ATTR_UINT64_TYPE);
        }
    }
    //else if(i_type == "uint64_t")
    // TODO - Add attribute array support
    else
    {
        // TODO - Need to ensure all attributes have data type at the end of processing
        printf("Unknown data type: %s\n",i_type.c_str());
        return(0);
    }

}

// ------------------------------------------------------------------------------------------------

void Symbols::add_define(const string * name, const Rpn * rpn)
{
    string s(*name);
    translate_spyname(s);
    iv_defines[s] = DEF_DATA(*rpn,NOT_USED);
}

// -------------------------------------------------------------------------------------------------

Rpn Symbols::get_define_rpn(uint32_t rpn_id)
{
    Rpn r(this);
    for(DEF_MAP::iterator i = iv_defines.begin(); i != iv_defines.end(); ++i)
    {
        if(i->second.second == rpn_id)
        {
            r = i->second.first;
            break;
        }
    }
    return r;
}

// ------------------------------------------------------------------------------------------------

uint32_t Symbols::use_symbol(string & i_symbol)
{
    uint32_t rpn_id = Rpn::SYMBOL | NOT_FOUND;
    if(i_symbol == "ANY") rpn_id = INIT_ANY_LIT | Rpn::SYMBOL;
    else if(i_symbol == "EXPR") rpn_id = INIT_EXPR_VAR | Rpn::SYMBOL;
    else if(i_symbol.compare(0,3,"DEF") == 0)
    {
        DEF_MAP::iterator i = iv_defines.find(i_symbol);
        if(i != iv_defines.end())
        {
            if(i->second.second == NOT_USED)
            {
                rpn_id = Rpn::DEFINE | iv_rpn_id++;
                i->second.second = rpn_id;
            }
            else
            {
                rpn_id = i->second.second;
            }
        }
        else
        {
            rpn_id = add_undefined(i_symbol);
        }
    }
    else
    {
        SYMBOL_MAP::iterator i = iv_symbols.find(i_symbol);
        if(i != iv_symbols.end())
        {
            if(i->second.second == NOT_USED)
            {
                rpn_id = Rpn::SYMBOL | iv_rpn_id++;
                i->second.second = rpn_id;
                iv_rpn_map[rpn_id] = RPN_DATA(i_symbol,i->second.first);

                //printf ("Symbols::use_symbol: Just added %s symbol, rpn_id:0x%8X to iv_rpn_map\n",i_symbol.c_str(),rpn_id);

                if(i->second.first & CINI_LIT_MASK)     ++iv_used_lit_count;
                else                                    ++iv_used_var_count;
            }
            else
            {
                rpn_id = i->second.second;
            }
        }
        else 
        {
            rpn_id = add_undefined(i_symbol);
        }
    }

    return rpn_id;
}

// ------------------------------------------------------------------------------------------------

uint32_t Symbols::add_undefined(const string & i_symbol)
{
    uint32_t rpn_id = 0;

    SYMBOL_MAP::iterator i = iv_not_found.find(i_symbol);
    if(i != iv_not_found.end())
    {
        rpn_id = i->second.second;
    }
    else
    {
        rpn_id = Rpn::SYMBOL | iv_rpn_id++;
        iv_not_found[i_symbol] = MAP_DATA(NOT_FOUND,rpn_id);
        iv_rpn_map[rpn_id] = RPN_DATA(i_symbol,CINI_ID_NOT_FOUND);
    }
    return rpn_id;
}

// ------------------------------------------------------------------------------------------------

uint16_t Symbols::get_tag(uint32_t i_rpn_id)
{
    uint16_t tag = NOT_FOUND;
    uint32_t cini_id = CINI_ID_NOT_FOUND;

    // Set up tag table if not already setup
    if(iv_used_var.size() == 0)
    {
        iv_used_var.reserve(iv_used_var_count); // makes if faster
        iv_used_lit.reserve(iv_used_lit_count);

        iv_used_var.push_back(iv_rpn_map[Rpn::SYMBOL|INIT_EXPR_VAR].second); // EXPR var always first
        iv_used_lit.push_back(iv_rpn_map[Rpn::SYMBOL|INIT_ANY_LIT].second);  // ANY lit always first

        for(SYMBOL_MAP::iterator i = iv_symbols.begin(); i != iv_symbols.end(); ++i)
        {
            if(i->second.second != NOT_USED)
            {
                if((i->second.first & CINI_LIT_MASK) ==  CINI_LIT_MASK)
                {
                    iv_used_lit.push_back(i->second.first);
                }
                else  //VAR
                {
                    iv_used_var.push_back(i->second.first);
                }
            }
        }
    }

    do
    {

        RPN_MAP::iterator rm = iv_rpn_map.find(i_rpn_id);
        if(rm != iv_rpn_map.end())
        {
            cini_id = (rm->second).second;
        }
        else
        {
            //SYMBOL_MAP::iterator sm = iv_not_found.begin();
            //for(; sm != iv_not_found.end(); ++sm)
            //{
            //    if((sm->second).second == i_rpn_id)
            //    {
            //        break;
            //    }
            //}

            //if(sm == iv_not_found.end())
            //{
                ostringstream err;
                err << hex;
                err << "ERROR! Symbols::get_tag() bad arg rpn_id = " << i_rpn_id << endl;
                throw invalid_argument(err.str());
            //}
            break;
        }


        if((cini_id & CINI_LIT_MASK) == CINI_LIT_MASK)
        {
            uint32_t offset = 0;
            for(SYMBOL_USED::iterator i = iv_used_lit.begin(); i != iv_used_lit.end(); ++i,++offset)
            {
                if(cini_id == *i) 
                {
                    tag = (uint16_t) (offset | LIT_TYPE);
                    break;
                }
            }
        }
        else // vars
        {
            uint32_t offset = 0;
            for(SYMBOL_USED::iterator i = iv_used_var.begin(); i != iv_used_var.end(); ++i,++offset)
            {
                if(cini_id == *i) 
                {
                    tag = (uint16_t) (offset | VAR_TYPE);
                    break;
                }
            }
        }
    } while(0);

    return tag;
}




// ------------------------------------------------------------------------------------------------

string Symbols::find_name(uint32_t i_rpn_id)
{
    string name;
    RPN_MAP::iterator rm = iv_rpn_map.find(i_rpn_id);
    if(rm != iv_rpn_map.end())
    {
        name = (rm->second).first;
    }
    else name = "NOT FOUND";
    return name;
}

// ------------------------------------------------------------------------------------------------

uint32_t Symbols::find_numeric_lit(uint64_t i_data, int32_t byte_size)
{
    uint32_t offset = 0;
    LIT_LIST::iterator i = iv_lits.begin();
    for(; i != iv_lits.end(); ++i,++offset)
    {
        if(i_data == i->first && (uint32_t)byte_size == i->second)
            break;
    }
    if(i == iv_lits.end())
    {
        iv_lits.push_back(LIT_DATA(i_data,byte_size));
    }
    //printf("Symbols::find_numeric_lit: i_data:0x%llX byte_size:%d Tag:0x%X\n",
    //      i_data,byte_size, offset | Rpn::NUMBER);
    return offset | Rpn::NUMBER;
}

uint32_t Symbols::find_numeric_array_lit(uint64_t i_data, int32_t byte_size)
{
    uint32_t offset = 0;
    LIT_LIST::iterator i = iv_lits.begin();
    for(; i != iv_lits.end(); ++i,++offset)
    {
        if(i_data == i->first && (uint32_t)byte_size == i->second)
            break;
    }
    if(i == iv_lits.end())
    {
        iv_lits.push_back(LIT_DATA(i_data,byte_size));
    }
    //printf("Symbols::find_numeric_lit: i_data:0x%llX byte_size:%d Tag:0x%X\n",
    //      i_data,byte_size, offset | Rpn::NUMBER);
    return offset | Rpn::ARRAY_INDEX;
}

// ------------------------------------------------------------------------------------------------

uint16_t Symbols::get_numeric_tag(uint32_t i_rpn_id)
{
    uint32_t tag = NOT_FOUND;
    uint32_t offset = i_rpn_id - Rpn::NUMBER;
    string any("ANY");
    if(iv_used_lit.size() == 0) get_tag(use_symbol(any));
    if(offset < iv_lits.size())
    {
        // numeric lits are numbered after enum lits, but with different TYPE
        tag = (iv_used_lit.size() + offset) | NUM_TYPE;
    }
    else
    {
        ostringstream err;
        err << hex;
        err << "ERROR! - Symbols::get_numeric_tag() invalid arg rpn_id = " << i_rpn_id << endl;
        throw invalid_argument(err.str());
    }
    return  (uint16_t)tag;
}

// ------------------------------------------------------------------------------------------------

uint16_t Symbols::get_numeric_array_tag(uint32_t i_rpn_id)
{
    uint32_t tag = NOT_FOUND;
    uint32_t offset = i_rpn_id - Rpn::ARRAY_INDEX;
    string any("ANY");
    if(iv_used_lit.size() == 0) get_tag(use_symbol(any));
    if(offset < iv_lits.size())
    {
        // numeric lits are numbered after enum lits, but with different TYPE
        tag = (iv_used_lit.size() + offset) | NUM_TYPE;
    }
    else
    {
        ostringstream err;
        err << hex;
        err << "ERROR! - Symbols::get_numeric_array_tag() invalid arg rpn_id = " << i_rpn_id << endl;
        throw invalid_argument(err.str());
    }
    return  (uint16_t)tag;
}

// ------------------------------------------------------------------------------------------------

uint64_t Symbols::get_numeric_data(uint32_t i_rpn_id, uint32_t & o_size)
{
    uint64_t data = 0;
    o_size = 0;
    uint32_t offset = i_rpn_id - Rpn::NUMBER;
    if(offset < iv_lits.size())
    {
        LIT_DATA d = iv_lits[offset];
        data = d.first;
        o_size = d.second;
    }
    else
    {
        ostringstream err;
        err << hex;
        err << "ERROR! - Symbols::get_numeric_data() invalid arg rpn_id = " << i_rpn_id << endl;
        throw invalid_argument(err.str());
    }
    return data;
}

// ------------------------------------------------------------------------------------------------
uint64_t Symbols::get_attr_enum_val(string & i_attr_enum)
{
    return iv_attr_enum[i_attr_enum];
}

// ------------------------------------------------------------------------------------------------

string Symbols::find_text(uint32_t i_cini_id)
{
    string name = "NOT FOUND";
    if(i_cini_id == CINI_LIT_MASK) name = "ANY";
    else if(i_cini_id == SYM_EXPR) name = "EXPR";
    else
    {
        for(SYMBOL_MAP::const_iterator i = iv_symbols.begin(); i != iv_symbols.end(); ++i)
        {
            //printf("SYMBOL:%s\n",i->first.c_str());
            if((i->second).first == i_cini_id)
            {
                name = i->first;
                break;
            }
        }
//        for(RPN_MAP::iterator i = iv_rpn_map.begin(); i != iv_rpn_map.end(); ++i)
//        {
//            if((i->second).second == i_cini_id) 
//            {
//                name = (i->second).first;
//                break;
//            }
//        }
    }
    return name;
}


// ------------------------------------------------------------------------------------------------

uint32_t Symbols::get_spy_id(const string & spyname)
{
    uint32_t id = NOT_FOUND;
    string s = spyname;
    translate_spyname(s);
    SPY_MAP::iterator sm = iv_spymap.find(s);
    if(sm != iv_spymap.end())
    {
        id = sm->second;
    }
    else
    {
        size_t pos = s.find('-');
        if(pos == string::npos) s.insert(0,"SPY_");
        else
        {
            s[pos] = '_';
            s.insert(pos+1,"SPY_");
            s.insert(0,"ENUM_");
        }
        iv_not_found[s] = MAP_DATA(0,0);
        //cerr << "ERROR! Symbols::get_spy_id() Spyname not found " << '[' << s << ']' << endl;
    }
    return id;
}

// ------------------------------------------------------------------------------------------------

uint32_t Symbols::use_enum(const string & enumname)
{
    uint32_t rpn_id = NOT_FOUND;
    string s = enumname;
    translate_spyname(s);
    SPY_MAP::iterator sm = iv_enums.find(s);
    if(sm != iv_enums.end())
    {
        rpn_id = sm->second;
    }
    else
    {
        printf("Error!\n");
        exit(0);
    }
    return rpn_id;
}

// ------------------------------------------------------------------------------------------------

uint32_t Symbols::get_spy_enum_id(uint32_t i_rpn_id, const string & spyname)
{
    //uint32_t id = NOT_FOUND;
    string enumname = get_enum_name(i_rpn_id);
    enumname.append("-");
    enumname.append(spyname);
    return get_spy_id(enumname);
}

// ------------------------------------------------------------------------------------------------

string Symbols::get_enum_name(uint32_t i_rpn_id)
{
    string name("SPY ENUM NOT FOUND");
    for(SPY_MAP::iterator i = iv_enums.begin(); i != iv_enums.end(); ++i)
    {
        if(i->second == i_rpn_id)
        {
            name = i->first;
            break;
        }
    }
    return name;
}

// ------------------------------------------------------------------------------------------------

string Symbols::full_listing()
{
    uint32_t count = 0;
    ostringstream oss;
    oss << hex << setfill('0');

    for(SYMBOL_MAP::iterator i = iv_symbols.begin(); i != iv_symbols.end(); ++i)
    {
        if(i->second.first < CINI_LIT_MASK) //VAR
        {
            ++count;
            oss << "0x" << setw(8) << i->second.first << '\t'
                << '[' << i->first << ']' << endl;
        }
    }

    ostringstream title;
    title << "\n--------------- Attribute Symbol Table ---------------\n\n"
          << "0x" << hex << setfill('0') << setw(8) << count << '\t' 
          << "Number of variables\n" << oss.str();

    oss.str("");
    count = 0;

    for(SYMBOL_MAP::iterator i = iv_symbols.begin(); i != iv_symbols.end(); ++i)
    {
        if((i->second.first & CINI_LIT_MASK) == CINI_LIT_MASK) //LIT
        {
            ++count;
            oss << "0x" << setw(8) << i->second.first << '\t'
                << '[' << i->first << ']' << endl;
        }
    }

    title << "\n--------------- Literal Symbol Table -----------------\n\n"
        << setw(8) << count << '\t' << "Number of enumerated literals\n"
        << oss.str();
    
    oss.str("");
    title << "\n-------------------- Spies and arrays ----------------------\n\n"
          << "0x" << setw(8) << iv_spymap.size() << '\t' << "Number of spies and array symbols\n";

    for(SPY_MAP::iterator i = iv_spymap.begin(); i != iv_spymap.end(); ++i)
    {
        oss << "0x" << setw(8) << i->second << '\t' << '[' << i->first << ']' << endl;
    }

    title << oss.str();

    return title.str();
}

// ------------------------------------------------------------------------------------------------

string Symbols::listing()
{
    uint32_t count = 0;
    ostringstream oss;

    // Set up tag table if not already setup
    string any = "ANY";
    get_tag(use_symbol(any));

    oss << hex << setfill('0');

    oss << "\n--------------- Attribute Symbol Table ---------------\n\n"
        << "0x" << setw(4) << iv_used_var.size()-1 << '\t' << "Number of variables\n";

    for(SYMBOL_USED::iterator i = iv_used_var.begin() + 1; i != iv_used_var.end(); ++i)
    {
        ++count;
        oss << "Type:" << setw(2) << iv_attr_type[find_text(*i)] << " Value:0x" << setw(8) << (*i) << '\t' << "ID 0X" << setw(4) << (count | VAR_TYPE)
            << '\t' << '[' << find_text(*i) << ']' << endl;

        //printf("ATTRIBUTE: %s  Value:0x%02X\n",(find_text(*i)).c_str(),iv_attr_type[find_text(*i)]);
    }

    count = 0;

    oss << "\n--------------- Literal Symbol Table -----------------\n\n";

    oss << "\n0x" << setw(4) << iv_lits.size() << '\t' << "Number of numeric literals\n";

    count = 0;
    for(LIT_LIST::iterator i = iv_lits.begin(); i != iv_lits.end(); ++i,++count)
    {
        oss << "0x" << setw(2) << i->second << endl
            << "0x" << setw(2 * i->second) << i->first;
        if(i->second < 6)        oss << "\t\t";
        else                    oss<< '\t';
        oss << "ID 0x" << setw(4) << get_numeric_tag(count | Rpn::NUMBER) << endl;
    }

    oss << not_found_listing();

    return oss.str();
}

// ------------------------------------------------------------------------------------------------

string Symbols::not_found_listing()
{
    ostringstream oss;
    if(iv_not_found.size())
    {
        oss << "\n------------- Symbols requested that were NOT FOUND ---------------\n\n";
        for(SYMBOL_MAP::iterator i = iv_not_found.begin(); i != iv_not_found.end(); ++i)
        {
            //if(i->first == "SPY_NOTFOUND" || (i->first).compare(0,13,"ENUM_NOTFOUND") == 0) continue;
            oss << '[' << i->first << ']' << endl;
        }
    }
    return oss.str();
}

// ------------------------------------------------------------------------------------------------

uint32_t Symbols::bin_vars(BINSEQ & blist)
{
    // Set up tag table if not already setup
    string any = "ANY";
    get_tag(use_symbol(any));

    uint32_t count = iv_used_var.size() - 1; // first VAR is 'EXPR' and is not stored

    Rpn::set16(blist,(uint16_t)count);

    for(SYMBOL_USED::iterator i = iv_used_var.begin() + 1; i != iv_used_var.end(); ++i)
    {
        // Write out the attribute type (i.e. uint8_t, uint16_t, ...) and it's index number
        Rpn::set8(blist,iv_attr_type[find_text(*i)]);
        Rpn::set32(blist,(*i));
        //printf("Symbols::bin_vars: Just wrote out type:%u value:%u\n",iv_attr_type[find_text(*i)],*i);
    }
    return count;
}

//-------------------------------------------------------------------------------------------------

uint32_t Symbols::bin_lits(BINSEQ & blist)
{
    // Set up tag table if not already setup
    string any = "ANY";
    get_tag(use_symbol(any));

    uint32_t count = iv_lits.size();
    uint32_t total = count;

    Rpn::set16(blist,(uint16_t)count);

    for(LIT_LIST::iterator i = iv_lits.begin(); i != iv_lits.end(); ++i)
    {
        uint32_t size = i->second;
        uint64_t data = i->first;
        blist.push_back( (uint8_t)size );
        uint32_t shift_count = size * 8;
        while(shift_count)
        {
            shift_count -= 8;
            blist.push_back( (uint8_t)(data >> shift_count) );
        }
    }
    total += count;

    return total;
}

//-------------------------------------------------------------------------------------------------

uint32_t Symbols::restore_var_bseq(BINSEQ::const_iterator & bli)
{
    uint32_t count = Rpn::extract16(bli);

    iv_used_var.clear();
    iv_used_var.push_back(iv_rpn_map[Rpn::SYMBOL|INIT_EXPR_VAR].second); // EXPR var always first

    for(uint32_t i = 0; i < count; ++i)
    {
        uint8_t type = Rpn::extract8(bli);
        uint32_t attribute = Rpn::extract32(bli);
        iv_attr_type[find_text(attribute)] = type;
        iv_used_var.push_back(attribute);
    }
    return count;
}

//-------------------------------------------------------------------------------------------------

uint32_t Symbols::restore_lit_bseq(BINSEQ::const_iterator & bli)
{
    iv_used_lit.clear();
    iv_used_lit.push_back(iv_rpn_map[Rpn::SYMBOL|INIT_ANY_LIT].second);  // ANY lit always first

    iv_lits.clear();
    uint32_t num_count = Rpn::extract16(bli);

    for(uint32_t i = 0; i < num_count; ++i)
    {
        uint8_t size = *bli++;
        uint64_t data = 0;
        switch (size)
        {
            case 1: data = *bli++;  break;
            case 2: data = Rpn::extract16(bli); break;
            case 4: data = Rpn::extract32(bli); break;
            case 8: data = Rpn::extract64(bli); break;
            default:
                    {
                        ostringstream errs;
                        errs << "ERROR! Symbols::restore_var_bseq().  Invalid literal data size ["
                            << size << ']' << endl;
                        throw invalid_argument(errs.str());
                    }
                    break;
        }

        iv_lits.push_back( LIT_DATA(data, size) );
    }

    return num_count;
}

//-------------------------------------------------------------------------------------------------

string Symbols::get_spyname(uint32_t spy_id)
{
    string name;

    for(SPY_MAP::const_iterator i = iv_spymap.begin(); i != iv_spymap.end(); ++i)
    {
        if (i->second == spy_id) 
        {
            name = i->first;
            break;
        }
    }
    if(name.length() == 0)
    {
        ostringstream oss;
        oss << hex << setfill('0');
        oss << "[0x" << setw(8) << spy_id << ']';
        name = oss.str();
    }
    return name;
}
//-------------------------------------------------------------------------------------------------

string Symbols::get_enumname(uint32_t spy_id)
{
    string name = get_spyname(spy_id);
    size_t pos = name.find('-');
    if(pos != string::npos)
    {
        name = name.substr(0,pos);
    }
    return name;
}

//-------------------------------------------------------------------------------------------------

uint32_t Symbols::get_rpn_id(uint32_t bin_tag)
{
    uint32_t rpn_id = NOT_FOUND;
    uint32_t type = bin_tag & TYPE_MASK;
    uint32_t offset = bin_tag & ~TYPE_MASK;
    uint32_t cini_id = 0;
    switch(type)
    {
        case LIT_TYPE:  {
                            cini_id = iv_used_lit[offset];
                            string name = find_text(cini_id);
                            rpn_id = use_symbol(name);
                        }
                        break;

        case VAR_TYPE:  {
                            cini_id = iv_used_var[offset];
                            string name = find_text(cini_id);
                            rpn_id = use_symbol(name);
                        }
                        break;

        case NUM_TYPE:  {
                            offset -= iv_used_lit.size();
                            if(offset >= iv_lits.size())
                            {
                                ostringstream erros;
                                erros << hex;
                                erros << "ERROR! Symbols::get_rpn_id() Invalid NUM_TYPE 0x" 
                                    << bin_tag;
                                throw range_error(erros.str());
                            }
                            LIT_DATA d = iv_lits[offset];
                            rpn_id = find_numeric_lit(d.first,d.second);
                        }
                        break;
        default:
                        {
                            ostringstream erros;
                            erros << hex
                                  << "ERROR! Symbols::get_rpn_id()  Invalid bin_tag = 0x" 
                                  << bin_tag << endl;
                            throw range_error(erros.str());
                        }
                        break;
    }
    return rpn_id;
}
//-------------------------------------------------------------------------------------------------

string Symbols::spies_are_in(Symbols & i_full_list, const set<string> & i_ignore_spies)
{
    ostringstream result;
    result << hex;

    for(SPY_MAP::iterator i = iv_spymap.begin(); i != iv_spymap.end(); ++i)
    {
        // enums in the reduced file will soon no longer contain the spyname as part of the enum name <enum name>-<spy name>
        // At that time we will just need to check the enum part of the name  <enum name> in both the ignore file and the full list
        //  When initfile processing AND spyhunter both use only enum names for enum spies then we can simplify all this
        string spyname = i->first;
        size_t pos = spyname.find('-');  // check for enum - if so just use the spy part of the name
        if(pos != string::npos)
        {
            spyname = spyname.substr(pos+1);
        }

        if(i_ignore_spies.find(spyname) != i_ignore_spies.end()) //don't check this spy or any of it's enums
        {
            cout << "Will not check spy: " << i->first << endl;
            continue;
        }

        uint32_t hash = 0;
        if(pos != string::npos)  // old enum style name - check by hash - only check enumname
        {
            // just compare enum names based on hash
            string enumname1 = (i->first).substr(0,pos);
            string enumname2 = i_full_list.get_enumname(i->second);
            if(enumname1 != enumname2)
            {
                result << "ERROR! Enum not found for spy " << i->first << '\n'
                       << "       Enum: " << enumname1 << "!=" << enumname2 << endl;
            }
        }
        else   // check spyname by name or new-style enum by name
        {
            hash = i_full_list.get_spy_id(i->first);
            if(hash != NOT_FOUND)
            {
                if(hash != i->second)
                {
                    result << "ERROR! HASH not the same for spy " 
                        << i->first << ' ' << hash << ' ' << i->second << endl;
                }
                // else cout << "Found " << i->first << ' ' << i->second << endl;
            }
        }
    }
    result << i_full_list.not_found_listing();
    

    return result.str();
}





