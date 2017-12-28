#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>

#include <linux/hardirq.h>

#include <asm/x86_init.h>

#include <xen/interface/xen.h>
#include <xen/interface/sched.h>
#include <xen/interface/vcpu.h>

#include <asm/xen/hypercall.h>
#include <asm/xen/hypervisor.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

#define MS_TO_NS(x)	(x * 1E6L)

static struct hrtimer hr_timer;

enum hrtimer_restart b_timer_callback( struct hrtimer *timer )
{
	ktime_t ktime;
        struct sched_sleep sched_sleep;
	ktime_t now = ktime_get();
	unsigned long delay_in_ms = 60L;
	ktime = ktime_set(0 , MS_TO_NS(delay_in_ms));
        sched_sleep.timeout = MS_TO_NS(delay_in_ms);
	//printk( "b_timer_callback called (%ld).\n", jiffies );
        mdelay(60);
	hrtimer_forward(timer, now, ktime);
        HYPERVISOR_sched_op(SCHEDOP_sleep, &sched_sleep);
        //xen_halt();

	return HRTIMER_RESTART;
}

int init_module( void )
{
	ktime_t ktime;
	unsigned long delay_in_ms = 200L;

	printk("HR Timer module installing\n");
	ktime = ktime_set( 0, MS_TO_NS(delay_in_ms) );
	hrtimer_init( &hr_timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
	hr_timer.function = &b_timer_callback;
	printk( "Starting timer to fire in %ldms (%ld)\n", delay_in_ms, jiffies );
	hrtimer_start( &hr_timer, ktime, HRTIMER_MODE_REL );

	return 0;
}

void cleanup_module( void )
{
	int ret;

	ret = hrtimer_cancel( &hr_timer );
	if (ret) printk("The timer was still in use...\n");
	printk("HR Timer module uninstalling\n");

	return;
}
