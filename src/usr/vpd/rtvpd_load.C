/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/rtvpd_load.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <sys/mm.h>
#include <vmmconst.h>
#include <pnor/pnorif.H>
#include <vpd/vpdreasoncodes.H>
#include <vpd/vpd_if.H>

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
                                PNOR::CURRENT_SIDE,
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
                 (((uint64_t)vpd_type) << 32) + info.size );

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);

        }
    }

    return err;

}

// External function see vpd_if.H
errlHndl_t VPD::vpd_load_rt_image(uint64_t & o_vpd_addr)
{
    errlHndl_t err = NULL;

    uint64_t vpd_addr = TARGETING::get_top_mem_addr();

    assert (vpd_addr != 0,
            "bld_devtree: Top of memory was 0!");

    vpd_addr -= VMM_RT_VPD_OFFSET;

    o_vpd_addr = vpd_addr;

    uint8_t * vpd_ptr = reinterpret_cast<uint8_t*>(vpd_addr);

    void * vptr = mm_block_map(vpd_ptr, VMM_RT_VPD_SIZE);

    assert(vptr != NULL,"bld_devtree: Could not map VPD memory");

    vpd_ptr = static_cast<uint8_t*>(vptr);

    err = bld_vpd_image(PNOR::DIMM_JEDEC_VPD,
                             vpd_ptr,
                             VMM_DIMM_JEDEC_VPD_SIZE);

    vpd_ptr += VMM_DIMM_JEDEC_VPD_SIZE;

    if(!err)
    {
        err = bld_vpd_image(PNOR::MODULE_VPD,
                                 vpd_ptr,
                                 VMM_MODULE_VPD_SIZE);

        vpd_ptr += VMM_MODULE_VPD_SIZE;
    }

    if(!err)
    {
        err = bld_vpd_image(PNOR::CENTAUR_VPD,
                                 vpd_ptr,
                                 VMM_CENTAUR_VPD_SIZE);
    }

    mm_block_unmap(vptr);

    return err;
}
