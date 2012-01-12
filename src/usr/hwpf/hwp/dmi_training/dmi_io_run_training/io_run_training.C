//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/HWPs/dmi_training/dmi_io_run_training/io_run_training.C $
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
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : io_run_training.C
// *! TITLE                : 
// *! DESCRIPTION          : IO Wiretest,Deskew ,Eye Opt training procedure
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
//   1.0   |varkeykv|09/27/11|Initial check in . Have to modify targets once bus target is defined and available.Not tested in any way other than in unit SIM IOTK
//   1.1   |varkeykv|11/16/11|Fixed header files & dependencies
//------------------------------------------------------------------------------
#define EDI_IO

#include <fapi.H>
#include "io_run_training.H"


extern "C" {
     using namespace fapi;
// These functions work on a pair of targets. One is the master side of the bus interface, the other the slave side. For eg; in EDI(DMI2)PU is the master and Centaur is the slave
// In EI4 both sides have pu targets . After the talk with Dean , my understanding is that targets are configured down upto the endpoints of a particular bus. eg; pu 0 A0 --> pu 1 A3 could be a combination on EI4
// In a EDI(DMI) bus the targets are considered to be one pu and one centaur pair . The overall code is same for EDI and EI4 and the run_training function handles both bus types ( X ,A or MC ) . 
ReturnCode io_run_training(const Target &master_target,io_interface_t master_interface,uint32_t master_group,const Target &slave_target,io_interface_t slave_interface,uint32_t slave_group){
     ReturnCode rc;
     edi_training init;

     FAPI_DBG("io_run_training:Running training on interface %d on master side and %d on slave side with master_group set to %d and slave group=%d",master_interface,slave_interface,master_group,slave_group);
     
     rc=init.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
       
     return rc;
}



} // extern 
