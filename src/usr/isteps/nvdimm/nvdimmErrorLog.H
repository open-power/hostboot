/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimmErrorLog.H $                      */
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

#ifndef NVDIMM_ERROR_LOG_H__
#define NVDIMM_ERROR_LOG_H__

#include <usr/errl/errlentry.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <i2c/eepromif.H>
#include <map>
#include "nvdimmdd.H"
#include "nvdimm.H"

using namespace TARGETING;
using namespace EEPROM;

// Trace definition
extern trace_desc_t* g_trac_nvdimm;

namespace NVDIMM
{

/**
 * @brief Function to read and save status registers for traces
 *
 * @param[in] i_nvdimm - nvdimm target with NV controller
 *
 * @param[out] o_RegInfo - the structure holding the register data
 *
 */
void nvdimmTraceRegs(Target *i_nvdimm, nvdimm_reg_t& o_RegInfo);

/**
 * @brief Helper function for standard callout of an NVDIMM
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[out] o_err - error log handler to be modified
 *
 * @return bool - true to commit log and continue, false to return
 *      the error log to caller and exit.
 */
bool nvdimmCalloutDimm(Target *i_nvdimm, uint8_t i_step, errlHndl_t& o_err);

/**
 * @brief Helper function for BPM/Cable high, NVDIMM low callout
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[out] o_err - error log handler to be modified
 *
 * @return bool - true to commit log and continue, false to return
 *      the error log to caller and exit.
 */
bool nvdimmBPMCableCallout(Target *i_nvdimm, uint8_t i_step, errlHndl_t& o_err);

/**
 * @brief Helper function for BPM high, NVDIMM low callout
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[out] o_err - error log handler to be modified
 *
 * @return bool - true to commit log and continue, false to return
 *      the error log to caller and exit.
 */
bool nvdimmBPMCallout(Target *i_nvdimm, uint8_t i_step, errlHndl_t& o_err);

/**
 * @brief Function checking the Health Status Registers for an nvdimm
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[out] o_exit - bool to signify exit procedure
 *
 * @return errlHndl_t - Null if successful, otherwise a pointer to
 *      the error log.
 */
errlHndl_t nvdimmHealthStatusCheck(Target *i_nvdimm, uint8_t i_step, bool& o_continue);

/**
 * @brief Read fw revision info and save into error log
 *
 * @param[in] i_nvdimm - nvdimm target
 *
 * @param[in] i_errhdl - pointer to error log, data will be saved here if not null
 */
void nvdimmReadFwLevels(Target *i_nvdimm, errlHndl_t i_errhdl);

} //End NVDIMM namespace


#endif  // NVDIMM_ERROR_LOG_H__
