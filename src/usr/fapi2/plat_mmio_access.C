/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_mmio_access.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
 * @file plat_mmio_access.C
 *
 * @brief Implements FAPI mmio functions at the platform layer.
 */

#include <stdint.h>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <return_code.H>
#include <target.H>
#include <target_types.H>
#include <plat_utils.H>
#include <attribute_service.H>
#include <hwpf_fapi2_reasoncodes.H>
#include <fapi2/plat_mmio_access.H>


namespace fapi2
{
//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

/// @brief Platform-level implementation of getMMIO()
///        Reads data via MMIO from the target
ReturnCode platGetMMIO( const Target<TARGET_TYPE_ALL>& i_target,
                        const uint64_t i_mmioAddr,
                        const size_t i_transSize,
                        std::vector<uint8_t>& o_data )
{
    ReturnCode l_rc;
    errlHndl_t l_err = nullptr;

    FAPI_DBG(ENTER_MRK "platGetMMIO");

    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_mmio_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    size_t l_get_size = o_data.size();

    // create a temporary buffer for read data
    uint8_t * l_data_read = new uint8_t[ l_get_size ];

    do
    {
        // Extract the component pointer
        TARGETING::Target * l_target = nullptr;
        l_err = fapi2::platAttrSvc::getTargetingTarget(i_target, l_target);
        if ( l_err )
        {
            FAPI_ERR( "platGetMMIO: Error from getTargetingTarget on %s",
                      l_targName );
            break; //return with error
        }

        // call MMIO driver
        l_err = DeviceFW::deviceRead(l_target,
                               l_data_read,
                               l_get_size,
                               DEVICE_MMIO_ADDRESS(i_mmioAddr, i_transSize));

        if (l_traceit)
        {
            // Only trace the first 8 bytes of data read
            // (don't want to overflow trace buffer)
            uint64_t l_traceDataRead = 0;
            if (l_get_size >= sizeof(l_traceDataRead))
            {
              memcpy(&l_traceDataRead, l_data_read, sizeof(l_traceDataRead));
            }
            else if (l_get_size > 0)
            {
              memcpy(&l_traceDataRead, l_data_read, l_get_size);
            }
            FAPI_SCAN("TRACE : getMMIO  :  %s %d - %d %.16llX",
                      l_targName,
                      o_data.size(),
                      l_get_size,
                      l_traceDataRead);
        }

    } while(0);

    if (l_err)
    {
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }
    else
    {
        // read was successful so copy data into o_data
        o_data.clear();
        o_data.insert( o_data.end(),
                       &l_data_read[0],
                       &l_data_read[l_get_size] );
    }
    delete [] l_data_read;

    FAPI_DBG(EXIT_MRK "platGetMMIO");
    return l_rc;
}


/// @brief Platform-level implementation of putMMIO()
///        Writes data via MMIO to the target
ReturnCode platPutMMIO( const Target<TARGET_TYPE_ALL>& i_target,
                        const uint64_t i_mmioAddr,
                        const size_t i_transSize,
                        const std::vector<uint8_t>& i_data )
{
    ReturnCode l_rc;
    errlHndl_t l_err = nullptr;
    uint8_t * l_writeDataPtr;

    FAPI_DBG(ENTER_MRK "platPutMMIO");

    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_mmio_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));

    do {
        // Extract the component pointer
        TARGETING::Target * l_target = nullptr;
        l_err = fapi2::platAttrSvc::getTargetingTarget(i_target, l_target);
        if (l_err)
        {
            FAPI_ERR( "platPutMMIO: Error from getTargetingTarget on %s",
                      l_targName );
            break; //return with error
        }

        //copy data from const vector to data ptr
        l_writeDataPtr = new uint8_t[ i_data.size() ];
        std::copy(i_data.begin(), i_data.end(), l_writeDataPtr);
        size_t l_dataSize = i_data.size();

        // call MMIO driver
        l_err = DeviceFW::deviceWrite(l_target,
                                l_writeDataPtr,
                                l_dataSize,
                                DEVICE_MMIO_ADDRESS(i_mmioAddr, i_transSize));
        if (l_traceit)
        {
            // trace the first 8 bytes of written data
            // (avoid trace buffer overflow)
            uint64_t traceWriteData = 0;
            if (l_dataSize > sizeof(traceWriteData))
            {
                // copy what will fit into traceWriteData variable
                memcpy(&traceWriteData, l_writeDataPtr, sizeof(traceWriteData));
            }
            else
            {
                memcpy(&traceWriteData, l_writeDataPtr, l_dataSize);
            }
            FAPI_SCAN( "TRACE : putMMIO    :  %s : %d %.16llX",
                       l_targName,
                       l_dataSize,
                       traceWriteData );
        }

        delete [] l_writeDataPtr;

    } while (0);

    if (l_err)
    {
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    FAPI_DBG(EXIT_MRK "platPutMMIO");
    return l_rc;
}

} // End namespace
