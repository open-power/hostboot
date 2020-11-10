/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/runtime/rt_scom.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#include <targeting/runtime/rt_targeting.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <xscom/piberror.H>
#include <runtime/hbrt_utilities.H>

// Trace definition
extern trace_desc_t* g_trac_scom;

namespace SCOM
{

struct RcPibErrMap
{
    PIB::PibError        iv_Piberr;
    int                  iv_Common;
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
PIB::PibError HbrtScomRcToPibErr( int i_rc )
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
    int l_hostRC = 0;

    do
    {
        // Convert target to something Sapphire understands
        TARGETING::rtChipId_t target_id = 0;
        l_err = TARGETING::getRtTarget(i_target,
                                       target_id);
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
                l_hostRC =
                    g_hostInterfaces->scom_read(target_id,
                                                i_scomAddr,
                                                io_buffer
                                            );
            }
            else if (i_opType == DeviceFW::WRITE)
            {
                l_hostRC =
                    g_hostInterfaces->scom_write(target_id,
                                                i_scomAddr,
                                                io_buffer
                                                );
            }

            if(l_hostRC)
            {
                TRACFCOMP(g_trac_scom,ERR_MRK
                    "Hypervisor scom read/write failed. "
                    "rc 0x%X target 0x%llX target_id 0x%llX addr 0x%llX r/w %d",
                    l_hostRC, get_huid(i_target), target_id, i_scomAddr, i_opType);

                // Use an unused bit in the 64-bit scom range to indicate
                //  read/write. Cannot use bit0 since that is part of an
                //  indirect address. Cannot use bit63 because that is a
                //  valid part of the address.
                uint64_t l_userdata2 = i_scomAddr;
                if(i_opType == DeviceFW::WRITE)
                {
                    l_userdata2 |= 0x4000000000000000;
                }

                // convert rc to error log
                /*@
                * @errortype
                * @moduleid     SCOM_RT_SEND_SCOM_TO_HYP
                * @reasoncode   SCOM_RUNTIME_HYP_ERR
                * @userdata1[0:31]   Hypervisor return code
                * @userdata1[32:63]  Chipid sent to Hyp
                * @userdata2[0:63]   SCOM address
                * @userdata2[1]      SCOM Op Type: 0=read, 1=write
                * @devdesc      Error from Hypervisor attempting SCOM
                */
                l_err = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    SCOM_RT_SEND_SCOM_TO_HYP,
                                    SCOM_RUNTIME_HYP_ERR,
                                    TWO_UINT32_TO_UINT64(
                                                    l_hostRC,
                                                    target_id),
                                    l_userdata2);

                if (l_hostRC == HBRT_RC_CHANNEL_FAILURE)
                {
                    if (i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_OCMB_CHIP)
                    {
                        // Channel is dead so switch to using the SBE for
                        //  access
                        SBESCOM::switchToSbeScomAccess(i_target);
                    }

                    // Callout the failing buffer chip
                    l_err->addHwCallout(i_target,
                                        HWAS::SRCI_PRIORITY_HIGH,
                                        HWAS::NO_DECONFIG,
                                        HWAS::GARD_NULL);
                }
                else
                {
                    // attempt to translate rc into a pib error assuming
                    //  the rc is in common format
                    int l_commonRc = l_hostRC;
                    PIB::PibError l_piberr = HbrtScomRcToPibErr( l_commonRc );

                    if // input was translated to a PIB error code
                        ( l_piberr != PIB::PIB_NO_ERROR )
                    {
                        // (translation was successful)
                        TRACFCOMP(g_trac_scom,ERR_MRK"RC to PIB Err: PIBERR 0x%X",l_piberr);
                    }

                    else if  // legacy opal
                        ( TARGETING::is_sapphire_load() )
                    {
                        // attempt to translate rc into a pib error assuming
                        //  the rc is in old opal format
                        // this preserves legacy behavior to avoid co-req/pre-req
                        l_piberr =  OpalRcToPibErr( l_hostRC );
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

                    PIB::addFruCallouts(i_target,
                                        l_piberr,
                                        i_scomAddr,
                                        l_err);
                }

                l_err->collectTrace( SCOM_COMP_NAME, 256);
                l_err->collectTrace( HBRT_TRACE_NAME, 256);
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
            l_err->collectTrace( SCOM_COMP_NAME, 256);
            l_err->collectTrace( HBRT_TRACE_NAME, 256);
        }

    } while(0);

    return l_err;
}

};  // end namespace SCOM
