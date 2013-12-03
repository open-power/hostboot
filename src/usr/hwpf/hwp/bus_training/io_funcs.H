/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_funcs.H $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: io_funcs.H,v 1.16 2013/11/25 07:10:39 varkeykv Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : IO_funcs.H
// *! TITLE                : 
// *! DESCRIPTION          : IO training comomon functions
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Varghese, Varkey         Email: varkey.kv@in.ibm.com
// *! BACKUP NAME          : Vijay S Kantanavar      Email: vijaysk@in.ibm.com      
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.0   |varkeykv|11/17/11| Combined other header files into one common file
//------------------------------------------------------------------------------

/****************************************************************************************/
/* IO_funcs.H                                                                           */
/****************************************************************************************/
#ifndef IO_funcs
#define IO_funcs
#include <fapi.H>
#include "gcr_funcs.H"
#include "io_clear_firs.H"

using namespace fapi;
	// Bus Status State
	typedef enum {  NOT_RUNNING, SELECTED,  RUNNING,   SUCCESSFULL  ,
        FAILED} bus_status;

class edi_training {
public:
	
	// Training enums for Wire test , Deskew , Eye Opt ,Repair , Functional   ---
	typedef   enum {  WIRE_TEST ,  DESKEW ,  EYE_OPT ,  REPAIR , FUNCTIONAL
                                           , TRAINING_TYPES} training_function;

    // Selection
	bus_status    wire_test_selected;
	bus_status    desckew_selected;
	bus_status    eye_opt_selected;
	bus_status    repair_selected;
	bus_status    functional_selected;

    // Current Training States
	bus_status    wire_test_status;
	bus_status    desckew_status;
	bus_status    eye_opt_status;
	bus_status    repair_status;
	bus_status    functional_status;
        //Updating max cycles to suit 280ms theoretical max timeout as per Mike Spear
	static const uint32_t      max_poll_cycles=1000;
	static const uint32_t      increment_poll_cycles=1;
	uint32_t endpoints_set; // How many end points have we accessed so far

	bool		          rx_wderf_timeout[6];   // Summary 5 bit timout  status
	bool		          rx_wderf_start[6];     // Summary 5 bit status
	bool		          rx_wderf_done[6];      // Summary 5 bit done
	bool		          rx_wderf_failed[6];    // Summary 5 bit failed

	// Constructor Initializes default states for status variables
    edi_training( bus_status wire_test=SELECTED,bus_status deskew=SELECTED,bus_status eye_opt=SELECTED,bus_status repair=SELECTED,bus_status functional=SELECTED)
    {
        wire_test_selected     =       wire_test;
        desckew_selected       =       deskew;
        eye_opt_selected       =       eye_opt;
        repair_selected        =       repair;
        functional_selected    =       functional;

        wire_test_status        =     wire_test;
        desckew_status          =     deskew;
        eye_opt_status          =     eye_opt;
        repair_status           =     repair;
        functional_status       =     functional;
        
        for(int i=0;i<6;++i)
        {
                rx_wderf_timeout[i]=false;
                rx_wderf_start[i]=false;
                rx_wderf_done[i]=false;
                rx_wderf_failed[i]=false;
        }
        endpoints_set=0; // reset this for multi endpoint pair runs
    } 
	
	//! Destructor
	~edi_training() {
        } 

    //  Training Functions
    // Run Wirtest,Deskew,Repair and Functional mode on selected target(endpoint) pair
    ReturnCode  run_training(const Target& master_target,  io_interface_t
                             master_interface,uint32_t master_group,const Target&  slave_target,
			     io_interface_t slave_interface,uint32_t slave_group);
    // Runs the selected training function(s)
    ReturnCode  run_training_functions(const Target&  target,
                                       io_interface_t interface,uint32_t current_group);
   // Checks the status of the training selected function(s)
    ReturnCode  training_function_status(const Target& master_target,
                                         io_interface_t master_interface,uint32_t master_group,
                                         const Target& slave_target,
                                         io_interface_t slave_interface,uint32_t slave_group
                                          );

    // First Fail Data Capture Routines
    // Wire Test First Fail Data Capture
    ReturnCode dump_ffdc_wiretest(const Target&  master_chip_target,
                                  io_interface_t  master_chip_interface ,
				  uint32_t master_group,
                                  const Target& slave_chip_target ,
                                  io_interface_t slave_chip_interface,
				  uint32_t slave_group
                                  );

    // Utility functions
    // Determines if target chip is a Master (reads rx_master_mode bit)
    ReturnCode isChipMaster(const Target& target, io_interface_t interface,uint32_t current_group,
                            bool& master_chip_found
                            );
        
};






/* functions */
#endif
