/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_pldmdd.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef __PNOR_PLDMDD_H
#define __PNOR_PLDMDD_H

/** @file pnor_pldmdd.H
 *  @brief Provides the interfaces to the PNOR PLDM Device Driver
 */

#include "pnorif.H"

namespace PNOR
{
class UdPnorDDParms;
}
/**
 *  @brief  PNOR PLDM Device Driver Class
 *     Provides access to the PNOR lids on the BMC via the LPC hardware using
 *     the PLDM protocol over a MCTP binding interface. See DSP0241_1.0.0
 *     for more details.
 */
class PnorPldmDD : public PnorIf
{

public:
    PnorPldmDD(TARGETING::Target* i_target = nullptr);
    ~PnorPldmDD();

    errlHndl_t readFlash(void* o_buffer,
                                 size_t& io_buflen,
                                 uint64_t i_address);

    errlHndl_t writeFlash(const void* i_buffer,
                                  size_t& io_buflen,
                                  uint64_t i_address);

    uint32_t getNorSize(void);
    uint32_t getNorWorkarounds(void);

  protected:

    /**
     * @brief Write data to PNOR using one or more PLDM File I/O request(s)
     * @pre Mutex should already be locked before calling
     *
     * @parm[in] i_addr  PNOR flash Address to write
     * @parm[in,out] io_size  Amount of data to write, in bytes.
     * @parm[in] i_data  Buffer containing data to write
     *
     * @return Error from operation
     */
    errlHndl_t _writeFlash( uint64_t i_addr,
                            size_t &io_size,
                            const void* i_data );

    /**
     * @brief Read data from PNOR using Mbox LPC windows
     * @pre Mutex should already be locked before calling
     *
     * @parm[in] i_addr  PNOR flash Address to read
     * @parm[in,out] io_size  Amount of data to read, in bytes.
     * @parm[out] o_data  Buffer to read data into
     *
     * @return Error from operation
     */
    errlHndl_t _readFlash( uint64_t i_addr,
                           size_t &io_size,
                           void* o_data );

private:
    /**
     * @brief Global Mutex to prevent concurrent PNOR accesses to Master
     *        Proc. This needs to be static so we can mutex across multiple
     *        instances of PnorPldmDD
     */
    static mutex_t cv_mutex;

    /**
     * @brief Class Mutex used to prevent concurrent PNOR accesses
     */
    mutex_t iv_mutex;

    /**
     * @brief Mutex pointer to either class-specific or global mutex to
     *        prevent concurrent PNOR accesses.
     *        Each class uses a mutex; some share the static cv_mutex
     */
    mutex_t* iv_mutex_ptr;

    /**
     * @brief Processor Target, currently not really used, but adding
     *        to be consistent with other PNOR device drivers.
     */
    TARGETING::Target* iv_target;

    // Needed for testcases
    friend class PnorDdTest;

    // let the UserDetails classes see internal structures
    friend class PNOR::UdPnorDDParms;
};


#endif
