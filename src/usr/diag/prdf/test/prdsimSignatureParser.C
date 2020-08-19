/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdsimSignatureParser.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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

#include "prdsimSignatureParser.H"
#include <prdfTrace.H>

namespace PRDF
{

static const char * STATUS_BAR = "=================================================";
static const char * SIG_ADD    = "==========     PRD Signature Add       ==========";
static const char * SIG_REPORT = "==========    PRD Signature Report     ==========";
static const char * SIG_SUM    = "==========    PRD Signature Summary    ==========";

/**
 *  @brief Returns a reference to the SimSignatureParser singleton
 *
 *  @return Reference to the SimSignatureParser
 */
/*
SimSignatureParser& getSimSignatureParser()
{
    return PRDF_GET_SINGLETON(theSimSignatureParser);
}
*/
void SimSignatureParser::Add(uint32_t i_chip, uint32_t i_sig)
//:iv_EnumMap(converter)
{
    PRDF_TRAC("%s", STATUS_BAR);
    PRDF_TRAC("%s", SIG_ADD);
    Signature signature(i_chip, i_sig);
    expectedSigList.push_back(signature);
    PRDF_TRAC("Error Signature   : 0x%08X 0x%08X", signature.chip, signature.code);
    PRDF_TRAC("%s", STATUS_BAR);
}

// --------------------------------------------------------------------

void SimSignatureParser::Report(uint32_t i_chip, uint32_t i_sig)
{
  PRDF_TRAC("%s", STATUS_BAR);
  PRDF_TRAC("%s", SIG_REPORT);

  // looking for the following in errlText
  //| PRD Signature            : 0x00811DE0 0x01010004                             |
  Signature signature(i_chip,i_sig);
  actualSigList.push_back(signature);
  const char * passOrFail = " Failed";

  if(expectedSigList.size() == 0)
  {
    PRDF_TRAC(" (W) No expected signature specified");
  }
  else
  {
    int thisIdx = actualSigList.size() - 1;
    int expectedIdx = thisIdx % expectedSigList.size();
    if(expectedSigList[expectedIdx] != actualSigList[thisIdx])
    {
        PRDF_ERR(" (S)FAIL! Expected 0x%08X 0x%08X", expectedSigList[expectedIdx].chip, expectedSigList[expectedIdx].code);
    }
    else
    {
      passOrFail = " Passed";
    }
  }

  PRDF_TRAC("Error Signature   : 0x%08X 0x%08X %s", signature.chip, signature.code, passOrFail);

  PRDF_TRAC("Description       : %s", Description(signature));
  PRDF_TRAC("%s", STATUS_BAR);
}

const char * SimSignatureParser::Description(const Signature & signature)
{
  // this is already in prdfLogParse.C - Need to make it comon TODO
  struct prdfErrorCodeDescription
  {
    uint32_t signature;
    const char * description;
  };

  static prdfErrorCodeDescription l_defaultErrorCodes[] =
  {
    {0xFFFFFFFF, "Undefined error code" },  //this must be first
    {0x0000DD00, "Assert failed in PRD"},
    {0x0000DD01, "Invalid attention type passed to PRD"},
    {0x0000DD02, "No active error bits found"},
    {0x0000DD03, "Chip connection lookup failure"},
    {0x0000DD05, "Internal PRD code"},
    {0x0000DD09, "Fail to access attention data from registry"},
    {0x0000DD11, "SRC Access failure"},
    {0x0000DD12, "HWSV Access failure"},
    {0x0000DD20, "Config error - no domains in system"},
    {0x0000DD21, "No active attentions found"},
    {0x0000DD23, "Unknown chip raised attention"},
    {0x0000DD24, "PRD Model is not built"},
    {0x0000DD27, "PrdRbsCallback failure"},
    {0x0000DD28, "PrdStartScrub failure"},
    {0x0000DD29, "PrdResoreRbs failure"},
    {0x0000DD81, "Multiple bits on in Error Register"},
    {0x0000DD90, "Scan comm access from Error Register failed"},
    {0x0000DD91, "Scan comm access from Error Register failed due to Power Fault"},
    {0x0000DDFF, "Special return code indicating Not to reset or mask FIR bits"},
    {0x00ED0000, "PLL error"},
    {0,nullptr} // this must exist and must be last
  };

  const char * result = nullptr;
//  PrdrErrSigTable & est = prdfGetErrorSigTable();
//  result = est[l_homt][signature.code];


  if(nullptr == result)
  {
      for(uint32_t i = 1; l_defaultErrorCodes[i].description != nullptr; ++i)
      {
            if(0x0000DD00 == (signature.code & 0x0000FF00))
            {
                if(l_defaultErrorCodes[i].signature ==
                   (signature.code & 0x0000FFFF))
                {
                    result = l_defaultErrorCodes[i].description;
                    break;
                }
            }
            else
            {
                if(l_defaultErrorCodes[i].signature == signature.code)
                {
                    result = l_defaultErrorCodes[i].description;
                    break;
                }
            }
      }
  }
  if(nullptr == result)
  {
    result = "(W) No description found";
  }
  return result;
}

// --------------------------------------------------------------------

bool SimSignatureParser::Summary(void)
{
  PRDF_TRAC("%s", STATUS_BAR);
  PRDF_TRAC("%s", SIG_SUM);
  // expected list rolls
  bool passed = true;
  if(expectedSigList.size() == 0)
  {
    PRDF_TRAC("(W) There were no expected signatures specified in the testcase");
  }
  else
  {
    int iterations = actualSigList.size();
    for(int i = 0; i < iterations; ++i)
    {
      int expectedIdx = i % expectedSigList.size();
      if(expectedSigList[expectedIdx] != actualSigList[i])
      {
        PRDF_ERR("(S)Iteration %d  signature: 0x%08X 0x%08X",
                 i, actualSigList[i].chip, actualSigList[i].code);

        PRDF_ERR(" Expected 0x%08X 0x%08X",
                 expectedSigList[expectedIdx].chip, expectedSigList[expectedIdx].code);

        passed = false;
      }
    }
  }
  if(passed)
  {
    PRDF_TRAC("All error signatures passed (E: %d, A: %d)", expectedSigList.size(), actualSigList.size());
  }
  else
  {
      if((actualSigList.size() == 0) && expectedSigList.size() > 0)
      {
          PRDF_ERR("There were no actual signatures reported");
          int iterations = expectedSigList.size();
          for(int i = 0; i < iterations; ++i)
          {
              PRDF_ERR(" Expected 0x%08X 0x%08X",
                       expectedSigList[i].chip, expectedSigList[i].code);
          }
      }
  }

  PRDF_TRAC("%s", STATUS_BAR);
  return passed;
}

} // End namespace PRDF
