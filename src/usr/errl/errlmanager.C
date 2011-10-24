//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/errl/errlmanager.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 *  @file errlmanager.C
 *
 *  @brief Implementation of ErrlManager class
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <errl/errlmanager.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <stdlib.h>
#include <string.h>





namespace ERRORLOG
{

extern trace_desc_t* g_trac_errl;



// Scaffolding
// Store error logs in this memory buffer in L3 RAM.
char g_ErrlStorage[ ERRL_STORAGE_SIZE ];


/**
* @brief
* In storage, the flattened error logs are interspersed with "markers."
* CBMARKER is the count of bytes in one marker.
* CB2MARKERS is the count of bytes in two markers.
*/
#define CBMARKER (sizeof(marker_t))
#define CB2MARKERS (2*sizeof(marker_t))

/**
* @brief OFFSET2MARKER()
* Convert an offset within the buffer to a marker_t pointer.
*/
#define OFFSET2MARKER(off) (reinterpret_cast<marker_t*>(&g_ErrlStorage[off]))

/**
* @brief POINTER2OFFSET()
* Convert a marker_t pointer to its offset within the buffer.
*/
#define POINTER2OFFSET(p) ((reinterpret_cast<char*>(p))-(g_ErrlStorage))



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::ErrlManager()
{
    // PNOR will be reinitialized every time hostboot runs
    iv_currLogId = 0;

    mutex_init(&iv_mutex);

    // Scaffolding.
    // For now, put error logs in a 64KB buffer in L3 RAM
    // This buffer has a header (storage_header_t) followed by
    // storage.
    iv_pStorage = reinterpret_cast<storage_header_t*>(g_ErrlStorage);

    // g_ErrlStorage is in BSS segment, therefore already zeroed.
    // memset( iv_pStorage, 0, sizeof(storage_header_t));

    // Storage size is placed here for benefit of downstream parsers.
    iv_pStorage->cbStorage    = sizeof( g_ErrlStorage );

    // Offsets are zero-based at &g_ErrlStorage[0],
    // so the first usable offset is just past the header.
    iv_pStorage->offsetMarker = sizeof(storage_header_t);
    iv_pStorage->offsetStart  = sizeof(storage_header_t);

    // g_ErrlStorage is in BSS segment, therefore already zeroed.
    // Thus, the prime marker in storage is already zero.
    // marker_t* l_pMarker = OFFSET2MARKER( iv_pStorage->offsetStart );
    // l_pMarker->offsetNext = 0;
    // l_pMarker->length     = 0;

}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
ErrlManager::~ErrlManager()
{
}

///////////////////////////////////////////////////////////////////////////////
//
//  Save and delete this error log. On output, io_err will be nul.
//
void ErrlManager::commitErrLog(errlHndl_t& io_err, compId_t i_committerComp )
{
    do
    {
        if (io_err == NULL)
        {
            // put out warning trace
            TRACFCOMP(g_trac_errl, "commitErrLog() - NULL pointer");
            break;
        }


        // lock sem
        mutex_lock(&iv_mutex);

        // Ask the ErrlEntry to assign commit component, commit time, etc.
        io_err->commit( i_committerComp  );

        // Get flattened count of bytes.
        uint32_t l_cbActualFlat = io_err->flattenedSize();

        // Round this copy up to next nearest word (32-bit) boundary.
        uint32_t l_cbflat = ((l_cbActualFlat+3) & ~3);

        // Save/flatten the error log to the storage buffer.
        uint32_t l_extent = iv_pStorage->offsetMarker + CB2MARKERS + l_cbflat;

        if( l_extent < ERRL_STORAGE_SIZE)
        {
            // New data and its surrounding markers can fit between
            // the insertion point and the end of the storage buffer.
            // Flatten the data at the insertion point.
            marker_t * l_pMarker = OFFSET2MARKER( iv_pStorage->offsetMarker );
            io_err->flatten( l_pMarker+1, l_cbflat );
            l_pMarker->length = l_cbActualFlat;

            // Assign offset to next marker to this marker.
            l_pMarker->offsetNext=iv_pStorage->offsetMarker+CBMARKER+l_cbflat;

            // Save new insertion point in header.
            iv_pStorage->offsetMarker = l_pMarker->offsetNext;

            // Initialize the marker at the new insertion point.
            marker_t * pNew = OFFSET2MARKER( iv_pStorage->offsetMarker );
            pNew->offsetNext = 0;
            pNew->length = 0;
        }


        // Count of error logs called to commit, regardless if there was
        // room to commit them or not.
        iv_pStorage->cInserted++;


        // unlock sem
        mutex_unlock(&iv_mutex);

        delete io_err;
        io_err = NULL;
    }
    while( 0 );
    return;
}



///////////////////////////////////////////////////////////////////////////////
// Atomically increment log id and return it.
uint32_t ErrlManager::getUniqueErrId()
{
    return (__sync_add_and_fetch(&iv_currLogId, 1));
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Global function (not a method on an object) to commit the error log.
void errlCommit(errlHndl_t& io_err, compId_t i_committerComp )
{
    ERRORLOG::theErrlManager::instance().commitErrLog(io_err, i_committerComp );
    return;
}

} // End namespace
