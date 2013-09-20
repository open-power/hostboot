/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/crc32.H $                                    */
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
#ifndef __UTIL_CRC32_H
#define __UTIL_CRC32_H


namespace Util
{
    /**
     * @brief Creates a 4-byte Cyclic Redundancy Check (CRC) on the data
     *        provided
     *
     * @param[in] ptr          Pointer to the data
     *
     * @param[in] size         Size of the data
     *
     * @return uint32_t        4-byte CRC
     */
    uint32_t crc32_calc(const void* ptr, size_t size);
};

#endif

