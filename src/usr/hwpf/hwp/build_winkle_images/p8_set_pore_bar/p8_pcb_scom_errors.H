/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pcb_scom_errors.H $ */
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
// $Id: p8_pcb_scom_errors.H,v 1.3 2013/02/16 20:26:51 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pcb_scom_errors.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
//------------------------------------------------------------------------------
// *! OWNER NAME: Gebhard Weber       Email: gweber@de.ibm.com
// *!
// *! General Description: Defines FFDC error codes for the procedures
// *!                      proc_timeout_error and proc_parity_error
//------------------------------------------------------------------------------

#ifndef P8_PCB_SCOM_ERRORS_H_
#define P8_PCB_SCOM_ERRORS_H_

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

extern "C" {

    enum PCB_ERRORS {
            PIB_NO_ERROR      = 0x0,
            PIB_XSCOM_ERROR   = 0x1,
            PIB_OFFLINE_ERROR = 0x2,
            PIB_PARTIAL_ERROR = 0x3,
            PIB_ADDRESS_ERROR = 0x4,
            PIB_CLOCK_ERROR   = 0x5,
            PIB_PARITY_ERROR  = 0x6,
            PIB_TIMEOUT_ERROR = 0x7
    };

} // extern "C"

#endif // P8_PCB_SCOM_ERRORS_H_

