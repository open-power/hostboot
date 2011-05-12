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
#include <errl/errltypes.H>

namespace ERRORLOG
{

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
      *  - Writes the log to PNOR where committed logs are kept.
      *    If there's not enough room, remove the latest log(s) to make
      *    enough room to commit this log.
      *  - The error log will be automatically deleted after the
      *    commit.  The input handle will be set to NULL.
      *  - For Host Boot environment, there's no individual committer
      *    (i.e. committer = Host Boot), so no component ID of
      *    committer is specified.
      *
      *  @param[in/out]  io_err      Error log handle to be committed
      *
      *  @return None
      */
     void commitErrLog(errlHndl_t& io_err);


     /**
      * @brief  Returns a unique error log ID
      *
      * This routine generates a unique Error ID and assign it to
      * the input error log
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


    uint32_t    iv_currLogId;

};

} // End namespace

#endif //ERRLMANAGER_H
