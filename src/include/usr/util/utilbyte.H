/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utilbyte.H $                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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

#ifndef UTILBYTE_H
#define UTILBYTE_H

/**
 * @file utilbyte.H
 *
 * @brief byte to integer utility
 *
 */

/*****************************************************************************/
// Byte Utility class
/*****************************************************************************/
/**
 *  @brief     Byte Utility class
 *
 */
class UtilByte
{
    public:

        /**
         *  @brief Default Constructor
         *
         */
        UtilByte();

        /**
         *  @brief Destructor
         *
         */
        ~UtilByte();

        /**
         * @brief extract 2 bytes from buffer and convert to uint16
         *
         * @param[in] i_buffer: pointer to buffer containing 2 bytes
         *  to be converted
         * @retval: 16 bit integer value of the consecutive 2 bytes
         *  pointed in the buffer
         */

        static uint16_t bufferTo16uint(void * i_buffer);

        /**
         * @brief extract 4 bytes from buffer and convert to uint32
         *
         * @param[in] i_buffer: pointer to buffer containing 4 bytes
         *  to be converted
         * @retval: 32 bit integer value of the consecutive 4 bytes
         *  pointed in the buffer
         */

        static uint32_t bufferTo32uint(void * i_buffer);

};

/*
 * Constructor
 */
UtilByte::UtilByte()
{
}

/*
 * Destructor
 */
UtilByte::~UtilByte()
{
}

/*
 * @brief converts 2 bytes into uint16
 */

inline uint16_t UtilByte::bufferTo16uint(void * i_buffer)
{
    return static_cast<uint16_t>(
        ((uint8_t) *static_cast<char *>(i_buffer)) << 8 |
        ((uint8_t) *(static_cast<char *>(i_buffer)+1)));
}

/*
 * @brief converts 4 bytes into uint16
 */

inline uint32_t UtilByte::bufferTo32uint(void * i_buffer)
{
    return static_cast<uint32_t>(
        ((uint8_t) *static_cast<char *>(i_buffer)) << 24 |
        ((uint8_t) *(static_cast<char *>(i_buffer)+1)) << 16 |
        ((uint8_t) *(static_cast<char *>(i_buffer)+2)) << 8 |
        ((uint8_t) *(static_cast<char *>(i_buffer)+3)));
}

#endif //UTILBYTE_H
