/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/plat_i2c_access.C $                             */
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
 * @file plat_i2c_access.C
 *
 * @brief Implements FAPI i2c functions at the platform layer.
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
#include <fapi2/plat_i2c_access.H>



namespace fapi2
{

//------------------------------------------------------------------------------
// HW Communication Functions to be implemented at the platform layer.
//------------------------------------------------------------------------------

/// @brief Platform-level implementation called by FAPI getI2c()
ReturnCode platGetI2c( const Target<TARGET_TYPE_ALL>& i_target,
                       const size_t i_get_size,
                       const std::vector<uint8_t>& i_cfgData,
                       std::vector<uint8_t>& o_data )
{
    ReturnCode l_rc;
    errlHndl_t l_err = nullptr;

    FAPI_DBG(ENTER_MRK "platGetI2c");
    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_i2c_access.H
    bool l_traceit = platIsScanTraceEnabled();

    // Grab the name of the target
    TARGETING::ATTR_FAPI_NAME_type l_targName = {0};
    fapi2::toString(i_target, l_targName, sizeof(l_targName));


    size_t l_get_size = i_get_size;  // need non-const

    // create a temporary buffer for read data
    uint8_t * l_data_read = new uint8_t[ l_get_size ];

    do
    {
        // Extract the component pointer
        TARGETING::Target * l_target = nullptr;
        l_err = fapi2::platAttrSvc::getTargetingTarget(i_target, l_target);
        if ( l_err )
        {
            FAPI_ERR( "platGetI2c: Error from getTargetingTarget on %s",
                      l_targName );
            break; //return with error
        }

        // Perform i2c read
        uint64_t l_traceCfgData = 0;

        if ( i_cfgData.empty() )
        {
            l_err = deviceRead(
                                l_target,
                                l_data_read,
                                l_get_size,
                                DEVICE_FAPI_I2C_ADDRESS()
                              );
        }
        else
        {
            // deviceRead() requires data pointer
            // copy data from const vector to data ptr
            uint8_t * l_configDataPtr = new uint8_t[ i_cfgData.size() ];
            std::copy(i_cfgData.begin(), i_cfgData.end(), l_configDataPtr);

            // if trace is enabled,
            // save the config data into l_traceCfgData variable
            if (l_traceit)
            {
              // copy the first 8 bytes of config data into trace variable
              if (i_cfgData.size() >= sizeof(l_traceCfgData))
              {
                // only copy what fits into l_traceCfgData variable
                memcpy(&l_traceCfgData, l_configDataPtr,sizeof(l_traceCfgData));
              }
              else
              {
                // all the config data bytes fit into l_traceCfgData variable
                memcpy(&l_traceCfgData, l_configDataPtr, i_cfgData.size());
              }
            }

            l_err = deviceRead(
                              l_target,
                              l_data_read,
                              l_get_size,
                              DEVICE_FAPI_I2C_ADDRESS_WCONFIG(i_cfgData.size(),
                                                              l_configDataPtr)
                              );

            delete [] l_configDataPtr;
        }

        if (l_err)
        {
            FAPI_ERR("platGetI2c: error from FAPI_I2C deviceRead() of target %s"
              , l_targName );
        }

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
            if ( i_cfgData.empty() )
            {
                FAPI_SCAN("TRACE : GETI2C  :  %s : %d %.16llX",
                          l_targName,
                          l_get_size,
                          l_traceDataRead);
            }
            else
            {
                FAPI_SCAN("TRACE : GETI2C w/config %.16llX :  %s : %d %.16llX",
                          l_traceCfgData,
                          l_targName,
                          l_get_size,
                          l_traceDataRead);
            }
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

    // cleanup allocated memory
    delete [] l_data_read;

    FAPI_DBG(EXIT_MRK "platGetI2c");
    return l_rc;
}

/// @brief Platform-level implementation called by FAPI putI2c()
ReturnCode platPutI2c(const Target<TARGET_TYPE_ALL>& i_target,
                      const std::vector<uint8_t>& i_data)
{
    ReturnCode l_rc;
    errlHndl_t l_err = nullptr;

    FAPI_DBG(ENTER_MRK "platPutI2c");
    // Note: Trace is placed here in plat code because PPE doesn't support
    //       trace in common fapi2_i2c_access.H
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
            FAPI_ERR( "platPutI2c: Error from getTargetingTarget on %s",
                      l_targName );
            break; //return with error
        }

        //copy data from const vector to data ptr
        uint8_t * l_dataPtr = new uint8_t[ i_data.size() ];
        std::copy(i_data.begin(), i_data.end(), l_dataPtr);
        size_t l_dataSize = i_data.size();

        l_err = deviceWrite( l_target,
                             l_dataPtr,
                             l_dataSize,
                             DEVICE_FAPI_I2C_ADDRESS() );
        if (l_traceit)
        {
            // trace the first 8 bytes of written data
            // (avoid trace buffer overflow)
            uint64_t traceWriteData = 0;
            if (l_dataSize > sizeof(traceWriteData))
            {
                // copy what will fit into traceWriteData variable
                memcpy(&traceWriteData, l_dataPtr, sizeof(traceWriteData));
            }
            else
            {
                memcpy(&traceWriteData, l_dataPtr, l_dataSize);
            }
            FAPI_SCAN( "TRACE : PUTI2C    :  %s : %d %.16llX",
                       l_targName,
                       l_dataSize,
                       traceWriteData );
        }

        delete [] l_dataPtr;

    } while (0);

    if (l_err)
    {
        l_rc.setPlatDataPtr(reinterpret_cast<void *> (l_err));
    }

    FAPI_DBG(EXIT_MRK "platPutI2c");
    return l_rc;
}

} // End namespace
