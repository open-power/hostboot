/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/wrapper/p10_getecid_wrap.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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

// Includes
#include <fapi2.H>
#include <fapi2ClientCapi.H>
#include <ecmdClientCapi.H>
#include <ecmdDataBuffer.H>
#include <ecmdSharedUtils.H>
#include <ecmdUtils.H>

#include <cstdlib>
#include <string>
#include <map>

#include <variable_buffer.H>
#include <variable_buffer_utils.H>
#include "p10_getecid.H"
#include "p10_scom_proc_c.H"

std::map<std::string, char> DT;  // decode table
std::map<std::string, std::string> DD10LEVEL;
std::map<std::string, std::string> DD20LEVEL;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Norm J. added
std::string
getCheckSum(std::string wafer)
{
    std::string rtn = wafer + "A0";
    int sum = 0;

    for(uint32_t i = 0; i < rtn.size(); i++)
    {
        sum = ((sum * 8) + (rtn[i] - 32)) % 59;
    }

    if (sum != 0 && rtn.size() >= 12)
    {
        int adjust = 59 - sum;
        rtn[11] += adjust & 7;
        adjust >>= 3;
        rtn[10] += adjust & 7;
    }

    return rtn;
}

//-----------------------------------------------------------------------------
uint32_t
p10_ecid_decodeEcidFuseString( ecmdDataBuffer fuseString, char* ecidString, char* DDlevelstring,
                               ecmdDataBuffer l_cfamid)
{
    uint32_t rc = ECMD_SUCCESS;

    ecmdDataBuffer waferID(60);
    uint8_t        Xloc;
    uint8_t        Yloc;
    uint8_t        majorEC;
    uint8_t        minorEC;
    ecmdDataBuffer subMinorEC(3);
    char           waferIdText[11];


    // CFAM IDs
    // P10

    const uint32_t P10_EC_DD10 = 0x120DA049;
    const uint32_t P10_EC_DD20 = 0x220DA049;

    std::string DD;

    *ecidString = 0;
    *DDlevelstring = 0;

    // --- the fuseString ---
    // bits   0:3  are the version, which should be all zeros to start with
    // bits   4:63 are the wafer id ( Eight 6 bit fields each containing a code )
    // bits  64:71 are the chip x location (7:0)
    // bits  72:79 are the chip y location (7:0)
    // bits  80:103 are used in a different chip location algorithm
    // bits 104:111 are the ECC over the whole 112 bits
    // bits 112:171 are lot id
    // bit  172 is unused
    // bits 173:176 are DD level
    // bits 177:191 are unused

    //***** Using the first 8 positions of the 10 character field, the last two will be programmed to "blanks" (all 1s) *****//
    fuseString.extract( waferID, 4, 48 );

    for( uint32_t offset = 0; offset < 48; offset += 6 )
    {
        // printf( "at offset %d value is %s which converts to %c\n", offset, waferID.genBinStr( offset, 6 ).c_str(), DT[waferID.genBinStr( offset, 6 ).c_str()] );
        waferIdText[(offset / 6)] = DT[waferID.genBinStr( offset, 6 ).c_str()];
    }

    waferIdText[8] = 0;

    fuseString.extract( &Xloc, 64, 8 );
    fuseString.extract( &Yloc, 72, 8 );

    std::string wafer = waferIdText;
    //***** 2 byte checksum: will not exist *****//
    //wafer = getCheckSum(wafer);

    // Get cfam 100A for chip ID
    // 0-3   Major EC
    // 4-7   Location Code (LOC)
    // 8-11  Minor EC
    // 12-19 Chip ID
    majorEC = l_cfamid.getByte(0) >> 4;
    minorEC = l_cfamid.getByte(1) >> 4;

    // if the sub-minor encoding is zero, no chip specific lookup is needed
    // just report the DD level as DD<major>.<minor>0
    DD = std::to_string(majorEC) + "." + std::to_string(minorEC);
    fuseString.extract( subMinorEC, 173, 3 );

    printf("sub minor EC: %02X \n", subMinorEC.getByte(0));

    if ( subMinorEC.isBitClear(0, 3) )
    {
        DD += "0";
    }
    else
    {
        std::map<std::string, std::string>* lookup = NULL;

        // look up chip specific meaning for subMinorEC
        if    (l_cfamid.getWord(0) == P10_EC_DD10 )
        {
            lookup = &DD10LEVEL;    // P10 DD1.0
        }

        if    (l_cfamid.getWord(0) == P10_EC_DD20 )
        {
            lookup = &DD20LEVEL;    // P10 DD2.0
        }

        if (lookup == NULL ||
            (*lookup)[subMinorEC.genBinStr( 0, 3 ).c_str()] == "")
        {
            printf( "Getecid not supported for this chip ID = %#x, update needed\n", l_cfamid.getWord(0) );
            DD += "?";
        }
        else
        {
            DD += (*lookup)[subMinorEC.genBinStr( 0, 3 )].c_str();
        }
    }

    sprintf( ecidString, "ECID: %s_%02d_%02d", wafer.c_str(), Xloc, Yloc );
    sprintf( DDlevelstring, "EC level: %s", DD.c_str() );

    return rc;
}


//-----------------------------------------------------------------------------
// Initialize the DT map like this cause I don't know how to do it otherwise.
//
void
ecid_initDecodeTable()
{
    DT.insert( std::pair<std::string, char> ( "000000" , '0' ) );
    DT.insert( std::pair<std::string, char> ( "000001" , '1' ) );
    DT.insert( std::pair<std::string, char> ( "000010" , '2' ) );
    DT.insert( std::pair<std::string, char> ( "000011" , '3' ) );
    DT.insert( std::pair<std::string, char> ( "000100" , '4' ) );
    DT.insert( std::pair<std::string, char> ( "000101" , '5' ) );
    DT.insert( std::pair<std::string, char> ( "000110" , '6' ) );
    DT.insert( std::pair<std::string, char> ( "000111" , '7' ) );
    DT.insert( std::pair<std::string, char> ( "001000" , '8' ) );
    DT.insert( std::pair<std::string, char> ( "001001" , '9' ) );
    DT.insert( std::pair<std::string, char> ( "001010" , 'A' ) );
    DT.insert( std::pair<std::string, char> ( "001011" , 'B' ) );
    DT.insert( std::pair<std::string, char> ( "001100" , 'C' ) );
    DT.insert( std::pair<std::string, char> ( "001101" , 'D' ) );
    DT.insert( std::pair<std::string, char> ( "001110" , 'E' ) );
    DT.insert( std::pair<std::string, char> ( "001111" , 'F' ) );
    DT.insert( std::pair<std::string, char> ( "010000" , 'G' ) );
    DT.insert( std::pair<std::string, char> ( "010001" , 'H' ) );
    DT.insert( std::pair<std::string, char> ( "010010" , 'I' ) );
    DT.insert( std::pair<std::string, char> ( "010011" , 'J' ) );
    DT.insert( std::pair<std::string, char> ( "010100" , 'K' ) );
    DT.insert( std::pair<std::string, char> ( "010101" , 'L' ) );
    DT.insert( std::pair<std::string, char> ( "010110" , 'M' ) );
    DT.insert( std::pair<std::string, char> ( "010111" , 'N' ) );
    DT.insert( std::pair<std::string, char> ( "011000" , 'O' ) );
    DT.insert( std::pair<std::string, char> ( "011001" , 'P' ) );
    DT.insert( std::pair<std::string, char> ( "011010" , 'Q' ) );
    DT.insert( std::pair<std::string, char> ( "011011" , 'R' ) );
    DT.insert( std::pair<std::string, char> ( "011100" , 'S' ) );
    DT.insert( std::pair<std::string, char> ( "011101" , 'T' ) );
    DT.insert( std::pair<std::string, char> ( "011110" , 'U' ) );
    DT.insert( std::pair<std::string, char> ( "011111" , 'V' ) );
    DT.insert( std::pair<std::string, char> ( "100000" , 'W' ) );
    DT.insert( std::pair<std::string, char> ( "100001" , 'X' ) );
    DT.insert( std::pair<std::string, char> ( "100010" , 'Y' ) );
    DT.insert( std::pair<std::string, char> ( "100011" , 'Z' ) );
    DT.insert( std::pair<std::string, char> ( "111101" , '-' ) );
    DT.insert( std::pair<std::string, char> ( "111110" , '.' ) );
    DT.insert( std::pair<std::string, char> ( "111111" , ' ' ) );
}

void
DD10level_decodetable()
{
    DD10LEVEL.insert( std::pair<std::string, std::string> ( "100" , "1 (G1 fix, Joachim approved)" ) );
    DD10LEVEL.insert( std::pair<std::string, std::string> ( "010" , "2 (V1 fix, decap short" ) );
    DD10LEVEL.insert( std::pair<std::string, std::string> ( "110" , "3 (Unused)" ) );
    DD10LEVEL.insert( std::pair<std::string, std::string> ( "001" , "4 (Unused)" ) );
}

void
DD20level_decodetable()
{
    DD20LEVEL.insert( std::pair<std::string, std::string> ( "100" , "2 (CA PCIE, N3/HB via fixes)" ) );
    DD20LEVEL.insert( std::pair<std::string, std::string> ( "010" , "3 (Unused)" ) );
    DD20LEVEL.insert( std::pair<std::string, std::string> ( "110" , "4 (Unused)" ) );
    DD20LEVEL.insert( std::pair<std::string, std::string> ( "001" , "5 (Unused)" ) );
}



//-----------------------------------------------------------------------------

static std::string REVISION = "1.3";

static std::string procedureName = "p10_getecid";

void help()
{
    char helpstr[256];
    sprintf(helpstr, "\nThis is the help text for the procedure %s: \n%s\n\n",
            procedureName.c_str(), REVISION.c_str());
    ecmdOutput("helpstr\n");
    ecmdOutput("Usage: p10_getecid_wrap [-h] [-k#] [-n#] [-s#] [-p#] [-quiet] [-verif]\n");
    ecmdOutput("  Option flags are:\n");
    ecmdOutput("      -h       Display this help message.\n");
    ecmdOutput("      -k#      Specify which cage to act on.\n");
    ecmdOutput("      -n#      Specify which node to act on.\n");
    ecmdOutput("      -s#      Specify which slot to act on.\n");
    ecmdOutput("      -p#      Specify which chip position to act on.\n");
    ecmdOutput("      -quiet   Suppress printing of eCMD DLL/procedure informational messages (default = false).\n");
    ecmdOutput("      -verif   Run procedure in sim verification mode (default = false).\n");
    ecmdOutput("      -o_fuseString      sets output for variable_buffer procedure argument o_fuseString to fusevalue \n");

}

int main(int argc,
         char* argv[])
{
    using namespace scomt;

    extern bool GLOBAL_SIM_MODE;
    extern bool GLOBAL_VERIF_MODE;
    uint64_t rc = ECMD_SUCCESS;
    fapi2::ReturnCode rc_fapi;
    ecmdLooperData looper; // Store internal Looper data
    ecmdChipTarget target; // This is the target to operate on
    ecmdDllInfo DLLINFO; // Needed?
    ecmdDataBuffer fuseString(192);
    char ecidString[100];
    char DDlevelstring[4];
    ecmdDataBuffer l_cfamid(32);;

    //
    // ------------------------------------
    // Load and initialize the eCMD Dll
    // If left NULL, which DLL to load is determined by the ECMD_DLL_FILE environment variable
    // If set to a specific value, the specified dll will be loaded
    // ------------------------------------
    rc = ecmdLoadDll("");

    if (rc)
    {
        ecmdOutput("p10_getecid_wrap: Error calling ecmdLoadDll.");
        ecmdUnloadDll();
        return rc;
    }

    ecid_initDecodeTable();
    DD10level_decodetable();

    //
    // This is needed if you're running a FAPI procedure from this eCMD procedure
    rc = fapi2InitExtension();

    if (rc)
    {
        ecmdOutput("p10_getecid_wrap: Error calling fapi2InitExtension.");
        ecmdUnloadDll();
        return rc;
    }

    //
    // establish if this is a simulation run or not
    //
    // NEEDED?????
    rc = ecmdQueryDllInfo(DLLINFO);

    if (rc)
    {
        ecmdOutput("p10_getecid_wrap: Error calling ecmdQueryDllInfo.");
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
        ecmdOutput("p10_getecid_wrap: Error calling ecmdCommandArgs.");
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
            ecmdOutput("p10_getecid_wrap: Error calling ecmdDisplayDllInfo.");
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
    target.threadState     = ECMD_TARGET_FIELD_UNUSED;
    rc = ecmdConfigLooperInit(target, ECMD_SELECTED_TARGETS_LOOP_DEFALL, looper);

    if (rc)
    {
        ecmdOutput("p10_getecid_wrap: Error calling ecmdConfigLooperInit.");
        ecmdUnloadDll();
        return rc;
    }

    ecmdOutput("Entering config looper\n");

    // loop over specified configured positions
    while (ecmdConfigLooperNext(target, looper))
    {
        // set up fapi target from an ecmd target
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>fapi_target(&target);
        fapi2::variable_buffer o_fuseString(192);
        ecmdDataBuffer fuseString(192);
        FAPI_EXEC_HWP(rc_fapi, p10_getecid, fapi_target, o_fuseString);
        rc = fapi2::bufferCopy(fuseString, o_fuseString);
        rc = (uint64_t)rc_fapi;

        if (rc)
        {
            ecmdOutput("p10_getecid_wrap: Error calling procedure p10_getecid.");
            ecmdUnloadDll();
            return rc;
        }
        else
        {
            uint64_t ecid0 = o_fuseString.get<uint64_t>(0);
            uint64_t ecid1 = o_fuseString.get<uint64_t>(1);
            uint64_t ecid2 = o_fuseString.get<uint64_t>(2);

            printf("\n%s\n", ecmdWriteTarget(target).c_str());
            printf("ecid0=%#lx\n", ecid0);
            printf("ecid1=%#lx\n", ecid1);
            printf("ecid2=%#lx\n", ecid2);

        }

        rc = getCfamRegister(target, proc::TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI, l_cfamid);

        if (rc)
        {
            ecmdOutput("Error from getCfamRegister (TP_TPVSB_FSI_W_FSI2PIB_CHIPID_FSI)\n");
            return rc;
        }

        rc = p10_ecid_decodeEcidFuseString( fuseString, ecidString, DDlevelstring, l_cfamid );

        if( rc )
        {
            printf( "ERROR: Could not decode the fuseString passed back by the p10_getecid fapi procedure\n" );
            return rc;
        }

        printf( "%s\n", ecidString );
        printf( "%s\n", DDlevelstring );


    }

    ecmdOutput("p10_getecid is Done\n");
    // Unload the eCMD Dll, this should always be the last thing you do
    ecmdUnloadDll();

    return rc;

}
