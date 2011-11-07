#  IBM_PROLOG_BEGIN_TAG
#  This is an automatically generated prolog.
#
#  $Source: src/build/simics/hb-simdebug.py $
#
#  IBM CONFIDENTIAL
#
#  COPYRIGHT International Business Machines Corp. 2011
#
#  p1
#
#  Object Code Only (OCO) source materials
#  Licensed Internal Code Source Materials
#  IBM HostBoot Licensed Internal Code
#
#  The source code for this program is not published or other-
#  wise divested of its trade secrets, irrespective of what has
#  been deposited with the U.S. Copyright Office.
#
#  Origin: 30
#
#  IBM_PROLOG_END

import os,sys
import conf
import configuration
import cli
import binascii
import datetime
import commands     ## getoutput, getstatusoutput

#------------------------------------------------------------------------------
# Function to dump L3
#------------------------------------------------------------------------------
def dumpL3():

    # "constants"
    L3_SIZE = 0x800000;

    print

    # Get a timestamp on when dump was collected
    t = datetime.datetime.now().strftime("%Y%m%d%H%M%S")
    #print t

    #dump L3 to hbdump.<timestamp>
    string = "memory_image_ln0.save hbdump.%s 0 0x%x"%(t, L3_SIZE)
    #print string
    result = run_command(string)
    #print result

    print "HostBoot dump saved to %s/hbdump.%s."%(os.getcwd(),t)

    return


#------------------------------------------------------------------------------
# Functions to run isteps
#------------------------------------------------------------------------------
def print_istep_list( inList ):

    zinList  =   [  "i0_sub0             0   CG  F   IStep0 substep0",   \
                   "i0_sub1             0   CG  F   IStep1 substep1",   \
                   "i1_sub0             1   CG  F   IStep1  substep1",  \
                   "i55sub55            55  CG  F   bogus istep",       \
                   ]
    print
    print   "istep commands:."
    print   "   istepmode - set IStep Mode flag in SCOM reg"
    print
    print   "-----------------------------------------------------------"
    print   " StepName                  Num   Who  Mode  Description    "
    print   "-----------------------------------------------------------"    
    for line in zinList:
        print line.strip()
    print 
    print   " Key:"  
    print   " Who ----  " 
    print   "    C = Cronus" 
    print   "    G = GFW"  
    print   " Mode ---- " 
    print   "    F = Fast Mode" 
    print   "    S = Slow Mode (Fast Mode + more)" 
    print   "    M = Manufacturing Mode"    
    return
 
#   normally this would be a loop to watch for the runningbit.  
#   currently simics dumps all sorts of error lines every time a SCOM is
#   read, so HostBoot only updates every 1 sec.  at that rate we only 
#   need to sleep for 2 sec and we are sure to get it.  
#   redo later after simics is fixed ...
def getStatusReg(): 
    ##StatusStr   = "salerno_chip.regdump SCOM 0x13012685"  
    ##  -f <file> dumps the output to <file>_SCOM_0X13012685
    StatusStr   = "salerno_chip.regdump SCOM 0x13012685 -f ./scom.out"   

    ##  get response
    (result, statusOutput)  =   quiet_run_command( StatusStr, output_modes.regular )
    ##  HACK:  quiet_run_command() only returns the first line of a 4-line
    ##  output, pipe all lines to a file and then read it back.
    file    =   open( "./scom.out_SCOM_0X13012685", "rU" )
    statusOutput    =   file.readlines()
    file.close()
    
    #print result  
    #print   "............" 
    #print statusOutput[0]
    #print statusOutput[1]
    #print statusOutput[2]
    #print   "..........."
        
    (j1, j2, j3, j4, hiword, loword) = statusOutput[2].split()
    return (hiword, loword)


     
#   normally this would be a loop to watch for the runningbit.  
#   currently simics dumps all sorts of error lines every time a SCOM is
#   read, so HostBoot only updates every 1 sec.  at that rate we only 
#   need to sleep for 2 sec and we are sure to get it.  
#   redo later after simics is fixed ...
def runIStep( istep, substep, inList ):
    print   "------------------------------------------------------------------"    
    print   "run  %s :"%( inList[istep][substep] )
    print   "   istep # = 0x%x / substep # = 0x%x :"%(istep, substep)
    
    CommandStr  = "salerno_chip.regwrite SCOM 0x13012684 \"0x80000000_%4.4x%4.4x\" 64"%(istep,substep)

    #result  =   run_command( "run" )
    
    ##  send command to Hostboot
    # print CommandStr
    (result, out) = quiet_run_command(CommandStr, output_modes.regular )
    #print result
    
    time.sleep(2) 
    
    # result  =   run_command( "stop" )
    
    (hiword, loword) =   getStatusReg()
    print hiword + " " + loword
    runningbit  =   ( ( int(hiword,16) & 0x80000000 ) >> 31 )
    readybit    =   ( ( int(hiword,16) & 0x40000000 ) >> 30 ) 
    stsIStep    =   ( ( int(hiword,16) & 0x3fff0000 ) >> 16 )
    stsSubstep  =   ( ( int(hiword,16) & 0x0000ffff ) )
    taskStatus  =   ( ( int(loword,16) & 0xffff0000 ) >> 16 )
    istepStatus =   ( ( int(loword,16) & 0x0000ffff )  )   
    print 
    print   "%s : returned Status : "%( inList[istep][substep] )
    print "runningbit = 0x%x, readybit=0x%x"%(runningbit, readybit)
    print "Istep 0x%x / Substep 0x%x Status: 0x%x 0x%x"%( stsIStep, stsSubstep, taskStatus, istepStatus )
    print   "-----------------------------------------------------------------"    
    
##  run command = "sN"    
def sCommand( inList, scommand ) :
    i   =   int(scommand)
    j   =   0
    for substep in inList[i] :
        ## print   "-----------------" 
        ##print "run IStep %d %s  ..."%(i, substep)
        ##print   "-----------------" 
        runIStep( i, j, inList )
        j = j+1
    return    
    
def find_in_inList( inList, substepname) :
    for i in range(0,len(inList)) :
        for j in range( 0, len(inList[i])) :
            #print "%d %d"%(i,j)
            if ( inList[i][j] == substepname ) :
                #print "%s %d %d"%( inList[i][j], i, j )
                return (i,j, True )
                break;  
                  
    return ( len(inList), len(inList[i]), False )   
            
       
##  possible commands:
##      list
##      istepmode
##      sN
##      sN..M
##      <substepname1>..<substepname2>  
def istepHB( str_arg1, inList):
    IStepModeStr = "salerno_chip.regwrite SCOM 0x13012686 \"0x4057b007_4057b007\" 64"

    print   "run isteps...."
    
    if ( str_arg1 == "list"  ):         ## dump command list
        print_istep_list( inList)           
        return         
           
    if ( str_arg1 == "istepmode"  ):    ## set IStep Mode in SCOM reg
        print   "Set Istep Mode"
        (result, out)  =   quiet_run_command(IStepModeStr, output_modes.regular )
        # print result  
        return  
        
    ## check to see if we have an 's' command (string starts with 's')    
    if ( str_arg1.startswith('s') ):
        ## run "s" command
        scommand    =   str_arg1.lstrip('s')
        if scommand.isdigit():
            # command = "sN"
            sCommand( inList, scommand )
        else:
            print "multiple ISteps:" + scommand
            #   list of substeps = "sM..N"
            (M, N)  =   scommand.split('..')
            #print M + "-" + N 
            for x in range( (int(M,16)), (int(N,16)+1) ) :
                sCommand( inList, x )
        return
    else:  
        ## substep name .. substep name
        (ss_nameM, ss_nameN) = str_arg1.split("..")
        (istepM, substepM, foundit) = find_in_inList( inList, ss_nameM )
        if ( not foundit ) :
            print( "Invalid substep %s"%(ss_nameM) )
            return
            
        (istepN, substepN, foundit) = find_in_inList( inList, ss_nameN )
        if ( not foundit ) :
            print( "Invalid substep %s"%(ss_nameN) )
            return
 
        for x in range( istepM, istepN+1 ) :
                for y in range( substepM, substepN+1) :
                    runIStep( x, y, inList )
        return  


#------------------------------------------------------------------------------
# Function to dump error logs
#------------------------------------------------------------------------------
def errlHB(symsFile, errlParser, flag, logid, stringFile):

    # "constants"
    L3_SIZE = 0x800000
    dumpFile = "hbdump.out"

    print

    #dump L3
    string = "memory_image_ln0.save %s 0 0x%x"%(dumpFile,L3_SIZE)
    #print string
    result = run_command(string)
    #print result

    if logid == "all":
        string = "./%s %s %s %s -t %s| tee Errorlogs"%(errlParser,dumpFile,symsFile,flag,stringFile)
    else:
        string = "./%s %s %s %s %s -t %s| tee Errorlogs"%(errlParser,dumpFile,symsFile,flag,logid,stringFile)
    #print string
    os.system(string)
    os.system("rm hbdump.out")

    print "\n\nData saved to %s/Errorlogs"%(os.getcwd())

    return


#===============================================================================
#   HOSTBOOT Commands
#===============================================================================
default_syms  = "hbicore.syms"
default_stringFile = "hbotStringFile"

#------------------------------------------------
#------------------------------------------------
new_command("hb-trace",
    (lambda comp: run_hb_debug_framework("Trace", 
                                         ("components="+comp) if comp else "")),
    [arg(str_t, "comp", "?", None),
    ],
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb_printk"],
    see_also = [ ],
    short = "Display the hostboot trace",
    doc = """
Parameters: \n
        in = component name(s) \n

Defaults: \n
        'comp' = all buffers \n
        'syms' = './hbicore.syms' \n
        'stringFile' = './hbotStringFile' \n\n

Examples: \n
    hb-trace \n
    hb-trace ERRL\n
    hb-trace "ERRL,INITSERVICE" \n
    """)

#------------------------------------------------
#------------------------------------------------
new_command("hb-printk",
    lambda: run_hb_debug_framework("Printk"),
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb-trace"],
    see_also = [ ],
    short = "Display the kernel printk buffer",
    doc = """
Parameters: \n
 
Defaults: \n
        'syms' = './hbicore.syms' \n\n

Examples: \n
    hb-printk \n
    """)
    
#------------------------------------------------
#------------------------------------------------
def hb_dump():
    dumpL3()
    return None

new_command("hb-dump",
    hb_dump,
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb-trace"],
    see_also = [ ],
    short = "Dumps L3 to hbdump.<timestamp>",
    doc = """
Parameters: \n

Defaults: \n

Examples: \n
    hb-dump \n
    """)

#------------------------------------------------
#   implement isteps
#------------------------------------------------
def hb_istep(str_arg1):  

    ##  preprocess inputs, 
    ##  read in a file and translate to an inList
    ##  TODO read in default file
    #   TODO inPath  =   "istep_list.txt"
    #   TODO inFile = open( inPath, 'rU')
    #   TODO inList = inFile.readlines()
    #   TODO inFile.close()
    
    ## set up demo inlist
    inList  =   [   [ "i0_sub0", "i0_sub1" ],
                    [ "i1_sub0" ],
                ]  
                          
    ## print   flag_t                   
    
    if str_arg1 == None: 
        print_istep_list( inList )
    else:
        print "args=%s" % str(str_arg1)       
        istepHB( str_arg1, inList, )
                    
    return None
    
new_command("hb-istep",
    hb_istep,
    [ arg(str_t, "syms", "?", None),
      # arg(flag_t,"-s", "?", None),
    ],
    type = ["hostboot-commands"],
    see_also = [ ],
    short = "Run IStep commands using the SPLess HostBoot interface",
    doc = """
Parameters: \n
 
Defaults: \n

Examples: \n
    hb-istep \n
    hb-istep -s0 \n
    hb-istep -s0..4
    hb-istep poweron
    hb-istep poweron..clock_frequency_set
    """)    
    
#------------------------------------------------
#------------------------------------------------
default_flag = "-l"
default_logid = "all"
default_errlParser = "errlparser"
def hb_errl(logid, logidStr, flg_list, flg_detail):
    #print "logid=%s" % str(logid)
    #print "logidStr=%s" % str(logidStr)
    #print "flg_list=%s" % str(flg_list)
    #print "flg_detail=%s" % str(flg_detail)

    syms = default_syms
    errlParser = default_errlParser

    if flg_list and flg_detail:
        print "ERROR:  enter either '-l' or '-d [<logid | all>]'"
        return None

    flag = default_flag
    id = default_logid
    if flg_list:
        flag = "-l"
    if flg_detail:
        flag = "-d"
        if logid != None:
            id = str(logid)

    if (flag == "-l") and (logid or logidStr):
        print "ERROR:  enter either '-l' or '-d [<logid | all>]'"
        return None

    if logidStr and (logid or (logidStr.lower() != "all")):
        print "ERROR:  enter <logid> or 'all'"
        return None

    print "syms=%s" % str(syms)
    print "errlParser=%s" % str(errlParser)
    #print "logid=%s" % str(id)
    errlHB(syms, errlParser, flag, id, default_stringFile)
    return None

new_command("hb-errl",
    hb_errl,
    [ arg(int_t, "logid", "?", None),
     arg(str_t, "logidStr", "?", None),
     arg(flag_t, "-l"),
     arg(flag_t, "-d"),
    ],
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb_printk"],
    see_also = [ ],
    short = "Display the hostboot error logs",
    doc = """
Parameters: \n
        in = option for dumping error logs\n

Defaults: \n
        'flag' = '-l' \n
        'syms' = './hbicore.syms' \n
        'errlParser' = ./errlparser'\n

Examples: \n
    hb_errl [-l]\n
    hb-errl -d 1\n
    hb-errl -d [all]\n
    """)
    
    
#------------------------------------------------
#------------------------------------------------
def hb_singlethread():
    run_command("foreach $cpu in (system_cmp0.get-processor-list) {$cpu.disable}")
    run_command("cpu0_0_0_0.enable");
    return

new_command("hb-singlethread",
    hb_singlethread,
    [],
    alias = "hb-st",
    type = ["hostboot-commands"],
    short = "Disable all threads except cpu0_0_0_0.")
