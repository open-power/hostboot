/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/errlud_fsi.H $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#ifndef ERRL_UD_FSI_H
#define ERRL_UD_FSI_H

/**
 *  @file errlud_fsi.H
 *
 *  Defines the classes that logs and parses various HDAT structures
 */

#include <errl/errluserdetails.H>

namespace FSI
{

/**
 * @class UdPresence
 *
 * Adds FSI Link/Presence information to an error log as user detail data
 */
class UdPresence : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *  
     *  @param i_target  Chip being detected/acted upon
     */
    UdPresence( TARGETING::Target* i_target );

    /**
     *  @brief Destructor
     */
    virtual ~UdPresence();

  private:
    // Disabled
    UdPresence(UdPresence &);
    UdPresence & operator=(UdPresence &);
};

/**
 * @class UdOperation
 *
 * Adds FSI Operation Information to an error log as user detail data
 */
class UdOperation : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_target  Target of FSI Op
     *  @param i_address  Address of FSI Op
     *  @param i_readNotWrite  True=read, False=write
     */
    UdOperation( TARGETING::Target* i_target,
                 uint64_t i_address,
                 bool i_readNotWrite );

    /**
     *  @brief Destructor
     */
    virtual ~UdOperation();

  private:
    // Disabled
    UdOperation(UdPresence &);
    UdOperation & operator=(UdOperation &);
};


}

#endif
