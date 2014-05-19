/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfPlatProcConst.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

//NOTE: Position at which strings representing names of TOD control registers
//are placed in regStatList cannot be changed independently. Position of string
//in the array must match value of corresponding enum member e.g. value
//of MPCR is zero, therefore, TOD_MPCR can only be placed at regStatList[0]

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

}//end namespace TOD

} // end namespace PRDF

#endif // __prdfPlatProcConst_H

