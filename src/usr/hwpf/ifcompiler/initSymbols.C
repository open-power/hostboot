/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/ifcompiler/initSymbols.C $                       */
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
// Change Log *************************************************************************************
//                                                                      
//  Flag Track     Userid   Date     Description                
//  ---- --------  -------- -------- -------------------------------------------------------------
//       D754106   dgilbert 06/14/10 Create
//                 dgilbert 10/22/10 Add spies_are_in()
//                 andrewg  09/19/11 Updates based on review
//                 camvanng 11/08/11 Added support for attribute enums
//                 andrewg  11/09/11 Multi-dimensional array and move to common fapi include
//                 mjjones  11/17/11 Output attribute listing
//                 camvanng 11/17/11 Support for system & target attributes
//                 camvanng 01/07/12 Support for writing an attribute to a SCOM register
//                 camvanng 04/10/12 Support fixed attribute enum value
//                 camvanng 04/16/12 Support defines for SCOM address
//                                   Support defines for bits, scom_data and attribute columns
//                                   Delete obsolete code for defines support
//                 camvanng 05/07/12 Support for associated target attributes
//                 camvanng 06/27/12 Improve error and debug tracing
//                                   Add get_numeric_array_data()
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
const string SYS_ATTR = "SYS.";

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
            errss << "ERROR! Symbols::Symbols: Could not open "
                  << *fn << endl;
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

                    while(fileline[0] != '}')
                    {
                        istringstream attr_stream(fileline);
                        string attr;
                        char tempChar = 0;
                        uint32_t attrId = 0;

                        // Read the attribute name
                        attr_stream >> attr;

                        // Read and ignore the '=' '0' 'x' characters
                        attr_stream >> tempChar;
                        attr_stream >> tempChar;
                        attr_stream >> tempChar;

                        // Read the attribute ID
                        attr_stream >> hex >> attrId;

                        // Store the value
                        iv_symbols[attr] = MAP_DATA(attrId,NOT_USED);

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
                                        value = strtoull(tmp.c_str(), NULL, 0);
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
                 uint32_t array = 0;
                 iss >> type;
                 iss >> attribute_name;
                 if(attribute_name == "*")
                 {
                     // It's a pointer type so read in the next string
                     iss >> attribute_name;
                     type = type + "*";
                 }
                 //printf("typedef: type:%s  attribute_name:%s\n",type.c_str(),attribute_name.c_str());

                 // Determine how many (if any) dimensions this array has
                 size_t pos = attribute_name.find(find_array);
                 while(pos != string::npos)
                 {
                     array++;
                     pos = attribute_name.find(find_array,pos+1);
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
                 //printf("Attribute %s Type  with array dimension %u for %s is %u\n",attribute_name.c_str(),array,
                 //       type.c_str(),get_attr_type(type,array));
            }
        }
        infs.close();
    }
    iv_rpn_map[Rpn::SYMBOL | INIT_EXPR_VAR] = RPN_DATA("EXPR",SYM_EXPR);
    iv_rpn_map[Rpn::SYMBOL | INIT_ANY_LIT]  = RPN_DATA("ANY",CINI_LIT_MASK);
}

uint32_t Symbols::get_attr_type(const string &i_type, const uint32_t i_array)
{
    uint32_t l_type = 0;

    if (i_type == "uint8_t")
    {
        l_type = SYM_ATTR_UINT8_TYPE;
    }
    else if(i_type == "uint32_t")
    {
        l_type = SYM_ATTR_UINT32_TYPE;   
    }
    else if(i_type == "uint64_t")
    {
        l_type = SYM_ATTR_UINT64_TYPE;
    }
    else
    {
        printf("Unknown data type: %s\n",i_type.c_str());
        exit(-1);
    }

    if(i_array > MAX_ATTRIBUTE_ARRAY_DIMENSION)
    {
        printf("Array dimension size for %s %u exceeded maximum dimension of %u\n",
               i_type.c_str(),i_array,MAX_ATTRIBUTE_ARRAY_DIMENSION);
        exit(-1);
    }
    // See enum definition on why this works
    l_type += (i_array*ATTR_DIMENSION_SIZE_MULT)+i_array;

    return(l_type);
}

uint32_t Symbols::get_attr_type(const uint32_t i_rpn_id)
{
    string l_attr_name = find_name(i_rpn_id);
    return(iv_attr_type[l_attr_name]);
}

// ------------------------------------------------------------------------------------------------

uint32_t Symbols::use_symbol(string & i_symbol)
{
    uint32_t rpn_id = Rpn::SYMBOL | NOT_FOUND;
    string l_symbol = i_symbol;

    if(i_symbol == "ANY") rpn_id = INIT_ANY_LIT | Rpn::SYMBOL;
    else if(i_symbol == "EXPR") rpn_id = INIT_EXPR_VAR | Rpn::SYMBOL;
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
            //Strip off any prefix (i.e. "SYS." or "TGT<#>.")
            size_t pos = i_symbol.find('.');
            if(pos != string::npos)
            {
                //Find the attribute without the prefix.
                //If found, then add this system or assoc target attribute
                //to our containers.
                l_symbol = i_symbol.substr(pos+1);
                SYMBOL_MAP::iterator i = iv_symbols.find(l_symbol);
                if(i != iv_symbols.end())
                {
                    //Add the new attribute

                    rpn_id = Rpn::SYMBOL | iv_rpn_id++;
                    uint32_t attrId = iv_symbols[l_symbol].first;

                    iv_rpn_map[rpn_id] = RPN_DATA(i_symbol,attrId);
                    iv_symbols[i_symbol] = MAP_DATA(attrId, rpn_id);
                    iv_attr_type[i_symbol] = iv_attr_type[l_symbol];

                    ++iv_used_var_count;

                    //printf ("Symbols::use_symbol: Just added %s symbol, rpn_id:0x%8X\n",i_symbol.c_str(),rpn_id);
                }
                else
                {
                    rpn_id = add_undefined(i_symbol);
                }
            }
            else
            {
                rpn_id = add_undefined(i_symbol);
            }
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

    // Set up tag table if not already setup
    if(iv_used_var.size() == 0)
    {
        iv_used_var.reserve(iv_used_var_count); // makes if faster
        iv_used_lit.reserve(iv_used_lit_count);

        //To differentiate between system, target, and associated target attributes
        //which have the same attribute id, save the attribute name also.
        iv_used_var.push_back(RPN_DATA("EXPR",SYM_EXPR));                    // EXPR var always first
        iv_used_lit.push_back(iv_rpn_map[Rpn::SYMBOL|INIT_ANY_LIT].second);  // ANY lit always first

        for(SYMBOL_MAP::iterator i = iv_symbols.begin(); i != iv_symbols.end(); ++i)
        {
            if(i->second.second != NOT_USED)
            {
                //printf("Symbols::get_tag adding rpn_id[0x%x]\n", i->second.second);

                if((i->second.first & CINI_LIT_MASK) ==  CINI_LIT_MASK)
                {
                    iv_used_lit.push_back(i->second.first);
                    //printf("Symbols::get_tag added to iv_used_lit[0x%x]\n", iv_used_lit.back());
                }
                else  //VAR
                {
                    iv_used_var.push_back(RPN_DATA(i->first, i->second.first));
                    //printf("Symbols::get_tag added to iv_used_var[%s, 0x%x]\n",
                    //       iv_used_var.back().first.c_str(), iv_used_var.back().second);
                }
            }
        }
    }

    do
    {
        string name = find_name(i_rpn_id);
        if ("NOT_FOUND" == name)
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

        uint32_t offset = 0;
        for(VAR_SYMBOL_USED::iterator i = iv_used_var.begin(); i != iv_used_var.end(); ++i,++offset)
        {
            if (name == (*i).first)
            {
                if (name.compare(0, ASSOC_TGT_ATTR.length(), ASSOC_TGT_ATTR) == 0)
                {
                    tag = (uint16_t) (offset | IF_ASSOC_TGT_ATTR_TYPE);
                }
                else if (name.compare(0, SYS_ATTR.length(), SYS_ATTR) == 0)
                {
                    tag = (uint16_t) (offset | IF_SYS_ATTR_TYPE);
                }
                else
                {
                    tag = (uint16_t) (offset | IF_ATTR_TYPE);
                }

                //printf ("get tag: %s tag 0x%x\n", name.c_str(), tag);
                break;
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
        tag = (iv_used_lit.size() + offset) | IF_NUM_TYPE;
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
        tag = (iv_used_lit.size() + offset) | IF_NUM_TYPE;
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

uint64_t Symbols::get_numeric_array_data(uint32_t i_rpn_id, uint32_t & o_size)
{
    uint64_t data = 0;
    o_size = 0;
    uint32_t offset = i_rpn_id - Rpn::ARRAY_INDEX;
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
        err << "ERROR! - Symbols::get_numeric_array_data() invalid arg rpn_id = " << i_rpn_id << endl;
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
        //NOTE:  if there are multiple elements of the same cini_id, then this function will return the
        //first element found
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

    for(VAR_SYMBOL_USED::iterator i = iv_used_var.begin() + 1; i != iv_used_var.end(); ++i)
    {
        ++count;
        uint32_t id = count;

        string name = (*i).first;
        uint32_t attrId = (*i).second;
        if(name.compare(0, ASSOC_TGT_ATTR.length(), ASSOC_TGT_ATTR) == 0)
        {
            id |= IF_ASSOC_TGT_ATTR_TYPE;
        }
        else if(name.compare(0, SYS_ATTR.length(), SYS_ATTR) == 0)
        {
            id |= IF_SYS_ATTR_TYPE;
        }
        else
        {
            id |= IF_ATTR_TYPE;
        }

        oss << "Type:" << setw(2) << iv_attr_type[name] << " Value:0x" << setw(8) << attrId << '\t' << "ID 0X" << setw(4) << id
            << '\t' << '[' << name << ']' << endl;

        //printf("ATTRIBUTE: %s  Value:0x%02X\n",name,iv_attr_type[name]);
    }

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

string Symbols::attr_listing()
{
    ostringstream oss;

    // Set up tag table if not already setup
    string any = "ANY";
    get_tag(use_symbol(any));

    for(VAR_SYMBOL_USED::iterator i = iv_used_var.begin() + 1; i != iv_used_var.end(); ++i)
    {
        string name = (*i).first;

        //Strip off any prefix (i.e. "SYS." or "TGT<#>.")
        size_t pos = name.find('.');
        if(pos != string::npos)
        {
            name = name.substr(pos+1);
        }

        oss << name << endl;
    }

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

    for(VAR_SYMBOL_USED::iterator i = iv_used_var.begin() + 1; i != iv_used_var.end(); ++i)
    {
        // Write out the attribute type (i.e. uint8_t, uint16_t, ...) and it's attribute id number

        string name = (*i).first;
        uint32_t attrId = (*i).second;

        Rpn::set8(blist,iv_attr_type[name]);

        Rpn::set32(blist,attrId);
        //printf("Symbols::bin_vars: Just wrote out type:%u attrId:0x%x\n",iv_attr_type[name],attrId);
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

    for(uint32_t i = 0; i < count; ++i)
    {
        uint8_t type = Rpn::extract8(bli);
        uint32_t attrId = Rpn::extract32(bli);

        string name = find_text(attrId);
        string used_var_name = iv_used_var.at(i+1).first;

        // Account for system & associated target attributes
        if (name != used_var_name)
        {
            size_t pos = used_var_name.find(name);
            if(pos != string::npos)
            {
                attrId = iv_symbols[used_var_name].first;

            }
            else
            {
                ostringstream errs;
                errs << "ERROR! Symbols::restore_var_bseq().  Invalid attribute id ["
                    << attrId << ']' << endl;
                throw invalid_argument(errs.str());
            }

        }

        iv_attr_type[used_var_name] = type;
        iv_used_var.at(i+1).second = attrId;
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
                        errs << "ERROR! Symbols::restore_lit_bseq().  Invalid literal data size ["
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
    uint32_t type = bin_tag & IF_TYPE_MASK;
    uint32_t offset = bin_tag & ~IF_TYPE_MASK;
    switch(type)
    {
        case IF_ATTR_TYPE:
        case IF_SYS_ATTR_TYPE:
        case IF_ASSOC_TGT_ATTR_TYPE:
                        {
                            string name = iv_used_var[offset].first;
                            rpn_id = use_symbol(name);
                        }
                        break;

        case IF_NUM_TYPE:  {
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





