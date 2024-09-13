/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_init_fsi.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
#include <list>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <fsi/fsiif.H>
#include <i2c/i2cif.H>
#include <i2c/tpmddif.H>
#include <initservice/taskargs.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <isteps/hwpisteperror.H>
#include <attributeenums.H>
#include <secureboot/trustedbootif.H>

//Targeting
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

// SBE
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>

using namespace TARGETING;
using namespace I2C;
using namespace TRUSTEDBOOT;

namespace ISTEP_06
{

/* @brief Find Processor I2C Engines Connected to TPMs
 *
 * This helper function loops through all of the TPMs in the system
 * blueprint and finds all of the Processors that serve as their I2C
 * Masters.  It then keeps track of which processor I2C engine(s) are
 * used.
 *
 * @return i2cEngineSelect - bit-wise enum indicating which processor engine(s)
 *                           were found
 */
i2cEngineSelect find_proc_i2c_engines_for_tpm ( void )
{
    int engineSelect = static_cast<int>(I2C_ENGINE_SELECT_NONE);

#ifdef CONFIG_TPMDD
    // Get all TPMs to setup our array
    TargetHandleList tpmList;
    getTPMs(tpmList,TPM_FILTER::ALL_IN_BLUEPRINT);

    TPMDD::tpm_info_t tpmData;
    for (auto tpm : tpmList)
    {
        memset(&tpmData, 0, sizeof(tpmData));
        errlHndl_t readErr = tpmReadAttributes(tpm,
                                               tpmData,
                                               TPMDD::TPM_LOCALITY_0);

        if (nullptr != readErr)
        {
            // We are just looking for configured TPMs here
            //  so we ignore any errors
            delete readErr;
            readErr = nullptr;
        }
        else
        {
            // If TPM is connected to a processor then keep track
            // of what engine needs to be reset
            if (tpmData.i2cTarget->getAttr<ATTR_TYPE>() == TYPE_PROC)
            {
                engineSelect |= static_cast<int>(i2cEngineToEngineSelect(tpmData.engine));
            }
        }
    }

    // There should only be 1 such bus per processor.  So if we found multiple
    // engines then we know that there are different proc/engine combinations
    // and we'd need a I2C reset intferace to support that.  This check here
    // makes sure we add that support when its necessary.
    assert(__builtin_popcount(engineSelect)==1, "find_proc_i2c_engines_for_tpm: Only one engine should be found: 0x%X", engineSelect);

#endif
    return static_cast<i2cEngineSelect>(engineSelect);
}

/* @brief Find Processor I2C Engines Connected to NVDIMMs
 *
 * This helper function loops through all of the DIMMs in the system,
 * checks if they are an NVDIMM, and finds all of the Processors
 * that serve as their I2C Masters.  It then keeps track of
 * which processor I2C engine(s) are used.
 *
 * @return i2cEngineSelect - bit-wise enum indicating which processor engine(s)
 *                           were found
 */
i2cEngineSelect find_proc_i2c_engines_for_nvdimms ( void )
{
    int engineSelect = static_cast<int>(I2C_ENGINE_SELECT_NONE);

#ifdef CONFIG_NVDIMM
    // Get all functional DIMMs
    //   Functional is valid this early in the boot because we only call this in MPIPL
    TargetHandleList dimmList;
    getAllLogicalCards(dimmList, TYPE_DIMM, true );

    for (auto dimm : dimmList)
    {
        if( isNVDIMM(dimm) )
        {
            ATTR_EEPROM_NV_INFO_type nvdimmData =
              dimm->getAttr<ATTR_EEPROM_NV_INFO>();

            TargetHandle_t proc_target = nullptr;
            proc_target = targetService().toTarget( nvdimmData.i2cMasterPath );

            // If NVDIMM is connected to a processor then keep track
            // of what engine needs to be reset
            assert( proc_target->getAttr<ATTR_TYPE>() == TYPE_PROC,
                    "find_proc_i2c_engines_for_nvdimms: Unsupported i2c master type for NVDIMM" );

            engineSelect |=
              static_cast<int>(i2cEngineToEngineSelect(nvdimmData.engine));
        }
    }

    // There should only be 1 or 0 such bus per processor.  So if we found multiple
    // engines then we know that there are different proc/engine combinations
    // and we'd need a I2C reset interface to support that.  This check here
    // makes sure we add that support when its necessary.
    assert(__builtin_popcount(engineSelect)<=1,
           "find_proc_i2c_engines_for_nvdimms: Only one engine should be found");

#endif

    if( engineSelect != I2C_ENGINE_SELECT_NONE )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Found NVDIMM i2c master at 0x%X",
                   engineSelect );
    }

    return static_cast<i2cEngineSelect>(engineSelect);
}


void* host_init_fsi( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    ISTEP_ERROR::IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi entry" );
    do
    {
        // process SBE PSU errors that might have occurred before fapi was
        // initialized
        SBEIO::SbePsu::getTheInstance().processEarlyError();

        l_err = FSI::initializeHardware( );
        if (l_err)
        {
            // This error should get returned
            l_stepError.addErrorDetails(l_err);
            errlCommit( l_err, ISTEP_COMP_ID );
            break;
        }

        // Reset all I2C Masters if FSP is not running
        if ( !INITSERVICE::spBaseServicesEnabled() )
        {
            l_err = i2cResetActiveMasters(I2C_ALL, false);
            if (l_err)
            {
                // Commit this error
                errlCommit( l_err, ISTEP_COMP_ID );
            }
        }
        // FSP cannot access I2C buses where the TPMs and PCIe Hot Plug
        // devices are due to a lack of a FSI connection to this bus.
        // Therefore, reset all host-mode I2C engines connected to these buses
        else
        {
            l_err = i2cResetActiveMasters(
                             I2C_PROC_HOST,
                             false,
                             find_proc_i2c_engines_for_tpm());
            if (l_err)
            {
                // Commit this error
                errlCommit( l_err, ISTEP_COMP_ID );
            }

            // This engine (specifically the Host logic) is used at runtime by the OCC.  We
            //   need to reset it back to a known state before we start using it again to
            //   avoid noticing leftover errors/activities (like interrupts).  Since this is
            //   a MPIPL, the hardware isn't reset unless we explicitly do it.
            TARGETING::Target* l_pTopLevel = NULL;
            TARGETING::targetService().getTopLevelTarget( l_pTopLevel );
            assert(l_pTopLevel, "host_init_fsi: no TopLevelTarget");
            if (l_pTopLevel->getAttr<TARGETING::ATTR_IS_MPIPL_HB>())
            {
                l_err = i2cResetActiveMasters(
                                I2C_PROC_HOST,
                                false,
                                find_proc_i2c_engines_for_nvdimms());
                if (l_err)
                {
                    // Commit this error
                    errlCommit( l_err, ISTEP_COMP_ID );
                }
            }
        }

    } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_init_fsi exit" );
    return l_stepError.getErrorHandle();
}

};
