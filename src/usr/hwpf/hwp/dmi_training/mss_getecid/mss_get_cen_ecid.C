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
// $Id: mss_get_cen_ecid.C,v 1.18 2013/03/27 13:20:55 bellows Exp $
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
#include "mss_get_cen_ecid.H"

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


// HWP entry point
fapi::ReturnCode mss_get_cen_ecid(
    const fapi::Target& i_target,
    uint8_t & o_ddr_port_status,
    uint8_t & o_cache_enable,
    uint8_t & o_centaur_sub_revision
    )
{
    // return code
    fapi::ReturnCode rc;
    uint64_t data[2];
    uint32_t rc_ecmd;
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
    data[0] = scom.getDoubleWord(0);
    //gets the second part of the ecid and sets the attribute
    rc = fapiGetScom( i_target, ECID_PART_1_0x00010001, scom );
    if (rc)
    {
        FAPI_ERR("mss_get_cen_ecid: could not read scom address 0x00010001" );
        return rc;
    }
    scom.reverse();
    data[1] = scom.getDoubleWord(0);
    rc = FAPI_ATTR_SET(ATTR_ECID, &i_target, data);
    if (rc)
    {
        FAPI_ERR("mss_get_cen_ecid: set ATTR_ECID" );
        return rc;
    }

    //get bit128
    uint8_t bit128=0;
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
      o_cache_enable = t;
    }
    else {
      FAPI_INF("Cache Dissbled because eDRAM data bits are assumed to be bad");
      o_cache_enable = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF;
    }

    //reads in the ECID info for whether a DDR port side is good or bad
    rc_ecmd = scom.extract(&o_ddr_port_status,50,2);
    o_ddr_port_status = o_ddr_port_status >> 6;
    if(rc_ecmd) {
       FAPI_ERR("mss_get_cen_ecid: could not extract DDR status data" );
       rc.setEcmdError(rc_ecmd);
       return rc;
    }

     //116..123         average PSRO from 85C wafer test
    uint8_t bit117_124=0;
    rc_ecmd = scom.extract(&bit117_124,52,8);
    if(rc_ecmd) {
       FAPI_ERR("mss_get_cen_ecid: could not extract PSRO" );
       rc.setEcmdError(rc_ecmd);
       return rc;
    }
    rc = FAPI_ATTR_SET(ATTR_MSS_PSRO, &i_target, bit117_124);
    if (!rc.ok()) {
       FAPI_ERR("mss_get_cen_ecid: could not set ATTR_MSS_PSRO" );
       return rc;
    }

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
    uint8_t ec;
    uint8_t l_nwell_misplacement = 0;
    rc = FAPI_ATTR_GET_PRIVILEGED(ATTR_EC, &i_target, ec);
    if (!rc.ok()) {
       FAPI_ERR("mss_get_cen_ecid: could not GET PRIVILEGED ATTR_EC" );
       return rc;
    }
    if ((ec == 0x10) && (o_centaur_sub_revision < 1))
    {
  // For DD1.00, the transistor misplaced in the nwell needs some setting adjustments to get it to function
  // after DD1.00, we no longer need to make that adjustment
       l_nwell_misplacement = 1;
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

} // extern "C"
