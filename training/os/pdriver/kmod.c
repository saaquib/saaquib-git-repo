#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 10
#define NR_DEVS 1

//
int myOpen (struct inode *inode, struct  file *filep);
int myRelease (struct inode *in, struct  file *fp);
long myIoctl (struct file *, unsigned int, unsigned long);
//
static int myInit (void);
static void myExit (void);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease,
	.unlocked_ioctl = myIoctl
};

char *devname;
int majNo;
static dev_t mydev;
struct cdev *my_cdev;
struct task_struct *ptr = NULL;
struct vm_area_struct *vm_new = NULL;

module_param (devname, charp, 0000); //
static struct class *mychar_class;
static struct device *mychar_device;

int myOpen (struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "Open successful\n");
	return 0;
}

int myRelease (struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

long myIoctl (struct file *fd, unsigned int pid, unsigned long b)
{
	printk(KERN_INFO "Ioctl Invoked \n" );
	printk(KERN_INFO "PID : %d\n",pid);

	extern struct list_head modules;
	struct module *cmod;
	struct module_use *dmod;

	ptr = find_task_by_vpid(pid);        
	vm_new = (ptr->mm)->mmap; 

	printk(KERN_INFO "sys/pid : %d \n ", ptr->pid);

/*	printk(KERN_INFO "------------MMAP---------------\n");
	while(vm_new != NULL) { 
		printk(KERN_INFO" %08x - %08x \t",vm_new->vm_start,vm_new->vm_end); 
		
		((vm_new->vm_flags) & 1 ) ? printk(KERN_CONT"r") : printk(KERN_CONT"-"); 
		((vm_new->vm_flags) & 2 ) ? printk(KERN_CONT"w") : printk(KERN_CONT"-"); 
		((vm_new->vm_flags) & 4 ) ? printk(KERN_CONT"x") : printk(KERN_CONT"-"); 
		((vm_new->vm_flags) & 8 ) ? printk(KERN_CONT"S\t") : printk(KERN_CONT"P\t"); 

		printk(KERN_CONT"%08x\n\n",vm_new->vm_pgoff); 
		vm_new = vm_new->vm_next; 
	} 
*/	printk(KERN_INFO "------------LSMOD---------------\n");
	 printk(KERN_INFO "Modules\t\t names");
        list_for_each_entry(cmod, &modules, list){
                printk(KERN_INFO "%s", cmod->name);
                list_for_each_entry(dmod, &(cmod -> source_list), source_list){
                        printk(KERN_CONT "%\t\ts  ", dmod -> source -> name);
                }
                printk(KERN_CONT "\n");	
	return 0;
}

static int __init myInit (void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing character device\n");
	
	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS,devname);
	if (status < 0) {
		printk(KERN_INFO "Device number allocation failed: %d\n", status);
		goto err;
	}

	printk(KERN_INFO "Major number allocated = %d\n", MAJOR(mydev));
	my_cdev = cdev_alloc();
	if (my_cdev == NULL) {
		printk(KERN_ERR "cdev _alloc failed\n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);
	my_cdev -> owner = THIS_MODULE;

	status = cdev_add (my_cdev,mydev, NR_DEVS);
	if(status) {
		printk(KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}
	
	mychar_class = class_create(THIS_MODULE, devname);
	if (IS_ERR(mychar_device)) {
		printk(KERN_INFO "class_create() failed \n");
		goto err_class_create;
	}

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if (IS_ERR(mychar_device)) {
		printk(KERN_INFO "device_create() failed \n");
		goto err_device_create;
	}
	
	return 0;

err_device_create:
	class_destroy(mychar_class);
	
err_class_create:
	cdev_del(my_cdev);

err_cdev_add:
	kfree(my_cdev);

err_cdev_alloc:
	unregister_chrdev_region(mydev, NR_DEVS);

err:
	return ret;

}

static void myExit(void)
{
	printk(KERN_INFO "Exiting the character driver \n");

	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);

	return;
}

module_init(myInit);
module_exit(myExit);
