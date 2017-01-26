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
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendSystemConfig(const uint64_t i_systemConfig );

    /**
    * @brief Sends a PSU chipOp to quiesce the SBE
    *
    * @return errlHndl_t Error log handle on failure.
    *
    */
    errlHndl_t sendPsuQueisceSbeCmd ();

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

} //end namespace SBEIO

#endif /* _SBEIOIF_H */
