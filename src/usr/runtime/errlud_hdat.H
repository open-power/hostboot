/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/errlud_hdat.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef ERRL_UD_HDAT_H
#define ERRL_UD_HDAT_H

/**
 *  @file errlud_hdat.H
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

