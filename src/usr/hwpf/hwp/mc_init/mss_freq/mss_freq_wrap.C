//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/mc_init/mss_freq/mss_freq_wrap.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//  eCMD Includes
//----------------------------------------------------------------------
#include <ecmdClientCapi.H>
#include <ecmdDataBuffer.H>
#include <ecmdUtils.H>
#include <ecmdSharedUtils.H>
#include <fapiClientCapi.H>
#include <croClientCapi.H>
#include <fapi.H>

const uint32_t BAD_ERROR_CODE           = 0xFFFF0000; 
//----------------------------------------------------------------------


int main( int argc, char *argv[] )
{
  uint32_t rc    = ECMD_SUCCESS;
  ecmdLooperData   looperdata;        // Store internal Looper data
  ecmdLooperData   looperdata2;
  ecmdChipTarget   target;              // This is the chip target to operate on
  bool             validPosFound = false;
  ecmdDataBuffer   data;
  char printStr[200];
  
  //------------------------------------
  // Load and initialize the eCMD Dll
  // If left NULL, which DLL to load is determined by the ECMD_DLL_FILE environment variable
  // If set to a specific value, the specified dll will be loaded
  //------------------------------------
  rc = ecmdLoadDll("");
  if (rc) return rc;

  /* This is needed if you're running a FAPI procedure via ecmdRunSo() */
  rc = fapiInitExtension(); if (rc) { printf("Error init fapi extension\n");return rc;}
  rc = croInitExtension(); if (rc) { printf("Error init cro extension\n");return rc;}

  //------------------------------------
  // Parse out common eCMD args like -p0, -c0, -coe, etc..
  // Any found args will be removed from arg list upon return
  //------------------------------------
  rc = ecmdCommandArgs(&argc, &argv);
  if (rc) return rc;

  /* Let's always print the dll info to the screen, unless in quiet mode */
  if (!ecmdGetGlobalVar(ECMD_GLOBALVAR_QUIETMODE)) {
    rc = ecmdDisplayDllInfo();
    if (rc) return rc;
  }


  /*******************************/
  /* Loop over all all Centaur chips  */
  /*******************************/
  ecmdOutput("---------------------------------------------\n");
  ecmdOutput("Loop over all Centaur chips:\n");
  ecmdOutput("---------------------------------------------\n");
  target.chipType          = "cen";
  target.chipTypeState     = ECMD_TARGET_FIELD_VALID;
  target.cageState         = ECMD_TARGET_FIELD_WILDCARD;
  target.nodeState         = ECMD_TARGET_FIELD_WILDCARD;
  target.slotState         = ECMD_TARGET_FIELD_WILDCARD;
  target.posState          = ECMD_TARGET_FIELD_WILDCARD; 
  target.chipUnitTypeState = ECMD_TARGET_FIELD_UNUSED;
  target.chipUnitNumState  = ECMD_TARGET_FIELD_UNUSED;
  target.threadState       = ECMD_TARGET_FIELD_UNUSED;

  rc = ecmdConfigLooperInit( target, ECMD_SELECTED_TARGETS_LOOP_DEFALL, looperdata); if (rc) return rc;

  std::list<uint64_t> myArgs;
  uint64_t arg1 = 0xBB;
  myArgs.push_back(arg1);
  arg1 = 0xDD;
  myArgs.push_back(arg1);

  while( ecmdConfigLooperNext( target, looperdata ) ){
    validPosFound = true;
    snprintf(printStr, 200, "Working on ecmdChipTarget = %s\n", ecmdWriteTarget(target).c_str()); 
    ecmdOutput(printStr);
    std::string myFileWithPath; 
    std::string myFile = "mss_ddr_phy_reset_x86.so";
    rc = fapiQueryFileLocation(FAPI_FILE_HWP, myFile, myFileWithPath); if (rc) return rc;
    rc = fapiHwpInvoker(target, myFileWithPath, "mss_ddr_phy_reset", myArgs);  if (rc) return rc;

    if (rc) {
       ecmdOutputError("-----------------------------------------------------------\n");
       ecmdOutputError("          mss_ddr_phy_reset exited early with ...\n");
       snprintf(printStr, 200,"          Return code = %s 0x%08x \n", ecmdParseReturnCode(rc).c_str(),rc);
       ecmdOutputError(printStr);
       ecmdOutputError("-----------------------------------------------------------\n");
       return rc;
     }
  } // end of loop through all configured Centaur chips
  
  if( rc == ECMD_SUCCESS && !validPosFound ){
    ecmdOutputError("**** ERROR : There were no Centaur chips configured so none were initialized.");
    rc= BAD_ERROR_CODE;
  }

  ecmdOutput("-------------------------------\n");
  ecmdOutput("      mss_ddr_phy_reset is Done\n");
  ecmdOutput("-------------------------------\n");
  //------------------------------------
  // Unload the eCMD Dll, this should always be the last thing you do
  //------------------------------------
  ecmdUnloadDll();

  return rc;
}



