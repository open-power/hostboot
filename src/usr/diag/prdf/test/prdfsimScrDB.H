/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimScrDB.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
