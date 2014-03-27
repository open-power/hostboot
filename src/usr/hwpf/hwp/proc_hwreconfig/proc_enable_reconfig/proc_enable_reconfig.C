/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/proc_hwreconfig/proc_enable_reconfig/proc_enable_reconfig.C $ */
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
// $Id: proc_enable_reconfig.C,v 1.7 2014/03/25 21:42:37 jdsloat Exp $
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
#include <io_cleanup.H>

extern "C" {

  using namespace fapi;

  ReturnCode proc_enable_reconfig(fapi::Target & i_target_pu_mcs, fapi::Target &  i_target_cen) {

    ReturnCode rc;
    ecmdDataBufferBase mask_buffer_64(64);
    ecmdDataBufferBase data_buffer_64(64);
    uint8_t  l_attr_mss_init_state;
    uint8_t  cold=true;
    uint8_t  dmi_active=false;
    uint8_t  clocks_on=false;
    Target l_target_pu;
    uint8_t l_attr_proc_ec_mss_reconfig_possible;
    uint32_t rc_ecmd;

    // determine how far into the IPL we have gone
    rc = FAPI_ATTR_GET(ATTR_MSS_INIT_STATE, &i_target_cen, l_attr_mss_init_state);
    if(rc) return rc;

    if(l_attr_mss_init_state != ENUM_ATTR_MSS_INIT_STATE_COLD )
      cold=false;

    if(l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_CLOCKS_ON )
      clocks_on=true;

    if(l_attr_mss_init_state == ENUM_ATTR_MSS_INIT_STATE_DMI_ACTIVE ) {
      clocks_on=true;
      dmi_active=true;
    }


    if(cold) { // If the centaur has not made it past cold, then exit with success
      return rc;
    }

    rc= fapiGetParentChip(i_target_pu_mcs, l_target_pu);
    if(rc) return rc;

    rc = FAPI_ATTR_GET(ATTR_PROC_EC_MSS_RECONFIG_POSSIBLE, &l_target_pu, l_attr_proc_ec_mss_reconfig_possible);
    if(rc) return rc;

    if(dmi_active) {

      if(l_attr_proc_ec_mss_reconfig_possible) {
    // turn off the FIR propagator
        rc_ecmd = data_buffer_64.setBit(42);
        if(rc_ecmd) {
          rc.setEcmdError(rc_ecmd);
          return(rc);
        }
        rc_ecmd = mask_buffer_64.setBit(42);
        if(rc_ecmd) {
          rc.setEcmdError(rc_ecmd);
          return(rc);
        }

        rc = fapiPutScomUnderMask(i_target_pu_mcs, MCS_MCICFG_0x0201184A, data_buffer_64, mask_buffer_64);
        if(rc) return rc;

      }
      else {
        FAPI_ERR("This processor cannot go through a reconfig loop. Please upgrade to > DD1\n");
        const fapi::Target & PROC =  l_target_pu;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_ENABLE_RECONFIG_UNSUPPORTED);
        return rc;
      }
    }

    // mask firs in the MCS
    rc_ecmd = data_buffer_64.setBit(0,64);
    if(rc_ecmd) {
      rc.setEcmdError(rc_ecmd);
      return(rc);
    }
    rc = fapiPutScom(i_target_pu_mcs, MCS_MCIFIRMASK_0x02011843, data_buffer_64);
    if(rc) return rc;


    // force a channel fail only if you are up to DMI ACTIVE state on this pair
    rc_ecmd = data_buffer_64.clearBit(0,64);
    if(rc_ecmd) {
      rc.setEcmdError(rc_ecmd);
      return(rc);
    }
    rc_ecmd = data_buffer_64.setBit(0);
    if(rc_ecmd) {
      rc.setEcmdError(rc_ecmd);
      return(rc);
    }
    rc_ecmd = mask_buffer_64.clearBit(0,64);
    if(rc_ecmd) {
      rc.setEcmdError(rc_ecmd);
      return(rc);
    }
    rc_ecmd = mask_buffer_64.setBit(0);
    if(rc_ecmd) {
      rc.setEcmdError(rc_ecmd);
      return(rc);
    }

    if(dmi_active) {
      rc = fapiPutScomUnderMask(i_target_pu_mcs, MCS_MCICFG_0x0201184A, data_buffer_64, mask_buffer_64);
      if(rc) return rc;
    }

    rc_ecmd = data_buffer_64.clearBit(0,64);
    if(rc_ecmd) {
      rc.setEcmdError(rc_ecmd);
      return(rc);
    }
    rc_ecmd = data_buffer_64.setBit(0);
    if(rc_ecmd) {
      rc.setEcmdError(rc_ecmd);
      return(rc);
    }
    if(dmi_active) {
      rc = fapiPutScom(i_target_cen, CENTAUR_MBI_CFG_0x0201080A, data_buffer_64);
      if(rc) return rc;
    }

    // perform IO cleanup on active dmi channels
    if(dmi_active) {

      FAPI_INF("mcs %s / cen %s : types %d %d\n", i_target_pu_mcs.toEcmdString(), i_target_cen.toEcmdString(), i_target_pu_mcs.getType(), i_target_cen.getType() );

      rc = io_cleanup(i_target_pu_mcs, i_target_cen );
      if(rc) return rc;
    }

    if(clocks_on ){

      rc_ecmd = data_buffer_64.clearBit(0,64);
      if(rc_ecmd) {
        rc.setEcmdError(rc_ecmd);
        return(rc);
      }

      // # cen mbi fir 
      rc = fapiPutScom(i_target_cen, CENTAUR_MBI_FIR_0x02010800, data_buffer_64);
      if(rc) return rc;

    // # cen mbicrc syndromes
      rc = fapiPutScom(i_target_cen, CENTAUR_MBI_CRCSYN_0x0201080C, data_buffer_64);
      if(rc) return rc;

    // # cen mbicfg configuration register
      rc = fapiPutScom(i_target_cen, CENTAUR_MBI_CFG_0x0201080A, data_buffer_64);
      if(rc) return rc;

    // # cen dmi fir
      rc = fapiPutScom(i_target_cen, CENTAUR_CEN_DMIFIR_0x02010400, data_buffer_64);
      if(rc) return rc;

      rc = fapiPutScom(i_target_pu_mcs,  MCS_MCIFIR_0x02011840, data_buffer_64);
      if(rc) return rc;

    // # pu mcicrcsyn
      rc = fapiPutScom(i_target_pu_mcs,  MCS_MCICRCSYN_0x0201184C, data_buffer_64);
      if(rc) return rc;

    // # pu mcicfg
      rc = fapiPutScom(i_target_pu_mcs,  MCS_MCICFG_0x0201184A, data_buffer_64);
      if(rc) return rc;

    // #dmi fir
      rc = fapiPutScom(l_target_pu, MC1_BUSCNTL_FIR_0x02011E00, data_buffer_64);
      if(rc) return rc;
    }

    if(dmi_active) {
      ecmdDataBufferBase mask_buffer_64(64);
      ecmdDataBufferBase data_buffer_64(64);

    // turn on the FIR propagator so FIR bits shut down the DMI
      if(l_attr_proc_ec_mss_reconfig_possible) {
        rc_ecmd = data_buffer_64.clearBit(0,64);
        if(rc_ecmd) {
          rc.setEcmdError(rc_ecmd);
          return(rc);
        }
        rc_ecmd = mask_buffer_64.clearBit(0,64);
        if(rc_ecmd) {
          rc.setEcmdError(rc_ecmd);
          return(rc);
        }
        rc_ecmd = data_buffer_64.clearBit(42);
        if(rc_ecmd) {
          rc.setEcmdError(rc_ecmd);
          return(rc);
        }
        rc_ecmd = mask_buffer_64.setBit(42);
        if(rc_ecmd) {
          rc.setEcmdError(rc_ecmd);
          return(rc);
        }
        rc = fapiPutScomUnderMask(i_target_pu_mcs, MCS_MCICFG_0x0201184A, data_buffer_64, mask_buffer_64);
        if(rc) return rc;
      }
      else {
        FAPI_ERR("This processor cannot go through a reconfig loop. Please upgrade to > DD1\n");
        const fapi::Target & PROC =  l_target_pu;
        FAPI_SET_HWP_ERROR(rc, RC_PROC_ENABLE_RECONFIG_UNSUPPORTED);
        return rc;
      }
    }

    /*
    l_attr_mss_init_state=ENUM_ATTR_MSS_INIT_STATE_COLD; // who knows where we might end on another pass through
    rc = FAPI_ATTR_SET(ATTR_MSS_INIT_STATE, &i_target_cen, l_attr_mss_init_state);
    */
    return rc;

  }

} // extern C

