/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/ctype.h $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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

/**
 * @brief Determine if character is a digit (0-9).
 *
 * @param[in]   Input character.
 * @return int - 0 if not a digit, non-zero if is a digit.
 */
int isdigit(int) __attribute__((const));

/**
 * @brief Determine if character is a lower-case character.
 *
 * @param[in]   Input character.
 * @return int - 0 if not, non-zero if so.
 */
int islower(int) __attribute__((const));

/**
 * @brief Determine if character is a upper-case character.
 *
 * @param[in]   Input character.
 * @return int - 0 if not, non-zero if so.
 */
int islower(int) __attribute__((const));

/**
 * @brief Determine if character is a alphabetic character.
 *
 * @param[in]   Input character.
 * @return int - 0 if not, non-zero if so.
 */
int isalpha(int) __attribute__((const));

/**
 * @brief Determine if character is a alpha-numeric character.
 *
 * @param[in]   Input character.
 * @return int - 0 if not, non-zero if so.
 */
int isalnum(int) __attribute__((const));

/**
 * @brief Determine if character is a punctuation character.
 *
 * @param[in]   Input character.
 * @return int - 0 if not, non-zero if so.
 */
int ispunct(int) __attribute__((const));

/**
 * @brief Determine if character is a space character.
 *
 * @param[in]   Input character.
 * @return int - 0 if not, non-zero if so.
 */
int isspace(int) __attribute__((const));

/**
 * @brief Determine if character is a printable character.
 *
 * @param[in]   Input character.
 * @return int - 0 if not, non-zero if so.
 */
int isprint(int) __attribute__((const));


#ifdef __cplusplus
};
#endif

#endif
