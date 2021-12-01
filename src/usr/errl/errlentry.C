/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlentry.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
/**
 *  @file errlentry.C
 *
 *  @brief Implementation of ErrlEntry class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <hbotcompid.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludbacktrace.H>
#include <errl/errludcallout.H>
#include <errl/errlreasoncodes.H>
#include <errl/errludstring.H>
#include <errl/errluserdetails.H>
#include <errl/errludattribute.H>
#include <errl/errludstate.H>
#include <errl/errli2c.H>
#include <trace/interface.H>

#include "../trace/entry.H"
#include <util/align.H>

#include <arch/ppc.H>
#include <hwas/common/deconfigGard.H>
#include <targeting/targplatutil.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/targetservice.H>
#include <initservice/initserviceif.H>
#include <attributeenums.H>
#include "errlentry_consts.H"
#include <util/misc.H>
#include <limits.h>

#include <util/utillidmgr.H>

// Hostboot Image ID string
extern char hbi_ImageId;

using namespace ERRORLOG;
using namespace HWAS;
using namespace TARGETING;

namespace ERRORLOG
{
// Initialize static variable
uint32_t ErrlEntry::iv_maxSize = 0;

#ifdef CONFIG_PLDM
// 16K for PLDM supported error logging
constexpr uint32_t DEFAULT_MAX_LOG_SIZE = 16*KILOBYTE;
#else
// 4K for all other types
constexpr uint32_t DEFAULT_MAX_LOG_SIZE = 4*KILOBYTE;
#endif

// Trace definition
trace_desc_t* g_trac_errl = NULL;
TRAC_INIT(&g_trac_errl, "ERRL", KILOBYTE, TRACE::BUFFER_SLOW);

// std::map to trace severity in trace
// NOTE: must be kept in sync with enum definition in hberrltypes.H
std::map<uint8_t, const char *> errl_sev_str_map {
    {ERRL_SEV_INFORMATIONAL,     "INFORMATIONAL"},
    {ERRL_SEV_RECOVERED,         "RECOVERED"},
    {ERRL_SEV_PREDICTIVE,        "PREDICTIVE"},
    {ERRL_SEV_UNRECOVERABLE,     "UNRECOVERABLE"},
    {ERRL_SEV_UNRECOVERABLE1,    "UNRECOVERABLE1"},
    {ERRL_SEV_CRITICAL_SYS_TERM, "CRITICAL_SYS_TERM"},
    {ERRL_SEV_UNKNOWN,           "UNKNOWN"},
};

#ifdef CONFIG_BUILD_FULL_PEL
// This list creates a mapping from epubProcedureID to the hostboot isolation procedure number HBxxxxx. Due to character
// limitations the isolation procedure must be 7 characters plus null terminator. The isolation procedure codes are hex
// characters to allow the maximum possible number of codes. These codes have meaning to customers where the customer
// can lookup the code and see a set of instructions to manually recover their system.
//
// Historically, this mapping between epubProcedureID and isolation procedure code was handled by FSP/HWSV. Hence the
// comments showing how the HBxxxxx codes map to FSPSPxx. For P10 FSP based systems, FSPSPxx codes will continue to be
// used but for eBMC systems these codes will be used instead. If an existing epubProcedureID needs to be added to this
// list then it should be inserted in the correct sorted order with respect to epubProcedureID and be assigned its
// corresponding hex value as its HBxxxxx code. This way, for all P10 systems, we can continue to leverage the existing
// documentation for those epubProcedureIDs which was already established by its corresponding FSPSPxx code.
// For example, EPUB_PRC_TOD_PROB is 0x07. If hostboot wanted to start using that, then it would just be inserted after
// EPUB_PRC_PHYP_CODE and assigned HB00007.

// Should a new epubProcedureID be added then it should be placed in sorted order in the list below with its
// corresponding HBxxxxx code. FSPSPxx codes range up to 99 (decimal) so any new code would need to be after that.
// This list is to remain in sorted order so that it can be binary searched when looking up the HBxxxxx
// code for a given epubProcedureID.

struct epubProcedureToIsolationProcedure_t
{
    epubProcedureID epub_procedure_id;
    char isolationProcedure[PEL_PART_NUM_SIZE];
};
static constexpr std::array<epubProcedureToIsolationProcedure_t, 25> EPUB_TO_ISOLATION_PROCEDURE =
{
    epubProcedureToIsolationProcedure_t
    { EPUB_PRC_NONE                   , "       "},
    { EPUB_PRC_FIND_DECONFIGURED_PART , "HB00001"}, // FSPSP01
    { EPUB_PRC_SP_CODE                , "HB00004"}, // FSPSP04
    { EPUB_PRC_PHYP_CODE              , "HB00005"}, // FSPSP05
    { EPUB_PRC_ALL_PROCS              , "HB00008"}, // FSPSP08
    { EPUB_PRC_ALL_MEMCRDS            , "HB00009"}, // FSPSP09
    { EPUB_PRC_INVALID_PART           , "HB0000A"}, // FSPSP10
    { EPUB_PRC_LVL_SUPP               , "HB00010"}, // FSPSP16
    { EPUB_PRC_SUE_PREVERROR          , "HB00011"}, // FSPSP17
    { EPUB_PRC_PROCPATH               , "HB00010"}, // map to EPUB_PRC_LVL_SUPP
    { EPUB_PRC_NO_VPD_FOR_FRU         , "HB00010"}, // map to EPUB_PRC_LVL_SUPP
    { EPUB_PRC_MEMORY_PLUGGING_ERROR  , "HB00022"}, // FSPSP34
    { EPUB_PRC_FSI_PATH               , "HB0002D"}, // FSPSP45
    { EPUB_PRC_PROC_AB_BUS            , "HB00037"}, // map to EPUB_PRC_EIBUS_ERROR
    { EPUB_PRC_PROC_XYZ_BUS           , "HB00037"}, // map to EPUB_PRC_EIBUS_ERROR
    { EPUB_PRC_MEMBUS_ERROR           , "HB00037"}, // map to EPUB_PRC_EIBUS_ERROR
    { EPUB_PRC_EIBUS_ERROR            , "HB00037"}, // FSPSP55
    { EPUB_PRC_POWER_ERROR            , "HB0003F"}, // FSPSP63
    { EPUB_PRC_PERFORMANCE_DEGRADED   , "HB0004D"}, // FSPSP77
    { EPUB_PRC_MEMORY_UE              , "HB0004F"}, // FSPSP79
    { EPUB_PRC_HB_CODE                , "HB00055"}, // FSPSP85
    { EPUB_PRC_TOD_CLOCK_ERR          , "HB00056"}, // FSPSP86
    { EPUB_PRC_COOLING_SYSTEM_ERR     , "HB0005C"}, // FSPSP92
    { EPUB_PRC_FW_VERIFICATION_ERR    , "HB0005D"}, // FSPSP93
    { EPUB_PRC_SBE_CODE               , "HB00062"}, // FSPSP98
};

template<typename Iterator>
static constexpr bool is_sorted(const Iterator begin, const Iterator end)
{
    if ((begin == end) || (begin + 1 == end))
    {
        return true;
    }
    else if (begin->epub_procedure_id > (begin+1)->epub_procedure_id)
    {
        return false;
    }
    return is_sorted(begin+1, end);
}
static_assert(is_sorted(EPUB_TO_ISOLATION_PROCEDURE.cbegin(), EPUB_TO_ISOLATION_PROCEDURE.cend()),
              "EPUB_TO_ISOLATION_PROCEDURE must be in sorted order with respect to epubProcedureID");
#endif
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlEntry::ErrlEntry(const errlSeverity_t i_sev,
                     const uint8_t i_modId,
                     const uint16_t i_reasonCode,
                     const uint64_t i_user1,
                     const uint64_t i_user2,
                     const bool i_hbSwError,
                     const bool i_hbDump ) :
    iv_Private( static_cast<compId_t>(i_reasonCode & 0xFF00)),
    iv_User( i_sev ),
    // The SRC_ERR_INFO becomes part of the SRC; example, B1 in SRC B180xxxx
    // iv_Src assigns the epubSubSystem_t; example, 80 in SRC B180xxxx
    iv_Src( SRC_ERR_INFO, i_modId, i_reasonCode, i_user1, i_user2 ),
    iv_ED( ),
    iv_termState(TERM_STATE_UNKNOWN),
    iv_sevFinal(false),
    iv_skipProcessingLog(true),
    iv_skipShowingLog(true),
    iv_doHbDump(i_hbDump)
{
    #ifdef CONFIG_ERRL_ENTRY_TRACE
    TRACFCOMP( g_trac_errl, ERR_MRK"Error created : PLID=%.8X, EID=%.8X, RC=%.4X, Mod=%.2X, Userdata=%.16llX %.16llX, Sev=%s", plid(), eid(), i_reasonCode, i_modId, i_user1, i_user2, errl_sev_str_map.at(i_sev) );
    #else
    TRACDCOMP( g_trac_errl, ERR_MRK"Error created : PLID=%.8X, EID=%.8X, RC=%.4X, Mod=%.2X, Userdata=%.16llX %.16llX, Sev=%s", plid(), eid(), i_reasonCode, i_modId, i_user1, i_user2, errl_sev_str_map.at(i_sev) );
    #endif
    // Collect the Backtrace and add it to the error log
    iv_pBackTrace = new ErrlUserDetailsBackTrace();

#ifndef __HOSTBOOT_RUNTIME
    // Add the istep data to the vector of sections for this error log
    ErrlUserDetailsSysState l_UserDetailsSysState;

    l_UserDetailsSysState.addToLog( this );
#endif

    // Automatically add a software callout if asked
    if( i_hbSwError )
    {
        addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH );
    }
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlEntry::~ErrlEntry()
{
    // Trace a delete/destruction on an uncommitted log
    if (iv_Private.iv_committed == 0)
    {
        #ifdef CONFIG_ERRL_ENTRY_TRACE
        TRACFCOMP( g_trac_errl, ERR_MRK"Error deleted without commit : PLID=%.8X, EID=%.8X", plid(), eid());
        #else
        TRACDCOMP( g_trac_errl, ERR_MRK"Error deleted without commit : PLID=%.8X, EID=%.8X", plid(), eid());
        #endif
    }

    // Free memory of all sections
    for (std::vector<ErrlUD*>::const_iterator l_itr = iv_SectionVector.begin();
         l_itr != iv_SectionVector.end(); ++l_itr)
    {
        delete (*l_itr);
    }

    delete iv_pBackTrace;
    iv_pBackTrace = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// add a new UD section to the list of optional sections

ErrlUD * ErrlEntry::addFFDC(const compId_t i_compId,
             const void * i_dataPtr,
             const uint32_t i_ffdcLen,
             const uint8_t i_ffdcVer,
             const uint8_t i_ffdcSubSect,
             bool i_merge)
{
    ErrlUD * l_ffdcSection = NULL;

    if ( (i_dataPtr != NULL) && (i_ffdcLen != 0) )
    {
        TRACDCOMP( g_trac_errl, INFO_MRK"addFFDC(): %x %d %d - %s merge",
                      i_compId, i_ffdcVer,
                      i_ffdcSubSect, i_merge == true ? "DO" : "NO" );

        // if we're to try to merge, AND there's at least 1 section
        if ((i_merge) && (iv_SectionVector.size() > 0))
        {   // look at the last one to see if it's a match or not.
            // this is done to preserve the order of the errlog - we
            // only merge like sections if they are being put in at the
            // 'same time'.
            ErrlUD *pErrlUD = iv_SectionVector.back();

            if ((i_compId       == pErrlUD->iv_header.iv_compId) &&
                (i_ffdcVer      == pErrlUD->iv_header.iv_ver) &&
                (i_ffdcSubSect  == pErrlUD->iv_header.iv_sst))
            {
                TRACDCOMP( g_trac_errl, INFO_MRK"appending to matched %p",
                            pErrlUD);
                appendToFFDC(pErrlUD, i_dataPtr, i_ffdcLen);
                l_ffdcSection = pErrlUD;
            }
        } // i_merge && >0 section

        // i_merge == false, or it was true but we didn't find a match
        if (l_ffdcSection == NULL)
        {
            // Create a user-defined section.
            l_ffdcSection = new ErrlUD(  i_dataPtr,
                                         i_ffdcLen,
                                         i_compId,
                                         i_ffdcVer,
                                         i_ffdcSubSect );

            // Add to the vector of sections for this error log.
            iv_SectionVector.push_back( l_ffdcSection );
        }
    }
    else
    {
        TRACFCOMP( g_trac_errl,
        ERR_MRK"addFFDC(): Invalid FFDC data pointer or size, no add");
    }

    return l_ffdcSection;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void ErrlEntry::appendToFFDC(ErrlUD * i_pErrlUD,
                  const void *i_dataPtr,
                  const uint32_t i_dataLen)
{
    uint64_t l_rc;
    TRACDCOMP( g_trac_errl, ENTER_MRK"appendToFFDC(%p, %p, %d)",
                i_pErrlUD, i_dataPtr, i_dataLen);

    l_rc = i_pErrlUD->addData( i_dataPtr, i_dataLen );
    if( 0 == l_rc )
    {
        TRACFCOMP( g_trac_errl, ERR_MRK"ErrlEntry::appendToFFDC() rets zero" );
    }
    return;
}

///////////////////////////////////////////////////////////////////////////////
// Return a Boolean indication of success.

bool ErrlEntry::collectTrace(const char i_name[], const uint64_t i_max)
{
    bool l_rc = false;  // assume a problem.
    char * l_pBuffer = NULL;
    uint64_t l_cbOutput = 0;
    uint64_t l_cbBuffer = 0;

    do
    {
        // By passing nil arguments 2 and 3, obtain the size of the buffer.
        // Besides getting buffer size, it validates i_name.
        uint64_t l_cbFull = TRACE::getBuffer( i_name, NULL,0 );
        if( 0 == l_cbFull )
        {
            // Problem, likely unknown trace buffer name.
            TRACFCOMP( g_trac_errl,
                ERR_MRK"ErrlEntry::collectTrace(): getBuffer(%s) rets zero.",i_name);
            break;
        }

        if(( 0 == i_max ) || ( i_max >= l_cbFull ))
        {
            // Full trace buffer desired
            l_cbBuffer = l_cbFull;
        }
        else
        {
            // Partial buffer desired
            l_cbBuffer = i_max;
        }

        // allocate the buffer
        l_pBuffer = new char[ l_cbBuffer ];

        // Get the data into the buffer.
        l_cbOutput = TRACE::getBuffer( i_name, l_pBuffer, l_cbBuffer );

        if( 0 == l_cbOutput )
        {
            // Problem.
            TRACFCOMP( g_trac_errl,
                ERR_MRK"ErrlEntry::collectTrace(): getBuffer(%s,%ld) rets zero.",
                i_name,
                l_cbBuffer );
            break;
        }

        // Save the trace buffer as a UD section on this.
        ErrlUD * l_udSection = new ErrlUD( l_pBuffer,
                                           l_cbOutput,
                                           FIPS_ERRL_COMP_ID,
                                           FIPS_ERRL_UDV_DEFAULT_VER_1,
                                           FIPS_ERRL_UDT_HB_TRACE );

        // Add the trace section to the vector of sections
        // for this error log.
        iv_SectionVector.push_back( l_udSection );

        l_rc = true;
    }
    while(0);

    delete[] l_pBuffer;

    return l_rc;
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::removeBackTrace()
{
    delete iv_pBackTrace;
    iv_pBackTrace = NULL;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
/*
 * @brief  Safely retrieves the EntityPath for the target or the SENTINEL
 *         pointer if appropriate
 * @param[in]  i_target  Target to evaluate
 * @param[out]  o_ePath  Pointer to new EntityPath if applicable, if this
 *     comes back non-NULL, caller must delete the memory
 * @param[out]  o_dataPtr  Pointer to target data
 * @param[out]  o_dataSize  Size of target data
 */
void getTargData( const TARGETING::Target *i_target,
                  TARGETING::EntityPath*& o_ePath,
                  const void*& o_dataPtr,
                  uint32_t& o_dataSize )
{
    o_ePath = nullptr;
    o_dataPtr = nullptr;
    o_dataSize = 0;
    if (i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        o_dataSize = sizeof(HWAS::TARGET_IS_SENTINEL);
        o_dataPtr = &HWAS::TARGET_IS_SENTINEL;
    }
    else
    {   // we got a non MASTER_SENTINEL target, therefore the targeting
        // module is loaded, therefore we can make this call.
        o_ePath = new TARGETING::EntityPath;
        *o_ePath = i_target->getAttr<TARGETING::ATTR_PHYS_PATH>();
        // size is total EntityPath size minus unused path elements
        o_dataSize = sizeof(*o_ePath) -
          (TARGETING::EntityPath::MAX_PATH_ELEMENTS - o_ePath->size()) *
          sizeof(TARGETING::EntityPath::PathElement);
        o_dataPtr = o_ePath;
    }
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addClockCallout(const TARGETING::Target *i_target,
                        const HWAS::clockTypeEnum i_clockType,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::DeconfigEnum i_deconfigState,
                        const HWAS::GARD_ErrorType i_gardErrorType)
{
    TRACFCOMP(g_trac_errl, ENTER_MRK"addClockCallout(%p, %d, 0x%x)",
                i_target, i_clockType, i_priority);

    const void* pData = nullptr;
    uint32_t size = 0;
    TARGETING::EntityPath* ep = nullptr;
    getTargData( i_target, ep, pData, size );

    ErrlUserDetailsCallout( pData, size, i_clockType,
            i_priority, i_deconfigState, i_gardErrorType).addToLog(this);

    if( ep )
    {
        delete ep;
    }
} // addClockCallout


void ErrlEntry::addSensorCallout(const uint32_t i_sensorID,
                            const HWAS::sensorTypeEnum i_sensorType,
                            const HWAS::callOutPriority i_priority)
{
    TRACFCOMP(g_trac_errl, ENTER_MRK"addSensorCallout(0x%X, %d, 0x%x)",
                i_sensorID, i_sensorType, i_priority);

    ErrlUserDetailsCallout(i_sensorID, i_sensorType, i_priority).addToLog(this);
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addPartCallout(const TARGETING::Target *i_target,
                        const HWAS::partTypeEnum i_partType,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::DeconfigEnum i_deconfigState,
                        const HWAS::GARD_ErrorType i_gardErrorType)
{
    TRACFCOMP(g_trac_errl, ENTER_MRK"addPartCallout(%p, %d, 0x%x, %d, 0x%x)",
                i_target, i_partType, i_priority,
                i_deconfigState, i_gardErrorType);

    const void* pData = nullptr;
    uint32_t size = 0;
    TARGETING::EntityPath* ep = nullptr;
    getTargData( i_target, ep, pData, size );

    ErrlUserDetailsCallout( pData, size, i_partType,
            i_priority, i_deconfigState, i_gardErrorType).addToLog(this);

    if( ep )
    {
        delete ep;
    }
} // addPartCallout

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addBusCallout(const TARGETING::Target *i_target_endp1,
                        const TARGETING::Target *i_target_endp2,
                        const HWAS::busTypeEnum i_busType,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::CalloutFlag_t i_flag)
{
    TRACFCOMP(g_trac_errl, ENTER_MRK"addBusCallout(%p, %p, %d, 0x%x)",
                i_target_endp1, i_target_endp2, i_busType, i_priority);

    const void* pData1 = nullptr;
    uint32_t size1 = 0;
    TARGETING::EntityPath* ep1 = nullptr;
    getTargData( i_target_endp1, ep1, pData1, size1 );

    const void* pData2 = nullptr;
    uint32_t size2 = 0;
    TARGETING::EntityPath* ep2 = nullptr;
    getTargData( i_target_endp2, ep2, pData2, size2 );


    ErrlUserDetailsCallout( pData1, size1, pData2, size2, i_busType,
                            i_priority, i_flag).addToLog(this);

    if( ep1 )
    {
        delete ep1;
    }
    if( ep2 )
    {
        delete ep2;
    }
} // addBusCallout

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addBusCallout(const TARGETING::EntityPath & i_target_endp1,
                              const TARGETING::EntityPath & i_target_endp2,
                              const HWAS::busTypeEnum i_busType,
                              const HWAS::callOutPriority i_priority,
                              const HWAS::CalloutFlag_t i_flag)
{
    char * l_target_endp1_path_str = nullptr;
    char * l_target_endp2_path_str = nullptr;

    do
    {

    // Need targeting module loaded before calculating the size of the
    // EntityPaths.  If not loaded, don't make error callout, which
    // shouldn't be an issue as without targeting only 1 target is
    // available in the system: TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    if(Util::isTargetingLoaded() && TARGETING::targetService().isInitialized())
    {

        l_target_endp1_path_str = i_target_endp1.toString();
        l_target_endp2_path_str = i_target_endp2.toString();

        TRACFCOMP(g_trac_errl, ENTER_MRK"addBusCallout(%s, %s, %d, 0x%x)",
                  l_target_endp1_path_str, l_target_endp2_path_str,
                  i_busType, i_priority);

        auto size1 = sizeof(i_target_endp1) -
          (TARGETING::EntityPath::MAX_PATH_ELEMENTS - i_target_endp1.size()) *
          sizeof(TARGETING::EntityPath::PathElement);

        auto size2 = sizeof(i_target_endp2) -
          (TARGETING::EntityPath::MAX_PATH_ELEMENTS - i_target_endp2.size()) *
          sizeof(TARGETING::EntityPath::PathElement);

        ErrlUserDetailsCallout(&i_target_endp1,
                               size1,
                               &i_target_endp2,
                               size2,
                               i_busType,
                               i_priority,
                               i_flag).addToLog(this);

    }
    else
    {
        TRACFCOMP(g_trac_errl, ERR_MRK"addBusCallout(ep1, ep2, %d, 0x%x): "
                  "Can't process because targeting isn't loaded",
                  i_busType, i_priority);
    }

    } while (0);

    if (l_target_endp1_path_str != nullptr)
    {
        free(l_target_endp1_path_str);
        l_target_endp1_path_str = nullptr;
    }

    if (l_target_endp2_path_str != nullptr)
    {
        free(l_target_endp2_path_str);
        l_target_endp2_path_str = nullptr;
    }

    return;

} // addBusCallout (with EntityPath inputs)

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addHwCallout(const TARGETING::Target *i_target,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::DeconfigEnum i_deconfigState,
                        const HWAS::GARD_ErrorType i_gardErrorType)
{
    if (i_target == nullptr)
    {
        TRACFCOMP(g_trac_errl, ENTER_MRK
                  "addHwCallout called with NULL target");
        addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);
        return;
    }

    if (i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        #ifdef CONFIG_ERRL_ENTRY_TRACE
        TRACFCOMP(g_trac_errl, ENTER_MRK
                "addHwCallout(\"MASTER_PROC_SENTINEL\" 0x%x 0x%x 0x%x)",
                i_priority, i_deconfigState, i_gardErrorType);
        #else
        TRACDCOMP(g_trac_errl, ENTER_MRK
                "addHwCallout(\"MASTER_PROC_SENTINEL\" 0x%x 0x%x 0x%x)",
                i_priority, i_deconfigState, i_gardErrorType);
        #endif

        //need to override deconfig value to avoid possible deadlocks
        // in pnor
        HWAS::DeconfigEnum l_deconfigState = i_deconfigState;
        if( i_deconfigState == HWAS::DELAYED_DECONFIG )
        {
            TRACFCOMP( g_trac_errl, "addHwCallout> Forcing delayed deconfig to standard deconfig on sentinel" );
            l_deconfigState = HWAS::DECONFIG;
        }

        ErrlUserDetailsCallout(
                &HWAS::TARGET_IS_SENTINEL, sizeof(HWAS::TARGET_IS_SENTINEL),
                i_priority, l_deconfigState, i_gardErrorType).addToLog(this);
    }
    else
    {   // we got a non MASTER_SENTINEL target, therefore the targeting
        // module is loaded, therefore we can make this call.
        #ifdef CONFIG_ERRL_ENTRY_TRACE
        TRACFCOMP(g_trac_errl, ENTER_MRK"addHwCallout(0x%.8x 0x%x 0x%x 0x%x)",
                get_huid(i_target), i_priority,
                i_deconfigState, i_gardErrorType);
        #else
        TRACDCOMP(g_trac_errl, ENTER_MRK"addHwCallout(0x%.8x 0x%x 0x%x 0x%x)",
                get_huid(i_target), i_priority,
                i_deconfigState, i_gardErrorType);
        #endif

        TARGETING::EntityPath ep;
        ep = i_target->getAttr<TARGETING::ATTR_PHYS_PATH>();

        // size is total EntityPath size minus unused path elements
        uint32_t size1 = sizeof(ep) -
                    (TARGETING::EntityPath::MAX_PATH_ELEMENTS - ep.size()) *
                        sizeof(TARGETING::EntityPath::PathElement);

        // There is a problem if Hostboot sends an error log with a regular DECONFIG option and then
        //  fails the istep.  In this case, HWSV has a race in the order that it processes the
        //  deconfig request and the istep fail message.  If the istep failure happens before the
        //  deconfig takes place (inside of HWSV) it will be treated as a hard failure.  The correct
        //  behavior is that when there is a deconfig during an istep failure that we trigger a
        //  reconfig loop.  Therefore this issue results in an IPL failure instead of a reconfig
        //  loop, which is not correct.  To avoid this issue we will always use DELAYED_DECONFIG
        //  while inside our IPL context which will force HWSV to act the way we want them to.
        HWAS::DeconfigEnum l_deconfigState = i_deconfigState;
#ifndef __HOSTBOOT_RUNTIME
        if( INITSERVICE::spBaseServicesEnabled()
            && (i_deconfigState == HWAS::DECONFIG) )
        {
            TRACFCOMP( g_trac_errl, "addHwCallout> Forcing delayed deconfig from standard deconfig" );
            l_deconfigState = HWAS::DELAYED_DECONFIG;
        }
#endif //#ifndef __HOSTBOOT_RUNTIME

        ErrlUserDetailsCallout(&ep, size1,
                i_priority, l_deconfigState, i_gardErrorType).addToLog(this);

    }
} // addHwCallout


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addProcedureCallout(const HWAS::epubProcedureID i_procedure,
                            const HWAS::callOutPriority i_priority)
{
    #ifdef CONFIG_ERRL_ENTRY_TRACE
    TRACFCOMP( g_trac_errl, ENTER_MRK"addProcedureCallout(0x%x, 0x%x)",
                i_procedure, i_priority);
    #else
    TRACDCOMP( g_trac_errl, ENTER_MRK"addProcedureCallout(0x%x, 0x%x)",
                i_procedure, i_priority);
    #endif

    ErrlUserDetailsCallout(i_procedure, i_priority).addToLog(this);

} // addProcedureCallout

///////////////////////////////////////////////////////////////////////////////
// Function to add a UD section containing the Hostboot Build ID to the
// current error log being committed
void ErrlEntry::addHbBuildId()
{
    // Title string
    const char * const l_title = "Hostboot Build ID: ";
    // Char[] based on title + Hostboot image ID
    char l_pString[strlen(l_title) + strlen(&hbi_ImageId) + 1];
    // Set beginning of string
    strcpy(l_pString, l_title);
    // Concatenate the Hostboot Image ID
    strcat(l_pString, &hbi_ImageId);
    // Create UD section and add string
    ErrlUserDetailsString(l_pString).addToLog(this);
}

enum {
    SKIP_INFO_RECOVERABLE_LOGS = 0,
    ENABLE_INFORMATIONAL_LOGS =
        TARGETING::HIDDEN_ERRLOGS_ENABLE_ALLOW_INFORMATIONAL,
    ENABLE_RECOVERABLE_LOGS =
        TARGETING::HIDDEN_ERRLOGS_ENABLE_ALLOW_RECOVERED,
    ENABLE_ALL_LOGS = ENABLE_INFORMATIONAL_LOGS | ENABLE_RECOVERABLE_LOGS,
    DISPLAY_INFORMATIONAL_LOGS =
        TARGETING::HIDDEN_ERRLOGS_ENABLE_DISPLAY_INFORMATIONAL,
    DISPLAY_RECOVERABLE_LOGS =
        TARGETING::HIDDEN_ERRLOGS_ENABLE_DISPLAY_RECOVERED,
    DISPLAY_ALL_LOGS = DISPLAY_INFORMATIONAL_LOGS | DISPLAY_RECOVERABLE_LOGS
};

void ErrlEntry::checkHiddenLogsEnable( )
{
    // Note: iv_skipShowingLog and iv_skipProcessingLog are set to true by
    //     default
    // See HIDDEN_ERRLOGS_ENABLE targeting enumeration for possible bitmask
    // values.

    const auto hiddenLogFlags = getHiddenLogsEnable();

    switch(sev())
    {
        case ERRL_SEV_INFORMATIONAL:

            if(hiddenLogFlags & ENABLE_INFORMATIONAL_LOGS)
            {
                iv_skipProcessingLog = false;
            }
            if(hiddenLogFlags & DISPLAY_INFORMATIONAL_LOGS)
            {
                iv_skipShowingLog = false;
            }
            break;

        case ERRL_SEV_RECOVERED:

            if(hiddenLogFlags & ENABLE_RECOVERABLE_LOGS)
            {
                iv_skipProcessingLog = false;
            }
            if(hiddenLogFlags & DISPLAY_RECOVERABLE_LOGS)
            {
                iv_skipShowingLog = false;
            }
            break;

        default:

            // For any error log that is not INFORMATIONAL
            // or RECOVERED, we want to process and display the log
            iv_skipProcessingLog = false;
            iv_skipShowingLog = false;
            break;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Called by addHwCallout to retrieve various pieces of card
//  and/or chip data, e.g. part number, serial number, ecid.
void ErrlEntry::addPartIdInfoToErrLog
   (const TARGETING::Target * i_target)
{
    TRACDCOMP(g_trac_errl, ENTER_MRK"ErrlEntry::addPartIdInfoToErrLog()");

    const TARGETING::Target * l_target = i_target;
    const TARGETING::Target * l_targetPrev = nullptr;
    ErrlUserDetailsAttribute* l_attrdata = nullptr;

    //Add the part number to the error log.
    TARGETING::TargetHandleList l_parentList;
    TARGETING::ATTR_PART_NUMBER_type l_PN = {};
    while( !l_target->tryGetAttr<TARGETING::ATTR_PART_NUMBER>(l_PN) )
    {
        // Get immediate parent
        TARGETING::targetService().getAssociated(
                              l_parentList,
                              l_target,
                              TARGETING::TargetService::PARENT,
                              TARGETING::TargetService::IMMEDIATE);

        // never found a match...
        if (l_parentList.size() != 1)
        {
            l_target = nullptr;
            break;
        }

        l_target = l_parentList[0];
        l_parentList.clear();  // clear out old entry
    } // end while
    if( l_target )
    {
        l_attrdata = new ErrlUserDetailsAttribute(l_target);
        l_attrdata->addData(TARGETING::ATTR_PART_NUMBER);
        l_targetPrev = l_target;
    }

    // Note - it is extremely likely that we will end up with the same
    //  target for PN and SN, but since this is error path only we're
    //  opting for thoroughness over efficiency.

    //Add the serial number to the error log.
    l_target = i_target;
    TARGETING::ATTR_SERIAL_NUMBER_type l_SN = {};
    while( !l_target->tryGetAttr<TARGETING::ATTR_SERIAL_NUMBER>(l_SN) )
    {
        // Get immediate parent
        TARGETING::targetService().getAssociated(
                              l_parentList,
                              l_target,
                              TARGETING::TargetService::PARENT,
                              TARGETING::TargetService::IMMEDIATE);

        // never found a match...
        if (l_parentList.size() != 1)
        {
            l_target = nullptr;
            break;
        }

        l_target = l_parentList[0];
        l_parentList.clear();  // clear out old entry
    } // end while
    if( l_target )
    {
        // not likely to happen, but just in case...
        if( l_attrdata && (l_targetPrev != l_target) )
        {
            // got a new target, commit the previous data and start over
            l_attrdata->addToLog(this);
            delete l_attrdata;
            l_attrdata = nullptr;
        }
        if( !l_attrdata )
        {
            l_attrdata = new ErrlUserDetailsAttribute(l_target);
        }

        l_attrdata->addData(TARGETING::ATTR_SERIAL_NUMBER);
        l_targetPrev = l_target;
    }

    //Add the ECID to the error log.
    l_target = i_target;
    TARGETING::ATTR_ECID_type l_ECID = {};
    while( !l_target->tryGetAttr<TARGETING::ATTR_ECID>(l_ECID) )
    {
        // Get immediate parent
        TARGETING::targetService().getAssociated(
                              l_parentList,
                              l_target,
                              TARGETING::TargetService::PARENT,
                              TARGETING::TargetService::IMMEDIATE);

        // never found a match...
        if (l_parentList.size() != 1)
        {
            l_target = nullptr;
            break;
        }

        l_target = l_parentList[0];
        l_parentList.clear();  // clear out old entry
    } // end while
    if( l_target )
    {
        // not likely to happen, but just in case...
        if( l_attrdata && (l_targetPrev != l_target) )
        {
            // got a new target, commit the previous data and start over
            l_attrdata->addToLog(this);
            delete l_attrdata;
            l_attrdata = nullptr;
        }
        if( !l_attrdata )
        {
            l_attrdata = new ErrlUserDetailsAttribute(l_target);
        }

        l_attrdata->addData(TARGETING::ATTR_ECID);
        l_targetPrev = l_target;
    }

    if( l_attrdata )
    {
        l_attrdata->addToLog(this);
        delete l_attrdata;
    }

    TRACDCOMP(g_trac_errl, EXIT_MRK"ErrlEntry::addPartIdInfoToErrLog()");
}


void ErrlEntry::checkForDeconfigAndGard()
{
    //Loop through each section of the errorlog
    for(auto & section : iv_SectionVector)
    {
        if (section->compId() == ERRL_COMP_ID && section->subSect() == ERRORLOG::ERRL_UDT_CALLOUT)
        {
            const auto callout_ud = reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData);
            // Looking at hwasCallout.H only the HW, CLOCK, and PART Callouts will have a target
            // entry that follows the UDT callout entry
            if(callout_ud->type == HWAS::HW_CALLOUT)
            {
                if(callout_ud->deconfigState != HWAS::NO_DECONFIG)
                {
                    setDeconfigBit();
                }
                if(callout_ud->gardErrorType != HWAS::GARD_NULL)
                {
                    setGardBit();
                }
            }
            else if(callout_ud->type == HWAS::CLOCK_CALLOUT)
            {
                if(callout_ud->clkDeconfigState != HWAS::NO_DECONFIG)
                {
                    setDeconfigBit();
                }
                if(callout_ud->clkGardErrorType != HWAS::GARD_NULL)
                {
                    setGardBit();
                }
            }
            else if(callout_ud->type == HWAS::PART_CALLOUT)
            {
                if(callout_ud->partDeconfigState != HWAS::NO_DECONFIG)
                {
                    setDeconfigBit();
                }
                if(callout_ud->partGardErrorType != HWAS::GARD_NULL)
                {
                    setGardBit();
                }
            }
        }
    }
}

void ErrlEntry::traceLogEntry()
{
    // Flatten the SRC section so that we can get the SRC words
    // (discarding the flattened result afterwards)
    std::vector<uint8_t> flatsrc(iv_Src.flatSize());
    iv_Src.flatten(flatsrc.data(), flatsrc.size());

    const auto pelsrchdr = reinterpret_cast<const pelSRCSection_t*>(flatsrc.data());
    const uint32_t * wordptr =  reinterpret_cast<const uint32_t*>(&(pelsrchdr->src.reserved1));

    TRACFCOMP(g_trac_errl, "PLID 0x%.8X EID 0x%.8X - Reference Code %.4X, log size 0x%llX", plid(), eid(), pelsrchdr->src.reserved1, flattenedSize());
    TRACFCOMP(g_trac_errl, "EID %.8X Hex Words 2 -5  : %08X %08X %08X %08X", eid(), wordptr[1], wordptr[2], wordptr[3], wordptr[4]);
    TRACFCOMP(g_trac_errl, "EID %.8X Hex Words 6 -9  : %08X %08X %08X %08X", eid(), wordptr[5], wordptr[6], wordptr[7], wordptr[8]);
}

///////////////////////////////////////////////////////////////////////////////
// for use by ErrlManager
void ErrlEntry::commit( compId_t  i_committerComponent )
{
    using namespace TARGETING;

    // TODO RTC 35258 need a better timepiece, or else apply a transform onto
    // timebase for an approximation of real time.
    iv_Private.iv_committed = getTB();

    // User/Extended headers contain the component ID of the committer.
    iv_User.setComponentId( i_committerComponent );
    iv_Extended.setComponentId(i_committerComponent);
    iv_ED.setComponentId( i_committerComponent );

    setSubSystemIdBasedOnCallouts();

    // Add the captured backtrace to the error log
    if (iv_pBackTrace)
    {
        iv_pBackTrace->addToLog(this);
        delete iv_pBackTrace;
        iv_pBackTrace = NULL;
    }

    // Add the Hostboot Build ID to the error log
    addHbBuildId();

    // Check to see if we should skip processing info and recoverable errors
    checkHiddenLogsEnable();

    // These will go into the EH section. The real information will be gathered
    // from attributes on called-out targets, if targeting is loaded.
    TARGETING::ATTR_SERIAL_NUMBER_type serial_number = { }; // first 4 bytes used as serial
    TARGETING::ATTR_RAW_MTM_type mtm = "UNKNOWN";
    TARGETING::ATTR_FW_RELEASE_VERSION_type release_version = "UNKNOWN";
    TARGETING::ATTR_FW_SUBSYS_VERSION_type subsys_version = "UNKNOWN";

    // Check to make sure targeting is initialized. If so, collect part and
    // serial numbers
    if(Util::isTargetingLoaded() && targetService().isInitialized())
    {
        Target* sys = nullptr;
        targetService().getTopLevelTarget(sys);

        Target* node = nullptr;
        UTIL::getMasterNodeTarget(node);

        // Set the starting values for these attributes based on the toplevel
        // and master node targets. They will be overriden by PEL target
        // callouts if there are any.
        if (sys)
        {
            UTIL::tryGetAttributeInHierarchy<ATTR_RAW_MTM>(sys, mtm);
            UTIL::tryGetAttributeInHierarchy<ATTR_FW_RELEASE_VERSION>(sys, release_version);
            UTIL::tryGetAttributeInHierarchy<ATTR_FW_SUBSYS_VERSION>(sys, subsys_version);
        }

        if (node)
        {
            UTIL::tryGetAttributeInHierarchy<ATTR_SERIAL_NUMBER>(node, serial_number);
        }

#ifdef CONFIG_BUILD_FULL_PEL
        // Collect various data for the callouts present in this error for BMC since FSP historically handled that for
        // Hostboot.
        collectCalloutDataForBMC( node);
#endif
    }
    else
    {
        TRACFCOMP(g_trac_errl,
                "TARGETING has not been initialized yet! Skipping serial/part "
                "number collection!");
    }

    // Ensure the iv_gard and iv_deconfig bits are set correctly on the ErrlSrc member
    checkForDeconfigAndGard();

    { /* Set Extended Header info */
        char serial_string[sizeof(mtms_t::serial)] = { };

        snprintf(serial_string, sizeof(serial_string),
                 "%.8X", *reinterpret_cast<const uint32_t*>(serial_number));

        iv_Extended.setSerial(serial_string);
        iv_Extended.setMTM(mtm);
        iv_Extended.setFirmwareVersion(release_version);
        iv_Extended.setSubsystemVersion(subsys_version);

        // Flatten the SRC section (and discard the result afterwards) so that
        // we can get the SRC words for the EH section's symptom ID
        std::vector<uint8_t> flatsrc(iv_Src.flatSize());

        iv_Src.flatten(flatsrc.data(), flatsrc.size());

        // Skip SRC words 0 and 1 to start at SRC word 2 for the symptom ID
        // (wordcount does not include the zeroth SRC word)
        const auto pelsrchdr = reinterpret_cast<const pelSRCSection_t*>(flatsrc.data());
        iv_Extended.setSymptomId(pelsrchdr->src.srcString, &pelsrchdr->src.word2, pelsrchdr->src.wordcount - 1);
    }
}

#ifdef CONFIG_BUILD_FULL_PEL

/* @brief Look up a target given a relative location code. If there are multiple
 *        targets with the same relative location code, prefer the one with
 *        valid FRU attributes (like FRU_CCIN etc.)
 *
 * @param[in] i_location_code  The relative location code to search for.
 * @return    Target*          The target with the given location code, or nullptr if not found.
 */
Target* findFruByLocationCode(const ATTR_STATIC_ABS_LOCATION_CODE_type& i_location_code)
{
    ATTR_STATIC_ABS_LOCATION_CODE_type target_location_code = { };

    Target* result = nullptr;

    // Prefer to find a target that has FRU attributes on it, but if we can't
    // then return this value.
    Target* worse_result = nullptr;

    for (const auto targ : targetService())
    {
        if (targ->tryGetAttr<ATTR_STATIC_ABS_LOCATION_CODE>(target_location_code))
        {
            if (strcmp(target_location_code, i_location_code) == 0)
            {
                // If the target has a good CCIN then return it.
                ATTR_FRU_CCIN_type ccin = { };
                if (targ->tryGetAttr<ATTR_FRU_CCIN>(ccin) && ccin != 0)
                {
                    result = targ;
                    break;
                }
                else
                {
                    worse_result = targ;
                }
            }
        }
    }

    if (!result)
    {
        result = worse_result;
    }

    return result;
}

/* @brief Parse the next callout in a list of callouts in the form
 *  P1:LOC1,P2:LOC2,...
 *
 * @param[in/out] io_callout_list  A list of callouts. On exit, points to the character in
 *                                 the string where parsing ended.
 * @param[out]    o_callout        The next callout. Only valid if the return value is true.
 * @return        bool             True if a valid callout was parsed, false otherwise.
 */
bool parseTargetCallout(const char*& io_callout_list, ErrlEntry::target_callout& o_callout)
{
    using namespace HWAS;

    bool parsed = false;

    do
    {

    if (*io_callout_list)
    {
        /* Look for the callout priority (L, M or H) */

        if (*io_callout_list == 'H')
        {
            o_callout.priority = SRCI_PRIORITY_HIGH;
        }
        else if (*io_callout_list == 'M')
        {
            o_callout.priority = SRCI_PRIORITY_MED;
        }
        else if (*io_callout_list == 'L')
        {
            o_callout.priority = SRCI_PRIORITY_LOW;
        }
        else
        {
            break;
        }

        /* Look for the colon separator */

        ++io_callout_list;

        if (*io_callout_list != ':')
        {
            break;
        }

        /* Look for a comma or the end of the string to delimit our location code */

        ++io_callout_list;

        const char* location_code_begin = io_callout_list;

        while (*io_callout_list && *io_callout_list != ',')
        {
            ++io_callout_list;
        }

        const char* location_code_end = io_callout_list;

        if (*io_callout_list == ',')
        {
            ++io_callout_list;
        }

        /* Copy it into a local variable and look up the target */

        ATTR_STATIC_ABS_LOCATION_CODE_type loccode = { };

        if (static_cast<size_t>(location_code_end - location_code_begin) >= sizeof(loccode))
        {
            break;
        }

        std::copy(location_code_begin, location_code_end, loccode);

        o_callout.target = findFruByLocationCode(loccode);

        if (!o_callout.target)
        {
            break;
        }

        parsed = true;
    }

    } while (false);

    return parsed;
}

/* @brief Get a list of all targets called out by a given string in the format
 *        P1:LOC1,P2:LOC2,...
 * where P1, P2, ... are the letters L, M or H (for low, medium, or high) and LOC1,
 * LOC2, ... are strings designating location codes.
 */
std::vector<ErrlEntry::target_callout> ErrlEntry::getTargetCallouts(const char* i_callout_list)
{
    std::vector<target_callout> callouts;

    while (*i_callout_list)
    {
        target_callout callout = { };

        if (parseTargetCallout(i_callout_list, callout))
        {
            callouts.push_back(callout);
        }
    }

    return callouts;
}

void ErrlEntry::collectFruPathCalloutDataForBMC(HWAS::callout_ud_t* i_ud)
{
    do
    {

    /* Read the called-out source and destination bus targets from the userdata */

    uint8_t* l_uData = reinterpret_cast<uint8_t *>(i_ud + 1);
    Target* targets[2] = { };

    bool l_err = HWAS::retrieveTarget(l_uData, targets[0], this);

    if (l_err)
    {
        TRACFCOMP(g_trac_errl, ERR_MRK"collectFruPathCalloutDataForBMC: Getting source bus from callout failed (plid = 0x%08x)",
                  plid());
        break;
    }

    l_err = HWAS::retrieveTarget(l_uData, targets[1], this);

    if (l_err)
    {
        TRACFCOMP(g_trac_errl, ERR_MRK"collectFruPathCalloutDataForBMC: Getting destination bus from callout failed (plid = 0x%08x)",
                  plid());
        break;
    }

    /* Parse and collect the FRU callouts from the bus targets */

    std::vector<target_callout> callouts;

    for (const auto target : targets)
    {
        ATTR_FRU_PATH_type fru_path = { };

        if (target->tryGetAttr<ATTR_FRU_PATH>(fru_path))
        {
            const auto target_callouts = getTargetCallouts(fru_path);

            callouts.insert(end(callouts), begin(target_callouts), end(target_callouts));
        }
    }

    callouts = hbstd::deduplicate(std::move(callouts));

    /* Collect FRU callout data from each called-out target */

    if (!callouts.empty())
    {
        for (const auto callout : callouts)
        {
            TRACFCOMP(g_trac_errl, INFO_MRK"collectFruPathCalloutDataForBMC(plid=0x%08x): Calling out 0x%08x with priority %d",
                      plid(), get_huid(callout.target), i_ud->priority);

            addFruCalloutDataToSrc(callout.target, i_ud->priority, FAILING_COMP_TYPE_NORMAL_HW, i_ud->procedure);
        }
    }
    else
    {
        // If we don't get any targets in the FRU path to call out, fall back to
        // calling out the two targets in the userdata directly.
        addFruCalloutDataToSrc(targets[0], i_ud->priority, FAILING_COMP_TYPE_NORMAL_HW, i_ud->procedure);
        addFruCalloutDataToSrc(targets[1], i_ud->priority, FAILING_COMP_TYPE_NORMAL_HW, i_ud->procedure);
    }

    } while (false);
}

void ErrlEntry::collectBusCalloutDataForBMC(HWAS::callout_ud_t* const i_ud)
{
    switch (i_ud->busType)
    {
    case HWAS::X_BUS_TYPE:
    case HWAS::OMI_BUS_TYPE:
    case HWAS::FSI_BUS_TYPE:
        collectFruPathCalloutDataForBMC(i_ud);
        break;
    default:
        // If we can't parse this kind of bus connection callout, we can't get a
        // target handle target and can't add any FRU data to the log.
        break;
    }
}

void ErrlEntry::collectSeepromCalloutDataForBMC(Target* const i_target, HWAS::callout_ud_t* const i_ud)
{
    ATTR_FRU_PATH_type fru_path = { };

    switch (i_ud->partType)
    {
    case HWAS::SBE_SEEPROM_PART_TYPE:
        i_target->tryGetAttr<ATTR_SPI_SBE_BOOT_CODE_PRIMARY_INFO_CALLOUTS>(fru_path);
        break;
    case HWAS::VPD_PART_TYPE:
        i_target->tryGetAttr<ATTR_SPI_MVPD_PRIMARY_INFO_CALLOUTS>(fru_path);
        break;
    default:
        // The callout list attributes we pull in the other cases above will
        // include all relevant targets in them. If we don't recognize this part
        // type, then we will by default call out the input target below.
        break;
    }

    const auto callouts = hbstd::deduplicate(getTargetCallouts(fru_path));
    const bool have_callouts = !callouts.empty();

    for (const auto callout : callouts)
    {
        TRACFCOMP(g_trac_errl, "collectSeepromCalloutDataForBMC(plid=0x%08x): Calling out 0x%08x with priority %d",
                  plid(), get_huid(callout.target), i_ud->priority);

        addFruCalloutDataToSrc(callout.target, i_ud->priority, FAILING_COMP_TYPE_NORMAL_HW, i_ud->procedure);
    }

    if (!have_callouts)
    { // If we didn't call anything out, call the target itself out.
        addFruCalloutDataToSrc(i_target, i_ud->priority, FAILING_COMP_TYPE_NORMAL_HW);
    }
}

void ErrlEntry::collectCalloutDataForBMC(TARGETING::Target* const i_node)
{
    using namespace TARGETING;

    for(size_t i = 0; i < iv_SectionVector.size(); i++)
    {
        ErrlUD * l_udSection = iv_SectionVector[i];
        HWAS::callout_ud_t * l_ud =
            reinterpret_cast<HWAS::callout_ud_t*>(l_udSection->iv_pData);

        if((ERRL_COMP_ID     == (l_udSection)->iv_header.iv_compId) &&
           (1                == (l_udSection)->iv_header.iv_ver) &&
           (ERRL_UDT_CALLOUT == (l_udSection)->iv_header.iv_sst))
        {

            switch(l_ud->type)
            {
                case(HWAS::PROCEDURE_CALLOUT):
                    addFruCalloutDataToSrc(nullptr, // No target associated with this callout.
                                           l_ud->priority,
                                           FAILING_COMP_TYPE_MAINT,
                                           l_ud->procedure);
                    break;
                case(HWAS::HW_CALLOUT):
                {
                    // Try to get the target associated with this user detail section.
                    uint8_t * l_uData = reinterpret_cast<uint8_t *>(l_ud + 1);
                    Target * l_target = nullptr;
                    bool l_err = HWAS::retrieveTarget(l_uData,
                                                      l_target,
                                                      this);

                    if (!l_err)
                    {
                        addPartIdInfoToErrLog( l_target );

                        // Add a FRU callout for this target to the Primary SRC
                        addFruCalloutDataToSrc(l_target,
                                               l_ud->priority,
                                               FAILING_COMP_TYPE_NORMAL_HW);
                    }
                    else
                    {
                        TRACFCOMP(g_trac_errl, ERR_MRK
                                  "ErrlEntry::collectCalloutDataForBMC() - HW_CALLOUT Error retrieving target");
                    }
                    break;
                }
                case(HWAS::BUS_CALLOUT):
                {
                    collectBusCalloutDataForBMC(l_ud);
                    break;
                }
                case(HWAS::CLOCK_CALLOUT):
                {
                    // All current BMC-based systems don't have a FRU for the clock card, it is a part of the backplane.
                    // Hostboot doesn't have a target for the backplane, so callout the node.
                    addFruCalloutDataToSrc(i_node,
                                           l_ud->priority,
                                           FAILING_COMP_TYPE_NORMAL_HW);
                    break;
                }
                case(HWAS::PART_CALLOUT):
                {
                    // Try to get the target associated with this user detail section.
                    uint8_t * l_uData = reinterpret_cast<uint8_t *>(l_ud + 1);
                    Target * l_target = nullptr;
                    bool l_err = HWAS::retrieveTarget(l_uData,
                                                      l_target,
                                                      this);
                    switch (l_ud->partType)
                    {
                        case(HWAS::PNOR_PART_TYPE):
                        {
                            // Since the PNOR is virtual this should be a callout of the BMC code.
                            addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                                HWAS::SRCI_PRIORITY_HIGH);
                            break;
                        }
                        case(HWAS::SBE_SEEPROM_PART_TYPE):
                        case(HWAS::VPD_PART_TYPE):
                        {
                            if (!l_err)
                            {
                                collectSeepromCalloutDataForBMC(l_target, l_ud);
                            }
                            else
                            {
                                TRACFCOMP(g_trac_errl, ERR_MRK
                                          "ErrlEntry::collectCalloutDataForBMC() - "
                                          "SBE_SEEPROM_PART_TYPE/VPD_PART_TYPE Error retrieving target");
                            }
                            break;
                        }
                        case(HWAS::LPC_SLAVE_PART_TYPE):
                        {
                            // A callout of the LPC receiver is going to be for the BMC but the target supplied will be
                            // the PROC which is the LPC controller. Find the BMC target and add a FRU callout for that.
                            TARGETING::TargetHandleList bmc;
                            getAllChips(bmc, TARGETING::TYPE_BMC, false);
                            if (bmc.size() != 0)
                            {
                                addFruCalloutDataToSrc(bmc[0],
                                                       l_ud->priority,
                                                       FAILING_COMP_TYPE_NORMAL_HW);
                            }
                            else
                            {
                                TRACFCOMP(g_trac_errl, ERR_MRK
                                          "ErrlEntry::collectCalloutDataForBMC() - "
                                          "LPC_SLAVE_PART_TYPE Error retrieving BMC target");
                            }
                            break;
                        }
                        case(HWAS::SPIVID_SLAVE_PART_TYPE):
                        {
                            //@TODO RTC-288617: Handle
                            break;
                        }
                        case(HWAS::TOD_CLOCK):
                        case(HWAS::MEM_REF_CLOCK):
                        case(HWAS::PROC_REF_CLOCK):
                        case(HWAS::PCI_REF_CLOCK):
                        {
                            // All current BMC-based systems don't have a FRU for the clock card, it is a part of the
                            // backplane. Hostboot doesn't have a target for the backplane, so callout the node.
                            addFruCalloutDataToSrc(i_node,
                                                   l_ud->priority,
                                                   FAILING_COMP_TYPE_NORMAL_HW);
                            break;
                        }
                        case(HWAS::NO_PART_TYPE):
                        case(HWAS::FLASH_CONTROLLER_PART_TYPE):
                        case(HWAS::SMP_CABLE):
                        case(HWAS::BPM_CABLE_PART_TYPE):
                        case(HWAS::NV_CONTROLLER_PART_TYPE):
                        case(HWAS::BPM_PART_TYPE):
                        case(HWAS::SPI_DUMP_PART_TYPE):
                        case(HWAS::GPIO_EXPANDER_PART_TYPE):
                        {
                            // Not supported, assert if Simics. So that they can be updated by error creators.
                            TRACFCOMP(g_trac_errl, ERR_MRK"ErrlEntry::collectCalloutDataForBMC(): "
                                      "Unsupported part type 0x%X for PART_CALLOUT",
                                      l_ud->partType);
                            if (Util::isSimicsRunning())
                            {
                                assert(false, "Part Type 0x%X for PART_CALLOUT not supported.",
                                       l_ud->partType);
                            }
                            break;
                        }
                    } // switch partTypeEnum
                    break;
                }
                case(HWAS::I2C_DEVICE_CALLOUT):
                {
                    // Taken care of by handleI2cDeviceCalloutWithinHostboot. Nothing to do here.
                    break;
                }
                case(HWAS::SENSOR_CALLOUT):
                {
                    // Not supported, assert if Simics. So that they can be updated by error creators.
                    TRACFCOMP(g_trac_errl, ERR_MRK"ErrlEntry::collectCalloutDataForBMC(): Unsupported callout type");
                    if (Util::isSimicsRunning())
                    {
                        assert(false, "Sensor Callouts are not supported.");
                    }

                    break;
                }
            }
        }
    }
}
#endif

///////////////////////////////////////////////////////////////////////////////
// Function to set the correct subsystem ID based on callout priorities
void ErrlEntry::setSubSystemIdBasedOnCallouts()
{
    TRACDCOMP(g_trac_errl, INFO_MRK
            "ErrlEntry::getSubSystemIdBasedOnCallouts()");

    HWAS::callout_ud_t *    pData = NULL;

    HWAS::callout_ud_t *  highestPriorityCallout = NULL;

    // look thru the errlog for any Callout UserDetail sections
    for( std::vector<ErrlUD*>::const_iterator it = iv_SectionVector.begin();
            it != iv_SectionVector.end();
            it++ )
    {
        // look for a CALLOUT section
        if ((ERRL_COMP_ID     == (*it)->iv_header.iv_compId) &&
                (1                == (*it)->iv_header.iv_ver) &&
                (ERRL_UDT_CALLOUT == (*it)->iv_header.iv_sst))
        {
            // its a callout, grab the priority
            pData = reinterpret_cast<HWAS::callout_ud_t *>
                ( (*it)->iv_pData );

            // figure out the highest priority callout, just grab
            // the first one if there are several with the same
            // priority.
            if( (highestPriorityCallout == NULL) ||
                (pData->priority > highestPriorityCallout->priority) )
            {
                highestPriorityCallout = pData;
            }
        }
    } // for each SectionVector

    // if this pointer is not null it will be pointing to the
    // highest priority entry
    if( (highestPriorityCallout == NULL) ||
        (highestPriorityCallout->priority == HWAS::SRCI_PRIORITY_NONE) )
    {
       if( sev() != ERRL_SEV_INFORMATIONAL )
       {
           // no callouts in log, add default callout for hb code and
           // add trace
           TRACFCOMP(g_trac_errl, "WRN>> No callouts in elog %.8X", eid());
           TRACFCOMP(g_trac_errl, "Adding default callout EPUB_PRC_HB_CODE ");
           addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                HWAS::SRCI_PRIORITY_LOW);
       }

       iv_User.setSubSys( EPUB_FIRMWARE_HOSTBOOT );
    }
    else
    {
        pData = highestPriorityCallout;

        if( pData->type ==  HWAS::HW_CALLOUT )
        {
            // rebuild the target from the entity path, then use
            // the target type to determine the ssid
            if (*((uint8_t *)(pData + 1)) != TARGET_IS_SENTINEL)
            {
                // copy the entity path from the data buffer
                TARGETING::EntityPath ep;
                memcpy(&ep, ( pData + 1), sizeof(ep));

                // convert the EntityPath to a Target pointer
                TARGETING::Target *pTarget =
                            TARGETING::targetService().toTarget(ep);

                TRACDCOMP(g_trac_errl, INFO_MRK
                        "mapping highest priority target 0x%x "
                        "callout to determine SSID",
                        pTarget->getAttr<TARGETING::ATTR_TYPE>() );

                // use the target type to get the failing ssid.
                iv_User.setSubSys( getSubSystem(
                        pTarget->getAttr<TARGETING::ATTR_TYPE>()));
            }
            else
            {
                // it was the sentinel -- so just use the proc ssid
                iv_User.setSubSys( EPUB_PROCESSOR_SUBSYS );
            }
        }
        else if ( pData->type == HWAS::PROCEDURE_CALLOUT )
        {
            // for procedures, map the procedure to a subsystem
            TRACDCOMP(g_trac_errl, INFO_MRK
                    "mapping highest priority procedure 0x%x "
                    "callout to determine SSID",  pData->procedure);
            iv_User.setSubSys(getSubSystem( pData->procedure));

        }
        else if ( pData->type == HWAS::BUS_CALLOUT )
        {
            TRACFCOMP(g_trac_errl, INFO_MRK
                    "mapping highest priority bus 0x%x "
                    "callout to determine SSID",  pData->busType);
            iv_User.setSubSys(getSubSystem(pData->busType));
        }
        else if ( pData->type == HWAS::CLOCK_CALLOUT )
        {
            TRACFCOMP(g_trac_errl, INFO_MRK
                    "mapping highest priority clock 0x%x "
                    "callout to determine SSID", pData->clockType);
            iv_User.setSubSys(getSubSystem(pData->clockType));
        }
        else if ( pData->type == HWAS::PART_CALLOUT )
        {
            TRACFCOMP(g_trac_errl, INFO_MRK
                    "mapping highest priority part 0x%x "
                    "callout to determine SSID", pData->partType);
            iv_User.setSubSys(getSubSystem(pData->partType));
        }
        else if ( pData->type == HWAS::SENSOR_CALLOUT )
        {
            TRACFCOMP(g_trac_errl, INFO_MRK
                    "mapping highest priority sensor type 0x%x "
                    "callout to determine SSID", pData->sensorType);
            iv_User.setSubSys(getSubSystem(pData->sensorType));
        }
        else if (pData->type == HWAS::I2C_DEVICE_CALLOUT)
        {
            TRACFCOMP(g_trac_errl, INFO_MRK
                    "setting subsystem for type 0x%x "
                    "callout to I2C Device", pData->type);

            iv_User.setSubSys(EPUB_CEC_HDW_I2C_DEVS);
        }
        else
        {
            TRACFCOMP(g_trac_errl, ERR_MRK
                    "Unknown callout type 0x%x, setting subsys to unknown",
                    pData->type);
            iv_User.setSubSys(EPUB_UNKNOWN);
        }
    }
    // add ssid to the SRC too, it is defined in the ErrlUH in FSP land
    // in hb code it has been defined in both places and is also used
    // in both places.
    iv_Src.setSubSys( iv_User.getSubSys() );

    TRACDCOMP(g_trac_errl, INFO_MRK
                "ErrlEntry::setSubSystemIdBasedOnCallouts() "
                "ssid selected 0x%X", iv_Src.getSubSys() );

}
///////////////////////////////////////////////////////////////////////////////
// Determine if this log should cause a termination
bool ErrlEntry::isTerminateLog() const
{
    bool l_terminate = false;

    switch( iv_termState )
    {
        case TERM_STATE_MNFG:
            l_terminate = true;
            break;

        case TERM_STATE_SOFT:
            l_terminate = true;
            break;

        default:
            l_terminate = false;
            break;

    }

    return l_terminate;

}

///////////////////////////////////////////////////////////////////////////////
// Map the target type to correct subsystem ID using a binary search
epubSubSystem_t ErrlEntry::getSubSystem( TARGETING::TYPE i_target ) const
{

    TRACDCOMP(g_trac_errl, ENTER_MRK"getSubSystem()"
            " i_target = 0x%x", i_target );

    // local variables
    epubSubSystem_t subsystem = EPUB_MISC_UNKNOWN;

    // search table for lowest possible match
    // iterator will either point to the match (if exists) or just past
    auto it = std::lower_bound(TARGET_TO_SUBSYS_TABLE,
                  std::end(TARGET_TO_SUBSYS_TABLE),
                  i_target,
                  [](const epubTargetTypeToSub_t& lhs, TARGETING::TYPE rhs){return lhs.xType < rhs; });
    // verify iterator not outside table
    if (it < std::end(TARGET_TO_SUBSYS_TABLE))
    {
       // verify iterator is pointing to target entry
       if (it->xType == i_target)
       {
          // found a valid subsystem for target type
          subsystem = it->xSubSys;
       }
    }

    if( subsystem == EPUB_MISC_UNKNOWN )
    {
        TRACFCOMP(g_trac_errl,"WRN>> Failed to find subsystem ID for "
                               "target type 0x%x", i_target);
    }

    TRACDCOMP(g_trac_errl, EXIT_MRK"getSubSystem()  ssid  0x%x", subsystem );

    return (subsystem);

}

///////////////////////////////////////////////////////////////////////////////
// Map the procedure type to correct subsystem ID using a binary search
epubSubSystem_t ErrlEntry::getSubSystem( epubProcedureID i_procedure  ) const
{
    TRACDCOMP(g_trac_errl, ENTER_MRK"getSubSystem()"
                " from procedure  0x%x", i_procedure );

    // local variables
    epubSubSystem_t subsystem = EPUB_MISC_UNKNOWN;

    uint32_t PROCEDURE_TO_SUBSYS_TABLE_ENTRIES =
                        sizeof(PROCEDURE_TO_SUBSYS_TABLE)/
                        sizeof(PROCEDURE_TO_SUBSYS_TABLE[0]);

    uint32_t low = 0;
    uint32_t high = PROCEDURE_TO_SUBSYS_TABLE_ENTRIES -1;
    uint32_t mid  = 0;

    while( low <= high )
    {
        mid = low + (( high - low)/2);

        if ( PROCEDURE_TO_SUBSYS_TABLE[mid].xProc > i_procedure )
        {
            high = mid -1;
        }
        else if ( PROCEDURE_TO_SUBSYS_TABLE[mid].xProc < i_procedure )
        {
            low = mid + 1;
        }
        else
        {
           subsystem = PROCEDURE_TO_SUBSYS_TABLE[mid].xSubSys;
           break;
        }
    }

    if( subsystem == EPUB_MISC_UNKNOWN )
    {
        TRACFCOMP(g_trac_errl,"WRN>> Failed to find subsystem ID for "
                               "procedure 0x%x", i_procedure);
    }

    TRACDCOMP(g_trac_errl, EXIT_MRK"getSubSystem()"
                " ssid  0x%x", subsystem );

    return (subsystem);
}

///////////////////////////////////////////////////////////////////////////////
// Map a bus type to a subsystem ID
epubSubSystem_t ErrlEntry::getSubSystem( HWAS::busTypeEnum i_busType ) const
{
    TRACDCOMP(g_trac_errl, ENTER_MRK"getSubSystem() from bus type 0x%x",
              i_busType);

    epubSubSystem_t subsystem = EPUB_MISC_UNKNOWN;

    const uint32_t BUS_TO_SUBSYS_TABLE_ENTRIES =
        sizeof(BUS_TO_SUBSYS_TABLE)/sizeof(BUS_TO_SUBSYS_TABLE[0]);

    for (uint32_t i = 0; i < BUS_TO_SUBSYS_TABLE_ENTRIES; i++)
    {
        if (BUS_TO_SUBSYS_TABLE[i].xType == i_busType)
        {
            subsystem = BUS_TO_SUBSYS_TABLE[i].xSubSys;
            break;
        }
    }

    if(subsystem == EPUB_MISC_UNKNOWN)
    {
        TRACFCOMP(g_trac_errl,"WRN>> Failed to find subsystem ID for bus type 0x%x",
                  i_busType);
    }

    TRACDCOMP(g_trac_errl, EXIT_MRK"getSubSystem() ssid 0x%x", subsystem);
    return subsystem;
}

///////////////////////////////////////////////////////////////////////////////
// Map a clock type to a subsystem ID
epubSubSystem_t ErrlEntry::getSubSystem( HWAS::clockTypeEnum i_clockType ) const
{
    TRACDCOMP(g_trac_errl, ENTER_MRK"getSubSystem() from clock type 0x%x",
              i_clockType);

    epubSubSystem_t subsystem = EPUB_MISC_UNKNOWN;

    const uint32_t CLOCK_TO_SUBSYS_TABLE_ENTRIES =
        sizeof(CLOCK_TO_SUBSYS_TABLE)/sizeof(CLOCK_TO_SUBSYS_TABLE[0]);

    for (uint32_t i = 0; i < CLOCK_TO_SUBSYS_TABLE_ENTRIES; i++)
    {
        if (CLOCK_TO_SUBSYS_TABLE[i].xType == i_clockType)
        {
            subsystem = CLOCK_TO_SUBSYS_TABLE[i].xSubSys;
            break;
        }
    }

    if(subsystem == EPUB_MISC_UNKNOWN)
    {
        TRACFCOMP(g_trac_errl,"WRN>> Failed to find subsystem ID for clock type 0x%x",
                  i_clockType);
    }

    TRACDCOMP(g_trac_errl, EXIT_MRK"getSubSystem() ssid 0x%x", subsystem);
    return subsystem;
}

///////////////////////////////////////////////////////////////////////////////
// Map a Sensor type to a subsystem ID
epubSubSystem_t ErrlEntry::getSubSystem(HWAS::sensorTypeEnum i_sensorType) const
{
    TRACDCOMP(g_trac_errl, ENTER_MRK"getSubSystem() from sensor type 0x%x",
              i_sensorType);

    epubSubSystem_t subsystem = EPUB_MISC_UNKNOWN;

    const uint32_t SENSOR_TO_SUBSYS_TABLE_ENTRIES =
        sizeof(SENSOR_TO_SUBSYS_TABLE)/sizeof(SENSOR_TO_SUBSYS_TABLE[0]);

    for (uint32_t i = 0; i < SENSOR_TO_SUBSYS_TABLE_ENTRIES; i++)
    {
        if (SENSOR_TO_SUBSYS_TABLE[i].xType == i_sensorType)
        {
            subsystem = SENSOR_TO_SUBSYS_TABLE[i].xSubSys;
            break;
        }
    }

    if(subsystem == EPUB_MISC_UNKNOWN)
    {
        TRACFCOMP(g_trac_errl,"WRN>> Failed to find subsystem ID for sensor type 0x%x",
                  i_sensorType);
    }

    TRACDCOMP(g_trac_errl, EXIT_MRK"getSubSystem() ssid 0x%x", subsystem);
    return subsystem;
}

///////////////////////////////////////////////////////////////////////////////
// Map a Part type to a subsystem ID
epubSubSystem_t ErrlEntry::getSubSystem( HWAS::partTypeEnum i_partType ) const
{
    TRACDCOMP(g_trac_errl, ENTER_MRK"getSubSystem() from part type 0x%x",
              i_partType);

    epubSubSystem_t subsystem = EPUB_MISC_UNKNOWN;

    const uint32_t PART_TO_SUBSYS_TABLE_ENTRIES =
        sizeof(PART_TO_SUBSYS_TABLE)/sizeof(PART_TO_SUBSYS_TABLE[0]);

    for (uint32_t i = 0; i < PART_TO_SUBSYS_TABLE_ENTRIES; i++)
    {
        if (PART_TO_SUBSYS_TABLE[i].xType == i_partType)
        {
            subsystem = PART_TO_SUBSYS_TABLE[i].xSubSys;
            break;
        }
    }

    if(subsystem == EPUB_MISC_UNKNOWN)
    {
        TRACFCOMP(g_trac_errl,"WRN>> Failed to find subsystem ID for part type 0x%x",
                  i_partType);
    }

    TRACDCOMP(g_trac_errl, EXIT_MRK"getSubSystem() ssid 0x%x", subsystem);
    return subsystem;
}


///////////////////////////////////////////////////////////////////////////////
// for use by ErrlManager
void ErrlEntry::processCallout()
{
    TRACDCOMP(g_trac_errl, INFO_MRK"errlEntry::processCallout");

    // Skip all callouts if this is a non-visible log
    if( !isSevVisible() )
    {
        TRACDCOMP(g_trac_errl, "Error log is non-visible - skipping callouts");
        return;
    }

    // see if HWAS has been loaded and has set the processCallout function
    HWAS::processCalloutFn pFn =
            ERRORLOG::theErrlManager::instance().getHwasProcessCalloutFn();
    if (pFn != NULL)
    {
        // look thru the errlog for any Callout UserDetail sections
        for(std::vector<ErrlUD*>::const_iterator it = iv_SectionVector.begin();
                it != iv_SectionVector.end();
                it++ )
        {
            // if this is a CALLOUT
            if ((ERRL_COMP_ID     == (*it)->iv_header.iv_compId) &&
                (1                == (*it)->iv_header.iv_ver) &&
                (ERRL_UDT_CALLOUT == (*it)->iv_header.iv_sst))
            {
                // call HWAS to have this processed
                errlHndl_t l_errl = this;
                (*pFn)(l_errl,(*it)->iv_pData, (*it)->iv_Size, false);
                assert((this == l_errl), "processCallout changed the errl");
            }
        } // for each SectionVector
    } // if HWAS module loaded
    else
    {
        TRACDCOMP(g_trac_errl, INFO_MRK"hwas processCalloutFn not set!");
    }

    TRACDCOMP(g_trac_errl, INFO_MRK"errlEntry::processCallout returning");
}


///////////////////////////////////////////////////////////////////////////////
// for use by ErrlManager
void ErrlEntry::deferredDeconfigure()
{
    // NOTE:
    // This function is called in the calling process of errl->commit.  Since
    // processes that are not allowed to touch swappable memory may call
    // errl->commit, we need to be very careful about what we do in this
    // function.
    //
    // The getHwasProcessCalloutFn is only enabled when the HWAS module is
    // loaded, but this does not ensure that the HWAS code pages are
    // physically present in memory.  Processes like the PnorRP cannot call
    // into the HWAS module, but can make callouts (using MASTER_..SENTINEL).
    //
    // Currently we're using the fact that non-swappable tasks do not make
    // deferred deconfig requests as the indicator that it is safe to call
    // the HWAS functionality.

    TRACDCOMP(g_trac_errl, INFO_MRK"errlEntry::deferredDeconfigure");

    // Skip all callouts if this is a non-visible log
    if( !isSevVisible() )
    {
        TRACDCOMP(g_trac_errl, "Error log is non-visible - skipping callouts");
        return;
    }

    // see if HWAS has been loaded and has set the processCallout function
    HWAS::processCalloutFn pFn =
            ERRORLOG::theErrlManager::instance().getHwasProcessCalloutFn();
    if (pFn != NULL)
    {
        //check for deferred deconfigure callouts
        // look thru the errlog for any Callout UserDetail sections
        for(std::vector<ErrlUD*>::const_iterator it = iv_SectionVector.begin();
                it != iv_SectionVector.end();
                it++ )
        {
            // if this is a CALLOUT and DELAYED_DECONFIG.
            if ((ERRL_COMP_ID     == (*it)->iv_header.iv_compId) &&
                (1                == (*it)->iv_header.iv_ver) &&
                (ERRL_UDT_CALLOUT == (*it)->iv_header.iv_sst) &&
                (HWAS::HW_CALLOUT ==
                    reinterpret_cast<HWAS::callout_ud_t*>(
                        (*it)->iv_pData)->type) &&
#if  __HOSTBOOT_RUNTIME
                ((HWAS::DELAYED_DECONFIG ==
                    reinterpret_cast<HWAS::callout_ud_t*>(
                        (*it)->iv_pData)->deconfigState) ||
                 (HWAS::DECONFIG ==
                    reinterpret_cast<HWAS::callout_ud_t*>(
                        (*it)->iv_pData)->deconfigState) ||
                 (HWAS::NO_DECONFIG ==
                    reinterpret_cast<HWAS::callout_ud_t*>(
                        (*it)->iv_pData)->deconfigState))
#else
                (HWAS::DELAYED_DECONFIG ==
                    reinterpret_cast<HWAS::callout_ud_t*>(
                        (*it)->iv_pData)->deconfigState)
#endif
               )
            {
                // call HWAS function to register this action,
                //  put it on a queue and will be processed separately,
                //  when the time is right.
                errlHndl_t l_errl = this;
                (*pFn)(l_errl,(*it)->iv_pData, (*it)->iv_Size, true);
                assert((this == l_errl), "processCallout changed the errl");
            }
        } // for each SectionVector
    } // if HWAS module loaded
    else
    {
        TRACDCOMP(g_trac_errl, INFO_MRK"hwas processCalloutFn not set!");
    }

    TRACDCOMP(g_trac_errl, INFO_MRK"errlEntry::deferredDeconfigure returning");
}

/* @brief Convenience function to select a value for systems that need Hostboot
 *        to build a full PEL (including the EH section) or 0 for those that don't.
 * @param[in] i_number Number to return
 * @return    size_t   The given value if this is a system that needs a full PEL,
 *                     or 0 otherwise.
 */

static size_t fullPelOnly(const size_t i_number)
{
#ifdef CONFIG_BUILD_FULL_PEL
    return i_number;
#else
    return 0;
#endif
}

// Sections at the start of an error log (non user-defined)
// 3 = PH, UH, PS + 2 more for full pel support (EH and ED)
const uint8_t NON_UD_SECTION_CNT = 3 + fullPelOnly(2);

//////////////////////////////////////////////////////////////////////////////
// for use by ErrlManager

uint64_t ErrlEntry::flattenedSize()
{
    uint64_t l_bytecount = iv_Private.flatSize() +
                           iv_User.flatSize() +
                           iv_Src.flatSize() +
                           fullPelOnly(iv_Extended.flatSize()) +
                           fullPelOnly(iv_ED.flatSize());

    // plus the sizes of the other optional sections

    std::vector<ErrlUD*>::const_iterator it;
    for( it = iv_SectionVector.begin(); it != iv_SectionVector.end(); it++ )
    {
        l_bytecount += (*it)->flatSize();
    }
    return l_bytecount;
}


/////////////////////////////////////////////////////////////////////////////
// Flatten this object and all its sections into PEL
// for use by ErrlManager. Return how many bytes flattened to the output
// buffer, or else zero on error.

uint64_t ErrlEntry::flatten( void * o_pBuffer,
            const uint64_t i_bufsize,
            const bool i_truncate)
{
    uint64_t l_flatSize = 0;
    uint64_t l_cb = 0;
    uint64_t l_sizeRemaining = i_bufsize;

    // iv_Private.iv_sectns is one byte so can only add one byte's worth of sections
    const uint8_t MAX_SECTIONS_ALLOWED = 0xFF;

    // The CPPASSERT() macro will cause the compile to abend
    // when the expression given evaluates to false.  If ever
    // these cause the compile to fail, then perhaps the size
    // of enum'ed types has grown unexpectedly.
    CPPASSERT( 2 == sizeof(iv_Src.iv_reasonCode));
    CPPASSERT( 2 == sizeof(compId_t));
    CPPASSERT( 1 == sizeof(iv_Src.iv_modId));

    do
    {
        // check if the input buffer needs to be and is big enough
        l_flatSize = flattenedSize();
        if (( l_sizeRemaining < l_flatSize ) && (!i_truncate))
        {
            TRACFCOMP( g_trac_errl,
                    ERR_MRK"Buffer (%d) < flatSize (%d), aborting flatten",
                    l_sizeRemaining, l_flatSize);
            l_flatSize = 0; // return zero
            break;
        }


        // Inform the private header how many sections there are,
        // counting the PH, UH, PS, EH, ED, and the optionals.
        const auto startingSectionCount = iv_SectionVector.size();
        auto sectionsLeft = startingSectionCount;
        if ((startingSectionCount + NON_UD_SECTION_CNT) > MAX_SECTIONS_ALLOWED)
        {
            TRACFCOMP(g_trac_errl,
                "Starting section count 0x%X is beyond max allowed by %d sections",
                startingSectionCount + NON_UD_SECTION_CNT,
                (startingSectionCount + NON_UD_SECTION_CNT) - MAX_SECTIONS_ALLOWED);
            iv_Private.iv_sctns = MAX_SECTIONS_ALLOWED;
            sectionsLeft = MAX_SECTIONS_ALLOWED - NON_UD_SECTION_CNT;
        }
        else
        {
            iv_Private.iv_sctns = NON_UD_SECTION_CNT + startingSectionCount;
        }

        char * pBuffer = static_cast<char *>(o_pBuffer);

        // save this location - if the number of sections that we flatten is
        // reduced, we need to update this PH section.
        char *pPHBuffer = pBuffer;

        auto flattener = [&](auto& section, const char* const section_name)
        {
            l_cb = section.flatten( pBuffer, l_sizeRemaining );
            if( 0 == l_cb )
            {
                TRACFCOMP( g_trac_errl, ERR_MRK"%s.flatten error", section_name);
                l_flatSize = 0;
                // don't check i_truncate - this section MUST fit.
                return false;
            }
            pBuffer += l_cb;
            l_sizeRemaining -= l_cb;
            return true;
        };

        // flatten the PH private header section
        if (!flattener(iv_Private, "ph")) break;

        // flatten the UH user header section
        if (!flattener(iv_User, "uh")) break;

        // flatten the PS primary SRC section
        if (!flattener(iv_Src, "ps")) break;

        // flatten the EH extended header section for OpenPOWER systems (the FSP
        // adds this section for us otherwise)
        if (fullPelOnly(true))
        {
            if (!flattener(iv_Extended, "eh")) break;
        }
        // flatten the ED extended user data section for OpenPOWER systems (the FSP
        // adds this section for us otherwise)
        if (fullPelOnly(true))
        {
            if (!flattener(iv_ED, "ed")) break;
        }

        // flatten the optional user-defined sections
        // Flattens in the following order: 1. Hardware Callouts
        //                                  2. Other UD sections (non-trace)
        //                                  3. Traces
        // When the user-defined sections exceed 16kB, FSP ERRL discards
        // any remaining user-defined sections.  Therefore this order
        // preserves the callouts, and then gives priority to other
        // non-trace sections.
        //
        // for saving errorlogs into PNOR, i_truncate will be set to true
        // and sections which don't fit are not saved.
        size_t flattenedSections = 0;

        std::vector<ErrlUD*>::const_iterator it;
        for(it = iv_SectionVector.begin();
            (it != iv_SectionVector.end()) && (l_flatSize != 0) && sectionsLeft;
            it++)
        {
            // If UD section is a hardware callout.
            if( (ERRL_COMP_ID     == (*it)->iv_header.iv_compId) &&
                (ERRL_UDT_CALLOUT == (*it)->iv_header.iv_sst) )
            {
                l_cb = (*it)->flatten( pBuffer, l_sizeRemaining );
                if( 0 == l_cb )
                {
                    if (i_truncate)
                    {
                        // TODO: RTC 77560 - error if this happens during test
                        TRACFCOMP( g_trac_errl,
                                INFO_MRK"ud.flatten error, skipping");
                        continue;
                    }
                    else
                    {
                        TRACFCOMP( g_trac_errl,
                                ERR_MRK"ud.flatten error, aborting");
                        l_flatSize = 0; // return zero
                        break;
                    }
                }
                ++flattenedSections;
                --sectionsLeft;
                pBuffer += l_cb;
                l_sizeRemaining -= l_cb;
            }
        } // for

        for(it = iv_SectionVector.begin();
            (it != iv_SectionVector.end()) && (l_flatSize != 0) && sectionsLeft;
            it++)
        {
            // If UD section is not a hardware callout and not a trace.
            if( !(((ERRL_COMP_ID        == (*it)->iv_header.iv_compId) &&
                   (ERRL_UDT_CALLOUT    == (*it)->iv_header.iv_sst)) ||
                  ((FIPS_ERRL_COMP_ID   == (*it)->iv_header.iv_compId) &&
                   (FIPS_ERRL_UDT_HB_TRACE == (*it)->iv_header.iv_sst))) )
            {
                l_cb = (*it)->flatten( pBuffer, l_sizeRemaining );
                if( 0 == l_cb )
                {
                    if (i_truncate)
                    {
                        // TODO: RTC 77560 - error if this happens during test
                        TRACFCOMP( g_trac_errl,
                                INFO_MRK"ud.flatten error, skipping");
                        continue;
                    }
                    else
                    {
                        TRACFCOMP( g_trac_errl,
                                ERR_MRK"ud.flatten error, aborting");
                        l_flatSize = 0; // return zero
                        break;
                    }
                }
                ++flattenedSections;
                --sectionsLeft;
                pBuffer += l_cb;
                l_sizeRemaining -= l_cb;
            }
        } // for

        // Before the trace UD sections are flattened, make sure there are no
        // duplicates.
        removeDuplicateTraces();

        for(it = iv_SectionVector.begin();
           (it != iv_SectionVector.end()) && (l_flatSize != 0) && sectionsLeft;
            it++)
        {
            // If UD section is a trace.
            if( (FIPS_ERRL_COMP_ID   == (*it)->iv_header.iv_compId) &&
                (FIPS_ERRL_UDT_HB_TRACE == (*it)->iv_header.iv_sst) )
            {

                l_cb = (*it)->flatten( pBuffer, l_sizeRemaining );
                if( 0 == l_cb )
                {
                    if (i_truncate)
                    {
                        // TODO: RTC 77560 - error if this happens during test
                        TRACFCOMP( g_trac_errl,
                                INFO_MRK"ud.flatten error, skipping");
                        continue;
                    }
                    else
                    {
                        TRACFCOMP( g_trac_errl,
                                ERR_MRK"ud.flatten error, aborting");
                        l_flatSize = 0; // return zero
                        break;
                    }
                }
                ++flattenedSections;
                --sectionsLeft;
                pBuffer += l_cb;
                l_sizeRemaining -= l_cb;
            }
        } // for

        if( 0 == l_flatSize )
        {
          break;
        }

        if (flattenedSections != startingSectionCount)
        {
            // some section was too big and didn't get flatten OR
            // there were too many sections - update the
            // section count in the PH section and re-flatten it.
            // count is the PH, UH, PS, EH, ED and the optionals.
            iv_Private.iv_sctns = NON_UD_SECTION_CNT + flattenedSections;
            if (sectionsLeft == 0)
            {
                TRACFCOMP(g_trac_errl, "Skipped flattening %d sections (sizeRemaining: %lld) "
                    "- actual total sections: 0x%02X size: %lld",
                    startingSectionCount - flattenedSections,
                    l_sizeRemaining,
                    iv_Private.iv_sctns,
                    (i_bufsize - l_sizeRemaining));
            }

            // use ph size, since this is overwriting flattened data
            l_cb = iv_Private.flatten( pPHBuffer, iv_Private.flatSize() );
            if( 0 == l_cb )
            {
                TRACFCOMP( g_trac_errl, ERR_MRK"ph.flatten error");
                l_flatSize = 0;
                // don't check i_truncate - this section MUST fit.
                break;
            }
        }
    }
    while( 0 );

    // if l_flatSize == 0, there was an error, return 0.
    //  else return actual size that we flattened into the buffer.
    return (l_flatSize == 0) ? 0 : (i_bufsize - l_sizeRemaining);
} // flatten


uint64_t ErrlEntry::unflatten( const void * i_buffer,  uint64_t i_len )
{
    const uint8_t * l_buf = static_cast<const uint8_t *>(i_buffer);
    uint64_t consumed = 0;
    uint64_t bytes_used = 0;
    uint64_t rc = 0;

    TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten Private section...");
    bytes_used = iv_Private.unflatten(l_buf);
    consumed    += bytes_used;
    l_buf       += bytes_used;
    TRACDCOMP(g_trac_errl, INFO_MRK"PH section, size 0x%04X, consumed=0x%04X", bytes_used, consumed);

    TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten User Header section...");
    bytes_used = iv_User.unflatten(l_buf);
    consumed    += bytes_used;
    l_buf       += bytes_used;
    TRACDCOMP(g_trac_errl, INFO_MRK"UH section, size 0x%04X, consumed=0x%04X", bytes_used, consumed);

    TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten SRC section...");
    bytes_used = iv_Src.unflatten(l_buf);
    consumed    += bytes_used;
    l_buf       += bytes_used;
    TRACDCOMP(g_trac_errl, INFO_MRK"PS section, size 0x%04X, consumed=0x%04X", bytes_used, consumed);

    if (fullPelOnly(true))
    {
        TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten Extended User Header section...");
        bytes_used = iv_Extended.unflatten(l_buf);
        consumed    += bytes_used;
        l_buf       += bytes_used;
        TRACDCOMP(g_trac_errl, INFO_MRK"EH section, size 0x%04X, consumed=0x%04X", bytes_used, consumed);
    }

    if (fullPelOnly(true))
    {
        TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten ED section...");
        bytes_used = iv_ED.unflatten(l_buf);
        consumed    += bytes_used;
        l_buf       += bytes_used;
        TRACDCOMP(g_trac_errl, INFO_MRK"ED section, size 0x%04X, consumed=0x%04X", bytes_used, consumed);
    }

    iv_SectionVector.clear();
    iv_btAddrs.clear();
    removeBackTrace();

    // loop thru the User Data sections (after already doing 3: Private, User
    // Header, SRC sections) while there's still data to process
    for (int32_t l_sc = NON_UD_SECTION_CNT;
            (l_sc < iv_Private.iv_sctns) && (consumed < i_len);
            l_sc++)
    {
        TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten User data section...");
        const ERRORLOG::pelSectionHeader_t * p =
            reinterpret_cast<const ERRORLOG::pelSectionHeader_t *>(l_buf);

        if(p->sid != ERRORLOG::ERRL_SID_USER_DEFINED) // 'UD'
        {
            // yikes - bad section
            TRACFCOMP(g_trac_errl, ERR_MRK"Bad UserData section (0x%04X) found while "
                      "importing flattened data into error log. plid=%08x",
                      p->sid, iv_Private.iv_plid);
            TRACFCOMP(g_trac_errl, ERR_MRK"Section %d of %d sections, overall offset in data 0x%.16llX",
                l_sc, iv_Private.iv_sctns, consumed);
            rc = -1;
            break;
        }
        const void * data = l_buf + sizeof(p);
        uint64_t d_size = p->len - sizeof(p);

        ErrlUD * ud = new ErrlUD(data,d_size,p->compId,p->ver,p->sst);
        consumed    += p->len;
        l_buf       += p->len;

        iv_SectionVector.push_back(ud);
    }

    // if we didn't get as many User Detail sections as the Private header says
    // we should have, then we have an error
    if ((iv_SectionVector.size() + NON_UD_SECTION_CNT) != iv_Private.iv_sctns)
    {
        rc = -1;
    }

    return rc;
}

//@brief Return the list of User Detail sections
//NOTE: You can pass COMP_ID or subsect 0 into this function for wildcard
std::vector<void*> ErrlEntry::getUDSections(compId_t i_compId,
                                            uint8_t i_subSect)
{
    std::vector<void *> copy_vector;

    for(auto const & section : iv_SectionVector)
    {
        if((section->compId() == i_compId) || (i_compId == 0))
        {
            if((section->subSect() == i_subSect) || (i_subSect == 0))
            {
                copy_vector.push_back(section->iv_pData);
            }
        }
    }

    return copy_vector;
}

uint8_t ErrlEntry::queryCallouts(TARGETING::Target         * const i_target,
                                 deconfig_and_gard_records * const o_accumulatedRecords)
{
    uint8_t criteria_matched = NO_MATCH;
    bool accumulateRecords = (o_accumulatedRecords != nullptr);

    if (accumulateRecords)
    {
        // Make sure the lists are empty
        o_accumulatedRecords->deconfigs.clear();
        o_accumulatedRecords->gards.clear();
    }

    //Loop through each section of the errorlog
    for(auto & section : iv_SectionVector)
    {
        if (section->compId() == ERRL_COMP_ID && section->subSect() == ERRORLOG::ERRL_UDT_CALLOUT)
        {
            const auto callout_ud = reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData);
            // Looking at hwasCallout.H only the HW, CLOCK, and PART Callouts will have a target
            // entry that follows the UDT callout entry
            if (callout_ud->type == HWAS::HW_CALLOUT ||
                callout_ud->type == HWAS::CLOCK_CALLOUT ||
                callout_ud->type == HWAS::PART_CALLOUT)
            {
                TARGETING::Target * target_found = nullptr;
                uint8_t * target_ptr = section->iv_pData + sizeof(HWAS::callout_ud_t);
                // retrieveTarget will return true if there was an error
                if(!retrieveTarget(target_ptr, target_found, this) &&
                   target_found  == i_target)
                {
                    criteria_matched |= TARGET_MATCH;

                    bool deconfig_exists = false;
                    bool gard_exists = false;
                    DeconfigEnum deconfigState = NO_DECONFIG;
                    GARD_ErrorType gardErrorType = GARD_NULL;

                    if(callout_ud->type == HWAS::HW_CALLOUT)
                    {
                        deconfig_exists = callout_ud->deconfigState != HWAS::NO_DECONFIG;
                        deconfigState = callout_ud->deconfigState;

                        gard_exists = callout_ud->gardErrorType != HWAS::GARD_NULL;
                        gardErrorType = callout_ud->gardErrorType;
                    }
                    else if(callout_ud->type == HWAS::CLOCK_CALLOUT)
                    {
                        deconfig_exists = callout_ud->clkDeconfigState != HWAS::NO_DECONFIG;
                        deconfigState = callout_ud->clkDeconfigState;

                        gard_exists = callout_ud->clkGardErrorType != HWAS::GARD_NULL;
                        gardErrorType = callout_ud->clkGardErrorType;
                    }
                    else if(callout_ud->type == HWAS::PART_CALLOUT)
                    {
                        deconfig_exists = callout_ud->partDeconfigState != HWAS::NO_DECONFIG;
                        deconfigState = callout_ud->partDeconfigState;

                        gard_exists = callout_ud->partGardErrorType != HWAS::GARD_NULL;
                        gardErrorType = callout_ud->partGardErrorType;
                    }

                    if(deconfig_exists)
                    {
                        criteria_matched |= DECONFIG_FOUND;
                    }
                    if(gard_exists)
                    {
                        criteria_matched |= GARD_FOUND;
                    }

                    if (accumulateRecords)
                    {
                        // Caller wishes to have a list of the deconfigs and gards. Add these to their respective lists.
                        o_accumulatedRecords->deconfigs.push_back(deconfigState);
                        o_accumulatedRecords->gards.push_back(gardErrorType);
                    }

                    // Do not exit loop in case there are multiple callouts
                    // for the same target type.
                }
            }
        }
    }

    return criteria_matched;
}

bool ErrlEntry::hasMaintenanceCallout(bool i_includeInfo)
{
    bool maintenance_callout_found = false;
    //Loop through each section of the errorlog
    for(auto & section : iv_SectionVector)
    {
        if (section->compId() == ERRL_COMP_ID && section->subSect() == ERRORLOG::ERRL_UDT_CALLOUT)
        {
            const auto callout_ud = reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData);
            // Looking at hwasCallout.H only the HW, CLOCK, and PART Callouts will have a target
            // entry that follows the UDT callout entry
            if (callout_ud->type != HWAS::PROCEDURE_CALLOUT)
            {
                maintenance_callout_found = true;
            }
        }
    }
    //Informational logs might have callouts but generally we don't care
    if( !i_includeInfo && !isSevVisible() )
    {
        maintenance_callout_found = false;
    }
    return maintenance_callout_found;
}


void ErrlEntry::setDeconfigState(TARGETING::Target* const i_target,
                                 DeconfigEnum i_deconfigState)
{
    //Loop through each section of the errorlog
    for(auto & section : iv_SectionVector)
    {
        if (section->compId() == ERRL_COMP_ID && section->subSect() == ERRORLOG::ERRL_UDT_CALLOUT)
        {
            const auto callout_ud = reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData);
            // Looking at hwasCallout.H only the HW, CLOCK, and PART Callouts will have a target
            // entry that follows the UDT callout entry
            if (callout_ud->type == HWAS::HW_CALLOUT ||
                callout_ud->type == HWAS::CLOCK_CALLOUT ||
                callout_ud->type == HWAS::PART_CALLOUT)
            {
                TARGETING::Target * target_found = nullptr;
                uint8_t * target_ptr = section->iv_pData + sizeof(HWAS::callout_ud_t);
                // retrieveTarget will return true if there was an error
                if(!retrieveTarget(target_ptr, target_found, this) &&
                   target_found  == i_target)
                {
                    TRACFCOMP(g_trac_errl,
                              "setDeconfigState: Found target 0x%08X callout match, setting deconfig state 0x%X for errl 0x%08X",
                              get_huid(i_target), i_deconfigState, eid());
                    // Depending on the user details' type set the appropriate
                    // deconfig field.
                    if (callout_ud->type == HWAS::HW_CALLOUT)
                    {
                        callout_ud->deconfigState = i_deconfigState;
                    }
                    else if (callout_ud->type == HWAS::CLOCK_CALLOUT)
                    {
                        callout_ud->clkDeconfigState = i_deconfigState;
                    }
                    else if (callout_ud->type == HWAS::PART_CALLOUT)
                    {
                        callout_ud->partDeconfigState = i_deconfigState;
                    }
                }
            }
        }
    }
}

void ErrlEntry::setGardType(TARGETING::Target* const i_target,
                            GARD_ErrorType i_gardType)
{
    //Loop through each section of the errorlog
    for(auto & section : iv_SectionVector)
    {
        if (section->compId() == ERRL_COMP_ID && section->subSect() == ERRORLOG::ERRL_UDT_CALLOUT)
        {
            const auto callout_ud = reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData);
            // Looking at hwasCallout.H only the HW, CLOCK, and PART Callouts will have a target
            // entry that follows the UDT callout entry
            if (callout_ud->type == HWAS::HW_CALLOUT ||
                callout_ud->type == HWAS::CLOCK_CALLOUT ||
                callout_ud->type == HWAS::PART_CALLOUT)
            {
                TARGETING::Target * target_found = nullptr;
                uint8_t * target_ptr = section->iv_pData + sizeof(HWAS::callout_ud_t);
                // retrieveTarget will return true if there was an error
                if(!retrieveTarget(target_ptr, target_found, this) &&
                   target_found  == i_target)
                {
                    TRACFCOMP(g_trac_errl,
                              "setGardType: Found target 0x%08X callout match, setting gard type 0x%X for errl 0x%08X",
                              get_huid(i_target), i_gardType, eid());
                    // Depending on the user details' type set the appropriate
                    // gard field.
                    if (callout_ud->type == HWAS::HW_CALLOUT)
                    {
                        callout_ud->gardErrorType = i_gardType;
                    }
                    else if (callout_ud->type == HWAS::CLOCK_CALLOUT)
                    {
                        callout_ud->clkGardErrorType = i_gardType;
                    }
                    else if (callout_ud->type == HWAS::PART_CALLOUT)
                    {
                        callout_ud->partGardErrorType = i_gardType;
                    }
                }
            }
        }
    }
}


void ErrlEntry::removeGardAndDeconfigure()
{
    //Loop through each section of the errorlog
    for(auto & section : iv_SectionVector)
    {
        if (section->compId() == ERRL_COMP_ID && section->subSect() == ERRORLOG::ERRL_UDT_CALLOUT)
        {
            auto ud_type = reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData)->type;
            TRACFCOMP(g_trac_errl,
                      "removeGardAndDeconfigure: setting GARD_NULL and NO_DECONFIG for callout of type 0x%02x for errl 0x%08X",
                      ud_type, eid());
            // Looking at hwasCallout.H only the HW, CLOCK, and PART Callouts have deconfigure/gard entries,
            // so only update those to ensure the ErrorType is GARD_NULL and deconfigType is NO_DECONFIG
            if (ud_type == HWAS::HW_CALLOUT)
            {
                reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData)->gardErrorType = HWAS::GARD_NULL;
                reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData)->deconfigState = HWAS::NO_DECONFIG;
            }
            else if (ud_type == HWAS::CLOCK_CALLOUT)
            {
                reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData)->clkGardErrorType = HWAS::GARD_NULL;
                reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData)->clkDeconfigState = HWAS::NO_DECONFIG;
            }
            else if (ud_type == HWAS::PART_CALLOUT)
            {
                reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData)->partGardErrorType = HWAS::GARD_NULL;
                reinterpret_cast<HWAS::callout_ud_t*>(section->iv_pData)->partDeconfigState = HWAS::NO_DECONFIG;
            }
        }
    }
}


void ErrlEntry::getErrlSize(uint32_t& o_flatSize,
                            uint32_t& o_maxSize)
{
    // iv_maxSize is a static class variable used so attribute does not
    // need to be constantly checked
    if (0 == iv_maxSize)
    {
#ifdef CONFIG_PLDM
        if(Util::isTargetingLoaded() && TARGETING::targetService().isInitialized())
        {
            TARGETING::TargetHandle_t l_sys = TARGETING::UTIL::assertGetToplevelTarget();
            iv_maxSize = l_sys->getAttr<TARGETING::ATTR_BMC_MAX_ERROR_LOG_SIZE>();
            TRACFCOMP(g_trac_errl, "getErrlSize() - ATTR_BMC_MAX_ERROR_LOG_SIZE is 0x%08X", iv_maxSize);
        }
        else
        {
            TRACFCOMP(g_trac_errl, "getErrlSize() - targeting unavailable, default max to 0x%08X", DEFAULT_MAX_LOG_SIZE);
            o_maxSize = DEFAULT_MAX_LOG_SIZE;
        }
#else
        // Default to 4KB for all others
        iv_maxSize = DEFAULT_MAX_LOG_SIZE;
#endif
    }

    // only use iv_maxSize if it was determined from targeting or non-PLDM
    if (iv_maxSize > 0)
    {
        o_maxSize = iv_maxSize;
    }

    // Remove any duplicate traces
    removeDuplicateTraces();
    o_flatSize = flattenedSize();
}


void ErrlEntry::removeDuplicateTraces()
{
    // Define a custom comparator function for std::map.find()
    struct mapComparator
    {
        bool operator()(const char* a, const char * b) const
        {
            return strcmp(a, b) < 0;
        }
    };

    // map of component id and corresponding trace entries.
    std::map<const char *, std::vector<TRACE::trace_bin_entry_t*>*,
             mapComparator> traceUD_map;
    auto it = traceUD_map.end();

    uint64_t l_flatSize = flattenedSize();

    // vector that will hold all of the trace UD sections
    // that are free of duplicates.
    std::vector<ErrlUD*> l_uniqueTraceUDVector;


    // Iterate through iv_SectionVector and create a map of all unique
    // component ids and their corresponding trace entries.
    for(auto sectionVectorIt = iv_SectionVector.begin();
       (sectionVectorIt != iv_SectionVector.end()) && (l_flatSize != 0);
        ++sectionVectorIt)
    {
        // If UD section is a trace.
        if( (FIPS_ERRL_COMP_ID   == (*sectionVectorIt)->iv_header.iv_compId)
          && (FIPS_ERRL_UDT_HB_TRACE == (*sectionVectorIt)->iv_header.iv_sst) )
        {
            char* l_dataPtr = static_cast<char*>((*sectionVectorIt)->data());
            char* l_dataEndPtr = l_dataPtr + (*sectionVectorIt)->dataSize();

            TRACE::trace_buf_head_t* l_trace_buf_head =
                reinterpret_cast<TRACE::trace_buf_head_t*>(l_dataPtr);

            // Look for the component id in the map to insert trace entries
            // or insert a new component id into the map to insert trace entries
            const char* l_compName = l_trace_buf_head->comp;

            it = traceUD_map.find(l_compName);

            if (traceUD_map.end() == it)
            {
                traceUD_map[l_compName] =
                    new std::vector<TRACE::trace_bin_entry_t*>;
                it = traceUD_map.find(l_compName);
            }

            //Start at end of trace header
            l_dataPtr += l_trace_buf_head->hdr_len;

            //verify that hdr_len doesn't extend outside the user data section
            if(l_dataPtr > l_dataEndPtr)
            {
                TRACFCOMP( g_trac_errl,
                    ERR_MRK"removeDuplicateTraces: header extends oustide UD section (hdr_len = %u)",
                    l_trace_buf_head->hdr_len);

                //skip this section and go to the next one
                continue;
            }

            // Add all trace entries to map for the current component id.
            for (size_t traceCount = 0; traceCount < l_trace_buf_head->te_count;
                 traceCount++)
            {
                TRACE::trace_bin_entry_t* l_trace_entry =
                    reinterpret_cast<TRACE::trace_bin_entry_t*>(l_dataPtr);

                // Find the size of this entry plus padding.
                // fsp-trace entries have an extra 4 bytes at the end of them
                // hence the sizeof(uint32_t)
                const size_t l_traceSize =
                            sizeof(TRACE::trace_bin_entry_t) +
                            ALIGN_8(l_trace_entry->head.length) +
                            sizeof(uint32_t);

                // Move pointer to start of next trace
                l_dataPtr += l_traceSize;

                // verify that this trace entry is contained within this user
                // data section
                if(l_dataPtr > l_dataEndPtr)
                {
                    TRACFCOMP( g_trac_errl,
                        ERR_MRK"removeDuplicateTraces: entry oustide UD section. length[%u] traceCount[%u] te_count[%u]",
                        l_traceSize, traceCount, l_trace_buf_head->te_count);
                    break;
                }

                // ok to add trace now that it passed our size check
                it->second->push_back(l_trace_entry);
            }
        }
    }

    // Iterate through the map to apply duplicate pruning to all component ids
    // found in iv_SectionVector
    for (auto const& it : traceUD_map)
    {
        // Sort the vector by timestamp and hash
        std::sort(it.second->begin(), it.second->end(),
                  // Define a lambda comparator function for sorting criteria
                  [](const TRACE::trace_bin_entry_t* a,
                      const TRACE::trace_bin_entry_t* b)
                    {
                        // a goes before b if a's timestamp is less than b's.
                        // If they are equal then compare the hash values.
                        bool result = false;
                        if (a->stamp.tbh < b->stamp.tbh)
                        {
                            result = true;
                        }
                        else if ((a->stamp.tbh == b->stamp.tbh)
                                 && (a->stamp.tbl < b->stamp.tbl))
                        {
                            result = true;
                        }
                        else if ((a->stamp.tbh == b->stamp.tbh)
                                && (a->stamp.tbl == b->stamp.tbl)
                                && (a->head.hash < b->head.hash))
                        {
                            result = true;
                        }
                        return result;
                    });

        // Call unique to prune the duplicate trace entries
        auto newEndIt = std::unique(it.second->begin(), it.second->end(),
                    // Define a lambda predicate function for duplicate criteria
                    [](const TRACE::trace_bin_entry_t* a,
                       const TRACE::trace_bin_entry_t* b)
                    {
                        // a is equivalent to b if a's timestamp is the same as
                        // b's and their hashes are the same.
                        bool result = false;
                        if ((a->stamp.tbh == b->stamp.tbh)
                            && (a->stamp.tbl == b->stamp.tbl)
                            && (a->head.hash == b->head.hash))
                        {
                            result = true;
                        }
                        return result;
                    });

        it.second->resize(std::distance(it.second->begin(), newEndIt));

        // Calculate the size of the buffer that will hold all remaining
        // trace entries in the new UD section
        size_t uniqueSize = sizeof(TRACE::trace_buf_head_t);

        for (auto uniqueIt = it.second->begin(); uniqueIt != it.second->end();
             ++uniqueIt)
        {
            uniqueSize += sizeof(TRACE::trace_bin_entry_t)
                          + ALIGN_8((*uniqueIt)->head.length)
                          + sizeof(uint32_t);
        }


        // Create a new buffer for the new UD section from the vector of traces
        // for this component id.
        TRACE::trace_buf_head_t* header = nullptr;
        char* l_pBuffer = new char[ uniqueSize ]();
        size_t l_pos = 0;

        // Write the header info to the buffer.
        // This header info was chosen based on the code that is found in
        // Buffer::getTrace() if that code is changed in the future those
        // changes will need to be reflected here.
        header = reinterpret_cast<TRACE::trace_buf_head_t*>(&l_pBuffer[l_pos]);

        memset(header, '\0', sizeof(TRACE::trace_buf_head_t));

        header->ver = TRACE::TRACE_BUF_VERSION;
        header->hdr_len = sizeof(TRACE::trace_buf_head_t);
        header->time_flg = TRACE::TRACE_TIME_REAL;
        header->endian_flg = 'B';
        memcpy(&header->comp[0], it.first, TRAC_COMP_SIZE);
        header->times_wrap = 0;
        header->te_count = 0;
        header->size = uniqueSize;
        header->next_free = uniqueSize;

        l_pos += header->hdr_len;

        // Copy the trace entries to the buffer
        for (auto uniqueIt = it.second->begin(); uniqueIt != it.second->end();
                ++uniqueIt)
        {
            // fsp-traces have an extra 4 bytes. Hence the sizeof(uint32_t)
            size_t entrySize = sizeof(TRACE::trace_bin_entry_t)
                             + ALIGN_8((*uniqueIt)->head.length)
                             + sizeof(uint32_t);

            // don't allow writing outside our allocated space
            if((l_pos + entrySize) > uniqueSize)
            {
                TRACFCOMP( g_trac_errl,
                    ERR_MRK"removeDuplicateTraces: trace len[%u] + pos[%u] > uniqueSize[%u]!!! te_count[%u]",
                    entrySize, l_pos, uniqueSize, header->te_count);
                break;
            }

            memcpy(&l_pBuffer[l_pos], (*uniqueIt), entrySize);

            l_pos += entrySize;

            // Keep count of how many entries were actually copied into
            // the buffer.
            header->te_count++;
        }
        header->next_free = l_pos;

        ErrlUD* l_udSection = new ErrlUD( l_pBuffer,
                                          uniqueSize,
                                          FIPS_ERRL_COMP_ID,
                                          FIPS_ERRL_UDV_DEFAULT_VER_1,
                                          FIPS_ERRL_UDT_HB_TRACE );

        l_uniqueTraceUDVector.push_back(l_udSection);

        delete[] l_pBuffer;
        delete it.second;
    }

    // Remove old trace UD sections
    auto sectionVectorIt = iv_SectionVector.begin();
    while(sectionVectorIt != iv_SectionVector.end())
    {
        // If UD section is a trace.
        if( (FIPS_ERRL_COMP_ID   == (*sectionVectorIt)->iv_header.iv_compId)
          && (FIPS_ERRL_UDT_HB_TRACE == (*sectionVectorIt)->iv_header.iv_sst))
        {
            // Remove the ErrlUD* at this position
            delete (*sectionVectorIt);
            // Erase this entry from the vector
            sectionVectorIt = iv_SectionVector.erase(sectionVectorIt);
        }
        else
        {
            ++sectionVectorIt;
        }

    }

    // Add new trace UD sections
    for(auto it = l_uniqueTraceUDVector.begin();
        it != l_uniqueTraceUDVector.end();
        ++it)
    {
        iv_SectionVector.push_back((*it));
    }

}



/**
 * @brief Check if the severity of this log indicates it is
 *   customer visible, note this ignores any override flags that
 *   might change standard behavior
 * @return true if log is visible
 */
bool ErrlEntry::isSevVisible( void )
{
    bool l_vis = true;
    switch( sev() )
    {
        // Hidden logs
        case( ERRL_SEV_INFORMATIONAL ): l_vis = false; break;
        case( ERRL_SEV_RECOVERED ): l_vis = false; break;

        // Visible logs
        case( ERRL_SEV_PREDICTIVE ): l_vis = true; break;
        case( ERRL_SEV_UNRECOVERABLE ): l_vis = true; break;
        case( ERRL_SEV_UNRECOVERABLE1 ): l_vis = true; break;
        case( ERRL_SEV_CRITICAL_SYS_TERM ): l_vis = true; break;

        // Error case, shouldn't happen so make it show up
        case( ERRL_SEV_UNKNOWN ): l_vis = true; break;
    }
    return l_vis;
}

void ErrlEntry::addI2cDeviceCallout(const TARGETING::Target *i_i2cMaster,
                                    const uint8_t i_engine,
                                    const uint8_t i_port,
                                    const uint8_t i_address,
                                    const HWAS::callOutPriority i_priority)
{
    do {

    if (i_i2cMaster == nullptr ||
        i_i2cMaster == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {

        TRACFCOMP(g_trac_errl, ERR_MRK
                  "addI2cDeviceCallout mistakenly called with %s target. "
                  "Adding high priority callout to the error log.",
                  i_i2cMaster? "MASTER_SENTINEL": "nullptr");
        addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);
        collectTrace(ERRL_COMP_NAME);
        break;
    }

    #ifdef CONFIG_ERRL_ENTRY_TRACE
    TRACFCOMP(g_trac_errl, ENTER_MRK
            "addI2cDeviceCallout(i2cm=0x%.8x e=0x%x p=0x%x devAddr=0x%x pri=0x%x)",
            get_huid(i_i2cMaster), i_engine, i_port, i_address, i_priority);
    #else
    TRACDCOMP(g_trac_errl, ENTER_MRK
            "addI2cDeviceCallout(i2cm=0x%.8x e=0x%x p=0x%x devAddr=0x%x pri=0x%x)",
            get_huid(i_i2cMaster), i_engine, i_port, i_address, i_priority);
    #endif

    const void* pData = nullptr;
    uint32_t size = 0;
    TARGETING::EntityPath* ep = nullptr;
    getTargData( i_i2cMaster, ep, pData, size );


    ErrlUserDetailsCallout(pData, size,
            i_engine, i_port, i_address, i_priority).addToLog(this);

    if (ep)
    {
        delete ep;
        ep = nullptr;
    }

    handleI2cDeviceCalloutWithinHostboot(this, i_i2cMaster, i_engine, i_port, i_address, i_priority);

    } while (0);

} // addI2cDeviceCallout


std::vector<ErrlUD*> ErrlEntry::removeExcessiveUDsections(uint64_t i_maxSize, bool i_keep_trace_sections)
{
    std::vector<ErrlUD*> l_extra_sections;

    uint64_t l_bytecount = iv_Private.flatSize() +
                           iv_User.flatSize() +
                           iv_Src.flatSize();


    std::vector<ErrlUD*>::iterator it;
    it = iv_SectionVector.begin();

    while( it != iv_SectionVector.end())
    {
        // If UD section is a trace and still room in ErrlEntry
        if ( i_keep_trace_sections &&
             ((FIPS_ERRL_COMP_ID == (*it)->iv_header.iv_compId) &&
              (FIPS_ERRL_UDT_HB_TRACE == (*it)->iv_header.iv_sst))
             && (l_bytecount + (*it)->flatSize() <= i_maxSize) )
        {
            l_bytecount += (*it)->flatSize();
            it++;
        }
        else
        {
            l_extra_sections.push_back(*it);
            it = iv_SectionVector.erase(it);
        }
    }

    it = l_extra_sections.begin();
    while ( it != l_extra_sections.end() )
    {
        if ((l_bytecount + (*it)->flatSize()) <= i_maxSize)
        {
            l_bytecount += (*it)->flatSize();
            iv_SectionVector.push_back(*it);
            it = l_extra_sections.erase(it);
        }
        else
        {
            break;
        }
    }
    return l_extra_sections;
}

void ErrlEntry::addUDSection( ErrlUD* i_section)
{
    iv_SectionVector.push_back(i_section);
}

#ifdef CONFIG_BUILD_FULL_PEL
void ErrlEntry::addFruCalloutDataToSrc(TARGETING::Target *            const i_target,
                                       callOutPriority                const i_priority,
                                       fruIdentitySubstructFlags      const i_compType,
                                       epubProcedureID                const i_procedure_id)
{
    using namespace TARGETING;

    // FRU callout
    fruCallOutEntry_t l_fruco {0};

    // Priority
    l_fruco.priority = i_priority;

    // Depending on the FRU component type passed in there may not be a target associated with the callout.
    switch(i_compType)
    {
    case(FAILING_COMP_TYPE_NORMAL_HW):
    {
        // The full location code is composed of the CHASSIS_LOCATION_CODE (C) concatenated with the
        // STATIC_ABS_LOCATION_CODE (S) separated by a hyphen. Ex. U78D8.ND0.FGD002D-P0-C16
        //                                                         CCCCCCCCCCCCCCCCC SSSSSS
        std::vector<char> full_location_code;

        {
            Target* const sys = UTIL::assertGetToplevelTarget();

            ATTR_CHASSIS_LOCATION_CODE_type chassis_code { };

            // ATTR_CHASSIS_LOCATION_CODE is a null terminated string and the max number of chars is defined by
            // ATTR_CHASSIS_LOCATION_CODE_max_chars. The maximum size for the location code according to the PEL
            // spec is PEL_LOC_CODE_SIZE which is also a null terminated string. So,
            // ATTR_CHASSIS_LOCATION_CODE_max_chars must be less than PEL_LOC_CODE_SIZE to account for the null
            // terminator.
            static_assert(ATTR_CHASSIS_LOCATION_CODE_max_chars < PEL_LOC_CODE_SIZE,
                         "ATTR_CHASSIS_LOCATION_CODE is too large to fit inside FRU callout location code section.");

            sys->tryGetAttr<ATTR_CHASSIS_LOCATION_CODE>(chassis_code);

            full_location_code.insert(end(full_location_code), chassis_code, chassis_code + strlen(chassis_code));

        }

        // Add the seperator
        full_location_code.push_back('-');

        {
            ATTR_STATIC_ABS_LOCATION_CODE_type static_abs_location_code { };

            // ATTR_STATIC_ABS_LOCATION_CODE is a null terminated string and the max number of chars is defined by
            // ATTR_STATIC_ABS_LOCATION_CODE_max_chars. The maximum size for the location code according to the PEL
            // spec is PEL_LOC_CODE_SIZE which is also a null terminated string. So,
            // ATTR_STATIC_ABS_LOCATION_CODE_max_chars must be less than PEL_LOC_CODE_SIZE to account for the null
            // terminator.
            static_assert(ATTR_STATIC_ABS_LOCATION_CODE_max_chars < PEL_LOC_CODE_SIZE,
                         "ATTR_STATIC_ABS_LOCATION_CODE is too large to fit inside FRU callout location code section.");

            UTIL::tryGetAttributeInHierarchy<ATTR_STATIC_ABS_LOCATION_CODE>(i_target, static_abs_location_code);

            full_location_code.insert(end(full_location_code),
                                      static_abs_location_code,
                                      static_abs_location_code + strlen(static_abs_location_code));
        }

        // Add the null terminator
        full_location_code.push_back('\0');

        // By setting the location code, part number, serial number, and CCIN using set_errl_string it ensures that the
        // size constraints given by the PEL spec are respected. That means that if any of those strings go over the
        // size then the remaining right half of characters are truncated and will not appear in the error log.
        set_errl_string(l_fruco.locationCode, full_location_code.data());

        // Spec requires the location code and size to be a multiple of 4 bytes (padded with NULLs). The location code
        // member was zero intialized so all that's necessary to follow spec is to allign the size by 4.
        l_fruco.locCodeLen = ALIGN_4(full_location_code.size());

        // Part Number
        ATTR_PART_NUMBER_type l_partnum { };
        UTIL::tryGetAttributeInHierarchy<ATTR_PART_NUMBER>(i_target, l_partnum);
        // Set part number truncating as necessary.
        set_errl_string(l_fruco.partNumber,
                        reinterpret_cast<const char*>(l_partnum));

        // CCIN
        ATTR_FRU_CCIN_type l_ccin { };
        UTIL::tryGetAttributeInHierarchy<ATTR_FRU_CCIN>(i_target, l_ccin);
        // Set CCIN truncating as necessary.
        set_errl_string(l_fruco.ccin,
                        reinterpret_cast<const char*>(&l_ccin),
                        false);

        // Serial Number
        ATTR_SERIAL_NUMBER_type l_serialnumber { };
        UTIL::tryGetAttributeInHierarchy<ATTR_SERIAL_NUMBER>(i_target, l_serialnumber);
        // Set serial number truncating as necessary.
        set_errl_string(l_fruco.serialNumber,
                        reinterpret_cast<const char*>(l_serialnumber),
                        false);

        // Type
        l_fruco.fruCompType = static_cast<uint8_t>(i_compType)
                            | static_cast<uint8_t>(FAILING_COMP_TYPE_FRU_PN)
                            | static_cast<uint8_t>(FAILING_COMP_TYPE_FRU_CCIN)
                            | static_cast<uint8_t>(FAILING_COMP_TYPE_FRU_SN);

        // Add fruco to the src vector
        iv_Src.addFruCallout(l_fruco);
        break;
    }
    case(FAILING_COMP_TYPE_MAINT):
    {
        // Type
        l_fruco.fruCompType = static_cast<uint8_t>(i_compType)
                            | static_cast<uint8_t>(FAILING_COMP_TYPE_FRU_PRC);

        // No location code supplied for this callout.
        l_fruco.locCodeLen = 0;

        // Get the corresponding HBxxxxx isolation procedure code from the map of epubProcedureIDs.
        auto procedureIdMapIterator = std::lower_bound(EPUB_TO_ISOLATION_PROCEDURE.cbegin(),
                                                       EPUB_TO_ISOLATION_PROCEDURE.cend(),
                                                       i_procedure_id,
                                                       [](const epubProcedureToIsolationProcedure_t& procedureEntry,
                                                          const epubProcedureID id)
                                                       {
                                                          return procedureEntry.epub_procedure_id < id;
                                                       });
        // lower_bound can return a match greater than the desired procedure id we're looking for, double check that
        // didn't happen.
        if ((procedureIdMapIterator != EPUB_TO_ISOLATION_PROCEDURE.cend())
                && (procedureIdMapIterator->epub_procedure_id == i_procedure_id))
        {
            // Set the part number for this fru callout to be the HBxxxxx code. This is a shared field for part numbers
            // and procedure ids.
            set_errl_string(l_fruco.partNumber,
                            reinterpret_cast<const char *>(procedureIdMapIterator->isolationProcedure));

            // Add fruco to the src vector
            iv_Src.addFruCallout(l_fruco);
        }
        else
        {
            // This shouldn't happen as long as the epub procedure id map is sorted, and remains up-to-date with the
            // epubProcedureID enum in hwasCallout.H. If for an unforeseen reason this path is hit, emit a trace and
            // move on.
            TRACFCOMP(g_trac_errl, ERR_MRK"addFruCalloutDataToSrc(): Couldn't find epubProcedureId 0x%X in "
                      "EPUB_TO_ISOLATION_PROCEDURE map. Unable to add callout to SRC",
                      i_procedure_id);
        }


        break;
    }
    case(FAILING_COMP_TYPE_CODE):
    case(FAILING_COMP_TYPE_CNFG_ERR):
    case(FAILING_COMP_TYPE_EXTERN_FRU):
    case(FAILING_COMP_TYPE_EXTERN_CODE):
    case(FAILING_COMP_TYPE_TOOL_FRU):
    case(FAILING_COMP_TYPE_SYMBOLIC_FRU):
    case(FAILING_COMP_TYPE_SYMBOLIC_FRU_LOC):
    case(FAILING_COMP_TYPE_RESERVED_MIN_VAL):
    case(FAILING_COMP_TYPE_RESERVED_MAX_VAL):
    {
        // Unused
        break;
    }
    } // switch(i_compType)
}
#endif

} // End namespace
