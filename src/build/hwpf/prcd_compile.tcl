#!/bin/sh
# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/hwpf/prcd_compile.tcl $
#
# OpenPOWER HostBoot Project
#
# COPYRIGHT International Business Machines Corp. 2011,2014
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
# The next line is executed by /bin/sh, but not tcl \
exec tclsh "$0" "$@" 

# Name: prcd_compile.tcl - Compile a hardware procedure remotely
#
# Based on if_make.tcl by Doug Gilbert


#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc getPassword { prompt } {
     exec stty -echo echonl <@stdin

     # Print the prompt
     puts -nonewline stdout $prompt
     flush stdout

     # Read that password!  :^)
     gets stdin password

     # Reset the terminal
     exec stty echo -echonl <@stdin

     return $password
}

#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc mysend { chan val } {
    #puts "Sending>>>$val<<<<"
    puts $chan $val
}

proc telnetResult { telnet } {
    global telnet_out
    #puts "Reading $telnet"

    if { [eof $telnet] || [catch { set dat [read $telnet]}] }  {
        #puts "GOT>>>AT END<<<"
        set telnet_out {AT END}
        if { [catch {close $telnet} res] }  {
            puts "Error: $res"
        }
    } else {
        #puts "GOT>>>$dat<<<<"
        append telnet_out $dat
    }
}

# Wait for p to showup in telnet_out
# return 1 if timout else returns 0
proc wait_for { p } {
    global telnet_out
    while { 1 } {
        vwait telnet_out
        if { [string last $p $telnet_out] > -1 } { return 0 }
        if { [string compare {timeout} $telnet_out] == 0 } { return 1 }
    }  
}


#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc get_fsp_info { fspip fsppassword} {
    global telnet_out
    set telnet_out {}

    # Open telnet session
    if {[catch {set telnet [open "|telnet $fspip" r+]} res]} {    
        puts "Could not telnet to $fspip"
        return {}
    }
    fconfigure $telnet -buffering none -blocking 0

    # all output from telnet session captured by telnetResult procedure
    # put into telnet_out variable
    fileevent $telnet readable [list telnetResult $telnet]

    # Set a timeout of 20 seconds
    set timeoutid [after 20000 {
        set telnet_out {timeout}
        close $telnet
    } ]

    if {[wait_for {login:}]} { return {} }

    mysend $telnet {root}
    if { [wait_for {Password:}]} { return {} }

    mysend $telnet "$fsppassword"
    while { 1 } {
        vwait telnet_out
        if { [string last {$} $telnet_out] > 0 } { break }
        if { [string last {Login incorrect} $telnet_out] > 0 } {
            puts {Login incorrect}
            close $telnet
            return {}
        }
        if { [string compare $telnet_out {timeout}] == 0 } { return {} }
    }
    set telnet_out {}
  
    mysend $telnet {registry -r fstp/DriverName}
    if { [wait_for {$}]} { return {} }

    regexp {registry -r fstp/DriverName.+fips[0-9]+/(.+)\n.+} $telnet_out a driver
    set telnet_out {}

    mysend $telnet {cat /proc/mounts | grep /nfs}
    if { [wait_for {$}]} { return {} }

    regexp {.+\n(.+?):(.+?) +/nfs nfs .+} $telnet_out a companion_ip nfs_dir

    mysend $telnet {exit}
    if { [wait_for {AT END}]} { return {} }

    # Cancel the timout
    after cancel $timeoutid

    return "$driver:$companion_ip:$nfs_dir"
}

proc check_bso { server } {
    global telnet_out
    set telnet_out {}

    #puts "Input server is $server"

    # Open telnet session
    if {[catch {set telnet [open "|telnet $server" r+]} res]} {
        puts "Could not telnet to $server"
        return {}
    }
    fconfigure $telnet -buffering none -blocking 0

    # all output from telnet session captured by telnetResult procedure
    # put into telnet_out variable
    fileevent $telnet readable [list telnetResult $telnet]

    # Set a timeout of 3 seconds
    set timeoutid [after 3000 {
        set telnet_out {timeout}
        close $telnet
    } ]

    while { 1 } {
        vwait telnet_out
        #puts "OUTPUT: $telnet_out"
        if { [string last {BSO} $telnet_out] > 0 } {
            puts "BSO Firewall Detected for $server, please authenticate first!"
            after cancel $timeoutid
            return 1;
        }
        if { [string compare $telnet_out {timeout}] == 0 } { break }
    }

    set telnet_out {}

    return 0
}

#---------------------------------------------------------
# TBD - No Support Yet 
#---------------------------------------------------------
proc start_patch_server_on_fsp { fspip fsppassword } {
    global telnet_out
    global telnet
    global fsp_server_port
    set telnet_out {}
    # Open telnet session
    if {[catch {set telnet [open "|telnet $fspip" r+]} res]} {
        puts "Could not telnet to $fspip"
        return 0
    }
    fconfigure $telnet -buffering none -blocking 0

    # all output from telnet session captured by telnetResult procedure
    # put into telnet_out variable
    fileevent $telnet readable [list telnetResult $telnet]

    # Set a timeout of 20 seconds
    set timeoutid [after 20000 {
        set telnet_out {timeout}
        close $telnet
    } ]

    if { [wait_for {login:}]} { return 0 }

    mysend $telnet {root}
    if { [wait_for {Password:}]} { return 0 }

    mysend $telnet "$fsppassword"
    while { 1 } {
        vwait telnet_out
        if { [string last {$} $telnet_out] > 0 } { break }
        if { [string last {Login incorrect} $telnet_out] > 0 } {
            puts {Login incorrect}
            close $telnet
            return 0
        }
        if { [string compare $telnet_out {timeout}] == 0 } { return 0 }
    }
    set telnet_out {}

    mysend $telnet {mkdir -p /nfs/data/engd}
    if { [wait_for {$}]} { return 0 }

    set telnet_out {}
    mysend $telnet {mkdir -p /nfs/data/rtbl}
    if { [wait_for {$}]} { return 0 }

    set telnet_out {}
    mysend $telnet {killall cini_patcher}
    if { [wait_for {$}]} { return 0 }

    set telnet_out {}
    mysend $telnet "cini_patcher &"
    if { [wait_for {Server ready}]} { return 0 }

    puts $telnet_out
    set telnet_out {}
    mysend $telnet {}
    if { [wait_for {$}]} { return 0 }
    set telnet_out {}

    mysend $telnet {exit}
    if { [wait_for {AT END}]} { return 0 }

    # Cancel the timout
    after cancel $timeoutid
    return 1
}

# ------------------------
# MAIN
# ------------------------
set userid $::env(USER)
set version "1.6"

set files [list]
set directories [list]
set cmds  [list]
set servers [list gfw160.aus.stglabs.ibm.com]

#-----------------------------------------------------------------------------------------
# Parse ARGs
#-----------------------------------------------------------------------------------------

set state flag
foreach arg $argv {
    switch -- $state {
        flag {
            switch -glob -- $arg {
                -quit { set cmds [list quit] }
                -D    { set state directory }
                -d    { set state driverflag }
                -f    { set state fipslevelflag }
# NOT SUPPORTED -s    { set state fspflag }
# NOT SUPPORTED -p    { set state portflag }
                -v    { set verbose 1 }
                -o    { set state outputflag }
                -n    { set newfiles 1 }
                -k    { set keepsandbox 1 }
                -O    { set noretrieve 1 }
                -*h* { puts {prcd_compile.tcl [--help] [-f <fipslevel> | -d <drivername>] [-o <ouput dir> | -O ] [-n] [ <filename> | -D <directory>] }
                       puts {}
                       puts {For existing files, this only supports *.{c,C,h,H,initfile,xml} files in the following hostboot directory trees: }
                       puts {    src/usr/hwpf/hwp }
                       puts {    src/include/usr/hwpf/hwp }
                       puts {}
                       puts {The files can either be in the local current working directory, or in some other directory. }
                       puts {}
                       puts {Without the -n parameter, the file MUST be an existing files in the hostboot sandbox.}
                       puts {If they are not found in the sandbox, an error will be returned.}
                       puts {}
                       puts {if -O is not specified, on success, image and pnor files will be placed in the output directory. }
                       puts {The -o parameter is optional. The default is the current working directory. }
                       puts {If instead the -O parameter is specified, no image or pnor files are returned. }
                       puts {}
                       puts {With the -n parameter, the files are assumed to be for a NEW HWP and will be checked to see}
                       puts {if they compile - no binary image files will be returned.}
                       puts {example }
                       puts {> prcd_compile.tcl -n mss_l3.C mss_l3.H}
                       puts {}
                       puts {With the -D parameter, all files in all sub-directories are built.}
                       puts {Without the -n, any files that do not exist in the hostboot sandbox are ignored.}
                       puts {example }
                       puts {> prcd_compile.tcl -D centaur/working/procedues/ -D p8/working/procedures}
                       puts {}
                       puts {The -d and -o parameters are optional.  Default for -d is the master level of code }
                       puts {and default for -o is the current working directory }
                       puts {}
                       puts {examples }
                       puts {> prcd_compile.tcl -d hb0216a_1307.810 -o ./output fapiTestHwp.C fapiTestHwp.C sample.initfile}
                       puts {> prcd_compile.tcl -d hb0216a_1307.810 -o ./output/ proc_cen_framelock.C }
                       puts {> prcd_compile.tcl -f b0211a_1307.810 -o output chips/p8/working/procedures/ipl/fapi/proc_cen_framelock.H }
                       puts {> prcd_compile.tcl -O chips/p8/working/procedures/ipl/fapi/proc_cen_framelock.* }
                       puts {}
                       puts "Version: $version"
                       puts {}
                       exit
                     }
                 *\.initfile     { lappend files $arg }
                 *\.C            { lappend files $arg }
                 *\.c            { lappend files $arg }
                 *\.H            { lappend files $arg }
                 *\.h            { lappend files $arg }
                 *\.xml          { lappend files $arg }
                default { puts "Unsupported File or Argument: $arg "
                          exit
                        }
            }
        }
        driverflag {
            set driver $arg
            set state flag
        }
        fipslevelflag {
            set fipslevel $arg
            set state flag
        }
        directory {
            lappend directories $arg
            set directory 1
            set state flag
        }
        fspflag {
            foreach {fspip fsp_port} [split $arg :] break
            set state flag
        }
        portflag {
            # Set the port the fsp patch server is listening on.
            # This is not the telnet port used in simics.
            # defaults to 7779
            set fsp_server_port $arg
            set state flag
        }
        outputflag {
            set output_dir $arg
            set state flag
        } 
    }
}

if {![info exists fsp_server_port]} { set fsp_server_port 7779 }

#-----------------------------------------------------------------------------------------
# Get fspip if not specified
#-----------------------------------------------------------------------------------------
# TBD - NOT SUPPORTED
if { ![info exists fspip] && ![info exists driver] } {
#    puts -nonewline {Enter telnet address of fsp: }
#    flush stdout
#    fconfigure stdin -blocking 1
#    foreach {fspip fsp_port} [split [gets stdin] { :}] break
#    fconfigure stdin -blockin 0
#     puts { No driver name input! }
#     exit
}

if { [info exists fspip] } {
    set fsppassword [getPassword "root password for fsp $fspip:"]
    set res [get_fsp_info "$fspip $fsp_port" $fsppassword]
    if { $res != "" } { foreach {driver companion_ip nfs_dir} [split $res {:}] break }

    if { [info exists driver]} {
        puts "FSP Driver: $driver"
    } else {
        puts {FSP login failed!}
        exit -1
    }

    if { $companion_ip != {} } {
        puts "Companion: $companion_ip"
    } else { unset companion_ip }


    if { $nfs_dir != {} } {
        puts "nfs_dir: $nfs_dir"
    }
}


if { ![info exists output_dir] } {
    # default to PWD for output
    set output_dir "./"
}

if { ![info exists noretrieve] } {
    # Make the output directory
    eval {exec} "mkdir -p $output_dir/pnor"
}

lappend cmds ":INFO userid $userid version $version"

if {[info exists keepsandbox]}  {
    lappend cmds ":INFO keepsandbox"
}

if { ![info exists driver] } {
    set driver "default"
}

if { ![info exists fipslevel] } {
    set fipslevel "default"
}

lappend cmds ":DRIVER $fipslevel $driver"

if {[info exists newfiles]}  {
  set hwp_file_cmd ":HWP_FILE_NEW"
} else {
  set hwp_file_cmd ":HWP_FILE"
}

if {[info exists directory]}  {
  # all valid files in directories
  lappend cmds ":HWP_FULL_DIRECTORY"

  ##########################################################
  # Generate command to send each input file
  ##########################################################
  foreach dirn $directories {
    set filelist [ exec find $dirn \( -name CVS -prune \) , -type f -name "*\.xml" -o -name "*\.initfile" -o -iname "*\.C" -o -iname "*\.H" ] 
    foreach filen $filelist {
       set file_size [file size $filen]
       set filesource($filen) $filen
       lappend cmds "$hwp_file_cmd $filen $file_size"
    }
  }

} else {

  ##########################################################
  # Generate command to send each input file
  ##########################################################
  foreach filen $files {
       if {![file exists $filen]} {
                puts "File not found: $filen "
                exit
       }
       set file_size [file size $filen]
       set filesource($filen) $filen
       lappend cmds "$hwp_file_cmd $filen $file_size"
  }
}

if {[info exists newfiles]}  {
  ##########################################################
  # Generate compile and complete directives
  ##########################################################
  lappend cmds ":HWP_COMPILE_NEW"
  lappend cmds ":HWP_DONE"
} else {

  ##########################################################
  # Generate compile, retrieve, and complete directives
  ##########################################################
  lappend cmds ":HWP_COMPILE"
  if { ![info exists noretrieve] } {
    lappend cmds ":HWP_RETRIEVE"
  }
  lappend cmds ":HWP_DONE"
}

set xfer_file_list {}

if {[llength $cmds] > 0 } {
    set result ""
    ##########################################################
    # Find a server to run on
    ##########################################################
    foreach server $servers {
        set result ""
        puts "Trying $server ..."

        # Check for BSO firewall
        if {[check_bso $server]} {
            exit -1
        }       

        if {[catch {set sockid [socket $server 7779] } res ] } {
            set result "    $res"
            puts $result
            continue
        } else { break }
    }
    ##########################################################
    # Now send all of the commands we generated sequentially
    # to the server, waiting for a :DONE between each one.
    ##########################################################
    if {$result == ""} {   
        puts "Connected to $server - Starting"
        foreach cmd $cmds {
            if {[info exists verbose]}  {puts "Send to hw procedure compiler:  $cmd"}
            # display some messages so that the user doesn't get concerned..
            if {[string first ":DRIVER" $cmd ] != -1} {
                puts "Sending command: start extract"
            } elseif {[string first ":HWP_COMPILE" $cmd ] != -1} {
                puts "Sending command: start build"
            } elseif {[string first ":HWP_RETRIEVE" $cmd ] != -1} {
                puts "Sending command: start retrieve"
            }

            if {[string compare $cmd {quit}] == 0 } {
                puts $sockid {quit}
                break
            } elseif {[regexp {^:HWP_FILE*} $cmd a ]} {
                regexp {^(.+) +(.+) +(.+)} $cmd a hwpcmd filename filesize
                set basename [file tail $filename]
                set newcmd "$hwpcmd $basename $filesize"
                puts $sockid $newcmd
                set hwpfile [open $filesource($filename) r]
                fconfigure $sockid -translation binary
                fconfigure $hwpfile -translation binary
                fcopy $hwpfile $sockid -size $filesize
                close $hwpfile
                fconfigure $sockid -translation auto
            } else {
                puts $sockid $cmd
            }
            flush $sockid
            set line ""
            while {[string compare $line {:DONE}] != 0} {
                if {[eof $sockid]} { break }
                gets $sockid line
                if {[info exists verbose]}  {puts "Received from hw procedure compiler:  $line"}
                if {[regexp {^:OBJ_FILE +(.+) +(.+)\n*} $line a b c] } {
                    fconfigure $sockid -translation binary
                    lappend xfer_file_list $b
                    set fp [open "$output_dir/$b" w]
                    fconfigure $fp -translation binary
                    fcopy $sockid $fp -size $c
                    close $fp
                    fconfigure $sockid -translation auto
                } elseif {[regexp {^:PNOR_FILE +(.+) +(.+)\n*} $line a b c] } {
                    fconfigure $sockid -translation binary
                    lappend xfer_file_list $b
                    set fp [open "$output_dir/pnor/$b" w]
                    fconfigure $fp -translation binary
                    fcopy $sockid $fp -size $c
                    close $fp
                    fconfigure $sockid -translation auto
                } elseif {[regexp {.*INFO: .*} $line ->] } {
                    puts "$line"
                } elseif {[regexp {.*ERROR:.*} $line ->] } {
                    puts stderr "Error in server script - $line"
                    set error 1
                } elseif {[regexp {.*error:.*} $line ->] } {
                    puts stderr "Error in compile - $line"
                    set error 1
                }
            }
            if {[eof $sockid]} { break }
        }
        close $sockid
        if {[info exists error]}  {
               puts "Compile Failed!  See above errors"
               exit -1
           } else {
               puts "Compile Complete"
           }
    } else {
        #  The server must be down
        puts stderr "All The servers seems to be down"
        exit -1
    }
}


# telnet back to fsp and start patch server
# TBD - Not implemented in this sprint
if {[info exists companion_ip]} {
    if {$companion_ip != {}} {
        set res [start_patch_server_on_fsp "$fspip $fsp_port" $fsppassword]
        if { $res } {
            #puts "fspip $fspip"
            if {[catch { set sockid [socket $fspip $fsp_server_port] } res ] } {
                puts $res
                exit -1
            }
            # call fspipResult when sockid becomes readable
            fileevent $sockid readable [list fspipResult $sockid]
            #fconfigure $sockid -buffering line

            # send files
            foreach f $xfer_file_list {
                #puts "file: $f"
                if {[string match {*.if} $f] || [string match {*.dat} $f] } {
                    set dest_dir {/nfs/data/engd}
                } else {
                    set dest_dir {/nfs/data/rtbl}
                }
                set filesize [file size $f]
                puts $sockid ":PUT $dest_dir/[file tail $f] $filesize"
                puts ":FSPPUT $fspip:$dest_dir/[file tail $f] $filesize"
                set hwpfile [open $f r]
                fconfigure $sockid -translation binary
                fconfigure $hwpfile -translation binary
                #puts "fcopy $hwpfile $sockid -size $filesize"
                fcopy $hwpfile $sockid -size $filesize
                close $hwpfile
                fconfigure $sockid -translation auto
            }
            close $sockid
        }
    }
}

# should only see data comming back if there were errors.
proc fspipResult { sockid } {
    gets $sockid line
    puts $line
}
