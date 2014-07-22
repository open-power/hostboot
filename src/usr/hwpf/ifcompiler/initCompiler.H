/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/ifcompiler/initCompiler.H $                      */
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
#if !defined(INITCOMPILER_H)
#define INITCOMPILER_H

// Change Log *************************************************************************************
//                                                                      
//  Flag   Track    Userid   Date     Description                
//  ----- -------- -------- -------- -------------------------------------------------------------
//        D754106  dgilbert 06/14/10 Create
//  dg002 SW039868 dgilbert 10/15/10 Add support to filter unneeded inits by EC
//  dg003 D779902  dgilbert 12/08/10 Ability to specify output if file
//                 andrewg  05/24/11 Port over for VPL/PgP
//                 andrewg  09/19/11 Updates based on review
//                 mjjones  11/17/11 Output attribute listing
//                 camvanng 04/12/12 Ability to specify search paths for include files
//                 camvanng 06/27/12 Improve error and debug tracing
// End Change Log *********************************************************************************
// $Id: initCompiler.H,v 1.4 2014/06/27 20:02:27 thi Exp $
/**
 * @file initCompiler.H
 * @brief Compile an initfile into bytecode.
 */

#include <initRpn.H>
#include <initScom.H>
#include <set>
#include <string>
#include <fstream>

using namespace std;


// bison & flex globals

extern int yyline;
extern FILE * yyin;
extern int yyparse();
void yyerror(const char * s);
extern init::ScomList * yyscomlist;
extern vector<string> yyincludepath;
extern vector<string> yyfname;
extern string dbg_fname;

namespace init
{


    extern ostringstream dbg;    // debug (verbose) output
    extern ostringstream erros;  // error output stream
    extern ostringstream stats;  // Misc info to be displayed

    /**
     * Dump the dbg stringstream to a file
     * @param i_fname file to dump dbg stringstream
     */
    void capture_dbg(string i_fname);



    class Parser
    {
        public:

            enum
            {
                IF_TYPE  = 1,
                INITFILE_TYPE = 2
            };

            Parser(int narg, char ** argv);
            ~Parser();

            string listing_fn() { return (binseq_fn()).append(".list"); }
            string attr_listing_fn() { return (binseq_fn()).append(".attr"); }
            string source_fn()  { return iv_source_path; }
            string binseq_fn()  { return iv_outfile; }  //dg003a
            //{ string s(iv_outdir); s.append(iv_initfile); s.append(".if"); return s; } //dg003d

            // File to dump dbg stringstream
            string dbg_fn() {string fname(iv_outdir); fname += iv_initfile + ".dbg"; return fname; }

            uint32_t get_source_type() { return iv_type; }

            ostream & listing_ostream() { return iv_list_ostream; }
            ostream & attr_listing_ostream() { return iv_attr_list_ostream; }

            bool debug_mode() { return iv_dbg; }

        private:
            string iv_prog_name;
            string iv_source_path;
            string iv_initfile;
            string iv_outdir;
            string iv_outfile;    //dg003a
            ofstream iv_list_ostream;
            ofstream iv_attr_list_ostream;
            uint32_t iv_type;
            ScomList * iv_scomlist;
            bool iv_dbg;
            uint32_t iv_ec;             // ec filter (if there is one) dg002a

    };
}

#endif
