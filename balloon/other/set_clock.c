#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sched.h>
#include <string.h>

#define __NR_sched_set_clock 324

int main(int argc, char* argv[])
{
  	int clock, ret;
	pid_t pid;

	pid = atoi(argv[1]);	
	clock = atoi(argv[2]);	
	ret = syscall(__NR_sched_set_clock, pid, clock);
	return 0;
}
