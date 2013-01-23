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
        ERRLOG_SHUTDOWN                    = 0x00000033 | MBOX::FIRST_SECURE_MSG, 
    };

    /**
     * @enum  ERRORLOG_PLID_OFFSET
     *
     * Base ID of Hostboot PLIDs.  The hostboot plid range is 0x90 to 0x93
     * (For each instance running on a multinode system.  Eventually the
     * offset will need to be offset for the proper node and possibly some
     * other initializer sent from FSP to keep PLIDs unique across IPLs.
     *
     * NOTE: Changes to this define may require changes to
     *       CpuManager::requestShutdown
     */
    enum ERRORLOG_PLID_OFFSET
    {
        ERRLOG_PLID_BASE    = 0x90000000, /**< Hostboot Base PLID Offset */
    };

    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlManager(const ErrlManager& i_right);
    ErrlManager& operator=(const ErrlManager& i_right);

    /**
     * @brief Create and register the error log message queue
     *
     * @param[in/out] NONE
     * @return NONE.
     */
    void msgQueueInit ( void );


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
    void errlogMsgHndlr ( void );

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
    void errlogShutdown( void ); 

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

};

} // End namespace

#endif //ERRLMANAGER_H
