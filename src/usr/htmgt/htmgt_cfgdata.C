/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_cfgdata.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#include <htmgt/htmgt_reasoncodes.H>
#include <fapi2_attribute_service.H>

using namespace TARGETING;


//for unit testing
//#define TRACUCOMP(args...)  TMGT_INF(args)
#define TRACUCOMP(args...)

namespace HTMGT
{

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

                            case OCC_CFGDATA_AVSBUS_CONFIG:
                                getAVSBusConfigMessageData( occ->getTarget(),
                                                            cmdData,
                                                            cmdDataLen );
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
                            if (l_err != nullptr)
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
    OCC_CFGDATA_FREQ_POINT_VERSION    = 0x20,
    OCC_CFGDATA_APSS_VERSION          = 0x20,
    OCC_CFGDATA_MEM_CONFIG_VERSION    = 0x21,
    OCC_CFGDATA_PCAP_CONFIG_VERSION   = 0x20,
    OCC_CFGDATA_SYS_CONFIG_VERSION    = 0x20,
    OCC_CFGDATA_MEM_THROTTLE_VERSION  = 0x20,
    OCC_CFGDATA_TCT_CONFIG_VERSION    = 0x20,
    OCC_CFGDATA_AVSBUS_CONFIG_VERSION = 0X01,
};


// Utility function for writing Memory Config data
void writeMemConfigData( uint8_t *& o_data,
                         TARGETING::Target * i_target,
                         TARGETING::SENSOR_NAME i_sensorState,
                         TARGETING::SENSOR_NAME i_sensorTemp,
                         uint8_t i_centPos,
                         uint8_t i_dimmPos,
                         uint8_t i_i2cPort,
                         uint8_t i_i2cDevAddr,
                         uint64_t & io_index )
{

    //Byte 0-3 Hardware Sensor ID
    uint32_t l_sensor = UTIL::getSensorNumber( i_target,i_sensorState );
    size_t l_dataSize = sizeof(l_sensor);
    memcpy(&o_data[io_index],
           reinterpret_cast<uint8_t*>(&l_sensor),
           l_dataSize);
    io_index += l_dataSize;

    //Byte 4-7 Temperature Sensor ID
    l_sensor = UTIL::getSensorNumber( i_target,i_sensorTemp );
    memcpy(&o_data[io_index],
           reinterpret_cast<uint8_t*>(&l_sensor),
           l_dataSize);
    io_index += l_dataSize;

    //Byte 8  Nimbus     indicator
    //        Cumulus     (Centaur #)
    o_data[io_index++] = i_centPos;

    //Byte 9  Nimbus     PIB I2C Master Engine
    //        Cumulus    (DIMM #)
    o_data[io_index++] = i_dimmPos;

    //Byte 10 Nimbus    DIMM I2C Port(0,1)
    //        Cumulus   Reserved for Cumulus
    o_data[io_index++] = i_i2cPort;

    //Byte 11 Nimbus    DIMM Temp i2c address
    //        Cumulus   Reserved for Cumulus
    o_data[io_index++] = i_i2cDevAddr;

}


void getMemConfigMessageData(const TargetHandle_t i_occ,
                             bool i_monitoringEnabled,
                             uint8_t* o_data, uint64_t & o_size)
{
    uint64_t index = 0;

    assert(o_data != nullptr);

    o_data[index++] = OCC_CFGDATA_MEM_CONFIG;
    o_data[index++] = OCC_CFGDATA_MEM_CONFIG_VERSION;


    //System reference needed for these ATTR.
    Target* sys = nullptr;
    targetService().getTopLevelTarget(sys);


    if( is_sapphire_load() )//if OPAL then no "Power Control Default" support.
    {
        //Byte 3:   Memory Power Control Default.
        o_data[index++] = 0xFF;

        //Byte 4:   Idle Power Memory Power Control.
        o_data[index++] = 0xFF;
    }
    else                    //else read in attr.
    {
        //Byte 3:   Memory Power Control Default.
        o_data[index++] = sys->getAttr<ATTR_MSS_MRW_POWER_CONTROL_REQUESTED>();

        //Byte 4:   Idle Power Memory Power Control.
        o_data[index++] =
                    sys->getAttr<ATTR_MSS_MRW_IDLE_POWER_CONTROL_REQUESTED>();
    }




    //Byte 5:   Number of data sets.
    size_t numSetsOffset = index++; //Will fill in numSets at the end


    if (i_monitoringEnabled)
    {
        TargetHandleList centaurs;
        TargetHandleList mbas;
        TargetHandleList dimms;
        uint8_t centPos = 0;
        uint8_t dimmPos = 0;
        uint8_t numSets = 0;


        ConstTargetHandle_t proc = getParentChip(i_occ);
        assert(proc != nullptr);

        // Save Processor Model for later
        ATTR_MODEL_type l_procModel = proc->getAttr<ATTR_MODEL>();

        if( l_procModel == MODEL_CUMULUS )
        {
            getChildAffinityTargets(centaurs, proc, CLASS_CHIP, TYPE_MEMBUF);

            TRACUCOMP("Proc 0x%X has %d centaurs",
                      proc->getAttr<ATTR_HUID>(),
                      centaurs.size());


            for ( const auto & centaur : centaurs )
            {
                numSets++;

                // TODO: RTC 163359 - OCC centaur support
                // Get the Centaur position
                centPos = centaur->getAttr<ATTR_POSITION>();
                // ATTR_POSISTION is system wide. Must be 0-7 on each OCC
                centPos = centPos%8;

                //Do the entry for the Centaur itself
                writeMemConfigData( o_data,
                                    centaur,
                                    SENSOR_NAME_MEMBUF_STATE,
                                    SENSOR_NAME_MEMBUF_TEMP,
                                    centPos,
                                    0xFF, //0xFF since a centaur
                                    0,    //Reserved for CUMULUS
                                    0,    //" "
                                    index );


                mbas.clear();
                getChildAffinityTargets(mbas, centaur,
                                        CLASS_UNIT, TYPE_MBA);

                for ( const auto & mba : mbas )
                {
                    dimms.clear();
                    getChildAffinityTargets(dimms, mba,
                                            CLASS_LOGICAL_CARD, TYPE_DIMM);

                    TRACUCOMP("MBA 0x%X has %d DIMMs",
                              mba->getAttr<ATTR_HUID>(), dimms.size());

                    for ( const auto & dimm : dimms )
                    {
                        numSets++;

                        // get the DIMM #
                        dimmPos = getOCCDIMMPos( mba, dimm );

                        // Fill in the DIMM entry
                        writeMemConfigData( o_data,
                                        dimm,
                                        SENSOR_NAME_DIMM_STATE,
                                        SENSOR_NAME_DIMM_TEMP,
                                        centPos,
                                        dimmPos,
                                        0,      //Reserved for CUMULUS
                                        0,      //"  "
                                        index );
                    }
                }
            }
        }
        else if( l_procModel == MODEL_NIMBUS )
        {
            // DIMMs are wired directly to the proc in Nimbus
            dimms.clear();
            getChildAffinityTargets( dimms,
                                     proc,
                                     CLASS_LOGICAL_CARD,
                                     TYPE_DIMM );

            for( const auto & dimm : dimms )
            {
                numSets++;

                // Get PIB I2C Master engine for this dimm
                ATTR_TEMP_SENSOR_I2C_CONFIG_type tempI2cCfgData =
                    dimm->getAttr<ATTR_TEMP_SENSOR_I2C_CONFIG>();

                // Fill in the DIMM entry
                writeMemConfigData( o_data,
                                dimm,
                                SENSOR_NAME_DIMM_STATE,//Bytes 0-3:HW sensor ID
                                SENSOR_NAME_DIMM_TEMP, //Bytes 4-7:TMP sensor ID
                                0xFF,                  //Bytes 8:MEM Nimbus,
                                tempI2cCfgData.engine, //Byte 9: DIMM Info byte1
                                tempI2cCfgData.port,   //Byte 10:DIMM Info byte2
                                tempI2cCfgData.devAddr,//Byte 11:DIMM Info byte3
                                index );
            }
        }//End MODEL_NIMBUS

        TMGT_INF("getMemConfigMessageData: returning %d"
                 " sets of data for OCC 0x%X",
                 numSets, i_occ->getAttr<ATTR_HUID>());

        o_data[numSetsOffset] = numSets;
    }//END i_monitoringEnabled
    else
    {
        TMGT_INF("getMemConfigMessageData: Mem monitoring is disabled");

        //A zero in byte 5 (numSets) means monitoring is disabled
        o_data[numSetsOffset] = 0;
    }

    o_size = index;

}




void getMemThrottleMessageData(const TargetHandle_t i_occ,
                               uint8_t* o_data, uint64_t & o_size)
{
    uint8_t numSets = 0;
    uint64_t index = 0;

    ConstTargetHandle_t proc = getParentChip(i_occ);
    assert(proc != nullptr);
    assert(o_data != nullptr);

    TargetHandleList centaurs;

    o_data[index++] = OCC_CFGDATA_MEM_THROTTLE;
    o_data[index++] = OCC_CFGDATA_MEM_THROTTLE_VERSION;

    //Byte 3:   Number of memory throttling data sets.
    size_t numSetsOffset = index++; //Will fill in numSets at the end


    getChildAffinityTargets(centaurs, proc, CLASS_CHIP, TYPE_MEMBUF);

    //Next, the following format repeats per set/MBA:
    //Byte 0:       Cumulus: Centaur position 0-7
    //              Nimbus : Memory Controller
    //Byte 1:       Cumulus: MBA Position 0-1
    //              Nimbus : Memory Controller's physical Port # 0-3
    //Bytes 2-3:    min N_PER_MBA
    //Bytes 4-5:    Max mem power with throttle @Min
    //Bytes 6-7:    Turbo N_PER_MBA
    //Bytes 8-9:    Turbo N_PER_CHIP
    //Bytes 10-11:  Max mem power with throttle @Turbo
    //Bytes 12-13:  Power Capping N_PER_MBA
    //Bytes 14-15:  Power Capping N_PER_MBA
    //Bytes 16-17:  Max mem power with throttle @PowerCapping
    //Bytes 18-19:  Nominal Power N_PER_MBA
    //Bytes 20-21:  Nominal Power N_PER_CHIP
    //Bytes 22-23:  Max mem power with throttle @Nominal
    //Bytes 24-29:  Reserved

    // Hard coding until we can get mem throttle cfg data
    for (uint8_t entry = 0; entry < 2; ++entry)
    {
        o_data[index++] = 0x00; //MC01
        o_data[index++] = entry; // Port
        o_data[index++] = 0x44; // Min N Per MBA
        o_data[index++] = 0x44;
        o_data[index++] = 0x01; // Max mem pwr at min throttle
        o_data[index++] = 0x00;
        o_data[index++] = 0x45; // Turbo N per MBA
        o_data[index++] = 0x56;
        o_data[index++] = 0x55; // Turbo N per chip
        o_data[index++] = 0x5F;
        o_data[index++] = 0x01; // Max mem pwr at turbo
        o_data[index++] = 0x10;
        o_data[index++] = 0x45; // Power capping N per MBA
        o_data[index++] = 0x56;
        o_data[index++] = 0x55; // Power capping N per chip
        o_data[index++] = 0x5F;
        o_data[index++] = 0x01; // Max mem pwr at power capping
        o_data[index++] = 0x20;
        o_data[index++] = 0x45; // Nominal N per MBA
        o_data[index++] = 0x56;
        o_data[index++] = 0x55; // Nominal N per chip
        o_data[index++] = 0x5F;
        o_data[index++] = 0x01; // Max mem pwr at Nominal
        o_data[index++] = 0x30;
        o_data[index++] = 0x00; // reserved
        o_data[index++] = 0x00;
        o_data[index++] = 0x00;
        o_data[index++] = 0x00;
        o_data[index++] = 0x00;
        o_data[index++] = 0x00;
        ++numSets ;
    }


    TMGT_INF("getMemThrottleMessageData: returning %d"
             " sets of data for OCC 0x%X",
             numSets, i_occ->getAttr<ATTR_HUID>());

    o_data[numSetsOffset] = numSets;

    o_size = index;

}



void getOCCRoleMessageData(bool i_master, bool i_firMaster,
                           uint8_t* o_data, uint64_t & o_size)
{
    assert(o_data != nullptr);

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
            if (nullptr == err)
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

    Target* sys = nullptr;
    targetService().getTopLevelTarget(sys);

    assert(sys != nullptr);
    assert(o_data != nullptr);

    o_data[index++] = OCC_CFGDATA_PCAP_CONFIG;
    o_data[index++] = OCC_CFGDATA_PCAP_CONFIG_VERSION;


    // Minimum HARD Power Cap
    ATTR_OPEN_POWER_MIN_POWER_CAP_WATTS_type pcap =
        sys->getAttr<ATTR_OPEN_POWER_MIN_POWER_CAP_WATTS>();


    // Minimum SOFT Power Cap
    ATTR_OPEN_POWER_SOFT_MIN_PCAP_WATTS_type soft_pcap;
     //if attr does not exists.
    if ( ! sys->tryGetAttr
            <ATTR_OPEN_POWER_SOFT_MIN_PCAP_WATTS>(soft_pcap))
    {
        soft_pcap = pcap;
    }


    // Minimum Soft Power Cap
    TMGT_INF("getPowerCapMessageData: minimum soft power cap =%dW",soft_pcap);
    memcpy(&o_data[index], &soft_pcap, 2);
    index += 2;

    // Minimum Hard Power Cap
    TMGT_INF("getPowerCapMessageData: minimum hard power cap = %dW",pcap);
    memcpy(&o_data[index], &pcap, 2);
    index += 2;

    // System Maximum Power Cap
    pcap = getMaxPowerCap(sys);
    memcpy(&o_data[index], &pcap, 2);
    index += 2;

    // Quick Power Drop Power Cap
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
    assert(o_data != nullptr);

    o_data[index++] = OCC_CFGDATA_SYS_CONFIG;
    o_data[index++] = OCC_CFGDATA_SYS_CONFIG_VERSION;

    //System Type
    o_data[index++] = OCC_CFGDATA_OPENPOWER_SYSTEMTYPE;

    //processor sensor ID
    ConstTargetHandle_t proc = getParentChip(i_occ);
    sensor = UTIL::getSensorNumber(proc, SENSOR_NAME_PROC_STATE);
    memcpy(&o_data[index], &sensor, 4);
    index += 4;

    //Next 12*4 bytes are for core sensors.
    //If a new processor with more cores comes along,
    //this command will have to change.
    TargetHandleList cores;
    TargetHandleList::iterator coreIt;
    getChildChiplets(cores, proc, TYPE_CORE, false);

    uint32_t tempSensor = 0;
    uint32_t freqSensor = 0;
    for (uint64_t core=0; core<CFGDATA_CORES; core++)
    {
        tempSensor = 0;
        freqSensor = 0;

        if ( core < cores.size() )
        {
            tempSensor = UTIL::getSensorNumber(cores[core],
                                               SENSOR_NAME_CORE_TEMP);

            freqSensor = UTIL::getSensorNumber(cores[core],
                                               SENSOR_NAME_CORE_FREQ);
        }

        //Core Temp Sensor ID
        memcpy(&o_data[index], &tempSensor, 4);
        index += 4;

        //Core Frequency Sensor ID
        memcpy(&o_data[index], &freqSensor, 4);
        index += 4;
    }

    TargetHandle_t sys = nullptr;
    TargetHandleList nodes;
    targetService().getTopLevelTarget(sys);
    assert(sys != nullptr);
    getChildAffinityTargets(nodes, sys, CLASS_ENC, TYPE_NODE);
    assert(!nodes.empty());
    TargetHandle_t node = nodes[0];


    //Backplane sensor ID
    sensor = UTIL::getSensorNumber(node, SENSOR_NAME_BACKPLANE_FAULT);
    memcpy(&o_data[index], &sensor, 4);
    index += 4;

    //APSS sensor ID
    sensor = UTIL::getSensorNumber(sys, SENSOR_NAME_APSS_FAULT);
    memcpy(&o_data[index], &sensor, 4);
    index += 4;

    o_size = index;
}


void getThermalControlMessageData(uint8_t* o_data,
                                  uint64_t & o_size)
{
    uint64_t index = 0;
    uint8_t l_numSets = 0;
    Target* l_sys = nullptr;
    targetService().getTopLevelTarget(l_sys);

    assert(l_sys != nullptr);
    assert(o_data != nullptr);

    o_data[index++] = OCC_CFGDATA_TCT_CONFIG;
    o_data[index++] = OCC_CFGDATA_TCT_CONFIG_VERSION;

    // Get the master processor target to get the system type
    Target* l_masterProc = nullptr;
    targetService().masterProcChipTargetHandle( l_masterProc );
    ATTR_MODEL_type l_systemType = l_masterProc->getAttr<ATTR_MODEL>();


    // Processor Core Weight
    ATTR_OPEN_POWER_PROC_WEIGHT_type l_proc_weight;
    if ( ! l_sys->tryGetAttr          //if attr does not exists.
           <ATTR_OPEN_POWER_PROC_WEIGHT>(l_proc_weight))
    {
        l_proc_weight = OCC_PROC_QUAD_DEFAULT_WEIGHT;
    }
    if(l_proc_weight == 0x0)
    {
        l_proc_weight = OCC_PROC_QUAD_DEFAULT_WEIGHT;
    }
    o_data[index++] = l_proc_weight;


    // Processor Quad Weight
    ATTR_OPEN_POWER_QUAD_WEIGHT_type l_quad_weight;
    if ( ! l_sys->tryGetAttr          //if attr does not exists.
           <ATTR_OPEN_POWER_QUAD_WEIGHT>(l_quad_weight))
    {
        l_quad_weight = OCC_PROC_QUAD_DEFAULT_WEIGHT;
    }
    if(l_quad_weight == 0x0)
    {
        l_quad_weight = OCC_PROC_QUAD_DEFAULT_WEIGHT;
    }
    o_data[index++] = l_quad_weight;


    // data sets following (proc, Centaur(Cumulus only), DIMM), and
    // each will get a FRU type, DVS temp, error temp,
    // and max read timeout
    size_t l_numSetsOffset = index++;

    // Note: Bytes 4 and 5 of each data set represent the PowerVM DVFS and ERROR
    // Resending the regular DVFS and ERROR for now

    // Processor
    o_data[index++] = CFGDATA_FRU_TYPE_PROC;
    uint8_t l_DVFS_temp =l_sys->getAttr<ATTR_OPEN_POWER_PROC_DVFS_TEMP_DEG_C>();
    uint8_t l_ERR_temp =l_sys->getAttr<ATTR_OPEN_POWER_PROC_ERROR_TEMP_DEG_C>();
    uint8_t l_timeout = l_sys->getAttr<ATTR_OPEN_POWER_PROC_READ_TIMEOUT_SEC>();
    if(l_DVFS_temp == 0x0)
    {
        l_DVFS_temp = OCC_PROC_DEFAULT_DVFS_TEMP;
        l_ERR_temp  = OCC_PROC_DEFAULT_ERR_TEMP;
        l_timeout   = OCC_PROC_DEFAULT_TIMEOUT;
    }
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = OCC_NOT_DEFINED;     //PM_DVFS
    o_data[index++] = OCC_NOT_DEFINED;     //PM_ERROR
    o_data[index++] = l_timeout;
    l_numSets++;

    // If Nimbus, skip non-existent Centaurs
    if( l_systemType != MODEL_NIMBUS )
    {
        // Centaur
        o_data[index++] = CFGDATA_FRU_TYPE_MEMBUF;
        o_data[index++] =
                l_sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_THROTTLE_TEMP_DEG_C>();
        o_data[index++] =
                l_sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_ERROR_TEMP_DEG_C>();
        o_data[index++] = OCC_NOT_DEFINED;     //PM_DVFS
        o_data[index++] = OCC_NOT_DEFINED;     //PM_ERROR
        o_data[index++] =
                l_sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_READ_TIMEOUT_SEC>();
        l_numSets++;
    }

    // Dimm
    o_data[index++] = CFGDATA_FRU_TYPE_DIMM;
    l_DVFS_temp =l_sys->getAttr<ATTR_OPEN_POWER_DIMM_THROTTLE_TEMP_DEG_C>();
    l_ERR_temp =l_sys->getAttr<ATTR_OPEN_POWER_DIMM_ERROR_TEMP_DEG_C>();
    l_timeout = l_sys->getAttr<ATTR_OPEN_POWER_DIMM_READ_TIMEOUT_SEC>();
    if(l_DVFS_temp == 0x0)
    {
        l_DVFS_temp = OCC_DIMM_DEFAULT_DVFS_TEMP;
        l_ERR_temp  = OCC_DIMM_DEFAULT_ERR_TEMP;
        l_timeout   = OCC_DIMM_DEFAULT_TIMEOUT;
    }
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = OCC_NOT_DEFINED;     //PM_DVFS
    o_data[index++] = OCC_NOT_DEFINED;     //PM_ERROR
    o_data[index++] = l_timeout;
    l_numSets++;

    o_data[l_numSetsOffset] = l_numSets;
    o_size = index;


}


void getAVSBusConfigMessageData( const TargetHandle_t i_occ,
                                 uint8_t * o_data,
                                 uint64_t & o_size )
{
    uint64_t index      = 0;

    assert( o_data != nullptr );

    // Get the parent processor
    ConstTargetHandle_t l_proc = getParentChip( i_occ );
    assert( l_proc != nullptr );

    // Populate the data
    o_data[index++] = OCC_CFGDATA_AVSBUS_CONFIG;
    o_data[index++] = OCC_CFGDATA_AVSBUS_CONFIG_VERSION;
    o_data[index++] = l_proc->getAttr<ATTR_VDD_AVSBUS_BUSNUM>();//Vdd Bus
    o_data[index++] = l_proc->getAttr<ATTR_VDD_AVSBUS_RAIL>();  //Vdd Rail Sel
    o_data[index++] = 0xFF;                                     //reserved
    o_data[index++] = 0xFF;                                     //reserved
    o_data[index++] = l_proc->getAttr<ATTR_VDN_AVSBUS_BUSNUM>();//Vdn Bus
    o_data[index++] = l_proc->getAttr<ATTR_VDN_AVSBUS_RAIL>();  //Vdn Rail sel
    o_data[index++] = 0xFF;                                     //reserved
    o_data[index++] = 0xFF;                                     //reserved
    o_size = index;
}



void getFrequencyPointMessageData(uint8_t* o_data,
                                  uint64_t & o_size)
{
    uint64_t index   = 0;
    uint16_t min     = 0;
    uint16_t turbo   = 0;
    uint16_t ultra   = 0;
    uint16_t nominal = 0;
    Target* sys = nullptr;

    targetService().getTopLevelTarget(sys);
    assert(sys != nullptr);
    assert(o_data != nullptr);


    o_data[index++] = OCC_CFGDATA_FREQ_POINT;
    o_data[index++] = OCC_CFGDATA_FREQ_POINT_VERSION;

    //Nominal Frequency in MHz
    nominal = sys->getAttr<ATTR_NOMINAL_FREQ_MHZ>();
    memcpy(&o_data[index], &nominal, 2);
    index += 2;

    uint8_t turboAllowed =
        sys->getAttr<ATTR_OPEN_POWER_TURBO_MODE_SUPPORTED>();
    if (turboAllowed)
    {
        turbo = sys->getAttr<ATTR_FREQ_CORE_MAX>();

        //Ultra Turbo Frequency in MHz
        const uint16_t wofSupported = sys->getAttr<ATTR_WOF_ENABLED>();
        if (0 != wofSupported)
        {
            ultra = sys->getAttr<ATTR_ULTRA_TURBO_FREQ_MHZ>();
        }
        else
        {
            TMGT_INF("getFrequencyPoint: WOF not enabled");
            G_wofSupported = false;
        }
    }
    else
    {
        // If turbo not supported, send nominal for turbo
        // and 0 for ultra-turbo (no WOF support)
        TMGT_INF("getFrequencyPoint: Turbo/WOF not supported");
        turbo = nominal;
        G_wofSupported = false;
    }

    //Turbo Frequency in MHz
    memcpy(&o_data[index], &turbo, 2);
    index += 2;

    //Minimum Frequency in MHz
    min = sys->getAttr<ATTR_MIN_FREQ_MHZ>();

    memcpy(&o_data[index], &min, 2);
    index += 2;

    //Ultra Turbo Frequency in MHz
    memcpy(&o_data[index], &ultra, 2);
    index += 2;

    // Reserved (Static Power Save in PowerVM)
    memset(&o_data[index], 0, 2);
    index += 2;

    // Reserved (FFO in PowerVM)
    memset(&o_data[index], 0, 2);
    index += 2;

    TMGT_INF("Frequency Points: Min %d, Nominal %d, Turbo %d, Ultra %d MHz",
             min, nominal, turbo, ultra);

    o_size = index;
}



void getApssMessageData(uint8_t* o_data,
                        uint64_t & o_size)
{
    Target* sys = nullptr;
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
    const uint32_t (*sensors)[16] = nullptr;

#ifdef CONFIG_BMC_IPMI
    errlHndl_t err = SENSOR::getAPSSChannelSensorNumbers(sensors);
    if (err)
    {
        TMGT_ERR("getApssMessageData: Call to getAPSSChannelSensorNumbers "
                 "failed.");
        ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
        sensors = nullptr;
    }
#endif

    o_data[0] = OCC_CFGDATA_APSS_CONFIG;
    o_data[1] = OCC_CFGDATA_APSS_VERSION;
    o_data[2] = 0;
    o_data[3] = 0;
    uint64_t idx = 4;
    uint32_t sensorId = 0;

    for(uint64_t channel = 0; channel < sizeof(function); ++channel)
    {
        o_data[idx] = function[channel]; // ADC Channel assignement
        idx += sizeof(uint8_t);

        sensorId = 0;
        if (sensors != nullptr)
        {
            sensorId = (*sensors)[channel];
        }
        memcpy(o_data+idx,&sensorId,sizeof(uint32_t)); // Sensor ID
        idx += sizeof(uint32_t);

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



}
