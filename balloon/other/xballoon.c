#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sched.h>
#include <string.h>

#define __NR_sched_sleep 322

void delay(int delay_in_us)
{
	int temp_cpu = 0;
	int accu_cpu = 0;
	int prev_time = 0;
	struct timeval start, end;
	int i;
	while (accu_cpu <= delay_in_us) {
		gettimeofday(&start, NULL);
		prev_time = temp_cpu;
		i = 0;
		while (i<1000)
			i++;
		gettimeofday(&end, NULL);
		temp_cpu = (unsigned long long)((unsigned long long)(end.tv_sec - start.tv_sec) * 1000000
				+ (unsigned long long)(end.tv_usec - start.tv_usec));
		if (temp_cpu < 3000)
//               printf("%d\n", temp_cpu);
			accu_cpu += temp_cpu;
	}

}



int main(int argc, char* argv[])
{
  	int ret;
 	int delay_in_us = 30;
	int compute;

	delay_in_us = atoi(argv[1]);	
	//compute = atoi(argv[2]);	
	while (1) {
	//delay(compute);
        //usleep(60000);
	ret = syscall(__NR_sched_sleep, delay_in_us);
	//sched_yield();
        if (ret){
		printf("xballoon canceled \n");
		//sched_yield();
	}
        //        usleep(2);
//	else
//		printf("xballoon ran \n");
	}

	return 0;
}
