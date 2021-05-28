/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/fapi_i2c_dd.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
 *  @file fapi_i2c_dd.C
 *
 *  @brief Provides a thin layer on top of our I2C device driver to
 *         serve as the back-end for the FAPI i2c interfaces.
 *         It will locate the appropriate i2c device information
 *         and will perform retries as needed.
 */

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/commontargeting.H>
#include <devicefw/driverif.H>
#include <i2c/i2creasoncodes.H>
#include "fapi_i2c_dd.H"
#include <time.h>
#include <stdio.h>

extern trace_desc_t* g_trac_i2c;

using namespace DeviceFW;

namespace FAPI_I2C_DD
{

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


// ------------------------------------------------------------------
// errorIsRetryable
// ------------------------------------------------------------------
static bool errorIsRetryable(uint16_t reasonCode)
{
    return reasonCode == I2C::I2C_NACK_ONLY_FOUND ||
        reasonCode == I2C::I2C_ARBITRATION_LOST_ONLY_FOUND;
}

// Link to device driver interface
DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::FAPI_I2C,
                       TARGETING::TYPE_OCMB_CHIP,
                       fapiI2cPerformOp );

DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::FAPI_I2C,
                       TARGETING::TYPE_PMIC,
                       fapiI2cPerformOp );

DEVICE_REGISTER_ROUTE( DeviceFW::WILDCARD,
                       DeviceFW::FAPI_I2C,
                       TARGETING::TYPE_GENERIC_I2C_DEVICE,
                       fapiI2cPerformOp );

errlHndl_t fapiI2cPerformOp(DeviceFW::OperationType i_opType,
                            TARGETING::Target * i_target,
                            void * io_buffer,
                            size_t & io_buflen,
                            int64_t i_accessType,
                            va_list i_args)
{
    errlHndl_t l_err = nullptr;
    errlHndl_t l_err_retryable = nullptr;
    bool l_non_retryable_err_hit = false;
    const uint8_t FAPI_I2C_MAX_RETRIES = 2;

    TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type l_i2cInfo;
    uint8_t * l_cfgData = nullptr;

    size_t l_cfgSize = va_arg( i_args, size_t );
    if (l_cfgSize > 0)
    {
        l_cfgData = va_arg( i_args, uint8_t* );
    }

    timespec_t l_startTime;
    timespec_t l_endTime;
    clock_gettime(CLOCK_MONOTONIC, &l_startTime);

    TRACUCOMP(g_trac_i2c, ENTER_MRK"fapiI2cPerformOp(): "
      "%s operation on target %.8X",
      (i_opType==DeviceFW::READ)?"READ":"WRITE",
      TARGETING::get_huid(i_target) );

    do
    {
        // Grab i2c access information
        l_err = readI2cAttributes (i_target, l_i2cInfo);
        if( l_err )
        {
            break;
        }

        // If the target has dynamic device address attribute, then use that instead of the
        // read-only address found in ATTR_FAPI_I2C_CONTROL_INFO. We use the dynamic address
        // attribute because ATTR_FAPI_I2C_CONTROL_INFO is not writable and its difficult
        // to override complex attributes.
        if(i_target->tryGetAttr<TARGETING::ATTR_DYNAMIC_I2C_DEVICE_ADDRESS>(l_i2cInfo.devAddr))
        {
            TRACDCOMP(g_trac_i2c,
                     "Using DYNAMIC_I2C_DEVICE_ADDRESS %.2x for HUID %.8x",
                      l_i2cInfo.devAddr,
                      TARGETING::get_huid(i_target));
        }

        // grab target pointer to master
        TARGETING::TargetService& ts = TARGETING::targetService();
        TARGETING::Target * i2cm = ts.toTarget(l_i2cInfo.i2cMasterPath);

        TARGETING::Target * sys = nullptr;
        ts.getTopLevelTarget( sys );

        // master target has to exist and can not be just sys target
        if( (i2cm == nullptr) || (i2cm == sys) )
        {
            char* l_masterPath = l_i2cInfo.i2cMasterPath.toString();
            TRACFCOMP( g_trac_i2c, ERR_MRK"fapiI2cPerformOp() - "
                       "I2C Master path (%s) not valid",
                       l_masterPath);
            free(l_masterPath);
            l_masterPath = nullptr;

            /*@
             * @errortype
             * @reasoncode       I2C::INVALID_MASTER_TARGET
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C::FAPI_I2C_PERFORM_OP
             * @userdata1        HUID of target with FAPI_I2C_CONTROL_INFO
             * @devdesc          Invalid I2C master path
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          I2C::FAPI_I2C_PERFORM_OP,
                                          I2C::INVALID_MASTER_TARGET,
                                          TARGETING::get_huid(i_target),
                                          0,
                                          true /*Add HB SW Callout*/ );
            break;
        }

        // Verify valid operation type
        if ((i_opType != DeviceFW::READ) && (i_opType != DeviceFW::WRITE))
        {
            TRACFCOMP( g_trac_i2c,
                       ERR_MRK"fapiI2cPerformOp() - Invalid OP type %d.",
                       i_opType );
            /*@
             * @errortype
             * @reasoncode       I2C::I2C_INVALID_OP_TYPE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         I2C::FAPI_I2C_PERFORM_OP
             * @userdata1        OP type
             * @userdata2        HUID of target
             * @devdesc          Invalid I2C device type
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          I2C::FAPI_I2C_PERFORM_OP,
                                          I2C::I2C_INVALID_OP_TYPE,
                                          i_opType,
                                          TARGETING::get_huid(i_target),
                                          true /*Add HB SW Callout*/ );
            break;
        }

        ////////////////////////////////////////////////////////////////////////
        // Attempt valid i2c operation multiple times ONLY on retryable fails
        ////////////////////////////////////////////////////////////////////////
        for ( uint8_t retry = 0; retry <= FAPI_I2C_MAX_RETRIES; ++retry )
        {
            if( i_opType == DeviceFW::READ )
            {
                l_err = i2cRead( i2cm,
                                 io_buffer,
                                 io_buflen,
                                 &l_i2cInfo,
                                 l_cfgData,
                                 l_cfgSize );
            }
            else if (i_opType == DeviceFW::WRITE )
            {
                l_err = i2cWrite( i2cm,
                                  io_buffer,
                                  io_buflen,
                                  &l_i2cInfo );
            }

            if ( nullptr == l_err )
            {
                // Operation completed successfully
                // break from retry loop
                break;
            }
            else if ( !errorIsRetryable( l_err->reasonCode() ) )
            {
                // Non-retryable failure
                TRACFCOMP( g_trac_i2c, ERR_MRK"fapiI2cPerformOp(): Non-Nack "
                           "Error: rc=0x%X, tgt=0x%X, No Retry (retry=%d)",
                            l_err->reasonCode(),
                            TARGETING::get_huid(i_target), retry);
                l_non_retryable_err_hit = true;
                // break from retry loop
                break;
            }
            else // Handle retryable error
            {
                // If op will be attempted again: save log and continue
                if ( retry < FAPI_I2C_MAX_RETRIES )
                {
                    // Only save original retryable error
                    if ( nullptr == l_err_retryable )
                    {
                        // Save original retryable error
                        l_err_retryable = l_err;

                        TRACFCOMP( g_trac_i2c, ERR_MRK"fapiI2cPerformOp(): "
                           "Retryable Error rc=0x%X, eid=0x%X, tgt=0x%X, "
                           "retry/MAX=%d/%d. Save error and retry",
                           l_err_retryable->reasonCode(),
                           l_err_retryable->eid(),
                           TARGETING::get_huid(i_target),
                           retry, FAPI_I2C_MAX_RETRIES);
                    }
                    else
                    {
                        // Add data to original retryable error
                        TRACFCOMP( g_trac_i2c, ERR_MRK"fapiI2cPerformOp(): "
                           "Another Retryable Error rc=0x%X, eid=0x%X "
                           "plid=0x%X, tgt=0x%X, retry/MAX=%d/%d. "
                           "Delete error and retry",
                           l_err->reasonCode(), l_err->eid(),
                           l_err->plid(), TARGETING::get_huid(i_target),
                           retry, FAPI_I2C_MAX_RETRIES );

                        ERRORLOG::ErrlUserDetailsString(
                                  "Another Retryable Error found")
                                  .addToLog(l_err_retryable);

                        // Delete this new retryable error
                        delete l_err;
                        l_err = nullptr;
                    }

                    // continue to retry
                    continue;
                }
                else // no more retries: trace and break
                {
                    TRACFCOMP( g_trac_i2c, ERR_MRK"fapiI2cPerformOp(): "
                       "Error rc=0x%X, eid=0x%X, tgt=0x%X. No More "
                       "Retries (retry/MAX=%d/%d). Returning Error",
                       l_err->reasonCode(), l_err->eid(),
                       TARGETING::get_huid(i_target),
                       retry, FAPI_I2C_MAX_RETRIES);

                    // break from retry loop
                    break;
                }
            } // end of handle retryable error else leg

        } // end of retryable error loop

        clock_gettime(CLOCK_MONOTONIC, &l_endTime);
        char l_time_str[128];
        snprintf(l_time_str, sizeof(l_time_str),
                 "Start Time: %lu sec %lu ns End Time: %lu sec %lu ns",
                  l_startTime.tv_sec, l_startTime.tv_nsec,
                  l_endTime.tv_sec, l_endTime.tv_nsec);

        // Handle saved retryable error, if any
        if (l_err_retryable)
        {
            // This is the case where we had 1 or more retryable errors and
            // eventually hit a non retryable error.
            if (l_err && l_non_retryable_err_hit)
            {
                // commit original retryable error with new err PLID
                l_err_retryable->plid(l_err->plid());
                TRACFCOMP(g_trac_i2c, "fapiI2cPerformOp(): Committing saved "
                    "retryable error eid=0x%X with plid of returned err 0x%X",
                    l_err_retryable->eid(), l_err_retryable->plid());
                ERRORLOG::ErrlUserDetailsString(l_time_str)
                                              .addToLog(l_err_retryable);
                ERRORLOG::ErrlUserDetailsTarget(i_target)
                                               .addToLog(l_err_retryable);
                l_err_retryable->collectTrace(I2C_COMP_NAME);
                l_err_retryable->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit(l_err_retryable, I2C_COMP_ID);
            }
            else
            {
                // In this case we have either hit the max retryable errors and
                // failed, or hit one or more retryable errors and eventually
                // passed. Either way we do not need this l_err_retryable anymore.
                TRACUCOMP(g_trac_i2c, "fapiI2cPerformOp(): Op successful, or we hit max Retries and"
                    " the caller is polling on this i2c op. Deleting saved retryable err eid=0x%X,"
                     " plid=0x%X.",
                    l_err_retryable->eid(), l_err_retryable->plid());
                delete l_err_retryable;
                l_err_retryable = nullptr;
            }
        }

        if(l_err)
        {
            ERRORLOG::ErrlUserDetailsString(l_time_str)
                                          .addToLog(l_err);
            l_err->collectTrace(I2C_COMP_NAME);
        }

    } while (0);

    return l_err;
}



errlHndl_t i2cRead( TARGETING::Target * i_target,
                    void * o_buffer,
                    size_t & io_buffer_size,
                    TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type * i_i2cInfo,
                    uint8_t * i_offset_data,
                    const size_t i_offset_data_size)
{
    errlHndl_t l_err = nullptr;

    TRACUCOMP(g_trac_i2c, ENTER_MRK"i2cRead()");

    // This i2c interface writes the offset data to the device then
    // reads the value of the port w/o a stop bit in between ops
    // Note: if i_offset_data_size == 0, it will skip the write
    l_err = deviceOp( DeviceFW::READ,
                      i_target,
                      o_buffer,
                      io_buffer_size,
                      DEVICE_I2C_ADDRESS_OFFSET(
                                            i_i2cInfo->port,
                                            i_i2cInfo->engine,
                                            i_i2cInfo->devAddr,
                                            i_offset_data_size,
                                            i_offset_data,
                                            i_i2cInfo->i2cMuxBusSelector,
                                            &(i_i2cInfo->i2cMuxPath) ) );

    if( l_err )
    {

        TRACFCOMP(g_trac_i2c,
            ERR_MRK"fapi i2cRead(): read failed on e%d/p%d/devAddr=0x%X, offsetSize=%d "
            "with eid 0x%x", i_i2cInfo->engine, i_i2cInfo->port,
            i_i2cInfo->devAddr, i_offset_data_size, l_err->eid());

        // Printing mux info separately, if combined, nothing is displayed
        char* l_muxPath = i_i2cInfo->i2cMuxPath.toString();
        TRACFCOMP(g_trac_i2c, ERR_MRK"fapi i2cRead(): "
                  "muxSelector=0x%X, muxPath=%s",
                  i_i2cInfo->i2cMuxBusSelector,
                  l_muxPath);
        free(l_muxPath);
        l_muxPath = nullptr;

        if (i_offset_data_size > 0)
        {
            TRACFBIN(g_trac_i2c, "i_offset_data[]",
                i_offset_data, i_offset_data_size);
        }
    }

    TRACUCOMP(g_trac_i2c, EXIT_MRK"i2cRead");

    return l_err;
}


errlHndl_t i2cWrite( TARGETING::Target * i_target,
                     void * i_buffer,
                     size_t & io_buffer_size,
                     TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type * i_i2cInfo )
{
    TRACUCOMP(g_trac_i2c, ENTER_MRK"i2cWrite");

    errlHndl_t l_err = nullptr;

    // Do the actual data write
    l_err = deviceOp( DeviceFW::WRITE,
                      i_target,
                      i_buffer,
                      io_buffer_size,
                      DEVICE_I2C_ADDRESS(i_i2cInfo->port,
                                             i_i2cInfo->engine,
                                             i_i2cInfo->devAddr,
                                             i_i2cInfo->i2cMuxBusSelector,
                                             &(i_i2cInfo->i2cMuxPath) ) );

    if( l_err )
    {
        TRACFCOMP(g_trac_i2c,
            ERR_MRK"fapi i2cWrite(): write failed on e%d/p%d/devAddr=0x%X, length %d "
            "with eid 0x%x", i_i2cInfo->engine, i_i2cInfo->port,
            i_i2cInfo->devAddr, io_buffer_size,
            l_err->eid());

        // Printing mux info separately, if combined, nothing is displayed
        char* l_muxPath = i_i2cInfo->i2cMuxPath.toString();
        TRACFCOMP(g_trac_i2c, ERR_MRK"fapi i2cWrite(): "
                  "muxSelector=0x%X, muxPath=%s",
                  i_i2cInfo->i2cMuxBusSelector,
                  l_muxPath);
        free(l_muxPath);
        l_muxPath = nullptr;
    }


    TRACUCOMP(g_trac_i2c, EXIT_MRK"i2cWrite");
    return l_err;
}


errlHndl_t readI2cAttributes( TARGETING::Target * i_target,
                       TARGETING::ATTR_FAPI_I2C_CONTROL_INFO_type & io_i2cInfo )
{
    errlHndl_t l_err = nullptr;

    if( !(i_target->tryGetAttr<TARGETING::ATTR_FAPI_I2C_CONTROL_INFO>
                      (io_i2cInfo)) )
    {
        TRACFCOMP( g_trac_i2c,
                   ERR_MRK"readI2cAttributes() - ERROR reading "
                   "attributes for target huid %.8X",
                    TARGETING::get_huid(i_target) );

        /*@
         * @errortype
         * @reasoncode       I2C::I2C_ATTRIBUTE_NOT_FOUND
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         I2C::READ_I2C_ATTRIBUTES
         * @userdata1        HUID of target
         * @devdesc          FAPI_I2C_CONTROL_INFO attribute was not found
         * @custdesc         A problem occurred during the IPL
         *                   of the system.
         */
        l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         I2C::READ_I2C_ATTRIBUTES,
                                         I2C::I2C_ATTRIBUTE_NOT_FOUND,
                                         TARGETING::get_huid(i_target),
                                         0,
                                         true /*Add HB SW Callout*/ );

        l_err->collectTrace( I2C_COMP_NAME );
    }
    return l_err;
}

}; // end namespace FAPI_I2C

