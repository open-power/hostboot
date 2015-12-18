# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/tools/perl.modules/GerritUtil.pm $
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
package GerritUtil;

use strict;
use Data::Dumper;
# Include custom modules
use lib "$ENV{'PERLMODULES'}";
use ToolInit;
use GitUtil;

# Grab initial globals from ToolInit module
my %globals = init_globals();

######################## Begin Gerrit Utility Subroutines ######################

# sub push
#
# Push commits in local git repository to gerrit server
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_remote - Remote to push to.
#
sub push
{
    my ($i_git_root, $i_remote) = @_;
    chdir($i_git_root);

    system("git push $i_remote HEAD:refs/for/master");
    die ("$?") if ($?);
}

# sub is_patch
#
# Determines if a patch identifier is a Gerrit patch or not.
#
# @param[in] i_patch - The patch to make determination about.
#
# @retval true - Patch is a Gerrit patch ID.
# @retval false - Patch does not appear to be a Gerrit patch ID.
sub is_patch
{
    my $i_patch = shift;
    chomp($i_patch);
    return 1 if ($i_patch =~ m/I[0-9a-f]+/);
    return 0;
}

# sub resolve_patch
#
# Resolves gerrit patch IDs to git commit numbers and ensures the git
# commits are fetched from the gerrit server.
#
# Any git commit number is left unchanged.
#
# @param[in] i_git_root - The root of the local git repository.
# @param[in] i_remote - Remote to fetch from.
# @param[in] i_patch - Patche to fetch.
# @param[in] i_patchset - Patchset to fetch. [0 or blank to get currentPatchSet]
#
# @return string - git commit number.
#
sub resolve_patch
{
    my ($i_git_root, $i_remote, $i_patch, $i_patchset) = @_;
    my $result = "";

    if (is_patch($i_patch))
    {
        # If latest wanted patchset <=0 or no patchset specified
        if($i_patchset <= 0 || $i_patchset eq "")
        {
            my $patch_info = query_current_patchset($i_patch);
            GitUtil::fetch($i_git_root, $i_remote,
                           $patch_info->{currentPatchSet}->{ref});
            $result = $patch_info->{currentPatchSet}->{revision};
        }
        # Patchset specified
        else
        {
            my $patch_info = query_patchsets($i_patch);
            # Fail if patchset DNE
            if ($i_patchset > $patch_info->{currentPatchSet}->{number})
            {
                die "$i_patch does not have patch number $i_patchset";
            }
            # JSON creates array of patchSets in number order
            my $index = $i_patchset - 1;
            GitUtil::fetch($i_git_root, $i_remote,
                           $patch_info->{patchSets}[$index]->{ref});
            $result = $patch_info->{patchSets}[$index]->{revision};
        }
    }
    else
    {
        $result = $i_patch;
    }

    return $result;
}

# sub query
#
# Performs a gerrit query and parses the resulting JSON.
#
# @param[in] i_query       - The query to perform.
#
# @return array - A list of items from the JSON query.  Each item is a
#                 hash (key-value pair) for the item attributes.
#
sub query
{
    my $i_query = shift;

    my @items = ();

    open COMMAND, ssh_command()." query $i_query --current-patch-set".
                  " --format=JSON |";
    while (my $line = <COMMAND>)
    {
        chomp $line;
        push @items, json_parse($line);
    }

    return \@items;
}

# sub query_commit
#
# Performs a gerrit query on a specific change-id or commit, can retrieve all
# or only current patchset via $patch_sets parameter.
#
# @param[in] commit     - The commit to query.
# @param[in] project    - The project to query [optional]
# @param[in] branch     - The branch in the project to query [optional]
# @param[in] patch_set  - Indicate patchset is not the currentPatchSet [optional]
#
# @return hash - The parsed JSON for the queried commit.
#
sub query_commit
{
    my ($commit, $project, $branch, $patch_set) = @_;

    $project = $globals{gerrit_project} if ($project eq "");
    $branch = $globals{branch} if ($branch eq "");

    # Get all patchsets, default no. This is important for performance.
    my $patch_sets = "";
    $patch_sets = "--patch-sets" if($patch_set == 1);

    # If --patch-sets and --current-patch-set flags are combined then the
    # current patch set information will be output twice, once in each field.
    my $query_result = query("$commit project:$project branch:$branch $patch_sets");
    foreach my $result (@{$query_result})
    {
        if ($result->{id} eq $commit  ||
            $result->{currentPatchSet}->{revision} =~ m/$commit/)
        {
            return $result;
        }
    }

    die "Cannot find $commit in $project:$branch";
}

# sub ssh_command
#
# Creates a properly formed ssh command based on the server address.
#
# @return string - The basic ssh command to connect to the server.
#
sub ssh_command
{
    my $server = $globals{remote_server};
    my $port = "";

    if ($server =~ m/.*:.*/)
    {
        $port = $server;
        $server =~ s/(.*):.*/$1/;
        $port =~ s/.*:(.*)/$1/;

        $port = "-p $port";
    }

    return "ssh -qx $port $server gerrit";
}

# sub current_patchset
#
# Get current patchset number of changd-id
#
# @param[in] i_patch - Change-id to get current patchset of.
#
# @return string - Number of currentPatchset
#
sub current_patchset
{
    my $i_patch = shift;

    die "Patch is not of type changd-id" if (!is_patch($i_patch));
    my $patch_info = query_current_patchset($i_patch);

    return $patch_info->{currentPatchSet}->{number};
}

# sub query_current_patchset
#
# Get current patchset info of a commit or change-id
#
# @param[in] i_commit - Change-id to get current patchset of.
#
# @return hash - The parsed JSON for the commit, only current patchset.
#
sub query_current_patchset
{
    my ($commit, $project, $branch) = @_;

    # Pass in 0 as last parameter to query only current patchset
    return query_commit($commit,$project,$branch,0);
}

# sub query_patchsets
#
# Get every patch set's info of a commit or change-id
#
# @param[in] i_commit - Change-id to get current patchset of.
#
# @return hash - The parsed JSON for the commit, containing all patchsets
#
sub query_patchsets
{
    my ($commit, $project, $branch) = @_;

    # Pass in 1 as last parameter to query all patchsets
    return query_commit($commit,$project,$branch,1);
}
# sub retrieve_change_ids
#
# Get the change Id associated with the commit
#
# @param[in] i_commit - The commit to examine.
#
# @return @Ids - The array of change Ids
#
sub retrieve_change_ids
{
    my $i_commit = shift;
    my @Ids;
    my $message = GitUtil::commit_msg($i_commit);
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

#################### Begin Gerrit JSON Utility Subroutines #####################

# sub json_parse
#
# Parse a line of JSON into an hash-object.
#
# @param[in] line - The JSON content.
#
# @return hash - The parsed object.
#
# @note There are perl modules for doing this but they are not installed on
#       the pool machines.  The parsing for JSON (at least the content from
#       the Gerrit server) isn't so bad...
#
sub json_parse
{
    my $line = shift;

    die "Invalid JSON format: $line" unless ($line =~ m/^\{.*\}$/);
    $line =~ s/^\{(.*)}$/$1/;

    my %object = ();

    while($line ne "")
    {
        my $key;
        my $value;

        ($key, $line) = json_get_string($line);
        $key =~ s/^"(.*)"$/$1/;

        $line =~ s/^://;
        if ($line =~ m/^"/)
        {
            ($value, $line) = json_get_string($line);
            $value =~ s/^"(.*)"$/$1/;
        }
        elsif ($line =~ m/^{/)
        {
            ($value, $line) = json_get_object($line);
            $value = json_parse($value);
        }
        elsif ($line =~ m/^\[/)
        {
            ($value, $line) = json_get_array($line);
            $value = json_parse_array($value);
        }
        else
        {
            $line =~ s/([^,]*)//;
            $value = $1;
        }

        $object{$key} = $value;
    }

    return \%object;
}

# sub json_parse_array
#
# Utility function for json_parse.
#
sub json_parse_array
{
    my $line = shift;

    $line =~ s/^\[(.*)\]$/$1/;

    my @array = ();

    while ($line ne "")
    {
        my $value;

        if ($line =~ m/^"/)
        {
            ($value, $line) = json_get_string($line);
            $value =~ s/^"(.*)"$/$1/;
        }
        elsif ($line =~ m/^\{/)
        {
            ($value, $line) = json_get_object($line);
            $value = json_parse($value);
        }
        elsif ($line =~ m/^\[/)
        {
            ($value, $line) = json_get_array($line);
            $value = json_parse_array($value);
        }
        else
        {
            $line =~ s/([^,]*)//;
            $value = $1;
        }

        push @array, $value;
        $line =~ s/^,//;
    }

    return \@array;
}

# sub json_get_string
#
# Utility function for json_parse.
#
sub json_get_string
{
    my $line = shift;

    $line =~ /("[^"]*")(.*)/;
    my $first = $1;
    my $second = $2;

    if ($first =~ m/\\"$/)
    {
        my ($more, $rest) = json_get_string($second);
        return ($first.$more , $rest);
    }
    else
    {
        return ($first, $second);
    }
}

# sub json_get_object
#
# Utility function for json_parse.
#
sub json_get_object
{
    my $line = shift;

    $line =~ s/^{//;
    my $object = "{";
    my $frag = "";

    my $found_object = 0;

    until ((not $found_object) && ($object =~ m/}$/))
    {
        $found_object = 0;

        if ($line =~ m/^\{/)
        {
            ($frag, $line) = json_get_object($line);
            $object = $object.$frag;
            $found_object = 1;
        }
        elsif ($line =~ m/^"/)
        {
            ($frag, $line) = json_get_string($line);
            $object = $object.$frag;
        }
        elsif ($line =~ m/^\[/)
        {
            ($frag, $line) = json_get_array($line);
            $object = $object.$frag;
        }
        elsif ($line =~ m/^[:,}]/)
        {
            $line =~ s/^([:,}])//;
            $frag = $1;
            $object = $object.$frag;
        }
        else
        {
            $line =~ s/([^,}]*)//;
            $frag = $1;
            $object = $object.$frag;
        }
    }

    return ($object, $line);
}

# sub json_get_array
#
# Utility function for json_parse.
#
sub json_get_array
{
    my $line = shift;

    $line =~ s/^\[//;
    my $array = "[";
    my $frag = "";

    my $found_array = 0;

    until ((not $found_array) && ($array =~ m/]$/))
    {
        $found_array = 0;

        if ($line =~ m/^\[/)
        {
            ($frag, $line) = json_get_array($line);
            $array = $array.$frag;
            $found_array;
        }
        elsif ($line =~ m/^\{/)
        {
            ($frag, $line) = json_get_object($line);
            $array = $array.$frag;
        }
        elsif ($line =~ m/^"/)
        {
            ($frag, $line) = json_get_string($line);
            $array = $array.$frag;
        }
        elsif ($line =~ m/^[:,\]]/)
        {
            $line =~ s/^([:,\]])//;
            $frag = $1;
            $array = $array.$frag;
        }
        else
        {
            $line =~ s/([^,]*)//;
            $frag = $1;
            $array = $array.$frag;
        }
    }

    return ($array, $line);
}

# Perl module must return true value
1;
