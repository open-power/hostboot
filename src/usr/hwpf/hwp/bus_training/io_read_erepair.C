/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_read_erepair.C $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: io_read_erepair.C,v 1.6 2013/07/14 15:50:02 varkeykv Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : io_read_erepair.C
// *! TITLE                : 
// *! DESCRIPTION          : Read e-repair data 
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Varghese, Varkey         Email: varkey.kv@in.ibm.com
// *! BACKUP NAME          : Swaminathan, Janani      Email: jaswamin@in.ibm.com      
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:   | Comment:
// --------|--------|---------|--------------------------------------------------
//   1.0   |varkeykv|21-Jan-13|Initial check in 
//------------------------------------------------------------------------------

#include <fapi.H>
#include "io_read_erepair.H"
#include "gcr_funcs.H"

extern "C" {


using namespace fapi;


//! Read repair values from VPD into the HW
/*
 This function will perform erepair for one IO type target  -- eithe MCS or XBUS or ABUS
* Tx and Rx lanes vector is filled in by the HWP with bad lane numbers
*/
ReturnCode io_read_erepair(const Target& target,std::vector<uint8_t> &rx_lanes)
{
  ReturnCode rc;
  ecmdDataBufferBase data_one(16);
  ecmdDataBufferBase data_two(16);
  ecmdDataBufferBase mask(16);
  uint8_t lane=0;

  io_interface_t interface=CP_IOMC0_P0; // Since G
  uint32_t rc_ecmd=0;
  uint8_t start_group=0;
  uint8_t end_group=0;
  
    rc_ecmd=mask.flushTo1();
    if(rc_ecmd)
    {
        rc.setEcmdError(rc_ecmd);
        return(rc);
    }
  
  // Check which type of bus this is and do setup needed 
  if(target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT) {
    start_group=0;
    end_group=0;
    interface=CP_FABRIC_A0; // base scom for A bus , assume translation to A1 by PLAT 
  }
  else if(target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT ) {
    start_group=0;
    end_group=3;
    interface=CP_FABRIC_X0; // base scom for X bus
  }
  else if(target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET){
    start_group=3;
    end_group=3;
    interface=CP_IOMC0_P0; // base scom for MC bus
  }
  else if(target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP){
    start_group=0;
    end_group=0;
    interface=CEN_DMI; // base scom Centaur chip
  }
  else{
      FAPI_ERR("Invalid io_read_erepair HWP invocation");
      FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_INVALID_INVOCATION_RC);
      return(rc);
  }
   
   FAPI_INF("Reading erepair data \n");

    for(uint8_t clock_group=start_group;clock_group<=end_group;++clock_group){
      // This is only for X bus ..where multi groups are translated to consecutive lane numbers
      if(interface==CP_FABRIC_X0){
          if(clock_group==0){
            lane=0;
          }
          else if(clock_group==1){
            lane=20;
          }
          else if(clock_group==2){
            lane=40;
          }
          else if(clock_group==3){
            lane=60;
          }
       }

      //Collect the RX bad lanes 
      rc_ecmd|=data_one.flushTo0();
      rc_ecmd|=data_two.flushTo0();
            
      if(rc_ecmd)
      {
          rc.setEcmdError(rc_ecmd);
          return(rc);
      }
      
      rc = GCR_read( target, interface, rx_lane_bad_vec_0_15_pg, clock_group,  0,  data_one);
      if(rc){return rc;}
      rc = GCR_read( target, interface, rx_lane_bad_vec_16_31_pg, clock_group,  0,  data_two);
      if(rc){return rc;}

      // RX lane records 
      // Set the RX bad lanes in the RX vector
      
      for(uint8_t i=0;i<16;++i){
          if (data_one.isBitSet(i)) {
             rx_lanes.push_back(lane+i); // 0 to 15 bad lanes
          }
          if(data_two.isBitSet(i)){
            rx_lanes.push_back(lane+i+16); // 16 to 31 bad lanes 
          }
      }

    }
  return rc;
}

} //end extern C

