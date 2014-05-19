# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/beam/beam_parms.tcl $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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
##  Set maximum time to spend analyzing to 1 minute per 1000 lines of code.
##  The default is 5 minutes; there are a few files in HB that take
##  more than an hour with the default setting.

source beam_min_parms.tcl

set beam::max_time_per_kloc_in_sec "60"

# Allow empty functions to be considered 'stubs' and not report 'no effect'
# errors.
set beam::stub_function_contents "return_constant"

set allocateAnchored {allocator (anchored,
                      return_index=return) }

beam::function_attribute "$allocateAnchored" \
         -names "ERRORLOG::ErrlUserDetails::reallocUsrBuf"

# beam::function_attribute "anchor(index=1)" \
#          -names "std::vector::push_back,std::list::push_back"

