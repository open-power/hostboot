//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/plugins/errlParse.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END




#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <endian.h>
#include <vector>

// Get these from a FipS/FSP backing build.
#include <errlplugins.H>
#include <errlusrparser.H>
#include <srcisrc.H>

// These are from Hostboot.
#include <hbotcompid.H>
#include <hostBootSrcParse.H>
#include <errl/hberrltypes.H>

// Get these from current directory.
#include "symbols.H"



//-------------------------------------------------------------
// endian switch a uint64
// TODO all plugins are probably going to want this.

static uint64_t ntohll( uint64_t i )
#if __BYTE_ORDER == __LITTLE_ENDIAN
{
    //  CONTEXT_x86_nfp
    uint64_t hi;
    uint64_t lo;
    uint32_t * pword = reinterpret_cast<uint32_t*>(&i);

    hi = ntohl( *pword );
    lo = ntohl( *(pword+1) );

    return (hi<<32)|lo;
}
#elif __BYTE_ORDER == __BIG_ENDIAN
{
    // CONTEXT_ppc (or maybe CONTEXT_aix_nfp)
    return i;
}
#else
#error Unexpected endian context.
#endif




//--------------------------------------------------------------------------
// Use methods of i_parser such as
//         i_parser.PrintString( "label", "datastring" );
// to format my user-defined data attached to error logs for my component.
// Parameters i_sst (subsection type) and i_ver (version) identify
// the nature of the user-defined data as defined by my component.
// The file $bb/export/x86.nfp/fips/include/errlusrparser.H defines the
// ErrlUsrParser class.
//
// Return true if handled, suppressing the default hex dump of the data.

static bool myDataParse  (
                        ErrlUsrParser& i_parser,
                        void* i_buffer,
                        uint32_t i_buflen,
                        errlver_t i_ver,
                        errlsubsec_t i_sst)
{

    bool rc = false;
    char szWork[ 256 ];


    switch( i_sst ) {
    case HBERRL_SST_FIRSTLADY:
        {
            memcpy( szWork, i_buffer, i_buflen );
            szWork[ i_buflen ] = 0;
            i_parser.PrintString( "First Lady", szWork );
            rc = true;
        }
        break;
    case HBERRL_SST_PRESIDENT:
        {
            memcpy( szWork, i_buffer, i_buflen );
            szWork[ i_buflen ] = 0;
            i_parser.PrintString( "President", szWork );
            rc = true;
        }
        break;
    case HBERRL_SST_STRING:
        {
            // How to label this string?
            const char * l_pLabel;
            switch( i_ver )
            {
                case HBERRL_VER_STRINGTASK:
                    l_pLabel = "Task";
                    break;
                case HBERRL_VER_STRINGTASKNAME:
                    l_pLabel = "Task name";
                    break;
                case HBERRL_VER_STRINGATTRNAME:
                    l_pLabel = "Attribute name";
                    break;
                case HBERRL_VER_STRINGFILENAME:
                    l_pLabel = "File name";
                    break;
                case HBERRL_VER_STRINGPROCNAME:
                    l_pLabel = "Procedure name";
                    break;
                case HBERRL_VER_STRINGNAME:
                default:
                    l_pLabel = "Name";
                    break;
             }
             // Expect to have a null-ended string in the data,
             // but add a null for good measure.
             int cb = i_buflen + 1;
             char * pWork = new char[cb];
             memcpy( pWork, i_buffer, i_buflen );
             pWork[i_buflen] = 0;
             i_parser.PrintString( l_pLabel, pWork );
             delete pWork;
             rc = true;
        }
        break;

    case HBERRL_SST_BACKTRACE:
        {
            // This buffer contains a number of 64-bit frame pointers.
            // Awkward because FipS/FSP errl provides no PrintNumber()
            // for a 64-bit number as of Jan 2012.

            // Initialize l_the symbol table.
            const char * l_pSymFile = "hbicore.syms";
            hbSymbolTable symTab;
            int readRC = symTab.readSymbols( l_pSymFile );
            if( readRC )
            {
                i_parser.PrintString( "Symbols not found", l_pSymFile );
                // symTab.nearestSymbol() will return NULL because of this.
                // Carry on.
            }

            const char * l_pErrlEntry = "ErrlEntry::ErrlEntry";
            const char * l_pLabel = "Backtrace";

            // loop thru the buffer which is an array of 64-bit addresses
            uint64_t * p64 = static_cast<uint64_t*>(i_buffer);
            int l_count = i_buflen / sizeof( uint64_t );
            for( int i = 0; i < l_count; i++ )
            {
                // endian convert the stack address
                uint64_t l_addr  = ntohll(*p64);

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
                    sprintf( szWork,"#%2d %016llX %s", i, l_addr, l_pSymbol );
                }
                else
                {
                    sprintf( szWork,"#%2d %016llX", i, l_addr );
                }
                i_parser.PrintString( l_pLabel, szWork );

                // next stack address in the buffer
                p64++;

                // don't print the label for subsequent backtraces
                l_pLabel = "";
            }

            rc = true;
        }
        break;
    default:
        break;
    }


    return rc;
}

// Map my Hostboot component ID to the function above.
// static errl::DataPlugin g_DataPlugin( HBERRL_COMP_ID, hberrl_DataParse );
static errl::DataPlugin g_DataPlugin( HBERRL_COMP_ID, myDataParse );




//----------------------------------------------------------------------------
// Call the code generated by scanforsrc.pl

static bool hbSrcParse( ErrlUsrParser & i_parser, const SrciSrc & i_src  )
{
  uint32_t src = 0;

  sscanf( i_src.getAsciiString(), "%X", &src );

  // Call this function in obj/genfiles/hostBootSrcParse.H (a script-generated
  // file) which serves for any Hostboot component.   This will cause
  // the FSP errl tool to add the tagged information to the primary SRC
  // section of the error log. For example, the developer description
  // (devdesc) tag and associated info as well as the other tags describing
  // the userdata1 and userdata2 words.
  printErrorTags( i_parser, (src & 0xFFFF), i_src.moduleId()  );

  return false;
}

// Create an instance of SrcPlugin by type (instead of the usual component).
static errl::SrcPlugin  g_SrcPlugin( errl::Plugin::HOSTBOOT_SRCPARSE, hbSrcParse );



