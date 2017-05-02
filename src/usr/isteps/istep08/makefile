# IBM_PROLOG_BEGIN_TAG
# This is an automatically generated prolog.
#
# $Source: src/usr/isteps/istep08/makefile $
#
# OpenPOWER HostBoot Project
#
# Contributors Listed Below - COPYRIGHT 2015,2017
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
ROOTPATH = ../../../..
PROCEDURES_PATH    = ${ROOTPATH}/src/import/chips/p9/procedures
MODULE = istep08

EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/pm/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/perv/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/sbe/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/nest/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/io/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/initfiles/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/lib
EXTRAINCDIR += ${ROOTPATH}/src/import/hwpf/fapi2/include/
EXTRAINCDIR += ${ROOTPATH}/src/include/usr/fapi2/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/common/include/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/
EXTRAINCDIR += ${ROOTPATH}/src/import/chips/p9/utils/imageProcs/
EXTRAINCDIR += ${ROOTPATH}/src/usr/isteps/
EXTRAINCDIR += ${PROCEDURES_PATH}/hwp/pm/include/registers

OBJS += call_host_slave_sbe_config.o
OBJS += call_host_setup_sbe.o
OBJS += call_host_cbs_start.o
OBJS += call_proc_check_slave_sbe_seeprom_complete.o
OBJS += call_host_p9_fbc_eff_config.o
OBJS += call_host_p9_fbc_eff_config_links.o
OBJS += call_proc_attr_update.o
OBJS += call_proc_chiplet_fabric_scominit.o
OBJS += call_proc_xbus_scominit.o
OBJS += call_proc_xbus_enable_ridi.o
OBJS += call_host_attnlisten_proc.o

VPATH += ${PROCEDURES_PATH}/hwp/perv/ ${PROCEDURES_PATH}/hwp/nest/
VPATH += ${PROCEDURES_PATH}/hwp/io/ ${PROCEDURES_PATH}/hwp/initfiles/
VPATH += ${PROCEDURES_PATH}/hwp/sbe/
VPATH += ${PROCEDURES_PATH}/hwp/pm/
VPATH += ${PROCEDURES_PATH}/hwp/lib

include ${ROOTPATH}/procedure.rules.mk

# host_slave_sbe_config
include ${PROCEDURES_PATH}/hwp/perv/p9_setup_sbe_config.mk

# host_setup_sbe
include ${PROCEDURES_PATH}/hwp/perv/p9_set_fsi_gp_shadow.mk

# host_cbs_start
include ${PROCEDURES_PATH}/hwp/perv/p9_start_cbs.mk

# proc_check_slave_sbe_seeprom_complete : Check Slave SBE Complete
include ${PROCEDURES_PATH}/hwp/perv/p9_check_slave_sbe_seeprom_complete.mk
include ${PROCEDURES_PATH}/hwp/perv/p9_extract_sbe_rc.mk
include ${PROCEDURES_PATH}/hwp/sbe/p9_get_sbe_msg_register.mk
include ${PROCEDURES_PATH}/hwp/perv/p9_getecid.mk

# host_p9_fbc_eff_config
include ${PROCEDURES_PATH}/hwp/nest/p9_fbc_eff_config.mk

# host_p9_fbc_eff_config_links
include ${PROCEDURES_PATH}/hwp/nest/p9_fbc_eff_config_links.mk

# proc_attr_update: Proc ATTR Update
include ${PROCEDURES_PATH}/hwp/nest/p9_attr_update.mk

# proc_chiplet_fabric_scominit : Scom inits to all chiplet fabric (sans Quad)
include ${PROCEDURES_PATH}/hwp/nest/p9_chiplet_fabric_scominit.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_fbc_ioe_dl_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_fbc_no_hp_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_fbc_ioe_tl_scom.mk

# proc_xbus_scominit : Apply scom inits to Xbus
include ${PROCEDURES_PATH}/hwp/io/p9_io_xbus_scominit.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_xbus_g0_scom.mk
include ${PROCEDURES_PATH}/hwp/initfiles/p9_xbus_g1_scom.mk

# proc_xbus_enable_ridi : Apply RI/DI for xbus
include ${PROCEDURES_PATH}/hwp/perv/p9_xbus_enable_ridi.mk

include ${ROOTPATH}/config.mk
