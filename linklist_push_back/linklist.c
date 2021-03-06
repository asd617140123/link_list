#include <stdlib.h>
#include <stdio.h>

typedef struct _NODE{
	int data;
	struct _NODE* next;
	unsigned int size;
}NODE;

NODE* head = NULL;
NODE* current;

void insert(int x)
{
	NODE* tmp = malloc(sizeof(NODE));
	tmp -> data = x;
	tmp -> next = NULL;

	if(head)
		current->next = tmp;
	else
		head = tmp;
	current = tmp;
	
	
	head ->size++;
}

void delete(int n)
{
	NODE* tmp1 = head;
	NODE* tmp2;
	if(head->size < n ||  head->size == 1)
	{
		printf("head size %d is bigger than n\n",head ->size);
		printf("head size is not valid\n");
		return;
	}
	//else if(head->size == 1)
	//{
	//	printf("head size %d is smaller than n\n",head->size);
	//	return;
	//}
	if(n == 0)
	{
		printf("n size can't be set zero");
		return;
	}
	if(n == 1){
		head = tmp1->next;
		head -> size = tmp1->size;
		free(tmp1);
	}
	else
	{
		for(int i = 0;i<(n-2);i++)
			tmp1 = tmp1 -> next;
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		free(tmp2);
	}

	head ->size--;
}

void reverse(void)
{
	NODE* cur,*prev,*next;
	cur = head;
	prev = NULL;
	while(cur != NULL)
	{
		next = cur -> next;
		cur -> next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}



void print(void)
{
	NODE* tmp = head;
	while(tmp)
	{
		printf(" %d ",tmp->data);
		tmp = tmp->next;
	}
}

void main(void)
{
	int n = 0;
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	printf("link list is =\n");
	print();
	printf("\n");
	reverse();
	printf("reverse link list is =\n");
	print();
	reverse();
	printf("reverse link list is =\n");
	print();
	while(1)
	{
		printf("please scan a number \n");
		scanf("%d",&n);
		delete(n);
		print();
	}
}