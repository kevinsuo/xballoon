# Introduction

While many prior studies attribute the suboptimal I/O performance to virtualization overhead and inefficient virtual machine scheduling  and propose corresponding solutions, we discover that the time discontinuity caused by virtualization can also degrade the I/O performance. With discontinuous CPU, I/O prioritization is ineffective in guest OSes to guarantee the performance of I/O-intensive workloads. xBalloon is a lightweight approach to preserving I/O prioritization under discontinuous CPU in virtualized systems.


# Dependency

The current design is based on Xen 4.5 and Linux 3.18. 

You need:

> gcc 5.0 or higher version

# Usage:

1, Download the xen code and compile it through compile.sh

> $ ./compile.sh

2, Download the guest os code and compile it through compile.sh.

> $ ./compile.sh

Modify the /boot/grub/grub.list to boot the guest in new kernel.

Add your application name into the CFS scheduler at place_entity@kernel/sched/fair.c for the fair credit allocation.

3, Set the absolute clock rq_clock to the low priority tasks

> $ cd xballoon/balloon/other/

> $ ./set_clock [pid] [clockid], 
(0: default clock; 1: rq_clock synchronizes with the host clock)  

Run the balloon process with your application in the guest os together.
> $ ./balloon
