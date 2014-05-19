/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimScrDB.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef PRDFSIMSCRDB_H
#define PRDFSIMSCRDB_H
/**
   @file prdfsimScrDB.H
   @brief Scr states for a simulation run
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include "prdfsimScrDataSet.H"    // data structure typedefs & classes
#include <prdfBitString.H>

//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

namespace PRDF
{

    /**
     *  @brief Singleton to access the only prdfScomService
     */
    //class ScrDB;
    //PRDF_DECLARE_SINGLETON(ScrDB, theScrDB);


    /**
      Scr DB Scan comm register simulator
      @author Douglas Gilbert
      */
    class ScrDB
    {
        public:

            enum SimOp
            {
                READ,
                WRITE,
                EXPECT,
                MAX_OP
            };

            /**
              Constructor
              @param
              @returns
              @pre
              @post
              @see
              @note
              */
            ScrDB();

            /*
               Destructor
               */
            //  ~ScrDB();

            //  void processCmd(const std::string & cmd, std::string & response);
            void processCmd(TARGETING::TargetHandle_t i_ptargetHandle,
                            BIT_STRING_CLASS & bs,
                            uint64_t registerId,
                            SimOp i_op);


        private:

            void Read(TARGETING::TargetHandle_t i_ptargetHandle,
                      BIT_STRING_CLASS & bs,
                      uint64_t registerId);
            void Write(TARGETING::TargetHandle_t i_ptargetHandle,
                       BIT_STRING_CLASS & bs,
                       uint64_t registerId);
            void Expect(TARGETING::TargetHandle_t i_ptargetHandle,
                        BIT_STRING_CLASS & bs,
                        uint64_t registerId);
            //  void Setup(std::istringstream & iss, std::string & response);
            //  void Expect(std::istringstream & iss, std::string & response);

        private:  // Data

            ChipMap chipset;
            PreChipMap pChipset;    // of predetermined value registers
            PreChipMap eChipset;    // map of expected values
            //std::string history;

    };

} // End namespace PRDF

#endif /* PRDFSIMSCRDB_H */
