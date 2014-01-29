/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dmi_training/mss_getecid/mss_get_cen_ecid_decode.C $ */
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
// $Id: mss_get_cen_ecid_decode.C,v 1.8 2013/10/14 16:22:30 bellows Exp $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2013
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : mss_get_cen_ecid_decode.C
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
//   1.8   | bellows  |14-OCT-13| One more sprintf update to make this hostboot/cronus agnostic
//   1.7   | bellows  |08-OCT-13| Made update so it compiles with cronus + hostboot
//   1.6   | thi      |05-OCT-13| Fix compiler error
//   1.5   | bellows  |02-OCT-13| Minor Review Comments addressed
//   1.4   | bellows  |27-SEP-13| Removed std::string
//   1.3   | bellows  |26-SEP-13| Firware comments and error checking added
//   1.2   | bellows  |25-SEP-13| Changed the format so that the ECID bits are
//         |          |         | broken into two lines.
//   1.1   | bellows  |17-SEP-13| Initial version

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi.H>
#include <mss_get_cen_ecid_decode.H>

using namespace fapi;

extern "C" {

  fapi::ReturnCode get_ecid_char(uint8_t c, char *creturn); // print helping function
  void get_ecid_checksum(char ECID[13]);

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
// HWP entry point
  fapi::ReturnCode mss_get_cen_ecid_decode(
                                           uint8_t & i_ddr_port_status,
                                           uint8_t & i_cache_enable,
                                           uint8_t & i_centaur_sub_revision,
                                           ecid_user_struct & i_user_info,
                                           char * o_display_string
                                           )
  {
    // return code
    fapi::ReturnCode rc;


//void decode_base_code(uint64_t ecid[2], uint8_t ddr_port, uint8_t cache_enable_o, uint8_t centaur_sub_revision_o, uint8_t nwell, uint8_t waterfall_broken, uint8_t user_input, uint8_t psro, uint8_t i_ec) {
    //checks the DDR ports and outputs the results
    //prints out all of the information
    uint32_t t = i_user_info.io_ecid[0];
    ecmdDataBufferBase temp(64);
    uint64_t data[2];
    data[0]=i_user_info.io_ecid[0];
    data[1]=i_user_info.io_ecid[1];
    char ecid_char;
    uint8_t c;
    float chip_version;
    char  ECID[13];
    for(int i=0;i<13;i++) ECID[i]='\0';
    uint8_t x;
    uint8_t y;
    char temp_string[200];
    uint32_t rc_num = 0;

    o_display_string[0]='\0';


    rc_num |= temp.insert(&t,32,32,0);
    t = data[0] >> 32;
    rc_num |= temp.insert(&t,0,32,0);
    for(uint8_t i=0;i<10;i++) {
      rc_num |= temp.extract(&c,4+i*6,6);
      c = c >> 2;
      rc = get_ecid_char( c, &ecid_char);
      if(rc) {
        FAPI_ERR("get_ecid_char returned with an error");
        return rc;
      }
      ECID[i]=ecid_char;
    }
    get_ecid_checksum(ECID);

    //generates the x and y location from the ecid
    t = data[1];
    rc_num |= temp.insert(&t,32,32,0);
    t = data[1] >> 32;
    rc_num |= temp.insert(&t,0,32,0);
    rc_num |= temp.extract(&x,0,8);
    rc_num |= temp.extract(&y,8,8);

    chip_version=i_user_info.io_ec/0x10;

    if(i_user_info.io_ec < 0x20) {

      if(!i_user_info.o_nwell_misplacement) chip_version = 1.01;
      if(!i_user_info.o_bluewaterfall_broken) chip_version=1.10;

    }


    if(!(i_user_info.i_user_defined & CSV)) {
      sprintf(temp_string, "ECID(1:64)   0x%016llx\n", static_cast<unsigned long long int>(i_user_info.io_ecid[0]));
      strcat(o_display_string, temp_string);
      sprintf(temp_string, "ECID(65:128) 0x%016llx\n", static_cast<unsigned long long int>(i_user_info.io_ecid[1]));
      strcat(o_display_string, temp_string);
      sprintf(temp_string, "  Wafer ID: %s\n", ECID);
      strcat(o_display_string, temp_string);
      sprintf(temp_string, "  Chip X/Y loc: x:%d y:%d\n",x,y);
      strcat(o_display_string, temp_string);
      sprintf(temp_string, "  Chip version: DD%.02f\n",chip_version);
      strcat(o_display_string, temp_string);

      if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON)   sprintf(temp_string, "  All eDRAMs Halves are good\n"); // Note A is Even, B is Odd	
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_A) sprintf(temp_string, "  eDRAM Half A is good.  eDRAM Half B is bad\n");
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_B)   sprintf(temp_string, "  eDRAM Half A is bad.  eDRAM Half B is good\n");
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF) sprintf(temp_string, "  All eDRAMs Halves are bad\n");
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_ON) sprintf(temp_string, "  All eDRAMs Halves are full unk good\n"); 
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_A) sprintf(temp_string, "  All eDRAMs A or Even unk good\n");
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_B) sprintf(temp_string, "  All eDRAMs B or odd  unk good\n");
      else sprintf(temp_string, "  All eDRAMs Halves are full unk bad\n");
      strcat(o_display_string, temp_string);

      if(i_ddr_port_status == 0)   sprintf(temp_string, "  All DDR Ports are good\n"); 	
      else if(i_ddr_port_status == 1) sprintf(temp_string, "  DDR Port 0/1 is good.  DDR Port 2/3 is bad\n");
      else if(i_ddr_port_status == 2)   sprintf(temp_string, "  DDR Port 0/1 is bad.  DDR Port 2/3 is good\n");
      else sprintf(temp_string, "  All DDR Ports are bad\n");
      strcat(o_display_string, temp_string);

      sprintf(temp_string, "  PSRO: 0x%02x %f ps\n",i_user_info.o_psro, i_user_info.o_psro*0.025+7.5);
      strcat(o_display_string, temp_string);
    }
    //prints out a CSV
    else {
      uint8_t repair,bad_edram_a,bad_edram_b;
      uint8_t bad_ddr_port01,bad_ddr_port23;
      if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_ON)  {repair=1;bad_edram_a=0;bad_edram_b=0; } 
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_A) {repair=1;bad_edram_a=0;bad_edram_b=1; }
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_HALF_B) {repair=1;bad_edram_a=1;bad_edram_b=0; }
      else if(i_cache_enable == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_OFF) {repair=1;bad_edram_a=1;bad_edram_b=1; }
//    else if(cache_enable_o == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_ON) {repair=0;bad_edram_a=0;bad_edram_b=0; } 
//    else if(cache_enable_o == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_A) {repair=0;bad_edram_a=0;bad_edram_b=1; }
//    else if(cache_enable_o == fapi::ENUM_ATTR_MSS_CACHE_ENABLE_UNK_HALF_B) {repair=0;bad_edram_a=1;bad_edram_b=0; }
      else {repair=0;bad_edram_a=1;bad_edram_b=1; }

      if(i_ddr_port_status == 0)   { bad_ddr_port01 = 0 ; bad_ddr_port23 = 0; }
      else if(i_ddr_port_status == 1)   { bad_ddr_port01 = 0 ; bad_ddr_port23 = 1; }
      else if(i_ddr_port_status == 2)   { bad_ddr_port01 = 1 ; bad_ddr_port23 = 0; }
      else    { bad_ddr_port01 = 1 ; bad_ddr_port23 = 1; }
      sprintf(o_display_string, "%s,%d,%d,%0.2f,%d,%d,%d,%d,%d,%f ps\n",ECID,x,y,chip_version,repair,bad_edram_a,bad_edram_b,bad_ddr_port01,bad_ddr_port23,((float)i_user_info.o_psro*0.025+7.5));
    }

    if(rc_num) {
      FAPI_ERR("Error occured during databuffer manipulations");
      rc.setEcmdError(rc);
    }

    return rc;
  }

//gets the character for the ECID
  fapi::ReturnCode get_ecid_char(uint8_t c, char *creturn) {
   //c is a number, so use the offset for a number
    if(c < 10) {*creturn = (char)(c+48);}
    else {*creturn = (char)(c+55);}
    return fapi::FAPI_RC_SUCCESS;
  }

//gets the checksum, the last two characters, in the ecid string
  void get_ecid_checksum(char ECID[13]) {
    char rtn[13];
    for(uint32_t i = 0; i < 10; i++) rtn[i] = ECID[i];
    rtn[10]='A';
    rtn[11]='0';
    rtn[12]='\0';
    int sum=0;
    for (uint32_t i = 0; i < 12; i++)
    {
      sum = ((sum * 8) + (rtn[i] - 32)) % 59;
    }
    if (sum != 0) {
      int adjust = 59 - sum;
      rtn[11] += adjust & 7;
      adjust >>= 3;
      rtn[10] += adjust & 7;
    }
    for (uint32_t i = 0; i < 13; i++) ECID[i] = rtn[i];
  }




} // extern "C"
