/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodDrawer.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef TODDRAWER_H
#define TODDRAWER_H

/**
 *  @file TodDrawer.H
 *
 *  @brief Contains TodDrawer class declaration
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include "TodProc.H"

namespace TOD
{

class TodDrawer;  // forward declaration
typedef std::list<TodDrawer*> TodDrawerContainer;

/**
 * @class TodDrawer
 *
 * @brief TodDrawer class provides a grouping of the TodProc objects
 *     that belong to a particular TOD drawer. Each processor chip belonging
 *     to a specific TOD drawer connect over X bus and inter TOD drawer
 *     connection is over A bus.Concept of TOD drawer is analogous
 *     to fabric node on the system.
 *
 *     TOD drawers fall under two categories,master TOD drawer and slave
 *     TOD drawers. Master TOD drawer is the one on which MDMT sits, all
 *     the remaining TOD drawers are designated as slave drawers.
 *
 *     MDMT should drive TOD signals to other processors on the master
 *     TOD drawer over X buses and to one  processor on each slave drawer over
 *     A bus ( This processor is designated as MDST ).
 *     MDST is responsible for driving the TOD signals to the remaining
 *     processors on slave drawer.
 */
class  TodDrawer
{
public:
    /**
     * @brief Constructor for the TodDrawer object
     *
     * @param[in] i_drawerId
     *     this TOD drawer's id, it is nothing but the fabric node id attribute
     *     of the processors that belong to a fabric node type
     *
     * @param[in] i_parentNode
     *     container node's target
     */
    TodDrawer(const uint8_t i_drawerId,
                  const TARGETING::Target* i_parentNode);

    /**
     * @brief Destructor for the TodDrawer object.
     *
     * @par Detailed Description:
     *     Will destroy all HwsvTodProc objects that were added to this TOD
     *     drawer.
     */
    ~TodDrawer();

    /**
     * @brief This method will return the TodProc object that is either a
     *     TOD master or Drawer Master
     *
     * @par Detailed Description:
     *     While creating the topology MDMT and MDST should be wired to the
     *     other processors on that TOD drawer over X buses.
     *     TodTopologyManager will use this method to determine which
     *     processor is the master for that drawer.
     *     The method will go over the iv_todProcList and return the processor
     *     that is marked as TodProc::TOD_MASTER or TodProc::DRAWER_MASTER
     *
     * @param[out] o_drawerMaster
     *     It will be set to master processor's address if master processor is
     *     successfully found.
     *     In case the master processor could not be found successfully
     *     o_drawerMaster will be set to NULL, and error handle will be retured.
     *
     * @return Error log handle, indicates status of request
     * @retval NULL indicates that master processor was successfully found
     * @retval !NULL indicates that the master processor could not be found
     *     successfully. The only possible reason for returning NULL can be
     *     that this method was called out of sequence i.e even before
     *     TodTopologyManager designated a processor on a given TOD drawer as
     *     master for that drawer.
     *
     *     Error log handle points to a valid error log object whose primary
     *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
     *     of error.
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */
     errlHndl_t findMasterProc(TodProc*& o_drawerMaster) const;

    /**
     * @brief This method will determine the processor that has maximum number
     *     functional cores among the list of processor owned by the TOD drawer
     *     object
     *
     * @par Detailed Description:
     *     For creation of topology , first task is to choose the MDMT. One of
     *     the criteria for choosing MDMT is that it should be the processor
     *     with maximum number of functional cores.
     *     This method will serve as a a helper for pickMdmt, to determine
     *     which processor in the TOD drawer has maximum number of functional
     *     cores
     *
     * @param[in] i_procToIgnore , The TodProc object to be ignored while
     *    choosing desired proc. This is the case when there is existing MDMT
     *    for primar/secondary topology and MDMT has to be chosen for the
     *    other topology, peviously chosen MDMT should be avoided.
     *
     * @param[out] o_pTodProc, It will carry back pointer to the HwsvTodProc
     *    object that has the maximum number of cores.
     *    In the unlikely case of TOD drawer not having any processor with
     *    functional cores, this parameter will be set to NULL
     *
     * @param[out] o_coreCount, This will carry back the no. of cores that was
     *    found on processor with max functional core count. In case o_pTodProc
     *    is set to NULL this will be zero.
     *
     * @return N/A
     */
    void getProcWithMaxCores(
           const TodProc * i_procToIgnore,
           TodProc *& o_pTodProc,
           uint32_t& o_coreCount)const;

    /**
     * @brief Getter method for iv_todProcList
     *
     * @param[out] o_procList
     *     Parameter in which iv_todProcList  will be returned
     *
     * @return N/A
     */
    const TodProcContainer& getProcs() const
    {
        return iv_todProcList;
    }

    /**
     * @brief setter method for iv_isTodMaster
     *
     * @param[in] i_masterTodDrawer
     *     true/false, indicating whether this TOD drawer is a master or not
     *
     * @return N/A
     */
    void setMasterDrawer(const bool i_masterTodDrawer)
    {
        iv_isTodMaster = i_masterTodDrawer;
    }

    /**
     * @brief Adds a processor to this TOD drawer
     *
     * @param[in] i_proc
     *    A VTodProc pointer correspnding to the proc to be added
     *
     * @return N/A
     */
    void addProc(TodProc* i_proc)
    {
        iv_todProcList.push_back(i_proc);
    }

    /**
     * @brief Get this TOD drawer's id (this will be
     *     the corresponding fabric node's id)
     *
     * @return TOD drawer's id
     * @retval corresponding fabric node's id
     */
    TARGETING::ATTR_FABRIC_NODE_ID_type getId() const
    {
        return iv_todDrawerId;
    }

    /**
     * @brief Checks if this TOD drawer is a master drawer for the system.
     *      The master status of TOD drawer is contained in iv_isTodMaster.
     *
     * @return bool value, it will be true if this TOD drawer is a master drawer
     *     ,false otherwise
     */
    bool isMaster() const
    {
        return iv_isTodMaster;
    }

    /**
     * @brief Returns the containing node's target
     *
     * @return Target pointer
     */
    const TARGETING::Target* getParentNodeTarget() const
    {
        return iv_parentNodeTarget;
    }

private:
    //List of TodProc objects that belongs to TodDrawer instance
    TodProcContainer iv_todProcList;

    //TOD drawer id, the value of this attribute will be derived from
    //ATTR_FABRIC_NODE_ID attribute of the processors that belong to this
    //TOD drawer, all the processors belonging to this TOD drawer will share
    //the same value for ATTR_FABRIC_NODE_ID
    TARGETING::ATTR_FABRIC_NODE_ID_type iv_todDrawerId;

    //This data member will identify if the current drawer is a Tod master
    bool iv_isTodMaster;

    //Target pointer of the node to which TodDrawer belongs
    const TARGETING::Target * iv_parentNodeTarget;
};

} //end of namespace

#endif //TODDRAWER_H
