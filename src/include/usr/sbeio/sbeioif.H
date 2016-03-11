/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbeioif.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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

} //end namespace SBEIO

#endif /* _SBEIOIF_H */
