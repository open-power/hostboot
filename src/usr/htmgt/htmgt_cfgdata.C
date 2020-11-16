/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_cfgdata.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2020                        */
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
#include <targeting/common/mfgFlagAccessors.H>
#include "htmgt_cfgdata.H"
#include "htmgt_utility.H"
#include "htmgt_poll.H"
#include "htmgt_occmanager.H"
#include "ipmi/ipmisensor.H"
#include <htmgt/htmgt_reasoncodes.H>
#include <fapi2_attribute_service.H>
#include "htmgt_memthrottles.H"
#include <isteps/pm/scopedHomerMapper.H>

using namespace TARGETING;


//for unit testing
//#define TRACUCOMP(args...)  TMGT_INF(args)
#define TRACUCOMP(args...)

namespace HTMGT
{

    bool G_wofSupported = true;
    uint8_t G_system_type = 0;

    // Send config format data to all OCCs
    errlHndl_t sendOccConfigData(const occCfgDataFormat i_requestedFormat)
    {
        errlHndl_t l_err = nullptr;
        uint8_t cmdData[OCC_MAX_DATA_LENGTH] = {0};

        if (G_debug_trace & DEBUG_TRACE_VERBOSE)
        {
            TMGT_INF("sendOccConfigData called");
        }

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

                // MAP HOMER for this OCC
                TARGETING::Target* procTarget = nullptr;
                procTarget = TARGETING::getImmediateParentByAffinity(occ->getTarget());
                HBPM::ScopedHomerMapper l_mapper(procTarget);
                l_err = l_mapper.map();
                if (l_err)
                {
                    TMGT_ERR("sendOccConfigData: Unable to get HOMER virtual address for OCC%d (rc=0x%04X)",
                             occInstance, l_err->reasonCode());
                    l_err->collectTrace(HTMGT_COMP_NAME);
                    l_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                    break;
                }
                occ->setHomerAddr(l_mapper.getHomerVirtAddr());

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
                        uint64_t cmdDataLen = 0;
                        switch(format)
                        {
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
                                getMemConfigMessageData(occ->getTarget(),
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
                                if (!int_flags_set(FLAG_DISABLE_MEM_CONFIG))
                                {
                                    getMemThrottleMessageData(occ->getTarget(),
                                                              occInstance, cmdData, cmdDataLen);
                                }
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

                            case OCC_CFGDATA_GPU_CONFIG:
                                getGPUConfigMessageData(occ->getTarget(),
                                                        cmdData,
                                                        cmdDataLen);
                                break;

                            default:
                                TMGT_ERR("sendOccConfigData: Unsupported"
                                         " format type 0x%02X",
                                         format);
                        }

                        if (cmdDataLen > 0)
                        {
                            TMGT_INF("sendOccConfigData: Sending config"
                                     " 0x%02X to OCC%d",
                                     format, occInstance);
                            OccCmd cmd(occ, OCC_CMD_SETUP_CFG_DATA,
                                       cmdDataLen, cmdData);
                            l_err = cmd.sendOccCmd();
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
                                             " 0x%02X",
                                             occInstance, format,
                                             cmd.getRspStatus());
                                }
                            }

                            // Send poll between config packets to flush errors
                            l_err = occ->pollForErrors(false);
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
                occ->invalidateHomer();

            } // for each OCC
        }

        return l_err;

    } // end sendOccConfigData()


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
                             uint8_t* o_data, uint64_t & o_size)
{
    uint64_t index = 0;

    assert(o_data != nullptr);

    o_data[index++] = OCC_CFGDATA_MEM_CONFIG;
    o_data[index++] = 0x21; // version

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

    if (!int_flags_set(FLAG_DISABLE_MEM_CONFIG))
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
    }
    else
    {
        TMGT_INF("getMemConfigMessageData: Mem monitoring is disabled");

        //A zero in byte 5 (numSets) means monitoring is disabled
        o_data[numSetsOffset] = 0;
    }

    o_size = index;

}




void getMemThrottleMessageData(const TargetHandle_t i_occ,
                               const uint8_t i_occ_instance,
                               uint8_t* o_data, uint64_t & o_size)
{
    uint8_t numSets = 0;
    uint64_t index = 0;

    ConstTargetHandle_t proc = getParentChip(i_occ);
    assert(proc != nullptr);
    assert(o_data != nullptr);

    //Get all functional MCSs
    TargetHandleList mcs_list;
    getAllChiplets(mcs_list, TYPE_MCS, true);
    TMGT_INF("getMemThrottleMessageData: found %d MCSs", mcs_list.size());

    o_data[index++] = OCC_CFGDATA_MEM_THROTTLE;
    o_data[index++] = 0x30; // version;

    //Byte 3:   Number of memory throttling data sets.
    size_t numSetsOffset = index++; //Will fill in numSets at the end

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
    //Bytes 14-15:  Power Capping N_PER_CHIP
    //Bytes 16-17:  Max mem power with throttle @PowerCapping
    //Bytes 18-19:  Nominal Power N_PER_MBA
    //Bytes 20-21:  Nominal Power N_PER_CHIP
    //Bytes 22-23:  Max mem power with throttle @Nominal
    //Bytes 24-29:  Reserved

    for(const auto & mcs_target : mcs_list)
    {
        uint8_t mcs_unit = 0xFF;
        if (!mcs_target->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(mcs_unit))
        {
            uint32_t mcs_huid = 0xFFFFFFFF;
            mcs_target->tryGetAttr<TARGETING::ATTR_HUID>(mcs_huid);
            TMGT_ERR("getMemThrottleMessageData: Unable to determine MCS unit"
                     " for HUID 0x%04X", mcs_huid);
            continue;
        }
        ConstTargetHandle_t proc_target = getParentChip(mcs_target);
        assert(proc_target != nullptr);

        // Make sure this MCS is for the current OCC/Proc
        if (i_occ_instance == proc_target->getAttr<TARGETING::ATTR_POSITION>())
        {
            // Read the throttle and power values for this MCS
            ATTR_OT_MIN_N_PER_MBA_type npm_min;
            ATTR_OT_MEM_POWER_type power_min;
            mcs_target->tryGetAttr<ATTR_OT_MIN_N_PER_MBA>(npm_min);
            mcs_target->tryGetAttr<ATTR_OT_MEM_POWER>(power_min);
            ATTR_N_PLUS_ONE_N_PER_MBA_type npm_redun;
            ATTR_N_PLUS_ONE_N_PER_CHIP_type npc_redun;
            ATTR_N_PLUS_ONE_MEM_POWER_type power_redun;
            mcs_target->tryGetAttr<ATTR_N_PLUS_ONE_N_PER_MBA>(npm_redun);
            mcs_target->tryGetAttr<ATTR_N_PLUS_ONE_N_PER_CHIP>(npc_redun);
            mcs_target->tryGetAttr<ATTR_N_PLUS_ONE_MEM_POWER>(power_redun);
            ATTR_POWERCAP_N_PER_MBA_type npm_pcap;
            ATTR_POWERCAP_N_PER_CHIP_type npc_pcap;
            ATTR_POWERCAP_MEM_POWER_type power_pcap;
            mcs_target->tryGetAttr<ATTR_POWERCAP_N_PER_MBA>(npm_pcap);
            mcs_target->tryGetAttr<ATTR_POWERCAP_N_PER_CHIP>(npc_pcap);
            mcs_target->tryGetAttr<ATTR_POWERCAP_MEM_POWER>(power_pcap);

            // Query the functional MCAs for this MCS
            TARGETING::TargetHandleList mca_list;
            getChildAffinityTargetsByState(mca_list, mcs_target, CLASS_UNIT,
                                           TYPE_MCA, UTIL_FILTER_FUNCTIONAL);
            for(const auto & mca_target : mca_list)
            {
                // unit identifies unique MCA under a processor
                uint8_t mca_unit = 0xFF;
                mca_target->tryGetAttr<TARGETING::ATTR_CHIP_UNIT>(mca_unit);
                const uint8_t mca_rel_pos = mca_unit % 2;
                if ((npm_min[mca_rel_pos] == 0) ||
                    (npm_redun[mca_rel_pos] == 0) ||
                    (npm_pcap[mca_rel_pos] == 0))
                {
                    TMGT_ERR("getMemThrottleMessageData: MCS%d/MCA%d [%d]"
                             " - Ignored due to null throttle",
                             mcs_unit, mca_unit, mca_rel_pos);
                    TMGT_ERR("N/slot: Min=%d, Turbo=%d, Pcap=%d",
                             npm_min[mca_rel_pos], npm_redun[mca_rel_pos],
                             npm_pcap[mca_rel_pos]);
                    continue;
                }
                if (mca_rel_pos >= TMGT_MAX_MCA_PER_MCS)
                {
                    TMGT_ERR("getMemThrottleMessageData: OCC%d / MCS%d / MCA%d"
                             " - Ignored due invalid MCA position: %d",
                             i_occ_instance, mcs_unit, mca_unit, mca_rel_pos);
                    continue;
                }
                TMGT_INF("getMemThrottleMessageData: OCC%d / MCS%d / MCA%d [%d]"
                         , i_occ_instance, mcs_unit, mca_unit, mca_rel_pos);
                // OCC expects phyMC=0 for (MCS0-1) and 1 for (MCS2-3)
                //  MCS   MCA  MCA    OCC   OCC
                // unit  unit relPos phyMC phyPort
                //   0     0    0      0     0
                //   0     1    1      0     1
                //   1     2    0      0     2
                //   1     3    1      0     3
                //   2     4    0      1     0
                //   2     5    1      1     1
                //   3     6    0      1     2
                //   3     7    1      1     3
                // TODO: RTC 247144
                o_data[index] = mcs_unit >> 1; // Mem Buf
                o_data[index+1] = 0x00; // reserved
                // Minimum
                UINT16_PUT(&o_data[index+ 2], npm_min[mca_rel_pos]);
                UINT16_PUT(&o_data[index+ 4], power_min[mca_rel_pos]);
                // WOF base
                UINT16_PUT(&o_data[index+ 6], npm_redun[mca_rel_pos]);
                UINT16_PUT(&o_data[index+ 8], npc_redun[mca_rel_pos]);
                UINT16_PUT(&o_data[index+10], power_redun[mca_rel_pos]);
                // Power Capping
                UINT16_PUT(&o_data[index+12], npm_pcap[mca_rel_pos]);
                UINT16_PUT(&o_data[index+14], npc_pcap[mca_rel_pos]);
                UINT16_PUT(&o_data[index+16], power_pcap[mca_rel_pos]);
                // Fmax
                UINT16_PUT(&o_data[index+18], npm_redun[mca_rel_pos]);
                UINT16_PUT(&o_data[index+20], npc_redun[mca_rel_pos]);
                UINT16_PUT(&o_data[index+22], power_redun[mca_rel_pos]);
                // reserved
                memset(&o_data[index], 0, 6); // reserved
                index += 30;
                ++numSets ;
            }
        }
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


uint16_t getMaxPowerCap(Target *i_sys, bool & o_is_redundant)
{
    uint16_t o_maxPcap = 0;
    o_is_redundant = true;

    // Check if HPC limit was found
    ATTR_OPEN_POWER_N_PLUS_ONE_HPC_BULK_POWER_LIMIT_WATTS_type hpc_pcap;
    if (i_sys->tryGetAttr
        <ATTR_OPEN_POWER_N_PLUS_ONE_HPC_BULK_POWER_LIMIT_WATTS>(hpc_pcap))
    {
        if (0 != hpc_pcap)
        {

// TODO: RTC 209572 Update with IPMI alternative
#if 0
#ifdef CONFIG_BMC_IPMI
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
                    o_is_redundant = false;
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
#endif
#endif
        }
        // else no valid HPC limit, use default
    }
    // else HPC limit not found, use default

    if (o_is_redundant)
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
    o_data[index++] = 0x20; // version

    // Minimum HARD Power Cap
    ATTR_OPEN_POWER_MIN_POWER_CAP_WATTS_type min_pcap =
        sys->getAttr<ATTR_OPEN_POWER_MIN_POWER_CAP_WATTS>();

    // Minimum SOFT Power Cap
    ATTR_OPEN_POWER_SOFT_MIN_PCAP_WATTS_type soft_pcap;
    if ( ! sys->tryGetAttr
            <ATTR_OPEN_POWER_SOFT_MIN_PCAP_WATTS>(soft_pcap))
    {
        // attr does not exist (us min)
        soft_pcap = min_pcap;
    }
    UINT16_PUT(&o_data[index], soft_pcap);
    index += 2;

    // Minimum Hard Power Cap
    UINT16_PUT(&o_data[index], min_pcap);
    index += 2;

    // System Maximum Power Cap
    bool is_redundant;
    const uint16_t max_pcap = getMaxPowerCap(sys, is_redundant);
    UINT16_PUT(&o_data[index], max_pcap);
    index += 2;

    // Quick Power Drop Power Cap
    ATTR_OPEN_POWER_N_BULK_POWER_LIMIT_WATTS_type qpd_pcap;
    if ( ! sys->tryGetAttr
         <ATTR_OPEN_POWER_N_BULK_POWER_LIMIT_WATTS>(qpd_pcap))
    {
        // attr does not exist, so disable by sending 0
        qpd_pcap = 0;
    }
    UINT16_PUT(&o_data[index], qpd_pcap);
    index += 2;

    TMGT_INF("getPowerCapMessageData: pcaps - soft min: %d, min: %d, max: %d,"
             " qpd: %d (in Watts)",
             soft_pcap, min_pcap, max_pcap, qpd_pcap);
    o_size = index;
}



void getSystemConfigMessageData(const TargetHandle_t i_occ, uint8_t* o_data,
                                uint64_t & o_size)
{
    uint64_t index = 0;
    uint32_t SensorID1 = 0;
    assert(o_data != nullptr);

    TargetHandle_t sys = nullptr;
    TargetHandleList nodes;
    targetService().getTopLevelTarget(sys);
    assert(sys != nullptr);
    getChildAffinityTargets(nodes, sys, CLASS_ENC, TYPE_NODE);
    assert(!nodes.empty());
    TargetHandle_t node = nodes[0];

    o_data[index++] = OCC_CFGDATA_SYS_CONFIG;
    o_data[index++] = 0x30; // version

    //System Type
    uint8_t l_throttle_below_nominal = 0;
    if(!sys->tryGetAttr
        <ATTR_REPORT_THROTTLE_BELOW_NOMINAL>(l_throttle_below_nominal))
    {
        l_throttle_below_nominal = 0;  // attr does not exist, disable
    }
    if (l_throttle_below_nominal == 1)
    {
        //1=OCC report throttling only when max frequency lowered below nominal
        G_system_type |= OCC_REPORT_THROTTLE_BELOW_NOMINAL;
    }
    else
    {
        //0=OCC report throttling when max frequency lowered below turbo
        G_system_type &= ~OCC_REPORT_THROTTLE_BELOW_NOMINAL;
    }
    bool is_redundant;
    getMaxPowerCap(sys, is_redundant);
    if (is_redundant == false)
    {
        // Power supply policy is non-redundant
        G_system_type |= OCC_CFGDATA_NON_REDUNDANT_PS;
    }
    else
    {
        // Power supply policy is redundant
        G_system_type &= ~OCC_CFGDATA_NON_REDUNDANT_PS;
    }
    o_data[index++] = G_system_type;

    //processor Callout Sensor ID
    ConstTargetHandle_t proc = getParentChip(i_occ);
    SensorID1 = UTIL::getSensorNumber(proc, SENSOR_NAME_PROC_STATE);
    memcpy(&o_data[index], &SensorID1, 4);
    index += 4;

    // processor frequency sensor id
    ++SensorID1; // TODO - get correct sensor
    memcpy(&o_data[index], &SensorID1, 4);
    index += 4;

    //Next 12*4 bytes are for core sensors.
    //If a new processor with more cores comes along,
    //this command will have to change.
    TargetHandleList cores;
    getChildChiplets(cores, proc, TYPE_CORE, false);

    TMGT_INF("getSystemConfigMessageData: systemType: 0x%02X, "
             "procSensor: 0x%04X, %d cores, %d nodes",
             G_system_type, SensorID1, cores.size(), nodes.size());

    for (uint64_t core=0; core<CFGDATA_CORES; core++)
    {
        SensorID1 = 0;

        if ( core < cores.size() )
        {
            SensorID1 = UTIL::getSensorNumber(cores[core],     //Temp Sensor
                                               SENSOR_NAME_CORE_TEMP);
        }

        //Core Temp Sensor ID
        memcpy(&o_data[index], &SensorID1, 4);
        index += 4;
    }

    //Backplane Callout Sensor ID
    SensorID1 = UTIL::getSensorNumber(node, SENSOR_NAME_BACKPLANE_FAULT);
    memcpy(&o_data[index], &SensorID1, 4);
    index += 4;

    //APSS Callout Sensor ID
    SensorID1 = UTIL::getSensorNumber(node, SENSOR_NAME_APSS_FAULT);
    memcpy(&o_data[index], &SensorID1, 4);
    index += 4;

    //Format 21 - VRM VDD Callout Sensor ID
    SensorID1 = UTIL::getSensorNumber(node, SENSOR_NAME_VRM_VDD_FAULT);
    memcpy(&o_data[index], &SensorID1, 4);
    index += 4;

    //Format 21 - VRM VDD Temperature Sensor ID
    SensorID1 = UTIL::getSensorNumber(node, SENSOR_NAME_VRM_VDD_TEMP);
    memcpy(&o_data[index], &SensorID1, 4);
    index += 4;

    memset(&o_data[index], 0, 8); // reserved
    index += 8;

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
    o_data[index++] = 0x30; // version


    // Processor Core Weight
    ATTR_OPEN_POWER_PROC_WEIGHT_type l_proc_weight;
    if ( ! l_sys->tryGetAttr          //if attr does not exists.
           <ATTR_OPEN_POWER_PROC_WEIGHT>(l_proc_weight))
    {
        l_proc_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    if(l_proc_weight == 0x0)
    {
        l_proc_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    o_data[index++] = l_proc_weight;


    // Processor Quad Weight
    ATTR_OPEN_POWER_QUAD_WEIGHT_type l_quad_weight;
    if ( ! l_sys->tryGetAttr          //if attr does not exists.
           <ATTR_OPEN_POWER_QUAD_WEIGHT>(l_quad_weight))
    {
        l_quad_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    if(l_quad_weight == 0x0)
    {
        l_quad_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    o_data[index++] = l_quad_weight;


    // Processor L3 Weight
    ATTR_OPEN_POWER_L3_WEIGHT_type l_l3_weight;
    if ( ! l_sys->tryGetAttr          //if attr does not exists.
           <ATTR_OPEN_POWER_L3_WEIGHT>(l_l3_weight))
    {
        l_l3_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    if(l_l3_weight == 0x0)
    {
        l_l3_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    o_data[index++] = l_l3_weight;

    // data sets following (proc, membuf, DIMM), and
    // each will get a FRU type, DVS temp, error temp,
    // and max read timeout
    size_t l_numSetsOffset = index++;

    // Processor
    o_data[index++] = CFGDATA_FRU_TYPE_PROC;
    uint8_t l_DVFS_temp =
        l_sys->getAttr<ATTR_OPEN_POWER_PROC_DVFS_TEMP_DEG_C>();
    uint8_t l_ERR_temp =
        l_sys->getAttr<ATTR_OPEN_POWER_PROC_ERROR_TEMP_DEG_C>();
    uint8_t l_timeout = l_sys->getAttr<ATTR_OPEN_POWER_PROC_READ_TIMEOUT_SEC>();
    if(l_DVFS_temp == 0x0)
    {
        l_DVFS_temp = OCC_PROC_DEFAULT_DVFS_TEMP;
        l_ERR_temp  = OCC_PROC_DEFAULT_ERR_TEMP;
        l_timeout   = OCC_PROC_DEFAULT_TIMEOUT;
    }
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // Memory Buffers
    o_data[index++] = CFGDATA_FRU_TYPE_MEMBUF;
    o_data[index++] =
        l_sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_THROTTLE_TEMP_DEG_C>();
    o_data[index++] =
        l_sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_ERROR_TEMP_DEG_C>();
    o_data[index++] =
        l_sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_READ_TIMEOUT_SEC>();
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // DIMM
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
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // GPU Cores
    if (!l_sys->tryGetAttr<ATTR_OPEN_POWER_GPU_READ_TIMEOUT_SEC>(l_timeout))
        l_timeout = 0xFF;
    if (l_timeout == 0)
    {
        l_timeout = 0xFF;
    }
    if (!l_sys->
        tryGetAttr<ATTR_OPEN_POWER_GPU_ERROR_TEMP_DEG_C>(l_ERR_temp))
        l_ERR_temp = OCC_NOT_DEFINED;
    if (l_ERR_temp == 0)
    {
        l_ERR_temp = OCC_NOT_DEFINED;
    }
    o_data[index++] = CFGDATA_FRU_TYPE_GPU_CORE;
    o_data[index++] = OCC_NOT_DEFINED;      //DVFS
    o_data[index++] = l_ERR_temp;           //ERROR
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // GPU Memory
    if (!l_sys->
        tryGetAttr<ATTR_OPEN_POWER_GPU_MEM_READ_TIMEOUT_SEC>(l_timeout))
        l_timeout = 0xFF;
    if (l_timeout == 0)
    {
        l_timeout = 0xFF;
    }
    if (!l_sys->
        tryGetAttr<ATTR_OPEN_POWER_GPU_MEM_ERROR_TEMP_DEG_C>(l_ERR_temp))
        l_ERR_temp = OCC_NOT_DEFINED;
    if (l_ERR_temp == 0)
    {
        l_ERR_temp = OCC_NOT_DEFINED;
    }
    o_data[index++] = CFGDATA_FRU_TYPE_GPU_MEMORY;
    o_data[index++] = OCC_NOT_DEFINED;      //DVFS
    o_data[index++] = l_ERR_temp;           //ERROR
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // VRM Vdd
    if(!l_sys->tryGetAttr<ATTR_OPEN_POWER_VRM_VDD_DVFS_TEMP_DEG_C>(l_DVFS_temp))
        l_DVFS_temp = OCC_NOT_DEFINED;
    if (l_DVFS_temp == 0)
    {
        l_DVFS_temp = OCC_NOT_DEFINED;
    }
    if(!l_sys->tryGetAttr<ATTR_OPEN_POWER_VRM_VDD_ERROR_TEMP_DEG_C>(l_ERR_temp))
        l_ERR_temp = OCC_NOT_DEFINED;
    if (l_ERR_temp == 0)
    {
        l_ERR_temp = OCC_NOT_DEFINED;
    }
    if(!l_sys->tryGetAttr<ATTR_OPEN_POWER_VRM_VDD_READ_TIMEOUT_SEC>(l_timeout))
        l_timeout = OCC_NOT_DEFINED;
    if(l_timeout == 0)
    {
        l_timeout = OCC_NOT_DEFINED;
    }
    o_data[index++] = CFGDATA_FRU_TYPE_VRM_VDD;
    o_data[index++] = l_DVFS_temp;          //DVFS
    o_data[index++] = l_ERR_temp;           //ERROR
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;


    o_data[l_numSetsOffset] = l_numSets;
    o_size = index;

} // end getThermalControlMessageData()


void getAVSBusConfigMessageData( const TargetHandle_t i_occ,
                                 uint8_t * o_data,
                                 uint64_t & o_size )
{
    uint64_t index = 0;
    o_size = 0;
    assert( o_data != nullptr );

    Target* l_sys = nullptr;
    targetService().getTopLevelTarget(l_sys);
    assert(l_sys != nullptr);

    // Get the parent processor
    ConstTargetHandle_t l_proc = getParentChip( i_occ );
    assert( l_proc != nullptr );
    // bus/rail [index] ->0: VDD; 1: VCS; 2: VDN; 3: VIO
    const unsigned int index_vdd = 0;
    ATTR_AVSBUS_BUSNUM_type l_bus;
    if (!l_proc->tryGetAttr<ATTR_AVSBUS_BUSNUM>(l_bus))
    {
        TMGT_ERR("getAVSBusConfigMessageData: unable to read "
                 "ATTR_AVSBUS_BUSNUM");
        memset(l_bus, 0xFF, sizeof(l_bus));
    }
    ATTR_AVSBUS_RAIL_type l_rail;
    if (!l_proc->tryGetAttr<ATTR_AVSBUS_RAIL>(l_rail))
    {
        TMGT_ERR("getAVSBusConfigMessageData: unable to read ATTR_AVSBUS_RAIL");
        memset(l_rail, 0, sizeof(l_rail));
    }

    // Populate the data
    o_data[index++] = OCC_CFGDATA_AVSBUS_CONFIG;
    o_data[index++] = 0x30; // version
    o_data[index++] = l_bus[index_vdd];  // Vdd Bus
    o_data[index++] = l_rail[index_vdd]; // Vdd Rail Selector
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    o_data[index++] = 0x00;
    o_data[index++] = 0x00;
    o_size = index;

}


// Send config data required by OCC for GPU handling.
// The OCC will determine which GPUs are present from the APSS GPIOs.
void getGPUConfigMessageData(const TargetHandle_t i_occ,
                             uint8_t * o_data,
                             uint64_t & o_size)
{
    unsigned int index = 0;
    assert(o_data != nullptr);

    // Populate the data
    o_data[index++] = OCC_CFGDATA_GPU_CONFIG;

    // Currently no supported GPUs, so hardcode data
    o_data[index++] = 0x02;             // GPU Config Version
    o_data[index++] = 0;                // total non-GPU max power
    o_data[index++] = 0;
    o_data[index++] = 0;                // total proc/mem power drop
    o_data[index++] = 0;
    o_data[index++] = 0;                // num GPUs
    o_data[index++] = 1;                // I2C engine "C"
    o_data[index++] = 0;                // I2C bus voltage
    o_data[index++] = 0;                // num data sets

    o_size = index;

} // end getGPUConfigMessageData()

// Determine if the BMC will allow turbo to be used.
// Returns true if BMC suppoted and turbo is allowed.
//         true if BMC Unsupported
//         false if supported and not allowed.
//         else false
bool bmcAllowsTurbo(Target* i_sys)
{
    bool turboAllowed = true;

// TODO: RTC 209572 Update with IPMI alternative
#if 0
#ifdef CONFIG_BMC_IPMI
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
#endif
#endif

    return turboAllowed;
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

// TODO: RTC 209572 Update with IPMI alternative
#if 0
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
#endif

    o_data[0] = OCC_CFGDATA_APSS_CONFIG;
    o_data[1] = 0x20; // version
    o_data[2] = 0;
    o_data[3] = 0;
    uint64_t idx = 4;

    for(uint64_t channel = 0; channel < sizeof(function); ++channel)
    {
        o_data[idx] = function[channel]; // ADC Channel assignement
        idx += sizeof(uint8_t);

        uint32_t sensorId = 0;
        if (sensors != nullptr)
        {
            sensorId = (*sensors)[channel];
        }
        memcpy(o_data+idx,&sensorId,sizeof(uint32_t)); // Sensor ID
        idx += sizeof(uint32_t);

        o_data[idx] = ground[channel];   // Ground Select
        idx += sizeof(uint8_t);

        INT32_PUT(o_data+idx, gain[channel]);
        idx += sizeof(int32_t);

        INT32_PUT(o_data+idx, offset[channel]);
        idx += sizeof(int32_t);

        TMGT_INF("APSS channel[%2d]: 0x%02X 0x%08X 0x%02X 0x%08X 0x%08X",
                 channel, function[channel], sensorId, ground[channel],
                 gain[channel], offset[channel]);
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
        TMGT_INF("APSS GPIO port[%2d]: 0x%02X 0x%08X 0x%08X",
                 port, gpioMode[port], UINT32_GET(o_data+idx),
                 UINT32_GET(o_data+idx+4));
        idx += pinsPerPort;
        pinIdx += pinsPerPort;
    }

    o_size = idx;
}


// Debug function to return config format data
void readConfigData(Occ * i_occ,
                    const uint8_t i_format,
                    uint16_t & o_cfgDataLength,
                    uint8_t *o_cfgDataPtr)
{
    uint64_t cfgDataLength = 0;
    switch(i_format)
    {
        case OCC_CFGDATA_OCC_ROLE:
            getOCCRoleMessageData(OCC_ROLE_MASTER ==
                                  i_occ->getRole(),
                                  OCC_ROLE_FIR_MASTER ==
                                  i_occ->getRole(),
                                  o_cfgDataPtr, cfgDataLength);
            break;

        case OCC_CFGDATA_APSS_CONFIG:
            getApssMessageData(o_cfgDataPtr, cfgDataLength);
            break;

        case OCC_CFGDATA_MEM_CONFIG:
            getMemConfigMessageData(i_occ->getTarget(),
                                    o_cfgDataPtr, cfgDataLength);
            break;

        case OCC_CFGDATA_PCAP_CONFIG:
            getPowerCapMessageData(o_cfgDataPtr, cfgDataLength);
            break;

        case OCC_CFGDATA_SYS_CONFIG:
            getSystemConfigMessageData(i_occ->getTarget(),
                                       o_cfgDataPtr, cfgDataLength);
            break;

        case OCC_CFGDATA_MEM_THROTTLE:
            {
                const uint8_t occInstance = i_occ->getInstance();
                getMemThrottleMessageData(i_occ->getTarget(),
                                          occInstance, o_cfgDataPtr,
                                          cfgDataLength);
            }
            break;

        case OCC_CFGDATA_TCT_CONFIG:
            getThermalControlMessageData(o_cfgDataPtr,
                                         cfgDataLength);
            break;

        case OCC_CFGDATA_AVSBUS_CONFIG:
            getAVSBusConfigMessageData(i_occ->getTarget(),
                                       o_cfgDataPtr,
                                       cfgDataLength );
            break;

        case OCC_CFGDATA_GPU_CONFIG:
            getGPUConfigMessageData(i_occ->getTarget(),
                                    o_cfgDataPtr,
                                    cfgDataLength);
            break;

        default:
            TMGT_ERR("readConfigData: Unsupported i_format type 0x%02X",
                     i_format);
    }
    o_cfgDataLength = cfgDataLength;

} // end readConfigData()


}
