/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_post_trainadv.C $            */
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
// $Id: io_post_trainadv.C,v 1.1 2013/05/10 20:06:00 thomsen Exp $
//*!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   *** IBM Confidential ***
//*!***************************************************************************
// *! FILENAME             : io_post_trainadv.C
// *! TITLE                :
// *! DESCRIPTION          : The purpose of this code is to allow for future post-training activity such as Host-based characterization
// *! CONTEXT              :
// *!
// *! OWNER  NAME          : Varghese, Varkey         Email: varkey.kv@in.ibm.com
// *! BACKUP NAME          : Swaminathan, Janani      Email: jaswamin@in.ibm.com
// *!
//*!***************************************************************************
// CHANGE HISTORY:
//-----------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|-------------------------------------------------
//   1.1   |thomsen |05/10/13| Initial empty shell
//-----------------------------------------------------------------------------

#include <fapi.H>
#include "io_post_trainadv.H"
#include "gcr_funcs.H"

extern "C" {


using namespace fapi;
//================================================================================================================================
// These functions work on a pair of targets. One is the master side of the bus interface, the other the slave side. For eg; in EDI(DMI2)PU is the master and Centaur is the slave
// In EI4 both sides have pu targets
ReturnCode io_post_trainadv(const Target& target){
    ReturnCode rc;
    //uint32_t master_group=0;
    FAPI_DBG("Running IO POST TRAINING ADVANCED PROCEDURE");
    //     ____  __  _______
    //    / __ \/  |/  /  _/
    //   / / / / /|_/ // /
    //  / /_/ / /  / // /
    // /_____/_/  /_/___/
    if( (target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET )){
      FAPI_DBG("This is a Processor DMI bus post training invocation using base DMI scom address");
      //master_interface=CP_IOMC0_P0; // base scom for MC bus
      //master_group=3; // Design requires us to do this as per scom map and layout
      // USER CODE HERE: ex. rc=run_offset_cal(target,master_interface,master_group);if (rc) {return(rc);};
    }
    else if( (target.getType() ==  fapi::TARGET_TYPE_MEMBUF_CHIP)){
      FAPI_DBG("This is a Centaur DMI bus post training invocation using base DMI scom address");
      //master_interface=CEN_DMI; // base scom for CEN
      //master_group=0;
      // USER CODE HERE: ex. rc=run_offset_cal(target,master_interface,master_group);if (rc) {return(rc);};
    }
    //
    //   | |/ // /
    //   |   // __ \/ / / / ___/
    //  /   |/ /_/ / /_/ (__  )
    // /_/|_/_.___/\__,_/____/
    else if( (target.getType() == fapi::TARGET_TYPE_XBUS_ENDPOINT  )){
      FAPI_DBG("This is a X Bus post training invocation");
      //master_interface=CP_FABRIC_X0; // base scom for X bus
      //master_group=0; // Design requires us to do this as per scom map and layout
      if(rc.ok()){
          // No Z cal in EI4/X bus design
          for(int i=0;i<5;++i){
             //master_group=i;
              // USER CODE HERE: ex. rc=run_offset_cal(target,master_interface,master_group);if (rc) {return(rc);};
          }
      }
    }
    //     ___    __
    //    /   |  / /_  __  _______
    //   / /| | / __ \/ / / / ___/
    //  / ___ |/ /_/ / /_/ (__  )
    // /_/  |_/_.___/\__,_/____/
    else if( (target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT )){
      FAPI_DBG("This is an A Bus post training invocation");
      //master_interface=CP_FABRIC_A0; // base scom for A bus , assume translation to A1 by PLAT
      //master_group=0; // Design requires us to do this as per scom map and layout
                // EDI-A bus needs both impedance cal and offset cal
      // USER CODE HERE: ex. rc=run_offset_cal(target,master_interface,master_group);if (rc) {return(rc);}
    }
    else{
      FAPI_ERR("Invalid io_post_trainadv HWP invocation . Target doesnt belong to DMI/X/A instances");
      // ADD THIS WHEN IMPLEMENTING FUNCTION: FAPI_SET_HWP_ERROR(rc, IO_post_TRAINADV_INVALID_INVOCATION_RC);
    }
    return rc;
}
//================================================================================================================================


} //end extern C
