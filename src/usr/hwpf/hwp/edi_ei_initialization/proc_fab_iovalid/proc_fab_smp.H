//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/edi_ei_initialization/proc_fab_iovalid/proc_fab_smp.H $
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
// $Id: proc_fab_smp.H,v 1.2 2012/03/19 03:18:39 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_fab_smp.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_fab_smp.H
// *! DESCRIPTION : Common fabric structure defintions/utility functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
// *! ADDITIONAL COMMENTS:
// *!
// *! Define interface structures which pass SMP connectivity information
// *! between platform and FAPI HWP code.
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_FAB_SMP_H_
#define _PROC_FAB_SMP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// define set of supported X busses
enum proc_fab_smp_x_bus_id
{
    FBC_BUS_X0 = 0,
    FBC_BUS_X1 = 1,
    FBC_BUS_X2 = 2,
    FBC_BUS_X3 = 3
};

// define set of supported A busses
enum proc_fab_smp_a_bus_id
{
    FBC_BUS_A0 = 0,
    FBC_BUS_A1 = 1,
    FBC_BUS_A2 = 2
};

// encapsulate X bus connectivity information (relative to source chip):
//   source bus ID
//   destination bus ID, pointer to destination target
struct proc_fab_smp_x_bus
{
    proc_fab_smp_x_bus_id src_chip_bus_id;
    fapi::Target*         dest_chip;
    proc_fab_smp_x_bus_id dest_chip_bus_id;
};

// encapsulate A bus connectivity information (relative to source chip):
//   source bus ID
//   destination bus ID, and pointer to destination target
struct proc_fab_smp_a_bus
{
    proc_fab_smp_a_bus_id src_chip_bus_id;
    fapi::Target*         dest_chip;
    proc_fab_smp_a_bus_id dest_chip_bus_id;
};

// structure to document target/fabric connectivity for a single chip
// in the SMP topology
struct proc_fab_smp_proc_chip
{
    // target associated with this chip
    fapi::Target this_chip;
    // X bus connections
    std::vector<proc_fab_smp_x_bus*> x_busses;
    // A bus connections
    std::vector<proc_fab_smp_a_bus*> a_busses;
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

// function: validate & display SMP topology
// parameters: i_smp => vector of proc_fab_smp_chip structures which
//                      defines scope of SMP fabric & bus connectivity
// returns: FAPI_RC_SUCCESS if topology is valid,
//          RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_PROC_CHIP_ARG
//              if invalid/NULL proc_fab_smp_proc_chip argument is passed
//              in HWP argument vector
//          RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_A_BUS_ARG
//              if invalid/NULL proc_fab_smp_a_bus argument is passed
//              in HWP argument vector
//          RC_PROC_FAB_SMP_INVALID_PROC_FAB_SMP_X_BUS_ARG
//              if invalid/NULL proc_fab_smp_x_bus argument is passed
//              in HWP argument vector
//          else FAPI getscom/putscom return code for failing operation
fapi::ReturnCode proc_fab_smp_validate_smp(
    std::vector<proc_fab_smp_proc_chip *>& i_smp);

} // extern "C"

#endif // _PROC_FAB_SMP_H_
