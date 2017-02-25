#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include "linux/fdtable.h"
MODULE_LICENSE("Dual BSD/GPL");

#define FIRST_MINOR 10
#define NR_DEVS 1		//Number of device numbers

//Function Declarations for syscall definitions
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);
long myIoctl(struct file *, unsigned int, unsigned long);
void print_path(struct dentry *dentry);


//Initialization routines
static int myInit(void);
static void myExit(void);

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

module_param(devname, charp, 0000);// to pass command line arguments devname=myChar

static struct class *mychar_class;
static struct device *mychar_device;

int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "Open successful\n");
	return 0;
}


int myRelease(struct inode *in, struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}


long myIoctl(struct file *fd, unsigned int pid, unsigned long request)
{
	struct task_struct *ptr = NULL;
	ptr = find_task_by_vpid(pid);
	struct list_head lists;
	struct task_struct *ptr1;
/*	struct vm_area_struct *str = NULL;
	printk(KERN_INFO"control device \n");
	printk(KERN_INFO"pid = %d ",pid);
	str = ptr -> mm -> mmap;
	printk(KERN_INFO "task_struct pid is:%d\n", ptr->pid);
	printk(KERN_INFO "In my ioctl function");
	printk(KERN_CONT"\n");*/
/*	while ( str != NULL ){
		printk(KERN_CONT"%x-%x\t",str->vm_start,str->vm_end);
		str -> vm_flags & 1 ? printk(KERN_CONT"r") : printk(KERN_CONT"-");	
		str -> vm_flags & 2 ? printk(KERN_CONT"w") : printk(KERN_CONT"-");
		str -> vm_flags & 4 ? printk(KERN_CONT"xp\t%08x\t",str->vm_pgoff << 12) : printk(KERN_CONT"-p\t%08x\t",str->vm_pgoff << 12);
		if ( str -> vm_file != NULL ) {
			printk(KERN_CONT" %lu\t ",str->vm_file->f_inode->i_ino);
			print_path(str->vm_file->f_path.dentry);
			printk(KERN_CONT"\n");
		}
		else {
			printk(KERN_CONT"0\n");
		}
		str = str -> vm_next;
	}*/
//	printk(KERN_INFO"%p\n",str);
//	struct file **fd1;
//	fd1 = ptr -> files -> fdt -> fd;
//	printk(KERN_INFO"%p",*fd1+3);
	
	list_for_each_entry(ptr1,&(ptr->tasks),tasks){
		printk(KERN_INFO"%d\t%d\t%d\t%d\n",ptr1->pid,ptr1->parent->pid,ptr1->real_parent->pid,ptr1->tgid);
	}
	return 0;
}

void print_path(struct dentry *dentry)
{
	if ( *(dentry->d_name.name) != '/'){
	print_path(dentry -> d_parent);
	printk(KERN_CONT"/%s",dentry->d_name.name);
}
}
static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;

	printk(KERN_INFO "Initializing character device\n");

	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0) {
		printk(KERN_INFO "Device number allocation failed: %d\n", status);
		goto err;
	}

	printk(KERN_INFO "Major number allocated = %d\n", MAJOR(mydev));
	my_cdev = cdev_alloc();
	if(my_cdev == NULL) {
		printk(KERN_INFO "cdev_alloc failed \n");
		goto err_cdev_alloc;
	}

	cdev_init(my_cdev, &fops);
	my_cdev -> owner = THIS_MODULE;

	status = cdev_add (my_cdev, mydev, NR_DEVS);
	if(status) {
		printk(KERN_ERR "cdev_add failed \n");
		goto err_cdev_add;
	}

	mychar_class = class_create(THIS_MODULE, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "class_create() failed \n");
		goto err_class_create;
	}

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device)) {
		printk(KERN_ERR "device_create() failed \n");
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

