# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: chips/p9/procedures/hwp/pm/p9_pm_reset.mk $
#
# IBM CONFIDENTIAL
#
# EKB Project
#
# COPYRIGHT 2015,2016
# [+] International Business Machines Corp.
#
#
# The source code for this program is not published or otherwise
# divested of its trade secrets, irrespective of what has been
# deposited with the U.S. Copyright Office.
#
# IBM_PROLOG_END_TAG

PROCEDURE=p9_pm_reset
libp9_pm_reset_DEPLIBS += p9_pm_utils p9_pm_firinit p9_pm_occ_control p9_cpu_special_wakeup p9_pm_stop_gpe_init p9_pm_occ_gpe_init p9_pm_corequad_init p9_pm_pba_init p9_pm_occ_sram_init p9_pm_ocb_init p9_pm_pss_init
$(call ADD_MODULE_SRCDIR,$(PROCEDURE),$(ROOTPATH)/chips/p9/procedures/hwp/lib)
$(call ADD_MODULE_SRCDIR,$(PROCEDURE),$(ROOTPATH)/chips/p9/common/pmlib/include/registers)
$(call BUILD_PROCEDURE)
