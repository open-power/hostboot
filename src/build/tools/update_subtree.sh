#!/usr/bin/env bash
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/update_subtree.sh $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2021,2022
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

#    update_subtree.sh
#
#    Author: Christian Geddes (crgeddes@us.ibm.com)
#
#    Hostboot developers sometimes want to make changes to the local
#    subtree that are not in the upstream repo yet. This can make
#    pulling in the latest upstream changes difficult. This script
#    eases that process.

function usage()
{
    echo "Hostboot developers sometimes want to make changes to the local"
    echo "subtree that are not in the upstream repo yet. This can make"
    echo "pulling in the latest upstream changes difficult. This script"
    echo "eases that process."
    echo ""
    echo "update_subtree.sh"
    echo "    -h --help"
    echo "    -p --push"
    echo "    -r --reviewer=<reviewer email>"
    echo "    -s --subtree=<subtree>"
    echo ""
    echo "Subtrees that are currently supported: $SUPPORTED_SUBTREES"
}

PUSH_COMMITS="0"
SUPPORTED_SUBTREES="pldm,libmctp"
REVIEWER=""
SUBTREE="wrong"

while [ "$1" != "" ]; do
    PARAM=`echo $1 | awk -F= '{print $1}'`
    VALUE=`echo $1 | awk -F= '{print $2}'`
    case $PARAM in
        -h | --help)
            usage
            exit
            ;;
        -p | --push)
            PUSH_COMMITS="1";
            ;;
        -r | --reviewer)
            REVIEWER=$VALUE;
            ;;
        -s | --subtree)
            SUBTREE=$VALUE;
            ;;
        *)
            echo "ERROR: unknown parameter \"$PARAM\""
            usage
            exit 1
            ;;
    esac
    shift
done

# Expecting input format to be in a format like '2.10.0'.
# Will return success (i.e. 0) if the current git version is greater than or
# equal to the given version (meaning the feature is supported). Otherwise,
# this will return a non-zero value.
function check_git_version()
{
    local given=(${1//./ })

    local current=`git version | awk '{print $3}'`
    current=(${current//./ })

    if [ ${current[0]} -gt ${given[0]} ]; then
        return 0
    elif [ ${current[0]} -eq ${given[0]} ]; then
        if [ ${current[1]} -gt ${given[1]} ]; then
            return 0
        elif [ ${current[1]} -eq ${given[1]} ]; then
            if [ ${current[2]} -ge ${given[2]} ]; then
                return 0
            fi
        fi
    fi

    return 1
}

if !(echo "$SUPPORTED_SUBTREES" | grep -w -q "$SUBTREE") ; then
  echo "  Error! Must specify a valid subtree to use!"
  echo "  Subtrees that are currently supported: $SUPPORTED_SUBTREES"
  exit 1
fi


# Check if we are in a hostboot repository directory
if [ `ls ./example_customrc 2>/dev/null | wc -c` -eq 0 ] > /dev/null 2>&1; then
  echo "Error! This script is expected to be ran from the top-level of a hostboot repository. cd to that directory and try again."
  exit 1
fi

# Just in case the tool is not run in a hb workon.
if [ -z "${HOSTBOOT_INSIDE_WORKON}" ]; then
    . ./env.bash
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

# Keep track of the current top commit's ID.
CURRENT_TOP_COMMIT=$(git rev-parse --short HEAD)

# Find the Change-Id of the subtree's last sync with the upstream repo.
LAST_SYNC_CHANGE_ID=$(grep $SUBTREE src/subtree/latest_commit_sync | awk '{print $2}')
if [ -z $LAST_SYNC_CHANGE_ID ]; then
    echo "Unable to find Change-Id subtree: $SUBTREE"
    exit 1
fi

# Get the commit ID of the last synched commit from the current working tree.
LAST_SYNC_COMMIT=$(git log --grep $LAST_SYNC_CHANGE_ID --format="%h")
if [ -z $LAST_SYNC_COMMIT ]; then
    echo "Unable to find commit ID for Change-Id: $LAST_SYNC_CHANGE_ID"
    exit 1
fi

# Figure out all of the changes we have made to the subtree between now and
# the last sync commit. Note this command will create outstanding changes
# that undo all of the downstream work hostboot has done on the subtree
# that has not been upstreamed yet
git checkout $LAST_SYNC_COMMIT -- src/subtree/openbmc/$SUBTREE/*
diff_found=0

# If outstanding changes are detected we know there are some changes
# that we want to try to patch after updating from upstream
if ! git diff-index --quiet HEAD --; then
    echo "Changes have been made to src/subtree/openbmc/$SUBTREE locally since the last sync, creating a patch that apply these changes post sync"
    diff_found=1
    git add --a
    # temporarily commit the changes, this will undo all of the downstream edits hostboot has done
    git commit -m "Revert $SUBTREE changes from $LAST_SYNC_COMMIT to $CURRENT_TOP_COMMIT"  > /dev/null 2>&1
    # revert the commit we just did so we can build a single patch with all of the edits we have done
    git revert HEAD --no-edit > /dev/null 2>&1
    # commit the revert
    git commit --amend -m "Reapply $SUBTREE subtree changes made from $LAST_SYNC_COMMIT to $CURRENT_TOP_COMMIT"  > /dev/null 2>&1
    # generate a patch of the revert, this patch will allow us to reapply all of
    # the downstream edits after syncing to latest openbmc/subtree
    git format-patch HEAD~1
    # reset back to the state prior to the temporary commit we created above
    git reset HEAD~2 --hard
fi

echo "Updating subtree with changes from remote.."
# add the bmc-subtree remote repository
git remote add bmc-$SUBTREE  https://github.com/openbmc/$SUBTREE.git > /dev/null 2>&1
# update the bmc-subtree remote repository
git fetch bmc-$SUBTREE > /dev/null 2>&1
# we will put the top level commit from the BMC repo in the commit message of the subtree update commit
BMC_SUBTREE_TOP_COMMIT=`git rev-parse --short bmc-$SUBTREE/master`

# Forcefully subtree update to the latest openbmc/subtree master branch, discard all local changes
CMD="git merge --squash -s recursive -Xsubtree=src/subtree/openbmc/$SUBTREE -Xtheirs bmc-$SUBTREE/master"
if check_git_version '2.10.0'; then
    CMD="${CMD} --allow-unrelated-histories"
fi
$CMD

# Check for any new changes.
if [ -z "$(git status --porcelain)" ]; then
    echo "No changes since last sync commit: $LAST_SYNC_COMMIT"

    # Reset the history back to the were we began.
    git reset --hard $CURRENT_TOP_COMMIT

    # Clean up patch files, if they exist.
    rm -f 0001-Reapply-$SUBTREE-subtree-changes-made-from-*

    # Nothing more to do.
    exit 0
fi

# If there are still merge conflicts because git thinks 'both' parties have added the
# file, explicitly checkout 'our' version of the file(s) and then add the files.
BOTH=$(git status --porcelain | grep 'AA' | awk '{print $2}')
if [ -n "$BOTH" ]; then
    echo "$BOTH" | xargs git checkout --ours
    echo "$BOTH" | xargs git add
fi

# Create a commit with the changes generated from the merge
git commit -m "Update to latest openbmc/$SUBTREE commit $BMC_SUBTREE_TOP_COMMIT" > /dev/null 2>&1

# Get the new sync Change-Id and stored it.
NEW_SYNC_CHANGE_ID=`git log -1 | grep "Change-Id" | awk '{print $2}'`

echo "Updating src/subtree/latest_commit_sync .."
sed -i "s/$SUBTREE $LAST_SYNC_CHANGE_ID/$SUBTREE $NEW_SYNC_CHANGE_ID/g" src/subtree/latest_commit_sync
git add src/subtree/latest_commit_sync

if ! git diff-index --quiet HEAD --; then
  git commit --amend --no-edit
fi

# if we generated a patch above, try to apply it
if [ $diff_found -eq 1 ]; then
  echo "Attempting to apply changes found earlier"
  # do a 3 way merge
  git am -3 0001-Reapply-$SUBTREE-subtree-changes-made-from-*
fi

if [ "$PUSH_COMMITS" == "1" ]; then
  git push origin HEAD:refs/for/master-p10
  if [ "$REVIEWER" != "" ]; then
      echo "Adding $REVIEWER as a reviewer to ${NEW_SYNC_CHANGE_ID}"
      ssh gerrit gerrit set-reviewers -p hostboot -a ${REVIEWER} ${NEW_SYNC_CHANGE_ID}
  fi
fi

# Clean up patch files, if they exist.
rm -f 0001-Reapply-$SUBTREE-subtree-changes-made-from-*
