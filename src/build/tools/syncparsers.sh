# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/syncparsers.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2023
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
export ERRL=$PROJECT_ROOT/obj/genfiles/errl/
export PLUGINS=$PROJECT_ROOT/obj/genfiles/plugins/

for pyfile in `find $ERRL $PLUGINS -name "*.py"`
do
   echo "----"
   echo $pyfile
   file=$(basename $pyfile)
   #echo $file
   srcfile=$(find $PROJECT_ROOT/src/ -name $file)
   echo $srcfile
   cp $pyfile $srcfile
done
