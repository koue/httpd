/*
 * Copyright (c) 2015 Nikola Kolev
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *    - Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    - Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <sys/param.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <sys/queue.h>
#include <libprocstat.h>

int
getdtablecount(void) {
	struct procstat *procstat;
	struct kinfo_proc *kipp;
	struct filestat_list *head;
	struct filestat *fst;
	unsigned int fd_count = 0;
	pid_t pid;
	int cnt;

	procstat = procstat_open_sysctl();
	if (procstat == NULL)
		return 0;

	pid = getpid();
	
	kipp = procstat_getprocs(procstat, KERN_PROC_PID, pid, &cnt);
	if (kipp == NULL)
		return 0;

	if (cnt != 0) {
		head = procstat_getfiles(procstat, kipp, 0);
		if (head == NULL)
			return 0;
		fst = STAILQ_LAST(head, filestat, next);
		fd_count = fst->fs_fd;
	}
	procstat_freeprocs(procstat, kipp);
	return fd_count;
}
