/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/utility_procedures/mss_maint_cmds.H $ */
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
// $Id: mss_maint_cmds.H,v 1.20 2014/02/20 20:52:15 bellows Exp $
//------------------------------------------------------------------------------
// Don't forget to create CVS comments when you check in your changes!
//------------------------------------------------------------------------------
// CHANGE HISTORY:
//------------------------------------------------------------------------------
// Version:|   Date:  | Author: | Comment:
//---------|----------|---------|-----------------------------------------------
//         | 11/02/11 | gollub  | Created
//         | 11/15/11 | gollub  | Fixed some reg addresses
//         | 03/30/12 | gollub  | Made stop condition parm into a mask.
//         |          |         | Added support for both MBAs
//         | 04/25/12 | gollub  | Added doxygen tags
//         | 05/23/12 | gollub  | Updates from review.
//         | 07/13/12 | gollub  | Updates from review.
//   1.7   | 07/16/12 | bellows | added in Id tag
//   1.8   | 07/18/12 | gollub  | Updates for timebase scrub.
//   1.9   | 08/15/12 | gollub  | Added stop condition enums
//         |          |         | STOP_IMMEDIATE
//         |          |         | ENABLE_CMD_COMPLETE_ATTENTION_ON_CLEAN_AND_ERROR
//         |          |         | Added iv_saved_MBA_WRD_MODE to allow
//         |          |         | save/restore of setting for super fast read
//   1.10  | 09/07/12 | gollub  | Updates from review.
//         |          |         | Support for more patterns.
//   1.11  | 09/28/12 | gollub  | Added mss_restore_DRAM_repairs
//   1.12  | 11/02/12 | gollub  | Updates from review.
//   1.13  | 11/08/12 | gollub  | Added timebase steer cleanup
//   1.14  | 11/21/12 | gollub  | Updates from review.
//   1.15  | 12/19/12 | gollub  | Added UE isolation
//   1.16  | 01/31/13 | gollub  | Added mss_check_steering
//         |          |         | Added mss_do_steering
//         |          |         | Added mss_stopCmd
//         |          |         | Changed setupAndExecuteCmd to pure virtual
//   1.17  | 08/23/13 | gollub  | Added x4 ECC mode support: mss_x4_chip_mark_to_centaurDQ
//   1.18  | 10/31/13 | gollub  | Removed support for stop condition enum
//         |          |         | ENABLE_CMD_COMPLETE_ATTENTION_ON_CLEAN_AND_ERROR
//   1.19  | 02/07/14 |adityamd | Added support to mss_restore_DRAM_repairs to be accessed at Standby
//   1.20  | 02/20/14 |bellows  | RAS update from repairs at standby


#ifndef _MSS_MAINT_CMDS_H
#define _MSS_MAINT_CMDS_H

/** @file  mss_maint_cmds.H
  *  @brief General utility functions to for running maint cmds,
  *         accessing markstore, and accessing steer muxes.
  */


//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------

#include <fapi.H>
#include <ecmdDataBufferBase.H>



//------------------------------------------------------------------------------
// Constants and enums
//------------------------------------------------------------------------------

//Structure to get count of repairs applied

struct repair_count
{
  uint8_t symbolmark_count[8];
  uint8_t chipmark_count[8];
  uint8_t steer_count[8];
};



/**
  * @brief For index into this table, use 1st symbol index of x8 chip mark / 4.
  */




static const uint8_t mss_x8_chip_mark_to_centaurDQ[18][2]={
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
  {0,           0}};  // 68

/**
  * @brief For index into this table, use 1st symbol index of x4 chip mark / 2.
  */
  static const uint8_t mss_x4_chip_mark_to_centaurDQ[36][2]={
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
    {0,           0}};  // 70



/**
  * @brief Used to get addess range of all ranks from get_address_range()
  */
    const uint8_t MSS_ALL_RANKS = 0xff;


/**
  * @brief Used to indicate invalid symbol
  */
    const uint8_t MSS_INVALID_SYMBOL = 0xff;



    namespace mss_SteerMux
    {

/**
  * @brief Used to specify read or write steer mux
  */
      enum muxType
      {
        READ_MUX = 0,
        WRITE_MUX = 1,
      };

/**
  * @brief Used to specify steer type
  */
      enum steerType
      {
        DRAM_SPARE_PORT0 = 0,    // Spare DRAM on port0
        DRAM_SPARE_PORT1 = 1,    // Spare DRAM on port1
        ECC_SPARE = 2,           // ECC spare (used in x4 mode only)
      };
    };



//------------------------------------------------------------------------------
// Parent class for all maintenance command types
//------------------------------------------------------------------------------

/**
  * @brief Contains functions common to multiple maint cmd types.
  */

    class mss_MaintCmd
    {

    public: // enums

/**
  * @brief Index into array containing data patterns to load into memory
  */
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

/**
  * @brief Inject type used for atomic error inject maint cmd
  */
      enum InjectType
      {
        ATOMIC_ALT_CE_INJ =         0,
        ATOMIC_ALT_CHIPKILL_INJ =   1,
        ATOMIC_ALT_UE_INJ =         2,
        ATOMIC_ALT_SUE_INJ =        3,
      };

/**
  * @brief Stop conditions for maint cmds.
  */
      enum StopCondition
      {
// Turn off all stop conditions
        NO_STOP_CONDITIONS =                 0x0000,

// Stop immediately if stop on error condition hit
        STOP_IMMEDIATE =                     0x8000,

// Stop at end of rank if stop on error condition hit
        STOP_END_OF_RANK =                   0x4000,

// Stop on hard new CE error threshlold equal
        STOP_ON_HARD_NCE_ETE =               0x2000,

// Stop on intermittent new CE error threshlold equal
        STOP_ON_INT_NCE_ETE =                0x1000,

// Stop on soft new CE error threshlold equal
        STOP_ON_SOFT_NCE_ETE =               0x0800,

// Stop on symbol corrected error (error on symbol already marked)
        STOP_ON_SCE =                        0x0400,

// Stop on mark corrected error (error on chip already marked)
        STOP_ON_MCE =                        0x0200,

// Stop on retry CE error threshold equal (UE that went away on retry)
        STOP_ON_RETRY_CE_ETE =               0x0100,

// Stop on mark placed error (hw placed a chip mark)
        STOP_ON_MPE =                        0x0080,

// Stop on UE
        STOP_ON_UE =                         0x0040,

// Stop on SUE
        STOP_ON_SUE =                        0x0020,

// Stop when MBMACAQ = MBMEAQ
        STOP_ON_END_ADDRESS =                0x0010,

// Enable command complete attention
        ENABLE_CMD_COMPLETE_ATTENTION =      0x0008,

      };

/**
  * @brief speed options for time base commands.
  */
      enum TimeBaseSpeed
      {
        FAST_AS_POSSIBLE =                     0,
        SLOW_12H =                             1,
      };


    protected:

/**
  * @brief Maintenance command types
  */
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

/**
  * @brief Constructor
  *
  * @param i_target          MBA target
  * @param i_startAddr       Address cmd will start at
  * @param i_endAddr,        Address cmd will stop at
  * @param i_stopCondition   Mask of error conditions cmd should stop on
  * @param i_poll            Set to true if you wait for command to complete
  * @param i_cmdType         Command type
  */
      mss_MaintCmd( const fapi::Target & i_target,
                    const ecmdDataBufferBase & i_startAddr,
                    const ecmdDataBufferBase & i_endAddr,
                    uint32_t i_stopCondition,
                    bool i_poll,
                    CmdType i_cmdType );


/**
  * @brief Destructor
  */
      virtual ~mss_MaintCmd() {}


//----------------------------------------------------------------------
// These are pure virtual functions that must be defined by every child
// class.
//----------------------------------------------------------------------


/**
  * @brief  Gets the cmd type of a given object
  * @return CmdType
  */
      virtual CmdType getCmdType() const = 0;

/**
  * @brief  Saves any settings that need to be restored when command is done.
  *         Loads the setup parameters into the hardware. Starts the command,
  *         then either polls for complete or exits with command running.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode setupAndExecuteCmd() = 0;



//----------------------------------------------------------------------
// These are virtual functions that will have a default definition in this
// class but can be overriden by a child class.
//----------------------------------------------------------------------

/**
  * @brief  Stops running maint cmd, and saves the address it stopped at.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode stopCmd();

/**
  * @brief  Called once a command is done if we need to restore settings that
  *         had to be modified to run a specific command type, or clear error
  *         data in the hw that is no longer relevant.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  * @note   NOT YET IMPLEMENTED
  */
      virtual fapi::ReturnCode cleanupCmd();

    protected:
//----------------------------------------------------------------------
// These are virtual functions that will have a default definition in this
// class but can be overriden by a child class.
//----------------------------------------------------------------------

/**
  * @brief  Checks for valid hw state and setup required before a cmd is run.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode preConditionCheck();

/**
  * @brief  Loads command type into hw.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode loadCmdType();

/**
  * @brief  Loads start address into hw.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode loadStartAddress();

/**
  * @brief  Loads end address into hw.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode loadEndAddress();

/**
  * @brief  Loads stop conditions into hw.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode loadStopCondMask();

/**
  * @brief  Starts command.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode startMaintCmd();

/**
  * @brief  Polls for command complete.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode pollForMaintCmdComplete();

/**
  * @brief  FOR DEBUG ONLY: Reads hw regs for FFDC after command is done.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode collectFFDC();

/**
  * @brief  Loads pattern into hw.
  * @param  i_initPattern    Index into array containing patterns to load.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  * @note   For now, no array of pattens, just hardcoded pattern of all 0's.
  */
      virtual fapi::ReturnCode loadPattern(PatternIndex i_initPattern);

/**
  * @brief  Loads timebase speed into hw.
  * @param  i_speed  FAST_AS_POSSIBLE or SLOW_12H
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
      virtual fapi::ReturnCode loadSpeed(TimeBaseSpeed i_speed);

/**
  * @brief  Checks for hw to be right state after cmd is started.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  * @note   For now, no array of pattens, just hardcoded pattern of all 0's.
  */
      virtual fapi::ReturnCode postConditionCheck();

    protected:

      const fapi::Target iv_target;       // MBA
      fapi::Target iv_targetCentaur;      // Centaur associated with this MBA
      ecmdDataBufferBase iv_startAddr;    // Start address
      ecmdDataBufferBase iv_endAddr;      // End address
      uint32_t iv_stopCondition;          // Mask of stop contitions
      bool iv_poll;                       // Set true to wait for cmd complete
      const CmdType iv_cmdType;           // Command type
      uint8_t iv_mbaPosition;             // 0 = mba01, 1 = mba23




    };

//------------------------------------------------------------------------------
// Child classes
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// mss_SuperFastInit
//------------------------------------------------------------------------------
    class mss_SuperFastInit : public mss_MaintCmd
    {
    public:

// Constructor
      mss_SuperFastInit( const fapi::Target & i_target,            // MBA target
                         const ecmdDataBufferBase & i_startAddr,   // Address cmd will start at
                         const ecmdDataBufferBase & i_endAddr,     // Address cmd will stop at
                         PatternIndex i_initPattern,               // Index into table containing patterns to load into memory
                         uint32_t i_stopCondition,                 // Mask of error conditions cmd should stop on
                         bool i_poll );                            // Set to true if you wait for command to complete

    public:

      fapi::ReturnCode setupAndExecuteCmd();
      CmdType getCmdType() const { return cv_cmdType; }

// This class's implementation of parent class functions that can be
// overridden.

      void setStartAddr(ecmdDataBufferBase i_startAddr)
      { iv_startAddr = i_startAddr; }

      void setEndAddr(  ecmdDataBufferBase i_endAddr  )
      { iv_endAddr   = i_endAddr;   }

      ecmdDataBufferBase getStartAddr() const { return iv_startAddr; }
      ecmdDataBufferBase getEndAddr()   const { return iv_endAddr; }

    private:

      fapi::ReturnCode setSavedData( uint32_t i_savedData )
      {fapi::ReturnCode l_rc; iv_savedData = i_savedData; return l_rc;}

      uint32_t getSavedData() { return iv_savedData; }

    private: // Class variable(s)

      static const CmdType cv_cmdType;

    private: // Instance variable(s)

// List of things to save may be cmd-specific, so keep it here for now
      uint32_t iv_savedData;
// Index into table containing patterns to load into memory
      PatternIndex iv_initPattern;

    };


//------------------------------------------------------------------------------
// SuperFastRandomInit
//------------------------------------------------------------------------------
    class mss_SuperFastRandomInit : public mss_MaintCmd
    {
    public: // Constructor(s)

// Constructor
      mss_SuperFastRandomInit( const fapi::Target & i_target,             // MBA target
                               const ecmdDataBufferBase & i_startAddr,    // Address cmd will start at
                               const ecmdDataBufferBase & i_endAddr,      // Address cmd will stop at
                               PatternIndex i_initPattern,                // Index into table containing pattern to use for random seed
                               uint32_t i_stopCondition,                  // Mask of error conditions cmd should stop on
                               bool i_poll );                             // Set to true if you wait for command to complete

    public:

      fapi::ReturnCode setupAndExecuteCmd();
      CmdType getCmdType() const { return cv_cmdType; }

// This class's implementation of parent class functions that can be
// overridden.
      fapi::ReturnCode cleanupCmd();

      void setStartAddr(ecmdDataBufferBase i_startAddr)
      { iv_startAddr = i_startAddr; }

      void setEndAddr(  ecmdDataBufferBase i_endAddr  )
      { iv_endAddr   = i_endAddr;   }

      ecmdDataBufferBase getStartAddr() const { return iv_startAddr; }
      ecmdDataBufferBase getEndAddr()   const { return iv_endAddr; }

    private:

      fapi::ReturnCode setSavedData( uint32_t i_savedData )
      {fapi::ReturnCode l_rc; iv_savedData = i_savedData; return l_rc;}

      uint32_t getSavedData() { return iv_savedData; }

    private: // Class variable(s)

      static const CmdType cv_cmdType;

    private: // Instance variable(s)

// List of things to save may be cmd-specific, so keep it here for now
      uint32_t iv_savedData;
// Index into table containing patterns to load into memory
      PatternIndex iv_initPattern;
// Setting that had to be restored when done
      ecmdDataBufferBase iv_saved_MBA_WRD_MODE;

    };



//------------------------------------------------------------------------------
// mss_SuperFastRead
//------------------------------------------------------------------------------
    class mss_SuperFastRead : public mss_MaintCmd
    {
    public: // Constructor(s)

      mss_SuperFastRead( const fapi::Target & i_target,            // MBA target
                         const ecmdDataBufferBase & i_startAddr,   // Address cmd will start at
                         const ecmdDataBufferBase & i_endAddr,     // Address cmd will stop at
                         uint32_t i_stopCondition,                 // Mask of error conditions cmd should stop on
                         bool i_poll );                            // Set to true if you wait for command to complete

    public:

      fapi::ReturnCode setupAndExecuteCmd();
      CmdType getCmdType() const { return cv_cmdType; }

// This class's implementation of parent class functions that can be
// overridden.
      fapi::ReturnCode cleanupCmd();

      void setStartAddr(ecmdDataBufferBase i_startAddr)
      { iv_startAddr = i_startAddr; }

      void setEndAddr(  ecmdDataBufferBase i_endAddr  )
      { iv_endAddr   = i_endAddr;   }

      ecmdDataBufferBase getStartAddr() const { return iv_startAddr; }
      ecmdDataBufferBase getEndAddr()   const { return iv_endAddr; }

    private:

      fapi::ReturnCode setSavedData( uint32_t i_savedData )
      {fapi::ReturnCode l_rc; iv_savedData = i_savedData; return l_rc; }

      uint32_t getSavedData() { return iv_savedData; }

      fapi::ReturnCode ueTrappingSetup();

    private: // Class variable(s)

      static const CmdType cv_cmdType;

    private: // Instance variable(s)

// List of things to save may be cmd-specific, so keep it here for now
      uint32_t iv_savedData;
// Setting that had to be restored when done
      ecmdDataBufferBase iv_saved_MBA_RRQ0;

    };



//------------------------------------------------------------------------------
// mss_AtomicInject
//------------------------------------------------------------------------------
    class mss_AtomicInject : public mss_MaintCmd
    {
    public: // Constructor(s)

      mss_AtomicInject( const fapi::Target & i_target,            // MBA target
                        const ecmdDataBufferBase & i_startAddr,   // Address to inject on
                        InjectType i_injectType);                 // Inject type



    public:

      fapi::ReturnCode setupAndExecuteCmd();
      CmdType getCmdType() const { return cv_cmdType; }

      void setStartAddr(ecmdDataBufferBase i_startAddr)
      { iv_startAddr = i_startAddr; }

      ecmdDataBufferBase getStartAddr() const { return iv_startAddr; }

      void setInjectType(InjectType i_injectType)
      { iv_injectType = i_injectType;   }


    private:

      fapi::ReturnCode setSavedData( uint32_t i_savedData )
      {fapi::ReturnCode l_rc; iv_savedData = i_savedData; return l_rc; }

      uint32_t getSavedData() { return iv_savedData; }

    private: // Class variable(s)

      static const CmdType cv_cmdType;

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

      mss_Display( const fapi::Target & i_target,            // MBA target
                   const ecmdDataBufferBase & i_startAddr ); // Address to display

    public: // Function declaration(s)

      fapi::ReturnCode setupAndExecuteCmd();
      CmdType getCmdType() const { return cv_cmdType; }

      void setStartAddr(const ecmdDataBufferBase & i_startAddr)
      { iv_startAddr = i_startAddr; }

      ecmdDataBufferBase getStartAddr() const { return iv_startAddr; }


    private:

      fapi::ReturnCode setSavedData( uint32_t i_savedData )
      {fapi::ReturnCode l_rc; iv_savedData = i_savedData; return l_rc; }

      uint32_t getSavedData() { return iv_savedData; }

    private: // Class variable(s)

      static const CmdType cv_cmdType;

    private: // Instance variable(s)

// List of things to save may be cmd-specific, so keep it here for now
      uint32_t iv_savedData;
    };



//------------------------------------------------------------------------------
// mss_IncrementAddress
//------------------------------------------------------------------------------
    class mss_IncrementAddress : public mss_MaintCmd
    {
    public: // Constructor(s)

      mss_IncrementAddress( const fapi::Target & i_target );    // MBA target

    public:

      fapi::ReturnCode setupAndExecuteCmd();
      CmdType getCmdType() const { return cv_cmdType; }

    private:

      static const CmdType cv_cmdType;
    };


//------------------------------------------------------------------------------
// mss_TimeBaseScrub
//------------------------------------------------------------------------------
    class mss_TimeBaseScrub : public mss_MaintCmd
    {
    public: // Constructor(s)

      mss_TimeBaseScrub( const fapi::Target & i_target,           // MBA target
                         const ecmdDataBufferBase & i_startAddr,  // Address cmd will start at
                         const ecmdDataBufferBase & i_endAddr,    // Address cmd will stop at
                         TimeBaseSpeed i_speed,                   // Fast as possible, or slow (all memory on the MBA in 12h)
                         uint32_t i_stopCondition,                // Mask of error conditions cmd should stop on
                         bool i_poll );                           // Set to true if you wait for command to complete

    public:

      fapi::ReturnCode setupAndExecuteCmd();
      CmdType getCmdType() const { return cv_cmdType; }

// This class's implementation of parent class functions that can be
// overridden.

      void setStartAddr(ecmdDataBufferBase i_startAddr)
      { iv_startAddr = i_startAddr; }

      void setEndAddr(  ecmdDataBufferBase i_endAddr  )
      { iv_endAddr   = i_endAddr;   }

      ecmdDataBufferBase getStartAddr() const { return iv_startAddr; }
      ecmdDataBufferBase getEndAddr()   const { return iv_endAddr; }

    private:

      fapi::ReturnCode setSavedData( uint32_t i_savedData )
      {fapi::ReturnCode l_rc; iv_savedData = i_savedData; return l_rc; }

      uint32_t getSavedData() { return iv_savedData; }

    private: // Class variable(s)

      static const CmdType cv_cmdType;

    private: // Instance variable(s)

// list of things to save may be specific to each cmd, so keep it
// here for now
      uint32_t iv_savedData;

// Fast as possible, or slow (all memory on the MBA in 12h)
      TimeBaseSpeed iv_speed;
    };


//------------------------------------------------------------------------------
// mss_TimeBaseSteerCleanup
//------------------------------------------------------------------------------
    class mss_TimeBaseSteerCleanup : public mss_MaintCmd
    {
    public: // Constructor(s)

      mss_TimeBaseSteerCleanup( const fapi::Target & i_target,    // MBA target
                                const ecmdDataBufferBase & i_startAddr,  // Address cmd will start at
                                const ecmdDataBufferBase & i_endAddr,    // Address cmd will stop at
                                TimeBaseSpeed i_speed,                   // TODO: fast for runtime, faster for ipl?
                                uint32_t i_stopCondition,                // Mask of error conditions cmd should stop on
                                bool i_poll );                           // Set to true if you wait for command to complete

    public:

      fapi::ReturnCode setupAndExecuteCmd();
      CmdType getCmdType() const { return cv_cmdType; }

// This class's implementation of parent class functions that can be
// overridden.

      void setStartAddr(ecmdDataBufferBase i_startAddr)
      { iv_startAddr = i_startAddr; }

      void setEndAddr(  ecmdDataBufferBase i_endAddr  )
      { iv_endAddr   = i_endAddr;   }

      ecmdDataBufferBase getStartAddr() const { return iv_startAddr; }
      ecmdDataBufferBase getEndAddr()   const { return iv_endAddr; }

    private:

      fapi::ReturnCode setSavedData( uint32_t i_savedData )
      {fapi::ReturnCode l_rc; iv_savedData = i_savedData; return l_rc; }

      uint32_t getSavedData() { return iv_savedData; }

    private: // Class variable(s)

      static const CmdType cv_cmdType;

    private: // Instance variable(s)

// list of things to save may be specific to each cmd, so keep it
// here for now
      uint32_t iv_savedData;

// TODO: Want as fast as possible, but IPL may be able to go faster than
// runtime since no fetch traffic to worry about.
      TimeBaseSpeed iv_speed;
    };



//------------------------------------------------------------------------------
// Utility funcitons
//------------------------------------------------------------------------------


/**
  * @brief  Calculates start and end address for a single rank, or all ranks
  *         behind the MBA.
  *
  * @param  i_target       MBA target
  * @param  i_rank         Either single rank on the MBA to get start/end address
  *                        for (0x00-0x07)
  *                        Or MSS_ALL_RANKS = 0xff to get start/end address for
  *                        all ranks behind the MBA.
  * @param  o_startAddr    Address to start cmd at.
  * @param  o_endAddr      Address to stop cmd at.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_get_address_range( const fapi::Target & i_target,
                                            uint8_t i_rank,
                                            ecmdDataBufferBase & o_startAddr,
                                            ecmdDataBufferBase & o_endAddr );


/**
  * @brief  Mark store is implemented as one register per rank, so read register
  *         for the given rank.
  *         If MPE FIR for the given rank (scrub or fetch) is on after the read,
  *         we will read one more time to make sure we get latest.
  *
  * @param  i_target        MBA target
  * @param  i_rank          Rank to get markstore for.
  * @param  o_symbolMark    Symbol mark, converted from galois field to symbol
  *                         index,(if no mark return 0xff)
  * @param  o_chipMark      Chip mark, converted from galois field to first
  *                         symbol index of the chip, (if no mark return 0xff)
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_get_mark_store( const fapi::Target & i_target,
                                         uint8_t i_rank,
                                         uint8_t & o_symbolMark,
                                         uint8_t & o_chipMark );


/**
  * @brief  Mark store is implemented as one register per rank, so write register
  *         for the given rank.  NOTE: Will be writing to both chip and symbol
  *         field at same time, so should use a read/modify/write approach to
  *         avoid unintentionally over-writing something.
  *
  * @param  i_target       MBA target
  * @param  i_rank         Rank to write markstore for.
  * @param  i_symbolMark   Symbol index, which will be converted to galois field
  *                        (if input is 0xff, we write 0x00 for no symbol mark).
  * @param  i_chipMark     First symbol index of the chip, which will be
  *                        converted to galois field (if input is 0xff, we write
  *                        0x00 for no chip mark).
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_put_mark_store( const fapi::Target & i_target,
                                         uint8_t i_rank,
                                         uint8_t i_symbolMark,
                                         uint8_t i_chipMark );

/**
  * @brief  Gets either the read or write steer mux control register for the
  *         given rank, and converts from steer code to x8/x4 dram index to
  *         first symbol index for all DRAMs steered on that rank.
  *
  * @param  i_target                 MBA target
  * @param  i_rank                   Rank we want to read steer mux for.
  * @param  i_muxType                Select either the read mux or the write mux
  *                                  to get.
  * @param  o_dramSparePort0Symbol   First symbol index of the DRAM fixed by the
  *                                  spare on port0 (if no steer, return 0xff)
  * @param  o_dramSparePort1Symbol   First symbol index of the DRAM fixed by the
  *                                  spare on port1 (if no steer, return 0xff)
  * @param  o_eccSpareSymbol         First symbol index of the DRAM fixed by the
  *                                  ECC spare, which can be used on either port0
  *                                  or port1 (if no steer, return 0xff)
  * @note   The ECC spare is available only with x4 mode ECC.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_get_steer_mux( const fapi::Target & i_target,
                                        uint8_t i_rank,
                                        mss_SteerMux::muxType i_muxType,
                                        uint8_t & o_dramSparePort0Symbol,
                                        uint8_t & o_dramSparePort1Symbol,
                                        uint8_t & o_eccSpareSymbol );

/**
  * @brief  Updates either the read or write steer mux control register with the
  *         selected steer type for the given rank.
  *
  * @param  i_target                MBA target
  * @param  i_rank                  Rank we want to write steer mux for.
  * @param  i_muxType               Select either the read mux or the write mux
  *                                 to update.
  * @param  i_steerType             0 = DRAM_SPARE_PORT0, Spare DRAM on port0
  *                                 1 = DRAM_SPARE_PORT1, Spare DRAM on port1
  *                                 2 = ECC_SPARE, ECC spare (used in x4 mode only)
  * @param  i_symbol                First symbol index of the DRAM to steer
  *                                 around.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_put_steer_mux( const fapi::Target & i_target,
                                        uint8_t i_rank,
                                        mss_SteerMux::muxType i_muxType,
                                        uint8_t i_steerType,
                                        uint8_t i_symbol );

/**
  * @brief  Reads the steer muxes for the given rank
  *
  * @param  i_target                 MBA target
  * @param  i_rank                   Rank we want to read steer mux for.
  * @param  o_dramSparePort0Symbol   First symbol index of the DRAM fixed by the
  *                                  spare on port0 (if no steer, return 0xff)
  * @param  o_dramSparePort1Symbol   First symbol index of the DRAM fixed by the
  *                                  spare on port1 (if no steer, return 0xff)
  * @param  o_eccSpareSymbol         First symbol index of the DRAM fixed by the
  *                                  ECC spare, which can be used on either port0
  *                                  or port1 (if no steer, return 0xff)
  * @note   The ECC spare is available only with x4 mode ECC.
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_check_steering(const fapi::Target & i_target,
                                        uint8_t i_rank,
                                        uint8_t & o_dramSparePort0Symbol,
                                        uint8_t & o_dramSparePort1Symbol,
                                        uint8_t & o_eccSpareSymbol );

/**
  * @brief  Set write mux, wait for periodic cal, set read mux, for the given rank.
  *
  * @param  i_target                MBA target
  * @param  i_rank                  Rank we want to write steer mux for.
  * @param  i_symbol                First symbol index of the DRAM to steer
  *                                 around.
  * @param i_x4EccSpare             If true, writes the x4 ECC Spare. Otherwise,
  *                                 writes the DRAM spare (default).
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_do_steering(const fapi::Target & i_target,
                                     uint8_t i_rank,
                                     uint8_t i_symbol,
                                     bool i_x4EccSpare = false );


/**
  * @brief  This procedure applies the maximum possible DRAM repairs
  *         (chip/symbol marks, DRAM steers) to known bad bits recorded in
  *         DIMM VPD. This operation is done on both valid logical DIMM pairs
  *         behind the given MBA.
  *
  * @param  i_target                MBA target
  * @param  o_repairs_applied       8-bit mask, where a bit set means the
  *                                 specified rank had any repairs applied.
  *
  *                       rank0 = 0x80           (maps to port0_dimm0, port1_dimm0)
  *                       rank1 = 0x40           (maps to port0_dimm0, port1_dimm0)
  *                       rank2 = 0x20           (maps to port0_dimm0, port1_dimm0)
  *                       rank3 = 0x10           (maps to port0_dimm0, port1_dimm0)
  *                       rank4 = 0x08           (maps to port0_dimm1, port1_dimm1)
  *                       rank5 = 0x04           (maps to port0_dimm1, port1_dimm1)
  *                       rank6 = 0x02           (maps to port0_dimm1, port1_dimm1)
  *                       rank7 = 0x01           (maps to port0_dimm1, port1_dimm1)
  *
  * @param  o_repairs_exceeded      4-bit mask, where a bit set means the
  *                                 specified DIMM-select on the specified port
  *                                 had more bad bits than could be repaired.
  *
  *                        port0_dimm0 = 0x8
  *                        port0_dimm1 = 0x4
  *                        port1_dimm0 = 0x2
  *                        port1_dimm1 = 0x1
  *
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_restore_DRAM_repairs( const fapi::Target & i_target,
                                               uint8_t & o_repairs_applied,
                                               uint8_t & o_repairs_exceeded);


/**
  * @brief  This procedure counts the maximum possible DRAM repairs
  *         (chip/symbol marks, DRAM steers) to known bad bits recorded in
  *         DIMM VPD. This operation is done on both valid logical DIMM pairs
  *         behind the given MBA.
  *
  * @param  i_target                MBA target
  * @param  o_repairs_applied       8-bit mask, where a bit set means the
  *                                 specified rank had any repairs applied.
  *
  *                       rank0 = 0x80           (maps to port0_dimm0, port1_dimm0)
  *                       rank1 = 0x40           (maps to port0_dimm0, port1_dimm0)
  *                       rank2 = 0x20           (maps to port0_dimm0, port1_dimm0)
  *                       rank3 = 0x10           (maps to port0_dimm0, port1_dimm0)
  *                       rank4 = 0x08           (maps to port0_dimm1, port1_dimm1)
  *                       rank5 = 0x04           (maps to port0_dimm1, port1_dimm1)
  *                       rank6 = 0x02           (maps to port0_dimm1, port1_dimm1)
  *                       rank7 = 0x01           (maps to port0_dimm1, port1_dimm1)
  *
  * @param  o_repairs_exceeded      4-bit mask, where a bit set means the
  *                                 specified DIMM-select on the specified port
  *                                 had more bad bits than could be repaired.
  *
  *                        port0_dimm0 = 0x8
  *                        port0_dimm1 = 0x4
  *                        port1_dimm0 = 0x2
  *                        port1_dimm1 = 0x1
  *
  * @param  i_strandby_flag     Boolean if we are in standby at call time
  *
  * @param  o_repair_count      Repair counts
  *
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_restore_DRAM_repairs_asm( const fapi::Target & i_target,
                                                      uint8_t & o_repairs_applied,
                                                      uint8_t & o_repairs_exceeded,
                                                      uint8_t i_standby_flag,
                                                      struct repair_count &o_repair_count);





/**
  * @brief  This function takes converts from a Centaur DQ on a given port
  *         to a corresponding symbol index.
  *
  * @param  i_dq     Centaur DQ from 0-71
  *
  * @param  i_port   port 0 or 1
  *
  * @return          Symbol index
  */

    uint8_t mss_centaurDQ_to_symbol( uint8_t i_dq, uint8_t i_port );


/**
  * @brief  This function compares trapped actual UE data to an expected
  *         data pattern in order to identify the bits that contributed to
  *         a UE encountered during IPL memory diagnostics.
  *
  * @param  i_target                MBA target
  * @param  i_rank                  Rank containing the UE.
  * @param  o_bad_bits              Map of bad bits (Centaur DQ format)
  *                                 2 ports x 10 bytes
  *
  * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
  */
    fapi::ReturnCode mss_IPL_UE_isolation( const fapi::Target & i_target,
                                           uint8_t i_rank,
                                           uint8_t (&o_bad_bits)[2][10]);


#endif/* _MSS_MAINT_CMDS_H */
