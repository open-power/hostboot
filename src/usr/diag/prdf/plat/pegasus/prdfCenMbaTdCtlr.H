/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/pegasus/prdfCenMbaTdCtlr.H $           */
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

/** @file  prdfCenMbaTdCtlr.H
 *  @brief The Hostboot implementation of the MBA TD Controller.
 */

#ifndef __prdfCenMbaTdCtlr_H
#define __prdfCenMbaTdCtlr_H

#include <prdfCenMbaTdCtlr_common.H>

namespace PRDF
{

/**
 * @brief A state machine for memory targeted diagnostics during Hostboot MDIA.
 */
class CenMbaTdCtlr : public CenMbaTdCtlrCommon
{
  private: // constants, enums

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
        MAX_TD_STATE     ///< The maximum number of TD states.
    };

    // Function pointers for maintenance command complete events.
    typedef int32_t (CenMbaTdCtlr::*CMD_COMPLETE_FUNCS)
                                            ( STEP_CODE_DATA_STRUCT & io_sc );

  public: // functions

    /**
     * @brief Constructor
     *
     * This contructor will be called in the MBA data bundle code. Therefore,
     * no register reads/writes can be done in this constructor. Anything needed
     * to initialize the instance variables that requires register reads/writes
     * or is non-trivial should be done in initialize().
     *
     * @param i_mbaChip An MBA chip.
     */
    explicit CenMbaTdCtlr( ExtensibleChip * i_mbaChip ) :
        CenMbaTdCtlrCommon(i_mbaChip), iv_tdState(NO_OP)
    {}

  public: // Overloaded functions

    int32_t handleCmdCompleteEvent( STEP_CODE_DATA_STRUCT & io_sc );

  private: // Overloaded functions

    int32_t initialize();

    int32_t analyzeCmdComplete( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeVcmPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeVcmPhase2( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeDsdPhase1( STEP_CODE_DATA_STRUCT & io_sc );
    int32_t analyzeDsdPhase2( STEP_CODE_DATA_STRUCT & io_sc );

    int32_t startVcmPhase1();
    int32_t startVcmPhase2();
    int32_t startDsdPhase1();
    int32_t startDsdPhase2();

    bool isInTdMode();

  private: // functions

    /**
     * @brief  Checks if ECC errors have occurred during a maintenance command.
     * @param  o_eccErrorMask Bitwise mask indicating which ECC errors have
     *         occurred.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t checkEccErrors( uint8_t & o_eccErrorMask );

    /**
     * @brief  Handle UEs during TD analysis.
     * @param  io_sc Service data collector.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleUE( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handle MCE event during VCM Phase 2
     * @param  io_sc Service data collector.
     * @note   This will update bad bits information in VPD, set callouts, and
     *         start the DRAM sparing procedure, if possible.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleMCE_VCM2( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handle MCE event during DSD Phase 2
     * @param  io_sc Service data collector.
     * @note   This will update bad bits information in VPD and set callouts.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t handleMCE_DSD2( STEP_CODE_DATA_STRUCT & io_sc );

    /**
     * @brief  Handle cleanup when TD sequence is complete and TD state machine
     *         will reset.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t exitTdSequence();

    /**
     * @brief  Preforms cleanup tasks that need to be done before starting the
     *         next maintenance command (i.e. clear scrub counter).
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t prepareNextCmd();

    /**
     * @brief  Sends a message to MDIA that a maintenance command has completed.
     * @note   If for some reason PRD needed to do some targeted diagnotics and
     *         on a rank that was not the last rank behind the MBA, this
     *         function will need to send a message to MDIA indicating that the
     *         command stopped and MDIA will need to restart the pattern testing
     *         from the next address to the end of memory.
     * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
     */
    int32_t signalMdiaCmdComplete();

  private: // instance variables

    /** The targeted diagnostics state variable (see enum TdState). */
    TdState iv_tdState;

    /** Array of functions pointers for TD controller states. This is used to
     *  determine the next course of action after a maintenance command complete
     *  attention.
     */
    static CMD_COMPLETE_FUNCS cv_cmdCompleteFuncs[MAX_TD_STATE];

}; // CenMbaTdCtlr

} // end namespace PRDF

#endif // __prdfCenMbaTdCtlr_H

