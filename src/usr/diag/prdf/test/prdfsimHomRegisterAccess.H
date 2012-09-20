/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/test/prdfsimHomRegisterAccess.H $           */
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
     @returns [SUCCESS|FAIL]
     @pre bs.Length() must be size of register data to read/write
     @post For read operation, bs is modified to reflect hardware register state
     @note
     */
    virtual uint32_t Access(TARGETING::TargetHandle_t i_target,
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
