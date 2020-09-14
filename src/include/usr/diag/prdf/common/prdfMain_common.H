/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/prdf/common/prdfMain_common.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

// Move here from xspprdsdbug.C
/**
 *  @brief Structure of target handle and its attention type
 */
struct AttnData
{
    TARGETING::TargetHandle_t targetHndl;   // tgt for chips at attention
    ATTENTION_VALUE_TYPE attnType;          // attention reported by chip
    bool isAnalysisNotDone;                 // analysis status for a given attn

    /**
     * @brief overloads operator <
     */
    bool operator < ( const  AttnData & i_attnData )
    {
        bool isLess = false ;
        if( this->targetHndl == i_attnData.targetHndl )
        {
            isLess = ( this->attnType < i_attnData.attnType );
        }
        else
        {
            isLess = ( this->targetHndl < i_attnData.targetHndl );
        }

        return isLess;
    }

    /**
     * @brief overloads operator ==
     */
    bool operator == ( const  AttnData & i_attnData )
    {
        bool isequal = false ;
        if( this->targetHndl == i_attnData.targetHndl )
        {
            isequal = ( this->attnType == i_attnData.attnType );
        }

        return isequal;
    }

    /**
     * @brief overloads operator <
     */
    bool operator < ( const  TARGETING::TargetHandle_t i_trgt )
    {
        return ( this->targetHndl < i_trgt );
    }

    /**
     * @brief   constructor.
     * @param   i_tgt       target of chip reporting attention.
     * @param   i_attnType  attention type reported by chip.
     */
    AttnData( TARGETING::TargetHandle_t i_tgt,
              ATTENTION_VALUE_TYPE i_attnType ):
      targetHndl( i_tgt ),
      attnType( i_attnType ),
      isAnalysisNotDone( true )
    {}

    /**
     * @brief   default constructor
     */
    AttnData() :
      targetHndl( 0 ),
      attnType( INVALID_ATTENTION_TYPE ),
      isAnalysisNotDone( false )
    {}

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

};

/** Indicates if PRD has been initialized. */
extern bool g_initialized;

/**
 * @brief Initialize PRD system model and data
 * @return Error log if error occurs
 */
extern errlHndl_t initialize();

/**
 * @brief Uninitializes the PRD system model and data.
 *
 * IMPORTANT: PRD initialization is expensive. The PRD system model and data is
 * intented to stay in memory indefinitely to avoid re-initialization. Also,
 * some data, like threshold counts or the memory maintenance command state
 * machine, are stored and the PRD system model and will be lost when
 * uninitialized.
 *
 * @return Error log if error occurs.
 */
extern void uninitialize();

/**
 * @brief analyze attention errors
 * @param[in] i_attnType - global attention type
 * @param[in] i_attnList - list of chips at attention
 * @return Error log if error occurs
 *
 * @note If the i_attnType is CHECK_STOP than an error log is returned
 * containing the analysis; otherwise, for other attention types, PRD
 * commits the error log itself and nullptr is returned.
 */
extern errlHndl_t main( ATTENTION_VALUE_TYPE i_attnType,
                        const AttnList & i_attnList );

/**
 *  @brief Remove non-functional chips from PRD config model
 *
 *  @return Error log if error occurs
 */
extern errlHndl_t refresh();

} // End namespace PRDF

#endif // __prdfMain_common_H
