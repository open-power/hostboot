# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/tod_init/makefile $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2013,2014
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
ROOTPATH = ../../../../..

MODULE = tod_init

##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

##  NOTE: add the base istep dir here.
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/@istepname
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##@ EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/???
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_setup
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_save_config
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_utils
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_init


##  NOTE: add new object files when you add a new HWP
OBJS += tod_init.o
OBJS += TodControls.o
OBJS += TodDrawer.o
OBJS += TodProc.o
OBJS += TodSvc.o
OBJS += TodSvcUtil.o
OBJS += TodHwpIntf.o
OBJS += TodTopologyManager.o
OBJS += proc_tod_setup.o
OBJS += proc_tod_save_config.o
OBJS += proc_tod_init.o
OBJS += proc_tod_utils.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##@ VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/???
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_setup
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_save_config
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_utils
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/tod_init/proc_tod_init

include ${ROOTPATH}/config.mk
