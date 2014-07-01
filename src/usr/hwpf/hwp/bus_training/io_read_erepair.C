/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_read_erepair.C $             */
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
// $Id: io_read_erepair.C,v 1.12 2014/04/17 15:58:23 steffen Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
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
	ecmdDataBufferBase mask(16);
	uint8_t lane=0;

	io_interface_t interface=CP_IOMC0_P0; // Since G
	uint32_t rc_ecmd=0;
	uint8_t start_group=0;
	uint8_t end_group=0;
        const fapi::Target &TARGET=target;
		rc_ecmd=mask.flushTo1();
		if(rc_ecmd)
		{
			rc.setEcmdError(rc_ecmd);
			return(rc);
		}

		// Check which type of bus this is and do setup needed
		fapi::TargetType l_type = target.getType();
        switch (l_type)
        {
            case fapi::TARGET_TYPE_ABUS_ENDPOINT:
				start_group=0;
				end_group=0;
				interface=CP_FABRIC_A0; // base scom for A bus , assume translation to A1 by PLAT
				break;
			case fapi::TARGET_TYPE_XBUS_ENDPOINT:
				start_group=0;
				end_group=0;
				interface=CP_FABRIC_X0; // base scom for X bus
				break;
			case fapi::TARGET_TYPE_MCS_CHIPLET:
				start_group=3;
				end_group=3;
				interface=CP_IOMC0_P0; // base scom for MC bus
				break;
			case fapi::TARGET_TYPE_MEMBUF_CHIP:
				start_group=0;
				end_group=0;
				interface=CEN_DMI; // base scom Centaur chip
				break;
			default:
				FAPI_ERR("Invalid io_read_erepair HWP invocation");
		        FAPI_SET_HWP_ERROR(rc,IO_READ_EREPAIR_INVALID_INVOCATION_RC);
				break;
		}
		if (rc)
		{
			return(rc);
		}

		FAPI_INF("Reading erepair data \n");

		for(uint8_t clock_group=start_group;clock_group<=end_group;++clock_group)
		{
			// This is only for X bus ..where multi groups are translated to consecutive lane numbers
			if(interface==CP_FABRIC_X0)
			{
				switch (clock_group)
				{
					case 0:
						lane=0;
						break;
					case 1:
						lane=20;
						break;
					case 2:
						lane=40;
						break;
					case 3:
						lane=60;
						break;
					default:
						//don't need to do anything?
						FAPI_ERR("io_read_erepair has a non-known clock groupd");
						break;
				}
			}

			//Collect the RX bad lanes
			rc_ecmd|=data_one.flushTo0();

			if(rc_ecmd)
			{
				FAPI_ERR("io_read_erepair hit an error while flushing data");
				rc.setEcmdError(rc_ecmd);
				return(rc);
			}

			rc = GCR_read( target, interface,  rx_bad_lane_enc_gcrmsg_pg, clock_group,  0,  data_one);
			if(rc)
			{
				FAPI_ERR("io_read_erepair hit an error while writing rx_bad_lane_enc_gcrmsg_pg");
				return(rc);
			}

			// RX lane records
			// Set the RX bad lanes in the RX vector
			uint8_t status=0;
			
			// Get first bad lane
			data_one.extract(&status,14,2);
			status=status>>6;
			FAPI_DBG("Bad lane status is %d",status);
			
			if(status!=0){
			  if(status>=1){
			      data_one.extract(&lane,0,7);
			      lane=lane>>1;
			      FAPI_DBG("First bad lane is %d",lane);
			      rx_lanes.push_back(lane); // 0 to 15 bad lanes
			  }
			  // Get second bad lane if any
			  if(status>=2){
			      data_one.extract(&lane,7,7);
			      lane=lane>>1;
			      FAPI_DBG("Second bad lane is %d",lane);
			      rx_lanes.push_back(lane); // 16 to 31 bad lanes
			  }
			}
			else{
			  // No bad lanes to report
			   FAPI_DBG("No bad lane to report!!");
			}

		}
	return rc;
}

} //end extern C

