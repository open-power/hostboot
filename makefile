# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: makefile $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2010,2014
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
# implied. See the License for the specific language governing
# permissions and limitations under the License.
#
# IBM_PROLOG_END_TAG
SUBDIRS = src.d
ROOTPATH = .

IMAGE_PASS_POST += $(GENDIR)/hwp_id.html
CLEAN_TARGETS   += $(GENDIR)/hwp_id.html
ifndef BUILD_MINIMAL
IMAGE_PASS_POST += cscope ctags
endif
IMAGE_PASS_POST += check_istep_modules

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

$(GENDIR)/hwp_id.html :
	$(ROOTPATH)/src/build/tools/hwp_id.pl -i -l > $@

.PHONY: check_istep_modules
check_istep_modules: $(OBJS)
	listdeps.pl $(IMGDIR)  -v


