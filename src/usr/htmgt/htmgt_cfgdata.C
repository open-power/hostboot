/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_cfgdata.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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

#include <initservice/initsvcstructs.H>
#include <attributeenums.H>
#include <targeting/common/target.H>
#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <targeting/targplatutil.H>

#include <htmgt/htmgt_reasoncodes.H>
#include <fapi2_attribute_service.H>
#include <isteps/pm/scopedHomerMapper.H>

using namespace TARGETING;

//for unit testing
//#define TRACUCOMP(args...)  TMGT_INF(args)
#define TRACUCOMP(args...)

namespace HTMGT
{

    bool G_wofSupported = true;
    uint8_t G_system_type = 0;

    struct occ_memory_table_t
    {
        TARGETING::Target* targetPtr;
        uint8_t  occInstance;
        uint8_t  ocmbNum;
        uint8_t  dts;
        uint8_t  ocmbTempType;
        uint8_t  reserved;
    } __attribute__((packed));
    std::vector<occ_memory_table_t> G_memTable;


    // Send config format data to all OCCs
    errlHndl_t sendOccConfigData(const occCfgDataFormat i_requestedFormat)
    {
        errlHndl_t l_err = nullptr;
        uint8_t cmdData[OCC_MAX_DATA_LENGTH] = {0};

        if (G_debug_trace & DEBUG_TRACE_VERBOSE)
        {
            TMGT_INF("sendOccConfigData called");
        }

        G_memTable.clear();

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
                procTarget = TARGETING::
                    getImmediateParentByAffinity(occ->getTarget());
                HBPM::ScopedHomerMapper l_mapper(procTarget);
                l_err = l_mapper.map();
                if (l_err)
                {
                    TMGT_ERR("sendOccConfigData: Unable to get HOMER virtual "
                             "address for OCC%d (rc=0x%04X)",
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
                                getMemConfigMessageData(occ,
                                                        cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_PCAP_CONFIG:
                                getPowerCapMessageData(cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_SYS_CONFIG:
                                getSystemConfigMessageData(*occ,
                                                           cmdData, cmdDataLen);
                                break;

                            case OCC_CFGDATA_MEM_THROTTLE:
                                if (!int_flags_set(FLAG_DISABLE_MEM_CONFIG))
                                {
                                    getMemThrottleMessageData(occ->getTarget(),
                                                              occInstance,
                                                              cmdData,
                                                              cmdDataLen);
                                }
                                break;

                            case OCC_CFGDATA_TCT_CONFIG:
                                getThermalControlMessageData(procTarget,
                                                             cmdData,
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
                        // No reason to keep sending config data for this OCC
                        break;
                    }

                } // for each config format
                occ->invalidateHomer();

                if (OccManager::occNeedsReset())
                {
                    // All OCCs are going to be reset so no need to continue
                    break;
                }

            } // for each OCC
        }

        if ((nullptr == l_err) && (OccManager::occNeedsReset()))
        {
            /*@
             * @errortype
             * @reasoncode HTMGT_RC_OCC_UNEXPECTED_STATE
             * @moduleid  HTMGT_MOD_SEND_OCC_CONFIG
             * @userdata1 requested config format
             * @devdesc Failed to send all required config data
             */
            bldErrLog(l_err,
                      HTMGT_MOD_SEND_OCC_CONFIG,
                      HTMGT_RC_OCC_UNEXPECTED_STATE,
                      i_requestedFormat, 0, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end sendOccConfigData()


// Utility function for writing Memory Config data
void writeMemConfigData( uint8_t *& o_data,
                         TARGETING::Target * i_target,
                         TARGETING::SENSOR_NAME i_sensorState,
                         TARGETING::SENSOR_NAME i_sensorTemp,
                         uint8_t i_memType,
                         uint8_t i_dimmInfo1,
                         uint8_t i_dimmInfo2,
                         uint8_t i_dimmInfo3,
                         uint32_t & io_index )
{

    //Byte 0-3 Hardware Sensor ID
    uint32_t l_sensor = UTIL::getSensorNumber(i_target, i_sensorState);
    size_t l_dataSize = sizeof(l_sensor);
    memcpy(&o_data[io_index],
           reinterpret_cast<uint8_t*>(&l_sensor),
           l_dataSize);
    io_index += l_dataSize;

    //Byte 4-7 Temperature Sensor ID
    l_sensor = UTIL::getSensorNumber(i_target, i_sensorTemp);
    memcpy(&o_data[io_index],
           reinterpret_cast<uint8_t*>(&l_sensor),
           l_dataSize);
    io_index += l_dataSize;

    //Byte 8 Memory type (0xAn, where n is Memory Buffer 0-F)
    o_data[io_index++] = 0xA0 | i_memType;

    //Byte 9 DIMM Info Byte 1 (Memory DTS 0/1)
    o_data[io_index++] = i_dimmInfo1;

    //Byte 10 DIMM Info Byte 2 (Temperature Type)
    o_data[io_index++] = i_dimmInfo2;

    //Byte 11 DIMM Info Byte 3 (Reserved)
    o_data[io_index++] = i_dimmInfo3;
}


uint8_t convert_temp_type(const uint8_t i_sensor_type)
{
    uint8_t occ_type = 0xFF; // Disabled
    static bool L_logged_invalid = false;

    switch(i_sensor_type)
    {
        case MEM_EFF_THERM_SENSOR_0_USAGE_DISABLED: // 0
            break;

        case MEM_EFF_THERM_SENSOR_0_USAGE_DRAM: // 1
            occ_type = 0x02; // DIMM
            break;

        case MEM_EFF_THERM_SENSOR_0_USAGE_PMIC: // 2
            occ_type = 0x07; // DIMM-PMIC
            break;

        case MEM_EFF_THERM_SENSOR_0_USAGE_DRAM_AND_MEM_BUF_EXT: // 5
            occ_type = 0x03; // DIMM+MB
            break;

        case MEM_EFF_THERM_SENSOR_0_USAGE_MEM_BUF_EXT: // 4
            occ_type = 0x08; // MB-EXT
            break;

        default:
            TMGT_ERR("convert_temp_type: Unsupported MEM_EFF_"
                     "THERM_SENSOR_USAGE 0x%02X", i_sensor_type);
            if (!L_logged_invalid)
            {
                L_logged_invalid = true;
                /*@
                 * @errortype
                 * @subsys EPUB_FIRMWARE_SP
                 * @reasoncode HTMGT_RC_INVALID_MEM_SENSOR
                 * @moduleid HTMGT_MOD_CONVERT_TEMP_TYPE
                 * @userdata1 USAGE type
                 * @userdata2 0
                 * @devdesc Unsupported MEM_EFF_THERM_SENSOR type
                 */
                errlHndl_t l_err = NULL;
                bldErrLog(l_err, HTMGT_MOD_CONVERT_TEMP_TYPE,
                          HTMGT_RC_INVALID_MEM_SENSOR,
                          i_sensor_type, 0,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
            }
            break;
    }

    return occ_type;
}


/* Function Specification *******************************************************/
/*                                                                              */
/*  Name:      ocmbInit                                                         */
/*                                                                              */
/*  Function:  Build memory config data for specified processor                 */
/*               1. Query all functional OCMBs for each processor               */
/*               2. Query all functional MEM_PORTs for each OCMB                */
/*               3. Query all functional DIMMs for each PORT                    */
/*                                                                              */
/*  Returns:   Number of functional ports                                       */
/*                                                                              */
/*  P10 processors allow up to 16 DDIMMs attached via an OMI channel            */
/*             16 DDIMMs / P10 processor                                        */
/*             1 EXPLORER OCMB chip / DDIMM                                     */
/*             1 port / EXPLORER OCMB chip                                      */
/*             2 DDR4 DIMMs / port                                              */
/*                                                                              */
/*  Logical Layout per proc:                                                    */
/*                     OCMB0 -- DDIMM0 -- CHIP0 -- (port 0) -- DIMM0            */
/*                                                          -- DIMM1            */
/*                           -- DDIMM1 -- CHIP0 -- (port 0) -- DIMM0            */
/*                                                          -- DIMM1            */
/*                           -- DDIMM2 -- CHIP0 -- (port 0) -- DIMM0            */
/*                                                          -- DIMM1            */
/*                   ...                                                        */
/*                                                                              */
/* End Function Specification ***************************************************/
uint8_t ocmbInit(Occ *i_occ,
                 uint8_t* o_data,
                 uint32_t & io_index)
{
    TargetHandleList ocmb_list;
    uint8_t numSets = 0;

    const TargetHandle_t occ_target = i_occ->getTarget();
    ConstTargetHandle_t proc = getParentChip(occ_target);
    assert(proc != nullptr);

    // Save Processor Model for later
    ATTR_POSITION_type l_procPosition = proc->getAttr<ATTR_POSITION>();
    ATTR_MODEL_type l_procModel = proc->getAttr<ATTR_MODEL>();
    TMGT_INF("ocmbInit: POWER10 PROCESSOR[%d] HUID=0x%08lX",
             l_procPosition, get_huid(proc));

    if( l_procModel == TARGETING::MODEL_POWER10 )
    {
        // Get functional OCMBs associated with this processor
        getChildAffinityTargets(ocmb_list, proc, CLASS_CHIP, TYPE_OCMB_CHIP);

        TMGT_INF("ocmbInit: Proc%d has %d functional OCMB_CHIPs",
                 l_procPosition, ocmb_list.size());

        for (const auto & ocmb : ocmb_list)
        {
            uint8_t l_ocmb_num = 0;
            TargetHandleList port_list;
            TargetHandleList dimm_list;
            uint8_t l_type = 0xFF; // Disabled
            static bool L_logged_invalid = false;
            const ATTR_HUID_type l_ocmb_huid = get_huid(ocmb);

            // OCMB instance comes from the parent (OMI target)
            Target *omi_target = getImmediateParentByAffinity(ocmb);
            if (omi_target != NULL)
            {
                // get relative OCMB per processor
                l_ocmb_num = omi_target->getAttr<ATTR_CHIP_UNIT>();
            }
            else
            {
                TMGT_ERR("ocmbInit: Unable to determine OCMB parent"
                         " for HUID 0x%04X", l_ocmb_huid);
            }
            // Get list of functional memory ports associated with this OCMB_CHIP
            getChildAffinityTargets(port_list, ocmb,
                                    CLASS_UNIT, TYPE_MEM_PORT);
            // Currently only support a single port per OCMB (use first port)
            Target* port_target = port_list[0];

            // Determine DTS type for OCMB
            if(port_target->tryGetAttr
               <TARGETING::ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE >(l_type))
            {
                if ((l_type == MEM_EFF_THERM_SENSOR_DIFF_USAGE_MB_INT_DTM) ||
                    (l_type == MEM_EFF_THERM_SENSOR_DIFF_USAGE_MB_INT_DTM_REM))
                {
                    l_type = 0x01; // Internal Memory Controller
                }
                else if (l_type == MEM_EFF_THERM_SENSOR_DIFF_USAGE_DISABLED)
                {
                    l_type = 0xFF; // Disabled
                }
                else
                {
                    TMGT_ERR("ocmbInit: Unsupported ATTR_MEM_EFF_THERM_SENSOR"
                             "_DIFF_USAGE 0x%02X", l_type);
                    if (!L_logged_invalid)
                    {
                        L_logged_invalid = true;
                        /*@
                         * @errortype
                         * @subsys EPUB_FIRMWARE_SP
                         * @reasoncode HTMGT_RC_INVALID_MEM_SENSOR
                         * @moduleid HTMGT_MOD_OCMB_INIT
                         * @userdata1 USAGE type
                         * @userdata2 OCMB HUID
                         * @devdesc Unsupported
                         *             ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE type
                         */
                        errlHndl_t l_err = NULL;
                        bldErrLog(l_err, HTMGT_MOD_OCMB_INIT,
                                  HTMGT_RC_INVALID_MEM_SENSOR,
                                  l_type, l_ocmb_huid,
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                        ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    }
                    l_type = 0xFF; // Disabled
                }
            }
            else
            {
                TMGT_ERR("ocmbInit: Failed to read "
                         "ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE");
                l_type = 0xFF; // Disabled
            }

            TMGT_INF("ocmbInit: OCMB[%d] HUID=0x%08lX TYPE[%d] "
                     "(position=0x%02X, ordinal=0x%02X, %d functional PORTs)",
                     l_ocmb_num, l_ocmb_huid, l_type,
                     ocmb->getAttr<ATTR_POSITION>(),
                     ocmb->getAttr<ATTR_ORDINAL_ID>(),
                     port_list.size());

            // add entry for the OCMB itself
            writeMemConfigData(o_data,
                               ocmb,
                               SENSOR_NAME_MEMBUF_STATE,
                               SENSOR_NAME_MEMBUF_TEMP,
                               l_ocmb_num, // Memory Buffer #
                               0xFF,       // (memory buffer)
                               l_type,     // Temperature Type
                               0,          // reserved
                               io_index);
            numSets++;

            occ_memory_table_t entry =
            {
                ocmb,
                i_occ->getInstance(),
                l_ocmb_num, 0xFF,
                l_type, 0,
            };
            G_memTable.push_back(entry);

            // Currently only support a single port per OCMB (use first port)
            const uint8_t l_port_unit =
                port_target->getAttr<TARGETING::ATTR_CHIP_UNIT>();
            const unsigned long l_port_huid = get_huid(port_target);

            // Get list of functional DIMMs assocated for this port (single port)
            getChildAffinityTargets(dimm_list, port_target,
                                    CLASS_LOGICAL_CARD, TYPE_DIMM);
            TMGT_INF("ocmbInit:   PORT[%d] HUID=0x%08lX (%d functional DIMMs)",
                     l_port_unit, l_port_huid, dimm_list.size());

            if (dimm_list.size() > 0)
            {
                // Dump DIMM info for completeness
                for (uint8_t index=0; index < dimm_list.size(); index++)
                {
                    TMGT_INF("ocmbInit:     DIMM[%d] HUID=0x%08lX (position=0x%02X)",
                             index,
                             get_huid(dimm_list[index]),
                             dimm_list[index]->getAttr<TARGETING::ATTR_POSITION>());
                }
            }

            // Update entry with DTSs
            for (unsigned int l_dts = 0; l_dts < HTMGT_NUM_DTS_PER_OCMB; ++l_dts)
            {
                if (l_dts == 0)
                {
                    if (port_target->tryGetAttr
                        <TARGETING::ATTR_MEM_EFF_THERM_SENSOR_0_USAGE>(l_type))
                    {
                        l_type = convert_temp_type(l_type);
                    }
                    else
                    {
                        TMGT_ERR("ocmbInit: Failed to read ATTR_MEM_EFF_"
                                 "THERM_SENSOR_0_USAGE");
                        l_type = 0xFF; // disabled
                    }
                }
                else
                {
                    if (port_target->tryGetAttr
                        <TARGETING::ATTR_MEM_EFF_THERM_SENSOR_1_USAGE>(l_type))
                    {
                        l_type = convert_temp_type(l_type);
                    }
                    else
                    {
                        TMGT_ERR("ocmbInit: Failed to read ATTR_MEM_EFF_"
                                 "THERM_SENSOR_1_USAGE");
                        l_type = 0xFF; // disabled
                    }
                }
                TMGT_INF("ocmbInit:     PORT[%d] DTS[%d] TYPE[%d]",
                         l_port_unit, l_dts, l_type);
                writeMemConfigData(o_data,
                                   port_target,
                                   SENSOR_NAME_DIMM_STATE,
                                   SENSOR_NAME_DIMM_TEMP,
                                   l_ocmb_num, // Memory Buffer #
                                   l_dts,      // DTS #
                                   l_type,     // Temperature Type
                                   0,          // reserved
                                   io_index );
                numSets++;
            } // for each DTS
        }
    }
    else
    {
        TMGT_ERR("ocmbInit: SKIPPING UNKNOWN PROCESSOR[%d] "
                 "(model 0x%02X, HUID=0x%08lX)",
                 l_procPosition, l_procModel, get_huid(proc));
    }

    TMGT_INF("ocmbInit: returning %d memory sets OCC%d",
             numSets, i_occ->getInstance());

    return numSets;

} // end ocmbInit()



void getMemConfigMessageData(Occ *i_occ,
                             uint8_t* o_data, uint64_t & o_size)
{
    uint32_t index = 0;

    assert(o_data != nullptr);

    o_data[index++] = OCC_CFGDATA_MEM_CONFIG;
    o_data[index++] = 0x30; // version

    //System reference needed for these ATTR.
    Target* sys = UTIL::assertGetToplevelTarget();

    ATTR_MSS_MRW_THERMAL_SENSOR_POLLING_PERIOD_type l_update_time;
    if(!sys->tryGetAttr<ATTR_MSS_MRW_THERMAL_SENSOR_POLLING_PERIOD>(l_update_time))
    {
        l_update_time = 200; //ms
    }

    o_data[index++] = l_update_time >> 8;
    o_data[index++] = l_update_time & 0xFF;

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
    uint8_t numSets = 0;
    if (!int_flags_set(FLAG_DISABLE_MEM_CONFIG))
    {
        // fill in details of the memory config
        numSets = ocmbInit(i_occ, o_data, index);

        TMGT_INF("getMemConfigMessageData: returning %d"
                 " memory sets for OCC%d",
                 numSets, i_occ->getInstance());
    }
    else
    {
        TMGT_INF("getMemConfigMessageData: Mem monitoring is disabled");
    }
    o_data[numSetsOffset] = numSets;

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

    //Get all functional OCMBs
    TargetHandleList ocmb_list;
    getAllChips(ocmb_list, TYPE_OCMB_CHIP, true);
    TMGT_INF("getMemThrottleMessageData: Total of %d functional OCMBs",
             ocmb_list.size());

    o_data[index++] = OCC_CFGDATA_MEM_THROTTLE;
    o_data[index++] = 0x40; // version;

    //Byte 3:   Number of memory throttling data sets.
    size_t numSetsOffset = index++; //Will fill in numSets at the end

    //Next, the following format repeats per set/OCMB:
    //Byte 0:       Throttle Info Byte 1 (membuf# 0-15)
    //Byte 1:       Throttle Info Byte 2 (reserved)
    //Bytes 2-3:    min N_PER_SLOT
    //Bytes 4-5:    Disabled N_PER_SLOT
    //Bytes 6-7:    DisabledN_PER_PORT
    //Bytes 8-9:    Ultra Turbo N_PER_SLOT
    //Bytes 10-11:  Ultra Turbo N_PER_PORT
    //Bytes 12-13:  Fmax N_PER_SLOT
    //Bytes 14-15:  Fmax N_PER_PORT
    //Bytes 16-17:  Oversubscription N_PER_SLOT
    //Bytes 18-19:  Oversubscription N_PER_PORT
    //Bytes 20-21:  Reserved

    for(const auto & ocmb_target : ocmb_list)
    {
        // OCMB instance comes from the parent (OMI target)
        uint8_t l_ocmb_pos = 0xFF;
        TARGETING::Target * omi_target = getImmediateParentByAffinity(ocmb_target);
        if (omi_target != NULL)
        {
            // get relative OCMB per processor
            l_ocmb_pos = omi_target->getAttr<ATTR_CHIP_UNIT>();
        }
        else
        {
            uint32_t ocmb_huid = get_huid(ocmb_target);
            TMGT_ERR("getMemThrottleMessageData: Unable to determine OCMB parent"
                     " for HUID 0x%04X", ocmb_huid);
            continue;
        }
        // Get functional parent processor
        TARGETING::TargetHandleList proc_targets;
        getParentAffinityTargets (proc_targets, ocmb_target, CLASS_CHIP, TYPE_PROC);
        if (proc_targets.size() > 0)
        {
            ConstTargetHandle_t proc_target = proc_targets[0];
            assert(proc_target != nullptr);

            // Make sure this OCMB is for the current OCC/Proc
            if (i_occ_instance == proc_target->getAttr<TARGETING::ATTR_POSITION>())
            {
                bool attr_failure = false;
                // Read the throttle and power values for this OCMB
                ATTR_OT_MIN_N_PER_SLOT_type nps_min;
                if (!ocmb_target->tryGetAttr<ATTR_OT_MIN_N_PER_SLOT>(nps_min))
                {
                    TMGT_ERR("getMemThrottleMessageData: failed to read "
                             "OT_MIN_N_PER_SLOT");
                    attr_failure = true;
                }
                ATTR_N_PLUS_ONE_N_PER_SLOT_type nps_redun;
                ATTR_N_PLUS_ONE_N_PER_PORT_type npp_redun;
                if (!ocmb_target->tryGetAttr<ATTR_N_PLUS_ONE_N_PER_SLOT>(nps_redun))
                {
                    TMGT_ERR("getMemThrottleMessageData: failed to read "
                             "N_PLUS_ONE_N_PER_SLOT");
                    attr_failure = true;
                }
                if (!ocmb_target->tryGetAttr<ATTR_N_PLUS_ONE_N_PER_PORT>(npp_redun))
                {
                    TMGT_ERR("getMemThrottleMessageData: failed to read "
                             "N_PLUS_ONE_N_PER_PORT");
                    attr_failure = true;
                }

                if (attr_failure)
                {
                    /*@
                     * @errortype
                     * @subsys EPUB_FIRMWARE_SP
                     * @moduleid HTMGT_MOD_MEMTHROTTLE
                     * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
                     * @userdata1 ocmb instance
                     * @devdesc Failed to read throttle settings
                     */
                    errlHndl_t l_err = NULL;
                    bldErrLog(l_err, HTMGT_MOD_MEMTHROTTLE,
                              HTMGT_RC_ATTRIBUTE_ERROR,
                              l_ocmb_pos, 0,
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    // Skip to next ocmb
                    continue;
                }

                // Query the functional Ports for this OCMB
                TARGETING::TargetHandleList port_list;
                getChildAffinityTargetsByState(port_list, ocmb_target, CLASS_UNIT,
                                               TYPE_MEM_PORT, UTIL_FILTER_FUNCTIONAL);
                for(const auto & port_target : port_list)
                {
                    // unit identifies unique Port under a processor
                    uint8_t port_unit = port_target->getAttr
                        <TARGETING::ATTR_CHIP_UNIT>();
                    const uint8_t port_rel_pos = port_unit % 2;
                    if ((nps_min[port_rel_pos] == 0) ||
                        (nps_redun[port_rel_pos] == 0))
                    {
                        TMGT_ERR("getMemThrottleMessageData: OCMB%d/Port%d [%d]"
                                 " - Ignored due to null throttle",
                                 l_ocmb_pos, port_unit, port_rel_pos);
                        TMGT_ERR("N/slot: Min=%d, Redun=%d",
                                 nps_min[port_rel_pos], nps_redun[port_rel_pos]);
                        continue;
                    }
                    if (port_rel_pos >= HTMGT_MAX_PORT_PER_OCMB_CHIP)
                    {
                        TMGT_ERR("getMemThrottleMessageData: OCMB%d / Port%d"
                                 " - Ignored due invalid Port position: %d",
                                 l_ocmb_pos, port_unit, port_rel_pos);
                        continue;
                    }
                    TMGT_INF("getMemThrottleMessageData: OCC%d / OCMB%d / port%d",
                             i_occ_instance, l_ocmb_pos, port_unit);

                    o_data[index] = l_ocmb_pos; // Mem Buf
                    o_data[index+1] = 0x00; // reserved
                    // Minimum
                    UINT16_PUT(&o_data[index+ 2], nps_min[port_rel_pos]);
                    // Disabled
                    UINT16_PUT(&o_data[index+ 4], nps_redun[port_rel_pos]);
                    UINT16_PUT(&o_data[index+ 6], npp_redun[port_rel_pos]);
                    // Ultra Turbo
                    UINT16_PUT(&o_data[index+ 8], nps_redun[port_rel_pos]);
                    UINT16_PUT(&o_data[index+10], npp_redun[port_rel_pos]);
                    // Fmax
                    UINT16_PUT(&o_data[index+12], nps_redun[port_rel_pos]);
                    UINT16_PUT(&o_data[index+14], npp_redun[port_rel_pos]);
                    // Oversubscription
                    UINT16_PUT(&o_data[index+16], nps_redun[port_rel_pos]);
                    UINT16_PUT(&o_data[index+18], npp_redun[port_rel_pos]);
                    // reserved
                    memset(&o_data[index+20], 0, 2); // reserved
                    index += 22;
                    ++numSets ;
                }
            }
        }
    }

    TMGT_INF("getMemThrottleMessageData: returning %d throttle sets for OCC%d",
             numSets, i_occ_instance);

    o_data[numSetsOffset] = numSets;

    o_size = index;

} // end getMemThrottleMessageData()



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

    // Read the default N+1 bulk power limit (redundant PS policy)
    o_maxPcap = i_sys->
        getAttr<ATTR_N_PLUS_ONE_BULK_POWER_LIMIT_WATTS>();
    TMGT_INF("getMaxPowerCap: maximum power cap = %dW "
             "(redundant PS bulk power limit)", o_maxPcap);
    return o_maxPcap;

} // end getMaxPowerCap()


void getPowerCapMessageData(uint8_t* o_data, uint64_t & o_size)
{
    uint64_t index = 0;

    Target* sys = UTIL::assertGetToplevelTarget();
    assert(o_data != nullptr);

    o_data[index++] = OCC_CFGDATA_PCAP_CONFIG;
    o_data[index++] = 0x20; // version

    // Minimum HARD Power Cap
    ATTR_MIN_POWER_CAP_WATTS_type min_pcap =
        sys->getAttr<ATTR_MIN_POWER_CAP_WATTS>();

    // Minimum SOFT Power Cap
    ATTR_SOFT_MIN_POWER_CAP_WATTS_type soft_pcap;
    if ( ! sys->tryGetAttr
            <ATTR_SOFT_MIN_POWER_CAP_WATTS>(soft_pcap))
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
    ATTR_N_BULK_POWER_LIMIT_WATTS_type qpd_pcap;
    if ( ! sys->tryGetAttr
         <ATTR_N_BULK_POWER_LIMIT_WATTS>(qpd_pcap))
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



void getSystemConfigMessageData(const Occ &i_occ,
                                uint8_t* o_data,
                                uint64_t & o_size)
{
    uint64_t index = 0;
    uint32_t SensorID1 = 0;
    assert(o_data != nullptr);

    TargetHandle_t sys = UTIL::assertGetToplevelTarget();
    TargetHandleList nodes;
    getChildAffinityTargets(nodes, sys, CLASS_ENC, TYPE_NODE);
    assert(!nodes.empty());
    TargetHandle_t node = nodes[0];

    o_data[index++] = OCC_CFGDATA_SYS_CONFIG;
    o_data[index++] = 0x30; // version

    //System Type
    uint8_t l_system_type = G_system_type;
    if (i_occ.wofResetCount() >= WOF_RESET_COUNT_THRESHOLD)
    {
        l_system_type |= OCC_CFGDATA_WOF_RESET_LIMIT;
        TMGT_INF("getSystemConfigMessageData: Reached WOF reset limit(%d)",
                 i_occ.wofResetCount());
    }
    o_data[index++] = l_system_type;

    //processor Callout Sensor ID
    ConstTargetHandle_t proc = getParentChip(i_occ.getTarget());
    SensorID1 = UTIL::getSensorNumber(proc, SENSOR_NAME_PROC_STATE);
    memcpy(&o_data[index], &SensorID1, 4);
    index += 4;

    // processor frequency sensor id
    memset(&o_data[index], 0, 4);
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


void getThermalControlMessageData(TARGETING::Target * i_procTarget,
                                  uint8_t* o_data,
                                  uint64_t & o_size)
{
    uint64_t index = 0;
    uint8_t l_numSets = 0;
    Target* sys = UTIL::assertGetToplevelTarget();
    assert(o_data != nullptr);

    o_data[index++] = OCC_CFGDATA_TCT_CONFIG;
    o_data[index++] = 0x30; // version


    // Processor Core Weight
    ATTR_CORE_WEIGHT_TENTHS_type l_proc_weight;
    if ( ! sys->tryGetAttr          //if attr does not exists.
           <ATTR_CORE_WEIGHT_TENTHS>(l_proc_weight))
    {
        l_proc_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    if(l_proc_weight == 0x0)
    {
        l_proc_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    o_data[index++] = l_proc_weight;


    // Processor Quad Weight
    ATTR_QUAD_WEIGHT_TENTHS_type l_quad_weight;
    if ( ! sys->tryGetAttr          //if attr does not exists.
           <ATTR_QUAD_WEIGHT_TENTHS>(l_quad_weight))
    {
        l_quad_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    if(l_quad_weight == 0x0)
    {
        l_quad_weight = OCC_PROC_DEFAULT_WEIGHT;
    }
    o_data[index++] = l_quad_weight;


    // Processor L3 Weight
    ATTR_L3_WEIGHT_TENTHS_type l_l3_weight;
    if ( ! sys->tryGetAttr          //if attr does not exists.
           <ATTR_L3_WEIGHT_TENTHS>(l_l3_weight))
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
    uint8_t l_timeout = 0;

    // Processor Deltas
    o_data[index++] = CFGDATA_FRU_TYPE_PROC_DELTA;

    // MVPD values for proc and procIO DVFS temps will be in the OCCPB
    // Send the deltas to the OCC

    ATTR_PROC_DVFS_TEMP_DELTA_C_type l_dvfsDelta;
    if(!i_procTarget->tryGetAttr<ATTR_PROC_DVFS_TEMP_DELTA_C>(l_dvfsDelta))
    {
        l_dvfsDelta = OCC_PROC_DEFAULT_DVFS_DELTA_C;
    }

    ATTR_PROC_ERROR_TEMP_DELTA_C_type l_errDelta;
    if(!i_procTarget->tryGetAttr<ATTR_PROC_ERROR_TEMP_DELTA_C>(l_errDelta))
    {
        l_errDelta = OCC_PROC_DEFAULT_ERR_DELTA_C;
    }

    if(!sys->tryGetAttr<ATTR_PROC_READ_TIMEOUT_SEC>(l_timeout) || l_timeout == 0)
    {
        l_timeout = OCC_PROC_DEFAULT_TIMEOUT;
    }

    o_data[index++] = l_dvfsDelta;
    o_data[index++] = l_errDelta;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // Memory Buffers
    uint8_t l_DVFS_temp = sys->getAttr<ATTR_MEMCTRL_THROTTLE_TEMP_DEG_C>();
    if(l_DVFS_temp == 0)
    {
        l_DVFS_temp =  OCC_MEMCTRL_DEFAULT_THROT_TEMP;
    }

    uint8_t l_ERR_temp = sys->getAttr<ATTR_MEMCTRL_ERROR_TEMP_DEG_C>();
    if(l_ERR_temp == 0)
    {
        l_ERR_temp = OCC_MEMCTRL_DEFAULT_ERROR_TEMP;
    }

    l_timeout = sys->getAttr<ATTR_MEMCTRL_READ_TIMEOUT_SEC>();
    if(l_timeout == 0)
    {
        l_timeout = OCC_MEMCTRL_DEFAULT_TIMEOUT;
    }
    o_data[index++] = CFGDATA_FRU_TYPE_MEMBUF;
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // DIMM
    l_DVFS_temp =sys->getAttr<ATTR_DIMM_THROTTLE_TEMP_DEG_C>();
    if(l_DVFS_temp == 0)
    {
        l_DVFS_temp = OCC_DIMM_DEFAULT_DVFS_TEMP;
    }

    l_ERR_temp = sys->getAttr<ATTR_DIMM_ERROR_TEMP_DEG_C>();
    if(l_ERR_temp == 0)
    {
        l_ERR_temp  = OCC_DIMM_DEFAULT_ERR_TEMP;
    }

    l_timeout = sys->getAttr<ATTR_DIMM_READ_TIMEOUT_SEC>();
    if(l_timeout == 0)
    {
        l_timeout   = OCC_DIMM_DEFAULT_TIMEOUT;
    }
    o_data[index++] = CFGDATA_FRU_TYPE_DIMM;
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // DRAM  (MC+DIMM)
    l_DVFS_temp = sys->getAttr<ATTR_MC_DRAM_THROTTLE_TEMP_DEG_C>();
    if(l_DVFS_temp == 0)
    {
        l_DVFS_temp =  OCC_DRAM_DEFAULT_THROT_TEMP;
    }

    l_ERR_temp = sys->getAttr<ATTR_MC_DRAM_ERROR_TEMP_DEG_C>();
    if(l_ERR_temp == 0)
    {
        l_ERR_temp = OCC_DRAM_DEFAULT_ERROR_TEMP;
    }

    l_timeout = sys->getAttr<ATTR_MC_DRAM_READ_TIMEOUT_SEC>();
    if(l_timeout == 0)
    {
        l_timeout = OCC_DRAM_DEFAULT_TIMEOUT;
    }

    o_data[index++] = CFGDATA_FRU_TYPE_MCDIMM;
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // VRM Vdd
    if(!sys->tryGetAttr<ATTR_VRM_VDD_DVFS_TEMP_DEG_C>(l_DVFS_temp))
        l_DVFS_temp = OCC_VRM_DEFAULT_DVFS_TEMP;
    if (l_DVFS_temp == 0)
    {
        l_DVFS_temp = OCC_VRM_DEFAULT_DVFS_TEMP;
    }
    if(!sys->tryGetAttr<ATTR_VRM_VDD_ERROR_TEMP_DEG_C>(l_ERR_temp))
        l_ERR_temp = OCC_VRM_DEFAULT_ERROR_TEMP;
    if (l_ERR_temp == 0)
    {
        l_ERR_temp = OCC_VRM_DEFAULT_ERROR_TEMP;
    }
    if(!sys->tryGetAttr<ATTR_VRM_VDD_READ_TIMEOUT_SEC>(l_timeout))
        l_timeout = OCC_VRM_DEFAULT_TIMEOUT;
    if(l_timeout == 0)
    {
        l_timeout = OCC_VRM_DEFAULT_TIMEOUT;
    }
    o_data[index++] = CFGDATA_FRU_TYPE_VRM_VDD;
    o_data[index++] = l_DVFS_temp;          //DVFS
    o_data[index++] = l_ERR_temp;           //ERROR
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // PMIC
    l_DVFS_temp = sys->getAttr<ATTR_PMIC_THROTTLE_TEMP_DEG_C>();
    if(l_DVFS_temp == 0)
    {
        l_DVFS_temp =  OCC_PMIC_DEFAULT_THROT_TEMP;
    }

    l_ERR_temp = sys->getAttr<ATTR_PMIC_ERROR_TEMP_DEG_C>();
    if(l_ERR_temp == 0)
    {
        l_ERR_temp = OCC_PMIC_DEFAULT_ERROR_TEMP;
    }

    l_timeout = sys->getAttr<ATTR_PMIC_READ_TIMEOUT_SEC>();
    if(l_timeout == 0)
    {
        l_timeout = OCC_PMIC_DEFAULT_TIMEOUT;
    }

    o_data[index++] = CFGDATA_FRU_TYPE_PMIC;
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // MEMCTRL_EXT
    l_DVFS_temp = sys->getAttr<ATTR_MC_EXT_THROTTLE_TEMP_DEG_C>();
    if(l_DVFS_temp == 0)
    {
        l_DVFS_temp =  OCC_MCEXT_DEFAULT_THROT_TEMP;
    }

    l_ERR_temp = sys->getAttr<ATTR_MC_EXT_ERROR_TEMP_DEG_C>();
    if(l_ERR_temp == 0)
    {
        l_ERR_temp = OCC_MCEXT_DEFAULT_ERROR_TEMP;
    }

    l_timeout = sys->getAttr<ATTR_MC_EXT_READ_TIMEOUT_SEC>();
    if(l_timeout == 0)
    {
        l_timeout = OCC_MCEXT_DEFAULT_TIMEOUT;
    }

    o_data[index++] = CFGDATA_FRU_TYPE_MEMCTRL_EXT;
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;


    // Processor I/O Ring Deltas
    if(!i_procTarget->tryGetAttr<ATTR_PROC_IO_DVFS_TEMP_DELTA_C>(l_dvfsDelta))
    {
        l_dvfsDelta = OCC_PROC_IO_DEFAULT_DVFS_DELTA_C;
    }

    if(!i_procTarget->tryGetAttr<ATTR_PROC_IO_ERROR_TEMP_DELTA_C>(l_errDelta))
    {
        l_errDelta = OCC_PROC_IO_DEFAULT_ERR_DELTA_C;
    }

    l_timeout = 0;
    if(!sys->tryGetAttr<ATTR_PROC_IO_READ_TIMEOUT_SEC>(l_timeout) || l_timeout == 0)
    {
        l_timeout = OCC_PROC_IO_DEFAULT_TIMEOUT;
    }

    o_data[index++] = CFGDATA_FRU_TYPE_PROC_IO_DELTA;
    o_data[index++] = l_dvfsDelta;          //DVFS
    o_data[index++] = l_errDelta;           //ERROR
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

const unsigned int NUM_APSS_CHANNELS = 16;
void getApssMessageData(uint8_t* o_data,
                        uint64_t & o_size)
{
    Target* sys = UTIL::assertGetToplevelTarget();
    bool attr_failure = false;

    ATTR_ADC_CHANNEL_FUNC_IDS_type function;
    if (!sys->tryGetAttr<ATTR_ADC_CHANNEL_FUNC_IDS>(function) ||
        (sizeof(function) != NUM_APSS_CHANNELS))
    {
        TMGT_ERR("getApssMessageData: Failed to get FUNC_IDS");
        attr_failure = true;
    }

    ATTR_ADC_CHANNEL_GNDS_type ground;
    if (!sys->tryGetAttr<ATTR_ADC_CHANNEL_GNDS>(ground) ||
        (sizeof(ground) != NUM_APSS_CHANNELS))
    {
        TMGT_ERR("getApssMessageData: Failed to get GNDS");
        attr_failure = true;
    }

    ATTR_ADC_CHANNEL_GAINS_type gain;
    if (!sys->tryGetAttr<ATTR_ADC_CHANNEL_GAINS>(gain) ||
        (sizeof(gain) != (NUM_APSS_CHANNELS*4)))
    {
        TMGT_ERR("getApssMessageData: Failed to get GAINS, size=%d",
                 sizeof(gain));
        attr_failure = true;
    }

    ATTR_ADC_CHANNEL_OFFSETS_type offset;
    if (!sys->tryGetAttr<ATTR_ADC_CHANNEL_OFFSETS>(offset) ||
        (sizeof(offset) != (NUM_APSS_CHANNELS*4)))
    {
        TMGT_ERR("getApssMessageData: Failed to get OFFSETS, size=%d",
                 sizeof(offset));
        attr_failure = true;
    }

    ATTR_ADC_CHANNEL_SENSOR_NUMBERS_type
        apss_sensors;
    if (!sys->tryGetAttr<ATTR_ADC_CHANNEL_SENSOR_NUMBERS>(apss_sensors) ||
        (sizeof(apss_sensors) != (NUM_APSS_CHANNELS*4)))
    {
        TMGT_ERR("getApssMessageData: Failed to get SENSOR_NUMBERS, size=%d",
                 sizeof(apss_sensors));
        // Just use 00s for sensor numbers
        memset(apss_sensors, 0, sizeof(apss_sensors));
    }

    ATTR_APSS_GPIO_PORT_MODES_type  gpioMode;
    if (!sys->tryGetAttr<ATTR_APSS_GPIO_PORT_MODES>(gpioMode))
    {
        TMGT_ERR("getApssMessageData: Failed to get GPIO MODES");
        attr_failure = true;
    }

    ATTR_APSS_GPIO_PORT_PINS_type gpioPin;
    if (!sys->tryGetAttr<ATTR_APSS_GPIO_PORT_PINS>(gpioPin))
    {
        TMGT_ERR("getApssMessageData: Failed to get GPIO PINS");
        attr_failure = true;
    }

    uint64_t idx = 0;
    if (attr_failure == false)
    {
        o_data[0] = OCC_CFGDATA_APSS_CONFIG;
        o_data[1] = 0x20; // version
        o_data[2] = 0;
        o_data[3] = 0;
        idx = 4;

        for(uint64_t channel = 0; channel < NUM_APSS_CHANNELS; ++channel)
        {
            o_data[idx] = function[channel]; // ADC Channel assignement
            idx += sizeof(uint8_t);

            const uint32_t sensorId = apss_sensors[channel];
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
    }
    else
    {
        /*@
         * @errortype
         * @subsys EPUB_FIRMWARE_SP
         * @moduleid HTMGT_MOD_APSS_DATA
         * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
         * @userdata1 ocmb instance
         * @devdesc Invalid APSS config data was found
         */
        errlHndl_t l_err = NULL;
        bldErrLog(l_err, HTMGT_MOD_APSS_DATA,
                  HTMGT_RC_ATTRIBUTE_ERROR,
                  0, 0,
                  ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
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
            getMemConfigMessageData(i_occ,
                                    o_cfgDataPtr, cfgDataLength);
            break;

        case OCC_CFGDATA_PCAP_CONFIG:
            getPowerCapMessageData(o_cfgDataPtr, cfgDataLength);
            break;

        case OCC_CFGDATA_SYS_CONFIG:
            getSystemConfigMessageData(*i_occ,
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
            {
                TARGETING::Target* procTarget = nullptr;
                procTarget = TARGETING::
                    getImmediateParentByAffinity(i_occ->getTarget());
                getThermalControlMessageData(procTarget,
                                             o_cfgDataPtr,
                                            cfgDataLength);
            }
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
