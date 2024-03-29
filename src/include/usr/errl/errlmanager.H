/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlmanager.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
/* [+] Google Inc.                                                        */
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
#ifndef ERRLMANAGER_H
#define ERRLMANAGER_H
/**
 *  @file errlmanager.H
 *
 *  @brief  Error Log management for Host Boot environment.
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <util/singleton.H>
#include <errl/errlentry.H>
#include <errldisplay/errldisplay.H>
#include <sys/sync.h>
#include <hbotcompid.H>
#include <hwas/common/hwasCallout.H>
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>
#include <utility>
#include <list>
#include <memory>
#include <time.h>

namespace ERRORLOG
{

//***************************************
//* Marker Lid Section
//  as found in file /fips1010/src/cupd/fsp/cupdUtils.H
//***************************************
// Marker lid structure
typedef struct {
    uint32_t   Version;              // This is the common marker lid structure version
    uint32_t   MIKeyWordOffset;      // Offset from the beginning of the marker data to the MI keyWord
    uint32_t   iSeriesMarkerOffset;  // Offset from the beginning of the marker data to the Mif level.
} markerHeader_t;

// Marker Lid MI Keyword section
// The MI Keyword, MIKeyword[40], is the firmware release version used to set
// the attribute ATTR_FW_RELEASE_VERSION.
typedef struct {
    uint32_t MIKeyWordSize;
    char MIKeyword[40];
    char DisrApply[3];
    char DisrActivation[3];
    char DisrPhyp[3];
    char DisrPfw[3];
    char DisrFsp[3];
    char Phyp[3];
    char Pfw[3];
    char Rsv[3];
    uint32_t ADFOffset;
} markerMI_t;

/**
 *  @brief  Global function to log an error
 *  Writes the log to PNOR where committed logs are kept.
 *  If there's not enough room, remove the latest log(s) to make
 *  enough room to commit this log.
 *  The error log will be automatically deleted after the
 *  commit.  The input handle will be set to NULL.
 *  For Host Boot environment, there's no individual committer
 *  (i.e. committer = Host Boot), so no component ID of
 *  committer is specified.
 *  This function is global in order to workaround the singleton
 *  linker issue in HostBoot (linker can't find singleton outside of
 *  a module).
 *
 *  @param[in,out] io_err          Error log handle to be committed
 *  @param[in]     i_comitterComp  Component committing the error log
 *
 *  @return None
 */
void errlCommit(errlHndl_t& io_err, compId_t i_committerComp );

/** @brief Wrapper around errlCommit(errlHndl_t, compId_t).
 *         Takes ownership of the given error.
 */
template<typename Del>
inline void errlCommit(errlOwner_d<Del>& io_err, const compId_t i_committerComp)
{
    errlHndl_t err = io_err.release();
    errlCommit(err, i_committerComp);
}

/** @brief Wrapper around errlCommit(errlHndl_t, compId_t).
 *         Takes ownership of the given error.
 */
template<typename Del>
inline void errlCommit(errlOwner_d<Del>&& io_err, const compId_t i_committerComp)
{
    errlHndl_t err = io_err.release();
    errlCommit(err, i_committerComp);
}

/**
 *  @brief  Global function to log a large error log into multiple logs
 *          Instead of removing latest log(s) to make enough room, this function
 *          moves these logs into new error logs which point to original one's plid
 *
 *  @param[in/out] io_err           Error log handle to be committed
 *  @param[in]     i_committerComp  Component committing the error log
 *  @param[in]     i_keepTraces     Try to keep trace entries in first log
 *
 *  @return None
 */
void errlCommitAllowExtraLogs(errlHndl_t& io_err, compId_t i_committerComp, bool i_keepTraces );

/**
 *  @brief  Global function to determine if INFO and Recovered errors
 *          should be skipped or forwarded
 *
 *  @param[in]     None
 *
 *  @return iv_hiddenErrLogsEnable
 */
uint8_t getHiddenLogsEnable();

/**
 *  @brief  Global enums used by static errlResourceReady function
 */
enum errlManagerNeeds
{
    PNOR,
    TARG,
    MBOX,
    BMC,
    ERRLDISP,
    UPDATE_ATTRIB_VARS,  // Force the refresh/update of attribute variables
} ;

const uint64_t MIN_PLD_WAIT_TIME_SEC = 10;

/*****************************************************************************/
// Forward class declarations
/*****************************************************************************/
class ErrlEntry;
class ErrlManager;

// Singleton - Use "theErrlManager::instance()" to access the singleton
typedef Singleton<ErrlManager> theErrlManager;

/**
 *  @brief  Error log manager
 *  This class provides interfaces to perform some specific tasks
 *  on existing error objects such as committing a log, sending the
 *  log to the SP, etc..
 */
class ErrlManager
{

public:

    /**
     *  @brief Commit an aggregate error log by sending it to the repository
     *  Writes the log to PNOR where committed logs are kept.
     *  If there's not enough room, remove the latest log(s) to make
     *  enough room to commit this log.
     *  The error log will be automatically deleted after the
     *  commit.  The input handle will be set to NULL.
     *  For Host Boot environment, there's no individual committer
     *  (i.e. committer = Host Boot), so no component ID of
     *  committer is specified.
     *
     *  @param[in,out] io_err          Error log handle to be committed
     *  @param[in]     i_comitterComp  Component committing the error log
     *
     *  @return None
     */
    void commitErrLog(errlHndl_t& io_err, compId_t i_committerComp );

    /**
     *  @brief  Acts like commitErrLog but instead of removing latest log(s) to
     *          make enough room, this function moves these logs into new
     *          informational error logs which point to original one's plid
     *          Commits up to 5 informational logs for each original one
     *
     *  @param[in/out] io_err           Error log handle to be committed
     *  @param[in]     i_committerComp  Component committing the error log
     *  @param[in]     i_keepTraces     Try to keep trace entries in first log
     *
     *  @return None
     */
     void commitErrAllowExtraLogs(errlHndl_t& io_err,
                                  compId_t i_committerComp,
                                  bool i_keepTraces );

    /**
     * @brief  Returns a unique error log ID
     *
     * This routine generates a unique Error ID and assign it to
     * the input error log. Mutates iv_currLogId.
     *
     * @return  Unique generated error log ID
     */
    uint32_t getUniqueErrId();

    /**
     * @brief Sets the HWAS ProcessCallout function pointer
     *
     * This is called by HWAS to inform errlmanager that HWAS is loaded and
     * therefore it can call HWAS to process callout information in an errlog
     *
     * It is a static function because a module cannot call an interface on a
     * singleton in another module
     */
    static void setHwasProcessCalloutFn(HWAS::processCalloutFn i_fn);

    /**
     * @brief Sends msg to errlmanager telling what resources are ready
     *
     * This is called by resources that the ErrlManager needs, which start up
     * AFTER ErrlManager starts.
     *
     * It is a static function because a module cannot call an interface on a
     * singleton in another module
     */
    static void errlResourceReady(errlManagerNeeds i_needs);

    /**
     * @brief Sends msg to errlmanager to ack sending of errl to BMC
     *
     * This is called by pldm code once the indicated errorlog
     * has been successfully sent to the BMC
     *
     * It is a static function because a module cannot call an interface on a
     * singleton in another module
     */
   static void errlAckErrorlog(uint32_t i_eid);

    /**
     * @brief Calls flush error logs
     *
     * This is called by doIstep after every istep to ensure that the error
     * logs have been cleared out before checking if a reconfigure loop
     * is needed
     *
     * It is a static function because a module cannot call an interface on a
     * singleton in another module
     */
    static void callFlushErrorLogs();

    /**
     * @brief  Returns the HWAS ProcessCallout function pointer
     *
     * This is called by ErrlEntry::commit to get the HWAS ProcessCallout
     * function pointer, this is called to process callout information in an
     * errlog, if NULL is returned then the function cannot be called (because
     * the HWAS module is not loaded)
     *
     * @return HWAS::processCalloutFn function pointer
     */
    HWAS::processCalloutFn getHwasProcessCalloutFn() const
    {
        return iv_hwasProcessCalloutFn;
    }

    /**
     * @brief Determines if any non-informational logs have been committed
     *        during this boot.
     *
     * @return true - A non-informational log has been committed.
     */
    static bool errlCommittedThisBoot();


    /**
     * @brief   Value to determine what logs are to be skipped. Mirrors
     *          what is currently set in ATTR_HIDDEN_ERRLOGS_ENABLE
     */
    static uint8_t iv_hiddenErrLogsEnable;

    /**
     * @brief Retrieve the MI keyword from the Marker LID.
     *
     * @details If the caller passes in 0 for the buffer size (io_bufferSize) then the
     *           size of the MI keyword will be returned and the buffer (o_buffer) will
     *           remain untouched.
     *          If the caller passes in a length of N for the buffer size and the size
     *           is less than the size of the MI keyword then an error log will be
     *           generated and returned.
     *          If the caller passes in a length of N for the buffer size but the buffer
     *           (o_buffer) is a nullptr then an error log will be generated and returned.
     *          If the caller passes in a length of N for the buffer and the buffer is not
     *           a nullptr; if N is greater than or equal to the size of MI keyword
     *           then the retuned buffer size will be the size of the MI keyword and the
     *           MI keyword will be copied over into the buffer with any bytes beyond
     *           the size of the MI keyword zeroed out.
     *
     * @note The MI keyword, that is copied over to the out buffer (o_buffer), is not a
     *       string in the sense that it is null terminated.  If the actual data of the MI
     *       keyword is less than the size of the buffer and/or less than the size of
     *       MI keyword itself, then the bits beyond the MI keyword actual data will
     *       be zeroed out acting as null terminated string.
     *
     * @param[in/out] io_bufferSize - Input: If 0, then the method will return the size of
     *                                       the MI Keyword
     *                                Input: If N, then the size should be large enough to
     *                                       hold the MI keyword, else an error will be returned
     *                                Output: If no error, will return the size of MI keyword
     *                                        regardless of the value of the input
     *
     * @param[out] o_buffer - If given a nullptr then a nullptr is returned, else the buffer
     *                        will contain the MI Keyword if large enough to hold the MI Keyword
     *                        otherwise an error is returned
     *
     * @return nullptr on success; non-nullptr on error.
     */
    static errlHndl_t getMarkerLidMiKeyword(size_t &io_bufferSize, char* const o_buffer);

    /**
     * @brief Set the FW Release Version Field at runtime
     *
     * @details This method is a runtime method that will set the FW Release Version.
     *          Useful for when a code update changes the FW Release Version.
     *
     * @note This method needs to be called after TARGETING is ready, if not an
     *       assertion will be thrown stating that 'TARGETING is not ready'.
     *       Currently being called in the initErrlManager method which is occurring
     *       after initialization of TARGETING.
     */
    void setFwReleaseVersion_rt();

    /**
     * @brief A wrapper around ErrlManager's _getFirstHbrtEid. Returns the
     *        value of the first EID to be used in HBRT.
     *
     * @return The value of the first EID to be used in HBRT.
     */
    static uint32_t getFirstHbrtEid();

    /**
     * @brief A wrapper around ErrlManager's _getLastIplEid. Returns the
     *        value of the last EID generated during IPL.
     *
     * @return The value of the last EID generated during IPL.
     */
    static uint32_t getLastIplEid();

#ifndef __HOSTBOOT_RUNTIME
    /**
     * @brief A wrapper around ErrlManager's _setLastIplEid. Sets the
     *        value of the last EID generated during IPL to the provided
     *        value.
     *
     * @param[in] i_plid the desired value of the last EID generated during IPL
     */
    static void setLastIplEid(uint32_t i_eid);
#endif

#ifdef __HOSTBOOT_RUNTIME
    /* @brief Set up the ErrlManager instance. This must be called before the
     * ErrlManager is used.
     */
    void setup();
#endif

protected:
    /**
     * @brief   Destructor
     *
     * Releases all resources owned by the handle.  If the log has not
     * been committed, it effectively aborts the log.
     * All logs (committed or not) must be deleted to avoid a resource leak.
     *
     * @return  None
     *
     */
    ~ErrlManager();

    /**
     * @brief Default constructor
     *        Protected so only SingletonHolder can call
     */
    ErrlManager();

private:

    /** @brief Implementation of commitErrLog; commits the given error
     *  and all errors owned by it as part of the aggregate.
     *
     *  @note This function takes ownership of the given error log.
     */
    void commitErrLogAggregate(errlHndl_t& io_err, compId_t i_committerComp);

    /**
     * @enum ERRLOG_MSG_TYPE
     *
     * @brief Message types that recognized by the error log message queue
     */
    enum ERRLOG_MSG_TYPE
    {
        ERRLOG_NEEDS_TO_BE_COMMITTED_TYPE  = 0x00000030 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_SEND_TO_FSP_TYPE            = 0x00000031 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_COMMITTED_ACK_RESPONSE_TYPE = 0x00000032 | MBOX::FIRST_UNSECURE_MSG,
        ERRLOG_SHUTDOWN_TYPE               = 0x00000033 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_ACCESS_PNOR_TYPE            = 0x00000034 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_ACCESS_MBOX_TYPE            = 0x00000035 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_ACCESS_TARG_TYPE            = 0x00000036 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_ACCESS_ERRLDISP_TYPE        = 0x00000037 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_ACCESS_BMC_TYPE             = 0x00000038 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_FLUSH_TYPE                  = 0x00000039 | MBOX::FIRST_SECURE_MSG,
        ERRLOG_UPDATE_ATTRIB_VARS_TYPE     = 0x00000040 | MBOX::FIRST_SECURE_MSG,
    };

    /**
     * @enum  ERRORLOG_PLID_OFFSET
     *
     * Base ID of Hostboot PLIDs.  The hostboot plid range is 0x90 to 0x93
     * for each instance running on a multinode system.
     *
     * NOTE: Changes to this define (if '9' changes) will require changes to
     *       CpuManager::requestShutdown
     */
    enum ERRORLOG_PLID_OFFSET
    {
#ifdef __HOSTBOOT_RUNTIME
        ERRLOG_PLID_BASE        = 0x80000000,// Hostboot Runtime Base PLID Offset
        ERRLOG_PLID_BASE_MASK   = 0x89000000,// mask of just the id
#else
        ERRLOG_PLID_BASE        = 0x90000000,// Hostboot Base PLID Offset
        ERRLOG_PLID_BASE_MASK   = 0x9F000000,// mask of just the id
#endif
        ERRLOG_HBRT_EID_BASE   = 0x80000000,// HBRT base EID
        ERRLOG_PLID_NODE_SHIFT  = 24,        // shift to put node number 0x9#
        ERRLOG_PLID_MASK        = 0x00FFFFFF,// mask to find log number
        ERRLOG_PLID_INITIAL     = 0x00800000,// min number for pre-boot
        ERRLOG_PLID_PRE_MAX     = 0x00FFFFFF,// max number during pre-boot
        ERRLOG_PLID_POST_MAX    = 0x007FFFFF,// max number after pre-boot
    };

    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlManager(const ErrlManager& i_right);
    ErrlManager& operator=(const ErrlManager& i_right);

     /**
      * @brief Sends msg to errlmanager telling what resources are ready
      *
      * called by static errlResourceReady function.
      */
     void sendResourcesMsg(errlManagerNeeds i_needs);

     /**
      * @brief Flushes out the error log queue before calling to process
      * deferred deconfigs
      *
      * called by static callFlushErrorLogs function.
      */

     void flushErrorLogs();

     /**
      * @brief Sends msg to errlmanager telling which errlog to ack
      *
      * called by static errlAckErrorlog function.
      */
     void sendAckErrorlog(uint32_t i_eid);

    /**
     * @brief Access PNOR and get the address and size of the HBEL section in
     * PNOR; sets the iv_pnorAddr, iv_maxErrlInPnor, iv_pnorOpenSlot variables;
     * parses the error logs in PNOR and determines the new iv_currLogId.
     *
     * @param[in/out] NONE
     * @return NONE.
     */
    void setupPnorInfo();

    /**
     * @brief Create and register the error log message queue
     *
     * @param[in/out] NONE
     * @return NONE.
     */
    void msgQueueInit ();

    /**
     *  @brief Performs startup of the error log processing thread.
     *
     *  @param[in/out]
     *  @return NONE
     */
     static void * startup ( void* i_self );

    /**
     *  @brief Performs setup of the PNOR info.  Done as a separate
     *         thread to handle error conditions (ECC on HBEL) where
     *         task gets killed.
     *
     *  @param[in/out]
     *  @return NONE
     */
     static void * pnorSetupThread ( void* i_self );

    /**
     * @brief Message handler for process Hostboot error log message
     *        and send it to FSP.
     *
     * @param[in/out] NONE
     * @return NONE
     *
     */
    void errlogMsgHndlr ();

    /**
     * @brief Send Host boot error log to error message queue for committing.
     *
     * @param[in,out] io_err Error log handle to be committed
     * @param[in] i_committerComp Component id that committed the error
     *
     * @return NONE
     *
     */
    void sendErrlogToMessageQueue ( errlHndl_t& io_err, compId_t i_committerComp );

    /**
     * @brief Create a mailbox message with the error log and send it to Fsp.
     *
     * @param[in,out] io_err Error log handle to be committed
     *
     */
    void sendErrLogToFSP ( errlHndl_t& io_err );

    /**
     * @brief Create a mailbox message with the error log and send it to Fsp.
     *
     * @param[in,out] io_err Error log handle to be committed
     * @return NONE
     *
     */
    void sendMboxMsg ( errlHndl_t& io_err );

    /**
     * @brief Save errlog entry in the memory
     *
     * @param[in,out] io_err Error log handle to be committed
     * @return NULL
     *
     */
    void saveErrLogEntry( errlHndl_t& io_err );

    /**
     * @brief Shutdown error log manager
     *
     * @param[in,out] None
     * @return NULL
     *
     */
    void errlogShutdown();

    /**
      * @brief    Current log ID.  As new error logs are created,
      * this value will be used to assign the new error log its ID.
      */
    uint32_t    iv_currLogId;

    /**
      * @brief    Base & Node part of log ID.
      *  This value will be used as a common ID among this node's error logs
      */
    uint32_t    iv_baseNodeId;

    /**
     *  @brief   Indicates if PNOR is ready for handling error logs
     *  Will cause a switch of MIN/MAX values used in calculating the
     *  next iv_currLogId.
     */
    bool        iv_pnorReadyForErrorLogs;

    /**
     *  @brief  Indicates if we have processed a shutdown event message
     */
    bool        iv_recvdShutdownEvent;

    /**
      * @brief
      * Pointer to the header that precedes the error log storage buffer
      * in L3 RAM.  This may go away when we adopt PNOR, or else become
      * instance variables instead of a pointer pointing within the
      * storage buffer.
      */
    storage_header_t * iv_pStorage;

    /**
      * @brief    Pointer to the HWAS processCallout function
      */
    HWAS::processCalloutFn iv_hwasProcessCalloutFn;

    /**
      * @brief Message queue for error log
      */
    msg_q_t iv_msgQ;

    // functions relating to writing the errorlogs to PNOR

    /**
     * @brief flatten and save the error log into PNOR
     *
     * @param[in]   error log handle
     * @return      true if saved in PNOR, false if not
     *
     */
    bool saveErrLogToPnor( errlHndl_t& io_err);

    /**
     * @brief find the flattened error log in PNOR and set it's ACK bit
     *
     * @param[in]   i_errEid EID of the error log to look for
     * @return      true if we successfully set the ACK bit,
     *              false if we couldn't find that errlog in PNOR
     */
    bool ackErrLogInPnor( uint32_t i_errEid );

    /**
     * @brief check the state of the PNOR 'slot'
     *
     * @param[in]   i_position - index into PNOR to check
     * @return      true if slot is empty
     *                  (first 32bits == EMPTY_ERRLOG_IN_PNOR)
     *
     */
    bool isSlotEmpty(uint32_t i_position);

    /**
     * @brief check the state of the PNOR 'slot'
     *          ONLY to be called on a slot that is NOT empty
     *
     * @param[in]   i_position - index into PNOR to check
     * @return      true if errlog in this slot has been ACKed
     *                  (ACK bit in word5 is 0x0)
     *
     */
    bool isSlotACKed(uint32_t i_position);

    /**
     * @brief increment the iv_PnorOpenSlot variable to the next
     *      available slot, handling wrap and checking that the
     *      slot is either EMPTY or has an ACKed error log.
     *
     * @return true if there was an open slot, false if PNOR is full
     *
     */
    bool incrementPnorOpenSlot();

    /**
     * @brief read the Eid from the flattened error log in PNOR;
     *      MUST point to a non-empty slot
     *
     * @param[in]   i_position - index into PNOR to check
     * @return      eid for that error log
     *
     */
    uint32_t readEidFromFlattened(uint32_t i_position);

    /**
     * @brief read the Plid from the flattened error log in PNOR;
     *      MUST point to a non-empty slot
     *
     * @param[in]   i_position - index into PNOR to check
     * @return      plid for that error log
     *
     */
    uint32_t readPlidFromFlattened(uint32_t i_position);

    /**
     * @brief set the ACK bit in the flattened error log in PNOR;
     *      MUST point to a non-empty slot
     *
     * @param[in]   i_position - index into PNOR to check
     * @return NONE
     *
     */
    void setACKInFlattened(uint32_t i_position);

#ifdef CONFIG_PLDM
    /**
     * @brief Send the error log down to the BMC
     *
     * @param[in,out] io_err Error log handle to be committed
     * @param[in] i_isPrevBootErr Is error from previous boot
     * @return true if error log successfully sent and acked
     */
    bool sendErrLogToBmc(errlHndl_t &io_err, bool i_isPrevBootErr = false);
#endif


    /**
      * @brief errorlog-into-PNOR variables
      */
    char *iv_pnorAddr;          // HBEL section in PNOR
    uint32_t iv_maxErrlInPnor;  // max number of errorlogs that will fit
    uint32_t iv_pnorOpenSlot;   // current open slot available for an errorlog
    bool iv_isFSP;              // do we need to send to FSP
    uint32_t iv_firstHbrtEid;   // The value of the first HBRT EID
#ifndef __HOSTBOOT_RUNTIME
    uint32_t iv_lastIplEid;     // The value of the last (highest) IPL-time EID
    bool iv_isMboxEnabled;      // are we able to send to FSP
    bool iv_nonInfoCommitted;   // Keeps track of any non-informational logs.
    bool iv_isErrlDisplayEnabled; // are we able to use the errorDisplay
#endif //#ifndef __HOSTBOOT_RUNTIME
    bool iv_pldWaitEnable; // should we wait for SP to check for PLD errors?
    int64_t iv_isBmcInterfaceEnabled;  // > 0 means we are able to send to BMC

    bool isBmcInterfaceEnabled() const { return iv_isBmcInterfaceEnabled > 0; }
    void enableBmcInterface() { iv_isBmcInterfaceEnabled++; }
    void disableBmcInterface() { iv_isBmcInterfaceEnabled--; }

    // Errl flags which represent processing needed by the errl
    // represented as a bit field (8 bits)
    // Note: When adding a new flag, add to the trace in errlogShutdown()
    enum ERRLOG_FLAGS
    {
        PNOR_FLAG         = 0x01,
        MBOX_FLAG         = 0x02,
        ERRLDISP_FLAG     = 0x04,
        BMC_FLAG          = 0x08,
        BMC_PREV_ERR_FLAG = 0x10,
        ALL_FLAGS       = PNOR_FLAG | MBOX_FLAG
    #ifdef CONFIG_PLDM
                                    | BMC_FLAG
    #endif
    #ifdef CONFIG_CONSOLE_OUTPUT_ERRORDISPLAY
                                    | ERRLDISP_FLAG
    #endif
    };

    // List of messages errl manager needs to handle
    // The unint8_t is a bit field to indiciate what needs to be done
    typedef std::pair<errlHndl_t, uint8_t> ErrlFlagPair_t;
    typedef std::list<ErrlFlagPair_t> ErrlList_t;
    typedef ErrlList_t::iterator ErrlListItr_t;
    ErrlList_t iv_errlList;

    /**
     * @brief checks if the flag is set
     *
     * @param[in]   i_pair - pair of errl and bitfield of flags
     * @param[in]   i_flag - specific flag
     * @return      True if specified flag is set
     *
     */
    static bool _isFlagSet(const ErrlFlagPair_t &i_pair,
                                const ERRLOG_FLAGS i_flag)
    {
        return (i_pair.second & i_flag);
    }

    /**
     * @brief clears the flag, indicating complete
     *
     * @param[in/out]   io_pair - pair of errl and bitfield of flags
     * @param[in]       i_flag - specific flag
     * @return          NA
     *
     */
    static void _clearFlag(ErrlFlagPair_t &io_pair,
                            const ERRLOG_FLAGS i_flag)
    {
        io_pair.second &= ~i_flag;
    }

    /**
     * @brief Checks if all flags are cleared for a errlhndl.
     *        If so deletes and NULLs the errl and removes from errl list.
     *        It then updates the iterator accordingly, done in this function
     *        to properly handle when a list.erase() happens
     *
     * @param[in/out]   io_it - iterator for the iv_errlList
     * @return          True if an erase occurred, otherwise false
     *
     */
    bool _updateErrlListIter(ErrlListItr_t & io_it);

    /**
     * @brief helper function to set the 'iv_skipShowingLog' flag of an error
     * log. this needs to be called when we first get an errl object before we
     * try to handle it. ie, when it's going to be committed, AND when it's
     * been unflattened out of PNOR
     *
     * @param[in/out]   io_err - errorlog that's being checked and updatd
     */
    void setErrlSkipFlag(errlHndl_t io_err);

    base_time_t iv_baseDateTime; // The base/reference date/time taken at the
                                 // time this daemon starts

    /**
     * @brief Returns the value of the first EID to be used in HBRT.
     *
     * @return The value of the first EID to be used in HBRT.
     */
    uint32_t _getFirstHbrtEid();

#ifndef __HOSTBOOT_RUNTIME
    /**
     * @brief Returns the value of the last EID that was generated during
     *        IPL and written to PNOR.
     *
     * @return The value of the last EID generated during IPL
     */
    uint32_t _getLastIplEid();

    /**
     * @brief Sets the value of the last EID generated during IPL to the
     *        given value.
     *
     * @param[in] i_eid the desired EID number
     */
    void _setLastIplEid(uint32_t i_eid);
#endif

    /**
     * @brief Helper function to check whether the EID of the error log
     *        at the specified position in PNOR matches the given EID.
     *
     * @param[in] i_position the position of the error log in PNOR
     * @param[in] i_plid the EID against which to compare
     * @return true if the EID matches; false otherwise
     */
    bool doesEidMatch(uint32_t i_position, uint32_t i_eid);

    /**
     * @brief A helper function to check if the EID of the error log at
     *        the given position matches that of the last EID that was
     *        recorded during IPL.
     *
     * @param[in] i_position the position of the error log in PNOR to check
     * @return true if the EID at the requested position matches the last
     *         EID recorded during IPL; false otherwise
     */
    bool isLastIplEid(uint32_t i_position);

    /**
     * @brief A helper function to check if the EID of the error log at
     *        the given position matches that of the first EID that HBRT
     *        will use (the highest HBRT EID found in the HBEL partition).
     *
     * @param[in] i_position the position of the error log in PNOR to check
     * @return true if the EID at the requested position matches the first
     *         EID that HBRT will use; false otherwise
     */
    bool isFirstHbrtEid(uint32_t i_position);

};

} // End namespace

#endif //ERRLMANAGER_H
