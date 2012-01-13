//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/fapiporeve/fapiPoreVeArg.C $
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
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: fapiPoreVeArg.C,v 1.16 2012/01/09 20:55:57 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/fapiPoreVeArg.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : fapiPoreVeArg.C
// *! DESCRIPTION : Defines the arg struct to pass to fapiPoreVe
// *! OWNER NAME  : Jeshua Smith    Email: jeshua@us.ibm.com
// *! BACKUP NAME : John Bordovsky  Email: johnb@us.ibm.com
// #! ADDITIONAL COMMENTS :
//
//		  

#include "fapiPoreVeArg.H"
#include <fapi.H>

#ifndef __HOSTBOOT_MODULE
//For file mapping
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

//For hooks
#include <dlfcn.h>
#endif

using namespace vsbe;

FapiPoreVeArg::FapiPoreVeArg( const FapiPoreVeArg_t i_type ) :
    iv_type(i_type)
{
}

FapiPoreVeArg::~FapiPoreVeArg( )
{
}

#ifndef __HOSTBOOT_MODULE
FapiPoreVeMemArg::FapiPoreVeMemArg( const FapiPoreVeArg_t   i_type,
                                    const char* const       i_filename,
                                    const uint32_t          i_base ) :
    FapiPoreVeArg(i_type),
    iv_base(i_base),
    iv_filename(i_filename),
    iv_fd(open(i_filename, O_RDONLY)),
    iv_crcEnable(true)
{
    uint32_t rc = 0;

    if( iv_fd < 0 ) {
        FAPI_ERR( "Failed to open %s file\n", iv_filename );
        rc = BAD_ERROR_CODE;
    } else {
        iv_size = lseek( iv_fd, 0, SEEK_END );
        if( iv_size == (size_t)((off_t)-1) ) {
            FAPI_ERR( "Failed to determine the size of %s file\n", iv_filename );
        } else {
            if( (iv_type == ARG_SRAM) || (iv_type == ARG_MAINMEM) ||
                (iv_type == ARG_PNOR) || (iv_type == ARG_SEEPROM) ) {
                iv_data = mmap( 0, iv_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, iv_fd, 0 );
            } else {
                iv_data = mmap( 0, iv_size, PROT_READ, MAP_PRIVATE, iv_fd, 0 );
            }
            if( iv_data == MAP_FAILED ) {
                FAPI_ERR( "Failed to map %s file\n", iv_filename );
                rc = BAD_ERROR_CODE;
            }
        }
    }
    //JDS TODO - how do I make the constructor fail if mapping failed?

}
#endif

FapiPoreVeMemArg::FapiPoreVeMemArg( const FapiPoreVeArg_t   i_type,
                                    const uint32_t          i_base,
                                    const size_t            i_size,
                                    void *                  i_data) :
    FapiPoreVeArg(i_type),
    iv_base(i_base),
#ifndef __HOSTBOOT_MODULE
    iv_filename(NULL),
    iv_fd(0),
#endif
    iv_size(i_size),
    iv_crcEnable(true),
    iv_data(i_data)
{
}

FapiPoreVeMemArg::~FapiPoreVeMemArg( )
{
#ifndef __HOSTBOOT_MODULE
    uint32_t rc = 0;
    if( iv_data != NULL && iv_data != MAP_FAILED && iv_filename != NULL ) {
        int unmap_rc = munmap( iv_data, iv_size );
        if( unmap_rc != 0 ) {
            FAPI_ERR( "Failed to unmap %s file\n", iv_filename );
            rc = BAD_ERROR_CODE;
        }
    }
    if( iv_fd >= 0 ) {
        int close_rc = close( iv_fd );
        if( close_rc != 0 ) {
            FAPI_ERR( "Failed to close %s\n", iv_filename );
            rc = BAD_ERROR_CODE;
        }
    }
#endif
    //JDS TODO - how do I make the destructor fail if unmapping failed?

}

#ifndef __HOSTBOOT_MODULE
FapiPoreVeStateArg::FapiPoreVeStateArg( const char* const i_filename ) :
    FapiPoreVeArg( ARG_STATE ),
    iv_filename(i_filename),
    iv_extractState(true),
    iv_installState(true),
    iv_data(NULL)
{
}
#endif

FapiPoreVeStateArg::FapiPoreVeStateArg( void * i_data ) :
    FapiPoreVeArg( ARG_STATE ),
#ifndef __HOSTBOOT_MODULE
    iv_filename(NULL),
#endif
    iv_extractState(true),
    iv_installState(true),
    iv_data(i_data)
{
}

FapiPoreVeStateArg::~FapiPoreVeStateArg( )
{
}

FapiPoreVeHooksArg::FapiPoreVeHooksArg( const char* const i_filename ) :
    FapiPoreVeArg( ARG_HOOKS ),
    iv_filename(i_filename),
    iv_handle(NULL)
{
}

FapiPoreVeHooksArg::~FapiPoreVeHooksArg( )
{
#ifndef __HOSTBOOT_MODULE
    if( iv_handle != NULL )
    {
        dlclose(iv_handle);
    }
#endif
}

FapiPoreVeOtherArg::FapiPoreVeOtherArg( const uint64_t   i_instructionCount,
                                        const PoreIbufId i_poreType ) :
    FapiPoreVeArg( ARG_OTHER ),
    iv_instructionCount(i_instructionCount),
    iv_poreType(i_poreType),
    iv_pdbgArgs(NULL),
    iv_entryPoint(NULL),
    iv_breakpoint(NULL),
    iv_mrr(0)
{
}

FapiPoreVeOtherArg::~FapiPoreVeOtherArg( )
{
}


/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they are included here.

$Log: fapiPoreVeArg.C,v $
Revision 1.16  2012/01/09 20:55:57  jeshua
Don't include file-related code for hostboot

Revision 1.15  2011/12/07 22:30:59  jeshua
Initial MRR support

Revision 1.14  2011/12/02 16:12:11  jeshua
Make seeprom writable (for control bits)

Revision 1.13  2011/11/17 18:20:05  jeshua
Skip file handling for hostboot

Revision 1.12  2011/09/20 15:38:42  jeshua
Allow creating memory args from memory pointers instead of just files

Revision 1.11  2011/09/02 20:54:29  jeshua
No longer do file open and close

Revision 1.10  2011/09/02 20:01:04  jeshua
Fixes for state arg support

Revision 1.9  2011/07/13 19:13:43  jeshua
Enabled writing of the PNOR at John B's request

Revision 1.8  2011/07/12 16:39:38  jeshua
Breakpoint support

Revision 1.7  2011/07/08 23:53:16  jeshua
Updated for FAPI changes

Revision 1.6  2011/07/07 20:34:43  jeshua
Moved entry point from hooks to other arg

Revision 1.5  2011/06/03 15:38:50  jeshua
Added pdbgArg to OtherArg type

Revision 1.4  2011/05/20 14:05:10  jeshua
Don't close hooks file if it wasn't opened

Revision 1.3  2011/05/20 13:57:48  jeshua
Added const
Use initializers
Unload hooks on destruction

Revision 1.2  2011/05/13 21:19:42  jeshua
Updated comments
Renamed InstructionCountArg to OtherArg, and added PORE type into it
Added iv_extractState
Added Hooks class

Revision 1.1  2011/05/11 19:57:29  jeshua
Initial version




*/
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
