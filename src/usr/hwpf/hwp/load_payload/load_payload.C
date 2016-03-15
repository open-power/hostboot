/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/load_payload/load_payload.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#include <stdint.h>
#include <trace/interface.H>
#include <initservice/isteps_trace.H>
#include <errl/errlentry.H>
#include <hwpf/istepreasoncodes.H>
#include <hwpf/hwpf_reasoncodes.H>
#include <pnor/pnorif.H>
#include <targeting/common/commontargeting.H>
#include <initservice/initserviceif.H>
#include <arch/ppc.H>
#include <kernel/console.H>
#include <util/misc.H>
#include <sys/mm.h>
#include <xz/xz.h>
#include <initservice/istepdispatcherif.H>
#include "load_payload.H"

namespace LOAD_PAYLOAD
{

using namespace TARGETING;
using namespace ISTEP;

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

//
//  Wrapper function to call load_payload
//
void*   call_host_load_payload( void *io_pArgs )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               ENTER_MRK"call_load_payload");
    errlHndl_t l_err = NULL;

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
             * @reasoncode       ISTEP_TARGET_NULL
             * @severity         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid         ISTEP_LOAD_PAYLOAD
             * @userdata1        <UNUSED>
             * @userdata2        <UNUSED>
             * @devdesc          System target was NULL!
             * @custdesc         A problem occurred during the IPL
             *                   of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                            ISTEP_LOAD_PAYLOAD,
                            ISTEP_TARGET_NULL,
                            0x0,
                            0x0 );

            break;
        }

        if(INITSERVICE::spBaseServicesEnabled())
        {
            //this function is a NOOP on FSP systems
            break;
        }

        // Get Payload base/entry from attributes
        uint64_t payloadBase = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,INFO_MRK
                   "call_load_payload: Payload Base: 0x%08x, Base:0x%08x",
                   payloadBase, (payloadBase * MEGABYTE) );

        // Load payload data in PHYP mode or in Sapphire mode
        if( is_sapphire_load() || is_phyp_load())
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

static void simics_load_payload(uint64_t addr) __attribute__((noinline));
static void simics_load_payload(uint64_t addr)
{
    MAGIC_INSTRUCTION(MAGIC_LOAD_PAYLOAD);
}

static errlHndl_t load_pnor_section(PNOR::SectionId i_section,
        uint64_t i_physAddr)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ENTER_MRK"load_pnor_section()");
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

    uint32_t uncompressedPayloadSize = pnorSectionInfo.xzCompressed ?
            pnorSectionInfo.xzSize : pnorSectionInfo.size;

    const uint32_t originalPayloadSize = pnorSectionInfo.size;

    printk( "Loading PNOR section %d (%s) %d bytes @0x%lx\n",
            i_section,
            pnorSectionInfo.name,
            originalPayloadSize,
            i_physAddr );

    uint64_t loadAddr = NULL;

    // Use simics optimization if we are running under simics which has very
    // slow PNOR access.
    if ( Util::isSimicsRunning()  )
    {
        //TODO RTC 143500
        if(pnorSectionInfo.xzCompressed)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "If you are running simics, and have xz compressed ",
                  "payload image, you are going to fail. RTC 143500");
        }
        simics_load_payload( i_physAddr );
    }
    else
    {
        // Map in the physical memory we are loading into.
        // If we are not xz compressed, the uncompressedSize
        // is equal to the original size.
        loadAddr = reinterpret_cast<uint64_t>(
        mm_block_map( reinterpret_cast<void*>( i_physAddr ),
                      uncompressedPayloadSize ) );

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

        if(!pnorSectionInfo.xzCompressed)
        {
            // Load the data block by block and update the progress bar.
            const uint32_t BLOCK_SIZE = 4096;
            for ( uint32_t i = 0; i < originalPayloadSize; i += BLOCK_SIZE )
            {
                memcpy( reinterpret_cast<void*>( loadAddr + i ),
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
    }

    if(pnorSectionInfo.xzCompressed)
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

     return err;
}

}; // end namespace
