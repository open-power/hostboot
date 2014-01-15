/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/proc_throttle_sync/proc_throttle_sync.C $ */
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
// $Id: proc_throttle_sync.C,v 1.6 2013/12/19 22:22:03 bellows Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_throttle_sync.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!  Licensed material - Program property of IBM
// *!  Refer to copyright instructions form no. G120-2083
// *! Created on Tue Nov 12 2013 at 13:42:15
//------------------------------------------------------------------------------
// *! TITLE       : proc_throttle_sync
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  :  Bellows Mark D.Email: bellows@us.ibm.com
// *! BACKUP NAME :                 Email: ______@us.ibm.com

// *! ADDITIONAL COMMENTS :
//
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.6   | bellows  |19-DEC-13| Fixed the minor (not functional) setting of rc_ecmd = for next set of data buffer commands
//   1.5   | bellows  |13-DEC-13| One missed firmware review comment
//   1.4   | bellows  |13-DEC-13| Firmware review updates
//   1.3   | bellows  |06-DEC-13| Handle the MCS functional but no centaur case
//   1.2   | bellows  |25-NOV-13| Functional Debug Performed
//   1.1   | bellows  |12-NOV-13| Created.
#include <fapi.H>
#include <proc_throttle_sync.H>
#include <p8_scom_addresses.H>

extern "C" {

  using namespace fapi;

  const uint32_t MAX_SYNC_RETRIES = 1000;
// run on one processor
  ReturnCode proc_throttle_sync(fapi::Target & i_target_proc) {

    ReturnCode rc;
    ecmdDataBufferBase mask_buffer_64(64);
    ecmdDataBufferBase data_buffer_64(64);
    uint8_t l_attr_cen_ec_throttle_sync_possible;
    uint32_t rc_ecmd;
    uint8_t l_proc_attached_centaurs=0;
    uint8_t l_summary_sync_possible=true;
    uint32_t i=0;
    std::vector<fapi::Target> l_target_attached_mcs;
    fapi::Target cen_target;

    do {
    // determine how far into the IPL we have gone
      rc = fapiGetChildChiplets( i_target_proc, TARGET_TYPE_MCS_CHIPLET, l_target_attached_mcs );
      if (rc)
      {
        FAPI_ERR("Failed to find attached mcs\n");
        break;
      }

// find the one mcs
// also form the centaur vector
      uint8_t theonemcs=0xff; // index into the MCS vector for the one MCS
      uint8_t l_functional;
      uint8_t unit_num[8];
      uint8_t pos_attr_data;

      for(i=0; i<8; i++) unit_num[i]=0xff;
      for(i=0; i < l_target_attached_mcs.size(); i++) {
        FAPI_INF("working on mcs %s\n", l_target_attached_mcs[i].toEcmdString());

        rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_target_attached_mcs[i], pos_attr_data);
        if(rc) {
          FAPI_ERR("ERROR: Unable to get ATTR_CHIP_UNIT_POS\n");
          break;
        }


        rc = fapiGetOtherSideOfMemChannel( l_target_attached_mcs[i], cen_target );
        if (rc)
        {
          FAPI_INF("--> this mcs does not have an attached centaur!\n");
          rc=fapi::FAPI_RC_SUCCESS;
        }
        else {
          unit_num[pos_attr_data] = i; // save in index back into the uint_num array

          cen_target.setType(TARGET_TYPE_MEMBUF_CHIP);

          // find out if this centaur can do a sync.  They should all be the same.  Give up if any aren't
          // capable
          rc = FAPI_ATTR_GET(ATTR_CEN_EC_THROTTLE_SYNC_POSSIBLE, &cen_target, l_attr_cen_ec_throttle_sync_possible);
          if(rc) break;

          if( ! l_attr_cen_ec_throttle_sync_possible) { // one or more are not DD2
            FAPI_INF("--> the attached centaur is not capable of this type of sync\n");
            l_summary_sync_possible=false;
          }

          // all functional centaurs form a vector to do a sync on
          rc = FAPI_ATTR_GET(ATTR_FUNCTIONAL, &cen_target,   l_functional);
          if(rc) {
            FAPI_ERR("Could not get ATTR_FUNCTIONAL");
            break;
          }
          if(l_functional) {
            l_proc_attached_centaurs |= ( 0x80 >> pos_attr_data );
          }
        }

      }



      if(l_summary_sync_possible) {
        FAPI_INF("--> Because sync possible, running procedure\n");

// SYNC PROCEDURE:
// 1.) Determined the MCS to be the master
//      Choose MC2.MCS0, since its on both Murano and Venice.
//      However, if its deconfigured then the code will have to determine the next master per processor chip.
//  [ This is determined by the platform.  The suggestion is to use MC2.MCS0, but if that is not available, pick a different one ]
      // select the one
        if(unit_num[4] != 0xFF) theonemcs=unit_num[4];
        else if(unit_num[5] != 0xFF) theonemcs=unit_num[5];
        else if(unit_num[6] != 0xFF) theonemcs=unit_num[6];
        else if(unit_num[7] != 0xFF) theonemcs=unit_num[7];
        else if(unit_num[0] != 0xFF) theonemcs=unit_num[0];
        else if(unit_num[1] != 0xFF) theonemcs=unit_num[1];
        else if(unit_num[2] != 0xFF) theonemcs=unit_num[2];
        else if(unit_num[3] != 0xFF) theonemcs=unit_num[3];
        else {
          FAPI_IMP("Did not find a valid MCS on this processor %s\n", i_target_proc.toEcmdString());
          break;
        }

        FAPI_INF("--> the one mcs is %s\n", l_target_attached_mcs[theonemcs].toEcmdString() );
// 2.) Select which MCS to be the targets per processor.  You'll want to select the configured MCS's with Centaur attached, but it might still work if you select all of them.
//       Bits 0:7 of MCSYNC Register (Scom addr 201180B) are the select bits.  These bits should be set on the master only.  They tell the master, which targets to send the sync commands.
//
// 	Here's the mapping, if you wish to select the configured MCS's only.  The red MCS's below are only on Venice chips.
// 	Bit 0: MC0.MCS0
// 	Bit 1: MC0.MCS1
// 	Bit 2: MC1.MCS0
// 	Bit 3: MC1.MCS1
// 	Bit 4: MC2.MCS0
// 	Bit 5: MC2.MCS1
// 	Bit 6: MC3.MCS0
// 	Bit 7: MC3.MCS1
        bool l_sync_complete=false;
        uint32_t l_tries=0;
        while ( l_sync_complete == false && l_tries < 1000 ) {
          rc_ecmd = ECMD_DBUF_SUCCESS;
          FAPI_INF("--> Doing the sync sequence try is %d\n", l_tries );
          rc_ecmd |= data_buffer_64.clearBit(0,64);
          rc_ecmd |= mask_buffer_64.clearBit(0,64);

          FAPI_INF("--> the vector of attached centaurs is %02x\n", l_proc_attached_centaurs );
          for(i=0; i<8; i++) {
            if((l_proc_attached_centaurs>>(7-i)) & 0x1) {
              rc_ecmd |= data_buffer_64.setBit(i);
            }
            rc_ecmd |= mask_buffer_64.setBit(i);
          }

// 3.) Setup the sync commands to issue to centaur on the master MCS
//      Bit 12 of MCSYNC Register is N/M Sync (Scom addr 201180B)
//      Bit 15 of MCSYNC Register is PC Sync (Scom addr 201180B)

          rc_ecmd |= data_buffer_64.setBit(12);
          rc_ecmd |= mask_buffer_64.setBit(12);
          rc_ecmd |= data_buffer_64.setBit(15);
          rc_ecmd |= mask_buffer_64.setBit(15);
          if(rc_ecmd) {
            rc.setEcmdError(rc_ecmd);
            break;
          }
          rc = fapiPutScomUnderMask(l_target_attached_mcs[theonemcs], MCS_MCSYNC_0x0201180B, data_buffer_64, mask_buffer_64);
          if(rc) break;

// 4.) Generate the Sync Command to Centaur from the master MCS
//      Bit 0 of MCS Mode3 Register (Scom addr 201180A)
//      (This bit needs a reset before another set, it does not reset automatically)
          rc_ecmd = data_buffer_64.clearBit(0,64);
          rc_ecmd |= data_buffer_64.setBit(0);
          rc_ecmd |= mask_buffer_64.clearBit(0,64);
          rc_ecmd |= mask_buffer_64.setBit(0);
          if(rc_ecmd) {
            rc.setEcmdError(rc_ecmd);
            break;
          }

          rc = fapiPutScomUnderMask(l_target_attached_mcs[theonemcs], MCS_MODE3_REGISTER_0x0201180A, data_buffer_64, mask_buffer_64);
          if(rc) break;

          // this resets the before mentioned bit
          rc_ecmd = data_buffer_64.clearBit(0);
          if(rc_ecmd) {
            rc.setEcmdError(rc_ecmd);
            break;
          }
          rc = fapiPutScomUnderMask(l_target_attached_mcs[theonemcs], MCS_MODE3_REGISTER_0x0201180A, data_buffer_64, mask_buffer_64);
          if(rc) break;

// 5.) Read the SYNC status register on the master MCS
//      Bits 1:7 of MCS Mode3 Register (Scom addr 201180A)
//     If any status bit is set, this indicates that a replay has occurred on the DMI channel, repeat steps 3 and 4 above.
// (actually to build the register back up, we go to step 2 to pick up the centaurs again)
          rc = fapiGetScom(l_target_attached_mcs[theonemcs], MCS_MODE3_REGISTER_0x0201180A, data_buffer_64);
          if(rc) break;

          if(data_buffer_64.isBitClear(1,7) == true) {
            l_sync_complete=true;
          }
          else {
            l_tries++;
            FAPI_INF("--> Not all ready, reissue the sync,  tries are %d\n", l_tries );
            l_sync_complete=false;
          }
        }
        if(rc) break;
        if (l_tries == MAX_SYNC_RETRIES) {
          FAPI_ERR("This processor did not see a successful MCSYNC\n");
          FAPI_SET_HWP_ERROR(rc, RC_PROC_MCSYNC_THERMAL_RETRY_EXCEEDED);
          break;
        }
        FAPI_INF("--> Success in running the sync sequence tries were %d\n", l_tries );

      }
    } while(0);

    return rc;
  }

} // extern "C"
