/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/errl/errlentry.H $                            */
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
#include <targeting/common/target.H>
#include <attributeenums.H>


namespace ERRORLOG
{
class ErrlEntry;
}
typedef ERRORLOG::ErrlEntry* errlHndl_t;

#include <hwas/common/hwasCallout.H>

namespace ERRORLOG
{

/*****************************************************************************/
// Forward class declarations
/*****************************************************************************/
class ErrlManager;
class ErrlUserDetailsBackTrace;

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
     * The backtrace is captured as user detail data. Use removeBackTrace to
     * remove
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
    errlSeverity_t sev() const { return iv_User.iv_severity; }


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
    void setSev(const errlSeverity_t i_sev)
    {
        iv_User.iv_severity = i_sev;
    }


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
     *  @brief Get the unique error log identifier (EID) of the error log.
     *
     *  @return The error log ID of the error log.
     */
    uint32_t eid() const;

    /**
     *  @brief Get the platform log identifier (PLID) of the error log.
     *  In legacy FSP, you could have one platform log ID such that a series
     *  of entry IDs (EIDs) related to a single PLID.
     *
     *  @return The platform log ID of the error log.
     */
    uint32_t plid() const;

    /**
     *  @brief Set the platform log id for this error log.
     *
     *  @return The platform log ID of the error log.
     */
    void plid( uint32_t i_plid);

    /**
     *  @brief Get the event type of the error log.
     *         See errl/errltypes.H
     *  @return errlEventType_t
     *
     */
    errlEventType_t eventType() const { return iv_User.iv_etype; }

    /**
     *  @brief Set the log's event type
     *
     *  @param[in]  i_eventType  Event type. See errl/errltypes.H
     *
     *  @return void
     *
     */
    void setEventType(const errlEventType_t i_eventType)
    {
        iv_User.iv_etype = i_eventType;
    }

    /**
     *  @brief Returns the log's sub system. See errl/errltypes.H
     *
     *  @return epubSubSystem_t
     *
     */
    epubSubSystem_t subSys() const { return iv_User.iv_ssid; }

   /**
     *  @brief Set the log's ePub sub system type.
     *
     *  @param[in]  i_subSys   Subsystem type. See errl/errltypes.H
     *
     *  @return void
     */
    void setSubSys(const epubSubSystem_t i_subSys)
    {
        // hb has ssid defined in two places
        iv_User.iv_ssid = i_subSys;
        iv_Src.iv_ssid  = i_subSys;
    }


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
     * @brief Helper function to determine if log is a terminating error
     *
     *
     * @return  returns true if error will result in system termination.
     */
    bool isTerminateLog() const;

    /**
     *  @brief Add data to the iv_Src user data words.
     *
     *  @param[in] i_data - information to add to the user data word 1.
     *
     *  @return void
     *
     */
    void addUserData1( const uint64_t i_data );
    /**
     *  @brief Add data to the iv_Src user data words.
     *
     *  @param[in] i_data - information to add to the user data word 2.
     *
     *  @return void
     *
     */
    void addUserData2( const uint64_t i_data );

    /**
     *  @brief set Deconfigure and GARD bits in Hex Word 5
     *
     *  @return void
     *
     */
    void setDeconfigBit();
    void setGardBit();

    /**
     *  @brief Return iv_Src user data words.
     *
     *  @return data1 word from SRC
     *
     */
    uint64_t getUserData1() const;

    /**
     *  @brief Return iv_Src user data words.
     *
     *  @return data2 word from SRC
     *
     */
    uint64_t getUserData2() const;

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
     * @param[in]   i_merge          A boolean value (defaults to false if
     *                               parameter is not specified) to indicate
     *                               whether this buffer is merged with the
     *                               previous section iff it matches.
     *
     * @return Pointer to FFDC section if successfully added.
     *         NULL if fails
     */
    ErrlUD * addFFDC(const compId_t i_compId,
                     const void * i_dataPtr,
                     const uint32_t i_ffdcLen,
                     const uint8_t i_ffdcVer,
                     const uint8_t i_ffdcSubSect,
                     bool i_merge = false);

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

    /**
     *  @brief Remove the back trace user detail data
     *  When an error log is constructed, the back trace is automatically
     *  captured. This function removes the backtrace. This should be used when
     *  a caller knows that the backtrace is of no use and wants to limit the
     *  size of the error log.
     */
    void removeBackTrace();

    /**
     *  @brief Add a clock callout.
     *  The i_target is used to identify the actual clock to callout because
     *  some systems have multiple clocks of a given type. This target is
     *  usually a chip target, but can possibly be a unit, depending on
     *  the clock type.
     *
     *  @param[in]  i_target        The hardware target fed by the clock
     *  @param[in]  i_clockType     The hardware clock type
     *  @param[in]  i_priority      Priority of the callout
     *
     *  @return void
     */
    void addClockCallout(const TARGETING::Target *i_target,
                       const HWAS::clockTypeEnum i_clockType,
                       const HWAS::callOutPriority i_priority);

    /**
     *  @brief Add a bus callout
     *
     *  @param[in]  i_target1       The hardware bus endpoint target1
     *  @param[in]  i_target2       The hardware bus endpoint target2
     *  @param[in]  i_busType       The hardware bus type
     *  @param[in]  i_priority      Priority of the callout
     *
     *  @return void
     */
    void addBusCallout(const TARGETING::Target *i_target1,
                       const TARGETING::Target *i_target2,
                       const HWAS::busTypeEnum i_busType,
                       const HWAS::callOutPriority i_priority);

    /**
     *  @brief Add a hardware callout
     *
     *  @param[in]  i_target        The hardware target
     *  @param[in]  i_priority      Priority of the callout
     *  @param [in] i_deconfigState Enum indicating whether the failing part
     *               should be deconfigured.
     *  @param [in] i_gardErrorType to indicate what type of failure occured
     *
     *  @return void
     */
    void addHwCallout(const TARGETING::Target *i_target,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::DeconfigEnum i_deconfigState,
                        const HWAS::GARD_ErrorType i_gardErrorType);

    /**
     *  @brief Add a procedure ( software ) callout
     *  Adds the given service procedure to the list
     *  of callouts for the log
     *
     *  @param[in]  i_procedure     Procedure identifier.
     *  @param[in]  i_priority      Priority of the callout
     *
     *  @return void
     */
    void addProcedureCallout(const HWAS::epubProcedureID i_procedure,
                             const HWAS::callOutPriority i_priority);

    /**
     * @brief  Import flatened error log
     *
     * @param[in] i_buffer, pointer to flat data
     * @param[in] i_len length of flat data
     * @return Status  0==SUCCESS
     */
    uint64_t unflatten( const void * i_buffer, uint64_t i_len);

private:

     /**
     *  @brief Set the failing subsystem ID in the error log
     *         based on the highest priority callout.
     *
     */
    void setSubSystemIdBasedOnCallouts();

    /**
     *  @brief maps the target type to corresponding subsystem ID
     *
     *  @param[in]  i_target   Target Type.
     *
     *  @return     subsystem ID
     */
    epubSubSystem_t getSubSystem( TARGETING::TYPE );

    /**
     *  @brief maps the procedure to a corresponding subsystem ID
     *
     *  @param[in]  i_procedureId   procedure.
     *
     *  @return     subsystem ID
     */
    epubSubSystem_t getSubSystem( HWAS::epubProcedureID i_procedureId );

#if 0
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


    /**
     * @brief The ErrlManager will call here to ask the
     * ErrlEntry to assign the time of commit, and to assign
     * the commiter's comp ID.
     * The ErrlManager is the primary user of this call.
     *
     */
    void commit( compId_t i_commiterComp );


    /**
     * @brief The ErrlManager will call here to ask the
     * ErrlEntry to handle deconfigure and GARD callouts
     * The ErrlManager is the primary user of this call.
     *
     */
    void processCallout();


    /**
     * @brief The ErrlManager will call here to ask the
     * ErrlEntry to handle deferred deconfigure callouts
     * The ErrlManager is the primary user of this call.
     *
     */
    void deferredDeconfigure();


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
     * @brief sort compare function, to be used when flattening an
     * error log
     *
     * @param[in]      i_ud1 - first user-defined section to compare
     * @param[in]      i_ud2 - second user-defined section to compare
     *
     * @return  true if i_ud1 should be first, false otherwise
     */
    static bool udSort(ErrlUD *i_ud1, ErrlUD *i_ud2);

    /**
     * @brief Flatten the data to caller's buffer. The resulting flat
     * data will be in PEL (platform event log) format.
     * The ErrlManager is the primary user of this call.
     *
     * @param[in,out]  o_buffer   Points to data block to be filled
     * @param[in]      i_cbBuffer Count of bytes in buffer supplied
     * @param[in]      i_truncate true: truncate the data
     *                              false: error if buffer too small
     *                  NOTE: PH, UH and PS MUST fit
     *
     * @return  Count of bytes copied to caller's
     *          buffer or else zero if it does not fit and i_truncate==false.
     */
    uint64_t flatten( void * o_buffer, const uint64_t i_cbBuffer,
            const bool i_truncate = false);

    /**
     * @brief Called by commit(), this fucntion creates a
     * user details section which contains the Hostboot
     * build ID and adds this to the current error log being
     * processed.
     */
    void addHbBuildId();


    /**
      * @brief   Disabled copy constructor and assignment operator
      */
    ErrlEntry(const ErrlEntry& i_right);
    ErrlEntry& operator=(const ErrlEntry& i_right);

private:
    // Data Members
    ErrlPrvt        iv_Private;    // private header object
    ErrlUH          iv_User;       // user header object
    ErrlSrc         iv_Src;        // primary SRC section
    std::vector<ErrlUD*> iv_SectionVector;  // list of user defined sections
    std::vector<uint64_t> iv_btAddrs;       // list of addresses for the backtrace
    ErrlUserDetailsBackTrace * iv_pBackTrace; // Pointer to back trace

    // termstate will not be flattend into PEL, its only used by
    // hostboot.
    errlTermState_t iv_termState;

};





//-----------------------------------------------------------------------
// In-line functions
//-----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

inline uint32_t ErrlEntry::eid() const
{
    return iv_Private.iv_eid;
}

inline uint32_t ErrlEntry::plid() const
{
    return iv_Private.iv_plid;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::plid( uint32_t i_plid)
{
    iv_Private.iv_plid = i_plid;
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
inline void ErrlEntry::addUserData1( const uint64_t i_data )
{
    iv_Src.iv_user1 = i_data;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::addUserData2( const uint64_t i_data )
{
    iv_Src.iv_user2 = i_data;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline void ErrlEntry::setDeconfigBit()
{
    iv_Src.iv_deconfig = true;
}
inline void ErrlEntry::setGardBit()
{
    iv_Src.iv_gard = true;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint64_t ErrlEntry::getUserData1() const
{
    return iv_Src.iv_user1;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
inline uint64_t ErrlEntry::getUserData2() const
{
    return iv_Src.iv_user2;
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


/**
 * Retrieve the RC inside an error log, or return zero if the log is NULL
 */
#define ERRL_GETRC_SAFE(errhdl) (errhdl == NULL ? 0 : errhdl->reasonCode())

/**
 * Retrieve the PLID inside an error log, or return zero if the log is NULL
 */
#define ERRL_GETPLID_SAFE(errhdl) (errhdl == NULL ? 0 : errhdl->plid())

/**
 * Retrieve the EID inside an error log, or return zero if the log is NULL
 */
#define ERRL_GETEID_SAFE(errhdl) (errhdl == NULL ? 0 : errhdl->eid())

#endif //ERRLENTRY_H
