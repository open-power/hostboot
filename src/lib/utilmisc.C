/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/utilmisc.C $                                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#include <util/misc.H>
#include <arch/ppc.H>

namespace Util
{

bool isSimics() __attribute__((alias("__isSimicsRunning")));
extern "C" void __isSimicsRunning() NEVER_INLINE;

void __isSimicsRunning()
{
    asm volatile("li 3, 0");
    MAGIC_INSTRUCTION(MAGIC_SIMICS_CHECK);
}

bool isSimicsRunning()
{
    static bool simics = isSimics();
    return simics;
}

};

