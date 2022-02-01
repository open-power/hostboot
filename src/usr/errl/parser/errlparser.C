/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/parser/errlparser.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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


/**
 *  @file errlparser.C
 *
 *  @brief This program spawns the FipS x86 errl tool to display
 *  a Hostboot error log in full detail.  This program can also show a
 *  brief list of error logs without the detail.  When the user
 *  wants the full detail, this program extracts the error log from
 *  the Hostboot image (or dump) and puts it into a temporary file. When
 *  saved to file, then this program execs "errl -d..."  to display
 *  the error log PEL data.
 *
 *  There are other options, such as "-p" which writes all the PEL files
 *  and does not exec errl. This is useful for debugging.
 *
 *  Enter errlparser ? (or -? or -h or --help)   to print help.
 *  This program can be run standalone using a Simics
 *  L3 memory image and the HB syms file, however it is more likely
 *  spawned via "simics> hb-errl"
 */


#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <string>
#include <vector>
using namespace std;

#include <errl/hberrltypes.H>
#include <hbotcompid.H>

// These should be included from plugin code.
// #include <errl/parser/errlusrparser.H>
// #include <hostBootSrcParse.H>


using namespace ERRORLOG;



#define USAGE "\
Usage:\n\
\n\
errlparser [-i]<image> [[-s]<syms>] [-l|-d[<logid>|all]] [-t <stringfile>] [-e <errl exe>]\n\
\n\
Arguments:\n\
  <image>  data file name\n\
  <syms>   symbols file name\n\
  -l       summarize all error logs (default)\n\
  -d id    print detail from specific error log\n\
  -i name  explicitly name the image file\n\
  -s name  explicitly name the symbols file\n\
  -t name  name the hbotStringFile\n\
  -e file  full path to errl binary\n\
  -v       verbose output to stdout\n\
\n\
Sample command lines:\n\
  errlparser image.bin hbicore.syms       # list logs from a full L3 image\n\
  errlparser image.bin hbicore.syms -d 1  # display log 1\n\
  errlparser image.bin hbicore.syms -d 1 -t hbotStringFile  # display traces\n\
  errlparser buffer.bin       # list logs from pre-extracted storage buffer\n\
  errlparser buffer.bin -d 1  # detail log 1 from pre-extracted storage buffer\n\
\n\
Remarks:\n\
[] If no symbols file name is given, <imagefile> is assumed to be an error\n\
   log storage buffer, usually 64KB in size, that has been pre-extracted\n\
   from an L3 image.\n\
[] All output written to stdout\n\
[] '-s' is optional if the symbols file name contains 'syms'\n\
[] '-i' can be optional in most cases\n\
\n\
Developer switches:\n\
  -p -o <dirname>    Extract all as PEL binaries to output <dirname>\n\
Contact: Monte Copeland\n\
"



//------------------------------------------------------------------------
// Stop the program with a message. This message is often USAGE.  Since
// this program will be spawned from traceHB.py, I think we're better
// served sending the error message to stdout, not stderr.  I don't
// think Simics is piping stderr to its console.
void halt( const char * msg )
{
    // stdout out because Simics does not appear to display stderr (?)
    fprintf( stdout, "%s", msg );

    // exit the process with a non-zero process exit level.
    exit(2);
}




//-------------------------------------------------------------------------
// The file src/include/usr/hbotcompid.H  provide a mapping from  compId_t
// to component name.
// that maps comp id to a string label for it.
struct _errlcompname
{
    const char *    pszName;
    uint32_t  value;
};
typedef _errlcompname  ERRLCOMPNAME_t;

ERRLCOMPNAME_t  g_errlcompnames[] = {
// comps.C generated at build time by a script
// that parses data from src/include/usr/hbotcompid.H.
// Refer to  src/usr/errl/parser/makefile
#include <comps.C>
};


//-------------------------------------------------------------
// Given a reason code which has a comp id mangled into
// it, return a char* to the component name. Return
// null if not found, which printf seems to handle
// OK by printing (null).
const char * FindComp( uint16_t reasoncode )
{
    const char * pch = NULL;
    uint32_t id = (reasoncode & 0xFF00 );
    int c = sizeof( g_errlcompnames ) / sizeof( g_errlcompnames[0] );
    for( int i = 0; i < c; i++ )
    {
      if( id == g_errlcompnames[i].value )
      {
          pch = g_errlcompnames[i].pszName;
          break;
      }
    }
    return pch;
}




//-------------------------------------------------------------
// endian switch a uint64
uint64_t ntohll( uint64_t i )
{
    uint64_t hi;
    uint64_t lo;
    uint32_t * pword = reinterpret_cast<uint32_t*>(&i);

    hi = ntohl( *pword );
    lo = ntohl( *(pword+1) );

    return (hi<<32)|lo;
}





//-------------------------------------------------------------
// endian stuff, convert a errl storage marker in place
marker_t*  ConvertMarker( marker_t* p)
{
    p->offsetNext    = ntohl( p->offsetNext );
    p->length        = ntohl( p->length );
    return p;
}


//-------------------------------------------------------------
// endian stuff, convert the data stored at the beginning of the
// errl storage buffer
storage_header_t * ConvertStorageHeader(  storage_header_t * p )
{
    p->cbStorage      = ntohl( p->cbStorage );
    p->cInserted      = ntohl( p->cInserted );
    p->offsetMarker   = ntohl( p->offsetMarker );
    p->offsetStart    = ntohl( p->offsetStart );
    return p;
}

//-------------------------------------------------------------
// endian stuff,convert in place, return a pointer to what
// you passed in.  PEL is made up of multiple sections, each
// one starting with a header that has these 8 bytes.
pelSectionHeader_t * ConvertPELSectionHeader( pelSectionHeader_t * p )
{
    p->sid    = ntohs( p->sid );
    p->len    = ntohs( p->len );
    // byte:  p->ver
    // byte:  p->sst
    p->compId = ntohs( p->compId );
    return p;
}


//-------------------------------------------------------------
// endian stuff, convert in place. This converts the first section
// encountered in PEL, the PH section (private header).
pelPrivateHeaderSection_t* ConvertPrivateHeader(pelPrivateHeaderSection_t* p)
{
    ConvertPELSectionHeader( &p->sectionheader );
    p->creationTime         = ntohll( p->creationTime );
    p->commitTime           = ntohll( p->commitTime );
    p->creatorImplementation = ntohll( p->creatorImplementation );
    p->plid                 = ntohl( p->plid );
    p->eid                  = ntohl( p->eid );
    return p;
}


//-------------------------------------------------------------
// endian stuff, convert in place. Convert the 2nd section in PEL,
// the UH (user header).
pelUserHeaderSection_t * ConvertUserHeader( pelUserHeaderSection_t * p )
{
    ConvertPELSectionHeader( &p->sectionheader );
    // mostly byte sized stuff
    p->actions      = ntohs( p->actions );
    return p;
}


//-------------------------------------------------------------
// endian stuff, convert in place.  The PS (primary SRC) section
// in PEL is the 3rd section.
pelSRCSection_t * ConvertSRC( pelSRCSection_t * p )
{
    ConvertPELSectionHeader( &p->sectionheader );
    // mostly byte sized stuff
    p->src.srcLength        = ntohs( p->src.srcLength );
    p->src.reserved1        = ntohs( p->src.reserved1 );
    p->src.word2            = ntohl( p->src.word2 );
    p->src.word3            = ntohs( p->src.word3 );
    p->src.word4            = ntohl( p->src.word4 );
    p->src.word5            = ntohl( p->src.word5 );
    p->src.word6            = ntohll( p->src.word6 );
    p->src.word8            = ntohll( p->src.word8 );
    return p;
}


//-------------------------------------------------------------
// endian stuff, convert in place.  The EH (Extended User Header) section
// in PEL is the 4th section.
pelExtendedUserHeaderSection_t * ConvertExtendedUserHeader( pelExtendedUserHeaderSection_t * p )
{
    ConvertPELSectionHeader( &p->sectionheader );
    p->reserved  = ntohl( p->reserved );
    p->timestamp = ntohll( p->timestamp );
    return p;
}



//-----------------------------------------------------------------------
// Given the binary image file name, return the errl storage part of the file.
// Caller must endian convert anything/everything in the output buffer.
// This function will allocate (malloc) the buffer and return a pointer to it.
// On fatal error, this function will print a diagnostic and end the process.
// Return how many bytes allocated for the buffer in io_cbBuffer.
char* ReadStorageBuffer(char* i_Image, uint32_t i_ulAddr, uint32_t &io_cbBuffer)
{
    int fd;
    int rc;
    int cb;
    off_t offsetEnd;
    char * l_pchBuffer = NULL;   // pointer to return
    storage_header_t header;

    // open the image file and read the errl log buffer
    fd = open( i_Image, O_RDONLY );
    if ( fd == -1 )
    {
        // write the error to stdout because more likely to be seen in Simics
        fprintf(stdout, "Unable to open %s for reading.\n", i_Image);
        fprintf(stdout, "Failed with errno %s\n", strerror(errno) );
        exit(2);
    }

    offsetEnd = lseek( fd, 0, SEEK_END );
    if( i_ulAddr >= offsetEnd )
    {
        fprintf( stdout, "Image file %s appears to be truncated. "
                         "Offset 0x%X exceeds size of image file.\n",
                         i_Image, i_ulAddr );
        exit(2);
    }

    rc = lseek( fd, i_ulAddr, SEEK_SET );
    assert( -1 != rc );


    // Read just the header for the size of the buffer is
    // stored in the header.
    cb = read( fd, &header, sizeof( header ));
    assert( -1 != cb );

    // endian convert this copy of the header
    ConvertStorageHeader( &header );

    // io_cbBuffer is a count of bytes in storage
    io_cbBuffer = header.cbStorage;

    if( io_cbBuffer > ( 5 * ERRL_STORAGE_SIZE ))
    {
        // Unreasonable
        fprintf( stdout, "Problem with image file %s\n", i_Image );
        fprintf( stdout, "Buffer size %d is unreasonable.\n", io_cbBuffer );
        exit(2);
    }

    if( ( i_ulAddr + io_cbBuffer ) > offsetEnd )
    {
        fprintf( stdout, "Image file %s appears to be truncated. "
                         "Offset 0x%X exceeds size of image file.\n",
                         i_Image, i_ulAddr+io_cbBuffer );
        exit(2);
    }


    if( io_cbBuffer == 0  )
    {
        // The committing of the very first error log would have put
        // data into the storage buffer header.  However, the data
        // is zero, meaning no error log was ever committed.
        fprintf( stdout, "No error logs to report.\n" );
        exit(0);
    }


    // re-seek and re-read entire buffer this time.
    rc = lseek( fd, i_ulAddr, SEEK_SET );
    assert( -1 != rc );

    l_pchBuffer = static_cast<char *>(malloc( io_cbBuffer ));
    assert( l_pchBuffer );

    cb = read( fd, l_pchBuffer, io_cbBuffer );
    assert( -1 != cb );

    close( fd );
#if 0
    {
      // Write the error log storage buffer to its own file.
      // Offsets stored in the buffer are relative to the
      // start of the buffer.  When this file is saved in
      // its own file, the same offsets are relative to the
      // start of the file. This is convenient when debugging.
      fd = open( "storagebuffer.bin", O_CREAT | O_RDWR, 0666 );
      if(  -1 != fd )
      {
        write( fd, l_pchBuffer, io_cbBuffer );
        close( fd );
      }
    }
#endif
    return l_pchBuffer;
}






//----------------------------------------------------------------------------
// Open the given symbols file name, a text file, and find the storage address
// of error logs given by the symbol in pszSearch.
uint32_t FindSymbol( char * pszSymbolFile,  const char * pszSearch )
{
    char * pszAddr = NULL;
    char * pch;
    char szWork[ 1024 ];
    uint32_t ulAddr = 0;
    FILE * f;

    f = fopen( pszSymbolFile, "r" );
    if ( !f )
    {
        fprintf(stdout, "Unable to open file %s for reading.\n", pszSymbolFile);
        fprintf(stdout, "Failed with errno %s\n", strerror(errno) );
        exit(2);
    }

    while( fgets( szWork, sizeof( szWork ), f ))
    {
        pch = strstr( szWork, pszSearch );
        if( pch )
        {
            // tease out the address for this symbol
            pszAddr = szWork + 2;
            pch = strchr( pszAddr, ',' );
            assert( pch );
            *pch = 0;
            break;
        }
    }
    fclose(f);

    if( NULL == pszAddr )
    {
        fprintf( stdout, "Cannot find %s in syms file.\n", pszSearch );
        exit(2);
    }

    // Convert ascii hex representation of address to a unsigned long
    int c = sscanf( pszAddr, "%x", &ulAddr );
    if( 1 != c )
    {
        fprintf( stdout,
                 "Error, expecting '%s' to convert to hexidecimal.\n",
                 pszAddr );
        exit(2);
    }
    return ulAddr;
}



//-----------------------------------------------------------------------------
// Output a vector of endian-converted PEL sections, without altering the caller's
// pchNativePEL input buffer.  The vector will have pointers to PEL section
// headers, and the user of the vector contents will have to cast according to
// pelSectionHeader_t.sid  (section id ).

bool ParseForPEL( char * i_pchNativePEL,
                  int    i_cbPEL,
                  vector<pelSectionHeader_t*> &o_vector )
{

    // use pch to bump along through the PEL sections
    char * pch = i_pchNativePEL;

    while( pch <  (i_pchNativePEL+i_cbPEL))
    {
        void * pvoid;
        pelSectionHeader_t  sectionHeader;

        // Convert a copy of just the PEL section header so I can look at the
        // sid (section id/type) and the overall section length.
        memcpy( &sectionHeader, pch, sizeof( pelSectionHeader_t ));
        ConvertPELSectionHeader( &sectionHeader );

        // For each section, allocate space for it, endian convert the
        // section, then insert into output vector.
        switch( sectionHeader.sid ) {
        case ERRL_SID_PRIVATE_HEADER:
            {
                pvoid = malloc(sectionHeader.len);
                pelPrivateHeaderSection_t * p;
                p = static_cast<pelPrivateHeaderSection_t*>(pvoid);
                memcpy( p, pch, sectionHeader.len );
                ConvertPrivateHeader( p );
                o_vector.push_back( reinterpret_cast<pelSectionHeader_t*>(p) );
            }
            break;
        case ERRL_SID_USER_HEADER:
            {
                pvoid = malloc(sectionHeader.len);
                pelUserHeaderSection_t * p;
                p = static_cast<pelUserHeaderSection_t*>(pvoid);
                memcpy( p, pch, sectionHeader.len );
                ConvertUserHeader( p );
                o_vector.push_back( reinterpret_cast<pelSectionHeader_t*>(p) );
            }
            break;
        case ERRL_SID_PRIMARY_SRC:
            {
                pvoid = malloc(sectionHeader.len);
                pelSRCSection_t * p;
                p = static_cast<pelSRCSection_t*>(pvoid);
                memcpy( p, pch, sectionHeader.len );
                ConvertSRC( p );
                o_vector.push_back( reinterpret_cast<pelSectionHeader_t*>(p) );
            }
            break;
        case ERRL_SID_EXTENDED_HEADER:
            {
                pvoid = malloc(sectionHeader.len);
                pelExtendedUserHeaderSection_t * p = static_cast<pelExtendedUserHeaderSection_t*>(pvoid);
                memcpy( p, pch, sectionHeader.len );
                ConvertExtendedUserHeader( p );
                o_vector.push_back( &p->sectionheader );
            }
            break;
        case ERRL_SID_USER_DEFINED:
        case ERRL_SID_EXTENDED_USER_DEFINED:
        case ERRL_SID_FAILING_ENCLOSURE_MTMS:
            {
                pvoid = malloc(sectionHeader.len);
                pelSectionHeader_t * p;
                p = static_cast<pelSectionHeader_t*>(pvoid);
                memcpy( p, pch, sectionHeader.len );
                // Only converts the PEL section header, but none of the
                // user-defined content.  No way to know what's in there.
                ConvertPELSectionHeader(p);
                o_vector.push_back(p);
            }
            break;
        default:
            assert( 0 );
            break;
        }

        pch +=  sectionHeader.len;
    }

    return true;
}




//-----------------------------------------------------------------------------
// Scan the vector of endian-converted PEL sections. Locate the target section
// and return it.  Return NULL if not found.  Caller will have to cast
// the returned section header pointer to the desired PEL section struct.

pelSectionHeader_t * FindPELSection( unsigned int i_target,
                                     vector<pelSectionHeader_t*> &o_vector )
{
    pelSectionHeader_t * p = NULL;

    vector<pelSectionHeader_t*>::iterator it;
    for( it = o_vector.begin(); it != o_vector.end(); it++ )
    {
        if( (*it)->sid == i_target )
        {
            p = *it;
            break;
        }
    }

    return p;
}












//-------------------------------------------------------------
int main( int argc,  char *argv[] )
{
    char * pch;
    char * pchNativePEL;
    const char * pszErrlTool = NULL;
    char * pszImageFile = NULL;
    char * pszSymbolFile = NULL;
    char * pszStringFile = NULL;
    char * pszOutputDir  = NULL;
    char szWork[ 1024 ];
    char szTmpFilename[ 1024 ];
    char szCommand[ 128 ];
    unsigned char * puch;
    char * pszSearch;
    char * pszAddr = NULL;
    char * pchBuffer;
    uint32_t ulAddr = 0;
    char szDivider[ 256 ];
    uint32_t ulLogId = 0;
    int c;
    int cb;
    int cbSearch;
    int fd;
    int i;
    int k;
    int item;
    int fOK;
    int rc;
    int exitcode = 0;
    uint32_t cbBuffer = 0;
    off_t offset;
    off_t offsetEnd;
    int fVerbose = 0;
    int fList = 1;
    int fListHead = 0;
    int fDetail = 0;
    int fAll    = 0;
    int fFound = 0;
    int fExtractPEL = 0;
    void * pvoid;
    struct stat statbuffer;


    // build a =========== divider for printfing
    cb = 78;
    assert( cb < sizeof( szDivider ));
    memset( szDivider, '=', sizeof( szDivider ));
    szDivider[ cb ] = 0;


    // Examine args.
    i = 1;
    while ( i < argc )
    {
        if( 0 == strcmp( "-v", argv[i] ))
        {
            fVerbose = 1;
        }
        else if( 0 == strcmp( "-d", argv[i] ))
        {
            i++;
            if( i >= argc )
            {
                // nothing after -d
                fAll = 1;
            }
            else if( 0 == strcmp( argv[i], "all" ))
            {
                fAll = 1;
            }
            else
            {
                int c = sscanf( argv[i], "%x", &ulLogId );
                if( c != 1 )
                {
                  fprintf( stdout, "Provide -d <hex log ID>\n" );
                  exit( 2 );
                }
            }

            fList = 0;
            fDetail = 1;
        }
        else if( 0 == strcmp( "-i", argv[i] ))
        {
            i++;
            if( i >= argc )
            {
              fprintf( stdout, "Provide -i <imagefile>\n" );
              exit( 2 );
            }
            pszImageFile = strdup( argv[i] );
        }
        else if( 0 == strcmp( "-o", argv[i] ))
        {
            i++;
            if( i >= argc )
            {
              fprintf( stdout, "Provide -o <dirname>\n" );
              exit( 2 );
            }
            pszOutputDir = strdup( argv[i] );
        }
        else if( 0 == strcmp( "-p", argv[i] ))
        {
            fExtractPEL = 1;
            fList = 0;
            fDetail = 0;
        }
        else if( 0 == strcmp( "-t", argv[i] ))
        {
            i++;
            if( i >= argc )
            {
              fprintf( stdout, "Provide -t <string file>\n" );
              exit( 2 );
            }
            pszStringFile = strdup( argv[i] );

            // errl messes up ~ somehow, I thought bash
            // would substitute this.
            pch = strchr( pszStringFile, '~' );
            if( pch )
            {
                printf( "Don't use ~ for file naming.\n" );
                exit(2);
            }
        }
        else if( 0 == strcmp( "-s", argv[i] ))
        {
            i++;
            if( i >= argc )
            {
              fprintf( stdout, "Provide -s <symsfile>\n" );
              exit( 2 );
            }
            pszSymbolFile = strdup( argv[i] );
        }
        else if( 0 == strcmp( "-l", argv[i] ))
        {
            fList = 1;
            fDetail = 0;
        }
        else if( 0 == strcmp("?", argv[i]) ||
                 0 == strcmp("-?", argv[i]) ||
                 0 == strcmp("-h", argv[i]) ||
                 0 == strcmp("--help", argv[i]))
        {
            // help
            halt( USAGE );
        }
        else if( 0 == strcmp( "-e", argv[i] ))
        {
            i++;
            if( i >= argc )
            {
              fprintf( stdout, "Provide -e <errl exe>\n" );
              exit( 2 );
            }
            pszErrlTool = strdup( argv[i] );
        }
        else if( 0 == strcmp( "-", argv[i] ))
        {
            // unrecognized switch
            halt( USAGE );
        }
        else
        {
            // must be a file name
            pch = strstr( argv[i], "syms" );
            if( pch )
            {
                if( pszSymbolFile )
                {
                    halt( USAGE );
                }
                pszSymbolFile = strdup( argv[i] );
            }
            else
            {
                if( pszImageFile )
                {
                    halt( USAGE );
                }
                pszImageFile = strdup( argv[i] );
            }
        }

        i++;
    }


    // Check args.
    if( !pszImageFile )
    {
        halt( USAGE );
    }

    if(( fExtractPEL ) && ( NULL == pszOutputDir ))
    {
        printf( "Provide output dir for PEL extraction.\n" );
        exit(1);
    }

    // There is a copy of FSP x86 errl tool in the simics dir.
    if( (pszErrlTool == NULL)
        || (-1 == stat( pszErrlTool, &statbuffer )) )
    {
        pszErrlTool = "./errl";
    }

    rc = stat( pszErrlTool, &statbuffer );
    if(  -1 == rc )
    {
        // Not found, so this one should be found for most users.
        pszErrlTool =
        "/esw/fips1010/Builds/built/obj/x86.nfp/errl/nfp/tool/errl";

        rc = stat( pszErrlTool, &statbuffer );
        if(  -1 == rc )
        {
            printf( "Unable to find a copy of errl, including %s.\n",
                    pszErrlTool );
            exit(2);
        }
    }

    if( fVerbose )
    {
        printf( "Using errl tool %s\n", pszErrlTool );
    }


    if( pszStringFile )
    {
        int fd = open( pszStringFile, O_RDONLY );
        if( -1 == fd )
        {
            printf( "String file %s not found.\n", pszStringFile );
            exit(2);
        }
        rc = fstat( fd, &statbuffer );
        close(fd);
        if( ( -1 == rc ) ||  !(S_ISREG(statbuffer.st_mode)))
        {
            printf( "String file %s is not valid.\n", pszStringFile );
            exit(2);
        }
    }



    if( pszSymbolFile )
    {
        // Given the symbols file, locate the address/offset of the
        // errl storage buffer.
        ulAddr = FindSymbol( pszSymbolFile, "g_ErrlStorage" );
        if( fVerbose )
        {
            printf( "Error log storage buffer offset: 0x%08x\n", ulAddr );
        }
    }
    else
    {
        // No symbols file name given.
        // Proceed as though the image file is the 64KB storage buffer,
        // already extracted for me. This is the case for awan.
        ulAddr = 0;
        if( fVerbose )
        {
            printf( "Assuming '%s' is errl storage buffer.\n", pszImageFile );
        }
    }

    // Given the image file, read the portion that contains the
    // error log storage buffer.
    pchBuffer = ReadStorageBuffer( pszImageFile, ulAddr, cbBuffer );
    assert( pchBuffer );
    assert( cbBuffer );
    if( fVerbose )
    {
        printf("Errlog storage buffer size: %d (decimal) bytes\n", cbBuffer );
    }


    // Convert the endianness of the storage header.
    storage_header_t* pHeader = reinterpret_cast<storage_header_t*>(pchBuffer);
    ConvertStorageHeader( pHeader );
    if( fVerbose )
    {
        printf( "%d error logs were committed.\n", pHeader->cInserted );
        printf( "Start offset:  0x%08x\n",  pHeader->offsetStart );
        printf( "Ending offset: 0x%08x\n",  pHeader->offsetMarker );
    }


/** @brief Convert an offset to a marker_t pointer.       */
#define OFFSET2MARKER(offset) (reinterpret_cast<marker_t*>(pchBuffer+offset))


/** @brief Convert a marker_t pointer to an offset within the buffer. */
#define MARKER2OFFSET(p) ((reinterpret_cast<char*>(p))-pchBuffer)



    // Count how many error logs found
    int logcount = 0;

    // Traverse the list of error logs in the buffer.  At this time, the
    // buffer does not wrap. It is a straight shot from start to finish.
    // Follow the markers.  The start-of-list marker:
    marker_t* pMarker = ConvertMarker( OFFSET2MARKER(pHeader->offsetStart));

    while( 1 )
    {
        if( fVerbose )
        {
            cb = printf( "Marker at 0x%06x: next 0x%06x, length 0x%06x\n",
                         MARKER2OFFSET(pMarker),
                         pMarker->offsetNext,
                         pMarker->length );
        }

        if( pMarker->offsetNext == 0 )
        {
            // This is the list-ending marker.
            break;
        }

        assert( pMarker->length );

        logcount++;

        // Flattened PEL of an error log resides just past marker
        // for a length of pMarker->length.  It is "native" meaning big endian.
        pchNativePEL = reinterpret_cast<char*>(pMarker+1);

        // Make a copy of PH that I can endian convert without screwing up
        // the native one.
        pvoid = malloc( pMarker->length );
        pelPrivateHeaderSection_t * pPrivateHdr;
        pPrivateHdr = static_cast<pelPrivateHeaderSection_t*>(pvoid);
        memcpy( pPrivateHdr, pchNativePEL, pMarker->length );

        // Convert the PEL private header copy to local endianness.
        ConvertPrivateHeader( pPrivateHdr );

        if( fList )
        {
            // print a simple list of error log IDs
            if( !fListHead )
            {
                // print a head line
                printf( "%-16s %8s\n", "Component", "PLID" );
                printf( "%s\n", szDivider );
                fListHead  = 1;
            }
            printf( "%-16s 0X%8X\n",
                    FindComp(pPrivateHdr->sectionheader.compId),
                    pPrivateHdr->eid );
        }
        else if(( fDetail ) && (( pPrivateHdr->eid == ulLogId ) || (fAll)))
        {
            // Write the native PEL to a temporary file
            // for x86 errl tool to display.
            sprintf( szTmpFilename, "/tmp/pel%X.bin", pPrivateHdr->eid );

            int fd = open( szTmpFilename,  O_RDWR | O_CREAT , 0664 );
            if( -1 == fd )
            {
                printf( "Unable to write %s. Exiting.\n", szTmpFilename );
                exit(2);
            }
            cb = write( fd, pchNativePEL, pMarker->length );
            assert( cb  == pMarker->length );
            close(fd);

            // Spawn the FSP x86 errl tool to display
            // the detail for this error log.
            cb=sprintf(szCommand,"%s -d --file=%s",pszErrlTool,szTmpFilename);
            if( pszStringFile )
            {
                sprintf( &szCommand[cb], " --trace=%s", pszStringFile );
            }

            // Run errl -d  to display the error log.
            system( szCommand );


            // Build a vector containing pointers to each PEL section
            // in the error log. On return, each section will be endian
            // converted as much as possible.  Do not alter the endianness
            // of the native pel buffer, however.
            vector<pelSectionHeader_t*> vectorPEL;
            ParseForPEL( pchNativePEL, pMarker->length, vectorPEL );
            assert( vectorPEL.size() );



            // Print the tag detail gleaned from the code by
            // the errl tag parser. That requires getting the reason
            // code and module ID from the error log. They live in
            // the Primary SRC section.
            uint32_t l_reasonCode = 0;


            // Find the PS section in the vector of PEL sections.
            pelSectionHeader_t* pPELHead;
            pPELHead = FindPELSection( ERRL_SID_PRIMARY_SRC, vectorPEL );
            assert( pPELHead );

            // Cast to Primary SRC section.
            pelSRCSection_t * pSRCSection;
            pSRCSection = reinterpret_cast<pelSRCSection_t*>(pPELHead);

#if 0
            // reasonCode has been "stringified" into the SRC string
            pch = strchr( pSRCSection->src.srcString, ' ' );
            assert( pch );
            *pch = 0;
            assert( 8 == strlen( pSRCSection->src.srcString));
            sscanf( pSRCSection->src.srcString + 4, "%X", &l_reasonCode );
#else
            // I have cheated and put reasonCode here:
            l_reasonCode = pSRCSection->src.reserved1;
#endif

            // done with this tmp file
            unlink( szTmpFilename );

            // found at least one
            fFound = 1;
        }


        if( fExtractPEL )
        {
            // Write the native PEL to a temporary file for debug later.
            sprintf( szTmpFilename, "%s/pel%X.bin", pszOutputDir, pPrivateHdr->eid );

            int fd = open( szTmpFilename,  O_RDWR | O_CREAT , 0664 );
            if( -1 == fd )
            {
                printf( "Unable to write %s. Exiting.\n", szTmpFilename );
                exit(2);
            }
            cb = write( fd, pchNativePEL, pMarker->length );
            assert( cb  == pMarker->length );
            close(fd);

            printf( "Saved as %s\n", szTmpFilename );
        }



        // next marker/error log
        pMarker = ConvertMarker( OFFSET2MARKER(pMarker->offsetNext) );
    }


    if( fVerbose )
    {
        printf( "%d error logs found.\n", logcount );
    }

    if( fDetail  &&  !fFound )
    {
        printf( "Error log %d not found.\n", ulLogId );
        exitcode = 2;
    }
    return exitcode;
}
