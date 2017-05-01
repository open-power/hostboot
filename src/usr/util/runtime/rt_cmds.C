/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/rt_cmds.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

#include <runtime/interface.h>
#include <stdio.h>
#include <trace/interface.H>
#include <string.h>
#include "../utilbase.H"
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/predicates/predicateattrval.H>
#include <targeting/common/iterators/rangefilter.H>
#include <pnor/pnorif.H>
#include <devicefw/userif.H>
#include <util/util_reasoncodes.H>
#include <errl/errlmanager.H>


namespace Util
{

/**
 * @brief Poor-man's version of strtoul, see man page
 */
uint64_t strtou64(const char *nptr, char **endptr, int base)
{
    uint64_t l_data = 0;
    size_t i = 0;
    while( nptr[i] != '\0' )
    {
        uint64_t l_nib = 0;
        switch(nptr[i])
        {
            // handle leading '0x' or 'x'
            case('x'): case('X'):
                l_data = 0;
                break;
            case('0'): l_nib = 0; break;
            case('1'): l_nib = 1; break;
            case('2'): l_nib = 2; break;
            case('3'): l_nib = 3; break;
            case('4'): l_nib = 4; break;
            case('5'): l_nib = 5; break;
            case('6'): l_nib = 6; break;
            case('7'): l_nib = 7; break;
            case('8'): l_nib = 8; break;
            case('9'): l_nib = 9; break;
            case('A'): case('a'): l_nib = 0xA; break;
            case('B'): case('b'): l_nib = 0xB; break;
            case('C'): case('c'): l_nib = 0xC; break;
            case('D'): case('d'): l_nib = 0xD; break;
            case('E'): case('e'): l_nib = 0xE; break;
            case('F'): case('f'): l_nib = 0xF; break;
            default:
                UTIL_FT( "strtou64> nptr=%s, nptr[%d]=%c", nptr, i, nptr[i] );
                return 0xDEADBEEF;
        }
        l_data <<= 4;
        l_data |= l_nib;
        i++;
    }
    return l_data;
}


/**
 * @brief Fetch a target by HUID
 * @param[in] i_huid  HUID to translate
 * @return  Target Pointer, NULL if no match found
 */
TARGETING::Target* getTargetFromHUID( uint32_t i_huid )
{
    TARGETING::PredicateAttrVal<TARGETING::ATTR_HUID> l_huidMatches(i_huid);
    TARGETING::TargetRangeFilter l_targetsWithHuid(
        TARGETING::targetService().begin(),
        TARGETING::targetService().end(),
        &l_huidMatches);
    if(l_targetsWithHuid)
    {
        return *l_targetsWithHuid;
    }
    else
    {
        UTIL_FT( "bad huid - %.8X!", i_huid );
        return NULL;
    }
}


/**
 * @brief Read the value of an attribute by name
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_huid  HUID associated with Target to get attribute from
 * @param[in] i_attrId  Hash of attribute to read
 * @param[in] i_size  Size of attribute data in bytes
 */
void cmd_getattr( char*& o_output,
                  uint32_t i_huid,
                  uint32_t i_attrId,
                  uint32_t i_size )
{
    UTIL_FT( "cmd_getattr> huid=%.8X, attr=%.8X, size=%d",
             i_huid, i_attrId, i_size );

    TARGETING::Target* l_targ = getTargetFromHUID(i_huid);
    if( l_targ == NULL )
    {
        o_output = new char[100];
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    uint8_t l_data[i_size];
    bool l_try = l_targ->_tryGetAttr( (TARGETING::ATTRIBUTE_ID)i_attrId,
                                      i_size, l_data );
    if( !l_try )
    {
        o_output = new char[100];
        sprintf( o_output, "Error reading %.8X", i_attrId );
        return;
    }

    // "Targ[12345678] Attr[12345678] = 0x12345678...\n"
    o_output = new char[50 + i_size*2];
    if( i_size == 1 )
    {
        uint8_t* l_data8 = (uint8_t*)(l_data);
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x%.2X\n",
                 i_huid, i_attrId, *l_data8 );
    }
    else if( i_size == 2 )
    {
        uint16_t* l_data16 = (uint16_t*)(l_data);
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x%.4X\n",
                 i_huid, i_attrId, *l_data16 );
    }
    else if( i_size == 4 )
    {
        uint32_t* l_data32 = (uint32_t*)(l_data);
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x%.8X\n",
                 i_huid, i_attrId, *l_data32 );
    }
    else if( i_size == 8 )
    {
        uint64_t* l_data64 = (uint64_t*)(l_data);
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x%.8X%.8X\n",
                 i_huid, i_attrId, (uint32_t)(*l_data64>>32),
                 (uint32_t)*l_data64 );
    }
    else // give up on pretty-printing and just dump the hex
    {
        sprintf( o_output, "Targ[%.8X] Attr[%.8X] = 0x", i_huid, i_attrId );
        size_t l_len1 = strlen(o_output);
        for( size_t i=0; i<i_size; i++ )
        {
            sprintf( &(o_output[l_len1+i]), "%.2X", l_data[i] );
        }
        o_output[l_len1+i_size*2] = '-';
        o_output[l_len1+i_size*2+1] = '\n';
        o_output[l_len1+i_size*2+2] = '\0';
    }
}

/**
 * @brief Read data out of pnor
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_section  PNOR section id
 * @param[in] i_bytes  Number of bytes to read
 */
void cmd_readpnor( char*& o_output,
                   uint32_t i_section,
                   uint32_t i_bytes )
{
    UTIL_FT( "cmd_readpnor> section=%d, bytes=%d", i_section, i_bytes );

    PNOR::SectionInfo_t l_pnor;
    errlHndl_t l_errhdl = PNOR::getSectionInfo( (PNOR::SectionId)i_section,
                                                l_pnor );
    if( l_errhdl )
    {
        UTIL_FT( "cmd_readpnor> Error from getSectionInfo()" );
        o_output = new char[100];
        sprintf( o_output, "Error from getSectionInfo()" );
        delete l_errhdl;
        return;
    }

    o_output = new char[50 + i_bytes*2];
    sprintf( o_output, "PNOR[%d] : name=%s, size=0x%X = 0x",
             i_section, l_pnor.name, l_pnor.size );
    uint8_t* l_ptr = (uint8_t*)l_pnor.vaddr;
    size_t l_len1 = strlen(o_output);
    for( size_t i=0; i<i_bytes; i++ )
    {
        sprintf( &(o_output[l_len1+2*i]), "%.2X", l_ptr[i] );
    }
    o_output[l_len1+i_bytes*2] = '-';
    o_output[l_len1+i_bytes*2+1] = '\n';
    o_output[l_len1+i_bytes*2+2] = '\0';

    UTIL_FT( "PNOR[%d] : name=%s, size=0x%X = 0x",
             i_section, l_pnor.name, l_pnor.size );
    TRACFBIN( Util::g_util_trace, "PNOR", l_ptr, i_bytes );
}


/**
 * @brief Read a scom register
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_huid  Target to read scom from
 * @param[in] i_addr  Scom address
 */
void cmd_getscom( char*& o_output,
                  uint32_t i_huid,
                  uint64_t i_addr )
{
    UTIL_FT( "cmd_getscom> huid=%.8X, addr=%X%.8X",
             i_huid, (uint32_t)(i_addr>>32), (uint32_t)i_addr );
    o_output = new char[100];

    TARGETING::Target* l_targ = getTargetFromHUID(i_huid);
    if( l_targ == NULL )
    {
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    uint64_t l_data = 0;
    size_t l_size = sizeof(uint64_t);
    errlHndl_t l_errhdl = deviceRead(l_targ,
                                     &l_data,
                                     l_size,
                                     DEVICE_SCOM_ADDRESS(i_addr));
    if( l_errhdl )
    {
        sprintf( o_output, "cmd_getscom> FAIL: RC=%.4X",
                 ERRL_GETRC_SAFE(l_errhdl) );
        return;
    }
    else
    {
        sprintf( o_output, "HUID=%.8X Addr=%X%.8X, Data=%.8X %.8X",
                 i_huid, (uint32_t)(i_addr>>32), (uint32_t)i_addr,
                 (uint32_t)(l_data>>32), (uint32_t)l_data );
        return;
    }
}


/**
 * @brief Write a scom register
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_huid  Target to read scom from
 * @param[in] i_addr  Scom address
 * @param[in] i_data  Scom data to write
 */
void cmd_putscom( char*& o_output,
                  uint32_t i_huid,
                  uint64_t i_addr,
                  uint64_t i_data )
{
    UTIL_FT( "cmd_putscom> huid=%.8X, addr=%X%.8X, data=%.8X %.8X",
             i_huid, (uint32_t)(i_addr>>32), (uint32_t)i_addr,
             (uint32_t)(i_data>>32), (uint32_t)i_data );
    o_output = new char[100];

    TARGETING::Target* l_targ = getTargetFromHUID(i_huid);
    if( l_targ == NULL )
    {
        sprintf( o_output, "HUID %.8X not found", i_huid );
        return;
    }

    size_t l_size = sizeof(uint64_t);
    errlHndl_t l_errhdl = deviceWrite( l_targ,
                                       &i_data,
                                       l_size,
                                       DEVICE_SCOM_ADDRESS(i_addr));
    if( l_errhdl )
    {
        sprintf( o_output, "cmd_putscom> FAIL: RC=%.4X",
                 ERRL_GETRC_SAFE(l_errhdl) );
        return;
    }
    else
    {
        sprintf( o_output, "HUID=%.8X Addr=%X%.8X",
                 i_huid, (uint32_t)(i_addr>>32), (uint32_t)i_addr );
        return;
    }
}


/**
 * @brief Create and commit an error log
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_word1  Userdata 1 & 2
 * @param[in] i_word2  Userdata 3 & 4
 * @param[in] i_callout  HUID of target to callout (zero if none)
 */
void cmd_errorlog( char*& o_output,
                   uint64_t i_word1,
                   uint64_t i_word2,
                   uint32_t i_callout )
{
    UTIL_FT( "cmd_errorlog> word1=%.8X%.8X, word2=%.8X%.8X, i_callout=%.8X",
             (uint32_t)(i_word1>>32), (uint32_t)i_word1,
             (uint32_t)(i_word2>>32), (uint32_t)i_word2, i_callout );
    o_output = new char[100];

    errlHndl_t l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                                Util::UTIL_RT_CMDS,
                                                Util::UTIL_ERC_NONE,
                                                i_word1,
                                                i_word2,
                                                false );
    TARGETING::Target* l_targ = getTargetFromHUID(i_callout);
    if( l_targ != NULL )
    {
        l_err->addHwCallout( l_targ,
                             HWAS::SRCI_PRIORITY_HIGH,
                             HWAS::NO_DECONFIG,
                             HWAS::GARD_NULL );
    }
    l_err->collectTrace("UTIL", 1024);
    uint32_t l_plid = l_err->plid();
    errlCommit(l_err, UTIL_COMP_ID);
    sprintf( o_output, "Committed plid 0x%.8X", l_plid );
}


/**
 * @brief Process an SBE Message with a pass-through request
 * @param[out] o_output  Output display buffer, memory allocated here
 * @param[in] i_chipId   Processor chip ID
 */
void cmd_sbemsg( char*& o_output,
                 uint32_t i_chipId)
{
    UTIL_FT( "cmd_sbemsg> chipId=%.8X",
             i_chipId);
    o_output = new char[100];

    int rc = 0;

    do
    {
        // Get the runtime interface object
        runtimeInterfaces_t *l_rt_intf = getRuntimeInterfaces();
        if(nullptr == l_rt_intf)
        {
            rc = -2;
            sprintf( o_output, "Not able to get run time interface object");
            return;
        }

        rc = l_rt_intf->sbe_message_passing(i_chipId);
        if(0 != rc)
        {
            sprintf( o_output, "Unexpected return from RT SBE message passing. "
                     "Return code: 0x%.8X for chipID: 0x%.8X", rc, i_chipId);
            return;
        }
    }while (0);

    sprintf( o_output, "SBE message passing command for chipID 0x%.8X returned "
                       "rc 0x%.8X", i_chipId, rc );
}


/**
 * @brief  Execute an arbitrary command inside Hostboot Runtime
 * @param[in]   Number of arguments (standard C args)
 * @param[in]   Array of argument values (standard C args)
 * @param[out]  Response message (NULL terminated), memory allocated
 *              by hbrt, if o_outString is NULL then no response will
 *              be sent
 * @return 0 on success, else error code
 */
int hbrtCommand( int argc,
                 const char** argv,
                 char** o_outString )
{
    int rc = 0;
    UTIL_FT("Executing run_command : argc=%d, o_outString=%p",
                argc, o_outString);

    if( !argc )
    {
        UTIL_FT("run_command : Number of arguments = 0");
        return rc;
    }

    if( argv == NULL )
    {
        UTIL_FT("run_command : Argument array is empty");
        return rc;
    }

    for( int aa=0; aa<argc; aa++ )
    {
        UTIL_FT("run_command : %d='%s'",aa,argv[aa]);
    }

    // If no output is specified, trace it instead
    bool l_traceOut = false;
    char* l_outPtr = NULL; //local value to use if needed
    char** l_output = o_outString;
    if( o_outString == NULL )
    {
        l_output = &l_outPtr;
        l_traceOut = true;
    }

    // Test path
    if( (argc == 2) && !strcmp( argv[0], "testRunCommand" ) )
    {
        *l_output = new char[strlen(argv[1])+1+5];//arg0+arg1+\0
        sprintf( *l_output, "TEST:%s", argv[1] );
    }
    else if( !strcmp( argv[0], "getattr" ) )
    {
        // getattr <huid> <attribute id> <size>
        if( argc == 4 )
        {
            cmd_getattr( *l_output,
                         strtou64( argv[1], NULL, 16 ),
                         strtou64( argv[2], NULL, 16 ),
                         strtou64( argv[3], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output,
                     "ERROR: getattr <huid> <attribute id> <size>\n" );
        }
    }
    else if( !strcmp( argv[0], "readpnor" ) )
    {
        // readpnor <pnor section> <bytes to read>
        if( argc == 3 )
        {
            cmd_readpnor( *l_output,
                          strtou64( argv[1], NULL, 16 ),
                          strtou64( argv[2], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output,
                     "ERROR: getpnor <pnor section> <bytes to read>\n" );
        }
    }
    else if( !strcmp( argv[0], "getscom" ) )
    {
        // getscom <huid> <address>
        if( argc == 3 )
        {
            cmd_getscom( *l_output,
                         strtou64( argv[1], NULL, 16 ),
                         strtou64( argv[2], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output, "ERROR: getscom <huid> <address>\n" );
        }
    }
    else if( !strcmp( argv[0], "putscom" ) )
    {
        // putscom <huid> <address> <data>
        if( argc == 4 )
        {
            cmd_putscom( *l_output,
                         strtou64( argv[1], NULL, 16 ),
                         strtou64( argv[2], NULL, 16 ),
                         strtou64( argv[3], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output, "ERROR: putscom <huid> <address> <data>\n" );
        }
    }
    else if( !strcmp( argv[0], "errorlog" ) )
    {
        // errorlog <word1> <word2> <huid to callout>
        if( (argc == 3) || (argc == 4) )
        {
            uint32_t l_huid = 0;
            if( argc == 4 )
            {
                l_huid = strtou64( argv[3], NULL, 16 );
            }
            cmd_errorlog( *l_output,
                          strtou64( argv[1], NULL, 16 ),
                          strtou64( argv[2], NULL, 16 ),
                          l_huid );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output, "ERROR: errorlog <word1> <word2>\n" );
        }
    }
    else if( !strcmp( argv[0], "sbemsg" ) )
    {
        // sbemsg <chipid>
        if( argc == 2 )
        {
            cmd_sbemsg( *l_output,
                         strtou64( argv[1], NULL, 16 ) );
        }
        else
        {
            *l_output = new char[100];
            sprintf( *l_output, "ERROR: sbemsg <chipid>\n" );
        }
    }
    else
    {
        *l_output = new char[50+100*6];
        char l_tmpstr[100];
        sprintf( *l_output, "HBRT Commands:\n" );
        sprintf( l_tmpstr, "testRunCommand <args...>\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "getattr <huid> <attribute id> <size>\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "readpnor <pnor section> <bytes to read>\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "getscom <huid> <address>\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "putscom <huid> <address> <data>\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "errorlog <word1> <word2> [<huid to callout>]\n" );
        strcat( *l_output, l_tmpstr );
        sprintf( l_tmpstr, "sbemsg <chipid>\n" );
        strcat( *l_output, l_tmpstr );
    }

    if( l_traceOut && (*l_output != NULL) )
    {
        UTIL_FT("Output::%s",*l_output);
        delete *l_output;
    }

    return rc;
}

};

struct registerCmds
{
    registerCmds()
    {
        getRuntimeInterfaces()->run_command = &Util::hbrtCommand;
    }
};

registerCmds g_registerCmds;


