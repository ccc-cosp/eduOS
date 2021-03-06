/*
 * Copyright (c) 2011, Stefan Lankes, RWTH Aachen University
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
 * @author Stefan Lankes
 * @file include/eduos/syscall.h
 * @brief System call number definitions
 *
 * This file contains define constants for every syscall's number.
 */

#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include <eduos/stddef.h>
#include <asm/syscall.h>

#ifdef __cplusplus
extern "C" {
#endif

#define __NR_exit 		0
#define __NR_write		1
#define __NR_open		2
#define __NR_close		3
#define __NR_read		4
#define __NR_lseek		6
#define __NR_unlink		7
#define __NR_getpid		8
#define __NR_kill		9
#define __NR_fstat		10
#define __NR_sbrk		11
#define __NR_fork		12
#define __NR_wait		13
#define __NR_execve		14
#define __NR_times		15
#define __NR_accept		16
#define __NR_bind		17
#define __NR_closesocket	18
#define __NR_connect		19
#define __NR_listen		20
#define __NR_recv		21
#define __NR_send		22
#define __NR_socket		23
#define __NR_getsockopt		24
#define __NR_setsockopt		25
#define __NR_gethostbyname	26
#define __NR_sendto		27
#define __NR_recvfrom		28
#define __NR_select		29
#define __NR_stat		30
#define __NR_dup		31
#define __NR_dup2		32

#ifdef __cplusplus
}
#endif

#endif
