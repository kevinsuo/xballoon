#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sched.h>
#include <string.h>

#define __NR_sched_get_clock 323

int main(int argc, char* argv[])
{
  	int clock;
	pid_t pid;

	pid = atoi(argv[1]);	
	clock = syscall(__NR_sched_get_clock, pid);
	printf("Process: %d has clock %d \n", pid, clock);
	return 0;
}
