/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occ.C $                                   */
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

#include <htmgt/htmgt.H>
#include <htmgt/htmgt_reasoncodes.H>
#include "htmgt_utility.H"
#include "htmgt_occcmd.H"
#include "htmgt_cfgdata.H"
#include "htmgt_occ.H"
#include "htmgt_poll.H"
#include <stdio.h>

#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <console/consoleif.H>
#include <sys/time.h>
#include <arch/ppc.H>
#include <isteps/pm/occAccess.H>
#include <errl/errludlogregister.H>
#include <isteps/pm/pm_common_ext.H>
#include <pldm/requests/pldm_pdr_requests.H>
#include <isteps/pm/scopedHomerMapper.H>

namespace HTMGT
{

    Occ::Occ(const uint8_t   i_instance,
             const bool      i_masterCapable,
             uint8_t       * i_homer,
             TARGETING::TargetHandle_t i_target,
             const occRole   i_role)
        :iv_instance(i_instance),
        iv_masterCapable(i_masterCapable),
        iv_role(i_role),
        iv_state(OCC_STATE_UNKNOWN),
        iv_mode(POWERMODE_UNKNOWN),
        iv_commEstablished(false),
        iv_needsReset(false),
        iv_needsWofReset(false),
        iv_wofResetCount(0),
        iv_wofResetReasons(0),
        iv_failed(false),
        iv_seqNumber(0),
        iv_homer(nullptr),
        iv_homerValid(false),
        iv_target(i_target),
        iv_lastPollValid(false),
        iv_occsPresent(0),
        iv_gpuCfg(0),
        iv_resetReason(OCC_RESET_REASON_NONE),
        iv_exceptionLogged(0),
        iv_resetCount(0),
        iv_version(0x01)
    {
    }

    Occ::~Occ()
    {
    }


    // Return true if specified status bit is set in last poll response
    bool Occ::statusBitSet(const uint8_t i_statusBit)
    {
        bool isSet = false;

        if (iv_lastPollValid)
        {
            const occPollRspStruct_t *lastPoll =
                (occPollRspStruct_t*)iv_lastPollResponse;
            isSet = ((lastPoll->status & i_statusBit) == i_statusBit);
        }

        return isSet;
    }


    // Set state of the OCC
    errlHndl_t Occ::setState(const occStateId i_state)
    {
        errlHndl_t l_err = nullptr;

        if (OCC_ROLE_MASTER == iv_role)
        {
            const uint8_t l_cmdData[] =
            {
                0x30, // version
                i_state,
                0x00, // mode
                0x00, // FFO freq
                0x00,
                0x00  // reserved
            };

            OccCmd cmd(this, OCC_CMD_SET_STATE,
                       sizeof(l_cmdData), l_cmdData);
            l_err = cmd.sendOccCmd();
            if (l_err != nullptr)
            {
                TMGT_ERR("setState: Failed to set OCC%d state, rc=0x%04X",
                         iv_instance, l_err->reasonCode());
            }
            else
            {
                if (OCC_RC_SUCCESS != cmd.getRspStatus())
                {
                    TMGT_ERR("setState: Set OCC%d state failed"
                             " with OCC status 0x%02X",
                             iv_instance, cmd.getRspStatus());
                    /*@
                     * @errortype
                     * @moduleid HTMGT_MOD_OCC_SET_STATE
                     * @reasoncode HTMGT_RC_OCC_CMD_FAIL
                     * @userdata1[0-31] OCC instance
                     * @userdata1[32-63] Requested state
                     * @userdata2[0-31] OCC response status
                     * @userdata2[32-63] current OCC state
                     * @devdesc Set of OCC state failed
                     * @custdesc An internal firmware error occurred
                     */
                    bldErrLog(l_err, HTMGT_MOD_OCC_SET_STATE,
                              HTMGT_RC_OCC_CMD_FAIL,
                              iv_instance, i_state,
                              cmd.getRspStatus(), iv_state,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }
            }
        }
        else
        {
            TMGT_ERR("setState: State only allowed to be set on master OCC");
            /*@
             * @errortype
             * @moduleid HTMGT_MOD_OCC_SET_STATE
             * @reasoncode HTMGT_RC_INTERNAL_ERROR
             * @userdata1  OCC instance
             * @userdata2  Requested state
             * @devdesc Set state only allowed on master OCC
             * @custdesc An internal firmware error occurred
             */
            bldErrLog(l_err, HTMGT_MOD_OCC_SET_STATE,
                      HTMGT_RC_INTERNAL_ERROR,
                      0, iv_instance, 0, i_state,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end Occ::setState()


    // Update master occsPresent bits for poll rsp validataion
    void Occ::updateOccPresentBits(uint8_t i_slavePresent)
    {
        if (iv_occsPresent & i_slavePresent)
        {
            // Flag error because multiple OCCs have same chip ID
            TMGT_ERR("updateOccPresentBits: slave 0x%02X already "
                     "exists (0x%02X)",
                     i_slavePresent, iv_occsPresent);
            iv_needsReset = true;
        }
        else
        {
            iv_occsPresent |= i_slavePresent;
        }
    };


    // Reset OCC
    bool Occ::resetPrep(bool i_skipComm)
    {
        errlHndl_t err = nullptr;
        bool atThreshold = false;

        TMGT_INF("resetPrep: OCC%d (failed=%c, reset count=%d)"
                 " reset reason=0x%x",
                 iv_instance,
                 iv_failed?'y':'n',
                 iv_resetCount,
                 iv_resetReason);

        if (iv_commEstablished && (i_skipComm == false))
        {
            // map HOMER for this OCC (for resetPrep command)
            TARGETING::Target* procTarget = nullptr;
            procTarget = TARGETING::
                getImmediateParentByAffinity(iv_target);
            HBPM::ScopedHomerMapper l_mapper(procTarget);
            err = l_mapper.map();
            if (nullptr == err)
            {
                // Send resetPrep command
                uint8_t cmdData[2] = { OCC_RESET_CMD_VERSION, OCC_RESET_FAIL_THIS_OCC };
                if((iv_resetReason == HTMGT::OCC_RESET_REASON_CODE_UPDATE) ||
                   (iv_resetReason == HTMGT::OCC_RESET_REASON_CANCEL_CODE_UPDATE))
                {
                    cmdData[1] = OCC_RESET_NON_FAILURE;
                }

                setHomerAddr(l_mapper.getHomerVirtAddr());

                OccCmd cmd(this, OCC_CMD_RESET_PREP, sizeof(cmdData), cmdData);
                err = cmd.sendOccCmd();
                if(err)
                {
                    // log error and keep going
                    TMGT_ERR("OCC::resetPrep: OCC%d resetPrep failed, rc=0x%04x",
                             iv_instance,
                             err->reasonCode());

                    ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                }

                // poll and flush error logs from OCC - Check Ex return code
                err = pollForErrors(true);
                if(err)
                {
                    ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                }

                invalidateHomer();
            }
            else
            {
                // Unable to send resetPrep command to this OCC,
                // just commit and proceed with reset
                TMGT_ERR("resetPrep: Unable to get HOMER virtual"
                         " address for OCC%d (rc=0x%04X)",
                         iv_instance, err->reasonCode());
                err->collectTrace(HTMGT_COMP_NAME);
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
            }
        }
        // else comm to OCC has not been established yet

        // Increment reset count (if failed)
        if(iv_failed)
        {
            ++iv_resetCount;
            TMGT_INF("resetPrep: OCC%d failed, incrementing reset count to %d",
                     iv_instance, iv_resetCount);
            if(iv_resetCount > OCC_RESET_COUNT_THRESHOLD)
            {
                atThreshold = true;
            }
        }
        else if( iv_needsWofReset ) //If WOF reset, increment count
        {
            iv_wofResetCount++;
            TMGT_INF("resetPrep(): WOF reset requested. Reset Count = %d",
                     iv_wofResetCount );
        }

        return atThreshold;
    }


    void Occ::postResetClear()
    {
        iv_state = OCC_STATE_UNKNOWN;
        iv_mode = POWERMODE_UNKNOWN;
        iv_commEstablished = false;
        iv_needsReset = false;
        iv_needsWofReset = false;
        iv_failed = false;
        iv_lastPollValid = false;
        iv_resetReason = OCC_RESET_REASON_NONE;
        iv_exceptionLogged = 0;
    }


    // Add channel 1 (circular buffer) SCOM data to elog
    void Occ::collectCheckpointScomData(errlHndl_t i_err)
    {
        if (i_err)
        {
            TARGETING::ConstTargetHandle_t procTarget =
                TARGETING::getParentChip(iv_target);
            ERRORLOG::ErrlUserDetailsLogRegister l_scom_data(procTarget);
            // Grab circular buffer scom data: (channel 1)
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C020));//OCB_OCI_IOSR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C024));//OCB_OCI_OIMR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C210));//OCB_OCI_OCBSLBR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C211));//OCB_OCI_OCBSLCS1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C213));//OCB_OCI_OCBSHBR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C214));//OCB_OCI_OCBSHCS1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C216));//OCB_OCI_OCBSES1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C218));//OCB_OCI_OCBLWCR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C21A));//OCB_OCI_OCBLWSR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6C21C));//*_OCI_OCBLWSBR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6D010));//OCB_PIB_OCBAR0
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6D030));//OCB_PIB_OCBAR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6D031));//OCB_PIB_OCBCSR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6D034));//OCB_PIB_OCBESR1
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6D050));//OCB_PIB_OCBAR2
            l_scom_data.addData(DEVICE_SCOM_ADDRESS(0x6D070));//OCB_PIB_OCBAR3

            l_scom_data.addToLog(i_err);
        }
        else
        {
            TMGT_ERR("collectCheckpointScomData: No error "
                     "handle supplied for OCC%d", iv_instance);
        }
    } // end Occ::collectCheckpointScomData()

    // Utility function to actually add trace buffer data
    void addOccTraceBuffer( errlHndl_t & io_errl,
                            TARGETING::Target * i_pOcc,
                            uint32_t i_address )
    {
        errlHndl_t l_errl = nullptr;

        uint8_t l_sramData[OCC_TRACE_BUFFER_SIZE];
        //Initialize to 0;
        memset(l_sramData, 0, OCC_TRACE_BUFFER_SIZE);

        l_errl = HBOCC::readSRAM(i_pOcc,
                          i_address,
                          reinterpret_cast<uint64_t*>(l_sramData),
                          OCC_TRACE_BUFFER_SIZE );

        if ( ( l_errl == nullptr ) &&
             ( l_sramData != 0 )   &&
             ( io_errl != nullptr ) )
        {
            // Strip off all but last 32 bytes of 00s
            uint32_t l_dataSize;

            // find first byte of data that is not 00s
            for( l_dataSize = OCC_TRACE_BUFFER_SIZE;
               ( l_dataSize > 32) && (l_sramData[l_dataSize-1] == 0x00);
               --l_dataSize);

            // pad 32 bytes
            l_dataSize += 32;
            if(l_dataSize > OCC_TRACE_BUFFER_SIZE)
            {
                l_dataSize = OCC_TRACE_BUFFER_SIZE;
            }

            // Add OCC trace buffer to error log
            io_errl->addFFDC( OCCC_COMP_ID,
                              l_sramData,
                              l_dataSize,
                              4, //version
                              0x02 );
#ifdef CONFIG_CONSOLE_OUTPUT_OCC_COMM
                    char header[64];
                    sprintf(header, "OCC Trace 0x%08X: (0x%04X bytes)",
                            i_address, l_dataSize);
                    dumpToConsole(header, (const uint8_t *)l_sramData,
                                  l_dataSize);
#endif

        }
        else
        {
            TMGT_ERR("addOccTraceBuffers: Unable to read OCC trace "
                    "buffer from SRAM address (0x%08X)",
                    i_address );
            if( l_errl != nullptr )
            {
                ERRORLOG::errlCommit(l_errl, HTMGT_COMP_ID);
            }
        }


    }

    void Occ::addOccTrace( errlHndl_t & io_errl )
    {
        // Add ERR trace buffer
        addOccTraceBuffer( io_errl,
                           iv_target,
                           OCC_TRACE_ERR );

        // Add IMP trace buffer
        addOccTraceBuffer( io_errl,
                           iv_target,
                           OCC_TRACE_IMP );

        // Add INF trace buffer
        addOccTraceBuffer( io_errl,
                           iv_target,
                           OCC_TRACE_INF );
    }

    // Set the homer virtual address for this OCC (required to send cmds)
    void Occ::setHomerAddr(const uint64_t i_homer_vaddress)
    {
        if (iv_homerValid)
        {
            TMGT_ERR("setHomerAddr(): HOMER was ALREADY VALID! 0x%08X", iv_homer);
        }
        // Get HOMER virtual address
        iv_homer = (uint8_t*)i_homer_vaddress;
        if (iv_homer != nullptr)
        {
            TMGT_INF("setHomerAddr(): 0x%08X", iv_homer);
            iv_homerValid = true;
        }
        else
        {
            TMGT_ERR("setHomerAddr(): HOMER virutal address was null!");
        }
    }

    // Invalidate the homer address for this OCC
    void Occ::invalidateHomer()
    {
        if (iv_homerValid)
        {
            TMGT_INF("invalidateHomer(): Clearing homer (0x%08X)", iv_homer);
            iv_homerValid = false;
        }
        iv_homer = nullptr;
    };


    // Notify HostBoot which GPUs are present (after OCC goes active)
    void Occ::updateGpuPresence()
    {
        // No GPUs are currently supported
    }


    // Notify BMC of OCC status
    errlHndl_t Occ::bmcSensor(const bool i_enabled, const bool i_safe)
    {
        errlHndl_t pError = nullptr;
#ifdef CONFIG_PLDM
        PLDM::occ_state new_state;
        if (i_enabled == true)
        {
            new_state = PLDM::occ_state_in_service;
        }
        else
        {
            if (i_safe)
            {
                new_state = PLDM::system_in_safe_mode;
            }
            else
            {
                new_state = PLDM::occ_state_stopped;
            }
        }

        pError = PLDM::sendOccStateChangedEvent(iv_target, new_state);
#endif
        return pError;
    }


} // end namespace
