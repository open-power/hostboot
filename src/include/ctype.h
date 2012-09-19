/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/ctype.h $                                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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
#ifndef __CTYPE_H
#define __CTYPE_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Converts lowercase letter to uppercase
 *
 * If no such conversion is possible then the input is returned unchanged
 *
 * @param[in]   Input letter
 * @return int. Uppercase letter
 */
int toupper(int) __attribute__((const));

#ifdef __cplusplus
};
#endif

#endif
