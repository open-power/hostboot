/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/trustedbootif.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/**
 * @file trustedbootif.H
 *
 * @brief Trustedboot interfaces
 *
 */
#ifndef __TRUSTEDBOOTIF_H
#define __TRUSTEDBOOTIF_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <targeting/common/targetservice.H>
#include <i2c/tpmddif.H>
#include <errl/errlentry.H>
#include <list>

namespace TRUSTEDBOOT
{
    struct _TpmLogMgr;

    /// Track system TPM status
    struct TpmTarget
    {
        TARGETING::Target*      nodeTarget;     ///< Node target ptr
        TPMDD::tpm_chip_types_t chip;           ///< Chip Pri vs Backup
        uint8_t                 initAttempted:1;///< Has TPM init been run
        uint8_t                 available:1;    ///< Is TPM physically in system
        uint8_t                 failed:1;       ///< Is TPM currently failed
        struct _TpmLogMgr*      logMgr;         ///< Event log manager for TPM
        mutex_t                 tpmMutex;       ///< TPM Mutex

        TpmTarget();
    };

    /// TPM PCR designations
    typedef enum
    {
        PCR_0     = 0,
        PCR_1     = 1,
        PCR_4     = 4,
        PCR_5     = 5,
        PCR_6     = 6,
        PCR_DEBUG = 16,
        PLATFORM_PCR = 24, ///< The number of PCR required by the platform spec
        IMPLEMENTATION_PCR = 24, ///< The number of PCRs implemented by TPM
    } TPM_Pcr;


    /**
     * @brief Initialize trusted boot/TPM components for the master TPM
     *
     * @param[in] io_pArgs istep args
     *
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    void* host_update_master_tpm( void *io_pArgs );

    /**
     * @brief Extend a measurement into the TPMs and log atomically
     * @param[in] i_pcr PCR to write to
     * @param[in] i_digest Digest value to write to PCR
     * @param[in] i_digestSize Byte size of i_digest data
     * @param[in] i_logMsg Null terminated log message, truncated at 128 chars
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     * Digest will be right padded with zeros or truncated to match TPM digest
     *  size being used
     */
    errlHndl_t pcrExtend(TPM_Pcr i_pcr,
                         uint8_t* i_digest,
                         size_t  i_digestSize,
                         const char* i_logMsg);

    /**
     * @brief Return a set of information related to every unique
     *        functional TPM in the system
     *
     * @param[out] o_info - list of TPM Information
     *
     */
    void getTPMs( std::list<TpmTarget>& o_info );

    /**
     * @brief Retrieve TPM log device tree information
     * @param[in] i_target TPM target information
     * @param[in/out] io_logAddr TPM Log Address
     * @param[out] o_allocationSize Total memory allocated for log
     * @param[out] o_xscomAddr Chip Xscom Address
     * @param[out] o_i2cMasterOffset I2c Master Offset
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t getTpmLogDevtreeInfo(TpmTarget & i_target,
                                    uint64_t & io_logAddr,
                                    size_t & o_allocationSize,
                                    uint64_t & o_xscomAddr,
                                    uint32_t & o_i2cMasterOffset);

    /**
     * @brief Store devtree node information for the TPM
     * @param[in] i_target TPM target information
     * @param[in] i_xscomAddr Chip Xscom Address
     * @param[in] i_i2cMasterOffset i2c Master Offset
     */
    void setTpmDevtreeInfo(TpmTarget & i_target,
                           uint64_t i_xscomAddr,
                           uint32_t i_i2cMasterOffset);

    /**
     * @brief Is trustedboot enabled and functional
     * @retval true if trustboot enabled and functional TPM's are available
     */
    bool enabled();

} // end TRUSTEDBOOT namespace


#endif // __TRUSTEDBOOTIF_H
