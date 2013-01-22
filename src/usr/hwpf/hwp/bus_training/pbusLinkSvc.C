/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/pbusLinkSvc.C $                 */
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
#include    "pbusLinkSvc.H"
#include    <hwpf/hwpf_reasoncodes.H>

namespace   EDI_EI_INITIALIZATION
{

using   namespace   TARGETING;
using   namespace   fapi;

PbusLinkSvc & PbusLinkSvc::getTheInstance()
{
    return Singleton<PbusLinkSvc>::instance();
}

PbusLinkSvc::PbusLinkSvc()
{
    mutex_init(&iv_mutex);
}

PbusLinkSvc::~PbusLinkSvc()
{
    mutex_destroy(&iv_mutex);
}

errlHndl_t PbusLinkSvc::getPbusConnections( TargetPairs_t & o_PbusConnections,
                                         TYPE i_busType, bool i_noDuplicate )
{
    errlHndl_t l_errl = NULL;
    TargetPairs_t * l_PbusConnections = NULL;
    o_PbusConnections.clear();

    mutex_lock(&iv_mutex);

    if (i_busType == TYPE_ABUS)
    {
        if (iv_abusConnections.size() == 0)
        {
            l_errl = collectPbusConections( TYPE_ABUS );
        }
        if (l_errl == NULL)
        {
            l_PbusConnections = i_noDuplicate ? &iv_abusUniqueConnections :
                                            &iv_abusConnections;
        }
    }
    else
    {
        if (iv_xbusConnections.size() == 0)
        {
            l_errl = collectPbusConections( TYPE_XBUS );
        }
        if (l_errl == NULL)
        {
            l_PbusConnections = i_noDuplicate ? &iv_xbusUniqueConnections :
                                            &iv_xbusConnections;
        }
    }

    o_PbusConnections.insert( (*l_PbusConnections).begin(),
                                      (*l_PbusConnections).end() );

    mutex_unlock(&iv_mutex);

    return l_errl;
}


errlHndl_t PbusLinkSvc::collectPbusConections( TYPE i_busType )
{
    errlHndl_t l_errl = NULL;

    // Get all functional i_busType chiplets
    TARGETING::TargetHandleList l_busTargetList;
    getAllChiplets(l_busTargetList, i_busType);

    // select the appropriate maps to work with
    TargetPairs_t & l_PbusConnections = (i_busType == TYPE_ABUS) ?
                                      iv_abusConnections : iv_xbusConnections;
    TargetPairs_t & l_PbusUniqueConnections = (i_busType == TYPE_ABUS) ?
                          iv_abusUniqueConnections : iv_xbusUniqueConnections;

    // Collect all functional i_busType pbus connections
    for (TargetHandleList::iterator l_bus_iter = l_busTargetList.begin();
            (l_errl == NULL) && (l_bus_iter != l_busTargetList.end());
            ++l_bus_iter)
    {
        // get two endpoint targets
        const TARGETING::Target * l_pTarget = *l_bus_iter;
        const TARGETING::Target * l_dstTgt = 
                    l_pTarget->getAttr<ATTR_PEER_TARGET>();

        // connection is existing, not to itself and is a real target
        if ((l_dstTgt != NULL) && (l_dstTgt != l_pTarget))
        {
            TYPE l_dstType = l_dstTgt->getAttr<ATTR_TYPE>();
            if (l_dstType != i_busType)
            {
                TRACFCOMP(TARGETING::g_trac_targeting,
                    "Both endpoints' bus type mismatch; "
                    "target HUID %.8X dest HUID",
                    TARGETING::get_huid(l_pTarget),
                    TARGETING::get_huid(l_dstTgt));

                // Mixed bus type connection
                /**
                 * @errortype    ERRL_SEV_UNRECOVERABLE
                 * @moduleid     MOD_EDI_EI_IO_RUN_TRAINING
                 * @reasoncode   RC_MIXED_PBUS_CONNECTION
                 * @userdata1    Endpoint1 bus type
                 * @userdata2    Endpoint2 bus type
                 * @devdesc      Platform generated error. See User Data.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_EDI_EI_IO_RUN_TRAINING,
                                         RC_MIXED_PBUS_CONNECTION,
                                         i_busType,
                                         l_dstType );
                continue;
            }

            // Get the chip parents of endpoints
            const TARGETING::Target * l_endp1Parent = getParentChip(l_pTarget);
            const TARGETING::Target * l_endp2Parent = getParentChip(l_dstTgt);

            if (l_endp1Parent == l_endp2Parent)
            {
                TRACFCOMP(TARGETING::g_trac_targeting,
                    "Both endpoints from same chip; "
                    "target HUID %.8X dest HUID %.8X",
                    TARGETING::get_huid(l_pTarget),
                    TARGETING::get_huid(l_dstTgt));

                // connection of same chip
                /**
                 * @errortype    ERRL_SEV_UNRECOVERABLE
                 * @moduleid     MOD_EDI_EI_IO_RUN_TRAINING
                 * @reasoncode   RC_SAME_CHIP_PBUS_CONNECTION
                 * @devdesc      Platform generated error.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                                     ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     MOD_EDI_EI_IO_RUN_TRAINING,
                                     RC_SAME_CHIP_PBUS_CONNECTION );
                continue;
            }

            for (TargetHandleList::iterator l_dst_iter = l_busTargetList.begin();
                    l_dst_iter != l_busTargetList.end();
                    ++l_dst_iter)
            {
                // l_dstTgt is functional
                if (l_dstTgt == *l_dst_iter)
                {
                    // save the pair if not yet done so
                    l_PbusConnections[l_pTarget] = l_dstTgt;
                    l_PbusUniqueConnections[l_pTarget] = l_dstTgt;
                    break;
                }
            }
        }
    } // for l_bus_iter

    // Validate pbus connections are valid and strike out
    // duplicates for the Unique connection map
    TargetPairs_t::iterator l_itr, l_jtr;
    for (l_itr = l_PbusUniqueConnections.begin();
         (l_errl == NULL) && (l_itr != l_PbusUniqueConnections.end());
         ++l_itr)
    {
        const TARGETING::Target *l_ptr1 = l_itr->first;
        const TARGETING::Target *l_ptr2 = l_itr->second;
        l_jtr = l_PbusUniqueConnections.find(l_ptr2);
        if ((l_jtr == l_PbusUniqueConnections.end())
                                                 || (l_jtr->second != l_ptr1))
        {
            // Connection is conflicting, e.g.
            //   endp1 -> endp2 but endp2 -> endp3.
            //   endp1 -> endp2 but endp2 -> endp2 (itself) or not existing
            EntityPath l_path;
            l_path = l_itr->second->getAttr<ATTR_PHYS_PATH>();
            char *l_pathString = l_path.toString();
            TARG_ERR( "First endpoint's PEER_TARGET is %s", l_pathString );
            free (l_pathString);
            if (l_jtr != l_PbusUniqueConnections.end())
            {
                l_path = l_jtr->second->getAttr<ATTR_PHYS_PATH>();
                l_pathString = l_path.toString();
                TARG_ERR("Second endpoint's PEER_TARGET is %s", l_pathString);
                free (l_pathString);
            }
            else
            {
                if (l_ptr2)
                {
                    l_path = l_ptr2->getAttr<ATTR_PHYS_PATH>();
                    l_pathString = l_path.toString();
                    TARG_ERR("Second endpoint's PEER_TARGET is itself, %s",
                                                                l_pathString);
                    free (l_pathString);
                }
                else
                {
                    TARG_ERR("Second endpoint's PEER_TARGET is not existing");
                }
            }

            /**
             * @errortype    ERRL_SEV_UNRECOVERABLE
             * @moduleid     MOD_EDI_EI_IO_RUN_TRAINING
             * @reasoncode   RC_CONFLICT_PBUS_CONNECTION
             * @userdata1    Bus endpoint target pointer1
             * @userdata2    Bus endpoint target pointer2
             * @devdesc      Platform generated error. See User Data.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_EDI_EI_IO_RUN_TRAINING,
                                         RC_CONFLICT_PBUS_CONNECTION,
                                         reinterpret_cast<uint64_t>(l_ptr1),
                                         reinterpret_cast<uint64_t>(l_ptr2));
            break;
        }
        else
        {
            l_PbusUniqueConnections.erase(l_jtr);
        }
    }

    return l_errl;
}

}
