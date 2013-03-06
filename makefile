# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2010,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
SUBDIRS = src.d
ROOTPATH = .

IMAGE_PASS_BODY += $(GENDIR)/hwp_id.html $(IMGDIR)/hbotStringFile
CLEAN_TARGETS   += $(GENDIR)/hwp_id.html $(IMGDIR)/hbotStringFile
IMAGE_PASS_BODY += cscope ctags check_istep_modules

include ./config.mk

.PHONY: docs
docs: src/build/doxygen/doxygen.conf
	rm -rf obj/doxygen/*
	doxygen src/build/doxygen/doxygen.conf

.PHONY: citest
citest:
	src/build/citest/cxxtest-start.sh

.PHONY: gcov
gcov:
	rm -rf obj/gcov/*
	$(MAKE) gcov_pass
	find obj/gcov/ -size 0c | xargs rm # Delete empty files.
	genhtml obj/gcov/*.lcov -o obj/gcov/html --prefix `pwd` \
	    --title `git describe --dirty`
	@echo "View GCOV results with: firefox obj/gcov/html/index.html"

$(IMGDIR)/hbotStringFile : $(IMAGES)
	$(ROOTPATH)/src/build/trace/tracehash_hb.pl -c -d $(ROOTPATH)/obj -s $@

$(GENDIR)/hwp_id.html :
	$(ROOTPATH)/src/build/tools/hwp_id.pl -i -l > $@

.PHONY: check_istep_modules
check_istep_modules: $(OBJS)
	listdeps.pl $(IMGDIR)  -v


