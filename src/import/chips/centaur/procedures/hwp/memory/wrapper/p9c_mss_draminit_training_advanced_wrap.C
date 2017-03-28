/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/wrapper/p9c_mss_draminit_training_advanced_wrap.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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

#include <prcdUtils.H>
#include <croClientCapi.H>
#include <ecmdClientCapi.H>
#include <ecmdUtils.H>
#include <ecmdSharedUtils.H>
#include <fapi2.H>
#include <fapi2ClientCapi.H>
#include <fapi2SharedUtils.H>
#include <string>
#include <sstream>

#include <p9c_mss_draminit_training_advanced.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

// display help message
void help()
{
    // procedure constants
    const std::string PROCEDURE = "mss_draminit_training_advanced_wrap";
    const std::string REVISION  = "$Revision: 1.1 $";
    // build help message
    char outstr[200];
    snprintf(outstr, sizeof(outstr),
             "\nThis is the help text for the procedure %s (%s)\n", PROCEDURE.c_str(),
             REVISION.c_str());
    ecmdOutput(outstr);
    snprintf(outstr, sizeof(outstr), "Syntax: %s\n", PROCEDURE.c_str());
    ecmdOutput(outstr);
    ecmdOutput("        [-h] [-k#] [-n#] [-s#] [-p#] [-verif]\n");
    ecmdOutput("\n");
    ecmdOutput("Additional options:\n");
    ecmdOutput("      -h                           This help\n");
    ecmdOutput("\n");
}


// main function
int main(int argc, char* argv[])
{
    // procedure constants
    const std::string PROCEDURE = "mss_draminit_training_advanced_wrap";
    const std::string REVISION  = "$Revision: 1.1 $";

    // from prcdUtils
    extern bool GLOBAL_SIM_MODE;
    extern bool GLOBAL_VERIF_MODE;

    // flow/control variables
    uint32_t rc = ECMD_SUCCESS;
    ecmdDllInfo DLLINFO;
    ecmdLooperData looper;
    ecmdChipTarget target;
    bool valid_pos_found = false;
    char outstr[200];

    fapi2::ReturnCode rc_fapi(fapi2::FAPI2_RC_SUCCESS);


    //-----------------------------------------------------------------------------------------
    // load and initialize the eCMD Dll
    // if left NULL, which DLL to load is determined by the ECMD_DLL_FILE environment variable
    // if set to a specific value, the specified DLL will be loaded
    //-----------------------------------------------------------------------------------------
    rc = ecmdLoadDll("");

    if (rc)
    {
        return rc;
    }

    //-----------------------------------------------------------------------------------------
    // This is needed if you're running a FAPI procedure from this eCMD procedure
    //-----------------------------------------------------------------------------------------

    // initalize FAPI2 extension
    rc = fapi2InitExtension();

    if (rc)
    {
        ecmdOutputError("Error initializing FAPI2 extension!\n");
        return rc;
    }



    // establish if this is a simulation run or not
    rc = ecmdQueryDllInfo(DLLINFO);

    if (rc)
    {
        ecmdUnloadDll();
        return rc;
    }

    if (DLLINFO.dllEnv == ECMD_DLL_ENV_SIM)
    {
        GLOBAL_SIM_MODE = true;
    }

    //-------------------------------------------------------------------------------------------------
    // Parse out user options (excluding -pX, -cX, -coe, -debug, etc
    // E.G., ecmdRunHwp.x86 -testmode
    //-------------------------------------------------------------------------------------------------
    if (ecmdParseOption(&argc, &argv, "-h"))
    {
        help();
        ecmdUnloadDll();
        return rc;
    }


    // run procedure in sim verification mode
    if (ecmdParseOption(&argc, &argv, "-verif"))
    {
        GLOBAL_VERIF_MODE = true;
    }


    //-------------------------------------------------------------------------------------------------
    // Parse out common eCMD args like -p0, -c0, -coe, etc..
    // Any found args will be removed from arg list upon return
    //-------------------------------------------------------------------------------------------------
    rc = ecmdCommandArgs(&argc, &argv);

    if (rc)
    {
        ecmdUnloadDll();
        return rc;
    }

    // unsupported arguments left over?
    if (argc != 1)
    {
        ecmdOutputError("Unknown/unsupported arguments specified!\n");
        help();
        ecmdUnloadDll();
        return ECMD_INVALID_ARGS;
    }

    //-------------------------------------------------------------------------------------------------
    // Let's always print the dll info to the screen, unless in quiet mode
    //-------------------------------------------------------------------------------------------------

    if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
    {
        // print informational message
        snprintf(outstr, sizeof(outstr), "Procedure %s: %s\n", PROCEDURE.c_str(),
                 REVISION.c_str());
        ecmdOutput(outstr);

        // always print the DLL info to the screen, unless in quiet mode
        rc = ecmdDisplayDllInfo();

        if (rc)
        {
            return rc;
        }
    }

    //-------------------------------------------------------------------------------------------------
    // Loop over all all pu chips
    //-------------------------------------------------------------------------------------------------
    target.chipType      = "centaur";     // "p9n"; // "pu";
    target.chipTypeState = ECMD_TARGET_FIELD_VALID;
    target.chipUnitType  = "mba";   // mca; // "mcs";     // "mba"; // "mcbist";
    target.chipUnitTypeState = ECMD_TARGET_FIELD_VALID;
    target.cageState     = ECMD_TARGET_FIELD_WILDCARD;
    target.nodeState     = ECMD_TARGET_FIELD_WILDCARD;
    target.slotState     = ECMD_TARGET_FIELD_WILDCARD;
    target.posState      = ECMD_TARGET_FIELD_WILDCARD;
    target.threadState   = ECMD_TARGET_FIELD_UNUSED;
    target.chipUnitNumState = ECMD_TARGET_FIELD_WILDCARD;

    rc = ecmdConfigLooperInit(target, ECMD_SELECTED_TARGETS_LOOP_DEFALL, looper);

    if (rc)
    {
        ecmdOutputError("Error initializing proc chip looper!\n");
        ecmdUnloadDll();
        return rc;
    }

    while (ecmdConfigLooperNext(target, looper))
    {
        if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
        {
            snprintf(outstr, sizeof(outstr),
                     "Going to call %s on proc k%d:n%d:s%d:p%02d chip type = %s %s\n",
                     PROCEDURE.c_str(), target.cage, target.node, target.slot, target.pos,
                     target.chipType.c_str(),
                     target.chipUnitType.c_str() );
            ecmdOutput(outstr);
        }

        // EXAMPLE setting up a fapi2::Target from an ecmdChipTarget
        fapi2::Target<fapi2::TARGET_TYPE_MBA> fapi_target(&target);

        // invoke FAPI procedure core
        FAPI_EXEC_HWP(rc_fapi, p9c_mss_draminit_training_advanced, fapi_target);
        rc = (uint64_t) rc_fapi;

        if (rc)
        {
            snprintf(outstr, sizeof(outstr),
                     "ERROR: %s FAPI call exited with return code = %s 0x%08x \n",
                     PROCEDURE.c_str(), ecmdParseReturnCode(rc).c_str(), rc);
            ecmdOutputError(outstr);
            ecmdUnloadDll();
            return rc;
        }

        // mark that valid position has been found
        valid_pos_found = true;
    }

    // check that a valid target was found
    if (rc == ECMD_SUCCESS && !valid_pos_found)
    {
        ecmdOutputError("No valid targets found!\n");
        ecmdUnloadDll();
        return ECMD_TARGET_NOT_CONFIGURED;
    }

    prcdInfoMessage("----------------------------------------\n");
    prcdInfoMessage("  mss_draminit_training_advanced is done\n");
    prcdInfoMessage("----------------------------------------\n");

    //-----------------------------------------------------------------------------------------------
    // Unload the eCMD Dll, this should always be the last thing you do
    //-----------------------------------------------------------------------------------------------

    ecmdUnloadDll();
    return rc;
}
