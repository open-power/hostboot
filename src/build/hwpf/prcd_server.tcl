# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/hwpf/prcd_server.tcl $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2011,2013
#
# p1
#
# Object Code Only (OCO) source materials
# Licensed Internal Code Source Materials
# IBM HostBoot Licensed Internal Code
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# Origin: 30
#
# IBM_PROLOG_END_TAG
# the next line restarts using tclsh\
exec tclsh "$0" "$@"


# Name: prcd_server.tcl - Compile a hardware procedure provided by a client.
#
# Based on if_server.tcl by Doug Gilbert


set version "1.4"

############################################################################
# Accept is called when a new client request comes in
# An event is forked that calls AquireData whenever the socket becomes 
# readable the main thread continues to run looking for more client requests
############################################################################
proc Accept { sock addr port} {
    global socklist
    global log

    puts "[clock format [clock seconds]]: Accept $sock from $addr port $port"
    puts $log "$port: [clock format [clock seconds]]: Accept $sock from $addr port $port"
    set socklist(addr,$sock) [list $addr $port]
    fconfigure $sock -buffering line
    fileevent $sock readable [list AquireData $sock]
}

############################################################################
# AquireData is called whenever there is data avaiable from a client.
# with line buffering on sock, this means when a line is 
# Processes commands and collect data from client
############################################################################
proc AquireData { sock } {
    global socklist
    global sandbox
    global forever
    global sb_dir
    global sbname
    global hwpfile
    global git_sh
    global backing
    global log
    global running
    global driver
    global keepsandbox
    global client_version
    global fulldirectory
    global fips_dir

    if { [eof $sock] || [catch {gets $sock line}] } {
        puts "ERROR: Client closed unexpectedly"
        puts $log "$sock: Client closed unexpectedly"
        CloseOut $sock
    } else {
        if { [string compare $line "quit"] == 0 } {
            close $socklist(main)
            puts $sock "hw procedure compiler server is terminating"
            puts $log "$sock: hw procedure compiler server is terminating"
            CloseOut $sock
            set forever 0
        } elseif {[regexp {:DRIVER +(.+) +(.+)} $line a b c] } {

            ################################################################
            # Make a unique sandbox backed to the driver specified
            # Do a workon to the sandbox.
            ################################################################
            set fipslevel $b
            set driver $c
            puts $log "$sock: Input: fipslevel \"$fipslevel\", driver \"$driver\""

            # if either is default, determine proper.
            if {[string compare $fipslevel "default"] == 0} {
                if {[string compare $driver "default"] == 0} {
                    set driver master
                 }
            } else {
                set lvl [ string trimleft $fipslevel 'abcdefghijklmnopqrstuvwxyz0123456789_' ]
                set lvl [ string trimleft $lvl '.' ]
                set fips_dir "/esw/fips$lvl/Builds/$fipslevel/"
                if {[string compare $driver "default"] == 0} {
                    # use the fips build to determine the hostboot driver
                    set fips_notes "$fips_dir/src/hbfw/releaseNotes.html"
                    if { [catch {set driver [ exec sed -n "s%<h1>Level: %%p" $fips_notes ] } ] } {
                        puts $sock "ERROR: bad FIPS level - can't find $fips_notes\n"
                        puts $log "$sock: bad FIPS level - can't find $fips_notes\n)"
                        flush $log
                        CloseOut $sock
                        return
                    } else {
                        set pos [ string last "</h1>" $driver ]
                        incr pos -1
                        set driver [ string range $driver 0 $pos ]
                    }
                }
            }
            puts $log "$sock: Using: fipslevel \"$fipslevel\", driver \"$driver\""

            ################################################################
            # create git repository
            ################################################################
            set sbname($sock) "sb[string range [clock seconds] 4 end]"

            puts $sock "$sbname($sock)"
            puts $log "$sock: $sbname($sock)"
            flush $log

            # Make sure sandbox dir exists
            if {[catch {file mkdir "$sb_dir/$sbname($sock)"} res ] } {
                puts $sock "ERROR: sandbox mkdir failed\n"
                puts $log "$sock: sandbox mkdir failed\n)"
                CloseOut $sock
            } else {
                set git_sh($sock) [open "|bash" r+]
                fconfigure $git_sh($sock) -buffering none
                fileevent $git_sh($sock) readable [list IfResult $git_sh($sock) $sock $sbname($sock)]

                ExtractSandbox $sock $git_sh($sock)
            }

        } elseif {[regexp {:HWP_FILE +(.+) +(.+)} $line a b c] } {

            ################################################################
            # Open the hw procedure file in the hw procedure directory
            ################################################################
            #puts $log "$sock: Input File $b $c"
            #flush $log

            if { ![info exists sbname($sock)] } {
                puts $sock "ERROR: No sandbox found"
                puts $log "$sock: No sandbox found"
                CloseOut $sock
                return
            }

            ################################################################
            # Find the path to the file in the git sandbox
            # We will only look in the hwpf/hwp directories (usr and include/usr)
            # which should be enough. ANY file in there can be replaced, though
            # the prcd_compile.tcl script inforces *.{c,C,h,H,initfile,xml} files only.
            ################################################################

            set src_path $sb_dir/$sbname($sock)/src/usr/hwpf/hwp
            set inc_path $sb_dir/$sbname($sock)/src/include/usr/hwpf/hwp
            if { $fulldirectory == 1 } {
              set filename [file tail $b]
            } else {
              set filename $b
            }
            # we can't just find -name $filename because that won't find path/filename. -wholename does
            #  that, but we need the $filename to not have any ./ prefix if the user included that.
            # additionally, find usually outputs the file(s) separated by a newline. if there
            #  is a filename that's not unique, we need to flag that as an erorr, so we use the
            #  -printf to force them all onto 1 line.
            set filen [ exec find $src_path $inc_path -type f -wholename */[ string trimleft $filename "./" ] -printf "%p\t" ] 
            # and then truncate the last \t. yeah, hackish..
            set filen [ string trimright $filen "\t" ]
            #puts $log "$sock: find found in hostboot sandbox: \"$filen\""
            # error if filen is not just 1 file
            set filesfound [regexp -all {[^\t]+} $filen ]
            if { $filesfound == 0 } {
              if { $fulldirectory == 1 } {
                # do nothing..
                puts $log "$sock: Ignoring Input File - $filename - file not found in hostboot sandbox"
                puts $sock "Ignoring Input File - $filename - file not found in hostboot sandbox"
                # read the file and just throw it away
                if {[catch {set devnull [open "/dev/null" w] } res ] } {
                    puts $sock "ERROR: Server can't open /dev/null"
                    puts $log "$sock: Server can't open /dev/null"
                    CloseOut $sock
                } else {
                    fconfigure $devnull -translation binary
                    fconfigure $sock -translation binary
                    fcopy $sock $devnull -size $c
                    close $devnull
                    fconfigure $sock -translation auto
                    puts $sock ":DONE"
                    puts $log "$sock: DONE"
                    flush $log
                }
                return
              } else {
                puts $sock "ERROR: Invalid Input File - $filename - file not found in hostboot sandbox"
                puts $log "$sock: Invalid Input File - $filename - file not found in hostboot  sandbox"
                CloseOut $sock
                return
              }
            }
            if { $filesfound > 1 } {
              if { $fulldirectory == 1 } {
                # do nothing..
                puts $log "$sock: Ignoring Input File - $filename - file not unique in hostboot sandbox"
                puts $sock "Ignoring Input File - $filename - file not unique in hostboot sandbox"
                # read the file and just throw it away
                if {[catch {set devnull [open "/dev/null" w] } res ] } {
                    puts $sock "ERROR: Server can't open /dev/null"
                    puts $log "$sock: Server can't open /dev/null"
                    CloseOut $sock
                } else {
                    fconfigure $devnull -translation binary
                    fconfigure $sock -translation binary
                    fcopy $sock $devnull -size $c
                    close $devnull
                    fconfigure $sock -translation auto
                    puts $sock ":DONE"
                    puts $log "$sock: DONE"
                    flush $log
                }
                return
              } else {
                puts $sock "ERROR: Invalid Input File - $filename - filename NOT unique in hostboot sandbox"
                puts $log "$sock: Invalid Input File - $filename - filename NOT unique in hostboot sandbox"
                CloseOut $sock
                return
              }
            }

            puts $sock "INFO: Input File - $filename - found in hostboot sandbox"
            puts $log "$sock: INFO: Input File - $filename - found in hostboot sandbox"
            # Open with create/overwrite option
            if {[catch {set hwpfile($sock) [open "$filen" w+] } res ] } {
                puts $sock "ERROR: Server can't open $filen"
                puts $log "$sock: Server can't open $filen"
                CloseOut $sock
            } else {
                fconfigure $hwpfile($sock) -translation binary
                fconfigure $sock -translation binary
                fcopy $sock $hwpfile($sock) -size $c
                close $hwpfile($sock)
                fconfigure $sock -translation auto
                puts $sock ":DONE"
                puts $log "$sock: DONE"
                flush $sock
            }
        } elseif {[string compare $line ":HWP_COMPILE"] == 0} {
            set git_sh($sock) [open "|bash" r+]
            fconfigure $git_sh($sock) -buffering none
            fileevent $git_sh($sock) readable [list IfResult $git_sh($sock) $sock $sbname($sock)]
            puts $git_sh($sock) "cd $sb_dir/$sbname($sock)"
            SendSandbox $sock $git_sh($sock)
            puts $sock ":DONE"
            puts $log "$sock: DONE"
            flush $sock
            flush $log
        } elseif {[regexp {:HWP_FILE_NEW +(.+) +(.+)} $line a b c] } {

            ################################################################
            # Open the hw procedure file in the hw procedure directory
            ################################################################
            #puts $log "$sock: Input New File $b $c"
            #flush $log

            if { ![info exists sbname($sock)] } {
                puts $sock "ERROR: No sandbox found"
                puts $log "$sock: No sandbox found"
                CloseOut $sock
                return
            }

            ################################################################
            # determine the path to the file in the git sandbox
            ################################################################
            set newdir $sb_dir/$sbname($sock)/src/usr/hwpf/hwp/mss_new
            set basename [file tail $b]
            set filen $newdir/$basename
            if {![file exists $newdir]} {
                #puts $log "$sock: mkdir \"$newdir\""; flush $log
                eval {exec} "mkdir -p $newdir"
            }

            puts $sock "INFO: Using File - $b"
            puts $log "$sock: INFO: Using File - $b"
            # Open with create/overwrite option
            if {[catch {set hwpfile($sock) [open "$filen" w+] } res ] } {
                puts $sock "ERROR: Server can't open $filen"
                puts $log "$sock: Server can't open $filen"
                CloseOut $sock
            } else {
                fconfigure $hwpfile($sock) -translation binary
                fconfigure $sock -translation binary
                fcopy $sock $hwpfile($sock) -size $c
                close $hwpfile($sock)
                fconfigure $sock -translation auto
                puts $sock ":DONE"
                puts $log "$sock: DONE"
                flush $sock
            }
        } elseif {[string compare $line ":HWP_COMPILE_NEW"] == 0} {
            set git_sh($sock) [open "|bash" r+]
            fconfigure $git_sh($sock) -buffering none
            fileevent $git_sh($sock) readable [list IfResult $git_sh($sock) $sock $sbname($sock)]
            puts $git_sh($sock) "cd $sb_dir/$sbname($sock)"

            ##################################################################
            # create the new tmp makefile
            ##################################################################
            set newdir $sb_dir/$sbname($sock)/src/usr/hwpf/hwp/mss_new
            set new_makefile $newdir/makefile
            #puts $log "$sock: creating makefile \"$new_makefile\"";flush $log
          
            set mkfile {}
            set mkfile [open "$new_makefile" w 0666]
            puts $mkfile "ROOTPATH = ../../../../.."
            puts $mkfile "MODULE = mss_volt"
            puts $mkfile "EXTRAINCDIR += \${ROOTPATH}/src/include/usr/ecmddatabuffer \${ROOTPATH}/src/include/usr/hwpf/fapi \\"
            puts $mkfile "\${ROOTPATH}/src/include/usr/hwpf/plat \${ROOTPATH}/src/include/usr/hwpf/hwp \\"
            puts $mkfile "\${ROOTPATH}/src/usr/hwpf/hwp/include ."
            puts $mkfile "SRCS_c = \$(wildcard *.c)"
            puts $mkfile "SRCS_C = \$(wildcard *.C)"
            puts $mkfile "OBJS = \$(SRCS_c:.c=.o) \$(SRCS_C:.C=.o)"
            puts $mkfile "include \${ROOTPATH}/config.mk"
            flush $mkfile
            close $mkfile

            SendSandboxNew $sock $git_sh($sock)
            puts $sock ":DONE"
            puts $log "$sock: DONE"
            flush $sock
            flush $log
        } elseif {[string compare $line ":HWP_RETRIEVE"] == 0} {
            if { [catch {SendObjFiles $sock "$sb_dir/$sbname($sock)/img"} res]} {
                puts $log "$sock: ERROR: SendObjFiles interrupted: $res\n"
                flush $log
            } else {
                puts $sock ":DONE"
                puts $log "$sock: DONE"
                flush $sock
            }
            if { [catch {SendPnorFiles $sock "$sb_dir/$sbname($sock)/prcd_fsp/obj/ppc/hbfw/img"} res]} {
                puts $log "$sock: ERROR: SendPnorFiles interrupted: $res\n"
                flush $log
            } else {
                puts $sock ":DONE"
                puts $log "$sock: DONE"
                flush $sock
            }
        } elseif {[string compare $line ":HWP_FULL_DIRECTORY"] == 0} {
            puts $log "$sock: HWP_FULL_DIRECTORY"
            puts $log "$sock: DONE"
            puts $sock ":DONE"
            flush $log
            flush $sock
            set fulldirectory 1
        } elseif {[string compare $line ":HWP_DONE"] == 0} {
            puts $sock ":DONE"
            puts $log "$sock: DONE"
            CloseOut $sock
            set line ""
        } elseif {[regexp {:INFO keepsandbox} $line a] } {
            puts $sock ":DONE"
            puts $log "$sock: $a"
            set keepsandbox 1
            flush $sock
            flush $log
        } elseif {[regexp {:INFO userid +(.+) version +(.+)} $line a b c ] } {
            puts $sock ":DONE"
            puts $log "$sock: $a"
            set client_version $c
            flush $sock
            flush $log
        } else {
            # Unrecognized command
            # if it's just blank line then skipt it - else report it
            if {[string length $line] > 0 } {
                puts "Unknown command:$line"
                puts $sock "Unknown command: $line"
                puts $log "$sock: Unknown command: $line"
            }
            if { [catch {puts $sock ":DONE"} res]} {
                puts $log "$sock: ERROR: puts failed: $res\n"
                flush $log
            } else {
                puts $log "$sock: DONE"
                flush $log
                flush $sock
            }
        }
    }
}

##################################################################
# Clean up and close the socket
##################################################################
proc CloseOut { sock } {
    global socklist
    global sandbox
    global sbname
    global sb_dir
    global git_sh
    global backing
    global log
    global keepsandbox

    if {![eof $sock]} { flush $sock }

    puts $log "$sock [clock format [clock seconds]]: Close $socklist(addr,$sock)- "
    flush $log
    close $sock
    puts "[clock format [clock seconds]]: Close $socklist(addr,$sock)- "
    unset socklist(addr,$sock)
    if {[info exists git_sh($sock)] } {
        if { $keepsandbox != 1 } {
            eval {exec} "rm -rf $sb_dir/$sbname($sock)"
        }
        unset git_sh($sock)
        #unset sandbox($sbname($sock))
    }

    if {[info exists sbname($sock)]} { unset sbname($sock) }
    if {[info exists backint($sock)]} { unset backing($sock) }
}

##################################################################
# Sets up the sandbox with the required code from git
##################################################################
proc ExtractSandbox { sock git_sh} {
    global sandbox
    global running
    global sbname
    global sb_dir
    global driver
    global log

    ############################################################
    # Create GIT repository and extract input driver
    # Open a separate pipe which does the extraction and 
    # compiling
    ############################################################
    puts $git_sh "cd $sb_dir/$sbname($sock)"
    puts $git_sh {git init}
    puts $git_sh {git remote add gerrit ssh://jenkins.localhost/hostboot}
    #puts $git_sh {git remote add gerrit ssh://hostboot.gerrit/hostboot}
    puts $git_sh {git fetch gerrit}
    puts $git_sh {git fetch gerrit --tags}

    if {[string compare $driver "master"] == 0} {
        puts $log "$sock: Using master branch"
        puts $git_sh "git checkout -b master gerrit/master"
    } else {
        puts $log "$sock: Using $driver branch"
        puts $git_sh "git checkout -b $sbname($sock) $driver"
    }
                
    ##################################################
    # tell the workon shell to terminate
    ##################################################
    puts $git_sh {echo :DONE}
    flush $git_sh

    ############################################################
    ## if the git_sh is not done by 60 sec, it probably crashed
    ## keep a list of running sandboxes
    ## hopefully processes timeout in the same order they were started
    ## Kick off an event that waits 60 sec then executes
    ############################################################
    lappend running $sbname($sock)
    set timoutid [after 60000 {
        set sandbox([lindex $running 0]) crashed
        lreplace $running 0 0
    } ]

    ############################################################
    ## This thread now waits until an event changes sandbox($sbname)
    ##   either the simulator exits or times out
    ############################################################
    vwait sandbox($sbname($sock))

    ############################################################
    # If the git_sh workon crashed then close the workon shell 
    # else cancel the timout event
    ############################################################
    if { [string compare $sandbox($sbname($sock)) "crashed"] == 0 } {
        if { [catch {close $git_sh} res]} {
            puts $sock "Failed: $res\n"
            puts $log "$sock: Failed: $res\n"
        }
        set sandbox($sbname($sock)) idle
    } else {
        after cancel $timoutid
    }
    flush $sock
    flush $log

    ## just a flag to indicate sandbox is being used
    set sandbox($sbname($sock)) running
    puts $sock ":DONE"
    puts $log "$sock: DONE"
    flush $sock
}

##################################################################
# Sets up the sandbox for the ifcompiler & sends commands
# sets up an event to collect the simulation results
# closes and deletes the sandbox
##################################################################
proc SendSandbox { sock git_sh} {
    global sandbox
    global running
    global sbname
    global log
    global fips_dir

    ##################################################################
    # Start Compile
    ##################################################################

    if {[string length $fips_dir ] > 0} {
        # need to overwrite bbuild
        puts $git_sh "echo $fips_dir > src/build/citest/etc/bbuild;"
    }

    puts $git_sh "source env.bash;\
                  make -j4;"

    # hack for now. need to point to 'current' version of hb, not built, since
    # older versions doesn't support the new fipssetup command.
    # when this is ready merge, i'll copy the corrected 'hb' into the hostboot
    # projects directory.
    puts $git_sh "rm -f hb;ln -s /gsa/ausgsa/home/h/o/hortonb/hb2/src/build/tools/hb;"

    puts $git_sh "export SANDBOXROOT=`pwd`; export SANDBOXNAME=prcd_fsp;\
                  echo \"./hb fipssetup && ./hb prime\" > hbdo; chmod +x hbdo;\
                  SHELL=./hbdo ./hb workon;"

    ##################################################################
    # tell the workon shell to terminate
    ##################################################################
    puts $git_sh {echo :DONE}
    flush $git_sh

    ##################################################################
    ## if the git_sh is not done by 600 sec, it probably crashed
    ## keep a list of running sandboxes
    ## hopefully processes timeout in the same order they were started
    ## Kick off an event that waits 360 sec then executes
    ##################################################################
    lappend running $sbname($sock)
    set timoutid [after 600000 {
       set sandbox([lindex $running 0]) crashed
       lreplace $running 0 0
    } ]

    ##################################################################
    ## This thread now waits until an event changes sandbox($sbname)
    ##   either the simulator exits or timesout
    ##################################################################
    vwait sandbox($sbname($sock))

    ##################################################################
    # If the git_sh workon crashed then close the workon shell else cancel the 
    # timout event
    ##################################################################
    if { [string compare $sandbox($sbname($sock)) "crashed"] == 0 } {
            if { [catch {close $git_sh} res]} {
                puts $sock "Fail: $res\n"
                puts $log "$sock: Fail: $res\n"
            }
        set sandbox($sbname($sock)) idle
    } else {
        after cancel $timoutid
    }

    flush $sock
    flush $log
}

##################################################################
# Sets up the sandbox for the ifcompiler & sends commands
# create a makefile to build the new HWP and build
# sets up an event to collect the simulation results
# closes and deletes the sandbox
##################################################################
proc SendSandboxNew { sock git_sh} {
    global sandbox
    global running
    global sbname
    global log

    ##################################################################
    # Start Compile
    ##################################################################
    set newdir src/usr/hwpf/hwp/mss_new
    puts $git_sh "source env.bash; make -j4; make -C $newdir"

    ##################################################################
    # tell the workon shell to terminate
    ##################################################################

    puts $git_sh {echo :DONE}
    flush $git_sh

    ##################################################################
    ## if the git_sh is not done by 600 sec, it probably crashed
    ## keep a list of running sandboxes
    ## hopefully processes timeout in the same order they were started
    ## Kick off an event that waits 600 sec then executes
    ##################################################################
    lappend running $sbname($sock)
    set timoutid [after 600000 {
       set sandbox([lindex $running 0]) crashed
       lreplace $running 0 0
    } ]

    ##################################################################
    ## This thread now waits until an event changes sandbox($sbname)
    ##   either the simulator exits or timesout
    ##################################################################
    vwait sandbox($sbname($sock))

    ##################################################################
    # If the git_sh workon crashed then close the workon shell else cancel the 
    # timout event
    ##################################################################
    if { [string compare $sandbox($sbname($sock)) "crashed"] == 0 } {
            if { [catch {close $git_sh} res]} {
                puts $sock "Fail: $res\n"
            puts $log "$sock: Fail: $res\n"
            }
        set sandbox($sbname($sock)) idle
    } else {
        after cancel $timoutid
    }

    flush $sock
    flush $log
}

##################################################################
# This is a list of regular expressions.  Any line sent to stdout during
# mk processing that matches one of these expressions will be sent to the 
# client.  Note: Everything from stderr gets returned
##################################################################

set explist [list  {^make.*Error.*} {ERROR:.*} {error:.*} {^IfScrub..E>.*} {^Parse Error.*} {^Error.*} ]

##################################################################
## This event catches the output of the sandbox when the pipe become readable
## and sends it back to the client.
## The git_sh pipe is closed when the full result has been processed
##################################################################
proc IfResult { git_sh sock sbname_sock } {
    global sandbox
    global explist
    global log

    if { [eof $git_sh] || [catch {gets $git_sh line}] } {
        puts $sock "compile unexpectedly terminated. sandbox $sbname_sock"
        puts $log "$sock: compile unexpectedly terminated. sandbox $sbname_sock"

        if { [catch {close $git_sh} res] } {
            puts $sock "error is $res\n"
            puts $log "$sock: error is $res\n"
        }
        set sandbox($sbname_sock) "idle"
    } else {

        # Uncomment to send back all compile output
        #puts $sock "$sock $line"
        #puts $log "$sock: $line"
        #flush $log

        if { [string compare $line ":DONE"] == 0 } {
            if { [catch {close $git_sh} res]} {
                #res has the stderr
                # Need to weed out the junk
                set rlines [split $res "\n"]
                foreach rline $rlines {
                    # weed out the errors from mk
                    foreach exp $explist {
                        if {[regexp $exp $rline a] } {
                            puts $sock "error: $rline"
                            puts $log "$sock: error: $rline"
                        }
                    }
                }
            }

            puts $sock "Exit Sandbox"
            puts $log "$sock: Exit Sandbox"
            flush $log
            set sandbox($sbname_sock) "idle"

        } else {
            foreach exp $explist {
               if {[regexp $exp $line a]} {
                   puts $sock "error: $line"
                   puts $log "$sock: error: $line"
               }
            }
        }
    }
    flush $log
}


##################################################################
# send the *.bin, *.sims and hbotStringFile files from the compile 
#  back to the client
##################################################################
proc SendObjFiles { sock obj_dir } {
    global log

    set img_files {}

    # Send the image files
    if {[catch {set img_files [glob -dir $obj_dir hbi*syms hbi*list hbi*modinfo *pnor *dat hbotStringFile errlparser isteplist.csv]} res]} {
        puts $sock "ERROR: Needed image files not found in $obj_dir"
        puts $log "$sock: Needed image files not found in $obj_dir"
    } else {
        SendFiles "OBJ_FILE" $sock $img_files
    }

    flush $sock
    flush $log
}

##################################################################
#  back to the client
##################################################################
proc SendPnorFiles { sock obj_dir } {
    global log
    global version
    global client_version

    set pnor_files {}

    # Send the image files
    if {[catch {set pnor_files [glob -dir $obj_dir hostboot.header.bin hostboot_extended.bin hostboot.stage.bin]} res]} {
        puts $sock "ERROR: Needed image files not found in $obj_dir"
        puts $log "$sock: Needed image files not found in $obj_dir"
    } else {
        if { $client_version < $version } {
            # client can't handle PNOR_FILE type, so just send the files
            #  back and they'll get put into the <outputdir>
            SendFiles "OBJ_FILE" $sock $pnor_files
        } else {
            # tell client to put these in <outputdir>/pnor
            SendFiles "PNOR_FILE" $sock $pnor_files
        }
    }

    flush $sock
    flush $log
}

##################################################################
# Send a file to the client
##################################################################
proc SendFiles { type sock files } {
    global log

    foreach f $files {
        set size [file size $f]
        puts $sock ":$type [file tail $f] $size"
        puts $log "$sock: :$type [file tail $f] $size"
        fconfigure $sock -translation binary
        set fp [open $f r]
        fconfigure $fp -translation binary
        fcopy $fp $sock -size $size
        close $fp
        fconfigure $sock -translation auto
    }
    flush $log
}

##################################################################
# main
##################################################################
set forever 1
#set base_dir "./"
set base_dir "/tmp"
set home_dir $::env(HOME)
set logfile "$home_dir/prcd_server.log"
set log {}
set keepsandbox 0
set client_version 0
set fulldirectory 0
set fips_dir ""

# Where are we running?
foreach {host site c d} [split [exec hostname] .]  break
if {[string compare $host {gfw160}] == 0} {
    set sb_dir "$base_dir/hwp/"
    eval {exec} "mkdir -p $sb_dir"
} else {
    puts "Invalid Location to run server!"
    exit -1
}

# array to keep track of ode sandboxes and thier state
array set sandbox {
    sb00000000 idle
}

array set backing {}

if { [file exists $logfile] } {
    set log [open "$logfile" a]
} else {
    set log [open "$logfile" w 0666]
}

puts "Logfile: $logfile $log"
exec chmod 666 $logfile

puts "[clock format [clock seconds]]: HWP compiler Server is starting"
puts $log "[clock format [clock seconds]]: HWP compiler Server is starting"
flush $log

set socklist(main) [socket -server Accept 7779]

# By catching errors from vwait- we can ignore them
catch {vwait forever}
