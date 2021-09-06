#include <stdio.h>

#include "event_module.h"
#include "event_manager.h"
#include "header.h"

int main()
{
	int event_ids, choice;

	module_init();

	do
	{
		printf("\nEnter the event to be shown : ");
         	scanf("%d",&event_ids);
		
		//Function to trigger event
		trigger_event(event_ids);
		
		//To continue triggering_events to know the Interested modules
		printf("\nTo continue press 1 : ");
		scanf("%d",&choice);

	}while(choice == 1);

}
