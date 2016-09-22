/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/base/service.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#include <secureboot/service.H>
#include <stdint.h>
#include <sys/mm.h>
#include <util/singleton.H>
#include <secureboot/secure_reasoncodes.H>
#include <config.h>
#include <devicefw/userif.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/targetservice.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <initservice/initserviceif.H>
#include <secureboot/settings.H>
#include <secureboot/header.H>
#include <sys/misc.h>
#include <kernel/console.H>
#include <console/consoleif.H>

#include "coreops.H"

extern trace_desc_t* g_trac_secure;

// Quick change for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using namespace ERRORLOG;
using namespace TARGETING;

namespace SECUREBOOT
{

/////////////////////////////////////////////////////////////////////
void* initializeBase(void* unused)
{
    errlHndl_t l_errl = NULL;

    do
    {

// Don't blind purge in VPO
#ifndef CONFIG_VPO_COMPILE

        // Load original secureboot header.
        if (enabled())
        {
            Singleton<Header>::instance().loadSecurely();

            // Unprotect the boot core so that we're not sent to ROM
            // code on error
            l_errl = unprotectCore();
            if(l_errl)
            {
                TRACFCOMP(g_trac_secure,ERR_MRK"Failed in call to "
                    "unprotectCore()");
                break;
            }
        }

        // Blind-purge lower portion of cache.
        l_errl = issueBlindPurge();
        if (l_errl)
        {
            break;
        }
#endif
        // Extend memory footprint into lower portion of cache.
        //   This can only fail is someone has already called to extend
        //   to post-secureboot state.  Major coding bug, so just assert.
        assert(0 == mm_extend(MM_EXTEND_POST_SECUREBOOT));

// Disable SecureROM in VPO
#ifndef CONFIG_VPO_COMPILE
        // Initialize the Secure ROM
        l_errl = initializeSecureROM();
        if (l_errl)
        {
            break;
        }
#endif
    } while(0);

    return l_errl;
}


/////////////////////////////////////////////////////////////////////
bool enabled()
{
    return Singleton<Settings>::instance().getEnabled();
}

/////////////////////////////////////////////////////////////////////
void secureSbeSeeproms( void )
{
    errlHndl_t err = NULL;
    uint64_t scomData = 0x0;
    size_t op_size = sizeof(scomData);
    size_t expected_size = op_size;

    TRACFCOMP( g_trac_secure, ENTER_MRK"secureSbeSeeproms()" );

    do{

        // Check if system is in secureboot mode before proceeding
        if ( !SECUREBOOT::enabled() )
        {
            // No need to secure/lock SBE Seeproms
            TRACFCOMP( g_trac_secure, "secureSbeSeeproms() - Not securing "
                       "SBE Seeproms since SECUREBOOT is not enabled" );
            break;
        }

        /*****************************************************************/
        /*  Iterate over all the functional processors and do for each:  */
        /*****************************************************************/
        TARGETING::TargetHandleList procList;
        TARGETING::getAllChips(procList,
                               TARGETING::TYPE_PROC,
                               true); // true: return all functional targets

        if( 0 == procList.size() )
        {
            TRACFCOMP( g_trac_secure, ERR_MRK"secureSbeSeeproms() - "
                       "No functional processors Found!" );
            break;
        }

        for(uint32_t i=0; i<procList.size(); i++)
        {
            TARGETING::Target * l_target=procList[i];

            // Read Security Vector/Register on the processor
            scomData = 0x0;
            err = deviceRead(
                      l_target,
                      &scomData,
                      op_size,
                      DEVICE_SCOM_ADDRESS(PROC_SECURITY_SWITCH_REGISTER));

            // Make sure op_size didn't change under the covers
            assert(op_size==expected_size, "Read of "
                   "PROC_SECURITY_SWITCH_REGISTER returned unexpected size");

            if( err )
            {
                TRACFCOMP( g_trac_secure,ERR_MRK"secureSbeSeeproms: Error "
                           "reading PROC SECURITY SWITCH REG (0x%.8X) from "
                           "Processor HUID=0x%.8X. Deconfiguring Proc and "
                           "Committing Error Log rc=0x%.4X eid=0x%.8X "
                           "plid=0x%.8X, but continuing",
                           PROC_SECURITY_SWITCH_REGISTER,
                           TARGETING::get_huid(l_target),
                           err->reasonCode(),
                           err->eid(),
                           err->plid());
            }
            else
            {
                // Successful read of register
                TRACUCOMP( g_trac_secure, "secureSbeSeeproms()"
                           "Processor HUID=0x%.8X: Reading "
                           "PROC SECURITY SWITCH REG (0x%.8X): 0x%.16llX",
                           TARGETING::get_huid(l_target),
                           PROC_SECURITY_SWITCH_REGISTER,
                           scomData);
            }

            /******************************************************/
            /*  Skip write to secure/lock SBEs if failed earlier  */
            /******************************************************/
            if ( err == NULL )
            {
                /**********************************************/
                /*  Secure the SBE Seeproms                   */
                /**********************************************/

                // Set bit
                scomData |= PROC_SECURITY_SWITCH_PROTECT_I2C_SEEPROM_MASK;

                // Write register
                err = deviceWrite(
                          l_target,
                          &scomData,
                          op_size,
                          DEVICE_SCOM_ADDRESS(
                              PROC_SECURITY_SWITCH_REGISTER));

                // Make sure op_size didn't change under the covers
                assert(op_size==expected_size, "Write of "
                      "PROC_SECURITY_SWITCH_REGISTER returned unexpected size");

                if ( err )
                {
                    TRACFCOMP( g_trac_secure,ERR_MRK"secureSbeSeeproms: Error "
                               "writing PROC SECURITY SWITCH REG (0x%.8X) from "
                               "Processor HUID=0x%.8X. Deconfiguring Proc and "
                               "Committing Error Log rc=0x%.4X eid=0x%.8X "
                               "plid=0x%.8X, but continuing",
                               PROC_SECURITY_SWITCH_REGISTER,
                               TARGETING::get_huid(l_target),
                               err->reasonCode(),
                               err->eid(),
                               err->plid());
                }
                else
                {
                    // Successful Write of register
                    TRACFCOMP( g_trac_secure, "secureSbeSeeproms(): Lock "
                               "Processor SBE HUID=0x%.8X: Wrote "
                               "PROC SECURITY SWITCH REG (0x%.8X): 0x%.16llX",
                               TARGETING::get_huid(l_target),
                               PROC_SECURITY_SWITCH_REGISTER,
                               scomData);
                }

            }

            // Process read or write error here
            if( err )
            {
                // This is a rare instance, but to be safe we're
                // terminating the IPL with this fail
                uint32_t l_errPlid = err->plid();

                err->collectTrace(SECURE_COMP_NAME);
                err->collectTrace(SBE_COMP_NAME);

                errlCommit( err, SECURE_COMP_ID );

                // Terminate IPL immediately
                INITSERVICE::doShutdown(l_errPlid);
            }

        } //end of Target for loop

    }while(0);

    TRACFCOMP( g_trac_secure, EXIT_MRK"secureSbeSeeproms()" );

    return;
}

bool getJumperState()
{
    return Singleton<Settings>::instance().getJumperState();
}

void handleSecurebootFailure(errlHndl_t &i_err)
{
    TRACFCOMP( g_trac_secure, ENTER_MRK"handleSecurebootFailure()");

    assert(i_err != NULL, "Secureboot Failure has a NULL error log")

    // Grab errlog reason code before committing.
    uint16_t l_rc = i_err->reasonCode();

#ifdef CONFIG_CONSOLE
    CONSOLE::displayf(SECURE_COMP_NAME, "Secureboot Failure plid = 0x%08X, rc = 0x%04X\n",
                      i_err->plid(), l_rc);
    CONSOLE::flush();
#endif
    printk("Secureboot Failure plid = 0x%08X, rc = 0x%04X\n",
           i_err->plid(),l_rc);

    // Add Verification callout
    i_err->addProcedureCallout(HWAS::EPUB_PRC_FW_VERIFICATION_ERR,
                               HWAS::SRCI_PRIORITY_HIGH);
    errlCommit(i_err, SECURE_COMP_ID);

    // Shutdown with Secureboot error status
    INITSERVICE::doShutdown(l_rc);
}

}  //namespace SECUREBOOT
