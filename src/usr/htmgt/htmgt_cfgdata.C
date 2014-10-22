/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_cfgdata.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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


using namespace TARGETING;


//for unit testing
//#define TRACUCOMP(args...)  TMGT_INF(args)
#define TRACUCOMP(args...)

namespace HTMGT
{

/** OCC configuration data message versions */
enum occCfgDataVersion
{
    OCC_CFGDATA_PSTATE_VERSION       = 0x10,
    OCC_CFGDATA_FREQ_POINT_VERSION   = 0x10,
    OCC_CFGDATA_APSS_VERSION         = 0x10,
    OCC_CFGDATA_MEM_CONFIG_VERSION   = 0x10,
    OCC_CFGDATA_PCAP_CONFIG_VERSION  = 0x10,
    OCC_CFGDATA_SYS_CONFIG_VERSION   = 0x10,
    OCC_CFGDATA_MEM_THROTTLE_VERSION = 0x10,
    OCC_CFGDATA_TCT_CONFIG_VERSION   = 0x10
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

            centPos = (*centaur)->getAttr<ATTR_POSITION>();

            //Do the entry for the Centaur itself

            //Reserved
            memset(&o_data[index], 0, 4);
            index += 4;

            //Hardware Sensor ID
            sensor = 0; //TODO RTC 115294
            memcpy(&o_data[index], &sensor, 2);
            index += 2;

            //Temperature Sensor ID
            sensor = 0; //TODO RTC 115294
            memcpy(&o_data[index], &sensor, 2);
            index += 2;

            //Centaur #
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

                    dimmPos = getOCCDIMMPos(*mba, *dimm);

                    //Reserved
                    memset(&o_data[index], 0, 4);
                    index += 4;

                    //Hardware Sensor ID
                    sensor = 0; //TODO RTC 115294
                    memcpy(&o_data[index], &sensor, 2);
                    index += 2;

                    //Temperature Sensor ID
                    sensor = 0; //TODO RTC 115294
                    memcpy(&o_data[index], &sensor, 2);
                    index += 2;

                    //Centaur #
                    o_data[index++] = centPos;

                    //DIMM #
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
    memcpy(&o_data[index], &pcap, 2);
    index += 2;

    //System Maximum Power Cap
    pcap = sys->getAttr<ATTR_OPEN_POWER_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS>();
    memcpy(&o_data[index], &pcap, 2);
    index += 2;

    //Oversubscription Power Cap
    pcap = sys->getAttr<ATTR_OPEN_POWER_N_BULK_POWER_LIMIT_WATTS>();
    memcpy(&o_data[index], &pcap, 2);
    index += 2;

    o_size = index;
}


void getSystemConfigMessageData(uint8_t* o_data, uint64_t & o_size)
{
    uint64_t index = 0;
    uint16_t sensor = 0;
    assert(o_data != NULL);

    o_data[index++] = OCC_CFGDATA_SYS_CONFIG;
    o_data[index++] = OCC_CFGDATA_SYS_CONFIG_VERSION;

    //System Type
    o_data[index++] = OCC_CFGDATA_OPENPOWER_SYSTEMTYPE;

    //processor sensor ID
    sensor = 0; //TODO all sensors - RTC 115294
    memcpy(&o_data[index], &sensor, 2);
    index += 2;

    //Next 12*4 bytes are for core sensors
    for (uint64_t core=0; core<CFGDATA_CORES; core++)
    {
        //Core Temp Sensor ID
        sensor = 0;
        memcpy(&o_data[index], &sensor, 2);
        index += 2;

        //Core Frequency Sensor ID
        sensor = 0;
        memcpy(&o_data[index], &sensor, 2);
        index += 2;
    }

    //Backplane sensor ID
    sensor = 0;
    memcpy(&o_data[index], &sensor, 2);
    index += 2;

    //APSS sensor ID
    sensor = 0;
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
    o_data[index++] = CFDATA_DVFS_NOT_DEFINED;
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_ERROR_TEMP_DEG_C>();
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_MEMCTRL_READ_TIMEOUT_SEC>();

    o_data[index++] = CFGDATA_FRU_TYPE_DIMM;
    o_data[index++] = CFDATA_DVFS_NOT_DEFINED;
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_DIMM_ERROR_TEMP_DEG_C>();
    o_data[index++] = sys->getAttr<ATTR_OPEN_POWER_DIMM_READ_TIMEOUT_SEC>();

    o_size = index;

}


void getFrequencyPointMessageData(uint8_t* o_data,
                                  uint64_t & o_size)
{
    uint64_t index   = 0;
    uint16_t min     = 0;
    uint16_t max     = 0;
    uint16_t nominal = 0;
    Target* sys = NULL;

    targetService().getTopLevelTarget(sys);
    assert(sys != NULL);
    assert(o_data != NULL);

    o_data[index++] = OCC_CFGDATA_FREQ_POINT;
    o_data[index++] = OCC_CFGDATA_FREQ_POINT_VERSION;


    //Nominal Frequency in MHz
    nominal = sys->getAttr<ATTR_NOMINAL_FREQ_MHZ>();
    memcpy(&o_data[index], &nominal, 2);
    index += 2;


    //Maximum Frequency in MHz
    uint8_t turboAllowed =
        sys->getAttr<ATTR_OPEN_POWER_TURBO_MODE_SUPPORTED>();

    //If Turbo isn't allowed, then we send up the
    //nominal frequency for this value.
    if (turboAllowed)
    {
        max = sys->getAttr<ATTR_FREQ_CORE_MAX>();
    }
    else
    {
        max = nominal;
    }

    memcpy(&o_data[index], &max, 2);
    index += 2;


    //Minimum Frequency in MHz
    min = sys->getAttr<ATTR_MIN_FREQ_MHZ>();
    memcpy(&o_data[index], &min, 2);
    index += 2;

    TMGT_INF("Frequency Points: Nominal %d, Max %d, Min %d",
             (uint32_t)nominal, (uint32_t)max, (uint32_t)min);

    o_size = index;
}


void getPstateTableMessageData(const TargetHandle_t i_occTarget,
                               uint8_t* o_data,
                               uint64_t & io_size)
{
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

    // Read data from attribute for specified occ
    ATTR_PSTATE_TABLE_type * pstateDataPtr =
        reinterpret_cast<ATTR_PSTATE_TABLE_type*>(o_data + 4);

    i_occTarget->tryGetAttr<ATTR_PSTATE_TABLE>(*pstateDataPtr);
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

    o_data[0] = OCC_CFGDATA_APSS_CONFIG;
    o_data[1] = OCC_CFGDATA_APSS_VERSION;
    o_data[2] = 0;
    o_data[3] = 0;
    uint64_t idx = 4;

    for(uint64_t channel = 0; channel < sizeof(function); ++channel)
    {
        o_data[idx] = function[channel]; // ADC Channel assignement
        idx += sizeof(uint8_t);

        uint16_t sensorId = 0;
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
}
