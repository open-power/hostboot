/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbeioif.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2017                        */
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
#ifndef _SBEIOIF_H
#define _SBEIOIF_H

#include <errl/errlentry.H>

namespace SBEIO
{
    /**
     * @brief Start Deadman loop
     *
     * @param[in] i_waitTime Time to wait in milliseconds
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t startDeadmanLoop(const uint64_t i_waitTime );

    /**
     * @brief Stop Deadman loop
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t stopDeadmanLoop( );

    /**
    * @brief Semd System Configuration
    *
    * @param[in] i_systemConfig Fabric grouping map bitstring
    *                           Examples:
    *                           bit 0  = proc 0 group 0
    *                           bit 8  = proc 0 group 1
    *                           bit 12 = proc 4 group 1
    * @param[in] i_procChip     Proc you would like to send the config to
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSystemConfig(const uint64_t i_systemConfig,
                                TARGETING::Target * i_procChip);


    /**
    * @brief Send the signal to the sbe that we are performing a MPIPL
    *
    * @param[in] i_procChip The proc you would like to request continueMPIPL to
    *                       NOTE: HB should only be sending this to slave procs
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendContinueMpiplRequest(TARGETING::Target * i_procChip);

    /**
     * @brief Sends a PSU chipOp to quiesce the SBE
     *
     * @param[in]  i_target  Target with SBE to quiesce
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t sendPsuQuiesceSbe(TARGETING::Target * i_target);

    /**
    * @brief Sends a PSU chipOp to quiesce the SBE
    *
    * @param[in]  i_key   The key used to identify what the value is
    * @param[in]  i_value Value that will be passed (likely an address)
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuStashKeyAddrRequest(const uint8_t i_key,
                                          const uint64_t i_value);

    /**
     * @brief Get SCOM via SBE FIFO
     *
     * @param[in]  i_target  Target to access
     * @param[in]  i_addr    Requested register address
     * @param[out] o_data    Returned data
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t getFifoScom(TARGETING::Target * i_target,
                           uint64_t            i_addr,
                           uint64_t          & o_data);
    /**
     * @brief Put SCOM via SBE FIFO
     *
     * @param[in]  i_target  Target to access
     * @param[in]  i_addr    Requested register address
     * @param[in]  i_data    Data to write
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t putFifoScom(TARGETING::Target * i_target,
                           uint64_t            i_addr,
                           uint64_t            i_data);

    /**
     * @brief Put SCOM under mask via SBE FIFO
     *
     * @param[in]  i_target  Target to access
     * @param[in]  i_addr    Requested register address
     * @param[in]  i_data    Data to write
     * @param[in]  i_mask    SCOM mask
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t putFifoScomUnderMask(TARGETING::Target * i_target,
                                    uint64_t            i_addr,
                                    uint64_t            i_data,
                                    uint64_t            i_mask);

    /**
     * @brief Issue Reset to SBE FIFO.  Note this can ONLY be
     *        done on slave processors on FSI SBE FIFO path
     *        never on the master chip.  This function is
     *        only intended to be used to cleanup the FIFO
     *        on IPLs -- as it doesn't follow the protocol
     *        with a running SBE
     *
     *
     * @param[in]  i_target  Target to access
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t sendFifoReset(TARGETING::Target * i_target);

    /**
    * @brief Set the FFDC address for the SBE so it is aware of the FFDC buffer
    *        and its size and it is aware of the SBE Communication buffer and
    *        its size
    *
    * @param[in] i_sbeffdcSize uint32 Size of SBE FFDC buffer
    * @param[in] i_sbeCommSize uint32 Size of SBE Communication buffer
    * @param[in] i_sbeffdcAddr uint64 Physical mainstore address of FFDC buffer
    * @param[in] i_sbeCommAddr uint64 Physical mainstore address of Comm buffer
    * @param[in] i_procChip The proc to which you would like to send the info
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSetFFDCAddr(const uint32_t i_sbeffdcSize,
                               const uint32_t i_sbeCommSize,
                               const uint64_t i_sbeffdcAddr,
                               const uint64_t i_sbeCommAddr,
                               TARGETING::Target * i_procChip);

} //end namespace SBEIO

#endif /* _SBEIOIF_H */
