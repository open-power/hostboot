#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/duplibs.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2018
# [+] International Business Machines Corp.
#
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

#####################################################
# Checks for duplicate objects in multiple libraries
#####################################################

for i in `ls -R $@ | grep '\.o$' | sort -u`
#for i in `ls -R obj/modules/ | grep '\.o$' | sort -u`
  do
      f=(`find $@ -name $i`)
      if [ ${#f[@]} -gt 2 ]
        then
          echo "=== file $i appears ${#f[@]} times in:"
          for j in ${f[@]}
            do
              dir=`dirname $j`
              #size=`ls -al $j | cut -f 5 -d' '`
              echo "  $dir"
          done
      fi
done
