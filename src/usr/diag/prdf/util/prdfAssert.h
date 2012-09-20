/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/util/prdfAssert.h $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
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

#ifndef PRDFASSERT_H
#define PRDFASSERT_H

/**
 * @file prdfAssert.h
 */

#define PRDF_ASSERT(x) { if(!(x)) { prdfAssert(#x,__FILE__,__LINE__); } }

/**
 * @brief PRD implementation of assert().
 * @param i_exp  A boolean expression.
 * @param i_file The file calling assert().
 * @param i_line The line of the file in which assert() is called.
 */
void prdfAssert( const char * i_exp, const char * i_file, int i_line );

#endif /* PRDFASSERT_H */
