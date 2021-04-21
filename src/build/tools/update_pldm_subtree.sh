#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/update_pldm_subtree.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021
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

#    update_pldm_subtree.sh
#
#    Author: Christian Geddes (crgeddes@us.ibm.com)
#
#    Hostboot developers sometimes want to make changes to the local
#    subtree that are not in the upstream openbmc/pldm repo yet. This
#    can make pulling in the latest upstream changes difficult. This
#    script eases that process.

# Check if we are in a hostboot repository directory
if [ `ls ./example_customrc 2>/dev/null | wc -c` -eq 0 ] > /dev/null 2>&1; then
  echo "Error! This script is expected to be ran from the top-level of a hostboot repository. cd to that directory and try again."
  exit 1
fi

# Check if there are any outstanding changes in the current branch
if ! git diff-index --quiet HEAD --; then
  echo "Error! Outstanding changes in this branch are detected. Clean up the outstanding changes in your current branch and try again."
  exit 1
fi

# Check if there are any untracked files in the current branch
if [ `git status --porcelain 2>/dev/null| grep "^??" | wc -l` -gt 0 ]; then
  echo "Error! An untracked file(s) is detected in this branch. Clean up this untracked file(s) and try again."
  exit 1
fi

# Find the last commit's short GUID that we used to sync with openbmc/pldm
LAST_SYNC_COMMIT=`grep pldm src/subtree/latest_commit_sync | awk '{print $2}'`
# Find the current commit's short GUID
CURRENT_TOP_COMMIT=`git rev-parse --short HEAD`

# Figure out all of the changes we have made to the pldm subtree between now and
# the last sync commit. Note this command will create outstanding changes
# that undo all of the downstream work hostboot has done on the subtree
# that has not been upstreamed yet
git checkout $LAST_SYNC_COMMIT -- src/subtree/openbmc/pldm/*
diff_found=0

# If outstanding changes are detected we know there are some changes
# that we want to try to patch after updating from upstream
if ! git diff-index --quiet HEAD --; then
    echo "Changes have been made to src/subtree/openbmc/pldm locally since the last sync, creating a patch that apply these changes post sync"
    diff_found=1
    git add --a
    # temporarily commit the changes, this will undo all of the downstream edits hostboot has done
    git commit -m "Revert PLDM changes from $LAST_SYNC_COMMIT to $CURRENT_TOP_COMMIT"  > /dev/null 2>&1
    # revert the commit we just did so we can build a single patch with all of the edits we have done
    git revert HEAD --no-edit > /dev/null 2>&1
    # commit the revert
    git commit --amend -m "Reapply PLDM subtree changes made from $LAST_SYNC_COMMIT to $CURRENT_TOP_COMMIT"  > /dev/null 2>&1
    # generate a patch of the revert, this patch will allow us to reapply all of
    # the downstream edits after syncing to latest openbmc/pldm
    git format-patch HEAD~1
    # reset back to the state prior to the temporary commit we created above
    git reset HEAD~2 --hard
fi

echo "Updating subtree with changes from remote.."
# add the bmc-pldm remote repository
git remote add bmc-pldm  https://github.com/openbmc/pldm.git > /dev/null 2>&1
# update the bmc-pldm remote repository
git fetch bmc-pldm > /dev/null 2>&1
# we will put the top level commit from the BMC repo in the commit message of the subtree update commit
BMC_PLDM_TOP_COMMIT=`git rev-parse --short bmc-pldm/master`
# Forcefully subtree update to the latest openbmc/pldm master branch, discard all local changes
git merge --squash -s recursive -Xsubtree=src/subtree/openbmc/pldm -Xtheirs bmc-pldm/master > /dev/null 2>&1
# Create a commit with the changes generated from the merge
git commit -m "Update to latest openbmc/pldm commit $BMC_PLDM_TOP_COMMIT" > /dev/null 2>&1

# store the new sync commit which will be used to update src/subtree/latest_commit_sync
NEW_SYNC_COMMIT=`git rev-parse --short HEAD`

# if we generated a patch above, try to apply it
if [ $diff_found -eq 1 ]; then
  echo "Attempting to apply changes found earlier"
  # do a 3 way merge
  git am -3 0001-Reapply-PLDM-subtree-changes-made-from-*
fi

echo "Updating src/subtree/latest/commit_sync .."
sed -i "s/pldm $LAST_SYNC_COMMIT/pldm $NEW_SYNC_COMMIT/g" src/subtree/latest_commit_sync
git add src/subtree/latest_commit_sync

# If the git am ran clean then we need to amend the latest_commit_sync changes
if ! git diff-index --quiet HEAD --; then
  git commit --amend --no-edit
fi

#cleanup patch
rm 0001-Reapply-PLDM-subtree-changes-made-from-*
