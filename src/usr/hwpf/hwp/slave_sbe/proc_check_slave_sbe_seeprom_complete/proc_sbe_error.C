/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/proc_check_slave_sbe_seeprom_complete/proc_sbe_error.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// -*- mode: C++; c-file-style: "linux";  -*-
// $Id: proc_sbe_error.C,v 1.2 2012/10/29 22:08:10 jeshua Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_sbe_error.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_sbe_error.C
// *! DESCRIPTION : Return a fapi::ReturnCode for the passed in rc
// *!
// *! OWNER NAME  : Jeshua Smith            Email: jeshua@us.ibm.com
// *!
// *! ***** IMPORTANT *****
// *!  This procedure is going to be replaced with a fapi call once the fapi
// *!  call exists!
// *!
// *! Overview:
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#ifdef FAPIECMD
// Including these first so we get the local, up-to-date copy that matches the
// fapiHwpErrorGen.H file from the SBE build that we include later
#include "../sbe/fapiHwpReturnCodes.H"
#include "../sbe/fapiHwpErrorInfo.H"
#endif

#include "proc_sbe_error.H"

//------------------------------------------------------------------------------
// Macro definitions
//------------------------------------------------------------------------------
#define GENERATE(RC) \
        case RC: \
            FAPI_SET_HWP_ERROR(rc, RC);\
            break;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C"
{


//------------------------------------------------------------------------------
// function:
//      Call the error handler for the specified rc
//
// parameters: i_target  => failing chip target
//             i_rc      => failing chip rc
// returns: fapi::ReturnCode with the error
//------------------------------------------------------------------------------
    fapi::ReturnCode proc_sbe_error(const fapi::Target & i_target,
                                    uint32_t i_rc)
    {
        // return codes
        fapi::ReturnCode rc;

        // generics for FFDC
        const fapi::Target & CHIP_IN_ERROR = i_target;
        uint32_t & ERROR_CODE = i_rc;

        FAPI_ERR("Processing SBE error code 0x%08X\n", i_rc);

        switch( i_rc ) {
#ifdef FAPIECMD
            //Include the specific errors in Cronus environment, let FW
            //just use the default for all errors for now.
            #include "../sbe/fapiHwpErrorGen.H"
#endif
        default:
            FAPI_SET_HWP_ERROR(rc, RC_SBE_UNKNOWN_ERROR);
            break;
        }

        return rc;
    }

} // extern "C"
/* Local Variables: */
/* c-basic-offset: 4 */
/* End: */
