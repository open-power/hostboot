/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar/p8_pcb_scom_errors.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
// $Id: p8_pcb_scom_errors.H,v 1.3 2013/02/16 20:26:51 stillgs Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/p8_pcb_scom_errors.H,v $
//------------------------------------------------------------------------------
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
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

