/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfP8ProcExtraSig.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

#ifndef __prdfP8ProcExtraSig_H
#define __prdfP8ProcExtraSig_H

#include <prdrSignatures.H>

PRDR_ERROR_SIGNATURE( PCI_OSC0_FAILOVER,  0x00ed0001, "","PCI Osc0 Failed" );
PRDR_ERROR_SIGNATURE( PCI_OSC1_FAILOVER,  0x00ed0002, "","PCI Osc1 Failed" );
PRDR_ERROR_SIGNATURE( MULTI_PROC_PCI_OSC0_FAILOVER,  0x00ed0003, "",
                      "PCI Osc0 Failed: Multiple Proc" );
PRDR_ERROR_SIGNATURE( MULTI_PROC_PCI_OSC1_FAILOVER,  0x00ed0004, "",
                      "PCI Osc1 Failed: Multiple Proc" );
PRDR_ERROR_SIGNATURE( PCI_OSC_FALSE_ALARM,0x00ed0005, "",
                      "PCI Osc Failed: False Alarm" );
PRDR_ERROR_SIGNATURE( PCI_OSC_ANL_FAILED, 0x00ed0006, "",
                      "PCI Osc Switch Over: Analysis failed" );
PRDR_ERROR_SIGNATURE( PCI_MULTIPLE_OSC_FO, 0x00ed0007, "",
                      "PCI Osc Failed: Multiple Osc" );

#endif // __prdfP8ProcExtraSig.H
