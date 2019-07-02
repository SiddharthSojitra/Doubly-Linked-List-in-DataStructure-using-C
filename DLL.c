#include<stdio.h>
#include"DLL.h"

main()
{
	NODE *head=NULL;
	
	while(1)
	{
		int S,val=0,pos,nval,eval;

		printf("\n||||||||||||||||||||||||||||||||||||||||||");
		printf("\n||          CHOOSE THE OPTION           ||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||");
		printf("\n|| 01_INSERT_FIRST                      ||");
		printf("\n|| 02_INSERT_LAST                       ||");
		printf("\n|| 03_DISPLAY                           ||");
		printf("\n|| 04_DISPLAY_REVERSE                   ||");
		printf("\n|| 05_INSERT_AT_POSITION                ||");
		printf("\n|| 06_INSERT_BEFORE                     ||");
		printf("\n|| 07_INSERT_AFTER                      ||");
		printf("\n|| 08_DELETE_FIRST                      ||");
		printf("\n|| 09_DELETE_LAST                       ||");
		printf("\n|| 10_DELETE_AT_POSITION                ||");
		printf("\n|| 11_DELETE_BEFORE                     ||");
		printf("\n|| 12_DELETE_AFTER                      ||");
		printf("\n|| 13_DELETE_GIVEN-VALUE-(FIRST OCC.)   ||");
		printf("\n|| 14_DELETE_GIVEN-VALUE-(ALL OCC.)     ||");
		printf("\n|| 00_EXIT                              ||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||\n");
		printf("\n\t\t\t\t Enter your choice...");
		scanf("%d",&S);
		switch(S)
		{
			case 0: return 0;

			case 1:
				printf("Enter the value :");
				scanf("%d",&val);
				head = insertfirst(head,val);
			break;

			case 2:
				printf("Enter the value :");
				scanf("%d",&val);
				head = insertlast(head,val);
			break;

			case 3:
				display(head);
			break;

			case 4:
				displayReverse(head);
			break;

			case 5:
				printf("Enter the Position : ");
				scanf("%d",&pos);
				printf("Enter the Value : ");
				scanf("%d",&val);
				head = insertpos(head,pos,val);
			break;

			case 6:
				printf("Where you add the new value : before..");
				scanf("%d",&eval);
				printf("Enter the new value :");
				scanf("%d",&nval);
				head = insertbefore(head,eval,nval);
			break;

			case 7:
				printf("Where you add the new value : after..");
				scanf("%d",&eval);
				printf("Enter the new value :");
				scanf("%d",&nval);
				insertafter(head,eval,nval);
			break;

			case 8:
				head = deletefirst(head);
			break;

			case 9:
				head = deletelast(head);
			break;

			case 10:
				printf("Enter the Position : ");
				scanf("%d",&pos);
				head = deleteatpos(head,pos);
			break;

			case 11:
				printf("Enter the EXISTING value :");
				scanf("%d",&val);
				head=deleteBefore(head,val);
			break;

			case 12:
				printf("Enter the EXISTING value :");
				scanf("%d",&val);
				deleteAfter(head,val);
			break;

			case 13:
				printf("Enter the EXISTING value :");
				scanf("%d",&val);
				head=deleteFirstOcc(head,val);
			break;

			case 14:
				printf("Enter the EXISTING value :");
				scanf("%d",&val);
				head = deleteAllOcc(head,val);
			break;

			default : printf("\n PLEASE ENTER VALID OPTION \n");
			break;
		}
	}
}
