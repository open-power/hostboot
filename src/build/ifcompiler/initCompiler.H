// IBM_PROLOG_BEGIN_TAG
// This is an automatically generated prolog.
//
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/ifcompiler/initCompiler.H,v $
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
// End Change Log *********************************************************************************

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

namespace init
{


    extern ostringstream dbg;    // debug (verbose) output
    extern ostringstream erros;  // error output stream
    extern ostringstream stats;  // Misc info to be displayed



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
            string source_fn()  { return iv_source_path; }
            string binseq_fn()  { return iv_outfile; }  //dg003a
            //{ string s(iv_outdir); s.append(iv_initfile); s.append(".if"); return s; } //dg003d
            uint32_t get_source_type() { return iv_type; }

            ostream & listing_ostream() { return iv_list_ostream; }

            ScomList * get_scomlist() { return iv_scomlist; }  // TODO refactor this out
            bool debug_mode() { return iv_dbg; }

            void capture_dbg();  // if iv_dbg then dump the dbg stringstream to a file

        private:
            string iv_prog_name;
            string iv_source_path;
            string iv_initfile;
            string iv_outdir;
            string iv_outfile;    //dg003a
            ofstream iv_list_ostream;
            uint32_t iv_type;
            ScomList * iv_scomlist;
            bool iv_dbg;
            uint32_t iv_ec;             // ec filter (if there is one) dg002a

    };
}

#endif
