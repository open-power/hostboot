//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/diag/prdf/prdf_proto.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END


#ifndef PRDF_PROTO_H
#define PRDF_PROTO_H

/**
 * @file prdf_proto.H
 * @brief Interface to Processor Run-time Diagnostics (PRD)
 * @par
 * This includes all type definitions, function interfaces/contracts and
 * return codes for PRD.
 * These prototypes specify the functions that can be called externally
 * from other binds.
 */


#include <stdint.h>
#include <errl/errlentry.H>
#include <targeting/common/target.H>

namespace PRDF
{

// Move here from iipsdbug.h
/**
 *  @brief Enum specifying attention type
 */
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


/**
 *  @brief Enum specifying all possible PRD returned code
 */
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


/**
 * @brief Initialize PRD system model and data
 * @return Error log if error occurs
 */
extern errlHndl_t PrdInitialize();

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
extern errlHndl_t PrdMain(ATTENTION_VALUE_TYPE i_attnType, const AttnList & i_attnList);

/**
 *  @brief initiate memory background scrubbing
 *  @param[in] i_pTarget - Target handle of System or Node
 *  @return Error log if error occurs
 */
extern errlHndl_t PrdStartScrub(const TARGETING::TargetHandle_t i_pTarget);

/**
 * @brief  Restores hardware DRAM repairs to reflect what is stored in VPD.
 * @param[in]  i_pTarget - Target handle of the memory controller
 * @return Non-SUCCESS if conditions are such that a callout had to be made, SUCCESS othewise.
 */
extern int32_t prdfRestoreDramRepairs(const TARGETING::TargetHandle_t i_pTarget);


/**
 *  @brief Clean up pieces of PRD for fresh IPLs.
 *
 *  Cleans up the PRD persistent storage areas in P1.
 */
extern void PrdIplCleanup();


#ifndef __HOSTBOOT_MODULE

/**
 *  @brief handle service data collector sync over
 *  @return Error log if error occurs
 */
extern errlHndl_t prdfFailoverComplete(void);

#endif


} // End namespace PRDF

#endif       // PRDF_PROTO_H
