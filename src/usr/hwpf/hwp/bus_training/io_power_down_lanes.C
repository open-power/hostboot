/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_power_down_lanes.C $         */
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
// $Id: io_power_down_lanes.C,v 1.7 2013/04/30 17:48:50 mjjones Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
// *!***************************************************************************
// *! FILENAME             : io_read_erepair.C
// *! TITLE                : 
// *! DESCRIPTION          : Power down bad lanes
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
//   1.7   |mjjones |04/30/13| Removed unused variables
//   1.0   |varkeykv||Initial check in 
//------------------------------------------------------------------------------

#include <fapi.H>
#include "io_power_down_lanes.H"
#include "gcr_funcs.H"

extern "C" {


using namespace fapi;


/*
 This function will perform power down of lanes on any IO target MEMBUF,MCS , XBUS or ABUS
 * Bad lanes are powered down , but caller is expected to logically disable lanes by calling restore_repair prior
 * to calling this HWP 
*/

ReturnCode io_power_down_lanes(const Target& target,const std::vector<uint8_t> &tx_lanes,const std::vector<uint8_t> &rx_lanes)
{
  ReturnCode rc;
  ecmdDataBufferBase data(16);
  ecmdDataBufferBase mask(16);
  ecmdDataBufferBase mode_reg(16);
  uint8_t lane=0;
  bool msbswap=false;
  const uint8_t xbus_lanes_per_group=20;
  uint8_t end_lane=0;
  
  io_interface_t interface=CP_IOMC0_P0; // Since G
  uint32_t rc_ecmd=0;
  uint8_t clock_group=0;
  
    rc_ecmd=mask.flushTo1();
    if(rc_ecmd)
    {
        rc.setEcmdError(rc_ecmd);
        return(rc);
    }
    // Both TX and RX power down bits are on bit 0 
    rc_ecmd=mask.clearBit(0);
    if(rc_ecmd)
    {
        rc.setEcmdError(rc_ecmd);
        return(rc);
    }
  
  // Check which type of bus this is and do setup needed 
  if(target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT) {
    interface=CP_FABRIC_A0; // base scom for A bus , assume translation to A1 by PLAT 
  }
  else if(target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT ) {
    interface=CP_FABRIC_X0; // base scom for X bus
  }
  else if(target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET){
    interface=CP_IOMC0_P0; // base scom for MC bus
  }
  else if(target.getType() == fapi::TARGET_TYPE_MEMBUF_CHIP){
    interface=CEN_DMI; // base scom Centaur chip
  }
  else{
      FAPI_ERR("Invalid io_power_down_lanes HWP invocation");
      FAPI_SET_HWP_ERROR(rc, IO_RUN_TRAINING_INVALID_INVOCATION_RC);
      return(rc);
  }
  
   FAPI_INF("Power down IO lanes\n");

      rc_ecmd|=data.flushTo0();
      rc_ecmd|=data.setBit(0); // Power down is on bit 0 always

      if(rc_ecmd)
      {
          rc.setEcmdError(rc_ecmd);
          return(rc);
      }
      
      rc = GCR_read( target, interface,tx_mode_pg, clock_group,  0,  mode_reg);
      if(rc){return rc;}
      
      if(mode_reg.isBitSet(5)){
        FAPI_DBG("TX MSB-LSB SWAP MODE ON on this target \n",tx_end_lane_id);
        msbswap=true;
      }
      
    //TX Lanes power down 
      for(uint8_t i=0;i<tx_lanes.size();++i){
        clock_group=0;
        lane=tx_lanes[i];
        //For Xbus figure out the clock group number 
        if(interface==CP_FABRIC_X0){
          while(lane>(xbus_lanes_per_group-1)){
            lane=lane-xbus_lanes_per_group;
            clock_group++;
          }
        }
        else{
          // MSBLSB SWAP condition can be there in MC or A 
             if(msbswap){
                // We can read out tx_end_lane_id now for swap correction
                rc = GCR_read( target, interface,tx_id3_pg, clock_group,  0,  mode_reg);
                if(rc){return rc;}
                rc_ecmd=mode_reg.extract(&end_lane,9,7);
                if(rc_ecmd)
                {
                    rc.setEcmdError(rc_ecmd);
                    return(rc);
                }
                end_lane=end_lane>>1;// move left aligned extract by 1
                FAPI_DBG("END lane id is %d\n",end_lane);
                lane=end_lane-tx_lanes[i]; // GFW VPD does not know about MSBSWAP , this adjusts for swapping
             }
        }
        //Power down this lane 
        rc = GCR_write( target, interface, tx_mode_pl, clock_group,  lane,  data,mask );
        if(rc){return rc;}

      }

      // Process RX lane powerdown 
      for(uint8_t i=0;i<rx_lanes.size();++i){
        clock_group=0;
        lane=rx_lanes[i];
        //For X bus set the right clock group number
        if(interface==CP_FABRIC_X0){
          while(lane>(xbus_lanes_per_group-1)){
            lane=lane-xbus_lanes_per_group;
            clock_group++;
          }
        }
        //Power down this lane 
        rc = GCR_write( target, interface, rx_mode_pl, clock_group,  lane,  data,mask );
        if(rc){return rc;}
      }
  return rc;
}

} //end extern C

