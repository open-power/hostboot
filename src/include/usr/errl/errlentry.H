//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errlentry.H $
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
/**
 * @page    errlog  Error Log
 *
 * @section Base Error Log
 *  See Host Boot Error Logging LLDD, Version 0.7  09/01/2011
 *
 * @section Adding User-Defined error blocks
 *
 *
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdint.h>
#include <vector>
#include <errl/hberrltypes.H>
#include <errl/errlsctn.H>
#include <errl/errlprvt.H>
#include <errl/errluh.H>
#include <errl/errlsrc.H>
#include <errl/errlud.H>
#include <hbotcompid.H>


namespace ERRORLOG
{

/*****************************************************************************/
// Forward class declarations
/*****************************************************************************/
class ErrlManager;




// In Sprint 6, the return from errl->addFFDC changed from
// ErrlFFDC* to ErrlUD*.  This typedef is for compatibility in
// case anybody previously stored the return from errl->addFFDC() as
// ErrlFFDC *.
typedef ErrlUD ErrlFFDC;

/**
 *  @brief      Host Boot Error log entry class.
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
     * @brief   ErrlEntry constructor. Builds an error log with info
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
     * @return  None
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
     * All logs not committed must be deleted to avoid a resource leak.
     * Committing an error log via ErrlManager will cause ErrlManager
     * to delete the log after saving it.
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
     *  See errl/errltypes.H
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
     *  @param[in]  i_sev Severity. See errl/errltypes.H
     *
     *  @return     void
     */
    void setSev(const errlSeverity_t i_sev);


    /**
     *  @brief Get reason code. See errl/errlreasoncodes.H
     *
     *  @return reason code
     */
    uint16_t reasonCode() const;

    /**
     *  @brief Set reason code
     *
     *  @param[in]  i_reasonCode   The reason code.  The upper byte
     *                             of a reason code is the component ID.
     *                             See errl/errlreasoncodes.H
     *
     *  @return     void
     */
    void setReasonCode( const uint16_t i_reasonCode );

    /**
     *  @brief Get module id.  See errl/errlreasoncodes.H
     *
     *  @return module id
     */
    uint8_t moduleId() const;



    /**
     *  @brief Set module id
     *
     *  @param[in]  i_moduleId  The module ID. See errl/errlreasoncodes.H
     *
     *  @return     void
     */
    void setModuleId( const uint8_t i_moduleId );


    /**
     *  @brief Get the unique platform log identifier (PLID) of the error log.
     *  In legacy FSP, you could have one platform log ID such that a
     *  of entry IDs (EIDs) related to a single PLID. So far in Hostboot,
     *  PLID == EID. As such, there is no setter in the ErrlEntry interface
     *  for EID. When flattened as PEL for export, EID will be set to PLID.
     *
     *  @return The platform log ID of the error log.
     */
    uint32_t plid() const;



    /**
     *  @brief Get the event type of the error log.
     *         See errl/errltypes.H
     *  @return errlEventType_t
     *
     */
    errlEventType_t eventType() const;

    /**
     *  @brief Set the log's event type
     *
     *  @param[in]  i_eventType  Event type. See errl/errltypes.H
     *
     *  @return void
     *
     */
    void setEventType(const errlEventType_t i_eventType);

    /**
     *  @brief Returns the log's sub system. See errl/errltypes.H
     *
     *  @return epubSubSystem_t
     *
     */
    epubSubSystem_t subSys() const;

   /**
     *  @brief Set the log's ePub sub system type.
     *
     *  @param[in]  i_subSys   Subsystem type. See errl/errltypes.H
     *
     *  @return void
     */
    void setSubSys(const epubSubSystem_t i_subSys);


    /**
     *  @brief Returns the log's SRC type. See errl/errltypes.H
     *
     *  @return srcType_t
     *
     */
    srcType_t srcType() const;

   /**
     *  @brief Set the log's SRC type
     *
     *  @param[in]  i_srcType   The SRC type for this error log. See
     *                          errl/errltypes.H
     *
     *  @return void
     */
    void setSrcType(const srcType_t i_srcType);

    /**
     *  @brief Returns the log's terminate state type. See
     *  errl/errltypes.H
     *
     *  @return errlTermState_t
     *
     */
    errlTermState_t termState() const;

    /**
     *  @brief Set the log's Terminating state
     *
     *  @param[in] i_termState  See errl/errltypes.H
     *
     *  @return void
     *
     */
    void setTermState(const errlTermState_t i_termState);



   /**
     * @brief Allows the caller to add a chunk of FFDC data in a log
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
     *
     * @return Pointer to FFDC section if successfully added.
     *         NULL if fails
     */
    ErrlUD * addFFDC(const compId_t i_compId,
                     const void * i_dataPtr,
                     const uint32_t i_ffdcLen,
                     const uint8_t i_ffdcVer = 0,
                     const uint8_t i_ffdcSubSect = 0);

    /**
     * @brief Append more data to an FFDC section.
     *
     * @param[in]   i_pErrlUD        Pointer to the user-define section
     *                               to add data to.  This pointer is
     *                               returned when addFFDC
     *                               function is called earlier.
     * @param[in]   i_dataPtr        Points to data block to be added
     * @param[in]   i_dataLen        Length of data in bytes
     *
     * @return void
     */
    void appendToFFDC( ErrlUD * i_pErrlUD,
                       const void *i_dataPtr,
                       const uint32_t i_dataLen);


    /**
     *  @brief Collect component trace
     *  The trace buffer named is collected and added to the error
     *  log.  The amount of traces is controlled by the i_max parameter.
     *  When zero, or left to default, the full trace buffer is copied.
     *  Otherwise, i_max size must be big enough to hold a trace buffer
     *  header (40 bytes) plus some trace data. For example, a trace
     *  entry with n bytes of data is n+28 bytes in size.
     *
     *  Note that component names given in hbotcompid.H do not necessarily
     *  map to the names of trace buffers created by that component.
     *  Trace buffer names are case insensitive.
     *
     *  @param[in]  i_name          Trace buffer name
     *  @param[in]  i_max           Size of trace to capture.
     *
     *  @return A Boolean indication of success.  False likely means
     *  the trace buffer name given is not found. However, check the ERRL
     *  trace buffer for the cause of the failure.
     */
    bool collectTrace(const char i_name[],
                      const uint64_t i_max = 0);





private:
    /**
     * @brief The ErrlManager will call here to ask the
     * ErrlEntry to assign the time of commit, and to assign
     * the commiter's comp ID.
     * The ErrlManager is the primary user of this call.
     *
     */
    void commit( compId_t i_commiterComp );



    /**
     * @brief Compute the flattened size of an error log.  It is typical
     * to call this function for the size of buffer required, then
     * allocate a buffer, then call flatten().
     * The ErrlManager is the primary user of this call.
     *
     * @return Size in bytes of the flattened data.
     */
    uint64_t flattenedSize();


    /**
     * @brief Flatten the data to caller's buffer. The resulting flat
     * data will be in PEL (platform event log) format.
     * The ErrlManager is the primary user of this call.
     *
     * @param[in,out]  o_buffer   Points to data block to be filled
     * @param[in]      i_cbBuffer  Count of bytes in buffer supplied
     *
     * @return  Count of bytes copied to caller's
     *          buffer or else zero if it does not fit.
     */
    uint64_t flatten( void * o_buffer, const uint64_t i_cbBuffer );


    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlEntry(const ErrlEntry& i_right);
    ErrlEntry& operator=(const ErrlEntry& i_right);



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
    ErrlPrvt        iv_Private;    // private header object
    ErrlUH          iv_User;       // user header object
    ErrlSrc         iv_Src;        // primary SRC section
    std::vector<ErrlUD*> iv_SectionVector;  // list of user defined sections
    std::vector<uint64_t> iv_btAddrs;       // list of addresses for the backtrace

    // TODO need to interpret term state and terminate accordingly.
    // TODO termstate is presently not being flattend into PEL
    errlTermState_t iv_termState;

};





//-----------------------------------------------------------------------
// In-line functions
//-----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

inline uint32_t ErrlEntry::plid() const
{
    return iv_Private.iv_plid;
}



////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint8_t ErrlEntry::moduleId() const
{
    return iv_Src.iv_modId;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setModuleId( const uint8_t i_moduleId )
{
    iv_Src.iv_modId = i_moduleId;
    return;
}




////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline errlTermState_t ErrlEntry::termState() const
{
    return iv_termState;
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
inline void ErrlEntry::setReasonCode( const uint16_t i_reasonCode )
{
    iv_Src.iv_reasonCode = i_reasonCode;
    return;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint16_t ErrlEntry::reasonCode() const
{
    return iv_Src.iv_reasonCode;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline srcType_t ErrlEntry::srcType() const
{
    return iv_Src.iv_srcType;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setSrcType(const srcType_t i_srcType)
{
    iv_Src.iv_srcType = i_srcType;
    return;
}

} // End namespace


typedef ERRORLOG::ErrlEntry* errlHndl_t;


#endif //ERRLENTRY_H
