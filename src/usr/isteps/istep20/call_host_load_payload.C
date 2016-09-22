/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep20/call_host_load_payload.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <isteps/hwpf_reasoncodes.H>
#include <targeting/common/commontargeting.H>
#include <initservice/istepdispatcherif.H>
#include <initservice/initserviceif.H>
#include <pnor/pnorif.H>
#include <util/misc.H>
#include <sys/mm.h>
#include <arch/ppc.H>
#include <kernel/console.H>
#include <xz/xz.h>

using namespace ERRORLOG;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace TARGETING;

namespace ISTEP_20
{

/**
 * @brief This function loads the pnor section in sapphire mode and
 *        and also decompresseses the section if it was compressed
 *
 * @param[in] i_section  - Which section are we loading
 * @param[in] i_physAddr - The physical address of the section
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer
 *                      to the error log.
 */
static errlHndl_t load_pnor_section(PNOR::SectionId i_section,
                                    uint64_t i_physAddr);

void* call_host_load_payload (void *io_pArgs)
{
    errlHndl_t  l_err  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"call_host_start_payload entry" );

    do
    {
        // Get Target Service, and the system target.
        TargetService& tS = targetService();
        TARGETING::Target* sys = NULL;
        (void) tS.getTopLevelTarget( sys );
        if( NULL == sys )
        {
            // Error getting system target to get payload related values.  We
            // will create an error to be passed back.  This will cause the
            // istep to fail.
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"call_load_payload: System Target was NULL!" );

            /*@
             * @errortype
             * @reasoncode       RC_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         MOD_LOAD_PAYLOAD
             * @userdata1        <UNUSED>
             * @userdata2        <UNUSED>
             * @devdesc          System target was NULL!
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            MOD_LOAD_PAYLOAD,
                            RC_TARGET_NULL,
                            0x0,
                            0x0 );

            break;
        }

        if(INITSERVICE::spBaseServicesEnabled())
        {
            //this function is a NOOP on FSP system
            break;
        }

        // Get Payload base/entry from attributes
        uint64_t payloadBase = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,INFO_MRK
                   "call_load_payload: Payload Base: 0x%08x MB, Base:0x%08x",
                   payloadBase, (payloadBase * MEGABYTE) );

        payloadBase = payloadBase * MEGABYTE;

        // Load payload data in PHYP mode or in Sapphire mode
        if(is_sapphire_load() || is_phyp_load())
        {
            l_err = load_pnor_section( PNOR::PAYLOAD, payloadBase );
            if ( l_err )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_load_payload: error loading pnor section");
                break;
            }
        }

    }while(0);

    return l_err;
}

static errlHndl_t load_pnor_section(PNOR::SectionId i_section,
        uint64_t i_physAddr)
{
    // Get the section info from PNOR.
    PNOR::SectionInfo_t pnorSectionInfo;
    errlHndl_t err = PNOR::getSectionInfo( i_section,
                    pnorSectionInfo );
    if( err != NULL )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "load_pnor_section: Could not get section info from %x",
                  i_section);
        return err;
    }

    // XZ repository: http:git.tukaani.org/xz.git
    // Header specifics can be found in xz/doc/xz-file-format.txt
    const uint8_t HEADER_MAGIC[]= { 0xFD, '7', 'z', 'X', 'Z', 0x00 };
    uint8_t* l_pnor_header = reinterpret_cast<uint8_t *>(pnorSectionInfo.vaddr);

    bool l_pnor_is_XZ_compressed = (0 == memcmp(l_pnor_header,
                               HEADER_MAGIC, sizeof(HEADER_MAGIC)));

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
             "load_pnor_section: is XZ_compressed: %d",
              l_pnor_is_XZ_compressed);

    // This assumes that the maximum decompression ratio will always be less
    // than 1:16 (compressed:uncompressed).  This works because XZ compression
    // is usually 14.1%, the decompressor does not need the exact size, and
    // we have all of mainstore memory at this point.
    uint32_t uncompressedPayloadSize = l_pnor_is_XZ_compressed ?
            (pnorSectionInfo.size * 16) : pnorSectionInfo.size;


    const uint32_t originalPayloadSize = pnorSectionInfo.size;

    printk( "Loading PNOR section %d (%s) %d bytes @0x%lx\n",
            i_section,
            pnorSectionInfo.name,
            originalPayloadSize,
            i_physAddr );

    void * loadAddr = NULL;
    // Map in the physical memory we are loading into.
    // If we are not xz compressed, the uncompressedSize
    // is equal to the original size.
    loadAddr = mm_block_map( reinterpret_cast<void*>( i_physAddr ),
                             uncompressedPayloadSize );

    // Print out inital progress bar.
#ifdef CONFIG_CONSOLE
    const int progressSteps = 80;
    int progress = 0;
    for ( int i = 0; i < progressSteps; ++i )
    {
        printk( "." );
    }
    printk( "\r" );
#endif

    if(!l_pnor_is_XZ_compressed)
    {
        // Load the data block by block and update the progress bar.
        const uint32_t BLOCK_SIZE = 4096;
        for ( uint32_t i = 0; i < originalPayloadSize; i += BLOCK_SIZE )
        {
            memcpy( reinterpret_cast<void*>(
                      reinterpret_cast<uint64_t>(loadAddr) + i ),
                    reinterpret_cast<void*>( pnorSectionInfo.vaddr + i ),
                    std::min( originalPayloadSize - i, BLOCK_SIZE ) );
#ifdef CONFIG_CONSOLE
            for ( int new_progress = (i * progressSteps) /
                  originalPayloadSize;
                  progress <= new_progress; progress++ )
            {
                printk( "=" );
            }
#endif
        }
#ifdef CONFIG_CONSOLE
        printk( "\n" );
#endif
    }

    if(l_pnor_is_XZ_compressed)
    {
        struct xz_buf b;
        struct xz_dec *s;
        enum xz_ret ret;

        xz_crc32_init();
        s = xz_dec_init(XZ_SINGLE, 0);
        if(s == NULL)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                     "load_pnor_section: XZ Embedded Initialization failed");
            return err;
        }

        static const uint64_t compressed_SIZE = originalPayloadSize;
        static const uint64_t decompressed_SIZE = uncompressedPayloadSize;

        b.in = reinterpret_cast<uint8_t *>( pnorSectionInfo.vaddr);
        b.in_pos = 0;
        b.in_size = compressed_SIZE;
        b.out = reinterpret_cast<uint8_t *>(loadAddr);
        b.out_pos = 0;
        b.out_size = decompressed_SIZE;

        ret = xz_dec_run(s, &b);

        if(ret == XZ_STREAM_END)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "load_pnor_section: The %s section was decompressed.",
                      pnorSectionInfo.name);
        }else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                     "load_pnor_section: xz-embedded returned an error, ",
                     "the ret is %d",ret);

            /*@
             * @errortype
             * @reasoncode       fapi::RC_INVALID_RETURN_XZ_CODE
             * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid         fapi::MOD_START_XZ_PAYLOAD
             * @devdesc          xz-embedded has returned an error.
             *                   the return code can be found in xz.h
             * @custdesc         Error uncompressing payload image from
             *                   boot flash
             * @userdata1        Return code from xz-embedded
             * @userdata2[0:31]  Original Payload Size
             * @userdata2[32:63] Uncompressed Payload Size
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            fapi::MOD_START_XZ_PAYLOAD,
                            fapi::RC_INVALID_RETURN_XZ_CODE,
                            ret,TWO_UINT32_TO_UINT64(
                                    originalPayloadSize,
                                    uncompressedPayloadSize));
            err->addProcedureCallout(HWAS::EPUB_PRC_PHYP_CODE,
                            HWAS::SRCI_PRIORITY_HIGH);

        }
        //Clean up memory
        xz_dec_end(s);

    }

    int rc = 0;
    rc = mm_block_unmap(reinterpret_cast<void *>(loadAddr));
    if(rc)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,ERR_MRK
                 "load_pnor_section: mm_block_unmap returned 1");

        /*@
         * @errortype
         * @reasoncode      fapi::RC_MM_UNMAP_ERR
         * @severity        ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        fapi::MOD_START_XZ_PAYLOAD
         * @devdesc         mm_block_unmap returned incorrectly with 0
         * @custdesc        Error unmapping memory section
         */
        err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      fapi::MOD_START_XZ_PAYLOAD,
                                      fapi::RC_MM_UNMAP_ERR,
                                      0,0,0);
    }
    return err;
}

};
