#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start = NULL, *current, *newnode, *temp1, *temp2,*temp,*temp3;
struct test
{
	int input[10], size,output[10];
}test[10] = { { {-1,0, 2, 2, 1 }, 5, { -1,0,1, 2, 2 } },
{ { 0, 3, 2, 2, 2 }, 5, { 0, 2, 2, 2, 3 } },
{ { -10000, 1000, -100, 0, 100, -1000, 10000 }, 7, { -10000, -1000, -100, 0, 100, 1000, 10000 } },
{ { 0, 0, 0, 0, 0, 0, 0, 0 }, 8, 0 },
{ { 2, 6, 10, 30, 18, 22, 26, 17 }, 8, { 2, 6, 10, 17, 18, 22, 26, 30 } },
{ { 1, 2, 5, 4, 3, 6 }, 6, { 1, 2, 3, 4, 5, 6 } },
{ { -10000, -9000, -7000, -8000, -6000, -5000, -4000 }, 7, { -10000, -9000, -8000, -7000, -6000, -5000, -4000 } }
};
void swapsort(struct node *start)
{
	int max;
	for (max = start->data, temp = start, temp1 = NULL; temp->next != NULL; temp = temp->next)
	{
		if (temp->next->data >= max)
			max = (temp->next)->data;
		else
			temp1 = temp;
	}
	if (temp1 != NULL)
	{
		temp2 = temp1->next;
		temp1->next = temp2->next;
		if (temp2->data < start->data)
		{                                   //mismatch at start node
			temp = temp2->next;
			temp1->next = start;
			temp2->next = start->next;
			(temp1->next)->next = temp;
			start = temp2;
		}
		else
		{
			for (temp = start; (temp->next)->data < temp2->data;)
				temp = temp->next;
			temp3 = temp->next;
			temp->next = temp3->next;
			temp2->next = temp->next;       //exchange of nodes
			temp->next = temp2;
			temp3->next = temp1->next;
			temp1->next = temp3;
		}
	}
}

void create(int index)
{
	char ch;
	int index1;
	for (index1 = 0; index1 < test[index].size; index1++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = test[index].input[index1];
		newnode->next = NULL;
		if (start == NULL)
		{
			start = newnode;
			current = newnode;
		}
		else
		{
			current->next = newnode;
			current = newnode;
		}
	}
}
void display()
{
	printf("list\n");
	for (temp1 = start; temp1 != NULL; temp1 = temp1->next)
		printf("%d\t", temp1->data);
}
void printop(int index)
{
	int index1;
	for (temp = start, index1 = 0; index1 < test[index].size; index1++,temp=temp->next)
	{
		if (temp->data != test[index].output[index1])
			break;
	}
	if (index1 == test[index].size)
		printf("passed\n");
	else
		printf("failed\n");
}
void testing()
{
	int index;
	for (index = 0; index < 8; index++)
	{
		create(index);
		swapsort(start);
		printop(index);
		start = NULL;
	}
}
void main()
{
	testing();
	_getch();
}