/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/lab_pstates.h $              */
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
#ifndef __LAB_PSTATES_H__
#define __LAB_PSTATES_H__

// $Id: lab_pstates.h,v 1.5 2013/08/13 17:12:56 jimyac Exp $

/// \file lab_pstates.h
/// \brief Lab-only (as opposed to product-procedure) support for Pstates.

#include <stdint.h>

// jwy #include "ssx_io.h"
#include "pstates.h"

// Error/panic codes

#define IVID_INVALID_VOLTAGE            0x00484301
#define PSTATE_STATUS_REPORT_SCOM_ERROR 0x00777701

/// String storage requirement for strings used of arguments of
/// sprintf_10uv, sprintf_vrm11() and sprintf_ivid().
///
/// \todo Replace with a typedef
#define FORMAT_10UV_STRLEN 8

#define FORMAT_10UV_ERROR "<Error>"

#define ROUND_VOLTAGE_UP    1
#define ROUND_VOLTAGE_DOWN -1

#ifndef __ASSEMBLER__

int
vuv2vrm11(uint32_t v_uv, int round, uint8_t *vrm11_vid);

int
vrm112vuv(uint8_t vrm11_vid, uint32_t *v_uv);

int
vuv2ivid(uint32_t v_uv, int round, uint8_t *ivid);

int
ivid2vuv(uint8_t ivid, uint32_t *v_uv);

int
sprintf_10uv(char *s, uint32_t v_uv);

#ifdef FAPIECMD

int
fprintf_10uv(FILE *stream, uint32_t v_uv);

int
sprintf_vrm11(char *s, uint8_t vrm11);

int
fprintf_vrm11(FILE *stream, uint8_t vrm11);

int
sprintf_ivid(char *s, uint8_t ivid);

int
fprintf_ivid(FILE *stream, uint8_t ivid);

void
gpst_print(FILE* stream, GlobalPstateTable* gpst);

void
lpsa_print(FILE* stream, LocalPstateArray* lpsa);

void
cpmrange_print(FILE* stream, CpmPstateModeRanges* cpmrange);

void
resclk_print(FILE* stream, ResonantClockingSetup* resclk);

void
pss_print(FILE* stream, PstateSuperStructure* pss);

#endif // FAPIECMD

#endif // __ASSEMBLER__

#endif // __LAB_PSTATES_H__
