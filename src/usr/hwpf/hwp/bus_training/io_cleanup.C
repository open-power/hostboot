/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/io_cleanup.C $                  */
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
// $Id: io_cleanup.C,v 1.14 2014/06/06 19:43:41 steffen Exp $
// *!***************************************************************************
// *! (C) Copyright International Business Machines Corp. 1997, 1998
// *!           All Rights Reserved -- Property of IBM
// *!                   ***  ***
// *!***************************************************************************
// *! FILENAME             : io_cleanup.C
// *! TITLE                :
// *! DESCRIPTION          : Cleanup procedure for re-init loop
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
//   1.0   |varkeykv|07/30/11|Initial check in .
//------------------------------------------------------------------------------
#include <fapi.H>
#include "io_cleanup.H"
#include "gcr_funcs.H"
#include <p8_scom_addresses.H>


extern "C" {
	using namespace fapi;

// For clearing the FIR mask , used by io run training
// As per Irving , it should be ok to clear all FIRs here since we will scom init , also we dont touch mask values
ReturnCode clear_fir_reg(const Target &i_target,fir_io_interface_t i_chip_interface){
	ReturnCode rc;
	ecmdDataBufferBase data(64);
	FAPI_INF("io_cleanup:In the Clear FIR RW register function on %s", i_target.toEcmdString());
	rc = fapiPutScom(i_target, fir_rw_reg_addr[i_chip_interface], data);
	if (!rc.ok()){FAPI_ERR("Error writing FIR mask register (=%08X)!",fir_rw_reg_addr[i_chip_interface]);}
	return(rc);
}


ReturnCode do_cleanup(const Target &master_target,io_interface_t master_interface,uint32_t master_group){
	ReturnCode rc;
	uint32_t rc_ecmd                             = 0;
	ecmdDataBufferBase   set_bits(16);
	ecmdDataBufferBase clear_bits(16);
	ecmdDataBufferBase mask_buffer_64(64);
	ecmdDataBufferBase data_buffer_64(64);
	ecmdDataBufferBase rx_set_bits(16);
	ecmdDataBufferBase tx_set_bits(16);
	bool memory_attached                         = false;
	bool reset_required                          = false;
	uint8_t l_attr_mss_init_state                = 0x0;
	uint8_t l_attr_proc_ec_mss_reconfig_possible = 0x0;
	uint8_t mcs_unit_id                          = 0x0;
	uint8_t mcs_unit_lower_limit                 = 0;
	uint8_t mcs_unit_upper_limit                 = 3;
	io_interface_t slave_interface               = CEN_DMI; // Centaur scom base
	uint32_t slave_group                         = 0x0;
	// vector to hold MCS chiplet targets
	std::vector<fapi::Target> mcs_chiplets;
	fapi::Target master_parent_target;
	fapi::Target attached_cen_target;

	// Find DMI0 or DMI1 controller limits based on passed in target.
	rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &master_target, mcs_unit_id);   // read chip unit number
	if(rc){return rc;}
	if(mcs_unit_id == 0){        // DMI0, not on Tuleta, on Brazos
		mcs_unit_lower_limit = 0;
		mcs_unit_upper_limit = 3;
	}else if(mcs_unit_id == 4){  // DMI1, on Tuleta and Brazos
		mcs_unit_lower_limit = 4;
		mcs_unit_upper_limit = 7;
	}else{
		return rc;
	}

	//Get Master Parent Target
	rc = fapiGetParentChip(master_target, master_parent_target); if(rc){return rc;}

	// Loop over all present MCS chiplets in the controller, to see if a reset is required
	rc = fapiGetChildChiplets(master_parent_target,fapi::TARGET_TYPE_MCS_CHIPLET,mcs_chiplets, fapi::TARGET_STATE_PRESENT);
	for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin(); i != mcs_chiplets.end(); i++){
		rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), mcs_unit_id);   // read chip unit number
		if(rc){return rc;}
		if((mcs_unit_lower_limit <= mcs_unit_id) && (mcs_unit_id <= mcs_unit_upper_limit)){    //To limit these actions to a single DMI controller
			rc = fapiGetOtherSideOfMemChannel( *i, attached_cen_target, fapi::TARGET_STATE_PRESENT);
			if(!rc){     // An error from this means that there is no centaur attached.
				rc = FAPI_ATTR_GET(ATTR_MSS_INIT_STATE, &attached_cen_target, l_attr_mss_init_state);  if(rc) return rc;
				if(l_attr_mss_init_state != ENUM_ATTR_MSS_INIT_STATE_COLD){
					reset_required = true;
				}
			}else{
				rc = FAPI_RC_SUCCESS;
			}
		}
	}
	if(!reset_required){
		return(rc);
	}
	FAPI_INF("IO CleanUp: Global Reset Required");

	//
	rc = FAPI_ATTR_GET(ATTR_PROC_EC_MSS_RECONFIG_POSSIBLE, &master_parent_target, l_attr_proc_ec_mss_reconfig_possible); if(rc){return rc;}
	// Loop over all present MCS chiplets in the controller
	// Turn off FIR propagator, Mask FIRs, and force channel fail
	rc = fapiGetChildChiplets(master_parent_target,fapi::TARGET_TYPE_MCS_CHIPLET,mcs_chiplets, fapi::TARGET_STATE_PRESENT);
	for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin(); i != mcs_chiplets.end(); i++){
		rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), mcs_unit_id);   // read chip unit number
		if(rc){return rc;}
		if((mcs_unit_lower_limit <= mcs_unit_id) && (mcs_unit_id <= mcs_unit_upper_limit)){    //To limit these actions to a single DMI controller
			memory_attached = true;
			rc = fapiGetOtherSideOfMemChannel( *i, attached_cen_target, fapi::TARGET_STATE_PRESENT);
			if(rc){    // An error from this means that there is no centaur attached.
				memory_attached = false;
			}else{
				rc = FAPI_ATTR_GET(ATTR_MSS_INIT_STATE, &attached_cen_target, l_attr_mss_init_state);  if(rc) return rc;
			}
			// turn off the FIR propagator
			if( l_attr_proc_ec_mss_reconfig_possible){
				rc_ecmd = data_buffer_64.setBit(42);
				if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
				rc_ecmd = mask_buffer_64.setBit(42);
				if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
				rc = fapiPutScomUnderMask(*i, MCS_MCICFG_0x0201184A, data_buffer_64, mask_buffer_64);  if(rc) return rc;
			}else{
				FAPI_ERR("This processor cannot go through a reconfig loop. Please upgrade to > DD1\n");
				const fapi::Target & PROC =  master_parent_target;
				FAPI_SET_HWP_ERROR(rc, RC_IO_CLEANUP_UNSUPPORTED);
				return rc;
			}
			// Mask firs in the MCS
			rc_ecmd = data_buffer_64.setBit(0,64);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc = fapiPutScom(*i, MCS_MCIFIRMASK_0x02011843, data_buffer_64); if(rc) return rc;
			// force a channel fail only if you are up to DMI ACTIVE state on this pair
			rc_ecmd = data_buffer_64.clearBit(0,64);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc_ecmd = data_buffer_64.setBit(0);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc_ecmd = mask_buffer_64.clearBit(0,64);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc_ecmd = mask_buffer_64.setBit(0);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc = fapiPutScomUnderMask(master_target, MCS_MCICFG_0x0201184A, data_buffer_64, mask_buffer_64); if(rc) return rc;
			if((memory_attached) && ((l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_CLOCKS_ON) || (l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_DMI_ACTIVE)) ){
				rc_ecmd = data_buffer_64.clearBit(0,64);
				if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
				rc_ecmd = data_buffer_64.setBit(0);
				if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
				rc = fapiPutScom(attached_cen_target, CENTAUR_MBI_CFG_0x0201080A, data_buffer_64);
			}
			rc_ecmd = set_bits.setBit(0);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc=GCR_write(*i, master_interface,  rx_fence_pg, master_group, 0, set_bits, set_bits, 1, 1);
			if(rc) return rc;
			if((memory_attached) && ((l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_CLOCKS_ON) || (l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_DMI_ACTIVE)) ){
				rc=GCR_write(attached_cen_target, slave_interface, rx_fence_pg, slave_group, 0, set_bits, set_bits, 1, 1);
				if(rc) return rc;
			}
		}
	}

	/// reset start
	// pu
	rc = fapiGetScom(master_target, scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0], data_buffer_64);
	if (!rc.ok()){FAPI_ERR("Error Reading SCOM mode PB register for ioreset_hard_bus0 on master side(=%08X)!",scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0]); return rc;}
	rc_ecmd = data_buffer_64.setBit(2,6);  // Scom_mode_pb ,ioreset starts at bit 2
	if(rc_ecmd){rc.setEcmdError(rc_ecmd);return(rc);}
	rc = fapiPutScom(master_target, scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0], data_buffer_64);
	if (!rc.ok()){FAPI_ERR("Error Reading SCOM mode PB register for ioreset_hard_bus0 on master side(=%08X)!",scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0]); return rc;}

	// cen
	rc = fapiGetChildChiplets(master_parent_target,fapi::TARGET_TYPE_MCS_CHIPLET,mcs_chiplets, fapi::TARGET_STATE_PRESENT);
	for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin(); i != mcs_chiplets.end(); i++){
		rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), mcs_unit_id);   // read chip unit number
		if (!rc.ok()){FAPI_ERR("Error retreiving MCS chiplet number, while setting bus id.");return rc;}
		if((mcs_unit_lower_limit <= mcs_unit_id) && (mcs_unit_id <= mcs_unit_upper_limit)){    //To limit these actions to a single DMI controller
			rc = fapiGetOtherSideOfMemChannel( *i, attached_cen_target, fapi::TARGET_STATE_PRESENT);
			if(!rc){   // An error from this means that there is no centaur attached.
				rc = FAPI_ATTR_GET(ATTR_MSS_INIT_STATE, &attached_cen_target, l_attr_mss_init_state);  if(rc) return rc;
				if((l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_CLOCKS_ON) || (l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_DMI_ACTIVE) ){
					rc_ecmd = data_buffer_64.flushTo0();
					if(rc_ecmd){rc.setEcmdError(rc_ecmd);return(rc);}
					rc = fapiGetScom(attached_cen_target, scom_mode_pb_reg_addr[FIR_CEN_DMI], data_buffer_64);
					if(!rc.ok()){FAPI_ERR("Error Reading SCOM mode PB register for ioreset_hard_bus0 on Slave side(=%08X)!",scom_mode_pb_reg_addr[FIR_CEN_DMI]); return rc;}
					rc_ecmd = data_buffer_64.setBit(2,1);  // Scom_mode_pb ,ioreset starts at bit 2
					if(rc_ecmd){rc.setEcmdError(rc_ecmd);return(rc);}
					rc = fapiPutScom(attached_cen_target, scom_mode_pb_reg_addr[FIR_CEN_DMI], data_buffer_64);
					if(!rc.ok()){FAPI_ERR("Error Reading SCOM mode PB register for ioreset_hard_bus0 on Slave side(=%08X)!",scom_mode_pb_reg_addr[FIR_CEN_DMI]); return rc;}
				}
			}
		}
	}
	FAPI_INF("IO CleanUp: Global Reset Done");
	/// reset end

	// Set Bus IDs, Clear FIRs, Turn on FIR Propagator
	rc = fapiGetChildChiplets(master_parent_target,fapi::TARGET_TYPE_MCS_CHIPLET,mcs_chiplets, fapi::TARGET_STATE_PRESENT);
	for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin(); i != mcs_chiplets.end(); i++){
		rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), mcs_unit_id);   // read chip unit number
		if (!rc.ok()){FAPI_ERR("Error retreiving MCS chiplet number, while setting bus id.");return rc;}
		if((mcs_unit_lower_limit <= mcs_unit_id) && (mcs_unit_id <= mcs_unit_upper_limit)){    //To limit these actions to a single DMI controller
			// Set Bus IDs
			clear_bits.flushTo0();
			uint32_t rxbits = 0;
			uint32_t txbits = 0;
			// Tuleta has MCS4-7 corresponding to port DMI1
			// Brazos has MCS0-7 corresponding to port DMI0 and DMI1
			if(mcs_unit_id == 0){
				rxbits = 0x0000;    //bus_id: 0 group_id: 0
				txbits = 0x0100;    //bus_id: 0 group_id: 32
			}else if(mcs_unit_id == 1){
				rxbits = 0x0400;    //bus_id: 1 group_id: 0
				txbits = 0x0500;    //bus_id: 1 group_id: 32
			}else if(mcs_unit_id == 2){
				rxbits = 0x0800;    //bus_id: 2 group_id: 0
				txbits = 0x0900;    //bus_id: 2 group_id: 32
			}else if(mcs_unit_id == 3){
				rxbits = 0x0C00;    //bus_id: 3 group_id: 0
				txbits = 0x0D00;    //bus_id: 3 group_id: 32
			}else if(mcs_unit_id == 4){
				rxbits = 0x0000;    //bus_id: 0 group_id: 0
				txbits = 0x0100;    //bus_id: 0 group_id: 32
			}else if(mcs_unit_id == 5){
				rxbits = 0x0400;    //bus_id: 1 group_id: 0
				txbits = 0x0500;    //bus_id: 1 group_id: 32
			}else if(mcs_unit_id == 6){
				rxbits = 0x0800;    //bus_id: 2 group_id: 0
				txbits = 0x0900;    //bus_id: 2 group_id: 32
			}else if(mcs_unit_id == 7){
				rxbits = 0x0C00;    //bus_id: 3 group_id: 0
				txbits = 0x0D00;    //bus_id: 3 group_id: 32
			}else{      //If chip_unit is unkown, set return error
				FAPI_ERR("Invalid io_cleanup HWP. MCS chiplet number is unknown while setting the bus id.");
				const fapi::Target & TARGET = *i;
				FAPI_SET_HWP_ERROR(rc, IO_CLEANUP_POST_RESET_MCS_UNIT_ID_FAIL);
				return rc;
			}
			rc_ecmd |= rx_set_bits.insertFromRight(rxbits, 0, 16);
			rc_ecmd |= tx_set_bits.insertFromRight(txbits, 0, 16);
			if(rc_ecmd){rc.setEcmdError(rc_ecmd);return(rc);}
			rc = GCR_write(*i, master_interface, rx_id1_pg, master_group, 0, rx_set_bits, clear_bits,1,1);
			if(rc){
				FAPI_INF("io_cleanup rx putscom fail");
				return(rc);
			}
			rc = GCR_write(*i, master_interface, tx_id1_pg, master_group, 0, tx_set_bits, clear_bits,1,1);
			if(rc){
				FAPI_INF("in_cleanup tx putscom fail");
				return(rc);
			}
			memory_attached = true;
			rc = fapiGetOtherSideOfMemChannel( *i, attached_cen_target, fapi::TARGET_STATE_PRESENT);
			if(rc){     // An error from this means that there is no centaur attached.
				memory_attached = false;
			}else{
				rc = FAPI_ATTR_GET(ATTR_MSS_INIT_STATE, &attached_cen_target, l_attr_mss_init_state);  if(rc) return rc;
			}
			// Clear FIR on MCS and CEN (DMI FIR)
			if((memory_attached) && ((l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_CLOCKS_ON) || (l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_DMI_ACTIVE)) ){
				rc = clear_fir_reg(attached_cen_target,FIR_CEN_DMI);
				if(rc){return(rc);}
			}
			rc = clear_fir_reg(*i,FIR_CP_IOMC0_P0);
			rc_ecmd = data_buffer_64.clearBit(0,64);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			if(rc){return(rc);}
			// # cen mbi fir
			if((memory_attached) && ((l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_CLOCKS_ON) || (l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_DMI_ACTIVE)) ){
				rc = fapiPutScom(attached_cen_target, CENTAUR_MBI_FIR_0x02010800, data_buffer_64);
				if(rc) return rc;
				// # cen mbicrc syndromes
				rc = fapiPutScom(attached_cen_target, CENTAUR_MBI_CRCSYN_0x0201080C, data_buffer_64);
				if(rc) return rc;
				// # cen mbicfg configuration register
				rc = fapiPutScom(attached_cen_target, CENTAUR_MBI_CFG_0x0201080A, data_buffer_64);
				if(rc) return rc;
				// # cen dmi fir
				rc = fapiPutScom(attached_cen_target, CENTAUR_CEN_DMIFIR_0x02010400, data_buffer_64);
				if(rc) return rc;
			}
			rc = fapiPutScom(*i, MCS_MCIFIR_0x02011840, data_buffer_64);
			if(rc) return rc;
			// # pu mcicrcsyn
			rc = fapiPutScom(*i, MCS_MCICRCSYN_0x0201184C, data_buffer_64);
			if(rc) return rc;
			// # pu mcicfg
			rc = fapiPutScom(*i, MCS_MCICFG_0x0201184A, data_buffer_64);
			if(rc) return rc;
			// #dmi fir
			rc = fapiPutScom(*i, IOMC0_BUSCNTL_FIR_0x02011A00, data_buffer_64);
			if(rc) return rc;
			//Turn off indication of valid MCS for OCC
			rc = fapiPutScom(*i, MCS_MCFGPR_0x02011802, data_buffer_64);
			if(rc) return rc;
			// turn on the FIR propagator so FIR bits shut down the DMI
			if(l_attr_proc_ec_mss_reconfig_possible){
				rc_ecmd = data_buffer_64.clearBit(0,64);
				if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
				rc_ecmd = mask_buffer_64.clearBit(0,64);
				if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
				rc_ecmd = data_buffer_64.clearBit(42);
				if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
				rc_ecmd = mask_buffer_64.setBit(42);
				if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
				rc = fapiPutScomUnderMask(*i, MCS_MCICFG_0x0201184A, data_buffer_64, mask_buffer_64);
				if(rc) return rc;
			}else{
				FAPI_ERR("This processor cannot go through a reconfig loop. Please upgrade to > DD1\n");
				const fapi::Target & PROC =  master_parent_target;
				FAPI_SET_HWP_ERROR(rc, RC_IO_CLEANUP_UNSUPPORTED);
				return rc;
			}
		}
	}
	FAPI_INF("IO CleanUp: Done");
	return rc;
}


// Cleans up for Centaur Reconfig or Abus hot plug case
ReturnCode io_cleanup(const Target &master_target){
	ReturnCode rc;
	io_interface_t master_interface;
	uint32_t master_group  = 0;

	// This is a DMI/MC bus
	if( master_target.getType() == fapi::TARGET_TYPE_MCS_CHIPLET ){
		FAPI_DBG("This is a DMI bus using base DMI scom address");
		master_interface = CP_IOMC0_P0; // base scom for MC bus
		master_group     = 3; // Design requires us to do this as per scom map and layout
		rc=do_cleanup(master_target,master_interface,master_group);
		if(rc){
			FAPI_INF("io_cleanup exited early.");
			return rc;
		}
	}

	//This is an A Bus
	else if( master_target.getType() == fapi::TARGET_TYPE_ABUS_ENDPOINT ){
		// This procedure only supports DMI for now
	}
	else{
		const Target &MASTER_TARGET = master_target;
		FAPI_ERR("Invalid io_cleanup HWP invocation . Pair of targets dont belong to DMI or A bus instances");
		FAPI_SET_HWP_ERROR(rc, IO_CLEANUP_INVALID_MCS_RC);
	}
	return rc;
}



} // extern
