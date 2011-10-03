//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/errno.h $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef _ERRNO_H
#define _ERRNO_H

#define ENOENT           2      // No such file or directory
#define	EIO              5      // I/O error
#define ENOEXEC          8      // Exec format error
#define EBADF            9      // Bad file descriptor
#define EAGAIN          11      // Try again
#define	EFAULT          14      // Bad address
#define EINVAL          22      // Invalid argument
#define ENFILE          23      // Too many open files in system
#define EDEADLK         35      // Operation would cause deadlock.

#define EWOULDBLOCK     EAGAIN  // operation would block

#endif
