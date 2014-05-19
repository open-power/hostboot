/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimHomRegisterAccess.H $           */
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

#ifndef PRDFSIMHOMREGISTERACCESS_H
#define PRDFSIMHOMREGISTERACCESS_H
/**
   @file prdfHomRegisterAccess.H
   @brief Provide access to scan & scan com registers via the HOM
*/


//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------

#include <prdfHomRegisterAccess.H>


//--------------------------------------------------------------------
//  Forward References
//--------------------------------------------------------------------

namespace PRDF
{

class SimScomAccessor : public ScomAccessor
{
  public:

    /**
     * @brief ctor
     */
    SimScomAccessor();

    /**
     * @brief dtor
     */
    virtual ~SimScomAccessor();

    /**
     Access the scan com register
     @param i_target Target to access the register
     @param BIT_STRING_CLASS - holds data read or to write
     @param register address
     @param [READ|WRITE]
     @returns NULL if success, valid error handle otherwise
     @pre bs.Length() must be size of register data to read/write
     @post For read operation, bs is modified to reflect hardware register state
     @note
     */
    virtual errlHndl_t Access(TARGETING::TargetHandle_t i_target,
                            BIT_STRING_CLASS & bs,
                            uint64_t registerId,
                            MopRegisterAccess::Operation operation) const;


  private:

    /**
     * @brief disable copy
     */
    SimScomAccessor(const SimScomAccessor &);

    /**
     * @brief disable assignment
     */
    SimScomAccessor & operator=(const SimScomAccessor &);

};

} // End namespace PRDF

#endif /* PRDFSIMHOMREGISTERACCESS_H */
