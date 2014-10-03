/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_power_down_lanes.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: io_power_down_lanes.C,v 1.14 2014/09/29 23:22:56 garyp Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             : io_power_down_lanes.C
// *! TITLE                : 
// *! DESCRIPTION          : Power down bad lanes
// *! CONTEXT              : 
// *!
// *! OWNER  NAME          : Steffen, Chris           Email: cwsteffen@us.ibm.com
// *! BACKUP NAME          : Peterson, Gary           Email: garyp@us.ibm.com      
// *!
// *!***************************************************************************
// CHANGE HISTORY: 
//------------------------------------------------------------------------------
// Version:|Author: | Date:  | Comment:
// --------|--------|--------|--------------------------------------------------
//   1.0   |varkeykv||Initial check in 
//------------------------------------------------------------------------------

#include <fapi.H>
#include "io_power_down_lanes.H"
#include "gcr_funcs.H"

extern "C" {

    using namespace fapi;

    /*
    This function will perform power down of lanes on any IO target: MEMBUF, MCS ,XBUS, or ABUS
    For rx_lanes, it will also set rx_wt_lane_disabled
    For a bad lane, it will be called twice:
          once with target set to the rx target, rx_lanes populated, and tx_lanes empty
          once with target set to the tx target, tx_lanes populated, and rx_lanes empty
    */

    ReturnCode io_power_down_lanes(const Target& target, const std::vector<uint8_t> &tx_lanes, const std::vector<uint8_t> &rx_lanes) {
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
	uint8_t start_group=0;

	do {
	    // rx_lane_pdwn, tx_lane_pdwn, and  rx_wt_lane_disabled are all bit 0; and this routine is setting all 3, so we set up data and mask once
	    rc_ecmd=mask.flushTo1();
	    if(rc_ecmd) {
		FAPI_ERR("io_power_down_lanes error occured while flushing bits for mask");
		rc.setEcmdError(rc_ecmd);
		break;
	    }

	    rc_ecmd=data.flushTo0();
	    if(rc_ecmd) {
		FAPI_ERR("io_power_down_lanes error occured while flushing bits for data");
		rc.setEcmdError(rc_ecmd);
		break;
	    }

	    rc_ecmd=data.setBit(0);
	    if(rc_ecmd) {
		FAPI_ERR("io_power_down_lanes error occured while clearing bits for data");
		rc.setEcmdError(rc_ecmd);
		break;
	    }

	    // Check which type of bus this is and do setup needed
	    fapi::TargetType l_type= target.getType();
	    switch (l_type) {
		case fapi::TARGET_TYPE_ABUS_ENDPOINT:
		    start_group=0;
		    interface=CP_FABRIC_A0; // base scom for A bus , assume translation to A1 by PLAT
		    break;
		case fapi::TARGET_TYPE_XBUS_ENDPOINT:
		    start_group=0;
		    interface=CP_FABRIC_X0; // base scom for X bus
		    break;
		case fapi::TARGET_TYPE_MCS_CHIPLET:
		    start_group=3;
		    interface=CP_IOMC0_P0; // base scom for MC bus
		    break;
		case fapi::TARGET_TYPE_MEMBUF_CHIP:
		    start_group=0;
		    interface=CEN_DMI; // base scom Centaur chip
		    break;
		default:
		    FAPI_ERR("Invalid io_power_down_lanes HWP invocation");
  		    const fapi::Target& TARGET = target;
		    FAPI_SET_HWP_ERROR(rc, IO_POWER_DOWN_LANES_INVALID_INVOCATION_RC);
		    break;
	    }
	    if (rc) {
		break;
	    }

	    FAPI_INF("Power down IO lanes\n");

	    rc = GCR_read( target, interface, tx_mode_pg, start_group, 0, mode_reg);
	    if(rc) {
		FAPI_ERR("GCR_read returned an error while reading tx_mode_pg");
		break;
	    }

	    if(mode_reg.isBitSet(5)) {
		FAPI_DBG("TX MSB-LSB SWAP MODE ON on this target %d \n",tx_end_lane_id);
		msbswap=true;
	    }

	    //TX Lanes power down; target must be the tx
	    for(uint8_t i=0;i<tx_lanes.size();++i) {
		lane=tx_lanes[i];
		//For X bus, adjust the lane and clock group
		if(interface==CP_FABRIC_X0) {
		    clock_group=start_group;
		    while(lane>(xbus_lanes_per_group-1)) {
			lane=lane-xbus_lanes_per_group;
			clock_group++;
		    }
		}
		else {
		    clock_group=start_group;
		    // MSBLSB SWAP condition can be there in MC or A
		    if(msbswap) {
			// We can read out tx_end_lane_id now for swap correction
			rc = GCR_read( target, interface, tx_id3_pg, clock_group, 0, mode_reg);
			if(rc) {
			    FAPI_ERR("GCR_read returned an error during call to read tx_id3_pg");
			    break;
			}

			rc_ecmd=mode_reg.extract(&end_lane,9,7);
			if(rc_ecmd) {
			    rc.setEcmdError(rc_ecmd);
			    break;
			}
			end_lane=end_lane>>1;// move left aligned extract by 1
			FAPI_DBG("END lane id is %d\n",end_lane);
			lane=end_lane-tx_lanes[i]; // GFW VPD does not know about MSBSWAP , this adjusts for swapping
		    }
		}

		//Power down this lane
		rc = GCR_write( target, interface, tx_mode_pl, clock_group, lane, data, mask );
		if(rc) {
		    FAPI_ERR("GCR_write returned an error  while writing tx_mode_pl");
		    break;
		}
	    }

	    if (rc) { //break out of larger while loop
		break;
	    }

	    // Process RX lane powerdown; target must be the rx
            for(uint8_t i=0;i<rx_lanes.size();++i) {
		lane=rx_lanes[i];

		//For X bus, adjust the lane and clock group
		if(interface==CP_FABRIC_X0) {
		    clock_group=start_group;
		    while(lane>(xbus_lanes_per_group-1)) {
			lane=lane-xbus_lanes_per_group;
			clock_group++;
		    }
		}
		else {
		    clock_group=start_group;
		}

		//Power down this lane
		rc = GCR_write( target, interface, rx_mode_pl, clock_group, lane, data, mask );
		if(rc) {
		    FAPI_ERR("GCR_write returned an error while writing rx_mode_pl");
		    break;
		}

		// Set rx_wt_lane_disabled for this lane; see SW244284, SW280992
		rc = GCR_write( target, interface,  rx_wt_status_pl, clock_group, lane, data, mask );
		if(rc) {
		    FAPI_ERR("GCR_write returned an error while writing rx_wt_status_pl");
		    break;
		}
	    }
	} while(0); // run loop only once
	return rc;
    } //end io_power_down_lanes
} //end extern C

