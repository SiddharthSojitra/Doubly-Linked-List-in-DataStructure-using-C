typedef struct Node
{
	int data;
	struct Node *pre, *nxt;
}NODE;

NODE *createNode()
{
	NODE *n = (NODE*)malloc(sizeof(NODE));
	n->data = NULL;
	n->pre = NULL;
	n->nxt = NULL;

	return n;
}

NODE *insertfirst(NODE *head, int val)
{
	NODE *n = createNode();
	n->data = val;

	if(head != NULL)
	{
		n->nxt = head;
		head->pre = n;
	}
	head = n;
	printf("\n %d is Inserted \n",val);

	return head;
}

NODE *insertlast(NODE *head, int val)
{
	NODE *tr = head;
	NODE *n = createNode();
	n->data = val;
	if(head==NULL)
	{
		head=n;
	}
	else
	{
		while(tr->nxt != NULL)
		{
			tr=tr->nxt;

		}
		n->pre = tr;
		tr->nxt = n;
	}
	printf("\n %d is Inserted \n",val);
	return head;
}

void display(NODE *head)
{
	NODE *tr=head;
	if(head == NULL)
	{
		printf("\n Link List is EMPTY");
	}
	else
	{
		while(tr != NULL)
		{
			printf("%d_",tr->data);
			tr = tr->nxt;
		}
		printf("\n");
	}
}

void displayReverse(NODE *head)
{
	NODE *tr=head;
	if(head == NULL)
	{
		printf("\n Link List is EMPTY");
	}
	else
	{
		while(tr->nxt != NULL)
		{
			tr = tr->nxt;
		}
		while(tr != NULL)
		{
			printf("%d_",tr->data);
			tr = tr->pre;
		}
		printf("\n");
	}
}

NODE *insertpos(NODE *head,int pos, int val)
{
	int con=1;
	NODE *n = createNode();
	n->data = val;
   NODE *tr = head, *post=NULL;
    if (pos == 1)
	{
        	n->nxt = head;
		head->pre = n;
	        head = n;
	}
	else
	{
		while (con < (pos-1) && tr != NULL)
	        {
				tr = tr->nxt;
        		con++;
        	}
        	post = tr->nxt;
	        if(tr == NULL)
        	{
        		printf("INVALID POSITION/n");
        	}
	        else
        	{
        		n->nxt = post;
        		n->pre = tr;
				tr->nxt = n;
				post->pre = n;
        	}
        	printf("\n %d is Inserted \n",val);
	}
	return head;
}

NODE *insertbefore(NODE *head, int eval, int nval)
{
	NODE *tr = head;
	NODE *n = createNode();
	n->data = nval;

	if(head == NULL)
	{
		printf("\n It's value is not inserted \n");
		free(n);
	}
	else if(head->data == eval)
	{
		n->nxt = head;
		head->pre = n;
		head =n;
	}
	else
	{
		while(tr != NULL && tr->data != eval)
		{
			tr = tr->nxt;
		}
		if(tr == NULL)
		{
			printf("\nValue not found \n");
			free(n);
		}
		else
		{
			n->nxt = tr;
			n->pre = tr->pre;
			(tr->pre)->nxt = n;
			tr->pre = n;
		}
	}
	printf("\n %d is Inserted \n",nval);
	return head;
}

void insertafter(NODE *head, int eval, int nval)
{
	NODE *tr = head;
	NODE *n = createNode();
	n->data = nval;

	if(head == NULL)
	{
		printf("\n It's value is not inserted \n");
		free(n);
	}
	else
	{
		while(tr != NULL && tr->data != eval)
		{
			tr = tr->nxt;
		}
		if(tr == NULL)
		{
			printf("\n It's value is not in Link-List \n");
			free(n);
		}
		else if(tr->nxt == NULL)
		{
			n->pre = tr;
			n->nxt = NULL;
			tr->nxt = n;
			printf("\n %d is Inserted \n",nval);
		}
		else
		{
			n->pre = tr;
			n->nxt = tr->nxt;
			(tr->nxt)->pre = n;
			tr->nxt = n;
			printf("\n %d is Inserted \n",nval);
		}
	}
}

NODE *deletefirst(NODE *head)
{
	NODE *tr = head;
	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else if(head->nxt == NULL)
	{
		printf("\n %d is Deleted \n",head->data);
		head=NULL;
		free(head);
	}
	else
	{
		printf("\n %d is Deleted \n",head->data);
		head = head->nxt;
		head->pre = NULL;
		free(tr);
	}
	return head;
}


/*
			OR
			==

NODE *deletefirst(NODE *head)
{
	NODE *tr = head;
	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else
	{
		del = head;
		head = head->nxt;
		if(head != NULL)
		{
			head->pre=NULL;
		}
		free(del);
	}
}
*/

NODE *deletelast(NODE *head)
{
	NODE *tr = head;
	if(head == NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else if(head->nxt==NULL)
	{
		printf("\n %d is Deleted \n",tr->data);
		head=NULL;
		free(head);
	}
	else
	{
		while(tr->nxt != NULL)
		{
			tr = tr->nxt;
		}
		printf("\n %d is Deleted \n",tr->data);
		(tr->pre)->nxt=NULL;
		free(tr);
	}
	return head;
}

NODE *deleteatpos(NODE *head, int pos)
{
	int con = 1;
	NODE *tr = head;

	if(head == NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else if(pos==1)
	{
		head=deletefirst(head);
	}
	else
	{
		while(con < pos && tr != NULL)
		{
			tr = tr->nxt;
			con++;
		}
		if(tr == NULL)
		{
			printf("\n VALUE NOT FOUND... \n");
		}
		else
		{
			(tr->pre)->nxt = tr->nxt;
			if(tr->nxt != NULL)
			{
				(tr->nxt)->pre = tr->pre;
			}
			printf("\n %d is Deleted \n",tr->data);
			free(tr);
		}
	}
	return head;
}

NODE *deleteBefore(NODE *head, int val)
{
	NODE *tr = head, *del=NULL;

	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else
	{
		while(tr != NULL && tr->data != val)
		{
			tr = tr->nxt;
		}
		if(tr == NULL)
		{
			printf("\n VALUE NOT FOUND... \n");
		}
		else if(tr->pre == NULL)
		{
			printf("\n NODE NOT FOUND... \n");
		}
		else
		{
			del = tr->pre;
			if(head==del)
			{
				tr->pre = NULL;
				head = tr;
			}
			else
			{
				(del->pre)->nxt = tr;
				tr->pre = del->pre;
			}
			printf("\n %d is Deleted \n",del->data);
			free(del);
		}
	}
	return head;
}

void deleteAfter(NODE *head, int val)
{
	NODE *tr = head, *del=NULL;

	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else
	{
		while(tr != NULL && tr->data != val)
		{
			tr = tr->nxt;
		}
		if(tr == NULL)
		{
			printf("\n VALUE NOT FOUND... \n");
		}
		else if(tr->nxt == NULL)
		{
			printf("\n NODE NOT FOUND... \n");
		}
		else
		{
			del = tr->nxt;
			tr->nxt = del->nxt;
			if(del->nxt != NULL)
			{
				(del->nxt)->pre = tr;
			}
			printf("\n %d is Deleted \n",del->data);
			free(del);
		}
	}
}

NODE* deleteFirstOcc(NODE *head,int val)
{
	NODE *tr=head;

	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else if(head->data == val)
	{
		head = head->nxt;
		printf("\n First %d is Deleted \n",tr->data);
		free(tr);
	}
	else
	{
		while (tr != NULL && tr->data != val)
		{
			tr = tr->nxt;
		}
		if(tr == NULL)
		{
			printf("\nValue not found\n");
		}
		else
		{
			(tr->pre)->nxt = tr->nxt;
			(tr->nxt)->pre = tr->pre;
			printf("\n First %d is Deleted \n",tr->data);
			free(tr);
		}
	}
	return head;
}



NODE* deleteAllOcc(NODE *head,int val)
{
	int flg=0,i=0;
	NODE *pre=NULL,*del=NULL;
	NODE *tr=head;
	if(head==NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	else
	{
		while(tr != NULL)
		{
			if(tr->data == val)
			{
				del = tr;
				if(tr == head)
				{
					head = head->nxt;
					if(head->pre!=NULL)
					{
						head->pre=NULL;
					}
					tr = head;
				}
				else
				{
					pre->nxt = tr->nxt;
					if(tr->nxt!=NULL)
						{
							(tr->nxt)->pre = pre;
						}
					tr = pre->nxt;
				}
				i++;
				flg=1;
				printf("\n %d times %d is Deleted \n",i,del->data);
				free(del);
			}
			else
			{
				pre = tr;
				tr = tr->nxt;
			}
		}
		if(flg==0)
			printf("\nValue not found\n");
	}
	return head;
}
