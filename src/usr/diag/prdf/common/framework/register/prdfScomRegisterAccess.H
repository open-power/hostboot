/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: prdfScomRegisterAccess.H $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

#ifndef __PRDF_REGISTER_
#define __PRDF_REGISTER_

#include <prdfScomRegister.H>
#include <prdfBitString.H>
#include <prdfPlatServices.H>

/**
 * @brief Models register.This model of register has target info
 *
 * In order to reduce the register objects required by PRD to do attention
 * analysis, these are shared across all the  RuleChip objects associated with
 * target of same type.In order to realize this,target info is taken out of
 * register object .RuleChip contains target info.During Analysis ,pointer to
 * Rulechip under analysis is maintained in Service Data collector.During
 * register Read and Write,target info is obtained by register from service data
 * collector.This idea fails when getRegister is called for Register read and
 * write.It may be called from plugin code which may use a RuleChip different
 * from the one in SDC.We would like to avoid SDC getting updated from multiple
 * places.To simplify solution for this use case, a wrapper register is required
 * .This register model knows which rule chip it is associated with.When plugin
 * code calls getRegister ,instead of returning  targetless flyweight object,it
 * returns an object of class ScomRegisterAccess.Since register Read Write is
 * in parent class ,it's just a container for Rulechip pointer giving us a way
 * to do scom without having to look for associated target/rule chip somewhere
 * else.
 */

namespace PRDF
{
class ScomRegisterAccess : public ScomRegister
{
    public :
    /**
     * @brief     constructor
     * @param     i_Register     Reference to flyweight register
     * @param     i_pchip        RuleChip associated with register
     */
    ScomRegisterAccess( const SCAN_COMM_REGISTER_CLASS & i_Register,
                        ExtensibleChip* i_pchip );
    /**
     * @brief     constructor
     */
    ScomRegisterAccess():ScomRegister( ),iv_containerChip ( NULL ){ };

    /**
     * @brief Destructor
    */
    ~ScomRegisterAccess(){ };
    /**
     * @brief     Returns pointer to rulechip associated with register
     * @return    Returns rule chip pointer
    */

    virtual ExtensibleChip* getChip( ) const;
    /**
     * @brief     compares two ScomRegisterAccess register for equality
     * @param     i_rightRegister   register to be compared against
     * @return    Returns true if registers are equal false otherwise
     */
    bool operator == ( const ScomRegisterAccess & i_rightRegister ) const;
    /**
     * @brief     defines < operation for ScomRegisterAccess
     * @param     i_rightRegister   register to be compared against
     * @return    Returns false if i_rightRegisters is less and true otherwise
     */
    bool operator < ( const ScomRegisterAccess & i_rightRegister ) const;
    /**
     * @brief     defines >= operation for ScomRegisterAccess
     * @param     i_right   register to be compared against
     * @return    Returns true if registers is >= i_rightRegister false
     *            otherwise
     */
    bool operator >= ( const ScomRegisterAccess & i_right ) const;


    private://Data

    ExtensibleChip* iv_containerChip;


};

}//namepsace PRDF ends
#endif

