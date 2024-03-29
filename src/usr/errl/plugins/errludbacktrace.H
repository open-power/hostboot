/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errludbacktrace.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
/* [+] International Business Machines Corp.                              */
/* [+] YADRO                                                              */
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
#ifndef ERRL_UDBACKTRACE_H
#define ERRL_UDBACKTRACE_H

/**
 *  @file errludbacktrace.H
 *
 *  Defines the ErrlUserDetailsParserBackTrace class that parses backtrace FFDC
 *  user detail in an error log
 */

#include "errluserdetails.H"
#include "symbols.H"
#include <vector>

namespace ERRORLOG
{

/**
 * @class ErrlUserDetailsParserBackTrace
 *
 * Parses backtrace user detail in an error log
 */
class ErrlUserDetailsParserBackTrace : public ErrlUserDetailsParser
{
public:
    /**
     *  @brief Constructor
     */
    ErrlUserDetailsParserBackTrace() {}

    /**
     *  @brief Destructor
     */
    virtual ~ErrlUserDetailsParserBackTrace() {}

    /**
     *  @brief Parses backtrace user detail data from an error log
     *
     *  @param  i_version Version of the data
     *  @param  i_parse   ErrlUsrParser object for outputting information
     *  @param  i_pBuffer Pointer to buffer containing detail data
     *  @param  i_buflen  Length of the buffer
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const
    {
        // This buffer contains a number of 64-bit frame pointers.

        // A character vector for storing a backtrace entry and the space
        // required for the header (frame number and address (with some padding
        // for safety)) and the symbol name. This vector is resized if a longer
        // symbol name is encountered.
        const uint8_t BACKTRACE_ENTRY_HEADER_SIZE = 32;
        const uint8_t BACKTRACE_ENTRY_SYMBOL_SIZE = 64;
        std::vector<char> l_traceEntry(BACKTRACE_ENTRY_HEADER_SIZE +
                                       BACKTRACE_ENTRY_SYMBOL_SIZE);

        // Initialize l_the symbol table.
        const char * const l_pNfsSymFile = "/nfs/data/hbicore.syms";
        hbSymbolTable symTab;
        int readRC = symTab.readSymbols( l_pNfsSymFile );
        if( readRC )
        {
            // Not found in NFS, look in maint for symbol file
            const char * const l_pMaintSymFile = "/maint/data/hbicore.syms";
            readRC = symTab.readSymbols( l_pMaintSymFile );

            if( readRC )
            {
                // Not found in maint, look in pwd
                const char * const l_pPwdSymFile = "hbicore.syms";
                readRC = symTab.readSymbols( l_pPwdSymFile );

                if( readRC )
                {
                    i_parser.PrintString( "Symbols not found", l_pPwdSymFile );
                    // symTab.nearestSymbol() will return NULL because of this.
                    // Carry on.
                }
            }
        }

        const char * l_pErrlEntry = "ErrlEntry::ErrlEntry";
        const char * l_pLabel = "Backtrace";

        // loop thru the buffer which is an array of 64-bit addresses
        uint64_t * p64 = static_cast<uint64_t *>(i_pBuffer);
        int l_count = i_buflen / sizeof( uint64_t );
        for( int i = 0; i < l_count; i++ )
        {
            // endian convert the stack address
            uint64_t l_addr  = ntohll(UINT64_FROM_PTR(p64));

            // get nearest symbol
            const char * l_pSymbol = symTab.nearestSymbol( l_addr );

            if( l_pSymbol )
            {
                if( strstr( l_pSymbol, l_pErrlEntry ))
                {
                    // hackish, makes for better looking output
                    // it's in every backtrace (jan2012)
                    l_pSymbol = l_pErrlEntry;
                }

                uint16_t l_traceSize =
                    (BACKTRACE_ENTRY_HEADER_SIZE + strlen(l_pSymbol) + 1);

                if (l_traceEntry.size() < l_traceSize)
                {
                    l_traceEntry.resize(l_traceSize);
                }
                sprintf(&(l_traceEntry[0]),
                        "#%2d %016llX %s", i, l_addr, l_pSymbol);
            }
            else
            {
                sprintf(&(l_traceEntry[0]),"#%2d %016llX", i, l_addr);
            }
            i_parser.PrintString( l_pLabel, &(l_traceEntry[0]) );

            // next stack address in the buffer
            p64++;

            // don't print the label for subsequent backtraces
            l_pLabel = "";
        }
    }

private:
    // Disabled
    ErrlUserDetailsParserBackTrace(const ErrlUserDetailsParserBackTrace &);
    ErrlUserDetailsParserBackTrace & operator=(
        const ErrlUserDetailsParserBackTrace &);
};

}

#endif

