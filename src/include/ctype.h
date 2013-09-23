/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/ctype.h $                                         */
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
