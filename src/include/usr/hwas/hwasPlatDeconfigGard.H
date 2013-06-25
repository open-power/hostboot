/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasPlatDeconfigGard.H $                 */
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
/**
 *  @file hwas/hwasPlatDeconfigGard.H
 *
 *  @brief Defines platform interfaces and whatnot needed for DeconfigGard in the
 *         HWAS common and platform specific functions
 */

#ifndef HWASPLATDECONFIGGARD_H_
#define HWASPLATDECONFIGGARD_H_

/**
 *  @brief Adapt common singleton declaration to specific platform
 *
 *  @param[in] __T__
 *      Type of singleton, fully namespaced
 *
 *  @param[in] __NAME__
 *      Symbol name for singleton
 */
#define HWAS_DECLARE_SINGLETON(__T__,__NAME__) \
    typedef Singleton<__T__> __NAME__;

/**
 *  @brief Adapt common singleton "getter" to the specific platform
 *
 *  @param[in] __TYPE__
 *      Typedef for singleton, as created above
 *
 *  @return Singleton reference for the given singleton
 */
#define HWAS_GET_SINGLETON(__TYPE__) \
    __TYPE__::instance()

namespace HWAS
{

struct HBDeconfigGard
{
    // GARD Record Data
    uint32_t iv_nextGardRecordId;   // Next GARD Record ID to use
    uint32_t iv_maxGardRecords;     // Maximum number of GARD Records
    void *iv_pGardRecords;          // Pointer to the GARD Records in PNOR
};

} // namespace HWAS

#endif // HWASPLATDECONFIGGARD_H_
