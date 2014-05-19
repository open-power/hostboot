/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimMacros.H $                      */
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

#ifndef _PRDFSIMMACROS_H
#define _PRDFSIMMACROS_H

#include "prdfsimServices.H"



#define PRDS_BEGIN(__NAME__) \
    PRDF::getSimServices().setTestName(__NAME__)

#define PRDS_START_SIM() \
    PRDF::getSimServices().startSim()

#define PRDS_END() \
   PRDF::getSimServices().endSim()

#define PRDS_ERROR_ENTRY(__EPATH__, __ATTNTYPE__) \
    PRDF::getSimServices().addAttnEntry(__EPATH__, __ATTNTYPE__)

#define PRDS_EXPECTED_SIGNATURE(__EPATH__, __SIGNATURE__) \
    PRDF::getSimServices().addSig(__EPATH__, __SIGNATURE__)

#define PRDS_SCR_WRITE(__EPATH__, __ADDRESS__, __DATA__) \
    PRDF::getSimServices().writeScr(__EPATH__, __ADDRESS__, __DATA__)

#define PRDS_SCR_EXPECT(__EPATH__, __ADDRESS__, __DATA__) \
    PRDF::getSimServices().expectScr(__EPATH__, __ADDRESS__, __DATA__)

#endif /* _PRDFSIMMACROS_H */
