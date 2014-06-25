/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/proc_hwreconfig/proc_enable_reconfig/proc_enable_reconfig.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: proc_enable_reconfig.C,v 1.15 2014/06/20 18:58:18 steffen Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_enable_reconfig.C,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *!  Licensed material - Program property of IBM
// *!  Refer to copyright instructions form no. G120-2083
// *! Created on Thu Oct 31 2013 at 10:28:49
//------------------------------------------------------------------------------
// *! TITLE       : proc_enable_reconfig
// *! DESCRIPTION : see additional comments below
// *! OWNER NAME  :  Jacob Sloat   Email: jdsloat@us.ibm.com
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
//   1.12  | jdsloat  |14-MAY-14| Fixed target name l_target_pu_mcs to i_target_pu_mcs
//   1.11  | jdsloat  |13-MAY-14| Removed unused attribute l_attr_feature_venice
//   1.10  | jdsloat  |08-MAY-14| Changed  MC1_BUSCNTL_FIR_0x02011E00 to IOMC0_BUSCNTL_FIR_0x02011A00 chiplet address to cover MC0 for venice.
///  1.9   | dcrowell |02-MAY-14| Corrected comment in previous commit
//   1.8   | jdsloat  |02-MAY-14| Added initializing of MCS_MCFGPR_0x02011802 to all 0s according to SW259625 by Dan Crowell
//   1.7   | jdsloat  |25-MAR-14| Added return rc to the end of the code
//   1.6   | jdsloat  |14-MAR-14| Commented out INIT_STATE set at the end of procedure.  SW245901
//   1.5   | bellows  |17-FEB-14| Deconfig a proc if error found - SW246059
//   1.4   | bellows  |13-NOV-13| Fixed up rc_ecmd problems from review
//   1.3   | bellows  |11-NOV-13| Firmware review updates
//   1.2   | bellows  |08-NOV-13| Simpified + added attributes
//   1.1   | bellows  |07-NOV-13| Created from proc_prep_for_reconfig.C
#include <fapi.H>
#include "proc_enable_reconfig.H"
#include <p8_scom_addresses.H>
#include <cen_scom_addresses.H>
#include "gcr_funcs.H"

extern "C" {

	using namespace fapi;

// For clearing the FIR mask , used by io run training
// As per Irving , it should be ok to clear all FIRs here since we will scom init , also we dont touch mask values
fapi::ReturnCode clear_fir_reg(const fapi::Target &i_target,fir_io_interface_t i_chip_interface){
	ReturnCode rc;
	ecmdDataBufferBase data(64);
	FAPI_INF("Clear Fir Reg:In the Clear FIR RW register function on %s", i_target.toEcmdString());
	rc = fapiPutScom(i_target, fir_rw_reg_addr[i_chip_interface], data);
	if (!rc.ok()){FAPI_ERR("Error writing FIR mask register (=%08X)!",fir_rw_reg_addr[i_chip_interface]);}
	return(rc);
}

// Cleans up for Centaur Reconfig
ReturnCode proc_enable_reconfig_cleanup(const Target &master_target){
	ReturnCode rc;
	io_interface_t master_interface;
	master_interface                             = CP_IOMC0_P0; // base scom for MC bus
	uint32_t master_group                        = 3;  // Design requires us to do this as per scom map and layout
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

	// Verify MCS Chiplet Type
	if(master_target.getType() != fapi::TARGET_TYPE_MCS_CHIPLET){
		const Target &MASTER_TARGET = master_target;
		FAPI_ERR("Invalid io_cleanup HWP invocation . Pair of targets dont belong to DMI bus instances");
		FAPI_SET_HWP_ERROR(rc, PROC_ENABLE_RECONFIG_CLEANUP_INVALID_MCS_RC);
		return(rc);
	}

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

	// Get Master Parent Target
	rc = fapiGetParentChip(master_target, master_parent_target); if(rc){return rc;}
	// Get mcs_chiplets list on processor
	rc = fapiGetChildChiplets(master_parent_target,fapi::TARGET_TYPE_MCS_CHIPLET,mcs_chiplets, fapi::TARGET_STATE_PRESENT); if(rc){return rc;}

	// Loop over all present MCS chiplets in the controller, to see if a reset is required
	for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin(); i != mcs_chiplets.end(); i++){
		rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), mcs_unit_id);   // read chip unit number
		if(rc){return rc;}
		if((mcs_unit_lower_limit <= mcs_unit_id) && (mcs_unit_id <= mcs_unit_upper_limit)){    //To limit these actions to a single DMI controller
			rc = fapiGetOtherSideOfMemChannel( *i, attached_cen_target, fapi::TARGET_STATE_PRESENT);
			if(!rc){     // An error from this means that there is no centaur attached.
				rc = FAPI_ATTR_GET(ATTR_MSS_INIT_STATE, &attached_cen_target, l_attr_mss_init_state);  if(rc) return rc;
				if(l_attr_mss_init_state != ENUM_ATTR_MSS_INIT_STATE_COLD){
					reset_required = true;
					break;
				}
			}else{
				rc = FAPI_RC_SUCCESS;
			}
		}
	}
	if(!reset_required){
		return(rc);
	}

	FAPI_INF("CleanUp: Global Reset Required");

	// Get l_attr_proc_ec_mss_reconfig_possible, an attribute that states whether the part is DD1(0) or DD2(1)
	rc = FAPI_ATTR_GET(ATTR_PROC_EC_MSS_RECONFIG_POSSIBLE, &master_parent_target, l_attr_proc_ec_mss_reconfig_possible); if(rc){return rc;}
	if(!l_attr_proc_ec_mss_reconfig_possible){
		FAPI_ERR("This processor cannot go through a reconfig loop. Please upgrade to > DD1\n");
		const fapi::Target & PROC =  master_parent_target;
		FAPI_SET_HWP_ERROR(rc, RC_PROC_ENABLE_RECONFIG_CLEANUP_UNSUPPORTED);
		return rc;
	}

	// Loop over all present MCS chiplets in the controller
	// Turn off FIR propagator, Mask FIRs, and force channel fail
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
			rc_ecmd = data_buffer_64.setBit(42);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc_ecmd = mask_buffer_64.setBit(42);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc = fapiPutScomUnderMask(*i, MCS_MCICFG_0x0201184A, data_buffer_64, mask_buffer_64);  if(rc) return rc;

			// Mask firs in the MCS, We do not mask firs on Centaur as they should not matter
			rc_ecmd = data_buffer_64.setBit(0,64);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc = fapiPutScom(*i, MCS_MCIFIRMASK_0x02011843, data_buffer_64); if(rc) return rc;

			// Force a channel fail on mcs and on Centaur if possible
			// ***
			// *** Causes too many bus errors on Centaur side.  This is okay as long as the function makes it to clearing the firs after reset.
			// *** If GCR hang after reset happens, the function will exit early before clearing firs and cause too many bus errors
			// *** GCR hang is fixed by doing global reset! Since global reset also does a GCR reset.
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
				if(rc) return rc;
			}

			// Set fence bits on mcs and on Centaur if possible
			rc_ecmd = set_bits.setBit(0);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
			rc = GCR_write(*i, master_interface,  rx_fence_pg, master_group, 0, set_bits, set_bits, 1, 1);
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
	if (!rc.ok()){FAPI_ERR("Error Reading SCOM mode PB register for ioreset_hard_bus0 on master side(%08X)!",scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0]); return rc;}
	rc_ecmd = data_buffer_64.setBit(2,6);  // Scom_mode_pb ,ioreset starts at bit 2, will reset every mcs on the memory controller
	if(rc_ecmd){rc.setEcmdError(rc_ecmd);return(rc);}
	rc = fapiPutScom(master_target, scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0], data_buffer_64);
	if (!rc.ok()){FAPI_ERR("Error Writing SCOM mode PB register for ioreset_hard_bus0 on master side(%08X)!",scom_mode_pb_reg_addr[FIR_CP_IOMC0_P0]); return rc;}

	// cen
	for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin(); i != mcs_chiplets.end(); i++){
		rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), mcs_unit_id);   // read chip unit number
		if (!rc.ok()){FAPI_ERR("Error retreiving MCS chiplet number, while resetting Centaurs.");return rc;}
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
	FAPI_INF("CleanUp: Global Reset Done");
	/// reset end

	// Set Bus IDs, Clear FIRs, Turn on FIR Propagator
	for (std::vector<fapi::Target>::iterator i = mcs_chiplets.begin(); i != mcs_chiplets.end(); i++){
		rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &(*i), mcs_unit_id);   // read chip unit number
		if (!rc.ok()){FAPI_ERR("Error retreiving MCS chiplet number, while setting bus id.");return rc;}
		if((mcs_unit_lower_limit <= mcs_unit_id) && (mcs_unit_id <= mcs_unit_upper_limit)){    //To limit these actions to a single DMI controller
			// Set Bus IDs -- Must rewrite bus ids after reset since reset sets all bus ids to 0 and there would be contention on the GCR ring
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
				FAPI_SET_HWP_ERROR(rc, PROC_ENABLE_RECONFIG_CLEANUP_POST_RESET_MCS_UNIT_ID_FAIL);
				return rc;
			}
			rc_ecmd |= rx_set_bits.insertFromRight(rxbits, 0, 16);
			rc_ecmd |= tx_set_bits.insertFromRight(txbits, 0, 16);
			if(rc_ecmd){rc.setEcmdError(rc_ecmd);return(rc);}
			// We do not need to rewrite bus ids for Centaur.
			// Write RX bus id on MCS
			rc = GCR_write(*i, master_interface, rx_id1_pg, master_group, 0, rx_set_bits, clear_bits,1,1);
			if(rc){
				FAPI_INF("io_cleanup rx putscom fail");
				return(rc);
			}
			// Write TX bus id on MCS
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
			if(rc){return(rc);}
			rc_ecmd = data_buffer_64.clearBit(0,64);
			if(rc_ecmd){ rc.setEcmdError(rc_ecmd); return(rc);}
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
			// # dmi fir
			rc = fapiPutScom(*i, IOMC0_BUSCNTL_FIR_0x02011A00, data_buffer_64);
			if(rc) return rc;
			//Turn off indication of valid MCS for OCC
			rc = fapiPutScom(*i, MCS_MCFGPR_0x02011802, data_buffer_64);
			if(rc) return rc;

			// Turn on the FIR propagator so FIR bits shut down the DMI
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
		}
	}
	FAPI_INF("CleanUp: Done");
	return rc;
}


ReturnCode proc_enable_reconfig(fapi::Target & i_target_pu_mcs) {
	ReturnCode rc;
	uint8_t mcs_unit_id = 0x0;     // Valid values for DMI0 (0-3) and DMI1 (4-7)
	rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &i_target_pu_mcs, mcs_unit_id);   // read mcs unit id value
	if(rc){return rc;}
	if((mcs_unit_id == 0) || (mcs_unit_id == 4) ){     // calls proc_enable_reconfig_cleanup only if mcs unit id is 0 or 4 (beginning of each memory controller)
		FAPI_INF("mcs %s : type %d\n", i_target_pu_mcs.toEcmdString(), i_target_pu_mcs.getType() );
		rc = proc_enable_reconfig_cleanup(i_target_pu_mcs);
		if(rc) return rc;
	}
	return rc;
}

} // extern C

