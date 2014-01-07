/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/string.h $                                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
#ifndef __STRING_H
#define __STRING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
    void *memset(void* s, int c, size_t n);
    void bzero(void *vdest, size_t len);
    void *memcpy(void *dest, const void *src, size_t num);
    void *memmove(void *vdest, const void *vsrc, size_t len);
    int memcmp(const void *p1, const void *p2, size_t len) __attribute__((pure));
    void *memmem(const void *haystack, size_t haystacklen,
                 const void *needle, size_t needlelen) __attribute__((pure));

    char* strcpy(char* d, const char* s);
    char* strncpy(char* d, const char* s, size_t l);
    int strcmp(const char* s1, const char* s2) __attribute__((pure));
    size_t strlen(const char* s1) __attribute__((pure));
    size_t strnlen(const char* s1, size_t n) __attribute__((pure));

    char* strcat(char* d, const char* s);
    char* strncat(char* d, const char* s, size_t n);

    char* strchr(const char* s, int c) __attribute__((pure));

#ifdef __cplusplus
};
#endif

#endif
