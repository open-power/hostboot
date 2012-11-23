/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimMacros.H $                      */
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
