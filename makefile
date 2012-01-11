#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: makefile $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2010 - 2012
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END
SUBDIRS = src.d
ROOTPATH = .

EXTRA_PARTS = cscope ctags

include ./config.mk

docs: src/build/doxygen/doxygen.conf
	rm -rf obj/doxygen/*
	doxygen src/build/doxygen/doxygen.conf

citest:
	src/build/citest/cxxtest-start.sh

gcov:
	rm -rf obj/gcov/*
	make gcov_pass
	find obj/gcov/ -size 0c | xargs rm # Delete empty files.
	genhtml obj/gcov/*.lcov -o obj/gcov/html
	echo "View GCOV results with: firefox obj/gcov/html/index.html"

