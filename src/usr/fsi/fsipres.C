/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/fsipres.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
/* [+] Google Inc.                                                        */
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
#include <targeting/common/attributes.H>
#include <fsi/fsiif.H>
#include <fsi/fsi_reasoncodes.H>
#include <vpd/mvpdenums.H>
#include <vpd/vpd_if.H>
#include <spi/spi.H>
#include <errl/errlmanager.H>
#include <hwas/common/hwasCallout.H>
#include <targeting/common/predicates/predicatectm.H>
#include <initservice/initserviceif.H>
#include <util/misc.H>

extern trace_desc_t* g_trac_fsi;


namespace FSI
{

/**
 * @brief Performs a presence detect operation on a Processor Chip.
 *
 * This function does FSI presence detect and compares it to the Module
 * VPD that is present, following the pre-defined prototype for a
 * device-driver framework function.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Presence detect target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t procPresenceDetect(DeviceFW::OperationType i_opType,
                              TARGETING::Target* i_target,
                              void* io_buffer,
                              size_t& io_buflen,
                              int64_t i_accessType,
                              va_list i_args)
{
    errlHndl_t l_errl = NULL;
    uint32_t l_saved_plid = 0;

    do {

        if (unlikely(io_buflen < sizeof(bool)))
        {
            TRACFCOMP(g_trac_fsi,
                      ERR_MRK "FSI::procPresenceDetect> Invalid data length: %d",
                      io_buflen);
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIPRES_PROCPRESENCEDETECT
             * @reasoncode   FSI::RC_INVALID_LENGTH
             * @userdata1    Data Length
             * @devdesc      presenceDetect> Invalid data length (!= 1 bytes)
             * @custdesc     FSI buffer length is not 1 byte when finding
             *               processor
             */
            l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIPRES_PROCPRESENCEDETECT,
                                            FSI::RC_INVALID_LENGTH,
                                            TO_UINT64(io_buflen),
                                            true /*SW error*/);
            io_buflen = 0;
            break;
        }

        // First look for FSI presence bits
        bool fsi_present = false;

        TARGETING::Target* l_masterChip = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_masterChip);

        if ((i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) ||
            (i_target == l_masterChip))
        {
            fsi_present = true;
        }
        else
        {
            fsi_present = isSlavePresent(i_target);
            if (fsi_present)
            {
                //@FIXME-RTC:254475-Remove once this works everywhere
                if( !Util::isMultiprocSupported() )
                {
                    TRACFCOMP(g_trac_fsi, "Ignoring secondary procs" );
                    fsi_present = false;
                }
                else
                {
                    TRACFCOMP(g_trac_fsi, "FSI::procPresenceDetect> 0x%.8X target present", TARGETING::get_huid(i_target) );
                    l_errl = SPI::spiSetAccessMode(i_target, SPI::FSI_ACCESS);
                    if (l_errl)
                    {
                        // Since this is a hard failure to detect later,
                        // error out here
                        TRACFCOMP( g_trac_fsi, ERR_MRK "FSI::procPresenceDetect> "
                            "Unable to switch to FSI_ACCESS for 0x%.8X",
                            TARGETING::get_huid(i_target) );
                        l_errl->collectTrace("FSI");
                        break;
                    }

                    // Since we'll be using the FSI SPI master to read MVPD
                    // initially, ensure that each applicable FSI SPI engine is
                    // initialized.
                    const std::vector<uint8_t> engines = {
                            i_target->getAttr<TARGETING::ATTR_SPI_EEPROM_VPD_PRIMARY_INFO>().engine,
                            i_target->getAttr<TARGETING::ATTR_SPI_EEPROM_VPD_BACKUP_INFO>().engine };

                    for(const auto engine : engines)
                    {
                        l_errl = SPI::spiInitEngine(i_target,engine);
                        if(l_errl != nullptr)
                        {
                            TRACFCOMP(g_trac_fsi,ERR_MRK "FSI::procPresenceDetect> "
                                "Unable to configure FSI SPI engine %d associated "
                                "with target 0x%.8X",
                                engine, TARGETING::get_huid(i_target) );
                            l_errl->collectTrace("FSI");
                            break;
                        }
                    }

                    if(l_errl)
                    {
                        break;
                    }
                }
            }
        }

        // Next look for valid Module VPD
        bool mvpd_present = false;
        bool check_for_mvpd = true;

#ifdef CONFIG_MVPD_READ_FROM_HW
        check_for_mvpd = fsi_present;
#endif

        if ((i_target != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL) &&
            (i_target != l_masterChip) &&
            !Util::isMultiprocSupported() ) //@FIXME-RTC:254475
        {
            check_for_mvpd = false;
        }

        if ( check_for_mvpd )
        {
             mvpd_present = VPD::mvpdPresent( i_target );
        }

#if defined(CONFIG_MVPD_READ_FROM_HW) && defined(CONFIG_MVPD_READ_FROM_PNOR)
        if( mvpd_present )
        {
            // Check if the VPD data in the PNOR matches the SEEPROM
            l_errl = VPD::ensureCacheIsInSync( i_target );
            if( l_errl )
            {
                // Save this plid to use later
                l_saved_plid = l_errl->plid();
                mvpd_present = false;

                TRACFCOMP(g_trac_fsi,ERR_MRK "FSI::procPresenceDetect> Error during ensureCacheIsInSync (MVPD)" );
                errlCommit( l_errl, FSI_COMP_ID );
            }
        }
        else
        {
            // Invalidate MVPD in the PNOR
            l_errl = VPD::invalidatePnorCache(i_target);
            if (l_errl)
            {
                TRACFCOMP( g_trac_fsi, "Error invalidating MVPD in PNOR" );
                errlCommit( l_errl, FSI_COMP_ID );
            }
        }
#endif

        // Finally compare the 2 methods
        if( fsi_present != mvpd_present )
        {
            TRACFCOMP(g_trac_fsi, ERR_MRK "FSI::procPresenceDetect> "
                      "FSI (=%d) and MVPD (=%d) do not agree for %.8X",
                      fsi_present, mvpd_present, TARGETING::get_huid(i_target));
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIPRES_PROCPRESENCEDETECT
             * @reasoncode   FSI::RC_FSI_MVPD_MISMATCH
             * @userdata1    HUID of processor
             * @userdata2[0:31]    FSI Presence
             * @userdata2[32:63]   MVPD Presence
             * @devdesc      presenceDetect> FSI and MVPD do not agree
             * @custdesc     FSI and MVPD do not agree
             */
            l_errl =
                    new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIPRES_PROCPRESENCEDETECT,
                                            FSI::RC_FSI_MVPD_MISMATCH,
                                            TARGETING::get_huid(i_target),
                                            TWO_UINT32_TO_UINT64(
                                                fsi_present,
                                                mvpd_present));

            // Callout the processor
            l_errl->addHwCallout( i_target,
                                  HWAS::SRCI_PRIORITY_LOW,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_NULL );


            // If there is a saved PLID, apply it to this error log
            if (l_saved_plid)
            {
                l_errl->plid(l_saved_plid);
            }

            // Add FFDC for the target to an error log
            getFsiFFDC( FFDC_PRESENCE_FAIL, l_errl, i_target);

            // Add FSI and VPD trace
            l_errl->collectTrace("FSI");
            l_errl->collectTrace("VPD");

            // Commit this log and move on
            errlCommit( l_errl,
                        FSI_COMP_ID );
        }

        bool present = fsi_present && mvpd_present;

        memcpy(io_buffer, &present, sizeof(present));
        io_buflen = sizeof(present);
    } while (0);

    return l_errl;
}

// Register as the presence detect for processor and memory buffers.
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PRESENT,
                      TARGETING::TYPE_PROC,
                      procPresenceDetect);

};
