//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/spinlock.H $
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
#ifndef __KERNEL_SPINLOCK_H
#define __KERNEL_SPINLOCK_H

#include <util/locked/lock.H>
#include <stdint.h>

class Spinlock : public Util::Locked::Lock
{
    public:
	Spinlock() : iv_reserve(0), iv_ready(0) {};

	void lock();
	void unlock();

    private:
	volatile uint64_t iv_reserve;
	volatile uint64_t iv_ready;
};

#endif
