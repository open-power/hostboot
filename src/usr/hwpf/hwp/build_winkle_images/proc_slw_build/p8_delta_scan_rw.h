/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/build_winkle_images/proc_slw_build/p8_delta_scan_rw.h $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
//***** IMPORTANT - Assumptions (you may have to change these settings) ******
#define ASM_RS4_LAUNCH_BUF_SIZE  24	// Byte size of binary RS4 launch buffer w/last two 
																		//   nops removed.
#define OVERRIDE_OFFSET 8						// Byte offset of forward pointer's addr relative 
																		//   to base forward pointer's addr.
#define SLW_MS_MAX_BUF_SIZE 50000000 // Max 50MB for SLW mainstore image.

/*****  Scan Control Regs  *****/
#define P8_PORE_CLOCK_CONTROLLER_REG  0x00030007 // Addr of clock ctrl scom reg
#define P8_PORE_SHIFT_REG             0x00038000 // Addr of scom reg that does scan ring shifting
#define P8_SCAN_CHECK_WORD						0xA5A55A5A // Header check word

/*****  Ring state *****/
#define MAX_RING_SIZE 1000000   // This is the max binary ring size in bits

// Debug and development stuff
#define IGNORE_FOR_NOW  // Causes code sections to be ignored.
#define DEBUG_SUPPORT   // Activates sbe-xip debug support.
#define PRINT_WF_DIS    // Causes wf inline code to be disassembled and written to file.

/***** Return codes *****/
#define DSLWB_RING_SEARCH_MATCH				 			 0
#define DSLWB_RING_SEARCH_EXHAUST_MATCH			30
#define DSLWB_RING_SEARCH_NO_MATCH					31
#define DSLWB_RING_SEARCH_MESS							32
#define DSLWB_SLWB_SUCCESS									 0
#define DSLWB_SLWB_NO_RING_MATCH						40
#define DSLWB_SLWB_DX_ERROR									41
#define DSLWB_SLWB_WF_ERROR									42
#define DSLWB_SLWB_WF_IMAGE_ERROR						43
#define DSLWB_SLWB_IMAGE_ERROR							44
#define DSLWB_SLWB_UNKNOWN_ERROR						45
#define IMGBUILD_SUCCESS                 		 0	// Successful image build.
#define IMGBUILD_ERR_MEMORY									20	// Memory allocation error.
#define IMGBUILD_ERR_XIP_MISC								25	// Miscellaneous XIP image error.
#define IMGBUILD_ERR_SECTION_DELETE					50	// Err assoc w/deleting ELF section.
#define IMGBUILD_ERR_APPEND        					51	// Err assoc w/appending to ELF section.
#define IMGBUILD_ERR_INCOMPLETE_IMG_BUILD		52	// The image was built, but with errors.
#define IMGBUILD_ERR_FWD_BACK_PTR_MESS      53	// Forward or backward pointer mess.
#define IMGBUILD_ERR_KEYWORD_NOT_FOUND 			54	// Image keyword not found.
#define	IMGBUILD_ERR_MISALIGNED_RING_LAYOUT	55	// Ring layout is misaligned.
#define IMGBUILD_ERR_IMAGE_TOO_LARGE        56  // Image too large. Exceeded max size.
#define IMGBUILD_ERR_CHECK_CODE    					60	// Coding problem - impossible state.

#ifdef __FAPI
#define MY_INF(_fmt_, _args_...) FAPI_INF(_fmt_, ##_args_)
#ifndef SLW_COMMAND_LINE
#define MY_ERR(_fmt_, _args_...) FAPI_ERR(_fmt_, ##_args_)
#else
#define MY_ERR(_fmt_, _args_...) FAPI_INF(_fmt_, ##_args_)
#endif // End of SLW_COMMAND_LINE
#define MY_DBG(_fmt_, _args_...) FAPI_DBG(_fmt_, ##_args_)
#else
#define MY_INF(_fmt_, _args_...) fprintf(stdout, _fmt_, ##_args_)
#define MY_ERR(_fmt_, _args_...) fprintf(stderr, _fmt_, ##_args_)
#define MY_DBG(_fmt_, _args_...) fprintf(stdout, _fmt_, ##_args_)
#endif  // End of FAPI

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef SLW_COMMAND_LINE
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#endif //End of SLW_COMMAND_LINE
#ifndef SLW_BUILD_WF_P0_FIX
#include "pore_bitmanip.H"
#endif // SLW_BUILD_WF_P0_FIX
#include "p8_pore_api.h"
#include "p8_pore_static_data.h"
#include "p8_scan_compression.H"
#include "sbe_xip_image.h"
#undef __PORE_INLINE_ASSEMBLER_C__
#include "pore_inline.h"

#ifdef __cplusplus
extern "C" {
#endif

// Info:
// DeltaRingLayout describes the sequential order of the content in the compressed delta
//   ring blocks in the .initf section in the SBE-XIP images.
// When creating the .initf delta ring blocks, the following rules must be followed:
// - Everything must be stored in BE format.
// - {entryOffset; sizeOfThis; sizeOfMeta; metaData} must be word-aligned to ensure 
//   that the {rs4Launch} starts on a word boundary.
// - {rs4Launch} must start on a word boundary (see earlier rule how to do that).
// - {entryOffset; sizeOfThis; sizeOfMeta; metaData; rs4Launch} must be double-word-
//   aligned to ensure that {rs4Delta} starts on a double-word boundary.
// - {rs4Delta} must start on a double-word bournday (see earlier rule how to do that).
//
typedef struct {
	uint64_t entryOffset;
	uint64_t backItemPtr;
	uint32_t sizeOfThis;
	uint32_t sizeOfMeta; // Exact size of meta data. Arbitrary size. Not null terminated.
	uint32_t ddLevel;
	uint8_t  sysPhase;
	uint8_t  override;
	uint8_t  reserved1;
	uint8_t  reserved2;
	char		 *metaData;  // Arbitrary size. Extra bytes to next alignment are random or 0s.
	uint32_t *rs4Launch; // Code. Must be 4-byte aligned.
	uint32_t *rs4Delta;  // Data. Must be 8-byte aligned.
	uint32_t *wfInline;  // Code. Must be 4-byte aligned.
} DeltaRingLayout;

typedef struct {
	uint32_t sizeOfData;
	char		 data[];
} MetaData;

int p8_ipl_build(	void 			*i_imageIn,
									uint32_t	i_ddLevel,
									void 			*i_imageOut,
									uint32_t	i_sizeImageOutMax);

int get_ring_layout_from_image2(	const void	*i_imageIn,
																	uint32_t		i_ddLevel,
																	uint8_t			i_sysPhase,
																	DeltaRingLayout	**o_rs4RingLayout,
																	void				**nextRing);

int write_ring_block_to_image(	void *io_image,
																DeltaRingLayout *i_ringBlock,
																uint32_t  i_sizeImageMax);

int	gen_ring_delta_state(	
							uint32_t 	bitLen, 
			  			uint32_t 	*i_init, 
			  			uint32_t 	*i_alter,
			  			uint32_t 	*o_delta,
			  			uint32_t	verbose);

int write_delta_ring_to_image(	
							char			*i_fnImage,
							CompressedScanData *i_RS4,
							uint32_t	i_ddLevel,
							uint8_t   i_sysPhase,
							uint8_t 	i_override,
							char 			*i_varName,
							char     	*i_fnMetaData,
							uint32_t 	verbose);

int get_delta_ring_from_image(
							char      *i_fnImage,
							char 			*i_varName,
							uint32_t	i_ddLevel,
							uint8_t		i_sysPhase,
							uint8_t		i_override,
							MetaData	**o_metaData,
							CompressedScanData	**o_deltaRingRS4,
							uint32_t	verbose);

int write_wiggle_flip_to_image(
							void			*io_imageOut,
							uint32_t	*i_sizeImageMaxNew,
							DeltaRingLayout *i_ringLayout,
							uint32_t	*i_wfInline,
							uint32_t	i_wfInlineLenInWords);

int get_ring_layout_from_image(	
							const void	*i_imageIn,
							uint32_t		i_ddLevel,
							uint8_t			i_sysPhase,
							DeltaRingLayout	*o_rs4RingLayout,
							void				**nextRing);

int	create_wiggle_flip_prg(	
              uint32_t  *i_deltaRing,
              uint32_t  i_ringBitLen,
              uint32_t  i_scanSelectData,
							uint32_t	i_chipletID,
              uint32_t  **o_wfInline,
              uint32_t  *o_wfInlineLenInWords);

int append_empty_section(
							void			*io_image,
							uint32_t	*i_sizeImageMaxNew,
							uint32_t	i_sectionId,
							uint32_t	i_sizeSection);

void cleanup(
							void *buf1=NULL,
							void *buf2=NULL,
							void *buf3=NULL,
							void *buf4=NULL,
							void *buf5=NULL);
							
// Byte-reverse a 32-bit integer if on an LE machine
inline uint32_t myRev32(const uint32_t i_x)
{
    uint32_t rx;

#ifdef _BIG_ENDIAN
    rx = i_x;
#else
    uint8_t *pix = (uint8_t*)(&i_x);
    uint8_t *prx = (uint8_t*)(&rx);

    prx[0] = pix[3];
    prx[1] = pix[2];
    prx[2] = pix[1];
    prx[3] = pix[0];
#endif

    return rx;
}

// Byte-reverse a 64-bit integer if on a little-endian machine
inline uint64_t myRev64(const uint64_t i_x)
{
    uint64_t rx;

#ifdef _BIG_ENDIAN
    rx = i_x;
#else
    uint8_t *pix = (uint8_t*)(&i_x);
    uint8_t *prx = (uint8_t*)(&rx);

    prx[0] = pix[7];
    prx[1] = pix[6];
    prx[2] = pix[5];
    prx[3] = pix[4];
    prx[4] = pix[3];
    prx[5] = pix[2];
    prx[6] = pix[1];
    prx[7] = pix[0];
#endif

    return rx;
}

#ifdef __cplusplus
}
#endif
