# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/hwpf/hwp/occ/occ.mk $
#
# IBM CONFIDENTIAL
#
# COPYRIGHT International Business Machines Corp. 2014
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
##      support for Targeting and fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/ecmddatabuffer
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/fapi
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/plat
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp

## pointer to common HWP files
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/include

## pointer to already consumed procedures.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/build_winkle_images/p8_set_pore_bar

##  NOTE: add the base istep dir here.
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/occ

##  Include sub dirs
##  NOTE: add a new EXTRAINCDIR when you add a new HWP
##  EXAMPLE:
##  EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/occ/<HWP_dir>
EXTRAINCDIR += ${ROOTPATH}/src/usr/hwpf/hwp/occ/occ_procedures
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/hwpf/hwp/utility_procedures

##  NOTE: add new object files when you add a new HWP
OBJS += p8_pba_init.o
OBJS += p8_pm_init.o
OBJS += p8_pcbs_init.o
OBJS += p8_pmc_init.o
OBJS += p8_poregpe_init.o
OBJS += p8_oha_init.o
OBJS += p8_ocb_init.o
OBJS += p8_pss_init.o
OBJS += p8_occ_control.o
OBJS += p8_occ_sram_init.o
OBJS += p8_pm_firinit.o
OBJS += p8_pm_oha_firinit.o
OBJS += p8_pm_pcbs_firinit.o
OBJS += p8_pm_occ_firinit.o
OBJS += p8_pm_pba_firinit.o
OBJS += p8_pm_pmc_firinit.o
OBJS += p8_pm_utils.o


#These procedures are included per Stradale's request so
#they can implement OCC Reset.
OBJS += p8_pm_prep_for_reset.o
OBJS += p8_pmc_force_vsafe.o
OBJS += p8_ocb_indir_access.o
OBJS += p8_ocb_indir_setup_linear.o

##  NOTE: add a new directory onto the vpaths when you add a new HWP
##  EXAMPLE:
#   VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/occ/<HWP_dir>
VPATH += ${ROOTPATH}/src/usr/hwpf/hwp/occ/occ_procedures


