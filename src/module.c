
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "event_manager.h"
#include "header.h"


//All the present modules

void module_one()
{
	printf("Module_1: I am Interested !!\n");
}
void module_two()
{
	printf("Module_2: I am Interested !!\n");
}
void module_three()
{
	printf("Module_3: I am Interested !!\n");
}
void module_four()
{
	printf("Module_4: I am Interested !!\n");
}
void module_five()
{
	printf("Module_5: I am Interested !!\n");
}
void module_six()
{
	printf("Module_6: I am Interested !!\n");
}
void module_seven()
{
	printf("Module_7: I am Interested !!\n");

}
void module_eight()
{
	printf("Module_8: I am Interested !!\n");
}
void module_nine()
{
	printf("Module_9: I am Interested !!\n");
}
void module_ten()
{
	printf("Module_10: I am Interested !!\n");
}

//Assign the addresses of modules to the array of function pointers
void (*reg_ptr[])()={module_one, module_two, module_three, module_four, module_five, module_six, module_seven, module_eight, module_nine, module_ten};

//Function to get the No.of Modules and pass to get the interested events 
void module_init()
{
	int num_modules, ch, i;
	bool res = true;

	printf("Enter the No.of.Modules(only up to 10): \n");
	scanf("%d", &num_modules);

	if ((num_modules > 1) && (num_modules <= 10))
	{
		for (i = 0; i < num_modules; i++)
		{
			init_events = 0;
			
			res = get_events(i, reg_ptr[i]);

			if(!res)
			{
				printf("\nDo you want to enter again for module %d.. Press 1 : ",i+1);
				scanf("%d",&ch);

				if(ch==1)
				{ 
					i--;

				}
				else
				{
					exit(0);
				}
			}

		}
	}
	else
	{
		printf("\nInvalid No.of.modules..!\n");
		exit(0);
	}
}
