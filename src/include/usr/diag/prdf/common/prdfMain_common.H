/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/prdf/common/prdfMain_common.H $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2013              */
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

#ifndef __prdfMain_common_H
#define __prdfMain_common_H

/**
 * @file  prdfMain_common.H
 * @brief PRD code used by external components.
 *
 * This file contains code that is strictly common between FSP and Hostboot. All
 * platform specific code should be in the respective FSP only or Hostboot only
 * files.
 */

#include <targeting/common/target.H>

namespace PRDF
{

// Move here from iipsdbug.h
/**
 *  @brief Enum specifying attention type
 */
// If changes are made to ATTENTION_VALUE_TYPE then subsequent changes need to be made to:
// /prdf/sim/prdsimAttentionParser.C  and /prdf/sim/errl2tcd.C
enum ATTENTION_VALUE_TYPE
{
    INVALID_ATTENTION_TYPE = 0,
    MACHINE_CHECK = 1,
    CHECK_STOP = MACHINE_CHECK,
    UNIT_CS = 2,
    PROC_CS = UNIT_CS,
    RECOVERABLE = 3,
    SPECIAL = 4,
    END_ATTENTION_TYPE = 5
};

// Move here from xspprdsdbug.C
/**
 *  @brief Structure of target handle and its attention type
 */
struct AttnData
{
    TARGETING::TargetHandle_t targetHndl;
    ATTENTION_VALUE_TYPE attnType;
};

typedef std::vector<AttnData> AttnList;

//! @c prd_return_code_t : possible return values from PRD
enum prd_return_code_t
{
    //! DD00: An assert statement failed in PRD
    PRD_ASSERT = 0xDD00,

    //! DD01: An attention of this type is not expected
    PRD_INVALID_ATTENTION_TYPE = 0xDD01,

    /*! DD02: A Scan Comm Register Read indicates no bits are set in the SCR
      where active bits were expected */
    PRD_SCAN_COMM_REGISTER_ZERO = 0xDD02,

    /*! DD03: Attempted to cross a chip connection but could not resolve target
     *        chip */
    PRD_UNRESOLVED_CHIP_CONNECTION = 0xDD03,

    //! DD05: Error is internal to PRD code
    PRD_INTERNAL_CODE_ERROR = 0xDD05,

    //! DD09: Failure accessing attention data from Registry
    PRD_ATTN_DATA_ACCESS_FAILED = 0xDD09,

    //! DD11: SRC ACCESS FAILED
    SCR_ACCESS_FAILED = 0xDD11,

    //! DD12: HOM ACCESS FAILED
    HOM_ACCESS_FAILED = 0xDD12,

    //! DD20: System Analyze() is called with no domains in System (init failed?)
    NO_DOMAINS_IN_SYSTEM = 0xDD20,

    //! DD21: System Analyze() is called, but no domains in the system are at attention
    NO_DOMAINS_AT_ATTENTION = 0xDD21,

    //! DD23: PRD did not perform an analysis - Unknown chip raised attention
    NO_PRD_ANALYSIS = 0xDD23,

    //! DD24: prdMain() called before prdInitialize()
    PRD_NOT_INITIALIZED = 0xDD24,

    //! DD28: PrdStartScrub failure
    PRD_RBS_START_SCRUB_ERROR = 0xDD28,

    //! DD29: PrdResoreRbs failure
    PRD_RBS_RESTORE_ERROR = 0xDD29,

    //! DD81: Multiple bits on in Error Register
    PRD_MULTIPLE_ERRORS = 0xDD81,

    //! DD90: Scan comm access from Error Register failed
    PRD_SCANCOM_FAILURE = 0xDD90,

    //! DD91: Scan comm access from Error Register failed due to Power Fault
    PRD_POWER_FAULT = 0xDD91,

    //! DDFF: Special return code indicating Not to reset or mask FIR bits.
    PRD_NO_CLEAR_FIR_BITS = 0xDDFF,

    //! 7FFD: word13 of src 7FFDxxxx - An assert failed in PRD
    PRD_ASSERT_ERROR_SIGNATURE = 0x7FFD,

    //! 7FFF: word13 of src 7FFFxxxx - xxxx will describe the error
    PRD_EXECUTION_ERROR_SIGNATURE = 0x7FFF

};

/** Indicates if PRD has been initialized. */
extern bool g_initialized;

/**
 * @brief Initialize PRD system model and data
 * @return Error log if error occurs
 */
extern errlHndl_t initialize();

/**
 * @brief analyze attention errors
 * @param[in] i_attnType - global attention type
 * @param[in] i_attnList - list of chips at attention
 * @return Error log if error occurs
 *
 * @note If the i_attnType is CHECK_STOP than an error log is returned
 * containing the analysis; otherwise, for other attention types, PRD
 * commits the error log itself and NULL is returned.
 */
extern errlHndl_t main(ATTENTION_VALUE_TYPE i_attnType, const AttnList & i_attnList);

/**
 *  @brief Clean up pieces of PRD for fresh IPLs.
 *
 *  Cleans up the PRD persistent storage areas in P1.
 */
extern void iplCleanup();

/**
 *  @brief Remove non-functional chips from PRD config model
 *
 *  @return Error log if error occurs
 */
extern errlHndl_t refresh();

} // End namespace PRDF

#endif // __prdfMain_common_H
