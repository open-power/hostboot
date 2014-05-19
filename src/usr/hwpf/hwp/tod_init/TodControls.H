/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/tod_init/TodControls.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
 *  @file TodControls.H
 *
 *  @brief This file declares the methods and members of TodControls class
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

#ifndef TODCONTROLS_H
#define TODCONTROLS_H

//------------------------------------------------------------------------------
//Includes
//------------------------------------------------------------------------------
#include <util/singleton.H>
#include "proc_tod_utils.H"
#include "TodDrawer.H"
#include <map>

namespace TOD
{

//------------------------------------------------------------------------------
//Forward declarations
//------------------------------------------------------------------------------
class TodDrawer;
class TodProc;
class TodControls;
struct TodChipData;

//------------------------------------------------------------------------------
//Typedefs
//------------------------------------------------------------------------------
typedef std::vector<TodChipData> TodChipDataContainer;

//------------------------------------------------------------------------------
//Static globals
//------------------------------------------------------------------------------
//2 configs - primary/secondary
const static uint8_t TOD_NUM_CONFIGS = 2;
const static uint8_t TOD_PSS_MSS_STATUS_REG_00040008_ACTIVE_BIT = 0;
const static uint8_t TOD_PSS_MSS_CTRL_REG_00040007_PRIMARY_MDMT_BIT = 1;
const static uint8_t TOD_PSS_MSS_CTRL_REG_00040007_SECONDARY_MDMT_BIT = 9;

const static uint32_t TOD_INVALID_UNITID = 0xFFFFFFEF;

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
     *    TOD drawers are represented by HwsvTodDrawer class, that
     *    basically provides a grouping of the HwsvTodProc objects such
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
     *    HwsvTodProc pointers.
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
    errlHndl_t buildTodDrawers(const proc_tod_setup_tod_sel i_config);

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
    errlHndl_t pickMdmt(const proc_tod_setup_tod_sel i_config);

    /**
     * @brief Destroy information pertaining to topology type
     *     i_config and free up associated memory
     *
     * @param[in] i_config
     *    Indicates the primary/secondary topology
     *
     * @return N/A
     */
    void destroy(const proc_tod_setup_tod_sel i_config);

    /**
     * @brief Gets a list of TOD drawers for a specific
     *     topology
     *
     * @param[in] i_config
     *    Indicates the primary/secondary topology
     *
     * @param[out] o_drawerList
     *    list of HwsvTodDrawer pointers, empty in case of error
     *
     * @return N/A
     */
    void getDrawers(const proc_tod_setup_tod_sel i_config,
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
     *     The HwsvTodProc pointer corresponding to the MDMT. NULL if error.
     *
     * @return Pointer to the data member iv_todConfig[i_config].iv_mdmt
     */
    TodProc* getMDMT(const proc_tod_setup_tod_sel i_config) const
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
    void setConfigStatus(const proc_tod_setup_tod_sel i_config,
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
    bool getConfigStatus(const proc_tod_setup_tod_sel i_config) const
    {
        return iv_todConfig[i_config].iv_isConfigured;
    }

    /**
     *
     * @brief getTodConfigState will enable other methods to make a decision
     *     regarding valid action to be performed to modify the
     *     topology.
     *
     * @par Detailed Description:
     *     On getting a topology creation/modification request, TOD service
     *     methods need to determine next course of action based on the ChipTOD
     *     HW state and the state of the data that is available in the
     *     TodSystemData file.(TodSystemData file contains the previously
     *     created TOD topology's information). This method will provide all
     *     the information that is required to determine next course of action.
     *
     *     Following algorithm is used
     *     1) Check TOD status register to determine TOD HW state and the active
     *     configuration
     *     2) Read the TodSystemData to find, if HW has changed i.e. new
     *     functional processors became available or one of the processor that
     *     was functional when topology was created last time became
     *     non-functional.
     *
     *     Method can report TOD config state as one of the following
     *        a)TOD_UNCHANGED ==> No change in the HW
     *        b)TOD_MODIFIED ==> HW has changed
     *        c)TOD_UNKNOWN ==> It is not possible to determine the state
     *
     * @param[out] o_configState
     *     This parameter will indicate to caller if the HW as seen by
     *     getTodConfigState is same as indicated by the TodSystemData or not.
     *     One of the enums listed in TOD_CONFIG_STATE will be returned.
     *
     * @param[out] o_isTodRunning
     *     It will be true if the ChipTOD HW is running.
     *
     * @param[out] o_activeConfig
     *     This parameter will carry back the information regarding the topology
     *     that has been currently selected by PHYP, if ChipTOD HW is running.
     *     In case TOD HW is not running then it will report TOD_PRIMARY, as
     *     that is the configuration to be picked by PHYP once the TOD logic
     *     starts running.
     *
     * @return Error log handle that will determine if method was successful in
     *      determining various parameters or not
     * @retval  NULL , Indicates success
     * @retval !NULL , Failed getting the output parameters,in this case
     *      value of o_configState,o_isTodRunning and o_activeConfig should
     *      not be considered for any further action.
     *
     *      This API may return one of the following "special" reason codes:
     *      NA
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */
     errlHndl_t getTodConfigState ( TOD_CONFIG_STATE& o_configState,
                                   proc_tod_setup_tod_sel& o_activeConfig,
                                   bool& o_isTodRunning)const;
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
     errlHndl_t writeTodProcData(const proc_tod_setup_tod_sel i_config);

 
     /**
      *
      * @brief This is a helper method for writeTodProcDataToFile, it will
      *     determine file path where array of hwsvTodChipData structure has to
      *     be written by HWSV , HDAT will read this file.
      *
      * @par Detailed Description:
      *     The file to which data has to be written will be determined by the
      *     following registry keys
      *     1. fstp/P1_Root (To determine the root directory of P1)
      *     2. CINI_SYSTODFILE_PATH (To determine the directory and file name
      *     within P1_Root where the data is to be written)
      *
      * @param[in] o_fileName
      *     Output parameter to carry back the file name qualified by full path
      *     where the data has has to be written.
      *
      * @return Error log handle indicating the status of the request.
      * @retval NULL if file path could be determined successfully
      * @retval !NULL if file path could not be found
      *
      *      Error log handle points to a valid error log object whose primary
      *      SRC reason code (pError->getSRC()->reasonCode()) indicates the type
      *      of error.
      *
      * @note It is up to the caller to change the severity of the returned error
      *     based on what it decides to do with it. By default any returned
      *     error created by this function will be a non-reported tracing event
      *     error log.
      */
     errlHndl_t getTodProcDataFilePath(char * o_fileName) const;

     /**
      * @brief This is a helper method for writeTodProcData, it will write the
      *     array of hwsvTodChipData structures created by writeTodProcData to a
      *     file with P1 persistancy
      *
      * @par Detailed Description:
      *     The method will work on iv_todChipData and take help of
      *     getTodProcDataFilePath to detrmine the file path where
      *     iv_todChipData has to be written.
      *
      * @return Error log handle indicating the status of the request
      * @retval NULL if the data could not be written  successfully
      * @retval !NULL if the data was written successfully
      *
      *     Error log handle points to a valid error log object whose primary
      *     SRC reason code (pError->getSRC()->reasonCode()) indicates the type
      *     of error.
      *
      * @note It is up to the caller to change the severity of the returned
      *     error based on what it decides to do with it. By default any
      *     returned error created by this function will be a non-reported
      *     tracing event error log.
      */
     errlHndl_t writeTodProcDataToFile();

     /**
      *
      * @brief Getter method for iv_todChipDataVector
      *
      * @return Constant reference to vector<hwsvTodChipData> that will carry
      *      back iv_todChipDataVector
      *
      */
     const TodChipDataContainer&  getTodChipDataVector()const
     {
         return iv_todChipDataVector;
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
     * @brief queryActiveConfig method will help to find the active TOD topology
     *     when ChipTOD HW is running,It will also report ChipTOD HW status.
     *     i.e. wheather it is currently running. In case ChipTOD HW is running
     *     active configuration should never be modified.
     *
     * @par Detailed Description:
     *     This method ports logic from P7.
     *     Bits 00:02 of the TOD status register ( 0x40008 ), indicates the
     *     topology that is currently active in HW.
     *
     * @param[out] o_activeConfig, active configuration [primary | secondary]
     *     In case the TOD HW is not running then primary will be returned.
     *
     * @param[out] o_isTodRunning, It will indicate if HW is running or not
     *
     * @return Error log handle that will indicate if method was successfully
     *      able to determine various parameters or not
     * @retval  NULL , Indicates success
     * @retval !NULL , Failed getting all the output parameters,in this case
     *      values of o_configAction,o_isTodRunning should not be considered for
     *      any further action.
     *
     *      This API may return one of the following "special" reason codes:
     *      NA
     *
     * @note It is up to the caller to change the severity of the
     *     returned error based on what it decides to do with it. By default
     *     any returned error created by this function will be a non-reported
     *     tracing event error log.
     */

     errlHndl_t queryActiveConfig( proc_tod_setup_tod_sel& o_activeConfig,
                                   bool& o_isTodRunning) const;

    /**
     *
     * @brief getConfiguredMdmt method will determine primary and secondary MDMT
     *      ,if they are configured, using TOD register data.
     *
     * @par Detailed Description:
     *      TOD control register (0x40007) has bits that
     *      will be set for the processor when it is designated as primary MDMT
     *      or secondary MDMT. In case TOD HW indicates that MDMT is not set,
     *      output variables will be NULL.
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
     *      parameters must be checked to determine if the respective MDMT were
     *      found or not.
     * @retval !NULL , Indicates a problem condition where method was not able
     *      to complete all the steps for determining MDMTs successfully. In the
     *      error condition output parameters should be ignored.
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
      * @brief This method will read the TOD topology register data from
      *     TodSystemData file
      *
      * @par Detailed Description:
      *     TodSystemData file is a P1 persistent file that will retain the TOD
      *     topology data from previous configuration. Any request to recofigure
      *     backup topology should consider the previous topology data. This
      *     method will read the TodSystemData file and put the data in
      *     hwsvTodChipData structures.
      *
      * @param[out ] o_todChipDataVector , Array of hwsvTodChipData structures
      *     that will be populated with the data from TodSystemData file.
      *
      * @return Error log handle indicating the status of the request.
      * @retval NULL if TodSystemData was successfully read.
      * @retval !NULL if TodSystemData could not be read. This will happen if
      *     the file does not exist, one of the file operation failed or file
      *     does not have expected data.
      *
      *     This API may return one of the following "special" reason codes:
      *     NA
      *
      * @note It is up to the caller to change the severity of the
      *     returned error based on what it decides to do with it. By default
      *     any returned error created by this function will be a non-reported
      *     tracing event error log.
      */
     errlHndl_t readTodProcDataFromFile(std::vector<TodChipData>&
             o_todChipDataVector )const;
 
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

    //Datastructure for a TOD topology :
    //A list of TOD drawers (which will contain a list of HWSVTodProc's)
    //The MDMT for this topology
    struct TodConfig{
        TodDrawerContainer iv_todDrawerList;
        TodProc* iv_mdmt;
        bool iv_isConfigured;
        TodConfig() :
            iv_mdmt(NULL),
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

    //hwsvTodChipData for the whole system (in ordinal order)
    TodChipDataContainer iv_todChipDataVector;
};

} //end of namespace
#endif //TODCONTROLS_H
