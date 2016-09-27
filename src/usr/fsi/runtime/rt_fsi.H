/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/runtime/rt_fsi.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#ifndef _RT_FSI_H_
#define _RT_FSI_H_

#include <fsi/fsiif.H>
#include <map>
#include "fsi_common.H"

class RtFsi
{

  public:
     /**
      * @brief Retrieve some FSI attribute information
      *
      * @param[in]  i_slave   Slave Chip Target to query
      * @param[out] o_info    FSI Link Information
      *
      */
      void getFsiLinkInfo( TARGETING::Target* i_slave,
                           FSI::FsiLinkInfo_t& o_info);

  protected:
     /**
      * @brief Constructor
      */
      RtFsi();

     /**
      * @brief Destructor
      */
      ~RtFsi();

    /**
     * @brief Figure out the optimal OPB Master to use and generate a
     *    complete FSI address relative to that master based on the target
     *    and the FSI offset within that target
     *
     * @param[inout] io_addrInfo  FSI addressing information,
     *     expects fsiTarg and relAddr to be populated as input
     *
     * @return errlHndl_t  NULL on success
     */
    errlHndl_t genFullFsiAddr(FSI::FsiAddrInfo_t& io_addrInfo);


    /**
     * @brief Retrieve the connection information needed to access FSI
     *        registers within the given chip target
     *
     * @param[in] i_target  Target of FSI Slave to access
     *
     * @return FsiChipInfo_t  FSI Chip Information
     */
    FSI::FsiChipInfo_t getFsiInfo( TARGETING::Target* i_target );

    /**
     * @brief Retrieve the connection information needed to access FSI
     *        registers within the given chip target from attributes
     *
     * @param[in] i_target  Target of FSI Slave to access
     *
     * @return FsiChipInfo_t  FSI Chip Information
     */
    FSI::FsiChipInfo_t getFsiInfoFromAttr( TARGETING::Target* i_target );


    /************************
     * VARIABLES
     ************************/

    /**
     * Master processor target
     */
    TARGETING::Target* iv_master;

    /**
     * Cache of FSI connection information gleaned from attributes
     *   Indexed by Target*, returns FsiChipInfo_t
     */
    std::map<TARGETING::Target*,FSI::FsiChipInfo_t> iv_fsiInfoMap;

    /**
     * Mutex to protect the internal maps
     */
    mutex_t iv_dataMutex;

    /**
     * Using alternate master
     */
    uint8_t iv_useAlt;

};

#endif
