/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaTdCtlr_common.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

/** @file  prdfCenMbaTdCtlr_common.H
 *  @brief The common implementation of the MBA TD Controller.
 */

#ifndef __prdfCenMbaTdCtlr_common_H
#define __prdfCenMbaTdCtlr_common_H

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdf_types.h>
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfCenAddress.H>
#include <prdfCenConst.H>
#include <prdfCenMarkstore.H>
#include <prdfCenMbaExtraSig.H>

namespace PRDF
{

class ExtensibleChip;

/**
 * @brief A state machine for memory targeted diagnostics.
 */
class CenMbaTdCtlrCommon
{
  public: // constants, enums

    /**
     * @brief This enum will be used to indicate type of TD event requested to
     *        be handled.
     * @note  The order of the enums values is important. It is used for
     *        sorting the TdQueue by event type priority.
     */
    enum TdType
    {
        VCM_EVENT = 0, ///< A Verify Chip Mark event.
        TPS_EVENT,     ///< A Two-Phase Scrub event.
    };

  protected: // constants, enums

    /**
     * @brief Lists all possible states of TD controller
     * @note  These enums are used as array indexes to cv_cmdCompleteFuncs and
     *        the last entry will be used to get the size of the array.
     */
    enum TdState
    {
        NO_OP = 0,       ///< No TD procedures in place.
        VCM_PHASE_1,     ///< Verify Chip Mark phase 1.
        VCM_PHASE_2,     ///< Verify Chip Mark phase 2.
        DSD_PHASE_1,     ///< DRAM Spare Deploy phase 1.
        DSD_PHASE_2,     ///< DRAM Spare Deploy phase 2.
        TPS_PHASE_1,     ///< Two-Phase Scrub phase 1.
        TPS_PHASE_2,     ///< Two-Phase Scrub phase 2.
        MAX_TD_STATE     ///< The maximum number of TD states.
    };

    enum EccErrorMask
    {
        NO_ERROR  = 0,        ///< No ECC errors found
        UE        = 0x01,     ///< UE
        MPE       = 0x02,     ///< Chip mark placed
        MCE       = 0x04,     ///< CE on chip mark
        HARD_CTE  = 0x08,     ///< Hard CE threshold exceeed
        SOFT_CTE  = 0x10,     ///< Soft CE threshold exceeed
        INTER_CTE = 0x20,     ///< Intermittent CE threshold exceeed
        RETRY_CTE = 0x40,     ///< Retry CE threshold exceeed
    };

    // Common stop conditions
    enum StopConditions
    {
        COND_TARGETED_CMD =
            mss_MaintCmd::STOP_ON_RETRY_CE_ETE |
            mss_MaintCmd::STOP_ON_END_ADDRESS |
            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION,

        COND_BG_SCRUB =
            mss_MaintCmd::STOP_ON_HARD_NCE_ETE |
            mss_MaintCmd::STOP_ON_INT_NCE_ETE  |
            mss_MaintCmd::STOP_ON_SOFT_NCE_ETE |
            mss_MaintCmd::STOP_ON_RETRY_CE_ETE |
            mss_MaintCmd::STOP_ON_MPE |
            mss_MaintCmd::STOP_ON_UE |
            mss_MaintCmd::STOP_IMMEDIATE |
            mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION,

        COND_FAST_SCRUB =
            COND_BG_SCRUB |
            mss_MaintCmd::STOP_ON_END_ADDRESS,
     };

  public: // functions

    /**
     * @brief Constructor
     *
     * This constructor will be called in the MBA data bundle code. Therefore,
     * no register reads/writes can be done in this constructor. Anything needed
     * to initialize the instance variables that requires register reads/writes
     * or is non-trivial should be done in initialize().
     *
     * @param i_mbaChip An MBA chip.
     */
    explicit CenMbaTdCtlrCommon( ExtensibleChip * i_mbaChip ) :
        iv_mbaChip(i_mbaChip), iv_membChip(NULL), iv_mbaTrgt(NULL),
        iv_mbaPos(MAX_MBA_PER_MEMBUF), iv_x4Dimm(false), iv_initialized(false),
        iv_tdState(NO_OP), iv_rank(), iv_mark(), iv_mssCmd(NULL),
        iv_isEccSteer(false)
    {}

    /** @brief Destructor */
    ~CenMbaTdCtlrCommon()
    {
        delete iv_mssCmd; iv_mssCmd = NULL;
    }

    /**
     * @brief  Determines and executes the next course of action after a
     *         maintenance command complete attention.
     * @note   Initializes the TD controller, if needed.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t handleCmdCompleteEvent( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Adds a TD procedure to the queue.
     *
     * TD events are only intended to be handled during FSP runtime, however, it
     * is possible that a TD events could be triggered in Hostboot after it has
     * been flushed from the cache to system memory. All requests to handle TD
     * events during Hostboot will be ignored. Any chip marks placed at this
     * time will be found when the FSP TD controller is initialized. The error
     * log for the trigger will be committed and a trace statement will be made
     * indicating which rank and TD procedure was requested.
     *
     * @param  io_sc    The step code data struct.
     * @param  i_rank   The rank in which the event occurred.
     * @param  i_event  The event type (see enum TdType).
     * @param  i_banTps TRUE to ban any future TPS requests for this rank,
     *                  default FALSE.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     * @note   If no TD procedures are in progress, it will stop background
     *         scrub and start the next TD procedure.
     */
    virtual int32_t handleTdEvent( STEP_CODE_DATA_STRUCT & io_sc,
                                   const CenRank & i_rank,
                                   const TdType i_event,
                                   bool i_banTps = false ) = 0;
  protected: // functions

    /**
     * @brief  Initializes the TD controller and sets appropriate information
     *         in the hardware, if needed.
     *
     * Since the TD controller constructor will only be called in the MBA data
     * bundle, register reads/writes can NOT be done in the constructor.
     * Instead, anything needed to initialize the instance variables that
     * requires register reads/writes or is non-trivial should be done in
     * this function.
     *
     * @note   Should be called at the beginning of every public function to
     *         ensure the TD controller is initialized.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t initialize();

    /**
     * @brief Analyzes a non-TD command complete event.
     *
     * A maintenance command has completed but no TD are in progress. This
     * function will check for any ECC errors, unverified chip marks from a
     * reset/reload, etc. and starts any TD procedures, if necessary.
     *
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t analyzeCmdComplete( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Analyzes VCM Phase 1 results and moves state machine.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t analyzeVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Analyzes VCM Phase 2 results and moves state machine.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t analyzeVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Analyzes DSD Phase 1 results and moves state machine.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t analyzeDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Analyzes DSD Phase 2 results and moves state machine.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t analyzeDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Analyzes Tps Phase 1 results and moves state machine.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t analyzeTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Analyzes Tps Phase 2 results and moves state machine.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t analyzeTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Starts VCM Phase 1.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t startVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Starts VCM Phase 2.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t startVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Starts DSD Phase 1.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t startDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Starts DSD Phase 2.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t startDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Starts Tps Phase 1.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t startTpsPhase1( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @brief  Starts Tps Phase 2.
     * @param  io_sc The step code data struct.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t startTpsPhase2( STEP_CODE_DATA_STRUCT & io_sc ) = 0;

    /**
     * @return TRUE if currently running a targeted diagnositics procedure,
     *         FALSE otherwise.
     */
    virtual bool isInTdMode();

    /**
     * @brief  Calls the cleanupCmd() function of the command that had just
     *         completed.
     * @note   This function will clear the maintenance command complete
     *         attention. So for FSP attentions, the SDC needs to be synched
     *         before calling this function just in case there is a
     *         reset/reload.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t cleanupPrevCmd();

    /**
     * @brief  Preforms cleanup tasks that need to be done before starting the
     *         next maintenance command (i.e. clear scrub counter).
     * @param  i_clearStats TRUE to clear all scrub statistics (default), FALSE
     *                      otherwise. This is useful when we need to resume
     *                      background scrubbing on the next address and we
     *                      don't want to clear all of the scrub statistics.
     * @note   Will call cleanupPrevCmd() as part of the preparations.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t prepareNextCmd( bool i_clearStats = true );

    /**
     * @brief  Clears FIR bits that may have been a side-effect of a chip mark
     *         placed by hardware.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t chipMarkCleanup();

    /**
     * @brief  Checks if ECC errors have occurred during a maintenance command.
     * @param  o_eccErrorMask Bitwise mask indicating which ECC errors have
     *         occurred.
     * @param  io_sc Service data collector.
     * @note   This function also updates SDC Multi-Signature list for each
     *         ECC error.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t checkEccErrors( uint16_t & o_eccErrorMask,
                                    STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handle MCE event during VCM Phase 2
     * @param  io_sc Service data collector.
     * @note   This will update bad bits information in VPD, set callouts, and
     *         start the DRAM sparing procedure, if possible.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t handleMCE_VCM2( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handle MCE event during DSD Phase 2
     * @param  io_sc Service data collector.
     * @note   This will update bad bits information in VPD and set callouts.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t handleMCE_DSD2( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Will set the threshold for all runtime ETE attentions in
     *         hardware.
     * @note   This only sets the runtime thresholds but is a common function
     *         because these thresholds will need to be set before starting the
     *         initial fast scrub at the end of Hostboot.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    virtual int32_t setRtEteThresholds();

    /**
     * @brief This class is designed such that all functions will eventually
     *        return any bad error code to the top level public functions such
     *        as handleCmdCompleteEvent() and handleTdEvent(). This is a common
     *        function to handle everything needed to that the TD controller
     *        can hopefully fail gracefully.
     * @param io_sc The step code data struct.
     */
    virtual void badPathErrorHandling( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Add signature to SDC
     * @param  io_sc Service data collector.
     * @param  i_sig Error Signature.
     * @note   All signatures in TD controller are scoped to the targeted MBA.
     *         However, it is possible that the attention that triggered this
     *         TD request came from one of the MBSECCFIRs, which are on the
     *         MEMBUF. So, change the chip ID in the signature to the targeted
     *         MBA to avoid an "Undefined error code".
     */
    void setTdSignature( STEP_CODE_DATA_STRUCT & io_sc, uint32_t i_sig );

  protected: // instance variables

    /** The MBA chip that this TD controller acts on. */
    ExtensibleChip * iv_mbaChip;

    /** The MEMBUF chip connected iv_mbaChip. */
    ExtensibleChip * iv_membChip;

    /** The MBA target associated with iv_mbaChip. */
    TARGETING::TargetHandle_t iv_mbaTrgt;

    /** The position number (0-1) relative to the connected MEMBUF. */
    uint32_t iv_mbaPos;

    /** TRUE if DIMM has x4 DRAMs, FALSE if DIMM has x8 DRAMs. */
    bool iv_x4Dimm;

    /** Indicates if TD controller is initialized. */
    bool iv_initialized;

    /** The targeted diagnostics state variable (see enum TdState). */
    TdState iv_tdState;

    /** The current rank that is being targeted for diagnostics. */
    CenRank iv_rank;

    /** The current mark that is being targeted for diagnostics. */
    CenMark iv_mark;

    /** Current maintenance command */
    PlatServices::mss_MaintCmdWrapper * iv_mssCmd;

    /** Tells if in DSD procedure we should use eccSpare. */
    bool iv_isEccSteer;

}; // CenMbaTdCtlrCommon

} // end namespace PRDF

#endif // __prdfCenMbaTdCtlr_common_H

