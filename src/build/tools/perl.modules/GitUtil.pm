# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/perl.modules/GitUtil.pm $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015
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
package GitUtil;

use strict;
use Data::Dumper;
use Switch;
use Cwd;
use List::Util 'max';
# Include custom modules
use lib "$ENV{'PERLMODULES'}";
use ToolInit;
use GerritUtil;

# Grab initial globals from ToolInit module
my %globals = init_globals;

######################## Begin Git Utility Subroutines #########################

# sub remote
#
# Gets the remote name of the specified project in a local git repostiory
#
# @param[in] git_root - The root of the local git repository.
# @param[in] project - The project desired relative to the remote base.
#
# @return string - Remote name that matches project for local repository.
#
sub remote
{
    my ($i_git_root, $i_project) =  @_;
    chdir($i_git_root);
    my $o_remote = "";

    # Get all remotes in local repo
    my @remotes = split('\n', `git remote`);

    die ("Git remotes not found in $i_git_root") if (!@remotes);

    # Search local remotes for correct project
    foreach my $remote (@remotes)
    {
        my $url = `git config --get remote.$remote.url`;
        chomp $url;

        die "Undefined git-remote '$remote'" if ($url eq "");
        die "Unexpected url found: $url" if (not ($url =~ m/ssh:\/\/.*\/.*/));

        # Only care about urls that match the specified remote server
        die "remote server not defined" if (!defined $globals{remote_server});
        next if ($url !~ m/$globals{remote_server}/);

        my $project = $url;
        $project =~ s/ssh:\/\/$globals{remote_server}\///;

        if ($i_project eq $project)
        {
            $o_remote = $remote;
        }
    }

    die ("$i_project not found in remotes in $i_git_root") if ($o_remote eq "");
    return $o_remote;
}

# sub root
#
# Determines the path of the root of the git repository.
#
# @return string - Root of the git repository.
#
sub root
{
    open COMMAND, "git rev-parse --show-toplevel |";
    my $root = <COMMAND>;
    close COMMAND;
    chomp $root;

    die "Unable to determine git_root" if ($root eq "");
    print "Found git_root at $root\n" if $debug;

    return $root;
}

# sub clone
#
# Clones git repository specified into git directory
#
# @param[in] i_location - Location to clone into
# @param[in] i_project - Project to clone, relative to gerrit server
# @param[in] i_dir - Directory to clone to, overriding default name
#
sub clone
{
    my ($i_location, $i_project, $i_dir) =  @_;
    chdir($i_location);

    # Check if caller provides full url for i_project
    if ($i_project =~ m/ssh:\/\//)
    {
        system("git clone $i_project $i_dir -q");
        die ("$?") if ($?);
    }
    else
    {
        die "remote server not defined" if (!defined $globals{remote_server});
        system("git clone ssh://$globals{remote_server}/$i_project $i_dir -q");
        die ("$?") if ($?);
    }
}

use constant
{
    STAGED => 1,
    NOT_STAGED => 2,
    TRACKED => 3,
    UNTRACKED => 4,
};

# sub status
#
# Run git status command to check state of git repoistory passed in
#
# See git status --help for info on porcelain format
#
# @param[in] i_git_root - The root of the git repository to check.
# @param[in] i_status - Type of status to check for
#
sub status
{
    my ($i_git_root, $i_status) =  @_;
    chdir($i_git_root);
    my $num = 0;

    # Shorten lines below
    my $git_cmd = "git status --porcelain 2>/dev/null|";
    switch ($i_status)
    {
        case (STAGED)
        {
            # Get number of file changes staged for commit
            $num = `$git_cmd egrep "^(M|A|D|R|C)" | wc -l`;
        }
        case (NOT_STAGED)
        {
            # Get number of file changes not staged for commit
            $num = `$git_cmd egrep "^(\\\?\\\?| M| D)" | wc -l`;
        }
        case (TRACKED)
        {
            # Get number of tracked changes, staged and not staged
            $num = `$git_cmd egrep "^(M| M|D| D|R)" | wc -l`;
        }
        case (UNTRACKED)
        {
            # Get number of untracked files, staged and not staged
            $num = `$git_cmd egrep "^(\\\?\\\?|A)" | wc -l`;
        }
        else
        {
            die "Git status $i_status not supported";
        }
    }

    die ("$?") if ($?);
    return $num;
}

# sub dirty
#
# Determines if git repository is Dirty.
# Dirty - any staged or not staged changes
#
# @param[in] i_git_root - The root of the git repository to check.
#
# @return bool - 1 if dirty.
#
sub dirty
{
    my $i_git_root = shift;
    if ( (status($i_git_root,STAGED) +
          status($i_git_root,NOT_STAGED)) > 0 )
    {
        return 1;
    }
    return 0;
}

# sub staged
#
# Determines if git repository has only staged changes.
#
# @param[in] i_git_root - The root of the git repository to check.
#
# @return bool - 1 if staged only.
#
sub staged
{
    my $i_git_root = shift;
    if ( (status($i_git_root,NOT_STAGED) <= 0) &&
         (status($i_git_root,STAGED) > 0) )
    {
        return 1;
    }
    return 0;
}

# sub clean
#
# Determines if git repository has nothing staged and only untracked changes
#
# @param[in] i_git_root - The root of the git repository to check.
#
# @return bool - 1 if untracked only.
#
sub clean
{
    my $i_git_root = shift;
    if ( (status($i_git_root,TRACKED) +
          status($i_git_root,STAGED)) > 0 )
    {
        return 0;
    }
    return 1;
}

# sub fetch
#
# Fetches the contents of a remote revision (refs/changes/*) to the local
# git repository.
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_remote - Remote to fetch from.
# @param[in] i_ref - The revision to fetch from the Gerrit server [optional].
# @param[in] i_project - The project to query [optional]
# @param[in] i_branch - The branch in the project to query [optional]
# @param[in] i_verbose - Display output of fetch for user to use [optional]
#
sub fetch
{
    my ($i_git_root, $i_remote, $i_ref, $i_project, $i_branch, $i_verbose) =  @_;
    chdir($i_git_root);

    # Check if ref is a change-id or commit and fetch from gerrit server
    if (GerritUtil::is_patch($i_ref) || is_commit($i_ref))
    {
        my $patch = GerritUtil::query_current_patchset($i_ref, $i_project,
                                                       $i_branch);
        $i_ref = $patch->{currentPatchSet}->{ref};
    }

    ($i_verbose) ? my $quiet  = "" : my $quiet = "-q";

    system("git fetch $i_remote $i_ref $quiet");
    die ("Could not find ref = $i_ref in remote = $i_remote") if ($?);
}

# sub reset
#
# Reset --hard current HEAD of git repository to the specified reference
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_remote - Remote to fetch from.
# @param[in] i_ref - The reference to fetch from the remote server.
#
sub reset
{
    my ($i_git_root, $i_remote, $i_ref) =  @_;
    chdir($i_git_root);

    # Check if commit is referenced locallay
    unless (GerritUtil::is_patch($i_ref))
    {
        system("git reset --hard $i_ref");
        die ("Could not resolve commit, may need rebase") if ($?);
    }
    # Try fetching change-id from remote
    else
    {
        fetch(cwd(),$i_remote,$i_ref);
        system("git reset --hard FETCH_HEAD");
        die ("$?") if ($?);
    }

}

# sub hooks
#
# Copies git hooks from remote server into local git repository
#
# @param[in] i_git_root - The root of the local git repository.
#
sub hooks
{
    my ($i_git_root) = @_;
    chdir($i_git_root);

    die "remote server not defined" if (!defined $globals{remote_server});
    system("scp -p -q $globals{remote_server}:hooks/commit-msg $i_git_root/.git/hooks");
    die ("$?") if ($?);
}

# sub add
#
# Stage all changes in a git repository for commit
#
# @param[in] i_git_root - The root of the local git repository.
#
sub add
{
    my ($i_git_root) = @_;
    chdir($i_git_root);

    system("git add -A .");
    die ("$?") if ($?);
}

# sub commit
#
# Commit all changes staged for commit in a git repository
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_amend - Amend commit in $GIT_ROOT [default 0].
#
sub commit
{
    my ($i_git_root, $i_amend) = @_;
    chdir($i_git_root);

    if ($i_amend)
    {
        system("git commit --amend");
    }
    else
    {
        system("git commit");
    }
    die ("$?") if ($?);
}

# sub resolve_ref
#
# Transforms a symbolic git reference into a commit number.
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_remote - Remote to fetch from.
# @param[in] i_ref - The reference to resolve.
#
# @return string - Resolved git commit number.
#
sub resolve_ref
{
    my ($i_git_root, $i_remote, $i_ref) = @_;
    chdir($i_git_root);

    my $resolve = "";

    if (GerritUtil::is_patch($i_ref))
    {
        my $gerrit = GerritUtil::resolve_patch($i_git_root,
                                               $i_remote,[$i_ref]);
        $resolve = $gerrit;
    }
    else
    {
        $resolve = `git log -n1 --pretty=\"%H\" $i_ref`;
        die ("Could not resolve commit, may need rebase") if ($?);
        chomp $resolve;

    }

    die "Unable to resolve ref $i_ref" if ($resolve eq "");
    print "Resolved $i_ref as $resolve\n" if $debug;

    return $resolve;
}

# sub order_commits
#
# Order a list of commits so that they are in a good order with regard to
# dependencies.  The order returned should be the most likely to not fail
# a cherry-pick sequence.
#
# @param[in] i_base - The base to apply patches to.
# @param[in] i_patches - The list of commits to order.
#
# @return array - Re-ordered list of commits (from patches).
#
sub order_commits
{
    my ($i_base, $i_patches) = @_;
    my @result = ();

    # Create patch -> { distance -> 0, deps -> [] } hash.
    my %patch_hash =
        map { $_ => \{ distance => 0, deps => [] }} @{$i_patches};

    # Determine dependencies and distance for each patch.
    foreach my $patch (@{$i_patches})
    {
        # Add dependencies for each patch to the hash.
        my $deps = commit_deps($i_base, $patch);
        push @{${$patch_hash{$patch}}->{deps}}, @{$deps};

        # Determine the distance from previous release for each patch.
        ${$patch_hash{$patch}}->{distance} =
            scalar @{commit_history($patch, $i_base)};
    }

    # Calculate Dijkstra's on the patches.
    my $changed = 1;
    while ($changed != 0)
    {
        $changed = 0;
        foreach my $patch (@{$i_patches})
        {
            my $distance = 1 + max( map
                    { ${$patch_hash{$_}}->{distance}}
                    @{${$patch_hash{$patch}}->{deps}});

            if ($distance > ${$patch_hash{$patch}}->{distance})
            {
                $changed = 1;
                ${$patch_hash{$patch}}->{distance} = $distance;
            }
        }
    }

    # Sort the patches based on shortest distance from previous release
    # (after Dijkstra).
    my @commit_order =
        sort { ${$patch_hash{$a}}->{distance} <=>
                    ${$patch_hash{$b}}->{distance} }
        @{$i_patches};
    return \@commit_order;
}

# sub commit_deps
#
# Determines a list of dependent commits based on common files touched.
#
# @param[in] base - The end point, in git history, of commits to compare.
# @param[in] commit - The commit to find dependents of.
#
# @return array - List of dependent commits.
#
sub commit_deps
{
    my $base = shift;
    my $commit = shift;
    chomp($base);
    chomp($commit);

    my @deps = ();

    print "Searching for deps for $commit against $base\n" if $debug;

    open COMMAND, "git diff-tree --name-only --no-commit-id -r $commit --diff-filter CMRT| ".
                  "xargs git rev-list $commit~1 ^$base -- |";
    while (my $line = <COMMAND>)
    {
        print "Found dep: $line" if $debug;

        chomp $line;
        push @deps, $line;
    }
    close COMMAND;

    return \@deps;
}

# sub commit_history
#
# Determines all the commits between two points in git history.
#
# @param[in] start - Beginning commit.
# @param[in, optional] not_including - Starting point to exclude.
#
# @return array - Commit history.
#
sub commit_history
{
    my $start = shift;
    my $not_including = shift;

    my @commits = ();

    unless ($not_including eq "") { $not_including = "^".$not_including; }

    open COMMAND, "git rev-list --cherry-pick $start $not_including |";
    while (my $line = <COMMAND>)
    {
        chomp $line;
        push @commits, $line;
    }
    close COMMAND;

    return \@commits;
}

# sub checkout
#
# Checkout specified reference in git repository
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_remote - Remote to fetch from.
# @param[in] i_ref - The reference to fetch from the remote server.
#
sub checkout
{
    my ($i_git_root, $i_remote, $i_ref) =  @_;
    chdir($i_git_root);

    my $base = top_commit($i_git_root);

    # Check if commit is referenced locally or is a non-commit reference
    # (e.g. FETCH_HEAD, master, remote tag)
    if ($i_remote eq "" || !is_commit($i_ref) || commit_local($base,
                                                              $i_ref))
    {
        system("git checkout $i_ref -q");
        die ("Could not resolve commit, may need rebase") if ($?);
    }
    else
    {
        fetch(cwd(),$i_remote,$i_ref);
        system("git checkout FETCH_HEAD -q");
        die ("$?") if ($?);
    }
}

# sub checkout_branch
#
# Create/Checkout branch in git repository
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_branch - The refer.
# @param[in] i_base - The reference to base the branch on.[optional]
#
sub checkout_branch
{
    my ($i_git_root, $i_remote, $i_branch, $i_base) =  @_;
    chdir($i_git_root);

    my $base = top_commit($i_git_root);

    # Check if commit is referenced locally or is a non-commit reference
    # (e.g. FETCH_HEAD, master, remote tag)
    if ($i_remote eq "" || !is_commit($i_base) || commit_local($base,
                                                               $i_base))
    {
        system("git checkout -b $i_branch $i_base -q");
        die ("Could not resolve branch base = $i_base") if ($?);
    }
    # Try fetching change-id/commit from remote
    else
    {
        fetch(cwd(),$i_remote,$i_base);
        system("git checkout -b $i_branch FETCH_HEAD -q");
        die ("$?") if ($?);
    }
}

# sub cherry_pick
#
# Cherry-pick a commit onto the current branch.
#
# @param[in] commit - The commit to cherry-pick.
#
# @retval false - Error occurred during cherry-pick.
sub cherry_pick
{
    my $commit = shift;

    system("git cherry-pick -x $commit");
    return ($? == 0);
}

# sub top_commit
#
# Get top commit on current branch
#
# @param[in] i_git_root - The root of the local git repository.
#
# @retval commit - Top commit on current branch.
sub top_commit
{
    my ($i_git_root) =  @_;

    chdir($i_git_root);
    return `git rev-parse HEAD`;
}

sub init
{
    system("git init -q");
    die $? if ($?);
}

# sub delete_branch
#
# Delete a git branch
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_branch - Branch to delete.
#
sub delete_branch
{
    my ($i_git_root, $i_branch) =  @_;
    chdir($i_git_root);

    system("git branch -D $i_branch -q");
    die "Failed to delete branch $i_branch" if ($?);
}

# sub commit_msg
#
# Get the entire commit message associated with a commit.
#
# @param[in] i_commit - The commit to examine.
#
# @return string - The commit message.
#
sub commit_msg
{
    my $i_commit = shift;

    open COMMAND, "git log -n1 --pretty=%B $i_commit |";
    my $message = "";
    while (my $line = <COMMAND>)
    {
        $message = $message.$line;
    }
    close COMMAND;

    return $message;
}

# sub retrieveChangeIds
#
# Get the change Id associated with the commit
#
# @param[in] i_commit - The commit to examine.
#
# @return @Ids - The array of change Ids
#
sub retrieveChangeIds
{
    my $i_commit = shift;
    my @Ids;
    my $message = commit_msg($i_commit);
    if ($message =~ m/Change-Id:\s*(I[0-9a-z]+)/)
    {
        push @Ids, $1;
    }
    if ($message =~ m/Original-Change-Id:\s*(I[0-9a-z]+)/)
    {
        push @Ids, $1;
    }
    if($#Ids < 0)
    {
        die "\nERROR: Invalid Commit, cannot get the Change ID\n";
    }
    return @Ids;
}

# sub commit_local
#
# Checks if commit is in local tree
#
# @param[in] i_commit - The commit to examine.
#
# @return bool - true if in local tree
#
sub commit_local
{
    my ($i_base, $i_commit) = @_;
    chomp($i_base);
    chomp($i_commit);

    die "Based is not of type commit (SHA hash)" if (!is_commit($i_base));

    # Git log will fail if not valid change-id or commit. Note order is check
    # for change-id first as it will also match the regex for is_commit
    if (GerritUtil::is_patch($i_commit))
    {
        `git log $i_base | grep "Change-Id: $i_commit"`;
        ($?) ? return 0 : return 1;
    }
    elsif(is_commit($i_commit))
    {
        # Note '^commit' used to avoid finding the commit in the commit message
        # somewhere
        `git log $i_base | grep "^commit $i_commit"`;
        ($?) ? return 0 : return 1;
    }
    else
    {
        die "Commit is not of type commit or change-id";
    }
}

# sub is_commit
#
# Determines if a patch identifier is a git commit id or not.
#
# @param[in] i_ref - The reference to make determination about.
#
# @return bool - Ref is in the style of a git commit
sub is_commit
{
    my $i_ref = shift;
    chomp($i_ref);

    ($i_ref =~ m/[0-9a-f]{7,40}/) ? return 1 : return 0;
}

sub cherry_pick_commits
{
    my ($i_git_root, $i_base, $i_commits, $i_verbose) = @_;

    chdir($i_git_root);
    die $? if ($?);

    # Order commits
    my $commit_ref = order_commits($i_base,$i_commits);
    if ($debug)
    {
        print "Determined commit order as:\n";
        foreach my $commit (@{$commit_ref})
        {
            print "\t$commit\n";
        }
    }

    print "\nApplying commits...\n";
    my @cp_failures = ();
    foreach my $commit (@{$commit_ref})
    {
        # Skip over commits that are already in the base. Some tooling has
        # old information, for a reason, but does not need to be applied as the
        # base is updated
        next if(commit_local($i_base, $commit));

        print "\nApplying $commit:\n";
        # If cherry-pick fails, continue on and store failed commit
        if(!cherry_pick($commit))
        {
            # Clear out failed cherry-pick
            print "Reverting $commit as cherry-pick failed.\n";
            system("git reset HEAD --hard");
            push @cp_failures, $commit;
        }
    }
    if (@cp_failures)
    {
        print "\n**Following Cherry-picks failed:\n";
        foreach my $commit (@cp_failures)
        {
            print_commit($commit,$i_verbose);
        }
    }
    else
    {
        print "\nAll Cherry-picks applied cleanly\n";
    }
}

####################### Begin Print Utility Subroutines ########################

# sub print_diff_help
#
# Print a reference for what different file change marks mean.
#
sub print_diff_help
{
    print
    q(
Diff-filter Guide:
        A - Added
        C - Copied
        D - Deleted
        M - Modified
        R - Renamed
        T - Have their type (mode) changed
    );
}

# sub print_commit
#
# Print info about commit
#
# @param[in] i_commit - Commit number.
# @param[in] i_verbose -   Verbose display
#
sub print_commit
{
    my ($i_commit, $i_verbose) = @_;

    my $pretty_format = " --pretty=format:'%Cred%h%Creset - %s %Cgreen(%ci) ";
    $pretty_format.="%C(bold blue)<%ae>%Creset'";

    if ($i_verbose)
    {
        print `git show --name-status $pretty_format $i_commit --diff-filter ACDMRT`."\n";
    }
    else
    {
        print $i_commit."\n";
    }
}

# Perl module must return true value
1;
