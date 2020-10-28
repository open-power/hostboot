/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scom/scomif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#ifndef __SCOMIF_H
#define __SCOMIF_H

#include <devicefw/driverif.H>

namespace SCOM
{

/**
 * @brief This function translates a relative scom address
 *        to an absolute scom address
 *
 * @param[in]           i_target         SCom target
 * @param[in|out]       io_addr          SCom address
 * @param[out]          o_needsWakeup    Enable SW before scom
 * @param[in]           i_opMode         Defaults to 0 (Standard)
 * @return              errlHndl_t
 */
errlHndl_t scomTranslate(TARGETING::Target * &i_target,
                         uint64_t & io_addr,
                         bool & o_needsWakeup,
                         uint64_t i_opMode = 0);

/**
 * @brief Common routine that verifies input parameters for *scom accesses.
 *
 * @param[in]   i_opType       Operation type, see driverif.H
 * @param[in]   i_target       Scom target
 * @param[in]   i_buffer       Read: Pointer to output data storage
 *                             Write: Pointer to input data storage
 * @param[in]   i_buflen       Input: size of io_buffer (in bytes)
 * @param[in]   i_addr         Address being accessed (Used for FFDC)
 * @return  errlHndl_t
 */
errlHndl_t scomOpSanityCheck(const DeviceFW::OperationType i_opType,
                             const TARGETING::Target* i_target,
                             const void* i_buffer,
                             const size_t i_buflen,
                             const uint64_t i_addr,
                             const size_t i_minbufsize);

/**
 * @brief Check if accessing a slave processor via FSI2SPI SCOM mode
 *
 * @param[in] i_target        Scom target
 * @param[in] i_scom_address  Address for FSI scom
 * @return true if accessing slave processor via FSI2SPI, else false
 */
bool scomCheckIfFsiSpiAddress( const TARGETING::Target * i_target,
                               const uint64_t i_scom_address );

/* @brief Check whether SCOM value tracing should be blocked/disabled for the
 *        current thread.
 *
 * @note  For debug purposes, some SCOM handlers print the value read or written
 *        by a particular SCOM operation. But certain SCOM registers contain
 *        sensitive information (e.g. cryptographic keys) that should not be
 *        traced. This interface allows code to temporarily disable SCOM value
 *        tracing on the current thread to avoid leaking this sensitive data.
 *
 * @note  This only applies to XSCOM operations right now but may be supported by
 *        other SCOM interfaces in the future.
 *
 * @return bool  True if SCOM value tracing should be blocked/disabled, false
 *               if it should be allowed.
 */
inline bool shouldBlockScomValueTrace()
{
    extern thread_local size_t block_scom_value_trace;
    return block_scom_value_trace > 0;
}

/* @brief Enable or disable sensitive SCOM value tracing on the current thread.
 *
 * @note  See shouldBlockScomValueTrace for more information.
 *
 * @note  Each call to block tracing should be balanced by a call to unblock
 *        tracing.
 *
 * @param[in] i_block  True to block SCOM value tracing, false otherwise.
 */
void setBlockScomValueTrace(bool i_block);

#ifndef __HOSTBOOT_RUNTIME
/**
 * @brief Enable scoms to all cores for multicast workaround
 */
void enableSlaveCoreMulticast( void );

/**
 * @brief Enable scoms to the memory chiplets for multicast workaround
 */
void enableMemChipletMulticast( void );
#endif

};  // end namespace SCOM

#endif  // end __SCOMIF_H
