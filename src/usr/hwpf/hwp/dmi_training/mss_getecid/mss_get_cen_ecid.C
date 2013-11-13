/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/mss_getecid/mss_get_cen_ecid.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
// $Id: mss_get_cen_ecid.C,v 1.30 2013/11/14 16:55:39 bellows Exp $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2012
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : mss_get_cen_ecid.C
// *! DESCRIPTION : Get ECID string from target using SCOM's
// *!
// *! OWNER NAME  : Mark Bellows Email: bellows@us.ibm.com
// *! Copied From : Joe McGill's proc_cleanup code
// *!
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|  Author: |  Date:  | Comment:
//---------|----------|---------|-----------------------------------------------
//   1.30  | bellows  |11-NOV-13| Gerrit review updates
//   1.29  | bellows  |08-NOV-13| Added ATTR_MSS_INIT_STATE to track IPL states
//   1.28  | bellows  |02-OCT-13| Minor Review Comments addressed
//   1.27  | bellows  |26-SEP-13| Fixed Minor firware comment
//   1.26  | bellows  |19-SEP-13| Fixed the bug in 1.24
//   1.25  | bellows  |18-SEP-13| Back to 1.23 because of some issue
//   1.24  | bellows  |17-SEP-13| Support for external wrappers and decode
//   1.23  | bellows  |10-SEP-13| For DD2, no partial logic hardware bits
//   1.22  | jones    |18-JUN-13| <attr ec use>
//   1.21  | bellows  |14-JUN-13| ECBIT added for case when we can trust the cache enable
//   1.20  | bellows  |22-MAY-13| Bluewaterfall matching actual ECID definition
//   1.19  | bellows  |15-MAY-13| Added Bluewaterfall handling
//   1.18  | bellows  |27-MAR-13| Fixes to rc handling from reviewer comments
//   1.17  | bellows  |26-MAR-13| Additional reviewer comments
//   1.16  | bellows  |26-MAR-13| Cleanup because of Firmware Gerrit Review Comments
//   1.15  | bellows  |22-MAR-13| Changed name of ECID Attribute per Firmware request
//   1.14  | bellows  |29-JAN-13| Getting sub version, setting NWELL Attribute
//   1.13  | bellows  |24-JAN-13| Cache Disable Valid bit is ecid_128, made bit
//         |          |         | number consistent
//   1.12  | bellows  |23-JAN-13| PSRO attriubute is available in cronus dev
//   1.11  | bellows  |21-JAN-13| fixed log comment
//   1.10  | bellows  |21-JAN-13| chip sub id read, psro shell added
//   1.9   | bellows  |15-JAN-13| moved Cache Enable Information to the caller
//   1.8   | sglancy  |10-DEC-12| Corrected typo
//   1.7   | sglancy  | 6-DEC-12| Updated to coincide with firmware updates to ECID attribute
//   1.6   | sglancy  | 5-DEC-12| Updated to coincide with firmware change requests
//   1.5-1 | sglancy  | 5-DEC-12| Lost due to no update log

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <mss_get_cen_ecid.H>

extern "C" {

using namespace fapi;
//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
  fapi::ReturnCode  user_ecid(    uint8_t & o_ddr_port_status,
                                  uint8_t & o_cache_enable,
                                  uint8_t & o_centaur_sub_revision,
                                  ecid_user_struct & ecid_struct
                                  );

// HWP entry point
  fapi::ReturnCode mss_get_cen_ecid(
                                    const fapi::Target& i_target,
                                    uint8_t & o_ddr_port_status,
                                    uint8_t & o_cache_enable,
                                    uint8_t & o_centaur_sub_revision,
                                    ecid_user_struct & ecid_struct
                                    )
  {
    // return code
    fapi::ReturnCode rc;

    if(ecid_struct.valid) {

      rc = mss_parse_ecid(ecid_struct.io_ecid,
                          ecid_struct.i_checkL4CacheEnableUnknown,
                          ecid_struct.i_ecidContainsPortLogicBadIndication,
                          ecid_struct.io_ec,
                          o_ddr_port_status,
                          o_cache_enable,
                          o_centaur_sub_revision,
                          ecid_struct.o_psro,
                          ecid_struct.o_bluewaterfall_broken,
                          ecid_struct.o_nwell_misplacement );
      if(rc) return rc;

      // set the init state attribute to CLOCKS_ON
      uint8_t l_attr_mss_init_state;
      l_attr_mss_init_state=ENUM_ATTR_MSS_INIT_STATE_CLOCKS_ON;
      rc = FAPI_ATTR_SET(ATTR_MSS_INIT_STATE, &i_target, l_attr_mss_init_state);
      if(rc) return rc;

      return rc;
    }

    uint8_t l_psro;

    // mark HWP entry

    ecmdDataBufferBase scom(64);
    FAPI_IMP("Entering mss_get_cen_ecid....");
    rc = fapiGetScom( i_target, ECID_PART_0_0x00010000, scom );
    if (rc)
    {
      FAPI_ERR("mss_get_cen_ecid: could not read scom address 0x00010000" );
      return rc;
    }
    scom.reverse();
    ecid_struct.io_ecid[0] = scom.getDoubleWord(0);

    //gets the second part of the ecid and sets the attribute
    rc = fapiGetScom( i_target, ECID_PART_1_0x00010001, scom );
    if (rc)
    {
      FAPI_ERR("mss_get_cen_ecid: could not read scom address 0x00010001" );
      return rc;
    }
    scom.reverse();
    ecid_struct.io_ecid[1] = scom.getDoubleWord(0);

    uint64_t ecid[2];
    ecid[0]=ecid_struct.io_ecid[0];
    ecid[1]=ecid_struct.io_ecid[1];

    rc = FAPI_ATTR_SET(ATTR_ECID, &i_target, ecid);
    if (rc)
    {
      FAPI_ERR("mss_get_cen_ecid: Could not set ATTR_ECID" );
      return rc;
    }

    uint8_t l_checkL4CacheEnableUnknown = 0;
    rc = FAPI_ATTR_GET(ATTR_CENTAUR_EC_CHECK_L4_CACHE_ENABLE_UNKNOWN,
                       &i_target, l_checkL4CacheEnableUnknown);
    if (!rc.ok()) {
      FAPI_ERR("mss_get_cen_ecid: could not get ATTR_CENTAUR_EC_CHECK_L4_CACHE_ENABLE_UNKNOWN" );
      return rc;
    }

    uint8_t l_ecidContainsPortLogicBadIndication = 0;
    rc = FAPI_ATTR_GET(ATTR_CENTAUR_EC_ECID_CONTAINS_PORT_LOGIC_BAD_INDICATION,
                       &i_target, l_ecidContainsPortLogicBadIndication);
    if (!rc.ok()) {
      FAPI_ERR("mss_get_cen_ecid: could not get ATTR_CENTAUR_EC_ECID_CONTAINS_PORT_LOGIC_BAD_INDICATION" );
      return rc;
    }

    uint8_t l_ec;
    uint8_t l_nwell_misplacement;
    uint8_t l_bluewaterfall_broken;
    rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC, &i_target, l_ec);
    if (!rc.ok()) {
      FAPI_ERR("mss_get_cen_ecid: could not GET PRIVILEGED ATTR_EC" );
      return rc;
    }
    ecid_struct.io_ec=l_ec;

    rc = mss_parse_ecid(ecid, l_checkL4CacheEnableUnknown, l_ecidContainsPortLogicBadIndication, l_ec, o_ddr_port_status, o_cache_enable, o_centaur_sub_revision, l_psro, l_bluewaterfall_broken, l_nwell_misplacement );
    ecid_struct.o_psro=l_psro;
    ecid_struct.o_bluewaterfall_broken=l_bluewaterfall_broken;
    ecid_struct.o_nwell_misplacement=l_nwell_misplacement;

    if (rc)
    {
      FAPI_ERR("mss_get_cen_ecid: mss_parse_ecid" );
      return rc;
    }

    rc = FAPI_ATTR_SET(ATTR_MSS_PSRO, &i_target, l_psro);
    if (!rc.ok()) {
      FAPI_ERR("mss_get_cen_ecid: could not set ATTR_MSS_PSRO" );
      return rc;
    }

    rc = FAPI_ATTR_SET(ATTR_MSS_BLUEWATERFALL_BROKEN, &i_target, l_bluewaterfall_broken);
    if (!rc.ok()) {
      FAPI_ERR("mss_get_cen_ecid: could not set ATTR_MSS_BLUEWATERFALL_BROKEN" );
      return rc;
    }

    rc = FAPI_ATTR_SET(ATTR_MSS_NWELL_MISPLACEMENT, &i_target, l_nwell_misplacement);
    if (!rc.ok()) {
      FAPI_ERR("mss_get_cen_ecid: could not set ATTR_MSS_NWELL_MISPLACEMENT" );
      return rc;
    }

   // mark HWP exit
    FAPI_IMP("Exiting mss_get_cen_ecid....");
    return rc;
  }

// Decoder function which allows us to pass in just the raw ECID data and get it decoded for in the lab
// or we can just use it to set up all the needed attributes

  fapi::ReturnCode  mss_parse_ecid(uint64_t ecid[2],
                                   const uint8_t i_checkL4CacheEnableUnknown,
                                   const uint8_t i_ecidContainsPortLogicBadIndication,
                                   const uint8_t ec,
                                   uint8_t & o_ddr_port_status,
                                   uint8_t & o_cache_enable,
                                   uint8_t & o_centaur_sub_revision,
                                   uint8_t & o_psro,
                                   uint8_t & o_bluewaterfall_broken,
                                   uint8_t & o_nwell_misplacement ){
//get bit128
    uint8_t bit128=0;
    uint32_t rc_ecmd;
    fapi::ReturnCode rc;
    ecmdDataBufferBase scom(64);

    o_nwell_misplacement = 0;
    o_bluewaterfall_broken = 0;


    scom.setDoubleWord(0, ecid[1]);

    rc_ecmd = scom.extract(&bit128,63,1);
    bit128 = bit128 >> 7;
    if(rc_ecmd) {
      FAPI_ERR("mss_get_cen_ecid: could not extract cache data_valid bit" );
      rc.setEcmdError(rc_ecmd);
      return rc;
    }

    if(bit128 == 1) { // Cache enable bit is valid

    //gets bits 113 and 114 to determine the state of the cache
      uint8_t bit113_114=0;
      rc_ecmd = scom.extract(&bit113_114,48,2);
      bit113_114 = bit113_114 >> 6;
      uint8_t t;
      if(rc_ecmd) {
        FAPI_ERR("mss_get_cen_ecid: could not extract cache data" );
        rc.setEcmdError(rc_ecmd);
        return rc;
      }
    //determines the state of the cache
      if(bit113_114 == 0) t = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON;
      else if(bit113_114 == 1) t = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_A;
      else if(bit113_114 == 2) t = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_B;
      else t = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF;

    // Centaur DD1.X chips have an ECBIT in bit127, if this is zero then the
    // cache enable bits are in an unknown state. DD2.X chips and higher do not
    // have an ECBIT. The decision to look at the ECBIT is done with a Chip EC
    // Feature Attribute - the attribute XML can be easily tweaked if it is
    // found that other DD levels also have an ECBIT.
    // Centaur | DataValid | ECBIT  | Return Value   | Firmware Action | Cronus Action**|
    // 1.*     | 0         | 0 or 1 | DIS            | DIS             | DIS            |
    // 1.*     | 1         | 0      | Unk ENA/DIS/A/B| DIS             | ENA/DIS/A/B    |
    // 1.*     | 1         | 1      | ENA/DIS/A/B    | ENA/DIS*        | ENA/DIS/A/B    |
    // != 1.*  | 0         | N/A    | DIS            | DIS             | DIS            |
    // != 1.*  | 1         | N/A    | ENA/DIS/A/B    | ENA/DIS         | ENA/DIS/A/B    |
    // 
    // * firmware can suport paritial cache if it wants to for DD1.* (e.g. DD1.0 DD1.01, DD1.1 etc)
    //    However, if it chooses to, it should still make all Unk ones disabled
    // ** Cronus Action - cronus and all fapi procedures only support the original defintion of ENA/DIS/A/B
    //    Cronus actually uses its config file for the 4 values and checks the hardware via the get_cen_ecid
    //    procedure during step 11 to make sure the end user does not enable a disable cache
    //    Under cronus, the Unk information is only printed to the screen

      if (i_checkL4CacheEnableUnknown)
      {
        uint8_t bit127 = 0;
        rc_ecmd = scom.extract(&bit127,62,1);
        bit127 = bit127 >> 7;
        if(rc_ecmd) {
          FAPI_ERR("mss_get_cen_ecid: could not extract ECBIT bit" );
          rc.setEcmdError(rc_ecmd);
          return rc;
        }
        if(bit127 == 0) {
          FAPI_INF("mss_get_cen_ecid: Cache Enable Bits are in Unknown State");
          if(bit113_114 == 0) t = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_ON;
          else if(bit113_114 == 1) t = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_A;
          else if(bit113_114 == 2) t = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_B;
          else t = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_OFF;
        }
        else
        {
          FAPI_INF("mss_get_cen_ecid: Cache Enable Bits are in Known State");
        }
      }

      o_cache_enable = t;
    }
    else {
      FAPI_INF("Cache Disbled because eDRAM data bits are assumed to be bad");
      o_cache_enable = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF;
    }

    //reads in the ECID info for whether a DDR port side is good or bad
    //This is only defined for DD1.x parts
    if(i_ecidContainsPortLogicBadIndication ) {
      rc_ecmd = scom.extract(&o_ddr_port_status,50,2);
      o_ddr_port_status = o_ddr_port_status >> 6;
      if(rc_ecmd) {
        FAPI_ERR("mss_get_cen_ecid: could not extract DDR status data" );
        rc.setEcmdError(rc_ecmd);
        return rc;
      }
    }
    else {
      o_ddr_port_status = 0x0; // logic in both ports are good
    }


     //116..123         average PSRO from 85C wafer test
    uint8_t bit117_124=0;
    rc_ecmd = scom.extract(&bit117_124,52,8);
    if(rc_ecmd) {
      FAPI_ERR("mss_get_cen_ecid: could not extract PSRO" );
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    o_psro=bit117_124;

    // read the bit in the ecid to see if we are a DD1.01
   // Bit 124 DD1.01  Indicator Bit. Set to '1' for DD1.01 devices
    uint8_t bit125 =0;
    rc_ecmd = scom.extract(&bit125,60,1);
    bit125 = bit125 >> 7;
    if(rc_ecmd) {
      FAPI_ERR("mss_get_cen_ecid: could not extract dd1.01 indicator bit" );
      rc.setEcmdError(rc_ecmd);
      return rc;
    }
    o_centaur_sub_revision=bit125;
    // The ecid contains the chip's subrevision, changes in the subrevision should not
    // change firmware behavior but for the exceptions, update attributes to indicate
    // those behaviors
    if ((ec == 0x10) && (o_centaur_sub_revision < 1))
    {
  // For DD1.00, the transistor misplaced in the nwell needs some setting adjustments to get it to function
  // after DD1.00, we no longer need to make that adjustment
      o_nwell_misplacement = 1;
    }

    uint8_t bit126 =0;
    rc_ecmd = scom.extract(&bit126,61,1);
    bit126 = bit126 >> 7;
    if(rc_ecmd) {
      FAPI_ERR("mss_get_cen_ecid: could not extract dd1.03 indicator bit" );
      rc.setEcmdError(rc_ecmd);
      return rc;
    }

  // we have to look at both the bluewaterfall and the n-well misplacement to determine the proper values of the n-well
    if (ec == 0x10) {
      if(bit126 == 0)
      {
  // on and after DD1.03, we no longer need to make adjustments due to the bluewaterfall - this is before
        o_bluewaterfall_broken = 1;
      }
      else {
        o_nwell_misplacement = 0; // Assume if the bluewaterfall is fixed, then the nwell is also fixed
      }
    }

    return rc;
  }

  fapi::ReturnCode  user_ecid(    uint8_t & o_ddr_port_status,
                                  uint8_t & o_cache_enable,
                                  uint8_t & o_centaur_sub_revision,
                                  ecid_user_struct & ecid_struct
                                  ){

    return mss_parse_ecid(ecid_struct.io_ecid,
                          ecid_struct.i_checkL4CacheEnableUnknown,
                          ecid_struct.i_ecidContainsPortLogicBadIndication,
                          ecid_struct.io_ec,
                          o_ddr_port_status,
                          o_cache_enable,
                          o_centaur_sub_revision,
                          ecid_struct.o_psro,
                          ecid_struct.o_bluewaterfall_broken,
                          ecid_struct.o_nwell_misplacement );

  }


} // extern "C"
