/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/hbterminatetypes.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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

/** @struct HB_T_SRC_DataAreaw
 *  @brief Defines the data space recreating an SRC needed for a TI from kernel
 *  space
 */
struct HB_T_SRC_DataArea
{

    union{
        struct {
            uint32_t ID:8;          /**< B1 or what we are using now*/
            uint32_t subsystem:8;   /**< Caller of the TI  */
            uint32_t reasoncode:16; /**< reasoncode */
        };
        uint32_t SRCword0;          /**< Full SRC word0 */
    };
    uint32_t SRCword1;              /**< Full SRC word2 */
    union{
        struct {
            uint32_t bpCCIN:16;     /**< BP CCIN*/
            uint32_t moduleID:8;    /**< Module ID  */
            uint32_t FSP:8;         /**< subsystem */
        };
        uint32_t SRCword2;          /**< Full SRC word1 */
    };

    uint32_t SRCword3;              /**< Full SRC word3 */
    uint32_t SRCword4;              /**< Full SRC word4 */
    /* Word 5-8 - user data */
    union{
        struct {
            uint32_t iType:16;     /**< SRC of PLID failure*/
            uint32_t iSource:16;   /**< Source of the src */
        };
        uint32_t SRCword5;         /**< Full Dword5 */
    };
    uint32_t word6;                /**< Full Dword6 */

    uint32_t word7;                /**< Full Dword7 */
    uint32_t word8;                /**< Full Dword8 */

};


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
        uint64_t flag;              /**< Full word - flag */
    };
    uint32_t reserved0;
    uint32_t plid;                  /**< Plid  */
    HB_T_SRC_DataArea src;          /**< SRC  */
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
    TI_KERNEL_ASSERT = 0x0001,
    TI_CRIT_ASSERT =   0x0002,
    TI_SHUTDOWN =      0x0003,
    TI_UNHANDLED_EX =  0x0004,
};


#endif
