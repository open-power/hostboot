/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plugins/prdfCenLogParse.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2003,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/** @file  prdfCenLogParse.C
 *  @brief Error log parsing code specific to the memory subsystem.
 */

#include <prdfCenLogParse.H>

#include <errlusrparser.H>
#include <cstring>
#include <utilmem.H>
#include  <iipconst.h>
#include <prdfDramRepairUsrData.H>
#include <prdfMemoryMruData.H>
#include <prdfParserEnums.H>

namespace PRDF
{

#ifdef PRDF_HOSTBOOT_ERRL_PLUGIN
namespace HOSTBOOT
#else
namespace FSP
#endif
{

using namespace PARSER;
using namespace MemoryMruData;
using namespace CEN_SYMBOL;

static const char * dramSiteCardAPortARank02[ ] =

{
    "DA01.d3", "DA01.d0", "DA01.d2", "DA01.d7",
    "DA01.d1", "DA01.d6", "DA01.d5", "DA01.d4",

    "DA04.d3", "DA04.d6", "DA04.d0", "DA04.d2",
    "DA04.d1", "DA04.d7", "DA04.d4", "DA04.d5",

    "DA07.d3", "DA07.d1", "DA07.d4", "DA07.d6",
    "DA07.d7", "DA07.d5", "DA07.d0", "DA07.d2",

    "DA06.d6", "DA06.d2", "DA06.d0", "DA06.d4",
    "DA06.d3", "DA06.d5", "DA06.d1", "DA06.d7",

    "DA02.d1", "DA02.d5", "DA02.d0", "DA02.d6",
    "DA02.d7", "DA02.d3", "DA02.d4", "DA02.d2",

    "DA05.d5", "DA05.d1", "DA05.d4", "DA05.d0",
    "DA05.d7", "DA05.d3", "DA05.d6", "DA05.d2",

    "DA03.d7", "DA03.d0", "DA03.d6", "DA03.d4",
    "DA03.d5", "DA03.d3", "DA03.d1", "DA03.d2",

    "DA08.d6", "DA08.d4", "DA08.d5", "DA08.d1",
    "DA08.d0", "DA08.d2", "DA08.d7", "DA08.d3",

    "DA09.d6", "DA09.d1", "DA09.d2", "DA09.d4",
    "DA09.d3", "DA09.d0", "DA09.d5", "DA09.d7",

    "DA0SP.d2", "DA0SP.d6", "DA0SP.d0", "DA0SP.d7",
    "DA0SP.d3", "DA0SP.d4", "DA0SP.d5", "DA0SP.d1"
};

//---------------------------------------------------------

static const char * dramCardAPortARank02[ ] =
{
    "DA01", "DA04", "DA07", "DA06", "DA02", "DA05", "DA03", "DA08",
    "DA09", "DA0SP"
};
//---------------------------------------------------------

static const char * dramSiteCardAPortARank46[ ] =
{
    "DA11.d2", "DA11.d1", "DA11.d3", "DA11.d4",
    "DA11.d0", "DA11.d5", "DA11.d6", "DA11.d7",

    "DA14.d2", "DA14.d5", "DA14.d1", "DA14.d3",
    "DA14.d0", "DA14.d4", "DA14.d7", "DA14.d6",

    "DA17.d2", "DA17.d0", "DA17.d7", "DA17.d5",
    "DA17.d4", "DA17.d6", "DA17.d1", "DA17.d3",

    "DA16.d5", "DA16.d3", "DA16.d1", "DA16.d7",
    "DA16.d2", "DA16.d6", "DA16.d0", "DA16.d4",

    "DA12.d0", "DA12.d6", "DA12.d1", "DA12.d5",
    "DA12.d4", "DA12.d2", "DA12.d7", "DA12.d3",

    "DA15.d6", "DA15.d0", "DA15.d7", "DA15.d1",
    "DA15.d4", "DA15.d2", "DA15.d5", "DA15.d3",

    "DA13.d4", "DA13.d1", "DA13.d5", "DA13.d7",
    "DA13.d6", "DA13.d2", "DA13.d0", "DA13.d3",

    "DA18.d5", "DA18.d7", "DA18.d6", "DA18.d0",
    "DA18.d1", "DA18.d3", "DA18.d4", "DA18.d2",

    "DA19.d5", "DA19.d0", "DA19.d3", "DA19.d7",
    "DA19.d2", "DA19.d1", "DA19.d6", "DA19.d4",

    "DA1SP.d3", "DA1SP.d5", "DA1SP.d1", "DA1SP.d4",
    "DA1SP.d2", "DA1SP.d7", "DA1SP.d6", "DA1SP.d0"
} ;//rank4_6

//---------------------------------------------------------

static const char * dramCardAPortARank46[ ] =
{
    "DA11", "DA14","DA17","DA16", "DA12", "DA15", "DA13", "DA18", "DA19","DA1SP"
};

//---------------------------------------------------------

static const char * dramSiteCardAPortBRank02[] =
{
    "DB07.d4", "DB07.d6", "DB07.d0", "DB07.d1",
    "DB07.d5", "DB07.d3", "DB07.d2",  "DB07.d7",

    "DB01.d6", "DB01.d2", "DB01.d1", "DB01.d0",
    "DB01.d4", "DB01.d3", "DB01.d7", "DB01.d5",

    "DB03.d5", "DB03.d1", "DB03.d4", "DB03.d2",
    "DB03.d3", "DB03.d7", "DB03.d6", "DB03.d0",

    "DB02.d7", "DB02.d1", "DB02.d5", "DB02.d4",
    "DB02.d6", "DB02.d3", "DB02.d2", "DB02.d0",

    "DB06.d3", "DB06.d4", "DB06.d6", "DB06.d2",
    "DB06.d5", "DB06.d7", "DB06.d1", "DB06.d0",

    "DB05.d4", "DB05.d7", "DB05.d2", "DB05.d0",
    "DB05.d3", "DB05.d5", "DB05.d1", "DB05.d6",

    "DB08.d4", "DB08.d3", "DB08.d7", "DB08.d6",
    "DB08.d1", "DB08.d5", "DB08.d0", "DB08.d2",

    "DB04.d7", "DB04.d1", "DB04.d6", "DB04.d5",
    "DB04.d3", "DB04.d4", "DB04.d0", "DB04.d2",

    "DB09.d4", "DB09.d6", "DB09.d7", "DB09.d1",
    "DB09.d2", "DB09.d0", "DB09.d5", "DB09.d3",

    "DB0SP.d1", "DB0SP.d5", "DB0SP.d7", "DB0SP.d0",
    "DB0SP.d4", "DB0SP.d6", "DB0SP.d2", "DB0SP.d3",

};

//---------------------------------------------------------

static const char * dramCardAPortBRank02[ ] =
{
    "DB07", "DB01", "DB03", "DB02", "DB06", "DB05", "DB08", "DB04",
    "DB09", "DB0SP"
};

//---------------------------------------------------------

static const char * dramSiteCardAPortBRank46[] =
{
    "DB17.d7", "DB17.d5", "DB17.d1", "DB17.d0",
    "DB17.d6", "DB17.d2", "DB17.d3", "DB17.d4",

    "DB11.d5", "DB11.d3", "DB11.d0", "DB11.d1",
    "DB11.d7", "DB11.d2", "DB11.d4", "DB11.d6",

    "DB13.d6", "DB13.d0", "DB13.d7", "DB13.d3",
    "DB13.d2", "DB13.d4", "DB13.d5", "DB13.d1",

    "DB12.d4", "DB12.d0", "DB12.d6", "DB12.d7",
    "DB12.d5", "DB12.d2", "DB12.d3", "DB12.d1",

    "DB16.d2", "DB16.d7", "DB16.d5", "DB16.d3",
    "DB16.d6", "DB16.d4", "DB16.d0", "DB16.d1",

    "DB15.d7", "DB15.d4", "DB15.d3", "DB15.d1",
    "DB15.d2", "DB15.d6", "DB15.d0", "DB15.d5",

    "DB18.d7", "DB18.d2", "DB18.d4", "DB18.d5",
    "DB18.d0", "DB18.d6", "DB18.d1", "DB18.d3",

    "DB14.d4", "DB14.d0", "DB14.d5", "DB14.d6",
    "DB14.d2", "DB14.d7", "DB14.d1", "DB14.d3",

    "DB19.d7", "DB19.d5", "DB19.d4", "DB19.d0",
    "DB19.d3", "DB19.d1", "DB19.d6", "DB19.d2",

    "DB1SP.d0", "DB1SP.d6", "DB1SP.d4", "DB1SP.d1",
    "DB1SP.d7", "DB1SP.d5", "DB1SP.d3", "DB1SP.d2",

};

//---------------------------------------------------------

static const char * dramCardAPortBRank46[ ] =
{
    "DB17", "DB11","DB13","DB12", "DB16", "DB15", "DB18", "DB14", "DB19","DB1SP"
};

//---------------------------------------------------------

static const char * dramSiteCardAPortCRank02[] =
{
    "DC02.d2", "DC02.d0", "DC02.d7", "DC02.d5",
    "DC02.d4", "DC02.d6", "DC02.d1",  "DC02.d3",

    "DC03.d3", "DC03.d6", "DC03.d7", "DC03.d1",
    "DC03.d2", "DC03.d0", "DC03.d5", "DC03.d4",

    "DC05.d6", "DC05.d0", "DC05.d5", "DC05.d2",
    "DC05.d4", "DC05.d1", "DC05.d7", "DC05.d3",

    "DC08.d5", "DC08.d0", "DC08.d1", "DC08.d6",
    "DC08.d2", "DC08.d7", "DC08.d3", "DC08.d4",

    "DC01.d7", "DC01.d3", "DC01.d6", "DC01.d2",
    "DC01.d5", "DC01.d1", "DC01.d4", "DC01.d0",

    "DC06.d1", "DC06.d5", "DC06.d4", "DC06.d7",
    "DC06.d3", "DC06.d6", "DC06.d2", "DC06.d0",

    "DC04.d5", "DC04.d3", "DC04.d0", "DC04.d2",
    "DC04.d7", "DC04.d1", "DC04.d4", "DC04.d6",

    "DC09.d0", "DC09.d1", "DC09.d5", "DC09.d3",
    "DC09.d2", "DC09.d4", "DC09.d6", "DC09.d7",

    "DC07.d3", "DC07.d1", "DC07.d0", "DC07.d7",
    "DC07.d5", "DC07.d4", "DC07.d6", "DC07.d2",

    "DC0SP.d2", "DC0SP.d0", "DC0SP.d6", "DC0SP.d1",
    "DC0SP.d4", "DC0SP.d7", "DC0SP.d5", "DC0SP.d3",

};

//---------------------------------------------------------

static const char * dramCardAPortCRank02[ ] =
{
    "DC02", "DC03", "DC05", "DC08", "DC01", "DC06", "DC04", "DC09",
    "DC07", "DC0SP"
};

//---------------------------------------------------------

static const char * dramSiteCardAPortCRank46[] =
{
    "DC12.d3", "DC12.d1", "DC12.d4", "DC12.d6",
    "DC12.d7", "DC12.d5", "DC12.d0", "DC12.d2",

    "DC13.d2", "DC13.d5", "DC13.d4", "DC13.d0",
    "DC13.d3", "DC13.d1", "DC13.d6", "DC13.d7",

    "DC15.d5", "DC15.d1", "DC15.d6", "DC15.d3",
    "DC15.d7", "DC15.d0", "DC15.d4", "DC15.d2",

    "DC18.d6", "DC18.d1", "DC18.d0", "DC18.d5",
    "DC18.d3", "DC18.d4", "DC18.d2", "DC18.d7",

    "DC11.d4", "DC11.d2", "DC11.d5", "DC11.d3",
    "DC11.d6", "DC11.d0", "DC11.d7", "DC11.d1",

    "DC16.d0", "DC16.d6", "DC16.d7", "DC16.d4",
    "DC16.d2", "DC16.d5", "DC16.d3", "DC16.d1",

    "DC14.d6", "DC14.d2", "DC14.d1", "DC14.d3",
    "DC14.d4", "DC14.d0", "DC14.d7", "DC14.d5",

    "DC19.d1", "DC19.d0", "DC19.d6", "DC19.d2",
    "DC19.d3", "DC19.d7", "DC19.d5", "DC19.d4",

    "DC17.d2", "DC17.d0", "DC17.d1", "DC17.d4",
    "DC17.d6", "DC17.d7", "DC17.d5", "DC17.d3",

    "DC1SP.d3", "DC1SP.d1", "DC1SP.d5", "DC1SP.d0",
    "DC1SP.d7", "DC1SP.d4", "DC1SP.d6", "DC1SP.d2",

};

//---------------------------------------------------------

static const char * dramCardAPortCRank46[ ] =
{
    "DC12", "DC13", "DC15", "DC18", "DC11", "DC16", "DC14", "DC19",
    "DC17", "DC1SP"
};

//---------------------------------------------------------

static const char * dramSiteCardAPortDRank02[] =
{
    "DD05.d5", "DD05.d3", "DD05.d2", "DD05.d6",
    "DD05.d1", "DD05.d7", "DD05.d0", "DD05.d4",

    "DD04.d7", "DD04.d5", "DD04.d6", "DD04.d2",
    "DD04.d1", "DD04.d3", "DD04.d0", "DD04.d4",

    "DD02.d1", "DD02.d4", "DD02.d3", "DD02.d7",
    "DD02.d6", "DD02.d5", "DD02.d0", "DD02.d2",

    "DD08.d7", "DD08.d1", "DD08.d4", "DD08.d2",
    "DD08.d3", "DD08.d5", "DD08.d6", "DD08.d0",

    "DD01.d4", "DD01.d2", "DD01.d5", "DD01.d1",
    "DD01.d0", "DD01.d6", "DD01.d7", "DD01.d3",

    "DD09.d2", "DD09.d6", "DD09.d3", "DD09.d1",
    "DD09.d0", "DD09.d4", "DD09.d5", "DD09.d7",

    "DD03.d2", "DD03.d7", "DD03.d4", "DD03.d6",
    "DD03.d1", "DD03.d3", "DD03.d0", "DD03.d5",

    "DD07.d7", "DD07.d3", "DD07.d0", "DD07.d2",
    "DD07.d5", "DD07.d1", "DD07.d4", "DD07.d6",

    "DD06.d3", "DD06.d5", "DD06.d0", "DD06.d1",
    "DD06.d6", "DD06.d7", "DD06.d4", "DD06.d2",

    "DD0SP.d7", "DD0SP.d1", "DD0SP.d2", "DD0SP.d0",
    "DD0SP.d6", "DD0SP.d5", "DD0SP.d4", "DD0SP.d3",

};

//---------------------------------------------------------

static const char * dramCardAPortDRank02[ ] =
{
    "DD05",  "DD04", "DD02", "DD08", "DD01", "DD09", "DD03", "DD07",
    "DD06",  "DD0SP"
};

//---------------------------------------------------------

static const char * dramSiteCardAPortDRank46[] =
{
    "DD15.d6", "DD15.d2", "DD15.d3", "DD15.d5",
    "DD15.d0", "DD15.d4", "DD15.d1", "DD15.d7",

    "DD14.d4", "DD14.d6", "DD14.d5", "DD14.d3",
    "DD14.d0", "DD14.d2", "DD14.d1", "DD14.d7",

    "DD12.d0", "DD12.d7", "DD12.d2", "DD12.d4",
    "DD12.d5", "DD12.d6", "DD12.d1", "DD12.d3",

    "DD18.d4", "DD18.d0", "DD18.d7", "DD18.d3",
    "DD18.d2", "DD18.d6", "DD18.d5", "DD18.d1",

    "DD11.d7", "DD11.d3", "DD11.d6", "DD11.d0",
    "DD11.d1", "DD11.d5", "DD11.d4", "DD11.d2",

    "DD19.d3", "DD19.d5", "DD19.d2", "DD19.d0",
    "DD19.d1", "DD19.d7", "DD19.d6", "DD19.d4",

    "DD13.d3", "DD13.d4", "DD13.d7", "DD13.d5",
    "DD13.d0", "DD13.d2", "DD13.d1", "DD13.d6",

    "DD17.d4", "DD17.d2", "DD17.d1", "DD17.d3",
    "DD17.d6", "DD17.d0", "DD17.d7", "DD17.d5",

    "DD16.d2", "DD16.d6", "DD16.d1", "DD16.d0",
    "DD16.d5", "DD16.d4", "DD16.d7", "DD16.d3",

    "DD1SP.d4", "DD1SP.d0", "DD1SP.d3", "DD1SP.d1",
    "DD1SP.d5", "DD1SP.d6", "DD1SP.d7", "DD1SP.d2",
};

//---------------------------------------------------------

static const char * dramCardAPortDRank46[ ] =
{
    "DD15", "DD14", "DD12", "DD18", "DD11", "DD19", "DD13", "DD17",
    "DD16", "DD1SP"
};

//---------------------------------------------------------

static const char * dramSiteCardBPortARank02[ ] =

{
    "DA07.d3", "DA07.d0", "DA07.d2", "DA07.d1",
    "DA02.d2", "DA02.d0", "DA02.d3", "DA02.d1",

    "DA03.d2", "DA03.d1", "DA03.d3", "DA03.d0",
    "DA04.d3", "DA04.d1", "DA04.d2", "DA04.d0",

    "DA12.d3", "DA12.d1", "DA12.d2", "DA12.d0",
    "DA06.d1", "DA06.d3", "DA06.d2", "DA06.d0",

    "DA11.d2", "DA11.d0", "DA11.d3", "DA11.d1",
    "DA05.d2", "DA05.d1", "DA05.d0", "DA05.d3",

    "DA14.d1", "DA14.d3", "DA14.d0", "DA14.d2",
    "DA18.d1", "DA18.d3", "DA18.d2", "DA18.d0",

    "DA13.d3", "DA13.d1", "DA13.d0", "DA13.d2",
    "DA19.d3", "DA19.d1", "DA19.d0", "DA19.d2",

    "DA09.d2", "DA09.d3", "DA09.d1", "DA09.d0",
    "DA16.d0", "DA16.d3", "DA16.d1", "DA16.d2",

    "DA08.d1", "DA08.d3", "DA08.d2", "DA08.d0",
    "DA15.d0", "DA15.d2", "DA15.d3", "DA15.d1",

    "DA01.d3", "DA01.d2", "DA01.d0", "DA01.d1",
    "DA17.d0", "DA17.d2", "DA17.d1", "DA17.d3",

    "DA1SP.d3", "DA1SP.d1", "DA1SP.d2", "DA1SP.d0",
    NULL,       NULL,       NULL,       NULL,
};

//---------------------------------------------------------

static const char * dramCardBPortARank02[ ] =
{
    "DA07", "DA02", "DA03", "DA04", "DA12", "DA06", "DA11", "DA05",
    "DA14", "DA18", "DA13", "DA19", "DA09", "DA16", "DA08", "DA15",
    "DA01", "DA17", "DA1SP",NULL
};
//---------------------------------------------------------

static const char * dramSiteCardBPortARank46[ ] =
{
    "DA27.d2", "DA27.d1", "DA27.d3", "DA27.d0",
    "DA22.d3", "DA22.d1", "DA22.d2", "DA22.d0",

    "DA23.d3", "DA23.d0", "DA23.d2", "DA23.d1",
    "DA24.d2", "DA24.d0", "DA24.d3", "DA24.d1",

    "DA32.d2", "DA32.d0", "DA32.d3", "DA32.d1",
    "DA26.d0", "DA26.d2", "DA26.d3", "DA26.d1",

    "DA31.d3", "DA31.d1", "DA31.d2", "DA31.d0",
    "DA25.d3", "DA25.d0", "DA25.d1", "DA25.d2",

    "DA34.d0", "DA34.d2", "DA34.d1", "DA34.d3",
    "DA38.d0", "DA38.d2", "DA38.d3", "DA38.d1",

    "DA33.d2", "DA33.d0", "DA33.d1", "DA33.d3",
    "DA39.d2", "DA39.d0", "DA39.d1", "DA39.d3",

    "DA29.d3", "DA29.d2", "DA29.d0", "DA29.d1",
    "DA36.d1", "DA36.d2", "DA36.d0", "DA36.d3",

    "DA28.d0", "DA28.d2", "DA28.d3", "DA28.d1",
    "DA35.d1", "DA35.d3", "DA35.d2", "DA35.d0",

    "DA21.d2", "DA21.d3", "DA21.d1", "DA21.d0",
    "DA37.d1", "DA37.d3", "DA37.d0", "DA37.d2",

    "DA3SP.d2", "DA3SP.d0", "DA3SP.d3", "DA3SP.d1",
    NULL,       NULL,       NULL,       NULL,

} ;//rank4_6

//---------------------------------------------------------

static const char * dramCardBPortARank46[ ] =
{
    "DA27", "DA22", "DA23", "DA24", "DA32", "DA26", "DA31", "DA25",
    "DA34", "DA38", "DA33", "DA39", "DA29", "DA36", "DA28", "DA35",
    "DA21", "DA37", "DA3SP",NULL
};

//---------------------------------------------------------

static const char * dramSiteCardBPortBRank02[] =
{
    "DB13.d0", "DB13.d2", "DB13.d3", "DB13.d1",
    "DB16.d3", "DB16.d2", "DB16.d1", "DB16.d0",

    "DB14.d3", "DB14.d0", "DB14.d1", "DB14.d2",
    "DB17.d3", "DB17.d2", "DB17.d1", "DB17.d0",

    "DB01.d1", "DB01.d3", "DB01.d0", "DB01.d2",
    "DB15.d2", "DB15.d1", "DB15.d0", "DB15.d3",

    "DB11.d0", "DB11.d2", "DB11.d1", "DB11.d3",
    "DB19.d0", "DB19.d2", "DB19.d1", "DB19.d3",

    "DB04.d3", "DB04.d2", "DB04.d0", "DB04.d1",
    "DB03.d2", "DB03.d0", "DB03.d3", "DB03.d1",

    "DB05.d0", "DB05.d3", "DB05.d2",  "DB05.d1",
    "DB07.d1", "DB07.d3", "DB07.d2", "DB07.d0",

    "DB06.d0", "DB06.d3", "DB06.d1", "DB06.d2",
    "DB09.d1", "DB09.d3", "DB09.d0", "DB09.d2",

    "DB08.d1", "DB08.d3", "DB08.d2", "DB08.d0",
    "DB18.d2", "DB18.d3", "DB18.d0", "DB18.d1",

    "DB02.d3", "DB02.d1", "DB02.d2", "DB02.d0",
    "DB12.d0", "DB12.d2", "DB12.d1", "DB12.d3",

    "DB1SP.d2", "DB1SP.d1", "DB1SP.d3", "DB1SP.d0",
    NULL,       NULL,       NULL,       NULL,

}; //rank0_2

//---------------------------------------------------------

static const char * dramCardBPortBRank02[ ] =
{
    "DB13", "DB16", "DB14", "DB17", "DB01", "DB15", "DB11", "DB19",
    "DB04", "DB03", "DB05", "DB07", "DB06", "DB09", "DB08", "DB18",
    "DB02", "DB12", "DB1SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardBPortBRank46[] =
{
    "DB33.d1", "DB33.d3", "DB33.d2", "DB33.d0",
    "DB36.d2", "DB36.d3", "DB36.d0", "DB36.d1",

    "DB34.d2", "DB34.d1", "DB34.d0", "DB34.d3",
    "DB37.d2", "DB37.d3", "DB37.d0", "DB37.d1",

    "DB21.d0", "DB21.d2", "DB21.d1", "DB21.d3",
    "DB35.d3", "DB35.d0", "DB35.d1",  "DB35.d2",

    "DB31.d1", "DB31.d3", "DB31.d0", "DB31.d2",
    "DB39.d1", "DB39.d3", "DB39.d0", "DB39.d2",

    "DB24.d2", "DB24.d3", "DB24.d1", "DB24.d0",
    "DB23.d3", "DB23.d1", "DB23.d2", "DB23.d0",

    "DB25.d1", "DB25.d2", "DB25.d3", "DB25.d0",
    "DB27.d0", "DB27.d2", "DB27.d3", "DB27.d1",

    "DB26.d1", "DB26.d2", "DB26.d0", "DB26.d3",
    "DB29.d0", "DB29.d2", "DB29.d1", "DB29.d3",

    "DB28.d0", "DB28.d2", "DB28.d3", "DB28.d1",
    "DB38.d3", "DB38.d2", "DB38.d1", "DB38.d0",

    "DB22.d2", "DB22.d0", "DB22.d3", "DB22.d1",
    "DB32.d1", "DB32.d3","DB32.d0",  "DB32.d2",

    "DB3SP.d3", "DB3SP.d0", "DB3SP.d2", "DB3SP.d1",
    NULL,       NULL,       NULL,       NULL,

}; //rank_4_6

//---------------------------------------------------------

static const char * dramCardBPortBRank46[ ] =
{
    "DB33", "DB36", "DB34", "DB37", "DB21", "DB35", "DB31", "DB39",
    "DB24", "DB23", "DB25", "DB27", "DB26", "DB29", "DB28", "DB38",
    "DB22", "DB32", "DB3SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardBPortCRank02[] =
{
    "DC18.d3", "DC18.d1", "DC18.d0", "DC18.d2",
    "DC09.d2", "DC09.d1", "DC09.d0", "DC09.d3",

    "DC08.d3", "DC08.d1", "DC08.d0", "DC08.d2",
    "DC07.d3", "DC07.d1", "DC07.d2", "DC07.d0",

    "DC16.d0", "DC16.d1", "DC16.d2", "DC16.d3",
    "DC17.d3", "DC17.d2", "DC17.d1", "DC17.d0",

    "DC19.d0", "DC19.d3", "DC19.d2", "DC19.d1",
    "DC01.d3", "DC01.d2", "DC01.d1", "DC01.d0",

    "DC12.d3", "DC12.d1", "DC12.d0", "DC12.d2",
    "DC02.d3", "DC02.d1", "DC02.d0", "DC02.d2",

    "DC13.d2", "DC13.d0", "DC13.d3", "DC13.d1",
    "DC14.d2", "DC14.d0", "DC14.d3", "DC14.d1",

    "DC11.d2", "DC11.d0", "DC11.d1", "DC11.d3",
    "DC03.d3", "DC03.d1", "DC03.d2", "DC03.d0",

    "DC04.d2", "DC04.d1", "DC04.d3", "DC04.d0",
    "DC15.d3", "DC15.d1", "DC15.d0", "DC15.d2",

    "DC05.d3", "DC05.d1", "DC05.d2", "DC05.d0",
    "DC06.d0", "DC06.d1", "DC06.d3", "DC06.d2",

    "DC1SP.d3", "DC1SP.d1", "DC1SP.d0", "DC1SP.d2",
    NULL,       NULL,       NULL,       NULL,

};//rank_0_2

//---------------------------------------------------------

static const char * dramCardBPortCRank02[ ] =
{
    "DC18", "DC09", "DC08", "DC07", "DC16", "DC17", "DC19", "DC01",
    "DC12", "DC02", "DC13", "DC14", "DC11", "DC03", "DC04", "DC15",
    "DC05", "DC06", "DC1SP", NULL,
};

//---------------------------------------------------------

static const char * dramSiteCardBPortCRank46[] =
{
    "DC38.d2", "DC38.d0", "DC38.d1", "DC38.d3",
    "DC29.d3", "DC29.d0", "DC29.d1", "DC29.d2",

    "DC28.d2", "DC28.d0", "DC28.d1", "DC28.d3",
    "DC27.d2", "DC27.d0", "DC27.d3", "DC27.d1",

    "DC36.d1", "DC36.d0", "DC36.d3", "DC36.d2",
    "DC37.d2", "DC37.d3", "DC37.d0", "DC37.d1",

    "DC39.d1", "DC39.d2", "DC39.d3", "DC39.d0",
    "DC21.d2", "DC21.d3", "DC21.d0", "DC21.d1",

    "DC32.d2", "DC32.d0", "DC32.d1", "DC32.d3",
    "DC22.d2", "DC22.d0", "DC22.d1", "DC22.d3",

    "DC33.d3", "DC33.d1", "DC33.d2", "DC33.d0",
    "DC34.d3", "DC34.d1", "DC34.d2", "DC34.d0",

    "DC31.d3", "DC31.d1", "DC31.d0", "DC31.d2",
    "DC23.d2", "DC23.d0", "DC23.d3", "DC23.d1",

    "DC24.d3", "DC24.d0", "DC24.d2", "DC24.d1",
    "DC35.d2", "DC35.d0", "DC35.d1", "DC35.d3",

    "DC25.d2", "DC25.d0", "DC25.d3", "DC25.d1",
    "DC26.d1", "DC26.d0", "DC26.d2", "DC26.d3",

    "DC3SP.d2", "DC3SP.d0", "DC3SP.d1", "DC3SP.d3",
    NULL,       NULL,       NULL,       NULL,
}; //rank_4_6

//---------------------------------------------------------

static const char * dramCardBPortCRank46[ ] =
{
    "DC38", "DC29", "DC28", "DC27", "DC36", "DC37", "DC39", "DC21",
    "DC32", "DC22", "DC33", "DC34", "DC31", "DC23", "DC24", "DC35",
    "DC25", "DC26", "DC3SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardBPortDRank02[] =
{
    "DD13.d0", "DD13.d2", "DD13.d1", "DD13.d3",
    "DD16.d2", "DD16.d0", "DD16.d1", "DD16.d3",

    "DD19.d1", "DD19.d3", "DD19.d0", "DD19.d2",
    "DD15.d1", "DD15.d3", "DD15.d2", "DD15.d0",

    "DD14.d0", "DD14.d3", "DD14.d2", "DD14.d1",
    "DD12.d2", "DD12.d0", "DD12.d1", "DD12.d3",

    "DD11.d2", "DD11.d3", "DD11.d1", "DD11.d0",
    "DD18.d1", "DD18.d3", "DD18.d2", "DD18.d0",

    "DD08.d2", "DD08.d3", "DD08.d1", "DD08.d0",
    "DD03.d3", "DD03.d1", "DD03.d0", "DD03.d2",

    "DD04.d2", "DD04.d0", "DD04.d3", "DD04.d1",
    "DD01.d3", "DD01.d1", "DD01.d2", "DD01.d0",

    "DD05.d3", "DD05.d2", "DD05.d0", "DD05.d1",
    "DD02.d0", "DD02.d1", "DD02.d2", "DD02.d3",

    "DD06.d2", "DD06.d0", "DD06.d1", "DD06.d3",
    "DD07.d2", "DD07.d0", "DD07.d1", "DD07.d3",

    "DD09.d2", "DD09.d0", "DD09.d3", "DD09.d1",
    "DD17.d0", "DD17.d3", "DD17.d1", "DD17.d2",

    "DD1SP.d2", "DD1SP.d0", "DD1SP.d3",  "DD1SP.d1",
    NULL,       NULL,       NULL,        NULL,
};//rank_0_2

//---------------------------------------------------------

static const char * dramCardBPortDRank02[ ] =
{
    "DD13", "DD16", "DD19", "DD15", "DD14", "DD12", "DD11", "DD18",
    "DD08", "DD03", "DD04", "DD01", "DD05", "DD02", "DD06", "DD07",
    "DD09", "DD17", "DD1SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardBPortDRank46[] =
{
    "DD33.d1", "DD33.d3", "DD33.d0", "DD33.d2",
    "DD36.d3", "DD36.d1", "DD36.d0", "DD36.d2",

    "DD39.d0", "DD39.d2", "DD39.d1", "DD39.d3",
    "DD35.d0", "DD35.d2", "DD35.d3", "DD35.d1",

    "DD34.d1", "DD34.d2", "DD34.d3", "DD34.d0",
    "DD32.d3", "DD32.d1", "DD32.d0", "DD32.d2",

    "DD31.d3", "DD31.d2", "DD31.d0", "DD31.d1",
    "DD38.d0", "DD38.d2", "DD38.d3", "DD38.d1",

    "DD28.d3", "DD28.d2", "DD28.d0", "DD28.d1",
    "DD23.d2", "DD23.d0", "DD23.d1", "DD23.d3",

    "DD24.d3", "DD24.d1", "DD24.d2", "DD24.d0",
    "DD21.d2", "DD21.d0", "DD21.d3", "DD21.d1",

    "DD25.d2", "DD25.d3", "DD25.d1", "DD25.d0",
    "DD22.d1", "DD22.d0", "DD22.d3", "DD22.d2",

    "DD26.d3", "DD26.d1", "DD26.d0", "DD26.d2",
    "DD27.d3", "DD27.d1", "DD27.d0", "DD27.d2",

    "DD29.d3", "DD29.d1", "DD29.d2", "DD29.d0",
    "DD37.d1", "DD37.d2", "DD37.d0", "DD37.d3",

    "DD3SP.d3", "DD3SP.d1", "DD3SP.d2", "DD3SP.d0",
    NULL,       NULL,       NULL,       NULL,
}; //rank_4_6

//---------------------------------------------------------

static const char * dramCardBPortDRank46[ ] =
{
    "DD33", "DD36", "DD39", "DD35", "DD34", "DD32", "DD31", "DD38",
    "DD28", "DD23", "DD24", "DD21", "DD25", "DD22", "DD26", "DD27",
    "DD29", "DD37", "DD3SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardDPortARank01[ ] =

{
    "DA07.d3", "DA07.d0", "DA07.d2", "DA07.d1",
    "DA02.d2", "DA02.d0", "DA02.d3", "DA02.d1",

    "DA03.d2", "DA03.d1", "DA03.d3", "DA03.d0",
    "DA04.d3", "DA04.d1", "DA04.d2", "DA04.d0",

    "DA11.d0", "DA11.d2", "DA11.d1", "DA11.d3",
    "DA12.d3", "DA12.d1", "DA12.d0", "DA12.d2",

    "DA17.d0", "DA17.d3", "DA17.d1", "DA17.d2",
    "DA05.d2", "DA05.d1", "DA05.d0", "DA05.d3",

    "DA01.d2", "DA01.d0", "DA01.d1", "DA01.d3",
    "DA18.d1", "DA18.d3", "DA18.d2", "DA18.d0",

    "DA16.d1", "DA16.d0", "DA16.d3", "DA16.d2",
    "DA19.d3", "DA19.d1", "DA19.d0", "DA19.d2",

    "DA09.d2", "DA09.d3", "DA09.d1", "DA09.d0",
    "DA14.d2", "DA14.d0", "DA14.d3", "DA14.d1",

    "DA08.d1", "DA08.d3", "DA08.d2", "DA08.d0",
    "DA15.d0", "DA15.d2", "DA15.d3", "DA15.d1",

    "DA13.d2", "DA13.d1", "DA13.d3", "DA13.d0",
    "DA06.d3", "DA06.d1", "DA06.d0", "DA06.d2",

    "DA1SP.d3", "DA1SP.d2", "DA1SP.d1", "DA1SP.d0",
    NULL,       NULL,       NULL,       NULL,
}; //rank 0_1

//---------------------------------------------------------

static const char * dramCardDPortARank01[ ] =
{
    "DA07", "DA02", "DA03", "DA04", "DA11", "DA12", "DA17", "DA05",
    "DA01", "DA18", "DA16", "DA19", "DA09", "DA14", "DA08", "DA15",
    "DA13", "DA06", "DA1SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardDPortARank45[ ] =
{
    "DA27.d2", "DA27.d1", "DA27.d3", "DA27.d0",
    "DA22.d3", "DA22.d1", "DA22.d2", "DA22.d0",

    "DA23.d3", "DA23.d0", "DA23.d2", "DA23.d1",
    "DA24.d2", "DA24.d0", "DA24.d3", "DA24.d1",

    "DA31.d1", "DA31.d3", "DA31.d0", "DA31.d2",
    "DA32.d2", "DA32.d0", "DA32.d1", "DA32.d3",

    "DA37.d1", "DA37.d2", "DA37.d0", "DA37.d3",
    "DA25.d3", "DA25.d0", "DA25.d1", "DA25.d2",

    "DA21.d3", "DA21.d1", "DA21.d0", "DA21.d2",
    "DA38.d0", "DA38.d2", "DA38.d3", "DA38.d1",

    "DA36.d0", "DA36.d1", "DA36.d2", "DA36.d3",
    "DA39.d2", "DA39.d0", "DA39.d1", "DA39.d3",

    "DA29.d3", "DA29.d2", "DA29.d0", "DA29.d1",
    "DA34.d3", "DA34.d1", "DA34.d2", "DA34.d0",

    "DA28.d0", "DA28.d2", "DA28.d3", "DA28.d1",
    "DA35.d1", "DA35.d3", "DA35.d2", "DA35.d0",

    "DA33.d3", "DA33.d0", "DA33.d2", "DA33.d1",
    "DA26.d2", "DA26.d0", "DA26.d1", "DA26.d3",

    "DA3SP.d2",  "DA3SP.d3", "DA3SP.d0", "DA3SP.d1",
    NULL,        NULL,       NULL,       NULL,

} ;//rank4_5

//---------------------------------------------------------

static const char * dramCardDPortARank45[ ] =
{
    "DA27", "DA22", "DA23", "DA24", "DA31", "DA32", "DA37", "DA25",
    "DA21", "DA38", "DA36", "DA39", "DA29", "DA34", "DA28", "DA35",
    "DA33", "DA26", "DA3SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardDPortBRank01[] =
{
    "DB13.d0", "DB13.d2", "DB13.d3", "DB13.d1",
    "DB16.d3", "DB16.d2", "DB16.d1", "DB16.d0",

    "DB14.d3", "DB14.d0", "DB14.d1", "DB14.d2",
    "DB17.d3", "DB17.d2", "DB17.d1", "DB17.d0",

    "DB01.d1", "DB01.d3", "DB01.d0", "DB01.d2",
    "DB15.d2", "DB15.d1", "DB15.d0", "DB15.d3",

    "DB11.d0", "DB11.d2", "DB11.d1", "DB11.d3",
    "DB19.d0", "DB19.d2", "DB19.d1", "DB19.d3",

    "DB04.d3", "DB04.d2", "DB04.d0", "DB04.d1",
    "DB03.d2", "DB03.d0", "DB03.d3", "DB03.d1",

    "DB05.d0", "DB05.d3", "DB05.d2", "DB05.d1",
    "DB07.d1", "DB07.d3", "DB07.d2", "DB07.d0",

    "DB06.d0", "DB06.d3", "DB06.d1", "DB06.d2",
    "DB09.d1", "DB09.d3", "DB09.d0", "DB09.d2",

    "DB08.d1", "DB08.d3", "DB08.d2", "DB08.d0",
    "DB18.d2", "DB18.d3", "DB18.d0", "DB18.d1",

    "DB02.d3", "DB02.d1", "DB02.d2", "DB02.d0",
    "DB12.d0", "DB12.d2", "DB12.d1", "DB12.d3",

    "DB1SP.d2", "DB1SP.d1", "DB1SP.d3", "DB1SP.d0",
    NULL,       NULL,       NULL,       NULL,

}; //rank0_1

//---------------------------------------------------------

static const char * dramCardDPortBRank01[ ] =
{
    "DB13", "DB16", "DB14", "DB17", "DB01", "DB15", "DB11", "DB19",
    "DB04", "DB03", "DB05", "DB07", "DB06", "DB09", "DB08", "DB18",
    "DB02", "DB12", "DB1SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardDPortBRank45[] =
{
    "DB33.d1", "DB33.d3", "DB33.d2", "DB33.d0",
    "DB36.d2", "DB36.d3", "DB36.d0",  "DB36.d1",

    "DB34.d2", "DB34.d1", "DB34.d0", "DB34.d3",
    "DB37.d2", "DB37.d3", "DB37.d0", "DB37.d1",

    "DB21.d0", "DB21.d2", "DB21.d1", "DB21.d3",
    "DB35.d3", "DB35.d0", "DB35.d1", "DB35.d2",

    "DB31.d1", "DB31.d3", "DB31.d0", "DB31.d2",
    "DB39.d1", "DB39.d3", "DB39.d0", "DB39.d2",

    "DB24.d2", "DB24.d3", "DB24.d1", "DB24.d0",
    "DB23.d3", "DB23.d1", "DB23.d2", "DB23.d0",

    "DB25.d1", "DB25.d2", "DB25.d3", "DB25.d0",
    "DB27.d0", "DB27.d2", "DB27.d3", "DB27.d1",

    "DB26.d1", "DB26.d2", "DB26.d0", "DB26.d3",
    "DB29.d0", "DB29.d2", "DB29.d1", "DB29.d3",

    "DB28.d0", "DB28.d2", "DB28.d3", "DB28.d1",
    "DB38.d3", "DB38.d2", "DB38.d1", "DB38.d0",

    "DB22.d2", "DB22.d0", "DB22.d3", "DB22.d1",
    "DB32.d1", "DB32.d3", "DB32.d0", "DB32.d2",

    "DB3SP.d3", "DB3SP.d0", "DB3SP.d2", "DB3SP.d1",
    NULL,       NULL,       NULL,       NULL,

}; //rank_4_5

//---------------------------------------------------------

static const char * dramCardDPortBRank45[ ] =
{
    "DB33", "DB36", "DB34", "DB37", "DB21", "DB35", "DB31", "DB39",
    "DB24", "DB23", "DB25", "DB27", "DB26", "DB29", "DB28", "DB38",
    "DB22", "DB32", "DB3SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardDPortCRank01[] =
{
    "DC18.d3", "DC18.d1", "DC18.d0", "DC18.d2",
    "DC09.d2", "DC09.d1", "DC09.d0", "DC09.d3",

    "DC08.d3", "DC08.d1", "DC08.d0", "DC08.d2",
    "DC07.d3", "DC07.d1", "DC07.d2", "DC07.d0",

    "DC16.d0", "DC16.d1", "DC16.d2", "DC16.d3",
    "DC17.d3", "DC17.d2", "DC17.d1", "DC17.d0",

    "DC19.d0", "DC19.d3", "DC19.d2", "DC19.d1",
    "DC01.d3", "DC01.d2", "DC01.d1", "DC01.d0",

    "DC12.d3", "DC12.d1", "DC12.d0", "DC12.d2",
    "DC02.d3", "DC02.d1", "DC02.d0", "DC02.d2",

    "DC13.d2", "DC13.d0", "DC13.d3", "DC13.d1",
    "DC14.d2", "DC14.d0", "DC14.d3", "DC14.d1",

    "DC11.d2", "DC11.d0", "DC11.d1", "DC11.d3",
    "DC03.d3", "DC03.d1", "DC03.d2", "DC03.d0",

    "DC04.d2", "DC04.d1", "DC04.d3", "DC04.d0",
    "DC15.d3", "DC15.d1", "DC15.d0", "DC15.d2",

    "DC05.d3", "DC05.d1", "DC05.d2", "DC05.d0",
    "DC06.d0", "DC06.d1", "DC06.d3", "DC06.d2",

    "DC1SP.d3", "DC1SP.d1", "DC1SP.d0", "DC1SP.d2",
    NULL,       NULL,       NULL,       NULL,

};//rank_0_1

//---------------------------------------------------------

static const char * dramCardDPortCRank01[ ] =
{
    "DC18", "DC09", "DC08", "DC07", "DC16", "DC17", "DC19", "DC01",
    "DC12", "DC02", "DC13", "DC14", "DC11", "DC03", "DC04", "DC15",
    "DC05", "DC06", "DC1SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardDPortCRank45[] =
{
    "DC38.d2", "DC38.d0", "DC38.d1", "DC38.d3",
    "DC29.d3", "DC29.d0", "DC29.d1", "DC29.d2",

    "DC28.d2", "DC28.d0", "DC28.d1", "DC28.d3",
    "DC27.d2", "DC27.d0", "DC27.d3", "DC27.d1",

    "DC36.d1", "DC36.d0", "DC36.d3", "DC36.d2",
    "DC37.d2", "DC37.d3", "DC37.d0", "DC37.d1",

    "DC39.d1", "DC39.d2", "DC39.d3", "DC39.d0",
    "DC21.d2", "DC21.d3", "DC21.d0", "DC21.d1",

    "DC32.d2", "DC32.d0", "DC32.d1", "DC32.d3",
    "DC22.d2", "DC22.d0", "DC22.d1", "DC22.d3",

    "DC33.d3", "DC33.d1", "DC33.d2", "DC33.d0",
    "DC34.d3", "DC34.d1", "DC34.d2", "DC34.d0",

    "DC31.d3", "DC31.d1", "DC31.d0", "DC31.d2",
    "DC23.d2", "DC23.d0", "DC23.d3", "DC23.d1",

    "DC24.d3", "DC24.d0", "DC24.d2", "DC24.d1",
    "DC35.d2", "DC35.d0", "DC35.d1", "DC35.d3",

    "DC25.d2", "DC25.d0", "DC25.d3", "DC25.d1",
    "DC26.d1", "DC26.d0", "DC26.d2", "DC26.d3",

    "DC3SP.d2", "DC3SP.d0", "DC3SP.d1", "DC3SP.d3",
    NULL,       NULL,       NULL,       NULL,
}; //rank_4_5

//---------------------------------------------------------

static const char * dramCardDPortCRank45[ ] =
{
    "DC38", "DC29", "DC28", "DC27", "DC36", "DC37", "DC39", "DC21",
    "DC32", "DC22", "DC33", "DC34", "DC31", "DC23", "DC24", "DC35",
    "DC25", "DC26", "DC3SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardDPortDRank01[] =
{
    "DD13.d0", "DD13.d2", "DD13.d1", "DD13.d3",
    "DD16.d2", "DD16.d0", "DD16.d1", "DD16.d3",

    "DD19.d1", "DD19.d3", "DD19.d0", "DD19.d2",
    "DD15.d1", "DD15.d3", "DD15.d2", "DD15.d0",

    "DD14.d0", "DD14.d3", "DD14.d2", "DD14.d1",
    "DD12.d2", "DD12.d0", "DD12.d1", "DD12.d3",

    "DD11.d2", "DD11.d3", "DD11.d1", "DD11.d0",
    "DD18.d2", "DD18.d0", "DD18.d1", "DD18.d3",

    "DD08.d2", "DD08.d3", "DD08.d1", "DD08.d0",
    "DD03.d3", "DD03.d1", "DD03.d0", "DD03.d2",

    "DD05.d2", "DD05.d0", "DD05.d3", "DD05.d1",
    "DD01.d3", "DD01.d1", "DD01.d2", "DD01.d0",

    "DD04.d3", "DD04.d2", "DD04.d0", "DD04.d1",
    "DD02.d0", "DD02.d1", "DD02.d2", "DD02.d3",

    "DD06.d2", "DD06.d0", "DD06.d1", "DD06.d3",
    "DD07.d2", "DD07.d0","DD07.d1", "DD07.d3",

    "DD09.d2", "DD09.d0", "DD09.d3", "DD09.d1",
    "DD17.d0", "DD17.d3", "DD17.d1", "DD17.d2",

    "DD1SP.d2", "DD1SP.d0", "DD1SP.d3", "DD1SP.d1",
    NULL,       NULL,       NULL,       NULL,
};//rank_0_1

//---------------------------------------------------------

static const char * dramCardDPortDRank01[ ] =
{
    "DD13", "DD16", "DD19", "DD15", "DD14", "DD12", "DD11", "DD18",
    "DD08", "DD03", "DD05", "DD01", "DD04", "DD02", "DD06", "DD07",
    "DD09", "DD17", "DD1SP", NULL
};

//---------------------------------------------------------

static const char * dramSiteCardDPortDRank45[] =
{
    "DD33.d1", "DD33.d3", "DD33.d0",  "DD33.d2",
    "DD36.d3", "DD36.d1", "DD36.d0",  "DD36.d2",

    "DD39.d0", "DD39.d2", "DD39.d1", "DD39.d3",
    "DD35.d0", "DD35.d2", "DD35.d3", "DD35.d1",

    "DD34.d1", "DD34.d2", "DD34.d3", "DD34.d0",
    "DD32.d3", "DD32.d1", "DD32.d0", "DD32.d2",

    "DD31.d3", "DD31.d2", "DD31.d0", "DD31.d1",
    "DD38.d3", "DD38.d1", "DD38.d0", "DD38.d2",

    "DD28.d3", "DD28.d2", "DD28.d0", "DD28.d1",
    "DD23.d2", "DD23.d0", "DD23.d1", "DD23.d3",

    "DD25.d3", "DD25.d1", "DD25.d2", "DD25.d0",
    "DD21.d2", "DD21.d0", "DD21.d3", "DD21.d1",

    "DD24.d2", "DD24.d3", "DD24.d1", "DD24.d0",
    "DD22.d1", "DD22.d0", "DD22.d3", "DD22.d2",

    "DD26.d3", "DD26.d1", "DD26.d0", "DD26.d2",
    "DD27.d3", "DD27.d1", "DD27.d0", "DD27.d2",

    "DD29.d3", "DD29.d1", "DD29.d2", "DD29.d0",
    "DD37.d1", "DD37.d2", "DD37.d0", "DD37.d3",

    "DD3SP.d3", "DD3SP.d1", "DD3SP.d2", "DD3SP.d0",
    NULL,       NULL,       NULL,       NULL,
}; //rank_4_5

//---------------------------------------------------------

static const char * dramCardDPortDRank45[ ] =
{
    "DD33", "DD36", "DD39", "DD35", "DD34", "DD32", "DD31", "DD38",
    "DD28", "DD23", "DD25", "DD21", "DD24", "DD22", "DD26", "DD27",
    "DD29", "DD37", "DD3SP", NULL
}; //rank_4_5

//---------------------------------------------------------

static const char ** dramSiteLocMap[] =
{
    dramSiteCardAPortARank02,
    dramSiteCardAPortARank46,
    dramSiteCardAPortBRank02,
    dramSiteCardAPortBRank46,
    dramSiteCardAPortCRank02,
    dramSiteCardAPortCRank46,
    dramSiteCardAPortDRank02,
    dramSiteCardAPortDRank46,

    dramSiteCardBPortARank02,
    dramSiteCardBPortARank46,
    dramSiteCardBPortBRank02,
    dramSiteCardBPortBRank46,
    dramSiteCardBPortCRank02,
    dramSiteCardBPortCRank46,
    dramSiteCardBPortDRank02,
    dramSiteCardBPortDRank46,

    dramSiteCardDPortARank01,
    dramSiteCardDPortARank45,
    dramSiteCardDPortBRank01,
    dramSiteCardDPortBRank45,
    dramSiteCardDPortCRank01,
    dramSiteCardDPortCRank45,
    dramSiteCardDPortDRank01,
    dramSiteCardDPortDRank45,

};

//---------------------------------------------------------

static const char ** dramLocMap[] =
{
    dramCardAPortARank02,
    dramCardAPortARank46,
    dramCardAPortBRank02,
    dramCardAPortBRank46,
    dramCardAPortCRank02,
    dramCardAPortCRank46,
    dramCardAPortDRank02,
    dramCardAPortDRank46,

    dramCardBPortARank02,
    dramCardBPortARank46,
    dramCardBPortBRank02,
    dramCardBPortBRank46,
    dramCardBPortCRank02,
    dramCardBPortCRank46,
    dramCardBPortDRank02,
    dramCardBPortDRank46,

    dramCardDPortARank01,
    dramCardDPortARank45,
    dramCardDPortBRank01,
    dramCardDPortBRank45,
    dramCardDPortCRank01,
    dramCardDPortCRank45,
    dramCardDPortDRank01,
    dramCardDPortDRank45,

};

//---------------------------------------------------------

// This table summarizes two things
// 1. all the valid ranks for various  Centaur card types.
// 2. There is an index of dramSiteLocMap/dramLocMap from which a dram Site
//    location table for a given Card Type and given Port begin. Let us call
//    this BASE LOCATION. A lookup in to cardRankMap using rank info, gives us
//    an offset to BASE LOCATION at which 'exact dram site table' is located.
//    qualification of 'exact dram site table' is :
//    dram site table for a given card type, given port type and given rank
//    number.

static int32_t cardRankMap[3][8] =
{
    //valid rank are 0-2 and 4-6
    { 0, -1,  0, -1, 1, -1,  1, -1 },   // Raw Card A

    //valid rank are 0-2 and 4-6
    { 0, -1,  0, -1, 1, -1,  1, -1 },   // Raw Card B

    //valid rank are 0-1 and 4-5
    { 0,  0, -1, -1, 1,  1, -1, -1 },   // Raw Card D
};

//------------------------------------------------------------------------------
// Helper functions
//------------------------------------------------------------------------------

// Displays symbol value. If symbol is not valid, will display '--' in output.
void getDramRepairSymbolStr( uint8_t i_value, char * o_str, uint32_t i_strSize )
{
    if ( SYMBOLS_PER_RANK <= i_value )
    {
        snprintf( o_str, i_strSize, "--" );
    }
    else
    {
        snprintf( o_str, i_strSize, "%2u", i_value );
    }
}

// Gets the string representation for a single bad DQ bitmap entry.
void getBadDqBitmapEntry( uint8_t * i_buffer, char * o_str )
{
    UtilMem membuf( i_buffer, DQ_BITMAP::ENTRY_SIZE );

    uint8_t rank; membuf >> rank;
    snprintf( o_str, DATA_SIZE, "R:%1d", rank );

    for ( int32_t p = 0; p < PORT_SLCT_PER_MBA; p++ )
    {
        char temp[DATA_SIZE];

        strcat( o_str, "  " );

        for ( int32_t b = 0; b < DQ_BITMAP::BITMAP_SIZE; b++ )
        {
            uint8_t byte; membuf >> byte;
            snprintf( temp, DATA_SIZE, "%02x", byte );
            strcat( o_str, temp );
        }
    }
}

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

uint8_t getCenDqFromSymbol( uint8_t i_symbol )
{
    uint8_t cenDq = DQS_PER_DIMM;

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        if ( 8 > i_symbol )
            cenDq = ( ((3 - (i_symbol % 4)) * 2) + 64 );
        else
            cenDq = ( (31 - (((i_symbol - 8) % 32))) * 2 );
    }

    return cenDq;
}

//------------------------------------------------------------------------------

uint8_t getPortFromSymbol( uint8_t i_symbol )
{
    uint8_t portSlct = PORT_SLCT_PER_MBA;

    if ( SYMBOLS_PER_RANK > i_symbol )
    {
        portSlct = ( ((i_symbol <= 3) || ((8 <= i_symbol) && (i_symbol <= 39)))
                     ? 1 : 0 );
    }

    return portSlct;
}

//------------------------------------------------------------------------------

int32_t resolveCenCard( MemoryMruData::MemMruMeld i_memMruData,
                     uint32_t & o_dramSiteTble, uint32_t & io_dimmDq,
                     uint32_t & o_dramIndex )
{
    int32_t rankOffset = 0;
    uint8_t bitsPerDram = 4; // since both Card B and D are x4
    int32_t o_rc = SUCCESS;
    o_dramSiteTble = 0;
    o_dramIndex = 0;

    do
    {
        switch( i_memMruData.s.wiringType )
        {
            case CEN_TYPE_A:    bitsPerDram = 8; break;
            case CEN_TYPE_B:    //both Card B and Card D are x4 DIMM
            case CEN_TYPE_D:    break;
            default:            o_rc = FAIL; break;
        }

        if( o_rc )
            break;
        //pick the valid rank offset from table
        rankOffset =
            cardRankMap[ i_memMruData.s.wiringType ][ i_memMruData.s.mrank ];

        if ( 0 > rankOffset )
        {
            // it is a case of unspported rank
            o_rc = FAIL;
            break;
        }

        // There are 4 step in looking up the DRAM Site location
        //  1. Find out the card associated with the symbol.
        //  2. Find out MBA associated with Symbol.
        //  3. Once MBA is known, find the MBA Port associated with symbol.
        //  4. Find the rank associated with the symbol.

        //  To reach the right table this is what we need to do :
        //  Relevant dramSite Table =
        //  dramSiteLocMap[Card Index + MBA Index + Port Index + Rank Index ]
        //  dram site location = Relevant dramSite Table[ DQ ]

        o_dramSiteTble = 8 * i_memMruData.s.wiringType;
        o_dramSiteTble += 4 * i_memMruData.s.mbaPos;
        o_dramSiteTble += 2 * getPortFromSymbol( i_memMruData.s.symbol );
        o_dramSiteTble += rankOffset;

        if( i_memMruData.s.dramSpared )
        {
            // mapping DQ to spare DRAM area.
            io_dimmDq = SYMBOLS_PER_RANK +  ( io_dimmDq % 8 ) ;
        }

        // getting DRAM info
        o_dramIndex = io_dimmDq / bitsPerDram;

    }while(0);

    return o_rc;
}

//------------------------------------------------------------------------------

int32_t getDramSite( MemoryMruData::MemMruMeld  i_memMruData, char *o_data )
{
    int32_t o_rc = SUCCESS;
    uint32_t tableOffset = 0;
    uint32_t dramIndex = 0;
    uint32_t dimmDq = 0;

    do
    {

        if( i_memMruData.s.eccSpared  )
        {
            // Symbol adjustment for ECC spare.
            // ECC spare is on symbol 0 and 1. So in case of ECC spare, we need
            // to find out which of the two ECC symbol was used to replace the
            // failing symbol. Since, we have just two symbols meant for ECC
            // spare, if failing symbol is even, symbol 0 is used else symbol 1
            // is used. This change of symbol in MemoryMruData is purely to
            // simplify lookup of correct dramSite location in case of ECC
            // spare.
            i_memMruData.s.symbol = i_memMruData.s.symbol % 2;
        }

        dimmDq = getCenDqFromSymbol( i_memMruData.s.symbol );
        o_rc = resolveCenCard( i_memMruData, tableOffset, dimmDq, dramIndex );

        if( SUCCESS != o_rc )   // an invalid card or unknown card
            break;

        if( ( NULL == (dramSiteLocMap[tableOffset])[dimmDq] )||
            ( NULL == (dramSiteLocMap[tableOffset])[dimmDq + 1] ) )

        {
            // Lookup shall fail. No point in moving further.
            o_rc = FAIL;
            break;
        }

        strcpy( o_data, "DRAM Site: " );

        switch( i_memMruData.s.pins )
        {
            case EVEN_SYMBOL_DQ:
                strcat( o_data, (dramSiteLocMap[tableOffset])[dimmDq] );
                break;

            case ODD_SYMBOL_DQ:
                strcat( o_data, (dramSiteLocMap[tableOffset])[dimmDq+1] );
                break;

            case BOTH_SYMBOL_DQS:
                strcat( o_data, (dramSiteLocMap[tableOffset])[dimmDq] );
                strcat( o_data, ", " );
                strcat( o_data, (dramSiteLocMap[tableOffset])[dimmDq+1] );
                break;

            case NO_SYMBOL_DQS:
                // blaming relevant dram since we aren't sure of DQ
                strcat( o_data, (dramLocMap[tableOffset])[dramIndex] );
                break;

            default:
                o_rc = FAIL; break;
        }

        if( SUCCESS != o_rc )   // an invalid failed pin info
            break;          // just in case we add something after this later

    }while(0);

    return o_rc;
}
//------------------------------------------------------------------------------

bool parseMemMruData( ErrlUsrParser & i_parser, uint32_t i_memMru )
{
    bool o_rc = true;

    MemoryMruData::MemMruMeld mm; mm.u = i_memMru;

    uint8_t nodePos  =  mm.s.nodePos;
    uint8_t cenPos   = (mm.s.procPos << 3) | mm.s.cenPos;
    uint8_t mbaPos   = mm.s.mbaPos;

    char tmp[HEADER_SIZE] = { '\0' };
    if ( 1 == mm.s.srankValid )
        snprintf( tmp, HEADER_SIZE, "S%d", mm.s.srank );

    char header[HEADER_SIZE];
    snprintf( header, HEADER_SIZE, "  mba(n%dp%dc%d)%s Rank:M%d%s",
              nodePos, cenPos, mbaPos, (cenPos < 10) ? " " : "",
              mm.s.mrank, tmp );

    char data[DATA_SIZE] = { '\0' };

    switch ( mm.s.symbol )
    {
        case MemoryMruData::CALLOUT_RANK:
            snprintf( data, DATA_SIZE, "Special: CALLOUT_RANK" );
            break;
        case MemoryMruData::CALLOUT_RANK_AND_MBA:
            snprintf( data, DATA_SIZE, "Special: CALLOUT_RANK_AND_MBA" );
            break;
        case MemoryMruData::CALLOUT_ALL_MEM:
            snprintf( data, DATA_SIZE, "Special: CALLOUT_ALL_MEM" );
            break;
        default:

            if( SYMBOLS_PER_RANK >  mm.s.symbol )
            {
                if( SUCCESS != getDramSite( mm, data ) )
                {
                    snprintf( data, DATA_SIZE, "Symbol: %d Pins: %d Spared: %s",
                              mm.s.symbol, mm.s.pins,
                              (1 == mm.s.dramSpared) ? "true" : "false" );
                }
            }
    }

    // Ouptut should look like:
    // |   mba(n0p0c0)  Rank:M7   : Special: CALLOUT_RANK                    |
    // |   mba(n7p63c1) Rank:M0S7 : Symbol: 71 Pins: 3 Spared: false         |
    // |   mba(n0p4c0)  Rank:M0S0 : DRAM Site: DA03.d1                       |

    i_parser.PrintString( header, data );

    return o_rc;
}

//------------------------------------------------------------------------------

bool parseMemUeTable( uint8_t  * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser )
{
    using namespace UE_TABLE;

    bool rc = true;

    if ( NULL == i_buffer ) return false; // Something failed in parser.

    const uint32_t entries = i_buflen / ENTRY_SIZE;

    i_parser.PrintNumber( " MEM_UE_TABLE", "%d", entries );

    const char * hh = "   Count Type";
    const char * hd = "Rank Bank Row     Column";
    i_parser.PrintString( hh, hd );
    hh = "   ----- -------------";
    hd = "---- ---- ------- ------";
    i_parser.PrintString( hh, hd );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        uint32_t idx = i * ENTRY_SIZE;

        uint32_t count = i_buffer[idx  ];                           //  8-bit
        uint32_t type  = i_buffer[idx+1] >> 4;                      //  4-bit

        uint32_t mrnk  = (i_buffer[idx+2] >> 5) & 0x7;              //  3-bit
        uint32_t srnk  = (i_buffer[idx+2] >> 2) & 0x7;              //  3-bit
        uint32_t svld  = (i_buffer[idx+2] >> 1) & 0x1;              //  1-bit

        uint32_t row0    = i_buffer[idx+2] & 0x1;
        uint32_t row1_8  = i_buffer[idx+3];
        uint32_t row9_16 = i_buffer[idx+4];
        uint32_t row     = (row0 << 16) | (row1_8 << 8) | row9_16;  // 17-bit

        uint32_t bnk   = i_buffer[idx+5] >> 4;                      //  4-bit

        uint32_t col0_3  = i_buffer[idx+5] & 0xf;
        uint32_t col4_11 = i_buffer[idx+6];
        uint32_t col     = (col0_3 << 8) | col4_11;                 // 12-bit

        const char * type_str = "UNKNOWN      "; // 13 characters
        switch ( type )
        {
            case SCRUB_MPE: type_str = "SCRUB_MPE    "; break;
            case FETCH_MPE: type_str = "FETCH_MPE    "; break;
            case SCRUB_UE:  type_str = "SCRUB_UE     "; break;
            case FETCH_UE:  type_str = "FETCH_UE     "; break;
        }

        char rank_str[DATA_SIZE]; // 4 characters
        if ( 1 == svld )
        {
            snprintf( rank_str, DATA_SIZE, "m%ds%d", mrnk, srnk );
        }
        else
        {
            snprintf( rank_str, DATA_SIZE, "m%d  ", mrnk );
        }

        char header[HEADER_SIZE] = { '\0' };
        snprintf( header, HEADER_SIZE, "    0x%02x %s", count, type_str );

        char data[DATA_SIZE]     = { '\0' };
        snprintf( data, DATA_SIZE, "%s  0x%01x 0x%05x  0x%03x",
                  rank_str, bnk, row, col );

        i_parser.PrintString( header, data );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseMemCeTable( uint8_t  * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser )
{
    using namespace CE_TABLE;

    bool rc = true;

    if ( NULL == i_buffer ) return false; // Something failed in parser.

    const uint32_t entries = i_buflen / ENTRY_SIZE;

    i_parser.PrintNumber( " MEM_CE_TABLE", "%d", entries );

    const char * hh = "  A H Count Type";
    const char * hd = "Rank Bank Row     Column DRAM Pins";
    i_parser.PrintString( hh, hd );
    hh = "  - - ----- -------------";
    hd = "---- ---- ------- ------ ---- ----";
    i_parser.PrintString( hh, hd );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        uint32_t idx = i * ENTRY_SIZE;

        uint32_t count = i_buffer[idx  ];                           //  8-bit
        uint32_t type  = i_buffer[idx+1] >> 4;                      //  4-bit

        uint8_t  isHard = (i_buffer[idx+2] >> 7) & 0x1;             //  1-bit
        uint8_t  active = (i_buffer[idx+2] >> 6) & 0x1;             //  1-bit
        uint8_t  dram   =  i_buffer[idx+2]       & 0x3f;            //  6-bit

        uint32_t dramPins = i_buffer[idx+3];                        //  8-bit

        uint32_t mrnk  = (i_buffer[idx+4] >> 5) & 0x7;              //  3-bit
        uint32_t srnk  = (i_buffer[idx+4] >> 2) & 0x7;              //  3-bit
        uint32_t svld  = (i_buffer[idx+4] >> 1) & 0x1;              //  1-bit

        uint32_t row0    = i_buffer[idx+4] & 0x1;
        uint32_t row1_8  = i_buffer[idx+5];
        uint32_t row9_16 = i_buffer[idx+6];
        uint32_t row     = (row0 << 16) | (row1_8 << 8) | row9_16;  // 17-bit

        uint32_t bnk   = i_buffer[idx+7] >> 4;                      //  4-bit

        uint32_t col0_3  = i_buffer[idx+7] & 0xf;
        uint32_t col4_11 = i_buffer[idx+8];
        uint32_t col     = (col0_3 << 8) | col4_11;                 // 12-bit

        char active_char = ( 1 == active ) ? 'Y':'N';
        char isHard_char = ( 1 == isHard ) ? 'Y':'N';

        const char * type_str = "UNKNOWN      "; // 13 characters
        switch ( type )
        {
            case CEN_TYPE_A: type_str = "RAW_CARD_A  "; break;
            case CEN_TYPE_B: type_str = "RAW_CARD_B  "; break;
            case CEN_TYPE_D: type_str = "RAW_CARD_D  "; break;

            default: ;
        }

        char rank_str[DATA_SIZE]; // 4 characters
        if ( 1 == svld )
        {
            snprintf( rank_str, DATA_SIZE, "m%ds%d", mrnk, srnk );
        }
        else
        {
            snprintf( rank_str, DATA_SIZE, "m%d  ", mrnk );
        }

        char header[HEADER_SIZE] = { '\0' };
        snprintf( header, HEADER_SIZE, "  %c %c  0x%02x %s", active_char,
                  isHard_char, count, type_str );

        char data[DATA_SIZE]     = { '\0' };
        snprintf( data, DATA_SIZE, "%s  0x%01x 0x%05x  0x%03x   %2d 0x%02x",
                  rank_str, bnk, row, col, dram, dramPins );

        i_parser.PrintString( header, data );
    }

    return rc;
}

//------------------------------------------------------------------------------

void getRceEntry( uint8_t * i_buffer , char * o_entry )
{

    uint32_t mrnk  = (i_buffer[0] >> 5) & 0x7;              //  3-bit
    uint32_t srnk  = (i_buffer[0] >> 2) & 0x7;              //  3-bit
    uint32_t svld  = (i_buffer[0] >> 1) & 0x1;              //  1-bit
    uint32_t count = i_buffer[1];                         //  8-bit

    // This Function should return string in this format
    // "Rank Count ".
    if ( 1 == svld )
    {
        snprintf( o_entry, DATA_SIZE, "m%ds%d", mrnk, srnk );
    }
    else
    {
        snprintf( o_entry, DATA_SIZE, "m%d  ", mrnk );
    }

    // Reserve some extra space for format
    // 5 chars for "Count", 1 blank before count , one after count
    char countStr[8] = { '\0' };
    snprintf( countStr, 8, "   %d    ", count );

    strcat( o_entry, countStr );
}

//------------------------------------------------------------------------------

bool parseMemRceTable( uint8_t  * i_buffer, uint32_t i_buflen,
                      ErrlUsrParser & i_parser )
{
    using namespace RCE_TABLE;

    bool rc = true;

    // Check if something failed in parser.
    if ( ( NULL == i_buffer ) || ( 0 == i_buflen) ) return false;

    const uint32_t entries = i_buffer[0];
    uint32_t idx = 1;
    i_parser.PrintNumber( " MEM_RCE_TABLE", "%d", entries );

    // To conserve space in error log output, have two entries in header
    // and 4 in Description.
    const uint32_t entryNumHdr = 2;
    const uint32_t entryNumDesc = 4;
    const char * hh = "  Rank Count Rank Count";
    const char * hd = "Rank Count Rank Count Rank Count Rank Count";

    i_parser.PrintString( hh, hd );
    hh = "  ---- ----- ---- -----";
    hd = "---- ----- ---- ----- ---- ----- ---- -----";
    i_parser.PrintString( hh, hd );

    uint32_t count = 0;

    while( count < entries )
    {
        // Get Header
        char header[HEADER_SIZE] = { '\0' };
        strcat( header, "  ");
        for( uint32_t i = 0;  i < entryNumHdr &&  count < entries;
                                i++, count++, idx += ENTRY_SIZE )
        {
            char data[12]     = { '\0' };
            getRceEntry( i_buffer+idx, data );
            strcat( header, data );
        }

        // Get Description
        char desc[DATA_SIZE] = { '\0' };
        for( uint32_t i = 0; i < entryNumDesc && count < entries;
                                i++, count++, idx += ENTRY_SIZE )
        {
            if( count >= entries ) break;

            char data[12]     = { '\0' };
            getRceEntry( i_buffer+idx, data );
            strcat( desc, data );
        }
        i_parser.PrintString( header, desc );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseDramRepairsData( uint8_t  * i_buffer, uint32_t i_buflen,
                           ErrlUsrParser & i_parser )
{
    bool rc = true;

    if ( NULL != i_buffer )
    {
        UtilMem l_membuf( i_buffer, i_buflen );

        DramRepairMbaData mbaData;
        l_membuf >> mbaData;

        uint8_t rankCount = mbaData.header.rankCount;

        i_parser.PrintNumber( " DRAM_REPAIRS_DATA", "%d", rankCount );

        // Iterate over all ranks
        for ( uint8_t rankIdx = 0; rankIdx < rankCount; rankIdx++ )
        {
            char data[64];
            char temp[64];
            char symbolStr[10];

            DramRepairRankData rankEntry = mbaData.rankDataList[rankIdx];
            snprintf(temp, 64, "Rank: %d", rankEntry.rank);
            snprintf(data, 64, temp);

            getDramRepairSymbolStr(rankEntry.chipMark, symbolStr, 10);
            snprintf(temp, 64, "%s CM: %s", data, symbolStr);
            snprintf(data, 64, temp);

            getDramRepairSymbolStr(rankEntry.symbolMark, symbolStr, 10);
            snprintf(temp, 64, "%s SM: %s", data, symbolStr);
            snprintf(data, 64, temp);

            // Display DRAM spare information if spare DRAM is supported.
            if ( mbaData.header.isSpareDram )
            {
                getDramRepairSymbolStr(rankEntry.port0Spare, symbolStr, 10);
                snprintf(temp, 64, "%s Sp0: %s", data, symbolStr);
                snprintf(data, 64, temp);

                getDramRepairSymbolStr(rankEntry.port1Spare, symbolStr, 10);
                snprintf(temp, 64, "%s Sp1: %s", data, symbolStr);
                snprintf(data, 64, temp);
            }

            // Display ECC spare information for X4 DRAMs
            if ( mbaData.header.isX4Dram )
            {
                getDramRepairSymbolStr( rankEntry.eccSpare, symbolStr, 10 );
                snprintf(temp, 64, "%s EccSp: %s", data, symbolStr);
                snprintf(data, 64, temp);
            }

            i_parser.PrintString( "", data );
        }
    }
    else
    {
        rc = false;
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseDramRepairsVpd( uint8_t * i_buffer, uint32_t i_buflen,
                          ErrlUsrParser & i_parser )
{
    bool rc = true;

    if ( NULL == i_buffer ) return false; // Something failed in parser.

    const uint32_t entries = i_buflen / DQ_BITMAP::ENTRY_SIZE;

    i_parser.PrintNumber( " DRAM_REPAIRS_VPD", "%d", entries );

    for ( uint32_t i = 0; i < entries; i++ )
    {
        char data[DATA_SIZE];
        getBadDqBitmapEntry( &i_buffer[i*DQ_BITMAP::ENTRY_SIZE], data );

        i_parser.PrintString( "", data );
    }

    return rc;
}

//------------------------------------------------------------------------------

bool parseBadDqBitmap( uint8_t  * i_buffer, uint32_t i_buflen,
                       ErrlUsrParser & i_parser )
{
    bool rc = true;

    if ( NULL == i_buffer ) return false; // Something failed in parser.

    if ( DQ_BITMAP::ENTRY_SIZE > i_buflen ) // Data is expected to be one entry.
    {
        i_parser.PrintString( " BAD_DQ_BITMAP", "" );
        i_parser.PrintHexDump(i_buffer, i_buflen);
    }
    else
    {
        char data[DATA_SIZE];
        getBadDqBitmapEntry( i_buffer, data );

        i_parser.PrintString( " BAD_DQ_BITMAP", data );
    }

    return rc;
}

//------------------------------------------------------------------------------

} // namespace FSP/HOSTBBOT
} // end namespace PRDF

