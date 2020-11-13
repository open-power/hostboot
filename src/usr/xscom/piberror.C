/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/xscom/piberror.C $                                    */
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

/**
 *  @file piberror.C
 *
 *  @brief Utility functions to handle PIB errors
 */


#include <errl/errlentry.H>
#include <xscom/piberror.H>
#include <errl/errlmanager.H>
#include <hwas/common/hwasCallout.H>
#include <targeting/common/targetservice.H>
#include <scom/errlud_pib.H>

namespace PIB
{

/**
 * @brief Add callouts to an errorlog based on the type of PIB error could be a
 *             hardware or procedure callout
 */
void addFruCallouts(TARGETING::Target* i_target,
                    uint32_t  i_pibErrStatus,
                    uint64_t i_scomAddr,
                    errlHndl_t& io_errl)
{
   // add user details section to error log that describes the pib err
   SCOM::UdPibInfo(i_pibErrStatus).addToLog(io_errl);

   switch (i_pibErrStatus)
   {
     case  PIB::PIB_CHIPLET_OFFLINE: //b010
       //Offline should just be a code bug, but it seems that there are
       //  cases where bad hardware can also cause this problem
       //Since we assume code is good before going out, make the
       //  hw callout a higher priority
       io_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_HIGH,
                              HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_NULL );
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_MED);
       break;

     case  PIB::PIB_PARTIAL_GOOD: //b011
        io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                      HWAS::SRCI_PRIORITY_HIGH);
        // Add a low priority callout w/ delayed deconfig
        // to ensure the part gets deconfigured so the next
        // ipl has a better change of booting.
        io_errl->addHwCallout(i_target,
                              HWAS::SRCI_PRIORITY_LOW,
                              HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_NULL );
       break;

     case  PIB::PIB_INVALID_ADDRESS: //b100
       //Invalid Address should just be a code bug, but it seems that there
       //  are cases where bad hardware can also cause this problem
       //Since we assume code is good before going out, make the
       //  hw callout a higher priority
       io_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_HIGH,
                              HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_NULL );
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_MED);
       break;

     case PIB::PIB_PARITY_ERROR: //b110
     case PIB::PIB_TIMEOUT: //b111
       io_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_LOW,
                              HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_NULL );
       break;

     case  PIB::PIB_CLOCK_ERROR: //b101
        if (i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
        {
            // SENTINEL is a proc so use the OSC path
            io_errl->addClockCallout(i_target,
                                HWAS::OSCREFCLK_TYPE,
                                HWAS::SRCI_PRIORITY_MED);
        }
        else if (i_target->getAttr<TARGETING::ATTR_TYPE>() ==
                    TARGETING::TYPE_PROC)
        {
            //check for addresses inside the PCI range
            // note: ideally we could use the logic from scomtrans.C, but
            //  that is a lot of overhead for a few simple checks
            if( (   ((i_scomAddr & 0xFF000000) == 0x0D000000) //PCI0
                 || ((i_scomAddr & 0xFF000000) == 0x0E000000) //PCI1
                 || ((i_scomAddr & 0xFF000000) == 0x0F000000))//PCI2
                && ((i_scomAddr & 0x00FF0000) != 0x000F0000) )//skip perv regs
            {
                io_errl->addClockCallout(i_target,
                                         HWAS::OSCPCICLK_TYPE,
                                         HWAS::SRCI_PRIORITY_MED);
            }
            //for everything else blame the ref clock
            else
            {
                io_errl->addClockCallout(i_target,
                                         HWAS::OSCREFCLK_TYPE,
                                         HWAS::SRCI_PRIORITY_MED);
            }
        }
        else if (i_target->getAttr<TARGETING::ATTR_TYPE>() ==
                    TARGETING::TYPE_MEMBUF)
        {
            io_errl->addClockCallout(i_target,
                                     HWAS::MEMCLK_TYPE,
                                     HWAS::SRCI_PRIORITY_MED);
        }
        else // for anything else, just blame the refclock
        {
            io_errl->addClockCallout(i_target,
                                HWAS::OSCREFCLK_TYPE,
                                HWAS::SRCI_PRIORITY_MED);
        }
        // Add a low priority callout w/ delayed deconfig
        // to ensure the part gets deconfigured so the next
        // ipl has a better change of booting.
        io_errl->addHwCallout(i_target,
                              HWAS::SRCI_PRIORITY_LOW,
                              HWAS::DELAYED_DECONFIG,
                              HWAS::GARD_NULL );
       break;

     default:
       // Anything else would most likely be a code bug
       io_errl->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_HIGH);
        // Make sure we aren't calling the part out if there wasn't actually
        // a PIB error and this function was mistakenly called
        if(i_pibErrStatus != PIB_NO_ERROR)
        {
            // Add a low priority callout w/ delayed deconfig
            // to ensure the part gets deconfigured so the next
            // ipl has a better change of booting.
            io_errl->addHwCallout(i_target,
                                  HWAS::SRCI_PRIORITY_LOW,
                                  HWAS::DELAYED_DECONFIG,
                                  HWAS::GARD_NULL );
        }
       break;
   }


}

} // end of namespace
