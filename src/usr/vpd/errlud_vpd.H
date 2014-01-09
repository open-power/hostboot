/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/vpd/errlud_vpd.H $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#ifndef ERRL_UD_VPD_H
#define ERRL_UD_VPD_H

/**
 *  @file errlud_vpd.H
 *
 *  Defines the classes that logs and parses various VPD structures
 */

#include <errl/errluserdetails.H>
#include "ipvpd.H"

namespace VPD
{

/**
 * @class UdVpdParms
 *
 * Adds VPD parameters information to an error log as user detail data
 */
class UdVpdParms : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_target        Target being detected/acted upon
     *  @param i_buflen        Length of In/Out buffer
     *  @param i_record        Record
     *  @param i_keyword       Keyword
     *  @param read_notWrite   Read/not-Write (read=true; write=false)
     */
    UdVpdParms( TARGETING::Target * i_target,
           uint64_t i_buflen,
           uint64_t i_record,
           uint64_t i_keyword,
           bool read_notWrite  );

    /**
     *  @brief Destructor
     */
    virtual ~UdVpdParms();

  private:
    // Disabled
    UdVpdParms(UdVpdParms &);
    UdVpdParms & operator=(UdVpdParms &);
};


}

#endif
