#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_ALLOC_S(str) str = (struct task *) malloc (sizeof(struct task))

#define VALIDATE(ptr) if (!ptr) {\
				printf("Malloc failed!\n");\
				exit(1);\
				}

#define BYTES 8

#define	ADDR(addr, ptr1, ptr2) (address - (ptr2 - ptr1))

struct link {
	struct link *next;
	struct link *prev;
};

struct task {
	long state;
	int pid;
	int flags;
	int prio;
	unsigned char fpu_counter;
	struct link tasks;
	char rcu_read;
	int tgid;
	char comm[16];
	unsigned int rt_prio;
}task1;

int main(void) {

	struct task *obj = NULL;
	struct task *print = NULL;
	unsigned int *ptr1 = NULL;
	unsigned int *ptr2 = NULL;
	unsigned int *address = NULL;

	MEM_ALLOC_S(obj);
	VALIDATE(obj);

	task1.state = 13426;
	task1.pid = 3778;
	task1.flags = 4;
	task1.prio = 9;
	task1.fpu_counter = 's';
	task1.tasks.next = NULL;
	task1.tasks.prev = NULL;
	task1.rcu_read = 'r';
	task1.tgid = 1234;
	strcpy(task1.comm, "Hello");
	task1.rt_prio = 6;

	address = (unsigned int *)&task1.tasks;
//	printf("%p\n", ptr1 = &obj);
//	printf("%p\n", ptr2 = &obj.tasks);
//	printf("%d\n", ptr2 - ptr1);

	ptr1 = (unsigned int *)obj;
	ptr2 = (unsigned int *)&obj->tasks;
	print = (struct task *)ADDR(address, ptr1, ptr2);

	printf("Address of task1-->%p\n", &task1);
	printf("Address from macro>%p\n", print);

// Displaying values of structure members
	printf("State		--> %ld\n", print->state);
	printf("PID		--> %d\n", print->pid);
	printf("Flags		--> %d\n", print->flags);
	printf("Prio		--> %d\n", print->prio);
	printf("fpu_counter	--> %c\n", print->fpu_counter);
	printf("rcu_read	--> %c\n", print->rcu_read);
	printf("tgid		--> %d\n", print->tgid);
	printf("comm		--> %s\n", print->comm);
	printf("rt_prio		--> %u\n", print->rt_prio);

	free(obj);

	obj = NULL;

	return 0;
}
