/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_rdf_fields.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#pragma once
#include "scomt_regs.H"

#define SCOMT_MP_USE_CNTL_ELPR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class CNTL_ELPR_t : public ScomRegister<0x801182F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(CNTL_ELPR_t); \
            _SCOMT_BOOL_FIELD(CNTL_ELPR_t, FULL, 0); \
            _SCOMT_INT_FIELD(CNTL_ELPR_t, POINTER, 3, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_AACR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_AACR_t : public ScomRegister<0x8011829> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_AACR_t); \
            _SCOMT_BOOL_FIELD(SCOM_AACR_t, RRAYSEL, 0); \
            _SCOMT_INT_FIELD(SCOM_AACR_t, DDRESS, 1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_AACR_t, UTOINC, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_AADR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_AADR_t : public ScomRegister<0x801182A> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_AADR_t); \
            _SCOMT_INT_FIELD(SCOM_AADR_t, AADR_DATA, 0, 64); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_AAER \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_AAER_t : public ScomRegister<0x801182B> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_AAER_t); \
            _SCOMT_INT_FIELD(SCOM_AAER_t, AAER_DATA, 0, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_CERR0 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_CERR0_t : public ScomRegister<0x801180E> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_CERR0_t); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, MSR_PE, 12); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, EICR_PE, 13); \
            _SCOMT_INT_FIELD(SCOM_CERR0_t, HWMSX_PE, 16, 8); \
            _SCOMT_INT_FIELD(SCOM_CERR0_t, FWMSX_PE, 24, 8); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, RSPAR_PE, 32); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, AACR_PE, 41); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, DBGR_PE, 46); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, MASK0_PE, 48); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, MASK1_PE, 49); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, CGDR_PE, 50); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, MCBCM_PE, 52); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, MCBCM2_PE, 53); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, DQERRA0M0_PE, 54); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, DQERRA0M1_PE, 55); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, DQERRB0M0_PE, 56); \
            _SCOMT_BOOL_FIELD(SCOM_CERR0_t, DQERRB0M1_PE, 57); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_CERR1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_CERR1_t : public ScomRegister<0x801180F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_CERR1_t); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_CTL_AF_PERR, 0); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_CTL_TCHN_PERR, 1); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_CTL_CMPMODE_ERR, 2); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_PCX_PERR, 3); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_SYND_PERR, 4); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_2SYM_PERR, 5); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_CPLX_PERR, 6); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_EP2_PERR, 7); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, READ_ECC_DATAPATH_PARITY_ERROR, 8); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_CMX_PERR, 9); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_VP1_PERR, 10); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_VP2_PERR, 11); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_SYG_PERR, 12); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_EF1_PERR, 13); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_MK3_PERR, 14); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, ECC_PIPE_E1A_PERR, 15); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, UNEXPECTED_RDDATA_VALID, 16); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, MISSING_RDDATA_VALID, 17); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, SUE_01_DETECT, 18); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, SUE_10_DETECT, 19); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, RBUF_ECC_ERR_CE_DW0, 20); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, RBUF_ECC_ERR_UE_DW0, 21); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, RBUF_ECC_ERR_CE_DW1, 22); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, RBUF_ECC_ERR_UE_DW1, 23); \
            _SCOMT_INT_FIELD(SCOM_CERR1_t, RD_BUFF_ECC_ERR_SYNDROME, 24, 8); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, PBUF_ECC_ERR_CE_DW0, 32); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, PBUF_ECC_ERR_UE_DW0, 33); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, PBUF_ECC_ERR_CE_DW1, 34); \
            _SCOMT_BOOL_FIELD(SCOM_CERR1_t, PBUF_ECC_ERR_UE_DW1, 35); \
            _SCOMT_INT_FIELD(SCOM_CERR1_t, PRE_BUFF_ECC_ERR_SYNDROME, 36, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_CGDR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_CGDR_t : public ScomRegister<0x8011832> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_CGDR_t); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_PCTL, 0); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_RESP, 1); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_RMW, 2); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_LPTR, 3); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_AHASH, 4); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_STG, 5); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_OUT, 6); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_TLM, 7); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_BD, 8); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_DCMP, 9); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_RBCTL, 10); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_RBRMW, 11); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_RBTRC, 12); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_MPE, 13); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_CONF, 14); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_HWMS, 15); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, PSDIS_ZERO_SYND, 16); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, PSDIS_SAME_MARKS, 17); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, PSDIS_SAME_STEER, 18); \
            _SCOMT_BOOL_FIELD(SCOM_CGDR_t, CGDIS_SPARE, 19); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_DBGR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_DBGR_t : public ScomRegister<0x801182E> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_DBGR_t); \
            _SCOMT_INT_FIELD(SCOM_DBGR_t, PRIMARY_SELECT, 0, 4); \
            _SCOMT_INT_FIELD(SCOM_DBGR_t, SECONDARY_SELECT, 4, 4); \
            _SCOMT_BOOL_FIELD(SCOM_DBGR_t, EPX_CHIP, 8); \
            _SCOMT_BOOL_FIELD(SCOM_DBGR_t, EPX_SYMS, 9); \
            _SCOMT_BOOL_FIELD(SCOM_DBGR_t, TRACE_ALWAYS, 10); \
            _SCOMT_BOOL_FIELD(SCOM_DBGR_t, WAT_ENABLE, 11); \
            _SCOMT_BOOL_FIELD(SCOM_DBGR_t, WAT_ACTION_SELECT, 12); \
            _SCOMT_INT_FIELD(SCOM_DBGR_t, WAT_SOURCE, 13, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_DQERRA0M0 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_DQERRA0M0_t : public ScomRegister<0x8011836> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_DQERRA0M0_t); \
            _SCOMT_INT_FIELD(SCOM_DQERRA0M0_t, DQERRA0M0_MISCOMPARES, 0, 40); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_DQERRA0M1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_DQERRA0M1_t : public ScomRegister<0x8011837> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_DQERRA0M1_t); \
            _SCOMT_INT_FIELD(SCOM_DQERRA0M1_t, DQERRA0M1_MISCOMPARES, 0, 40); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_DQERRB0M0 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_DQERRB0M0_t : public ScomRegister<0x8011838> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_DQERRB0M0_t); \
            _SCOMT_INT_FIELD(SCOM_DQERRB0M0_t, DQERRB0M0_MISCOMPARES, 0, 40); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_DQERRB0M1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_DQERRB0M1_t : public ScomRegister<0x8011839> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_DQERRB0M1_t); \
            _SCOMT_INT_FIELD(SCOM_DQERRB0M1_t, DQERRB0M1_MISCOMPARES, 0, 40); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_EICR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_EICR_t : public ScomRegister<0x801180D> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_EICR_t); \
            _SCOMT_INT_FIELD(SCOM_EICR_t, ADDRESS, 0, 38); \
            _SCOMT_INT_FIELD(SCOM_EICR_t, PERSIST, 38, 2); \
            _SCOMT_INT_FIELD(SCOM_EICR_t, REGION, 40, 3); \
            _SCOMT_INT_FIELD(SCOM_EICR_t, TYPE, 43, 5); \
            _SCOMT_INT_FIELD(SCOM_EICR_t, MISC, 48, 6); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FIR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FIR_t : public ScomRegister<0x8011800> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FIR_t); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, INTERNAL_SCOM_ERROR, 0); \
            _SCOMT_INT_FIELD(SCOM_FIR_t, MAINLINE_MPE_RANK_0_TO_7, 1, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_NCE, 9); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_TCE, 10); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_SCE, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_MCE, 12); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_SUE, 13); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_AUE, 14); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_UE, 15); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_RCD, 16); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_IAUE, 17); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_IUE, 18); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_IRCD, 19); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINLINE_IMPE, 20); \
            _SCOMT_INT_FIELD(SCOM_FIR_t, MAINTENANCE_MPE_RANK_0_TO_7, 21, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_NCE, 29); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_TCE, 30); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_SCE, 31); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_MCE, 32); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_SUE, 33); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_AUE, 34); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_UE, 35); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_RCD, 36); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_IAUE, 37); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_IUE, 38); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_IRCD, 39); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, MAINTENANCE_IMPE, 40); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, RDDATA_VALID_ERROR, 41); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, SCOM_PARITY_CLASS_STATUS, 42); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, SCOM_PARITY_CLASS_RECOVERABLE, 43); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, SCOM_PARITY_CLASS_UNRECOVERABLE, 44); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_CORRECTOR_INTERNAL_PARITY_ERROR, 45); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_RBUF_CE_DW0, 46); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_RBUF_CE_DW1, 47); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_RBUF_UE_DW0, 48); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_RBUF_UE_DW1, 49); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_PBUF_CE_DW0, 50); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_PBUF_CE_DW1, 51); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_PBUF_UE_DW0, 52); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, ECC_PBUF_UE_DW1, 53); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, TLXT_RDF_RBUF_PERR, 54); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, TLXT_RDF_PBUF_PERR, 55); \
            _SCOMT_INT_FIELD(SCOM_FIR_t, RESERVED_56_60, 56, 5); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, SCOM_PARITY_DEBUG_WAT, 61); \
            _SCOMT_BOOL_FIELD(SCOM_FIR_t, RESERVED, 62); \
            _SCOMT_EXTRA_PUTSCOM(putScom_SET, 0x8011801); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FWMS0 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FWMS0_t : public ScomRegister<0x8011818> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FWMS0_t); \
            _SCOMT_INT_FIELD(SCOM_FWMS0_t, MARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS0_t, TYPE, 8); \
            _SCOMT_INT_FIELD(SCOM_FWMS0_t, REGION, 9, 3); \
            _SCOMT_INT_FIELD(SCOM_FWMS0_t, ADDRESS, 12, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS0_t, EXIT_1, 23); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS0_t, EXIT_2, 24); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FWMS1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FWMS1_t : public ScomRegister<0x8011819> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FWMS1_t); \
            _SCOMT_INT_FIELD(SCOM_FWMS1_t, MARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS1_t, TYPE, 8); \
            _SCOMT_INT_FIELD(SCOM_FWMS1_t, REGION, 9, 3); \
            _SCOMT_INT_FIELD(SCOM_FWMS1_t, ADDRESS, 12, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS1_t, EXIT_1, 23); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS1_t, EXIT_2, 24); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FWMS2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FWMS2_t : public ScomRegister<0x801181A> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FWMS2_t); \
            _SCOMT_INT_FIELD(SCOM_FWMS2_t, MARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS2_t, TYPE, 8); \
            _SCOMT_INT_FIELD(SCOM_FWMS2_t, REGION, 9, 3); \
            _SCOMT_INT_FIELD(SCOM_FWMS2_t, ADDRESS, 12, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS2_t, EXIT_1, 23); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS2_t, EXIT_2, 24); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FWMS3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FWMS3_t : public ScomRegister<0x801181B> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FWMS3_t); \
            _SCOMT_INT_FIELD(SCOM_FWMS3_t, MARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS3_t, TYPE, 8); \
            _SCOMT_INT_FIELD(SCOM_FWMS3_t, REGION, 9, 3); \
            _SCOMT_INT_FIELD(SCOM_FWMS3_t, ADDRESS, 12, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS3_t, EXIT_1, 23); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS3_t, EXIT_2, 24); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FWMS4 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FWMS4_t : public ScomRegister<0x801181C> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FWMS4_t); \
            _SCOMT_INT_FIELD(SCOM_FWMS4_t, MARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS4_t, TYPE, 8); \
            _SCOMT_INT_FIELD(SCOM_FWMS4_t, REGION, 9, 3); \
            _SCOMT_INT_FIELD(SCOM_FWMS4_t, ADDRESS, 12, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS4_t, EXIT_1, 23); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS4_t, EXIT_2, 24); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FWMS5 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FWMS5_t : public ScomRegister<0x801181D> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FWMS5_t); \
            _SCOMT_INT_FIELD(SCOM_FWMS5_t, MARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS5_t, TYPE, 8); \
            _SCOMT_INT_FIELD(SCOM_FWMS5_t, REGION, 9, 3); \
            _SCOMT_INT_FIELD(SCOM_FWMS5_t, ADDRESS, 12, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS5_t, EXIT_1, 23); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS5_t, EXIT_2, 24); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FWMS6 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FWMS6_t : public ScomRegister<0x801181E> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FWMS6_t); \
            _SCOMT_INT_FIELD(SCOM_FWMS6_t, MARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS6_t, TYPE, 8); \
            _SCOMT_INT_FIELD(SCOM_FWMS6_t, REGION, 9, 3); \
            _SCOMT_INT_FIELD(SCOM_FWMS6_t, ADDRESS, 12, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS6_t, EXIT_1, 23); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS6_t, EXIT_2, 24); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_FWMS7 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_FWMS7_t : public ScomRegister<0x801181F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_FWMS7_t); \
            _SCOMT_INT_FIELD(SCOM_FWMS7_t, MARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS7_t, TYPE, 8); \
            _SCOMT_INT_FIELD(SCOM_FWMS7_t, REGION, 9, 3); \
            _SCOMT_INT_FIELD(SCOM_FWMS7_t, ADDRESS, 12, 11); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS7_t, EXIT_1, 23); \
            _SCOMT_BOOL_FIELD(SCOM_FWMS7_t, EXIT_2, 24); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_HWMS0 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_HWMS0_t : public ScomRegister<0x8011810> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_HWMS0_t); \
            _SCOMT_INT_FIELD(SCOM_HWMS0_t, CHIPMARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS0_t, CONFIRMED, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS0_t, EXIT_1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS0_t, EXIT_2, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_HWMS1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_HWMS1_t : public ScomRegister<0x8011811> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_HWMS1_t); \
            _SCOMT_INT_FIELD(SCOM_HWMS1_t, CHIPMARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS1_t, CONFIRMED, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS1_t, EXIT_1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS1_t, EXIT_2, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_HWMS2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_HWMS2_t : public ScomRegister<0x8011812> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_HWMS2_t); \
            _SCOMT_INT_FIELD(SCOM_HWMS2_t, CHIPMARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS2_t, CONFIRMED, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS2_t, EXIT_1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS2_t, EXIT_2, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_HWMS3 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_HWMS3_t : public ScomRegister<0x8011813> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_HWMS3_t); \
            _SCOMT_INT_FIELD(SCOM_HWMS3_t, CHIPMARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS3_t, CONFIRMED, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS3_t, EXIT_1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS3_t, EXIT_2, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_HWMS4 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_HWMS4_t : public ScomRegister<0x8011814> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_HWMS4_t); \
            _SCOMT_INT_FIELD(SCOM_HWMS4_t, CHIPMARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS4_t, CONFIRMED, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS4_t, EXIT_1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS4_t, EXIT_2, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_HWMS5 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_HWMS5_t : public ScomRegister<0x8011815> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_HWMS5_t); \
            _SCOMT_INT_FIELD(SCOM_HWMS5_t, CHIPMARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS5_t, CONFIRMED, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS5_t, EXIT_1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS5_t, EXIT_2, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_HWMS6 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_HWMS6_t : public ScomRegister<0x8011816> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_HWMS6_t); \
            _SCOMT_INT_FIELD(SCOM_HWMS6_t, CHIPMARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS6_t, CONFIRMED, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS6_t, EXIT_1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS6_t, EXIT_2, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_HWMS7 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_HWMS7_t : public ScomRegister<0x8011817> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_HWMS7_t); \
            _SCOMT_INT_FIELD(SCOM_HWMS7_t, CHIPMARK, 0, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS7_t, CONFIRMED, 8); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS7_t, EXIT_1, 9); \
            _SCOMT_BOOL_FIELD(SCOM_HWMS7_t, EXIT_2, 10); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_MASK0 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_MASK0_t : public ScomRegister<0x8011830> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_MASK0_t); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, MSR_PE, 12); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, EICR_PE, 13); \
            _SCOMT_INT_FIELD(SCOM_MASK0_t, HWMSX_PE, 16, 8); \
            _SCOMT_INT_FIELD(SCOM_MASK0_t, FWMSX_PE, 24, 8); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, RSPAR_PE, 32); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, AACR_PE, 41); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, DBGR_PE, 46); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, MASK0_PE, 48); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, MASK1_PE, 49); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, CGDR_PE, 50); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, MCBCM_PE, 52); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, MCBCM2_PE, 53); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, DQERRA0M0_PE, 54); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, DQERRA0M1_PE, 55); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, DQERRB0M0_PE, 56); \
            _SCOMT_BOOL_FIELD(SCOM_MASK0_t, DQERRB0M1_PE, 57); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_MASK1 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_MASK1_t : public ScomRegister<0x8011831> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_MASK1_t); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_CTL_AF_PERR, 0); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_CTL_TCHN_PERR, 1); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_CTL_CMPMODE_ERR, 2); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_PCX_PERR, 3); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_SYND_PERR, 4); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_2SYM_PERR, 5); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_CPLX_PERR, 6); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_EP2_PERR, 7); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, READ_ECC_DATAPATH_PARITY_ERROR, 8); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_CMX_PERR, 9); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_VP1_PERR, 10); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_VP2_PERR, 11); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_SYG_PERR, 12); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_EF1_PERR, 13); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_MK3_PERR, 14); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, ECC_PIPE_E1A_PERR, 15); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, UNEXPECTED_RDDATA_VALID, 16); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, MISSING_RDDATA_VALID, 17); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, SUE_01_DETECT, 18); \
            _SCOMT_BOOL_FIELD(SCOM_MASK1_t, SUE_10_DETECT, 19); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_MCBCM \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_MCBCM_t : public ScomRegister<0x8011834> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_MCBCM_t); \
            _SCOMT_INT_FIELD(SCOM_MCBCM_t, HALF_COMPARE_MASK, 0, 40); \
            _SCOMT_BOOL_FIELD(SCOM_MCBCM_t, MASK_COVERAGE_SELECTOR, 40); \
            _SCOMT_BOOL_FIELD(SCOM_MCBCM_t, TRAP_NONSTOP, 41); \
            _SCOMT_BOOL_FIELD(SCOM_MCBCM_t, TRAP_CE_ENABLE, 42); \
            _SCOMT_BOOL_FIELD(SCOM_MCBCM_t, TRAP_MPE_ENABLE, 43); \
            _SCOMT_BOOL_FIELD(SCOM_MCBCM_t, TRAP_UE_ENABLE, 44); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_MCBCM2 \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_MCBCM2_t : public ScomRegister<0x8011835> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_MCBCM2_t); \
            _SCOMT_INT_FIELD(SCOM_MCBCM2_t, MCBCM2_MCBIST_HALF_COMPARE_MASK, 0, 40); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_MSR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_MSR_t : public ScomRegister<0x801180C> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_MSR_t); \
            _SCOMT_INT_FIELD(SCOM_MSR_t, CHIPMARK, 8, 8); \
            _SCOMT_INT_FIELD(SCOM_MSR_t, RANK, 16, 3); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_RDFCFGLXSTOP \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_RDFCFGLXSTOP_t : public ScomRegister<0x8011807> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_RDFCFGLXSTOP_t); \
            _SCOMT_INT_FIELD(SCOM_RDFCFGLXSTOP_t, CFG_LXSTOP, 0, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_RDFCFGRECOV \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_RDFCFGRECOV_t : public ScomRegister<0x8011805> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_RDFCFGRECOV_t); \
            _SCOMT_INT_FIELD(SCOM_RDFCFGRECOV_t, CFG_RECOV, 0, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_RDFCFGSPATTN \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_RDFCFGSPATTN_t : public ScomRegister<0x8011806> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_RDFCFGSPATTN_t); \
            _SCOMT_INT_FIELD(SCOM_RDFCFGSPATTN_t, CFG_SPATTN, 0, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_RDFCFGXSTOP \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_RDFCFGXSTOP_t : public ScomRegister<0x8011804> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_RDFCFGXSTOP_t); \
            _SCOMT_INT_FIELD(SCOM_RDFCFGXSTOP_t, CFG_XSTOP, 0, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_RDFFIRMASK \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_RDFFIRMASK_t : public ScomRegister<0x8011802> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_RDFFIRMASK_t); \
            _SCOMT_INT_FIELD(SCOM_RDFFIRMASK_t, FIR_MASK, 0, 63); \
            _SCOMT_EXTRA_PUTSCOM(putScom_SET, 0x8011803); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_RDFFIRWOF \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_RDFFIRWOF_t : public ScomRegister<0x8011808> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_RDFFIRWOF_t); \
            _SCOMT_INT_FIELD(SCOM_RDFFIRWOF_t, RDFFIRWOF_FIR_WOF, 0, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_MP_USE_SCOM_RSPAR \
    _SCOMT_OPEN_NAMESPACE(mp) \
    class SCOM_RSPAR_t : public ScomRegister<0x8011820> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(SCOM_RSPAR_t); \
            _SCOMT_INT_FIELD(SCOM_RSPAR_t, 0_LEFT, 0, 5); \
            _SCOMT_INT_FIELD(SCOM_RSPAR_t, 0_RIGHT, 5, 5); \
            _SCOMT_INT_FIELD(SCOM_RSPAR_t, 1_LEFT, 10, 5); \
            _SCOMT_INT_FIELD(SCOM_RSPAR_t, 1_RIGHT, 15, 5); \
            _SCOMT_INT_FIELD(SCOM_RSPAR_t, 2_LEFT, 20, 5); \
            _SCOMT_INT_FIELD(SCOM_RSPAR_t, 2_RIGHT, 25, 5); \
            _SCOMT_INT_FIELD(SCOM_RSPAR_t, 3_LEFT, 30, 5); \
            _SCOMT_INT_FIELD(SCOM_RSPAR_t, 3_RIGHT, 35, 5); \
    }; _SCOMT_CLOSE_NAMESPACE
