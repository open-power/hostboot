/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/bus_training/pbusLinkSvc.H $                 */
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
 *  @file pbusLinkSvc.H
 *
 *  Singleton service to provide validation of pbus connections and
 *  return validated valid connections
 *
 */

#ifndef __PBUSLINKSVC_H
#define __PBUSLINKSVC_H

#include    <stdint.h>
#include    <util/singleton.H>
#include    <map>

#include    <errl/errlentry.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

//  fapi support
#include    <fapi.H>

namespace   EDI_EI_INITIALIZATION
{

using   namespace   TARGETING;
using   namespace   fapi;

typedef std::map<const TARGETING::Target*,
                 const TARGETING::Target*> TargetPairs_t;

class PbusLinkSvc
{

public:

    /**
     * @brief Get singleton instance of this class.
     *
     *  @return the (one and only) instance of PbusLinkSvc
     */
    static PbusLinkSvc& getTheInstance();

    /**
     * @brief getPbusConnections() will collect all pbus connections of
     *        the specified bus type. If this is the first time collection,
     *        it will perform the collection and save them into the vectors
     *        within the singleton. Then, it will make a copy into the
     *        caller's map whose reference is passed to this function.
     *  
     * @parm[out] o_PbusConnections, reference of a map for getting a copy
     *            of the map of specified bus connections
     * @parm[in]  i_busType, type of bus connection, TYPE_XBUS or TYPE_ABUS
     * @parm[in]  i_noDuplicate, set to true to eliminate duplicates, i.e.
     *            only (endpoint1,endpoint2) or (endpoint2,endpoint1) will
     *            be in the present in the map
     * @return    errlHndl_t if encountering an error, or NULL (no error)
     *  
     */

    errlHndl_t getPbusConnections( TargetPairs_t & o_PbusConnections,
                             TYPE i_busType,  bool i_noDuplicate = true );

protected:
    /**
     * @brief Constructor for the PbusLinkSvc object.
     */
    PbusLinkSvc();

    /**
     * @brief Destructor for the PbusLinkSvc object.
     */
    ~PbusLinkSvc();

private:
    /**
     * @note   Disable copy constructor and assignment operator
     */
    PbusLinkSvc(const PbusLinkSvc& i_right);
    PbusLinkSvc& operator=(const PbusLinkSvc& i_right);

    TargetPairs_t iv_abusUniqueConnections;
    TargetPairs_t iv_abusConnections;
    TargetPairs_t iv_xbusUniqueConnections;
    TargetPairs_t iv_xbusConnections;

    // Mutex serializing changes to the above four maps
    mutex_t iv_mutex;

    /**
     * @brief collectPbusConections() will collect all pbus connections of
     *        the specified bus type. It checks for mixed-type connection,
     *        conflicting connection, and invalid-same-chip connection.
     *        The connections are saved within the singleton.
     *  
     * @parm[in]  i_busType, type of bus connection, TYPE_XBUS or TYPE_ABUS
     * @return    errlHndl_t if encountering an error, or NULL (no error)
     *
     */
    errlHndl_t collectPbusConections( TYPE i_busType );

};

}

#endif
