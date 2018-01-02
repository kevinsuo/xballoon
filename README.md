# Dependency

The current design is based on Xen 4.5 and Linux 3.18. 

You need:

> gcc 5.0 and higher version

# Usage:

1, download the xen code and compile it through compile.sh

2, download the guest os code and compile it through compile.sh. 
Add your application name into the CFS scheduler at place_entity@kernel/sched/fair.c for the fair credit allocation.

3, run the balloon process with your application in the guest os together.
