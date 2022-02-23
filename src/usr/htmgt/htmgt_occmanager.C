/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occmanager.C $                            */
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
#include "htmgt_occ.H"
#include "htmgt_occmanager.H"
#include "htmgt_cfgdata.H"

#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <console/consoleif.H>
#include <sys/time.h>
#include <isteps/pm/occAccess.H>
#include <isteps/pm/pm_common_ext.H>
#include <isteps/pm/scopedHomerMapper.H>
#include <targeting/common/mfgFlagAccessors.H>

#include <targeting/common/mfgFlagAccessors.H>
#include "htmgt_cfgdata.H"

namespace HTMGT
{

    uint32_t OccManager::cv_safeReturnCode = 0;
    uint32_t OccManager::cv_safeOccInstance = 0;


    OccManager::OccManager()
        :iv_occMaster(nullptr),
        iv_state(OCC_STATE_UNKNOWN),
        iv_targetState(OCC_STATE_ACTIVE),
        iv_sysResetCount(0),
        iv_occsAreRunning(false)
    {
    }


    OccManager::~OccManager()
    {
        _removeAllOccs();
    }


    // Remove all OCC objects
    void OccManager::_removeAllOccs()
    {
        iv_occsAreRunning = false;
        iv_occMaster = nullptr;
        if (iv_occArray.size() > 0)
        {
            for( const auto & occ : iv_occArray )
            {
                TMGT_INF("removeAllOccs: Removing OCC%d",
                         occ->getInstance());
                delete occ;
            }
            iv_occArray.clear();
        }
    }


    // Query the functional OCCs and build OCC objects
    errlHndl_t OccManager::_buildOccs(const bool i_occStart,
                                      const bool i_skipComm)
    {
        errlHndl_t err = nullptr;
        bool safeModeNeeded = false;
        TMGT_INF("_buildOccs called");

        // Only build OCC objects once.
        if((iv_occArray.size() > 0) && (iv_occMaster != nullptr))
        {
            TMGT_INF("_buildOccs: Existing OCC Targets kept = %d",
                     iv_occArray.size());
            return err;
        }

        // Remove existing OCC objects
        _removeAllOccs();

        if (TARGETING::is_phyp_load())
        {
            TMGT_INF("_buildOccs: PHYP/PowerVM system");
            G_system_type = OCC_CFGDATA_OPENPOWER_POWERVM;
        }
        else
        {
            TMGT_INF("_buildOccs: OPAL system");
            G_system_type = OCC_CFGDATA_OPENPOWER_OPALVM;
        }

        // Get all functional processors
        TARGETING::TargetHandleList pProcs;
        TARGETING::getChipResources(pProcs,
                                    TARGETING::TYPE_PROC,
                                    TARGETING::UTIL_FILTER_FUNCTIONAL);
        if (pProcs.size() > 0)
        {
            // for each functional processor
            for(const auto & proc : pProcs )
            {
                // Instance number for this Processor/OCC
                const uint8_t instance =
                    proc->getAttr<TARGETING::ATTR_POSITION>();
                TMGT_INF("_buildOccs: PROC%d is functional", instance);

                // Check HOMER addresses
                uint8_t * homer = nullptr;
                HBPM::ScopedHomerMapper l_mapper(proc);
                err = l_mapper.map();
                if (nullptr == err)
                {
                    // Save the HOMER virtual address
                    homer =
                        reinterpret_cast<uint8_t*>(l_mapper.getHomerVirtAddr());
                }
                else
                {
                    err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                }
                TMGT_INF("_buildOccs: Proc%d homer = 0x%08llX",
                         instance, homer);

                if (nullptr != homer)
                {
                    // Get functional OCC (one per proc)
                    TARGETING::TargetHandleList occs;
                    getChildChiplets(occs, proc, TARGETING::TYPE_OCC);
                    if (occs.size() > 0)
                    {
                        const unsigned long huid =
                            occs[0]->getAttr<TARGETING::ATTR_HUID>();
                        const bool masterCapable =
                            occs[0]->
                            getAttr<TARGETING::ATTR_OCC_MASTER_CAPABLE>();

                        TMGT_INF("_buildOccs: Found OCC%d - HUID: 0x%0lX, "
                                 "masterCapable: %c, homer: 0x%0lX",
                                 instance, huid, masterCapable?'Y':'N',
                                 homer);
                        _addOcc(instance, masterCapable, homer, occs[0]);
                    }
                    else
                    {
                        // OCC must not be functional
                        TMGT_ERR("_buildOccs: OCC%d not functional", instance);
                    }
                }
                else
                {
                    // OCC will not be functional with no HOMER address
                    TMGT_ERR("_buildOccs: HOMER address for OCC%d is nullptr!",
                             instance);
                    if (nullptr == err)
                    {
                        /*@
                         * @errortype
                         * @moduleid HTMGT_MOD_BUILD_OCCS
                         * @reasoncode HTMGT_RC_OCC_CRIT_FAILURE
                         * @userdata1  OCC Instance
                         * @userdata2  homer virtual address
                         * @devdesc Homer pointer is nullptr, unable to
                         *          communicate with the OCCs.
                         *          Leaving system in safe mode.
                         */
                        bldErrLog(err,
                                  HTMGT_MOD_BUILD_OCCS,
                                  HTMGT_RC_OCC_CRIT_FAILURE,
                                  0, instance,
                                  (uint64_t)homer>>32,
                                  (uint64_t)homer&0xFFFFFFFF,
                                  ERRORLOG::ERRL_SEV_UNRECOVERABLE1);
                    }
                    else
                    {
                        err->collectTrace(HTMGT_COMP_NAME);
                    }
                    safeModeNeeded = true;
                    iv_occMaster = nullptr;
                    break;
                }

            } // for each processor

            if (nullptr != iv_occMaster)
            {
                // update master occsPresent bit for each slave OCC
                for( const auto & occ : iv_occArray )
                {
                    if(occ != iv_occMaster)
                    {
                        iv_occMaster->
                            updateOccPresentBits(occ->getPresentBits());
                    }
                }
            }

        }
        else
        {
            TMGT_ERR("_buildOccs: No functional processors found");
        }

        if (0 == _getNumOccs())
        {
            TMGT_ERR("_buildOccs: Unable to find any functional OCCs");
            if (nullptr == err)
            {
                /*@
                 * @errortype
                 * @reasoncode      HTMGT_RC_OCC_UNAVAILABLE
                 * @moduleid        HTMGT_MOD_BUILD_OCCS
                 * @userdata1       functional processor count
                 * @devdesc         No functional OCCs were found
                 */
                bldErrLog(err, HTMGT_MOD_BUILD_OCCS,
                          HTMGT_RC_OCC_UNAVAILABLE,
                          0, pProcs.size(), 0, 0,
                          ERRORLOG::ERRL_SEV_UNRECOVERABLE);
            }
            safeModeNeeded = true;
        }

        if ((false == i_occStart) && (nullptr == err) &&
            (false == i_skipComm))
        {
            // Send poll to query state of all OCCs
            // and flush any errors reported by the OCCs
            err = sendOccPoll(true);
            if (err)
            {
                TMGT_ERR("_buildOccs: Poll all OCCs failed");
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
            }
            _syncOccStates();
        }

        if (safeModeNeeded)
        {
            // Clear OCC enabled sensors
            errlHndl_t err2 = setOccEnabledSensors(false);
            if (err2)
            {
                TMGT_ERR("_buildOccs: Set OCC enabled sensors to false failed");
                ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
            }

            // Reset all OCCs
            TMGT_INF("_buildOccs: Calling HBPM::resetPMAll");
            err2 = HBPM::resetPMAll();
            if (nullptr != err2)
            {
                TMGT_ERR("_buildOccs: HBPM::resetPMAll failed with rc 0x%04X",
                         err2->reasonCode());
                err2->collectTrace(HTMGT_COMP_NAME);
                ERRORLOG::errlCommit(err2, HTMGT_COMP_ID);
            }

            updateForSafeMode(err);
        }

        TMGT_INF("_buildOccs: OCC Targets found = %d", _getNumOccs());

        return err;

    } // end OccManager::_buildOccs()



    // Add a functional OCC to be monitored
    void OccManager::_addOcc(const uint8_t   i_instance,
                             const bool      i_masterCapable,
                             uint8_t       * i_homer,
                             TARGETING::TargetHandle_t i_target)
    {
        TMGT_INF("addOcc(%d, masterCapable=%c)",
                 i_instance, i_masterCapable?'y':'n');

        occRole role = OCC_ROLE_SLAVE;
        if (true == i_masterCapable)
        {
            if (nullptr == iv_occMaster)
            {
                // No master assigned yet, use this OCC
                TMGT_INF("addOcc: OCC%d will be the master", i_instance);
                role = OCC_ROLE_MASTER;
            }
            else
            {
                role = OCC_ROLE_BACKUP_MASTER;
            }
        }

        Occ * l_occ = new Occ(i_instance,
                              i_masterCapable,
                              i_homer,
                              i_target,
                              role);

        // Add OCC to the array
        iv_occArray.push_back(l_occ);

        if (OCC_ROLE_MASTER == role)
        {
            iv_occMaster = l_occ;
        }

    } // end OccManager::_addOcc()


    // Get pointer to specified OCC
    Occ * OccManager::_getOcc(const uint8_t i_instance)
    {
        Occ *targetOcc = nullptr;
        for( const auto & occ : iv_occArray )
        {
            if (occ->getInstance() == i_instance)
            {
                targetOcc = occ;
                break;
            }
        }

        return targetOcc;

    } // eng OccManager::_getOcc()


    // Set the OCC state
    errlHndl_t OccManager::_setOccState(const occStateId i_state)
    {
        errlHndl_t l_err = nullptr;

        occStateId requestedState = i_state;
        if (OCC_STATE_NO_CHANGE == i_state)
        {
            // If no state was requested use the target state
            requestedState = iv_targetState;
        }

        if ((requestedState == OCC_STATE_ACTIVE) ||
            (requestedState == OCC_STATE_OBSERVATION) ||
            (requestedState == OCC_STATE_CHARACTERIZATION) )
        {
            // Function is only called on initial IPL and when user/mfg
            // requests a new state, so we can update target here.
            iv_targetState = requestedState;

            l_err = _buildOccs(); // if not already built.
            if (nullptr == l_err)
            {
                // Poll all OCCs to confirm comm has been established.
                // Flush old errors to ensure any new errors will be collected
                l_err = _sendOccPoll(true, nullptr);
                if (l_err)
                {
                    TMGT_ERR("_setOccState: Poll OCCs failed.");
                    // Proceed with reset even if failed
                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                }

                if (nullptr != iv_occMaster)
                {
                    TMGT_INF("_setOccState(state=0x%02X)", requestedState);
                    // map HOMER for this OCC
                    TARGETING::Target* procTarget = nullptr;
                    procTarget = TARGETING::
                        getImmediateParentByAffinity(iv_occMaster->getTarget());
                    HBPM::ScopedHomerMapper l_mapper(procTarget);
                    l_err = l_mapper.map();
                    if (nullptr == l_err)
                    {
                        iv_occMaster->setHomerAddr(l_mapper.getHomerVirtAddr());

                        const uint8_t occInstance = iv_occMaster->getInstance();
                        bool needsRetry = false;
                        do
                        {
                            l_err = iv_occMaster->setState(requestedState);
                            if (nullptr == l_err)
                            {
                                needsRetry = false;
                            }
                            else
                            {
                                TMGT_ERR("_setOccState: Failed to set OCC%d "
                                         "state, rc=0x%04X",
                                         occInstance, l_err->reasonCode());
                                if (false == needsRetry)
                                {
                                    ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                                    needsRetry = true;
                                }
                                else
                                {
                                    // Only one retry, return error handle
                                    needsRetry = false;
                                }
                            }
                        }
                        while (needsRetry);
                        iv_occMaster->invalidateHomer();
                    }
                    else
                    {
                        TMGT_ERR("_setOccState: Unable to get HOMER virtual "
                                 "address for Master OCC (rc=0x%04X)",
                                 l_err->reasonCode());
                        l_err->collectTrace(HTMGT_COMP_NAME);
                        l_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE);
                    }
                }
                else
                {
                    /*@
                     * @errortype
                     * @moduleid HTMGT_MOD_OCCMGR_SET_STATE
                     * @reasoncode HTMGT_RC_INTERNAL_ERROR
                     * @devdesc Unable to set state of master OCC
                     */
                    bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_STATE,
                              HTMGT_RC_INTERNAL_ERROR,
                              0, 0, 0, 0,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }

                if (nullptr == l_err)
                {
                    // Send poll to query state of all OCCs
                    // and flush any errors reported by the OCCs
                    l_err = sendOccPoll(true);
                    if (l_err)
                    {
                        TMGT_ERR("_setOccState: Poll all OCCs failed");
                        ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    }

                    // Make sure all OCCs went to active state
                    for( const auto & occ : iv_occArray )
                    {
                        if (requestedState == occ->getState())
                        {
                            // Update GPU present status
                            occ->updateGpuPresence();
                        }
                        else
                        {
                            TMGT_ERR("_setOccState: OCC%d is not in 0x%02X "
                                     "state",
                                     occ->getInstance(), requestedState);
                            /*@
                             * @errortype
                             * @moduleid HTMGT_MOD_OCCMGR_SET_STATE
                             * @reasoncode HTMGT_RC_OCC_UNEXPECTED_STATE
                             * @userdata1[0-31] requested state
                             * @userdata1[32-63] OCC state
                             * @userdata2 OCC instance
                             * @devdesc OCC did not change to requested state
                             */
                            bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_STATE,
                                      HTMGT_RC_OCC_UNEXPECTED_STATE,
                                      requestedState, occ->getState(),
                                      0, occ->getInstance(),
                                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
                            break;
                        }
                    }

                    if (nullptr == l_err)
                    {
                        // Clear safe mode reason since OCC is at target state
                        if (cv_safeReturnCode != 0)
                        {
                            TMGT_INF("_setOccState: clearing safe mode reason "
                                     "(0x%04X)", cv_safeReturnCode);
                            cv_safeReturnCode = 0;
                            cv_safeOccInstance = 0;
                        }
                        TMGT_INF("_setOccState: All OCCs have reached state "
                                 "0x%02X", requestedState);
                        iv_state = requestedState;

                        if (OCC_STATE_ACTIVE == requestedState)
                        {
                            TMGT_CONSOLE("OCCs are now running in ACTIVE "
                                         "state");
                        }
                        else if (OCC_STATE_OBSERVATION == requestedState)
                        {
                            TMGT_CONSOLE("OCCs are now running in OBSERVATION "
                                         "state");
                        }
                        else if (OCC_STATE_CHARACTERIZATION == requestedState)
                        {
                            TMGT_CONSOLE("OCCs are now running in "
                                         "CHARACTERIZATION state");
                        }

                        // TODO - Remove default in RTC 209567
                        if (iv_occMaster->getMode() == POWERMODE_UNKNOWN)
                        {
                            // Set default mode
                            TMGT_INF("_setOccState: Setting power mode to "
                                     "Maximum Performance (default)");
                            l_err = _setMode(POWERMODE_MAX_PERF, 0);
                        }
                    }
                }
            }
        }
        else
        {
            TMGT_ERR("_setOccState: Invalid state 0x%02X requested",
                     requestedState);
            /*@
             * @errortype
             * @moduleid HTMGT_MOD_OCCMGR_SET_STATE
             * @reasoncode HTMGT_RC_INVALID_DATA
             * @userdata1 requested state
             * @devdesc Invalid OCC state requested
             */
            bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_STATE,
                      HTMGT_RC_INVALID_DATA,
                      0, requestedState, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;

    } // end OccManager::_setOccState()


    errlHndl_t OccManager::_resetOccs(TARGETING::Target * i_failedOccTarget,
                                      bool i_skipCountIncrement,
                                      bool i_skipComm,
                                      enum occResetReason i_reason)
    {
        errlHndl_t err = nullptr;
        bool atThreshold = false;

        iv_occsAreRunning = false;

        err = _buildOccs(false, i_skipComm); // if not a already built.
        if (nullptr == err)
        {
            if (false == int_flags_set(FLAG_RESET_DISABLED))
            {
                err = setOccEnabledSensors(false); // Set OCC sensor to inactive
                if( err )
                {
                    TMGT_ERR("_resetOccs: Set OCC enabled sensors to false failed");
                    // log and continue
                    ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                }

                // Create info log indicating that the OCCs are getting reset
                /*@
                 * @errortype
                 * @moduleid HTMGT_MOD_OCC_RESET
                 * @reasoncode HTMGT_RC_OCC_RESET
                 * @userdata1  reset reason | safe src
                 * @userdata2  safe instance | huid
                 * @devdesc OCCs will be reset
                 */
                uint32_t l_huid = 0;
                if (i_failedOccTarget)
                {
                    l_huid = TARGETING::get_huid(i_failedOccTarget);
                }
                bldErrLog(err,
                          HTMGT_MOD_OCC_RESET,
                          HTMGT_RC_OCC_RESET,
                          i_reason, cv_safeReturnCode,
                          cv_safeOccInstance, l_huid,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL);
                ERRORLOG::errlCommit(err, HTMGT_COMP_ID);

                if (false == i_skipComm)
                {
                    // Send poll cmd to all OCCs
                    err = _sendOccPoll(false, // don't flush errors
                                       nullptr, // send to all OCCs
                                       true); // only poll if communications
                    // has been established
                    if (err)
                    {
                        TMGT_ERR("_resetOccs: Poll OCCs failed.");
                        // Proceed with reset even if failed
                        ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                    }
                }

                for(const auto & occ : iv_occArray )
                {
                    if (i_reason != OCC_RESET_REASON_NONE)
                    {
                        occ->iv_resetReason = i_reason;
                    }
                    if ((i_reason != HTMGT::OCC_RESET_REASON_CODE_UPDATE) &&
                        (i_reason != HTMGT::OCC_RESET_REASON_CANCEL_CODE_UPDATE))
                    {
                        if(occ->getTarget() == i_failedOccTarget)
                        {
                            occ->failed(true);
                        }
                    }

                    if (false == i_skipComm)
                    {
                        // map HOMER for this OCC (for resetPrep command)
                        TARGETING::Target* procTarget = nullptr;
                        procTarget = TARGETING::
                            getImmediateParentByAffinity(occ->getTarget());
                        HBPM::ScopedHomerMapper l_mapper(procTarget);
                        err = l_mapper.map();
                        if (nullptr == err)
                        {
                            occ->setHomerAddr(l_mapper.getHomerVirtAddr());

                            // Send reset prep cmd to each OCCs
                            if(occ->resetPrep())
                            {
                                atThreshold = true;
                            }

                            occ->invalidateHomer();
                        }
                        else
                        {
                            // Unable to send resetPrep command to this OCC,
                            // just commit and proceed with reset
                            TMGT_ERR("_resetOccs: Unable to get HOMER virtual"
                                     " address for OCC%d (rc=0x%04X)",
                                     occ->getInstance(), err->reasonCode());
                            err->collectTrace(HTMGT_COMP_NAME);
                            ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                        }
                    }
                    // If we need a WOF reset, skip system count increment
                    if( occ->needsWofReset() )
                    {
                        i_skipCountIncrement = true;
                    }
                }

                if((i_reason == HTMGT::OCC_RESET_REASON_CODE_UPDATE) ||
                        (i_reason == HTMGT::OCC_RESET_REASON_CANCEL_CODE_UPDATE))
                {
                    i_skipCountIncrement = true;
                }

                if ((false == i_skipCountIncrement) && (false == _occFailed()))
                {
                    // No OCC has been marked failed, increment sys reset count
                    ++iv_sysResetCount;

                    TMGT_INF("_resetOCCs: Incrementing system OCC reset count"
                             " to %d", iv_sysResetCount);

                    if(iv_sysResetCount > OCC_RESET_COUNT_THRESHOLD)
                    {
                        atThreshold = true;
                    }
                }
                // else failed OCC reset count will be incremented automatically

                // Update OCC states to RESET
                for( const auto & occ : iv_occArray )
                {
                    occ->iv_state = OCC_STATE_RESET;
                }

                uint64_t retryCount = OCC_RESET_COUNT_THRESHOLD;
                TARGETING::Target* sys = nullptr;
                TARGETING::targetService().getTopLevelTarget(sys);
                while(retryCount)
                {
                    if (sys)
                    {
                        // Increment cumulative reset count since boot
                        uint8_t count = sys->getAttr<TARGETING::
                            ATTR_CUMULATIVE_PMCOMPLEX_RESET_COUNT>();
                        if (count < 0xFF)
                        {
                            ++count;
                            sys->setAttr<TARGETING::
                                ATTR_CUMULATIVE_PMCOMPLEX_RESET_COUNT>(count);
                        }
                    }

                    // Reset all OCCs
                    TMGT_INF("_resetOccs: Calling HBPM::resetPMAll");
                    err = HBPM::resetPMAll();
                    if(!err)
                    {
                        break;
                    }
                    --retryCount;

                    if (int_flags_set(FLAG_HALT_ON_RESET_FAIL))
                    {
                        TMGT_ERR("_resetOCCs: resetPMAll failed with 0x%04X "
                                 "and HALT_ON_RESET_FAIL is set.  Resets will "
                                 "be disabled", err->reasonCode());
                        set_int_flags(get_int_flags() | FLAG_RESET_DISABLED);
                        break;
                    }

                    if(retryCount)
                    {
                        // log if not last retry
                        err->collectTrace(HTMGT_COMP_NAME);
                        ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                    }
                    else
                    {
                        TMGT_ERR("_resetOCCs: HBPM::resetPMAll failed. "
                                 "Leaving OCCs in reset state");
                        // pass err handle back
                        err->collectTrace(HTMGT_COMP_NAME);
                    }
                }

                if(!atThreshold && !err)
                {
                    for( const auto & occ : iv_occArray )
                    {
                        // After OCC has been reset, clear internal flags
                        occ->postResetClear();
                    }

                    // Don't restart OCC's on CODE UPDATE
                    if(i_reason != HTMGT::OCC_RESET_REASON_CODE_UPDATE )
                    {

                        //get parent proc chip.
                        TARGETING::Target* l_proc_target = NULL;

                        //Reload OCC on this processor chip.
                        TMGT_INF("_resetOccs: Calling loadAndStartPMAll");
                        err = HBPM::loadAndStartPMAll(HBPM::PM_RELOAD,
                                                      l_proc_target);
                        if(err)
                        {
                            TMGT_ERR("_resetOCCs: loadAndStartPMAll failed. ");
                            err->collectTrace(HTMGT_COMP_NAME);
                            processOccStartStatus(false, l_proc_target);
                        }
                        else
                        {
                            processOccStartStatus(true, l_proc_target);
                        }
                    }
                    else
                    {
                        TMGT_INF("_resetOccs: OCC load being skipped due to code update");

                        // Update OCC states to RESET (vs UNKNOWN)
                        for( const auto & occ : iv_occArray )
                        {
                            occ->iv_state = OCC_STATE_RESET;
                        }
                        iv_state = OCC_STATE_RESET;
                    }
                }
                else if (!err) // Reset Threshold reached and no other err
                {
                    // Create threshold error
                    TMGT_ERR("_resetOCCs: Retry Threshold reached. "
                             "Leaving OCCs in reset state");
                    /*@
                     * @errortype
                     * @moduleid HTMGT_MOD_OCC_RESET
                     * @reasoncode HTMGT_RC_OCC_CRIT_FAILURE
                     * @userdata1  return code triggering safe mode
                     * @userdata2  OCC instance
                     * @devdesc OCC reset threshold reached.
                     *          Leaving OCCs in reset state
                     */
                    bldErrLog(err,
                              HTMGT_MOD_OCC_RESET,
                              HTMGT_RC_OCC_CRIT_FAILURE,
                              0, cv_safeReturnCode, 0, cv_safeOccInstance,
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE1);

                    TMGT_ERR("_resetOccs: Safe Mode (RC: 0x%04X OCC%d)",
                             cv_safeReturnCode, cv_safeOccInstance);

                    // Check if OCC already logged reason for safe mode
                    // (add proc callout if non-OCC safe mode reason or
                    //  the OCC hit an exception)
                    if (((cv_safeReturnCode & OCCC_COMP_ID) != OCCC_COMP_ID) ||
                        ((cv_safeReturnCode & 0xE0) == 0xE0))
                    {
                        // Add processor callout
                        TARGETING::ConstTargetHandle_t procTarget = nullptr;
                        Occ *occPtr = _getOcc(cv_safeOccInstance);
                        if (occPtr != nullptr)
                        {
                            procTarget =
                                TARGETING::getParentChip(occPtr->getTarget());
                        }
                        else
                        {
                            TMGT_ERR("_resetOCCs: Unable to determine target, "
                                     "using first proc");
                            // Get all functional processors
                            TARGETING::TargetHandleList pProcs;
                            TARGETING::getChipResources(pProcs,
                                                        TARGETING::TYPE_PROC,
                                             TARGETING::UTIL_FILTER_FUNCTIONAL);
                            procTarget = pProcs[0];
                        }
                        if (nullptr != procTarget)
                        {
                            const unsigned long huid =
                                procTarget->getAttr<TARGETING::ATTR_HUID>();
                            TMGT_ERR("_resetOCCs: Adding processor callout "
                                     "(HUID=0x%0lX)", huid);
                            err->addHwCallout(procTarget,
                                              HWAS::SRCI_PRIORITY_MED,
                                              HWAS::NO_DECONFIG,
                                              HWAS::GARD_NULL);
                        }
                    }
                    else
                    {
                        TMGT_INF("_resetOccs: OCC should have already logged "
                                 "an error for safe mode");
                    }
                }

                // Any error at this point means OCCs were not reactivated
                if(err)
                {
                    // PM Complex reset/load calls are recursive.
                    // If the inital resetOcc call(s) return an error,
                    // that error can be ignored IF the OCCs were
                    // actually enabled successfully in later recursive calls.
                    // Check if OCCs are now active/running
                    if (OccManager::occsAreRunning())
                    {
                        const uint16_t l_rc = err->reasonCode();
                        // prior reset worked - commit original error as info
                        err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                        ERRORLOG::errlCommit(err, HTMGT_COMP_ID);
                        TMGT_INF("_resetOccs: OCC failed to go "
                                 "active after reset with 0x%04X, but recovery "
                                 "was successful", l_rc);

                        // Clear safe reason since recovery was successful.
                        OccManager::updateSafeModeReason(0, 0);
                        // Clear system safe mode flag/attribute
                        if(sys)
                        {
                            const uint8_t safeMode = 0;
                            sys->setAttr<TARGETING::ATTR_HTMGT_SAFEMODE>
                                (safeMode);
                        }
                    }
                    else
                    {
                        updateForSafeMode(err);
                    }
                }
            }
            else
            {
                TMGT_INF("_resetOccs: Skipping OCC reset due to "
                         "internal flags 0x%08X", get_int_flags());
            }
        }

        return err;

    } // end OccManager::_resetOccs()


    void OccManager::updateForSafeMode(errlHndl_t & io_err)
    {
        io_err->setSev(ERRORLOG::ERRL_SEV_UNRECOVERABLE1);

        // Add level 2 support callout
        io_err->addProcedureCallout(HWAS::EPUB_PRC_LVL_SUPP,
                                    HWAS::SRCI_PRIORITY_MED);
        // Add HB firmware callout
        io_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_MED);

        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);
        const uint8_t safeMode = 1;

        // Mark system as being in safe mode
        if(sys)
        {
            sys->setAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
        }
        iv_state = OCC_STATE_SAFE;

        _updateSafeModeReason(io_err->reasonCode(), 0);

        TMGT_ERR("updateForSafeMode: Safe Mode (RC: 0x%04X OCC%d)",
                 cv_safeReturnCode, cv_safeOccInstance);

        TMGT_CONSOLE("OCCs are not active. The system will remain in "
                     "safe mode (RC: 0x%04x  for OCC%d)",
                     cv_safeReturnCode,
                     cv_safeOccInstance);

        // Iterate through OCC objects to notify the BMC
        for( const auto & occ : iv_occArray )
        {
            // Notify BMC that this OCC is not active and system is in safe mode
            errlHndl_t l_err = occ->bmcSensor(false, true);
            if( l_err )
            {
                TMGT_ERR("updateForSafeMode: failed setting occEnabled sensor"
                         " for safe mode (OCC%d)",
                         occ->getInstance());
                l_err->collectTrace(HTMGT_COMP_NAME);
                l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
            }
        }

    } // end  OccManager::updateForSafeMode()


    // Wait for all OCCs to reach communications checkpoint
    errlHndl_t OccManager::_waitForOccCheckpoint()
    {
        errlHndl_t checkpointElog = nullptr;
#ifdef CONFIG_HTMGT
        // Wait up to 15 seconds for all OCCs to be ready (150 * 100ms = 15s)
        const size_t NS_BETWEEN_READ = 100 * NS_PER_MSEC;
        const size_t READ_RETRY_LIMIT = 150;

        if (iv_occArray.size() > 0)
        {
            uint8_t retryCount = 0;
            bool throttleErrors = false;

            for( const auto & occ : iv_occArray )
            {
                bool occReady = false;
                uint16_t lastCheckpoint = 0x0000;

                while ((!occReady) && (retryCount++ < READ_RETRY_LIMIT))
                {
                    nanosleep(0, NS_BETWEEN_READ);

                    TARGETING::ConstTargetHandle_t procTarget =
                        TARGETING::getParentChip(occ->getTarget() );

                    // Read SRAM response buffer to check for OCC checkpoint
                    errlHndl_t l_err = nullptr;
                    const uint16_t l_length = 8;  //Note: number of bytes
                    uint8_t l_sram_data[l_length] = { 0x0 };
                    l_err = HBOCC::readSRAM(procTarget,
                                            OCC_RSP_SRAM_ADDR,
                                            (uint64_t*)(&(l_sram_data)),
                                            l_length);

                    if (nullptr == l_err)
                    {
                        // Pull status from response (byte 2)
                        uint8_t status = l_sram_data[2];

                        // Pull checkpoint from response (byte 6-7)
                        uint16_t checkpoint= l_sram_data[6]<<8 | l_sram_data[7];

                        if (checkpoint != lastCheckpoint)
                        {
                            TMGT_INF("_waitForOccCheckpoint: OCC%d Checkpoint "
                                     "0x%04X",
                                     occ->getInstance(), checkpoint);
                            lastCheckpoint = checkpoint;
                        }
                        if ( ( OCC_RC_OCC_INIT_CHECKPOINT == status ) &&
                             ( OCC_COMM_INIT_COMPLETE == checkpoint) )
                        {
                            TMGT_INF("_waitForOccCheckpoint OCC%d ready!",
                                     occ->getInstance());

                            occReady = true;
                            break;
                        }
                        if( ((checkpoint & OCC_INIT_FAILURE ) ==
                                        OCC_INIT_FAILURE ) ||
                            ( status == OCC_RC_INIT_FAILURE ) )
                        {
                            TMGT_ERR("_waitForOccCheckpoint: OCC%d failed "
                                    "during initialization (0x%02X, 0x%04X)",
                                    occ->getInstance(),
                                    status,
                                    checkpoint );

                           occReady = false;
                           break;
                        }
                    }
                    else
                    {
                        if (false == throttleErrors)
                        {
                            throttleErrors = true;
                            TMGT_ERR("_waitForOccCheckpoint: error trying to "
                                     "read OCC%d SRAM (rc=0x%04X)",
                                     occ->getInstance(),
                                     l_err->reasonCode());
                            ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                        }
                        else
                        {
                            delete l_err;
                            l_err = nullptr;
                        }
                    }
                }

                if (!occReady)
                {
                    TMGT_CONSOLE("Final OCC%d Checkpoint NOT reached (0x%04X)",
                                 occ->getInstance(), lastCheckpoint);
                    TMGT_ERR("_waitForOccCheckpoint OCC%d still NOT ready! "
                             "(last checkpoint=0x%04X)",
                             occ->getInstance(), lastCheckpoint);
                    errlHndl_t l_err = nullptr;
                    /*@
                     * @errortype
                     * @moduleid HTMGT_MOD_WAIT_FOR_CHECKPOINT
                     * @reasoncode HTMGT_RC_OCC_NOT_READY
                     * @userdata1 OCC instance
                     * @userdata2 last OCC checkpoint
                     * @devdesc Set of OCC state failed
                     */
                    bldErrLog(l_err, HTMGT_MOD_WAIT_FOR_CHECKPOINT,
                              HTMGT_RC_OCC_NOT_READY,
                              0, occ->getInstance(), 0, lastCheckpoint,
                              ERRORLOG::ERRL_SEV_PREDICTIVE);

                    occ->collectCheckpointScomData( l_err );
                    occ->addOccTrace( l_err );

                    if (nullptr == checkpointElog)
                    {
                        // return the first elog
                        checkpointElog = l_err;
                        l_err = nullptr;
                    }
                    else
                    {
                        ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    }
                    TMGT_ERR("waitForOccCheckpoint OCC%d still NOT ready!",
                             occ->getInstance());
                    break;
                }
            }
        }
#endif
        return checkpointElog;
    }


    void OccManager::_updateSafeModeReason(uint32_t i_src,
                                           uint32_t i_instance)
    {
        if ((cv_safeReturnCode == 0) ||
            ((i_src == 0) && (i_instance == 0)))
        {
            // Only update safe mode reason for the first failure,
            // or if trying to clear safe mode
            cv_safeReturnCode = i_src;
            cv_safeOccInstance = i_instance;
        }
    }


    uint32_t OccManager::_getSafeModeReason(uint32_t & o_instance)
    {
        o_instance = cv_safeOccInstance;
        return cv_safeReturnCode;
    }


    bool OccManager::_occNeedsReset()
    {
        bool needsReset = false;

        for( const auto & occ : iv_occArray )
        {
            if (occ->needsReset() || occ->needsWofReset())
            {
                needsReset = true;
                break;
            }
        }

        return needsReset;
    }

    // Return true if any OCC has been marked as failed
    bool OccManager::_occFailed()
    {
        bool failed = false;

        for( const auto & occ : iv_occArray )
        {
            if (occ->iv_failed)
            {
                failed = true;
                break;
            }
        }

        return failed;
    }


    // Collect HTMGT Status Information for debug
    // NOTE: o_data is pointer to OCC_MAX_DATA_LENGTH byte buffer
    // Error parser is in: src/usr/htmgt/plugins/ebmc/b2600.py
    // Some tools use older parser: src/usr/htmgt/plugins/errludP_htmgt.H
    void OccManager::_getHtmgtData(uint16_t & o_length, uint8_t *o_data)
    {
        uint16_t index = 0;

        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;
        uint8_t resets_since_boot = 0;
        if (sys)
        {
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
            sys->tryGetAttr<TARGETING::ATTR_CUMULATIVE_PMCOMPLEX_RESET_COUNT>
                (resets_since_boot);
        }
        // First add HTMGT specific data
        o_data[index++] = _getNumOccs();
        o_data[index++] =
            (nullptr!=iv_occMaster)?iv_occMaster->getInstance():0xFF;
        o_data[index++] = iv_state;
        o_data[index++] = iv_targetState;
        o_data[index++] = iv_sysResetCount;
        o_data[index++] = resets_since_boot;
        const uint16_t modeIndex = index++;
        o_data[modeIndex] = iv_mode;
        o_data[index++] = safeMode;
        UINT32_PUT(&o_data[index], cv_safeReturnCode);
        index += 4;
        UINT32_PUT(&o_data[index], cv_safeOccInstance);
        index += 4;

        // Now add OCC specific data (for each OCC)
        for( const auto & occ : iv_occArray )
        {
            o_data[index++] = occ->getInstance();
            o_data[index++] = occ->getState();
            o_data[index++] = occ->getRole();
            o_data[index++] = occ->iv_masterCapable;
            o_data[index++] = occ->iv_commEstablished;
            o_data[index++] = occ->iv_mode;
            if (iv_mode != occ->iv_mode)
            {
                // BMC probably updated mode, use new mode
                TMGT_INF("_getHtmgtData: OCC%d has mode 0x%02X (vs HTMGT: 0x%02X)",
                         occ->getInstance(), occ->iv_mode, iv_mode);
                iv_mode = occ->iv_mode;
                o_data[modeIndex] = iv_mode;
            }
            o_data[index++] = 0; // reserved for expansion
            o_data[index++] = 0; // reserved for expansion
            o_data[index++] = occ->iv_failed;
            o_data[index++] = occ->needsReset();
            o_data[index++] = occ->iv_resetReason;
            o_data[index++] = (occ->iv_wofResetCount<<4)|occ->iv_resetCount;
            if (occ->iv_lastPollValid)
            {
                memcpy(&o_data[index], occ->iv_lastPollResponse, 4);
            }
            else
            {
                memset(&o_data[index], 0xFF, 4);
            }
            index += 4;
        }

        o_length = index;
    }

    // Get WOF Reset reasons for all OCCs
    // NOTE: Data returned is of the form [ 1-byte ID | 4-byte bit vector]
    //       per OCC instance found
    void OccManager::_getWOFResetReasons(uint16_t & o_length,
                                         uint8_t * o_data)
    {
        uint16_t index = 0;

        // Make sure OCCs were built first (so data is valid)
        errlHndl_t l_err = _buildOccs(); // if not already built.
        if( l_err )
        {
            TMGT_ERR("_getWOFResetReasons: Failed to build OCC structures "
                     "rc=0x%04X", l_err->reasonCode());
            ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
        }

        // Iterate through OCC objects to get bit vectors.
        for( const auto & occ : iv_occArray )
        {
            o_data[index++] = occ->getInstance();
            UINT32_PUT(&o_data[index], occ->getWofResetReasons());
            index += 4;
        }

        o_length = index;
    }


    // Consolidate all OCC states
    void OccManager::_syncOccStates()
    {
        occStateId currentState = OCC_STATE_NO_CHANGE;

        for(const auto & occ : iv_occArray )
        {
            if (OCC_STATE_NO_CHANGE == currentState)
            {
                currentState = occ->getState();
            }
            else
            {
                if (currentState != occ->getState())
                {
                    // States do not match yet...
                    currentState = OCC_STATE_NO_CHANGE;
                    break;
                }
            }
        }
        if (OCC_STATE_NO_CHANGE != currentState)
        {
            if (iv_state != currentState)
            {
                TMGT_INF("_syncOccStates: All OCCs are in 0x%02X",
                         currentState);
                iv_state = currentState;
            }
        }
    }


    // Clear all OCC reset counts
    // Should not be called if the system is in safe mode.
    void OccManager::_clearResetCounts(const bool i_periodicClear)
    {
        for( const auto & occ : iv_occArray )
        {
            if (occ->iv_resetCount != 0)
            {
                TMGT_INF("_clearResetCounts: Clearing OCC%d reset count "
                         "(was %d)",
                         occ->getInstance(),
                         occ->iv_resetCount);
                occ->iv_resetCount = 0;
            }

            // Don't clear WOF reset counts if WOF was disabled.
            // This will prevent WOF from being re-enabled until next boot.
            // Manual/user requested clears will clear all reset counts.
            if ( (occ->iv_wofResetCount > 0) &&
                 ((i_periodicClear == false) ||
                  (occ->iv_wofResetCount < WOF_RESET_COUNT_THRESHOLD)) )
            {
                TMGT_INF("_clearResetCounts: Clearing OCC%d WOF reset count "
                         "(was %d) reason(s): 0x%08X",
                         occ->getInstance(),
                         occ->iv_wofResetCount,
                         occ->iv_wofResetReasons);
                occ->iv_wofResetCount = 0;
            }
        }

        if (iv_sysResetCount != 0)
        {
            TMGT_INF("_clearResetCounts: Clearing system reset count "
                     "(was %d)", iv_sysResetCount);
            iv_sysResetCount = 0;
        }
    }


    uint8_t OccManager::_validateOccsPresent(const uint8_t i_present,
                                             const uint8_t i_instance)
    {
        uint8_t l_dup_instance = 0xFF; // no duplicate found
        for( const auto & occ : iv_occArray )
        {
            if ((occ->getInstance() != i_instance) &&
                (occ->getPresentBits() != 0) &&
                (occ->getPresentBits() == i_present))

            {
                l_dup_instance = occ->getInstance();
                break;

            }
        }
        return l_dup_instance;
    }


    errlHndl_t OccManager::_setMode(const uint8_t  i_mode,
                                    const uint16_t i_freq)
    {
        errlHndl_t l_err = nullptr;

        if (nullptr != iv_occMaster)
        {
            // map HOMER for this OCC
            TARGETING::Target* procTarget = nullptr;
            procTarget = TARGETING::
                getImmediateParentByAffinity(iv_occMaster->getTarget());
            HBPM::ScopedHomerMapper l_mapper(procTarget);
            l_err = l_mapper.map();
            if (nullptr == l_err)
            {
                iv_occMaster->setHomerAddr(l_mapper.getHomerVirtAddr());
                l_err = iv_occMaster->setMode(i_mode, i_freq);
                if (nullptr == l_err)
                {
                    // Send poll to query state/mode of all OCCs
                    // and flush any errors reported by the OCCs
                    l_err = sendOccPoll(true);
                    if (l_err)
                    {
                        TMGT_ERR("_setMode: Poll all OCCs failed");
                        ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
                    }

                    // Make sure all OCCs went to requested mode
                    for( const auto & occ : iv_occArray )
                    {
                        if (occ->getMode() != i_mode)
                        {
                            TMGT_ERR("_setMode: OCC%d is not in mode "
                                     "0x%02X", occ->getInstance(), i_mode);
                            iv_mode = POWERMODE_UNKNOWN;
                            /*@
                             * @errortype
                             * @moduleid HTMGT_MOD_OCCMGR_SET_MODE
                             * @reasoncode HTMGT_RC_OCC_UNEXPECTED_MODE
                             * @userdata1[0-31]  OCC mode
                             * @userdata1[32-47] requested mode
                             * @userdata1[48-63] SFP/FFO freq point
                             * @userdata2[0-31]  OCC state
                             * @userdata2[32-63] OCC instance
                             * @devdesc Mismatched OCC mode
                             */
                            bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_MODE,
                                      HTMGT_RC_OCC_UNEXPECTED_MODE,
                                      occ->getMode(),
                                      (i_mode << 16) | (i_freq),
                                      occ->getState(),
                                      occ->getInstance(),
                                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
                            break;
                        }
                    }

                    TMGT_INF("_setMode: All OCCs are in mode 0x%02X", i_mode);
                    iv_mode = (powerMode)i_mode;
                    iv_freqPoint = i_freq;
                }
                iv_occMaster->invalidateHomer();
            }
            else
            {
                // Unable to send resetPrep command to this OCC,
                // just commit and proceed with reset
                TMGT_ERR("_setMode: Unable to get HOMER virtual"
                         " address for OCC%d (rc=0x%04X)",
                         iv_occMaster->getInstance(), l_err->reasonCode());
                l_err->collectTrace(HTMGT_COMP_NAME);
            }
        }
        else
        {
            /*@
             * @errortype
             * @moduleid HTMGT_MOD_OCCMGR_SET_MODE
             * @reasoncode HTMGT_RC_INTERNAL_ERROR
             * @devdesc Master OCC is not defined
             * @userdata1  requested power mode
             * @userdata2  requested frequency for SPF or FFO
             */
            bldErrLog(l_err, HTMGT_MOD_OCCMGR_SET_MODE,
                      HTMGT_RC_INTERNAL_ERROR,
                      i_mode, i_freq, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        return l_err;
    }


    // Collect Mode and Function Capabilities
    // NOTE: o_data is pointer to OCC_MAX_DATA_LENGTH byte buffer
    errlHndl_t OccManager::_queryModeAndFunction(uint16_t & o_length,
                                                 uint8_t *o_data)
    {
        errlHndl_t l_err = nullptr;
        uint16_t index = 0;

        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget(sys);
        uint8_t safeMode = 0;
        uint8_t resets_since_boot = 0;
        if (sys)
        {
            sys->tryGetAttr<TARGETING::ATTR_HTMGT_SAFEMODE>(safeMode);
            sys->tryGetAttr<TARGETING::ATTR_CUMULATIVE_PMCOMPLEX_RESET_COUNT>
                (resets_since_boot);
        }
        // First add HTMGT specific data
        if (safeMode)
            o_data[index++] = POWERMODE_SAFE; // currentPwrMode
        else
            o_data[index++] = 1; // currentPwrMode = NORMAL
        o_data[index++] = iv_mode;  // custRequestedMode
        o_data[index++] = iv_mode;  // currentVoltSetting
        o_data[index++] = iv_state;
        o_data[index++] = 0; // EnableHFTrading
        uint16_t l_freq = 0;
        if ((iv_mode == POWERMODE_SFP) || (iv_mode == POWERMODE_FFO))
            l_freq = iv_freqPoint;
        o_data[index++] = (l_freq >> 8); // DesiredFrequency (FFO/SFP)
        o_data[index++] = (l_freq & 0xFF);
        // currEmpathFunct
        if (safeMode)
            o_data[index++] = 0; // .occStatus = DISABLED
        else
            o_data[index++] = 1; // .occStatus = ACTIVE
        o_data[index++] = 1; // .powerSave
        o_data[index++] = 1; // .powerCap
        o_data[index++] = 0; // reserved
        o_data[index++] = 1; // .dynamicPerformance
        o_data[index++] = 1; // .FFO
        o_data[index++] = 0; // reserved (IPS)
        o_data[index++] = 1; // .maxPerformance
        o_data[index++] = 0; // reserved
        o_data[index++] = 0; // reserved
        o_data[index++] = 0; // reserved
        o_data[index++] = 0; // reserved
        bool is_mfg = isMfgFlagSet(TARGETING::
                                   MFG_FLAGS_MNFG_ENERGYSCALE_SPECIAL_POLICIES);
        o_data[index++] = is_mfg ? 1 : 0; // .mfgMode

        UINT32_PUT(&o_data[index], cv_safeReturnCode);
        index += 4;
        UINT32_PUT(&o_data[index], cv_safeOccInstance);
        index += 4;

        o_length = index;

        return l_err;
    }

    // ---------- public interfaces ---------- //


    uint8_t  OccManager::getNumOccs()
    {
        return Singleton<OccManager>::instance()._getNumOccs();
    }


    std::vector<Occ*> OccManager::getOccArray()
    {
        return Singleton<OccManager>::instance()._getOccArray();
    }


    errlHndl_t OccManager::buildOccs(const bool i_occStart, bool i_skipComm)
    {
        return Singleton<OccManager>::instance()._buildOccs(i_occStart,
                                                                    i_skipComm);
    }


    Occ * OccManager::getMasterOcc()
    {
        return Singleton<OccManager>::instance()._getMasterOcc();
    }


    Occ * OccManager::getOcc(const uint8_t i_instance)
    {
        return Singleton<OccManager>::instance()._getOcc(i_instance);
    }


    errlHndl_t OccManager::setOccState(const occStateId i_state)
    {
        return Singleton<OccManager>::instance()._setOccState(i_state);
    }


    errlHndl_t OccManager::resetOccs(TARGETING::Target * i_failedOccTarget,
                                     bool i_skipCountIncrement,
                                     bool i_skipComm,
                                     enum occResetReason i_reason)
    {
        return
            Singleton<OccManager>::instance()._resetOccs(i_failedOccTarget,
                                                         i_skipCountIncrement,
                                                         i_skipComm,
                                                         i_reason);
    }


    occStateId OccManager::getState()
    {
        return Singleton<OccManager>::instance()._getState();
    }


    occStateId OccManager::getTargetState()
    {
        return Singleton<OccManager>::instance()._getTargetState();
    }


    errlHndl_t OccManager::waitForOccCheckpoint()
    {
        return Singleton<OccManager>::instance()._waitForOccCheckpoint();
    }

    void OccManager::updateSafeModeReason(uint32_t i_src,
                                          uint32_t i_instance)
    {
        Singleton<OccManager>::instance().
            _updateSafeModeReason(i_src, i_instance);
    }

    uint32_t OccManager::getSafeModeReason(uint32_t & o_instance)
    {
        return Singleton<OccManager>::instance().
            _getSafeModeReason(o_instance);
    }

    bool OccManager::occNeedsReset()
    {
        return Singleton<OccManager>::instance()._occNeedsReset();
    }

    bool OccManager::occFailed()
    {
        return Singleton<OccManager>::instance()._occFailed();
    }

    void OccManager::getHtmgtData(uint16_t & o_length, uint8_t *o_data)
    {
        Singleton<OccManager>::instance()._getHtmgtData(o_length, o_data);
    }

    void OccManager::getWOFResetReasons(uint16_t & o_length, uint8_t * o_data)
    {
        Singleton<OccManager>::instance()._getWOFResetReasons(o_length,
                                                              o_data);
    }

    void OccManager::syncOccStates()
    {
        Singleton<OccManager>::instance()._syncOccStates();
    }

    void OccManager::clearResetCounts(const bool i_periodicClear)
    {
        Singleton<OccManager>::instance()._clearResetCounts(i_periodicClear);
    }

    uint8_t OccManager::validateOccsPresent(const uint8_t i_present,
                                            const uint8_t i_instance)
    {
        return Singleton<OccManager>::instance()._validateOccsPresent(i_present,
                                                                    i_instance);
    }

    errlHndl_t OccManager::setMode(const uint8_t  i_mode,
                                   const uint16_t i_freq)
    {
        return Singleton<OccManager>::instance()._setMode(i_mode, i_freq);
    }

    errlHndl_t OccManager::queryModeAndFunction(uint16_t & o_length, uint8_t *o_data)
    {
        return Singleton<OccManager>::instance()._queryModeAndFunction(o_length, o_data);
    }

    bool OccManager::occsAreRunning()
    {
        return Singleton<OccManager>::instance()._occsAreRunning();
    }

    void OccManager::setOccsAreRunning(const bool i_running)
    {
        return Singleton<OccManager>::instance()._setOccsAreRunning(i_running);
    }

} // end namespace
