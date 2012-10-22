/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/terminatetypes.H $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
/** @file terminate.H
 *  @brief Defines kernel information about the TI data area
 */
#ifndef __KERNEL_HBTERMINATETYPES_H
#define __KERNEL_HBTERMINATETYPES_H
#include <stdint.h>



/** @struct TI_DataArea
 *  @brief Defines the data space used to store the src or PLID regarding a
 *     Terminate Immediate request
 */
struct HB_TI_DataArea
{

    union{
        struct {
            uint64_t type:16;       /**< indicates either plid or src  */
            uint64_t source:16;     /**< Caller of the TI  */
            uint64_t reserved2:16;  /**< Reserved space */
            uint64_t reserved3:16;  /**< Reserved space  */
        };
        uint64_t flag;  /**< Full Dword0 */
    };
    uint64_t src[4];
    uint64_t plid;
};

// Enum indicating whether a SRC or PLID is stored
enum hb_terminate_type
{
    TI_WITH_PLID = 0x0001,
    TI_WITH_SRC =  0x0002,
};

// Enum used in the flag indicating who initiated the TI 
enum hb_terminate_source
{
    TI_KERNAL_ASSERT = 0x0001,
    TI_CRIT_ASSERT =   0x0002,
    TI_SHUTDOWN =      0x0003,
};


#endif
