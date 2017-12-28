#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sched.h>
#include <string.h>

#define __NR_sched_sleep 322


int main(int argc, char* argv[])
{
        int ret;
//        int delay_in_us = 1000;
//        int compute;

//        delay_in_us = atoi(argv[1]);

	while (1) {
//		ret = syscall(__NR_sched_sleep, delay_in_us);
		ret = syscall(__NR_sched_sleep);

		if (ret){
                	printf("xballoon canceled \n");
		}
	}
	
	return 0;
}

