//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errlmanager.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#include <stdint.h>
#include <stdlib.h>
#include <util/singleton.H>
#include <errl/errlentry.H>
#include <sys/sync.h>
#include <vector>
#include <kernel/timemgr.H>
#include <hbotcompid.H>




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

// TODO Work item 4104 to make comitter comp required, no default.
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
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlManager(const ErrlManager& i_right);
    ErrlManager& operator=(const ErrlManager& i_right);


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
      * @brief Serialization for error log commits.
      */
    mutex_t    iv_mutex;

};

} // End namespace

#endif //ERRLMANAGER_H
