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
// $Id: mss_get_cen_ecid.C,v 1.13 2013/01/24 18:29:59 bellows Exp $
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
    uint8_t & ddr_port_status,
    uint8_t & cache_enable_o,
    uint8_t & centaur_sub_revision_o
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
    rc = FAPI_ATTR_SET(ATTR_MSS_ECID, &i_target, data);
    if (rc)
    {
        FAPI_ERR("mss_get_cen_ecid: set ATTR_MSS_ECID" );
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
      cache_enable_o = t;
    }
    else {
      FAPI_INF("Cache Dissbled because eDRAM data bits are assumed to be bad");
      cache_enable_o = fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF;
    }

//    //sets the cache attribute and error checks
//    rc = FAPI_ATTR_SET(ATTR_MSS_CACHE_ENABLE, &i_target, t);
//    if (!rc.ok()) {
//       FAPI_ERR("mss_get_cen_ecid: could not set ATTR_MSS_CACHE_ENABLE" );
//       return rc;
//    }
    
    //reads in the ECID info for whether a DDR port side is good or bad
    rc_ecmd = scom.extract(&ddr_port_status,50,2);
    ddr_port_status = ddr_port_status >> 6;
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
    centaur_sub_revision_o=bit125;

   // mark HWP exit
    FAPI_IMP("Exiting mss_get_cen_ecid....");
    return rc;
}

} // extern "C"
