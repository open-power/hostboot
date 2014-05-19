/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_slw_build/p8_pore_api_const.h $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
/* $Id: p8_pore_api_const.h,v 1.2 2012/06/11 20:55:00 cmolsen Exp $ */
/* $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/utils/p8_pore_api_const.h,v $ */

/**
  * Contains any constants uses as inputs or outputs to the p7p_pore functions
  */

// CMO-20120601: SCOM Operators moved to p8_pore_table_gen_api.H
/****************************/
/*****  SCOM Operators  *****/
/****************************/
//#define P8_PORE_SCOM_APPEND  0  /* add scom instructions to the end of the existing image */
//#define P8_PORE_SCOM_REPLACE 1  /* replace existing instructions with new data */
//#define P8_PORE_SCOM_OR      2  /* overlay scom data onto existing instruction by bitwise OR */
//#define P8_PORE_SCOM_AND     3  /* overlay scom data onto existing instruction by bitwise AND */
//#define P8_PORE_SCOM_NOOP    4  /* replace existing instructions with NOP */
//#define P8_PORE_SCOM_LAST_OP 4  /* keep track of the last op for checking correctness of op input */


/***************************/
/*****  CPU Registers  *****/
/***************************/
#define P8_PORE_HSPRG0  304
#define P8_PORE_HRMOR   313
#define P8_PORE_LPCR    318
#define P8_PORE_HMEER   337
#define P8_PORE_HID0   1008
#define P8_PORE_HID1   1009
#define P8_PORE_HID4   1012
#define P8_PORE_HID5   1014
#define P8_PORE_MSR    2000


/****************************/
/*****  Branch Types    *****/
/****************************/
#define P8_PORE_BRA_REL  0  /* generate relative branch instruction */
#define P8_PORE_BRA_SUB  1  /* generate branch to subroutine instruction */


/**************************/
/*****  Return Codes  *****/
/**************************/
#define P8_PORE_SUCCESS_RC          0x00000000  /* Success, no errors */
#define P8_PORE_IMAGE_TOO_BIG_RC    0x00000001  /* size of PORE image exceeded allowed space */
#define P8_PORE_BAD_ARG_RC          0x00000002  /* some input argument is nonsensical */
#define P8_PORE_NO_ADDR_FOUND_RC    0x00000003  /* address to overlay not found */
#define P8_PORE_MULT_ADDR_FOUND_RC  0x00000004  /* address to replace/overlay found multiple times */
#define P8_PORE_MULT_SPR_FOUND_RC   0x00000005  /* spr to add/replace found multiple times*/
#define P8_PORE_BAD_RING_ADDR_RC    0x00000006  /* don't recognize the ring addr*/


/* may need to include errors for 128byte_bound check and cpureg_status check */
/*...etc...*/

/*
*************** Do not edit this area ***************
This section is automatically updated by CVS when you check in this file.
Be sure to create CVS comments when you commit so that they can be included here.

$Log: p8_pore_api_const.h,v $
Revision 1.2  2012/06/11 20:55:00  cmolsen
Updated to comment out the Scom operation defines which are now defined in
p8_pore_table_gen_api.H instead.

Revision 1.1  2011/08/25 12:32:33  yjkim
initial checkin

Revision 1.7  2010/11/03 19:13:16  schwartz
Added code to gen_cpureg to handle changes to MSR

Revision 1.6  2010/08/30 23:27:16  schwartz
Added TRACE statements to include specified number of arguments
Defined branch type constants
Added constant for last scom op used to check if operation input to gen_scan is valid
Added mult spr error constant
Added p7p_pore_gen_wait API
Changed additional C++ style comments to C style
Initialized all variables to 0
Removed FTRACE statements
Added additional information to trace statements
Updated gen_scom to use the defined operation constants
Updated branch gen_relbranch to use defined branch type constants
Added rc check for calls to p7p_pore_gen_cpureg_status and p7p_pore_span_128byte_boundary subroutines

Revision 1.5  2010/08/26 15:13:34  schwartz
Fixed more C++ style comments to C style comments

Revision 1.4  2010/08/26 03:57:02  schwartz
Changed comments to C-style
Changed "" to <> for #includes
Moved RINGINFO struct and RINGINDEX constant into separate object file, includes created static_data.h file
Put p7p_pore in front of #defines
Removed ring length from ringInfoStruct
Renamed scom operators to have SCOM in the name
Fixed gen_scan to use SCANRD and SCANWR pore instructions
Fixed compiler warnings

Revision 1.3  2010/06/23 23:07:40  schwartz
Updated define statements for SPRs, constant values are actual SPR values from Book IV

Revision 1.2  2010/05/24 02:33:14  schwartz
Fixed errors that appear when using -Werrors flag
Added in cvs logging (hopefully)


*/

