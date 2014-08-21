/*
 * Copyright (c) 2010, Stefan Lankes, RWTH Aachen University
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the University nor the names of its contributors
 *      may be used to endorse or promote products derived from this
 *      software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @author Steffen Vogel
 * @file arch/x86/include/asm/page.h
 * @brief Paging related functions
 *
 * This file contains the several functions to manage the page tables
 */

#ifndef __PAGE_H__
#define __PAGE_H__

/// Page offset bits
#define PAGE_BITS		12
/// The size of a single page in bytes
#define PAGE_SIZE		(1L << PAGE_BITS)

/// Total operand width in bits
#define BITS			32
/// Linear/virtual address width
#define VIRT_BITS		BITS
/// Physical address width (we dont support PAE)
#define PHYS_BITS		BITS
/// Page map bits
#define PAGE_MAP_BITS		10
/// Number of page map indirections
#define PAGE_MAP_LEVELS	2
/// Mask the page address without page map flags
#define PAGE_MASK		0xFFFFF000

/// Make address canonical
#define CANONICAL(addr)		(addr) // only for 32 bit paging

/// The number of entries in a page map table
#define PAGE_MAP_ENTRIES	(1L << PAGE_MAP_BITS)

// Base addresses of the self-mapped pagetables
#define PAGE_MAP_PGD		0xFFFFF000
#define PAGE_MAP_PGT		0xFFC00000

/// Align to next page
#define PAGE_FLOOR(addr)        (((addr) + PAGE_SIZE - 1) & PAGE_MASK)
/// Align to page
#define PAGE_CEIL(addr)         ( (addr)                  & PAGE_MASK)

/// Page is present
#define PG_PRESENT		(1 << 0)
/// Page is read- and writable
#define PG_RW			(1 << 1)
/// Page is addressable from userspace
#define PG_USER			(1 << 2)
/// Page write through is activated
#define PG_PWT			(1 << 3)
/// Page cache is disabled
#define PG_PCD			(1 << 4)
/// Page was recently accessed (set by CPU)
#define PG_ACCESSED		(1 << 5)
/// Page is dirty due to recent write-access (set by CPU)
#define PG_DIRTY		(1 << 6)
/// Huge page: 4MB (or 2MB, 1GB)
#define PG_PSE			(1 << 7)
/// Page attribute table
#define PG_PAT			PG_PSE
/// Global TLB entry (Pentium Pro and later)
#define PG_GLOBAL		(1 << 8)
/// This page or table is used during the boot process
#define PG_BOOT			(1 << 9)


/** @brief A single entry in a page map
 *
 * Usually used as a pointer to a mapped page map entry.
 */
typedef size_t page_entry_t;

/** @brief Initialize paging subsystem
 *
 * This function uses the existing bootstrap page tables (boot_{pgd, pgt})
 * to map required regions (video memory, kernel, etc..).
 * Before calling page_init(), the bootstrap tables contain a simple identity
 * paging. Which is replaced by more specific mappings.
 */
int page_init();

/** @brief Map a continious region of pages
 *
 * @param viraddr
 * @param phyaddr
 * @param pages
 * @param flags
 * @return
 */
int page_map(size_t viraddr, size_t phyaddr, size_t pages, size_t flags);

/** @brief Unmap a continious region of pages
 *
 * @param viraddr
 * @param pages
 * @return
 */
int page_unmap(size_t viraddr, size_t pages);

/**  @brief Copy a single page frame
 *
 * @param dest
 * @param src
 * @return
 */
int page_copy(size_t dest, size_t src);

/** @brief Copy a whole page map tree
 *
 * @param dest
 * @param src
 * @return
 */
int page_map_copy(page_entry_t *dest, page_entry_t *src);

/** @brief Free a whole page map tree
 *
 * @param map
 */
int page_map_drop(page_entry_t *map);

/** @brief Converts a virtual address to a physical
 *
 * @param viraddr Virtual address to convert
 * @return Physical address
 */
size_t virt_to_phys(size_t viraddr);

#endif
