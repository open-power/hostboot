# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/build/simics/hb-simdebug.py $
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
import os,sys
import conf
import configuration
import cli
import binascii
import datetime
import commands     ## getoutput, getstatusoutput
import random

#===============================================================================
#   HOSTBOOT Commands
#===============================================================================
default_syms  = "hbicore.syms"
default_stringFile = "hbotStringFile"

#------------------------------------------------
#------------------------------------------------
new_command("hb-trace",
    (lambda comp: run_hb_debug_framework("Trace",
                                         ("components="+comp) if comp else "",
                                         outputFile = "hb-trace.output")),
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
    lambda: run_hb_debug_framework("Printk", outputFile = "hb-printk.output"),
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
new_command("hb-dump",
    lambda: run_hb_debug_framework("Dump", outputFile = "hb-dump.output"),
    #alias = "hbt",
    type = ["hostboot-commands"],
    #see_also = ["hb-trace"],
    see_also = [ ],
    short = "Dumps HB memory to hbdump.<timestamp>",
    doc = """
Parameters: \n

Defaults: \n

Examples: \n
    hb-dump \n
    """)


#------------------------------------------------
#   Disable for now, need to pass in lots of options
#------------------------------------------------
new_command("hb-istep",
            lambda istep:  run_hb_debug_framework("Istep", istep,
            outputFile = "hb-istep.output"),
            [ arg( str_t, "istep", "?", "") ],
            type = ["hostboot-commands"],
            see_also = [ ],
            short = "Run IStep commands",
            doc = """
Parameters: \n

Defaults: \n

Examples: \n
    hb-istep    \n
    hb-istep    list \n
    hb-istep    splessmode \n
    hb-istep    fspmode \n
    hb-istep    clear-trace \n
    hb-istep    resume \n
    hb-istep    s4 \n
    hb-istep    s4..N
    hb-istep    poweron \n
    hb-istep    poweron..clock_frequency_set /n
    """)

#------------------------------------------------
#------------------------------------------------
new_command("hb-errl",
    (lambda logid, logidStr, flg_l, flg_d:
        run_hb_debug_framework("Errl",
                ("display="+(("0x%x" % logid) if logid else logidStr) if flg_d else ""
                ),
                outputFile = "hb-errl.output")),
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

Examples: \n
    hb_errl [-l]\n
    hb-errl -d 1\n
    hb-errl -d [all]\n
    """)


#------------------------------------------------
#------------------------------------------------
def hb_singlethread():
    run_command("foreach $cpu in (system_cmp0.get-processor-list) " +
                "{ pdisable $cpu}");
    run_command("penable cpu0_0_05_0");
    run_command("pselect cpu0_0_05_0");
    return

new_command("hb-singlethread",
    hb_singlethread,
    [],
    alias = "hb-st",
    type = ["hostboot-commands"],
    short = "Disable all threads except cpu0_0_05_0.")



#------------------------------------------------
#------------------------------------------------
def hb_get_objects_by_class(classname):
    obj_list=[]
    obj_dict={}
    # Put objects into a dictionary, indexed by object name
    for obj in SIM_get_all_objects():
        if (obj.classname == classname):
            obj_dict[obj.name]=obj

    # Sort the dictionary by key (object name)
    obj_names=obj_dict.keys()
    obj_names.sort()
    for obj_name in obj_names:
        obj_list.append(obj_dict[obj_name])
        #print "object name=%s" % obj_name
    return obj_list

def hb_getallregs(regname):
    proc_list=[]
    proc_list=hb_get_objects_by_class("ppc-power8-mambo-core")
    for proc in proc_list:
        output = run_command("%s.read-reg %s"%(proc.name,regname))
        print ">> %s : " %(proc.name) + "%x" %output

new_command("hb-getallregs",
    (lambda reg: hb_getallregs(reg)),
    [ arg(str_t, "reg", "?", None),
    ],
    alias = "hb-gar",
    type = ["hostboot-commands"],
    short = "Read a reg from all cores.",
    doc = """
Examples: \n
    hb-getallregs <regname>\n
    hb-getallregs pc\n
    """)

