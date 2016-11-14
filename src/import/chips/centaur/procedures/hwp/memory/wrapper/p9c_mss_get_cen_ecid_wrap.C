/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/wrapper/p9c_mss_get_cen_ecid_wrap.C $ */
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
/// @file p9c_mss_get_cen_ecid_wrap.C
/// @brief Wrapper for calling p9c_mss_get_cen_ecid hwp
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup:
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
//////

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
//#include <prcdUtils.H>

//----------------------------------------------------------------------
//  eCMD Includes
//----------------------------------------------------------------------
#include <ecmdClientCapi.H>
#include <ecmdDataBuffer.H>
#include <ecmdUtils.H>
#include <ecmdSharedUtils.H>
#include <fapi2ClientCapi.H>
#include <croClientCapi.H>
#include <fapi2.H>
#include <fapi2SharedUtils.H>

//----------------------------------------------------------------------
//  PROCEDURE Includes
//----------------------------------------------------------------------
#include <p9c_mss_get_cen_ecid.H>
#include <p9c_mss_get_cen_ecid_decode.H>


void help()
{
    printf("Help function for mss_get_cen_ecid\n");
    printf("   Default case, gets the ecid from a centaur\n");
    printf("   -h displays the help function\n");
    printf("   -user_defined allows the user to input 2 user defined, 64 bit hex values to be processed and displayed to the screen \n");
    printf("   -ecid0= corresponds to register 10000 and -ecid1= corresponds to 10001\n");
    printf("   -attr0= corresponds to ATTR_ECID[0] -attr1= corresponds to ATTR_ECID[1]\n");
    printf("   -user_ec= EC level of the chip in user mode: 10, 20, etc\n");
    printf("   eg -user_defined -ecid0=69AC004284086980 -ecid1=93C37C000000E8F4 \n");
    printf("   -csv print in comma separated values \n");
}

//ecid_user_struct::ecid_user_struct() { valid=0; i_checkL4CacheEnableUnknown=0; i_ecidContainsPortLogicBadIndication=0; i_ec=0; io_ecid[0]=0; io_ecid[1]=0; }

int main( int argc, char* argv[] )
{
    fapi2::ReturnCode f_rc    = fapi2::FAPI2_RC_SUCCESS;
    uint32_t rc;
    ecmdLooperData   node_looper;
    ecmdChipTarget   node_target;
    ecmdDataBuffer   data;
    char printStr[200];
    char user_ec[20] = "2.0";
    uint8_t ddr_port;
    uint8_t cache_enable_o;
    uint64_t ecid0 = 0, ecid1 = 0;
    uint8_t centaur_sub_revision_o;
    char* value;
    char* comment;
    ecid_user_struct user_data;
    user_data.valid = 0;
    user_data.i_user_defined = 0;

    //-------------------------------------------------------------------------------------------------
    //-h was selected, so print out the help screen and exit out.
    //-------------------------------------------------------------------------------------------------
    if (ecmdParseOption(&argc, &argv, "-h"))
    {
        help();
        return 1;
    }

    //parses the user -csv option
    if (ecmdParseOption(&argc, &argv, "-csv"))
    {
        user_data.i_user_defined |= CSV;
    }

    //parses the user -comment=
    if ((comment = ecmdParseOptionWithArgs(&argc, &argv, "-comment=")))
    {
        user_data.i_user_defined |= COMMENT;
    }

    //user defined input selected
    if (ecmdParseOption(&argc, &argv, "-user_defined"))
    {
        user_data.i_user_defined |= USER_INPUT_ECID;
        ecmdDataBufferBase scom(64);
        printf("User defined input selected.....\n");

        //processes the ecid value so it can be interpretted by the get_cen_ecid_lab function
        if ((value = ecmdParseOptionWithArgs(&argc, &argv, "-ecid0=")))
        {
            ecid0 = strtoull( value, NULL, 16 );
            scom.setDoubleWord(0, ecid0);
            scom.reverse();
            ecid0 = scom.getDoubleWord(0);
        }
        else if ((value = ecmdParseOptionWithArgs(&argc, &argv, "-attr0=")))
        {
            ecid0 = strtoull( value, NULL, 16 );
        }
        else
        {
            printf("ERROR: ecid0 not set! Exiting....\n");
            return 1;
        }

        if ((value = ecmdParseOptionWithArgs(&argc, &argv, "-ecid1=")))
        {
            ecid1 = strtoull( value, NULL, 16 );
            scom.setDoubleWord(0, ecid1);
            scom.reverse();
            ecid1 = scom.getDoubleWord(0);
        }
        else if ((value = ecmdParseOptionWithArgs(&argc, &argv, "-attr1=")))
        {
            ecid1 = strtoull( value, NULL, 16 );
        }
        else
        {
            printf("ERROR: ecid1 not set! Exiting....\n");
            return 1;
        }

        if ((value = ecmdParseOptionWithArgs(&argc, &argv, "-user_ec=")))
        {
            strcpy(user_ec, value);
        }
        else
        {
            printf("Using default EC level of %s\n", user_ec);
        }
    }

    //-------------------------------------------------------------------------------------------------
    // Pick up the name of the Procedure your looking to compile
    //-------------------------------------------------------------------------------------------------
    std::string myHWP = "mss_get_cen_ecid";
    std::string myInput = "";
    std::string myTarget = "centaur";
    std::string myTargetChiplet = "mba";

    //-------------------------------------------------------------------------------------------------
    // Load and initialize the eCMD Dll
    // If left NULL, which DLL to load is determined by the ECMD_DLL_FILE environment variable
    // If set to a specific value, the specified dll will be loaded
    //-------------------------------------------------------------------------------------------------
    rc = ecmdLoadDll("");

    if (rc)
    {
        return rc;
    }

    //-------------------------------------------------------------------------------------------------
    // This is needed if you're running a FAPI procedure from this eCMD procedure
    //-------------------------------------------------------------------------------------------------
    rc = fapi2InitExtension();

    if (rc)
    {
        printf("Error init fapi2 extension\n");
        return rc;
    }

    rc = croInitExtension();

    if (rc)
    {
        printf("Error init cro extension\n");
        return rc;
    }

    //-------------------------------------------------------------------------------------------------
    // Parse out common eCMD args like -p0, -c0, -coe, etc..
    // Any found args will be removed from arg list upon return
    //-------------------------------------------------------------------------------------------------
    rc = ecmdCommandArgs(&argc, &argv);

    if (rc)
    {
        return rc;
    }

    //-------------------------------------------------------------------------------------------------
    // Let's always print the dll info to the screen, unless in quiet mode
    //-------------------------------------------------------------------------------------------------
    if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
    {
        rc = ecmdDisplayDllInfo();

        if (rc)
        {
            return rc;
        }
    }

    char o_display_string[MSS_GET_CEN_ECID_DECODE_STRING_LENGTH];

    if(user_data.i_user_defined & USER_INPUT_ECID)
    {
        user_data.valid = 1;

        if(strcmp(user_ec, "1.0") == 0 || strcmp(user_ec, "1.00") == 0 ||
           strcmp(user_ec, "1.01") == 0 || strcmp(user_ec, "1.1") == 0 ||
           strcmp(user_ec, "1.10") == 0 || strcmp(user_ec, "10") == 0)
        {
            user_data.i_checkL4CacheEnableUnknown = 1;
            user_data.i_ecidContainsPortLogicBadIndication = 1;
            user_data.io_ec = 0x10;
        }
        else
        {
            user_data.i_checkL4CacheEnableUnknown = 0;
            user_data.i_ecidContainsPortLogicBadIndication = 0;
            user_data.io_ec = int((atof(user_ec) + 0.00001) * 0x10);
        }

        printf("User EC level is set to %s with major revision of %02x\n", user_ec, user_data.io_ec);

        fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fTarget;
        user_data.io_ecid[0] = ecid0;
        user_data.io_ecid[1] = ecid1;

        FAPI_EXEC_HWP(f_rc, p9c_mss_get_cen_ecid, fTarget, ddr_port, cache_enable_o, centaur_sub_revision_o, user_data );

        if (f_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ecmdOutputError("-----------------------------------------------------------\n");
            snprintf(printStr, 200, " 	 Procedure: %s  exited early with ...\n", myHWP.c_str());
            ecmdOutputError(printStr);
            snprintf(printStr, 200, " 	 Return code = %s 0x%08x \n", ecmdParseReturnCode(f_rc).c_str(), (uint32_t)f_rc);
            ecmdOutputError(printStr);
            ecmdOutputError("-----------------------------------------------------------\n");
            return 1;
        }

        FAPI_EXEC_HWP(f_rc, p9c_mss_get_cen_ecid_decode, ddr_port, cache_enable_o, centaur_sub_revision_o, user_data,
                      o_display_string );

        if (f_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            ecmdOutputError("-----------------------------------------------------------\n");
            snprintf(printStr, 200, " 	 Procedure: %s  exited early with ...\n", myHWP.c_str());
            ecmdOutputError(printStr);
            snprintf(printStr, 200, " 	 Return code = %s 0x%08x \n", ecmdParseReturnCode(f_rc).c_str(), (uint32_t)f_rc);
            ecmdOutputError(printStr);
            ecmdOutputError("-----------------------------------------------------------\n");
            return 1;
        }

        printf("%s\n", o_display_string);
    }
    else
    {
        //-------------------------------------------------------------------------------------------------
        // Loop over all all Centaur chips
        //-------------------------------------------------------------------------------------------------
        //  ecmdOutput("---------------------------------------------\n");
        //  sprintf(printStr, "Loop over all %s chips:\n", myTarget.c_str());
        //  ecmdOutput(printStr);
        //  ecmdOutput("---------------------------------------------\n");

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
            return rc;
        }

        // loop over specified configured nodes
        while (ecmdConfigLooperNext(node_target, node_looper))
        {
            ecmdLooperData cen_looper;
            ecmdChipTarget cen_target;

            if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
            {
                snprintf(printStr, sizeof(printStr), "Processing %s\n",
                         ecmdWriteTarget(node_target).c_str());
                ecmdOutput(printStr);
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
                return rc;
            }

            // loop over configured positions inside current node
            while(ecmdConfigLooperNext(cen_target, cen_looper))
            {
                if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE))
                {
                    snprintf(printStr, sizeof(printStr), "Going to call %s on %s\n",
                             myHWP.c_str(),
                             ecmdWriteTarget(cen_target).c_str());
                    ecmdOutput(printStr);
                }

                // invoke FAPI procedure core
                fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP> fapi_target(&cen_target);
                FAPI_EXEC_HWP(f_rc, p9c_mss_get_cen_ecid, fapi_target, ddr_port, cache_enable_o, centaur_sub_revision_o, user_data);
                rc = (uint32_t) f_rc;

                if (rc)
                {
                    snprintf(printStr, sizeof(printStr), "ERROR: %s FAPI call exited with bad return code = %s 0x%08x\n",
                             myHWP.c_str(),
                             ecmdParseReturnCode(rc).c_str(), rc);
                    ecmdOutputError(printStr);
                    return rc;
                }

                FAPI_EXEC_HWP(f_rc, p9c_mss_get_cen_ecid_decode, ddr_port, cache_enable_o, centaur_sub_revision_o, user_data,
                              o_display_string );
                rc = (uint32_t) f_rc;

                if (rc)
                {
                    snprintf(printStr, sizeof(printStr), "ERROR: %s FAPI call exited with bad return code = %s 0x%08x\n",
                             myHWP.c_str(),
                             ecmdParseReturnCode(rc).c_str(), rc);
                    ecmdOutputError(printStr);
                    return rc;
                }

                printf("%s\n", o_display_string);
            }
        }


//    ecmdOutput("---------------------------\n");
//    ecmdOutput("      Procedure is Done\n");
//    ecmdOutput("---------------------------\n");
    }

    //-----------------------------------------------------------------------------------------------
    // Unload the eCMD Dll, this should always be the last thing you do
    //-----------------------------------------------------------------------------------------------
    ecmdUnloadDll();

    return rc;
}




