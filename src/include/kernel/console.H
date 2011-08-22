//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/console.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
#ifndef __KERNEL_CONSOLE_H
#define __KERNEL_CONSOLE_H

#include <stdint.h>
#include <string.h>
#include <builtins.h>

#ifdef HOSTBOOT_DEBUG
    #define printkd(format...) printk(## format)
#else
    #define printkd(format...)
#endif

void printk(const char*, ...) FORMAT_PRINTF;

class Console
{
    public:
	int putc(int);

	enum { BUFFER_SIZE = 1024 * 16 };

    protected:
	Console();
	~Console() {};

    private:
	size_t iv_pos;
	char * iv_buffer;
};

#endif
