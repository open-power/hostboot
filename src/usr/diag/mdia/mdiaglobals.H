/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiaglobals.H $                             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __MDIA__MDIAGLOBALS_H
#define __MDIA__MDIAGLOBALS_H

/**
 * @file mdiaglobals.H
 * @brief memory diagnostics global variables
 */

#include "mdiafwd.H"
#include <stdint.h>

namespace MDIA
{

/**
 * @brief memory diagnostics step global variables
 */
struct Globals
{
    /**
     * @brief policy flags
     */
    uint64_t mfgPolicy;

    /**
     * @brief user interface policy
     */
    uint64_t userPolicy;

    /**
     * @brief flag to indicate running in simics env
     */
    bool simicsRunning;

    /**
     * @brief flag to disable scrubs after pattern test
     */
    bool disableScrubs;


    Globals(): mfgPolicy(0), userPolicy(0),
       simicsRunning(false), disableScrubs(false) {}

};
}
#endif
