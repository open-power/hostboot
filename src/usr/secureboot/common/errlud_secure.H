/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/common/errlud_secure.H $                   */
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
#ifndef ERRL_UD_SECURE_H
#define ERRL_UD_SECURE_H

/**
 *  @file errlud_secure.H
 *
 *  Defines the classes that logs and parses various Secureboot data
 */

#include <secureboot/service.H>
#include <errl/errluserdetails.H>

namespace SECUREBOOT
{

/**
 * @class UdSystemHwKeyHash
 *
 * Adds System HW Keys Hash to an error log as user detail data
 */
class UdSystemHwKeyHash : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_hash  System HW Keys Hash represented by SHA512
     */
    UdSystemHwKeyHash(const SHA512_t i_hash);

    /**
     *  @brief Destructor
     */
    virtual ~UdSystemHwKeyHash();

    /**
     * Delete Copy Constructor
     */
    UdSystemHwKeyHash(const UdSystemHwKeyHash&) = delete;

    /**
     * Delete Copy Assignment
     */
    UdSystemHwKeyHash& operator= (const UdSystemHwKeyHash&) = delete;

    /**
     * Delete Move Constructor
     */
    UdSystemHwKeyHash (UdSystemHwKeyHash&&) = delete;

    /**
     * Delete Move Assignment
     */
    UdSystemHwKeyHash& operator = (UdSystemHwKeyHash&&) = delete;

};

/**
 * @class UdTargetHwKeyHash
 *
 * Adds Target HW Keys Hash to an error log as user detail data
 */
class UdTargetHwKeyHash : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     *
     *  @param i_target       Processor Target containing HW Keys Hash
     *  @param i_side         SEEPROM side used on the target:
     *                        0=SBE_PRIMARY, 1=SBE_BACKUP
     *  @param i_hash         Target HW Keys Hash represented by SHA512
     */
    UdTargetHwKeyHash(const TARGETING::Target * i_target,
                      const uint8_t i_side,
                      const SHA512_t i_hash);

    /**
     *  @brief Destructor
     */
    virtual ~UdTargetHwKeyHash();

    /**
     * Delete Copy Constructor
     */
    UdTargetHwKeyHash(const UdTargetHwKeyHash&) = delete;

    /**
     * Delete Copy Assignment
     */
    UdTargetHwKeyHash& operator= (const UdTargetHwKeyHash&) = delete;

    /**
     * Delete Move Constructor
     */
    UdTargetHwKeyHash (UdTargetHwKeyHash&&) = delete;

    /**
     * Delete Move Assignment
     */
    UdTargetHwKeyHash& operator = (UdTargetHwKeyHash&&) = delete;
};

/**
 * @class UdSecuritySettings
 *
 * Adds Security Settings to an error log as user detail data
 */
class UdSecuritySettings : public ERRORLOG::ErrlUserDetails
{
  public:
    /**
     *  @brief Constructor
     */
    UdSecuritySettings();

    /**
     *  @brief Destructor
     */
    virtual ~UdSecuritySettings();

    /**
     * Delete Copy Constructor
     */
    UdSecuritySettings(const UdSecuritySettings&) = delete;

    /**
     * Delete Copy Assignment
     */
    UdSecuritySettings& operator= (const UdSecuritySettings&) = delete;

    /**
     * Delete Move Constructor
     */
    UdSecuritySettings (UdSecuritySettings&&) = delete;

    /**
     * Delete Move Assignment
     */
    UdSecuritySettings& operator = (UdSecuritySettings&&) = delete;

    private:
        // Errl User Details layout
        struct detailsLayout
        {
            uint8_t secAccessBit;
            uint8_t secOverride;
            uint8_t allowAttrOverride;
        };

};

} // end SECUREBOOT namespace

#endif
