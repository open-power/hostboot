/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/rtvpd_load.C $                                    */
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

#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/mfgFlagAccessors.H>
#include <sys/mm.h>
#include <vmmconst.h>
#include <pnor/pnorif.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/vpd_if.H>
#include <errl/errlmanager.H>

// ----------------------------------------------
// Trace definitions
// ----------------------------------------------
extern trace_desc_t* g_trac_vpd;


/**
 * Copy a VPD image from PNOR into MEMORY
 * @param[in] vpd type (pnor section id)
 * @param[in] destination memory location
 * @param[in] Max size of image.
 * @return error handle if error
 */
errlHndl_t bld_vpd_image(PNOR::SectionId vpd_type,
                         void * i_dest,
                         uint64_t i_size)
{
    errlHndl_t err = NULL;
    PNOR::SectionInfo_t info;
    err = PNOR::getSectionInfo( vpd_type,
                                info );

    if(!err)
    {
        if(info.size <= i_size)
        {
            memcpy(i_dest,
                  reinterpret_cast<void *>(info.vaddr),
                  info.size);
        }
        else
        {
            TRACFCOMP( g_trac_vpd, ERR_MRK
                       "bld_vpd_image: Reserved size in memory insufficient "
                       "for VPD type %d. Size provided: %d Size needed: %d",
                       (uint32_t)vpd_type,
                       i_size,
                       info.size );


            /*@
             * @errortype
             * @reasoncode       VPD::VPD_INSUFFICIENT_SPACE_FOR_IMAGE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         VPD::VPD_BLD_RT_IMAGE
             * @userdata1        Size provided
             * @userdata2        vpd_type | Size required
             * @devdesc          Reserved size in memory insufficient
             *                   for runtime VPD
             */
            err = new ERRORLOG::ErrlEntry
                (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                 VPD::VPD_BLD_RT_IMAGE,
                 VPD::VPD_INSUFFICIENT_SPACE_FOR_IMAGE,
                 i_size,
                 (((uint64_t)vpd_type) << 32) + info.size,
                 true /*Add HB Software Callout*/);

            err->collectTrace( "VPD", 256);
        }
    }

    return err;

}

// External function see vpd_if.H
errlHndl_t VPD::vpd_load_rt_image(uint64_t & i_vpd_addr)
{
    errlHndl_t err = NULL;

    do
    {
        // All of the VPD EEPROM contents are stored in EECACHE
        // so copy the EECACHE pnor section to the space in reserved
        // memory allocated for VPD.
        void* vptr = reinterpret_cast<void*>(i_vpd_addr);
        uint8_t* vpd_ptr = reinterpret_cast<uint8_t*>(vptr);

        err = bld_vpd_image(PNOR::EECACHE,
                                 vpd_ptr,
                                 VMM_RT_VPD_SIZE);
        if(err)
        {
            break;
        }
    } while( 0 );

    return err;
}

