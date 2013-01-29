/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_run_training.C $             */
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
// $Id: io_run_training.C,v 1.28 2013/01/28 20:19:06 jaswamin Exp $
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
// *! BACKUP NAME          : Janani Swaminathan      Email:  jaswamin@in.ibm.com     
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//  1.27   |jaswamin|01/28/13|Changed fatal errors to warning prints to allow training to continue
//   1.0   |varkeykv|09/27/11|Initial check in . Have to modify targets once bus target is defined and available.Not tested in any way other than in unit SIM IOTK
//   1.1   |varkeykv|11/16/11|Fixed header files & dependencies
//------------------------------------------------------------------------------
#include <fapi.H>
#include "io_run_training.H"
#include "io_funcs.H"

extern "C" {
     using namespace fapi;
// These functions work on a pair of targets. One is the master side of the bus interface, the other the slave side. For eg; in EDI(DMI2)PU is the master and Centaur is the slave
// In EI4 both sides have pu targets . After the talk with Dean , my understanding is that targets are configured down upto the endpoints of a particular bus. eg; pu 0 A0 --> pu 1 A3 could be a combination on EI4
// In a EDI(DMI) bus the targets are considered to be one pu and one centaur pair . The overall code is same for EDI and EI4 and the run_training function handles both bus types ( X ,A or MC ) . 
ReturnCode io_run_training(const Target &master_target,const Target &slave_target){
     ReturnCode rc;
     io_interface_t master_interface,slave_interface;
     uint32_t master_group=0;
     uint32_t slave_group=0;
     edi_training init;
     // Workaround - HW 220654 -- Need to split WDERF into WDE + RF
     edi_training init1(SELECTED,SELECTED,SELECTED, NOT_RUNNING, NOT_RUNNING); // Run WDE first
     edi_training init2( NOT_RUNNING, NOT_RUNNING, NOT_RUNNING,SELECTED,SELECTED); // Run RF next
     bool is_master=false;
     // This is a DMI/MC bus 
     if( (master_target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET )&& (slave_target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP)){
          FAPI_DBG("This is a DMI bus using base DMI scom address");
          master_interface=CP_IOMC0_P0; // base scom for MC bus
          slave_interface=CEN_DMI; // Centaur scom base
          master_group=3; // Design requires us to do this as per scom map and layout
          slave_group=0;
          // Workaround - HW 220654 -- Need to split WDERF into WDE + RF due to sync problem
          rc=init1.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
          if(rc){
               return rc;
          }
          rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
     }
     //This is an X Bus
     else if( (master_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT  )&& (slave_target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT )){
          FAPI_DBG("This is a X Bus training invocation");
          master_interface=CP_FABRIC_X0; // base scom for X bus
          slave_interface=CP_FABRIC_X0; // base scom for X bus
          master_group=0; // Design requires us to do this as per scom map and layout
          slave_group=0;
          rc=init.isChipMaster(master_target,master_interface,master_group,is_master);
          if(rc.ok()){
               if(!is_master){
                     //Swap master and slave targets !!
                     FAPI_DBG("X Bus ..target swap performed");
                    rc=init1.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    if(rc) return rc;
                    rc=init2.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
	       }
               else{
                    rc=init1.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                    if(rc) return rc;
                    rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
               }
          }
     }
     //This is an A Bus
     else if( (master_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT )&& (slave_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT)){
          FAPI_DBG("This is an A Bus training invocation");
          master_interface=CP_FABRIC_A0; // base scom for A bus , assume translation to A1 by PLAT 
          slave_interface=CP_FABRIC_A0; //base scom for A bus
          master_group=0; // Design requires us to do this as per scom map and layout
          slave_group=0;
          rc=init.isChipMaster(master_target,master_interface,master_group,is_master);
          if(rc.ok()){
               if(!is_master)
               {
                    FAPI_DBG("A Bus ..target swap performed");
                    rc=init1.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
                    if(rc) return rc;
                    rc=init2.run_training(slave_target,slave_interface,slave_group,master_target,master_interface,master_group);
               }
               else
               {
                    rc=init1.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
                    if(rc) return rc;
                    rc=init2.run_training(master_target,master_interface,master_group,slave_target,slave_interface,slave_group);
               }
          }
     }
     else{
          FAPI_ERR("Invalid io_run_training HWP invocation . Pair of targets dont belong to DMI/X/A instances");
          FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_INVALID_INVOCATION_RC);
     }
     return rc;
}



} // extern 
