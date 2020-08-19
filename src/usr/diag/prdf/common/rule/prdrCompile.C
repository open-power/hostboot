/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/rule/prdrCompile.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#include <map>
#include <list>
#include <vector>
#include <stack>
#include <fstream>

// It is important to limit what is included here. We don't want to include
// files that include external components such as the errl or targeting code.
// Otherwise, we will pull in way too much code just to compile this on file.
#include <attributeenums.H> // For TARGETING::TYPE enum

// define needed to enable x86 rule parser code only
#define __PRD_RULE_COMPILE
#include <prdrCommon.H>
#include <prdrToken.H>
#include <UtilHash.H>
#include <prdfCalloutMap.H> // for enums

using namespace PRDR_COMPILER;

int yyline;
std::stack<std::pair<std::string, int> > yyincfiles;

namespace PRDR_COMPILER
{

Chip * g_currentChip;                                 // the current chip
std::map<std::string, Expr *> g_rules;                // list of rules.
std::map<std::string, Group *> g_groups;              // list of bit groups
std::map<std::string, Group *> g_actionclasses;       // list of actions
std::map<std::string, std::string> g_attentionStartGroup;

// Internal list of references, to make sure every reference resolved.
std::list<std::pair<std::string, std::string> > g_references;

Prdr::HashCollisionMap g_groupHashCollision;
Prdr::HashCollisionMap g_regsHashCollision;

// Used in error reference outputting.
uint32_t g_nextAndBit;
bool g_hadError;

} // end namespace PRDR_COMPILER

//--------------------------------------------
// main
//--------------------------------------------
int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        std::cerr << "No destination file given." << std::endl;
        exit(-1);
    }

    FILE * l_prfFile = fopen(argv[1], "w+");
    if (nullptr == l_prfFile)
    {
        std::cerr << "Error opening file for output." << std::endl;
        exit(-1);
    }

    std::ofstream l_htmlFile((std::string(argv[1]) + ".html").c_str());
    std::ofstream l_htmlDummy(std::string("/dev/null").c_str());
    std::ofstream l_errFile((std::string(argv[1]) + ".err.C").c_str());
    std::ofstream l_dispFile((std::string(argv[1]) + ".disp.C").c_str());
    std::ofstream l_regFile((std::string(argv[1]) + ".reg.C").c_str());

#ifndef __HOSTBOOT_MODULE
    // Get Backing build or sandbox name.
    std::string l_backingBuild(getenv("SANDBOXBASE"));
    l_backingBuild = l_backingBuild.substr(l_backingBuild.find_last_of('/')+1);
#else
    std::string l_backingBuild("HOSTBOOT");
#endif

    // setup HTML headers.
    l_htmlFile << "<HTML><HEAD><STYLE type=\"text/css\">" << std::endl;
    l_htmlFile << "TABLE { border-collapse: collapse; border: solid; "
               << "border-width: 3px; "
               << "margin-left: auto; margin-right: auto; width: 100% }"
               << std::endl;
    l_htmlFile << "TH { border: solid; border-width: thin; padding: 3px }"
               << std::endl;
    l_htmlFile << "TD { border: solid; border-width: thin; padding: 3px }"
               << std::endl;
    l_htmlFile << "</STYLE>" << std::endl;

    // setup error signature file.
    l_errFile << "#include <prdrErrlPluginsSupt.H>" << std::endl;
    l_errFile << "PRDR_ERROR_SIGNATURE_TABLE_START ";

    l_dispFile << "#include <prdrErrlDisplaySupt.H>" << std::endl;
    l_dispFile << "PRDR_ERROR_SIGNATURE_TABLE_START ";

    // setup register id file.
    l_regFile << "#include <prdrErrlPluginsSupt.H>" << std::endl;
    l_regFile << "PRDR_REGISTER_ID_TABLE_START ";

    yyline = 1;  // current line is 1.
    g_currentChip = nullptr; // initialize current chip.

    uint16_t l_size;

    // parse standard input.
    yyparse();

    // verify references.
    prdrCheckReferences();

    // output chip.
    if (nullptr != g_currentChip)
    {
        g_currentChip->output(l_prfFile);
        g_currentChip->outputRegisterFile(l_regFile);
        //g_currentChip->print();
    }
    else
    {
        yyerror("No chip define!");
        exit(1);
    }

    l_htmlFile << "<TITLE> PRD Table: "
               << g_currentChip->cv_name->substr(1,
                        g_currentChip->cv_name->length()-2)
               << "</TITLE>"
               << std::endl;
    l_htmlFile << "</HEAD><BODY>" << std::endl;

    // output rules.
    l_size = htons((uint16_t)g_rules.size());
    PRDR_FWRITE(&l_size, sizeof(l_size), 1, l_prfFile);
    for (std::map<std::string, Expr *>::iterator i = g_rules.begin();
         i != g_rules.end();
         i++)
    {
        (*i).second->output(l_prfFile);
    };

    // set error register HOM_TYPE
    l_errFile << "( 0x" << std::hex << g_currentChip->cv_targetType << ", 0x"
              << std::hex << g_currentChip->cv_signatureOffset
              << " )" << std::endl;

    // set error register HOM_TYPE
    l_dispFile << "( 0x" << std::hex << g_currentChip->cv_targetType << ", 0x"
              << std::hex << g_currentChip->cv_signatureOffset
              << " )" << std::endl;

    // output bit groups
    uint32_t l_pos = 0;
    l_size = htons((uint16_t)g_groups.size());
    PRDR_FWRITE(&l_size, sizeof(l_size), 1, l_prfFile);
    l_size = htons((uint16_t)prdrGetRefId(&g_attentionStartGroup["CHECK_STOP"]));
    PRDR_FWRITE(&l_size, sizeof(l_size), 1, l_prfFile);
    l_size = htons((uint16_t)prdrGetRefId(&g_attentionStartGroup["RECOVERABLE"]));
    PRDR_FWRITE(&l_size, sizeof(l_size), 1, l_prfFile);
    l_size = htons((uint16_t)prdrGetRefId(&g_attentionStartGroup["SPECIAL"]));
    PRDR_FWRITE(&l_size, sizeof(l_size), 1, l_prfFile);
    l_size = htons((uint16_t)prdrGetRefId(&g_attentionStartGroup["UNIT_CS"]));
    PRDR_FWRITE(&l_size, sizeof(l_size), 1, l_prfFile);
    l_size = htons((uint16_t)prdrGetRefId(&g_attentionStartGroup["HOST_ATTN"]));
    PRDR_FWRITE(&l_size, sizeof(l_size), 1, l_prfFile);

    l_htmlFile << "<H2> Register Groups </H2>" << std::endl;
    l_htmlFile << "Generated from " << l_backingBuild << "<BR>" << std::endl;

    for (std::map<std::string, Group *>::iterator i = g_groups.begin();
         i != g_groups.end();
         i++, l_pos++)
    {
        (*i).second->output(l_prfFile);
        (*i).second->generateDoxygen(l_htmlFile, (*i).first, l_errFile);
        (*i).second->generateDoxygen(l_htmlDummy, (*i).first, l_dispFile);
    }

    // output action classes.
    l_size = htons((uint16_t)g_actionclasses.size());
    PRDR_FWRITE(&l_size, sizeof(l_size), 1, l_prfFile);

    l_htmlFile << "<H2> Actions </H2>" << std::endl;
    l_htmlFile << "Generated from " << l_backingBuild << "<BR>" << std::endl;
    l_htmlFile << "<TABLE>" << std::endl;
    l_htmlFile << "<TR><TH> Action Class </TH> "
               << "<TH> Description </TH> "
               << "<TH> Actions </TH></TR>" << std::endl;

    for (std::map<std::string, Group *>::iterator i =
                g_actionclasses.begin();
         i != g_actionclasses.end();
         i++)
    {
        (*i).second->output(l_prfFile);
        (*i).second->generateDoxygen(l_htmlFile, (*i).first);
    }

    l_htmlFile << "</TABLE>" << std::endl;

    fclose(l_prfFile);

    l_htmlFile << "</HTML>";
    l_htmlFile.close();

    // Add chip's extra signatures.
    l_errFile << "//---- Extra Signatures ----" << std::endl;
    l_dispFile << "//---- Extra Signatures ----" << std::endl;
    for (std::list<ExtraSignature>::iterator i
            = g_currentChip->cv_sigExtras.begin();
            i != g_currentChip->cv_sigExtras.end();
            i++)
    {
        l_errFile << "\tPRDR_ERROR_SIGNATURE ( 0x"
            << std::setfill('0') << std::setw(8) << std::hex
            << i->iv_sig << ", " << *(i->iv_sname) << ", "
            << *(i->iv_desc) << ")" << std::endl;

        l_dispFile << "\tPRDR_ERROR_SIGNATURE ( 0x"
            << std::setfill('0') << std::setw(8) << std::hex
            << i->iv_sig << ", " << *(i->iv_sname) << ", "
            << *(i->iv_desc) << ")" << std::endl;
    }

    l_errFile << "PRDR_ERROR_SIGNATURE_TABLE_END" << std::endl;
    l_errFile.close();

    l_dispFile << "PRDR_ERROR_SIGNATURE_TABLE_END" << std::endl;
    l_dispFile.close();

    l_regFile << "PRDR_REGISTER_ID_TABLE_END" << std::endl;
    l_regFile.close();

    return (g_hadError ? -1 : 0);
};

namespace PRDR_COMPILER
{

std::map<std::string, uint32_t> g_refId;
std::map<std::string, char> g_refType;

uint16_t prdrGetRefId(std::string * i_name)
{
    if (nullptr == i_name)
    {
        yyerror("ICE - NPE.");
        return 0;
    }

    uint32_t l_refId = g_refId[*i_name];

    //fprintf(stderr, "%s: %08x\n", i_name->c_str(), l_refId);
    return l_refId;
};

char prdrGetRefType(std::string * i_name)
{
    if (nullptr == i_name)
    {
        yyerror("ICE - NPE.");
        return 0;
    }

    char l_refType = g_refType[*i_name];

    return l_refType;
};

void prdrCheckReferences()
{
    do
    {
        uint32_t l_refId = 1;

        if (nullptr == g_currentChip)
            break;

        for (RegisterList::iterator i = g_currentChip->cv_reglist.begin();
                 i != g_currentChip->cv_reglist.end();
                 i++)
        {
            g_refId[*(*i)->cv_sname] = l_refId++;
            g_refType[*(*i)->cv_sname] = Prdr::REF_REG;
        }

        for (std::map<std::string, Expr *>::iterator i = g_rules.begin();
                i != g_rules.end();
                i++)
        {
            g_refId[(*i).first] = l_refId++;
            g_refType[(*i).first] = Prdr::REF_RULE;
        }

        for (std::map<std::string, Group *>::iterator i = g_groups.begin();
                i != g_groups.end();
                i++)
        {
            g_refId[(*i).first] = l_refId++;
            g_refType[(*i).first] = Prdr::REF_GRP;
        }

        for (std::map<std::string, Group *>::iterator i =
                    g_actionclasses.begin();
                i != g_actionclasses.end();
                i++)
        {
            g_refId[(*i).first] = l_refId++;
            g_refType[(*i).first] = Prdr::REF_ACT;
        }

        for (std::list<std::pair<std::string, std::string> >::iterator i =
                    g_references.begin();
                i != g_references.end();
                i++)
        {
            if (std::string::npos == (*i).first.find(g_refType[(*i).second]))
            {
                if (char() == g_refType[(*i).second])
                {
                    std::string l_tmp = "Undefined reference for ";
                    l_tmp += (*i).second;
                    yyerror(l_tmp.c_str());
                }
                else
                {
                    std::string l_tmp = "Bad reference type: expected ";
                    l_tmp += (*i).first + " but found ";
                    l_tmp += g_refType[(*i).second];
                    l_tmp += " for " + (*i).second;
                    yyerror(l_tmp.c_str());
                }
            }
        }

    } while (false);
    return;
};

std::list<std::string> prdrParseDoxygen(std::string & i_string)
{
    std::list<std::string> l_result;

    std::string l_input = i_string;
    std::string l_tmp;

    for (int i = 0; i < 2; i++) // grab title and short desc.
    {
        std::string::size_type l_pos = l_input.find('\n');
        l_result.push_back(l_input.substr(0, l_pos));
        l_input.erase(0,l_pos+1);
    }
    l_result.push_back(l_input); // push long desc.

    return l_result;
};

uint32_t prdrCaptureGroupMap( const std::string & i_arg )
{
    if ( 0 == i_arg.compare("never") )
    {
        return 0;
    }
    else if ( 0 == i_arg.compare("default") )
    {
        return 1;
    }
    else
    {
        uint16_t hash = PRDF::Util::hashString( i_arg.c_str() );
        Prdr::HashCollisionMap::iterator i = g_groupHashCollision.find(hash);
        if ( g_groupHashCollision.end() != i )
        {
            if ( 0 != i_arg.compare(i->second) )
            {
                g_hadError = true; // Compile error

                std::cerr << "Capture Group hash collision '" << i_arg << "' "
                          << std::hex << "[0x"
                          << std::setfill('0') << std::setw(4)
                          << hash << "]"
                          << ": previous group was '" << i->second << "'"
                          << std::endl;
            }
        }
        g_groupHashCollision[hash] = i_arg;

        return hash;
    }
}

uint32_t prdrCaptureTypeMap(const std::string & i_arg)
{
    if ("primary" == i_arg)
        return 1;
    if ("secondary" == i_arg)
        return 2;
    return 1;
}

} // end namespace PRDR_COMPILER

namespace PRDR_COMPILER
{

std::map<std::string, uint32_t> g_ActionArgMap;

uint32_t prdrActionArgMap(const std::string & i_arg)
{
    using namespace PRDF;
    using namespace std;

    static bool l_initialized = false;

    do
    {
        if (l_initialized)
            break;

        // Include procedure callouts, callout priorities, and target types.
        #define PRDF_RULE_COMPILER_ENUMS
        #undef __prdfCalloutMap_H
        #include <prdfCalloutMap.H> // for string-to-enum map
        #undef PRDF_RULE_COMPILER_ENUMS

        // Initialize SDC Flags.
        // FIXME: RTC 119976
        // Not quite happy with the way this is implemented.
        // Would like to move the macros to another file like we
        // did with prdfCalloutMap.H, but will need to do this later.
        #define PRDF_SDC_FLAGS_MAP_ONLY
        #define PRDF_SDC_FLAGS_MAP
        #define PRDF_SDC_FLAG(name, value) \
                g_ActionArgMap[#name] = value;
        #define PRDF_SDC_FLAGS_MAP_END

        #define PRDF_GARD_POLICY_MAP_ONLY
        #define PRDF_GARD_POLICY_MAP
        #define PRDF_GARD_POLICY(name, value) \
                g_ActionArgMap[#name] = value;
        #define PRDF_GARD_POLICY_MAP_END
        #undef iipServiceDataCollector_h
        #include <iipServiceDataCollector.h>


#ifdef __HOSTBOOT_MODULE
        //Note: Hostboot does not support dump.So,defining dump type here
        //to retain common rule code for hostboot and FSP.
        g_ActionArgMap["DUMP_CONTENT_SW"]           = 0x80000000;
        g_ActionArgMap["DUMP_CONTENT_HW"]           = 0x40000000;
        g_ActionArgMap["DUMP_CONTENT_SH"]           = 0x20000000;
        g_ActionArgMap["DUMP_CONTENT_CORE"]         = 0x10000000;
#else
        // Initialize Dump values. //@ecdf
        #include <hdctContent.H>
        #undef __hdctContent_H__
        #undef HDCT_CONTENT_T
        #undef HDCT_CONTENT_V
        #undef HDCT_CONTENT_T_END
        #define HDCT_CONTENT_T
        #define HDCT_CONTENT_V(name, value) \
                g_ActionArgMap["DUMP_" #name] = value;
        #define HDCT_CONTENT_T_END
        #undef HDCT_COMMAND_T
        #undef HDCT_COMMAND_V
        #undef HDCT_COMMAND_T_END
        #define HDCT_COMMAND_T
        #define HDCT_COMMAND_V(name, value)
        #define HDCT_COMMAND_T_END
        #include <hdctContent.H>

#endif

        // Initialize MFG thresholds.
        #define PRDF_MFGTHRESHOLD_TABLE_BEGIN
        #define PRDF_MFGTHRESHOLD_TABLE_END
        #define PRDF_MFGTHRESHOLD_ENTRY(a,b) \
            g_ActionArgMap[#a] = b;
        #include <prdfMfgThresholdAttrs.H>


        l_initialized = true;

    } while (false);

    if (g_ActionArgMap.end() == g_ActionArgMap.find(i_arg)) //@pw01
    {
        yyerror((std::string("Undefined argument: ")+i_arg).c_str());
    }

    return g_ActionArgMap[i_arg];
}

} // end namespace PRDR_COMPILER

