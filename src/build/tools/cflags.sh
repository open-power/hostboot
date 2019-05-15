#!/bin/bash
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/cflags.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2019
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

# The purpose of this script is to convert a series of GCC compiler
# flags into an equivalent series of flags, but which use absolute
# paths for include directories (i.e. the "-I" flag) instead of
# relative paths. We have to do this when GCOV is in use, because it
# stupidly puts data files in one path but stores paths inside the
# data files that are relative to some other path. When GCOV then
# tries to read the source files via these relative paths, it can't
# find the files. We correct this by converting all paths to source
# and header files to absolute paths.

if [ ! "$HOSTBOOT_PROFILE" ] ; then
    echo "$@"
    exit
fi

make_path_abs () {
    local ABSPATH
    ABSPATH=$(readlink -f "$1")

    if [ $? -ne 0 ] ; then
        ABSPATH="$1"
    fi

    echo -n "$ABSPATH"
}

while [ "$#" -gt 0 ] ; do
    FLAG="$1"

    if [ "$FLAG" = "-I" ] ; then
        shift
        echo -n "-I $(make_path_abs "$1") "
    elif [ "${FLAG:0:2}" = "-I" ] ; then
        echo -n "-I $(make_path_abs "${FLAG:2}") "
    else
        echo -n "$FLAG "
    fi

    shift
done

echo
