/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/trustedbootif.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <pnor/pnorif.H>
#include <secureboot/containerheader.H>

namespace TRUSTEDBOOT
{
    struct _TpmLogMgr;

    /// Enumerations to select TPM
    typedef enum
    {
        TPM_PRIMARY   = 0,
        TPM_BACKUP    = 1,
        LAST_CHIP_TYPE,
        FIRST_CHIP_TYPE = TPM_PRIMARY
    } TPM_role;


    /// Track system TPM status
    struct TpmTarget
    {
        TARGETING::Target*      tpmTarget;      ///< TPM target ptr
        TPM_role                role;           ///< Pri vs Backup
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
        PCR_2     = 2,
        PCR_3     = 3,
        PCR_4     = 4,
        PCR_5     = 5,
        PCR_6     = 6,
        PCR_7     = 7,
        PCR_DEBUG = 16,
        PCR_DRTM_17 = 17,
        PCR_DRTM_18 = 18,
        PCR_DRTM_19 = 19,
        PCR_DRTM_20 = 20,
        PCR_DRTM_21 = 21,
        PCR_DRTM_22 = 22,
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
     * @param[in] i_sendAsync Perform extension asynchronously, default true
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     * Digest will be right padded with zeros or truncated to match TPM digest
     *  size being used
     */
    errlHndl_t pcrExtend(TPM_Pcr i_pcr,
                         const uint8_t* i_digest,
                         size_t  i_digestSize,
                         const char* i_logMsg,
                         bool i_sendAsync = true);

    /**
     * @brief Extend a separator into the TPMs and log atomically
     * @param[in] i_sendAsync Perform extension asynchronously, default true
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t pcrExtendSeparator(bool i_sendAsync = true);

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

    /**
     * @brief Wrapper around pcrExtend for measuring PNOR sections
     * @param[in] i_conHdr  Reference to ContainerHeader of a section
     * @param[in] i_vaddr   Pointer to a virtual address for the protected
     *                      portion of the PNOR section.
     *                      [Not used if SECUREBOOT::enabled()]
     * @param[in] i_sec     Section ID of PNOR section
     * @return errlHndl_t NULL if successful, otherwise a pointer to the
     *      error log.
     */
    errlHndl_t extendPnorSectionHash(const SECUREBOOT::ContainerHeader& i_conHdr,
                                     const void* i_vaddr,
                                     const PNOR::SectionId i_sec);

    /**
     *
     *  @brief Extends the Hostboot base image to the TPM
     *
     *  @warning No-op if trusted boot compiled out
     *
     *  @return errHndl_t Error log pointer
     *  @retval NULL  Successfully extended Hostboot base image to the TPM
     *  @retval !NULL Failed to extend Hostboot base image to TPM
     *                                     */
    errlHndl_t extendBaseImage();

} // end TRUSTEDBOOT namespace


#endif // __TRUSTEDBOOTIF_H
