/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlmanager.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
#include <sys/sync.h>
#include <kernel/timemgr.H>
#include <hbotcompid.H>
#include <hwas/common/hwasCallout.H>
#include <mbox/mbox_queues.H>
#include <mbox/mboxif.H>


namespace ERRORLOG
{

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

/**
 *  @brief  Global enums used by static errlResourceReady function
 */
enum errlManagerNeeds
{
    PNOR,
    TARG,
    MBOX,
} ;


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
      *  @brief Commit an error log by sending it to the repository
      *  Writes the log to PNOR where committed logs are kept.
      *  If there's not enough room, remove the latest log(s) to make
      *  enough room to commit this log.
      *  The error log will be automatically deleted after the
      *  commit.  The input handle will be set to NULL.
      *  For Host Boot environment, there's no individual committer
      *  (i.e. committer = Host Boot), so no component ID of
      *  committer is specified.
      *
      *  @param[in,out] io_err  Error log handle to be committed
      *
      *  @return None
      */
     void commitErrLog(errlHndl_t& io_err, compId_t i_committerComp );

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
      * AFTER ErrlManager starts. Currently, that's PNOR MBOX and TARGeting.
      *
      * It is a static function because a module cannot call an interface on a
      * singleton in another module
      */
     static void errlResourceReady(errlManagerNeeds i_needs);

     /**
      * @brief Sends msg to errlmanager telling what resources are ready
      *
      * This is called by resources that the ErrlManager needs, which start up
      * AFTER ErrlManager starts. Currently, that's PNOR MBOX and TARGeting.
      *
      */
     void sendResourcesMsg(errlManagerNeeds i_needs);

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
        ERRLOG_PLID_BASE        = 0x90000000,// Hostboot Base PLID Offset
        ERRLOG_PLID_BASE_MASK   = 0x9F000000,// mask of just the id
        ERRLOG_PLID_NODE_SHIFT  = 24,        // shift to put node number 0x9#
        ERRLOG_PLID_MASK        = 0x00FFFFFF,// mask to find log number
        ERRLOG_PLID_INITIAL     = 0x00FF0000,// initial big id number
    };

    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlManager(const ErrlManager& i_right);
    ErrlManager& operator=(const ErrlManager& i_right);

    /**
     * @brief Access PNOR and get the address and size of the HBEL section in
     * PNOR; sets the iv_pnorAddr, iv_maxErrlInPnor, iv_pnorOpenSlot variables;
     * parsers the error logs in PNOR and determines the new iv_currLogId.
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
     * @return        msg_t pointer - NULL if msg sent, allocated msg if
     *                  couldn't send
     *
     */
    msg_t *sendErrLogToMbox ( errlHndl_t& io_err );

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
      * @brief
      * Pointer to the header that preceeds the error log storage buffer
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
     * @return NONE
     *
     */
    void ackErrLogInPnor( uint32_t i_errEid );

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
     * @brief set the ACK bit in the flattened error log in PNOR;
     *      MUST point to a non-empty slot
     *
     * @param[in]   i_position - index into PNOR to check
     * @return NONE
     *
     */
    void setACKInFlattened(uint32_t i_position);

    /**
      * @brief errorlog-into-PNOR variables
      */
    char *iv_pnorAddr;          // HBEL section in PNOR
    uint32_t iv_maxErrlInPnor;  // max number of errorlogs that will fit
    uint32_t iv_pnorOpenSlot;   // current open slot available for an errorlog
    std::list<errlHndl_t> iv_errlToSave;   // errlogs still to be saved to PNOR

    bool iv_isSpBaseServices;           // do we need to send to FSP
    bool iv_isMboxEnabled;              // are we able to send to FSP
    std::list<msg_t *> iv_errlToSend;   // msgs still to be sent to FSP
};

} // End namespace

#endif //ERRLMANAGER_H
