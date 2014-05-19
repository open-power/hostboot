/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errlentry.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <hbotcompid.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludbacktrace.H>
#include <errl/errludcallout.H>
#include <errl/errlreasoncodes.H>
#include <errl/errludstring.H>
#include <trace/interface.H>
#include <arch/ppc.H>
#include <hwas/common/hwasCallout.H>
#include <hwas/common/deconfigGard.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>


// Hostboot Image ID string
extern char hbi_ImageId;

using namespace ERRORLOG;
using namespace HWAS;

struct epubProcToSub_t
{
    epubProcedureID xProc;
    epubSubSystem_t xSubSys;

};
// Procedure to subsystem table.
static const epubProcToSub_t PROCEDURE_TO_SUBSYS_TABLE[] =
{
    { EPUB_PRC_FIND_DECONFIGURED_PART , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_SP_CODE                , EPUB_FIRMWARE_SP            },
    { EPUB_PRC_PHYP_CODE              , EPUB_FIRMWARE_PHYP          },
    { EPUB_PRC_ALL_PROCS              , EPUB_PROCESSOR_SUBSYS       },
    { EPUB_PRC_ALL_MEMCRDS            , EPUB_MEMORY_SUBSYS          },
    { EPUB_PRC_INVALID_PART           , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_LVL_SUPP               , EPUB_MISC_SUBSYS            },
    { EPUB_PRC_PROCPATH               , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_NO_VPD_FOR_FRU         , EPUB_CEC_HDW_VPD_INTF       },
    { EPUB_PRC_MEMORY_PLUGGING_ERROR  , EPUB_MEMORY_SUBSYS          },
    { EPUB_PRC_FSI_PATH               , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_PROC_AB_BUS            , EPUB_PROCESSOR_BUS_CTL      },
    { EPUB_PRC_PROC_XYZ_BUS           , EPUB_PROCESSOR_BUS_CTL      },
    { EPUB_PRC_MEMBUS_ERROR           , EPUB_MEMORY_SUBSYS          },
    { EPUB_PRC_EIBUS_ERROR            , EPUB_CEC_HDW_SUBSYS         },
    { EPUB_PRC_POWER_ERROR            , EPUB_POWER_SUBSYS           },
    { EPUB_PRC_PERFORMANCE_DEGRADED   , EPUB_MISC_SUBSYS            },
    { EPUB_PRC_HB_CODE                , EPUB_FIRMWARE_HOSTBOOT      },
};

struct epubTargetTypeToSub_t
{
    TARGETING::TYPE     xType;
    epubSubSystem_t     xSubSys;
};
// Target type to subsystem table.
static const epubTargetTypeToSub_t TARGET_TO_SUBSYS_TABLE[] =
{
    { TARGETING::TYPE_DIMM             , EPUB_MEMORY_DIMM          },
    { TARGETING::TYPE_MEMBUF           , EPUB_MEMORY_SUBSYS        },
    { TARGETING::TYPE_PROC             , EPUB_PROCESSOR_SUBSYS     },
    { TARGETING::TYPE_EX               , EPUB_PROCESSOR_UNIT       },
    { TARGETING::TYPE_L4               , EPUB_MEMORY_SUBSYS        },
    { TARGETING::TYPE_MCS              , EPUB_MEMORY_CONTROLLER    },
    { TARGETING::TYPE_MBA              , EPUB_MEMORY_CONTROLLER    },
    { TARGETING::TYPE_XBUS             , EPUB_PROCESSOR_BUS_CTL    },
    { TARGETING::TYPE_ABUS             , EPUB_PROCESSOR_SUBSYS     },
};

struct epubBusTypeToSub_t
{
    HWAS::busTypeEnum xType;
    epubSubSystem_t   xSubSys;
};
// Bus type to subsystem table
static const epubBusTypeToSub_t BUS_TO_SUBSYS_TABLE[] =
{
    { HWAS::FSI_BUS_TYPE               , EPUB_CEC_HDW_CHIP_INTF    },
    { HWAS::DMI_BUS_TYPE               , EPUB_MEMORY_BUS           },
    { HWAS::A_BUS_TYPE                 , EPUB_PROCESSOR_BUS_CTL    },
    { HWAS::X_BUS_TYPE                 , EPUB_PROCESSOR_BUS_CTL    },
    { HWAS::I2C_BUS_TYPE               , EPUB_CEC_HDW_I2C_DEVS     },
    { HWAS::PSI_BUS_TYPE               , EPUB_CEC_HDW_SP_PHYP_INTF },
};

struct epubClockTypeToSub_t
{
    HWAS::clockTypeEnum xType;
    epubSubSystem_t     xSubSys;
};
// Clock type to subsystem table
static const epubClockTypeToSub_t CLOCK_TO_SUBSYS_TABLE[] =
{
    { HWAS::TODCLK_TYPE                , EPUB_CEC_HDW_TOD_HDW },
    { HWAS::MEMCLK_TYPE                , EPUB_CEC_HDW_CLK_CTL },
    { HWAS::OSCREFCLK_TYPE             , EPUB_CEC_HDW_CLK_CTL },
    { HWAS::OSCPCICLK_TYPE             , EPUB_CEC_HDW_CLK_CTL },
};

namespace ERRORLOG
{

// Trace definition
trace_desc_t* g_trac_errl = NULL;
TRAC_INIT(&g_trac_errl, "ERRL", KILOBYTE, TRACE::BUFFER_SLOW);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlEntry::ErrlEntry(const errlSeverity_t i_sev,
                     const uint8_t i_modId,
                     const uint16_t i_reasonCode,
                     const uint64_t i_user1,
                     const uint64_t i_user2,
                     const bool i_hbSwError ) :
    iv_Private( static_cast<compId_t>(i_reasonCode & 0xFF00)),
    iv_User( i_sev ),
    // The SRC_ERR_INFO becomes part of the SRC; example, B1 in SRC B180xxxx
    // iv_Src assigns the epubSubSystem_t; example, 80 in SRC B180xxxx
    iv_Src( SRC_ERR_INFO, i_modId, i_reasonCode, i_user1, i_user2 ),
    iv_termState(TERM_STATE_UNKNOWN),
    iv_sevFinal(false)
{
    TRACFCOMP( g_trac_errl, ERR_MRK"Error created : PLID=%.8X, RC=%.4X, Mod=%.2X, Userdata=%.16X %.16X", plid(), i_reasonCode, i_modId, i_user1, i_user2 );
    // Collect the Backtrace and add it to the error log
    iv_pBackTrace = new ErrlUserDetailsBackTrace();
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

// Use these to tag the UD section containing the trace.
const int FIPS_ERRL_UDT_TRACE              = 0x0c;
const int FIPS_ERRL_UDV_DEFAULT_VER_1      = 1;

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
                                           FIPS_ERRL_UDT_TRACE );

        // Add the trace section to the vector of sections
        // for this error log.
        iv_SectionVector.push_back( l_udSection );

        l_rc = true;
    }
    while(0);

    delete[] l_pBuffer;

    return l_rc;
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::removeBackTrace()
{
    delete iv_pBackTrace;
    iv_pBackTrace = NULL;
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

    TARGETING::EntityPath ep;
    const void *pData;
    uint32_t size;

    if (i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        size = sizeof(HWAS::TARGET_IS_SENTINEL);
        pData = &HWAS::TARGET_IS_SENTINEL;
    }
    else
    {   // we got a non MASTER_SENTINEL target, therefore the targeting
        // module is loaded, therefore we can make this call.
        ep = i_target->getAttr<TARGETING::ATTR_PHYS_PATH>();
        // size is total EntityPath size minus unused path elements
        size = sizeof(ep) -
                    (TARGETING::EntityPath::MAX_PATH_ELEMENTS - ep.size()) *
                        sizeof(TARGETING::EntityPath::PathElement);
        pData = &ep;
    }

    ErrlUserDetailsCallout( pData, size, i_clockType,
            i_priority, i_deconfigState, i_gardErrorType).addToLog(this);

    if (i_gardErrorType != GARD_NULL)
    {
        setGardBit();
    }
    if (i_deconfigState != NO_DECONFIG)
    {
        setDeconfigBit();
    }

} // addClockCallout


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addBusCallout(const TARGETING::Target *i_target_endp1,
                        const TARGETING::Target *i_target_endp2,
                        const HWAS::busTypeEnum i_busType,
                        const HWAS::callOutPriority i_priority)
{
    TRACFCOMP(g_trac_errl, ENTER_MRK"addBusCallout(%p, %p, %d, 0x%x)",
                i_target_endp1, i_target_endp2, i_busType, i_priority);

    TARGETING::EntityPath ep1, ep2;
    const void *pData1, *pData2;
    uint32_t size1, size2;

    if (i_target_endp1 == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        size1 = sizeof(HWAS::TARGET_IS_SENTINEL);
        pData1 = &HWAS::TARGET_IS_SENTINEL;
    }
    else
    {   // we got a non MASTER_SENTINEL target, therefore the targeting
        // module is loaded, therefore we can make this call.
        ep1 = i_target_endp1->getAttr<TARGETING::ATTR_PHYS_PATH>();
        // size is total EntityPath size minus unused path elements
        size1 = sizeof(ep1) -
                    (TARGETING::EntityPath::MAX_PATH_ELEMENTS - ep1.size()) *
                        sizeof(TARGETING::EntityPath::PathElement);
        pData1 = &ep1;
    }

    if (i_target_endp2 == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        size2 = sizeof(HWAS::TARGET_IS_SENTINEL);
        pData2 = &HWAS::TARGET_IS_SENTINEL;
    }
    else
    {   // we got a non MASTER_SENTINEL target, therefore the targeting
        // module is loaded, therefore we can make this call.
        ep2 = i_target_endp2->getAttr<TARGETING::ATTR_PHYS_PATH>();
        // size is total EntityPath size minus unused path elements
        size2 = sizeof(ep2) -
                    (TARGETING::EntityPath::MAX_PATH_ELEMENTS - ep2.size()) *
                        sizeof(TARGETING::EntityPath::PathElement);
        pData2 = &ep2;
    }

    ErrlUserDetailsCallout( pData1, size1, pData2, size2, i_busType,
                            i_priority).addToLog(this);

} // addBusCallout


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addHwCallout(const TARGETING::Target *i_target,
                        const HWAS::callOutPriority i_priority,
                        const HWAS::DeconfigEnum i_deconfigState,
                        const HWAS::GARD_ErrorType i_gardErrorType)
{

    if (i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    {
        TRACFCOMP(g_trac_errl, ENTER_MRK
                "addHwCallout(\"MASTER_PROC_SENTINEL\" 0x%x 0x%x 0x%x)",
                i_target, i_priority, i_deconfigState, i_gardErrorType);
        ErrlUserDetailsCallout(
                &HWAS::TARGET_IS_SENTINEL, sizeof(HWAS::TARGET_IS_SENTINEL),
                i_priority, i_deconfigState, i_gardErrorType).addToLog(this);
    }
    else
    {   // we got a non MASTER_SENTINEL target, therefore the targeting
        // module is loaded, therefore we can make this call.
        TRACFCOMP(g_trac_errl, ENTER_MRK"addHwCallout(0x%.8x 0x%x 0x%x 0x%x)",
                get_huid(i_target), i_priority,
                i_deconfigState, i_gardErrorType);

        TARGETING::EntityPath ep;
        TARGETING::TYPE l_type = i_target->getAttr<TARGETING::ATTR_TYPE>();
        if (l_type == TARGETING::TYPE_CORE)
        {
            //IF the type being garded is a Core the associated EX Chiplet
            //  needs to be found and garded instead because the core is
            //  not gardable
            TRACFCOMP(g_trac_errl, INFO_MRK
                "addHwCallout - Callout on Core type, use EX Chiplet instead"
                " because Core is not gardable");
            TARGETING::TargetHandleList targetList;
            getParentAffinityTargets(targetList,
                                     i_target,
                                     TARGETING::CLASS_UNIT,
                                     TARGETING::TYPE_EX);
            if ( targetList.size() != 1 )
            {
                TRACFCOMP(g_trac_errl, ERR_MRK
                    "addHwCallout - Found No EX Chiplet for this Core");

                //Just use the the Core itself in the gard operation
                ep = i_target->getAttr<TARGETING::ATTR_PHYS_PATH>();

                /*@     errorlog tag
                *  @errortype      ERRL_SEV_UNRECOVERABLE
                *  @moduleid       ERRL_ADD_HW_CALLOUT_ID
                *  @reasoncode     ERRL_CORE_EX_TARGET_NULL
                *  @userdata1      Core HUID that has bad EX association
                *  @userdata2      Number of EX chips associatd with core
                *
                *  @devdesc        Hardware callout could not Gard target
                *                  because it could not find EX chip
                *                  associated with the Core to be called out
                *
                */
                errlHndl_t l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ERRORLOG::ERRL_ADD_HW_CALLOUT_ID,
                                    ERRORLOG::ERRL_CORE_EX_TARGET_NULL,
                                    get_huid(i_target), targetList.size(),
                                    true);

                if (l_errl)
                {
                    errlCommit(l_errl, ERRL_COMP_ID);
                }

            }
            else
            {
                //Use the EX target found in below logic to gard
                ep = targetList[0]->getAttr<TARGETING::ATTR_PHYS_PATH>();
            }
        }
        else
        {
            ep = i_target->getAttr<TARGETING::ATTR_PHYS_PATH>();
        }

        // size is total EntityPath size minus unused path elements
        uint32_t size1 = sizeof(ep) -
                    (TARGETING::EntityPath::MAX_PATH_ELEMENTS - ep.size()) *
                        sizeof(TARGETING::EntityPath::PathElement);

        ErrlUserDetailsCallout(&ep, size1,
                i_priority, i_deconfigState, i_gardErrorType).addToLog(this);
    }
    if (i_gardErrorType != GARD_NULL)
    {
        setGardBit();
    }
    if (i_deconfigState != NO_DECONFIG)
    {
        setDeconfigBit();
    }
} // addHwCallout


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void ErrlEntry::addProcedureCallout(const HWAS::epubProcedureID i_procedure,
                            const HWAS::callOutPriority i_priority)
{
    TRACFCOMP( g_trac_errl, ENTER_MRK"addProcedureCallout(0x%x, 0x%x)",
                i_procedure, i_priority);

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

///////////////////////////////////////////////////////////////////////////////
// for use by ErrlManager
void ErrlEntry::commit( compId_t  i_committerComponent )
{
    // TODO RTC 35258 need a better timepiece, or else apply a transform onto
    // timebase for an approximation of real time.
    iv_Private.iv_committed = getTB();

    // User header contains the component ID of the committer.
    iv_User.setComponentId( i_committerComponent );

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

}

///////////////////////////////////////////////////////////////////////////////
// Function to set the correct subsystem ID based on callout priorities
void ErrlEntry::setSubSystemIdBasedOnCallouts()
{
    TRACFCOMP(g_trac_errl, INFO_MRK
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
            if( highestPriorityCallout == NULL ||
                  ( pData->priority > highestPriorityCallout->priority) )
            {
                highestPriorityCallout = pData;
            }
        }
    } // for each SectionVector

    // if this pointer is not null it will be pointing to the
    // highest priority entry
    if( highestPriorityCallout == NULL  )
    {
        // no callouts in log, add default callout for hb code and
        // add trace
        TRACFCOMP(g_trac_errl, "WRN>> No callouts in elog %.8X", eid());
        TRACFCOMP(g_trac_errl, "Adding default callout EPUB_PRC_HB_CODE ");
        addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_LOW);

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

                TRACFCOMP(g_trac_errl, INFO_MRK
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
            TRACFCOMP(g_trac_errl, INFO_MRK
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

    TRACFCOMP(g_trac_errl, INFO_MRK
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

    uint32_t TARGET_TO_SUBSYS_TABLE_ENTRIES =
                    sizeof(TARGET_TO_SUBSYS_TABLE)/
                    sizeof(TARGET_TO_SUBSYS_TABLE[0]);

    uint32_t low = 0;
    uint32_t high = TARGET_TO_SUBSYS_TABLE_ENTRIES - 1;
    uint32_t mid  = 0;

    while( low <= high )
    {
        mid = low + (( high - low)/2);

        if ( TARGET_TO_SUBSYS_TABLE[mid].xType > i_target )
        {
            high = mid -1;
        }
        else if ( TARGET_TO_SUBSYS_TABLE[mid].xType < i_target )
        {
            low = mid + 1;
        }
        else
        {
            // found it
           subsystem = TARGET_TO_SUBSYS_TABLE[mid].xSubSys;
           break;
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
// for use by ErrlManager
void ErrlEntry::processCallout()
{
    TRACFCOMP(g_trac_errl, INFO_MRK"errlEntry::processCallout");

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
        TRACFCOMP(g_trac_errl, INFO_MRK"hwas processCalloutFn not set!");
    }

    TRACFCOMP(g_trac_errl, INFO_MRK"errlEntry::processCallout returning");
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

    TRACFCOMP(g_trac_errl, INFO_MRK"errlEntry::deferredDeconfigure");

    // see if HWAS has been loaded and has set the processCallout function
    HWAS::processCalloutFn pFn =
            ERRORLOG::theErrlManager::instance().getHwasProcessCalloutFn();
    if (pFn != NULL)
    {
        //check for defered deconfigure callouts
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
                (HWAS::DELAYED_DECONFIG ==
                    reinterpret_cast<HWAS::callout_ud_t*>(
                        (*it)->iv_pData)->deconfigState)
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
        TRACFCOMP(g_trac_errl, INFO_MRK"hwas processCalloutFn not set!");
    }

    TRACFCOMP(g_trac_errl, INFO_MRK"errlEntry::deferredDeconfigure returning");
}


//////////////////////////////////////////////////////////////////////////////
// for use by ErrlManager

uint64_t ErrlEntry::flattenedSize()
{
    uint64_t l_bytecount = iv_Private.flatSize() +
                           iv_User.flatSize() +
                           iv_Src.flatSize();

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
        // counting the PH, UH, PS, and the optionals.
        iv_Private.iv_sctns = 3 + iv_SectionVector.size();

        // Flatten the PH private header section
        char * pBuffer = static_cast<char *>(o_pBuffer);
        l_cb = iv_Private.flatten( pBuffer, l_sizeRemaining );
        if( 0 == l_cb )
        {
            TRACFCOMP( g_trac_errl, ERR_MRK"ph.flatten error");
            l_flatSize = 0;
            // don't check i_truncate - this section MUST fit.
            break;
        }

        // save this location - if the number of sections that we flatten is
        // reduced, we need to update this PH section.
        char *pPHBuffer = pBuffer;

        pBuffer += l_cb;
        l_sizeRemaining -= l_cb;

        // flatten the UH user header section
        l_cb = iv_User.flatten( pBuffer,  l_sizeRemaining );
        if( 0 == l_cb )
        {
            TRACFCOMP( g_trac_errl, ERR_MRK"uh.flatten error");
            l_flatSize = 0;
            // don't check i_truncate - this section MUST fit.
            break;
        }
        pBuffer += l_cb;
        l_sizeRemaining -= l_cb;

        // flatten the PS primary SRC section
        l_cb = iv_Src.flatten( pBuffer, l_sizeRemaining );
        if( 0 == l_cb )
        {
            TRACFCOMP( g_trac_errl, ERR_MRK"ps.flatten error");
            l_flatSize = 0;
            // don't check i_truncate - this section MUST fit.
            break;
        }
        pBuffer += l_cb;
        l_sizeRemaining -= l_cb;


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
        uint32_t l_sectionCount = iv_SectionVector.size();

        std::vector<ErrlUD*>::const_iterator it;
        for(it = iv_SectionVector.begin();
            (it != iv_SectionVector.end()) && (l_flatSize != 0);
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
                        // won't fit - don't count it.
                        l_sectionCount--;
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
                pBuffer += l_cb;
                l_sizeRemaining -= l_cb;
            }
        } // for

        for(it = iv_SectionVector.begin();
            (it != iv_SectionVector.end()) && (l_flatSize != 0);
            it++)
        {
            // If UD section is not a hardware callout and not a trace.
            if( !(((ERRL_COMP_ID        == (*it)->iv_header.iv_compId) &&
                   (ERRL_UDT_CALLOUT    == (*it)->iv_header.iv_sst)) ||
                  ((FIPS_ERRL_COMP_ID   == (*it)->iv_header.iv_compId) &&
                   (FIPS_ERRL_UDT_TRACE == (*it)->iv_header.iv_sst))) )
            {
                l_cb = (*it)->flatten( pBuffer, l_sizeRemaining );
                if( 0 == l_cb )
                {
                    if (i_truncate)
                    {
                        // TODO: RTC 77560 - error if this happens during test
                        TRACFCOMP( g_trac_errl,
                                INFO_MRK"ud.flatten error, skipping");
                        // won't fit - don't count it.
                        l_sectionCount--;
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
                pBuffer += l_cb;
                l_sizeRemaining -= l_cb;
            }
        } // for

        for(it = iv_SectionVector.begin();
            (it != iv_SectionVector.end()) && (l_flatSize != 0);
            it++)
        {
            // If UD section is a trace.
            if( (FIPS_ERRL_COMP_ID   == (*it)->iv_header.iv_compId) &&
                (FIPS_ERRL_UDT_TRACE == (*it)->iv_header.iv_sst) )
            {
                l_cb = (*it)->flatten( pBuffer, l_sizeRemaining );
                if( 0 == l_cb )
                {
                    if (i_truncate)
                    {
                        // TODO: RTC 77560 - error if this happens during test
                        TRACFCOMP( g_trac_errl,
                                INFO_MRK"ud.flatten error, skipping");
                        // won't fit - don't count it.
                        l_sectionCount--;
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
                pBuffer += l_cb;
                l_sizeRemaining -= l_cb;
            }
        } // for

        if( 0 == l_flatSize )
        {
          break;
        }

        if (l_sectionCount != iv_SectionVector.size())
        {
            // some section was too big and didn't get flatten - update the
            // section count in the PH section and re-flatten it.
            iv_Private.iv_sctns = 3 + l_sectionCount;
            l_cb = iv_Private.flatten( pPHBuffer, l_sizeRemaining );
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

    TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten private section...");
    bytes_used = iv_Private.unflatten(l_buf);
    consumed    += bytes_used;
    l_buf       += bytes_used;

    TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten User header section...");
    bytes_used = iv_User.unflatten(l_buf);
    consumed    += bytes_used;
    l_buf       += bytes_used;

    TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten SRC section...");
    bytes_used = iv_Src.unflatten(l_buf);
    consumed    += bytes_used;
    l_buf       += bytes_used;

    iv_SectionVector.clear();
    iv_btAddrs.clear();
    removeBackTrace();

    while(consumed < i_len)
    {
        TRACDCOMP(g_trac_errl, INFO_MRK"Unflatten User data section...");
        const ERRORLOG::pelSectionHeader_t * p =
            reinterpret_cast<const ERRORLOG::pelSectionHeader_t *>(l_buf);

        if(p->sid != ERRORLOG::ERRL_SID_USER_DEFINED) // 'UD'
        {
            // yikes - bad section
            TRACFCOMP(g_trac_errl, ERR_MRK"Bad UserData section found while "
                      "importing flattened data into error log. plid=%08x",
                      iv_Private.iv_plid);
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

    return rc;
}

} // End namespace

