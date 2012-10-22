/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasPlatDeconfigGard.H $                 */
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
/**
 *  @file hwas/hwasPlatDeconfigGard.H
 *
 *  @brief Defines platform interfaces and whatnot needed for DeconfigGard in the
 *         HWAS common and platform specific functions
 */

#ifndef HWASPLATDECONFIGGARD_H_
#define HWASPLATDECONFIGGARD_H_

#include <sys/mm.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <hwas/hwasPlatError.H>

//******************************************************************************
// Trace descriptors that are defined in a C file
//******************************************************************************
namespace HWAS
{

#if 0
//TODO: RTC 37739: flush PNOR
// questions -- what address and what size do it need to use? the section
//  starting address and section size? or the address and size of the
//  gard record that is being flushed?

/**
 * @brief function to push GARD records 'out' to PNOR
 */
inline void pushGardRecords(void *i_pAddr, uint64_t i_size)
{
    int l_rc = mm_remove_pages(FLUSH, i_pAddr, i_size);
    if (l_rc )
    {   // mm_remove_pages returns none zero for error
        HWAS_ERR("Fail to flush the page");
    }
}
#endif

}

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


#endif // HWASPLATDECONFIGGARD_H_
