/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPlatProcConst.H $   */
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

#ifndef __prdfPlatProcConst_H
#define __prdfPlatProcConst_H

/**
 * @file  prdfPlatProcConst.H
 * @brief Defines platform specific constants for the processor.
 */
namespace PRDF
{

namespace TOD
{

// following enum represents all the tod control and status registers which
// need to be read and restored during data parity errors.
enum Register
{
    MPCR            = 0,
    PCRP0           = 1,
    PCRP1           = 2,
    SCRP0           = 3,
    SCRP1           = 4,
    SPCR            = 5,
    IPCR            = 6,
    PSMSCR          = 7,
    LAST_TOD_REG    = 8,
};

//NOTE: Position at which strings representing names of TOD control registers
//are placed in regStatList cannot be changed independently. Position of string
//in the array must match value of corresponding enum member e.g. value
//of MPCR is zero, therefore, TOD_MPCR can only be placed at regStatList[0]

static const char *regStatList[] = { "TOD_MPCR","TOD_PCRP0", "TOD_PCRP1",
                                     "TOD_SCRP0", "TOD_SCRP1","TOD_SPCR",
                                     "TOD_IPCR", "TOD_PSMSCR" };

}//end namespace TOD

} // end namespace PRDF

#endif // __prdfPlatProcConst_H

