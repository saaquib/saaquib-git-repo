#include<stdio.h>
#include<stdlib.h>

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
};


#define prt_struct(offset,member,struct_type) struct_type *temp; \
				temp =(struct_type *) (offset -(((int *)(&(temp->member)))-((int *)temp)));

int  print_struct(unsigned int  var,int  mem,struct task tas4  );
int main()
{
	struct task tas;
	struct task tas1;
	unsigned int *offset;
	tas.state = 25; 	                                                             
    tas.pid=1215;                                                                    
    tas.flags=1;                                                                  
    tas.prio=10;                                                                   
    tas.fpu_counter='A';                                                  
    tas.tasks.next = tas1.tasks.next;   
	tas.tasks.prev = NULL;                                                       
    tas.rcu_read='B';                                                              
    tas.tgid=420;                                                                   
    tas.comm[16]=0;                                                              
    tas.rt_prio=840;  

	
	tas1.state = 250; 	                                                             
    tas1.pid=12150;                                                                    
    tas1.flags=10;                                                                  
    tas1.prio=100;                                                                   
    tas1.fpu_counter='C';                                                  
    tas1.tasks.next = NULL;
	tas1.tasks.prev = tas.tasks.prev;                                                          
    tas1.rcu_read='D';                                                              
    tas1.tgid=520;                                                                   
    tas1.comm[16]=0;                                                              
    tas1.rt_prio=80;

	offset = &(tas1.tasks);
	
	prt_struct(offset,tasks,struct task);
	
	printf("offset=0x%x\n",offset);
	printf("addd of tas=%x\n",(int)(&tas));
	printf("base addr=%x\n",temp);

	printf("---------------------\n");
	printf("state=%d\n",temp->state);
	printf("pid=%d\n",temp->pid);
}
