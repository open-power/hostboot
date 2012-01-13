//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pore/fapiporeve/fapiPoreVeArg.H $
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
// $Id: fapiPoreVeArg.H,v 1.11 2011/12/07 22:31:39 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/fapiPoreVeArg.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
//------------------------------------------------------------------------------
// *! TITLE : fapiPoreVeArg.H
// *! DESCRIPTION : Headers for the args to pass to fapiPoreVe
// *! OWNER NAME  : Jeshua Smith    Email: jeshua@us.ibm.com
// *! BACKUP NAME : John Bordovsky  Email: johnb@us.ibm.com
// #! ADDITIONAL COMMENTS :
//
//		  

#ifndef __FAPIPOREVEARG_H
#define __FAPIPOREVEARG_H

#include "poreconstants.H"

namespace vsbe
{

    enum FapiPoreVeArg_t
    {
        ARG_STATE,
        ARG_OTHER,
        ARG_HOOKS,
        ARG_OTPROM,
        ARG_PNOR,
        ARG_SEEPROM,
        ARG_SRAM,
        ARG_MAINMEM,
    };

    const uint32_t BAD_ERROR_CODE = 0xDEADC0DE;

    struct FapiPoreVeArg
    {
    public:
        FapiPoreVeArg( const FapiPoreVeArg_t i_type );
        
        virtual ~FapiPoreVeArg();
        
        const FapiPoreVeArg_t iv_type;
    };

    struct FapiPoreVeMemArg : public FapiPoreVeArg
    {
    public:
#ifndef __HOSTBOOT_MODULE
        FapiPoreVeMemArg( const FapiPoreVeArg_t i_type,
                          const char* const     i_filename,
                          const uint32_t        i_base );
#endif
        FapiPoreVeMemArg( const FapiPoreVeArg_t i_type,
                          const uint32_t        i_base, 
                          const size_t          i_size,
                          void *                i_data );

        ~FapiPoreVeMemArg();
        
        const uint32_t        iv_base;
#ifndef __HOSTBOOT_MODULE
        const char*           iv_filename;
        const int             iv_fd;
#endif
        size_t          iv_size;
        bool            iv_crcEnable;
        void *          iv_data;
    };

    struct FapiPoreVeStateArg : public FapiPoreVeArg
    {
    public:
#ifndef __HOSTBOOT_MODULE
        FapiPoreVeStateArg( const char* const i_filename );
#endif
        FapiPoreVeStateArg( void *            i_data     );

        virtual ~FapiPoreVeStateArg();
        
#ifndef __HOSTBOOT_MODULE
        const char* const iv_filename;
        FILE *            iv_fd;
#endif
        bool              iv_extractState;
        bool              iv_installState;
        void *            iv_data;
    };

    struct FapiPoreVeHooksArg : public FapiPoreVeArg
    {
    public:
        FapiPoreVeHooksArg( const char* const i_filename );

        virtual ~FapiPoreVeHooksArg();
        
        const char* const iv_filename;
        void*             iv_handle;
    };

    struct FapiPoreVeOtherArg : public FapiPoreVeArg
    {
    public:
        FapiPoreVeOtherArg( const uint64_t   i_instructionCount,
                            const PoreIbufId i_poreType );

        virtual ~FapiPoreVeOtherArg();
        
        uint64_t          iv_instructionCount;
        PoreIbufId        iv_poreType;
        const char*       iv_pdbgArgs;
        char*             iv_entryPoint;
        char*             iv_breakpoint;
        uint64_t          iv_mrr;
    };
} //end vsbe namespace

#endif
    
/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they are included here.

$Log: fapiPoreVeArg.H,v $
Revision 1.11  2011/12/07 22:31:39  jeshua
Initial MRR support

Revision 1.10  2011/11/17 18:21:10  jeshua
Skip file handling for hostboot
Keep a pointer to raw state data in the state arg

Revision 1.9  2011/09/20 15:39:06  jeshua
Allow creating memory args from pointers instead of just files

Revision 1.8  2011/09/02 19:57:45  jeshua
Updates for state install & extract support

Revision 1.7  2011/08/03 23:01:47  bcbrock
Update fapiPoreVeArg.H to use the new 'poreconstants.H'

Revision 1.6  2011/07/12 16:39:39  jeshua
Breakpoint support

Revision 1.5  2011/07/07 20:34:59  jeshua
Moved entry point from hooks to other arg

Revision 1.4  2011/06/03 15:38:04  jeshua
Added pdbgArgs to OtherArg type

Revision 1.3  2011/05/20 13:54:51  jeshua
Changed to struct
Added const
Added entryPoint
Removed dead code

Revision 1.2  2011/05/13 21:15:22  jeshua
Updated comments
Renamed InstructionCountArg to OtherArg, and added PORE type into it
Added iv_extractState
Added Hooks class

Revision 1.1  2011/05/11 19:57:30  jeshua
Initial version




*/
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
