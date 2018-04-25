/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/runtime/rt_scom.C $                              */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <scom/scomreasoncodes.H>
#include <scom/scomif.H>
#include <scom/runtime/rt_scomif.H>
#include <runtime/interface.h>
#include <runtime/rt_targeting.H>
#include <xscom/piberror.H>

// Trace definition
extern trace_desc_t* g_trac_scom;

namespace SCOM
{

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
 * @brief Send the scom to the hypervisor
 *
 * @param[in]     i_opType    Operation type, see driverif.H
 * @param[in]     i_target    Scom target
 * @param[in]     i_scomAddr  Scom address
 * @param[in/out] io_buffer   Read: Pointer to output data storage
 *                            Write: Pointer to input data storage
 * @return  errlHndl_t
 */
errlHndl_t sendScomToHyp(DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         uint64_t i_scomAddr,
                         void * io_buffer)
{
    errlHndl_t l_err = nullptr;
    int rc = 0;

    do
    {
        // Convert target to something Sapphire understands
        RT_TARG::rtChipId_t proc_id = 0;
        l_err = RT_TARG::getRtTarget(i_target,
                                    proc_id);
        if(l_err)
        {
            break;
        }

        if(g_hostInterfaces != nullptr &&
        g_hostInterfaces->scom_read != nullptr &&
        g_hostInterfaces->scom_write != nullptr)
        {

            if(i_opType == DeviceFW::READ)
            {
                rc =
                    g_hostInterfaces->scom_read(proc_id,
                                                i_scomAddr,
                                                io_buffer
                                            );
            }
            else if (i_opType == DeviceFW::WRITE)
            {
                rc =
                    g_hostInterfaces->scom_write(proc_id,
                                                i_scomAddr,
                                                io_buffer
                                                );
            }

            if(rc)
            {
                TRACFCOMP(g_trac_scom,ERR_MRK
                    "Hypervisor scom read/write failed. "
                    "rc 0x%X target 0x%llX proc_id 0x%llX addr 0x%llX r/w %d",
                    rc, get_huid(i_target), proc_id, i_scomAddr, i_opType);

                // convert rc to error log
                /*@
                * @errortype
                * @moduleid     SCOM_RT_SEND_SCOM_TO_HYP
                * @reasoncode   SCOM_RUNTIME_HYP_ERR
                * @userdata1[0:31]    Hypervisor return code
                * @userdata1[32:63]   SCOM Op Type
                * @userdata2    SCOM address
                * @devdesc      SCOM access error
                */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    SCOM_RT_SEND_SCOM_TO_HYP,
                                    SCOM_RUNTIME_HYP_ERR,
                                    TWO_UINT32_TO_UINT64(
                                                    rc,
                                                    i_opType),
                                    i_scomAddr);

                constexpr int MembufFatalError = -0x1008;

                if (rc == MembufFatalError)
                {
                    FSISCOM::switchToFspScomAccess(i_target);
                }

                // attempt to translate rc into a pib error assuming
                //  the rc is in common format
                HbrtRcPiberr_t l_commonRc = static_cast<HbrtRcPiberr_t>(rc);
                PIB::PibError l_piberr = HbrtRcToPibErr( l_commonRc );

                if // input was translated to a PIB error code
                ( l_piberr != PIB::PIB_NO_ERROR )
                {
                    // (translation was successful)
                    TRACFCOMP(g_trac_scom,ERR_MRK"RC to PIB Err: PIBERR 0x%X",l_piberr);
                }

                else if // input was common format, but not a PIB error
                ( l_commonRc == HBRT_RC_SOMEOTHERERROR )
                {
                    // (already translated to PIB::PIB_NO_ERROR,
                    //   no more translation needed)
                    TRACFCOMP(g_trac_scom,ERR_MRK"RC to PIB Err: PIB_NO_ERROR");
                }

                else if  // legacy opal
                ( TARGETING::is_sapphire_load() )
                {
                    // attempt to translate rc into a pib error assuming
                    //  the rc is in old opal format
                    // this preserves legacy behavior to avoid co-req/pre-req
                    l_piberr =  OpalRcToPibErr( rc );
                    TRACFCOMP(g_trac_scom,ERR_MRK"RC to PIB Err: OPAL 0x%X",l_piberr);
                }

                else if  // legacy phyp
                ( TARGETING::is_phyp_load() )
                {
                    // default to OFFLINE for now to trigger
                    // the multicast workaround in scom.C
                    l_piberr = PIB::PIB_CHIPLET_OFFLINE;
                    TRACFCOMP(g_trac_scom,ERR_MRK"RC to PIB Err: PIB_CHIPLET_OFFLINE");
                }

                else
                {
                    // our testcases respond back with the
                    //  pib error directly
                    if( rc > 0 )
                    {
                        l_piberr = static_cast<PIB::PibError>(rc);
                        TRACFCOMP(g_trac_scom,ERR_MRK"RC to PIB Err: RC 0x%X",l_piberr);
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
            TRACFCOMP(g_trac_scom,ERR_MRK"Hypervisor scom interface not linked");
            /*@
            * @errortype
            * @moduleid     SCOM_RT_SEND_SCOM_TO_HYP
            * @reasoncode   SCOM_RUNTIME_INTERFACE_ERR
            * @userdata1    SCOM Op Type
            * @userdata2    SCOM address
            * @devdesc      SCOM runtime interface not linked.
            */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                            SCOM_RT_SEND_SCOM_TO_HYP,
                                            SCOM_RUNTIME_INTERFACE_ERR,
                                            i_opType,
                                            i_scomAddr);

            l_err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);
        }

    } while(0);

    return l_err;
}

};  // end namespace SCOM
