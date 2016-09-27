/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/fsi_common.C $                                    */
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
#include "fsi_common.H"
#include <fsi/fsiif.H>

/**
 * @brief Convert a type/port pair into a FSI address offset
 */
uint64_t FSI::getPortOffset(TARGETING::FSI_MASTER_TYPE i_type,
                              uint8_t i_port)
{
    uint64_t offset = 0;
    if( TARGETING::FSI_MASTER_TYPE_MFSI == i_type )
    {
        switch(i_port)
        {
            case(0): offset = FSI::MFSI_PORT_0; break;
            case(1): offset = FSI::MFSI_PORT_1; break;
            case(2): offset = FSI::MFSI_PORT_2; break;
            case(3): offset = FSI::MFSI_PORT_3; break;
            case(4): offset = FSI::MFSI_PORT_4; break;
            case(5): offset = FSI::MFSI_PORT_5; break;
            case(6): offset = FSI::MFSI_PORT_6; break;
            case(7): offset = FSI::MFSI_PORT_7; break;
        }
    }
    else if( TARGETING::FSI_MASTER_TYPE_CMFSI == i_type )
    {
        switch(i_port)
        {
            case(0): offset = FSI::CMFSI_PORT_0; break;
            case(1): offset = FSI::CMFSI_PORT_1; break;
            case(2): offset = FSI::CMFSI_PORT_2; break;
            case(3): offset = FSI::CMFSI_PORT_3; break;
            case(4): offset = FSI::CMFSI_PORT_4; break;
            case(5): offset = FSI::CMFSI_PORT_5; break;
            case(6): offset = FSI::CMFSI_PORT_6; break;
            case(7): offset = FSI::CMFSI_PORT_7; break;
        }
    }

    return offset;
}
