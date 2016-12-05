/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/securerom.ld $                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/*****************************************************************************/
/* linker script for low level firmware                                      */
/*****************************************************************************/

/* PH: to use the same lds file for 32/64bit, don't specify
 *     OUTPUT_FORMAT, OUTPUT_ARCH here.
 * /
 OUTPUT_FORMAT("elf64-powerpc")
 OUTPUT_ARCH(powerpc64:common)
 */

/* set the entry point */
ENTRY(_instruction_start)

MEMORY {
	secure_boot_rom  (IRX): ORIGIN = 0x80001C0000000000, LENGTH = 32K
/*	untrusted_memory (RW): ORIGIN = 0x8000000000000000, LENGTH = 0x0000000000800000
*	trusted_memory   (RW): ORIGIN = 0x8000000000800000, LENGTH = 0x800000FFFF800000
*/
}


SECTIONS {
	. = 0x80001C0000000000; /* tbrom base address */

	.branchtable : {
		. = ALIGN(0x1000);
	}>secure_boot_rom

	.text : {
		*(.text)
	}>secure_boot_rom

	. = ALIGN(8);

	__toc_start = .;
	.toc : {
		 *(.toc .got)
	}>secure_boot_rom
	. = ALIGN(8);
	__toc_end = .;

	.data : {
		*(.data)
		*(.rodata .rodata.*)
		*(.got1)
		*(.sdata)
	}>secure_boot_rom

	. = ALIGN(8);

	/* PH: opd section must be separate, if i put it in .data,
	 * the C functions are not present in the generated file....
	 * If anybody can explain why, i'd be glad to hear...
	 * Note: the KEEP has been removed was: " KEEP (*(.opd)) "
	 */
	.opd ALIGN(8) : {
		*(.opd)
	}>secure_boot_rom
	 
	. = ALIGN(8);
	__bss_start = .;
	.bss : {
		*(.sbss) *(.scommon)
		*(.dynbss)
		*(.bss)
	}>secure_boot_rom
	. = ALIGN(8);
	__bss_end = .;
	__bss_size = SIZEOF(.bss);

}
