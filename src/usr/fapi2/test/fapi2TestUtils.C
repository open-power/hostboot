/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2TestUtils.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#define NUM_EXS          2
#define NUM_CORES        2
#define NUM_MCS          2
#define NUM_MCAS         2
#define NUM_MCBISTS      2
#define NUM_PECS         3
#define NUM_PHBS         6
#define NUM_XBUS         2
#define NUM_OBUS         2
#define NUM_OBUS_BRICK   3
#define NUM_PPES         21
#define NUM_PERVS        55
#define NUM_CAPPS        2
#define NUM_SBES         1
#define NUM_MC           2
#define NUM_MI           2
#define NUM_DMI          2
#define NUM_OMI          2
#define NUM_OMIC         3
#define NUM_MCC          2

namespace fapi2
{

void generateTargets(TARGETING::Target* i_pMasterProcChip,
                                    TARGETING::Target* o_targetList[])
{
    for( uint64_t x = 0; x < NUM_TARGETS; x++ )
    {
        o_targetList[x] = nullptr;
    }

    // Set up entity path for proc
    TARGETING::EntityPath l_epath;
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);

    o_targetList[MY_PROC] = i_pMasterProcChip;

    //Setup EQs, COREs, and EXs
    for(int i = 0; i < NUM_EQS; i++)
    {
        l_epath.addLast(TARGETING::TYPE_EQ,i);
        if(TARGETING::targetService().toTarget(l_epath) != nullptr)
        {
            o_targetList[MY_EQ] =
                TARGETING::targetService().toTarget(l_epath);
            for(int j = 0; j < NUM_EXS; j++)
            {
                l_epath.addLast(TARGETING::TYPE_EX,i);
                if(TARGETING::targetService().toTarget(l_epath) != nullptr)
                {
                    o_targetList[MY_EX] =
                        TARGETING::targetService().toTarget(l_epath);
                    for(int k = 0; k < NUM_CORES; k++)
                    {
                        l_epath.addLast(TARGETING::TYPE_CORE,k);
                        if(TARGETING::targetService().toTarget(l_epath)!=nullptr)
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

    if (TARGETING::MODEL_NIMBUS ==
                i_pMasterProcChip->getAttr<TARGETING::ATTR_MODEL>())
    {
        //Setup MCBISTs, MCSs, and MCAs
        i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
        for(int i = 0; i < NUM_MCBISTS; i++)
        {
            l_epath.addLast(TARGETING::TYPE_MCBIST, i);
            if(TARGETING::targetService().toTarget(l_epath) != nullptr)
            {
                o_targetList[MY_MCBIST] =
                  TARGETING::targetService().toTarget(l_epath);
                for(int j = 0; j < NUM_MCS; j++)
                {
                    l_epath.addLast(TARGETING::TYPE_MCS, j);
                    if(TARGETING::targetService().toTarget(l_epath) != nullptr)
                    {
                        o_targetList[MY_MCS] =
                          TARGETING::targetService().toTarget(l_epath);
                        for(int k = 0; k < NUM_MCAS; k++)
                        {
                            l_epath.addLast(TARGETING::TYPE_MCA,k);
                            if(TARGETING::targetService().toTarget(l_epath)!=nullptr)
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
    }
    else if (TARGETING::MODEL_CUMULUS ==
                i_pMasterProcChip->getAttr<TARGETING::ATTR_MODEL>())
    {
        //Setup MC, MI, DMI
        i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
        for(int i = 0; i < NUM_MC; i++)
        {
            l_epath.addLast(TARGETING::TYPE_MC, i);
            if(TARGETING::targetService().toTarget(l_epath) != nullptr)
            {
                o_targetList[MY_MC] =
                  TARGETING::targetService().toTarget(l_epath);
                for(int j = 0; j < NUM_MI; j++)
                {
                    l_epath.addLast(TARGETING::TYPE_MI, j);
                    if(TARGETING::targetService().toTarget(l_epath) != nullptr)
                    {
                        o_targetList[MY_MI] =
                          TARGETING::targetService().toTarget(l_epath);
                        for(int k = 0; k < NUM_DMI; k++)
                        {
                            l_epath.addLast(TARGETING::TYPE_DMI,k);
                            if(TARGETING::targetService().toTarget(l_epath)!=nullptr)
                            {
                                o_targetList[MY_DMI] =
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
    }
    else if (TARGETING::MODEL_AXONE ==
                i_pMasterProcChip->getAttr<TARGETING::ATTR_MODEL>())
    {
        //Setup MC, MI, MCC, OMI, and OMIC
        i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
        for(int i = 0; i < NUM_MC; i++)
        {
            l_epath.addLast(TARGETING::TYPE_MC, i);
            if(TARGETING::targetService().toTarget(l_epath) != nullptr)
            {
                o_targetList[MY_MC] =
                TARGETING::targetService().toTarget(l_epath);
                for(int j = 0; j < NUM_MI; j++)
                {
                    l_epath.addLast(TARGETING::TYPE_MI, j);
                    if(TARGETING::targetService().toTarget(l_epath) != nullptr)
                    {
                        o_targetList[MY_MI] =
                        TARGETING::targetService().toTarget(l_epath);
                        for(int k = 0; k < NUM_MCC; k++)
                        {
                            l_epath.addLast(TARGETING::TYPE_MCC,k);
                            if(TARGETING::targetService().toTarget(l_epath)!=nullptr)
                            {
                                o_targetList[MY_MCC] =
                                TARGETING::targetService().toTarget(l_epath);
                                for(int l = 0; l < NUM_OMI; l++)
                                {
                                    l_epath.addLast(TARGETING::TYPE_OMI,l);
                                    if(TARGETING::targetService().toTarget(l_epath)!=nullptr)
                                    {
                                        o_targetList[MY_OMI] =
                                        TARGETING::targetService().toTarget(l_epath);
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
                for(int j = 0; j < NUM_OMIC; j++)
                {
                    l_epath.addLast(TARGETING::TYPE_OMIC, j);
                    if(TARGETING::targetService().toTarget(l_epath) != nullptr)
                    {
                        o_targetList[MY_OMIC] =
                        TARGETING::targetService().toTarget(l_epath);
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
    }

    //Setup PECs and PHBs
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_PECS; i++)
    {
        l_epath.addLast(TARGETING::TYPE_PEC, i);
        if(TARGETING::targetService().toTarget(l_epath) != nullptr)
        {
            o_targetList[MY_PEC] =
              TARGETING::targetService().toTarget(l_epath);
            for(int j = 0; j < NUM_PHBS; j++)
              {
                  l_epath.addLast(TARGETING::TYPE_PHB,j);
                  if(TARGETING::targetService().toTarget(l_epath) != nullptr)
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
        if(TARGETING::targetService().toTarget(l_epath) != nullptr)
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
        if(TARGETING::targetService().toTarget(l_epath) != nullptr)
        {
            o_targetList[MY_OBUS] =
              TARGETING::targetService().toTarget(l_epath);

            for (int j = 0; j < NUM_OBUS_BRICK; j++)
            {
                l_epath.addLast(TARGETING::TYPE_OBUS_BRICK, j);
                if (TARGETING::targetService().toTarget(l_epath) != nullptr)
                {
                    o_targetList[MY_OBUS_BRICK] =
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

    //Setup PPEs
    i_pMasterProcChip->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(l_epath);
    for(int i = 0; i < NUM_PPES; i++)
    {
        l_epath.addLast(TARGETING::TYPE_PPE, i);
        if(TARGETING::targetService().toTarget(l_epath) != nullptr)
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
        if(TARGETING::targetService().toTarget(l_epath) != nullptr)
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
        if(TARGETING::targetService().toTarget(l_epath) != nullptr)
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
      if(TARGETING::targetService().toTarget(l_epath) != nullptr)
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

bool isHwValid(TARGETING::Target* i_procChip, uint8_t i_hwType)
{
    bool isValid = true;

    // Only need to check model if this is NOT a common target for p9
    if (!(i_hwType == MY_PROC || i_hwType == MY_EQ || i_hwType == MY_EX || i_hwType == MY_CORE ||
        i_hwType == MY_PEC || i_hwType == MY_PHB || i_hwType == MY_XBUS || i_hwType == MY_OBUS ||
        i_hwType == MY_OBUS_BRICK || i_hwType == MY_PPE || i_hwType == MY_PERV || i_hwType == MY_CAPP ||
        i_hwType == MY_SBE))
    {
        auto l_model = i_procChip->getAttr<TARGETING::ATTR_MODEL>();
        if (l_model == TARGETING::MODEL_CUMULUS)
        {
            if (i_hwType == MY_MCS || i_hwType == MY_MCA || i_hwType == MY_MCBIST ||
                i_hwType == MY_OMI || i_hwType == MY_OMIC || i_hwType == MY_MCC )
            {
                isValid = false;
            }
        }
        else if (l_model == TARGETING::MODEL_NIMBUS)
        {
            if (i_hwType == MY_MC || i_hwType == MY_MI || i_hwType == MY_DMI ||
                i_hwType == MY_OMI || i_hwType == MY_OMIC || i_hwType == MY_MCC)
            {
                isValid = false;
            }
        }
        else if (l_model == TARGETING::MODEL_AXONE)
        {
            if (i_hwType == MY_MCS || i_hwType == MY_MCA || i_hwType == MY_MCBIST ||
                i_hwType == MY_DMI)
            {
                isValid = false;
            }
        }
    }
    return isValid;
}

} // End namespace fapi2
