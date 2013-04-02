/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/namedtarget.C $                             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
/**
 *  @file namedtarget.C
 *
 *  hostBoot - specific filters.   This was removed from ../common because
 *  that source is also compiled into the fsp.
 *
 */

//******************************************************************************
// Includes
//******************************************************************************
#include <targeting/common/commontargeting.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/trace.H>
#include <attributeenums.H>
#include <targeting/common/iterators/rangefilter.H>
#include <targeting/common/predicates/predicateisfunctional.H>
#include <targeting/common/predicates/predicatepostfixexpr.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>

#include <sys/task.h>           // task_getcpuid()


/**
 * Miscellaneous Filter Utility Functions
 */

namespace TARGETING
{

const TARGETING::Target *   getMasterCore( )
{
    uint64_t l_masterCoreID                     =   task_getcpuid() & ~7;
    const   TARGETING::Target * l_masterCore    =   NULL;

    TARGETING::Target * l_processor =   NULL;
    (void)TARGETING::targetService().masterProcChipTargetHandle( l_processor );
    FABRIC_NODE_ID_ATTR l_logicalNodeId =
                l_processor->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();
    FABRIC_CHIP_ID_ATTR l_chipId =
                l_processor->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();

    TargetHandleList l_cores;
    getChildChiplets( l_cores,
                      l_processor,
                      TYPE_CORE,
                      true );

    TRACDCOMP( g_trac_targeting,
               "getMasterCore: found %d cores on master proc, l_mastreCoreID:0x%X",
               l_cores.size(),l_masterCoreID   );

    for (TARGETING::TargetHandleList::const_iterator
            coreIter = l_cores.begin();
            coreIter != l_cores.end();
            ++coreIter)
    {
        TARGETING::Target * l_core = *coreIter;

        CHIP_UNIT_ATTR l_coreId =
                    l_core->getAttr<TARGETING::ATTR_CHIP_UNIT>();

        uint64_t pir = l_coreId << 3;
        pir |= l_chipId << 7;
        pir |= l_logicalNodeId << 10;

        if (pir == l_masterCoreID){
            TRACFCOMP( g_trac_targeting,
                       "found master core: 0x%x, PIR=0x%x :",
                       l_coreId,
                       pir  );
            EntityPath l_path;
            l_path  =   l_core->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            l_masterCore    =   l_core ;
            break;
        }

    }   // endfor

    return l_masterCore;
}

};  // end namespace
