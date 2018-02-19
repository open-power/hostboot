/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/runtime/rt_xscom.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2018                        */
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
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <xscom/xscomreasoncodes.H>
#include "../xscom.H"
#include <assert.h>
#include <errl/errludlogregister.H>
#include <runtime/interface.h>
#include <errl/errludtarget.H>
#include <runtime/rt_targeting.H>
#include <xscom/piberror.H>

// Trace definition
trace_desc_t* g_trac_xscom = NULL;
TRAC_INIT(&g_trac_xscom, "XSCOM", 2*KILOBYTE, TRACE::BUFFER_SLOW);

namespace XSCOM
{

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::XSCOM,
                      TARGETING::TYPE_PROC,
                      xscomPerformOp);

// Direct all scom calls though this interface at runtime
DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::FSISCOM,
                      TARGETING::TYPE_PROC,
                      xscomPerformOp);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::FSISCOM,
                      TARGETING::TYPE_MEMBUF,
                      xscomPerformOp);

DEVICE_REGISTER_ROUTE(DeviceFW::WILDCARD,
                      DeviceFW::IBSCOM,
                      TARGETING::TYPE_MEMBUF,
                      xscomPerformOp);

struct RcPibErrMap
{
    PIB::PibError        iv_Piberr;
    HbrtRcPiberr_t       iv_Common;
    int                  iv_Opal; // note : opal values taken from opal-api.h
};


const RcPibErrMap pibErrTbl[] =
{
        // 001
        PIB::PIB_RESOURCE_OCCUPIED,
        HBRT_RC_PIBERR_001_BUSY,
        -12,     // OPAL_XSCOM_BUSY

        // 002
        PIB::PIB_CHIPLET_OFFLINE,
        HBRT_RC_PIBERR_010_OFFLINE,
        -14,    // OPAL_XSCOM_CHIPLET_OFF

        // 003
        PIB::PIB_PARTIAL_GOOD,
        HBRT_RC_PIBERR_011_PGOOD,
        -25,    // OPAL_XSCOM_PARTIAL_GOOD

        // 004
        PIB::PIB_INVALID_ADDRESS,
        HBRT_RC_PIBERR_100_INVALIDADDR,
        -26,    // OPAL_XSCOM_ADDR_ERROR

        // 005
        PIB::PIB_CLOCK_ERROR,
        HBRT_RC_PIBERR_101_CLOCKERR,
        -27,    // OPAL_XSCOM_CLOCK_ERROR

        // 006
        PIB::PIB_PARITY_ERROR,
        HBRT_RC_PIBERR_110_PARITYERR,
        -28,    // OPAL_XSCOM_PARITY_ERROR

        // 007
        PIB::PIB_TIMEOUT,
        HBRT_RC_PIBERR_111_TIMEOUT,
        -29     // OPAL_XSCOM_TIMEOUT
};


/**
 * @brief Internal routine that translates a HBRT return code to a
 * PIB error code
 *
 * @param[in]   i_rc           HBRT return code,
 * @return      PibError,  PIB::PIB_NO_ERROR if not translatable
 *
 */
PIB::PibError HbrtRcToPibErr( HbrtRcPiberr_t i_rc )
{
    int l_entryCnt = sizeof(pibErrTbl) / sizeof(RcPibErrMap);
    PIB::PibError l_rv = PIB::PIB_NO_ERROR;

    for // loop thru the xlate table
      ( int i = 0;
        i < l_entryCnt;
        i++ )
    {
        if // matching entry found
          ( pibErrTbl[i].iv_Common == i_rc )
        {
            // extract translation value
            l_rv = pibErrTbl[i].iv_Piberr;
            break;
        }
    }

    return( l_rv );
}


/**
 * @brief Internal routine that translates an OPAL return code to a
 * PIB error code
 *
 * @param[in]   i_rc           OPAL return code
 * @return      PibError,  PIB::PIB_NO_ERROR if not translatable
 */
PIB::PibError OpalRcToPibErr( int i_rc )
{
    int l_entryCnt = sizeof(pibErrTbl) / sizeof(RcPibErrMap);
    PIB::PibError l_rv = PIB::PIB_NO_ERROR;

    for // loop thru the xlate table
      ( int i = 0;
        i < l_entryCnt;
        i++ )
    {
        if // matching entry found
          ( pibErrTbl[i].iv_Opal == i_rc )
        {
            // extract translation value
            l_rv = pibErrTbl[i].iv_Piberr;
            break;
        }
    }

    return( l_rv );
}


/**
 * @brief Internal routine that verifies the validity of input parameters
 * for an XSCOM access.
 *
 * @param[in]   i_opType       Operation type, see DeviceFW::OperationType
 *                             in driverif.H
 * @param[in]   i_target       XSCom target
 * @param[in/out] i_buffer     Read: Pointer to output data storage
 *                             Write: Pointer to input data storage
 * @param[in/out] i_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_args         This is an argument list for DD framework.
 *                             In this function, there's only one argument,
 *                             which is the MMIO XSCom address
 * @return  errlHndl_t
 */
errlHndl_t xscomOpSanityCheck(const DeviceFW::OperationType i_opType,
                              const TARGETING::Target* i_target,
                              const void* i_buffer,
                              const size_t& i_buflen,
                              const va_list i_args);



errlHndl_t xscomOpSanityCheck(const DeviceFW::OperationType i_opType,
                              const TARGETING::Target* i_target,
                              const void* i_buffer,
                              const size_t& i_buflen,
                              const va_list i_args){
    errlHndl_t l_err = NULL;

    do
    {
        // Verify data buffer
        if ( (i_buflen < XSCOM_BUFFER_SIZE) ||
             (i_buffer == NULL) )
        {
            /*@
             * @errortype
             * @moduleid     XSCOM_RT_SANITY_CHECK
             * @reasoncode   XSCOM_INVALID_DATA_BUFFER
             * @userdata1    Buffer size
             * @userdata2    XSCom address
             * @devdesc      XSCOM buffer size < 8 bytes or NULL data buff
             */
            l_err =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        XSCOM_RT_SANITY_CHECK,
                                        XSCOM_INVALID_DATA_BUFFER,
                                        i_buflen,
                                        va_arg(i_args,uint64_t));
            break;
        }

        // Verify OP type
        if ( (i_opType != DeviceFW::READ) &&
             (i_opType != DeviceFW::WRITE) )
        {
            /*@
             * @errortype
             * @moduleid     XSCOM_RT_SANITY_CHECK
             * @reasoncode   XSCOM_INVALID_OP_TYPE
             * @userdata1    Operation type
             * @userdata2    XSCom address
             * @devdesc      XSCOM invalid operation type
             */
            l_err =
                new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        XSCOM_RT_SANITY_CHECK,
                                        XSCOM_INVALID_OP_TYPE,
                                        i_opType,
                                        va_arg(i_args,uint64_t));
            break;
        }


    } while(0);

    return l_err;
}

/**
 * @brief Do the scom operation
 */
errlHndl_t  xScomDoOp(DeviceFW::OperationType i_ioType,
                      TARGETING::Target * i_target,
                      uint64_t i_scomAddr,
                      void * io_buffer)
{
    errlHndl_t l_err = NULL;
    int rc = 0;
    RT_TARG::rtChipId_t proc_id = 0;

    // Convert target to something  Sapphire understands
    l_err = RT_TARG::getRtTarget(i_target,
                                 proc_id);

    if(l_err)
    {
        return l_err;
    }

    if(g_hostInterfaces != NULL &&
       g_hostInterfaces->scom_read != NULL &&
       g_hostInterfaces->scom_write != NULL)
    {

        if(i_ioType == DeviceFW::READ)
        {
            rc =
                g_hostInterfaces->scom_read(proc_id,
                                            i_scomAddr,
                                            io_buffer
                                           );
        }
        else if (i_ioType == DeviceFW::WRITE)
        {
            rc =
                g_hostInterfaces->scom_write(proc_id,
                                             i_scomAddr,
                                             io_buffer
                                            );
        }

        if(rc)
        {
            TRACFCOMP(g_trac_xscom,ERR_MRK
                "Hypervisor scom read/write failed. "
                "rc 0x%X target 0x%llX proc_id 0x%llX addr 0x%llX r/w %d",
                rc, get_huid(i_target), proc_id, i_scomAddr, i_ioType);

            // convert rc to error log
            /*@
             * @errortype
             * @moduleid     XSCOM_RT_DO_OP
             * @reasoncode   XSCOM_RUNTIME_ERR
             * @userdata1    Hypervisor return code
             * @userdata2    SCOM address
             * @devdesc      XSCOM access error
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            XSCOM_RT_DO_OP,
                                            XSCOM_RUNTIME_ERR,
                                            rc,
                                            i_scomAddr);

            // attempt to translate rc into a pib error assuming
            //  the rc is in common format
            HbrtRcPiberr_t l_commonRc = static_cast<HbrtRcPiberr_t>(rc);
            PIB::PibError l_piberr = HbrtRcToPibErr( l_commonRc );

            if // input was translated to a PIB error code
              ( l_piberr != PIB::PIB_NO_ERROR )
            {
                // (translation was successful)
            }

            else if // input was common format, but not a PIB error
              ( l_commonRc == HBRT_RC_SOMEOTHERERROR )
            {
                // (already translated to PIB::PIB_NO_ERROR,
                //   no more translation needed)
            }

            else if  // legacy opal
              ( TARGETING::is_sapphire_load() )
            {
                // attempt to translate rc into a pib error assuming
                //  the rc is in old opal format
                // this preserves legacy behavior to avoid co-req/pre-req
                l_piberr =  OpalRcToPibErr( rc );
            }

            else if  // legacy phyp
              ( TARGETING::is_phyp_load() )
            {
                // default to OFFLINE for now to trigger
                // the multicast workaround in scom.C
                l_piberr = PIB::PIB_CHIPLET_OFFLINE;
            }

            else
            {
                // our testcases respond back with the
                //  pib error directly
                if( rc > 0 )
                {
                    l_piberr = static_cast<PIB::PibError>(rc);
                }
            }

            PIB::addFruCallouts(i_target,
                                l_piberr,
                                i_scomAddr,
                                l_err);

            // Note: no trace buffer available at runtime
        }
    }
    else // Hypervisor interface not initialized
    {
        TRACFCOMP(g_trac_xscom,ERR_MRK"Hypervisor scom interface not linked");
        /*@
         * @errortype
         * @moduleid     XSCOM_RT_DO_OP
         * @reasoncode   XSCOM_RUNTIME_INTERFACE_ERR
         * @userdata1    0
         * @userdata2    SCOM address
         * @devdesc      XSCOM runtime interface not linked.
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        XSCOM_RT_DO_OP,
                                        XSCOM_RUNTIME_INTERFACE_ERR,
                                        0,
                                        i_scomAddr);

        l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                   HWAS::SRCI_PRIORITY_HIGH);
    }

    return l_err;
}


errlHndl_t xscomPerformOp(DeviceFW::OperationType i_opType,
                          TARGETING::Target* i_target,
                          void* io_buffer,
                          size_t& io_buflen,
                          int64_t i_accessType,
                          va_list i_args)
{
    TRACDCOMP(g_trac_xscom,ENTER_MRK"xscomPerformOp");
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    l_err = xscomOpSanityCheck(i_opType,
                               i_target,
                               io_buffer,
                               io_buflen,
                               i_args);

    if (!l_err)
    {

        l_err = xScomDoOp(i_opType,
                          i_target,
                          l_addr,
                          io_buffer);
    }

    TRACDCOMP(g_trac_xscom,EXIT_MRK"xscomPerformOp");

    return l_err;
}

}; // end namespace XSCOM

