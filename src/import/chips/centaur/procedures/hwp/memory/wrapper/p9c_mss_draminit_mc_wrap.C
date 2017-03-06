/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/wrapper/p9c_mss_draminit_mc_wrap.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

/// @file p9c_mss_draminit_mc_wrap.C
/// @brief Wrapper for calling p9c_mss_draminit_mc hwp
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup:
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <prcdUtils.H>
#include <croClientCapi.H>
#include <ecmdClientCapi.H>
#include <ecmdDataBuffer.H>
#include <ecmdUtils.H>
#include <ecmdSharedUtils.H>
#include <fapi2.H>
#include <fapi2ClientCapi.H>
#include <fapi2SharedUtils.H>
#include <p9c_mss_draminit_mc.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// display help message
void help()
{
    // procedure constants
    std::string PROCEDURE = "mss_draminit_mc_wrap";

    // build help message
    char outstr[256];
    snprintf(outstr, sizeof(outstr), "\nThis is the help text for the procedure %s \n",
             PROCEDURE.c_str());
    ecmdOutput(outstr);
    ecmdOutput("        [-h] [-k#] [-n#] [-s#] [-p#] [-d] [-quiet] [-verif]\n");
    ecmdOutput("\n");
    ecmdOutput("Additional options:\n");
    ecmdOutput("      -h                           Display this help message.\n");

    ecmdOutput("      -k#                          Specify which cage to act on (default = 0).\n");
    ecmdOutput("      -n#                          Specify which node to act on (default = 0).\n");
    ecmdOutput("      -s#                          Specify which slot to act on (default = 0).\n");
    ecmdOutput("      -p#                          Specify which chip position to act on (default = 0).\n");
    ecmdOutput("      -quiet                       Suppress printing of eCMD DLL/procedure information (default = false).\n");
    ecmdOutput("      -verif                       Run procedure in sim verification mode (default = false).\n");
    return;
}

// main function
int main(int argc, char* argv[])
{
    // procedure constants
    const std::string PROCEDURE = "mss_draminit_mc_wrap";

    // from prcdUtils
    extern bool GLOBAL_SIM_MODE;
    extern bool GLOBAL_VERIF_MODE;

    // flow/control variables
    uint32_t rc = ECMD_SUCCESS;
    fapi2::ReturnCode rc_fapi;
    ecmdDllInfo DLLINFO;
    ecmdLooperData node_looper;
    ecmdChipTarget node_target;
    char outstr[256];

    // required parameters & optional flags

    // load and initialize the eCMD Dll
    // if left NULL, which DLL to load is determined by the ECMD_DLL_FILE
    // environment variable if set to a specific value, the specified DLL
    // will be loaded
    rc = ecmdLoadDll("");

    if (rc)
    {
        return rc;
    }

    do
    {
        // initalize FAPI extension
        rc = fapi2InitExtension();

        if (rc)
        {
            ecmdOutputError("Error initializing FAPI extension!\n");
            break;
        }

        // establish if this is a simulation run or not
        rc = ecmdQueryDllInfo(DLLINFO);

        if (rc)
        {
            ecmdOutput("Error querying DLL!\n");
            break;
        }

        if (DLLINFO.dllEnv == ECMD_DLL_ENV_SIM)
        {
            GLOBAL_SIM_MODE = true;
        }

        // show help message
        if (ecmdParseOption(&argc, &argv, "-h"))
        {
            help();
            break;
        }

        // run procedure in sim verification mode
        if (ecmdParseOption(&argc, &argv, "-verif"))
        {
            GLOBAL_VERIF_MODE = true;
        }

        // parse out common eCMD args like -p0, -c0, -coe, etc..
        // any found args will be removed from arg list upon return
        rc = ecmdCommandArgs(&argc, &argv);

        if (rc)
        {
            ecmdOutputError("Error parsing eCMD arguments\n");
            break;
        }

        // unsupported arguments left over?
        if (argc != 1)
        {
            ecmdOutputError("Unknown/unsupported arguments specified!\n");
            help();
            rc = ECMD_INVALID_ARGS;
            break;
        }

        // print procedure information header
        if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
        {
            // print informational message
            snprintf(outstr, sizeof(outstr), "Procedure %s\n",
                     PROCEDURE.c_str());
            ecmdOutput(outstr);

            // always print the DLL info to the screen, unless in quiet mode
            rc = ecmdDisplayDllInfo();

            if (rc)
            {
                ecmdOutputError("Error displaying DLL info!");
                break;
            }
        }

        // configure looper to iterate over all nodes
        node_target.cageState   = ECMD_TARGET_FIELD_WILDCARD;
        node_target.nodeState   = ECMD_TARGET_FIELD_WILDCARD;
        node_target.slotState   = ECMD_TARGET_FIELD_UNUSED;
        node_target.posState    = ECMD_TARGET_FIELD_UNUSED;
        node_target.coreState   = ECMD_TARGET_FIELD_UNUSED;
        node_target.threadState = ECMD_TARGET_FIELD_UNUSED;
        rc = ecmdConfigLooperInit(node_target, ECMD_SELECTED_TARGETS_LOOP_DEFALL, node_looper);

        if (rc)
        {
            ecmdOutputError("Error initializing node looper!\n");
            break;
        }

        // loop over specified configured nodes
        while (ecmdConfigLooperNext(node_target, node_looper))
        {
            ecmdLooperData cen_looper;
            ecmdChipTarget cen_target;

            if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
            {
                snprintf(outstr, sizeof(outstr), "Processing %s\n",
                         ecmdWriteTarget(node_target).c_str());
                ecmdOutput(outstr);
            }

            cen_target.chipType = "cen";
            cen_target.chipTypeState = ECMD_TARGET_FIELD_VALID;

            cen_target.cage = node_target.cage;
            cen_target.node = node_target.node;

            cen_target.cageState   = ECMD_TARGET_FIELD_VALID;
            cen_target.nodeState   = ECMD_TARGET_FIELD_VALID;
            cen_target.slotState   = ECMD_TARGET_FIELD_WILDCARD;
            cen_target.posState    = ECMD_TARGET_FIELD_WILDCARD;
            cen_target.coreState   = ECMD_TARGET_FIELD_UNUSED;
            cen_target.threadState = ECMD_TARGET_FIELD_UNUSED;

            rc = ecmdConfigLooperInit(cen_target, ECMD_SELECTED_TARGETS_LOOP_DEFALL, cen_looper);

            if (rc)
            {
                ecmdOutputError("Error initializing chip looper!\n");
                break;
            }

            // loop over configured positions inside current node
            while(ecmdConfigLooperNext(cen_target, cen_looper))
            {
                if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
                {
                    snprintf(outstr, sizeof(outstr), "Going to call %s on %s\n",
                             PROCEDURE.c_str(),
                             ecmdWriteTarget(cen_target).c_str());
                    ecmdOutput(outstr);
                }

                // invoke FAPI procedure core
                fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fapi_target(&cen_target);
                FAPI_EXEC_HWP(rc_fapi,
                              p9c_mss_draminit_mc,
                              fapi_target);
                rc = (uint32_t) rc_fapi;

                if (rc)
                {
                    snprintf(outstr, sizeof(outstr), "ERROR: %s FAPI call exited with bad return code = %s 0x%08x\n",
                             PROCEDURE.c_str(),
                             ecmdParseReturnCode(rc).c_str(), rc);
                    ecmdOutputError(outstr);
                    break;
                }
            }

            if (rc)
            {
                break;
            }
        }

        if (rc)
        {
            break;
        }
    }
    while(0);

    ecmdUnloadDll();
    return rc;
}
