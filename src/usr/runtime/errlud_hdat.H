/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/errlud_hdat.H $                               */
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
#ifndef ERRL_UD_HDAT_H
#define ERRL_UD_HDAT_H

/**
 *  @file errlud_naca.H
 *
 *  Defines the classes that logs and parses various HDAT structures
 */

#include <errl/errluserdetails.H>
#include "hdatstructs.H"

namespace RUNTIME
{

/**
 * @class UdNaca
 *
 * Adds NACA FFDC to an error log as user detail data
 */
class UdNaca : public ERRORLOG::ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Copies the NACA data into the FFDC data
     *  
     *  @param i_naca Pointer to NACA data to capture
     */
    UdNaca(hdatNaca_t* i_naca);

    /**
     *  @brief Destructor
     */
    virtual ~UdNaca();

private:
    // Disabled
    UdNaca(UdNaca &);
    UdNaca & operator=(UdNaca &);
};


/**
 * @class UdSpira
 *
 * Adds SPIRA FFDC to an error log as user detail data
 */
class UdSpira : public ERRORLOG::ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Copies the SPIRA data into the FFDC data
     *  
     *  @param i_spira Pointer to Spira data to capture
     */
    UdSpira(hdatSpira_t* i_spira);

    /**
     *  @brief Destructor
     */
    virtual ~UdSpira();

private:
    // Disabled
    UdSpira(UdSpira &);
    UdSpira & operator=(UdSpira &);
};


/**
 * @class UdSpira
 *
 * Adds a Tuple FFDC to an error log as user detail data
 */
class UdTuple : public ERRORLOG::ErrlUserDetails
{
public:
    /**
     *  @brief Constructor
     *  
     *  Copies the SPIRA data into the FFDC data
     *  
     *  @param i_spira Pointer to Spira data to capture
     */
    UdTuple(hdat5Tuple_t* i_spira);

    /**
     *  @brief Destructor
     */
    virtual ~UdTuple();

private:
    // Disabled
    UdTuple(UdSpira &);
    UdTuple & operator=(UdSpira &);
};

}

#endif

