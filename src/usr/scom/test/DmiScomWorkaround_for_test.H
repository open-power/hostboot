/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/test/DmiScomWorkaround_for_test.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __SCOM_DMI_SCOM_WORKAROUND_FOR_TEST_H
#define __SCOM_DMI_SCOM_WORKAROUND_FOR_TEST_H

#include "../DmiScomWorkaround.H"

using namespace SCOM;
using namespace ERRORLOG;

// Derived class to implement mocked target dependency injection for
// Unit Testing of the DmiScomWorkaround class.
class DmiScomWorkaround_for_test : public DmiScomWorkaround
{
public:

    //---------------------------------------------------------------------
    DmiScomWorkaround_for_test()=default;

   //-----------------------------------------------------------------------
   // getTargetType implemented using mocked target.
   bool getTargetType(TARGETING::Target* i_target,
                                              TARGETING::TYPE& o_type) const
                                                                       override
   {
       //Encodings for mock targets
       // 0x4000000000000000 DMI Target
       // 0x8000000000000000 PROC Target
       // 0x0200000000000000 NIMBUS
       // 0x0100000000000000 CUMULUS
       // 0x00000000000000XX EC Level

       constexpr uint64_t typeMask{0xC000000000000000};
       constexpr uint64_t procType{0x8000000000000000};
       constexpr uint64_t dmiType{0x4000000000000000};

       bool l_retval{false};
       uint64_t l_targetAddr = reinterpret_cast<uint64_t>(i_target);

       const uint64_t typeAddr = l_targetAddr & typeMask;
       if(procType == typeAddr)
       {
            o_type = TARGETING::TYPE_PROC;
            l_retval = true;
       }
       else if(dmiType == typeAddr)
       {
            o_type = TARGETING::TYPE_DMI;
            l_retval = true;
       }

       return l_retval;
   }

   //------------------------------------------------------------------------
   // getTargetModel implemented using mocked target.
   bool getTargetModel(TARGETING::Target* i_target,
                                            TARGETING::MODEL& o_model) const
                                                                       override
   {
       //Encodings for mock targets
       // 0x4000000000000000 DMI Target
       // 0x8000000000000000 PROC Target
       // 0x0200000000000000 NIMBUS
       // 0x0100000000000000 CUMULUS
       // 0x00000000000000XX EC Level

       constexpr uint64_t modelMask{0x0300000000000000};
       constexpr uint64_t cumulusModel{0x0100000000000000};
       constexpr uint64_t nimbusModel{0x0200000000000000};

       bool l_retval{false};
       uint64_t l_targetAddr = reinterpret_cast<uint64_t>(i_target);

       const uint64_t modelAddr = l_targetAddr & modelMask;
       if(cumulusModel == modelAddr)
       {
            o_model = TARGETING::MODEL_CUMULUS;
            l_retval = true;
       }
       else if(nimbusModel == modelAddr)
       {
            o_model = TARGETING::MODEL_NIMBUS;
            l_retval = true;
       }

       return l_retval;
   }

    //-----------------------------------------------------------------------
    bool getTargetECLevel(TARGETING::Target* i_target,
                                                    uint8_t& o_ecLevel) const
    {
        constexpr uint64_t ECLevelMask{0x00000000000000FF};

        uint64_t l_targetAddr = reinterpret_cast<uint64_t>(i_target);

        const uint64_t l_ecLevel = l_targetAddr & ECLevelMask;
        o_ecLevel = static_cast<uint8_t>(l_ecLevel);

        return true;
    }

   //------------------------------------------------------------------------
   // We don't want to cache the processor model for unit tests
   // in order to allow mocking targets with different models.
   bool useCachedProcModel() const override {return false;}

};

#endif
