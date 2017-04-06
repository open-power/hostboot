/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_maint_cmds.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

///
/// @file p9c_mss_maint_cmds.H
/// @brief Utility functions for running maint cmds,accessing markstore, and accessing steer muxes.
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///


#ifndef _MSS_MAINT_CMDS_H
#define _MSS_MAINT_CMDS_H

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <dimmConsts.H>


//------------------------------------------------------------------------------
// Constants and enums
//------------------------------------------------------------------------------

///
/// @brief Structure to get count of repairs applied
///
struct repair_count
{
    uint8_t symbolmark_count[MAX_RANKS_PER_PORT];
    uint8_t chipmark_count[MAX_RANKS_PER_PORT];
    uint8_t steer_count[MAX_RANKS_PER_PORT];
};



///
/// @brief For index into this table, use 1st symbol index of x8 chip mark / 4.
///
static const uint8_t mss_x8_chip_mark_to_centaurDQ[18][2] =
{
// centaurDQ  port  1st symbol index of chip mark
    {64,          1},   // 0
    {64,          0},   // 4
    {56,          1},   // 8
    {48,          1},   // 12
    {40,          1},   // 16
    {32,          1},   // 20
    {24,          1},   // 24
    {16,          1},   // 28
    {8,           1},   // 32
    {0,           1},   // 36
    {56,          0},   // 40
    {48,          0},   // 44
    {40,          0},   // 48
    {32,          0},   // 52
    {24,          0},   // 56
    {16,          0},   // 60
    {8,           0},   // 64
    {0,           0}    // 68
};

///
/// @brief For index into this table, use 1st symbol index of x4 chip mark / 2.
///
static const uint8_t mss_x4_chip_mark_to_centaurDQ[36][2] =
{
// centaurDQ  port  1st symbol index of x4 chip mark
    {68,          1},   // 0 - NOTE: not actually valid in x4 mode....
    {64,          1},   // 2
    {68,          0},   // 4
    {64,          0},   // 6
    {60,          1},   // 8
    {56,          1},   // 10
    {52,          1},   // 12
    {48,          1},   // 14
    {44,          1},   // 16
    {40,          1},   // 18
    {36,          1},   // 20
    {32,          1},   // 22
    {28,          1},   // 24
    {24,          1},   // 26
    {20,          1},   // 28
    {16,          1},   // 30
    {12,          1},   // 32
    {8,           1},   // 34
    {4,           1},   // 36
    {0,           1},   // 38
    {60,          0},   // 40
    {56,          0},   // 42
    {52,          0},   // 44
    {48,          0},   // 46
    {44,          0},   // 48
    {40,          0},   // 50
    {36,          0},   // 52
    {32,          0},   // 54
    {28,          0},   // 56
    {24,          0},   // 58
    {20,          0},   // 60
    {16,          0},   // 62
    {12,          0},   // 64
    {8,           0},   // 66
    {4,           0},   // 68
    {0,           0}    // 70
};



///
/// @brief Used to get addess range of all ranks from get_address_range()
///
const uint8_t MSS_ALL_RANKS = 0xff;


///
/// @brief Used to indicate invalid symbol
///
const uint8_t MSS_INVALID_SYMBOL = 0xff;


///
/// @brief SteerMux information
///
namespace mss_SteerMux
{

///
/// @brief Used to specify read or write steer mux
///
enum mux_type
{
    READ_MUX = 0,
    WRITE_MUX = 1,
};

///
/// @brief Used to specify steer type
///
enum steer_type
{
    DRAM_SPARE_PORT0 = 0,    // Spare DRAM on port0
    DRAM_SPARE_PORT1 = 1,    // Spare DRAM on port1
    ECC_SPARE = 2,           // ECC spare (used in x4 mode only)
};
};



//------------------------------------------------------------------------------
// Parent class for all maintenance command types
//------------------------------------------------------------------------------

///
/// @brief Contains functions common to multiple maint cmd types.
///
class mss_MaintCmd
{

    public: // enums

        ///
        /// @brief Index into array containing data patterns to load into memory
        ///
        enum PatternIndex
        {
            PATTERN_0       = 0,  //0x00
            PATTERN_1       = 1,  //0xFF
            PATTERN_2       = 2,  //0xF0
            PATTERN_3       = 3,  //0x0F
            PATTERN_4       = 4,  //0xAA
            PATTERN_5       = 5,  //0x55
            PATTERN_6       = 6,  //0xCC
            PATTERN_7       = 7,  //0x33
            PATTERN_RANDOM  = 8,  // random seed
        };

        ///
        /// @brief Inject type used for atomic error inject maint cmd
        ///
        enum InjectType
        {
            ATOMIC_ALT_CE_INJ =         0,
            ATOMIC_ALT_CHIPKILL_INJ =   1,
            ATOMIC_ALT_UE_INJ =         2,
            ATOMIC_ALT_SUE_INJ =        3,
        };

        ///
        /// @brief Stop conditions for maint cmds.
        ///
        enum StopCondition
        {
            NO_STOP_CONDITIONS =                 0x0000, ///< Turn off all stop conditions
            STOP_IMMEDIATE =                     0x8000, ///< Stop immediately if stop on error condition hit
            STOP_END_OF_RANK =                   0x4000, ///< Stop at end of rank if stop on error condition hit
            STOP_ON_HARD_NCE_ETE =               0x2000, ///< Stop on hard new CE error threshlold equal
            STOP_ON_INT_NCE_ETE =                0x1000, ///< Stop on intermittent new CE error threshlold equal
            STOP_ON_SOFT_NCE_ETE =               0x0800, ///< Stop on soft new CE error threshlold equal
            STOP_ON_SCE =                        0x0400, ///< Stop on symbol corrected error (error on symbol already marked)
            STOP_ON_MCE =                        0x0200, ///< Stop on mark corrected error (error on chip already marked)
            STOP_ON_RETRY_CE_ETE =               0x0100, ///< Stop on retry CE error threshold equal (UE that went away on retry)
            STOP_ON_MPE =                        0x0080, ///< Stop on mark placed error (hw placed a chip mark)
            STOP_ON_UE =                         0x0040, ///< Stop on UE
            STOP_ON_SUE =                        0x0020, ///< Stop on SUE
            STOP_ON_END_ADDRESS =                0x0010, ///< Stop when MBMACAQ = MBMEAQ
            ENABLE_CMD_COMPLETE_ATTENTION =      0x0008, ///< Enable command complete attention
        };

        ///
        /// @brief speed options for time base commands.
        ///
        enum TimeBaseSpeed
        {

            BG_SCRUB, ///< Background scrubbing (field).
            FAST_MIN_BW_IMPACT, ///< Runtime DRAM repairs procedures (field) and the initial fast scrub of memory (field).
            FAST_MED_BW_IMPACT, ///< Background scrubbing (mnfg) and the initial fast scrub of memory (mnfg)
            FAST_MAX_BW_IMPACT, ///< IPL time DRAM repairs procedures (field / mnfg) and runtime DRAM repairs procedures (mnfg).
        };


    protected:

        ///
        /// @brief Maintenance command types
        ///
        enum CmdType
        {
            TIMEBASE_READ =                     0,
            TIMEBASE_SCRUB =                    1,
            TIMEBASE_STEER_CLEANUP =            2,
            TIMEBASE_INIT =                     3,
            TIMEBASE_RANDOM_INIT =              4,

            SUPERFAST_READ =                    8,
            SUPERFAST_INIT =                    9,
            SUPERFAST_RANDOM_INIT =             10,

            MEMORY_DISPLAY =                    16,
            MEMORY_ALTER =                      17,
            MEMORY_ALTER_WITH_ECC_OVERRIDE =    18,
            ATOMIC_ALTER_ERROR_INJECT =         19,
            INCREMENT_MBMACA_ADDRESS =          20,
        };



    public:

        ///
        /// @brief Constructor
        ///
        /// @param[in] i_target          MBA target
        /// @param[in] i_start_addr       Address cmd will start at
        /// @param[in] i_end_addr,        Address cmd will stop at
        /// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
        /// @param[in] i_poll            Set to true if you wait for command to complete
        /// @param[in] i_cmd_type         Command type
        ///
        mss_MaintCmd( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                      const fapi2::buffer<uint64_t>& i_start_addr,
                      const fapi2::buffer<uint64_t>& i_end_addr,
                      const uint32_t i_stop_condition,
                      const bool i_poll,
                      const CmdType i_cmd_type );


        ///
        /// @brief Destructor
        ///
        virtual ~mss_MaintCmd() {}


        //----------------------------------------------------------------------
        // These are pure virtual functions that must be defined by every child
        // class.
        //----------------------------------------------------------------------


        ///
        /// @brief  Gets the cmd type of a given object
        /// @return CmdType
        ///
        virtual CmdType getCmdType() const = 0;

        ///
        /// @brief  Saves any settings that need to be restored when command is done.
        ///         Loads the setup parameters into the hardware. Starts the command,
        ///         then either polls for complete or exits with command running.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode setupAndExecuteCmd() = 0;



        //----------------------------------------------------------------------
        // These are virtual functions that will have a default definition in this
        // class but can be overriden by a child class.
        //----------------------------------------------------------------------

        ///
        /// @brief  Stops running maint cmd, and saves the address it stopped at.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode stopCmd();

        ///
        /// @brief  Called once a command is done if we need to restore settings that
        ///         had to be modified to run a specific command type, or clear error
        ///         data in the hw that is no longer relevant.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        /// @note   NOT YET IMPLEMENTED
        ///
        virtual fapi2::ReturnCode cleanupCmd();

    protected:
        //----------------------------------------------------------------------
        // These are virtual functions that will have a default definition in this
        // class but can be overriden by a child class.
        //----------------------------------------------------------------------

        ///
        /// @brief  Checks for valid hw state and setup required before a cmd is run.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode preConditionCheck();

        ///
        /// @brief  Loads command type into hw.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode loadCmdType();

        ///
        /// @brief  Loads start address into hw.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode loadStartAddress();

        ///
        /// @brief  Loads end address into hw.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode loadEndAddress();

        ///
        /// @brief  Loads stop conditions into hw.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode loadStopCondMask();

        ///
        /// @brief  Starts command.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode startMaintCmd();

        ///
        /// @brief  Polls for command complete.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode pollForMaintCmdComplete();

        ///
        /// @brief  FOR DEBUG ONLY: Reads hw regs for FFDC after command is done.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode collectFFDC();

        ///
        /// @brief  Loads pattern into hw.
        /// @param[in]  i_initPattern    Index into array containing patterns to load.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        /// @note   For now, no array of pattens, just hardcoded pattern of all 0's.
        ///
        virtual fapi2::ReturnCode loadPattern(const PatternIndex i_initPattern);

        ///
        /// @brief  Loads timebase speed into hw.
        /// @param[in]  i_speed  See enum TimeBaseSpeed
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        ///
        virtual fapi2::ReturnCode loadSpeed(const TimeBaseSpeed i_speed);

        ///
        /// @brief  Checks for hw to be right state after cmd is started.
        /// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
        /// @note   For now, no array of pattens, just hardcoded pattern of all 0's.
        ///
        virtual fapi2::ReturnCode postConditionCheck();

    protected:

        const fapi2::Target<fapi2::TARGET_TYPE_MBA> iv_target;       // MBA
        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> iv_targetCentaur;      // Centaur associated with this MBA
        fapi2::buffer<uint64_t> iv_start_addr;    // Start address
        fapi2::buffer<uint64_t> iv_end_addr;      // End address
        uint32_t iv_stop_condition;          // Mask of stop contitions
        bool iv_poll;                       // Set true to wait for cmd complete
        const CmdType iv_cmd_type;           // Command type
        uint8_t iv_mbaPosition;             // 0 = mba01, 1 = mba23




};

//------------------------------------------------------------------------------
// Child classes
//------------------------------------------------------------------------------


///
/// @brief Init an address range to a pattern
///
class mss_SuperFastInit : public mss_MaintCmd
{
    public:

        ///
        /// @brief Superfastinit Constructor
        ///
        /// @param[in] i_target          MBA target
        /// @param[in] i_start_addr       Address cmd will start at
        /// @param[in] i_end_addr,        Address cmd will stop at
        /// @param[in] i_initPattern     Pattern to initialize memory
        /// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
        /// @param[in] i_poll            Set to true if you wait for command to complete
        ///
        mss_SuperFastInit( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,             // MBA target
                           const fapi2::buffer<uint64_t>& i_start_addr,    // Address cmd will start at
                           const fapi2::buffer<uint64_t>& i_end_addr,      // Address cmd will stop at
                           const PatternIndex i_initPattern,               // Index into table containing patterns to load into memory
                           const uint32_t i_stop_condition,                 // Mask of error conditions cmd should stop on
                           const  bool i_poll );                            // Set to true if you wait for command to complete

    public:
        ///
        /// @brief Return superfastinit cmd type
        ///
        fapi2::ReturnCode setupAndExecuteCmd();
        CmdType getCmdType() const
        {
            return cv_cmd_type;
        }

        // This class's implementation of parent class functions that can be
        // overridden.
        ///
        /// @brief Set superfastinit start addr
        /// @param[in] i_start_addr Start Address
        ///
        void setStartAddr(const fapi2::buffer<uint64_t> i_start_addr)
        {
            iv_start_addr = i_start_addr;
        }

        ///
        /// @brief Set superfastinit end addr
        /// @param[in] i_end_addr End Address
        ///
        void setEndAddr(const fapi2::buffer<uint64_t> i_end_addr  )
        {
            iv_end_addr   = i_end_addr;
        }

        fapi2::buffer<uint64_t> getStartAddr() const
        {
            return iv_start_addr;
        }
        fapi2::buffer<uint64_t> getEndAddr()   const
        {
            return iv_end_addr;
        }

    private:

        fapi2::ReturnCode setSavedData(const uint32_t i_savedData )
        {
            fapi2::ReturnCode l_rc;
            iv_savedData = i_savedData;
            return l_rc;
        }

        uint32_t getSavedData()
        {
            return iv_savedData;
        }

    private: // Class variable(s)

        static const CmdType cv_cmd_type;

    private: // Instance variable(s)

        // List of things to save may be cmd-specific, so keep it here for now
        uint32_t iv_savedData;
        // Index into table containing patterns to load into memory
        PatternIndex iv_initPattern;

};


//------------------------------------------------------------------------------
// SuperFastRandomInit
//------------------------------------------------------------------------------
///
/// @brief init an address range to random pattern
///
class mss_SuperFastRandomInit : public mss_MaintCmd
{
    public: // Constructor(s)

        ///
        /// @brief SuperFastRandomInit Constructor
        ///
        /// @param[in] i_target          MBA target
        /// @param[in] i_start_addr       Address cmd will start at
        /// @param[in] i_end_addr,        Address cmd will stop at
        /// @param[in] i_initPattern     Pattern to initialize
        /// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
        /// @param[in] i_poll            Set to true if you wait for command to complete
        ///
        mss_SuperFastRandomInit( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,              // MBA target
                                 const fapi2::buffer<uint64_t>& i_start_addr,     // Address cmd will start at
                                 const fapi2::buffer<uint64_t>& i_end_addr,       // Address cmd will stop at
                                 const PatternIndex i_initPattern,                // Index into table containing pattern to use for random seed
                                 const uint32_t i_stop_condition,                  // Mask of error conditions cmd should stop on
                                 const bool i_poll );                             // Set to true if you wait for command to complete

    public:

        fapi2::ReturnCode setupAndExecuteCmd();
        CmdType getCmdType() const
        {
            return cv_cmd_type;
        }

        // This class's implementation of parent class functions that can be
        // overridden.
        fapi2::ReturnCode cleanupCmd();

        void setStartAddr(const fapi2::buffer<uint64_t> i_start_addr)
        {
            iv_start_addr = i_start_addr;
        }

        void setEndAddr(const fapi2::buffer<uint64_t> i_end_addr  )
        {
            iv_end_addr   = i_end_addr;
        }

        fapi2::buffer<uint64_t> getStartAddr() const
        {
            return iv_start_addr;
        }
        fapi2::buffer<uint64_t> getEndAddr()   const
        {
            return iv_end_addr;
        }

    private:

        fapi2::ReturnCode setSavedData( const uint32_t i_savedData )
        {
            fapi2::ReturnCode l_rc;
            iv_savedData = i_savedData;
            return l_rc;
        }

        uint32_t getSavedData()
        {
            return iv_savedData;
        }

    private: // Class variable(s)

        static const CmdType cv_cmd_type;

    private: // Instance variable(s)

        // List of things to save may be cmd-specific, so keep it here for now
        uint32_t iv_savedData;
        // Index into table containing patterns to load into memory
        PatternIndex iv_initPattern;
        // Setting that had to be restored when done
        fapi2::buffer<uint64_t> iv_saved_MBA_WRD_MODE;

};



//------------------------------------------------------------------------------
// mss_SuperFastRead
//------------------------------------------------------------------------------
class mss_SuperFastRead : public mss_MaintCmd
{
    public: // Constructor(s)
        ///
        /// @brief SuperFastRead Constructor
        ///
        /// @param[in] i_target          MBA target
        /// @param[in] i_start_addr       Address cmd will start at
        /// @param[in] i_end_addr,        Address cmd will stop at
        /// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
        /// @param[in] i_poll            Set to true if you wait for command to complete
        ///
        mss_SuperFastRead( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,             // MBA target
                           const fapi2::buffer<uint64_t>& i_start_addr,    // Address cmd will start at
                           const fapi2::buffer<uint64_t>& i_end_addr,      // Address cmd will stop at
                           const uint32_t i_stop_condition,                 // Mask of error conditions cmd should stop on
                           const bool i_poll );                            // Set to true if you wait for command to complete

    public:

        fapi2::ReturnCode setupAndExecuteCmd();
        CmdType getCmdType() const
        {
            return cv_cmd_type;
        }

        // This class's implementation of parent class functions that can be
        // overridden.
        fapi2::ReturnCode cleanupCmd();

        void setStartAddr(const fapi2::buffer<uint64_t> i_start_addr)
        {
            iv_start_addr = i_start_addr;
        }

        void setEndAddr(const  fapi2::buffer<uint64_t> i_end_addr  )
        {
            iv_end_addr   = i_end_addr;
        }

        fapi2::buffer<uint64_t> getStartAddr() const
        {
            return iv_start_addr;
        }
        fapi2::buffer<uint64_t> getEndAddr()   const
        {
            return iv_end_addr;
        }

    private:

        fapi2::ReturnCode setSavedData(const uint32_t i_savedData )
        {
            fapi2::ReturnCode l_rc;
            iv_savedData = i_savedData;
            return l_rc;
        }

        uint32_t getSavedData()
        {
            return iv_savedData;
        }

        fapi2::ReturnCode ueTrappingSetup();

    private: // Class variable(s)

        static const CmdType cv_cmd_type;

    private: // Instance variable(s)

        // List of things to save may be cmd-specific, so keep it here for now
        uint32_t iv_savedData;
        // Setting that had to be restored when done
        fapi2::buffer<uint64_t> iv_saved_MBA_RRQ0;

};



//------------------------------------------------------------------------------
// mss_AtomicInject
//------------------------------------------------------------------------------
class mss_AtomicInject : public mss_MaintCmd
{
    public: // Constructor(s)
        ///
        /// @brief AtomicInject Constructor
        /// @param[in] i_target          MBA target
        /// @param[in] i_start_addr       Address cmd will start at
        /// @param[in] i_injectType      Type of inject
        ///
        mss_AtomicInject( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,             // MBA target
                          const fapi2::buffer<uint64_t>& i_start_addr,    // Address to inject on
                          const InjectType i_injectType);                 // Inject type



    public:

        fapi2::ReturnCode setupAndExecuteCmd();
        CmdType getCmdType() const
        {
            return cv_cmd_type;
        }

        void setStartAddr(const fapi2::buffer<uint64_t> i_start_addr)
        {
            iv_start_addr = i_start_addr;
        }

        fapi2::buffer<uint64_t> getStartAddr() const
        {
            return iv_start_addr;
        }

        void setInjectType(const InjectType i_injectType)
        {
            iv_injectType = i_injectType;
        }


    private:

        fapi2::ReturnCode setSavedData(const uint32_t i_savedData )
        {
            fapi2::ReturnCode l_rc;
            iv_savedData = i_savedData;
            return l_rc;
        }

        uint32_t getSavedData()
        {
            return iv_savedData;
        }

    private: // Class variable(s)

        static const CmdType cv_cmd_type;

    private: // Instance variable(s)

        // List of things to save may be cmd-specific, so keep it here for now
        uint32_t iv_savedData;
        // Inject type
        InjectType iv_injectType;
};


//------------------------------------------------------------------------------
// Display
//------------------------------------------------------------------------------
class mss_Display : public mss_MaintCmd
{
    public: // Constructor(s)
        ///
        /// @brief Display Constructor
        /// @param[in] i_target          MBA target
        /// @param[in] i_start_addr       Address cmd will start at
        ///
        mss_Display( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,             // MBA target
                     const fapi2::buffer<uint64_t>& i_start_addr );  // Address to display

    public: // Function declaration(s)

        fapi2::ReturnCode setupAndExecuteCmd();
        CmdType getCmdType() const
        {
            return cv_cmd_type;
        }

        void setStartAddr(const fapi2::buffer<uint64_t>& i_start_addr)
        {
            iv_start_addr = i_start_addr;
        }

        fapi2::buffer<uint64_t> getStartAddr() const
        {
            return iv_start_addr;
        }


    private:

        fapi2::ReturnCode setSavedData(const uint32_t i_savedData )
        {
            fapi2::ReturnCode l_rc;
            iv_savedData = i_savedData;
            return l_rc;
        }

        uint32_t getSavedData()
        {
            return iv_savedData;
        }

    private: // Class variable(s)

        static const CmdType cv_cmd_type;

    private: // Instance variable(s)

        // List of things to save may be cmd-specific, so keep it here for now
        uint32_t iv_savedData;
};



///
/// @brief Edit MBSPA register
///
class mss_IncrementAddress : public mss_MaintCmd
{
    public: // Constructor(s)
        ///
        /// @brief IncrementAddress Constructor
        /// @param[in] i_target          MBA target
        ///
        mss_IncrementAddress( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target );     // MBA target

    public:

        fapi2::ReturnCode setupAndExecuteCmd();
        CmdType getCmdType() const
        {
            return cv_cmd_type;
        }

    private:

        static const CmdType cv_cmd_type;
};

///
/// @brief Set timebase speed
///
class mss_TimeBaseScrub : public mss_MaintCmd
{
    public: // Constructor(s)
        ///
        /// @brief TimeBaseScrub Constructor
        /// @param[in] i_target          MBA target
        /// @param[in] i_start_addr       Address cmd will start at
        /// @param[in] i_end_addr,        Address cmd will stop at
        /// @param[in] i_speed           TimeBase Speed
        /// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
        /// @param[in] i_poll            Set to true if you wait for command to complete
        ///
        mss_TimeBaseScrub( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,            // MBA target
                           const fapi2::buffer<uint64_t>& i_start_addr,   // Address cmd will start at
                           const fapi2::buffer<uint64_t>& i_end_addr,     // Address cmd will stop at
                           TimeBaseSpeed i_speed,                   // See enum TimeBaseSpeed
                           uint32_t i_stop_condition,                // Mask of error conditions cmd should stop on
                           bool i_poll );                           // Set to true if you wait for command to complete

    public:

        fapi2::ReturnCode setupAndExecuteCmd();
        CmdType getCmdType() const
        {
            return cv_cmd_type;
        }

        // This class's implementation of parent class functions that can be
        // overridden.

        void setStartAddr(fapi2::buffer<uint64_t> i_start_addr)
        {
            iv_start_addr = i_start_addr;
        }

        void setEndAddr(  fapi2::buffer<uint64_t> i_end_addr  )
        {
            iv_end_addr   = i_end_addr;
        }

        fapi2::buffer<uint64_t> getStartAddr() const
        {
            return iv_start_addr;
        }
        fapi2::buffer<uint64_t> getEndAddr()   const
        {
            return iv_end_addr;
        }

    private:

        fapi2::ReturnCode setSavedData( uint32_t i_savedData )
        {
            fapi2::ReturnCode l_rc;
            iv_savedData = i_savedData;
            return l_rc;
        }

        uint32_t getSavedData()
        {
            return iv_savedData;
        }

    private: // Class variable(s)

        static const CmdType cv_cmd_type;

    private: // Instance variable(s)

        // list of things to save may be specific to each cmd, so keep it
        // here for now
        uint32_t iv_savedData;

        // See enum TimeBaseSpeed
        TimeBaseSpeed iv_speed;
};

///
/// @brief Execute TimeBaseSteerCleanup
///
class mss_TimeBaseSteerCleanup : public mss_MaintCmd
{
    public: // Constructor(s)
        ///
        /// @brief TimeBaseSteerCleanup Constructor
        /// @param[in] i_target          MBA target
        /// @param[in] i_start_addr       Address cmd will start at
        /// @param[in] i_end_addr,        Address cmd will stop at
        /// @param[in] i_stop_condition   Mask of error conditions cmd should stop on
        /// @param[in] i_speed           TimeBase speed
        /// @param[in] i_poll            Set to true if you wait for command to complete
        ///
        mss_TimeBaseSteerCleanup( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,     // MBA target
                                  const fapi2::buffer<uint64_t>& i_start_addr,   // Address cmd will start at
                                  const fapi2::buffer<uint64_t>& i_end_addr,     // Address cmd will stop at
                                  const TimeBaseSpeed i_speed,                   // See enum TimeBaseSpeed
                                  const uint32_t i_stop_condition,                // Mask of error conditions cmd should stop on
                                  const bool i_poll );                           // Set to true if you wait for command to complete

    public:

        fapi2::ReturnCode setupAndExecuteCmd();
        CmdType getCmdType() const
        {
            return cv_cmd_type;
        }

        // This class's implementation of parent class functions that can be
        // overridden.

        void setStartAddr(fapi2::buffer<uint64_t> i_start_addr)
        {
            iv_start_addr = i_start_addr;
        }

        void setEndAddr(  fapi2::buffer<uint64_t> i_end_addr  )
        {
            iv_end_addr   = i_end_addr;
        }

        fapi2::buffer<uint64_t> getStartAddr() const
        {
            return iv_start_addr;
        }
        fapi2::buffer<uint64_t> getEndAddr()   const
        {
            return iv_end_addr;
        }

    private:

        fapi2::ReturnCode setSavedData( uint32_t i_savedData )
        {
            fapi2::ReturnCode l_rc;
            iv_savedData = i_savedData;
            return l_rc;
        }

        uint32_t getSavedData()
        {
            return iv_savedData;
        }

    private: // Class variable(s)

        static const CmdType cv_cmd_type;

    private: // Instance variable(s)

        // list of things to save may be specific to each cmd, so keep it
        // here for now
        uint32_t iv_savedData;

        // See enum TimeBaseSpeed
        TimeBaseSpeed iv_speed;
};



//------------------------------------------------------------------------------
// Utility funcitons
//------------------------------------------------------------------------------

///
/// @brief  Calculates start and end address for a single rank, or all ranks behind the MBA.
///
/// @param[in]  i_target       MBA target
/// @param[in]  i_rank         Either single rank on the MBA to get start/end address
///                        for (0x00-0x07)
///                        Or MSS_ALL_RANKS = 0xff to get start/end address for
///                        all ranks behind the MBA.
/// @param[out] o_start_addr    Address to start cmd at.
/// @param[out] o_end_addr      Address to stop cmd at.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_get_address_range( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint8_t i_rank,
        fapi2::buffer<uint64_t>& o_start_addr,
        fapi2::buffer<uint64_t>& o_end_addr );


///
/// @brief  Calculates start and end address for a single slave rank
///
/// @param[in]  i_target       MBA target
/// @param[in]  i_master        master rank corresponding to the desired slave rank on the MBA to get start/end address
///                        for (0x00-0x07)
/// @param[in]  i_slave         Slave rank to get the address range for
/// @param[out] o_start_addr    Address to start cmd at.
/// @param[out] o_end_addr      Address to stop cmd at.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_get_slave_address_range( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        const uint8_t i_master,
        const uint8_t i_slave,
        fapi2::buffer<uint64_t>& o_start_addr,
        fapi2::buffer<uint64_t>& o_end_addr );


///
/// @brief  Mark store is implemented as one register per rank, so read register for the given rank.
///
///         If MPE FIR for the given rank (scrub or fetch) is on after the read,
///         we will read one more time to make sure we get latest.
///
/// @param[in]  i_target        MBA target
/// @param[in]  i_rank          Rank to get markstore for.
/// @param[out] o_symbolMark    Symbol mark, converted from galois field to symbol
///                         index,(if no mark return 0xff)
/// @param[out] o_chipMark      Chip mark, converted from galois field to first
///                         symbol index of the chip, (if no mark return 0xff)
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_get_mark_store( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const uint8_t i_rank,
                                      uint8_t& o_symbolMark,
                                      uint8_t& o_chipMark );


///
/// @brief  Mark store is implemented as one register per rank, so write register the rank.
///
///         NOTE: Will be writing to both chip and symbol
///         field at same time, so should use a read/modify/write approach to
///         avoid unintentionally over-writing something.
///
/// @param[in]  i_target       MBA target
/// @param[in]  i_rank         Rank to write markstore for.
/// @param[in]  i_symbolMark   Symbol index, which will be converted to galois field
///                        (if input is 0xff, we write 0x00 for no symbol mark).
/// @param[in]  i_chipMark     First symbol index of the chip, which will be
///                        converted to galois field (if input is 0xff, we write
///                        0x00 for no chip mark).
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_put_mark_store( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                      const uint8_t i_rank,
                                      const uint8_t i_symbolMark,
                                      const uint8_t i_chipMark );

///
/// @brief  Gets either the read or write steer mux control register for the given rank
///
///         Converts from steer code to x8/x4 dram index to
///         first symbol index for all DRAMs steered on that rank.
///
/// @param[in]  i_target                 MBA target
/// @param[in]  i_rank                   Rank we want to read steer mux for.
/// @param[in]  i_mux_type                Select either the read mux or the write mux
///                                  to get.
/// @param[out] o_dramSparePort0Symbol   First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dramSparePort1Symbol   First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @param[out] o_eccSpareSymbol         First symbol index of the DRAM fixed by the
///                                  ECC spare, which can be used on either port0
///                                  or port1 (if no steer, return 0xff)
/// @note   The ECC spare is available only with x4 mode ECC.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_get_steer_mux( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_rank,
                                     const mss_SteerMux::mux_type i_mux_type,
                                     uint8_t& o_dramSparePort0Symbol,
                                     uint8_t& o_dramSparePort1Symbol,
                                     uint8_t& o_eccSpareSymbol );

///
/// @brief  Updates the read or write steer mux control register with the steer type for the rank
///
///
/// @param[in]  i_target                MBA target
/// @param[in]  i_rank                  Rank we want to write steer mux for.
/// @param[in]  i_mux_type               Select either the read mux or the write mux
///                                 to update.
/// @param[in]  i_steer_type             0 = DRAM_SPARE_PORT0, Spare DRAM on port0
///                                 1 = DRAM_SPARE_PORT1, Spare DRAM on port1
///                                 2 = ECC_SPARE, ECC spare (used in x4 mode only)
/// @param[in]  i_symbol                First symbol index of the DRAM to steer
///                                 around.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_put_steer_mux( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_rank,
                                     const mss_SteerMux::mux_type i_mux_type,
                                     const uint8_t i_steer_type,
                                     const uint8_t i_symbol );

///
/// @brief  Reads the steer muxes for the given rank
///
/// @param[in]  i_target                 MBA target
/// @param[in]  i_rank                   Rank we want to read steer mux for.
/// @param[out] o_dramSparePort0Symbol   First symbol index of the DRAM fixed by the
///                                  spare on port0 (if no steer, return 0xff)
/// @param[out] o_dramSparePort1Symbol   First symbol index of the DRAM fixed by the
///                                  spare on port1 (if no steer, return 0xff)
/// @param[out] o_eccSpareSymbol         First symbol index of the DRAM fixed by the
///                                  ECC spare, which can be used on either port0
///                                  or port1 (if no steer, return 0xff)
/// @note   The ECC spare is available only with x4 mode ECC.
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_check_steering(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_rank,
                                     uint8_t& o_dramSparePort0Symbol,
                                     uint8_t& o_dramSparePort1Symbol,
                                     uint8_t& o_eccSpareSymbol );

///
/// @brief  Set write mux, wait for periodic cal, set read mux, for the given rank.
///
/// @param[in]  i_target                MBA target
/// @param[in]  i_rank                  Rank we want to write steer mux for.
/// @param[in]  i_symbol                First symbol index of the DRAM to steer
///                                 around.
/// @param[in] i_x4EccSpare             If true, writes the x4 ECC Spare. Otherwise,
///                                 writes the DRAM spare (default).
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_do_steering(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                  const uint8_t i_rank,
                                  const uint8_t i_symbol,
                                  const bool i_x4EccSpare = false );


///
/// @brief  This procedure applies the maximum possible DRAM repairs (chip/symbol marks, DRAM steers)
///
///         brief cont. :  to known bad bits recorded in
///         DIMM VPD. This operation is done on both valid logical DIMM pairs
///         behind the given MBA.
///
/// @param[in]  i_target                MBA target
/// @param[out] o_repairs_applied       8-bit mask, where a bit set means the
///                                 specified rank had any repairs applied.
///
///                       rank0 = 0x80           (maps to port0_dimm0, port1_dimm0)
///                       rank1 = 0x40           (maps to port0_dimm0, port1_dimm0)
///                       rank2 = 0x20           (maps to port0_dimm0, port1_dimm0)
///                       rank3 = 0x10           (maps to port0_dimm0, port1_dimm0)
///                       rank4 = 0x08           (maps to port0_dimm1, port1_dimm1)
///                       rank5 = 0x04           (maps to port0_dimm1, port1_dimm1)
///                       rank6 = 0x02           (maps to port0_dimm1, port1_dimm1)
///                       rank7 = 0x01           (maps to port0_dimm1, port1_dimm1)
///
/// @param[out] o_repairs_exceeded      4-bit mask, where a bit set means the
///                                 specified DIMM-select on the specified port
///                                 had more bad bits than could be repaired.
///
///                        port0_dimm0 = 0x8
///                        port0_dimm1 = 0x4
///                        port1_dimm0 = 0x2
///                        port1_dimm1 = 0x1
///
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_restore_DRAM_repairs( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint8_t& o_repairs_applied,
        uint8_t& o_repairs_exceeded);


///
/// @brief  This procedure counts the maximum possible DRAM repairs (chip/symbol marks, DRAM steers)
///
///         brief cont.  to known bad bits recorded in
///         DIMM VPD. This operation is done on both valid logical DIMM pairs
///         behind the given MBA.
///
/// @param[in]  i_target                MBA target
/// @param[out] o_repairs_applied       8-bit mask, where a bit set means the
///                                 specified rank had any repairs applied.
///
///                       rank0 = 0x80           (maps to port0_dimm0, port1_dimm0)
///                       rank1 = 0x40           (maps to port0_dimm0, port1_dimm0)
///                       rank2 = 0x20           (maps to port0_dimm0, port1_dimm0)
///                       rank3 = 0x10           (maps to port0_dimm0, port1_dimm0)
///                       rank4 = 0x08           (maps to port0_dimm1, port1_dimm1)
///                       rank5 = 0x04           (maps to port0_dimm1, port1_dimm1)
///                       rank6 = 0x02           (maps to port0_dimm1, port1_dimm1)
///                       rank7 = 0x01           (maps to port0_dimm1, port1_dimm1)
///
/// @param[out] o_repairs_exceeded      4-bit mask, where a bit set means the
///                                 specified DIMM-select on the specified port
///                                 had more bad bits than could be repaired.
///
///                        port0_dimm0 = 0x8
///                        port0_dimm1 = 0x4
///                        port1_dimm0 = 0x2
///                        port1_dimm1 = 0x1
///
/// @param[in]  i_strandby_flag     Boolean if we are in standby at call time
/// @param[out] o_repair_count      Repair counts
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_restore_DRAM_repairs_asm( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
        uint8_t& o_repairs_applied,
        uint8_t& o_repairs_exceeded,
        const bool i_standby_flag,
        struct repair_count& o_repair_count);





///
/// @brief  This function takes converts from a Centaur DQ on a given port to a corresponding symbol index.
/// @param[in]  i_dq     Centaur DQ from 0-71
/// @param[in]  i_port   port 0 or 1
/// @return          Symbol index
///
uint8_t mss_centaurDQ_to_symbol( const uint8_t i_dq,
                                 const uint8_t i_port );


///
/// @brief  Identifies UE bits from trap data
///
///         This function compares trapped actual UE data to an expected
///         data pattern in order to identify the bits that contributed to
///         a UE encountered during IPL memory diagnostics.
///
/// @param[in]  i_target                MBA target
/// @param[in]  i_rank                  Rank containing the UE.
/// @param[out] o_bad_bits              Map of bad bits (Centaur DQ format) 2 ports x 10 bytes
/// @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
///
fapi2::ReturnCode mss_IPL_UE_isolation( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                        const uint8_t i_rank,
                                        uint8_t (&o_bad_bits)[2][10]);

///
/// @brief Update o_symbolMark and o_chipMark with mark_store values
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centaur input rank
/// @param[out] o_symbolMark Symbol Mark
/// @param[out] o_chipMark Chip Mark
/// @param[out] mark_store Markstore array
///
void mss_get_dummy_mark_store( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                               const uint8_t i_rank,
                               uint8_t& o_symbolMark,
                               uint8_t& o_chipMark,
                               uint8_t mark_store[8][2]);

///
/// @brief  Set mark store with new symbol and chip mark values
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centaur input rank
/// @param[out] i_symbolMark Symbol Mark
/// @param[out] i_chipMarkChip Mark
/// @param[out] mark_store Markstore array
///
void mss_put_dummy_mark_store( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                               const uint8_t i_rank,
                               const uint8_t i_symbolMark,
                               const uint8_t i_chipMark,
                               uint8_t mark_store[8][2]);
///
/// @brief Pull steer mux values from steer array
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centuar input rank
/// @param[in] i_mux_type  Read or Write
/// @param[out] o_dramSparePort0Symbol Port 0 spare val
/// @param[out] o_dramSparePort1Symbol Port 1 spare val
/// @param[out] o_eccSpareSymbol Ecc Spare val
/// @param[out] steer[8][3] Steer mux array
///
void mss_get_dummy_steer_mux( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                              const uint8_t i_rank,
                              const mss_SteerMux::mux_type i_mux_type,
                              uint8_t& o_dramSparePort0Symbol,
                              uint8_t& o_dramSparePort1Symbol,
                              uint8_t& o_eccSpareSymbol,
                              uint8_t steer[8][3]);

///
/// @brief Set steer mux value for a given rank and type
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centuar input rank
/// @param[in] i_mux_type Read or Write
/// @param[in] i_steer_type spare port 0, port 1 or ecc spare
/// @param[in] i_symbol First symbol index of byte to steer
/// @param[out] steer[8][3]  Steer mux array
///
void mss_put_dummy_steer_mux( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                              const uint8_t i_rank,
                              const mss_SteerMux::mux_type i_mux_type,
                              const uint8_t i_steer_type,
                              const uint8_t i_symbol,
                              uint8_t steer[8][3]);

///
/// @brief Populate output vars with corresponding steer mux array values
/// @param[in] i_target Centaur MBA target
/// @param[in] i_rank   Centuar input rank
/// @param[out] o_dramSparePort0Symbol Spare port 0 symbol
/// @param[out] o_dramSparePort1Symbol Spare port 1 symbol
/// @param[out] o_eccSpareSymbol ECC spare symbol
/// @param[out] steer[8][3] Steer mux array
///
void mss_check_dummy_steering(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                              const uint8_t i_rank,
                              uint8_t& o_dramSparePort0Symbol,
                              uint8_t& o_dramSparePort1Symbol,
                              uint8_t& o_eccSpareSymbol,
                              uint8_t steer[8][3]);



#endif/// _MSS_MAINT_CMDS_H */
