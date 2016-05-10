/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2TestUtils.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
///
/// @file fapi2TestUtils.C
///
/// @brief FAPI2 utility functions
///
/// Note that platform code must provide the implementation.
///

#include <fapi2.H>
#include "fapi2TestUtils.H"


//This is subject to change, try to keep updated
#define NUM_EQS          6
#define NUM_EXS          12
#define NUM_CORES        24
#define NUM_L2S          12
#define NUM_L3S          12
#define NUM_MCS          4
#define NUM_MCAS         8
#define NUM_MCBISTS      2
#define NUM_PECS         3
#define NUM_PHBS         6
#define NUM_XBUS         2
#define NUM_OBUS         2
#define NUM_NV           2
#define NUM_PPES         21
#define NUM_PERVS        55
#define NUM_CAPPS        2
#define NUM_SBES         1

namespace fapi2
{

void generateTargets(TARGETING::Target* i_pMasterProcChip,
                                    TARGETING::Target* o_targetList[])
{
    for( uint64_t x = 0; x < NUM_TARGETS; x++ )
    {
        o_targetList[x] = NULL;
    }

    // Set up entity path for NIMBUS proc
    TARGETING::EntityPath l_epath;
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);

    //Setup EQs, COREs, and EXs
    for(int i = 0; i < NUM_EQS; i++)
    {
        l_epath.addLast(TARGETING::TYPE_EQ,i);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_EQ] =
                TARGETING::targetService().toTarget(l_epath);
            for(int j = 0; j < NUM_EXS; j++)
            {
                l_epath.addLast(TARGETING::TYPE_EX,i);
                if(TARGETING::targetService().toTarget(l_epath) != NULL)
                {
                    o_targetList[MY_EX] =
                        TARGETING::targetService().toTarget(l_epath);
                    for(int k = 0; k < NUM_CORES; k++)
                    {
                        l_epath.addLast(TARGETING::TYPE_CORE,k);
                        if(TARGETING::targetService().toTarget(l_epath)!=NULL)
                        {
                            o_targetList[MY_CORE] =
                              TARGETING::targetService().toTarget(l_epath);
                            break;
                        }
                        else
                        {
                            l_epath.removeLast();
                        }
                    }
                    break;
                }
                else
                {
                    l_epath.removeLast();
                }
            }
            break;
        }
        else
        {
          l_epath.removeLast();
        }
    }

    //Setup MCBISTs, MCSs, and MCAs
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_MCBISTS; i++)
    {
        l_epath.addLast(TARGETING::TYPE_MCBIST, i);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_MCBIST] =
              TARGETING::targetService().toTarget(l_epath);
            for(int j = 0; j < NUM_MCS; j++)
            {
                l_epath.addLast(TARGETING::TYPE_MCS, j);
                if(TARGETING::targetService().toTarget(l_epath) != NULL)
                {
                    o_targetList[MY_MCS] =
                      TARGETING::targetService().toTarget(l_epath);
                    for(int k = 0; k < NUM_MCAS; k++)
                    {
                        l_epath.addLast(TARGETING::TYPE_MCA,k);
                        if(TARGETING::targetService().toTarget(l_epath)!=NULL)
                        {
                            o_targetList[MY_MCA] =
                              TARGETING::targetService().toTarget(l_epath);
                            break;
                        }
                        else
                        {
                            l_epath.removeLast();
                        }
                    }
                    break;
                }
                else
                {
                  l_epath.removeLast();
                }
            }
            break;
        }
        else
        {
          l_epath.removeLast();
        }
    }

    //Setup PECs and PHBs
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_PECS; i++)
    {
        l_epath.addLast(TARGETING::TYPE_PEC, i);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_PEC] =
              TARGETING::targetService().toTarget(l_epath);
            for(int j = 0; j < NUM_PHBS; j++)
              {
                  l_epath.addLast(TARGETING::TYPE_PHB,j);
                  if(TARGETING::targetService().toTarget(l_epath) != NULL)
                  {
                    o_targetList[MY_PHB] =
                      TARGETING::targetService().toTarget(l_epath);
                    break;
                  }
                  else
                  {
                    l_epath.removeLast();
                  }
              }
              break;
        }
        else
        {
          l_epath.removeLast();
        }
    }

    //Setup XBUS
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_XBUS; i++)
    {
        // Nimbus doesn't have the 0th xbus, so index from 1 for now
        l_epath.addLast(TARGETING::TYPE_XBUS, i+1);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_XBUS] =
              TARGETING::targetService().toTarget(l_epath);
            break;
        }
        else
        {
          l_epath.removeLast();
        }
    }

    //Setup OBUSs
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_OBUS; i+=3)
    {
        l_epath.addLast(TARGETING::TYPE_OBUS, i);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_OBUS] =
              TARGETING::targetService().toTarget(l_epath);
            break;
        }
        else
        {
            l_epath.removeLast();
        }
    }

    //Setup NV
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_NV; i++)
    {
        l_epath.addLast(TARGETING::TYPE_NV, i);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_NV] =
              TARGETING::targetService().toTarget(l_epath);
            break;
        }
        else
        {
            l_epath.removeLast();
        }
    }

    //Setup PPEs
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_PPES; i++)
    {
        l_epath.addLast(TARGETING::TYPE_PPE, i);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_PPE] =
              TARGETING::targetService().toTarget(l_epath);
            break;
        }
        else
        {
            l_epath.removeLast();
        }
    }

    //Setup CAPPs
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_CAPPS; i++)
    {
        l_epath.addLast(TARGETING::TYPE_CAPP, i);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_CAPP] =
              TARGETING::targetService().toTarget(l_epath);
            break;
        }
        else
        {
            l_epath.removeLast();
        }
    }

    //Setup SBE
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_SBES; i++)
    {
        l_epath.addLast(TARGETING::TYPE_SBE, i);
        if(TARGETING::targetService().toTarget(l_epath) != NULL)
        {
            o_targetList[MY_SBE] =
              TARGETING::targetService().toTarget(l_epath);
            break;
        }
        else
        {
            l_epath.removeLast();
        }
    }

    //Setup PERVs
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_PERVS; i++)
    {
      l_epath.addLast(TARGETING::TYPE_PERV, i);
      if(TARGETING::targetService().toTarget(l_epath) != NULL)
      {
          o_targetList[MY_PERV] =
            TARGETING::targetService().toTarget(l_epath);
          break;
      }
      else
      {
        l_epath.removeLast();
      }
    }
}

} // End namespace fapi2
