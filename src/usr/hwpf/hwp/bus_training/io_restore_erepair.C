/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_restore_erepair.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: io_restore_erepair.C,v 1.17 2014/03/05 12:01:03 varkeykv Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : io_restore_erepair.C
// *! TITLE                : 
// *! DESCRIPTION          : Restore e-repair data 
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Varghese, Varkey         Email: varkey.kv@in.ibm.com
// *! BACKUP NAME          : Swaminathan, Janani      Email: jaswamin@in.ibm.com      
// *!
// *!***************************************************************************
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.0   |varkeykv|09/27/11|Initial check in . Have to modify targets once bus target is defined and available.Not tested in any way other than in unit SIM IOTK 
//------------------------------------------------------------------------------


#include <fapi.H>
#include "io_restore_erepair.H"
#include "gcr_funcs.H"
#include "io_power_down_lanes.H"
#include <erepairAccessorHwpFuncs.H>

extern "C" {


using namespace fapi;


//! Read repair values from VPD into the HW
/*
 This function will perform erepair for one IO type target  -- eithe MCS or XBUS or ABUS
 * In Cronus the tx_lanes and rx_lanes vectors should be passed empty so we will use the accessor provided data instead 
 * This is due to a MFG FW requirement that needed to pass in bad lanes as args instead of via VPD
 * Note that power down of lanes is done by a seperate HWP called io_power_down_lanes
 * Its up to the caller to call that separately to power down a lane
*/
ReturnCode io_restore_erepair(const Target& target,std::vector<uint8_t> &tx_lanes,std::vector<uint8_t> &rx_lanes)
{
  ReturnCode rc;
  ecmdDataBufferBase data_one(16);
  ecmdDataBufferBase data_two(16);
  ecmdDataBufferBase mode_reg(16);
  ecmdDataBufferBase mask(16);
  uint8_t lane=0;
  bool lane_valid=false;

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
      FAPI_ERR("Invalid io_restore_erepair HWP invocation");
      const fapi::Target &TARGET = target;
      FAPI_SET_HWP_ERROR(rc, IO_RESTORE_EREPAIR_INVALID_INVOCATION_RC);
      return(rc);
  }
  // Use the accessor to fetch VPD data for this particular target instance
  // -- New MFG requirement .. GFW Will pass in lanes as args
  // And we still need to run this in Cronus
  // Since the hack was not made in the accessor to detect this,
  // Provision was made to detect if arguments passed in are empty.
  // If so then the accessor is called to determine from VPD data directly . 
  
  // This is specially for Cronus/Lab 
  if(tx_lanes.size()==0 && rx_lanes.size()==0){
   // rc=erepairGetFailedLanes(target,tx_lanes,rx_lanes); 
    //FAPI_EXEC_HWP(rc,erepairGetFailedLanesHwp,target,tx_lanes,rx_lanes);
    if(!rc.ok()){
      FAPI_ERR("Accessor HWP has returned a fail");
      return rc;
    }
  }
  
   FAPI_INF("Restoring erepair data \n");

    for(uint8_t clock_group=start_group;clock_group<=end_group;++clock_group){
      rc_ecmd|=data_one.flushTo0();
      rc_ecmd|=data_two.flushTo0();
      
      if(rc_ecmd)
      {
          rc.setEcmdError(rc_ecmd);
          return(rc);
      }
      
      // Read in original data
      
      // Read in values for RMW 
      rc = GCR_read( target,interface,rx_lane_bad_vec_0_15_pg, clock_group,  0,  data_one);
      if(rc){return rc;}
      rc = GCR_read( target,interface,rx_lane_bad_vec_16_31_pg, clock_group,  0,  data_two);
      if(rc){return rc;}
      
      // RX lane records 
      // Set the RX bad lanes in the buffer 
      for(uint8_t i=0;i<rx_lanes.size();++i){
        
            if(interface==CP_FABRIC_X0){
                  if(clock_group==0 && rx_lanes[i]<20){
                    lane=rx_lanes[i];
                    lane_valid=true;
                  }
                  else if(clock_group==1 && (rx_lanes[i]>19 && rx_lanes[i]<40)){
                    lane=rx_lanes[i]-20;
                    lane_valid=true;
                  }
                  else if(clock_group==2 && (rx_lanes[i]>39 && rx_lanes[i]<60)){
                    lane=rx_lanes[i]-40;
                    lane_valid=true;
                  }
                  else if(clock_group==3 && (rx_lanes[i]>59 && rx_lanes[i]<80) ){
                    lane=rx_lanes[i]-60;
                    lane_valid=true;
                  }
                  else{
                    lane_valid=false;
                  }
            }
            else{
              lane=rx_lanes[i];
              lane_valid=true;
            }
          if (lane < 16 && lane_valid) {
             rc_ecmd = data_one.setBit(lane);
             if(rc_ecmd)
             {
                 rc.setEcmdError(rc_ecmd);
                 return(rc);
             }
          }
          else if(lane>=16 && lane_valid) {
             rc_ecmd = data_two.setBit(lane-16);
             if(rc_ecmd)
             {
                 rc.setEcmdError(rc_ecmd);
                 return(rc);
             }
          }
      }
       FAPI_DBG("#2 Corrected RX lane is  %d\n",lane);
      //Now write the bad lanes in one shot on the slave side RX
      if(!data_one.isBitClear(0,16)){
        rc = GCR_write( target, interface, rx_lane_bad_vec_0_15_pg, clock_group,  0,  data_one,mask );
        if(rc){return rc;}
      }
       if(!data_two.isBitClear(0,16)){
        //Now write the bad lanes in one shot on the slave side RX
        rc = GCR_write( target, interface, rx_lane_bad_vec_16_31_pg, clock_group,  0,  data_two,mask);
        if(rc){return rc;}
       }
    }
    FAPI_EXEC_HWP(rc, io_power_down_lanes,target,tx_lanes,rx_lanes);
  return rc;
}


} //end extern C

