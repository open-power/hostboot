/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/p8_ivrm.H $                  */
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
// $Id: p8_ivrm.H,v 1.2 2013/10/23 12:55:19 jimyac Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_ivrm.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Greg Still         Email: stillgs@us.ibm.com
// *!
// *! General Description:
// *!        #M IVRM Vital Product Data Structure
//------------------------------------------------------------------------------
//  
// 
// 

#define CHIPLETS 12

// 4 x 2B = 8B per measurement 
typedef struct IVRM_MEASUREMENT {
    uint16_t            gate_voltage;       // V1: mV, V2: uV
    uint16_t            drain_voltage;      // V1: mV, V2: uV
    uint16_t            source_voltage;     // V1: mV, V2: uV
    uint16_t            drain_current;      // V1: mA, V2: uA
} ivrm_measurement_t;

// 8B x 32 measurements = 256B cal data
#define IVRM_CAL_POINTS 32
typedef struct IVRM_CAL_DATA {
    uint32_t            point_valid;              // bit vector indicating valid points 
    double             Coef[4];                      
    ivrm_measurement_t  point[IVRM_CAL_POINTS];
} ivrm_cal_data_t;

// Murano:  256B x 6  = 1036B + 2 (temp) = 1038B
// Venice:  256B x 12 = 2072B + 2 (temp) = 2074B

typedef struct IVRM_EX_CAL_DATA 
{
    uint16_t            temp;       // binary in degrees C
    uint16_t            ex_valid;   // bit vector of valid chiplets, left justified
    ivrm_cal_data_t     ex[CHIPLETS];
} ivrm_ex_cal_data_t;

// 4 byte header
typedef struct IVRM_MVPD_HEADER 
{
    char                name[2];       // Two character ID
    uint8_t             length;        // Version 1: milli units; Version 2: micro units  
    uint8_t             version;
} ivrm_mvpd_header_t;


typedef struct IVRM_MVPD 
{
    ivrm_mvpd_header_t  header;
    ivrm_ex_cal_data_t  data;
} ivrm_mvpd_t;

// Chiplet numbering to indexing needs translation if VPD is held "packed" 
// (eg 0:5 for Murano; 0:11 for Venice)
//
// Murano translation
//   Index 0  <> EX 4
//   Index 1  <> EX 5
//   Index 2  <> EX 6
//   Index 3  <> EX C (12)
//   Index 4  <> EX D (13)
//   Index 5  <> EX E (14)
//
// Venice translation
//   Index 0  <> EX 1
//   Index 1  <> EX 2
//   Index 2  <> EX 3
//   Index 3  <> EX 4
//   Index 4  <> EX 5
//   Index 5  <> EX 6
//   Index 6  <> EX 9
//   Index 7  <> EX A (10)
//   Index 8  <> EX B (11)
//   Index 9  <> EX C (12)
//   Index 10 <> EX D (13)
//   Index 11 <> EX E (14)
