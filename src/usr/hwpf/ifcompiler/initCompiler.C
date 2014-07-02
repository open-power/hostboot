/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/ifcompiler/initCompiler.C $                      */
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
//  Flag   Track    Userid   Date     Description                
//  ----- -------- -------- -------- -------------------------------------------------------------
//         D754106 dgilbert 06/14/10 Create
//  dg002 SW039868 dgilbert 10/15/10 Add support to filter unneeded inits by EC
//  dg003  D779902 dgilbert 12/08/10 Add ability to specify ouput if file
//                 andrewg  05/24/11 Port over for VPL/PgP
//                 andrewg  09/19/11 Updates based on review
//                 mjjones  11/17/11 Output attribute listing
//                 camvanng 04/12/12 Ability to specify search paths for include files
//                 camvanng 06/27/12 Improve error and debug tracing
// End Change Log *********************************************************************************

/**
 * @file initCompiler.C
 * @brief Compile an initfile into bytecode.
 */
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <stdexcept>
#include <initCompiler.H>
#include <initRpn.H>
#include <initSymbols.H>
#include <initScom.H>
//#include <initSpy.H>

using namespace init;
using namespace std;

//Globals

int yyline = 1;
init::ScomList * yyscomlist = NULL;
vector<string> yyincludepath;  //path to search for include files
vector<string> yyfname;        //list of initfile/define files being parsed
string dbg_fname;              //file to dump dbg stringstream

ostringstream init::dbg;
ostringstream init::erros;
ostringstream init::stats;   // TODO move to Parser

// Main
int main(int narg, char ** argv)
{
    int rc = 0;

#if 0
    yyin = fopen("sample.initfile","r");
    if(!yyin)
    {
        std::cerr << "\nERROR: Failed to open sample.initfile! " << std::endl;
        exit(-1);
    }
    yyparse();
    fclose(yyin);
#endif

    try
    {
        // Parser: 
        //   - Parse args
        //   - Set up source location and source type
        //   - Load & parse Symbols & Spy/Array tables
        //   - Load & parse the initfile (if there is one)
        //
        Parser parsed(narg,argv);

        string initfile = parsed.source_fn();
        uint32_t type = parsed.get_source_type();

        BINSEQ bin_seq;
        bin_seq.reserve(0x38000);

        if(type == Parser::IF_TYPE)  // input is binary *.if file - build listing from it.
        {

            //for(SPY_LIST::iterator i = yyspylist->begin(); i != yyspylist->end(); ++i)
            //{
            //    cout << (*i)->listing() << endl;
            //}

            ifstream ifs(initfile.c_str(), ios_base::in | ios_base::binary);
            if(!ifs)
            {
                std::ostringstream msg;
                msg << "initCompiler.C: main: Could not open " << initfile << endl;
                throw invalid_argument(msg.str());
            }
            while(1)
            {
                int ch = ifs.get();
                if (!(ifs.good())) break;
                bin_seq.push_back(ch);
            }
            ifs.close();

            yyscomlist->listing(bin_seq, cout);

            erros << yyscomlist->get_symbols()->not_found_listing();

        }
        else // normal initfile processing
        {
            // Already parsed
            yyscomlist->compile(bin_seq);


            std::cerr << "Compiled size = " << std::dec << bin_seq.size() << endl;

            // if there are missing symbols, SpyList::listing() will add duplicates
            // So get the listing now
            erros << yyscomlist->get_symbols()->not_found_listing();

            string if_fn = parsed.binseq_fn();
            ofstream ofs(if_fn.c_str(), ios_base::out | ios_base::binary);
            if(!ofs)
            {
                std::ostringstream msg;
                msg << "initCompiler.C: main: Could not open " << if_fn << endl;
                throw invalid_argument(msg.str());
            }
            else
            {
                for(BINSEQ::const_iterator bli = bin_seq.begin(); bli != bin_seq.end(); ++bli)
                    ofs.put((char)(*bli));

                ofs.close();
            }
            //cout << dbg << std::endl;
            printf("Generate Listing\n");
            yyscomlist->listing(bin_seq, parsed.listing_ostream());
            yyscomlist->attr_listing(bin_seq, parsed.attr_listing_ostream());

            // open if file and read in to new SpyList
            
            printf("Generate Stats\n");
            stats << "*********************************************************\n";

            cerr << stats.str() << endl;  // TODO -> cout

        }

        if (parsed.debug_mode())
        {
            printf("Generate Debug\n");
            capture_dbg(dbg_fname);
        }
        //if(parsed.debug_mode()) cout << dbg.str() << endl;
    }
    catch(exception & e)
    {
        //Dump dbg stringstream to file
        capture_dbg(dbg_fname);

        //Dump current stats
        stats << "*********************************************************\n";
        cerr << stats.str() << endl;

        cerr << "ERROR! exception caught: " << e.what() << endl;
        rc = 2;
    }

    if(erros.str().size())
    {
        rc = 1;
        cerr << erros.str() << endl;
    }
    return rc;
}

// ------------------------------------------------------------------------------------------------
//  Parser:
//    Check the args and build the symbol table
//  -----------------------------------------------------------------------------------------------

Parser::Parser(int narg, char ** argv)
: iv_type(0), iv_scomlist(NULL), iv_dbg(false), iv_ec(0xFFFFFFFF)   //dg002c
{
    set<string> header_files;
    iv_prog_name = argv[0];

    stats << iv_prog_name << endl;
    --narg; ++argv;

    string type;

    pair<string,string> compare;

    for(int i = 0; i < narg; ++i)
    {
        string arg(argv[i]);
        if(arg.compare(0,5,"-init") == 0)  iv_source_path = argv[++i];
        else if (arg.compare(0,3,"-kw") == 0 ||
                 arg.compare(0,4,"-spy") == 0 ||
                 arg.compare(0,5,"-attr") == 0 || 
                 arg.compare(0,6,"-array") == 0 ) header_files.insert(string(argv[++i]));
        else if (arg.compare(0,7,"-outdir") == 0) iv_outdir = argv[++i];
        else if (arg.compare(0,2,"-o") == 0)      iv_outfile = argv[++i];              //dg003a
        else if (arg.compare(0,3,"-if") == 0)     iv_source_path = argv[++i];
        else if (arg.compare(0,3,"-ec") == 0)     iv_ec = strtoul(argv[++i],NULL,16);  //dg002a
        else if (arg.compare(0,2, "-I") == 0) yyincludepath.push_back(argv[++i]);
        else if (arg.compare(0,9,"--compare") == 0)
        {
            compare.first = argv[++i];
            compare.second = argv[++i];
        }
        else if (arg.compare(0,7,"--debug") == 0) iv_dbg = true;

    }
    if(iv_source_path.size() == 0)
    {
        iv_source_path = compare.first;
    }
    else
    {
        yyfname.push_back(iv_source_path);
    }

    if(!narg) // TEST MODE
    {
        iv_source_path = "p7.initfile";
        header_files.insert("p7_init_spies.h");
        header_files.insert("p7_init_arrays.h");
        header_files.insert("ciniIfSymbols.H");
    }

    size_t pos = iv_source_path.rfind('.');
    if(pos != string::npos)
    {
        string type = iv_source_path.substr(pos+1);
        if(type.compare(0,2,"if") == 0) iv_type = IF_TYPE;
        else if(type.compare(0,8,"initfile") == 0) iv_type = INITFILE_TYPE;

        size_t pos1 = iv_source_path.rfind('/',pos);
        if(pos1 == string::npos) pos1 = 0;
        else ++pos1;

        iv_initfile = iv_source_path.substr(pos1,pos-pos1);
    }

    if(iv_outdir.length() == 0) iv_outdir.push_back('.');
    if(iv_outdir.at(iv_outdir.size()-1) != '/') iv_outdir.push_back('/');

    if(iv_outfile.size() == 0) 
    {
        iv_outfile.append(iv_initfile);
        iv_outfile.append(".if");
    }

    iv_outfile.insert(0,iv_outdir);

    dbg_fname = dbg_fn();

    stats << "*********************************************************" << endl;
    stats << "* source:  " << iv_source_path << endl;
    stats << "* listing: " << listing_fn() << endl;
    stats << "* attr: " << attr_listing_fn() << endl;
    stats << "* binary:  " << binseq_fn() << endl;

    if (yyincludepath.size())
    {
        stats << "* search paths for include files:" << endl;
        for (size_t i = 0; i < yyincludepath.size(); i++)
        {
            stats << "*   " << yyincludepath.at(i) << endl;
        }
        stats << "*" << endl;
    }
            
    iv_scomlist = new ScomList(iv_source_path, header_files, stats, iv_ec);   //dg002c
    if(compare.second.size())
    {
        ScomList cmplist(compare.second, header_files, stats, iv_ec);  //dg002c
        if(iv_scomlist->compare(cmplist))
        {
            cout << "Compare SUCCESS" << endl;
        }
        else
        {
            cout << stats;
        }
    }

    iv_list_ostream.open(listing_fn().c_str());
    if(!iv_list_ostream)
    {
        std::ostringstream msg;
        msg << "initCompiler.C: Parser: Could not open " << listing_fn() << endl;
        throw invalid_argument(msg.str());
    }

    iv_attr_list_ostream.open(attr_listing_fn().c_str());
    if(!iv_attr_list_ostream)
    {
        std::ostringstream msg;
        msg << "initCompiler.C: Parser: Could not open " << attr_listing_fn() << endl;
        throw invalid_argument(msg.str());
    }
}

Parser::~Parser()
{
    iv_list_ostream.close();
    iv_attr_list_ostream.close();
}

void init::capture_dbg(string i_fname)
{
    ofstream dbgfs(i_fname.c_str());
    if(!dbgfs)
    {
        std::ostringstream msg;
        msg << "initCompiler.C: capture_dbg: Could not open " << i_fname << endl;
        throw invalid_argument(msg.str());
    }
    dbgfs << dbg.str() << endl;
    dbgfs.close();
}

// TODO
//  - Detect all errors down to a line # ?
//  - bad rows/cols check - have already?
//
