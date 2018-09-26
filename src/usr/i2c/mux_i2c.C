/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/mux_i2c.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2018                        */
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
 * @file mux_i2c.C
 *
 * @brief I2C MUX utility functions
 *
 */

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "mux_i2c.H"

// -----------------------------------------------------------------------------
// Trace definitions
// -----------------------------------------------------------------------------
extern trace_desc_t* g_trac_i2c;

namespace MUX_I2C
{

using namespace TARGETING;

// Register the presence detect for the I2C MUX
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::PRESENT,
                       TARGETING::TYPE_I2C_MUX,
                       i2cMuxPresenceDetect );


// ------------------------------------------------------------------
// i2cMuxPresenceDetect
// ------------------------------------------------------------------
errlHndl_t i2cMuxPresenceDetect(DeviceFW::OperationType i_opType,
                                TargetHandle_t          i_target,
                                void*   io_isPresentBuffer,
                                size_t& io_isPresentBufferSize,
                                int64_t i_accessType,
                                va_list i_args)
{
    TRACDCOMP(g_trac_i2c, ENTER_MRK"i2cMuxPresenceDetect()");

    // Always return true
    bool l_present = true;
    memcpy(io_isPresentBuffer, &l_present, sizeof(l_present));
    io_isPresentBufferSize = sizeof(l_present);

    TRACDCOMP(g_trac_i2c, EXIT_MRK"i2cMuxPresenceDetect()");

    return nullptr;
}


}  // namespace MUX_I2C
