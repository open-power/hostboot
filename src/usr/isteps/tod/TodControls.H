/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/tod/TodControls.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
#ifndef TODCONTROLS_H
#define TODCONTROLS_H
/**
 *  @file TodControls.H
 *
 *  @brief Contains TodControls class declaration
 *      TodControls class will maintain the data structures required for
 *      creating/modifying TOD topologies
 */

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
//System Include

#include  <util/singleton.H>
#include  <vector>
#include "TodDrawer.H"
#include "TodProc.H"
#include "TodSvcUtil.H"
#include "TodAssert.H"
#include "TodTrace.H"
#include <isteps/tod/TodTypes.H>

namespace TOD
{

//------------------------------------------------------------------------------
//Forward declarations
//------------------------------------------------------------------------------
class TodDrawer;
class TodProc;
class TodControls;

//------------------------------------------------------------------------------
//Typedefs
//------------------------------------------------------------------------------
//Use "thesTodControls_t::Instance()" to access the singleton via reference
typedef Singleton<TodControls> theTodControls_t;
typedef std::vector<TARGETING::ConstTargetHandle_t>
    BlacListedProcContainer;
typedef std::vector<TARGETING::ConstTargetHandle_t>
    GardedProcContainer;
typedef std::vector<TARGETING::ATTR_HUID_type>
    GardedTargetsContainer;

//------------------------------------------------------------------------------
//Static globals
//------------------------------------------------------------------------------
//2 configs - primary/secondary
const static uint8_t TOD_NUM_CONFIGS = 2;
const uint32_t TOD_HUID_INVALID = 0xFFFFFFFF;
const uint32_t FSP_INVALID_RID = 0x0;

/**
 * @class TodControls
 *
 * @brief TOD topology tree will comprise of the interconnected processor chips.
 *     This class manages the objects representing proc chips (TodProc)
 *     that are available to be wired in TOD network.
 *     The proc chips are contained in one or more Tod drawers
 *     (TodDrawer).
 *     The class has data structures that represent this relationship and
 *     hence enable establishment of TOD topology.
 */
class TodControls
{
public:

    /**
     * @brief Get singleton instance of this class.
     *
     *  @return the (one and only) instance of TodControls
     */
    static TodControls& getTheInstance();

    /**
     * @brief TOD_CONFIG_STATE  enum will help to determine if there has been HW
     *   changes since the last time topology was created.
     *   i.e. new  functional processor has become available or one of the
     *   processor that was part of old TOD topology has become non-functional
     */
    enum TOD_CONFIG_STATE
    {
        TOD_UNCHANGED,     //No change in the HW
        TOD_MODIFIED,      //Either new HW is available or some of them have
                           //been deconfigured
        TOD_UNKNOWN,       //Failed to determine if there was any change in the
                           //HW based on old topology data
    };

    /**
     * @brief This method will build a list of functional TOD drawers
     *    available in the system
     *
     * @par Detailed Description:
     *    TOD drawers are represented by TodDrawer class, that
     *    basically provides a grouping of the TodProc objects such
     *    that processor chips beloning to a specific drawer connect
     *    over X bus and inter drawer connection is over A bus. TOD drawer
     *    is analogous to fabic node on the system.
     *
     *    On a TULETA system each DCM chip is a fabric node however on a
     *    Brazos they can be different physical nodes.
     *    Each proc chip has an arribute representing the fabric node
     *    to which it belongs.
     *
     *    The method will get all the functional proc chips on the system ,
     *    and then group them according to fabric nodes.
     *
     *    At the end of operation TOD topology infrastructure will either
     *    have iv_primTodDrawer or iv_secTodDrawerList completed with each
     *    drawer having a list of functional proc chips represented as
     *    TodProc pointers.
     *
     * @param[in] i_config
     *    Indicates the primary/secondary topology
     *
     * @return Error log handle indicating status of request.
     * @retval NULL indicates successful completion of operation
     * @retval !NULL indicates that the system doesn't have a TOD drawer,
     *     TOD topologies can't be created.
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
    errlHndl_t buildTodDrawers(const p10_tod_setup_tod_sel i_config);

    /**
     * @brief This method will pick MDMT chip for the configuration
     *     requested
     *
     * @par Detailed Description:
     *    MDMT is a processor chip that is chosen to receive signals from
     *    the oscillator and it drives TOD signals to the remaining
     *    processors on the system.
     *    The criteria for choosing MDMT on a processor are as follows
     *    1.Processor should be connected to the oscillator. ( This is
     *    invariably true for all processors on TULETA systems )
     *    2.Processor should be marked as functional in the targeting
     *    model.
     *    3.Among the possible candidates the one which is having maximum
     *    number of functional cores should be preferred.
     *
     *    Whenever possible the MDMT for the primary and secondary
     *    configurations should be located on different TOD drawers. In
     *    case of multi node systems, MDMT on secondary topology
     *    should be located on a TOD drawer that belongs to different
     *    node  as compared to the MDMT of primary configuration.  If it
     *    is not possible to locate the MDMTs on different TOD drawers,
     *    then different processor within the same TOD drawer should be
     *    preferred.
     *
     * @param[in] i_config
     *    Indicates the primary/secondary configuration for which the MDMT
     *    has to be picked
     *
     * @return Error log handle indicating the status of the request.
     * @retval NULL if successful
     * @retval !NULL if failed to pick the MDMT
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
     errlHndl_t pickMdmt(const p10_tod_setup_tod_sel i_config);

    /**
     * @brief Destroy information pertaining to topology type
     *     i_config and free up associated memory
     *
     * @param[in] i_config
     *    Indicates the primary/secondary topology
     *
     * @return N/A
     */
     void destroy(const p10_tod_setup_tod_sel i_config);

    /**
     * @brief Gets a list of TOD drawers for a specific
     *     topology
     *
     * @param[in] i_config
     *    Indicates the primary/secondary topology
     *
     * @param[out] o_drawerList
     *    list of TodDrawer pointers, empty in case of error
     *
     * @return N/A
     */
    void getDrawers(const p10_tod_setup_tod_sel i_config,
                    TodDrawerContainer& o_drawerList) const
    {
        o_drawerList = iv_todConfig[i_config].iv_todDrawerList;
    }

    /**
     * @brief Gets the MDMT for a specific topology
     *
     * @param[in] i_config
     *    Indicates the primary/secondary topology
     *
     * @param[out] o_pMDMT
     *     The TodProc pointer corresponding to the MDMT. NULL if error.
     *
     * @return Pointer to the data member iv_todConfig[i_config].iv_mdmt
     */
    TodProc* getMDMT(const p10_tod_setup_tod_sel i_config) const
    {
        return iv_todConfig[i_config].iv_mdmt;
    }

    /**
     *
     * @brief Setter method for iv_isConfigured variable of TodConfig structure
     *      for a specific configuration
     *
     * @param[in] i_config
     *     Indicates the primary/secondary topology
     *
     * @param[in] i_isConfigured
     *      Boolean variable to indicate the configuration status
     *
     * @return NA
     */
    void setConfigStatus(const p10_tod_setup_tod_sel i_config,
                        const bool i_isConfigured )
    {
        iv_todConfig[i_config].iv_isConfigured = i_isConfigured;
    }

    /**
     *
     * @brief Getter method for iv_isConfigured variable of TodConfig structure
     *      for a specific configuration
     *
     * @param[in] i_config
     *     Indicates the primary/secondary topology
     *
     * @return bool, indicating iv_isConfigured's value
     */
    bool getConfigStatus(const p10_tod_setup_tod_sel i_config) const
    {
        return iv_todConfig[i_config].iv_isConfigured;
    }

     /**
     * @brief isTodRunning returns the current state of  ChipTOD HW i.e.
     *    whether it is running or not
     *
     * @par Detailed Description:
     *    This method should be used by the methods that want to make a decision
     *    on creating TOD topology. If TOD HW is not running then it is safe to
     *    create new topology, however if TOD HW is running, program cannot
     *    modify the currently active topology.( It is still possible to
     *    modify/re-create a backup topology)
     *    TOD status register bits are clear as long as TOD HW is not running,
     *    method will read status register.
     *
     * @param[out] o_isTodRunning, boolean parameter that will be set to true if
     *    ChipTOD HW is running
     *
     * @return Error log handle that will determine if method was successful in
     *     determining ChipTOD HW state
     * @retval  NULL , Indicates success i.e. o_isTodRunning parameter indicates
     *     ChipTOD HW state
     * @retval !NULL , Failed getting the ChipTOD HW state , in this case value
     *      of o_isTodRunning  should be ignored.
     *
     *      This API may return one of the following "special" reason codes:
     *      NA
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */
     errlHndl_t isTodRunning ( bool& o_isTodRunning)const;

     /**
      * @brief This method will provide TOD topology register data to HDAT
      *
      * @par Detailed Description:
      *     HWSV needs to share TOD topology data with HDAT.
      *     HWSV also needs to persist with TOD topology data across non-memory
      *     preserving IPL's.
      *     Both the above requirements will be fulfilled by writing data
      *     to a file.
      *     This method will take the TOD register data and put it in the format
      *     required by HDAT, and then call helper method to write the same to a
      *     file
      *
      * @param[in] i_config
      *     Indicates the primary/secondary topology. When both Primary and
      *     Secondary topologies are successfully configured, the TOD register
      *     should be in synch for both primary and secondary, so passing any
      *     topology type will work here. However if there was a problem in
      *     building one of the topologies i.e. primary could be built but not
      *     the secondary then primary should be passed as i_config.
      *
      * @return Error log handle indicating the status of the request.
      * @retval NULL if successful
      * @retval !NULL if failed to write TOD configuration data
      *
      *      Error log handle points to a valid error log object whose primary
      *      SRC reason code (pError->getSRC()->reasonCode()) indicates the type
      *      of error.
      *
      * @note It is up to the caller to change the severity of the returned
      *     error based on what it decides to do with it. By default any
      *     returned error created by this function will be a non-reported
      *     tracing event error log.
      */
     errlHndl_t writeTodProcData(const p10_tod_setup_tod_sel i_config);

     /**
      *
      * @brief Getter method for iv_todChipDataVector
      *
      * @return Constant reference to vector<TodChipData> that will carry
      *      back iv_todChipDataVector
      *
      */
     const TodChipDataContainer&  getTodChipDataVector()const
     {
         return iv_todChipDataVector;
     }

     /**
      *
      * @brief This method will determine if the input processor target is
      *      available in the precessor blacklist or not.
      *
      * @param[in] i_procTarget
      *      The input processor target.
      *      The input target must not be NULL, and it must be of the processor
      *      type only.
      *
      * @return bool
      *      True if input processor target is blacklisted false otherwise
      *
      */
     bool  isProcBlackListed (
             TARGETING::ConstTargetHandle_t i_procTarget
             )const;
     /**
      *
      * @brief queryActiveConfig method will help to find the active TOD
      *     topology when ChipTOD HW is running, it will also report ChipTOD HW
      *     status (i.e. wheather it is currently running)and the MDMT belonging
      *     to active configuration.
      *     Calling code should ensure that it does not modifies active
      *     configuration when TOD HW is running.
      *
      * @par Detailed Description:
      *     This method ports logic from P7.
      *     Bits 00:02 of the TOD status register ( 0x40008 ), indicates the
      *     topology that is currently active in HW.
      *
      * @param[out] o_activeConfig, active configuration [primary | secondary]
      *     In case the TOD HW is not running then primary will be returned.
      *
      * @param[out] o_isTodRunning, It will indicate if TOD HW logic is running
      *     or not?
      *
      * @param[out] o_mdmtOnActiveTopology, target pointer of MDMT on active
      *     topology. In case of error or TOD HW logic is not running then this
      *     parameter will be NULL.
      *
      * @param[in] i_determineTodRunningState, This is a boolean variable that
      *     will determine if this method determines the TOD running state or
      *     not, this is done to reduce the number of SCOM operations in those
      *     flows where knowledge of running state is not required. Defaults to
      *     true i.e. determine the running state.
      *
      * @return Error log handle that will indicate if method was successfully
      *      able to determine various parameters or not
      *
      * @retval  NULL , Indicates success
      * @retval !NULL , Failed getting all the output parameters,in this case
      *      values of o_configAction,o_isTodRunning should not be considered
      *      for any further action.
      *
      *      This API may return one of the following "special" reason codes:
      *      NA
      *
      * @note It is up to the caller to change the severity of the
      *     returned error based on what it decides to do with it. By default
      *     any returned error created by this function will be a non-reported
      *     tracing event error log.
      */
     errlHndl_t queryActiveConfig( p10_tod_setup_tod_sel& o_activeConfig,
             bool& o_isTodRunning,
             TARGETING::Target*& o_mdmtOnActiveTopology,
             bool i_determineTodRunningState=true) const;

      /**
       *
       * @brief getConfiguredMdmt method will determine primary and secondary
       *      MDMT, if they are configured, using TOD register data.
       *
       * @par Detailed Description:
       *      TOD control register (0x40007) has bits that
       *      will be set for the processor when it is designated as primary
       *      MDMT or secondary MDMT. In case TOD HW indicates that MDMT is not
       *      set, output variables will be NULL.
       *
       * @param[out] o_primaryMdmt, Parameter in which target pointer of primary
       *      MDMT will be returned, it will be set to NULL if TOD HW does not
       *      shows that primary MDMT is configured.
       *
       * @param[out] o_secondaryMdmt, Parameter in which target pointer of
       *      secondary MDMT will be returned, it will be set to NULL if TOD HW
       *      does not show that secondary MDMT is configured.
       *
       * @return Error log handle indicating the status of request.
       * @retval  NULL , Indicates that method successfully executed its
       *      algorithm for determining MDMTs, however the individual output
       *      parameters must be checked to determine if the respective MDMT
       *      were found or not.
       * @retval !NULL , Indicates a problem condition where method was not able
       *      to complete all the steps for determining MDMTs successfully. In
       *      the error condition output parameters should be ignored.
       *
       *      This API may return one of the following "special" reason codes:
       *      NA
       * @note It is up to the caller to change the severity of the
       *     returned error based on what it decides to do with it. By default
       *     any returned error created by this function will be a non-reported
       *     tracing event error log.
       */
      errlHndl_t getConfiguredMdmt(TARGETING::Target*& o_primaryMdmt,
              TARGETING::Target*& o_secondaryMdmt)const;

      /**
       * @brief For the input config fills up iv_todConfig with MDMT and OSC
       *     info. Input proc is set as the master and the input drawer as the
       *     master drawer. Will also ask the proc to pick an OSC from which it
       *     can receive signals. Caller can provide an i_avoidOscHUID, this
       *     will help choose a redundant OSC for the redundant topology.
       *
       * @param[in] i_config
       *    Indicates the primary/secondary topology
       *
       * @param[in] i_proc
       *     TodProc pointer, must not be NULL.
       *
       * @param[in] i_drawer
       *     TodDrawer pointer, must not be NULL.
       *
       * @return Error log handle indicating the status of the request.
       * @retval NULL if the MDMT was set
       * @retval !NULL if MDMT couldn't be set
       *
       *     This API may return one of the following "special" reason codes:
       *     NA
       *
       * @note It is up to the caller to change the severity of the
       *     returned error based on what it decides to do with it. By default
       *     any returned error created by this function will be a non-reported
       *     tracing event error log.
       */
      errlHndl_t setMdmt(const p10_tod_setup_tod_sel i_config,
              TodProc* i_proc,
              TodDrawer* i_drawer);

      /**
       * @brief This method is has similar functionality as setMdmt except that
       *     it will presume that OSC has already been configured for the
       *     processor chip that is going to be designated as MDMT.
       *
       * @par Detailed Description:
       *     The use case for this method is when we need to use the already
       *     configured values of MDMT and the OSC source for it. This may
       *     happen when TOD service gets a request for re-configuring the
       *     backup topology after RR because of which the in memory copy of
       *     active topology no longer exists.
       *
       * @param[in] i_config
       *    Indicates the primary/secondary topology
       *
       * @param[in] i_proc
       *     TodProc pointer, must not be NULL.
       *
       * @param[in] i_drawer
       *     TodDrawer pointer
       *
       * @return NA
       *
       */
      void setMdmtOfActiveConfig(const p10_tod_setup_tod_sel i_config,
              TodProc* i_proc,
              TodDrawer* i_drawer);

      /**
       * @brief This method will collect gard records from system model and keep
       *       the HUIDs of garded targets on the system in local cache.
       *       It is done with the aim of avoiding repeated requests to the
       *       system model DB for checking the garded state of processors and
       *       OSCs, which can be time taking.
       *
       * @return Error log handle indicating the status of the request.
       * @retval NULL if gard records could be retrieved successfully from
       *       system model.
       * @retval !NULL if this method failed to build the local data structure
       *       of the garded targets on the system.
       *
       */
      errlHndl_t    buildGardedTargetsList();

      /**
       * @brief Given a target this method will tell whether it is garded or
       *       not. This  method will look into local cache it that was already
       *       initialized else it will go and look into the system model.
       *
       * @param[in] i_target  Input target whose gard status needs to be
       *        determined.
       * @param[out] o_isTargetGarded Boolean parameter to return the gard
       *        status of the input target to the caller.
       *
       * @return Error log handle indicating the status of the request.
       * @retval NULL if gard gard status of the input target could be
       *        successfully determined.
       * @retval !NULL if this method failed to build the local data structure
       *       of the garded targets on the system.
       *
       */
      errlHndl_t    checkGardStatusOfTarget(
              TARGETING::ConstTargetHandle_t i_target,
              bool&  o_isTargetGarded);

      /**
       *
       * @brief Interface to clear the local list of garded targets on the
       * system.
       *
       * @return NA
       */
      void  clearGardedTargetsList()
      {
          TOD_INF("Clearing the list of garded targets");
          iv_gardedTargets.clear();
          iv_gardListInitialized = false;
      }

protected:
      /**
       * @brief Constructor for the TodControls object.
       */
       TodControls();

      /**
       * @brief Destructor for the TodControls object.
       */
       ~TodControls();


private:

      /**
       *
       * @brief Add new target to the processor blacklist
       *
       * @param[in] i_ProcTarget
       *       Processor target that needs to be added to blacklist of
       *       processors.
       *       Caller must ensure that the input target is neither
       *       NULL nor of non-processor type.
       *
       * @return NA
       *
       */
      void  addProcToBlackList(TARGETING::ConstTargetHandle_t i_procTarget)
      {
          if ( !i_procTarget )
          {
              TOD_ERR_ASSERT(false, "Input target cannot be NULL for "
                      "addProcToBlackList");
          }

          if (
                  ( GETCLASS(i_procTarget) != TARGETING::CLASS_CHIP )
                  ||
                  ( GETTYPE(i_procTarget) != TARGETING::TYPE_PROC))
          {
              TOD_ERR_ASSERT(false, " Only processor target allowed as input for "
                      " addProcToBlackList");
          }

          iv_BlackListedProcs.push_back(i_procTarget);
      }

      /**
       * @brief This method will be used to determine if the data read from
       *     TodSystemData file indicates at least one functional processor
       *
       * @retval boolean value indicating presence or absence of valid data
       * @retval false , There is useful data
       * @retval true, No useful data found
       */
      bool  hasNoValidData(const std::vector<TodChipData>&
              i_todChipDataVector)const;

public:
      /**
       * @brief Given the MDMT for TOD config alternate to i_config,
       *     picks the MDMT for i_config based on the following criteria
       *
       * @par Detailed Description:
       *      Whenever there is an existing MDMT for the opposite configuration
       *      following criteria will decide the MDMT for this configuration
       *
       *      First of all we'll look only at TOD drawers having at least one
       *      proc with OSC input. Of all such procs across TOD drawers, we'll
       *      pick the one with max no of cores
       *
       *      We'll run the below algorithm twice, first time we'll try to pick
       *      an MDMT with redundant OSC.
       *      If we don't find one, we'll run it again witout the redundant OSC
       *      constraint.
       *      That way we'll maximise reliability : best case we'll find the
       *      MDMT connected to a redundant OSC on some other node.
       *
       *      1.MDMT will be chosen from a node other that the node on which
       *      this MDMT exists, in case of multinode systems.
       *      2.In single node system MDMT will be chosen from a different
       *      fabric node (tod drawer).
       *      3.Last a processor different from MDMT on the same fabric node
       *      will be chosen, if other options are not feasible
       *
       * @param[in] i_otherConfigMdmt
       *     TodProc pointer to the MDMT of the config alternate to i_config
       *
       * @param[in] i_config
       *    Indicates the primary/secondary topology, alternate to the one in
       *    which i_otherConfigMdmt is the MDMT
       *
       * @param[in] i_setMdmt
       *     Represents an special case where the method will find the MDMT but
       *     not set it, this case will be used when some part of code just
       *     wants to validate if MDMT can be found under given constraints or
       *     not.
       *
       * @return TodProc pointer to new MDMT, NULL if couldn't be chosen
       */
      TodProc* pickMdmt(const TodProc* i_otherConfigMdmt,
              const p10_tod_setup_tod_sel& i_config,
              const bool i_setMdmt = true);

private:

      //Datastructure for a TOD topology :
      //A list of TOD drawers (which will contain a list of TodProc's)
      //The MDMT for this topology
      struct TodConfig{
          TodDrawerContainer iv_todDrawerList;
          TodProc* iv_mdmt;
          bool iv_isConfigured;
          TodConfig() :
              iv_mdmt(nullptr),
              iv_isConfigured(false)
          {
          }
      };

      //Disabled copy constructor and assignment operator
      TodControls(const TodControls& rhs);
      TodControls& operator=(const TodControls& rhs);

      //Array of TOD configs
      //The fact that TOD_PRIMARY and TOD_SECONDARY are defined as 0 and 1
      //make then as appropriate indices to the array
      //iv_todConfig[0] -> primary
      //iv_todConfig[1] -> secondary
      TodConfig iv_todConfig[TOD_NUM_CONFIGS];

      //TodChipData for the whole system (in ordinal order)
      TodChipDataContainer iv_todChipDataVector;

      //Black listed processors that should not be considered as MDMT
      BlacListedProcContainer iv_BlackListedProcs;

      //List of garded targets on the system
      GardedTargetsContainer iv_gardedTargets;

      //Boolean value to indicate whether container iv_gardedTargets  is
      //initialized or not
      bool  iv_gardListInitialized;

      /* @brief enum for disable or Enable of Nag */
      enum NagUpdateAction{
          ENABLE_NAG = 0x0,
          DISABLE_NAG = 0x1,
          NAG_INVALID = 0x2,
      };


      //NOTE:Extended mod ids have PLACEHOLDER MODID which needs to be used
      //first when one is required.
      enum ExtendedModId
      {
          EMOD_TOD_BUILD_BLACKLIST = 0x132,
          EMOD_TOD_INIT = 0x10E,
          EMOD_TOD_INIT_HWP = 0x10F,
      };

      /**
       * @brief struct for returning gard records
       *
       */
      struct GardedUnit_t{
          TARGETING::ATTR_HUID_type   iv_huid;  //HUID of garded unit
          TARGETING::ATTR_HUID_type   iv_nodeHuid; //Node containing the unit
          uint32_t                    iv_errlogId; //Garded Error log
          HWAS::GARD_ErrorType        iv_errType; //Type of gard error
          TARGETING::CDM_DOMAIN       iv_domain; //CDM Domain of the unit
          TARGETING::ATTR_TYPE_type   iv_type; //Type of the unit
          TARGETING::ATTR_CLASS_type  iv_class; //Class of the unit
          uint32_t                    iv_rid; //RID of the unit
          NagUpdateAction             iv_nagDisabled; // Default to NAG enable
          GardedUnit_t() : iv_huid(TOD_HUID_INVALID),
                           iv_nodeHuid(TOD_HUID_INVALID),
                           iv_errlogId(0),
                           iv_errType(HWAS::GARD_NULL),
                           iv_domain(TARGETING::CDM_DOMAIN_NONE),
                           iv_type(TARGETING::TYPE_NA),
                           iv_class(TARGETING::CLASS_NA),
                           iv_rid(FSP_INVALID_RID),
                           iv_nagDisabled(ENABLE_NAG)
          {
          }

      };
      typedef std::list<GardedUnit_t> GardedUnitList_t;

      /**
       * @brief - This function returns all  gard records in a system
       * or node based on input huid
       *
       * @param[in] i_pTarget Target pointer to node or system, cannot be NULL
       * @param[out] o_gardedUnitList List of garded records
       *
       * @return Error log handle indicating the status of the request
       * @retval NULL on success
       * @retval !NULL  Error log handle, on failure
       *
       * @note It is up to the caller to change the severity of the returned
       *       error based on what it decides to do with it. By default any
       *       returned error created by this function will be a non-reported
       *       tracing event error log.
       */
      errlHndl_t gardGetGardedUnits(
              const TARGETING::Target* const i_pTarget,
              GardedUnitList_t &o_gardedUnitList);

      /**
       * @brief Return the physical path as string
       *
       * @param[in] i_path
       * The physical path of a target
       *
       *
       * @return string contains the string format of the path
       */

      const char * getPhysicalPathString(
              const TARGETING::ATTR_PHYS_PATH_type &i_path);

      /**
       * @brief Get Target based on the PHYSICAL Path
       *
       * @param[in] i_path
       * Supplied PHYSICAL PATH
       *
       * @param[out] o_Target
       * Pointer to Target
       *
       * assert if supplied physical path is not valid
       */

      void getTargetFromPhysicalPath(
          const TARGETING::ATTR_PHYS_PATH_type &i_path,
                TARGETING::Target*&  o_pTarget);

      /**
       * @brief Get parent of input CLASS for a Target
       *
       * @par Description:
       * Given a target, gets first target higher in the containment hierarchy
       * whose class matches the specified class.
       *
       * @param[in] i_pTarget
       * Input target pointer. Must not be NULL (otherwise call will return an
       * error log).  Must be a valid target from the system blueprint.
       *
       * @param[in] i_class
       * Class which constrains the search result.  CLASS_NA is not enforced,
       * but it will never find a matching parent.  Also note that if search
       * is for a chip parent of a chip, or other illogical searches, it will
       * not find a matching parent.  See attributeenums.H for class values.
       *
       * @param[out] o_parent_target
       * Parent Target; ignore on error.  Note: points to a blueprint target
       * which may or may not actually be present (source target must be
       * present to have assurances about presence of parent)
       *
       * @return errlHndl_t Error log handle indicating the status of the
       *  operation
       * @retval NULL Success, returned target is valid
       * @retval !NULL Failure; returned target is invalid.  Primary SRC
       *  reason codes
       * may be set to the following (others may be possible):
       * TOD_UTIL_REASON_NULL_TG: Supplied target is NULL
       * TOD_UTIL_REASON_PARENT_NOT_FOUND: Parent target of specified class
       * was not found
       */

       errlHndl_t getParent(const TARGETING::Target *i_pTarget,
                     const TARGETING::CLASS i_class,
                     TARGETING::Target *& o_parent_target);


};

// Wrapper function for TodControls::getDrawers instance
void getDrawers(const p10_tod_setup_tod_sel i_config,
             TodDrawerContainer& o_drawerList);

// Wrapper function for TodControls::isProcBlackListed instance
bool isProcBlackListed(TARGETING::ConstTargetHandle_t i_procTarget);

// Wrapper function for TodControls::getMDMT instance
TodProc* getMDMT(const p10_tod_setup_tod_sel i_config);

// Wrapper function for TodControls::pickMdmt instance
errlHndl_t pickMdmt(const p10_tod_setup_tod_sel i_config);

// Wrapper function for TodControls::isTodRunning instance
errlHndl_t isTodRunning(bool& o_isTodRunning);

// Wrapper function for TodControls::checkGardStatusOfTarget instance
errlHndl_t checkGardStatusOfTarget(
              TARGETING::ConstTargetHandle_t i_target,
              bool&  o_isTargetGarded);

// Wrapper function for TodControls::destroy instance
void destroy(const p10_tod_setup_tod_sel i_config);

// Wrapper function for TodControls::buildTodDrawers instance
errlHndl_t buildTodDrawers(const p10_tod_setup_tod_sel i_config);

// Wrapper function for TodControls::buildGardedTargetsList instance
errlHndl_t buildGardedTargetsList();

// Wrapper function for TodControls::setConfigStatus instance
void setConfigStatus(const p10_tod_setup_tod_sel i_config,
              const bool i_isConfigured );

// Wrapper function for TodControls::getConfiguredMdmt instance
errlHndl_t getConfiguredMdmt(TARGETING::Target*& o_primaryMdmt,
              TARGETING::Target*& o_secondaryMdmt);

// Wrapper function for TodControls::writeTodProcData instance
errlHndl_t writeTodProcData(const p10_tod_setup_tod_sel i_config);

// Wrapper function for TodControls::clearGardedTargetsList instance
void  clearGardedTargetsList();

// Wrapper function for TodControls::queryActiveConfig instance
errlHndl_t queryActiveConfig(p10_tod_setup_tod_sel& o_activeConfig,
             bool& o_isTodRunning,
             TARGETING::Target*& o_mdmtOnActiveTopology,
             bool i_determineTodRunningState);

// Wrapper function for TodControls::setMdmtOfActiveConfig instance
void setMdmtOfActiveConfig(const p10_tod_setup_tod_sel i_config,
             TodProc* i_proc,
             TodDrawer* i_drawer);

// Wrapper function for TodControls::getConfigStatus instance
bool getConfigStatus(const p10_tod_setup_tod_sel i_config);

} //end of namespace

#endif //TODCONTROLS_H
