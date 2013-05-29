/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/plat/fapiPlatUtil.H $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
 *  @file fapiPlatUtil.H
 *
 *  @brief Defines miscellanous utility functions for the platform layer.
 *         Hardware procedure writers will not call these functions.
 *
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          whs         11/14/2012  new
 */

#ifndef FAPIPLATUTIL_H_
#define FAPIPLATUTIL_H_

#include <endian.h>
#include <stdlib.h>

// defines for endian conversion
#define FAPI_PLAT_BE16TOH(x) be16toh(x)
#define FAPI_PLAT_LE16TOH(x) le16toh(x)
#define FAPI_PLAT_HTOBE16(x) htobe16(x)
#define FAPI_PLAT_HTOLE16(x) htole16(x)

#define FAPI_PLAT_BE32TOH(x) be32toh(x)
#define FAPI_PLAT_LE32TOH(x) le32toh(x)
#define FAPI_PLAT_HTOBE32(x) htobe32(x)
#define FAPI_PLAT_HTOLE32(x) htole32(x)

#define FAPI_PLAT_BE64TOH(x) be64toh(x)
#define FAPI_PLAT_LE64TOH(x) le64toh(x)
#define FAPI_PLAT_HTOBE64(x) htobe64(x)
#define FAPI_PLAT_HTOLE64(x) htole64(x)

#define fapiPlatMalloc(s) malloc(s)
#define fapiPlatFree(p) free(p)

#endif // FAPIPLATUTIL_H_
