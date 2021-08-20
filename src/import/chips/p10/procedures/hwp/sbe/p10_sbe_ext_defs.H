/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/sbe/p10_sbe_ext_defs.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
/// @file p10_sbe_ext_defs.H
/// @brief This file will has structures and constants that can be treated as
//         the external interfaces of the SBE.

#ifndef _P10_SBE_EXT_DEFS_H_
#define _P10_SBE_EXT_DEFS_H_

/// @brief A structure (bitfield) representing the SBE messaging register
typedef union sbeMsgReg
{
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t sbeBooted : 1; ///< SBE control loop initialized
        uint32_t asyncFFDC : 1; // < async ffdc present on sbe
        uint32_t reserved1 : 2; ///< Reserved
        uint32_t prevState : 4; ///< Previous SBE state
        uint32_t currState : 4; ///< Current SBE state
        uint32_t majorStep : 8; ///< Last major istep executed by the SBE
        uint32_t minorStep : 6; ///< Last minor istep executed by the SBE
        uint32_t reserved2 : 2; ///< Reserved
        uint32_t iv_progressCode  : 4;
#else
        uint32_t iv_progressCode  : 4;
        uint32_t reserved2 : 2; ///< Reserved
        uint32_t minorStep : 6; ///< Last minor istep executed by the SBE
        uint32_t majorStep : 8; ///< Last major istep executed by the SBE
        uint32_t currState : 4; ///< Current SBE state
        uint32_t prevState : 4; ///< Previous SBE state
        uint32_t reserved1 : 2; ///< Reserved
        uint32_t asyncFFDC : 1; // < async ffdc present on sbe
        uint32_t sbeBooted : 1; ///< SBE control loop initialized
#endif
    };
    uint32_t reg; ///< The complete SBE messaging register as a uint32
} sbeMsgReg_t;

/**
 * @brief Enumeration of SBE states
*/
typedef enum sbeState
{
    SBE_STATE_UNKNOWN = 0x0, // Unkown, initial state
    SBE_STATE_IPLING  = 0x1, // IPL'ing - autonomous mode (transient)
    SBE_STATE_ISTEP   = 0x2, // ISTEP - Running IPL by steps (transient)
    SBE_STATE_MPIPL   = 0x3, // MPIPL
    SBE_STATE_RUNTIME = 0x4, // SBE Runtime
    SBE_STATE_DMT     = 0x5, // Dead Man Timer State (transient)
    SBE_STATE_DUMP    = 0x6, // Dumping
    SBE_STATE_FAILURE = 0x7, // Internal SBE failure
    SBE_STATE_QUIESCE = 0x8, // This state quiesces any seeprom access
    SBE_STATE_HALT    = 0x9, // SBE halted via chip-op driven from Hostboot.Needs SBE reset to get out

    // Max States, Always keep it at the last of the enum and sequential
    SBE_MAX_STATE     = 0xA,
    // Don't count this in the state, just to intialize the state variables
    SBE_INVALID_STATE = 0xF,
} sbeState_t;

#endif //_P10_SBE_EXT_DEFS_H_
