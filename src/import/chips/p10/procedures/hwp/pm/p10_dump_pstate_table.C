/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_dump_pstate_table.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <stdio.h>
#include <stdint.h>
#include <string>
#include "p10_dump_pstate_table.H"
#include "p10_pstate_parameter_block.H"
#include "p10_pm_utils.H"
#include "p10_pm_hcd_flags.h"
#include "p10_hcd_common.H"
#include "p10_hcd_memmap_base.H"
#include <pstates_common.H>
#include <pstates_occ.H>
#include <pstates_pgpe.H>
#include <pstates_table.H>

/*
#define LCL_INF(_fmt_, _args_...) \
     FAPI_INF(_fmt_, ##_args_)
*/

#define LCL_INF(_fmt_, _args_...)  \
    printf(_fmt_, ##_args_);      \
    printf("\n")

#define LCL_DBG(_fmt_, _args_...)  \
    printf(_fmt_, ##_args_);      \
    printf("\n")

#define LCL_IMP(_fmt_, _args_...)  \
    printf(_fmt_, ##_args_);      \
    printf("\n")

//
//Local function protoytpes
//

void oppb_print(FILE* stream, const OCCPstateParmBlock_t* oppb);
void gpi_print(FILE* stream, void* gpi, uint32_t dump_flag);
void gppb_print(FILE* stream, const GlobalPstateParmBlock_v1_t* gppb, uint32_t dump_flag);
void pgpe_flags_print(FILE* stream, const GlobalPstateParmBlock_v1_t* gppb);
void vrm_print(FILE* stream, const GlobalPstateParmBlock_v1_t* gppb);
void resclk_print(FILE* stream,
                  const GlobalPstateParmBlock_v1_t* gppb,
                  const char* i_title);
void dds_print(FILE* stream, const GlobalPstateParmBlock_v1_t* gppb);
void wov_wof_print(FILE* stream, const GlobalPstateParmBlock_v1_t* gppb);
void iddq_print(const IddqTable_t* i_iddqt);

//
//p10_dump_pstate_table
//
void p10_dump_pstate_table(void* vgpi, uint32_t dump_flag)
{
    const GlobalPstateParmBlock_v1_t* gppb;

    GeneratedPstateInfo_v1_t* g = (GeneratedPstateInfo_v1_t*)vgpi;
    gppb = &g->globalppb;

    LCL_INF("Dump_Flag=0x%x\n", dump_flag);

    if (dump_flag & PSTATE_DUMP_BASIC)
    {
        //Global PState Parameters
        gppb_print(stdout, gppb, dump_flag);

        //Generated PState Info
        gpi_print(stdout, vgpi, dump_flag);
    }

    if (dump_flag & PSTATE_DUMP_PGPE_FLAGS)
    {
        //PGPE_Flags
        pgpe_flags_print(stdout, gppb);
    }

    if (dump_flag & PSTATE_DUMP_VRM)
    {
        //VRM parameter
        vrm_print(stdout, gppb);
    }

    if (dump_flag & PSTATE_DUMP_WOF_WOV)
    {
        //WOV_WOF
        wov_wof_print(stdout, gppb);
    }

    if (dump_flag & PSTATE_DUMP_RESCLK)
    {
        //Resonant Clock Parameters
        resclk_print(stdout, gppb, "Global Pstate Parmaeter Block");
    }

    if (dump_flag & PSTATE_DUMP_DDS)
    {
        //DDS
        dds_print(stdout, gppb);
    }

    return;
}


//
//p10_dump_pstate_parmblocks
//
void p10_dump_occ_ppb(OCCPstateParmBlock_t* i_oppb)
{
    const IddqTable_t* iddq = &i_oppb->iddq;

    oppb_print(stdout, i_oppb);
    iddq_print(iddq);

    return;
}



//
//gpi_print
//
void gpi_print(FILE* stream, void* vgpi, uint32_t dump_flag)
{
    uint32_t e;
    const PstateTable_t* tbl;
    //uint64_t GenPstateInfoMagic  = revle64(*(uint64_t*)vgpi);

    GeneratedPstateInfo_v1_t* g = (GeneratedPstateInfo_v1_t*)vgpi;

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "GENERATED PSTATE INFO START@ %p\n", vgpi);
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stdout, "Magic Number(gpi):           %s\n", (char*)((uint64_t*)vgpi));

    fprintf(stream, "PState 0 Frequency (kHz):    %u Khz\n", revle32(g->pstate0_frequency_khz));
    fprintf(stream, "Highest PState:              %u \n", revle32(g->highest_pstate));

    if (dump_flag & PSTATE_DUMP_FULL)
    {
        tbl = g->raw_pstates;
        fprintf(stream, "Raw Pstate Table\n");
        fprintf(stream, "\t%3s %3s   %9s %7s %7s\n", "Psd", "Psh", "Freq(Mhz)", "Ext(mV)",
                "Eff(mV)");

        for (e = 0; e < revle32(g->highest_pstate); e++)
        {
            fprintf(stream, "\t%3u 0x%2X %9u %7u %7u\n",
                    tbl[e].pstate,
                    tbl[e].pstate,
                    revle16(tbl[e].frequency_mhz),
                    revle16(tbl[e].external_vdd_mv),
                    revle16(tbl[e].effective_vdd_mv));
        }
    }

    tbl = g->biased_pstates;
    fprintf(stream, "Biased Pstate Table\n");
    fprintf(stream, "\t%3s %3s   %9s %7s %7s\n", "Psd", "Psh", "Freq(Mhz)", "Ext(mV)",
            "Eff(mV)");

    for (e = 0; e < revle32(g->highest_pstate); e++)
    {
        fprintf(stream, "\t%3u 0x%2X %9u %7u %7u\n",
                tbl[e].pstate,
                tbl[e].pstate,
                revle16(tbl[e].frequency_mhz),
                revle16(tbl[e].external_vdd_mv),
                revle16(tbl[e].effective_vdd_mv));
    }

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "GENERATED PSTATE INFO END@ %p\n", vgpi);
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\n");
}

//
// gppb_print
//
void gppb_print(FILE* stream, const GlobalPstateParmBlock_v1_t* gppb, uint32_t  dump_flag)
{
    uint32_t p, s, r;
    const char* vpdPvStr[NUM_OP_POINTS] = PV_OP_STR;
    const int   vpdPv[NUM_OP_POINTS] = PV_OP;
    const char* vpdOpSetStr[NUM_VPD_PTS_SET] = VPD_PT_SET_STR;
    const int   vpdOpSet[NUM_VPD_PTS_SET] = VPD_PT_SET;
    const char* vpdOpSlopesRegionStr[VPD_NUM_SLOPES_REGION] = VPD_OP_SLOPES_REGION_ORDER_STR;

    //Endian conversion
    uint32_t reference_frequency_khz = revle32(gppb->base.reference_frequency_khz);
    uint32_t frequency_step_khz = revle32(gppb->base.frequency_step_khz);
    uint32_t occ_freq_mhz = revle32(gppb->base.occ_complex_frequency_mhz);
    uint32_t safe_voltage_mv[SAFE_VOLTAGE_SIZE];

    for (s = 0 ; s < SAFE_VOLTAGE_SIZE; s++)
    {
        safe_voltage_mv[s] = revle32(gppb->base.safe_voltage_mv[s]);
    }

    uint32_t safe_frequency_khz = revle32(gppb->base.safe_frequency_khz);

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "GLOBAL PSTATE PARAMETERS START@ %p\n", gppb);
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "sizeof(GlobalPstateParmBlock_v1_t):   %lu\n", sizeof(GlobalPstateParmBlock_v1_t));
    fprintf(stream, "Magic_Number:                      %s\n", (char*)&gppb->magic);
    fprintf(stream, "Reference_Frequency:               %u Khz\n", reference_frequency_khz);
    fprintf(stream, "Frequency_Step_Size:               %u Khz\n", frequency_step_khz);
    fprintf(stream, "OCC Complex_Frequency:             %u Mhz\n", occ_freq_mhz);


    for (s = 0 ; s < SAFE_VOLTAGE_SIZE; s++)
    {
        fprintf(stream, "Safe_Voltage[%u]                    %u mV\n", s, safe_voltage_mv[s]);
    }

    fprintf(stream, "Safe_Frequency                     %u Khz\n", safe_frequency_khz);

    for (s = 0 ; s < NUM_VPD_PTS_SET; s++)
    {
        fprintf(stream, "\nVPD_Operating_Points(%s)\n", vpdOpSetStr[s]);
        fprintf(stream, "\t%-10s %-8s %-9s %-7s %-7s %-8s %-15s %-15s %-15s %-15s %-15s %-15s %-15s %-15s\n",
                "Point", "Pstate", "Freq(Mhz)", "Vdd(mV)",
                "Vcs(mV)", "Vmin(mV)",
                "iddAcTDP(10mA)", "iddDcTDP(10mA)", "iddAcRDP(10mA)", "iddDcRDP(10mA)",
                "icsAcTDP(10mA)", "icsDcTDP(10mA)", "icsAcRDP(10mA)", "icsDcRDP(10mA)");

        for (p = 0; p < NUM_PV_POINTS; p++)
        {
            fprintf(stream, "\t%-10s %-8d %-9d %-7d %-7d %-8d %-15d %-15d %-15d %-15d %-15d %-15d %-15d %-15d\n",
                    vpdPvStr[p],
                    gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].pstate,
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].frequency_mhz),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].vdd_mv),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].vcs_mv),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].vdd_vmin),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].idd_tdp_ac_10ma),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].idd_tdp_dc_10ma),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].idd_rdp_ac_10ma),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].idd_rdp_dc_10ma),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].ics_tdp_ac_10ma),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].ics_tdp_dc_10ma),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].ics_rdp_ac_10ma),
                    revle32(gppb->operating_points_set[vpdOpSet[s]][vpdPv[p]].ics_rdp_dc_10ma)
                   );
        }
    }

    fprintf(stream, "\nSystem_Power_Distribution_Parameters\n");
    fprintf(stream, "\t      LoadLine(uOhm) DistLoss(uOhm)  DistOffset(uV)\n");
    fprintf(stream, "\tVDD        %5u        %5u        %5u\n",
            revle32(gppb->vdd_sysparm.loadline_uohm),
            revle32(gppb->vdd_sysparm.distloss_uohm),
            revle32(gppb->vdd_sysparm.distoffset_uv));
    fprintf(stream, "\tVCS        %5u        %5u        %5u\n",
            revle32(gppb->vcs_sysparm.loadline_uohm),
            revle32(gppb->vcs_sysparm.distloss_uohm),
            revle32(gppb->vcs_sysparm.distoffset_uv));
    fprintf(stream, "\tVDN        %5u        %5u        %5u\n",
            revle32(gppb->vdn_sysparm.loadline_uohm),
            revle32(gppb->vdn_sysparm.distloss_uohm),
            revle32(gppb->vdn_sysparm.distoffset_uv));

    fprintf(stream, "\nExternal_Biases\n");
    fprintf(stream, "\tFrequency Bias: %6.1f%%\n", (double)gppb->poundv_biases_0p05pct.frequency_0p5pct);
    fprintf(stream, "\t%-11s  %8s %8s\n", "VPD_Point", "Vdd_Ext", "Vcs_Ext");

    for (p = 0; p < NUM_PV_POINTS; p++)
    {
        fprintf(stream, "\t%-10s %6.1f%% %6.1f%%\n",
                vpdPvStr[p],
                (double)gppb->poundv_biases_0p05pct.vdd_ext_0p5pct[vpdPv[p]] ,
                (double)gppb->poundv_biases_0p05pct.vcs_ext_0p5pct[vpdPv[p]]
               );
    }

    uint16_t PsVSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    uint16_t VPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    float fPsVSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
    float fVPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];


    for (r = 0; r < RUNTIME_RAILS; r++)
    {
        for (p = 0; p < NUM_VPD_PTS_SET; p++)
        {
            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                PsVSlopes[r][p][s] = revle16(gppb->poundv_slopes.ps_voltage_slopes[r][p][s]);
                VPsSlopes[r][p][s] = revle16(gppb->poundv_slopes.voltage_ps_slopes[r][p][s]);
                fPsVSlopes[r][p][s] = float(PsVSlopes[r][p][s]);
                fPsVSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);
                fVPsSlopes[r][p][s] = float(VPsSlopes[r][p][s]);
                fVPsSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);
            }
        }
    }

    fprintf(stream, "\nPstate-Voltage Slopes\n");

    for (r = 0; r < RUNTIME_RAILS; r++)
    {
        fprintf(stream, "\tRail %u\n", r);
        fprintf(stream, "\t\t%-13s ", "Region");

        for (p = 0; p < NUM_VPD_PTS_SET; p++)
        {
            fprintf(stream, "Ps-VSlopes-%-25s ", vpdOpSetStr[p]);
        }

        fprintf(stream, "\n");

        for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
        {
            fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "%017.12f 0x%04x             ", fPsVSlopes[r][p][s], PsVSlopes[r][p][s]);
            }

            fprintf(stream, "\n");
        }

        fprintf(stream, "\n");
        fprintf(stream, "\t\t%-13s ", "Region");

        for (p = 0; p < NUM_VPD_PTS_SET; p++)
        {
            fprintf(stream, "V-PsSlopes-%-25s ", vpdOpSetStr[p]);
        }

        fprintf(stream, "\n");

        for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
        {
            fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "%017.12f 0x%04x             ", fVPsSlopes[r][p][s], VPsSlopes[r][p][s]);
            }

            fprintf(stream, "\n");
        }
    }


    if (dump_flag & PSTATE_DUMP_FULL)
    {
        fprintf(stream, "\nPstate-Current Slopes\n");
        //AC-TDP
        uint16_t PsAcTDPSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        float fPsAcTDPSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        uint16_t AcTDPPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        float fAcTDPPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];

        //DC-TDP
        uint16_t PsDcTDPSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        float fPsDcTDPSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        uint16_t DcTDPPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        float fDcTDPPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];

        //AC-RDP
        uint16_t PsAcRDPSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        float fPsAcRDPSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        uint16_t AcRDPPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        float fAcRDPPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];

        //DC-RDP
        uint16_t PsDcRDPSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        float fPsDcRDPSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        uint16_t DcRDPPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];
        float fDcRDPPsSlopes[RUNTIME_RAILS][NUM_VPD_PTS_SET][VPD_NUM_SLOPES_REGION];

        for (r = 0; r < RUNTIME_RAILS; r++)
        {
            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
                {
                    //AC-TDP
                    PsAcTDPSlopes[r][p][s] = revle16(gppb->poundv_slopes.ps_ac_current_tdp[r][p][s]);
                    AcTDPPsSlopes[r][p][s] = revle16(gppb->poundv_slopes.ac_current_ps_tdp[r][p][s]);
                    fPsAcTDPSlopes[r][p][s] = float(PsAcTDPSlopes[r][p][s]);
                    fPsVSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);
                    fAcTDPPsSlopes[r][p][s] = float(AcTDPPsSlopes[r][p][s]);
                    fAcTDPPsSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);

                    //DC-TDP
                    PsDcTDPSlopes[r][p][s] = revle16(gppb->poundv_slopes.ps_dc_current_tdp[r][p][s]);
                    DcTDPPsSlopes[r][p][s] = revle16(gppb->poundv_slopes.dc_current_ps_tdp[r][p][s]);
                    fPsDcTDPSlopes[r][p][s] = float(PsDcTDPSlopes[r][p][s]);
                    fPsVSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);
                    fDcTDPPsSlopes[r][p][s] = float(DcTDPPsSlopes[r][p][s]);
                    fDcTDPPsSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);

                    //AC-RDP
                    PsAcRDPSlopes[r][p][s] = revle16(gppb->poundv_slopes.ps_ac_current_rdp[r][p][s]);
                    AcRDPPsSlopes[r][p][s] = revle16(gppb->poundv_slopes.ac_current_ps_rdp[r][p][s]);
                    fPsAcRDPSlopes[r][p][s] = float(PsAcRDPSlopes[r][p][s]);
                    fPsVSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);
                    fAcRDPPsSlopes[r][p][s] = float(AcRDPPsSlopes[r][p][s]);
                    fAcRDPPsSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);

                    //DC-RDP
                    PsDcRDPSlopes[r][p][s] = revle16(gppb->poundv_slopes.ps_dc_current_rdp[r][p][s]);
                    DcRDPPsSlopes[r][p][s] = revle16(gppb->poundv_slopes.dc_current_ps_rdp[r][p][s]);
                    fPsDcRDPSlopes[r][p][s] = float(PsDcRDPSlopes[r][p][s]);
                    fPsVSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);
                    fDcRDPPsSlopes[r][p][s] = float(DcRDPPsSlopes[r][p][s]);
                    fDcRDPPsSlopes[r][p][s] /= (1 << VID_SLOPE_FP_SHIFT_12);
                }
            }
        }

        for (r = 0; r < RUNTIME_RAILS; r++)
        {
            fprintf(stream, "\tRail %u\n", r);
            fprintf(stream, "\n");
            fprintf(stream, "\t\t%-13s ", "Region");

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "PsAcTDPSlopes-%-25s", vpdOpSetStr[p]);
            }

            fprintf(stream, "\n");

            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

                for (p = 0; p < NUM_VPD_PTS_SET; p++)
                {
                    fprintf(stream, "%017.12f 0x%04x               ", fPsAcTDPSlopes[r][p][s], PsAcTDPSlopes[r][p][s]);
                }

                fprintf(stream, "\n");
            }

            fprintf(stream, "\n");
            fprintf(stream, "\t\t%-13s ", "Region");

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "AcTDPPsSlopes-%-25s", vpdOpSetStr[p]);
            }

            fprintf(stream, "\n");

            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

                for (p = 0; p < NUM_VPD_PTS_SET; p++)
                {
                    fprintf(stream, "%017.12f 0x%04x               ", fAcTDPPsSlopes[r][p][s], AcTDPPsSlopes[r][p][s]);
                }

                fprintf(stream, "\n");
            }

            fprintf(stream, "\n");
            fprintf(stream, "\t\t%-13s ", "Region");

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "PsDcTDPSlopes-%-25s", vpdOpSetStr[p]);
            }

            fprintf(stream, "\n");

            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

                for (p = 0; p < NUM_VPD_PTS_SET; p++)
                {
                    fprintf(stream, "%017.12f 0x%04x               ", fPsDcTDPSlopes[r][p][s], PsDcTDPSlopes[r][p][s]);
                }

                fprintf(stream, "\n");
            }

            fprintf(stream, "\n");
            fprintf(stream, "\t\t%-13s ", "Region");

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "DcTDPPsSlopes-%-25s", vpdOpSetStr[p]);
            }

            fprintf(stream, "\n");

            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

                for (p = 0; p < NUM_VPD_PTS_SET; p++)
                {
                    fprintf(stream, "%017.12f 0x%04x               ", fDcTDPPsSlopes[r][p][s], DcTDPPsSlopes[r][p][s]);
                }

                fprintf(stream, "\n");
            }


            fprintf(stream, "\n");
            fprintf(stream, "\t\t%-13s ", "Region");

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "PsAcRDPSlopes-%-25s", vpdOpSetStr[p]);
            }

            fprintf(stream, "\n");

            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

                for (p = 0; p < NUM_VPD_PTS_SET; p++)
                {
                    fprintf(stream, "%017.12f 0x%04x               ", fPsAcRDPSlopes[r][p][s], PsAcRDPSlopes[r][p][s]);
                }

                fprintf(stream, "\n");
            }

            fprintf(stream, "\n");
            fprintf(stream, "\t\t%-13s ", "Region");

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "AcRDPPsSlopes-%-25s", vpdOpSetStr[p]);
            }

            fprintf(stream, "\n");

            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

                for (p = 0; p < NUM_VPD_PTS_SET; p++)
                {
                    fprintf(stream, "%017.12f 0x%04x               ", fAcRDPPsSlopes[r][p][s], AcRDPPsSlopes[r][p][s]);
                }

                fprintf(stream, "\n");
            }


            fprintf(stream, "\n");
            fprintf(stream, "\t\t%-13s ", "Region");

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "PsDcRDPSlopes-%-25s", vpdOpSetStr[p]);
            }

            fprintf(stream, "\n");

            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

                for (p = 0; p < NUM_VPD_PTS_SET; p++)
                {
                    fprintf(stream, "%017.12f 0x%04x               ", fPsDcRDPSlopes[r][p][s], PsDcRDPSlopes[r][p][s]);
                }

                fprintf(stream, "\n");
            }

            fprintf(stream, "\n");
            fprintf(stream, "\t\t%-13s ", "Region");

            for (p = 0; p < NUM_VPD_PTS_SET; p++)
            {
                fprintf(stream, "DcRDPPsSlopes-%-25s", vpdOpSetStr[p]);
            }

            fprintf(stream, "\n");

            for (s = 0; s < VPD_NUM_SLOPES_REGION; s++)
            {
                fprintf(stream, "\t\t%-13s ", vpdOpSlopesRegionStr[s]);

                for (p = 0; p < NUM_VPD_PTS_SET; p++)
                {
                    fprintf(stream, "%017.12f 0x%04x               ", fDcRDPPsSlopes[r][p][s], DcRDPPsSlopes[r][p][s]);
                }

                fprintf(stream, "\n");
            }
        }
    }

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "GLOBAL PSTATE PARAMETER END@ %p\n", gppb);
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");

    fprintf(stream, "\n");
}


//
// _oppb_print
//
void oppb_print(FILE* stream, OCCPstateParmBlock_t const* i_oppb)
{
    static const uint32_t   BUFFSIZE = 256;
    char                    l_buffer[BUFFSIZE];
    char                    l_temp_buffer[BUFFSIZE];

    // Put out the endian-corrected scalars

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "OCC PSTATE PARAMETERS START@ %p\n", i_oppb);
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "sizeof(OCCPstateParmBlock):       %lu\n", sizeof(OCCPstateParmBlock_t));
    fprintf(stream, "Magic: %s\n", (char*)&i_oppb->magic);
    fprintf(stream, "Operating_Points:   Frequency       VDD(mV)      IDD(100mA)       VCS(mV)      ICS(100mA)\n");

    for (uint32_t i = 0; i < NUM_OP_POINTS; i++)
    {
        sprintf(l_buffer, "                 ");
        sprintf(l_temp_buffer, " 0x%04X (%4d) ",
                revle32(i_oppb->operating_points[i].frequency_mhz),
                revle32(i_oppb->operating_points[i].frequency_mhz));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " 0x%04X (%4d) ",
                revle32(i_oppb->operating_points[i].vdd_mv),
                revle32(i_oppb->operating_points[i].vdd_mv));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " 0x%04X (%4d) ",
                revle32(i_oppb->operating_points[i].idd_tdp_ac_10ma),
                revle32(i_oppb->operating_points[i].idd_tdp_ac_10ma));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " 0x%04X (%4d) ",
                revle32(i_oppb->operating_points[i].vcs_mv),
                revle32(i_oppb->operating_points[i].vcs_mv));
        strcat(l_buffer, l_temp_buffer);

        sprintf(l_temp_buffer, " 0x%04X (%3d) ",
                revle32(i_oppb->operating_points[i].ics_tdp_ac_10ma),
                revle32(i_oppb->operating_points[i].ics_tdp_ac_10ma));
        strcat(l_buffer, l_temp_buffer);
        fprintf(stream, "%s\n", l_buffer);
    }

    fprintf(stream, "System_Parameters:             VDD         VCS         VDN\n");
    sprintf(l_buffer, "   Load line (uOhm)         ");
    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.loadline_uohm),
            revle32(i_oppb->vdd_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.loadline_uohm),
            revle32(i_oppb->vcs_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.loadline_uohm),
            revle32(i_oppb->vdn_sysparm.loadline_uohm));
    strcat(l_buffer, l_temp_buffer);
    fprintf(stream, "%s\n", l_buffer);

    sprintf(l_buffer, "   Distribution_Loss(uOhm)  ");
    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.distloss_uohm),
            revle32(i_oppb->vdd_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.distloss_uohm),
            revle32(i_oppb->vcs_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.distloss_uohm),
            revle32(i_oppb->vdn_sysparm.distloss_uohm));
    strcat(l_buffer, l_temp_buffer);
    fprintf(stream, "%s\n", l_buffer);

    sprintf(l_buffer, "   Offset(uV)               ");
    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vdd_sysparm.distoffset_uv),
            revle32(i_oppb->vdd_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vcs_sysparm.distoffset_uv),
            revle32(i_oppb->vcs_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);

    sprintf(l_temp_buffer, " 0x%04X (%3d) ",
            revle32(i_oppb->vdn_sysparm.distoffset_uv),
            revle32(i_oppb->vdn_sysparm.distoffset_uv));
    strcat(l_buffer, l_temp_buffer);
    fprintf(stream, "%s\n", l_buffer);

    fprintf(stream, "Frequencies:\n");
    fprintf(stream, "  %-28s : 0x%04X (%3d)\n",
            "Frequency Minumum (kHz)",
            revle32(i_oppb->frequency_min_khz),
            revle32(i_oppb->frequency_min_khz));

    fprintf(stream, "  %-28s : 0x%04X (%3d)\n",
            "Frequency Maximum (kHz)",
            revle32(i_oppb->frequency_max_khz),
            revle32(i_oppb->frequency_max_khz));

    fprintf(stream, "  %-28s : 0x%04X (%3d)\n",
            "Frequency Ceiling (kHz)",
            revle32(i_oppb->frequency_ceiling_khz),
            revle32(i_oppb->frequency_ceiling_khz));

    fprintf(stream, "  %-28s : 0x%04X (%3d)\n",
            "Frequency Step (kHz)",
            revle32(i_oppb->frequency_step_khz),
            revle32(i_oppb->frequency_step_khz));

    fprintf(stream, "  %-28s : 0x%04X (%3d)\n",
            "Frequency Minimum (Pstate)",
            revle32(i_oppb->pstate_min),
            revle32(i_oppb->pstate_min));

    fprintf(stream, "  %-28s : 0x%04X (%3d)\n",
            "Frequency OCC Complex (MHz)",
            revle32(i_oppb->occ_complex_frequency_mhz),
            revle32(i_oppb->occ_complex_frequency_mhz));

    fprintf(stream, "Attributes:\n");

    fprintf(stream, "  %-28s : %1d\n",
            "pstates_enabled",
            i_oppb->attr.fields.pstates_enabled);

    fprintf(stream, "  %-28s : %1d\n",
            "resclk_enabled",
            i_oppb->attr.fields.resclk_enabled);

    fprintf(stream, "  %-28s : %1d\n",
            "wof_enabled",
            i_oppb->attr.fields.wof_enabled);

    fprintf(stream, "  %-28s : %1d\n",
            "wof_disable_vdd",
            i_oppb->attr.fields.wof_disable_vdd);

    fprintf(stream, "  %-28s : %1d\n",
            "wof_disable_vcs",
            i_oppb->attr.fields.wof_disable_vcs);

    fprintf(stream, "  %-28s : %1d\n",
            "wof_disable_io",
            i_oppb->attr.fields.wof_disable_io);

    fprintf(stream, "  %-28s : %1d\n",
            "wof_disable_amb",
            i_oppb->attr.fields.wof_disable_amb);

    fprintf(stream, "  %-28s : %1d\n",
            "wof_disable_vratio",
            i_oppb->attr.fields.wof_disable_vratio);

    fprintf(stream, "  %-28s : %1d\n",
            "dds_enabled",
            i_oppb->attr.fields.dds_enabled);

    fprintf(stream, "  %-28s : %1d\n",
            "ocs_enabled",
            i_oppb->attr.fields.ocs_enabled);

    fprintf(stream, "  %-28s : %1d\n",
            "underv_enabled",
            i_oppb->attr.fields.underv_enabled);

    fprintf(stream, "  %-28s : %1d\n",
            "overv_enabled",
            i_oppb->attr.fields.overv_enabled);

    fprintf(stream, "  %-28s : %1d\n",
            "throttle_control_enabled",
            i_oppb->attr.fields.throttle_control_enabled);

    fprintf(stream, "  %-28s : %1d\n",
            "rvrm_enabled",
            i_oppb->attr.fields.rvrm_enabled);


    fprintf(stream, "OCC PSTATE PARAMETER END@ %p\n", i_oppb);
    fprintf(stream, "\n");
}

//
//pgpe_flags_print
//
void pgpe_flags_print(FILE* stream,
                      const GlobalPstateParmBlock_v1_t* gppb)
{
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "PGPE FLAGS START\n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\nPGPE Flags\n");
    fprintf(stream, "\tResonant_Clocking          = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_RESCLK_ENABLE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tCurrent Read               = %s\n",
            (!gppb->pgpe_flags[PGPE_FLAG_CURRENT_READ_DISABLE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tOCS(Over-Current)          = %s\n",
            (!gppb->pgpe_flags[PGPE_FLAG_OCS_DISABLE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tWOF                        = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_WOF_ENABLE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tWOV-UnderVolt              = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_WOV_UNDERVOLT_ENABLE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tWOV-OverVolt               = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_WOV_OVERVOLT_ENABLE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tDDS-Coarse Throttle        = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_DDS_COARSE_THROTTLE_ENABLE]) ? "ENABLED" : "DISABLED");

    if (gppb->pgpe_flags[PGPE_FLAG_DDS_SLEW_MODE] == 0x0)
    {
        fprintf(stream, "\tDDS-SlewMode           = %s\n", "NONE");
    }
    else if (gppb->pgpe_flags[PGPE_FLAG_DDS_SLEW_MODE] == 0x1)
    {
        fprintf(stream, "\tDDS-SlewMode           = %s\n", "JUMP_PROTECT");
    }
    else if (gppb->pgpe_flags[PGPE_FLAG_DDS_SLEW_MODE] == 0x2)
    {
        fprintf(stream, "\tDDS-SlewMode           = %s\n", "SLEW_MODE");
    }

    fprintf(stream, "\tDDS-Frequency Jump         = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_FREQ_JUMP_ENABLE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tPMCR Most Recent           = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_PMCR_MOST_RECENT_ENABLE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tOCC Immediate Mode         = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_OCC_IPC_IMMEDIATE_MODE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tWOF Immediate Mode         = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_WOF_IPC_IMMEDIATE_MODE]) ? "ENABLED" : "DISABLED");
    fprintf(stream, "\tPhantom Halt               = %s\n",
            (gppb->pgpe_flags[PGPE_FLAG_PHANTOM_HALT_ENABLE]) ? "ENABLED" : "DISABLED");

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "PGPE FLAGS END\n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\n");
}

//
//resclk_print
//
void resclk_print(FILE* stream,
                  const GlobalPstateParmBlock_v1_t* gppb,
                  const char* i_title)
{
    uint32_t i, c;
    uint32_t l_freq;

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "%s RESONANT CLOCKING PARAMETERS START@ \n", i_title);
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "Frequency Index Table\n");
    fprintf(stream, "\t%2s %3s %5s  %5s\n", "  ", "Idx", " PS", "Freq(kHz)");

    const uint32_t l_columns = 8;

    // Note: in HOMER, the resclk_freq has been put in terms of Pstates for
    // Hcode use.
    for (i = 0; i < RESCLK_FREQ_REGIONS; i++)
    {
        l_freq = ((float)(revle32(gppb->base.reference_frequency_khz)) -
                  (gppb->resclk.ps[i] * (float)revle32(gppb->base.frequency_step_khz)));

        fprintf(stream, "\t%2d %3u %5u    %5u\n",
                i,
                gppb->resclk.index[i],
                gppb->resclk.ps[i],
                l_freq
               );
    }

    fprintf(stream, "Step Array");

    for (i = 0; i < RESCLK_STEPS;  i += l_columns)
    {
        fprintf(stream, "\n");

        for (c = 0; c < l_columns; c++)
        {
            fprintf(stream, "\t%2u 0x%04x", i + c, revle16(gppb->resclk.steparray[i + c].value));
        }

    }

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\nRESONANT CLOCKING PARAMETERS END \n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\n");
}


//
//dds_print
//
void dds_print(FILE* stream,
               const GlobalPstateParmBlock_v1_t* gppb)
{
    uint32_t c, p;
    const char* vpdPvStr[NUM_OP_POINTS] = PV_OP_STR;
    const int   vpdPv[NUM_OP_POINTS] = PV_OP;
    //uint32_t c,p;
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "DIGITAL DROOP SENSOR PARAMETERS START@ \n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "DDS Points \n");
    fprintf(stream,         "\t%4s %13s %7s %6s %7s %5s %5s %5s %5s %5s %11s %9s %11s %9s %9s %9s\n", "Core", "  Point",
            "CalAdj", "InsDly", "TripOff",
            "Data0", "Data1", "Data2", "Large", "Small", "SlopeAStart", "SlopeAEnd", "SlopeBStart", "SlopeBEnd", "SlopeACyc",
            "SlopeBCyc");

    for (c = 0 ; c < MAXIMUM_CORES; c++)
    {
        for (p = 0; p < NUM_PV_POINTS; p++)
        {
            fprintf(stream, "\t%4u %13s %7lu %6lu %7lu %5lu %5lu %5lu %5lu %5lu %11lu %9lu %11lu %9lu %9lu %9lu\n",
                    c,
                    vpdPvStr[p],
                    gppb->dds[vpdPv[p]][c].ddsc.fields.calb_adj,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.insrtn_dely,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.trip_offset,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.data0_select,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.data1_select,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.data2_select,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.large_droop,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.small_droop,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.slopeA_start,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.slopeA_end,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.slopeB_start,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.slopeB_end,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.slopeA_cycles,
                    gppb->dds[vpdPv[p]][c].ddsc.fields.slopeB_cycles
                   );
        }
    }

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "DIGITAL DROOP SENSOR PARAMETERS END \n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\n");
}


//
//wov_wof_print
//

void wov_wof_print(FILE* stream,
                   const GlobalPstateParmBlock_v1_t* gppb)
{
    //WOV
    fprintf(stream,
            "\n---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "WOV/WOF PARAMETERS START\n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "WOV-Underv Performance Loss Threshold  %6.1f%%\n",
            (double)gppb->wov.wov_underv_perf_loss_thresh_pct / 10);
    fprintf(stream, "WOV-Underv Step Increment              %6.1f%%\n", (double)gppb->wov.wov_underv_step_incr_pct);
    fprintf(stream, "WOV-Underv Step Decrement              %6.1f%%\n", (double)gppb->wov.wov_underv_step_decr_pct);
    fprintf(stream, "WOV-Underv Max                         %6.1f%%\n", (double)gppb->wov.wov_underv_max_pct);
    fprintf(stream, "WOV-Underv Vmin                        %6u mV\n", revle16(gppb->wov.wov_underv_vmin_mv));

    fprintf(stream, "WOV-Overv Step Increment               %6.1f%%\n", (double)gppb->wov.wov_overv_step_incr_pct);
    fprintf(stream, "WOV-Overv Step Decrement               %6.1f%%\n", (double)gppb->wov.wov_overv_step_decr_pct);
    fprintf(stream, "WOV-Overv Max                          %6.1f%%\n", (double)gppb->wov.wov_overv_max_pct);
    fprintf(stream, "WOV-Overv Vmax                         %6u mV\n", revle16(gppb->wov.wov_overv_vmax_mv));
    fprintf(stream, "WOV Sample Rate                        %6u uS\n", 125 * gppb->wov.wov_sample_125us);
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "WOV/WOF PARAMETERS END\n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\n");
}

void vrm_print(FILE* stream,
               const GlobalPstateParmBlock_v1_t* gppb)
{

    uint32_t r;
    //AvsBusTopology
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "VRM PARAMETERS START\n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\nAvsBus Topology\n");
    fprintf(stream, "\t Type    BusNum    RailNum \n");
    fprintf(stream, "\t VDD       %u         %u\n", gppb->avs_bus_topology.vdd_avsbus_num,
            gppb->avs_bus_topology.vdd_avsbus_rail);
    fprintf(stream, "\t VDN       %u         %u\n", gppb->avs_bus_topology.vdn_avsbus_num,
            gppb->avs_bus_topology.vdn_avsbus_rail);
    fprintf(stream, "\t VCS       %u         %u\n", gppb->avs_bus_topology.vcs_avsbus_num,
            gppb->avs_bus_topology.vcs_avsbus_rail);
    fprintf(stream, "\t VIO       %u         %u\n", gppb->avs_bus_topology.vio_avsbus_num,
            gppb->avs_bus_topology.vio_avsbus_rail);

    fprintf(stream, "\nVRM Parameters\n");

    for (r = 0; r < RUNTIME_RAILS; r++)
    {
        fprintf(stream, "\tVRM Rail %u\n", r);
        fprintf(stream, "\tTransition Start:              %u nS\n", revle32(gppb->ext_vrm_parms.transition_start_ns[r]));
        fprintf(stream, "\tTransition Rate Inc:           %u uV/uS\n",
                revle32(gppb->ext_vrm_parms.transition_rate_inc_uv_per_us[r]));
        fprintf(stream, "\tTransition Rate Dec:           %u uV/uS\n",
                revle32(gppb->ext_vrm_parms.transition_rate_dec_uv_per_us[r]));
        fprintf(stream, "\tStabilization Time:            %u us\n", revle32(gppb->ext_vrm_parms.stabilization_time_us[r]));
        fprintf(stream, "\tStep Size:                     %u mV\n", revle32(gppb->ext_vrm_parms.step_size_mv[r]));
    }

    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "VRM PARAMETERS END\n");
    fprintf(stream,
            "---------------------------------------------------------------------------------------------------------\n");
    fprintf(stream, "\n");
}


/// Print an iddq_print structure on a given stream
///
/// \param i_iddqt pointer to Iddq structure to output

void
iddq_print(const IddqTable_t* i_iddqt)
{
    uint32_t        i, j;
    const char*     idd_meas_str[IDDQ_MEASUREMENTS] = IDDQ_ARRAY_VOLTAGES_STR;
    char            l_buffer_str[256];   // Temporary formatting string buffer
    char            l_line_str[256];     // Formatted output line string

    static const uint32_t IDDQ_DESC_SIZE = 56;
    static const uint32_t IDDQ_QUAD_SIZE = IDDQ_DESC_SIZE -
                                           strlen("Quad X:");


    LCL_INF("---------------------------------------------------------------------------------------------------------");
    LCL_INF( "IDDQ PARAMETERS START@ %p", i_iddqt);
    LCL_INF("---------------------------------------------------------------------------------------------------------");

    // Put out the endian-corrected scalars

    // get IQ version and advance pointer 1-byte
    LCL_INF("  IDDQ Version Number = %u", i_iddqt->iddq_version);
    LCL_INF("  Sort Info:         Good Cores = %02d ",
            i_iddqt->good_normal_cores_per_sort);

    // get number of good normal cores in each quad
    strcpy(l_line_str, "  Good normal cores:");
    strcpy(l_buffer_str, "");

    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        sprintf(l_buffer_str, " EQ%d = %u ", i, i_iddqt->good_normal_cores_per_EQs[i]);
        strcat(l_line_str, l_buffer_str);
    }

    LCL_INF("%s", l_line_str);

    // All IQ IDDQ measurements are at 5mA resolution. The OCC wants to
    // consume these at 1mA values.  thus, all values are multiplied by
    // 5 upon installation into the paramater block.
    static const uint32_t CONST_5MA_1MA = 5;
    LCL_INF("  IDDQ data is converted 5mA units to 1mA units");

    // Put out the measurement voltages to the trace.
    strcpy(l_line_str, "  Measurement voltages:");
    sprintf(l_buffer_str, "%-*s", IDDQ_DESC_SIZE, l_line_str);
    strcpy(l_line_str, l_buffer_str);
    strcpy(l_buffer_str, "");

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        sprintf(l_buffer_str, "  %*sV ", 5, idd_meas_str[i]);
        strcat(l_line_str, l_buffer_str);
    }

    LCL_INF("%s", l_line_str);

#define IDDQ_CURRENT_EXTRACT(_member)                       \
    sprintf(l_buffer_str, " %7.3f ",                        \
            ((double)revle16(i_iddqt->_member)) * CONST_5MA_1MA / 1000); \
    strcat(l_line_str, l_buffer_str);

#define IDDQ_TEMP_EXTRACT(_member)                          \
    sprintf(l_buffer_str, "   %4.1f  ",                     \
            ((double)i_iddqt->_member) / 2);                \
    strcat(l_line_str, l_buffer_str);

#define IDDQ_TRACE(string, size)                            \
    strcpy(l_line_str, string);                             \
    sprintf(l_buffer_str, "%-*s", size, l_line_str);        \
    strcpy(l_line_str, l_buffer_str);                       \
    strcpy(l_buffer_str, "");

    // get IVDDQ measurements with all good cores ON and caches ON
    IDDQ_TRACE ("  IDDQ all good cores ON and good caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_on_caches_on_5ma[i]);
    }

    LCL_INF("%s", l_line_str);

    // get IDDQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  IDDQ all good cores and good caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_off_good_caches_off_5ma[i]);
    }

    LCL_INF("%s", l_line_str);;

    // get IDDQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  IDDQ all good cores OFF and caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(iddq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    LCL_INF("%s", l_line_str);

    // get IDDQ measurements with all good cores in each EQ
    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        IDDQ_TRACE ("  IDDQ all good cores ON and good caches ON in EQ ", IDDQ_QUAD_SIZE);
        sprintf(l_buffer_str, "EQ%d:  ", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(iddq_eqs_good_cores_on_good_caches_on_5ma[i][j]);
        }

        LCL_INF("%s", l_line_str);
    }

    // get ICSQ measurements with all good cores ON and caches ON
    IDDQ_TRACE ("  ICSQ all good cores ON and good caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_on_caches_on_5ma[i]);
    }

    LCL_INF("%s", l_line_str);

    // get ICSQ measurements with all cores and caches OFF
    IDDQ_TRACE ("  ICSQ all good cores and good caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_off_good_caches_off_5ma[i]);
    }

    LCL_INF("%s", l_line_str);;

    // get ICSQ measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  ICSQ all good cores OFF and good caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_CURRENT_EXTRACT(icsq_all_good_cores_off_good_caches_on_5ma[i]);
    }

    LCL_INF("%s", l_line_str);

    // get ICSQ measurements with all good cores in each EQ
    for (i = 0; i < MAXIMUM_EQ_SETS; i++)
    {
        IDDQ_TRACE ("  ICSQ all good cores ON and good caches ON in EQ ", IDDQ_QUAD_SIZE);
        sprintf(l_buffer_str, "EQ%d:  ", i);
        strcat(l_line_str, l_buffer_str);

        for (j = 0; j < IDDQ_MEASUREMENTS; j++)
        {
            IDDQ_CURRENT_EXTRACT(icsq_eqs_good_cores_on_good_caches_on_5ma[i][j]);
        }

        LCL_INF("%s", l_line_str);
    }

    // get average temperature measurements with all good cores ON
    IDDQ_TRACE ("  Average temp all good cores ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_cores_on_good_caches_on_p5c[i]);
    }

    LCL_INF("%s", l_line_str);

    // get average temperatur}e measurements with all cores and caches OFF
    IDDQ_TRACE ("  Average temp all cores OFF, caches OFF:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_cores_off_caches_off_p5c[i]);
    }

    LCL_INF("%s", l_line_str);

    // get average temperature measurements with all good cores OFF and caches ON
    IDDQ_TRACE ("  Average temp all good cores OFF, caches ON:", IDDQ_DESC_SIZE);

    for (i = 0; i < IDDQ_MEASUREMENTS; i++)
    {
        IDDQ_TEMP_EXTRACT(avgtemp_all_good_cores_off_good_caches_on_p5c[i]);
    }

    LCL_INF("%s", l_line_str);


    LCL_INF("IDDQ PARAMETERS END@ %p", i_iddqt);
    LCL_INF(" ");
}
