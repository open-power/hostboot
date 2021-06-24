# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/simics/validate-hb-nfs-dir.py $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2020,2021
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

######
# @file A brief script to validate user input for the HB_NFS_DIR environment variable, the existence of which will
#       trigger an auto-boot and auto-patch of Denali simics.
#####

import sys
import os

# @brief A helper function to get the basename (the last path element) from a path. Since the user could leave a
#        trailing "/" this function deals with both cases.
#
# @param[in]    nfsPath      A path to the nfs directory where the hostboot code patches for FSP reside.
#
# @return       string       The last path element from the given path. Ex. "/path/to/nfs/" returns "nfs"
def getBasename(nfsPath):
    # basename will be the final dir in the given path or None if there is a trailing "/" at the end of nfsPath
    # path will be the path after having stripped off basename or the full path with a trailing "/" removed
    path, basename = os.path.split(nfsPath)

    # If basename is not None then that is the basename we want to return. Otherwise, grab it from path and return.
    return basename or os.path.basename(path)

# @brief A helper function to get the path without a trailing "/" if one exists.
#
# @param[in]    nfsPath      A path to the nfs directory where the hostboot code patches for FSP reside.
#
# @return       string       The path without a trialing "/". Ex. "/path/to/nfs/" returns "/path/to/nfs"
def getPath(nfsPath):
    # This will remove any trailing "/" at the end of the given path
    path, basename = os.path.split(nfsPath)

    if basename:
        # If basename is not None then path will have lost that dir off the end.
        # Add it back so caller has full path to work with.
        path = path + "/" + basename
    return path

# @brief Validates the nfs path retrieved from the environment variable HB_NFS_DIR in main. If the path is incorrect
#        two things could happen: The return path will be corrected to point to /path/to/nfs if the path is trivially
#        correctable. Otherwise, the return path will be changed to None which will signal to the caller that input was
#        bad and automation shouldn't continue.
#
# @param[in]    nfsPath      A path to the nfs directory where the hostboot code patches for FSP reside.
#
# @return       string or None    The validated path which has the last path element as "nfs" or None if the input was
#                                 bad.
def validateNfsPath(nfsPath):

    if nfsPath != None:
        # Get the dir at the end of the nfs path.
        currentBaseName = getBasename(nfsPath)
        # Strip off any trailing "/" from the given nfs path.
        nfsPath = getPath(nfsPath)

        if currentBaseName != "nfs":

            if currentBaseName == "pnor":
                # Strip off test/pnor/
                nfsPath = os.path.dirname(os.path.dirname(nfsPath))

            elif currentBaseName == "test":
                # Strip off test/
                nfsPath = os.path.dirname(nfsPath)

            # Verify that nfs is now the basename.
            currentBaseName = getBasename(nfsPath)
            if currentBaseName != "nfs":
                # Path not correct or easily correctable.
                nfsPath = None

    return nfsPath

# @brief Python main function
if __name__ == "__main__":
    try:
        nfsDir = validateNfsPath(os.environ['HB_NFS_DIR'])
        if nfsDir == None:
            print ("WARNING: Final dir in path" + os.environ['HB_NFS_DIR'] + " was not nfs. Path validation failed, continue at your own discretion.")
            # Restore the old path
            nfsDir = os.environ['HB_NFS_DIR']

        # Set env var to the validated path
        os.environ['HB_NFS_DIR'] = nfsDir
    except KeyError:
        # Script was called with environment variable undefined.
        print ("Path to nfs directory with hostboot patches doesn't exist. Skipping auto-patch and auto-boot.")
