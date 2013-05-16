/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/edi_ei_initialization/smp_unfencing_inter_enclosure_abus_links.H $ */
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
#ifndef  __SMP_UNFENCING_INTER_ENCLOSURE_ABUS_LINKS_H
#define  __SMP_UNFENCING_INTER_ENCLOSURE_ABUS_LINKS_H

#include <errl/errlentry.H>

namespace   EDI_EI_INITIALIZATION
{

/**
 *  @brief   smp_unfencing_inter_enclosure_abus_links
 *
 *           Lower functional fences of inter-enclosure Abus links
 *
 *  return  errlHndl if an error occurs
 *
 */
errlHndl_t  smp_unfencing_inter_enclosure_abus_links();

}

#endif
