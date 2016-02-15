/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_cfgdata.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2016                        */
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
#include <targeting/common/commontargeting.H>
#include <targeting/common/attributes.H>
#include <targeting/common/utilFilter.H>
#include "htmgt_cfgdata.H"
#include "htmgt_utility.H"
#include "htmgt_poll.H"
#include "ipmi/ipmisensor.H"
#include "fapiPlatAttributeService.H"
#include <htmgt/htmgt_reasoncodes.H>



using namespace TARGETING;


//for unit testing
//#define TRACUCOMP(args...)  TMGT_INF(args)
#define TRACUCOMP(args...)

namespace HTMGT
{
    void getWofCoreFrequencyData(const TargetHandle_t i_occ,
                                 uint8_t* o_data,
                                 uint64_t & o_size);
    void getWofVrmEfficiencyData(uint8_t* o_data,
                                 uint64_t & o_size);

    bool G_wofSupported = true;

    // Send config format data to all OCCs
    void sendOccConfigData(const occCfgDataFormat i_requestedFormat)
    {
        if (G_debug_trace & DEBUG_TRACE_VERBOSE)
        {
            TMGT_INF("sendOccConfigData called");
        }

        uint8_t cmdData[OCC_MAX_DATA_LENGTH] = {0};
        uint64_t cmdDataLen = OCC_MAX_DATA_LENGTH;

        const occCfgDataTable_t* start = &occCfgDataTable[0];
        const occCfgDataTable_t* end =
            &occCfgDataTable[OCC_CONFIG_TABLE_SIZE];
        bool validFormat = true;
        if (OCC_CFGDATA_CLEAR_ALL != i_requestedFormat)
        {
            const occCfgDataTable_t * target =
                std::find(start, end, i_requestedFormat);
            if (target != end)
            {
                // only need to send a single packet
                start = target;
                end = start+1;
            }
            else
            {
                TMGT_ERR("sendOccConfigData: Invalid cfg format supplied %d",
                         i_requestedFormat);
                validFormat = false;
            }
        }

        if (validFormat)
        {
            // Loop through all functional OCCs
            std::vector<Occ*> occList = OccManager::getOccArray();
            for (std::vector<Occ*>::iterator itr = occList.begin();
                 itr < occList.end();
                 itr++)
            {
                Occ * occ = (*itr);
                const uint8_t occInstance = occ->getInstance();
                const occRole role = occ->getRole();

                // Loop through all config data types
                for (const occCfgDataTable_t *itr = start; itr < end; ++itr)
                {
                    const occCfgDataFormat format = itr->format;
                    bool sendData = true;

                    // Make sure format is supported by this OCC
                    if (TARGET_MASTER == itr->targets)
                    {
                        if (OCC_ROLE_MASTER != role)
                        {
                            sendData = false;
                        }
                    }

                    // Make sure data is supported in the current state
                    const occStateId state = occ->getState();
                    if (CFGSTATE_STANDBY == itr->supportedStates)
                    {
                        if (OCC_STATE_STANDBY != state)
                        {
                            sendData = false;
                        }
                    }
                    else if (CFGSTATE_SBYOBS == itr->supportedStates)
                    {
                        if ((OCC_STATE_STANDBY != state) &&
                            (OCC_STATE_OBSERVATION != state))
                        {
                            sendData = false;
                        }
                    }

                    if (sendData)
                    {
                        cmdDataLen = OCC_MAX_DATA_LENGTH;
                        switch(format)
                        {
                            case OCC_CFGDATA_PSTATE_SSTRUCT:
                                getPstateTableMessageData(occ->getTarget(),
                                                          cmdData,
                                                          cmdDataLen);
                                break;

                            case OCC_CFGDATA_FREQ_POINT:
                                getFrequencyPointMessageData(cmdData,
                                                             cmdDataLen);
                                break;

                            case OCC_CFGDATA_OCC_ROLE:
                                getOCCRoleMessageData(OCC_ROLE_MASTER ==
                                                      occ->getRole(),
                                                      OCC_ROLE_FIR_MASTER ==
                                                      occ->getRole(),
                                                      cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_APSS_CONFIG:
                                getApssMessageData(cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_MEM_CONFIG:
                                getMemConfigMessageData(occ->getTarget(), true,
                                                        cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_FIR_SCOMS:
                                TMGT_ERR("NO FIR SCOMS AVAILABLE YET");
                                cmdDataLen = 0;
                                break;

                            case OCC_CFGDATA_PCAP_CONFIG:
                                getPowerCapMessageData(cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_SYS_CONFIG:
                                getSystemConfigMessageData(occ->getTarget(),
                                                           cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_MEM_THROTTLE:
                                getMemThrottleMessageData(occ->getTarget(),
                                                          cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_TCT_CONFIG:
                                getThermalControlMessageData(cmdData,
                                                             cmdDataLen);
                                break;

                            case OCC_CFGDATA_WOF_CORE_FREQ:
                                getWofCoreFrequencyData(occ->getTarget(),
                                                        cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_WOF_VRM_EFF:
                                getWofVrmEfficiencyData(cmdData, cmdDataLen);
                                break;

                            default:
                                TMGT_ERR("sendOccConfigData: Unsupported"
                                         " format type 0x%02X",
                                         format);
                                cmdDataLen = 0;
                        }

                        if (cmdDataLen > 0)
                        {
                            TMGT_INF("sendOccConfigData: Sending config"
                                     " 0x%02X to OCC%d",
                                     format, occInstance);
                            OccCmd cmd(occ, OCC_CMD_SETUP_CFG_DATA,
                                       cmdDataLen, cmdData);
                            errlHndl_t l_err = cmd.sendOccCmd();
                            if (l_err != NULL)
                            {
                                TMGT_ERR("sendOccConfigData: OCC%d cfg "
                                         "format 0x%02X failed with rc=0x%04X",
                                         occInstance, format,
                                         l_err->reasonCode());
                                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                            }
                            else
                            {
                                if (OCC_RC_SUCCESS != cmd.getRspStatus())
                                {
                                    TMGT_ERR("sendOccConfigData: OCC%d cfg "
                                             "format 0x%02X had bad rsp status"
                                             " 0x%02X for sysConfig",
                                             occInstance, format,
                                             cmd.getRspStatus());
                                }
                            }

                            // Send poll between config packets to flush errors
                            l_err = OccManager::sendOccPoll();
                            if (l_err)
                            {
                                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                            }
                        }
                    } // if (sendData)

                    if (OccManager::occNeedsReset())
                    {
                        TMGT_ERR("sendOccConfigData(): OCCs need to be reset");
                    }

                } // for each config format

            } // for each OCC
        }

    } // end sendOccConfigData()


/** OCC configuration data message versions */
enum occCfgDataVersion
{
    OCC_CFGDATA_PSTATE_VERSION       = 0x10,
    OCC_CFGDATA_FREQ_POINT_VERSION   = 0x11,
    OCC_CFGDATA_APSS_VERSION         = 0x10,
    OCC_CFGDATA_MEM_CONFIG_VERSION   = 0x10,
    OCC_CFGDATA_PCAP_CONFIG_VERSION  = 0x10,
    OCC_CFGDATA_SYS_CONFIG_VERSION   = 0x10,
    OCC_CFGDATA_MEM_THROTTLE_VERSION = 0x10,
    OCC_CFGDATA_TCT_CONFIG_VERSION   = 0x10,
    OCC_CFGDATA_WOF_CORE_FREQ_VERSION = 0x10,
    OCC_CFGDATA_WOF_VRM_EFF_VERSION  = 0x10
};

void getMemConfigMessageData(const TargetHandle_t i_occ,
                             bool i_monitoringEnabled,
                             uint8_t* o_data, uint64_t & o_size)
{
    uint64_t index = 0;

    assert(o_data != NULL);

    o_data[index++] = OCC_CFGDATA_MEM_CONFIG;
    o_data[index++] = OCC_CFGDATA_MEM_CONFIG_VERSION;
    size_t numSetsOffset = index++; //Will fill in numSets at the end

    //Next, the following format repeats per set of data
    //Bytes 0-3:    Reserved
    //Bytes 4-5     hardware sensor ID
    //Bytes 6-7:    temperature sensor ID
    //Byte 8:       Centaur position 0-7
    //Byte 9:       DIMM position 0-7
    //Bytes 10-11:  Reserved

    if (i_monitoringEnabled)
    {
        TargetHandleList centaurs;
        TargetHandleList mbas;
        TargetHandleList dimms;
        TargetHandleList::const_iterator centaur;
        TargetHandleList::const_iterator mba;
        TargetHandleList::const_iterator dimm;
        uint8_t centPos = 0;
        uint8_t dimmPos = 0;
        uint8_t numSets = 0;
        uint16_t sensor = 0;


        ConstTargetHandle_t proc = getParentChip(i_occ);
        assert(proc != NULL);

        getChildAffinityTargets(centaurs, proc, CLASS_CHIP, TYPE_MEMBUF);

        TRACUCOMP("Proc 0x%X has %d centaurs",
                  proc->getAttr<ATTR_HUID>(),
                  centaurs.size());

        for (centaur=centaurs.begin(); centaur!=centaurs.end(); ++centaur)
        {
            numSets++;

            //Do the entry for the Centaur itself

            //Reserved
            memset(&o_data[index], 0, 4);
            index += 4;

            //Hardware Sensor ID
            sensor = UTIL::getSensorNumber(*centaur,
                                           SENSOR_NAME_MEMBUF_STATE);
            memcpy(&o_data[index], &sensor, 2);
            index += 2;

            //Temperature Sensor ID
            sensor = UTIL::getSensorNumber(*centaur,
                                           SENSOR_NAME_MEMBUF_TEMP);
            memcpy(&o_data[index], &sensor, 2);
            index += 2;

            //Centaur #
            centPos = (*centaur)->getAttr<ATTR_POSITION>();
            // ATTR_POSITION is system wide. Must be 0-7 on each OCC
            centPos = centPos % 8;
            o_data[index++] = centPos;

            //Dimm # (0xFF since a centaur)
            o_data[index++] = 0xFF;

            //Reserved
            memset(&o_data[index], 0, 2);
            index += 2;


            mbas.clear();
            getChildAffinityTargets(mbas, *centaur,
                                    CLASS_UNIT, TYPE_MBA);

            for (mba=mbas.begin(); mba!=mbas.end(); ++mba)
            {
                dimms.clear();
                getChildAffinityTargets(dimms, *mba,
                                        CLASS_LOGICAL_CARD, TYPE_DIMM);

                TRACUCOMP("MBA 0x%X has %d DIMMs",
                          (*mba)->getAttr<ATTR_HUID>(), dimms.size());

                for (dimm=dimms.begin(); dimm!=dimms.end(); ++dimm)
                {
                    //Fill in the DIMM entry
                    numSets++;

                    //Reserved
                    memset(&o_data[index], 0, 4);
                    index += 4;

                    //Hardware Sensor ID
                    sensor = UTIL::getSensorNumber(*dimm,
                                                   SENSOR_NAME_DIMM_STATE);
                    memcpy(&o_data[index], &sensor, 2);
                    index += 2;

                    //Temperature Sensor ID
                    sensor = UTIL::getSensorNumber(*dimm,
                                                   SENSOR_NAME_DIMM_TEMP);
                    memcpy(&o_data[index], &sensor, 2);
                    index += 2;

                    //Centaur #
                    o_data[index++] = centPos;

                    //DIMM #
                    dimmPos = getOCCDIMMPos(*mba, *dimm);
                    o_data[index++] = dimmPos;

                    //Reserved
                    memset(&o_data[index], 0, 2);
                    index += 2;

                }
            }
        }

        TMGT_INF("getMemConfigMessageData: returning %d"
                 " sets of data for OCC 0x%X",
                 numSets, i_occ->getAttr<ATTR_HUID>());

        o_data[numSetsOffset] = numSets;
    }
    else
    {
        TMGT_INF("getMemConfigMessageData: Mem monitoring is disabled");

        //A zero in byte 2 (numSets) means monitoring is disabled
        o_data[2] = 0;
    }

    o_size = index;

}




void getMemThrottleMessageData(const TargetHandle_t i_occ,
                               uint8_t* o_data, uint64_t & o_size)
{
    uint8_t centPos = 0;
    uint8_t mbaPos = 0;
    uint8_t numSets = 0;
    uint64_t index = 0;
    uint16_t numerator = 0;

    ConstTargetHandle_t proc = getParentChip(i_occ);
    assert(proc != NULL);
    assert(o_data != NULL);

    o_data[index++] = OCC_CFGDATA_MEM_THROTTLE;
    o_data[index++] = OCC_CFGDATA_MEM_THROTTLE_VERSION;
    index++; //Will fill in numSets at the end


    TargetHandleList centaurs;
    TargetHandleList mbas;
    TargetHandleList::const_iterator centaur;
    TargetHandleList::const_iterator mba;

    getChildAffinityTargets(centaurs, proc, CLASS_CHIP, TYPE_MEMBUF);

    //Next, the following format repeats per set/MBA:
    //Byte 0:       Centaur position 0-7
    //Byte 1:       MBA Position 0-1
    //Bytes 2-3:    min OT N_PER_MBA
    //bytes 4-5:    redundant power N_PER_MBA
    //bytes 6-7:    redundant power N_PER_CHIP
    //bytes 8-9:    oversubscription N_PER_MBA
    //bytes 10-11:  oversubscription N_PER_CHIP


    for (centaur=centaurs.begin(); centaur!=centaurs.end(); ++centaur)
    {
        centPos = (*centaur)->getAttr<ATTR_POSITION>();
        // ATTR_POSITION is system wide. Must 0-7 on each OCC
        centPos = centPos % 8;

        mbas.clear();
        getChildAffinityTargets(mbas, *centaur,
                                CLASS_UNIT, TYPE_MBA);

        for (mba=mbas.begin(); mba!=mbas.end(); ++mba)
        {
            numSets++;
            mbaPos = (*mba)->getAttr<ATTR_CHIP_UNIT>();

            TRACUCOMP("centPos = %d, mbaPos = %d",
                      centPos, mbaPos);

            o_data[index++] = centPos;
            o_data[index++] = mbaPos;

            numerator = (*mba)->getAttr<ATTR_OT_MIN_N_PER_MBA>();
            memcpy(&o_data[index], &numerator, 2);
            index += 2;

            numerator = (*mba)->getAttr<ATTR_N_PLUS_ONE_N_PER_MBA>();
            memcpy(&o_data[index], &numerator, 2);
            index += 2;

            numerator = (*mba)->getAttr<ATTR_N_PLUS_ONE_N_PER_CHIP>();
            memcpy(&o_data[index], &numerator, 2);
            index += 2;

            numerator = (*mba)->getAttr<ATTR_OVERSUB_N_PER_MBA>();
            memcpy(&o_data[index], &numerator, 2);
            index += 2;

            numerator = (*mba)->getAttr<ATTR_OVERSUB_N_PER_CHIP>();
            memcpy(&o_data[index], &numerator, 2);
            index += 2;
        }

    }


    TMGT_INF("getMemThrottleMessageData: returning %d"
             " sets of data for OCC 0x%X",
             numSets, i_occ->getAttr<ATTR_HUID>());

    o_data[2] = numSets;

    o_size = index;

}



void getOCCRoleMessageData(bool i_master, bool i_firMaster,
                           uint8_t* o_data, uint64_t & o_size)
{
    assert(o_data != NULL);

    o_data[0] = OCC_CFGDATA_OCC_ROLE;

    o_data[1] = OCC_ROLE_SLAVE;

    if (i_master)
    {
        o_data[1] = OCC_ROLE_MASTER;
    }

    if (i_firMaster)
    {
        o_data[1] |= OCC_ROLE_FIR_MASTER;
    }

    o_size = 2;
}


uint16_t getMaxPowerCap(Target *i_sys)
{
    uint16_t o_maxPcap = 0;
    bool useDefaultLimit = true;

#ifdef CONFIG_BMC_IPMI
    // Check if HPC limit was found
    ATTR_OPEN_POWER_N_PLUS_ONE_HPC_BULK_POWER_LIMIT_WATTS_type hpc_pcap;
    if (i_sys->tryGetAttr
        <ATTR_OPEN_POWER_N_PLUS_ONE_HPC_BULK_POWER_LIMIT_WATTS>(hpc_pcap))
    {
        if (0 != hpc_pcap)
        {
            // Check if redundant power supply policy is enabled (on BMC)
            SENSOR::getSensorReadingData redPolicyData;
            SENSOR::SensorBase
                redPolicySensor(TARGETING::SENSOR_NAME_REDUNDANT_PS_POLICY,
                                i_sys);
            errlHndl_t err = redPolicySensor.readSensorData(redPolicyData);
            if (NULL == err)
            {
                // 0x02 == Asserted bit (redundant policy is enabled)
                if ((redPolicyData.event_status & 0x02) == 0x00)
                {
                    // non-redundant policy allows higher bulk power limit
                    // with the potential impact of OCC not being able to
                    // lower power fast enough
                    useDefaultLimit = false;
                    TMGT_INF("getMaxPowerCap: maximum power cap = %dW"
                             " (HPC/non-redundant PS bulk power limit)",
                             hpc_pcap);
                    o_maxPcap = hpc_pcap;
                }
                // else redundant policy enabled, use default
            }
            else
            {
                // error reading policy, commit and use default
                TMGT_ERR("getMaxPowerCap: unable to read power supply"
                         " redundancy policy sensor, rc=0x%04X",
                         err->reasonCode());
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
            }
        }
        // else no valid HPC limit, use default
    }
    // else HPC limit not found, use default
#endif

    if (useDefaultLimit)
    {
        // Read the default N+1 bulk power limit (redundant PS policy)
        o_maxPcap = i_sys->
            getAttr<ATTR_OPEN_POWER_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS>();
        TMGT_INF("getMaxPowerCap: maximum power cap = %dW "
                 "(redundant PS bulk power limit)", o_maxPcap);
    }

    return o_maxPcap;

} // end getMaxPowerCap()


void getPowerCapMessageData(uint8_t* o_data, uint64_t & o_size)
{
    uint64_t index = 0;
    uint16_t pcap = 0;
    Target* sys = NULL;
    targetService().getTopLevelTarget(sys);

    assert(sys != NULL);
    assert(o_data != NULL);

    o_data[index++] = OCC_CFGDATA_PCAP_CONFIG;
    o_data[index++] = OCC_CFGDATA_PCAP_CONFIG_VERSION;

    //Minimum Power Cap
    pcap = sys->getAttr<ATTR_OPEN_POWER_MIN_POWER_CAP_WATTS>();
    TMGT_INF("getPowerCapMessageData: minimum power cap = %dW",
             pcap);
    memcpy(&o_data[index], &pcap, 2);
    index += 2;

    //System Maximum Power Cap
    pcap = getMaxPowerCap(sys);
    memcpy(&o_data[index], &pcap, 2);
    index += 2;

    //Oversubscription Power Cap
    pcap = sys->getAttr<ATTR_OPEN_POWER_N_BULK_POWER_LIMIT_WATTS>();
    TMGT_INF("getPowerCapMessageData: oversubscription power cap = %dW",
             pcap);
    memcpy(&o_data[index], &pcap, 2);
    index += 2;

    o_size = index;
}



void getSystemConfigMessageData(const TargetHandle_t i_occ, uint8_t* o_data,
                                uint64_t & o_size)
{
    uint64_t index = 0;
    uint16_t sensor = 0;
    assert(o_data != NULL);

    o_data[index++] = OCC_CFGDATA_SYS_CONFIG;
    o_data[index++] = OCC_CFGDATA_SYS_CONFIG_VERSION;

    //System Type
    o_data[index++] = OCC_CFGDATA_OPENPOWER_SYSTEMTYPE;

    //processor sensor ID
    ConstTargetHandle_t proc = getParentChip(i_occ);
    sensor = UTIL::getSensorNumber(proc, SENSOR_NAME_PROC_STATE);
    memcpy(&o_data[index], &sensor, 2);
    index += 2;

    //Next 12*4 bytes are for core sensors.
    //If a new processor with more cores comes along,
    //this command will have to change.
    TargetHandleList cores;
    TargetHandleList::iterator coreIt;
    getChildChiplets(cores, proc, TYPE_CORE, false);

    uint16_t tempSensor = 0;
    uint16_t freqSensor = 0;
    for (uint64_t core=0; core<CFGDATA_CORES; core++)
    {
        tempSensor = 0;
        freqSensor = 0;

        if (core < cores.size())
        {
            tempSensor = UTIL::getSensorNumber(cores[core],
                                               SENSOR_NAME_CORE_TEMP);

            freqSensor = UTIL::getSensorNumber(cores[core],
                                               SENSOR_NAME_CORE_FREQ);
        }

        //Core Temp Sensor ID
        memcpy(&o_data[index], &tempSensor, 2);
        index += 2;

        //Core Frequency Sensor ID
        memcpy(&o_data[index], &freqSensor, 2);
        index += 2;
    }

    TargetHandle_t sys = NULL;
    TargetHandleList nodes;
    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);
    getChildAffinityTargets(nodes, sys, CLASS_ENC, TYPE_NODE);
    assert(!nodes.empty());
    TargetHandle_t node = nodes[0];


    //Backplane sensor ID
    sensor = UTIL::getSensorNumber(node, SENSOR_NAME_BACKPLANE_FAULT);
    memcpy(&o_data[index], &sensor, 2);
    index += 2;

    //APSS sensor ID
    sensor = UTIL::getSensorNumber(sys, SENSOR_NAME_APSS_FAULT);
    memcpy(&o_data[index], &sensor, 2);
    index += 2;

    o_size = index;
}


void getThermalControlMessageData(uint8_t* o_data,
                                  uint64_t & o_size)
{
    uint64_t index = 0;
    Target* sys = NULL;
    targetService().getTopLevelTarget(sys);

    assert(sys != NULL);
    assert(o_data != NULL);

    o_data[index++] = OCC_CFGDATA_TCT_CONFIG;
    o_data[index++] = OCC_CFGDATA_TCT_CONFIG_VERSION;

    //3 data sets following (proc, Centaur, DIMM), and
    //each will get a FRU type, DVS temp, error temp,
    //and max read timeout
    o_data[index++] = 3;

    o_data[index++] = CFGDATA_FRU_TYPE_PROC;
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_PROC_DVFS_TEMP_DEG_C>();
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_PROC_ERROR_TEMP_DEG_C>();
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_PROC_READ_TIMEOUT_SEC>();

    o_data[index++] = CFGDATA_FRU_TYPE_MEMBUF;
    o_data[index++] = sys->
                        getAttr<ATTR_OPEN_POWER_MEMCTRL_THROTTLE_TEMP_DEG_C>();
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_ERROR_TEMP_DEG_C>();
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_READ_TIMEOUT_SEC>();

    o_data[index++] = CFGDATA_FRU_TYPE_DIMM;
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_DIMM_THROTTLE_TEMP_DEG_C>();
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_DIMM_ERROR_TEMP_DEG_C>();
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_DIMM_READ_TIMEOUT_SEC>();

    o_size = index;

}


// Determine if the BMC will allow turbo to be used.
// Returns true if turbo is allowed, else false
bool bmcAllowsTurbo(Target* i_sys)
{
    bool turboAllowed = true;

    uint32_t sensorNum = UTIL::getSensorNumber(i_sys,
                                               SENSOR_NAME_TURBO_ALLOWED);
    // VALID IPMI sensors are 0-0xFE
    if (sensorNum != 0xFF)
    {
        // Check if turbo frequency is allowed on BMC
        SENSOR::getSensorReadingData turboSupportData;
        SENSOR::SensorBase turboSensor(SENSOR_NAME_TURBO_ALLOWED, i_sys);
        errlHndl_t err = turboSensor.readSensorData(turboSupportData);
        if (NULL == err)
        {
            // 0x02 == Asserted bit (turbo frequency is allowed)
            if ((turboSupportData.event_status & 0x02) == 0x02)
            {
                TMGT_INF("bmcAllowsTurbo: turbo is allowed");
            }
            else
            {
                turboAllowed = false;
            }
        }
        else
        {
            // error reading sensor, assume turbo is allowed
            TMGT_ERR("bmcAllowsTurbo: unable to read turbo support sensor "
                     " from BMC, rc=0x%04X",
                     err->reasonCode());
            delete err;
        }
    }
    // else, sensor not supported on this platform so turbo is allowed

    return turboAllowed;
}


void getFrequencyPointMessageData(uint8_t* o_data,
                                  uint64_t & o_size)
{
    uint64_t index   = 0;
    uint16_t min     = 0;
    uint16_t turbo   = 0;
    uint16_t ultra   = 0;
    uint16_t nominal = 0;
    Target* sys = NULL;

    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);
    assert(o_data != NULL);

    int32_t biasFactor = 0;
    if (false == OccManager::isNormalPstate())
    {
        // Only apply bias if using mfg pstate tables
        Occ *master = OccManager::getMasterOcc();
        if (NULL != master)
        {
            errlHndl_t err = NULL;
            TARGETING::TargetHandle_t occTarget = master->getTarget();
            ConstTargetHandle_t procTarget = getParentChip(occTarget);
            assert(procTarget != NULL);
            const fapi::Target fapiTarget(fapi::TARGET_TYPE_PROC_CHIP,
                               (const_cast<TARGETING::Target*>(procTarget)));
            uint32_t biasUp   = 0;
            uint32_t biasDown = 0;
            int rc = FAPI_ATTR_GET(ATTR_FREQ_EXT_BIAS_UP,&fapiTarget,biasUp);
            rc |= FAPI_ATTR_GET(ATTR_FREQ_EXT_BIAS_DOWN,&fapiTarget,biasDown);
            if (0 == rc)
            {
                if ((biasDown > 0) && (biasUp == 0))
                {
                    TMGT_INF("FREQ_EXT_BIAS_DOWN=%d (in 0.5%% units)",biasDown);
                    biasFactor = -(biasDown);
                }
                else if ((biasUp > 0) && (biasDown == 0))
                {
                    biasFactor = biasUp;
                    TMGT_INF("FREQ_EXT_BIAS_UP=%d (in 0.5%% units)", biasUp);
                }
                else if ((biasUp > 0) && (biasDown > 0))
                {
                    TMGT_ERR("Invalid bias values: BIAS_UP=%d and BIAS_DOWN=%d",
                             biasUp, biasDown);
                    /*@
                     * @errortype
                     * @reasoncode  HTMGT_RC_INVALID_PARAMETER
                     * @moduleid    HTMGT_MOD_CFG_FREQ_POINTS
                     * @userdata1   ATTR_FREQ_EXT_BIAS_UP
                     * @userdata2   ATTR_FREQ_EXT_BIAS_DOWN
                     * @devdesc     Invalid ATTR_FREQ_EXT_BIAS attribute values
                     */
                    bldErrLog(err, HTMGT_MOD_CFG_FREQ_POINTS,
                              HTMGT_RC_INVALID_PARAMETER,
                              0, biasUp, 0, biasDown,
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                    ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                }
            }
            else
            {
                TMGT_ERR("Unable to read ATTR_FREQ_EXT_BIAS values rc=%d", rc);
                /*@
                 * @errortype
                 * @reasoncode       HTMGT_RC_ATTRIBUTE_ERROR
                 * @moduleid         HTMGT_MOD_CFG_FREQ_POINTS
                 * @userdata1[0-31]  rc
                 * @userdata1[32-63] ATTR_FREQ_EXT_BIAS_UP
                 * @userdata2        ATTR_FREQ_EXT_BIAS_DOWN
                 * @devdesc          Unable to read FREQ_EXT_BIAS attributes
                 */
                bldErrLog(err, HTMGT_MOD_CFG_FREQ_POINTS,
                          HTMGT_RC_ATTRIBUTE_ERROR,
                          rc, biasUp, 0, biasDown,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
            }
        }
    }

    o_data[index++] = OCC_CFGDATA_FREQ_POINT;
    o_data[index++] = OCC_CFGDATA_FREQ_POINT_VERSION;

    //Nominal Frequency in MHz
    nominal = sys->getAttr<ATTR_NOMINAL_FREQ_MHZ>();
    if (biasFactor)
    {
        TMGT_INF("Pre-biased Nominal=%dMhz", nominal);
        // % change = (biasFactor/2) / 100
        nominal += ((nominal * biasFactor) / 200);
    }
    memcpy(&o_data[index], &nominal, 2);
    index += 2;

    // Check if MRW allows turbo
    uint8_t turboAllowed =
        sys->getAttr<ATTR_OPEN_POWER_TURBO_MODE_SUPPORTED>();
    if (turboAllowed)
    {
        // Check if BMC allows turbo
        if (bmcAllowsTurbo(sys))
        {
            turbo = sys->getAttr<ATTR_FREQ_CORE_MAX>();

            //Ultra Turbo Frequency in MHz
            const uint16_t wofSupported = sys->getAttr<ATTR_WOF_ENABLED>();
            if (0 != wofSupported)
            {
                ultra = sys->getAttr<ATTR_ULTRA_TURBO_FREQ_MHZ>();
                if (0 != ultra)
                {
                    if (biasFactor)
                    {
                        TMGT_INF("Pre-biased Ultra=%dMhz", ultra);
                        // % change = (biasFactor/2) / 100
                        ultra += ((ultra * biasFactor) / 200);
                    }
                }
                else
                {
                    TMGT_INF("getFrequencyPoint: WOF enabled, but freq is 0");
                    G_wofSupported = false;
                }
            }
            else
            {
                TMGT_INF("getFrequencyPoint: WOF not enabled");
                G_wofSupported = false;
            }
        }
        else
        {
            TMGT_INF("getFrequencyPoint: Turbo/WOF not allowed by BMC");
            TMGT_CONSOLE("Turbo frequency not allowed due to BMC limit");
            turbo = nominal;
            G_wofSupported = false;
        }
    }
    else
    {
        // If turbo not supported, send nominal for turbo
        // and 0 for ultra-turbo (no WOF support)
        TMGT_INF("getFrequencyPoint: Turbo/WOF not supported");
        TMGT_CONSOLE("Turbo frequency not supported");
        turbo = nominal;
        G_wofSupported = false;
    }
    if (biasFactor)
    {
        TMGT_INF("Pre-biased Turbo=%dMhz", turbo);
        // % change = (biasFactor/2) / 100
        turbo += ((turbo * biasFactor) / 200);
    }

    //Turbo Frequency in MHz
    memcpy(&o_data[index], &turbo, 2);
    index += 2;

    //Minimum Frequency in MHz
    min = sys->getAttr<ATTR_MIN_FREQ_MHZ>();
    if (biasFactor)
    {
        TMGT_INF("Pre-biased Min=%dMhz", min);
        // % change = (biasFactor/2) / 100
        min += ((min * biasFactor) / 200);
    }
    memcpy(&o_data[index], &min, 2);
    index += 2;

    //Ultra Turbo Frequency in MHz
    memcpy(&o_data[index], &ultra, 2);
    index += 2;

    TMGT_INF("Frequency Points: Min %d, Nominal %d, Turbo %d, Ultra %d MHz",
             min, nominal, turbo, ultra);

    o_size = index;
}


void getPstateTableMessageData(const TargetHandle_t i_occTarget,
                               uint8_t* o_data,
                               uint64_t & io_size)
{
    // normal and mfg pstate tables are the same size: see genPstateTables()
    uint64_t msg_size = sizeof(ATTR_PSTATE_TABLE_type) + 4;
    assert(io_size >= msg_size);

    if(io_size > msg_size)
    {
        io_size = msg_size;
    }

    o_data[0] = OCC_CFGDATA_PSTATE_SSTRUCT;
    o_data[1] = 0;  // reserved
    o_data[2] = 0;  // reserved
    o_data[3] = 0;  // reserved

    if (OccManager::isNormalPstate())
    {
        TMGT_INF("getPstateTableMessageData: Sending normal tables");
        // Read data from attribute for specified occ
        ATTR_PSTATE_TABLE_type * pstateDataPtr =
            reinterpret_cast<ATTR_PSTATE_TABLE_type*>(o_data + 4);

        i_occTarget->tryGetAttr<ATTR_PSTATE_TABLE>(*pstateDataPtr);
    }
    else
    {
        TMGT_INF("getPstateTableMessageData: Sending MFG tables");
        ATTR_PSTATE_TABLE_MFG_type * pstateDataPtr =
            reinterpret_cast<ATTR_PSTATE_TABLE_MFG_type*>(o_data + 4);

        i_occTarget->tryGetAttr<ATTR_PSTATE_TABLE_MFG>(*pstateDataPtr);
    }
}



void getApssMessageData(uint8_t* o_data,
                        uint64_t & o_size)
{
    Target* sys = NULL;
    targetService().getTopLevelTarget(sys);

    ATTR_ADC_CHANNEL_FUNC_IDS_type function;
    sys->tryGetAttr<ATTR_ADC_CHANNEL_FUNC_IDS>(function);

    ATTR_ADC_CHANNEL_GNDS_type ground;
    sys->tryGetAttr<ATTR_ADC_CHANNEL_GNDS>(ground);

    ATTR_ADC_CHANNEL_GAINS_type gain;
    sys->tryGetAttr<ATTR_ADC_CHANNEL_GAINS>(gain);

    ATTR_ADC_CHANNEL_OFFSETS_type offset;
    sys->tryGetAttr<ATTR_ADC_CHANNEL_OFFSETS>(offset);

    CPPASSERT(sizeof(function) == sizeof(ground));
    CPPASSERT(sizeof(function) == sizeof(gain));
    CPPASSERT(sizeof(function) == sizeof(offset));

    //The APSS function below hardcodes 16 channels,
    //so everything better agree.
    CPPASSERT(sizeof(function) == 16);
    const uint16_t (*sensors)[16] = NULL;

#ifdef CONFIG_BMC_IPMI
    errlHndl_t err = SENSOR::getAPSSChannelSensorNumbers(sensors);
    if (err)
    {
        TMGT_ERR("getApssMessageData: Call to getAPSSChannelSensorNumbers "
                 "failed.");
        ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
        sensors = NULL;
    }
#endif

    o_data[0] = OCC_CFGDATA_APSS_CONFIG;
    o_data[1] = OCC_CFGDATA_APSS_VERSION;
    o_data[2] = 0;
    o_data[3] = 0;
    uint64_t idx = 4;
    uint16_t sensorId = 0;

    for(uint64_t channel = 0; channel < sizeof(function); ++channel)
    {
        o_data[idx] = function[channel]; // ADC Channel assignement
        idx += sizeof(uint8_t);

        sensorId = 0;
        if (sensors != NULL)
        {
            sensorId = (*sensors)[channel];
        }
        memcpy(o_data+idx,&sensorId,sizeof(uint16_t)); // Sensor ID
        idx += sizeof(uint16_t);

        o_data[idx] = ground[channel];   // Ground Select
        idx += sizeof(uint8_t);

        memcpy(o_data+idx, &gain[channel], sizeof(uint32_t));  // Gain
        idx += sizeof(uint32_t);

        memcpy(o_data+idx, &offset[channel], sizeof(uint32_t));   // offset
        idx += sizeof(uint32_t);
    }

    ATTR_APSS_GPIO_PORT_MODES_type  gpioMode;
    sys->tryGetAttr<ATTR_APSS_GPIO_PORT_MODES>(gpioMode);

    ATTR_APSS_GPIO_PORT_PINS_type gpioPin;
    sys->tryGetAttr<ATTR_APSS_GPIO_PORT_PINS>(gpioPin);

    uint64_t pinsPerPort = sizeof(ATTR_APSS_GPIO_PORT_PINS_type) /
        sizeof(ATTR_APSS_GPIO_PORT_MODES_type);
    uint64_t pinIdx = 0;

    for(uint64_t port = 0; port < sizeof(gpioMode); ++port)
    {
        o_data[idx] = gpioMode[port];
        idx += sizeof(uint8_t);
        o_data[idx] = 0;
        idx += sizeof(uint8_t);
        memcpy(o_data + idx, gpioPin+pinIdx, pinsPerPort);
        idx += pinsPerPort;
        pinIdx += pinsPerPort;
    }

    o_size = idx;
}

void getWofCoreFrequencyData(const TargetHandle_t i_occ,
                             uint8_t * o_data,
                             uint64_t & o_size)
{
    assert(o_data != NULL);
    uint64_t index = 0;
    Target* sys = NULL;
    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);
    ConstTargetHandle_t proc = getParentChip(i_occ);
    assert(proc != NULL);

    // Count the number of cores that are good on each chip without
    // regard to being GARDED.  Cores that are deconfigured do not
    // affect this number. This is the number of present cores
    // (max - partial bad).
    TARGETING::TargetHandleList l_presCoreList;
    getChildAffinityTargetsByState(l_presCoreList,
                                   proc,
                                   TARGETING::CLASS_UNIT,
                                   TARGETING::TYPE_CORE,
                                   TARGETING::UTIL_FILTER_PRESENT);
    const uint8_t maxCoresPerChip = l_presCoreList.size();

    o_data[index++] = OCC_CFGDATA_WOF_CORE_FREQ;
    o_data[index++] = OCC_CFGDATA_WOF_CORE_FREQ_VERSION;
    o_data[index++] = maxCoresPerChip;
    memset(&o_data[index], 0, 3); // reserved
    index += 3;

    uint8_t numRows = 0;
    uint8_t numColumns = 0;
    const uint16_t tablesize=sizeof(ATTR_WOF_FREQUENCY_UPLIFT_SELECTED_type);
    if (G_wofSupported)
    {
        numRows = 22;
        numColumns = 13;
        TMGT_INF("getWofCoreFrequencyData: %d rows, %d cols (0x%04X bytes)",
                 numRows, numColumns, tablesize);
        assert(tablesize == numRows * numColumns * 2);
    }
    o_data[index++] = numRows;
    o_data[index++] = numColumns;

    if (G_wofSupported)
    {
        // Host Boot will determine correct chip sort and pick correct
        // frequncy uplift table
        ATTR_WOF_FREQUENCY_UPLIFT_SELECTED_type * upliftTable =
            reinterpret_cast<ATTR_WOF_FREQUENCY_UPLIFT_SELECTED_type*>
            (&o_data[index]);

        proc->tryGetAttr<ATTR_WOF_FREQUENCY_UPLIFT_SELECTED>(*upliftTable);
        TMGT_BIN("WOF CoreFrequency Data", upliftTable, tablesize);

        // first table entry must be 0s
        memset(&o_data[index], 0, 2);

        index += tablesize;
    }

    o_size = index;

} // end getWofCoreFrequencyData()


void getWofVrmEfficiencyData(uint8_t* o_data,
                             uint64_t & o_size)
{
    assert(o_data != NULL);
    uint64_t index = 0;
    Target* sys = NULL;
    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);

    o_data[index++] = OCC_CFGDATA_WOF_VRM_EFF;
    o_data[index++] = OCC_CFGDATA_WOF_VRM_EFF_VERSION;
    memset(&o_data[index], 0, 4); // reserved
    index += 4;

    uint8_t numRows = 0;
    uint8_t numColumns = 0;
    const uint16_t tablesize = sizeof(ATTR_WOF_REGULATOR_EFFICIENCIES_type);
    if (G_wofSupported)
    {
        numRows = 3;
        numColumns = 14;
        TMGT_INF("getWofVrmEfficiencyData: %d rows, %d cols (0x%04X bytes)",
                 numRows, numColumns, tablesize);
        assert(tablesize == numRows * numColumns * 2);
    }
    o_data[index++] = numRows;
    o_data[index++] = numColumns;

    if (G_wofSupported)
    {
        // VRM efficiency table is unique per system

        ATTR_WOF_REGULATOR_EFFICIENCIES_type * regEffDataPtr =
            reinterpret_cast<ATTR_WOF_REGULATOR_EFFICIENCIES_type*>
            (&o_data[index]);

        sys->tryGetAttr<ATTR_WOF_REGULATOR_EFFICIENCIES>(*regEffDataPtr);
        TMGT_BIN("WOF VRM Efficiency Data", regEffDataPtr, tablesize);

        // first table entry must be 0s
        memset(&o_data[index], 0, 2);

        index += tablesize;
    }

    o_size = index;

} // end getWofVrmEfficiencyData()



}
