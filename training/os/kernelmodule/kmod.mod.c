#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x2fcee869, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x6f213ebd, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xae37b398, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xe72caaa8, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xad048f93, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x515c3870, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xb9c67764, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x3ca1c114, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xb920492a, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xb6e94223, __VMLINUX_SYMBOL_STR(cdev_alloc) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{        0, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "9EEB20652005182F835C1CE");
