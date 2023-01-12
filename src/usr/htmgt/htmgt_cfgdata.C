/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_cfgdata.C $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
#include <chips/common/utils/chipids.H>

using namespace TARGETING;

//for unit testing
//#define TRACUCOMP(args...)  TMGT_INF(args)
#define TRACUCOMP(args...)

namespace HTMGT
{

#define OCC_MEM_TYPE_EXPLORER 0xA0
#define OCC_MEM_TYPE_ODYSSEY  0xB0
#define OCC_MEM_TYPE_ISDIMM   0xC0
    bool G_wofSupported = true;
    uint8_t G_system_type = 0;
    uint8_t G_memory_type = OCC_MEM_TYPE_EXPLORER;


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
             * @custdesc An internal firmware error occurred
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

    //Byte 8 Memory type
    o_data[io_index++] = i_memType;

    //Byte 9 DIMM Info Byte 1 (Memory DTS 0-3/DIMM I2C Engine)
    o_data[io_index++] = i_dimmInfo1;

    //Byte 10 DIMM Info Byte 2 (Temperature Type/DIMM I2C Port)
    o_data[io_index++] = i_dimmInfo2;

    //Byte 11 DIMM Info Byte 3 (Reserved/DIMM I2C Address)
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
                 * @custdesc An internal firmware error occurred
                 */
                errlHndl_t l_err = nullptr;
                bldErrLog(l_err, HTMGT_MOD_CONVERT_TEMP_TYPE,
                          HTMGT_RC_INVALID_MEM_SENSOR,
                          i_sensor_type, 0, 0, 0,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
            }
            break;
    }

    return occ_type;
}


// Read I2C parameters for target ISDIMM and add to OCC config
uint8_t addIsDimm(uint8_t* o_data,
                  Target* i_portTarget,
                  Target* i_dimmTarget,
                  uint32_t &io_index,
                  const uint8_t i_ocmbNum)

{
    uint8_t numSets = 0;

    // TODO JIRA: PFES-6 - Hardcoded I2C Parms until available in MRW
    uint8_t i2cEngine = 3; // PIB I2C master engine for DIMM (E = 3)
    uint8_t i2cPort = 3 + i_ocmbNum;        // I2C port (0/1)
    uint8_t i2cAddr = 0x30 + (i_ocmbNum*2); // sensor I2C Address
    TMGT_INF("ocmbInit:       I2C Engine[%d] Port[%d] Address[0x%02X] (hardcoded)",
             i2cEngine, i2cPort, i2cAddr);

#if 0
    writeMemConfigData(o_data,
                       i_portTarget,
                       SENSOR_NAME_DIMM_STATE,
                       SENSOR_NAME_DIMM_TEMP,
                       OCC_MEM_TYPE_ISDIMM,
                       i2cEngine,
                       i2cPort,
                       i2cAddr,
                       io_index );
    ++numSets;
#endif

    return numSets;
}


// Read internal DTS type for target OCMB and add to OCC config
uint8_t addOcmbInternalDts(uint8_t*  o_data,
                           Target*   i_ocmbTarget,
                           uint8_t   i_ocmbNum,
                           uint8_t&  o_memType,
                           uint32_t& io_index)
{
    uint8_t numSets = 0;
    uint8_t dtsType = 0xFF; // disabled
    const uint32_t chipId = i_ocmbTarget->getAttr<ATTR_CHIP_ID>();
    const ATTR_HUID_type l_ocmb_huid = get_huid(i_ocmbTarget);
    static bool L_logged_invalid = false;

    // Determine internal DTS type for OCMB
    if(i_ocmbTarget->tryGetAttr
       <TARGETING::ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE >(dtsType))
    {
        if ((dtsType == MEM_EFF_THERM_SENSOR_DIFF_USAGE_MB_INT_DTM) ||
            (dtsType == MEM_EFF_THERM_SENSOR_DIFF_USAGE_MB_INT_DTM_REM))
        {
            dtsType = 0x01; // Internal Memory Controller
        }
        else if (dtsType == MEM_EFF_THERM_SENSOR_DIFF_USAGE_DISABLED)
        {
            dtsType = 0xFF; // Disabled
        }
        else
        {
            TMGT_ERR("addOcmbInternalDts: Unsupported ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE 0x%02X",
                     dtsType);
            if (!L_logged_invalid)
            {
                L_logged_invalid = true;
                /*@
                 * @errortype
                 * @subsys EPUB_FIRMWARE_SP
                 * @reasoncode HTMGT_RC_INVALID_MEM_SENSOR
                 * @moduleid HTMGT_MOD_ADD_OBMC_INTERNAL_DTS
                 * @userdata1 USAGE type
                 * @userdata2 OCMB HUID
                 * @devdesc Unsupported
                 *             ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE type
                 * @custdesc An internal firmware error occurred
                 */
                errlHndl_t l_err = nullptr;
                bldErrLog(l_err, HTMGT_MOD_ADD_OBMC_INTERNAL_DTS,
                          HTMGT_RC_INVALID_MEM_SENSOR,
                          dtsType, l_ocmb_huid, 0, 0,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
            }
            dtsType = 0xFF; // Disabled
        }
        numSets++;
    }
    else
    {
        TMGT_ERR("addOcmbInternalDts: Failed to read ATTR_MEM_EFF_THERM_SENSOR_DIFF_USAGE");
        dtsType = 0xFF; // Disabled
        if (!L_logged_invalid)
        {
            L_logged_invalid = true;
            /*@
             * @errortype
             * @subsys EPUB_FIRMWARE_SP
             * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
             * @moduleid HTMGT_MOD_ADD_OBMC_INTERNAL_DTS
             * @userdata1 OCMB number
             * @userdata2 chip ID
             * @devdesc Failed to read MEM_EFF_THERM_SENSOR_DIFF_USAGE
             * @custdesc Failed to determine memory temperature sensor type.
             *           Some memory temperatures may not be available.
             */
            errlHndl_t l_err = nullptr;
            bldErrLog(l_err, HTMGT_MOD_ADD_OBMC_INTERNAL_DTS,
                      HTMGT_RC_ATTRIBUTE_ERROR,
                      i_ocmbNum, chipId, 0, 0,
                      ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
        }
    }

    if (chipId == POWER_CHIPID::EXPLORER_16)
    {
        // EXPLORER/DDR4 OCMB Memory type (0xAn, where n is Memory Buffer 0-F)
        o_memType = OCC_MEM_TYPE_EXPLORER | i_ocmbNum;
        G_memory_type = OCC_MEM_TYPE_EXPLORER;

        TMGT_INF("ocmbInit: OCMB-EXPL[%d] HUID=0x%08lX DTS[int] TYPE[%d] "
                 "(pos=0x%02X, ordinal=0x%02X)",
                 i_ocmbNum, l_ocmb_huid, dtsType,
                 i_ocmbTarget->getAttr<ATTR_POSITION>(),
                 i_ocmbTarget->getAttr<ATTR_ORDINAL_ID>());
    }
    else
    {
        // ODYSSEY/DDR5 OCMB Memory type (0xBn, where n is Memory Buffer 0-F)
        o_memType = OCC_MEM_TYPE_ODYSSEY | i_ocmbNum;
        G_memory_type = OCC_MEM_TYPE_ODYSSEY;

        TMGT_INF("ocmbInit: OCMB-ODYS[%d] HUID=0x%08lX DTS[int] TYPE[%d] "
                 "(pos=0x%02X, ordinal=0x%02X)",
                 i_ocmbNum, l_ocmb_huid, dtsType,
                 i_ocmbTarget->getAttr<ATTR_POSITION>(),
                 i_ocmbTarget->getAttr<ATTR_ORDINAL_ID>());
    }

    if (numSets > 0)
    {
        // add entry for the OCMB itself
        writeMemConfigData(o_data,
                           i_ocmbTarget,
                           SENSOR_NAME_MEMBUF_STATE,
                           SENSOR_NAME_MEMBUF_TEMP,
                           o_memType,
                           0xFF,        // on-chip thermal sensor
                           dtsType,      // temperature type (internal, disabled)
                           0,           // reserved
                           io_index);
    }

    return numSets;
}

// Read available DTSs for target OCMB DIMMS and add to OCC config
uint8_t addOcmbExternalDts(uint8_t* o_data,
                           Target* i_ocmbTarget,
                           const uint8_t i_memType,
                           uint32_t &io_index)
{
    uint8_t numSets = 0;
    uint8_t dtsType = 0xFF; // disabled
    static bool attrReadFailure = false;

    uint8_t maxNumDts = HTMGT_NUM_DTS_PER_OCMB;
    if ((i_memType & 0xF0) == OCC_MEM_TYPE_ODYSSEY)
    {
        maxNumDts = HTMGT_NUM_DTS_PER_OCMB_ODYSSEY;
    }

    // Update entry with DIMM DTSs for this OCMB
    for (unsigned int l_dts = 0; l_dts < maxNumDts; ++l_dts)
    {
        if (l_dts == 0)
        {
            if (i_ocmbTarget->tryGetAttr
                <TARGETING::ATTR_MEM_EFF_THERM_SENSOR_0_USAGE>(dtsType))
            {
                dtsType = convert_temp_type(dtsType);
            }
            else
            {
                TMGT_ERR("ocmbInit: Failed to read ATTR_MEM_EFF_THERM_SENSOR_0_USAGE");
                dtsType = 0xFF; // disabled
                attrReadFailure = true;
            }
        }
        else if (l_dts == 1)
        {
            if (i_ocmbTarget->tryGetAttr
                <TARGETING::ATTR_MEM_EFF_THERM_SENSOR_1_USAGE>(dtsType))
            {
                dtsType = convert_temp_type(dtsType);
            }
            else
            {
                TMGT_ERR("ocmbInit: Failed to read ATTR_MEM_EFF_THERM_SENSOR_1_USAGE");
                dtsType = 0xFF; // disabled
                attrReadFailure = true;
            }
        }
        else if (l_dts == 2)
        {
            if (i_ocmbTarget->tryGetAttr
                <TARGETING::ATTR_MEM_EFF_THERM_SENSOR_2_USAGE>(dtsType))
            {
                dtsType = convert_temp_type(dtsType);
            }
            else
            {
                TMGT_ERR("ocmbInit: Failed to read ATTR_MEM_EFF_THERM_SENSOR_2_USAGE");
                dtsType = 0xFF; // disabled
                attrReadFailure = true;
            }
        }
        else
        {
            if (i_ocmbTarget->tryGetAttr
                <TARGETING::ATTR_MEM_EFF_THERM_SENSOR_3_USAGE>(dtsType))
            {
                dtsType = convert_temp_type(dtsType);
            }
            else
            {
                TMGT_ERR("ocmbInit: Failed to read ATTR_MEM_EFF_THERM_SENSOR_3_USAGE");
                dtsType = 0xFF; // disabled
                attrReadFailure = true;
            }
        }

        TMGT_INF("ocmbInit:   DTS[%d] TYPE[%d]", l_dts, dtsType);
        writeMemConfigData(o_data,
                           i_ocmbTarget,
                           SENSOR_NAME_DIMM_STATE,
                           SENSOR_NAME_DIMM_TEMP,
                           i_memType,  // Memory Buffer #
                           l_dts,      // DTS #
                           dtsType,     // Temperature Type
                           0,          // reserved
                           io_index );
        numSets++;
    } // for each DTS

    if (attrReadFailure)
    {
        TMGT_ERR("addOcmbExternalDts: Failed to read at least one memory thermal sensor attribute");
        /*@
         * @errortype
         * @subsys EPUB_FIRMWARE_SP
         * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
         * @moduleid HTMGT_MOD_ADD_OBMC_DTS
         * @userdata1 DTS count
         * @userdata2 Memory type
         * @devdesc Failed to read memory thermal sensor usage type
         * @custdesc Failed to determine memory temperature sensor type.
         *           Some memory temperatures may not be available.
         */
        errlHndl_t l_err = nullptr;
        bldErrLog(l_err, HTMGT_MOD_ADD_OBMC_DTS,
                  HTMGT_RC_ATTRIBUTE_ERROR,
                  numSets, i_memType, 0, 0,
                  ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
    }

    return numSets;
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
/*            or                                                                */
/*             1 ODYSSEY OCMB chip / DDIMM                                      */
/*             1 port / ODYSSEY OCMB chip                                       */
/*             4 channels (data ports) / port                                   */
/*             2 sides / data port (A/B)                                        */
/*             2 DDR5 DIMMs / port                                              */
/*            or                                                                */
/*             1 EXPLORER OCMB chip supports 1 DDR4 ISDIMM                      */
/*                                                                              */
/*  There is no mixing of DIMM types within a node/drawer                       */
/*                                                                              */
/*  Logical Layout per proc:                                                    */
/*                     OCMB0 -- DDIMM0 -- CHIP0 -- (port 0) -- DIMM0            */
/*                                                          -- DIMM1            */
/*                           -- DDIMM1 -- CHIP0 -- (port 0) -- DIMM0            */
/*                                                          -- DIMM1            */
/*              or                                                              */
/*                     OCMB0 -- ISDIMM0                                         */
/*                                                                              */
/* End Function Specification ***************************************************/
uint8_t ocmbInit(Occ *i_occ,
                 uint8_t* o_data,
                 uint32_t & io_index)
{
    TargetHandleList ocmb_list;
    static bool L_logged_error = false;
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
            const ATTR_HUID_type l_ocmb_huid = get_huid(ocmb);
            uint8_t l_memType;

            ATTR_MEM_MRW_IS_PLANAR_type isDIMMs = false;
            if (!ocmb->tryGetAttr<ATTR_MEM_MRW_IS_PLANAR>(isDIMMs))
            {
                TMGT_ERR("ocmbInit: failed to read ATTR_MEM_MRW_IS_PLANAR");
                isDIMMs = false;
            }

            // OCMB instance comes from the parent (OMI target)
            Target *omi_target = getImmediateParentByAffinity(ocmb);
            if (omi_target != nullptr)
            {
                // get relative OCMB per processor
                l_ocmb_num = omi_target->getAttr<ATTR_CHIP_UNIT>();
            }
            else
            {
                TMGT_ERR("ocmbInit: Unable to determine OCMB parent for HUID 0x%04X",
                         l_ocmb_huid);
                if (!L_logged_error)
                {
                    /*@
                     * @errortype
                     * @subsys EPUB_FIRMWARE_SP
                     * @reasoncode HTMGT_RC_TARGET_NOT_FOUND
                     * @moduleid HTMGT_MOD_OCMB_INIT
                     * @userdata1 OCC Instance
                     * @userdata2 OCMB HUID
                     * @devdesc Failed to find OMI target for OCMB
                     * @custdesc Failed to determine part of the memory config.
                     *           Some memory temperatures may not be available.
                     */
                    errlHndl_t l_err = nullptr;
                    bldErrLog(l_err, HTMGT_MOD_OCMB_INIT,
                              HTMGT_RC_TARGET_NOT_FOUND,
                              i_occ->getInstance(), l_ocmb_huid, 0, 0,
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    L_logged_error = true;
                }
                continue;
            }

            // Get list of functional memory ports associated with this OCMB_CHIP
            getChildAffinityTargets(port_list, ocmb, CLASS_UNIT, TYPE_MEM_PORT);
            if (port_list.size() > 0)
            {
                TargetHandleList dimm_list;

                // Currently only support a single port per OCMB (use first port)
                Target* port_target = port_list[0];
                if (port_list.size() > 1)
                {
                    TMGT_ERR("ocmbInit: Found %d functional ports (expected 1)",
                             port_list.size());
                }

                numSets += addOcmbInternalDts(o_data, ocmb, l_ocmb_num, l_memType, io_index);
                if (!isDIMMs)
                {
                    numSets += addOcmbExternalDts(o_data, ocmb, l_memType, io_index);
                }

                // Get list of functional DIMMs assocated for this port (single port)
                getChildAffinityTargets(dimm_list, port_target,
                                        CLASS_LOGICAL_CARD, TYPE_DIMM);
                const unsigned long l_port_huid = get_huid(port_target);
                TMGT_INF("ocmbInit:   PORT[%d] HUID=0x%08lX (%d functional DIMMs)",
                         port_target->getAttr<TARGETING::ATTR_CHIP_UNIT>(),
                         l_port_huid, dimm_list.size());

                if (dimm_list.size() > 0)
                {
                    for (uint8_t index=0; index < dimm_list.size(); index++)
                    {
                        if (!isDIMMs)
                        {
                            // Dump DIMM info for completeness (DTSs will be added after this)
                            TMGT_INF("ocmbInit:     DIMM[%d] HUID=0x%08lX (position=0x%02X)",
                                     index, get_huid(dimm_list[index]),
                                     dimm_list[index]->getAttr<TARGETING::ATTR_POSITION>());
                        }
                        else
                        {
                            // ISDIMM (I2C) Memory type (0xC0)
                            TMGT_INF("ocmbInit:     ISDIMM[%d] HUID=0x%08lX (position=0x%02X)",
                                     index, get_huid(dimm_list[index]),
                                     dimm_list[index]->getAttr<TARGETING::ATTR_POSITION>());

                            numSets += addIsDimm(o_data, port_target, dimm_list[index], io_index,
                                                 l_ocmb_num);
                        }
                    }
                }
            }
        }
    }
    else
    {
        TMGT_ERR("ocmbInit: SKIPPING UNKNOWN PROCESSOR[%d] (model 0x%02X, HUID=0x%08lX)",
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

    // Get functional OCMBs associated with this processor
    TargetHandleList ocmb_list;
    getChildAffinityTargets(ocmb_list, proc, CLASS_CHIP, TYPE_OCMB_CHIP);
    TMGT_INF("getMemThrottleMessageData: p%d has %d functional OCMBs",
             i_occ_instance, ocmb_list.size());

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

    bool loggedAttrFailure = false;
    for(const auto & ocmb_target : ocmb_list)
    {
        // OCMB instance comes from the parent (OMI target)
        uint8_t l_ocmb_pos = 0xFF;
        TARGETING::Target * omi_target = getImmediateParentByAffinity(ocmb_target);
        if (omi_target != nullptr)
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

        // Read the throttle and power values for this OCMB
        bool attr_failure = false;
        ATTR_OT_MIN_N_PER_SLOT_type nps_min;
        if (!ocmb_target->tryGetAttr<ATTR_OT_MIN_N_PER_SLOT>(nps_min))
        {
            TMGT_ERR("getMemThrottleMessageData: failed to read OT_MIN_N_PER_SLOT");
            attr_failure = true;
        }
        ATTR_N_PLUS_ONE_N_PER_SLOT_type nps_redun;
        ATTR_N_PLUS_ONE_N_PER_PORT_type npp_redun;
        if (!ocmb_target->tryGetAttr<ATTR_N_PLUS_ONE_N_PER_SLOT>(nps_redun))
        {
            TMGT_ERR("getMemThrottleMessageData: failed to read N_PLUS_ONE_N_PER_SLOT");
            attr_failure = true;
        }
        if (!ocmb_target->tryGetAttr<ATTR_N_PLUS_ONE_N_PER_PORT>(npp_redun))
        {
            TMGT_ERR("getMemThrottleMessageData: failed to read N_PLUS_ONE_N_PER_PORT");
            attr_failure = true;
        }
        ATTR_OVERSUB_N_PER_SLOT_type nps_oversub;
        ATTR_OVERSUB_N_PER_PORT_type npp_oversub;
        if (!ocmb_target->tryGetAttr<ATTR_OVERSUB_N_PER_SLOT>(nps_oversub))
        {
            TMGT_ERR("getMemThrottleMessageData: failed to read OVERSUB_N_PER_SLOT");
            attr_failure = true;
        }
        if (!ocmb_target->tryGetAttr<ATTR_OVERSUB_N_PER_PORT>(npp_oversub))
        {
            TMGT_ERR("getMemThrottleMessageData: failed to read OVERSUB_N_PER_PORT");
            attr_failure = true;
        }

        if (attr_failure)
        {
            if (!loggedAttrFailure)
            {
                /*@
                 * @errortype
                 * @subsys EPUB_FIRMWARE_SP
                 * @moduleid HTMGT_MOD_MEMTHROTTLE
                 * @reasoncode HTMGT_RC_ATTRIBUTE_ERROR
                 * @userdata1 ocmb instance
                 * @userdata2 occ instance
                 * @devdesc Failed to read throttle settings
                 * @custdesc An internal firmware error occurred
                 */
                errlHndl_t l_err = nullptr;
                bldErrLog(l_err, HTMGT_MOD_MEMTHROTTLE,
                          HTMGT_RC_ATTRIBUTE_ERROR,
                          l_ocmb_pos, i_occ_instance, 0, 0,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                loggedAttrFailure = true;
            }
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
                (nps_redun[port_rel_pos] == 0) ||
                (nps_oversub[port_rel_pos] == 0))
            {
                TMGT_ERR("getMemThrottleMessageData: OCMB%d/Port%d [%d]"
                         " - Ignored due to null throttle",
                         l_ocmb_pos, port_unit, port_rel_pos);
                TMGT_ERR("N/slot: Min=%d, Redun=%d, Oversub=%d",
                         nps_min[port_rel_pos],
                         nps_redun[port_rel_pos],
                         nps_oversub[port_rel_pos]);
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
            UINT16_PUT(&o_data[index+16], nps_oversub[port_rel_pos]);
            UINT16_PUT(&o_data[index+18], npp_oversub[port_rel_pos]);
            // reserved
            memset(&o_data[index+20], 0, 2); // reserved
            index += 22;
            ++numSets ;
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
    SensorID1 = UTIL::getSensorNumber(proc, SENSOR_NAME_VRM_VDD_FAULT);
    memcpy(&o_data[index], &SensorID1, 4);
    index += 4;

    //Format 21 - VRM VDD Temperature Sensor ID
    SensorID1 = UTIL::getSensorNumber(proc, SENSOR_NAME_VRM_VDD_TEMP);
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
    uint8_t l_DVFS_temp, l_ERR_temp;
    if (G_memory_type != OCC_MEM_TYPE_ODYSSEY)
    {
        l_DVFS_temp = sys->getAttr<ATTR_MEMCTRL_THROTTLE_TEMP_DEG_C>();
        if(l_DVFS_temp == 0)
        {
            l_DVFS_temp =  OCC_MEMCTRL_DEFAULT_THROT_TEMP;
        }

        l_ERR_temp = sys->getAttr<ATTR_MEMCTRL_ERROR_TEMP_DEG_C>();
        if(l_ERR_temp == 0)
        {
            l_ERR_temp = OCC_MEMCTRL_DEFAULT_ERROR_TEMP;
        }

        l_timeout = sys->getAttr<ATTR_MEMCTRL_READ_TIMEOUT_SEC>();
        if(l_timeout == 0)
        {
            l_timeout = OCC_MEMCTRL_DEFAULT_TIMEOUT;
        }
    }
    else
    {
        l_DVFS_temp = sys->getAttr<ATTR_DDR5_MEMCTRL_THROTTLE_TEMP_DEG_C>();
        if(l_DVFS_temp == 0)
        {
            l_DVFS_temp =  OCC_MEMCTRL_DEFAULT_THROT_TEMP;
        }

        l_ERR_temp = sys->getAttr<ATTR_DDR5_MEMCTRL_ERROR_TEMP_DEG_C>();
        if(l_ERR_temp == 0)
        {
            l_ERR_temp = OCC_MEMCTRL_DEFAULT_ERROR_TEMP;
        }

        l_timeout = sys->getAttr<ATTR_DDR5_MEMCTRL_READ_TIMEOUT_SEC>();
        if(l_timeout == 0)
        {
            l_timeout = OCC_MEMCTRL_DEFAULT_TIMEOUT;
        }
    }
    o_data[index++] = CFGDATA_FRU_TYPE_MEMBUF;
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // DIMM
    if (G_memory_type != OCC_MEM_TYPE_ODYSSEY)
    {
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
    }
    else
    {
        l_DVFS_temp =sys->getAttr<ATTR_DDR5_DIMM_THROTTLE_TEMP_DEG_C>();
        if(l_DVFS_temp == 0)
        {
            l_DVFS_temp = OCC_DIMM_DEFAULT_DVFS_TEMP;
        }

        l_ERR_temp = sys->getAttr<ATTR_DDR5_DIMM_ERROR_TEMP_DEG_C>();
        if(l_ERR_temp == 0)
        {
            l_ERR_temp  = OCC_DIMM_DEFAULT_ERR_TEMP;
        }

        l_timeout = sys->getAttr<ATTR_DDR5_DIMM_READ_TIMEOUT_SEC>();
        if(l_timeout == 0)
        {
            l_timeout   = OCC_DIMM_DEFAULT_TIMEOUT;
        }
    }
    o_data[index++] = CFGDATA_FRU_TYPE_DIMM;
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // DRAM  (MC+DIMM)
    if (G_memory_type != OCC_MEM_TYPE_ODYSSEY)
    {
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
    }
    else
    {
        l_DVFS_temp = sys->getAttr<ATTR_DDR5_MC_DRAM_THROTTLE_TEMP_DEG_C>();
        if(l_DVFS_temp == 0)
        {
            l_DVFS_temp =  OCC_DRAM_DEFAULT_THROT_TEMP;
        }

        l_ERR_temp = sys->getAttr<ATTR_DDR5_MC_DRAM_ERROR_TEMP_DEG_C>();
        if(l_ERR_temp == 0)
        {
            l_ERR_temp = OCC_DRAM_DEFAULT_ERROR_TEMP;
        }

        l_timeout = sys->getAttr<ATTR_DDR5_MC_DRAM_READ_TIMEOUT_SEC>();
        if(l_timeout == 0)
        {
            l_timeout = OCC_DRAM_DEFAULT_TIMEOUT;
        }
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
    if (G_memory_type != OCC_MEM_TYPE_ODYSSEY)
    {
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
    }
    else
    {
        l_DVFS_temp = sys->getAttr<ATTR_DDR5_PMIC_THROTTLE_TEMP_DEG_C>();
        if(l_DVFS_temp == 0)
        {
            l_DVFS_temp =  OCC_PMIC_DEFAULT_THROT_TEMP;
        }

        l_ERR_temp = sys->getAttr<ATTR_DDR5_PMIC_ERROR_TEMP_DEG_C>();
        if(l_ERR_temp == 0)
        {
            l_ERR_temp = OCC_PMIC_DEFAULT_ERROR_TEMP;
        }

        l_timeout = sys->getAttr<ATTR_DDR5_PMIC_READ_TIMEOUT_SEC>();
        if(l_timeout == 0)
        {
            l_timeout = OCC_PMIC_DEFAULT_TIMEOUT;
        }
    }
    o_data[index++] = CFGDATA_FRU_TYPE_PMIC;
    o_data[index++] = l_DVFS_temp;
    o_data[index++] = l_ERR_temp;
    o_data[index++] = l_timeout;
    o_data[index++] = 0x00; // reserved
    o_data[index++] = 0x00;
    l_numSets++;

    // MEMCTRL_EXT
    if (G_memory_type != OCC_MEM_TYPE_ODYSSEY)
    {
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
    }
    else
    {
        l_DVFS_temp = sys->getAttr<ATTR_DDR5_MC_EXT_THROTTLE_TEMP_DEG_C>();
        if(l_DVFS_temp == 0)
        {
            l_DVFS_temp =  OCC_MCEXT_DEFAULT_THROT_TEMP;
        }

        l_ERR_temp = sys->getAttr<ATTR_DDR5_MC_EXT_ERROR_TEMP_DEG_C>();
        if(l_ERR_temp == 0)
        {
            l_ERR_temp = OCC_MCEXT_DEFAULT_ERROR_TEMP;
        }

        l_timeout = sys->getAttr<ATTR_DDR5_MC_EXT_READ_TIMEOUT_SEC>();
        if(l_timeout == 0)
        {
            l_timeout = OCC_MCEXT_DEFAULT_TIMEOUT;
        }
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
         * @devdesc Invalid APSS config data was found
         * @custdesc An internal firmware error occurred
         */
        errlHndl_t l_err = nullptr;
        bldErrLog(l_err, HTMGT_MOD_APSS_DATA,
                  HTMGT_RC_ATTRIBUTE_ERROR,
                  0, 0, 0, 0,
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
