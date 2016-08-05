/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/wrapper/p9_pstate_parameter_block_wrap.C $ */
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

//## auto_generated

// Includes
#include <fapi2.H>
#include <fapi2ClientCapi.H>
#include <ecmdClientCapi.H>
#include <ecmdSharedUtils.H>
#include <ecmdUtils.H>

#include <p9_pstate_parameter_block.H>

static std::string procedureName = "p9_pstate_parameter_block";

void help()
{
    char helpstr[256];
    sprintf(helpstr, "\nThis is the help text for the procedure %s: \n\n",
            procedureName.c_str());
    ecmdOutput("helpstr\n");
    ecmdOutput("Usage: p9_pstate_parameter_block_wrap [-h] [-k#] [-n#] [-s#] [-p#] [-quiet] [-verif]\n");
    ecmdOutput("  Option flags are:\n");
    ecmdOutput(" -h       Display this help message.\n");
    ecmdOutput(" -k#      Specify which cage to act on.\n");
    ecmdOutput(" -n#      Specify which node to act on.\n");
    ecmdOutput(" -s#      Specify which slot to act on.\n");
    ecmdOutput(" -p#      Specify which chip position to act on.\n");
    ecmdOutput(" -quiet   Suppress printing of eCMD DLL/procedure informational messages (default = false).\n");
    ecmdOutput(" -verif   Run procedure in sim verification mode (default = false).\n");

}

int main(int argc,
         char* argv[])
{
    extern bool GLOBAL_SIM_MODE;
    extern bool GLOBAL_VERIF_MODE;
    uint64_t rc = ECMD_SUCCESS;
    fapi2::ReturnCode rc_fapi;
    ecmdLooperData looper; // Store internal Looper data
    ecmdChipTarget target; // This is the target to operate on
    ecmdDllInfo DLLINFO; //

    // PState super structure
    PstateSuperStructure io_pss;
    //
    // ------------------------------------
    // Load and initialize the eCMD Dll
    // If left NULL, which DLL to load is determined by the ECMD_DLL_FILE
    // environment variable
    // If set to a specific value, the specified dll will be loaded
    // ------------------------------------
    rc = ecmdLoadDll("");

    if (rc)
    {
        ecmdOutput("p9_pstate_parameter_block_wrap: Error calling ecmdLoadDll.");
        ecmdUnloadDll();
        return rc;
    }

    //
    // This is needed if you're running a FAPI procedure from this eCMD procedure
    rc = fapi2InitExtension();

    if (rc)
    {
        ecmdOutput("p9_pstate_parameter_block_wrap: Error calling fapi2InitExtension.");
        ecmdUnloadDll();
        return rc;
    }

    //
    // establish if this is a simulation run or not
    //
    rc = ecmdQueryDllInfo(DLLINFO);

    if (rc)
    {
        ecmdOutput("p9_pstate_parameter_block_wrap: Error calling ecmdQueryDllInfo.");
        ecmdUnloadDll();
        return rc;
    }

    if (DLLINFO.dllEnv == ECMD_DLL_ENV_SIM)
    {
        GLOBAL_SIM_MODE = true;
    }

    // Parse out user options (excluding -pX, -cX, -coe, -debug, etc
    if (ecmdParseOption(&argc, &argv, "-h"))
    {
        help();
        ecmdUnloadDll();
        return 1;
    }

    // run procedure in sim verification mode
    if (ecmdParseOption(&argc, &argv, "-verif"))
    {
        GLOBAL_VERIF_MODE = true;
    }

    //
    // -------------------------------------------------------------------------------------------------
    // Parse out common eCMD args like -p0, -c0, -coe, etc..
    // Any found args will be removed from arg list upon return
    // -------------------------------------------------------------------------------------------------
    rc = ecmdCommandArgs(&argc, &argv);

    if (rc)
    {
        ecmdOutput("p9_pstate_parameter_block_wrap: Error calling ecmdCommandArgs.");
        ecmdUnloadDll();
        return rc;
    }

    // unsupported arguments left over?
    if (argc != 1)
    {
        ecmdOutput("Unknown/unsupported arguments specified!\n");
        help();
        ecmdUnloadDll();
        return ECMD_INVALID_ARGS;
    }

    //
    // always print the dll info to the screen, unless in quiet mode
    if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
    {
        rc = ecmdDisplayDllInfo();

        if (rc)
        {
            ecmdOutput("p9_pstate_parameter_block_wrap: Error calling ecmdDisplayDllInfo.");
            ecmdUnloadDll();
            return rc;
        }
    }

    target.chipType      = "pu";
    target.chipTypeState = ECMD_TARGET_FIELD_VALID;
    target.chipUnitTypeState     = ECMD_TARGET_FIELD_UNUSED;
    target.chipUnitNumState     = ECMD_TARGET_FIELD_UNUSED;
    target.cageState     = ECMD_TARGET_FIELD_WILDCARD;
    target.nodeState     = ECMD_TARGET_FIELD_WILDCARD;
    target.slotState     = ECMD_TARGET_FIELD_WILDCARD;
    target.chipUnitNumState     = ECMD_TARGET_FIELD_WILDCARD;
    target.coreState     = ECMD_TARGET_FIELD_UNUSED;
    target.threadState     = ECMD_TARGET_FIELD_UNUSED;
    rc = ecmdConfigLooperInit(target, ECMD_SELECTED_TARGETS_LOOP_DEFALL, looper);

    if (rc)
    {
        ecmdOutput("p9_pstate_parameter_block_wrap: Error calling ecmdConfigLooperInit.");
        ecmdUnloadDll();
        return rc;
    }

    ecmdOutput("Entering config looper\n");

    // loop over specified configured positions
    while (ecmdConfigLooperNext(target, looper))
    {
        // set up fapi target from an ecmd target
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>fapi_target(&target);

        //Run it with the COMPUTE command
        FAPI_EXEC_HWP(rc_fapi, p9_pstate_parameter_block, fapi_target, &io_pss);
        rc = (uint64_t)rc_fapi;

        if (rc)
        {
            ecmdOutput("p9_pstate_parameter_block_wrap: Error calling procedure p9_pstate_parameter_block");
            ecmdUnloadDll();
            return rc;
        }

    }

    ecmdOutput("p9_pstate_parameter_block is Done\n");
    // Unload the eCMD Dll, this should always be the last thing you do
    ecmdUnloadDll();

    return rc;

}
