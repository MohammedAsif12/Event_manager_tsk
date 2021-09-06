#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "event_manager.h"
#include "event_module.h"
#include "header.h"


struct modules
{       int mod_id;
	int events_interested;
	void (*mod_ptr)();
	struct modules *next;
}*head = NULL,*p1,*p2;


void reg_event(int,int,void(*)());

//Function to get the interested events and store them in the structure
bool get_events(int i,void (*call_fun)())
{       
	
	int event_per_module, event_id, ch, j;

	printf("Enter the no of events for module %d : ",i+1);
	scanf("%d",&event_per_module);

	if(event_per_module <= 32)
	{
		for(j=0; j<event_per_module; j++)
		{
			printf("\nEnter the event ID : ");
			scanf("%d",&event_id);

			if(event_id>=32)
			{
				printf("\nnot a valid event id....!\n");
				printf("\nTo Re-enter press 1: \n");
				scanf("%d",&ch);

				if(ch==1)
				{
					j--;
				}
				else
				{
					exit(0);
				}
			}
			else
			{
				//Macro to set the Event bits,in structure
				set_bit(init_events,event_id);

			}

		}
		//Function to store the respected events for the particular module in linked list structure
		reg_event(i+1,init_events,call_fun);
	}
	else
	{
		printf("\nNot a valid event id ....!\n");
		return false;

	}


	return true;
}
void reg_event(int module_id,int event_ids,void (*fun_ptrs)())
{
	p2= (struct modules*)malloc(sizeof(struct modules*));
	p2->mod_id=module_id;
	p2->events_interested=event_ids;

	p2->mod_ptr=fun_ptrs;
	if(head==NULL)
	{
		head=p1=p2;
		return;
	}
	p1->next=p2;
	p1=p2;
	return;

}


void trigger_event(int event_no)
{

	struct modules *p;
	p=head;
	bool not_interested=true;
	while(p)
	{ 
		if(get_bit(p->events_interested,event_no)){
			p->mod_ptr();
			not_interested=false; 
		}
		p=p->next;
	}
	if(not_interested)
	{
		printf("No modules interested in this event..!\n");
	}
}
