/**
 *  @file errlparser.C
 *
 *  @brief Parse and display committed error logs. Enter
 *  errlparser ? (or -? or -h or --help)   to print help.
 */


#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <string>
using namespace std;


#include <errl/errltypes.H>
#include <hbotcompid.H>
using namespace ERRORLOG;


#define USAGE "\
Usage:\n\
\n\
errlparser  <imagefile> <symsfile> [-l | -d <logid>]\n\
\n\
Provide L3 memory image file and its hbicore*.syms file.\n\
  -l       summarize all error logs (default)\n\
  -d id    print detail from specific error log\n\
\n\
Contact: Monte Copeland\n\
"

//------------------------------------------------------------------------
// Stop the program with a message. This message is often USAGE.  Since
// this program will be spawned from traceHB.py, I think we're better
// served sending the error message to stdout, not stderr.  I don't
// think Simics is piping stderr to its console.
void halt( char * msg )
{
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
    char *    pszName;
    uint32_t  value;
};
typedef _errlcompname  ERRLCOMPNAME_t;

ERRLCOMPNAME_t  g_errlcompnames[] = {
// comps.C generated at build time by a script
// that parses data from src/include/usr/hbotcompid.H.
// Refer to  src/usr/errl/parser/makefile
#include <comps.C>
};

// Given a reason code which has a comp id mangled into
// it, return a char* to the component name. Return
// null if not found, which printf seems to handle
// OK by printing (null).
char * FindComp( uint16_t reasoncode )
{
    char * pch = NULL;
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



//------------------------------------------------------------
// Print a hex dump of the input buffer to the output file
// given, probably stdout.

int FormatBytes(  FILE * f,  char * pchInput, int count, int indent )
{
    char             szChars[ 80 ];
    char             szHex[ 80 ];
    char             szOffset[ 64 ];
    char             szWork[ 256 ];
    int              i;
    unsigned int     ul;
    char           * pch;
    char           * pchLine;
    int              cb;
    char           * pszIndent = NULL;



    pszIndent = static_cast<char*>(malloc( indent+1 ));
    memset( pszIndent, 0, indent+1 );
    memset( pszIndent, ' ', indent );



    pchLine = pchInput;


    while( pchLine < pchInput + count )
    {
        /* current offset */
        ul = pchLine - pchInput;

        sprintf( szOffset, "%08X", ul );

        memset( szHex, ' ', sizeof( szHex ));
        pch = szHex;

        cb = ((pchInput+count)-pchLine) > 16 ? 16 : ((pchInput+count)-pchLine);

        for( i = 0; i < cb; i++ )
        {
            ul = (unsigned char) pchLine[ i ];

            sprintf( szWork, "%02x", ul );
            memcpy( pch, szWork, 2 );

            pch += 3;
        }

        szHex[ 23 ] = '-';
        szHex[ 48 ] = 0;

        memset( szChars, 0, sizeof( szChars ));
        for( i = 0; i < cb; i++ )
        {
            szChars[i] = '.';

            int t = pchLine[i];

            if( t > 31  )
            {
              szChars[i] = pchLine[ i ];
            }
        }

        sprintf( szWork, "%s  %s %s", szOffset, szHex, szChars );
        fprintf( f, "%s%s\n", pszIndent, szWork );
        fflush( f );
        pchLine += 16;
    }

    return 0;
}



//-------------------------------------------------------------
// endian stuff
section_header_t*  ConvertSectionHeader( section_header_t* p)
{
    p->cbHeader           = ntohl( p->cbHeader );
    p->cbSection          = ntohl( p->cbSection );
    p->compId             = ntohs( p->compId );
    // sctnVer is byte long
    // subSect is byte long
    return p;
}


//-------------------------------------------------------------
// endian stuff
marker_t*  ConvertMarker( marker_t* p)
{
    p->offsetNext    = ntohl( p->offsetNext );
    p->length        = ntohl( p->length );
    return p;
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
// endian stuff
errl_header_t* ConvertErrlHeader( errl_header_t* p )
{
    p->cbytes                = ntohl( p->cbytes );
    p->csections             = ntohl( p->csections );
    p->reasonCode            = ntohs( p->reasonCode );
    // p->modId      is a byte
    // p->sev        is a byte
    // p->eventType  is a byte
    // p->subSys     is a byte
    // p->srcType    is a byte
    p->termState             = ntohl( p->termState );
    p->logId                 = ntohl( p->logId );
    p->user1                 = ntohll( p->user1 );
    p->user2                 = ntohll( p->user2 );
    p->CreationTime          = ntohll( p->CreationTime );
    return p;
}



//-------------------------------------------------------------
// endian stuff
storage_header_t * ConvertStorageHeader(  storage_header_t * p )
{
    p->cbStorage      = ntohl( p->cbStorage );
    p->cInserted      = ntohl( p->cInserted );
    p->offsetMarker   = ntohl( p->offsetMarker );
    p->offsetStart    = ntohl( p->offsetStart );
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

    // open the binary image of L3 RAM and read the errl log buffer
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

    if( ( i_ulAddr + io_cbBuffer ) > offsetEnd )
    {
        fprintf( stdout, "Image file %s appears to be truncated. "
                         "Offset 0x%X exceeds size of image file.\n",
                         i_Image, i_ulAddr+io_cbBuffer );
        exit(2);
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
uint32_t FindSymbol( char * pszSymbolFile,  char * pszSearch )
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



// --------------------------------------------------------------------------
// Print a summary of the error log, no user-defined data nor detail.
// perrlog is already endian converted

void PrintErrlSummary(  errl_header_t * perrlog  )
{

    // print headline
    //      comp  id   sev rc  mod  evt   u1    u2   csec
    printf( "%-7s %10s %4s %-6s %-4s %-4s %-18s %-18s %5s\n",
      "comp",
      "logid",
      "sev",
      "reason",
      "mod",
      "evnt",
      "user1",
      "user2",
      "csect"  );


    //       comp   id   sev    reason  mod   event  user1     user2     csec
    //                          code
    printf( "%-7s %10d 0x%02x 0x%04x 0x%02x 0x%02x 0x%016llx 0x%016llx %5d\n",
          FindComp( perrlog->reasonCode ),
          perrlog->logId,
          perrlog->sev,
          perrlog->reasonCode,
          perrlog->modId,
          perrlog->eventType,
          perrlog->user1,
          perrlog->user2,
          perrlog->csections      // count of sections
    );
}


//---------------------------------------------------------------------------
//
//
void PrintErrlDetail(  errl_header_t * perrlog  )
{

    // print the summary line
    PrintErrlSummary(  perrlog  );

    // print sections if any
    if( perrlog->csections )
    {
        int i;
        section_header_t* psect;

        // first section header resides just past the errl_header_t
        psect = reinterpret_cast<section_header_t*>(perrlog+1);

        // Endian convert it
        ConvertSectionHeader( psect );

        i = 0;
        do
        {
            printf(
              "\nSection %d: %-8s len=0x%04x, ver=0x%04x, subsection=0x%04x\n",
              i,
              FindComp( psect->compId ),
              psect->cbSection,
              psect->sctnVer,
              psect->subSect
            );

            // The user-provided data resides just past the section header.
            char * pUserData = reinterpret_cast<char*>(psect+1);

            // Print a hex dump (for now) of the user-provided data.
            FormatBytes( stdout, pUserData, (int)psect->cbSection, 4 );

            i++;
            if( i >= perrlog->csections )
            {
                // Leave the loop, and do not ConvertSectionHeader().
                break;
            }

            // There's more; point to the next section.
            int cb = psect->cbHeader + psect->cbSection;
            char * p =  (reinterpret_cast<char*>(psect)) + cb;
            psect = reinterpret_cast<section_header_t*>(p);

            // Endian convert it.
            ConvertSectionHeader( psect );
        }
        while( 1 );
    }
}






//-------------------------------------------------------------
int main( int argc,  char *argv[] )
{
    char * pch;
    char * pszImageFile = NULL;
    char * pszSymbolFile = NULL;
    char szWork[ 1024 ];
    unsigned char * puch;
    char * pszSearch;
    char * pszAddr = NULL;
    char * pchBuffer;
    uint32_t ulAddr;
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
    int fDetail = 0;
    int fFound = 0;


    // build a =========== divider for printfing
    cb = 84;
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
              fprintf( stdout, "Provide -d <logid>\n" );
              exit( 2 );
            }
            int c = sscanf( argv[i], "%d", &ulLogId );
            if( c != 1 )
            {
              fprintf( stdout, "Provide -d <decimal log ID>\n" );
              exit( 2 );
            }
            fList = 0;
            fDetail = 1;
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
                pszSymbolFile = strdup( argv[i] );
            }
            else
            {
                pszImageFile = strdup( argv[i] );
            }
        }

        i++;
    }


    // Check args.
    if((!pszImageFile) || (!pszSymbolFile))
    {
        halt( USAGE );
    }



    // Given the symbols file, locate the address/offset of the errl storage
    // buffer.
    ulAddr = FindSymbol( pszSymbolFile, "g_ErrlStorage" );
    if( fVerbose )
    {
        printf( "Error log storage buffer offset: 0x%08x\n", ulAddr );
    }


    // Given the image file, read the portion that contains the
    // error logs.
    pchBuffer = ReadStorageBuffer( pszImageFile, ulAddr, cbBuffer );
    assert( pchBuffer );
    assert( cbBuffer );
    if( fVerbose )
    {
        printf("Errlog storage buffer size: %d (decimal) bytes\n", cbBuffer );
    }


    // Convert the endianess of the storage header.
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
            printf( "%s\n", szDivider );
            break;
        }

        assert( pMarker->length );

        logcount++;

        // Flattened struct of an error log resides just past marker.
        errl_header_t* perr = reinterpret_cast<errl_header_t*>(pMarker+1);
        ConvertErrlHeader( perr );

        if( fList )
        {
            // Just list the error log headers.
            printf( "%s\n", szDivider );
            PrintErrlSummary( perr );
        }
        else if(( fDetail ) && ( perr->logId ==  ulLogId ))
        {
            // Print the detail for the one error log.
            printf( "%s\n", szDivider );
            PrintErrlDetail( perr );
            fFound = 1;
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

