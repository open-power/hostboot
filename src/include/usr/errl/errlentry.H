#ifndef ERRLENTRY_H
#define ERRLENTRY_H
/**
 *  @file errlentry.H
 *
 *  @brief  Error Log entry object for Host Boot environment.
 *
 *  This header file contains the definition of error log entry class that
 *  is used to log errors from all firmware running in Host Boot environment.
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <vector>
#include <errl/errltypes.H>
#include <hbotcompid.H>

namespace ERRORLOG
{

/*****************************************************************************/
// Forward class declarations
/*****************************************************************************/
class ErrlManager;
class ErrlSctn;
class ErrlFFDC;

/**
 *  @brief	Host Boot Error log entry class.
 *  This class contains all of the entry management logic and necessary
 *  information to create a PEL or IPMI event type logs.
 *  A pointer to this class is known as an errlHndl_t (the error log handle)
 *  and it is the data type passed by applications on the stack to convey
 *  a failure.
 */
class ErrlEntry
{

    friend class ErrlManager;

public:
    /**
     * @brief	ErrlEntry constructor. Builds an error log with info
     * constructed from the input.
     * Event type, Sub System, SRC type, and Terminate state are defaulted
     * to the most common values for Host Boot environment.  These values
     * can also be set to specific values by users if needed.
     * For available values, see errltypes.H
     * To understand the meaning of these values, refer to the
     * Platform Event Log and SRC PLDD at: https://mcdoc.boeblingen.de.
     * ibm.com/out/out.ViewDocument.php?documentid=1675
     *
     * The order of parameters is arranged so that Host Boot error log
     * is as close to SP as possible.
     *
     * @param[in]   i_sev           Log's severity. See errltypes.H for
     *                              available values
     * @param[in]   i_modId         The module (interface) where this log is
     *                              created from.
     * @param[in]   i_reasonCode    Bits 00-07: Component Id
     *                              Bits 08-15: Reason code
     * @param[in]   i_user1         64 bits of user data which are placed
     *                              in the primary SRC
     * @param[in]   i_user2         64 bits of user data which are placed
     *                              in the primary SRC
     * @return	None
     */
    ErrlEntry(const errlSeverity_t i_sev,
              const uint8_t i_modId,
              const uint16_t i_reasonCode,
              const uint64_t i_user1 = 0,
              const uint64_t i_user2 = 0);

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
    ~ErrlEntry();

    /**
     *  @brief Read the log's severity
     *  The severity of a log determines how severe the
     *  problem is perceived to be.  The severity is
     *  initially set by the parameter in the constructor
     *  and can be changed at any point thereafter.
     *
     *  @return Current Log Severity
     *
     */
    errlSeverity_t sev() const;

    /**
     *  @brief Set the log's severity
     *  The severity of a log determines how severe the
     *  problem is perceived to be.  The severity is
     *  initially set by the parameter in the constructor
     *  and can be changed at any point thereafter.
     *
     *  @return void
     *
     */
    void setSev(const errlSeverity_t i_sev);

    /**
     *  @brief Returns the log's reason code
     *
     *  @return uint16_t
     *
     */
    uint16_t reasonCode() const;

    /**
     *  @brief Returns the log's event type
     *
     *  @return errlEventType_t
     *
     */
    errlEventType_t eventType() const;

    /**
      *  @brief Set the log's event type
      *
      *  @return void
      *
      */
    void setEventType(const errlEventType_t i_eventType);

    /**
     *  @brief Returns the log's sub system
     *
     *  @return epubSubSystem_t
     *
     */
    epubSubSystem_t subSys() const;

   /**
     *  @brief Set the log's sub system
     *
     *  @return void
     *
     */
    void setSubSys(const epubSubSystem_t i_subSys);

    /**
     *  @brief Returns the log's SRC type
     *
     *  @return srcType_t
     *
     */
    srcType_t srcType() const;

   /**
     *  @brief Set the log's SRC type
     *
     *  @return void
     *
     */
    void setSrcType(const srcType_t i_srcType);

    /**
     *  @brief Returns the log's terminate state type
     *
     *  @return errlTermState_t
     *
     */
    errlTermState_t termState() const;

    /**
     *  @brief Set the log's Terminating state
     *
     *  @return void
     *
     */
    void setTermState(const errlTermState_t i_termState);

   /**
     * @brief Allows the caller to add a chunk of data in a log
     *
     * @param[in]   i_compId         Component Id of the caller
     * @param[in]   i_dataPtr        Pointer to FFDC data
     * @param[in]   i_ffdcLen        Length of the data in bytes
     * @param[in]   i_ffdcVer        A user supplied identifier which
     *                               classifies the data
     * @param[in]   i_ffdcSubSect    A user supplied sub section identifier
     *                               which classifies the data.  This in
     *                               conjunction with the version can be used
     *                               to decode the data.
     * @return Pointer to FFDC section if successfully added.
     *         NULL if fails
     */
    ErrlFFDC* addFFDC(const compId_t i_compId,
                 const void * i_dataPtr,
                 const uint32_t i_ffdcLen,
                 const uint8_t i_ffdcVer = 0,
                 const uint8_t i_ffdcSubSect = 0);

    /**
     * @brief Append more data to an FFDC section.
     *
     * @param[in]   i_ffdcSctnPtr    Pointer to FFDC section to add data to.
     *                               This pointer is returned when addFFDC
     *                               function is called earlier.
     * @param[in]   i_dataPtr        Points to data block to be added
     * @param[in]   i_dataLen        Length of data in bytes
     * @return void
     */
    void appendToFFDC(ErrlFFDC* i_ffdcSctnPtr,
                      const void *i_dataPtr,
                      const uint32_t i_dataLen);
private:

    /**
      * @brief   Disabled copy constructor and assignment operator
      */
     ErrlEntry(const ErrlEntry& i_right);
     ErrlEntry& operator=(const ErrlEntry& i_right);

    /**
     * @brief Add a data section to error log object
     *
     * @param[in]   i_sctn      Pointer to data section to be added
     *
     * @return void
     */
    void addSection(ErrlSctn* i_sctn);

    /**
     * @brief   Returns the unique Error Entry Id.  This ID is assigned to
     *          the entry when it's created.
     *          This is to be called by ErrlManager only.
     * @return  32 bit unsigned identifier
     */
    uint32_t logId() const;

    /**
     *  @brief Set the log's id
     *  This function is called by the ErrlManager to
     *  set this log's ID to a unique input number.
     *  This is to be called by ErrlManager only.
     *
     *  @return void
     */
    void setLogId(const uint32_t i_val);

    //@todo - Need to add serialization interfaces for ErrlSctn object.
    //        Serialization method (boost serialization?) is for HostBoot
    //        is currently not yet determined.
    //        Note: stream is currently not supported


#if 0

    //@todo - The interfaces in this block still need support in order
    // to have code written.


    //@todo: Need to set EPUB_Sub system based on highest
    // priority call out FRU
    /**
     *  @brief Add a hardware ( FRU ) callout
     *
     *  @param[in]  i_resourceId    The resource identifier for the part
     *  @param[in]  i_target        The hardware target
     *
     *  @return void
     */
    void addFruCallout(const target_t i_target,
                       const callOutPriority_t i_priority);


    //@todo: Need to set EPUB_Sub system based on highest
    // priority procedure call out
    /**
     *  @brief Add a procedure ( software ) callout
     *  Adds the given service procedure to the list
     *  of callouts for the log
     *
     *  @param[in]  i_priority      Priority of the callout
     *  @param[in]  i_procedure     Procedure identifier.
     *
     *  @return void
     */
    void addProcedureCallout(const epubProcedureId_t i_procedure,
                             const callOutPriority_t i_priority);

    /**
     *  @brief Collect component trace
     *  The given component's trace is collected ( if possible )
     *  and added to the log's data sections.  The amount of data
     *  added is the smallest of the log's available space (up to
     *  1024 bytes of trace) or the given input max.
     *
     *  @param[in]  i_Name          Component Name
     *  @param[in]  i_Max           Upper limit of trace to capture.
     *
     *  @return None
     */
    void CollectTrace(const char i_Name[],
                      const uint32_t i_Max = 0);

    /**
     *  @brief Adds a software section to the log which is
     *         mostly used as a stack call indicator
     *
     *  @param[in] i_cid        Component for which the section is being logged
     *  @param[in] i_returnCode User supplied return code.
     *  @param[in] i_fileId     User supplied file identifier
     *  @param[in] i_codeloc    User supplied code location ( line # )
     *  @param[in] i_objId      User supplied object identifier
     *
     *  @return Token which identifies the newly added section
     *          A negative token is considered to be invalid
     *
     *  @note   The section may be dropped if there is not enough
     *          room available to contain it
     *
     *
     */
    void addSwErr(const compId_t i_cid,
                  const uint32_t i_returnCode,
                  const uint16_t i_fileId,
                  const uint16_t i_codeLoc,
                  const uint32_t i_objId = 0);

#endif

private:

    // Data Members
    uint16_t iv_reasonCode;     // Component ID and reason code, 2 nibbles each
    errlSeverity_t iv_sev;      // Log severity
    errlEventType_t iv_eventType;   // Event type
    epubSubSystem_t iv_subSys;      // Sub system
    srcType_t iv_srcType;           // SRC type
    errlTermState_t iv_termState;   // Terminate state
    uint8_t iv_modId;               // Module ID
    uint64_t iv_user1;              // Optional user data 1
    uint64_t iv_user2;              // Optional user data 2
    uint32_t iv_logId;              // This log's unique ID

    // Sections in this log object
    std::vector<ErrlSctn*> iv_sections;

};

//-----------------------------------------------------------------------
// In-line functions
//-----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline errlSeverity_t ErrlEntry::sev() const
{
    return (iv_sev);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setSev(const errlSeverity_t i_sev)
{
    iv_sev = i_sev;
    return;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint16_t ErrlEntry::reasonCode() const
{
    return (iv_reasonCode);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline errlEventType_t ErrlEntry::eventType() const
{
    return (iv_eventType);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setEventType(const errlEventType_t i_eventType)
{
    iv_eventType = i_eventType;
    return;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline epubSubSystem_t ErrlEntry::subSys() const
{
    return (iv_subSys);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setSubSys(const epubSubSystem_t i_subSys)
{
    iv_subSys = i_subSys;
    return;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline srcType_t ErrlEntry::srcType() const
{
    return (iv_srcType);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setSrcType(const srcType_t i_srcType)
{
    iv_srcType = i_srcType;
    return;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline errlTermState_t ErrlEntry::termState() const
{
    return (iv_termState);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setTermState(const errlTermState_t i_termState)
{
    iv_termState = i_termState;
    return;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint32_t ErrlEntry::logId() const
{
    return (iv_logId);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setLogId(const uint32_t i_val)
{
    iv_logId = i_val;
    return;
}

} // End namespace

#endif //ERRLENTRY_H
