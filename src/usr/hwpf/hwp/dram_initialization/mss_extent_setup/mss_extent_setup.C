/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/mss_extent_setup/mss_extent_setup.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
//Owner :- Girisankar paulraj
//Back-up owner :- Mark bellows
//
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//  1.7    | bellows  |15-Jun-12| Updated for Firmware
//  1.3    | gpaulraj |11-Nov-11| modified according HWPF format
//  1.2    | gpaulraj |02-oct-11| supported for MCS loop - SIM model. compiled in the ecmd & FAPI calls included.
//  1.1    | gpaulraj |31-jul-11| First drop for centaur
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
//#include <prcdUtils.H>
//#include <verifUtils.H>
//#include <cen_maintcmds.H>
#include <mss_extent_setup.H>
//----------------------------------------------------------------------
//  eCMD Includes
//----------------------------------------------------------------------
//#include <ecmdClientCapi.H>
//#include <ecmdDataBuffer.H>
//#include <ecmdUtils.H>
//#include <ecmdSharedUtils.H>
//#include <fapiClientCapi.H>
//#include <croClientCapi.H>
//#include <fapi.H>
//#include <fapiSystemConfig.H> 
//#include <fapiSharedUtils.H>
// attributes listing
// FAPI procedure calling
//
extern "C" {

using namespace fapi;


ReturnCode mss_extent_setup(){

    ReturnCode rc;
	    if(rc){
		FAPI_ERR(" Calling Extent function Error ");
		return rc;
	    }
    return rc;
}


} //end extern C

