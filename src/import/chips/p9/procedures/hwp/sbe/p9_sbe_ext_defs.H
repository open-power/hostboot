/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/sbe/p9_sbe_ext_defs.H $               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// @file p9_sbe_ext_defs.H
/// @brief This file will has structures and constants that can be treated as
//         the external interfaces of the SBE.

#ifndef _P9_SBE_EXT_DEFS_H_
#define _P9_SBE_EXT_DEFS_H_

/// @brief A structure (bitfield) representing the SBE messaging register
typedef union sbeMsgReg
{
    struct
    {
#ifdef _BIG_ENDIAN
        uint32_t sbeBooted : 1; ///< SBE control loop initialized
        uint32_t reserved1 : 3; ///< Reserved
        uint32_t prevState : 4; ///< Previous SBE state
        uint32_t currState : 4; ///< Current SBE state
        uint32_t majorStep : 4; ///< Last major istep executed by the SBE
        uint32_t minorStep : 8; ///< Last minor istep executed by the SBE
        uint32_t reserved2 : 8; ///< Reserved
#else
        uint32_t reserved2 : 8; ///< Reserved
        uint32_t minorStep : 8; ///< Last minor istep executed by the SBE
        uint32_t majorStep : 4; ///< Last major istep executed by the SBE
        uint32_t currState : 4; ///< Current SBE state
        uint32_t prevState : 4; ///< Previous SBE state
        uint32_t reserved1 : 3; ///< Reserved
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
    SBE_STATE_UNKNOWN = 0, ///< Unknown state - Initial (stable state)
    SBE_STATE_FFDC = 1, ///< Waiting for SBE FFDC to be collected
    SBE_STATE_IPLING = 2, ///< IPL'ing - autonomous mode (transient state)
    SBE_STATE_ISTEP = 3, ///< IPL'ing - istep mode (transient state)
    SBE_STATE_RUNTIME = 4, ///< SBE runtime (stable state)
    SBE_STATE_DUMP = 5, ///< SBE dumping (transient state)
    SBE_STATE_MPIPL = 6, ///< SBE mpipl (transient state)
    SBE_STATE_FAILURE = 7, ///< SBE internal failure (stable state)
    SBE_STATE_ABORT = 8, ///< SBE aborted
    SBE_STATE_QUIESCE = 0xF, ///< SBE quiesce state
} sbeState_t;

#endif //_P9_SBE_EXT_DEFS_H_
